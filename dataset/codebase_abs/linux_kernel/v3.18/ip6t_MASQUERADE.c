static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
return F_2 ( V_2 , V_4 -> V_5 , V_4 -> V_6 ) ;
}
static int F_3 ( const struct V_7 * V_4 )
{
const struct V_8 * V_9 = V_4 -> V_5 ;
if ( V_9 -> V_10 & V_11 )
return - V_12 ;
return 0 ;
}
static int T_1 F_4 ( void )
{
int V_13 ;
V_13 = F_5 ( & V_14 ) ;
if ( V_13 == 0 )
F_6 () ;
return V_13 ;
}
static void T_2 F_7 ( void )
{
F_8 () ;
F_9 ( & V_14 ) ;
}
