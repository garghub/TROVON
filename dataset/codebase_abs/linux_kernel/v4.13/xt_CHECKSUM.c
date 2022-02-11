static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
if ( V_2 -> V_5 == V_6 )
F_2 ( V_2 ) ;
return V_7 ;
}
static int F_3 ( const struct V_8 * V_4 )
{
const struct V_9 * V_10 = V_4 -> V_11 ;
if ( V_10 -> V_12 & ~ V_13 ) {
F_4 ( L_1 , V_10 -> V_12 ) ;
return - V_14 ;
}
if ( ! V_10 -> V_12 ) {
F_4 ( L_2 ) ;
return - V_14 ;
}
return 0 ;
}
static int T_1 F_5 ( void )
{
return F_6 ( & V_15 ) ;
}
static void T_2 F_7 ( void )
{
F_8 ( & V_15 ) ;
}
