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
    vector<double> out_loads = {10e-15, 15e-15, 20e-15};
    string filename = "NAND3D0BWP.arcs";
    ifstream input_file(filename);
    if (0==(input_file.is_open())){
            cout << "Cannot open file:" << filename << endl;
            return -1;
    }
    
    vector<string> arcs = parser(input_file, input_count, output_count);
    cout << "Inputs:" << input_count << endl;
    cout << "Outputs:" << output_count << endl;
    
    // Generate runset for each arc x capacitance x load
    for (double slew : slew_rates){
        for (double capacitance : out_loads){
            for (string arc : arcs)
            {
                string input_transition_type = "fall";
                string output_transition_type = "fall";
                for(int i = 0; i < input_count; i++){
                    if(arc[i] == 'R'){
                        input_transition_type = "rise";
                        break;
                    }
                }
                for(int i = input_count-1; i < (input_count + output_count)-1; i++){
                    if(arc[i] == 'R'){
                        output_transition_type = "rise";
                        break;
                    }
                }
                generateTestForArc(arc, slew, capacitance, input_transition_type, output_transition_type);
                
            }
        }
    }

    // Print completion message
    cout << "SPICE tests generated for " << arcs.size() << " switching arcs.\n";

    return 0;
}
