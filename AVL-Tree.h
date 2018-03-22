//AVL-Tree must satisfy three criteria
//Insertion of values
//Remove Values
//Shift for balance

template <typename T>
struct Node {
	Node *left;
	Node *right;
	T data;
	Node(Node *l = NULL, Node *r = NULL, T d = NULL):
		left(l),
		right(r),
		data(d){}
};

template <class T>
class AVL_Tree 
{
	public:
		AVL_Tree();
		void insert(T);
		void remove(T);
		void print();
		bool search(T);
	
	private:
		Node<T> *head;
		void n_insert(Node<T>*&, T);
		void n_print(Node<T> *);
		bool n_search(T, Node<T>*);
		Node<T>* rotateRight(Node<T>*);
		Node<T>* rotateLeft(Node<T>*);
		Node<T>* rotateRightLeft(Node<T>*);
		Node<T>* rotateLeftRight(Node<T>*);
		Node<T>* balance(Node<T>*);
		int difference(Node<T>*);
		int height(Node<T>*);
		int size;
};

template <class T>
AVL_Tree<T>::AVL_Tree() {
	head = NULL;
	size = 0;
};

template <class T>
void AVL_Tree<T>::insert(T data) {
	if(search(data)) return;
	n_insert(head, data);
	head = balance(head);
};

template <class T>
void AVL_Tree<T>::n_insert(Node<T>*& node, T data)
{
	if(node == NULL)
	{
		node = new Node<T>(NULL, NULL, data);
	} else if (data < node->data) {
		n_insert(node->left, data);
		node->left = balance(node->left);
	} else {
		n_insert(node->right, data);
		node->right = balance(node->right);
	}
};

template <class T>
void AVL_Tree<T>::remove(T data) 
{
	if (!search(data)) return;
}

template <class T>
void AVL_Tree<T>::print()
{
	if(!head) return;
	n_print(head);
};

template <class T>
void AVL_Tree<T>::n_print(Node<T> *node)
{
	if(!node) return;
	
	std::cout << node->data << std::endl;
	n_print(node->left);
	n_print(node->right);
};

template <class T>
bool AVL_Tree<T>::search(T data)
{
	if(!head) return false;
	else if (head->data == data) return true;
	n_search(data, head);
};

template <class T>
bool AVL_Tree<T>::n_search(T data, Node<T>* node)
{
	if(node == NULL) return false;
	else if(node->data == data) return true;
	else if(node->data <= data) n_search(data, node->right);
	else n_search(data, node->left);
};

template <class T>
Node<T>* AVL_Tree<T>::rotateRight(Node<T>* node)
{
	//Return the node resulting from right rotation
	Node<T>* newParent = node->left;
	Node<T>* branch = newParent->right;
	newParent->right = node;
	node->left = branch;
	return newParent;
};

template <class T>
Node<T>* AVL_Tree<T>::rotateLeft(Node<T>* node)
{
	//Return the node resulting from a left rotation
	Node<T>* newParent = node->right;
	Node<T>* branch = newParent->left;
	newParent->left = node;
	node->right = branch;
	return newParent;
};

template <class T>
Node<T>* AVL_Tree<T>::rotateRightLeft(Node<T>* node)
{
	Node<T>* rightNode = node->right;
	node->right = rotateRight(rightNode);
	return rotateLeft(node);
};

template <class T>
Node<T>* AVL_Tree<T>::rotateLeftRight(Node<T>* node)
{
	Node<T>* leftNode = node->left;
	node->left = rotateLeft(leftNode);
	return rotateRight(node);
};

//Checks and balances the subtree
template <class T>
Node<T>* AVL_Tree<T>::balance(Node<T>* node)
{
	int dif = difference(node);
	
	if (dif > 1) {
		if (difference(node->left) > 1) 
			return rotateRight(node);
		else
			return rotateLeftRight(node);
	}
	else if (dif < -1) {
		if (difference(node->right) < 0) 
			return rotateLeft(node);
		else
			return rotateRightLeft(node);
	}
	else
		return node;
};

//Returns the difference between hight of left and right subtrees
template <class T>
int AVL_Tree<T>::difference(Node<T>* node)
{
	return height(node->left) - height(node->right);
};

//Returns height
template <class T>
int AVL_Tree<T>::height(Node<T>* n)
{
	if(n == NULL) return 0;
	else {
		int heightLeft = height(n->left);
		int heightRight = height(n->right);
		if (heightLeft > heightRight)
			return heightLeft + 1;
		else 
			return heightRight + 1;
	}
};