#include "Utilities.h"

std::vector<double> Utilities::GetDataFromString(std::string data, char delimiter) throw(int)
{
    std::vector<double> measurements;

    if (data.length() <= 0)
        return std::move(measurements);

    std::istringstream dataStream(data);
    std::string value;
    int index = 0;
    while (std::getline(dataStream, value, delimiter))
    {
        try {
            double parsedValue = std::stod(value);
            measurements.push_back(parsedValue);
            index++;
        }
        catch (...) {
            throw (index);
        }

        
    }

    return std::move(measurements);
}

std::shared_ptr<Measurement>  Utilities::GetMeasurementFromString(std::string command)
{
    std::istringstream dataStream(command);
    std::vector<std::string> commandData;
    std::string value;
    while (std::getline(dataStream, value, ' '))
    {
        commandData.push_back(value);
    }



    if (command.size() < 3) // command paramters
        return nullptr;

    if (commandData[0].length() < MIN_KEY_LENGTH || commandData[0].length() > MAX_KEY_LENGTH)
        return nullptr;

    try {

        std::vector<double> data = GetDataFromString(commandData[2]);

        if (data.size() < 1 || data.size() > MAX_MEASUREMENT)
            return nullptr;

        uint32_t length = std::stol(commandData[1]); // long 

        return std::make_shared<Measurement>(commandData[0], length, std::move(data), command);


    }
    catch (...) {
        return nullptr;
    }
}



