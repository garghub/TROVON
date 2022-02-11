static bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
void T_1 * V_5 = V_4 -> V_6 + V_7 ;
T_2 V_8 = F_2 ( V_5 ) ;
if ( V_8 & V_9 ) {
F_3 ( V_8 & ~ V_9 , V_5 ) ;
return true ;
}
return false ;
}
static void F_4 ( struct V_1 * V_2 , bool V_10 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
void T_1 * V_5 = V_4 -> V_6 + V_11 ;
T_2 V_8 = F_2 ( V_5 ) ;
if ( V_10 )
V_8 |= V_9 ;
else
V_8 &= ~ V_9 ;
F_3 ( V_8 , V_5 ) ;
}
static int F_5 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = & V_13 -> V_15 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_16 * V_17 ;
V_2 = F_6 ( V_15 , sizeof( * V_2 ) , V_18 ) ;
if ( ! V_2 )
return - V_19 ;
V_4 = F_6 ( V_15 , sizeof( * V_4 ) , V_18 ) ;
if ( ! V_4 )
return - V_19 ;
V_17 = F_7 ( V_13 , V_20 , L_1 ) ;
V_4 -> V_6 = F_8 ( V_15 , V_17 ) ;
if ( F_9 ( V_4 -> V_6 ) )
return F_10 ( V_4 -> V_6 ) ;
V_2 -> V_13 = V_13 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_21 = F_1 ;
V_2 -> V_22 = F_4 ;
return F_11 ( V_13 , V_2 ) ;
}
