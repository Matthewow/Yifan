/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size(), columns = matrix[0].size();
        vector<int> result;
        //设定上下左右四个方向
        int left = 0,right = columns - 1, top = 0, bottom = rows -1;
        //当最
        while(left<=right && top<=bottom){
            //从左到右
            for (int column = left; column <= right; column++) {
                result.push_back(matrix[top][column]);
            }
            //从上到下
            for (int row = top + 1; row <= bottom; row++) {
                result.push_back(matrix[row][right]);
            }
            //判断这一层是不是只有一行
            if (left < right && top < bottom) {
                //从右到左
                for (int column = right - 1; column > left; column--) {
                    result.push_back(matrix[bottom][column]);
                }
                //从下到上
                for (int row = bottom; row > top; row--) {
                    result.push_back(matrix[row][left]);
                }
            }
            //缩小一层
            left++;
            right--;
            top++;
            bottom--;
        }
        return result;
    }
};
// @lc code=end

