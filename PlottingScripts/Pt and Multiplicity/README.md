# Pt and Multiplicity Plotting

This directory contains the plotting macros that read the analyzed heavy-flavor ROOT files and produce PNG plots for charm and beauty baryon-to-meson studies as a function of `pT` and multiplicity.

The macros read analyzed subsamples from:

```text
Hadronization/AnalyzedData/<DATE>/Beauty/
Hadronization/AnalyzedData/<DATE>/Charm/
```

and write plots to:

```text
Hadronization/PlottingScripts/Pt and Multiplicity/Plots/
```

## Workflow

1. Run the analysis macros first so that the subsample ROOT files exist in:
   - `AnalyzedData/<DATE>/Beauty/`
   - `AnalyzedData/<DATE>/Charm/`
2. Go to the Hadronization base directory.
3. Run one or more plotting macros for a specific date such as `12-01-2026`.
4. Collect the PNG outputs from `PlottingScripts/Pt and Multiplicity/Plots/`.

## Input structure

The plotting macros support both analyzed filename layouts:

```text
AnalyzedData/<DATE>/Beauty/bbbar_MONASH_sub0.root
AnalyzedData/<DATE>/Beauty/bbbar_JUNCTIONS_sub0.root
AnalyzedData/<DATE>/Charm/ccbar_MONASH_sub0.root
AnalyzedData/<DATE>/Charm/ccbar_JUNCTIONS_sub0.root

AnalyzedData/<DATE>/Beauty/hf_MONASH_sub0.root
AnalyzedData/<DATE>/Beauty/hf_JUNCTIONS_sub0.root
AnalyzedData/<DATE>/Charm/hf_MONASH_sub0.root
AnalyzedData/<DATE>/Charm/hf_JUNCTIONS_sub0.root
```

For date-based entry points, the macros automatically prefer the unified `hf_...` files when they are present and otherwise fall back to the legacy `ccbar_...` or `bbbar_...` files.

The number of subsamples passed to the plotting macro must match the number of subsamples produced by the analysis step.

For species-resolved plots, the macros assume charge-conjugate-combined histogram names first. If a combined histogram is not found, they look for the split `Particle` and `Bar` histograms and sum them on the fly.

## Statistical errors

The plotting macros assume the analyzed ROOT files were produced by the current `*_mult_pt_analysis_multi.C` scripts, which write histograms with `Sumw2` enabled and an explicit `fHistEventCount`.

The main statistical-error conventions are:

- pT spectra plots normalize each subsample spectrum first and then use the mean and SEM across subsamples for the plotted bin contents and uncertainties.
- pT baryon-to-meson ratio plots build the ratio in each subsample and then use the mean and SEM across subsamples for the final error bars.
- multiplicity-percentile ratio plots build one ratio point per subsample in each multiplicity class and then use the mean and SEM across subsamples for the final uncertainty.

## Date handling

- If a date is passed explicitly, the macro reads that folder.
- If no date is passed, the macro looks for the latest dated folder inside `AnalyzedData/`.
- The expected date format is:

```text
DD-MM-YYYY
```

## Output location

All plots are written to:

```text
PlottingScripts/Pt and Multiplicity/Plots/
```

Important: the output file names do not include the date. Running the same macro for a different date will overwrite plots with the same name unless the files are moved or renamed.

## Base path resolution

The plotting macros are not tied to one machine.

They resolve the Hadronization base directory in this order:

1. `HADRONIZATION_BASE` environment variable
2. The location of the loaded macro inside the repo
3. `base_path.txt`
4. The current working directory as a last fallback

In normal use, running the macro from a clone of the repo is enough.

## Convenience wrappers

Each plotting macro also provides a short wrapper that can be called after loading the macro in an interactive ROOT session.

Available wrappers:

