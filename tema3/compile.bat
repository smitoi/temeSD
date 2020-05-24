@echo off
set /P var="Problema pe care vreti sa o compilati: "
g++ -std=c++11 %var%.cpp -o %var%.exe
pause