---
comments: true
---

直接插入排序（Straight Insertion Sort）是一种最简单的排序方法，其基本操作是将一条记录插入到已排好的有序表中，从而得到一个新的、记录数量增 1 的有序表。[^1]

## 一、实现思路

### 1.1 步骤

-   [ ] 将整个数组分成两部分，左边有序部分和右边无序部分；
-   [ ] 在排序的过程中，不用管右边部分的顺序，只需要保证左边始终有序；
-   [ ] 从左到右遍历整个数组，每遍历到一个新的元素，都将其取出(1)；
        { .annotate}

    1.  因为无法马上确定其位置，需要对其进行排序

-   [ ] 然后在保证顺序的左边部分中寻找其应该的位置；
-   [ ] 即，从该元素位置触发，向左遍历有序的部分，并判断是否应该插入；
-   [ ] 如不能插入，则将判断的元素向右移位，反之插入；
-   [ ] 如此反复直至所有元素都遍历完成，那么整个数组都是有序的了；

### 1.2 图解

#### 1.2.1 动画图解

!!! tip "说明"

    动画图解暂未更新，敬请期待！

=== "步骤 01"

    ![png](#)

=== "步骤 02"

    ![png](#)

=== "步骤 03"

    ![png](#)

=== "步骤 04"

    ![png](#)

=== "步骤 05"

    ![png](#)

=== "步骤 06"

    ![png](#)

=== "步骤 07"

    ![png](#)

#### 1.2.2 流程图图解

??? note "流程图"

    ```mermaid
    flowchart TB
        START(["开始"])
        END(["结束"])
        in1[/"接收参数：T* arr, int n"/]
        if1{"判断：j ≥ 0 ?"}
        if2{"判断：tmp < arr[i] ?"}
        if3{"判断：i < n ?"}
        def1("定义：T tmp")
        def2("定义：int j")
        def3("定义：int i")
        op1["右移：arr[j + 1] = arr[j]"]
        op2["插入：arr[j + 1] = tmp"]
        op3["j--"]
        op4["i++"]
        op5["赋值：j = i - 1"]
        op6["赋值：tmp = arr[i]"]
        op7["赋值：i = 1"]

        START --> in1 --> def2 --> def3 --> op7 --> if3 --True--> END
        if3 --True--> def1 --> op6 --> op5 --> if1 --False--> op2 --> op4 --> if3
        if1 --True--> if2 --False--> op2
        if2 --True--> op1 --> op3 --> if1
    ```

## 二、实现代码

### 2.1 多语言版本

=== "🟣 C 17"

    ```c
    --8<-- "sources/Algorithm/sort/C/straight_insertion_sort.c"
    ```

    1. 相等时，被比较元素原来在前面的就不用右移了，保证稳定性

    --8<-- "pythontutor/Algorithm/sort/C/straight_insertion_sort.md"

=== "🔴 C++ 20"

    ```cpp
    --8<-- "sources/Algorithm/sort/C++/straight_insertion_sort.cpp"
    ```

    1. 相等时，被比较元素原来在前面的就不用右移了，保证稳定性

    --8<-- "pythontutor/Algorithm/sort/C++/straight_insertion_sort.md"

=== "🔵 Python 3"

    ```python
    --8<-- "sources/Algorithm/sort/Python/straight_insertion_sort.py"
    ```

    1. 相等时，被比较元素原来在前面的就不用右移了，保证稳定性

    --8<-- "pythontutor/Algorithm/sort/Python/straight_insertion_sort.md"

=== "🟠 Java 21"

    ```java
    --8<-- "sources/Algorithm/sort/Java/straight_insertion_sort.java"
    ```

    1. 相等时，被比较元素原来在前面的就不用右移了，保证稳定性

    --8<-- "pythontutor/Algorithm/sort/Java/straight_insertion_sort.md"

=== "🟢 C# 12"

    ```csharp
    --8<-- "sources/Algorithm/sort/C#/straight_insertion_sort.cs"
    ```

    1. 相等时，被比较元素原来在前面的就不用右移了，保证稳定性

    --8<-- "pythontutor/Algorithm/sort/C#/straight_insertion_sort.md"

=== "🟡 TypeScript 5"

    ```typescript
    --8<-- "sources/Algorithm/sort/TypeScript/straight_insertion_sort.ts"
    ```

    1. 相等时，被比较元素原来在前面的就不用右移了，保证稳定性

    --8<-- "pythontutor/Algorithm/sort/TypeScript/straight_insertion_sort.md"

### 2.2 测试用例

=== "🔻 输入数据"

    ```text
    9
    6 28 13 72 85 39 41 6 20
    ```

=== "🔺 输出数据"

    ```text
    6 6 13 20 28 39 41 72 85
    ```

## 三、算法性质

### 3.1 时空复杂度

|   复杂度   |        😀 最好情况         |         😭 最坏情况          | 🫤 平均情况 |
| :--------: | :------------------------: | :--------------------------: | :--------: |
| 时间复杂度 | $O(n)${ title="数组顺序" } | $O(n^2)${ title="数组逆序" } |  $O(n^2)$  |
| 空间复杂度 |           $O(1)$           |            $O(1)$            |   $O(1)$   |

#### 3.1.1 时间复杂度分析

假设数组大小为 $n$ 。

外循环从左边第 $2$ 个元素(1)开始到右边遍历了数组的每一个元素，即 $n-1$ 个元素被外循环遍历。在每一个内循环中，假设此时待排序元素的索引为 $i$，该元素会反向对左边已遍历（排好序）的元素进行再次遍历，遍历 $i-1$ 次(2)。但每次内循环会在元素插入的时候终止，我们并不知道是在什么时候终止的，但我们知道，这是随机的（取决于数据）。
{ .annotate }

1. 第 1 个元素本身就是有序的，遍历它没有什么意义，直接跳过
2. 💡 思考：遍历有序的部分是否可以改进以提高算法性能呢？

当数组初始为顺序时，每个内循环只需要比较 $1$ 次，反之，当数组逆序的时候，就需要完成全部的遍历过程，即每次内循环要比较 $i-1$ 次，平均下来，每次内循环比较了 $\frac{i-1}{2}$ 次，因此时间复杂度：

数组顺序时，有最好情况：

$$
O(T_n) = O(1 + 1 + 1 + ... + 1) = O(n-1) = O(n)
$$

数组逆序时，有最坏情况：

$$
O(T_n) = O(1 + 2 + 3 + ... + (n-1)) = O\Big(\frac{n(n-1)}{2}\Big) = O(n^2)
$$

平均情况：

$$
O(T_n) = O\Big(\frac{1}{2} + \frac{2}{2} + \frac{3}{2} + ... + \frac{n-1}{2}\Big) = O\Big(\frac{n(n-1)}{4}\Big) = O(n^2)
$$

#### 3.1.2 空间复杂度分析

整个算法的过程中，我们只用了 $1$ 个临时变量来存储被取出来的那个元素，因此空间复杂度：

$$
O(S_n) = O(1)
$$

### 3.2 稳定性与排序方式

|     算法     |  稳定性  | 排序方式 |
| :----------: | :------: | :------: |
| 直接插入排序 | 可以稳定 | 内部排序 |

#### 3.2.1 稳定性分析

能否稳定取决于具体的实现，实现细节没把握好也可能导致不稳定。关键在于对元素比较出现相等情况时是否应该插入的判断。

#### 3.2.2 排序方式分析

排序方式属于内部排序，没有用到外部的空间。

## 四、相关习题

### 4.1 编程题

-   [ ] [洛谷 - P7910 [CSP-J 2021]](https://www.luogu.com.cn/problem/P7910)
-   [ ] [力扣 - 147](https://leetcode.cn/problems/insertion-sort-list/description/)
-   [ ] [力扣 - 面试题 05.01](https://leetcode.cn/problems/insert-into-bits-lcci/description/)

### 4.2 选择题

-   [ ] [牛客 - 试题广场](https://www.nowcoder.com/questionTerminal/4ee287d1d96a4aea9fc83d29e7ce9695?)

[^1]: [直接插入排序 · 百度百科](https://baike.baidu.com/item/%E7%9B%B4%E6%8E%A5%E6%8F%92%E5%85%A5%E6%8E%92%E5%BA%8F/8255911)