```cpp
runBeautyRatios(const char* dateTag = "", int nSub = 10, int rebinFactor = 2);
runCharmRatios(const char* dateTag = "", int nSub = 10, int rebinFactor = 2);
runCharmBeautyRatios(const char* dateTag = "", int nSub = 10, int rebinFactor = 2);
runHFSpectra(const char* dateTag = "", int nSub = 10);
runHFRatios(const char* dateTag = "", int nSub = 10, double ptMin = 0.0, double ptMax = -1.0);
runHFSpeciesResolvedSpectra(const char* dateTag = "", const char* selectorTag = "Charm", int nSub = 10, bool includeHeavyBeautyExtras = false);
runHFSpeciesResolvedSpectraCharm(const char* dateTag = "", int nSub = 10, bool includeHeavyBeautyExtras = false);
runHFSpeciesResolvedSpectraBeauty(const char* dateTag = "", int nSub = 10, bool includeHeavyBeautyExtras = false);
runHFSpeciesResolvedSpectraBothTunes(const char* dateTag = "", int nSub = 10, bool includeHeavyBeautyExtras = false);
runHFSingleParticleSpectra(const char* dateTag = "", const char* selectorTag = "Dplus", int nSub = 10, bool includeHeavyBeautyExtras = false);
runHFSingleParticleSpectraCharm(const char* dateTag = "", int nSub = 10, bool includeHeavyBeautyExtras = false);
runHFSingleParticleSpectraBeauty(const char* dateTag = "", int nSub = 10, bool includeHeavyBeautyExtras = false);
runHFMinimumBiasSpectra(const char* dateTag = "", const char* selectorTag = "Charm", int nSub = 10, bool includeHeavyBeautyExtras = false);
runHFMinimumBiasSpectraCharm(const char* dateTag = "", int nSub = 10, bool includeHeavyBeautyExtras = false);
runHFMinimumBiasSpectraBeauty(const char* dateTag = "", int nSub = 10, bool includeHeavyBeautyExtras = false);
runHFMinimumBiasSpectraBoth(const char* dateTag = "", int nSub = 10, bool includeHeavyBeautyExtras = false);
```

Example interactive session:

```bash
root -l
```

```cpp
.L "PlottingScripts/Pt and Multiplicity/Plot_Beauty_BaryonMesonRatio_MONASH_vs_JUNCTIONS_subsamples.C"
runBeautyRatios("12-01-2026", 10, 2);

.L "PlottingScripts/Pt and Multiplicity/Plot_Charm_BaryonMesonRatio_MONASH_vs_JUNCTIONS_subsamples.C"
runCharmRatios("12-01-2026", 10, 2);

.L "PlottingScripts/Pt and Multiplicity/Plot_BaryonMesonRatio_CharmBeauty_MONASH_vs_JUNCTIONS_subsamples.C"
runCharmBeautyRatios("12-01-2026", 10, 2);

.L "PlottingScripts/Pt and Multiplicity/Plot_HF_PtSpectra_vsMultiplicity_MONASH_JUNCTIONS_subsamples.C"
runHFSpectra("12-01-2026", 10);

.L "PlottingScripts/Pt and Multiplicity/Plot_HF_Ratios_vsMultiplicityPercentile_subsamples.C"
runHFRatios("12-01-2026", 10, 0.0, -1.0);

.L "PlottingScripts/Pt and Multiplicity/Plot_HF_SpeciesResolvedPtSpectra_vsMultiplicity_subsamples.C"
runHFSpeciesResolvedSpectra("12-01-2026", "Charm", 10);

.L "PlottingScripts/Pt and Multiplicity/Plot_HF_SingleParticlePtSpectra_vsMultiplicity_MONASH_JUNCTIONS_subsamples.C"
runHFSingleParticleSpectra("12-01-2026", "Dzero", 10);

.L "PlottingScripts/Pt and Multiplicity/Plot_HF_MinimumBiasPtSpectra_MONASH_JUNCTIONS_subsamples.C"
runHFMinimumBiasSpectra("12-01-2026", "Charm", 10);
```

## Macros

### 1. Beauty baryon/meson ratios

Macro:

```text
Plot_Beauty_BaryonMesonRatio_MONASH_vs_JUNCTIONS_subsamples.C
```

What it makes:

- Beauty baryon / beauty meson ratio vs `pT`
- `Lambda_b / B+` ratio vs `pT`
- One plot per multiplicity percentile class

Default call:

```bash
root -l -b -q 'PlottingScripts/Pt and Multiplicity/Plot_Beauty_BaryonMesonRatio_MONASH_vs_JUNCTIONS_subsamples.C'
```

