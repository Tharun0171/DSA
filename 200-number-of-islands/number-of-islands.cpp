class Solution {
private:
    void findConnectUsingBFS(vector<vector<int>>& vis,vector<vector<char>>& grid,int row,int col){
        vis[row][col]=1;
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        q.push({row,col});
        while(!q.empty()){
            row=q.front().first;
            col=q.front().second;
            q.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nrow=row+i;
                    int ncol=col+j;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1' && (abs(i)!=abs(j))){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    findConnectUsingBFS(vis,grid,i,j);
                }
            }
        }
        return cnt;
    }
};