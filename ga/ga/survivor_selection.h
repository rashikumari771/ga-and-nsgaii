#ifndef ENVIRONMENTAL_SELECTION__
#define ENVIRONMENTAL_SELECTION__
#include <vector>


// ----------------------------------------------------------------------
//	The environmental selection mechanism is the key innovation of 
//  the GA algorithm.
//
//  Check Algorithm I in the original paper of NSGA-III.
// ----------------------------------------------------------------------

class CPopulation;
class CReferencePoint;

void SurvivorSelection(CPopulation *pnext, // population in the next generation
							CPopulation *pcur,  // population in the current generation
							size_t PopSize);

#endif
