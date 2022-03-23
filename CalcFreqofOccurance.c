#include <stdio.h>
#include <stdlib.h>
#include "CalcFreqofOccurance.h"

int CheckInput(const void * firstInput, const void * secondInput) 
{
  return ( *(int*)firstInput - *(int*)secondInput );
}

int* SortArray(int *CurrentSamples, int NoOfSamples) 
{
  qsort(CurrentSamples,NoOfSamples,sizeof(int),CheckInput);
  int* SortedSamples = CurrentSamples;

  return SortedSamples;
}
  
int CalcFreqofOccurance(int* SortedSamples, int TotalNoSamples)
{
  int FreqofOccurance = 0;
  int Startpt         = SortedSamples[0];
  int Endpt           = SortedSamples[TotalNoSamples - 1];

  for(int i = 0 ;i < TotalNoSamples; i++)
  {
    if((Startpt <= SortedSamples[i]) && (Endpt >= SortedSamples[i]))
    {
      FreqofOccurance++;
    }
  }
  Print(Startpt, Endpt, FreqofOccurance);

  return FreqofOccurance;
}

void Print(int Startpt ,int Endpt ,int FreqofOccurance)
{
  char DisplayData[100];
  sprintf(DisplayData,"%d-%d,%d\n",Startpt,Endpt,FreqofOccurance);
  printf("%s",DisplayData);
}

int GetCurrentSamples(int *CurrentSamples, int NoOfSamples)
{
  int *SortedSamples = SortArray(CurrentSamples,NoOfSamples);
  int  SamplesCount  = CalcFreqofOccurance(SortedSamples,NoOfSamples);

  return SamplesCount;  
}