/**
 * @file stacker.cpp
 * @author Code4Days (Connor Walsh, Isaac Copeland)
 * @date 2022-09-23
 * @brief this is the stacker source code
 * 
 * This file contains the implementation for the stacker class.
 */

#include <iostream> 
#include <fstream>
#include "stacker.h"  

using namespace std;

Stacker::Stacker(){
  //This code initializes all of the image header variables. 
  magic_number = "";   
  height = 0;
  width = 0; 
  max_color = 0; 
}

void Stacker::fileLoader(string folderName, int numberOfImages){
  ifstream in;
  string fileName;
  //These are the temp variables for the priming read and while loop. 
  int tempR, tempG, tempB;
  //This vector reads in the color values from the file. 
  vector<pixel> pVec;
  
  //These two if statements set the correct file locations equal to the fileName string
  //and print said file names for the user to see. 
  if(numberOfImages < 10){ 
    fileName = "ppms/" + folderName + "/" + folderName + "_00" + to_string(numberOfImages) + ".ppm";
    cout << "\t" + fileName << endl;
  }
  
  if(10 <= numberOfImages){
    fileName = "ppms/" + folderName + "/" + folderName + "_0" + to_string(numberOfImages) + ".ppm";
    cout << "\t" + fileName << endl;
  }   
  //This line opens up the file stream. 
  in.open(fileName.c_str());
 
  //This line reads in the values for the image header from the top of the file.
  in >> magic_number >> height >> width >> max_color;
  
  //This is a priming read of the file. Without doing this, the read skips over
  //the first 3 color values. 
  in >> tempR >> tempG >> tempB;
  
  //This loop reads in the data while in the file. 
  while(in){ 
    //This code puts values into the vector of structs.
    p.red = tempR;
    p.green = tempG;
    p.blue = tempB;
    pVec.push_back(p);
    in >> tempR;
    in >> tempG;
    in >> tempB;
  }

  //This line closes the file stream. 
  in.close();
  
  //This calls the total method so we can add up the numbers stored in each file
  //for averaging later on. 
  total(pVec);
}

void Stacker::total(vector<pixel> pVec){
  //when pixels has nothing in it, it must be initialized or
  //the program will return NULL.
  if(pixels.size() == 0){
    totalInit(pVec.size()); 
  }
  
  //The for loop below adds up and stores the vector pixel values into
  //the pixels vector to keep track of them. They are averaged later.  
  for(unsigned int i = 0; i < pixels.size(); i++){
    pixels[i].red += pVec[i].red;
    pixels[i].green += pVec[i].green;
    pixels[i].blue += pVec[i].blue;
  }
}

void Stacker::average(int numberOfImages){
  //This averages all of the entries in the pixels vector. The totals of
  //the numbers read in from the ppm file are divided by the number of ppm
  //files that were read.
  for(unsigned int i = 0; i <= pixels.size(); i++){
    pixels[i].red = pixels[i].red/numberOfImages;
    pixels[i].green = pixels[i].green/numberOfImages;
    pixels[i].blue = pixels[i].blue/numberOfImages;
  }
}

void Stacker::totalInit(int vecSize){
  pixel pTotal;
  //This loop initializes pixels by pushing pixel structs filled with zeros into it.
  //The point of this is to have an initialized entry for every index that the fileRead vector has. 
  for(int i = 0; i < vecSize; i++){
    pTotal.red = 0;
    pTotal.green = 0;
    pTotal.blue = 0;
    pixels.push_back(pTotal);
  }
}

void Stacker::fileWrite(string folderName){
  //This code will set the name of the file we are writing to.
  string fileName = folderName + ".ppm"; 
  ofstream out;

  //This opens our file stream.
  out.open(fileName.c_str()); 
  out << magic_number << '\n' << height << ' ' << width << '\n' << max_color << endl;

  //This code writes the pixels structs to the new ppm file.
  for(int i = 0; i < pixels.size(); i++){
    out << pixels[i].red << ' ' << pixels[i].green << ' ' << pixels[i].blue << ' ';
  }

  //This closes the file stream.
  out.close();
  cout << "Output written to: " << fileName << endl; 
}
