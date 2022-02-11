static unsigned long F_1 ( void )
{
return F_2 () ;
}
static T_1 F_3 ( void )
{
return F_2 () ;
}
static void T_2 F_4 ( void )
{
V_1 . V_2 = F_1 ;
V_1 . V_3 = F_5 () ;
F_6 ( & V_1 ) ;
}
int T_2 F_7 ( void )
{
int V_4 ;
V_4 = F_8 () ;
if ( V_4 )
return V_4 ;
F_4 () ;
return 0 ;
}
int T_2 F_9 ( void )
{
if ( F_5 () == 0 )
return - V_5 ;
F_10 ( F_3 ,
32 , F_5 () ) ;
return 0 ;
}
