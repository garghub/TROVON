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
unsigned long F_8 ( struct V_1 * V_1 )
{
T_1 V_2 ;
unsigned long V_10 ;
struct V_11 * V_12 ;
if ( ! V_1 || ! V_1 -> V_11 )
return 0 ;
V_12 = V_1 -> V_11 ;
V_10 = F_9 ( V_1 ) ;
V_2 = F_3 ( V_12 -> V_13 ) ;
if ( V_2 & V_14 )
V_10 *= V_15 ;
return V_10 ;
}
long F_10 ( struct V_1 * V_1 , unsigned long V_16 )
{
T_1 V_2 ;
struct V_11 * V_12 ;
long V_17 ;
if ( ! V_1 || ! V_1 -> V_11 )
return - V_5 ;
V_12 = V_1 -> V_11 ;
V_2 = F_3 ( V_12 -> V_13 ) & V_14 ;
if ( V_2 )
V_16 = V_16 / V_15 ;
V_17 = F_11 ( V_1 , V_16 ) ;
if ( V_17 == ~ 0 )
return V_17 ;
if ( V_2 )
V_1 -> V_11 -> V_18 *= V_15 ;
return V_1 -> V_11 -> V_18 ;
}
