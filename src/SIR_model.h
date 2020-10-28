/**
 * Class for SIR Model.
 * Inside comments: later I will keep adding more parameters for better models, but I want to keep track of them.
 */

#ifndef _H_SIR_MODEL
#define _H_SIR_MODEL

#include <vector>
#include <string>

#include "data.h"

class SIR{
	public:
		SIR();
		~SIR();

		//Getters & Setters
		void set_params(float beta, float gamma, float csi);
		float get_beta();
		float get_gamma();
		float get_csi();
		
		void initialize_model(float S, float I, float R);
		void reset_model();
		void run_model(int days);

		float set_fitness(std::vector<float> fitness);
		float fitness(std::string data, std::vector<float> goal);
		float calc_fitness(std::vector<int> predicted, std::vector<int> goal);
		
		//POPULATION
		//We are using a vector so we can keep track of the numbers in each day of the data we have
		//like so, we can evolve it later
		Data *data;
		
		float T; //total population
		std::vector<float> S; //Susceptible
		std::vector<float> I; //Infectious
		std::vector<float> R; //Recovered
		enum Condition {s, i, r};
		
		//PARAMETERS
		float beta; //rate of spread
		float gamma; //recovery rate and = 1/D (D = average duration of the infection)
		float csi; //rate which recovered individuals return to the susceptible statue due to loss of immunity

		//Gene
		std::vector<float> _fitness;
		
};

#endif 

