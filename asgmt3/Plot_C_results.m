dft1 = dlmread('dft_noise1.txt');
dft2 = dlmread('dft_noise2.txt');

subplot(2, 1, 1)
plot(abs(dft1))
xlabel('Frequency (Hz)');
ylabel('Magnitude');
title('spectrum of noise1');

subplot(2, 1, 2)
plot(abs(dft2))
xlabel('Frequency (Hz)');
ylabel('Magnitude');
title('spectrum of noise2');