Specific date:

```bash
root -l -b -q 'PlottingScripts/Pt and Multiplicity/Plot_Beauty_BaryonMesonRatio_MONASH_vs_JUNCTIONS_subsamples.C("12-01-2026")'
```

Specific date, subsamples, and rebin:

```bash
root -l -b -q 'PlottingScripts/Pt and Multiplicity/Plot_Beauty_BaryonMesonRatio_MONASH_vs_JUNCTIONS_subsamples.C("12-01-2026", 10, 2)'
```

Interactive wrapper:

```bash
root -l
```

```cpp
.L "PlottingScripts/Pt and Multiplicity/Plot_Beauty_BaryonMesonRatio_MONASH_vs_JUNCTIONS_subsamples.C"
runBeautyRatios("12-01-2026", 10, 2);
```

Main outputs:

```text
Ratio_BeautyBaryonMeson_MONASH_vs_JUNCTIONS_*.png
Ratio_LambdabOverBpm_MONASH_vs_JUNCTIONS_*.png
```

### 2. Charm baryon/meson ratios

Macro:

```text
Plot_Charm_BaryonMesonRatio_MONASH_vs_JUNCTIONS_subsamples.C
```

What it makes:

- Charm baryon / charm meson ratio vs `pT`
- `(#Lambda_c + #bar{#Lambda}_c) / D^{#pm}` ratio vs `pT`
- One plot per multiplicity percentile class

Default call:

```bash
root -l -b -q 'PlottingScripts/Pt and Multiplicity/Plot_Charm_BaryonMesonRatio_MONASH_vs_JUNCTIONS_subsamples.C'
```

Specific date:

```bash
root -l -b -q 'PlottingScripts/Pt and Multiplicity/Plot_Charm_BaryonMesonRatio_MONASH_vs_JUNCTIONS_subsamples.C("12-01-2026")'
```

Specific date, subsamples, and rebin:

```bash
root -l -b -q 'PlottingScripts/Pt and Multiplicity/Plot_Charm_BaryonMesonRatio_MONASH_vs_JUNCTIONS_subsamples.C("12-01-2026", 10, 2)'
```

Interactive wrapper:

```cpp
.L "PlottingScripts/Pt and Multiplicity/Plot_Charm_BaryonMesonRatio_MONASH_vs_JUNCTIONS_subsamples.C"
runCharmRatios("12-01-2026", 10, 2);
```

Main outputs:

```text
Ratio_CharmBaryonMeson_MONASH_vs_JUNCTIONS_*.png
Ratio_LambdacOverDpm_MONASH_vs_JUNCTIONS_*.png
```

### 3. Combined charm and beauty baryon/meson ratios

Macro:

```text
Plot_BaryonMesonRatio_CharmBeauty_MONASH_vs_JUNCTIONS_subsamples.C
```

What it makes:

- One plot per multiplicity percentile class
- Each plot compares:
  - beauty MONASH
  - beauty JUNCTIONS
  - charm MONASH
  - charm JUNCTIONS

Default call:

```bash
root -l -b -q 'PlottingScripts/Pt and Multiplicity/Plot_BaryonMesonRatio_CharmBeauty_MONASH_vs_JUNCTIONS_subsamples.C'
```

Specific date:

```bash
root -l -b -q 'PlottingScripts/Pt and Multiplicity/Plot_BaryonMesonRatio_CharmBeauty_MONASH_vs_JUNCTIONS_subsamples.C("12-01-2026")'
```

Specific date, subsamples, and rebin:

```bash
root -l -b -q 'PlottingScripts/Pt and Multiplicity/Plot_BaryonMesonRatio_CharmBeauty_MONASH_vs_JUNCTIONS_subsamples.C("12-01-2026", 10, 2)'
```

Interactive wrappers:

```cpp
.L "PlottingScripts/Pt and Multiplicity/Plot_BaryonMesonRatio_CharmBeauty_MONASH_vs_JUNCTIONS_subsamples.C"
runCharmBeautyRatios("12-01-2026", 10, 2);
```

or

```cpp
runBaryonMesonCharmBeauty("12-01-2026", 10, 2);
```

Main outputs:

