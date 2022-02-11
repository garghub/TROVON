void F_1 ( const union V_1 * V_2 ,
union V_3 * V_4 )
{
V_4 -> V_5 . V_6 = V_2 -> V_5 . V_6 ;
}
void F_2 ( const union V_3 * V_4 ,
union V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_5 . V_6 = V_4 -> V_5 . V_6 ;
}
