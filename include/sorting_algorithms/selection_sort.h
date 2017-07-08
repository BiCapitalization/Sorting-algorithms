#pragma once

#include <utility>
#include <iterator>
#include <algorithm>
#include <functional>

namespace sorting_algorithms {
	template <typename FwdIterator, typename Comparator = std::less<>>
	void selection_sort(FwdIterator begin, FwdIterator end, Comparator cmp = {}) {
		for (FwdIterator current_element = begin; current_element != end;
				++current_element) {
			auto current_value = *current_element; 
			//should be std::optional in C++17
			std::pair<FwdIterator, bool> swap_place =
				std::make_pair(current_element, false);

			for (auto i = std::next(current_element); i != end; ++i) {
				const auto& index_value = *i;
				if (cmp(index_value, current_value)) {
					current_value = index_value;
					swap_place.first = i;
					swap_place.second = true;
				}
			}
			if (swap_place.second) {
				std::iter_swap(swap_place.first, current_element);
			}
		}
	}
}
