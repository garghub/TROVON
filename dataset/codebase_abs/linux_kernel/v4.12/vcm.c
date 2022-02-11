int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
V_4 = F_2 () ;
if ( NULL == V_4 )
return - V_5 ;
return V_4 -> V_6 ( V_2 , 1 ) ;
}
int F_3 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
V_4 = F_2 () ;
if ( NULL == V_4 )
return - V_5 ;
return V_4 -> V_6 ( V_2 , 0 ) ;
}
