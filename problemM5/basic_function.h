#pragma once

#include "basic_definition.h"

// 각 Player별 Rank를 계산해주는 함수
Rank GetRank(int maxnum, int minnum)
{
    int diff = maxnum - minnum; // 차이
    assert(diff >= 0); // 음수 예외처리

    switch (diff)
    {
    case 1:
    case 9:
        return Rank0;
    case 0:
        return Rank1;
    }

    return Rank2;
}

// Player A가 이겼는지 판단
bool IsPlayerA_Win(int A1, int A2, int B1, int B2)
{
    // 1,2 : player A
    int Amax = max(A1, A2);
    int Amin = min(A1, A2);

    // 3,4 : player B
    int Bmax = max(B1, B2);
    int Bmin = min(B1, B2);

    Rank rankA = GetRank(Amax, Amin);
    Rank rankB = GetRank(Bmax, Bmin);

    bool win = false;
    if (rankA < rankB) // A의 rank가 더 높음 (rank가 낮을수록 높은 등급)
    {
        return true;
    }
    else if (rankA > rankB) // A의 rank가 더 낮음
    {
        return false;
    }
    else // rank가 같음
    {
        if (Amax > Bmax) // 더 높은숫자의 카드를 비교했을때 A가 더크면
        {
            return true;
        }
        else if (Amax < Bmax)
        {
            return false;
        }
        else
        {
            if (Amin > Bmin)
            {
                return true;
            }
        }
    }

    return win;
}