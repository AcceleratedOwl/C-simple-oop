#include "product.h"

product::product() : fatness(0), price(0) {}
product::product(unsigned f, unsigned p, string prod, string b) : fatness(f), price(p), producer(prod), brand_name(b) {}

unsigned product::get_fatness() const { return fatness; }
unsigned product::get_price() const { return price; }
string product::get_producer() const { return producer; }
string product::get_brand_name() const { return brand_name; }

void product::set_fatness(unsigned f) { fatness = f; }
void product::set_price(unsigned p) { price = p; }
void product::set_producer(string p) { producer = p; }
void product::set_brand_name(string b) { brand_name = b; }

void product::print() const
{
	cout << "Fatness: " << fatness << "\nBrand name: " << brand_name
		<< "\nProducer: " << producer << "\nPrice: " << price;
}

void product::print_to_file(ofstream& s) const
{
	s << fatness << '\n' << brand_name << '\n'
		<< producer << '\n' <<  price << '\n';
}

void product::load()
{
	cout << "Fatness: ";
	cin >> fatness;
	while (cin.fail())
	{
		std::cout << "Fatness must be digit!\nFatness: ";
		cin.clear();
		cin.ignore(1);
		cin >> fatness;
	}
	cout << "Brand name: ";
	cin.clear();
	cin.ignore(1);
	getline(cin, brand_name);
	cout << "Producer: ";
	getline(cin, producer);
	cout << "Price: ";
	cin >> price;
	while (cin.fail())
	{
		std::cout << "Price must be digit!\nPrice: ";
		cin.clear();
		cin.ignore(1);
		cin >> price;
	}
}

void product::load_from_file(ifstream& s)
{
	s >> fatness;
	s.clear();
	s.ignore(1);
	s >> brand_name;
	s >> producer;
	s >> price;
}

ofstream& operator <<(ofstream& s, const product& p)
{
	p.print_to_file(s);
	return s;
}
ostream& operator <<(ostream& s, const product& p)
{
	p.print();
	return s;
}
istream& operator >>(istream& s, product& p) 
{
	p.load();
	return s;
}
ifstream& operator >>(ifstream& s, product& p)
{
	p.load_from_file(s);
	return s;
}

product::~product() = default;