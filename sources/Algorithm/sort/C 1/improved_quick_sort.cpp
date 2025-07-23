import <algorithm>;

// 获取中位数的索引
template <typename T = int>
int median(T* arr, int n) {
    T l = arr[0], m = arr[n / 2], r = arr[n - 1];
    if ((m >= l && l >= r) || (m <= l && l <= r))
        return 0;
    if ((m >= r && r >= l) || (m <= r && r <= l))
        return n - 1;
    return n / 2;
}

// 三数取中的改进版快速排序
export template <typename T = int>
void improved_quick_sort(T* arr, int n) {
    if (n <= 1)
        return;
    std::swap(arr[0], arr[median(arr, n)]);  // 三数取中
    int k = 1;  // 最左边大于 arr[0] 的数索引
    for (int i = 1; i < n; i++)
        if (arr[i] < arr[0])  // 小于 arr[0] 就和最左边的大于 arr[0] 的数换位
            std::swap(arr[i], arr[k++]);
    std::swap(arr[0], arr[k - 1]);  // 将 arr[0] 移至中间
    improved_quick_sort(arr, k - 1);
    improved_quick_sort(arr + k, n - k);
}