#pragma once
#include <string>
#include <vector>
class Measurement
{
public:
	Measurement(std::string name,uint32_t length,std::vector<double> data,std::string command):mName(name),mLength(length),mData(data), mOrginalCommand(command){
	}

	const std::string& GetName() const;
	std::vector<double>& GetData();
	uint32_t GetLength() const;
	const std::string& toString() const;

private:
	std::string mName;
	uint32_t mLength; // 32 bit
	std::vector<double> mData; // 64bit
	std::string mOrginalCommand;
};

