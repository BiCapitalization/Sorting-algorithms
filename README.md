# Sorting-algorithms
Several popular sorting algorithms implemented in modern C++

## What is this?
This project comprises implementations of some of the most widely used sorting
algorithms in modern C++ (the version used is C++14). Currently, there are
implementations of
 * Bubble sort
 * Insertion sort
 * Selection sort

## Structure
The project comprises an `include/` directory which contains the file
`sorting_algorithms.h`, which itself includes all other sorting algorithm
headers (which can be found in `include/sorting_algorithms/`). Usually,
including `sorting_algorithms.h` should suffice, but if compilation time is a
concern, you may also opt to include each header separately as needed.  

All sorting algorithms live in the `sorting_algorithms` namespace,
and have the general structure
```c++
template <typename [IteratorType], typename Comparator = std::less<>>
void [name]_sort([IteratorType] begin, [IteratorType] end,
		Comparator com = {}) { /*...*/ }
```
where `[IteratorType]` is one of `FwdIterator`, `Bidirectionaliterator` and
`[name]` denotes the name of the algorithm (e.g. `bubble` for Bubble sort).
