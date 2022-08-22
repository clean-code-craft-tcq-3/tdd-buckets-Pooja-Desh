#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"
#include "Range.h"


TEST_CASE("Calculate continuous range")
{

  std::vector<int> InputData {1, 2, 4};
  std::vector<ContinuityInfo> ContinuityInfoList;
  ContinuityInfoList = CalculateContinuosRange(InputData);
  REQUIRE(ContinuityInfoList.size() == 1);
  REQUIRE(ContinuityInfoList.size() == true);
  REQUIRE(ContinuityInfoList[0].numberOfReadingsContinuousRange == 2);
  REQUIRE(ContinuityInfoList[0].startIndexContinuousRange == 1);
  REQUIRE(ContinuityInfoList[0].endIndexContinuousRange == 2);

  ::std::vector<int> InputData1 {3, 3, 5, 4, 10, 11, 12};
  std::vector<ContinuityInfo> ContinuityInfoList1;
  ContinuityInfoList1 = CalculateContinuosRange(InputData1);
  REQUIRE(ContinuityInfoList1.size() == 2);
  REQUIRE(ContinuityInfoList1[0].numberOfReadingsContinuousRange == 4);
  REQUIRE(ContinuityInfoList1[0].startIndexContinuousRange == 3);
  REQUIRE(ContinuityInfoList1[0].endIndexContinuousRange == 5);
  REQUIRE(ContinuityInfoList1[1].numberOfReadingsContinuousRange == 3);
  REQUIRE(ContinuityInfoList1[1].startIndexContinuousRange == 10);
  REQUIRE(ContinuityInfoList1[1].endIndexContinuousRange == 12);
}

TEST_CASE("Test CalculateContinuosRange No Continuous reading")
{
  std::vector<int> InputData2 {1, 3, 5};
  std::vector<ContinuityInfo> ContinuityInfoList2;
  ContinuityInfoList2 = CalculateContinuosRange(InputData2);
  assert(0 == ContinuityInfoList2.size());
}


TEST_CASE("Test checkForContinuityInInputData positive")
{
   std::vector<int> sortedData {1, 2, 4};
   int CurrentIndexInPeriodicCurrentVector = 0;
   ContinuousRangeInfo ContinuousRangeInfo;
   checkContinuityInInputData(sortedData, CurrentIndexInPeriodicCurrentVector, continuityInfo);
   REQUIRE(continuityInfo.numberOfReadingsContinuousRange == 2);
   REQUIRE(continuityInfo.startIndexContinuousRange == 1);
   REQUIRE(continuityInfo.endIndexContinuousRange == 2);  
}

TEST_CASE("Test checkForContinuityInPeriodicCurrent Negative")
{
   std::vector<int> sortedData {1, 2, 4};
   int CurrentIndexInPeriodicCurrentVector = 1;
   ContinuityInfo continuityInfo;
   checkContinuityInInputData(sortedData, CurrentIndexInPeriodicCurrentVector, continuityInfo);
   //default values
   REQUIRE(continuityInfo.numberOfReadingsContinuousRange == 1);
   REQUIRE(continuityInfo.startIndexContinuousRange == 0);
   REQUIRE(continuityInfo.endIndexContinuousRange == 0); 
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