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
  cout << "Please enter the image you wish to stack: ";
  cin >> folderName;
  cout << "Please enter the number of images: ";
  cin >> numberOfImages;
  s.fileLoader(folderName, numberOfImages);

}
