




#include "problemM5_A.h"
#include "problemM5_B.h"



int main()
{
    //// ������ �������������� mt19937 ���
    //// 0 ~ 20 ���̿��� �����ϰ� ���ڸ� �̴´�
    //// Gold : 1~10, Blue : 11~20
    //mt19937 engine(static_cast<unsigned int>(time(NULL)));
    //uniform_int_distribution<int> dist(1, 20);
    //auto rand_generator = bind(dist, engine);

    ///*
    //vector<int> num(20);
    //for (int i = 0; i < 1000000000; ++i)
    //{
    //++num[rand_generator()-1];
    //}

    //for (int i = 0; i < 20; ++i)
    //{
    //cout << num[i] << endl;wha
    //}*/

    //int totalCase = 20 * 19 * 18 * 17;

    //int loop = totalCase * 100;
    //int winNum = 0;
    //for (int i = 0; i < loop; ++i)
    //{
    //    vector<int> cardList(4);
    //    int index = 0;

    //    // peek 4 card
    //    set<int> duplicateChecker;
    //    while (duplicateChecker.size() < 4) // ���� �ٸ� ������ ī�尡 4�� ���������� �ݺ�
    //    {
    //        int cardNum = rand_generator();
    //        if (duplicateChecker.insert(cardNum).second == true)
    //        {
    //            cardList[index] = (cardNum > 10) ? (cardNum - 10) : cardNum;
    //            ++index;
    //        }
    //    }

    //    for (auto itr = cardList.begin(); itr != cardList.end(); ++itr)
    //    {
    //        if (*itr > 10)
    //        {
    //            *itr -= 10;
    //        }
    //    }

    //    if (IsPlayerA_Win(cardList))
    //    {
    //        ++winNum;
    //    }
    //}

    //double percent = static_cast<double>(winNum) / loop;
    //cout << "Percent :" << percent << endl;

    SolveProblemM5_A();
    //SolveProblemM5_B();


    return 0;
}