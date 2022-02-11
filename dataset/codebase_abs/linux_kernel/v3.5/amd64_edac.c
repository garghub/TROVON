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
static inline void F_47 ( T_3 V_69 ,
T_1 * V_70 , T_1 * V_3 )
{
* V_70 = ( T_1 ) ( V_69 >> V_71 ) ;
* V_3 = ( ( T_1 ) V_69 ) & ~ V_72 ;
}
static int F_48 ( struct V_25 * V_26 , T_3 V_34 )
{
int V_43 ;
V_43 = F_29 ( V_26 , F_43 ( V_26 , V_34 ) ) ;
if ( V_43 == - 1 )
F_49 ( V_26 , L_25
L_26 , ( unsigned long ) V_34 ) ;
return V_43 ;
}
static unsigned long F_50 ( struct V_8 * V_9 )
{
T_2 V_73 ;
unsigned long V_74 = V_75 ;
V_73 = ( V_30 . V_31 > 0xf || V_9 -> V_51 >= V_52 )
? 19
: 17 ;
if ( V_9 -> V_76 & F_51 ( V_73 ) )
V_74 = V_77 ;
return V_74 ;
}
static void F_52 ( T_1 V_78 , int V_79 )
{
F_33 ( L_27 , V_79 , V_78 ) ;
F_33 ( L_28 ,
( V_78 & F_51 ( 16 ) ) ? L_29 : L_30 ,
( V_78 & F_51 ( 19 ) ) ? L_31 : L_32 ) ;
F_33 ( L_33 ,
( V_78 & F_51 ( 8 ) ) ? L_34 : L_35 ) ;
if ( V_30 . V_31 == 0x10 )
F_33 ( L_36 ,
( V_78 & F_51 ( 11 ) ) ? L_37 : L_38 ) ;
F_33 ( L_39 ,
( V_78 & F_51 ( 12 ) ) ? L_31 : L_32 ,
( V_78 & F_51 ( 13 ) ) ? L_31 : L_32 ,
( V_78 & F_51 ( 14 ) ) ? L_31 : L_32 ,
( V_78 & F_51 ( 15 ) ) ? L_31 : L_32 ) ;
}
static void F_53 ( struct V_8 * V_9 )
{
F_33 ( L_40 , V_9 -> V_80 ) ;
F_33 ( L_41 ,
( V_9 -> V_80 & V_81 ) ? L_31 : L_32 ) ;
F_33 ( L_42 ,
( V_9 -> V_80 & V_82 ) ? L_31 : L_32 ,
( V_9 -> V_80 & V_83 ) ? L_31 : L_32 ) ;
F_52 ( V_9 -> V_76 , 0 ) ;
F_33 ( L_43 , V_9 -> V_84 ) ;
F_33 ( L_44
L_45 ,
V_9 -> V_85 , F_36 ( V_9 ) ,
( V_30 . V_31 == 0xf ) ? F_38 ( V_9 )
: F_37 ( V_9 ) ) ;
F_33 ( L_46 , F_35 ( V_9 ) ? L_31 : L_32 ) ;
F_54 ( V_9 , 0 ) ;
if ( V_30 . V_31 == 0xf )
return;
F_54 ( V_9 , 1 ) ;
F_55 ( L_47 , ( ( V_9 -> V_86 == 8 ) ? L_48 : L_49 ) ) ;
if ( ! F_56 ( V_9 ) )
F_52 ( V_9 -> V_87 , 1 ) ;
}
static void F_57 ( struct V_8 * V_9 )
{
if ( V_30 . V_31 == 0xf && V_9 -> V_51 < V_52 ) {
V_9 -> V_53 [ 0 ] . V_88 = V_9 -> V_53 [ 1 ] . V_88 = 8 ;
V_9 -> V_53 [ 0 ] . V_89 = V_9 -> V_53 [ 1 ] . V_89 = 8 ;
} else {
V_9 -> V_53 [ 0 ] . V_88 = V_9 -> V_53 [ 1 ] . V_88 = 8 ;
V_9 -> V_53 [ 0 ] . V_89 = V_9 -> V_53 [ 1 ] . V_89 = 4 ;
}
}
static void F_58 ( struct V_8 * V_9 )
{
int V_90 ;
F_57 ( V_9 ) ;
F_30 (cs, 0 , pvt) {
int V_91 = V_92 + ( V_90 * 4 ) ;
int V_93 = V_94 + ( V_90 * 4 ) ;
T_1 * V_95 = & V_9 -> V_53 [ 0 ] . V_54 [ V_90 ] ;
T_1 * V_96 = & V_9 -> V_53 [ 1 ] . V_54 [ V_90 ] ;
if ( ! F_59 ( V_9 , V_91 , V_95 ) )
F_60 ( L_50 ,
V_90 , * V_95 , V_91 ) ;
if ( V_30 . V_31 == 0xf || F_56 ( V_9 ) )
continue;
if ( ! F_59 ( V_9 , V_93 , V_96 ) )
F_60 ( L_51 ,
V_90 , * V_96 , V_93 ) ;
}
F_61 (cs, 0 , pvt) {
int V_91 = V_97 + ( V_90 * 4 ) ;
int V_93 = V_98 + ( V_90 * 4 ) ;
T_1 * V_99 = & V_9 -> V_53 [ 0 ] . V_55 [ V_90 ] ;
T_1 * V_100 = & V_9 -> V_53 [ 1 ] . V_55 [ V_90 ] ;
if ( ! F_59 ( V_9 , V_91 , V_99 ) )
F_60 ( L_52 ,
V_90 , * V_99 , V_91 ) ;
if ( V_30 . V_31 == 0xf || F_56 ( V_9 ) )
continue;
if ( ! F_59 ( V_9 , V_93 , V_100 ) )
F_60 ( L_53 ,
V_90 , * V_100 , V_93 ) ;
}
}
static enum V_101 F_62 ( struct V_8 * V_9 , int V_90 )
{
enum V_101 type ;
if ( V_30 . V_31 >= 0x15 )
type = ( V_9 -> V_76 & F_51 ( 16 ) ) ? V_102 : V_103 ;
else if ( V_30 . V_31 == 0x10 || V_9 -> V_51 >= V_52 ) {
if ( V_9 -> V_104 & V_105 )
type = ( V_9 -> V_76 & F_51 ( 16 ) ) ? V_102 : V_103 ;
else
type = ( V_9 -> V_76 & F_51 ( 16 ) ) ? V_106 : V_107 ;
} else {
type = ( V_9 -> V_76 & F_51 ( 18 ) ) ? V_108 : V_109 ;
}
F_55 ( L_54 , V_90 , V_110 [ type ] ) ;
return type ;
}
static int F_63 ( struct V_8 * V_9 )
{
int V_111 ;
if ( V_9 -> V_51 >= V_52 )
V_111 = V_9 -> V_76 & V_112 ;
else
V_111 = V_9 -> V_76 & V_113 ;
V_9 -> V_87 = 0 ;
return ( V_111 ) ? 2 : 1 ;
}
static T_3 F_64 ( struct V_114 * V_115 )
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
V_123 = F_65 ( V_115 -> V_124 ) ;
V_9 = V_125 [ V_123 ] -> V_28 ;
F_10 ( V_9 -> V_15 , V_126 , & V_122 ) ;
V_37 = V_122 >> 21 & 0x7 ;
V_120 = ( V_122 & F_28 ( 0 , 20 ) ) << 3 ;
V_120 |= V_37 ^ 0x7 ;
V_120 <<= 24 ;
if ( ! V_37 )
return V_120 | ( V_10 & F_28 ( 0 , 23 ) ) ;
F_10 ( V_9 -> V_15 , V_127 , & V_122 ) ;
V_121 = ( V_10 & F_28 ( 12 , 23 ) ) << F_66 ( V_37 + 1 ) ;
V_121 |= ( V_122 & F_28 ( 21 , 23 ) ) >> 9 ;
V_121 |= V_10 & F_28 ( 0 , 11 ) ;
return V_120 | V_121 ;
}
return V_10 ;
}
static void F_67 ( struct V_8 * V_9 , unsigned V_128 )
{
struct V_116 * V_117 = & V_30 ;
int V_129 = V_128 << 3 ;
F_10 ( V_9 -> V_15 , V_130 + V_129 , & V_9 -> V_131 [ V_128 ] . V_44 . V_132 ) ;
F_10 ( V_9 -> V_15 , V_133 + V_129 , & V_9 -> V_131 [ V_128 ] . V_134 . V_132 ) ;
if ( V_117 -> V_31 == 0xf )
return;
if ( ! F_68 ( V_9 , V_128 ) )
return;
F_10 ( V_9 -> V_15 , V_135 + V_129 , & V_9 -> V_131 [ V_128 ] . V_44 . V_136 ) ;
F_10 ( V_9 -> V_15 , V_137 + V_129 , & V_9 -> V_131 [ V_128 ] . V_134 . V_136 ) ;
if ( V_117 -> V_31 == 0x15 ) {
struct V_1 * V_138 = NULL ;
T_2 V_35 = F_69 ( V_9 , V_128 ) ;
T_1 V_139 ;
V_138 = F_70 ( 0 , 0 , F_71 ( 0x18 + V_35 , 1 ) ) ;
if ( F_72 ( ! V_138 ) )
return;
F_10 ( V_138 , V_126 , & V_139 ) ;
V_9 -> V_131 [ V_128 ] . V_134 . V_132 &= F_28 ( 0 , 15 ) ;
V_9 -> V_131 [ V_128 ] . V_134 . V_132 |= ( ( V_139 & 0x1fff ) << 3 | 0x7 ) << 16 ;
V_9 -> V_131 [ V_128 ] . V_134 . V_136 &= F_28 ( 0 , 7 ) ;
V_9 -> V_131 [ V_128 ] . V_134 . V_136 |= V_139 >> 13 ;
F_73 ( V_138 ) ;
}
}
static void F_74 ( struct V_25 * V_26 , T_3 V_34 ,
T_4 V_140 )
{
struct V_25 * V_141 ;
struct V_8 * V_9 = V_26 -> V_28 ;
int V_142 , V_43 ;
T_1 V_70 , V_3 ;
F_47 ( V_34 , & V_70 , & V_3 ) ;
V_141 = F_21 ( V_26 , V_34 ) ;
if ( ! V_141 ) {
F_49 ( V_26 , L_55 ,
( unsigned long ) V_34 ) ;
F_75 ( V_143 , V_26 ,
V_70 , V_3 , V_140 ,
- 1 , - 1 , - 1 ,
V_144 ,
L_56 ,
NULL ) ;
return;
}
V_43 = F_48 ( V_141 , V_34 ) ;
if ( V_43 < 0 ) {
F_75 ( V_143 , V_26 ,
V_70 , V_3 , V_140 ,
- 1 , - 1 , - 1 ,
V_144 ,
L_57 ,
NULL ) ;
return;
}
if ( V_9 -> V_145 & V_146 ) {
V_142 = F_76 ( V_26 , V_140 ) ;
if ( V_142 < 0 ) {
F_77 ( V_141 , L_58
L_59 ,
V_140 ) ;
F_75 ( V_143 , V_26 ,
V_70 , V_3 , V_140 ,
V_43 , - 1 , - 1 ,
V_144 ,
L_60 ,
NULL ) ;
return;
}
} else {
V_142 = ( ( V_34 & F_51 ( 3 ) ) != 0 ) ;
}
F_75 ( V_143 , V_141 ,
V_70 , V_3 , V_140 ,
V_43 , V_142 , - 1 ,
V_144 , L_30 , NULL ) ;
}
static int F_78 ( unsigned V_21 , bool V_147 )
{
unsigned V_148 = 0 ;
if ( V_21 <= 2 )
V_148 = V_21 ;
else if ( ! ( V_21 & 0x1 ) )
V_148 = V_21 >> 1 ;
else
V_148 = ( V_21 + 1 ) >> 1 ;
return 128 << ( V_148 + ! ! V_147 ) ;
}
static int F_79 ( struct V_8 * V_9 , T_2 V_13 ,
unsigned V_149 )
{
T_1 V_78 = V_13 ? V_9 -> V_87 : V_9 -> V_76 ;
if ( V_9 -> V_51 >= V_52 ) {
F_72 ( V_149 > 11 ) ;
return F_78 ( V_149 , V_78 & V_112 ) ;
}
else if ( V_9 -> V_51 >= V_150 ) {
unsigned V_151 ;
F_72 ( V_149 > 10 ) ;
V_151 = V_149 / 3 + ( unsigned ) ( V_149 > 5 ) ;
return 32 << ( V_149 - V_151 ) ;
}
else {
F_72 ( V_149 > 6 ) ;
return 32 << V_149 ;
}
}
static int F_80 ( struct V_8 * V_9 )
{
int V_21 , V_152 , V_153 = 0 ;
if ( V_30 . V_31 == 0x10 && ( V_9 -> V_76 & V_112 ) )
return 2 ;
F_60 ( L_61 ) ;
for ( V_21 = 0 ; V_21 < 2 ; V_21 ++ ) {
T_1 V_154 = ( V_21 ? V_9 -> V_155 : V_9 -> V_156 ) ;
for ( V_152 = 0 ; V_152 < 4 ; V_152 ++ ) {
if ( F_81 ( V_152 , V_154 ) > 0 ) {
V_153 ++ ;
break;
}
}
}
if ( V_153 > 2 )
V_153 = 2 ;
F_55 ( L_62 , V_153 ) ;
return V_153 ;
}
static int F_82 ( unsigned V_21 , bool V_147 )
{
unsigned V_148 = 0 ;
int V_157 = 0 ;
if ( V_21 == 0 || V_21 == 3 || V_21 == 4 )
V_157 = - 1 ;
else if ( V_21 <= 2 )
V_148 = V_21 ;
else if ( V_21 == 12 )
V_148 = 7 ;
else if ( ! ( V_21 & 0x1 ) )
V_148 = V_21 >> 1 ;
else
V_148 = ( V_21 + 1 ) >> 1 ;
if ( V_157 != - 1 )
V_157 = ( 128 * ( 1 << ! ! V_147 ) ) << V_148 ;
return V_157 ;
}
static int F_83 ( struct V_8 * V_9 , T_2 V_13 ,
unsigned V_149 )
{
T_1 V_78 = V_13 ? V_9 -> V_87 : V_9 -> V_76 ;
F_72 ( V_149 > 11 ) ;
if ( V_9 -> V_104 & V_105 || V_9 -> V_158 & V_105 )
return F_82 ( V_149 , V_78 & V_112 ) ;
else
return F_78 ( V_149 , V_78 & V_112 ) ;
}
static int F_84 ( struct V_8 * V_9 , T_2 V_13 ,
unsigned V_149 )
{
F_72 ( V_149 > 12 ) ;
return F_82 ( V_149 , false ) ;
}
static void F_85 ( struct V_8 * V_9 )
{
if ( V_30 . V_31 == 0xf )
return;
if ( ! F_59 ( V_9 , V_159 , & V_9 -> V_160 ) ) {
F_60 ( L_63 ,
V_9 -> V_160 , F_86 ( V_9 ) ) ;
F_60 ( L_64 ,
( F_56 ( V_9 ) ? L_65 : L_66 ) ) ;
if ( ! F_56 ( V_9 ) )
F_60 ( L_67 ,
( F_87 ( V_9 ) ? L_31 : L_32 ) ) ;
F_60 ( L_68
L_69 ,
( F_88 ( V_9 ) ? L_34 : L_35 ) ,
( F_89 ( V_9 ) ? L_31 : L_32 ) ) ;
F_60 ( L_70
L_71 ,
( F_90 ( V_9 ) ? L_34 : L_35 ) ,
F_91 ( V_9 ) ) ;
}
F_59 ( V_9 , V_161 , & V_9 -> V_162 ) ;
}
static T_2 F_92 ( struct V_8 * V_9 , T_3 V_34 ,
bool V_163 , T_2 V_37 )
{
T_2 V_164 = ( V_9 -> V_160 >> 1 ) & 1 ;
if ( F_56 ( V_9 ) )
return 0 ;
if ( V_163 )
return V_164 ;
if ( F_90 ( V_9 ) ) {
T_2 V_165 = F_91 ( V_9 ) ;
if ( ! V_165 )
return V_34 >> 6 & 1 ;
if ( V_165 & 0x2 ) {
T_2 V_148 = V_165 & 0x1 ? 9 : 6 ;
T_1 V_166 = F_93 ( ( T_1 ) ( ( V_34 >> 16 ) & 0x1F ) ) % 2 ;
return ( ( V_34 >> V_148 ) & 1 ) ^ V_166 ;
}
return ( V_34 >> ( 12 + F_94 ( V_37 ) ) ) & 1 ;
}
if ( F_87 ( V_9 ) )
return ~ V_164 & 1 ;
return 0 ;
}
static T_3 F_95 ( struct V_8 * V_9 , unsigned V_128 ,
T_3 V_34 , bool V_167 ,
T_1 V_168 )
{
T_3 V_169 ;
T_3 V_62 = F_19 ( V_9 , V_128 ) ;
T_3 V_170 = F_37 ( V_9 ) ;
T_3 V_171 = ( V_9 -> V_162 & 0xFFFFFC00 ) << 16 ;
if ( V_167 ) {
if ( ( ! ( V_168 >> 16 ) ||
V_168 < F_36 ( V_9 ) ) &&
F_35 ( V_9 ) &&
( V_34 >= F_96 ( 32 ) ) )
V_169 = V_170 ;
else
V_169 = V_171 ;
} else {
if ( F_35 ( V_9 ) && ( V_34 >= F_96 ( 32 ) ) )
V_169 = V_170 ;
else
V_169 = V_62 ;
}
return ( V_34 & F_28 ( 6 , 47 ) ) - ( V_169 & F_28 ( 23 , 47 ) ) ;
}
static int F_97 ( struct V_8 * V_9 , T_2 V_13 , int V_43 )
{
int V_172 ;
if ( F_98 ( V_9 , V_13 ) &&
V_43 == F_99 ( V_9 , V_13 ) ) {
F_30 (tmp_cs, dct, pvt) {
if ( F_100 ( V_172 , V_13 , V_9 ) & 0x2 ) {
V_43 = V_172 ;
break;
}
}
}
return V_43 ;
}
static int F_101 ( T_3 V_173 , T_1 V_35 , T_2 V_13 )
{
struct V_25 * V_26 ;
struct V_8 * V_9 ;
T_3 V_174 , V_175 ;
int V_176 = - V_11 ;
int V_43 ;
V_26 = V_125 [ V_35 ] ;
if ( ! V_26 )
return V_176 ;
V_9 = V_26 -> V_28 ;
F_33 ( L_72 , V_173 , V_13 ) ;
F_30 (csrow, dct, pvt) {
if ( ! F_31 ( V_43 , V_13 , V_9 ) )
continue;
F_27 ( V_9 , V_43 , V_13 , & V_174 , & V_175 ) ;
F_33 ( L_73 ,
V_43 , V_174 , V_175 ) ;
V_175 = ~ V_175 ;
F_33 ( L_74
L_75 ,
( V_173 & V_175 ) , ( V_174 & V_175 ) ) ;
if ( ( V_173 & V_175 ) == ( V_174 & V_175 ) ) {
V_176 = F_97 ( V_9 , V_13 , V_43 ) ;
F_33 ( L_76 , V_176 ) ;
break;
}
}
return V_176 ;
}
static T_3 F_102 ( struct V_8 * V_9 , T_3 V_34 )
{
T_1 V_177 , V_178 , V_179 , V_180 , V_121 ;
if ( V_30 . V_31 == 0x10 ) {
if ( V_30 . V_181 < 4 ||
( V_30 . V_181 < 0xa &&
V_30 . V_182 < 3 ) )
return V_34 ;
}
F_59 ( V_9 , V_183 , & V_177 ) ;
if ( ! ( V_177 & 0x1 ) )
return V_34 ;
V_178 = ( V_177 >> 3 ) & 0x7f ;
V_179 = ( V_177 >> 11 ) & 0x7f ;
V_180 = ( V_177 >> 20 ) & 0x7f ;
V_121 = V_34 >> 27 ;
if ( ! ( V_34 >> 34 ) &&
( ( ( V_121 >= V_178 ) &&
( V_121 <= V_179 ) ) ||
( V_121 < V_180 ) ) )
return V_34 ^ ( T_3 ) V_178 << 27 ;
return V_34 ;
}
static int F_103 ( struct V_8 * V_9 , unsigned V_128 ,
T_3 V_34 , int * V_35 , int * V_184 )
{
int V_176 = - V_11 ;
T_3 V_185 ;
T_1 V_186 ;
T_2 V_142 ;
bool V_187 = false ;
T_2 V_36 = F_69 ( V_9 , V_128 ) ;
T_2 V_37 = F_22 ( V_9 , V_128 ) ;
T_1 V_68 = F_24 ( V_9 , V_128 ) ;
F_33 ( L_77 ,
V_128 , V_34 , F_20 ( V_9 , V_128 ) ) ;
if ( F_35 ( V_9 ) &&
F_36 ( V_9 ) <= V_34 &&
V_34 < F_96 ( 32 ) ) {
F_3 ( L_78 ,
V_34 ) ;
return - V_11 ;
}
if ( V_37 && ( V_68 != ( ( V_34 >> 12 ) & V_37 ) ) )
return - V_11 ;
V_34 = F_102 ( V_9 , V_34 ) ;
V_186 = F_86 ( V_9 ) ;
if ( F_87 ( V_9 ) &&
! F_56 ( V_9 ) &&
( ( V_34 >> 27 ) >= ( V_186 >> 11 ) ) )
V_187 = true ;
V_142 = F_92 ( V_9 , V_34 , V_187 , V_37 ) ;
V_185 = F_95 ( V_9 , V_128 , V_34 ,
V_187 , V_186 ) ;
if ( V_37 )
V_185 = ( ( V_185 >> ( 12 + F_94 ( V_37 ) ) ) << 12 ) |
( V_185 & 0xfff ) ;
if ( F_90 ( V_9 ) &&
! F_87 ( V_9 ) &&
! F_56 ( V_9 ) ) {
if ( F_91 ( V_9 ) != 1 ) {
if ( F_91 ( V_9 ) == 0x3 )
V_185 = ( ( V_185 >> 10 ) << 9 ) |
( V_185 & 0x1ff ) ;
else
V_185 = ( ( V_185 >> 7 ) << 6 ) |
( V_185 & 0x3f ) ;
} else
V_185 = ( ( V_185 >> 13 ) << 12 ) |
( V_185 & 0xfff ) ;
}
F_33 ( L_79 , V_185 ) ;
V_176 = F_101 ( V_185 , V_36 , V_142 ) ;
if ( V_176 >= 0 ) {
* V_35 = V_36 ;
* V_184 = V_142 ;
}
return V_176 ;
}
static int F_104 ( struct V_8 * V_9 , T_3 V_34 ,
int * V_188 , int * V_184 )
{
int V_176 = - V_11 ;
unsigned V_128 ;
for ( V_128 = 0 ; V_128 < V_39 ; V_128 ++ ) {
if ( ! F_68 ( V_9 , V_128 ) )
continue;
if ( ( F_19 ( V_9 , V_128 ) <= V_34 ) &&
( F_20 ( V_9 , V_128 ) >= V_34 ) ) {
V_176 = F_103 ( V_9 , V_128 ,
V_34 , V_188 ,
V_184 ) ;
if ( V_176 >= 0 )
break;
}
}
return V_176 ;
}
static void F_105 ( struct V_25 * V_26 , T_3 V_34 ,
T_4 V_140 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
T_1 V_70 , V_3 ;
int V_35 , V_43 , V_79 = 0 ;
F_47 ( V_34 , & V_70 , & V_3 ) ;
V_43 = F_104 ( V_9 , V_34 , & V_35 , & V_79 ) ;
if ( V_43 < 0 ) {
F_75 ( V_143 , V_26 ,
V_70 , V_3 , V_140 ,
- 1 , - 1 , - 1 ,
V_144 ,
L_57 ,
NULL ) ;
return;
}
if ( F_56 ( V_9 ) )
V_79 = F_76 ( V_26 , V_140 ) ;
F_75 ( V_143 , V_26 ,
V_70 , V_3 , V_140 ,
V_43 , V_79 , - 1 ,
V_144 , L_30 , NULL ) ;
}
static void F_54 ( struct V_8 * V_9 , T_2 V_189 )
{
int V_190 , V_191 , V_192 , V_193 = 0 ;
T_1 * V_194 = V_189 ? V_9 -> V_53 [ 1 ] . V_54 : V_9 -> V_53 [ 0 ] . V_54 ;
T_1 V_154 = V_189 ? V_9 -> V_155 : V_9 -> V_156 ;
if ( V_30 . V_31 == 0xf ) {
if ( V_9 -> V_76 & V_112 )
V_193 = 1 ;
if ( V_9 -> V_51 < V_52 )
return;
else
F_72 ( V_189 != 0 ) ;
}
V_154 = ( V_189 && ! F_56 ( V_9 ) ) ? V_9 -> V_155 : V_9 -> V_156 ;
V_194 = ( V_189 && ! F_56 ( V_9 ) ) ? V_9 -> V_53 [ 1 ] . V_54
: V_9 -> V_53 [ 0 ] . V_54 ;
F_33 ( L_80 , V_189 , V_154 ) ;
F_106 ( V_195 , V_196 , L_81 , V_189 ) ;
for ( V_190 = 0 ; V_190 < 4 ; V_190 ++ ) {
V_191 = 0 ;
if ( V_194 [ V_190 * 2 ] & V_197 )
V_191 = V_9 -> V_198 -> V_199 ( V_9 , V_189 ,
F_81 ( V_190 , V_154 ) ) ;
V_192 = 0 ;
if ( V_194 [ V_190 * 2 + 1 ] & V_197 )
V_192 = V_9 -> V_198 -> V_199 ( V_9 , V_189 ,
F_81 ( V_190 , V_154 ) ) ;
F_55 ( V_196 L_82 ,
V_190 * 2 , V_191 << V_193 ,
V_190 * 2 + 1 , V_192 << V_193 ) ;
}
}
static struct V_1 * F_107 ( unsigned int V_200 ,
unsigned int V_201 ,
struct V_1 * V_202 )
{
struct V_1 * V_203 = NULL ;
V_203 = F_108 ( V_200 , V_201 , V_203 ) ;
while ( V_203 ) {
if ( ( V_203 -> V_204 -> V_205 == V_202 -> V_204 -> V_205 ) &&
( F_109 ( V_203 -> V_7 ) == F_109 ( V_202 -> V_7 ) ) )
break;
V_203 = F_108 ( V_200 , V_201 , V_203 ) ;
}
return V_203 ;
}
static int F_110 ( T_4 V_140 , T_4 * V_206 , unsigned V_207 ,
unsigned V_208 )
{
unsigned int V_21 , V_209 ;
for ( V_209 = 0 ; V_209 < V_207 / V_208 ; V_209 ++ ) {
T_4 V_210 = V_140 ;
unsigned V_211 = V_209 * V_208 ;
unsigned V_212 = ( V_209 + 1 ) * V_208 ;
for ( V_21 = 1 ; V_21 < ( 1U << 16 ) ; V_21 <<= 1 ) {
if ( V_211 < V_212 && V_206 [ V_211 ] & V_21 ) {
T_4 V_213 = V_206 [ V_211 ++ ] ;
if ( V_210 & V_21 ) {
V_210 ^= V_213 ;
if ( ! V_210 )
return V_209 ;
}
} else if ( V_210 & V_21 )
break;
}
}
F_60 ( L_83 , V_140 ) ;
return - 1 ;
}
static int F_111 ( int V_209 , int V_214 )
{
if ( V_214 == 4 )
switch ( V_209 ) {
case 0x20 :
case 0x21 :
return 0 ;
break;
case 0x22 :
case 0x23 :
return 1 ;
break;
default:
return V_209 >> 4 ;
break;
}
else
switch ( V_209 ) {
case 0x10 :
F_112 ( 1 , V_215 L_84 ,
V_209 ) ;
return - 1 ;
break;
case 0x11 :
return 0 ;
break;
case 0x12 :
return 1 ;
break;
default:
return V_209 >> 3 ;
break;
}
return - 1 ;
}
static int F_76 ( struct V_25 * V_26 , T_4 V_140 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
int V_209 = - 1 ;
if ( V_9 -> V_86 == 8 )
V_209 = F_110 ( V_140 , V_216 ,
F_14 ( V_216 ) ,
V_9 -> V_86 ) ;
else if ( V_9 -> V_86 == 4 )
V_209 = F_110 ( V_140 , V_217 ,
F_14 ( V_217 ) ,
V_9 -> V_86 ) ;
else {
F_3 ( L_85 , V_9 -> V_86 ) ;
return V_209 ;
}
return F_111 ( V_209 , V_9 -> V_86 ) ;
}
static void F_113 ( struct V_25 * V_26 , struct V_114 * V_115 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
T_3 V_34 ;
T_4 V_140 ;
if ( ! ( V_115 -> V_218 & V_219 ) ) {
F_49 ( V_26 , L_86 ) ;
F_75 ( V_143 , V_26 ,
0 , 0 , 0 ,
- 1 , - 1 , - 1 ,
V_144 ,
L_87 ,
NULL ) ;
return;
}
V_34 = F_64 ( V_115 ) ;
V_140 = F_114 ( V_115 -> V_218 ) ;
F_49 ( V_26 , L_88 , V_34 ) ;
V_9 -> V_198 -> V_220 ( V_26 , V_34 , V_140 ) ;
}
static void F_115 ( struct V_25 * V_26 , struct V_114 * V_115 )
{
struct V_25 * V_221 , * V_141 = NULL ;
int V_43 ;
T_3 V_34 ;
T_1 V_70 , V_3 ;
V_221 = V_26 ;
if ( ! ( V_115 -> V_218 & V_219 ) ) {
F_49 ( V_26 , L_86 ) ;
F_75 ( V_222 , V_26 ,
0 , 0 , 0 ,
- 1 , - 1 , - 1 ,
V_144 ,
L_87 ,
NULL ) ;
return;
}
V_34 = F_64 ( V_115 ) ;
F_47 ( V_34 , & V_70 , & V_3 ) ;
V_141 = F_21 ( V_26 , V_34 ) ;
if ( ! V_141 ) {
F_49 ( V_26 , L_89 ,
( unsigned long ) V_34 ) ;
F_75 ( V_222 , V_26 ,
V_70 , V_3 , 0 ,
- 1 , - 1 , - 1 ,
V_144 ,
L_90 , NULL ) ;
return;
}
V_221 = V_141 ;
V_43 = F_48 ( V_221 , V_34 ) ;
if ( V_43 < 0 ) {
F_49 ( V_26 , L_91 ,
( unsigned long ) V_34 ) ;
F_75 ( V_222 , V_26 ,
V_70 , V_3 , 0 ,
- 1 , - 1 , - 1 ,
V_144 ,
L_92 ,
NULL ) ;
} else {
F_75 ( V_222 , V_26 ,
V_70 , V_3 , 0 ,
V_43 , - 1 , - 1 ,
V_144 , L_30 , NULL ) ;
}
}
static inline void F_116 ( struct V_25 * V_26 ,
struct V_114 * V_115 )
{
T_4 V_223 = F_117 ( V_115 -> V_218 ) ;
T_2 V_224 = F_118 ( V_115 -> V_218 , 0x1f ) ;
T_2 V_225 = ( V_115 -> V_218 >> 45 ) & 0x3 ;
if ( F_119 ( V_223 ) == V_226 )
return;
if ( V_224 && V_224 != V_227 )
return;
if ( V_225 == 2 )
F_113 ( V_26 , V_115 ) ;
else if ( V_225 == 1 )
F_115 ( V_26 , V_115 ) ;
}
void F_120 ( int V_36 , struct V_114 * V_115 )
{
F_116 ( V_125 [ V_36 ] , V_115 ) ;
}
static int F_121 ( struct V_8 * V_9 , T_4 V_228 , T_4 V_229 )
{
V_9 -> V_15 = F_107 ( V_9 -> V_12 -> V_200 , V_228 , V_9 -> V_12 ) ;
if ( ! V_9 -> V_15 ) {
F_122 ( L_93
L_94 ,
V_230 , V_228 ) ;
return - V_231 ;
}
V_9 -> V_32 = F_107 ( V_9 -> V_12 -> V_200 , V_229 , V_9 -> V_12 ) ;
if ( ! V_9 -> V_32 ) {
F_73 ( V_9 -> V_15 ) ;
V_9 -> V_15 = NULL ;
F_122 ( L_95
L_94 ,
V_230 , V_229 ) ;
return - V_231 ;
}
F_33 ( L_96 , F_123 ( V_9 -> V_15 ) ) ;
F_33 ( L_97 , F_123 ( V_9 -> V_12 ) ) ;
F_33 ( L_98 , F_123 ( V_9 -> V_32 ) ) ;
return 0 ;
}
static void F_124 ( struct V_8 * V_9 )
{
F_73 ( V_9 -> V_15 ) ;
F_73 ( V_9 -> V_32 ) ;
}
static void F_125 ( struct V_8 * V_9 )
{
struct V_116 * V_117 = & V_30 ;
T_3 V_232 ;
T_1 V_122 ;
unsigned V_128 ;
F_126 ( V_233 , V_9 -> V_234 ) ;
F_60 ( L_99 , V_9 -> V_234 ) ;
F_126 ( V_235 , V_232 ) ;
if ( V_232 & ( 1U << 21 ) ) {
F_126 ( V_236 , V_9 -> V_237 ) ;
F_60 ( L_100 , V_9 -> V_237 ) ;
} else
F_60 ( L_101 ) ;
F_10 ( V_9 -> V_32 , V_238 , & V_9 -> V_80 ) ;
F_85 ( V_9 ) ;
for ( V_128 = 0 ; V_128 < V_39 ; V_128 ++ ) {
T_2 V_239 ;
F_67 ( V_9 , V_128 ) ;
V_239 = F_68 ( V_9 , V_128 ) ;
if ( ! V_239 )
continue;
F_33 ( L_102 ,
V_128 ,
F_19 ( V_9 , V_128 ) ,
F_20 ( V_9 , V_128 ) ) ;
F_33 ( L_103 ,
F_22 ( V_9 , V_128 ) ? L_104 : L_105 ,
( V_239 & 0x1 ) ? L_106 : L_107 ,
( V_239 & 0x2 ) ? L_108 : L_107 ,
F_24 ( V_9 , V_128 ) ,
F_69 ( V_9 , V_128 ) ) ;
}
F_58 ( V_9 ) ;
F_10 ( V_9 -> V_15 , V_240 , & V_9 -> V_85 ) ;
F_59 ( V_9 , V_241 , & V_9 -> V_156 ) ;
F_10 ( V_9 -> V_32 , V_242 , & V_9 -> V_84 ) ;
F_59 ( V_9 , V_243 , & V_9 -> V_76 ) ;
F_59 ( V_9 , V_244 , & V_9 -> V_104 ) ;
if ( ! F_56 ( V_9 ) ) {
F_59 ( V_9 , V_245 , & V_9 -> V_87 ) ;
F_59 ( V_9 , V_246 , & V_9 -> V_158 ) ;
}
V_9 -> V_86 = 4 ;
if ( V_117 -> V_31 >= 0x10 ) {
F_10 ( V_9 -> V_32 , V_247 , & V_122 ) ;
F_59 ( V_9 , V_248 , & V_9 -> V_155 ) ;
if ( ( V_117 -> V_31 > 0x10 || V_117 -> V_181 > 7 ) && V_122 & F_51 ( 25 ) )
V_9 -> V_86 = 8 ;
}
F_53 ( V_9 ) ;
}
static T_1 F_127 ( struct V_8 * V_9 , T_2 V_13 , int V_249 )
{
T_1 V_149 , V_250 ;
T_1 V_154 = V_13 ? V_9 -> V_155 : V_9 -> V_156 ;
V_149 = ( V_154 >> ( ( V_249 / 2 ) * 4 ) ) & 0xF ;
V_250 = V_9 -> V_198 -> V_199 ( V_9 , V_13 , V_149 ) << ( 20 - V_71 ) ;
F_60 ( L_109 , V_249 , V_149 ) ;
F_60 ( L_110 ,
V_250 , V_9 -> V_251 ) ;
return V_250 ;
}
static int F_128 ( struct V_25 * V_26 )
{
struct V_252 * V_43 ;
struct V_8 * V_9 = V_26 -> V_28 ;
T_3 V_44 , V_45 ;
T_1 V_4 ;
int V_21 , V_152 , V_253 = 1 ;
enum V_101 V_254 ;
enum V_255 V_256 ;
int V_250 = 0 ;
F_10 ( V_9 -> V_32 , V_257 , & V_4 ) ;
V_9 -> V_145 = V_4 ;
F_60 ( L_111 ,
V_9 -> V_57 , V_4 ,
! ! ( V_4 & V_146 ) , ! ! ( V_4 & V_258 ) ) ;
F_30 (i, 0 , pvt) {
V_43 = & V_26 -> V_259 [ V_21 ] ;
if ( ! F_31 ( V_21 , 0 , V_9 ) && ! F_31 ( V_21 , 1 , V_9 ) ) {
F_33 ( L_112 , V_21 ,
V_9 -> V_57 ) ;
continue;
}
F_33 ( L_113 ,
V_21 , V_9 -> V_57 ) ;
V_253 = 0 ;
if ( F_31 ( V_21 , 0 , V_9 ) )
V_250 = F_127 ( V_9 , 0 , V_21 ) ;
if ( F_31 ( V_21 , 1 , V_9 ) )
V_250 += F_127 ( V_9 , 1 , V_21 ) ;
F_27 ( V_9 , V_21 , 0 , & V_44 , & V_45 ) ;
V_254 = F_62 ( V_9 , V_21 ) ;
F_33 ( L_114 , V_9 -> V_57 , V_21 ) ;
F_33 ( L_115 , V_250 * V_9 -> V_251 ) ;
if ( V_9 -> V_145 & V_258 )
V_256 = ( V_9 -> V_145 & V_146 ) ?
V_260 : V_261 ;
else
V_256 = V_262 ;
for ( V_152 = 0 ; V_152 < V_9 -> V_251 ; V_152 ++ ) {
V_43 -> V_153 [ V_152 ] . V_190 -> V_254 = V_254 ;
V_43 -> V_153 [ V_152 ] . V_190 -> V_256 = V_256 ;
V_43 -> V_153 [ V_152 ] . V_190 -> V_250 = V_250 ;
}
}
return V_253 ;
}
static void F_129 ( struct V_263 * V_45 , unsigned V_35 )
{
int V_264 ;
F_130 (cpu)
if ( F_65 ( V_264 ) == V_35 )
F_131 ( V_264 , V_45 ) ;
}
static bool F_132 ( unsigned V_35 )
{
T_5 V_45 ;
int V_264 , V_265 ;
bool V_64 = false ;
if ( ! F_133 ( & V_45 , V_266 ) ) {
F_3 ( L_116 , V_42 ) ;
return false ;
}
F_129 ( V_45 , V_35 ) ;
F_134 ( V_45 , V_267 , V_268 ) ;
F_135 (cpu, mask) {
struct V_269 * V_14 = F_136 ( V_268 , V_264 ) ;
V_265 = V_14 -> V_270 & V_271 ;
F_60 ( L_117 ,
V_264 , V_14 -> V_272 ,
( V_265 ? L_34 : L_35 ) ) ;
if ( ! V_265 )
goto V_273;
}
V_64 = true ;
V_273:
F_137 ( V_45 ) ;
return V_64 ;
}
static int F_138 ( struct V_274 * V_210 , T_2 V_35 , bool V_275 )
{
T_5 V_276 ;
int V_264 ;
if ( ! F_133 ( & V_276 , V_266 ) ) {
F_3 ( L_118 , V_42 ) ;
return false ;
}
F_129 ( V_276 , V_35 ) ;
F_134 ( V_276 , V_267 , V_268 ) ;
F_135 (cpu, cmask) {
struct V_269 * V_14 = F_136 ( V_268 , V_264 ) ;
if ( V_275 ) {
if ( V_14 -> V_270 & V_271 )
V_210 -> V_277 . V_278 = 1 ;
V_14 -> V_270 |= V_271 ;
} else {
if ( ! V_210 -> V_277 . V_278 )
V_14 -> V_270 &= ~ V_271 ;
}
}
F_139 ( V_276 , V_267 , V_268 ) ;
F_137 ( V_276 ) ;
return 0 ;
}
static bool F_140 ( struct V_274 * V_210 , T_2 V_35 ,
struct V_1 * V_32 )
{
bool V_64 = true ;
T_1 V_279 , V_45 = 0x3 ;
if ( F_138 ( V_210 , V_35 , V_280 ) ) {
F_3 ( L_119 ) ;
return false ;
}
F_10 ( V_32 , V_281 , & V_279 ) ;
V_210 -> V_282 = V_279 & V_45 ;
V_210 -> V_283 = true ;
V_279 |= V_45 ;
F_11 ( V_32 , V_281 , V_279 ) ;
F_10 ( V_32 , V_257 , & V_279 ) ;
F_60 ( L_120 ,
V_35 , V_279 , ! ! ( V_279 & V_258 ) ) ;
if ( ! ( V_279 & V_258 ) ) {
F_3 ( L_121 ) ;
V_210 -> V_277 . V_284 = 0 ;
V_279 |= V_258 ;
F_11 ( V_32 , V_257 , V_279 ) ;
F_10 ( V_32 , V_257 , & V_279 ) ;
if ( ! ( V_279 & V_258 ) ) {
F_3 ( L_122
L_123 ) ;
V_64 = false ;
} else {
F_55 ( L_124 ) ;
}
} else {
V_210 -> V_277 . V_284 = 1 ;
}
F_60 ( L_125 ,
V_35 , V_279 , ! ! ( V_279 & V_258 ) ) ;
return V_64 ;
}
static void F_141 ( struct V_274 * V_210 , T_2 V_35 ,
struct V_1 * V_32 )
{
T_1 V_279 , V_45 = 0x3 ;
if ( ! V_210 -> V_283 )
return;
F_10 ( V_32 , V_281 , & V_279 ) ;
V_279 &= ~ V_45 ;
V_279 |= V_210 -> V_282 ;
F_11 ( V_32 , V_281 , V_279 ) ;
if ( ! V_210 -> V_277 . V_284 ) {
F_10 ( V_32 , V_257 , & V_279 ) ;
V_279 &= ~ V_258 ;
F_11 ( V_32 , V_257 , V_279 ) ;
}
if ( F_138 ( V_210 , V_35 , V_285 ) )
F_3 ( L_126 ) ;
}
static bool F_142 ( struct V_1 * V_32 , T_2 V_35 )
{
T_1 V_279 ;
T_2 V_286 = 0 ;
bool V_287 = false ;
F_10 ( V_32 , V_257 , & V_279 ) ;
V_286 = ! ! ( V_279 & V_258 ) ;
F_55 ( L_127 , ( V_286 ? L_34 : L_35 ) ) ;
V_287 = F_132 ( V_35 ) ;
if ( ! V_287 )
F_143 ( L_128
L_129 ,
V_267 , V_35 ) ;
if ( ! V_286 || ! V_287 ) {
F_143 ( L_130 , V_288 ) ;
return false ;
}
return true ;
}
static void F_144 ( struct V_25 * V_26 )
{
unsigned int V_21 = 0 , V_152 = 0 ;
for (; V_21 < F_14 ( V_289 ) ; V_21 ++ )
V_290 [ V_21 ] = V_289 [ V_21 ] ;
if ( V_30 . V_31 >= 0x10 )
for ( V_152 = 0 ; V_152 < F_14 ( V_291 ) ; V_152 ++ , V_21 ++ )
V_290 [ V_21 ] = V_291 [ V_152 ] ;
V_290 [ V_21 ] = V_292 ;
V_26 -> V_293 = V_290 ;
}
static void F_145 ( struct V_25 * V_26 ,
struct V_294 * V_295 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
V_26 -> V_296 = V_297 | V_298 ;
V_26 -> V_299 = V_75 ;
if ( V_9 -> V_80 & V_82 )
V_26 -> V_299 |= V_77 ;
if ( V_9 -> V_80 & V_83 )
V_26 -> V_299 |= V_300 ;
V_26 -> V_74 = F_50 ( V_9 ) ;
V_26 -> V_301 = V_144 ;
V_26 -> V_302 = V_303 ;
V_26 -> V_304 = V_295 -> V_304 ;
V_26 -> V_305 = F_123 ( V_9 -> V_12 ) ;
V_26 -> V_306 = NULL ;
V_26 -> V_307 = F_16 ;
V_26 -> V_308 = F_17 ;
}
static struct V_294 * F_146 ( struct V_8 * V_9 )
{
T_2 V_295 = V_30 . V_31 ;
struct V_294 * V_309 = NULL ;
switch ( V_295 ) {
case 0xf :
V_309 = & V_310 [ V_311 ] ;
V_9 -> V_198 = & V_310 [ V_311 ] . V_198 ;
break;
case 0x10 :
V_309 = & V_310 [ V_312 ] ;
V_9 -> V_198 = & V_310 [ V_312 ] . V_198 ;
break;
case 0x15 :
V_309 = & V_310 [ V_313 ] ;
V_9 -> V_198 = & V_310 [ V_313 ] . V_198 ;
break;
default:
F_122 ( L_131 ) ;
return NULL ;
}
V_9 -> V_51 = V_30 . V_181 >> 4 ;
F_55 ( L_132 , V_309 -> V_304 ,
( V_295 == 0xf ?
( V_9 -> V_51 >= V_52 ? L_133
: L_134 )
: L_30 ) , V_9 -> V_57 ) ;
return V_309 ;
}
static int F_147 ( struct V_1 * V_12 )
{
struct V_8 * V_9 = NULL ;
struct V_294 * V_309 = NULL ;
struct V_25 * V_26 = NULL ;
struct V_314 V_315 [ 2 ] ;
int V_6 = 0 , V_64 ;
T_2 V_35 = F_148 ( V_12 ) ;
V_64 = - V_316 ;
V_9 = F_149 ( sizeof( struct V_8 ) , V_266 ) ;
if ( ! V_9 )
goto V_317;
V_9 -> V_57 = V_35 ;
V_9 -> V_12 = V_12 ;
V_64 = - V_11 ;
V_309 = F_146 ( V_9 ) ;
if ( ! V_309 )
goto V_318;
V_64 = - V_231 ;
V_6 = F_121 ( V_9 , V_309 -> V_228 , V_309 -> V_229 ) ;
if ( V_6 )
goto V_318;
F_125 ( V_9 ) ;
V_64 = - V_11 ;
V_9 -> V_251 = V_9 -> V_198 -> V_319 ( V_9 ) ;
if ( V_9 -> V_251 < 0 )
goto V_320;
V_64 = - V_316 ;
V_315 [ 0 ] . type = V_321 ;
V_315 [ 0 ] . V_322 = V_9 -> V_53 [ 0 ] . V_88 ;
V_315 [ 0 ] . V_323 = true ;
V_315 [ 1 ] . type = V_324 ;
V_315 [ 1 ] . V_322 = V_9 -> V_251 ;
V_315 [ 1 ] . V_323 = false ;
V_26 = F_150 ( V_35 , F_14 ( V_315 ) , V_315 , 0 ) ;
if ( ! V_26 )
goto V_320;
V_26 -> V_28 = V_9 ;
V_26 -> V_203 = & V_9 -> V_12 -> V_203 ;
F_145 ( V_26 , V_309 ) ;
if ( F_128 ( V_26 ) )
V_26 -> V_74 = V_75 ;
F_144 ( V_26 ) ;
V_64 = - V_231 ;
if ( F_151 ( V_26 ) ) {
F_33 ( L_135 ) ;
goto V_325;
}
if ( V_326 )
F_152 ( true ) ;
F_153 ( F_120 ) ;
V_125 [ V_35 ] = V_26 ;
F_154 ( & V_327 ) ;
return 0 ;
V_325:
F_155 ( V_26 ) ;
V_320:
F_124 ( V_9 ) ;
V_318:
F_156 ( V_9 ) ;
V_317:
return V_64 ;
}
static int T_6 F_157 ( struct V_1 * V_2 ,
const struct V_328 * V_329 )
{
T_2 V_35 = F_148 ( V_2 ) ;
struct V_1 * V_32 = F_158 ( V_35 ) -> V_330 ;
struct V_274 * V_210 ;
int V_64 = 0 ;
V_64 = F_159 ( V_2 ) ;
if ( V_64 < 0 ) {
F_60 ( L_136 , V_64 ) ;
return - V_331 ;
}
V_64 = - V_316 ;
V_210 = F_149 ( sizeof( struct V_274 ) , V_266 ) ;
if ( ! V_210 )
goto V_332;
V_333 [ V_35 ] = V_210 ;
if ( ! F_142 ( V_32 , V_35 ) ) {
V_64 = - V_231 ;
if ( ! V_334 )
goto V_335;
F_3 ( L_137 ) ;
if ( ! F_140 ( V_210 , V_35 , V_32 ) )
goto V_335;
}
V_64 = F_147 ( V_2 ) ;
if ( V_64 < 0 ) {
F_122 ( L_138 , V_35 ) ;
F_141 ( V_210 , V_35 , V_32 ) ;
}
return V_64 ;
V_335:
F_156 ( V_210 ) ;
V_333 [ V_35 ] = NULL ;
V_332:
return V_64 ;
}
static void T_7 F_160 ( struct V_1 * V_2 )
{
struct V_25 * V_26 ;
struct V_8 * V_9 ;
T_2 V_35 = F_148 ( V_2 ) ;
struct V_1 * V_32 = F_158 ( V_35 ) -> V_330 ;
struct V_274 * V_210 = V_333 [ V_35 ] ;
V_26 = F_161 ( & V_2 -> V_203 ) ;
if ( ! V_26 )
return;
V_9 = V_26 -> V_28 ;
F_141 ( V_210 , V_35 , V_32 ) ;
F_124 ( V_9 ) ;
F_152 ( false ) ;
F_162 ( F_120 ) ;
F_156 ( V_333 [ V_35 ] ) ;
V_333 [ V_35 ] = NULL ;
V_26 -> V_28 = NULL ;
V_125 [ V_35 ] = NULL ;
F_156 ( V_9 ) ;
F_155 ( V_26 ) ;
}
static void F_163 ( void )
{
struct V_25 * V_26 ;
struct V_8 * V_9 ;
if ( V_336 )
return;
V_26 = V_125 [ 0 ] ;
if ( V_26 ) {
V_9 = V_26 -> V_28 ;
V_336 =
F_164 ( & V_9 -> V_12 -> V_203 , V_144 ) ;
if ( ! V_336 ) {
F_165 ( L_139 ,
V_42 ) ;
F_165 ( L_140 ,
V_42 ) ;
}
}
}
static int T_8 F_166 ( void )
{
int V_6 = - V_231 ;
F_167 ( V_337 L_141 , V_303 ) ;
F_168 () ;
if ( F_169 () < 0 )
goto V_317;
V_6 = - V_316 ;
V_125 = F_149 ( F_170 () * sizeof( V_125 [ 0 ] ) , V_266 ) ;
V_333 = F_149 ( F_170 () * sizeof( V_333 [ 0 ] ) , V_266 ) ;
if ( ! ( V_125 && V_333 ) )
goto V_318;
V_268 = F_171 () ;
if ( ! V_268 )
goto V_318;
V_6 = F_172 ( & V_338 ) ;
if ( V_6 )
goto V_339;
V_6 = - V_231 ;
if ( ! F_173 ( & V_327 ) )
goto V_340;
F_163 () ;
return 0 ;
V_340:
F_174 ( & V_338 ) ;
V_339:
F_175 ( V_268 ) ;
V_268 = NULL ;
V_318:
F_156 ( V_125 ) ;
V_125 = NULL ;
F_156 ( V_333 ) ;
V_333 = NULL ;
V_317:
return V_6 ;
}
static void T_9 F_176 ( void )
{
if ( V_336 )
F_177 ( V_336 ) ;
F_174 ( & V_338 ) ;
F_156 ( V_333 ) ;
V_333 = NULL ;
F_156 ( V_125 ) ;
V_125 = NULL ;
F_175 ( V_268 ) ;
V_268 = NULL ;
}
