static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , struct V_4 * V_5 ,
int V_6 , int V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
T_1 V_9 , V_10 ;
unsigned long long V_11 ;
T_2 V_12 ;
if ( V_7 > V_13 )
return - V_14 ;
V_11 = V_8 -> V_15 ;
V_11 = V_11 * V_7 ;
F_4 ( V_11 , V_13 ) ;
V_9 = ( T_1 ) V_11 ;
if ( V_9 < 1 ) {
V_9 = 1 ;
V_10 = 1 ;
} else {
V_11 = V_8 -> V_15 ;
V_11 = V_11 * V_6 ;
F_4 ( V_11 , V_13 ) ;
V_10 = ( T_1 ) V_11 ;
}
F_5 ( V_8 -> V_3 . V_16 ) ;
V_12 = F_6 ( V_8 -> V_17 + V_18 ) ;
V_12 |= V_19 | V_20 ;
F_7 ( V_12 , V_8 -> V_17 + V_18 ) ;
if ( ! F_8 ( V_5 ) ) {
F_9 ( V_10 , V_8 -> V_17 + V_21 ) ;
F_9 ( V_9 , V_8 -> V_17 + V_22 ) ;
} else {
F_9 ( V_10 , V_8 -> V_17 + V_23 ) ;
F_9 ( V_9 , V_8 -> V_17 + V_24 ) ;
}
if ( ! F_8 ( V_5 ) ) {
V_12 = F_6 ( V_8 -> V_17 + V_18 ) ;
V_12 &= ~ V_19 ;
F_7 ( V_12 , V_8 -> V_17 + V_18 ) ;
}
F_10 ( V_8 -> V_3 . V_16 ) ;
return 0 ;
}
static int F_11 ( struct V_2 * V_3 , struct V_4 * V_5 ,
enum V_25 V_26 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
T_2 V_12 ;
F_5 ( V_8 -> V_3 . V_16 ) ;
V_12 = F_6 ( V_8 -> V_17 + V_18 ) ;
if ( V_26 == V_27 )
V_12 |= V_28 ;
else
V_12 &= ~ V_28 ;
F_7 ( V_12 , V_8 -> V_17 + V_18 ) ;
F_10 ( V_8 -> V_3 . V_16 ) ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
T_2 V_12 ;
F_5 ( V_8 -> V_3 . V_16 ) ;
V_12 = F_6 ( V_8 -> V_17 + V_18 ) ;
V_12 |= V_29 | V_19 ;
F_7 ( V_12 , V_8 -> V_17 + V_18 ) ;
return 0 ;
}
static void F_13 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
T_2 V_12 ;
V_12 = F_6 ( V_8 -> V_17 + V_18 ) ;
V_12 &= ~ ( V_29 | V_19 ) ;
F_7 ( V_12 , V_8 -> V_17 + V_18 ) ;
F_10 ( V_8 -> V_3 . V_16 ) ;
}
static void F_14 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
if ( F_8 ( V_5 ) ) {
F_15 ( V_3 -> V_16 , L_1 ) ;
F_10 ( V_3 -> V_16 ) ;
}
}
static int F_16 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_16 . V_34 ;
struct V_1 * V_8 ;
struct V_35 * V_36 ;
struct V_37 * V_37 ;
int V_38 ;
V_8 = F_17 ( & V_31 -> V_16 , sizeof( * V_8 ) , V_39 ) ;
if ( ! V_8 )
return - V_40 ;
V_37 = F_18 ( & V_31 -> V_16 , L_2 ) ;
if ( F_19 ( V_37 ) ) {
if ( F_20 ( V_33 , L_3 ) ) {
F_15 ( & V_31 -> V_16 , L_4 ) ;
V_37 = F_18 ( V_31 -> V_16 . V_41 , L_2 ) ;
}
}
if ( F_19 ( V_37 ) ) {
F_21 ( & V_31 -> V_16 , L_5 ) ;
return F_22 ( V_37 ) ;
}
V_8 -> V_15 = F_23 ( V_37 ) ;
if ( ! V_8 -> V_15 ) {
F_21 ( & V_31 -> V_16 , L_6 ) ;
return - V_42 ;
}
V_8 -> V_3 . V_16 = & V_31 -> V_16 ;
V_8 -> V_3 . V_43 = & V_44 ;
V_8 -> V_3 . V_45 = V_46 ;
V_8 -> V_3 . V_47 = 3 ;
V_8 -> V_3 . V_48 = - 1 ;
V_8 -> V_3 . V_49 = 1 ;
V_36 = F_24 ( V_31 , V_50 , 0 ) ;
V_8 -> V_17 = F_25 ( & V_31 -> V_16 , V_36 ) ;
if ( F_19 ( V_8 -> V_17 ) )
return F_22 ( V_8 -> V_17 ) ;
V_38 = F_26 ( & V_8 -> V_3 ) ;
if ( V_38 < 0 ) {
F_21 ( & V_31 -> V_16 , L_7 , V_38 ) ;
return V_38 ;
}
F_27 ( V_31 , V_8 ) ;
F_28 ( & V_31 -> V_16 ) ;
return 0 ;
}
static int F_29 ( struct V_30 * V_31 )
{
struct V_1 * V_8 = F_30 ( V_31 ) ;
F_31 ( & V_31 -> V_16 ) ;
return F_32 ( & V_8 -> V_3 ) ;
}
static void F_33 ( struct V_1 * V_8 )
{
F_5 ( V_8 -> V_3 . V_16 ) ;
V_8 -> V_51 . V_52 = F_6 ( V_8 -> V_17 + V_18 ) ;
V_8 -> V_51 . V_53 = F_34 ( V_8 -> V_17 + V_23 ) ;
V_8 -> V_51 . V_54 = F_34 ( V_8 -> V_17 + V_24 ) ;
F_10 ( V_8 -> V_3 . V_16 ) ;
}
static void F_35 ( struct V_1 * V_8 )
{
F_9 ( V_8 -> V_51 . V_54 , V_8 -> V_17 + V_24 ) ;
F_9 ( V_8 -> V_51 . V_53 , V_8 -> V_17 + V_23 ) ;
F_7 ( V_8 -> V_51 . V_52 , V_8 -> V_17 + V_18 ) ;
}
static int F_36 ( struct V_55 * V_16 )
{
struct V_1 * V_8 = F_37 ( V_16 ) ;
struct V_4 * V_5 = V_8 -> V_3 . V_56 ;
F_33 ( V_8 ) ;
if ( F_8 ( V_5 ) )
F_10 ( V_16 ) ;
return 0 ;
}
static int F_38 ( struct V_55 * V_16 )
{
struct V_1 * V_8 = F_37 ( V_16 ) ;
struct V_4 * V_5 = V_8 -> V_3 . V_56 ;
if ( F_8 ( V_5 ) )
F_5 ( V_16 ) ;
F_35 ( V_8 ) ;
return 0 ;
}
