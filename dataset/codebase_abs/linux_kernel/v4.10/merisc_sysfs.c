static T_1 F_1 ( struct V_1 * V_1 , char * V_2 )
{
T_1 V_3 = 0 ;
sprintf ( V_2 , L_1 , F_2 () ) ;
V_3 = strlen ( V_2 ) + 1 ;
return V_3 ;
}
static T_1 F_3 ( struct V_1 * V_1 , char * V_2 )
{
T_1 V_3 = 0 ;
sprintf ( V_2 , L_1 , F_4 () ) ;
V_3 = strlen ( V_2 ) + 1 ;
return V_3 ;
}
static int T_2 F_5 ( void )
{
int V_4 ;
V_4 = F_6 ( & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
return 0 ;
}
