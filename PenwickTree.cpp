class PanwickTree {
	public:
	vector<int> v;
	PanwickTree(int n) {
		v = vector<int>(n+1, 0);
	}

	void insert(int pos, int val) {//pos = 1~n
		while(pos<=n) {
			v[pos]+=val;
			pos+=pos&(-pos);
		}
	}

	int sum(int pos) {
		int ret=0;
		while(pos) {
			ret+=v[pos];
			pos-=pos&(-pos);
		}
		return ret;
	}
	int sum(int x, int  y) {
		return sum(y)-sum(x-1);
	}
};

//BOJ 2042
