static int T_1 F_1 ( void )
{
int V_1 ;
V_1 = F_2 ( & V_2 ) ;
if ( V_1 )
goto V_3;
V_1 = F_3 ( & V_4 ) ;
if ( V_1 )
goto V_5;
F_4 (KERN_INFO DRIVER_DESC L_1 ) ;
F_4 (KERN_INFO DRIVER_VERSION L_2 DRIVER_AUTHOR L_1 ) ;
return V_1 ;
V_5:
F_5 ( & V_2 ) ;
V_3:
return V_1 ;
}
static void T_2 F_6 ( void )
{
F_7 ( & V_4 ) ;
F_5 ( & V_2 ) ;
}
