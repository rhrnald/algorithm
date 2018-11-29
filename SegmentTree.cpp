#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>

#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3c3c3c3c;
const ll LINF = 1ll*INF*INF*2;

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

const int N = 1001;
int n;
int input[N];
vector<pii> v;

int main(void) {
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", input+i);
	for(int i=0; i<n; i++) v.push_back(make_pair(input[i], -i));
	sort(all(v));// ->	sort(v.begin(), v.end());랑 같음 위에 #define all(v) (v).begin(), (v).end()

	SegTree sg = SegTree(n);

	for(int i=0; i<n; i++) {
		int pos = -v[i].second;
		int temp;
		temp=sg.getVal(0, pos-1)+1;
		sg.insert(pos, temp);
	}
	printf("%d", sg.getVal(0, n-1));
}
