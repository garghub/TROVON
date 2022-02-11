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
static int F_7 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_1 ( V_5 -> V_3 ) ;
const void T_2 * V_12 = V_6 -> V_7 + V_5 -> V_8 * V_9 + V_10 ;
const unsigned int V_13 = 500 * V_14 ;
T_1 V_15 ;
int V_16 ;
V_16 = F_8 ( V_12 , V_15 , ! ( V_15 & V_17 ) , 40 , V_13 ) ;
if ( V_16 )
F_9 ( V_5 -> V_3 -> V_18 , L_1 ) ;
return V_16 ;
}
static inline int F_10 ( struct V_4 * V_5 )
{
return ( F_3 ( V_5 ) & V_17 ) ? - V_19 : 0 ;
}
static void F_11 ( struct V_1 * V_6 , struct V_4 * V_5 ,
int V_20 , int V_21 )
{
unsigned long long V_22 ;
unsigned long V_23 = V_6 -> V_24 -> V_25 , V_26 ;
unsigned long long V_27 , V_28 = V_29 ;
T_1 V_30 ;
F_12 ( V_28 , V_21 ) ;
V_26 = F_13 ( V_6 -> V_24 -> V_31 ) - 1 ;
V_28 *= V_26 ;
V_27 = F_14 ( V_28 , V_23 ) ;
V_22 = 255ULL * V_20 ;
F_12 ( V_22 , V_21 ) ;
V_22 = 255ULL - V_22 ;
V_30 = F_3 ( V_5 ) ;
V_30 &= ~ V_32 ;
V_30 &= ~ ( V_26 << V_33 ) ;
V_27 &= V_26 ;
V_30 |= ( T_1 ) V_27 << V_33 ;
V_30 |= V_22 ;
F_5 ( V_5 , V_30 ) ;
}
static inline void F_15 ( struct V_4 * V_5 , bool V_34 )
{
if ( V_34 )
F_5 ( V_5 , F_3 ( V_5 ) | V_35 ) ;
}
static int F_16 ( struct V_2 * V_3 , struct V_4 * V_5 ,
struct V_36 * V_37 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_38 ;
if ( V_37 -> V_39 ) {
if ( ! F_17 ( V_5 ) ) {
F_18 ( V_3 -> V_18 ) ;
V_38 = F_10 ( V_5 ) ;
if ( V_38 ) {
F_19 ( V_3 -> V_18 ) ;
return V_38 ;
}
F_11 ( V_6 , V_5 , V_37 -> V_40 , V_37 -> V_41 ) ;
F_5 ( V_5 , F_3 ( V_5 ) | V_17 ) ;
F_15 ( V_5 , V_6 -> V_24 -> V_42 == false ) ;
V_38 = F_7 ( V_5 ) ;
if ( V_38 ) {
F_19 ( V_3 -> V_18 ) ;
return V_38 ;
}
F_15 ( V_5 , V_6 -> V_24 -> V_42 == true ) ;
} else {
V_38 = F_10 ( V_5 ) ;
if ( V_38 )
return V_38 ;
F_11 ( V_6 , V_5 , V_37 -> V_40 , V_37 -> V_41 ) ;
F_5 ( V_5 , F_3 ( V_5 ) | V_17 ) ;
return F_7 ( V_5 ) ;
}
} else if ( F_17 ( V_5 ) ) {
F_5 ( V_5 , F_3 ( V_5 ) & ~ V_35 ) ;
F_19 ( V_3 -> V_18 ) ;
}
return 0 ;
}
struct V_1 * F_20 ( struct V_43 * V_18 , struct V_44 * V_45 ,
const struct V_46 * V_24 )
{
struct V_1 * V_6 ;
unsigned long V_23 ;
int V_38 ;
V_6 = F_21 ( V_18 , sizeof( * V_6 ) , V_47 ) ;
if ( ! V_6 )
return F_22 ( - V_48 ) ;
V_6 -> V_7 = F_23 ( V_18 , V_45 ) ;
if ( F_24 ( V_6 -> V_7 ) )
return F_25 ( V_6 -> V_7 ) ;
V_6 -> V_24 = V_24 ;
V_23 = V_6 -> V_24 -> V_25 ;
if ( ! V_23 )
return F_22 ( - V_49 ) ;
V_6 -> V_3 . V_18 = V_18 ;
V_6 -> V_3 . V_50 = & V_51 ;
V_6 -> V_3 . V_52 = - 1 ;
V_6 -> V_3 . V_53 = V_24 -> V_53 ;
V_38 = F_26 ( & V_6 -> V_3 ) ;
if ( V_38 ) {
F_9 ( V_18 , L_2 , V_38 ) ;
return F_22 ( V_38 ) ;
}
return V_6 ;
}
int F_27 ( struct V_1 * V_6 )
{
return F_28 ( & V_6 -> V_3 ) ;
}
