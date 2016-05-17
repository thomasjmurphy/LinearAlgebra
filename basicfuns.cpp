#include<vector>
#include<iostream>

using namespace std;

void swap(double &a, double &b)
{
    if(&a == &b){return;}
a = a + b;
b = a - b;
a = a - b;
}

void rowDivide(vector<double> &vec, int index)
{
    double div = vec[index];
    for(int i=0;i<vec.size();i++)
    {
        vec[i] = vec[i]/div;
    }
}

void printMat(vector<vector<double>> &mat)
{
    int cols = mat[0].size();
    int rows = mat.size();
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout << mat[i][j];
        }
        cout << endl;
    }
    cout << endl;
}


void rowReduce(vector<vector<double>> &mat)
{
    int pivot = 0;
    int nextpivot = 0;
    int cols = mat[0].size();
    int rows = mat.size();
    for(int i=0;i<cols;i++)
    {
        nextpivot = pivot;
        while(mat[nextpivot][i] == 0 && nextpivot < rows)
        {
            nextpivot++;
        }
        
        if(mat[nextpivot][i] != 0 && nextpivot < rows)
        {
            for(int k = i;k<cols;k++)
            {
                swap(mat[nextpivot][k],mat[pivot][k]);
            }
            rowDivide(mat[pivot],i);
            for(int k = pivot+1;k<rows;k++)
            {
                double multiplier = mat[k][i];
                for(int l = i;l<cols;l++)
                {
                    mat[k][l] = mat[k][l] - multiplier*mat[pivot][l];
                }
                printMat(mat);
            }
            
            pivot++;
        }
        if(pivot == rows){break;}
    }
}

