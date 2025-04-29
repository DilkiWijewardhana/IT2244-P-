::turns off the command echoing,hide the command execution
@echo off  

::displays the current user's username
echo username:%username%

::displays the windows version
ver

::set the text color in cmd to white
color 7

::displays the current time
time

::displays the current date
date

::lists files in wide format
dir /w

::get the user input for age
set /p Age=How old are you? 

::displays the age
::%Age% is the input age from user
echo You are %Age% years old.

::Keeps the window open until the user presses a key
pause