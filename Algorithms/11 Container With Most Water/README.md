# [Container With Most Water](https://leetcode.com/problems/container-with-most-water/)

Given n non-negative integers a_1, a_2, ..., a_n, where each represents a point at coordinate (i, a_i). n vertical lines are drawn such that the two endpoints of line i is at (i, a_i) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.

- **[Array](https://leetcode.com/tag/array/)** 
- **[Two Pointers](https://leetcode.com/tag/two-pointers/)**


##Solutions

- **[Container -- 34ms](https://leetcode.com/submissions/detail/22699575/)**
    - 从两头开始算起，保证了宽是从大到小减少的；
    - 然后比较两头的高度：leftH 和 rightH ；
    - 因为是盛水，即求能构成的长方形的面积，所以取 `min(leftH,rightH)`；
    - 比较新构成的面积和原来的比较哪个大，取大的；
    - 如果 `leftH < rightH `，则左边的坐标向前移一步，否则是右边的移动，这个保证了高的那个边得以保留；
    - 直到两个坐标移动到同一点或左边的坐标移动到了右边坐标的右边时说明所有点判断完毕，已经得出了最大区域。


##**附录**
- **[开源GitHub](https://github.com/bbxytl/LeetCodesOJ/blob/master/README.md)** 
- **[GitHub博客](http://bbxytl.github.io/)**
