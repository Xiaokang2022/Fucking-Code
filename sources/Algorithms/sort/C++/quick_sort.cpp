import <algorithm>;

template <typename T = int>
void quick_sort(T* arr, int n) {
    if (n <= 1)
        return;
    int k = 1;  // 最左边大于 arr[0] 的数索引
    for (int i = 1; i < n; i++)
        if (arr[i] < arr[0])  // 小于 arr[0] 就和最左边的大于 arr[0] 的数换位
            std::swap(arr[i], arr[k++]);
    std::swap(arr[0], arr[k - 1]);  // 将 arr[0] 移至中间
    quick_sort(arr, k - 1);
    quick_sort(arr + k, n - k);
}