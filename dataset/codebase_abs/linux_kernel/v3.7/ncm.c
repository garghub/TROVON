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
struct V_11 * V_4 = V_3 -> V_4 ;
int V_12 ;
V_12 = F_5 ( V_3 -> V_4 , V_9 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_6 ( V_3 , V_13 ) ;
if ( V_12 < 0 )
goto V_14;
V_15 . V_16 = V_13 [ V_17 ] . V_18 ;
V_15 . V_19 = V_13 [ V_20 ] . V_18 ;
V_12 = F_7 ( V_3 , & V_21 ,
F_1 ) ;
if ( V_12 < 0 )
goto V_14;
F_8 ( V_3 , & V_22 ) ;
F_9 ( & V_4 -> V_23 , L_1 , V_24 ) ;
return 0 ;
V_14:
F_10 () ;
return V_12 ;
}
static int T_2 F_11 ( struct V_10 * V_3 )
{
F_10 () ;
return 0 ;
}
static int T_1 F_12 ( void )
{
return F_13 ( & V_25 ) ;
}
static void T_2 F_14 ( void )
{
F_15 ( & V_25 ) ;
}
