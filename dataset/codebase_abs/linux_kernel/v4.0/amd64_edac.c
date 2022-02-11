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
if ( V_9 -> V_80 == V_81 ) {
T_1 V_82 = V_9 -> V_53 [ V_79 ] . V_55 [ 0 ] ;
F_25 ( 1 , L_20 , ( V_82 & 0x3 ) ) ;
}
F_25 ( 1 , L_21 ,
( V_78 & F_46 ( 19 ) ) ? L_22 : L_23 ) ;
F_25 ( 1 , L_24 ,
( V_78 & F_46 ( 8 ) ) ? L_25 : L_26 ) ;
if ( V_9 -> V_15 == 0x10 )
F_25 ( 1 , L_27 ,
( V_78 & F_46 ( 11 ) ) ? L_28 : L_29 ) ;
F_25 ( 1 , L_30 ,
( V_78 & F_46 ( 12 ) ) ? L_22 : L_23 ,
( V_78 & F_46 ( 13 ) ) ? L_22 : L_23 ,
( V_78 & F_46 ( 14 ) ) ? L_22 : L_23 ,
( V_78 & F_46 ( 15 ) ) ? L_22 : L_23 ) ;
}
static void F_48 ( struct V_8 * V_9 )
{
F_25 ( 1 , L_31 , V_9 -> V_83 ) ;
F_25 ( 1 , L_32 ,
( V_9 -> V_83 & V_84 ) ? L_22 : L_23 ) ;
F_25 ( 1 , L_33 ,
( V_9 -> V_83 & V_85 ) ? L_22 : L_23 ,
( V_9 -> V_83 & V_86 ) ? L_22 : L_23 ) ;
F_47 ( V_9 , V_9 -> V_76 , 0 ) ;
F_25 ( 1 , L_34 , V_9 -> V_87 ) ;
F_25 ( 1 , L_35 ,
V_9 -> V_88 , F_34 ( V_9 ) ,
( V_9 -> V_15 == 0xf ) ? F_36 ( V_9 )
: F_35 ( V_9 ) ) ;
F_25 ( 1 , L_36 , F_33 ( V_9 ) ? L_22 : L_23 ) ;
F_49 ( V_9 , 0 ) ;
if ( V_9 -> V_15 == 0xf )
return;
F_49 ( V_9 , 1 ) ;
F_50 ( L_37 , ( ( V_9 -> V_89 == 8 ) ? L_38 : L_39 ) ) ;
if ( ! F_11 ( V_9 ) )
F_47 ( V_9 , V_9 -> V_90 , 1 ) ;
}
static void F_51 ( struct V_8 * V_9 )
{
if ( V_9 -> V_15 == 0xf && V_9 -> V_51 < V_52 ) {
V_9 -> V_53 [ 0 ] . V_91 = V_9 -> V_53 [ 1 ] . V_91 = 8 ;
V_9 -> V_53 [ 0 ] . V_92 = V_9 -> V_53 [ 1 ] . V_92 = 8 ;
} else if ( V_9 -> V_15 == 0x15 && V_9 -> V_14 == 0x30 ) {
V_9 -> V_53 [ 0 ] . V_91 = V_9 -> V_53 [ 1 ] . V_91 = 4 ;
V_9 -> V_53 [ 0 ] . V_92 = V_9 -> V_53 [ 1 ] . V_92 = 2 ;
} else {
V_9 -> V_53 [ 0 ] . V_91 = V_9 -> V_53 [ 1 ] . V_91 = 8 ;
V_9 -> V_53 [ 0 ] . V_92 = V_9 -> V_53 [ 1 ] . V_92 = 4 ;
}
}
static void F_52 ( struct V_8 * V_9 )
{
int V_93 ;
F_51 ( V_9 ) ;
F_29 (cs, 0 , pvt) {
int V_94 = V_95 + ( V_93 * 4 ) ;
int V_96 = V_97 + ( V_93 * 4 ) ;
T_1 * V_98 = & V_9 -> V_53 [ 0 ] . V_54 [ V_93 ] ;
T_1 * V_99 = & V_9 -> V_53 [ 1 ] . V_54 [ V_93 ] ;
if ( ! F_10 ( V_9 , 0 , V_94 , V_98 ) )
F_25 ( 0 , L_40 ,
V_93 , * V_98 , V_94 ) ;
if ( V_9 -> V_15 == 0xf )
continue;
if ( ! F_10 ( V_9 , 1 , V_94 , V_99 ) )
F_25 ( 0 , L_41 ,
V_93 , * V_99 , ( V_9 -> V_15 == 0x10 ) ? V_96
: V_94 ) ;
}
F_53 (cs, 0 , pvt) {
int V_94 = V_100 + ( V_93 * 4 ) ;
int V_96 = V_101 + ( V_93 * 4 ) ;
T_1 * V_102 = & V_9 -> V_53 [ 0 ] . V_55 [ V_93 ] ;
T_1 * V_103 = & V_9 -> V_53 [ 1 ] . V_55 [ V_93 ] ;
if ( ! F_10 ( V_9 , 0 , V_94 , V_102 ) )
F_25 ( 0 , L_42 ,
V_93 , * V_102 , V_94 ) ;
if ( V_9 -> V_15 == 0xf )
continue;
if ( ! F_10 ( V_9 , 1 , V_94 , V_103 ) )
F_25 ( 0 , L_43 ,
V_93 , * V_103 , ( V_9 -> V_15 == 0x10 ) ? V_96
: V_94 ) ;
}
}
static void F_54 ( struct V_8 * V_9 )
{
T_1 V_104 , V_82 ;
switch ( V_9 -> V_15 ) {
case 0xf :
if ( V_9 -> V_51 >= V_52 )
goto V_105;
V_9 -> V_80 = ( V_9 -> V_76 & F_46 ( 18 ) ) ? V_106 : V_107 ;
return;
case 0x10 :
if ( V_9 -> V_108 & V_109 )
goto V_105;
V_9 -> V_80 = ( V_9 -> V_76 & F_46 ( 16 ) ) ? V_110 : V_111 ;
return;
case 0x15 :
if ( V_9 -> V_14 < 0x60 )
goto V_105;
F_10 ( V_9 , 0 , V_112 , & V_104 ) ;
V_82 = V_9 -> V_53 [ 0 ] . V_55 [ 0 ] ;
if ( ( ( V_104 >> 8 ) & 0x7 ) == 0x2 )
V_9 -> V_80 = V_113 ;
else if ( V_9 -> V_76 & F_46 ( 16 ) )
V_9 -> V_80 = V_114 ;
else if ( V_82 & 0x3 )
V_9 -> V_80 = V_81 ;
else
V_9 -> V_80 = V_115 ;
return;
case 0x16 :
goto V_105;
default:
F_55 ( 1 , V_116 L_44 , V_42 , V_9 -> V_15 ) ;
V_9 -> V_80 = V_117 ;
}
return;
V_105:
V_9 -> V_80 = ( V_9 -> V_76 & F_46 ( 16 ) ) ? V_114 : V_115 ;
}
static int F_56 ( struct V_8 * V_9 )
{
int V_118 ;
if ( V_9 -> V_51 >= V_52 )
V_118 = V_9 -> V_76 & V_119 ;
else
V_118 = V_9 -> V_76 & V_120 ;
V_9 -> V_90 = 0 ;
return ( V_118 ) ? 2 : 1 ;
}
static T_3 F_57 ( struct V_8 * V_9 , struct V_121 * V_122 )
{
T_3 V_35 ;
T_2 V_123 = 1 ;
T_2 V_124 = 47 ;
if ( V_9 -> V_15 == 0xf ) {
V_123 = 3 ;
V_124 = 39 ;
}
V_35 = V_122 -> V_35 & F_27 ( V_124 , V_123 ) ;
if ( V_9 -> V_15 == 0x15 ) {
struct V_8 * V_9 ;
T_3 V_125 , V_126 ;
T_1 V_127 ;
T_4 V_128 ;
T_2 V_37 ;
if ( ( V_35 & F_27 ( 47 , 24 ) ) >> 24 != 0x00fdf7 )
return V_35 ;
V_128 = F_58 ( V_122 -> V_129 ) ;
V_9 = V_130 [ V_128 ] -> V_29 ;
F_8 ( V_9 -> V_12 , V_131 , & V_127 ) ;
V_37 = V_127 >> 21 & 0x7 ;
V_125 = ( V_127 & F_27 ( 20 , 0 ) ) << 3 ;
V_125 |= V_37 ^ 0x7 ;
V_125 <<= 24 ;
if ( ! V_37 )
return V_125 | ( V_35 & F_27 ( 23 , 0 ) ) ;
F_8 ( V_9 -> V_12 , V_132 , & V_127 ) ;
V_126 = ( V_35 & F_27 ( 23 , 12 ) ) << F_59 ( V_37 + 1 ) ;
V_126 |= ( V_127 & F_27 ( 23 , 21 ) ) >> 9 ;
V_126 |= V_35 & F_27 ( 11 , 0 ) ;
return V_125 | V_126 ;
}
return V_35 ;
}
static struct V_1 * F_60 ( unsigned int V_133 ,
unsigned int V_134 ,
struct V_1 * V_135 )
{
struct V_1 * V_136 = NULL ;
while ( ( V_136 = F_61 ( V_133 , V_134 , V_136 ) ) ) {
if ( F_62 ( V_136 -> V_137 ) == F_62 ( V_135 -> V_137 ) &&
( V_136 -> V_137 -> V_138 == V_135 -> V_137 -> V_138 ) &&
( F_63 ( V_136 -> V_7 ) == F_63 ( V_135 -> V_7 ) ) )
break;
}
return V_136 ;
}
static void F_64 ( struct V_8 * V_9 , unsigned V_139 )
{
struct V_140 * V_141 ;
struct V_1 * V_142 = NULL ;
unsigned int V_143 ;
int V_144 = V_139 << 3 ;
T_1 V_145 ;
F_8 ( V_9 -> V_12 , V_146 + V_144 , & V_9 -> V_147 [ V_139 ] . V_44 . V_148 ) ;
F_8 ( V_9 -> V_12 , V_149 + V_144 , & V_9 -> V_147 [ V_139 ] . V_150 . V_148 ) ;
if ( V_9 -> V_15 == 0xf )
return;
if ( ! F_65 ( V_9 , V_139 ) )
return;
F_8 ( V_9 -> V_12 , V_151 + V_144 , & V_9 -> V_147 [ V_139 ] . V_44 . V_152 ) ;
F_8 ( V_9 -> V_12 , V_153 + V_144 , & V_9 -> V_147 [ V_139 ] . V_150 . V_152 ) ;
if ( V_9 -> V_15 != 0x15 )
return;
V_141 = F_66 ( F_67 ( V_9 , V_139 ) ) ;
if ( F_68 ( ! V_141 ) )
return;
if ( V_9 -> V_14 == 0x60 )
V_143 = V_154 ;
else if ( V_9 -> V_14 == 0x30 )
V_143 = V_155 ;
else
V_143 = V_156 ;
V_142 = F_60 ( V_141 -> V_157 -> V_133 , V_143 , V_141 -> V_157 ) ;
if ( F_68 ( ! V_142 ) )
return;
F_8 ( V_142 , V_131 , & V_145 ) ;
V_9 -> V_147 [ V_139 ] . V_150 . V_148 &= F_27 ( 15 , 0 ) ;
V_9 -> V_147 [ V_139 ] . V_150 . V_148 |= ( ( V_145 & 0x1fff ) << 3 | 0x7 ) << 16 ;
V_9 -> V_147 [ V_139 ] . V_150 . V_152 &= F_27 ( 7 , 0 ) ;
V_9 -> V_147 [ V_139 ] . V_150 . V_152 |= V_145 >> 13 ;
F_69 ( V_142 ) ;
}
static void F_70 ( struct V_26 * V_27 , T_3 V_33 ,
struct V_69 * V_6 )
{
struct V_8 * V_9 = V_27 -> V_29 ;
F_42 ( V_33 , V_6 ) ;
V_6 -> V_158 = F_20 ( V_27 , V_33 ) ;
if ( ! V_6 -> V_158 ) {
F_44 ( V_27 , L_45 ,
( unsigned long ) V_33 ) ;
V_6 -> V_159 = V_160 ;
return;
}
V_6 -> V_43 = F_43 ( V_6 -> V_158 , V_33 ) ;
if ( V_6 -> V_43 < 0 ) {
V_6 -> V_159 = V_161 ;
return;
}
if ( V_9 -> V_162 & V_163 ) {
V_6 -> V_164 = F_71 ( V_27 , V_6 -> V_165 ) ;
if ( V_6 -> V_164 < 0 ) {
F_72 ( V_6 -> V_158 , L_46
L_47 ,
V_6 -> V_165 ) ;
V_6 -> V_159 = V_166 ;
return;
}
} else {
V_6 -> V_164 = ( ( V_33 & F_46 ( 3 ) ) != 0 ) ;
}
}
static int F_73 ( unsigned V_22 , bool V_167 )
{
unsigned V_168 = 0 ;
if ( V_22 <= 2 )
V_168 = V_22 ;
else if ( ! ( V_22 & 0x1 ) )
V_168 = V_22 >> 1 ;
else
V_168 = ( V_22 + 1 ) >> 1 ;
return 128 << ( V_168 + ! ! V_167 ) ;
}
static int F_74 ( struct V_8 * V_9 , T_2 V_10 ,
unsigned V_169 , int V_170 )
{
T_1 V_78 = V_10 ? V_9 -> V_90 : V_9 -> V_76 ;
if ( V_9 -> V_51 >= V_52 ) {
F_68 ( V_169 > 11 ) ;
return F_73 ( V_169 , V_78 & V_119 ) ;
}
else if ( V_9 -> V_51 >= V_171 ) {
unsigned V_172 ;
F_68 ( V_169 > 10 ) ;
V_172 = V_169 / 3 + ( unsigned ) ( V_169 > 5 ) ;
return 32 << ( V_169 - V_172 ) ;
}
else {
F_68 ( V_169 > 6 ) ;
return 32 << V_169 ;
}
}
static int F_75 ( struct V_8 * V_9 )
{
int V_22 , V_173 , V_174 = 0 ;
if ( V_9 -> V_15 == 0x10 && ( V_9 -> V_76 & V_119 ) )
return 2 ;
F_25 ( 0 , L_48 ) ;
for ( V_22 = 0 ; V_22 < 2 ; V_22 ++ ) {
T_1 V_175 = ( V_22 ? V_9 -> V_176 : V_9 -> V_177 ) ;
for ( V_173 = 0 ; V_173 < 4 ; V_173 ++ ) {
if ( F_76 ( V_173 , V_175 ) > 0 ) {
V_174 ++ ;
break;
}
}
}
if ( V_174 > 2 )
V_174 = 2 ;
F_50 ( L_49 , V_174 ) ;
return V_174 ;
}
static int F_77 ( unsigned V_22 , bool V_167 )
{
unsigned V_168 = 0 ;
int V_178 = 0 ;
if ( V_22 == 0 || V_22 == 3 || V_22 == 4 )
V_178 = - 1 ;
else if ( V_22 <= 2 )
V_168 = V_22 ;
else if ( V_22 == 12 )
V_168 = 7 ;
else if ( ! ( V_22 & 0x1 ) )
V_168 = V_22 >> 1 ;
else
V_168 = ( V_22 + 1 ) >> 1 ;
if ( V_178 != - 1 )
V_178 = ( 128 * ( 1 << ! ! V_167 ) ) << V_168 ;
return V_178 ;
}
static int F_78 ( unsigned V_22 , unsigned V_179 )
{
unsigned V_168 = 0 ;
int V_178 = 0 ;
if ( V_22 < 4 || V_22 == 6 )
V_178 = - 1 ;
else if ( V_22 == 12 )
V_168 = 7 ;
else if ( ! ( V_22 & 0x1 ) )
V_168 = V_22 >> 1 ;
else
V_168 = ( V_22 + 1 ) >> 1 ;
if ( V_178 != - 1 )
V_178 = V_179 * ( 128 << V_168 ) ;
return V_178 ;
}
static int F_79 ( unsigned V_22 )
{
int V_178 = 0 ;
if ( V_22 == 0 )
V_178 = - 1 ;
else if ( V_22 == 1 )
V_178 = 1024 ;
else
V_178 = 1024 * ( 1 << ( V_22 >> 1 ) ) ;
return V_178 ;
}
static int F_80 ( struct V_8 * V_9 , T_2 V_10 ,
unsigned V_169 , int V_170 )
{
T_1 V_78 = V_10 ? V_9 -> V_90 : V_9 -> V_76 ;
F_68 ( V_169 > 11 ) ;
if ( V_9 -> V_108 & V_109 || V_9 -> V_180 & V_109 )
return F_77 ( V_169 , V_78 & V_119 ) ;
else
return F_73 ( V_169 , V_78 & V_119 ) ;
}
static int F_81 ( struct V_8 * V_9 , T_2 V_10 ,
unsigned V_169 , int V_170 )
{
F_68 ( V_169 > 12 ) ;
return F_77 ( V_169 , false ) ;
}
static int F_82 ( struct V_8 * V_9 , T_2 V_10 ,
unsigned V_169 , int V_170 )
{
int V_178 ;
T_1 V_82 = V_9 -> V_53 [ V_10 ] . V_55 [ V_170 ] ;
F_68 ( V_169 > 12 ) ;
if ( V_9 -> V_80 == V_113 ) {
if ( V_169 > 9 )
return - 1 ;
V_178 = F_79 ( V_169 ) ;
} else if ( V_9 -> V_80 == V_81 ) {
unsigned V_179 = V_82 & 0xf ;
if ( V_179 == 3 )
V_179 = 4 ;
V_178 = F_78 ( V_169 , V_179 ) ;
} else {
if ( V_169 == 0x1 )
return - 1 ;
V_178 = F_77 ( V_169 , false ) ;
}
return V_178 ;
}
static int F_83 ( struct V_8 * V_9 , T_2 V_10 ,
unsigned V_169 , int V_170 )
{
F_68 ( V_169 > 12 ) ;
if ( V_169 == 6 || V_169 == 8 ||
V_169 == 9 || V_169 == 12 )
return - 1 ;
else
return F_77 ( V_169 , false ) ;
}
static void F_84 ( struct V_8 * V_9 )
{
if ( V_9 -> V_15 == 0xf )
return;
if ( ! F_8 ( V_9 -> V_17 , V_181 , & V_9 -> V_182 ) ) {
F_25 ( 0 , L_50 ,
V_9 -> V_182 , F_85 ( V_9 ) ) ;
F_25 ( 0 , L_51 ,
( F_11 ( V_9 ) ? L_52 : L_53 ) ) ;
if ( ! F_11 ( V_9 ) )
F_25 ( 0 , L_54 ,
( F_86 ( V_9 ) ? L_22 : L_23 ) ) ;
F_25 ( 0 , L_55 ,
( F_87 ( V_9 ) ? L_25 : L_26 ) ,
( F_88 ( V_9 ) ? L_22 : L_23 ) ) ;
F_25 ( 0 , L_56
L_57 ,
( F_89 ( V_9 ) ? L_25 : L_26 ) ,
F_90 ( V_9 ) ) ;
}
F_8 ( V_9 -> V_17 , V_183 , & V_9 -> V_184 ) ;
}
static T_2 F_91 ( struct V_8 * V_9 , T_3 V_33 ,
T_2 V_37 , int V_185 ,
T_1 V_186 )
{
T_2 V_164 = 0 ;
T_2 V_187 ;
if ( ! ( V_37 ) )
return ( T_2 ) ( V_186 ) ;
if ( V_185 == 2 ) {
V_187 = ( V_33 >> 8 ) & 0x3 ;
V_164 = V_187 ? 0x3 : 0 ;
} else if ( V_185 == 4 ) {
T_2 V_188 = F_90 ( V_9 ) ;
switch ( V_188 ) {
case 0x4 :
V_164 = ( V_33 >> 8 ) & 0x3 ;
break;
case 0x5 :
V_164 = ( V_33 >> 9 ) & 0x3 ;
break;
}
}
return V_164 ;
}
static T_2 F_92 ( struct V_8 * V_9 , T_3 V_33 ,
bool V_189 , T_2 V_37 )
{
T_2 V_190 = ( V_9 -> V_182 >> 1 ) & 1 ;
if ( F_11 ( V_9 ) )
return 0 ;
if ( V_189 )
return V_190 ;
if ( F_89 ( V_9 ) ) {
T_2 V_188 = F_90 ( V_9 ) ;
if ( ! V_188 )
return V_33 >> 6 & 1 ;
if ( V_188 & 0x2 ) {
T_2 V_168 = V_188 & 0x1 ? 9 : 6 ;
T_1 V_191 = F_93 ( ( T_1 ) ( ( V_33 >> 16 ) & 0x1F ) ) % 2 ;
return ( ( V_33 >> V_168 ) & 1 ) ^ V_191 ;
}
return ( V_33 >> ( 12 + F_94 ( V_37 ) ) ) & 1 ;
}
if ( F_86 ( V_9 ) )
return ~ V_190 & 1 ;
return 0 ;
}
static T_3 F_95 ( struct V_8 * V_9 , T_2 V_139 ,
T_3 V_33 , bool V_192 ,
T_1 V_193 )
{
T_3 V_194 ;
T_3 V_62 = F_18 ( V_9 , V_139 ) ;
T_3 V_195 = F_35 ( V_9 ) ;
T_3 V_196 = ( V_9 -> V_184 & 0xFFFFFC00 ) << 16 ;
if ( V_192 ) {
if ( ( ! ( V_193 >> 16 ) ||
V_193 < F_34 ( V_9 ) ) &&
F_33 ( V_9 ) &&
( V_33 >= F_96 ( 32 ) ) )
V_194 = V_195 ;
else
V_194 = V_196 ;
} else {
if ( F_33 ( V_9 ) && ( V_33 >= F_96 ( 32 ) ) )
V_194 = V_195 ;
else
V_194 = V_62 ;
}
return ( V_33 & F_27 ( 47 , 6 ) ) - ( V_194 & F_27 ( 47 , 23 ) ) ;
}
static int F_97 ( struct V_8 * V_9 , T_2 V_10 , int V_43 )
{
int V_197 ;
if ( F_98 ( V_9 , V_10 ) &&
V_43 == F_99 ( V_9 , V_10 ) ) {
F_29 (tmp_cs, dct, pvt) {
if ( F_100 ( V_197 , V_10 , V_9 ) & 0x2 ) {
V_43 = V_197 ;
break;
}
}
}
return V_43 ;
}
static int F_101 ( T_3 V_198 , T_2 V_34 , T_2 V_10 )
{
struct V_26 * V_27 ;
struct V_8 * V_9 ;
T_3 V_199 , V_200 ;
int V_201 = - V_16 ;
int V_43 ;
V_27 = V_130 [ V_34 ] ;
if ( ! V_27 )
return V_201 ;
V_9 = V_27 -> V_29 ;
F_25 ( 1 , L_58 , V_198 , V_10 ) ;
F_29 (csrow, dct, pvt) {
if ( ! F_30 ( V_43 , V_10 , V_9 ) )
continue;
F_26 ( V_9 , V_43 , V_10 , & V_199 , & V_200 ) ;
F_25 ( 1 , L_59 ,
V_43 , V_199 , V_200 ) ;
V_200 = ~ V_200 ;
F_25 ( 1 , L_60 ,
( V_198 & V_200 ) , ( V_199 & V_200 ) ) ;
if ( ( V_198 & V_200 ) == ( V_199 & V_200 ) ) {
if ( V_9 -> V_15 == 0x15 && V_9 -> V_14 >= 0x30 ) {
V_201 = V_43 ;
break;
}
V_201 = F_97 ( V_9 , V_10 , V_43 ) ;
F_25 ( 1 , L_61 , V_201 ) ;
break;
}
}
return V_201 ;
}
static T_3 F_102 ( struct V_8 * V_9 , T_3 V_33 )
{
T_1 V_202 , V_203 , V_204 , V_205 , V_126 ;
if ( V_9 -> V_15 == 0x10 ) {
if ( V_9 -> V_14 < 4 || ( V_9 -> V_14 < 0xa && V_9 -> V_206 < 3 ) )
return V_33 ;
}
F_8 ( V_9 -> V_17 , V_207 , & V_202 ) ;
if ( ! ( V_202 & 0x1 ) )
return V_33 ;
V_203 = ( V_202 >> 3 ) & 0x7f ;
V_204 = ( V_202 >> 11 ) & 0x7f ;
V_205 = ( V_202 >> 20 ) & 0x7f ;
V_126 = V_33 >> 27 ;
if ( ! ( V_33 >> 34 ) &&
( ( ( V_126 >= V_203 ) &&
( V_126 <= V_204 ) ) ||
( V_126 < V_205 ) ) )
return V_33 ^ ( T_3 ) V_203 << 27 ;
return V_33 ;
}
static int F_103 ( struct V_8 * V_9 , unsigned V_139 ,
T_3 V_33 , int * V_208 )
{
int V_201 = - V_16 ;
T_3 V_209 ;
T_1 V_210 ;
T_2 V_164 ;
bool V_211 = false ;
T_2 V_36 = F_67 ( V_9 , V_139 ) ;
T_2 V_37 = F_21 ( V_9 , V_139 ) ;
T_1 V_212 = F_23 ( V_9 , V_139 ) ;
F_25 ( 1 , L_62 ,
V_139 , V_33 , F_19 ( V_9 , V_139 ) ) ;
if ( F_33 ( V_9 ) &&
F_34 ( V_9 ) <= V_33 &&
V_33 < F_96 ( 32 ) ) {
F_3 ( L_63 ,
V_33 ) ;
return - V_16 ;
}
if ( V_37 && ( V_212 != ( ( V_33 >> 12 ) & V_37 ) ) )
return - V_16 ;
V_33 = F_102 ( V_9 , V_33 ) ;
V_210 = F_85 ( V_9 ) ;
if ( F_86 ( V_9 ) &&
! F_11 ( V_9 ) &&
( ( V_33 >> 27 ) >= ( V_210 >> 11 ) ) )
V_211 = true ;
V_164 = F_92 ( V_9 , V_33 , V_211 , V_37 ) ;
V_209 = F_95 ( V_9 , V_139 , V_33 ,
V_211 , V_210 ) ;
if ( V_37 )
V_209 = ( ( V_209 >> ( 12 + F_94 ( V_37 ) ) ) << 12 ) |
( V_209 & 0xfff ) ;
if ( F_89 ( V_9 ) &&
! F_86 ( V_9 ) &&
! F_11 ( V_9 ) ) {
if ( F_90 ( V_9 ) != 1 ) {
if ( F_90 ( V_9 ) == 0x3 )
V_209 = ( ( V_209 >> 10 ) << 9 ) |
( V_209 & 0x1ff ) ;
else
V_209 = ( ( V_209 >> 7 ) << 6 ) |
( V_209 & 0x3f ) ;
} else
V_209 = ( ( V_209 >> 13 ) << 12 ) |
( V_209 & 0xfff ) ;
}
F_25 ( 1 , L_64 , V_209 ) ;
V_201 = F_101 ( V_209 , V_36 , V_164 ) ;
if ( V_201 >= 0 )
* V_208 = V_164 ;
return V_201 ;
}
static int F_104 ( struct V_8 * V_9 , unsigned V_139 ,
T_3 V_33 , int * V_208 )
{
int V_201 = - V_16 ;
int V_185 = 0 ;
T_3 V_209 , V_213 ;
T_3 V_214 , V_215 ;
T_1 V_216 , V_217 , V_127 ;
T_2 V_164 , V_218 , V_219 , V_186 , V_220 ;
T_3 V_221 = F_35 ( V_9 ) ;
T_2 V_188 = F_90 ( V_9 ) ;
T_2 V_36 = F_67 ( V_9 , V_139 ) ;
T_2 V_37 = F_21 ( V_9 , V_139 ) ;
F_8 ( V_9 -> V_12 , V_222 , & V_216 ) ;
F_8 ( V_9 -> V_12 , V_223 , & V_217 ) ;
V_220 = ( T_2 ) ( ( V_216 >> 3 ) & F_46 ( 0 ) ) ;
V_186 = ( T_2 ) ( ( V_216 >> 4 ) & 0x7 ) ;
F_25 ( 1 , L_62 ,
V_139 , V_33 , F_19 ( V_9 , V_139 ) ) ;
if ( ! ( F_18 ( V_9 , V_139 ) <= V_33 ) &&
! ( F_19 ( V_9 , V_139 ) >= V_33 ) )
return - V_16 ;
if ( F_33 ( V_9 ) &&
F_34 ( V_9 ) <= V_33 &&
V_33 < F_96 ( 32 ) ) {
F_3 ( L_63 ,
V_33 ) ;
return - V_16 ;
}
V_214 = ( T_3 ) F_85 ( V_9 ) ;
V_215 = ( V_217 >> 11 ) & 0x1FFF ;
if ( ! ( V_216 & F_46 ( 0 ) ) &&
! ( V_214 <= ( V_33 >> 27 ) &&
V_215 >= ( V_33 >> 27 ) ) )
return - V_16 ;
V_185 = ( int ) F_94 ( V_37 ) ;
if ( ! ( V_185 % 2 == 0 ) || ( V_185 > 4 ) )
return - V_16 ;
V_164 = F_91 ( V_9 , V_33 , V_37 ,
V_185 , V_186 ) ;
if ( V_164 > 3 )
return - V_16 ;
V_219 = ( T_2 ) ( V_216 >> 1 & F_46 ( 0 ) ) ;
if ( V_219 && ( V_33 >= F_96 ( 32 ) ) )
V_213 = V_221 ;
else
V_213 = V_214 << 27 ;
V_209 = V_33 - V_213 ;
if ( V_185 == 2 ) {
if ( V_188 == 0x4 )
V_209 = ( ( V_209 >> 9 ) << 8 ) |
( V_209 & 0xff ) ;
else if ( V_188 == 0x5 )
V_209 = ( ( V_209 >> 10 ) << 9 ) |
( V_209 & 0x1ff ) ;
else
return - V_16 ;
} else if ( V_185 == 4 ) {
if ( V_188 == 0x4 )
V_209 = ( ( V_209 >> 10 ) << 8 ) |
( V_209 & 0xff ) ;
else if ( V_188 == 0x5 )
V_209 = ( ( V_209 >> 11 ) << 9 ) |
( V_209 & 0x1ff ) ;
else
return - V_16 ;
}
if ( V_220 ) {
F_8 ( V_9 -> V_12 ,
V_224 + ( int ) V_164 * 4 ,
& V_127 ) ;
V_209 += ( T_3 ) ( ( V_127 >> 11 ) & 0xfff ) << 27 ;
}
F_7 ( V_9 , V_164 ) ;
F_25 ( 1 , L_64 , V_209 ) ;
V_218 = ( V_164 == 3 ) ? 1 : V_164 ;
V_201 = F_101 ( V_209 , V_36 , V_218 ) ;
if ( V_201 >= 0 )
* V_208 = V_218 ;
return V_201 ;
}
static int F_105 ( struct V_8 * V_9 ,
T_3 V_33 ,
int * V_208 )
{
int V_201 = - V_16 ;
unsigned V_139 ;
for ( V_139 = 0 ; V_139 < V_39 ; V_139 ++ ) {
if ( ! F_65 ( V_9 , V_139 ) )
continue;
if ( V_9 -> V_15 == 0x15 && V_9 -> V_14 >= 0x30 )
V_201 = F_104 ( V_9 , V_139 ,
V_33 ,
V_208 ) ;
else if ( ( F_18 ( V_9 , V_139 ) <= V_33 ) &&
( F_19 ( V_9 , V_139 ) >= V_33 ) ) {
V_201 = F_103 ( V_9 , V_139 ,
V_33 , V_208 ) ;
if ( V_201 >= 0 )
break;
}
}
return V_201 ;
}
static void F_106 ( struct V_26 * V_27 , T_3 V_33 ,
struct V_69 * V_6 )
{
struct V_8 * V_9 = V_27 -> V_29 ;
F_42 ( V_33 , V_6 ) ;
V_6 -> V_43 = F_105 ( V_9 , V_33 , & V_6 -> V_164 ) ;
if ( V_6 -> V_43 < 0 ) {
V_6 -> V_159 = V_161 ;
return;
}
if ( F_11 ( V_9 ) )
V_6 -> V_164 = F_71 ( V_27 , V_6 -> V_165 ) ;
}
static void F_49 ( struct V_8 * V_9 , T_2 V_225 )
{
int V_226 , V_227 , V_228 ;
T_1 * V_229 = V_225 ? V_9 -> V_53 [ 1 ] . V_54 : V_9 -> V_53 [ 0 ] . V_54 ;
T_1 V_175 = V_225 ? V_9 -> V_176 : V_9 -> V_177 ;
if ( V_9 -> V_15 == 0xf ) {
if ( V_9 -> V_51 < V_52 )
return;
else
F_68 ( V_225 != 0 ) ;
}
if ( V_9 -> V_15 == 0x10 ) {
V_175 = ( V_225 && ! F_11 ( V_9 ) ) ? V_9 -> V_176
: V_9 -> V_177 ;
V_229 = ( V_225 && ! F_11 ( V_9 ) ) ?
V_9 -> V_53 [ 1 ] . V_54 :
V_9 -> V_53 [ 0 ] . V_54 ;
} else if ( V_225 ) {
V_175 = V_9 -> V_177 ;
V_229 = V_9 -> V_53 [ 1 ] . V_54 ;
}
F_25 ( 1 , L_65 ,
V_225 , V_175 ) ;
F_107 ( V_230 , V_231 , L_66 , V_225 ) ;
for ( V_226 = 0 ; V_226 < 4 ; V_226 ++ ) {
V_227 = 0 ;
if ( V_229 [ V_226 * 2 ] & V_232 )
V_227 = V_9 -> V_233 -> V_234 ( V_9 , V_225 ,
F_76 ( V_226 , V_175 ) ,
V_226 ) ;
V_228 = 0 ;
if ( V_229 [ V_226 * 2 + 1 ] & V_232 )
V_228 = V_9 -> V_233 -> V_234 ( V_9 , V_225 ,
F_76 ( V_226 , V_175 ) ,
V_226 ) ;
F_50 ( V_231 L_67 ,
V_226 * 2 , V_227 ,
V_226 * 2 + 1 , V_228 ) ;
}
}
static int F_108 ( T_4 V_165 , const T_4 * V_235 , unsigned V_236 ,
unsigned V_237 )
{
unsigned int V_22 , V_238 ;
for ( V_238 = 0 ; V_238 < V_236 / V_237 ; V_238 ++ ) {
T_4 V_239 = V_165 ;
unsigned V_240 = V_238 * V_237 ;
unsigned V_241 = ( V_238 + 1 ) * V_237 ;
for ( V_22 = 1 ; V_22 < ( 1U << 16 ) ; V_22 <<= 1 ) {
if ( V_240 < V_241 && V_235 [ V_240 ] & V_22 ) {
T_4 V_242 = V_235 [ V_240 ++ ] ;
if ( V_239 & V_22 ) {
V_239 ^= V_242 ;
if ( ! V_239 )
return V_238 ;
}
} else if ( V_239 & V_22 )
break;
}
}
F_25 ( 0 , L_68 , V_165 ) ;
return - 1 ;
}
static int F_109 ( int V_238 , int V_243 )
{
if ( V_243 == 4 )
switch ( V_238 ) {
case 0x20 :
case 0x21 :
return 0 ;
break;
case 0x22 :
case 0x23 :
return 1 ;
break;
default:
return V_238 >> 4 ;
break;
}
else
switch ( V_238 ) {
case 0x10 :
F_55 ( 1 , V_116 L_69 ,
V_238 ) ;
return - 1 ;
break;
case 0x11 :
return 0 ;
break;
case 0x12 :
return 1 ;
break;
default:
return V_238 >> 3 ;
break;
}
return - 1 ;
}
static int F_71 ( struct V_26 * V_27 , T_4 V_165 )
{
struct V_8 * V_9 = V_27 -> V_29 ;
int V_238 = - 1 ;
if ( V_9 -> V_89 == 8 )
V_238 = F_108 ( V_165 , V_244 ,
F_13 ( V_244 ) ,
V_9 -> V_89 ) ;
else if ( V_9 -> V_89 == 4 )
V_238 = F_108 ( V_165 , V_245 ,
F_13 ( V_245 ) ,
V_9 -> V_89 ) ;
else {
F_3 ( L_70 , V_9 -> V_89 ) ;
return V_238 ;
}
return F_109 ( V_238 , V_9 -> V_89 ) ;
}
static void F_110 ( struct V_26 * V_27 , struct V_69 * V_6 ,
T_2 V_246 )
{
enum V_247 V_248 ;
const char * string ;
if ( V_246 == 2 )
V_248 = V_249 ;
else if ( V_246 == 1 )
V_248 = V_250 ;
else {
F_55 ( 1 , L_71 ) ;
return;
}
switch ( V_6 -> V_159 ) {
case V_251 :
string = L_72 ;
break;
case V_160 :
string = L_73 ;
break;
case V_161 :
string = L_74 ;
break;
case V_166 :
string = L_75 ;
break;
default:
string = L_76 ;
break;
}
F_111 ( V_248 , V_27 , 1 ,
V_6 -> V_70 , V_6 -> V_3 , V_6 -> V_165 ,
V_6 -> V_43 , V_6 -> V_164 , - 1 ,
string , L_72 ) ;
}
static inline void F_112 ( int V_36 , struct V_121 * V_122 )
{
struct V_26 * V_27 ;
struct V_8 * V_9 ;
T_2 V_246 = ( V_122 -> V_252 >> 45 ) & 0x3 ;
T_2 V_253 = F_113 ( V_122 -> V_252 , 0x1f ) ;
T_4 V_254 = F_114 ( V_122 -> V_252 ) ;
T_3 V_33 ;
struct V_69 V_6 ;
V_27 = F_24 ( V_36 ) ;
if ( ! V_27 )
return;
V_9 = V_27 -> V_29 ;
if ( F_115 ( V_254 ) == V_255 )
return;
if ( V_253 && V_253 != V_256 )
return;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_33 = F_57 ( V_9 , V_122 ) ;
if ( V_246 == 2 )
V_6 . V_165 = F_116 ( V_122 -> V_252 ) ;
V_9 -> V_233 -> V_257 ( V_27 , V_33 , & V_6 ) ;
F_110 ( V_27 , & V_6 , V_246 ) ;
}
static int F_117 ( struct V_8 * V_9 , T_4 V_258 , T_4 V_259 )
{
V_9 -> V_12 = F_60 ( V_9 -> V_17 -> V_133 , V_258 , V_9 -> V_17 ) ;
if ( ! V_9 -> V_12 ) {
F_118 ( L_77
L_78 ,
V_260 , V_258 ) ;
return - V_261 ;
}
V_9 -> V_31 = F_60 ( V_9 -> V_17 -> V_133 , V_259 , V_9 -> V_17 ) ;
if ( ! V_9 -> V_31 ) {
F_69 ( V_9 -> V_12 ) ;
V_9 -> V_12 = NULL ;
F_118 ( L_79
L_78 ,
V_260 , V_259 ) ;
return - V_261 ;
}
F_25 ( 1 , L_80 , F_119 ( V_9 -> V_12 ) ) ;
F_25 ( 1 , L_81 , F_119 ( V_9 -> V_17 ) ) ;
F_25 ( 1 , L_82 , F_119 ( V_9 -> V_31 ) ) ;
return 0 ;
}
static void F_120 ( struct V_8 * V_9 )
{
F_69 ( V_9 -> V_12 ) ;
F_69 ( V_9 -> V_31 ) ;
}
static void F_121 ( struct V_8 * V_9 )
{
unsigned V_139 ;
T_3 V_262 ;
T_1 V_127 ;
F_122 ( V_263 , V_9 -> V_264 ) ;
F_25 ( 0 , L_83 , V_9 -> V_264 ) ;
F_122 ( V_265 , V_262 ) ;
if ( V_262 & ( 1U << 21 ) ) {
F_122 ( V_266 , V_9 -> V_267 ) ;
F_25 ( 0 , L_84 , V_9 -> V_267 ) ;
} else
F_25 ( 0 , L_85 ) ;
F_8 ( V_9 -> V_31 , V_268 , & V_9 -> V_83 ) ;
F_84 ( V_9 ) ;
for ( V_139 = 0 ; V_139 < V_39 ; V_139 ++ ) {
T_2 V_269 ;
F_64 ( V_9 , V_139 ) ;
V_269 = F_65 ( V_9 , V_139 ) ;
if ( ! V_269 )
continue;
F_25 ( 1 , L_86 ,
V_139 ,
F_18 ( V_9 , V_139 ) ,
F_19 ( V_9 , V_139 ) ) ;
F_25 ( 1 , L_87 ,
F_21 ( V_9 , V_139 ) ? L_88 : L_89 ,
( V_269 & 0x1 ) ? L_90 : L_91 ,
( V_269 & 0x2 ) ? L_92 : L_91 ,
F_23 ( V_9 , V_139 ) ,
F_67 ( V_9 , V_139 ) ) ;
}
F_52 ( V_9 ) ;
F_8 ( V_9 -> V_12 , V_270 , & V_9 -> V_88 ) ;
F_10 ( V_9 , 0 , V_271 , & V_9 -> V_177 ) ;
F_8 ( V_9 -> V_31 , V_272 , & V_9 -> V_87 ) ;
F_10 ( V_9 , 0 , V_273 , & V_9 -> V_76 ) ;
F_10 ( V_9 , 0 , V_274 , & V_9 -> V_108 ) ;
if ( ! F_11 ( V_9 ) ) {
F_10 ( V_9 , 1 , V_273 , & V_9 -> V_90 ) ;
F_10 ( V_9 , 1 , V_274 , & V_9 -> V_180 ) ;
}
V_9 -> V_89 = 4 ;
F_54 ( V_9 ) ;
F_25 ( 1 , L_93 , V_275 [ V_9 -> V_80 ] ) ;
if ( V_9 -> V_15 >= 0x10 ) {
F_8 ( V_9 -> V_31 , V_276 , & V_127 ) ;
if ( V_9 -> V_15 != 0x16 )
F_10 ( V_9 , 1 , V_271 , & V_9 -> V_176 ) ;
if ( ( V_9 -> V_15 > 0x10 || V_9 -> V_14 > 7 ) && V_127 & F_46 ( 25 ) )
V_9 -> V_89 = 8 ;
}
F_48 ( V_9 ) ;
}
static T_1 F_123 ( struct V_8 * V_9 , T_2 V_10 , int V_277 )
{
T_1 V_169 , V_278 ;
T_1 V_175 = V_10 ? V_9 -> V_176 : V_9 -> V_177 ;
V_169 = F_76 ( V_277 / 2 , V_175 ) ;
V_278 = V_9 -> V_233 -> V_234 ( V_9 , V_10 , V_169 , ( V_277 / 2 ) )
<< ( 20 - V_71 ) ;
F_25 ( 0 , L_94 ,
V_277 , V_10 , V_169 ) ;
F_25 ( 0 , L_95 , V_278 ) ;
return V_278 ;
}
static int F_124 ( struct V_26 * V_27 )
{
struct V_8 * V_9 = V_27 -> V_29 ;
struct V_279 * V_43 ;
struct V_280 * V_226 ;
enum V_281 V_282 ;
int V_22 , V_173 , V_283 = 1 ;
int V_278 = 0 ;
T_1 V_4 ;
F_8 ( V_9 -> V_31 , V_284 , & V_4 ) ;
V_9 -> V_162 = V_4 ;
F_25 ( 0 , L_96 ,
V_9 -> V_57 , V_4 ,
! ! ( V_4 & V_163 ) , ! ! ( V_4 & V_285 ) ) ;
F_29 (i, 0 , pvt) {
bool V_286 = ! ! F_30 ( V_22 , 0 , V_9 ) ;
bool V_287 = false ;
if ( V_9 -> V_15 != 0xf )
V_287 = ! ! F_30 ( V_22 , 1 , V_9 ) ;
if ( ! V_286 && ! V_287 )
continue;
V_43 = V_27 -> V_288 [ V_22 ] ;
V_283 = 0 ;
F_25 ( 1 , L_97 ,
V_9 -> V_57 , V_22 ) ;
if ( V_286 ) {
V_278 = F_123 ( V_9 , 0 , V_22 ) ;
V_43 -> V_174 [ 0 ] -> V_226 -> V_278 = V_278 ;
}
if ( V_9 -> V_15 != 0xf && V_287 ) {
int V_289 = F_123 ( V_9 , 1 , V_22 ) ;
V_43 -> V_174 [ 1 ] -> V_226 -> V_278 = V_289 ;
V_278 += V_289 ;
}
F_25 ( 1 , L_98 , V_22 , V_278 ) ;
if ( V_9 -> V_162 & V_285 )
V_282 = ( V_9 -> V_162 & V_163 ) ?
V_290 : V_291 ;
else
V_282 = V_292 ;
for ( V_173 = 0 ; V_173 < V_9 -> V_293 ; V_173 ++ ) {
V_226 = V_43 -> V_174 [ V_173 ] -> V_226 ;
V_226 -> V_294 = V_9 -> V_80 ;
V_226 -> V_282 = V_282 ;
}
}
return V_283 ;
}
static void F_125 ( struct V_295 * V_45 , T_4 V_34 )
{
int V_296 ;
F_126 (cpu)
if ( F_58 ( V_296 ) == V_34 )
F_127 ( V_296 , V_45 ) ;
}
static bool F_128 ( T_4 V_34 )
{
T_5 V_45 ;
int V_296 , V_297 ;
bool V_64 = false ;
if ( ! F_129 ( & V_45 , V_298 ) ) {
F_3 ( L_99 , V_42 ) ;
return false ;
}
F_125 ( V_45 , V_34 ) ;
F_130 ( V_45 , V_299 , V_300 ) ;
F_131 (cpu, mask) {
struct V_301 * V_11 = F_132 ( V_300 , V_296 ) ;
V_297 = V_11 -> V_302 & V_303 ;
F_25 ( 0 , L_100 ,
V_296 , V_11 -> V_304 ,
( V_297 ? L_25 : L_26 ) ) ;
if ( ! V_297 )
goto V_305;
}
V_64 = true ;
V_305:
F_133 ( V_45 ) ;
return V_64 ;
}
static int F_134 ( struct V_306 * V_239 , T_4 V_34 , bool V_307 )
{
T_5 V_308 ;
int V_296 ;
if ( ! F_129 ( & V_308 , V_298 ) ) {
F_3 ( L_101 , V_42 ) ;
return false ;
}
F_125 ( V_308 , V_34 ) ;
F_130 ( V_308 , V_299 , V_300 ) ;
F_131 (cpu, cmask) {
struct V_301 * V_11 = F_132 ( V_300 , V_296 ) ;
if ( V_307 ) {
if ( V_11 -> V_302 & V_303 )
V_239 -> V_309 . V_310 = 1 ;
V_11 -> V_302 |= V_303 ;
} else {
if ( ! V_239 -> V_309 . V_310 )
V_11 -> V_302 &= ~ V_303 ;
}
}
F_135 ( V_308 , V_299 , V_300 ) ;
F_133 ( V_308 ) ;
return 0 ;
}
static bool F_136 ( struct V_306 * V_239 , T_4 V_34 ,
struct V_1 * V_31 )
{
bool V_64 = true ;
T_1 V_311 , V_45 = 0x3 ;
if ( F_134 ( V_239 , V_34 , V_312 ) ) {
F_3 ( L_102 ) ;
return false ;
}
F_8 ( V_31 , V_313 , & V_311 ) ;
V_239 -> V_314 = V_311 & V_45 ;
V_239 -> V_315 = true ;
V_311 |= V_45 ;
F_9 ( V_31 , V_313 , V_311 ) ;
F_8 ( V_31 , V_284 , & V_311 ) ;
F_25 ( 0 , L_103 ,
V_34 , V_311 , ! ! ( V_311 & V_285 ) ) ;
if ( ! ( V_311 & V_285 ) ) {
F_3 ( L_104 ) ;
V_239 -> V_309 . V_316 = 0 ;
V_311 |= V_285 ;
F_9 ( V_31 , V_284 , V_311 ) ;
F_8 ( V_31 , V_284 , & V_311 ) ;
if ( ! ( V_311 & V_285 ) ) {
F_3 ( L_105
L_106 ) ;
V_64 = false ;
} else {
F_50 ( L_107 ) ;
}
} else {
V_239 -> V_309 . V_316 = 1 ;
}
F_25 ( 0 , L_108 ,
V_34 , V_311 , ! ! ( V_311 & V_285 ) ) ;
return V_64 ;
}
static void F_137 ( struct V_306 * V_239 , T_4 V_34 ,
struct V_1 * V_31 )
{
T_1 V_311 , V_45 = 0x3 ;
if ( ! V_239 -> V_315 )
return;
F_8 ( V_31 , V_313 , & V_311 ) ;
V_311 &= ~ V_45 ;
V_311 |= V_239 -> V_314 ;
F_9 ( V_31 , V_313 , V_311 ) ;
if ( ! V_239 -> V_309 . V_316 ) {
F_8 ( V_31 , V_284 , & V_311 ) ;
V_311 &= ~ V_285 ;
F_9 ( V_31 , V_284 , V_311 ) ;
}
if ( F_134 ( V_239 , V_34 , V_317 ) )
F_3 ( L_109 ) ;
}
static bool F_138 ( struct V_1 * V_31 , T_4 V_34 )
{
T_1 V_311 ;
T_2 V_318 = 0 ;
bool V_319 = false ;
F_8 ( V_31 , V_284 , & V_311 ) ;
V_318 = ! ! ( V_311 & V_285 ) ;
F_50 ( L_110 , ( V_318 ? L_25 : L_26 ) ) ;
V_319 = F_128 ( V_34 ) ;
if ( ! V_319 )
F_139 ( L_111
L_112 ,
V_299 , V_34 ) ;
if ( ! V_318 || ! V_319 ) {
F_139 ( L_113 , V_320 ) ;
return false ;
}
return true ;
}
static int F_140 ( struct V_26 * V_27 )
{
struct V_8 * V_9 = V_27 -> V_29 ;
int V_321 ;
V_321 = F_141 ( V_27 ) ;
if ( V_321 < 0 )
return V_321 ;
if ( V_9 -> V_15 >= 0x10 ) {
V_321 = F_142 ( V_27 ) ;
if ( V_321 < 0 )
return V_321 ;
}
return 0 ;
}
static void F_143 ( struct V_26 * V_27 )
{
struct V_8 * V_9 = V_27 -> V_29 ;
F_144 ( V_27 ) ;
if ( V_9 -> V_15 >= 0x10 )
F_145 ( V_27 ) ;
}
static void F_146 ( struct V_26 * V_27 ,
struct V_322 * V_15 )
{
struct V_8 * V_9 = V_27 -> V_29 ;
V_27 -> V_323 = V_324 | V_325 ;
V_27 -> V_326 = V_75 ;
if ( V_9 -> V_83 & V_85 )
V_27 -> V_326 |= V_77 ;
if ( V_9 -> V_83 & V_86 )
V_27 -> V_326 |= V_327 ;
V_27 -> V_74 = F_45 ( V_9 ) ;
V_27 -> V_328 = V_329 ;
V_27 -> V_330 = V_331 ;
V_27 -> V_332 = V_15 -> V_332 ;
V_27 -> V_333 = F_119 ( V_9 -> V_17 ) ;
V_27 -> V_334 = NULL ;
V_27 -> V_335 = F_15 ;
V_27 -> V_336 = F_16 ;
}
static struct V_322 * F_147 ( struct V_8 * V_9 )
{
struct V_322 * V_337 = NULL ;
V_9 -> V_51 = V_338 . V_339 >> 4 ;
V_9 -> V_206 = V_338 . V_340 ;
V_9 -> V_14 = V_338 . V_339 ;
V_9 -> V_15 = V_338 . V_341 ;
switch ( V_9 -> V_15 ) {
case 0xf :
V_337 = & V_342 [ V_343 ] ;
V_9 -> V_233 = & V_342 [ V_343 ] . V_233 ;
break;
case 0x10 :
V_337 = & V_342 [ V_344 ] ;
V_9 -> V_233 = & V_342 [ V_344 ] . V_233 ;
break;
case 0x15 :
if ( V_9 -> V_14 == 0x30 ) {
V_337 = & V_342 [ V_345 ] ;
V_9 -> V_233 = & V_342 [ V_345 ] . V_233 ;
break;
} else if ( V_9 -> V_14 == 0x60 ) {
V_337 = & V_342 [ V_346 ] ;
V_9 -> V_233 = & V_342 [ V_346 ] . V_233 ;
break;
}
V_337 = & V_342 [ V_347 ] ;
V_9 -> V_233 = & V_342 [ V_347 ] . V_233 ;
break;
case 0x16 :
if ( V_9 -> V_14 == 0x30 ) {
V_337 = & V_342 [ V_348 ] ;
V_9 -> V_233 = & V_342 [ V_348 ] . V_233 ;
break;
}
V_337 = & V_342 [ V_349 ] ;
V_9 -> V_233 = & V_342 [ V_349 ] . V_233 ;
break;
default:
F_118 ( L_114 ) ;
return NULL ;
}
F_50 ( L_115 , V_337 -> V_332 ,
( V_9 -> V_15 == 0xf ?
( V_9 -> V_51 >= V_52 ? L_116
: L_117 )
: L_72 ) , V_9 -> V_57 ) ;
return V_337 ;
}
static int F_148 ( struct V_1 * V_17 )
{
struct V_8 * V_9 = NULL ;
struct V_322 * V_337 = NULL ;
struct V_26 * V_27 = NULL ;
struct V_350 V_351 [ 2 ] ;
int V_6 = 0 , V_64 ;
T_4 V_34 = F_149 ( V_17 ) ;
V_64 = - V_352 ;
V_9 = F_150 ( sizeof( struct V_8 ) , V_298 ) ;
if ( ! V_9 )
goto V_353;
V_9 -> V_57 = V_34 ;
V_9 -> V_17 = V_17 ;
V_64 = - V_16 ;
V_337 = F_147 ( V_9 ) ;
if ( ! V_337 )
goto V_354;
V_64 = - V_261 ;
V_6 = F_117 ( V_9 , V_337 -> V_258 , V_337 -> V_259 ) ;
if ( V_6 )
goto V_354;
F_121 ( V_9 ) ;
V_64 = - V_16 ;
V_9 -> V_293 = V_9 -> V_233 -> V_355 ( V_9 ) ;
if ( V_9 -> V_293 < 0 )
goto V_356;
V_64 = - V_352 ;
V_351 [ 0 ] . type = V_357 ;
V_351 [ 0 ] . V_358 = V_9 -> V_53 [ 0 ] . V_91 ;
V_351 [ 0 ] . V_359 = true ;
V_351 [ 1 ] . type = V_360 ;
V_351 [ 1 ] . V_358 = 2 ;
V_351 [ 1 ] . V_359 = false ;
V_27 = F_151 ( V_34 , F_13 ( V_351 ) , V_351 , 0 ) ;
if ( ! V_27 )
goto V_356;
V_27 -> V_29 = V_9 ;
V_27 -> V_2 = & V_9 -> V_17 -> V_136 ;
F_146 ( V_27 , V_337 ) ;
if ( F_124 ( V_27 ) )
V_27 -> V_74 = V_75 ;
V_64 = - V_261 ;
if ( F_152 ( V_27 ) ) {
F_25 ( 1 , L_118 ) ;
goto V_361;
}
if ( F_140 ( V_27 ) ) {
F_25 ( 1 , L_118 ) ;
goto V_362;
}
if ( V_363 )
F_153 ( true ) ;
F_154 ( F_112 ) ;
V_130 [ V_34 ] = V_27 ;
F_155 ( & V_364 ) ;
return 0 ;
V_362:
F_156 ( V_27 -> V_2 ) ;
V_361:
F_157 ( V_27 ) ;
V_356:
F_120 ( V_9 ) ;
V_354:
F_158 ( V_9 ) ;
V_353:
return V_64 ;
}
static int F_159 ( struct V_1 * V_2 ,
const struct V_365 * V_366 )
{
T_4 V_34 = F_149 ( V_2 ) ;
struct V_1 * V_31 = F_66 ( V_34 ) -> V_157 ;
struct V_306 * V_239 ;
int V_64 = 0 ;
V_64 = F_160 ( V_2 ) ;
if ( V_64 < 0 ) {
F_25 ( 0 , L_119 , V_64 ) ;
return - V_367 ;
}
V_64 = - V_352 ;
V_239 = F_150 ( sizeof( struct V_306 ) , V_298 ) ;
if ( ! V_239 )
goto V_368;
V_369 [ V_34 ] = V_239 ;
if ( ! F_138 ( V_31 , V_34 ) ) {
V_64 = - V_261 ;
if ( ! V_370 )
goto V_371;
F_3 ( L_120 ) ;
if ( ! F_136 ( V_239 , V_34 , V_31 ) )
goto V_371;
}
V_64 = F_148 ( V_2 ) ;
if ( V_64 < 0 ) {
F_118 ( L_121 , V_34 ) ;
F_137 ( V_239 , V_34 , V_31 ) ;
}
return V_64 ;
V_371:
F_158 ( V_239 ) ;
V_369 [ V_34 ] = NULL ;
V_368:
return V_64 ;
}
static void F_161 ( struct V_1 * V_2 )
{
struct V_26 * V_27 ;
struct V_8 * V_9 ;
T_4 V_34 = F_149 ( V_2 ) ;
struct V_1 * V_31 = F_66 ( V_34 ) -> V_157 ;
struct V_306 * V_239 = V_369 [ V_34 ] ;
V_27 = F_162 ( & V_2 -> V_136 ) ;
F_68 ( ! V_27 ) ;
F_143 ( V_27 ) ;
V_27 = F_156 ( & V_2 -> V_136 ) ;
if ( ! V_27 )
return;
V_9 = V_27 -> V_29 ;
F_137 ( V_239 , V_34 , V_31 ) ;
F_120 ( V_9 ) ;
F_153 ( false ) ;
F_163 ( F_112 ) ;
F_158 ( V_369 [ V_34 ] ) ;
V_369 [ V_34 ] = NULL ;
V_27 -> V_29 = NULL ;
V_130 [ V_34 ] = NULL ;
F_158 ( V_9 ) ;
F_157 ( V_27 ) ;
}
static void F_164 ( void )
{
struct V_26 * V_27 ;
struct V_8 * V_9 ;
if ( V_372 )
return;
V_27 = V_130 [ 0 ] ;
if ( ! V_27 )
return;
V_9 = V_27 -> V_29 ;
V_372 = F_165 ( & V_9 -> V_17 -> V_136 , V_329 ) ;
if ( ! V_372 ) {
F_166 ( L_122 , V_42 ) ;
F_166 ( L_123 , V_42 ) ;
}
}
static int T_6 F_167 ( void )
{
int V_6 = - V_261 ;
F_168 ( V_373 L_124 , V_331 ) ;
F_169 () ;
if ( F_170 () < 0 )
goto V_353;
V_6 = - V_352 ;
V_130 = F_150 ( F_171 () * sizeof( V_130 [ 0 ] ) , V_298 ) ;
V_369 = F_150 ( F_171 () * sizeof( V_369 [ 0 ] ) , V_298 ) ;
if ( ! ( V_130 && V_369 ) )
goto V_354;
V_300 = F_172 () ;
if ( ! V_300 )
goto V_354;
V_6 = F_173 ( & V_374 ) ;
if ( V_6 )
goto V_375;
V_6 = - V_261 ;
if ( ! F_174 ( & V_364 ) )
goto V_376;
F_164 () ;
#ifdef F_175
F_118 ( L_125 , V_329 ) ;
#endif
return 0 ;
V_376:
F_176 ( & V_374 ) ;
V_375:
F_177 ( V_300 ) ;
V_300 = NULL ;
V_354:
F_158 ( V_130 ) ;
V_130 = NULL ;
F_158 ( V_369 ) ;
V_369 = NULL ;
V_353:
return V_6 ;
}
static void T_7 F_178 ( void )
{
if ( V_372 )
F_179 ( V_372 ) ;
F_176 ( & V_374 ) ;
F_158 ( V_369 ) ;
V_369 = NULL ;
F_158 ( V_130 ) ;
V_130 = NULL ;
F_177 ( V_300 ) ;
V_300 = NULL ;
}
