/**
 * @file stacker.cpp
 * @author Connor Walsh
 * @date 2022-09-14
 * @brief This is the stacker source code
 * 
 * stuff
 */

#include <iostream> //remove the ones that aren't used later
#include <fstream>
#include <vector>
#include <string>
#include "stacker.h"  

using namespace std;

Stacker::Stacker(){
  magic_number = ""; //since this is declared in the header it may not need to be here  
  height = 0;
  width = 0; 
  max_color = 255;    
}

void Stacker::fileLoader(string folderName, int numberOfImages){
  ifstream in;
  string fileName;
  //This loop is going to read through all the files
  while(numberOfImages > 0){
  
    //Something like these will get the correct file name depending on the number of files the user wants to get.
    //We might want to put in an else statement to end the method if the number is less than one or more than 99 
    if(numberOfImages < 10){ 
      fileName = folderName + "/" + folderName + "_00" + to_string(numberOfImages) + ".ppm";
      cout << fileName << endl; 
    }
  
    if(10 <= numberOfImages){
      fileName = folderName + "/" + folderName + "_0" + to_string(numberOfImages) + ".ppm";
      cout << fileName << endl; 
    } //when these run we might want to do a numberOfimages-- and then call the method again at the end
    //or we could do like numberOfImages-(numberOfimages - 1) and count up. The example went from 1 to 10  
    
    in.open(fileName.c_str());
 
    //this line reads in the values for these variables from the file. 
    in >> magic_number >> height >> width >> max_color;  //**note the magic_number might want to be a priming read

    while(in){ //priming read? 
      //this puts values into the vector of structs.  
      in >> p.red;
      in >> p.green;
      in >> p.blue;
      pixels.push_back(p);
      
    }
    total(); 
    numberOfImages--;
  }
  //closes the file stream
  in.close(); 
}

void Stacker::total(){
  //if the vecTotal has nothing in it, it must be initialized or
  //the program will return NULL. 
  if(vecTotal.size() == 0){
    totalInit(); 
  }
  
  //The for loop below adds up and stores the vector pixel values into
  //another vector for averaging 
  for(unsigned int i = 0; i < pixels.size(); i++){
    vecTotal[i].red += pixels[i].red;
    vecTotal[i].green += pixels[i].green;
    vecTotal[i].blue += pixels[i].blue;
  }
}

void Stacker::average(int numberOfImages){
  //This averages all of the entries in the total vector. 
  for(unsigned int i = 0; i <= pixels.size(); i++){
    vecTotal[i].red = vecTotal[i].red/numberOfImages;
    vecTotal[i].green = vecTotal[i].green/numberOfImages;
    vecTotal[i].blue = vecTotal[i].blue/numberOfImages;
  }
}

void Stacker::totalInit(){
  pixel pTotal;
  pTotal.red = 0;
  pTotal.green = 0;
  pTotal.blue = 0;
  vecTotal.push_back(pTotal);
}
