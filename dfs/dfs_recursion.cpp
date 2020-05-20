#include <iostream>
#include <stack>
#include <vector>

void add_edge(std::vector< std::vector<int> > &adjacent, int src, int dst){
	// adjacent.push
	adjacent[src][dst] = 1;
}

void dfs(int here, std::vector<bool> &visit, std::vector< std::vector<int> > adjacent){
	visit[here] = true;
	std::cout << here << '-';
	for (int i = 0; i < visit.size(); ++i)
	{
		if ( adjacent[here][i] != 0 ){
			int next = adjacent[here][i];
			if (!visit[next]){
				std::cout << "\t::::" << next << std::endl;
				dfs(next, visit, adjacent);
			}
		}
	}
}

int main(){
	std::cout << "Hello, DFS(Recursion)!" << std::endl;

	// Graph Initialization
	int n = 7;
	std::vector< std::vector<int> > adj(n, std::vector<int>(n, 0));
	add_edge(adj, 0, 1);

	add_edge(adj, 1, 0);
	add_edge(adj, 1, 2);
	add_edge(adj, 1, 5);

	add_edge(adj, 2, 1);
	add_edge(adj, 2, 3);
	add_edge(adj, 2, 4);

	add_edge(adj, 3, 2);
	add_edge(adj, 3, 4);

	add_edge(adj, 4, 2);
	add_edge(adj, 4, 3);
	add_edge(adj, 4, 5);
	add_edge(adj, 4, 6);

	add_edge(adj, 5, 1);
	add_edge(adj, 5, 4);

	add_edge(adj, 6, 4);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			std::cout << adj[i][j] << "-";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::vector<bool> visit(n, false);

	dfs(0, visit, adj);
	return -1;
}