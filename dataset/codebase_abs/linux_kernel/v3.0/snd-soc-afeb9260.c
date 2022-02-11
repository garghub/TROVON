static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
int V_11 ;
V_11 = F_2 ( V_9 ,
V_12 |
V_13 |
V_14 ) ;
if ( V_11 < 0 ) {
F_3 ( V_15 L_1 ) ;
return V_11 ;
}
V_11 = F_2 ( V_10 ,
V_12 |
V_13 |
V_14 ) ;
if ( V_11 < 0 ) {
F_3 ( V_15 L_2 ) ;
return V_11 ;
}
V_11 =
F_4 ( V_9 , 0 , V_16 , V_17 ) ;
if ( V_11 < 0 ) {
F_3 ( V_15 L_3 ) ;
return V_11 ;
}
return V_11 ;
}
static int F_5 ( struct V_5 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_19 ;
struct V_20 * V_21 = & V_19 -> V_21 ;
F_6 ( V_21 , V_22 ,
F_7 ( V_22 ) ) ;
F_8 ( V_21 , V_23 , F_7 ( V_23 ) ) ;
F_9 ( V_21 , L_4 ) ;
F_9 ( V_21 , L_5 ) ;
F_9 ( V_21 , L_6 ) ;
F_10 ( V_21 ) ;
return 0 ;
}
static int T_1 F_11 ( void )
{
int V_11 ;
struct V_24 * V_25 ;
if ( ! ( F_12 () ) )
return - V_26 ;
V_27 = F_13 ( L_7 , - 1 ) ;
if ( ! V_27 ) {
F_3 ( V_15 L_8 ) ;
return - V_28 ;
}
F_14 ( V_27 , & V_29 ) ;
V_11 = F_15 ( V_27 ) ;
if ( V_11 )
goto V_30;
V_25 = & V_27 -> V_25 ;
return 0 ;
V_30:
F_16 ( V_27 ) ;
return V_11 ;
}
static void T_2 F_17 ( void )
{
F_18 ( V_27 ) ;
}
