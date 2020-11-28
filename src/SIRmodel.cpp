#include "SIRmodel.h"

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
void SIR::setParams(float beta, float gamma, float csi)
{
	this->beta = beta;
	this->gamma = gamma;
	this->csi = csi;
}

void SIR::setBeta(float beta){
	this->beta = beta;
}

void SIR::setGamma(float gamma){
	this->gamma = gamma;
}

void SIR::setCsi(float csi){
	this->csi = csi;
}

float SIR::getBeta(){return beta;}

float SIR::getGamma(){return gamma;}

float SIR::getCsi(){return csi;}

std::vector<float> SIR::getS(){ return S; };

std::vector<float> SIR::getI(){ return I; };

std::vector<float> SIR::getR(){ return R; };
	
//MODEL FUNCTIONS
void SIR::initialize(float S, float I, float R)
{
	this->S.push_back(S);
	this->I.push_back(I);
	this->R.push_back(R);
	T = S + I + R;
}

void SIR::reset()
{
	//Clear all the data
	beta = .0;
	gamma = .0;
	csi = .0;
	S.clear();
	I.clear();
	R.clear();
}
	
void SIR::run(int pred_days)
{
	while(pred_days--){
		float currS = S.front();
		float currI = I.front();
		S.push_back(S.front() - beta * S.front() * I.front() / T);
		I.push_back(I.front() + beta * currS * I.front() / T - gamma * I.front());
		R.push_back(R.front() + gamma * currI);
	}
}
/*
float SIR::calc_fitness(std::vector<int> predicted, std::vector<int> goal)

{	
	float sum = 0;
	for(int i=0; i<int(predicted.size()); i++)
		sum += abs(predicted[i]-goal[i]);
	return sum;
}

std::vector<float> SIR::fitness()
{
	std::vector<float> temp;	
   	temp.push_back(calc_fitness(S, _file.get_realS()));
	temp.push_back(calc_fitness(I, _file.get_realI()));
	temp.push_back(calc_fitness(R, _file.get_realR()));
	return temp;
}
*/
