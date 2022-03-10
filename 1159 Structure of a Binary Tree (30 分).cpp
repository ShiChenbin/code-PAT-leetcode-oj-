#include <bits/stdc++.h>
//根据前序和中序构造一棵树，然后问你，下面的说法是否正确

using namespace std;
std::vector<int> post, in;

struct node
{
	int val, height;
	node *parent, *left, *right;
	node(int x, int h){
		this.val = x;
		this.height = h;
		this.left = this.right = this.parent = null;
	}
};

unordered_map<int, node *> mp;

bool isfull = true;

node * create(int postL, int postH, int inL, int inH, int height){
	if (postL > postH){
		return NULL;
	}

	node * root = new node(post[postH], height);
	int k;
	for(k = inL; in[k] != post[postH]; k++);

	int leftnum = k - inL;

	root->left = create(postL, )
}
int main()
{
	
	return 0;
}