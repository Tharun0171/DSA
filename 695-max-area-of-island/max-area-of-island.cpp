class Solution {
public:
    int bfs(vector<vector<int>>& vis,vector<vector<int>>& grid,int row,int col){
        int sum=0;
        queue<pair<int,int>> q;
        vis[row][col]=1;
        q.push({row,col});
        int dr[]={-1,0,1,0},dc[]={0,1,0,-1};
        while(!q.empty()){
            auto it=q.front();
            int row=it.first,col=it.second;sum++;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+dr[i],ncol=col+dc[i];
                if(nrow>=0 && ncol>=0 && nrow<grid.size() && ncol<grid[0].size() && !vis[nrow][ncol] && grid[nrow][ncol]){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
        return sum;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && !vis[i][j]){
                    maxi=max(maxi,bfs(vis,grid,i,j));
                }
            }
        }
        return maxi;
    }
};