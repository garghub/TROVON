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
break;
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
V_6 -> V_47 [ V_21 ] = V_20 [ 0 ] ;
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
V_6 -> V_47 [ V_21 ] = V_20 [ 0 ] ;
F_13 ( V_20 [ 0 ] , V_6 -> V_48 + V_52 ) ;
return V_13 -> V_26 ;
}
static int F_24 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_12 * V_13 ,
unsigned int * V_20 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
V_20 [ 0 ] = V_6 -> V_47 [ F_10 ( V_13 -> V_22 ) ] ;
return 1 ;
}
static int F_25 ( unsigned long V_53 )
{
static const int V_54 = 1000 ;
unsigned int V_55 ;
for ( V_55 = 0 ; V_55 < V_54 ; V_55 ++ ) {
if ( ( F_26 ( V_53 +
V_56 ) & V_57 )
== 0 )
return 0 ;
F_27 ( 1 ) ;
}
return - 1 ;
}
static int F_28 ( struct V_3 * V_4 , unsigned int V_58 ,
T_1 * V_20 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_59 = V_6 -> V_60 ;
if ( F_25 ( V_59 ) < 0 )
return - V_61 ;
F_29 ( V_62 | V_63 ,
V_59 + V_56 ) ;
F_29 ( V_58 & 0xff , V_59 + V_64 ) ;
F_29 ( V_62 | V_65 ,
V_59 + V_56 ) ;
F_29 ( ( V_58 >> 8 ) & 0xff , V_59 + V_64 ) ;
F_29 ( V_62 | V_66 , V_59 + V_56 ) ;
if ( F_25 ( V_59 ) < 0 )
return - V_61 ;
* V_20 = F_26 ( V_59 + V_64 ) ;
return 0 ;
}
static int F_30 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_20 )
{
T_1 V_67 ;
int V_68 ;
V_68 = F_28 ( V_4 , F_10 ( V_13 -> V_22 ) , & V_67 ) ;
if ( V_68 < 0 )
return V_68 ;
V_20 [ 0 ] = V_67 ;
return 1 ;
}
static void F_31 ( struct V_3 * V_4 ,
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
F_27 ( V_72 ) ;
F_13 ( V_69 , V_6 -> V_16 + V_28 ) ;
}
}
static int F_32 ( struct V_3 * V_4 , unsigned int V_58 ,
T_1 V_75 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
static const int V_76 = 8 ;
static const int V_71 = 11 ;
unsigned int V_70 = ( ( V_58 & 0x7 ) << 8 ) | V_75 ;
static const int V_77 = 1 ;
if ( V_58 >= V_76 ) {
F_33 ( V_4 , L_2 ) ;
return - 1 ;
}
if ( V_75 == V_6 -> V_78 [ V_58 ] )
return 1 ;
V_6 -> V_78 [ V_58 ] = V_75 ;
F_31 ( V_4 , F_5 ( V_4 ) , V_70 ,
V_71 ) ;
F_27 ( V_77 ) ;
F_13 ( F_5 ( V_4 ) | V_79 ,
V_6 -> V_16 + V_28 ) ;
F_27 ( V_77 ) ;
F_13 ( F_5 ( V_4 ) , V_6 -> V_16 + V_28 ) ;
return 1 ;
}
static int F_34 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_20 )
{
const unsigned int V_1 = F_10 ( V_13 -> V_22 ) ;
return F_32 ( V_4 , V_1 , V_20 [ 0 ] ) ;
}
static int F_35 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_20 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
V_20 [ 0 ] = V_6 -> V_78 [ F_10 ( V_13 -> V_22 ) ] ;
return 1 ;
}
static void F_36 ( struct V_3 * V_4 , unsigned int V_75 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_80 ;
if ( V_6 -> V_81 != V_75 ) {
V_6 -> V_81 = V_75 ;
V_80 = V_6 -> V_16 + V_28 ;
V_75 &= 0xff ;
V_75 |= F_5 ( V_4 ) ;
F_13 ( V_75 , V_80 ) ;
F_27 ( 1 ) ;
F_13 ( V_75 | V_82 , V_80 ) ;
F_27 ( 1 ) ;
F_13 ( V_75 , V_80 ) ;
F_27 ( 1 ) ;
}
}
static int F_37 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_20 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < V_13 -> V_26 ; V_55 ++ )
F_36 ( V_4 , V_20 [ V_55 ] ) ;
return V_13 -> V_26 ;
}
static int F_38 ( struct V_3 * V_4 ,
struct V_10 * V_11 , struct V_12 * V_13 ,
unsigned int * V_20 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
V_20 [ 0 ] = V_6 -> V_81 ;
return 1 ;
}
static int F_39 ( struct V_3 * V_4 , T_1 V_75 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
static const int V_71 = 7 ;
unsigned int V_70 = V_75 & 0x7f ;
unsigned int V_69 ;
static const int V_83 = 1 ;
V_69 = F_5 ( V_4 ) | V_84 ;
F_27 ( V_83 ) ;
F_13 ( V_69 , V_6 -> V_16 + V_28 ) ;
F_31 ( V_4 , V_69 , V_70 ,
V_71 ) ;
F_27 ( V_83 ) ;
F_13 ( F_5 ( V_4 ) , V_6 -> V_16 + V_28 ) ;
return 0 ;
}
static int F_40 ( struct V_3 * V_4 , unsigned int V_1 ,
T_1 V_75 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
static const int V_71 = 10 ;
unsigned int V_70 = ( ( V_1 & 0x3 ) << 8 ) | ( V_75 & 0xff ) ;
unsigned int V_69 ;
static const int V_85 = 1 ;
V_69 = F_5 ( V_4 ) | V_84 ;
F_27 ( V_85 ) ;
F_13 ( V_69 , V_6 -> V_16 + V_28 ) ;
F_31 ( V_4 , V_69 , V_70 ,
V_71 ) ;
F_27 ( V_85 ) ;
F_13 ( F_5 ( V_4 ) , V_6 -> V_16 + V_28 ) ;
return 0 ;
}
static int F_41 ( struct V_3 * V_4 ,
unsigned int V_1 , unsigned int V_75 )
{
const struct V_86 * V_87 = F_42 ( V_4 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_6 -> V_88 [ V_1 ] == V_75 )
return 1 ;
V_6 -> V_88 [ V_1 ] = V_75 ;
switch ( V_87 -> V_89 ) {
case V_90 :
F_39 ( V_4 , V_75 ) ;
break;
case V_91 :
F_40 ( V_4 , V_1 , V_75 ) ;
break;
default:
F_33 ( V_4 , L_3 ) ;
return - 1 ;
break;
}
return 1 ;
}
static int F_43 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_20 )
{
unsigned int V_1 = F_10 ( V_13 -> V_22 ) ;
return F_41 ( V_4 , V_1 , V_20 [ 0 ] ) ;
}
static int F_44 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_20 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_1 = F_10 ( V_13 -> V_22 ) ;
V_20 [ 0 ] = V_6 -> V_88 [ V_1 ] ;
return 1 ;
}
static int F_45 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_92 * V_93 )
{
const struct V_86 * V_87 = F_42 ( V_4 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
int V_94 = 0 ;
int V_95 ;
int V_55 , V_96 , V_97 ;
V_94 |= F_46 ( & V_93 -> V_98 , V_99 | V_100 ) ;
V_94 |= F_46 ( & V_93 -> V_101 ,
V_102 | V_103 | V_100 ) ;
V_94 |= F_46 ( & V_93 -> V_104 ,
V_103 | V_99 | V_100 ) ;
V_94 |= F_46 ( & V_93 -> V_105 , V_106 ) ;
V_94 |= F_46 ( & V_93 -> V_107 , V_106 | V_108 ) ;
if ( V_94 )
return 1 ;
V_94 |= F_47 ( V_93 -> V_98 ) ;
V_94 |= F_47 ( V_93 -> V_101 ) ;
V_94 |= F_47 ( V_93 -> V_104 ) ;
V_94 |= F_47 ( V_93 -> V_107 ) ;
if ( V_93 -> V_101 == V_102 && V_93 -> V_104 == V_99 )
V_94 |= - V_40 ;
if ( V_93 -> V_101 != V_102 && V_93 -> V_104 != V_99 )
V_94 |= - V_40 ;
if ( V_93 -> V_98 == V_100 &&
( V_93 -> V_104 == V_100 || V_93 -> V_101 == V_100 ) )
V_94 |= - V_40 ;
if ( V_94 )
return 2 ;
switch ( V_93 -> V_98 ) {
case V_100 :
if ( ( V_93 -> V_109
& ( V_110 & ~ ( V_111 | V_112 ) ) ) != 0 ) {
V_93 -> V_109 &= ~ ( V_110 &
~ ( V_111 | V_112 ) ) ;
V_94 |= - V_40 ;
}
if ( ! V_87 -> V_113 && ( V_93 -> V_109 & V_112 ) ) {
V_93 -> V_109 &= ( V_110 & ~ V_112 ) ;
V_94 |= - V_40 ;
}
break;
default:
V_94 |= F_48 ( & V_93 -> V_109 , 0 ) ;
break;
}
if ( V_93 -> V_101 == V_103 )
V_94 |= F_49 ( & V_93 -> V_114 ,
V_87 -> V_115 * V_93 -> V_116 ) ;
if ( V_93 -> V_104 == V_103 )
V_94 |= F_49 ( & V_93 -> V_117 ,
V_87 -> V_115 ) ;
V_94 |= F_48 ( & V_93 -> V_118 , V_93 -> V_116 ) ;
if ( V_93 -> V_107 == V_108 )
V_94 |= F_48 ( & V_93 -> V_119 , 0 ) ;
if ( V_94 )
return 3 ;
if ( V_93 -> V_101 == V_103 ) {
V_95 = V_93 -> V_114 ;
F_50 ( V_120 ,
& V_6 -> V_121 ,
& V_6 -> V_122 ,
& V_93 -> V_114 , V_93 -> V_41 ) ;
if ( V_95 != V_93 -> V_114 )
V_94 ++ ;
}
if ( V_93 -> V_104 == V_103 ) {
V_95 = V_93 -> V_117 ;
F_50 ( V_120 ,
& V_6 -> V_121 ,
& V_6 -> V_122 ,
& V_93 -> V_117 , V_93 -> V_41 ) ;
if ( V_95 != V_93 -> V_117 )
V_94 ++ ;
}
if ( V_94 )
return 4 ;
if ( V_93 -> V_123 ) {
V_96 = F_11 ( V_93 -> V_123 [ 0 ] ) ;
V_97 = F_10 ( V_93 -> V_123 [ 0 ] ) ;
for ( V_55 = 1 ; V_55 < V_93 -> V_116 ; V_55 ++ ) {
if ( F_10 ( V_93 -> V_123 [ V_55 ] ) !=
( V_97 + V_55 ) % V_11 -> V_124 ) {
F_33 ( V_4 ,
L_4 ) ;
V_94 ++ ;
}
if ( F_11 ( V_93 -> V_123 [ V_55 ] ) != V_96 ) {
F_33 ( V_4 ,
L_5 ) ;
V_94 ++ ;
}
}
}
if ( V_94 )
return 5 ;
return 0 ;
}
static void F_51 ( struct V_3 * V_4 , unsigned int * V_125 ,
int V_126 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
F_50 ( V_120 ,
& V_6 -> V_121 , & V_6 -> V_122 ,
V_125 , V_126 ) ;
F_52 ( V_6 -> V_127 + V_128 , 0 , 1 ,
V_6 -> V_121 , 2 ) ;
F_52 ( V_6 -> V_127 + V_128 , 0 , 2 ,
V_6 -> V_122 , 2 ) ;
}
static int F_53 ( struct V_3 * V_4 ,
struct V_10 * V_11 )
{
const struct V_86 * V_87 = F_42 ( V_4 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_129 * V_130 = V_11 -> V_130 ;
struct V_92 * V_93 = & V_130 -> V_93 ;
unsigned int V_24 ;
unsigned long V_41 ;
F_13 ( 0 , V_6 -> V_16 + V_28 ) ;
F_13 ( 0 , V_6 -> V_16 + V_131 ) ;
F_13 ( 0 , V_6 -> V_33 + V_34 ) ;
V_24 = F_14 ( F_10 ( V_93 -> V_123 [ 0 ] ) ) |
F_15 ( F_10 ( V_93 -> V_123 [ V_93 -> V_116 - 1 ] ) ) |
F_16 ( F_11 ( V_93 -> V_123 [ 0 ] ) ) ;
if ( F_11 ( V_93 -> V_123 [ 0 ] ) & V_29 )
V_24 |= V_30 ;
if ( F_12 ( V_93 -> V_123 [ 0 ] ) != V_31 )
V_24 |= V_32 ;
if ( V_93 -> V_104 == V_100 || V_93 -> V_101 == V_100 )
V_24 |= V_132 ;
else
V_24 |= V_133 ;
F_13 ( V_24 , V_6 -> V_16 + V_17 ) ;
if ( V_93 -> V_104 == V_103 )
F_51 ( V_4 , & V_93 -> V_117 ,
V_93 -> V_41 & V_134 ) ;
else if ( V_93 -> V_101 == V_103 )
F_51 ( V_4 , & V_93 -> V_114 ,
V_93 -> V_41 & V_134 ) ;
if ( V_93 -> V_107 == V_106 )
V_6 -> V_135 = V_93 -> V_116 * V_93 -> V_119 ;
F_21 ( & V_4 -> V_42 , V_41 ) ;
V_6 -> V_136 |= V_137 ;
V_6 -> V_136 &= ~ V_138 ;
if ( V_93 -> V_41 & V_139 ) {
if ( V_93 -> V_104 == V_99 && V_93 -> V_116 > 1 ) {
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
if ( V_93 -> V_98 == V_99 ) {
V_24 |= V_146 ;
} else {
V_24 |= V_147 | V_148 | V_149 ;
if ( V_87 -> V_113 ) {
if ( V_93 -> V_109 & V_112 )
V_24 |= V_150 ;
if ( V_93 -> V_109 & V_111 )
V_24 |= V_151 ;
}
}
if ( V_93 -> V_104 == V_99 && V_93 -> V_116 > 1 )
V_24 |= V_152 ;
F_13 ( V_24 , V_6 -> V_16 + V_131 ) ;
return 0 ;
}
static int F_54 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_92 * V_93 )
{
const struct V_86 * V_87 = F_42 ( V_4 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
int V_94 = 0 ;
int V_95 ;
V_94 |= F_46 ( & V_93 -> V_98 , V_153 ) ;
V_94 |= F_46 ( & V_93 -> V_101 ,
V_103 | V_100 ) ;
V_94 |= F_46 ( & V_93 -> V_104 , V_99 ) ;
V_94 |= F_46 ( & V_93 -> V_105 , V_106 ) ;
V_94 |= F_46 ( & V_93 -> V_107 , V_106 | V_108 ) ;
if ( V_94 )
return 1 ;
V_94 |= F_47 ( V_93 -> V_101 ) ;
V_94 |= F_47 ( V_93 -> V_107 ) ;
if ( V_94 )
return 2 ;
V_94 |= F_48 ( & V_93 -> V_109 , 0 ) ;
if ( V_93 -> V_101 == V_103 )
V_94 |= F_49 ( & V_93 -> V_114 ,
V_87 -> V_154 ) ;
V_94 |= F_48 ( & V_93 -> V_118 , V_93 -> V_116 ) ;
if ( V_93 -> V_107 == V_108 )
V_94 |= F_48 ( & V_93 -> V_119 , 0 ) ;
if ( V_94 )
return 3 ;
if ( V_93 -> V_101 == V_103 ) {
V_95 = V_93 -> V_114 ;
F_50 ( V_120 ,
& V_6 -> V_155 ,
& V_6 -> V_156 ,
& V_93 -> V_114 , V_93 -> V_41 ) ;
if ( V_95 != V_93 -> V_114 )
V_94 ++ ;
}
if ( V_94 )
return 4 ;
if ( V_93 -> V_123 && V_93 -> V_116 > 1 ) {
if ( F_10 ( V_93 -> V_123 [ 0 ] ) != 0 ||
F_10 ( V_93 -> V_123 [ 1 ] ) != 1 ) {
F_33 ( V_4 ,
L_6 ) ;
V_94 ++ ;
}
}
if ( V_94 )
return 5 ;
return 0 ;
}
static int F_55 ( struct V_3 * V_4 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_41 ;
F_21 ( & V_4 -> V_42 , V_41 ) ;
V_6 -> V_136 &= ~ V_137 & ~ V_157 ;
F_13 ( V_6 -> V_136 , V_6 -> V_16 + V_145 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
F_13 ( 0 , V_6 -> V_16 + V_131 ) ;
F_13 ( 0 , V_6 -> V_16 + V_17 ) ;
return 0 ;
}
static int F_56 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
unsigned int V_158 )
{
const struct V_86 * V_87 = F_42 ( V_4 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_159 , V_160 = V_87 -> V_161 ;
struct V_129 * V_130 = V_11 -> V_130 ;
struct V_92 * V_93 = & V_11 -> V_130 -> V_93 ;
unsigned long V_41 ;
if ( V_158 != 0 )
return - V_40 ;
if ( V_93 -> V_107 == V_106 && V_6 -> V_162 < V_160 )
V_160 = V_6 -> V_162 ;
V_159 = F_57 ( V_11 , V_6 -> V_163 ,
V_160 * sizeof( short ) ) ;
V_160 = V_159 / sizeof( short ) ;
if ( V_93 -> V_107 == V_106 )
V_6 -> V_162 -= V_160 ;
F_58 ( V_6 -> V_48 + V_52 , V_6 -> V_163 , V_159 ) ;
F_21 ( & V_4 -> V_42 , V_41 ) ;
V_6 -> V_136 |= V_164 | V_165 ;
F_13 ( V_6 -> V_136 | V_166 | V_167 ,
V_6 -> V_16 + V_145 ) ;
V_6 -> V_43 |= V_51 | V_45 | V_168 ;
F_13 ( V_6 -> V_43 , V_6 -> V_16 + V_46 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
V_130 -> V_169 = NULL ;
return 0 ;
}
static int F_59 ( struct V_3 * V_4 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_129 * V_130 = V_11 -> V_130 ;
struct V_92 * V_93 = & V_130 -> V_93 ;
unsigned int V_55 ;
unsigned long V_41 ;
F_21 ( & V_4 -> V_42 , V_41 ) ;
for ( V_55 = 0 ; V_55 < V_93 -> V_116 ; V_55 ++ ) {
V_6 -> V_43 |=
F_3 ( F_10 ( V_93 -> V_123 [ V_55 ] ) ) ;
V_6 -> V_43 |= F_1 ( F_10 ( V_93 -> V_123 [ V_55 ] ) ,
F_11 ( V_93 ->
V_123 [ V_55 ] ) ) ;
}
F_13 ( V_6 -> V_43 , V_6 -> V_16 + V_46 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
F_13 ( 0 , V_6 -> V_48 + V_49 ) ;
if ( V_93 -> V_101 == V_103 ) {
F_50 ( V_120 ,
& V_6 -> V_155 ,
& V_6 -> V_156 ,
& V_93 -> V_114 , V_93 -> V_41 ) ;
F_52 ( V_6 -> V_127 + V_170 , 0 , 1 ,
V_6 -> V_155 , 2 ) ;
F_52 ( V_6 -> V_127 + V_170 , 0 , 2 ,
V_6 -> V_156 , 2 ) ;
}
if ( V_93 -> V_107 == V_106 )
V_6 -> V_162 = V_93 -> V_116 * V_93 -> V_119 ;
F_21 ( & V_4 -> V_42 , V_41 ) ;
switch ( V_93 -> V_101 ) {
case V_103 :
V_6 -> V_43 |= V_171 ;
break;
case V_100 :
V_6 -> V_43 |= V_172 ;
break;
default:
F_22 ( & V_4 -> V_42 , V_41 ) ;
F_33 ( V_4 , L_7 ) ;
return - 1 ;
break;
}
F_22 ( & V_4 -> V_42 , V_41 ) ;
V_130 -> V_169 = F_56 ;
return 0 ;
}
static int F_60 ( struct V_3 * V_4 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_41 ;
F_21 ( & V_4 -> V_42 , V_41 ) ;
V_6 -> V_136 &= ~ V_165 & ~ V_164 ;
F_13 ( V_6 -> V_136 , V_6 -> V_16 + V_145 ) ;
V_6 -> V_43 &= ~ V_45 & ~ V_50 ;
F_13 ( V_6 -> V_43 , V_6 -> V_16 + V_46 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
return 0 ;
}
static void F_61 ( struct V_3 * V_4 , unsigned int V_15 )
{
const struct V_86 * V_87 = F_42 ( V_4 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_10 * V_11 = V_4 -> V_173 ;
struct V_129 * V_130 = V_11 -> V_130 ;
struct V_92 * V_93 = & V_130 -> V_93 ;
unsigned int V_174 = V_87 -> V_161 / 2 ;
unsigned int V_160 ;
unsigned long V_41 ;
if ( V_15 & V_166 ) {
F_21 ( & V_4 -> V_42 , V_41 ) ;
F_13 ( V_6 -> V_136 | V_166 ,
V_6 -> V_16 + V_145 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
if ( F_8 ( V_6 -> V_48 + V_46 ) & V_168 ) {
if ( V_93 -> V_107 == V_108 ||
( V_93 -> V_107 == V_106
&& V_6 -> V_162 ) ) {
F_33 ( V_4 , L_8 ) ;
V_130 -> V_175 |= V_176 ;
}
V_130 -> V_175 |= V_177 ;
}
} else if ( V_15 & V_167 ) {
unsigned int V_159 ;
V_160 = V_174 ;
if ( V_93 -> V_107 == V_106 &&
V_6 -> V_162 < V_160 )
V_160 = V_6 -> V_162 ;
V_159 =
F_57 ( V_11 , V_6 -> V_163 ,
V_160 * sizeof( short ) ) ;
V_160 = V_159 / sizeof( short ) ;
if ( V_130 -> V_93 . V_107 == V_106 )
V_6 -> V_162 -= V_160 ;
F_58 ( V_6 -> V_48 + V_52 , V_6 -> V_163 ,
V_160 ) ;
F_21 ( & V_4 -> V_42 , V_41 ) ;
F_13 ( V_6 -> V_136 | V_167 ,
V_6 -> V_16 + V_145 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
}
F_62 ( V_4 , V_11 ) ;
}
static T_2 F_63 ( int V_178 , void * V_179 )
{
struct V_3 * V_4 = (struct V_3 * ) V_179 ;
const struct V_86 * V_87 = F_42 ( V_4 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_10 * V_11 = V_4 -> V_180 ;
struct V_129 * V_130 ;
int V_15 , V_181 ;
int V_174 = V_87 -> V_161 / 2 ;
unsigned int V_182 , V_55 ;
static const int V_54 = 10000 ;
unsigned long V_41 ;
if ( ! V_4 -> V_183 )
return V_184 ;
V_130 = V_11 -> V_130 ;
V_181 = F_64 ( V_6 -> V_60 + V_185 ) ;
if ( ( V_186 & V_181 ) == 0 )
return V_184 ;
F_65 ( V_6 -> V_60 + V_187 ) ;
F_66 ( V_6 -> V_188 | V_189 ,
V_6 -> V_60 + V_185 ) ;
V_15 = F_8 ( V_6 -> V_16 + V_145 ) ;
if ( V_15 & ( V_167 | V_166 ) )
F_61 ( V_4 , V_15 ) ;
if ( V_15 & V_190 ) {
V_182 = V_174 ;
if ( V_130 -> V_93 . V_107 == V_106 &&
V_182 > V_6 -> V_135 ) {
V_182 = V_6 -> V_135 ;
}
F_67 ( V_6 -> V_33 + V_35 , V_6 -> V_191 ,
V_182 ) ;
F_68 ( V_11 , V_6 -> V_191 ,
V_182 * sizeof( short ) ) ;
V_6 -> V_135 -= V_182 ;
if ( V_130 -> V_93 . V_107 == V_106 && V_6 -> V_135 == 0 )
V_130 -> V_175 |= V_177 ;
F_21 ( & V_4 -> V_42 , V_41 ) ;
F_13 ( V_6 -> V_136 | INT ,
V_6 -> V_16 + V_145 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
} else if ( V_15 & ( V_192 | V_193 ) ) {
for ( V_55 = 0 ; V_55 < V_54 ; V_55 ++ ) {
if ( ( V_194 & F_8 ( V_6 -> V_16 +
V_145 ) ) == 0 )
break;
F_69 ( V_11 , F_8 ( V_6 -> V_33 ) ) ;
if ( V_130 -> V_93 . V_107 == V_106 &&
-- V_6 -> V_135 == 0 ) {
V_130 -> V_175 |= V_177 ;
break;
}
}
F_21 ( & V_4 -> V_42 , V_41 ) ;
F_13 ( V_6 -> V_136 | INT ,
V_6 -> V_16 + V_145 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
} else if ( V_15 & V_143 ) {
F_33 ( V_4 ,
L_9 ) ;
F_21 ( & V_4 -> V_42 , V_41 ) ;
F_13 ( V_6 -> V_136 | V_143 ,
V_6 -> V_16 + V_145 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
}
if ( V_15 & V_144 ) {
F_33 ( V_4 , L_10 ) ;
F_21 ( & V_4 -> V_42 , V_41 ) ;
F_13 ( V_6 -> V_136 | V_144 ,
V_6 -> V_16 + V_145 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
V_130 -> V_175 |= V_177 | V_176 ;
}
F_62 ( V_4 , V_11 ) ;
return V_195 ;
}
static int F_70 ( struct V_3 * V_4 ,
unsigned long V_14 )
{
struct V_196 * V_197 = F_71 ( V_4 ) ;
const struct V_86 * V_87 = NULL ;
struct V_5 * V_6 ;
struct V_10 * V_11 ;
int V_55 ;
int V_25 ;
if ( V_14 < F_72 ( V_198 ) )
V_87 = & V_198 [ V_14 ] ;
if ( ! V_87 )
return - V_199 ;
V_4 -> V_200 = V_87 ;
V_4 -> V_201 = V_87 -> V_202 ;
V_6 = F_73 ( V_4 , sizeof( * V_6 ) ) ;
if ( ! V_6 )
return - V_203 ;
V_25 = F_74 ( V_4 ) ;
if ( V_25 )
return V_25 ;
V_6 -> V_60 = F_75 ( V_197 , 0 ) ;
V_6 -> V_16 = F_75 ( V_197 , 1 ) ;
V_6 -> V_33 = F_75 ( V_197 , 2 ) ;
V_6 -> V_127 = F_75 ( V_197 , 3 ) ;
if ( V_87 -> V_204 )
V_6 -> V_48 = F_75 ( V_197 , 4 ) ;
F_66 ( V_189 ,
V_6 -> V_60 + V_185 ) ;
if ( F_76 ( V_197 -> V_178 , F_63 ,
V_205 , V_4 -> V_206 -> V_207 , V_4 ) ) {
F_77 ( V_4 -> V_39 , L_11 ,
V_197 -> V_178 ) ;
return - V_40 ;
}
V_4 -> V_178 = V_197 -> V_178 ;
V_25 = F_78 ( V_4 , 7 ) ;
if ( V_25 )
return V_25 ;
V_11 = & V_4 -> V_208 [ 0 ] ;
V_4 -> V_180 = V_11 ;
V_11 -> type = V_209 ;
V_11 -> V_210 = V_211 | V_212 | V_213 | V_214 ;
V_11 -> V_124 = V_87 -> V_215 ;
V_11 -> V_216 = V_87 -> V_215 ;
V_11 -> V_217 = ( 1 << V_87 -> V_218 ) - 1 ;
V_11 -> V_219 = V_87 -> V_220 ;
V_11 -> V_221 = F_9 ;
V_11 -> V_222 = F_18 ;
V_11 -> V_223 = F_53 ;
V_11 -> V_224 = F_45 ;
V_11 -> V_225 = F_55 ;
V_11 = & V_4 -> V_208 [ 1 ] ;
if ( V_87 -> V_204 ) {
V_11 -> type = V_226 ;
V_11 -> V_210 = V_211 | V_227 | V_212 ;
V_11 -> V_124 = V_87 -> V_204 ;
V_11 -> V_217 = ( 1 << V_87 -> V_218 ) - 1 ;
V_11 -> V_219 = & V_228 ;
V_11 -> V_221 = F_24 ;
if ( V_87 -> V_229 ) {
V_4 -> V_173 = V_11 ;
V_11 -> V_210 |= V_230 ;
V_11 -> V_231 = F_23 ;
V_11 -> V_224 = F_54 ;
V_11 -> V_223 = F_59 ;
V_11 -> V_225 = F_60 ;
} else {
V_11 -> V_231 = F_20 ;
}
} else {
V_11 -> type = V_232 ;
}
V_11 = & V_4 -> V_208 [ 2 ] ;
V_25 = F_79 ( V_4 , V_11 , NULL ,
V_6 -> V_127 + V_233 ) ;
if ( V_25 )
return V_25 ;
V_11 = & V_4 -> V_208 [ 3 ] ;
V_11 -> type = V_234 ;
V_11 -> V_210 = V_211 | V_235 ;
V_11 -> V_124 = 256 ;
V_11 -> V_217 = 0xff ;
V_11 -> V_221 = F_30 ;
V_11 = & V_4 -> V_208 [ 4 ] ;
V_11 -> type = V_236 ;
V_11 -> V_210 = V_211 | V_227 | V_235 ;
V_11 -> V_124 = V_237 ;
V_11 -> V_217 = 0xff ;
V_11 -> V_221 = F_35 ;
V_11 -> V_231 = F_34 ;
for ( V_55 = 0 ; V_55 < V_11 -> V_124 ; V_55 ++ )
F_32 ( V_4 , V_55 , V_11 -> V_217 / 2 ) ;
V_11 = & V_4 -> V_208 [ 5 ] ;
V_11 -> type = V_236 ;
V_11 -> V_210 = V_211 | V_227 | V_235 ;
if ( V_87 -> V_89 == V_90 ) {
V_11 -> V_124 = V_238 ;
V_11 -> V_217 = 0x7f ;
} else {
V_11 -> V_124 = V_239 ;
V_11 -> V_217 = 0xff ;
}
V_11 -> V_221 = F_44 ;
V_11 -> V_231 = F_43 ;
for ( V_55 = 0 ; V_55 < V_11 -> V_124 ; V_55 ++ )
F_41 ( V_4 , V_55 , V_11 -> V_217 / 2 ) ;
V_11 = & V_4 -> V_208 [ 6 ] ;
if ( V_87 -> V_240 ) {
V_11 -> type = V_236 ;
V_11 -> V_210 = V_211 | V_227 | V_235 ;
V_11 -> V_124 = V_241 ;
V_11 -> V_221 = F_38 ;
V_11 -> V_231 = F_37 ;
V_11 -> V_217 = 0xff ;
F_36 ( V_4 , V_11 -> V_217 / 2 ) ;
} else
V_11 -> type = V_232 ;
F_64 ( V_6 -> V_60 + V_187 ) ;
V_6 -> V_188 =
F_80 ( 3 ) | F_81 ( 3 ) |
V_242 ;
F_66 ( V_6 -> V_188 | V_189 ,
V_6 -> V_60 + V_185 ) ;
return 0 ;
}
static void F_82 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_6 ) {
if ( V_6 -> V_60 ) {
F_66 ( V_189 ,
V_6 -> V_60 + V_185 ) ;
}
}
if ( V_4 -> V_178 )
F_83 ( V_4 -> V_178 , V_4 ) ;
F_84 ( V_4 ) ;
}
static int F_85 ( struct V_196 * V_4 ,
const struct V_243 * V_36 )
{
return F_86 ( V_4 , & V_244 ,
V_36 -> V_245 ) ;
}
