#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int dr[] = { 0, 0, -1, 1};
int dc[] = {-1, 1,  0, 0};

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

void spread_virus(int r, int c, vector< vector<int> > &map, int N, int M){
	// printf("(%d, %d)\n", r, c);
	map[r][c] = 2;
	for (int i = 0; i < 4; ++i)
	{
		int nr = r + dr[i];
		int nc = c + dc[i];
		if ((nr >= 0) && (nc >= 0) && (nr < N) && (nc < M)){
			if (map[nr][nc] == 0)
				spread_virus(nr, nc, map, N, M);
		}
	}
}

int count_safe(vector< vector<int> > map, int N, int M){
	int val = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (map[i][j] == 0)
				val++;
		}
	}
	return val;
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

	for (int i = 0; i < virus_location.size(); ++i)
	{
		int r = virus_location[i].r;
		int c = virus_location[i].c;
		spread_virus(r, c, map, N, M);
	}
	printf("\n===============================\n");
	print_map(map, N, M);

	cout << "Safe: " << count_safe(map, N, M);
	return -1;
}