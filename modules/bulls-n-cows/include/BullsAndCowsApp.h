// Copyright 2021 Solovev Aleksandr

#ifndef MODULES_QSORT_INCLUDE_QSORTER_H_
#define MODULES_QSORT_INCLUDE_QSORTER_H_

#include <string>

class BullsAndCowsApp {
 public:
    BullsAndCowsApp() = default;
    std::string operator()(int argc, const char* argv[],
                           int* retcode = nullptr) const;

 private:
    std::string help(const std::string& filename) const;
};


#endif  // MODULES_QSORT_INCLUDE_QSORTER_H_
