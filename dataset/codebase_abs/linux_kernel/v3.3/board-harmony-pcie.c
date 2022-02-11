static int T_1 F_1 ( void )
{
struct V_1 * V_1 = NULL ;
int V_2 ;
if ( ! F_2 () )
return 0 ;
V_2 = F_3 ( V_3 , L_1 ) ;
if ( V_2 )
return V_2 ;
F_4 ( V_3 , 1 ) ;
V_1 = F_5 ( NULL , L_2 ) ;
if ( F_6 ( V_1 ) )
goto V_4;
F_7 ( V_1 ) ;
V_2 = F_8 ( true , true ) ;
if ( V_2 )
goto V_5;
return 0 ;
V_5:
F_9 ( V_1 ) ;
F_10 ( V_1 ) ;
V_4:
F_11 ( V_3 ) ;
return V_2 ;
}
