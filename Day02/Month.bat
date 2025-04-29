::turns off the command echoing,hide the command execution
@echo OFF

::extract the current month from the system date  

::%date% contains the system date (e.g. "Sat 03/23/2025" )
::~4,2 extracts 2 characters starting at position 4 to get only month
set/a month=%date:~ 4,2%

::displays the month of current date
echo %month%

::Keeps the window open until the user presses a key
pause