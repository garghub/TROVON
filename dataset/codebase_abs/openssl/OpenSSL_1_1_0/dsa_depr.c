T_1
#else
# include <stdio.h>
# include <time.h>
# include "internal/cryptlib.h"
# include <openssl/evp.h>
# include <openssl/bn.h>
# include <openssl/dsa.h>
# include <openssl/sha.h>
T_2 * F_1 ( int V_1 ,
unsigned char * V_2 , int V_3 ,
int * V_4 , unsigned long * V_5 ,
void (* F_2) ( int , int , void * ) ,
void * V_6 )
{
T_3 * V_7 ;
T_2 * V_8 ;
if ( ( V_8 = F_3 () ) == NULL )
return NULL ;
V_7 = F_4 () ;
if ( V_7 == NULL )
goto V_9;
F_5 ( V_7 , F_2 , V_6 ) ;
if ( F_6 ( V_8 , V_1 , V_2 , V_3 ,
V_4 , V_5 , V_7 ) ) {
F_7 ( V_7 ) ;
return V_8 ;
}
F_7 ( V_7 ) ;
V_9:
F_8 ( V_8 ) ;
return NULL ;
}
