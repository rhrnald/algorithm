class KMP{
public:
	string s;
	int n;
	vector<int> kmp;
	KMP(string _s){
		s=_s;
		n=s.size();
	}
	
	void getKMP() {
		int k=-1;
		kmp.resize(n);
		kmp[0] = -1;
		for(int i=1; i<n; i++) {
			while(k>=0 && s[i] != s[k+1]) k=kmp[k];
			if(s[i]==s[k+1]) k++;
			kmp[i] = k;
		}
	}
};
