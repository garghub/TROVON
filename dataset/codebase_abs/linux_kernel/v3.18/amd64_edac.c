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
static void F_7 ( struct V_8 * V_9 , T_2 V_10 )
{
T_1 V_11 = 0 ;
F_8 ( V_9 -> V_12 , V_13 , & V_11 ) ;
V_11 &= ( V_9 -> V_14 == 0x30 ) ? ~ 3 : ~ 1 ;
V_11 |= V_10 ;
F_9 ( V_9 -> V_12 , V_13 , V_11 ) ;
}
static inline int F_10 ( struct V_8 * V_9 , T_2 V_10 ,
int V_3 , T_1 * V_4 )
{
switch ( V_9 -> V_15 ) {
case 0xf :
if ( V_10 || V_3 >= 0x100 )
return - V_16 ;
break;
case 0x10 :
if ( V_10 ) {
if ( F_11 ( V_9 ) )
return 0 ;
V_3 += 0x100 ;
}
break;
case 0x15 :
V_10 = ( V_10 && V_9 -> V_14 == 0x30 ) ? 3 : V_10 ;
F_7 ( V_9 , V_10 ) ;
break;
case 0x16 :
if ( V_10 )
return - V_16 ;
break;
default:
break;
}
return F_8 ( V_9 -> V_17 , V_3 , V_4 ) ;
}
static int F_12 ( struct V_1 * V_18 , T_1 V_19 , T_1 V_20 )
{
T_1 V_21 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < F_13 ( V_23 ) - 1 ; V_22 ++ ) {
if ( V_23 [ V_22 ] . V_21 < V_20 )
continue;
if ( V_23 [ V_22 ] . V_24 <= V_19 )
break;
}
V_21 = V_23 [ V_22 ] . V_21 ;
F_14 ( V_18 , V_25 , V_21 , 0x001F ) ;
if ( V_21 )
return V_23 [ V_22 ] . V_24 ;
return 0 ;
}
static int F_15 ( struct V_26 * V_27 , T_1 V_28 )
{
struct V_8 * V_9 = V_27 -> V_29 ;
T_1 V_30 = 0x5 ;
if ( V_9 -> V_15 == 0xf )
V_30 = 0x0 ;
if ( V_9 -> V_15 == 0x15 && V_9 -> V_14 < 0x10 )
F_7 ( V_9 , 0 ) ;
return F_12 ( V_9 -> V_31 , V_28 , V_30 ) ;
}
static int F_16 ( struct V_26 * V_27 )
{
struct V_8 * V_9 = V_27 -> V_29 ;
T_1 V_21 = 0 ;
int V_22 , V_32 = - V_16 ;
if ( V_9 -> V_15 == 0x15 && V_9 -> V_14 < 0x10 )
F_7 ( V_9 , 0 ) ;
F_8 ( V_9 -> V_31 , V_25 , & V_21 ) ;
V_21 = V_21 & 0x001F ;
for ( V_22 = 0 ; V_22 < F_13 ( V_23 ) ; V_22 ++ ) {
if ( V_23 [ V_22 ] . V_21 == V_21 ) {
V_32 = V_23 [ V_22 ] . V_24 ;
break;
}
}
return V_32 ;
}
static bool F_17 ( struct V_8 * V_9 , T_3 V_33 , T_2 V_34 )
{
T_3 V_35 ;
V_35 = V_33 & 0x000000ffffffffffull ;
return ( ( V_35 >= F_18 ( V_9 , V_34 ) ) &&
( V_35 <= F_19 ( V_9 , V_34 ) ) ) ;
}
static struct V_26 * F_20 ( struct V_26 * V_27 ,
T_3 V_33 )
{
struct V_8 * V_9 ;
T_2 V_36 ;
T_1 V_37 , V_38 ;
V_9 = V_27 -> V_29 ;
V_37 = F_21 ( V_9 , 0 ) ;
if ( V_37 == 0 ) {
for ( V_36 = 0 ; V_36 < V_39 ; V_36 ++ ) {
if ( F_17 ( V_9 , V_33 , V_36 ) )
goto V_40;
}
goto V_41;
}
if ( F_22 ( ( V_37 != 0x01 ) &&
( V_37 != 0x03 ) &&
( V_37 != 0x07 ) ) ) {
F_3 ( L_3 , V_37 ) ;
return NULL ;
}
V_38 = ( ( ( T_1 ) V_33 ) >> 12 ) & V_37 ;
for ( V_36 = 0 ; ; ) {
if ( ( F_23 ( V_9 , V_36 ) & V_37 ) == V_38 )
break;
if ( ++ V_36 >= V_39 )
goto V_41;
}
if ( F_22 ( ! F_17 ( V_9 , V_33 , V_36 ) ) ) {
F_3 ( L_4
L_5 ,
V_42 , V_33 , V_36 ) ;
return NULL ;
}
V_40:
return F_24 ( ( int ) V_36 ) ;
V_41:
F_25 ( 2 , L_6 ,
( unsigned long ) V_33 ) ;
return NULL ;
}
static void F_26 ( struct V_8 * V_9 , int V_43 , T_2 V_10 ,
T_3 * V_44 , T_3 * V_45 )
{
T_3 V_46 , V_47 , V_48 , V_49 ;
T_2 V_50 ;
if ( V_9 -> V_15 == 0xf && V_9 -> V_51 < V_52 ) {
V_46 = V_9 -> V_53 [ V_10 ] . V_54 [ V_43 ] ;
V_47 = V_9 -> V_53 [ V_10 ] . V_55 [ V_43 ] ;
V_48 = F_27 ( 31 , 21 ) | F_27 ( 15 , 9 ) ;
V_49 = F_27 ( 29 , 21 ) | F_27 ( 15 , 9 ) ;
V_50 = 4 ;
} else if ( V_9 -> V_15 == 0x16 ||
( V_9 -> V_15 == 0x15 && V_9 -> V_14 >= 0x30 ) ) {
V_46 = V_9 -> V_53 [ V_10 ] . V_54 [ V_43 ] ;
V_47 = V_9 -> V_53 [ V_10 ] . V_55 [ V_43 >> 1 ] ;
* V_44 = ( V_46 & F_27 ( 15 , 5 ) ) << 6 ;
* V_44 |= ( V_46 & F_27 ( 30 , 19 ) ) << 8 ;
* V_45 = ~ 0ULL ;
* V_45 &= ~ ( ( F_27 ( 15 , 5 ) << 6 ) |
( F_27 ( 30 , 19 ) << 8 ) ) ;
* V_45 |= ( V_47 & F_27 ( 15 , 5 ) ) << 6 ;
* V_45 |= ( V_47 & F_27 ( 30 , 19 ) ) << 8 ;
return;
} else {
V_46 = V_9 -> V_53 [ V_10 ] . V_54 [ V_43 ] ;
V_47 = V_9 -> V_53 [ V_10 ] . V_55 [ V_43 >> 1 ] ;
V_50 = 8 ;
if ( V_9 -> V_15 == 0x15 )
V_48 = V_49 =
F_27 ( 30 , 19 ) | F_27 ( 13 , 5 ) ;
else
V_48 = V_49 =
F_27 ( 28 , 19 ) | F_27 ( 13 , 5 ) ;
}
* V_44 = ( V_46 & V_48 ) << V_50 ;
* V_45 = ~ 0ULL ;
* V_45 &= ~ ( V_49 << V_50 ) ;
* V_45 |= ( V_47 & V_49 ) << V_50 ;
}
static int F_28 ( struct V_26 * V_27 , T_3 V_56 )
{
struct V_8 * V_9 ;
int V_43 ;
T_3 V_44 , V_45 ;
V_9 = V_27 -> V_29 ;
F_29 (csrow, 0 , pvt) {
if ( ! F_30 ( V_43 , 0 , V_9 ) )
continue;
F_26 ( V_9 , V_43 , 0 , & V_44 , & V_45 ) ;
V_45 = ~ V_45 ;
if ( ( V_56 & V_45 ) == ( V_44 & V_45 ) ) {
F_25 ( 2 , L_7 ,
( unsigned long ) V_56 , V_43 ,
V_9 -> V_57 ) ;
return V_43 ;
}
}
F_25 ( 2 , L_8 ,
( unsigned long ) V_56 , V_9 -> V_57 ) ;
return - 1 ;
}
int F_31 ( struct V_26 * V_27 , T_3 * V_58 ,
T_3 * V_59 , T_3 * V_60 )
{
struct V_8 * V_9 = V_27 -> V_29 ;
if ( V_9 -> V_15 == 0xf && V_9 -> V_51 < V_61 ) {
F_25 ( 1 , L_9 ,
V_9 -> V_51 , V_9 -> V_57 ) ;
return 1 ;
}
if ( V_9 -> V_15 >= 0x10 && ! F_32 ( V_9 ) ) {
F_25 ( 1 , L_10 ) ;
return 1 ;
}
if ( ! F_33 ( V_9 ) ) {
F_25 ( 1 , L_11 ,
V_9 -> V_57 ) ;
return 1 ;
}
* V_58 = F_34 ( V_9 ) ;
* V_60 = ( 1ULL << 32 ) - * V_58 ;
* V_59 = ( V_9 -> V_15 > 0xf ) ? F_35 ( V_9 )
: F_36 ( V_9 ) ;
F_25 ( 1 , L_12 ,
V_9 -> V_57 , ( unsigned long ) * V_58 ,
( unsigned long ) * V_59 , ( unsigned long ) * V_60 ) ;
return 0 ;
}
static T_3 F_37 ( struct V_26 * V_27 , T_3 V_33 )
{
struct V_8 * V_9 = V_27 -> V_29 ;
T_3 V_62 , V_58 , V_59 , V_60 , V_63 ;
int V_64 ;
V_62 = F_18 ( V_9 , V_9 -> V_57 ) ;
V_64 = F_31 ( V_27 , & V_58 , & V_59 ,
& V_60 ) ;
if ( ! V_64 ) {
if ( ( V_33 >= ( 1ULL << 32 ) ) &&
( V_33 < ( ( 1ULL << 32 ) + V_60 ) ) ) {
V_63 = V_33 - V_59 ;
F_25 ( 2 , L_13 ,
( unsigned long ) V_33 ,
( unsigned long ) V_63 ) ;
return V_63 ;
}
}
V_63 = ( V_33 & F_27 ( 39 , 0 ) ) - V_62 ;
F_25 ( 2 , L_14 ,
( unsigned long ) V_33 , ( unsigned long ) V_63 ) ;
return V_63 ;
}
static int F_38 ( unsigned V_37 )
{
static const int V_65 [] = { 0 , 1 , 0 , 2 , 0 , 0 , 0 , 3 } ;
int V_66 ;
F_39 ( V_37 > 7 ) ;
V_66 = V_65 [ V_37 ] ;
return V_66 ;
}
static T_3 F_40 ( struct V_26 * V_27 , T_3 V_63 )
{
struct V_8 * V_9 ;
int V_67 ;
T_3 V_56 ;
V_9 = V_27 -> V_29 ;
V_67 = F_38 ( F_21 ( V_9 , 0 ) ) ;
V_56 = ( ( V_63 >> V_67 ) & F_27 ( 35 , 12 ) ) +
( V_63 & 0xfff ) ;
F_25 ( 2 , L_15 ,
V_67 , ( unsigned long ) V_63 ,
( unsigned long ) V_56 ) ;
return V_56 ;
}
static T_3 F_41 ( struct V_26 * V_27 , T_3 V_33 )
{
T_3 V_56 ;
V_56 =
F_40 ( V_27 , F_37 ( V_27 , V_33 ) ) ;
F_25 ( 2 , L_16 ,
( unsigned long ) V_33 , ( unsigned long ) V_56 ) ;
return V_56 ;
}
static inline void F_42 ( T_3 V_68 ,
struct V_69 * V_6 )
{
V_6 -> V_70 = ( T_1 ) ( V_68 >> V_71 ) ;
V_6 -> V_3 = ( ( T_1 ) V_68 ) & ~ V_72 ;
}
static int F_43 ( struct V_26 * V_27 , T_3 V_33 )
{
int V_43 ;
V_43 = F_28 ( V_27 , F_41 ( V_27 , V_33 ) ) ;
if ( V_43 == - 1 )
F_44 ( V_27 , L_17
L_18 , ( unsigned long ) V_33 ) ;
return V_43 ;
}
static unsigned long F_45 ( struct V_8 * V_9 )
{
T_2 V_73 ;
unsigned long V_74 = V_75 ;
V_73 = ( V_9 -> V_15 > 0xf || V_9 -> V_51 >= V_52 )
? 19
: 17 ;
if ( V_9 -> V_76 & F_46 ( V_73 ) )
V_74 = V_77 ;
return V_74 ;
}
static void F_47 ( struct V_8 * V_9 , T_1 V_78 , int V_79 )
{
F_25 ( 1 , L_19 , V_79 , V_78 ) ;
F_25 ( 1 , L_20 ,
( V_78 & F_46 ( 16 ) ) ? L_21 : L_22 ,
( V_78 & F_46 ( 19 ) ) ? L_23 : L_24 ) ;
F_25 ( 1 , L_25 ,
( V_78 & F_46 ( 8 ) ) ? L_26 : L_27 ) ;
if ( V_9 -> V_15 == 0x10 )
F_25 ( 1 , L_28 ,
( V_78 & F_46 ( 11 ) ) ? L_29 : L_30 ) ;
F_25 ( 1 , L_31 ,
( V_78 & F_46 ( 12 ) ) ? L_23 : L_24 ,
( V_78 & F_46 ( 13 ) ) ? L_23 : L_24 ,
( V_78 & F_46 ( 14 ) ) ? L_23 : L_24 ,
( V_78 & F_46 ( 15 ) ) ? L_23 : L_24 ) ;
}
static void F_48 ( struct V_8 * V_9 )
{
F_25 ( 1 , L_32 , V_9 -> V_80 ) ;
F_25 ( 1 , L_33 ,
( V_9 -> V_80 & V_81 ) ? L_23 : L_24 ) ;
F_25 ( 1 , L_34 ,
( V_9 -> V_80 & V_82 ) ? L_23 : L_24 ,
( V_9 -> V_80 & V_83 ) ? L_23 : L_24 ) ;
F_47 ( V_9 , V_9 -> V_76 , 0 ) ;
F_25 ( 1 , L_35 , V_9 -> V_84 ) ;
F_25 ( 1 , L_36 ,
V_9 -> V_85 , F_34 ( V_9 ) ,
( V_9 -> V_15 == 0xf ) ? F_36 ( V_9 )
: F_35 ( V_9 ) ) ;
F_25 ( 1 , L_37 , F_33 ( V_9 ) ? L_23 : L_24 ) ;
F_49 ( V_9 , 0 ) ;
if ( V_9 -> V_15 == 0xf )
return;
F_49 ( V_9 , 1 ) ;
F_50 ( L_38 , ( ( V_9 -> V_86 == 8 ) ? L_39 : L_40 ) ) ;
if ( ! F_11 ( V_9 ) )
F_47 ( V_9 , V_9 -> V_87 , 1 ) ;
}
static void F_51 ( struct V_8 * V_9 )
{
if ( V_9 -> V_15 == 0xf && V_9 -> V_51 < V_52 ) {
V_9 -> V_53 [ 0 ] . V_88 = V_9 -> V_53 [ 1 ] . V_88 = 8 ;
V_9 -> V_53 [ 0 ] . V_89 = V_9 -> V_53 [ 1 ] . V_89 = 8 ;
} else if ( V_9 -> V_15 == 0x15 && V_9 -> V_14 >= 0x30 ) {
V_9 -> V_53 [ 0 ] . V_88 = V_9 -> V_53 [ 1 ] . V_88 = 4 ;
V_9 -> V_53 [ 0 ] . V_89 = V_9 -> V_53 [ 1 ] . V_89 = 2 ;
} else {
V_9 -> V_53 [ 0 ] . V_88 = V_9 -> V_53 [ 1 ] . V_88 = 8 ;
V_9 -> V_53 [ 0 ] . V_89 = V_9 -> V_53 [ 1 ] . V_89 = 4 ;
}
}
static void F_52 ( struct V_8 * V_9 )
{
int V_90 ;
F_51 ( V_9 ) ;
F_29 (cs, 0 , pvt) {
int V_91 = V_92 + ( V_90 * 4 ) ;
int V_93 = V_94 + ( V_90 * 4 ) ;
T_1 * V_95 = & V_9 -> V_53 [ 0 ] . V_54 [ V_90 ] ;
T_1 * V_96 = & V_9 -> V_53 [ 1 ] . V_54 [ V_90 ] ;
if ( ! F_10 ( V_9 , 0 , V_91 , V_95 ) )
F_25 ( 0 , L_41 ,
V_90 , * V_95 , V_91 ) ;
if ( V_9 -> V_15 == 0xf )
continue;
if ( ! F_10 ( V_9 , 1 , V_91 , V_96 ) )
F_25 ( 0 , L_42 ,
V_90 , * V_96 , ( V_9 -> V_15 == 0x10 ) ? V_93
: V_91 ) ;
}
F_53 (cs, 0 , pvt) {
int V_91 = V_97 + ( V_90 * 4 ) ;
int V_93 = V_98 + ( V_90 * 4 ) ;
T_1 * V_99 = & V_9 -> V_53 [ 0 ] . V_55 [ V_90 ] ;
T_1 * V_100 = & V_9 -> V_53 [ 1 ] . V_55 [ V_90 ] ;
if ( ! F_10 ( V_9 , 0 , V_91 , V_99 ) )
F_25 ( 0 , L_43 ,
V_90 , * V_99 , V_91 ) ;
if ( V_9 -> V_15 == 0xf )
continue;
if ( ! F_10 ( V_9 , 1 , V_91 , V_100 ) )
F_25 ( 0 , L_44 ,
V_90 , * V_100 , ( V_9 -> V_15 == 0x10 ) ? V_93
: V_91 ) ;
}
}
static enum V_101 F_54 ( struct V_8 * V_9 , int V_90 )
{
enum V_101 type ;
if ( V_9 -> V_15 >= 0x15 )
type = ( V_9 -> V_76 & F_46 ( 16 ) ) ? V_102 : V_103 ;
else if ( V_9 -> V_15 == 0x10 || V_9 -> V_51 >= V_52 ) {
if ( V_9 -> V_104 & V_105 )
type = ( V_9 -> V_76 & F_46 ( 16 ) ) ? V_102 : V_103 ;
else
type = ( V_9 -> V_76 & F_46 ( 16 ) ) ? V_106 : V_107 ;
} else {
type = ( V_9 -> V_76 & F_46 ( 18 ) ) ? V_108 : V_109 ;
}
F_50 ( L_45 , V_90 , V_110 [ type ] ) ;
return type ;
}
static int F_55 ( struct V_8 * V_9 )
{
int V_111 ;
if ( V_9 -> V_51 >= V_52 )
V_111 = V_9 -> V_76 & V_112 ;
else
V_111 = V_9 -> V_76 & V_113 ;
V_9 -> V_87 = 0 ;
return ( V_111 ) ? 2 : 1 ;
}
static T_3 F_56 ( struct V_8 * V_9 , struct V_114 * V_115 )
{
T_3 V_35 ;
T_2 V_116 = 1 ;
T_2 V_117 = 47 ;
if ( V_9 -> V_15 == 0xf ) {
V_116 = 3 ;
V_117 = 39 ;
}
V_35 = V_115 -> V_35 & F_27 ( V_117 , V_116 ) ;
if ( V_9 -> V_15 == 0x15 ) {
struct V_8 * V_9 ;
T_3 V_118 , V_119 ;
T_1 V_120 ;
T_4 V_121 ;
T_2 V_37 ;
if ( ( V_35 & F_27 ( 47 , 24 ) ) >> 24 != 0x00fdf7 )
return V_35 ;
V_121 = F_57 ( V_115 -> V_122 ) ;
V_9 = V_123 [ V_121 ] -> V_29 ;
F_8 ( V_9 -> V_12 , V_124 , & V_120 ) ;
V_37 = V_120 >> 21 & 0x7 ;
V_118 = ( V_120 & F_27 ( 20 , 0 ) ) << 3 ;
V_118 |= V_37 ^ 0x7 ;
V_118 <<= 24 ;
if ( ! V_37 )
return V_118 | ( V_35 & F_27 ( 23 , 0 ) ) ;
F_8 ( V_9 -> V_12 , V_125 , & V_120 ) ;
V_119 = ( V_35 & F_27 ( 23 , 12 ) ) << F_58 ( V_37 + 1 ) ;
V_119 |= ( V_120 & F_27 ( 23 , 21 ) ) >> 9 ;
V_119 |= V_35 & F_27 ( 11 , 0 ) ;
return V_118 | V_119 ;
}
return V_35 ;
}
static struct V_1 * F_59 ( unsigned int V_126 ,
unsigned int V_127 ,
struct V_1 * V_128 )
{
struct V_1 * V_129 = NULL ;
while ( ( V_129 = F_60 ( V_126 , V_127 , V_129 ) ) ) {
if ( F_61 ( V_129 -> V_130 ) == F_61 ( V_128 -> V_130 ) &&
( V_129 -> V_130 -> V_131 == V_128 -> V_130 -> V_131 ) &&
( F_62 ( V_129 -> V_7 ) == F_62 ( V_128 -> V_7 ) ) )
break;
}
return V_129 ;
}
static void F_63 ( struct V_8 * V_9 , unsigned V_132 )
{
struct V_133 * V_134 ;
struct V_1 * V_135 = NULL ;
unsigned int V_136 ;
int V_137 = V_132 << 3 ;
T_1 V_138 ;
F_8 ( V_9 -> V_12 , V_139 + V_137 , & V_9 -> V_140 [ V_132 ] . V_44 . V_141 ) ;
F_8 ( V_9 -> V_12 , V_142 + V_137 , & V_9 -> V_140 [ V_132 ] . V_143 . V_141 ) ;
if ( V_9 -> V_15 == 0xf )
return;
if ( ! F_64 ( V_9 , V_132 ) )
return;
F_8 ( V_9 -> V_12 , V_144 + V_137 , & V_9 -> V_140 [ V_132 ] . V_44 . V_145 ) ;
F_8 ( V_9 -> V_12 , V_146 + V_137 , & V_9 -> V_140 [ V_132 ] . V_143 . V_145 ) ;
if ( V_9 -> V_15 != 0x15 )
return;
V_134 = F_65 ( F_66 ( V_9 , V_132 ) ) ;
if ( F_67 ( ! V_134 ) )
return;
V_136 = ( V_9 -> V_14 == 0x30 ) ? V_147
: V_148 ;
V_135 = F_59 ( V_134 -> V_149 -> V_126 , V_136 , V_134 -> V_149 ) ;
if ( F_67 ( ! V_135 ) )
return;
F_8 ( V_135 , V_124 , & V_138 ) ;
V_9 -> V_140 [ V_132 ] . V_143 . V_141 &= F_27 ( 15 , 0 ) ;
V_9 -> V_140 [ V_132 ] . V_143 . V_141 |= ( ( V_138 & 0x1fff ) << 3 | 0x7 ) << 16 ;
V_9 -> V_140 [ V_132 ] . V_143 . V_145 &= F_27 ( 7 , 0 ) ;
V_9 -> V_140 [ V_132 ] . V_143 . V_145 |= V_138 >> 13 ;
F_68 ( V_135 ) ;
}
static void F_69 ( struct V_26 * V_27 , T_3 V_33 ,
struct V_69 * V_6 )
{
struct V_8 * V_9 = V_27 -> V_29 ;
F_42 ( V_33 , V_6 ) ;
V_6 -> V_150 = F_20 ( V_27 , V_33 ) ;
if ( ! V_6 -> V_150 ) {
F_44 ( V_27 , L_46 ,
( unsigned long ) V_33 ) ;
V_6 -> V_151 = V_152 ;
return;
}
V_6 -> V_43 = F_43 ( V_6 -> V_150 , V_33 ) ;
if ( V_6 -> V_43 < 0 ) {
V_6 -> V_151 = V_153 ;
return;
}
if ( V_9 -> V_154 & V_155 ) {
V_6 -> V_156 = F_70 ( V_27 , V_6 -> V_157 ) ;
if ( V_6 -> V_156 < 0 ) {
F_71 ( V_6 -> V_150 , L_47
L_48 ,
V_6 -> V_157 ) ;
V_6 -> V_151 = V_158 ;
return;
}
} else {
V_6 -> V_156 = ( ( V_33 & F_46 ( 3 ) ) != 0 ) ;
}
}
static int F_72 ( unsigned V_22 , bool V_159 )
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
static int F_73 ( struct V_8 * V_9 , T_2 V_10 ,
unsigned V_161 )
{
T_1 V_78 = V_10 ? V_9 -> V_87 : V_9 -> V_76 ;
if ( V_9 -> V_51 >= V_52 ) {
F_67 ( V_161 > 11 ) ;
return F_72 ( V_161 , V_78 & V_112 ) ;
}
else if ( V_9 -> V_51 >= V_162 ) {
unsigned V_163 ;
F_67 ( V_161 > 10 ) ;
V_163 = V_161 / 3 + ( unsigned ) ( V_161 > 5 ) ;
return 32 << ( V_161 - V_163 ) ;
}
else {
F_67 ( V_161 > 6 ) ;
return 32 << V_161 ;
}
}
static int F_74 ( struct V_8 * V_9 )
{
int V_22 , V_164 , V_165 = 0 ;
if ( V_9 -> V_15 == 0x10 && ( V_9 -> V_76 & V_112 ) )
return 2 ;
F_25 ( 0 , L_49 ) ;
for ( V_22 = 0 ; V_22 < 2 ; V_22 ++ ) {
T_1 V_166 = ( V_22 ? V_9 -> V_167 : V_9 -> V_168 ) ;
for ( V_164 = 0 ; V_164 < 4 ; V_164 ++ ) {
if ( F_75 ( V_164 , V_166 ) > 0 ) {
V_165 ++ ;
break;
}
}
}
if ( V_165 > 2 )
V_165 = 2 ;
F_50 ( L_50 , V_165 ) ;
return V_165 ;
}
static int F_76 ( unsigned V_22 , bool V_159 )
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
static int F_77 ( struct V_8 * V_9 , T_2 V_10 ,
unsigned V_161 )
{
T_1 V_78 = V_10 ? V_9 -> V_87 : V_9 -> V_76 ;
F_67 ( V_161 > 11 ) ;
if ( V_9 -> V_104 & V_105 || V_9 -> V_170 & V_105 )
return F_76 ( V_161 , V_78 & V_112 ) ;
else
return F_72 ( V_161 , V_78 & V_112 ) ;
}
static int F_78 ( struct V_8 * V_9 , T_2 V_10 ,
unsigned V_161 )
{
F_67 ( V_161 > 12 ) ;
return F_76 ( V_161 , false ) ;
}
static int F_79 ( struct V_8 * V_9 , T_2 V_10 ,
unsigned V_161 )
{
F_67 ( V_161 > 12 ) ;
if ( V_161 == 6 || V_161 == 8 ||
V_161 == 9 || V_161 == 12 )
return - 1 ;
else
return F_76 ( V_161 , false ) ;
}
static void F_80 ( struct V_8 * V_9 )
{
if ( V_9 -> V_15 == 0xf )
return;
if ( ! F_8 ( V_9 -> V_17 , V_171 , & V_9 -> V_172 ) ) {
F_25 ( 0 , L_51 ,
V_9 -> V_172 , F_81 ( V_9 ) ) ;
F_25 ( 0 , L_52 ,
( F_11 ( V_9 ) ? L_53 : L_54 ) ) ;
if ( ! F_11 ( V_9 ) )
F_25 ( 0 , L_55 ,
( F_82 ( V_9 ) ? L_23 : L_24 ) ) ;
F_25 ( 0 , L_56 ,
( F_83 ( V_9 ) ? L_26 : L_27 ) ,
( F_84 ( V_9 ) ? L_23 : L_24 ) ) ;
F_25 ( 0 , L_57
L_58 ,
( F_85 ( V_9 ) ? L_26 : L_27 ) ,
F_86 ( V_9 ) ) ;
}
F_8 ( V_9 -> V_17 , V_173 , & V_9 -> V_174 ) ;
}
static T_2 F_87 ( struct V_8 * V_9 , T_3 V_33 ,
T_2 V_37 , int V_175 ,
T_1 V_176 )
{
T_2 V_156 = 0 ;
T_2 V_177 ;
if ( ! ( V_37 ) )
return ( T_2 ) ( V_176 ) ;
if ( V_175 == 2 ) {
V_177 = ( V_33 >> 8 ) & 0x3 ;
V_156 = V_177 ? 0x3 : 0 ;
} else if ( V_175 == 4 ) {
T_2 V_178 = F_86 ( V_9 ) ;
switch ( V_178 ) {
case 0x4 :
V_156 = ( V_33 >> 8 ) & 0x3 ;
break;
case 0x5 :
V_156 = ( V_33 >> 9 ) & 0x3 ;
break;
}
}
return V_156 ;
}
static T_2 F_88 ( struct V_8 * V_9 , T_3 V_33 ,
bool V_179 , T_2 V_37 )
{
T_2 V_180 = ( V_9 -> V_172 >> 1 ) & 1 ;
if ( F_11 ( V_9 ) )
return 0 ;
if ( V_179 )
return V_180 ;
if ( F_85 ( V_9 ) ) {
T_2 V_178 = F_86 ( V_9 ) ;
if ( ! V_178 )
return V_33 >> 6 & 1 ;
if ( V_178 & 0x2 ) {
T_2 V_160 = V_178 & 0x1 ? 9 : 6 ;
T_1 V_181 = F_89 ( ( T_1 ) ( ( V_33 >> 16 ) & 0x1F ) ) % 2 ;
return ( ( V_33 >> V_160 ) & 1 ) ^ V_181 ;
}
return ( V_33 >> ( 12 + F_90 ( V_37 ) ) ) & 1 ;
}
if ( F_82 ( V_9 ) )
return ~ V_180 & 1 ;
return 0 ;
}
static T_3 F_91 ( struct V_8 * V_9 , T_2 V_132 ,
T_3 V_33 , bool V_182 ,
T_1 V_183 )
{
T_3 V_184 ;
T_3 V_62 = F_18 ( V_9 , V_132 ) ;
T_3 V_185 = F_35 ( V_9 ) ;
T_3 V_186 = ( V_9 -> V_174 & 0xFFFFFC00 ) << 16 ;
if ( V_182 ) {
if ( ( ! ( V_183 >> 16 ) ||
V_183 < F_34 ( V_9 ) ) &&
F_33 ( V_9 ) &&
( V_33 >= F_92 ( 32 ) ) )
V_184 = V_185 ;
else
V_184 = V_186 ;
} else {
if ( F_33 ( V_9 ) && ( V_33 >= F_92 ( 32 ) ) )
V_184 = V_185 ;
else
V_184 = V_62 ;
}
return ( V_33 & F_27 ( 47 , 6 ) ) - ( V_184 & F_27 ( 47 , 23 ) ) ;
}
static int F_93 ( struct V_8 * V_9 , T_2 V_10 , int V_43 )
{
int V_187 ;
if ( F_94 ( V_9 , V_10 ) &&
V_43 == F_95 ( V_9 , V_10 ) ) {
F_29 (tmp_cs, dct, pvt) {
if ( F_96 ( V_187 , V_10 , V_9 ) & 0x2 ) {
V_43 = V_187 ;
break;
}
}
}
return V_43 ;
}
static int F_97 ( T_3 V_188 , T_2 V_34 , T_2 V_10 )
{
struct V_26 * V_27 ;
struct V_8 * V_9 ;
T_3 V_189 , V_190 ;
int V_191 = - V_16 ;
int V_43 ;
V_27 = V_123 [ V_34 ] ;
if ( ! V_27 )
return V_191 ;
V_9 = V_27 -> V_29 ;
F_25 ( 1 , L_59 , V_188 , V_10 ) ;
F_29 (csrow, dct, pvt) {
if ( ! F_30 ( V_43 , V_10 , V_9 ) )
continue;
F_26 ( V_9 , V_43 , V_10 , & V_189 , & V_190 ) ;
F_25 ( 1 , L_60 ,
V_43 , V_189 , V_190 ) ;
V_190 = ~ V_190 ;
F_25 ( 1 , L_61 ,
( V_188 & V_190 ) , ( V_189 & V_190 ) ) ;
if ( ( V_188 & V_190 ) == ( V_189 & V_190 ) ) {
if ( V_9 -> V_15 == 0x15 && V_9 -> V_14 >= 0x30 ) {
V_191 = V_43 ;
break;
}
V_191 = F_93 ( V_9 , V_10 , V_43 ) ;
F_25 ( 1 , L_62 , V_191 ) ;
break;
}
}
return V_191 ;
}
static T_3 F_98 ( struct V_8 * V_9 , T_3 V_33 )
{
T_1 V_192 , V_193 , V_194 , V_195 , V_119 ;
if ( V_9 -> V_15 == 0x10 ) {
if ( V_9 -> V_14 < 4 || ( V_9 -> V_14 < 0xa && V_9 -> V_196 < 3 ) )
return V_33 ;
}
F_8 ( V_9 -> V_17 , V_197 , & V_192 ) ;
if ( ! ( V_192 & 0x1 ) )
return V_33 ;
V_193 = ( V_192 >> 3 ) & 0x7f ;
V_194 = ( V_192 >> 11 ) & 0x7f ;
V_195 = ( V_192 >> 20 ) & 0x7f ;
V_119 = V_33 >> 27 ;
if ( ! ( V_33 >> 34 ) &&
( ( ( V_119 >= V_193 ) &&
( V_119 <= V_194 ) ) ||
( V_119 < V_195 ) ) )
return V_33 ^ ( T_3 ) V_193 << 27 ;
return V_33 ;
}
static int F_99 ( struct V_8 * V_9 , unsigned V_132 ,
T_3 V_33 , int * V_198 )
{
int V_191 = - V_16 ;
T_3 V_199 ;
T_1 V_200 ;
T_2 V_156 ;
bool V_201 = false ;
T_2 V_36 = F_66 ( V_9 , V_132 ) ;
T_2 V_37 = F_21 ( V_9 , V_132 ) ;
T_1 V_202 = F_23 ( V_9 , V_132 ) ;
F_25 ( 1 , L_63 ,
V_132 , V_33 , F_19 ( V_9 , V_132 ) ) ;
if ( F_33 ( V_9 ) &&
F_34 ( V_9 ) <= V_33 &&
V_33 < F_92 ( 32 ) ) {
F_3 ( L_64 ,
V_33 ) ;
return - V_16 ;
}
if ( V_37 && ( V_202 != ( ( V_33 >> 12 ) & V_37 ) ) )
return - V_16 ;
V_33 = F_98 ( V_9 , V_33 ) ;
V_200 = F_81 ( V_9 ) ;
if ( F_82 ( V_9 ) &&
! F_11 ( V_9 ) &&
( ( V_33 >> 27 ) >= ( V_200 >> 11 ) ) )
V_201 = true ;
V_156 = F_88 ( V_9 , V_33 , V_201 , V_37 ) ;
V_199 = F_91 ( V_9 , V_132 , V_33 ,
V_201 , V_200 ) ;
if ( V_37 )
V_199 = ( ( V_199 >> ( 12 + F_90 ( V_37 ) ) ) << 12 ) |
( V_199 & 0xfff ) ;
if ( F_85 ( V_9 ) &&
! F_82 ( V_9 ) &&
! F_11 ( V_9 ) ) {
if ( F_86 ( V_9 ) != 1 ) {
if ( F_86 ( V_9 ) == 0x3 )
V_199 = ( ( V_199 >> 10 ) << 9 ) |
( V_199 & 0x1ff ) ;
else
V_199 = ( ( V_199 >> 7 ) << 6 ) |
( V_199 & 0x3f ) ;
} else
V_199 = ( ( V_199 >> 13 ) << 12 ) |
( V_199 & 0xfff ) ;
}
F_25 ( 1 , L_65 , V_199 ) ;
V_191 = F_97 ( V_199 , V_36 , V_156 ) ;
if ( V_191 >= 0 )
* V_198 = V_156 ;
return V_191 ;
}
static int F_100 ( struct V_8 * V_9 , unsigned V_132 ,
T_3 V_33 , int * V_198 )
{
int V_191 = - V_16 ;
int V_175 = 0 ;
T_3 V_199 , V_203 ;
T_3 V_204 , V_205 ;
T_1 V_206 , V_207 , V_120 ;
T_2 V_156 , V_208 , V_209 , V_176 , V_210 ;
T_3 V_211 = F_35 ( V_9 ) ;
T_2 V_178 = F_86 ( V_9 ) ;
T_2 V_36 = F_66 ( V_9 , V_132 ) ;
T_2 V_37 = F_21 ( V_9 , V_132 ) ;
F_8 ( V_9 -> V_12 , V_212 , & V_206 ) ;
F_8 ( V_9 -> V_12 , V_213 , & V_207 ) ;
V_210 = ( T_2 ) ( ( V_206 >> 3 ) & F_46 ( 0 ) ) ;
V_176 = ( T_2 ) ( ( V_206 >> 4 ) & 0x7 ) ;
F_25 ( 1 , L_63 ,
V_132 , V_33 , F_19 ( V_9 , V_132 ) ) ;
if ( ! ( F_18 ( V_9 , V_132 ) <= V_33 ) &&
! ( F_19 ( V_9 , V_132 ) >= V_33 ) )
return - V_16 ;
if ( F_33 ( V_9 ) &&
F_34 ( V_9 ) <= V_33 &&
V_33 < F_92 ( 32 ) ) {
F_3 ( L_64 ,
V_33 ) ;
return - V_16 ;
}
V_204 = ( T_3 ) F_81 ( V_9 ) ;
V_205 = ( V_207 >> 11 ) & 0x1FFF ;
if ( ! ( V_206 & F_46 ( 0 ) ) &&
! ( V_204 <= ( V_33 >> 27 ) &&
V_205 >= ( V_33 >> 27 ) ) )
return - V_16 ;
V_175 = ( int ) F_90 ( V_37 ) ;
if ( ! ( V_175 % 2 == 0 ) || ( V_175 > 4 ) )
return - V_16 ;
V_156 = F_87 ( V_9 , V_33 , V_37 ,
V_175 , V_176 ) ;
if ( V_156 > 3 )
return - V_16 ;
V_209 = ( T_2 ) ( V_206 >> 1 & F_46 ( 0 ) ) ;
if ( V_209 && ( V_33 >= F_92 ( 32 ) ) )
V_203 = V_211 ;
else
V_203 = V_204 << 27 ;
V_199 = V_33 - V_203 ;
if ( V_175 == 2 ) {
if ( V_178 == 0x4 )
V_199 = ( ( V_199 >> 9 ) << 8 ) |
( V_199 & 0xff ) ;
else if ( V_178 == 0x5 )
V_199 = ( ( V_199 >> 10 ) << 9 ) |
( V_199 & 0x1ff ) ;
else
return - V_16 ;
} else if ( V_175 == 4 ) {
if ( V_178 == 0x4 )
V_199 = ( ( V_199 >> 10 ) << 8 ) |
( V_199 & 0xff ) ;
else if ( V_178 == 0x5 )
V_199 = ( ( V_199 >> 11 ) << 9 ) |
( V_199 & 0x1ff ) ;
else
return - V_16 ;
}
if ( V_210 ) {
F_8 ( V_9 -> V_12 ,
V_214 + ( int ) V_156 * 4 ,
& V_120 ) ;
V_199 += ( T_3 ) ( ( V_120 >> 11 ) & 0xfff ) << 27 ;
}
F_7 ( V_9 , V_156 ) ;
F_25 ( 1 , L_65 , V_199 ) ;
V_208 = ( V_156 == 3 ) ? 1 : V_156 ;
V_191 = F_97 ( V_199 , V_36 , V_208 ) ;
if ( V_191 >= 0 )
* V_198 = V_208 ;
return V_191 ;
}
static int F_101 ( struct V_8 * V_9 ,
T_3 V_33 ,
int * V_198 )
{
int V_191 = - V_16 ;
unsigned V_132 ;
for ( V_132 = 0 ; V_132 < V_39 ; V_132 ++ ) {
if ( ! F_64 ( V_9 , V_132 ) )
continue;
if ( V_9 -> V_15 == 0x15 && V_9 -> V_14 >= 0x30 )
V_191 = F_100 ( V_9 , V_132 ,
V_33 ,
V_198 ) ;
else if ( ( F_18 ( V_9 , V_132 ) <= V_33 ) &&
( F_19 ( V_9 , V_132 ) >= V_33 ) ) {
V_191 = F_99 ( V_9 , V_132 ,
V_33 , V_198 ) ;
if ( V_191 >= 0 )
break;
}
}
return V_191 ;
}
static void F_102 ( struct V_26 * V_27 , T_3 V_33 ,
struct V_69 * V_6 )
{
struct V_8 * V_9 = V_27 -> V_29 ;
F_42 ( V_33 , V_6 ) ;
V_6 -> V_43 = F_101 ( V_9 , V_33 , & V_6 -> V_156 ) ;
if ( V_6 -> V_43 < 0 ) {
V_6 -> V_151 = V_153 ;
return;
}
if ( F_11 ( V_9 ) )
V_6 -> V_156 = F_70 ( V_27 , V_6 -> V_157 ) ;
}
static void F_49 ( struct V_8 * V_9 , T_2 V_215 )
{
int V_216 , V_217 , V_218 ;
T_1 * V_219 = V_215 ? V_9 -> V_53 [ 1 ] . V_54 : V_9 -> V_53 [ 0 ] . V_54 ;
T_1 V_166 = V_215 ? V_9 -> V_167 : V_9 -> V_168 ;
if ( V_9 -> V_15 == 0xf ) {
if ( V_9 -> V_51 < V_52 )
return;
else
F_67 ( V_215 != 0 ) ;
}
if ( V_9 -> V_15 == 0x10 ) {
V_166 = ( V_215 && ! F_11 ( V_9 ) ) ? V_9 -> V_167
: V_9 -> V_168 ;
V_219 = ( V_215 && ! F_11 ( V_9 ) ) ?
V_9 -> V_53 [ 1 ] . V_54 :
V_9 -> V_53 [ 0 ] . V_54 ;
} else if ( V_215 ) {
V_166 = V_9 -> V_168 ;
V_219 = V_9 -> V_53 [ 1 ] . V_54 ;
}
F_25 ( 1 , L_66 ,
V_215 , V_166 ) ;
F_103 ( V_220 , V_221 , L_67 , V_215 ) ;
for ( V_216 = 0 ; V_216 < 4 ; V_216 ++ ) {
V_217 = 0 ;
if ( V_219 [ V_216 * 2 ] & V_222 )
V_217 = V_9 -> V_223 -> V_224 ( V_9 , V_215 ,
F_75 ( V_216 , V_166 ) ) ;
V_218 = 0 ;
if ( V_219 [ V_216 * 2 + 1 ] & V_222 )
V_218 = V_9 -> V_223 -> V_224 ( V_9 , V_215 ,
F_75 ( V_216 , V_166 ) ) ;
F_50 ( V_221 L_68 ,
V_216 * 2 , V_217 ,
V_216 * 2 + 1 , V_218 ) ;
}
}
static int F_104 ( T_4 V_157 , const T_4 * V_225 , unsigned V_226 ,
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
F_25 ( 0 , L_69 , V_157 ) ;
return - 1 ;
}
static int F_105 ( int V_228 , int V_233 )
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
F_106 ( 1 , V_234 L_70 ,
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
static int F_70 ( struct V_26 * V_27 , T_4 V_157 )
{
struct V_8 * V_9 = V_27 -> V_29 ;
int V_228 = - 1 ;
if ( V_9 -> V_86 == 8 )
V_228 = F_104 ( V_157 , V_235 ,
F_13 ( V_235 ) ,
V_9 -> V_86 ) ;
else if ( V_9 -> V_86 == 4 )
V_228 = F_104 ( V_157 , V_236 ,
F_13 ( V_236 ) ,
V_9 -> V_86 ) ;
else {
F_3 ( L_71 , V_9 -> V_86 ) ;
return V_228 ;
}
return F_105 ( V_228 , V_9 -> V_86 ) ;
}
static void F_107 ( struct V_26 * V_27 , struct V_69 * V_6 ,
T_2 V_237 )
{
enum V_238 V_239 ;
const char * string ;
if ( V_237 == 2 )
V_239 = V_240 ;
else if ( V_237 == 1 )
V_239 = V_241 ;
else {
F_106 ( 1 , L_72 ) ;
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
F_108 ( V_239 , V_27 , 1 ,
V_6 -> V_70 , V_6 -> V_3 , V_6 -> V_157 ,
V_6 -> V_43 , V_6 -> V_156 , - 1 ,
string , L_22 ) ;
}
static inline void F_109 ( int V_36 , struct V_114 * V_115 )
{
struct V_26 * V_27 = V_123 [ V_36 ] ;
struct V_8 * V_9 = V_27 -> V_29 ;
T_2 V_237 = ( V_115 -> V_243 >> 45 ) & 0x3 ;
T_2 V_244 = F_110 ( V_115 -> V_243 , 0x1f ) ;
T_4 V_245 = F_111 ( V_115 -> V_243 ) ;
T_3 V_33 ;
struct V_69 V_6 ;
if ( F_112 ( V_245 ) == V_246 )
return;
if ( V_244 && V_244 != V_247 )
return;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_33 = F_56 ( V_9 , V_115 ) ;
if ( V_237 == 2 )
V_6 . V_157 = F_113 ( V_115 -> V_243 ) ;
V_9 -> V_223 -> V_248 ( V_27 , V_33 , & V_6 ) ;
F_107 ( V_27 , & V_6 , V_237 ) ;
}
static int F_114 ( struct V_8 * V_9 , T_4 V_249 , T_4 V_250 )
{
V_9 -> V_12 = F_59 ( V_9 -> V_17 -> V_126 , V_249 , V_9 -> V_17 ) ;
if ( ! V_9 -> V_12 ) {
F_115 ( L_77
L_78 ,
V_251 , V_249 ) ;
return - V_252 ;
}
V_9 -> V_31 = F_59 ( V_9 -> V_17 -> V_126 , V_250 , V_9 -> V_17 ) ;
if ( ! V_9 -> V_31 ) {
F_68 ( V_9 -> V_12 ) ;
V_9 -> V_12 = NULL ;
F_115 ( L_79
L_78 ,
V_251 , V_250 ) ;
return - V_252 ;
}
F_25 ( 1 , L_80 , F_116 ( V_9 -> V_12 ) ) ;
F_25 ( 1 , L_81 , F_116 ( V_9 -> V_17 ) ) ;
F_25 ( 1 , L_82 , F_116 ( V_9 -> V_31 ) ) ;
return 0 ;
}
static void F_117 ( struct V_8 * V_9 )
{
F_68 ( V_9 -> V_12 ) ;
F_68 ( V_9 -> V_31 ) ;
}
static void F_118 ( struct V_8 * V_9 )
{
unsigned V_132 ;
T_3 V_253 ;
T_1 V_120 ;
F_119 ( V_254 , V_9 -> V_255 ) ;
F_25 ( 0 , L_83 , V_9 -> V_255 ) ;
F_119 ( V_256 , V_253 ) ;
if ( V_253 & ( 1U << 21 ) ) {
F_119 ( V_257 , V_9 -> V_258 ) ;
F_25 ( 0 , L_84 , V_9 -> V_258 ) ;
} else
F_25 ( 0 , L_85 ) ;
F_8 ( V_9 -> V_31 , V_259 , & V_9 -> V_80 ) ;
F_80 ( V_9 ) ;
for ( V_132 = 0 ; V_132 < V_39 ; V_132 ++ ) {
T_2 V_260 ;
F_63 ( V_9 , V_132 ) ;
V_260 = F_64 ( V_9 , V_132 ) ;
if ( ! V_260 )
continue;
F_25 ( 1 , L_86 ,
V_132 ,
F_18 ( V_9 , V_132 ) ,
F_19 ( V_9 , V_132 ) ) ;
F_25 ( 1 , L_87 ,
F_21 ( V_9 , V_132 ) ? L_88 : L_89 ,
( V_260 & 0x1 ) ? L_90 : L_91 ,
( V_260 & 0x2 ) ? L_92 : L_91 ,
F_23 ( V_9 , V_132 ) ,
F_66 ( V_9 , V_132 ) ) ;
}
F_52 ( V_9 ) ;
F_8 ( V_9 -> V_12 , V_261 , & V_9 -> V_85 ) ;
F_10 ( V_9 , 0 , V_262 , & V_9 -> V_168 ) ;
F_8 ( V_9 -> V_31 , V_263 , & V_9 -> V_84 ) ;
F_10 ( V_9 , 0 , V_264 , & V_9 -> V_76 ) ;
F_10 ( V_9 , 0 , V_265 , & V_9 -> V_104 ) ;
if ( ! F_11 ( V_9 ) ) {
F_10 ( V_9 , 1 , V_264 , & V_9 -> V_87 ) ;
F_10 ( V_9 , 1 , V_265 , & V_9 -> V_170 ) ;
}
V_9 -> V_86 = 4 ;
if ( V_9 -> V_15 >= 0x10 ) {
F_8 ( V_9 -> V_31 , V_266 , & V_120 ) ;
if ( V_9 -> V_15 != 0x16 )
F_10 ( V_9 , 1 , V_262 , & V_9 -> V_167 ) ;
if ( ( V_9 -> V_15 > 0x10 || V_9 -> V_14 > 7 ) && V_120 & F_46 ( 25 ) )
V_9 -> V_86 = 8 ;
}
F_48 ( V_9 ) ;
}
static T_1 F_120 ( struct V_8 * V_9 , T_2 V_10 , int V_267 )
{
T_1 V_161 , V_268 ;
T_1 V_166 = V_10 ? V_9 -> V_167 : V_9 -> V_168 ;
V_161 = F_75 ( V_267 / 2 , V_166 ) ;
V_268 = V_9 -> V_223 -> V_224 ( V_9 , V_10 , V_161 ) << ( 20 - V_71 ) ;
F_25 ( 0 , L_93 ,
V_267 , V_10 , V_161 ) ;
F_25 ( 0 , L_94 , V_268 ) ;
return V_268 ;
}
static int F_121 ( struct V_26 * V_27 )
{
struct V_8 * V_9 = V_27 -> V_29 ;
struct V_269 * V_43 ;
struct V_270 * V_216 ;
enum V_271 V_272 ;
enum V_101 V_273 ;
int V_22 , V_164 , V_274 = 1 ;
int V_268 = 0 ;
T_1 V_4 ;
F_8 ( V_9 -> V_31 , V_275 , & V_4 ) ;
V_9 -> V_154 = V_4 ;
F_25 ( 0 , L_95 ,
V_9 -> V_57 , V_4 ,
! ! ( V_4 & V_155 ) , ! ! ( V_4 & V_276 ) ) ;
F_29 (i, 0 , pvt) {
bool V_277 = ! ! F_30 ( V_22 , 0 , V_9 ) ;
bool V_278 = false ;
if ( V_9 -> V_15 != 0xf )
V_278 = ! ! F_30 ( V_22 , 1 , V_9 ) ;
if ( ! V_277 && ! V_278 )
continue;
V_43 = V_27 -> V_279 [ V_22 ] ;
V_274 = 0 ;
F_25 ( 1 , L_96 ,
V_9 -> V_57 , V_22 ) ;
if ( V_277 ) {
V_268 = F_120 ( V_9 , 0 , V_22 ) ;
V_43 -> V_165 [ 0 ] -> V_216 -> V_268 = V_268 ;
}
if ( V_9 -> V_15 != 0xf && V_278 ) {
int V_280 = F_120 ( V_9 , 1 , V_22 ) ;
V_43 -> V_165 [ 1 ] -> V_216 -> V_268 = V_280 ;
V_268 += V_280 ;
}
V_273 = F_54 ( V_9 , V_22 ) ;
F_25 ( 1 , L_97 , V_22 , V_268 ) ;
if ( V_9 -> V_154 & V_276 )
V_272 = ( V_9 -> V_154 & V_155 ) ?
V_281 : V_282 ;
else
V_272 = V_283 ;
for ( V_164 = 0 ; V_164 < V_9 -> V_284 ; V_164 ++ ) {
V_216 = V_43 -> V_165 [ V_164 ] -> V_216 ;
V_216 -> V_273 = V_273 ;
V_216 -> V_272 = V_272 ;
}
}
return V_274 ;
}
static void F_122 ( struct V_285 * V_45 , T_4 V_34 )
{
int V_286 ;
F_123 (cpu)
if ( F_57 ( V_286 ) == V_34 )
F_124 ( V_286 , V_45 ) ;
}
static bool F_125 ( T_4 V_34 )
{
T_5 V_45 ;
int V_286 , V_287 ;
bool V_64 = false ;
if ( ! F_126 ( & V_45 , V_288 ) ) {
F_3 ( L_98 , V_42 ) ;
return false ;
}
F_122 ( V_45 , V_34 ) ;
F_127 ( V_45 , V_289 , V_290 ) ;
F_128 (cpu, mask) {
struct V_291 * V_11 = F_129 ( V_290 , V_286 ) ;
V_287 = V_11 -> V_292 & V_293 ;
F_25 ( 0 , L_99 ,
V_286 , V_11 -> V_294 ,
( V_287 ? L_26 : L_27 ) ) ;
if ( ! V_287 )
goto V_295;
}
V_64 = true ;
V_295:
F_130 ( V_45 ) ;
return V_64 ;
}
static int F_131 ( struct V_296 * V_229 , T_4 V_34 , bool V_297 )
{
T_5 V_298 ;
int V_286 ;
if ( ! F_126 ( & V_298 , V_288 ) ) {
F_3 ( L_100 , V_42 ) ;
return false ;
}
F_122 ( V_298 , V_34 ) ;
F_127 ( V_298 , V_289 , V_290 ) ;
F_128 (cpu, cmask) {
struct V_291 * V_11 = F_129 ( V_290 , V_286 ) ;
if ( V_297 ) {
if ( V_11 -> V_292 & V_293 )
V_229 -> V_299 . V_300 = 1 ;
V_11 -> V_292 |= V_293 ;
} else {
if ( ! V_229 -> V_299 . V_300 )
V_11 -> V_292 &= ~ V_293 ;
}
}
F_132 ( V_298 , V_289 , V_290 ) ;
F_130 ( V_298 ) ;
return 0 ;
}
static bool F_133 ( struct V_296 * V_229 , T_4 V_34 ,
struct V_1 * V_31 )
{
bool V_64 = true ;
T_1 V_301 , V_45 = 0x3 ;
if ( F_131 ( V_229 , V_34 , V_302 ) ) {
F_3 ( L_101 ) ;
return false ;
}
F_8 ( V_31 , V_303 , & V_301 ) ;
V_229 -> V_304 = V_301 & V_45 ;
V_229 -> V_305 = true ;
V_301 |= V_45 ;
F_9 ( V_31 , V_303 , V_301 ) ;
F_8 ( V_31 , V_275 , & V_301 ) ;
F_25 ( 0 , L_102 ,
V_34 , V_301 , ! ! ( V_301 & V_276 ) ) ;
if ( ! ( V_301 & V_276 ) ) {
F_3 ( L_103 ) ;
V_229 -> V_299 . V_306 = 0 ;
V_301 |= V_276 ;
F_9 ( V_31 , V_275 , V_301 ) ;
F_8 ( V_31 , V_275 , & V_301 ) ;
if ( ! ( V_301 & V_276 ) ) {
F_3 ( L_104
L_105 ) ;
V_64 = false ;
} else {
F_50 ( L_106 ) ;
}
} else {
V_229 -> V_299 . V_306 = 1 ;
}
F_25 ( 0 , L_107 ,
V_34 , V_301 , ! ! ( V_301 & V_276 ) ) ;
return V_64 ;
}
static void F_134 ( struct V_296 * V_229 , T_4 V_34 ,
struct V_1 * V_31 )
{
T_1 V_301 , V_45 = 0x3 ;
if ( ! V_229 -> V_305 )
return;
F_8 ( V_31 , V_303 , & V_301 ) ;
V_301 &= ~ V_45 ;
V_301 |= V_229 -> V_304 ;
F_9 ( V_31 , V_303 , V_301 ) ;
if ( ! V_229 -> V_299 . V_306 ) {
F_8 ( V_31 , V_275 , & V_301 ) ;
V_301 &= ~ V_276 ;
F_9 ( V_31 , V_275 , V_301 ) ;
}
if ( F_131 ( V_229 , V_34 , V_307 ) )
F_3 ( L_108 ) ;
}
static bool F_135 ( struct V_1 * V_31 , T_4 V_34 )
{
T_1 V_301 ;
T_2 V_308 = 0 ;
bool V_309 = false ;
F_8 ( V_31 , V_275 , & V_301 ) ;
V_308 = ! ! ( V_301 & V_276 ) ;
F_50 ( L_109 , ( V_308 ? L_26 : L_27 ) ) ;
V_309 = F_125 ( V_34 ) ;
if ( ! V_309 )
F_136 ( L_110
L_111 ,
V_289 , V_34 ) ;
if ( ! V_308 || ! V_309 ) {
F_136 ( L_112 , V_310 ) ;
return false ;
}
return true ;
}
static int F_137 ( struct V_26 * V_27 )
{
struct V_8 * V_9 = V_27 -> V_29 ;
int V_311 ;
V_311 = F_138 ( V_27 ) ;
if ( V_311 < 0 )
return V_311 ;
if ( V_9 -> V_15 >= 0x10 ) {
V_311 = F_139 ( V_27 ) ;
if ( V_311 < 0 )
return V_311 ;
}
return 0 ;
}
static void F_140 ( struct V_26 * V_27 )
{
struct V_8 * V_9 = V_27 -> V_29 ;
F_141 ( V_27 ) ;
if ( V_9 -> V_15 >= 0x10 )
F_142 ( V_27 ) ;
}
static void F_143 ( struct V_26 * V_27 ,
struct V_312 * V_15 )
{
struct V_8 * V_9 = V_27 -> V_29 ;
V_27 -> V_313 = V_314 | V_315 ;
V_27 -> V_316 = V_75 ;
if ( V_9 -> V_80 & V_82 )
V_27 -> V_316 |= V_77 ;
if ( V_9 -> V_80 & V_83 )
V_27 -> V_316 |= V_317 ;
V_27 -> V_74 = F_45 ( V_9 ) ;
V_27 -> V_318 = V_319 ;
V_27 -> V_320 = V_321 ;
V_27 -> V_322 = V_15 -> V_322 ;
V_27 -> V_323 = F_116 ( V_9 -> V_17 ) ;
V_27 -> V_324 = NULL ;
V_27 -> V_325 = F_15 ;
V_27 -> V_326 = F_16 ;
}
static struct V_312 * F_144 ( struct V_8 * V_9 )
{
struct V_312 * V_327 = NULL ;
V_9 -> V_51 = V_328 . V_329 >> 4 ;
V_9 -> V_196 = V_328 . V_330 ;
V_9 -> V_14 = V_328 . V_329 ;
V_9 -> V_15 = V_328 . V_331 ;
switch ( V_9 -> V_15 ) {
case 0xf :
V_327 = & V_332 [ V_333 ] ;
V_9 -> V_223 = & V_332 [ V_333 ] . V_223 ;
break;
case 0x10 :
V_327 = & V_332 [ V_334 ] ;
V_9 -> V_223 = & V_332 [ V_334 ] . V_223 ;
break;
case 0x15 :
if ( V_9 -> V_14 == 0x30 ) {
V_327 = & V_332 [ V_335 ] ;
V_9 -> V_223 = & V_332 [ V_335 ] . V_223 ;
break;
}
V_327 = & V_332 [ V_336 ] ;
V_9 -> V_223 = & V_332 [ V_336 ] . V_223 ;
break;
case 0x16 :
if ( V_9 -> V_14 == 0x30 ) {
V_327 = & V_332 [ V_337 ] ;
V_9 -> V_223 = & V_332 [ V_337 ] . V_223 ;
break;
}
V_327 = & V_332 [ V_338 ] ;
V_9 -> V_223 = & V_332 [ V_338 ] . V_223 ;
break;
default:
F_115 ( L_113 ) ;
return NULL ;
}
F_50 ( L_114 , V_327 -> V_322 ,
( V_9 -> V_15 == 0xf ?
( V_9 -> V_51 >= V_52 ? L_115
: L_116 )
: L_22 ) , V_9 -> V_57 ) ;
return V_327 ;
}
static int F_145 ( struct V_1 * V_17 )
{
struct V_8 * V_9 = NULL ;
struct V_312 * V_327 = NULL ;
struct V_26 * V_27 = NULL ;
struct V_339 V_340 [ 2 ] ;
int V_6 = 0 , V_64 ;
T_4 V_34 = F_146 ( V_17 ) ;
V_64 = - V_341 ;
V_9 = F_147 ( sizeof( struct V_8 ) , V_288 ) ;
if ( ! V_9 )
goto V_342;
V_9 -> V_57 = V_34 ;
V_9 -> V_17 = V_17 ;
V_64 = - V_16 ;
V_327 = F_144 ( V_9 ) ;
if ( ! V_327 )
goto V_343;
V_64 = - V_252 ;
V_6 = F_114 ( V_9 , V_327 -> V_249 , V_327 -> V_250 ) ;
if ( V_6 )
goto V_343;
F_118 ( V_9 ) ;
V_64 = - V_16 ;
V_9 -> V_284 = V_9 -> V_223 -> V_344 ( V_9 ) ;
if ( V_9 -> V_284 < 0 )
goto V_345;
V_64 = - V_341 ;
V_340 [ 0 ] . type = V_346 ;
V_340 [ 0 ] . V_347 = V_9 -> V_53 [ 0 ] . V_88 ;
V_340 [ 0 ] . V_348 = true ;
V_340 [ 1 ] . type = V_349 ;
V_340 [ 1 ] . V_347 = 2 ;
V_340 [ 1 ] . V_348 = false ;
V_27 = F_148 ( V_34 , F_13 ( V_340 ) , V_340 , 0 ) ;
if ( ! V_27 )
goto V_345;
V_27 -> V_29 = V_9 ;
V_27 -> V_2 = & V_9 -> V_17 -> V_129 ;
F_143 ( V_27 , V_327 ) ;
if ( F_121 ( V_27 ) )
V_27 -> V_74 = V_75 ;
V_64 = - V_252 ;
if ( F_149 ( V_27 ) ) {
F_25 ( 1 , L_117 ) ;
goto V_350;
}
if ( F_137 ( V_27 ) ) {
F_25 ( 1 , L_117 ) ;
goto V_351;
}
if ( V_352 )
F_150 ( true ) ;
F_151 ( F_109 ) ;
V_123 [ V_34 ] = V_27 ;
F_152 ( & V_353 ) ;
return 0 ;
V_351:
F_153 ( V_27 -> V_2 ) ;
V_350:
F_154 ( V_27 ) ;
V_345:
F_117 ( V_9 ) ;
V_343:
F_155 ( V_9 ) ;
V_342:
return V_64 ;
}
static int F_156 ( struct V_1 * V_2 ,
const struct V_354 * V_355 )
{
T_4 V_34 = F_146 ( V_2 ) ;
struct V_1 * V_31 = F_65 ( V_34 ) -> V_149 ;
struct V_296 * V_229 ;
int V_64 = 0 ;
V_64 = F_157 ( V_2 ) ;
if ( V_64 < 0 ) {
F_25 ( 0 , L_118 , V_64 ) ;
return - V_356 ;
}
V_64 = - V_341 ;
V_229 = F_147 ( sizeof( struct V_296 ) , V_288 ) ;
if ( ! V_229 )
goto V_357;
V_358 [ V_34 ] = V_229 ;
if ( ! F_135 ( V_31 , V_34 ) ) {
V_64 = - V_252 ;
if ( ! V_359 )
goto V_360;
F_3 ( L_119 ) ;
if ( ! F_133 ( V_229 , V_34 , V_31 ) )
goto V_360;
}
V_64 = F_145 ( V_2 ) ;
if ( V_64 < 0 ) {
F_115 ( L_120 , V_34 ) ;
F_134 ( V_229 , V_34 , V_31 ) ;
}
return V_64 ;
V_360:
F_155 ( V_229 ) ;
V_358 [ V_34 ] = NULL ;
V_357:
return V_64 ;
}
static void F_158 ( struct V_1 * V_2 )
{
struct V_26 * V_27 ;
struct V_8 * V_9 ;
T_4 V_34 = F_146 ( V_2 ) ;
struct V_1 * V_31 = F_65 ( V_34 ) -> V_149 ;
struct V_296 * V_229 = V_358 [ V_34 ] ;
V_27 = F_159 ( & V_2 -> V_129 ) ;
F_67 ( ! V_27 ) ;
F_140 ( V_27 ) ;
V_27 = F_153 ( & V_2 -> V_129 ) ;
if ( ! V_27 )
return;
V_9 = V_27 -> V_29 ;
F_134 ( V_229 , V_34 , V_31 ) ;
F_117 ( V_9 ) ;
F_150 ( false ) ;
F_160 ( F_109 ) ;
F_155 ( V_358 [ V_34 ] ) ;
V_358 [ V_34 ] = NULL ;
V_27 -> V_29 = NULL ;
V_123 [ V_34 ] = NULL ;
F_155 ( V_9 ) ;
F_154 ( V_27 ) ;
}
static void F_161 ( void )
{
struct V_26 * V_27 ;
struct V_8 * V_9 ;
if ( V_361 )
return;
V_27 = V_123 [ 0 ] ;
if ( ! V_27 )
return;
V_9 = V_27 -> V_29 ;
V_361 = F_162 ( & V_9 -> V_17 -> V_129 , V_319 ) ;
if ( ! V_361 ) {
F_163 ( L_121 , V_42 ) ;
F_163 ( L_122 , V_42 ) ;
}
}
static int T_6 F_164 ( void )
{
int V_6 = - V_252 ;
F_165 ( V_362 L_123 , V_321 ) ;
F_166 () ;
if ( F_167 () < 0 )
goto V_342;
V_6 = - V_341 ;
V_123 = F_147 ( F_168 () * sizeof( V_123 [ 0 ] ) , V_288 ) ;
V_358 = F_147 ( F_168 () * sizeof( V_358 [ 0 ] ) , V_288 ) ;
if ( ! ( V_123 && V_358 ) )
goto V_343;
V_290 = F_169 () ;
if ( ! V_290 )
goto V_343;
V_6 = F_170 ( & V_363 ) ;
if ( V_6 )
goto V_364;
V_6 = - V_252 ;
if ( ! F_171 ( & V_353 ) )
goto V_365;
F_161 () ;
return 0 ;
V_365:
F_172 ( & V_363 ) ;
V_364:
F_173 ( V_290 ) ;
V_290 = NULL ;
V_343:
F_155 ( V_123 ) ;
V_123 = NULL ;
F_155 ( V_358 ) ;
V_358 = NULL ;
V_342:
return V_6 ;
}
static void T_7 F_174 ( void )
{
if ( V_361 )
F_175 ( V_361 ) ;
F_172 ( & V_363 ) ;
F_155 ( V_358 ) ;
V_358 = NULL ;
F_155 ( V_123 ) ;
V_123 = NULL ;
F_173 ( V_290 ) ;
V_290 = NULL ;
}
