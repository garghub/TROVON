T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
T_1 * F_2 ( void )
{
return ( & V_2 ) ;
}
static int F_3 ( T_2 * V_3 , const unsigned char * V_4 ,
const unsigned char * V_5 , int V_6 )
{
F_4 ( & ( V_3 -> V_7 . V_8 . V_9 ) , F_5 ( V_3 ) ,
V_4 , V_3 -> V_7 . V_8 . V_10 ) ;
return 1 ;
}
static int F_6 ( T_2 * V_11 )
{
int V_12 ;
F_7 ( V_11 , V_13 , 0 , & V_12 ) ;
if ( V_12 == 128 ) return ( V_14 ) ;
else if ( V_12 == 64 ) return ( V_15 ) ;
else if ( V_12 == 40 ) return ( V_16 ) ;
else return ( 0 ) ;
}
static int F_8 ( int V_12 )
{
if ( V_12 == V_14 ) return 128 ;
else if ( V_12 == V_15 ) return 64 ;
else if ( V_12 == V_16 ) return 40 ;
else
{
F_9 ( V_17 , V_18 ) ;
return ( 0 ) ;
}
}
static int F_10 ( T_2 * V_7 , T_3 * type )
{
long V_19 = 0 ;
int V_12 = 0 , V_20 ;
int V_10 ;
unsigned char V_5 [ V_21 ] ;
if ( type != NULL )
{
V_20 = F_11 ( V_7 ) ;
V_12 = F_12 ( type , & V_19 , V_5 , V_20 ) ;
if ( V_12 != V_20 )
return ( - 1 ) ;
V_10 = F_8 ( ( int ) V_19 ) ;
if ( ! V_10 )
return ( - 1 ) ;
if( V_12 > 0 ) F_13 ( V_7 , NULL , NULL , V_5 , - 1 ) ;
F_7 ( V_7 , V_22 , V_10 , NULL ) ;
F_14 ( V_7 , V_10 / 8 ) ;
}
return ( V_12 ) ;
}
static int F_15 ( T_2 * V_7 , T_3 * type )
{
long V_19 ;
int V_12 = 0 , V_23 ;
if ( type != NULL )
{
V_19 = F_6 ( V_7 ) ;
V_23 = F_11 ( V_7 ) ;
V_12 = F_16 ( type , V_19 , V_7 -> V_24 , V_23 ) ;
}
return ( V_12 ) ;
}
static int F_17 ( T_2 * V_7 , int type , int V_25 , void * V_26 )
{
switch( type ) {
case V_27 :
V_7 -> V_7 . V_8 . V_10 = F_5 ( V_7 ) * 8 ;
return 1 ;
case V_13 :
* ( int * ) V_26 = V_7 -> V_7 . V_8 . V_10 ;
return 1 ;
case V_22 :
if( V_25 > 0 ) {
V_7 -> V_7 . V_8 . V_10 = V_25 ;
return 1 ;
}
return 0 ;
default:
return - 1 ;
}
}
