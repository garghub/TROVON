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
V_10 = F_5 ( V_8 -> V_15 ) ;
if ( ! V_10 )
return - V_16 ;
F_4 ( V_11 , V_10 ) ;
V_11 += V_17 ;
if ( V_11 > V_18 )
return - V_16 ;
if ( V_6 <= 0 )
V_6 = 1 ;
V_9 = 255 - ( 255 * V_6 / V_7 ) ;
V_14 = F_6 ( V_8 -> V_19 + V_20 ) ;
V_14 &= ~ ( V_21 | V_22 ) ;
V_14 |= ( V_23 ) V_11 << V_24 ;
V_14 |= V_9 ;
V_14 |= V_25 ;
F_7 ( V_14 , V_8 -> V_19 + V_20 ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
T_2 V_14 ;
int V_26 ;
V_26 = F_9 ( V_8 -> V_15 ) ;
if ( V_26 )
return V_26 ;
V_14 = F_6 ( V_8 -> V_19 + V_20 ) ;
F_7 ( V_14 | V_27 , V_8 -> V_19 + V_20 ) ;
return 0 ;
}
static void F_10 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
T_2 V_14 ;
V_14 = F_6 ( V_8 -> V_19 + V_20 ) ;
F_7 ( V_14 & ~ V_27 , V_8 -> V_19 + V_20 ) ;
F_11 ( V_8 -> V_15 ) ;
}
static int F_12 ( struct V_28 * V_29 )
{
struct V_1 * V_8 ;
struct V_30 * V_31 ;
int V_26 ;
V_8 = F_13 ( & V_29 -> V_32 , sizeof( * V_8 ) , V_33 ) ;
if ( ! V_8 )
return - V_34 ;
V_31 = F_14 ( V_29 , V_35 , 0 ) ;
V_8 -> V_19 = F_15 ( & V_29 -> V_32 , V_31 ) ;
if ( F_16 ( V_8 -> V_19 ) )
return F_17 ( V_8 -> V_19 ) ;
V_8 -> V_15 = F_18 ( & V_29 -> V_32 , NULL ) ;
if ( F_16 ( V_8 -> V_15 ) ) {
F_19 ( & V_29 -> V_32 , L_1 ) ;
return F_17 ( V_8 -> V_15 ) ;
}
V_8 -> V_3 . V_32 = & V_29 -> V_32 ;
V_8 -> V_3 . V_36 = & V_37 ;
V_8 -> V_3 . V_38 = - 1 ;
V_8 -> V_3 . V_39 = 1 ;
V_26 = F_20 ( & V_8 -> V_3 ) ;
if ( V_26 ) {
F_19 ( & V_29 -> V_32 , L_2 , V_26 ) ;
return V_26 ;
}
F_21 ( V_29 , V_8 ) ;
return 0 ;
}
static int F_22 ( struct V_28 * V_29 )
{
struct V_1 * V_8 = F_23 ( V_29 ) ;
T_2 V_14 ;
V_14 = F_6 ( V_8 -> V_19 + V_20 ) ;
F_7 ( V_14 & ~ V_27 , V_8 -> V_19 + V_20 ) ;
return F_24 ( & V_8 -> V_3 ) ;
}
