static void F_1 ( void )
{
memcpy ( & V_1 [ V_2 ] , & V_3 , sizeof( V_3 ) ) ;
memcpy ( & V_1 [ V_4 ] , & V_5 , sizeof( V_5 ) ) ;
memcpy ( & V_1 [ V_6 ] , & V_7 , sizeof( V_7 ) ) ;
memcpy ( & V_1 [ V_8 ] , & V_9 ,
sizeof( V_9 ) ) ;
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
! V_1 [ V_10 ] . V_21 ) ;
return F_6 ( V_1 [ V_10 ] . V_21 + V_11 + V_18 ) ;
}
static void F_7 ( T_1 V_22 , T_2 V_10 , T_3 V_11 , T_3 V_18 )
{
F_5 ( V_10 >= V_19 ||
V_10 == V_20 ||
! V_1 [ V_10 ] . V_21 ) ;
F_8 ( V_22 , V_1 [ V_10 ] . V_21 + V_11 + V_18 ) ;
}
static T_1 F_9 ( T_1 V_23 , T_1 V_24 , T_2 V_10 , T_3 V_11 ,
T_4 V_18 )
{
T_1 V_13 ;
V_13 = F_3 ( V_10 , V_11 , V_18 ) ;
V_13 &= ~ V_23 ;
V_13 |= V_24 ;
F_7 ( V_13 , V_10 , V_11 , V_18 ) ;
return V_13 ;
}
static T_1 F_10 ( T_1 V_24 , T_2 V_10 , T_3 V_11 , T_4 V_18 )
{
return F_9 ( V_24 , V_24 , V_10 , V_11 , V_18 ) ;
}
static T_1 F_11 ( T_1 V_24 , T_2 V_10 , T_3 V_11 ,
T_4 V_18 )
{
return F_9 ( V_24 , 0x0 , V_10 , V_11 , V_18 ) ;
}
static T_1 F_12 ( T_2 V_10 , T_3 V_11 , T_4 V_18 , T_1 V_23 )
{
T_1 V_13 ;
V_13 = F_3 ( V_10 , V_11 , V_18 ) ;
V_13 &= V_23 ;
V_13 >>= F_13 ( V_23 ) ;
return V_13 ;
}
static void F_14 ( T_2 V_25 , T_2 V_10 , T_3 V_11 , T_3 V_26 )
{
T_1 V_13 ;
V_13 = F_3 ( V_10 , V_11 , V_26 + V_27 ) ;
V_13 &= ~ V_28 ;
V_13 |= V_25 << V_29 ;
F_7 ( V_13 , V_10 , V_11 , V_26 + V_27 ) ;
}
static bool F_15 ( T_2 V_10 , T_3 V_11 , T_3 V_26 )
{
T_1 V_13 ;
V_13 = F_3 ( V_10 , V_11 , V_26 + V_27 ) ;
V_13 &= V_28 ;
V_13 >>= V_29 ;
return ( V_13 == V_30 ) ? true : false ;
}
static void F_16 ( T_2 V_10 , T_3 V_11 , T_3 V_26 )
{
F_14 ( V_30 , V_10 , V_11 , V_26 ) ;
}
static void F_17 ( T_2 V_10 , T_3 V_11 , T_3 V_26 )
{
F_14 ( V_31 , V_10 , V_11 , V_26 ) ;
}
static void F_18 ( T_2 V_10 , T_3 V_11 , T_3 V_26 )
{
F_14 ( V_32 , V_10 , V_11 , V_26 ) ;
}
static void F_19 ( T_2 V_10 , T_3 V_11 , T_3 V_26 )
{
F_14 ( V_33 , V_10 , V_11 , V_26 ) ;
}
static int F_20 ( T_2 V_10 , T_4 V_11 , T_3 V_12 ,
T_2 V_34 )
{
int V_35 = 0 ;
F_21 ( F_4 ( V_10 , V_11 , V_12 ) ,
V_36 , V_35 ) ;
return ( V_35 < V_36 ) ? 0 : - V_37 ;
}
static int F_22 ( T_2 V_10 , T_4 V_11 , T_3 V_12 ,
T_2 V_34 )
{
int V_35 = 0 ;
F_21 ( ( F_2 ( V_10 , V_11 , V_12 ) ==
V_38 ) ,
V_39 , V_35 ) ;
return ( V_35 < V_39 ) ? 0 : - V_37 ;
}
static void F_23 ( T_2 V_40 , T_2 V_10 , T_3 V_11 ,
T_3 V_12 )
{
T_1 V_13 ;
V_13 = F_3 ( V_10 , V_11 , V_12 ) ;
V_13 &= ~ V_41 ;
V_13 |= V_40 << V_42 ;
F_7 ( V_13 , V_10 , V_11 , V_12 ) ;
}
static void F_24 ( T_2 V_10 , T_3 V_11 , T_3 V_12 )
{
T_1 V_13 ;
V_13 = F_3 ( V_10 , V_11 , V_12 ) ;
V_13 &= ~ V_41 ;
F_7 ( V_13 , V_10 , V_11 , V_12 ) ;
}
static int F_25 ( struct V_43 * V_44 ,
struct V_43 * V_45 )
{
F_10 ( ( 1 << V_45 -> V_46 ) ,
V_44 -> V_47 ,
V_44 -> V_48 , V_44 -> V_49 +
V_50 ) ;
return 0 ;
}
static int F_26 ( struct V_43 * V_44 ,
struct V_43 * V_45 )
{
F_11 ( ( 1 << V_45 -> V_46 ) ,
V_44 -> V_47 ,
V_44 -> V_48 , V_44 -> V_49 +
V_50 ) ;
return 0 ;
}
static int F_27 ( struct V_43 * V_44 ,
struct V_43 * V_45 )
{
return F_12 ( V_44 -> V_47 ,
V_44 -> V_48 ,
V_44 -> V_49 +
V_50 ,
( 1 << V_45 -> V_46 ) ) ;
}
static int F_28 ( struct V_43 * V_51 )
{
struct V_52 * V_53 ;
T_1 V_23 = 0 ;
if ( ! V_51 -> V_47 )
return 0 ;
for ( V_53 = V_51 -> V_54 ; V_53 && V_53 -> V_55 ; V_53 ++ ) {
if ( ! V_53 -> V_51 )
continue;
V_23 |= 1 << V_53 -> V_51 -> V_46 ;
V_53 -> V_56 = 0 ;
}
F_11 ( V_23 , V_51 -> V_47 ,
V_51 -> V_48 , V_51 -> V_49 +
V_50 ) ;
return 0 ;
}
static int F_29 ( struct V_43 * V_51 )
{
if ( V_51 -> V_57 & V_58 )
F_16 ( V_51 -> V_47 ,
V_51 -> V_48 ,
V_51 -> V_49 ) ;
else if ( V_51 -> V_57 & V_59 )
F_19 ( V_51 -> V_47 ,
V_51 -> V_48 ,
V_51 -> V_49 ) ;
else
return - V_60 ;
return 0 ;
}
static int F_30 ( struct V_43 * V_51 )
{
F_18 ( V_51 -> V_47 ,
V_51 -> V_48 , V_51 -> V_49 ) ;
return 0 ;
}
static void F_31 ( struct V_43 * V_51 )
{
F_16 ( V_51 -> V_47 ,
V_51 -> V_48 , V_51 -> V_49 ) ;
}
static void F_32 ( struct V_43 * V_51 )
{
if ( V_51 -> V_57 & V_61 )
F_30 ( V_51 ) ;
else
F_17 ( V_51 -> V_47 ,
V_51 -> V_48 ,
V_51 -> V_49 ) ;
}
static int F_33 ( struct V_43 * V_51 )
{
if ( V_51 -> V_57 & V_61 )
return F_30 ( V_51 ) ;
return 0 ;
}
static int F_34 ( struct V_43 * V_51 )
{
bool V_62 = false ;
if ( ! V_51 -> V_47 )
return 0 ;
if ( V_51 -> V_57 & V_63 &&
! ( V_51 -> V_57 & V_59 ) ) {
F_31 ( V_51 ) ;
return 0 ;
}
V_62 = F_15 ( V_51 -> V_47 ,
V_51 -> V_48 , V_51 -> V_49 ) ;
if ( ! V_62 && ( V_51 -> V_57 & V_59 ) )
F_29 ( V_51 ) ;
return 0 ;
}
static T_1 F_35 ( struct V_43 * V_51 )
{
T_1 V_64 = V_1 [ V_51 -> V_47 ] . V_65 + V_51 -> V_48 +
V_51 -> V_49 ;
return V_64 ;
}
int T_5 F_36 ( const struct V_66 * V_67 )
{
F_1 () ;
return F_37 ( & V_68 ) ;
}
static void T_6 F_38 ( void )
{
F_39 ( & V_68 ) ;
}
