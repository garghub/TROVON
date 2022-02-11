static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
int V_10 ;
V_10 = F_2 ( V_9 , 0 , 26000000 ,
V_11 ) ;
if ( V_10 < 0 ) {
F_3 ( V_12 L_1 ) ;
return V_10 ;
}
return 0 ;
}
static int F_4 ( struct V_5 * V_6 )
{
struct V_13 * V_14 = V_6 -> V_14 ;
struct V_15 * V_16 = & V_14 -> V_16 ;
F_5 ( V_16 , L_2 ) ;
F_5 ( V_16 , L_3 ) ;
F_5 ( V_16 , L_4 ) ;
F_5 ( V_16 , L_5 ) ;
F_5 ( V_16 , L_6 ) ;
F_5 ( V_16 , L_7 ) ;
F_5 ( V_16 , L_8 ) ;
F_5 ( V_16 , L_9 ) ;
return 0 ;
}
static int F_6 ( struct V_5 * V_6 )
{
struct V_13 * V_14 = V_6 -> V_14 ;
unsigned short V_17 ;
V_17 = V_14 -> V_18 -> V_19 ( V_14 , V_20 ) ;
V_17 |= V_21 | V_22 | V_23 ;
V_14 -> V_18 -> V_24 ( V_14 , V_20 , V_17 ) ;
return 0 ;
}
static int T_1 F_7 ( void )
{
int V_10 ;
if ( ! F_8 () )
return - V_25 ;
F_3 ( V_26 L_10 ) ;
V_27 = F_9 ( L_11 , - 1 ) ;
if ( ! V_27 ) {
F_3 ( V_12 L_12 ) ;
return - V_28 ;
}
F_10 ( V_27 , & V_29 ) ;
V_10 = F_11 ( V_27 ) ;
if ( V_10 )
goto V_30;
F_12 ( F_13 ( V_31 , L_13 ) < 0 ) ;
F_14 ( V_31 , 0 ) ;
return 0 ;
V_30:
F_3 ( V_12 L_14 ) ;
F_15 ( V_27 ) ;
return V_10 ;
}
static void T_2 F_16 ( void )
{
F_17 ( V_31 ) ;
F_18 ( V_27 ) ;
}
