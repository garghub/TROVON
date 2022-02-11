static bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
void T_1 * V_5 = V_4 -> V_6 + V_7 ;
T_2 V_8 = F_3 ( V_5 ) ;
if ( V_8 & ( V_9 << V_10 ) ) {
V_8 &= ~ V_11 ;
V_8 |= V_9 << V_10 ;
F_4 ( V_8 , V_5 ) ;
return true ;
}
return false ;
}
static void F_5 ( struct V_1 * V_2 , bool V_12 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
void T_1 * V_5 = V_4 -> V_6 + V_7 ;
T_2 V_8 = F_3 ( V_5 ) ;
V_8 &= ~ V_11 ;
if ( V_12 )
V_8 |= V_9 << V_13 ;
else
V_8 &= ~ ( V_9 << V_13 ) ;
F_4 ( V_8 , V_5 ) ;
}
static int F_6 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = & V_15 -> V_17 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_18 * V_19 ;
V_4 = F_7 ( V_17 , sizeof( * V_4 ) , V_20 ) ;
if ( ! V_4 )
return - V_21 ;
V_2 = & V_4 -> V_2 ;
V_19 = F_8 ( V_15 ,
V_22 , L_1 ) ;
V_4 -> V_6 = F_9 ( V_17 , V_19 ) ;
if ( F_10 ( V_4 -> V_6 ) )
return F_11 ( V_4 -> V_6 ) ;
V_2 -> V_23 = F_1 ;
V_2 -> V_24 = F_5 ;
F_4 ( 0 , V_4 -> V_6 + V_7 ) ;
F_4 ( V_11 ,
V_4 -> V_6 + V_7 ) ;
return F_12 ( V_15 , V_2 ) ;
}
