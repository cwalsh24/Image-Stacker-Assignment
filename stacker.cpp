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
  // my guess is that we are going to recursively call the fileRead method and also send the current vector we just read out to the total method
}

void Stacker:::total(){
  /**  pixel pTotal; //probably another variable to go into private
  pTotal.red = 0;
  pTotal.green = 0; 
  pTotal.blue = 0; 
  vecTotal.push_back(pTotal);
  **/ //this works with the aforementioned code, but we need to put it in the constructor or something (this might make us lose points). Also, do we need pTotal when we have p?   
  
  //The for loop below adds up and stores the vector pixel values into
  //another vector for averaging 
  for(unsigned int i = 0; i < vec2.size(); i++){
    vecTotal[i].red += vec2[i].red;
    vecTotal[i].green += vec2[i].green;
    vecTotal[i].blue += vec2[i].blue;
  }
}

void Stacker::average(int numberOfImages){ //this is currently set to overwrite the total vector, it works we might want to put in an average vector 
  for(unsigned int i = 0; i <= vec2.size(); i++){
    vecTotal[i].red = vecTotal[i].red/numberOfImages;
    vecTotal[i].green = vecTotal[i].green/numberOfImages;
    vecTotal[i].blue = vecTotal[i].blue/numberOfImages;
  }
}
