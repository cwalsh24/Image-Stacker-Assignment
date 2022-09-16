/**
 * @file stacker.cpp
 * @author Connor Walsh
 * @date 2022-09-14
 * @brief This is the stacker source code
 * 
 * stuff
 */

#include "stacker.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string> 

using namespace std;

Stacker::Stacker(){
  magic_number; 
  width = 0;
  height = 0;//height before width
  max_color = 255;
  p(0, 0, 0); 
  pixels; 
}

void Stacker::fileLoader(){
  int temporary = 0;
  ifstream in;
  string fileName;
  cout << "What file do you want to open? ";
  cin >> fileName; //type the path of the file ppms/.ppm 
  in.open(fileName.c_str());

  int count = 0;
  in >> temporary;

  while(in){

  }

}

