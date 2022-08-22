#include "Range.h"
#include <algorithm>
#include <iostream>
using namespace std;

bool isCurrentValueContinuous(int valueOfCurrentIndex, int ValueOfNextIndex)
{
  if(((ValueOfNextIndex - valueOfCurrentIndex) == 1) || ((ValueOfNextIndex - valueOfCurrentIndex) == 0))//Continuous element or same element
   {
	   return true;
   }
   return false;
}

void checkContinuityInInputData(std::vector<int>  sortedInputData, int currentIndexInputData, ContinuousRangeInfo& ContinuousRangrInfo)
{
  int startIndex = sortedInputData[currentIndexInputData];
   for(int index = currentIndexInputData; index < (sortedInputData.size() - 1); index++)
   {
	   if(isCurrentValueContinuous(sortedInputData[index], sortedInputData[index + 1]))
	   {
		   ContinuousRangrInfo.startIndexContinuousRange ++;
		   ContinuousRangrInfo.endIndexContinuousRange = startIndex;
		   ContinuousRangrInfo.numberOfReadingsContinuousRange = sortedInputData[index + 1];
	   }
	   else
	   {
		   break;
	   }
   }
}

std::vector<ContinuousRangeInfo> CalculateContinuosRange(std::vector<int> inputData)
{
  int currentIndexInputData = 0;
  std::vector<ContinuousRangeInfo> ContinuosRangeList;
  std::sort(inputData.begin(), inputData.end());
  while((currentIndexInputData < inputData.size()) == true)
  {
    ContinuousRangeInfo ContinuousRangeInfo;
    checkContinuityInInputData(inputData, currentIndexInputData, ContinuousRangeInfo);
    if(ContinuousRangeInfo.numberOfReadingsContinuousRange > 1)
    {
      ContinuosRangeList.push_back(ContinuousRangeInfo);
      currentIndexInputData = currentIndexInputData + ContinuousRangeInfo.numberOfReadingsContinuousRange - 1;
    }
    currentIndexInputData++;
  }
  return ContinuosRangeList;
}
