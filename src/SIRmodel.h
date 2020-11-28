/**
 * Class for SIR Model.
 * Inside comments: later I will keep adding more parameters for better models, but I want to keep track of them.
 */

#ifndef _H_SIR_MODEL
#define _H_SIR_MODEL

#include <vector>
#include <string>
#include <cfloat>

#include "data.h"

class SIR{
	public:
		SIR();
		~SIR();

		//Getters & Setters
		void setParams(float beta, float gamma, float csi);
		
		void setBeta(float beta);
		void setGamma(float gamma);
		void setCsi(float csi);

		float getBeta();
		float getGamma();
		float getCsi();
		
		std::vector<float> getS();
		std::vector<float> getI();
		std::vector<float> getR();
	
		void initialize(float S, float I, float R);
		void reset();
		void run(int days);

		std::vector<float> fitness();
		float calc_fitness(std::vector<int> predicted, std::vector<int> goal);
		
		//POPULATION
		//We are using a vector so we can keep track of the numbers in each day of the data we have
		//like so, we can evolve it later
	private:	
		int _days;	
		float T; //total population
		std::vector<float> S; //Susceptible
		std::vector<float> I; //Infectious
		std::vector<float> R; //Recovered
	
		//PARAMETERS
		float beta; //rate of spread
		float gamma; //recovery rate and = 1/D (D = average duration of the infection)
		float csi; //rate which recovered individuals return to the susceptible statue due to loss of immunity
		
		//Gene
		std::vector<std::vector<float>> _genes;
		
};

#endif 

