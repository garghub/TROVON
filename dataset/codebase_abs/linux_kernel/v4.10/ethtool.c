static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_7 = F_3 ( V_6 -> V_8 -> V_9 . V_7 ) ;
V_4 -> V_10 = V_11 | V_12 | V_13 | V_14 ;
if ( V_7 == V_15 )
return;
if ( V_7 & V_16 )
V_4 -> V_17 |= V_11 ;
if ( V_7 & V_18 )
V_4 -> V_17 |= V_12 ;
if ( V_7 & V_19 )
V_4 -> V_17 |= V_13 ;
if ( V_7 & V_20 )
V_4 -> V_17 |= V_14 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_7 = 0 ;
if ( V_4 -> V_17 & ~ ( V_11 | V_12 | V_13 | V_14 ) )
return - V_21 ;
if ( V_4 -> V_17 & V_11 )
V_7 |= V_16 ;
if ( V_4 -> V_17 & V_12 )
V_7 |= V_18 ;
if ( V_4 -> V_17 & V_13 )
V_7 |= V_19 ;
if ( V_4 -> V_17 & V_14 )
V_7 |= V_20 ;
if ( V_4 -> V_17 == 0 )
V_7 |= V_15 ;
V_6 -> V_8 -> V_9 . V_7 = F_5 ( V_7 ) ;
return 0 ;
}
