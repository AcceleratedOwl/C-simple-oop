#ifndef HEADER_4
#define HEADER_4

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class product
{
protected:
	unsigned fatness, price;
	string producer, brand_name;
public:
	product();
	product(unsigned f, unsigned p, string prod, string b);

	unsigned get_fatness() const;
	unsigned get_price() const;
	string get_producer() const;
	string get_brand_name() const;

	void set_fatness(unsigned f);
	void set_price(unsigned p);
	void set_producer(string p);
	void set_brand_name(string b);

	virtual void print() const;
	virtual void print_to_file(ofstream& s) const;
	virtual void load();
	virtual void load_from_file(ifstream& s);

	friend ofstream& operator <<(ofstream& s, const product& p);
	friend ostream& operator <<(ostream& s, const product& p);
	friend istream& operator >>(istream& s, product& p);
	friend ifstream& operator >>(ifstream& s, product& p);

	virtual ~product() = 0;
};
#endif