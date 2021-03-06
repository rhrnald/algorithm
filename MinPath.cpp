using namespace std;

typedef pair<int,int> pii;

const int INF = 0x3c3c3c3c;

class Graph{
public:
	struct E {int to, w;};
	int n;
	vector<vector<E>> G;

	Graph(int x) {
		G.resize(x);
		n=x;
	}

	void connect(int x, int y, int wt) {
		G[x].push_back({y, wt});
		//G[y].push_back({x, wt});
	}
	vector<int> Dijkstra(int from) {//O(E + V log V)
		vector<int> ans = vector<int>(n, INF);
		vector<bool> vst = vector<bool>(n, false);
		ans[from] = 0;
		priority_queue<pii, vector<pii>, greater<pii>> Q;
		Q.push(make_pair(0,from));
		while(!Q.empty()) {
			pii temp = Q.top(); Q.pop();
			int d = temp.first;
			int idx = temp.second;

			if(vst[idx]) continue;
			vst[idx] = true;

			for(int i=0; i<G[idx].size(); i++) {
				if(ans[G[idx][i].to]>G[idx][i].w+ans[idx]) {
					ans[G[idx][i].to] = G[idx][i].w+ans[idx];
					Q.push(make_pair(ans[G[idx][i].to], G[idx][i].to));
				}
			}
		}
		return ans;
	}
	
	vector<int> BellmanFord(int from) {//negative edge OK // O(VE)
		vector<int> ans = vector<int>(n, INF);
		ans[from] = 0;

		for(int tc=0; tc<n-1; tc++) {
			for(int i=0; i<n; i++) {
				for(int j=0; j<G[i].size(); j++) {
					if(ans[G[i][j].to] > ans[i]+G[i][j].w) ans[G[i][j].to]=ans[i]+G[i][j].w;
				}
			}
		}

		return ans;
	}
	vector<vector<int>> Floyd_Warshall() {//O(V^3)
		vector<vector<int>> ret = vector<vector<int>>(n, vector<int>(n, INF));
		for(int i=0; i<n; i++)
			for(int j=0; j<G[i].size(); j++) {
				ret[i][G[i][j].to] = G[i][j].w; //if path from x to y is single
			}
		for(int i=0; i<n; i++) ret[i][i] = 0;

		for(int k=0; k<n; k++)
			for(int i=0; i<n; i++)
				for(int j=0; j<n; j++) {
					ret[i][j] = min(ret[i][j], ret[i][k]+ret[k][j]);
				}
		return ret;
	}
};
