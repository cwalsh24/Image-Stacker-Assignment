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

  //The code asks the user for the name of the image and the number of images. 
  cout << "Please enter the image you wish to stack: ";
  cin >> folderName;
  cout << "Please enter the number of images: ";
  cin >> numberOfImages;
  
  //This count variable will be used for looping the fileLoader method.
  int count = numberOfImages; 
  cout << "Stacking Images: " << endl;
  
  //This loop is to call the fileLoader method on the user specified ppms. 
  while(count > 0){ //NOTE: There is currently no catch for if an image doesnt exist, the program crashes
    s.fileLoader(folderName, count);
    count--;
  }
  cout << endl << "Stacking succeeded." << endl; 
  
  //This calls the average method and averages the values in the pixel vector. 
  cout << "The Average of the first 4 reds is" << endl; //remove this later DEBUG STUFF
  s.average(numberOfImages);

  //This calls the file writer method to create the new image. 
  s.fileWrite(folderName); 
  

}
