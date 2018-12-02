class AdjMat {
public:
	vector<vector<int>> G;
	AdjMat(int n) {
		G = vector<vector<int>>(n+1, vector<int>(n+1));
	}

	void con(int x, int y, int d) {
		G[x][y] = d;
		//G[y][x] = d;
	}
};

class DirectedGraph {
public:
	struct E {int to, w;};

	vector<vector<E>> G;

	DirectedGraph(int n) {
		G.resize(n+1);
	}

	void connect(int x, int y, int wt) {
		G[x].push_back({y, wt});
		// For non-directed Graph
		// G[y].push_back({x, wt});
	}
};

class UndirectedGraph{
public:
	struct E {int to, w;};

	vector<vector<E>> G;

	UndirectedGraph(int n) {
		G.resize(n+1);
	}

	void connect(int x, int y, int wt) {
		G[x].push_back({y, wt});
		G[y].push_back({x, wt});
	}
};

class FlowGraph {
public:
	struct E {int to, w, rev;};

	vector<vector<E>> G;

	FlowGraph(int n) {
		G.resize(n+1);
	}

	void connect(int x, int y, int wt) {
		G[x].push_back({y, wt, sz(G[y])});
		G[y].push_back({x, 0, sz(G[x])-1});
	}
};
