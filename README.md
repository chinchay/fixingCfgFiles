# fixingCfgFiles
To use this code, it is necessary a POSCAR file with a head containing element names.
To customize it, just modify the following lines in fixing_cfgFiles.cpp:

  ## Names of all participant elements: 
  Write down the names of all the chemical elements in your project, even if is not present in the POSCAR (a binary may be part of a ternary alloy study, for example):
  
  vector<string> allElementNames = {string("Co"), string{"Ni"}, string("Ti")};

  ## Name of the *.cfg file got from the mlp (select-add):
  A diff.cfg is obtained after executing `mlp select-add pot.mtp train.cfg new.cfg diff.cfg`:
  string cfgFileName = "diff.cfg";

  ## POSCAR file name:
  string poscarFileName = "POSCAR";
