#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int a;
    int i=0;
    printf("인원 수를 입력하세요");
    scanf("%d",&a);
    char b[a]={};


    for(int i=0;i<a;i++)
    {
         b[i]=i+1;
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
            memmove(b+d,b+d+1,strlen(b)-d);
            printf(b);
            printf("틀렷습니다.마피아가 한명 죽이려 시도합니다...");
            srand(time(NULL));
            int e=(rand()%a)+1;
            if(e==c)
            {
                printf("마피아 살인 실패!");
                continue;
            }
            else
            {
                memmove(b+e,b+e+1,strlen(b)-e);
                printf(b);
                printf("마피아가 한명을 죽였습니다...");
            }
            if(strlen(b)==1)
            {
                printf("마피아 승리...");
            }

        }

    }
}
