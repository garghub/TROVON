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
T_3 V_44 ;
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
V_44 = F_35 ( V_9 ) ;
* V_58 = V_44 ;
* V_60 = ( 0x1ull << 32 ) - V_44 ;
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
int V_64 = 0 ;
V_62 = F_19 ( V_9 , V_9 -> V_57 ) ;
V_64 = F_32 ( V_26 , & V_58 , & V_59 ,
& V_60 ) ;
if ( ! V_64 ) {
if ( ( V_34 >= ( 1ull << 32 ) ) &&
( V_34 < ( ( 1ull << 32 ) + V_60 ) ) ) {
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
T_1 * V_70 , T_1 * V_3 )
{
* V_70 = ( T_1 ) ( V_69 >> V_71 ) ;
* V_3 = ( ( T_1 ) V_69 ) & ~ V_72 ;
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
T_2 V_73 ;
unsigned long V_74 = V_75 ;
V_73 = ( V_30 . V_31 > 0xf || V_9 -> V_51 >= V_52 )
? 19
: 17 ;
if ( V_9 -> V_76 & F_50 ( V_73 ) )
V_74 = V_77 ;
return V_74 ;
}
static void F_51 ( T_1 V_78 , int V_79 )
{
F_26 ( 1 , L_23 , V_79 , V_78 ) ;
F_26 ( 1 , L_24 ,
( V_78 & F_50 ( 16 ) ) ? L_25 : L_26 ,
( V_78 & F_50 ( 19 ) ) ? L_27 : L_28 ) ;
F_26 ( 1 , L_29 ,
( V_78 & F_50 ( 8 ) ) ? L_30 : L_31 ) ;
if ( V_30 . V_31 == 0x10 )
F_26 ( 1 , L_32 ,
( V_78 & F_50 ( 11 ) ) ? L_33 : L_34 ) ;
F_26 ( 1 , L_35 ,
( V_78 & F_50 ( 12 ) ) ? L_27 : L_28 ,
( V_78 & F_50 ( 13 ) ) ? L_27 : L_28 ,
( V_78 & F_50 ( 14 ) ) ? L_27 : L_28 ,
( V_78 & F_50 ( 15 ) ) ? L_27 : L_28 ) ;
}
static void F_52 ( struct V_8 * V_9 )
{
F_26 ( 1 , L_36 , V_9 -> V_80 ) ;
F_26 ( 1 , L_37 ,
( V_9 -> V_80 & V_81 ) ? L_27 : L_28 ) ;
F_26 ( 1 , L_38 ,
( V_9 -> V_80 & V_82 ) ? L_27 : L_28 ,
( V_9 -> V_80 & V_83 ) ? L_27 : L_28 ) ;
F_51 ( V_9 -> V_76 , 0 ) ;
F_26 ( 1 , L_39 , V_9 -> V_84 ) ;
F_26 ( 1 , L_40 ,
V_9 -> V_85 , F_35 ( V_9 ) ,
( V_30 . V_31 == 0xf ) ? F_37 ( V_9 )
: F_36 ( V_9 ) ) ;
F_26 ( 1 , L_41 , F_34 ( V_9 ) ? L_27 : L_28 ) ;
F_53 ( V_9 , 0 ) ;
if ( V_30 . V_31 == 0xf )
return;
F_53 ( V_9 , 1 ) ;
F_54 ( L_42 , ( ( V_9 -> V_86 == 8 ) ? L_43 : L_44 ) ) ;
if ( ! F_55 ( V_9 ) )
F_51 ( V_9 -> V_87 , 1 ) ;
}
static void F_56 ( struct V_8 * V_9 )
{
if ( V_30 . V_31 == 0xf && V_9 -> V_51 < V_52 ) {
V_9 -> V_53 [ 0 ] . V_88 = V_9 -> V_53 [ 1 ] . V_88 = 8 ;
V_9 -> V_53 [ 0 ] . V_89 = V_9 -> V_53 [ 1 ] . V_89 = 8 ;
} else {
V_9 -> V_53 [ 0 ] . V_88 = V_9 -> V_53 [ 1 ] . V_88 = 8 ;
V_9 -> V_53 [ 0 ] . V_89 = V_9 -> V_53 [ 1 ] . V_89 = 4 ;
}
}
static void F_57 ( struct V_8 * V_9 )
{
int V_90 ;
F_56 ( V_9 ) ;
F_30 (cs, 0 , pvt) {
int V_91 = V_92 + ( V_90 * 4 ) ;
int V_93 = V_94 + ( V_90 * 4 ) ;
T_1 * V_95 = & V_9 -> V_53 [ 0 ] . V_54 [ V_90 ] ;
T_1 * V_96 = & V_9 -> V_53 [ 1 ] . V_54 [ V_90 ] ;
if ( ! F_58 ( V_9 , V_91 , V_95 ) )
F_26 ( 0 , L_45 ,
V_90 , * V_95 , V_91 ) ;
if ( V_30 . V_31 == 0xf || F_55 ( V_9 ) )
continue;
if ( ! F_58 ( V_9 , V_93 , V_96 ) )
F_26 ( 0 , L_46 ,
V_90 , * V_96 , V_93 ) ;
}
F_59 (cs, 0 , pvt) {
int V_91 = V_97 + ( V_90 * 4 ) ;
int V_93 = V_98 + ( V_90 * 4 ) ;
T_1 * V_99 = & V_9 -> V_53 [ 0 ] . V_55 [ V_90 ] ;
T_1 * V_100 = & V_9 -> V_53 [ 1 ] . V_55 [ V_90 ] ;
if ( ! F_58 ( V_9 , V_91 , V_99 ) )
F_26 ( 0 , L_47 ,
V_90 , * V_99 , V_91 ) ;
if ( V_30 . V_31 == 0xf || F_55 ( V_9 ) )
continue;
if ( ! F_58 ( V_9 , V_93 , V_100 ) )
F_26 ( 0 , L_48 ,
V_90 , * V_100 , V_93 ) ;
}
}
static enum V_101 F_60 ( struct V_8 * V_9 , int V_90 )
{
enum V_101 type ;
if ( V_30 . V_31 >= 0x15 )
type = ( V_9 -> V_76 & F_50 ( 16 ) ) ? V_102 : V_103 ;
else if ( V_30 . V_31 == 0x10 || V_9 -> V_51 >= V_52 ) {
if ( V_9 -> V_104 & V_105 )
type = ( V_9 -> V_76 & F_50 ( 16 ) ) ? V_102 : V_103 ;
else
type = ( V_9 -> V_76 & F_50 ( 16 ) ) ? V_106 : V_107 ;
} else {
type = ( V_9 -> V_76 & F_50 ( 18 ) ) ? V_108 : V_109 ;
}
F_54 ( L_49 , V_90 , V_110 [ type ] ) ;
return type ;
}
static int F_61 ( struct V_8 * V_9 )
{
int V_111 ;
if ( V_9 -> V_51 >= V_52 )
V_111 = V_9 -> V_76 & V_112 ;
else
V_111 = V_9 -> V_76 & V_113 ;
V_9 -> V_87 = 0 ;
return ( V_111 ) ? 2 : 1 ;
}
static T_3 F_62 ( struct V_114 * V_115 )
{
struct V_116 * V_117 = & V_30 ;
T_3 V_10 ;
T_2 V_118 = 1 ;
T_2 V_119 = 47 ;
if ( V_117 -> V_31 == 0xf ) {
V_118 = 3 ;
V_119 = 39 ;
}
V_10 = V_115 -> V_10 & F_28 ( V_118 , V_119 ) ;
if ( V_117 -> V_31 == 0x15 ) {
struct V_8 * V_9 ;
T_3 V_120 , V_121 ;
T_1 V_122 ;
T_2 V_123 , V_37 ;
if ( ( V_10 & F_28 ( 24 , 47 ) ) >> 24 != 0x00fdf7 )
return V_10 ;
V_123 = F_63 ( V_115 -> V_124 ) ;
V_9 = V_125 [ V_123 ] -> V_28 ;
F_10 ( V_9 -> V_15 , V_126 , & V_122 ) ;
V_37 = V_122 >> 21 & 0x7 ;
V_120 = ( V_122 & F_28 ( 0 , 20 ) ) << 3 ;
V_120 |= V_37 ^ 0x7 ;
V_120 <<= 24 ;
if ( ! V_37 )
return V_120 | ( V_10 & F_28 ( 0 , 23 ) ) ;
F_10 ( V_9 -> V_15 , V_127 , & V_122 ) ;
V_121 = ( V_10 & F_28 ( 12 , 23 ) ) << F_64 ( V_37 + 1 ) ;
V_121 |= ( V_122 & F_28 ( 21 , 23 ) ) >> 9 ;
V_121 |= V_10 & F_28 ( 0 , 11 ) ;
return V_120 | V_121 ;
}
return V_10 ;
}
static void F_65 ( struct V_8 * V_9 , unsigned V_128 )
{
struct V_116 * V_117 = & V_30 ;
int V_129 = V_128 << 3 ;
F_10 ( V_9 -> V_15 , V_130 + V_129 , & V_9 -> V_131 [ V_128 ] . V_44 . V_132 ) ;
F_10 ( V_9 -> V_15 , V_133 + V_129 , & V_9 -> V_131 [ V_128 ] . V_134 . V_132 ) ;
if ( V_117 -> V_31 == 0xf )
return;
if ( ! F_66 ( V_9 , V_128 ) )
return;
F_10 ( V_9 -> V_15 , V_135 + V_129 , & V_9 -> V_131 [ V_128 ] . V_44 . V_136 ) ;
F_10 ( V_9 -> V_15 , V_137 + V_129 , & V_9 -> V_131 [ V_128 ] . V_134 . V_136 ) ;
if ( V_117 -> V_31 == 0x15 ) {
struct V_1 * V_138 = NULL ;
T_2 V_35 = F_67 ( V_9 , V_128 ) ;
T_1 V_139 ;
V_138 = F_68 ( 0 , 0 , F_69 ( 0x18 + V_35 , 1 ) ) ;
if ( F_70 ( ! V_138 ) )
return;
F_10 ( V_138 , V_126 , & V_139 ) ;
V_9 -> V_131 [ V_128 ] . V_134 . V_132 &= F_28 ( 0 , 15 ) ;
V_9 -> V_131 [ V_128 ] . V_134 . V_132 |= ( ( V_139 & 0x1fff ) << 3 | 0x7 ) << 16 ;
V_9 -> V_131 [ V_128 ] . V_134 . V_136 &= F_28 ( 0 , 7 ) ;
V_9 -> V_131 [ V_128 ] . V_134 . V_136 |= V_139 >> 13 ;
F_71 ( V_138 ) ;
}
}
static void F_72 ( struct V_25 * V_26 , T_3 V_34 ,
T_4 V_140 )
{
struct V_25 * V_141 ;
struct V_8 * V_9 = V_26 -> V_28 ;
int V_142 , V_43 ;
T_1 V_70 , V_3 ;
F_46 ( V_34 , & V_70 , & V_3 ) ;
V_141 = F_21 ( V_26 , V_34 ) ;
if ( ! V_141 ) {
F_48 ( V_26 , L_50 ,
( unsigned long ) V_34 ) ;
F_73 ( V_143 , V_26 , 1 ,
V_70 , V_3 , V_140 ,
- 1 , - 1 , - 1 ,
L_51 ,
L_26 ) ;
return;
}
V_43 = F_47 ( V_141 , V_34 ) ;
if ( V_43 < 0 ) {
F_73 ( V_143 , V_26 , 1 ,
V_70 , V_3 , V_140 ,
- 1 , - 1 , - 1 ,
L_52 ,
L_26 ) ;
return;
}
if ( V_9 -> V_144 & V_145 ) {
V_142 = F_74 ( V_26 , V_140 ) ;
if ( V_142 < 0 ) {
F_75 ( V_141 , L_53
L_54 ,
V_140 ) ;
F_73 ( V_143 , V_26 , 1 ,
V_70 , V_3 , V_140 ,
V_43 , - 1 , - 1 ,
L_55 ,
L_26 ) ;
return;
}
} else {
V_142 = ( ( V_34 & F_50 ( 3 ) ) != 0 ) ;
}
F_73 ( V_143 , V_141 , 1 ,
V_70 , V_3 , V_140 ,
V_43 , V_142 , - 1 ,
L_26 , L_26 ) ;
}
static int F_76 ( unsigned V_21 , bool V_146 )
{
unsigned V_147 = 0 ;
if ( V_21 <= 2 )
V_147 = V_21 ;
else if ( ! ( V_21 & 0x1 ) )
V_147 = V_21 >> 1 ;
else
V_147 = ( V_21 + 1 ) >> 1 ;
return 128 << ( V_147 + ! ! V_146 ) ;
}
static int F_77 ( struct V_8 * V_9 , T_2 V_13 ,
unsigned V_148 )
{
T_1 V_78 = V_13 ? V_9 -> V_87 : V_9 -> V_76 ;
if ( V_9 -> V_51 >= V_52 ) {
F_70 ( V_148 > 11 ) ;
return F_76 ( V_148 , V_78 & V_112 ) ;
}
else if ( V_9 -> V_51 >= V_149 ) {
unsigned V_150 ;
F_70 ( V_148 > 10 ) ;
V_150 = V_148 / 3 + ( unsigned ) ( V_148 > 5 ) ;
return 32 << ( V_148 - V_150 ) ;
}
else {
F_70 ( V_148 > 6 ) ;
return 32 << V_148 ;
}
}
static int F_78 ( struct V_8 * V_9 )
{
int V_21 , V_151 , V_152 = 0 ;
if ( V_30 . V_31 == 0x10 && ( V_9 -> V_76 & V_112 ) )
return 2 ;
F_26 ( 0 , L_56 ) ;
for ( V_21 = 0 ; V_21 < 2 ; V_21 ++ ) {
T_1 V_153 = ( V_21 ? V_9 -> V_154 : V_9 -> V_155 ) ;
for ( V_151 = 0 ; V_151 < 4 ; V_151 ++ ) {
if ( F_79 ( V_151 , V_153 ) > 0 ) {
V_152 ++ ;
break;
}
}
}
if ( V_152 > 2 )
V_152 = 2 ;
F_54 ( L_57 , V_152 ) ;
return V_152 ;
}
static int F_80 ( unsigned V_21 , bool V_146 )
{
unsigned V_147 = 0 ;
int V_156 = 0 ;
if ( V_21 == 0 || V_21 == 3 || V_21 == 4 )
V_156 = - 1 ;
else if ( V_21 <= 2 )
V_147 = V_21 ;
else if ( V_21 == 12 )
V_147 = 7 ;
else if ( ! ( V_21 & 0x1 ) )
V_147 = V_21 >> 1 ;
else
V_147 = ( V_21 + 1 ) >> 1 ;
if ( V_156 != - 1 )
V_156 = ( 128 * ( 1 << ! ! V_146 ) ) << V_147 ;
return V_156 ;
}
static int F_81 ( struct V_8 * V_9 , T_2 V_13 ,
unsigned V_148 )
{
T_1 V_78 = V_13 ? V_9 -> V_87 : V_9 -> V_76 ;
F_70 ( V_148 > 11 ) ;
if ( V_9 -> V_104 & V_105 || V_9 -> V_157 & V_105 )
return F_80 ( V_148 , V_78 & V_112 ) ;
else
return F_76 ( V_148 , V_78 & V_112 ) ;
}
static int F_82 ( struct V_8 * V_9 , T_2 V_13 ,
unsigned V_148 )
{
F_70 ( V_148 > 12 ) ;
return F_80 ( V_148 , false ) ;
}
static void F_83 ( struct V_8 * V_9 )
{
if ( V_30 . V_31 == 0xf )
return;
if ( ! F_58 ( V_9 , V_158 , & V_9 -> V_159 ) ) {
F_26 ( 0 , L_58 ,
V_9 -> V_159 , F_84 ( V_9 ) ) ;
F_26 ( 0 , L_59 ,
( F_55 ( V_9 ) ? L_60 : L_61 ) ) ;
if ( ! F_55 ( V_9 ) )
F_26 ( 0 , L_62 ,
( F_85 ( V_9 ) ? L_27 : L_28 ) ) ;
F_26 ( 0 , L_63 ,
( F_86 ( V_9 ) ? L_30 : L_31 ) ,
( F_87 ( V_9 ) ? L_27 : L_28 ) ) ;
F_26 ( 0 , L_64
L_65 ,
( F_88 ( V_9 ) ? L_30 : L_31 ) ,
F_89 ( V_9 ) ) ;
}
F_58 ( V_9 , V_160 , & V_9 -> V_161 ) ;
}
static T_2 F_90 ( struct V_8 * V_9 , T_3 V_34 ,
bool V_162 , T_2 V_37 )
{
T_2 V_163 = ( V_9 -> V_159 >> 1 ) & 1 ;
if ( F_55 ( V_9 ) )
return 0 ;
if ( V_162 )
return V_163 ;
if ( F_88 ( V_9 ) ) {
T_2 V_164 = F_89 ( V_9 ) ;
if ( ! V_164 )
return V_34 >> 6 & 1 ;
if ( V_164 & 0x2 ) {
T_2 V_147 = V_164 & 0x1 ? 9 : 6 ;
T_1 V_165 = F_91 ( ( T_1 ) ( ( V_34 >> 16 ) & 0x1F ) ) % 2 ;
return ( ( V_34 >> V_147 ) & 1 ) ^ V_165 ;
}
return ( V_34 >> ( 12 + F_92 ( V_37 ) ) ) & 1 ;
}
if ( F_85 ( V_9 ) )
return ~ V_163 & 1 ;
return 0 ;
}
static T_3 F_93 ( struct V_8 * V_9 , unsigned V_128 ,
T_3 V_34 , bool V_166 ,
T_1 V_167 )
{
T_3 V_168 ;
T_3 V_62 = F_19 ( V_9 , V_128 ) ;
T_3 V_169 = F_36 ( V_9 ) ;
T_3 V_170 = ( V_9 -> V_161 & 0xFFFFFC00 ) << 16 ;
if ( V_166 ) {
if ( ( ! ( V_167 >> 16 ) ||
V_167 < F_35 ( V_9 ) ) &&
F_34 ( V_9 ) &&
( V_34 >= F_94 ( 32 ) ) )
V_168 = V_169 ;
else
V_168 = V_170 ;
} else {
if ( F_34 ( V_9 ) && ( V_34 >= F_94 ( 32 ) ) )
V_168 = V_169 ;
else
V_168 = V_62 ;
}
return ( V_34 & F_28 ( 6 , 47 ) ) - ( V_168 & F_28 ( 23 , 47 ) ) ;
}
static int F_95 ( struct V_8 * V_9 , T_2 V_13 , int V_43 )
{
int V_171 ;
if ( F_96 ( V_9 , V_13 ) &&
V_43 == F_97 ( V_9 , V_13 ) ) {
F_30 (tmp_cs, dct, pvt) {
if ( F_98 ( V_171 , V_13 , V_9 ) & 0x2 ) {
V_43 = V_171 ;
break;
}
}
}
return V_43 ;
}
static int F_99 ( T_3 V_172 , T_1 V_35 , T_2 V_13 )
{
struct V_25 * V_26 ;
struct V_8 * V_9 ;
T_3 V_173 , V_174 ;
int V_175 = - V_11 ;
int V_43 ;
V_26 = V_125 [ V_35 ] ;
if ( ! V_26 )
return V_175 ;
V_9 = V_26 -> V_28 ;
F_26 ( 1 , L_66 , V_172 , V_13 ) ;
F_30 (csrow, dct, pvt) {
if ( ! F_31 ( V_43 , V_13 , V_9 ) )
continue;
F_27 ( V_9 , V_43 , V_13 , & V_173 , & V_174 ) ;
F_26 ( 1 , L_67 ,
V_43 , V_173 , V_174 ) ;
V_174 = ~ V_174 ;
F_26 ( 1 , L_68 ,
( V_172 & V_174 ) , ( V_173 & V_174 ) ) ;
if ( ( V_172 & V_174 ) == ( V_173 & V_174 ) ) {
V_175 = F_95 ( V_9 , V_13 , V_43 ) ;
F_26 ( 1 , L_69 , V_175 ) ;
break;
}
}
return V_175 ;
}
static T_3 F_100 ( struct V_8 * V_9 , T_3 V_34 )
{
T_1 V_176 , V_177 , V_178 , V_179 , V_121 ;
if ( V_30 . V_31 == 0x10 ) {
if ( V_30 . V_180 < 4 ||
( V_30 . V_180 < 0xa &&
V_30 . V_181 < 3 ) )
return V_34 ;
}
F_58 ( V_9 , V_182 , & V_176 ) ;
if ( ! ( V_176 & 0x1 ) )
return V_34 ;
V_177 = ( V_176 >> 3 ) & 0x7f ;
V_178 = ( V_176 >> 11 ) & 0x7f ;
V_179 = ( V_176 >> 20 ) & 0x7f ;
V_121 = V_34 >> 27 ;
if ( ! ( V_34 >> 34 ) &&
( ( ( V_121 >= V_177 ) &&
( V_121 <= V_178 ) ) ||
( V_121 < V_179 ) ) )
return V_34 ^ ( T_3 ) V_177 << 27 ;
return V_34 ;
}
static int F_101 ( struct V_8 * V_9 , unsigned V_128 ,
T_3 V_34 , int * V_35 , int * V_183 )
{
int V_175 = - V_11 ;
T_3 V_184 ;
T_1 V_185 ;
T_2 V_142 ;
bool V_186 = false ;
T_2 V_36 = F_67 ( V_9 , V_128 ) ;
T_2 V_37 = F_22 ( V_9 , V_128 ) ;
T_1 V_68 = F_24 ( V_9 , V_128 ) ;
F_26 ( 1 , L_70 ,
V_128 , V_34 , F_20 ( V_9 , V_128 ) ) ;
if ( F_34 ( V_9 ) &&
F_35 ( V_9 ) <= V_34 &&
V_34 < F_94 ( 32 ) ) {
F_3 ( L_71 ,
V_34 ) ;
return - V_11 ;
}
if ( V_37 && ( V_68 != ( ( V_34 >> 12 ) & V_37 ) ) )
return - V_11 ;
V_34 = F_100 ( V_9 , V_34 ) ;
V_185 = F_84 ( V_9 ) ;
if ( F_85 ( V_9 ) &&
! F_55 ( V_9 ) &&
( ( V_34 >> 27 ) >= ( V_185 >> 11 ) ) )
V_186 = true ;
V_142 = F_90 ( V_9 , V_34 , V_186 , V_37 ) ;
V_184 = F_93 ( V_9 , V_128 , V_34 ,
V_186 , V_185 ) ;
if ( V_37 )
V_184 = ( ( V_184 >> ( 12 + F_92 ( V_37 ) ) ) << 12 ) |
( V_184 & 0xfff ) ;
if ( F_88 ( V_9 ) &&
! F_85 ( V_9 ) &&
! F_55 ( V_9 ) ) {
if ( F_89 ( V_9 ) != 1 ) {
if ( F_89 ( V_9 ) == 0x3 )
V_184 = ( ( V_184 >> 10 ) << 9 ) |
( V_184 & 0x1ff ) ;
else
V_184 = ( ( V_184 >> 7 ) << 6 ) |
( V_184 & 0x3f ) ;
} else
V_184 = ( ( V_184 >> 13 ) << 12 ) |
( V_184 & 0xfff ) ;
}
F_26 ( 1 , L_72 , V_184 ) ;
V_175 = F_99 ( V_184 , V_36 , V_142 ) ;
if ( V_175 >= 0 ) {
* V_35 = V_36 ;
* V_183 = V_142 ;
}
return V_175 ;
}
static int F_102 ( struct V_8 * V_9 , T_3 V_34 ,
int * V_187 , int * V_183 )
{
int V_175 = - V_11 ;
unsigned V_128 ;
for ( V_128 = 0 ; V_128 < V_39 ; V_128 ++ ) {
if ( ! F_66 ( V_9 , V_128 ) )
continue;
if ( ( F_19 ( V_9 , V_128 ) <= V_34 ) &&
( F_20 ( V_9 , V_128 ) >= V_34 ) ) {
V_175 = F_101 ( V_9 , V_128 ,
V_34 , V_187 ,
V_183 ) ;
if ( V_175 >= 0 )
break;
}
}
return V_175 ;
}
static void F_103 ( struct V_25 * V_26 , T_3 V_34 ,
T_4 V_140 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
T_1 V_70 , V_3 ;
int V_35 , V_43 , V_79 = 0 ;
F_46 ( V_34 , & V_70 , & V_3 ) ;
V_43 = F_102 ( V_9 , V_34 , & V_35 , & V_79 ) ;
if ( V_43 < 0 ) {
F_73 ( V_143 , V_26 , 1 ,
V_70 , V_3 , V_140 ,
- 1 , - 1 , - 1 ,
L_52 ,
L_26 ) ;
return;
}
if ( F_55 ( V_9 ) )
V_79 = F_74 ( V_26 , V_140 ) ;
F_73 ( V_143 , V_26 , 1 ,
V_70 , V_3 , V_140 ,
V_43 , V_79 , - 1 ,
L_26 , L_26 ) ;
}
static void F_53 ( struct V_8 * V_9 , T_2 V_188 )
{
int V_189 , V_190 , V_191 , V_192 = 0 ;
T_1 * V_193 = V_188 ? V_9 -> V_53 [ 1 ] . V_54 : V_9 -> V_53 [ 0 ] . V_54 ;
T_1 V_153 = V_188 ? V_9 -> V_154 : V_9 -> V_155 ;
if ( V_30 . V_31 == 0xf ) {
if ( V_9 -> V_76 & V_112 )
V_192 = 1 ;
if ( V_9 -> V_51 < V_52 )
return;
else
F_70 ( V_188 != 0 ) ;
}
V_153 = ( V_188 && ! F_55 ( V_9 ) ) ? V_9 -> V_154 : V_9 -> V_155 ;
V_193 = ( V_188 && ! F_55 ( V_9 ) ) ? V_9 -> V_53 [ 1 ] . V_54
: V_9 -> V_53 [ 0 ] . V_54 ;
F_26 ( 1 , L_73 ,
V_188 , V_153 ) ;
F_104 ( V_194 , V_195 , L_74 , V_188 ) ;
for ( V_189 = 0 ; V_189 < 4 ; V_189 ++ ) {
V_190 = 0 ;
if ( V_193 [ V_189 * 2 ] & V_196 )
V_190 = V_9 -> V_197 -> V_198 ( V_9 , V_188 ,
F_79 ( V_189 , V_153 ) ) ;
V_191 = 0 ;
if ( V_193 [ V_189 * 2 + 1 ] & V_196 )
V_191 = V_9 -> V_197 -> V_198 ( V_9 , V_188 ,
F_79 ( V_189 , V_153 ) ) ;
F_54 ( V_195 L_75 ,
V_189 * 2 , V_190 << V_192 ,
V_189 * 2 + 1 , V_191 << V_192 ) ;
}
}
static struct V_1 * F_105 ( unsigned int V_199 ,
unsigned int V_200 ,
struct V_1 * V_201 )
{
struct V_1 * V_202 = NULL ;
V_202 = F_106 ( V_199 , V_200 , V_202 ) ;
while ( V_202 ) {
if ( ( V_202 -> V_203 -> V_204 == V_201 -> V_203 -> V_204 ) &&
( F_107 ( V_202 -> V_7 ) == F_107 ( V_201 -> V_7 ) ) )
break;
V_202 = F_106 ( V_199 , V_200 , V_202 ) ;
}
return V_202 ;
}
static int F_108 ( T_4 V_140 , T_4 * V_205 , unsigned V_206 ,
unsigned V_207 )
{
unsigned int V_21 , V_208 ;
for ( V_208 = 0 ; V_208 < V_206 / V_207 ; V_208 ++ ) {
T_4 V_209 = V_140 ;
unsigned V_210 = V_208 * V_207 ;
unsigned V_211 = ( V_208 + 1 ) * V_207 ;
for ( V_21 = 1 ; V_21 < ( 1U << 16 ) ; V_21 <<= 1 ) {
if ( V_210 < V_211 && V_205 [ V_210 ] & V_21 ) {
T_4 V_212 = V_205 [ V_210 ++ ] ;
if ( V_209 & V_21 ) {
V_209 ^= V_212 ;
if ( ! V_209 )
return V_208 ;
}
} else if ( V_209 & V_21 )
break;
}
}
F_26 ( 0 , L_76 , V_140 ) ;
return - 1 ;
}
static int F_109 ( int V_208 , int V_213 )
{
if ( V_213 == 4 )
switch ( V_208 ) {
case 0x20 :
case 0x21 :
return 0 ;
break;
case 0x22 :
case 0x23 :
return 1 ;
break;
default:
return V_208 >> 4 ;
break;
}
else
switch ( V_208 ) {
case 0x10 :
F_110 ( 1 , V_214 L_77 ,
V_208 ) ;
return - 1 ;
break;
case 0x11 :
return 0 ;
break;
case 0x12 :
return 1 ;
break;
default:
return V_208 >> 3 ;
break;
}
return - 1 ;
}
static int F_74 ( struct V_25 * V_26 , T_4 V_140 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
int V_208 = - 1 ;
if ( V_9 -> V_86 == 8 )
V_208 = F_108 ( V_140 , V_215 ,
F_14 ( V_215 ) ,
V_9 -> V_86 ) ;
else if ( V_9 -> V_86 == 4 )
V_208 = F_108 ( V_140 , V_216 ,
F_14 ( V_216 ) ,
V_9 -> V_86 ) ;
else {
F_3 ( L_78 , V_9 -> V_86 ) ;
return V_208 ;
}
return F_109 ( V_208 , V_9 -> V_86 ) ;
}
static void F_111 ( struct V_25 * V_26 , struct V_114 * V_115 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
T_3 V_34 ;
T_4 V_140 ;
if ( ! ( V_115 -> V_217 & V_218 ) ) {
F_48 ( V_26 , L_79 ) ;
F_73 ( V_143 , V_26 , 1 ,
0 , 0 , 0 ,
- 1 , - 1 , - 1 ,
L_80 ,
L_26 ) ;
return;
}
V_34 = F_62 ( V_115 ) ;
V_140 = F_112 ( V_115 -> V_217 ) ;
F_48 ( V_26 , L_81 , V_34 ) ;
V_9 -> V_197 -> V_219 ( V_26 , V_34 , V_140 ) ;
}
static void F_113 ( struct V_25 * V_26 , struct V_114 * V_115 )
{
struct V_25 * V_220 , * V_141 = NULL ;
int V_43 ;
T_3 V_34 ;
T_1 V_70 , V_3 ;
V_220 = V_26 ;
if ( ! ( V_115 -> V_217 & V_218 ) ) {
F_48 ( V_26 , L_79 ) ;
F_73 ( V_221 , V_26 , 1 ,
0 , 0 , 0 ,
- 1 , - 1 , - 1 ,
L_80 ,
L_26 ) ;
return;
}
V_34 = F_62 ( V_115 ) ;
F_46 ( V_34 , & V_70 , & V_3 ) ;
V_141 = F_21 ( V_26 , V_34 ) ;
if ( ! V_141 ) {
F_48 ( V_26 , L_82 ,
( unsigned long ) V_34 ) ;
F_73 ( V_221 , V_26 , 1 ,
V_70 , V_3 , 0 ,
- 1 , - 1 , - 1 ,
L_83 ,
L_26 ) ;
return;
}
V_220 = V_141 ;
V_43 = F_47 ( V_220 , V_34 ) ;
if ( V_43 < 0 ) {
F_48 ( V_26 , L_84 ,
( unsigned long ) V_34 ) ;
F_73 ( V_221 , V_26 , 1 ,
V_70 , V_3 , 0 ,
- 1 , - 1 , - 1 ,
L_85 ,
L_26 ) ;
} else {
F_73 ( V_221 , V_26 , 1 ,
V_70 , V_3 , 0 ,
V_43 , - 1 , - 1 ,
L_26 , L_26 ) ;
}
}
static inline void F_114 ( struct V_25 * V_26 ,
struct V_114 * V_115 )
{
T_4 V_222 = F_115 ( V_115 -> V_217 ) ;
T_2 V_223 = F_116 ( V_115 -> V_217 , 0x1f ) ;
T_2 V_224 = ( V_115 -> V_217 >> 45 ) & 0x3 ;
if ( F_117 ( V_222 ) == V_225 )
return;
if ( V_223 && V_223 != V_226 )
return;
if ( V_224 == 2 )
F_111 ( V_26 , V_115 ) ;
else if ( V_224 == 1 )
F_113 ( V_26 , V_115 ) ;
}
void F_118 ( int V_36 , struct V_114 * V_115 )
{
F_114 ( V_125 [ V_36 ] , V_115 ) ;
}
static int F_119 ( struct V_8 * V_9 , T_4 V_227 , T_4 V_228 )
{
V_9 -> V_15 = F_105 ( V_9 -> V_12 -> V_199 , V_227 , V_9 -> V_12 ) ;
if ( ! V_9 -> V_15 ) {
F_120 ( L_86
L_87 ,
V_229 , V_227 ) ;
return - V_230 ;
}
V_9 -> V_32 = F_105 ( V_9 -> V_12 -> V_199 , V_228 , V_9 -> V_12 ) ;
if ( ! V_9 -> V_32 ) {
F_71 ( V_9 -> V_15 ) ;
V_9 -> V_15 = NULL ;
F_120 ( L_88
L_87 ,
V_229 , V_228 ) ;
return - V_230 ;
}
F_26 ( 1 , L_89 , F_121 ( V_9 -> V_15 ) ) ;
F_26 ( 1 , L_90 , F_121 ( V_9 -> V_12 ) ) ;
F_26 ( 1 , L_91 , F_121 ( V_9 -> V_32 ) ) ;
return 0 ;
}
static void F_122 ( struct V_8 * V_9 )
{
F_71 ( V_9 -> V_15 ) ;
F_71 ( V_9 -> V_32 ) ;
}
static void F_123 ( struct V_8 * V_9 )
{
struct V_116 * V_117 = & V_30 ;
T_3 V_231 ;
T_1 V_122 ;
unsigned V_128 ;
F_124 ( V_232 , V_9 -> V_233 ) ;
F_26 ( 0 , L_92 , V_9 -> V_233 ) ;
F_124 ( V_234 , V_231 ) ;
if ( V_231 & ( 1U << 21 ) ) {
F_124 ( V_235 , V_9 -> V_236 ) ;
F_26 ( 0 , L_93 , V_9 -> V_236 ) ;
} else
F_26 ( 0 , L_94 ) ;
F_10 ( V_9 -> V_32 , V_237 , & V_9 -> V_80 ) ;
F_83 ( V_9 ) ;
for ( V_128 = 0 ; V_128 < V_39 ; V_128 ++ ) {
T_2 V_238 ;
F_65 ( V_9 , V_128 ) ;
V_238 = F_66 ( V_9 , V_128 ) ;
if ( ! V_238 )
continue;
F_26 ( 1 , L_95 ,
V_128 ,
F_19 ( V_9 , V_128 ) ,
F_20 ( V_9 , V_128 ) ) ;
F_26 ( 1 , L_96 ,
F_22 ( V_9 , V_128 ) ? L_97 : L_98 ,
( V_238 & 0x1 ) ? L_99 : L_100 ,
( V_238 & 0x2 ) ? L_101 : L_100 ,
F_24 ( V_9 , V_128 ) ,
F_67 ( V_9 , V_128 ) ) ;
}
F_57 ( V_9 ) ;
F_10 ( V_9 -> V_15 , V_239 , & V_9 -> V_85 ) ;
F_58 ( V_9 , V_240 , & V_9 -> V_155 ) ;
F_10 ( V_9 -> V_32 , V_241 , & V_9 -> V_84 ) ;
F_58 ( V_9 , V_242 , & V_9 -> V_76 ) ;
F_58 ( V_9 , V_243 , & V_9 -> V_104 ) ;
if ( ! F_55 ( V_9 ) ) {
F_58 ( V_9 , V_244 , & V_9 -> V_87 ) ;
F_58 ( V_9 , V_245 , & V_9 -> V_157 ) ;
}
V_9 -> V_86 = 4 ;
if ( V_117 -> V_31 >= 0x10 ) {
F_10 ( V_9 -> V_32 , V_246 , & V_122 ) ;
F_58 ( V_9 , V_247 , & V_9 -> V_154 ) ;
if ( ( V_117 -> V_31 > 0x10 || V_117 -> V_180 > 7 ) && V_122 & F_50 ( 25 ) )
V_9 -> V_86 = 8 ;
}
F_52 ( V_9 ) ;
}
static T_1 F_125 ( struct V_8 * V_9 , T_2 V_13 , int V_248 )
{
T_1 V_148 , V_249 ;
T_1 V_153 = V_13 ? V_9 -> V_154 : V_9 -> V_155 ;
V_148 = ( V_153 >> ( ( V_248 / 2 ) * 4 ) ) & 0xF ;
V_249 = V_9 -> V_197 -> V_198 ( V_9 , V_13 , V_148 ) << ( 20 - V_71 ) ;
F_26 ( 0 , L_102 , V_248 , V_148 ) ;
F_26 ( 0 , L_103 ,
V_249 , V_9 -> V_250 ) ;
return V_249 ;
}
static int F_126 ( struct V_25 * V_26 )
{
struct V_251 * V_43 ;
struct V_252 * V_189 ;
struct V_8 * V_9 = V_26 -> V_28 ;
T_3 V_44 , V_45 ;
T_1 V_4 ;
int V_21 , V_151 , V_253 = 1 ;
enum V_101 V_254 ;
enum V_255 V_256 ;
int V_249 = 0 ;
F_10 ( V_9 -> V_32 , V_257 , & V_4 ) ;
V_9 -> V_144 = V_4 ;
F_26 ( 0 , L_104 ,
V_9 -> V_57 , V_4 ,
! ! ( V_4 & V_145 ) , ! ! ( V_4 & V_258 ) ) ;
F_30 (i, 0 , pvt) {
V_43 = V_26 -> V_259 [ V_21 ] ;
if ( ! F_31 ( V_21 , 0 , V_9 ) && ! F_31 ( V_21 , 1 , V_9 ) ) {
F_26 ( 1 , L_105 ,
V_21 , V_9 -> V_57 ) ;
continue;
}
V_253 = 0 ;
if ( F_31 ( V_21 , 0 , V_9 ) )
V_249 = F_125 ( V_9 , 0 , V_21 ) ;
if ( F_31 ( V_21 , 1 , V_9 ) )
V_249 += F_125 ( V_9 , 1 , V_21 ) ;
F_27 ( V_9 , V_21 , 0 , & V_44 , & V_45 ) ;
V_254 = F_60 ( V_9 , V_21 ) ;
F_26 ( 1 , L_106 , V_9 -> V_57 , V_21 ) ;
F_26 ( 1 , L_107 ,
V_249 * V_9 -> V_250 ) ;
if ( V_9 -> V_144 & V_258 )
V_256 = ( V_9 -> V_144 & V_145 ) ?
V_260 : V_261 ;
else
V_256 = V_262 ;
for ( V_151 = 0 ; V_151 < V_9 -> V_250 ; V_151 ++ ) {
V_189 = V_43 -> V_152 [ V_151 ] -> V_189 ;
V_189 -> V_254 = V_254 ;
V_189 -> V_256 = V_256 ;
V_189 -> V_249 = V_249 ;
}
}
return V_253 ;
}
static void F_127 ( struct V_263 * V_45 , unsigned V_35 )
{
int V_264 ;
F_128 (cpu)
if ( F_63 ( V_264 ) == V_35 )
F_129 ( V_264 , V_45 ) ;
}
static bool F_130 ( unsigned V_35 )
{
T_5 V_45 ;
int V_264 , V_265 ;
bool V_64 = false ;
if ( ! F_131 ( & V_45 , V_266 ) ) {
F_3 ( L_108 , V_42 ) ;
return false ;
}
F_127 ( V_45 , V_35 ) ;
F_132 ( V_45 , V_267 , V_268 ) ;
F_133 (cpu, mask) {
struct V_269 * V_14 = F_134 ( V_268 , V_264 ) ;
V_265 = V_14 -> V_270 & V_271 ;
F_26 ( 0 , L_109 ,
V_264 , V_14 -> V_272 ,
( V_265 ? L_30 : L_31 ) ) ;
if ( ! V_265 )
goto V_273;
}
V_64 = true ;
V_273:
F_135 ( V_45 ) ;
return V_64 ;
}
static int F_136 ( struct V_274 * V_209 , T_2 V_35 , bool V_275 )
{
T_5 V_276 ;
int V_264 ;
if ( ! F_131 ( & V_276 , V_266 ) ) {
F_3 ( L_110 , V_42 ) ;
return false ;
}
F_127 ( V_276 , V_35 ) ;
F_132 ( V_276 , V_267 , V_268 ) ;
F_133 (cpu, cmask) {
struct V_269 * V_14 = F_134 ( V_268 , V_264 ) ;
if ( V_275 ) {
if ( V_14 -> V_270 & V_271 )
V_209 -> V_277 . V_278 = 1 ;
V_14 -> V_270 |= V_271 ;
} else {
if ( ! V_209 -> V_277 . V_278 )
V_14 -> V_270 &= ~ V_271 ;
}
}
F_137 ( V_276 , V_267 , V_268 ) ;
F_135 ( V_276 ) ;
return 0 ;
}
static bool F_138 ( struct V_274 * V_209 , T_2 V_35 ,
struct V_1 * V_32 )
{
bool V_64 = true ;
T_1 V_279 , V_45 = 0x3 ;
if ( F_136 ( V_209 , V_35 , V_280 ) ) {
F_3 ( L_111 ) ;
return false ;
}
F_10 ( V_32 , V_281 , & V_279 ) ;
V_209 -> V_282 = V_279 & V_45 ;
V_209 -> V_283 = true ;
V_279 |= V_45 ;
F_11 ( V_32 , V_281 , V_279 ) ;
F_10 ( V_32 , V_257 , & V_279 ) ;
F_26 ( 0 , L_112 ,
V_35 , V_279 , ! ! ( V_279 & V_258 ) ) ;
if ( ! ( V_279 & V_258 ) ) {
F_3 ( L_113 ) ;
V_209 -> V_277 . V_284 = 0 ;
V_279 |= V_258 ;
F_11 ( V_32 , V_257 , V_279 ) ;
F_10 ( V_32 , V_257 , & V_279 ) ;
if ( ! ( V_279 & V_258 ) ) {
F_3 ( L_114
L_115 ) ;
V_64 = false ;
} else {
F_54 ( L_116 ) ;
}
} else {
V_209 -> V_277 . V_284 = 1 ;
}
F_26 ( 0 , L_117 ,
V_35 , V_279 , ! ! ( V_279 & V_258 ) ) ;
return V_64 ;
}
static void F_139 ( struct V_274 * V_209 , T_2 V_35 ,
struct V_1 * V_32 )
{
T_1 V_279 , V_45 = 0x3 ;
if ( ! V_209 -> V_283 )
return;
F_10 ( V_32 , V_281 , & V_279 ) ;
V_279 &= ~ V_45 ;
V_279 |= V_209 -> V_282 ;
F_11 ( V_32 , V_281 , V_279 ) ;
if ( ! V_209 -> V_277 . V_284 ) {
F_10 ( V_32 , V_257 , & V_279 ) ;
V_279 &= ~ V_258 ;
F_11 ( V_32 , V_257 , V_279 ) ;
}
if ( F_136 ( V_209 , V_35 , V_285 ) )
F_3 ( L_118 ) ;
}
static bool F_140 ( struct V_1 * V_32 , T_2 V_35 )
{
T_1 V_279 ;
T_2 V_286 = 0 ;
bool V_287 = false ;
F_10 ( V_32 , V_257 , & V_279 ) ;
V_286 = ! ! ( V_279 & V_258 ) ;
F_54 ( L_119 , ( V_286 ? L_30 : L_31 ) ) ;
V_287 = F_130 ( V_35 ) ;
if ( ! V_287 )
F_141 ( L_120
L_121 ,
V_267 , V_35 ) ;
if ( ! V_286 || ! V_287 ) {
F_141 ( L_122 , V_288 ) ;
return false ;
}
return true ;
}
static int F_142 ( struct V_25 * V_26 )
{
int V_289 ;
V_289 = F_143 ( V_26 ) ;
if ( V_289 < 0 )
return V_289 ;
if ( V_30 . V_31 >= 0x10 ) {
V_289 = F_144 ( V_26 ) ;
if ( V_289 < 0 )
return V_289 ;
}
return 0 ;
}
static void F_145 ( struct V_25 * V_26 )
{
F_146 ( V_26 ) ;
if ( V_30 . V_31 >= 0x10 )
F_147 ( V_26 ) ;
}
static void F_148 ( struct V_25 * V_26 ,
struct V_290 * V_291 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
V_26 -> V_292 = V_293 | V_294 ;
V_26 -> V_295 = V_75 ;
if ( V_9 -> V_80 & V_82 )
V_26 -> V_295 |= V_77 ;
if ( V_9 -> V_80 & V_83 )
V_26 -> V_295 |= V_296 ;
V_26 -> V_74 = F_49 ( V_9 ) ;
V_26 -> V_297 = V_298 ;
V_26 -> V_299 = V_300 ;
V_26 -> V_301 = V_291 -> V_301 ;
V_26 -> V_302 = F_121 ( V_9 -> V_12 ) ;
V_26 -> V_303 = NULL ;
V_26 -> V_304 = F_16 ;
V_26 -> V_305 = F_17 ;
}
static struct V_290 * F_149 ( struct V_8 * V_9 )
{
T_2 V_291 = V_30 . V_31 ;
struct V_290 * V_306 = NULL ;
switch ( V_291 ) {
case 0xf :
V_306 = & V_307 [ V_308 ] ;
V_9 -> V_197 = & V_307 [ V_308 ] . V_197 ;
break;
case 0x10 :
V_306 = & V_307 [ V_309 ] ;
V_9 -> V_197 = & V_307 [ V_309 ] . V_197 ;
break;
case 0x15 :
V_306 = & V_307 [ V_310 ] ;
V_9 -> V_197 = & V_307 [ V_310 ] . V_197 ;
break;
default:
F_120 ( L_123 ) ;
return NULL ;
}
V_9 -> V_51 = V_30 . V_180 >> 4 ;
F_54 ( L_124 , V_306 -> V_301 ,
( V_291 == 0xf ?
( V_9 -> V_51 >= V_52 ? L_125
: L_126 )
: L_26 ) , V_9 -> V_57 ) ;
return V_306 ;
}
static int F_150 ( struct V_1 * V_12 )
{
struct V_8 * V_9 = NULL ;
struct V_290 * V_306 = NULL ;
struct V_25 * V_26 = NULL ;
struct V_311 V_312 [ 2 ] ;
int V_6 = 0 , V_64 ;
T_2 V_35 = F_151 ( V_12 ) ;
V_64 = - V_313 ;
V_9 = F_152 ( sizeof( struct V_8 ) , V_266 ) ;
if ( ! V_9 )
goto V_314;
V_9 -> V_57 = V_35 ;
V_9 -> V_12 = V_12 ;
V_64 = - V_11 ;
V_306 = F_149 ( V_9 ) ;
if ( ! V_306 )
goto V_315;
V_64 = - V_230 ;
V_6 = F_119 ( V_9 , V_306 -> V_227 , V_306 -> V_228 ) ;
if ( V_6 )
goto V_315;
F_123 ( V_9 ) ;
V_64 = - V_11 ;
V_9 -> V_250 = V_9 -> V_197 -> V_316 ( V_9 ) ;
if ( V_9 -> V_250 < 0 )
goto V_317;
V_64 = - V_313 ;
V_312 [ 0 ] . type = V_318 ;
V_312 [ 0 ] . V_319 = V_9 -> V_53 [ 0 ] . V_88 ;
V_312 [ 0 ] . V_320 = true ;
V_312 [ 1 ] . type = V_321 ;
V_312 [ 1 ] . V_319 = V_9 -> V_250 ;
V_312 [ 1 ] . V_320 = false ;
V_26 = F_153 ( V_35 , F_14 ( V_312 ) , V_312 , 0 ) ;
if ( ! V_26 )
goto V_317;
V_26 -> V_28 = V_9 ;
V_26 -> V_2 = & V_9 -> V_12 -> V_202 ;
F_148 ( V_26 , V_306 ) ;
if ( F_126 ( V_26 ) )
V_26 -> V_74 = V_75 ;
V_64 = - V_230 ;
if ( F_154 ( V_26 ) ) {
F_26 ( 1 , L_127 ) ;
goto V_322;
}
if ( F_142 ( V_26 ) ) {
F_26 ( 1 , L_127 ) ;
goto V_323;
}
if ( V_324 )
F_155 ( true ) ;
F_156 ( F_118 ) ;
V_125 [ V_35 ] = V_26 ;
F_157 ( & V_325 ) ;
return 0 ;
V_323:
F_158 ( V_26 -> V_2 ) ;
V_322:
F_159 ( V_26 ) ;
V_317:
F_122 ( V_9 ) ;
V_315:
F_160 ( V_9 ) ;
V_314:
return V_64 ;
}
static int T_6 F_161 ( struct V_1 * V_2 ,
const struct V_326 * V_327 )
{
T_2 V_35 = F_151 ( V_2 ) ;
struct V_1 * V_32 = F_162 ( V_35 ) -> V_328 ;
struct V_274 * V_209 ;
int V_64 = 0 ;
V_64 = F_163 ( V_2 ) ;
if ( V_64 < 0 ) {
F_26 ( 0 , L_128 , V_64 ) ;
return - V_329 ;
}
V_64 = - V_313 ;
V_209 = F_152 ( sizeof( struct V_274 ) , V_266 ) ;
if ( ! V_209 )
goto V_330;
V_331 [ V_35 ] = V_209 ;
if ( ! F_140 ( V_32 , V_35 ) ) {
V_64 = - V_230 ;
if ( ! V_332 )
goto V_333;
F_3 ( L_129 ) ;
if ( ! F_138 ( V_209 , V_35 , V_32 ) )
goto V_333;
}
V_64 = F_150 ( V_2 ) ;
if ( V_64 < 0 ) {
F_120 ( L_130 , V_35 ) ;
F_139 ( V_209 , V_35 , V_32 ) ;
}
return V_64 ;
V_333:
F_160 ( V_209 ) ;
V_331 [ V_35 ] = NULL ;
V_330:
return V_64 ;
}
static void T_7 F_164 ( struct V_1 * V_2 )
{
struct V_25 * V_26 ;
struct V_8 * V_9 ;
T_2 V_35 = F_151 ( V_2 ) ;
struct V_1 * V_32 = F_162 ( V_35 ) -> V_328 ;
struct V_274 * V_209 = V_331 [ V_35 ] ;
V_26 = F_165 ( & V_2 -> V_202 ) ;
F_145 ( V_26 ) ;
V_26 = F_158 ( & V_2 -> V_202 ) ;
if ( ! V_26 )
return;
V_9 = V_26 -> V_28 ;
F_139 ( V_209 , V_35 , V_32 ) ;
F_122 ( V_9 ) ;
F_155 ( false ) ;
F_166 ( F_118 ) ;
F_160 ( V_331 [ V_35 ] ) ;
V_331 [ V_35 ] = NULL ;
V_26 -> V_28 = NULL ;
V_125 [ V_35 ] = NULL ;
F_160 ( V_9 ) ;
F_159 ( V_26 ) ;
}
static void F_167 ( void )
{
struct V_25 * V_26 ;
struct V_8 * V_9 ;
if ( V_334 )
return;
V_26 = V_125 [ 0 ] ;
if ( V_26 ) {
V_9 = V_26 -> V_28 ;
V_334 =
F_168 ( & V_9 -> V_12 -> V_202 , V_298 ) ;
if ( ! V_334 ) {
F_169 ( L_131 ,
V_42 ) ;
F_169 ( L_132 ,
V_42 ) ;
}
}
}
static int T_8 F_170 ( void )
{
int V_6 = - V_230 ;
F_171 ( V_335 L_133 , V_300 ) ;
F_172 () ;
if ( F_173 () < 0 )
goto V_314;
V_6 = - V_313 ;
V_125 = F_152 ( F_174 () * sizeof( V_125 [ 0 ] ) , V_266 ) ;
V_331 = F_152 ( F_174 () * sizeof( V_331 [ 0 ] ) , V_266 ) ;
if ( ! ( V_125 && V_331 ) )
goto V_315;
V_268 = F_175 () ;
if ( ! V_268 )
goto V_315;
V_6 = F_176 ( & V_336 ) ;
if ( V_6 )
goto V_337;
V_6 = - V_230 ;
if ( ! F_177 ( & V_325 ) )
goto V_338;
F_167 () ;
return 0 ;
V_338:
F_178 ( & V_336 ) ;
V_337:
F_179 ( V_268 ) ;
V_268 = NULL ;
V_315:
F_160 ( V_125 ) ;
V_125 = NULL ;
F_160 ( V_331 ) ;
V_331 = NULL ;
V_314:
return V_6 ;
}
static void T_9 F_180 ( void )
{
if ( V_334 )
F_181 ( V_334 ) ;
F_178 ( & V_336 ) ;
F_160 ( V_331 ) ;
V_331 = NULL ;
F_160 ( V_125 ) ;
V_125 = NULL ;
F_179 ( V_268 ) ;
V_268 = NULL ;
}
