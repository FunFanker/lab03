#ifndef HISTOGRAM_SHOW_H_INCLUDED
#define HISTOGRAM_SHOW_H_INCLUDED
#include <iostream>
#include <vector>
#include "histogram.h"
using namespace std;
void
svg_begin(double width, double height);

void
svg_end();

void svg_rect(double x, double y, double width, double height, string stroke /*= "blue"*/, string fill /*= "blue"*/);

void svg_text(double left, double baseline, string text);


void
show_histogram_svg(const vector<size_t>& bins);
#endif // HISTOGRAM_SHOW_H_INCLUDED
