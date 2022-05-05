#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define edge pair<int, int>

class Graph {
   private:
  vector<pair<int, edge> > G;  
  vector<pair<int, edge> > T; 
  int *parent;
  int V;
   public:
  Graph(int V);
  void AddWeightedEdge(int u, int v, int w);
  int find_set(int i);
  void union_set(int u, int v);
  void kruskal();
  void print();
};

Graph::Graph(int V) {
  parent = new int[V];
  for (int i = 0; i < V; i++)
    parent[i] = i;
  G.clear();
  T.clear();
}

void Graph::AddWeightedEdge(int u, int v, int w) {
  G.push_back(make_pair(w, edge(u, v)));
}

int Graph::find_set(int i) {
  if (i == parent[i])
    return i;
  else
    return find_set(parent[i]);
}

void Graph::union_set(int u, int v) {
  parent[u] = parent[v];
}

void Graph::kruskal() {
  int i, uRep, vRep;
  sort(G.begin(), G.end());  
  for (i = 0; i < G.size(); i++) {
    uRep = find_set(G[i].second.first);
    vRep = find_set(G[i].second.second);
    if (uRep != vRep) {
      T.push_back(G[i]);
      union_set(uRep, vRep);
    }
  }
}

void Graph::print() {
  cout << "Edge :"
     << " Weight" << endl;
  for (int i = 0; i < T.size(); i++) {
    cout << T[i].second.first << " - " << T[i].second.second << " : "
       << T[i].first;
    cout << endl;
  }
}

int minKey(int key[], bool mstSet[],int V){
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void printMST(int parent[], int graph[5][5],int V){
    cout<<"Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
}
 
void primMST(int graph[5][5]){
	int V=5;
    int parent[V];
    int key[V];
    bool mstSet[V];
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++){
        int u = minKey(key, mstSet,V);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
 
    printMST(parent, graph,V);
}

int main() {
	int v,edges,nodes,weight,select;
	cout<<"Enter no. of Vertices ";
	cin>>v;
	Graph g(v);
	cout<<"Enter method to find MST \n1. Kruskal's Algorithm \n2. Prim's Algorithm";
	cin>>select;
	if (select==1){
		for(int i=0;i<v;i++){
			cout<<"Enter Edge";
			cin>>edges;
			cout<<"Enter Node";
			cin>>nodes;
			cout<<"Enter Weight";
			cin>>weight;
			g.AddWeightedEdge(edges, nodes, weight);
		}
		g.kruskal();
		g.print();
	}
	
	if (select==2){
		int graph[5][5] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
		primMST(graph);
	}
  	return 0;
}
