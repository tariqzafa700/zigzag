#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

void arrange(string& input, int rows, int cols)
{
    cout << input << endl;
    vector<vector<char>> zigzagArray(rows, vector<char>(cols, ' '));
    int i = 0, row = 0, col = 0, j = 0;
    while (i < input.size())
    {
        while (j < rows)
        {
            zigzagArray[j++][col] = input[i++];
            if (i == input.size())
            {
                break;
            }
        }
        j--;
        while (j > 1)
        {
            zigzagArray[--j][++col] = input[i++];
            if (i == input.size())
            {
                break;
            }
        }
        j = 0;
        col++;
    }
    int m = 0, n = 0;
    for (m = 0; m < zigzagArray.size(); ++m)
    {
        for (n = 0; n < zigzagArray[m].size(); ++n)
        {
            cout << zigzagArray[m][n] ;
        }
        cout << endl;
    }
}

string findZigzag(string&& input, int rows) 
{
    int sz = input.size() / (rows + rows - 2);
    int rem = input.size() % (rows + rows - 2);
    int extra;
    if (rem > 0 && rem <= rows)
    {
        extra = 1;
    }
    else if (rem == 0)
    {
        extra = 0;
    }
    else
    {
        extra = 1 + rem - rows;
    }

    int col = (1 + rows - 2) * sz + extra;
    arrange(input, rows, col);
    return "";
}

int main(int, char**) {
    findZigzag("Hello world of our time", 5);
}
