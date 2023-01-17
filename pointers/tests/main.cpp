/*
# https://www.youtube.com/watch?v=9OBISBBZ3CQ&list=PLqCJpWy5Fohfil0gvjzgdV4h29R9kDKtZ&index=3
# https://www.youtube.com/watch?v=j1ZF__Ml5ds&list=PLqCJpWy5Fohfil0gvjzgdV4h29R9kDKtZ&index=5
*/

#include <gtest/gtest.h>

[[nodiscard]] int sum(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum;
}

[[nodiscard]] int sum2(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++, arr++)
    {
        sum += *arr;
    }

    return sum;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void reverse(int *arr, int size)
{
    int *end = &arr[size - 1];
    for (; arr < end; arr++, end--) {
        ::swap(arr, end);
    }
}

TEST(TestSum, OnlyOneMemberArray) {
    int arr[1] = {0};
    EXPECT_EQ(sum(arr, 1), 0);
    EXPECT_EQ(sum(arr, 1), sum2(arr, 1));
}

TEST(TestSum, HasTwoMembersArray) {
    int arr[2] = {1, 5};
    EXPECT_EQ(sum(arr, 2), 6);
    EXPECT_EQ(sum(arr, 2), sum2(arr, 2));
}

TEST(TestSum, HasThreeMembersArray) {
    int arr[3] = {1, 5, -1};
    EXPECT_EQ(sum(arr, 3), 5);
    EXPECT_EQ(sum(arr, 3), sum2(arr, 3));
}

TEST(TestSum, HasManyMembersArray) {
    int arr[] = {1, 5, -1, 0, 8, 9, 4, 5};
    EXPECT_EQ(sum(arr, 8), 31);
    EXPECT_EQ(sum(arr, 8), sum2(arr, 8));
}

TEST(TestReverse, OnlyOneMemberArray) {
    int arr[1] = {1};
    reverse(arr, 1);
    int des[1] = {1};
    for (int i = 0; i < 1; i++) {
        EXPECT_EQ(arr[i], des[i]);
    }
}

TEST(TestReverse, HasTwoMembersArray) {
    int arr[] = {1, 2};
    reverse(arr, 2);
    int des[] = {2, 1};
    for (int i = 0; i < 2; i++) {
        EXPECT_EQ(arr[i], des[i]);
    }
}

TEST(TestReverse, HasThreeMembersArray) {
    int arr[] = {1, 2, 1};
    reverse(arr, 3);
    int des[] = {1, 2, 1};
    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(arr[i], des[i]);
    }
}

TEST(TestReverse, HasManyMembersArray) {
    int arr[] = {1, 2, 1, 4, 3, 2, 5};
    reverse(arr, 7);
    int des[] = {5, 2, 3, 4, 1, 2, 1};
    for (int i = 0; i < 7; i++) {
        EXPECT_EQ(arr[i], des[i]);
    }
}
