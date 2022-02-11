static int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
const struct V_5 * V_6 ;
V_6 = F_2 ( V_7 , & V_2 -> V_8 ) ;
if ( ! V_6 || ! V_6 -> V_9 )
return - V_10 ;
V_4 = ( const struct V_3 * ) V_6 -> V_9 ;
return F_3 ( V_2 , V_4 ) ;
}
static int T_1 F_4 ( void )
{
return F_5 ( & V_11 ) ;
}
static void T_2 F_6 ( void )
{
F_7 ( & V_11 ) ;
}
