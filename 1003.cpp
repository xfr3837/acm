/**
 * Copy from https://blog.csdn.net/qq_31258245/article/details/61916077 
 * 2018/07/14
 */ 

#include <iostream>
using namespace std;

char cArray[101];// 用于保存输入的01字符
// 根据总分得到等级
int getLevel(int sum)
{
    int level = 8;
    if (sum < 750)
    {
        if (sum >= 650)
            level = 7;
        else if (sum >= 550)
            level = 6;
        else if (sum >= 450)
            level = 5;
        else if (sum >= 350)
            level = 4;
        else if (sum >= 250)
            level = 3;
        else if (sum >= 150)
            level = 2;
        else if (sum >= 50)
            level = 1;
        else
            level = 0;
    }
    return level;
}
// 根据连续天数得到总分
int getSum(int i)
{
    if (i < 6)
        return (1 + i)*i / 2 * 10;
    else
        return 150 * (i / 5) + getSum(i % 5);
}
int main()
{
    int t;
    cin >> t; // cases number
    while (t--)
    {
        int num, k = 1; // days number & Continuity days
        int sum = 0;
        cin >> num;
        cin >> cArray; // IMPORTANT
        for (int i = 0;i < num;i++)
        {
            if (cArray[i] == '1')
            {
                if (cArray[i + 1] == '1')
                {
                    k++;
                    continue;
                }
                sum += getSum(k);
                k = 1;
            }
        }
        cout << getLevel(sum) << endl;
    }
    return 0;
}

