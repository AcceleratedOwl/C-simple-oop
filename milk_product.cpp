#include "milk_product.h"

milk_product::milk_product() = default;
milk_product::milk_product(unsigned f, unsigned p, string prod, string b, string t)
	:product::product(f,p,prod,b), type_of_milk(t) {}

string milk_product::get_type_of_milk() { return type_of_milk; }
void milk_product::set_type_of_milk(string t) { type_of_milk = t; }

void milk_product::print() const
{
	product::print();
	cout << "\nType of milk: " << type_of_milk << "\n\n";
}

void milk_product::print_to_file(ofstream& s) const
{
	s << "M\n";
	product::print_to_file(s);
	s << type_of_milk << '\n';
}

void milk_product::load()
{
	product::load();
	cout << "Type of milk: ";
	cin >> type_of_milk;
}

void milk_product::load_from_file(ifstream& s)
{
	product::load_from_file(s);
	s >> type_of_milk;
}

milk_product::~milk_product() = default;