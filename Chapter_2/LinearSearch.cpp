// linear search in Singly Linked-list
// 2015-01-25
#include <iostream>

using namespace std;

template <class Iterator, class T>
Iterator find1(Iterator first, Iterator last, const T& value)
{
	while(first != last && *first != value) {
		++first;
	}
	return first;
}

struct int_node {
	int val;
	int_node *next;
	int_node(int v, int_node *p): val(v), next(p) { }
};

template <class Node>
struct node_wrap {
	Node *ptr;
	node_wrap(Node *p = 0): ptr(p) { }

	Node& operator*() const { return *ptr; }
	Node* operator->() const { return ptr; }

	node_wrap& operator++() { ptr = ptr->next; return *this; }
	// post-increment operator shouldn't return a lvalue(same as int), so it cannot be a reference
	node_wrap operator++(int) { node_wrap tmp = *this; ++*this; return tmp; }

	bool operator==(const node_wrap& rhs) const { return ptr == rhs.ptr; }
	bool operator!=(const node_wrap& rhs) const { return ptr != rhs.ptr; }

};

bool operator!=(const int_node& node, int n)
{
	return node.val != n; 
}

int main()
{
	int_node *list_head = new int_node(1, 0);
	list_head->next = new int_node(2, 0);
	list_head->next->next = new int_node(3, 0);
	list_head->next->next->next = new int_node(4, 0);

	node_wrap<int_node> ret = find1(node_wrap<int_node>(list_head), node_wrap<int_node>(), 2);
	if(ret == node_wrap<int_node>())
		cout << "no found" << endl;
	else
		cout << ret->val << endl;
}













