static T_1 F_1 ( T_2 V_1 , T_3 V_2 )
{
return F_2 ( V_3 + V_1 + V_2 ) ;
}
static void F_3 ( T_1 V_4 , T_2 V_1 , T_3 V_2 )
{
F_4 ( V_4 , V_3 + V_1 + V_2 ) ;
}
static T_1 F_5 ( T_1 V_5 , T_1 V_6 , T_2 V_1 , T_2 V_2 )
{
T_1 V_7 ;
V_7 = F_1 ( V_1 , V_2 ) ;
V_7 &= ~ V_5 ;
V_7 |= V_6 ;
F_3 ( V_7 , V_1 , V_2 ) ;
return V_7 ;
}
static T_1 F_6 ( T_4 V_8 )
{
struct V_9 * V_10 = & V_9 [ V_8 ] ;
T_1 V_11 ;
V_11 = F_7 ( V_12 ,
V_13 ,
V_10 -> V_14 ) ;
return V_11 & V_10 -> V_15 ;
}
static void F_8 ( T_4 V_8 )
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
static void F_16 ( unsigned long * V_21 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_23 . V_24 ; V_22 ++ )
V_21 [ V_22 ] = F_15 ( V_23 . V_5 +
V_22 * 4 , V_23 . V_25 + V_22 * 4 ) ;
}
static void F_17 ( void )
{
F_1 ( V_13 ,
V_26 ) ;
}
static void F_18 ( T_1 * V_27 )
{
int V_22 ;
T_3 V_2 ;
for ( V_22 = 0 ; V_22 < V_23 . V_24 ; V_22 ++ ) {
V_2 = V_23 . V_5 + V_22 * 4 ;
V_27 [ V_22 ] =
F_1 ( V_13 ,
V_2 ) ;
F_3 ( 0 , V_13 , V_2 ) ;
}
F_1 ( V_13 ,
V_26 ) ;
}
static void F_19 ( T_1 * V_27 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_23 . V_24 ; V_22 ++ )
F_3 ( V_27 [ V_22 ] ,
V_13 ,
V_23 . V_5 + V_22 * 4 ) ;
}
static void F_20 ( void )
{
int V_22 = 0 ;
T_5 V_1 = F_11 () ;
if ( V_1 == V_17 )
return;
F_5 ( V_28 ,
V_28 ,
V_1 ,
V_23 . V_29 ) ;
F_21 (
( ( ( F_1 ( V_1 ,
V_23 . V_29 ) &
V_30 ) >>
V_31 ) == 1 ) ,
V_32 , V_22 ) ;
if ( V_22 == V_32 )
F_22 ( L_1 ) ;
F_5 ( V_28 , 0x0 ,
V_1 ,
V_23 . V_29 ) ;
F_21 (
( ( ( F_1 ( V_1 ,
V_23 . V_29 ) &
V_30 ) >>
V_31 ) == 0 ) ,
V_32 , V_22 ) ;
if ( V_22 == V_32 )
F_22 ( L_2 ) ;
return;
}
static void T_6 F_23 ( void )
{
T_5 V_1 = F_11 () ;
if ( V_1 == V_17 )
return;
F_5 ( V_33 ,
V_33 ,
V_1 ,
V_23 . V_29 ) ;
}
static T_1 F_24 ( void )
{
struct V_34 * V_35 ;
T_1 V_36 = 0 ;
T_1 V_7 ;
T_5 V_1 = F_11 () ;
if ( V_1 == V_17 )
return 0 ;
V_7 = F_1 ( V_1 ,
V_37 ) ;
V_35 = V_38 ;
while ( V_35 -> V_39 >= 0 && V_35 -> V_40 >= 0 ) {
if ( V_7 & ( 1 << V_35 -> V_39 ) )
V_36 |= 1 << V_35 -> V_40 ;
V_35 ++ ;
}
return V_36 ;
}
static bool F_25 ( T_4 V_41 , T_2 V_1 , T_3 V_42 )
{
return ( F_7 ( V_41 , V_1 , V_42 ) ) ? 1 : 0 ;
}
static void F_26 ( T_4 V_41 , T_2 V_1 ,
T_3 V_42 )
{
F_9 ( 0xffffffff , V_41 , V_1 , V_42 ) ;
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
T_1 V_7 ;
V_7 = F_7 ( V_44 -> V_48 , V_44 -> V_49 ,
V_50 ) ;
V_7 &= V_46 ;
V_7 >>= V_47 ;
return V_7 ;
}
static int F_29 ( struct V_43 * V_44 )
{
T_1 V_7 ;
V_7 = F_7 ( V_44 -> V_48 , V_44 -> V_49 ,
V_51 ) ;
V_7 &= V_52 ;
V_7 >>= V_53 ;
return V_7 ;
}
static int F_30 ( struct V_43 * V_44 )
{
T_1 V_7 ;
V_7 = F_7 ( V_44 -> V_48 , V_44 -> V_49 ,
V_51 ) ;
V_7 &= V_54 ;
V_7 >>= V_55 ;
return V_7 ;
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
T_1 V_7 ;
V_7 = V_45 << F_34 ( V_58 ) ;
F_14 ( V_58 , V_7 ,
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
T_1 V_7 ;
V_7 = F_7 ( V_44 -> V_48 , V_44 -> V_49 ,
V_51 ) ;
V_7 &= V_61 ;
V_7 >>= V_62 ;
return V_7 ;
}
static int F_40 ( struct V_43 * V_44 )
{
T_1 V_7 ;
V_7 = F_7 ( V_44 -> V_48 , V_44 -> V_49 ,
V_50 ) ;
V_7 &= V_58 ;
V_7 >>= V_63 ;
return V_7 ;
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
T_1 V_60 , V_7 ;
V_60 = F_43 ( V_59 ) ;
V_7 = F_7 ( V_44 -> V_48 , V_44 -> V_49 ,
V_51 ) ;
V_7 &= V_60 ;
V_7 >>= F_34 ( V_60 ) ;
return V_7 ;
}
static int F_44 ( struct V_43 * V_44 , T_4 V_59 )
{
T_1 V_60 , V_7 ;
V_60 = F_38 ( V_59 ) ;
V_7 = F_7 ( V_44 -> V_48 , V_44 -> V_49 ,
V_50 ) ;
V_7 &= V_60 ;
V_7 >>= F_34 ( V_60 ) ;
return V_7 ;
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
while ( ( F_7 ( V_44 -> V_48 ,
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
static int F_50 ( void )
{
if ( V_72 & V_73 )
return 1 ;
return 0 ;
}
int T_6 F_51 ( const struct V_74 * V_75 )
{
F_52 () ;
V_76 = V_75 ;
if ( V_75 -> V_77 & V_78 )
V_72 |= V_78 ;
if ( V_75 -> V_77 & V_73 )
V_72 |= V_73 ;
F_53 ( V_75 -> V_79 ) ;
if ( F_54 ( V_75 -> V_80 , L_5 ) ) {
V_23 . V_81 = 1 ;
V_23 . V_24 = 1 ;
V_23 . V_29 = V_82 ;
V_23 . V_25 = V_83 ;
V_23 . V_5 = V_84 ;
}
return F_55 ( & V_85 ) ;
}
static int F_56 ( void )
{
int V_86 ;
if ( ! ( V_72 & V_78 ) )
return 0 ;
if ( ! F_57 () )
return 0 ;
V_86 = F_58 ( V_76 -> V_80 , 0 ) ;
if ( V_86 < 0 && ! ( V_76 -> V_77 & V_87 ) ) {
if ( V_86 == - V_88 )
return V_86 ;
return 0 ;
}
if ( V_86 >= 0 ) {
V_23 . V_89 = V_86 ;
V_23 . V_90 = NULL ;
}
F_23 () ;
return F_59 ( & V_23 ) ;
}
static void T_7 F_60 ( void )
{
F_61 ( & V_85 ) ;
}
