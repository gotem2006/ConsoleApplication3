
#include <iostream>  
#include <string>
#include<limits>
#include<locale>
#include <windows.h>
using namespace std;
struct employee
{
	long nomer;
	char name[100];
	
};
employee getdata()
{
	employee sf;
	cout << "Введите номер сотрудника:";
	cin >> sf.nomer;
	cin.get();
	cout << "Введите имя сотрудника:";
	cin.getline (sf.name,100);
	
	
	return sf;
}
void putdata(employee fr[], int size)
{
	for (int i = 0; i < size; i++) {
		cout << "Номер " << i + 1 << " сотрудника: " << fr[i].nomer << endl;
		cout << "Имя: " << fr[i].name << endl;
	}
}

int maxint(int number[], int b)
{
	int max = 0, index = 0;

	for (int i = 0; i < b; ++i)
	{
		if (number[i] > max)
		{
			max = number[i];
			index = i;
		}
	}
	return index;
}
struct fraction
{
	int chislitel;
	int znamenatel;
	int nod;
};

fraction sr(fraction* arr, int sz)
{
	fraction sr = { arr[0].chislitel, arr[0].znamenatel };
	int l = 1;
	do
	{
		sr.chislitel = sr.chislitel * arr[l].znamenatel + sr.znamenatel * arr[l].chislitel;
		sr.znamenatel *= arr[l].znamenatel;
		l += 1;
	} while (l != (sz));
	sr.znamenatel = sr.znamenatel * sz;
	return sr;

}

void reversit(string& str)
{
	
	string temp = "";
	for (auto& s : str)
	{
		temp = s + temp;
	}
	cout << "Перевернутая строка: " << temp << endl;
	str.clear();
	str = temp;
}
struct dist
{
	int funt;
	int dime;
};
dist srpyt(dist pyt[], int const shizik)
{
	dist srzpyt = {pyt[0].dime,pyt[0].funt};
	for (int i = 1; i < shizik + 1; i++)
	{
		srzpyt.funt = srzpyt.funt + pyt[i].funt;
		srzpyt.dime = srzpyt.dime + pyt[i].funt;
	}
	if (srzpyt.dime > 12)
	{
		do
		{
			srzpyt.dime = srzpyt.dime - 12;
			srzpyt.funt = srzpyt.funt + 1;
		}while (srzpyt.dime < 12);
	}
	srzpyt.funt = srzpyt.funt / 5;
	srzpyt.dime = srzpyt.dime / 5;
	return srzpyt;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int a;
	cout << "Введите номер задания:";
	cin >> a;
	cin.get();
	switch (a)
	{
	case 1:
	{
		int const size1 = 100;
		fraction array[size1];
		int p;
		char slash5;
		string choice5;
		p = 0;
		do
		{
			cout << "Введите значение дроби:";
			cin >> array[p].chislitel >> slash5 >> array[p].znamenatel;
			cout << "Продолжить(y/n):";
			cin >> choice5;
			p += 1;
		} while (choice5 == "y");
		fraction srednechok;
		srednechok = sr(array, p);
		if (srednechok.chislitel < srednechok.znamenatel) {
			for (int i = 1; i < srednechok.znamenatel; i++) {
				if ((srednechok.chislitel % i == 0) && (srednechok.znamenatel % i == 0)) {
					srednechok.nod = i;
				}
			}
		}
		else {
			for (int i = 1; i < srednechok.chislitel; i++) {
				if ((srednechok.chislitel % i == 0) && (srednechok.znamenatel % i == 0)) {
					srednechok.nod = i;
				}
			}
		}
		if (srednechok.chislitel % srednechok.znamenatel == 0) {
			cout << "Среднее значение: " << srednechok.chislitel / srednechok.znamenatel << endl;
		}
		else {
			cout << "Среднее значение: " << srednechok.chislitel / srednechok.nod << "/" << srednechok.znamenatel / srednechok.nod << endl;
		}
		return main();
	}

		

	case 2:
	{
		char otvet;
		int n = 0;
		int const size = 100;
		int numbers[size];
	metka1:
		cout << "Введите число:";
		cin >> numbers[n];
		cout << "Продолжить(y/n):";
		cin >> otvet;
		if (otvet == 'y')
		{
			n += 1;
			goto metka1;

		}
		else
		{
			n += 1;
			cout << "Наибольший элемент и его индекс:" << numbers[maxint(numbers, n)] << ";" << maxint(numbers, n) << endl;
			return main();
		}
	}
	case 3:
	{
		cout << "Введите предложение:";
		string stroka;
		
		getline(cin, stroka);
		reversit(stroka);
		return main();
		
	}
	case 4:
	{
		employee fr[3];
		cout << "Введите данные о трех сотрудниках:" << endl;
		for (int i = 0; i < 3; i++)
		{
			fr[i] = getdata();
		}
		putdata(fr, 3);
		return main();
	}
	case 5:
	{
		int const sizik = 4;
		dist srpet[sizik];
		char stop;
		for (int i = 0; i < sizik + 1; i++)
		{
			cout << "Введите дистанцию:";
			cin >> srpet[i].funt >> stop >> srpet[i].dime;
		}
		dist srednechok2;
		srednechok2 = srpyt(srpet, sizik);
		cout << "Среднее значение пути:" << srednechok2.funt << "." << srednechok2.dime << endl;
		return main();
	}
	return 0;
	}

	
}

