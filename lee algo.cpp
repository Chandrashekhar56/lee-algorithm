#include <bits/stdc++.h>
using namespace std;
#define TOTAL_ROW 12
#define TOTAL_COL 10
struct Point
{
	int x_cordinates;
	int y_cordinates;
};
struct node_queue
{
	Point pt;
	int distance;
};
bool check_row_and_col_is_valid_or_not(int r, int c)//here r used for Row and c used for col
{
	return (r >= 0) && (r < TOTAL_ROW) &&
		(c >= 0) && (c < TOTAL_COL);
}
int r[] = {-1, 0, 0, 1};
int c[] = {0, -1, 1, 0};
int lee_algo_function(int matrix[][TOTAL_COL], Point source_point, Point destination_point)
{
	if (!matrix[source_point.x_cordinates][source_point.y_cordinates] || !matrix[destination_point.x_cordinates][destination_point.y_cordinates])
		return -1;

	bool visited_cell[TOTAL_ROW][TOTAL_COL];
	memset(visited_cell, false, sizeof visited_cell);
	visited_cell[source_point.x_cordinates][source_point.y_cordinates] = true;
	queue<node_queue> queue;
	node_queue ce = {source_point, 0};
	queue.push(ce);
	while (!queue.empty())
	{
		node_queue current = queue.front();
		Point pt = current.pt;
		if (pt.x_cordinates == destination_point.x_cordinates && pt.y_cordinates == destination_point.y_cordinates)
			return current.distance;
		queue.pop();
		for (int x = 0; x < 4; x++)
		{
			int row = pt.x_cordinates + r[x];
			int col = pt.y_cordinates + c[x];
			if (check_row_and_col_is_valid_or_not(row, col) && matrix[row][col] && !visited_cell[row][col])
			{
				visited_cell[row][col] = true;
				node_queue adjency_Cell = { {row, col},current.distance + 1 };
				queue.push(adjency_Cell);
			}
		}
	}
	return -1;
}
int main()
{
	int matrix[TOTAL_ROW][TOTAL_COL] =
	{
		{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
		{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
		{ 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }
	};

	Point source_point = {0, 0};
	Point destination_point = {5, 4};

	int distance = lee_algo_function(matrix, source_point, destination_point);

	if (distance != -1)
		cout <<"Shortest Path is: " << distance ;
	else
		cout <<"Shortest Path doesn't exist";

	return 0;
}
