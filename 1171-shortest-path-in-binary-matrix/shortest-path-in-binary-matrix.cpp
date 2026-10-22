class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)return -1;
        int n=grid.size();
        queue<pair<int,pair<int,int>>> qu;
        qu.push({1,{0,0}});
        vector<vector<int>> vis(n,vector<int>(n,0));
        vis[0][0]=1;
        while(!qu.empty()){
            auto it=qu.front();
            qu.pop();
            int dist=it.first;
            int row=it.second.first,col=it.second.second;
            if(row==n-1 && col==n-1)return dist;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nrow=row+i,ncol=col+j;
                    if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol]==0 && !vis[nrow][ncol]){
                        qu.push({dist+1,{nrow,ncol}});
                        vis[nrow][ncol]=1;
                    }
                }
            }
        }
        return -1;
    }
};