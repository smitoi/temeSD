import sys
from time import time
from random import seed
from random import randint
from random import shuffle

# BUBBLE SORT O(n^2)
def bubble_sort(array):
    if len(array) > 3000:
        return 
    for index in range(len(array)):
        for jndex in range(index + 1, len(array)):
            if array[index] > array[jndex]:
                array[index], array[jndex] = array[jndex], array[index]

# INSERTION SORT O(n^2)
def insertion_sort(array):
    if len(array) > 3000:
        return 
    for index in range(1, len(array)):
        valueInsert = array[index]
        jndex = index
        
        while jndex > 0 and valueInsert < array[jndex - 1]:
            array[jndex] = array[jndex - 1]
            jndex = jndex - 1
        array[jndex] = valueInsert

# SELECTION SORT O(n^2)
def selection_sort(array):
    if len(array) > 3000:
        return 
    for index in range(len(array)):
        minim = index
        for jndex in range(index + 1, len(array)):
            if array[minim] > array[jndex]:
                minim = jndex
        
        array[index], array[minim] = array[minim], array[index]

# MERGE SORT O(n*logn)
def inter_class(left, right):
    i = 0
    j = 0
    rez = list()
    
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            rez.append(left[i])
            i += 1
        else:
            rez.append(right[j])
            j += 1
    
    while i < len(left):
        rez.append(left[i])
        i += 1
    
    while j < len(right):
        rez.append(right[j])
        j += 1
    
    return rez

def merge_sort(array):
    if len(array) <= 1:
        return array
    else:
        mid = len(array)//2
        left = merge_sort(array[:mid])
        right = merge_sort(array[mid:])
        return inter_class(left, right)

# QUICK SORT cu mediana elementul de la final - O(n*logn)
def partition_end(array, left, right):
    index = left - 1

    for jndex in range(left, right):
        if array[jndex] < array[right]:
            index += 1
            array[index], array[jndex] = array[jndex], array[index]

    array[index + 1], array[right] = array[right], array[index + 1]
    return (index + 1)

def quick_sort_end(array, left, right):
    if (left < right):
        poz = partition_end(array, left, right)
        quick_sort_end(array, left, poz - 1)
        quick_sort_end(array, poz + 1, right)

# QUICK SORT cu mediana din trei - O(n*logn)
def median_of_three(array, left, right):
    mid = (left + right) // 2;
    
    if (array[left] > array[right]):
        array[left], array[right] = array[right], array[left]
    if (array[left] > array[mid]):
        array[left], array[mid] = array[mid], array[left]
    if (array[mid] > array[right]):
        array[mid], array[right] = array[right], array[mid]
    return array[mid]

def partition(array, left, right):
    index = left - 1
    jndex = right + 1
    pivot = median_of_three(array, left, right)
    
    while (index < jndex):
        index += 1
        while (array[index] < pivot):
            index += 1
        
        jndex -= 1
        while (array[jndex] > pivot):
            jndex -= 1;
        
        if (index < jndex):
            array[index], array[jndex] = array[jndex], array[index]
    
    return jndex

def quick_sort_mo3(array, left, right):
    if (left < right):
        poz = partition(array, left, right)
        quick_sort_mo3(array, left, poz)
        quick_sort_mo3(array, poz + 1, right)

# COUNT SORT O(n)
def count_sort(array, maxim):
    count = [0] * maxim;
    rez = [0] * len(array)

    for index in range(len(array)):
        count[array[index]] += 1

    for index in range(1, len(count)):
        count[index] += count[index - 1]

    for index in range(len(array)):
        rez[count[array[index]] - 1] = array[index]
        count[array[index]] -= 1

    for index in range(len(array)):
        array[index] = rez[index]

