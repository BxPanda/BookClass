#include<string>
#include<iostream>

#pragma once

using namespace std;

class Book
{
protected:
	string Title;
	string Name;
	string Surname;
	unsigned int Pages;
	unsigned int Year;
	double Price;
public:
	Book() :Title("-"), Name("-"), Surname("-"), Pages(0), Year(0), Price(0) {}
	Book(string t, string n, string s, unsigned int p, unsigned int y, double P) :Title(t), Name(n), Surname(s), Pages(p), Year(y), Price(P) {}
	Book(const Book& b) :Title(b.Title), Name(b.Name), Surname(b.Surname), Pages(b.Pages), Year(b.Year), Price(b.Price) {}

	friend ostream& operator<<(ostream& os, const Book& b)
	{
		os << b.Title << " " << b.Name << " " << b.Surname << " " << b.Pages << " " << b.Year << " " << b.Price << endl;
		return os;
	}
	friend istream& operator>>(istream& is, Book& b)
	{
		is >> b.Title;
		is >> b.Name;
		is >> b.Surname;
		is >> b.Pages;
		is >> b.Year;
		is >> b.Price;
		return is;
	}
	void Print()
	{
		cout << "Title of book : " << Title << endl;
		cout << "Autor : " << Name << " " << Surname << endl;
		cout << "Amount of pages : " << Pages << endl;
		cout << "Year : " << Year << "p." << endl;
		cout << "Price : " << Price << "$" << endl;
	}
	string GetTitle()
	{
		return Title;
	}
	string GetAutor()
	{
		string Autor = Name + Surname;
		return Autor;
	}
	unsigned int GetPages()
	{
		return Pages;
	}
	unsigned int GetYear()
	{
		return Year;
	}
	double GetPrice()
	{
		return Price;
	}
	void SetPrice(double price)
	{
		Price = price;
	}

	friend bool operator == (Book b1, Book b2)
	{
		return b1.GetPages() == b2.GetPages();
	}
	friend bool operator != (Book b1, Book b2)
	{
		return !(b1.GetPages() == b2.GetPages());
	}
	friend bool operator <(Book b1, Book b2)
	{
		return b1.GetPages() < b2.GetPages();
	}
	friend bool operator >(Book b1, Book b2)
	{
		return b1.GetPages() > b2.GetPages();
	}
};


