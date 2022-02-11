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
static int T_1 F_4 ( void )
{
int V_10 ;
struct V_14 * V_15 ;
if ( ! ( F_5 () ) )
return - V_16 ;
V_17 = F_6 ( L_2 , - 1 ) ;
if ( ! V_17 ) {
F_3 ( V_13 L_3 ) ;
return - V_18 ;
}
F_7 ( V_17 , & V_19 ) ;
V_10 = F_8 ( V_17 ) ;
if ( V_10 )
goto V_20;
V_15 = & V_17 -> V_15 ;
return 0 ;
V_20:
F_9 ( V_17 ) ;
return V_10 ;
}
static void T_2 F_10 ( void )
{
F_11 ( V_17 ) ;
}
