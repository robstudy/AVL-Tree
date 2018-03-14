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
		void print();
		bool search(T);
	
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
		void n_print(Node *);
		bool n_search(T, Node*);
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
	Node *tmp = head;
	while(tmp->left != NULL && tmp->right != NULL) {
		if(tmp->data < data && tmp->right != NULL) tmp = tmp->right;
		else tmp = tmp->left;
	}
	
	if(data >= tmp->data) tmp->right = new Node(tmp, NULL, NULL, data);
	else tmp->left = new Node(tmp, NULL, NULL, data);
};

template <class T>
void AVL_Tree<T>::print()
{
	if(!head) return;
	n_print(head);
};

template <class T>
void AVL_Tree<T>::n_print(Node *node)
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
bool AVL_Tree<T>::n_search(T data, Node* node)
{
	if(node == NULL) return false;
	else if(node->data == data) return true;
	else if(node->data <= data) n_search(data, node->right);
	else n_search(data, node->left);
};