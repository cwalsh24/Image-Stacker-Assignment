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
  pixel p; 
  
 public:
  Stacker(); //default constructor
  void fileLoader(std::string folderName, int numberOfImages);
  void total(std::vector<pixel> pVec); //this is where the vecTotal vector is filled 
  void average(int numberOfImages);
  void totalInit(int vecSize); //this initializes the pixels vector
  void fileWrite(); //this should output all the information we have collected into a ppm file
  
};


#endif //STACKER_H
