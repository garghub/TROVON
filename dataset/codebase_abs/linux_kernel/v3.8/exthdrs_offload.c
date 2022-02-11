int T_1 F_1 ( void )
{
int V_1 ;
V_1 = F_2 ( & V_2 , V_3 ) ;
if ( ! V_1 )
goto V_4;
V_1 = F_2 ( & V_5 , V_6 ) ;
if ( ! V_1 )
goto V_7;
V_4:
return V_1 ;
V_7:
F_3 ( & V_2 , V_3 ) ;
goto V_4;
}
