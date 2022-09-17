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
  pixels.red = 0;
  pixels.green = 0;
  pixels.blue = 0; 
}

void Stacker::fileLoader(){
  int temporary = 0;
  ifstream in;
  string fileName;
  string folderName;
  int numberOfImages; 
  cout << "Please enter the image you wish to stack: "; 
  cin >> folderName;
  //getline();? Might need this to get rid of the space
  
  cout << "Please enter the number of images: ";
  cout >> numberOfImages;
  //Something like these will get the correct file name depending on the number of files the user wants to get.
  //We might want to put in an else statement to end the method if the number is less than one or more than 99 
  if(numberOfImages < 10){
    fileName = folderName + "/" + folderName + "_00" + numberOfImages + ".ppm";
  }
  
  if(10 <= numberOfImages){
    fileName = folderName + "/" + folderName + "_00" + numberOfImages + ".ppm";
  }

  in.open(fileName.c_str());

  int count = 0;
  in >> temporary;

  while(in){

  }

}

