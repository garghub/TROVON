int F_1 ( struct V_1 * V_2 , int V_3 ,
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
for ( V_21 = 0 ; V_21 < F_14 ( V_22 ) - 1 ; V_21 ++ ) {
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
F_26 ( 2 , L_6 ,
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
F_26 ( 2 , L_7 ,
( unsigned long ) V_56 , V_43 ,
V_9 -> V_57 ) ;
return V_43 ;
}
}
F_26 ( 2 , L_8 ,
( unsigned long ) V_56 , V_9 -> V_57 ) ;
return - 1 ;
}
int F_32 ( struct V_25 * V_26 , T_3 * V_58 ,
T_3 * V_59 , T_3 * V_60 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
if ( V_30 . V_31 == 0xf && V_9 -> V_51 < V_61 ) {
F_26 ( 1 , L_9 ,
V_9 -> V_51 , V_9 -> V_57 ) ;
return 1 ;
}
if ( V_30 . V_31 >= 0x10 && ! F_33 ( V_9 ) ) {
F_26 ( 1 , L_10 ) ;
return 1 ;
}
if ( ! F_34 ( V_9 ) ) {
F_26 ( 1 , L_11 ,
V_9 -> V_57 ) ;
return 1 ;
}
* V_58 = F_35 ( V_9 ) ;
* V_60 = ( 1ULL << 32 ) - * V_58 ;
if ( V_30 . V_31 > 0xf )
* V_59 = F_36 ( V_9 ) ;
else
* V_59 = F_37 ( V_9 ) ;
F_26 ( 1 , L_12 ,
V_9 -> V_57 , ( unsigned long ) * V_58 ,
( unsigned long ) * V_59 , ( unsigned long ) * V_60 ) ;
return 0 ;
}
static T_3 F_38 ( struct V_25 * V_26 , T_3 V_34 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
T_3 V_62 , V_58 , V_59 , V_60 , V_63 ;
int V_64 ;
V_62 = F_19 ( V_9 , V_9 -> V_57 ) ;
V_64 = F_32 ( V_26 , & V_58 , & V_59 ,
& V_60 ) ;
if ( ! V_64 ) {
if ( ( V_34 >= ( 1ULL << 32 ) ) &&
( V_34 < ( ( 1ULL << 32 ) + V_60 ) ) ) {
V_63 = V_34 - V_59 ;
F_26 ( 2 , L_13 ,
( unsigned long ) V_34 ,
( unsigned long ) V_63 ) ;
return V_63 ;
}
}
V_63 = ( V_34 & F_28 ( 0 , 39 ) ) - V_62 ;
F_26 ( 2 , L_14 ,
( unsigned long ) V_34 , ( unsigned long ) V_63 ) ;
return V_63 ;
}
static int F_39 ( unsigned V_37 )
{
static const int V_65 [] = { 0 , 1 , 0 , 2 , 0 , 0 , 0 , 3 } ;
int V_66 ;
F_40 ( V_37 > 7 ) ;
V_66 = V_65 [ V_37 ] ;
return V_66 ;
}
static T_3 F_41 ( struct V_25 * V_26 , T_3 V_63 )
{
struct V_8 * V_9 ;
int V_67 ;
T_3 V_56 ;
V_9 = V_26 -> V_28 ;
V_67 = F_39 ( F_22 ( V_9 , 0 ) ) ;
V_56 = ( ( V_63 >> V_67 ) & F_28 ( 12 , 35 ) ) +
( V_63 & 0xfff ) ;
F_26 ( 2 , L_15 ,
V_67 , ( unsigned long ) V_63 ,
( unsigned long ) V_56 ) ;
return V_56 ;
}
static T_3 F_42 ( struct V_25 * V_26 , T_3 V_34 )
{
T_3 V_56 ;
V_56 =
F_41 ( V_26 , F_38 ( V_26 , V_34 ) ) ;
F_26 ( 2 , L_16 ,
( unsigned long ) V_34 , ( unsigned long ) V_56 ) ;
return V_56 ;
}
static T_3 F_43 ( struct V_25 * V_26 , T_3 V_56 )
{
struct V_8 * V_9 ;
unsigned V_36 , V_67 ;
T_3 V_38 , V_63 ;
T_1 V_68 ;
V_9 = V_26 -> V_28 ;
V_36 = V_9 -> V_57 ;
F_40 ( V_36 > 7 ) ;
V_67 = F_39 ( F_22 ( V_9 , 0 ) ) ;
if ( V_67 == 0 ) {
F_26 ( 1 , L_17 ,
( unsigned long ) V_56 ) ;
return V_56 ;
}
V_38 = ( ( V_56 & F_28 ( 12 , 35 ) ) << V_67 ) +
( V_56 & 0xfff ) ;
V_68 = F_24 ( V_9 , V_36 ) & ( ( 1 << V_67 ) - 1 ) ;
V_63 = V_38 + ( V_68 << 12 ) ;
F_26 ( 1 , L_18 ,
( unsigned long ) V_56 ,
( unsigned long ) V_63 , V_67 ) ;
return V_63 ;
}
static T_3 F_44 ( struct V_25 * V_26 , T_3 V_63 )
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
F_26 ( 1 , L_19 ,
( unsigned long ) V_63 ,
( unsigned long ) V_34 ) ;
return V_34 ;
}
}
V_44 = F_19 ( V_9 , V_9 -> V_57 ) ;
V_34 = V_63 + V_44 ;
V_34 |= ~ ( ( V_34 & ( 1ull << 39 ) ) - 1 ) ;
F_26 ( 1 , L_20 ,
V_9 -> V_57 , ( unsigned long ) V_63 ,
( unsigned long ) V_34 ) ;
return V_34 ;
}
static inline T_3 F_45 ( struct V_25 * V_26 ,
T_3 V_56 )
{
return F_44 ( V_26 ,
F_43 ( V_26 , V_56 ) ) ;
}
static inline void F_46 ( T_3 V_69 ,
struct V_70 * V_6 )
{
V_6 -> V_71 = ( T_1 ) ( V_69 >> V_72 ) ;
V_6 -> V_3 = ( ( T_1 ) V_69 ) & ~ V_73 ;
}
static int F_47 ( struct V_25 * V_26 , T_3 V_34 )
{
int V_43 ;
V_43 = F_29 ( V_26 , F_42 ( V_26 , V_34 ) ) ;
if ( V_43 == - 1 )
F_48 ( V_26 , L_21
L_22 , ( unsigned long ) V_34 ) ;
return V_43 ;
}
static unsigned long F_49 ( struct V_8 * V_9 )
{
T_2 V_74 ;
unsigned long V_75 = V_76 ;
V_74 = ( V_30 . V_31 > 0xf || V_9 -> V_51 >= V_52 )
? 19
: 17 ;
if ( V_9 -> V_77 & F_50 ( V_74 ) )
V_75 = V_78 ;
return V_75 ;
}
static void F_51 ( T_1 V_79 , int V_80 )
{
F_26 ( 1 , L_23 , V_80 , V_79 ) ;
F_26 ( 1 , L_24 ,
( V_79 & F_50 ( 16 ) ) ? L_25 : L_26 ,
( V_79 & F_50 ( 19 ) ) ? L_27 : L_28 ) ;
F_26 ( 1 , L_29 ,
( V_79 & F_50 ( 8 ) ) ? L_30 : L_31 ) ;
if ( V_30 . V_31 == 0x10 )
F_26 ( 1 , L_32 ,
( V_79 & F_50 ( 11 ) ) ? L_33 : L_34 ) ;
F_26 ( 1 , L_35 ,
( V_79 & F_50 ( 12 ) ) ? L_27 : L_28 ,
( V_79 & F_50 ( 13 ) ) ? L_27 : L_28 ,
( V_79 & F_50 ( 14 ) ) ? L_27 : L_28 ,
( V_79 & F_50 ( 15 ) ) ? L_27 : L_28 ) ;
}
static void F_52 ( struct V_8 * V_9 )
{
F_26 ( 1 , L_36 , V_9 -> V_81 ) ;
F_26 ( 1 , L_37 ,
( V_9 -> V_81 & V_82 ) ? L_27 : L_28 ) ;
F_26 ( 1 , L_38 ,
( V_9 -> V_81 & V_83 ) ? L_27 : L_28 ,
( V_9 -> V_81 & V_84 ) ? L_27 : L_28 ) ;
F_51 ( V_9 -> V_77 , 0 ) ;
F_26 ( 1 , L_39 , V_9 -> V_85 ) ;
F_26 ( 1 , L_40 ,
V_9 -> V_86 , F_35 ( V_9 ) ,
( V_30 . V_31 == 0xf ) ? F_37 ( V_9 )
: F_36 ( V_9 ) ) ;
F_26 ( 1 , L_41 , F_34 ( V_9 ) ? L_27 : L_28 ) ;
F_53 ( V_9 , 0 ) ;
if ( V_30 . V_31 == 0xf )
return;
F_53 ( V_9 , 1 ) ;
F_54 ( L_42 , ( ( V_9 -> V_87 == 8 ) ? L_43 : L_44 ) ) ;
if ( ! F_55 ( V_9 ) )
F_51 ( V_9 -> V_88 , 1 ) ;
}
static void F_56 ( struct V_8 * V_9 )
{
if ( V_30 . V_31 == 0xf && V_9 -> V_51 < V_52 ) {
V_9 -> V_53 [ 0 ] . V_89 = V_9 -> V_53 [ 1 ] . V_89 = 8 ;
V_9 -> V_53 [ 0 ] . V_90 = V_9 -> V_53 [ 1 ] . V_90 = 8 ;
} else {
V_9 -> V_53 [ 0 ] . V_89 = V_9 -> V_53 [ 1 ] . V_89 = 8 ;
V_9 -> V_53 [ 0 ] . V_90 = V_9 -> V_53 [ 1 ] . V_90 = 4 ;
}
}
static void F_57 ( struct V_8 * V_9 )
{
int V_91 ;
F_56 ( V_9 ) ;
F_30 (cs, 0 , pvt) {
int V_92 = V_93 + ( V_91 * 4 ) ;
int V_94 = V_95 + ( V_91 * 4 ) ;
T_1 * V_96 = & V_9 -> V_53 [ 0 ] . V_54 [ V_91 ] ;
T_1 * V_97 = & V_9 -> V_53 [ 1 ] . V_54 [ V_91 ] ;
if ( ! F_58 ( V_9 , V_92 , V_96 ) )
F_26 ( 0 , L_45 ,
V_91 , * V_96 , V_92 ) ;
if ( V_30 . V_31 == 0xf || F_55 ( V_9 ) )
continue;
if ( ! F_58 ( V_9 , V_94 , V_97 ) )
F_26 ( 0 , L_46 ,
V_91 , * V_97 , V_94 ) ;
}
F_59 (cs, 0 , pvt) {
int V_92 = V_98 + ( V_91 * 4 ) ;
int V_94 = V_99 + ( V_91 * 4 ) ;
T_1 * V_100 = & V_9 -> V_53 [ 0 ] . V_55 [ V_91 ] ;
T_1 * V_101 = & V_9 -> V_53 [ 1 ] . V_55 [ V_91 ] ;
if ( ! F_58 ( V_9 , V_92 , V_100 ) )
F_26 ( 0 , L_47 ,
V_91 , * V_100 , V_92 ) ;
if ( V_30 . V_31 == 0xf || F_55 ( V_9 ) )
continue;
if ( ! F_58 ( V_9 , V_94 , V_101 ) )
F_26 ( 0 , L_48 ,
V_91 , * V_101 , V_94 ) ;
}
}
static enum V_102 F_60 ( struct V_8 * V_9 , int V_91 )
{
enum V_102 type ;
if ( V_30 . V_31 >= 0x15 )
type = ( V_9 -> V_77 & F_50 ( 16 ) ) ? V_103 : V_104 ;
else if ( V_30 . V_31 == 0x10 || V_9 -> V_51 >= V_52 ) {
if ( V_9 -> V_105 & V_106 )
type = ( V_9 -> V_77 & F_50 ( 16 ) ) ? V_103 : V_104 ;
else
type = ( V_9 -> V_77 & F_50 ( 16 ) ) ? V_107 : V_108 ;
} else {
type = ( V_9 -> V_77 & F_50 ( 18 ) ) ? V_109 : V_110 ;
}
F_54 ( L_49 , V_91 , V_111 [ type ] ) ;
return type ;
}
static int F_61 ( struct V_8 * V_9 )
{
int V_112 ;
if ( V_9 -> V_51 >= V_52 )
V_112 = V_9 -> V_77 & V_113 ;
else
V_112 = V_9 -> V_77 & V_114 ;
V_9 -> V_88 = 0 ;
return ( V_112 ) ? 2 : 1 ;
}
static T_3 F_62 ( struct V_115 * V_116 )
{
struct V_117 * V_118 = & V_30 ;
T_3 V_10 ;
T_2 V_119 = 1 ;
T_2 V_120 = 47 ;
if ( V_118 -> V_31 == 0xf ) {
V_119 = 3 ;
V_120 = 39 ;
}
V_10 = V_116 -> V_10 & F_28 ( V_119 , V_120 ) ;
if ( V_118 -> V_31 == 0x15 ) {
struct V_8 * V_9 ;
T_3 V_121 , V_122 ;
T_1 V_123 ;
T_2 V_124 , V_37 ;
if ( ( V_10 & F_28 ( 24 , 47 ) ) >> 24 != 0x00fdf7 )
return V_10 ;
V_124 = F_63 ( V_116 -> V_125 ) ;
V_9 = V_126 [ V_124 ] -> V_28 ;
F_10 ( V_9 -> V_15 , V_127 , & V_123 ) ;
V_37 = V_123 >> 21 & 0x7 ;
V_121 = ( V_123 & F_28 ( 0 , 20 ) ) << 3 ;
V_121 |= V_37 ^ 0x7 ;
V_121 <<= 24 ;
if ( ! V_37 )
return V_121 | ( V_10 & F_28 ( 0 , 23 ) ) ;
F_10 ( V_9 -> V_15 , V_128 , & V_123 ) ;
V_122 = ( V_10 & F_28 ( 12 , 23 ) ) << F_64 ( V_37 + 1 ) ;
V_122 |= ( V_123 & F_28 ( 21 , 23 ) ) >> 9 ;
V_122 |= V_10 & F_28 ( 0 , 11 ) ;
return V_121 | V_122 ;
}
return V_10 ;
}
static void F_65 ( struct V_8 * V_9 , unsigned V_129 )
{
struct V_117 * V_118 = & V_30 ;
int V_130 = V_129 << 3 ;
F_10 ( V_9 -> V_15 , V_131 + V_130 , & V_9 -> V_132 [ V_129 ] . V_44 . V_133 ) ;
F_10 ( V_9 -> V_15 , V_134 + V_130 , & V_9 -> V_132 [ V_129 ] . V_135 . V_133 ) ;
if ( V_118 -> V_31 == 0xf )
return;
if ( ! F_66 ( V_9 , V_129 ) )
return;
F_10 ( V_9 -> V_15 , V_136 + V_130 , & V_9 -> V_132 [ V_129 ] . V_44 . V_137 ) ;
F_10 ( V_9 -> V_15 , V_138 + V_130 , & V_9 -> V_132 [ V_129 ] . V_135 . V_137 ) ;
if ( V_118 -> V_31 == 0x15 ) {
struct V_1 * V_139 = NULL ;
T_2 V_35 = F_67 ( V_9 , V_129 ) ;
T_1 V_140 ;
V_139 = F_68 ( 0 , 0 , F_69 ( 0x18 + V_35 , 1 ) ) ;
if ( F_70 ( ! V_139 ) )
return;
F_10 ( V_139 , V_127 , & V_140 ) ;
V_9 -> V_132 [ V_129 ] . V_135 . V_133 &= F_28 ( 0 , 15 ) ;
V_9 -> V_132 [ V_129 ] . V_135 . V_133 |= ( ( V_140 & 0x1fff ) << 3 | 0x7 ) << 16 ;
V_9 -> V_132 [ V_129 ] . V_135 . V_137 &= F_28 ( 0 , 7 ) ;
V_9 -> V_132 [ V_129 ] . V_135 . V_137 |= V_140 >> 13 ;
F_71 ( V_139 ) ;
}
}
static void F_72 ( struct V_25 * V_26 , T_3 V_34 ,
struct V_70 * V_6 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
F_46 ( V_34 , V_6 ) ;
V_6 -> V_141 = F_21 ( V_26 , V_34 ) ;
if ( ! V_6 -> V_141 ) {
F_48 ( V_26 , L_50 ,
( unsigned long ) V_34 ) ;
V_6 -> V_142 = V_143 ;
return;
}
V_6 -> V_43 = F_47 ( V_6 -> V_141 , V_34 ) ;
if ( V_6 -> V_43 < 0 ) {
V_6 -> V_142 = V_144 ;
return;
}
if ( V_9 -> V_145 & V_146 ) {
V_6 -> V_147 = F_73 ( V_26 , V_6 -> V_148 ) ;
if ( V_6 -> V_147 < 0 ) {
F_74 ( V_6 -> V_141 , L_51
L_52 ,
V_6 -> V_148 ) ;
V_6 -> V_142 = V_149 ;
return;
}
} else {
V_6 -> V_147 = ( ( V_34 & F_50 ( 3 ) ) != 0 ) ;
}
}
static int F_75 ( unsigned V_21 , bool V_150 )
{
unsigned V_151 = 0 ;
if ( V_21 <= 2 )
V_151 = V_21 ;
else if ( ! ( V_21 & 0x1 ) )
V_151 = V_21 >> 1 ;
else
V_151 = ( V_21 + 1 ) >> 1 ;
return 128 << ( V_151 + ! ! V_150 ) ;
}
static int F_76 ( struct V_8 * V_9 , T_2 V_13 ,
unsigned V_152 )
{
T_1 V_79 = V_13 ? V_9 -> V_88 : V_9 -> V_77 ;
if ( V_9 -> V_51 >= V_52 ) {
F_70 ( V_152 > 11 ) ;
return F_75 ( V_152 , V_79 & V_113 ) ;
}
else if ( V_9 -> V_51 >= V_153 ) {
unsigned V_154 ;
F_70 ( V_152 > 10 ) ;
V_154 = V_152 / 3 + ( unsigned ) ( V_152 > 5 ) ;
return 32 << ( V_152 - V_154 ) ;
}
else {
F_70 ( V_152 > 6 ) ;
return 32 << V_152 ;
}
}
static int F_77 ( struct V_8 * V_9 )
{
int V_21 , V_155 , V_156 = 0 ;
if ( V_30 . V_31 == 0x10 && ( V_9 -> V_77 & V_113 ) )
return 2 ;
F_26 ( 0 , L_53 ) ;
for ( V_21 = 0 ; V_21 < 2 ; V_21 ++ ) {
T_1 V_157 = ( V_21 ? V_9 -> V_158 : V_9 -> V_159 ) ;
for ( V_155 = 0 ; V_155 < 4 ; V_155 ++ ) {
if ( F_78 ( V_155 , V_157 ) > 0 ) {
V_156 ++ ;
break;
}
}
}
if ( V_156 > 2 )
V_156 = 2 ;
F_54 ( L_54 , V_156 ) ;
return V_156 ;
}
static int F_79 ( unsigned V_21 , bool V_150 )
{
unsigned V_151 = 0 ;
int V_160 = 0 ;
if ( V_21 == 0 || V_21 == 3 || V_21 == 4 )
V_160 = - 1 ;
else if ( V_21 <= 2 )
V_151 = V_21 ;
else if ( V_21 == 12 )
V_151 = 7 ;
else if ( ! ( V_21 & 0x1 ) )
V_151 = V_21 >> 1 ;
else
V_151 = ( V_21 + 1 ) >> 1 ;
if ( V_160 != - 1 )
V_160 = ( 128 * ( 1 << ! ! V_150 ) ) << V_151 ;
return V_160 ;
}
static int F_80 ( struct V_8 * V_9 , T_2 V_13 ,
unsigned V_152 )
{
T_1 V_79 = V_13 ? V_9 -> V_88 : V_9 -> V_77 ;
F_70 ( V_152 > 11 ) ;
if ( V_9 -> V_105 & V_106 || V_9 -> V_161 & V_106 )
return F_79 ( V_152 , V_79 & V_113 ) ;
else
return F_75 ( V_152 , V_79 & V_113 ) ;
}
static int F_81 ( struct V_8 * V_9 , T_2 V_13 ,
unsigned V_152 )
{
F_70 ( V_152 > 12 ) ;
return F_79 ( V_152 , false ) ;
}
static void F_82 ( struct V_8 * V_9 )
{
if ( V_30 . V_31 == 0xf )
return;
if ( ! F_58 ( V_9 , V_162 , & V_9 -> V_163 ) ) {
F_26 ( 0 , L_55 ,
V_9 -> V_163 , F_83 ( V_9 ) ) ;
F_26 ( 0 , L_56 ,
( F_55 ( V_9 ) ? L_57 : L_58 ) ) ;
if ( ! F_55 ( V_9 ) )
F_26 ( 0 , L_59 ,
( F_84 ( V_9 ) ? L_27 : L_28 ) ) ;
F_26 ( 0 , L_60 ,
( F_85 ( V_9 ) ? L_30 : L_31 ) ,
( F_86 ( V_9 ) ? L_27 : L_28 ) ) ;
F_26 ( 0 , L_61
L_62 ,
( F_87 ( V_9 ) ? L_30 : L_31 ) ,
F_88 ( V_9 ) ) ;
}
F_58 ( V_9 , V_164 , & V_9 -> V_165 ) ;
}
static T_2 F_89 ( struct V_8 * V_9 , T_3 V_34 ,
bool V_166 , T_2 V_37 )
{
T_2 V_167 = ( V_9 -> V_163 >> 1 ) & 1 ;
if ( F_55 ( V_9 ) )
return 0 ;
if ( V_166 )
return V_167 ;
if ( F_87 ( V_9 ) ) {
T_2 V_168 = F_88 ( V_9 ) ;
if ( ! V_168 )
return V_34 >> 6 & 1 ;
if ( V_168 & 0x2 ) {
T_2 V_151 = V_168 & 0x1 ? 9 : 6 ;
T_1 V_169 = F_90 ( ( T_1 ) ( ( V_34 >> 16 ) & 0x1F ) ) % 2 ;
return ( ( V_34 >> V_151 ) & 1 ) ^ V_169 ;
}
return ( V_34 >> ( 12 + F_91 ( V_37 ) ) ) & 1 ;
}
if ( F_84 ( V_9 ) )
return ~ V_167 & 1 ;
return 0 ;
}
static T_3 F_92 ( struct V_8 * V_9 , unsigned V_129 ,
T_3 V_34 , bool V_170 ,
T_1 V_171 )
{
T_3 V_172 ;
T_3 V_62 = F_19 ( V_9 , V_129 ) ;
T_3 V_173 = F_36 ( V_9 ) ;
T_3 V_174 = ( V_9 -> V_165 & 0xFFFFFC00 ) << 16 ;
if ( V_170 ) {
if ( ( ! ( V_171 >> 16 ) ||
V_171 < F_35 ( V_9 ) ) &&
F_34 ( V_9 ) &&
( V_34 >= F_93 ( 32 ) ) )
V_172 = V_173 ;
else
V_172 = V_174 ;
} else {
if ( F_34 ( V_9 ) && ( V_34 >= F_93 ( 32 ) ) )
V_172 = V_173 ;
else
V_172 = V_62 ;
}
return ( V_34 & F_28 ( 6 , 47 ) ) - ( V_172 & F_28 ( 23 , 47 ) ) ;
}
static int F_94 ( struct V_8 * V_9 , T_2 V_13 , int V_43 )
{
int V_175 ;
if ( F_95 ( V_9 , V_13 ) &&
V_43 == F_96 ( V_9 , V_13 ) ) {
F_30 (tmp_cs, dct, pvt) {
if ( F_97 ( V_175 , V_13 , V_9 ) & 0x2 ) {
V_43 = V_175 ;
break;
}
}
}
return V_43 ;
}
static int F_98 ( T_3 V_176 , T_1 V_35 , T_2 V_13 )
{
struct V_25 * V_26 ;
struct V_8 * V_9 ;
T_3 V_177 , V_178 ;
int V_179 = - V_11 ;
int V_43 ;
V_26 = V_126 [ V_35 ] ;
if ( ! V_26 )
return V_179 ;
V_9 = V_26 -> V_28 ;
F_26 ( 1 , L_63 , V_176 , V_13 ) ;
F_30 (csrow, dct, pvt) {
if ( ! F_31 ( V_43 , V_13 , V_9 ) )
continue;
F_27 ( V_9 , V_43 , V_13 , & V_177 , & V_178 ) ;
F_26 ( 1 , L_64 ,
V_43 , V_177 , V_178 ) ;
V_178 = ~ V_178 ;
F_26 ( 1 , L_65 ,
( V_176 & V_178 ) , ( V_177 & V_178 ) ) ;
if ( ( V_176 & V_178 ) == ( V_177 & V_178 ) ) {
V_179 = F_94 ( V_9 , V_13 , V_43 ) ;
F_26 ( 1 , L_66 , V_179 ) ;
break;
}
}
return V_179 ;
}
static T_3 F_99 ( struct V_8 * V_9 , T_3 V_34 )
{
T_1 V_180 , V_181 , V_182 , V_183 , V_122 ;
if ( V_30 . V_31 == 0x10 ) {
if ( V_30 . V_184 < 4 ||
( V_30 . V_184 < 0xa &&
V_30 . V_185 < 3 ) )
return V_34 ;
}
F_58 ( V_9 , V_186 , & V_180 ) ;
if ( ! ( V_180 & 0x1 ) )
return V_34 ;
V_181 = ( V_180 >> 3 ) & 0x7f ;
V_182 = ( V_180 >> 11 ) & 0x7f ;
V_183 = ( V_180 >> 20 ) & 0x7f ;
V_122 = V_34 >> 27 ;
if ( ! ( V_34 >> 34 ) &&
( ( ( V_122 >= V_181 ) &&
( V_122 <= V_182 ) ) ||
( V_122 < V_183 ) ) )
return V_34 ^ ( T_3 ) V_181 << 27 ;
return V_34 ;
}
static int F_100 ( struct V_8 * V_9 , unsigned V_129 ,
T_3 V_34 , int * V_187 )
{
int V_179 = - V_11 ;
T_3 V_188 ;
T_1 V_189 ;
T_2 V_147 ;
bool V_190 = false ;
T_2 V_36 = F_67 ( V_9 , V_129 ) ;
T_2 V_37 = F_22 ( V_9 , V_129 ) ;
T_1 V_68 = F_24 ( V_9 , V_129 ) ;
F_26 ( 1 , L_67 ,
V_129 , V_34 , F_20 ( V_9 , V_129 ) ) ;
if ( F_34 ( V_9 ) &&
F_35 ( V_9 ) <= V_34 &&
V_34 < F_93 ( 32 ) ) {
F_3 ( L_68 ,
V_34 ) ;
return - V_11 ;
}
if ( V_37 && ( V_68 != ( ( V_34 >> 12 ) & V_37 ) ) )
return - V_11 ;
V_34 = F_99 ( V_9 , V_34 ) ;
V_189 = F_83 ( V_9 ) ;
if ( F_84 ( V_9 ) &&
! F_55 ( V_9 ) &&
( ( V_34 >> 27 ) >= ( V_189 >> 11 ) ) )
V_190 = true ;
V_147 = F_89 ( V_9 , V_34 , V_190 , V_37 ) ;
V_188 = F_92 ( V_9 , V_129 , V_34 ,
V_190 , V_189 ) ;
if ( V_37 )
V_188 = ( ( V_188 >> ( 12 + F_91 ( V_37 ) ) ) << 12 ) |
( V_188 & 0xfff ) ;
if ( F_87 ( V_9 ) &&
! F_84 ( V_9 ) &&
! F_55 ( V_9 ) ) {
if ( F_88 ( V_9 ) != 1 ) {
if ( F_88 ( V_9 ) == 0x3 )
V_188 = ( ( V_188 >> 10 ) << 9 ) |
( V_188 & 0x1ff ) ;
else
V_188 = ( ( V_188 >> 7 ) << 6 ) |
( V_188 & 0x3f ) ;
} else
V_188 = ( ( V_188 >> 13 ) << 12 ) |
( V_188 & 0xfff ) ;
}
F_26 ( 1 , L_69 , V_188 ) ;
V_179 = F_98 ( V_188 , V_36 , V_147 ) ;
if ( V_179 >= 0 )
* V_187 = V_147 ;
return V_179 ;
}
static int F_101 ( struct V_8 * V_9 , T_3 V_34 ,
int * V_187 )
{
int V_179 = - V_11 ;
unsigned V_129 ;
for ( V_129 = 0 ; V_129 < V_39 ; V_129 ++ ) {
if ( ! F_66 ( V_9 , V_129 ) )
continue;
if ( ( F_19 ( V_9 , V_129 ) <= V_34 ) &&
( F_20 ( V_9 , V_129 ) >= V_34 ) ) {
V_179 = F_100 ( V_9 , V_129 ,
V_34 , V_187 ) ;
if ( V_179 >= 0 )
break;
}
}
return V_179 ;
}
static void F_102 ( struct V_25 * V_26 , T_3 V_34 ,
struct V_70 * V_6 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
F_46 ( V_34 , V_6 ) ;
V_6 -> V_43 = F_101 ( V_9 , V_34 , & V_6 -> V_147 ) ;
if ( V_6 -> V_43 < 0 ) {
V_6 -> V_142 = V_144 ;
return;
}
if ( F_55 ( V_9 ) )
V_6 -> V_147 = F_73 ( V_26 , V_6 -> V_148 ) ;
}
static void F_53 ( struct V_8 * V_9 , T_2 V_191 )
{
int V_192 , V_193 , V_194 ;
T_1 * V_195 = V_191 ? V_9 -> V_53 [ 1 ] . V_54 : V_9 -> V_53 [ 0 ] . V_54 ;
T_1 V_157 = V_191 ? V_9 -> V_158 : V_9 -> V_159 ;
if ( V_30 . V_31 == 0xf ) {
if ( V_9 -> V_51 < V_52 )
return;
else
F_70 ( V_191 != 0 ) ;
}
V_157 = ( V_191 && ! F_55 ( V_9 ) ) ? V_9 -> V_158 : V_9 -> V_159 ;
V_195 = ( V_191 && ! F_55 ( V_9 ) ) ? V_9 -> V_53 [ 1 ] . V_54
: V_9 -> V_53 [ 0 ] . V_54 ;
F_26 ( 1 , L_70 ,
V_191 , V_157 ) ;
F_103 ( V_196 , V_197 , L_71 , V_191 ) ;
for ( V_192 = 0 ; V_192 < 4 ; V_192 ++ ) {
V_193 = 0 ;
if ( V_195 [ V_192 * 2 ] & V_198 )
V_193 = V_9 -> V_199 -> V_200 ( V_9 , V_191 ,
F_78 ( V_192 , V_157 ) ) ;
V_194 = 0 ;
if ( V_195 [ V_192 * 2 + 1 ] & V_198 )
V_194 = V_9 -> V_199 -> V_200 ( V_9 , V_191 ,
F_78 ( V_192 , V_157 ) ) ;
F_54 ( V_197 L_72 ,
V_192 * 2 , V_193 ,
V_192 * 2 + 1 , V_194 ) ;
}
}
static struct V_1 * F_104 ( unsigned int V_201 ,
unsigned int V_202 ,
struct V_1 * V_203 )
{
struct V_1 * V_204 = NULL ;
V_204 = F_105 ( V_201 , V_202 , V_204 ) ;
while ( V_204 ) {
if ( ( V_204 -> V_205 -> V_206 == V_203 -> V_205 -> V_206 ) &&
( F_106 ( V_204 -> V_7 ) == F_106 ( V_203 -> V_7 ) ) )
break;
V_204 = F_105 ( V_201 , V_202 , V_204 ) ;
}
return V_204 ;
}
static int F_107 ( T_4 V_148 , T_4 * V_207 , unsigned V_208 ,
unsigned V_209 )
{
unsigned int V_21 , V_210 ;
for ( V_210 = 0 ; V_210 < V_208 / V_209 ; V_210 ++ ) {
T_4 V_211 = V_148 ;
unsigned V_212 = V_210 * V_209 ;
unsigned V_213 = ( V_210 + 1 ) * V_209 ;
for ( V_21 = 1 ; V_21 < ( 1U << 16 ) ; V_21 <<= 1 ) {
if ( V_212 < V_213 && V_207 [ V_212 ] & V_21 ) {
T_4 V_214 = V_207 [ V_212 ++ ] ;
if ( V_211 & V_21 ) {
V_211 ^= V_214 ;
if ( ! V_211 )
return V_210 ;
}
} else if ( V_211 & V_21 )
break;
}
}
F_26 ( 0 , L_73 , V_148 ) ;
return - 1 ;
}
static int F_108 ( int V_210 , int V_215 )
{
if ( V_215 == 4 )
switch ( V_210 ) {
case 0x20 :
case 0x21 :
return 0 ;
break;
case 0x22 :
case 0x23 :
return 1 ;
break;
default:
return V_210 >> 4 ;
break;
}
else
switch ( V_210 ) {
case 0x10 :
F_109 ( 1 , V_216 L_74 ,
V_210 ) ;
return - 1 ;
break;
case 0x11 :
return 0 ;
break;
case 0x12 :
return 1 ;
break;
default:
return V_210 >> 3 ;
break;
}
return - 1 ;
}
static int F_73 ( struct V_25 * V_26 , T_4 V_148 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
int V_210 = - 1 ;
if ( V_9 -> V_87 == 8 )
V_210 = F_107 ( V_148 , V_217 ,
F_14 ( V_217 ) ,
V_9 -> V_87 ) ;
else if ( V_9 -> V_87 == 4 )
V_210 = F_107 ( V_148 , V_218 ,
F_14 ( V_218 ) ,
V_9 -> V_87 ) ;
else {
F_3 ( L_75 , V_9 -> V_87 ) ;
return V_210 ;
}
return F_108 ( V_210 , V_9 -> V_87 ) ;
}
static void F_110 ( struct V_25 * V_26 , struct V_70 * V_6 ,
T_2 V_219 )
{
enum V_220 V_221 ;
const char * string ;
if ( V_219 == 2 )
V_221 = V_222 ;
else if ( V_219 == 1 )
V_221 = V_223 ;
else {
F_109 ( 1 , L_76 ) ;
return;
}
switch ( V_6 -> V_142 ) {
case V_224 :
string = L_26 ;
break;
case V_143 :
string = L_77 ;
break;
case V_144 :
string = L_78 ;
break;
case V_149 :
string = L_79 ;
break;
default:
string = L_80 ;
break;
}
F_111 ( V_221 , V_26 , 1 ,
V_6 -> V_71 , V_6 -> V_3 , V_6 -> V_148 ,
V_6 -> V_43 , V_6 -> V_147 , - 1 ,
string , L_26 ) ;
}
static inline void F_112 ( struct V_25 * V_26 ,
struct V_115 * V_116 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
T_2 V_219 = ( V_116 -> V_225 >> 45 ) & 0x3 ;
T_2 V_226 = F_113 ( V_116 -> V_225 , 0x1f ) ;
T_4 V_227 = F_114 ( V_116 -> V_225 ) ;
T_3 V_34 ;
struct V_70 V_6 ;
if ( F_115 ( V_227 ) == V_228 )
return;
if ( V_226 && V_226 != V_229 )
return;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_34 = F_62 ( V_116 ) ;
if ( V_219 == 2 )
V_6 . V_148 = F_116 ( V_116 -> V_225 ) ;
V_9 -> V_199 -> V_230 ( V_26 , V_34 , & V_6 ) ;
F_110 ( V_26 , & V_6 , V_219 ) ;
}
void F_117 ( int V_36 , struct V_115 * V_116 )
{
F_112 ( V_126 [ V_36 ] , V_116 ) ;
}
static int F_118 ( struct V_8 * V_9 , T_4 V_231 , T_4 V_232 )
{
V_9 -> V_15 = F_104 ( V_9 -> V_12 -> V_201 , V_231 , V_9 -> V_12 ) ;
if ( ! V_9 -> V_15 ) {
F_119 ( L_81
L_82 ,
V_233 , V_231 ) ;
return - V_234 ;
}
V_9 -> V_32 = F_104 ( V_9 -> V_12 -> V_201 , V_232 , V_9 -> V_12 ) ;
if ( ! V_9 -> V_32 ) {
F_71 ( V_9 -> V_15 ) ;
V_9 -> V_15 = NULL ;
F_119 ( L_83
L_82 ,
V_233 , V_232 ) ;
return - V_234 ;
}
F_26 ( 1 , L_84 , F_120 ( V_9 -> V_15 ) ) ;
F_26 ( 1 , L_85 , F_120 ( V_9 -> V_12 ) ) ;
F_26 ( 1 , L_86 , F_120 ( V_9 -> V_32 ) ) ;
return 0 ;
}
static void F_121 ( struct V_8 * V_9 )
{
F_71 ( V_9 -> V_15 ) ;
F_71 ( V_9 -> V_32 ) ;
}
static void F_122 ( struct V_8 * V_9 )
{
struct V_117 * V_118 = & V_30 ;
T_3 V_235 ;
T_1 V_123 ;
unsigned V_129 ;
F_123 ( V_236 , V_9 -> V_237 ) ;
F_26 ( 0 , L_87 , V_9 -> V_237 ) ;
F_123 ( V_238 , V_235 ) ;
if ( V_235 & ( 1U << 21 ) ) {
F_123 ( V_239 , V_9 -> V_240 ) ;
F_26 ( 0 , L_88 , V_9 -> V_240 ) ;
} else
F_26 ( 0 , L_89 ) ;
F_10 ( V_9 -> V_32 , V_241 , & V_9 -> V_81 ) ;
F_82 ( V_9 ) ;
for ( V_129 = 0 ; V_129 < V_39 ; V_129 ++ ) {
T_2 V_242 ;
F_65 ( V_9 , V_129 ) ;
V_242 = F_66 ( V_9 , V_129 ) ;
if ( ! V_242 )
continue;
F_26 ( 1 , L_90 ,
V_129 ,
F_19 ( V_9 , V_129 ) ,
F_20 ( V_9 , V_129 ) ) ;
F_26 ( 1 , L_91 ,
F_22 ( V_9 , V_129 ) ? L_92 : L_93 ,
( V_242 & 0x1 ) ? L_94 : L_95 ,
( V_242 & 0x2 ) ? L_96 : L_95 ,
F_24 ( V_9 , V_129 ) ,
F_67 ( V_9 , V_129 ) ) ;
}
F_57 ( V_9 ) ;
F_10 ( V_9 -> V_15 , V_243 , & V_9 -> V_86 ) ;
F_58 ( V_9 , V_244 , & V_9 -> V_159 ) ;
F_10 ( V_9 -> V_32 , V_245 , & V_9 -> V_85 ) ;
F_58 ( V_9 , V_246 , & V_9 -> V_77 ) ;
F_58 ( V_9 , V_247 , & V_9 -> V_105 ) ;
if ( ! F_55 ( V_9 ) ) {
F_58 ( V_9 , V_248 , & V_9 -> V_88 ) ;
F_58 ( V_9 , V_249 , & V_9 -> V_161 ) ;
}
V_9 -> V_87 = 4 ;
if ( V_118 -> V_31 >= 0x10 ) {
F_10 ( V_9 -> V_32 , V_250 , & V_123 ) ;
F_58 ( V_9 , V_251 , & V_9 -> V_158 ) ;
if ( ( V_118 -> V_31 > 0x10 || V_118 -> V_184 > 7 ) && V_123 & F_50 ( 25 ) )
V_9 -> V_87 = 8 ;
}
F_52 ( V_9 ) ;
}
static T_1 F_124 ( struct V_8 * V_9 , T_2 V_13 , int V_252 )
{
T_1 V_152 , V_253 ;
T_1 V_157 = V_13 ? V_9 -> V_158 : V_9 -> V_159 ;
V_152 = F_78 ( V_252 / 2 , V_157 ) ;
V_253 = V_9 -> V_199 -> V_200 ( V_9 , V_13 , V_152 ) << ( 20 - V_72 ) ;
F_26 ( 0 , L_97 ,
V_252 , V_13 , V_152 ) ;
F_26 ( 0 , L_98 , V_253 ) ;
return V_253 ;
}
static int F_125 ( struct V_25 * V_26 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
struct V_254 * V_43 ;
struct V_255 * V_192 ;
enum V_256 V_257 ;
enum V_102 V_258 ;
int V_21 , V_155 , V_259 = 1 ;
int V_253 = 0 ;
T_1 V_4 ;
F_10 ( V_9 -> V_32 , V_260 , & V_4 ) ;
V_9 -> V_145 = V_4 ;
F_26 ( 0 , L_99 ,
V_9 -> V_57 , V_4 ,
! ! ( V_4 & V_146 ) , ! ! ( V_4 & V_261 ) ) ;
F_30 (i, 0 , pvt) {
bool V_262 = ! ! F_31 ( V_21 , 0 , V_9 ) ;
bool V_263 = false ;
if ( V_30 . V_31 != 0xf )
V_263 = ! ! F_31 ( V_21 , 1 , V_9 ) ;
if ( ! V_262 && ! V_263 )
continue;
V_43 = V_26 -> V_264 [ V_21 ] ;
V_259 = 0 ;
F_26 ( 1 , L_100 ,
V_9 -> V_57 , V_21 ) ;
if ( V_262 )
V_253 = F_124 ( V_9 , 0 , V_21 ) ;
if ( V_30 . V_31 != 0xf && V_263 )
V_253 += F_124 ( V_9 , 1 , V_21 ) ;
V_258 = F_60 ( V_9 , V_21 ) ;
F_26 ( 1 , L_101 , V_21 , V_253 ) ;
if ( V_9 -> V_145 & V_261 )
V_257 = ( V_9 -> V_145 & V_146 ) ?
V_265 : V_266 ;
else
V_257 = V_267 ;
for ( V_155 = 0 ; V_155 < V_9 -> V_268 ; V_155 ++ ) {
V_192 = V_43 -> V_156 [ V_155 ] -> V_192 ;
V_192 -> V_258 = V_258 ;
V_192 -> V_257 = V_257 ;
V_192 -> V_253 = V_253 ;
}
V_43 -> V_253 = V_253 ;
}
return V_259 ;
}
static void F_126 ( struct V_269 * V_45 , unsigned V_35 )
{
int V_270 ;
F_127 (cpu)
if ( F_63 ( V_270 ) == V_35 )
F_128 ( V_270 , V_45 ) ;
}
static bool F_129 ( unsigned V_35 )
{
T_5 V_45 ;
int V_270 , V_271 ;
bool V_64 = false ;
if ( ! F_130 ( & V_45 , V_272 ) ) {
F_3 ( L_102 , V_42 ) ;
return false ;
}
F_126 ( V_45 , V_35 ) ;
F_131 ( V_45 , V_273 , V_274 ) ;
F_132 (cpu, mask) {
struct V_275 * V_14 = F_133 ( V_274 , V_270 ) ;
V_271 = V_14 -> V_276 & V_277 ;
F_26 ( 0 , L_103 ,
V_270 , V_14 -> V_278 ,
( V_271 ? L_30 : L_31 ) ) ;
if ( ! V_271 )
goto V_279;
}
V_64 = true ;
V_279:
F_134 ( V_45 ) ;
return V_64 ;
}
static int F_135 ( struct V_280 * V_211 , T_2 V_35 , bool V_281 )
{
T_5 V_282 ;
int V_270 ;
if ( ! F_130 ( & V_282 , V_272 ) ) {
F_3 ( L_104 , V_42 ) ;
return false ;
}
F_126 ( V_282 , V_35 ) ;
F_131 ( V_282 , V_273 , V_274 ) ;
F_132 (cpu, cmask) {
struct V_275 * V_14 = F_133 ( V_274 , V_270 ) ;
if ( V_281 ) {
if ( V_14 -> V_276 & V_277 )
V_211 -> V_283 . V_284 = 1 ;
V_14 -> V_276 |= V_277 ;
} else {
if ( ! V_211 -> V_283 . V_284 )
V_14 -> V_276 &= ~ V_277 ;
}
}
F_136 ( V_282 , V_273 , V_274 ) ;
F_134 ( V_282 ) ;
return 0 ;
}
static bool F_137 ( struct V_280 * V_211 , T_2 V_35 ,
struct V_1 * V_32 )
{
bool V_64 = true ;
T_1 V_285 , V_45 = 0x3 ;
if ( F_135 ( V_211 , V_35 , V_286 ) ) {
F_3 ( L_105 ) ;
return false ;
}
F_10 ( V_32 , V_287 , & V_285 ) ;
V_211 -> V_288 = V_285 & V_45 ;
V_211 -> V_289 = true ;
V_285 |= V_45 ;
F_11 ( V_32 , V_287 , V_285 ) ;
F_10 ( V_32 , V_260 , & V_285 ) ;
F_26 ( 0 , L_106 ,
V_35 , V_285 , ! ! ( V_285 & V_261 ) ) ;
if ( ! ( V_285 & V_261 ) ) {
F_3 ( L_107 ) ;
V_211 -> V_283 . V_290 = 0 ;
V_285 |= V_261 ;
F_11 ( V_32 , V_260 , V_285 ) ;
F_10 ( V_32 , V_260 , & V_285 ) ;
if ( ! ( V_285 & V_261 ) ) {
F_3 ( L_108
L_109 ) ;
V_64 = false ;
} else {
F_54 ( L_110 ) ;
}
} else {
V_211 -> V_283 . V_290 = 1 ;
}
F_26 ( 0 , L_111 ,
V_35 , V_285 , ! ! ( V_285 & V_261 ) ) ;
return V_64 ;
}
static void F_138 ( struct V_280 * V_211 , T_2 V_35 ,
struct V_1 * V_32 )
{
T_1 V_285 , V_45 = 0x3 ;
if ( ! V_211 -> V_289 )
return;
F_10 ( V_32 , V_287 , & V_285 ) ;
V_285 &= ~ V_45 ;
V_285 |= V_211 -> V_288 ;
F_11 ( V_32 , V_287 , V_285 ) ;
if ( ! V_211 -> V_283 . V_290 ) {
F_10 ( V_32 , V_260 , & V_285 ) ;
V_285 &= ~ V_261 ;
F_11 ( V_32 , V_260 , V_285 ) ;
}
if ( F_135 ( V_211 , V_35 , V_291 ) )
F_3 ( L_112 ) ;
}
static bool F_139 ( struct V_1 * V_32 , T_2 V_35 )
{
T_1 V_285 ;
T_2 V_292 = 0 ;
bool V_293 = false ;
F_10 ( V_32 , V_260 , & V_285 ) ;
V_292 = ! ! ( V_285 & V_261 ) ;
F_54 ( L_113 , ( V_292 ? L_30 : L_31 ) ) ;
V_293 = F_129 ( V_35 ) ;
if ( ! V_293 )
F_140 ( L_114
L_115 ,
V_273 , V_35 ) ;
if ( ! V_292 || ! V_293 ) {
F_140 ( L_116 , V_294 ) ;
return false ;
}
return true ;
}
static int F_141 ( struct V_25 * V_26 )
{
int V_295 ;
V_295 = F_142 ( V_26 ) ;
if ( V_295 < 0 )
return V_295 ;
if ( V_30 . V_31 >= 0x10 ) {
V_295 = F_143 ( V_26 ) ;
if ( V_295 < 0 )
return V_295 ;
}
return 0 ;
}
static void F_144 ( struct V_25 * V_26 )
{
F_145 ( V_26 ) ;
if ( V_30 . V_31 >= 0x10 )
F_146 ( V_26 ) ;
}
static void F_147 ( struct V_25 * V_26 ,
struct V_296 * V_297 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
V_26 -> V_298 = V_299 | V_300 ;
V_26 -> V_301 = V_76 ;
if ( V_9 -> V_81 & V_83 )
V_26 -> V_301 |= V_78 ;
if ( V_9 -> V_81 & V_84 )
V_26 -> V_301 |= V_302 ;
V_26 -> V_75 = F_49 ( V_9 ) ;
V_26 -> V_303 = V_304 ;
V_26 -> V_305 = V_306 ;
V_26 -> V_307 = V_297 -> V_307 ;
V_26 -> V_308 = F_120 ( V_9 -> V_12 ) ;
V_26 -> V_309 = NULL ;
V_26 -> V_310 = F_16 ;
V_26 -> V_311 = F_17 ;
}
static struct V_296 * F_148 ( struct V_8 * V_9 )
{
T_2 V_297 = V_30 . V_31 ;
struct V_296 * V_312 = NULL ;
switch ( V_297 ) {
case 0xf :
V_312 = & V_313 [ V_314 ] ;
V_9 -> V_199 = & V_313 [ V_314 ] . V_199 ;
break;
case 0x10 :
V_312 = & V_313 [ V_315 ] ;
V_9 -> V_199 = & V_313 [ V_315 ] . V_199 ;
break;
case 0x15 :
V_312 = & V_313 [ V_316 ] ;
V_9 -> V_199 = & V_313 [ V_316 ] . V_199 ;
break;
default:
F_119 ( L_117 ) ;
return NULL ;
}
V_9 -> V_51 = V_30 . V_184 >> 4 ;
F_54 ( L_118 , V_312 -> V_307 ,
( V_297 == 0xf ?
( V_9 -> V_51 >= V_52 ? L_119
: L_120 )
: L_26 ) , V_9 -> V_57 ) ;
return V_312 ;
}
static int F_149 ( struct V_1 * V_12 )
{
struct V_8 * V_9 = NULL ;
struct V_296 * V_312 = NULL ;
struct V_25 * V_26 = NULL ;
struct V_317 V_318 [ 2 ] ;
int V_6 = 0 , V_64 ;
T_2 V_35 = F_150 ( V_12 ) ;
V_64 = - V_319 ;
V_9 = F_151 ( sizeof( struct V_8 ) , V_272 ) ;
if ( ! V_9 )
goto V_320;
V_9 -> V_57 = V_35 ;
V_9 -> V_12 = V_12 ;
V_64 = - V_11 ;
V_312 = F_148 ( V_9 ) ;
if ( ! V_312 )
goto V_321;
V_64 = - V_234 ;
V_6 = F_118 ( V_9 , V_312 -> V_231 , V_312 -> V_232 ) ;
if ( V_6 )
goto V_321;
F_122 ( V_9 ) ;
V_64 = - V_11 ;
V_9 -> V_268 = V_9 -> V_199 -> V_322 ( V_9 ) ;
if ( V_9 -> V_268 < 0 )
goto V_323;
V_64 = - V_319 ;
V_318 [ 0 ] . type = V_324 ;
V_318 [ 0 ] . V_325 = V_9 -> V_53 [ 0 ] . V_89 ;
V_318 [ 0 ] . V_326 = true ;
V_318 [ 1 ] . type = V_327 ;
V_318 [ 1 ] . V_325 = V_9 -> V_268 ;
V_318 [ 1 ] . V_326 = false ;
V_26 = F_152 ( V_35 , F_14 ( V_318 ) , V_318 , 0 ) ;
if ( ! V_26 )
goto V_323;
V_26 -> V_28 = V_9 ;
V_26 -> V_2 = & V_9 -> V_12 -> V_204 ;
V_26 -> V_328 = 1 ;
F_147 ( V_26 , V_312 ) ;
if ( F_125 ( V_26 ) )
V_26 -> V_75 = V_76 ;
V_64 = - V_234 ;
if ( F_153 ( V_26 ) ) {
F_26 ( 1 , L_121 ) ;
goto V_329;
}
if ( F_141 ( V_26 ) ) {
F_26 ( 1 , L_121 ) ;
goto V_330;
}
if ( V_331 )
F_154 ( true ) ;
F_155 ( F_117 ) ;
V_126 [ V_35 ] = V_26 ;
F_156 ( & V_332 ) ;
return 0 ;
V_330:
F_157 ( V_26 -> V_2 ) ;
V_329:
F_158 ( V_26 ) ;
V_323:
F_121 ( V_9 ) ;
V_321:
F_159 ( V_9 ) ;
V_320:
return V_64 ;
}
static int F_160 ( struct V_1 * V_2 ,
const struct V_333 * V_334 )
{
T_2 V_35 = F_150 ( V_2 ) ;
struct V_1 * V_32 = F_161 ( V_35 ) -> V_335 ;
struct V_280 * V_211 ;
int V_64 = 0 ;
V_64 = F_162 ( V_2 ) ;
if ( V_64 < 0 ) {
F_26 ( 0 , L_122 , V_64 ) ;
return - V_336 ;
}
V_64 = - V_319 ;
V_211 = F_151 ( sizeof( struct V_280 ) , V_272 ) ;
if ( ! V_211 )
goto V_337;
V_338 [ V_35 ] = V_211 ;
if ( ! F_139 ( V_32 , V_35 ) ) {
V_64 = - V_234 ;
if ( ! V_339 )
goto V_340;
F_3 ( L_123 ) ;
if ( ! F_137 ( V_211 , V_35 , V_32 ) )
goto V_340;
}
V_64 = F_149 ( V_2 ) ;
if ( V_64 < 0 ) {
F_119 ( L_124 , V_35 ) ;
F_138 ( V_211 , V_35 , V_32 ) ;
}
return V_64 ;
V_340:
F_159 ( V_211 ) ;
V_338 [ V_35 ] = NULL ;
V_337:
return V_64 ;
}
static void F_163 ( struct V_1 * V_2 )
{
struct V_25 * V_26 ;
struct V_8 * V_9 ;
T_2 V_35 = F_150 ( V_2 ) ;
struct V_1 * V_32 = F_161 ( V_35 ) -> V_335 ;
struct V_280 * V_211 = V_338 [ V_35 ] ;
V_26 = F_164 ( & V_2 -> V_204 ) ;
F_144 ( V_26 ) ;
V_26 = F_157 ( & V_2 -> V_204 ) ;
if ( ! V_26 )
return;
V_9 = V_26 -> V_28 ;
F_138 ( V_211 , V_35 , V_32 ) ;
F_121 ( V_9 ) ;
F_154 ( false ) ;
F_165 ( F_117 ) ;
F_159 ( V_338 [ V_35 ] ) ;
V_338 [ V_35 ] = NULL ;
V_26 -> V_28 = NULL ;
V_126 [ V_35 ] = NULL ;
F_159 ( V_9 ) ;
F_158 ( V_26 ) ;
}
static void F_166 ( void )
{
struct V_25 * V_26 ;
struct V_8 * V_9 ;
if ( V_341 )
return;
V_26 = V_126 [ 0 ] ;
if ( V_26 ) {
V_9 = V_26 -> V_28 ;
V_341 =
F_167 ( & V_9 -> V_12 -> V_204 , V_304 ) ;
if ( ! V_341 ) {
F_168 ( L_125 ,
V_42 ) ;
F_168 ( L_126 ,
V_42 ) ;
}
}
}
static int T_6 F_169 ( void )
{
int V_6 = - V_234 ;
F_170 ( V_342 L_127 , V_306 ) ;
F_171 () ;
if ( F_172 () < 0 )
goto V_320;
V_6 = - V_319 ;
V_126 = F_151 ( F_173 () * sizeof( V_126 [ 0 ] ) , V_272 ) ;
V_338 = F_151 ( F_173 () * sizeof( V_338 [ 0 ] ) , V_272 ) ;
if ( ! ( V_126 && V_338 ) )
goto V_321;
V_274 = F_174 () ;
if ( ! V_274 )
goto V_321;
V_6 = F_175 ( & V_343 ) ;
if ( V_6 )
goto V_344;
V_6 = - V_234 ;
if ( ! F_176 ( & V_332 ) )
goto V_345;
F_166 () ;
return 0 ;
V_345:
F_177 ( & V_343 ) ;
V_344:
F_178 ( V_274 ) ;
V_274 = NULL ;
V_321:
F_159 ( V_126 ) ;
V_126 = NULL ;
F_159 ( V_338 ) ;
V_338 = NULL ;
V_320:
return V_6 ;
}
static void T_7 F_179 ( void )
{
if ( V_341 )
F_180 ( V_341 ) ;
F_177 ( & V_343 ) ;
F_159 ( V_338 ) ;
V_338 = NULL ;
F_159 ( V_126 ) ;
V_126 = NULL ;
F_178 ( V_274 ) ;
V_274 = NULL ;
}
