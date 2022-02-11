static int T_1 F_1 ( void )
{
int V_1 ;
V_1 = F_2 ( ( const char V_2 V_3 * ) L_1 , 0755 ) ;
if ( V_1 < 0 )
goto V_4;
V_1 = F_3 ( ( const char V_2 V_3 * ) L_2 ,
V_5 | V_6 | V_7 ,
F_4 ( F_5 ( 5 , 1 ) ) ) ;
if ( V_1 < 0 )
goto V_4;
V_1 = F_2 ( ( const char V_2 V_3 * ) L_3 , 0700 ) ;
if ( V_1 < 0 )
goto V_4;
return 0 ;
V_4:
F_6 ( V_8 L_4 ) ;
return V_1 ;
}
