# Wuziqi
国科大C++大作业-五子棋程序

## 项目简介
本项目使用C++实现五子棋程序，分为人人对战和人机对战两种模式。
项目关键技术：
- 五子胜利、黑子三三禁手、四四禁手、长连禁手的判别。
- AI使用PVM搜索算法进行搜索，搜索范围是以上一步棋为中心的5x5的方格，搜索深度为2。

## 编译代码
g++ -std=c++11 -O2 main.cpp src/*.cpp -I./include -o main

## 界面展示

- 双人对弈

<img src="pic\图片1.png" alt="图片1" style="zoom:25%;" />

- 人机对弈

<img src="pic\图片2.png" alt="图片2" style="zoom:25%;" />
