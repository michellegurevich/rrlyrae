//
//  main.cpp
//  CCD Mask
//
//  Created by Michelle Gurevich on 7/28/16.
//  Output locations of pixels in CCD image corners to text document
//  to create a mask for telescope images.
//

#include <iostream>
#include <fstream>
#include <math.h>


int main() {
    
    // Open the file in write mode.
    std::ofstream outputFile;
    outputFile.open ("CCDmask.txt");

    // Set dimensions and important point locations.
    int xDimension = 1481;
    int yDimension = 1469;
    
    double xCenter = 745;
    double yCenter = 735;
    
    double xCircum = 50;
    double yCircum = 1000;
    
    // Calculate trradius of image.
    double radius = sqrt( pow(xCircum-xCenter,2) + pow(yCircum-yCenter,2) );
    
    // Iterate through pixels.
    for (int x = 1; x <= xDimension; x++) {
        for (int y = 1; y <= yDimension; y++) {
            // Calculate distance between each new point and center.
            double distance = sqrt( pow(x-xCenter,2) + pow(y-yCenter,2) );
            // Print bad pixels to file.
            if (distance > radius || x > 1448) {
                outputFile << x << " " << y << '\n';
            }
        }
    }
    
    // Close the file.
    outputFile.close();
  
    return 0;
}