```text
Ratio_BaryonMeson_CharmBeauty_MONASH_vs_JUNCTIONS_*.png
```

### 4. Heavy-flavor pT spectra vs multiplicity

Macro:

```text
Plot_HF_PtSpectra_vsMultiplicity_MONASH_JUNCTIONS_subsamples.C
```

What it makes:

- `#Lambda_c + #bar{#Lambda}_c` spectra by multiplicity percentile
- `D^{#pm}` spectra by multiplicity percentile
- `#Lambda_b + #bar{#Lambda}_b` spectra by multiplicity percentile
- `B^{#pm}` spectra by multiplicity percentile
- Separate plots for MONASH and JUNCTIONS

Default call:

```bash
root -l -b -q 'PlottingScripts/Pt and Multiplicity/Plot_HF_PtSpectra_vsMultiplicity_MONASH_JUNCTIONS_subsamples.C'
```

Specific date:

```bash
root -l -b -q 'PlottingScripts/Pt and Multiplicity/Plot_HF_PtSpectra_vsMultiplicity_MONASH_JUNCTIONS_subsamples.C("12-01-2026")'
```

Specific date and subsamples:

```bash
root -l -b -q 'PlottingScripts/Pt and Multiplicity/Plot_HF_PtSpectra_vsMultiplicity_MONASH_JUNCTIONS_subsamples.C("12-01-2026", 10)'
```

Interactive wrapper:

```cpp
.L "PlottingScripts/Pt and Multiplicity/Plot_HF_PtSpectra_vsMultiplicity_MONASH_JUNCTIONS_subsamples.C"
runHFSpectra("12-01-2026", 10);
```

Main outputs:

```text
Spectra_Lambdac_MONASH.png
Spectra_Lambdac_JUNCTIONS.png
Spectra_Dpm_MONASH.png
Spectra_Dpm_JUNCTIONS.png
Spectra_Lambdab_MONASH.png
Spectra_Lambdab_JUNCTIONS.png
Spectra_Bpm_MONASH.png
Spectra_Bpm_JUNCTIONS.png
```

Advanced custom-prefix wrapper:

```cpp
runHFSpectraWithPrefixes("/full/path/to/Charm/hf_MONASH_sub",
                         "/full/path/to/Charm/hf_JUNCTIONS_sub",
                         "/full/path/to/Beauty/hf_MONASH_sub",
                         "/full/path/to/Beauty/hf_JUNCTIONS_sub",
                         10);
```

You can also pass the legacy `ccbar_...` and `bbbar_...` stems explicitly if you are plotting an older split analysis sample.

### 5. Heavy-flavor ratios vs multiplicity percentile

Macro:

```text
Plot_HF_Ratios_vsMultiplicityPercentile_subsamples.C
```

What it makes:

- `(#Lambda_c + #bar{#Lambda}_c) / D^{#pm}` vs multiplicity percentile
- `(#Lambda_b + #bar{#Lambda}_b) / B^{#pm}` vs multiplicity percentile

Default call:

```bash
root -l -b -q 'PlottingScripts/Pt and Multiplicity/Plot_HF_Ratios_vsMultiplicityPercentile_subsamples.C'
```

Specific date:

```bash
root -l -b -q 'PlottingScripts/Pt and Multiplicity/Plot_HF_Ratios_vsMultiplicityPercentile_subsamples.C("12-01-2026")'
```

Specific date, subsamples, and pT range:

```bash
root -l -b -q 'PlottingScripts/Pt and Multiplicity/Plot_HF_Ratios_vsMultiplicityPercentile_subsamples.C("12-01-2026", 10, 0.0, -1.0)'
```

Notes:

- `ptMin` and `ptMax` define the integrated `pT` range.
- If `ptMax <= ptMin`, the macro integrates all `pT` bins.

Interactive wrapper:

```cpp
.L "PlottingScripts/Pt and Multiplicity/Plot_HF_Ratios_vsMultiplicityPercentile_subsamples.C"
runHFRatios("12-01-2026", 10, 0.0, -1.0);
```

Main outputs:

```text
Ratio_Lambdac_over_Dpm_vsMult.png
Ratio_Lambdab_over_Bpm_vsMult.png
```

### 6. Species-resolved heavy-flavour pT spectra

