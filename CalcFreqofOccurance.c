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
  SendDataToPrint(FromRange ,ToRange ,NoofOccurance);
  return FreqofOccurance;
}

void SendDataToPrint(int FromRange , int ToRange ,int TotalOccurance )
{
  char PrintData[100];
  sprintf(PrintData,"%d-%d,%d\n",FromRange,ToRange,TotalOccurance);
  printf("%s",PrintData);
}
