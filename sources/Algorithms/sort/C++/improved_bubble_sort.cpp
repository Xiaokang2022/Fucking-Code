import <algorithm>;

template <typename T = int>
void improved_bubble_sort(T* arr, int n) {
    for (bool flag = true; n > 1 && flag; n--) {
        flag = false;
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
    }
}