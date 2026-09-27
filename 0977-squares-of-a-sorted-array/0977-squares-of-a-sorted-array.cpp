class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        vector<int> answer(nums.size());

        int i = 0;
        int j = nums.size() - 1;
        int k = nums.size() - 1;

        while (i <= j) {

            int leftSquare = nums[i] * nums[i];
            int rightSquare = nums[j] * nums[j];

            if (leftSquare > rightSquare) {
                answer[k] = leftSquare;
                i++;
            }
            else {
                answer[k] = rightSquare;
                j--;
            }

            k--;
        }

        return answer;
    }
};