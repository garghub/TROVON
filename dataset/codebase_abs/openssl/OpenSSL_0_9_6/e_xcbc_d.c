T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 , const unsigned char * V_3 ,
const unsigned char * V_4 , int V_5 )
{
T_3 * V_6 = ( T_3 * ) V_3 ;
F_3 ( V_6 , V_2 -> V_7 . V_8 . V_9 ) ;
memcpy ( & ( V_2 -> V_7 . V_8 . V_10 [ 0 ] ) , & ( V_3 [ 8 ] ) , 8 ) ;
memcpy ( & ( V_2 -> V_7 . V_8 . V_11 [ 0 ] ) , & ( V_3 [ 16 ] ) , 8 ) ;
return 1 ;
}
static int F_4 ( T_2 * V_2 , unsigned char * V_12 ,
const unsigned char * V_13 , unsigned int V_14 )
{
F_5 ( V_13 , V_12 , V_14 , V_2 -> V_7 . V_8 . V_9 ,
( T_3 * ) & ( V_2 -> V_4 [ 0 ] ) ,
& V_2 -> V_7 . V_8 . V_10 ,
& V_2 -> V_7 . V_8 . V_11 ,
V_2 -> V_15 ) ;
return 1 ;
}
