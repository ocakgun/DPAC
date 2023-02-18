#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void generateTestForArc(string arcName, double slew, double capacitance, string inputTransition, string outputTransition)
{
    // Open output file for writing
    string fileName = "outputs/" + arcName + "_" + inputTransition + "_" + outputTransition + ".sp";
    ofstream outFile(fileName);

    // Write out header
    outFile << "** Test for arc " << arcName << " with " << inputTransition << " input and " << outputTransition << " output\n";
    outFile << ".include standard_cells.sp\n";
    outFile << ".temp 25\n";
    outFile << ".param slew=" << slew << "\n";
    outFile << ".param capacitance=" << capacitance << "\n\n";

    // Write out test stimulus
    outFile << "* Stimulus for arc " << arcName << "\n";
    outFile << "Vdd vdd 0 1.2V\n";

    if (inputTransition == "rise") {
        outFile << "Vtest in 0 PULSE(0V 1.2V 0ns 0.1ns 0.1ns 1us 2us)\n\n";
    } else {
        outFile << "Vtest in 0 PULSE(1.2V 0V 0ns 0.1ns 0.1ns 1us 2us)\n\n";
    }

    // Write out instance of standard cell
    outFile << "* Instance of standard cell for arc " << arcName << "\n";
    outFile << "Xcell " << arcName << "_" << inputTransition << "_" << outputTransition << "_inst in out vdd vdd ";

    if (outputTransition == "rise") {
        outFile << "NAND3_RISE\n\n";
    } else {
        outFile << "NAND3_FALL\n\n";
    }

    // Add average current measurement
    outFile << "* Average current measurement for arc " << arcName << "\n";
    outFile << "Iavg out 0 1uA\n";
    outFile << "Vavg avg 0 DC 0V\n";
    outFile << ".meas avgCurrent AVG(I(Iavg))\n";
    outFile << ".meas avgVoltage AVG(V(avg))\n\n";

    // Write out end statement
    outFile << ".end\n";

    // Close output file
    outFile.close();
}

int main()
{
    // Create vector to hold switching arcs
    vector<string> arcs = {"r0f", "f1r", "0rf"};

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
