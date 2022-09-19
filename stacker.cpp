/**
 * @file stacker.cpp
 * @author Connor Walsh
 * @date 2022-09-14
 * @brief This is the stacker source code
 * 
 * stuff
 */

#include "stacker.h"  

using namespace std;

Stacker::Stacker(){
  magic_number; 
  width = 0;
  height = 0;//height before width
  max_color = 255; 
  pixel p;   
}

void Stacker::fileLoader(string folderName, int numberOfImages, pixel p){  
  //int temporary = 0; may not be needed
  ifstream in;
  string fileName;
  
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
  //or we could do like numberOfImages-(numberOfimages - 1) and count up. The example went from 1 to 10  
  
  in.open(fileName.c_str());
 
  //this line reads in the values for these variables from the file. 
  in >> magic_number >> height >> width >> max_color;  //**note the magic_number might want to be a priming read

  while(in){ //priming read? 
    //this puts values into the vector of structs.  
    in >> p2.red;
    in >> p2.green;
    in >> p2.blue;
    vec2.push_back(p2);

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
