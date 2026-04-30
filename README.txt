Hadronization

The canonical repository description is now written in README.md. This text file is kept because older notes and scripts may still refer to README.txt, but the maintained documentation is the Markdown README at the repository root and the specialized README files under SimulationScripts, AnalysisScripts, PlottingScripts, and the Condor notes.

In short, we now use this repository to generate PYTHIA 8 heavy-flavour samples, reduce the raw ROOT trees into subsampled analysis histograms, and make the current MONASH-versus-JUNCTIONS comparison plots. The preferred production is the unified heavy-flavour chain, where charm and beauty are generated in the same run and analyzed with AnalysisScripts/hf_mult_pt_analysis_multi.C. The split bbbar and ccbar chain remains available for independent reference samples and comparisons to older productions.

Use README.md for the full repository-level workflow.
