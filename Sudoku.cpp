#include <iostream>
#include <vector>

using namespace std;

bool checkValor(vector< vector<int> >& v, int l, int c, int k) {
    for (int i = 0; i < 9; i++) { //checa linha e coluna
        
        if (v[i][c] == k || v[l][i] == k) {
            return false;
        }
    }
    int lQ = (l / 3)*3;
    int cQ = (c / 3)*3;
    for (int i = lQ; i < (lQ + 3); i++) {
        for (int j= cQ; j < (cQ + 3); j++) {            
            if (v[i][j] == k) {
                return false;                
            }
        }
    }
    return true;
}

void printVector(vector<vector<int>>& v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

void preencheSudoku(vector<vector<int>>& v, int k, int l) {
    if (l == 8 && k==9) {
        printVector(v);
        cout << endl;
        return;
    }
    else {
        
        for (int c = 0; c < 9; c++) {
            if (v[l][c] == k) {
                if (l == 8) {
                    preencheSudoku(v, ++k, 0);
                    --k;
                }
                else {
                    preencheSudoku(v, k, ++l);
                    --l;
                }
                
                
            }else if (v[l][c] == 0) {
                if (checkValor(v, l, c, k)) {
                    v[l][c] = k;
                    if (l == 8 && k < 10) {                       
                        preencheSudoku(v, ++k, 0);
                        --k;                        
                        v[l][c] = 0;                        
                    }
                    else {                       
                        preencheSudoku(v, k, ++l);
                        --l;
                        v[l][c] = 0;                        
                    }                    
                } 
            }                            
        }        
        return;
        
    }                
            
}

void Sudoku(vector<vector<int>>& v) {
    preencheSudoku(v, 1, 0);
}




int main()
{

   
    vector<vector<int>> v = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    Sudoku(v);

}