int T_1 F_1 ( void )
{
struct V_1 * V_1 = NULL ;
int V_2 ;
V_2 = F_2 ( V_3 , L_1 ) ;
if ( V_2 )
return V_2 ;
F_3 ( V_3 , 1 ) ;
V_1 = F_4 ( NULL , L_2 ) ;
if ( F_5 ( V_1 ) )
goto V_4;
F_6 ( V_1 ) ;
V_2 = F_7 ( true , true ) ;
if ( V_2 )
goto V_5;
return 0 ;
V_5:
F_8 ( V_1 ) ;
F_9 ( V_1 ) ;
V_4:
F_10 ( V_3 ) ;
return V_2 ;
}
static int T_1 F_11 ( void )
{
if ( ! F_12 () )
return 0 ;
return F_1 () ;
}
