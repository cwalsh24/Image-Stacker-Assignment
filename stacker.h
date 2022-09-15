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
  string magic_number = "P3";
  int width;
  int height;
  int max_color;
  vector pixels;
  
  struct pixel{
    int red;
    int green;
    int blue;
  }
 public:
  //This will be added to
  
  
};


#endif //STACKER_H
