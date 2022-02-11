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
static void F_31 ( struct V_3 * V_4 ,
unsigned int V_21 , T_1 V_75 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
static const int V_71 = 11 ;
unsigned int V_70 = ( ( V_21 & 0x7 ) << 8 ) | V_75 ;
static const int V_76 = 1 ;
F_30 ( V_4 , F_5 ( V_4 ) , V_70 ,
V_71 ) ;
F_26 ( V_76 ) ;
F_13 ( F_5 ( V_4 ) | V_77 ,
V_6 -> V_16 + V_28 ) ;
F_26 ( V_76 ) ;
F_13 ( F_5 ( V_4 ) , V_6 -> V_16 + V_28 ) ;
}
static int F_32 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_12 * V_13 ,
unsigned int * V_20 )
{
unsigned int V_21 = F_10 ( V_13 -> V_22 ) ;
if ( V_13 -> V_26 ) {
unsigned int V_75 = V_20 [ V_13 -> V_26 - 1 ] ;
if ( V_11 -> V_47 [ V_21 ] != V_75 ) {
F_31 ( V_4 , V_21 , V_75 ) ;
V_11 -> V_47 [ V_21 ] = V_75 ;
}
}
return V_13 -> V_26 ;
}
static void F_33 ( struct V_3 * V_4 , unsigned int V_78 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
V_78 &= 0xff ;
V_78 |= F_5 ( V_4 ) ;
F_13 ( V_78 , V_6 -> V_16 + V_28 ) ;
F_26 ( 1 ) ;
F_13 ( V_78 | V_79 ,
V_6 -> V_16 + V_28 ) ;
F_26 ( 1 ) ;
F_13 ( V_78 , V_6 -> V_16 + V_28 ) ;
F_26 ( 1 ) ;
}
static int F_34 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_12 * V_13 ,
unsigned int * V_20 )
{
unsigned int V_21 = F_10 ( V_13 -> V_22 ) ;
if ( V_13 -> V_26 ) {
unsigned int V_75 = V_20 [ V_13 -> V_26 - 1 ] ;
if ( V_11 -> V_47 [ V_21 ] != V_75 ) {
F_33 ( V_4 , V_75 ) ;
V_11 -> V_47 [ V_21 ] = V_75 ;
}
}
return V_13 -> V_26 ;
}
static int F_35 ( struct V_3 * V_4 , T_1 V_78 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
static const int V_71 = 7 ;
unsigned int V_70 = V_78 & 0x7f ;
unsigned int V_69 ;
static const int V_80 = 1 ;
V_69 = F_5 ( V_4 ) | V_81 ;
F_26 ( V_80 ) ;
F_13 ( V_69 , V_6 -> V_16 + V_28 ) ;
F_30 ( V_4 , V_69 , V_70 ,
V_71 ) ;
F_26 ( V_80 ) ;
F_13 ( F_5 ( V_4 ) , V_6 -> V_16 + V_28 ) ;
return 0 ;
}
static int F_36 ( struct V_3 * V_4 , unsigned int V_1 ,
T_1 V_78 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
static const int V_71 = 10 ;
unsigned int V_70 = ( ( V_1 & 0x3 ) << 8 ) | ( V_78 & 0xff ) ;
unsigned int V_69 ;
static const int V_82 = 1 ;
V_69 = F_5 ( V_4 ) | V_81 ;
F_26 ( V_82 ) ;
F_13 ( V_69 , V_6 -> V_16 + V_28 ) ;
F_30 ( V_4 , V_69 , V_70 ,
V_71 ) ;
F_26 ( V_82 ) ;
F_13 ( F_5 ( V_4 ) , V_6 -> V_16 + V_28 ) ;
return 0 ;
}
static void F_37 ( struct V_3 * V_4 ,
unsigned int V_21 , unsigned int V_75 )
{
const struct V_83 * V_84 = V_4 -> V_85 ;
switch ( V_84 -> V_86 ) {
case V_87 :
F_35 ( V_4 , V_75 ) ;
break;
case V_88 :
F_36 ( V_4 , V_21 , V_75 ) ;
break;
default:
F_19 ( V_4 -> V_39 , L_2 ) ;
break;
}
}
static int F_38 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_12 * V_13 ,
unsigned int * V_20 )
{
unsigned int V_21 = F_10 ( V_13 -> V_22 ) ;
if ( V_13 -> V_26 ) {
unsigned int V_75 = V_20 [ V_13 -> V_26 - 1 ] ;
if ( V_11 -> V_47 [ V_21 ] != V_75 ) {
F_37 ( V_4 , V_21 , V_75 ) ;
V_11 -> V_47 [ V_21 ] = V_75 ;
}
}
return V_13 -> V_26 ;
}
static int F_39 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_89 * V_90 )
{
unsigned int V_91 = F_10 ( V_90 -> V_92 [ 0 ] ) ;
unsigned int V_93 = F_11 ( V_90 -> V_92 [ 0 ] ) ;
int V_55 ;
for ( V_55 = 1 ; V_55 < V_90 -> V_94 ; V_55 ++ ) {
unsigned int V_21 = F_10 ( V_90 -> V_92 [ V_55 ] ) ;
unsigned int V_2 = F_11 ( V_90 -> V_92 [ V_55 ] ) ;
if ( V_21 != ( V_91 + V_55 ) % V_11 -> V_95 ) {
F_40 ( V_4 -> V_39 ,
L_3 ) ;
return - V_40 ;
}
if ( V_2 != V_93 ) {
F_40 ( V_4 -> V_39 ,
L_4 ) ;
return - V_40 ;
}
}
return 0 ;
}
static int F_41 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_89 * V_90 )
{
const struct V_83 * V_84 = V_4 -> V_85 ;
struct V_5 * V_6 = V_4 -> V_7 ;
int V_96 = 0 ;
unsigned int V_97 ;
V_96 |= F_42 ( & V_90 -> V_98 , V_99 | V_100 ) ;
V_96 |= F_42 ( & V_90 -> V_101 ,
V_102 | V_103 | V_100 ) ;
V_96 |= F_42 ( & V_90 -> V_104 ,
V_103 | V_99 | V_100 ) ;
V_96 |= F_42 ( & V_90 -> V_105 , V_106 ) ;
V_96 |= F_42 ( & V_90 -> V_107 , V_106 | V_108 ) ;
if ( V_96 )
return 1 ;
V_96 |= F_43 ( V_90 -> V_98 ) ;
V_96 |= F_43 ( V_90 -> V_101 ) ;
V_96 |= F_43 ( V_90 -> V_104 ) ;
V_96 |= F_43 ( V_90 -> V_107 ) ;
if ( V_90 -> V_101 == V_102 && V_90 -> V_104 == V_99 )
V_96 |= - V_40 ;
if ( V_90 -> V_101 != V_102 && V_90 -> V_104 != V_99 )
V_96 |= - V_40 ;
if ( V_90 -> V_98 == V_100 &&
( V_90 -> V_104 == V_100 || V_90 -> V_101 == V_100 ) )
V_96 |= - V_40 ;
if ( V_96 )
return 2 ;
switch ( V_90 -> V_98 ) {
case V_99 :
V_96 |= F_44 ( & V_90 -> V_109 , 0 ) ;
break;
case V_100 :
if ( ( V_90 -> V_109
& ( V_110 & ~ ( V_111 | V_112 ) ) ) != 0 ) {
V_90 -> V_109 &= ~ ( V_110 &
~ ( V_111 | V_112 ) ) ;
V_96 |= - V_40 ;
}
if ( ! V_84 -> V_113 && ( V_90 -> V_109 & V_112 ) ) {
V_90 -> V_109 &= ( V_110 & ~ V_112 ) ;
V_96 |= - V_40 ;
}
break;
}
if ( V_90 -> V_101 == V_103 )
V_96 |= F_45 ( & V_90 -> V_114 ,
V_84 -> V_115 * V_90 -> V_94 ) ;
if ( V_90 -> V_104 == V_103 )
V_96 |= F_45 ( & V_90 -> V_116 ,
V_84 -> V_115 ) ;
V_96 |= F_44 ( & V_90 -> V_117 , V_90 -> V_94 ) ;
if ( V_90 -> V_107 == V_106 )
V_96 |= F_45 ( & V_90 -> V_118 , 1 ) ;
else
V_96 |= F_44 ( & V_90 -> V_118 , 0 ) ;
if ( V_96 )
return 3 ;
if ( V_90 -> V_101 == V_103 ) {
V_97 = V_90 -> V_114 ;
F_46 ( V_119 ,
& V_6 -> V_120 ,
& V_6 -> V_121 ,
& V_97 , V_90 -> V_41 ) ;
V_96 |= F_44 ( & V_90 -> V_114 , V_97 ) ;
}
if ( V_90 -> V_104 == V_103 ) {
V_97 = V_90 -> V_116 ;
F_46 ( V_119 ,
& V_6 -> V_120 ,
& V_6 -> V_121 ,
& V_97 , V_90 -> V_41 ) ;
V_96 |= F_44 ( & V_90 -> V_116 , V_97 ) ;
}
if ( V_96 )
return 4 ;
if ( V_90 -> V_92 && V_90 -> V_94 > 0 )
V_96 |= F_39 ( V_4 , V_11 , V_90 ) ;
if ( V_96 )
return 5 ;
return 0 ;
}
static void F_47 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_122 = V_4 -> V_59 + V_123 ;
F_48 ( V_122 , 0 , 1 , V_124 | V_125 ) ;
F_48 ( V_122 , 0 , 2 , V_124 | V_125 ) ;
F_49 ( V_122 , 0 , 1 , V_6 -> V_120 ) ;
F_49 ( V_122 , 0 , 2 , V_6 -> V_121 ) ;
}
static int F_50 ( struct V_3 * V_4 ,
struct V_10 * V_11 )
{
const struct V_83 * V_84 = V_4 -> V_85 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_126 * V_127 = V_11 -> V_127 ;
struct V_89 * V_90 = & V_127 -> V_90 ;
unsigned int V_24 ;
unsigned long V_41 ;
F_13 ( 0 , V_6 -> V_16 + V_28 ) ;
F_13 ( 0 , V_6 -> V_16 + V_128 ) ;
F_13 ( 0 , V_6 -> V_33 + V_34 ) ;
V_24 = F_14 ( F_10 ( V_90 -> V_92 [ 0 ] ) ) |
F_15 ( F_10 ( V_90 -> V_92 [ V_90 -> V_94 - 1 ] ) ) |
F_16 ( F_11 ( V_90 -> V_92 [ 0 ] ) ) ;
if ( F_11 ( V_90 -> V_92 [ 0 ] ) & V_29 )
V_24 |= V_30 ;
if ( F_12 ( V_90 -> V_92 [ 0 ] ) != V_31 )
V_24 |= V_32 ;
if ( V_90 -> V_104 == V_100 || V_90 -> V_101 == V_100 )
V_24 |= V_129 ;
else
V_24 |= V_130 ;
F_13 ( V_24 , V_6 -> V_16 + V_17 ) ;
if ( V_90 -> V_101 == V_103 || V_90 -> V_104 == V_103 )
F_47 ( V_4 ) ;
F_21 ( & V_4 -> V_42 , V_41 ) ;
V_6 -> V_131 |= V_132 ;
V_6 -> V_131 &= ~ V_133 ;
if ( V_90 -> V_41 & V_134 ) {
if ( V_90 -> V_104 == V_99 && V_90 -> V_94 > 1 ) {
V_6 -> V_131 |= V_135 ;
} else {
V_6 -> V_131 |= V_136 ;
}
} else {
V_6 -> V_131 |= V_137 ;
}
F_13 ( V_6 -> V_131 | V_138 | INT | V_139 ,
V_6 -> V_16 + V_140 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
V_24 = 0 ;
if ( V_90 -> V_98 == V_99 ) {
V_24 |= V_141 ;
} else {
V_24 |= V_142 | V_143 | V_144 ;
if ( V_84 -> V_113 ) {
if ( V_90 -> V_109 & V_112 )
V_24 |= V_145 ;
if ( V_90 -> V_109 & V_111 )
V_24 |= V_146 ;
}
}
if ( V_90 -> V_104 == V_99 && V_90 -> V_94 > 1 )
V_24 |= V_147 ;
F_13 ( V_24 , V_6 -> V_16 + V_128 ) ;
return 0 ;
}
static int F_51 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_89 * V_90 )
{
unsigned int V_91 = F_10 ( V_90 -> V_92 [ 0 ] ) ;
if ( V_90 -> V_94 > 1 ) {
unsigned int V_148 = F_10 ( V_90 -> V_92 [ 1 ] ) ;
if ( V_91 != 0 || V_148 != 1 ) {
F_40 ( V_4 -> V_39 ,
L_5 ) ;
return - V_40 ;
}
}
return 0 ;
}
static int F_52 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_89 * V_90 )
{
const struct V_83 * V_84 = V_4 -> V_85 ;
struct V_5 * V_6 = V_4 -> V_7 ;
int V_96 = 0 ;
unsigned int V_97 ;
V_96 |= F_42 ( & V_90 -> V_98 , V_149 ) ;
V_96 |= F_42 ( & V_90 -> V_101 ,
V_103 | V_100 ) ;
V_96 |= F_42 ( & V_90 -> V_104 , V_99 ) ;
V_96 |= F_42 ( & V_90 -> V_105 , V_106 ) ;
V_96 |= F_42 ( & V_90 -> V_107 , V_106 | V_108 ) ;
if ( V_96 )
return 1 ;
V_96 |= F_43 ( V_90 -> V_101 ) ;
V_96 |= F_43 ( V_90 -> V_107 ) ;
if ( V_96 )
return 2 ;
V_96 |= F_44 ( & V_90 -> V_109 , 0 ) ;
if ( V_90 -> V_101 == V_103 )
V_96 |= F_45 ( & V_90 -> V_114 ,
V_84 -> V_150 ) ;
V_96 |= F_44 ( & V_90 -> V_117 , V_90 -> V_94 ) ;
if ( V_90 -> V_107 == V_106 )
V_96 |= F_45 ( & V_90 -> V_118 , 1 ) ;
else
V_96 |= F_44 ( & V_90 -> V_118 , 0 ) ;
if ( V_96 )
return 3 ;
if ( V_90 -> V_101 == V_103 ) {
V_97 = V_90 -> V_114 ;
F_46 ( V_119 ,
& V_6 -> V_151 ,
& V_6 -> V_152 ,
& V_97 , V_90 -> V_41 ) ;
V_96 |= F_44 ( & V_90 -> V_114 , V_97 ) ;
}
if ( V_96 )
return 4 ;
if ( V_90 -> V_92 && V_90 -> V_94 > 0 )
V_96 |= F_51 ( V_4 , V_11 , V_90 ) ;
if ( V_96 )
return 5 ;
return 0 ;
}
static int F_53 ( struct V_3 * V_4 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_41 ;
F_21 ( & V_4 -> V_42 , V_41 ) ;
V_6 -> V_131 &= ~ V_132 & ~ V_153 ;
F_13 ( V_6 -> V_131 , V_6 -> V_16 + V_140 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
F_13 ( 0 , V_6 -> V_16 + V_128 ) ;
F_13 ( 0 , V_6 -> V_16 + V_17 ) ;
return 0 ;
}
static void F_54 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
unsigned int V_154 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_155 ;
V_154 = F_55 ( V_11 , V_154 ) ;
V_155 = F_56 ( V_11 , V_6 -> V_156 , V_154 ) ;
V_154 = F_57 ( V_11 , V_155 ) ;
F_58 ( V_6 -> V_48 + V_52 , V_6 -> V_156 , V_154 ) ;
}
static int F_59 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
unsigned int V_157 )
{
const struct V_83 * V_84 = V_4 -> V_85 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_126 * V_127 = V_11 -> V_127 ;
struct V_89 * V_90 = & V_127 -> V_90 ;
unsigned long V_41 ;
if ( V_157 != V_90 -> V_109 )
return - V_40 ;
F_54 ( V_4 , V_11 , V_84 -> V_158 ) ;
F_21 ( & V_4 -> V_42 , V_41 ) ;
V_6 -> V_131 |= V_159 | V_160 ;
F_13 ( V_6 -> V_131 | V_161 | V_162 ,
V_6 -> V_16 + V_140 ) ;
V_6 -> V_43 |= V_51 | V_45 | V_163 ;
F_13 ( V_6 -> V_43 , V_6 -> V_16 + V_46 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
V_127 -> V_164 = NULL ;
return 0 ;
}
static void F_60 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_122 = V_4 -> V_59 + V_165 ;
F_48 ( V_122 , 0 , 1 , V_124 | V_125 ) ;
F_48 ( V_122 , 0 , 2 , V_124 | V_125 ) ;
F_49 ( V_122 , 0 , 1 , V_6 -> V_151 ) ;
F_49 ( V_122 , 0 , 2 , V_6 -> V_152 ) ;
}
static int F_61 ( struct V_3 * V_4 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_126 * V_127 = V_11 -> V_127 ;
struct V_89 * V_90 = & V_127 -> V_90 ;
unsigned int V_55 ;
unsigned long V_41 ;
F_21 ( & V_4 -> V_42 , V_41 ) ;
for ( V_55 = 0 ; V_55 < V_90 -> V_94 ; V_55 ++ ) {
V_6 -> V_43 |=
F_3 ( F_10 ( V_90 -> V_92 [ V_55 ] ) ) ;
V_6 -> V_43 |= F_1 ( F_10 ( V_90 -> V_92 [ V_55 ] ) ,
F_11 ( V_90 ->
V_92 [ V_55 ] ) ) ;
}
F_13 ( V_6 -> V_43 , V_6 -> V_16 + V_46 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
F_13 ( 0 , V_6 -> V_48 + V_49 ) ;
if ( V_90 -> V_101 == V_103 )
F_60 ( V_4 ) ;
F_21 ( & V_4 -> V_42 , V_41 ) ;
switch ( V_90 -> V_101 ) {
case V_103 :
V_6 -> V_43 |= V_166 ;
break;
case V_100 :
V_6 -> V_43 |= V_167 ;
break;
default:
F_22 ( & V_4 -> V_42 , V_41 ) ;
F_19 ( V_4 -> V_39 , L_6 ) ;
return - 1 ;
}
F_22 ( & V_4 -> V_42 , V_41 ) ;
V_127 -> V_164 = F_59 ;
return 0 ;
}
static int F_62 ( struct V_3 * V_4 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_41 ;
F_21 ( & V_4 -> V_42 , V_41 ) ;
V_6 -> V_131 &= ~ V_160 & ~ V_159 ;
F_13 ( V_6 -> V_131 , V_6 -> V_16 + V_140 ) ;
V_6 -> V_43 &= ~ V_45 & ~ V_50 ;
F_13 ( V_6 -> V_43 , V_6 -> V_16 + V_46 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
return 0 ;
}
static void F_63 ( struct V_3 * V_4 , unsigned int V_15 )
{
const struct V_83 * V_84 = V_4 -> V_85 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_10 * V_11 = V_4 -> V_168 ;
struct V_126 * V_127 = V_11 -> V_127 ;
struct V_89 * V_90 = & V_127 -> V_90 ;
unsigned long V_41 ;
if ( V_15 & V_161 ) {
F_21 ( & V_4 -> V_42 , V_41 ) ;
F_13 ( V_6 -> V_131 | V_161 ,
V_6 -> V_16 + V_140 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
if ( F_8 ( V_6 -> V_48 + V_46 ) & V_163 ) {
if ( V_90 -> V_107 == V_106 &&
V_127 -> V_169 >= V_90 -> V_118 ) {
V_127 -> V_170 |= V_171 ;
} else {
F_19 ( V_4 -> V_39 , L_7 ) ;
V_127 -> V_170 |= V_172 ;
}
}
} else if ( V_15 & V_162 ) {
F_54 ( V_4 , V_11 , V_84 -> V_158 / 2 ) ;
F_21 ( & V_4 -> V_42 , V_41 ) ;
F_13 ( V_6 -> V_131 | V_162 ,
V_6 -> V_16 + V_140 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
}
F_64 ( V_4 , V_11 ) ;
}
static T_2 F_65 ( int V_173 , void * V_174 )
{
struct V_3 * V_4 = (struct V_3 * ) V_174 ;
const struct V_83 * V_84 = V_4 -> V_85 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_10 * V_11 = V_4 -> V_175 ;
struct V_126 * V_127 ;
struct V_89 * V_90 ;
int V_15 , V_176 ;
int V_177 = V_84 -> V_158 / 2 ;
unsigned int V_178 , V_55 ;
static const int V_54 = 10000 ;
unsigned long V_41 ;
if ( ! V_4 -> V_179 )
return V_180 ;
V_127 = V_11 -> V_127 ;
V_90 = & V_127 -> V_90 ;
V_176 = F_66 ( V_6 -> V_60 + V_181 ) ;
if ( ( V_182 & V_176 ) == 0 )
return V_180 ;
F_67 ( V_6 -> V_60 + V_183 ) ;
F_68 ( V_6 -> V_184 | V_185 ,
V_6 -> V_60 + V_181 ) ;
V_15 = F_8 ( V_6 -> V_16 + V_140 ) ;
if ( V_15 & ( V_162 | V_161 ) )
F_63 ( V_4 , V_15 ) ;
if ( V_15 & V_186 ) {
V_178 = F_55 ( V_11 , V_177 ) ;
F_69 ( V_6 -> V_33 + V_35 , V_6 -> V_187 ,
V_178 ) ;
F_70 ( V_11 , V_6 -> V_187 , V_178 ) ;
if ( V_90 -> V_107 == V_106 &&
V_127 -> V_169 >= V_90 -> V_118 )
V_127 -> V_170 |= V_171 ;
F_21 ( & V_4 -> V_42 , V_41 ) ;
F_13 ( V_6 -> V_131 | INT ,
V_6 -> V_16 + V_140 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
} else if ( V_15 & ( V_188 | V_189 ) ) {
for ( V_55 = 0 ; V_55 < V_54 ; V_55 ++ ) {
unsigned short V_75 ;
if ( ( V_190 & F_8 ( V_6 -> V_16 +
V_140 ) ) == 0 )
break;
V_75 = F_8 ( V_6 -> V_33 ) ;
F_70 ( V_11 , & V_75 , 1 ) ;
if ( V_90 -> V_107 == V_106 &&
V_127 -> V_169 >= V_90 -> V_118 ) {
V_127 -> V_170 |= V_171 ;
break;
}
}
F_21 ( & V_4 -> V_42 , V_41 ) ;
F_13 ( V_6 -> V_131 | INT ,
V_6 -> V_16 + V_140 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
} else if ( V_15 & V_138 ) {
F_19 ( V_4 -> V_39 ,
L_8 ) ;
F_21 ( & V_4 -> V_42 , V_41 ) ;
F_13 ( V_6 -> V_131 | V_138 ,
V_6 -> V_16 + V_140 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
}
if ( V_15 & V_139 ) {
F_19 ( V_4 -> V_39 , L_9 ) ;
F_21 ( & V_4 -> V_42 , V_41 ) ;
F_13 ( V_6 -> V_131 | V_139 ,
V_6 -> V_16 + V_140 ) ;
F_22 ( & V_4 -> V_42 , V_41 ) ;
V_127 -> V_170 |= V_172 ;
}
F_64 ( V_4 , V_11 ) ;
return V_191 ;
}
static int F_71 ( struct V_3 * V_4 ,
unsigned long V_14 )
{
struct V_192 * V_193 = F_72 ( V_4 ) ;
const struct V_83 * V_84 = NULL ;
struct V_5 * V_6 ;
struct V_10 * V_11 ;
int V_55 ;
int V_25 ;
if ( V_14 < F_73 ( V_194 ) )
V_84 = & V_194 [ V_14 ] ;
if ( ! V_84 )
return - V_195 ;
V_4 -> V_85 = V_84 ;
V_4 -> V_196 = V_84 -> V_197 ;
V_6 = F_74 ( V_4 , sizeof( * V_6 ) ) ;
if ( ! V_6 )
return - V_198 ;
V_25 = F_75 ( V_4 ) ;
if ( V_25 )
return V_25 ;
V_6 -> V_60 = F_76 ( V_193 , 0 ) ;
V_6 -> V_16 = F_76 ( V_193 , 1 ) ;
V_6 -> V_33 = F_76 ( V_193 , 2 ) ;
V_4 -> V_59 = F_76 ( V_193 , 3 ) ;
if ( V_84 -> V_199 )
V_6 -> V_48 = F_76 ( V_193 , 4 ) ;
F_68 ( V_185 ,
V_6 -> V_60 + V_181 ) ;
V_25 = F_77 ( V_193 -> V_173 , F_65 , V_200 ,
V_4 -> V_196 , V_4 ) ;
if ( V_25 ) {
F_40 ( V_4 -> V_39 , L_10 ,
V_193 -> V_173 ) ;
return V_25 ;
}
V_4 -> V_173 = V_193 -> V_173 ;
V_25 = F_78 ( V_4 , 7 ) ;
if ( V_25 )
return V_25 ;
V_11 = & V_4 -> V_201 [ 0 ] ;
V_4 -> V_175 = V_11 ;
V_11 -> type = V_202 ;
V_11 -> V_203 = V_204 | V_205 | V_206 | V_207 ;
V_11 -> V_95 = V_84 -> V_208 ;
V_11 -> V_209 = V_84 -> V_208 ;
V_11 -> V_210 = ( 1 << V_84 -> V_211 ) - 1 ;
V_11 -> V_212 = V_84 -> V_213 ;
V_11 -> V_214 = F_9 ;
V_11 -> V_215 = F_18 ;
V_11 -> V_216 = F_50 ;
V_11 -> V_217 = F_41 ;
V_11 -> V_218 = F_53 ;
V_11 = & V_4 -> V_201 [ 1 ] ;
if ( V_84 -> V_199 ) {
V_11 -> type = V_219 ;
V_11 -> V_203 = V_204 | V_220 | V_205 ;
V_11 -> V_95 = V_84 -> V_199 ;
V_11 -> V_210 = ( 1 << V_84 -> V_211 ) - 1 ;
V_11 -> V_212 = & V_221 ;
V_11 -> V_222 = F_20 ;
V_25 = F_79 ( V_11 ) ;
if ( V_25 )
return V_25 ;
if ( V_84 -> V_223 ) {
V_4 -> V_168 = V_11 ;
V_11 -> V_203 |= V_224 ;
V_11 -> V_222 = F_23 ;
V_11 -> V_217 = F_52 ;
V_11 -> V_216 = F_61 ;
V_11 -> V_218 = F_62 ;
}
} else {
V_11 -> type = V_225 ;
}
V_11 = & V_4 -> V_201 [ 2 ] ;
V_25 = F_80 ( V_4 , V_11 , NULL , V_226 ) ;
if ( V_25 )
return V_25 ;
V_11 = & V_4 -> V_201 [ 3 ] ;
V_11 -> type = V_227 ;
V_11 -> V_203 = V_204 | V_228 ;
V_11 -> V_95 = 256 ;
V_11 -> V_210 = 0xff ;
V_11 -> V_214 = F_29 ;
V_11 = & V_4 -> V_201 [ 4 ] ;
V_11 -> type = V_229 ;
V_11 -> V_203 = V_204 | V_220 | V_228 ;
V_11 -> V_95 = V_230 ;
V_11 -> V_210 = 0xff ;
V_11 -> V_222 = F_32 ;
V_25 = F_79 ( V_11 ) ;
if ( V_25 )
return V_25 ;
for ( V_55 = 0 ; V_55 < V_11 -> V_95 ; V_55 ++ ) {
F_31 ( V_4 , V_55 , V_11 -> V_210 / 2 ) ;
V_11 -> V_47 [ V_55 ] = V_11 -> V_210 / 2 ;
}
V_11 = & V_4 -> V_201 [ 5 ] ;
V_11 -> type = V_229 ;
V_11 -> V_203 = V_204 | V_220 | V_228 ;
if ( V_84 -> V_86 == V_87 ) {
V_11 -> V_95 = V_231 ;
V_11 -> V_210 = 0x7f ;
} else {
V_11 -> V_95 = V_232 ;
V_11 -> V_210 = 0xff ;
}
V_11 -> V_222 = F_38 ;
V_25 = F_79 ( V_11 ) ;
if ( V_25 )
return V_25 ;
for ( V_55 = 0 ; V_55 < V_11 -> V_95 ; V_55 ++ ) {
F_37 ( V_4 , V_55 , V_11 -> V_210 / 2 ) ;
V_11 -> V_47 [ V_55 ] = V_11 -> V_210 / 2 ;
}
V_11 = & V_4 -> V_201 [ 6 ] ;
if ( V_84 -> V_233 ) {
V_11 -> type = V_229 ;
V_11 -> V_203 = V_204 | V_220 | V_228 ;
V_11 -> V_95 = V_234 ;
V_11 -> V_210 = 0xff ;
V_11 -> V_222 = F_34 ;
V_25 = F_79 ( V_11 ) ;
if ( V_25 )
return V_25 ;
for ( V_55 = 0 ; V_55 < V_11 -> V_95 ; V_55 ++ ) {
F_33 ( V_4 , V_11 -> V_210 / 2 ) ;
V_11 -> V_47 [ V_55 ] = V_11 -> V_210 / 2 ;
}
} else
V_11 -> type = V_225 ;
F_66 ( V_6 -> V_60 + V_183 ) ;
V_6 -> V_184 =
F_81 ( 3 ) | F_82 ( 3 ) |
V_235 ;
F_68 ( V_6 -> V_184 | V_185 ,
V_6 -> V_60 + V_181 ) ;
return 0 ;
}
static void F_83 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_6 && V_6 -> V_60 ) {
F_68 ( V_185 ,
V_6 -> V_60 + V_181 ) ;
}
F_84 ( V_4 ) ;
}
static int F_85 ( struct V_192 * V_4 ,
const struct V_236 * V_36 )
{
return F_86 ( V_4 , & V_237 ,
V_36 -> V_238 ) ;
}
