/**
 * @file main.cpp
 * @author Code4Days (Isaac Copeland, Connor Walsh)
 * @date 2022-09-19
 * @brief driver code for the Stacker class
 * 
 * This program receives input for .ppm files to be opened and averaged to clean up an image.
 */


#include "Vector.h"

using namespace std;

int main() {
  Stack s; 
  string folderName;
  int numberOfImages;
  cout << "Please enter the image you wish to stack: ";
  cin >> folderName;
  cout << "Please enter the number of images: ";
  cout >> numberOfImages;
  s.fileLoader(folderName, numberOfImages);  

}
