#include <iostream>
using namespace std;

//1
//class Fraction
//{
//public:
//	int numerator; 
//	int denominator;
//	Fraction()
//	{
//		cout << "Введите числитель: ";
//		cin >> numerator;
//		cout << "Введите знаминатель: ";
//		cin >> denominator;
//	}
//	Fraction(int Numerator, int Denominator)
//	{
//		numerator = Numerator;
//		denominator = Denominator;
//	}
//	void Assign(int Numerator, int Denominator)
//	{
//		numerator = Numerator;
//		denominator = Denominator;
//	}
//	void Print()
//	{
//		cout << numerator << "/" << denominator << "\n";
//	}
//	void Mul(Fraction a)
//	{
//		Assign(numerator * a.numerator, denominator * a.denominator);
//	}
//	void Div(Fraction a)
//	{
//		Assign(numerator * a.denominator, denominator * a.numerator);
//	}
//	void Sum(Fraction a)
//	{
//		Assign(numerator * a.denominator + denominator * a.numerator, denominator * a.denominator);
//	}
//	void Sub(Fraction a)
//	{
//		Assign(numerator * a.denominator - denominator * a.numerator, denominator * a.denominator);
//	}
//};
//int main()
//{
//	Fraction f1;
//	Fraction f2;
//	f1.Print();
//	f2.Print();
//
//	f1.Mul(f2);
//	f1.Print();
//
//	f1.Div(f2);
//	f1.Print();
//
//	f1.Sum(f2);
//	f1.Print();
//
//	f1.Sub(f2);
//	f1.Print();
//}







class Contact
{
	int HomeNumber;
	int WorkNumber;
	int OwnNumber;
	char* Name;
	char* LastName;
	char* SurName;
public:
	Contact()
	{
		Name = nullptr;
		LastName = nullptr;
		SurName = nullptr;
		HomeNumber = 0;
		WorkNumber = 0;
		OwnNumber = 0;
	}
	Contact(int homen, int workn, int ownn)
	{
		SetNum(homen, workn, ownn);
	}
	Contact(const char* name, const char* lastname, const char* surname)
	{
		SetFIO(name, lastname, surname);
	}
	Contact(const char* name, const char* lastname, const char* surname, int homen, int workn, int ownn)
	{
		SetFIO(name, lastname, surname);
		SetNum(homen, workn, ownn);
	}
	inline void SetNum(int homen, int workn, int ownn)
	{
		if (homen < 0)
		{
			cout << "Error";
		}
		else
		{
			HomeNumber = homen;
		}

		if (workn < 0)
		{
			cout << "Error";
		}
		else
		{
			WorkNumber = workn;
		}
		if (ownn < 0)
		{
			cout << "Error";
		}
		else
		{
			OwnNumber = ownn;
		}
	}
	inline void SetFIO(const char* name, const char* lastname, const char* surname)
	{
		if (Name == nullptr)
		{
			delete[] Name;
		}
		Name = new char[strlen(name) + 1];
		strcpy_s(Name, strlen(name) + 1, name);
		if (LastName == nullptr)
		{
			delete[] LastName;
		}
		LastName = new char[strlen(lastname) + 1];
		strcpy_s(LastName, strlen(lastname) + 1, lastname);
		if (SurName == nullptr)
		{
			delete[] SurName;
		}
		SurName = new char[strlen(surname) + 1];
		strcpy_s(SurName, strlen(surname) + 1, surname);
	}
	void OutPut()
	{
			cout << "\nФИО: ";
			if (LastName == nullptr) cout << " ";
			else cout << LastName << " ";

			if (Name == nullptr) cout << " ";
			else cout << Name << " ";

			if (SurName == nullptr) cout << " ";
			else cout << SurName << " " << endl;

			cout << "Домашний номер: " << HomeNumber << endl;
			cout << "Рабочий номер: " << WorkNumber << endl;
			cout << "Личный номер: " << OwnNumber << endl;
	}

	
	~Contact()
	{
		if (Name == nullptr)
		{
			delete[] Name;
		}
		if (LastName == nullptr)
		{
			delete[] LastName;
		}
		if (SurName == nullptr)
		{
			delete[] SurName;
		}
	}
};


Contact* Add(Contact* list, int size, Contact contact)
{
	Contact* result = new Contact[size + 1];
	for (int i = 0; i < size; i++)
	{
		result[i] = list[i];
	}
	result[size] = contact;
	delete[] list;
	return result;
}

Contact* Delete(Contact* list, int size, int pos)
{
	if (pos < 0 || pos >= size)
	{
		cout << "Error";
		return list;
	}
	Contact* result = new Contact[size - 1];
	for (int i = 0; i < pos; i++)
	{
		result[i] = list[i];
	}
	for (int i = pos; i < size - 1; i++)
	{
		result[i] = list[i + 1];
	}
	delete[] list;
	return result;
}
void Print(Contact* list, int size)
{
	for (int i = 0; i < size; i++)
	{
		list[i].OutPut();
	}
}


int main()
{
	setlocale(LC_ALL, "");
	int homen;
	int workn;
	int ownn;
	int size = 0;
	char name[100];
	char lastname[100];
	char surname[100];
	cout << "Введите Номера телефона" << endl;
	cout << "Домашный: ";
	cin >> homen;
	cout << "Рабочий: ";
	cin >> workn;
	cout << "Личный: ";
	cin >> ownn;
	cout << "ФИО" << endl;
	cout << "Фамилия: ";
	cin >> lastname;
	cout << "Имя: ";
	cin >> name;
	cout << "Отчество: ";
	cin >> surname;
	Contact* mas = new Contact[size];
	Contact obj(name, lastname, surname, homen, workn, ownn);
	mas = Add(mas, size, obj);
	size++;
	Contact obj1(name, lastname, surname, homen, workn, ownn);
	mas = Add(mas, size, obj);
	size++;
	Contact obj2(name, lastname, surname, homen, workn, ownn);
	mas = Add(mas, size, obj);
	size++;
	Print(mas, size);
	mas = Delete(mas, size , 0);
	size--;
	Print(mas, size);
	obj.~Contact(); 
	obj1.~Contact();
	obj2.~Contact();
	delete[] mas;
}