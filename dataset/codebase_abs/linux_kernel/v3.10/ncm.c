static int T_1 F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_3 -> V_4 ) ) {
V_2 -> V_5 = V_6 ;
V_2 -> V_7 |= V_8 ;
}
return F_3 ( V_2 , V_9 , V_10 ) ;
}
static int T_1 F_4 ( struct V_11 * V_3 )
{
struct V_12 * V_4 = V_3 -> V_4 ;
int V_13 ;
V_10 = F_5 ( V_3 -> V_4 , V_9 ) ;
if ( F_6 ( V_10 ) )
return F_7 ( V_10 ) ;
V_13 = F_8 ( V_3 , V_14 ) ;
if ( V_13 < 0 )
goto V_15;
V_16 . V_17 = V_14 [ V_18 ] . V_19 ;
V_16 . V_20 = V_14 [ V_21 ] . V_19 ;
V_13 = F_9 ( V_3 , & V_22 ,
F_1 ) ;
if ( V_13 < 0 )
goto V_15;
F_10 ( V_3 , & V_23 ) ;
F_11 ( & V_4 -> V_24 , L_1 , V_25 ) ;
return 0 ;
V_15:
F_12 ( V_10 ) ;
return V_13 ;
}
static int T_2 F_13 ( struct V_11 * V_3 )
{
F_12 ( V_10 ) ;
return 0 ;
}
static int T_1 F_14 ( void )
{
return F_15 ( & V_26 ) ;
}
static void T_2 F_16 ( void )
{
F_17 ( & V_26 ) ;
}
