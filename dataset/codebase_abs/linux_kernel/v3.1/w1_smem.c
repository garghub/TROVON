static int T_1 F_1 ( void )
{
int V_1 ;
V_1 = F_2 ( & V_2 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_2 ( & V_3 ) ;
if ( V_1 ) {
F_3 ( & V_2 ) ;
return V_1 ;
}
return 0 ;
}
static void T_2 F_4 ( void )
{
F_3 ( & V_2 ) ;
F_3 ( & V_3 ) ;
}
