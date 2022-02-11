static int T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( F_2 ( V_2 -> V_4 -> V_5 ) ) {
V_2 -> V_6 = V_7 ;
V_2 -> V_8 |= V_9 ;
}
V_3 = F_3 ( V_2 , V_10 , V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
V_12 = F_4 ( L_1 ) ;
if ( F_5 ( V_12 ) )
return F_6 ( V_12 ) ;
V_13 = F_7 ( V_12 ) ;
if ( F_5 ( V_13 ) ) {
V_3 = F_6 ( V_13 ) ;
goto V_14;
}
V_3 = F_8 ( V_2 , V_13 ) ;
if ( V_3 )
goto V_15;
return 0 ;
V_15:
F_9 ( V_13 ) ;
V_14:
F_10 ( V_12 ) ;
return V_3 ;
}
static int T_1 F_11 ( struct V_16 * V_4 )
{
struct V_17 * V_5 = V_4 -> V_5 ;
int V_3 ;
if ( ! F_12 ( V_4 -> V_5 ) ) {
F_13 ( & V_5 -> V_18 , L_2 ,
V_5 -> V_19 ) ;
return - V_20 ;
}
V_11 = F_14 ( V_4 -> V_5 , V_10 ) ;
if ( F_5 ( V_11 ) )
return F_6 ( V_11 ) ;
V_3 = F_15 ( V_4 , V_21 ) ;
if ( V_3 < 0 )
goto V_22;
V_23 . V_24 = V_21 [ V_25 ] . V_26 ;
V_23 . V_27 = V_21 [ V_28 ] . V_26 ;
V_3 = F_16 ( V_4 , & V_29 , F_1 ) ;
if ( V_3 < 0 )
goto V_22;
F_17 ( V_4 , & V_30 ) ;
F_18 ( & V_5 -> V_18 , L_3 V_31 L_4 ,
V_32 ) ;
return 0 ;
V_22:
F_19 ( V_11 ) ;
return V_3 ;
}
static int T_2 F_20 ( struct V_16 * V_4 )
{
F_9 ( V_13 ) ;
F_10 ( V_12 ) ;
F_19 ( V_11 ) ;
return 0 ;
}
static int T_1 F_21 ( void )
{
return F_22 ( & V_33 ) ;
}
static void T_2 F_23 ( void )
{
F_24 ( & V_33 ) ;
}
