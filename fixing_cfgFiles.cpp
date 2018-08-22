/*****************************************************************************
* Program:
* fixing_cfgFiles.cpp
*
* Author:
*    Carlos Leon. MSG-BYU
*
* Summary:
*
*     This program fixes the error in the types of diff.cfg files. If a
*     POSCAR file have the element types Ti and Ni, 4 atoms of both in every
*     unit cell, and the .cfg file has types  0 0 0 0 1 1 1 1, then the Program
*     should replace it by 1 1 1 1 2 2 2 2.
*
*****************************************************************************/

#include <iostream>
#include <fstream>      // input and output of files
#include <iomanip>      // we will use setw() in this code
#include <sstream>      //  used for  strinstream
#include <string>
#include <vector>

#include "Cfg.h"
#include "Atom.h"
#include "VectT.h"
//#include "ChemicalTypes.h"

using namespace std;

/*****************************************************************************
 * This funcion reads which elements (Co, Ni or Ti) are in the POSCAR file. The
 * listType array is built by knowing the occupation of each atom. For example,
 * if the elements in the POSCAR are Ni and Ti, and the occupation are 3 and 5,
 * then the listType would be = 1 1 1 2 2 2 2 2, where '1' refers to Ni, and
 * '2' refers to Ti.
 *****************************************************************************/
vector<int> getRightTypes(vector<string> allElementNames, string headPoscar)
{
   VectT<string> chemNamesInHead; // vector with the names of participant elements
   
   stringstream buffer(headPoscar);
   buffer >> chemNamesInHead; // will collect unary, or binary, or ternary, or ...
   
   int n_ary = chemNamesInHead.size(); // n = {1,2,3,...}
   
   vector<int> types;
   for (int i = 0; i < n_ary; i++)
   {
      for (int j = 0; j < allElementNames.size(); j++)
      {
         if ( chemNamesInHead[i] == allElementNames[j])
         {
            types.push_back(j);
         }
      }
   }
   return types;
}

/*****************************************************************************
 * This funcion reads which elements (Co, Ni or Ti) are in the POSCAR file. The
 * listType array is built by knowing the occupation of each atom. For example,
 * if the elements in the POSCAR are Ni and Ti, and the occupation are 3 and 5,
 * then the listType would be = 1 1 1 2 2 2 2 2, where '1' refers to Ni, and
 * '2' refers to Ti.
 *****************************************************************************/
void correcTypesInCfg(vector<string> allElementNames, string headPoscar, Cfg &cfg)
{
   vector<int> types = getRightTypes(allElementNames, headPoscar);
   for (int i = 0; i < cfg.atoms.size(); i++)
      cfg.atoms[i].chemType = types[ cfg.atoms[i].chemType ];
   
}

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   //   vector<string> allElementNames = getAllElementNames();
   vector<string> allElementNames = {string("Co"), string{"Ni"}, string("Ti"), string("Al")};

   string cfgFileName = "diff.cfg";
   Cfg cfg(cfgFileName);
   
   string poscarFileName = "POSCAR";
//   Poscar poscar(poscarFileName);
   ifstream fin(poscarFileName.c_str());
   string headPoscar;
   getline(fin, headPoscar);
   fin.close();
   
   
//   correcTypesInCfg(allElementNames, poscar.head, cfg);
   correcTypesInCfg(allElementNames, headPoscar, cfg);
   
   string cfgFileOut = "diff_fixed.cfg";
   ofstream fout(cfgFileOut.c_str());
   fout << cfg << endl;
   fout.close();
   
   return 0;
}

/***********************************************************************
* The *.cfg file has the following face:

BEGIN_CFG
 Size
    8
 Supercell
        -2.870000      0.000000      2.870000
         0.000000     -5.740000      0.000000
         4.305000     -1.435000      1.435000
 AtomData:  id type       cartes_x      cartes_y      cartes_z           fx          fy          fz
             1    0       0.000000      0.000000      0.000000    -0.061748   -0.141426   -0.061748
             2    0       1.435000     -1.435000      1.435000    -0.003687   -0.012858   -0.003687
             3    0       0.000000     -2.870000      2.870000     0.232110    0.368754    0.232110
             4    1      -1.435000     -1.435000      1.435000    -0.105045    0.366426   -0.105045
             5    1       1.435000     -4.305000      1.435000    -0.041126   -0.188016   -0.041126
             6    1      -1.435000     -4.305000      1.435000     0.138471   -0.368570    0.138471
             7    1       0.000000     -5.740000      2.870000    -0.154100   -0.210589   -0.154100
             8    2       0.000000     -2.870000      0.000000    -0.004875    0.186281   -0.004875
 Energy
        -50.565676610000
 PlusStress:  xx          yy          zz          yz          xz          xy
        -5.07408    -5.00971    -5.07408     0.00534    -0.23650     0.00534
 Feature   EFS_by       VASP
END_CFG
*************************************************************************/

