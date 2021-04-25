// Copyright 2021 Solovev Alexandr

#include "include/mergesort.h"

#include <algorithm>
#include <random>
#include <vector>
#include <iostream>
std::vector<double> MergeSort::createRandomVector(int vec_size) {
    if (vec_size <= 0) throw "Vector's size must be > 0.";
    if (vec_size %2 != 0) throw "Vector's size must be even";
    std::random_device rand_d;
    std::mt19937 gen(rand_d());
    std::vector<double> res_vec(vec_size);

    for (int i = 0; i < vec_size; i++)
        res_vec[i] = static_cast<double>(gen() % 256) - 75.0;

    return res_vec;
}

void MergeSort::compexch(double a, double b)
{
    if (b < a)
        std::swap(a, b);
}

void MergeSort::shuffle(std::vector<double> *a, int l, int r)
{
    auto half = (unsigned int) (l + r) / 2;
    std::vector<double> tmp(a->size());
    int i, j;
    for (i = l, j = 0; i <= r; i += 2, j++)
    {
        tmp[i] = a->at(l + j);
        tmp[i + 1] = a->at(half + j + 1);
    }
    for (auto i = l; i < r; i++)
       a->at(i) = tmp[i];
}

void MergeSort::unshuffle(std::vector<double> *a, int l, int r)
{
    auto half = (unsigned int) (l + r) / 2;
    std::vector<double> tmp(a->size());
    int i, j;
    for (i = l, j =0; i<=r; i += 2, j++)
    {
        tmp[l + j] = a->at(i);
        tmp[half + j + 1] = a->at(i + 1);
    }
    for (auto i = l; i < r; i++)
        a->at(i)  = tmp[i];
}

void MergeSort::LocalSort(std::vector<double> *a, int l, int r)
{
    std::vector<double> tmp(r - l);
    int count = r - l;
    for (auto i = 0; i < count; i++)
        tmp[i] = a->at(l+i);
    std::sort(tmp.begin(), tmp.end());
    for (auto i = 0; i < count; i++)
        a->at(l+i) = tmp[i];
}

void MergeSort::OddEvenMergeSort(std::vector<double> *a, int l, int r)
{   
    if (r == l + 1) 
    {   
        if( a->at(l)> a->at(r))
        {
            std::swap(a->at(l), a->at(r));
        }
        return;
    }
    if (r < l + 2) return; 
    unshuffle(a, l, r);
    auto half = (int) (l + r) / 2;
    OddEvenMergeSort(a, l, half);
    LocalSort(a, l, r);
    OddEvenMergeSort(a, half + 1, r);
    LocalSort(a, l, r);
    shuffle(a, l, r); 
    LocalSort(a, l, r);     
}