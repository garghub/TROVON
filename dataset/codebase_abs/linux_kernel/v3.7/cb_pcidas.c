static inline unsigned int F_1 ( unsigned int V_1 , unsigned int V_2 )
{
return ( V_2 & 0x3 ) << ( 8 + 2 * ( V_1 & 0x1 ) ) ;
}
static inline unsigned int F_2 ( unsigned int V_1 )
{
return 0x3 << ( 8 + 2 * ( V_1 & 0x1 ) ) ;
}
static inline unsigned int F_3 ( unsigned int V_1 )
{
return 1 << ( 5 + ( V_1 & 0x1 ) ) ;
}
static inline unsigned int F_4 ( unsigned int V_1 )
{
return 2 * ( V_1 & 0x1 ) ;
}
static inline unsigned int F_5 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
return V_8 | F_6 ( V_6 -> V_9 ) ;
}
static int F_7 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_14 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_15 = F_8 ( V_13 -> V_16 ) ;
unsigned int V_2 = F_9 ( V_13 -> V_16 ) ;
unsigned int V_17 = F_10 ( V_13 -> V_16 ) ;
unsigned int V_18 ;
int V_19 , V_20 ;
if ( V_13 -> V_16 & V_21 ) {
F_11 ( F_5 ( V_4 ) ,
V_6 -> V_22 + V_23 ) ;
V_15 = 0 ;
} else {
F_11 ( 0 , V_6 -> V_22 + V_23 ) ;
}
V_18 = F_12 ( V_15 ) | F_13 ( V_15 ) | F_14 ( V_2 ) ;
if ( V_2 & V_24 )
V_18 |= V_25 ;
if ( V_17 != V_26 )
V_18 |= V_27 ;
F_11 ( V_18 , V_6 -> V_22 + V_28 ) ;
F_11 ( 0 , V_6 -> V_29 + V_30 ) ;
for ( V_19 = 0 ; V_19 < V_13 -> V_19 ; V_19 ++ ) {
F_11 ( 0 , V_6 -> V_29 + V_31 ) ;
for ( V_20 = 0 ; V_20 < 10000 ; V_20 ++ ) {
if ( F_15 ( V_6 -> V_22 + V_28 ) & V_32 )
break;
}
if ( V_20 == 10000 )
return - V_33 ;
V_14 [ V_19 ] = F_15 ( V_6 -> V_29 + V_31 ) ;
}
return V_19 ;
}
static int F_16 ( struct V_3 * V_4 , struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_14 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
int V_34 = V_14 [ 0 ] ;
unsigned int V_35 = V_14 [ 1 ] ;
switch ( V_34 ) {
case V_36 :
if ( V_35 >= 8 ) {
F_17 ( V_4 -> V_37 ,
L_1 ,
V_35 ) ;
return - V_38 ;
}
V_6 -> V_9 = V_35 ;
break;
default:
return - V_38 ;
break;
}
return V_13 -> V_19 ;
}
static int F_18 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_12 * V_13 ,
unsigned int * V_14 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_15 = F_8 ( V_13 -> V_16 ) ;
unsigned int V_2 = F_9 ( V_13 -> V_16 ) ;
unsigned long V_39 ;
F_19 ( & V_4 -> V_40 , V_39 ) ;
V_6 -> V_41 &= ( ~ V_42 &
~ F_2 ( V_15 ) ) ;
V_6 -> V_41 |= ( V_43 | F_1 ( V_15 , V_2 ) ) ;
F_11 ( V_6 -> V_41 , V_6 -> V_22 + V_44 ) ;
F_20 ( & V_4 -> V_40 , V_39 ) ;
V_6 -> V_45 [ V_15 ] = V_14 [ 0 ] ;
F_11 ( V_14 [ 0 ] , V_6 -> V_46 + F_4 ( V_15 ) ) ;
return V_13 -> V_19 ;
}
static int F_21 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_14 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_15 = F_8 ( V_13 -> V_16 ) ;
unsigned int V_2 = F_9 ( V_13 -> V_16 ) ;
unsigned long V_39 ;
F_11 ( 0 , V_6 -> V_46 + V_47 ) ;
F_19 ( & V_4 -> V_40 , V_39 ) ;
V_6 -> V_41 &= ( ~ F_3 ( 0 ) & ~ F_3 ( 1 ) &
~ F_2 ( V_15 ) & ~ V_48 ) ;
V_6 -> V_41 |= ( V_43 | F_1 ( V_15 , V_2 ) |
F_3 ( V_15 ) | V_49 ) ;
F_11 ( V_6 -> V_41 , V_6 -> V_22 + V_44 ) ;
F_20 ( & V_4 -> V_40 , V_39 ) ;
V_6 -> V_45 [ V_15 ] = V_14 [ 0 ] ;
F_11 ( V_14 [ 0 ] , V_6 -> V_46 + V_50 ) ;
return V_13 -> V_19 ;
}
static int F_22 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_12 * V_13 ,
unsigned int * V_14 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
V_14 [ 0 ] = V_6 -> V_45 [ F_8 ( V_13 -> V_16 ) ] ;
return 1 ;
}
static int F_23 ( unsigned long V_51 )
{
static const int V_52 = 1000 ;
unsigned int V_20 ;
for ( V_20 = 0 ; V_20 < V_52 ; V_20 ++ ) {
if ( ( F_24 ( V_51 +
V_53 ) & V_54 )
== 0 )
return 0 ;
F_25 ( 1 ) ;
}
return - 1 ;
}
static int F_26 ( struct V_3 * V_4 , unsigned int V_55 ,
T_1 * V_14 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_56 = V_6 -> V_57 ;
if ( F_23 ( V_56 ) < 0 )
return - V_33 ;
F_27 ( V_58 | V_59 ,
V_56 + V_53 ) ;
F_27 ( V_55 & 0xff , V_56 + V_60 ) ;
F_27 ( V_58 | V_61 ,
V_56 + V_53 ) ;
F_27 ( ( V_55 >> 8 ) & 0xff , V_56 + V_60 ) ;
F_27 ( V_58 | V_62 , V_56 + V_53 ) ;
if ( F_23 ( V_56 ) < 0 )
return - V_33 ;
* V_14 = F_24 ( V_56 + V_60 ) ;
return 0 ;
}
static int F_28 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_14 )
{
T_1 V_63 ;
int V_64 ;
V_64 = F_26 ( V_4 , F_8 ( V_13 -> V_16 ) , & V_63 ) ;
if ( V_64 < 0 )
return V_64 ;
V_14 [ 0 ] = V_63 ;
return 1 ;
}
static void F_29 ( struct V_3 * V_4 ,
unsigned int V_65 ,
unsigned int V_66 ,
unsigned int V_67 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
static const int V_68 = 1 ;
unsigned int V_69 ;
for ( V_69 = 1 << ( V_67 - 1 ) ; V_69 ; V_69 >>= 1 ) {
if ( V_66 & V_69 )
V_65 |= V_70 ;
else
V_65 &= ~ V_70 ;
F_25 ( V_68 ) ;
F_11 ( V_65 , V_6 -> V_22 + V_23 ) ;
}
}
static int F_30 ( struct V_3 * V_4 , unsigned int V_55 ,
T_1 V_71 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
static const int V_72 = 8 ;
static const int V_67 = 11 ;
unsigned int V_66 = ( ( V_55 & 0x7 ) << 8 ) | V_71 ;
static const int V_73 = 1 ;
if ( V_55 >= V_72 ) {
F_31 ( V_4 , L_2 ) ;
return - 1 ;
}
if ( V_71 == V_6 -> V_74 [ V_55 ] )
return 1 ;
V_6 -> V_74 [ V_55 ] = V_71 ;
F_29 ( V_4 , F_5 ( V_4 ) , V_66 ,
V_67 ) ;
F_25 ( V_73 ) ;
F_11 ( F_5 ( V_4 ) | V_75 ,
V_6 -> V_22 + V_23 ) ;
F_25 ( V_73 ) ;
F_11 ( F_5 ( V_4 ) , V_6 -> V_22 + V_23 ) ;
return 1 ;
}
static int F_32 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_14 )
{
const unsigned int V_1 = F_8 ( V_13 -> V_16 ) ;
return F_30 ( V_4 , V_1 , V_14 [ 0 ] ) ;
}
static int F_33 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_14 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
V_14 [ 0 ] = V_6 -> V_74 [ F_8 ( V_13 -> V_16 ) ] ;
return 1 ;
}
static void F_34 ( struct V_3 * V_4 , unsigned int V_71 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_76 ;
if ( V_6 -> V_77 != V_71 ) {
V_6 -> V_77 = V_71 ;
V_76 = V_6 -> V_22 + V_23 ;
V_71 &= 0xff ;
V_71 |= F_5 ( V_4 ) ;
F_11 ( V_71 , V_76 ) ;
F_25 ( 1 ) ;
F_11 ( V_71 | V_78 , V_76 ) ;
F_25 ( 1 ) ;
F_11 ( V_71 , V_76 ) ;
F_25 ( 1 ) ;
}
}
static int F_35 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_14 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_13 -> V_19 ; V_20 ++ )
F_34 ( V_4 , V_14 [ V_20 ] ) ;
return V_13 -> V_19 ;
}
static int F_36 ( struct V_3 * V_4 ,
struct V_10 * V_11 , struct V_12 * V_13 ,
unsigned int * V_14 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
V_14 [ 0 ] = V_6 -> V_77 ;
return 1 ;
}
static int F_37 ( struct V_3 * V_4 , T_1 V_71 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
static const int V_67 = 7 ;
unsigned int V_66 = V_71 & 0x7f ;
unsigned int V_65 ;
static const int V_79 = 1 ;
V_65 = F_5 ( V_4 ) | V_80 ;
F_25 ( V_79 ) ;
F_11 ( V_65 , V_6 -> V_22 + V_23 ) ;
F_29 ( V_4 , V_65 , V_66 ,
V_67 ) ;
F_25 ( V_79 ) ;
F_11 ( F_5 ( V_4 ) , V_6 -> V_22 + V_23 ) ;
return 0 ;
}
static int F_38 ( struct V_3 * V_4 , unsigned int V_1 ,
T_1 V_71 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
static const int V_67 = 10 ;
unsigned int V_66 = ( ( V_1 & 0x3 ) << 8 ) | ( V_71 & 0xff ) ;
unsigned int V_65 ;
static const int V_81 = 1 ;
V_65 = F_5 ( V_4 ) | V_80 ;
F_25 ( V_81 ) ;
F_11 ( V_65 , V_6 -> V_22 + V_23 ) ;
F_29 ( V_4 , V_65 , V_66 ,
V_67 ) ;
F_25 ( V_81 ) ;
F_11 ( F_5 ( V_4 ) , V_6 -> V_22 + V_23 ) ;
return 0 ;
}
static int F_39 ( struct V_3 * V_4 ,
unsigned int V_1 , unsigned int V_71 )
{
const struct V_82 * V_83 = F_40 ( V_4 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_6 -> V_84 [ V_1 ] == V_71 )
return 1 ;
V_6 -> V_84 [ V_1 ] = V_71 ;
switch ( V_83 -> V_85 ) {
case V_86 :
F_37 ( V_4 , V_71 ) ;
break;
case V_87 :
F_38 ( V_4 , V_1 , V_71 ) ;
break;
default:
F_31 ( V_4 , L_3 ) ;
return - 1 ;
break;
}
return 1 ;
}
static int F_41 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_14 )
{
unsigned int V_1 = F_8 ( V_13 -> V_16 ) ;
return F_39 ( V_4 , V_1 , V_14 [ 0 ] ) ;
}
static int F_42 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_14 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_1 = F_8 ( V_13 -> V_16 ) ;
V_14 [ 0 ] = V_6 -> V_84 [ V_1 ] ;
return 1 ;
}
static int F_43 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_88 * V_89 )
{
const struct V_82 * V_83 = F_40 ( V_4 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
int V_90 = 0 ;
int V_91 ;
int V_20 , V_92 , V_93 ;
V_90 |= F_44 ( & V_89 -> V_94 , V_95 | V_96 ) ;
V_90 |= F_44 ( & V_89 -> V_97 ,
V_98 | V_99 | V_96 ) ;
V_90 |= F_44 ( & V_89 -> V_100 ,
V_99 | V_95 | V_96 ) ;
V_90 |= F_44 ( & V_89 -> V_101 , V_102 ) ;
V_90 |= F_44 ( & V_89 -> V_103 , V_102 | V_104 ) ;
if ( V_90 )
return 1 ;
V_90 |= F_45 ( V_89 -> V_94 ) ;
V_90 |= F_45 ( V_89 -> V_97 ) ;
V_90 |= F_45 ( V_89 -> V_100 ) ;
V_90 |= F_45 ( V_89 -> V_103 ) ;
if ( V_89 -> V_97 == V_98 && V_89 -> V_100 == V_95 )
V_90 |= - V_38 ;
if ( V_89 -> V_97 != V_98 && V_89 -> V_100 != V_95 )
V_90 |= - V_38 ;
if ( V_89 -> V_94 == V_96 &&
( V_89 -> V_100 == V_96 || V_89 -> V_97 == V_96 ) )
V_90 |= - V_38 ;
if ( V_90 )
return 2 ;
switch ( V_89 -> V_94 ) {
case V_96 :
if ( ( V_89 -> V_105
& ( V_106 & ~ ( V_107 | V_108 ) ) ) != 0 ) {
V_89 -> V_105 &=
~ ( V_106 & ~ ( V_107 | V_108 ) ) ;
V_90 ++ ;
}
if ( ! V_83 -> V_109 && ( V_89 -> V_105 & V_108 ) ) {
V_89 -> V_105 &= ( V_106 & ~ V_108 ) ;
V_90 ++ ;
}
break;
default:
if ( V_89 -> V_105 != 0 ) {
V_89 -> V_105 = 0 ;
V_90 ++ ;
}
break;
}
if ( V_89 -> V_97 == V_99 ) {
if ( V_89 -> V_110 <
V_83 -> V_111 * V_89 -> V_112 ) {
V_89 -> V_110 =
V_83 -> V_111 * V_89 -> V_112 ;
V_90 ++ ;
}
}
if ( V_89 -> V_100 == V_99 ) {
if ( V_89 -> V_113 < V_83 -> V_111 ) {
V_89 -> V_113 = V_83 -> V_111 ;
V_90 ++ ;
}
}
if ( V_89 -> V_114 != V_89 -> V_112 ) {
V_89 -> V_114 = V_89 -> V_112 ;
V_90 ++ ;
}
if ( V_89 -> V_103 == V_104 ) {
if ( V_89 -> V_115 != 0 ) {
V_89 -> V_115 = 0 ;
V_90 ++ ;
}
}
if ( V_90 )
return 3 ;
if ( V_89 -> V_97 == V_99 ) {
V_91 = V_89 -> V_110 ;
F_46 ( V_116 ,
& ( V_6 -> V_117 ) ,
& ( V_6 -> V_118 ) ,
& ( V_89 -> V_110 ) ,
V_89 -> V_39 & V_119 ) ;
if ( V_91 != V_89 -> V_110 )
V_90 ++ ;
}
if ( V_89 -> V_100 == V_99 ) {
V_91 = V_89 -> V_113 ;
F_46 ( V_116 ,
& ( V_6 -> V_117 ) ,
& ( V_6 -> V_118 ) ,
& ( V_89 -> V_113 ) ,
V_89 -> V_39 & V_119 ) ;
if ( V_91 != V_89 -> V_113 )
V_90 ++ ;
}
if ( V_90 )
return 4 ;
if ( V_89 -> V_120 ) {
V_92 = F_9 ( V_89 -> V_120 [ 0 ] ) ;
V_93 = F_8 ( V_89 -> V_120 [ 0 ] ) ;
for ( V_20 = 1 ; V_20 < V_89 -> V_112 ; V_20 ++ ) {
if ( F_8 ( V_89 -> V_120 [ V_20 ] ) !=
( V_93 + V_20 ) % V_11 -> V_121 ) {
F_31 ( V_4 ,
L_4 ) ;
V_90 ++ ;
}
if ( F_9 ( V_89 -> V_120 [ V_20 ] ) != V_92 ) {
F_31 ( V_4 ,
L_5 ) ;
V_90 ++ ;
}
}
}
if ( V_90 )
return 5 ;
return 0 ;
}
static void F_47 ( struct V_3 * V_4 , unsigned int * V_122 ,
int V_123 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
F_46 ( V_116 , & ( V_6 -> V_117 ) ,
& ( V_6 -> V_118 ) , V_122 ,
V_123 & V_119 ) ;
F_48 ( V_6 -> V_124 + V_125 , 0 , 1 ,
V_6 -> V_117 , 2 ) ;
F_48 ( V_6 -> V_124 + V_125 , 0 , 2 ,
V_6 -> V_118 , 2 ) ;
}
static int F_49 ( struct V_3 * V_4 ,
struct V_10 * V_11 )
{
const struct V_82 * V_83 = F_40 ( V_4 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_126 * V_127 = V_11 -> V_127 ;
struct V_88 * V_89 = & V_127 -> V_89 ;
unsigned int V_18 ;
unsigned long V_39 ;
F_11 ( 0 , V_6 -> V_22 + V_23 ) ;
F_11 ( 0 , V_6 -> V_22 + V_128 ) ;
F_11 ( 0 , V_6 -> V_29 + V_30 ) ;
V_18 = F_12 ( F_8 ( V_89 -> V_120 [ 0 ] ) ) |
F_13 ( F_8 ( V_89 -> V_120 [ V_89 -> V_112 - 1 ] ) ) |
F_14 ( F_9 ( V_89 -> V_120 [ 0 ] ) ) ;
if ( F_9 ( V_89 -> V_120 [ 0 ] ) & V_24 )
V_18 |= V_25 ;
if ( F_10 ( V_89 -> V_120 [ 0 ] ) != V_26 )
V_18 |= V_27 ;
if ( V_89 -> V_100 == V_96 || V_89 -> V_97 == V_96 )
V_18 |= V_129 ;
else
V_18 |= V_130 ;
F_11 ( V_18 , V_6 -> V_22 + V_28 ) ;
if ( V_89 -> V_100 == V_99 )
F_47 ( V_4 , & V_89 -> V_113 ,
V_89 -> V_39 & V_119 ) ;
else if ( V_89 -> V_97 == V_99 )
F_47 ( V_4 , & V_89 -> V_110 ,
V_89 -> V_39 & V_119 ) ;
if ( V_89 -> V_103 == V_102 )
V_6 -> V_131 = V_89 -> V_112 * V_89 -> V_115 ;
F_19 ( & V_4 -> V_40 , V_39 ) ;
V_6 -> V_132 |= V_133 ;
V_6 -> V_132 &= ~ V_134 ;
if ( V_89 -> V_39 & V_135 ) {
if ( V_89 -> V_100 == V_95 && V_89 -> V_112 > 1 ) {
V_6 -> V_132 |= V_136 ;
} else {
V_6 -> V_132 |= V_137 ;
}
} else {
V_6 -> V_132 |= V_138 ;
}
F_11 ( V_6 -> V_132 | V_139 | INT | V_140 ,
V_6 -> V_22 + V_141 ) ;
F_20 ( & V_4 -> V_40 , V_39 ) ;
V_18 = 0 ;
if ( V_89 -> V_94 == V_95 )
V_18 |= V_142 ;
else if ( V_89 -> V_94 == V_96 ) {
V_18 |= V_143 | V_144 | V_145 ;
if ( V_83 -> V_109 ) {
if ( V_89 -> V_105 & V_108 )
V_18 |= V_146 ;
if ( V_89 -> V_105 & V_107 )
V_18 |= V_147 ;
}
} else {
F_31 ( V_4 , L_6 ) ;
return - 1 ;
}
if ( V_89 -> V_100 == V_95 && V_89 -> V_112 > 1 )
V_18 |= V_148 ;
F_11 ( V_18 , V_6 -> V_22 + V_128 ) ;
return 0 ;
}
static int F_50 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_88 * V_89 )
{
const struct V_82 * V_83 = F_40 ( V_4 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
int V_90 = 0 ;
int V_91 ;
V_90 |= F_44 ( & V_89 -> V_94 , V_149 ) ;
V_90 |= F_44 ( & V_89 -> V_97 ,
V_99 | V_96 ) ;
V_90 |= F_44 ( & V_89 -> V_100 , V_95 ) ;
V_90 |= F_44 ( & V_89 -> V_101 , V_102 ) ;
V_90 |= F_44 ( & V_89 -> V_103 , V_102 | V_104 ) ;
if ( V_90 )
return 1 ;
V_90 |= F_45 ( V_89 -> V_97 ) ;
V_90 |= F_45 ( V_89 -> V_103 ) ;
if ( V_90 )
return 2 ;
if ( V_89 -> V_105 != 0 ) {
V_89 -> V_105 = 0 ;
V_90 ++ ;
}
if ( V_89 -> V_97 == V_99 ) {
if ( V_89 -> V_110 < V_83 -> V_150 ) {
V_89 -> V_110 = V_83 -> V_150 ;
V_90 ++ ;
}
}
if ( V_89 -> V_114 != V_89 -> V_112 ) {
V_89 -> V_114 = V_89 -> V_112 ;
V_90 ++ ;
}
if ( V_89 -> V_103 == V_104 ) {
if ( V_89 -> V_115 != 0 ) {
V_89 -> V_115 = 0 ;
V_90 ++ ;
}
}
if ( V_90 )
return 3 ;
if ( V_89 -> V_97 == V_99 ) {
V_91 = V_89 -> V_110 ;
F_46 ( V_116 ,
& ( V_6 -> V_151 ) ,
& ( V_6 -> V_152 ) ,
& ( V_89 -> V_110 ) ,
V_89 -> V_39 & V_119 ) ;
if ( V_91 != V_89 -> V_110 )
V_90 ++ ;
}
if ( V_90 )
return 4 ;
if ( V_89 -> V_120 && V_89 -> V_112 > 1 ) {
if ( F_8 ( V_89 -> V_120 [ 0 ] ) != 0 ||
F_8 ( V_89 -> V_120 [ 1 ] ) != 1 ) {
F_31 ( V_4 ,
L_7 ) ;
V_90 ++ ;
}
}
if ( V_90 )
return 5 ;
return 0 ;
}
static int F_51 ( struct V_3 * V_4 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_39 ;
F_19 ( & V_4 -> V_40 , V_39 ) ;
V_6 -> V_132 &= ~ V_133 & ~ V_153 ;
F_11 ( V_6 -> V_132 , V_6 -> V_22 + V_141 ) ;
F_20 ( & V_4 -> V_40 , V_39 ) ;
F_11 ( 0 , V_6 -> V_22 + V_128 ) ;
F_11 ( 0 , V_6 -> V_22 + V_28 ) ;
return 0 ;
}
static int F_52 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
unsigned int V_154 )
{
const struct V_82 * V_83 = F_40 ( V_4 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_155 , V_156 = V_83 -> V_157 ;
struct V_126 * V_127 = V_11 -> V_127 ;
struct V_88 * V_89 = & V_11 -> V_127 -> V_89 ;
unsigned long V_39 ;
if ( V_154 != 0 )
return - V_38 ;
if ( V_89 -> V_103 == V_102 && V_6 -> V_158 < V_156 )
V_156 = V_6 -> V_158 ;
V_155 = F_53 ( V_11 , V_6 -> V_159 ,
V_156 * sizeof( short ) ) ;
V_156 = V_155 / sizeof( short ) ;
if ( V_89 -> V_103 == V_102 )
V_6 -> V_158 -= V_156 ;
F_54 ( V_6 -> V_46 + V_50 , V_6 -> V_159 , V_155 ) ;
F_19 ( & V_4 -> V_40 , V_39 ) ;
V_6 -> V_132 |= V_160 | V_161 ;
F_11 ( V_6 -> V_132 | V_162 | V_163 ,
V_6 -> V_22 + V_141 ) ;
V_6 -> V_41 |= V_49 | V_43 | V_164 ;
F_11 ( V_6 -> V_41 , V_6 -> V_22 + V_44 ) ;
F_20 ( & V_4 -> V_40 , V_39 ) ;
V_127 -> V_165 = NULL ;
return 0 ;
}
static int F_55 ( struct V_3 * V_4 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_126 * V_127 = V_11 -> V_127 ;
struct V_88 * V_89 = & V_127 -> V_89 ;
unsigned int V_20 ;
unsigned long V_39 ;
F_19 ( & V_4 -> V_40 , V_39 ) ;
for ( V_20 = 0 ; V_20 < V_89 -> V_112 ; V_20 ++ ) {
V_6 -> V_41 |=
F_3 ( F_8 ( V_89 -> V_120 [ V_20 ] ) ) ;
V_6 -> V_41 |= F_1 ( F_8 ( V_89 -> V_120 [ V_20 ] ) ,
F_9 ( V_89 ->
V_120 [ V_20 ] ) ) ;
}
F_11 ( V_6 -> V_41 , V_6 -> V_22 + V_44 ) ;
F_20 ( & V_4 -> V_40 , V_39 ) ;
F_11 ( 0 , V_6 -> V_46 + V_47 ) ;
if ( V_89 -> V_97 == V_99 ) {
F_46 ( V_116 ,
& ( V_6 -> V_151 ) ,
& ( V_6 -> V_152 ) ,
& ( V_89 -> V_110 ) ,
V_89 -> V_39 ) ;
F_48 ( V_6 -> V_124 + V_166 , 0 , 1 ,
V_6 -> V_151 , 2 ) ;
F_48 ( V_6 -> V_124 + V_166 , 0 , 2 ,
V_6 -> V_152 , 2 ) ;
}
if ( V_89 -> V_103 == V_102 )
V_6 -> V_158 = V_89 -> V_112 * V_89 -> V_115 ;
F_19 ( & V_4 -> V_40 , V_39 ) ;
switch ( V_89 -> V_97 ) {
case V_99 :
V_6 -> V_41 |= V_167 ;
break;
case V_96 :
V_6 -> V_41 |= V_168 ;
break;
default:
F_20 ( & V_4 -> V_40 , V_39 ) ;
F_31 ( V_4 , L_8 ) ;
return - 1 ;
break;
}
F_20 ( & V_4 -> V_40 , V_39 ) ;
V_127 -> V_165 = F_52 ;
return 0 ;
}
static int F_56 ( struct V_3 * V_4 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_39 ;
F_19 ( & V_4 -> V_40 , V_39 ) ;
V_6 -> V_132 &= ~ V_161 & ~ V_160 ;
F_11 ( V_6 -> V_132 , V_6 -> V_22 + V_141 ) ;
V_6 -> V_41 &= ~ V_43 & ~ V_48 ;
F_11 ( V_6 -> V_41 , V_6 -> V_22 + V_44 ) ;
F_20 ( & V_4 -> V_40 , V_39 ) ;
return 0 ;
}
static void F_57 ( struct V_3 * V_4 , unsigned int V_169 )
{
const struct V_82 * V_83 = F_40 ( V_4 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_10 * V_11 = V_4 -> V_170 ;
struct V_126 * V_127 = V_11 -> V_127 ;
struct V_88 * V_89 = & V_127 -> V_89 ;
unsigned int V_171 = V_83 -> V_157 / 2 ;
unsigned int V_156 ;
unsigned long V_39 ;
V_127 -> V_172 = 0 ;
if ( V_169 & V_162 ) {
F_19 ( & V_4 -> V_40 , V_39 ) ;
F_11 ( V_6 -> V_132 | V_162 ,
V_6 -> V_22 + V_141 ) ;
F_20 ( & V_4 -> V_40 , V_39 ) ;
if ( F_15 ( V_6 -> V_46 + V_44 ) & V_164 ) {
if ( V_89 -> V_103 == V_104 ||
( V_89 -> V_103 == V_102
&& V_6 -> V_158 ) ) {
F_31 ( V_4 , L_9 ) ;
F_56 ( V_4 , V_11 ) ;
V_127 -> V_172 |= V_173 ;
}
V_127 -> V_172 |= V_174 ;
}
} else if ( V_169 & V_163 ) {
unsigned int V_155 ;
V_156 = V_171 ;
if ( V_89 -> V_103 == V_102 &&
V_6 -> V_158 < V_156 )
V_156 = V_6 -> V_158 ;
V_155 =
F_53 ( V_11 , V_6 -> V_159 ,
V_156 * sizeof( short ) ) ;
V_156 = V_155 / sizeof( short ) ;
if ( V_127 -> V_89 . V_103 == V_102 )
V_6 -> V_158 -= V_156 ;
F_54 ( V_6 -> V_46 + V_50 , V_6 -> V_159 ,
V_156 ) ;
F_19 ( & V_4 -> V_40 , V_39 ) ;
F_11 ( V_6 -> V_132 | V_163 ,
V_6 -> V_22 + V_141 ) ;
F_20 ( & V_4 -> V_40 , V_39 ) ;
}
F_58 ( V_4 , V_11 ) ;
}
static T_2 F_59 ( int V_175 , void * V_176 )
{
struct V_3 * V_4 = (struct V_3 * ) V_176 ;
const struct V_82 * V_83 = F_40 ( V_4 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_10 * V_11 = V_4 -> V_177 ;
struct V_126 * V_127 ;
int V_169 , V_178 ;
int V_171 = V_83 -> V_157 / 2 ;
unsigned int V_179 , V_20 ;
static const int V_52 = 10000 ;
unsigned long V_39 ;
if ( V_4 -> V_180 == 0 )
return V_181 ;
V_127 = V_11 -> V_127 ;
V_127 -> V_172 = 0 ;
V_178 = F_60 ( V_6 -> V_57 + V_182 ) ;
if ( ( V_183 & V_178 ) == 0 )
return V_181 ;
F_61 ( V_6 -> V_57 + V_184 ) ;
F_62 ( V_6 -> V_185 | V_186 ,
V_6 -> V_57 + V_182 ) ;
V_169 = F_15 ( V_6 -> V_22 + V_141 ) ;
if ( V_169 & ( V_163 | V_162 ) )
F_57 ( V_4 , V_169 ) ;
if ( V_169 & V_187 ) {
V_179 = V_171 ;
if ( V_127 -> V_89 . V_103 == V_102 &&
V_179 > V_6 -> V_131 ) {
V_179 = V_6 -> V_131 ;
}
F_63 ( V_6 -> V_29 + V_31 , V_6 -> V_188 ,
V_179 ) ;
F_64 ( V_11 , V_6 -> V_188 ,
V_179 * sizeof( short ) ) ;
V_6 -> V_131 -= V_179 ;
if ( V_127 -> V_89 . V_103 == V_102 && V_6 -> V_131 == 0 ) {
V_127 -> V_172 |= V_174 ;
F_51 ( V_4 , V_11 ) ;
}
F_19 ( & V_4 -> V_40 , V_39 ) ;
F_11 ( V_6 -> V_132 | INT ,
V_6 -> V_22 + V_141 ) ;
F_20 ( & V_4 -> V_40 , V_39 ) ;
} else if ( V_169 & ( V_189 | V_190 ) ) {
for ( V_20 = 0 ; V_20 < V_52 ; V_20 ++ ) {
if ( ( V_191 & F_15 ( V_6 -> V_22 +
V_141 ) ) == 0 )
break;
F_65 ( V_11 , F_15 ( V_6 -> V_29 ) ) ;
if ( V_127 -> V_89 . V_103 == V_102 &&
-- V_6 -> V_131 == 0 ) {
F_51 ( V_4 , V_11 ) ;
V_127 -> V_172 |= V_174 ;
break;
}
}
F_19 ( & V_4 -> V_40 , V_39 ) ;
F_11 ( V_6 -> V_132 | INT ,
V_6 -> V_22 + V_141 ) ;
F_20 ( & V_4 -> V_40 , V_39 ) ;
} else if ( V_169 & V_139 ) {
F_31 ( V_4 ,
L_10 ) ;
F_19 ( & V_4 -> V_40 , V_39 ) ;
F_11 ( V_6 -> V_132 | V_139 ,
V_6 -> V_22 + V_141 ) ;
F_20 ( & V_4 -> V_40 , V_39 ) ;
}
if ( V_169 & V_140 ) {
F_31 ( V_4 , L_11 ) ;
F_19 ( & V_4 -> V_40 , V_39 ) ;
F_11 ( V_6 -> V_132 | V_140 ,
V_6 -> V_22 + V_141 ) ;
F_20 ( & V_4 -> V_40 , V_39 ) ;
F_51 ( V_4 , V_11 ) ;
V_127 -> V_172 |= V_174 | V_173 ;
}
F_58 ( V_4 , V_11 ) ;
return V_192 ;
}
static const void * F_66 ( struct V_3 * V_4 ,
struct V_193 * V_194 )
{
const struct V_82 * V_83 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < F_67 ( V_195 ) ; V_20 ++ ) {
V_83 = & V_195 [ V_20 ] ;
if ( V_83 -> V_196 == V_194 -> V_197 )
return V_83 ;
}
return NULL ;
}
static int F_68 ( struct V_3 * V_4 ,
struct V_193 * V_194 )
{
const struct V_82 * V_83 ;
struct V_5 * V_6 ;
struct V_10 * V_11 ;
int V_20 ;
int V_198 ;
F_69 ( V_4 , & V_194 -> V_4 ) ;
V_83 = F_66 ( V_4 , V_194 ) ;
if ( ! V_83 )
return - V_199 ;
V_4 -> V_200 = V_83 ;
V_4 -> V_201 = V_83 -> V_202 ;
V_198 = F_70 ( V_4 , sizeof( * V_6 ) ) ;
if ( V_198 )
return V_198 ;
V_6 = V_4 -> V_7 ;
V_198 = F_71 ( V_194 , V_4 -> V_201 ) ;
if ( V_198 )
return V_198 ;
V_6 -> V_57 = F_72 ( V_194 , 0 ) ;
V_6 -> V_22 = F_72 ( V_194 , 1 ) ;
V_6 -> V_29 = F_72 ( V_194 , 2 ) ;
V_6 -> V_124 = F_72 ( V_194 , 3 ) ;
if ( V_83 -> V_203 )
V_6 -> V_46 = F_72 ( V_194 , 4 ) ;
F_62 ( V_186 ,
V_6 -> V_57 + V_182 ) ;
if ( F_73 ( V_194 -> V_175 , F_59 ,
V_204 , V_4 -> V_205 -> V_206 , V_4 ) ) {
F_74 ( V_4 -> V_37 , L_12 ,
V_194 -> V_175 ) ;
return - V_38 ;
}
V_4 -> V_175 = V_194 -> V_175 ;
V_198 = F_75 ( V_4 , 7 ) ;
if ( V_198 )
return V_198 ;
V_11 = & V_4 -> V_207 [ 0 ] ;
V_4 -> V_177 = V_11 ;
V_11 -> type = V_208 ;
V_11 -> V_209 = V_210 | V_211 | V_212 | V_213 ;
V_11 -> V_121 = V_83 -> V_214 ;
V_11 -> V_215 = V_83 -> V_214 ;
V_11 -> V_216 = ( 1 << V_83 -> V_217 ) - 1 ;
V_11 -> V_218 = V_83 -> V_219 ;
V_11 -> V_220 = F_7 ;
V_11 -> V_221 = F_16 ;
V_11 -> V_222 = F_49 ;
V_11 -> V_223 = F_43 ;
V_11 -> V_224 = F_51 ;
V_11 = & V_4 -> V_207 [ 1 ] ;
if ( V_83 -> V_203 ) {
V_11 -> type = V_225 ;
V_11 -> V_209 = V_210 | V_226 | V_211 ;
V_11 -> V_121 = V_83 -> V_203 ;
V_11 -> V_216 = ( 1 << V_83 -> V_217 ) - 1 ;
V_11 -> V_218 = & V_227 ;
V_11 -> V_220 = F_22 ;
if ( V_83 -> V_228 ) {
V_4 -> V_170 = V_11 ;
V_11 -> V_209 |= V_229 ;
V_11 -> V_230 = F_21 ;
V_11 -> V_223 = F_50 ;
V_11 -> V_222 = F_55 ;
V_11 -> V_224 = F_56 ;
} else {
V_11 -> V_230 = F_18 ;
}
} else {
V_11 -> type = V_231 ;
}
V_11 = & V_4 -> V_207 [ 2 ] ;
V_198 = F_76 ( V_4 , V_11 , NULL ,
V_6 -> V_124 + V_232 ) ;
if ( V_198 )
return V_198 ;
V_11 = & V_4 -> V_207 [ 3 ] ;
V_11 -> type = V_233 ;
V_11 -> V_209 = V_210 | V_234 ;
V_11 -> V_121 = 256 ;
V_11 -> V_216 = 0xff ;
V_11 -> V_220 = F_28 ;
V_11 = & V_4 -> V_207 [ 4 ] ;
V_11 -> type = V_235 ;
V_11 -> V_209 = V_210 | V_226 | V_234 ;
V_11 -> V_121 = V_236 ;
V_11 -> V_216 = 0xff ;
V_11 -> V_220 = F_33 ;
V_11 -> V_230 = F_32 ;
for ( V_20 = 0 ; V_20 < V_11 -> V_121 ; V_20 ++ )
F_30 ( V_4 , V_20 , V_11 -> V_216 / 2 ) ;
V_11 = & V_4 -> V_207 [ 5 ] ;
V_11 -> type = V_235 ;
V_11 -> V_209 = V_210 | V_226 | V_234 ;
if ( V_83 -> V_85 == V_86 ) {
V_11 -> V_121 = V_237 ;
V_11 -> V_216 = 0x7f ;
} else {
V_11 -> V_121 = V_238 ;
V_11 -> V_216 = 0xff ;
}
V_11 -> V_220 = F_42 ;
V_11 -> V_230 = F_41 ;
for ( V_20 = 0 ; V_20 < V_11 -> V_121 ; V_20 ++ )
F_39 ( V_4 , V_20 , V_11 -> V_216 / 2 ) ;
V_11 = & V_4 -> V_207 [ 6 ] ;
if ( V_83 -> V_239 ) {
V_11 -> type = V_235 ;
V_11 -> V_209 = V_210 | V_226 | V_234 ;
V_11 -> V_121 = V_240 ;
V_11 -> V_220 = F_36 ;
V_11 -> V_230 = F_35 ;
V_11 -> V_216 = 0xff ;
F_34 ( V_4 , V_11 -> V_216 / 2 ) ;
} else
V_11 -> type = V_231 ;
F_60 ( V_6 -> V_57 + V_184 ) ;
V_6 -> V_185 =
F_77 ( 3 ) | F_78 ( 3 ) |
V_241 ;
F_62 ( V_6 -> V_185 | V_186 ,
V_6 -> V_57 + V_182 ) ;
F_79 ( V_4 -> V_37 , L_13 ,
V_4 -> V_205 -> V_206 , V_4 -> V_201 ) ;
return 0 ;
}
static void F_80 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_193 * V_194 = F_81 ( V_4 ) ;
if ( V_6 ) {
if ( V_6 -> V_57 ) {
F_62 ( V_186 ,
V_6 -> V_57 + V_182 ) ;
}
}
if ( V_4 -> V_175 )
F_82 ( V_4 -> V_175 , V_4 ) ;
if ( V_4 -> V_207 )
F_83 ( V_4 , & V_4 -> V_207 [ 2 ] ) ;
if ( V_194 ) {
if ( V_6 -> V_57 )
F_84 ( V_194 ) ;
}
}
static int T_3 F_85 ( struct V_193 * V_4 ,
const struct V_242 * V_243 )
{
return F_86 ( V_4 , & V_244 ) ;
}
static void T_4 F_87 ( struct V_193 * V_4 )
{
F_88 ( V_4 ) ;
}
