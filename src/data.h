#ifndef _H_DATA
#define _H_DATA

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>

#include "../lib/defines.h"
#include <vector>

class Data{
	public:
		Data(std::string filename);
		~Data();
		
		std::string readFile(std::string filename);	

		void readFileCovid(std::string filename);

		void write(std::string line);
		//void writeParameters();

		std::fstream openFile(std::string localData);
		

	private:
		std::string filename;
		std::fstream file;
	
		float total;		
		std::vector<float> S; //Susceptible
		std::vector<float> I; //Infectious
		std::vector<float> R; //Recovered
		std::vector<float> D; //Dead	
};


#endif
