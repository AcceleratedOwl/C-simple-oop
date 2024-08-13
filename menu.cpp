#include "menu.h"

void menu::print_menu() const
{
	system("cls");
	cout << "=================== Welcome ===================\n";
	cout << "|Please, input '1' to create milk's object    |\n";
	cout << "|Please, input '2' to create Sausage's object |\n";
	cout << "|Please, input '3' to show the list of goods  |\n";
	cout << "|Please, input '4' to remove first of goods   |\n";
	cout << "|Please, input '5' to remove all the goods    |\n";
	cout << "|Please, input '6' to save to the file        |\n";
	cout << "|Please, input '7' to load from the file      |\n";
	cout << "|Please, input '8' to sort goods              |\n";
	cout << "|Please, input '9' to do request              |\n";
	cout << "|Please, input '0' to exit the program        |\n";
	cout << "===============================================\n\n";
}

void menu::create_milk_product()
{
	print_menu();
	milk_product* m = new milk_product;
	cin >> *m;
	l.push_back(m);
	cout << "Successfully added\n";
}

void menu::create_sausage_product()
{
	print_menu();
	sausage_product* s = new sausage_product;
	cin >> *s;
	l.push_back(s);
	cout << "Successfully added\n";
}

void menu::print() const
{
	print_menu();
	try
	{
		l.print();
	}
	catch (logic_error e)
	{
		cout << e.what();
	}
}

void menu::remove_first()
{
	print_menu();
	try
	{
		l.pop_front();
	}
	catch (logic_error e)
	{
		cout << e.what();
	}
	cout << "Removed\n";
}

void menu::clear()
{
	print_menu();
	try
	{
		l.clear();
	}
	catch (logic_error e)
	{
		cout << e.what();
	}
	cout << "Cleared\n";
}

void menu::save_to_file() const
{
	print_menu();
	cout << "Input path: ";
	string path;
	cin >> path;
	ofstream s(path);
	try
	{
		l.print_to_file(s);
	}
	catch (logic_error e)
	{
		cout << e.what();
	}
	cout << "Saved\n";
}

void menu::load()
{
	print_menu();
	cout << "Input path: ";
	string path;
	cin >> path;
	ifstream s(path);
	if (!s)
		cout << "Wrong path\n";
	else
	{
		char c;
		do
		{
			s >> c;
			if (c == 'M')
			{
				milk_product* m = new milk_product;
				s >> *m;
				l.push_back(m);
			}
			else if (c == 'S')
			{
				sausage_product* s_ = new sausage_product;
				s >> *s_;
				l.push_back(s_);
			}
			c = ' ';
		} while (s);
		cout << "Loaded\n";
	}
}

void menu::sort()
{
	print_menu();
	try
	{
		l.sort();
	}
	catch (logic_error e)
	{
		cout << e.what();
	}
	cout << "Sorted\n";
}

void menu::request() const
{
	print_menu();
	unsigned fatness;
	cout << "Input fatness: ";
	cin >> fatness;
	try
	{
		l.print_by_fatness(fatness);
	}
	catch (logic_error e)
	{
		cout << e.what();
	}
}

menu& menu::get()
{
	static menu m;
	return m;
}

void menu::run()
{
	char c;
	print_menu();
	do
	{
		c = _getch();
		switch (c)
		{
		case '1':
			create_milk_product();
			break;
		case '2':
			create_sausage_product();
			break;
		case '3':
			print();
			break;
		case '4':
			remove_first();
			break;
		case '5':
			clear();
			break;
		case '6':
			save_to_file();
			break;
		case '7':
			load();
			break;
		case '8':
			sort();
			break;
		case '9':
			request();
			break;
		}
	} while (c != '0');
}