#pragma once
#include <algorithm>
#include <iterator>
#include <vector>
#include <numeric>


// Returns a vector of sorted indexes based on supplied vector
template<class T>
std::vector<int> create_permutation(const std::vector<T>& vec)
{
	std::vector<int> temp(vec.size());
	std::iota(temp.begin(), temp.end(), 0);
	std::sort(temp.begin(), temp.end(), [&vec](int x, int y) {return vec[x] < vec[y]; });
	return std::move(temp);
}

// Returns a new vector, sorted according to permutation
template<class T>
std::vector<T> apply_permutation(const std::vector<T>& original, const std::vector<int>& permutation)
{
	std::vector<T> temp(original.size());
	std::transform(permutation.cbegin(), permutation.cend(), temp.begin(), [&](int index) {
		return original[index];
	});
	return std::move(temp);
}