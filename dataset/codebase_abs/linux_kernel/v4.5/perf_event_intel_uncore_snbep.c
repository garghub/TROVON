static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
int V_5 = F_2 ( V_2 ) ;
T_1 V_6 = 0 ;
if ( ! F_3 ( V_4 , V_5 , & V_6 ) ) {
V_6 |= V_7 ;
F_4 ( V_4 , V_5 , V_6 ) ;
}
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
int V_5 = F_2 ( V_2 ) ;
T_1 V_6 = 0 ;
if ( ! F_3 ( V_4 , V_5 , & V_6 ) ) {
V_6 &= ~ V_7 ;
F_4 ( V_4 , V_5 , V_6 ) ;
}
}
static void F_6 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
struct V_10 * V_11 = & V_9 -> V_12 ;
F_4 ( V_4 , V_11 -> V_13 , V_11 -> V_6 | V_14 ) ;
}
static void F_7 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
struct V_10 * V_11 = & V_9 -> V_12 ;
F_4 ( V_4 , V_11 -> V_13 , V_11 -> V_6 ) ;
}
static T_2 F_8 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
struct V_10 * V_11 = & V_9 -> V_12 ;
T_2 V_15 = 0 ;
F_3 ( V_4 , V_11 -> V_16 , ( T_1 * ) & V_15 ) ;
F_3 ( V_4 , V_11 -> V_16 + 4 , ( T_1 * ) & V_15 + 1 ) ;
return V_15 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
int V_5 = F_2 ( V_2 ) ;
F_4 ( V_4 , V_5 , V_17 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
T_2 V_6 ;
unsigned V_18 ;
V_18 = F_11 ( V_2 ) ;
if ( V_18 ) {
F_12 ( V_18 , V_6 ) ;
V_6 |= V_7 ;
F_13 ( V_18 , V_6 ) ;
}
}
static void F_14 ( struct V_1 * V_2 )
{
T_2 V_6 ;
unsigned V_18 ;
V_18 = F_11 ( V_2 ) ;
if ( V_18 ) {
F_12 ( V_18 , V_6 ) ;
V_6 &= ~ V_7 ;
F_13 ( V_18 , V_6 ) ;
}
}
static void F_15 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_12 ;
struct V_19 * V_20 = & V_11 -> V_21 ;
if ( V_20 -> V_22 != V_23 )
F_13 ( V_20 -> V_24 , F_16 ( V_2 , 0 ) ) ;
F_13 ( V_11 -> V_13 , V_11 -> V_6 | V_14 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_12 ;
F_13 ( V_11 -> V_13 , V_11 -> V_6 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
unsigned V_18 = F_11 ( V_2 ) ;
if ( V_18 )
F_13 ( V_18 , V_17 ) ;
}
static void F_19 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_19 * V_20 = & V_9 -> V_12 . V_21 ;
struct V_25 * V_26 = & V_2 -> V_27 [ 0 ] ;
int V_28 ;
if ( F_20 ( V_2 ) )
return;
for ( V_28 = 0 ; V_28 < 5 ; V_28 ++ ) {
if ( V_20 -> V_29 & ( 0x1 << V_28 ) )
F_21 ( 1 << ( V_28 * 6 ) , & V_26 -> V_30 ) ;
}
V_20 -> V_29 = 0 ;
}
static struct V_31 *
F_22 ( struct V_1 * V_2 , struct V_8 * V_9 ,
T_2 (* F_23)( int V_32 ) )
{
struct V_19 * V_20 = & V_9 -> V_12 . V_21 ;
struct V_25 * V_26 = & V_2 -> V_27 [ 0 ] ;
int V_28 , V_29 = 0 ;
unsigned long V_33 ;
T_2 V_34 ;
if ( V_20 -> V_22 == V_23 )
return NULL ;
F_24 ( & V_26 -> V_35 , V_33 ) ;
for ( V_28 = 0 ; V_28 < 5 ; V_28 ++ ) {
if ( ! ( V_20 -> V_22 & ( 0x1 << V_28 ) ) )
continue;
if ( ! F_20 ( V_2 ) && ( V_20 -> V_29 & ( 0x1 << V_28 ) ) )
continue;
V_34 = F_23 ( 0x1 << V_28 ) ;
if ( ! F_25 ( F_26 ( & V_26 -> V_30 ) , V_28 , 6 ) ||
! ( ( V_20 -> V_6 ^ V_26 -> V_6 ) & V_34 ) ) {
F_27 ( 1 << ( V_28 * 6 ) , & V_26 -> V_30 ) ;
V_26 -> V_6 &= ~ V_34 ;
V_26 -> V_6 |= V_20 -> V_6 & V_34 ;
V_29 |= ( 0x1 << V_28 ) ;
} else {
break;
}
}
F_28 ( & V_26 -> V_35 , V_33 ) ;
if ( V_28 < 5 )
goto V_36;
if ( ! F_20 ( V_2 ) )
V_20 -> V_29 |= V_29 ;
return NULL ;
V_36:
for (; V_28 >= 0 ; V_28 -- ) {
if ( V_29 & ( 0x1 << V_28 ) )
F_21 ( 1 << ( V_28 * 6 ) , & V_26 -> V_30 ) ;
}
return & V_37 ;
}
static T_2 F_29 ( int V_32 )
{
T_2 V_34 = 0 ;
if ( V_32 & 0x1 )
V_34 |= V_38 ;
if ( V_32 & 0x2 )
V_34 |= V_39 ;
if ( V_32 & 0x4 )
V_34 |= V_40 ;
if ( V_32 & 0x8 )
V_34 |= V_41 ;
return V_34 ;
}
static struct V_31 *
F_30 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
return F_22 ( V_2 , V_9 , F_29 ) ;
}
static int F_31 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_19 * V_20 = & V_9 -> V_12 . V_21 ;
struct V_21 * V_26 ;
int V_22 = 0 ;
for ( V_26 = V_42 ; V_26 -> V_18 ; V_26 ++ ) {
if ( V_26 -> V_9 != ( V_9 -> V_12 . V_6 & V_26 -> V_43 ) )
continue;
V_22 |= V_26 -> V_22 ;
}
if ( V_22 ) {
V_20 -> V_24 = V_44 +
V_45 * V_2 -> V_46 -> V_47 ;
V_20 -> V_6 = V_9 -> V_48 . V_49 & F_29 ( V_22 ) ;
V_20 -> V_22 = V_22 ;
}
return 0 ;
}
static T_2 F_32 ( struct V_8 * V_9 , int V_50 , bool V_51 )
{
struct V_10 * V_11 = & V_9 -> V_12 ;
struct V_19 * V_20 = & V_11 -> V_21 ;
T_2 V_6 = V_20 -> V_6 ;
if ( V_50 > V_20 -> V_22 )
V_6 <<= 8 * ( V_50 - V_20 -> V_22 ) ;
else
V_6 >>= 8 * ( V_20 -> V_22 - V_50 ) ;
if ( V_51 ) {
V_11 -> V_6 += V_50 - V_20 -> V_22 ;
V_20 -> V_6 = V_6 ;
V_20 -> V_22 = V_50 ;
}
return V_6 ;
}
static struct V_31 *
F_33 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_19 * V_20 = & V_9 -> V_12 . V_21 ;
struct V_25 * V_26 = & V_2 -> V_27 [ 0 ] ;
unsigned long V_33 ;
int V_22 = V_20 -> V_22 ;
T_2 V_34 , V_49 = V_20 -> V_6 ;
bool V_52 = false ;
if ( V_20 -> V_22 == V_23 ||
( ! F_20 ( V_2 ) && V_20 -> V_29 ) )
return NULL ;
V_53:
V_34 = 0xffULL << ( V_22 * 8 ) ;
F_24 ( & V_26 -> V_35 , V_33 ) ;
if ( ! F_25 ( F_26 ( & V_26 -> V_30 ) , V_22 , 8 ) ||
! ( ( V_49 ^ V_26 -> V_6 ) & V_34 ) ) {
F_27 ( 1 << ( V_22 * 8 ) , & V_26 -> V_30 ) ;
V_26 -> V_6 &= ~ V_34 ;
V_26 -> V_6 |= V_49 & V_34 ;
V_52 = true ;
}
F_28 ( & V_26 -> V_35 , V_33 ) ;
if ( ! V_52 ) {
V_22 = ( V_22 + 1 ) % 4 ;
if ( V_22 != V_20 -> V_22 ) {
V_49 = F_32 ( V_9 , V_22 , false ) ;
goto V_53;
}
return & V_37 ;
}
if ( ! F_20 ( V_2 ) ) {
if ( V_22 != V_20 -> V_22 )
F_32 ( V_9 , V_22 , true ) ;
V_20 -> V_29 = 1 ;
}
return NULL ;
}
static void F_34 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_19 * V_20 = & V_9 -> V_12 . V_21 ;
struct V_25 * V_26 = & V_2 -> V_27 [ 0 ] ;
if ( F_20 ( V_2 ) || ! V_20 -> V_29 )
return;
F_21 ( 1 << ( V_20 -> V_22 * 8 ) , & V_26 -> V_30 ) ;
V_20 -> V_29 = 0 ;
}
static int F_35 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_12 ;
struct V_19 * V_20 = & V_11 -> V_21 ;
int V_54 = V_11 -> V_6 & V_55 ;
if ( V_54 >= 0xb && V_54 <= 0xe ) {
V_20 -> V_24 = V_56 ;
V_20 -> V_22 = V_54 - 0xb ;
V_20 -> V_6 = V_9 -> V_48 . V_49 & ( 0xff << ( V_20 -> V_22 * 8 ) ) ;
}
return 0 ;
}
void F_36 ( void )
{
if ( V_57 . V_58 > V_59 . V_60 )
V_57 . V_58 = V_59 . V_60 ;
V_61 = V_62 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_12 ;
struct V_19 * V_20 = & V_11 -> V_21 ;
struct V_19 * V_63 = & V_11 -> V_64 ;
if ( ( V_11 -> V_6 & V_55 ) == 0x38 ) {
V_20 -> V_22 = 0 ;
V_20 -> V_24 = V_65 ;
V_20 -> V_6 = V_9 -> V_48 . V_49 ;
V_63 -> V_24 = V_66 ;
V_63 -> V_6 = V_9 -> V_48 . V_67 ;
}
return 0 ;
}
static void F_38 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
struct V_10 * V_11 = & V_9 -> V_12 ;
struct V_19 * V_20 = & V_11 -> V_21 ;
struct V_19 * V_63 = & V_11 -> V_64 ;
if ( V_20 -> V_22 != V_23 ) {
int V_22 = V_2 -> V_46 -> V_47 + V_68 ;
struct V_3 * V_69 = V_70 [ V_2 -> V_71 ] [ V_22 ] ;
if ( V_69 ) {
F_4 ( V_69 , V_20 -> V_24 ,
( T_1 ) V_20 -> V_6 ) ;
F_4 ( V_69 , V_20 -> V_24 + 4 ,
( T_1 ) ( V_20 -> V_6 >> 32 ) ) ;
F_4 ( V_69 , V_63 -> V_24 ,
( T_1 ) V_63 -> V_6 ) ;
F_4 ( V_69 , V_63 -> V_24 + 4 ,
( T_1 ) ( V_63 -> V_6 >> 32 ) ) ;
}
}
F_4 ( V_4 , V_11 -> V_13 , V_11 -> V_6 | V_14 ) ;
}
static int F_39 ( int V_72 )
{
struct V_3 * V_73 = NULL ;
int V_28 , V_74 , V_75 , V_76 ;
struct V_77 * V_78 ;
int V_79 = 0 ;
T_1 V_6 = 0 ;
while ( 1 ) {
V_73 = F_40 ( V_80 , V_72 , V_73 ) ;
if ( ! V_73 )
break;
V_74 = V_73 -> V_74 -> V_81 ;
V_79 = F_3 ( V_73 , 0x40 , & V_6 ) ;
if ( V_79 )
break;
V_75 = V_6 ;
V_79 = F_3 ( V_73 , 0x54 , & V_6 ) ;
if ( V_79 )
break;
V_76 = F_41 ( V_73 -> V_74 ) ;
F_42 ( & V_82 ) ;
V_78 = F_43 ( V_76 ) ;
if ( ! V_78 ) {
F_44 ( & V_82 ) ;
V_79 = - V_83 ;
break;
}
for ( V_28 = 0 ; V_28 < 8 ; V_28 ++ ) {
if ( V_75 == ( ( V_6 >> ( 3 * V_28 ) ) & 0x7 ) ) {
V_78 -> V_84 [ V_74 ] = V_28 ;
break;
}
}
F_44 ( & V_82 ) ;
}
if ( ! V_79 ) {
F_42 ( & V_82 ) ;
F_45 (map, &pci2phy_map_head, list) {
V_28 = - 1 ;
for ( V_74 = 255 ; V_74 >= 0 ; V_74 -- ) {
if ( V_78 -> V_84 [ V_74 ] >= 0 )
V_28 = V_78 -> V_84 [ V_74 ] ;
else
V_78 -> V_84 [ V_74 ] = V_28 ;
}
}
F_44 ( & V_82 ) ;
}
F_46 ( V_73 ) ;
return V_79 ? F_47 ( V_79 ) : 0 ;
}
int F_48 ( void )
{
int V_85 = F_39 ( 0x3ce0 ) ;
if ( V_85 )
return V_85 ;
V_86 = V_87 ;
V_88 = & V_89 ;
return 0 ;
}
static void F_49 ( struct V_1 * V_2 )
{
unsigned V_18 = F_11 ( V_2 ) ;
if ( V_18 )
F_13 ( V_18 , V_90 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
F_4 ( V_4 , V_91 , V_90 ) ;
}
static T_2 F_51 ( int V_32 )
{
T_2 V_34 = 0 ;
if ( V_32 & 0x1 )
V_34 |= V_92 ;
if ( V_32 & 0x2 )
V_34 |= V_93 ;
if ( V_32 & 0x4 )
V_34 |= V_94 ;
if ( V_32 & 0x8 )
V_34 |= V_95 ;
if ( V_32 & 0x10 ) {
V_34 |= V_96 ;
V_34 |= V_97 ;
V_34 |= V_98 ;
V_34 |= V_99 ;
}
return V_34 ;
}
static struct V_31 *
F_52 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
return F_22 ( V_2 , V_9 , F_51 ) ;
}
static int F_53 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_19 * V_20 = & V_9 -> V_12 . V_21 ;
struct V_21 * V_26 ;
int V_22 = 0 ;
for ( V_26 = V_100 ; V_26 -> V_18 ; V_26 ++ ) {
if ( V_26 -> V_9 != ( V_9 -> V_12 . V_6 & V_26 -> V_43 ) )
continue;
V_22 |= V_26 -> V_22 ;
}
if ( V_22 ) {
V_20 -> V_24 = V_44 +
V_45 * V_2 -> V_46 -> V_47 ;
V_20 -> V_6 = V_9 -> V_48 . V_49 & F_51 ( V_22 ) ;
V_20 -> V_22 = V_22 ;
}
return 0 ;
}
static void F_54 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_12 ;
struct V_19 * V_20 = & V_11 -> V_21 ;
if ( V_20 -> V_22 != V_23 ) {
T_2 V_101 = F_16 ( V_2 , 0 ) ;
F_13 ( V_20 -> V_24 , V_101 & 0xffffffff ) ;
F_13 ( V_20 -> V_24 + 6 , V_101 >> 32 ) ;
}
F_13 ( V_11 -> V_13 , V_11 -> V_6 | V_14 ) ;
}
void F_55 ( void )
{
if ( V_102 . V_58 > V_59 . V_60 )
V_102 . V_58 = V_59 . V_60 ;
V_61 = V_103 ;
}
static void F_56 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
struct V_10 * V_11 = & V_9 -> V_12 ;
F_4 ( V_4 , V_104 [ V_11 -> V_22 ] ,
V_11 -> V_6 | V_14 ) ;
}
static void F_57 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
struct V_10 * V_11 = & V_9 -> V_12 ;
F_4 ( V_4 , V_104 [ V_11 -> V_22 ] , V_11 -> V_6 ) ;
}
static T_2 F_58 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
struct V_10 * V_11 = & V_9 -> V_12 ;
T_2 V_15 = 0 ;
F_3 ( V_4 , V_105 [ V_11 -> V_22 ] , ( T_1 * ) & V_15 ) ;
F_3 ( V_4 , V_105 [ V_11 -> V_22 ] + 4 , ( T_1 * ) & V_15 + 1 ) ;
return V_15 ;
}
int F_59 ( void )
{
int V_85 = F_39 ( 0x0e1e ) ;
if ( V_85 )
return V_85 ;
V_86 = V_106 ;
V_88 = & V_107 ;
return 0 ;
}
static T_2 F_60 ( int V_32 )
{
T_2 V_34 = 0 ;
if ( V_32 & 0x1 )
V_34 |= V_108 ;
if ( V_32 & 0x2 )
V_34 |= V_109 ;
if ( V_32 & 0x4 )
V_34 |= V_110 ;
return V_34 ;
}
static struct V_31 *
F_61 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
return F_22 ( V_2 , V_9 , F_60 ) ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_19 * V_20 = & V_9 -> V_12 . V_21 ;
struct V_21 * V_26 ;
int V_22 = 0 ;
for ( V_26 = V_111 ; V_26 -> V_18 ; V_26 ++ ) {
if ( V_26 -> V_9 != ( V_9 -> V_12 . V_6 & V_26 -> V_43 ) )
continue;
V_22 |= V_26 -> V_22 ;
}
if ( V_22 ) {
V_20 -> V_24 = V_112 +
V_113 * V_2 -> V_46 -> V_47 ;
V_20 -> V_6 = V_9 -> V_48 . V_49 & F_60 ( V_22 ) ;
V_20 -> V_22 = V_22 ;
}
return 0 ;
}
void F_63 ( void )
{
V_61 = V_114 ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
int V_5 = F_2 ( V_2 ) ;
F_4 ( V_4 , V_5 , 0 ) ;
}
static void F_65 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
struct V_10 * V_11 = & V_9 -> V_12 ;
if ( ( V_9 -> V_48 . V_6 & V_55 )
== V_115 )
F_4 ( V_4 , V_11 -> V_13 ,
V_11 -> V_6 | V_116 ) ;
else
F_4 ( V_4 , V_11 -> V_13 ,
V_11 -> V_6 | V_14 ) ;
}
int F_66 ( void )
{
int V_85 ;
V_85 = F_67 ( 0x7814 ) ;
if ( V_85 )
return V_85 ;
V_85 = F_67 ( 0x7817 ) ;
if ( V_85 )
return V_85 ;
V_86 = V_117 ;
V_88 = & V_118 ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_19 * V_20 = & V_9 -> V_12 . V_21 ;
V_20 -> V_24 = V_119 ;
V_20 -> V_6 = V_9 -> V_48 . V_49 & V_120 ;
V_20 -> V_22 = 0 ;
return 0 ;
}
static T_2 F_69 ( int V_32 )
{
T_2 V_34 = 0 ;
if ( V_32 & 0x1 )
V_34 |= V_121 ;
if ( V_32 & 0x2 )
V_34 |= V_122 ;
if ( V_32 & 0x4 )
V_34 |= V_123 ;
if ( V_32 & 0x8 )
V_34 |= V_124 ;
if ( V_32 & 0x10 ) {
V_34 |= V_125 ;
V_34 |= V_126 ;
V_34 |= V_127 ;
V_34 |= V_128 ;
}
return V_34 ;
}
static struct V_31 *
F_70 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
return F_22 ( V_2 , V_9 , F_69 ) ;
}
static int F_71 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_19 * V_20 = & V_9 -> V_12 . V_21 ;
struct V_21 * V_26 ;
int V_22 = 0 ;
for ( V_26 = V_129 ; V_26 -> V_18 ; V_26 ++ ) {
if ( V_26 -> V_9 != ( V_9 -> V_12 . V_6 & V_26 -> V_43 ) )
continue;
V_22 |= V_26 -> V_22 ;
}
if ( V_22 ) {
V_20 -> V_24 = V_112 +
V_130 * V_2 -> V_46 -> V_47 ;
V_20 -> V_6 = V_9 -> V_48 . V_49 & F_69 ( V_22 ) ;
V_20 -> V_22 = V_22 ;
}
return 0 ;
}
static void F_72 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_12 ;
struct V_19 * V_20 = & V_11 -> V_21 ;
if ( V_20 -> V_22 != V_23 ) {
T_2 V_101 = F_16 ( V_2 , 0 ) ;
F_13 ( V_20 -> V_24 , V_101 & 0xffffffff ) ;
F_13 ( V_20 -> V_24 + 1 , V_101 >> 32 ) ;
}
F_13 ( V_11 -> V_13 , V_11 -> V_6 | V_14 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
unsigned V_18 = F_11 ( V_2 ) ;
if ( V_18 ) {
T_2 V_131 = V_17 ;
T_2 V_33 = 0 ;
int V_28 ;
F_74 (i, (unsigned long *)&init, 64 ) {
V_33 |= ( 1ULL << V_28 ) ;
F_13 ( V_18 , V_33 ) ;
}
}
}
static int F_75 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_12 ;
struct V_19 * V_20 = & V_11 -> V_21 ;
int V_54 = V_11 -> V_6 & V_55 ;
if ( V_54 >= 0xb && V_54 <= 0xe ) {
V_20 -> V_24 = V_132 ;
V_20 -> V_22 = V_54 - 0xb ;
V_20 -> V_6 = V_9 -> V_48 . V_49 & ( 0xff << V_20 -> V_22 ) ;
}
return 0 ;
}
void F_76 ( void )
{
if ( V_133 . V_58 > V_59 . V_60 )
V_133 . V_58 = V_59 . V_60 ;
if ( V_70 [ 0 ] [ V_134 ] ) {
T_1 V_135 ;
F_3 ( V_70 [ 0 ] [ V_134 ] ,
0x94 , & V_135 ) ;
if ( ( ( V_135 >> 6 ) & 0x3 ) == 0 )
V_136 . V_58 = 2 ;
}
V_61 = V_137 ;
}
static T_2 F_77 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
struct V_10 * V_11 = & V_9 -> V_12 ;
T_2 V_15 = 0 ;
F_3 ( V_4 , V_138 [ V_11 -> V_22 ] , ( T_1 * ) & V_15 ) ;
F_3 ( V_4 , V_138 [ V_11 -> V_22 ] + 4 , ( T_1 * ) & V_15 + 1 ) ;
return V_15 ;
}
int F_78 ( void )
{
int V_85 = F_39 ( 0x2f1e ) ;
if ( V_85 )
return V_85 ;
V_86 = V_139 ;
V_88 = & V_140 ;
return 0 ;
}
void F_79 ( void )
{
if ( V_141 . V_58 > V_59 . V_60 )
V_141 . V_58 = V_59 . V_60 ;
V_61 = V_142 ;
}
int F_80 ( void )
{
int V_85 = F_39 ( 0x6f1e ) ;
if ( V_85 )
return V_85 ;
V_86 = V_143 ;
V_88 = & V_144 ;
return 0 ;
}
