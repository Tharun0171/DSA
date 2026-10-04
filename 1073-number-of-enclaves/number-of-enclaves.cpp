class Solution {
private:
    void findBFS(vector<vector<int>>& vis,vector<vector<int>>& grid){
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0||i==n-1||j==m-1) && grid[i][j]==1 && !vis[i][j]){
                    q.push({i,j});
                    //vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            int row=q.front().first,col=q.front().second;
            q.pop();
            vis[row][col]=1;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nrow=row+i;
                    int ncol=col+j;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1 && (abs(i)!=abs(j))){
                        q.push({nrow,ncol});
                        vis[nrow][ncol]=1;
                    }
                }
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int cnt=0;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        findBFS(vis,grid);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]==1)cnt++;
            }
        }
        return cnt;
    }
};