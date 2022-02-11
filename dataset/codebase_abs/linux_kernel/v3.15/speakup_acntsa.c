static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 ) ;
if ( V_3 == 0 ) {
F_3 ( V_2 , L_1 ) ;
F_4 ( 100 ) ;
}
V_2 -> V_4 = ! V_3 ;
return V_3 ;
}
static int T_1 F_5 ( void )
{
return F_6 ( & V_5 ) ;
}
static void T_2 F_7 ( void )
{
F_8 ( & V_5 ) ;
}
