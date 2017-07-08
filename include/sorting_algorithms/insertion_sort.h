#pragma once

#include <iterator>
#include <algorithm>
#include <functional>

namespace sorting_algorithms {
	template <typename BidirectionalIterator,
			 typename Comparator = std::less<>>
	void insertion_sort(BidirectionalIterator begin, BidirectionalIterator end,
			Comparator cmp = {}) {

		if (std::distance(begin, end) < 2) {
			return;
		}

		for (auto current_element = std::next(begin); current_element != end;
				++current_element) {
			for (auto i = std::prev(current_element), i_next = current_element;
					i_next != begin; --i, --i_next) {
				auto& i_val = *i;
				auto& i_next_val = *i_next;
				if (cmp(i_val, i_next_val)) {
					break;
				}
				std::iter_swap(&i_val, &i_next_val);
			}
		}
	}
}
