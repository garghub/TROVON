void T_1 F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 ;
V_3 = F_2 ( V_2 , sizeof( * V_3 ) , & V_4 ) ;
if ( V_3 ) {
V_3 -> V_5 = F_3 ( V_2 -> V_5 ,
sizeof( struct V_6 ) * V_3 -> V_7 ,
V_8 ) ;
if ( ! V_3 -> V_5 )
F_4 ( V_9 L_1 ) ;
} else {
F_4 ( V_9 L_2 ) ;
}
}
void T_1 F_5 ( struct V_10 * V_11 )
{
F_2 ( V_11 ,
sizeof( struct V_10 ) , & V_12 ) ;
}
void T_1 F_6 ( struct V_13 * V_2 )
{
F_2 ( V_2 , sizeof( * V_2 ) , & V_14 ) ;
}
void T_1 F_7 ( struct V_15 * V_2 )
{
F_2 ( V_2 , sizeof( * V_2 ) , & V_16 ) ;
}
void T_1 F_8 ( struct V_17 * V_18 )
{
F_2 ( V_18 , sizeof( struct V_17 ) ,
& V_19 ) ;
}
