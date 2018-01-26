#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
vector<int> vg[10005];
vector<pair<int,int> > bridge_edges;

class BridgeInGraph{
	private:
	  int V,E;
	  static int timer;
	  int used[30000],Tin[300000] ,Tup[300000];
          void inti();
          void findBridgeEdge(int,int);
    public: 
      	  void solve();
      	  void printTime();
      	  void printGraph();
      	  void printBridgeEdges();
          

};
int BridgeInGraph :: timer = 0;
void BridgeInGraph::printTime() {
	 for(int i= 1; i<= V ;i++) {
	 	cout << "vertex: " << i << "startTime :" << Tin[i] <<" "<<"upTime: "<< Tup[i]<<"\n";
	 }
}
void BridgeInGraph::inti(){
	memset(used,0,sizeof(used));
	memset(Tup,0,sizeof(Tup));
	memset(Tin,0,sizeof(Tin));
}

void BridgeInGraph::findBridgeEdge(int root,int parent = -1) {
         used[root] =1;
         Tup[root] = Tin[root] = timer++;
         for(int i = 0 ; i< vg[root].size() ; i++) {
         	 int u = vg[root][i];
         	 if(u == parent ) continue;
         	 else if(used[u]) Tup[root] = min(Tup[root],Tin[u]);
         	 else {
         	 	 findBridgeEdge(u , root);
         	 	 Tup[root] = min(Tup[root],Tup[u]);

         	 }
         	 if(Tin[root]   <  Tup[u]) {
         	 	 bridge_edges.push_back({root,u});
         	 }
         }
}

void BridgeInGraph::solve(){
         cin >> V >> E;
         int u , v;
         for(int i= 1; i<= E ; i++) {
         	cin >> u >> v;
         	vg[u].push_back(v);
         	vg[v].push_back(u);
         }
         inti();
         for(int i= 1 ;  i<= V ; i++) {
         	if(!used[i]) findBridgeEdge(i);
         } 
}
void BridgeInGraph::printBridgeEdges(){
	cout << "BridgeEdges in the graph:"<< bridge_edges.size()<<"\n";
	for(int i =0 ; i< bridge_edges.size(); i++) {
		cout << bridge_edges[i].first <<" "<< bridge_edges[i].second<<"\n";
	}
}
void BridgeInGraph::printGraph(){
	for(int i=1; i<= V; i++) {
		cout << i <<"-> ";	
		for(int j= 0; j < vg[i].size() ; j++) cout << vg[i][j] <<" ";
		cout <<"\n";
	}
}
int main(){
	 BridgeInGraph ob;
	 ob.solve();
	 ob.printBridgeEdges();
	return 0;
}
