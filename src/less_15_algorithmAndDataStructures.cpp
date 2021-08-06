//============================================================================
// Name        : less_15_algorithmAndDataStructures.cpp
// Author      : andry antonenko
// IDE         : Eclipse IDE
// Description : lesson 15 of the algorithms and data structures course
//============================================================================

#include <iostream>
using namespace std;
//----------------------------------------------------------------------------
//#define NDEBUG
#include <cassert>
//----------------------------------------------------------------------------
/*
1. Реализовать простейшую хеш-функцию.
На вход функции подается строка,
на выходе сумма кодов символов.
*/

typedef int htIndex;

htIndex getHash(char *s)
{
  assert(s != nullptr);

  htIndex hti = 0;
  while(*s != 0)
  {
    hti += (htIndex)*s++;
  }
  return hti;
}

//----------------------------------------------------------------------------
/*
2. Имеются монеты номиналом 50, 10, 5, 2, 1 коп.
Напишите функцию которая минимальным количеством монет
наберет сумму 98 коп.
Для решения задачи используйте “жадный” алгоритм.
*/

void swapInt(int * pA, int * pB)
{
  assert(pA != nullptr);
  assert(pB != nullptr);

  int t = *pA; *pA = *pB; *pB = t;
}

void sortInserts(int *pArr, int aFirst, int aLast)
{
  assert(pArr != nullptr);

  if(aFirst >= aLast) return;
  int indLast = aFirst;
  while(indLast < aLast)
  {
    indLast++;
    for(int i = aFirst; i < indLast; i++)
      if(pArr[i] > pArr[indLast])
        swapInt(&pArr[i],&pArr[indLast]);
  }
}

bool printCoins(const int kopecks,int *coins,const int numberCoins)
{
  assert(coins != nullptr);

  int k = kopecks;
  sortInserts(coins,0,numberCoins-1);
  int iTypeCoins = numberCoins-1;
  int sum = 0;
  bool isFirst = true;
  while(k > 0)
  {
    if(k >= coins[iTypeCoins])
    {
      if(!isFirst) cout << "+ ";
      isFirst = false;
      k -= coins[iTypeCoins];
      sum += coins[iTypeCoins];
      cout << coins[iTypeCoins] << " ";
    }
    else
    {
      if(iTypeCoins != 0)
        iTypeCoins--;
      else
        return false;
    }
  }

  cout << " = " << sum << endl;

  return true;
}

//----------------------------------------------------------------------------
void task_1()
{
  cout << "Task 1\n" << endl;

  char str[] = "1234567890";

  cout << "Enter sequence:" << str << endl;

  int h = getHash(&str[0]);
  cout << "Hash of the sequence: " << h << endl;
}
//----------------------------------------------------------------------------
void task_2()
{
  cout << "Task 2\n" << endl;

  const int NUMBER_COINS = 5; //number nominal values of coins
  int coins[] = {10,50,5,2,1};

  int kopecks = 98;

  cout << "Enter value of enter value of kopecks: " << endl;
  cin >> kopecks;

  if(printCoins(kopecks,coins,NUMBER_COINS))
  {
    cout << endl << "The list of coins found." << endl;
  }
  else
  {
    cout << endl << "The list of coins not found." << endl;
  }
}

//----------------------------------------------------------------------------
int main() {
//----------------------------------------------------------------------------
  // Task 1
  //*
  task_1();
  //*/
//----------------------------------------------------------------------------
  // Task 2
  //*
  task_2();
  //*/
//----------------------------------------------------------------------------
	return 0;
//----------------------------------------------------------------------------
}
//----------------------------------------------------------------------------
