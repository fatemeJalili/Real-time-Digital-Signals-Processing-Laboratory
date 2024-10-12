%% DSP lab - sassion 2
%%
save('coef.mat', 'Num')
f1 = 2000;
f2 = 4000;
f3 = 20000;
t = -0.0004 + 0.00001 : 0.00001 : 0.0004;
y1 = sin(2*pi*f1*t);
y2 = sin(2*pi*f2*t);
y3 = sin(2*pi*f3*t);


