int F_1 ( T_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
memset ( & ( V_3 -> V_5 ) , 0 , sizeof( V_6 ) ) ;
F_2 ( & ( V_3 -> V_7 ) , & V_8 ) ;
V_3 -> V_5 . V_9 = & ( V_3 -> V_7 ) ;
return 1 ;
}
int F_3 ( T_1 * V_1 , const void * V_10 , T_2 V_11 )
{
return F_4 ( ( V_6 * ) V_1 -> V_4 , V_10 , V_11 ) ;
}
int F_5 ( T_1 * V_1 , unsigned char * V_12 )
{
return F_6 ( ( V_6 * ) V_1 -> V_4 , V_12 ) ;
}
int F_7 ( T_1 * V_13 , const T_1 * V_14 )
{
struct V_2 * V_15 = V_13 -> V_4 ;
if ( V_13 -> V_4 && V_14 -> V_4 ) {
memcpy ( V_13 -> V_4 , V_14 -> V_4 ,
sizeof( struct V_2 ) ) ;
V_15 -> V_5 . V_9 = & ( V_15 -> V_7 ) ;
}
return 1 ;
}
int F_8 ( T_1 * V_1 )
{
if ( V_1 -> V_4 )
memset ( V_1 -> V_4 , 0 , sizeof( struct V_2 ) ) ;
return 1 ;
}
