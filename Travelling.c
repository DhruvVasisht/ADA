#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 10
#define INFINITY INT_MAX

int costMatrix[MAX_CITIES][MAX_CITIES];
int visited[MAX_CITIES];
int numCities, minCost = 0;

int findNearestCity(int city)
{
  int nearestCity = -1, minCost = INFINITY;

  for (int i = 0; i < numCities; i++)
  {
    if (costMatrix[city][i] != 0 && !visited[i])
    {
      if (costMatrix[city][i] < minCost)
      {
        minCost = costMatrix[city][i];
        nearestCity = i;
      }
    }
  }

  return nearestCity;
}

void takeInput()
{
  printf("Enter the number of cities: ");
  scanf("%d", &numCities);

  printf("\nEnter the Cost Matrix\n");

  for (int i = 0; i < numCities; i++)
  {
    printf("\nEnter Elements of Row: %d\n", i + 1);

    for (int j = 0; j < numCities; j++)
    {
      scanf("%d", &costMatrix[i][j]);
    }

    visited[i] = 0;
  }

  printf("\n\nThe cost list is:");

  for (int i = 0; i < numCities; i++)
  {
    printf("\n");

    for (int j = 0; j < numCities; j++)
    {
      printf("\t%d", costMatrix[i][j]);
    }
  }
}

void findMinimumCost(int city)
{
  visited[city] = 1;
  printf("%d--->", city + 1);

  int nearestCity = findNearestCity(city);

  if (nearestCity == -1)
  {
    nearestCity = 0;
    printf("%d", nearestCity + 1);
    minCost += costMatrix[city][nearestCity];
    return;
  }

  minCost += costMatrix[city][nearestCity];
  findMinimumCost(nearestCity);
}

int main()
{
  takeInput();

  printf("\n\nThe Path is:\n");
  findMinimumCost(0); // passing 0 because starting vertex

  printf("\n\nMinimum cost is %d\n ", minCost);

  return 0;
}


