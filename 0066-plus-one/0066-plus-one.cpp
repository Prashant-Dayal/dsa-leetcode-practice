#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = static_cast<int>(digits.size());

        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }

        // Every digit was 9, so result is 1 followed by n zeros.
        digits.insert(digits.begin(), 1);
        return digits;
    }
};