%% DSP Lab - sassion 3
%%
load('SOS_G.mat');
load('Hd_object.mat');
[h, w] = freqz(SOS, 1000);
%plot(w, abs(h))
%%
noise1 = wgn(60 * 10000, 1, 0);
noise2 = wgn(60 * 10000, 1, 0) + 4;


%%
filtered_noise1 = filter(Hd, noise1);
filtered_noise2 = filter(Hd, noise2);

subplot(2, 1, 1)
plot(abs(fft(filtered_noise1)))
xlabel('Frequency (Hz)');
ylabel('Magnitude');
title('spectrum of noise1');

subplot(2, 1, 2)
plot(abs(fft(filtered_noise2)))
xlabel('Frequency (Hz)');
ylabel('Magnitude');
title('spectrum of noise2');

