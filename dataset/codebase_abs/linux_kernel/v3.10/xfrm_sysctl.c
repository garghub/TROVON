static void T_1 F_1 ( struct V_1 * V_1 )
{
V_1 -> V_2 . V_3 = V_4 ;
V_1 -> V_2 . V_5 = V_6 ;
V_1 -> V_2 . V_7 = 1 ;
V_1 -> V_2 . V_8 = 30 ;
}
int T_1 F_2 ( struct V_1 * V_1 )
{
struct V_9 * V_10 ;
F_1 ( V_1 ) ;
V_10 = F_3 ( V_11 , sizeof( V_11 ) , V_12 ) ;
if ( ! V_10 )
goto V_13;
V_10 [ 0 ] . V_14 = & V_1 -> V_2 . V_3 ;
V_10 [ 1 ] . V_14 = & V_1 -> V_2 . V_5 ;
V_10 [ 2 ] . V_14 = & V_1 -> V_2 . V_7 ;
V_10 [ 3 ] . V_14 = & V_1 -> V_2 . V_8 ;
if ( V_1 -> V_15 != & V_16 )
V_10 [ 0 ] . V_17 = NULL ;
V_1 -> V_2 . V_18 = F_4 ( V_1 , L_1 , V_10 ) ;
if ( ! V_1 -> V_2 . V_18 )
goto V_19;
return 0 ;
V_19:
F_5 ( V_10 ) ;
V_13:
return - V_20 ;
}
void T_2 F_6 ( struct V_1 * V_1 )
{
struct V_9 * V_10 ;
V_10 = V_1 -> V_2 . V_18 -> V_21 ;
F_7 ( V_1 -> V_2 . V_18 ) ;
F_5 ( V_10 ) ;
}
int T_1 F_2 ( struct V_1 * V_1 )
{
F_1 ( V_1 ) ;
return 0 ;
}
