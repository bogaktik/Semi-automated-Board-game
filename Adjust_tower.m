clear
clc

s = serialport('COM', 9600);
pause(5)
write(s, int2str(), 'string')