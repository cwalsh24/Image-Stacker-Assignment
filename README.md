# Collaboration Assignment 1: Image Stacker
Group: Code4Days (Isaac Copeland, Connor Walsh)
Date: 9/24/2022

This program is designed to average color values from more than one ppm file to reduce image noise. 

## How to Run
* Type "make" to compile the program
* Type ./stacker to run the executable created by the compilation process
* Type "make clean" to remove unwanted files created by the compilation process
* Note: The various ppm directories must be contained inside a directory called ppms
* When the executable is run, the user will be prompted to input the name of the ppm image followed by the number of images they want to stack.

## Design Decisions
* We decided to use two vectors to deal with the RGB values inside of the ppm class. Firstly, when we made the fileLoader method, we used a vector that was declared inside of said method to store the RGB values. After the while loop had read in all the values from a file, we had the fileLoader method call the total method which stored these values into the pixels vector by using the size of the vector inside the fileLoader method and addition. Whenever the total method is called by the fileLoader method, the values from the vector inside the fileLoader method are added to the same index in the pixels vector which makes it easy to keep track of all of these RGB values for averaging. Since the vector inside the fileLoader method was declared there, we also didn't have to worry about resizing or clearing its contents.
* We created an initializer method to initialize the pixels vector the first time the total method is called because we thought it looked cleaner to make an initializer method to do this for us rather than calling the push_back method on the pixels vector inside of the default constructor.
* We created an average method that simply divides the red green and blue values from every index of the pixels vector to average our values. We decided to preform this action on the pixels vector because we did not think having a third vector to store averages would be practical.
* The fileWriter method creates the new ppm file by first writing in the file header, which was stored in our member variables, followed by all of the structs in the pixels vector using a for loop. We decided to use this approach because it was the easiest way we could come up with to creates the new ppm file. 

## Challenges
* One challenge that we ran into was having to deal with the fileLoader vector. Originally we had it declared in the header file as a private variable, but this caused us problems because when we called the fileLoader method, the vector would just take in the RGB values from the next file on the end rather than starting over from the beginning. In order to fix this we just declared this vector inside of the fileLoader instead, which causes it to get deleted after the method is finished running.
* At the end we ran into problems with trying to output the data into a new ppm file, but it turned out that we had swapped the height and width values in the image header, which caused the files to have incorrect dimensions. After fixing this logic error, our code worked.
* We also had problems with trying to store the totals of the RGB values into the pixels vector. Whenever we tried to do this it would cause a segmentation fault, but it turned out that the pixels vector had simply not been initialized properly. After implementing the initializer method, our pixel vector worked for totaling the RGB values and later averaging them. 

## How We Shared Work
* We shared the work by simply getting together in the G1 lab to talk about and work on the program.
* Connor wrote most of the code for the assignment, did about half of the comments, and brainstormed.
* Isaac made the Makefile, did the other half of the comments, helped brainstorm, and tested out coding ideas that we could potentially implement.
* We both just had to work on it when possible to get it done on time.

