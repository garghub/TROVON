void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
memset ( V_4 , 0 , sizeof( struct V_3 ) ) ;
V_2 -> V_5 . V_7 = & V_4 -> V_7 ;
memset ( V_2 -> V_5 . V_7 , 0 , sizeof( struct V_8 ) ) ;
return;
}
