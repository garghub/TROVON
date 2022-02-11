static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
V_5 = F_2 ( V_4 ,
V_4 -> V_6 ,
F_3 ( ( void * ) ( ( unsigned long ) V_7 ) ) >> V_8 ,
V_4 -> V_9 - V_4 -> V_6 ,
V_10 ) ;
if ( V_5 != 0 )
return - V_11 ;
return 0 ;
}
static int T_1
F_4 ( void )
{
int V_5 ;
V_5 = F_5 ( & V_12 ) ;
if ( V_5 ) {
F_6 ( V_13 L_1 ,
V_14 ) ;
return V_5 ;
}
F_6 ( V_15 L_2 V_16 L_3 ) ;
return 0 ;
}
static void T_2
F_7 ( void )
{
F_8 ( & V_12 ) ;
}
