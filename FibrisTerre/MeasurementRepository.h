#pragma once
#include "Measurement.h"
#include "Utilities.h"
#include <unordered_map>
#include <fstream>
#include <map>
class MeasurementRepository
{


public:
	Measurement* findMeasurementbyName(std::string key);
	bool deleteMeasurementByName(std::string key);

	bool saveMeasurement(Measurement measurement);
	void loadMeasurementsFromFile(std::string filename);
	void saveMeasurementsToFile(std::string filename);


	const std::map<std::string, Measurement> & getAllMeasurements() const;

private:
	std::map<std::string, Measurement> mMeasurements; // Get key is log() 
};

