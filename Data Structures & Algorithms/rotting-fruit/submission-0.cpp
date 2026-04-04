class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        vector<int>dx = {0,0,1,-1};
        vector<int>dy = {1,-1,0,0};

        int min = 0;

        while(!q.empty() && fresh > 0){
            int size = q.size();
            min++;

            for(int i = 0 ; i < size; i++){
                auto[x,y] = q.front();
                q.pop();
                for(int d = 0 ; d < 4 ; d++){
                    int nx = x+dx[d];
                    int ny = y+dy[d];

                    if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                        fresh--;
                    }
                }
            }
        }
        return fresh == 0 ? min : -1;
    }
};
