/**
 * @file stacker.h
 * @author Connor Walsh
 * @date 2022-09-14
 * @brief this is the stacker header file 
 * 
 * This file contains the definition of the stacker class.
 */

#ifndef STACKER_H
#define STACKER_H

#include <vector>
#include <string>


/**
 * Utility for averaging the values of all pixels in a series of the same image to produce a clear picture.
 *
 * @class Stacker{ stacker.h "Image-Stacker-Assignment/stacker.h"
 * @brief stacks images
 *
 */
class Stacker{
 private: 
  std::string magic_number;
  int width;
  int height;
  int max_color;
  struct pixel{
    int red;
    int green;
    int blue;
  };  
  std::vector<pixel> pixels;
  pixel p; 
  
 public:

/**
 * default constructor intializes private data members
 *
 * @pre 
 * @post magic_number = "", width = 0, height = 0, max_color = 0
 * 
 */
  Stacker();
  

/**
 * creates a vector to hold the data loaded from a .ppm file and calls the total() method 
 *
 * @param std::string folderName the name of the folder entered by the user in main()
 * @param int numberOfImages the number of images entered by the user
 * @pre folderName and numberOfImages must be properly initialized
 * @return void 
 * @post 
 * 
 */
  void fileLoader(std::string folderName, int numberOfImages);


/**
 * sums all pixel values in their respective index for each image indicated by the user
 *
 * @param std::vector<pixel> pVec 
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void total(std::vector<pixel> pVec); //this is where the vecTotal vector is filled 

  void average(int numberOfImages);
  void totalInit(int vecSize); //this initializes the pixels vector
  void fileWrite(std::string folderName); //this should output all the information we have collected into a ppm file
  
};


#endif //STACKER_H
