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

#include <iostream> //remove the ones that aren't used later
#include <fstream>
#include <vector>
#include <string>

class Stacker{
 private: 
  std::string magic_number;
  int width;
  int height;
  int max_color;
  std::vector<pixel> pixels;
  //std::vector<pixel> vecTotal; This is probably how we are going to have to keep track of all the vectors 
  
  struct pixel{
    int red;
    int green;
    int blue;
  };
  
 public:
  Stacker(); //default constructor
  void fileLoader();
  // double average this is going to divide everything in the vecTotal vector by the number the user enters
  void total(); //this is where the vecTotal vector is filled 
  
  
};


#endif //STACKER_H
