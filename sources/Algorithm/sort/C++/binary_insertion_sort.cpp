template <typename T = int>
void binary_insertion_sort(T* arr, int n) {
    T tmp;
    int l, r, m;  // 左右中
    for (int i = 1; i < n; i++) {
        tmp = arr[i];  // 取出
        l = 0;
        r = i - 1;
        while (l <= r) {  // 二分查找
            m = (l + r) / 2;
            if (tmp < arr[m])  // 稳定性关键点
                r = m - 1;
            else
                l = m + 1;
        }
        for (r = i - 1; r >= l; r--)  // 重用r
            arr[r + 1] = arr[r];  // 移位
        arr[l] = tmp;  // 插入
    }
}