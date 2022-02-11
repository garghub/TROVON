static int F_1 ( const struct V_1 * V_2 )
{
V_3 = V_2 -> V_4 ;
return 1 ;
}
static void F_2 ( struct V_5 * V_6 )
{
V_3 = & V_7 ;
F_3 ( V_8 ) ;
V_6 -> V_3 = V_3 ;
V_6 -> V_9 = V_10 ;
if ( V_11 != - 1 )
V_3 -> V_11 = V_11 ;
else
V_11 = V_3 -> V_11 ;
}
static int T_1 F_4 ( void )
{
return F_5 ( & V_12 ) ;
}
static void T_2 F_6 ( void )
{
F_7 ( & V_12 ) ;
}
