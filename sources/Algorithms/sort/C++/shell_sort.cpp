template <typename T = int>
void straight_insertion_sort(T* arr, int n, int l = 1) {  // l 表示元素间隔，默认为 1，被 ShellSort 所调用
    T tmp;
    int j;  // 位置
    for (int i = l; i < n; i++) {
        tmp = arr[i];  // 取出
        for (j = i - l; j >= 0 && tmp < arr[j]; j -= l)  // 稳定性关键点
            arr[j + l] = arr[j];  // 移位
        arr[j + l] = tmp;  // 插入
    }
}

template <typename T = int>
void shell_sort(T* arr, int n) {
    for (int s = n / 2; s; s >>= 1) {  // 分组
        straight_insertion_sort(arr, n, s);  // 排序
    }
}