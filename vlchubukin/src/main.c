#include "../inc/pathfinder.h"

int main(int argc, char *argv[]) {

    if(argc != 2){
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(-1);
    }

    CheckError(argv[1]);

    char *strFile = mx_file_to_str(argv[1]);

    int sz = GetSizeFromFile(strFile);
    char **islands = CreateVertexArr(strFile, sz);

    int **startWeight = CreateAdjMatrix(strFile, islands ,sz);
    int **endWeight = CreateAdjMatrix(strFile, islands ,sz);
   

    algorithmFloid(&endWeight, sz);
    
    PrintAllPath(startWeight, endWeight, sz, islands);

    mx_strdel(&strFile);
    mx_del_strarr(&islands);
    for(int i = 0; i < sz; i++){
        free(startWeight[i]);
        free(endWeight[i]);
    }
    free(startWeight);
    free(endWeight);
    
    return 0;
}
