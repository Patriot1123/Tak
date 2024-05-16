

#include <vector>
#include <cstdint>
#include <gtest/gtest.h>

std::vector<std::uint8_t> toDigits(long long num) {
    std::vector<std::uint8_t> digits;
    do {
        digits.insert(digits.begin(), num % 10);
        num /= 10;
    } while (num != 0);
    return digits;
}


TEST(toDigitsTest, integers)
{
    std::vector<int> iv{ 1200, 2450, 643, -7896, 90345 };
    std::vector<std::uint8_t> expected_iv_digits{ 1, 2, 0, 0, 2, 4, 5, 0, 6, 4, 3, 7, 8, 9, 6, 9, 0, 3, 4, 5 };

    for (size_t i = 0; i < iv.size(); ++i) {
        EXPECT_EQ(toDigits(iv[i]), expected_iv_digits);
    }
}

TEST(toDigitsTest, longlong)
{
    std::vector<long long> llv{ 234567, -987654321, 908070, 14253647 };
    std::vector<std::uint8_t> expected_llv_digits{ 2, 3, 4, 5, 6, 7, 9, 8, 7, 6, 5, 4, 3, 2, 1, 9, 0, 8, 0, 7, 0, 1, 4, 2, 5, 3, 6, 4, 7 };

    for (size_t i = 0; i < llv.size(); ++i) {
        EXPECT_EQ(toDigits(llv[i]), expected_llv_digits);
    }
}