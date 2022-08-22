#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"
#include "Range.hpp"
#include "Analog2Digital.hpp"


TEST_CASE("Calculate continuous range")
{
  std::vector<int> InputData {1, 2, 4};
  std::vector<ContinuousRangeInfo> ContinuousRangeInfoList;
  ContinuousRangeInfoList = CalculateContinuosRange(InputData);
  assert(1 == ContinuousRangeInfoList.size());
  assert(true ==ContinuousRangeInfoList.size());
  REQUIRE(ContinuousRangeInfoList[0].numberOfReadingsContinuousRange == 2);
  REQUIRE(ContinuousRangeInfoList[0].startIndexContinuousRange == 1);
  REQUIRE(ContinuousRangeInfoList[0].endIndexContinuousRange == 2);

  std::vector<int> InputData1 {3, 3, 5, 4, 10, 11, 12};
  std::vector<ContinuousRangeInfo> ContinuousRangeInfoList1;
  ContinuousRangeInfoList1 = CalculateContinuosRange(InputData1);
  assert(2 == ContinuousRangeInfoList1.size());
  REQUIRE(ContinuousRangeInfoList1[0].numberOfReadingsContinuousRange == 4);
  REQUIRE(ContinuousRangeInfoList1[0].startIndexContinuousRange == 3);
  REQUIRE(ContinuousRangeInfoList1[0].endIndexContinuousRange == 5);
  REQUIRE(ContinuousRangeInfoList1[1].numberOfReadingsContinuousRange == 3);
  REQUIRE(ContinuousRangeInfoList1[1].startIndexContinuousRange == 10);
  REQUIRE(ContinuousRangeInfoList1[1].endIndexContinuousRange == 12);
}

TEST_CASE("Test CalculateContinuosRange No Continuous reading")
{
  std::vector<int> InputData2 {1, 3, 5};
  std::vector<ContinuousRangeInfo> ContinuousRangeInfoList2;
  ContinuousRangeInfoList2 = CalculateContinuosRange(InputData2);
  assert(0 == ContinuousRangeInfoList2.size());
}


TEST_CASE("Test checkForContinuityInInputData positive")
{
   std::vector<int> sortedData {1, 2, 4};
   int CurrentIndexInPeriodicCurrentVector = 0;
   ContinuousRangeInfo ContinuousRangeInfo;
   checkContinuityInInputData(sortedData, CurrentIndexInPeriodicCurrentVector, ContinuousRangeInfo);
   REQUIRE(ContinuousRangeInfo.numberOfReadingsContinuousRange == 2);
   REQUIRE(ContinuousRangeInfo.startIndexContinuousRange == 1);
   REQUIRE(ContinuousRangeInfo.endIndexContinuousRange == 2);  
}

TEST_CASE("Test checkForContinuityInPeriodicCurrent Negative")
{
   std::vector<int> sortedData {1, 2, 4};
   int CurrentIndexInPeriodicCurrentVector = 1;
   ContinuousRangeInfo ContinuousRangeInfo;
   checkContinuityInInputData(sortedData, CurrentIndexInPeriodicCurrentVector, ContinuousRangeInfo);
   //default values
   REQUIRE(ContinuousRangeInfo.numberOfReadingsContinuousRange == 1);
   REQUIRE(ContinuousRangeInfo.startIndexContinuousRange == 0);
   REQUIRE(ContinuousRangeInfo.endIndexContinuousRange == 0); 
}

TEST_CASE("Test isCurrentValueContinuous Positive")
{
	int currentIndexValue = 5;
	int nextIndexValue = 5;
	REQUIRE((isCurrentValueContinuous(currentIndexValue, nextIndexValue)) == true);

	currentIndexValue = 5;
	nextIndexValue = 6;
	REQUIRE((isCurrentValueContinuous(currentIndexValue, nextIndexValue)) == true);
}

TEST_CASE("Test isCurrentValueContinuous Negative")
{
	int currentIndexValue = 5;
	int nextIndexValue = 7;
	REQUIRE((isCurrentValueContinuous(currentIndexValue, nextIndexValue)) == false);
}

//Test AToD cpnverter implementation

TEST_CASE("Test ConvertFromAnalogToDigital Positive") 
{
   std::vector<int> valueInAnalog {4094, 4000};
   std::vector<int> valueInDigital = ConvertFromAnalogToDigital(valueInAnalog);
   assert(false == valueInDigital.empty());
   REQUIRE(valueInDigital[0] == 10);
   REQUIRE(valueInDigital[1] == 10);
}

TEST_CASE("Test ConvertFromAnalogToDigital Negative") 
{
   std::vector<int> valueInAnalog {0, 4095};
   std::vector<int> valueInDigital = ConvertFromAnalogToDigital(valueInAnalog);
   assert(true == valueInDigital.empty());
}

TEST_CASE("Test getValueInDigital")
{
	int valueInAnalog = 4094;
	REQUIRE((getValueInDigital(valueInAnalog)) == 10);
	
	valueInAnalog = 1146;
	REQUIRE((getValueInDigital(valueInAnalog)) == 3);
}
