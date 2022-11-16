/*
 * @Author: fanIST fanISTREC2DX@outlook.com
 * @Date: 2022-11-09 14:20:19
 * @LastEditors: fanIST fanISTREC2DX@outlook.com
 * @LastEditTime: 2022-11-16 14:03:04
 * @FilePath: \c-1\d12\d12.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
int main(void)
{
    int array[8] = {0};
    int i = 0;
    //
    while (i < 8)
    {
        scanf("%i", &array[i]);
        i++;
    }
    //先取两个进行比较
    int a = array[0] + array[1];
    int b = array[2] + array[3];
    int c = array[4] + array[5];
    if (a != b)
    { // cd为真，ab为假
        printf("前四中有假");
        if (a != c)
        { // a为假，在a类中找
            if (array[0] = array[7])
            {
                printf("第二枚为假");
            }
            else
            {
                printf("第一枚为假");
            }
        }
        else
        { // a为真
            if (array[2] = array[7])
            {
                printf("第三枚为假");
            }
            else
            {
                printf("第四枚为假");
            }
        }
    }
    else
    { // cd不等，ab为真
        printf("后四中有假");
        if (c != a)
        { // c组有假
            if (array[4] != array[0])
            {
                printf("第五枚假");
            }
            else
            {
                printf("第六枚假");
            }
        }
        else
        { // d组有假
            if (array[6] != array[0])
            {
                printf("第七枚假");
            }
            else
            {
                printf("第八是假的捏");
            }
        }
    }

    return 0;
}