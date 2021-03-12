#include "pch.h"
#include "../Utilities.cpp"

TEST(UtilitiesTest, WhenSendEmptyStringShouldReturnEmptyVector) {
	std::vector<double> res = Utilities::GetDataFromString("");

  EXPECT_EQ(res.size(), 0);
  EXPECT_TRUE(true);
}


TEST(UtilitiesTest, WhenSendValidStringShouldReturnCorrectFloatVector) {
	std::vector<double> res = Utilities::GetDataFromString("1.0,2.0,3.0");

	EXPECT_EQ(res.size(), 3);
	EXPECT_EQ(res[0],1.0);
	EXPECT_EQ(res[1], 2);
	EXPECT_EQ(res[2], 3);

}


TEST(UtilitiesTest, WhenSendStringWithDiamaterAtEndShouldReturnCorrectFloatVector) {
	std::vector<double> res = Utilities::GetDataFromString("1.0,2.0,3.0,");

	EXPECT_EQ(res.size(), 3);
	EXPECT_EQ(res[0], 1.0);
	EXPECT_EQ(res[1], 2);
	EXPECT_EQ(res[2], 3);

}


TEST(UtilitiesTest, WhenSendStringInValidNumberShouldThroughException) {

	EXPECT_ANY_THROW (Utilities::GetDataFromString("1.0,kk,3.0,"));


}

TEST(UtilitiesTest, WhenTryParseCommandWithEmptyKeyShouldRetuenNull) {


	EXPECT_EQ(nullptr, Utilities::GetMeasurementFromString(" 5 10,1,0"));

}


TEST(UtilitiesTest, WhenTryParseCommandWithEmptyInValidLengthShouldRetuenNull) {


	EXPECT_EQ(nullptr, Utilities::GetMeasurementFromString("ss s 10,1,0"));

}


TEST(UtilitiesTest, WhenTryParseCommandWithValidLengthValidKeyValiDataShouldReturnGoodObject) {

	std::shared_ptr<Measurement> obj = Utilities::GetMeasurementFromString("ss 10 10,1,0");

	EXPECT_EQ(obj->GetName(), "ss");
	EXPECT_EQ(obj->GetLength(), 10);
	EXPECT_EQ(obj->GetData().size(), 3);
	EXPECT_EQ(obj->GetData()[0], 10);
	EXPECT_EQ(obj->GetData()[1], 1);


}


