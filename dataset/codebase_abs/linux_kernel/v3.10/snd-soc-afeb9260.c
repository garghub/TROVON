static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
int V_10 ;
V_10 =
F_2 ( V_9 , 0 , V_11 , V_12 ) ;
if ( V_10 < 0 ) {
F_3 ( V_13 L_1 ) ;
return V_10 ;
}
return V_10 ;
}
static int F_4 ( struct V_5 * V_6 )
{
struct V_14 * V_15 = V_6 -> V_15 ;
struct V_16 * V_17 = & V_15 -> V_17 ;
F_5 ( V_17 , L_2 ) ;
F_5 ( V_17 , L_3 ) ;
F_5 ( V_17 , L_4 ) ;
return 0 ;
}
static int T_1 F_6 ( void )
{
int V_10 ;
struct V_18 * V_19 ;
if ( ! ( F_7 () ) )
return - V_20 ;
V_21 = F_8 ( L_5 , - 1 ) ;
if ( ! V_21 ) {
F_3 ( V_13 L_6 ) ;
return - V_22 ;
}
F_9 ( V_21 , & V_23 ) ;
V_10 = F_10 ( V_21 ) ;
if ( V_10 )
goto V_24;
V_19 = & V_21 -> V_19 ;
return 0 ;
V_24:
F_11 ( V_21 ) ;
return V_10 ;
}
static void T_2 F_12 ( void )
{
F_13 ( V_21 ) ;
}
