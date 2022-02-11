void T_1 F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 ;
if ( ! V_2 )
V_2 = & V_4 ;
V_3 = F_2 ( V_2 , sizeof( struct V_1 ) , V_5 ) ;
if ( ! V_3 )
F_3 ( V_6 L_1 , V_7 ) ;
else if ( ! V_3 -> V_8 )
V_3 -> V_8 = V_9 ;
V_10 . V_11 . V_12 = V_3 ;
}
