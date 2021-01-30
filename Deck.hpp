#pragma once

#include <string>
#include <tuple>
#include <vector>

/// <summary>
/// A tuple that contains a card's name, quantity, and likelihood to be drawn.
/// </summary>
using card = std::tuple<
	const std::string, // Card Name
	unsigned short int, // Card Count
	float // Card Draw (%) 
>;

/// <summary>
/// The Deck class can be used to determine the quantity of each card in a deck as well as your likelihood to draw it.
/// </summary>
class Deck {
	public:
		/// <summary>
		/// The default constructor for the Deck class.
		/// </summary>
		/// <param name="cards"></param>
		Deck(std::vector<card> cards, const unsigned short deck_size);

		/// <summary>
		/// Prints formatted card probability data to the console.
		/// </summary>
		void get_probabilities() const;

	private:
		/// <summary>
		/// Calculates & sets probability for each card in the deck.
		/// </summary>
		void set_probabilities();
		
		// Private Member Variable(s)
		std::vector<card> m_cards;
		unsigned short m_deck_size;
};