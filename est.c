/**
 * a program that calculates estimated RTT
 * it takes two input parameters upon running:
 * old_estimateRTT and new_sampleRTT
 * @author Sua "Joshua" Lee
 * @version 19 Apr 2020
 */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[])
{
  // convert the inputs to double data type
  double old_est = atof(argv[1]);
  double new_sample = atof(argv[2]);
  
  // then calculate the estimatedRTT and printout the result
  double est = (1 - 0.125) * old_est + 0.125 * new_sample;

  printf("%.5f\n", est);
}
