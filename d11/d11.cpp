void produce(int arr[])
{
    int i;
    srand((unsigned int)time(NULL));
    int a = rand() % 9 + 1; //产生随机真币重量
    for (int i = 0; i < Max; i++)
    {
         arr[i] = a; //假定全为真币重量
    }
    int b;
    do
    {
         b = rand() % 20 + 1;
    } while (b == a);
    int c = rand() % 7;
    arr[c] = b;
}

int Method(int arr[], int i, int j, int k)
{
    int Jiabi = 1; //初识化假币标识
    if (arr[i] > arr[k])
    {
         printf("第%d个是假币,较重\n", i + 1);
    }
    else if (arr[i] < arr[k])
    {
         printf("第%d个是假币,较轻\n", i + 1);
    }
    else
    {
         if (arr[j] > arr[k])

 
        {

              printf("第%d个是假币,较重\n", j + 1);

             
        }

         else if (arr[j] < arr[k])
        {

              printf("第%d个是假币,较轻\n", j + 1);

             
        }

         else
        {

              Jiabi = 0;

             
        }
    }

    return Jiabi;
}

void Test(int arr[])
{

    int sum1 = arr[0] + arr[1] + arr[2];

    int sum2 = arr[3] + arr[4] + arr[5];

    if (sum1 == sum2)
    {

         Method(arr, 6, 7, 0);
    }
}
else
{
    if (sum1 != sum2)
    {

         if (arr[0] + arr[1] == arr[3] + arr[4])
        {

              Method(arr, 2, 5, 6);

             else
            {

                  if (Method(arr, 2, 5, 6) == 0)
                {

                       Method(arr, 1, 4, 2);

                     
                }

                 
            }
        }
    }