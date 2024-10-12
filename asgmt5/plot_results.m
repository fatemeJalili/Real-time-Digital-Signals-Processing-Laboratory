%% DSP lab - lab 4
%%
% Read the data from the C output files
fft_cos = dlmread('cos_output.txt');
fft_sin = dlmread('sin_output.txt');
fft_rect = dlmread('rect_output.txt');

figure;

subplot(3, 1, 1);
plot(fft_cos);
title('Cos Spectrum');

subplot(3, 1, 2);
plot(fft_sin);
title('Sin Spectrum');

subplot(3, 1, 3);
plot(fft_rect);
title('Rect Spectrum');
        
   