#ifndef Proj_Int_INCLUDED
#define Proj_Int_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]);
void Read_input_file(FILE *fp_in, char *filename);
void help(void);
int mode_A1(int a, int b, int **labyrinth, int L, int C);
int mode_A2(int a, int b, int **labyrinth, int L, int C);
int mode_A3(int a, int b, int **labyrinth, int L, int C);
int mode_A4(int a, int b, int **labyrinth, int L, int C);
int mode_A5(int a, int b, int **labyrinth, int L, int C);
int mode_A6(int a, int b);
int choose_test(char *test_mode, int **labyrinth, int L, int C, int a, int b);
void print_table(int **labyrinth, int L, int C);
void free_labyrinth(int **labyrinth, int C);
void write_output_file(char *name,int result);
void str_paste(char *name, char *filename, int num_chars);
int find_last_period(char *filename);
int **allocate_table(int **labyrinth,int C, int L);
char *allocate_outputname(char *out_name, char *in_name);
void error(FILE *fp);
#endif