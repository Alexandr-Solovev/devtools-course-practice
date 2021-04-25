// Copyright 2021 Solovev Alexandr

#include <vector>

#ifndef MODULES_BATCHER_MERGESORT_INCLUDE_MERGESORT_H_
#define MODULES_BATCHER_MERGESORT_INCLUDE_MERGESORT_H_

namespace MergeSort {
    std::vector<double> createRandomVector(int vec_size);
    void compexch(double a, double b);
    void shuffle(std::vector<double> *a, int l, int r);
    void unshuffle(std::vector<double> *a, int l, int r);
    void LocalSort(std::vector<double> *a, int l, int r);
    void OddEvenMergeSort(std::vector<double> *a, int l, int r);
}

#endif  // MODULES_BATCHER_MERGESORT_INCLUDE_MERGESORT_H_