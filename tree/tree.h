#include <queue>
#include <stack>
using namespace std;

#ifndef Binary_Search_Tree
#define Binary_Search_Tree

template<class T> class Tree;

template<class T>
class Node {
public:
	Node() { left = right = NULL; }
	Node(const T& el, Node *l = 0, Node *r = 0) {
		key = el; left = l; right = r;
	}
	T key;
	Node *left, *right;
};

template<class T>
class Tree {
public:
	Tree() { root = 0; }
	~Tree() { clear(); }
	void clear() { clear(root); root = 0; }
	bool isEmpty() { return root == 0; }
	void inorder() { inorder(root); }
	void insert(const T& el);
	void findAndDelete(const T& el);
	void deleteNode(Node<T> *& node);

protected:
	Node<T> *root;

	void clear(Node<T> *p);
	void inorder(Node<T> *p);

};

template<class T>
void Tree<T>::clear(Node<T> *p)
{
	if (p != 0) {
		clear(p->left);
		clear(p->right);
		delete p;
	}
}

template<class T>
void Tree<T>::inorder(Node<T> *p) {
	//TO DO! This is for an inorder tree traversal!
}

template<class T>
void Tree<T>::insert(const T &el) {
	Node<T> *p = root, *prev = 0;
	while (p != 0) {
		prev = p;
		if (p->key < el)
			p = p->right;
		else
			p = p->left;
	}
	if (root == 0)
		root = new Node<T>(el);
	else if (prev->key<el)
		prev->right = new Node<T>(el);
	else
		prev->left = new Node<T>(el);
}

template<class T>
void Tree<T>::findAndDelete(const T& el) {
	Node<T> *node = root, *prev = 0;
	while (node != 0) {
		if (node->key == el)
			break;
		prev = node;
		if (node->key < el)
			node = node->right;
		else node = node->left;
	}
	if (node != 0 && node->key == el)
		if (node == root)
			deleteNode(root);
		else if (prev->left == node)
			deleteNode(prev->left);
		else deleteNode(prev->right);
}


template<class T>
void Tree<T>::deleteNode(Node<T> *&node) {
	Node<T> *prev, *tmp = node;
	if (node->right == 0)
		node = node->left;
	else if (node->left == 0)
		node = node->right;
	else {
		tmp = node->left;
		prev = node;
		while (tmp->right != 0) {
			prev = tmp;
			tmp = tmp->right;
		}
		node->key = tmp->key;
		if (prev == node)
			prev->left = tmp->left;
		else prev->right = tmp->left;
	}
	delete tmp;
}

#endif // Binary_Search_Tree
