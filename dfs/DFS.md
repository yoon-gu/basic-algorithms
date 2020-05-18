# Depth First Search

## 알고리즘 설명

필요한 변수들:
- `visit`: 방문헀던 곳인지 표시
- `adjacent`: 노드(Node)들의 연결성을 나타내는 행렬
- `stack`: 방문 예정 노드들이 저장되는 곳

알고리즘: `stack`에 시작 지점인 노드 `0`을 추가한다.
1. `stack`에서 `pop()`을 해서 현재 위치를 얻는다.
1. `visit`의 현재 위치에 표시를 한다.(`true`)
1. 현재 위치에서 (a)인접한 위치에 있고, (b)방문하지 않았던 곳들을 `stack`에 추가한다.
1. `stack`이 비어있지 않다면 1단계로 간다.

### `C++` 코드
```c++
// DFS Loop
std::vector<bool> visit(n, false);
std::stack<int> stack;
int s = 0; // start
stack.push(s);
stack_history[s] = true;

while(!stack.empty()){
	// Step 1
	s = stack.top();
	stack.pop();
	if (!visit[s]){
		std::cout << s << "-";
		std::cout << '\t' << s << " is removed from the stack." << std::endl;
	}

	// Step 2
	visit[s] = true;

	// Step 3
	for (int i = 0; i < n; ++i)
	{
		if ( (adj[s][i]!=0) && !visit[i]){
			stack.push(i);
			std::cout << '\t' << i << " is added to the stack." << std::endl;
		}
	}
}
```

출력 결과:
```
0-	0 is removed from the stack.
	1 is added to the stack.
1-	1 is removed from the stack.
	2 is added to the stack.
	5 is added to the stack.
5-	5 is removed from the stack.
	4 is added to the stack.
4-	4 is removed from the stack.
	3 is added to the stack.
	6 is added to the stack.
6-	6 is removed from the stack.
3-	3 is removed from the stack.
2-	2 is removed from the stack.
```

## 미로 찾기
미로 찾기에 잘 맞는 알고리즘이다.
1. 미로 찾기에서 갈림길을 만났을 때, 한 가지를 선택한다.
1. 선택한 방향에 표시를 한다.
1. 선택한 갈림길로 진행한다.
1. 출구가 나오기 전에 갈림길이 나오면 다시 2단계로 가고, 출구가 나오면 끝.
