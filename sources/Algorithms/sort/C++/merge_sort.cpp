import <memory>;

// 合并操作
template <typename T = int>
void merge(T* arr, int n) {
    T* tmp = new T[n];  // 申请辅助数组
    int i = 0, j = n / 2;
    for (int k = 0; k < n; k++) {
        if (i == n / 2)  // 左边被用完
            tmp[k] = arr[j++];
        else if (j == n)  // 右边被用完
            tmp[k] = arr[i++];
        else  // 都没有被用完
            tmp[k] = arr[i] < arr[j] ? arr[i++] : arr[j++];
    }
    std::memcpy(arr, tmp, n * sizeof(T));
    delete[] tmp;
}

/// 归并排序
/// 稳定性：是
/// 内部操作：是
/// 时间复杂度：O(nlog₂n)
/// 空间复杂度：O(log₂n)
export template <typename T = int>
void merge_sort(T* arr, int n) {
    if (n <= 1)
        return;
    int mid = n / 2;
    merge_sort(arr, mid);
    merge_sort(arr + mid, n - mid);
    merge(arr, n);
}