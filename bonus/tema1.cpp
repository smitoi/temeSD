#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
#include <stdlib.h>

int		maxim(std :: vector<int>);
void		generateTest(int, int);
void		afisare(std :: vector<int>);
bool		isSorted(std :: vector<int>);
void	swap(int&, int&);

// BUBLE SORT O(n^2)
void		bubble_sort(std :: vector<int>	&array)
{
	if (array.size() > 10000)
		return ;
	int		aux;
	
	for (std :: size_t index = 0; index < array.size(); ++index)
		for (std :: size_t jndex = index + 1; jndex < array.size(); ++jndex)
				if (array[index] > array[jndex])
				{
					aux = array[index];
					array[index] = array[jndex];
					array[jndex] = aux;
				}
}

// INSERTION SORT O(n^2)
void		insertion_sort(std :: vector<int>	&array)
{
	if (array.size() > 10000)
		return ;
	int		jndex;
	int		valueInsert;
	
	for (std :: size_t index = 1; index < array.size(); ++index)
	{
		valueInsert = array[index];
		jndex = index;
		
		while (jndex > 0 && valueInsert < array[jndex - 1])
		{
			array[jndex] = array[jndex - 1];
			jndex--;
		}
		array[jndex] = valueInsert;
	}
}

// SELECTION SORT O(n^2)
void		selection_sort(std :: vector<int>	&array)
{
	if (array.size() > 10000)
		return ;
	int		minim;
	int		aux;
	
	for (std :: size_t index = 0; index < array.size(); ++index)
	{
		minim = index;
		for (std :: size_t jndex = index + 1; jndex < array.size(); ++jndex)
			if (array[minim] > array[jndex])
				minim = jndex;
		
		aux = array[index];
		array[index] = array[minim];
		array[minim] = aux;
	}
}

// MERGE SORT O(n * logn)
std :: vector<int>		inter_class(std :: vector<int>	left, std :: vector<int> right)
{
	int					index = 0;
	int					jndex = 0;
	std :: vector<int>	rez;
	
	while (index < left.size() && jndex < right.size())
		if (left[index] < right[jndex])
		{
			rez.push_back(left[index]);
			index++;
		}
		else
		{
			rez.push_back(right[jndex]);
			jndex++;
		}
	
	while (index < left.size())
	{
		rez.push_back(left[index]);
		index++;
	}
	
	while (jndex < right.size())
	{
		rez.push_back(right[jndex]);
		jndex++;
	}
	
	return	rez;
}

std :: vector<int>		merge_sort(std :: vector<int>	array)
{
	if (array.size() <= 1)
		return	array;
	else
	{
		size_t		mid = array.size() / 2;
		std :: vector<int>	left;
		std :: vector<int> right;
		
		for (std :: size_t index = 0; index < array.size(); ++index)
			if (index < mid)
				left.push_back(array[index]);
			else
				right.push_back(array[index]);
		left = merge_sort(left);
		right = merge_sort(right);
		return inter_class(left, right);
	}
}

// QUICK SORT O(n * logn)
int		partition(std :: vector<int> &array, int	left, int right)
{
	int		index = left - 1;
	int		pivot = array[right];
	int		aux;
	
	for	(std :: size_t jndex = left; jndex < right; ++jndex)
		if (array[jndex] < pivot)
		{
			index += 1;
			aux = array[index];
			array[index] = array[jndex];
			array[jndex] = aux;
		}
	
	aux = array[index + 1];
	array[index + 1] = array[right];
	array[right] = aux;
	
	return (index + 1);
}

void	quick_sort(std :: vector<int> &array, int left, int right)
{
	int		poz;
	
	if (left < right)
	{
		poz = partition(array, left, right);
		quick_sort(array, left, poz - 1);
		quick_sort(array, poz + 1, right);
	}
}

// COUNT SORT O(n)
void	count_sort(std :: vector<int>	&array, int	maxim)
{
	std :: vector<int>	count(maxim, 0);
	std :: vector<int> 	rez(array.size(), 0);
	for(std :: size_t index = 0; index < array.size(); ++index)
		count[array[index]] += 1;

	for(std :: size_t index = 1; index < count.size(); ++index)
		count[index] += count[index - 1];

	for(std :: size_t index = 0; index < array.size(); ++index)
	{
		rez[count[array[index]] - 1] = array[index];
		count[array[index]] -= 1;
	}

	for (std :: size_t index = 0; index < array.size(); ++index)
		array[index] = rez[index];
}

// RADIX SORT + COUNT SORT (cu bază și în funcție de cifră)
std :: vector<int>	counting_sort(std :: vector<int>	array, int		baza, int		exponent)
{
	std :: vector<int>	count(baza, 0);
	std :: vector<int> 	rez(array.size(), 0);
	int		aux = 0;
	
	for(std :: size_t index = 0; index < array.size(); ++index)
	{
		aux = array[index] / exponent % baza;
		count[aux] += 1;
	}
	
	for(std :: size_t index = 1; index < count.size(); ++index)
		count[index] += count[index - 1];

	for(int index = array.size() - 1; index > -1; --index)
	{
		aux = array[index] / exponent % baza;
		count[aux] -= 1;
		rez[count[aux]] = array[index];
	}
	
	return rez;
}

std :: vector<int>	radix_sort(std :: vector<int> array, int	baza)
{
	int		elMax = maxim(array);
	for (int	exponent = 1; elMax / exponent > 0; exponent *= baza)
		array = counting_sort(array, baza, exponent);


	return array;
}

// HEAP SORT
void	create_maxHeap(std :: vector<int>	&array, int	index, int	length)
{
	int		max = index;
	int		left = 2 * index + 1;
	int		right = 2 * index + 2;
	
	if (left < length && array[max] < array[left])
	{
		swap(array[max], array[left]);
		create_maxHeap(array, left, length);
	}
	if (right < length && array[max] < array[right])
	{
		swap(array[max], array[right]);
		create_maxHeap(array, right, length);
	}
}

