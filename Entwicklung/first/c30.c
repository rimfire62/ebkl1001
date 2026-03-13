/**********************************************************
* Programm C30.C arbeitet mit Bit-Funktionen
* 19.11.2020 Rieg
**********************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef JNIX
static char *itoa ( int value, char * str, int base );
#endif

int main(void)
{
int i= 26,j= 39,k;
char *cbit;

cbit= (char *)malloc(65);

/*---------------------------------------------------------
* Bit-AND
*--------------------------------------------------------*/
k= i & j;

printf("i= %2d %16s\n",  i,itoa(i,cbit,2));
printf("j= %2d %16s\n",  j,itoa(j,cbit,2));
printf("&= %2d %16s\n\n",k,itoa(k,cbit,2));

/*---------------------------------------------------------
* Bit-OR
*--------------------------------------------------------*/
k= i | j;

printf("i= %2d %16s\n",  i,itoa(i,cbit,2));
printf("j= %2d %16s\n",  j,itoa(j,cbit,2));
printf("|= %2d %16s\n\n",k,itoa(k,cbit,2));

/*---------------------------------------------------------
* Bit-XOR
*--------------------------------------------------------*/
k= i ^ j;

printf("i= %2d %16s\n",  i,itoa(i,cbit,2));
printf("j= %2d %16s\n",  j,itoa(j,cbit,2));
printf("^= %2d %16s\n\n",k,itoa(k,cbit,2));

/*---------------------------------------------------------
* Bit-NOT
*--------------------------------------------------------*/
k= ~i;

printf("i= %2d %16s\n",  i,itoa(i,cbit,2));
printf("~= %2d %16s\n\n",k,itoa(k,cbit,2));

/*---------------------------------------------------------
* Bit-SHL  (shift left)
*--------------------------------------------------------*/
k= i << 2;

printf("   i= %3d %16s\n",  i,itoa(i,cbit,2));
printf("<< 2= %3d %16s\n\n",k,itoa(k,cbit,2));

/*---------------------------------------------------------
* Bit-SHR  (shift right)
*--------------------------------------------------------*/
k= i >> 2;

printf("   i= %2d %16s\n",  i,itoa(i,cbit,2));
printf(">> 2= %2d %16s\n\n",k,itoa(k,cbit,2));

return(0);
}

#ifdef JNIX
/**********************************************************
* Fuction itoa ist kein C-Standard, daher eine Function aus
* dem Internet von User waaagh in stackoverflow
* 19.11.2020 Rieg
**********************************************************/
#define INT_LEN (10)
#define HEX_LEN (8)
#define BIN_LEN (32)
#define OCT_LEN (11)

static char *itoa ( int value, char * str, int base )
{
    int i,n =2,tmp;
    char buf[BIN_LEN+1];


    switch(base)
    {
        case 16:
            for(i = 0;i<HEX_LEN;++i)
            {
                if(value/base>0)
                {
                    n++;
                }
            }
            snprintf(str, n, "%x" ,value);
            break;
        case 10:
            for(i = 0;i<INT_LEN;++i)
            {
                if(value/base>0)
                {
                    n++;
                }
            }
            snprintf(str, n, "%d" ,value);
            break;
        case 8:
            for(i = 0;i<OCT_LEN;++i)
            {
                if(value/base>0)
                {
                    n++;
                }
            }
            snprintf(str, n, "%o" ,value);
            break;
        case 2:
            for(i = 0,tmp = value;i<BIN_LEN;++i)
            {
                if(tmp/base>0)
                {
                    n++;
                }
                tmp/=base;
            }
            for(i = 1 ,tmp = value; i<n;++i)
            {
                if(tmp%2 != 0)
                {
                    buf[n-i-1] ='1';
                }
                else
                {
                    buf[n-i-1] ='0';
                }
                tmp/=base;
            }
            buf[n-1] = '\0';
            strcpy(str,buf);
            break;
        default:
            return NULL;
    }
    return str;
}
#endif


