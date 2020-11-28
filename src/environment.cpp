#include "environment.h"

Environment::Environment(Data *refData):
	_qtyModels(QTY_MODELS), _refData(refData)
{
	
	//Create all models
	_model = new SIR[_qtyModels];			
	
	_generationFitness.resize(_qtyModels);

	for(int i=0; i<_qtyModels; i++)
	{
		_model[i].initialize(1., 0., 0.);
		
		_model[i].setParams((double)rand()/(double)rand(), (double)rand()/(double)rand(), (double)rand()/(double)rand());
		_model[i].run(refData->getDays());
		_generationFitness.push_back(fitness(i));			
	}

	//Evolve models
	do{
		float bestFit;
		
		bestFit = DBL_MAX;

		//Getting the fitness for each model
		for(int i=0; i<_qtyModels; i++)
		{
			_model[i].run(refData->getDays());
			_generationFitness.clear();
			_generationFitness.push_back(fitness(i));
			
			//Getting the best one
	
			if(_generationFitness[i] < bestFit){
				_best = i; //holds the index of the model
				bestFit = _generationFitness[i];
			}
		}
		
		for(int i=0; i<_qtyModels; i++)
		{
			//-----Crossover-----//
			if(_best == i) continue; // Preserves the best	
			_model[i].setBeta( ( _model[i].getBeta() + _model[_best].getBeta() ) / 2. );
			_model[i].setGamma( ( _model[i].getGamma() + _model[_best].getGamma() ) / 2. );
			_model[i].setCsi( ( _model[i].getCsi() + _model[_best].getCsi() ) / 2. );
		}	

	}while(1);


};

Environment::~Environment()
{
	
}

void Environment::plotGeneration()
{

}

void Environment::run(int steps)
{

}

float Environment::fitness(int index)
{
	float sum = 0;
	for(int i=0; i<_refData->getDays(); i++)
	{
		sum += abs( _model[index].getS()[i] - _refData->getS()[i]);
   		sum += abs( _model[index].getI()[i] - _refData->getI()[i]);
   		sum += abs( _model[index].getR()[i] - _refData->getR()[i]);
	}
	return sum;
}

