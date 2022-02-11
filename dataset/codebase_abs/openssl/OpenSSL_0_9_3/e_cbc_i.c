T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static void F_2 ( T_2 * V_2 , unsigned char * V_3 ,
unsigned char * V_4 , int V_5 )
{
if ( V_4 != NULL )
memcpy ( & ( V_2 -> V_6 [ 0 ] ) , V_4 , 8 ) ;
memcpy ( & ( V_2 -> V_4 [ 0 ] ) , & ( V_2 -> V_6 [ 0 ] ) , 8 ) ;
if ( V_3 != NULL )
{
if ( V_5 )
F_3 ( V_3 , & ( V_2 -> V_7 . V_8 ) ) ;
else
{
T_3 V_9 ;
F_3 ( V_3 , & V_9 ) ;
F_4 ( & V_9 , & ( V_2 -> V_7 . V_8 ) ) ;
memset ( ( unsigned char * ) & V_9 , 0 ,
sizeof( T_3 ) ) ;
}
}
}
static void F_5 ( T_2 * V_2 , unsigned char * V_10 ,
unsigned char * V_11 , unsigned int V_12 )
{
F_6 (
V_11 , V_10 , ( long ) V_12 ,
& ( V_2 -> V_7 . V_8 ) , & ( V_2 -> V_4 [ 0 ] ) ,
V_2 -> V_13 ) ;
}
