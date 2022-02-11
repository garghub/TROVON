T_1
#else
# include <stdio.h>
# include <time.h>
# include "internal/cryptlib.h"
# include "bn_lcl.h"
T_2 * F_1 ( T_2 * V_1 , int V_2 , int V_3 ,
const T_2 * V_4 , const T_2 * V_5 ,
void (* F_2) ( int , int , void * ) , void * V_6 )
{
T_3 V_7 ;
T_2 * V_8 = NULL ;
F_3 ( & V_7 , F_2 , V_6 ) ;
if ( V_1 == NULL ) {
if ( ( V_8 = F_4 () ) == NULL )
goto V_9;
} else
V_8 = V_1 ;
if ( ! F_5 ( V_8 , V_2 , V_3 , V_4 , V_5 , & V_7 ) )
goto V_9;
return V_1 ;
V_9:
F_6 ( V_8 ) ;
return NULL ;
}
int F_7 ( const T_2 * V_10 , int V_11 ,
void (* F_2) ( int , int , void * ) , T_4 * V_12 ,
void * V_6 )
{
T_3 V_7 ;
F_3 ( & V_7 , F_2 , V_6 ) ;
return F_8 ( V_10 , V_11 , V_12 , & V_7 ) ;
}
int F_9 ( const T_2 * V_10 , int V_11 ,
void (* F_2) ( int , int , void * ) ,
T_4 * V_12 , void * V_6 ,
int V_13 )
{
T_3 V_7 ;
F_3 ( & V_7 , F_2 , V_6 ) ;
return F_10 ( V_10 , V_11 , V_12 ,
V_13 , & V_7 ) ;
}