void	heap_sort(std :: vector<int>	&array)
{
	if (array.size() > 10000)
		return ;
	for (std :: size_t index = array.size() - 1; index > 0; --index)
		create_maxHeap(array, index, array.size());
	create_maxHeap(array, 0, array.size());
	for (std :: size_t index = array.size() - 1; index > 0; --index)
	{
		swap(array[index], array[0]);
		create_maxHeap(array, 0, index);
	}
}

// COCKTAIL SORT
void	cocktail_sort(std :: vector<int>	&array)
{
	if (array.size() > 10000)
		return ;
	int		index = 0;
	int		high = array.size() - 1;
	int		low = 0;
	bool	sorted;
	
	sorted = false;
	while (sorted == false)
	{
		sorted = true;
		while (index < high)
		{
			if (array[index] > array[index + 1])
			{
				sorted = false;
				swap(array[index], array[index + 1]);
			}
			index++;
		}
		high--;
		index = high;
		sorted = true;
		while (index > low)
		{
			if (array[index] < array[index - 1])
			{
				sorted = false;
				swap(array[index], array[index - 1]);
			}
			index--;
		}
		low++;
		index = low;
	}
}

// PANCAKE SORT
void	flip(std :: vector<int>	&array, int start, int stop)
{
	while (start < stop)
	{
		swap(array[start], array[stop]);
		start++;
		stop--;
	}
}

void	pancake_sort(std :: vector<int>	&array)
{
	if (array.size() > 10000)
		return ;
	int	max = -1;
	
	for (std :: size_t index = array.size() - 1; index > 0; --index)
	{
		for (std :: size_t jndex = 0; jndex < index + 1; ++jndex)
			if (array[jndex] > array[max] or max == -1)
				max = jndex;
		flip(array, max, index);
		max = -1;
	}
}
/// FUNCȚII AUXILIARE

// AFISARE
void		afisare(std :: vector<int>	array)
{
	for(std :: size_t index = 0; index < array.size(); ++index)
		std :: cout << array[index] << ' ';
	std :: cout << '\n';

}

// VERIFICAREA SORTARII
bool		isSorted(std :: vector<int>	array)
{
	for(std :: size_t index = 1; index < array.size(); ++index)
		if (array[index - 1] > array[index])
			return 	false;
	
	return 	true;

}

// GENERAREA TESTULUI
void		generateTest(int	number, int		maximum)
{
	std :: ofstream		out;
	srand(time(NULL));

	out.open("test.in");
	while (number)
	{
		out << rand() % maximum <<' ';
		number--;
	}
	out.close();
}

// MAXIMUL DINTR-UN VECTOR
int		maxim(std :: vector<int>	array)
{
	int		maxim = 0;
	
	for (std :: size_t index = 0; index < array.size(); ++index)
		if (array[maxim] < array[index])
			maxim = index;
	
	return array[maxim];
}

// SWAP ÎNTRE ELEMENTE
void	swap(int	&a,	int		&b)
{
	int		aux;
	
	aux = a;
	a = b;
	b = aux;
}

// MAIN
int		main(int	argc, char*		argv[])
{
	double				start;
	double				end;
	double				time_taken;
	std :: ifstream		input;
	std :: ofstream		output;
	std :: vector<int> 	array;
	int					aux;
	
	if (argc != 3)
	{
		std :: cout << "Usage: " << argv[0] << " <no. of elements> <maximum value of elements>" << '\n';
		return (-1);
	}
	else
		generateTest(atoi(argv[1]), atoi(argv[2]));
	
	std :: vector<std :: string>	sortari = {
		"Bubble sort", 
		"Insertion sort", 
		"Selection sort", 
		"Merge sort", 
		"Quick sort", 
		"Count sort", 
		"Radix sort baza 10",
		"Radix sort baza 2",
		"Radix sort baza 256",
		"Heap sort",
		"Cocktail sort",
		"Pancake sort",
		"C++ .sort()"};
	
	output.open("output-cpp.out");
	for (std :: size_t index = 0; index < sortari.size(); ++index)
	{
		input.open("test.in");
		
		while (input >> aux)
			array.push_back(aux);
		input.close();
		start = clock();
		switch (index) {
			case 0:
				bubble_sort(array);
				break;
			case 1:
				insertion_sort(array);
				break;
			case 2:
				selection_sort(array);
				break;
			case 3:
				array = merge_sort(array);
				break;
			case 4:
				quick_sort(array, 0, array.size() - 1);
				break;
			case 5:
				count_sort(array, maxim(array) + 1);
				break;
			case 6:
				array = radix_sort(array, 10);
				break;
			case 7:
				array = radix_sort(array, 2);
				break;
			case 8:
				array = radix_sort(array, 256);
				break;
			case 9:
				heap_sort(array);
				break;
			case 10:
				cocktail_sort(array);
				break;
			case 11:
				pancake_sort(array);
				break;
			case 12:
				sort(array.begin(), array.end());
				break;
		}
		end = clock();
		time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
		if (isSorted(array))
		{
			std :: cout << sortari[index] << " realizat in " << time_taken << " secunde" << '\n';
			output << sortari[index] << " realizat in " << time_taken << " secunde" << '\n';
		}
		else
		{
			std :: cout << sortari[index] << " ERROR" << '\n';
			output << sortari[index] << " ERROR" << '\n';
		}
		if (index == 12)
			for (std :: size_t jndex = 0; jndex < array.size(); ++jndex)
				output << array[jndex] << ' ';
		output << '\n';
		array.clear();
	}
	output.close();

	return (0);
}