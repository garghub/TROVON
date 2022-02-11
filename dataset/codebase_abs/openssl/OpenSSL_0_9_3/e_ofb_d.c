T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static void F_2 ( T_2 * V_2 , unsigned char * V_3 ,
unsigned char * V_4 , int V_5 )
{
T_3 * V_6 = ( T_3 * ) V_3 ;
V_2 -> V_7 = 0 ;
if ( V_4 != NULL )
memcpy ( & ( V_2 -> V_8 [ 0 ] ) , V_4 , 8 ) ;
memcpy ( & ( V_2 -> V_4 [ 0 ] ) , & ( V_2 -> V_8 [ 0 ] ) , 8 ) ;
if ( V_6 != NULL )
F_3 ( V_6 , V_2 -> V_9 . V_10 ) ;
}
static void F_4 ( T_2 * V_2 , unsigned char * V_11 ,
unsigned char * V_12 , unsigned int V_13 )
{
F_5 ( V_12 , V_11 , V_13 , V_2 -> V_9 . V_10 ,
( T_3 * ) & ( V_2 -> V_4 [ 0 ] ) , & V_2 -> V_7 ) ;
}
