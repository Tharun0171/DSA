class Solution {
public:
    long long bfs(vector<vector<int>>& vis,vector<vector<int>>& grid,int val,int r,int c){
        queue<pair<int,pair<int,int>>> q;
        long long sum=0;
        vis[r][c]=1;
        q.push({val,{r,c}});
        int dr[]={-1,0,1,0},dc[]={0,1,0,-1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int value=it.first;sum+=value;
            int row=it.second.first;
            int col=it.second.second;
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0 && ncol>=0 && nrow<grid.size() && ncol<grid[0].size() && !vis[nrow][ncol] && grid[nrow][ncol]){
                    q.push({grid[nrow][ncol],{nrow,ncol}});
                    vis[nrow][ncol]=1;
                }
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        int cnt=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]){
                    long long sum=bfs(vis,grid,grid[i][j],i,j);
                    if(sum%k==0)cnt++;
                }
            }
        }
        return cnt;
    }
};