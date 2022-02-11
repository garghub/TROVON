T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
T_1 * F_2 ( void )
{
return ( & V_2 ) ;
}
static void F_3 ( T_2 * V_3 , unsigned char * V_4 ,
unsigned char * V_5 , int V_6 )
{
T_3 * V_7 = ( T_3 * ) V_4 ;
if ( V_5 != NULL )
memcpy ( & ( V_3 -> V_8 [ 0 ] ) , V_5 , 8 ) ;
memcpy ( & ( V_3 -> V_5 [ 0 ] ) , & ( V_3 -> V_8 [ 0 ] ) , 8 ) ;
if ( V_7 != NULL )
{
F_4 ( & V_7 [ 0 ] , V_3 -> V_9 . V_10 . V_11 ) ;
F_4 ( & V_7 [ 1 ] , V_3 -> V_9 . V_10 . V_12 ) ;
memcpy ( ( char * ) V_3 -> V_9 . V_10 . V_13 ,
( char * ) V_3 -> V_9 . V_10 . V_11 ,
sizeof( V_3 -> V_9 . V_10 . V_11 ) ) ;
}
}
static void F_5 ( T_2 * V_3 , unsigned char * V_4 ,
unsigned char * V_5 , int V_6 )
{
T_3 * V_7 = ( T_3 * ) V_4 ;
if ( V_5 != NULL )
memcpy ( & ( V_3 -> V_8 [ 0 ] ) , V_5 , 8 ) ;
memcpy ( & ( V_3 -> V_5 [ 0 ] ) , & ( V_3 -> V_8 [ 0 ] ) , 8 ) ;
if ( V_7 != NULL )
{
F_4 ( & V_7 [ 0 ] , V_3 -> V_9 . V_10 . V_11 ) ;
F_4 ( & V_7 [ 1 ] , V_3 -> V_9 . V_10 . V_12 ) ;
F_4 ( & V_7 [ 2 ] , V_3 -> V_9 . V_10 . V_13 ) ;
}
}
static void F_6 ( T_2 * V_3 , unsigned char * V_14 ,
unsigned char * V_15 , unsigned int V_16 )
{
F_7 ( V_15 , V_14 , V_16 , V_3 -> V_9 . V_10 . V_11 ,
V_3 -> V_9 . V_10 . V_12 , V_3 -> V_9 . V_10 . V_13 ,
( T_3 * ) & ( V_3 -> V_5 [ 0 ] ) ,
V_3 -> V_17 ) ;
}
