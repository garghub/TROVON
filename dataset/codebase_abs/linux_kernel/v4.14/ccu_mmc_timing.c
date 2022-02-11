int F_1 ( struct V_1 * V_1 , bool V_2 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
unsigned long V_7 ;
T_1 V_8 ;
if ( ! ( V_6 -> V_9 & V_10 ) )
return - V_11 ;
F_4 ( V_6 -> V_12 , V_7 ) ;
V_8 = F_5 ( V_6 -> V_13 + V_6 -> V_14 ) ;
if ( V_2 )
V_8 |= V_15 ;
else
V_8 &= ~ V_15 ;
F_6 ( V_8 , V_6 -> V_13 + V_6 -> V_14 ) ;
F_7 ( V_6 -> V_12 , V_7 ) ;
return 0 ;
}
int F_8 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
if ( ! ( V_6 -> V_9 & V_10 ) )
return - V_11 ;
return ! ! ( F_5 ( V_6 -> V_13 + V_6 -> V_14 ) & V_15 ) ;
}
