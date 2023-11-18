#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"

void CheckError(char *filename);
char** CreateVertexArr(char *str, int size);
int GetIndex(char **strarr, char *str);
int GetSizeFromFile(char *str);
int **CreateAdjMatrix(char *str, char **vertex_arr, int size);
void algorithmFloid(int ***w, int size) ;
void PrintPath(int **start_weight, int **end_weight, int *way, int way_count, int size, char **vertex_arr);
void PrintAllPath(int **start_weight, int **end_weight, int size, char **vertex_arr);

#endif
