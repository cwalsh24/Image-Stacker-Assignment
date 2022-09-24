/**
 * @file main.cpp
 * @author Code4Days (Isaac Copeland, Connor Walsh)
 * @date 2022-09-19
 * @brief driver code for the Stacker class
 * 
 * This program receives input for .ppm files to be opened and averaged to clean up an image.
 */

#include <iostream>

#include "stacker.h"

using namespace std;

int main() {
  Stacker s;
  string folderName;
  int numberOfImages;

  //This code asks the user for the name of the image and the number of images. 
  cout << "Please enter the image you wish to stack: ";
  cin >> folderName;
  cout << "Please enter the number of images: ";
  cin >> numberOfImages;
  
  //This count variable will be used for looping the fileLoader method.
  int count = numberOfImages; 
  cout << "Stacking Images: " << endl;
  
  //This loop is to call the fileLoader method on the user specified ppms. 
  while(count > 0){
    s.fileLoader(folderName, count);
    count--;
  }
  cout << "Stacking succeeded." << endl; 
  
  //This calls the average method and averages the values in the pixel vector. 
  s.average(numberOfImages);

  //This calls the file writer method to create the new image. 
  s.fileWrite(folderName); 
  

}
