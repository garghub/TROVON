static T_1 int F_1 ( void )
{
struct V_1 * V_2 ;
int V_3 ;
V_2 = F_2 ( L_1 , - 1 ) ;
if ( ! V_2 )
return - V_4 ;
V_3 = F_3 ( V_2 , & V_5 , 1 ) ;
if ( V_3 )
goto V_6;
V_3 = F_4 ( V_2 ) ;
if ( V_3 )
goto V_6;
return 0 ;
V_6:
F_5 ( V_2 ) ;
return V_3 ;
}
