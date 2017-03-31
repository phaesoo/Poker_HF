#pragma once


#include<random>
#include<functional>
#include<algorithm>
#include<iostream>
#include<set>
#include<assert.h>
#include<time.h>

using namespace std;

enum Rank
{
    Rank0 = 0, // 연속번호
    Rank1,     // 쌍
    Rank2,     // Others
};