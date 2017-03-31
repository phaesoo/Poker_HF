#pragma once

#include "basic_function.h"

void ChooseBestCombination(const vector<int>& cardList, int& A1, int& A2)
{
    if (IsPlayerA_Win(cardList[0], cardList[1], cardList[1], cardList[2]))
    {
        if (IsPlayerA_Win(cardList[0], cardList[1], cardList[0], cardList[2]))
        {
            A1 = 0;
            A2 = 1;
        }
        else
        {
            A1 = 0;
            A2 = 2;
        }
    }
    else
    {
        if (IsPlayerA_Win(cardList[1], cardList[2], cardList[0], cardList[2]))
        {
            A1 = 1;
            A2 = 2;
        }
        else
        {
            A1 = 0;
            A2 = 2;
        }
    }
}

double SolveProblemM5_B()
{
    // ������ �������������� mt19937 ���
    // 0 ~ 20 ���̿��� �����ϰ� ���ڸ� �̴´�
    // Gold : 1~10, Blue : 11~20
    mt19937 engine(static_cast<unsigned int>(time(NULL)));
    uniform_int_distribution<int> dist(1, 20);
    auto rand_generator = bind(dist, engine);

    int totalCase = 20 * 19 * 18 * 17 * 16;

    int loop = totalCase * 10;
    int winNum = 0;
    for (int i = 0; i < loop; ++i)
    {
        vector<int> cardList(5);
        int index = 0;

        // peek 5 card
        set<int> duplicateChecker;
        while (duplicateChecker.size() < 5) // ���� �ٸ� ������ ī�尡 5�� ���������� �ݺ�
        {
            int cardNum = rand_generator();
            if (duplicateChecker.insert(cardNum).second == true)
            {
                cardList[index] = (cardNum > 10) ? (cardNum - 10) : cardNum;
                ++index;
            }
        }

        int A1 = 0;
        int A2 = 0;
        ChooseBestCombination(cardList, A1, A2);

        if (IsPlayerA_Win(A1, A2, cardList[3], cardList[4]))
        {
            ++winNum;
        }
    }

    double percent = static_cast<double>(winNum) / loop;
    cout << "Percent :" << percent << endl;

    return percent;
}