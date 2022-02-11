static inline T_1 F_1 ( T_2 V_1 , T_3 V_2 )
{
return F_2 ( V_3 + V_1 + V_2 ) ;
}
static inline void F_3 ( T_1 V_4 , T_2 V_1 , T_3 V_2 )
{
F_4 ( V_4 , V_3 + V_1 + V_2 ) ;
}
static inline T_1 F_5 ( T_1 V_5 , T_1 V_6 , T_2 V_1 , T_2 V_2 )
{
T_1 V_7 ;
V_7 = F_1 ( V_1 , V_2 ) ;
V_7 &= ~ V_5 ;
V_7 |= V_6 ;
F_3 ( V_7 , V_1 , V_2 ) ;
return V_7 ;
}
static inline T_1 F_6 ( T_1 V_6 , T_2 V_1 , T_2 V_2 )
{
return F_5 ( V_6 , V_6 , V_1 , V_2 ) ;
}
static inline T_1 F_7 ( T_1 V_6 , T_2 V_1 , T_2 V_2 )
{
return F_5 ( V_6 , 0x0 , V_1 , V_2 ) ;
}
static inline T_1 F_8 ( T_3 V_1 , T_2 V_2 , T_1 V_5 )
{
T_1 V_7 ;
V_7 = F_1 ( V_1 , V_2 ) ;
V_7 &= V_5 ;
V_7 >>= F_9 ( V_5 ) ;
return V_7 ;
}
static T_1 F_10 ( T_3 V_1 , T_2 V_8 , T_3 V_9 )
{
T_1 V_7 = F_1 ( V_1 , V_9 ) ;
V_7 &= V_10 ;
V_7 >>= V_11 ;
return V_7 ;
}
static bool F_11 ( T_3 V_1 , T_2 V_8 , T_3 V_9 )
{
T_1 V_7 ;
V_7 = F_10 ( V_1 , V_8 , V_9 ) ;
return ( V_7 == V_12 ||
V_7 == V_13 ) ? true : false ;
}
static void F_12 ( T_4 V_14 , T_2 V_1 , T_3 V_8 )
{
T_1 V_7 ;
V_7 = F_1 ( V_1 , V_8 ) ;
V_7 &= ~ V_15 ;
V_7 |= V_14 << V_16 ;
F_3 ( V_7 , V_1 , V_8 ) ;
}
bool F_13 ( T_2 V_1 , T_3 V_8 )
{
T_1 V_7 ;
V_7 = F_1 ( V_1 , V_8 ) ;
V_7 &= V_15 ;
V_7 >>= V_16 ;
return ( V_7 == V_17 ) ? true : false ;
}
void F_14 ( T_2 V_1 , T_3 V_8 )
{
F_12 ( V_17 , V_1 , V_8 ) ;
}
void F_15 ( T_2 V_1 , T_3 V_8 )
{
F_12 ( V_18 , V_1 , V_8 ) ;
}
void F_16 ( T_2 V_1 , T_3 V_8 )
{
F_12 ( V_19 , V_1 , V_8 ) ;
}
void F_17 ( T_2 V_1 , T_3 V_8 )
{
F_12 ( V_20 , V_1 , V_8 ) ;
}
int F_18 ( T_3 V_1 , T_2 V_8 , T_3 V_9 )
{
int V_21 = 0 ;
if ( ! V_9 )
return 0 ;
F_19 ( F_11 ( V_1 , V_8 , V_9 ) ,
V_22 , V_21 ) ;
return ( V_21 < V_22 ) ? 0 : - V_23 ;
}
int F_20 ( T_3 V_1 , T_2 V_8 , T_3 V_9 )
{
int V_21 = 0 ;
if ( ! V_9 )
return 0 ;
F_19 ( ( F_10 ( V_1 , V_8 , V_9 ) ==
V_24 ) ,
V_22 , V_21 ) ;
return ( V_21 < V_22 ) ? 0 : - V_23 ;
}
void F_21 ( T_4 V_25 , T_3 V_1 , T_2 V_8 , T_3 V_9 )
{
T_1 V_7 ;
V_7 = F_1 ( V_1 , V_9 ) ;
V_7 &= ~ V_26 ;
V_7 |= V_25 << V_27 ;
F_3 ( V_7 , V_1 , V_9 ) ;
}
void F_22 ( T_3 V_1 , T_2 V_8 , T_3 V_9 )
{
T_1 V_7 ;
V_7 = F_1 ( V_1 , V_9 ) ;
V_7 &= ~ V_26 ;
F_3 ( V_7 , V_1 , V_9 ) ;
}
static int F_23 ( struct V_28 * V_29 )
{
F_16 ( V_29 -> V_30 , V_29 -> V_31 ) ;
return 0 ;
}
static int F_24 ( struct V_28 * V_29 )
{
F_17 ( V_29 -> V_30 , V_29 -> V_31 ) ;
return 0 ;
}
static void F_25 ( struct V_28 * V_29 )
{
F_14 ( V_29 -> V_30 , V_29 -> V_31 ) ;
}
static void F_26 ( struct V_28 * V_29 )
{
F_15 ( V_29 -> V_30 , V_29 -> V_31 ) ;
}
static int F_27 ( struct V_28 * V_29 )
{
if ( V_29 -> V_32 & V_33 )
return F_24 ( V_29 ) ;
return 0 ;
}
static int F_28 ( struct V_28 * V_29 )
{
bool V_34 = false ;
V_34 = F_13 ( V_29 -> V_30 , V_29 -> V_31 ) ;
if ( ! V_34 && ( V_29 -> V_32 & V_35 ) )
F_23 ( V_29 ) ;
return 0 ;
}
