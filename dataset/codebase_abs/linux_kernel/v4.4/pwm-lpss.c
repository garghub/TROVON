static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline T_1 F_3 ( const struct V_4 * V_5 )
{
struct V_1 * V_6 = F_1 ( V_5 -> V_3 ) ;
return F_4 ( V_6 -> V_7 + V_5 -> V_8 * V_9 + V_10 ) ;
}
static inline void F_5 ( const struct V_4 * V_5 , T_1 V_11 )
{
struct V_1 * V_6 = F_1 ( V_5 -> V_3 ) ;
F_6 ( V_11 , V_6 -> V_7 + V_5 -> V_8 * V_9 + V_10 ) ;
}
static int F_7 ( struct V_2 * V_3 , struct V_4 * V_5 ,
int V_12 , int V_13 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_2 V_14 ;
unsigned long V_15 ;
unsigned long long V_16 , V_17 = V_18 ;
T_1 V_19 ;
F_8 ( V_17 , V_13 ) ;
V_16 = V_17 * 65536 ;
V_15 = V_6 -> V_20 ;
if ( ! V_15 )
return - V_21 ;
F_8 ( V_16 , V_15 ) ;
V_16 += V_22 ;
if ( V_16 > V_23 )
return - V_21 ;
if ( V_12 <= 0 )
V_12 = 1 ;
V_14 = 255 - ( 255 * V_12 / V_13 ) ;
F_9 ( V_3 -> V_24 ) ;
V_19 = F_3 ( V_5 ) ;
V_19 &= ~ ( V_25 | V_26 ) ;
V_19 |= ( V_27 ) V_16 << V_28 ;
V_19 |= V_14 ;
V_19 |= V_29 ;
F_5 ( V_5 , V_19 ) ;
F_10 ( V_3 -> V_24 ) ;
return 0 ;
}
static int F_11 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
F_9 ( V_3 -> V_24 ) ;
F_5 ( V_5 , F_3 ( V_5 ) | V_30 ) ;
return 0 ;
}
static void F_12 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
F_5 ( V_5 , F_3 ( V_5 ) & ~ V_30 ) ;
F_10 ( V_3 -> V_24 ) ;
}
struct V_1 * F_13 ( struct V_31 * V_24 , struct V_32 * V_33 ,
const struct V_34 * V_35 )
{
struct V_1 * V_6 ;
int V_36 ;
V_6 = F_14 ( V_24 , sizeof( * V_6 ) , V_37 ) ;
if ( ! V_6 )
return F_15 ( - V_38 ) ;
V_6 -> V_7 = F_16 ( V_24 , V_33 ) ;
if ( F_17 ( V_6 -> V_7 ) )
return F_18 ( V_6 -> V_7 ) ;
V_6 -> V_20 = V_35 -> V_20 ;
V_6 -> V_3 . V_24 = V_24 ;
V_6 -> V_3 . V_39 = & V_40 ;
V_6 -> V_3 . V_41 = - 1 ;
V_6 -> V_3 . V_42 = V_35 -> V_42 ;
V_36 = F_19 ( & V_6 -> V_3 ) ;
if ( V_36 ) {
F_20 ( V_24 , L_1 , V_36 ) ;
return F_15 ( V_36 ) ;
}
return V_6 ;
}
int F_21 ( struct V_1 * V_6 )
{
return F_22 ( & V_6 -> V_3 ) ;
}
