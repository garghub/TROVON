void T_1 F_1 ( void )
{
#ifndef F_2
V_1 = V_2 ;
F_3 ( L_1 ,
( int ) ( V_1 >> 20 ) ) ;
#endif
F_4 ( F_5 ( V_3 ) , V_4 ) ;
F_4 ( F_5 ( V_5 ) , V_4 ) ;
F_6 () ;
}
static int T_1 F_7 ( struct V_6 * V_7 , T_2 V_8 , T_2 V_9 )
{
if ( V_8 == 1 )
return F_5 ( V_3 ) ;
if ( V_8 == 2 )
return F_5 ( V_5 ) ;
return - 1 ;
}
int T_1 F_8 ( void )
{
if ( F_9 () )
F_10 ( & V_10 ) ;
return 0 ;
}
