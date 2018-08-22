# fixingCfgFiles
To use this code, it is necessary a POSCAR file with a head containing element names.
To customize it, just modify the following lines in fixing_cfgFiles.cpp:

  ## Names of all participant elements: 
  Write down the names of all the chemical elements in your project, even if is not present in the POSCAR (case of binary in a Poscar Co Ni, for example):
  vector<string> allElementNames = {string("Co"), string{"Ni"}, string("Ti")};

  ## *.cfg file got from the mlp command: mlp select-add pot.mtp train.cfg new.cfg diff.cfg
  string cfgFileName = "diff.cfg";

  ## POSCAR file name:
  string poscarFileName = "POSCAR";
