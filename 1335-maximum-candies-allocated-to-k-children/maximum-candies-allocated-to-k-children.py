class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:

        def isPossible(x):
            children = 0

            for pile in candies:
                children += pile // x

            return children >= k

        left, right = 1, max(candies)
        ans = 0

        while left <= right:
            mid = (left + right) // 2

            if isPossible(mid):
                ans = mid
                left = mid + 1
            else:
                right = mid - 1

        return ans