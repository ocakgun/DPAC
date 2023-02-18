#ifndef ARCS_H
#define ARCS_H
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void print_logo();

void generateTestForArc(string arcName, double slew, double capacitance, string inputTransition, string outputTransition);

vector<string> parser(ifstream& infile, int& input_count, int& output_count);

#endif