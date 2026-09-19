# MyDB

MyDB 是一个使用 C++20 从零实现的教学型 Mini DBMS。项目主要参考
*Build Your Own Database From Scratch*，使用现代 C++ 翻译原书实现，同时保持核心存储算法和设计原理不变。

## 当前基线：原始表文件存储

`v0.0-raw-table` 是用于对照的初始版本。它把固定的 `User` 表直接存入二进制文件，目前支持：

- 追加用户；
- 拒绝重复的用户 ID；
- 通过终端菜单读取全部用户。

这个版本还没有 Page、B+Tree、索引、事务和 SQL 引擎。程序运行生成的 `*.table` 文件属于本地数据，不由 Git 跟踪。
该版本的源码保存在 `examples/raw_table/`。

## 构建和运行

```bash
cmake -S . -B build
cmake --build build
./build/raw_table_example
```

下一阶段将从原书 Chapter 4 的 B+Tree Node 二进制布局开始实现。
