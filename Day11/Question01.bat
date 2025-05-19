::Question 01
cd %USERPROFILE%\Desktop
mkdir CSC2244 Marks Exam
 
cd CSC2244
mkdir practical theory "exam papers"

cd Practical
 echo. > practical.docx
 echo. > practical.pptx
 
cd..\theory
echo Theory Text > theory.txt
echo. > theory.docx
echo. > theory.pptx

cd "..\exam papers"
echo Exam Text > exam.txt
echo. > exam.docx
echo. > exam.pptx

cd %USERPROFILE%\Desktop

echo. > "Icae MArks.xlsx"
echo. > "Final Exam Marks.xlsx"

move "Icae MArks.xlsx"
move "Final Exam Marks.xlsx"

xcopy /E /I Marks Exam\Marks
attri +h Exam 