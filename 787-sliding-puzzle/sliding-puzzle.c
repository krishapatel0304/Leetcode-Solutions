int slidingPuzzle(int** board, int boardSize, int* boardColSize) {
    char start[7], target[] = "123450";
    int idx = 0;
    for (int i = 0; i < boardSize; i++)
        for (int j = 0; j < boardColSize[i]; j++)
            start[idx++] = board[i][j] + '0';
    start[6] = '\0';

    int moves[6][3] = {
        {1, 3, -1},
        {0, 2, 4}, 
        {1, 5, -1},  
        {0, 4, -1},  
        {1, 3, 5},    
        {2, 4, -1}    
    };

    char queue[1000][7];
    int steps[1000];
    char visited[720][7];
    int front = 0, rear = 0, visitedCount = 0;

    strcpy(queue[rear], start);
    steps[rear++] = 0;
    strcpy(visited[visitedCount++], start);

    while (front < rear) {
        char curr[7];
        strcpy(curr, queue[front]);
        int moveCount = steps[front];
        front++;

        if (strcmp(curr, target) == 0)
            return moveCount;

        int zeroPos = strchr(curr, '0') - curr;

        for (int k = 0; k < 3 && moves[zeroPos][k] != -1; k++) {
            int n = moves[zeroPos][k];
            char next[7];
            strcpy(next, curr);

            char temp = next[zeroPos];
            next[zeroPos] = next[n];
            next[n] = temp;

            int seen = 0;
            for (int i = 0; i < visitedCount; i++) {
                if (strcmp(visited[i], next) == 0) {
                    seen = 1;
                    break;
                }
            }
            if (!seen) {
                strcpy(visited[visitedCount++], next);
                strcpy(queue[rear], next);
                steps[rear++] = moveCount + 1;
            }
        }
    }
    return -1;
}