#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Position
{
	int r, c;
};

void print_map(vector< vector<int> > map, int N, int M){
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < M; ++j)
			cout << map[i][j] << "-";
		cout << endl;
	}
}

void spread_virus(vector< vector<int> > &map, int N, int M){

}

int main(){
	int N, M;

	cin >> N;
	cin >> M;

	vector< vector<int> > map(N, vector<int>(M, 0));
	vector<Position> virus_location;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j){
			cin >> map[i][j];
			if (map[i][j] == 2){
				Position here = {i, j};
				virus_location.push_back(here);
			}
		}

	// Print Information
	printf("\nN=%d, M=%d\n", N, M);
	print_map(map, N, M);

	// Spread virus
	for (int i = 0; i < virus_location.size(); ++i)
	{
		int r = virus_location[i].r;
		int c = virus_location[i].c;
		// vector< vector<bool> > visit(N, vector<bool>(M, false));
		stack<Position> stack;
		stack.push(virus_location[i]);
		while(!stack.empty()){
			Position here = stack.top();
			stack.pop();
			for (int d = 0; d < 4; ++d)
			{
				int nr = -1;
				int nc = -1;
				if (d == 0) // Up
				{
					nr = r - 1;
					nc = c;
				}
				else if (d == 1) // Down
				{
					nr = r + 1;
					nc = c;
				}
				else if (d == 2) // Left
				{
					nr = r;
					nc = c - 1;
				}
				else if (d == 3) // Right
				{
					nr = r;
					nc = c + 1;
				}
				if ((nr < N && (nc < M) && (nr >= 0) && (nc >= 0) && map[nr][nc] == 0))
					map[nr][nc] = 2;
			}
		}
	}
	return -1;
}