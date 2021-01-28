#pragma once

#include <string>
#include <map>

using deck = std::map<const std::string, unsigned int>;
using probabilities = std::map<const std::string, const float>;

class Deck {
	public:
		Deck(
			const unsigned int deck_size,
			deck const& cards
		);

		const float get_probability(std::string const& card);
		
		probabilities get_probabilities();

	private:
		const float calculate_probability(const unsigned int remaining);

		const unsigned int m_deck_size;
		deck m_cards;
};