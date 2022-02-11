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
V_14 &= ( V_9 -> V_17 >= 0x30 ) ? ~ 3 : ~ 1 ;
V_14 |= V_13 ;
F_11 ( V_9 -> V_15 , V_16 , V_14 ) ;
}
static int F_12 ( struct V_8 * V_9 , int V_10 , T_1 * V_4 ,
const char * V_5 )
{
T_2 V_13 = 0 ;
if ( V_10 >= 0x140 && V_10 <= 0x1a0 ) {
V_13 = ( V_9 -> V_17 >= 0x30 ) ? 3 : 1 ;
V_10 -= 0x100 ;
}
F_9 ( V_9 , V_13 ) ;
return F_1 ( V_9 -> V_12 , V_10 , V_4 , V_5 ) ;
}
static int F_13 ( struct V_1 * V_18 , T_1 V_19 , T_1 V_20 )
{
T_1 V_21 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < F_14 ( V_23 ) - 1 ; V_22 ++ ) {
if ( V_23 [ V_22 ] . V_21 < V_20 )
continue;
if ( V_23 [ V_22 ] . V_24 <= V_19 )
break;
}
V_21 = V_23 [ V_22 ] . V_21 ;
F_15 ( V_18 , V_25 , V_21 , 0x001F ) ;
if ( V_21 )
return V_23 [ V_22 ] . V_24 ;
return 0 ;
}
static int F_16 ( struct V_26 * V_27 , T_1 V_28 )
{
struct V_8 * V_9 = V_27 -> V_29 ;
T_1 V_30 = 0x5 ;
if ( V_9 -> V_31 == 0xf )
V_30 = 0x0 ;
if ( V_9 -> V_31 == 0x15 && V_9 -> V_17 < 0x10 )
F_9 ( V_9 , 0 ) ;
return F_13 ( V_9 -> V_32 , V_28 , V_30 ) ;
}
static int F_17 ( struct V_26 * V_27 )
{
struct V_8 * V_9 = V_27 -> V_29 ;
T_1 V_21 = 0 ;
int V_22 , V_33 = - V_11 ;
if ( V_9 -> V_31 == 0x15 && V_9 -> V_17 < 0x10 )
F_9 ( V_9 , 0 ) ;
F_10 ( V_9 -> V_32 , V_25 , & V_21 ) ;
V_21 = V_21 & 0x001F ;
for ( V_22 = 0 ; V_22 < F_14 ( V_23 ) ; V_22 ++ ) {
if ( V_23 [ V_22 ] . V_21 == V_21 ) {
V_33 = V_23 [ V_22 ] . V_24 ;
break;
}
}
return V_33 ;
}
static bool F_18 ( struct V_8 * V_9 , T_3 V_34 , T_2 V_35 )
{
T_3 V_10 ;
V_10 = V_34 & 0x000000ffffffffffull ;
return ( ( V_10 >= F_19 ( V_9 , V_35 ) ) &&
( V_10 <= F_20 ( V_9 , V_35 ) ) ) ;
}
static struct V_26 * F_21 ( struct V_26 * V_27 ,
T_3 V_34 )
{
struct V_8 * V_9 ;
T_2 V_36 ;
T_1 V_37 , V_38 ;
V_9 = V_27 -> V_29 ;
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
if ( V_9 -> V_31 == 0xf && V_9 -> V_51 < V_52 ) {
V_46 = V_9 -> V_53 [ V_13 ] . V_54 [ V_43 ] ;
V_47 = V_9 -> V_53 [ V_13 ] . V_55 [ V_43 ] ;
V_48 = F_28 ( 31 , 21 ) | F_28 ( 15 , 9 ) ;
V_49 = F_28 ( 29 , 21 ) | F_28 ( 15 , 9 ) ;
V_50 = 4 ;
} else if ( V_9 -> V_31 == 0x16 ||
( V_9 -> V_31 == 0x15 && V_9 -> V_17 >= 0x30 ) ) {
V_46 = V_9 -> V_53 [ V_13 ] . V_54 [ V_43 ] ;
V_47 = V_9 -> V_53 [ V_13 ] . V_55 [ V_43 >> 1 ] ;
* V_44 = ( V_46 & F_28 ( 15 , 5 ) ) << 6 ;
* V_44 |= ( V_46 & F_28 ( 30 , 19 ) ) << 8 ;
* V_45 = ~ 0ULL ;
* V_45 &= ~ ( ( F_28 ( 15 , 5 ) << 6 ) |
( F_28 ( 30 , 19 ) << 8 ) ) ;
* V_45 |= ( V_47 & F_28 ( 15 , 5 ) ) << 6 ;
* V_45 |= ( V_47 & F_28 ( 30 , 19 ) ) << 8 ;
return;
} else {
V_46 = V_9 -> V_53 [ V_13 ] . V_54 [ V_43 ] ;
V_47 = V_9 -> V_53 [ V_13 ] . V_55 [ V_43 >> 1 ] ;
V_50 = 8 ;
if ( V_9 -> V_31 == 0x15 )
V_48 = V_49 =
F_28 ( 30 , 19 ) | F_28 ( 13 , 5 ) ;
else
V_48 = V_49 =
F_28 ( 28 , 19 ) | F_28 ( 13 , 5 ) ;
}
* V_44 = ( V_46 & V_48 ) << V_50 ;
* V_45 = ~ 0ULL ;
* V_45 &= ~ ( V_49 << V_50 ) ;
* V_45 |= ( V_47 & V_49 ) << V_50 ;
}
static int F_29 ( struct V_26 * V_27 , T_3 V_56 )
{
struct V_8 * V_9 ;
int V_43 ;
T_3 V_44 , V_45 ;
V_9 = V_27 -> V_29 ;
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
int F_32 ( struct V_26 * V_27 , T_3 * V_58 ,
T_3 * V_59 , T_3 * V_60 )
{
struct V_8 * V_9 = V_27 -> V_29 ;
if ( V_9 -> V_31 == 0xf && V_9 -> V_51 < V_61 ) {
F_26 ( 1 , L_9 ,
V_9 -> V_51 , V_9 -> V_57 ) ;
return 1 ;
}
if ( V_9 -> V_31 >= 0x10 && ! F_33 ( V_9 ) ) {
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
* V_59 = ( V_9 -> V_31 > 0xf ) ? F_36 ( V_9 )
: F_37 ( V_9 ) ;
F_26 ( 1 , L_12 ,
V_9 -> V_57 , ( unsigned long ) * V_58 ,
( unsigned long ) * V_59 , ( unsigned long ) * V_60 ) ;
return 0 ;
}
static T_3 F_38 ( struct V_26 * V_27 , T_3 V_34 )
{
struct V_8 * V_9 = V_27 -> V_29 ;
T_3 V_62 , V_58 , V_59 , V_60 , V_63 ;
int V_64 ;
V_62 = F_19 ( V_9 , V_9 -> V_57 ) ;
V_64 = F_32 ( V_27 , & V_58 , & V_59 ,
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
V_63 = ( V_34 & F_28 ( 39 , 0 ) ) - V_62 ;
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
static T_3 F_41 ( struct V_26 * V_27 , T_3 V_63 )
{
struct V_8 * V_9 ;
int V_67 ;
T_3 V_56 ;
V_9 = V_27 -> V_29 ;
V_67 = F_39 ( F_22 ( V_9 , 0 ) ) ;
V_56 = ( ( V_63 >> V_67 ) & F_28 ( 35 , 12 ) ) +
( V_63 & 0xfff ) ;
F_26 ( 2 , L_15 ,
V_67 , ( unsigned long ) V_63 ,
( unsigned long ) V_56 ) ;
return V_56 ;
}
static T_3 F_42 ( struct V_26 * V_27 , T_3 V_34 )
{
T_3 V_56 ;
V_56 =
F_41 ( V_27 , F_38 ( V_27 , V_34 ) ) ;
F_26 ( 2 , L_16 ,
( unsigned long ) V_34 , ( unsigned long ) V_56 ) ;
return V_56 ;
}
static inline void F_43 ( T_3 V_68 ,
struct V_69 * V_6 )
{
V_6 -> V_70 = ( T_1 ) ( V_68 >> V_71 ) ;
V_6 -> V_3 = ( ( T_1 ) V_68 ) & ~ V_72 ;
}
static int F_44 ( struct V_26 * V_27 , T_3 V_34 )
{
int V_43 ;
V_43 = F_29 ( V_27 , F_42 ( V_27 , V_34 ) ) ;
if ( V_43 == - 1 )
F_45 ( V_27 , L_17
L_18 , ( unsigned long ) V_34 ) ;
return V_43 ;
}
static unsigned long F_46 ( struct V_8 * V_9 )
{
T_2 V_73 ;
unsigned long V_74 = V_75 ;
V_73 = ( V_9 -> V_31 > 0xf || V_9 -> V_51 >= V_52 )
? 19
: 17 ;
if ( V_9 -> V_76 & F_47 ( V_73 ) )
V_74 = V_77 ;
return V_74 ;
}
static void F_48 ( struct V_8 * V_9 , T_1 V_78 , int V_79 )
{
F_26 ( 1 , L_19 , V_79 , V_78 ) ;
F_26 ( 1 , L_20 ,
( V_78 & F_47 ( 16 ) ) ? L_21 : L_22 ,
( V_78 & F_47 ( 19 ) ) ? L_23 : L_24 ) ;
F_26 ( 1 , L_25 ,
( V_78 & F_47 ( 8 ) ) ? L_26 : L_27 ) ;
if ( V_9 -> V_31 == 0x10 )
F_26 ( 1 , L_28 ,
( V_78 & F_47 ( 11 ) ) ? L_29 : L_30 ) ;
F_26 ( 1 , L_31 ,
( V_78 & F_47 ( 12 ) ) ? L_23 : L_24 ,
( V_78 & F_47 ( 13 ) ) ? L_23 : L_24 ,
( V_78 & F_47 ( 14 ) ) ? L_23 : L_24 ,
( V_78 & F_47 ( 15 ) ) ? L_23 : L_24 ) ;
}
static void F_49 ( struct V_8 * V_9 )
{
F_26 ( 1 , L_32 , V_9 -> V_80 ) ;
F_26 ( 1 , L_33 ,
( V_9 -> V_80 & V_81 ) ? L_23 : L_24 ) ;
F_26 ( 1 , L_34 ,
( V_9 -> V_80 & V_82 ) ? L_23 : L_24 ,
( V_9 -> V_80 & V_83 ) ? L_23 : L_24 ) ;
F_48 ( V_9 , V_9 -> V_76 , 0 ) ;
F_26 ( 1 , L_35 , V_9 -> V_84 ) ;
F_26 ( 1 , L_36 ,
V_9 -> V_85 , F_35 ( V_9 ) ,
( V_9 -> V_31 == 0xf ) ? F_37 ( V_9 )
: F_36 ( V_9 ) ) ;
F_26 ( 1 , L_37 , F_34 ( V_9 ) ? L_23 : L_24 ) ;
F_50 ( V_9 , 0 ) ;
if ( V_9 -> V_31 == 0xf )
return;
F_50 ( V_9 , 1 ) ;
F_51 ( L_38 , ( ( V_9 -> V_86 == 8 ) ? L_39 : L_40 ) ) ;
if ( ! F_52 ( V_9 ) )
F_48 ( V_9 , V_9 -> V_87 , 1 ) ;
}
static void F_53 ( struct V_8 * V_9 )
{
if ( V_9 -> V_31 == 0xf && V_9 -> V_51 < V_52 ) {
V_9 -> V_53 [ 0 ] . V_88 = V_9 -> V_53 [ 1 ] . V_88 = 8 ;
V_9 -> V_53 [ 0 ] . V_89 = V_9 -> V_53 [ 1 ] . V_89 = 8 ;
} else if ( V_9 -> V_31 == 0x15 && V_9 -> V_17 >= 0x30 ) {
V_9 -> V_53 [ 0 ] . V_88 = V_9 -> V_53 [ 1 ] . V_88 = 4 ;
V_9 -> V_53 [ 0 ] . V_89 = V_9 -> V_53 [ 1 ] . V_89 = 2 ;
} else {
V_9 -> V_53 [ 0 ] . V_88 = V_9 -> V_53 [ 1 ] . V_88 = 8 ;
V_9 -> V_53 [ 0 ] . V_89 = V_9 -> V_53 [ 1 ] . V_89 = 4 ;
}
}
static void F_54 ( struct V_8 * V_9 )
{
int V_90 ;
F_53 ( V_9 ) ;
F_30 (cs, 0 , pvt) {
int V_91 = V_92 + ( V_90 * 4 ) ;
int V_93 = V_94 + ( V_90 * 4 ) ;
T_1 * V_95 = & V_9 -> V_53 [ 0 ] . V_54 [ V_90 ] ;
T_1 * V_96 = & V_9 -> V_53 [ 1 ] . V_54 [ V_90 ] ;
if ( ! F_55 ( V_9 , V_91 , V_95 ) )
F_26 ( 0 , L_41 ,
V_90 , * V_95 , V_91 ) ;
if ( V_9 -> V_31 == 0xf || F_52 ( V_9 ) )
continue;
if ( ! F_55 ( V_9 , V_93 , V_96 ) )
F_26 ( 0 , L_42 ,
V_90 , * V_96 , V_93 ) ;
}
F_56 (cs, 0 , pvt) {
int V_91 = V_97 + ( V_90 * 4 ) ;
int V_93 = V_98 + ( V_90 * 4 ) ;
T_1 * V_99 = & V_9 -> V_53 [ 0 ] . V_55 [ V_90 ] ;
T_1 * V_100 = & V_9 -> V_53 [ 1 ] . V_55 [ V_90 ] ;
if ( ! F_55 ( V_9 , V_91 , V_99 ) )
F_26 ( 0 , L_43 ,
V_90 , * V_99 , V_91 ) ;
if ( V_9 -> V_31 == 0xf || F_52 ( V_9 ) )
continue;
if ( ! F_55 ( V_9 , V_93 , V_100 ) )
F_26 ( 0 , L_44 ,
V_90 , * V_100 , V_93 ) ;
}
}
static enum V_101 F_57 ( struct V_8 * V_9 , int V_90 )
{
enum V_101 type ;
if ( V_9 -> V_31 >= 0x15 )
type = ( V_9 -> V_76 & F_47 ( 16 ) ) ? V_102 : V_103 ;
else if ( V_9 -> V_31 == 0x10 || V_9 -> V_51 >= V_52 ) {
if ( V_9 -> V_104 & V_105 )
type = ( V_9 -> V_76 & F_47 ( 16 ) ) ? V_102 : V_103 ;
else
type = ( V_9 -> V_76 & F_47 ( 16 ) ) ? V_106 : V_107 ;
} else {
type = ( V_9 -> V_76 & F_47 ( 18 ) ) ? V_108 : V_109 ;
}
F_51 ( L_45 , V_90 , V_110 [ type ] ) ;
return type ;
}
static int F_58 ( struct V_8 * V_9 )
{
int V_111 ;
if ( V_9 -> V_51 >= V_52 )
V_111 = V_9 -> V_76 & V_112 ;
else
V_111 = V_9 -> V_76 & V_113 ;
V_9 -> V_87 = 0 ;
return ( V_111 ) ? 2 : 1 ;
}
static T_3 F_59 ( struct V_8 * V_9 , struct V_114 * V_115 )
{
T_3 V_10 ;
T_2 V_116 = 1 ;
T_2 V_117 = 47 ;
if ( V_9 -> V_31 == 0xf ) {
V_116 = 3 ;
V_117 = 39 ;
}
V_10 = V_115 -> V_10 & F_28 ( V_117 , V_116 ) ;
if ( V_9 -> V_31 == 0x15 ) {
struct V_8 * V_9 ;
T_3 V_118 , V_119 ;
T_1 V_120 ;
T_4 V_121 ;
T_2 V_37 ;
if ( ( V_10 & F_28 ( 47 , 24 ) ) >> 24 != 0x00fdf7 )
return V_10 ;
V_121 = F_60 ( V_115 -> V_122 ) ;
V_9 = V_123 [ V_121 ] -> V_29 ;
F_10 ( V_9 -> V_15 , V_124 , & V_120 ) ;
V_37 = V_120 >> 21 & 0x7 ;
V_118 = ( V_120 & F_28 ( 20 , 0 ) ) << 3 ;
V_118 |= V_37 ^ 0x7 ;
V_118 <<= 24 ;
if ( ! V_37 )
return V_118 | ( V_10 & F_28 ( 23 , 0 ) ) ;
F_10 ( V_9 -> V_15 , V_125 , & V_120 ) ;
V_119 = ( V_10 & F_28 ( 23 , 12 ) ) << F_61 ( V_37 + 1 ) ;
V_119 |= ( V_120 & F_28 ( 23 , 21 ) ) >> 9 ;
V_119 |= V_10 & F_28 ( 11 , 0 ) ;
return V_118 | V_119 ;
}
return V_10 ;
}
static struct V_1 * F_62 ( unsigned int V_126 ,
unsigned int V_127 ,
struct V_1 * V_128 )
{
struct V_1 * V_129 = NULL ;
while ( ( V_129 = F_63 ( V_126 , V_127 , V_129 ) ) ) {
if ( F_64 ( V_129 -> V_130 ) == F_64 ( V_128 -> V_130 ) &&
( V_129 -> V_130 -> V_131 == V_128 -> V_130 -> V_131 ) &&
( F_65 ( V_129 -> V_7 ) == F_65 ( V_128 -> V_7 ) ) )
break;
}
return V_129 ;
}
static void F_66 ( struct V_8 * V_9 , unsigned V_132 )
{
struct V_133 * V_134 ;
struct V_1 * V_135 = NULL ;
unsigned int V_136 ;
int V_137 = V_132 << 3 ;
T_1 V_138 ;
F_10 ( V_9 -> V_15 , V_139 + V_137 , & V_9 -> V_140 [ V_132 ] . V_44 . V_141 ) ;
F_10 ( V_9 -> V_15 , V_142 + V_137 , & V_9 -> V_140 [ V_132 ] . V_143 . V_141 ) ;
if ( V_9 -> V_31 == 0xf )
return;
if ( ! F_67 ( V_9 , V_132 ) )
return;
F_10 ( V_9 -> V_15 , V_144 + V_137 , & V_9 -> V_140 [ V_132 ] . V_44 . V_145 ) ;
F_10 ( V_9 -> V_15 , V_146 + V_137 , & V_9 -> V_140 [ V_132 ] . V_143 . V_145 ) ;
if ( V_9 -> V_31 != 0x15 )
return;
V_134 = F_68 ( F_69 ( V_9 , V_132 ) ) ;
if ( F_70 ( ! V_134 ) )
return;
V_136 = ( V_9 -> V_17 == 0x30 ) ? V_147
: V_148 ;
V_135 = F_62 ( V_134 -> V_149 -> V_126 , V_136 , V_134 -> V_149 ) ;
if ( F_70 ( ! V_135 ) )
return;
F_10 ( V_135 , V_124 , & V_138 ) ;
V_9 -> V_140 [ V_132 ] . V_143 . V_141 &= F_28 ( 15 , 0 ) ;
V_9 -> V_140 [ V_132 ] . V_143 . V_141 |= ( ( V_138 & 0x1fff ) << 3 | 0x7 ) << 16 ;
V_9 -> V_140 [ V_132 ] . V_143 . V_145 &= F_28 ( 7 , 0 ) ;
V_9 -> V_140 [ V_132 ] . V_143 . V_145 |= V_138 >> 13 ;
F_71 ( V_135 ) ;
}
static void F_72 ( struct V_26 * V_27 , T_3 V_34 ,
struct V_69 * V_6 )
{
struct V_8 * V_9 = V_27 -> V_29 ;
F_43 ( V_34 , V_6 ) ;
V_6 -> V_150 = F_21 ( V_27 , V_34 ) ;
if ( ! V_6 -> V_150 ) {
F_45 ( V_27 , L_46 ,
( unsigned long ) V_34 ) ;
V_6 -> V_151 = V_152 ;
return;
}
V_6 -> V_43 = F_44 ( V_6 -> V_150 , V_34 ) ;
if ( V_6 -> V_43 < 0 ) {
V_6 -> V_151 = V_153 ;
return;
}
if ( V_9 -> V_154 & V_155 ) {
V_6 -> V_156 = F_73 ( V_27 , V_6 -> V_157 ) ;
if ( V_6 -> V_156 < 0 ) {
F_74 ( V_6 -> V_150 , L_47
L_48 ,
V_6 -> V_157 ) ;
V_6 -> V_151 = V_158 ;
return;
}
} else {
V_6 -> V_156 = ( ( V_34 & F_47 ( 3 ) ) != 0 ) ;
}
}
static int F_75 ( unsigned V_22 , bool V_159 )
{
unsigned V_160 = 0 ;
if ( V_22 <= 2 )
V_160 = V_22 ;
else if ( ! ( V_22 & 0x1 ) )
V_160 = V_22 >> 1 ;
else
V_160 = ( V_22 + 1 ) >> 1 ;
return 128 << ( V_160 + ! ! V_159 ) ;
}
static int F_76 ( struct V_8 * V_9 , T_2 V_13 ,
unsigned V_161 )
{
T_1 V_78 = V_13 ? V_9 -> V_87 : V_9 -> V_76 ;
if ( V_9 -> V_51 >= V_52 ) {
F_70 ( V_161 > 11 ) ;
return F_75 ( V_161 , V_78 & V_112 ) ;
}
else if ( V_9 -> V_51 >= V_162 ) {
unsigned V_163 ;
F_70 ( V_161 > 10 ) ;
V_163 = V_161 / 3 + ( unsigned ) ( V_161 > 5 ) ;
return 32 << ( V_161 - V_163 ) ;
}
else {
F_70 ( V_161 > 6 ) ;
return 32 << V_161 ;
}
}
static int F_77 ( struct V_8 * V_9 )
{
int V_22 , V_164 , V_165 = 0 ;
if ( V_9 -> V_31 == 0x10 && ( V_9 -> V_76 & V_112 ) )
return 2 ;
F_26 ( 0 , L_49 ) ;
for ( V_22 = 0 ; V_22 < 2 ; V_22 ++ ) {
T_1 V_166 = ( V_22 ? V_9 -> V_167 : V_9 -> V_168 ) ;
for ( V_164 = 0 ; V_164 < 4 ; V_164 ++ ) {
if ( F_78 ( V_164 , V_166 ) > 0 ) {
V_165 ++ ;
break;
}
}
}
if ( V_165 > 2 )
V_165 = 2 ;
F_51 ( L_50 , V_165 ) ;
return V_165 ;
}
static int F_79 ( unsigned V_22 , bool V_159 )
{
unsigned V_160 = 0 ;
int V_169 = 0 ;
if ( V_22 == 0 || V_22 == 3 || V_22 == 4 )
V_169 = - 1 ;
else if ( V_22 <= 2 )
V_160 = V_22 ;
else if ( V_22 == 12 )
V_160 = 7 ;
else if ( ! ( V_22 & 0x1 ) )
V_160 = V_22 >> 1 ;
else
V_160 = ( V_22 + 1 ) >> 1 ;
if ( V_169 != - 1 )
V_169 = ( 128 * ( 1 << ! ! V_159 ) ) << V_160 ;
return V_169 ;
}
static int F_80 ( struct V_8 * V_9 , T_2 V_13 ,
unsigned V_161 )
{
T_1 V_78 = V_13 ? V_9 -> V_87 : V_9 -> V_76 ;
F_70 ( V_161 > 11 ) ;
if ( V_9 -> V_104 & V_105 || V_9 -> V_170 & V_105 )
return F_79 ( V_161 , V_78 & V_112 ) ;
else
return F_75 ( V_161 , V_78 & V_112 ) ;
}
static int F_81 ( struct V_8 * V_9 , T_2 V_13 ,
unsigned V_161 )
{
F_70 ( V_161 > 12 ) ;
return F_79 ( V_161 , false ) ;
}
static int F_82 ( struct V_8 * V_9 , T_2 V_13 ,
unsigned V_161 )
{
F_70 ( V_161 > 12 ) ;
if ( V_161 == 6 || V_161 == 8 ||
V_161 == 9 || V_161 == 12 )
return - 1 ;
else
return F_79 ( V_161 , false ) ;
}
static void F_83 ( struct V_8 * V_9 )
{
if ( V_9 -> V_31 == 0xf )
return;
if ( ! F_55 ( V_9 , V_171 , & V_9 -> V_172 ) ) {
F_26 ( 0 , L_51 ,
V_9 -> V_172 , F_84 ( V_9 ) ) ;
F_26 ( 0 , L_52 ,
( F_52 ( V_9 ) ? L_53 : L_54 ) ) ;
if ( ! F_52 ( V_9 ) )
F_26 ( 0 , L_55 ,
( F_85 ( V_9 ) ? L_23 : L_24 ) ) ;
F_26 ( 0 , L_56 ,
( F_86 ( V_9 ) ? L_26 : L_27 ) ,
( F_87 ( V_9 ) ? L_23 : L_24 ) ) ;
F_26 ( 0 , L_57
L_58 ,
( F_88 ( V_9 ) ? L_26 : L_27 ) ,
F_89 ( V_9 ) ) ;
}
F_55 ( V_9 , V_173 , & V_9 -> V_174 ) ;
}
static T_2 F_90 ( struct V_8 * V_9 , T_3 V_34 ,
T_2 V_37 , int V_175 ,
T_1 V_176 )
{
T_2 V_156 = 0 ;
T_2 V_177 ;
if ( ! ( V_37 ) )
return ( T_2 ) ( V_176 ) ;
if ( V_175 == 2 ) {
V_177 = ( V_34 >> 8 ) & 0x3 ;
V_156 = V_177 ? 0x3 : 0 ;
} else if ( V_175 == 4 )
V_156 = ( V_34 >> 8 ) & 0x7 ;
return V_156 ;
}
static T_2 F_91 ( struct V_8 * V_9 , T_3 V_34 ,
bool V_178 , T_2 V_37 )
{
T_2 V_179 = ( V_9 -> V_172 >> 1 ) & 1 ;
if ( F_52 ( V_9 ) )
return 0 ;
if ( V_178 )
return V_179 ;
if ( F_88 ( V_9 ) ) {
T_2 V_180 = F_89 ( V_9 ) ;
if ( ! V_180 )
return V_34 >> 6 & 1 ;
if ( V_180 & 0x2 ) {
T_2 V_160 = V_180 & 0x1 ? 9 : 6 ;
T_1 V_181 = F_92 ( ( T_1 ) ( ( V_34 >> 16 ) & 0x1F ) ) % 2 ;
return ( ( V_34 >> V_160 ) & 1 ) ^ V_181 ;
}
return ( V_34 >> ( 12 + F_93 ( V_37 ) ) ) & 1 ;
}
if ( F_85 ( V_9 ) )
return ~ V_179 & 1 ;
return 0 ;
}
static T_3 F_94 ( struct V_8 * V_9 , T_2 V_132 ,
T_3 V_34 , bool V_182 ,
T_1 V_183 )
{
T_3 V_184 ;
T_3 V_62 = F_19 ( V_9 , V_132 ) ;
T_3 V_185 = F_36 ( V_9 ) ;
T_3 V_186 = ( V_9 -> V_174 & 0xFFFFFC00 ) << 16 ;
if ( V_182 ) {
if ( ( ! ( V_183 >> 16 ) ||
V_183 < F_35 ( V_9 ) ) &&
F_34 ( V_9 ) &&
( V_34 >= F_95 ( 32 ) ) )
V_184 = V_185 ;
else
V_184 = V_186 ;
} else {
if ( F_34 ( V_9 ) && ( V_34 >= F_95 ( 32 ) ) )
V_184 = V_185 ;
else
V_184 = V_62 ;
}
return ( V_34 & F_28 ( 47 , 6 ) ) - ( V_184 & F_28 ( 47 , 23 ) ) ;
}
static int F_96 ( struct V_8 * V_9 , T_2 V_13 , int V_43 )
{
int V_187 ;
if ( F_97 ( V_9 , V_13 ) &&
V_43 == F_98 ( V_9 , V_13 ) ) {
F_30 (tmp_cs, dct, pvt) {
if ( F_99 ( V_187 , V_13 , V_9 ) & 0x2 ) {
V_43 = V_187 ;
break;
}
}
}
return V_43 ;
}
static int F_100 ( T_3 V_188 , T_2 V_35 , T_2 V_13 )
{
struct V_26 * V_27 ;
struct V_8 * V_9 ;
T_3 V_189 , V_190 ;
int V_191 = - V_11 ;
int V_43 ;
V_27 = V_123 [ V_35 ] ;
if ( ! V_27 )
return V_191 ;
V_9 = V_27 -> V_29 ;
F_26 ( 1 , L_59 , V_188 , V_13 ) ;
F_30 (csrow, dct, pvt) {
if ( ! F_31 ( V_43 , V_13 , V_9 ) )
continue;
F_27 ( V_9 , V_43 , V_13 , & V_189 , & V_190 ) ;
F_26 ( 1 , L_60 ,
V_43 , V_189 , V_190 ) ;
V_190 = ~ V_190 ;
F_26 ( 1 , L_61 ,
( V_188 & V_190 ) , ( V_189 & V_190 ) ) ;
if ( ( V_188 & V_190 ) == ( V_189 & V_190 ) ) {
if ( V_9 -> V_31 == 0x15 && V_9 -> V_17 >= 0x30 ) {
V_191 = V_43 ;
break;
}
V_191 = F_96 ( V_9 , V_13 , V_43 ) ;
F_26 ( 1 , L_62 , V_191 ) ;
break;
}
}
return V_191 ;
}
static T_3 F_101 ( struct V_8 * V_9 , T_3 V_34 )
{
T_1 V_192 , V_193 , V_194 , V_195 , V_119 ;
if ( V_9 -> V_31 == 0x10 ) {
if ( V_9 -> V_17 < 4 || ( V_9 -> V_17 < 0xa && V_9 -> V_196 < 3 ) )
return V_34 ;
}
F_55 ( V_9 , V_197 , & V_192 ) ;
if ( ! ( V_192 & 0x1 ) )
return V_34 ;
V_193 = ( V_192 >> 3 ) & 0x7f ;
V_194 = ( V_192 >> 11 ) & 0x7f ;
V_195 = ( V_192 >> 20 ) & 0x7f ;
V_119 = V_34 >> 27 ;
if ( ! ( V_34 >> 34 ) &&
( ( ( V_119 >= V_193 ) &&
( V_119 <= V_194 ) ) ||
( V_119 < V_195 ) ) )
return V_34 ^ ( T_3 ) V_193 << 27 ;
return V_34 ;
}
static int F_102 ( struct V_8 * V_9 , unsigned V_132 ,
T_3 V_34 , int * V_198 )
{
int V_191 = - V_11 ;
T_3 V_199 ;
T_1 V_200 ;
T_2 V_156 ;
bool V_201 = false ;
T_2 V_36 = F_69 ( V_9 , V_132 ) ;
T_2 V_37 = F_22 ( V_9 , V_132 ) ;
T_1 V_202 = F_24 ( V_9 , V_132 ) ;
F_26 ( 1 , L_63 ,
V_132 , V_34 , F_20 ( V_9 , V_132 ) ) ;
if ( F_34 ( V_9 ) &&
F_35 ( V_9 ) <= V_34 &&
V_34 < F_95 ( 32 ) ) {
F_3 ( L_64 ,
V_34 ) ;
return - V_11 ;
}
if ( V_37 && ( V_202 != ( ( V_34 >> 12 ) & V_37 ) ) )
return - V_11 ;
V_34 = F_101 ( V_9 , V_34 ) ;
V_200 = F_84 ( V_9 ) ;
if ( F_85 ( V_9 ) &&
! F_52 ( V_9 ) &&
( ( V_34 >> 27 ) >= ( V_200 >> 11 ) ) )
V_201 = true ;
V_156 = F_91 ( V_9 , V_34 , V_201 , V_37 ) ;
V_199 = F_94 ( V_9 , V_132 , V_34 ,
V_201 , V_200 ) ;
if ( V_37 )
V_199 = ( ( V_199 >> ( 12 + F_93 ( V_37 ) ) ) << 12 ) |
( V_199 & 0xfff ) ;
if ( F_88 ( V_9 ) &&
! F_85 ( V_9 ) &&
! F_52 ( V_9 ) ) {
if ( F_89 ( V_9 ) != 1 ) {
if ( F_89 ( V_9 ) == 0x3 )
V_199 = ( ( V_199 >> 10 ) << 9 ) |
( V_199 & 0x1ff ) ;
else
V_199 = ( ( V_199 >> 7 ) << 6 ) |
( V_199 & 0x3f ) ;
} else
V_199 = ( ( V_199 >> 13 ) << 12 ) |
( V_199 & 0xfff ) ;
}
F_26 ( 1 , L_65 , V_199 ) ;
V_191 = F_100 ( V_199 , V_36 , V_156 ) ;
if ( V_191 >= 0 )
* V_198 = V_156 ;
return V_191 ;
}
static int F_103 ( struct V_8 * V_9 , unsigned V_132 ,
T_3 V_34 , int * V_198 )
{
int V_191 = - V_11 ;
int V_175 = 0 ;
T_3 V_199 , V_203 ;
T_3 V_204 , V_205 ;
T_1 V_206 , V_207 , V_120 ;
T_2 V_156 , V_208 , V_209 , V_176 , V_210 ;
T_3 V_211 = F_36 ( V_9 ) ;
T_2 V_180 = F_89 ( V_9 ) ;
T_2 V_36 = F_69 ( V_9 , V_132 ) ;
T_2 V_37 = F_22 ( V_9 , V_132 ) ;
F_10 ( V_9 -> V_15 , V_212 , & V_206 ) ;
F_10 ( V_9 -> V_15 , V_213 , & V_207 ) ;
V_210 = ( T_2 ) ( ( V_206 >> 3 ) & F_47 ( 0 ) ) ;
V_176 = ( T_2 ) ( ( V_206 >> 4 ) & 0x7 ) ;
F_26 ( 1 , L_63 ,
V_132 , V_34 , F_20 ( V_9 , V_132 ) ) ;
if ( ! ( F_19 ( V_9 , V_132 ) <= V_34 ) &&
! ( F_20 ( V_9 , V_132 ) >= V_34 ) )
return - V_11 ;
if ( F_34 ( V_9 ) &&
F_35 ( V_9 ) <= V_34 &&
V_34 < F_95 ( 32 ) ) {
F_3 ( L_64 ,
V_34 ) ;
return - V_11 ;
}
V_204 = ( T_3 ) F_84 ( V_9 ) ;
V_205 = ( V_207 >> 11 ) & 0x1FFF ;
if ( ! ( V_206 & F_47 ( 0 ) ) &&
! ( V_204 <= ( V_34 >> 27 ) &&
V_205 >= ( V_34 >> 27 ) ) )
return - V_11 ;
V_175 = ( int ) F_93 ( V_37 ) ;
if ( ! ( V_175 % 2 == 0 ) || ( V_175 > 4 ) )
return - V_11 ;
V_156 = F_90 ( V_9 , V_34 , V_37 ,
V_175 , V_176 ) ;
if ( V_156 > 3 )
return - V_11 ;
V_209 = ( T_2 ) ( V_206 >> 1 & F_47 ( 0 ) ) ;
if ( V_209 && ( V_34 >= F_95 ( 32 ) ) )
V_203 = V_211 ;
else
V_203 = V_204 << 27 ;
V_199 = V_34 - V_203 ;
if ( V_175 == 2 ) {
if ( V_180 == 0x4 )
V_199 = ( ( V_199 >> 9 ) << 8 ) |
( V_199 & 0xff ) ;
else if ( V_180 == 0x5 )
V_199 = ( ( V_199 >> 10 ) << 9 ) |
( V_199 & 0x1ff ) ;
else
return - V_11 ;
} else if ( V_175 == 4 ) {
if ( V_180 == 0x4 )
V_199 = ( ( V_199 >> 10 ) << 8 ) |
( V_199 & 0xff ) ;
else if ( V_180 == 0x5 )
V_199 = ( ( V_199 >> 11 ) << 9 ) |
( V_199 & 0x1ff ) ;
else
return - V_11 ;
}
if ( V_210 ) {
F_10 ( V_9 -> V_15 ,
V_214 + ( int ) V_156 * 4 ,
& V_120 ) ;
V_199 += ( T_3 ) ( ( V_120 >> 11 ) & 0xfff ) << 27 ;
}
F_9 ( V_9 , V_156 ) ;
F_26 ( 1 , L_65 , V_199 ) ;
V_208 = ( V_156 == 3 ) ? 1 : V_156 ;
V_191 = F_100 ( V_199 , V_36 , V_208 ) ;
if ( V_191 >= 0 )
* V_198 = V_208 ;
return V_191 ;
}
static int F_104 ( struct V_8 * V_9 ,
T_3 V_34 ,
int * V_198 )
{
int V_191 = - V_11 ;
unsigned V_132 ;
for ( V_132 = 0 ; V_132 < V_39 ; V_132 ++ ) {
if ( ! F_67 ( V_9 , V_132 ) )
continue;
if ( V_9 -> V_31 == 0x15 && V_9 -> V_17 >= 0x30 )
V_191 = F_103 ( V_9 , V_132 ,
V_34 ,
V_198 ) ;
else if ( ( F_19 ( V_9 , V_132 ) <= V_34 ) &&
( F_20 ( V_9 , V_132 ) >= V_34 ) ) {
V_191 = F_102 ( V_9 , V_132 ,
V_34 , V_198 ) ;
if ( V_191 >= 0 )
break;
}
}
return V_191 ;
}
static void F_105 ( struct V_26 * V_27 , T_3 V_34 ,
struct V_69 * V_6 )
{
struct V_8 * V_9 = V_27 -> V_29 ;
F_43 ( V_34 , V_6 ) ;
V_6 -> V_43 = F_104 ( V_9 , V_34 , & V_6 -> V_156 ) ;
if ( V_6 -> V_43 < 0 ) {
V_6 -> V_151 = V_153 ;
return;
}
if ( F_52 ( V_9 ) )
V_6 -> V_156 = F_73 ( V_27 , V_6 -> V_157 ) ;
}
static void F_50 ( struct V_8 * V_9 , T_2 V_215 )
{
int V_216 , V_217 , V_218 ;
T_1 * V_219 = V_215 ? V_9 -> V_53 [ 1 ] . V_54 : V_9 -> V_53 [ 0 ] . V_54 ;
T_1 V_166 = V_215 ? V_9 -> V_167 : V_9 -> V_168 ;
if ( V_9 -> V_31 == 0xf ) {
if ( V_9 -> V_51 < V_52 )
return;
else
F_70 ( V_215 != 0 ) ;
}
V_166 = ( V_215 && ! F_52 ( V_9 ) ) ? V_9 -> V_167 : V_9 -> V_168 ;
V_219 = ( V_215 && ! F_52 ( V_9 ) ) ? V_9 -> V_53 [ 1 ] . V_54
: V_9 -> V_53 [ 0 ] . V_54 ;
F_26 ( 1 , L_66 ,
V_215 , V_166 ) ;
F_106 ( V_220 , V_221 , L_67 , V_215 ) ;
for ( V_216 = 0 ; V_216 < 4 ; V_216 ++ ) {
V_217 = 0 ;
if ( V_219 [ V_216 * 2 ] & V_222 )
V_217 = V_9 -> V_223 -> V_224 ( V_9 , V_215 ,
F_78 ( V_216 , V_166 ) ) ;
V_218 = 0 ;
if ( V_219 [ V_216 * 2 + 1 ] & V_222 )
V_218 = V_9 -> V_223 -> V_224 ( V_9 , V_215 ,
F_78 ( V_216 , V_166 ) ) ;
F_51 ( V_221 L_68 ,
V_216 * 2 , V_217 ,
V_216 * 2 + 1 , V_218 ) ;
}
}
static int F_107 ( T_4 V_157 , const T_4 * V_225 , unsigned V_226 ,
unsigned V_227 )
{
unsigned int V_22 , V_228 ;
for ( V_228 = 0 ; V_228 < V_226 / V_227 ; V_228 ++ ) {
T_4 V_229 = V_157 ;
unsigned V_230 = V_228 * V_227 ;
unsigned V_231 = ( V_228 + 1 ) * V_227 ;
for ( V_22 = 1 ; V_22 < ( 1U << 16 ) ; V_22 <<= 1 ) {
if ( V_230 < V_231 && V_225 [ V_230 ] & V_22 ) {
T_4 V_232 = V_225 [ V_230 ++ ] ;
if ( V_229 & V_22 ) {
V_229 ^= V_232 ;
if ( ! V_229 )
return V_228 ;
}
} else if ( V_229 & V_22 )
break;
}
}
F_26 ( 0 , L_69 , V_157 ) ;
return - 1 ;
}
static int F_108 ( int V_228 , int V_233 )
{
if ( V_233 == 4 )
switch ( V_228 ) {
case 0x20 :
case 0x21 :
return 0 ;
break;
case 0x22 :
case 0x23 :
return 1 ;
break;
default:
return V_228 >> 4 ;
break;
}
else
switch ( V_228 ) {
case 0x10 :
F_109 ( 1 , V_234 L_70 ,
V_228 ) ;
return - 1 ;
break;
case 0x11 :
return 0 ;
break;
case 0x12 :
return 1 ;
break;
default:
return V_228 >> 3 ;
break;
}
return - 1 ;
}
static int F_73 ( struct V_26 * V_27 , T_4 V_157 )
{
struct V_8 * V_9 = V_27 -> V_29 ;
int V_228 = - 1 ;
if ( V_9 -> V_86 == 8 )
V_228 = F_107 ( V_157 , V_235 ,
F_14 ( V_235 ) ,
V_9 -> V_86 ) ;
else if ( V_9 -> V_86 == 4 )
V_228 = F_107 ( V_157 , V_236 ,
F_14 ( V_236 ) ,
V_9 -> V_86 ) ;
else {
F_3 ( L_71 , V_9 -> V_86 ) ;
return V_228 ;
}
return F_108 ( V_228 , V_9 -> V_86 ) ;
}
static void F_110 ( struct V_26 * V_27 , struct V_69 * V_6 ,
T_2 V_237 )
{
enum V_238 V_239 ;
const char * string ;
if ( V_237 == 2 )
V_239 = V_240 ;
else if ( V_237 == 1 )
V_239 = V_241 ;
else {
F_109 ( 1 , L_72 ) ;
return;
}
switch ( V_6 -> V_151 ) {
case V_242 :
string = L_22 ;
break;
case V_152 :
string = L_73 ;
break;
case V_153 :
string = L_74 ;
break;
case V_158 :
string = L_75 ;
break;
default:
string = L_76 ;
break;
}
F_111 ( V_239 , V_27 , 1 ,
V_6 -> V_70 , V_6 -> V_3 , V_6 -> V_157 ,
V_6 -> V_43 , V_6 -> V_156 , - 1 ,
string , L_22 ) ;
}
static inline void F_112 ( int V_36 , struct V_114 * V_115 )
{
struct V_26 * V_27 = V_123 [ V_36 ] ;
struct V_8 * V_9 = V_27 -> V_29 ;
T_2 V_237 = ( V_115 -> V_243 >> 45 ) & 0x3 ;
T_2 V_244 = F_113 ( V_115 -> V_243 , 0x1f ) ;
T_4 V_245 = F_114 ( V_115 -> V_243 ) ;
T_3 V_34 ;
struct V_69 V_6 ;
if ( F_115 ( V_245 ) == V_246 )
return;
if ( V_244 && V_244 != V_247 )
return;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_34 = F_59 ( V_9 , V_115 ) ;
if ( V_237 == 2 )
V_6 . V_157 = F_116 ( V_115 -> V_243 ) ;
V_9 -> V_223 -> V_248 ( V_27 , V_34 , & V_6 ) ;
F_110 ( V_27 , & V_6 , V_237 ) ;
}
static int F_117 ( struct V_8 * V_9 , T_4 V_249 , T_4 V_250 )
{
V_9 -> V_15 = F_62 ( V_9 -> V_12 -> V_126 , V_249 , V_9 -> V_12 ) ;
if ( ! V_9 -> V_15 ) {
F_118 ( L_77
L_78 ,
V_251 , V_249 ) ;
return - V_252 ;
}
V_9 -> V_32 = F_62 ( V_9 -> V_12 -> V_126 , V_250 , V_9 -> V_12 ) ;
if ( ! V_9 -> V_32 ) {
F_71 ( V_9 -> V_15 ) ;
V_9 -> V_15 = NULL ;
F_118 ( L_79
L_78 ,
V_251 , V_250 ) ;
return - V_252 ;
}
F_26 ( 1 , L_80 , F_119 ( V_9 -> V_15 ) ) ;
F_26 ( 1 , L_81 , F_119 ( V_9 -> V_12 ) ) ;
F_26 ( 1 , L_82 , F_119 ( V_9 -> V_32 ) ) ;
return 0 ;
}
static void F_120 ( struct V_8 * V_9 )
{
F_71 ( V_9 -> V_15 ) ;
F_71 ( V_9 -> V_32 ) ;
}
static void F_121 ( struct V_8 * V_9 )
{
unsigned V_132 ;
T_3 V_253 ;
T_1 V_120 ;
F_122 ( V_254 , V_9 -> V_255 ) ;
F_26 ( 0 , L_83 , V_9 -> V_255 ) ;
F_122 ( V_256 , V_253 ) ;
if ( V_253 & ( 1U << 21 ) ) {
F_122 ( V_257 , V_9 -> V_258 ) ;
F_26 ( 0 , L_84 , V_9 -> V_258 ) ;
} else
F_26 ( 0 , L_85 ) ;
F_10 ( V_9 -> V_32 , V_259 , & V_9 -> V_80 ) ;
F_83 ( V_9 ) ;
for ( V_132 = 0 ; V_132 < V_39 ; V_132 ++ ) {
T_2 V_260 ;
F_66 ( V_9 , V_132 ) ;
V_260 = F_67 ( V_9 , V_132 ) ;
if ( ! V_260 )
continue;
F_26 ( 1 , L_86 ,
V_132 ,
F_19 ( V_9 , V_132 ) ,
F_20 ( V_9 , V_132 ) ) ;
F_26 ( 1 , L_87 ,
F_22 ( V_9 , V_132 ) ? L_88 : L_89 ,
( V_260 & 0x1 ) ? L_90 : L_91 ,
( V_260 & 0x2 ) ? L_92 : L_91 ,
F_24 ( V_9 , V_132 ) ,
F_69 ( V_9 , V_132 ) ) ;
}
F_54 ( V_9 ) ;
F_10 ( V_9 -> V_15 , V_261 , & V_9 -> V_85 ) ;
F_55 ( V_9 , V_262 , & V_9 -> V_168 ) ;
F_10 ( V_9 -> V_32 , V_263 , & V_9 -> V_84 ) ;
F_55 ( V_9 , V_264 , & V_9 -> V_76 ) ;
F_55 ( V_9 , V_265 , & V_9 -> V_104 ) ;
if ( ! F_52 ( V_9 ) ) {
F_55 ( V_9 , V_266 , & V_9 -> V_87 ) ;
F_55 ( V_9 , V_267 , & V_9 -> V_170 ) ;
}
V_9 -> V_86 = 4 ;
if ( V_9 -> V_31 >= 0x10 ) {
F_10 ( V_9 -> V_32 , V_268 , & V_120 ) ;
if ( V_9 -> V_31 != 0x16 )
F_55 ( V_9 , V_269 , & V_9 -> V_167 ) ;
if ( ( V_9 -> V_31 > 0x10 || V_9 -> V_17 > 7 ) && V_120 & F_47 ( 25 ) )
V_9 -> V_86 = 8 ;
}
F_49 ( V_9 ) ;
}
static T_1 F_123 ( struct V_8 * V_9 , T_2 V_13 , int V_270 )
{
T_1 V_161 , V_271 ;
T_1 V_166 = V_13 ? V_9 -> V_167 : V_9 -> V_168 ;
V_161 = F_78 ( V_270 / 2 , V_166 ) ;
V_271 = V_9 -> V_223 -> V_224 ( V_9 , V_13 , V_161 ) << ( 20 - V_71 ) ;
F_26 ( 0 , L_93 ,
V_270 , V_13 , V_161 ) ;
F_26 ( 0 , L_94 , V_271 ) ;
return V_271 ;
}
static int F_124 ( struct V_26 * V_27 )
{
struct V_8 * V_9 = V_27 -> V_29 ;
struct V_272 * V_43 ;
struct V_273 * V_216 ;
enum V_274 V_275 ;
enum V_101 V_276 ;
int V_22 , V_164 , V_277 = 1 ;
int V_271 = 0 ;
T_1 V_4 ;
F_10 ( V_9 -> V_32 , V_278 , & V_4 ) ;
V_9 -> V_154 = V_4 ;
F_26 ( 0 , L_95 ,
V_9 -> V_57 , V_4 ,
! ! ( V_4 & V_155 ) , ! ! ( V_4 & V_279 ) ) ;
F_30 (i, 0 , pvt) {
bool V_280 = ! ! F_31 ( V_22 , 0 , V_9 ) ;
bool V_281 = false ;
if ( V_9 -> V_31 != 0xf )
V_281 = ! ! F_31 ( V_22 , 1 , V_9 ) ;
if ( ! V_280 && ! V_281 )
continue;
V_43 = V_27 -> V_282 [ V_22 ] ;
V_277 = 0 ;
F_26 ( 1 , L_96 ,
V_9 -> V_57 , V_22 ) ;
if ( V_280 ) {
V_271 = F_123 ( V_9 , 0 , V_22 ) ;
V_43 -> V_165 [ 0 ] -> V_216 -> V_271 = V_271 ;
}
if ( V_9 -> V_31 != 0xf && V_281 ) {
int V_283 = F_123 ( V_9 , 1 , V_22 ) ;
V_43 -> V_165 [ 1 ] -> V_216 -> V_271 = V_283 ;
V_271 += V_283 ;
}
V_276 = F_57 ( V_9 , V_22 ) ;
F_26 ( 1 , L_97 , V_22 , V_271 ) ;
if ( V_9 -> V_154 & V_279 )
V_275 = ( V_9 -> V_154 & V_155 ) ?
V_284 : V_285 ;
else
V_275 = V_286 ;
for ( V_164 = 0 ; V_164 < V_9 -> V_287 ; V_164 ++ ) {
V_216 = V_43 -> V_165 [ V_164 ] -> V_216 ;
V_216 -> V_276 = V_276 ;
V_216 -> V_275 = V_275 ;
}
}
return V_277 ;
}
static void F_125 ( struct V_288 * V_45 , T_4 V_35 )
{
int V_289 ;
F_126 (cpu)
if ( F_60 ( V_289 ) == V_35 )
F_127 ( V_289 , V_45 ) ;
}
static bool F_128 ( T_4 V_35 )
{
T_5 V_45 ;
int V_289 , V_290 ;
bool V_64 = false ;
if ( ! F_129 ( & V_45 , V_291 ) ) {
F_3 ( L_98 , V_42 ) ;
return false ;
}
F_125 ( V_45 , V_35 ) ;
F_130 ( V_45 , V_292 , V_293 ) ;
F_131 (cpu, mask) {
struct V_294 * V_14 = F_132 ( V_293 , V_289 ) ;
V_290 = V_14 -> V_295 & V_296 ;
F_26 ( 0 , L_99 ,
V_289 , V_14 -> V_297 ,
( V_290 ? L_26 : L_27 ) ) ;
if ( ! V_290 )
goto V_298;
}
V_64 = true ;
V_298:
F_133 ( V_45 ) ;
return V_64 ;
}
static int F_134 ( struct V_299 * V_229 , T_4 V_35 , bool V_300 )
{
T_5 V_301 ;
int V_289 ;
if ( ! F_129 ( & V_301 , V_291 ) ) {
F_3 ( L_100 , V_42 ) ;
return false ;
}
F_125 ( V_301 , V_35 ) ;
F_130 ( V_301 , V_292 , V_293 ) ;
F_131 (cpu, cmask) {
struct V_294 * V_14 = F_132 ( V_293 , V_289 ) ;
if ( V_300 ) {
if ( V_14 -> V_295 & V_296 )
V_229 -> V_302 . V_303 = 1 ;
V_14 -> V_295 |= V_296 ;
} else {
if ( ! V_229 -> V_302 . V_303 )
V_14 -> V_295 &= ~ V_296 ;
}
}
F_135 ( V_301 , V_292 , V_293 ) ;
F_133 ( V_301 ) ;
return 0 ;
}
static bool F_136 ( struct V_299 * V_229 , T_4 V_35 ,
struct V_1 * V_32 )
{
bool V_64 = true ;
T_1 V_304 , V_45 = 0x3 ;
if ( F_134 ( V_229 , V_35 , V_305 ) ) {
F_3 ( L_101 ) ;
return false ;
}
F_10 ( V_32 , V_306 , & V_304 ) ;
V_229 -> V_307 = V_304 & V_45 ;
V_229 -> V_308 = true ;
V_304 |= V_45 ;
F_11 ( V_32 , V_306 , V_304 ) ;
F_10 ( V_32 , V_278 , & V_304 ) ;
F_26 ( 0 , L_102 ,
V_35 , V_304 , ! ! ( V_304 & V_279 ) ) ;
if ( ! ( V_304 & V_279 ) ) {
F_3 ( L_103 ) ;
V_229 -> V_302 . V_309 = 0 ;
V_304 |= V_279 ;
F_11 ( V_32 , V_278 , V_304 ) ;
F_10 ( V_32 , V_278 , & V_304 ) ;
if ( ! ( V_304 & V_279 ) ) {
F_3 ( L_104
L_105 ) ;
V_64 = false ;
} else {
F_51 ( L_106 ) ;
}
} else {
V_229 -> V_302 . V_309 = 1 ;
}
F_26 ( 0 , L_107 ,
V_35 , V_304 , ! ! ( V_304 & V_279 ) ) ;
return V_64 ;
}
static void F_137 ( struct V_299 * V_229 , T_4 V_35 ,
struct V_1 * V_32 )
{
T_1 V_304 , V_45 = 0x3 ;
if ( ! V_229 -> V_308 )
return;
F_10 ( V_32 , V_306 , & V_304 ) ;
V_304 &= ~ V_45 ;
V_304 |= V_229 -> V_307 ;
F_11 ( V_32 , V_306 , V_304 ) ;
if ( ! V_229 -> V_302 . V_309 ) {
F_10 ( V_32 , V_278 , & V_304 ) ;
V_304 &= ~ V_279 ;
F_11 ( V_32 , V_278 , V_304 ) ;
}
if ( F_134 ( V_229 , V_35 , V_310 ) )
F_3 ( L_108 ) ;
}
static bool F_138 ( struct V_1 * V_32 , T_4 V_35 )
{
T_1 V_304 ;
T_2 V_311 = 0 ;
bool V_312 = false ;
F_10 ( V_32 , V_278 , & V_304 ) ;
V_311 = ! ! ( V_304 & V_279 ) ;
F_51 ( L_109 , ( V_311 ? L_26 : L_27 ) ) ;
V_312 = F_128 ( V_35 ) ;
if ( ! V_312 )
F_139 ( L_110
L_111 ,
V_292 , V_35 ) ;
if ( ! V_311 || ! V_312 ) {
F_139 ( L_112 , V_313 ) ;
return false ;
}
return true ;
}
static int F_140 ( struct V_26 * V_27 )
{
struct V_8 * V_9 = V_27 -> V_29 ;
int V_314 ;
V_314 = F_141 ( V_27 ) ;
if ( V_314 < 0 )
return V_314 ;
if ( V_9 -> V_31 >= 0x10 ) {
V_314 = F_142 ( V_27 ) ;
if ( V_314 < 0 )
return V_314 ;
}
return 0 ;
}
static void F_143 ( struct V_26 * V_27 )
{
struct V_8 * V_9 = V_27 -> V_29 ;
F_144 ( V_27 ) ;
if ( V_9 -> V_31 >= 0x10 )
F_145 ( V_27 ) ;
}
static void F_146 ( struct V_26 * V_27 ,
struct V_315 * V_31 )
{
struct V_8 * V_9 = V_27 -> V_29 ;
V_27 -> V_316 = V_317 | V_318 ;
V_27 -> V_319 = V_75 ;
if ( V_9 -> V_80 & V_82 )
V_27 -> V_319 |= V_77 ;
if ( V_9 -> V_80 & V_83 )
V_27 -> V_319 |= V_320 ;
V_27 -> V_74 = F_46 ( V_9 ) ;
V_27 -> V_321 = V_322 ;
V_27 -> V_323 = V_324 ;
V_27 -> V_325 = V_31 -> V_325 ;
V_27 -> V_326 = F_119 ( V_9 -> V_12 ) ;
V_27 -> V_327 = NULL ;
V_27 -> V_328 = F_16 ;
V_27 -> V_329 = F_17 ;
}
static struct V_315 * F_147 ( struct V_8 * V_9 )
{
struct V_315 * V_330 = NULL ;
V_9 -> V_51 = V_331 . V_332 >> 4 ;
V_9 -> V_196 = V_331 . V_333 ;
V_9 -> V_17 = V_331 . V_332 ;
V_9 -> V_31 = V_331 . V_334 ;
switch ( V_9 -> V_31 ) {
case 0xf :
V_330 = & V_335 [ V_336 ] ;
V_9 -> V_223 = & V_335 [ V_336 ] . V_223 ;
break;
case 0x10 :
V_330 = & V_335 [ V_337 ] ;
V_9 -> V_223 = & V_335 [ V_337 ] . V_223 ;
break;
case 0x15 :
if ( V_9 -> V_17 == 0x30 ) {
V_330 = & V_335 [ V_338 ] ;
V_9 -> V_223 = & V_335 [ V_338 ] . V_223 ;
break;
}
V_330 = & V_335 [ V_339 ] ;
V_9 -> V_223 = & V_335 [ V_339 ] . V_223 ;
break;
case 0x16 :
V_330 = & V_335 [ V_340 ] ;
V_9 -> V_223 = & V_335 [ V_340 ] . V_223 ;
break;
default:
F_118 ( L_113 ) ;
return NULL ;
}
F_51 ( L_114 , V_330 -> V_325 ,
( V_9 -> V_31 == 0xf ?
( V_9 -> V_51 >= V_52 ? L_115
: L_116 )
: L_22 ) , V_9 -> V_57 ) ;
return V_330 ;
}
static int F_148 ( struct V_1 * V_12 )
{
struct V_8 * V_9 = NULL ;
struct V_315 * V_330 = NULL ;
struct V_26 * V_27 = NULL ;
struct V_341 V_342 [ 2 ] ;
int V_6 = 0 , V_64 ;
T_4 V_35 = F_149 ( V_12 ) ;
V_64 = - V_343 ;
V_9 = F_150 ( sizeof( struct V_8 ) , V_291 ) ;
if ( ! V_9 )
goto V_344;
V_9 -> V_57 = V_35 ;
V_9 -> V_12 = V_12 ;
V_64 = - V_11 ;
V_330 = F_147 ( V_9 ) ;
if ( ! V_330 )
goto V_345;
V_64 = - V_252 ;
V_6 = F_117 ( V_9 , V_330 -> V_249 , V_330 -> V_250 ) ;
if ( V_6 )
goto V_345;
F_121 ( V_9 ) ;
V_64 = - V_11 ;
V_9 -> V_287 = V_9 -> V_223 -> V_346 ( V_9 ) ;
if ( V_9 -> V_287 < 0 )
goto V_347;
V_64 = - V_343 ;
V_342 [ 0 ] . type = V_348 ;
V_342 [ 0 ] . V_349 = V_9 -> V_53 [ 0 ] . V_88 ;
V_342 [ 0 ] . V_350 = true ;
V_342 [ 1 ] . type = V_351 ;
V_342 [ 1 ] . V_349 = 2 ;
V_342 [ 1 ] . V_350 = false ;
V_27 = F_151 ( V_35 , F_14 ( V_342 ) , V_342 , 0 ) ;
if ( ! V_27 )
goto V_347;
V_27 -> V_29 = V_9 ;
V_27 -> V_2 = & V_9 -> V_12 -> V_129 ;
F_146 ( V_27 , V_330 ) ;
if ( F_124 ( V_27 ) )
V_27 -> V_74 = V_75 ;
V_64 = - V_252 ;
if ( F_152 ( V_27 ) ) {
F_26 ( 1 , L_117 ) ;
goto V_352;
}
if ( F_140 ( V_27 ) ) {
F_26 ( 1 , L_117 ) ;
goto V_353;
}
if ( V_354 )
F_153 ( true ) ;
F_154 ( F_112 ) ;
V_123 [ V_35 ] = V_27 ;
F_155 ( & V_355 ) ;
return 0 ;
V_353:
F_156 ( V_27 -> V_2 ) ;
V_352:
F_157 ( V_27 ) ;
V_347:
F_120 ( V_9 ) ;
V_345:
F_158 ( V_9 ) ;
V_344:
return V_64 ;
}
static int F_159 ( struct V_1 * V_2 ,
const struct V_356 * V_357 )
{
T_4 V_35 = F_149 ( V_2 ) ;
struct V_1 * V_32 = F_68 ( V_35 ) -> V_149 ;
struct V_299 * V_229 ;
int V_64 = 0 ;
V_64 = F_160 ( V_2 ) ;
if ( V_64 < 0 ) {
F_26 ( 0 , L_118 , V_64 ) ;
return - V_358 ;
}
V_64 = - V_343 ;
V_229 = F_150 ( sizeof( struct V_299 ) , V_291 ) ;
if ( ! V_229 )
goto V_359;
V_360 [ V_35 ] = V_229 ;
if ( ! F_138 ( V_32 , V_35 ) ) {
V_64 = - V_252 ;
if ( ! V_361 )
goto V_362;
F_3 ( L_119 ) ;
if ( ! F_136 ( V_229 , V_35 , V_32 ) )
goto V_362;
}
V_64 = F_148 ( V_2 ) ;
if ( V_64 < 0 ) {
F_118 ( L_120 , V_35 ) ;
F_137 ( V_229 , V_35 , V_32 ) ;
}
return V_64 ;
V_362:
F_158 ( V_229 ) ;
V_360 [ V_35 ] = NULL ;
V_359:
return V_64 ;
}
static void F_161 ( struct V_1 * V_2 )
{
struct V_26 * V_27 ;
struct V_8 * V_9 ;
T_4 V_35 = F_149 ( V_2 ) ;
struct V_1 * V_32 = F_68 ( V_35 ) -> V_149 ;
struct V_299 * V_229 = V_360 [ V_35 ] ;
V_27 = F_162 ( & V_2 -> V_129 ) ;
F_70 ( ! V_27 ) ;
F_143 ( V_27 ) ;
V_27 = F_156 ( & V_2 -> V_129 ) ;
if ( ! V_27 )
return;
V_9 = V_27 -> V_29 ;
F_137 ( V_229 , V_35 , V_32 ) ;
F_120 ( V_9 ) ;
F_153 ( false ) ;
F_163 ( F_112 ) ;
F_158 ( V_360 [ V_35 ] ) ;
V_360 [ V_35 ] = NULL ;
V_27 -> V_29 = NULL ;
V_123 [ V_35 ] = NULL ;
F_158 ( V_9 ) ;
F_157 ( V_27 ) ;
}
static void F_164 ( void )
{
struct V_26 * V_27 ;
struct V_8 * V_9 ;
if ( V_363 )
return;
V_27 = V_123 [ 0 ] ;
if ( ! V_27 )
return;
V_9 = V_27 -> V_29 ;
V_363 = F_165 ( & V_9 -> V_12 -> V_129 , V_322 ) ;
if ( ! V_363 ) {
F_166 ( L_121 , V_42 ) ;
F_166 ( L_122 , V_42 ) ;
}
}
static int T_6 F_167 ( void )
{
int V_6 = - V_252 ;
F_168 ( V_364 L_123 , V_324 ) ;
F_169 () ;
if ( F_170 () < 0 )
goto V_344;
V_6 = - V_343 ;
V_123 = F_150 ( F_171 () * sizeof( V_123 [ 0 ] ) , V_291 ) ;
V_360 = F_150 ( F_171 () * sizeof( V_360 [ 0 ] ) , V_291 ) ;
if ( ! ( V_123 && V_360 ) )
goto V_345;
V_293 = F_172 () ;
if ( ! V_293 )
goto V_345;
V_6 = F_173 ( & V_365 ) ;
if ( V_6 )
goto V_366;
V_6 = - V_252 ;
if ( ! F_174 ( & V_355 ) )
goto V_367;
F_164 () ;
return 0 ;
V_367:
F_175 ( & V_365 ) ;
V_366:
F_176 ( V_293 ) ;
V_293 = NULL ;
V_345:
F_158 ( V_123 ) ;
V_123 = NULL ;
F_158 ( V_360 ) ;
V_360 = NULL ;
V_344:
return V_6 ;
}
static void T_7 F_177 ( void )
{
if ( V_363 )
F_178 ( V_363 ) ;
F_175 ( & V_365 ) ;
F_158 ( V_360 ) ;
V_360 = NULL ;
F_158 ( V_123 ) ;
V_123 = NULL ;
F_176 ( V_293 ) ;
V_293 = NULL ;
}
