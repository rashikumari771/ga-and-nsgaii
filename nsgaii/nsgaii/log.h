#ifndef LOG__
#define LOG__

#include <string>
#include <fstream>  // Include <fstream> for std::ios_base and std::ios_base::openmode

class CPopulation;
class Gnuplot;

// Save a population into the designated file.
bool SaveToFile(const std::string& fname, const CPopulation& pop, std::ios_base::openmode mode = std::ios_base::app);

// Show a population by calling gnuplot.
bool ShowPopulation(Gnuplot& gplot, const CPopulation&, const std::string& legend = "pop");

#endif
