/**
 * this program calculates the timeout interval
 * using 2 inputs given as parameters upon running
 * @author Sua "Joshua" Lee
 * @version 19 Apr 2020
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
  // convert inputs to double data type
  double estimated = atof(argv[1]);
  double dev = atof(argv[2]);

  // other variable declaration
  double interval;

  // calculate timout interval and printout the result
  interval = estimated + 4 * dev;

  printf("%.5f\n", interval);
}
