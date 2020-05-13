/**
 * this program reads a string input, converts it into double data type,
 * waits for 5 seconds, then returns the double data to the caller
 * @author Sua "Joshua" Lee
 * @version 19-Apr-2020
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// function declaration
void delay(int seconds);

int main(int argc, char * argv[])
{
  // convert to double and print
  double result = atof(argv[1]);
  printf("%.5f\n", result);

  // wait for 5 seconds
  delay(5);

  return 0;
}

// wait for a given amount of time
void delay(int seconds)
{
  clock_t start = clock() / CLOCKS_PER_SEC;

  while ((clock() / CLOCKS_PER_SEC) < (start + seconds));
}
