static int T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( F_2 ( V_2 -> V_4 -> V_5 ) ) {
V_2 -> V_6 = V_7 ;
V_2 -> V_8 |= V_9 ;
}
V_3 = F_3 ( V_2 , V_10 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static int T_1 F_5 ( struct V_11 * V_4 )
{
int V_12 ;
struct V_13 * V_5 = V_4 -> V_5 ;
int V_3 ;
if ( ! F_6 ( V_4 -> V_5 ) ) {
F_7 ( & V_5 -> V_14 , L_1 ,
V_5 -> V_15 ) ;
return - V_16 ;
}
V_3 = F_8 ( V_4 -> V_5 , V_10 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_9 ( V_4 -> V_5 , 1 ) ;
if ( V_3 < 0 )
goto V_17;
V_12 = F_10 ( V_5 ) ;
if ( V_12 >= 0 )
V_18 . V_19 = F_11 ( 0x0300 | V_12 ) ;
else {
F_12 ( V_4 , L_2 ,
V_5 -> V_15 ,
V_20 . V_21 ) ;
V_18 . V_19 =
F_11 ( 0x0300 | 0x0099 ) ;
}
snprintf ( V_22 , sizeof V_22 , L_3 ,
F_13 () -> V_23 , F_13 () -> V_24 ,
V_5 -> V_15 ) ;
V_3 = F_14 ( V_4 ) ;
if ( V_3 < 0 )
goto V_25;
V_26 [ V_27 ] . V_28 = V_3 ;
V_18 . V_29 = V_3 ;
V_3 = F_14 ( V_4 ) ;
if ( V_3 < 0 )
goto V_25;
V_26 [ V_30 ] . V_28 = V_3 ;
V_18 . V_31 = V_3 ;
V_3 = F_15 ( V_4 , & V_20 , F_1 ) ;
if ( V_3 < 0 )
goto V_25;
F_16 ( & V_5 -> V_14 , L_4 V_32 L_5 ,
V_33 ) ;
return 0 ;
V_25:
F_17 () ;
V_17:
F_18 () ;
return V_3 ;
}
static int T_2 F_19 ( struct V_11 * V_4 )
{
F_17 () ;
F_18 () ;
return 0 ;
}
static int T_1 F_20 ( void )
{
return F_21 ( & V_34 , F_5 ) ;
}
static void T_2 F_22 ( void )
{
F_23 ( & V_34 ) ;
}
