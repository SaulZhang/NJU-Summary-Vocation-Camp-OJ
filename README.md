# 南大夏令营机试题目汇总
根据博客上收集的题目还原试题,有的没有测试样例的就自己造了几组，每一题的后面的link中都有代码题解。

### 2016

- A.最大连续字段和<b>[here](https://github.com/SaulZhang/NJU-Summary-Vocation-Camp-OJ/blob/master/2016A.cpp)</b>

- B.无向图最长单源路径<b>[here](https://github.com/SaulZhang/NJU-Summary-Vocation-Camp-OJ/blob/master/2016B.cpp)</b>

- C.表示式求值：形如(3*2+3/5)+1*5<b>[here](https://github.com/SaulZhang/NJU-Summary-Vocation-Camp-OJ/blob/master/2016C.cpp)</b>

- D.求树上最长的路径长度<b>[here](https://github.com/SaulZhang/NJU-Summary-Vocation-Camp-OJ/blob/master/2016D.cpp)</b>

### 2017

- A.给定一个n层的满二叉树，不存在的结点用-1表示，同时给定一个sum，问从根结点到达叶节点有哪些路径使得点权和刚好为sum。从左到右输出所有满足条件的路径。<b>[here](https://github.com/SaulZhang/NJU-Summary-Vocation-Camp-OJ/blob/master/2017A.cpp)</b>

- B.给定n个非负的整数，每个数代表这个数可以跳跃的最远距离，同时每个数字之间的距离已知，问能不能从最左边的点跳到最右边<b>[here](https://github.com/SaulZhang/NJU-Summary-Vocation-Camp-OJ/blob/master/2017B.cpp)</b>

- C.给定由IF，THEN，ELSE，BEGIN，END构成的一组语句，判断该语句的嵌套结构是否符合语法规范<b>[here](https://github.com/SaulZhang/NJU-Summary-Vocation-Camp-OJ/blob/master/2017C.cpp)</b>

- D.给定一组数，问从给定的数组中选取3个数作为三角形的不同边，一共有多少中符合条件的选法<b>[here](https://github.com/SaulZhang/NJU-Summary-Vocation-Camp-OJ/blob/master/2017D.cpp)</b>

### 2018

(南京市内高校)
- A.给出一个多叉树(多于二叉)的先序遍历和后序遍历，(每个节点以字符串标识)，求该树的深度。没有数据范围.<b>[here](https://github.com/SaulZhang/NJU-Summary-Vocation-Camp-OJ/blob/master/2018-1-A.cpp)</b>

- B.第二题:给出初始单词，终止单词，以及词典，所有单词均为长度相等的小写字母串，求从初始单词变换到终止单词的路径长度。每次变换只允许改变一个字符，且所有中间单词只能是词典中的，若不能做到则输出0。样例：<br>
  hit<br>
  cog<br>
  hot dot dog cog dig
该样例中hit hot dot dog cog路径长度为5.
数据范围：词典单词数<=20000，串长度<=5.
<b>[here](https://github.com/SaulZhang/NJU-Summary-Vocation-Camp-OJ/blob/master/2018-1-B.cpp)</b>
- C.第三题:一台机器有ni张面值为ki的纸币，给定一个c，求小于等于c的一个最大金额，使得机器能恰好给出。数据范围：C<=100000，ni<=1000，ki<=1000，种类数<=10.<b>[here](https://github.com/SaulZhang/NJU-Summary-Vocation-Camp-OJ/blob/master/2018-1-C.cpp)</b>

(南京市外高校)
第一组
- A.Count number of binary strings without consecutive 1’s Given a positive integer n(3≤n≤90), count all possible distinct binary strings of length n such that there are no consecutive 1's .  
  Input:  2 <br>
  Output: 3 // The 3 strings are 00, 01, 10 
  Input:  3 <br>
  Output: 5 // The 5 strings are 000, 001, 010, 100, 101
<b>[here](https://github.com/SaulZhang/NJU-Summary-Vocation-Camp-OJ/blob/master/2018-2-A.cpp)</b>

- B.给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。<b>[here](https://github.com/SaulZhang/NJU-Summary-Vocation-Camp-OJ/blob/master/2018-2-B.cpp)</b>

- C.双向LIS [POJ1836](http://poj.org/problem?id=1836)<b>[here](https://github.com/SaulZhang/NJU-Summary-Vocation-Camp-OJ/blob/master/2018-2-C.cpp)</b>

第二组

- A.给定正整数n（n≤40），从1到n中随机选择n-1个数，并将它们以随机顺序连接为字符串s，这意味着在1和n之间有一个缺失的数字。你能找到那个缺失的数字吗？（请注意在某些情况下答案不唯一，此时你只需要找到一个有效的答案。）<b>[here](https://github.com/SaulZhang/NJU-Summary-Vocation-Camp-OJ/blob/master/2018-3-A.cpp)</b>

- B.动态规划[poj1018](http://poj.org/problem?id=1018)<b>[here](https://github.com/SaulZhang/NJU-Summary-Vocation-Camp-OJ/blob/master/2018-3-B.cpp)</b>

- C.最大子矩阵问题[poj1050](http://poj.org/problem?id=1050)<b>[here](https://github.com/SaulZhang/NJU-Summary-Vocation-Camp-OJ/blob/master/2018-3-C.cpp)</b>
