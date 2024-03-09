def straight_insertion_sort[T](lst: list[T]) -> None:
    # 外循环：遍历所有要被排序的元素
    for i in range(1, len(lst)):
        tmp = lst[i]  # 取出待排序的元素
        j = i - 1  # 向左寻找的起始索引
        # 内循环：向左边寻找待排序元素应该的位置
        while j >= 0 and tmp < lst[j]:  # 到该插入时停止内循环(1)
            lst[j + 1] = lst[j]  # 右移
            j -= 1
        lst[j + 1] = tmp  # 插入
