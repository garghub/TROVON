static int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_2 V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
V_4 = F_2 ( V_2 , V_10 , 0 ) ;
if ( ! V_4 )
return - V_11 ;
if ( ! F_3 ( V_4 -> V_12 , F_4 ( V_4 ) ,
L_1 ) )
return - V_13 ;
V_7 = F_5 ( sizeof( struct V_6 ) ,
V_14 ) ;
if ( ! V_7 ) {
F_6 ( & V_2 -> V_15 , L_2 ) ;
goto V_16;
}
V_5 = V_4 -> V_12 + V_17 ;
V_7 -> V_18 = ( void V_19 * ) F_7 ( V_5 ) ;
V_7 -> clock = 50 ;
V_7 -> V_20 = 1 ;
V_7 -> V_21 = V_22 ;
V_7 -> V_23 = V_24 ;
V_9 = F_8 ( & V_25 , V_7 ,
& V_2 -> V_15 ) ;
if ( ! V_9 ) {
F_6 ( & V_2 -> V_15 ,
L_3 ) ;
goto V_26;
}
V_9 -> V_27 = 7 ;
V_9 -> V_18 = V_5 ;
V_9 -> V_28 = V_29 ;
if ( F_9 ( V_9 -> V_28 , V_30 , V_31 , L_4 ,
V_9 ) ) {
F_6 ( & V_2 -> V_15 , L_5 ) ;
goto V_32;
}
F_10 ( V_2 , V_9 ) ;
F_11 ( V_9 ) ;
return 0 ;
V_32:
F_12 ( V_9 ) ;
V_26:
F_13 ( V_7 ) ;
V_16:
F_14 ( V_4 -> V_12 , F_4 ( V_4 ) ) ;
return - V_11 ;
}
static int T_3 F_15 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_16 ( V_2 ) ;
struct V_6 * V_7 = F_17 ( V_9 ) ;
struct V_3 * V_4 = F_2 ( V_2 , V_10 , 0 ) ;
F_18 ( V_9 ) ;
F_19 ( V_9 ) ;
F_13 ( V_7 ) ;
F_20 ( V_9 -> V_28 , V_9 ) ;
F_14 ( V_4 -> V_12 , F_4 ( V_4 ) ) ;
return 0 ;
}
