#include "data.h"

Data::Data(std::string filename): //will be used for keeping the generations and stuff
	filename(filename)
{

	file = openFile(filename);
}

Data::~Data()
{
	file.close();
}

std::fstream Data::openFile(std::string localData)
{
	std::fstream datafile;
	if(localData == "")
		datafile.open("data/noName.txt", std::ios_base::out);
	else
		datafile.open("data"+localData+".txt", std::ios_base::in | std::ios_base::out);
	
	return datafile;
}

void Data::readFileCovid(std::string filename)
{
	std::string content;
	std::ifstream covidData;
	std::vector<std::string> row; ///vector for columns names

	covidData.open(("../data/"+filename).c_str(), std::ios_base::in);
	
	if(!covidData.is_open()) ///Fail
	{
		std::cout << BOLDRED << "[DataCovid] Failed to read " + filename << RESET << std::endl;
	  	return;
	}
	
	std::string line, word;
	
	std::getline(covidData, line); ///first line representing the name of the columns.
	std::stringstream s(line);

	while((getline(s, word, ';')))
	{
		row.push_back(word); ///I'm not keeping this information, maybe I should
	}
	
	bool stop = false;
	while(!covidData.eof() && stop == false)
	{
		std::getline(covidData, line);
		std::stringstream ss(line);
		int index = 0;
		while((getline(ss, word, ';')))
		{
			if(!(word == "Brasil") && index == 0){
				stop = true;
				break;
			}
			float temp;
			if(index >= 10){
				if(word == "" || word.size()) 
					temp = 0;
				else 
					temp = std::stof(word);
			}

			if(index == 9){//populacaoTCU2019
				total = temp;	
			}else if(index == 10){//casosAcumulado
				I.push_back(temp);	
			}else if(index == 11){//casosNovos
				//Isso é pra casos novos, por enquanto não precisa.
			}else if(index == 12){//obitosAcumulado
				if(int(D.size()) > 0)
					D.push_back(temp+D.front());
				else
					D.push_back(temp);	
			}else if(index == 14){//RecuperadosNovos
				if(int(R.size()) > 0)
					R.push_back(temp+R.front());
				else
					R.push_back(temp);
			}//We have all information we need to calculate susceptible
			index++;
		}
	
		S.push_back(total-D.front()-R.front()-I.front());
	
	}

	covidData.close();
}

std::string Data::readFile(std::string filename)
{
	
}

void Data::write(std::string line){

}

/*void Data::writeParameters(){

}*/

