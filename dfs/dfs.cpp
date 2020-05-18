#include <iostream>
#include <stack>
#include <vector>

void add_edge(std::vector< std::vector<int> > &adjacent, int src, int dst){
	// adjacent.push
	adjacent[src][dst] = 1;
}

int main(){
	std::cout << "Hello, DFS!" << std::endl;

	// Graph Initialization
	int n = 7;
	std::vector< std::vector<int> > adj(n, std::vector<int>(n));
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

	// DFS Loop
	std::vector<bool> visit(n, false);
	std::vector<bool> stack_history(n, false);
	std::stack<int> stack;
	int s = 0; // start
	stack.push(s);
	stack_history[s] = true;

	while(!stack.empty()){
		// Step 1
		s = stack.top();
		std::cout << s << "-";
		stack.pop();
		std::cout << '\t' << s << " is removed from the stack." << std::endl;

		// Step 2
		visit[s] = true;

		// Step 3
		for (int i = 0; i < n; ++i)
		{
			if ( (adj[s][i]!=0) && !visit[i] && !stack_history[i] ){
				stack.push(i);
				stack_history[i] = true;
				std::cout << '\t' << i << " is added to the stack." << std::endl;
			}
		}
	}

	return -1;
}