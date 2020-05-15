#include<bits/stdc++.h>
using namespace std;

class BST{
	int val;
	BST *left, *right;

	public:
		BST(int v);
		BST* search(int v);
		void insert(int v);
		void del(int v);
		void inorder();
};

BST :: BST(int v){
	val = v;
	left = right = 0;
}

BST* BST :: search(int v){
	BST* n = this;
	while(n != 0 && n->val != v){
		if (v< n->val) n = n->left;
		else n = n->right;
	}
	if (n==0) {cout<<"Element "<<v<<" does not exist!\n"; return 0;}
	else cout<<"Element "<<v<<" exists!\n";
	return n;
}

void BST :: insert(int v){
	BST* n = this;
	while(1){
		if (v<n->val) {
			if (n->left !=0) n = n->left;
			else {n->left = new BST(v); break;}
		}
		else {
			if (n->right !=0) n = n->right;
			else {n->right = new BST(v); break;}
		}
	}
	cout<<"Element "<<v<<" inserted!\n";
}

void BST :: del(int v){
	BST * n = this->search(v);
	if (n ==0) return;
	if (n->left == 0){
		auto temp = n;
		n = n->right;
		delete temp;
	}
	else{
		auto nn = n->left;
		if (nn->right ==0) {
			n->val = nn->val;
			n->left = nn->left;
			delete nn;
		}
		else{
			auto nn1 = nn->right;
			while(nn1->right!=0){
				nn = nn1;
				nn1 = nn1->right;
			}
			nn->right = nn1->left;
			n->val = nn1->val;
			delete nn1;
		}
	}
	cout<<"Element "<<v<<" deleted!\n";
}
void BST :: inorder(){
	stack<BST*> st;
	auto n = this;
	while(n!=0 || !st.empty()){
		while(n!=0){
			st.push(n);
			n = n->left;
		}
		n = st.top();
		st.pop();
		cout<< n->val<<" ";
		n = n->right;
	}
	cout<<endl;
}
int main(){
	BST* root = new BST(5);
	root->insert(4);
	root->insert(10);
	root->insert(6);
	root->search(4);
	root->search(3);
	root->del(10);
	root->inorder();

}