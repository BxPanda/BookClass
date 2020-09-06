// Completed by Khodonovich Semen 08.05.2020 , 15:42
#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
#include<fstream>
#include"Book.h"

using namespace std;


bool pred(Book b1, Book b2)
{
	if (b1.GetAutor() == b2.GetAutor())
	{
		return b1.GetTitle() < b2.GetTitle();
	}
	else
	{
		return b1.GetAutor() < b2.GetAutor();
	}

}

void SortByAutor(vector<Book>& b)
{
	sort(b.begin(), b.end(), pred);
	cout << "Sorted by Author : " << endl << endl;
	for_each(b.begin(), b.end(), [](Book&b)
	{
			b.Print();
			cout << "---------------------------------------------------" << endl;
	});
}

void CountYear(vector<Book>& b,unsigned int f,unsigned int k)
{
	int count = 0;
	Book last("last", "last", "last", 0, 0, 0); // Тому що в діапазоні [ ; )
	b.push_back(last);
	for_each(b.begin(), b.end(), [&f, &k,&count](Book& el)
	{
			if (el.GetYear() >= f && el.GetYear() <= k)
			{
				count++;
			}
	});
	b.pop_back(); // Видаляю те що добавив на початку 
	cout << endl << "Amount of books writted in period " << f << "-" << k << "  : " << count << endl << endl;
	cout << "---------------------------------------------------" << endl;
}



void Move_to_new(vector<Book>& b, vector<Book>& b2)
{
	Book last("last","last","last",0,0,0); // Тому що в діапазоні [ ; )
	b.push_back(last);
	string Name;
	string Surname;
	cout << "Input name of author to move in new container : ";
	cin >> Name;
	cout << "Input surname of author to move in new container : ";
	cin >> Surname;
	cout << endl;
	string Autor = Name + Surname;
	int count = 0;
	for_each(b.begin(), b.end(), [&Autor,&b2,&b,&count](Book&el)
	{
			if (el.GetAutor() == Autor)
			{
				count++;
				b2.push_back(el);
			}
	});
	b.pop_back(); // Видаляю те що добавив на початку 
	if (count > 0)
	{
		cout << "Moved to new container : " << endl << endl;
		for (auto el : b2)
		{
			el.Print();
			cout << "---------------------------------------------------" << endl;
		}
	}
	else
	{
		cout << "Author not found !" << endl << endl;
		cout << "Input again ! " << endl << endl;
		Move_to_new(b, b2);
	}
	
}

void FindMax(vector<Book>& b)
{
	vector<Book>t_max;
	vector<Book>b_copy;
	copy(b.begin(), b.end(), inserter(b_copy, b_copy.end()));
    auto max = max_element(b_copy.begin(), b_copy.end());
	Book maxx = *max;
    t_max.push_back(maxx);
	b_copy.erase(max);
	
	for_each(b_copy.begin(), b_copy.end(), [&maxx,&t_max](Book&el)
	{
			if (el.GetPages() == maxx.GetPages())
			{
				t_max.push_back(el);
			}
	});

	cout << "All books with the biggest amount of pages : " << endl << endl;
	for (auto el : t_max)
	{
		el.Print();
		cout << "---------------------------------------------------" << endl;
	}
}

void GeneralMoney(vector<Book>& b)
{
	double sum = 0;
	for_each(b.begin(), b.end(), [&sum](Book& el)
	{
			sum += el.GetPrice();
	});
	cout << endl << "General worth of books : " << sum << "$" << endl;
	cout << "---------------------------------------------------" << endl;
}

void IncreasePerc(vector<Book>& b,double perc)
{
	vector<Book>new_vector;
	for_each(b.begin(), b.end(), [&perc,&new_vector](Book&el)
	{
			double price = el.GetPrice() + (el.GetPrice() * (perc / 100));
			el.SetPrice(price);
			new_vector.push_back(el);
	});
	b.clear();
	copy(new_vector.begin(), new_vector.end(), inserter(b, b.end()));
	cout << "Increased by " << perc << "%  : " << endl << endl;
	for (auto el : b)
	{
		el.Print();
		cout << "---------------------------------------------------" << endl;
	}

}

int main()
{
	ifstream ifs("Text.txt");
	vector<Book>v1;
	copy(istream_iterator<Book>(ifs), istream_iterator<Book>(), inserter(v1, v1.end()));

	SortByAutor(v1);

	CountYear(v1, 2017, 2021);

	vector<Book>v2;
	Move_to_new(v1, v2); // Переміщаю в новий контейнер , якщо автор знайдений
	
	FindMax(v1);

	GeneralMoney(v1);

	IncreasePerc(v1, 100);

	GeneralMoney(v1);


	return 0;
}