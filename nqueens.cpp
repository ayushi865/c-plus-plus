class Solution {
public:
    vector<string> empty_board(int n)
    {
        vector<string> board;
        for(int i=0;i<n;i++)
        {
            board.push_back(string(n,'.'));
        }
        return board;
    }
    bool is_valid(vector<string>& board,int n, int row, int col)
    {
        for(int i=0;i<n;i++)
        {
            if(board[row][i]=='Q') return false;
            if(board[i][col]=='Q') return false;
            int j = col - (row - i);
            if(j>=0 && j<n && board[i][j] == 'Q') return false;
            int k = col + (row - i);
            if(k>=0 && k<n && board[i][k] == 'Q') return false;
        }
        return true;
    }
    bool search(set<vector<string>>& solutions, vector<string>& board,int n, int q_cnt, int pos)
    {
        if(q_cnt==n) 
        {
            solutions.insert(board);
            return true;
        }
        
        for(int p=pos; p<n*n; p++)
        {
            int row = p/n;
            int col = p%n;
            if(is_valid(board, n, row, col))
            {
                board[row][col]='Q';
                search(solutions, board, n, q_cnt+1, p+1);
                board[row][col]='.';
            }            
        }
        return false;
    }
    vector<vector<string>> solveNQueens(int n) {
        set<vector<string>> solutions;

        auto board = empty_board(n);
        search(solutions, board, n, 0, 0);
        
        vector<vector<string>> res;
        for(auto board: solutions)
            res.push_back(board);
        
        return res;
    }
};
