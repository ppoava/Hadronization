# Plotting Scripts

This directory contains the plotting layer for the hadronization analysis. The current paper workflow is centered on Paul's THnSparse plotting macro and treats `MONASH`, `JUNCTIONS`, and `CLOSEPACKING` as equal tunes.

## Paper THnSparse Inputs

Paul's plotting macro does not read the raw PYTHIA ROOT trees directly. It reads pair-named ROOT files produced by:

```text
AnalysisScripts/status_analysis_THnSparse_qq.C
```

Those pair files contain:

```text
summed MULTIPLICITY
hTrKinematics
hAsKinematics
hCorrelations
```

The root-level scripts create the expected input layout:

```bash
./submit_status_analysis.sh ALL 100 Job700
./merge_root_files.sh ALL Job700 21_06_2026
./make_subsamples.sh
```

For a smaller validation run, change the number of raw files passed to `submit_status_analysis.sh` and use distinct output tags when merging and subsampling. The submit wrapper sorts available files by numeric job id and selects the first N completed files for each tune; it does not require the selected files to be exactly job ids `0` through `N-1`.

`make_subsamples.sh` uses non-overlapping shuffled partitions by default. With no arguments, it runs the final paper default: all three tunes, ten independent 10-job subsamples per tune, `Job700` input, and `SUBSAMPLES_700` output. This covers all 100 jobs per tune.

When using distinct validation tags, copy one of the JSON configs and update:

```text
bb_bar_complete_root_dir
cc_bar_complete_root_dir
bb_bar_complete_root_dir_sub_samples
cc_bar_complete_root_dir_sub_samples
```

Then run the paper runner with the copied config through `THNSPARSE_CONFIG`, `THNSPARSE_COMPLETE_ROOT_CONFIG`, or `MULTIPLICITY_CONFIG`.

Expected complete-root inputs:

```text
AnalyzedData/complete_root_21_06_2026_MONASH
AnalyzedData/complete_root_21_06_2026_JUNCTIONS
AnalyzedData/complete_root_21_06_2026_CLOSEPACKING
```

Expected subsample inputs when `calculate_errors` is enabled:

```text
AnalyzedData/SUBSAMPLES_700/combined_root_subSamples_MONASH
AnalyzedData/SUBSAMPLES_700/combined_root_subSamples_JUNCTIONS
AnalyzedData/SUBSAMPLES_700/combined_root_subSamples_CLOSEPACKING
```

The plotting macro accepts both this flat layout and a nested tune layout.

## Main Paper Runner

Use the paper runner from the repository root:

```bash
./PlottingScripts/run_paper_plots.sh list
./PlottingScripts/run_paper_plots.sh smoke
./PlottingScripts/run_paper_plots.sh
```

Targets:

- `smoke`: multiplicity-boundary plot plus complete-root THnSparse plots without subsampling.
- `thnsparse-complete-root`: Paul's THnSparse plots without subsampling.
- `thnsparse`: Paul's full THnSparse plots with subsampling if enabled in the config.
- `multiplicity-boundaries`: charged-particle multiplicity distribution with percentile boundary lines.
- `all` / `paper`: multiplicity boundaries plus the full THnSparse config.

The runner resolves the repository root from `HADRONIZATION_BASE` or from its own location, sources `setupEnv.sh` when present, and runs ROOT in batch mode.

## THnSparse Configs

Full config with subsampling:

```text
PlottingScripts/configuration_multiplicity_reduced_JUNCTIONS_THnSparse.json
```

Complete-root-only config for smoke tests:

```text
PlottingScripts/configuration_multiplicity_reduced_JUNCTIONS_THnSparse_complete_root.json
```

Both configs use the same tunes and event-activity classes:

```text
0-1, 1-10, 10-20, 20-30, 30-40, 40-50,
50-60, 60-70, 70-80, 80-90, 90-100
```

All paths in the configs are relative to the Hadronization checkout unless they are absolute paths or `NONE`.

## Direct ROOT Commands

Complete-root smoke test:

```bash
root -l -b <<'ROOT'
.L PlottingScripts/improvedPlotting_THnSparse.C+
improvedPlotting_THnSparse("PlottingScripts/configuration_multiplicity_reduced_JUNCTIONS_THnSparse_complete_root.json")
.q
ROOT
```

Full THnSparse plotting:

```bash
root -l -b <<'ROOT'
.L PlottingScripts/improvedPlotting_THnSparse.C+
improvedPlotting_THnSparse("PlottingScripts/configuration_multiplicity_reduced_JUNCTIONS_THnSparse.json")
.q
ROOT
```

Multiplicity-boundary plot:

```bash
root -l -b -q 'PlottingScripts/Plot_MultiplicityDistribution_PercentileBoundaries.C'
```

## Outputs

The current paper runner writes under:

```text
PlottingScripts/Plots/THnSparse
PlottingScripts/Plots/THnSparseCompleteRoot
PlottingScripts/Plots/MultiplicityDistribution
```

These are generated artifacts and are ignored by Git. Regenerate them from the macros instead of committing them.

## Older Plotting Code

The directory still contains older plotting macros such as `improvedPlotting.C`, `combinedCanvasPlots.C`, `B_Balancing_GeneralPlotting.C`, and `PlottingWizard.C`. They are kept for reference and older studies, but the current paper pipeline should start from `run_paper_plots.sh` and the THnSparse configs above.
