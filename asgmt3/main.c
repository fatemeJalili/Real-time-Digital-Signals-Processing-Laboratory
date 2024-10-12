#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#define pi 3.14

double w1[3], w2[3], w3[3];
const double A[3][2] = {{-1.071, 0.843}, {0.543, 0.819}, {-0.178, 0.014}};
const double B[3][3] = {{1, -0.697, 1}, {1, 0.018, 1}, {1, -0.351, 1}};
const double G[3] = {0.603, 0.603, 0.968};

void initializeWeights(){
    for (int j = 0; j < 3; j++){
        w1[j] = 0;
        w2[j] = 0;
        w3[j] = 0;
    }
}

double DirectForm2(int unit, double x){
    double y;
    w1[unit] = x - A[unit][0] * w2[unit] - A[unit][1] * w3[unit];
    y = B[unit][0] * w1[unit] + B[unit][1] * w2[unit] + B[unit][2] * w3[unit];
    w3[unit] = w2[unit];
    w2[unit] = w1[unit];
    return y;
}

double *IIR_Filtering(double *x, int N){
    double y = 0;
    double *Output = (double *)malloc(N * sizeof(double));
    initializeWeights();
    for (int j = 0; j < N; j++){
        y = DirectForm2(0, x[j] * G[0]);
        y = DirectForm2(1, y * G[1]);
        y = DirectForm2(2, y * G[2]);
        Output[j] = y;
    }
    return Output;
}

double complex *dft(double *x, int N){
    double complex *X = (double complex *)malloc(N * sizeof(double complex));
    for (int k = 0; k < N; k++){
        X[k] = 0 + 0 * I;
        for (int n = 0; n < N; n++){
            double complex W = cos(2 * pi * k * n / N) - I * sin(2 * pi * k * n / N);
            X[k] += x[n] * W;
        }
    }
    return X;
}

int main(){
    int N = 6000;

    FILE *noise1F = fopen("../noise1.txt", "r");
    FILE *noise2F = fopen("../noise2.txt", "r");

    double *noise1 = (double *)malloc(N * sizeof(double));
    double *noise2 = (double *)malloc(N * sizeof(double));

    for (int i = 0; i < N; i++){
        if (fscanf(noise1F, "%lf", &noise1[i]) != 1){
            printf("Error reading from noise1 file\n");
            return 1;
        }
        if (fscanf(noise2F, "%lf", &noise2[i]) != 1) {
            printf("Error reading from noise2 file\n");
            return 1;
        }
    }

    fclose(noise1F);
    fclose(noise2F);

    double *filtered_noise1 = IIR_Filtering(noise1, N);
    double *filtered_noise2 = IIR_Filtering(noise2, N);

//    FILE *outputFile = fopen("../filtered_noise.txt", "w");
//    if (outputFile == NULL)
//    {
//        printf("Error creating file\n");
//        return 1; // Exit the program with an error code
//    }
//
//    for (int i = 0; i < N; i++)
//    {
//        fprintf(outputFile, "%f\n", creal(filtered_noise[i]));
//    }
//
//    fclose(outputFile);

    double complex *dft_filtered_noise1 = dft(filtered_noise1, N);
    double complex *dft_filtered_noise2 = dft(filtered_noise2, N);

    FILE *outputFile1 = fopen("../dft_noise1.txt", "w");
    FILE *outputFile2 = fopen("../dft_noise2.txt", "w");
    for (int i = 0; i < N; i++){
        fprintf(outputFile1, "%f\n", creal(dft_filtered_noise1[i]));
        fprintf(outputFile2, "%f\n", creal(dft_filtered_noise2[i]));
    }
    fclose(outputFile1);
    fclose(outputFile2);

    free(noise1);
    free(filtered_noise1);
    free(dft_filtered_noise1);
    free(noise2);
    free(filtered_noise2);
    free(dft_filtered_noise2);

    return 0;
}