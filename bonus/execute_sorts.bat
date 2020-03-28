@echo off
@echo SORTARILE IN C++ SE AFLA IN FISIERUL output-cpp.out
@echo SORTARILE IN PYTHON SE AFLA IN FISIERUL output-python.out
@echo TIMPUL ESTE ROTUNJIT LA 3 ZECIMALE, DECI 0.0 INSEAMNA CA TIMPUL RULARII ESTE MAI MIC DE 0.001s
set /P NrVar="Numarul de elemente: "
set /P NrMax="Valoarea maxima a elementelor: "
g++ -std=c++11 tema1.cpp -o tema1.exe
pause
@echo SORTARILE IN C++:
tema1.exe %NrVar% %NrMax%
pause
@echo SORTARILE IN PYTHON:
py tema1.py %NrVar% %NrMax%
pause
clear_sorts.bat