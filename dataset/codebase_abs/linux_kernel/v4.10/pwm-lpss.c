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
unsigned long long V_15 ;
unsigned long V_16 = V_6 -> V_17 -> V_18 , V_19 ;
unsigned long long V_20 , V_21 = V_22 ;
T_1 V_23 ;
F_10 ( V_21 , V_14 ) ;
V_19 = F_11 ( V_6 -> V_17 -> V_24 ) ;
V_21 *= V_19 ;
V_20 = F_12 ( V_21 , V_16 ) ;
if ( V_13 <= 0 )
V_13 = 1 ;
V_15 = 255ULL * V_13 ;
F_10 ( V_15 , V_14 ) ;
V_15 = 255ULL - V_15 ;
F_13 ( V_3 -> V_25 ) ;
V_23 = F_3 ( V_5 ) ;
V_23 &= ~ V_26 ;
V_23 &= ~ ( ( V_19 - 1 ) << V_27 ) ;
V_20 &= ( V_19 - 1 ) ;
V_23 |= ( T_1 ) V_20 << V_27 ;
V_23 |= V_15 ;
F_5 ( V_5 , V_23 ) ;
if ( F_14 ( V_5 ) )
F_7 ( V_5 ) ;
F_15 ( V_3 -> V_25 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
F_13 ( V_3 -> V_25 ) ;
F_7 ( V_5 ) ;
F_5 ( V_5 , F_3 ( V_5 ) | V_28 ) ;
return 0 ;
}
static void F_17 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
F_5 ( V_5 , F_3 ( V_5 ) & ~ V_28 ) ;
F_15 ( V_3 -> V_25 ) ;
}
struct V_1 * F_18 ( struct V_29 * V_25 , struct V_30 * V_31 ,
const struct V_32 * V_17 )
{
struct V_1 * V_6 ;
unsigned long V_16 ;
int V_33 ;
V_6 = F_19 ( V_25 , sizeof( * V_6 ) , V_34 ) ;
if ( ! V_6 )
return F_20 ( - V_35 ) ;
V_6 -> V_7 = F_21 ( V_25 , V_31 ) ;
if ( F_22 ( V_6 -> V_7 ) )
return F_23 ( V_6 -> V_7 ) ;
V_6 -> V_17 = V_17 ;
V_16 = V_6 -> V_17 -> V_18 ;
if ( ! V_16 )
return F_20 ( - V_36 ) ;
V_6 -> V_3 . V_25 = V_25 ;
V_6 -> V_3 . V_37 = & V_38 ;
V_6 -> V_3 . V_39 = - 1 ;
V_6 -> V_3 . V_40 = V_17 -> V_40 ;
V_33 = F_24 ( & V_6 -> V_3 ) ;
if ( V_33 ) {
F_25 ( V_25 , L_1 , V_33 ) ;
return F_20 ( V_33 ) ;
}
return V_6 ;
}
int F_26 ( struct V_1 * V_6 )
{
return F_27 ( & V_6 -> V_3 ) ;
}
