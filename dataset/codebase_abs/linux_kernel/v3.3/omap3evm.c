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
static int T_1 F_4 ( void )
{
int V_10 ;
if ( ! F_5 () )
return - V_13 ;
F_6 ( L_2 ) ;
V_14 = F_7 ( L_3 , - 1 ) ;
if ( ! V_14 ) {
F_3 ( V_12 L_4 ) ;
return - V_15 ;
}
F_8 ( V_14 , & V_16 ) ;
V_10 = F_9 ( V_14 ) ;
if ( V_10 )
goto V_17;
return 0 ;
V_17:
F_3 ( V_12 L_5 ) ;
F_10 ( V_14 ) ;
return V_10 ;
}
static void T_2 F_11 ( void )
{
F_12 ( V_14 ) ;
}
