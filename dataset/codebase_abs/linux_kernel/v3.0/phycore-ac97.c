static int T_1 F_1 ( void )
{
int V_1 ;
if ( ! F_2 () && ! F_3 () )
return 0 ;
V_2 = F_4 ( L_1 , - 1 ) ;
if ( ! V_2 )
return - V_3 ;
F_5 ( V_2 , & V_4 ) ;
V_1 = F_6 ( V_2 ) ;
if ( V_1 )
goto V_5;
V_6 = F_4 ( L_2 , - 1 ) ;
if ( ! V_6 ) {
V_1 = - V_3 ;
goto V_7;
}
V_1 = F_6 ( V_6 ) ;
if ( V_1 ) {
F_7 ( V_8 L_3 ) ;
goto V_9;
}
return 0 ;
V_9:
F_8 ( V_6 ) ;
V_7:
F_9 ( V_2 ) ;
V_5:
F_8 ( V_2 ) ;
return V_1 ;
}
static void T_2 F_10 ( void )
{
F_11 ( V_6 ) ;
F_11 ( V_2 ) ;
}
