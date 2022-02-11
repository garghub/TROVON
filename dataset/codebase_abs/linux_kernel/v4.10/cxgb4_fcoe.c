bool F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) F_2 ( V_4 ) ;
T_1 V_7 = V_6 -> V_8 ;
T_1 V_9 = 0 ;
if ( ( V_7 != V_10 ) && ( V_7 != V_11 ) ) {
F_3 ( V_2 -> V_12 , L_1 , V_7 ) ;
return false ;
}
F_4 ( V_4 , V_4 -> V_13 - 4 , & V_9 , 1 ) ;
if ( ( V_9 != V_14 ) && ( V_9 != V_15 ) ) {
F_3 ( V_2 -> V_12 , L_2 , V_9 ) ;
return false ;
}
return true ;
}
int F_5 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_6 ( V_17 ) ;
struct V_1 * V_2 = V_19 -> V_1 ;
struct V_20 * V_21 = & V_19 -> V_21 ;
if ( F_7 ( V_2 -> V_22 . V_23 ) )
return - V_24 ;
if ( ! ( V_2 -> V_25 & V_26 ) )
return - V_24 ;
F_8 ( V_2 -> V_12 , L_3 ) ;
V_17 -> V_27 |= V_28 ;
V_17 -> V_29 |= V_28 ;
V_17 -> V_27 |= V_30 ;
V_17 -> V_29 |= V_30 ;
F_9 ( V_17 ) ;
V_21 -> V_25 |= V_31 ;
return 0 ;
}
int F_10 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_6 ( V_17 ) ;
struct V_1 * V_2 = V_19 -> V_1 ;
struct V_20 * V_21 = & V_19 -> V_21 ;
if ( ! ( V_21 -> V_25 & V_31 ) )
return - V_24 ;
F_8 ( V_2 -> V_12 , L_4 ) ;
V_21 -> V_25 &= ~ V_31 ;
V_17 -> V_27 &= ~ V_28 ;
V_17 -> V_29 &= ~ V_28 ;
V_17 -> V_27 &= ~ V_30 ;
V_17 -> V_29 &= ~ V_30 ;
F_9 ( V_17 ) ;
return 0 ;
}
