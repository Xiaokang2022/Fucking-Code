function straight_insertion_sort<T extends number | string>(arr: T[]): void {
    // 外循环：遍历所有要被排序的元素
    for (let i = 1; i < arr.length; i++) {
        let tmp = arr[i]; // 取出待排序的元素
        let j = i - 1; // 向左寻找的起始索引
        // 内循环：向左边寻找待排序元素应该的位置
        while (j >= 0 && tmp < arr[j]) { // 到该插入时停止内循环(1)
            arr[j + 1] = arr[j]; // 右移
            j--;
        }
        arr[j + 1] = tmp; // 插入
    }
}