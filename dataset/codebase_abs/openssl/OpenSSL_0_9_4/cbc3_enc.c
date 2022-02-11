void F_1 ( T_1 * V_1 , T_1 * V_2 , long V_3 ,
T_2 V_4 , T_2 V_5 , T_1 * V_6 ,
T_1 * V_7 , int V_8 )
{
int V_9 = ( ( int ) V_3 - 1 ) / 8 ;
long V_10 = ( ( V_3 + 7 ) / 8 ) * 8 ;
T_1 V_11 , V_12 ;
if ( V_8 == V_13 )
{
F_2 ( V_1 , V_2 , V_3 , V_4 , V_6 , V_8 ) ;
if ( V_3 >= sizeof( T_1 ) )
memcpy ( V_11 , V_2 [ V_9 ] , sizeof( T_1 ) ) ;
F_2 ( V_2 , V_2 , V_10 , V_5 , V_6 , ! V_8 ) ;
F_2 ( V_2 , V_2 , V_10 , V_4 , V_7 , V_8 ) ;
if ( V_3 >= sizeof( T_1 ) )
memcpy ( V_12 , V_2 [ V_9 ] , sizeof( T_1 ) ) ;
}
else
{
if ( V_3 >= sizeof( T_1 ) )
memcpy ( V_12 , V_1 [ V_9 ] , sizeof( T_1 ) ) ;
F_2 ( V_1 , V_2 , V_10 , V_4 , V_7 , V_8 ) ;
F_2 ( V_2 , V_2 , V_10 , V_5 , V_6 , ! V_8 ) ;
if ( V_3 >= sizeof( T_1 ) )
memcpy ( V_11 , V_2 [ V_9 ] , sizeof( T_1 ) ) ;
F_2 ( V_2 , V_2 , V_3 , V_4 , V_6 , V_8 ) ;
}
memcpy ( * V_6 , V_11 , sizeof( T_1 ) ) ;
memcpy ( * V_7 , V_12 , sizeof( T_1 ) ) ;
}
