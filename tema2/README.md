# Tema 2
Implementarea Fibonacci Heap în Python cu operațiile:
  * insert (valoare)
  * delete (valoare)
  * extragere-minim + returnarea nodului minim
  * merge între două heap-uri

Codul se află în fișierul 'tema2.py'. Testele se dau în fișierul 'input.txt' sub forma:

```
<nr. operații>
<operație-1> <nr. suplimentar-1>
<operație-2> <nr. suplimentar-2>
...
<operație-n> <nr. suplimentar-n>
```

(doar operațiile care au valoare necesită și numărul suplimentar)

Operații:
	* 1 - inserare valoare
    * 2 - ștergere valoare
    * 3 - afișare minim
    * 4 - șterge minim

Observații:
* Am aflat că Fibonacci Heap rulează bine în teorie, dar în practică poate fi și de două ori mai slab decât un Min-Max Heap 😮 
* Cred că există implementări mai bune (am văzut ceva cu cut și cascade cut)