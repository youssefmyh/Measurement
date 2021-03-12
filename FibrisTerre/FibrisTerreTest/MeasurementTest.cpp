#include "pch.h"
#include "../Measurement.cpp"
TEST(MeasurementTest, WhenCreateMeasurementGetFunctionShouldReturnCorrctValue) {

	Measurement measurement("H", 10, { 50,10,20,41 },"");

  EXPECT_EQ(measurement.GetName(), "H");
  EXPECT_EQ(measurement.GetLength(), 10);
  EXPECT_EQ(measurement.GetData().size(), 4);
  EXPECT_EQ(measurement.GetData()[0], 50.0);

}