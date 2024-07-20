#include <bits/stdc++.h>
#include <vector>
using namespace std;

void constructCarpet(vector<vector<char>> &carpet, int x, int y, int size, int level)
{
  if (level == 0)
  {
    carpet[x][y] = '#';
  }
  else
  {
    int newSize = size / 3;
    for (int i = 0; i < 3; ++i)
    {
      for (int j = 0; j < 3; ++j)
      {
        if (i == 1 && j == 1)
        {
          for (int dx = 0; dx < newSize; ++dx)
          {
            for (int dy = 0; dy < newSize; ++dy)
            {
              carpet[x + newSize + dx][y + newSize + dy] = '.';
            }
          }
        }
        else
        {
          constructCarpet(carpet, x + i * newSize, y + j * newSize, newSize, level - 1);
        }
      }
    }
  }
}

int main()
{
  int N;
  cin >> N;

  int size = pow(3, N);
  vector<vector<char>> carpet(size, vector<char>(size, '#'));
  constructCarpet(carpet, 0, 0, size, N);

  for (int i = 0; i < size; ++i)
  {
    for (int j = 0; j < size; ++j)
    {
      cout << carpet[i][j];
    }
    cout << endl;
  }

  return 0;
}
