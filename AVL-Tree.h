//AVL-Tree must satisfy three criteria
//Insertion of values
//Remove Values
//Shift for balance
template <class T>
class AVL_Tree 
{
	public:
		AVL_Tree();
		void insert(T);
	
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
		int size;
};

template <class T>
AVL_Tree<T>::AVL_Tree() {
	head = NULL;
	size = 0;
};

template <class T>
void AVL_Tree<T>::insert(T data) {
	if (!head) {
		head = new Node(NULL, NULL, NULL, data);
		return;
	}
	Node tmp = head;
	while(tmp->left != NULL && tmp->right != NULL) {
		if(tmp->data < data && tmp->right != NULL) tmp = tmp->right;
		else tmp = tmp->left;
	}
	
	if(data >= tmp->data) tmp->right = new Node(tmp, NULL, NULL, data);
	else tmp->left = new Node(tmp, NULL, NULL, data);
};