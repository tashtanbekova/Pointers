#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

int** Allocate(const int rows, const int cols);
void Clear(int**arr, const int rows,const int cols);

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back (int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);

int* pop_back(int arr[], int& n);
//int* pop_front(int arr[], int& n);


void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef DYNAMIC_MEMORY_1 
	int n;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	//delete[]buffer;
	delete[]arr;

	arr = pop_back(arr, n);
	Print(arr, n);

	//arr = pop_front(arr, n);
	//Print(arr, n);  
#endif // DYNAMIC_MEMORY_1 

#ifdef DYNAMIC_MEMORY_2
	int rows;
	int cols;
	cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ���������� ��������� �����: "; cin >> cols;

	int** arr = Allocate (rows, cols);
    FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	
#endif DYNAMIC_MEMORY_2
}

int** Allocate(const int rows, const int cols)
{
	//1 C������ ������ ����������
	int** arr = new int* [rows];
	//2 �������� ������ ��� ������
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr;
}
void Clear(int** arr, const int rows,const int cols)
{
	//1 ������� ������� ������
	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}//2������� ������ ����������
	for (int i = 0; i < cols; i++)
	{
		delete[]arr;
	}
}

void FillRand(int arr[], const int n)
{
	//��������e � ��������� ������� ����� ���������� ����������
	//� �������� �������������;
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void FillRand (int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int arr[], const int n)
{
	//��������� � ��������� ������� ����� �������� �������������� - [];
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
void Print(int** arr, const int rows, const int cols)
{

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl;
}
int* push_back (int arr[], int& n, int value)
{
	//1 ������� ��������� ������:
	int* buffer = new int[n + 1];
	//2 �������� �������� �� �������� ������:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3 ������� �������� ������:
	delete[]arr;
	//4 ��������� ����� ��������� ������� ������� ������ �������
	arr = buffer;
	//5 ������ ���� ����� � ���� ������� ���������� ��������� �����,
	//  ���� ����� �������� ��������:
	arr[n] = value;
	n++;
	//Print(arr, n);
	return arr;
}
int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[]arr;
	return buffer;
}
//int* pop_front(int arr[], int& n)



