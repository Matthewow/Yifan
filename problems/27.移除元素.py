#
# @lc app=leetcode.cn id=27 lang=python3
#
# [27] 移除元素
#

# @lc code=start
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i,n = 0,len(nums)
        for j in range(n):
            if nums[j] != val:
                nums[i] = nums[j]
                i += 1
        print(nums)

# @lc code=end

