static unsigned long F_1 ( void )
{
return F_2 () ;
}
static unsigned long long T_1 F_3 ( void )
{
return F_2 () * V_1 ;
}
static void T_2 F_4 ( void )
{
V_2 . V_3 = F_1 ;
V_2 . V_4 = F_5 () ;
F_6 ( & V_2 ) ;
}
int T_2 F_7 ( void )
{
T_3 V_5 = F_5 () ;
if ( V_5 == 0 )
return - V_6 ;
F_4 () ;
V_1 = V_7 / V_5 ;
V_8 = F_3 ;
F_8 ( L_1 ,
V_5 / 1000 , V_1 ) ;
return 0 ;
}
