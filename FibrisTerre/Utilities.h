#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <sstream> 
#include "Measurement.h"
#include "Settings.h"
class Utilities
{

public:
	/*GetDataFromString
	* 
	* Return vector of float from string
	* @param std::string data
	* @param optional char delimiter
	*/
	static std::vector<double> GetDataFromString(std::string  data, char delimiter = ',')throw(int);


	static std::shared_ptr<Measurement> GetMeasurementFromString(std::string command);

};

