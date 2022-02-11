T_1
#else
# include <stdio.h>
# include "internal/cryptlib.h"
# include <openssl/bn.h>
# include <openssl/dh.h>
T_2 * F_1 ( int V_1 , int V_2 ,
void (* F_2) ( int , int , void * ) , void * V_3 )
{
T_3 * V_4 ;
T_2 * V_5 = NULL ;
if ( ( V_5 = F_3 () ) == NULL )
return NULL ;
V_4 = F_4 () ;
if ( V_4 == NULL ) {
F_5 ( V_5 ) ;
return NULL ;
}
F_6 ( V_4 , F_2 , V_3 ) ;
if ( F_7 ( V_5 , V_1 , V_2 , V_4 ) ) {
F_8 ( V_4 ) ;
return V_5 ;
}
F_8 ( V_4 ) ;
F_5 ( V_5 ) ;
return NULL ;
}
