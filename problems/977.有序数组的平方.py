#
# @lc app=leetcode.cn id=977 lang=python3
#
# [977] 有序数组的平方
#

# @lc code=start
class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        left,right,x = 0,len(nums) - 1,len(nums) - 1
        a = [0]*len(nums)
        while left <= right:
            if(pow(nums[left],2)> pow(nums[right],2)):
                a[x] = pow(nums[left],2)
                x -= 1 
                left += 1
            else:
                a[x] = pow(nums[right],2)
                x -= 1 
                right -= 1
        return a 
# @lc code=end

