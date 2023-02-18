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
    vector<double> slew_rates = {0.1, 0.2, 0.3};
    vector<double> out_loads = {15e-15, 15e-15, 15e-15};
    ifstream input_file("NAND3D0BWP.arcs");
    if (0==(input_file.is_open())){
            cout << "Cannot open file:" << "NAND3D0BWP.arcs" << endl;
            return -1;
    }
    
    vector<string> arcs = parser(input_file, input_count, output_count);
    cout << "Inputs:" << input_count << endl;
    cout << "Outputs:" << output_count << endl;
    
    // Generate runset for each arc x capacitance x load
    for (double capacitance : out_loads){
        for (double slew : slew_rates){
            for (string arc : arcs)
            {
                generateTestForArc(arc, slew, capacitance, "rise", "fall");
            }
        }
    }

    // Print completion message
    cout << "SPICE tests generated for " << arcs.size() << " switching arcs.\n";

    return 0;
}
