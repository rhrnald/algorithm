class Graph{
public:
	struct E {int to, w;};
	int n;
	vector<vector<E>> G;

	Graph(int x) {
		G.resize(x);
		n = x;
	}

	void connect(int x, int y, int wt) {
		G[x].push_back({y, wt});
		//G[y].push_back({x, wt});
	}
	vector<int> Dijkstra(int from) {
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
	
	vector<int> BellmanFord(int from) {
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
};
