static int F_1 ( struct V_1 * V_2 , int V_3 ,
T_1 * V_4 , const char * V_5 )
{
int V_6 = 0 ;
V_6 = F_2 ( V_2 , V_3 , V_4 ) ;
if ( V_6 )
F_3 ( L_1 ,
V_5 , F_4 ( V_2 -> V_7 ) , V_3 ) ;
return V_6 ;
}
int F_5 ( struct V_1 * V_2 , int V_3 ,
T_1 V_4 , const char * V_5 )
{
int V_6 = 0 ;
V_6 = F_6 ( V_2 , V_3 , V_4 ) ;
if ( V_6 )
F_3 ( L_2 ,
V_5 , F_4 ( V_2 -> V_7 ) , V_3 ) ;
return V_6 ;
}
static int F_7 ( struct V_8 * V_9 , int V_10 , T_1 * V_4 ,
const char * V_5 )
{
if ( V_10 >= 0x100 )
return - V_11 ;
return F_1 ( V_9 -> V_12 , V_10 , V_4 , V_5 ) ;
}
static int F_8 ( struct V_8 * V_9 , int V_10 , T_1 * V_4 ,
const char * V_5 )
{
return F_1 ( V_9 -> V_12 , V_10 , V_4 , V_5 ) ;
}
static void F_9 ( struct V_8 * V_9 , T_2 V_13 )
{
T_1 V_14 = 0 ;
F_10 ( V_9 -> V_15 , V_16 , & V_14 ) ;
V_14 &= 0xfffffffe ;
V_14 |= V_13 ;
F_11 ( V_9 -> V_15 , V_16 , V_14 ) ;
}
static int F_12 ( struct V_8 * V_9 , int V_10 , T_1 * V_4 ,
const char * V_5 )
{
T_2 V_13 = 0 ;
if ( V_10 >= 0x140 && V_10 <= 0x1a0 ) {
V_13 = 1 ;
V_10 -= 0x100 ;
}
F_9 ( V_9 , V_13 ) ;
return F_1 ( V_9 -> V_12 , V_10 , V_4 , V_5 ) ;
}
static int F_13 ( struct V_1 * V_17 , T_1 V_18 , T_1 V_19 )
{
T_1 V_20 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < F_14 ( V_22 ) ; V_21 ++ ) {
if ( V_22 [ V_21 ] . V_20 < V_19 )
continue;
if ( V_22 [ V_21 ] . V_23 <= V_18 )
break;
}
V_20 = V_22 [ V_21 ] . V_20 ;
F_15 ( V_17 , V_24 , V_20 , 0x001F ) ;
if ( V_20 )
return V_22 [ V_21 ] . V_23 ;
return 0 ;
}
static int F_16 ( struct V_25 * V_26 , T_1 V_27 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
T_1 V_29 = 0x5 ;
if ( V_30 . V_31 == 0xf )
V_29 = 0x0 ;
if ( V_30 . V_31 == 0x15 )
F_9 ( V_9 , 0 ) ;
return F_13 ( V_9 -> V_32 , V_27 , V_29 ) ;
}
static int F_17 ( struct V_25 * V_26 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
T_1 V_20 = 0 ;
int V_21 , V_33 = - V_11 ;
if ( V_30 . V_31 == 0x15 )
F_9 ( V_9 , 0 ) ;
F_10 ( V_9 -> V_32 , V_24 , & V_20 ) ;
V_20 = V_20 & 0x001F ;
for ( V_21 = 0 ; V_21 < F_14 ( V_22 ) ; V_21 ++ ) {
if ( V_22 [ V_21 ] . V_20 == V_20 ) {
V_33 = V_22 [ V_21 ] . V_23 ;
break;
}
}
return V_33 ;
}
static bool F_18 ( struct V_8 * V_9 , T_3 V_34 ,
unsigned V_35 )
{
T_3 V_10 ;
V_10 = V_34 & 0x000000ffffffffffull ;
return ( ( V_10 >= F_19 ( V_9 , V_35 ) ) &&
( V_10 <= F_20 ( V_9 , V_35 ) ) ) ;
}
static struct V_25 * F_21 ( struct V_25 * V_26 ,
T_3 V_34 )
{
struct V_8 * V_9 ;
unsigned V_36 ;
T_1 V_37 , V_38 ;
V_9 = V_26 -> V_28 ;
V_37 = F_22 ( V_9 , 0 ) ;
if ( V_37 == 0 ) {
for ( V_36 = 0 ; V_36 < V_39 ; V_36 ++ ) {
if ( F_18 ( V_9 , V_34 , V_36 ) )
goto V_40;
}
goto V_41;
}
if ( F_23 ( ( V_37 != 0x01 ) &&
( V_37 != 0x03 ) &&
( V_37 != 0x07 ) ) ) {
F_3 ( L_3 , V_37 ) ;
return NULL ;
}
V_38 = ( ( ( T_1 ) V_34 ) >> 12 ) & V_37 ;
for ( V_36 = 0 ; ; ) {
if ( ( F_24 ( V_9 , V_36 ) & V_37 ) == V_38 )
break;
if ( ++ V_36 >= V_39 )
goto V_41;
}
if ( F_23 ( ! F_18 ( V_9 , V_34 , V_36 ) ) ) {
F_3 ( L_4
L_5 ,
V_42 , V_34 , V_36 ) ;
return NULL ;
}
V_40:
return F_25 ( ( int ) V_36 ) ;
V_41:
F_26 ( L_6 ,
( unsigned long ) V_34 ) ;
return NULL ;
}
static void F_27 ( struct V_8 * V_9 , int V_43 , T_2 V_13 ,
T_3 * V_44 , T_3 * V_45 )
{
T_3 V_46 , V_47 , V_48 , V_49 ;
T_2 V_50 ;
if ( V_30 . V_31 == 0xf && V_9 -> V_51 < V_52 ) {
V_46 = V_9 -> V_53 [ V_13 ] . V_54 [ V_43 ] ;
V_47 = V_9 -> V_53 [ V_13 ] . V_55 [ V_43 ] ;
V_48 = F_28 ( 21 , 31 ) | F_28 ( 9 , 15 ) ;
V_49 = F_28 ( 21 , 29 ) | F_28 ( 9 , 15 ) ;
V_50 = 4 ;
} else {
V_46 = V_9 -> V_53 [ V_13 ] . V_54 [ V_43 ] ;
V_47 = V_9 -> V_53 [ V_13 ] . V_55 [ V_43 >> 1 ] ;
V_50 = 8 ;
if ( V_30 . V_31 == 0x15 )
V_48 = V_49 = F_28 ( 19 , 30 ) | F_28 ( 5 , 13 ) ;
else
V_48 = V_49 = F_28 ( 19 , 28 ) | F_28 ( 5 , 13 ) ;
}
* V_44 = ( V_46 & V_48 ) << V_50 ;
* V_45 = ~ 0ULL ;
* V_45 &= ~ ( V_49 << V_50 ) ;
* V_45 |= ( V_47 & V_49 ) << V_50 ;
}
static int F_29 ( struct V_25 * V_26 , T_3 V_56 )
{
struct V_8 * V_9 ;
int V_43 ;
T_3 V_44 , V_45 ;
V_9 = V_26 -> V_28 ;
F_30 (csrow, 0 , pvt) {
if ( ! F_31 ( V_43 , 0 , V_9 ) )
continue;
F_27 ( V_9 , V_43 , 0 , & V_44 , & V_45 ) ;
V_45 = ~ V_45 ;
if ( ( V_56 & V_45 ) == ( V_44 & V_45 ) ) {
F_26 ( L_7 ,
( unsigned long ) V_56 , V_43 ,
V_9 -> V_57 ) ;
return V_43 ;
}
}
F_26 ( L_8 ,
( unsigned long ) V_56 , V_9 -> V_57 ) ;
return - 1 ;
}
int F_32 ( struct V_25 * V_26 , T_3 * V_58 ,
T_3 * V_59 , T_3 * V_60 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
T_3 V_44 ;
if ( V_30 . V_31 == 0xf && V_9 -> V_51 < V_61 ) {
F_33 ( L_9 ,
V_9 -> V_51 , V_9 -> V_57 ) ;
return 1 ;
}
if ( V_30 . V_31 >= 0x10 && ! F_34 ( V_9 ) ) {
F_33 ( L_10 ) ;
return 1 ;
}
if ( ! F_35 ( V_9 ) ) {
F_33 ( L_11 ,
V_9 -> V_57 ) ;
return 1 ;
}
V_44 = F_36 ( V_9 ) ;
* V_58 = V_44 ;
* V_60 = ( 0x1ull << 32 ) - V_44 ;
if ( V_30 . V_31 > 0xf )
* V_59 = F_37 ( V_9 ) ;
else
* V_59 = F_38 ( V_9 ) ;
F_33 ( L_12 ,
V_9 -> V_57 , ( unsigned long ) * V_58 ,
( unsigned long ) * V_59 , ( unsigned long ) * V_60 ) ;
return 0 ;
}
static T_3 F_39 ( struct V_25 * V_26 , T_3 V_34 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
T_3 V_62 , V_58 , V_59 , V_60 , V_63 ;
int V_64 = 0 ;
V_62 = F_19 ( V_9 , V_9 -> V_57 ) ;
V_64 = F_32 ( V_26 , & V_58 , & V_59 ,
& V_60 ) ;
if ( ! V_64 ) {
if ( ( V_34 >= ( 1ull << 32 ) ) &&
( V_34 < ( ( 1ull << 32 ) + V_60 ) ) ) {
V_63 = V_34 - V_59 ;
F_26 ( L_13
L_14 ,
( unsigned long ) V_34 ,
( unsigned long ) V_63 ) ;
return V_63 ;
}
}
V_63 = ( V_34 & F_28 ( 0 , 39 ) ) - V_62 ;
F_26 ( L_15
L_14 , ( unsigned long ) V_34 ,
( unsigned long ) V_63 ) ;
return V_63 ;
}
static int F_40 ( unsigned V_37 )
{
static const int V_65 [] = { 0 , 1 , 0 , 2 , 0 , 0 , 0 , 3 } ;
int V_66 ;
F_41 ( V_37 > 7 ) ;
V_66 = V_65 [ V_37 ] ;
return V_66 ;
}
static T_3 F_42 ( struct V_25 * V_26 , T_3 V_63 )
{
struct V_8 * V_9 ;
int V_67 ;
T_3 V_56 ;
V_9 = V_26 -> V_28 ;
V_67 = F_40 ( F_22 ( V_9 , 0 ) ) ;
V_56 = ( ( V_63 >> V_67 ) & F_28 ( 12 , 35 ) ) +
( V_63 & 0xfff ) ;
F_26 ( L_16 ,
V_67 , ( unsigned long ) V_63 ,
( unsigned long ) V_56 ) ;
return V_56 ;
}
static T_3 F_43 ( struct V_25 * V_26 , T_3 V_34 )
{
T_3 V_56 ;
V_56 =
F_42 ( V_26 , F_39 ( V_26 , V_34 ) ) ;
F_26 ( L_17 ,
( unsigned long ) V_34 , ( unsigned long ) V_56 ) ;
return V_56 ;
}
static T_3 F_44 ( struct V_25 * V_26 , T_3 V_56 )
{
struct V_8 * V_9 ;
unsigned V_36 , V_67 ;
T_3 V_38 , V_63 ;
T_1 V_68 ;
V_9 = V_26 -> V_28 ;
V_36 = V_9 -> V_57 ;
F_41 ( V_36 > 7 ) ;
V_67 = F_40 ( F_22 ( V_9 , 0 ) ) ;
if ( V_67 == 0 ) {
F_33 ( L_18
L_19 , ( unsigned long ) V_56 ) ;
return V_56 ;
}
V_38 = ( ( V_56 & F_28 ( 12 , 35 ) ) << V_67 ) +
( V_56 & 0xfff ) ;
V_68 = F_24 ( V_9 , V_36 ) & ( ( 1 << V_67 ) - 1 ) ;
V_63 = V_38 + ( V_68 << 12 ) ;
F_33 ( L_20
L_21 , ( unsigned long ) V_56 ,
( unsigned long ) V_63 , V_67 ) ;
return V_63 ;
}
static T_3 F_45 ( struct V_25 * V_26 , T_3 V_63 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
T_3 V_58 , V_59 , V_60 , V_44 , V_34 ;
int V_64 = 0 ;
V_64 = F_32 ( V_26 , & V_58 , & V_59 ,
& V_60 ) ;
if ( ! V_64 ) {
if ( ( V_63 >= V_58 ) &&
( V_63 < ( V_58 + V_60 ) ) ) {
V_34 = V_63 + V_59 ;
F_33 ( L_22
L_23 , ( unsigned long ) V_63 ,
( unsigned long ) V_34 ) ;
return V_34 ;
}
}
V_44 = F_19 ( V_9 , V_9 -> V_57 ) ;
V_34 = V_63 + V_44 ;
V_34 |= ~ ( ( V_34 & ( 1ull << 39 ) ) - 1 ) ;
F_33 ( L_24 ,
V_9 -> V_57 , ( unsigned long ) V_63 ,
( unsigned long ) V_34 ) ;
return V_34 ;
}
static inline T_3 F_46 ( struct V_25 * V_26 ,
T_3 V_56 )
{
return F_45 ( V_26 ,
F_44 ( V_26 , V_56 ) ) ;
}
static void F_47 ( struct V_25 * V_26 , int V_43 ,
T_3 * V_69 , T_3 * V_70 )
{
struct V_8 * V_9 ;
T_3 V_44 , V_45 ;
V_9 = V_26 -> V_28 ;
F_41 ( ( V_43 < 0 ) || ( V_43 >= V_9 -> V_53 [ 0 ] . V_71 ) ) ;
F_27 ( V_9 , V_43 , 0 , & V_44 , & V_45 ) ;
* V_69 = V_44 & ~ V_45 ;
* V_70 = V_44 | V_45 ;
}
static inline void F_48 ( T_3 V_72 ,
T_1 * V_73 , T_1 * V_3 )
{
* V_73 = ( T_1 ) ( V_72 >> V_74 ) ;
* V_3 = ( ( T_1 ) V_72 ) & ~ V_75 ;
}
static int F_49 ( struct V_25 * V_26 , T_3 V_34 )
{
int V_43 ;
V_43 = F_29 ( V_26 , F_43 ( V_26 , V_34 ) ) ;
if ( V_43 == - 1 )
F_50 ( V_26 , L_25
L_26 , ( unsigned long ) V_34 ) ;
return V_43 ;
}
static unsigned long F_51 ( struct V_8 * V_9 )
{
T_2 V_76 ;
unsigned long V_77 = V_78 ;
V_76 = ( V_30 . V_31 > 0xf || V_9 -> V_51 >= V_52 )
? 19
: 17 ;
if ( V_9 -> V_79 & F_52 ( V_76 ) )
V_77 = V_80 ;
return V_77 ;
}
static void F_53 ( T_1 V_81 , int V_82 )
{
F_33 ( L_27 , V_82 , V_81 ) ;
F_33 ( L_28 ,
( V_81 & F_52 ( 16 ) ) ? L_29 : L_30 ,
( V_81 & F_52 ( 19 ) ) ? L_31 : L_32 ) ;
F_33 ( L_33 ,
( V_81 & F_52 ( 8 ) ) ? L_34 : L_35 ) ;
if ( V_30 . V_31 == 0x10 )
F_33 ( L_36 ,
( V_81 & F_52 ( 11 ) ) ? L_37 : L_38 ) ;
F_33 ( L_39 ,
( V_81 & F_52 ( 12 ) ) ? L_31 : L_32 ,
( V_81 & F_52 ( 13 ) ) ? L_31 : L_32 ,
( V_81 & F_52 ( 14 ) ) ? L_31 : L_32 ,
( V_81 & F_52 ( 15 ) ) ? L_31 : L_32 ) ;
}
static void F_54 ( struct V_8 * V_9 )
{
F_33 ( L_40 , V_9 -> V_83 ) ;
F_33 ( L_41 ,
( V_9 -> V_83 & V_84 ) ? L_31 : L_32 ) ;
F_33 ( L_42 ,
( V_9 -> V_83 & V_85 ) ? L_31 : L_32 ,
( V_9 -> V_83 & V_86 ) ? L_31 : L_32 ) ;
F_53 ( V_9 -> V_79 , 0 ) ;
F_33 ( L_43 , V_9 -> V_87 ) ;
F_33 ( L_44
L_45 ,
V_9 -> V_88 , F_36 ( V_9 ) ,
( V_30 . V_31 == 0xf ) ? F_38 ( V_9 )
: F_37 ( V_9 ) ) ;
F_33 ( L_46 , F_35 ( V_9 ) ? L_31 : L_32 ) ;
F_55 ( V_9 , 0 ) ;
if ( V_30 . V_31 == 0xf )
return;
F_55 ( V_9 , 1 ) ;
F_56 ( L_47 , ( ( V_9 -> V_89 == 8 ) ? L_48 : L_49 ) ) ;
if ( ! F_57 ( V_9 ) )
F_53 ( V_9 -> V_90 , 1 ) ;
}
static void F_58 ( struct V_8 * V_9 )
{
if ( V_30 . V_31 == 0xf && V_9 -> V_51 < V_52 ) {
V_9 -> V_53 [ 0 ] . V_71 = V_9 -> V_53 [ 1 ] . V_71 = 8 ;
V_9 -> V_53 [ 0 ] . V_91 = V_9 -> V_53 [ 1 ] . V_91 = 8 ;
} else {
V_9 -> V_53 [ 0 ] . V_71 = V_9 -> V_53 [ 1 ] . V_71 = 8 ;
V_9 -> V_53 [ 0 ] . V_91 = V_9 -> V_53 [ 1 ] . V_91 = 4 ;
}
}
static void F_59 ( struct V_8 * V_9 )
{
int V_92 ;
F_58 ( V_9 ) ;
F_30 (cs, 0 , pvt) {
int V_93 = V_94 + ( V_92 * 4 ) ;
int V_95 = V_96 + ( V_92 * 4 ) ;
T_1 * V_97 = & V_9 -> V_53 [ 0 ] . V_54 [ V_92 ] ;
T_1 * V_98 = & V_9 -> V_53 [ 1 ] . V_54 [ V_92 ] ;
if ( ! F_60 ( V_9 , V_93 , V_97 ) )
F_61 ( L_50 ,
V_92 , * V_97 , V_93 ) ;
if ( V_30 . V_31 == 0xf || F_57 ( V_9 ) )
continue;
if ( ! F_60 ( V_9 , V_95 , V_98 ) )
F_61 ( L_51 ,
V_92 , * V_98 , V_95 ) ;
}
F_62 (cs, 0 , pvt) {
int V_93 = V_99 + ( V_92 * 4 ) ;
int V_95 = V_100 + ( V_92 * 4 ) ;
T_1 * V_101 = & V_9 -> V_53 [ 0 ] . V_55 [ V_92 ] ;
T_1 * V_102 = & V_9 -> V_53 [ 1 ] . V_55 [ V_92 ] ;
if ( ! F_60 ( V_9 , V_93 , V_101 ) )
F_61 ( L_52 ,
V_92 , * V_101 , V_93 ) ;
if ( V_30 . V_31 == 0xf || F_57 ( V_9 ) )
continue;
if ( ! F_60 ( V_9 , V_95 , V_102 ) )
F_61 ( L_53 ,
V_92 , * V_102 , V_95 ) ;
}
}
static enum V_103 F_63 ( struct V_8 * V_9 , int V_92 )
{
enum V_103 type ;
if ( V_30 . V_31 >= 0x15 )
type = ( V_9 -> V_79 & F_52 ( 16 ) ) ? V_104 : V_105 ;
else if ( V_30 . V_31 == 0x10 || V_9 -> V_51 >= V_52 ) {
if ( V_9 -> V_106 & V_107 )
type = ( V_9 -> V_79 & F_52 ( 16 ) ) ? V_104 : V_105 ;
else
type = ( V_9 -> V_79 & F_52 ( 16 ) ) ? V_108 : V_109 ;
} else {
type = ( V_9 -> V_79 & F_52 ( 18 ) ) ? V_110 : V_111 ;
}
F_56 ( L_54 , V_92 , V_112 [ type ] ) ;
return type ;
}
static int F_64 ( struct V_8 * V_9 )
{
int V_113 ;
if ( V_9 -> V_51 >= V_52 )
V_113 = V_9 -> V_79 & V_114 ;
else
V_113 = V_9 -> V_79 & V_115 ;
V_9 -> V_90 = 0 ;
return ( V_113 ) ? 2 : 1 ;
}
static T_3 F_65 ( struct V_116 * V_117 )
{
struct V_118 * V_119 = & V_30 ;
T_3 V_10 ;
T_2 V_120 = 1 ;
T_2 V_121 = 47 ;
if ( V_119 -> V_31 == 0xf ) {
V_120 = 3 ;
V_121 = 39 ;
}
V_10 = V_117 -> V_10 & F_28 ( V_120 , V_121 ) ;
if ( V_119 -> V_31 == 0x15 ) {
struct V_8 * V_9 ;
T_3 V_122 , V_123 ;
T_1 V_124 ;
T_2 V_125 , V_37 ;
if ( ( V_10 & F_28 ( 24 , 47 ) ) >> 24 != 0x00fdf7 )
return V_10 ;
V_125 = F_66 ( V_117 -> V_126 ) ;
V_9 = V_127 [ V_125 ] -> V_28 ;
F_10 ( V_9 -> V_15 , V_128 , & V_124 ) ;
V_37 = V_124 >> 21 & 0x7 ;
V_122 = ( V_124 & F_28 ( 0 , 20 ) ) << 3 ;
V_122 |= V_37 ^ 0x7 ;
V_122 <<= 24 ;
if ( ! V_37 )
return V_122 | ( V_10 & F_28 ( 0 , 23 ) ) ;
F_10 ( V_9 -> V_15 , V_129 , & V_124 ) ;
V_123 = ( V_10 & F_28 ( 12 , 23 ) ) << F_67 ( V_37 + 1 ) ;
V_123 |= ( V_124 & F_28 ( 21 , 23 ) ) >> 9 ;
V_123 |= V_10 & F_28 ( 0 , 11 ) ;
return V_122 | V_123 ;
}
return V_10 ;
}
static void F_68 ( struct V_8 * V_9 , unsigned V_130 )
{
struct V_118 * V_119 = & V_30 ;
int V_131 = V_130 << 3 ;
F_10 ( V_9 -> V_15 , V_132 + V_131 , & V_9 -> V_133 [ V_130 ] . V_44 . V_134 ) ;
F_10 ( V_9 -> V_15 , V_135 + V_131 , & V_9 -> V_133 [ V_130 ] . V_136 . V_134 ) ;
if ( V_119 -> V_31 == 0xf )
return;
if ( ! F_69 ( V_9 , V_130 ) )
return;
F_10 ( V_9 -> V_15 , V_137 + V_131 , & V_9 -> V_133 [ V_130 ] . V_44 . V_138 ) ;
F_10 ( V_9 -> V_15 , V_139 + V_131 , & V_9 -> V_133 [ V_130 ] . V_136 . V_138 ) ;
if ( V_119 -> V_31 == 0x15 ) {
struct V_1 * V_140 = NULL ;
T_2 V_35 = F_70 ( V_9 , V_130 ) ;
T_1 V_141 ;
V_140 = F_71 ( 0 , 0 , F_72 ( 0x18 + V_35 , 1 ) ) ;
if ( F_73 ( ! V_140 ) )
return;
F_10 ( V_140 , V_128 , & V_141 ) ;
V_9 -> V_133 [ V_130 ] . V_136 . V_134 &= F_28 ( 0 , 15 ) ;
V_9 -> V_133 [ V_130 ] . V_136 . V_134 |= ( ( V_141 & 0x1fff ) << 3 | 0x7 ) << 16 ;
V_9 -> V_133 [ V_130 ] . V_136 . V_138 &= F_28 ( 0 , 7 ) ;
V_9 -> V_133 [ V_130 ] . V_136 . V_138 |= V_141 >> 13 ;
F_74 ( V_140 ) ;
}
}
static void F_75 ( struct V_25 * V_26 , T_3 V_34 ,
T_4 V_142 )
{
struct V_25 * V_143 ;
struct V_8 * V_9 = V_26 -> V_28 ;
int V_144 , V_43 ;
T_1 V_73 , V_3 ;
if ( V_9 -> V_145 & V_146 ) {
V_144 = F_76 ( V_26 , V_142 ) ;
if ( V_144 < 0 ) {
F_77 ( V_26 , L_55
L_56 , V_142 ) ;
F_78 ( V_26 , V_147 ) ;
return;
}
} else {
V_144 = ( ( V_34 & F_52 ( 3 ) ) != 0 ) ;
}
V_143 = F_21 ( V_26 , V_34 ) ;
if ( ! V_143 ) {
F_50 ( V_26 , L_57 ,
( unsigned long ) V_34 ) ;
F_78 ( V_26 , V_147 ) ;
return;
}
V_43 = F_49 ( V_143 , V_34 ) ;
if ( V_43 < 0 ) {
F_78 ( V_143 , V_147 ) ;
} else {
F_48 ( V_34 , & V_73 , & V_3 ) ;
F_79 ( V_143 , V_73 , V_3 , V_142 , V_43 ,
V_144 , V_147 ) ;
}
}
static int F_80 ( unsigned V_21 , bool V_148 )
{
unsigned V_149 = 0 ;
if ( V_21 <= 2 )
V_149 = V_21 ;
else if ( ! ( V_21 & 0x1 ) )
V_149 = V_21 >> 1 ;
else
V_149 = ( V_21 + 1 ) >> 1 ;
return 128 << ( V_149 + ! ! V_148 ) ;
}
static int F_81 ( struct V_8 * V_9 , T_2 V_13 ,
unsigned V_150 )
{
T_1 V_81 = V_13 ? V_9 -> V_90 : V_9 -> V_79 ;
if ( V_9 -> V_51 >= V_52 ) {
F_73 ( V_150 > 11 ) ;
return F_80 ( V_150 , V_81 & V_114 ) ;
}
else if ( V_9 -> V_51 >= V_151 ) {
unsigned V_152 ;
F_73 ( V_150 > 10 ) ;
V_152 = V_150 / 3 + ( unsigned ) ( V_150 > 5 ) ;
return 32 << ( V_150 - V_152 ) ;
}
else {
F_73 ( V_150 > 6 ) ;
return 32 << V_150 ;
}
}
static int F_82 ( struct V_8 * V_9 )
{
int V_21 , V_153 , V_154 = 0 ;
if ( V_30 . V_31 == 0x10 && ( V_9 -> V_79 & V_114 ) )
return 2 ;
F_61 ( L_58 ) ;
for ( V_21 = 0 ; V_21 < 2 ; V_21 ++ ) {
T_1 V_155 = ( V_21 ? V_9 -> V_156 : V_9 -> V_157 ) ;
for ( V_153 = 0 ; V_153 < 4 ; V_153 ++ ) {
if ( F_83 ( V_153 , V_155 ) > 0 ) {
V_154 ++ ;
break;
}
}
}
if ( V_154 > 2 )
V_154 = 2 ;
F_56 ( L_59 , V_154 ) ;
return V_154 ;
}
static int F_84 ( unsigned V_21 , bool V_148 )
{
unsigned V_149 = 0 ;
int V_158 = 0 ;
if ( V_21 == 0 || V_21 == 3 || V_21 == 4 )
V_158 = - 1 ;
else if ( V_21 <= 2 )
V_149 = V_21 ;
else if ( V_21 == 12 )
V_149 = 7 ;
else if ( ! ( V_21 & 0x1 ) )
V_149 = V_21 >> 1 ;
else
V_149 = ( V_21 + 1 ) >> 1 ;
if ( V_158 != - 1 )
V_158 = ( 128 * ( 1 << ! ! V_148 ) ) << V_149 ;
return V_158 ;
}
static int F_85 ( struct V_8 * V_9 , T_2 V_13 ,
unsigned V_150 )
{
T_1 V_81 = V_13 ? V_9 -> V_90 : V_9 -> V_79 ;
F_73 ( V_150 > 11 ) ;
if ( V_9 -> V_106 & V_107 || V_9 -> V_159 & V_107 )
return F_84 ( V_150 , V_81 & V_114 ) ;
else
return F_80 ( V_150 , V_81 & V_114 ) ;
}
static int F_86 ( struct V_8 * V_9 , T_2 V_13 ,
unsigned V_150 )
{
F_73 ( V_150 > 12 ) ;
return F_84 ( V_150 , false ) ;
}
static void F_87 ( struct V_8 * V_9 )
{
if ( V_30 . V_31 == 0xf )
return;
if ( ! F_60 ( V_9 , V_160 , & V_9 -> V_161 ) ) {
F_61 ( L_60 ,
V_9 -> V_161 , F_88 ( V_9 ) ) ;
F_61 ( L_61 ,
( F_57 ( V_9 ) ? L_62 : L_63 ) ) ;
if ( ! F_57 ( V_9 ) )
F_61 ( L_64 ,
( F_89 ( V_9 ) ? L_31 : L_32 ) ) ;
F_61 ( L_65
L_66 ,
( F_90 ( V_9 ) ? L_34 : L_35 ) ,
( F_91 ( V_9 ) ? L_31 : L_32 ) ) ;
F_61 ( L_67
L_68 ,
( F_92 ( V_9 ) ? L_34 : L_35 ) ,
F_93 ( V_9 ) ) ;
}
F_60 ( V_9 , V_162 , & V_9 -> V_163 ) ;
}
static T_2 F_94 ( struct V_8 * V_9 , T_3 V_34 ,
bool V_164 , T_2 V_37 )
{
T_2 V_165 = ( V_9 -> V_161 >> 1 ) & 1 ;
if ( F_57 ( V_9 ) )
return 0 ;
if ( V_164 )
return V_165 ;
if ( F_92 ( V_9 ) ) {
T_2 V_166 = F_93 ( V_9 ) ;
if ( ! V_166 )
return V_34 >> 6 & 1 ;
if ( V_166 & 0x2 ) {
T_2 V_149 = V_166 & 0x1 ? 9 : 6 ;
T_1 V_167 = F_95 ( ( T_1 ) ( ( V_34 >> 16 ) & 0x1F ) ) % 2 ;
return ( ( V_34 >> V_149 ) & 1 ) ^ V_167 ;
}
return ( V_34 >> ( 12 + F_96 ( V_37 ) ) ) & 1 ;
}
if ( F_89 ( V_9 ) )
return ~ V_165 & 1 ;
return 0 ;
}
static T_3 F_97 ( struct V_8 * V_9 , unsigned V_130 ,
T_3 V_34 , bool V_168 ,
T_1 V_169 )
{
T_3 V_170 ;
T_3 V_62 = F_19 ( V_9 , V_130 ) ;
T_3 V_171 = F_37 ( V_9 ) ;
T_3 V_172 = ( V_9 -> V_163 & 0xFFFFFC00 ) << 16 ;
if ( V_168 ) {
if ( ( ! ( V_169 >> 16 ) ||
V_169 < F_36 ( V_9 ) ) &&
F_35 ( V_9 ) &&
( V_34 >= F_98 ( 32 ) ) )
V_170 = V_171 ;
else
V_170 = V_172 ;
} else {
if ( F_35 ( V_9 ) && ( V_34 >= F_98 ( 32 ) ) )
V_170 = V_171 ;
else
V_170 = V_62 ;
}
return ( V_34 & F_28 ( 6 , 47 ) ) - ( V_170 & F_28 ( 23 , 47 ) ) ;
}
static int F_99 ( struct V_8 * V_9 , T_2 V_13 , int V_43 )
{
int V_173 ;
if ( F_100 ( V_9 , V_13 ) &&
V_43 == F_101 ( V_9 , V_13 ) ) {
F_30 (tmp_cs, dct, pvt) {
if ( F_102 ( V_173 , V_13 , V_9 ) & 0x2 ) {
V_43 = V_173 ;
break;
}
}
}
return V_43 ;
}
static int F_103 ( T_3 V_174 , T_1 V_35 , T_2 V_13 )
{
struct V_25 * V_26 ;
struct V_8 * V_9 ;
T_3 V_175 , V_176 ;
int V_177 = - V_11 ;
int V_43 ;
V_26 = V_127 [ V_35 ] ;
if ( ! V_26 )
return V_177 ;
V_9 = V_26 -> V_28 ;
F_33 ( L_69 , V_174 , V_13 ) ;
F_30 (csrow, dct, pvt) {
if ( ! F_31 ( V_43 , V_13 , V_9 ) )
continue;
F_27 ( V_9 , V_43 , V_13 , & V_175 , & V_176 ) ;
F_33 ( L_70 ,
V_43 , V_175 , V_176 ) ;
V_176 = ~ V_176 ;
F_33 ( L_71
L_72 ,
( V_174 & V_176 ) , ( V_175 & V_176 ) ) ;
if ( ( V_174 & V_176 ) == ( V_175 & V_176 ) ) {
V_177 = F_99 ( V_9 , V_13 , V_43 ) ;
F_33 ( L_73 , V_177 ) ;
break;
}
}
return V_177 ;
}
static T_3 F_104 ( struct V_8 * V_9 , T_3 V_34 )
{
T_1 V_178 , V_179 , V_180 , V_181 , V_123 ;
if ( V_30 . V_31 == 0x10 ) {
if ( V_30 . V_182 < 4 ||
( V_30 . V_182 < 0xa &&
V_30 . V_183 < 3 ) )
return V_34 ;
}
F_60 ( V_9 , V_184 , & V_178 ) ;
if ( ! ( V_178 & 0x1 ) )
return V_34 ;
V_179 = ( V_178 >> 3 ) & 0x7f ;
V_180 = ( V_178 >> 11 ) & 0x7f ;
V_181 = ( V_178 >> 20 ) & 0x7f ;
V_123 = V_34 >> 27 ;
if ( ! ( V_34 >> 34 ) &&
( ( ( V_123 >= V_179 ) &&
( V_123 <= V_180 ) ) ||
( V_123 < V_181 ) ) )
return V_34 ^ ( T_3 ) V_179 << 27 ;
return V_34 ;
}
static int F_105 ( struct V_8 * V_9 , unsigned V_130 ,
T_3 V_34 , int * V_35 , int * V_185 )
{
int V_177 = - V_11 ;
T_3 V_186 ;
T_1 V_187 ;
T_2 V_144 ;
bool V_188 = false ;
T_2 V_36 = F_70 ( V_9 , V_130 ) ;
T_2 V_37 = F_22 ( V_9 , V_130 ) ;
T_1 V_68 = F_24 ( V_9 , V_130 ) ;
F_33 ( L_74 ,
V_130 , V_34 , F_20 ( V_9 , V_130 ) ) ;
if ( F_35 ( V_9 ) &&
F_36 ( V_9 ) <= V_34 &&
V_34 < F_98 ( 32 ) ) {
F_3 ( L_75 ,
V_34 ) ;
return - V_11 ;
}
if ( V_37 && ( V_68 != ( ( V_34 >> 12 ) & V_37 ) ) )
return - V_11 ;
V_34 = F_104 ( V_9 , V_34 ) ;
V_187 = F_88 ( V_9 ) ;
if ( F_89 ( V_9 ) &&
! F_57 ( V_9 ) &&
( ( V_34 >> 27 ) >= ( V_187 >> 11 ) ) )
V_188 = true ;
V_144 = F_94 ( V_9 , V_34 , V_188 , V_37 ) ;
V_186 = F_97 ( V_9 , V_130 , V_34 ,
V_188 , V_187 ) ;
if ( V_37 )
V_186 = ( ( V_186 >> ( 12 + F_96 ( V_37 ) ) ) << 12 ) |
( V_186 & 0xfff ) ;
if ( F_92 ( V_9 ) &&
! F_89 ( V_9 ) &&
! F_57 ( V_9 ) ) {
if ( F_93 ( V_9 ) != 1 ) {
if ( F_93 ( V_9 ) == 0x3 )
V_186 = ( ( V_186 >> 10 ) << 9 ) |
( V_186 & 0x1ff ) ;
else
V_186 = ( ( V_186 >> 7 ) << 6 ) |
( V_186 & 0x3f ) ;
} else
V_186 = ( ( V_186 >> 13 ) << 12 ) |
( V_186 & 0xfff ) ;
}
F_33 ( L_76 , V_186 ) ;
V_177 = F_103 ( V_186 , V_36 , V_144 ) ;
if ( V_177 >= 0 ) {
* V_35 = V_36 ;
* V_185 = V_144 ;
}
return V_177 ;
}
static int F_106 ( struct V_8 * V_9 , T_3 V_34 ,
int * V_189 , int * V_185 )
{
int V_177 = - V_11 ;
unsigned V_130 ;
for ( V_130 = 0 ; V_130 < V_39 ; V_130 ++ ) {
if ( ! F_69 ( V_9 , V_130 ) )
continue;
if ( ( F_19 ( V_9 , V_130 ) <= V_34 ) &&
( F_20 ( V_9 , V_130 ) >= V_34 ) ) {
V_177 = F_105 ( V_9 , V_130 ,
V_34 , V_189 ,
V_185 ) ;
if ( V_177 >= 0 )
break;
}
}
return V_177 ;
}
static void F_107 ( struct V_25 * V_26 , T_3 V_34 ,
T_4 V_142 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
T_1 V_73 , V_3 ;
int V_35 , V_43 , V_82 = 0 ;
V_43 = F_106 ( V_9 , V_34 , & V_35 , & V_82 ) ;
if ( V_43 < 0 ) {
F_78 ( V_26 , V_147 ) ;
return;
}
F_48 ( V_34 , & V_73 , & V_3 ) ;
if ( F_57 ( V_9 ) )
V_82 = F_76 ( V_26 , V_142 ) ;
if ( V_82 >= 0 )
F_79 ( V_26 , V_73 , V_3 , V_142 , V_43 , V_82 ,
V_147 ) ;
else
for ( V_82 = 0 ; V_82 < V_26 -> V_190 [ V_43 ] . V_191 ; V_82 ++ )
F_79 ( V_26 , V_73 , V_3 , V_142 ,
V_43 , V_82 , V_147 ) ;
}
static void F_55 ( struct V_8 * V_9 , T_2 V_192 )
{
int V_193 , V_194 , V_195 , V_196 = 0 ;
T_1 * V_197 = V_192 ? V_9 -> V_53 [ 1 ] . V_54 : V_9 -> V_53 [ 0 ] . V_54 ;
T_1 V_155 = V_192 ? V_9 -> V_156 : V_9 -> V_157 ;
if ( V_30 . V_31 == 0xf ) {
if ( V_9 -> V_79 & V_114 )
V_196 = 1 ;
if ( V_9 -> V_51 < V_52 )
return;
else
F_73 ( V_192 != 0 ) ;
}
V_155 = ( V_192 && ! F_57 ( V_9 ) ) ? V_9 -> V_156 : V_9 -> V_157 ;
V_197 = ( V_192 && ! F_57 ( V_9 ) ) ? V_9 -> V_53 [ 1 ] . V_54
: V_9 -> V_53 [ 0 ] . V_54 ;
F_33 ( L_77 , V_192 , V_155 ) ;
F_108 ( V_198 , V_199 , L_78 , V_192 ) ;
for ( V_193 = 0 ; V_193 < 4 ; V_193 ++ ) {
V_194 = 0 ;
if ( V_197 [ V_193 * 2 ] & V_200 )
V_194 = V_9 -> V_201 -> V_202 ( V_9 , V_192 ,
F_83 ( V_193 , V_155 ) ) ;
V_195 = 0 ;
if ( V_197 [ V_193 * 2 + 1 ] & V_200 )
V_195 = V_9 -> V_201 -> V_202 ( V_9 , V_192 ,
F_83 ( V_193 , V_155 ) ) ;
F_56 ( V_199 L_79 ,
V_193 * 2 , V_194 << V_196 ,
V_193 * 2 + 1 , V_195 << V_196 ) ;
}
}
static struct V_1 * F_109 ( unsigned int V_203 ,
unsigned int V_204 ,
struct V_1 * V_205 )
{
struct V_1 * V_206 = NULL ;
V_206 = F_110 ( V_203 , V_204 , V_206 ) ;
while ( V_206 ) {
if ( ( V_206 -> V_207 -> V_208 == V_205 -> V_207 -> V_208 ) &&
( F_111 ( V_206 -> V_7 ) == F_111 ( V_205 -> V_7 ) ) )
break;
V_206 = F_110 ( V_203 , V_204 , V_206 ) ;
}
return V_206 ;
}
static int F_112 ( T_4 V_142 , T_4 * V_209 , unsigned V_210 ,
unsigned V_211 )
{
unsigned int V_21 , V_212 ;
for ( V_212 = 0 ; V_212 < V_210 / V_211 ; V_212 ++ ) {
T_4 V_213 = V_142 ;
unsigned V_214 = V_212 * V_211 ;
unsigned V_215 = ( V_212 + 1 ) * V_211 ;
for ( V_21 = 1 ; V_21 < ( 1U << 16 ) ; V_21 <<= 1 ) {
if ( V_214 < V_215 && V_209 [ V_214 ] & V_21 ) {
T_4 V_216 = V_209 [ V_214 ++ ] ;
if ( V_213 & V_21 ) {
V_213 ^= V_216 ;
if ( ! V_213 )
return V_212 ;
}
} else if ( V_213 & V_21 )
break;
}
}
F_61 ( L_80 , V_142 ) ;
return - 1 ;
}
static int F_113 ( int V_212 , int V_217 )
{
if ( V_217 == 4 )
switch ( V_212 ) {
case 0x20 :
case 0x21 :
return 0 ;
break;
case 0x22 :
case 0x23 :
return 1 ;
break;
default:
return V_212 >> 4 ;
break;
}
else
switch ( V_212 ) {
case 0x10 :
F_114 ( 1 , V_218 L_81 ,
V_212 ) ;
return - 1 ;
break;
case 0x11 :
return 0 ;
break;
case 0x12 :
return 1 ;
break;
default:
return V_212 >> 3 ;
break;
}
return - 1 ;
}
static int F_76 ( struct V_25 * V_26 , T_4 V_142 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
int V_212 = - 1 ;
if ( V_9 -> V_89 == 8 )
V_212 = F_112 ( V_142 , V_219 ,
F_14 ( V_219 ) ,
V_9 -> V_89 ) ;
else if ( V_9 -> V_89 == 4 )
V_212 = F_112 ( V_142 , V_220 ,
F_14 ( V_220 ) ,
V_9 -> V_89 ) ;
else {
F_3 ( L_82 , V_9 -> V_89 ) ;
return V_212 ;
}
return F_113 ( V_212 , V_9 -> V_89 ) ;
}
static void F_115 ( struct V_25 * V_26 , struct V_116 * V_117 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
T_3 V_34 ;
T_4 V_142 ;
if ( ! ( V_117 -> V_221 & V_222 ) ) {
F_50 ( V_26 , L_83 ) ;
F_78 ( V_26 , V_147 ) ;
return;
}
V_34 = F_65 ( V_117 ) ;
V_142 = F_116 ( V_117 -> V_221 ) ;
F_50 ( V_26 , L_84 , V_34 ) ;
V_9 -> V_201 -> V_223 ( V_26 , V_34 , V_142 ) ;
}
static void F_117 ( struct V_25 * V_26 , struct V_116 * V_117 )
{
struct V_25 * V_224 , * V_143 = NULL ;
int V_43 ;
T_3 V_34 ;
T_1 V_73 , V_3 ;
V_224 = V_26 ;
if ( ! ( V_117 -> V_221 & V_222 ) ) {
F_50 ( V_26 , L_83 ) ;
F_118 ( V_224 , V_147 ) ;
return;
}
V_34 = F_65 ( V_117 ) ;
V_143 = F_21 ( V_26 , V_34 ) ;
if ( ! V_143 ) {
F_50 ( V_26 , L_85 ,
( unsigned long ) V_34 ) ;
F_118 ( V_224 , V_147 ) ;
return;
}
V_224 = V_143 ;
V_43 = F_49 ( V_224 , V_34 ) ;
if ( V_43 < 0 ) {
F_50 ( V_26 , L_86 ,
( unsigned long ) V_34 ) ;
F_118 ( V_224 , V_147 ) ;
} else {
F_48 ( V_34 , & V_73 , & V_3 ) ;
F_119 ( V_224 , V_73 , V_3 , V_43 , V_147 ) ;
}
}
static inline void F_120 ( struct V_25 * V_26 ,
struct V_116 * V_117 )
{
T_4 V_225 = F_121 ( V_117 -> V_221 ) ;
T_2 V_226 = F_122 ( V_117 -> V_221 , 0x1f ) ;
T_2 V_227 = ( V_117 -> V_221 >> 45 ) & 0x3 ;
if ( F_123 ( V_225 ) == V_228 )
return;
if ( V_226 && V_226 != V_229 )
return;
if ( V_227 == 2 )
F_115 ( V_26 , V_117 ) ;
else if ( V_227 == 1 )
F_117 ( V_26 , V_117 ) ;
}
void F_124 ( int V_36 , struct V_116 * V_117 )
{
F_120 ( V_127 [ V_36 ] , V_117 ) ;
}
static int F_125 ( struct V_8 * V_9 , T_4 V_230 , T_4 V_231 )
{
V_9 -> V_15 = F_109 ( V_9 -> V_12 -> V_203 , V_230 , V_9 -> V_12 ) ;
if ( ! V_9 -> V_15 ) {
F_126 ( L_87
L_88 ,
V_232 , V_230 ) ;
return - V_233 ;
}
V_9 -> V_32 = F_109 ( V_9 -> V_12 -> V_203 , V_231 , V_9 -> V_12 ) ;
if ( ! V_9 -> V_32 ) {
F_74 ( V_9 -> V_15 ) ;
V_9 -> V_15 = NULL ;
F_126 ( L_89
L_88 ,
V_232 , V_231 ) ;
return - V_233 ;
}
F_33 ( L_90 , F_127 ( V_9 -> V_15 ) ) ;
F_33 ( L_91 , F_127 ( V_9 -> V_12 ) ) ;
F_33 ( L_92 , F_127 ( V_9 -> V_32 ) ) ;
return 0 ;
}
static void F_128 ( struct V_8 * V_9 )
{
F_74 ( V_9 -> V_15 ) ;
F_74 ( V_9 -> V_32 ) ;
}
static void F_129 ( struct V_8 * V_9 )
{
struct V_118 * V_119 = & V_30 ;
T_3 V_234 ;
T_1 V_124 ;
unsigned V_130 ;
F_130 ( V_235 , V_9 -> V_236 ) ;
F_61 ( L_93 , V_9 -> V_236 ) ;
F_130 ( V_237 , V_234 ) ;
if ( V_234 & ( 1U << 21 ) ) {
F_130 ( V_238 , V_9 -> V_239 ) ;
F_61 ( L_94 , V_9 -> V_239 ) ;
} else
F_61 ( L_95 ) ;
F_10 ( V_9 -> V_32 , V_240 , & V_9 -> V_83 ) ;
F_87 ( V_9 ) ;
for ( V_130 = 0 ; V_130 < V_39 ; V_130 ++ ) {
T_2 V_241 ;
F_68 ( V_9 , V_130 ) ;
V_241 = F_69 ( V_9 , V_130 ) ;
if ( ! V_241 )
continue;
F_33 ( L_96 ,
V_130 ,
F_19 ( V_9 , V_130 ) ,
F_20 ( V_9 , V_130 ) ) ;
F_33 ( L_97 ,
F_22 ( V_9 , V_130 ) ? L_98 : L_99 ,
( V_241 & 0x1 ) ? L_100 : L_101 ,
( V_241 & 0x2 ) ? L_102 : L_101 ,
F_24 ( V_9 , V_130 ) ,
F_70 ( V_9 , V_130 ) ) ;
}
F_59 ( V_9 ) ;
F_10 ( V_9 -> V_15 , V_242 , & V_9 -> V_88 ) ;
F_60 ( V_9 , V_243 , & V_9 -> V_157 ) ;
F_10 ( V_9 -> V_32 , V_244 , & V_9 -> V_87 ) ;
F_60 ( V_9 , V_245 , & V_9 -> V_79 ) ;
F_60 ( V_9 , V_246 , & V_9 -> V_106 ) ;
if ( ! F_57 ( V_9 ) ) {
F_60 ( V_9 , V_247 , & V_9 -> V_90 ) ;
F_60 ( V_9 , V_248 , & V_9 -> V_159 ) ;
}
V_9 -> V_89 = 4 ;
if ( V_119 -> V_31 >= 0x10 ) {
F_10 ( V_9 -> V_32 , V_249 , & V_124 ) ;
F_60 ( V_9 , V_250 , & V_9 -> V_156 ) ;
if ( ( V_119 -> V_31 > 0x10 || V_119 -> V_182 > 7 ) && V_124 & F_52 ( 25 ) )
V_9 -> V_89 = 8 ;
}
F_54 ( V_9 ) ;
}
static T_1 F_131 ( struct V_8 * V_9 , T_2 V_13 , int V_251 )
{
T_1 V_150 , V_252 ;
T_1 V_155 = V_13 ? V_9 -> V_156 : V_9 -> V_157 ;
V_150 = ( V_155 >> ( ( V_251 / 2 ) * 4 ) ) & 0xF ;
V_252 = V_9 -> V_201 -> V_202 ( V_9 , V_13 , V_150 ) << ( 20 - V_74 ) ;
F_61 ( L_103 , V_251 , V_150 ) ;
F_61 ( L_104 ,
V_252 , V_9 -> V_253 ) ;
return V_252 ;
}
static int F_132 ( struct V_25 * V_26 )
{
struct V_254 * V_43 ;
struct V_8 * V_9 = V_26 -> V_28 ;
T_3 V_69 , V_70 , V_34 , V_44 , V_45 ;
T_1 V_4 ;
int V_21 , V_255 = 1 ;
F_10 ( V_9 -> V_32 , V_256 , & V_4 ) ;
V_9 -> V_145 = V_4 ;
F_61 ( L_105 ,
V_9 -> V_57 , V_4 ,
! ! ( V_4 & V_146 ) , ! ! ( V_4 & V_257 ) ) ;
F_30 (i, 0 , pvt) {
V_43 = & V_26 -> V_190 [ V_21 ] ;
if ( ! F_31 ( V_21 , 0 , V_9 ) && ! F_31 ( V_21 , 1 , V_9 ) ) {
F_33 ( L_106 , V_21 ,
V_9 -> V_57 ) ;
continue;
}
F_33 ( L_107 ,
V_21 , V_9 -> V_57 ) ;
V_255 = 0 ;
if ( F_31 ( V_21 , 0 , V_9 ) )
V_43 -> V_252 = F_131 ( V_9 , 0 , V_21 ) ;
if ( F_31 ( V_21 , 1 , V_9 ) )
V_43 -> V_252 += F_131 ( V_9 , 1 , V_21 ) ;
F_47 ( V_26 , V_21 , & V_69 , & V_70 ) ;
V_34 = F_46 ( V_26 , V_69 ) ;
V_43 -> V_258 = ( T_1 ) ( V_34 >> V_74 ) ;
V_34 = F_46 ( V_26 , V_70 ) ;
V_43 -> V_259 = ( T_1 ) ( V_34 >> V_74 ) ;
F_27 ( V_9 , V_21 , 0 , & V_44 , & V_45 ) ;
V_43 -> V_260 = ~ V_45 ;
V_43 -> V_261 = F_63 ( V_9 , V_21 ) ;
F_33 ( L_108 , V_9 -> V_57 , V_21 ) ;
F_33 ( L_109 ,
( unsigned long ) V_69 ,
( unsigned long ) V_70 ) ;
F_33 ( L_110 ,
( unsigned long ) V_34 , V_43 -> V_260 ) ;
F_33 ( L_111
L_112 ,
( unsigned ) V_43 -> V_252 ,
V_43 -> V_258 , V_43 -> V_259 ) ;
if ( V_9 -> V_145 & V_257 )
V_43 -> V_262 =
( V_9 -> V_145 & V_146 ) ?
V_263 : V_264 ;
else
V_43 -> V_262 = V_265 ;
}
return V_255 ;
}
static void F_133 ( struct V_266 * V_45 , unsigned V_35 )
{
int V_267 ;
F_134 (cpu)
if ( F_66 ( V_267 ) == V_35 )
F_135 ( V_267 , V_45 ) ;
}
static bool F_136 ( unsigned V_35 )
{
T_5 V_45 ;
int V_267 , V_268 ;
bool V_64 = false ;
if ( ! F_137 ( & V_45 , V_269 ) ) {
F_3 ( L_113 , V_42 ) ;
return false ;
}
F_133 ( V_45 , V_35 ) ;
F_138 ( V_45 , V_270 , V_271 ) ;
F_139 (cpu, mask) {
struct V_272 * V_14 = F_140 ( V_271 , V_267 ) ;
V_268 = V_14 -> V_273 & V_274 ;
F_61 ( L_114 ,
V_267 , V_14 -> V_275 ,
( V_268 ? L_34 : L_35 ) ) ;
if ( ! V_268 )
goto V_276;
}
V_64 = true ;
V_276:
F_141 ( V_45 ) ;
return V_64 ;
}
static int F_142 ( struct V_277 * V_213 , T_2 V_35 , bool V_278 )
{
T_5 V_279 ;
int V_267 ;
if ( ! F_137 ( & V_279 , V_269 ) ) {
F_3 ( L_115 , V_42 ) ;
return false ;
}
F_133 ( V_279 , V_35 ) ;
F_138 ( V_279 , V_270 , V_271 ) ;
F_139 (cpu, cmask) {
struct V_272 * V_14 = F_140 ( V_271 , V_267 ) ;
if ( V_278 ) {
if ( V_14 -> V_273 & V_274 )
V_213 -> V_280 . V_281 = 1 ;
V_14 -> V_273 |= V_274 ;
} else {
if ( ! V_213 -> V_280 . V_281 )
V_14 -> V_273 &= ~ V_274 ;
}
}
F_143 ( V_279 , V_270 , V_271 ) ;
F_141 ( V_279 ) ;
return 0 ;
}
static bool F_144 ( struct V_277 * V_213 , T_2 V_35 ,
struct V_1 * V_32 )
{
bool V_64 = true ;
T_1 V_282 , V_45 = 0x3 ;
if ( F_142 ( V_213 , V_35 , V_283 ) ) {
F_3 ( L_116 ) ;
return false ;
}
F_10 ( V_32 , V_284 , & V_282 ) ;
V_213 -> V_285 = V_282 & V_45 ;
V_213 -> V_286 = true ;
V_282 |= V_45 ;
F_11 ( V_32 , V_284 , V_282 ) ;
F_10 ( V_32 , V_256 , & V_282 ) ;
F_61 ( L_117 ,
V_35 , V_282 , ! ! ( V_282 & V_257 ) ) ;
if ( ! ( V_282 & V_257 ) ) {
F_3 ( L_118 ) ;
V_213 -> V_280 . V_287 = 0 ;
V_282 |= V_257 ;
F_11 ( V_32 , V_256 , V_282 ) ;
F_10 ( V_32 , V_256 , & V_282 ) ;
if ( ! ( V_282 & V_257 ) ) {
F_3 ( L_119
L_120 ) ;
V_64 = false ;
} else {
F_56 ( L_121 ) ;
}
} else {
V_213 -> V_280 . V_287 = 1 ;
}
F_61 ( L_122 ,
V_35 , V_282 , ! ! ( V_282 & V_257 ) ) ;
return V_64 ;
}
static void F_145 ( struct V_277 * V_213 , T_2 V_35 ,
struct V_1 * V_32 )
{
T_1 V_282 , V_45 = 0x3 ;
if ( ! V_213 -> V_286 )
return;
F_10 ( V_32 , V_284 , & V_282 ) ;
V_282 &= ~ V_45 ;
V_282 |= V_213 -> V_285 ;
F_11 ( V_32 , V_284 , V_282 ) ;
if ( ! V_213 -> V_280 . V_287 ) {
F_10 ( V_32 , V_256 , & V_282 ) ;
V_282 &= ~ V_257 ;
F_11 ( V_32 , V_256 , V_282 ) ;
}
if ( F_142 ( V_213 , V_35 , V_288 ) )
F_3 ( L_123 ) ;
}
static bool F_146 ( struct V_1 * V_32 , T_2 V_35 )
{
T_1 V_282 ;
T_2 V_289 = 0 ;
bool V_290 = false ;
F_10 ( V_32 , V_256 , & V_282 ) ;
V_289 = ! ! ( V_282 & V_257 ) ;
F_56 ( L_124 , ( V_289 ? L_34 : L_35 ) ) ;
V_290 = F_136 ( V_35 ) ;
if ( ! V_290 )
F_147 ( L_125
L_126 ,
V_270 , V_35 ) ;
if ( ! V_289 || ! V_290 ) {
F_147 ( L_127 , V_291 ) ;
return false ;
}
return true ;
}
static void F_148 ( struct V_25 * V_26 )
{
unsigned int V_21 = 0 , V_153 = 0 ;
for (; V_21 < F_14 ( V_292 ) ; V_21 ++ )
V_293 [ V_21 ] = V_292 [ V_21 ] ;
if ( V_30 . V_31 >= 0x10 )
for ( V_153 = 0 ; V_153 < F_14 ( V_294 ) ; V_153 ++ , V_21 ++ )
V_293 [ V_21 ] = V_294 [ V_153 ] ;
V_293 [ V_21 ] = V_295 ;
V_26 -> V_296 = V_293 ;
}
static void F_149 ( struct V_25 * V_26 ,
struct V_297 * V_298 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
V_26 -> V_299 = V_300 | V_301 ;
V_26 -> V_302 = V_78 ;
if ( V_9 -> V_83 & V_85 )
V_26 -> V_302 |= V_80 ;
if ( V_9 -> V_83 & V_86 )
V_26 -> V_302 |= V_303 ;
V_26 -> V_77 = F_51 ( V_9 ) ;
V_26 -> V_304 = V_147 ;
V_26 -> V_305 = V_306 ;
V_26 -> V_307 = V_298 -> V_307 ;
V_26 -> V_308 = F_127 ( V_9 -> V_12 ) ;
V_26 -> V_309 = NULL ;
V_26 -> V_310 = F_16 ;
V_26 -> V_311 = F_17 ;
}
static struct V_297 * F_150 ( struct V_8 * V_9 )
{
T_2 V_298 = V_30 . V_31 ;
struct V_297 * V_312 = NULL ;
switch ( V_298 ) {
case 0xf :
V_312 = & V_313 [ V_314 ] ;
V_9 -> V_201 = & V_313 [ V_314 ] . V_201 ;
break;
case 0x10 :
V_312 = & V_313 [ V_315 ] ;
V_9 -> V_201 = & V_313 [ V_315 ] . V_201 ;
break;
case 0x15 :
V_312 = & V_313 [ V_316 ] ;
V_9 -> V_201 = & V_313 [ V_316 ] . V_201 ;
break;
default:
F_126 ( L_128 ) ;
return NULL ;
}
V_9 -> V_51 = V_30 . V_182 >> 4 ;
F_56 ( L_129 , V_312 -> V_307 ,
( V_298 == 0xf ?
( V_9 -> V_51 >= V_52 ? L_130
: L_131 )
: L_30 ) , V_9 -> V_57 ) ;
return V_312 ;
}
static int F_151 ( struct V_1 * V_12 )
{
struct V_8 * V_9 = NULL ;
struct V_297 * V_312 = NULL ;
struct V_25 * V_26 = NULL ;
int V_6 = 0 , V_64 ;
T_2 V_35 = F_152 ( V_12 ) ;
V_64 = - V_317 ;
V_9 = F_153 ( sizeof( struct V_8 ) , V_269 ) ;
if ( ! V_9 )
goto V_318;
V_9 -> V_57 = V_35 ;
V_9 -> V_12 = V_12 ;
V_64 = - V_11 ;
V_312 = F_150 ( V_9 ) ;
if ( ! V_312 )
goto V_319;
V_64 = - V_233 ;
V_6 = F_125 ( V_9 , V_312 -> V_230 , V_312 -> V_231 ) ;
if ( V_6 )
goto V_319;
F_129 ( V_9 ) ;
V_64 = - V_11 ;
V_9 -> V_253 = V_9 -> V_201 -> V_320 ( V_9 ) ;
if ( V_9 -> V_253 < 0 )
goto V_321;
V_64 = - V_317 ;
V_26 = F_154 ( 0 , V_9 -> V_53 [ 0 ] . V_71 , V_9 -> V_253 , V_35 ) ;
if ( ! V_26 )
goto V_321;
V_26 -> V_28 = V_9 ;
V_26 -> V_206 = & V_9 -> V_12 -> V_206 ;
F_149 ( V_26 , V_312 ) ;
if ( F_132 ( V_26 ) )
V_26 -> V_77 = V_78 ;
F_148 ( V_26 ) ;
V_64 = - V_233 ;
if ( F_155 ( V_26 ) ) {
F_33 ( L_132 ) ;
goto V_322;
}
if ( V_323 )
F_156 ( true ) ;
F_157 ( F_124 ) ;
V_127 [ V_35 ] = V_26 ;
F_158 ( & V_324 ) ;
return 0 ;
V_322:
F_159 ( V_26 ) ;
V_321:
F_128 ( V_9 ) ;
V_319:
F_160 ( V_9 ) ;
V_318:
return V_64 ;
}
static int T_6 F_161 ( struct V_1 * V_2 ,
const struct V_325 * V_326 )
{
T_2 V_35 = F_152 ( V_2 ) ;
struct V_1 * V_32 = F_162 ( V_35 ) -> V_327 ;
struct V_277 * V_213 ;
int V_64 = 0 ;
V_64 = F_163 ( V_2 ) ;
if ( V_64 < 0 ) {
F_61 ( L_133 , V_64 ) ;
return - V_328 ;
}
V_64 = - V_317 ;
V_213 = F_153 ( sizeof( struct V_277 ) , V_269 ) ;
if ( ! V_213 )
goto V_329;
V_330 [ V_35 ] = V_213 ;
if ( ! F_146 ( V_32 , V_35 ) ) {
V_64 = - V_233 ;
if ( ! V_331 )
goto V_332;
F_3 ( L_134 ) ;
if ( ! F_144 ( V_213 , V_35 , V_32 ) )
goto V_332;
}
V_64 = F_151 ( V_2 ) ;
if ( V_64 < 0 ) {
F_126 ( L_135 , V_35 ) ;
F_145 ( V_213 , V_35 , V_32 ) ;
}
return V_64 ;
V_332:
F_160 ( V_213 ) ;
V_330 [ V_35 ] = NULL ;
V_329:
return V_64 ;
}
static void T_7 F_164 ( struct V_1 * V_2 )
{
struct V_25 * V_26 ;
struct V_8 * V_9 ;
T_2 V_35 = F_152 ( V_2 ) ;
struct V_1 * V_32 = F_162 ( V_35 ) -> V_327 ;
struct V_277 * V_213 = V_330 [ V_35 ] ;
V_26 = F_165 ( & V_2 -> V_206 ) ;
if ( ! V_26 )
return;
V_9 = V_26 -> V_28 ;
F_145 ( V_213 , V_35 , V_32 ) ;
F_128 ( V_9 ) ;
F_156 ( false ) ;
F_166 ( F_124 ) ;
F_160 ( V_330 [ V_35 ] ) ;
V_330 [ V_35 ] = NULL ;
V_26 -> V_28 = NULL ;
V_127 [ V_35 ] = NULL ;
F_160 ( V_9 ) ;
F_159 ( V_26 ) ;
}
static void F_167 ( void )
{
struct V_25 * V_26 ;
struct V_8 * V_9 ;
if ( V_333 )
return;
V_26 = V_127 [ 0 ] ;
if ( V_26 ) {
V_9 = V_26 -> V_28 ;
V_333 =
F_168 ( & V_9 -> V_12 -> V_206 , V_147 ) ;
if ( ! V_333 ) {
F_169 ( L_136 ,
V_42 ) ;
F_169 ( L_137 ,
V_42 ) ;
}
}
}
static int T_8 F_170 ( void )
{
int V_6 = - V_233 ;
F_171 ( V_334 L_138 , V_306 ) ;
F_172 () ;
if ( F_173 () < 0 )
goto V_318;
V_6 = - V_317 ;
V_127 = F_153 ( F_174 () * sizeof( V_127 [ 0 ] ) , V_269 ) ;
V_330 = F_153 ( F_174 () * sizeof( V_330 [ 0 ] ) , V_269 ) ;
if ( ! ( V_127 && V_330 ) )
goto V_319;
V_271 = F_175 () ;
if ( ! V_271 )
goto V_319;
V_6 = F_176 ( & V_335 ) ;
if ( V_6 )
goto V_336;
V_6 = - V_233 ;
if ( ! F_177 ( & V_324 ) )
goto V_337;
F_167 () ;
return 0 ;
V_337:
F_178 ( & V_335 ) ;
V_336:
F_179 ( V_271 ) ;
V_271 = NULL ;
V_319:
F_160 ( V_127 ) ;
V_127 = NULL ;
F_160 ( V_330 ) ;
V_330 = NULL ;
V_318:
return V_6 ;
}
static void T_9 F_180 ( void )
{
if ( V_333 )
F_181 ( V_333 ) ;
F_178 ( & V_335 ) ;
F_160 ( V_330 ) ;
V_330 = NULL ;
F_160 ( V_127 ) ;
V_127 = NULL ;
F_179 ( V_271 ) ;
V_271 = NULL ;
}
