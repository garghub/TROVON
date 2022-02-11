void F_1 ( void )
{
V_1 [ V_2 ] = V_3 ;
V_1 [ V_4 ] = V_5 ;
V_1 [ V_6 ] = V_7 ;
V_1 [ V_8 ] = V_9 ;
}
static T_1 F_2 ( T_2 V_10 , T_3 V_11 , T_4 V_12 , T_3 V_13 )
{
T_1 V_14 = F_3 ( V_10 , V_11 , V_13 ) ;
V_14 &= V_15 ;
V_14 >>= V_16 ;
return V_14 ;
}
static bool F_4 ( T_2 V_10 , T_3 V_11 , T_4 V_12 , T_3 V_13 )
{
T_1 V_14 ;
V_14 = F_2 ( V_10 , V_11 , V_12 , V_13 ) ;
return ( V_14 == V_17 ||
V_14 == V_18 ) ? true : false ;
}
T_1 F_3 ( T_2 V_10 , T_3 V_11 , T_3 V_19 )
{
F_5 ( V_10 >= V_20 ||
V_10 == V_21 ||
! V_1 [ V_10 ] ) ;
return F_6 ( V_1 [ V_10 ] + V_11 + V_19 ) ;
}
void F_7 ( T_1 V_22 , T_2 V_10 , T_3 V_11 , T_3 V_19 )
{
F_5 ( V_10 >= V_20 ||
V_10 == V_21 ||
! V_1 [ V_10 ] ) ;
F_8 ( V_22 , V_1 [ V_10 ] + V_11 + V_19 ) ;
}
T_1 F_9 ( T_1 V_23 , T_1 V_24 , T_2 V_10 , T_3 V_11 ,
T_4 V_19 )
{
T_1 V_14 ;
V_14 = F_3 ( V_10 , V_11 , V_19 ) ;
V_14 &= ~ V_23 ;
V_14 |= V_24 ;
F_7 ( V_14 , V_10 , V_11 , V_19 ) ;
return V_14 ;
}
T_1 F_10 ( T_1 V_24 , T_2 V_10 , T_3 V_11 , T_4 V_19 )
{
return F_9 ( V_24 , V_24 , V_10 , V_11 , V_19 ) ;
}
T_1 F_11 ( T_1 V_24 , T_2 V_10 , T_3 V_11 , T_4 V_19 )
{
return F_9 ( V_24 , 0x0 , V_10 , V_11 , V_19 ) ;
}
T_1 F_12 ( T_2 V_10 , T_3 V_11 , T_4 V_19 , T_1 V_23 )
{
T_1 V_14 ;
V_14 = F_3 ( V_10 , V_11 , V_19 ) ;
V_14 &= V_23 ;
V_14 >>= F_13 ( V_23 ) ;
return V_14 ;
}
static void F_14 ( T_2 V_25 , T_2 V_10 , T_3 V_11 , T_3 V_12 )
{
T_1 V_14 ;
V_14 = F_3 ( V_10 , V_11 , V_12 + V_26 ) ;
V_14 &= ~ V_27 ;
V_14 |= V_25 << V_28 ;
F_7 ( V_14 , V_10 , V_11 , V_12 + V_26 ) ;
}
bool F_15 ( T_2 V_10 , T_3 V_11 , T_3 V_12 )
{
T_1 V_14 ;
V_14 = F_3 ( V_10 , V_11 , V_12 + V_26 ) ;
V_14 &= V_27 ;
V_14 >>= V_28 ;
return ( V_14 == V_29 ) ? true : false ;
}
void F_16 ( T_2 V_10 , T_3 V_11 , T_3 V_12 )
{
F_14 ( V_29 , V_10 , V_11 , V_12 ) ;
}
void F_17 ( T_2 V_10 , T_3 V_11 , T_3 V_12 )
{
F_14 ( V_30 , V_10 , V_11 , V_12 ) ;
}
void F_18 ( T_2 V_10 , T_3 V_11 , T_3 V_12 )
{
F_14 ( V_31 , V_10 , V_11 , V_12 ) ;
}
void F_19 ( T_2 V_10 , T_3 V_11 , T_3 V_12 )
{
F_14 ( V_32 , V_10 , V_11 , V_12 ) ;
}
int F_20 ( T_2 V_10 , T_3 V_11 , T_4 V_12 ,
T_3 V_13 )
{
int V_33 = 0 ;
if ( ! V_13 )
return 0 ;
F_21 ( F_4 ( V_10 , V_11 , V_12 , V_13 ) ,
V_34 , V_33 ) ;
return ( V_33 < V_34 ) ? 0 : - V_35 ;
}
int F_22 ( T_2 V_10 , T_3 V_11 , T_4 V_12 , T_3 V_13 )
{
int V_33 = 0 ;
if ( ! V_13 )
return 0 ;
F_21 ( ( F_2 ( V_10 , V_11 , V_12 , V_13 ) ==
V_36 ) ,
V_37 , V_33 ) ;
return ( V_33 < V_37 ) ? 0 : - V_35 ;
}
void F_23 ( T_2 V_38 , T_2 V_10 , T_3 V_11 , T_4 V_12 ,
T_3 V_13 )
{
T_1 V_14 ;
V_14 = F_3 ( V_10 , V_11 , V_13 ) ;
V_14 &= ~ V_39 ;
V_14 |= V_38 << V_40 ;
F_7 ( V_14 , V_10 , V_11 , V_13 ) ;
}
void F_24 ( T_2 V_10 , T_3 V_11 , T_4 V_12 ,
T_3 V_13 )
{
T_1 V_14 ;
V_14 = F_3 ( V_10 , V_11 , V_13 ) ;
V_14 &= ~ V_39 ;
F_7 ( V_14 , V_10 , V_11 , V_13 ) ;
}
static int F_25 ( struct V_41 * V_42 ,
struct V_41 * V_43 )
{
F_10 ( ( 1 << V_43 -> V_44 ) ,
V_42 -> V_45 ,
V_42 -> V_46 , V_42 -> V_47 +
V_48 ) ;
return 0 ;
}
static int F_26 ( struct V_41 * V_42 ,
struct V_41 * V_43 )
{
F_11 ( ( 1 << V_43 -> V_44 ) ,
V_42 -> V_45 ,
V_42 -> V_46 , V_42 -> V_47 +
V_48 ) ;
return 0 ;
}
static int F_27 ( struct V_41 * V_42 ,
struct V_41 * V_43 )
{
return F_12 ( V_42 -> V_45 ,
V_42 -> V_46 ,
V_42 -> V_47 +
V_48 ,
( 1 << V_43 -> V_44 ) ) ;
}
static int F_28 ( struct V_41 * V_49 )
{
struct V_50 * V_51 ;
T_1 V_23 = 0 ;
if ( ! V_49 -> V_45 )
return 0 ;
for ( V_51 = V_49 -> V_52 ; V_51 && V_51 -> V_53 ; V_51 ++ ) {
if ( ! V_51 -> V_49 )
continue;
V_23 |= 1 << V_51 -> V_49 -> V_44 ;
V_51 -> V_54 = 0 ;
}
F_11 ( V_23 , V_49 -> V_45 ,
V_49 -> V_46 , V_49 -> V_47 +
V_48 ) ;
return 0 ;
}
static int F_29 ( struct V_41 * V_49 )
{
if ( V_49 -> V_55 & V_56 )
F_16 ( V_49 -> V_45 ,
V_49 -> V_46 ,
V_49 -> V_47 ) ;
else if ( V_49 -> V_55 & V_57 )
F_19 ( V_49 -> V_45 ,
V_49 -> V_46 ,
V_49 -> V_47 ) ;
else
return - V_58 ;
return 0 ;
}
static int F_30 ( struct V_41 * V_49 )
{
F_18 ( V_49 -> V_45 ,
V_49 -> V_46 , V_49 -> V_47 ) ;
return 0 ;
}
static void F_31 ( struct V_41 * V_49 )
{
F_16 ( V_49 -> V_45 ,
V_49 -> V_46 , V_49 -> V_47 ) ;
}
static void F_32 ( struct V_41 * V_49 )
{
if ( V_49 -> V_55 & V_59 )
F_30 ( V_49 ) ;
else
F_17 ( V_49 -> V_45 ,
V_49 -> V_46 ,
V_49 -> V_47 ) ;
}
static int F_33 ( struct V_41 * V_49 )
{
if ( V_49 -> V_55 & V_59 )
return F_30 ( V_49 ) ;
return 0 ;
}
static int F_34 ( struct V_41 * V_49 )
{
bool V_60 = false ;
if ( ! V_49 -> V_45 )
return 0 ;
if ( V_49 -> V_55 & V_61 &&
! ( V_49 -> V_55 & V_57 ) ) {
F_31 ( V_49 ) ;
return 0 ;
}
V_60 = F_15 ( V_49 -> V_45 ,
V_49 -> V_46 , V_49 -> V_47 ) ;
if ( ! V_60 && ( V_49 -> V_55 & V_57 ) )
F_29 ( V_49 ) ;
return 0 ;
}
