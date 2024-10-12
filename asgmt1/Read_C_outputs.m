%% DSP Lab - Sassion 1
clear;
%% Read Upsampled C output .txt file 
load('fs.mat', 'fs');
upSampled_audio = importdata('upSampled_audio.txt');
%sound(upSampled_audio, fs);

%% Read Downsampled C output .txt file 
downSampled_audio = importdata('downSampled_audio.txt');
sound(downSampled_audio, fs);

%%