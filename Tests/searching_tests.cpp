#include <gtest/gtest.h>
#include "../search_algorithms/linear_search.cpp"
#include "../search_algorithms/iterative_binary_search.cpp"
#include "../search_algorithms/recursive_binary_search.cpp"


TEST(LinearSearch, LinearSearchAllTestCases){
    std::vector<int> vectorOfIntegers{ 1, 3,4,6,8,9,0,10,4,11 };
    std::vector<const char*> vectorOfStrings{ "1", "3","4","6","8","9","0","10","4", "11" };

    ASSERT_EQ(linearSearch(vectorOfIntegers, 4), 2);
    ASSERT_EQ(linearSearch(vectorOfStrings, static_cast<const char*>("0")), 6);
    ASSERT_EQ(linearSearch(vectorOfStrings, static_cast<const char*>("111")), -1);
}

TEST(BinarySearch, BinarySearchTests){
    std::vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9 };

    ASSERT_EQ(iterative_binary_search(v, 1), 0);
    ASSERT_EQ(recursive_binary_search(v, 1), 0);

    ASSERT_EQ(iterative_binary_search(v,9), 8);
    ASSERT_EQ(recursive_binary_search(v,9), 8);

    ASSERT_EQ(iterative_binary_search(v,5), 4);
    ASSERT_EQ(recursive_binary_search(v,5), 4);

    ASSERT_EQ(iterative_binary_search(v, 41), -1);
    ASSERT_EQ(recursive_binary_search(v, 41), -1);
}