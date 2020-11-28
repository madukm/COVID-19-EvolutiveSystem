#include "data.h"

Data::Data(){}

Data::Data(std::string filename): //will be used for keeping the generations and stuff
	_filename(filename)
{

	_file = openFile(filename);
}

Data::~Data()
{
	_file.close();
}

std::fstream Data::openFile(std::string localData)
{
	std::fstream dataFile;
	if(localData == "")
		dataFile.open("data/noName.txt", std::ios_base::out);
	else
		dataFile.open("data/"+localData+".txt", std::ios_base::in | std::ios_base::out);
	
	if(!dataFile.is_open()) //Fail
	{
		std::cout << BOLDRED << "[ERROR] Failed to read " + localData + "!" << RESET << std::endl;
	}
	return dataFile;
}

void Data::readFile(std::string filename)
{
	
}

void Data::write(std::string line)
{

}
	
std::vector<float> Data::getS(){return S;}

std::vector<float> Data::getI(){return I;}

std::vector<float> Data::getR(){return R;}

std::vector<float> Data::getD(){return D;}
		
int Data::getDays(){return _days;}

float Data::getT(){return T;}


/*void Data::writeParameters(){

}*/

