%% DSP lab - sassion 2
%% A
[audio, fs] = audioread('Mefsin.wav');
%% B
X = fft(audio);
L = length(audio);
A1 = 2 * abs(X(1:L/2+1)/L);
frequencies = fs*(0:(L/2))/L;
subplot(2, 1, 1)
plot(frequencies, A1);
title('Single-Sided Amplitude Spectrum of Mefsin Audio');
xlabel('Frequency (Hz)');
ylabel('Amplitude');

%% C
[~, indx] = max(A1);
f0 = frequencies(indx);
theta = 2*pi*f0 / fs;
b = [1 -2*cos(theta) 1];
filtered_audio = filter(b, 1, audio);
Y = fft(filtered_audio);
A2 = 2 * abs(Y(1:L/2+1)/L);
frequencies = fs*(0:(L/2))/L;
subplot(2, 1, 2)
plot(frequencies, A2);
title('Single-Sided Amplitude Spectrum of filtered Mefsin Audio');
xlabel('Frequency (Hz)');
ylabel('Amplitude');

sound(filtered_audio, fs)