#pragma once

#include <iostream>
#include <vector>

class Slide {
private:
	std::string _title;
	std::vector<std::string> _lines;
	Slide(const Slide& other);
	Slide& operator=(const Slide& other);
public:
	Slide(const std::string& header, const std::vector<std::string>& lines);
	~Slide();
	const std::string getTitle() const;
	void setTitle(const std::string& title);
	const std::vector<std::string> getLines() const;
	void addLine(const std::string& line);
};