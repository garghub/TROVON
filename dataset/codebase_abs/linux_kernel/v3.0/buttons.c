static T_1 int F_1 ( void )
{
struct V_1 * V_2 ;
int error ;
V_2 = F_2 ( L_1 , - 1 ) ;
if ( ! V_2 )
return - V_3 ;
error = F_3 ( V_2 , & V_4 , 1 ) ;
if ( error )
goto V_5;
error = F_4 ( V_2 ) ;
if ( error )
goto V_5;
return 0 ;
V_5:
F_5 ( V_2 ) ;
return error ;
}
