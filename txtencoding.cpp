#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>

int main(void)
{
    int a;
    int i=0;
    printf("인원 수를 입력하세요");
    scanf("%d",&a);
    std::vector<int> b{};
    std::vector<int> k{};


    for(int i=0;i<a;i++)
    {
         b.push_back(i+1);
    }
    srand(time(NULL));
    int c=(rand()%a)+1;
    while(1)
    {
        int d;
        printf("마피아 일 것 같은 사림의 번호를 적으세요");
        scanf("%d",&d);
        if(d==c)
        {
            printf("맞췄습니다!");
            break;
        }
        else
        {
            b.erase(std::remove(b.begin(),b.end(),d));
            k.push_back(d);
            printf("틀렷습니다.마피아가 한명 죽이려 시도합니다...\n");
            srand(time(NULL));
            int e=(rand()%a)+1;
            auto t = find(b.begin(), b.end(), e);
            if(t != b.end()) 
            {
                printf("%d",e);
                if(e==c)
                {
                    printf("마피아 살인 실패!\n");
                    std::cout << "죽은자" << '\n';
                    for(int i=0;i<k.size();i++)
                    {
                        std::cout<<k[i]<<" ";
                    }
                    continue;
                }
                else
                {
                    b.erase(std::remove(b.begin(),b.end(),e));
                    k.push_back(e);
                    printf("마피아가 한명을 죽였습니다...\n");
                    std::cout << "죽은자" << '\n';
                    for(int i=0;i<k.size();i++)
                    {
                        std::cout<<k[i]<<" ";
                    }
                    
                }
                if(b.size()==1)
                {
                    printf("마피아 승리...");
                }
            }

        }

    }
}
