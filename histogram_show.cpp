#include "histogram_show.h"
using namespace std;
void
svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg width='" << width << "' height='" << height << "' "
         << "viewBox='0 0 " << width << " " << height << "' "
         << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void
svg_end()
{
    cout << "</svg>\n";
}


void svg_rect(double x, double y, double width, double height, string stroke = "blue", string fill = "blue")
{
    cout << "<rect x='" << x << "' y='" <<y << "' width='"<<width<<" ' height=' "<<height<<" ' stroke='"<<stroke<<"' fill='"<<fill<<"'  />";
}

void svg_text(double left, double baseline, string text)
{
    cout << "<text x='" << left << "' y='" <<baseline << "' > "<<text<<" </text>";
}


void
show_histogram_svg(const vector<size_t>& bins)
{
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double top = 0;
    const size_t SCREEN_WIDTHEN = 30;
    double max_size;
    for (size_t bin : bins)
    {

        max_size=0;
        if (bin>max_size)
            max_size=bin;
    }
    double koef_size=SCREEN_WIDTHEN/max_size;

    for (size_t bin : bins)
    {

        double bin_width = 10 * bin*koef_size;

        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT,"red","blue");
        svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
        top += BIN_HEIGHT;
    }
    svg_end();
}
