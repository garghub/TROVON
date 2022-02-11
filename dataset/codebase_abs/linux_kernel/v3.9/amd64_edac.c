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
T_2 V_35 )
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
T_2 V_36 ;
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
static inline void F_43 ( T_3 V_68 ,
struct V_69 * V_6 )
{
V_6 -> V_70 = ( T_1 ) ( V_68 >> V_71 ) ;
V_6 -> V_3 = ( ( T_1 ) V_68 ) & ~ V_72 ;
}
static int F_44 ( struct V_25 * V_26 , T_3 V_34 )
{
int V_43 ;
V_43 = F_29 ( V_26 , F_42 ( V_26 , V_34 ) ) ;
if ( V_43 == - 1 )
F_45 ( V_26 , L_17
L_18 , ( unsigned long ) V_34 ) ;
return V_43 ;
}
static unsigned long F_46 ( struct V_8 * V_9 )
{
T_2 V_73 ;
unsigned long V_74 = V_75 ;
V_73 = ( V_30 . V_31 > 0xf || V_9 -> V_51 >= V_52 )
? 19
: 17 ;
if ( V_9 -> V_76 & F_47 ( V_73 ) )
V_74 = V_77 ;
return V_74 ;
}
static void F_48 ( T_1 V_78 , int V_79 )
{
F_26 ( 1 , L_19 , V_79 , V_78 ) ;
F_26 ( 1 , L_20 ,
( V_78 & F_47 ( 16 ) ) ? L_21 : L_22 ,
( V_78 & F_47 ( 19 ) ) ? L_23 : L_24 ) ;
F_26 ( 1 , L_25 ,
( V_78 & F_47 ( 8 ) ) ? L_26 : L_27 ) ;
if ( V_30 . V_31 == 0x10 )
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
F_48 ( V_9 -> V_76 , 0 ) ;
F_26 ( 1 , L_35 , V_9 -> V_84 ) ;
F_26 ( 1 , L_36 ,
V_9 -> V_85 , F_35 ( V_9 ) ,
( V_30 . V_31 == 0xf ) ? F_37 ( V_9 )
: F_36 ( V_9 ) ) ;
F_26 ( 1 , L_37 , F_34 ( V_9 ) ? L_23 : L_24 ) ;
F_50 ( V_9 , 0 ) ;
if ( V_30 . V_31 == 0xf )
return;
F_50 ( V_9 , 1 ) ;
F_51 ( L_38 , ( ( V_9 -> V_86 == 8 ) ? L_39 : L_40 ) ) ;
if ( ! F_52 ( V_9 ) )
F_48 ( V_9 -> V_87 , 1 ) ;
}
static void F_53 ( struct V_8 * V_9 )
{
if ( V_30 . V_31 == 0xf && V_9 -> V_51 < V_52 ) {
V_9 -> V_53 [ 0 ] . V_88 = V_9 -> V_53 [ 1 ] . V_88 = 8 ;
V_9 -> V_53 [ 0 ] . V_89 = V_9 -> V_53 [ 1 ] . V_89 = 8 ;
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
if ( V_30 . V_31 == 0xf || F_52 ( V_9 ) )
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
if ( V_30 . V_31 == 0xf || F_52 ( V_9 ) )
continue;
if ( ! F_55 ( V_9 , V_93 , V_100 ) )
F_26 ( 0 , L_44 ,
V_90 , * V_100 , V_93 ) ;
}
}
static enum V_101 F_57 ( struct V_8 * V_9 , int V_90 )
{
enum V_101 type ;
if ( V_30 . V_31 >= 0x15 )
type = ( V_9 -> V_76 & F_47 ( 16 ) ) ? V_102 : V_103 ;
else if ( V_30 . V_31 == 0x10 || V_9 -> V_51 >= V_52 ) {
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
static T_3 F_59 ( struct V_114 * V_115 )
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
T_4 V_123 ;
T_2 V_37 ;
if ( ( V_10 & F_28 ( 24 , 47 ) ) >> 24 != 0x00fdf7 )
return V_10 ;
V_123 = F_60 ( V_115 -> V_124 ) ;
V_9 = V_125 [ V_123 ] -> V_28 ;
F_10 ( V_9 -> V_15 , V_126 , & V_122 ) ;
V_37 = V_122 >> 21 & 0x7 ;
V_120 = ( V_122 & F_28 ( 0 , 20 ) ) << 3 ;
V_120 |= V_37 ^ 0x7 ;
V_120 <<= 24 ;
if ( ! V_37 )
return V_120 | ( V_10 & F_28 ( 0 , 23 ) ) ;
F_10 ( V_9 -> V_15 , V_127 , & V_122 ) ;
V_121 = ( V_10 & F_28 ( 12 , 23 ) ) << F_61 ( V_37 + 1 ) ;
V_121 |= ( V_122 & F_28 ( 21 , 23 ) ) >> 9 ;
V_121 |= V_10 & F_28 ( 0 , 11 ) ;
return V_120 | V_121 ;
}
return V_10 ;
}
static struct V_1 * F_62 ( unsigned int V_128 ,
unsigned int V_129 ,
struct V_1 * V_130 )
{
struct V_1 * V_131 = NULL ;
while ( ( V_131 = F_63 ( V_128 , V_129 , V_131 ) ) ) {
if ( F_64 ( V_131 -> V_132 ) == F_64 ( V_130 -> V_132 ) &&
( V_131 -> V_132 -> V_133 == V_130 -> V_132 -> V_133 ) &&
( F_65 ( V_131 -> V_7 ) == F_65 ( V_130 -> V_7 ) ) )
break;
}
return V_131 ;
}
static void F_66 ( struct V_8 * V_9 , unsigned V_134 )
{
struct V_135 * V_136 ;
struct V_1 * V_137 , * V_138 = NULL ;
struct V_116 * V_117 = & V_30 ;
int V_139 = V_134 << 3 ;
T_1 V_140 ;
F_10 ( V_9 -> V_15 , V_141 + V_139 , & V_9 -> V_142 [ V_134 ] . V_44 . V_143 ) ;
F_10 ( V_9 -> V_15 , V_144 + V_139 , & V_9 -> V_142 [ V_134 ] . V_145 . V_143 ) ;
if ( V_117 -> V_31 == 0xf )
return;
if ( ! F_67 ( V_9 , V_134 ) )
return;
F_10 ( V_9 -> V_15 , V_146 + V_139 , & V_9 -> V_142 [ V_134 ] . V_44 . V_147 ) ;
F_10 ( V_9 -> V_15 , V_148 + V_139 , & V_9 -> V_142 [ V_134 ] . V_145 . V_147 ) ;
if ( V_117 -> V_31 != 0x15 )
return;
V_136 = F_68 ( F_69 ( V_9 , V_134 ) ) ;
if ( F_70 ( ! V_136 ) )
return;
V_137 = V_136 -> V_137 ;
V_138 = F_62 ( V_137 -> V_128 , V_149 , V_137 ) ;
if ( F_70 ( ! V_138 ) )
return;
F_10 ( V_138 , V_126 , & V_140 ) ;
V_9 -> V_142 [ V_134 ] . V_145 . V_143 &= F_28 ( 0 , 15 ) ;
V_9 -> V_142 [ V_134 ] . V_145 . V_143 |= ( ( V_140 & 0x1fff ) << 3 | 0x7 ) << 16 ;
V_9 -> V_142 [ V_134 ] . V_145 . V_147 &= F_28 ( 0 , 7 ) ;
V_9 -> V_142 [ V_134 ] . V_145 . V_147 |= V_140 >> 13 ;
F_71 ( V_138 ) ;
}
static void F_72 ( struct V_25 * V_26 , T_3 V_34 ,
struct V_69 * V_6 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
F_43 ( V_34 , V_6 ) ;
V_6 -> V_150 = F_21 ( V_26 , V_34 ) ;
if ( ! V_6 -> V_150 ) {
F_45 ( V_26 , L_46 ,
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
V_6 -> V_156 = F_73 ( V_26 , V_6 -> V_157 ) ;
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
static int F_75 ( unsigned V_21 , bool V_159 )
{
unsigned V_160 = 0 ;
if ( V_21 <= 2 )
V_160 = V_21 ;
else if ( ! ( V_21 & 0x1 ) )
V_160 = V_21 >> 1 ;
else
V_160 = ( V_21 + 1 ) >> 1 ;
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
int V_21 , V_164 , V_165 = 0 ;
if ( V_30 . V_31 == 0x10 && ( V_9 -> V_76 & V_112 ) )
return 2 ;
F_26 ( 0 , L_49 ) ;
for ( V_21 = 0 ; V_21 < 2 ; V_21 ++ ) {
T_1 V_166 = ( V_21 ? V_9 -> V_167 : V_9 -> V_168 ) ;
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
static int F_79 ( unsigned V_21 , bool V_159 )
{
unsigned V_160 = 0 ;
int V_169 = 0 ;
if ( V_21 == 0 || V_21 == 3 || V_21 == 4 )
V_169 = - 1 ;
else if ( V_21 <= 2 )
V_160 = V_21 ;
else if ( V_21 == 12 )
V_160 = 7 ;
else if ( ! ( V_21 & 0x1 ) )
V_160 = V_21 >> 1 ;
else
V_160 = ( V_21 + 1 ) >> 1 ;
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
static void F_82 ( struct V_8 * V_9 )
{
if ( V_30 . V_31 == 0xf )
return;
if ( ! F_55 ( V_9 , V_171 , & V_9 -> V_172 ) ) {
F_26 ( 0 , L_51 ,
V_9 -> V_172 , F_83 ( V_9 ) ) ;
F_26 ( 0 , L_52 ,
( F_52 ( V_9 ) ? L_53 : L_54 ) ) ;
if ( ! F_52 ( V_9 ) )
F_26 ( 0 , L_55 ,
( F_84 ( V_9 ) ? L_23 : L_24 ) ) ;
F_26 ( 0 , L_56 ,
( F_85 ( V_9 ) ? L_26 : L_27 ) ,
( F_86 ( V_9 ) ? L_23 : L_24 ) ) ;
F_26 ( 0 , L_57
L_58 ,
( F_87 ( V_9 ) ? L_26 : L_27 ) ,
F_88 ( V_9 ) ) ;
}
F_55 ( V_9 , V_173 , & V_9 -> V_174 ) ;
}
static T_2 F_89 ( struct V_8 * V_9 , T_3 V_34 ,
bool V_175 , T_2 V_37 )
{
T_2 V_176 = ( V_9 -> V_172 >> 1 ) & 1 ;
if ( F_52 ( V_9 ) )
return 0 ;
if ( V_175 )
return V_176 ;
if ( F_87 ( V_9 ) ) {
T_2 V_177 = F_88 ( V_9 ) ;
if ( ! V_177 )
return V_34 >> 6 & 1 ;
if ( V_177 & 0x2 ) {
T_2 V_160 = V_177 & 0x1 ? 9 : 6 ;
T_1 V_178 = F_90 ( ( T_1 ) ( ( V_34 >> 16 ) & 0x1F ) ) % 2 ;
return ( ( V_34 >> V_160 ) & 1 ) ^ V_178 ;
}
return ( V_34 >> ( 12 + F_91 ( V_37 ) ) ) & 1 ;
}
if ( F_84 ( V_9 ) )
return ~ V_176 & 1 ;
return 0 ;
}
static T_3 F_92 ( struct V_8 * V_9 , T_2 V_134 ,
T_3 V_34 , bool V_179 ,
T_1 V_180 )
{
T_3 V_181 ;
T_3 V_62 = F_19 ( V_9 , V_134 ) ;
T_3 V_182 = F_36 ( V_9 ) ;
T_3 V_183 = ( V_9 -> V_174 & 0xFFFFFC00 ) << 16 ;
if ( V_179 ) {
if ( ( ! ( V_180 >> 16 ) ||
V_180 < F_35 ( V_9 ) ) &&
F_34 ( V_9 ) &&
( V_34 >= F_93 ( 32 ) ) )
V_181 = V_182 ;
else
V_181 = V_183 ;
} else {
if ( F_34 ( V_9 ) && ( V_34 >= F_93 ( 32 ) ) )
V_181 = V_182 ;
else
V_181 = V_62 ;
}
return ( V_34 & F_28 ( 6 , 47 ) ) - ( V_181 & F_28 ( 23 , 47 ) ) ;
}
static int F_94 ( struct V_8 * V_9 , T_2 V_13 , int V_43 )
{
int V_184 ;
if ( F_95 ( V_9 , V_13 ) &&
V_43 == F_96 ( V_9 , V_13 ) ) {
F_30 (tmp_cs, dct, pvt) {
if ( F_97 ( V_184 , V_13 , V_9 ) & 0x2 ) {
V_43 = V_184 ;
break;
}
}
}
return V_43 ;
}
static int F_98 ( T_3 V_185 , T_2 V_35 , T_2 V_13 )
{
struct V_25 * V_26 ;
struct V_8 * V_9 ;
T_3 V_186 , V_187 ;
int V_188 = - V_11 ;
int V_43 ;
V_26 = V_125 [ V_35 ] ;
if ( ! V_26 )
return V_188 ;
V_9 = V_26 -> V_28 ;
F_26 ( 1 , L_59 , V_185 , V_13 ) ;
F_30 (csrow, dct, pvt) {
if ( ! F_31 ( V_43 , V_13 , V_9 ) )
continue;
F_27 ( V_9 , V_43 , V_13 , & V_186 , & V_187 ) ;
F_26 ( 1 , L_60 ,
V_43 , V_186 , V_187 ) ;
V_187 = ~ V_187 ;
F_26 ( 1 , L_61 ,
( V_185 & V_187 ) , ( V_186 & V_187 ) ) ;
if ( ( V_185 & V_187 ) == ( V_186 & V_187 ) ) {
V_188 = F_94 ( V_9 , V_13 , V_43 ) ;
F_26 ( 1 , L_62 , V_188 ) ;
break;
}
}
return V_188 ;
}
static T_3 F_99 ( struct V_8 * V_9 , T_3 V_34 )
{
T_1 V_189 , V_190 , V_191 , V_192 , V_121 ;
if ( V_30 . V_31 == 0x10 ) {
if ( V_30 . V_193 < 4 ||
( V_30 . V_193 < 0xa &&
V_30 . V_194 < 3 ) )
return V_34 ;
}
F_55 ( V_9 , V_195 , & V_189 ) ;
if ( ! ( V_189 & 0x1 ) )
return V_34 ;
V_190 = ( V_189 >> 3 ) & 0x7f ;
V_191 = ( V_189 >> 11 ) & 0x7f ;
V_192 = ( V_189 >> 20 ) & 0x7f ;
V_121 = V_34 >> 27 ;
if ( ! ( V_34 >> 34 ) &&
( ( ( V_121 >= V_190 ) &&
( V_121 <= V_191 ) ) ||
( V_121 < V_192 ) ) )
return V_34 ^ ( T_3 ) V_190 << 27 ;
return V_34 ;
}
static int F_100 ( struct V_8 * V_9 , unsigned V_134 ,
T_3 V_34 , int * V_196 )
{
int V_188 = - V_11 ;
T_3 V_197 ;
T_1 V_198 ;
T_2 V_156 ;
bool V_199 = false ;
T_2 V_36 = F_69 ( V_9 , V_134 ) ;
T_2 V_37 = F_22 ( V_9 , V_134 ) ;
T_1 V_200 = F_24 ( V_9 , V_134 ) ;
F_26 ( 1 , L_63 ,
V_134 , V_34 , F_20 ( V_9 , V_134 ) ) ;
if ( F_34 ( V_9 ) &&
F_35 ( V_9 ) <= V_34 &&
V_34 < F_93 ( 32 ) ) {
F_3 ( L_64 ,
V_34 ) ;
return - V_11 ;
}
if ( V_37 && ( V_200 != ( ( V_34 >> 12 ) & V_37 ) ) )
return - V_11 ;
V_34 = F_99 ( V_9 , V_34 ) ;
V_198 = F_83 ( V_9 ) ;
if ( F_84 ( V_9 ) &&
! F_52 ( V_9 ) &&
( ( V_34 >> 27 ) >= ( V_198 >> 11 ) ) )
V_199 = true ;
V_156 = F_89 ( V_9 , V_34 , V_199 , V_37 ) ;
V_197 = F_92 ( V_9 , V_134 , V_34 ,
V_199 , V_198 ) ;
if ( V_37 )
V_197 = ( ( V_197 >> ( 12 + F_91 ( V_37 ) ) ) << 12 ) |
( V_197 & 0xfff ) ;
if ( F_87 ( V_9 ) &&
! F_84 ( V_9 ) &&
! F_52 ( V_9 ) ) {
if ( F_88 ( V_9 ) != 1 ) {
if ( F_88 ( V_9 ) == 0x3 )
V_197 = ( ( V_197 >> 10 ) << 9 ) |
( V_197 & 0x1ff ) ;
else
V_197 = ( ( V_197 >> 7 ) << 6 ) |
( V_197 & 0x3f ) ;
} else
V_197 = ( ( V_197 >> 13 ) << 12 ) |
( V_197 & 0xfff ) ;
}
F_26 ( 1 , L_65 , V_197 ) ;
V_188 = F_98 ( V_197 , V_36 , V_156 ) ;
if ( V_188 >= 0 )
* V_196 = V_156 ;
return V_188 ;
}
static int F_101 ( struct V_8 * V_9 , T_3 V_34 ,
int * V_196 )
{
int V_188 = - V_11 ;
unsigned V_134 ;
for ( V_134 = 0 ; V_134 < V_39 ; V_134 ++ ) {
if ( ! F_67 ( V_9 , V_134 ) )
continue;
if ( ( F_19 ( V_9 , V_134 ) <= V_34 ) &&
( F_20 ( V_9 , V_134 ) >= V_34 ) ) {
V_188 = F_100 ( V_9 , V_134 ,
V_34 , V_196 ) ;
if ( V_188 >= 0 )
break;
}
}
return V_188 ;
}
static void F_102 ( struct V_25 * V_26 , T_3 V_34 ,
struct V_69 * V_6 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
F_43 ( V_34 , V_6 ) ;
V_6 -> V_43 = F_101 ( V_9 , V_34 , & V_6 -> V_156 ) ;
if ( V_6 -> V_43 < 0 ) {
V_6 -> V_151 = V_153 ;
return;
}
if ( F_52 ( V_9 ) )
V_6 -> V_156 = F_73 ( V_26 , V_6 -> V_157 ) ;
}
static void F_50 ( struct V_8 * V_9 , T_2 V_201 )
{
int V_202 , V_203 , V_204 ;
T_1 * V_205 = V_201 ? V_9 -> V_53 [ 1 ] . V_54 : V_9 -> V_53 [ 0 ] . V_54 ;
T_1 V_166 = V_201 ? V_9 -> V_167 : V_9 -> V_168 ;
if ( V_30 . V_31 == 0xf ) {
if ( V_9 -> V_51 < V_52 )
return;
else
F_70 ( V_201 != 0 ) ;
}
V_166 = ( V_201 && ! F_52 ( V_9 ) ) ? V_9 -> V_167 : V_9 -> V_168 ;
V_205 = ( V_201 && ! F_52 ( V_9 ) ) ? V_9 -> V_53 [ 1 ] . V_54
: V_9 -> V_53 [ 0 ] . V_54 ;
F_26 ( 1 , L_66 ,
V_201 , V_166 ) ;
F_103 ( V_206 , V_207 , L_67 , V_201 ) ;
for ( V_202 = 0 ; V_202 < 4 ; V_202 ++ ) {
V_203 = 0 ;
if ( V_205 [ V_202 * 2 ] & V_208 )
V_203 = V_9 -> V_209 -> V_210 ( V_9 , V_201 ,
F_78 ( V_202 , V_166 ) ) ;
V_204 = 0 ;
if ( V_205 [ V_202 * 2 + 1 ] & V_208 )
V_204 = V_9 -> V_209 -> V_210 ( V_9 , V_201 ,
F_78 ( V_202 , V_166 ) ) ;
F_51 ( V_207 L_68 ,
V_202 * 2 , V_203 ,
V_202 * 2 + 1 , V_204 ) ;
}
}
static int F_104 ( T_4 V_157 , const T_4 * V_211 , unsigned V_212 ,
unsigned V_213 )
{
unsigned int V_21 , V_214 ;
for ( V_214 = 0 ; V_214 < V_212 / V_213 ; V_214 ++ ) {
T_4 V_215 = V_157 ;
unsigned V_216 = V_214 * V_213 ;
unsigned V_217 = ( V_214 + 1 ) * V_213 ;
for ( V_21 = 1 ; V_21 < ( 1U << 16 ) ; V_21 <<= 1 ) {
if ( V_216 < V_217 && V_211 [ V_216 ] & V_21 ) {
T_4 V_218 = V_211 [ V_216 ++ ] ;
if ( V_215 & V_21 ) {
V_215 ^= V_218 ;
if ( ! V_215 )
return V_214 ;
}
} else if ( V_215 & V_21 )
break;
}
}
F_26 ( 0 , L_69 , V_157 ) ;
return - 1 ;
}
static int F_105 ( int V_214 , int V_219 )
{
if ( V_219 == 4 )
switch ( V_214 ) {
case 0x20 :
case 0x21 :
return 0 ;
break;
case 0x22 :
case 0x23 :
return 1 ;
break;
default:
return V_214 >> 4 ;
break;
}
else
switch ( V_214 ) {
case 0x10 :
F_106 ( 1 , V_220 L_70 ,
V_214 ) ;
return - 1 ;
break;
case 0x11 :
return 0 ;
break;
case 0x12 :
return 1 ;
break;
default:
return V_214 >> 3 ;
break;
}
return - 1 ;
}
static int F_73 ( struct V_25 * V_26 , T_4 V_157 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
int V_214 = - 1 ;
if ( V_9 -> V_86 == 8 )
V_214 = F_104 ( V_157 , V_221 ,
F_14 ( V_221 ) ,
V_9 -> V_86 ) ;
else if ( V_9 -> V_86 == 4 )
V_214 = F_104 ( V_157 , V_222 ,
F_14 ( V_222 ) ,
V_9 -> V_86 ) ;
else {
F_3 ( L_71 , V_9 -> V_86 ) ;
return V_214 ;
}
return F_105 ( V_214 , V_9 -> V_86 ) ;
}
static void F_107 ( struct V_25 * V_26 , struct V_69 * V_6 ,
T_2 V_223 )
{
enum V_224 V_225 ;
const char * string ;
if ( V_223 == 2 )
V_225 = V_226 ;
else if ( V_223 == 1 )
V_225 = V_227 ;
else {
F_106 ( 1 , L_72 ) ;
return;
}
switch ( V_6 -> V_151 ) {
case V_228 :
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
F_108 ( V_225 , V_26 , 1 ,
V_6 -> V_70 , V_6 -> V_3 , V_6 -> V_157 ,
V_6 -> V_43 , V_6 -> V_156 , - 1 ,
string , L_22 ) ;
}
static inline void F_109 ( struct V_25 * V_26 ,
struct V_114 * V_115 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
T_2 V_223 = ( V_115 -> V_229 >> 45 ) & 0x3 ;
T_2 V_230 = F_110 ( V_115 -> V_229 , 0x1f ) ;
T_4 V_231 = F_111 ( V_115 -> V_229 ) ;
T_3 V_34 ;
struct V_69 V_6 ;
if ( F_112 ( V_231 ) == V_232 )
return;
if ( V_230 && V_230 != V_233 )
return;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_34 = F_59 ( V_115 ) ;
if ( V_223 == 2 )
V_6 . V_157 = F_113 ( V_115 -> V_229 ) ;
V_9 -> V_209 -> V_234 ( V_26 , V_34 , & V_6 ) ;
F_107 ( V_26 , & V_6 , V_223 ) ;
}
void F_114 ( int V_36 , struct V_114 * V_115 )
{
F_109 ( V_125 [ V_36 ] , V_115 ) ;
}
static int F_115 ( struct V_8 * V_9 , T_4 V_235 , T_4 V_236 )
{
V_9 -> V_15 = F_62 ( V_9 -> V_12 -> V_128 , V_235 , V_9 -> V_12 ) ;
if ( ! V_9 -> V_15 ) {
F_116 ( L_77
L_78 ,
V_237 , V_235 ) ;
return - V_238 ;
}
V_9 -> V_32 = F_62 ( V_9 -> V_12 -> V_128 , V_236 , V_9 -> V_12 ) ;
if ( ! V_9 -> V_32 ) {
F_71 ( V_9 -> V_15 ) ;
V_9 -> V_15 = NULL ;
F_116 ( L_79
L_78 ,
V_237 , V_236 ) ;
return - V_238 ;
}
F_26 ( 1 , L_80 , F_117 ( V_9 -> V_15 ) ) ;
F_26 ( 1 , L_81 , F_117 ( V_9 -> V_12 ) ) ;
F_26 ( 1 , L_82 , F_117 ( V_9 -> V_32 ) ) ;
return 0 ;
}
static void F_118 ( struct V_8 * V_9 )
{
F_71 ( V_9 -> V_15 ) ;
F_71 ( V_9 -> V_32 ) ;
}
static void F_119 ( struct V_8 * V_9 )
{
struct V_116 * V_117 = & V_30 ;
T_3 V_239 ;
T_1 V_122 ;
unsigned V_134 ;
F_120 ( V_240 , V_9 -> V_241 ) ;
F_26 ( 0 , L_83 , V_9 -> V_241 ) ;
F_120 ( V_242 , V_239 ) ;
if ( V_239 & ( 1U << 21 ) ) {
F_120 ( V_243 , V_9 -> V_244 ) ;
F_26 ( 0 , L_84 , V_9 -> V_244 ) ;
} else
F_26 ( 0 , L_85 ) ;
F_10 ( V_9 -> V_32 , V_245 , & V_9 -> V_80 ) ;
F_82 ( V_9 ) ;
for ( V_134 = 0 ; V_134 < V_39 ; V_134 ++ ) {
T_2 V_246 ;
F_66 ( V_9 , V_134 ) ;
V_246 = F_67 ( V_9 , V_134 ) ;
if ( ! V_246 )
continue;
F_26 ( 1 , L_86 ,
V_134 ,
F_19 ( V_9 , V_134 ) ,
F_20 ( V_9 , V_134 ) ) ;
F_26 ( 1 , L_87 ,
F_22 ( V_9 , V_134 ) ? L_88 : L_89 ,
( V_246 & 0x1 ) ? L_90 : L_91 ,
( V_246 & 0x2 ) ? L_92 : L_91 ,
F_24 ( V_9 , V_134 ) ,
F_69 ( V_9 , V_134 ) ) ;
}
F_54 ( V_9 ) ;
F_10 ( V_9 -> V_15 , V_247 , & V_9 -> V_85 ) ;
F_55 ( V_9 , V_248 , & V_9 -> V_168 ) ;
F_10 ( V_9 -> V_32 , V_249 , & V_9 -> V_84 ) ;
F_55 ( V_9 , V_250 , & V_9 -> V_76 ) ;
F_55 ( V_9 , V_251 , & V_9 -> V_104 ) ;
if ( ! F_52 ( V_9 ) ) {
F_55 ( V_9 , V_252 , & V_9 -> V_87 ) ;
F_55 ( V_9 , V_253 , & V_9 -> V_170 ) ;
}
V_9 -> V_86 = 4 ;
if ( V_117 -> V_31 >= 0x10 ) {
F_10 ( V_9 -> V_32 , V_254 , & V_122 ) ;
F_55 ( V_9 , V_255 , & V_9 -> V_167 ) ;
if ( ( V_117 -> V_31 > 0x10 || V_117 -> V_193 > 7 ) && V_122 & F_47 ( 25 ) )
V_9 -> V_86 = 8 ;
}
F_49 ( V_9 ) ;
}
static T_1 F_121 ( struct V_8 * V_9 , T_2 V_13 , int V_256 )
{
T_1 V_161 , V_257 ;
T_1 V_166 = V_13 ? V_9 -> V_167 : V_9 -> V_168 ;
V_161 = F_78 ( V_256 / 2 , V_166 ) ;
V_257 = V_9 -> V_209 -> V_210 ( V_9 , V_13 , V_161 ) << ( 20 - V_71 ) ;
F_26 ( 0 , L_93 ,
V_256 , V_13 , V_161 ) ;
F_26 ( 0 , L_94 , V_257 ) ;
return V_257 ;
}
static int F_122 ( struct V_25 * V_26 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
struct V_258 * V_43 ;
struct V_259 * V_202 ;
enum V_260 V_261 ;
enum V_101 V_262 ;
int V_21 , V_164 , V_263 = 1 ;
int V_257 = 0 ;
T_1 V_4 ;
F_10 ( V_9 -> V_32 , V_264 , & V_4 ) ;
V_9 -> V_154 = V_4 ;
F_26 ( 0 , L_95 ,
V_9 -> V_57 , V_4 ,
! ! ( V_4 & V_155 ) , ! ! ( V_4 & V_265 ) ) ;
F_30 (i, 0 , pvt) {
bool V_266 = ! ! F_31 ( V_21 , 0 , V_9 ) ;
bool V_267 = false ;
if ( V_30 . V_31 != 0xf )
V_267 = ! ! F_31 ( V_21 , 1 , V_9 ) ;
if ( ! V_266 && ! V_267 )
continue;
V_43 = V_26 -> V_268 [ V_21 ] ;
V_263 = 0 ;
F_26 ( 1 , L_96 ,
V_9 -> V_57 , V_21 ) ;
if ( V_266 ) {
V_257 = F_121 ( V_9 , 0 , V_21 ) ;
V_43 -> V_165 [ 0 ] -> V_202 -> V_257 = V_257 ;
}
if ( V_30 . V_31 != 0xf && V_267 ) {
int V_269 = F_121 ( V_9 , 1 , V_21 ) ;
V_43 -> V_165 [ 1 ] -> V_202 -> V_257 = V_269 ;
V_257 += V_269 ;
}
V_262 = F_57 ( V_9 , V_21 ) ;
F_26 ( 1 , L_97 , V_21 , V_257 ) ;
if ( V_9 -> V_154 & V_265 )
V_261 = ( V_9 -> V_154 & V_155 ) ?
V_270 : V_271 ;
else
V_261 = V_272 ;
for ( V_164 = 0 ; V_164 < V_9 -> V_273 ; V_164 ++ ) {
V_202 = V_43 -> V_165 [ V_164 ] -> V_202 ;
V_202 -> V_262 = V_262 ;
V_202 -> V_261 = V_261 ;
}
}
return V_263 ;
}
static void F_123 ( struct V_274 * V_45 , T_4 V_35 )
{
int V_275 ;
F_124 (cpu)
if ( F_60 ( V_275 ) == V_35 )
F_125 ( V_275 , V_45 ) ;
}
static bool F_126 ( T_4 V_35 )
{
T_5 V_45 ;
int V_275 , V_276 ;
bool V_64 = false ;
if ( ! F_127 ( & V_45 , V_277 ) ) {
F_3 ( L_98 , V_42 ) ;
return false ;
}
F_123 ( V_45 , V_35 ) ;
F_128 ( V_45 , V_278 , V_279 ) ;
F_129 (cpu, mask) {
struct V_280 * V_14 = F_130 ( V_279 , V_275 ) ;
V_276 = V_14 -> V_281 & V_282 ;
F_26 ( 0 , L_99 ,
V_275 , V_14 -> V_283 ,
( V_276 ? L_26 : L_27 ) ) ;
if ( ! V_276 )
goto V_284;
}
V_64 = true ;
V_284:
F_131 ( V_45 ) ;
return V_64 ;
}
static int F_132 ( struct V_285 * V_215 , T_4 V_35 , bool V_286 )
{
T_5 V_287 ;
int V_275 ;
if ( ! F_127 ( & V_287 , V_277 ) ) {
F_3 ( L_100 , V_42 ) ;
return false ;
}
F_123 ( V_287 , V_35 ) ;
F_128 ( V_287 , V_278 , V_279 ) ;
F_129 (cpu, cmask) {
struct V_280 * V_14 = F_130 ( V_279 , V_275 ) ;
if ( V_286 ) {
if ( V_14 -> V_281 & V_282 )
V_215 -> V_288 . V_289 = 1 ;
V_14 -> V_281 |= V_282 ;
} else {
if ( ! V_215 -> V_288 . V_289 )
V_14 -> V_281 &= ~ V_282 ;
}
}
F_133 ( V_287 , V_278 , V_279 ) ;
F_131 ( V_287 ) ;
return 0 ;
}
static bool F_134 ( struct V_285 * V_215 , T_4 V_35 ,
struct V_1 * V_32 )
{
bool V_64 = true ;
T_1 V_290 , V_45 = 0x3 ;
if ( F_132 ( V_215 , V_35 , V_291 ) ) {
F_3 ( L_101 ) ;
return false ;
}
F_10 ( V_32 , V_292 , & V_290 ) ;
V_215 -> V_293 = V_290 & V_45 ;
V_215 -> V_294 = true ;
V_290 |= V_45 ;
F_11 ( V_32 , V_292 , V_290 ) ;
F_10 ( V_32 , V_264 , & V_290 ) ;
F_26 ( 0 , L_102 ,
V_35 , V_290 , ! ! ( V_290 & V_265 ) ) ;
if ( ! ( V_290 & V_265 ) ) {
F_3 ( L_103 ) ;
V_215 -> V_288 . V_295 = 0 ;
V_290 |= V_265 ;
F_11 ( V_32 , V_264 , V_290 ) ;
F_10 ( V_32 , V_264 , & V_290 ) ;
if ( ! ( V_290 & V_265 ) ) {
F_3 ( L_104
L_105 ) ;
V_64 = false ;
} else {
F_51 ( L_106 ) ;
}
} else {
V_215 -> V_288 . V_295 = 1 ;
}
F_26 ( 0 , L_107 ,
V_35 , V_290 , ! ! ( V_290 & V_265 ) ) ;
return V_64 ;
}
static void F_135 ( struct V_285 * V_215 , T_4 V_35 ,
struct V_1 * V_32 )
{
T_1 V_290 , V_45 = 0x3 ;
if ( ! V_215 -> V_294 )
return;
F_10 ( V_32 , V_292 , & V_290 ) ;
V_290 &= ~ V_45 ;
V_290 |= V_215 -> V_293 ;
F_11 ( V_32 , V_292 , V_290 ) ;
if ( ! V_215 -> V_288 . V_295 ) {
F_10 ( V_32 , V_264 , & V_290 ) ;
V_290 &= ~ V_265 ;
F_11 ( V_32 , V_264 , V_290 ) ;
}
if ( F_132 ( V_215 , V_35 , V_296 ) )
F_3 ( L_108 ) ;
}
static bool F_136 ( struct V_1 * V_32 , T_4 V_35 )
{
T_1 V_290 ;
T_2 V_297 = 0 ;
bool V_298 = false ;
F_10 ( V_32 , V_264 , & V_290 ) ;
V_297 = ! ! ( V_290 & V_265 ) ;
F_51 ( L_109 , ( V_297 ? L_26 : L_27 ) ) ;
V_298 = F_126 ( V_35 ) ;
if ( ! V_298 )
F_137 ( L_110
L_111 ,
V_278 , V_35 ) ;
if ( ! V_297 || ! V_298 ) {
F_137 ( L_112 , V_299 ) ;
return false ;
}
return true ;
}
static int F_138 ( struct V_25 * V_26 )
{
int V_300 ;
V_300 = F_139 ( V_26 ) ;
if ( V_300 < 0 )
return V_300 ;
if ( V_30 . V_31 >= 0x10 ) {
V_300 = F_140 ( V_26 ) ;
if ( V_300 < 0 )
return V_300 ;
}
return 0 ;
}
static void F_141 ( struct V_25 * V_26 )
{
F_142 ( V_26 ) ;
if ( V_30 . V_31 >= 0x10 )
F_143 ( V_26 ) ;
}
static void F_144 ( struct V_25 * V_26 ,
struct V_301 * V_302 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
V_26 -> V_303 = V_304 | V_305 ;
V_26 -> V_306 = V_75 ;
if ( V_9 -> V_80 & V_82 )
V_26 -> V_306 |= V_77 ;
if ( V_9 -> V_80 & V_83 )
V_26 -> V_306 |= V_307 ;
V_26 -> V_74 = F_46 ( V_9 ) ;
V_26 -> V_308 = V_309 ;
V_26 -> V_310 = V_311 ;
V_26 -> V_312 = V_302 -> V_312 ;
V_26 -> V_313 = F_117 ( V_9 -> V_12 ) ;
V_26 -> V_314 = NULL ;
V_26 -> V_315 = F_16 ;
V_26 -> V_316 = F_17 ;
}
static struct V_301 * F_145 ( struct V_8 * V_9 )
{
T_2 V_302 = V_30 . V_31 ;
struct V_301 * V_317 = NULL ;
switch ( V_302 ) {
case 0xf :
V_317 = & V_318 [ V_319 ] ;
V_9 -> V_209 = & V_318 [ V_319 ] . V_209 ;
break;
case 0x10 :
V_317 = & V_318 [ V_320 ] ;
V_9 -> V_209 = & V_318 [ V_320 ] . V_209 ;
break;
case 0x15 :
V_317 = & V_318 [ V_321 ] ;
V_9 -> V_209 = & V_318 [ V_321 ] . V_209 ;
break;
default:
F_116 ( L_113 ) ;
return NULL ;
}
V_9 -> V_51 = V_30 . V_193 >> 4 ;
F_51 ( L_114 , V_317 -> V_312 ,
( V_302 == 0xf ?
( V_9 -> V_51 >= V_52 ? L_115
: L_116 )
: L_22 ) , V_9 -> V_57 ) ;
return V_317 ;
}
static int F_146 ( struct V_1 * V_12 )
{
struct V_8 * V_9 = NULL ;
struct V_301 * V_317 = NULL ;
struct V_25 * V_26 = NULL ;
struct V_322 V_323 [ 2 ] ;
int V_6 = 0 , V_64 ;
T_4 V_35 = F_147 ( V_12 ) ;
V_64 = - V_324 ;
V_9 = F_148 ( sizeof( struct V_8 ) , V_277 ) ;
if ( ! V_9 )
goto V_325;
V_9 -> V_57 = V_35 ;
V_9 -> V_12 = V_12 ;
V_64 = - V_11 ;
V_317 = F_145 ( V_9 ) ;
if ( ! V_317 )
goto V_326;
V_64 = - V_238 ;
V_6 = F_115 ( V_9 , V_317 -> V_235 , V_317 -> V_236 ) ;
if ( V_6 )
goto V_326;
F_119 ( V_9 ) ;
V_64 = - V_11 ;
V_9 -> V_273 = V_9 -> V_209 -> V_327 ( V_9 ) ;
if ( V_9 -> V_273 < 0 )
goto V_328;
V_64 = - V_324 ;
V_323 [ 0 ] . type = V_329 ;
V_323 [ 0 ] . V_330 = V_9 -> V_53 [ 0 ] . V_88 ;
V_323 [ 0 ] . V_331 = true ;
V_323 [ 1 ] . type = V_332 ;
V_323 [ 1 ] . V_330 = V_9 -> V_273 ;
V_323 [ 1 ] . V_331 = false ;
V_26 = F_149 ( V_35 , F_14 ( V_323 ) , V_323 , 0 ) ;
if ( ! V_26 )
goto V_328;
V_26 -> V_28 = V_9 ;
V_26 -> V_2 = & V_9 -> V_12 -> V_131 ;
F_144 ( V_26 , V_317 ) ;
if ( F_122 ( V_26 ) )
V_26 -> V_74 = V_75 ;
V_64 = - V_238 ;
if ( F_150 ( V_26 ) ) {
F_26 ( 1 , L_117 ) ;
goto V_333;
}
if ( F_138 ( V_26 ) ) {
F_26 ( 1 , L_117 ) ;
goto V_334;
}
if ( V_335 )
F_151 ( true ) ;
F_152 ( F_114 ) ;
V_125 [ V_35 ] = V_26 ;
F_153 ( & V_336 ) ;
return 0 ;
V_334:
F_154 ( V_26 -> V_2 ) ;
V_333:
F_155 ( V_26 ) ;
V_328:
F_118 ( V_9 ) ;
V_326:
F_156 ( V_9 ) ;
V_325:
return V_64 ;
}
static int F_157 ( struct V_1 * V_2 ,
const struct V_337 * V_338 )
{
T_4 V_35 = F_147 ( V_2 ) ;
struct V_1 * V_32 = F_68 ( V_35 ) -> V_137 ;
struct V_285 * V_215 ;
int V_64 = 0 ;
V_64 = F_158 ( V_2 ) ;
if ( V_64 < 0 ) {
F_26 ( 0 , L_118 , V_64 ) ;
return - V_339 ;
}
V_64 = - V_324 ;
V_215 = F_148 ( sizeof( struct V_285 ) , V_277 ) ;
if ( ! V_215 )
goto V_340;
V_341 [ V_35 ] = V_215 ;
if ( ! F_136 ( V_32 , V_35 ) ) {
V_64 = - V_238 ;
if ( ! V_342 )
goto V_343;
F_3 ( L_119 ) ;
if ( ! F_134 ( V_215 , V_35 , V_32 ) )
goto V_343;
}
V_64 = F_146 ( V_2 ) ;
if ( V_64 < 0 ) {
F_116 ( L_120 , V_35 ) ;
F_135 ( V_215 , V_35 , V_32 ) ;
}
return V_64 ;
V_343:
F_156 ( V_215 ) ;
V_341 [ V_35 ] = NULL ;
V_340:
return V_64 ;
}
static void F_159 ( struct V_1 * V_2 )
{
struct V_25 * V_26 ;
struct V_8 * V_9 ;
T_4 V_35 = F_147 ( V_2 ) ;
struct V_1 * V_32 = F_68 ( V_35 ) -> V_137 ;
struct V_285 * V_215 = V_341 [ V_35 ] ;
V_26 = F_160 ( & V_2 -> V_131 ) ;
F_141 ( V_26 ) ;
V_26 = F_154 ( & V_2 -> V_131 ) ;
if ( ! V_26 )
return;
V_9 = V_26 -> V_28 ;
F_135 ( V_215 , V_35 , V_32 ) ;
F_118 ( V_9 ) ;
F_151 ( false ) ;
F_161 ( F_114 ) ;
F_156 ( V_341 [ V_35 ] ) ;
V_341 [ V_35 ] = NULL ;
V_26 -> V_28 = NULL ;
V_125 [ V_35 ] = NULL ;
F_156 ( V_9 ) ;
F_155 ( V_26 ) ;
}
static void F_162 ( void )
{
struct V_25 * V_26 ;
struct V_8 * V_9 ;
if ( V_344 )
return;
V_26 = V_125 [ 0 ] ;
if ( V_26 ) {
V_9 = V_26 -> V_28 ;
V_344 =
F_163 ( & V_9 -> V_12 -> V_131 , V_309 ) ;
if ( ! V_344 ) {
F_164 ( L_121 ,
V_42 ) ;
F_164 ( L_122 ,
V_42 ) ;
}
}
}
static int T_6 F_165 ( void )
{
int V_6 = - V_238 ;
F_166 ( V_345 L_123 , V_311 ) ;
F_167 () ;
if ( F_168 () < 0 )
goto V_325;
V_6 = - V_324 ;
V_125 = F_148 ( F_169 () * sizeof( V_125 [ 0 ] ) , V_277 ) ;
V_341 = F_148 ( F_169 () * sizeof( V_341 [ 0 ] ) , V_277 ) ;
if ( ! ( V_125 && V_341 ) )
goto V_326;
V_279 = F_170 () ;
if ( ! V_279 )
goto V_326;
V_6 = F_171 ( & V_346 ) ;
if ( V_6 )
goto V_347;
V_6 = - V_238 ;
if ( ! F_172 ( & V_336 ) )
goto V_348;
F_162 () ;
return 0 ;
V_348:
F_173 ( & V_346 ) ;
V_347:
F_174 ( V_279 ) ;
V_279 = NULL ;
V_326:
F_156 ( V_125 ) ;
V_125 = NULL ;
F_156 ( V_341 ) ;
V_341 = NULL ;
V_325:
return V_6 ;
}
static void T_7 F_175 ( void )
{
if ( V_344 )
F_176 ( V_344 ) ;
F_173 ( & V_346 ) ;
F_156 ( V_341 ) ;
V_341 = NULL ;
F_156 ( V_125 ) ;
V_125 = NULL ;
F_174 ( V_279 ) ;
V_279 = NULL ;
}
