#include <stdio.h>
#include <math.h>
#include "fft.c"
#include "Complex.c"

#define PI 3.14159

int main(){
    int i, j;
    float f[3] = {2000.0, 4000.0, 5000.0};
    float fs[3] = {16000.0, 20000.0, 24000.0};
    int N = 1024;

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            float w = 2 * PI * f[i];
            float fs_val = fs[j];

            complex sine[N];

            for (int k = 0; k < N; k++){
                sine[k].x = sin(w * k / fs_val);
                sine[k].y = 0;
            }

            fft(sine, N, 1/fs_val);

            char filename[40];
            sprintf(filename, "../sine_fft_f%.1f_fs%.1f.txt", f[i], fs_val);
            FILE* fft_file = fopen(filename, "w+");

            for (int k = 0; k < N; k++){
                fprintf(fft_file, "%f ", ccabs(sine[k]));
            }

            fclose(fft_file);
        }
    }

    return 0;
}

