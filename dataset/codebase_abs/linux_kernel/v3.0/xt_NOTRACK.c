static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
if ( V_2 -> V_5 != NULL )
return V_6 ;
V_2 -> V_5 = & F_2 () -> V_7 ;
V_2 -> V_8 = V_9 ;
F_3 ( V_2 -> V_5 ) ;
return V_6 ;
}
static int T_1 F_4 ( void )
{
return F_5 ( & V_10 ) ;
}
static void T_2 F_6 ( void )
{
F_7 ( & V_10 ) ;
}
