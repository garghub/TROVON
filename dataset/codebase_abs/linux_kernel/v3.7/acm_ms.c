static int T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( F_2 ( V_2 -> V_4 -> V_5 ) ) {
V_2 -> V_6 = V_7 ;
V_2 -> V_8 |= V_9 ;
}
V_3 = F_3 ( V_2 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 -> V_4 , V_2 , & V_10 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static int T_1 F_5 ( struct V_11 * V_4 )
{
struct V_12 * V_5 = V_4 -> V_5 ;
int V_3 ;
void * V_13 ;
V_3 = F_6 ( V_4 -> V_5 , 1 ) ;
if ( V_3 < 0 )
return V_3 ;
V_13 = F_7 ( & V_10 , V_4 , & V_14 ) ;
if ( F_8 ( V_13 ) ) {
V_3 = F_9 ( V_13 ) ;
goto V_15;
}
V_3 = F_10 ( V_4 , V_16 ) ;
if ( V_3 < 0 )
goto V_17;
V_18 . V_19 = V_16 [ V_20 ] . V_21 ;
V_18 . V_22 = V_16 [ V_23 ] . V_21 ;
V_3 = F_11 ( V_4 , & V_24 , F_1 ) ;
if ( V_3 < 0 )
goto V_17;
F_12 ( V_4 , & V_25 ) ;
F_13 ( & V_5 -> V_26 , L_1 V_27 L_2 ,
V_28 ) ;
F_14 ( & V_10 ) ;
return 0 ;
V_17:
F_14 ( & V_10 ) ;
V_15:
F_15 () ;
return V_3 ;
}
static int T_2 F_16 ( struct V_11 * V_4 )
{
F_15 () ;
return 0 ;
}
static int T_1 F_17 ( void )
{
return F_18 ( & V_29 ) ;
}
static void T_2 F_19 ( void )
{
F_20 ( & V_29 ) ;
}
