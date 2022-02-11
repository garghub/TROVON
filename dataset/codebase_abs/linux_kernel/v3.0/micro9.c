static unsigned int T_1 F_1 ( void )
{
T_2 V_1 ;
V_1 = F_2 ( V_2 ) ;
if ( V_1 & V_3 )
return 4 ;
else
return 2 ;
}
static void T_1 F_3 ( void )
{
unsigned int V_4 ;
if ( F_4 () )
V_4 = 4 ;
else if ( F_5 () || F_6 () )
V_4 = F_1 () ;
else
V_4 = 0 ;
if ( V_4 )
F_7 ( V_4 , V_5 , V_6 ) ;
}
static void T_1 F_8 ( void )
{
F_9 () ;
F_10 ( & V_7 , 1 ) ;
F_3 () ;
}
