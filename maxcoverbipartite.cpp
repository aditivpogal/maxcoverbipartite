#include <iostream>
#include <string.h>
using namespace std;
#define M 6
#define N 6

bool bpm(bool bpGraph[M][N], int u,
bool seen[], int matchR[])
{
for (int v = 0; v < N; v++)
{
if (bpGraph[u][v] && !seen[v])
{
seen[v] = true;

if (matchR[v] < 0 || bpm(bpGraph, matchR[v],
seen, matchR))
{
matchR[v] = u;
return true;
}
}
}
return false;
}

int maxBPM(bool bpGraph[M][N])
{
int matchR[N];
memset(matchR, -1, sizeof(matchR));

int result = 0;
for (int u = 0; u < M; u++)
{
bool seen[N];
memset(seen, 0, sizeof(seen));

if (bpm(bpGraph, u, seen, matchR))
result++;
}
return result;
}

int main()
{
int i,j,a[20][20],r,c;
bool bpGraph[M][N];
cout<<"Enter the number of rows and columns"<<endl;
cin>>r;
cin>>c;

cout<<"Enter the matrix"<<endl;
for(i=0;i<M;i++) {
for(j=0;j<N;j++) {
cin>>bpGraph[i][j];
}
}

cout << "Maximum number of applicants that can get job is "
<< maxBPM(bpGraph);

return 0;
}

