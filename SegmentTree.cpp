class SegTree {
	public:
	vector<int> tree;
	int K;//node (1 to K-1) + leaf node(K~ 2k-1);

	int function(int x, int y) {
		return max(x,y);
		//return x+y;
	}
	SegTree(int n) {
		K=1;
		while(K<n) K = K+K;
		tree = vector<int>(K+K, 0);
	}

	void insert(int pos, int val) { //pos = 0~n-1
		pos+=K;
		tree[pos] = val;
		pos/=2;
		while(pos) {
			tree[pos] = function(tree[pos+pos], tree[pos+pos+1]);
			pos/=2;
		}
	}

	int getVal(int x, int y) {//x,y = 0~n-1
		if(y<x) return 0;
		x+=K; y+=K;
		int xVal = tree[x];
		int yVal = tree[y];
		while(y-x>1) {
			if(!(x%2)) xVal = function(xVal, tree[x+1]); // x가 왼쪽 노드일경우
			if(y%2) yVal = function(tree[y-1], yVal); // y가 오른쪽 노드일경우
			
			x/=2;
			y/=2;
		}
		return function(xVal, yVal);
	}
	void printTree() {
		for(int i=1; i<=K; i=i+i) {
			for(int j=i; j<i+i; j++) printf("%d ", tree[j]);
			printf("\n");
		}
		printf("\n");
	}
};

//BOJ 11053, 11055
