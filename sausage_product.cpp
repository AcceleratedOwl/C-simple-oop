#include "sausage_product.h"

sausage_product::sausage_product() = default;
sausage_product::sausage_product(unsigned f, unsigned p, string prod, string b, unsigned m, string c)
	:product::product(f,p,prod,b), meat_precent(m), country_of_origin(c) {}

unsigned sausage_product::get_meat_precent() { return meat_precent; }
string sausage_product::get_country_of_origin() { return country_of_origin; }
void sausage_product::set_meat_precent(unsigned m) { meat_precent = m; }
void sausage_product::set_country_of_origin(string c) { country_of_origin = c; }

void sausage_product::print() const 
{
	product::print();
	cout << "\nMeat precent: " << meat_precent << "\nCountry of origin: " << country_of_origin << "\n\n";
}

void sausage_product::print_to_file(ofstream& s) const
{
	s << "S\n";
	product::print_to_file(s);
	s << meat_precent << '\n' << country_of_origin << '\n';
}

void sausage_product::load()
{
	product::load();
	cout << "Meat precent: ";
	cin >> meat_precent;
	while (cin.fail())
	{
		std::cout << "Meat precent must be digit!\nMeat precent: ";
		cin.clear();
		cin.ignore(1);
		cin >> meat_precent;
	}
	cout << "Country of origin: ";
	cin >> country_of_origin;
}

void sausage_product::load_from_file(ifstream& s)
{
	product::load_from_file(s);
	s >> meat_precent;
	s >> country_of_origin;
}

sausage_product::~sausage_product() = default;