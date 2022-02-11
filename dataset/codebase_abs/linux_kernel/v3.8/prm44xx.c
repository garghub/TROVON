T_1 F_1 ( T_2 V_1 , T_3 V_2 )
{
return F_2 ( F_3 ( V_1 , V_2 ) ) ;
}
void F_4 ( T_1 V_3 , T_2 V_1 , T_3 V_2 )
{
F_5 ( V_3 , F_3 ( V_1 , V_2 ) ) ;
}
T_1 F_6 ( T_1 V_4 , T_1 V_5 , T_2 V_1 , T_2 V_2 )
{
T_1 V_6 ;
V_6 = F_1 ( V_1 , V_2 ) ;
V_6 &= ~ V_4 ;
V_6 |= V_5 ;
F_4 ( V_6 , V_1 , V_2 ) ;
return V_6 ;
}
T_1 F_7 ( T_4 V_7 )
{
struct V_8 * V_9 = & V_8 [ V_7 ] ;
T_1 V_10 ;
V_10 = F_8 ( V_11 ,
V_12 ,
V_9 -> V_13 ) ;
return V_10 & V_9 -> V_14 ;
}
void F_9 ( T_4 V_7 )
{
struct V_8 * V_9 = & V_8 [ V_7 ] ;
F_10 ( V_9 -> V_14 ,
V_11 ,
V_12 ,
V_9 -> V_13 ) ;
}
T_1 F_11 ( T_4 V_15 )
{
return F_8 ( V_11 ,
V_16 , V_15 ) ;
}
void F_12 ( T_1 V_3 , T_4 V_15 )
{
F_10 ( V_3 , V_11 ,
V_16 , V_15 ) ;
}
T_1 F_13 ( T_1 V_4 , T_1 V_5 , T_4 V_15 )
{
return F_14 ( V_4 , V_5 ,
V_11 ,
V_16 ,
V_15 ) ;
}
static inline T_1 F_15 ( T_3 V_17 , T_3 V_18 )
{
T_1 V_4 , V_19 ;
V_4 = F_1 ( V_12 ,
V_17 ) ;
V_19 = F_1 ( V_12 , V_18 ) ;
return V_4 & V_19 ;
}
void F_16 ( unsigned long * V_20 )
{
V_20 [ 0 ] = F_15 ( V_21 ,
V_22 ) ;
V_20 [ 1 ] = F_15 ( V_23 ,
V_24 ) ;
}
void F_17 ( void )
{
F_1 ( V_12 ,
V_25 ) ;
}
void F_18 ( T_1 * V_26 )
{
V_26 [ 0 ] =
F_1 ( V_12 ,
V_22 ) ;
V_26 [ 1 ] =
F_1 ( V_12 ,
V_24 ) ;
F_4 ( 0 , V_12 ,
V_21 ) ;
F_4 ( 0 , V_12 ,
V_23 ) ;
F_1 ( V_12 ,
V_25 ) ;
}
void F_19 ( T_1 * V_26 )
{
F_4 ( V_26 [ 0 ] , V_12 ,
V_21 ) ;
F_4 ( V_26 [ 1 ] , V_12 ,
V_23 ) ;
}
void F_20 ( void )
{
int V_27 = 0 ;
F_6 ( V_28 ,
V_28 ,
V_16 ,
V_29 ) ;
F_21 (
( ( ( F_1 ( V_16 ,
V_29 ) &
V_30 ) >>
V_31 ) == 1 ) ,
V_32 , V_27 ) ;
if ( V_27 == V_32 )
F_22 ( L_1 ) ;
F_6 ( V_28 , 0x0 ,
V_16 ,
V_29 ) ;
F_21 (
( ( ( F_1 ( V_16 ,
V_29 ) &
V_30 ) >>
V_31 ) == 0 ) ,
V_32 , V_27 ) ;
if ( V_27 == V_32 )
F_22 ( L_2 ) ;
return;
}
static void T_5 F_23 ( void )
{
F_6 ( V_33 ,
V_33 ,
V_16 ,
V_29 ) ;
}
static T_1 F_24 ( void )
{
struct V_34 * V_35 ;
T_1 V_36 = 0 ;
T_1 V_6 ;
V_6 = F_1 ( V_16 ,
V_37 ) ;
V_35 = V_38 ;
while ( V_35 -> V_39 >= 0 && V_35 -> V_40 >= 0 ) {
if ( V_6 & ( 1 << V_35 -> V_39 ) )
V_36 |= 1 << V_35 -> V_40 ;
V_35 ++ ;
}
return V_36 ;
}
static bool F_25 ( T_4 V_41 , T_2 V_1 , T_3 V_42 )
{
return ( F_8 ( V_41 , V_1 , V_42 ) ) ? 1 : 0 ;
}
static void F_26 ( T_4 V_41 , T_2 V_1 ,
T_3 V_42 )
{
F_10 ( 0xffffffff , V_41 , V_1 , V_42 ) ;
}
static int F_27 ( struct V_43 * V_44 , T_4 V_45 )
{
F_14 ( V_46 ,
( V_45 << V_47 ) ,
V_44 -> V_48 ,
V_44 -> V_49 , V_50 ) ;
return 0 ;
}
static int F_28 ( struct V_43 * V_44 )
{
T_1 V_6 ;
V_6 = F_8 ( V_44 -> V_48 , V_44 -> V_49 ,
V_50 ) ;
V_6 &= V_46 ;
V_6 >>= V_47 ;
return V_6 ;
}
static int F_29 ( struct V_43 * V_44 )
{
T_1 V_6 ;
V_6 = F_8 ( V_44 -> V_48 , V_44 -> V_49 ,
V_51 ) ;
V_6 &= V_52 ;
V_6 >>= V_53 ;
return V_6 ;
}
static int F_30 ( struct V_43 * V_44 )
{
T_1 V_6 ;
V_6 = F_8 ( V_44 -> V_48 , V_44 -> V_49 ,
V_51 ) ;
V_6 &= V_54 ;
V_6 >>= V_55 ;
return V_6 ;
}
static int F_31 ( struct V_43 * V_44 )
{
F_14 ( V_56 ,
( 1 << V_57 ) ,
V_44 -> V_48 ,
V_44 -> V_49 , V_50 ) ;
return 0 ;
}
static int F_32 ( struct V_43 * V_44 )
{
F_14 ( V_54 ,
V_54 ,
V_44 -> V_48 ,
V_44 -> V_49 , V_51 ) ;
return 0 ;
}
static int F_33 ( struct V_43 * V_44 , T_4 V_45 )
{
T_1 V_6 ;
V_6 = V_45 << F_34 ( V_58 ) ;
F_14 ( V_58 , V_6 ,
V_44 -> V_48 , V_44 -> V_49 ,
V_50 ) ;
return 0 ;
}
static int F_35 ( struct V_43 * V_44 , T_4 V_59 ,
T_4 V_45 )
{
T_1 V_60 ;
V_60 = F_36 ( V_59 ) ;
F_14 ( V_60 , ( V_45 << F_34 ( V_60 ) ) ,
V_44 -> V_48 , V_44 -> V_49 ,
V_50 ) ;
return 0 ;
}
static int F_37 ( struct V_43 * V_44 , T_4 V_59 ,
T_4 V_45 )
{
T_1 V_60 ;
V_60 = F_38 ( V_59 ) ;
F_14 ( V_60 , ( V_45 << F_34 ( V_60 ) ) ,
V_44 -> V_48 , V_44 -> V_49 ,
V_50 ) ;
return 0 ;
}
static int F_39 ( struct V_43 * V_44 )
{
T_1 V_6 ;
V_6 = F_8 ( V_44 -> V_48 , V_44 -> V_49 ,
V_51 ) ;
V_6 &= V_61 ;
V_6 >>= V_62 ;
return V_6 ;
}
static int F_40 ( struct V_43 * V_44 )
{
T_1 V_6 ;
V_6 = F_8 ( V_44 -> V_48 , V_44 -> V_49 ,
V_50 ) ;
V_6 &= V_58 ;
V_6 >>= V_63 ;
return V_6 ;
}
static int F_41 ( struct V_43 * V_44 )
{
int V_64 ;
V_64 = F_30 ( V_44 ) ;
if ( V_64 == V_65 )
return V_65 ;
if ( V_64 != V_66 )
return V_66 ;
return F_40 ( V_44 ) ;
}
static int F_42 ( struct V_43 * V_44 , T_4 V_59 )
{
T_1 V_60 , V_6 ;
V_60 = F_43 ( V_59 ) ;
V_6 = F_8 ( V_44 -> V_48 , V_44 -> V_49 ,
V_51 ) ;
V_6 &= V_60 ;
V_6 >>= F_34 ( V_60 ) ;
return V_6 ;
}
static int F_44 ( struct V_43 * V_44 , T_4 V_59 )
{
T_1 V_60 , V_6 ;
V_60 = F_38 ( V_59 ) ;
V_6 = F_8 ( V_44 -> V_48 , V_44 -> V_49 ,
V_50 ) ;
V_6 &= V_60 ;
V_6 >>= F_34 ( V_60 ) ;
return V_6 ;
}
static int F_45 ( struct V_43 * V_44 , T_4 V_59 )
{
int V_64 ;
V_64 = F_30 ( V_44 ) ;
if ( V_64 == V_65 )
return V_65 ;
if ( V_64 != V_66 )
return V_66 ;
return F_44 ( V_44 , V_59 ) ;
}
static int F_46 ( struct V_43 * V_44 )
{
T_1 V_67 = 0 ;
while ( ( F_8 ( V_44 -> V_48 ,
V_44 -> V_49 ,
V_51 ) &
V_68 ) &&
( V_67 ++ < V_69 ) )
F_47 ( 1 ) ;
if ( V_67 > V_69 ) {
F_48 ( L_3 ,
V_44 -> V_70 ) ;
return - V_71 ;
}
F_49 ( L_4 , V_67 ) ;
return 0 ;
}
int T_5 F_50 ( void )
{
if ( ! F_51 () )
return 0 ;
return F_52 ( & V_72 ) ;
}
static int T_5 F_53 ( void )
{
if ( ! F_51 () )
return 0 ;
F_23 () ;
return F_54 ( & V_73 ) ;
}
static void T_6 F_55 ( void )
{
if ( ! F_51 () )
return;
F_56 ( F_57 ( & V_72 ) ,
L_5 , V_74 ) ;
}
