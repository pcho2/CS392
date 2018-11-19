//Philip Cho, “I pledge my honor I have abided by the Stevens Honor System.”
//edit file
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

void printMatrix(float * matrix, int width){
    int count2 = 0;
    int i;
    for(i = 0; i < width * width; i++){
        printf("%.2f ", matrix[i]);
        count2++;
        if(count2 == width){
            printf("\n");
            count2 = 0;
        }
    }
}

void transposeMatrix(float * inputMatrix, float * outputMatrix, int width, int blockWidth){
    int row;
    int column;

    int i;
    int j;
    for (int i = 0; i < width; i += blockWidth) {
        for (int j = 0; j < width; j += blockWidth) {
            for (row = i; row < i + blockWidth && row < width; row++) {
                for (column = j; column < j + blockWidth && column < width; column++) {
                    outputMatrix[column * width + row] = inputMatrix[row * width + column];
                }
            }
        }
    }
}


int main(int argc, char **argv){

    if (argc != 3) {
        fprintf(stderr, "Wrong number of command-line arguments\n");
        return 1;
    }
    float * inputMatrix;
    float * outputMatrix;
    int width = atoi(argv[1]);
    int blockWidth = atoi(argv[2]);
    inputMatrix = (float *) malloc(width * width *sizeof(float));
    outputMatrix = (float *) malloc(width * width *sizeof(float));
    //randomNumber 
    int randomNumberLoop;
    for(randomNumberLoop = 0; randomNumberLoop < width * width; randomNumberLoop++){
        inputMatrix[randomNumberLoop] = rand();
    }
    // printMatrix(inputMatrix, width);
    //Transpose and Time
    struct timeval startTime;
    gettimeofday(&startTime, 0);
    transposeMatrix(inputMatrix, outputMatrix, width, blockWidth);
    struct timeval endTime;
    gettimeofday(&endTime, 0);

    // printf("\nOutput:\n");
    // printMatrix(outputMatrix, width);
    free(inputMatrix);
    free(outputMatrix);


    // long long t1 = startTime.tv_usec;
    // long long t2 = endTime.tv_usec;
    // long long elapsed = t2 - t1;

    // long long t1sec = startTime.tv_sec;
    // long long t2sec = endTime.tv_sec;
    // long long elapsedSec = t2sec - t1sec;

    float elapsed = (endTime.tv_sec - startTime.tv_sec) + ((endTime.tv_usec - startTime.tv_usec)/1000000.0);
    // printf("Time: %lld Seconds\n", elapsedSec);
    printf("Time: %f4 Seconds\n", elapsed);
    return 0;

}