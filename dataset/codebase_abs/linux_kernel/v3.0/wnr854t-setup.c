static void T_1 F_1 ( void )
{
F_2 () ;
F_3 ( V_1 ) ;
F_4 ( & V_2 ) ;
F_5 ( & V_3 , V_4 ) ;
F_6 () ;
F_7 ( V_5 ,
V_6 ) ;
F_8 ( & V_7 ) ;
}
static int T_1 F_9 ( struct V_8 * V_9 , T_2 V_10 , T_2 V_11 )
{
int V_12 ;
V_12 = F_10 ( V_9 , V_10 , V_11 ) ;
if ( V_12 != - 1 )
return V_12 ;
if ( V_10 == 7 )
return F_11 ( 4 ) ;
return - 1 ;
}
static int T_1 F_12 ( void )
{
if ( F_13 () )
F_14 ( & V_13 ) ;
return 0 ;
}
