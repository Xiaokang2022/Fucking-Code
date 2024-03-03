def straight_insertion_sort[T](lst: list[T]) -> None:
    for i in range(1, len(lst)):
        tmp = lst[i]  # 取出不确定位置的元素
        for j in range(i - 1, -1, -1):
            if tmp >= lst[j]:  # 到该插入的位置了(1)
                lst[j + 1] = tmp  # 插入
                break
            lst[j + 1] = lst[j]  # 右移
        else:  # 此处容易忘记，遍历完了表示 tmp 是最小的，虽然但是，它还没有插入啊！
            lst[0] = tmp  # 特殊情况的插入
