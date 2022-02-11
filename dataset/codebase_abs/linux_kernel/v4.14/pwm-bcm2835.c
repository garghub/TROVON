static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_7 ;
V_7 = F_4 ( V_6 -> V_8 + V_9 ) ;
V_7 &= ~ ( V_10 << F_5 ( V_5 -> V_11 ) ) ;
V_7 |= ( V_12 << F_5 ( V_5 -> V_11 ) ) ;
F_6 ( V_7 , V_6 -> V_8 + V_9 ) ;
return 0 ;
}
static void F_7 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_7 ;
V_7 = F_4 ( V_6 -> V_8 + V_9 ) ;
V_7 &= ~ ( V_10 << F_5 ( V_5 -> V_11 ) ) ;
F_6 ( V_7 , V_6 -> V_8 + V_9 ) ;
}
static int F_8 ( struct V_2 * V_3 , struct V_4 * V_5 ,
int V_13 , int V_14 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned long V_15 = F_9 ( V_6 -> V_16 ) ;
unsigned long V_17 ;
if ( ! V_15 ) {
F_10 ( V_6 -> V_18 , L_1 ) ;
return - V_19 ;
}
V_17 = V_20 / V_15 ;
if ( V_14 <= V_21 ) {
F_10 ( V_6 -> V_18 , L_2 ,
V_14 , V_21 ) ;
return - V_19 ;
}
F_6 ( V_13 / V_17 , V_6 -> V_8 + F_11 ( V_5 -> V_11 ) ) ;
F_6 ( V_14 / V_17 , V_6 -> V_8 + F_12 ( V_5 -> V_11 ) ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_7 ;
V_7 = F_4 ( V_6 -> V_8 + V_9 ) ;
V_7 |= V_22 << F_5 ( V_5 -> V_11 ) ;
F_6 ( V_7 , V_6 -> V_8 + V_9 ) ;
return 0 ;
}
static void F_14 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_7 ;
V_7 = F_4 ( V_6 -> V_8 + V_9 ) ;
V_7 &= ~ ( V_22 << F_5 ( V_5 -> V_11 ) ) ;
F_6 ( V_7 , V_6 -> V_8 + V_9 ) ;
}
static int F_15 ( struct V_2 * V_3 , struct V_4 * V_5 ,
enum V_23 V_24 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_7 ;
V_7 = F_4 ( V_6 -> V_8 + V_9 ) ;
if ( V_24 == V_25 )
V_7 &= ~ ( V_26 << F_5 ( V_5 -> V_11 ) ) ;
else
V_7 |= V_26 << F_5 ( V_5 -> V_11 ) ;
F_6 ( V_7 , V_6 -> V_8 + V_9 ) ;
return 0 ;
}
static int F_16 ( struct V_27 * V_28 )
{
struct V_1 * V_6 ;
struct V_29 * V_30 ;
int V_31 ;
V_6 = F_17 ( & V_28 -> V_18 , sizeof( * V_6 ) , V_32 ) ;
if ( ! V_6 )
return - V_33 ;
V_6 -> V_18 = & V_28 -> V_18 ;
V_30 = F_18 ( V_28 , V_34 , 0 ) ;
V_6 -> V_8 = F_19 ( & V_28 -> V_18 , V_30 ) ;
if ( F_20 ( V_6 -> V_8 ) )
return F_21 ( V_6 -> V_8 ) ;
V_6 -> V_16 = F_22 ( & V_28 -> V_18 , NULL ) ;
if ( F_20 ( V_6 -> V_16 ) ) {
F_10 ( & V_28 -> V_18 , L_3 , F_21 ( V_6 -> V_16 ) ) ;
return F_21 ( V_6 -> V_16 ) ;
}
V_31 = F_23 ( V_6 -> V_16 ) ;
if ( V_31 )
return V_31 ;
V_6 -> V_3 . V_18 = & V_28 -> V_18 ;
V_6 -> V_3 . V_35 = & V_36 ;
V_6 -> V_3 . V_37 = 2 ;
V_6 -> V_3 . V_38 = V_39 ;
V_6 -> V_3 . V_40 = 3 ;
F_24 ( V_28 , V_6 ) ;
V_31 = F_25 ( & V_6 -> V_3 ) ;
if ( V_31 < 0 )
goto V_41;
return 0 ;
V_41:
F_26 ( V_6 -> V_16 ) ;
return V_31 ;
}
static int F_27 ( struct V_27 * V_28 )
{
struct V_1 * V_6 = F_28 ( V_28 ) ;
F_26 ( V_6 -> V_16 ) ;
return F_29 ( & V_6 -> V_3 ) ;
}
