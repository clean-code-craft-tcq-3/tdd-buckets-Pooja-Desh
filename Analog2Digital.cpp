#include "Analog2Digital.hpp"
#include <math.h>

int getValueInDigital(int valueInAnalog)
{
  double valueInDigital = 10 * (float(valueInAnalog)/4094);
  return int(round(valueInDigital));
}

std::vector<int> ConvertFromAnalogToDigital(std::vector<int> valueInAnalog)
{
	std::vector<int> valueInDigital;
	std::vector<int>::iterator AnalogDataItr = valueInAnalog.begin();
	while(AnalogDataItr != 	valueInAnalog.end())
	{
		if(*AnalogDataItr > 1 && *AnalogDataItr <= 4094)
		{
			int AmpInDigital = getValueInDigital(*AnalogDataItr);
			valueInDigital.push_back(AmpInDigital);
		}
		AnalogDataItr++;
	}
	return valueInDigital;
}
