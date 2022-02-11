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
if ( V_14 <= V_15 ) {
F_9 ( V_6 -> V_16 , L_1 ,
V_14 , V_15 ) ;
return - V_17 ;
}
F_6 ( V_13 / V_6 -> V_18 , V_6 -> V_8 + F_10 ( V_5 -> V_11 ) ) ;
F_6 ( V_14 / V_6 -> V_18 , V_6 -> V_8 + F_11 ( V_5 -> V_11 ) ) ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_7 ;
V_7 = F_4 ( V_6 -> V_8 + V_9 ) ;
V_7 |= V_19 << F_5 ( V_5 -> V_11 ) ;
F_6 ( V_7 , V_6 -> V_8 + V_9 ) ;
return 0 ;
}
static void F_13 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_7 ;
V_7 = F_4 ( V_6 -> V_8 + V_9 ) ;
V_7 &= ~ ( V_19 << F_5 ( V_5 -> V_11 ) ) ;
F_6 ( V_7 , V_6 -> V_8 + V_9 ) ;
}
static int F_14 ( struct V_2 * V_3 , struct V_4 * V_5 ,
enum V_20 V_21 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_7 ;
V_7 = F_4 ( V_6 -> V_8 + V_9 ) ;
if ( V_21 == V_22 )
V_7 &= ~ ( V_23 << F_5 ( V_5 -> V_11 ) ) ;
else
V_7 |= V_23 << F_5 ( V_5 -> V_11 ) ;
F_6 ( V_7 , V_6 -> V_8 + V_9 ) ;
return 0 ;
}
static int F_15 ( struct V_24 * V_25 )
{
struct V_1 * V_6 ;
struct V_26 * V_27 ;
int V_28 ;
V_6 = F_16 ( & V_25 -> V_16 , sizeof( * V_6 ) , V_29 ) ;
if ( ! V_6 )
return - V_30 ;
V_6 -> V_16 = & V_25 -> V_16 ;
V_27 = F_17 ( V_25 , V_31 , 0 ) ;
V_6 -> V_8 = F_18 ( & V_25 -> V_16 , V_27 ) ;
if ( F_19 ( V_6 -> V_8 ) )
return F_20 ( V_6 -> V_8 ) ;
V_6 -> V_32 = F_21 ( & V_25 -> V_16 , NULL ) ;
if ( F_19 ( V_6 -> V_32 ) ) {
F_9 ( & V_25 -> V_16 , L_2 , F_20 ( V_6 -> V_32 ) ) ;
return F_20 ( V_6 -> V_32 ) ;
}
V_28 = F_22 ( V_6 -> V_32 ) ;
if ( V_28 )
return V_28 ;
V_6 -> V_18 = V_33 / F_23 ( V_6 -> V_32 ) ;
V_6 -> V_3 . V_16 = & V_25 -> V_16 ;
V_6 -> V_3 . V_34 = & V_35 ;
V_6 -> V_3 . V_36 = 2 ;
F_24 ( V_25 , V_6 ) ;
V_28 = F_25 ( & V_6 -> V_3 ) ;
if ( V_28 < 0 )
goto V_37;
return 0 ;
V_37:
F_26 ( V_6 -> V_32 ) ;
return V_28 ;
}
static int F_27 ( struct V_24 * V_25 )
{
struct V_1 * V_6 = F_28 ( V_25 ) ;
F_26 ( V_6 -> V_32 ) ;
return F_29 ( & V_6 -> V_3 ) ;
}
