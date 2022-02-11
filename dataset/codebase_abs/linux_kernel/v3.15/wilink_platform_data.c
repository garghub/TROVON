int T_1 F_1 ( const struct V_1 * V_2 )
{
if ( V_1 )
return - V_3 ;
if ( ! V_2 )
return - V_4 ;
V_1 = F_2 ( V_2 , sizeof( * V_2 ) , V_5 ) ;
if ( ! V_1 )
return - V_6 ;
return 0 ;
}
struct V_1 * F_3 ( void )
{
if ( ! V_1 )
return F_4 ( - V_7 ) ;
return V_1 ;
}
int T_1 F_5 ( const struct V_8 * V_2 )
{
if ( V_8 )
return - V_3 ;
if ( ! V_2 )
return - V_4 ;
V_8 = F_2 ( V_2 , sizeof( * V_2 ) , V_5 ) ;
if ( ! V_8 )
return - V_6 ;
return 0 ;
}
struct V_8 * F_6 ( void )
{
if ( ! V_8 )
return F_4 ( - V_7 ) ;
return V_8 ;
}
