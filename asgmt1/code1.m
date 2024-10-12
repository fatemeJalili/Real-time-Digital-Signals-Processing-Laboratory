%% DSP Lab - Sassion 1
%% Upsample
clear;
[audio, fs] = audioread('myAudio.aac');
save('fs.mat', 'fs')
writematrix(audio(:,1), 'audio.txt')
upSampled_audio = zeros(2 * size(audio, 1), 2);

for i = 1 : 2 : size(audio, 1)
    upSampled_audio(i, :) = audio((i+1)/2, :);
end
%sound(upSampled_audio, fs);

%% Downsample
downSampled_audio = zeros(size(audio, 1) / 2, 2);
for i = 1 : size(audio, 1) / 2
    downSampled_audio(i, :) = audio(2*i, :);
end
sound(downSampled_audio, fs);

%%
