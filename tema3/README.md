# Tema 3

### Probleme. În ordinea în care 'mi-au făcut cu ochiul':

* #### Sortări (33p / max 25p - 7 probleme) ✔️
	* [x] - 3p [Statistici de ordine - sdo.cpp](https://www.infoarena.ro/problema/sdo) (quick select implementat)
	* [x] - 3p [Beri - beri.cpp](https://www.infoarena.ro/problema/beri) (quick select cu nth_element)
	* [x] - 3p [Căutare binară - cautbin.cpp](https://www.infoarena.ro/problema/cautbin) (cautare binară)
	* [x] - 4p [Numarare triunghiuri - nrtri.cpp](https://www.infoarena.ro/problema/nrtri) (sortare)
	* [x] - 4p [Vanya and Lanterns - vanya&lanterns.cpp](https://codeforces.com/problemset/problem/492/B) (sortare și diferență dintre elemente)
	* [x] - 6p [Inv - inv.cpp](https://www.infoarena.ro/problema/inv) (merge sort + numărare la fiecare interschimbare)
	* [x] - 10p [Drazil and Factorial - drazil&fact.cpp](https://codeforces.com/problemset/problem/515/C) (matematică, sortare)

* #### Liste, Stive, Cozi, Deque, Hashuri (31p / max 25p - 8 probleme) ✔️
	* [x] - 3p [Alibaba - alibaba.cpp](https://www.infoarena.ro/problema/alibaba) (stack + un fel de greedy)
	* [x] - 5p [Queue - queue.cpp](https://www.infoarena.ro/problema/queue) (două stack-uri)
	* [x] - 3p [Hotelier - hotelier.cpp](https://codeforces.com/problemset/problem/1200/A) (mergem stânga dreapta într-un vector)
	* [x] - 3p [Muzica - muzica.cpp](https://www.infoarena.ro/problema/muzica) (unordered map - 70p)
	* [x] - 4p [Vila 2 - vila2.cpp](https://www.infoarena.ro/problema/vila2) (două deque-uri)
	* [x] - 4p [Anagrams - anagrams.py](https://csacademy.com/contest/archive/task/anagrams/statement/) (sortăm cuvântul + dicționar)
	* [x] - 4p [Paranteze - paranteze.cpp](https://www.infoarena.ro/problema/paranteze) (stack cu paranteze + indecșii)
	* [x] - 5p [Sereja and Suffixes - seraja&suffixes.cpp](https://codeforces.com/problemset/problem/368/B) (set + parcurgere)
	
* #### Diverse (22p / max 25 p - 8 probleme) 3️⃣
	* [x] - 1p [Four X-tremes - four-x-tremes.py](https://csacademy.com/contest/interview-archive/task/four-x-tremes/)
	* [x] - 2p [Array Intersection array_intersection.py](https://www.csacademy.com/contest/interview-archive/task/array-intersection/)
	* [x] - 3p [Closest Pair - closest-pair.py](https://csacademy.com/contest/interview-archive/task/closest-pair/) (sortare + parcurgere de vector)
	* [x] - 3p [Largest Concat Number - largest_concat_number.cpp](https://csacademy.com/contest/interview-archive/task/largest-concat-number/) (sortare custom)
	* [x] - 3p [Bounded Offset Sorting - bounded-offset-sorting.py](https://csacademy.com/contest/interview-archive/task/Bounded-offset-sorting/) (heap)
	* [x] - 3p [Dominoes - dominoes.py](https://csacademy.com/contest/archive/task/dominoes/statement/) (queue)
	* [x] - 3p [Kefa and Company - kefa&company.py](https://codeforces.com/contest/580/problem/B) (deque cu indici + greedy)
	* [x] - 3p [Patrate3 - patrate3.cpp](https://www.infoarena.ro/problema/patrate3) (clasă puncte, sort, căutăm celălalte puncte - 50p)
	
	* [x] - 1p Blat - blat.py (FMI No Stress)
	* Încercate în timpul FMI No Stress 9 - Freakadebunic, PermutariAB, Covrigi
	* Încercate în timpul FMI No Stress Warm-up - Vampir, Ași

* #### Heap-uri, Arbori binari de căutare (13p / max 15p - două probleme) 2️⃣
	* [x] - 7p [All BST Preorders - allbst.cpp](https://csacademy.com/contest/interview-archive/task/all-bst-preorders/)
	* [x] - 6p [Proc2 - proc2.cpp](https://www.infoarena.ro/problema/proc2)

* #### Arbori de intervale, RMQ (9p / max 15p - două probleme) 6️⃣
	* [x] - 5p [Range Minimum Query (RmQ) - rmq.cpp](https://www.infoarena.ro/problema/rmq) (rmq simulat cu o matrice)
	* [x] - 4p [Mit - mit.cpp](https://www.infoarena.ro/problema/mit) (rmq de la problema precendentă + modificare vectorul inițial și reconstruire rmq - 40p)
	* [ ] - 0p [Circular RMQ](https://codeforces.com/problemset/problem/52/C) (am încercat-o, dar m-a dovedit - nu am putut să fac citirea cum trebuie, și m-am pierdut în indecși - era aceeași cu Mit, doar că aplicam operația fie pe intervalul [x, y], dacă x <= y, fie pe intervalul [x, n - 1], [0, y], dacă y > x)

## Total: 94/105p (25 + 25 + 22 + 13 + 9)

##### Observații:
* Trebuie create fișiere de intrare (de obicei e <numele-problemei>.in) pentru cele de pe InfoArena.
* Problemele în C++ au fost compilate cu 'g++ -std=c++11'
* Problemele în Python au fost rulate cu Python 3.7+
* clear-folder.bat va șterge fișierele .in, .out și .exe
	
#### Notă: Le-am implementat pe cele care mi-au permis în Python.
