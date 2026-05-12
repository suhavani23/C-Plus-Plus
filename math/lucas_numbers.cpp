/**
 * @file
 * @brief n-th [Lucas
 * number](https://en.wikipedia.org/wiki/Lucas_number).
 *
 * @details
 * Iterative implementation to calculate the n-th Lucas number.
 * Lucas numbers are similar to Fibonacci numbers but start with 2 and 1.
 * \f[\text{lucas}(n) = \text{lucas}(n-1) + \text{lucas}(n-2)\f]
 *
 * @see fibonacci.cpp, fibonacci_fast.cpp
 */

#include <cassert>   /// for assert
#include <cstdint>   /// for uint64_t
#include <iostream>  /// for IO operations

/**
 * @namespace math
 * @brief Math algorithms
 */
namespace math {
/**
 * @namespace lucas_numbers
 * @brief Functions for Lucas number sequence
 */
namespace lucas_numbers {
/**
 * @brief Function to compute the n-th Lucas number
 * @param n the index of the Lucas number
 * @returns n-th element of the Lucas sequence
 */
uint64_t lucas(uint64_t n) {
    if (n == 0)
        return 2;
    if (n == 1)
        return 1;

    uint64_t a = 2, b = 1;
    for (uint64_t i = 2; i <= n; i++) {
        uint64_t c = a + b;
        a = b;
        b = c;
    }
    return b;
}
}  // namespace lucas_numbers
}  // namespace math

/**
 * @brief Self-test implementation
 * @returns `void`
 */
static void test() {
    assert(math::lucas_numbers::lucas(0) == 2);
    assert(math::lucas_numbers::lucas(1) == 1);
    assert(math::lucas_numbers::lucas(2) == 3);
    assert(math::lucas_numbers::lucas(3) == 4);
    assert(math::lucas_numbers::lucas(4) == 7);
    assert(math::lucas_numbers::lucas(5) == 11);
    assert(math::lucas_numbers::lucas(6) == 18);
    std::cout << "All tests have passed successfully!\n";
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
    test();  // run self-test implementations
    return 0;
}