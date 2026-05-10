// qq_draw_2D_correlations

// C headers
#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
#include <cmath>

// ROOT headers
#include "TFile.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "TString.h" // TODO: can use this for the legend entry names?
#include <TLegend.h>


void do_draw_2D_correlations(const char *title, const char *fileNameOS, const char *fileNameSS) {

    const char *base_path = "/Users/pv280546/alice/Hadronization/AnalyzedData/complete_root_10_05_2026/";
    const char *pathOS = Form("%s%s", base_path, fileNameOS);
    const char *pathSS = Form("%s%s", base_path, fileNameSS);

    TFile *fileOS = new TFile(pathOS);
    TFile *fileSS = new TFile(pathSS);

    TH2D *hDPhiDEtaOS = (TH2D*)fileOS->Get("hDPhiDEta");
    TH2D *hDPhiDEtaM60_100_OS = (TH2D*)fileOS->Get("hDPhiDEtaM60_100");
    TH2D *hDPhiDEtaM20_60_OS = (TH2D*)fileOS->Get("hDPhiDEtaM20_60");
    TH2D *hDPhiDEtaM00_20_OS = (TH2D*)fileOS->Get("hDPhiDEtaM00_20");
    TH2D *hDPhiDEtaSS = (TH2D*)fileSS->Get("hDPhiDEta");
    TH2D *hDPhiDEtaM60_100_SS = (TH2D*)fileSS->Get("hDPhiDEtaM60_100");
    TH2D *hDPhiDEtaM20_60_SS = (TH2D*)fileSS->Get("hDPhiDEtaM20_60");
    TH2D *hDPhiDEtaM00_20_SS = (TH2D*)fileSS->Get("hDPhiDEtaM00_20");

    TH1D *hTrPtOS = (TH1D*)fileOS->Get("hTrPt");
    TH1D *hTrPtM60_100_OS = (TH1D*)fileOS->Get("hTrPtM60_100");
    TH1D *hTrPtM20_60_OS = (TH1D*)fileOS->Get("hTrPtM20_60");
    TH1D *hTrPtM00_20_OS = (TH1D*)fileOS->Get("hTrPtM00_20");
    TH1D *hTrPtSS = (TH1D*)fileSS->Get("hTrPt");
    TH1D *hTrPtM60_100_SS = (TH1D*)fileSS->Get("hTrPtM60_100");
    TH1D *hTrPtM20_60_SS = (TH1D*)fileSS->Get("hTrPtM20_60");
    TH1D *hTrPtM00_20_SS = (TH1D*)fileSS->Get("hTrPtM00_20");

    // add code to scale by 1/2 for double counted B+B+ and D+D+

    hDPhiDEtaOS->Scale(1/hTrPtOS->Integral());
    hDPhiDEtaM60_100_OS->Scale(1/hTrPtM60_100_OS->Integral());
    hDPhiDEtaM20_60_OS->Scale(1/hTrPtM20_60_OS->Integral());
    hDPhiDEtaM00_20_OS->Scale(1/hTrPtM00_20_OS->Integral());
    hDPhiDEtaSS->Scale(1/hTrPtSS->Integral());
    hDPhiDEtaM60_100_SS->Scale(1/hTrPtM60_100_SS->Integral());
    hDPhiDEtaM20_60_SS->Scale(1/hTrPtM20_60_SS->Integral());
    hDPhiDEtaM00_20_SS->Scale(1/hTrPtM00_20_SS->Integral());

    // =====================================================
    // Inclusive OS - SS
    // =====================================================

    TH2D *hSubtracted = (TH2D*)hDPhiDEtaOS->Clone("hSubtracted");
    hSubtracted->Add(hDPhiDEtaSS, -1.0);
    hSubtracted->Rebin2D(5, 5);

    TCanvas *c1 = new TCanvas(Form("%s", title), Form("%s", title), 1200, 900);

    gStyle->SetPalette(kBird);

    hSubtracted->SetTitle(Form("%s;#Delta#varphi;#Delta#eta", title));
    hSubtracted->Draw("SURF1 FB");

    // =====================================================
    // Multiplicity-binned OS - SS
    // =====================================================

    TH2D *hSub_M00_20 = (TH2D*)hDPhiDEtaM00_20_OS->Clone("hSub_M00_20");
    TH2D *hSub_M20_60 = (TH2D*)hDPhiDEtaM20_60_OS->Clone("hSub_M20_60");
    TH2D *hSub_M60_100 = (TH2D*)hDPhiDEtaM60_100_OS->Clone("hSub_M60_100");

    // Subtract SS
    hSub_M00_20->Add(hDPhiDEtaM00_20_SS, -1.0);
    hSub_M20_60->Add(hDPhiDEtaM20_60_SS, -1.0);
    hSub_M60_100->Add(hDPhiDEtaM60_100_SS, -1.0);

    // Rebin
    hSub_M00_20->Rebin2D(5,5);
    hSub_M20_60->Rebin2D(5,5);
    hSub_M60_100->Rebin2D(5,5);

    // Titles
    hSub_M60_100->SetTitle(Form("%s 60-100;#Delta#varphi;#Delta#eta", title));
    hSub_M20_60->SetTitle(Form("%s 20-60;#Delta#varphi;#Delta#eta", title));
    hSub_M00_20->SetTitle(Form("%s 00-20;#Delta#varphi;#Delta#eta", title));

    // Canvas
    TCanvas *cMult = new TCanvas(Form("c_mult_%s", title), "Multiplicity bins", 2400, 800);
    cMult->Divide(3,1);

    // 60-100%
    cMult->cd(1);
    gPad->SetTheta(30);
    gPad->SetPhi(50);
    hSub_M60_100->Draw("SURF1 FB");

    // 20-60%
    cMult->cd(2);
    gPad->SetTheta(30);
    gPad->SetPhi(50);
    hSub_M20_60->Draw("SURF1 FB");

    // 0-20%
    cMult->cd(3);
    gPad->SetTheta(30);
    gPad->SetPhi(50);
    hSub_M00_20->Draw("SURF1 FB");

    c1->SaveAs("2D_correlations.pdf");
    cMult->SaveAs("2D_correlations.pdf");

    return;
}






int qq_draw_2D_correlations() {

    TCanvas *cdummy = new TCanvas();
    cdummy->SaveAs("2D_correlations.pdf(");
    do_draw_2D_correlations("D^{+}D^{-}", "DplusDminus.root", "DplusDplus.root");
    do_draw_2D_correlations("D^{+}#bar#Lambda_{c}^{+}", "DplusLambdacplusbar.root", "DplusLambdacplus.root");
    do_draw_2D_correlations("D^{+}#bar#Sigma_{c}^{+}", "DplusSigmacplusbar.root", "DplusSigmacplus.root");
    do_draw_2D_correlations("B^{+}B^{-}", "BplusBminus.root", "BplusBplus.root");
    do_draw_2D_correlations("B^{+}#Lambda_{b}^{0}", "BplusLb.root", "BplusLbbar.root");
    do_draw_2D_correlations("B^{+}#Sigma_{b}^{0}", "BplusSigmabzero.root", "BplusSigmabzerobar.root");
    cdummy->SaveAs("2D_correlations.pdf)");

    return 0;
}