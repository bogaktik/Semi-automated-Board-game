clc
clear

s = serialport('COM',9600);
write(s,int2str(distance),'string');