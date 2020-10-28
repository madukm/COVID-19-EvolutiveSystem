#include "SIR_model.h"

#include <iostream>
#include <vector>
#include <string>

//CONSTRUCTORS & DESTRUCTORS
SIR::SIR():
	beta(.0), gamma(.0), csi(.0)
{
	//Clear all the data
	S.clear();
	I.clear();
	R.clear();
}

SIR::~SIR(){

}

//SETTER & GETTERS
void SIR::set_params(float beta, float gamma, float csi)
{
	this->beta = beta;
	this->gamma = gamma;
	this->csi = csi;
}

float SIR::get_beta(){
	return beta;
}

float SIR::get_gamma(){
	return gamma;
}

float SIR::get_csi(){
	return csi;
}

//MODEL FUNCTIONS
void SIR::initialize_model(float S, float I, float R)
{
	this->S.push_back(S);
	this->I.push_back(I);
	this->R.push_back(R);
	T = S + I + R;
}

void SIR::reset_model()
{
	//Clear all the data
	beta = .0;
	gamma = .0;
	csi = .0;
	_fitness.clear();
	S.clear();
	I.clear();
	R.clear();
}

	
void SIR::run_model(int pred_days)
{
	while(pred_days--){
		float currS = S.front();
		float currI = I.front();
		S.push_back(S.front() - beta * S.front() * I.front() / T);
		I.push_back(I.front() + beta * currS * I.front() / T - gamma * I.front());
		R.push_back(R.front() + gamma * currI);
	}
}

/*float SIR::set_fitness(std::vector<float> fitness)
{
	
}*/
float SIR::calc_fitness(std::vector<int> predicted, std::vector<int> goal)

{	
	float sum = 0;
	for(int i=0; i<int(predicted.size()); i++)
		sum += abs(predicted[i]-goal[i]);
	return sum;
}
/**
float SIR::fitness(Condition condition, int days)
{
	switch(state){
		case S:
			calc_fitness(S, data.get_realS());
			return ;
			
		case I:
			return ;
		
		case R:

			return ;
	}	
}*/
