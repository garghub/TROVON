static int T_1 F_1 ( void )
{
int V_1 ;
V_2 = F_2 ( L_1 , - 1 ) ;
if ( ! V_2 )
return - V_3 ;
V_1 = F_3 ( V_2 ) ;
if ( V_1 )
goto V_4;
V_5 = F_2 ( L_2 , - 1 ) ;
if ( ! V_5 ) {
V_1 = - V_3 ;
goto V_6;
}
F_4 ( V_5 , & V_7 ) ;
V_1 = F_3 ( V_5 ) ;
if ( V_1 )
goto V_8;
return 0 ;
V_8:
F_5 ( V_5 ) ;
V_6:
F_6 ( V_2 ) ;
V_4:
F_5 ( V_2 ) ;
return V_1 ;
}
static void T_2 F_7 ( void )
{
F_8 ( V_5 ) ;
F_8 ( V_2 ) ;
}
