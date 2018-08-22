/**************************************************************************************
 * Header File:
 *    Atom : Representation of an Atom object.
 * Author:
 *    Carlos Leon. MSG-BYU
 *************************************************************************************/

#ifndef ATOM_h
#define ATOM_h

#include "VectT.h"

class Atom
{
private:
   
   string chemName;
   VectT<float> position;
   
   
public:
   
   int idNumber;
   int chemType;
   VectT<float> forces;
  
   Atom(){}
   
   Atom(const Atom &atom){*this = atom;}
   
   Atom(VectT<float> position, int chemType, string chemName)
   {
      set(position, chemType, chemName);
   }
   
   void set(VectT<float> position, int chemType, string chemName)
   {
      setPosition(position);
      setChemType(chemType);
      setChemName(chemName);
   }
   
   Atom &operator = (const Atom &rhs)
   {
      position = rhs.position;
      chemType = rhs.chemType;
      chemName = rhs.chemName;
      idNumber = rhs.idNumber;
      forces = rhs.forces;
      return *this;
   }
   
   // setters
   void setPosition(const VectT<float> &vectT) { position = vectT; }
   void setChemType(int chemType) {this->chemType = chemType;}
   void setChemName(string chemName) {this->chemName = chemName;}
   
   // getters
   int getChemType() {return chemType;}
   string getChemName() {return chemName;}   
   VectT<float> getPosition(){return position;}
   
   //   int factorial(int n)
   //   {
   //      return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
   //   }


   /***********************************************************************************
    * OPERATOR OVERLOADING >>
    **********************************************************************************/
   friend istream &operator >> (istream &in, Atom &atom)
   {
      in >> atom.idNumber;
      in >> atom.chemType;
      
      float temp;
      
      in >> temp;
      atom.position.push_back(temp); // cartes_x
      in >> temp;
      atom.position.push_back(temp); // cartes_y
      in >> temp;
      atom.position.push_back(temp); // cartes_z
      
      in >> temp;
      atom.forces.push_back(temp); // fx
      in >> temp;
      atom.forces.push_back(temp); // fy
      in >> temp;
      atom.forces.push_back(temp); // fz
           
      return in;
   }

};


#endif /* VectT_h */
