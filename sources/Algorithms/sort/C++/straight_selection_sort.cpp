import <iostream>;

template <typename T = int>
void straight_selection_sort(T* arr, int n) {
    int ind;
    for (int i = 0; i < n - 1; i++) {
        ind = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[ind])
                ind = j;
        if (ind != i)
            std::swap(arr[i], arr[ind]);
    }
}