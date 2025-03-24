#include <iostream>
#include "SlidePresenter.hpp"

int main (int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Usage: " << std::string(argv[0]) << " spathToSlides.md\n";
		return 1;
	}

	SlidePresenter presentation;

	try {
		presentation.initSlides(argv[1]);
		presentation.startPresentation();
	} catch (const std::runtime_error& e) {
		std::cout << "Caught error: " << e.what() << "\n";
		return 1;
	}

	return 0;
}