void F_1 ( const T_1 * V_1 ,
T_2 * V_2 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_3 . V_4 = V_1 -> V_3 . V_4 ;
}
void F_2 ( const T_2 * V_2 ,
T_1 * V_1 )
{
memset ( V_1 , 0 , sizeof( * V_1 ) ) ;
V_1 -> V_3 . V_4 = V_2 -> V_3 . V_4 ;
}
