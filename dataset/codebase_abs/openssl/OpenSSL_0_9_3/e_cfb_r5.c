T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static void F_2 ( T_2 * V_2 , unsigned char * V_3 ,
unsigned char * V_4 , int V_5 )
{
V_2 -> V_6 = 0 ;
if ( V_4 != NULL )
memcpy ( & ( V_2 -> V_7 [ 0 ] ) , V_4 , 8 ) ;
memcpy ( & ( V_2 -> V_4 [ 0 ] ) , & ( V_2 -> V_7 [ 0 ] ) , 8 ) ;
if ( V_3 != NULL )
F_3 ( & ( V_2 -> V_8 . V_9 ) , V_10 , V_3 ,
V_11 ) ;
}
static void F_4 ( T_2 * V_2 , unsigned char * V_12 ,
unsigned char * V_13 , unsigned int V_14 )
{
F_5 (
V_13 , V_12 ,
( long ) V_14 , & ( V_2 -> V_8 . V_9 ) ,
& ( V_2 -> V_4 [ 0 ] ) ,
& V_2 -> V_6 , V_2 -> V_15 ) ;
}
