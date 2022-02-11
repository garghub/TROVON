T_1 F_1 ( T_2 V_1 , T_3 V_2 )
{
return F_2 ( V_3 + V_1 + V_2 ) ;
}
void F_3 ( T_1 V_4 , T_2 V_1 , T_3 V_2 )
{
F_4 ( V_4 , V_3 + V_1 + V_2 ) ;
}
T_1 F_5 ( T_1 V_5 , T_1 V_6 , T_2 V_1 , T_2 V_2 )
{
T_1 V_7 ;
V_7 = F_1 ( V_1 , V_2 ) ;
V_7 &= ~ V_5 ;
V_7 |= V_6 ;
F_3 ( V_7 , V_1 , V_2 ) ;
return V_7 ;
}
T_1 F_6 ( T_4 V_8 )
{
struct V_9 * V_10 = & V_9 [ V_8 ] ;
T_1 V_11 ;
V_11 = F_7 ( V_12 ,
V_13 ,
V_10 -> V_14 ) ;
return V_11 & V_10 -> V_15 ;
}
void F_8 ( T_4 V_8 )
{
struct V_9 * V_10 = & V_9 [ V_8 ] ;
F_9 ( V_10 -> V_15 ,
V_12 ,
V_13 ,
V_10 -> V_14 ) ;
}
T_1 F_10 ( T_4 V_16 )
{
T_5 V_1 = F_11 () ;
if ( V_1 == V_17 )
return 0 ;
return F_7 ( V_12 ,
V_1 , V_16 ) ;
}
void F_12 ( T_1 V_4 , T_4 V_16 )
{
T_5 V_1 = F_11 () ;
if ( V_1 == V_17 )
return;
F_9 ( V_4 , V_12 ,
V_1 , V_16 ) ;
}
T_1 F_13 ( T_1 V_5 , T_1 V_6 , T_4 V_16 )
{
T_5 V_1 = F_11 () ;
if ( V_1 == V_17 )
return 0 ;
return F_14 ( V_5 , V_6 ,
V_12 ,
V_1 ,
V_16 ) ;
}
static inline T_1 F_15 ( T_3 V_18 , T_3 V_19 )
{
T_1 V_5 , V_20 ;
V_5 = F_1 ( V_13 ,
V_18 ) ;
V_20 = F_1 ( V_13 , V_19 ) ;
return V_5 & V_20 ;
}
void F_16 ( unsigned long * V_21 )
{
V_21 [ 0 ] = F_15 ( V_22 ,
V_23 ) ;
V_21 [ 1 ] = F_15 ( V_24 ,
V_25 ) ;
}
void F_17 ( void )
{
F_1 ( V_13 ,
V_26 ) ;
}
void F_18 ( T_1 * V_27 )
{
V_27 [ 0 ] =
F_1 ( V_13 ,
V_23 ) ;
V_27 [ 1 ] =
F_1 ( V_13 ,
V_25 ) ;
F_3 ( 0 , V_13 ,
V_22 ) ;
F_3 ( 0 , V_13 ,
V_24 ) ;
F_1 ( V_13 ,
V_26 ) ;
}
void F_19 ( T_1 * V_27 )
{
F_3 ( V_27 [ 0 ] , V_13 ,
V_22 ) ;
F_3 ( V_27 [ 1 ] , V_13 ,
V_24 ) ;
}
void F_20 ( void )
{
int V_28 = 0 ;
T_5 V_1 = F_11 () ;
if ( V_1 == V_17 )
return;
F_5 ( V_29 ,
V_29 ,
V_1 ,
V_30 ) ;
F_21 (
( ( ( F_1 ( V_1 ,
V_30 ) &
V_31 ) >>
V_32 ) == 1 ) ,
V_33 , V_28 ) ;
if ( V_28 == V_33 )
F_22 ( L_1 ) ;
F_5 ( V_29 , 0x0 ,
V_1 ,
V_30 ) ;
F_21 (
( ( ( F_1 ( V_1 ,
V_30 ) &
V_31 ) >>
V_32 ) == 0 ) ,
V_33 , V_28 ) ;
if ( V_28 == V_33 )
F_22 ( L_2 ) ;
return;
}
static void T_6 F_23 ( void )
{
T_5 V_1 = F_11 () ;
if ( V_1 == V_17 )
return;
F_5 ( V_34 ,
V_34 ,
V_1 ,
V_30 ) ;
}
static T_1 F_24 ( void )
{
struct V_35 * V_36 ;
T_1 V_37 = 0 ;
T_1 V_7 ;
T_5 V_1 = F_11 () ;
if ( V_1 == V_17 )
return 0 ;
V_7 = F_1 ( V_1 ,
V_38 ) ;
V_36 = V_39 ;
while ( V_36 -> V_40 >= 0 && V_36 -> V_41 >= 0 ) {
if ( V_7 & ( 1 << V_36 -> V_40 ) )
V_37 |= 1 << V_36 -> V_41 ;
V_36 ++ ;
}
return V_37 ;
}
static bool F_25 ( T_4 V_42 , T_2 V_1 , T_3 V_43 )
{
return ( F_7 ( V_42 , V_1 , V_43 ) ) ? 1 : 0 ;
}
static void F_26 ( T_4 V_42 , T_2 V_1 ,
T_3 V_43 )
{
F_9 ( 0xffffffff , V_42 , V_1 , V_43 ) ;
}
static int F_27 ( struct V_44 * V_45 , T_4 V_46 )
{
F_14 ( V_47 ,
( V_46 << V_48 ) ,
V_45 -> V_49 ,
V_45 -> V_50 , V_51 ) ;
return 0 ;
}
static int F_28 ( struct V_44 * V_45 )
{
T_1 V_7 ;
V_7 = F_7 ( V_45 -> V_49 , V_45 -> V_50 ,
V_51 ) ;
V_7 &= V_47 ;
V_7 >>= V_48 ;
return V_7 ;
}
static int F_29 ( struct V_44 * V_45 )
{
T_1 V_7 ;
V_7 = F_7 ( V_45 -> V_49 , V_45 -> V_50 ,
V_52 ) ;
V_7 &= V_53 ;
V_7 >>= V_54 ;
return V_7 ;
}
static int F_30 ( struct V_44 * V_45 )
{
T_1 V_7 ;
V_7 = F_7 ( V_45 -> V_49 , V_45 -> V_50 ,
V_52 ) ;
V_7 &= V_55 ;
V_7 >>= V_56 ;
return V_7 ;
}
static int F_31 ( struct V_44 * V_45 )
{
F_14 ( V_57 ,
( 1 << V_58 ) ,
V_45 -> V_49 ,
V_45 -> V_50 , V_51 ) ;
return 0 ;
}
static int F_32 ( struct V_44 * V_45 )
{
F_14 ( V_55 ,
V_55 ,
V_45 -> V_49 ,
V_45 -> V_50 , V_52 ) ;
return 0 ;
}
static int F_33 ( struct V_44 * V_45 , T_4 V_46 )
{
T_1 V_7 ;
V_7 = V_46 << F_34 ( V_59 ) ;
F_14 ( V_59 , V_7 ,
V_45 -> V_49 , V_45 -> V_50 ,
V_51 ) ;
return 0 ;
}
static int F_35 ( struct V_44 * V_45 , T_4 V_60 ,
T_4 V_46 )
{
T_1 V_61 ;
V_61 = F_36 ( V_60 ) ;
F_14 ( V_61 , ( V_46 << F_34 ( V_61 ) ) ,
V_45 -> V_49 , V_45 -> V_50 ,
V_51 ) ;
return 0 ;
}
static int F_37 ( struct V_44 * V_45 , T_4 V_60 ,
T_4 V_46 )
{
T_1 V_61 ;
V_61 = F_38 ( V_60 ) ;
F_14 ( V_61 , ( V_46 << F_34 ( V_61 ) ) ,
V_45 -> V_49 , V_45 -> V_50 ,
V_51 ) ;
return 0 ;
}
static int F_39 ( struct V_44 * V_45 )
{
T_1 V_7 ;
V_7 = F_7 ( V_45 -> V_49 , V_45 -> V_50 ,
V_52 ) ;
V_7 &= V_62 ;
V_7 >>= V_63 ;
return V_7 ;
}
static int F_40 ( struct V_44 * V_45 )
{
T_1 V_7 ;
V_7 = F_7 ( V_45 -> V_49 , V_45 -> V_50 ,
V_51 ) ;
V_7 &= V_59 ;
V_7 >>= V_64 ;
return V_7 ;
}
static int F_41 ( struct V_44 * V_45 )
{
int V_65 ;
V_65 = F_30 ( V_45 ) ;
if ( V_65 == V_66 )
return V_66 ;
if ( V_65 != V_67 )
return V_67 ;
return F_40 ( V_45 ) ;
}
static int F_42 ( struct V_44 * V_45 , T_4 V_60 )
{
T_1 V_61 , V_7 ;
V_61 = F_43 ( V_60 ) ;
V_7 = F_7 ( V_45 -> V_49 , V_45 -> V_50 ,
V_52 ) ;
V_7 &= V_61 ;
V_7 >>= F_34 ( V_61 ) ;
return V_7 ;
}
static int F_44 ( struct V_44 * V_45 , T_4 V_60 )
{
T_1 V_61 , V_7 ;
V_61 = F_38 ( V_60 ) ;
V_7 = F_7 ( V_45 -> V_49 , V_45 -> V_50 ,
V_51 ) ;
V_7 &= V_61 ;
V_7 >>= F_34 ( V_61 ) ;
return V_7 ;
}
static int F_45 ( struct V_44 * V_45 , T_4 V_60 )
{
int V_65 ;
V_65 = F_30 ( V_45 ) ;
if ( V_65 == V_66 )
return V_66 ;
if ( V_65 != V_67 )
return V_67 ;
return F_44 ( V_45 , V_60 ) ;
}
static int F_46 ( struct V_44 * V_45 )
{
T_1 V_68 = 0 ;
while ( ( F_7 ( V_45 -> V_49 ,
V_45 -> V_50 ,
V_52 ) &
V_69 ) &&
( V_68 ++ < V_70 ) )
F_47 ( 1 ) ;
if ( V_68 > V_70 ) {
F_48 ( L_3 ,
V_45 -> V_71 ) ;
return - V_72 ;
}
F_49 ( L_4 , V_68 ) ;
return 0 ;
}
static int F_50 ( void )
{
if ( F_51 () )
return 0 ;
return 1 ;
}
int T_6 F_52 ( void )
{
if ( F_53 () || F_54 () || F_51 () )
V_73 |= V_74 ;
return F_55 ( & V_75 ) ;
}
static int F_56 ( void )
{
struct V_76 * V_77 ;
int V_78 ;
if ( ! ( V_73 & V_74 ) )
return 0 ;
if ( ! F_57 () )
return 0 ;
V_77 = F_58 ( NULL , V_79 ) ;
if ( ! V_77 ) {
if ( ! F_53 () )
return 0 ;
} else {
V_78 = F_59 ( V_77 , 0 ) ;
if ( V_78 < 0 && ! F_53 () ) {
if ( V_78 == - V_80 )
return V_78 ;
return 0 ;
}
if ( V_78 >= 0 )
V_81 . V_82 = V_78 ;
}
F_23 () ;
return F_60 ( & V_81 ) ;
}
static void T_7 F_61 ( void )
{
F_62 ( & V_75 ) ;
}
