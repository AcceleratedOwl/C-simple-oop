#ifndef HEADER_2
#define HEADER_2

#include "list.h"
#include "milk_product.h"
#include "sausage_product.h"
#include <conio.h>

class menu
{
private:
	menu() = default;
	void print_menu() const;
	void create_milk_product();
	void create_sausage_product();
	void print() const;
	void remove_first();
	void clear();
	void save_to_file() const;
	void load();
	void sort();
	void request() const;
	list l;
public:
	static menu& get();
	void run();
};
#endif