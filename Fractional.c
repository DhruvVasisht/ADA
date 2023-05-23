#include <stdio.h>

// Function to swap two items
void swap(float *a, float *b)
{
  float t = *a;
  *a = *b;
  *b = t;
}
void swapInt(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

// Partition function used in quicksort
int partition(int arr[], float density[], int low, int high)
{
  float pivot = density[high];
  int i = low - 1;

  for (int j = low; j <= high - 1; j++)
  {
    if (density[j] >= pivot)
    {
      i++;
      swapInt(&arr[i], &arr[j]);
      swap(&density[i], &density[j]);
    }
  }
  swapInt(&arr[i + 1], &arr[high]);
  swap(&density[i + 1], &density[high]);
  return (i + 1);
}

// Quicksort function
void quicksort(int arr[], float density[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, density, low, high);
    quicksort(arr, density, low, pi - 1);
    quicksort(arr, density, pi + 1, high);
  }
}

// Fractional Knapsack function
float fractionalKnapsack(int W, int value[], int weight[], int n)
{
  float total_value = 0;
  int current_weight = 0;
  float density[n];

  // Calculate density of each item
  for (int i = 0; i < n; i++)
  {
    density[i] = (float)value[i] / weight[i];
  }

  // Sort items by density using quicksort
  quicksort(weight, density, 0, n - 1);

  for (int i = 0; i < n; i++)
  {
    if (current_weight + weight[i] <= W)
    {
      current_weight += weight[i];
      total_value += value[i];
    }
    else
    {
      int remaining_weight = W - current_weight;
      total_value += density[i] * remaining_weight;
      break;
    }
  }
  return total_value;
}

int main()
{
  int W, n;
  printf("Enter the total weight of the knapsack: ");
  scanf("%d", &W);
  printf("Enter the number of items: ");
  scanf("%d", &n);

  int value[n], weight[n];
  printf("Enter the value and weight:\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d %d", &value[i], &weight[i]);
  }

  float max_value = fractionalKnapsack(W, value, weight, n);
  printf("Maximum value= %f\n", max_value);
  return 0;
}

