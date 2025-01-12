clc
clear

% Establish connections
s = serialport('COM3',9600);     %Your COM port is likely different. Make sure to watch the above video to see how to find where each board is
pause(3)

% When sending a string to control multiple steppers, the format should be
% as follows "Stepper #1, Steps for Stepper 1 to move, Stepper #2, Steps
% for Stepper 2 to move". If you have changed the Arduino IDE code to allow
% for additional steppers (i.e., 3 or more), then you would continue this
% format to account for your additional stepper motors.
% Have the first stepper do a full rotation while the second stepper does nothing
steps_for_1 = 0;    %up-down 4-7
steps_for_2 = 0;  %8-11 closer-open. positive num to move inside



% Append combines the various strings into one individual string to be sent over to the Arduino
Multiple_Stepper_String = append("1,",int2str(steps_for_1),",","2,",int2str(steps_for_2));

% Send the string to the Arduino using the connected serial port
write(s,Multiple_Stepper_String,'string');

% Pause to allow the previous movements to complete before sending new movements
pause(7)

clear