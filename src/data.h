#ifndef _H_DATA
#define _H_DATA

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>

#include "../lib/defines.h"
#include <vector>

#define POP_TOT 9
#define CASOS_TOT 10
#define CASOS_NOVOS 11
#define OBITOS_TOT 12
#define RECUPERADOS NOVOS 14

class Data{
	public:
		Data();
		Data(std::string filename);
		~Data();
		
		void readFileCovid(std::string filename);	
		void readFile(std::string filename);
		void write(std::string line);
		//void writeParameters();

		std::fstream openFile(std::string localData);
		
		void manageDataReference();	

		std::vector<float> getS();
		std::vector<float> getI();
		std::vector<float> getR();
		std::vector<float> getD();
		float getT();
		int getDays();

	protected:
		std::string _filename;
		std::fstream _file;
		
		int _days;	
		float T;		
		std::vector<float> S; //Susceptible
		std::vector<float> I; //Infectious
		std::vector<float> R; //Recovered
		std::vector<float> D; //Dead	
		
};

#endif
