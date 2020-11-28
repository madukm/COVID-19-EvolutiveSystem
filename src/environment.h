#ifndef _H_SIMULATOR
#define _H_SIMULATOR

#include <vector>
#include <algorithm>

#include "SIRmodel.h"
#include "../lib/defines.h"

class Environment{
	public:
		Environment(Data *refData);
		~Environment();

		void plotGeneration();
		void run(int steps);

	private:
		Data *_data;
		Data *_refData;		
		SIR *_model;
		
		int _qtyModels;
		
		std::vector<float> _generationFitness;
		int _best; //index of the best
		float fitness(int index);

};

#endif
