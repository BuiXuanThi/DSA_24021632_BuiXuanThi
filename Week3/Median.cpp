#include <iostream>
#include <vector>
#include <algorithm> 
#include <climits>   
#include <iomanip>   
#include"Priority_Queue_withHeap.h"
using namespace std;
//------------MEDIAN-----------------
void timTrungVi(const vector<int>& nums) {
    PriorityQueueMax lower_half; // Nua duoi (Max Heap)
    PriorityQueueMin upper_half; // Nua tren (Min Heap)

    cout << fixed << setprecision(1);

    for (int num : nums) {
        // 1. Chen vao heap phu hop
        if (lower_half.isEmpty() || num <= lower_half.max())
            lower_half.insert(num);
        else
            upper_half.insert(num);

        // 2. Can bang lai hai heap (chenh lech size <= 1)
        if (lower_half.size() > upper_half.size() + 1)
            upper_half.insert(lower_half.delMax());
        else if (upper_half.size() > lower_half.size())
            lower_half.insert(upper_half.delMin());

        // 3. Tinh trung vi
        double median;
        if (lower_half.size() == upper_half.size())
            median = (lower_half.max() + upper_half.min()) / 2.0;
        else
            median = lower_half.max();

        // 4. In trung vi hien tai
        cout << median << endl;
    }
}
//-------------MAINTEST---------------------
int main() {
    vector<int> nums = { 5, 15, 1, 3 };
    timTrungVi(nums);
    return 0;
}