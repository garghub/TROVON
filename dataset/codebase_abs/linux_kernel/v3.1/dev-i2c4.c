void T_1 F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 ;
if ( ! V_2 ) {
V_2 = & V_4 ;
V_2 -> V_5 = 4 ;
}
V_3 = F_2 ( V_2 , sizeof( struct V_1 ) ,
& V_6 ) ;
if ( ! V_3 -> V_7 )
V_3 -> V_7 = V_8 ;
}
