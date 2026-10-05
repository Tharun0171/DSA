class Solution {
private:
    int findBFS(vector<vector<int>>& vis,vector<vector<int>>& grid){
        int n=grid.size(),m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        int cnt=0,ref=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},cnt});
                }
                else if(grid[i][j]==1)ref++;
            }
        }
        if(ref==0)return 0;
        while(!q.empty()){
            cnt+=1;
            while(q.front().second==cnt-1){
                int row=q.front().first.first;
                int col=q.front().first.second;
                q.pop();
                vis[row][col]=1;
                for(int i=-1;i<=1;i++){
                    for(int j=-1;j<=1;j++){
                        int nrow=row+i;
                        int ncol=col+j;
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] && (abs(i)!=abs(j))){
                            q.push({{nrow,ncol},cnt});
                            vis[nrow][ncol]=1;
                            grid[nrow][ncol]=2;
                        }
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return cnt-1;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int time=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        time=findBFS(vis,grid);
        return time;
    }
};