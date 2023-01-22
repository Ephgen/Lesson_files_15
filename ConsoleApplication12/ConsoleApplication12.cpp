#include <iostream>
#include <windows.h>
#include <fstream>
#include <string> 

using namespace std;

struct item
{
	char title[20];
	unsigned int qty;
	float price;
};
void dobavlenie(item* myshop, int &i);
void prosmotr(item *myshop,int &i);
int main()
{
	srand(time(NULL));
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//string line;
	//ifstream in("C:\\ps\\mydata.txt");
	//if (in.is_open())
	//{
	//	while (getline(in, line))  // in это как переменная
	//		cout << line << endl;
	//}
	//else
	//	cout << " Нет";
	//in.close();       // это обязательно

	//ofstream out;    //поток для записи
	//out.open("C:\\ps\\mydata.txt", ios::app);   // открываем или создаем файл для записи, если ios::app то файл не пересоздается а дополняется
	//if(out.is_open)
	//{
	//	cout << " Hello world!" << endl;
	//}
	//out.close();


	//const int size = 5;
	//int arr[size];
	//for (int i = 0; i < size; i++) {
	//	arr[i] = rand() % (10 - 1) + 1;
	//}
	//for (int i = 0; i < size; i++) {
	//	for (int j = size - 1; j > i; j--) {
	//		if (arr[i] < arr[j])
	//			swap(arr[i], arr[j]);
	//	}
	//}
	//ofstream out;
	//out.open("C:\\ps\\mydata.txt", ios::app);
	//if (out.is_open())
	//{
	//	for (int i = 0; i < size; i++) {
	//		out << arr[i] << endl;
	//	}
	//}
	//out.close();

	//string line;
	//ifstream in("C:\\ps\\mydata.txt");
	//if (in.is_open())
	//{
	//	while (getline(in, line))  // in это как переменная
	//		cout << line << endl;
	//}
	//else
	//	cout << " Нет";
	//in.close(); 


	//Второй способ работы с файлами
	//const int n = 5;
	//int arr[n];
	//FILE* out;
	//const char* path = "C:\\ps\\outfile.txt";
	//for (int i = 0; i < n; i++) {
	//	arr[i] = rand()%  (50 - (-20)) + (-20);
	//}
	//if ((fopen_s(&out, path, "w")) != NULL)
	//	cout << " File could not be created";
	//else
	//{
	//	for (int i = 0;i < n; i++) {
	//		fprintf(out, "%1d", arr[i]);    ///Записываем в файл в определенном формате(%1d ) из массива
	//		fprintf(out, "\n");
	//	}
	//	fclose(out);
	//}
 //
	//float a;
	//if ((fopen_s(&out, path, "r")) != 0)
	//	cout << " File could not be created";
	//else
	//{
	//	while (!feof(out))   // Пока файд не закончиться
	//	{
	//		fscanf_s(out, "%f ", &a);
	//		if (a > 0)
	//		{
	//			cout << a;
	//			cout << endl;
	//		}
	//	}
	//	fclose(out);
	//}

	int i = 0;
	FILE* in;
	item myshop[10];
	const char* path = "C:\\ps\\data.txt";
	if (fopen_s(&in, path, "r") != NULL)
		cout << " File could not be created.";
	else
	{
		while (!feof(in))
		{
			fscanf_s(in, "%s ", myshop[i].title, sizeof(myshop[i].title));
			fscanf_s(in, "%u ", &myshop[i].qty, sizeof(myshop[i].qty));
			fscanf_s(in, "%f ", &myshop[i].price, sizeof(myshop[i].price));
			cout << myshop[i].title << " "
				<< myshop[i].qty << " "
				<< myshop[i].price << endl;
			i++;
		}
		fclose(in);
	}
	
	int vihod;
	
	do
	{
		cout << " \n Будете добавлять какие-то товары?\n 1 - да. 0 - нет.\n 2 - просмотр.\n";
		cin >> vihod;
		if (vihod == 1)
		dobavlenie(myshop, i);		
		if (vihod == 2)
			prosmotr(myshop,i);
	} while (vihod != 0);
	
}

void dobavlenie(item* myshop, int& i)
{
	FILE* in;
	const char* path = "C:\\ps\\data.txt";
	fopen_s(&in, path, "a");
	cout << " Введите новый продукт: \n";
	cin >> myshop[i].title;
	cout << " Введите кол-во: \n";
	cin >> myshop[i].qty;
	cout << " Введите цену: \n";
	cin >> myshop[i].price;
	
	fprintf(in, "%s ", myshop[i].title);    ///Записываем в файл в определенном формате(%1d ) из массива
	fprintf(in, "%u ", myshop[i].qty);
	fprintf(in, "%f ", myshop[i].price);
	fprintf(in, "\n");
	fclose(in);
i++;
}
void prosmotr(item* myshop, int& i)
{
	for (int j = 0; j < i; j++) {
		cout << myshop[j].title << " "
			<< myshop[j].qty << " "
			<< myshop[j].price << endl;
	}
}