static struct V_1 *
F_1 ( struct V_2 * V_3 , int V_4 )
{
unsigned int V_5 = F_2 ( V_3 -> V_6 ) ;
if ( V_5 == V_7 )
return & V_8 ;
return NULL ;
}
static int T_1 F_3 ( void )
{
if ( F_4 () != V_9 )
return - V_10 ;
V_11 = F_1 ;
return 0 ;
}
