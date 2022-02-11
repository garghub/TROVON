static inline T_1 F_1 ( T_2 V_1 , T_2 V_2 )
{
return F_2 ( V_3 . V_4 + V_1 + V_2 ) ;
}
static inline void F_3 ( T_1 V_5 , T_2 V_1 , T_2 V_2 )
{
F_4 ( V_5 , V_3 . V_4 + V_1 + V_2 ) ;
}
static inline T_1 F_5 ( T_1 V_6 , T_1 V_7 , T_3 V_1 , T_3 V_2 )
{
T_1 V_8 ;
V_8 = F_1 ( V_1 , V_2 ) ;
V_8 &= ~ V_6 ;
V_8 |= V_7 ;
F_3 ( V_8 , V_1 , V_2 ) ;
return V_8 ;
}
static T_1 F_6 ( T_2 V_1 , T_2 V_9 )
{
T_1 V_8 = F_1 ( V_1 , V_9 ) ;
V_8 &= V_10 ;
V_8 >>= V_11 ;
return V_8 ;
}
static bool F_7 ( T_2 V_1 , T_2 V_9 )
{
T_1 V_8 ;
V_8 = F_6 ( V_1 , V_9 ) ;
return ( V_8 == V_12 ||
V_8 == V_13 ) ? true : false ;
}
static void F_8 ( T_4 V_14 , T_2 V_1 , T_2 V_15 )
{
T_1 V_8 ;
V_8 = F_1 ( V_1 , V_15 ) ;
V_8 &= ~ V_16 ;
V_8 |= V_14 << V_17 ;
F_3 ( V_8 , V_1 , V_15 ) ;
}
static bool F_9 ( T_2 V_1 , T_2 V_15 )
{
T_1 V_8 ;
V_8 = F_1 ( V_1 , V_15 ) ;
V_8 &= V_16 ;
V_8 >>= V_17 ;
return ( V_8 == V_18 ) ? true : false ;
}
static void F_10 ( T_2 V_1 , T_2 V_15 )
{
F_8 ( V_18 , V_1 , V_15 ) ;
}
static void F_11 ( T_2 V_1 , T_2 V_15 )
{
F_8 ( V_19 , V_1 , V_15 ) ;
}
static void F_12 ( T_2 V_1 , T_2 V_15 )
{
F_8 ( V_20 , V_1 , V_15 ) ;
}
static void F_13 ( T_2 V_1 , T_2 V_15 )
{
F_8 ( V_21 , V_1 , V_15 ) ;
}
static int F_14 ( T_4 V_22 , T_3 V_1 , T_2 V_9 ,
T_4 V_23 )
{
int V_24 = 0 ;
F_15 ( F_7 ( V_1 , V_9 ) ,
V_25 , V_24 ) ;
return ( V_24 < V_25 ) ? 0 : - V_26 ;
}
static int F_16 ( T_4 V_22 , T_3 V_1 , T_2 V_9 ,
T_4 V_23 )
{
int V_24 = 0 ;
F_15 ( ( F_6 ( V_1 , V_9 ) ==
V_27 ) ,
V_25 , V_24 ) ;
return ( V_24 < V_25 ) ? 0 : - V_26 ;
}
static void F_17 ( T_4 V_28 , T_4 V_22 , T_2 V_1 ,
T_2 V_9 )
{
T_1 V_8 ;
V_8 = F_1 ( V_1 , V_9 ) ;
V_8 &= ~ V_29 ;
V_8 |= V_28 << V_30 ;
F_3 ( V_8 , V_1 , V_9 ) ;
}
static void F_18 ( T_4 V_22 , T_2 V_1 , T_2 V_9 )
{
T_1 V_8 ;
V_8 = F_1 ( V_1 , V_9 ) ;
V_8 &= ~ V_29 ;
F_3 ( V_8 , V_1 , V_9 ) ;
}
static int F_19 ( struct V_31 * V_32 )
{
F_12 ( V_32 -> V_33 , V_32 -> V_34 ) ;
return 0 ;
}
static int F_20 ( struct V_31 * V_32 )
{
F_13 ( V_32 -> V_33 , V_32 -> V_34 ) ;
return 0 ;
}
static void F_21 ( struct V_31 * V_32 )
{
F_10 ( V_32 -> V_33 , V_32 -> V_34 ) ;
}
static void F_22 ( struct V_31 * V_32 )
{
F_11 ( V_32 -> V_33 , V_32 -> V_34 ) ;
}
static int F_23 ( struct V_31 * V_32 )
{
if ( V_32 -> V_35 & V_36 )
return F_20 ( V_32 ) ;
return 0 ;
}
static int F_24 ( struct V_31 * V_32 )
{
bool V_37 = false ;
V_37 = F_9 ( V_32 -> V_33 , V_32 -> V_34 ) ;
if ( ! V_37 && ( V_32 -> V_35 & V_38 ) )
F_19 ( V_32 ) ;
return 0 ;
}
int T_5 F_25 ( const struct V_39 * V_40 )
{
return F_26 ( & V_41 ) ;
}
static void T_6 F_27 ( void )
{
F_28 ( & V_41 ) ;
}
