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
struct V_1 * V_2 = F_11 ( V_24 , struct V_1 , V_25 ) ;
T_1 V_5 ;
if ( V_18 >= V_2 -> V_26 )
return 1 ;
if ( V_2 -> V_25 . V_27 . V_28 ) {
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
F_12 ( T_1 V_18 , T_1 V_19 , T_1 V_20 , T_1 V_21 ,
T_1 V_22 , struct V_23 * V_24 )
{
struct V_1 * V_2 = F_11 ( V_24 , struct V_1 , V_25 ) ;
unsigned int V_5 ;
int V_37 = 1 ;
if ( V_2 -> V_38 ) {
V_19 = 0xffff - V_19 ;
V_20 = 0xffff - V_20 ;
V_21 = 0xffff - V_21 ;
}
if ( V_2 -> V_25 . V_27 . V_28 )
V_19 = V_20 = V_21 = ( 19595 * V_19 + 38470 * V_20 +
7471 * V_21 ) >> 16 ;
switch ( V_2 -> V_25 . V_39 . V_40 ) {
case V_41 :
if ( V_18 < 16 ) {
V_34 * V_42 = V_2 -> V_25 . V_43 ;
V_5 = F_9 ( V_19 , & V_2 -> V_25 . V_27 . V_19 ) ;
V_5 |= F_9 ( V_20 , & V_2 -> V_25 . V_27 . V_20 ) ;
V_5 |= F_9 ( V_21 , & V_2 -> V_25 . V_27 . V_21 ) ;
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
static inline int F_13 ( struct V_46 * V_27 )
{
return V_27 -> V_19 . V_16 + V_27 -> V_20 . V_16 +
V_27 -> V_21 . V_16 + V_27 -> V_47 . V_16 ;
}
static int F_14 ( struct V_46 * V_27 )
{
int V_48 = - V_49 ;
switch ( V_27 -> V_50 ) {
case 1 : V_48 = 0 ; break;
case 2 : V_48 = 1 ; break;
case 4 : V_48 = 2 ; break;
case 8 : V_48 = 3 ; break;
case 16 : V_48 = 4 ; break;
case 24 :
switch ( F_13 ( V_27 ) ) {
case 18 : V_48 = 6 ; break;
case 19 : V_48 = 8 ; break;
case 24 : V_48 = 9 ; break;
}
break;
case 32 :
switch ( F_13 ( V_27 ) ) {
case 18 : V_48 = 5 ; break;
case 19 : V_48 = 7 ; break;
case 25 : V_48 = 10 ; break;
}
break;
}
return V_48 ;
}
static T_2 F_15 ( struct V_46 * V_27 )
{
int V_48 = F_14 ( V_27 ) ;
T_2 V_51 ;
if ( V_48 < 0 )
return 0 ;
V_51 = F_16 ( V_48 ) ;
switch ( F_13 ( V_27 ) ) {
case 16 : V_51 |= V_27 -> V_47 . V_16 ? V_52 : 0 ; break;
case 18 : V_51 |= V_52 ; break;
case 24 : V_51 |= V_27 -> V_47 . V_16 ? V_53 : V_52 ;
break;
case 19 :
case 25 : V_51 |= V_54 ; break;
}
return V_51 ;
}
static void F_17 ( struct V_46 * V_27 , int V_55 )
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
F_18 ( V_27 , 5 , 5 , 5 , 1 ) :
F_18 ( V_27 , 5 , 6 , 5 , 0 ) ; break;
case 18 : F_18 ( V_27 , 6 , 6 , 6 , 0 ) ; break;
case 19 : F_18 ( V_27 , 6 , 6 , 6 , 1 ) ; break;
case 24 : V_27 -> V_47 . V_16 ?
F_18 ( V_27 , 8 , 8 , 7 , 1 ) :
F_18 ( V_27 , 8 , 8 , 8 , 0 ) ; break;
case 25 : F_18 ( V_27 , 8 , 8 , 8 , 1 ) ; break;
}
}
static unsigned int F_19 ( struct V_46 * V_27 )
{
return V_27 -> V_56 * 8 * 16 / V_27 -> V_50 ;
}
static struct V_57 * F_20 ( struct V_58 * V_59 ,
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
static void F_21 ( struct V_46 * V_27 ,
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
F_17 ( V_27 , V_60 -> V_55 ) ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_46 * V_27 )
{
int V_78 ;
V_27 -> V_67 = F_23 ( int , V_27 -> V_67 , V_79 ) ;
V_27 -> V_68 = F_23 ( int , V_27 -> V_68 , V_80 ) ;
if ( ! ( V_2 -> V_81 & V_82 ) ) {
F_24 ( V_27 -> V_69 , 1 , 64 ) ;
F_24 ( V_27 -> V_72 , 1 , 64 ) ;
F_24 ( V_27 -> V_70 , 1 , 255 ) ;
F_24 ( V_27 -> V_71 , 1 , 255 ) ;
F_24 ( V_27 -> V_73 , 1 , 255 ) ;
F_24 ( V_27 -> V_74 , 1 , 255 ) ;
}
V_78 = V_27 -> V_67 * V_27 -> V_50 / 8 ;
V_78 = F_25 ( V_78 , 4 ) ;
V_27 -> V_67 = V_78 * 8 / V_27 -> V_50 ;
V_27 -> V_83 = V_27 -> V_67 ;
if ( V_27 -> V_84 & V_85 )
V_27 -> V_86 = V_2 -> V_25 . V_39 . V_87 / V_78 ;
else
V_27 -> V_86 = F_26 ( V_27 -> V_86 , V_27 -> V_68 ) ;
if ( V_27 -> V_67 > V_88 || V_27 -> V_68 > V_89 )
return - V_49 ;
if ( V_27 -> V_68 > V_27 -> V_86 )
return - V_49 ;
return 0 ;
}
static int F_27 ( struct V_46 * V_27 , struct V_23 * V_24 )
{
struct V_1 * V_2 = F_11 ( V_24 , struct V_1 , V_25 ) ;
struct V_58 * V_90 = F_28 ( V_2 -> V_91 ) ;
int V_92 ;
if ( V_90 -> V_93 ) {
struct V_57 * V_60 ;
V_60 = F_20 ( V_90 , V_27 ) ;
if ( ! V_60 )
return - V_49 ;
F_21 ( V_27 , V_60 ) ;
}
V_92 = F_14 ( V_27 ) ;
if ( V_92 < 0 )
return V_92 ;
F_17 ( V_27 , F_13 ( V_27 ) ) ;
V_92 = F_22 ( V_2 , V_27 ) ;
if ( V_92 )
return V_92 ;
#ifdef F_29
F_30 ( L_1 ,
F_19 ( V_27 ) ) ;
#endif
return 0 ;
}
static int F_31 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_11 ( V_24 , struct V_1 , V_25 ) ;
struct V_46 * V_27 = & V_24 -> V_27 ;
if ( V_27 -> V_50 >= 16 )
V_2 -> V_25 . V_39 . V_40 = V_41 ;
else if ( ! V_2 -> V_94 )
V_2 -> V_25 . V_39 . V_40 = V_45 ;
else {
V_2 -> V_25 . V_39 . V_40 = V_44 ;
}
V_2 -> V_25 . V_39 . V_78 = V_27 -> V_83 *
V_27 -> V_50 / 8 ;
if ( V_27 -> V_50 >= 16 )
V_2 -> V_26 = 0 ;
else
V_2 -> V_26 = V_27 -> V_50 == 1 ?
4 : 1 << V_27 -> V_50 ;
V_2 -> V_29 = ( V_95 * ) & V_2 -> V_96 -> V_97 [ 0 ] ;
if ( V_2 -> V_25 . V_27 . V_50 >= 16 )
F_32 ( & V_2 -> V_25 . V_98 ) ;
else
F_33 ( & V_2 -> V_25 . V_98 , 1 << V_2 -> V_25 . V_27 . V_50 , 0 ) ;
F_34 ( V_27 , V_2 ) ;
return 0 ;
}
static int F_35 ( struct V_46 * V_27 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = F_11 ( V_24 , struct V_1 , V_25 ) ;
struct V_46 V_99 ;
int V_100 = V_101 + V_102 ;
if ( V_2 -> V_6 != V_9 )
return 0 ;
memcpy ( & V_99 , & V_2 -> V_25 . V_27 , sizeof( V_99 ) ) ;
V_99 . V_103 = V_27 -> V_103 ;
V_99 . V_104 = V_27 -> V_104 ;
V_99 . V_105 &= ~ V_106 ;
V_99 . V_105 |= V_27 -> V_105 & V_106 ;
F_36 ( V_2 , & V_99 , 1 ) ;
if ( V_2 -> V_81 & V_107 )
F_3 ( V_2 , V_108 , V_2 -> V_109 [ V_100 + 1 ] | 0x1 ) ;
F_3 ( V_2 , V_110 , V_2 -> V_109 [ V_100 ] | 0x1 ) ;
return 0 ;
}
static int F_37 ( int V_111 , struct V_23 * V_24 )
{
struct V_1 * V_2 = F_11 ( V_24 , struct V_1 , V_25 ) ;
int V_65 ;
switch ( V_111 ) {
case V_112 :
case V_113 :
case V_114 :
case V_115 :
if ( V_2 -> V_25 . V_39 . V_40 == V_45 ||
V_2 -> V_25 . V_39 . V_40 == V_44 )
for ( V_65 = 0 ; V_65 < V_2 -> V_26 ; V_65 ++ )
F_10 ( V_65 , 0 , 0 , 0 , 0 , V_24 ) ;
F_5 ( V_2 , V_11 ) ;
break;
case V_116 :
if ( V_2 -> V_25 . V_39 . V_40 == V_45 ||
V_2 -> V_25 . V_39 . V_40 == V_44 )
F_38 ( & V_2 -> V_25 . V_98 , V_24 ) ;
F_5 ( V_2 , V_9 ) ;
}
return 0 ;
}
static void F_39 ( struct V_117 * V_118 )
{
int V_119 = V_118 -> V_25 . V_39 . V_78 * V_118 -> V_25 . V_27 . V_86 ;
unsigned long V_120 = V_118 -> V_121 ;
F_40 ( V_118 -> V_2 , V_122 , V_123 , V_120 , V_119 ) ;
}
static void F_41 ( struct V_117 * V_118 )
{
int V_124 = F_1 ( V_118 -> V_2 , V_125 ) & V_126 ;
T_2 V_127 = V_118 -> V_2 -> V_109 [ V_122 ] | ( V_124 ? 0x1 : 0 ) ;
F_3 ( V_118 -> V_2 , V_124 ? V_108 : V_128 , V_127 ) ;
F_3 ( V_118 -> V_2 , V_129 , V_118 -> V_130 [ 1 ] ) ;
F_3 ( V_118 -> V_2 , V_125 , V_118 -> V_130 [ 0 ] | V_126 ) ;
}
static void F_42 ( struct V_117 * V_118 )
{
T_2 V_131 ;
if ( ! ( F_1 ( V_118 -> V_2 , V_125 ) & V_126 ) )
return;
V_131 = F_1 ( V_118 -> V_2 , V_132 ) ;
F_3 ( V_118 -> V_2 , V_125 , V_118 -> V_130 [ 0 ] & ~ V_126 ) ;
F_3 ( V_118 -> V_2 , V_133 , F_43 ( 1 ) ) ;
F_3 ( V_118 -> V_2 , V_132 , V_131 & ~ F_43 ( 1 ) ) ;
F_3 ( V_118 -> V_2 , V_108 , V_118 -> V_2 -> V_109 [ V_122 ] | 0x3 ) ;
if ( F_44 ( & V_118 -> V_134 , 1 * V_135 ) == 0 )
F_45 ( L_2 , V_136 ) ;
F_3 ( V_118 -> V_2 , V_132 , V_131 ) ;
}
static void F_46 ( struct V_117 * V_118 )
{
int V_119 , div = 1 , V_137 = F_47 ( V_118 -> V_25 . V_27 . V_138 ) ;
unsigned long V_120 [ 3 ] = { V_118 -> V_121 , 0 , 0 } ;
if ( V_137 == V_139 || V_137 == V_140 ) {
V_119 = V_118 -> V_25 . V_39 . V_78 * V_118 -> V_25 . V_27 . V_86 ;
F_40 ( V_118 -> V_2 , V_141 , - 1 , V_120 [ 0 ] , V_119 ) ;
} else {
V_119 = V_118 -> V_25 . V_27 . V_83 * V_118 -> V_25 . V_27 . V_86 ;
switch ( V_137 ) {
case V_142 : div = 1 ; break;
case V_143 : div = 2 ; break;
case V_144 : div = 4 ; break;
}
V_120 [ 1 ] = V_120 [ 0 ] + V_119 ;
V_120 [ 2 ] = V_120 [ 1 ] + V_119 / div ;
F_40 ( V_118 -> V_2 , V_141 , - 1 , V_120 [ 0 ] , V_119 ) ;
F_40 ( V_118 -> V_2 , V_145 , - 1 , V_120 [ 1 ] , V_119 / div ) ;
F_40 ( V_118 -> V_2 , V_146 , - 1 , V_120 [ 2 ] , V_119 / div ) ;
}
}
static void F_48 ( struct V_117 * V_118 )
{
int V_137 = F_47 ( V_118 -> V_25 . V_27 . V_138 ) ;
int V_124 = F_1 ( V_118 -> V_2 , V_147 ) & V_126 ;
T_2 V_148 = V_118 -> V_2 -> V_109 [ V_141 ] | ( V_124 ? 0x1 : 0 ) ;
T_2 V_149 = V_118 -> V_2 -> V_109 [ V_145 ] | ( V_124 ? 0x1 : 0 ) ;
T_2 V_150 = V_118 -> V_2 -> V_109 [ V_146 ] | ( V_124 ? 0x1 : 0 ) ;
if ( V_137 == V_139 || V_137 == V_140 )
F_3 ( V_118 -> V_2 , V_124 ? V_151 : V_152 , V_148 ) ;
else {
F_3 ( V_118 -> V_2 , V_124 ? V_151 : V_152 , V_148 ) ;
F_3 ( V_118 -> V_2 , V_124 ? V_153 : V_154 , V_149 ) ;
F_3 ( V_118 -> V_2 , V_124 ? V_155 : V_156 , V_150 ) ;
}
F_3 ( V_118 -> V_2 , V_157 , V_118 -> V_130 [ 1 ] ) ;
F_3 ( V_118 -> V_2 , V_147 , V_118 -> V_130 [ 0 ] | V_126 ) ;
}
static void F_49 ( struct V_117 * V_118 )
{
T_2 V_131 ;
if ( ! ( F_1 ( V_118 -> V_2 , V_147 ) & V_126 ) )
return;
V_131 = F_1 ( V_118 -> V_2 , V_132 ) ;
F_3 ( V_118 -> V_2 , V_147 , V_118 -> V_130 [ 0 ] & ~ V_126 ) ;
F_3 ( V_118 -> V_2 , V_133 , F_43 ( 2 ) ) ;
F_3 ( V_118 -> V_2 , V_132 , V_131 & ~ F_43 ( 2 ) ) ;
F_3 ( V_118 -> V_2 , V_151 , V_118 -> V_2 -> V_109 [ V_141 ] | 0x3 ) ;
F_3 ( V_118 -> V_2 , V_153 , V_118 -> V_2 -> V_109 [ V_145 ] | 0x3 ) ;
F_3 ( V_118 -> V_2 , V_155 , V_118 -> V_2 -> V_109 [ V_146 ] | 0x3 ) ;
if ( F_44 ( & V_118 -> V_134 , 1 * V_135 ) == 0 )
F_45 ( L_3 , V_136 ) ;
}
static int F_50 ( struct V_23 * V_24 , int V_158 )
{
struct V_117 * V_118 = F_11 ( V_24 , struct V_117 , V_25 ) ;
if ( V_158 == 0 )
return - V_159 ;
if ( V_118 -> V_160 ++ == 0 ) {
F_51 () ;
F_52 ( & V_118 -> V_2 -> V_25 , V_116 ) ;
F_53 () ;
}
return 0 ;
}
static int F_54 ( struct V_23 * V_24 , int V_158 )
{
struct V_117 * V_118 = F_11 ( V_24 , struct V_117 , V_25 ) ;
if ( V_118 -> V_160 == 1 ) {
V_118 -> V_161 -> V_162 ( V_118 ) ;
V_118 -> V_25 . V_27 . V_163 = - 1 ;
V_118 -> V_25 . V_27 . V_164 = - 1 ;
V_118 -> V_25 . V_27 . V_67 = V_118 -> V_25 . V_27 . V_83 = 0 ;
V_118 -> V_25 . V_27 . V_68 = V_118 -> V_25 . V_27 . V_86 = 0 ;
V_118 -> V_160 -- ;
}
return 0 ;
}
static int F_55 ( struct V_46 * V_27 ,
struct V_23 * V_24 )
{
struct V_117 * V_118 = F_11 ( V_24 , struct V_117 , V_25 ) ;
struct V_46 * V_165 = & V_118 -> V_2 -> V_25 . V_27 ;
int V_166 , V_167 , V_137 , V_48 ;
V_166 = F_56 ( V_27 -> V_138 ) ;
V_167 = F_57 ( V_27 -> V_138 ) ;
V_137 = F_47 ( V_27 -> V_138 ) ;
V_48 = F_14 ( V_27 ) ;
if ( V_48 < 0 )
return - V_49 ;
if ( V_118 -> V_168 == V_169 && V_137 != 0 )
return - V_49 ;
switch ( V_137 ) {
case V_139 :
V_48 = F_14 ( V_27 ) ;
if ( V_48 < 0 )
return - V_49 ;
F_17 ( V_27 , F_13 ( V_27 ) ) ;
break;
case V_140 : V_48 = 24 ; break;
case V_142 : V_48 = 8 ; break;
case V_143 : V_48 = 4 ; break;
case V_144 : V_48 = 2 ; break;
default:
return - V_49 ;
}
if ( ( V_166 * V_48 ) % 32 )
return - V_49 ;
V_27 -> V_67 = F_58 ( V_27 -> V_67 * V_48 , 32 ) / V_48 ;
if ( ( V_166 + V_27 -> V_67 > V_165 -> V_67 ) ||
( V_167 + V_27 -> V_68 > V_165 -> V_68 ) )
return - V_49 ;
V_27 -> V_83 = V_27 -> V_67 ;
V_27 -> V_86 = F_26 ( V_27 -> V_68 , V_27 -> V_86 ) ;
return 0 ;
}
static int F_59 ( struct V_117 * V_118 )
{
struct V_46 * V_27 = & V_118 -> V_25 . V_27 ;
int V_137 = F_47 ( V_27 -> V_138 ) ;
int V_119 , V_48 = 0 ;
switch ( V_137 ) {
case V_139 : V_48 = V_27 -> V_50 ; break;
case V_140 : V_48 = 24 ; break;
case V_142 : V_48 = 24 ; break;
case V_143 : V_48 = 16 ; break;
case V_144 : V_48 = 12 ; break;
}
V_118 -> V_25 . V_39 . V_78 = V_27 -> V_83 * V_48 / 8 ;
V_119 = F_60 ( V_118 -> V_25 . V_39 . V_78 * V_27 -> V_86 ) ;
if ( V_118 -> V_170 ) {
if ( V_118 -> V_171 >= V_119 )
return 0 ;
}
return - V_49 ;
}
static int F_61 ( struct V_23 * V_24 )
{
struct V_117 * V_118 = F_11 ( V_24 , struct V_117 , V_25 ) ;
struct V_46 * V_27 = & V_24 -> V_27 ;
int V_166 , V_167 , V_137 , V_48 , V_37 ;
V_37 = F_59 ( V_118 ) ;
if ( V_37 )
return V_37 ;
V_48 = F_14 ( V_27 ) ;
V_166 = F_56 ( V_27 -> V_138 ) ;
V_167 = F_57 ( V_27 -> V_138 ) ;
V_137 = F_47 ( V_27 -> V_138 ) ;
V_118 -> V_130 [ 0 ] = F_62 ( V_27 -> V_67 ) | F_63 ( V_27 -> V_68 ) |
F_64 ( V_48 ) ;
V_118 -> V_130 [ 1 ] = F_65 ( V_166 ) | F_66 ( V_167 ) ;
if ( V_118 -> V_168 == V_172 )
V_118 -> V_130 [ 1 ] |= F_67 ( V_137 ) ;
V_118 -> V_161 -> V_173 ( V_118 ) ;
V_118 -> V_161 -> V_174 ( V_118 ) ;
return 0 ;
}
static void F_68 ( struct V_1 * V_2 , struct V_117 * V_118 ,
int V_168 )
{
sprintf ( V_118 -> V_25 . V_39 . V_168 , L_4 , V_168 + 1 ) ;
V_118 -> V_25 . V_39 . type = V_175 ;
V_118 -> V_25 . V_39 . V_176 = 0 ;
V_118 -> V_25 . V_39 . V_177 = 1 ;
V_118 -> V_25 . V_27 . V_178 = V_179 ;
V_118 -> V_25 . V_27 . V_163 = - 1 ;
V_118 -> V_25 . V_27 . V_164 = - 1 ;
V_118 -> V_25 . V_27 . V_105 = V_180 ;
V_118 -> V_25 . V_181 = & V_182 ;
V_118 -> V_25 . V_7 = V_183 ;
V_118 -> V_25 . V_184 = - 1 ;
V_118 -> V_25 . V_43 = NULL ;
V_118 -> V_168 = V_168 ;
V_118 -> V_161 = & V_185 [ V_168 ] ;
V_118 -> V_160 = 0 ;
V_118 -> V_2 = V_2 ;
F_69 ( & V_118 -> V_134 ) ;
}
static inline int F_70 ( void )
{
if ( F_71 () || F_72 () )
return 1 ;
return 0 ;
}
static int F_73 ( struct V_1 * V_186 ,
struct V_117 * V_118 )
{
V_118 -> V_170 = F_74 ( F_60 ( V_186 -> V_171 ) ,
V_187 | V_188 ) ;
if ( V_118 -> V_170 == NULL )
return - V_189 ;
V_118 -> V_121 = F_75 ( V_118 -> V_170 ) ;
V_118 -> V_171 = F_60 ( V_186 -> V_171 ) ;
F_76 ( & V_118 -> V_25 . V_190 ) ;
V_118 -> V_25 . V_39 . V_191 = V_118 -> V_121 ;
V_118 -> V_25 . V_39 . V_87 = V_186 -> V_171 ;
F_77 ( & V_118 -> V_25 . V_190 ) ;
V_118 -> V_25 . V_192 = V_118 -> V_170 ;
return 0 ;
}
static void F_78 ( struct V_1 * V_2 )
{
int V_65 , V_37 ;
if ( ! F_70 () )
return;
for ( V_65 = 0 ; V_65 < 2 ; V_65 ++ ) {
struct V_117 * V_118 = & V_2 -> V_193 [ V_65 ] ;
F_68 ( V_2 , V_118 , V_65 ) ;
V_37 = F_79 ( & V_118 -> V_25 ) ;
if ( V_37 ) {
F_80 ( V_2 -> V_91 , L_5 , V_65 ) ;
continue;
}
V_37 = F_73 ( V_2 , V_118 ) ;
if ( V_37 ) {
F_80 ( V_2 -> V_91 ,
L_6 ,
V_65 ) ;
F_81 ( & V_118 -> V_25 ) ;
continue;
}
V_118 -> V_194 = 1 ;
}
F_3 ( V_2 , V_132 , ~ 0 ) ;
F_82 ( L_7 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
int V_65 ;
if ( ! F_70 () )
return;
for ( V_65 = 0 ; V_65 < 2 ; V_65 ++ ) {
struct V_117 * V_118 = & V_2 -> V_193 [ V_65 ] ;
if ( V_118 -> V_194 ) {
if ( V_118 -> V_170 )
F_84 ( V_118 -> V_170 ,
V_118 -> V_171 ) ;
F_81 ( & V_118 -> V_25 ) ;
}
}
}
static inline void F_78 ( struct V_1 * V_2 ) {}
static inline void F_83 ( struct V_1 * V_2 ) {}
static inline unsigned int F_85 ( struct V_1 * V_2 ,
unsigned int V_56 )
{
unsigned long long V_195 ;
V_195 = ( unsigned long long ) ( F_86 ( V_2 -> V_196 ) / 10000 ) ;
V_195 *= V_56 ;
F_87 ( V_195 , 100000000 * 2 ) ;
return ( unsigned int ) V_195 ;
}
static inline void F_88 ( struct V_1 * V_2 , unsigned int V_195 )
{
unsigned long V_197 ;
if ( ( V_195 == 0 ) || ( V_2 -> V_25 . V_27 . V_69 == 0 ) ) {
V_2 -> V_198 = 0 ;
return;
}
V_197 = F_86 ( V_2 -> V_196 ) / ( V_195 * V_2 -> V_25 . V_27 . V_69 ) ;
V_2 -> V_198 = V_197 ;
}
unsigned long F_89 ( struct V_199 * V_91 )
{
struct V_1 * V_2 = F_90 ( V_91 ) ;
if ( ! V_2 || ( V_2 -> V_6 != V_9 ) )
return 0 ;
return V_2 -> V_198 ;
}
static int F_40 ( struct V_1 * V_2 , int V_100 , int V_42 ,
unsigned long V_120 , T_3 V_119 )
{
struct V_200 * V_201 , * V_202 ;
unsigned int V_203 , V_204 ;
if ( V_100 < 0 || V_100 >= V_101 * 2 )
return - V_49 ;
V_201 = & V_2 -> V_96 -> V_201 [ V_100 ] ;
V_203 = F_91 ( struct V_205 , V_201 [ V_100 ] ) ;
V_201 -> V_206 = V_120 ;
V_201 -> V_207 = 0 ;
V_201 -> V_208 = V_119 ;
if ( V_42 < 0 || V_42 >= V_209 * 2 ) {
V_201 -> V_109 = V_2 -> V_210 + V_203 ;
V_2 -> V_109 [ V_100 ] = V_2 -> V_210 + V_203 ;
} else {
V_202 = & V_2 -> V_96 -> V_202 [ V_42 ] ;
V_204 = F_91 ( struct V_205 , V_202 [ V_42 ] ) ;
V_202 -> V_206 = V_2 -> V_210 + V_42 * V_211 ;
V_202 -> V_207 = 0 ;
if ( ( V_2 -> V_30 & V_31 ) == V_32 )
V_202 -> V_208 = V_2 -> V_26 * sizeof( V_95 ) ;
else
V_202 -> V_208 = V_2 -> V_26 * sizeof( V_34 ) ;
V_202 -> V_208 |= V_212 ;
V_202 -> V_109 = V_2 -> V_210 + V_203 ;
V_201 -> V_109 = V_2 -> V_210 + V_204 ;
V_2 -> V_109 [ V_100 ] = V_2 -> V_210 + V_203 ;
}
return 0 ;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_46 * V_27 ,
int V_213 )
{
struct V_214 * V_39 = & V_2 -> V_25 . V_39 ;
int V_215 , V_100 , V_42 , V_48 = V_27 -> V_50 ;
unsigned long V_17 ;
V_100 = V_102 + ( V_213 ? V_101 : 0 ) ;
V_42 = ( V_48 >= 16 ) ? V_123 : V_216 + ( V_213 ? V_209 : 0 ) ;
V_215 = V_39 -> V_78 * V_27 -> V_68 ;
V_17 = V_39 -> V_78 * V_27 -> V_104 + V_2 -> V_121 ;
if ( V_2 -> V_81 & V_107 ) {
V_215 = V_215 / 2 ;
F_40 ( V_2 , V_100 + 1 , V_123 , V_17 + V_215 , V_215 ) ;
}
F_40 ( V_2 , V_100 , V_42 , V_17 , V_215 ) ;
}
static int F_92 ( struct V_1 * V_2 )
{
struct V_200 * V_201 ;
unsigned long V_203 , V_217 ;
V_201 = & V_2 -> V_96 -> V_201 [ V_218 ] ;
V_203 = F_91 ( struct V_205 , V_201 [ V_218 ] ) ;
V_217 = F_91 ( struct V_205 , V_219 ) ;
V_201 -> V_109 = V_2 -> V_210 + V_203 ;
V_201 -> V_206 = V_2 -> V_210 + V_217 ;
V_201 -> V_207 = 0 ;
V_201 -> V_208 = V_2 -> V_220 * sizeof( V_221 ) ;
V_2 -> V_109 [ V_218 ] = V_201 -> V_109 ;
return 0 ;
}
int F_93 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_11 ( V_24 , struct V_1 , V_25 ) ;
T_2 V_222 ;
int V_37 = 0 ;
F_3 ( V_2 , V_223 , V_2 -> V_224 & ~ V_225 ) ;
while ( V_2 -> V_220 & 1 )
V_2 -> V_226 [ V_2 -> V_220 ++ ] = V_227 ;
V_2 -> V_226 [ V_2 -> V_220 ++ ] = V_228 ;
V_2 -> V_226 [ V_2 -> V_220 ++ ] = V_229 ;
F_92 ( V_2 ) ;
V_222 = F_1 ( V_2 , V_230 ) | V_231 | V_232 ;
F_3 ( V_2 , V_230 , V_222 ) ;
F_3 ( V_2 , V_233 , 0x0001 ) ;
F_3 ( V_2 , V_132 , F_94 ( 6 ) ) ;
F_3 ( V_2 , V_234 , V_2 -> V_235 ) ;
F_3 ( V_2 , V_236 , V_2 -> V_237 ) ;
F_3 ( V_2 , V_238 , V_2 -> V_239 ) ;
F_3 ( V_2 , V_240 , V_2 -> V_241 ) ;
F_3 ( V_2 , V_242 , V_2 -> V_109 [ 0 ] ) ;
F_3 ( V_2 , V_243 , V_2 -> V_109 [ 6 ] ) ;
F_3 ( V_2 , V_223 , V_2 -> V_224 | V_225 ) ;
if ( F_44 ( & V_2 -> V_244 , V_135 / 2 ) == 0 ) {
F_45 ( L_8 ,
V_136 ) ;
V_37 = - V_245 ;
}
V_222 = F_1 ( V_2 , V_230 ) & ~ ( V_231 | V_232 ) ;
F_3 ( V_2 , V_230 , V_222 ) ;
F_3 ( V_2 , V_223 , V_2 -> V_224 & ~ V_225 ) ;
F_3 ( V_2 , V_243 , 0 ) ;
V_2 -> V_220 = 0 ;
return V_37 ;
}
int F_95 ( struct V_23 * V_24 , V_221 * V_246 , int V_247 )
{
int V_65 ;
struct V_1 * V_2 = F_11 ( V_24 , struct V_1 , V_25 ) ;
for ( V_65 = 0 ; V_65 < V_247 ; V_65 ++ , V_246 ++ ) {
if ( ( * V_246 & 0xff00 ) == V_248 ) {
F_93 ( V_24 ) ;
F_96 ( * V_246 & 0xff ) ;
continue;
}
if ( V_2 -> V_220 == V_249 - 8 )
F_93 ( V_24 ) ;
V_2 -> V_226 [ V_2 -> V_220 ++ ] = * V_246 ;
}
return 0 ;
}
static unsigned int F_97 ( unsigned V_250 , unsigned long V_251 )
{
unsigned int V_252 = ( V_250 * ( V_251 / 1000000 ) / 1000 ) ;
return ( V_252 == 0 ) ? 1 : V_252 ;
}
static void F_98 ( struct V_1 * V_2 ,
struct V_46 * V_27 )
{
struct V_58 * V_90 = F_28 ( V_2 -> V_91 ) ;
struct V_57 * V_60 = & V_90 -> V_62 [ 0 ] ;
unsigned long V_253 = F_86 ( V_2 -> V_196 ) ;
unsigned V_254 , V_255 , V_256 , V_257 ;
V_254 = F_26 ( V_60 -> V_258 , V_60 -> V_259 ) ;
V_255 = F_26 ( V_60 -> V_260 , V_60 -> V_261 ) ;
V_256 = V_60 -> V_262 ;
V_257 = V_60 -> V_263 ;
V_2 -> V_235 =
F_99 ( V_27 -> V_67 ) |
F_100 ( F_97 ( V_254 , V_253 ) ) |
F_101 ( F_97 ( V_255 , V_253 ) ) |
F_102 ( F_97 ( V_256 , V_253 ) ) ;
V_2 -> V_237 = F_103 ( V_27 -> V_68 ) ;
V_2 -> V_239 = V_2 -> V_51 | F_104 ( F_97 ( V_257 , V_253 ) ) ;
V_2 -> V_239 |= ( V_27 -> V_75 & V_264 ) ? V_265 : 0 ;
V_2 -> V_239 |= ( V_27 -> V_75 & V_266 ) ? V_267 : 0 ;
V_2 -> V_268 = 1 ;
}
static int F_105 ( void * V_269 )
{
struct V_1 * V_2 = V_269 ;
struct V_58 * V_90 = F_28 ( V_2 -> V_91 ) ;
if ( ! V_90 -> V_270 ) {
F_106 ( L_9 ,
V_136 ) ;
return - V_49 ;
}
V_90 = F_28 ( V_2 -> V_91 ) ;
F_30 ( L_10 , V_136 ) ;
F_107 () ;
while ( ! F_108 () ) {
if ( F_109 () )
continue;
F_76 ( & V_2 -> V_271 ) ;
if ( V_2 -> V_6 == V_9 ) {
V_90 -> V_270 ( & V_2 -> V_25 ) ;
F_110 ( & V_2 -> V_272 ) ;
}
F_77 ( & V_2 -> V_271 ) ;
F_111 ( V_273 ) ;
F_112 ( 30 * V_135 / 1000 ) ;
}
F_30 ( L_11 , V_136 ) ;
return 0 ;
}
static int F_113 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_81 & V_82 ) )
return 0 ;
V_2 -> V_226 = ( V_221 * ) V_2 -> V_96 -> V_219 ;
V_2 -> V_220 = 0 ;
F_69 ( & V_2 -> V_244 ) ;
F_69 ( & V_2 -> V_272 ) ;
V_2 -> V_274 = F_114 ( F_105 , V_2 ,
L_12 ) ;
if ( F_115 ( V_2 -> V_274 ) ) {
F_106 ( L_13 , V_136 ) ;
return F_116 ( V_2 -> V_274 ) ;
}
return 0 ;
}
static inline int F_113 ( struct V_1 * V_2 ) { return 0 ; }
static void F_117 ( struct V_1 * V_2 ,
struct V_46 * V_27 )
{
unsigned int V_275 , V_195 = F_85 ( V_2 , V_27 -> V_56 ) ;
V_2 -> V_235 =
F_99 ( V_27 -> V_67 ) +
F_102 ( V_27 -> V_69 ) +
F_100 ( V_27 -> V_70 ) +
F_101 ( V_27 -> V_71 ) ;
V_275 = V_27 -> V_68 ;
if ( ( V_2 -> V_81 & V_107 ) == V_276 )
V_275 /= 2 ;
V_2 -> V_237 =
F_103 ( V_275 ) +
F_118 ( V_27 -> V_72 ) +
F_119 ( V_27 -> V_73 ) +
F_120 ( V_27 -> V_74 ) ;
V_2 -> V_239 = V_2 -> V_51 |
( V_27 -> V_75 & V_264 ?
V_277 : V_278 ) |
( V_27 -> V_75 & V_266 ?
V_279 : V_280 ) ;
if ( V_195 ) {
V_2 -> V_239 |= F_104 ( V_195 ) ;
F_88 ( V_2 , V_195 ) ;
}
}
static int F_34 ( struct V_46 * V_27 ,
struct V_1 * V_2 )
{
T_4 V_7 ;
F_6 ( V_7 ) ;
#ifdef F_121
if ( V_2 -> V_81 & V_82 )
F_98 ( V_2 , V_27 ) ;
else
#endif
F_117 ( V_2 , V_27 ) ;
F_36 ( V_2 , V_27 , 0 ) ;
V_2 -> V_224 = V_2 -> V_81 |
( V_281 | V_282 | V_283 | V_284 |
V_285 | V_286 | V_287 ) ;
V_2 -> V_239 |= F_15 ( V_27 ) ;
V_2 -> V_241 = F_1 ( V_2 , V_240 ) & ~ V_31 ;
V_2 -> V_241 |= ( V_2 -> V_30 & V_31 ) ;
F_8 ( V_7 ) ;
if ( ( F_1 ( V_2 , V_223 ) != V_2 -> V_224 ) ||
( F_1 ( V_2 , V_234 ) != V_2 -> V_235 ) ||
( F_1 ( V_2 , V_236 ) != V_2 -> V_237 ) ||
( F_1 ( V_2 , V_238 ) != V_2 -> V_239 ) ||
( F_1 ( V_2 , V_240 ) != V_2 -> V_241 ) ||
( F_1 ( V_2 , V_242 ) != V_2 -> V_109 [ 0 ] ) ||
( ( V_2 -> V_81 & V_107 ) &&
( F_1 ( V_2 , V_128 ) != V_2 -> V_109 [ 1 ] ) ) )
F_5 ( V_2 , V_10 ) ;
return 0 ;
}
static inline void F_122 ( struct V_1 * V_2 , int V_288 )
{
F_30 ( L_14 , V_288 ? L_15 : L_16 ) ;
if ( V_2 -> V_289 )
V_2 -> V_289 ( V_288 ) ;
}
static inline void F_123 ( struct V_1 * V_2 , int V_288 )
{
F_30 ( L_17 , V_288 ? L_15 : L_16 ) ;
if ( V_2 -> V_290 )
V_2 -> V_290 ( V_288 , & V_2 -> V_25 . V_27 ) ;
}
static void F_124 ( struct V_1 * V_2 )
{
F_30 ( L_18 ) ;
F_30 ( L_19 , ( unsigned int ) V_2 -> V_109 [ 0 ] ) ;
F_30 ( L_20 , ( unsigned int ) V_2 -> V_109 [ 1 ] ) ;
F_30 ( L_21 , ( unsigned int ) V_2 -> V_224 ) ;
F_30 ( L_22 , ( unsigned int ) V_2 -> V_235 ) ;
F_30 ( L_23 , ( unsigned int ) V_2 -> V_237 ) ;
F_30 ( L_24 , ( unsigned int ) V_2 -> V_239 ) ;
F_125 ( V_2 -> V_196 ) ;
if ( V_2 -> V_81 & V_82 )
return;
F_3 ( V_2 , V_240 , V_2 -> V_241 ) ;
F_3 ( V_2 , V_238 , V_2 -> V_239 ) ;
F_3 ( V_2 , V_236 , V_2 -> V_237 ) ;
F_3 ( V_2 , V_234 , V_2 -> V_235 ) ;
F_3 ( V_2 , V_223 , V_2 -> V_224 & ~ V_225 ) ;
F_3 ( V_2 , V_242 , V_2 -> V_109 [ 0 ] ) ;
if ( V_2 -> V_81 & V_107 )
F_3 ( V_2 , V_128 , V_2 -> V_109 [ 1 ] ) ;
F_3 ( V_2 , V_223 , V_2 -> V_224 | V_225 ) ;
}
static void F_126 ( struct V_1 * V_2 )
{
T_2 V_81 ;
#ifdef F_121
if ( V_2 -> V_81 & V_82 ) {
F_44 ( & V_2 -> V_272 ,
200 * V_135 / 1000 ) ;
return;
}
#endif
F_3 ( V_2 , V_291 , 0xffffffff ) ;
V_81 = F_1 ( V_2 , V_223 ) & ~ V_281 ;
F_3 ( V_2 , V_223 , V_81 ) ;
F_3 ( V_2 , V_223 , V_81 | V_292 ) ;
F_44 ( & V_2 -> V_293 , 200 * V_135 / 1000 ) ;
F_127 ( V_2 -> V_196 ) ;
}
static T_5 F_128 ( int V_294 , void * V_295 )
{
struct V_1 * V_2 = V_295 ;
unsigned int V_81 , V_296 ;
V_296 = F_1 ( V_2 , V_291 ) ;
if ( V_296 & V_297 ) {
V_81 = F_1 ( V_2 , V_223 ) ;
F_3 ( V_2 , V_223 , V_81 | V_281 ) ;
F_110 ( & V_2 -> V_293 ) ;
}
#ifdef F_121
if ( V_296 & V_298 )
F_110 ( & V_2 -> V_244 ) ;
#endif
F_3 ( V_2 , V_291 , V_296 ) ;
#ifdef F_129
{
unsigned int V_299 = F_1 ( V_2 , V_133 ) ;
if ( V_299 & F_43 ( 1 ) )
F_110 ( & V_2 -> V_193 [ 0 ] . V_134 ) ;
if ( V_299 & F_43 ( 2 ) )
F_110 ( & V_2 -> V_193 [ 1 ] . V_134 ) ;
F_3 ( V_2 , V_133 , V_299 ) ;
}
#endif
return V_300 ;
}
static void F_130 ( struct V_1 * V_2 , T_1 V_6 )
{
T_1 V_301 ;
F_76 ( & V_2 -> V_271 ) ;
V_301 = V_2 -> V_6 ;
if ( V_301 == V_302 && V_6 == V_10 )
V_6 = V_9 ;
switch ( V_6 ) {
case V_303 :
if ( V_301 != V_11 && V_301 != V_304 ) {
V_2 -> V_6 = V_6 ;
F_126 ( V_2 ) ;
}
break;
case V_304 :
case V_11 :
if ( V_301 != V_11 ) {
V_2 -> V_6 = V_6 ;
F_122 ( V_2 , 0 ) ;
F_123 ( V_2 , 0 ) ;
if ( V_301 != V_303 )
F_126 ( V_2 ) ;
}
break;
case V_305 :
if ( V_301 == V_303 ) {
V_2 -> V_6 = V_9 ;
F_124 ( V_2 ) ;
}
break;
case V_10 :
if ( V_301 == V_9 ) {
F_123 ( V_2 , 0 ) ;
F_126 ( V_2 ) ;
F_124 ( V_2 ) ;
F_123 ( V_2 , 1 ) ;
}
break;
case V_306 :
if ( V_301 != V_304 )
break;
case V_9 :
if ( V_301 != V_9 ) {
V_2 -> V_6 = V_9 ;
F_124 ( V_2 ) ;
F_123 ( V_2 , 1 ) ;
F_122 ( V_2 , 1 ) ;
}
break;
}
F_77 ( & V_2 -> V_271 ) ;
}
static void F_131 ( struct V_307 * V_308 )
{
struct V_1 * V_2 =
F_11 ( V_308 , struct V_1 , V_12 ) ;
T_1 V_6 = F_132 ( & V_2 -> V_8 , - 1 ) ;
F_130 ( V_2 , V_6 ) ;
}
static int
F_133 ( struct V_309 * V_310 , unsigned long V_5 , void * V_311 )
{
struct V_1 * V_2 = F_134 ( V_310 , V_312 ) ;
T_1 V_195 ;
switch ( V_5 ) {
case V_313 :
#ifdef F_129
if ( ! ( V_2 -> V_193 [ 0 ] . V_160 || V_2 -> V_193 [ 1 ] . V_160 ) )
#endif
F_130 ( V_2 , V_303 ) ;
break;
case V_314 :
V_195 = F_85 ( V_2 , V_2 -> V_25 . V_27 . V_56 ) ;
F_88 ( V_2 , V_195 ) ;
V_2 -> V_239 = ( V_2 -> V_239 & ~ 0xff ) |
F_104 ( V_195 ) ;
F_130 ( V_2 , V_305 ) ;
break;
}
return 0 ;
}
static int
F_135 ( struct V_309 * V_310 , unsigned long V_5 , void * V_311 )
{
struct V_1 * V_2 = F_134 ( V_310 , V_315 ) ;
struct V_46 * V_27 = & V_2 -> V_25 . V_27 ;
struct V_316 * V_317 = V_311 ;
switch ( V_5 ) {
case V_318 :
case V_319 :
F_30 ( L_25
L_26 , F_19 ( V_27 ) ,
V_317 -> F_26 ) ;
break;
}
return 0 ;
}
static int F_136 ( struct V_199 * V_91 )
{
struct V_1 * V_2 = F_90 ( V_91 ) ;
F_130 ( V_2 , V_304 ) ;
return 0 ;
}
static int F_137 ( struct V_199 * V_91 )
{
struct V_1 * V_2 = F_90 ( V_91 ) ;
F_130 ( V_2 , V_306 ) ;
return 0 ;
}
static int F_138 ( struct V_1 * V_2 )
{
int V_119 = F_60 ( V_2 -> V_171 ) ;
V_2 -> V_170 = F_74 ( V_119 , V_187 | V_188 ) ;
if ( V_2 -> V_170 == NULL )
return - V_189 ;
V_2 -> V_121 = F_75 ( V_2 -> V_170 ) ;
V_2 -> V_171 = V_119 ;
V_2 -> V_25 . V_39 . V_191 = V_2 -> V_121 ;
V_2 -> V_25 . V_39 . V_87 = V_2 -> V_171 ;
V_2 -> V_25 . V_192 = V_2 -> V_170 ;
return V_2 -> V_170 ? 0 : - V_189 ;
}
static void F_139 ( struct V_1 * V_2 ,
struct V_58 * V_90 )
{
unsigned int V_320 = V_90 -> V_320 ;
struct V_57 * V_321 ;
int V_65 ;
V_2 -> V_38 = V_90 -> V_38 ;
V_2 -> V_94 = V_90 -> V_94 ;
V_2 -> V_30 = V_90 -> V_30 ;
switch ( V_320 & V_322 ) {
case V_323 :
V_2 -> V_81 = V_324 ;
break;
case V_325 :
V_2 -> V_81 = V_324 | V_107 ;
break;
case V_326 :
V_2 -> V_81 = 0 ;
break;
case V_327 :
V_2 -> V_81 = V_107 ;
break;
case V_328 :
V_2 -> V_81 = V_329 ;
break;
case V_330 :
V_2 -> V_81 = V_82 | V_329 ;
break;
default:
V_2 -> V_81 = V_90 -> V_81 ;
V_2 -> V_51 = V_90 -> V_51 ;
goto V_331;
}
if ( V_320 == V_332 )
V_2 -> V_81 |= V_333 ;
V_2 -> V_81 |= ( V_320 & V_334 ) ? V_335 : 0 ;
V_2 -> V_51 = F_140 ( ( V_90 -> V_320 >> 10 ) & 0xff ) ;
V_2 -> V_51 |= ( V_320 & V_336 ) ? V_337 : 0 ;
V_2 -> V_51 |= ( V_320 & V_338 ) ? V_339 : 0 ;
V_331:
F_21 ( & V_2 -> V_25 . V_27 , & V_90 -> V_62 [ 0 ] ) ;
for ( V_65 = 0 , V_321 = & V_90 -> V_62 [ 0 ] ; V_65 < V_90 -> V_66 ; V_65 ++ , V_321 ++ )
V_2 -> V_171 = F_23 ( T_3 , V_2 -> V_171 ,
V_321 -> V_67 * V_321 -> V_68 * V_321 -> V_48 / 8 ) ;
if ( V_90 -> V_171 > V_2 -> V_171 )
V_2 -> V_171 = V_90 -> V_171 ;
if ( V_171 > V_2 -> V_171 )
V_2 -> V_171 = V_171 ;
}
static struct V_1 * F_141 ( struct V_199 * V_91 )
{
struct V_1 * V_2 ;
void * V_340 ;
struct V_58 * V_90 = F_28 ( V_91 ) ;
V_2 = F_142 ( sizeof( struct V_1 ) + sizeof( V_34 ) * 16 , V_187 ) ;
if ( ! V_2 )
return NULL ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_91 = V_91 ;
V_2 -> V_196 = F_143 ( V_91 , NULL ) ;
if ( F_115 ( V_2 -> V_196 ) ) {
F_144 ( V_2 ) ;
return NULL ;
}
strcpy ( V_2 -> V_25 . V_39 . V_168 , V_341 ) ;
V_2 -> V_25 . V_39 . type = V_175 ;
V_2 -> V_25 . V_39 . V_342 = 0 ;
V_2 -> V_25 . V_39 . V_176 = 0 ;
V_2 -> V_25 . V_39 . V_177 = 1 ;
V_2 -> V_25 . V_39 . V_343 = 0 ;
V_2 -> V_25 . V_39 . V_344 = V_345 ;
V_2 -> V_25 . V_27 . V_138 = 0 ;
V_2 -> V_25 . V_27 . V_178 = V_179 ;
V_2 -> V_25 . V_27 . V_163 = - 1 ;
V_2 -> V_25 . V_27 . V_164 = - 1 ;
V_2 -> V_25 . V_27 . V_84 = V_85 ;
V_2 -> V_25 . V_27 . V_105 = V_180 ;
V_2 -> V_25 . V_181 = & V_346 ;
V_2 -> V_25 . V_7 = V_347 ;
V_2 -> V_25 . V_184 = - 1 ;
V_340 = V_2 ;
V_340 = V_340 + sizeof( struct V_1 ) ;
V_2 -> V_25 . V_43 = V_340 ;
V_2 -> V_6 = V_302 ;
V_2 -> V_8 = ( V_348 ) - 1 ;
F_139 ( V_2 , V_90 ) ;
#ifdef F_129
if ( F_70 () )
V_2 -> V_81 |= V_349 ;
#endif
F_145 ( & V_2 -> V_350 ) ;
F_146 ( & V_2 -> V_12 , F_131 ) ;
F_147 ( & V_2 -> V_271 ) ;
F_69 ( & V_2 -> V_293 ) ;
return V_2 ;
}
static int F_148 ( struct V_199 * V_91 , const char * V_351 )
{
struct V_58 * V_90 = F_28 ( V_91 ) ;
const char * V_352 = V_351 + 5 ;
unsigned int V_353 = strlen ( V_352 ) ;
int V_354 = 0 , V_355 = 0 ;
unsigned int V_67 = 0 , V_68 = 0 , V_48 = 0 ;
int V_356 = 0 ;
int V_65 ;
for ( V_65 = V_353 - 1 ; V_65 >= 0 ; V_65 -- ) {
switch ( V_352 [ V_65 ] ) {
case '-' :
V_353 = V_65 ;
if ( ! V_355 && ! V_356 ) {
V_48 = F_149 ( & V_352 [ V_65 + 1 ] , NULL , 0 ) ;
V_355 = 1 ;
} else
goto V_357;
break;
case 'x' :
if ( ! V_356 ) {
V_68 = F_149 ( & V_352 [ V_65 + 1 ] , NULL , 0 ) ;
V_356 = 1 ;
} else
goto V_357;
break;
case '0' ... '9' :
break;
default:
goto V_357;
}
}
if ( V_65 < 0 && V_356 ) {
V_67 = F_149 ( V_352 , NULL , 0 ) ;
V_354 = 1 ;
}
V_357:
if ( V_354 ) {
F_150 ( V_91 , L_27 , V_67 , V_68 ) ;
V_90 -> V_62 [ 0 ] . V_67 = V_67 ; V_90 -> V_62 [ 0 ] . V_68 = V_68 ;
}
if ( V_355 )
switch ( V_48 ) {
case 1 :
case 2 :
case 4 :
case 8 :
case 16 :
V_90 -> V_62 [ 0 ] . V_48 = V_48 ;
F_150 ( V_91 , L_28 , V_48 ) ;
break;
default:
F_80 ( V_91 , L_29 , V_48 ) ;
return - V_49 ;
}
return 0 ;
}
static int F_151 ( struct V_199 * V_91 , char * V_351 )
{
struct V_58 * V_90 = F_28 ( V_91 ) ;
struct V_57 * V_60 = & V_90 -> V_62 [ 0 ] ;
char V_358 [ 64 ] ;
V_358 [ 0 ] = '\0' ;
if ( ! strncmp ( V_351 , L_30 , 5 ) ) {
V_171 = F_152 ( V_351 + 5 , NULL ) ;
} else if ( ! strncmp ( V_351 , L_31 , 5 ) ) {
return F_148 ( V_91 , V_351 ) ;
} else if ( ! strncmp ( V_351 , L_32 , 9 ) ) {
V_60 -> V_56 = F_149 ( V_351 + 9 , NULL , 0 ) ;
sprintf ( V_358 , L_33 , V_60 -> V_56 ) ;
} else if ( ! strncmp ( V_351 , L_34 , 5 ) ) {
V_60 -> V_70 = F_149 ( V_351 + 5 , NULL , 0 ) ;
sprintf ( V_358 , L_35 , V_60 -> V_70 ) ;
} else if ( ! strncmp ( V_351 , L_36 , 6 ) ) {
V_60 -> V_71 = F_149 ( V_351 + 6 , NULL , 0 ) ;
sprintf ( V_358 , L_37 , V_60 -> V_71 ) ;
} else if ( ! strncmp ( V_351 , L_38 , 6 ) ) {
V_60 -> V_73 = F_149 ( V_351 + 6 , NULL , 0 ) ;
sprintf ( V_358 , L_39 , V_60 -> V_73 ) ;
} else if ( ! strncmp ( V_351 , L_40 , 6 ) ) {
V_60 -> V_74 = F_149 ( V_351 + 6 , NULL , 0 ) ;
sprintf ( V_358 , L_41 , V_60 -> V_74 ) ;
} else if ( ! strncmp ( V_351 , L_42 , 9 ) ) {
V_60 -> V_69 = F_149 ( V_351 + 9 , NULL , 0 ) ;
sprintf ( V_358 , L_43 , V_60 -> V_69 ) ;
} else if ( ! strncmp ( V_351 , L_44 , 9 ) ) {
V_60 -> V_72 = F_149 ( V_351 + 9 , NULL , 0 ) ;
sprintf ( V_358 , L_45 , V_60 -> V_72 ) ;
} else if ( ! strncmp ( V_351 , L_46 , 6 ) ) {
if ( F_149 ( V_351 + 6 , NULL , 0 ) == 0 ) {
sprintf ( V_358 , L_47 ) ;
V_60 -> V_75 &= ~ V_264 ;
} else {
sprintf ( V_358 , L_48 ) ;
V_60 -> V_75 |= V_264 ;
}
} else if ( ! strncmp ( V_351 , L_49 , 6 ) ) {
if ( F_149 ( V_351 + 6 , NULL , 0 ) == 0 ) {
sprintf ( V_358 , L_50 ) ;
V_60 -> V_75 &= ~ V_266 ;
} else {
sprintf ( V_358 , L_51 ) ;
V_60 -> V_75 |= V_266 ;
}
} else if ( ! strncmp ( V_351 , L_52 , 4 ) ) {
if ( F_149 ( V_351 + 4 , NULL , 0 ) == 0 ) {
sprintf ( V_358 , L_53 ) ;
V_90 -> V_51 &= ~ V_359 ;
} else {
sprintf ( V_358 , L_54 ) ;
V_90 -> V_51 |= V_359 ;
}
} else if ( ! strncmp ( V_351 , L_55 , 9 ) ) {
if ( F_149 ( V_351 + 9 , NULL , 0 ) == 0 ) {
sprintf ( V_358 , L_56 ) ;
V_90 -> V_51 = ( V_90 -> V_51 & ~ V_337 ) | V_360 ;
} else {
sprintf ( V_358 , L_57 ) ;
V_90 -> V_51 = ( V_90 -> V_51 & ~ V_337 ) | V_361 ;
}
} else if ( ! strncmp ( V_351 , L_58 , 12 ) ) {
if ( F_149 ( V_351 + 12 , NULL , 0 ) == 0 ) {
sprintf ( V_358 , L_59 ) ;
V_90 -> V_51 = ( V_90 -> V_51 & ~ V_339 ) | V_362 ;
} else {
sprintf ( V_358 , L_60 ) ;
V_90 -> V_51 = ( V_90 -> V_51 & ~ V_339 ) | V_363 ;
}
} else if ( ! strncmp ( V_351 , L_61 , 5 ) ) {
V_90 -> V_81 = ( V_90 -> V_81 & ~ V_324 ) | V_364 ;
} else if ( ! strncmp ( V_351 , L_62 , 4 ) ) {
V_90 -> V_81 = ( V_90 -> V_81 & ~ V_324 ) | V_365 ;
} else if ( ! strncmp ( V_351 , L_63 , 6 ) ) {
V_90 -> V_81 = ( V_90 -> V_81 & ~ V_329 ) | V_366 ;
} else if ( ! strncmp ( V_351 , L_64 , 7 ) ) {
V_90 -> V_81 = ( V_90 -> V_81 & ~ V_329 ) | V_367 ;
} else if ( ! strncmp ( V_351 , L_65 , 6 ) ) {
V_90 -> V_81 = ( V_90 -> V_81 & ~ V_107 ) | V_368 ;
} else if ( ! strncmp ( V_351 , L_66 , 4 ) ) {
V_90 -> V_81 = ( V_90 -> V_81 & ~ V_107 ) | V_276 ;
} else if ( ! strncmp ( V_351 , L_67 , 4 ) ) {
V_90 -> V_81 = ( V_90 -> V_81 & ~ V_333 ) | V_369 ;
} else if ( ! strncmp ( V_351 , L_68 , 4 ) ) {
V_90 -> V_81 = ( V_90 -> V_81 & ~ V_333 ) | V_370 ;
} else {
F_80 ( V_91 , L_69 , V_351 ) ;
return - V_49 ;
}
if ( V_358 [ 0 ] != '\0' )
F_150 ( V_91 , L_70 , V_358 ) ;
return 0 ;
}
static int F_153 ( struct V_199 * V_91 , char * V_371 )
{
char * V_351 ;
int V_37 ;
if ( ! V_371 || ! * V_371 )
return 0 ;
F_154 ( V_91 , L_71 , V_371 ? V_371 : L_72 ) ;
while ( ( V_351 = F_155 ( & V_371 , L_73 ) ) != NULL ) {
V_37 = F_151 ( V_91 , V_351 ) ;
if ( V_37 )
return V_37 ;
}
return 0 ;
}
static int T_6 F_156 ( void )
{
char * V_371 = NULL ;
if ( F_157 ( L_74 , & V_371 ) )
return - V_159 ;
if ( V_371 )
F_158 ( V_372 , V_371 , sizeof( V_372 ) ) ;
return 0 ;
}
static void F_159 ( struct V_199 * V_91 , struct V_58 * V_90 )
{
if ( V_90 -> V_320 )
return;
if ( V_90 -> V_81 & V_373 )
F_160 ( V_91 , L_75
L_76 ,
V_90 -> V_81 & V_373 ) ;
if ( V_90 -> V_51 & V_374 )
F_160 ( V_91 , L_77
L_76 ,
V_90 -> V_51 & V_374 ) ;
if ( V_90 -> V_81 & V_333 &&
( ( V_90 -> V_81 & V_329 ) != V_367 ||
( V_90 -> V_81 & V_107 ) != V_368 ||
( V_90 -> V_81 & V_324 ) != V_365 ) )
F_160 ( V_91 , L_78
L_79
L_80 ) ;
if ( ( V_90 -> V_81 & V_329 ) == V_366 &&
( V_90 -> V_81 & V_107 ) == V_276 )
F_160 ( V_91 , L_81 ) ;
if ( ( V_90 -> V_81 & V_329 ) == V_367 &&
( V_90 -> V_62 -> V_73 || V_90 -> V_62 -> V_74 ) )
F_160 ( V_91 , L_82
L_83 ) ;
}
static int F_161 ( struct V_375 * V_91 )
{
struct V_1 * V_2 ;
struct V_58 * V_90 ;
struct V_376 * V_377 ;
int V_294 , V_37 ;
F_154 ( & V_91 -> V_91 , L_84 ) ;
V_90 = F_28 ( & V_91 -> V_91 ) ;
V_37 = - V_189 ;
V_2 = NULL ;
if ( ! V_90 )
goto V_378;
V_37 = F_153 ( & V_91 -> V_91 , V_372 ) ;
if ( V_37 < 0 )
goto V_378;
F_159 ( & V_91 -> V_91 , V_90 ) ;
F_154 ( & V_91 -> V_91 , L_85 ,
V_90 -> V_62 -> V_67 ,
V_90 -> V_62 -> V_68 ,
V_90 -> V_62 -> V_48 ) ;
if ( V_90 -> V_62 -> V_67 == 0 ||
V_90 -> V_62 -> V_68 == 0 ||
V_90 -> V_62 -> V_48 == 0 ) {
F_80 ( & V_91 -> V_91 , L_86 ) ;
V_37 = - V_49 ;
goto V_378;
}
V_2 = F_141 ( & V_91 -> V_91 ) ;
if ( ! V_2 ) {
F_80 ( & V_91 -> V_91 , L_87 ) ;
V_37 = - V_189 ;
goto V_378;
}
if ( F_72 () && V_90 -> V_379 )
V_2 -> V_25 . V_39 . V_344 = V_380 ;
V_2 -> V_289 = V_90 -> V_381 ;
V_2 -> V_290 = V_90 -> V_382 ;
V_377 = F_162 ( V_91 , V_383 , 0 ) ;
if ( V_377 == NULL ) {
F_80 ( & V_91 -> V_91 , L_88 ) ;
V_37 = - V_159 ;
goto V_384;
}
V_377 = F_163 ( V_377 -> V_120 , F_164 ( V_377 ) , V_91 -> V_352 ) ;
if ( V_377 == NULL ) {
F_80 ( & V_91 -> V_91 , L_89 ) ;
V_37 = - V_385 ;
goto V_384;
}
V_2 -> V_4 = F_165 ( V_377 -> V_120 , F_164 ( V_377 ) ) ;
if ( V_2 -> V_4 == NULL ) {
F_80 ( & V_91 -> V_91 , L_90 ) ;
V_37 = - V_385 ;
goto V_386;
}
V_2 -> V_387 = F_60 ( sizeof( struct V_205 ) ) ;
V_2 -> V_96 = F_166 ( V_2 -> V_91 , V_2 -> V_387 ,
& V_2 -> V_210 , V_187 ) ;
if ( V_2 -> V_96 == NULL ) {
F_80 ( & V_91 -> V_91 , L_91 ) ;
V_37 = - V_189 ;
goto V_388;
}
V_37 = F_138 ( V_2 ) ;
if ( V_37 ) {
F_80 ( & V_91 -> V_91 , L_92 , V_37 ) ;
V_37 = - V_189 ;
goto V_389;
}
V_294 = F_167 ( V_91 , 0 ) ;
if ( V_294 < 0 ) {
F_80 ( & V_91 -> V_91 , L_93 ) ;
V_37 = - V_159 ;
goto V_390;
}
V_37 = F_168 ( V_294 , F_128 , 0 , L_94 , V_2 ) ;
if ( V_37 ) {
F_80 ( & V_91 -> V_91 , L_95 , V_37 ) ;
V_37 = - V_385 ;
goto V_390;
}
V_37 = F_113 ( V_2 ) ;
if ( V_37 ) {
F_80 ( & V_91 -> V_91 , L_96 ) ;
goto V_391;
}
V_37 = F_27 ( & V_2 -> V_25 . V_27 , & V_2 -> V_25 ) ;
if ( V_37 ) {
F_80 ( & V_91 -> V_91 , L_97 ) ;
goto V_391;
}
V_37 = F_31 ( & V_2 -> V_25 ) ;
if ( V_37 ) {
F_80 ( & V_91 -> V_91 , L_98 ) ;
goto V_391;
}
F_169 ( V_91 , V_2 ) ;
V_37 = F_79 ( & V_2 -> V_25 ) ;
if ( V_37 < 0 ) {
F_80 ( & V_91 -> V_91 ,
L_99 , V_37 ) ;
goto V_392;
}
F_78 ( V_2 ) ;
#ifdef F_29
V_2 -> V_312 . V_393 = F_133 ;
V_2 -> V_315 . V_393 = F_135 ;
F_170 ( & V_2 -> V_312 ,
V_394 ) ;
F_170 ( & V_2 -> V_315 ,
V_395 ) ;
#endif
F_130 ( V_2 , V_9 ) ;
return 0 ;
V_392:
if ( V_2 -> V_25 . V_98 . V_396 )
F_32 ( & V_2 -> V_25 . V_98 ) ;
V_391:
F_171 ( V_294 , V_2 ) ;
V_390:
F_84 ( V_2 -> V_170 , V_2 -> V_171 ) ;
V_389:
F_172 ( & V_91 -> V_91 , V_2 -> V_387 ,
V_2 -> V_96 , V_2 -> V_210 ) ;
V_388:
F_173 ( V_2 -> V_4 ) ;
V_386:
F_174 ( V_377 -> V_120 , F_164 ( V_377 ) ) ;
V_384:
F_175 ( V_2 -> V_196 ) ;
F_144 ( V_2 ) ;
V_378:
return V_37 ;
}
static int F_176 ( struct V_375 * V_91 )
{
struct V_1 * V_2 = F_177 ( V_91 ) ;
struct V_376 * V_377 ;
int V_294 ;
struct V_23 * V_24 ;
if ( ! V_2 )
return 0 ;
V_24 = & V_2 -> V_25 ;
F_83 ( V_2 ) ;
F_81 ( V_24 ) ;
F_126 ( V_2 ) ;
if ( V_2 -> V_25 . V_98 . V_396 )
F_32 ( & V_2 -> V_25 . V_98 ) ;
V_294 = F_167 ( V_91 , 0 ) ;
F_171 ( V_294 , V_2 ) ;
F_84 ( V_2 -> V_170 , V_2 -> V_171 ) ;
F_178 ( & V_91 -> V_91 , V_2 -> V_387 ,
V_2 -> V_96 , V_2 -> V_210 ) ;
F_173 ( V_2 -> V_4 ) ;
V_377 = F_162 ( V_91 , V_383 , 0 ) ;
F_174 ( V_377 -> V_120 , F_164 ( V_377 ) ) ;
F_175 ( V_2 -> V_196 ) ;
F_144 ( V_2 ) ;
return 0 ;
}
static int T_6 F_179 ( void )
{
if ( F_156 () )
return - V_49 ;
return F_180 ( & V_397 ) ;
}
static void T_7 F_181 ( void )
{
F_182 ( & V_397 ) ;
}
