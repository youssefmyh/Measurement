#include "MeasurementRepository.h"

Measurement* MeasurementRepository::findMeasurementbyName(std::string key)
{
	auto it = mMeasurements.find(key);

	if (it == mMeasurements.end())
		return nullptr;

	return &(it->second);
}

bool MeasurementRepository::deleteMeasurementByName(std::string key) {

	auto it = mMeasurements.find(key);

	if (it == mMeasurements.end())
		return false;
	mMeasurements.erase(it);
	return true;
}

bool MeasurementRepository::saveMeasurement(Measurement nMeasurement)
{
	if (nMeasurement.GetName().length() < 1)
		return false;

	Measurement* measurement = findMeasurementbyName(nMeasurement.GetName());

	if (measurement != nullptr)
		return false;

	mMeasurements.insert(std::pair<std::string, Measurement>(nMeasurement.GetName(), std::move(nMeasurement)));

	return true;
}

void MeasurementRepository::loadMeasurementsFromFile(std::string filename)
{
	std::ifstream infile(filename);
	std::string line;
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		std::shared_ptr<Measurement> obj = Utilities::GetMeasurementFromString(line);
		if (obj != nullptr ) {
			saveMeasurement(*obj);
		}

	}
	infile.close();

}

void MeasurementRepository::saveMeasurementsToFile(std::string filename)
{
	std::ofstream savedMeasurement(filename);
	auto it = mMeasurements.begin();
	while (it != mMeasurements.end())
	{
		it->second.toString();
		savedMeasurement << it->second.toString();
		savedMeasurement << '\n';
		it++;
	}
	savedMeasurement.flush();
	savedMeasurement.close();

}

const std::map<std::string, Measurement>& MeasurementRepository::getAllMeasurements() const
{
	return mMeasurements;
}
