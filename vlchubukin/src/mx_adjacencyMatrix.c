#include "../inc/pathfinder.h"

int **CreateAdjMatrix(char *str, char **vertex_arr, int size) {
    int **adjWeightMtx = (int **) malloc((size + 1) * sizeof(int *));
    for(int i = 0; i < size; i++) {
        adjWeightMtx[i] = (int*)malloc(size * sizeof(int));
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            adjWeightMtx[i][j] = 999999;
        }
    }

    int **matrixTest = (int **) malloc((size + 1) * sizeof(int *));
    for(int i = 0; i < size; i++) {
        matrixTest[i] = (int*)malloc(size * sizeof(int));
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            matrixTest[i][j] = 0;
        }
    }

    char **strArr = mx_strsplit(str, '\n');

    for (int i = 1; strArr[i]; i++) {
        char *from = mx_strndup(strArr[i], mx_get_char_index(strArr[i], '-'));
        strArr[i] += mx_get_char_index(strArr[i], '-') + 1;
        
        char *to = mx_strndup(strArr[i], mx_get_char_index(strArr[i], ','));
        strArr[i] += mx_get_char_index(strArr[i], ',') + 1;
        
        char *path = mx_strndup(strArr[i], mx_get_char_index(strArr[i], '\n'));

        if (matrixTest[GetIndex(vertex_arr, from)][GetIndex(vertex_arr, to)] == 1 && matrixTest[GetIndex(vertex_arr, to)][GetIndex(vertex_arr, from)] == 1) {
            mx_printerr("error: duplicate bridges\n");
            exit(-1);
        }

        if (mx_atoi(path) == -1) {
            mx_printerr("error: sum of bridges lengths is too big\n");
            exit(-1);
        }

        adjWeightMtx[GetIndex(vertex_arr, from)][GetIndex(vertex_arr, to)] = mx_atoi(path);
        adjWeightMtx[GetIndex(vertex_arr, to)][GetIndex(vertex_arr, from)] = mx_atoi(path);

        matrixTest[GetIndex(vertex_arr, from)][GetIndex(vertex_arr, to)] = 1;
        matrixTest[GetIndex(vertex_arr, to)][GetIndex(vertex_arr, from)] = 1;

        
        mx_strdel(&from);
        mx_strdel(&to);
        mx_strdel(&path);
    }


    for(int i = 0; i < size; i++){
        free(matrixTest[i]);
    }
    free(matrixTest);
    return adjWeightMtx;
}
