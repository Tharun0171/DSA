class Solution {
private:
    void findBFS(vector<vector<int>>& vis,vector<vector<char>>& board,int row,int col){
        int n=board.size(),m=board[0].size();
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            row=q.front().first;
            col=q.front().second;
            vis[row][col]=1;
            q.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nrow=row+i;
                    int ncol=col+j;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O' && (abs(i)!=abs(j))){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && board[i][j]=='O' && !vis[i][j]){
                    findBFS(vis,board,i,j);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j])board[i][j]='X';
            }
        }
    }
};