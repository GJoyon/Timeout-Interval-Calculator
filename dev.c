/**
 * this program calculates the devRTT
 * using three inputs given as parameters upon running
 * @author Sua "Joshua" Lee
 * @version 19 Apr 2020
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
  // convert three inputs to double data types
  double sample = atof(argv[1]);
  double estimated = atof(argv[2]);
  double dev = atof(argv[3]);

  // other variable declarations
  double beta = 0.25;
  double diff;

  // calculate difference
  if (sample > estimated)
  {
    diff = sample - estimated;
  }
  else
  {
    diff = estimated - sample;
  }

  // calculate devRTT and printout the result
  dev = (1 - beta) * dev + beta * diff;
  printf("%.5f", dev);
}
