static unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
const struct V_4 * V_5 ;
void T_1 * V_6 ;
V_5 = F_2 ( V_7 , F_3 ( V_7 ) , V_3 ) ;
if ( ! V_5 )
return V_8 ;
V_6 = V_2 -> V_9 -> V_10 + V_5 -> V_11 ;
if ( F_4 ( V_6 ) & F_5 ( V_5 -> V_12 ) )
return V_13 ;
else
return V_8 ;
}
static void F_6 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_14 )
{
const struct V_4 * V_5 ;
void T_1 * V_6 ;
T_2 V_15 ;
T_2 V_12 ;
V_5 = F_2 ( V_7 , F_3 ( V_7 ) , V_3 ) ;
if ( ! V_5 )
return;
V_6 = V_2 -> V_9 -> V_10 + V_5 -> V_11 ;
V_12 = F_5 ( V_5 -> V_12 ) ;
V_15 = F_4 ( V_6 ) & ~ V_12 ;
if ( V_14 == V_13 )
V_15 |= V_12 ;
F_7 ( V_15 , V_6 ) ;
}
