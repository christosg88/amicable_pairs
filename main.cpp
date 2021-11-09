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
  std::iota(sum_of_factors.begin(), sum_of_factors.end(), 0);

  std::transform(
      std::execution::par_unseq,
      sum_of_factors.begin(),
      sum_of_factors.end(),
      sum_of_factors.begin(),
      get_sum_of_factors);

  // in case TBB are not available
  //  for (uint64_t i = 1, end = LIMIT + 1; i < end; ++i) {
  //    sum_of_factors[i] = get_sum_of_factors(i);
  //  }

  std::vector<std::pair<uint64_t, uint64_t>> amicable_pairs;

  for (uint64_t i = 1, end = LIMIT + 1; i < end; ++i) {
    auto sum = sum_of_factors[i];
    if (sum >= LIMIT) {
      continue;
    }
    if (sum_of_factors[sum] == i && i != sum) {
      amicable_pairs.emplace_back(i, sum);
    }
  }

  for (auto it = amicable_pairs.begin(), end = amicable_pairs.end(); it != end; ++it) {
    if (it->first > it->second) {
      continue;
    }

    std::cout << it->first << " " << it->second;
    auto find_it =
        std::find_if(amicable_pairs.begin(), amicable_pairs.end(), [it](std::pair<uint64_t, uint64_t> const &p) {
          return p.first == it->second;
        });
    if (std::distance(it, find_it) == 1) {
      std::cout << " twins!";
    }
    std::cout << '\n';
  }

  return 0;
}
