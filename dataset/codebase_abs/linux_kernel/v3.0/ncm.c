static int T_1 F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_3 -> V_4 ) ) {
V_2 -> V_5 = V_6 ;
V_2 -> V_7 |= V_8 ;
}
return F_3 ( V_2 , V_9 ) ;
}
static int T_1 F_4 ( struct V_10 * V_3 )
{
int V_11 ;
struct V_12 * V_4 = V_3 -> V_4 ;
int V_13 ;
V_13 = F_5 ( V_3 -> V_4 , V_9 ) ;
if ( V_13 < 0 )
return V_13 ;
V_11 = F_6 ( V_4 ) ;
if ( V_11 >= 0 )
V_14 . V_15 = F_7 ( 0x0300 | V_11 ) ;
else {
F_8 ( & V_4 -> V_16 ,
L_1 ,
V_4 -> V_17 ,
V_18 . V_19 ) ;
V_14 . V_15 =
F_7 ( 0x0300 | 0x0099 ) ;
}
snprintf ( V_20 , sizeof V_20 , L_2 ,
F_9 () -> V_21 , F_9 () -> V_22 ,
V_4 -> V_17 ) ;
V_13 = F_10 ( V_3 ) ;
if ( V_13 < 0 )
goto V_23;
V_24 [ V_25 ] . V_26 = V_13 ;
V_14 . V_27 = V_13 ;
V_13 = F_10 ( V_3 ) ;
if ( V_13 < 0 )
goto V_23;
V_24 [ V_28 ] . V_26 = V_13 ;
V_14 . V_29 = V_13 ;
V_13 = F_11 ( V_3 , & V_18 ,
F_1 ) ;
if ( V_13 < 0 )
goto V_23;
F_12 ( & V_4 -> V_16 , L_3 , V_30 ) ;
return 0 ;
V_23:
F_13 () ;
return V_13 ;
}
static int T_2 F_14 ( struct V_10 * V_3 )
{
F_13 () ;
return 0 ;
}
static int T_1 F_15 ( void )
{
return F_16 ( & V_31 , F_4 ) ;
}
static void T_2 F_17 ( void )
{
F_18 ( & V_31 ) ;
}