Macro:

```text
Plot_HF_SpeciesResolvedPtSpectra_vsMultiplicity_subsamples.C
```

What it makes:

- For `Charm` or `Beauty`, five wide comparison canvases, one for each multiplicity percentile
- In each comparison canvas, `MONASH` is on the left and `JUNCTIONS` is on the right
- Inside each tune panel, the default flavor list is overlaid for the selected multiplicity percentile:
- `Charm`: `D0`, `D+`, `D-`, `Ds`, `Lambdac`
- `Beauty`: `B+`, `B-`, `B0`, `Bs`, `Bc`, `Lambdab`
- Bin-by-bin uncertainties from the spread across subsamples, shown as mean ± SEM

Histogram handling:

- If `<base>Particle` and `<base>Bar` histograms are present, the macro uses them for the charge-separated entries.
- Otherwise it uses the single histogram object that is present in the file and takes the displayed species label from that histogram title.
- The heavier beauty states `Sigmab`, `Xib`, and `Omegab` are available through the extra boolean switch `includeHeavyBeautyExtras`, which is `false` by default.

Default call:

```bash
root -l -b -q 'PlottingScripts/Pt and Multiplicity/Plot_HF_SpeciesResolvedPtSpectra_vsMultiplicity_subsamples.C'
```

Specific date and flavor comparison:

```bash
root -l -b -q 'PlottingScripts/Pt and Multiplicity/Plot_HF_SpeciesResolvedPtSpectra_vsMultiplicity_subsamples.C("12-01-2026", "Charm", 10)'
```

Beauty comparison:

```cpp
.L "PlottingScripts/Pt and Multiplicity/Plot_HF_SpeciesResolvedPtSpectra_vsMultiplicity_subsamples.C"
runHFSpeciesResolvedSpectraBeauty("12-01-2026", 10);
```

Beauty comparison with heavier beauty states re-enabled:

```cpp
.L "PlottingScripts/Pt and Multiplicity/Plot_HF_SpeciesResolvedPtSpectra_vsMultiplicity_subsamples.C"
runHFSpeciesResolvedSpectraBeauty("12-01-2026", 10, true);
```

Legacy single-tune view:

```cpp
.L "PlottingScripts/Pt and Multiplicity/Plot_HF_SpeciesResolvedPtSpectra_vsMultiplicity_subsamples.C"
runHFSpeciesResolvedSpectra("12-01-2026", "MONASH", 10);
```

Main outputs:

```text
SpeciesResolvedSpectraCompareTunes_Charm_0_20_<DATE>.png
SpeciesResolvedSpectraCompareTunes_Charm_20_40_<DATE>.png
SpeciesResolvedSpectraCompareTunes_Charm_40_60_<DATE>.png
SpeciesResolvedSpectraCompareTunes_Charm_60_80_<DATE>.png
SpeciesResolvedSpectraCompareTunes_Charm_80_100_<DATE>.png
SpeciesResolvedSpectraCompareTunes_Beauty_0_20_<DATE>.png
SpeciesResolvedSpectraCompareTunes_Beauty_20_40_<DATE>.png
SpeciesResolvedSpectraCompareTunes_Beauty_40_60_<DATE>.png
SpeciesResolvedSpectraCompareTunes_Beauty_60_80_<DATE>.png
SpeciesResolvedSpectraCompareTunes_Beauty_80_100_<DATE>.png
```

Legacy outputs kept for the single-tune mode:

```text
SpeciesResolvedSpectra_Charm_<TUNE>_<DATE>.png
SpeciesResolvedSpectra_Charm_<TUNE>_<DATE>.pdf
SpeciesResolvedSpectra_Beauty_<TUNE>_<DATE>.png
SpeciesResolvedSpectra_Beauty_<TUNE>_<DATE>.pdf
```

### 7. Single-particle heavy-flavour pT spectra vs multiplicity

Macro:

```text
Plot_HF_SingleParticlePtSpectra_vsMultiplicity_MONASH_JUNCTIONS_subsamples.C
```

What it makes:

