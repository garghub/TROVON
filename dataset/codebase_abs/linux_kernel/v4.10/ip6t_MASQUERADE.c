static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
return F_2 ( V_2 , V_4 -> V_5 , F_3 ( V_4 ) ) ;
}
static int F_4 ( const struct V_6 * V_4 )
{
const struct V_7 * V_8 = V_4 -> V_5 ;
if ( V_8 -> V_9 & V_10 )
return - V_11 ;
return 0 ;
}
static int T_1 F_5 ( void )
{
int V_12 ;
V_12 = F_6 ( & V_13 ) ;
if ( V_12 == 0 )
F_7 () ;
return V_12 ;
}
static void T_2 F_8 ( void )
{
F_9 () ;
F_10 ( & V_13 ) ;
}
