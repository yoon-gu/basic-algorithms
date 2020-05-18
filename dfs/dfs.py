from collections import deque
import numpy as np

class Graph:
	def __init__(self, n):
		self.adj = np.zeros((n, n))
		self.visit = np.zeros((n,1))
		self.stack_history = np.zeros((n,1))
		self.stack = deque()

	def add_edge(self, src, dst):
		self.adj[src][dst] = 1

n = 7
g = Graph(n)
g.add_edge(0, 1);

g.add_edge(1, 0);
g.add_edge(1, 2);
g.add_edge(1, 5);

g.add_edge(2, 1);
g.add_edge(2, 3);
g.add_edge(2, 4);

g.add_edge(3, 2);
g.add_edge(3, 4);

g.add_edge(4, 2);
g.add_edge(4, 3);
g.add_edge(4, 5);
g.add_edge(4, 6);

g.add_edge(5, 1);
g.add_edge(5, 4);

g.add_edge(6, 4);


here = 2
g.stack.append(here)

while len(g.stack) > 0 :
	here = g.stack.pop()
	if not g.visit[here]:
		print("{0}-\t{0} is removed from the stack.".format(here))
		g.visit[here] = True
	for i in range(n):
		if (g.adj[here][i] != 0) and (not g.visit[i]):
			g.stack.append(i)
			print("\t{} is added to the stack.".format(i))
			g.stack_history[i] = True

	print(g.stack)