%% DSP lab - lab 3
%%
f = [2000.0, 4000.0, 5000.0];
fs = [16000.0, 20000.0, 24000.0];
N = 1024;

for j = 1:length(fs)
    figure;
    sgtitle(sprintf('FFT Results for fs=%.1f', fs(j)));
    
    for i = 1:length(f)
        
        t = (0:N-1) / fs(j);
        x = sin(2*pi*f(i)*t);
        
        % Calculate FFT using MATLAB
        fft_matlab = fft(x);
        
        % Read FFT data calculated by C code
        filename = sprintf('sine_fft_f%.1f_fs%.1f.txt', f(i), fs(j));
        fft_c = dlmread(filename);
        
        subplot(length(f), 2, (i-1)*2 + 1);
        plot(abs(fft_matlab)/ fs(j));
        title(sprintf('f=%.1f (MATLAB FFT)', f(i)));
        xlabel('Frequency');
        ylabel('Magnitude');
        subplot(length(f), 2, (i-1)*2 + 2);
        plot(fft_c);
        title(sprintf('f=%.1f (C FFT)', f(i)));
        xlabel('Frequency');
        ylabel('Magnitude');
    end
end