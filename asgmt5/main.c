#include <stdio.h>
#include <math.h>
#include "fft.c"
#include "Complex.c"
#include "Complex.h"

# define N 1024
# define L 8
# define len 8 * 1024

void ISR(complex* ping, complex* pong, float* a, float* b);
void coef_generator(float* signal, float* a, float* b, int window_num);

int main() {
    double spectrum[N / 2 + 1] = {0};
    double buffer[N / 2 + 1] = {0};
    float a[N] = {0};
    float b[N] = {0};
    float signal[len] = {0};
    complex ping[N];
    complex pong[N];

    for (int n = 0; n < N * L; n++){
        signal[n] = 10000 * cos(n * 100 * 2 * PI / 1024);
    }
//
//    for (int n = 0; n < N * L; n++){
//        signal[n] = 10000 * sin(n * 100 * 2 * PI / 512);
//    }

//    for (int n = 0; n < N * L; n++) {
//        if ((n % 512) < 256) {
//            signal[n] = 1;
//        } else {
//            signal[n] = 0;
//        }
//    }

    FILE* file;
    fopen_s(&file, "../cos_output.txt", "w");
//    fopen_s(&file, "../sin_output.txt", "w");
//    fopen_s(&file, "../rect_output.txt", "w");

    int window_num = 0;
    for (window_num; window_num < floor(len / (2 * N)); window_num++) {
        coef_generator(signal, a, b, window_num);
        ISR(ping, pong, a, b);
        fft(pong, 1024, 1);

        int j = 0;
        for (j; j < N / 2 + 1; j++) {
            buffer[j] += (ccabs(pong[j]) * ccabs(pong[j]) + ccabs(pong[N - 1 - j]) * ccabs(pong[N - 1 - j])) / 2 ;
            if ((window_num - 1) % L == 0){
                spectrum[j] += buffer[j] / (L* N);
                fprintf(file, "%lf\n", spectrum[j]);
                buffer[j] = 0;
            }}

    }
    return 0;
}
void coef_generator(float *signal, float *a, float *b, int window_num) {
    int i = 0;
    for (i; i < 2 * N; i++) {
        if (i < N)
            a[i] = signal[window_num * N + i];
        else
            b[i - N] = signal[window_num * N + i];
    }
}

void ISR(complex *ping, complex *pong, float *a, float *b) {
    for (int i = 0; i < N; i++) {
        ping[i].x = a[i];
        ping[i].y = b[i];
        pong[i].x = a[i];
        pong[i].y = b[i];
    }
}