#include <boost/math/constants/constants.hpp>
#include <boost/multiprecision/cpp_bin_float.hpp>

using namespace boost::multiprecision;

// Static class
class Dpi
{
public:
    static void init();

    // Any of the pixel size convert function is DPI scaled

    // Convert font point size to pixel size
    // https://accessibility.psu.edu/legibility/fontsize
    static int ptToPx(int pt);

    // Multiply number with dpiMultiplier
    static int multiply(int number);

    // Try scale object inherted from QWidget and QRect
    static void scale_qWidgetRect(QWidget *widget);

    // Default font pixel size, convert from point size in config
    static int defaultFontSize_pixel;

private:
    // Disallow creating an instance of this object
    Dpi();

    static cpp_bin_float_single zoomLevel;
    const static cpp_bin_float_single percentage;

    static cpp_bin_float_single dpiMultiplier;
    static cpp_bin_float_single pointToPixelMultiplier;

    // It seems Qt use 1/72 as internal dpi calculation
    const static cpp_bin_float_single assumeQtPointEachInch;
    // But Windows use 96/1 as internal dpi calculation
    const static cpp_bin_float_single assumeOsPointEachInch;

    static int defaultFontSize_point;
};
