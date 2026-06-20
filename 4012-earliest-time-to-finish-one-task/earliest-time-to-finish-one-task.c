int earliestTime(int** tasks, int tasksSize, int* tasksColSize) {
    int minTime= tasks[0][0]+tasks[0][1];
    for(int i=1;i<tasksSize;i++){
        int s=tasks[i][0];
        int t=tasks[i][1];
        int finish=s+t;
        if(finish<minTime){
            minTime=finish;
        }
    }
    return minTime;
}