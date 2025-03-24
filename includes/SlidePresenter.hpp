#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include "Slide.hpp"

class SlidePresenter {
private:
	std::vector<Slide> _slides;
	int _width;
	int _height;
	SlidePresenter(const SlidePresenter& other);
	SlidePresenter& operator=(const SlidePresenter& other);
	void showSlide(const Slide& slide) const;
	void updateScreenInfo();
	void addSlide(const Slide& slide);
public:
	SlidePresenter();
	~SlidePresenter();
	void initSlides(const std::string& slidePath);
	void runPresentation();
};