// Amicable numbers are two different numbers related in such a way that the sum
// of the proper divisors of each is equal to the other number.
// source: https://en.wikipedia.org/wiki/Amicable_numbers

#include <algorithm>
#include <array>
#include <execution>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

constexpr uint64_t LIMIT = 1'000'000;

uint64_t get_sum_of_factors(uint64_t num) {
  uint64_t total = 1;
  for (uint64_t i = 2, end = num / 2 + 1; i < end; ++i) {
    if (num % i == 0) {
      total += i;
    }
  }

  return total;
}

int main() {
  std::array<uint64_t, LIMIT + 1> sum_of_factors;
  // initialize the array with the values from 0 to LIMIT
  std::iota(sum_of_factors.begin(), sum_of_factors.end(), 0);

  // in case TBB are not available, just remove the first argument which specifies the execution policy
  std::transform(
      std::execution::par_unseq,
      sum_of_factors.begin(),
      sum_of_factors.end(),
      sum_of_factors.begin(),
      get_sum_of_factors);

  std::vector<std::pair<uint64_t, uint64_t>> amicable_pairs;

  for (uint64_t i = 1, end = LIMIT + 1; i < end; ++i) {
    uint64_t sum_of_factors_of_i = sum_of_factors[i];
    uint64_t sum_of_factors_of_sum;

    // if sum is greater than LIMIT, we don't have the sum_of_factors of sum in the array, so get it here on the fly
    if (sum_of_factors_of_i >= LIMIT) {
      sum_of_factors_of_sum = get_sum_of_factors(sum_of_factors_of_i);
    } else {
      sum_of_factors_of_sum = sum_of_factors[sum_of_factors_of_i];
    }

    // we need to exclude perfect numbers, i.e. numbers which are equal to the sum of their proper divisors
    if (i == sum_of_factors_of_sum && i != sum_of_factors_of_i) {
      amicable_pairs.emplace_back(i, sum_of_factors_of_i);
    }
  }

  for (auto it = amicable_pairs.begin(), end = amicable_pairs.end(); it != end; ++it) {
    // print the amicable pairs in increasing order and exclude duplicates, i.e. (x, y) and (y, x)
    if (it->first > it->second) {
      continue;
    }

    // find where the second member of the pair is in the vector, to determine if they are twins
    auto find_it = std::find_if(it, end, [it](auto const &p) { return p.first == it->second; });

    std::cout << it->first << " " << it->second;
    if (std::distance(it, find_it) == 1) {
      std::cout << " twins!";
    }
    std::cout << '\n';
  }

  return 0;
}
