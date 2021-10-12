#ifndef Proj_Int_INCLUDED
#define Proj_Int_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]);
void Read_input_file(char *filename);
void help(void);
int mode_A1(int a, int b, int **labyrinth, int L, int C);
int mode_A2(int a, int b, int **labyrinth, int L, int C);
int mode_A3(int a, int b, int **labyrinth, int L, int C);
int mode_A4(int a, int b, int **labyrinth, int L, int C);
int mode_A5(int a, int b, int **labyrinth, int L, int C);
int mode_A6(int a, int b, int c, int d);
int choose_test(char *test_mode, int **labyrinth, int L, int C, int a, int b, int c, int d);
void print_table(int **labyrinth, int L, int C);
void free_labyrinth(int **labyrinth, int C);
void write_output(FILE *fp, int result);
void str_paste(char *name, char *filename, int num_chars);
int find_last_period(char *filename);
char *allocate_outputname(char *out_name, char *in_name);
int **allocate_table(int **labyrinth, int C, int L);
FILE *open_inputfile(FILE *fp_in, char *filename);
FILE *open_outputfile(FILE *fp_out, char *filename);
void error(FILE *fp_in, FILE *fp_out, char *filename_out, char *filename_in);
#endif