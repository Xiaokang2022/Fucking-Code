import <algorithm>;

template <typename T = int>
void bubble_sort(T* arr, int n) {
    for (; n > 1; n--) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
        }
    }
}