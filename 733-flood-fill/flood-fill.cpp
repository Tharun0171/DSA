class Solution {
private:
    void findConnectUsingBFS(vector<vector<int>>& vis,vector<vector<int>>& image,int row,int col,int ref,int color){
        vis[row][col]=1;
        image[row][col]=color;
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            row=q.front().first;
            col=q.front().second;
            q.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nrow=row+i;
                    int ncol=col+j;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && image[nrow][ncol]==ref && (abs(i)!=abs(j))){
                        image[nrow][ncol]=color;
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ref=image[sr][sc];
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        findConnectUsingBFS(vis,image,sr,sc,ref,color);
        return image;
    }
};