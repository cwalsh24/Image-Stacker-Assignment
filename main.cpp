/**
 * @file main.cpp
 * @author Code4Days (Isaac Copeland, Connor Walsh)
 * @date 2022-09-19
 * @brief driver code for the Stacker class
 * 
 * This program receives input for .ppm files to be opened and averaged to clean up an image.
 */

#include <iostream> //remove the ones that aren't used later
#include <fstream>
#include <vector>
#include <string>

#include "stacker.h"

using namespace std;

int main() {
  Stacker s;
  string folderName;
  int numberOfImages;

  //The program asks the user for the name of the image and the number of images. 
  cout << "Please enter the image you wish to stack: ";
  cin >> folderName;
  cout << "Please enter the number of images: ";
  cin >> numberOfImages;
  
  //reads in data from all our files and totals it into one vector
  // s.fileLoader(folderName, numberOfImages);
  while(numberOfImages > 0){
    s.fileLoader(folderName, numberOfImages);
    numberOfImages--;
  }
  //averages the values in the total vector
  // s.average(numberOfImages);

  // s.fileWrite(); 
  

}
