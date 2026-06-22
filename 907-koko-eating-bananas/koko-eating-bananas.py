class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:

        def isPossible(speed):
            time = 0

            for pile in piles:
                time += pile // speed
                if pile % speed != 0:
                    time += 1

            return time <= h

        left, right = 1, max(piles)
        ans = -1

        while left <= right:
            mid = (left + right) // 2

            if isPossible(mid):
                ans = mid
                right = mid - 1
            else:
                left = mid + 1

        return ans