
#include "gnuplot_interface.h"
#include <iostream>
#include <sstream>

using namespace std;

// ---------------------------------------------------------
// Ref:
// http://user.frdm.info/ckhung/b/ma/gnuplot.php
// ---------------------------------------------------------

Gnuplot::Gnuplot()
{
	// with -persist option you will see the windows as your program ends
	//gnuplotpipe=_popen("gnuplot -persist","w");
	//without that option you will not see the window

	// because I choose the terminal to output files so I don't want to see the window

	gnuplotpipe = _popen("gnuplot", "w");

	if (!gnuplotpipe)
	{
		cerr << ("Gnuplot not found !");
	}
}
// ---------------------------------------------------------
Gnuplot::~Gnuplot()
{
	fprintf(gnuplotpipe, "exit\n");
	_pclose(gnuplotpipe);
}
// ---------------------------------------------------------
void Gnuplot::operator()(const string& command)
{
	fprintf(gnuplotpipe, "%s\n", command.c_str());
	fflush(gnuplotpipe);
	// flush is necessary, nothing gets plotted else
}
// ---------------------------------------------------------
void Gnuplot::set_title(const std::string& title)
{
	ostringstream ss;
	ss << "set title \"" << title << "\"";
	operator()(ss.str());
}
// ---------------------------------------------------------
void Gnuplot::plot(const std::string& fname, std::size_t x, std::size_t y)
{
	ostringstream ss;
	ss << "plot \"" << fname << "\" using " << x << ":" << y;
	operator()(ss.str());
}
// ---------------------------------------------------------
void Gnuplot::splot(const std::string& fname, std::size_t x, std::size_t y, std::size_t z)
{
	ostringstream ss;

	ss << "splot \"" << fname << "\" using " << x << ":" << y << ":" << z;
	operator()(ss.str());
}
// ---------------------------------------------------------