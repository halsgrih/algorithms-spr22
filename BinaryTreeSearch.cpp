#include <iostream>
using namespace std;
struct node {
	int key;
	int value;
	node* left = NULL;
	node* right = NULL;
	//node *parent = NULL;
} typedef node;

node* getNewNode(int val, int key) {
	node* newNode = new node();
	newNode->value = val;
	newNode->key = key;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

node* insert(node* root, int val, int key) {
	if (root == NULL) {
		root = getNewNode(val, key);
		return root;
	}
	else if (val < root->value) {
		root->left = insert(root->left, val, key);
	}
	else if (val > root->value){
		root->right = insert(root->right, val, key);
	}
	else if (val == root->value) {
		if (key <= root->key) {
			root->left = insert(root->left, val, key);
		}
		else {
			root->right = insert(root->right, val, key);
		}
	}
	return root;
}

void inorder(node* x) {
	if (x != NULL) {
		inorder(x->left);
		printf("%d %d	", x->value, x->key);
		inorder(x->right);
	}
}

bool search(node* root, int data, int l, int r) {
	if (root == NULL) return false;
	else if (root->value == data) return true;
	else if (data <= root->value) return search(root->left, data);
	else return search(root->right, data);
}

int main() {
	node* root = NULL; //create an empty tree
	int n;
	cin >> n;
	int a[70000];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		root = insert(root, a[i], i);
	}

	inorder(root);

	int q, l, r, x;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> l >> r >> x;
		//cout << search(root, x);
	}
	return 0;
}