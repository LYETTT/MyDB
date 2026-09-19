# MyDB

MyDB is a teaching-oriented Mini DBMS written in C++20. The project follows
*Build Your Own Database From Scratch* while translating the implementation to
modern C++ without changing the core storage algorithms.

## Current baseline: raw table storage

The `v0.0-raw-table` baseline is a deliberately small comparison version. It
stores a fixed `User` table directly in a binary file and currently supports:

- appending a user;
- rejecting duplicate user IDs;
- reading all users through a terminal menu.

This baseline does not yet contain pages, a B+Tree, indexes, transactions, or a
SQL engine. Runtime `*.table` files are local data and are not tracked by Git.

## Build

```bash
cmake -S . -B build
cmake --build build
./build/MyDB
```

The next development stage starts with the Chapter 4 B+Tree node binary layout.
