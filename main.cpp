//
//  main.cpp
//  photometryscript
//
//  Created by Michelle Gurevich on 8/11/16.
//  Copyright © 2016 Michelle Gurevich. All rights reserved.
//

#include <string>
#include <fstream>
#include <iostream>
#include <ostream>

using namespace std;

int main() {
    
    FILE *ifile = NULL;
    string name;
    float mode;
    float stddev;
    
    ifile = fopen("stats.list","r");
    if (ifile == NULL) {
        cout << stddev << "Can't open file stats.list\n";
        exit(1);
    }
    for(;;) {
        cin >> name;
        cin >> mode >> stddev;
        if (feof(ifile))
            break;
        
    int FWHM = 5;
    int sigmaDetect = 4;
    int maxValue = 65000;
    float minValue = mode - 3 * stddev;
        
    cout << "daofind " << name << " " << FWHM << " " << stddev << " "
    << sigmaDetect << " " << minValue << " " << maxValue << "\n";
        
    }
    fclose(ifile);
    
    // Open the script in write mode.
    ofstream outputFile;
    outputFile.open ("daofind.cl");
    
    // Close the script.
    outputFile.close();
    
    return 0;
}
