int F_1 ( struct V_1 * V_1 )
{
T_1 V_2 ;
T_1 V_3 ;
if ( ! V_1 || ! V_1 -> V_4 || ! F_2 () )
return - V_5 ;
V_3 = V_1 -> V_6 & V_7 ?
V_8 :
V_9 ;
V_2 = F_3 ( V_1 -> V_4 ) ;
V_2 &= V_3 ;
V_2 >>= F_4 ( V_3 ) ;
return V_2 ;
}
void F_5 ( struct V_1 * V_1 )
{
T_1 V_2 ;
T_1 V_3 ;
if ( ! V_1 || ! V_1 -> V_4 || ! F_2 () )
return;
V_3 = V_1 -> V_6 & V_7 ?
V_8 :
V_9 ;
V_2 = F_3 ( V_1 -> V_4 ) ;
V_2 &= ~ V_3 ;
F_6 ( V_2 , V_1 -> V_4 ) ;
}
void F_7 ( struct V_1 * V_1 )
{
T_1 V_2 ;
T_1 V_3 ;
if ( ! V_1 || ! V_1 -> V_4 || ! F_2 () )
return;
V_3 = V_1 -> V_6 & V_7 ?
V_8 :
V_9 ;
V_2 = F_3 ( V_1 -> V_4 ) ;
V_2 |= V_3 ;
F_6 ( V_2 , V_1 -> V_4 ) ;
}
