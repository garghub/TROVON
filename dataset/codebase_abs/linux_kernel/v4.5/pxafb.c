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
struct V_58 * V_90 = V_2 -> V_90 ;
int V_91 ;
if ( V_90 -> V_92 ) {
struct V_57 * V_60 ;
V_60 = F_20 ( V_90 , V_27 ) ;
if ( ! V_60 )
return - V_49 ;
F_21 ( V_27 , V_60 ) ;
}
V_91 = F_14 ( V_27 ) ;
if ( V_91 < 0 )
return V_91 ;
F_17 ( V_27 , F_13 ( V_27 ) ) ;
V_91 = F_22 ( V_2 , V_27 ) ;
if ( V_91 )
return V_91 ;
#ifdef F_28
F_29 ( L_1 ,
F_19 ( V_27 ) ) ;
#endif
return 0 ;
}
static int F_30 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_11 ( V_24 , struct V_1 , V_25 ) ;
struct V_46 * V_27 = & V_24 -> V_27 ;
if ( V_27 -> V_50 >= 16 )
V_2 -> V_25 . V_39 . V_40 = V_41 ;
else if ( ! V_2 -> V_93 )
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
V_2 -> V_29 = ( V_94 * ) & V_2 -> V_95 -> V_96 [ 0 ] ;
if ( V_2 -> V_25 . V_27 . V_50 >= 16 )
F_31 ( & V_2 -> V_25 . V_97 ) ;
else
F_32 ( & V_2 -> V_25 . V_97 , 1 << V_2 -> V_25 . V_27 . V_50 , 0 ) ;
F_33 ( V_27 , V_2 ) ;
return 0 ;
}
static int F_34 ( struct V_46 * V_27 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = F_11 ( V_24 , struct V_1 , V_25 ) ;
struct V_46 V_98 ;
int V_99 = V_100 + V_101 ;
if ( V_2 -> V_6 != V_9 )
return 0 ;
memcpy ( & V_98 , & V_2 -> V_25 . V_27 , sizeof( V_98 ) ) ;
V_98 . V_102 = V_27 -> V_102 ;
V_98 . V_103 = V_27 -> V_103 ;
V_98 . V_104 &= ~ V_105 ;
V_98 . V_104 |= V_27 -> V_104 & V_105 ;
F_35 ( V_2 , & V_98 , 1 ) ;
if ( V_2 -> V_81 & V_106 )
F_3 ( V_2 , V_107 , V_2 -> V_108 [ V_99 + 1 ] | 0x1 ) ;
F_3 ( V_2 , V_109 , V_2 -> V_108 [ V_99 ] | 0x1 ) ;
return 0 ;
}
static int F_36 ( int V_110 , struct V_23 * V_24 )
{
struct V_1 * V_2 = F_11 ( V_24 , struct V_1 , V_25 ) ;
int V_65 ;
switch ( V_110 ) {
case V_111 :
case V_112 :
case V_113 :
case V_114 :
if ( V_2 -> V_25 . V_39 . V_40 == V_45 ||
V_2 -> V_25 . V_39 . V_40 == V_44 )
for ( V_65 = 0 ; V_65 < V_2 -> V_26 ; V_65 ++ )
F_10 ( V_65 , 0 , 0 , 0 , 0 , V_24 ) ;
F_5 ( V_2 , V_11 ) ;
break;
case V_115 :
if ( V_2 -> V_25 . V_39 . V_40 == V_45 ||
V_2 -> V_25 . V_39 . V_40 == V_44 )
F_37 ( & V_2 -> V_25 . V_97 , V_24 ) ;
F_5 ( V_2 , V_9 ) ;
}
return 0 ;
}
static void F_38 ( struct V_116 * V_117 )
{
int V_118 = V_117 -> V_25 . V_39 . V_78 * V_117 -> V_25 . V_27 . V_86 ;
unsigned long V_119 = V_117 -> V_120 ;
F_39 ( V_117 -> V_2 , V_121 , V_122 , V_119 , V_118 ) ;
}
static void F_40 ( struct V_116 * V_117 )
{
int V_123 = F_1 ( V_117 -> V_2 , V_124 ) & V_125 ;
T_2 V_126 = V_117 -> V_2 -> V_108 [ V_121 ] | ( V_123 ? 0x1 : 0 ) ;
F_3 ( V_117 -> V_2 , V_123 ? V_107 : V_127 , V_126 ) ;
F_3 ( V_117 -> V_2 , V_128 , V_117 -> V_129 [ 1 ] ) ;
F_3 ( V_117 -> V_2 , V_124 , V_117 -> V_129 [ 0 ] | V_125 ) ;
}
static void F_41 ( struct V_116 * V_117 )
{
T_2 V_130 ;
if ( ! ( F_1 ( V_117 -> V_2 , V_124 ) & V_125 ) )
return;
V_130 = F_1 ( V_117 -> V_2 , V_131 ) ;
F_3 ( V_117 -> V_2 , V_124 , V_117 -> V_129 [ 0 ] & ~ V_125 ) ;
F_3 ( V_117 -> V_2 , V_132 , F_42 ( 1 ) ) ;
F_3 ( V_117 -> V_2 , V_131 , V_130 & ~ F_42 ( 1 ) ) ;
F_3 ( V_117 -> V_2 , V_107 , V_117 -> V_2 -> V_108 [ V_121 ] | 0x3 ) ;
if ( F_43 ( & V_117 -> V_133 , 1 * V_134 ) == 0 )
F_44 ( L_2 , V_135 ) ;
F_3 ( V_117 -> V_2 , V_131 , V_130 ) ;
}
static void F_45 ( struct V_116 * V_117 )
{
int V_118 , div = 1 , V_136 = F_46 ( V_117 -> V_25 . V_27 . V_137 ) ;
unsigned long V_119 [ 3 ] = { V_117 -> V_120 , 0 , 0 } ;
if ( V_136 == V_138 || V_136 == V_139 ) {
V_118 = V_117 -> V_25 . V_39 . V_78 * V_117 -> V_25 . V_27 . V_86 ;
F_39 ( V_117 -> V_2 , V_140 , - 1 , V_119 [ 0 ] , V_118 ) ;
} else {
V_118 = V_117 -> V_25 . V_27 . V_83 * V_117 -> V_25 . V_27 . V_86 ;
switch ( V_136 ) {
case V_141 : div = 1 ; break;
case V_142 : div = 2 ; break;
case V_143 : div = 4 ; break;
}
V_119 [ 1 ] = V_119 [ 0 ] + V_118 ;
V_119 [ 2 ] = V_119 [ 1 ] + V_118 / div ;
F_39 ( V_117 -> V_2 , V_140 , - 1 , V_119 [ 0 ] , V_118 ) ;
F_39 ( V_117 -> V_2 , V_144 , - 1 , V_119 [ 1 ] , V_118 / div ) ;
F_39 ( V_117 -> V_2 , V_145 , - 1 , V_119 [ 2 ] , V_118 / div ) ;
}
}
static void F_47 ( struct V_116 * V_117 )
{
int V_136 = F_46 ( V_117 -> V_25 . V_27 . V_137 ) ;
int V_123 = F_1 ( V_117 -> V_2 , V_146 ) & V_125 ;
T_2 V_147 = V_117 -> V_2 -> V_108 [ V_140 ] | ( V_123 ? 0x1 : 0 ) ;
T_2 V_148 = V_117 -> V_2 -> V_108 [ V_144 ] | ( V_123 ? 0x1 : 0 ) ;
T_2 V_149 = V_117 -> V_2 -> V_108 [ V_145 ] | ( V_123 ? 0x1 : 0 ) ;
if ( V_136 == V_138 || V_136 == V_139 )
F_3 ( V_117 -> V_2 , V_123 ? V_150 : V_151 , V_147 ) ;
else {
F_3 ( V_117 -> V_2 , V_123 ? V_150 : V_151 , V_147 ) ;
F_3 ( V_117 -> V_2 , V_123 ? V_152 : V_153 , V_148 ) ;
F_3 ( V_117 -> V_2 , V_123 ? V_154 : V_155 , V_149 ) ;
}
F_3 ( V_117 -> V_2 , V_156 , V_117 -> V_129 [ 1 ] ) ;
F_3 ( V_117 -> V_2 , V_146 , V_117 -> V_129 [ 0 ] | V_125 ) ;
}
static void F_48 ( struct V_116 * V_117 )
{
T_2 V_130 ;
if ( ! ( F_1 ( V_117 -> V_2 , V_146 ) & V_125 ) )
return;
V_130 = F_1 ( V_117 -> V_2 , V_131 ) ;
F_3 ( V_117 -> V_2 , V_146 , V_117 -> V_129 [ 0 ] & ~ V_125 ) ;
F_3 ( V_117 -> V_2 , V_132 , F_42 ( 2 ) ) ;
F_3 ( V_117 -> V_2 , V_131 , V_130 & ~ F_42 ( 2 ) ) ;
F_3 ( V_117 -> V_2 , V_150 , V_117 -> V_2 -> V_108 [ V_140 ] | 0x3 ) ;
F_3 ( V_117 -> V_2 , V_152 , V_117 -> V_2 -> V_108 [ V_144 ] | 0x3 ) ;
F_3 ( V_117 -> V_2 , V_154 , V_117 -> V_2 -> V_108 [ V_145 ] | 0x3 ) ;
if ( F_43 ( & V_117 -> V_133 , 1 * V_134 ) == 0 )
F_44 ( L_3 , V_135 ) ;
}
static int F_49 ( struct V_23 * V_24 , int V_157 )
{
struct V_116 * V_117 = F_11 ( V_24 , struct V_116 , V_25 ) ;
if ( V_157 == 0 )
return - V_158 ;
if ( V_117 -> V_159 ++ == 0 ) {
F_50 () ;
F_51 ( & V_117 -> V_2 -> V_25 , V_115 ) ;
F_52 () ;
}
return 0 ;
}
static int F_53 ( struct V_23 * V_24 , int V_157 )
{
struct V_116 * V_117 = F_11 ( V_24 , struct V_116 , V_25 ) ;
if ( V_117 -> V_159 == 1 ) {
V_117 -> V_160 -> V_161 ( V_117 ) ;
V_117 -> V_25 . V_27 . V_162 = - 1 ;
V_117 -> V_25 . V_27 . V_163 = - 1 ;
V_117 -> V_25 . V_27 . V_67 = V_117 -> V_25 . V_27 . V_83 = 0 ;
V_117 -> V_25 . V_27 . V_68 = V_117 -> V_25 . V_27 . V_86 = 0 ;
V_117 -> V_159 -- ;
}
return 0 ;
}
static int F_54 ( struct V_46 * V_27 ,
struct V_23 * V_24 )
{
struct V_116 * V_117 = F_11 ( V_24 , struct V_116 , V_25 ) ;
struct V_46 * V_164 = & V_117 -> V_2 -> V_25 . V_27 ;
int V_165 , V_166 , V_136 , V_48 ;
V_165 = F_55 ( V_27 -> V_137 ) ;
V_166 = F_56 ( V_27 -> V_137 ) ;
V_136 = F_46 ( V_27 -> V_137 ) ;
V_48 = F_14 ( V_27 ) ;
if ( V_48 < 0 )
return - V_49 ;
if ( V_117 -> V_167 == V_168 && V_136 != 0 )
return - V_49 ;
switch ( V_136 ) {
case V_138 :
V_48 = F_14 ( V_27 ) ;
if ( V_48 < 0 )
return - V_49 ;
F_17 ( V_27 , F_13 ( V_27 ) ) ;
break;
case V_139 : V_48 = 24 ; break;
case V_141 : V_48 = 8 ; break;
case V_142 : V_48 = 4 ; break;
case V_143 : V_48 = 2 ; break;
default:
return - V_49 ;
}
if ( ( V_165 * V_48 ) % 32 )
return - V_49 ;
V_27 -> V_67 = F_57 ( V_27 -> V_67 * V_48 , 32 ) / V_48 ;
if ( ( V_165 + V_27 -> V_67 > V_164 -> V_67 ) ||
( V_166 + V_27 -> V_68 > V_164 -> V_68 ) )
return - V_49 ;
V_27 -> V_83 = V_27 -> V_67 ;
V_27 -> V_86 = F_26 ( V_27 -> V_68 , V_27 -> V_86 ) ;
return 0 ;
}
static int F_58 ( struct V_116 * V_117 )
{
struct V_46 * V_27 = & V_117 -> V_25 . V_27 ;
int V_136 = F_46 ( V_27 -> V_137 ) ;
int V_118 , V_48 = 0 ;
switch ( V_136 ) {
case V_138 : V_48 = V_27 -> V_50 ; break;
case V_139 : V_48 = 24 ; break;
case V_141 : V_48 = 24 ; break;
case V_142 : V_48 = 16 ; break;
case V_143 : V_48 = 12 ; break;
}
V_117 -> V_25 . V_39 . V_78 = V_27 -> V_83 * V_48 / 8 ;
V_118 = F_59 ( V_117 -> V_25 . V_39 . V_78 * V_27 -> V_86 ) ;
if ( V_117 -> V_169 ) {
if ( V_117 -> V_170 >= V_118 )
return 0 ;
}
return - V_49 ;
}
static int F_60 ( struct V_23 * V_24 )
{
struct V_116 * V_117 = F_11 ( V_24 , struct V_116 , V_25 ) ;
struct V_46 * V_27 = & V_24 -> V_27 ;
int V_165 , V_166 , V_136 , V_48 , V_37 ;
V_37 = F_58 ( V_117 ) ;
if ( V_37 )
return V_37 ;
V_48 = F_14 ( V_27 ) ;
V_165 = F_55 ( V_27 -> V_137 ) ;
V_166 = F_56 ( V_27 -> V_137 ) ;
V_136 = F_46 ( V_27 -> V_137 ) ;
V_117 -> V_129 [ 0 ] = F_61 ( V_27 -> V_67 ) | F_62 ( V_27 -> V_68 ) |
F_63 ( V_48 ) ;
V_117 -> V_129 [ 1 ] = F_64 ( V_165 ) | F_65 ( V_166 ) ;
if ( V_117 -> V_167 == V_171 )
V_117 -> V_129 [ 1 ] |= F_66 ( V_136 ) ;
V_117 -> V_160 -> V_172 ( V_117 ) ;
V_117 -> V_160 -> V_173 ( V_117 ) ;
return 0 ;
}
static void F_67 ( struct V_1 * V_2 , struct V_116 * V_117 ,
int V_167 )
{
sprintf ( V_117 -> V_25 . V_39 . V_167 , L_4 , V_167 + 1 ) ;
V_117 -> V_25 . V_39 . type = V_174 ;
V_117 -> V_25 . V_39 . V_175 = 0 ;
V_117 -> V_25 . V_39 . V_176 = 1 ;
V_117 -> V_25 . V_27 . V_177 = V_178 ;
V_117 -> V_25 . V_27 . V_162 = - 1 ;
V_117 -> V_25 . V_27 . V_163 = - 1 ;
V_117 -> V_25 . V_27 . V_104 = V_179 ;
V_117 -> V_25 . V_180 = & V_181 ;
V_117 -> V_25 . V_7 = V_182 ;
V_117 -> V_25 . V_183 = - 1 ;
V_117 -> V_25 . V_43 = NULL ;
V_117 -> V_167 = V_167 ;
V_117 -> V_160 = & V_184 [ V_167 ] ;
V_117 -> V_159 = 0 ;
V_117 -> V_2 = V_2 ;
F_68 ( & V_117 -> V_133 ) ;
}
static inline int F_69 ( void )
{
if ( F_70 () || F_71 () )
return 1 ;
return 0 ;
}
static int F_72 ( struct V_1 * V_185 ,
struct V_116 * V_117 )
{
V_117 -> V_169 = F_73 ( F_59 ( V_185 -> V_170 ) ,
V_186 | V_187 ) ;
if ( V_117 -> V_169 == NULL )
return - V_188 ;
V_117 -> V_120 = F_74 ( V_117 -> V_169 ) ;
V_117 -> V_170 = F_59 ( V_185 -> V_170 ) ;
F_75 ( & V_117 -> V_25 . V_189 ) ;
V_117 -> V_25 . V_39 . V_190 = V_117 -> V_120 ;
V_117 -> V_25 . V_39 . V_87 = V_185 -> V_170 ;
F_76 ( & V_117 -> V_25 . V_189 ) ;
V_117 -> V_25 . V_191 = V_117 -> V_169 ;
return 0 ;
}
static void F_77 ( struct V_1 * V_2 )
{
int V_65 , V_37 ;
if ( ! F_69 () )
return;
for ( V_65 = 0 ; V_65 < 2 ; V_65 ++ ) {
struct V_116 * V_117 = & V_2 -> V_192 [ V_65 ] ;
F_67 ( V_2 , V_117 , V_65 ) ;
V_37 = F_78 ( & V_117 -> V_25 ) ;
if ( V_37 ) {
F_79 ( V_2 -> V_193 , L_5 , V_65 ) ;
continue;
}
V_37 = F_72 ( V_2 , V_117 ) ;
if ( V_37 ) {
F_79 ( V_2 -> V_193 ,
L_6 ,
V_65 ) ;
F_80 ( & V_117 -> V_25 ) ;
continue;
}
V_117 -> V_194 = 1 ;
}
F_3 ( V_2 , V_131 , ~ 0 ) ;
F_81 ( L_7 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
int V_65 ;
if ( ! F_69 () )
return;
for ( V_65 = 0 ; V_65 < 2 ; V_65 ++ ) {
struct V_116 * V_117 = & V_2 -> V_192 [ V_65 ] ;
if ( V_117 -> V_194 ) {
if ( V_117 -> V_169 )
F_83 ( V_117 -> V_169 ,
V_117 -> V_170 ) ;
F_80 ( & V_117 -> V_25 ) ;
}
}
}
static inline void F_77 ( struct V_1 * V_2 ) {}
static inline void F_82 ( struct V_1 * V_2 ) {}
static inline unsigned int F_84 ( struct V_1 * V_2 ,
unsigned int V_56 )
{
unsigned long long V_195 ;
V_195 = ( unsigned long long ) ( F_85 ( V_2 -> V_196 ) / 10000 ) ;
V_195 *= V_56 ;
F_86 ( V_195 , 100000000 * 2 ) ;
return ( unsigned int ) V_195 ;
}
static inline void F_87 ( struct V_1 * V_2 , unsigned int V_195 )
{
unsigned long V_197 ;
if ( ( V_195 == 0 ) || ( V_2 -> V_25 . V_27 . V_69 == 0 ) ) {
V_2 -> V_198 = 0 ;
return;
}
V_197 = F_85 ( V_2 -> V_196 ) / ( V_195 * V_2 -> V_25 . V_27 . V_69 ) ;
V_2 -> V_198 = V_197 ;
}
unsigned long F_88 ( struct V_199 * V_193 )
{
struct V_1 * V_2 = F_89 ( V_193 ) ;
if ( ! V_2 || ( V_2 -> V_6 != V_9 ) )
return 0 ;
return V_2 -> V_198 ;
}
static int F_39 ( struct V_1 * V_2 , int V_99 , int V_42 ,
unsigned long V_119 , T_3 V_118 )
{
struct V_200 * V_201 , * V_202 ;
unsigned int V_203 , V_204 ;
if ( V_99 < 0 || V_99 >= V_100 * 2 )
return - V_49 ;
V_201 = & V_2 -> V_95 -> V_201 [ V_99 ] ;
V_203 = F_90 ( struct V_205 , V_201 [ V_99 ] ) ;
V_201 -> V_206 = V_119 ;
V_201 -> V_207 = 0 ;
V_201 -> V_208 = V_118 ;
if ( V_42 < 0 || V_42 >= V_209 * 2 ) {
V_201 -> V_108 = V_2 -> V_210 + V_203 ;
V_2 -> V_108 [ V_99 ] = V_2 -> V_210 + V_203 ;
} else {
V_202 = & V_2 -> V_95 -> V_202 [ V_42 ] ;
V_204 = F_90 ( struct V_205 , V_202 [ V_42 ] ) ;
V_202 -> V_206 = V_2 -> V_210 + V_42 * V_211 ;
V_202 -> V_207 = 0 ;
if ( ( V_2 -> V_30 & V_31 ) == V_32 )
V_202 -> V_208 = V_2 -> V_26 * sizeof( V_94 ) ;
else
V_202 -> V_208 = V_2 -> V_26 * sizeof( V_34 ) ;
V_202 -> V_208 |= V_212 ;
V_202 -> V_108 = V_2 -> V_210 + V_203 ;
V_201 -> V_108 = V_2 -> V_210 + V_204 ;
V_2 -> V_108 [ V_99 ] = V_2 -> V_210 + V_203 ;
}
return 0 ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_46 * V_27 ,
int V_213 )
{
struct V_214 * V_39 = & V_2 -> V_25 . V_39 ;
int V_215 , V_99 , V_42 , V_48 = V_27 -> V_50 ;
unsigned long V_17 ;
V_99 = V_101 + ( V_213 ? V_100 : 0 ) ;
V_42 = ( V_48 >= 16 ) ? V_122 : V_216 + ( V_213 ? V_209 : 0 ) ;
V_215 = V_39 -> V_78 * V_27 -> V_68 ;
V_17 = V_39 -> V_78 * V_27 -> V_103 + V_2 -> V_120 ;
if ( V_2 -> V_81 & V_106 ) {
V_215 = V_215 / 2 ;
F_39 ( V_2 , V_99 + 1 , V_122 , V_17 + V_215 , V_215 ) ;
}
F_39 ( V_2 , V_99 , V_42 , V_17 , V_215 ) ;
}
static int F_91 ( struct V_1 * V_2 )
{
struct V_200 * V_201 ;
unsigned long V_203 , V_217 ;
V_201 = & V_2 -> V_95 -> V_201 [ V_218 ] ;
V_203 = F_90 ( struct V_205 , V_201 [ V_218 ] ) ;
V_217 = F_90 ( struct V_205 , V_219 ) ;
V_201 -> V_108 = V_2 -> V_210 + V_203 ;
V_201 -> V_206 = V_2 -> V_210 + V_217 ;
V_201 -> V_207 = 0 ;
V_201 -> V_208 = V_2 -> V_220 * sizeof( V_221 ) ;
V_2 -> V_108 [ V_218 ] = V_201 -> V_108 ;
return 0 ;
}
int F_92 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_11 ( V_24 , struct V_1 , V_25 ) ;
T_2 V_222 ;
int V_37 = 0 ;
F_3 ( V_2 , V_223 , V_2 -> V_224 & ~ V_225 ) ;
while ( V_2 -> V_220 & 1 )
V_2 -> V_226 [ V_2 -> V_220 ++ ] = V_227 ;
V_2 -> V_226 [ V_2 -> V_220 ++ ] = V_228 ;
V_2 -> V_226 [ V_2 -> V_220 ++ ] = V_229 ;
F_91 ( V_2 ) ;
V_222 = F_1 ( V_2 , V_230 ) | V_231 | V_232 ;
F_3 ( V_2 , V_230 , V_222 ) ;
F_3 ( V_2 , V_233 , 0x0001 ) ;
F_3 ( V_2 , V_131 , F_93 ( 6 ) ) ;
F_3 ( V_2 , V_234 , V_2 -> V_235 ) ;
F_3 ( V_2 , V_236 , V_2 -> V_237 ) ;
F_3 ( V_2 , V_238 , V_2 -> V_239 ) ;
F_3 ( V_2 , V_240 , V_2 -> V_241 ) ;
F_3 ( V_2 , V_242 , V_2 -> V_108 [ 0 ] ) ;
F_3 ( V_2 , V_243 , V_2 -> V_108 [ 6 ] ) ;
F_3 ( V_2 , V_223 , V_2 -> V_224 | V_225 ) ;
if ( F_43 ( & V_2 -> V_244 , V_134 / 2 ) == 0 ) {
F_44 ( L_8 ,
V_135 ) ;
V_37 = - V_245 ;
}
V_222 = F_1 ( V_2 , V_230 ) & ~ ( V_231 | V_232 ) ;
F_3 ( V_2 , V_230 , V_222 ) ;
F_3 ( V_2 , V_223 , V_2 -> V_224 & ~ V_225 ) ;
F_3 ( V_2 , V_243 , 0 ) ;
V_2 -> V_220 = 0 ;
return V_37 ;
}
int F_94 ( struct V_23 * V_24 , V_221 * V_246 , int V_247 )
{
int V_65 ;
struct V_1 * V_2 = F_11 ( V_24 , struct V_1 , V_25 ) ;
for ( V_65 = 0 ; V_65 < V_247 ; V_65 ++ , V_246 ++ ) {
if ( ( * V_246 & 0xff00 ) == V_248 ) {
F_92 ( V_24 ) ;
F_95 ( * V_246 & 0xff ) ;
continue;
}
if ( V_2 -> V_220 == V_249 - 8 )
F_92 ( V_24 ) ;
V_2 -> V_226 [ V_2 -> V_220 ++ ] = * V_246 ;
}
return 0 ;
}
static unsigned int F_96 ( unsigned V_250 , unsigned long V_251 )
{
unsigned int V_252 = ( V_250 * ( V_251 / 1000000 ) / 1000 ) ;
return ( V_252 == 0 ) ? 1 : V_252 ;
}
static void F_97 ( struct V_1 * V_2 ,
struct V_46 * V_27 )
{
struct V_58 * V_90 = V_2 -> V_90 ;
struct V_57 * V_60 = & V_90 -> V_62 [ 0 ] ;
unsigned long V_253 = F_85 ( V_2 -> V_196 ) ;
unsigned V_254 , V_255 , V_256 , V_257 ;
V_254 = F_26 ( V_60 -> V_258 , V_60 -> V_259 ) ;
V_255 = F_26 ( V_60 -> V_260 , V_60 -> V_261 ) ;
V_256 = V_60 -> V_262 ;
V_257 = V_60 -> V_263 ;
V_2 -> V_235 =
F_98 ( V_27 -> V_67 ) |
F_99 ( F_96 ( V_254 , V_253 ) ) |
F_100 ( F_96 ( V_255 , V_253 ) ) |
F_101 ( F_96 ( V_256 , V_253 ) ) ;
V_2 -> V_237 = F_102 ( V_27 -> V_68 ) ;
V_2 -> V_239 = V_2 -> V_51 | F_103 ( F_96 ( V_257 , V_253 ) ) ;
V_2 -> V_239 |= ( V_27 -> V_75 & V_264 ) ? V_265 : 0 ;
V_2 -> V_239 |= ( V_27 -> V_75 & V_266 ) ? V_267 : 0 ;
V_2 -> V_268 = 1 ;
}
static int F_104 ( void * V_269 )
{
struct V_1 * V_2 = V_269 ;
struct V_58 * V_90 = V_2 -> V_90 ;
if ( ! V_90 -> V_270 ) {
F_105 ( L_9 ,
V_135 ) ;
return - V_49 ;
}
F_29 ( L_10 , V_135 ) ;
F_106 () ;
while ( ! F_107 () ) {
if ( F_108 () )
continue;
F_75 ( & V_2 -> V_271 ) ;
if ( V_2 -> V_6 == V_9 ) {
V_90 -> V_270 ( & V_2 -> V_25 ) ;
F_109 ( & V_2 -> V_272 ) ;
}
F_76 ( & V_2 -> V_271 ) ;
F_110 ( V_273 ) ;
F_111 ( F_112 ( 30 ) ) ;
}
F_29 ( L_11 , V_135 ) ;
return 0 ;
}
static int F_113 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_81 & V_82 ) )
return 0 ;
V_2 -> V_226 = ( V_221 * ) V_2 -> V_95 -> V_219 ;
V_2 -> V_220 = 0 ;
F_68 ( & V_2 -> V_244 ) ;
F_68 ( & V_2 -> V_272 ) ;
V_2 -> V_274 = F_114 ( F_104 , V_2 ,
L_12 ) ;
if ( F_115 ( V_2 -> V_274 ) ) {
F_105 ( L_13 , V_135 ) ;
return F_116 ( V_2 -> V_274 ) ;
}
return 0 ;
}
static inline int F_113 ( struct V_1 * V_2 ) { return 0 ; }
static void F_117 ( struct V_1 * V_2 ,
struct V_46 * V_27 )
{
unsigned int V_275 , V_195 = F_84 ( V_2 , V_27 -> V_56 ) ;
V_2 -> V_235 =
F_98 ( V_27 -> V_67 ) +
F_101 ( V_27 -> V_69 ) +
F_99 ( V_27 -> V_70 ) +
F_100 ( V_27 -> V_71 ) ;
V_275 = V_27 -> V_68 ;
if ( ( V_2 -> V_81 & V_106 ) == V_276 )
V_275 /= 2 ;
V_2 -> V_237 =
F_102 ( V_275 ) +
F_118 ( V_27 -> V_72 ) +
F_119 ( V_27 -> V_73 ) +
F_120 ( V_27 -> V_74 ) ;
V_2 -> V_239 = V_2 -> V_51 |
( V_27 -> V_75 & V_264 ?
V_277 : V_278 ) |
( V_27 -> V_75 & V_266 ?
V_279 : V_280 ) ;
if ( V_195 ) {
V_2 -> V_239 |= F_103 ( V_195 ) ;
F_87 ( V_2 , V_195 ) ;
}
}
static int F_33 ( struct V_46 * V_27 ,
struct V_1 * V_2 )
{
T_4 V_7 ;
F_6 ( V_7 ) ;
#ifdef F_121
if ( V_2 -> V_81 & V_82 )
F_97 ( V_2 , V_27 ) ;
else
#endif
F_117 ( V_2 , V_27 ) ;
F_35 ( V_2 , V_27 , 0 ) ;
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
( F_1 ( V_2 , V_242 ) != V_2 -> V_108 [ 0 ] ) ||
( ( V_2 -> V_81 & V_106 ) &&
( F_1 ( V_2 , V_127 ) != V_2 -> V_108 [ 1 ] ) ) )
F_5 ( V_2 , V_10 ) ;
return 0 ;
}
static inline void F_122 ( struct V_1 * V_2 , int V_288 )
{
F_29 ( L_14 , V_288 ? L_15 : L_16 ) ;
if ( V_2 -> V_289 )
V_2 -> V_289 ( V_288 ) ;
}
static inline void F_123 ( struct V_1 * V_2 , int V_288 )
{
F_29 ( L_17 , V_288 ? L_15 : L_16 ) ;
if ( V_2 -> V_290 )
V_2 -> V_290 ( V_288 , & V_2 -> V_25 . V_27 ) ;
}
static void F_124 ( struct V_1 * V_2 )
{
F_29 ( L_18 ) ;
F_29 ( L_19 , ( unsigned int ) V_2 -> V_108 [ 0 ] ) ;
F_29 ( L_20 , ( unsigned int ) V_2 -> V_108 [ 1 ] ) ;
F_29 ( L_21 , ( unsigned int ) V_2 -> V_224 ) ;
F_29 ( L_22 , ( unsigned int ) V_2 -> V_235 ) ;
F_29 ( L_23 , ( unsigned int ) V_2 -> V_237 ) ;
F_29 ( L_24 , ( unsigned int ) V_2 -> V_239 ) ;
F_125 ( V_2 -> V_196 ) ;
if ( V_2 -> V_81 & V_82 )
return;
F_3 ( V_2 , V_240 , V_2 -> V_241 ) ;
F_3 ( V_2 , V_238 , V_2 -> V_239 ) ;
F_3 ( V_2 , V_236 , V_2 -> V_237 ) ;
F_3 ( V_2 , V_234 , V_2 -> V_235 ) ;
F_3 ( V_2 , V_223 , V_2 -> V_224 & ~ V_225 ) ;
F_3 ( V_2 , V_242 , V_2 -> V_108 [ 0 ] ) ;
if ( V_2 -> V_81 & V_106 )
F_3 ( V_2 , V_127 , V_2 -> V_108 [ 1 ] ) ;
F_3 ( V_2 , V_223 , V_2 -> V_224 | V_225 ) ;
}
static void F_126 ( struct V_1 * V_2 )
{
T_2 V_81 ;
#ifdef F_121
if ( V_2 -> V_81 & V_82 ) {
F_43 ( & V_2 -> V_272 ,
F_112 ( 200 ) ) ;
return;
}
#endif
F_3 ( V_2 , V_291 , 0xffffffff ) ;
V_81 = F_1 ( V_2 , V_223 ) & ~ V_281 ;
F_3 ( V_2 , V_223 , V_81 ) ;
F_3 ( V_2 , V_223 , V_81 | V_292 ) ;
F_43 ( & V_2 -> V_293 , F_112 ( 200 ) ) ;
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
F_109 ( & V_2 -> V_293 ) ;
}
#ifdef F_121
if ( V_296 & V_298 )
F_109 ( & V_2 -> V_244 ) ;
#endif
F_3 ( V_2 , V_291 , V_296 ) ;
#ifdef F_129
{
unsigned int V_299 = F_1 ( V_2 , V_132 ) ;
if ( V_299 & F_42 ( 1 ) )
F_109 ( & V_2 -> V_192 [ 0 ] . V_133 ) ;
if ( V_299 & F_42 ( 2 ) )
F_109 ( & V_2 -> V_192 [ 1 ] . V_133 ) ;
F_3 ( V_2 , V_132 , V_299 ) ;
}
#endif
return V_300 ;
}
static void F_130 ( struct V_1 * V_2 , T_1 V_6 )
{
T_1 V_301 ;
F_75 ( & V_2 -> V_271 ) ;
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
F_76 ( & V_2 -> V_271 ) ;
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
if ( ! ( V_2 -> V_192 [ 0 ] . V_159 || V_2 -> V_192 [ 1 ] . V_159 ) )
#endif
F_130 ( V_2 , V_303 ) ;
break;
case V_314 :
V_195 = F_84 ( V_2 , V_2 -> V_25 . V_27 . V_56 ) ;
F_87 ( V_2 , V_195 ) ;
V_2 -> V_239 = ( V_2 -> V_239 & ~ 0xff ) |
F_103 ( V_195 ) ;
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
F_29 ( L_25
L_26 , F_19 ( V_27 ) ,
V_317 -> F_26 ) ;
break;
}
return 0 ;
}
static int F_136 ( struct V_199 * V_193 )
{
struct V_1 * V_2 = F_89 ( V_193 ) ;
F_130 ( V_2 , V_304 ) ;
return 0 ;
}
static int F_137 ( struct V_199 * V_193 )
{
struct V_1 * V_2 = F_89 ( V_193 ) ;
F_130 ( V_2 , V_306 ) ;
return 0 ;
}
static int F_138 ( struct V_1 * V_2 )
{
int V_118 = F_59 ( V_2 -> V_170 ) ;
V_2 -> V_169 = F_73 ( V_118 , V_186 | V_187 ) ;
if ( V_2 -> V_169 == NULL )
return - V_188 ;
V_2 -> V_120 = F_74 ( V_2 -> V_169 ) ;
V_2 -> V_170 = V_118 ;
V_2 -> V_25 . V_39 . V_190 = V_2 -> V_120 ;
V_2 -> V_25 . V_39 . V_87 = V_2 -> V_170 ;
V_2 -> V_25 . V_191 = V_2 -> V_169 ;
return V_2 -> V_169 ? 0 : - V_188 ;
}
static void F_139 ( struct V_1 * V_2 ,
struct V_58 * V_90 )
{
unsigned int V_319 = V_90 -> V_319 ;
struct V_57 * V_320 ;
int V_65 ;
V_2 -> V_38 = V_90 -> V_38 ;
V_2 -> V_93 = V_90 -> V_93 ;
V_2 -> V_30 = V_90 -> V_30 ;
switch ( V_319 & V_321 ) {
case V_322 :
V_2 -> V_81 = V_323 ;
break;
case V_324 :
V_2 -> V_81 = V_323 | V_106 ;
break;
case V_325 :
V_2 -> V_81 = 0 ;
break;
case V_326 :
V_2 -> V_81 = V_106 ;
break;
case V_327 :
V_2 -> V_81 = V_328 ;
break;
case V_329 :
V_2 -> V_81 = V_82 | V_328 ;
break;
default:
V_2 -> V_81 = V_90 -> V_81 ;
V_2 -> V_51 = V_90 -> V_51 ;
goto V_330;
}
if ( V_319 == V_331 )
V_2 -> V_81 |= V_332 ;
V_2 -> V_81 |= ( V_319 & V_333 ) ? V_334 : 0 ;
V_2 -> V_51 = F_140 ( ( V_90 -> V_319 >> 10 ) & 0xff ) ;
V_2 -> V_51 |= ( V_319 & V_335 ) ? V_336 : 0 ;
V_2 -> V_51 |= ( V_319 & V_337 ) ? V_338 : 0 ;
V_330:
F_21 ( & V_2 -> V_25 . V_27 , & V_90 -> V_62 [ 0 ] ) ;
for ( V_65 = 0 , V_320 = & V_90 -> V_62 [ 0 ] ; V_65 < V_90 -> V_66 ; V_65 ++ , V_320 ++ )
V_2 -> V_170 = F_23 ( T_3 , V_2 -> V_170 ,
V_320 -> V_67 * V_320 -> V_68 * V_320 -> V_48 / 8 ) ;
if ( V_90 -> V_170 > V_2 -> V_170 )
V_2 -> V_170 = V_90 -> V_170 ;
if ( V_170 > V_2 -> V_170 )
V_2 -> V_170 = V_170 ;
}
static struct V_1 * F_141 ( struct V_199 * V_193 ,
struct V_58 * V_90 )
{
struct V_1 * V_2 ;
void * V_339 ;
V_2 = F_142 ( sizeof( struct V_1 ) + sizeof( V_34 ) * 16 , V_186 ) ;
if ( ! V_2 )
return NULL ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_193 = V_193 ;
V_2 -> V_90 = V_90 ;
V_2 -> V_196 = F_143 ( V_193 , NULL ) ;
if ( F_115 ( V_2 -> V_196 ) ) {
F_144 ( V_2 ) ;
return NULL ;
}
strcpy ( V_2 -> V_25 . V_39 . V_167 , V_340 ) ;
V_2 -> V_25 . V_39 . type = V_174 ;
V_2 -> V_25 . V_39 . V_341 = 0 ;
V_2 -> V_25 . V_39 . V_175 = 0 ;
V_2 -> V_25 . V_39 . V_176 = 1 ;
V_2 -> V_25 . V_39 . V_342 = 0 ;
V_2 -> V_25 . V_39 . V_343 = V_344 ;
V_2 -> V_25 . V_27 . V_137 = 0 ;
V_2 -> V_25 . V_27 . V_177 = V_178 ;
V_2 -> V_25 . V_27 . V_162 = - 1 ;
V_2 -> V_25 . V_27 . V_163 = - 1 ;
V_2 -> V_25 . V_27 . V_84 = V_85 ;
V_2 -> V_25 . V_27 . V_104 = V_179 ;
V_2 -> V_25 . V_180 = & V_345 ;
V_2 -> V_25 . V_7 = V_346 ;
V_2 -> V_25 . V_183 = - 1 ;
V_339 = V_2 ;
V_339 = V_339 + sizeof( struct V_1 ) ;
V_2 -> V_25 . V_43 = V_339 ;
V_2 -> V_6 = V_302 ;
V_2 -> V_8 = ( V_347 ) - 1 ;
F_139 ( V_2 , V_90 ) ;
#ifdef F_129
if ( F_69 () )
V_2 -> V_81 |= V_348 ;
#endif
F_145 ( & V_2 -> V_349 ) ;
F_146 ( & V_2 -> V_12 , F_131 ) ;
F_147 ( & V_2 -> V_271 ) ;
F_68 ( & V_2 -> V_293 ) ;
return V_2 ;
}
static int F_148 ( struct V_199 * V_193 , const char * V_350 ,
struct V_58 * V_90 )
{
const char * V_351 = V_350 + 5 ;
unsigned int V_352 = strlen ( V_351 ) ;
int V_353 = 0 , V_354 = 0 ;
unsigned int V_67 = 0 , V_68 = 0 , V_48 = 0 ;
int V_355 = 0 ;
int V_65 ;
for ( V_65 = V_352 - 1 ; V_65 >= 0 ; V_65 -- ) {
switch ( V_351 [ V_65 ] ) {
case '-' :
V_352 = V_65 ;
if ( ! V_354 && ! V_355 ) {
V_48 = F_149 ( & V_351 [ V_65 + 1 ] , NULL , 0 ) ;
V_354 = 1 ;
} else
goto V_356;
break;
case 'x' :
if ( ! V_355 ) {
V_68 = F_149 ( & V_351 [ V_65 + 1 ] , NULL , 0 ) ;
V_355 = 1 ;
} else
goto V_356;
break;
case '0' ... '9' :
break;
default:
goto V_356;
}
}
if ( V_65 < 0 && V_355 ) {
V_67 = F_149 ( V_351 , NULL , 0 ) ;
V_353 = 1 ;
}
V_356:
if ( V_353 ) {
F_150 ( V_193 , L_27 , V_67 , V_68 ) ;
V_90 -> V_62 [ 0 ] . V_67 = V_67 ; V_90 -> V_62 [ 0 ] . V_68 = V_68 ;
}
if ( V_354 )
switch ( V_48 ) {
case 1 :
case 2 :
case 4 :
case 8 :
case 16 :
V_90 -> V_62 [ 0 ] . V_48 = V_48 ;
F_150 ( V_193 , L_28 , V_48 ) ;
break;
default:
F_79 ( V_193 , L_29 , V_48 ) ;
return - V_49 ;
}
return 0 ;
}
static int F_151 ( struct V_199 * V_193 , char * V_350 ,
struct V_58 * V_90 )
{
struct V_57 * V_60 = & V_90 -> V_62 [ 0 ] ;
char V_357 [ 64 ] ;
V_357 [ 0 ] = '\0' ;
if ( ! strncmp ( V_350 , L_30 , 5 ) ) {
V_170 = F_152 ( V_350 + 5 , NULL ) ;
} else if ( ! strncmp ( V_350 , L_31 , 5 ) ) {
return F_148 ( V_193 , V_350 , V_90 ) ;
} else if ( ! strncmp ( V_350 , L_32 , 9 ) ) {
V_60 -> V_56 = F_149 ( V_350 + 9 , NULL , 0 ) ;
sprintf ( V_357 , L_33 , V_60 -> V_56 ) ;
} else if ( ! strncmp ( V_350 , L_34 , 5 ) ) {
V_60 -> V_70 = F_149 ( V_350 + 5 , NULL , 0 ) ;
sprintf ( V_357 , L_35 , V_60 -> V_70 ) ;
} else if ( ! strncmp ( V_350 , L_36 , 6 ) ) {
V_60 -> V_71 = F_149 ( V_350 + 6 , NULL , 0 ) ;
sprintf ( V_357 , L_37 , V_60 -> V_71 ) ;
} else if ( ! strncmp ( V_350 , L_38 , 6 ) ) {
V_60 -> V_73 = F_149 ( V_350 + 6 , NULL , 0 ) ;
sprintf ( V_357 , L_39 , V_60 -> V_73 ) ;
} else if ( ! strncmp ( V_350 , L_40 , 6 ) ) {
V_60 -> V_74 = F_149 ( V_350 + 6 , NULL , 0 ) ;
sprintf ( V_357 , L_41 , V_60 -> V_74 ) ;
} else if ( ! strncmp ( V_350 , L_42 , 9 ) ) {
V_60 -> V_69 = F_149 ( V_350 + 9 , NULL , 0 ) ;
sprintf ( V_357 , L_43 , V_60 -> V_69 ) ;
} else if ( ! strncmp ( V_350 , L_44 , 9 ) ) {
V_60 -> V_72 = F_149 ( V_350 + 9 , NULL , 0 ) ;
sprintf ( V_357 , L_45 , V_60 -> V_72 ) ;
} else if ( ! strncmp ( V_350 , L_46 , 6 ) ) {
if ( F_149 ( V_350 + 6 , NULL , 0 ) == 0 ) {
sprintf ( V_357 , L_47 ) ;
V_60 -> V_75 &= ~ V_264 ;
} else {
sprintf ( V_357 , L_48 ) ;
V_60 -> V_75 |= V_264 ;
}
} else if ( ! strncmp ( V_350 , L_49 , 6 ) ) {
if ( F_149 ( V_350 + 6 , NULL , 0 ) == 0 ) {
sprintf ( V_357 , L_50 ) ;
V_60 -> V_75 &= ~ V_266 ;
} else {
sprintf ( V_357 , L_51 ) ;
V_60 -> V_75 |= V_266 ;
}
} else if ( ! strncmp ( V_350 , L_52 , 4 ) ) {
if ( F_149 ( V_350 + 4 , NULL , 0 ) == 0 ) {
sprintf ( V_357 , L_53 ) ;
V_90 -> V_51 &= ~ V_358 ;
} else {
sprintf ( V_357 , L_54 ) ;
V_90 -> V_51 |= V_358 ;
}
} else if ( ! strncmp ( V_350 , L_55 , 9 ) ) {
if ( F_149 ( V_350 + 9 , NULL , 0 ) == 0 ) {
sprintf ( V_357 , L_56 ) ;
V_90 -> V_51 = ( V_90 -> V_51 & ~ V_336 ) | V_359 ;
} else {
sprintf ( V_357 , L_57 ) ;
V_90 -> V_51 = ( V_90 -> V_51 & ~ V_336 ) | V_360 ;
}
} else if ( ! strncmp ( V_350 , L_58 , 12 ) ) {
if ( F_149 ( V_350 + 12 , NULL , 0 ) == 0 ) {
sprintf ( V_357 , L_59 ) ;
V_90 -> V_51 = ( V_90 -> V_51 & ~ V_338 ) | V_361 ;
} else {
sprintf ( V_357 , L_60 ) ;
V_90 -> V_51 = ( V_90 -> V_51 & ~ V_338 ) | V_362 ;
}
} else if ( ! strncmp ( V_350 , L_61 , 5 ) ) {
V_90 -> V_81 = ( V_90 -> V_81 & ~ V_323 ) | V_363 ;
} else if ( ! strncmp ( V_350 , L_62 , 4 ) ) {
V_90 -> V_81 = ( V_90 -> V_81 & ~ V_323 ) | V_364 ;
} else if ( ! strncmp ( V_350 , L_63 , 6 ) ) {
V_90 -> V_81 = ( V_90 -> V_81 & ~ V_328 ) | V_365 ;
} else if ( ! strncmp ( V_350 , L_64 , 7 ) ) {
V_90 -> V_81 = ( V_90 -> V_81 & ~ V_328 ) | V_366 ;
} else if ( ! strncmp ( V_350 , L_65 , 6 ) ) {
V_90 -> V_81 = ( V_90 -> V_81 & ~ V_106 ) | V_367 ;
} else if ( ! strncmp ( V_350 , L_66 , 4 ) ) {
V_90 -> V_81 = ( V_90 -> V_81 & ~ V_106 ) | V_276 ;
} else if ( ! strncmp ( V_350 , L_67 , 4 ) ) {
V_90 -> V_81 = ( V_90 -> V_81 & ~ V_332 ) | V_368 ;
} else if ( ! strncmp ( V_350 , L_68 , 4 ) ) {
V_90 -> V_81 = ( V_90 -> V_81 & ~ V_332 ) | V_369 ;
} else {
F_79 ( V_193 , L_69 , V_350 ) ;
return - V_49 ;
}
if ( V_357 [ 0 ] != '\0' )
F_150 ( V_193 , L_70 , V_357 ) ;
return 0 ;
}
static int F_153 ( struct V_199 * V_193 , char * V_370 ,
struct V_58 * V_90 )
{
char * V_350 ;
int V_37 ;
if ( ! V_370 || ! * V_370 )
return 0 ;
F_154 ( V_193 , L_71 , V_370 ? V_370 : L_72 ) ;
while ( ( V_350 = F_155 ( & V_370 , L_73 ) ) != NULL ) {
V_37 = F_151 ( V_193 , V_350 , V_90 ) ;
if ( V_37 )
return V_37 ;
}
return 0 ;
}
static int T_6 F_156 ( void )
{
char * V_370 = NULL ;
if ( F_157 ( L_74 , & V_370 ) )
return - V_158 ;
if ( V_370 )
F_158 ( V_371 , V_370 , sizeof( V_371 ) ) ;
return 0 ;
}
static void F_159 ( struct V_199 * V_193 , struct V_58 * V_90 )
{
if ( V_90 -> V_319 )
return;
if ( V_90 -> V_81 & V_372 )
F_160 ( V_193 , L_75
L_76 ,
V_90 -> V_81 & V_372 ) ;
if ( V_90 -> V_51 & V_373 )
F_160 ( V_193 , L_77
L_76 ,
V_90 -> V_51 & V_373 ) ;
if ( V_90 -> V_81 & V_332 &&
( ( V_90 -> V_81 & V_328 ) != V_366 ||
( V_90 -> V_81 & V_106 ) != V_367 ||
( V_90 -> V_81 & V_323 ) != V_364 ) )
F_160 ( V_193 , L_78
L_79
L_80 ) ;
if ( ( V_90 -> V_81 & V_328 ) == V_365 &&
( V_90 -> V_81 & V_106 ) == V_276 )
F_160 ( V_193 , L_81 ) ;
if ( ( V_90 -> V_81 & V_328 ) == V_366 &&
( V_90 -> V_62 -> V_73 || V_90 -> V_62 -> V_74 ) )
F_160 ( V_193 , L_82
L_83 ) ;
}
static int F_161 ( struct V_199 * V_193 , struct V_374 * V_375 ,
struct V_58 * V_24 , V_34 V_376 )
{
struct V_377 * V_378 ;
struct V_379 V_380 ;
int V_65 , V_37 = - V_49 ;
const char * V_357 ;
V_37 = F_162 ( V_375 , L_84 , & V_357 ) ;
if ( V_37 )
V_357 = L_85 ;
for ( V_65 = 0 ; V_381 [ V_65 ] ; V_65 ++ )
if ( ! strcmp ( V_357 , V_381 [ V_65 ] ) )
break;
if ( ! V_65 || ! V_381 [ V_65 ] ) {
F_79 ( V_193 , L_86 , V_357 ) ;
return - V_49 ;
}
V_24 -> V_319 |= F_163 ( V_65 ) ;
V_24 -> V_319 |= F_164 ( V_376 ) ;
V_378 = F_165 ( V_375 ) ;
if ( ! V_378 )
goto V_382;
V_37 = - V_188 ;
V_24 -> V_62 = F_166 ( V_378 -> V_383 ,
sizeof( V_24 -> V_62 [ 0 ] ) , V_186 ) ;
if ( ! V_24 -> V_62 )
goto V_382;
V_24 -> V_66 = V_378 -> V_383 ;
for ( V_65 = 0 ; V_65 < V_378 -> V_383 ; V_65 ++ ) {
V_37 = F_167 ( V_378 , & V_380 , V_65 ) ;
if ( V_37 ) {
F_79 ( V_193 , L_87 ,
V_65 , V_37 ) ;
goto V_382;
}
if ( V_380 . V_7 & V_384 )
V_24 -> V_319 |= V_385 ;
if ( V_380 . V_7 & V_386 )
V_24 -> V_319 |= V_337 ;
if ( V_380 . V_7 & V_387 )
V_24 -> V_319 |= V_388 ;
if ( V_380 . V_7 & V_389 )
V_24 -> V_319 |= V_335 ;
if ( V_380 . V_7 & V_390 )
V_24 -> V_62 [ V_65 ] . V_75 |= V_264 ;
if ( V_380 . V_7 & V_391 )
V_24 -> V_62 [ V_65 ] . V_75 |= V_266 ;
V_24 -> V_62 [ V_65 ] . V_56 = 1000000000UL / ( V_380 . V_392 / 1000 ) ;
V_24 -> V_62 [ V_65 ] . V_67 = V_380 . V_393 ;
V_24 -> V_62 [ V_65 ] . V_68 = V_380 . V_394 ;
V_24 -> V_62 [ V_65 ] . V_69 = V_380 . V_69 ;
V_24 -> V_62 [ V_65 ] . V_70 = V_380 . V_395 ;
V_24 -> V_62 [ V_65 ] . V_71 = V_380 . V_396 ;
V_24 -> V_62 [ V_65 ] . V_72 = V_380 . V_72 ;
V_24 -> V_62 [ V_65 ] . V_73 = V_380 . V_397 ;
V_24 -> V_62 [ V_65 ] . V_74 = V_380 . V_398 ;
}
V_37 = 0 ;
V_382:
F_168 ( V_378 ) ;
return V_37 ;
}
static int F_169 ( struct V_199 * V_193 ,
struct V_58 * V_24 )
{
struct V_374 * V_399 , * V_400 ;
V_34 V_376 ;
int V_37 , V_65 ;
V_400 = F_170 ( V_193 -> V_401 , NULL ) ;
if ( ! V_400 ) {
F_79 ( V_193 , L_88 ) ;
return - V_49 ;
}
V_37 = F_171 ( V_400 , L_89 , & V_376 ) ;
if ( V_37 ) {
F_79 ( V_193 , L_90 , V_37 ) ;
return V_37 ;
}
V_399 = F_172 ( V_400 ) ;
F_173 ( V_400 ) ;
if ( ! V_399 ) {
F_79 ( V_193 , L_91 ) ;
return - V_49 ;
}
V_37 = F_161 ( V_193 , V_399 , V_24 , V_376 ) ;
F_173 ( V_399 ) ;
if ( V_37 )
return V_37 ;
for ( V_65 = 0 ; V_65 < V_24 -> V_66 ; V_65 ++ )
V_24 -> V_62 [ V_65 ] . V_48 = V_376 ;
return 0 ;
}
static struct V_58 * F_174 ( struct V_199 * V_193 )
{
int V_37 ;
struct V_58 * V_24 ;
if ( ! V_193 -> V_401 )
return NULL ;
V_24 = F_175 ( V_193 , sizeof( * V_24 ) , V_186 ) ;
if ( ! V_24 )
return F_176 ( - V_188 ) ;
V_37 = F_169 ( V_193 , V_24 ) ;
if ( V_37 ) {
F_144 ( V_24 -> V_62 ) ;
return F_176 ( V_37 ) ;
}
return V_24 ;
}
static struct V_58 * F_174 ( struct V_199 * V_193 )
{
return NULL ;
}
static int F_177 ( struct V_402 * V_193 )
{
struct V_1 * V_2 ;
struct V_58 * V_90 , * V_403 ;
struct V_404 * V_405 ;
int V_65 , V_294 , V_37 ;
F_154 ( & V_193 -> V_193 , L_92 ) ;
V_37 = - V_188 ;
V_403 = F_178 ( & V_193 -> V_193 ) ;
V_90 = F_179 ( & V_193 -> V_193 , sizeof( * V_90 ) , V_186 ) ;
if ( ! V_90 )
goto V_406;
if ( V_403 ) {
* V_90 = * V_403 ;
V_90 -> V_62 =
F_180 ( & V_193 -> V_193 , V_403 -> V_66 ,
sizeof( V_90 -> V_62 [ 0 ] ) , V_186 ) ;
if ( ! V_90 -> V_62 )
goto V_406;
for ( V_65 = 0 ; V_65 < V_90 -> V_66 ; V_65 ++ )
V_90 -> V_62 [ V_65 ] = V_403 -> V_62 [ V_65 ] ;
}
if ( ! V_403 )
V_90 = F_174 ( & V_193 -> V_193 ) ;
if ( F_181 ( V_90 ) )
goto V_406;
V_37 = F_153 ( & V_193 -> V_193 , V_371 , V_90 ) ;
if ( V_37 < 0 )
goto V_406;
F_159 ( & V_193 -> V_193 , V_90 ) ;
F_154 ( & V_193 -> V_193 , L_93 ,
V_90 -> V_62 -> V_67 ,
V_90 -> V_62 -> V_68 ,
V_90 -> V_62 -> V_48 ) ;
if ( V_90 -> V_62 -> V_67 == 0 ||
V_90 -> V_62 -> V_68 == 0 ||
V_90 -> V_62 -> V_48 == 0 ) {
F_79 ( & V_193 -> V_193 , L_94 ) ;
V_37 = - V_49 ;
goto V_406;
}
V_2 = F_141 ( & V_193 -> V_193 , V_90 ) ;
if ( ! V_2 ) {
F_79 ( & V_193 -> V_193 , L_95 ) ;
V_37 = - V_188 ;
goto V_406;
}
if ( F_71 () && V_90 -> V_407 )
V_2 -> V_25 . V_39 . V_343 = V_408 ;
V_2 -> V_289 = V_90 -> V_409 ;
V_2 -> V_290 = V_90 -> V_410 ;
V_405 = F_182 ( V_193 , V_411 , 0 ) ;
if ( V_405 == NULL ) {
F_79 ( & V_193 -> V_193 , L_96 ) ;
V_37 = - V_158 ;
goto V_412;
}
V_405 = F_183 ( V_405 -> V_119 , F_184 ( V_405 ) , V_193 -> V_351 ) ;
if ( V_405 == NULL ) {
F_79 ( & V_193 -> V_193 , L_97 ) ;
V_37 = - V_413 ;
goto V_412;
}
V_2 -> V_4 = F_185 ( V_405 -> V_119 , F_184 ( V_405 ) ) ;
if ( V_2 -> V_4 == NULL ) {
F_79 ( & V_193 -> V_193 , L_98 ) ;
V_37 = - V_413 ;
goto V_414;
}
V_2 -> V_415 = F_59 ( sizeof( struct V_205 ) ) ;
V_2 -> V_95 = F_186 ( V_2 -> V_193 , V_2 -> V_415 ,
& V_2 -> V_210 , V_186 ) ;
if ( V_2 -> V_95 == NULL ) {
F_79 ( & V_193 -> V_193 , L_99 ) ;
V_37 = - V_188 ;
goto V_416;
}
V_37 = F_138 ( V_2 ) ;
if ( V_37 ) {
F_79 ( & V_193 -> V_193 , L_100 , V_37 ) ;
V_37 = - V_188 ;
goto V_417;
}
V_294 = F_187 ( V_193 , 0 ) ;
if ( V_294 < 0 ) {
F_79 ( & V_193 -> V_193 , L_101 ) ;
V_37 = - V_158 ;
goto V_418;
}
V_37 = F_188 ( V_294 , F_128 , 0 , L_102 , V_2 ) ;
if ( V_37 ) {
F_79 ( & V_193 -> V_193 , L_103 , V_37 ) ;
V_37 = - V_413 ;
goto V_418;
}
V_37 = F_113 ( V_2 ) ;
if ( V_37 ) {
F_79 ( & V_193 -> V_193 , L_104 ) ;
goto V_419;
}
V_37 = F_27 ( & V_2 -> V_25 . V_27 , & V_2 -> V_25 ) ;
if ( V_37 ) {
F_79 ( & V_193 -> V_193 , L_105 ) ;
goto V_419;
}
V_37 = F_30 ( & V_2 -> V_25 ) ;
if ( V_37 ) {
F_79 ( & V_193 -> V_193 , L_106 ) ;
goto V_419;
}
F_189 ( V_193 , V_2 ) ;
V_37 = F_78 ( & V_2 -> V_25 ) ;
if ( V_37 < 0 ) {
F_79 ( & V_193 -> V_193 ,
L_107 , V_37 ) ;
goto V_420;
}
F_77 ( V_2 ) ;
#ifdef F_28
V_2 -> V_312 . V_421 = F_133 ;
V_2 -> V_315 . V_421 = F_135 ;
F_190 ( & V_2 -> V_312 ,
V_422 ) ;
F_190 ( & V_2 -> V_315 ,
V_423 ) ;
#endif
F_130 ( V_2 , V_9 ) ;
return 0 ;
V_420:
if ( V_2 -> V_25 . V_97 . V_424 )
F_31 ( & V_2 -> V_25 . V_97 ) ;
V_419:
F_191 ( V_294 , V_2 ) ;
V_418:
F_83 ( V_2 -> V_169 , V_2 -> V_170 ) ;
V_417:
F_192 ( & V_193 -> V_193 , V_2 -> V_415 ,
V_2 -> V_95 , V_2 -> V_210 ) ;
V_416:
F_193 ( V_2 -> V_4 ) ;
V_414:
F_194 ( V_405 -> V_119 , F_184 ( V_405 ) ) ;
V_412:
F_195 ( V_2 -> V_196 ) ;
F_144 ( V_2 ) ;
V_406:
return V_37 ;
}
static int F_196 ( struct V_402 * V_193 )
{
struct V_1 * V_2 = F_197 ( V_193 ) ;
struct V_404 * V_405 ;
int V_294 ;
struct V_23 * V_24 ;
if ( ! V_2 )
return 0 ;
V_24 = & V_2 -> V_25 ;
F_82 ( V_2 ) ;
F_80 ( V_24 ) ;
F_126 ( V_2 ) ;
if ( V_2 -> V_25 . V_97 . V_424 )
F_31 ( & V_2 -> V_25 . V_97 ) ;
V_294 = F_187 ( V_193 , 0 ) ;
F_191 ( V_294 , V_2 ) ;
F_83 ( V_2 -> V_169 , V_2 -> V_170 ) ;
F_198 ( & V_193 -> V_193 , V_2 -> V_415 ,
V_2 -> V_95 , V_2 -> V_210 ) ;
F_193 ( V_2 -> V_4 ) ;
V_405 = F_182 ( V_193 , V_411 , 0 ) ;
F_194 ( V_405 -> V_119 , F_184 ( V_405 ) ) ;
F_195 ( V_2 -> V_196 ) ;
F_144 ( V_2 ) ;
return 0 ;
}
static int T_6 F_199 ( void )
{
if ( F_156 () )
return - V_49 ;
return F_200 ( & V_425 ) ;
}
static void T_7 F_201 ( void )
{
F_202 ( & V_425 ) ;
}
