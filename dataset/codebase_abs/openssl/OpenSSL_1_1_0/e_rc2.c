const T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
const T_1 * F_2 ( void )
{
return ( & V_2 ) ;
}
static int F_3 ( T_2 * V_3 , const unsigned char * V_4 ,
const unsigned char * V_5 , int V_6 )
{
F_4 ( & F_5 ( V_3 ) -> V_7 , F_6 ( V_3 ) ,
V_4 , F_5 ( V_3 ) -> V_8 ) ;
return 1 ;
}
static int F_7 ( T_2 * V_9 )
{
int V_10 ;
F_8 ( V_9 , V_11 , 0 , & V_10 ) ;
if ( V_10 == 128 )
return ( V_12 ) ;
else if ( V_10 == 64 )
return ( V_13 ) ;
else if ( V_10 == 40 )
return ( V_14 ) ;
else
return ( 0 ) ;
}
static int F_9 ( int V_10 )
{
if ( V_10 == V_12 )
return 128 ;
else if ( V_10 == V_13 )
return 64 ;
else if ( V_10 == V_14 )
return 40 ;
else {
F_10 ( V_15 , V_16 ) ;
return ( 0 ) ;
}
}
static int F_11 ( T_2 * V_17 , T_3 * type )
{
long V_18 = 0 ;
int V_10 = 0 ;
int V_8 ;
unsigned int V_19 ;
unsigned char V_5 [ V_20 ] ;
if ( type != NULL ) {
V_19 = F_12 ( V_17 ) ;
F_13 ( V_19 <= sizeof( V_5 ) ) ;
V_10 = F_14 ( type , & V_18 , V_5 , V_19 ) ;
if ( V_10 != ( int ) V_19 )
return - 1 ;
V_8 = F_9 ( ( int ) V_18 ) ;
if ( ! V_8 )
return - 1 ;
if ( V_10 > 0 && ! F_15 ( V_17 , NULL , NULL , NULL , V_5 , - 1 ) )
return - 1 ;
F_8 ( V_17 , V_21 , V_8 , NULL ) ;
if ( F_16 ( V_17 , V_8 / 8 ) <= 0 )
return - 1 ;
}
return V_10 ;
}
static int F_17 ( T_2 * V_17 , T_3 * type )
{
long V_18 ;
int V_10 = 0 , V_22 ;
if ( type != NULL ) {
V_18 = F_7 ( V_17 ) ;
V_22 = F_12 ( V_17 ) ;
V_10 = F_18 ( type , V_18 ,
( unsigned char * ) F_19 ( V_17 ) ,
V_22 ) ;
}
return ( V_10 ) ;
}
static int F_20 ( T_2 * V_17 , int type , int V_23 , void * V_24 )
{
switch ( type ) {
case V_25 :
F_5 ( V_17 ) -> V_8 = F_6 ( V_17 ) * 8 ;
return 1 ;
case V_11 :
* ( int * ) V_24 = F_5 ( V_17 ) -> V_8 ;
return 1 ;
case V_21 :
if ( V_23 > 0 ) {
F_5 ( V_17 ) -> V_8 = V_23 ;
return 1 ;
}
return 0 ;
# ifdef F_21
case V_26 :
* ( int * ) V_24 = V_27 ;
return 1 ;
# endif
default:
return - 1 ;
}
}
