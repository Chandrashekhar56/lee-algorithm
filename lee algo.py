from collections import deque
TOTAL_ROW = 12
TOTAL_COL = 10

class Cell:
	def __init__(self,x_cordinates: int, y_cordinates: int):
		self.x_cordinates = x_cordinates
		self.y_cordinates = y_cordinates

class node_queue:
	def __init__(self,pt: Cell, dist: int):
		self.pt = pt
		self.dist = dist

def check_row_and_col_is_valid_or_not(r: int, c: int):
	return ((r >= 0) and (r < TOTAL_ROW) and (c >= 0) and (c < TOTAL_COL))

r = [-1, 0, 0, 1]
c = [0, -1, 1, 0]

def lee_algo_function(matrix, source_point: Cell, destination_point: Cell):

	if matrix[source_point.x_cordinates][source_point.y_cordinates]!=1 or matrix[destination_point.x_cordinates][destination_point.y_cordinates]!=1:
		return -1

	visited_cell = [[False for x in range(TOTAL_COL)]
					for y in range(TOTAL_ROW)]

	visited_cell[source_point.x_cordinates][source_point.y_cordinates] = True

	queue = deque()

	ce = node_queue(source_point,0)
	queue.append(ce)

	while queue:

		current = queue.popleft()

		pt = current.pt
		if pt.x_cordinates == destination_point.x_cordinates and pt.y_cordinates == destination_point.y_cordinates:
			return current.dist

		for x in range(4):
			row = pt.x_cordinates + r[x]
			col = pt.y_cordinates + c[x]

			if (check_row_and_col_is_valid_or_not(row,col) and
			matrix[row][col] == 1 and
				not visited_cell[row][col]):
				visited_cell[row][col] = True
				adjency_Cell = node_queue(Cell(row,col),
									current.dist+1)
				queue.append(adjency_Cell)
	return -1

matrix = 	[
		[ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 ],
		[ 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 ],
		[ 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 ],
		[ 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 ],
		[ 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 ],
		[ 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 ],
		[ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 ],
		[ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 ],
        [ 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 ],
		[ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 ],
		[ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 ],
		[ 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 ]
	];
source_point = Cell(0,0)
destination_point = Cell(5,4)

distance = lee_algo_function(matrix,source_point,destination_point)

if distance!=-1:
		print("Length of the Shortest Path is: ",distance)
else:
		print("Shortest Path doesn't exist")
