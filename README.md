# DPAC
Open-Source Standard Cell Characterization Tool Developed by Rodrigo N. Wuerdig.

The input of this code comes from another branch:

https://github.com/rodrigowue/s2cae

The other tool outputs a <*>.arcs file from a standard-cell SPICE netlist input.

## Development Steps:
1. Create Runsets [Under Development]
2. Run Spice Runsets [not started]
3. Analyse Results [not started]
4. Generate Liberty File [not started]


## Step 1 - Creating SPICE Runsets

Creates a file tree structure
```
/outputs/[slew_rate]/[out cap]/[arc].sp
```
E.g.,
For Slew {0.1,0.2,0.3}

```
/outputs/0.1/[out cap]/[arc].sp
/outputs/0.2/[out cap]/[arc].sp
/outputs/0.3/[out cap]/[arc].sp
```
For out Cap {10e-15,15e-15,20e-15}
```
/outputs/0.1/10fF/[arc].sp
/outputs/0.1/15fF/[arc].sp
/outputs/0.1/20fF/[arc].sp
/outputs/0.2/10fF/[arc].sp
/outputs/0.2/15fF/[arc].sp
/outputs/0.2/20fF/[arc].sp
/outputs/0.3/10fF/[arc].sp
/outputs/0.3/15fF/[arc].sp
/outputs/0.3/20fF/[arc].sp
```
Do the same for the arcs...

## Step 2 - Running SPICE Simulations
[TBD]
## Step 3 - Analyzing Simulation Results
[TBD]
## Step 4 - Generating Liberty File
[TBD]
