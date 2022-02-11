static void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
}
static int T_1 F_4 ( void )
{
const char * V_2 , * V_3 ;
if ( ! F_5 () )
return 0 ;
V_2 = F_6 ( V_4 ) ;
if ( ! V_2 || strcmp ( V_2 , L_1 ) )
return 0 ;
V_3 = F_6 ( V_5 ) ;
if ( ! V_3 || strcmp ( V_3 , L_2 ) )
return 0 ;
F_7 ( V_6 L_3 ,
V_7 , V_2 , V_3 ) ;
F_1 () ;
return 0 ;
}
