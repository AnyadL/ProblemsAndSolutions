#include <iostream>
#include <vector>
#include <algorithm>

int FindNumberAtPosition(int position)
{
  int x2 = 2; int i2 = 0;
  int x3 = 3; int i3 = 0;
  int x5 = 5; int i5 = 0;
  
  std::vector<int> numbers;
  numbers.push_back(1);

  for(int i = 1; i < position; ++i)
  {
    // The next number will be one of the earlier numbers multiplied by 2, 3, or 5
    int nextNumber = std::min({numbers[i2] * x2, numbers[i3] * x3, numbers[i5] * x5});

    // Check for overflow
    if(nextNumber <= 0)
    {
      std::cout << "That position was too high for this program." << std::endl;
      return -1;
    }

    // The next number may be X * 2, but it may also be Y * 3 or Z * 5
    // Check all three posibilities to remove the posibility of duplicates
    if(nextNumber == numbers[i2] * x2)
    {
      // The next number is X * 2
      // Increment the index counter so that X * 2 is not considered again
      ++i2;
    }
    if(nextNumber == numbers[i3] * x3)
    {
      // The next number is Y * 3
      // Increment the index counter so that Y * 3 is not considered again
      ++i3;
    }
    if(nextNumber == numbers[i5] * x5)
    {
      // The next number is Z * 5
      // Increment the index counter so that Z * 5 is not considered again
      ++i5;
    }

    numbers.push_back(nextNumber);

    // If all indices are 1 or higher, 
    // we are no longer considering the first element in the numbers array
    // Remove it and decrement counters to conserve memory.
    if(std::min({i2, i3, i5}) > 0)
    {
      numbers.erase(numbers.begin());
      --i2; --i3; --i5;
    }
  }

  // The final number in the array will be the number at `position`
  return numbers.back();
}

int main() 
{
  int position;
  std::cout << "Enter the position you'd like to find the number for: ";
  std::cin >> position;
  int number = FindNumberAtPosition(position);
  if(number > -1)
  {
    std::cout << "The number at that position is " << FindNumberAtPosition(position) << std::endl;
  }
}