- For one selected particle, one wide comparison canvas with `MONASH` on the left and `JUNCTIONS` on the right
- In each tune panel, the five multiplicity percentile spectra are overlaid in the original-style layout
- If `Charm` or `Beauty` is passed instead of one particle, the macro loops over the default flavor list automatically:
- `Charm`: `D0`, `D+`, `D-`, `Ds`, `Lambdac`
- `Beauty`: `B+`, `B-`, `B0`, `Bs`, `Bc`, `Lambdab`
- Bin-by-bin uncertainties from the spread across subsamples, shown as mean ± SEM

Selector handling:

- Supported flavor selectors: `Charm`, `Beauty`
- Supported particle selectors include `Dzero`, `Dplus`, `Dsplus`, `Lambdac`, `Bplus`, `Bzero`, `Bs0`, `Bcplus`, `Lambdab`, `SigmabPlus`, `SigmabZero`, `SigmabMinus`, `XibZero`, `XibMinus`, `OmegabMinus`
- Positive-particle requests prefer split `Particle` histograms if they exist and otherwise fall back to the direct histogram in the file
- Anti-particle requests use split `Bar` histograms when they are available
- The heavier beauty states `Sigmab`, `Xib`, and `Omegab` are excluded from the default `Beauty` loop and can be re-enabled with `includeHeavyBeautyExtras = true`

Specific date and one particle:

```bash
root -l -b -q 'PlottingScripts/Pt and Multiplicity/Plot_HF_SingleParticlePtSpectra_vsMultiplicity_MONASH_JUNCTIONS_subsamples.C("12-01-2026", "Dzero", 10)'
```

All charm particles:

```bash
root -l -b -q 'PlottingScripts/Pt and Multiplicity/Plot_HF_SingleParticlePtSpectra_vsMultiplicity_MONASH_JUNCTIONS_subsamples.C("12-01-2026", "Charm", 10)'
```

Interactive wrapper:

```cpp
.L "PlottingScripts/Pt and Multiplicity/Plot_HF_SingleParticlePtSpectra_vsMultiplicity_MONASH_JUNCTIONS_subsamples.C"
runHFSingleParticleSpectraBeauty("12-01-2026", 10);
```

Interactive wrapper with heavier beauty states re-enabled:

```cpp
.L "PlottingScripts/Pt and Multiplicity/Plot_HF_SingleParticlePtSpectra_vsMultiplicity_MONASH_JUNCTIONS_subsamples.C"
runHFSingleParticleSpectraBeauty("12-01-2026", 10, true);
```

Main outputs:

```text
SingleParticleSpectra_Dzero_<DATE>.png
SingleParticleSpectra_Dplus_<DATE>.png
SingleParticleSpectra_Bplus_<DATE>.png
...
```

### 8. Minimum-bias heavy-flavour pT spectra

Macro:

```text
Plot_HF_MinimumBiasPtSpectra_MONASH_JUNCTIONS_subsamples.C
```

What it makes:

- For `Charm` or `Beauty`, one minimum-bias species-overlay comparison canvas with `MONASH` on the left and `JUNCTIONS` on the right
- For the same flavor call, one minimum-bias side-by-side comparison canvas per particle, again with `MONASH` on the left and `JUNCTIONS` on the right
- The default flavor lists are:
- `Charm`: `D0`, `D+`, `D-`, `Ds`, `Lambdac`
- `Beauty`: `B+`, `B-`, `B0`, `Bs`, `Bc`, `Lambdab`
- Bin-by-bin uncertainties from the spread across subsamples, shown as mean ± SEM

Histogram handling:

- The minimum-bias spectrum is the inclusive `0-100%` projection over the full multiplicity axis
- Positive-particle requests prefer split `Particle` histograms if they exist and otherwise fall back to the direct histogram in the file
- Anti-particle requests use split `Bar` histograms when they are available
- The heavier beauty states `Sigmab`, `Xib`, and `Omegab` are excluded from the default `Beauty` loop and can be re-enabled with `includeHeavyBeautyExtras = true`

Specific date and one flavor:

```bash
root -l -b -q 'PlottingScripts/Pt and Multiplicity/Plot_HF_MinimumBiasPtSpectra_MONASH_JUNCTIONS_subsamples.C("12-01-2026", "Charm", 10)'
```

Beauty with heavier beauty states re-enabled:

