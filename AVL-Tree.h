//AVL-Tree must satisfy three criteria
//Insertion of values
//Remove Values
//Shift for balance
template <class T>
class AVL_Tree 
{
	public:
	
	
	
	
	
	private:
	struct Node {
		Node *parent;
		Node *left;
		Node *right;
		T data;
		Node(Node *p = NULL, Node *l = NULL, Node *r = NULL, T d = NULL):
			parent(p),
			left(l),
			right(r),
			data(d){}
	};
	
	Node *head;
};