import <memory>;

template <typename T = int>
void counting_sort(T* arr, int n) {
    T minnum = *std::min_element(arr, arr + n), maxnum = *std::max_element(arr, arr + n);
    T length = maxnum - minnum;
    T* cnt = new T[length + 1]{}, * tmp = new T[n];  // 计数数组，临时数组
    for (int i = 0; i < n; i++)
        cnt[arr[i] - minnum]++;
    for (int i = length, j = n; i >= 0; i--)  // 逆向填充，保证稳定性
        for (; cnt[i]; cnt[i]--)
            tmp[--j] = i + minnum;
    std::memcpy(arr, tmp, n * sizeof(T));
    delete[] cnt;
    delete[] tmp;
}