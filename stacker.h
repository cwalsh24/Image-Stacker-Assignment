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
  vector<pixel> pixels;
  
  struct pixel{
    int red;
    int green;
    int blue;
  };
  
 public:
  Stacker(); //default constructor
  void fileLoader();
  // double average
  
  
};


#endif //STACKER_H
