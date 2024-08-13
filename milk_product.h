#ifndef HEADER_3
#define HEADER_3

#include "product.h"

class milk_product : public product
{
private:
	string type_of_milk;
public:
	milk_product();
	milk_product(unsigned f, unsigned p, string prod, string b, string t);

	string get_type_of_milk();
	void set_type_of_milk(string t);

	void print() const override;
	void print_to_file(ofstream& s) const override;
	void load() override;
	void load_from_file(ifstream& s) override;

	~milk_product() override;
};

#endif