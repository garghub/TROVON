static int F_1 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , unsigned int V_4 )
{
F_2 ()
F_3 ( ( V_5 * ) ( V_3 + V_6 ) , ( V_5 * ) ( V_2 + V_6 ) , V_1 -> V_7 , V_1 -> V_8 ) ;
return 1 ;
}
static int F_4 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , unsigned int V_4 )
{
F_5 ( V_3 , V_2 , ( long ) V_4 , V_1 -> V_7 , ( V_5 * ) V_1 -> V_9 , & V_1 -> V_10 ) ;
return 1 ;
}
static int F_6 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , unsigned int V_4 )
{
F_7 ( V_3 , V_2 , ( long ) V_4 , V_1 -> V_7 ,
( V_5 * ) V_1 -> V_9 , V_1 -> V_8 ) ;
return 1 ;
}
static int F_8 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , unsigned int V_4 )
{
F_9 ( V_3 , V_2 , ( long ) V_4 , V_1 -> V_7 ,
( V_5 * ) V_1 -> V_9 , & V_1 -> V_10 , V_1 -> V_8 ) ;
return 1 ;
}
static int F_10 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , unsigned int V_4 )
{
unsigned int V_11 ;
unsigned char V_12 [ 1 ] , V_13 [ 1 ] ;
for( V_11 = 0 ; V_11 < V_4 ; ++ V_11 )
{
V_12 [ 0 ] = ( V_3 [ V_11 / 8 ] & ( 1 << ( 7 - V_11 % 8 ) ) ) ? 0x80 : 0 ;
F_11 ( V_12 , V_13 , 1 , 1 , V_1 -> V_7 , ( V_5 * ) V_1 -> V_9 ,
V_1 -> V_8 ) ;
V_2 [ V_11 / 8 ] = ( V_2 [ V_11 / 8 ] & ~ ( 0x80 >> ( V_11 % 8 ) ) ) | ( ( V_13 [ 0 ] & 0x80 ) >> ( V_11 % 8 ) ) ;
}
return 1 ;
}
static int F_12 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , unsigned int V_4 )
{
F_11 ( V_3 , V_2 , 8 , V_4 , V_1 -> V_7 , ( V_5 * ) V_1 -> V_9 ,
V_1 -> V_8 ) ;
return 1 ;
}
static int F_13 ( T_1 * V_1 , const unsigned char * V_14 ,
const unsigned char * V_9 , int V_15 )
{
V_5 * V_16 = ( V_5 * ) V_14 ;
#ifdef F_14
if( F_15 ( V_16 , V_1 -> V_7 ) != 0 )
return 0 ;
#else
F_16 ( V_16 , V_1 -> V_7 ) ;
#endif
return 1 ;
}
static int F_17 ( T_1 * V_12 , int type , int V_17 , void * V_18 )
{
switch( type )
{
case V_19 :
if ( F_18 ( V_18 , 8 ) <= 0 )
return 0 ;
F_19 ( ( V_5 * ) V_18 ) ;
return 1 ;
default:
return - 1 ;
}
}
