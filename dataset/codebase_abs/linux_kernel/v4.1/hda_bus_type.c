static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
if ( V_6 -> type != V_8 -> type )
return 0 ;
if ( V_8 -> V_9 )
return V_8 -> V_9 ( V_6 , V_8 ) ;
return 1 ;
}
static int T_1 F_4 ( void )
{
return F_5 ( & V_10 ) ;
}
static void T_2 F_6 ( void )
{
F_7 ( & V_10 ) ;
}
