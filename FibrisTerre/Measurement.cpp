#include "Measurement.h"

const std::string& Measurement::GetName() const
{
    return mName;
}

std::vector<double>& Measurement::GetData()
{
    return mData;
}

uint32_t Measurement::GetLength() const
{
    return mLength;
}

const std::string& Measurement::toString() const
{
    
    return mOrginalCommand;
}
