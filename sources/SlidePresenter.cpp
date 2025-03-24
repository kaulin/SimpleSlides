#include <iterator>
#include <fstream>
#include "SlidePresenter.hpp"

SlidePresenter::SlidePresenter() {}

SlidePresenter::~SlidePresenter() {}

void SlidePresenter::initSlides(const std::string& slidePath) {
	std::ifstream file(slidePath);
	if (!file.is_open() || !file.good()) {
		throw std::runtime_error("Can't read from file: " + slidePath);
	}
	std::string line;
	std::slide
	while (getline(file, line)) {
		if (!line.empty() && line)
	}
}

void SlidePresenter::runPresentation() {
	auto currentSlide = _slides.begin();

	while (true) {
		showSlide(*currentSlide);
	}
}

SlidePresenter::SlidePresenter(const SlidePresenter& other) : _slides(other._slides) {}

SlidePresenter& SlidePresenter::operator=(const SlidePresenter& other) {
	if (this == &other) return *this;
	_slides = other._slides;
	return *this;
}

void SlidePresenter::showSlide(const Slide& slide) const {
	std::string title = slide.getTitle();
	std::vector<std::string> lines = slide.getLines();
	std::cout << "\n\n\n";
	std::cout << slide.getTitle() << "\n";
	for (std::string line : lines)
		std::cout << line << "\n";
	for (int i = 3 + lines.size(); i < _height; i++)
		std::cout << "\n"; 
}

void SlidePresenter::updateScreenInfo() {
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	_width = w.ws_col;
	_height = w.ws_row;
}

void SlidePresenter::addSlide(const Slide& slide) {
	_slides.emplace_back(slide);
}