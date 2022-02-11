static inline unsigned long
F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void
F_3 ( struct V_1 * V_2 , unsigned int V_3 , unsigned long V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_6 )
{
unsigned long V_7 ;
F_6 ( V_7 ) ;
if ( V_2 -> V_8 == V_9 && V_6 == V_10 )
V_6 = ( T_1 ) - 1 ;
if ( V_2 -> V_8 == V_11 && V_6 == V_9 )
V_6 = V_10 ;
if ( V_6 != ( T_1 ) - 1 ) {
V_2 -> V_8 = V_6 ;
F_7 ( & V_2 -> V_12 ) ;
}
F_8 ( V_7 ) ;
}
static inline T_1 F_9 ( T_1 V_13 , struct V_14 * V_15 )
{
V_13 &= 0xffff ;
V_13 >>= 16 - V_15 -> V_16 ;
return V_13 << V_15 -> V_17 ;
}
static int
F_10 ( T_1 V_18 , T_1 V_19 , T_1 V_20 , T_1 V_21 ,
T_1 V_22 , struct V_23 * V_24 )
{
struct V_1 * V_2 = (struct V_1 * ) V_24 ;
T_1 V_5 ;
if ( V_18 >= V_2 -> V_25 )
return 1 ;
if ( V_2 -> V_26 . V_27 . V_28 ) {
V_2 -> V_29 [ V_18 ] = ( ( V_21 >> 8 ) & 0x00ff ) ;
return 0 ;
}
switch ( V_2 -> V_30 & V_31 ) {
case V_32 :
V_5 = ( ( V_19 >> 0 ) & 0xf800 ) ;
V_5 |= ( ( V_20 >> 5 ) & 0x07e0 ) ;
V_5 |= ( ( V_21 >> 11 ) & 0x001f ) ;
V_2 -> V_29 [ V_18 ] = V_5 ;
break;
case V_33 :
V_5 = ( ( V_19 << 8 ) & 0x00f80000 ) ;
V_5 |= ( ( V_20 >> 0 ) & 0x0000fc00 ) ;
V_5 |= ( ( V_21 >> 8 ) & 0x000000f8 ) ;
( ( V_34 * ) ( V_2 -> V_29 ) ) [ V_18 ] = V_5 ;
break;
case V_35 :
V_5 = ( ( V_19 << 8 ) & 0x00fc0000 ) ;
V_5 |= ( ( V_20 >> 0 ) & 0x0000fc00 ) ;
V_5 |= ( ( V_21 >> 8 ) & 0x000000fc ) ;
( ( V_34 * ) ( V_2 -> V_29 ) ) [ V_18 ] = V_5 ;
break;
case V_36 :
V_5 = ( ( V_19 << 8 ) & 0x00ff0000 ) ;
V_5 |= ( ( V_20 >> 0 ) & 0x0000ff00 ) ;
V_5 |= ( ( V_21 >> 8 ) & 0x000000ff ) ;
( ( V_34 * ) ( V_2 -> V_29 ) ) [ V_18 ] = V_5 ;
break;
}
return 0 ;
}
static int
F_11 ( T_1 V_18 , T_1 V_19 , T_1 V_20 , T_1 V_21 ,
T_1 V_22 , struct V_23 * V_24 )
{
struct V_1 * V_2 = (struct V_1 * ) V_24 ;
unsigned int V_5 ;
int V_37 = 1 ;
if ( V_2 -> V_38 ) {
V_19 = 0xffff - V_19 ;
V_20 = 0xffff - V_20 ;
V_21 = 0xffff - V_21 ;
}
if ( V_2 -> V_26 . V_27 . V_28 )
V_19 = V_20 = V_21 = ( 19595 * V_19 + 38470 * V_20 +
7471 * V_21 ) >> 16 ;
switch ( V_2 -> V_26 . V_39 . V_40 ) {
case V_41 :
if ( V_18 < 16 ) {
V_34 * V_42 = V_2 -> V_26 . V_43 ;
V_5 = F_9 ( V_19 , & V_2 -> V_26 . V_27 . V_19 ) ;
V_5 |= F_9 ( V_20 , & V_2 -> V_26 . V_27 . V_20 ) ;
V_5 |= F_9 ( V_21 , & V_2 -> V_26 . V_27 . V_21 ) ;
V_42 [ V_18 ] = V_5 ;
V_37 = 0 ;
}
break;
case V_44 :
case V_45 :
V_37 = F_10 ( V_18 , V_19 , V_20 , V_21 , V_22 , V_24 ) ;
break;
}
return V_37 ;
}
static inline int F_12 ( struct V_46 * V_27 )
{
return V_27 -> V_19 . V_16 + V_27 -> V_20 . V_16 +
V_27 -> V_21 . V_16 + V_27 -> V_47 . V_16 ;
}
static int F_13 ( struct V_46 * V_27 )
{
int V_48 = - V_49 ;
switch ( V_27 -> V_50 ) {
case 1 : V_48 = 0 ; break;
case 2 : V_48 = 1 ; break;
case 4 : V_48 = 2 ; break;
case 8 : V_48 = 3 ; break;
case 16 : V_48 = 4 ; break;
case 24 :
switch ( F_12 ( V_27 ) ) {
case 18 : V_48 = 6 ; break;
case 19 : V_48 = 8 ; break;
case 24 : V_48 = 9 ; break;
}
break;
case 32 :
switch ( F_12 ( V_27 ) ) {
case 18 : V_48 = 5 ; break;
case 19 : V_48 = 7 ; break;
case 25 : V_48 = 10 ; break;
}
break;
}
return V_48 ;
}
static T_2 F_14 ( struct V_46 * V_27 )
{
int V_48 = F_13 ( V_27 ) ;
T_2 V_51 ;
if ( V_48 < 0 )
return 0 ;
V_51 = F_15 ( V_48 ) ;
switch ( F_12 ( V_27 ) ) {
case 16 : V_51 |= V_27 -> V_47 . V_16 ? V_52 : 0 ; break;
case 18 : V_51 |= V_52 ; break;
case 24 : V_51 |= V_27 -> V_47 . V_16 ? V_53 : V_52 ;
break;
case 19 :
case 25 : V_51 |= V_54 ; break;
}
return V_51 ;
}
static void F_16 ( struct V_46 * V_27 , int V_55 )
{
if ( V_55 == 0 )
V_55 = V_27 -> V_50 ;
if ( V_27 -> V_50 < 16 ) {
V_27 -> V_19 . V_17 = 0 ; V_27 -> V_19 . V_16 = 8 ;
V_27 -> V_20 . V_17 = 0 ; V_27 -> V_20 . V_16 = 8 ;
V_27 -> V_21 . V_17 = 0 ; V_27 -> V_21 . V_16 = 8 ;
V_27 -> V_47 . V_17 = 0 ; V_27 -> V_47 . V_16 = 8 ;
}
switch ( V_55 ) {
case 16 : V_27 -> V_47 . V_16 ?
F_17 ( V_27 , 5 , 5 , 5 , 1 ) :
F_17 ( V_27 , 5 , 6 , 5 , 0 ) ; break;
case 18 : F_17 ( V_27 , 6 , 6 , 6 , 0 ) ; break;
case 19 : F_17 ( V_27 , 6 , 6 , 6 , 1 ) ; break;
case 24 : V_27 -> V_47 . V_16 ?
F_17 ( V_27 , 8 , 8 , 7 , 1 ) :
F_17 ( V_27 , 8 , 8 , 8 , 0 ) ; break;
case 25 : F_17 ( V_27 , 8 , 8 , 8 , 1 ) ; break;
}
}
static unsigned int F_18 ( struct V_46 * V_27 )
{
return V_27 -> V_56 * 8 * 16 / V_27 -> V_50 ;
}
static struct V_57 * F_19 ( struct V_58 * V_59 ,
struct V_46 * V_27 )
{
struct V_57 * V_60 = NULL ;
struct V_57 * V_61 = V_59 -> V_62 ;
unsigned int V_63 = 0xffffffff , V_64 = 0xffffffff ;
unsigned int V_65 ;
for ( V_65 = 0 ; V_65 < V_59 -> V_66 ; V_65 ++ ) {
if ( V_61 [ V_65 ] . V_67 >= V_27 -> V_67 &&
V_61 [ V_65 ] . V_68 >= V_27 -> V_68 &&
V_61 [ V_65 ] . V_67 < V_63 &&
V_61 [ V_65 ] . V_68 < V_64 &&
V_61 [ V_65 ] . V_48 >= V_27 -> V_50 ) {
V_63 = V_61 [ V_65 ] . V_67 ;
V_64 = V_61 [ V_65 ] . V_68 ;
V_60 = & V_61 [ V_65 ] ;
}
}
return V_60 ;
}
static void F_20 ( struct V_46 * V_27 ,
struct V_57 * V_60 )
{
V_27 -> V_67 = V_60 -> V_67 ;
V_27 -> V_68 = V_60 -> V_68 ;
V_27 -> V_50 = V_60 -> V_48 ;
V_27 -> V_56 = V_60 -> V_56 ;
V_27 -> V_69 = V_60 -> V_69 ;
V_27 -> V_70 = V_60 -> V_70 ;
V_27 -> V_71 = V_60 -> V_71 ;
V_27 -> V_72 = V_60 -> V_72 ;
V_27 -> V_73 = V_60 -> V_73 ;
V_27 -> V_74 = V_60 -> V_74 ;
V_27 -> V_75 = V_60 -> V_75 ;
V_27 -> V_28 = V_60 -> V_76 ;
V_27 -> V_47 . V_16 = V_60 -> V_77 ;
F_16 ( V_27 , V_60 -> V_55 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_46 * V_27 )
{
int V_78 ;
V_27 -> V_67 = F_22 ( int , V_27 -> V_67 , V_79 ) ;
V_27 -> V_68 = F_22 ( int , V_27 -> V_68 , V_80 ) ;
if ( ! ( V_2 -> V_81 & V_82 ) ) {
F_23 ( V_27 -> V_69 , 1 , 64 ) ;
F_23 ( V_27 -> V_72 , 1 , 64 ) ;
F_23 ( V_27 -> V_70 , 1 , 255 ) ;
F_23 ( V_27 -> V_71 , 1 , 255 ) ;
F_23 ( V_27 -> V_73 , 1 , 255 ) ;
F_23 ( V_27 -> V_74 , 1 , 255 ) ;
}
V_78 = V_27 -> V_67 * V_27 -> V_50 / 8 ;
V_78 = F_24 ( V_78 , 4 ) ;
V_27 -> V_67 = V_78 * 8 / V_27 -> V_50 ;
V_27 -> V_83 = V_27 -> V_67 ;
if ( V_27 -> V_84 & V_85 )
V_27 -> V_86 = V_2 -> V_26 . V_39 . V_87 / V_78 ;
else
V_27 -> V_86 = F_25 ( V_27 -> V_86 , V_27 -> V_68 ) ;
if ( V_27 -> V_67 > V_88 || V_27 -> V_68 > V_89 )
return - V_49 ;
if ( V_27 -> V_68 > V_27 -> V_86 )
return - V_49 ;
return 0 ;
}
static int F_26 ( struct V_46 * V_27 , struct V_23 * V_24 )
{
struct V_1 * V_2 = (struct V_1 * ) V_24 ;
struct V_58 * V_90 = V_2 -> V_91 -> V_92 ;
int V_93 ;
if ( V_90 -> V_94 ) {
struct V_57 * V_60 ;
V_60 = F_19 ( V_90 , V_27 ) ;
if ( ! V_60 )
return - V_49 ;
F_20 ( V_27 , V_60 ) ;
}
V_93 = F_13 ( V_27 ) ;
if ( V_93 < 0 )
return V_93 ;
F_16 ( V_27 , F_12 ( V_27 ) ) ;
V_93 = F_21 ( V_2 , V_27 ) ;
if ( V_93 )
return V_93 ;
#ifdef F_27
F_28 ( L_1 ,
F_18 ( V_27 ) ) ;
#endif
return 0 ;
}
static int F_29 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = (struct V_1 * ) V_24 ;
struct V_46 * V_27 = & V_24 -> V_27 ;
if ( V_27 -> V_50 >= 16 )
V_2 -> V_26 . V_39 . V_40 = V_41 ;
else if ( ! V_2 -> V_95 )
V_2 -> V_26 . V_39 . V_40 = V_45 ;
else {
V_2 -> V_26 . V_39 . V_40 = V_44 ;
}
V_2 -> V_26 . V_39 . V_78 = V_27 -> V_83 *
V_27 -> V_50 / 8 ;
if ( V_27 -> V_50 >= 16 )
V_2 -> V_25 = 0 ;
else
V_2 -> V_25 = V_27 -> V_50 == 1 ?
4 : 1 << V_27 -> V_50 ;
V_2 -> V_29 = ( V_96 * ) & V_2 -> V_97 -> V_98 [ 0 ] ;
if ( V_2 -> V_26 . V_27 . V_50 >= 16 )
F_30 ( & V_2 -> V_26 . V_99 ) ;
else
F_31 ( & V_2 -> V_26 . V_99 , 1 << V_2 -> V_26 . V_27 . V_50 , 0 ) ;
F_32 ( V_27 , V_2 ) ;
return 0 ;
}
static int F_33 ( struct V_46 * V_27 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = (struct V_1 * ) V_24 ;
struct V_46 V_100 ;
int V_101 = V_102 + V_103 ;
if ( V_2 -> V_6 != V_9 )
return 0 ;
memcpy ( & V_100 , & V_2 -> V_26 . V_27 , sizeof( V_100 ) ) ;
V_100 . V_104 = V_27 -> V_104 ;
V_100 . V_105 = V_27 -> V_105 ;
V_100 . V_106 &= ~ V_107 ;
V_100 . V_106 |= V_27 -> V_106 & V_107 ;
F_34 ( V_2 , & V_100 , 1 ) ;
if ( V_2 -> V_81 & V_108 )
F_3 ( V_2 , V_109 , V_2 -> V_110 [ V_101 + 1 ] | 0x1 ) ;
F_3 ( V_2 , V_111 , V_2 -> V_110 [ V_101 ] | 0x1 ) ;
return 0 ;
}
static int F_35 ( int V_112 , struct V_23 * V_24 )
{
struct V_1 * V_2 = (struct V_1 * ) V_24 ;
int V_65 ;
switch ( V_112 ) {
case V_113 :
case V_114 :
case V_115 :
case V_116 :
if ( V_2 -> V_26 . V_39 . V_40 == V_45 ||
V_2 -> V_26 . V_39 . V_40 == V_44 )
for ( V_65 = 0 ; V_65 < V_2 -> V_25 ; V_65 ++ )
F_10 ( V_65 , 0 , 0 , 0 , 0 , V_24 ) ;
F_5 ( V_2 , V_11 ) ;
break;
case V_117 :
if ( V_2 -> V_26 . V_39 . V_40 == V_45 ||
V_2 -> V_26 . V_39 . V_40 == V_44 )
F_36 ( & V_2 -> V_26 . V_99 , V_24 ) ;
F_5 ( V_2 , V_9 ) ;
}
return 0 ;
}
static void F_37 ( struct V_118 * V_119 )
{
int V_120 = V_119 -> V_26 . V_39 . V_78 * V_119 -> V_26 . V_27 . V_86 ;
unsigned long V_121 = V_119 -> V_122 ;
F_38 ( V_119 -> V_2 , V_123 , V_124 , V_121 , V_120 ) ;
}
static void F_39 ( struct V_118 * V_119 )
{
int V_125 = F_1 ( V_119 -> V_2 , V_126 ) & V_127 ;
T_2 V_128 = V_119 -> V_2 -> V_110 [ V_123 ] | ( V_125 ? 0x1 : 0 ) ;
F_3 ( V_119 -> V_2 , V_125 ? V_109 : V_129 , V_128 ) ;
F_3 ( V_119 -> V_2 , V_130 , V_119 -> V_131 [ 1 ] ) ;
F_3 ( V_119 -> V_2 , V_126 , V_119 -> V_131 [ 0 ] | V_127 ) ;
}
static void F_40 ( struct V_118 * V_119 )
{
T_2 V_132 ;
if ( ! ( F_1 ( V_119 -> V_2 , V_126 ) & V_127 ) )
return;
V_132 = F_1 ( V_119 -> V_2 , V_133 ) ;
F_3 ( V_119 -> V_2 , V_126 , V_119 -> V_131 [ 0 ] & ~ V_127 ) ;
F_3 ( V_119 -> V_2 , V_134 , F_41 ( 1 ) ) ;
F_3 ( V_119 -> V_2 , V_133 , V_132 & ~ F_41 ( 1 ) ) ;
F_3 ( V_119 -> V_2 , V_109 , V_119 -> V_2 -> V_110 [ V_123 ] | 0x3 ) ;
if ( F_42 ( & V_119 -> V_135 , 1 * V_136 ) == 0 )
F_43 ( L_2 , V_137 ) ;
F_3 ( V_119 -> V_2 , V_133 , V_132 ) ;
}
static void F_44 ( struct V_118 * V_119 )
{
int V_120 , div = 1 , V_138 = F_45 ( V_119 -> V_26 . V_27 . V_139 ) ;
unsigned long V_121 [ 3 ] = { V_119 -> V_122 , 0 , 0 } ;
if ( V_138 == V_140 || V_138 == V_141 ) {
V_120 = V_119 -> V_26 . V_39 . V_78 * V_119 -> V_26 . V_27 . V_86 ;
F_38 ( V_119 -> V_2 , V_142 , - 1 , V_121 [ 0 ] , V_120 ) ;
} else {
V_120 = V_119 -> V_26 . V_27 . V_83 * V_119 -> V_26 . V_27 . V_86 ;
switch ( V_138 ) {
case V_143 : div = 1 ; break;
case V_144 : div = 2 ; break;
case V_145 : div = 4 ; break;
}
V_121 [ 1 ] = V_121 [ 0 ] + V_120 ;
V_121 [ 2 ] = V_121 [ 1 ] + V_120 / div ;
F_38 ( V_119 -> V_2 , V_142 , - 1 , V_121 [ 0 ] , V_120 ) ;
F_38 ( V_119 -> V_2 , V_146 , - 1 , V_121 [ 1 ] , V_120 / div ) ;
F_38 ( V_119 -> V_2 , V_147 , - 1 , V_121 [ 2 ] , V_120 / div ) ;
}
}
static void F_46 ( struct V_118 * V_119 )
{
int V_138 = F_45 ( V_119 -> V_26 . V_27 . V_139 ) ;
int V_125 = F_1 ( V_119 -> V_2 , V_148 ) & V_127 ;
T_2 V_149 = V_119 -> V_2 -> V_110 [ V_142 ] | ( V_125 ? 0x1 : 0 ) ;
T_2 V_150 = V_119 -> V_2 -> V_110 [ V_146 ] | ( V_125 ? 0x1 : 0 ) ;
T_2 V_151 = V_119 -> V_2 -> V_110 [ V_147 ] | ( V_125 ? 0x1 : 0 ) ;
if ( V_138 == V_140 || V_138 == V_141 )
F_3 ( V_119 -> V_2 , V_125 ? V_152 : V_153 , V_149 ) ;
else {
F_3 ( V_119 -> V_2 , V_125 ? V_152 : V_153 , V_149 ) ;
F_3 ( V_119 -> V_2 , V_125 ? V_154 : V_155 , V_150 ) ;
F_3 ( V_119 -> V_2 , V_125 ? V_156 : V_157 , V_151 ) ;
}
F_3 ( V_119 -> V_2 , V_158 , V_119 -> V_131 [ 1 ] ) ;
F_3 ( V_119 -> V_2 , V_148 , V_119 -> V_131 [ 0 ] | V_127 ) ;
}
static void F_47 ( struct V_118 * V_119 )
{
T_2 V_132 ;
if ( ! ( F_1 ( V_119 -> V_2 , V_148 ) & V_127 ) )
return;
V_132 = F_1 ( V_119 -> V_2 , V_133 ) ;
F_3 ( V_119 -> V_2 , V_148 , V_119 -> V_131 [ 0 ] & ~ V_127 ) ;
F_3 ( V_119 -> V_2 , V_134 , F_41 ( 2 ) ) ;
F_3 ( V_119 -> V_2 , V_133 , V_132 & ~ F_41 ( 2 ) ) ;
F_3 ( V_119 -> V_2 , V_152 , V_119 -> V_2 -> V_110 [ V_142 ] | 0x3 ) ;
F_3 ( V_119 -> V_2 , V_154 , V_119 -> V_2 -> V_110 [ V_146 ] | 0x3 ) ;
F_3 ( V_119 -> V_2 , V_156 , V_119 -> V_2 -> V_110 [ V_147 ] | 0x3 ) ;
if ( F_42 ( & V_119 -> V_135 , 1 * V_136 ) == 0 )
F_43 ( L_3 , V_137 ) ;
}
static int F_48 ( struct V_23 * V_24 , int V_159 )
{
struct V_118 * V_119 = (struct V_118 * ) V_24 ;
if ( V_159 == 0 )
return - V_160 ;
if ( V_119 -> V_161 ++ == 0 )
F_49 ( & V_119 -> V_2 -> V_26 , V_117 ) ;
return 0 ;
}
static int F_50 ( struct V_23 * V_24 , int V_159 )
{
struct V_118 * V_119 = (struct V_118 * ) V_24 ;
if ( V_119 -> V_161 == 1 ) {
V_119 -> V_162 -> V_163 ( V_119 ) ;
V_119 -> V_26 . V_27 . V_164 = - 1 ;
V_119 -> V_26 . V_27 . V_165 = - 1 ;
V_119 -> V_26 . V_27 . V_67 = V_119 -> V_26 . V_27 . V_83 = 0 ;
V_119 -> V_26 . V_27 . V_68 = V_119 -> V_26 . V_27 . V_86 = 0 ;
V_119 -> V_161 -- ;
}
return 0 ;
}
static int F_51 ( struct V_46 * V_27 ,
struct V_23 * V_24 )
{
struct V_118 * V_119 = (struct V_118 * ) V_24 ;
struct V_46 * V_166 = & V_119 -> V_2 -> V_26 . V_27 ;
int V_167 , V_168 , V_138 , V_48 ;
V_167 = F_52 ( V_27 -> V_139 ) ;
V_168 = F_53 ( V_27 -> V_139 ) ;
V_138 = F_45 ( V_27 -> V_139 ) ;
V_48 = F_13 ( V_27 ) ;
if ( V_48 < 0 )
return - V_49 ;
if ( V_119 -> V_169 == V_170 && V_138 != 0 )
return - V_49 ;
switch ( V_138 ) {
case V_140 :
V_48 = F_13 ( V_27 ) ;
if ( V_48 < 0 )
return - V_49 ;
F_16 ( V_27 , F_12 ( V_27 ) ) ;
break;
case V_141 : V_48 = 24 ; break;
case V_143 : V_48 = 8 ; break;
case V_144 : V_48 = 4 ; break;
case V_145 : V_48 = 2 ; break;
default:
return - V_49 ;
}
if ( ( V_167 * V_48 ) % 32 )
return - V_49 ;
V_27 -> V_67 = F_54 ( V_27 -> V_67 * V_48 , 32 ) / V_48 ;
if ( ( V_167 + V_27 -> V_67 > V_166 -> V_67 ) ||
( V_168 + V_27 -> V_68 > V_166 -> V_68 ) )
return - V_49 ;
V_27 -> V_83 = V_27 -> V_67 ;
V_27 -> V_86 = F_25 ( V_27 -> V_68 , V_27 -> V_86 ) ;
return 0 ;
}
static int F_55 ( struct V_118 * V_119 )
{
struct V_46 * V_27 = & V_119 -> V_26 . V_27 ;
int V_138 = F_45 ( V_27 -> V_139 ) ;
int V_120 , V_48 = 0 ;
switch ( V_138 ) {
case V_140 : V_48 = V_27 -> V_50 ; break;
case V_141 : V_48 = 24 ; break;
case V_143 : V_48 = 24 ; break;
case V_144 : V_48 = 16 ; break;
case V_145 : V_48 = 12 ; break;
}
V_119 -> V_26 . V_39 . V_78 = V_27 -> V_83 * V_48 / 8 ;
V_120 = F_56 ( V_119 -> V_26 . V_39 . V_78 * V_27 -> V_86 ) ;
if ( V_119 -> V_171 ) {
if ( V_119 -> V_172 >= V_120 )
return 0 ;
}
return - V_49 ;
}
static int F_57 ( struct V_23 * V_24 )
{
struct V_118 * V_119 = (struct V_118 * ) V_24 ;
struct V_46 * V_27 = & V_24 -> V_27 ;
int V_167 , V_168 , V_138 , V_48 , V_37 ;
V_37 = F_55 ( V_119 ) ;
if ( V_37 )
return V_37 ;
V_48 = F_13 ( V_27 ) ;
V_167 = F_52 ( V_27 -> V_139 ) ;
V_168 = F_53 ( V_27 -> V_139 ) ;
V_138 = F_45 ( V_27 -> V_139 ) ;
V_119 -> V_131 [ 0 ] = F_58 ( V_27 -> V_67 ) | F_59 ( V_27 -> V_68 ) |
F_60 ( V_48 ) ;
V_119 -> V_131 [ 1 ] = F_61 ( V_167 ) | F_62 ( V_168 ) ;
if ( V_119 -> V_169 == V_173 )
V_119 -> V_131 [ 1 ] |= F_63 ( V_138 ) ;
V_119 -> V_162 -> V_174 ( V_119 ) ;
V_119 -> V_162 -> V_175 ( V_119 ) ;
return 0 ;
}
static void T_3 F_64 ( struct V_1 * V_2 ,
struct V_118 * V_119 , int V_169 )
{
sprintf ( V_119 -> V_26 . V_39 . V_169 , L_4 , V_169 + 1 ) ;
V_119 -> V_26 . V_39 . type = V_176 ;
V_119 -> V_26 . V_39 . V_177 = 0 ;
V_119 -> V_26 . V_39 . V_178 = 1 ;
V_119 -> V_26 . V_27 . V_179 = V_180 ;
V_119 -> V_26 . V_27 . V_164 = - 1 ;
V_119 -> V_26 . V_27 . V_165 = - 1 ;
V_119 -> V_26 . V_27 . V_106 = V_181 ;
V_119 -> V_26 . V_182 = & V_183 ;
V_119 -> V_26 . V_7 = V_184 ;
V_119 -> V_26 . V_185 = - 1 ;
V_119 -> V_26 . V_43 = NULL ;
V_119 -> V_169 = V_169 ;
V_119 -> V_162 = & V_186 [ V_169 ] ;
V_119 -> V_161 = 0 ;
V_119 -> V_2 = V_2 ;
F_65 ( & V_119 -> V_135 ) ;
}
static inline int F_66 ( void )
{
if ( F_67 () || F_68 () )
return 1 ;
return 0 ;
}
static int T_3 F_69 ( struct V_1 * V_187 ,
struct V_118 * V_119 )
{
V_119 -> V_171 = F_70 ( F_56 ( V_187 -> V_172 ) ,
V_188 | V_189 ) ;
if ( V_119 -> V_171 == NULL )
return - V_190 ;
V_119 -> V_122 = F_71 ( V_119 -> V_171 ) ;
V_119 -> V_172 = F_56 ( V_187 -> V_172 ) ;
F_72 ( & V_119 -> V_26 . V_191 ) ;
V_119 -> V_26 . V_39 . V_192 = V_119 -> V_122 ;
V_119 -> V_26 . V_39 . V_87 = V_187 -> V_172 ;
F_73 ( & V_119 -> V_26 . V_191 ) ;
V_119 -> V_26 . V_193 = V_119 -> V_171 ;
return 0 ;
}
static void T_3 F_74 ( struct V_1 * V_2 )
{
int V_65 , V_37 ;
if ( ! F_66 () )
return;
for ( V_65 = 0 ; V_65 < 2 ; V_65 ++ ) {
struct V_118 * V_119 = & V_2 -> V_194 [ V_65 ] ;
F_64 ( V_2 , V_119 , V_65 ) ;
V_37 = F_75 ( & V_119 -> V_26 ) ;
if ( V_37 ) {
F_76 ( V_2 -> V_91 , L_5 , V_65 ) ;
continue;
}
V_37 = F_69 ( V_2 , V_119 ) ;
if ( V_37 ) {
F_76 ( V_2 -> V_91 ,
L_6 ,
V_65 ) ;
F_77 ( & V_119 -> V_26 ) ;
continue;
}
V_119 -> V_195 = 1 ;
}
F_3 ( V_2 , V_133 , ~ 0 ) ;
F_78 ( L_7 ) ;
}
static void T_4 F_79 ( struct V_1 * V_2 )
{
int V_65 ;
if ( ! F_66 () )
return;
for ( V_65 = 0 ; V_65 < 2 ; V_65 ++ ) {
struct V_118 * V_119 = & V_2 -> V_194 [ V_65 ] ;
if ( V_119 -> V_195 ) {
if ( V_119 -> V_171 )
F_80 ( V_119 -> V_171 ,
V_119 -> V_172 ) ;
F_77 ( & V_119 -> V_26 ) ;
}
}
}
static inline void F_74 ( struct V_1 * V_2 ) {}
static inline void F_79 ( struct V_1 * V_2 ) {}
static inline unsigned int F_81 ( struct V_1 * V_2 ,
unsigned int V_56 )
{
unsigned long long V_196 ;
V_196 = ( unsigned long long ) ( F_82 ( V_2 -> V_197 ) / 10000 ) ;
V_196 *= V_56 ;
F_83 ( V_196 , 100000000 * 2 ) ;
return ( unsigned int ) V_196 ;
}
static inline void F_84 ( struct V_1 * V_2 , unsigned int V_196 )
{
unsigned long V_198 ;
if ( ( V_196 == 0 ) || ( V_2 -> V_26 . V_27 . V_69 == 0 ) ) {
V_2 -> V_199 = 0 ;
return;
}
V_198 = F_82 ( V_2 -> V_197 ) / ( V_196 * V_2 -> V_26 . V_27 . V_69 ) ;
V_2 -> V_199 = V_198 ;
}
unsigned long F_85 ( struct V_200 * V_91 )
{
struct V_1 * V_2 = F_86 ( V_91 ) ;
if ( ! V_2 || ( V_2 -> V_6 != V_9 ) )
return 0 ;
return V_2 -> V_199 ;
}
static int F_38 ( struct V_1 * V_2 , int V_101 , int V_42 ,
unsigned long V_121 , T_5 V_120 )
{
struct V_201 * V_202 , * V_203 ;
unsigned int V_204 , V_205 ;
if ( V_101 < 0 || V_101 >= V_102 * 2 )
return - V_49 ;
V_202 = & V_2 -> V_97 -> V_202 [ V_101 ] ;
V_204 = F_87 ( struct V_206 , V_202 [ V_101 ] ) ;
V_202 -> V_207 = V_121 ;
V_202 -> V_208 = 0 ;
V_202 -> V_209 = V_120 ;
if ( V_42 < 0 || V_42 >= V_210 * 2 ) {
V_202 -> V_110 = V_2 -> V_211 + V_204 ;
V_2 -> V_110 [ V_101 ] = V_2 -> V_211 + V_204 ;
} else {
V_203 = & V_2 -> V_97 -> V_203 [ V_42 ] ;
V_205 = F_87 ( struct V_206 , V_203 [ V_42 ] ) ;
V_203 -> V_207 = V_2 -> V_211 + V_42 * V_212 ;
V_203 -> V_208 = 0 ;
if ( ( V_2 -> V_30 & V_31 ) == V_32 )
V_203 -> V_209 = V_2 -> V_25 * sizeof( V_96 ) ;
else
V_203 -> V_209 = V_2 -> V_25 * sizeof( V_34 ) ;
V_203 -> V_209 |= V_213 ;
V_203 -> V_110 = V_2 -> V_211 + V_204 ;
V_202 -> V_110 = V_2 -> V_211 + V_205 ;
V_2 -> V_110 [ V_101 ] = V_2 -> V_211 + V_204 ;
}
return 0 ;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_46 * V_27 ,
int V_214 )
{
struct V_215 * V_39 = & V_2 -> V_26 . V_39 ;
int V_216 , V_101 , V_42 , V_48 = V_27 -> V_50 ;
unsigned long V_17 ;
V_101 = V_103 + ( V_214 ? V_102 : 0 ) ;
V_42 = ( V_48 >= 16 ) ? V_124 : V_217 + ( V_214 ? V_210 : 0 ) ;
V_216 = V_39 -> V_78 * V_27 -> V_68 ;
V_17 = V_39 -> V_78 * V_27 -> V_105 + V_2 -> V_122 ;
if ( V_2 -> V_81 & V_108 ) {
V_216 = V_216 / 2 ;
F_38 ( V_2 , V_101 + 1 , V_124 , V_17 + V_216 , V_216 ) ;
}
F_38 ( V_2 , V_101 , V_42 , V_17 , V_216 ) ;
}
static int F_88 ( struct V_1 * V_2 )
{
struct V_201 * V_202 ;
unsigned long V_204 , V_218 ;
V_202 = & V_2 -> V_97 -> V_202 [ V_219 ] ;
V_204 = F_87 ( struct V_206 , V_202 [ V_219 ] ) ;
V_218 = F_87 ( struct V_206 , V_220 ) ;
V_202 -> V_110 = V_2 -> V_211 + V_204 ;
V_202 -> V_207 = V_2 -> V_211 + V_218 ;
V_202 -> V_208 = 0 ;
V_202 -> V_209 = V_2 -> V_221 * sizeof( V_222 ) ;
V_2 -> V_110 [ V_219 ] = V_202 -> V_110 ;
return 0 ;
}
int F_89 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_90 ( V_24 , struct V_1 , V_26 ) ;
T_2 V_223 ;
int V_37 = 0 ;
F_3 ( V_2 , V_224 , V_2 -> V_225 & ~ V_226 ) ;
while ( V_2 -> V_221 & 1 )
V_2 -> V_227 [ V_2 -> V_221 ++ ] = V_228 ;
V_2 -> V_227 [ V_2 -> V_221 ++ ] = V_229 ;
V_2 -> V_227 [ V_2 -> V_221 ++ ] = V_230 ;
F_88 ( V_2 ) ;
V_223 = F_1 ( V_2 , V_231 ) | V_232 | V_233 ;
F_3 ( V_2 , V_231 , V_223 ) ;
F_3 ( V_2 , V_234 , 0x0001 ) ;
F_3 ( V_2 , V_133 , F_91 ( 6 ) ) ;
F_3 ( V_2 , V_235 , V_2 -> V_236 ) ;
F_3 ( V_2 , V_237 , V_2 -> V_238 ) ;
F_3 ( V_2 , V_239 , V_2 -> V_240 ) ;
F_3 ( V_2 , V_241 , V_2 -> V_242 ) ;
F_3 ( V_2 , V_243 , V_2 -> V_110 [ 0 ] ) ;
F_3 ( V_2 , V_244 , V_2 -> V_110 [ 6 ] ) ;
F_3 ( V_2 , V_224 , V_2 -> V_225 | V_226 ) ;
if ( F_42 ( & V_2 -> V_245 , V_136 / 2 ) == 0 ) {
F_43 ( L_8 ,
V_137 ) ;
V_37 = - V_246 ;
}
V_223 = F_1 ( V_2 , V_231 ) & ~ ( V_232 | V_233 ) ;
F_3 ( V_2 , V_231 , V_223 ) ;
F_3 ( V_2 , V_224 , V_2 -> V_225 & ~ V_226 ) ;
F_3 ( V_2 , V_244 , 0 ) ;
V_2 -> V_221 = 0 ;
return V_37 ;
}
int F_92 ( struct V_23 * V_24 , V_222 * V_247 , int V_248 )
{
int V_65 ;
struct V_1 * V_2 = F_90 ( V_24 , struct V_1 , V_26 ) ;
for ( V_65 = 0 ; V_65 < V_248 ; V_65 ++ , V_247 ++ ) {
if ( ( * V_247 & 0xff00 ) == V_249 ) {
F_89 ( V_24 ) ;
F_93 ( * V_247 & 0xff ) ;
continue;
}
if ( V_2 -> V_221 == V_250 - 8 )
F_89 ( V_24 ) ;
V_2 -> V_227 [ V_2 -> V_221 ++ ] = * V_247 ;
}
return 0 ;
}
static unsigned int F_94 ( unsigned V_251 , unsigned long V_252 )
{
unsigned int V_253 = ( V_251 * ( V_252 / 1000000 ) / 1000 ) ;
return ( V_253 == 0 ) ? 1 : V_253 ;
}
static void F_95 ( struct V_1 * V_2 ,
struct V_46 * V_27 )
{
struct V_58 * V_90 = V_2 -> V_91 -> V_92 ;
struct V_57 * V_60 = & V_90 -> V_62 [ 0 ] ;
unsigned long V_254 = F_82 ( V_2 -> V_197 ) ;
unsigned V_255 , V_256 , V_257 , V_258 ;
V_255 = F_25 ( V_60 -> V_259 , V_60 -> V_260 ) ;
V_256 = F_25 ( V_60 -> V_261 , V_60 -> V_262 ) ;
V_257 = V_60 -> V_263 ;
V_258 = V_60 -> V_264 ;
V_2 -> V_236 =
F_96 ( V_27 -> V_67 ) |
F_97 ( F_94 ( V_255 , V_254 ) ) |
F_98 ( F_94 ( V_256 , V_254 ) ) |
F_99 ( F_94 ( V_257 , V_254 ) ) ;
V_2 -> V_238 = F_100 ( V_27 -> V_68 ) ;
V_2 -> V_240 = V_2 -> V_51 | F_101 ( F_94 ( V_258 , V_254 ) ) ;
V_2 -> V_240 |= ( V_27 -> V_75 & V_265 ) ? V_266 : 0 ;
V_2 -> V_240 |= ( V_27 -> V_75 & V_267 ) ? V_268 : 0 ;
V_2 -> V_269 = 1 ;
}
static int F_102 ( void * V_270 )
{
struct V_1 * V_2 = V_270 ;
struct V_58 * V_90 = V_2 -> V_91 -> V_92 ;
if ( ! V_90 -> V_271 ) {
F_103 ( L_9 ,
V_137 ) ;
return - V_49 ;
}
V_90 = V_2 -> V_91 -> V_92 ;
F_28 ( L_10 , V_137 ) ;
F_104 () ;
while ( ! F_105 () ) {
if ( F_106 () )
continue;
F_72 ( & V_2 -> V_272 ) ;
if ( V_2 -> V_6 == V_9 ) {
V_90 -> V_271 ( & V_2 -> V_26 ) ;
F_107 ( & V_2 -> V_273 ) ;
}
F_73 ( & V_2 -> V_272 ) ;
F_108 ( V_274 ) ;
F_109 ( 30 * V_136 / 1000 ) ;
}
F_28 ( L_11 , V_137 ) ;
return 0 ;
}
static int F_110 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_81 & V_82 ) )
return 0 ;
V_2 -> V_227 = ( V_222 * ) V_2 -> V_97 -> V_220 ;
V_2 -> V_221 = 0 ;
F_65 ( & V_2 -> V_245 ) ;
F_65 ( & V_2 -> V_273 ) ;
V_2 -> V_275 = F_111 ( F_102 , V_2 ,
L_12 ) ;
if ( F_112 ( V_2 -> V_275 ) ) {
F_103 ( L_13 , V_137 ) ;
return F_113 ( V_2 -> V_275 ) ;
}
return 0 ;
}
static inline int F_110 ( struct V_1 * V_2 ) { return 0 ; }
static void F_114 ( struct V_1 * V_2 ,
struct V_46 * V_27 )
{
unsigned int V_276 , V_196 = F_81 ( V_2 , V_27 -> V_56 ) ;
V_2 -> V_236 =
F_96 ( V_27 -> V_67 ) +
F_99 ( V_27 -> V_69 ) +
F_97 ( V_27 -> V_70 ) +
F_98 ( V_27 -> V_71 ) ;
V_276 = V_27 -> V_68 ;
if ( ( V_2 -> V_81 & V_108 ) == V_277 )
V_276 /= 2 ;
V_2 -> V_238 =
F_100 ( V_276 ) +
F_115 ( V_27 -> V_72 ) +
F_116 ( V_27 -> V_73 ) +
F_117 ( V_27 -> V_74 ) ;
V_2 -> V_240 = V_2 -> V_51 |
( V_27 -> V_75 & V_265 ?
V_278 : V_279 ) |
( V_27 -> V_75 & V_267 ?
V_280 : V_281 ) ;
if ( V_196 ) {
V_2 -> V_240 |= F_101 ( V_196 ) ;
F_84 ( V_2 , V_196 ) ;
}
}
static int F_32 ( struct V_46 * V_27 ,
struct V_1 * V_2 )
{
T_6 V_7 ;
F_6 ( V_7 ) ;
#ifdef F_118
if ( V_2 -> V_81 & V_82 )
F_95 ( V_2 , V_27 ) ;
else
#endif
F_114 ( V_2 , V_27 ) ;
F_34 ( V_2 , V_27 , 0 ) ;
V_2 -> V_225 = V_2 -> V_81 |
( V_282 | V_283 | V_284 | V_285 |
V_286 | V_287 | V_288 ) ;
V_2 -> V_240 |= F_14 ( V_27 ) ;
V_2 -> V_242 = F_1 ( V_2 , V_241 ) & ~ V_31 ;
V_2 -> V_242 |= ( V_2 -> V_30 & V_31 ) ;
F_8 ( V_7 ) ;
if ( ( F_1 ( V_2 , V_224 ) != V_2 -> V_225 ) ||
( F_1 ( V_2 , V_235 ) != V_2 -> V_236 ) ||
( F_1 ( V_2 , V_237 ) != V_2 -> V_238 ) ||
( F_1 ( V_2 , V_239 ) != V_2 -> V_240 ) ||
( F_1 ( V_2 , V_241 ) != V_2 -> V_242 ) ||
( F_1 ( V_2 , V_243 ) != V_2 -> V_110 [ 0 ] ) ||
( ( V_2 -> V_81 & V_108 ) &&
( F_1 ( V_2 , V_129 ) != V_2 -> V_110 [ 1 ] ) ) )
F_5 ( V_2 , V_10 ) ;
return 0 ;
}
static inline void F_119 ( struct V_1 * V_2 , int V_289 )
{
F_28 ( L_14 , V_289 ? L_15 : L_16 ) ;
if ( V_2 -> V_290 )
V_2 -> V_290 ( V_289 ) ;
}
static inline void F_120 ( struct V_1 * V_2 , int V_289 )
{
F_28 ( L_17 , V_289 ? L_15 : L_16 ) ;
if ( V_2 -> V_291 )
V_2 -> V_291 ( V_289 , & V_2 -> V_26 . V_27 ) ;
}
static void F_121 ( struct V_1 * V_2 )
{
F_28 ( L_18 ) ;
F_28 ( L_19 , ( unsigned int ) V_2 -> V_110 [ 0 ] ) ;
F_28 ( L_20 , ( unsigned int ) V_2 -> V_110 [ 1 ] ) ;
F_28 ( L_21 , ( unsigned int ) V_2 -> V_225 ) ;
F_28 ( L_22 , ( unsigned int ) V_2 -> V_236 ) ;
F_28 ( L_23 , ( unsigned int ) V_2 -> V_238 ) ;
F_28 ( L_24 , ( unsigned int ) V_2 -> V_240 ) ;
F_122 ( V_2 -> V_197 ) ;
if ( V_2 -> V_81 & V_82 )
return;
F_3 ( V_2 , V_241 , V_2 -> V_242 ) ;
F_3 ( V_2 , V_239 , V_2 -> V_240 ) ;
F_3 ( V_2 , V_237 , V_2 -> V_238 ) ;
F_3 ( V_2 , V_235 , V_2 -> V_236 ) ;
F_3 ( V_2 , V_224 , V_2 -> V_225 & ~ V_226 ) ;
F_3 ( V_2 , V_243 , V_2 -> V_110 [ 0 ] ) ;
if ( V_2 -> V_81 & V_108 )
F_3 ( V_2 , V_129 , V_2 -> V_110 [ 1 ] ) ;
F_3 ( V_2 , V_224 , V_2 -> V_225 | V_226 ) ;
}
static void F_123 ( struct V_1 * V_2 )
{
T_2 V_81 ;
#ifdef F_118
if ( V_2 -> V_81 & V_82 ) {
F_42 ( & V_2 -> V_273 ,
200 * V_136 / 1000 ) ;
return;
}
#endif
F_3 ( V_2 , V_292 , 0xffffffff ) ;
V_81 = F_1 ( V_2 , V_224 ) & ~ V_282 ;
F_3 ( V_2 , V_224 , V_81 ) ;
F_3 ( V_2 , V_224 , V_81 | V_293 ) ;
F_42 ( & V_2 -> V_294 , 200 * V_136 / 1000 ) ;
F_124 ( V_2 -> V_197 ) ;
}
static T_7 F_125 ( int V_295 , void * V_296 )
{
struct V_1 * V_2 = V_296 ;
unsigned int V_81 , V_297 ;
V_297 = F_1 ( V_2 , V_292 ) ;
if ( V_297 & V_298 ) {
V_81 = F_1 ( V_2 , V_224 ) ;
F_3 ( V_2 , V_224 , V_81 | V_282 ) ;
F_107 ( & V_2 -> V_294 ) ;
}
#ifdef F_118
if ( V_297 & V_299 )
F_107 ( & V_2 -> V_245 ) ;
#endif
F_3 ( V_2 , V_292 , V_297 ) ;
#ifdef F_126
{
unsigned int V_300 = F_1 ( V_2 , V_134 ) ;
if ( V_300 & F_41 ( 1 ) )
F_107 ( & V_2 -> V_194 [ 0 ] . V_135 ) ;
if ( V_300 & F_41 ( 2 ) )
F_107 ( & V_2 -> V_194 [ 1 ] . V_135 ) ;
F_3 ( V_2 , V_134 , V_300 ) ;
}
#endif
return V_301 ;
}
static void F_127 ( struct V_1 * V_2 , T_1 V_6 )
{
T_1 V_302 ;
F_72 ( & V_2 -> V_272 ) ;
V_302 = V_2 -> V_6 ;
if ( V_302 == V_303 && V_6 == V_10 )
V_6 = V_9 ;
switch ( V_6 ) {
case V_304 :
if ( V_302 != V_11 && V_302 != V_305 ) {
V_2 -> V_6 = V_6 ;
F_123 ( V_2 ) ;
}
break;
case V_305 :
case V_11 :
if ( V_302 != V_11 ) {
V_2 -> V_6 = V_6 ;
F_119 ( V_2 , 0 ) ;
F_120 ( V_2 , 0 ) ;
if ( V_302 != V_304 )
F_123 ( V_2 ) ;
}
break;
case V_306 :
if ( V_302 == V_304 ) {
V_2 -> V_6 = V_9 ;
F_121 ( V_2 ) ;
}
break;
case V_10 :
if ( V_302 == V_9 ) {
F_120 ( V_2 , 0 ) ;
F_123 ( V_2 ) ;
F_121 ( V_2 ) ;
F_120 ( V_2 , 1 ) ;
}
break;
case V_307 :
if ( V_302 != V_305 )
break;
case V_9 :
if ( V_302 != V_9 ) {
V_2 -> V_6 = V_9 ;
F_121 ( V_2 ) ;
F_120 ( V_2 , 1 ) ;
F_119 ( V_2 , 1 ) ;
}
break;
}
F_73 ( & V_2 -> V_272 ) ;
}
static void F_128 ( struct V_308 * V_309 )
{
struct V_1 * V_2 =
F_90 ( V_309 , struct V_1 , V_12 ) ;
T_1 V_6 = F_129 ( & V_2 -> V_8 , - 1 ) ;
F_127 ( V_2 , V_6 ) ;
}
static int
F_130 ( struct V_310 * V_311 , unsigned long V_5 , void * V_312 )
{
struct V_1 * V_2 = F_131 ( V_311 , V_313 ) ;
T_1 V_196 ;
switch ( V_5 ) {
case V_314 :
#ifdef F_126
if ( ! ( V_2 -> V_194 [ 0 ] . V_161 || V_2 -> V_194 [ 1 ] . V_161 ) )
#endif
F_127 ( V_2 , V_304 ) ;
break;
case V_315 :
V_196 = F_81 ( V_2 , V_2 -> V_26 . V_27 . V_56 ) ;
F_84 ( V_2 , V_196 ) ;
V_2 -> V_240 = ( V_2 -> V_240 & ~ 0xff ) |
F_101 ( V_196 ) ;
F_127 ( V_2 , V_306 ) ;
break;
}
return 0 ;
}
static int
F_132 ( struct V_310 * V_311 , unsigned long V_5 , void * V_312 )
{
struct V_1 * V_2 = F_131 ( V_311 , V_316 ) ;
struct V_46 * V_27 = & V_2 -> V_26 . V_27 ;
struct V_317 * V_318 = V_312 ;
switch ( V_5 ) {
case V_319 :
case V_320 :
F_28 ( L_25
L_26 , F_18 ( V_27 ) ,
V_318 -> F_25 ) ;
break;
}
return 0 ;
}
static int F_133 ( struct V_200 * V_91 )
{
struct V_1 * V_2 = F_86 ( V_91 ) ;
F_127 ( V_2 , V_305 ) ;
return 0 ;
}
static int F_134 ( struct V_200 * V_91 )
{
struct V_1 * V_2 = F_86 ( V_91 ) ;
F_127 ( V_2 , V_307 ) ;
return 0 ;
}
static int T_3 F_135 ( struct V_1 * V_2 )
{
int V_120 = F_56 ( V_2 -> V_172 ) ;
V_2 -> V_171 = F_70 ( V_120 , V_188 | V_189 ) ;
if ( V_2 -> V_171 == NULL )
return - V_190 ;
V_2 -> V_122 = F_71 ( V_2 -> V_171 ) ;
V_2 -> V_172 = V_120 ;
V_2 -> V_26 . V_39 . V_192 = V_2 -> V_122 ;
V_2 -> V_26 . V_39 . V_87 = V_2 -> V_172 ;
V_2 -> V_26 . V_193 = V_2 -> V_171 ;
return V_2 -> V_171 ? 0 : - V_190 ;
}
static void F_136 ( struct V_1 * V_2 ,
struct V_58 * V_90 )
{
unsigned int V_321 = V_90 -> V_321 ;
struct V_57 * V_322 ;
int V_65 ;
V_2 -> V_38 = V_90 -> V_38 ;
V_2 -> V_95 = V_90 -> V_95 ;
V_2 -> V_30 = V_90 -> V_30 ;
switch ( V_321 & V_323 ) {
case V_324 :
V_2 -> V_81 = V_325 ;
break;
case V_326 :
V_2 -> V_81 = V_325 | V_108 ;
break;
case V_327 :
V_2 -> V_81 = 0 ;
break;
case V_328 :
V_2 -> V_81 = V_108 ;
break;
case V_329 :
V_2 -> V_81 = V_330 ;
break;
case V_331 :
V_2 -> V_81 = V_82 | V_330 ;
break;
default:
V_2 -> V_81 = V_90 -> V_81 ;
V_2 -> V_51 = V_90 -> V_51 ;
goto V_332;
}
if ( V_321 == V_333 )
V_2 -> V_81 |= V_334 ;
V_2 -> V_81 |= ( V_321 & V_335 ) ? V_336 : 0 ;
V_2 -> V_51 = F_137 ( ( V_90 -> V_321 >> 10 ) & 0xff ) ;
V_2 -> V_51 |= ( V_321 & V_337 ) ? V_338 : 0 ;
V_2 -> V_51 |= ( V_321 & V_339 ) ? V_340 : 0 ;
V_332:
F_20 ( & V_2 -> V_26 . V_27 , & V_90 -> V_62 [ 0 ] ) ;
for ( V_65 = 0 , V_322 = & V_90 -> V_62 [ 0 ] ; V_65 < V_90 -> V_66 ; V_65 ++ , V_322 ++ )
V_2 -> V_172 = F_22 ( T_5 , V_2 -> V_172 ,
V_322 -> V_67 * V_322 -> V_68 * V_322 -> V_48 / 8 ) ;
if ( V_90 -> V_172 > V_2 -> V_172 )
V_2 -> V_172 = V_90 -> V_172 ;
if ( V_172 > V_2 -> V_172 )
V_2 -> V_172 = V_172 ;
}
static struct V_1 * T_3 F_138 ( struct V_200 * V_91 )
{
struct V_1 * V_2 ;
void * V_341 ;
struct V_58 * V_90 = V_91 -> V_92 ;
V_2 = F_139 ( sizeof( struct V_1 ) + sizeof( V_34 ) * 16 , V_188 ) ;
if ( ! V_2 )
return NULL ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_91 = V_91 ;
V_2 -> V_197 = F_140 ( V_91 , NULL ) ;
if ( F_112 ( V_2 -> V_197 ) ) {
F_141 ( V_2 ) ;
return NULL ;
}
strcpy ( V_2 -> V_26 . V_39 . V_169 , V_342 ) ;
V_2 -> V_26 . V_39 . type = V_176 ;
V_2 -> V_26 . V_39 . V_343 = 0 ;
V_2 -> V_26 . V_39 . V_177 = 0 ;
V_2 -> V_26 . V_39 . V_178 = 1 ;
V_2 -> V_26 . V_39 . V_344 = 0 ;
V_2 -> V_26 . V_39 . V_345 = V_346 ;
V_2 -> V_26 . V_27 . V_139 = 0 ;
V_2 -> V_26 . V_27 . V_179 = V_180 ;
V_2 -> V_26 . V_27 . V_164 = - 1 ;
V_2 -> V_26 . V_27 . V_165 = - 1 ;
V_2 -> V_26 . V_27 . V_84 = V_85 ;
V_2 -> V_26 . V_27 . V_106 = V_181 ;
V_2 -> V_26 . V_182 = & V_347 ;
V_2 -> V_26 . V_7 = V_348 ;
V_2 -> V_26 . V_185 = - 1 ;
V_341 = V_2 ;
V_341 = V_341 + sizeof( struct V_1 ) ;
V_2 -> V_26 . V_43 = V_341 ;
V_2 -> V_6 = V_303 ;
V_2 -> V_8 = ( V_349 ) - 1 ;
F_136 ( V_2 , V_90 ) ;
#ifdef F_126
if ( F_66 () )
V_2 -> V_81 |= V_350 ;
#endif
F_142 ( & V_2 -> V_351 ) ;
F_143 ( & V_2 -> V_12 , F_128 ) ;
F_144 ( & V_2 -> V_272 ) ;
F_65 ( & V_2 -> V_294 ) ;
return V_2 ;
}
static int T_3 F_145 ( struct V_200 * V_91 , const char * V_352 )
{
struct V_58 * V_90 = V_91 -> V_92 ;
const char * V_353 = V_352 + 5 ;
unsigned int V_354 = strlen ( V_353 ) ;
int V_355 = 0 , V_356 = 0 ;
unsigned int V_67 = 0 , V_68 = 0 , V_48 = 0 ;
int V_357 = 0 ;
int V_65 ;
for ( V_65 = V_354 - 1 ; V_65 >= 0 ; V_65 -- ) {
switch ( V_353 [ V_65 ] ) {
case '-' :
V_354 = V_65 ;
if ( ! V_356 && ! V_357 ) {
V_48 = F_146 ( & V_353 [ V_65 + 1 ] , NULL , 0 ) ;
V_356 = 1 ;
} else
goto V_358;
break;
case 'x' :
if ( ! V_357 ) {
V_68 = F_146 ( & V_353 [ V_65 + 1 ] , NULL , 0 ) ;
V_357 = 1 ;
} else
goto V_358;
break;
case '0' ... '9' :
break;
default:
goto V_358;
}
}
if ( V_65 < 0 && V_357 ) {
V_67 = F_146 ( V_353 , NULL , 0 ) ;
V_355 = 1 ;
}
V_358:
if ( V_355 ) {
F_147 ( V_91 , L_27 , V_67 , V_68 ) ;
V_90 -> V_62 [ 0 ] . V_67 = V_67 ; V_90 -> V_62 [ 0 ] . V_68 = V_68 ;
}
if ( V_356 )
switch ( V_48 ) {
case 1 :
case 2 :
case 4 :
case 8 :
case 16 :
V_90 -> V_62 [ 0 ] . V_48 = V_48 ;
F_147 ( V_91 , L_28 , V_48 ) ;
break;
default:
F_76 ( V_91 , L_29 , V_48 ) ;
return - V_49 ;
}
return 0 ;
}
static int T_3 F_148 ( struct V_200 * V_91 , char * V_352 )
{
struct V_58 * V_90 = V_91 -> V_92 ;
struct V_57 * V_60 = & V_90 -> V_62 [ 0 ] ;
char V_359 [ 64 ] ;
V_359 [ 0 ] = '\0' ;
if ( ! strncmp ( V_352 , L_30 , 5 ) ) {
V_172 = F_149 ( V_352 + 5 , NULL ) ;
} else if ( ! strncmp ( V_352 , L_31 , 5 ) ) {
return F_145 ( V_91 , V_352 ) ;
} else if ( ! strncmp ( V_352 , L_32 , 9 ) ) {
V_60 -> V_56 = F_146 ( V_352 + 9 , NULL , 0 ) ;
sprintf ( V_359 , L_33 , V_60 -> V_56 ) ;
} else if ( ! strncmp ( V_352 , L_34 , 5 ) ) {
V_60 -> V_70 = F_146 ( V_352 + 5 , NULL , 0 ) ;
sprintf ( V_359 , L_35 , V_60 -> V_70 ) ;
} else if ( ! strncmp ( V_352 , L_36 , 6 ) ) {
V_60 -> V_71 = F_146 ( V_352 + 6 , NULL , 0 ) ;
sprintf ( V_359 , L_37 , V_60 -> V_71 ) ;
} else if ( ! strncmp ( V_352 , L_38 , 6 ) ) {
V_60 -> V_73 = F_146 ( V_352 + 6 , NULL , 0 ) ;
sprintf ( V_359 , L_39 , V_60 -> V_73 ) ;
} else if ( ! strncmp ( V_352 , L_40 , 6 ) ) {
V_60 -> V_74 = F_146 ( V_352 + 6 , NULL , 0 ) ;
sprintf ( V_359 , L_41 , V_60 -> V_74 ) ;
} else if ( ! strncmp ( V_352 , L_42 , 9 ) ) {
V_60 -> V_69 = F_146 ( V_352 + 9 , NULL , 0 ) ;
sprintf ( V_359 , L_43 , V_60 -> V_69 ) ;
} else if ( ! strncmp ( V_352 , L_44 , 9 ) ) {
V_60 -> V_72 = F_146 ( V_352 + 9 , NULL , 0 ) ;
sprintf ( V_359 , L_45 , V_60 -> V_72 ) ;
} else if ( ! strncmp ( V_352 , L_46 , 6 ) ) {
if ( F_146 ( V_352 + 6 , NULL , 0 ) == 0 ) {
sprintf ( V_359 , L_47 ) ;
V_60 -> V_75 &= ~ V_265 ;
} else {
sprintf ( V_359 , L_48 ) ;
V_60 -> V_75 |= V_265 ;
}
} else if ( ! strncmp ( V_352 , L_49 , 6 ) ) {
if ( F_146 ( V_352 + 6 , NULL , 0 ) == 0 ) {
sprintf ( V_359 , L_50 ) ;
V_60 -> V_75 &= ~ V_267 ;
} else {
sprintf ( V_359 , L_51 ) ;
V_60 -> V_75 |= V_267 ;
}
} else if ( ! strncmp ( V_352 , L_52 , 4 ) ) {
if ( F_146 ( V_352 + 4 , NULL , 0 ) == 0 ) {
sprintf ( V_359 , L_53 ) ;
V_90 -> V_51 &= ~ V_360 ;
} else {
sprintf ( V_359 , L_54 ) ;
V_90 -> V_51 |= V_360 ;
}
} else if ( ! strncmp ( V_352 , L_55 , 9 ) ) {
if ( F_146 ( V_352 + 9 , NULL , 0 ) == 0 ) {
sprintf ( V_359 , L_56 ) ;
V_90 -> V_51 = ( V_90 -> V_51 & ~ V_338 ) | V_361 ;
} else {
sprintf ( V_359 , L_57 ) ;
V_90 -> V_51 = ( V_90 -> V_51 & ~ V_338 ) | V_362 ;
}
} else if ( ! strncmp ( V_352 , L_58 , 12 ) ) {
if ( F_146 ( V_352 + 12 , NULL , 0 ) == 0 ) {
sprintf ( V_359 , L_59 ) ;
V_90 -> V_51 = ( V_90 -> V_51 & ~ V_340 ) | V_363 ;
} else {
sprintf ( V_359 , L_60 ) ;
V_90 -> V_51 = ( V_90 -> V_51 & ~ V_340 ) | V_364 ;
}
} else if ( ! strncmp ( V_352 , L_61 , 5 ) ) {
V_90 -> V_81 = ( V_90 -> V_81 & ~ V_325 ) | V_365 ;
} else if ( ! strncmp ( V_352 , L_62 , 4 ) ) {
V_90 -> V_81 = ( V_90 -> V_81 & ~ V_325 ) | V_366 ;
} else if ( ! strncmp ( V_352 , L_63 , 6 ) ) {
V_90 -> V_81 = ( V_90 -> V_81 & ~ V_330 ) | V_367 ;
} else if ( ! strncmp ( V_352 , L_64 , 7 ) ) {
V_90 -> V_81 = ( V_90 -> V_81 & ~ V_330 ) | V_368 ;
} else if ( ! strncmp ( V_352 , L_65 , 6 ) ) {
V_90 -> V_81 = ( V_90 -> V_81 & ~ V_108 ) | V_369 ;
} else if ( ! strncmp ( V_352 , L_66 , 4 ) ) {
V_90 -> V_81 = ( V_90 -> V_81 & ~ V_108 ) | V_277 ;
} else if ( ! strncmp ( V_352 , L_67 , 4 ) ) {
V_90 -> V_81 = ( V_90 -> V_81 & ~ V_334 ) | V_370 ;
} else if ( ! strncmp ( V_352 , L_68 , 4 ) ) {
V_90 -> V_81 = ( V_90 -> V_81 & ~ V_334 ) | V_371 ;
} else {
F_76 ( V_91 , L_69 , V_352 ) ;
return - V_49 ;
}
if ( V_359 [ 0 ] != '\0' )
F_147 ( V_91 , L_70 , V_359 ) ;
return 0 ;
}
static int T_3 F_150 ( struct V_200 * V_91 , char * V_372 )
{
char * V_352 ;
int V_37 ;
if ( ! V_372 || ! * V_372 )
return 0 ;
F_151 ( V_91 , L_71 , V_372 ? V_372 : L_72 ) ;
while ( ( V_352 = F_152 ( & V_372 , L_73 ) ) != NULL ) {
V_37 = F_148 ( V_91 , V_352 ) ;
if ( V_37 )
return V_37 ;
}
return 0 ;
}
static int T_8 F_153 ( void )
{
char * V_372 = NULL ;
if ( F_154 ( L_74 , & V_372 ) )
return - V_160 ;
if ( V_372 )
F_155 ( V_373 , V_372 , sizeof( V_373 ) ) ;
return 0 ;
}
static void T_3 F_156 ( struct V_200 * V_91 ,
struct V_58 * V_90 )
{
if ( V_90 -> V_321 )
return;
if ( V_90 -> V_81 & V_374 )
F_157 ( V_91 , L_75
L_76 ,
V_90 -> V_81 & V_374 ) ;
if ( V_90 -> V_51 & V_375 )
F_157 ( V_91 , L_77
L_76 ,
V_90 -> V_51 & V_375 ) ;
if ( V_90 -> V_81 & V_334 &&
( ( V_90 -> V_81 & V_330 ) != V_368 ||
( V_90 -> V_81 & V_108 ) != V_369 ||
( V_90 -> V_81 & V_325 ) != V_366 ) )
F_157 ( V_91 , L_78
L_79
L_80 ) ;
if ( ( V_90 -> V_81 & V_330 ) == V_367 &&
( V_90 -> V_81 & V_108 ) == V_277 )
F_157 ( V_91 , L_81 ) ;
if ( ( V_90 -> V_81 & V_330 ) == V_368 &&
( V_90 -> V_62 -> V_73 || V_90 -> V_62 -> V_74 ) )
F_157 ( V_91 , L_82
L_83 ) ;
}
static int T_3 F_158 ( struct V_376 * V_91 )
{
struct V_1 * V_2 ;
struct V_58 * V_90 ;
struct V_377 * V_378 ;
int V_295 , V_37 ;
F_151 ( & V_91 -> V_91 , L_84 ) ;
V_90 = V_91 -> V_91 . V_92 ;
V_37 = - V_190 ;
V_2 = NULL ;
if ( ! V_90 )
goto V_379;
V_37 = F_150 ( & V_91 -> V_91 , V_373 ) ;
if ( V_37 < 0 )
goto V_379;
F_156 ( & V_91 -> V_91 , V_90 ) ;
F_151 ( & V_91 -> V_91 , L_85 ,
V_90 -> V_62 -> V_67 ,
V_90 -> V_62 -> V_68 ,
V_90 -> V_62 -> V_48 ) ;
if ( V_90 -> V_62 -> V_67 == 0 ||
V_90 -> V_62 -> V_68 == 0 ||
V_90 -> V_62 -> V_48 == 0 ) {
F_76 ( & V_91 -> V_91 , L_86 ) ;
V_37 = - V_49 ;
goto V_379;
}
V_2 = F_138 ( & V_91 -> V_91 ) ;
if ( ! V_2 ) {
F_76 ( & V_91 -> V_91 , L_87 ) ;
V_37 = - V_190 ;
goto V_379;
}
if ( F_68 () && V_90 -> V_380 )
V_2 -> V_26 . V_39 . V_345 = V_381 ;
V_2 -> V_290 = V_90 -> V_382 ;
V_2 -> V_291 = V_90 -> V_383 ;
V_378 = F_159 ( V_91 , V_384 , 0 ) ;
if ( V_378 == NULL ) {
F_76 ( & V_91 -> V_91 , L_88 ) ;
V_37 = - V_160 ;
goto V_385;
}
V_378 = F_160 ( V_378 -> V_121 , F_161 ( V_378 ) , V_91 -> V_353 ) ;
if ( V_378 == NULL ) {
F_76 ( & V_91 -> V_91 , L_89 ) ;
V_37 = - V_386 ;
goto V_385;
}
V_2 -> V_4 = F_162 ( V_378 -> V_121 , F_161 ( V_378 ) ) ;
if ( V_2 -> V_4 == NULL ) {
F_76 ( & V_91 -> V_91 , L_90 ) ;
V_37 = - V_386 ;
goto V_387;
}
V_2 -> V_388 = F_56 ( sizeof( struct V_206 ) ) ;
V_2 -> V_97 = F_163 ( V_2 -> V_91 , V_2 -> V_388 ,
& V_2 -> V_211 , V_188 ) ;
if ( V_2 -> V_97 == NULL ) {
F_76 ( & V_91 -> V_91 , L_91 ) ;
V_37 = - V_190 ;
goto V_389;
}
V_37 = F_135 ( V_2 ) ;
if ( V_37 ) {
F_76 ( & V_91 -> V_91 , L_92 , V_37 ) ;
V_37 = - V_190 ;
goto V_390;
}
V_295 = F_164 ( V_91 , 0 ) ;
if ( V_295 < 0 ) {
F_76 ( & V_91 -> V_91 , L_93 ) ;
V_37 = - V_160 ;
goto V_391;
}
V_37 = F_165 ( V_295 , F_125 , 0 , L_94 , V_2 ) ;
if ( V_37 ) {
F_76 ( & V_91 -> V_91 , L_95 , V_37 ) ;
V_37 = - V_386 ;
goto V_391;
}
V_37 = F_110 ( V_2 ) ;
if ( V_37 ) {
F_76 ( & V_91 -> V_91 , L_96 ) ;
goto V_392;
}
V_37 = F_26 ( & V_2 -> V_26 . V_27 , & V_2 -> V_26 ) ;
if ( V_37 ) {
F_76 ( & V_91 -> V_91 , L_97 ) ;
goto V_392;
}
V_37 = F_29 ( & V_2 -> V_26 ) ;
if ( V_37 ) {
F_76 ( & V_91 -> V_91 , L_98 ) ;
goto V_392;
}
F_166 ( V_91 , V_2 ) ;
V_37 = F_75 ( & V_2 -> V_26 ) ;
if ( V_37 < 0 ) {
F_76 ( & V_91 -> V_91 ,
L_99 , V_37 ) ;
goto V_393;
}
F_74 ( V_2 ) ;
#ifdef F_27
V_2 -> V_313 . V_394 = F_130 ;
V_2 -> V_316 . V_394 = F_132 ;
F_167 ( & V_2 -> V_313 ,
V_395 ) ;
F_167 ( & V_2 -> V_316 ,
V_396 ) ;
#endif
F_127 ( V_2 , V_9 ) ;
return 0 ;
V_393:
if ( V_2 -> V_26 . V_99 . V_397 )
F_30 ( & V_2 -> V_26 . V_99 ) ;
V_392:
F_168 ( V_295 , V_2 ) ;
V_391:
F_80 ( V_2 -> V_171 , V_2 -> V_172 ) ;
V_390:
F_169 ( & V_91 -> V_91 , V_2 -> V_388 ,
V_2 -> V_97 , V_2 -> V_211 ) ;
V_389:
F_170 ( V_2 -> V_4 ) ;
V_387:
F_171 ( V_378 -> V_121 , F_161 ( V_378 ) ) ;
V_385:
F_172 ( V_2 -> V_197 ) ;
F_166 ( V_91 , NULL ) ;
F_141 ( V_2 ) ;
V_379:
return V_37 ;
}
static int T_4 F_173 ( struct V_376 * V_91 )
{
struct V_1 * V_2 = F_174 ( V_91 ) ;
struct V_377 * V_378 ;
int V_295 ;
struct V_23 * V_24 ;
if ( ! V_2 )
return 0 ;
V_24 = & V_2 -> V_26 ;
F_79 ( V_2 ) ;
F_77 ( V_24 ) ;
F_123 ( V_2 ) ;
if ( V_2 -> V_26 . V_99 . V_397 )
F_30 ( & V_2 -> V_26 . V_99 ) ;
V_295 = F_164 ( V_91 , 0 ) ;
F_168 ( V_295 , V_2 ) ;
F_80 ( V_2 -> V_171 , V_2 -> V_172 ) ;
F_175 ( & V_91 -> V_91 , V_2 -> V_388 ,
V_2 -> V_97 , V_2 -> V_211 ) ;
F_170 ( V_2 -> V_4 ) ;
V_378 = F_159 ( V_91 , V_384 , 0 ) ;
F_171 ( V_378 -> V_121 , F_161 ( V_378 ) ) ;
F_172 ( V_2 -> V_197 ) ;
F_141 ( V_2 ) ;
return 0 ;
}
static int T_8 F_176 ( void )
{
if ( F_153 () )
return - V_49 ;
return F_177 ( & V_398 ) ;
}
static void T_9 F_178 ( void )
{
F_179 ( & V_398 ) ;
}
