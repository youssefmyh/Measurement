#include "pch.h"
#include "../MeasurementRepository.cpp"

TEST(MeasurementRepositoryTest, WhenSaveMeasurementWithEmptyKeyShouldReturnFalse) {

	MeasurementRepository measurementRepository;
	Measurement m("", 0, {},"");

	EXPECT_FALSE(measurementRepository.saveMeasurement(m));
}

TEST(MeasurementRepositoryTest, WhenLookUpForExisitingMeasurementByKeyShouldReturnValidObject) {

	MeasurementRepository measurementRepository;
	Measurement m("so", 1, {1,2,3},"");
	measurementRepository.saveMeasurement(m);
	EXPECT_EQ(measurementRepository.findMeasurementbyName("ss"),nullptr);
	Measurement* mObject = measurementRepository.findMeasurementbyName("so");

	EXPECT_EQ(mObject->GetName(),"so");
	EXPECT_EQ(mObject->GetLength(), 1);
	EXPECT_EQ(mObject->GetData()[2], 3);

}


TEST(MeasurementRepositoryTest, WhenTryToSaveExistingObjectSHouldreturnfalse) {

	MeasurementRepository measurementRepository;
	Measurement m("so", 1, { 1,2,3 },"");
	measurementRepository.saveMeasurement(m);
	EXPECT_EQ(measurementRepository.findMeasurementbyName("ss"), nullptr);
	
	measurementRepository.saveMeasurement(m);

	EXPECT_FALSE(measurementRepository.saveMeasurement(m));


}


TEST(MeasurementRepositoryTest, WhenSaveMeastoFileAllMapObjectsShouldbeSaved) {

	MeasurementRepository measurementRepository;
	Measurement m("so", 1, { 1,2,3 }, "so 1 50,50,50,50,4");
	Measurement d("de", 1, { 1,2,3 }, "de 1 50,50,50,50,4");

	measurementRepository.saveMeasurement(m);
	measurementRepository.saveMeasurement(d);


	measurementRepository.saveMeasurementsToFile("output.test");



}


TEST(MeasurementRepositoryTest, WhenLoadMeasurementsFromFileShouldReturnCorrectValue) {

	MeasurementRepository measurementRepository;
	Measurement m("so", 1, { 1,2,3 }, "so 1 50,50,50,50,4");
	Measurement d("de", 1, { 1,2,3 }, "de 1 50,50,50,50,4");

	measurementRepository.saveMeasurement(m);
	measurementRepository.saveMeasurement(d);


	measurementRepository.saveMeasurementsToFile("output.test");


	MeasurementRepository measurementRepository2;
	measurementRepository2.loadMeasurementsFromFile("output.test");
	Measurement* mObject = measurementRepository2.findMeasurementbyName("so");

	EXPECT_EQ(mObject->GetName(), "so");
	EXPECT_EQ(mObject->GetLength(), 1);
	EXPECT_EQ(mObject->GetData()[2], 3);


}