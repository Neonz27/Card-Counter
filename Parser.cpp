#include "Parser.hpp"
#include "Utility.hpp"
#include <fstream>

Parser::Parser(const std::string& file_name) : m_card_quantity(0) {
	std::ifstream deck_file(file_name + ".txt");

	if(deck_file.fail()) {
		throw DeckFileDoesntExist();
	}

	std::string current_line;

	while(std::getline(deck_file, current_line)) {
		const size_t delimeter_position = current_line.find_first_of(' ');

		const std::string name = current_line.substr(delimeter_position + 1);
		const unsigned short int quantity = std::stoi(current_line.substr(0, delimeter_position), nullptr, 0);

		m_cards.push_back(
			std::make_tuple(
				name,
				quantity,
				0.0f
			)
		);

		m_card_quantity += 1;
	}
}