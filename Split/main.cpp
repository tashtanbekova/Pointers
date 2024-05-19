#include<iostream>
using namespace std;

#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "Russian");
	const int n=10;
	int arr[n];
	//arr[-1] = 0;
	
	FillRand(arr, n);
	Print(arr, n);

	//1- Вычесляем количество четных и нечетных
	int even_count = 0;
	int odd_count = 0;
	for (int i = 0; i < n; i++)
	{
		//if (arr[i] % 2 == 0)even_count++; else odd_count++;
		arr[i] % 2 == 0 ? even_count++ : odd_count++;
	}
	cout << "Количество четных чисел: " << even_count << endl;
	cout << "Количество нечетных чисел: " << odd_count << endl;

	//2- выделяем память для массивов
	int* even_arr = new int[even_count];
	int* odd_arr = new int[odd_count];

	//3- Копируем четные и нечетные элементы в соответствуещие массивы;
	for (int i = 0, j = 0, k = 0; i < n; i++)
	{
		//if (arr[i] % 2 == 0)even_arr[j++] = arr[i];
		//else odd_arr[k++] = arr[i];
		//(arr[i] % 2 == 0 ? even_arr[j++] : odd_arr[k++]) = arr[i];
		(arr[i] % 2 ? odd_arr[k++] : even_arr[j++]) = arr[i];
	}
	//4- Вывод резyльтата
	Print(even_arr, even_count);
	Print(odd_arr, odd_count);
	
	//5- удаление массива
	delete[] odd_arr;
	delete[] even_arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout<<arr[i]<<tab;
	}
	cout << endl;
}