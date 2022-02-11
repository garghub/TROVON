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
F_3 ( & ( V_2 -> V_8 . V_9 ) , F_4 ( V_2 ) ,
V_3 , F_4 ( V_2 ) * 8 ) ;
}
static void F_5 ( T_2 * V_2 , unsigned char * V_10 ,
unsigned char * V_11 , unsigned int V_12 )
{
F_6 (
V_11 , V_10 ,
( long ) V_12 , & ( V_2 -> V_8 . V_9 ) ,
& ( V_2 -> V_4 [ 0 ] ) ,
& V_2 -> V_6 , V_2 -> V_13 ) ;
}
