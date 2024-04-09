#ifndef GA__
#define GA__

#include <cstddef>
#include <string>

// ----------------------------------------------------------------------------------

class BProblem;
class CPopulation;

class CGA
{
public:
	explicit CGA(const std::string& inifile_name = "");
	void Solve(CPopulation* solutions, const BProblem& prob);

	const std::string& name() const { return name_; }
private:
	std::string name_;
	std::size_t obj_division_p_;
	std::size_t gen_num_;
	double	pc_, // crossover rate
		pm_, // mutation rate
		eta_c_, // eta in SBX
		eta_m_; // eta in Polynomial Mutation
};


#endif