#include <vector>

using namespace std;

struct ContinuousRangeInfo
{
  int startIndexContinuousRange;
  int endIndexContinuousRange;
  int numberOfReadingsContinuousRange;
  
  ContinuousRangeInfo()
    : startIndexContinuousRange(0)
    , endIndexContinuousRange(0)
    , numberOfReadingsContinuousRange(1)
    {
    }
};

std::vector<ContinuousRangeInfo> CalculateContinuosRange(std::vector<int> inputData);
void checkContinuityInInputData(std::vector<int>  sortedInputData, int currentIndexInputData, ContinuousRangeInfo& ContinuousRangrInfo);
bool isCurrentValueContinuous(int valueOfCurrentIndex, int ValueOfNextIndex);
