#ifndef HEADER_5
#define HEADER_5

#include "product.h"

class sausage_product : public product
{
private:
	unsigned meat_precent;
	string country_of_origin;
public:
	sausage_product();
	sausage_product(unsigned f, unsigned p, string prod, string b, unsigned m, string c);

	unsigned get_meat_precent();
	string get_country_of_origin();
	void set_meat_precent(unsigned m);
	void set_country_of_origin(string c);

	void print() const override;
	void print_to_file(ofstream& s) const override;
	void load() override;
	void load_from_file(ifstream& s) override;

	~sausage_product() override;
};
#endif