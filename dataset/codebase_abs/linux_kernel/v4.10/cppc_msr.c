bool F_1 ( void )
{
return true ;
}
int F_2 ( int V_1 , struct V_2 * V_3 , T_1 * V_4 )
{
int V_5 ;
V_5 = F_3 ( V_1 , V_3 -> V_6 , V_4 ) ;
if ( ! V_5 ) {
T_1 V_7 = F_4 ( V_3 -> V_8 + V_3 -> V_9 - 1 ,
V_3 -> V_8 ) ;
* V_4 &= V_7 ;
* V_4 >>= V_3 -> V_8 ;
}
return V_5 ;
}
int F_5 ( int V_1 , struct V_2 * V_3 , T_1 V_4 )
{
T_1 V_10 ;
int V_5 ;
V_5 = F_3 ( V_1 , V_3 -> V_6 , & V_10 ) ;
if ( ! V_5 ) {
T_1 V_7 = F_4 ( V_3 -> V_8 + V_3 -> V_9 - 1 ,
V_3 -> V_8 ) ;
V_4 <<= V_3 -> V_8 ;
V_4 &= V_7 ;
V_10 &= ~ V_7 ;
V_10 |= V_4 ;
V_5 = F_6 ( V_1 , V_3 -> V_6 , V_10 ) ;
}
return V_5 ;
}
