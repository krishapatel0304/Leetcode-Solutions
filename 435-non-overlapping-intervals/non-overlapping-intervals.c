int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
   if (intervalsSize <= 1) return 0;
    int stack_capacity = intervalsSize * 2;
    int *stack = (int*)malloc(sizeof(int) * stack_capacity);
    int top = -1;
    stack[++top] = 0;
    stack[++top] = intervalsSize - 1;
    while (top >= 0) {
        int right = stack[top--];
        int left  = stack[top--];
        if (left >= right) continue;
        int pivotIdx = left + (right - left) / 2;
        int* tmp = intervals[pivotIdx];
        intervals[pivotIdx] = intervals[right];
        intervals[right] = tmp;
        int* pivot = intervals[right];
        int i = left - 1;
        for (int j = left; j < right; ++j) {
            if (intervals[j][1] <= pivot[1]) {
                ++i;
                tmp = intervals[i];
                intervals[i] = intervals[j];
                intervals[j] = tmp;
            }
        }
        tmp = intervals[i + 1];
        intervals[i + 1] = intervals[right];
        intervals[right] = tmp;
        int p = i + 1;
        if (left < p - 1) { stack[++top] = left; stack[++top] = p - 1; }
        if (p + 1 < right) { stack[++top] = p + 1; stack[++top] = right; }
    }
    free(stack);
    int removals = 0;
    int end = intervals[0][1];
    for (int i = 1; i < intervalsSize; ++i) {
        if (intervals[i][0] < end) ++removals;
        else end = intervals[i][1];
    }
    return removals;
}