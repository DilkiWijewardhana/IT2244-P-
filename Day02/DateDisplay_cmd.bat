::Display the year,month,date and dayname separately of the current date

::turns off the command echoing,hide the command execution
@echo OFF

::extract the year from the current date
::~10,4 extracts 4 characters starting at position 10 to display only year 
set year=%date:~ 10,4%

::extract the month from the current date 
::~4,2 extracts 2 characters starting at position 4 to display only month 
set month=%date:~ 4,2%

::extract the date from the current date 
::~7,2 extracts 2 characters starting at position 7 to display only date 
set day=%date:~ 7,2%

::extract the day from the current date 
::~0,3 extracts 3 characters starting at position 0 to display only dayname 
set weekday=%date:~ 0,3%

::display the year of the current date
echo Year: %year%

::display the month of the current date
echo Month: %month%

::display the date of the current date
echo Date: %day%

::display the day of the current date
echo Day: %weekday%

if "%month%"=="01" set monthName=January
if "%month%"=="02" set monthName=February
if "%month%"=="03" set monthName=March
if "%month%"=="04" set monthName=April
if "%month%"=="05" set monthName=May
if "%month%"=="06" set monthName=June
if "%month%"=="07" set monthName=July
if "%month%"=="08" set monthName=August
if "%month%"=="09" set monthName=September
if "%month%"=="10" set monthName=October
if "%month%"=="11" set monthName=November
if "%month%"=="12" set monthName=December

::display the monthname of the current date
echo The current month is %monthName%.

::Keeps the window open until the user presses a key
pause