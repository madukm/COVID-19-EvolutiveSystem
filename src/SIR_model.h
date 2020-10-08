#ifndef _H_MODEL
#define _H_MODEL

#include <vector>

class SIR{
	public:
		SIR();
		~SIR();
		//Getters & Setters
		void set_params(float beta, float gamma, float csi);
		float get_beta();
		float get_gamma();
		float get_csi();
		
		void run_model(int days);

		void initialize_model(double S, double I, double R);

		double N; //total population
		
		//POPULATION
		std::vector<double> S; //Susceptible
		std::vector<double> I; //Infectious
		std::vector<double> R; //Recovered
		
		//PARAMETERS
		float beta; //rate of spread
		float gamma; //recovery rate and = 1/D (D = average duration of the infection)
		float csi; //rate which recovered individuals return to the susceptible statue due to loss of immunity
	};

#endif 

