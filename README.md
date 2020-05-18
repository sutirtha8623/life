# life
Conway's Game of Life implementation in C++ and sfml
### An useful trick
Conway's Game of Life is usually played on an infinite grid of cells. An easy trick to handle this is to join the edges of the grid. (i.e the last cell of a column is adjacent to its first.). This forms a toroid like structure. To achieve this, one can use ```matrix [(i+rows)%rows] [(j+columns)%columns]``` instead of ```matrix[i][j]``` to access a particular cell in a grid. 
