// MergeAnalysisObjects.C
//
// Object-level merger for the status-analysis ROOT outputs. This is a safer
// fallback when hadd becomes pathological on accumulated THnSparse objects.

#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "TFile.h"
#include "TH1.h"
#include "THnSparse.h"
#include "TKey.h"
#include "TList.h"
#include "TObject.h"
#include "TSystem.h"

namespace {

std::string Trim(const std::string& input)
{
    const char* whitespace = " \t\r\n";
    const std::size_t begin = input.find_first_not_of(whitespace);
    if (begin == std::string::npos) return "";
    const std::size_t end = input.find_last_not_of(whitespace);
    return input.substr(begin, end - begin + 1);
}

std::vector<std::string> ReadInputList(const char* inputListPath)
{
    std::ifstream input(inputListPath);
    std::vector<std::string> paths;
    std::string line;

    while (std::getline(input, line)) {
        line = Trim(line);
        if (line.empty() || line[0] == '#') continue;
        paths.push_back(line);
    }

    return paths;
}

bool AddObject(TObject* target,
               TObject* source,
               const std::string& objectName,
               const std::string& sourcePath)
{
    if (auto* targetHist = dynamic_cast<TH1*>(target)) {
        auto* sourceHist = dynamic_cast<TH1*>(source);
        if (!sourceHist) {
            std::cerr << "ERROR: object '" << objectName << "' in " << sourcePath
                      << " is not a TH1-compatible object" << std::endl;
            return false;
        }
        targetHist->Add(sourceHist);
        return true;
    }

    if (auto* targetSparse = dynamic_cast<THnSparse*>(target)) {
        auto* sourceSparse = dynamic_cast<THnSparse*>(source);
        if (!sourceSparse) {
            std::cerr << "ERROR: object '" << objectName << "' in " << sourcePath
                      << " is not a THnSparse-compatible object" << std::endl;
            return false;
        }
        targetSparse->Add(sourceSparse);
        return true;
    }

    std::cerr << "ERROR: unsupported object type for '" << objectName
              << "': " << target->ClassName() << std::endl;
    return false;
}

} // namespace

int MergeAnalysisObjects(const char* inputListPath,
                         const char* outputPath,
                         bool verbose = true)
{
    TH1::AddDirectory(kFALSE);

    const std::vector<std::string> inputPaths = ReadInputList(inputListPath);
    if (inputPaths.empty()) {
        std::cerr << "ERROR: input list is empty: " << inputListPath << std::endl;
        return 1;
    }

    std::unique_ptr<TFile> firstFile(TFile::Open(inputPaths.front().c_str(), "READ"));
    if (!firstFile || firstFile->IsZombie()) {
        std::cerr << "ERROR: could not open first input file: "
                  << inputPaths.front() << std::endl;
        return 2;
    }

    std::vector<std::string> objectNames;
    std::vector<std::unique_ptr<TObject>> mergedObjects;

    TIter nextKey(firstFile->GetListOfKeys());
    TKey* key = nullptr;
    while ((key = dynamic_cast<TKey*>(nextKey()))) {
        std::unique_ptr<TObject> object(key->ReadObj());
        if (!object) {
            std::cerr << "ERROR: could not read object from first input: "
                      << key->GetName() << std::endl;
            return 3;
        }

        TObject* clone = object->Clone(object->GetName());
        if (!clone) {
            std::cerr << "ERROR: could not clone object: "
                      << object->GetName() << std::endl;
            return 4;
        }

        if (auto* hist = dynamic_cast<TH1*>(clone)) {
            hist->SetDirectory(nullptr);
        }

        objectNames.emplace_back(object->GetName());
        mergedObjects.emplace_back(clone);
    }

    if (mergedObjects.empty()) {
        std::cerr << "ERROR: no mergeable objects found in first input: "
                  << inputPaths.front() << std::endl;
        return 5;
    }

    for (std::size_t i = 1; i < inputPaths.size(); ++i) {
        std::unique_ptr<TFile> inputFile(TFile::Open(inputPaths[i].c_str(), "READ"));
        if (!inputFile || inputFile->IsZombie()) {
            std::cerr << "ERROR: could not open input file: "
                      << inputPaths[i] << std::endl;
            return 6;
        }

        for (std::size_t j = 0; j < objectNames.size(); ++j) {
            TObject* source = inputFile->Get(objectNames[j].c_str());
            if (!source) {
                std::cerr << "ERROR: missing object '" << objectNames[j]
                          << "' in " << inputPaths[i] << std::endl;
                return 7;
            }

            if (!AddObject(mergedObjects[j].get(), source, objectNames[j], inputPaths[i])) {
                return 8;
            }
        }

        if (verbose && (((i + 1) % 10 == 0) || (i + 1 == inputPaths.size()))) {
            std::cout << "Merged " << (i + 1) << "/" << inputPaths.size()
                      << " files into " << outputPath << std::endl;
        }
    }

    const std::string outputDir = gSystem->DirName(outputPath);
    if (!outputDir.empty() && gSystem->AccessPathName(outputDir.c_str())) {
        if (gSystem->mkdir(outputDir.c_str(), true) != 0) {
            std::cerr << "ERROR: could not create output directory: "
                      << outputDir << std::endl;
            return 9;
        }
    }

    std::unique_ptr<TFile> outputFile(TFile::Open(outputPath, "RECREATE"));
    if (!outputFile || outputFile->IsZombie()) {
        std::cerr << "ERROR: could not create output file: "
                  << outputPath << std::endl;
        return 10;
    }

    outputFile->cd();
    for (const auto& object : mergedObjects) {
        object->Write(object->GetName(), TObject::kOverwrite);
    }
    outputFile->Close();

    if (verbose) {
        std::cout << "Wrote merged file: " << outputPath << std::endl;
    }

    return 0;
}
