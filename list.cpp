#include "list.h"
#include <typeinfo>
#include <typeindex>

list::list() = default;

void list::push_front(product * p)
{
	node* n = new node;
	n->p = p;
	if (head)
	{
		head->prev = n;
		n->next = head;
		head = n;
	}
	else
		head = tail = n;
}

void list::push_back(product* p)
{
	node* n = new node;
	n->p = p;
	if (tail)
	{
		tail->next = n;
		n->prev = tail;
		tail = n;
	}
	else
		head = tail = n;
}

void list::pop_front()
{
	if (!head)
		throw logic_error("List is empty\n");

	node* temp = head->next;
	delete head->p;
	delete head;
	head = temp;
}

void list::sort()
{
	if (!head)
		throw logic_error("List is empty\n");

	for (node* i = head; i; i = i->next)
		for (node* j = head; j->next; j = j->next)
			if (j->p->get_fatness() > j->next->p->get_fatness())
			{
				product* temp = j->next->p;
				j->next->p = j->p;
				j->p = temp;
			}
}

void list::print() const
{
	if (!head)
		throw logic_error("List is empty\n");
	
	for (node* i = head; i; i = i->next)
		cout << *(i->p);
}

void list::print_to_file(ofstream& s) const
{
	if (!head)
		throw logic_error("List is empty\n");

	for (node* i = head; i; i = i->next)
		s << *(i->p);
}

void list::print_by_fatness(unsigned border) const
{
	if (!head)
		throw logic_error("List is empty\n");

	for (node* i = head; i; i = i->next)
		if (i->p->get_fatness() <= border)
			cout << *(i->p);
}

void list::clear()
{
	if (!head)
		throw logic_error("List is empty\n");

	while (head)
	{
		node* temp = head->next;
		delete head->p;
		delete head;
		head = temp;
	}
	head = tail = nullptr;
}

list::~list()
{
	while (head)
	{
		node* temp = head->next;
		delete head->p;
		delete head;
		head = temp;
	}
}
