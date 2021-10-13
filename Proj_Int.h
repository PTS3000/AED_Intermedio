#ifndef Proj_Int_INCLUDED
#define Proj_Int_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]);
void Read_input_file(char *filename);
void help(void);
int mode_A1(int a, int b, short **labyrinth, int L, int C);
int mode_A2(int a, int b, short **labyrinth, int L, int C);
int mode_A3(int a, int b, short **labyrinth, int L, int C);
int mode_A4(int a, int b, short **labyrinth, int L, int C);
int mode_A5(int a, int b, short **labyrinth, int L, int C);
int mode_A6(int a, int b, int l, int c, short **labyrinth, int L, int C);
char *get_inputfilename(char **argv, char *filename);
int choose_test(char *test_mode, short **labyrinth, int L, int C, int a, int b, int c, int d);
void print_table(short **labyrinth, int L, int C);
void free_labyrinth(short **labyrinth, int C);
void write_output(FILE *fp, int result);
void str_paste(char *name, char *filename, int num_chars);
int find_last_period(char *filename);
char *allocate_outputname(char *out_name, char *in_name);
short **allocate_table(short **labyrinth, int C, int L);
FILE *open_inputfile(FILE *fp_in, char *filename);
FILE *open_outputfile(FILE *fp_out, char *filename);
void error(FILE *fp_in, FILE *fp_out, char *filename_out, char *filename_in);
int get_index(int a, int b, int C);
int **make_pairs(short **labyrinth, int n_max_pairs, int L, int C);
int compressed_weighted_quick_union_halfing(int *id, int N, int n_max_pairs, int **pairs_data, int start, int finish);
void free_pairs(int **pairs, int n_pairs, int L, int C);

#endif