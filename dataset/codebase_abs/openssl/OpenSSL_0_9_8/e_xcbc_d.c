const T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 , const unsigned char * V_3 ,
const unsigned char * V_4 , int V_5 )
{
T_3 * V_6 = ( T_3 * ) V_3 ;
F_3 ( V_6 , & F_4 ( V_2 ) -> V_7 ) ;
memcpy ( & F_4 ( V_2 ) -> V_8 [ 0 ] , & V_3 [ 8 ] , 8 ) ;
memcpy ( & F_4 ( V_2 ) -> V_9 [ 0 ] , & V_3 [ 16 ] , 8 ) ;
return 1 ;
}
static int F_5 ( T_2 * V_2 , unsigned char * V_10 ,
const unsigned char * V_11 , unsigned int V_12 )
{
F_6 ( V_11 , V_10 , V_12 , & F_4 ( V_2 ) -> V_7 ,
( T_3 * ) & ( V_2 -> V_4 [ 0 ] ) ,
& F_4 ( V_2 ) -> V_8 ,
& F_4 ( V_2 ) -> V_9 ,
V_2 -> V_13 ) ;
return 1 ;
}
