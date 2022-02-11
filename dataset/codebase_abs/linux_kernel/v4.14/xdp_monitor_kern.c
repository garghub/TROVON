static T_1
int F_1 ( struct V_1 * V_2 )
{
T_2 V_3 = V_4 ;
int V_5 = V_2 -> V_5 ;
T_3 * V_6 ;
if ( ! V_5 )
V_3 = V_7 ;
V_6 = F_2 ( & V_8 , & V_3 ) ;
if ( ! V_6 )
return 0 ;
* V_6 += 1 ;
return 0 ;
}
int F_3 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) ;
}
int F_4 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) ;
}
int F_5 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) ;
}
int F_6 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) ;
}
