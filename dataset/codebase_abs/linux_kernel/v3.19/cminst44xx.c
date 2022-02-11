void F_1 ( void )
{
V_1 [ V_2 ] = V_3 ;
V_1 [ V_4 ] = V_5 ;
V_1 [ V_6 ] = V_7 ;
V_1 [ V_8 ] = V_9 ;
}
static T_1 F_2 ( T_2 V_10 , T_3 V_11 , T_3 V_12 )
{
T_1 V_13 = F_3 ( V_10 , V_11 , V_12 ) ;
V_13 &= V_14 ;
V_13 >>= V_15 ;
return V_13 ;
}
static bool F_4 ( T_2 V_10 , T_3 V_11 , T_3 V_12 )
{
T_1 V_13 ;
V_13 = F_2 ( V_10 , V_11 , V_12 ) ;
return ( V_13 == V_16 ||
V_13 == V_17 ) ? true : false ;
}
static T_1 F_3 ( T_2 V_10 , T_3 V_11 , T_3 V_18 )
{
F_5 ( V_10 >= V_19 ||
V_10 == V_20 ||
! V_1 [ V_10 ] ) ;
return F_6 ( V_1 [ V_10 ] + V_11 + V_18 ) ;
}
static void F_7 ( T_1 V_21 , T_2 V_10 , T_3 V_11 , T_3 V_18 )
{
F_5 ( V_10 >= V_19 ||
V_10 == V_20 ||
! V_1 [ V_10 ] ) ;
F_8 ( V_21 , V_1 [ V_10 ] + V_11 + V_18 ) ;
}
static T_1 F_9 ( T_1 V_22 , T_1 V_23 , T_2 V_10 , T_3 V_11 ,
T_4 V_18 )
{
T_1 V_13 ;
V_13 = F_3 ( V_10 , V_11 , V_18 ) ;
V_13 &= ~ V_22 ;
V_13 |= V_23 ;
F_7 ( V_13 , V_10 , V_11 , V_18 ) ;
return V_13 ;
}
static T_1 F_10 ( T_1 V_23 , T_2 V_10 , T_3 V_11 , T_4 V_18 )
{
return F_9 ( V_23 , V_23 , V_10 , V_11 , V_18 ) ;
}
static T_1 F_11 ( T_1 V_23 , T_2 V_10 , T_3 V_11 ,
T_4 V_18 )
{
return F_9 ( V_23 , 0x0 , V_10 , V_11 , V_18 ) ;
}
static T_1 F_12 ( T_2 V_10 , T_3 V_11 , T_4 V_18 , T_1 V_22 )
{
T_1 V_13 ;
V_13 = F_3 ( V_10 , V_11 , V_18 ) ;
V_13 &= V_22 ;
V_13 >>= F_13 ( V_22 ) ;
return V_13 ;
}
static void F_14 ( T_2 V_24 , T_2 V_10 , T_3 V_11 , T_3 V_25 )
{
T_1 V_13 ;
V_13 = F_3 ( V_10 , V_11 , V_25 + V_26 ) ;
V_13 &= ~ V_27 ;
V_13 |= V_24 << V_28 ;
F_7 ( V_13 , V_10 , V_11 , V_25 + V_26 ) ;
}
static bool F_15 ( T_2 V_10 , T_3 V_11 , T_3 V_25 )
{
T_1 V_13 ;
V_13 = F_3 ( V_10 , V_11 , V_25 + V_26 ) ;
V_13 &= V_27 ;
V_13 >>= V_28 ;
return ( V_13 == V_29 ) ? true : false ;
}
static void F_16 ( T_2 V_10 , T_3 V_11 , T_3 V_25 )
{
F_14 ( V_29 , V_10 , V_11 , V_25 ) ;
}
static void F_17 ( T_2 V_10 , T_3 V_11 , T_3 V_25 )
{
F_14 ( V_30 , V_10 , V_11 , V_25 ) ;
}
static void F_18 ( T_2 V_10 , T_3 V_11 , T_3 V_25 )
{
F_14 ( V_31 , V_10 , V_11 , V_25 ) ;
}
static void F_19 ( T_2 V_10 , T_3 V_11 , T_3 V_25 )
{
F_14 ( V_32 , V_10 , V_11 , V_25 ) ;
}
static int F_20 ( T_2 V_10 , T_4 V_11 , T_3 V_12 ,
T_2 V_33 )
{
int V_34 = 0 ;
if ( ! V_12 )
return 0 ;
F_21 ( F_4 ( V_10 , V_11 , V_12 ) ,
V_35 , V_34 ) ;
return ( V_34 < V_35 ) ? 0 : - V_36 ;
}
static int F_22 ( T_2 V_10 , T_4 V_11 , T_3 V_12 ,
T_2 V_33 )
{
int V_34 = 0 ;
if ( ! V_12 )
return 0 ;
F_21 ( ( F_2 ( V_10 , V_11 , V_12 ) ==
V_37 ) ,
V_38 , V_34 ) ;
return ( V_34 < V_38 ) ? 0 : - V_36 ;
}
static void F_23 ( T_2 V_39 , T_2 V_10 , T_3 V_11 ,
T_3 V_12 )
{
T_1 V_13 ;
V_13 = F_3 ( V_10 , V_11 , V_12 ) ;
V_13 &= ~ V_40 ;
V_13 |= V_39 << V_41 ;
F_7 ( V_13 , V_10 , V_11 , V_12 ) ;
}
static void F_24 ( T_2 V_10 , T_3 V_11 , T_3 V_12 )
{
T_1 V_13 ;
V_13 = F_3 ( V_10 , V_11 , V_12 ) ;
V_13 &= ~ V_40 ;
F_7 ( V_13 , V_10 , V_11 , V_12 ) ;
}
static int F_25 ( struct V_42 * V_43 ,
struct V_42 * V_44 )
{
F_10 ( ( 1 << V_44 -> V_45 ) ,
V_43 -> V_46 ,
V_43 -> V_47 , V_43 -> V_48 +
V_49 ) ;
return 0 ;
}
static int F_26 ( struct V_42 * V_43 ,
struct V_42 * V_44 )
{
F_11 ( ( 1 << V_44 -> V_45 ) ,
V_43 -> V_46 ,
V_43 -> V_47 , V_43 -> V_48 +
V_49 ) ;
return 0 ;
}
static int F_27 ( struct V_42 * V_43 ,
struct V_42 * V_44 )
{
return F_12 ( V_43 -> V_46 ,
V_43 -> V_47 ,
V_43 -> V_48 +
V_49 ,
( 1 << V_44 -> V_45 ) ) ;
}
static int F_28 ( struct V_42 * V_50 )
{
struct V_51 * V_52 ;
T_1 V_22 = 0 ;
if ( ! V_50 -> V_46 )
return 0 ;
for ( V_52 = V_50 -> V_53 ; V_52 && V_52 -> V_54 ; V_52 ++ ) {
if ( ! V_52 -> V_50 )
continue;
V_22 |= 1 << V_52 -> V_50 -> V_45 ;
V_52 -> V_55 = 0 ;
}
F_11 ( V_22 , V_50 -> V_46 ,
V_50 -> V_47 , V_50 -> V_48 +
V_49 ) ;
return 0 ;
}
static int F_29 ( struct V_42 * V_50 )
{
if ( V_50 -> V_56 & V_57 )
F_16 ( V_50 -> V_46 ,
V_50 -> V_47 ,
V_50 -> V_48 ) ;
else if ( V_50 -> V_56 & V_58 )
F_19 ( V_50 -> V_46 ,
V_50 -> V_47 ,
V_50 -> V_48 ) ;
else
return - V_59 ;
return 0 ;
}
static int F_30 ( struct V_42 * V_50 )
{
F_18 ( V_50 -> V_46 ,
V_50 -> V_47 , V_50 -> V_48 ) ;
return 0 ;
}
static void F_31 ( struct V_42 * V_50 )
{
F_16 ( V_50 -> V_46 ,
V_50 -> V_47 , V_50 -> V_48 ) ;
}
static void F_32 ( struct V_42 * V_50 )
{
if ( V_50 -> V_56 & V_60 )
F_30 ( V_50 ) ;
else
F_17 ( V_50 -> V_46 ,
V_50 -> V_47 ,
V_50 -> V_48 ) ;
}
static int F_33 ( struct V_42 * V_50 )
{
if ( V_50 -> V_56 & V_60 )
return F_30 ( V_50 ) ;
return 0 ;
}
static int F_34 ( struct V_42 * V_50 )
{
bool V_61 = false ;
if ( ! V_50 -> V_46 )
return 0 ;
if ( V_50 -> V_56 & V_62 &&
! ( V_50 -> V_56 & V_58 ) ) {
F_31 ( V_50 ) ;
return 0 ;
}
V_61 = F_15 ( V_50 -> V_46 ,
V_50 -> V_47 , V_50 -> V_48 ) ;
if ( ! V_61 && ( V_50 -> V_56 & V_58 ) )
F_29 ( V_50 ) ;
return 0 ;
}
int T_5 F_35 ( void )
{
return F_36 ( & V_63 ) ;
}
static void T_6 F_37 ( void )
{
F_38 ( & V_63 ) ;
}
