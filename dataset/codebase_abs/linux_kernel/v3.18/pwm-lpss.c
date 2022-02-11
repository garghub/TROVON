static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , struct V_4 * V_5 ,
int V_6 , int V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
T_1 V_9 ;
unsigned long V_10 ;
unsigned long long V_11 , V_12 = V_13 ;
T_2 V_14 ;
F_4 ( V_12 , V_7 ) ;
V_11 = V_12 * 65536 ;
V_10 = V_8 -> V_15 ;
if ( ! V_10 )
return - V_16 ;
F_4 ( V_11 , V_10 ) ;
V_11 += V_17 ;
if ( V_11 > V_18 )
return - V_16 ;
if ( V_6 <= 0 )
V_6 = 1 ;
V_9 = 255 - ( 255 * V_6 / V_7 ) ;
V_14 = F_5 ( V_8 -> V_19 + V_20 ) ;
V_14 &= ~ ( V_21 | V_22 ) ;
V_14 |= ( V_23 ) V_11 << V_24 ;
V_14 |= V_9 ;
V_14 |= V_25 ;
F_6 ( V_14 , V_8 -> V_19 + V_20 ) ;
return 0 ;
}
static int F_7 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
T_2 V_14 ;
V_14 = F_5 ( V_8 -> V_19 + V_20 ) ;
F_6 ( V_14 | V_26 , V_8 -> V_19 + V_20 ) ;
return 0 ;
}
static void F_8 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
T_2 V_14 ;
V_14 = F_5 ( V_8 -> V_19 + V_20 ) ;
F_6 ( V_14 & ~ V_26 , V_8 -> V_19 + V_20 ) ;
}
struct V_1 * F_9 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const struct V_31 * V_32 )
{
struct V_1 * V_8 ;
int V_33 ;
V_8 = F_10 ( V_28 , sizeof( * V_8 ) , V_34 ) ;
if ( ! V_8 )
return F_11 ( - V_35 ) ;
V_8 -> V_19 = F_12 ( V_28 , V_30 ) ;
if ( F_13 ( V_8 -> V_19 ) )
return F_14 ( V_8 -> V_19 ) ;
V_8 -> V_15 = V_32 -> V_15 ;
V_8 -> V_3 . V_28 = V_28 ;
V_8 -> V_3 . V_36 = & V_37 ;
V_8 -> V_3 . V_38 = - 1 ;
V_8 -> V_3 . V_39 = 1 ;
V_33 = F_15 ( & V_8 -> V_3 ) ;
if ( V_33 ) {
F_16 ( V_28 , L_1 , V_33 ) ;
return F_11 ( V_33 ) ;
}
return V_8 ;
}
int F_17 ( struct V_1 * V_8 )
{
T_2 V_14 ;
V_14 = F_5 ( V_8 -> V_19 + V_20 ) ;
F_6 ( V_14 & ~ V_26 , V_8 -> V_19 + V_20 ) ;
return F_18 ( & V_8 -> V_3 ) ;
}
