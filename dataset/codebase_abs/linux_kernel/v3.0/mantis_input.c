int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
V_5 = F_2 ( & V_6 ) ;
if ( V_5 )
goto V_7;
V_4 = F_3 () ;
if ( ! V_4 ) {
F_4 ( V_8 , 1 , L_1 ) ;
V_5 = - V_9 ;
goto V_10;
}
sprintf ( V_2 -> V_11 , L_2 , V_2 -> V_12 -> V_13 ) ;
sprintf ( V_2 -> V_14 , L_3 , F_5 ( V_2 -> V_15 ) ) ;
V_4 -> V_11 = V_2 -> V_11 ;
V_4 -> V_14 = V_2 -> V_14 ;
V_4 -> V_16 . V_17 = V_18 ;
V_4 -> V_16 . V_19 = V_2 -> V_20 ;
V_4 -> V_16 . V_21 = V_2 -> V_22 ;
V_4 -> V_16 . V_23 = 1 ;
V_4 -> V_24 = V_25 ;
V_4 -> V_26 = V_27 ;
V_4 -> V_4 . V_28 = & V_2 -> V_15 -> V_4 ;
V_5 = F_6 ( V_4 ) ;
if ( V_5 ) {
F_4 ( V_8 , 1 , L_4 , V_5 ) ;
goto V_29;
}
V_2 -> V_30 = V_4 ;
return 0 ;
V_29:
F_7 ( V_4 ) ;
V_10:
F_8 ( & V_6 ) ;
V_7:
return V_5 ;
}
int F_9 ( struct V_1 * V_2 )
{
F_10 ( V_2 -> V_30 ) ;
F_8 ( & V_6 ) ;
return 0 ;
}
