#pragma once

#include "basic_definition.h"

// �� Player�� Rank�� ������ִ� �Լ�
Rank GetRank(int maxnum, int minnum)
{
    int diff = maxnum - minnum; // ����
    assert(diff >= 0); // ���� ����ó��

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

// Player A�� �̰���� �Ǵ�
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
    if (rankA < rankB) // A�� rank�� �� ���� (rank�� �������� ���� ���)
    {
        return true;
    }
    else if (rankA > rankB) // A�� rank�� �� ����
    {
        return false;
    }
    else // rank�� ����
    {
        if (Amax > Bmax) // �� ���������� ī�带 �������� A�� ��ũ��
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