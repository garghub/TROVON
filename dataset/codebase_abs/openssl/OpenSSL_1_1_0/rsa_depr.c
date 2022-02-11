T_1
#else
# include <stdio.h>
# include <time.h>
# include "internal/cryptlib.h"
# include <openssl/bn.h>
# include <openssl/rsa.h>
T_2 * F_1 ( int V_1 , unsigned long V_2 ,
void (* F_2) ( int , int , void * ) , void * V_3 )
{
int V_4 ;
T_3 * V_5 = F_3 () ;
T_2 * V_6 = F_4 () ;
T_4 * V_7 = F_5 () ;
if ( V_5 == NULL || V_6 == NULL || V_7 == NULL )
goto V_8;
for ( V_4 = 0 ; V_4 < ( int )sizeof( unsigned long ) * 8 ; V_4 ++ ) {
if ( V_2 & ( 1UL << V_4 ) )
if ( F_6 ( V_7 , V_4 ) == 0 )
goto V_8;
}
F_7 ( V_5 , F_2 , V_3 ) ;
if ( F_8 ( V_6 , V_1 , V_7 , V_5 ) ) {
F_9 ( V_7 ) ;
F_10 ( V_5 ) ;
return V_6 ;
}
V_8:
F_9 ( V_7 ) ;
F_11 ( V_6 ) ;
F_10 ( V_5 ) ;
return 0 ;
}
