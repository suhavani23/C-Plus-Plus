/**
 * @file
 * @brief Implementation of the Collatz Conjecture sequence.
 * @details
 * The Collatz Conjecture states that for any positive integer n,
 * repeatedly applying the following rules will always eventually reach 1:
 * - If n is even: n = n / 2
 * - If n is odd:  n = 3n + 1
 * The number of steps taken to reach 1 is called the Collatz sequence length.
 * Reference: https://en.wikipedia.org/wiki/Collatz_conjecture
 * @author [suhavani23](https://github.com/suhavani23)
 * @see fibonacci.cpp, magic_number.cpp
 */

#include <cassert>   /// for assert
#include <iostream>  /// for std::cout
#include <vector>    /// for std::vector

/**
 * @namespace math
 * @brief Mathematical algorithms
 */
namespace math {

/**
 * @brief Generates the full Collatz sequence starting from n
 * @param n the starting positive integer (must be >= 1)
 * @returns vector containing the full sequence ending at 1
 */
std::vector<uint64_t> collatz_sequence(uint64_t n) {
    std::vector<uint64_t> sequence;
    while (n != 1) {
        sequence.push_back(n);
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
    }
    sequence.push_back(1);
    return sequence;
}

/**
 * @brief Counts the number of steps to reach 1 from n
 * @param n the starting positive integer (must be >= 1)
 * @returns number of steps taken to reach 1
 */
uint64_t collatz_steps(uint64_t n) { return collatz_sequence(n).size() - 1; }

}  // namespace math

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test() {
    // sequence for 6: 6 -> 3 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
    std::vector<uint64_t> expected = {6, 3, 10, 5, 16, 8, 4, 2, 1};
    assert(math::collatz_sequence(6) == expected);

    assert(math::collatz_steps(1) == 0);     // already at 1, zero steps
    assert(math::collatz_steps(6) == 8);     // 8 steps to reach 1
    assert(math::collatz_steps(27) == 111);  // known result

    std::cout << "All tests have successfully passed!\n";
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
    test();  // run self-test implementations
    return 0;
}