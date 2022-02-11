static inline T_1 F_1 ( T_2 V_1 , T_2 V_2 )
{
return F_2 ( V_3 + V_1 + V_2 ) ;
}
static inline void F_3 ( T_1 V_4 , T_2 V_1 , T_2 V_2 )
{
F_4 ( V_4 , V_3 + V_1 + V_2 ) ;
}
static inline T_1 F_5 ( T_1 V_5 , T_1 V_6 , T_3 V_1 , T_3 V_2 )
{
T_1 V_7 ;
V_7 = F_1 ( V_1 , V_2 ) ;
V_7 &= ~ V_5 ;
V_7 |= V_6 ;
F_3 ( V_7 , V_1 , V_2 ) ;
return V_7 ;
}
static T_1 F_6 ( T_2 V_1 , T_2 V_8 )
{
T_1 V_7 = F_1 ( V_1 , V_8 ) ;
V_7 &= V_9 ;
V_7 >>= V_10 ;
return V_7 ;
}
static bool F_7 ( T_2 V_1 , T_2 V_8 )
{
T_1 V_7 ;
V_7 = F_6 ( V_1 , V_8 ) ;
return ( V_7 == V_11 ||
V_7 == V_12 ) ? true : false ;
}
static void F_8 ( T_4 V_13 , T_2 V_1 , T_2 V_14 )
{
T_1 V_7 ;
V_7 = F_1 ( V_1 , V_14 ) ;
V_7 &= ~ V_15 ;
V_7 |= V_13 << V_16 ;
F_3 ( V_7 , V_1 , V_14 ) ;
}
static bool F_9 ( T_2 V_1 , T_2 V_14 )
{
T_1 V_7 ;
V_7 = F_1 ( V_1 , V_14 ) ;
V_7 &= V_15 ;
V_7 >>= V_16 ;
return ( V_7 == V_17 ) ? true : false ;
}
static void F_10 ( T_2 V_1 , T_2 V_14 )
{
F_8 ( V_17 , V_1 , V_14 ) ;
}
static void F_11 ( T_2 V_1 , T_2 V_14 )
{
F_8 ( V_18 , V_1 , V_14 ) ;
}
static void F_12 ( T_2 V_1 , T_2 V_14 )
{
F_8 ( V_19 , V_1 , V_14 ) ;
}
static void F_13 ( T_2 V_1 , T_2 V_14 )
{
F_8 ( V_20 , V_1 , V_14 ) ;
}
static int F_14 ( T_4 V_21 , T_3 V_1 , T_2 V_8 ,
T_4 V_22 )
{
int V_23 = 0 ;
F_15 ( F_7 ( V_1 , V_8 ) ,
V_24 , V_23 ) ;
return ( V_23 < V_24 ) ? 0 : - V_25 ;
}
static int F_16 ( T_4 V_21 , T_3 V_1 , T_2 V_8 ,
T_4 V_22 )
{
int V_23 = 0 ;
if ( ! V_8 )
return 0 ;
F_15 ( ( F_6 ( V_1 , V_8 ) ==
V_26 ) ,
V_24 , V_23 ) ;
return ( V_23 < V_24 ) ? 0 : - V_25 ;
}
static void F_17 ( T_4 V_27 , T_4 V_21 , T_2 V_1 ,
T_2 V_8 )
{
T_1 V_7 ;
V_7 = F_1 ( V_1 , V_8 ) ;
V_7 &= ~ V_28 ;
V_7 |= V_27 << V_29 ;
F_3 ( V_7 , V_1 , V_8 ) ;
}
static void F_18 ( T_4 V_21 , T_2 V_1 , T_2 V_8 )
{
T_1 V_7 ;
V_7 = F_1 ( V_1 , V_8 ) ;
V_7 &= ~ V_28 ;
F_3 ( V_7 , V_1 , V_8 ) ;
}
static int F_19 ( struct V_30 * V_31 )
{
F_12 ( V_31 -> V_32 , V_31 -> V_33 ) ;
return 0 ;
}
static int F_20 ( struct V_30 * V_31 )
{
F_13 ( V_31 -> V_32 , V_31 -> V_33 ) ;
return 0 ;
}
static void F_21 ( struct V_30 * V_31 )
{
F_10 ( V_31 -> V_32 , V_31 -> V_33 ) ;
}
static void F_22 ( struct V_30 * V_31 )
{
F_11 ( V_31 -> V_32 , V_31 -> V_33 ) ;
}
static int F_23 ( struct V_30 * V_31 )
{
if ( V_31 -> V_34 & V_35 )
return F_20 ( V_31 ) ;
return 0 ;
}
static int F_24 ( struct V_30 * V_31 )
{
bool V_36 = false ;
V_36 = F_9 ( V_31 -> V_32 , V_31 -> V_33 ) ;
if ( ! V_36 && ( V_31 -> V_34 & V_37 ) )
F_19 ( V_31 ) ;
return 0 ;
}
int T_5 F_25 ( const struct V_38 * V_39 )
{
return F_26 ( & V_40 ) ;
}
static void T_6 F_27 ( void )
{
F_28 ( & V_40 ) ;
}
