#pragma once

#include "basic_function.h"

double SolveProblemM5_A()
{
    // 균일한 난수생성을위해 mt19937 사용
    // 0 ~ 20 사이에서 균일하게 숫자를 뽑는다
    // Gold : 1~10, Blue : 11~20
    mt19937 engine(static_cast<unsigned int>(time(NULL)));
    uniform_int_distribution<int> dist(1, 20);
    auto rand_generator = bind(dist, engine);

    int totalCase = 19 * 18 * 17;

    int loop = totalCase * 3000;
    int winNum = 0;
    for (int i = 0; i < loop; ++i)
    {
        vector<int> cardList(4);
        int index = 0;

        // peek 3 card
        set<int> duplicateChecker;
        while (duplicateChecker.size() < 3) // 서로 다른 숫자의 카드가 4개 뽑힐때까지 반복
        {
            int cardNum = rand_generator();
            if (cardNum == 9) { continue; } // 9는 이미 뽑힘
            if (duplicateChecker.insert(cardNum).second == true)
            {
                cardList[index] = (cardNum > 10) ? (cardNum - 10) : cardNum;
                ++index;
            }
        }

        //// 1,2 : player A
        //int Amax = max(A1, A2);
        //int Amin = min(A1, A2);

        //// 3,4 : player B
        //int Bmax = max(B1, B2);
        //int Bmin = min(B1, B2);

        if (IsPlayerA_Win(9, cardList[0], cardList[1], cardList[2]))
        {
            ++winNum;
        }
    }

    double percent = static_cast<double>(winNum) / loop;
    cout << "Percent :" << percent << endl;

    return percent;
}