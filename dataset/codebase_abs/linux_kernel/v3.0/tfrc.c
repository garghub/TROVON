int T_1 F_1 ( void )
{
int V_1 = F_2 () ;
if ( V_1 )
goto V_2;
V_1 = F_3 () ;
if ( V_1 )
goto V_3;
V_1 = F_4 () ;
if ( V_1 )
goto V_4;
return 0 ;
V_4:
F_5 () ;
V_3:
F_6 () ;
V_2:
return V_1 ;
}
void F_7 ( void )
{
F_8 () ;
F_5 () ;
F_6 () ;
}
