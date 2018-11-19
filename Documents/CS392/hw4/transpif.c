//Philip Cho, “I pledge my honor I have abided by the Stevens Honor System.”

#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

void printMatrix(float * matrix, int width, int height){
    int count2 = 0;
    int i;
    for(i = 0; i < width * height; i++){
        printf("%.2f ", matrix[i]);
        count2++;
        if(count2 == width){
            printf("\n");
            count2 = 0;
        }
    }
}

void transposeMatrix(float * inputMatrix, float * outputMatrix, int width, int height, int blockWidth){
    int row;
    int column;
    int currNum = 0;

    for (int i = 0; i < height; i += blockWidth) {
        for (int j = 0; j < width; j += blockWidth) {
            for (row = i; row < i + blockWidth; row++) {
                if(row < height){
                        for (column = j; column < j + blockWidth; column++) {
                            if(column < width){
                                outputMatrix[column * height + row] = inputMatrix[row * width + column];
                        }
                        else{
                            printf("Memory Access Error");
                        }
                    }
                }
                else{
                    printf("Memory Access Error");
                }
            }
        }
    }
}
int main(int argc, char **argv){

    if (argc != 4) {
        fprintf(stderr, "Wrong number of command-line arguments\n");
        return 1;
    }
    float * inputMatrix;
    float * outputMatrix;
    int width = atoi(argv[2]);
    int height = atoi(argv[1]);
    int blockWidth = atoi(argv[3]);
    inputMatrix = (float *) malloc(width * height *sizeof(float));
    outputMatrix = (float *) malloc(width * height *sizeof(float));
    int randomNumberLoop;
    for(randomNumberLoop = 0; randomNumberLoop < width * height; randomNumberLoop++){
        inputMatrix[randomNumberLoop] = rand();
    }
    // printMatrix(inputMatrix, width, height);
    struct timeval startTime;
    gettimeofday(&startTime, 0);
    transposeMatrix(inputMatrix, outputMatrix, width, height, blockWidth);
    struct timeval endTime;
    gettimeofday(&endTime, 0);

    // printf("\nOutput:\n");
    int count = 0;
    // printMatrix(outputMatrix, height, width);

    free(inputMatrix);
    free(outputMatrix);
    float elapsed = (endTime.tv_sec - startTime.tv_sec) + ((endTime.tv_usec - startTime.tv_usec)/1000000.0);
    printf("Time: %f4 Seconds\n", elapsed);
    return 0;

}