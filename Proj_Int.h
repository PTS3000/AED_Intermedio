#ifndef Proj_Int_INCLUDED
#define Proj_Int_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <getopt.h>


int main(int argc, char *argv[]);
int ** Read_input_file(FILE *fp, char *filename, int *test_mode);
void help(void);



#endif