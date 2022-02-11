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
static int F_9 ( struct V_8 * V_9 , int V_10 , T_1 * V_4 ,
const char * V_5 )
{
T_1 V_13 = 0 ;
T_2 V_14 = 0 ;
if ( V_10 >= 0x140 && V_10 <= 0x1a0 ) {
V_14 = 1 ;
V_10 -= 0x100 ;
}
F_10 ( V_9 -> V_15 , V_16 , & V_13 ) ;
V_13 &= 0xfffffffe ;
V_13 |= V_14 ;
F_11 ( V_9 -> V_15 , V_16 , V_13 ) ;
return F_1 ( V_9 -> V_12 , V_10 , V_4 , V_5 ) ;
}
static int F_12 ( struct V_1 * V_17 , T_1 V_18 , T_1 V_19 )
{
T_1 V_20 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < F_13 ( V_22 ) ; V_21 ++ ) {
if ( V_22 [ V_21 ] . V_20 < V_19 )
continue;
if ( V_22 [ V_21 ] . V_23 <= V_18 )
break;
}
V_20 = V_22 [ V_21 ] . V_20 ;
F_14 ( V_17 , V_24 , V_20 , 0x001F ) ;
if ( V_20 )
return V_22 [ V_21 ] . V_23 ;
return 0 ;
}
static int F_15 ( struct V_25 * V_26 , T_1 V_27 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
T_1 V_29 = 0x5 ;
if ( V_30 . V_31 == 0xf )
V_29 = 0x0 ;
return F_12 ( V_9 -> V_32 , V_27 , V_29 ) ;
}
static int F_16 ( struct V_25 * V_26 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
T_1 V_20 = 0 ;
int V_21 , V_33 = - V_11 ;
F_10 ( V_9 -> V_32 , V_24 , & V_20 ) ;
V_20 = V_20 & 0x001F ;
for ( V_21 = 0 ; V_21 < F_13 ( V_22 ) ; V_21 ++ ) {
if ( V_22 [ V_21 ] . V_20 == V_20 ) {
V_33 = V_22 [ V_21 ] . V_23 ;
break;
}
}
return V_33 ;
}
static bool F_17 ( struct V_8 * V_9 , T_3 V_34 ,
unsigned V_35 )
{
T_3 V_10 ;
V_10 = V_34 & 0x000000ffffffffffull ;
return ( ( V_10 >= F_18 ( V_9 , V_35 ) ) &&
( V_10 <= F_19 ( V_9 , V_35 ) ) ) ;
}
static struct V_25 * F_20 ( struct V_25 * V_26 ,
T_3 V_34 )
{
struct V_8 * V_9 ;
unsigned V_36 ;
T_1 V_37 , V_38 ;
V_9 = V_26 -> V_28 ;
V_37 = F_21 ( V_9 , 0 ) ;
if ( V_37 == 0 ) {
for ( V_36 = 0 ; V_36 < V_39 ; V_36 ++ ) {
if ( F_17 ( V_9 , V_34 , V_36 ) )
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
V_38 = ( ( ( T_1 ) V_34 ) >> 12 ) & V_37 ;
for ( V_36 = 0 ; ; ) {
if ( ( F_23 ( V_9 , V_36 ) & V_37 ) == V_38 )
break;
if ( ++ V_36 >= V_39 )
goto V_41;
}
if ( F_22 ( ! F_17 ( V_9 , V_34 , V_36 ) ) ) {
F_3 ( L_4
L_5 ,
V_42 , V_34 , V_36 ) ;
return NULL ;
}
V_40:
return F_24 ( ( int ) V_36 ) ;
V_41:
F_25 ( L_6 ,
( unsigned long ) V_34 ) ;
return NULL ;
}
static void F_26 ( struct V_8 * V_9 , int V_43 , T_2 V_14 ,
T_3 * V_44 , T_3 * V_45 )
{
T_3 V_46 , V_47 , V_48 , V_49 ;
T_2 V_50 ;
if ( V_30 . V_31 == 0xf && V_9 -> V_51 < V_52 ) {
V_46 = V_9 -> V_53 [ V_14 ] . V_54 [ V_43 ] ;
V_47 = V_9 -> V_53 [ V_14 ] . V_55 [ V_43 ] ;
V_48 = F_27 ( 21 , 31 ) | F_27 ( 9 , 15 ) ;
V_49 = F_27 ( 21 , 29 ) | F_27 ( 9 , 15 ) ;
V_50 = 4 ;
} else {
V_46 = V_9 -> V_53 [ V_14 ] . V_54 [ V_43 ] ;
V_47 = V_9 -> V_53 [ V_14 ] . V_55 [ V_43 >> 1 ] ;
V_50 = 8 ;
if ( V_30 . V_31 == 0x15 )
V_48 = V_49 = F_27 ( 19 , 30 ) | F_27 ( 5 , 13 ) ;
else
V_48 = V_49 = F_27 ( 19 , 28 ) | F_27 ( 5 , 13 ) ;
}
* V_44 = ( V_46 & V_48 ) << V_50 ;
* V_45 = ~ 0ULL ;
* V_45 &= ~ ( V_49 << V_50 ) ;
* V_45 |= ( V_47 & V_49 ) << V_50 ;
}
static int F_28 ( struct V_25 * V_26 , T_3 V_56 )
{
struct V_8 * V_9 ;
int V_43 ;
T_3 V_44 , V_45 ;
V_9 = V_26 -> V_28 ;
F_29 (csrow, 0 , pvt) {
if ( ! F_30 ( V_43 , 0 , V_9 ) )
continue;
F_26 ( V_9 , V_43 , 0 , & V_44 , & V_45 ) ;
V_45 = ~ V_45 ;
if ( ( V_56 & V_45 ) == ( V_44 & V_45 ) ) {
F_25 ( L_7 ,
( unsigned long ) V_56 , V_43 ,
V_9 -> V_57 ) ;
return V_43 ;
}
}
F_25 ( L_8 ,
( unsigned long ) V_56 , V_9 -> V_57 ) ;
return - 1 ;
}
int F_31 ( struct V_25 * V_26 , T_3 * V_58 ,
T_3 * V_59 , T_3 * V_60 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
T_3 V_44 ;
if ( V_30 . V_31 == 0xf && V_9 -> V_51 < V_61 ) {
F_32 ( L_9 ,
V_9 -> V_51 , V_9 -> V_57 ) ;
return 1 ;
}
if ( V_30 . V_31 >= 0x10 && ! F_33 ( V_9 ) ) {
F_32 ( L_10 ) ;
return 1 ;
}
if ( ! F_34 ( V_9 ) ) {
F_32 ( L_11 ,
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
F_32 ( L_12 ,
V_9 -> V_57 , ( unsigned long ) * V_58 ,
( unsigned long ) * V_59 , ( unsigned long ) * V_60 ) ;
return 0 ;
}
static T_3 F_38 ( struct V_25 * V_26 , T_3 V_34 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
T_3 V_62 , V_58 , V_59 , V_60 , V_63 ;
int V_64 = 0 ;
V_62 = F_18 ( V_9 , V_9 -> V_57 ) ;
V_64 = F_31 ( V_26 , & V_58 , & V_59 ,
& V_60 ) ;
if ( ! V_64 ) {
if ( ( V_34 >= ( 1ull << 32 ) ) &&
( V_34 < ( ( 1ull << 32 ) + V_60 ) ) ) {
V_63 = V_34 - V_59 ;
F_25 ( L_13
L_14 ,
( unsigned long ) V_34 ,
( unsigned long ) V_63 ) ;
return V_63 ;
}
}
V_63 = ( V_34 & F_27 ( 0 , 39 ) ) - V_62 ;
F_25 ( L_15
L_14 , ( unsigned long ) V_34 ,
( unsigned long ) V_63 ) ;
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
V_67 = F_39 ( F_21 ( V_9 , 0 ) ) ;
V_56 = ( ( V_63 >> V_67 ) & F_27 ( 12 , 35 ) ) +
( V_63 & 0xfff ) ;
F_25 ( L_16 ,
V_67 , ( unsigned long ) V_63 ,
( unsigned long ) V_56 ) ;
return V_56 ;
}
static T_3 F_42 ( struct V_25 * V_26 , T_3 V_34 )
{
T_3 V_56 ;
V_56 =
F_41 ( V_26 , F_38 ( V_26 , V_34 ) ) ;
F_25 ( L_17 ,
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
V_67 = F_39 ( F_21 ( V_9 , 0 ) ) ;
if ( V_67 == 0 ) {
F_32 ( L_18
L_19 , ( unsigned long ) V_56 ) ;
return V_56 ;
}
V_38 = ( ( V_56 & F_27 ( 12 , 35 ) ) << V_67 ) +
( V_56 & 0xfff ) ;
V_68 = F_23 ( V_9 , V_36 ) & ( ( 1 << V_67 ) - 1 ) ;
V_63 = V_38 + ( V_68 << 12 ) ;
F_32 ( L_20
L_21 , ( unsigned long ) V_56 ,
( unsigned long ) V_63 , V_67 ) ;
return V_63 ;
}
static T_3 F_44 ( struct V_25 * V_26 , T_3 V_63 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
T_3 V_58 , V_59 , V_60 , V_44 , V_34 ;
int V_64 = 0 ;
V_64 = F_31 ( V_26 , & V_58 , & V_59 ,
& V_60 ) ;
if ( ! V_64 ) {
if ( ( V_63 >= V_58 ) &&
( V_63 < ( V_58 + V_60 ) ) ) {
V_34 = V_63 + V_59 ;
F_32 ( L_22
L_23 , ( unsigned long ) V_63 ,
( unsigned long ) V_34 ) ;
return V_34 ;
}
}
V_44 = F_18 ( V_9 , V_9 -> V_57 ) ;
V_34 = V_63 + V_44 ;
V_34 |= ~ ( ( V_34 & ( 1ull << 39 ) ) - 1 ) ;
F_32 ( L_24 ,
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
static void F_46 ( struct V_25 * V_26 , int V_43 ,
T_3 * V_69 , T_3 * V_70 )
{
struct V_8 * V_9 ;
T_3 V_44 , V_45 ;
V_9 = V_26 -> V_28 ;
F_40 ( ( V_43 < 0 ) || ( V_43 >= V_9 -> V_53 [ 0 ] . V_71 ) ) ;
F_26 ( V_9 , V_43 , 0 , & V_44 , & V_45 ) ;
* V_69 = V_44 & ~ V_45 ;
* V_70 = V_44 | V_45 ;
}
static inline void F_47 ( T_3 V_72 ,
T_1 * V_73 , T_1 * V_3 )
{
* V_73 = ( T_1 ) ( V_72 >> V_74 ) ;
* V_3 = ( ( T_1 ) V_72 ) & ~ V_75 ;
}
static int F_48 ( struct V_25 * V_26 , T_3 V_34 )
{
int V_43 ;
V_43 = F_28 ( V_26 , F_42 ( V_26 , V_34 ) ) ;
if ( V_43 == - 1 )
F_49 ( V_26 , L_25
L_26 , ( unsigned long ) V_34 ) ;
return V_43 ;
}
static enum V_76 F_50 ( struct V_8 * V_9 )
{
T_2 V_77 ;
enum V_78 V_79 = V_80 ;
V_77 = ( V_30 . V_31 > 0xf || V_9 -> V_51 >= V_52 )
? 19
: 17 ;
if ( V_9 -> V_81 & F_51 ( V_77 ) )
V_79 = V_82 ;
return V_79 ;
}
static void F_52 ( T_1 V_83 , int V_84 )
{
F_32 ( L_27 , V_84 , V_83 ) ;
F_32 ( L_28 ,
( V_83 & F_51 ( 16 ) ) ? L_29 : L_30 ,
( V_83 & F_51 ( 19 ) ) ? L_31 : L_32 ) ;
F_32 ( L_33 ,
( V_83 & F_51 ( 8 ) ) ? L_34 : L_35 ) ;
if ( V_30 . V_31 == 0x10 )
F_32 ( L_36 ,
( V_83 & F_51 ( 11 ) ) ? L_37 : L_38 ) ;
F_32 ( L_39 ,
( V_83 & F_51 ( 12 ) ) ? L_31 : L_32 ,
( V_83 & F_51 ( 13 ) ) ? L_31 : L_32 ,
( V_83 & F_51 ( 14 ) ) ? L_31 : L_32 ,
( V_83 & F_51 ( 15 ) ) ? L_31 : L_32 ) ;
}
static void F_53 ( struct V_8 * V_9 )
{
F_32 ( L_40 , V_9 -> V_85 ) ;
F_32 ( L_41 ,
( V_9 -> V_85 & V_86 ) ? L_31 : L_32 ) ;
F_32 ( L_42 ,
( V_9 -> V_85 & V_87 ) ? L_31 : L_32 ,
( V_9 -> V_85 & V_88 ) ? L_31 : L_32 ) ;
F_52 ( V_9 -> V_81 , 0 ) ;
F_32 ( L_43 , V_9 -> V_89 ) ;
F_32 ( L_44
L_45 ,
V_9 -> V_90 , F_35 ( V_9 ) ,
( V_30 . V_31 == 0xf ) ? F_37 ( V_9 )
: F_36 ( V_9 ) ) ;
F_32 ( L_46 , F_34 ( V_9 ) ? L_31 : L_32 ) ;
F_54 ( V_9 , 0 ) ;
if ( V_30 . V_31 == 0xf )
return;
F_54 ( V_9 , 1 ) ;
F_55 ( L_47 , ( ( V_9 -> V_91 == 8 ) ? L_48 : L_49 ) ) ;
if ( ! F_56 ( V_9 ) )
F_52 ( V_9 -> V_92 , 1 ) ;
}
static void F_57 ( struct V_8 * V_9 )
{
if ( V_30 . V_31 == 0xf && V_9 -> V_51 < V_52 ) {
V_9 -> V_53 [ 0 ] . V_71 = V_9 -> V_53 [ 1 ] . V_71 = 8 ;
V_9 -> V_53 [ 0 ] . V_93 = V_9 -> V_53 [ 1 ] . V_93 = 8 ;
} else {
V_9 -> V_53 [ 0 ] . V_71 = V_9 -> V_53 [ 1 ] . V_71 = 8 ;
V_9 -> V_53 [ 0 ] . V_93 = V_9 -> V_53 [ 1 ] . V_93 = 4 ;
}
}
static void F_58 ( struct V_8 * V_9 )
{
int V_94 ;
F_57 ( V_9 ) ;
F_29 (cs, 0 , pvt) {
int V_95 = V_96 + ( V_94 * 4 ) ;
int V_97 = V_98 + ( V_94 * 4 ) ;
T_1 * V_99 = & V_9 -> V_53 [ 0 ] . V_54 [ V_94 ] ;
T_1 * V_100 = & V_9 -> V_53 [ 1 ] . V_54 [ V_94 ] ;
if ( ! F_59 ( V_9 , V_95 , V_99 ) )
F_60 ( L_50 ,
V_94 , * V_99 , V_95 ) ;
if ( V_30 . V_31 == 0xf || F_56 ( V_9 ) )
continue;
if ( ! F_59 ( V_9 , V_97 , V_100 ) )
F_60 ( L_51 ,
V_94 , * V_100 , V_97 ) ;
}
F_61 (cs, 0 , pvt) {
int V_95 = V_101 + ( V_94 * 4 ) ;
int V_97 = V_102 + ( V_94 * 4 ) ;
T_1 * V_103 = & V_9 -> V_53 [ 0 ] . V_55 [ V_94 ] ;
T_1 * V_104 = & V_9 -> V_53 [ 1 ] . V_55 [ V_94 ] ;
if ( ! F_59 ( V_9 , V_95 , V_103 ) )
F_60 ( L_52 ,
V_94 , * V_103 , V_95 ) ;
if ( V_30 . V_31 == 0xf || F_56 ( V_9 ) )
continue;
if ( ! F_59 ( V_9 , V_97 , V_104 ) )
F_60 ( L_53 ,
V_94 , * V_104 , V_97 ) ;
}
}
static enum V_105 F_62 ( struct V_8 * V_9 , int V_94 )
{
enum V_105 type ;
if ( V_30 . V_31 >= 0x15 )
type = ( V_9 -> V_81 & F_51 ( 16 ) ) ? V_106 : V_107 ;
else if ( V_30 . V_31 == 0x10 || V_9 -> V_51 >= V_52 ) {
if ( V_9 -> V_108 & V_109 )
type = ( V_9 -> V_81 & F_51 ( 16 ) ) ? V_106 : V_107 ;
else
type = ( V_9 -> V_81 & F_51 ( 16 ) ) ? V_110 : V_111 ;
} else {
type = ( V_9 -> V_81 & F_51 ( 18 ) ) ? V_112 : V_113 ;
}
F_55 ( L_54 , V_94 , V_114 [ type ] ) ;
return type ;
}
static int F_63 ( struct V_8 * V_9 )
{
int V_115 ;
if ( V_9 -> V_51 >= V_52 )
V_115 = V_9 -> V_81 & V_116 ;
else
V_115 = V_9 -> V_81 & V_117 ;
V_9 -> V_92 = 0 ;
return ( V_115 ) ? 2 : 1 ;
}
static T_3 F_64 ( struct V_118 * V_119 )
{
struct V_120 * V_121 = & V_30 ;
T_3 V_10 ;
T_2 V_122 = 1 ;
T_2 V_123 = 47 ;
if ( V_121 -> V_31 == 0xf ) {
V_122 = 3 ;
V_123 = 39 ;
}
V_10 = V_119 -> V_10 & F_27 ( V_122 , V_123 ) ;
if ( V_121 -> V_31 == 0x15 ) {
struct V_8 * V_9 ;
T_3 V_124 , V_125 ;
T_1 V_126 ;
T_2 V_127 , V_37 ;
if ( ( V_10 & F_27 ( 24 , 47 ) ) >> 24 != 0x00fdf7 )
return V_10 ;
V_127 = F_65 ( V_119 -> V_128 ) ;
V_9 = V_129 [ V_127 ] -> V_28 ;
F_10 ( V_9 -> V_15 , V_130 , & V_126 ) ;
V_37 = V_126 >> 21 & 0x7 ;
V_124 = ( V_126 & F_27 ( 0 , 20 ) ) << 3 ;
V_124 |= V_37 ^ 0x7 ;
V_124 <<= 24 ;
if ( ! V_37 )
return V_124 | ( V_10 & F_27 ( 0 , 23 ) ) ;
F_10 ( V_9 -> V_15 , V_131 , & V_126 ) ;
V_125 = ( V_10 & F_27 ( 12 , 23 ) ) << F_66 ( V_37 + 1 ) ;
V_125 |= ( V_126 & F_27 ( 21 , 23 ) ) >> 9 ;
V_125 |= V_10 & F_27 ( 0 , 11 ) ;
return V_124 | V_125 ;
}
return V_10 ;
}
static void F_67 ( struct V_8 * V_9 , unsigned V_132 )
{
struct V_120 * V_121 = & V_30 ;
int V_133 = V_132 << 3 ;
F_10 ( V_9 -> V_15 , V_134 + V_133 , & V_9 -> V_135 [ V_132 ] . V_44 . V_136 ) ;
F_10 ( V_9 -> V_15 , V_137 + V_133 , & V_9 -> V_135 [ V_132 ] . V_138 . V_136 ) ;
if ( V_121 -> V_31 == 0xf )
return;
if ( ! F_68 ( V_9 , V_132 ) )
return;
F_10 ( V_9 -> V_15 , V_139 + V_133 , & V_9 -> V_135 [ V_132 ] . V_44 . V_140 ) ;
F_10 ( V_9 -> V_15 , V_141 + V_133 , & V_9 -> V_135 [ V_132 ] . V_138 . V_140 ) ;
if ( V_121 -> V_31 == 0x15 ) {
struct V_1 * V_142 = NULL ;
T_2 V_35 = F_69 ( V_9 , V_132 ) ;
T_1 V_143 ;
V_142 = F_70 ( 0 , 0 , F_71 ( 0x18 + V_35 , 1 ) ) ;
if ( F_72 ( ! V_142 ) )
return;
F_10 ( V_142 , V_130 , & V_143 ) ;
V_9 -> V_135 [ V_132 ] . V_138 . V_136 &= F_27 ( 0 , 15 ) ;
V_9 -> V_135 [ V_132 ] . V_138 . V_136 |= ( ( V_143 & 0x1fff ) << 3 | 0x7 ) << 16 ;
V_9 -> V_135 [ V_132 ] . V_138 . V_140 &= F_27 ( 0 , 7 ) ;
V_9 -> V_135 [ V_132 ] . V_138 . V_140 |= V_143 >> 13 ;
F_73 ( V_142 ) ;
}
}
static void F_74 ( struct V_25 * V_26 , T_3 V_34 ,
T_4 V_144 )
{
struct V_25 * V_145 ;
struct V_8 * V_9 = V_26 -> V_28 ;
int V_146 , V_43 ;
T_1 V_73 , V_3 ;
if ( V_9 -> V_147 & V_148 ) {
V_146 = F_75 ( V_26 , V_144 ) ;
if ( V_146 < 0 ) {
F_76 ( V_26 , L_55
L_56 , V_144 ) ;
F_77 ( V_26 , V_149 ) ;
return;
}
} else {
V_146 = ( ( V_34 & F_51 ( 3 ) ) != 0 ) ;
}
V_145 = F_20 ( V_26 , V_34 ) ;
if ( ! V_145 ) {
F_49 ( V_26 , L_57 ,
( unsigned long ) V_34 ) ;
F_77 ( V_26 , V_149 ) ;
return;
}
V_43 = F_48 ( V_145 , V_34 ) ;
if ( V_43 < 0 ) {
F_77 ( V_145 , V_149 ) ;
} else {
F_47 ( V_34 , & V_73 , & V_3 ) ;
F_78 ( V_145 , V_73 , V_3 , V_144 , V_43 ,
V_146 , V_149 ) ;
}
}
static int F_79 ( unsigned V_21 , bool V_150 )
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
static int F_80 ( struct V_8 * V_9 , T_2 V_14 ,
unsigned V_152 )
{
T_1 V_83 = V_14 ? V_9 -> V_92 : V_9 -> V_81 ;
if ( V_9 -> V_51 >= V_52 ) {
F_72 ( V_152 > 11 ) ;
return F_79 ( V_152 , V_83 & V_116 ) ;
}
else if ( V_9 -> V_51 >= V_153 ) {
F_72 ( V_152 > 10 ) ;
if ( V_152 == 3 || V_152 == 8 )
return 32 << ( V_152 - 1 ) ;
else
return 32 << V_152 ;
}
else {
F_72 ( V_152 > 6 ) ;
return 32 << V_152 ;
}
}
static int F_81 ( struct V_8 * V_9 )
{
int V_21 , V_154 , V_155 = 0 ;
if ( V_30 . V_31 == 0x10 && ( V_9 -> V_81 & V_116 ) )
return 2 ;
F_60 ( L_58 ) ;
for ( V_21 = 0 ; V_21 < 2 ; V_21 ++ ) {
T_1 V_156 = ( V_21 ? V_9 -> V_157 : V_9 -> V_158 ) ;
for ( V_154 = 0 ; V_154 < 4 ; V_154 ++ ) {
if ( F_82 ( V_154 , V_156 ) > 0 ) {
V_155 ++ ;
break;
}
}
}
if ( V_155 > 2 )
V_155 = 2 ;
F_55 ( L_59 , V_155 ) ;
return V_155 ;
}
static int F_83 ( unsigned V_21 , bool V_150 )
{
unsigned V_151 = 0 ;
int V_159 = 0 ;
if ( V_21 == 0 || V_21 == 3 || V_21 == 4 )
V_159 = - 1 ;
else if ( V_21 <= 2 )
V_151 = V_21 ;
else if ( V_21 == 12 )
V_151 = 7 ;
else if ( ! ( V_21 & 0x1 ) )
V_151 = V_21 >> 1 ;
else
V_151 = ( V_21 + 1 ) >> 1 ;
if ( V_159 != - 1 )
V_159 = ( 128 * ( 1 << ! ! V_150 ) ) << V_151 ;
return V_159 ;
}
static int F_84 ( struct V_8 * V_9 , T_2 V_14 ,
unsigned V_152 )
{
T_1 V_83 = V_14 ? V_9 -> V_92 : V_9 -> V_81 ;
F_72 ( V_152 > 11 ) ;
if ( V_9 -> V_108 & V_109 || V_9 -> V_160 & V_109 )
return F_83 ( V_152 , V_83 & V_116 ) ;
else
return F_79 ( V_152 , V_83 & V_116 ) ;
}
static int F_85 ( struct V_8 * V_9 , T_2 V_14 ,
unsigned V_152 )
{
F_72 ( V_152 > 12 ) ;
return F_83 ( V_152 , false ) ;
}
static void F_86 ( struct V_8 * V_9 )
{
if ( V_30 . V_31 == 0xf )
return;
if ( ! F_59 ( V_9 , V_161 , & V_9 -> V_162 ) ) {
F_60 ( L_60 ,
V_9 -> V_162 , F_87 ( V_9 ) ) ;
F_60 ( L_61 ,
( F_56 ( V_9 ) ? L_62 : L_63 ) ) ;
if ( ! F_56 ( V_9 ) )
F_60 ( L_64 ,
( F_88 ( V_9 ) ? L_31 : L_32 ) ) ;
F_60 ( L_65
L_66 ,
( F_89 ( V_9 ) ? L_34 : L_35 ) ,
( F_90 ( V_9 ) ? L_31 : L_32 ) ) ;
F_60 ( L_67
L_68 ,
( F_91 ( V_9 ) ? L_34 : L_35 ) ,
F_92 ( V_9 ) ) ;
}
F_59 ( V_9 , V_163 , & V_9 -> V_164 ) ;
}
static T_2 F_93 ( struct V_8 * V_9 , T_3 V_34 ,
bool V_165 , T_2 V_37 )
{
T_2 V_166 = ( V_9 -> V_162 >> 1 ) & 1 ;
if ( F_56 ( V_9 ) )
return 0 ;
if ( V_165 )
return V_166 ;
if ( F_91 ( V_9 ) ) {
T_2 V_167 = F_92 ( V_9 ) ;
if ( ! V_167 )
return V_34 >> 6 & 1 ;
if ( V_167 & 0x2 ) {
T_2 V_151 = V_167 & 0x1 ? 9 : 6 ;
T_1 V_168 = F_94 ( ( T_1 ) ( ( V_34 >> 16 ) & 0x1F ) ) % 2 ;
return ( ( V_34 >> V_151 ) & 1 ) ^ V_168 ;
}
return ( V_34 >> ( 12 + F_95 ( V_37 ) ) ) & 1 ;
}
if ( F_88 ( V_9 ) )
return ~ V_166 & 1 ;
return 0 ;
}
static T_3 F_96 ( struct V_8 * V_9 , unsigned V_132 ,
T_3 V_34 , bool V_169 ,
T_1 V_170 )
{
T_3 V_171 ;
T_3 V_62 = F_18 ( V_9 , V_132 ) ;
T_3 V_172 = F_36 ( V_9 ) ;
T_3 V_173 = ( V_9 -> V_164 & 0xFFFFFC00 ) << 16 ;
if ( V_169 ) {
if ( ( ! ( V_170 >> 16 ) ||
V_170 < F_35 ( V_9 ) ) &&
F_34 ( V_9 ) &&
( V_34 >= F_97 ( 32 ) ) )
V_171 = V_172 ;
else
V_171 = V_173 ;
} else {
if ( F_34 ( V_9 ) && ( V_34 >= F_97 ( 32 ) ) )
V_171 = V_172 ;
else
V_171 = V_62 ;
}
return ( V_34 & F_27 ( 6 , 47 ) ) - ( V_171 & F_27 ( 23 , 47 ) ) ;
}
static int F_98 ( struct V_8 * V_9 , T_2 V_14 , int V_43 )
{
int V_174 ;
if ( F_99 ( V_9 , V_14 ) &&
V_43 == F_100 ( V_9 , V_14 ) ) {
F_29 (tmp_cs, dct, pvt) {
if ( F_101 ( V_174 , V_14 , V_9 ) & 0x2 ) {
V_43 = V_174 ;
break;
}
}
}
return V_43 ;
}
static int F_102 ( T_3 V_175 , T_1 V_35 , T_2 V_14 )
{
struct V_25 * V_26 ;
struct V_8 * V_9 ;
T_3 V_176 , V_177 ;
int V_178 = - V_11 ;
int V_43 ;
V_26 = V_129 [ V_35 ] ;
if ( ! V_26 )
return V_178 ;
V_9 = V_26 -> V_28 ;
F_32 ( L_69 , V_175 , V_14 ) ;
F_29 (csrow, dct, pvt) {
if ( ! F_30 ( V_43 , V_14 , V_9 ) )
continue;
F_26 ( V_9 , V_43 , V_14 , & V_176 , & V_177 ) ;
F_32 ( L_70 ,
V_43 , V_176 , V_177 ) ;
V_177 = ~ V_177 ;
F_32 ( L_71
L_72 ,
( V_175 & V_177 ) , ( V_176 & V_177 ) ) ;
if ( ( V_175 & V_177 ) == ( V_176 & V_177 ) ) {
V_178 = F_98 ( V_9 , V_14 , V_43 ) ;
F_32 ( L_73 , V_178 ) ;
break;
}
}
return V_178 ;
}
static T_3 F_103 ( struct V_8 * V_9 , T_3 V_34 )
{
T_1 V_179 , V_180 , V_181 , V_182 , V_125 ;
if ( V_30 . V_31 == 0x10 ) {
if ( V_30 . V_183 < 4 ||
( V_30 . V_183 < 0xa &&
V_30 . V_184 < 3 ) )
return V_34 ;
}
F_59 ( V_9 , V_185 , & V_179 ) ;
if ( ! ( V_179 & 0x1 ) )
return V_34 ;
V_180 = ( V_179 >> 3 ) & 0x7f ;
V_181 = ( V_179 >> 11 ) & 0x7f ;
V_182 = ( V_179 >> 20 ) & 0x7f ;
V_125 = V_34 >> 27 ;
if ( ! ( V_34 >> 34 ) &&
( ( ( V_125 >= V_180 ) &&
( V_125 <= V_181 ) ) ||
( V_125 < V_182 ) ) )
return V_34 ^ ( T_3 ) V_180 << 27 ;
return V_34 ;
}
static int F_104 ( struct V_8 * V_9 , unsigned V_132 ,
T_3 V_34 , int * V_35 , int * V_186 )
{
int V_178 = - V_11 ;
T_3 V_187 ;
T_1 V_188 ;
T_2 V_146 ;
bool V_189 = false ;
T_2 V_36 = F_69 ( V_9 , V_132 ) ;
T_2 V_37 = F_21 ( V_9 , V_132 ) ;
T_1 V_68 = F_23 ( V_9 , V_132 ) ;
F_32 ( L_74 ,
V_132 , V_34 , F_19 ( V_9 , V_132 ) ) ;
if ( F_34 ( V_9 ) &&
F_35 ( V_9 ) <= V_34 &&
V_34 < F_97 ( 32 ) ) {
F_3 ( L_75 ,
V_34 ) ;
return - V_11 ;
}
if ( V_37 && ( V_68 != ( ( V_34 >> 12 ) & V_37 ) ) )
return - V_11 ;
V_34 = F_103 ( V_9 , V_34 ) ;
V_188 = F_87 ( V_9 ) ;
if ( F_88 ( V_9 ) &&
! F_56 ( V_9 ) &&
( ( V_34 >> 27 ) >= ( V_188 >> 11 ) ) )
V_189 = true ;
V_146 = F_93 ( V_9 , V_34 , V_189 , V_37 ) ;
V_187 = F_96 ( V_9 , V_132 , V_34 ,
V_189 , V_188 ) ;
if ( V_37 )
V_187 = ( ( V_187 >> ( 12 + F_95 ( V_37 ) ) ) << 12 ) |
( V_187 & 0xfff ) ;
if ( F_91 ( V_9 ) &&
! F_88 ( V_9 ) &&
! F_56 ( V_9 ) ) {
if ( F_92 ( V_9 ) != 1 ) {
if ( F_92 ( V_9 ) == 0x3 )
V_187 = ( ( V_187 >> 10 ) << 9 ) |
( V_187 & 0x1ff ) ;
else
V_187 = ( ( V_187 >> 7 ) << 6 ) |
( V_187 & 0x3f ) ;
} else
V_187 = ( ( V_187 >> 13 ) << 12 ) |
( V_187 & 0xfff ) ;
}
F_32 ( L_76 , V_187 ) ;
V_178 = F_102 ( V_187 , V_36 , V_146 ) ;
if ( V_178 >= 0 ) {
* V_35 = V_36 ;
* V_186 = V_146 ;
}
return V_178 ;
}
static int F_105 ( struct V_8 * V_9 , T_3 V_34 ,
int * V_190 , int * V_186 )
{
int V_178 = - V_11 ;
unsigned V_132 ;
for ( V_132 = 0 ; V_132 < V_39 ; V_132 ++ ) {
if ( ! F_68 ( V_9 , V_132 ) )
continue;
if ( ( F_18 ( V_9 , V_132 ) <= V_34 ) &&
( F_19 ( V_9 , V_132 ) >= V_34 ) ) {
V_178 = F_104 ( V_9 , V_132 ,
V_34 , V_190 ,
V_186 ) ;
if ( V_178 >= 0 )
break;
}
}
return V_178 ;
}
static void F_106 ( struct V_25 * V_26 , T_3 V_34 ,
T_4 V_144 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
T_1 V_73 , V_3 ;
int V_35 , V_43 , V_84 = 0 ;
V_43 = F_105 ( V_9 , V_34 , & V_35 , & V_84 ) ;
if ( V_43 < 0 ) {
F_77 ( V_26 , V_149 ) ;
return;
}
F_47 ( V_34 , & V_73 , & V_3 ) ;
if ( F_56 ( V_9 ) )
V_84 = F_75 ( V_26 , V_144 ) ;
if ( V_84 >= 0 )
F_78 ( V_26 , V_73 , V_3 , V_144 , V_43 , V_84 ,
V_149 ) ;
else
for ( V_84 = 0 ; V_84 < V_26 -> V_191 [ V_43 ] . V_192 ; V_84 ++ )
F_78 ( V_26 , V_73 , V_3 , V_144 ,
V_43 , V_84 , V_149 ) ;
}
static void F_54 ( struct V_8 * V_9 , T_2 V_193 )
{
int V_194 , V_195 , V_196 , V_197 = 0 ;
T_1 * V_198 = V_193 ? V_9 -> V_53 [ 1 ] . V_54 : V_9 -> V_53 [ 0 ] . V_54 ;
T_1 V_156 = V_193 ? V_9 -> V_157 : V_9 -> V_158 ;
if ( V_30 . V_31 == 0xf ) {
if ( V_9 -> V_81 & V_116 )
V_197 = 1 ;
if ( V_9 -> V_51 < V_52 )
return;
else
F_72 ( V_193 != 0 ) ;
}
V_156 = ( V_193 && ! F_56 ( V_9 ) ) ? V_9 -> V_157 : V_9 -> V_158 ;
V_198 = ( V_193 && ! F_56 ( V_9 ) ) ? V_9 -> V_53 [ 1 ] . V_54
: V_9 -> V_53 [ 0 ] . V_54 ;
F_32 ( L_77 , V_193 , V_156 ) ;
F_107 ( V_199 , V_200 , L_78 , V_193 ) ;
for ( V_194 = 0 ; V_194 < 4 ; V_194 ++ ) {
V_195 = 0 ;
if ( V_198 [ V_194 * 2 ] & V_201 )
V_195 = V_9 -> V_202 -> V_203 ( V_9 , V_193 ,
F_82 ( V_194 , V_156 ) ) ;
V_196 = 0 ;
if ( V_198 [ V_194 * 2 + 1 ] & V_201 )
V_196 = V_9 -> V_202 -> V_203 ( V_9 , V_193 ,
F_82 ( V_194 , V_156 ) ) ;
F_55 ( V_200 L_79 ,
V_194 * 2 , V_195 << V_197 ,
V_194 * 2 + 1 , V_196 << V_197 ) ;
}
}
static struct V_1 * F_108 ( unsigned int V_204 ,
unsigned int V_205 ,
struct V_1 * V_206 )
{
struct V_1 * V_207 = NULL ;
V_207 = F_109 ( V_204 , V_205 , V_207 ) ;
while ( V_207 ) {
if ( ( V_207 -> V_208 -> V_209 == V_206 -> V_208 -> V_209 ) &&
( F_110 ( V_207 -> V_7 ) == F_110 ( V_206 -> V_7 ) ) )
break;
V_207 = F_109 ( V_204 , V_205 , V_207 ) ;
}
return V_207 ;
}
static int F_111 ( T_4 V_144 , T_4 * V_210 , unsigned V_211 ,
unsigned V_212 )
{
unsigned int V_21 , V_213 ;
for ( V_213 = 0 ; V_213 < V_211 / V_212 ; V_213 ++ ) {
T_4 V_214 = V_144 ;
unsigned V_215 = V_213 * V_212 ;
unsigned V_216 = ( V_213 + 1 ) * V_212 ;
for ( V_21 = 1 ; V_21 < ( 1U << 16 ) ; V_21 <<= 1 ) {
if ( V_215 < V_216 && V_210 [ V_215 ] & V_21 ) {
T_4 V_217 = V_210 [ V_215 ++ ] ;
if ( V_214 & V_21 ) {
V_214 ^= V_217 ;
if ( ! V_214 )
return V_213 ;
}
} else if ( V_214 & V_21 )
break;
}
}
F_60 ( L_80 , V_144 ) ;
return - 1 ;
}
static int F_112 ( int V_213 , int V_218 )
{
if ( V_218 == 4 )
switch ( V_213 ) {
case 0x20 :
case 0x21 :
return 0 ;
break;
case 0x22 :
case 0x23 :
return 1 ;
break;
default:
return V_213 >> 4 ;
break;
}
else
switch ( V_213 ) {
case 0x10 :
F_113 ( 1 , V_219 L_81 ,
V_213 ) ;
return - 1 ;
break;
case 0x11 :
return 0 ;
break;
case 0x12 :
return 1 ;
break;
default:
return V_213 >> 3 ;
break;
}
return - 1 ;
}
static int F_75 ( struct V_25 * V_26 , T_4 V_144 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
int V_213 = - 1 ;
if ( V_9 -> V_91 == 8 )
V_213 = F_111 ( V_144 , V_220 ,
F_13 ( V_220 ) ,
V_9 -> V_91 ) ;
else if ( V_9 -> V_91 == 4 )
V_213 = F_111 ( V_144 , V_221 ,
F_13 ( V_221 ) ,
V_9 -> V_91 ) ;
else {
F_3 ( L_82 , V_9 -> V_91 ) ;
return V_213 ;
}
return F_112 ( V_213 , V_9 -> V_91 ) ;
}
static void F_114 ( struct V_25 * V_26 , struct V_118 * V_119 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
T_3 V_34 ;
T_4 V_144 ;
if ( ! ( V_119 -> V_222 & V_223 ) ) {
F_49 ( V_26 , L_83 ) ;
F_77 ( V_26 , V_149 ) ;
return;
}
V_34 = F_64 ( V_119 ) ;
V_144 = F_115 ( V_119 -> V_222 ) ;
F_49 ( V_26 , L_84 , V_34 ) ;
V_9 -> V_202 -> V_224 ( V_26 , V_34 , V_144 ) ;
}
static void F_116 ( struct V_25 * V_26 , struct V_118 * V_119 )
{
struct V_25 * V_225 , * V_145 = NULL ;
int V_43 ;
T_3 V_34 ;
T_1 V_73 , V_3 ;
V_225 = V_26 ;
if ( ! ( V_119 -> V_222 & V_223 ) ) {
F_49 ( V_26 , L_83 ) ;
F_117 ( V_225 , V_149 ) ;
return;
}
V_34 = F_64 ( V_119 ) ;
V_145 = F_20 ( V_26 , V_34 ) ;
if ( ! V_145 ) {
F_49 ( V_26 , L_85 ,
( unsigned long ) V_34 ) ;
F_117 ( V_225 , V_149 ) ;
return;
}
V_225 = V_145 ;
V_43 = F_48 ( V_225 , V_34 ) ;
if ( V_43 < 0 ) {
F_49 ( V_26 , L_86 ,
( unsigned long ) V_34 ) ;
F_117 ( V_225 , V_149 ) ;
} else {
F_47 ( V_34 , & V_73 , & V_3 ) ;
F_118 ( V_225 , V_73 , V_3 , V_43 , V_149 ) ;
}
}
static inline void F_119 ( struct V_25 * V_26 ,
struct V_118 * V_119 )
{
T_4 V_226 = F_120 ( V_119 -> V_222 ) ;
T_2 V_227 = F_121 ( V_119 -> V_222 , 0x1f ) ;
T_2 V_228 = ( V_119 -> V_222 >> 45 ) & 0x3 ;
if ( F_122 ( V_226 ) == V_229 )
return;
if ( V_227 && V_227 != V_230 )
return;
if ( V_228 == 2 )
F_114 ( V_26 , V_119 ) ;
else if ( V_228 == 1 )
F_116 ( V_26 , V_119 ) ;
}
void F_123 ( int V_36 , struct V_118 * V_119 , T_1 V_147 )
{
struct V_25 * V_26 = V_129 [ V_36 ] ;
F_119 ( V_26 , V_119 ) ;
}
static int F_124 ( struct V_8 * V_9 , T_4 V_231 , T_4 V_232 )
{
V_9 -> V_15 = F_108 ( V_9 -> V_12 -> V_204 , V_231 , V_9 -> V_12 ) ;
if ( ! V_9 -> V_15 ) {
F_125 ( L_87
L_88 ,
V_233 , V_231 ) ;
return - V_234 ;
}
V_9 -> V_32 = F_108 ( V_9 -> V_12 -> V_204 , V_232 , V_9 -> V_12 ) ;
if ( ! V_9 -> V_32 ) {
F_73 ( V_9 -> V_15 ) ;
V_9 -> V_15 = NULL ;
F_125 ( L_89
L_88 ,
V_233 , V_232 ) ;
return - V_234 ;
}
F_32 ( L_90 , F_126 ( V_9 -> V_15 ) ) ;
F_32 ( L_91 , F_126 ( V_9 -> V_12 ) ) ;
F_32 ( L_92 , F_126 ( V_9 -> V_32 ) ) ;
return 0 ;
}
static void F_127 ( struct V_8 * V_9 )
{
F_73 ( V_9 -> V_15 ) ;
F_73 ( V_9 -> V_32 ) ;
}
static void F_128 ( struct V_8 * V_9 )
{
struct V_120 * V_121 = & V_30 ;
T_3 V_235 ;
T_1 V_126 ;
unsigned V_132 ;
F_129 ( V_236 , V_9 -> V_237 ) ;
F_60 ( L_93 , V_9 -> V_237 ) ;
F_129 ( V_238 , V_235 ) ;
if ( V_235 & ( 1U << 21 ) ) {
F_129 ( V_239 , V_9 -> V_240 ) ;
F_60 ( L_94 , V_9 -> V_240 ) ;
} else
F_60 ( L_95 ) ;
F_10 ( V_9 -> V_32 , V_241 , & V_9 -> V_85 ) ;
F_86 ( V_9 ) ;
for ( V_132 = 0 ; V_132 < V_39 ; V_132 ++ ) {
T_2 V_242 ;
F_67 ( V_9 , V_132 ) ;
V_242 = F_68 ( V_9 , V_132 ) ;
if ( ! V_242 )
continue;
F_32 ( L_96 ,
V_132 ,
F_18 ( V_9 , V_132 ) ,
F_19 ( V_9 , V_132 ) ) ;
F_32 ( L_97 ,
F_21 ( V_9 , V_132 ) ? L_98 : L_99 ,
( V_242 & 0x1 ) ? L_100 : L_101 ,
( V_242 & 0x2 ) ? L_102 : L_101 ,
F_23 ( V_9 , V_132 ) ,
F_69 ( V_9 , V_132 ) ) ;
}
F_58 ( V_9 ) ;
F_10 ( V_9 -> V_15 , V_243 , & V_9 -> V_90 ) ;
F_59 ( V_9 , V_244 , & V_9 -> V_158 ) ;
F_10 ( V_9 -> V_32 , V_245 , & V_9 -> V_89 ) ;
F_59 ( V_9 , V_246 , & V_9 -> V_81 ) ;
F_59 ( V_9 , V_247 , & V_9 -> V_108 ) ;
if ( ! F_56 ( V_9 ) ) {
F_59 ( V_9 , V_248 , & V_9 -> V_92 ) ;
F_59 ( V_9 , V_249 , & V_9 -> V_160 ) ;
}
V_9 -> V_91 = 4 ;
if ( V_121 -> V_31 >= 0x10 ) {
F_10 ( V_9 -> V_32 , V_250 , & V_126 ) ;
F_59 ( V_9 , V_251 , & V_9 -> V_157 ) ;
if ( ( V_121 -> V_31 > 0x10 || V_121 -> V_183 > 7 ) && V_126 & F_51 ( 25 ) )
V_9 -> V_91 = 8 ;
}
F_53 ( V_9 ) ;
}
static T_1 F_130 ( struct V_8 * V_9 , T_2 V_14 , int V_252 )
{
T_1 V_152 , V_253 ;
V_152 = ( V_9 -> V_158 >> ( ( V_252 / 2 ) * 4 ) ) & 0xF ;
V_253 = V_9 -> V_202 -> V_203 ( V_9 , V_14 , V_152 ) << ( 20 - V_74 ) ;
V_253 <<= ( V_9 -> V_254 - 1 ) ;
F_60 ( L_103 , V_252 , V_152 ) ;
F_60 ( L_104 ,
V_253 , V_9 -> V_254 ) ;
return V_253 ;
}
static int F_131 ( struct V_25 * V_26 )
{
struct V_255 * V_43 ;
struct V_8 * V_9 = V_26 -> V_28 ;
T_3 V_69 , V_70 , V_34 , V_44 , V_45 ;
T_1 V_4 ;
int V_21 , V_256 = 1 ;
F_10 ( V_9 -> V_32 , V_257 , & V_4 ) ;
V_9 -> V_147 = V_4 ;
F_60 ( L_105 ,
V_9 -> V_57 , V_4 ,
! ! ( V_4 & V_148 ) , ! ! ( V_4 & V_258 ) ) ;
F_29 (i, 0 , pvt) {
V_43 = & V_26 -> V_191 [ V_21 ] ;
if ( ! F_30 ( V_21 , 0 , V_9 ) ) {
F_32 ( L_106 , V_21 ,
V_9 -> V_57 ) ;
continue;
}
F_32 ( L_107 ,
V_21 , V_9 -> V_57 ) ;
V_256 = 0 ;
V_43 -> V_253 = F_130 ( V_9 , 0 , V_21 ) ;
F_46 ( V_26 , V_21 , & V_69 , & V_70 ) ;
V_34 = F_45 ( V_26 , V_69 ) ;
V_43 -> V_259 = ( T_1 ) ( V_34 >> V_74 ) ;
V_34 = F_45 ( V_26 , V_70 ) ;
V_43 -> V_260 = ( T_1 ) ( V_34 >> V_74 ) ;
F_26 ( V_9 , V_21 , 0 , & V_44 , & V_45 ) ;
V_43 -> V_261 = ~ V_45 ;
V_43 -> V_262 = F_62 ( V_9 , V_21 ) ;
F_32 ( L_108 , V_9 -> V_57 , V_21 ) ;
F_32 ( L_109 ,
( unsigned long ) V_69 ,
( unsigned long ) V_70 ) ;
F_32 ( L_110 ,
( unsigned long ) V_34 , V_43 -> V_261 ) ;
F_32 ( L_111
L_112 ,
( unsigned ) V_43 -> V_253 ,
V_43 -> V_259 , V_43 -> V_260 ) ;
if ( V_9 -> V_147 & V_258 )
V_43 -> V_263 =
( V_9 -> V_147 & V_148 ) ?
V_264 : V_265 ;
else
V_43 -> V_263 = V_266 ;
}
return V_256 ;
}
static void F_132 ( struct V_267 * V_45 , unsigned V_35 )
{
int V_268 ;
F_133 (cpu)
if ( F_65 ( V_268 ) == V_35 )
F_134 ( V_268 , V_45 ) ;
}
static bool F_135 ( unsigned V_35 )
{
T_5 V_45 ;
int V_268 , V_269 ;
bool V_64 = false ;
if ( ! F_136 ( & V_45 , V_270 ) ) {
F_3 ( L_113 , V_42 ) ;
return false ;
}
F_132 ( V_45 , V_35 ) ;
F_137 ( V_45 , V_271 , V_272 ) ;
F_138 (cpu, mask) {
struct V_273 * V_13 = F_139 ( V_272 , V_268 ) ;
V_269 = V_13 -> V_274 & V_275 ;
F_60 ( L_114 ,
V_268 , V_13 -> V_276 ,
( V_269 ? L_34 : L_35 ) ) ;
if ( ! V_269 )
goto V_277;
}
V_64 = true ;
V_277:
F_140 ( V_45 ) ;
return V_64 ;
}
static int F_141 ( struct V_278 * V_214 , T_2 V_35 , bool V_279 )
{
T_5 V_280 ;
int V_268 ;
if ( ! F_136 ( & V_280 , V_270 ) ) {
F_3 ( L_115 , V_42 ) ;
return false ;
}
F_132 ( V_280 , V_35 ) ;
F_137 ( V_280 , V_271 , V_272 ) ;
F_138 (cpu, cmask) {
struct V_273 * V_13 = F_139 ( V_272 , V_268 ) ;
if ( V_279 ) {
if ( V_13 -> V_274 & V_275 )
V_214 -> V_281 . V_282 = 1 ;
V_13 -> V_274 |= V_275 ;
} else {
if ( ! V_214 -> V_281 . V_282 )
V_13 -> V_274 &= ~ V_275 ;
}
}
F_142 ( V_280 , V_271 , V_272 ) ;
F_140 ( V_280 ) ;
return 0 ;
}
static bool F_143 ( struct V_278 * V_214 , T_2 V_35 ,
struct V_1 * V_32 )
{
bool V_64 = true ;
T_1 V_283 , V_45 = 0x3 ;
if ( F_141 ( V_214 , V_35 , V_284 ) ) {
F_3 ( L_116 ) ;
return false ;
}
F_10 ( V_32 , V_285 , & V_283 ) ;
V_214 -> V_286 = V_283 & V_45 ;
V_214 -> V_287 = true ;
V_283 |= V_45 ;
F_11 ( V_32 , V_285 , V_283 ) ;
F_10 ( V_32 , V_257 , & V_283 ) ;
F_60 ( L_117 ,
V_35 , V_283 , ! ! ( V_283 & V_258 ) ) ;
if ( ! ( V_283 & V_258 ) ) {
F_3 ( L_118 ) ;
V_214 -> V_281 . V_288 = 0 ;
V_283 |= V_258 ;
F_11 ( V_32 , V_257 , V_283 ) ;
F_10 ( V_32 , V_257 , & V_283 ) ;
if ( ! ( V_283 & V_258 ) ) {
F_3 ( L_119
L_120 ) ;
V_64 = false ;
} else {
F_55 ( L_121 ) ;
}
} else {
V_214 -> V_281 . V_288 = 1 ;
}
F_60 ( L_122 ,
V_35 , V_283 , ! ! ( V_283 & V_258 ) ) ;
return V_64 ;
}
static void F_144 ( struct V_278 * V_214 , T_2 V_35 ,
struct V_1 * V_32 )
{
T_1 V_283 , V_45 = 0x3 ;
if ( ! V_214 -> V_287 )
return;
F_10 ( V_32 , V_285 , & V_283 ) ;
V_283 &= ~ V_45 ;
V_283 |= V_214 -> V_286 ;
F_11 ( V_32 , V_285 , V_283 ) ;
if ( ! V_214 -> V_281 . V_288 ) {
F_10 ( V_32 , V_257 , & V_283 ) ;
V_283 &= ~ V_258 ;
F_11 ( V_32 , V_257 , V_283 ) ;
}
if ( F_141 ( V_214 , V_35 , V_289 ) )
F_3 ( L_123 ) ;
}
static bool F_145 ( struct V_1 * V_32 , T_2 V_35 )
{
T_1 V_283 ;
T_2 V_290 = 0 ;
bool V_291 = false ;
F_10 ( V_32 , V_257 , & V_283 ) ;
V_290 = ! ! ( V_283 & V_258 ) ;
F_55 ( L_124 , ( V_290 ? L_34 : L_35 ) ) ;
V_291 = F_135 ( V_35 ) ;
if ( ! V_291 )
F_146 ( L_125
L_126 ,
V_271 , V_35 ) ;
if ( ! V_290 || ! V_291 ) {
F_146 ( L_127 , V_292 ) ;
return false ;
}
return true ;
}
static void F_147 ( struct V_25 * V_26 )
{
unsigned int V_21 = 0 , V_154 = 0 ;
for (; V_21 < F_13 ( V_293 ) ; V_21 ++ )
V_294 [ V_21 ] = V_293 [ V_21 ] ;
if ( V_30 . V_31 >= 0x10 )
for ( V_154 = 0 ; V_154 < F_13 ( V_295 ) ; V_154 ++ , V_21 ++ )
V_294 [ V_21 ] = V_295 [ V_154 ] ;
V_294 [ V_21 ] = V_296 ;
V_26 -> V_297 = V_294 ;
}
static void F_148 ( struct V_25 * V_26 ,
struct V_298 * V_299 )
{
struct V_8 * V_9 = V_26 -> V_28 ;
V_26 -> V_300 = V_301 | V_302 ;
V_26 -> V_303 = V_80 ;
if ( V_9 -> V_85 & V_87 )
V_26 -> V_303 |= V_82 ;
if ( V_9 -> V_85 & V_88 )
V_26 -> V_303 |= V_304 ;
V_26 -> V_79 = F_50 ( V_9 ) ;
V_26 -> V_305 = V_149 ;
V_26 -> V_306 = V_307 ;
V_26 -> V_308 = V_299 -> V_308 ;
V_26 -> V_309 = F_126 ( V_9 -> V_12 ) ;
V_26 -> V_310 = NULL ;
V_26 -> V_311 = F_15 ;
V_26 -> V_312 = F_16 ;
}
static struct V_298 * F_149 ( struct V_8 * V_9 )
{
T_2 V_299 = V_30 . V_31 ;
struct V_298 * V_313 = NULL ;
switch ( V_299 ) {
case 0xf :
V_313 = & V_314 [ V_315 ] ;
V_9 -> V_202 = & V_314 [ V_315 ] . V_202 ;
break;
case 0x10 :
V_313 = & V_314 [ V_316 ] ;
V_9 -> V_202 = & V_314 [ V_316 ] . V_202 ;
break;
case 0x15 :
V_313 = & V_314 [ V_317 ] ;
V_9 -> V_202 = & V_314 [ V_317 ] . V_202 ;
break;
default:
F_125 ( L_128 ) ;
return NULL ;
}
V_9 -> V_51 = V_30 . V_183 >> 4 ;
F_55 ( L_129 , V_313 -> V_308 ,
( V_299 == 0xf ?
( V_9 -> V_51 >= V_52 ? L_130
: L_131 )
: L_30 ) , V_9 -> V_57 ) ;
return V_313 ;
}
static int F_150 ( struct V_1 * V_12 )
{
struct V_8 * V_9 = NULL ;
struct V_298 * V_313 = NULL ;
struct V_25 * V_26 = NULL ;
int V_6 = 0 , V_64 ;
T_2 V_35 = F_151 ( V_12 ) ;
V_64 = - V_318 ;
V_9 = F_152 ( sizeof( struct V_8 ) , V_270 ) ;
if ( ! V_9 )
goto V_319;
V_9 -> V_57 = V_35 ;
V_9 -> V_12 = V_12 ;
V_64 = - V_11 ;
V_313 = F_149 ( V_9 ) ;
if ( ! V_313 )
goto V_320;
V_64 = - V_234 ;
V_6 = F_124 ( V_9 , V_313 -> V_231 , V_313 -> V_232 ) ;
if ( V_6 )
goto V_320;
F_128 ( V_9 ) ;
V_64 = - V_11 ;
V_9 -> V_254 = V_9 -> V_202 -> V_321 ( V_9 ) ;
if ( V_9 -> V_254 < 0 )
goto V_322;
V_64 = - V_318 ;
V_26 = F_153 ( 0 , V_9 -> V_53 [ 0 ] . V_71 , V_9 -> V_254 , V_35 ) ;
if ( ! V_26 )
goto V_322;
V_26 -> V_28 = V_9 ;
V_26 -> V_207 = & V_9 -> V_12 -> V_207 ;
F_148 ( V_26 , V_313 ) ;
if ( F_131 ( V_26 ) )
V_26 -> V_79 = V_80 ;
F_147 ( V_26 ) ;
V_64 = - V_234 ;
if ( F_154 ( V_26 ) ) {
F_32 ( L_132 ) ;
goto V_323;
}
if ( V_324 )
F_155 ( true ) ;
F_156 ( F_123 ) ;
V_129 [ V_35 ] = V_26 ;
F_157 ( & V_325 ) ;
return 0 ;
V_323:
F_158 ( V_26 ) ;
V_322:
F_127 ( V_9 ) ;
V_320:
F_159 ( V_9 ) ;
V_319:
return V_64 ;
}
static int T_6 F_160 ( struct V_1 * V_2 ,
const struct V_326 * V_327 )
{
T_2 V_35 = F_151 ( V_2 ) ;
struct V_1 * V_32 = F_161 ( V_35 ) -> V_328 ;
struct V_278 * V_214 ;
int V_64 = 0 ;
V_64 = F_162 ( V_2 ) ;
if ( V_64 < 0 ) {
F_60 ( L_133 , V_64 ) ;
return - V_329 ;
}
V_64 = - V_318 ;
V_214 = F_152 ( sizeof( struct V_278 ) , V_270 ) ;
if ( ! V_214 )
goto V_330;
V_331 [ V_35 ] = V_214 ;
if ( ! F_145 ( V_32 , V_35 ) ) {
V_64 = - V_234 ;
if ( ! V_332 )
goto V_333;
F_3 ( L_134 ) ;
if ( ! F_143 ( V_214 , V_35 , V_32 ) )
goto V_333;
}
V_64 = F_150 ( V_2 ) ;
if ( V_64 < 0 ) {
F_125 ( L_135 , V_35 ) ;
F_144 ( V_214 , V_35 , V_32 ) ;
}
return V_64 ;
V_333:
F_159 ( V_214 ) ;
V_331 [ V_35 ] = NULL ;
V_330:
return V_64 ;
}
static void T_7 F_163 ( struct V_1 * V_2 )
{
struct V_25 * V_26 ;
struct V_8 * V_9 ;
T_2 V_35 = F_151 ( V_2 ) ;
struct V_1 * V_32 = F_161 ( V_35 ) -> V_328 ;
struct V_278 * V_214 = V_331 [ V_35 ] ;
V_26 = F_164 ( & V_2 -> V_207 ) ;
if ( ! V_26 )
return;
V_9 = V_26 -> V_28 ;
F_144 ( V_214 , V_35 , V_32 ) ;
F_127 ( V_9 ) ;
F_155 ( false ) ;
F_165 ( F_123 ) ;
F_159 ( V_331 [ V_35 ] ) ;
V_331 [ V_35 ] = NULL ;
V_26 -> V_28 = NULL ;
V_129 [ V_35 ] = NULL ;
F_159 ( V_9 ) ;
F_158 ( V_26 ) ;
}
static void F_166 ( void )
{
struct V_25 * V_26 ;
struct V_8 * V_9 ;
if ( V_334 )
return;
V_26 = V_129 [ 0 ] ;
if ( V_26 ) {
V_9 = V_26 -> V_28 ;
V_334 =
F_167 ( & V_9 -> V_12 -> V_207 , V_149 ) ;
if ( ! V_334 ) {
F_168 ( L_136 ,
V_42 ) ;
F_168 ( L_137 ,
V_42 ) ;
}
}
}
static int T_8 F_169 ( void )
{
int V_6 = - V_234 ;
F_170 ( V_335 L_138 , V_307 ) ;
F_171 () ;
if ( F_172 () < 0 )
goto V_319;
V_6 = - V_318 ;
V_129 = F_152 ( F_173 () * sizeof( V_129 [ 0 ] ) , V_270 ) ;
V_331 = F_152 ( F_173 () * sizeof( V_331 [ 0 ] ) , V_270 ) ;
if ( ! ( V_129 && V_331 ) )
goto V_320;
V_272 = F_174 () ;
if ( ! V_272 )
goto V_320;
V_6 = F_175 ( & V_336 ) ;
if ( V_6 )
goto V_337;
V_6 = - V_234 ;
if ( ! F_176 ( & V_325 ) )
goto V_338;
F_166 () ;
return 0 ;
V_338:
F_177 ( & V_336 ) ;
V_337:
F_178 ( V_272 ) ;
V_272 = NULL ;
V_320:
F_159 ( V_129 ) ;
V_129 = NULL ;
F_159 ( V_331 ) ;
V_331 = NULL ;
V_319:
return V_6 ;
}
static void T_9 F_179 ( void )
{
if ( V_334 )
F_180 ( V_334 ) ;
F_177 ( & V_336 ) ;
F_159 ( V_331 ) ;
V_331 = NULL ;
F_159 ( V_129 ) ;
V_129 = NULL ;
F_178 ( V_272 ) ;
V_272 = NULL ;
}
