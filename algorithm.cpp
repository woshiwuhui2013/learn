// a file to learn programm

/* 零钱兑换：贪心 */
int coinChangeGreedy(vector<int> &coins, int amt) {
    // 假设 coins 列表有序
    int i = coins.size() - 1;
    int count = 0;
    // 循环进行贪心选择，直到无剩余金额
    while (amt > 0) {
        // 找到小于且最接近剩余金额的硬币
        while (i > 0 && coins[i] > amt) {
            i--;
        }
        // 选择 coins[i]
        amt -= coins[i];
        count++;
    }
    // 若未找到可行方案，则返回 -1
    return amt == 0 ? count : -1;
}


/* 物品 */
class Item {
  public:
    int w; // 物品重量
    int v; // 物品价值

    Item(int w, int v) : w(w), v(v) {
    }
};

/* 分数背包：贪心 */
double fractionalKnapsack(vector<int> &wgt, vector<int> &val, int cap) {
    // 创建物品列表，包含两个属性：重量、价值
    vector<Item> items;
    for (int i = 0; i < wgt.size(); i++) {
        items.push_back(Item(wgt[i], val[i]));
    }
    // 按照单位价值 item.v / item.w 从高到低进行排序
    sort(items.begin(), items.end(), [](Item &a, Item &b) { return (double)a.v / a.w > (double)b.v / b.w; });
    // 循环贪心选择
    double res = 0;
    for (auto &item : items) {
        if (item.w <= cap) {
            // 若剩余容量充足，则将当前物品整个装进背包
            res += item.v;
            cap -= item.w;
        } else {
            // 若剩余容量不足，则将当前物品的一部分装进背包
            res += (double)item.v / item.w * cap;
            // 已无剩余容量，因此跳出循环
            break;
        }
    }
    return res;
}

/**
输入一个数组 ，数组中的每个元素代表一个垂直隔板的高度。数组中的任意两个隔板，以及它们之间的空间可以组成一个容器。

容器的容量等于高度和宽度的乘积（即面积），其中高度由较短的隔板决定，宽度是两个隔板的数组索引之差。

请在数组中选择两个隔板，使得组成的容器的容量最大，返回最大容量。
*/

/* 最大容量：贪心 */

/*
方案
设数组长度为
 ，两个隔板的组合数量（即状态总数）为

 个。最直接地，我们可以穷举所有状态，从而求得最大容量，时间复杂度为
 。
*/
int maxCapacity(vector<int> &ht) {
    // 初始化 i, j 分列数组两端
    int i = 0, j = ht.size() - 1;
    // 初始最大容量为 0
    int res = 0;
    // 循环贪心选择，直至两板相遇
    while (i < j) {
        // 更新最大容量
        int cap = min(ht[i], ht[j]) * (j - i);
        res = max(res, cap);
        // 向内移动短板
        if (ht[i] < ht[j]) {
            i++;
        } else {
            j--;
        }
    }
    return res;
}

// add 2
// add 4
// add 5

// add test pr open

// add close pr
// addd ew pr to issue
// add for 59

// add for 63
// add 1
// add 2

//add 3

//add test binding

//add test binding 2


