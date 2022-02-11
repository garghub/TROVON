int F_1 ( struct V_1 * V_2 ,
T_1 (* F_2)( int V_3 , void * V_4 ) ,
T_1 (* F_3)( int V_3 , void * V_4 ) )
{
V_2 -> V_5 = F_4 ( F_2 ,
F_3 ,
V_6 ,
V_2 ,
L_1 ,
V_2 -> V_7 ,
V_2 -> V_8 ) ;
if ( V_2 -> V_5 == NULL )
return - V_9 ;
V_2 -> V_10 |= V_11 ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
V_2 -> V_10 &= ~ V_11 ;
F_6 ( V_2 -> V_5 ) ;
}
