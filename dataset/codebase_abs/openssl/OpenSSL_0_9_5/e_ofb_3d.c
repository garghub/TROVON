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
V_3 -> V_8 = 0 ;
if ( V_5 != NULL )
memcpy ( & ( V_3 -> V_9 [ 0 ] ) , V_5 , 8 ) ;
memcpy ( & ( V_3 -> V_5 [ 0 ] ) , & ( V_3 -> V_9 [ 0 ] ) , 8 ) ;
if ( V_7 != NULL )
{
F_4 ( & V_7 [ 0 ] , V_3 -> V_10 . V_11 . V_12 ) ;
F_4 ( & V_7 [ 1 ] , V_3 -> V_10 . V_11 . V_13 ) ;
memcpy ( ( char * ) V_3 -> V_10 . V_11 . V_14 ,
( char * ) V_3 -> V_10 . V_11 . V_12 ,
sizeof( V_3 -> V_10 . V_11 . V_12 ) ) ;
}
}
static void F_5 ( T_2 * V_3 , unsigned char * V_4 ,
unsigned char * V_5 , int V_6 )
{
T_3 * V_7 = ( T_3 * ) V_4 ;
V_3 -> V_8 = 0 ;
if ( V_5 != NULL )
memcpy ( & ( V_3 -> V_9 [ 0 ] ) , V_5 , 8 ) ;
memcpy ( & ( V_3 -> V_5 [ 0 ] ) , & ( V_3 -> V_9 [ 0 ] ) , 8 ) ;
if ( V_7 != NULL )
{
F_4 ( & V_7 [ 0 ] , V_3 -> V_10 . V_11 . V_12 ) ;
F_4 ( & V_7 [ 1 ] , V_3 -> V_10 . V_11 . V_13 ) ;
F_4 ( & V_7 [ 2 ] , V_3 -> V_10 . V_11 . V_14 ) ;
}
}
static void F_6 ( T_2 * V_3 , unsigned char * V_15 ,
unsigned char * V_16 , unsigned int V_17 )
{
F_7 ( V_16 , V_15 , V_17 , V_3 -> V_10 . V_11 . V_12 ,
V_3 -> V_10 . V_11 . V_13 , V_3 -> V_10 . V_11 . V_14 ,
( T_3 * ) & ( V_3 -> V_5 [ 0 ] ) , & V_3 -> V_8 ) ;
}
