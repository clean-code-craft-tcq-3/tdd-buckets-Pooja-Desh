#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"
#include "Range.hpp"


TEST_CASE("Calculate continuous range")
{

  std::vector<int> InputData {1, 2, 4};
  std::vector<ContinuousRangeInfo> ContinuousRangeInfoList;
  ContinuousRangeInfoList = CalculateContinuosRange(InputData);
  REQUIRE(ContinuousRangeInfoList.size() == 1);
  REQUIRE(ContinuousRangeInfoList.size() == true);
  REQUIRE(ContinuousRangeInfoList[0].numberOfReadingsContinuousRange == 2);
  REQUIRE(ContinuousRangeInfoList[0].startIndexContinuousRange == 1);
  REQUIRE(ContinuousRangeInfoList[0].endIndexContinuousRange == 2);

  std::vector<int> InputData1 {3, 3, 5, 4, 10, 11, 12};
  std::vector<ContinuousRangeInfo> ContinuousRangeInfoList1;
  ContinuousRangeInfoList1 = CalculateContinuosRange(InputData1);
  REQUIRE(ContinuousRangeInfoList1.size() == 2);
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
  REQUIRE(0 == ContinuousRangeInfoList2.size());
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
