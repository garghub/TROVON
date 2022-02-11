int T_1 F_1 ( const struct V_1 * V_2 )
{
if ( V_3 )
return - V_4 ;
if ( ! V_2 )
return - V_5 ;
V_3 = F_2 ( V_2 , sizeof( * V_2 ) , V_6 ) ;
if ( ! V_3 )
return - V_7 ;
return 0 ;
}
struct V_1 * F_3 ( void )
{
if ( ! V_3 )
return F_4 ( - V_8 ) ;
return V_3 ;
}
