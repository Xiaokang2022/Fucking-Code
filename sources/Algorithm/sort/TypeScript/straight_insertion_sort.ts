function straight_insertion_sort<T extends number | string>(arr: T[]): void {
    let j; // 当前被比较元素的索引
    for (let i = 1; i < arr.length; i++) {
        let tmp = arr[i]; // 取出不确定位置的元素
        for (j = i - 1; j >= 0 && tmp < arr[j]; j--) // 稳定性关键点(1)
            arr[j + 1] = arr[j]; // 右移
        arr[j + 1] = tmp; // 插入
    }
}