```bash
root -l -b -q 'PlottingScripts/Pt and Multiplicity/Plot_HF_MinimumBiasPtSpectra_MONASH_JUNCTIONS_subsamples.C("12-01-2026", "Beauty", 10, true)'
```

Single particle:

```bash
root -l -b -q 'PlottingScripts/Pt and Multiplicity/Plot_HF_MinimumBiasPtSpectra_MONASH_JUNCTIONS_subsamples.C("12-01-2026", "Dplus", 10)'
```

Interactive wrapper:

```cpp
.L "PlottingScripts/Pt and Multiplicity/Plot_HF_MinimumBiasPtSpectra_MONASH_JUNCTIONS_subsamples.C"
runHFMinimumBiasSpectraBeauty("12-01-2026", 10);
```

Main outputs:

```text
MinimumBiasSpeciesResolvedSpectraCompareTunes_Charm_<DATE>.png
MinimumBiasSpeciesResolvedSpectraCompareTunes_Beauty_<DATE>.png
MinimumBiasSingleParticleSpectra_Dzero_<DATE>.png
MinimumBiasSingleParticleSpectra_Dplus_<DATE>.png
MinimumBiasSingleParticleSpectra_Bplus_<DATE>.png
...
```

## Recommended usage

From the Hadronization base directory:

```bash
cd /path/to/Hadronization
```

Beauty ratios:

```bash
root -l -b -q 'PlottingScripts/Pt and Multiplicity/Plot_Beauty_BaryonMesonRatio_MONASH_vs_JUNCTIONS_subsamples.C("12-01-2026", 10, 2)'
```

Charm ratios:

```bash
root -l -b -q 'PlottingScripts/Pt and Multiplicity/Plot_Charm_BaryonMesonRatio_MONASH_vs_JUNCTIONS_subsamples.C("12-01-2026", 10, 2)'
```

Combined charm and beauty:

```bash
root -l -b -q 'PlottingScripts/Pt and Multiplicity/Plot_BaryonMesonRatio_CharmBeauty_MONASH_vs_JUNCTIONS_subsamples.C("12-01-2026", 10, 2)'
```

Spectra:

```bash
root -l -b -q 'PlottingScripts/Pt and Multiplicity/Plot_HF_PtSpectra_vsMultiplicity_MONASH_JUNCTIONS_subsamples.C("12-01-2026", 10)'
```

Ratios vs multiplicity:

```bash
root -l -b -q 'PlottingScripts/Pt and Multiplicity/Plot_HF_Ratios_vsMultiplicityPercentile_subsamples.C("12-01-2026", 10, 0.0, -1.0)'
```

Species-resolved spectra:

```bash
root -l -b -q 'PlottingScripts/Pt and Multiplicity/Plot_HF_SpeciesResolvedPtSpectra_vsMultiplicity_subsamples.C("12-01-2026", "Charm", 10)'
```

Single-particle spectra for all particles of one flavor:

```bash
root -l -b -q 'PlottingScripts/Pt and Multiplicity/Plot_HF_SingleParticlePtSpectra_vsMultiplicity_MONASH_JUNCTIONS_subsamples.C("12-01-2026", "Charm", 10)'
```

Minimum-bias spectra:

```bash
root -l -b -q 'PlottingScripts/Pt and Multiplicity/Plot_HF_MinimumBiasPtSpectra_MONASH_JUNCTIONS_subsamples.C("12-01-2026", "Charm", 10)'
```

Species-resolved spectra for both flavors:

```cpp
.L "PlottingScripts/Pt and Multiplicity/Plot_HF_SpeciesResolvedPtSpectra_vsMultiplicity_subsamples.C"
runHFSpeciesResolvedSpectraBothTunes("12-01-2026", 10);
```

## Common issues

### Missing files

If a macro reports missing ROOT files, check:

- that the analysis step already ran
- that the date exists under `AnalyzedData/`
- that `nSub` matches the available `sub0`, `sub1`, ..., `subN` files

### Wrong date selected

If no date is passed, the macro will use the latest dated folder it finds. Pass the date explicitly if a specific production must be used.

### Plots overwritten

The plots are always written to the same `Plots/` directory. If multiple productions must be kept, move or rename the files after each run.
