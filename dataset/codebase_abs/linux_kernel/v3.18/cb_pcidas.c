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
struct V_12 * V_13 ,
unsigned long V_14 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_15 ;
V_15 = F_8 ( V_6 -> V_16 + V_17 ) ;
if ( V_15 & V_18 )
return 0 ;
return - V_19 ;
}
static int F_9 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_20 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_21 = F_10 ( V_13 -> V_22 ) ;
unsigned int V_2 = F_11 ( V_13 -> V_22 ) ;
unsigned int V_23 = F_12 ( V_13 -> V_22 ) ;
unsigned int V_24 ;
int V_25 ;
int V_26 ;
if ( V_13 -> V_22 & V_27 ) {
F_13 ( F_5 ( V_4 ) ,
V_6 -> V_16 + V_28 ) ;
V_21 = 0 ;
} else {
F_13 ( 0 , V_6 -> V_16 + V_28 ) ;
}
V_24 = F_14 ( V_21 ) | F_15 ( V_21 ) | F_16 ( V_2 ) ;
if ( V_2 & V_29 )
V_24 |= V_30 ;
if ( V_23 != V_31 )
V_24 |= V_32 ;
F_13 ( V_24 , V_6 -> V_16 + V_17 ) ;
F_13 ( 0 , V_6 -> V_33 + V_34 ) ;
for ( V_26 = 0 ; V_26 < V_13 -> V_26 ; V_26 ++ ) {
F_13 ( 0 , V_6 -> V_33 + V_35 ) ;
V_25 = F_17 ( V_4 , V_11 , V_13 , F_7 , 0 ) ;
if ( V_25 )
return V_25 ;
V_20 [ V_26 ] = F_8 ( V_6 -> V_33 + V_35 ) ;
}
return V_26 ;
}
static int F_18 ( struct V_3 * V_4 , struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_20 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
int V_36 = V_20 [ 0 ] ;
unsigned int V_37 = V_20 [ 1 ] ;
switch ( V_36 ) {
case V_38 :
if ( V_37 >= 8 ) {
F_19 ( V_4 -> V_39 ,
L_1 ,
V_37 ) ;
return - V_40 ;
}
V_6 -> V_9 = V_37 ;
break;
default:
return - V_40 ;
}
return V_13 -> V_26 ;
}
static int F_20 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_12 * V_13 ,
unsigned int * V_20 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_21 = F_10 ( V_13 -> V_22 ) ;
unsigned int V_2 = F_11 ( V_13 -> V_22 ) ;
unsigned long V_41 ;
F_21 ( & V_4 -> V_42 , V_41 ) ;
V_6 -> V_43 &= ( ~ V_44 &
~ F_2 ( V_21 ) ) ;
V_6 -> V_43 |= ( V_45 | F_1 ( V_21 , V_2 ) ) ;
F_13 ( V_6 -> V_43 , V_6 -> V_16 + V_46 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
V_11 -> V_47 [ V_21 ] = V_20 [ 0 ] ;
F_13 ( V_20 [ 0 ] , V_6 -> V_48 + F_4 ( V_21 ) ) ;
return V_13 -> V_26 ;
}
static int F_23 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_20 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_21 = F_10 ( V_13 -> V_22 ) ;
unsigned int V_2 = F_11 ( V_13 -> V_22 ) ;
unsigned long V_41 ;
F_13 ( 0 , V_6 -> V_48 + V_49 ) ;
F_21 ( & V_4 -> V_42 , V_41 ) ;
V_6 -> V_43 &= ( ~ F_3 ( 0 ) & ~ F_3 ( 1 ) &
~ F_2 ( V_21 ) & ~ V_50 ) ;
V_6 -> V_43 |= ( V_45 | F_1 ( V_21 , V_2 ) |
F_3 ( V_21 ) | V_51 ) ;
F_13 ( V_6 -> V_43 , V_6 -> V_16 + V_46 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
V_11 -> V_47 [ V_21 ] = V_20 [ 0 ] ;
F_13 ( V_20 [ 0 ] , V_6 -> V_48 + V_52 ) ;
return V_13 -> V_26 ;
}
static int F_24 ( unsigned long V_53 )
{
static const int V_54 = 1000 ;
unsigned int V_55 ;
for ( V_55 = 0 ; V_55 < V_54 ; V_55 ++ ) {
if ( ( F_25 ( V_53 +
V_56 ) & V_57 )
== 0 )
return 0 ;
F_26 ( 1 ) ;
}
return - 1 ;
}
static int F_27 ( struct V_3 * V_4 , unsigned int V_58 ,
T_1 * V_20 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_59 = V_6 -> V_60 ;
if ( F_24 ( V_59 ) < 0 )
return - V_61 ;
F_28 ( V_62 | V_63 ,
V_59 + V_56 ) ;
F_28 ( V_58 & 0xff , V_59 + V_64 ) ;
F_28 ( V_62 | V_65 ,
V_59 + V_56 ) ;
F_28 ( ( V_58 >> 8 ) & 0xff , V_59 + V_64 ) ;
F_28 ( V_62 | V_66 , V_59 + V_56 ) ;
if ( F_24 ( V_59 ) < 0 )
return - V_61 ;
* V_20 = F_25 ( V_59 + V_64 ) ;
return 0 ;
}
static int F_29 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_20 )
{
T_1 V_67 ;
int V_68 ;
V_68 = F_27 ( V_4 , F_10 ( V_13 -> V_22 ) , & V_67 ) ;
if ( V_68 < 0 )
return V_68 ;
V_20 [ 0 ] = V_67 ;
return 1 ;
}
static void F_30 ( struct V_3 * V_4 ,
unsigned int V_69 ,
unsigned int V_70 ,
unsigned int V_71 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
static const int V_72 = 1 ;
unsigned int V_73 ;
for ( V_73 = 1 << ( V_71 - 1 ) ; V_73 ; V_73 >>= 1 ) {
if ( V_70 & V_73 )
V_69 |= V_74 ;
else
V_69 &= ~ V_74 ;
F_26 ( V_72 ) ;
F_13 ( V_69 , V_6 -> V_16 + V_28 ) ;
}
}
static int F_31 ( struct V_3 * V_4 , unsigned int V_58 ,
T_1 V_75 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
static const int V_76 = 8 ;
static const int V_71 = 11 ;
unsigned int V_70 = ( ( V_58 & 0x7 ) << 8 ) | V_75 ;
static const int V_77 = 1 ;
if ( V_58 >= V_76 ) {
F_19 ( V_4 -> V_39 , L_2 ) ;
return - 1 ;
}
if ( V_75 == V_6 -> V_78 [ V_58 ] )
return 1 ;
V_6 -> V_78 [ V_58 ] = V_75 ;
F_30 ( V_4 , F_5 ( V_4 ) , V_70 ,
V_71 ) ;
F_26 ( V_77 ) ;
F_13 ( F_5 ( V_4 ) | V_79 ,
V_6 -> V_16 + V_28 ) ;
F_26 ( V_77 ) ;
F_13 ( F_5 ( V_4 ) , V_6 -> V_16 + V_28 ) ;
return 1 ;
}
static int F_32 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_20 )
{
const unsigned int V_1 = F_10 ( V_13 -> V_22 ) ;
return F_31 ( V_4 , V_1 , V_20 [ 0 ] ) ;
}
static int F_33 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_20 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
V_20 [ 0 ] = V_6 -> V_78 [ F_10 ( V_13 -> V_22 ) ] ;
return 1 ;
}
static void F_34 ( struct V_3 * V_4 , unsigned int V_75 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_80 ;
if ( V_6 -> V_81 != V_75 ) {
V_6 -> V_81 = V_75 ;
V_80 = V_6 -> V_16 + V_28 ;
V_75 &= 0xff ;
V_75 |= F_5 ( V_4 ) ;
F_13 ( V_75 , V_80 ) ;
F_26 ( 1 ) ;
F_13 ( V_75 | V_82 , V_80 ) ;
F_26 ( 1 ) ;
F_13 ( V_75 , V_80 ) ;
F_26 ( 1 ) ;
}
}
static int F_35 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_20 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < V_13 -> V_26 ; V_55 ++ )
F_34 ( V_4 , V_20 [ V_55 ] ) ;
return V_13 -> V_26 ;
}
static int F_36 ( struct V_3 * V_4 ,
struct V_10 * V_11 , struct V_12 * V_13 ,
unsigned int * V_20 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
V_20 [ 0 ] = V_6 -> V_81 ;
return 1 ;
}
static int F_37 ( struct V_3 * V_4 , T_1 V_75 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
static const int V_71 = 7 ;
unsigned int V_70 = V_75 & 0x7f ;
unsigned int V_69 ;
static const int V_83 = 1 ;
V_69 = F_5 ( V_4 ) | V_84 ;
F_26 ( V_83 ) ;
F_13 ( V_69 , V_6 -> V_16 + V_28 ) ;
F_30 ( V_4 , V_69 , V_70 ,
V_71 ) ;
F_26 ( V_83 ) ;
F_13 ( F_5 ( V_4 ) , V_6 -> V_16 + V_28 ) ;
return 0 ;
}
static int F_38 ( struct V_3 * V_4 , unsigned int V_1 ,
T_1 V_75 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
static const int V_71 = 10 ;
unsigned int V_70 = ( ( V_1 & 0x3 ) << 8 ) | ( V_75 & 0xff ) ;
unsigned int V_69 ;
static const int V_85 = 1 ;
V_69 = F_5 ( V_4 ) | V_84 ;
F_26 ( V_85 ) ;
F_13 ( V_69 , V_6 -> V_16 + V_28 ) ;
F_30 ( V_4 , V_69 , V_70 ,
V_71 ) ;
F_26 ( V_85 ) ;
F_13 ( F_5 ( V_4 ) , V_6 -> V_16 + V_28 ) ;
return 0 ;
}
static int F_39 ( struct V_3 * V_4 ,
unsigned int V_1 , unsigned int V_75 )
{
const struct V_86 * V_87 = V_4 -> V_88 ;
struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_6 -> V_89 [ V_1 ] == V_75 )
return 1 ;
V_6 -> V_89 [ V_1 ] = V_75 ;
switch ( V_87 -> V_90 ) {
case V_91 :
F_37 ( V_4 , V_75 ) ;
break;
case V_92 :
F_38 ( V_4 , V_1 , V_75 ) ;
break;
default:
F_19 ( V_4 -> V_39 , L_3 ) ;
return - 1 ;
}
return 1 ;
}
static int F_40 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_20 )
{
unsigned int V_1 = F_10 ( V_13 -> V_22 ) ;
return F_39 ( V_4 , V_1 , V_20 [ 0 ] ) ;
}
static int F_41 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_20 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_1 = F_10 ( V_13 -> V_22 ) ;
V_20 [ 0 ] = V_6 -> V_89 [ V_1 ] ;
return 1 ;
}
static int F_42 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_93 * V_94 )
{
unsigned int V_95 = F_10 ( V_94 -> V_96 [ 0 ] ) ;
unsigned int V_97 = F_11 ( V_94 -> V_96 [ 0 ] ) ;
int V_55 ;
for ( V_55 = 1 ; V_55 < V_94 -> V_98 ; V_55 ++ ) {
unsigned int V_21 = F_10 ( V_94 -> V_96 [ V_55 ] ) ;
unsigned int V_2 = F_11 ( V_94 -> V_96 [ V_55 ] ) ;
if ( V_21 != ( V_95 + V_55 ) % V_11 -> V_99 ) {
F_43 ( V_4 -> V_39 ,
L_4 ) ;
return - V_40 ;
}
if ( V_2 != V_97 ) {
F_43 ( V_4 -> V_39 ,
L_5 ) ;
return - V_40 ;
}
}
return 0 ;
}
static int F_44 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_93 * V_94 )
{
const struct V_86 * V_87 = V_4 -> V_88 ;
struct V_5 * V_6 = V_4 -> V_7 ;
int V_100 = 0 ;
unsigned int V_101 ;
V_100 |= F_45 ( & V_94 -> V_102 , V_103 | V_104 ) ;
V_100 |= F_45 ( & V_94 -> V_105 ,
V_106 | V_107 | V_104 ) ;
V_100 |= F_45 ( & V_94 -> V_108 ,
V_107 | V_103 | V_104 ) ;
V_100 |= F_45 ( & V_94 -> V_109 , V_110 ) ;
V_100 |= F_45 ( & V_94 -> V_111 , V_110 | V_112 ) ;
if ( V_100 )
return 1 ;
V_100 |= F_46 ( V_94 -> V_102 ) ;
V_100 |= F_46 ( V_94 -> V_105 ) ;
V_100 |= F_46 ( V_94 -> V_108 ) ;
V_100 |= F_46 ( V_94 -> V_111 ) ;
if ( V_94 -> V_105 == V_106 && V_94 -> V_108 == V_103 )
V_100 |= - V_40 ;
if ( V_94 -> V_105 != V_106 && V_94 -> V_108 != V_103 )
V_100 |= - V_40 ;
if ( V_94 -> V_102 == V_104 &&
( V_94 -> V_108 == V_104 || V_94 -> V_105 == V_104 ) )
V_100 |= - V_40 ;
if ( V_100 )
return 2 ;
switch ( V_94 -> V_102 ) {
case V_103 :
V_100 |= F_47 ( & V_94 -> V_113 , 0 ) ;
break;
case V_104 :
if ( ( V_94 -> V_113
& ( V_114 & ~ ( V_115 | V_116 ) ) ) != 0 ) {
V_94 -> V_113 &= ~ ( V_114 &
~ ( V_115 | V_116 ) ) ;
V_100 |= - V_40 ;
}
if ( ! V_87 -> V_117 && ( V_94 -> V_113 & V_116 ) ) {
V_94 -> V_113 &= ( V_114 & ~ V_116 ) ;
V_100 |= - V_40 ;
}
break;
}
if ( V_94 -> V_105 == V_107 )
V_100 |= F_48 ( & V_94 -> V_118 ,
V_87 -> V_119 * V_94 -> V_98 ) ;
if ( V_94 -> V_108 == V_107 )
V_100 |= F_48 ( & V_94 -> V_120 ,
V_87 -> V_119 ) ;
V_100 |= F_47 ( & V_94 -> V_121 , V_94 -> V_98 ) ;
if ( V_94 -> V_111 == V_110 )
V_100 |= F_48 ( & V_94 -> V_122 , 1 ) ;
else
V_100 |= F_47 ( & V_94 -> V_122 , 0 ) ;
if ( V_100 )
return 3 ;
if ( V_94 -> V_105 == V_107 ) {
V_101 = V_94 -> V_118 ;
F_49 ( V_123 ,
& V_6 -> V_124 ,
& V_6 -> V_125 ,
& V_101 , V_94 -> V_41 ) ;
V_100 |= F_47 ( & V_94 -> V_118 , V_101 ) ;
}
if ( V_94 -> V_108 == V_107 ) {
V_101 = V_94 -> V_120 ;
F_49 ( V_123 ,
& V_6 -> V_124 ,
& V_6 -> V_125 ,
& V_101 , V_94 -> V_41 ) ;
V_100 |= F_47 ( & V_94 -> V_120 , V_101 ) ;
}
if ( V_100 )
return 4 ;
if ( V_94 -> V_96 && V_94 -> V_98 > 0 )
V_100 |= F_42 ( V_4 , V_11 , V_94 ) ;
if ( V_100 )
return 5 ;
return 0 ;
}
static void F_50 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_126 = V_4 -> V_59 + V_127 ;
F_51 ( V_126 , 0 , 1 , V_128 | V_129 ) ;
F_51 ( V_126 , 0 , 2 , V_128 | V_129 ) ;
F_52 ( V_126 , 0 , 1 , V_6 -> V_124 ) ;
F_52 ( V_126 , 0 , 2 , V_6 -> V_125 ) ;
}
static int F_53 ( struct V_3 * V_4 ,
struct V_10 * V_11 )
{
const struct V_86 * V_87 = V_4 -> V_88 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_130 * V_131 = V_11 -> V_131 ;
struct V_93 * V_94 = & V_131 -> V_94 ;
unsigned int V_24 ;
unsigned long V_41 ;
F_13 ( 0 , V_6 -> V_16 + V_28 ) ;
F_13 ( 0 , V_6 -> V_16 + V_132 ) ;
F_13 ( 0 , V_6 -> V_33 + V_34 ) ;
V_24 = F_14 ( F_10 ( V_94 -> V_96 [ 0 ] ) ) |
F_15 ( F_10 ( V_94 -> V_96 [ V_94 -> V_98 - 1 ] ) ) |
F_16 ( F_11 ( V_94 -> V_96 [ 0 ] ) ) ;
if ( F_11 ( V_94 -> V_96 [ 0 ] ) & V_29 )
V_24 |= V_30 ;
if ( F_12 ( V_94 -> V_96 [ 0 ] ) != V_31 )
V_24 |= V_32 ;
if ( V_94 -> V_108 == V_104 || V_94 -> V_105 == V_104 )
V_24 |= V_133 ;
else
V_24 |= V_134 ;
F_13 ( V_24 , V_6 -> V_16 + V_17 ) ;
if ( V_94 -> V_105 == V_107 || V_94 -> V_108 == V_107 )
F_50 ( V_4 ) ;
if ( V_94 -> V_111 == V_110 )
V_6 -> V_135 = V_94 -> V_98 * V_94 -> V_122 ;
F_21 ( & V_4 -> V_42 , V_41 ) ;
V_6 -> V_136 |= V_137 ;
V_6 -> V_136 &= ~ V_138 ;
if ( V_94 -> V_41 & V_139 ) {
if ( V_94 -> V_108 == V_103 && V_94 -> V_98 > 1 ) {
V_6 -> V_136 |= V_140 ;
} else {
V_6 -> V_136 |= V_141 ;
}
} else {
V_6 -> V_136 |= V_142 ;
}
F_13 ( V_6 -> V_136 | V_143 | INT | V_144 ,
V_6 -> V_16 + V_145 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
V_24 = 0 ;
if ( V_94 -> V_102 == V_103 ) {
V_24 |= V_146 ;
} else {
V_24 |= V_147 | V_148 | V_149 ;
if ( V_87 -> V_117 ) {
if ( V_94 -> V_113 & V_116 )
V_24 |= V_150 ;
if ( V_94 -> V_113 & V_115 )
V_24 |= V_151 ;
}
}
if ( V_94 -> V_108 == V_103 && V_94 -> V_98 > 1 )
V_24 |= V_152 ;
F_13 ( V_24 , V_6 -> V_16 + V_132 ) ;
return 0 ;
}
static int F_54 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_93 * V_94 )
{
unsigned int V_95 = F_10 ( V_94 -> V_96 [ 0 ] ) ;
if ( V_94 -> V_98 > 1 ) {
unsigned int V_153 = F_10 ( V_94 -> V_96 [ 1 ] ) ;
if ( V_95 != 0 || V_153 != 1 ) {
F_43 ( V_4 -> V_39 ,
L_6 ) ;
return - V_40 ;
}
}
return 0 ;
}
static int F_55 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_93 * V_94 )
{
const struct V_86 * V_87 = V_4 -> V_88 ;
struct V_5 * V_6 = V_4 -> V_7 ;
int V_100 = 0 ;
unsigned int V_101 ;
V_100 |= F_45 ( & V_94 -> V_102 , V_154 ) ;
V_100 |= F_45 ( & V_94 -> V_105 ,
V_107 | V_104 ) ;
V_100 |= F_45 ( & V_94 -> V_108 , V_103 ) ;
V_100 |= F_45 ( & V_94 -> V_109 , V_110 ) ;
V_100 |= F_45 ( & V_94 -> V_111 , V_110 | V_112 ) ;
if ( V_100 )
return 1 ;
V_100 |= F_46 ( V_94 -> V_105 ) ;
V_100 |= F_46 ( V_94 -> V_111 ) ;
if ( V_100 )
return 2 ;
V_100 |= F_47 ( & V_94 -> V_113 , 0 ) ;
if ( V_94 -> V_105 == V_107 )
V_100 |= F_48 ( & V_94 -> V_118 ,
V_87 -> V_155 ) ;
V_100 |= F_47 ( & V_94 -> V_121 , V_94 -> V_98 ) ;
if ( V_94 -> V_111 == V_110 )
V_100 |= F_48 ( & V_94 -> V_122 , 1 ) ;
else
V_100 |= F_47 ( & V_94 -> V_122 , 0 ) ;
if ( V_100 )
return 3 ;
if ( V_94 -> V_105 == V_107 ) {
V_101 = V_94 -> V_118 ;
F_49 ( V_123 ,
& V_6 -> V_156 ,
& V_6 -> V_157 ,
& V_101 , V_94 -> V_41 ) ;
V_100 |= F_47 ( & V_94 -> V_118 , V_101 ) ;
}
if ( V_100 )
return 4 ;
if ( V_94 -> V_96 && V_94 -> V_98 > 0 )
V_100 |= F_54 ( V_4 , V_11 , V_94 ) ;
if ( V_100 )
return 5 ;
return 0 ;
}
static int F_56 ( struct V_3 * V_4 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_41 ;
F_21 ( & V_4 -> V_42 , V_41 ) ;
V_6 -> V_136 &= ~ V_137 & ~ V_158 ;
F_13 ( V_6 -> V_136 , V_6 -> V_16 + V_145 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
F_13 ( 0 , V_6 -> V_16 + V_132 ) ;
F_13 ( 0 , V_6 -> V_16 + V_17 ) ;
return 0 ;
}
static int F_57 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
unsigned int V_159 )
{
const struct V_86 * V_87 = V_4 -> V_88 ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_160 , V_161 = V_87 -> V_162 ;
struct V_130 * V_131 = V_11 -> V_131 ;
struct V_93 * V_94 = & V_11 -> V_131 -> V_94 ;
unsigned long V_41 ;
if ( V_159 != V_94 -> V_113 )
return - V_40 ;
if ( V_94 -> V_111 == V_110 && V_6 -> V_163 < V_161 )
V_161 = V_6 -> V_163 ;
V_160 = F_58 ( V_11 , V_6 -> V_164 ,
V_161 * sizeof( short ) ) ;
V_161 = V_160 / sizeof( short ) ;
if ( V_94 -> V_111 == V_110 )
V_6 -> V_163 -= V_161 ;
F_59 ( V_6 -> V_48 + V_52 , V_6 -> V_164 , V_160 ) ;
F_21 ( & V_4 -> V_42 , V_41 ) ;
V_6 -> V_136 |= V_165 | V_166 ;
F_13 ( V_6 -> V_136 | V_167 | V_168 ,
V_6 -> V_16 + V_145 ) ;
V_6 -> V_43 |= V_51 | V_45 | V_169 ;
F_13 ( V_6 -> V_43 , V_6 -> V_16 + V_46 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
V_131 -> V_170 = NULL ;
return 0 ;
}
static void F_60 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_126 = V_4 -> V_59 + V_171 ;
F_51 ( V_126 , 0 , 1 , V_128 | V_129 ) ;
F_51 ( V_126 , 0 , 2 , V_128 | V_129 ) ;
F_52 ( V_126 , 0 , 1 , V_6 -> V_156 ) ;
F_52 ( V_126 , 0 , 2 , V_6 -> V_157 ) ;
}
static int F_61 ( struct V_3 * V_4 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_130 * V_131 = V_11 -> V_131 ;
struct V_93 * V_94 = & V_131 -> V_94 ;
unsigned int V_55 ;
unsigned long V_41 ;
F_21 ( & V_4 -> V_42 , V_41 ) ;
for ( V_55 = 0 ; V_55 < V_94 -> V_98 ; V_55 ++ ) {
V_6 -> V_43 |=
F_3 ( F_10 ( V_94 -> V_96 [ V_55 ] ) ) ;
V_6 -> V_43 |= F_1 ( F_10 ( V_94 -> V_96 [ V_55 ] ) ,
F_11 ( V_94 ->
V_96 [ V_55 ] ) ) ;
}
F_13 ( V_6 -> V_43 , V_6 -> V_16 + V_46 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
F_13 ( 0 , V_6 -> V_48 + V_49 ) ;
if ( V_94 -> V_105 == V_107 )
F_60 ( V_4 ) ;
if ( V_94 -> V_111 == V_110 )
V_6 -> V_163 = V_94 -> V_98 * V_94 -> V_122 ;
F_21 ( & V_4 -> V_42 , V_41 ) ;
switch ( V_94 -> V_105 ) {
case V_107 :
V_6 -> V_43 |= V_172 ;
break;
case V_104 :
V_6 -> V_43 |= V_173 ;
break;
default:
F_22 ( & V_4 -> V_42 , V_41 ) ;
F_19 ( V_4 -> V_39 , L_7 ) ;
return - 1 ;
}
F_22 ( & V_4 -> V_42 , V_41 ) ;
V_131 -> V_170 = F_57 ;
return 0 ;
}
static int F_62 ( struct V_3 * V_4 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_41 ;
F_21 ( & V_4 -> V_42 , V_41 ) ;
V_6 -> V_136 &= ~ V_166 & ~ V_165 ;
F_13 ( V_6 -> V_136 , V_6 -> V_16 + V_145 ) ;
V_6 -> V_43 &= ~ V_45 & ~ V_50 ;
F_13 ( V_6 -> V_43 , V_6 -> V_16 + V_46 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
return 0 ;
}
static void F_63 ( struct V_3 * V_4 , unsigned int V_15 )
{
const struct V_86 * V_87 = V_4 -> V_88 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_10 * V_11 = V_4 -> V_174 ;
struct V_130 * V_131 = V_11 -> V_131 ;
struct V_93 * V_94 = & V_131 -> V_94 ;
unsigned int V_175 = V_87 -> V_162 / 2 ;
unsigned int V_161 ;
unsigned long V_41 ;
if ( V_15 & V_167 ) {
F_21 ( & V_4 -> V_42 , V_41 ) ;
F_13 ( V_6 -> V_136 | V_167 ,
V_6 -> V_16 + V_145 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
if ( F_8 ( V_6 -> V_48 + V_46 ) & V_169 ) {
if ( V_94 -> V_111 == V_112 ||
( V_94 -> V_111 == V_110
&& V_6 -> V_163 ) ) {
F_19 ( V_4 -> V_39 , L_8 ) ;
V_131 -> V_176 |= V_177 ;
}
V_131 -> V_176 |= V_178 ;
}
} else if ( V_15 & V_168 ) {
unsigned int V_160 ;
V_161 = V_175 ;
if ( V_94 -> V_111 == V_110 &&
V_6 -> V_163 < V_161 )
V_161 = V_6 -> V_163 ;
V_160 =
F_58 ( V_11 , V_6 -> V_164 ,
V_161 * sizeof( short ) ) ;
V_161 = V_160 / sizeof( short ) ;
if ( V_94 -> V_111 == V_110 )
V_6 -> V_163 -= V_161 ;
F_59 ( V_6 -> V_48 + V_52 , V_6 -> V_164 ,
V_161 ) ;
F_21 ( & V_4 -> V_42 , V_41 ) ;
F_13 ( V_6 -> V_136 | V_168 ,
V_6 -> V_16 + V_145 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
}
F_64 ( V_4 , V_11 ) ;
}
static T_2 F_65 ( int V_179 , void * V_180 )
{
struct V_3 * V_4 = (struct V_3 * ) V_180 ;
const struct V_86 * V_87 = V_4 -> V_88 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_10 * V_11 = V_4 -> V_181 ;
struct V_130 * V_131 ;
struct V_93 * V_94 ;
int V_15 , V_182 ;
int V_175 = V_87 -> V_162 / 2 ;
unsigned int V_183 , V_55 ;
static const int V_54 = 10000 ;
unsigned long V_41 ;
if ( ! V_4 -> V_184 )
return V_185 ;
V_131 = V_11 -> V_131 ;
V_94 = & V_131 -> V_94 ;
V_182 = F_66 ( V_6 -> V_60 + V_186 ) ;
if ( ( V_187 & V_182 ) == 0 )
return V_185 ;
F_67 ( V_6 -> V_60 + V_188 ) ;
F_68 ( V_6 -> V_189 | V_190 ,
V_6 -> V_60 + V_186 ) ;
V_15 = F_8 ( V_6 -> V_16 + V_145 ) ;
if ( V_15 & ( V_168 | V_167 ) )
F_63 ( V_4 , V_15 ) ;
if ( V_15 & V_191 ) {
V_183 = V_175 ;
if ( V_94 -> V_111 == V_110 &&
V_183 > V_6 -> V_135 ) {
V_183 = V_6 -> V_135 ;
}
F_69 ( V_6 -> V_33 + V_35 , V_6 -> V_192 ,
V_183 ) ;
F_70 ( V_11 , V_6 -> V_192 ,
V_183 * sizeof( short ) ) ;
V_6 -> V_135 -= V_183 ;
if ( V_94 -> V_111 == V_110 && V_6 -> V_135 == 0 )
V_131 -> V_176 |= V_178 ;
F_21 ( & V_4 -> V_42 , V_41 ) ;
F_13 ( V_6 -> V_136 | INT ,
V_6 -> V_16 + V_145 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
} else if ( V_15 & ( V_193 | V_194 ) ) {
for ( V_55 = 0 ; V_55 < V_54 ; V_55 ++ ) {
if ( ( V_195 & F_8 ( V_6 -> V_16 +
V_145 ) ) == 0 )
break;
F_71 ( V_11 , F_8 ( V_6 -> V_33 ) ) ;
if ( V_94 -> V_111 == V_110 &&
-- V_6 -> V_135 == 0 ) {
V_131 -> V_176 |= V_178 ;
break;
}
}
F_21 ( & V_4 -> V_42 , V_41 ) ;
F_13 ( V_6 -> V_136 | INT ,
V_6 -> V_16 + V_145 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
} else if ( V_15 & V_143 ) {
F_19 ( V_4 -> V_39 ,
L_9 ) ;
F_21 ( & V_4 -> V_42 , V_41 ) ;
F_13 ( V_6 -> V_136 | V_143 ,
V_6 -> V_16 + V_145 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
}
if ( V_15 & V_144 ) {
F_19 ( V_4 -> V_39 , L_10 ) ;
F_21 ( & V_4 -> V_42 , V_41 ) ;
F_13 ( V_6 -> V_136 | V_144 ,
V_6 -> V_16 + V_145 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
V_131 -> V_176 |= V_178 | V_177 ;
}
F_64 ( V_4 , V_11 ) ;
return V_196 ;
}
static int F_72 ( struct V_3 * V_4 ,
unsigned long V_14 )
{
struct V_197 * V_198 = F_73 ( V_4 ) ;
const struct V_86 * V_87 = NULL ;
struct V_5 * V_6 ;
struct V_10 * V_11 ;
int V_55 ;
int V_25 ;
if ( V_14 < F_74 ( V_199 ) )
V_87 = & V_199 [ V_14 ] ;
if ( ! V_87 )
return - V_200 ;
V_4 -> V_88 = V_87 ;
V_4 -> V_201 = V_87 -> V_202 ;
V_6 = F_75 ( V_4 , sizeof( * V_6 ) ) ;
if ( ! V_6 )
return - V_203 ;
V_25 = F_76 ( V_4 ) ;
if ( V_25 )
return V_25 ;
V_6 -> V_60 = F_77 ( V_198 , 0 ) ;
V_6 -> V_16 = F_77 ( V_198 , 1 ) ;
V_6 -> V_33 = F_77 ( V_198 , 2 ) ;
V_4 -> V_59 = F_77 ( V_198 , 3 ) ;
if ( V_87 -> V_204 )
V_6 -> V_48 = F_77 ( V_198 , 4 ) ;
F_68 ( V_190 ,
V_6 -> V_60 + V_186 ) ;
V_25 = F_78 ( V_198 -> V_179 , F_65 , V_205 ,
V_4 -> V_201 , V_4 ) ;
if ( V_25 ) {
F_43 ( V_4 -> V_39 , L_11 ,
V_198 -> V_179 ) ;
return V_25 ;
}
V_4 -> V_179 = V_198 -> V_179 ;
V_25 = F_79 ( V_4 , 7 ) ;
if ( V_25 )
return V_25 ;
V_11 = & V_4 -> V_206 [ 0 ] ;
V_4 -> V_181 = V_11 ;
V_11 -> type = V_207 ;
V_11 -> V_208 = V_209 | V_210 | V_211 | V_212 ;
V_11 -> V_99 = V_87 -> V_213 ;
V_11 -> V_214 = V_87 -> V_213 ;
V_11 -> V_215 = ( 1 << V_87 -> V_216 ) - 1 ;
V_11 -> V_217 = V_87 -> V_218 ;
V_11 -> V_219 = F_9 ;
V_11 -> V_220 = F_18 ;
V_11 -> V_221 = F_53 ;
V_11 -> V_222 = F_44 ;
V_11 -> V_223 = F_56 ;
V_11 = & V_4 -> V_206 [ 1 ] ;
if ( V_87 -> V_204 ) {
V_11 -> type = V_224 ;
V_11 -> V_208 = V_209 | V_225 | V_210 ;
V_11 -> V_99 = V_87 -> V_204 ;
V_11 -> V_215 = ( 1 << V_87 -> V_216 ) - 1 ;
V_11 -> V_217 = & V_226 ;
V_11 -> V_227 = F_20 ;
V_11 -> V_219 = V_228 ;
V_25 = F_80 ( V_11 ) ;
if ( V_25 )
return V_25 ;
if ( V_87 -> V_229 ) {
V_4 -> V_174 = V_11 ;
V_11 -> V_208 |= V_230 ;
V_11 -> V_227 = F_23 ;
V_11 -> V_222 = F_55 ;
V_11 -> V_221 = F_61 ;
V_11 -> V_223 = F_62 ;
}
} else {
V_11 -> type = V_231 ;
}
V_11 = & V_4 -> V_206 [ 2 ] ;
V_25 = F_81 ( V_4 , V_11 , NULL , V_232 ) ;
if ( V_25 )
return V_25 ;
V_11 = & V_4 -> V_206 [ 3 ] ;
V_11 -> type = V_233 ;
V_11 -> V_208 = V_209 | V_234 ;
V_11 -> V_99 = 256 ;
V_11 -> V_215 = 0xff ;
V_11 -> V_219 = F_29 ;
V_11 = & V_4 -> V_206 [ 4 ] ;
V_11 -> type = V_235 ;
V_11 -> V_208 = V_209 | V_225 | V_234 ;
V_11 -> V_99 = V_236 ;
V_11 -> V_215 = 0xff ;
V_11 -> V_219 = F_33 ;
V_11 -> V_227 = F_32 ;
for ( V_55 = 0 ; V_55 < V_11 -> V_99 ; V_55 ++ )
F_31 ( V_4 , V_55 , V_11 -> V_215 / 2 ) ;
V_11 = & V_4 -> V_206 [ 5 ] ;
V_11 -> type = V_235 ;
V_11 -> V_208 = V_209 | V_225 | V_234 ;
if ( V_87 -> V_90 == V_91 ) {
V_11 -> V_99 = V_237 ;
V_11 -> V_215 = 0x7f ;
} else {
V_11 -> V_99 = V_238 ;
V_11 -> V_215 = 0xff ;
}
V_11 -> V_219 = F_41 ;
V_11 -> V_227 = F_40 ;
for ( V_55 = 0 ; V_55 < V_11 -> V_99 ; V_55 ++ )
F_39 ( V_4 , V_55 , V_11 -> V_215 / 2 ) ;
V_11 = & V_4 -> V_206 [ 6 ] ;
if ( V_87 -> V_239 ) {
V_11 -> type = V_235 ;
V_11 -> V_208 = V_209 | V_225 | V_234 ;
V_11 -> V_99 = V_240 ;
V_11 -> V_219 = F_36 ;
V_11 -> V_227 = F_35 ;
V_11 -> V_215 = 0xff ;
F_34 ( V_4 , V_11 -> V_215 / 2 ) ;
} else
V_11 -> type = V_231 ;
F_66 ( V_6 -> V_60 + V_188 ) ;
V_6 -> V_189 =
F_82 ( 3 ) | F_83 ( 3 ) |
V_241 ;
F_68 ( V_6 -> V_189 | V_190 ,
V_6 -> V_60 + V_186 ) ;
return 0 ;
}
static void F_84 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_6 && V_6 -> V_60 ) {
F_68 ( V_190 ,
V_6 -> V_60 + V_186 ) ;
}
F_85 ( V_4 ) ;
}
static int F_86 ( struct V_197 * V_4 ,
const struct V_242 * V_36 )
{
return F_87 ( V_4 , & V_243 ,
V_36 -> V_244 ) ;
}
