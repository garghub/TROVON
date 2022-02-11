static int T_1 F_1 ( void )
{
int V_1 ;
V_1 = F_2 () ;
if ( V_1 )
return V_1 ;
V_1 = F_3 ( V_2 ) ;
if ( V_1 )
goto V_3;
F_4 ( V_4 , 1 ) ;
F_5 () ;
return 0 ;
V_3:
F_6 () ;
return V_1 ;
}
static void T_2 F_7 ( void )
{
F_8 () ;
F_9 () ;
F_6 () ;
}
