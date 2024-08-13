#ifndef HEADER_1
#define HEADER_1

#include "product.h"

class list
{
private:
	struct node
	{
		product* p = nullptr;
		node* prev = nullptr, * next = nullptr;
	};
	node* head = nullptr, * tail = nullptr;
public:
	list();

	void push_front(product* p);

	void push_back(product* p);

	void pop_front();

	void sort();

	void print() const;

	void print_to_file(ofstream& s) const;
	 
	void print_by_fatness(unsigned border) const;

	void clear();

	~list();
};

#endif