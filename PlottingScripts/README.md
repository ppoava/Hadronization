** in progress **

The most developped script is the `improvedPlotting_THnSparse`, using the configuration `configuration_multiplicity_reduced_JUNCTIONS_THnSparse.json`. When things are finalised I will change the names and remove the by-then legacy code.
Note that the configuration also draws Sigma_b baryons (Sigma_c not available in current simulation output). At a later stage this can be removed, as we will focus on the Lambda baryons instead.

To run the macro, one needs to use the same input file structure, or change it. The one I use is like the screenshot below.
![input_structure](image.png)
--- i.e. basically having a path to a folder containing MONASH and JUNCTIONS (and in general, TUNE) folders and these ones contain then the the complete_root directories. 
For subsampling I did something similar, but I would anyways like to improve how it's done, so this could be changed (and the way it is implemented in the newest folder with that path it doesn't actually work; it requires the THnSparses)

Actually running the macro is done with the following command: `root 'improvedPlotting_THnSparse.C("configuration_multiplicity_reduced_JUNCTIONS_THnSparse.json")'`