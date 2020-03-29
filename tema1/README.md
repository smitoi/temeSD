# Tema 1
Implementarea următorilor algoritmi de sortare:
* Pentru un număr maxim de elemente (vor afișa 'ERROR' dacă șirul le depășește limitele):
  * Bubble Sort (max. 5000)
  * Insertion Sort (max. 7000)
  * Selection Sort (max. 7000)
  * Pancake Sort (max. 3000)
  * Cocktail Sort (max. 3000)
  * Heap Sort (max. 5000)
* Pentru elemente mai mici de 1 000 000 (va afișa 'ERROR' dacă elementul maxim din șir depășește 1 000 000):
  * Count Sort
* Fără limită:
  * Merge Sort
  * Quick Sort
  * Radix Sort (în baza 2, 10, 256)

Codul se află în fișierul 'tema1.py'. Testele se dau în fișierul 'teste.in' sub forma:
```
<nr. teste n>
<nr. elem. test 1> <val. min. elem. test 1> <val. max. elem.  test 1>
<nr. elem. test 2> <val. min. elem. test 2> <val. max. elem.  test 2>
<nr. elem. test 3> <val. min. elem. test 3> <val. max. elem.  test 3>
. . .
<nr. elem. test n> <val. min. elem. test n> <val. max. elem.  test n>
```
Observații:
* Heap Sort rulează bine doar pentru număr mic de numere
* Radix Sort merge mai bine dacă este implementat cu o bază mai mare
* Radix Sort în baza 10 și 2 este depășit de Quick Sort
* Quick Sort cu mediana din 3 e o idee mai rapid decât cu mediana elementul final
