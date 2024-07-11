//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool safetyCheck(int newx, int newy,vector<vector<int>> &m,vector<vector<bool>> &visited, int n ) {
        if(newx < 0 || newy < 0 || newx >=n || newy >= n ) {
            //out of bound
            return false;
        }
        if(visited[newx][newy] == true) {
            //already visited
            return false;
        }
        if(m[newx][newy] == 0) {
            //blocked space
            return false;
        }
        //valid case
        return true;
    }
    
    void solvePath(vector<vector<int>> &m,vector<vector<bool>> &visited, int n,vector<string> &ans,
                int src_x, int src_y, int destx,int desty, string output) {
        //base case
        if(src_x == destx && src_y == desty) {
            ans.push_back(output);
            return;
        }
        
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        char move[] = {'U','D','L','R'};
        
        for(int i=0; i<4; i++) {
            int newx = src_x + dx[i];
            int newy = src_y + dy[i];
            char movement = move[i];
            
            if(safetyCheck(newx,newy,m,visited,n)) {
                visited[newx][newy] = true;
                output.push_back(movement);
                solvePath(m,visited,n,ans,newx,newy,destx,desty,output);
                //backtracking
                output.pop_back();
                visited[newx][newy] = false;
            }
            
        }
        
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<bool> > visited(n, vector<bool>(n,0));
        int src_x = 0;
        int src_y = 0;
        visited[0][0] = true;
        int destx = n-1;
        int desty = n-1;
        string output = "";
        if(m[0][0] == 0) {
            return ans;
        }
        
        
        solvePath(m,visited,n,ans,src_x,src_y,destx,desty,output);
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends