static int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
if ( F_2 ( V_2 -> V_6 -> V_7 ) ) {
V_2 -> V_8 = V_9 ;
V_2 -> V_10 |= V_11 ;
}
V_5 = F_3 ( V_2 , V_12 ) ;
if ( V_5 < 0 )
return V_5 ;
V_13 = F_4 ( L_1 ) ;
if ( F_5 ( V_13 ) )
return F_6 ( V_13 ) ;
V_4 = F_7 ( V_13 , struct V_3 , V_14 ) ;
V_4 -> V_15 = V_16 ;
V_17 = F_8 ( V_13 ) ;
if ( F_5 ( V_17 ) )
goto V_18;
V_5 = F_9 ( V_2 , V_17 ) ;
if ( V_5 )
goto V_19;
return 0 ;
V_19:
F_10 ( V_17 ) ;
V_18:
F_11 ( V_13 ) ;
return V_5 ;
}
static int T_1 F_12 ( struct V_20 * V_6 )
{
struct V_21 * V_7 = V_6 -> V_7 ;
int V_5 ;
if ( ! F_13 ( V_6 -> V_7 ) ) {
F_14 ( & V_7 -> V_22 , L_2 ,
V_7 -> V_23 ) ;
return - V_24 ;
}
V_5 = F_15 ( V_6 -> V_7 , V_12 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_16 ( & V_16 ) ;
if ( V_5 < 0 )
goto V_25;
V_5 = F_17 ( V_6 , V_26 ) ;
if ( V_5 < 0 )
goto V_27;
V_28 . V_29 = V_26 [ V_30 ] . V_31 ;
V_28 . V_32 = V_26 [ V_33 ] . V_31 ;
V_5 = F_18 ( V_6 , & V_34 , F_1 ) ;
if ( V_5 < 0 )
goto V_27;
F_19 ( V_6 , & V_35 ) ;
F_20 ( & V_7 -> V_22 , L_3 V_36 L_4 ,
V_37 ) ;
return 0 ;
V_27:
F_21 ( V_16 ) ;
V_25:
F_22 () ;
return V_5 ;
}
static int T_2 F_23 ( struct V_20 * V_6 )
{
F_10 ( V_17 ) ;
F_11 ( V_13 ) ;
F_21 ( V_16 ) ;
F_22 () ;
return 0 ;
}
static int T_1 F_24 ( void )
{
return F_25 ( & V_38 ) ;
}
static void T_2 F_26 ( void )
{
F_27 ( & V_38 ) ;
}
