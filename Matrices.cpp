#include <iostream>
#include <vector>
using namespace std;

int minu()
{
    int choice = -1;
    while (choice == -1)
    {
        cout << "1) Multiply Matrices\n2) Exit\nYour Choice: ";
        cin >> choice;

        if ( !(choice == 1 || choice == 2) )
        {
            cout << "Invalid Choice, Choose again\n";
            choice = -1;
        }
    }
    return choice;
}

void read_matrix(vector<vector<int>> &v, int rows, int columns)
{
    
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < columns; col++)
        {
            cin >> v[row][col];
        }
    }
}

void print_matrix(vector<vector<int>>& v, int rows, int columns)
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < columns; col++)
        {
            cout << v[row][col] << " ";
        }
        cout << endl;
    }
}

void calculate(vector<vector<int>>& v1, int r1, int c1, vector<vector<int>>& v2, int r2, int c2)
{
    if (c1 == r2)
    {
        
        vector<vector<int>> res(r1, vector<int>(c2));
        for (int row = 0; row < r1; row++)
        {
            for (int col = 0; col < c2; col++)
            {
                
                //for (int k = 0; k < c1; ++k){
                int k = 0;
                while(k < c1){
                    cout << row << k << " * " << k <<row << " || ";
                    res[row][col] += v1[row][k] * v2[k][row];
                    ++k;
                }
                
                cout << res[row][col] << "  ";
                cout << "End 1 " << endl;
            }
        }
        cout << "\nThe Result: \n";
        
        print_matrix(v1, r1, c1); cout << endl;
        print_matrix(v2, r2, c2); cout << endl;
        print_matrix(res, r1, c2);
        
    }
    else
    {
        cout << "Error: These two Matrices Can't be Multiplied\n";
    }
}

void multiply()
{
    cout << "================\nFirst Matrix:" << endl;
    int rows1, columns1;
    cout << "Num of Rows: "; cin >> rows1;
    cout << "Num of Columns: "; cin >> columns1;
    vector<vector<int>> v1(rows1, vector<int>(columns1));
    read_matrix(v1, rows1, columns1);

    cout << "================\Second Matrix:" << endl;
    int rows2, columns2;
    cout << "Num of Rows: "; cin >> rows2;
    cout << "Num of Columns: "; cin >> columns2;
    vector<vector<int>> v2(rows2, vector<int>(columns2));
    read_matrix(v2, rows2, columns2);

    //Final Result
    calculate(v1, rows1, columns1, v2, rows2, columns2);

}

void user()
{
    while (true)
    {
        int choice = minu();
        if (choice == 1)
            multiply();
        else
            break;
    }
    
}

int main()
{
    user();
    
    return 0;
}


