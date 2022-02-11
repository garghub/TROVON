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
static void F_7 ( struct V_4 * V_5 )
{
F_5 ( V_5 , F_3 ( V_5 ) | V_12 ) ;
F_8 ( 10 , 50 ) ;
}
static int F_9 ( struct V_2 * V_3 , struct V_4 * V_5 ,
int V_13 , int V_14 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_2 V_15 ;
unsigned long V_16 , V_17 ;
unsigned long long V_18 , V_19 = V_20 ;
T_1 V_21 ;
F_10 ( V_19 , V_14 ) ;
V_17 = F_11 ( V_6 -> V_22 -> V_23 ) ;
V_18 = V_19 * V_17 ;
V_16 = V_6 -> V_22 -> V_24 ;
if ( ! V_16 )
return - V_25 ;
F_10 ( V_18 , V_16 ) ;
V_18 += V_26 ;
if ( V_13 <= 0 )
V_13 = 1 ;
V_15 = 255 - ( 255 * V_13 / V_14 ) ;
F_12 ( V_3 -> V_27 ) ;
V_21 = F_3 ( V_5 ) ;
V_21 &= ~ V_28 ;
V_21 &= ~ ( ( V_17 - 1 ) << V_29 ) ;
V_18 &= ( V_17 - 1 ) ;
V_21 |= ( T_1 ) V_18 << V_29 ;
V_21 |= V_15 ;
F_5 ( V_5 , V_21 ) ;
if ( F_13 ( V_5 ) )
F_7 ( V_5 ) ;
F_14 ( V_3 -> V_27 ) ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
F_12 ( V_3 -> V_27 ) ;
F_7 ( V_5 ) ;
F_5 ( V_5 , F_3 ( V_5 ) | V_30 ) ;
return 0 ;
}
static void F_16 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
F_5 ( V_5 , F_3 ( V_5 ) & ~ V_30 ) ;
F_14 ( V_3 -> V_27 ) ;
}
struct V_1 * F_17 ( struct V_31 * V_27 , struct V_32 * V_33 ,
const struct V_34 * V_22 )
{
struct V_1 * V_6 ;
int V_35 ;
V_6 = F_18 ( V_27 , sizeof( * V_6 ) , V_36 ) ;
if ( ! V_6 )
return F_19 ( - V_37 ) ;
V_6 -> V_7 = F_20 ( V_27 , V_33 ) ;
if ( F_21 ( V_6 -> V_7 ) )
return F_22 ( V_6 -> V_7 ) ;
V_6 -> V_22 = V_22 ;
V_6 -> V_3 . V_27 = V_27 ;
V_6 -> V_3 . V_38 = & V_39 ;
V_6 -> V_3 . V_40 = - 1 ;
V_6 -> V_3 . V_41 = V_22 -> V_41 ;
V_35 = F_23 ( & V_6 -> V_3 ) ;
if ( V_35 ) {
F_24 ( V_27 , L_1 , V_35 ) ;
return F_19 ( V_35 ) ;
}
return V_6 ;
}
int F_25 ( struct V_1 * V_6 )
{
return F_26 ( & V_6 -> V_3 ) ;
}
