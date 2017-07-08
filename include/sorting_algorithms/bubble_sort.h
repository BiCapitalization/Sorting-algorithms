#pragma once

#include <iterator>
#include <algorithm>
#include <functional>

namespace sorting_algorithms {
	template <typename FwdIterator, typename Comparator = std::less<>>
	void bubble_sort(FwdIterator begin, FwdIterator end, Comparator cmp = {}) {
		if (std::distance(begin, end) < 2) {
			return;
		}

		bool swapped;
		do {
			swapped = false;
			for (auto i = begin, i_next = std::next(i); i_next != end; ++i,
					++i_next) {
				auto& val0 = *i_next;
				auto& val1 = *i;
				if (cmp(val0, val1)) {
					std::iter_swap(&val1, &val0);
					swapped = true;
				}
			}
		} while (swapped);
	}
}
