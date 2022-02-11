static void T_1 F_1 ( void )
{
F_2 () ;
F_3 ( V_1 ) ;
F_4 () ;
F_5 ( & V_2 ) ;
F_6 ( & V_3 , V_4 ) ;
F_7 () ;
F_8 ( V_5 ,
V_6 ) ;
F_9 ( & V_7 ) ;
}
static int T_1
F_10 ( struct V_8 * V_9 , T_2 V_10 , T_2 V_11 )
{
int V_12 ;
V_12 = F_11 ( V_9 , V_10 , V_11 ) ;
if ( V_12 != - 1 )
return V_12 ;
return F_12 ( 1 ) ;
}
static int T_1 F_13 ( void )
{
if ( F_14 () ) {
F_15 () ;
F_16 ( & V_13 ) ;
}
return 0 ;
}
