#include "Slide.hpp"

Slide::Slide(const std::string& title, const std::vector<std::string>& lines) : _title(title), _lines(lines){}

Slide::~Slide() {}

Slide::Slide(const Slide& other) : _title(other._title), _lines(other._lines) {}

Slide& Slide::operator=(const Slide& other) {
	if (this == &other) return *this;
	_title = other._title;
	_lines = other._lines;
	return *this;
}

const std::string Slide::getTitle() const {
	return _title;
}

void Slide::setTitle(const std::string& title) {
	_title = title;
}

const std::vector<std::string> Slide::getLines() const {
	return _lines;
}

void Slide::addLine(const std::string& line) {
	_lines.emplace_back(line);
}