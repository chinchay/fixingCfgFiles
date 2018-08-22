# fixingCfgFiles
Just modify the following lines in fixing_cfgFiles.cpp:

  ## Names of all the participant elements:
  vector<string> allElementNames = {string("Co"), string{"Ni"}, string("Ti")};

  ## *.cfg file got from the mlp command: mlp select-add pot.mtp train.cfg new.cfg diff.cfg
  string cfgFileName = "diff.cfg";

  ## POSCAR file name:
  string poscarFileName = "POSCAR";
