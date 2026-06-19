class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        res = []
        board = [["."] * n for _ in range(n)]
        cols = [0] * n
        diag1 = [0] * (2 * n - 1)
        diag2 = [0] * (2 * n - 1)
        def backtrack(row):
            if row == n:
                res.append(["".join(board[i]) for i in range(n)])
                return
            for col in range(n):
                if cols[col] or diag1[row + col] or diag2[row - col + n - 1]:
                    continue
                board[row][col] = "Q"
                cols[col] = diag1[row + col] = diag2[row - col + n - 1] = 1
                backtrack(row + 1)
                board[row][col] = "."
                cols[col] = diag1[row + col] = diag2[row - col + n - 1] = 0
        backtrack(0)
        return res
        