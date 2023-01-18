#include <cstdio>
#include <gtest/gtest.h>
namespace nhq
{
int str2int([[maybe_unused]]const char* str)
{
    int ret = 0;
    for (; *str != '\0'; str++)
    {
        if (*str < '0' || *str > '9') {
            return -1;
        }
        ret = ret * 10 + *str - '0';
    }

    return ret;
}
} // namespace nhq

TEST(STR2INT, Invalid) {
    EXPECT_EQ(nhq::str2int("a"), -1);
}

TEST(STR2INT, OneCharacter) {
    EXPECT_EQ(nhq::str2int("1"), 1);
    EXPECT_EQ(nhq::str2int("0"), 0);
}

TEST(STR2INT, TwoCharacters) {
    EXPECT_EQ(nhq::str2int("11"), 11);
    EXPECT_EQ(nhq::str2int("23"), 23);
}

TEST(STR2INT, ManyCharacters) {
    EXPECT_EQ(nhq::str2int("1109345"), 1109345);
    EXPECT_EQ(nhq::str2int("90876561"), 90876561);
}

