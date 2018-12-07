class SuffixArray {
public:
	string s;
	int n;
	SuffixArray(string _s){
		s = _s;
		n = s.size();
	}

	vector<int> m,idx,sfx,cnt,temp;
	void getSFX() {
		int lim = max(n+1, 257);
		m.resize(n+1); idx.resize(n+1); sfx.resize(n+1);temp.resize(n+1);
		for(int i=0; i<n; i++) m[i] = s[i];
		for(int i=0; i<n; i++) sfx[i] = i;

		for(int d=1; d<n; d=d+d) {
			cnt=vector<int>(lim, 0);
			for(int i=0; i<n; i++) cnt[m[min(n, i+d)]]++;
			for(int i=1; i<lim; i++) cnt[i]+=cnt[i-1];
			for(int i=n-1; i>=0; i--) idx[--cnt[m[min(n,i+d)]]] = i;

			cnt=vector<int>(lim,0);
			for(int i=0; i<n; i++) cnt[m[i]]++;
			for(int i=1; i<lim; i++) cnt[i]+=cnt[i-1];
			for(int i=n-1; i>=0; i--) sfx[--cnt[m[idx[i]]]] = idx[i];

			temp[sfx[0]] = 1;
			for(int i=1; i<n; i++) {
				if((m[sfx[i]] == m[sfx[i-1]]) && (m[sfx[i]+d] == m[sfx[i-1]+d])) temp[sfx[i]] = temp[sfx[i-1]];
				else temp[sfx[i]] = temp[sfx[i-1]]+1;
			}
			m = temp;
		}
	}
	
	vector<int> loc;
	vector<int> lcp;
	void getLCP() {
		loc.resize(n); lcp.resize(n);
		for(int i=0; i<n; i++) loc[sfx[i]] = i;
		int k=0;
		for(int i=0; i<n; i++) {
			int l = loc[i];
			if(l==0) {k=0; continue;}
			if(k) k--;

			while(s[i+k] == s[sfx[l-1]+k]) k++;
			lcp[l] = k;
		}	
	}
};
