static unsigned long F_1 ( void )
{
return F_2 () ;
}
static void T_1 F_3 ( void )
{
V_1 . V_2 = F_1 ;
V_1 . V_3 = F_4 () ;
F_5 ( & V_1 ) ;
}
int T_1 F_6 ( void )
{
T_2 V_4 = F_4 () ;
if ( V_4 == 0 )
return - V_5 ;
F_3 () ;
return 0 ;
}
