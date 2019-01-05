class node{
	public:
	node *L;
	node *R;
	int cnt;
	node(node *_L=nullptr, node *_R=nullptr, int _cnt=0):L(_L), R(_R), cnt(_cnt) {}
};

class SegTree {
	public:
	node *head;
	SegTree() {head=new node(nullptr, nullptr, 0);}
	void insert(int val) {
		val+=B;
		vector<int> b;
		while(val) {b.push_back(val%2); val/=2;}

		node* temp=head;
		for(int i=sz(b)-2; i>=0 ;i--) {
			temp->cnt++;
			if(b[i]) {
				if(temp->R == nullptr) {
					temp->R = new node(nullptr, nullptr, 0); 
				}
				temp = temp->R;
			} else {
				if(temp->L == nullptr) {
					temp->L = new node(nullptr, nullptr, 0);
				}
				temp = temp->L;
			}
		}
		temp->cnt++;
	}
	
	int count(int val) {
		val+=B;
		vector<int> b;
		while(val) {b.push_back(val%2); val/=2;}

		node *temp = head;
		int ret=0;
		for(int i=sz(b)-2; i>=0 ;i--) {
			if(b[i]) {
				if(temp->L != nullptr) ret+=temp->L->cnt;
				if(temp->R == nullptr) 	break;
				temp = temp->R;
			} else {
				if(temp->L == nullptr) break;
				temp = temp->L;
			}
			if(i==0) ret+=temp->cnt;
		}
		return ret;
	}
};
