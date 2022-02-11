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
F_4 ( V_4 , V_17 , V_18 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
T_2 V_6 ;
unsigned V_19 ;
V_19 = F_11 ( V_2 ) ;
if ( V_19 ) {
F_12 ( V_19 , V_6 ) ;
V_6 |= V_7 ;
F_13 ( V_19 , V_6 ) ;
}
}
static void F_14 ( struct V_1 * V_2 )
{
T_2 V_6 ;
unsigned V_19 ;
V_19 = F_11 ( V_2 ) ;
if ( V_19 ) {
F_12 ( V_19 , V_6 ) ;
V_6 &= ~ V_7 ;
F_13 ( V_19 , V_6 ) ;
}
}
static void F_15 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_12 ;
struct V_20 * V_21 = & V_11 -> V_22 ;
if ( V_21 -> V_23 != V_24 )
F_13 ( V_21 -> V_25 , F_16 ( V_2 , 0 ) ) ;
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
unsigned V_19 = F_11 ( V_2 ) ;
if ( V_19 )
F_13 ( V_19 , V_18 ) ;
}
static void F_19 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_20 * V_21 = & V_9 -> V_12 . V_22 ;
struct V_26 * V_27 = & V_2 -> V_28 [ 0 ] ;
int V_29 ;
if ( F_20 ( V_2 ) )
return;
for ( V_29 = 0 ; V_29 < 5 ; V_29 ++ ) {
if ( V_21 -> V_30 & ( 0x1 << V_29 ) )
F_21 ( 1 << ( V_29 * 6 ) , & V_27 -> V_31 ) ;
}
V_21 -> V_30 = 0 ;
}
static struct V_32 *
F_22 ( struct V_1 * V_2 , struct V_8 * V_9 ,
T_2 (* F_23)( int V_33 ) )
{
struct V_20 * V_21 = & V_9 -> V_12 . V_22 ;
struct V_26 * V_27 = & V_2 -> V_28 [ 0 ] ;
int V_29 , V_30 = 0 ;
unsigned long V_34 ;
T_2 V_35 ;
if ( V_21 -> V_23 == V_24 )
return NULL ;
F_24 ( & V_27 -> V_36 , V_34 ) ;
for ( V_29 = 0 ; V_29 < 5 ; V_29 ++ ) {
if ( ! ( V_21 -> V_23 & ( 0x1 << V_29 ) ) )
continue;
if ( ! F_20 ( V_2 ) && ( V_21 -> V_30 & ( 0x1 << V_29 ) ) )
continue;
V_35 = F_23 ( 0x1 << V_29 ) ;
if ( ! F_25 ( F_26 ( & V_27 -> V_31 ) , V_29 , 6 ) ||
! ( ( V_21 -> V_6 ^ V_27 -> V_6 ) & V_35 ) ) {
F_27 ( 1 << ( V_29 * 6 ) , & V_27 -> V_31 ) ;
V_27 -> V_6 &= ~ V_35 ;
V_27 -> V_6 |= V_21 -> V_6 & V_35 ;
V_30 |= ( 0x1 << V_29 ) ;
} else {
break;
}
}
F_28 ( & V_27 -> V_36 , V_34 ) ;
if ( V_29 < 5 )
goto V_37;
if ( ! F_20 ( V_2 ) )
V_21 -> V_30 |= V_30 ;
return NULL ;
V_37:
for (; V_29 >= 0 ; V_29 -- ) {
if ( V_30 & ( 0x1 << V_29 ) )
F_21 ( 1 << ( V_29 * 6 ) , & V_27 -> V_31 ) ;
}
return & V_38 ;
}
static T_2 F_29 ( int V_33 )
{
T_2 V_35 = 0 ;
if ( V_33 & 0x1 )
V_35 |= V_39 ;
if ( V_33 & 0x2 )
V_35 |= V_40 ;
if ( V_33 & 0x4 )
V_35 |= V_41 ;
if ( V_33 & 0x8 )
V_35 |= V_42 ;
return V_35 ;
}
static struct V_32 *
F_30 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
return F_22 ( V_2 , V_9 , F_29 ) ;
}
static int F_31 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_20 * V_21 = & V_9 -> V_12 . V_22 ;
struct V_22 * V_27 ;
int V_23 = 0 ;
for ( V_27 = V_43 ; V_27 -> V_19 ; V_27 ++ ) {
if ( V_27 -> V_9 != ( V_9 -> V_12 . V_6 & V_27 -> V_44 ) )
continue;
V_23 |= V_27 -> V_23 ;
}
if ( V_23 ) {
V_21 -> V_25 = V_45 +
V_46 * V_2 -> V_47 -> V_48 ;
V_21 -> V_6 = V_9 -> V_49 . V_50 & F_29 ( V_23 ) ;
V_21 -> V_23 = V_23 ;
}
return 0 ;
}
static T_2 F_32 ( struct V_8 * V_9 , int V_51 , bool V_52 )
{
struct V_10 * V_11 = & V_9 -> V_12 ;
struct V_20 * V_21 = & V_11 -> V_22 ;
T_2 V_6 = V_21 -> V_6 ;
if ( V_51 > V_21 -> V_23 )
V_6 <<= 8 * ( V_51 - V_21 -> V_23 ) ;
else
V_6 >>= 8 * ( V_21 -> V_23 - V_51 ) ;
if ( V_52 ) {
V_11 -> V_6 += V_51 - V_21 -> V_23 ;
V_21 -> V_6 = V_6 ;
V_21 -> V_23 = V_51 ;
}
return V_6 ;
}
static struct V_32 *
F_33 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_20 * V_21 = & V_9 -> V_12 . V_22 ;
struct V_26 * V_27 = & V_2 -> V_28 [ 0 ] ;
unsigned long V_34 ;
int V_23 = V_21 -> V_23 ;
T_2 V_35 , V_50 = V_21 -> V_6 ;
bool V_53 = false ;
if ( V_21 -> V_23 == V_24 ||
( ! F_20 ( V_2 ) && V_21 -> V_30 ) )
return NULL ;
V_54:
V_35 = 0xffULL << ( V_23 * 8 ) ;
F_24 ( & V_27 -> V_36 , V_34 ) ;
if ( ! F_25 ( F_26 ( & V_27 -> V_31 ) , V_23 , 8 ) ||
! ( ( V_50 ^ V_27 -> V_6 ) & V_35 ) ) {
F_27 ( 1 << ( V_23 * 8 ) , & V_27 -> V_31 ) ;
V_27 -> V_6 &= ~ V_35 ;
V_27 -> V_6 |= V_50 & V_35 ;
V_53 = true ;
}
F_28 ( & V_27 -> V_36 , V_34 ) ;
if ( ! V_53 ) {
V_23 = ( V_23 + 1 ) % 4 ;
if ( V_23 != V_21 -> V_23 ) {
V_50 = F_32 ( V_9 , V_23 , false ) ;
goto V_54;
}
return & V_38 ;
}
if ( ! F_20 ( V_2 ) ) {
if ( V_23 != V_21 -> V_23 )
F_32 ( V_9 , V_23 , true ) ;
V_21 -> V_30 = 1 ;
}
return NULL ;
}
static void F_34 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_20 * V_21 = & V_9 -> V_12 . V_22 ;
struct V_26 * V_27 = & V_2 -> V_28 [ 0 ] ;
if ( F_20 ( V_2 ) || ! V_21 -> V_30 )
return;
F_21 ( 1 << ( V_21 -> V_23 * 8 ) , & V_27 -> V_31 ) ;
V_21 -> V_30 = 0 ;
}
static int F_35 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_12 ;
struct V_20 * V_21 = & V_11 -> V_22 ;
int V_55 = V_11 -> V_6 & V_56 ;
if ( V_55 >= 0xb && V_55 <= 0xe ) {
V_21 -> V_25 = V_57 ;
V_21 -> V_23 = V_55 - 0xb ;
V_21 -> V_6 = V_9 -> V_49 . V_50 & ( 0xff << ( V_21 -> V_23 * 8 ) ) ;
}
return 0 ;
}
void F_36 ( void )
{
if ( V_58 . V_59 > V_60 . V_61 )
V_58 . V_59 = V_60 . V_61 ;
V_62 = V_63 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_12 ;
struct V_20 * V_21 = & V_11 -> V_22 ;
struct V_20 * V_64 = & V_11 -> V_65 ;
if ( ( V_11 -> V_6 & V_56 ) == 0x38 ) {
V_21 -> V_23 = 0 ;
V_21 -> V_25 = V_66 ;
V_21 -> V_6 = V_9 -> V_49 . V_50 ;
V_64 -> V_25 = V_67 ;
V_64 -> V_6 = V_9 -> V_49 . V_68 ;
}
return 0 ;
}
static void F_38 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
struct V_10 * V_11 = & V_9 -> V_12 ;
struct V_20 * V_21 = & V_11 -> V_22 ;
struct V_20 * V_64 = & V_11 -> V_65 ;
if ( V_21 -> V_23 != V_24 ) {
int V_23 = V_2 -> V_47 -> V_48 + V_69 ;
struct V_3 * V_70 = V_71 [ V_2 -> V_72 ] [ V_23 ] ;
if ( V_70 ) {
F_4 ( V_70 , V_21 -> V_25 ,
( T_1 ) V_21 -> V_6 ) ;
F_4 ( V_70 , V_21 -> V_25 + 4 ,
( T_1 ) ( V_21 -> V_6 >> 32 ) ) ;
F_4 ( V_70 , V_64 -> V_25 ,
( T_1 ) V_64 -> V_6 ) ;
F_4 ( V_70 , V_64 -> V_25 + 4 ,
( T_1 ) ( V_64 -> V_6 >> 32 ) ) ;
}
}
F_4 ( V_4 , V_11 -> V_13 , V_11 -> V_6 | V_14 ) ;
}
static int F_39 ( int V_73 )
{
struct V_3 * V_74 = NULL ;
int V_29 , V_75 , V_76 ;
int V_77 = 0 ;
T_1 V_6 = 0 ;
while ( 1 ) {
V_74 = F_40 ( V_78 , V_73 , V_74 ) ;
if ( ! V_74 )
break;
V_75 = V_74 -> V_75 -> V_79 ;
V_77 = F_3 ( V_74 , 0x40 , & V_6 ) ;
if ( V_77 )
break;
V_76 = V_6 ;
V_77 = F_3 ( V_74 , 0x54 , & V_6 ) ;
if ( V_77 )
break;
for ( V_29 = 0 ; V_29 < 8 ; V_29 ++ ) {
if ( V_76 == ( ( V_6 >> ( 3 * V_29 ) ) & 0x7 ) ) {
V_80 [ V_75 ] = V_29 ;
break;
}
}
}
if ( ! V_77 ) {
V_29 = - 1 ;
for ( V_75 = 255 ; V_75 >= 0 ; V_75 -- ) {
if ( V_80 [ V_75 ] >= 0 )
V_29 = V_80 [ V_75 ] ;
else
V_80 [ V_75 ] = V_29 ;
}
}
F_41 ( V_74 ) ;
return V_77 ? F_42 ( V_77 ) : 0 ;
}
int F_43 ( void )
{
int V_81 = F_39 ( 0x3ce0 ) ;
if ( V_81 )
return V_81 ;
V_82 = V_83 ;
V_84 = & V_85 ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 )
{
unsigned V_19 = F_11 ( V_2 ) ;
if ( V_19 )
F_13 ( V_19 , V_86 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
F_4 ( V_4 , V_17 , V_86 ) ;
}
static T_2 F_46 ( int V_33 )
{
T_2 V_35 = 0 ;
if ( V_33 & 0x1 )
V_35 |= V_87 ;
if ( V_33 & 0x2 )
V_35 |= V_88 ;
if ( V_33 & 0x4 )
V_35 |= V_89 ;
if ( V_33 & 0x8 )
V_35 |= V_90 ;
if ( V_33 & 0x10 ) {
V_35 |= V_91 ;
V_35 |= V_92 ;
V_35 |= V_93 ;
V_35 |= V_94 ;
}
return V_35 ;
}
static struct V_32 *
F_47 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
return F_22 ( V_2 , V_9 , F_46 ) ;
}
static int F_48 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_20 * V_21 = & V_9 -> V_12 . V_22 ;
struct V_22 * V_27 ;
int V_23 = 0 ;
for ( V_27 = V_95 ; V_27 -> V_19 ; V_27 ++ ) {
if ( V_27 -> V_9 != ( V_9 -> V_12 . V_6 & V_27 -> V_44 ) )
continue;
V_23 |= V_27 -> V_23 ;
}
if ( V_23 ) {
V_21 -> V_25 = V_45 +
V_46 * V_2 -> V_47 -> V_48 ;
V_21 -> V_6 = V_9 -> V_49 . V_50 & F_46 ( V_23 ) ;
V_21 -> V_23 = V_23 ;
}
return 0 ;
}
static void F_49 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_12 ;
struct V_20 * V_21 = & V_11 -> V_22 ;
if ( V_21 -> V_23 != V_24 ) {
T_2 V_96 = F_16 ( V_2 , 0 ) ;
F_13 ( V_21 -> V_25 , V_96 & 0xffffffff ) ;
F_13 ( V_21 -> V_25 + 6 , V_96 >> 32 ) ;
}
F_13 ( V_11 -> V_13 , V_11 -> V_6 | V_14 ) ;
}
void F_50 ( void )
{
if ( V_97 . V_59 > V_60 . V_61 )
V_97 . V_59 = V_60 . V_61 ;
V_62 = V_98 ;
}
static void F_51 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
struct V_10 * V_11 = & V_9 -> V_12 ;
F_4 ( V_4 , V_99 [ V_11 -> V_23 ] ,
V_11 -> V_6 | V_14 ) ;
}
static void F_52 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
struct V_10 * V_11 = & V_9 -> V_12 ;
F_4 ( V_4 , V_99 [ V_11 -> V_23 ] , V_11 -> V_6 ) ;
}
static T_2 F_53 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
struct V_10 * V_11 = & V_9 -> V_12 ;
T_2 V_15 = 0 ;
F_3 ( V_4 , V_100 [ V_11 -> V_23 ] , ( T_1 * ) & V_15 ) ;
F_3 ( V_4 , V_100 [ V_11 -> V_23 ] + 4 , ( T_1 * ) & V_15 + 1 ) ;
return V_15 ;
}
int F_54 ( void )
{
int V_81 = F_39 ( 0x0e1e ) ;
if ( V_81 )
return V_81 ;
V_82 = V_101 ;
V_84 = & V_102 ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_20 * V_21 = & V_9 -> V_12 . V_22 ;
V_21 -> V_25 = V_103 ;
V_21 -> V_6 = V_9 -> V_49 . V_50 & V_104 ;
V_21 -> V_23 = 0 ;
return 0 ;
}
static T_2 F_56 ( int V_33 )
{
T_2 V_35 = 0 ;
if ( V_33 & 0x1 )
V_35 |= V_105 ;
if ( V_33 & 0x2 )
V_35 |= V_106 ;
if ( V_33 & 0x4 )
V_35 |= V_107 ;
if ( V_33 & 0x8 )
V_35 |= V_108 ;
if ( V_33 & 0x10 ) {
V_35 |= V_109 ;
V_35 |= V_110 ;
V_35 |= V_111 ;
V_35 |= V_112 ;
}
return V_35 ;
}
static struct V_32 *
F_57 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
return F_22 ( V_2 , V_9 , F_56 ) ;
}
static int F_58 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_20 * V_21 = & V_9 -> V_12 . V_22 ;
struct V_22 * V_27 ;
int V_23 = 0 ;
for ( V_27 = V_113 ; V_27 -> V_19 ; V_27 ++ ) {
if ( V_27 -> V_9 != ( V_9 -> V_12 . V_6 & V_27 -> V_44 ) )
continue;
V_23 |= V_27 -> V_23 ;
}
if ( V_23 ) {
V_21 -> V_25 = V_114 +
V_115 * V_2 -> V_47 -> V_48 ;
V_21 -> V_6 = V_9 -> V_49 . V_50 & F_56 ( V_23 ) ;
V_21 -> V_23 = V_23 ;
}
return 0 ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_12 ;
struct V_20 * V_21 = & V_11 -> V_22 ;
if ( V_21 -> V_23 != V_24 ) {
T_2 V_96 = F_16 ( V_2 , 0 ) ;
F_13 ( V_21 -> V_25 , V_96 & 0xffffffff ) ;
F_13 ( V_21 -> V_25 + 1 , V_96 >> 32 ) ;
}
F_13 ( V_11 -> V_13 , V_11 -> V_6 | V_14 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
unsigned V_19 = F_11 ( V_2 ) ;
if ( V_19 ) {
T_2 V_116 = V_18 ;
T_2 V_34 = 0 ;
int V_29 ;
F_61 (i, (unsigned long *)&init, 64 ) {
V_34 |= ( 1ULL << V_29 ) ;
F_13 ( V_19 , V_34 ) ;
}
}
}
static int F_62 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_12 ;
struct V_20 * V_21 = & V_11 -> V_22 ;
int V_55 = V_11 -> V_6 & V_56 ;
if ( V_55 >= 0xb && V_55 <= 0xe ) {
V_21 -> V_25 = V_117 ;
V_21 -> V_23 = V_55 - 0xb ;
V_21 -> V_6 = V_9 -> V_49 . V_50 & ( 0xff << V_21 -> V_23 ) ;
}
return 0 ;
}
void F_63 ( void )
{
if ( V_118 . V_59 > V_60 . V_61 )
V_118 . V_59 = V_60 . V_61 ;
if ( V_71 [ 0 ] [ V_119 ] ) {
T_1 V_120 ;
F_3 ( V_71 [ 0 ] [ V_119 ] ,
0x94 , & V_120 ) ;
if ( ( ( V_120 >> 6 ) & 0x3 ) == 0 )
V_121 . V_59 = 2 ;
}
V_62 = V_122 ;
}
static T_2 F_64 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
struct V_10 * V_11 = & V_9 -> V_12 ;
T_2 V_15 = 0 ;
F_3 ( V_4 , V_123 [ V_11 -> V_23 ] , ( T_1 * ) & V_15 ) ;
F_3 ( V_4 , V_123 [ V_11 -> V_23 ] + 4 , ( T_1 * ) & V_15 + 1 ) ;
return V_15 ;
}
int F_65 ( void )
{
int V_81 = F_39 ( 0x2f1e ) ;
if ( V_81 )
return V_81 ;
V_82 = V_124 ;
V_84 = & V_125 ;
return 0 ;
}
