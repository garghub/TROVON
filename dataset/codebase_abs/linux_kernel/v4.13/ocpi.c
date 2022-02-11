int F_1 ( void )
{
unsigned int V_1 ;
if ( ! F_2 () )
return - V_2 ;
V_1 = F_3 ( V_3 ) ;
V_1 &= ~ 0xff ;
F_4 ( V_1 , V_3 ) ;
V_1 = F_3 ( V_4 ) ;
V_1 &= ~ 0xff ;
F_4 ( V_1 , V_4 ) ;
return 0 ;
}
static int T_1 F_5 ( void )
{
if ( ! F_2 () )
return - V_2 ;
V_5 = F_6 ( NULL , L_1 ) ;
if ( F_7 ( V_5 ) )
return F_8 ( V_5 ) ;
F_9 ( V_5 ) ;
F_1 () ;
F_10 ( L_2 ) ;
return 0 ;
}
static void T_2 F_11 ( void )
{
if ( ! F_2 () )
return;
F_12 ( V_5 ) ;
F_13 ( V_5 ) ;
}
