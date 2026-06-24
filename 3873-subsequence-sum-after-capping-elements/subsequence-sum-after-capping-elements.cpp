class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
         vector<int> zolvarinte =nums;
        int n=zolvarinte.size();

        vector<int> freq(n + 1, 0);
        for (int v : zolvarinte) freq[v]++;

        vector<int> suffixFreq(n + 2, 0);
        for (int i = n; i >= 1; --i) {
            suffixFreq[i] = suffixFreq[i + 1] + freq[i];
        }
         vector<bool> ans(n,false);
        for (int x = 1; x <= n; ++x) {
             vector<pair<int,int>> items;
            for (int v = 1; v < x; ++v) {
                if (freq[v] > 0) items.push_back({v, freq[v]});
            }
            int cnt = suffixFreq[x];
            if (cnt > 0) items.push_back({x, cnt}); 
            bitset<4001>dp;
            dp[0]=1;
            for(auto[val,count]:items){
                int c = count;
                int p = 1;
                while (c > 0) {
                      int take = min(p, c);
                    int add = val * take;
                    if (add <= k) {
                         dp |= (dp << add);
                    }
                    c -= take;
                    p <<= 1;
            }
            if(dp[k])break;
            }
            ans[x-1]=dp[k];
        }
        return ans;
    }
};