# RADIX SORT
def counting_sort(array, baza, cifra):
    count = [0] * baza
    rez = [0] * len(array)

    for index in range(len(array)):
        aux = (array[index] // (baza ** cifra)) % baza
        count[aux] += 1

    for index in range(1, len(count)):
        count[index] += count[index - 1]

    for index in range(len(array) - 1, -1, -1):
        aux = (array[index] // (baza ** cifra)) % baza
        count[aux] -= 1
        rez[count[aux]] = array[index]
    
    return rez

def radix_sort(array, baza):
    maxim = elementMaxim(array)
    cifre = 0
    while (maxim):
        maxim = maxim // baza
        cifre += 1
    
    for cifra in range(cifre):
        array = counting_sort(array, baza, cifra)
    
    return array
    
# HEAP SORT
def create_maxHeap(array, index, length):
    max = index
    left = 2 * index + 1
    right = 2 * index + 2
    
    if left < length and array[max] < array[left]:
        array[left], array[max] = array[max], array[left]
        create_maxHeap(array, left, length)

    if right < length and array[max] < array[right]:
        array[right], array[max] = array[max], array[right]
        create_maxHeap(array, right, length)
    
def heap_sort(array):
    for index in range(len(array) - 1, -1, -1):
        create_maxHeap(array, index, len(array))
    for index in range(len(array) - 1, 0, -1): 
        array[index], array[0] = array[0], array[index] 
        create_maxHeap(array, 0, index) 

# COCKTAIL SORT
def cocktail_sort(array):
    if len(array) > 3000:
        return ;
    index = 0
    high = len(array) - 1
    low = 0
    
    sorted = False
    while (sorted == False):
        sorted = True
        while (index < high):
            if (array[index] > array[index + 1]):
                sorted = False
                array[index], array[index + 1] = array[index + 1], array[index]
            index += 1
        
        high -= 1
        index = high
        while (index > low):
            if (array[index] < array[index - 1]):
                sorted = False
                array[index], array[index - 1] = array[index - 1], array[index]
            index -= 1
        
        low += 1
        index = low

# PANCAKE SORT
def flip(array, start, stop):
    
    while (start < stop):
        array[start], array[stop] = array[stop], array[start]
        start += 1
        stop -= 1
        

def pancake_sort(array):
    if len(array) > 3000:
        return ;
    maxim = -1
    
    for index in range(len(array) - 1, 0, -1):
        
        for jndex in range(index + 1):
            if (array[jndex] > array[maxim] or maxim == -1):
                maxim = jndex
        flip(array, maxim, index)
        maxim = -1


# FUNCTII AUXILIARE
def elementMaxim(array):
    maxim = 0
    
    for index in range(len(array)):
        if array[index] > maxim:
            maxim = array[index]
    return (maxim + 1)
    

def isSorted(array):
    for index in range(1, len(array)):
        if array[index - 1] > array[index]:
            return False
    return True
    
    return True


def testare_sortari(numar, maxim):
    sortari = ('.sort()', 'sorted()', 'Bubble sort', 'Insertion sort', 'Selection sort', 'Merge sort', 
                'Quick sort (mediana final)', 'Quick sort (mediana din trei)', 'Count sort', 'Radix sort baza 10', 
                'Radix sort baza 2', 'Radix sort baza 256', 'Heap sort', 'Cocktail sort', 'Pancake sort')
    print ('Sortam ' + str(numar) + ' elemente cu valori între 0 și ' + str(maxim))
    elemente_random = list()
    
    seed(time())
    for index in range(numar):
        elemente_random.append(randint(0, maxim))

    file = open('test.in', 'w')
    for index in range(numar):
        file.write(str(elemente_random[index]))
        if index != (numar - 1):
            file.write(' ')
    file.close()
    
    ofile = open('output-py.out', 'w')
    for name in sortari:
        file = open('test.in', 'r')
        elemente = file.readline()
        elemente = elemente.split(' ')
        elemente.pop()
        elemente = [int(x) for x in elemente]
        file.close()
        startTime = time()
        if (name == '.sort()'):
            elemente.sort()
        elif (name == 'sorted()'):
            elemente = sorted(elemente)
        elif (name == 'Bubble sort'):
            bubble_sort(elemente)
        elif (name == 'Insertion sort'):
            insertion_sort(elemente)
        elif (name == 'Selection sort'):
            selection_sort(elemente)
        elif (name == 'Merge sort'):
            elemente = merge_sort(elemente)
        elif (name == 'Quick sort (mediana final)'):
            quick_sort_end(elemente, 0, len(elemente) - 1)
        elif (name == 'Quick sort (mediana din trei)'):
            quick_sort_mo3(elemente, 0, len(elemente) - 1)
        elif (name == 'Count sort'):
            maxim = elementMaxim(elemente)
            count_sort(elemente, maxim)
        elif (name == 'Radix sort baza 10'):
            elemente = radix_sort(elemente, 10)
        elif (name == 'Radix sort baza 2'):
            elemente = radix_sort(elemente, 2)
        elif (name == 'Radix sort baza 256'):
            elemente = radix_sort(elemente, 256)
        elif (name == 'Heap sort'):
            heap_sort(elemente)
        elif (name == 'Cocktail sort'):
            cocktail_sort(elemente)
        elif (name == 'Pancake sort'):
            pancake_sort(elemente)
        endTime = time()
        if isSorted(elemente):
            print (name + ' a sortat elementele in ' + str(round(endTime - startTime, 3)))
            ofile.write (name + ' a sortat elementele in ' + str(round(endTime - startTime, 3)) + '\n')
        else:
            print (name + ': ERROR')
            ofile.write (name + ': ERROR\n')
        ofile.write(str(elemente) + '\n')
    ofile.close()
if __name__ == "__main__":
    if (len(sys.argv) != 3):
        print ('Usage: python ' + str(sys.argv[0]) + ' <no. of elements> <maximum value of elements>')
    else:
        testare_sortari(int(sys.argv[1]), int(sys.argv[2]))