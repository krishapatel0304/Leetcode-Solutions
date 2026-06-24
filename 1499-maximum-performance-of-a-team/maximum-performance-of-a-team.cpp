class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
         const int MOD = 1e9 + 7;
        vector<pair<int,int>> engineers;
        for (int i = 0; i < n; i++) {
            engineers.push_back({efficiency[i], speed[i]});
        }
        sort(engineers.rbegin(), engineers.rend());

        long long speedSum = 0, maxPerf = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap; 
        for (auto& [eff, spd] : engineers) {
            minHeap.push(spd);
            speedSum += spd;
            if ((int)minHeap.size() > k) {
                speedSum -= minHeap.top();
                minHeap.pop();
            }
            maxPerf = max(maxPerf, speedSum * eff);
        }

        return (int)(maxPerf % MOD);
    }
};