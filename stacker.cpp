/**
 * @file stacker.cpp
 * @author Connor Walsh
 * @date 2022-09-14
 * @brief This is the stacker source code
 * 
 * stuff
 */

#include "stacker.h" 
#include <iostream> //if these are in the .h we don't need them 
#include <fstream>
#include <vector>
#include <string> 

using namespace std;

Stacker::Stacker(){
  magic_number; 
  width = 0;
  height = 0;//height before width
  max_color = 255; 
  //pixels.red = 0;
  //pixels.green = 0;
  //pixels.blue = 0;
  //pixel; do any of these need to be initialized here?  
}

void Stacker::fileLoader(){ //parameters (vector<pixel> & vec, string folderName, int numberOfImages) 
  int temporary = 0;
  ifstream in;
  string fileName; 
  string folderName;//this and the numberOfImages variable might need to go in the main
  //something like this will be used for reading in all the files
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
    cout << fileName; 
  }
  
  if(10 <= numberOfImages){
    fileName = folderName + "/" + folderName + "_00" + numberOfImages + ".ppm";
    cout << fileName; 
  } //when these run we might want to do a numberOfimages-- and then call the method again at the end
  
  in.open(fileName.c_str());

  int count = 0; //I thought of using this to prevent the loop from trying to read in height/P3/width again
  //in >> temporary; //this is a priming read
  while(in){
    getline(in, magic_number); //something like this should get the P3 value;
    
    //in >> height;  //in.ignore() might be worth looking into for dealing with the spaces
    //in >> width;

    while(in){
      //this should put values into the vector of structs; 
      in >> vec.r[count];
      in >> vec.g[count];
      in >> vec.b[count];
      count++; 

    }
    
  }
}

void Stacker::Average(vector<pixel> &vec){ //we are probably going to end up with a vector for each file read 
  double rAverage = 0;
  double gAverage = 0;
  double bAverage = 0;
  for(int i = 0; i < vec.size(); i++){
    rAverage = vec[i].r + rAverage; //this won't work for what we are trying to do 
    gAverage = vec[i].g + gAverage;
    bAverage = vec[i].b + bAverage;
  }
}
