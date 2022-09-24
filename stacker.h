/**
 * @file stacker.h
 * @author Code4Days (Connor Walsh, Isaac Copeland)
 * @date 2022-09-23
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
 * @pre a Stacker object must be created by the user
 * @post magic_number = "", width = 0, height = 0, max_color = 0
 * 
 */
  Stacker();
  

/**
 * This method creates a vector to hold the data loaded from a .ppm file and calls the 
 * total() method after the data has been stored into the vector to store the data totals 
 * for averaging. It also reads the data for the member variables.   
 *
 * @param std::string folderName the name of the folder entered by the user in main()
 * @param int numberOfImages the number of images entered by the user in main() 
 * @pre folderName and numberOfImages must be declared and user input must be given. 
 * @return void this method does not return anything
 * @post the totals of all red, green, and blue values have been stored in the pixels vector
 * and the private member variables now contain the data from the file header. 
 * 
 */
  void fileLoader(std::string folderName, int numberOfImages);


/**
 * sums all pixel values in their respective index for each image indicated by the user
 *
 * @param std::vector<pixel> pVec 
 * @pre the method must be sent a vector of type pixel to be used 
 * @return void this method returns nothing
 * @post the pixels vector now contains the total of the values in each pixel vector sent
 * 
 */
  void total(std::vector<pixel> pVec);  


/**
 * the average method calculates the average of the totaled pixel values in the pixels vector
 *
 * @param int numberOfImages the number of images that are requested to be stacked by the user
 * @pre the pixels vector must contain pixel structs and the user must give the number of images
 * @return void this function returns nothing
 * @post the totaled pixel struct values in the pixels vector have been averaged
 * 
 */
  void average(int numberOfImages);
  

/**
 * this method initializes the pixels vector to contain structs with all variables set to zero. 
 *
 * @param int vecSize the size of the vector being totaled for averaging
 * @pre a size total for a vector must be sent
 * @return void this function returns nothing
 * @post the pixels vector has been initialized
 * 
 */
  void totalInit(int vecSize);
  

/**
 * this function writes the information in the member variables and the averaged pixel
 * struct values contained in the pixels vector to a new ppm file. 
 *
 * @param std::string folderName the user inputted name of the folder containing the 
 * original ppm images. 
 * @pre the folderName must be given by the user, the pixels vector and member variables
 * must contain values 
 * @return void this method returns nothing
 * @post the new ppm file with the name of the user specified folder has been written.  
 * 
 */
  void fileWrite(std::string folderName);
  
};


#endif //STACKER_H
