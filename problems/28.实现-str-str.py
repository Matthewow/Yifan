#
# @lc app=leetcode.cn id=28 lang=python
#
# [28] 实现 strStr()
#

# @lc code=start
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        for i in range(len(haystack)):
            index = i
            for j in range(len(needle)):
                if len(haystack) - index < len(needle):
                    break
                if haystack[i] == needle[j]:
                    i+=1
                    if j == len(needle)-1:
                        return index
                    continue
                else:
                    break
        return -1
# @lc code=end

