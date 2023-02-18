#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <bits/stdc++.h>
#include "arcs.h"
using namespace std;

int main()
{
    int input_count, output_count = 0;
    ifstream input_file("NAND3D0BWP.arcs");
    if (0==(input_file.is_open())){
            cout << "Cannot open file:" << "NAND3D0BWP.arcs" << endl;
            return -1;
    }
    
    vector<string> arcs = parser(input_file, input_count, output_count);
    cout << "Inputs:" << input_count << endl;
    cout << "Outputs:" << output_count << endl;
    // Create vector to hold switching arcs

    // Generate tests for each arc
    for (string arc : arcs)
    {
        generateTestForArc(arc, 0.1, 10e-15, "rise", "fall");
        generateTestForArc(arc, 0.1, 10e-15, "fall", "rise");
    }

    // Print completion message
    cout << "SPICE tests generated for " << arcs.size() << " switching arcs.\n";

    return 0;
}
