void F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
void T_1 * V_5 ;
V_5 = V_2 -> V_6 + V_7 ;
if ( 0 == F_2 ( V_5 + V_8 ) ) {
F_3 ( V_2 -> V_9 , L_1 ) ;
V_2 -> V_10 = - 1 ;
return;
}
memset ( & V_4 , 0 , sizeof( struct V_3 ) ) ;
V_4 . V_11 = V_2 -> V_11 ;
V_4 . V_12 = 3686400 ;
V_4 . V_13 = V_14 ;
V_4 . V_15 = V_16 ;
V_4 . V_17 = V_5 ;
V_2 -> V_10 = F_4 ( & V_4 ) ;
if ( V_2 -> V_10 < 0 ) {
F_5 ( V_2 -> V_9 , L_2 ) ;
return;
}
F_6 ( V_2 -> V_6 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
if ( V_2 -> V_10 < 0 )
return;
F_8 ( V_2 -> V_6 ) ;
F_9 ( V_2 -> V_10 ) ;
}
