#include <stdio.h>
#include "CalcFreqofOccurance.h"

int SamplesCount = 0;
int CurrentSamples[7] = {3, 3, 5, 4, 10, 11, 12};
int TotalNoSamples = sizeof(CurrentSamples)/sizeof(CurrentSamples[0]);
  
int ReadSamples(int FromRange , int ToRange)
{
  int FreqofOccurance = 0;
  for(int i = 0 ; i < TotalNoSamples; i++)
  {
    if((FromRange <= CurrentSamples[i]) && (ToRange >= CurrentSamples[i]))
    {
      FreqofOccurance++;
    }
  }
  Print(FromRange ,ToRange ,FreqofOccurance);
  return FreqofOccurance;
}

void Print(int FromRange , int ToRange ,int FreqofOccurance )
{
  char PrintData[100];
  sprintf(PrintData,"%d-%d,%d\n",FromRange,ToRange,FreqofOccurance);
  printf("%s",PrintData);
}
