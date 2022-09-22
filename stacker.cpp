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
  magic_number = "";   
  height = 0;
  width = 0; 
  max_color = 0; 
}

void Stacker::fileLoader(string folderName, int numberOfImages){
  ifstream in;
  string fileName;
  int tempR, tempG, tempB;
  vector<pixel> pVec;
  
  //These two if statements set the correct file locations equal to the fileName string
  //and print said file names for the user to see. 
  if(numberOfImages < 10){ 
    fileName = "ppms/" + folderName + "/" + folderName + "_00" + to_string(numberOfImages) + ".ppm";
    cout << fileName << endl;
  }
  
  if(10 <= numberOfImages){
    fileName = "ppms/" + folderName + "/" + folderName + "_0" + to_string(numberOfImages) + ".ppm";
    cout << fileName << endl;
  }   

  in.open(fileName.c_str());
 
  //this line reads in the values for these variables from the file. 
  in >> magic_number >> height >> width >> max_color;
  //This is a priming read of the file
  in >> tempR >> tempG >> tempB;
  
  while(in){ 
    //this puts values into the vector of structs.
    p.red = tempR;
    p.green = tempG;
    p.blue = tempB;
    pVec.push_back(p);
    in >> tempR;
    in >> tempG;
    in >> tempB;
  }
  in.close();
  //This is supposed to allow the reader to read in the next file
  total(pVec);
  cout << "pixels size: " << pVec.size() << endl;

  cout << pVec[0].red << endl;
  cout << pVec[1].red << endl;
  cout << pVec[2].red << endl;
  cout << pVec[3].red << endl;
  
  pVec.clear();
  //numberOfImages--; //this all causes an infinite loop
  //calls the method again to read in the next file
  //while(numberOfImages > 0){
  //  fileLoader(folderName, numberOfImages);
  //}
}

void Stacker::total(vector<pixel> pVec){
  //if the vecTotal has nothing in it, it must be initialized or
  //the program will return NULL. 
  if(pixels.size() == 0){
    totalInit(pVec.size()); 
  }
  
  //The for loop below adds up and stores the vector pixel values into
  //another vector for averaging 
  for(unsigned int i = 0; i < pixels.size(); i++){
    pixels[i].red += pVec[i].red;
    pixels[i].green += pVec[i].green;
    pixels[i].blue += pVec[i].blue;
  }
}

void Stacker::average(int numberOfImages){
  //This averages all of the entries in the total vector. 
  for(unsigned int i = 0; i <= pixels.size(); i++){
    pixels[i].red = pixels[i].red/numberOfImages;
    pixels[i].green = pixels[i].green/numberOfImages;
    pixels[i].blue = pixels[i].blue/numberOfImages;
  }
  //DEBUG JUNK
  cout<<pixels[0].red << endl;
  cout<<pixels[1].red << endl;
  cout<<pixels[2].red << endl;
  cout<<pixels[3].red << endl;
}

void Stacker::totalInit(int vecSize){ //this initilizes the pixels vector, we need the size from the fileRead vector so it has the correct number of entries
  pixel pTotal;
  for(int i = 0; i < vecSize; i++){
    pTotal.red = 0;
    pTotal.green = 0;
    pTotal.blue = 0;
    pixels.push_back(pTotal);
  }
}

void Stacker::fileWrite(){
  ofstream out;
  out.open("test.ppm");
  out << magic_number << '\n' << width << ' ' << height << '\n' << max_color << endl;
  //for(int i = 0; i < width; i++){ we need to get it to print until the width ends and then start a new line
  out.close();
}
