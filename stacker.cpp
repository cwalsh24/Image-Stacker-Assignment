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
  //pixels; 
}

void Stacker::fileLoader(){
  int temporary = 0;
  ifstream in;
  string fileName;
  string folderName; 
  cout << "Please enter the image you wish to stack: "; 
  cin >> folderName; 

  
  fileName = folderName + "/" + folderName + "_0" + endNumber + ".ppm"; //this will get the file name, but we need to figure out how to get the numbers 
  in.open(fileName.c_str());

  int count = 0;
  in >> temporary;

  while(in){

  }

}

