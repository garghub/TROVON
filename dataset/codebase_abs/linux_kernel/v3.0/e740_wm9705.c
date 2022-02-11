static void F_1 ( int V_1 )
{
F_2 ( V_2 , ! V_1 ) ;
F_2 ( V_3 , ( V_1 & V_4 ) ? 1 : 0 ) ;
F_2 ( V_5 , ( V_1 & V_6 ) ? 1 : 0 ) ;
}
static int F_3 ( struct V_7 * V_8 ,
struct V_9 * V_10 , int V_11 )
{
if ( V_11 & V_12 )
V_13 |= V_6 ;
else if ( V_11 & V_14 )
V_13 &= ~ V_6 ;
F_1 ( V_13 ) ;
return 0 ;
}
static int F_4 ( struct V_7 * V_8 ,
struct V_9 * V_10 , int V_11 )
{
if ( V_11 & V_12 )
V_13 |= V_4 ;
else if ( V_11 & V_14 )
V_13 &= ~ V_4 ;
F_1 ( V_13 ) ;
return 0 ;
}
static int F_5 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_18 ;
struct V_19 * V_20 = & V_18 -> V_20 ;
F_6 ( V_20 , L_1 ) ;
F_6 ( V_20 , L_2 ) ;
F_6 ( V_20 , L_3 ) ;
F_6 ( V_20 , L_4 ) ;
F_6 ( V_20 , L_5 ) ;
F_6 ( V_20 , L_6 ) ;
F_6 ( V_20 , L_7 ) ;
F_6 ( V_20 , L_8 ) ;
F_6 ( V_20 , L_9 ) ;
F_7 ( V_20 , V_21 ,
F_8 ( V_21 ) ) ;
F_9 ( V_20 , V_22 , F_8 ( V_22 ) ) ;
F_10 ( V_20 ) ;
return 0 ;
}
static int T_1 F_11 ( void )
{
int V_23 ;
if ( ! F_12 () )
return - V_24 ;
V_23 = F_13 ( V_5 , L_10 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_13 ( V_3 , L_11 ) ;
if ( V_23 )
goto V_25;
V_23 = F_13 ( V_2 , L_12 ) ;
if ( V_23 )
goto V_26;
V_23 = F_14 ( V_5 , 0 ) ;
if ( V_23 )
goto V_27;
V_23 = F_14 ( V_3 , 0 ) ;
if ( V_23 )
goto V_27;
V_23 = F_14 ( V_2 , 1 ) ;
if ( V_23 )
goto V_27;
V_28 = F_15 ( L_13 , - 1 ) ;
if ( ! V_28 ) {
V_23 = - V_29 ;
goto V_27;
}
F_16 ( V_28 , & V_30 ) ;
V_23 = F_17 ( V_28 ) ;
if ( ! V_23 )
return 0 ;
F_18 ( V_28 ) ;
V_27:
F_19 ( V_2 ) ;
V_26:
F_19 ( V_3 ) ;
V_25:
F_19 ( V_5 ) ;
return V_23 ;
}
static void T_2 F_20 ( void )
{
F_21 ( V_28 ) ;
F_19 ( V_2 ) ;
F_19 ( V_3 ) ;
F_19 ( V_5 ) ;
}
