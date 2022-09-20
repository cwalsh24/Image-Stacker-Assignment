/**
 * @file stacker.h
 * @author Connor Walsh
 * @date 2022-09-14
 * @brief This is the stacker header file 
 * 
 * It has the stacker class 
 */
#ifndef STACKER_H
#define STACKER_H

#include <iostream> //remove the ones that aren't used later, if they need to be here remove from other files since it will import them in
#include <fstream>
#include <vector>
#include <string>

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
  pixel p; //not sure if we want this here 
  //This is to keep track of the totals of all the pixels in the ppm files
  std::vector<pixel> vecTotal;
  
 public:
  Stacker(); //default constructor
  void fileLoader(std::string folderName, int numberOfImages);
  // double average this is going to divide everything in the vecTotal vector by the number the user enters
  void total(); //this is where the vecTotal vector is filled 
  
  
};


#endif //STACKER_H
