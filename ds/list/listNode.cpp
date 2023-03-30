#include "axc.cpp"


_AXC_BEGIN

template <
	class Vty_
>
struct _List_node {
public:
    using value_type      = Vty_;
    using _Nodeptr        = _List_node<Vty_>*;           


    explicit _List_node (
    	const value_type& value,
    	_Nodeptr prev,
    	_Nodeptr next
    ) noexcept :
    	_Myval(value),
    	_Prev(prev),
    	_Next(next)
    {}

    explicit _List_node (
    	value_type&& value,
    	_Nodeptr prev,
    	_Nodeptr next
    ) noexcept :
    	_Myval(move(value)), // CHECK THIS
    	_Prev(prev),
    	_Next(next)
    {}

    _List_node (const _List_node&) = delete;
    
    _List_node& operator= (const _List_node&) = delete;

    ~_List_node() {
    	_Myval.~value_type(); // calling destructor explicitly is bad 
    	_Next = nullptr;
    	_Prev = nullptr;
    }

    // void DEALLOCATE_ (_Nodeptr ptr) noexcept {
    // 	delete ptr->_Next; ptr->_Next = nullptr;
    // 	delete ptr->_Prev; ptr->_Prev = nullptr;

    // 	::operator delete(ptr);
    // } 

    // void Freenode_ (_Nodeptr ptr) noexcept { // destroy all members in ptr and deallocate memory
    // 	_AXC destroy_(_AXC addressof(ptr->_Myval));
    // 	DEALLOCATE_(ptr);
    // }

    // void Free_non_head_ (_Nodeptr head) noexcept { // free a list starting at head 
    // 	head->_Prev->_Next = nullptr;

    // 	auto Pnode = head->_Next;
    // 	for (_Nodeptr Pnext; Pnode != nullptr; Pnode = Pnext) {
    // 		Pnext = Pnode->_Next;
    // 		Freenode_(Pnode);
    // 	}
    // }

    template <class Ty_>
    friend std::ostream& operator<< (std::ostream& output, const _List_node<Ty_>& node);
    void get() {
    	std::cout << this << "\n" << &this;
    }

	value_type _Myval; // the stored value, unused if head
	_Nodeptr   _Prev;  // successor node, or first element if head
	_Nodeptr   _Next;  // the stored value, unused if head
};



template <
	class Vty_
>
std::ostream& operator<< (std::ostream& output, const _List_node<Vty_>& node) {
	output << node;

	return output;
}

_AXC_END


// int main() {
// 	auto node1 = static_cast<_List_node<int>*>(::operator new(sizeof(_List_node<int>)));
// 	auto node2 = static_cast<_List_node<int>*>(::operator new(sizeof(_List_node<int>)));
	
// 	node1->_Next = node2;

// 	// std::cout << node1->_Next << '\n';
	
// 	node1->get();

// 	// _List_node<int> node(2542, node1, node2);


// 	operator delete(node1);
// 	// operator delete(node1);
// 	operator delete(node2);
// }





































// int main() {


// 	int x = 32;
// 	int* px = &x;
// 	std::cout << px << "\n";

// 	int* ptr = new int(32);
// 	std::cout << *ptr << '\n';

// 	auto node1 = new Node<int>(1);
// 	auto node2 = new Node<int>(2);

// 	node1->setNext(node2);
// 	node2->setPrev(node1);

// 	std::cout << *node1 << " " << *node2;

// 	swap(node1, node2);

// 	std::cout << '\n' << *node1 << " " << *node2;
// }