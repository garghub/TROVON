static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( & V_2 -> V_6 , L_1 , V_3 ) ;
if ( V_3 != 0x88 ) {
F_4 ( & V_2 -> V_6 , L_2 , V_3 ) ;
return;
}
F_5 ( V_5 -> V_7 , V_8 , 1 ) ;
F_5 ( V_5 -> V_7 , V_8 , 0 ) ;
F_6 ( V_5 -> V_7 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
V_5 = F_8 ( & V_2 -> V_6 , sizeof( * V_5 ) , V_9 ) ;
if ( ! V_5 )
return - V_10 ;
V_2 -> V_11 = V_5 ;
V_5 -> V_7 = F_9 ( & V_2 -> V_6 ) ;
if ( ! V_5 -> V_7 )
return - V_10 ;
V_5 -> V_7 -> V_12 = L_3 ;
V_5 -> V_7 -> V_13 = L_4 ;
V_5 -> V_7 -> V_14 . V_15 = V_16 ;
V_5 -> V_7 -> V_14 . V_17 = V_18 ;
F_10 ( V_19 , V_5 -> V_7 -> V_20 ) ;
F_10 ( V_8 , V_5 -> V_7 -> V_21 ) ;
return F_11 ( V_5 -> V_7 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
return 0 ;
}
