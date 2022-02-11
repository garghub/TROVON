T_1
#else
# include <stddef.h>
# include "ec_lcl.h"
void F_1 ( T_2 V_1 , void * V_2 ,
T_2 V_3 ,
void * V_4 ,
void (* F_2) ( void * V_5 ) ,
int (* F_3) ( const void
* V_6 ) ,
void (* F_4) ( void * V_5 ,
const void
* V_6 ) ,
void (* F_5) ( void * V_5 ,
const void
* V_6 ) ,
void (* F_6) ( void * V_5 ,
const void
* V_7 ,
const void
* V_8 ) ,
void (* F_7) ( void * V_5 ,
const void
* V_6 ) ,
void (* F_8) ( void
* V_5 ,
const
void
* V_6 ) )
{
int V_9 = 0 ;
# define F_9 ( T_3 ) (&((char *)tmp_felems)[(I) * felem_size])
# define F_10 ( T_3 ) (&((char *)point_array)[3*(I) * felem_size])
# define F_11 ( T_3 ) (&((char *)point_array)[(3*(I) + 1) * felem_size])
# define F_12 ( T_3 ) (&((char *)point_array)[(3*(I) + 2) * felem_size])
if ( ! F_3 ( F_12 ( 0 ) ) )
F_4 ( F_9 ( 0 ) , F_12 ( 0 ) ) ;
else
F_2 ( F_9 ( 0 ) ) ;
for ( V_9 = 1 ; V_9 < ( int ) V_1 ; V_9 ++ ) {
if ( ! F_3 ( F_12 ( V_9 ) ) )
F_6 ( F_9 ( V_9 ) , F_9 ( V_9 - 1 ) , F_12 ( V_9 ) ) ;
else
F_4 ( F_9 ( V_9 ) , F_9 ( V_9 - 1 ) ) ;
}
F_7 ( F_9 ( V_1 - 1 ) , F_9 ( V_1 - 1 ) ) ;
for ( V_9 = V_1 - 1 ; V_9 >= 0 ; V_9 -- ) {
if ( V_9 > 0 )
F_6 ( F_9 ( V_1 ) , F_9 ( V_9 - 1 ) , F_9 ( V_9 ) ) ;
else
F_4 ( F_9 ( V_1 ) , F_9 ( 0 ) ) ;
if ( ! F_3 ( F_12 ( V_9 ) ) ) {
if ( V_9 > 0 )
F_6 ( F_9 ( V_9 - 1 ) , F_9 ( V_9 ) , F_12 ( V_9 ) ) ;
F_5 ( F_12 ( V_9 ) , F_9 ( V_1 ) ) ;
F_6 ( F_10 ( V_9 ) , F_10 ( V_9 ) , F_12 ( V_9 ) ) ;
F_6 ( F_12 ( V_9 ) , F_12 ( V_9 ) , F_9 ( V_1 ) ) ;
F_6 ( F_11 ( V_9 ) , F_11 ( V_9 ) , F_12 ( V_9 ) ) ;
F_8 ( F_10 ( V_9 ) , F_10 ( V_9 ) ) ;
F_8 ( F_11 ( V_9 ) , F_11 ( V_9 ) ) ;
F_2 ( F_12 ( V_9 ) ) ;
} else {
if ( V_9 > 0 )
F_4 ( F_9 ( V_9 - 1 ) , F_9 ( V_9 ) ) ;
}
}
}
void F_13 ( unsigned char * V_10 ,
unsigned char * V_11 , unsigned char V_6 )
{
unsigned char V_12 , V_13 ;
V_12 = ~ ( ( V_6 >> 5 ) - 1 ) ;
V_13 = ( 1 << 6 ) - V_6 - 1 ;
V_13 = ( V_13 & V_12 ) | ( V_6 & ~ V_12 ) ;
V_13 = ( V_13 >> 1 ) + ( V_13 & 1 ) ;
* V_10 = V_12 & 1 ;
* V_11 = V_13 ;
}
