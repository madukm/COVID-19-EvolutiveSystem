#include "SIR_model.h"

#include <iostream>
#include <vector>

SIR::SIR():
	beta(.0), gamma(.0), csi(.0)
{
	S.clear();
	I.clear();
	R.clear();
}

SIR::~SIR(){

}

void SIR::set_params(float beta, float gamma, float csi){
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

void SIR::initialize_model(double S, double I, double R){
	this->S.push_back(S);
	this->I.push_back(I);
	this->R.push_back(R);
	N = S + I + R;
}
void SIR::run_model(int days){
	
	while(days--){
		double currS = S.front();
		double currI = I.front();
		S.push_back(S.front() - beta * S.front() * I.front() / N);
		I.push_back(I.front() + beta * currS * I.front() / N - gamma * I.front());
		R.push_back(R.front() + gamma * currI);
	}
}


