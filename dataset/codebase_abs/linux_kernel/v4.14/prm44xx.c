static T_1 F_1 ( T_2 V_1 , T_3 V_2 )
{
return F_2 ( V_3 . V_4 + V_1 + V_2 ) ;
}
static void F_3 ( T_1 V_5 , T_2 V_1 , T_3 V_2 )
{
F_4 ( V_5 , V_3 . V_4 + V_1 + V_2 ) ;
}
static T_1 F_5 ( T_1 V_6 , T_1 V_7 , T_2 V_1 , T_2 V_2 )
{
T_1 V_8 ;
V_8 = F_1 ( V_1 , V_2 ) ;
V_8 &= ~ V_6 ;
V_8 |= V_7 ;
F_3 ( V_8 , V_1 , V_2 ) ;
return V_8 ;
}
static T_1 F_6 ( T_4 V_9 )
{
struct V_10 * V_11 = & V_10 [ V_9 ] ;
T_1 V_12 ;
V_12 = F_7 ( V_13 ,
V_14 ,
V_11 -> V_15 ) ;
return V_12 & V_11 -> V_16 ;
}
static void F_8 ( T_4 V_9 )
{
struct V_10 * V_11 = & V_10 [ V_9 ] ;
F_9 ( V_11 -> V_16 ,
V_13 ,
V_14 ,
V_11 -> V_15 ) ;
}
T_1 F_10 ( T_4 V_17 )
{
T_5 V_1 = F_11 () ;
if ( V_1 == V_18 )
return 0 ;
return F_7 ( V_13 ,
V_1 , V_17 ) ;
}
void F_12 ( T_1 V_5 , T_4 V_17 )
{
T_5 V_1 = F_11 () ;
if ( V_1 == V_18 )
return;
F_9 ( V_5 , V_13 ,
V_1 , V_17 ) ;
}
T_1 F_13 ( T_1 V_6 , T_1 V_7 , T_4 V_17 )
{
T_5 V_1 = F_11 () ;
if ( V_1 == V_18 )
return 0 ;
return F_14 ( V_6 , V_7 ,
V_13 ,
V_1 ,
V_17 ) ;
}
static inline T_1 F_15 ( T_3 V_19 , T_3 V_20 )
{
T_1 V_6 , V_21 ;
V_6 = F_1 ( V_14 ,
V_19 ) ;
V_21 = F_1 ( V_14 , V_20 ) ;
return V_6 & V_21 ;
}
static void F_16 ( unsigned long * V_22 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_24 . V_25 ; V_23 ++ )
V_22 [ V_23 ] = F_15 ( V_24 . V_6 +
V_23 * 4 , V_24 . V_26 + V_23 * 4 ) ;
}
static void F_17 ( void )
{
F_1 ( V_14 ,
V_27 ) ;
}
static void F_18 ( T_1 * V_28 )
{
int V_23 ;
T_3 V_2 ;
for ( V_23 = 0 ; V_23 < V_24 . V_25 ; V_23 ++ ) {
V_2 = V_24 . V_6 + V_23 * 4 ;
V_28 [ V_23 ] =
F_1 ( V_14 ,
V_2 ) ;
F_3 ( 0 , V_14 , V_2 ) ;
}
F_1 ( V_14 ,
V_27 ) ;
}
static void F_19 ( T_1 * V_28 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_24 . V_25 ; V_23 ++ )
F_3 ( V_28 [ V_23 ] ,
V_14 ,
V_24 . V_6 + V_23 * 4 ) ;
}
static void F_20 ( void )
{
int V_23 = 0 ;
T_5 V_1 = F_11 () ;
if ( V_1 == V_18 )
return;
F_5 ( V_29 ,
V_29 ,
V_1 ,
V_24 . V_30 ) ;
F_21 (
( ( ( F_1 ( V_1 ,
V_24 . V_30 ) &
V_31 ) >>
V_32 ) == 1 ) ,
V_33 , V_23 ) ;
if ( V_23 == V_33 )
F_22 ( L_1 ) ;
F_5 ( V_29 , 0x0 ,
V_1 ,
V_24 . V_30 ) ;
F_21 (
( ( ( F_1 ( V_1 ,
V_24 . V_30 ) &
V_31 ) >>
V_32 ) == 0 ) ,
V_33 , V_23 ) ;
if ( V_23 == V_33 )
F_22 ( L_2 ) ;
return;
}
static void T_6 F_23 ( void )
{
T_5 V_1 = F_11 () ;
if ( V_1 == V_18 )
return;
F_5 ( V_34 ,
V_34 ,
V_1 ,
V_24 . V_30 ) ;
}
static T_1 F_24 ( void )
{
struct V_35 * V_36 ;
T_1 V_37 = 0 ;
T_1 V_8 ;
T_5 V_1 = F_11 () ;
if ( V_1 == V_18 )
return 0 ;
V_8 = F_1 ( V_1 ,
V_38 ) ;
V_36 = V_39 ;
while ( V_36 -> V_40 >= 0 && V_36 -> V_41 >= 0 ) {
if ( V_8 & ( 1 << V_36 -> V_40 ) )
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
T_1 V_8 ;
V_8 = F_7 ( V_45 -> V_49 , V_45 -> V_50 ,
V_51 ) ;
V_8 &= V_47 ;
V_8 >>= V_48 ;
return V_8 ;
}
static int F_29 ( struct V_44 * V_45 )
{
T_1 V_8 ;
V_8 = F_7 ( V_45 -> V_49 , V_45 -> V_50 ,
V_52 ) ;
V_8 &= V_53 ;
V_8 >>= V_54 ;
return V_8 ;
}
static int F_30 ( struct V_44 * V_45 )
{
T_1 V_8 ;
V_8 = F_7 ( V_45 -> V_49 , V_45 -> V_50 ,
V_52 ) ;
V_8 &= V_55 ;
V_8 >>= V_56 ;
return V_8 ;
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
T_1 V_8 ;
V_8 = V_46 << F_34 ( V_59 ) ;
F_14 ( V_59 , V_8 ,
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
T_1 V_8 ;
V_8 = F_7 ( V_45 -> V_49 , V_45 -> V_50 ,
V_52 ) ;
V_8 &= V_62 ;
V_8 >>= V_63 ;
return V_8 ;
}
static int F_40 ( struct V_44 * V_45 )
{
T_1 V_8 ;
V_8 = F_7 ( V_45 -> V_49 , V_45 -> V_50 ,
V_51 ) ;
V_8 &= V_59 ;
V_8 >>= V_64 ;
return V_8 ;
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
T_1 V_61 , V_8 ;
V_61 = F_43 ( V_60 ) ;
V_8 = F_7 ( V_45 -> V_49 , V_45 -> V_50 ,
V_52 ) ;
V_8 &= V_61 ;
V_8 >>= F_34 ( V_61 ) ;
return V_8 ;
}
static int F_44 ( struct V_44 * V_45 , T_4 V_60 )
{
T_1 V_61 , V_8 ;
V_61 = F_38 ( V_60 ) ;
V_8 = F_7 ( V_45 -> V_49 , V_45 -> V_50 ,
V_51 ) ;
V_8 &= V_61 ;
V_8 >>= F_34 ( V_61 ) ;
return V_8 ;
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
if ( V_73 & V_74 )
return 1 ;
return 0 ;
}
int T_6 F_51 ( const struct V_75 * V_76 )
{
F_52 () ;
V_77 = V_76 ;
if ( V_76 -> V_78 & V_79 )
V_73 |= V_79 ;
if ( V_76 -> V_78 & V_74 )
V_73 |= V_74 ;
F_53 ( V_76 -> V_80 ) ;
if ( F_54 ( V_76 -> V_81 , L_5 ) ) {
V_24 . V_82 = 1 ;
V_24 . V_25 = 1 ;
V_24 . V_30 = V_83 ;
V_24 . V_26 = V_84 ;
V_24 . V_6 = V_85 ;
}
return F_55 ( & V_86 ) ;
}
static int F_56 ( void )
{
int V_87 ;
if ( ! ( V_73 & V_79 ) )
return 0 ;
V_87 = F_57 ( V_77 -> V_81 , 0 ) ;
if ( V_87 <= 0 && ! ( V_77 -> V_78 & V_88 ) ) {
if ( V_87 == - V_89 )
return V_87 ;
return 0 ;
}
if ( V_87 > 0 ) {
V_24 . V_90 = V_87 ;
V_24 . V_91 = NULL ;
}
F_23 () ;
return F_58 ( & V_24 ) ;
}
static void T_7 F_59 ( void )
{
F_60 ( & V_86 ) ;
}
