#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

int MochilaMemoPD(int profit[], int weight[], int capacity, int i, int j, vector < vector <int> >& Memo, int value)
{
while(Memo[i][j] < 0 && j < Memo[0].size() && i < Memo.size() )
{
    if( j < weight[i-1])
    {
        value = MochilaMemoPD(profit, weight, capacity,  i-1, j, Memo, value);
    }else
    {
        value = max(  MochilaMemoPD(profit, weight, capacity,  i-1, j, Memo, value), profit[i-1] + MochilaMemoPD(profit, weight, capacity, i-1, j - weight[i-1], Memo, value) );

    }

     Memo[i][j] = value;
     j = j + 1;
     if( j == Memo[0].size() && i < Memo.size()-1 )
        {
             j = 0;
             i = i + 1;

        }
}
return Memo[i][j];

}

int main()
{
int n = 10000;
int weight[n];
int profit[n];
int capacity = 49297;
int l = capacity;
vector < int > aux(l+1,-1);
vector < vector <int> > Memo(n+1, aux);

for(int j = 0; j < l + 1; j++)
{
    Memo[0][j] = 0;
}
ifstream dados("dados10000.txt");
for(int i = 0; i< n; i++){
    dados >> profit[i];
    dados >> weight[i];
}
dados.close();

MochilaMemoPD(profit, weight, capacity, 1, 0, Memo, 0 );

cout << Memo[n][l] << "\n";


}