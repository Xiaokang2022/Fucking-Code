static void straight_insertion_sort<T>(T[] arr) where T : IComparable<T>
{
    int j; // 当前被比较元素的索引
    for (int i = 0; i < arr.Length; i++)
    {
        T tmp = arr[i]; // 取出不确定位置的元素
        for (j = i - 1; j >= 0 && tmp.CompareTo(arr[j]) < 0; j--) // 稳定性关键点(1)
            arr[j + 1] = arr[j]; // 右移
        arr[j + 1] = tmp; // 插入
    }
}