static inline unsigned int F_1 ( unsigned int V_1 )
{
return 0x70 + ( 2 * ( V_1 & 0x1 ) ) ;
}
static inline unsigned int F_2 ( unsigned int V_1 )
{
return 0x70 + ( 4 * ( V_1 & 0x1 ) ) ;
}
static inline unsigned int F_3 ( unsigned int V_1 )
{
return 0x72 + ( 4 * ( V_1 & 0x1 ) ) ;
}
static inline T_1 F_4 ( T_1 V_2 )
{
return V_2 & 0xfff ;
}
static inline T_1 F_5 ( unsigned int V_1 )
{
return ( V_1 & 0x3 ) << 8 ;
}
static inline T_1 F_6 ( unsigned int V_1 )
{
return ( V_1 & 0x3 ) << 10 ;
}
static inline T_1 F_7 ( unsigned int V_3 )
{
return ( V_3 & 0xf ) << 12 ;
}
static inline T_1 F_8 ( unsigned int V_4 )
{
return ( V_4 & 0xf ) << 3 ;
}
static inline T_1 F_9 ( unsigned int V_1 )
{
return ( V_1 & 0x3 ) << 8 ;
}
static inline T_1 F_10 ( unsigned int V_1 )
{
return V_1 & 0x3f ;
}
static inline T_1 F_11 ( T_1 V_5 )
{
return ( V_5 >> 10 ) & 0x3 ;
}
static inline unsigned int F_12 ( T_1 V_6 )
{
return ( V_6 >> 6 ) & 0x3 ;
}
static inline unsigned int F_13 ( T_1 V_6 )
{
return ( V_6 >> 12 ) & 0x3 ;
}
static inline unsigned int F_14 ( T_1 V_6 )
{
return ( V_6 >> 14 ) & 0x3 ;
}
static inline T_2 F_15 ( unsigned int V_4 )
{
return ( V_4 << 4 ) & V_7 ;
}
static inline T_2 F_16 ( unsigned int V_1 )
{
return 1 << ( V_1 & 0x3 ) ;
}
static inline unsigned int F_17 ( const struct V_8 * V_9 )
{
if ( V_9 -> V_10 == V_11 )
return V_12 ;
else
return V_13 ;
}
static inline unsigned short F_18 ( struct V_14 * V_15 ,
int V_16 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
if ( ( V_17 -> V_10 == V_18 && ! V_16 ) ||
( V_17 -> V_10 == V_19 && V_16 ) )
return V_20 ;
else
return 0 ;
}
static unsigned int F_20 ( const struct V_14 * V_15 ,
unsigned int V_21 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
const struct V_22 * V_23 =
& V_17 -> V_24 -> V_23 [ V_21 ] ;
unsigned int V_25 = 0 ;
switch ( V_23 -> V_26 ) {
case 10000000 :
V_25 = 0x000 ;
break;
case 5000000 :
V_25 = 0x100 ;
break;
case 2000000 :
case 2500000 :
V_25 = 0x200 ;
break;
case 1000000 :
case 1250000 :
V_25 = 0x300 ;
break;
case 500000 :
V_25 = 0x400 ;
break;
case 200000 :
case 250000 :
V_25 = 0x500 ;
break;
case 100000 :
V_25 = 0x600 ;
break;
case 50000 :
V_25 = 0x700 ;
break;
default:
F_21 ( V_15 , L_1 ) ;
break;
}
if ( V_23 -> V_27 == 0 )
V_25 += 0x900 ;
return V_25 ;
}
static unsigned int F_22 ( const struct V_14 * V_15 ,
T_1 V_5 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
if ( V_17 -> V_10 == V_11 )
return ( V_5 >> 13 ) & 0x7 ;
return ( V_5 >> 12 ) & 0xf ;
}
static void F_23 ( struct V_14 * V_15 ,
volatile T_1 * V_25 , unsigned int V_1 ,
unsigned int V_23 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
unsigned int V_28 = V_17 -> V_29 [ V_23 ] ;
if ( V_1 > 1 )
F_21 ( V_15 , L_2 ) ;
if ( V_28 & ~ 0x3 )
F_21 ( V_15 , L_3 ) ;
* V_25 &= ~ ( 0x3 << ( 2 * V_1 ) ) ;
* V_25 |= V_28 << ( 2 * V_1 ) ;
}
static inline int F_24 ( const struct V_8 * V_9 )
{
return V_9 -> V_30 && V_9 -> V_10 != V_11 ;
}
static void F_25 ( struct V_14 * V_15 , unsigned int V_1 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned long V_34 ;
F_26 ( & V_15 -> V_35 , V_34 ) ;
F_27 ( V_32 -> V_36 , V_1 ) ;
F_28 ( & V_15 -> V_35 , V_34 ) ;
}
static void F_29 ( struct V_14 * V_15 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
V_32 -> V_37 = 0 ;
F_30 ( V_32 -> V_37 ,
V_32 -> V_36 + V_38 ) ;
}
static void F_31 ( struct V_14 * V_15 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned long V_34 ;
F_26 ( & V_15 -> V_35 , V_34 ) ;
V_32 -> V_39 &=
~ V_40 & ~ V_41 &
~ V_42 & ~ V_43 &
~ V_44 & ~ V_45 ;
F_32 ( V_32 -> V_39 ,
V_32 -> V_46 + V_47 ) ;
F_28 ( & V_15 -> V_35 , V_34 ) ;
}
static void F_33 ( struct V_14 * V_15 ,
const struct V_48 * V_49 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
T_3 V_25 ;
unsigned long V_34 ;
V_25 = V_44 | V_41 |
V_42 | V_43 ;
if ( V_49 -> V_34 & V_50 ) {
if ( V_17 -> V_10 != V_11 )
V_25 |= V_51 | V_40 ;
}
F_26 ( & V_15 -> V_35 , V_34 ) ;
V_32 -> V_39 |= V_25 ;
F_32 ( V_32 -> V_39 ,
V_32 -> V_46 + V_47 ) ;
F_28 ( & V_15 -> V_35 , V_34 ) ;
}
static void F_34 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
T_3 V_25 ;
void T_4 * V_52 = V_32 -> V_36 ;
V_32 -> V_53 =
F_35 ( V_32 -> V_36 + V_54 ) ;
#ifdef F_36
V_25 = V_55 | V_56 ;
#else
V_25 = 0 ;
#endif
F_30 ( V_25 , V_32 -> V_36 + V_57 ) ;
F_29 ( V_15 ) ;
F_25 ( V_15 , 0 ) ;
F_25 ( V_15 , 1 ) ;
V_25 = 0 ;
V_25 |= V_58 ;
V_25 |= V_59 ;
V_25 |= V_60 ;
V_25 |= V_61 ;
V_25 |= V_62 ;
V_25 |= V_63 ;
V_25 |= V_64 ;
V_25 |= V_65 ;
if ( V_17 -> V_10 == V_11 )
V_25 |= V_66 ;
else
V_25 |= V_67 ;
F_30 ( V_25 , V_52 + V_68 ) ;
if ( F_24 ( V_17 ) )
F_30 ( V_25 , V_52 + V_69 ) ;
V_32 -> V_37 |=
V_70 | V_71 | V_72 | V_73 | V_74 | V_75 |
V_76 | V_77 ;
F_30 ( V_32 -> V_37 ,
V_32 -> V_36 + V_38 ) ;
}
static void F_37 ( struct V_14 * V_15 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned long V_34 ;
F_31 ( V_15 ) ;
F_26 ( & V_15 -> V_35 , V_34 ) ;
V_32 -> V_78 &= ~ V_79 ;
F_32 ( V_32 -> V_78 ,
V_32 -> V_46 + V_80 ) ;
F_28 ( & V_15 -> V_35 , V_34 ) ;
F_32 ( V_81 | V_82 | V_83 ,
V_32 -> V_46 + V_84 ) ;
}
static int F_38 ( struct V_14 * V_15 ,
unsigned int V_85 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
static const int V_86 = 0x100 ;
const struct V_87 * const V_88 = V_17 -> V_89 ;
unsigned int V_90 ;
T_1 V_25 ;
if ( V_85 < V_86 )
V_85 = V_86 ;
if ( V_85 > V_88 -> V_91 )
V_85 = V_88 -> V_91 ;
V_90 = ( V_85 + V_86 / 2 ) / V_86 ;
V_25 = ( ~ ( V_90 - 1 ) ) & V_88 -> V_92 ;
V_32 -> V_93 &= ~ V_88 -> V_92 ;
V_32 -> V_93 |= V_25 ;
F_32 ( V_32 -> V_93 ,
V_32 -> V_46 + V_94 ) ;
V_32 -> V_95 = V_90 * V_86 ;
return V_32 -> V_95 ;
}
static int F_39 ( struct V_14 * V_15 , unsigned int V_96 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
unsigned int V_97 ;
int V_98 ;
const struct V_87 * const V_88 = V_17 -> V_89 ;
V_97 = V_96 / V_88 -> V_99 ;
V_98 = F_38 ( V_15 ,
V_97 /
V_88 -> V_100 ) ;
if ( V_98 < 0 )
return V_98 ;
V_96 = V_98 * V_88 -> V_100 * V_88 -> V_99 ;
return V_96 ;
}
static unsigned int F_40 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
return V_32 -> V_95 *
V_17 -> V_89 -> V_100 *
V_17 -> V_89 -> V_99 ;
}
static void F_41 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
T_1 V_25 ;
unsigned long V_34 ;
F_26 ( & V_15 -> V_35 , V_34 ) ;
if ( 1 )
V_32 -> V_78 |= V_101 ;
F_32 ( V_32 -> V_78 ,
V_32 -> V_46 + V_80 ) ;
F_32 ( 0xff , V_32 -> V_46 + V_102 ) ;
V_25 = V_103 | V_104 ;
if ( V_17 -> V_10 == V_11 )
V_25 |= V_105 ;
V_32 -> V_106 |= V_25 ;
F_32 ( V_32 -> V_106 ,
V_32 -> V_46 + V_107 ) ;
F_32 ( 0 , V_32 -> V_46 + V_108 ) ;
F_32 ( 0 , V_32 -> V_46 + V_109 ) ;
F_28 ( & V_15 -> V_35 , V_34 ) ;
V_32 -> V_93 |= V_110 ;
F_38 ( V_15 ,
V_17 -> V_89 -> V_91 ) ;
V_32 -> V_111 = V_112 ;
V_32 -> V_39 =
V_113 | V_114 ;
F_32 ( V_32 -> V_39 ,
V_32 -> V_46 + V_47 ) ;
F_37 ( V_15 ) ;
}
static int F_42 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_115 * V_116 = F_43 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
int V_117 ;
for ( V_117 = 0 ; V_117 < F_17 ( V_17 ) ; V_117 ++ ) {
V_32 -> V_118 [ V_117 ] =
F_44 ( V_116 , V_119 ,
& V_32 -> V_120 [ V_117 ] ) ;
if ( V_32 -> V_118 [ V_117 ] == NULL )
return - V_121 ;
}
for ( V_117 = 0 ; V_117 < V_122 ; V_117 ++ ) {
if ( F_24 ( V_17 ) ) {
V_32 -> V_123 [ V_117 ] =
F_44 ( V_116 , V_119 ,
& V_32 ->
V_124 [ V_117 ] ) ;
if ( V_32 -> V_123 [ V_117 ] == NULL )
return - V_121 ;
}
}
V_32 -> V_125 =
F_44 ( V_116 , sizeof( struct V_126 ) *
F_17 ( V_17 ) ,
& V_32 -> V_127 ) ;
if ( V_32 -> V_125 == NULL )
return - V_121 ;
if ( F_24 ( V_17 ) ) {
V_32 -> V_128 =
F_44 ( V_116 ,
sizeof( struct V_126 ) *
V_122 ,
& V_32 -> V_129 ) ;
if ( V_32 -> V_128 == NULL )
return - V_121 ;
}
for ( V_117 = 0 ; V_117 < F_17 ( V_17 ) ; V_117 ++ ) {
V_32 -> V_125 [ V_117 ] . V_130 =
F_45 ( V_32 -> V_120 [ V_117 ] ) ;
if ( V_17 -> V_10 == V_11 )
V_32 -> V_125 [ V_117 ] . V_131 =
F_45 ( V_32 -> V_132 +
V_133 ) ;
else
V_32 -> V_125 [ V_117 ] . V_131 =
F_45 ( V_32 -> V_134 +
V_133 ) ;
V_32 -> V_125 [ V_117 ] . V_135 = F_45 ( 0 ) ;
V_32 -> V_125 [ V_117 ] . V_136 =
F_45 ( ( V_32 -> V_127 +
( ( V_117 + 1 ) % F_17 ( V_17 ) ) *
sizeof( V_32 -> V_125 [ 0 ] ) ) |
V_137 | V_138 |
V_139 ) ;
}
if ( F_24 ( V_17 ) ) {
for ( V_117 = 0 ; V_117 < V_122 ; V_117 ++ ) {
V_32 -> V_128 [ V_117 ] . V_130 =
F_45 ( V_32 -> V_124 [ V_117 ] ) ;
V_32 -> V_128 [ V_117 ] . V_131 =
F_45 ( V_32 -> V_134 +
V_140 ) ;
V_32 -> V_128 [ V_117 ] . V_135 = F_45 ( 0 ) ;
V_32 -> V_128 [ V_117 ] . V_136 =
F_45 ( ( V_32 -> V_129 +
( ( V_117 + 1 ) % ( V_122 ) ) *
sizeof( V_32 -> V_128 [ 0 ] ) ) |
V_137 |
V_138 ) ;
}
}
return 0 ;
}
static inline void F_46 ( struct V_14 * V_15 )
{
F_21 ( V_15 ,
L_4 ) ;
F_21 ( V_15 ,
L_5 ) ;
}
static void F_47 ( struct V_14 * V_15 , int V_141 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
static const int V_142 = V_143 ;
void T_4 * V_144 = V_32 -> V_36 +
V_54 ;
if ( V_141 ) {
V_32 -> V_53 &= ~ V_142 ;
F_30 ( V_32 -> V_53 , V_144 ) ;
F_48 ( V_145 ) ;
} else {
V_32 -> V_53 |= V_142 ;
F_30 ( V_32 -> V_53 , V_144 ) ;
F_48 ( V_146 ) ;
}
}
static void F_49 ( struct V_14 * V_15 , int V_141 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
static const int V_147 = V_148 ;
void T_4 * V_144 = V_32 -> V_36 +
V_54 ;
if ( V_141 ) {
V_32 -> V_53 &= ~ V_147 ;
F_30 ( V_32 -> V_53 , V_144 ) ;
F_48 ( V_145 ) ;
} else {
V_32 -> V_53 |= V_147 ;
F_30 ( V_32 -> V_53 , V_144 ) ;
F_48 ( V_146 ) ;
}
}
static void F_50 ( struct V_14 * V_15 , T_2 V_149 )
{
T_2 V_150 ;
unsigned int V_151 = 8 ;
for ( V_150 = 1 << ( V_151 - 1 ) ; V_150 ; V_150 >>= 1 ) {
F_49 ( V_15 , 0 ) ;
if ( ( V_149 & V_150 ) )
F_47 ( V_15 , 1 ) ;
else
F_47 ( V_15 , 0 ) ;
F_49 ( V_15 , 1 ) ;
}
}
static int F_51 ( struct V_14 * V_15 )
{
F_49 ( V_15 , 0 ) ;
F_47 ( V_15 , 1 ) ;
F_49 ( V_15 , 1 ) ;
return 0 ;
}
static void F_52 ( struct V_14 * V_15 )
{
F_49 ( V_15 , 1 ) ;
F_47 ( V_15 , 1 ) ;
F_47 ( V_15 , 0 ) ;
}
static void F_53 ( struct V_14 * V_15 )
{
F_49 ( V_15 , 0 ) ;
F_47 ( V_15 , 0 ) ;
F_49 ( V_15 , 1 ) ;
F_47 ( V_15 , 1 ) ;
}
static void F_54 ( struct V_14 * V_15 , unsigned int V_152 ,
const T_2 * V_153 , unsigned int V_154 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_117 ;
T_2 V_155 ;
static const int V_156 = 0x1 ;
V_32 -> V_53 &= ~ V_157 ;
F_53 ( V_15 ) ;
F_52 ( V_15 ) ;
V_155 = ( V_152 << 1 ) & ~ V_156 ;
F_50 ( V_15 , V_155 ) ;
if ( F_51 ( V_15 ) != 0 ) {
F_21 ( V_15 , L_6 ) ;
F_53 ( V_15 ) ;
return;
}
for ( V_117 = 0 ; V_117 < V_154 ; V_117 ++ ) {
F_50 ( V_15 , V_153 [ V_117 ] ) ;
if ( F_51 ( V_15 ) != 0 ) {
F_21 ( V_15 , L_6 ) ;
F_53 ( V_15 ) ;
return;
}
}
F_53 ( V_15 ) ;
}
static int F_55 ( struct V_14 * V_15 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
unsigned long V_162 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_163 ;
V_163 = F_56 ( V_32 -> V_46 + V_164 ) ;
if ( V_17 -> V_10 == V_11 ) {
V_163 = F_56 ( V_32 -> V_46 + V_165 ) ;
if ( V_163 )
return 0 ;
} else {
if ( F_11 ( V_163 ) )
return 0 ;
}
return - V_166 ;
}
static int F_57 ( struct V_14 * V_15 , struct V_158 * V_159 ,
struct V_160 * V_161 , unsigned int * V_153 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_25 = 0 , V_167 ;
unsigned int V_1 , V_23 , V_168 ;
unsigned long V_34 ;
int V_169 ;
V_1 = F_58 ( V_161 -> V_170 ) ;
V_23 = F_59 ( V_161 -> V_170 ) ;
V_168 = F_60 ( V_161 -> V_170 ) ;
F_37 ( V_15 ) ;
F_26 ( & V_15 -> V_35 , V_34 ) ;
if ( V_161 -> V_170 & V_171 )
V_32 -> V_78 |= V_172 ;
else
V_32 -> V_78 &= ~ V_172 ;
F_32 ( V_32 -> V_78 ,
V_32 -> V_46 + V_80 ) ;
F_28 ( & V_15 -> V_35 , V_34 ) ;
if ( V_17 -> V_10 != V_11 ) {
V_32 -> V_106 &= ~ V_173 ;
F_32 ( V_32 -> V_106 ,
V_32 -> V_46 + V_107 ) ;
if ( V_161 -> V_170 & V_174 ) {
unsigned int V_175 ;
if ( V_17 -> V_10 == V_19 )
V_175 = V_176 ;
else
V_175 = V_177 ;
F_32 ( V_175 |
F_8 ( V_32 -> V_178 ) ,
V_32 -> V_46 + V_109 ) ;
} else {
F_32 ( 0 , V_32 -> V_46 + V_109 ) ;
}
V_25 = 0 ;
V_25 |= F_20 ( V_15 , F_59 ( V_161 -> V_170 ) ) ;
V_25 |= F_18 ( V_15 , V_168 == V_179 ) ;
if ( V_168 == V_180 )
V_25 |= V_181 ;
V_25 |= F_10 ( V_1 ) ;
F_32 ( F_10 ( V_1 ) ,
V_32 -> V_46 + V_182 ) ;
F_32 ( V_25 , V_32 -> V_46 + V_183 ) ;
} else {
T_2 V_184 = V_32 -> V_185 ;
V_32 -> V_185 &= ~ V_7 ;
if ( V_161 -> V_170 & V_174 ) {
V_32 -> V_185 |=
F_15 ( V_32 -> V_178 ) ;
} else {
V_32 -> V_185 |= F_15 ( 4 ) ;
}
if ( V_23 == 0 )
V_32 -> V_185 |= F_16 ( V_1 ) ;
else
V_32 -> V_185 &= ~ F_16 ( V_1 ) ;
if ( V_184 != V_32 -> V_185 ) {
T_2 V_186 = V_32 -> V_185 ;
F_54 ( V_15 , V_187 , & V_186 ,
sizeof( V_186 ) ) ;
}
F_32 ( 0 , V_32 -> V_46 + V_102 ) ;
F_32 ( 2 , V_32 -> V_46 + V_188 ) ;
}
for ( V_167 = 0 ; V_167 < V_161 -> V_167 ; V_167 ++ ) {
F_32 ( 0 , V_32 -> V_46 + V_189 ) ;
F_32 ( F_9 ( F_58 ( V_161 -> V_170 ) ) ,
V_32 -> V_46 + V_190 ) ;
V_169 = F_61 ( V_15 , V_159 , V_161 , F_55 , 0 ) ;
if ( V_169 )
return V_169 ;
if ( V_17 -> V_10 == V_11 )
V_153 [ V_167 ] = F_35 ( V_32 -> V_191 +
V_133 ) & 0xffff ;
else
V_153 [ V_167 ] = F_56 ( V_32 -> V_46 + V_192 ) ;
}
return V_167 ;
}
static int F_62 ( struct V_14 * V_15 ,
unsigned int * V_153 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_4 = V_153 [ 1 ] ;
int V_193 ;
if ( V_17 -> V_10 == V_19 )
V_193 = 16 ;
else
V_193 = 8 ;
if ( V_4 >= V_193 ) {
F_63 ( V_15 -> V_194 , L_7 ,
V_4 ) ;
return - V_195 ;
}
V_32 -> V_178 = V_4 ;
return 2 ;
}
static int F_64 ( struct V_14 * V_15 , unsigned int * V_153 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
int V_196 ;
const struct V_87 * const V_88 = V_17 -> V_89 ;
unsigned int V_197 , V_198 ;
int V_98 ;
V_198 = V_153 [ 1 ] ;
if ( V_198 ) {
V_196 = V_198 * V_88 -> V_100 /
V_199 ;
V_98 = F_39 ( V_15 , V_196 ) ;
if ( V_98 < 0 )
return V_98 ;
}
V_197 = F_40 ( V_15 ) / V_88 -> V_100 * V_199 ;
V_153 [ 1 ] = V_197 ;
return 2 ;
}
static int F_65 ( struct V_14 * V_15 ,
unsigned int * V_153 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_200 = V_153 [ 4 ] ;
int V_98 = 0 ;
if ( V_200 < 2 ) {
V_200 = 2 ;
V_98 = - V_201 ;
}
switch ( V_153 [ 1 ] ) {
case V_202 :
V_32 -> V_203 . V_200 = V_200 ;
V_32 -> V_203 . V_170 = V_153 [ 2 ] ;
break;
default:
return - V_195 ;
break;
}
V_153 [ 4 ] = V_200 ;
return V_98 ? V_98 : 5 ;
}
static int F_66 ( struct V_14 * V_15 , unsigned int * V_153 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
switch ( V_17 -> V_10 ) {
case V_11 :
return F_65 ( V_15 , V_153 ) ;
break;
default:
return - V_195 ;
break;
}
return - V_195 ;
}
static int F_67 ( struct V_14 * V_15 , struct V_158 * V_159 ,
struct V_160 * V_161 , unsigned int * V_153 )
{
int V_204 = V_153 [ 0 ] ;
switch ( V_204 ) {
case V_205 :
return F_62 ( V_15 , V_153 ) ;
break;
case V_206 :
return F_64 ( V_15 , V_153 ) ;
break;
case V_207 :
return F_66 ( V_15 , V_153 ) ;
break;
default:
return - V_195 ;
break;
}
return - V_195 ;
}
static unsigned int F_68 ( unsigned int V_208 , unsigned int V_34 )
{
unsigned int V_200 ;
switch ( V_34 & V_209 ) {
case V_210 :
V_200 = ( V_208 + V_211 - 1 ) / V_211 ;
break;
case V_212 :
V_200 = V_208 / V_211 ;
break;
case V_213 :
default:
V_200 = ( V_208 + V_211 / 2 ) / V_211 ;
break;
}
return V_200 ;
}
static void F_69 ( struct V_14 * V_15 , struct V_48 * V_49 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
unsigned int V_214 = 0 , V_215 ;
static const int V_216 = 3 ;
static const int V_217 =
V_218 + V_216 ;
static const int V_219 = 2 ;
unsigned long long V_220 , V_221 ;
if ( V_49 -> V_222 == V_223 ) {
if ( V_17 -> V_10 == V_11 ) {
V_49 -> V_224 = 0 ;
} else {
V_214 = F_68 ( V_49 -> V_224 ,
V_49 -> V_34 ) ;
if ( V_214 > V_217 )
V_214 = V_217 ;
if ( V_214 < V_216 )
V_214 = V_216 ;
V_49 -> V_224 = V_214 * V_211 ;
}
} else if ( V_49 -> V_222 == V_225 ) {
V_49 -> V_224 = 0 ;
}
if ( V_49 -> V_226 == V_223 ) {
V_215 = F_68 ( V_49 -> V_227 , V_49 -> V_34 ) ;
if ( V_49 -> V_222 == V_223 ) {
V_221 = V_214 * V_49 -> V_228 ;
V_220 =
( V_214 * V_49 -> V_228 - 1 ) +
V_218 ;
} else {
V_221 = V_219 ;
V_220 = V_218 + V_221 ;
}
if ( V_215 > V_220 )
V_215 = V_220 ;
if ( V_215 < V_221 )
V_215 = V_221 ;
V_49 -> V_227 = V_215 * V_211 ;
}
return;
}
static int F_70 ( struct V_14 * V_15 , struct V_158 * V_159 ,
struct V_48 * V_49 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
int V_229 = 0 ;
unsigned int V_230 , V_231 ;
int V_117 ;
int V_168 ;
unsigned int V_232 ;
V_229 |= F_71 ( & V_49 -> V_233 , V_225 | V_234 ) ;
V_232 = V_223 ;
if ( V_17 -> V_10 == V_11 )
V_232 |= V_235 ;
else
V_232 |= V_236 ;
V_229 |= F_71 ( & V_49 -> V_226 , V_232 ) ;
V_232 = V_223 ;
if ( V_17 -> V_10 == V_11 )
V_232 |= V_225 ;
else
V_232 |= V_234 ;
V_229 |= F_71 ( & V_49 -> V_222 , V_232 ) ;
V_229 |= F_71 ( & V_49 -> V_237 , V_238 ) ;
V_229 |= F_71 ( & V_49 -> V_239 ,
V_238 | V_234 | V_240 ) ;
if ( V_229 )
return 1 ;
V_229 |= F_72 ( V_49 -> V_233 ) ;
V_229 |= F_72 ( V_49 -> V_226 ) ;
V_229 |= F_72 ( V_49 -> V_222 ) ;
V_229 |= F_72 ( V_49 -> V_239 ) ;
if ( V_49 -> V_222 == V_234 && V_49 -> V_226 == V_223 )
V_229 |= - V_195 ;
if ( V_49 -> V_239 != V_238 &&
V_49 -> V_239 != V_240 && V_49 -> V_239 != V_234 )
V_229 |= - V_195 ;
if ( V_229 )
return 2 ;
if ( V_49 -> V_222 == V_223 ) {
if ( V_17 -> V_10 == V_11 ) {
V_229 |= F_73 ( & V_49 -> V_224 , 0 ) ;
} else {
V_229 |= F_74 ( & V_49 -> V_224 ,
V_17 -> V_241 ) ;
if ( V_49 -> V_226 == V_223 )
V_229 |= F_74 (
& V_49 -> V_227 ,
V_49 -> V_224 *
V_49 -> V_228 ) ;
}
}
V_229 |= F_74 ( & V_49 -> V_228 , 1 ) ;
V_229 |= F_73 ( & V_49 -> V_242 , V_49 -> V_228 ) ;
switch ( V_49 -> V_239 ) {
case V_234 :
break;
case V_238 :
V_229 |= F_74 ( & V_49 -> V_243 , 1 ) ;
break;
case V_240 :
V_229 |= F_73 ( & V_49 -> V_243 , 0 ) ;
break;
default:
break;
}
if ( V_229 )
return 3 ;
if ( V_49 -> V_222 == V_223 ) {
V_230 = V_49 -> V_224 ;
V_231 = V_49 -> V_227 ;
F_69 ( V_15 , V_49 ) ;
if ( V_230 != V_49 -> V_224 )
V_229 ++ ;
if ( V_231 != V_49 -> V_227 )
V_229 ++ ;
}
if ( V_229 )
return 4 ;
if ( V_49 -> V_244 ) {
V_168 = F_60 ( V_49 -> V_244 [ 0 ] ) ;
for ( V_117 = 1 ; V_117 < V_49 -> V_228 ; V_117 ++ ) {
if ( V_168 != F_60 ( V_49 -> V_244 [ V_117 ] ) ) {
F_21 ( V_15 ,
L_8 ) ;
V_229 ++ ;
break;
}
}
if ( V_17 -> V_10 == V_11 ) {
unsigned int V_245 = F_58 ( V_49 -> V_244 [ 0 ] ) ;
for ( V_117 = 1 ; V_117 < V_49 -> V_228 ; V_117 ++ ) {
if ( F_58 ( V_49 -> V_244 [ V_117 ] ) !=
V_245 + V_117 ) {
F_21 ( V_15 ,
L_9 ) ;
V_229 ++ ;
break;
}
}
if ( V_49 -> V_228 == 3 ) {
F_21 ( V_15 ,
L_10 ) ;
V_229 ++ ;
}
}
}
if ( V_229 )
return 5 ;
return 0 ;
}
static int F_75 ( struct V_48 * V_49 )
{
return 0 ;
if ( V_49 -> V_239 == V_238 && V_49 -> V_243 <= V_218 )
return 1 ;
else
return 0 ;
}
static void F_76 ( struct V_14 * V_15 ,
struct V_48 * V_49 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
if ( V_49 -> V_239 == V_238 ) {
V_32 -> V_246 = V_49 -> V_243 * V_49 -> V_228 ;
}
if ( F_75 ( V_49 ) ) {
F_32 ( V_49 -> V_243 & 0xffff ,
V_32 -> V_46 + V_247 ) ;
F_32 ( ( V_49 -> V_243 >> 16 ) & 0xff ,
V_32 -> V_46 + V_248 ) ;
} else {
F_32 ( 1 , V_32 -> V_46 + V_247 ) ;
}
}
static inline unsigned int F_77 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_96 ;
V_96 = V_32 -> V_95 *
V_17 -> V_89 -> V_99 ;
if ( V_96 > V_119 / sizeof( T_1 ) )
V_96 = V_119 / sizeof( T_1 ) ;
return V_96 ;
}
static T_3 F_78 ( const struct V_14 * V_15 ,
const struct V_48 * V_49 )
{
return V_49 -> V_224 / V_211 - 3 ;
}
static T_3 F_79 ( struct V_14 * V_15 ,
struct V_48 * V_49 )
{
T_3 V_249 ;
switch ( V_49 -> V_226 ) {
case V_223 :
V_249 = ( V_49 -> V_227 -
( V_49 -> V_224 * ( V_49 -> V_228 - 1 ) ) ) /
V_211 ;
break;
case V_236 :
V_249 = V_49 -> V_224 / V_211 ;
break;
default:
return 0 ;
break;
}
return V_249 - 3 ;
}
static T_3 F_80 ( struct V_14 * V_15 ,
struct V_48 * V_49 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_200 ;
switch ( V_49 -> V_226 ) {
case V_223 :
V_200 = V_49 -> V_227 / V_211 ;
break;
case V_235 :
V_200 = V_32 -> V_203 . V_200 ;
break;
default:
F_21 ( V_15 , L_11 ) ;
V_200 = 1000 ;
break;
}
return V_200 - 2 ;
}
static void F_81 ( struct V_14 * V_15 ,
const struct V_48 * V_49 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
V_32 -> V_106 &= ~ V_250 ;
if ( V_49 -> V_226 == V_235 ) {
int V_170 = V_32 -> V_203 . V_170 ;
if ( F_58 ( V_170 ) )
V_32 -> V_106 |= V_251 ;
else
V_32 -> V_106 |= V_252 ;
} else {
V_32 -> V_106 |= V_105 ;
}
F_32 ( V_32 -> V_106 ,
V_32 -> V_46 + V_107 ) ;
}
static void F_82 ( struct V_14 * V_15 ,
const struct V_48 * V_49 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
switch ( V_17 -> V_10 ) {
case V_11 :
F_81 ( V_15 , V_49 ) ;
break;
default:
break;
}
}
static inline void F_83 ( struct V_14 * V_15 ,
unsigned int V_1 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned long V_34 ;
F_26 ( & V_15 -> V_35 , V_34 ) ;
if ( V_1 )
F_84 ( V_253 | V_254 |
V_255 ,
V_32 -> V_36 + V_256 ) ;
else
F_84 ( V_253 | V_254 |
V_255 ,
V_32 -> V_36 + V_257 ) ;
F_28 ( & V_15 -> V_35 , V_34 ) ;
}
static void F_85 ( struct V_14 * V_15 , struct V_48 * V_49 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
T_3 V_258 = 0 , V_259 = 0 ;
F_69 ( V_15 , V_49 ) ;
F_82 ( V_15 , V_49 ) ;
if ( V_17 -> V_10 == V_11 ) {
V_258 = F_80 ( V_15 , V_49 ) ;
} else {
V_258 = F_78 ( V_15 , V_49 ) ;
V_259 = F_79 ( V_15 , V_49 ) ;
}
F_32 ( V_258 & 0xffff ,
V_32 -> V_46 + V_188 ) ;
F_32 ( ( V_258 >> 16 ) & 0xff ,
V_32 -> V_46 + V_102 ) ;
F_32 ( V_259 & 0xffff ,
V_32 -> V_46 + V_260 ) ;
F_32 ( ( V_259 >> 16 ) & 0xff ,
V_32 -> V_46 + V_261 ) ;
}
static int F_86 ( const struct V_48 * V_49 )
{
int V_117 ;
for ( V_117 = 0 ; V_117 + 1 < V_49 -> V_228 ; V_117 ++ ) {
if ( F_58 ( V_49 -> V_244 [ V_117 + 1 ] ) !=
F_58 ( V_49 -> V_244 [ V_117 ] ) + 1 )
return 0 ;
if ( F_59 ( V_49 -> V_244 [ V_117 + 1 ] ) !=
F_59 ( V_49 -> V_244 [ V_117 ] ) )
return 0 ;
if ( F_60 ( V_49 -> V_244 [ V_117 + 1 ] ) != F_60 ( V_49 -> V_244 [ V_117 ] ) )
return 0 ;
}
return 1 ;
}
static int F_87 ( struct V_14 * V_15 ,
const struct V_48 * V_49 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned short V_25 ;
int V_117 ;
if ( V_17 -> V_10 != V_11 ) {
if ( F_86 ( V_49 ) ) {
V_32 -> V_106 &= ~ V_173 ;
F_32 ( V_32 -> V_106 ,
V_32 -> V_46 + V_107 ) ;
V_25 = 0 ;
V_25 |= F_10 ( F_58 ( V_49 -> V_244 [ 0 ] ) ) ;
V_25 |= F_20 ( V_15 ,
F_59 ( V_49 -> V_244 [ 0 ] ) ) ;
V_25 |= F_18 ( V_15 ,
F_60 ( V_49 -> V_244 [ 0 ] ) ==
V_179 ) ;
if ( F_60 ( V_49 -> V_244 [ 0 ] ) == V_180 )
V_25 |= V_181 ;
F_32 ( F_10
( F_58 ( V_49 -> V_244 [ V_49 -> V_228 - 1 ] ) ) ,
V_32 -> V_46 + V_182 ) ;
F_32 ( V_25 ,
V_32 -> V_46 + V_183 ) ;
} else {
if ( V_15 -> V_262 && V_15 -> V_262 -> V_263 ) {
F_46 ( V_15 ) ;
return - V_166 ;
}
V_32 -> V_106 |= V_173 ;
F_32 ( V_32 -> V_106 ,
V_32 -> V_46 + V_107 ) ;
F_32 ( 0 ,
V_32 -> V_46 + V_264 ) ;
F_32 ( 0 , V_32 -> V_46 + V_265 ) ;
for ( V_117 = 0 ; V_117 < V_49 -> V_228 ; V_117 ++ ) {
V_25 = 0 ;
V_25 |= F_10 ( F_58 ( V_49 ->
V_244 [ V_117 ] ) ) ;
V_25 |= F_20 ( V_15 ,
F_59 ( V_49 ->
V_244
[ V_117 ] ) ) ;
V_25 |= F_18 ( V_15 ,
F_60 ( V_49 ->
V_244 [ V_117 ] ) ==
V_179 ) ;
if ( F_60 ( V_49 -> V_244 [ V_117 ] ) == V_180 )
V_25 |= V_181 ;
if ( V_117 == V_49 -> V_228 - 1 )
V_25 |= V_266 |
V_267 ;
F_32 ( V_25 ,
V_32 -> V_46 +
V_268 ) ;
}
F_32 ( 0 , V_32 -> V_46 + V_265 ) ;
F_32 ( 0 , V_32 -> V_46 + V_183 ) ;
}
} else {
unsigned short V_184 = V_32 -> V_185 ;
V_32 -> V_185 &= ~ V_7 ;
V_32 -> V_185 |= F_15 ( 4 ) ;
for ( V_117 = 0 ; V_117 < V_49 -> V_228 ; V_117 ++ ) {
unsigned int V_1 = F_58 ( V_49 -> V_244 [ V_117 ] ) ;
unsigned int V_23 = F_59 ( V_49 -> V_244 [ V_117 ] ) ;
if ( V_23 == 0 )
V_32 -> V_185 |=
F_16 ( V_1 ) ;
else
V_32 -> V_185 &=
~ F_16 ( V_1 ) ;
}
if ( V_184 != V_32 -> V_185 ) {
T_2 V_186 = V_32 -> V_185 ;
F_54 ( V_15 , V_187 , & V_186 ,
sizeof( V_186 ) ) ;
}
}
return 0 ;
}
static inline void F_88 ( struct V_14 * V_15 ,
unsigned int V_269 ,
unsigned int V_270 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
if ( V_269 ) {
F_30 ( 0 ,
V_32 -> V_36 + V_271 ) ;
F_30 ( 0 , V_32 -> V_36 + V_272 ) ;
F_30 ( 0 ,
V_32 -> V_36 + V_273 ) ;
F_30 ( V_270 ,
V_32 -> V_36 + V_274 ) ;
} else {
F_30 ( 0 ,
V_32 -> V_36 + V_275 ) ;
F_30 ( 0 , V_32 -> V_36 + V_276 ) ;
F_30 ( 0 ,
V_32 -> V_36 + V_277 ) ;
F_30 ( V_270 ,
V_32 -> V_36 + V_278 ) ;
}
}
static int F_89 ( struct V_14 * V_15 , struct V_158 * V_159 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
struct V_279 * V_280 = V_159 -> V_280 ;
struct V_48 * V_49 = & V_280 -> V_49 ;
T_3 V_25 ;
unsigned int V_117 ;
unsigned long V_34 ;
int V_98 ;
F_37 ( V_15 ) ;
F_25 ( V_15 , 1 ) ;
V_98 = F_87 ( V_15 , V_49 ) ;
if ( V_98 < 0 )
return V_98 ;
F_32 ( 0 , V_32 -> V_46 + V_109 ) ;
F_85 ( V_15 , V_49 ) ;
F_76 ( V_15 , V_49 ) ;
F_33 ( V_15 , V_49 ) ;
F_26 ( & V_15 -> V_35 , V_34 ) ;
V_32 -> V_78 |= V_79 ;
V_32 -> V_78 &= ~ V_172 ;
if ( V_17 -> V_10 != V_11 ) {
V_32 -> V_78 &= ~ V_281 ;
if ( V_49 -> V_222 == V_234 )
V_32 -> V_78 |= F_7 ( 13 ) ;
else
V_32 -> V_78 |= F_7 ( 8 ) ;
} else {
V_32 -> V_78 &= ~ V_282 ;
if ( V_49 -> V_228 == 4 )
V_32 -> V_78 |= V_283 ;
else if ( V_49 -> V_228 == 2 )
V_32 -> V_78 |= V_284 ;
V_32 -> V_78 &= ~ V_285 ;
V_32 -> V_78 |=
F_5 ( F_58 ( V_49 -> V_244 [ 0 ] ) ) ;
V_32 -> V_78 &= ~ V_286 ;
V_32 -> V_78 |=
F_6 ( F_58 ( V_49 -> V_244
[ V_49 -> V_228 - 1 ] ) ) ;
}
F_32 ( V_32 -> V_78 ,
V_32 -> V_46 + V_80 ) ;
F_28 ( & V_15 -> V_35 , V_34 ) ;
F_32 ( 0 , V_32 -> V_46 + V_189 ) ;
if ( ( V_49 -> V_34 & V_50 ) == 0 ||
V_17 -> V_10 == V_11 ) {
V_32 -> V_287 = 0 ;
for ( V_117 = 0 ; V_117 < F_17 ( V_17 ) ; V_117 ++ )
V_32 -> V_125 [ V_117 ] . V_135 =
F_45 ( F_77 ( V_15 ) *
sizeof( T_1 ) ) ;
F_88 ( V_15 , 1 ,
V_32 -> V_127 |
V_137 |
V_138 |
V_139 ) ;
F_83 ( V_15 , 1 ) ;
}
if ( V_17 -> V_10 == V_11 ) {
V_25 = 0 ;
if ( V_49 -> V_233 == V_234 && F_58 ( V_49 -> V_288 ) )
V_25 |= V_289 ;
if ( V_49 -> V_239 == V_234 && F_58 ( V_49 -> V_243 ) )
V_25 |= V_290 ;
F_32 ( V_25 , V_32 -> V_46 + V_291 ) ;
}
F_26 ( & V_15 -> V_35 , V_34 ) ;
V_25 = V_292 | V_82 | V_83 ;
if ( V_49 -> V_34 & V_50 )
V_25 |= V_81 ;
if ( V_49 -> V_233 == V_234 ) {
V_25 |= V_293 ;
if ( V_49 -> V_288 & V_294 )
V_25 |= V_295 ;
} else if ( V_49 -> V_233 == V_225 )
V_25 |= V_296 ;
if ( F_75 ( V_49 ) )
V_25 |= V_297 ;
F_32 ( V_25 , V_32 -> V_46 + V_84 ) ;
V_32 -> V_298 = 1 ;
F_28 ( & V_15 -> V_35 , V_34 ) ;
if ( V_49 -> V_233 == V_225 )
F_32 ( 0 , V_32 -> V_46 + V_299 ) ;
return 0 ;
}
static void F_90 ( struct V_14 * V_15 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
struct V_158 * V_159 = V_15 -> V_300 ;
struct V_279 * V_280 = V_159 -> V_280 ;
struct V_48 * V_49 = & V_280 -> V_49 ;
unsigned int V_117 ;
T_1 V_6 ;
int V_301 , V_302 , V_303 , V_304 ;
int V_96 ;
do {
V_302 = F_56 ( V_32 -> V_46 + V_305 ) &
0x7fff ;
V_304 = F_56 ( V_32 -> V_46 + V_165 ) &
0x7fff ;
V_6 = F_56 ( V_32 -> V_46 + V_306 ) ;
V_301 = F_13 ( V_6 ) ;
V_303 = F_14 ( V_6 ) ;
if ( V_301 != V_303 )
V_96 =
V_32 -> V_95 - V_302 ;
else
V_96 = V_304 - V_302 ;
if ( V_49 -> V_239 == V_238 ) {
if ( V_32 -> V_246 == 0 )
break;
if ( V_96 > V_32 -> V_246 )
V_96 = V_32 -> V_246 ;
V_32 -> V_246 -= V_96 ;
}
if ( V_96 < 0 ) {
F_91 ( V_15 -> V_194 ,
L_12 ) ;
break;
}
for ( V_117 = 0 ; V_117 < V_96 ; V_117 ++ ) {
F_92 ( V_159 ,
F_56 ( V_32 -> V_46 +
V_133 ) ) ;
}
} while ( V_301 != V_303 );
}
static void F_93 ( struct V_14 * V_15 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
struct V_158 * V_159 = V_15 -> V_300 ;
struct V_279 * V_280 = V_159 -> V_280 ;
struct V_48 * V_49 = & V_280 -> V_49 ;
unsigned int V_117 ;
unsigned int V_307 = 100000 ;
T_3 V_308 ;
int V_309 =
F_56 ( V_32 -> V_46 + V_165 ) & 0x7fff ;
int V_310 =
F_56 ( V_32 -> V_46 + V_305 ) & 0x7fff ;
if ( V_49 -> V_239 == V_238 ) {
if ( V_307 > V_32 -> V_246 )
V_307 = V_32 -> V_246 ;
}
for ( V_117 = 0 ; V_310 != V_309 && V_117 < V_307 ; ) {
V_308 = F_35 ( V_32 -> V_191 + V_133 ) ;
F_92 ( V_159 , V_308 & 0xffff ) ;
V_117 ++ ;
if ( V_117 < V_307 ) {
F_92 ( V_159 , ( V_308 >> 16 ) & 0xffff ) ;
V_117 ++ ;
}
V_310 = F_56 ( V_32 -> V_46 + V_305 ) &
0x7fff ;
}
V_32 -> V_246 -= V_117 ;
}
static void F_94 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
if ( V_17 -> V_10 == V_11 )
F_93 ( V_15 ) ;
else
F_90 ( V_15 ) ;
}
static void F_95 ( struct V_14 * V_15 , unsigned int V_1 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
struct V_279 * V_280 = V_15 -> V_300 -> V_280 ;
T_3 V_311 ;
int V_312 ;
int V_96 = 0 ;
void T_4 * V_313 ;
if ( V_1 )
V_313 =
V_32 -> V_36 + V_272 ;
else
V_313 =
V_32 -> V_36 + V_276 ;
for ( V_312 = 0 , V_311 = F_35 ( V_313 ) ;
( V_311 <
V_32 -> V_120 [ V_32 -> V_287 ] ||
V_311 >=
V_32 -> V_120 [ V_32 -> V_287 ] +
V_119 ) && V_312 < F_17 ( V_17 ) ; V_312 ++ ) {
V_96 = F_77 ( V_15 ) ;
if ( V_280 -> V_49 . V_239 == V_238 ) {
if ( V_96 > V_32 -> V_246 )
V_96 = V_32 -> V_246 ;
V_32 -> V_246 -= V_96 ;
}
F_96 ( V_15 -> V_300 ,
V_32 -> V_118 [ V_32 ->
V_287 ] ,
V_96 * sizeof( T_1 ) ) ;
V_32 -> V_287 = ( V_32 -> V_287 + 1 ) %
F_17 ( V_17 ) ;
}
}
static void F_97 ( struct V_14 * V_15 ,
unsigned short V_163 ,
unsigned int V_314 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
struct V_158 * V_159 = V_15 -> V_300 ;
struct V_279 * V_280 = V_159 -> V_280 ;
struct V_48 * V_49 = & V_280 -> V_49 ;
T_2 V_315 ;
unsigned long V_34 ;
if ( V_163 & V_316 ) {
F_21 ( V_15 , L_13 ) ;
V_280 -> V_317 |= V_318 | V_319 ;
}
F_26 ( & V_15 -> V_35 , V_34 ) ;
V_315 = F_98 ( V_32 -> V_36 + V_256 ) ;
if ( V_314 & V_320 ) {
F_84 ( ( V_315 & V_253 ) | V_255 ,
V_32 -> V_36 + V_256 ) ;
if ( V_315 & V_253 )
F_95 ( V_15 , 1 ) ;
}
F_28 ( & V_15 -> V_35 , V_34 ) ;
if ( ( V_163 & V_321 ) ||
( ( V_49 -> V_34 & V_50 ) &&
( V_163 & V_322 ) &&
( V_17 -> V_10 != V_11 ) ) ) {
F_26 ( & V_15 -> V_35 , V_34 ) ;
if ( V_32 -> V_298 ) {
F_28 ( & V_15 -> V_35 , V_34 ) ;
F_94 ( V_15 ) ;
} else
F_28 ( & V_15 -> V_35 , V_34 ) ;
}
if ( ( V_49 -> V_239 == V_238 && ( int ) V_32 -> V_246 <= 0 ) ||
( V_49 -> V_239 == V_234 && ( V_163 & V_323 ) ) ) {
V_280 -> V_317 |= V_318 ;
}
F_99 ( V_15 , V_159 ) ;
}
static inline unsigned int F_100 ( struct V_14 * V_15 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_324 ;
if ( V_32 -> V_325 == 0 )
V_324 = V_122 - 1 ;
else
V_324 = V_32 -> V_325 - 1 ;
return V_324 ;
}
static int F_101 ( struct V_14 * V_15 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_324 ;
unsigned int V_326 ;
unsigned short V_327 ;
V_324 = F_100 ( V_15 ) ;
V_327 = F_98 ( V_32 -> V_36 + V_257 ) ;
if ( ( V_327 & V_328 ) == 0 )
return 0 ;
V_326 =
F_35 ( V_32 -> V_36 + V_276 ) ;
if ( V_326 != V_32 -> V_124 [ V_324 ] )
return 0 ;
return 1 ;
}
static int F_102 ( struct V_14 * V_15 ,
const struct V_48 * V_49 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
if ( V_49 -> V_239 == V_240 )
return 1 ;
if ( V_49 -> V_239 == V_238 ) {
if ( V_32 -> V_329 )
return 1 ;
if ( F_101 ( V_15 ) == 0 )
return 1 ;
}
return 0 ;
}
static inline int F_103 ( struct V_14 * V_15 ,
unsigned short V_327 )
{
if ( ( V_327 & V_328 ) == 0 ||
( V_327 & V_253 ) == 0 )
return 0 ;
if ( F_101 ( V_15 ) )
return 0 ;
return 1 ;
}
static void F_104 ( struct V_14 * V_15 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_330 ;
V_330 =
F_35 ( V_32 -> V_36 + V_278 ) ;
V_330 &= ~ V_331 ;
F_88 ( V_15 , 0 , V_330 ) ;
F_83 ( V_15 , 0 ) ;
}
static unsigned int F_105 ( struct V_14 * V_15 ,
const struct V_48 * V_49 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_332 , V_324 , V_333 ;
unsigned int V_334 ;
V_324 = V_32 -> V_325 ;
V_333 = F_100 ( V_15 ) ;
V_332 = F_106 ( V_15 -> V_262 -> V_280 ) ;
if ( V_332 > V_119 )
V_332 = V_119 ;
if ( V_49 -> V_239 == V_238 && V_332 > V_32 -> V_329 )
V_332 = V_32 -> V_329 ;
V_332 -= V_332 % V_199 ;
if ( V_332 == 0 )
return 0 ;
V_332 = F_107 ( V_15 -> V_262 ,
V_32 ->
V_123 [ V_324 ] ,
V_332 ) ;
V_32 -> V_128 [ V_324 ] . V_135 =
F_45 ( V_332 ) ;
V_334 = F_108 ( V_32 -> V_128 [ V_324 ] . V_136 ) ;
V_334 |= V_331 ;
V_32 -> V_128 [ V_324 ] . V_136 = F_45 ( V_334 ) ;
V_334 = F_108 ( V_32 -> V_128 [ V_333 ] . V_136 ) ;
V_334 &= ~ V_331 ;
V_32 -> V_128 [ V_333 ] . V_136 = F_45 ( V_334 ) ;
V_32 -> V_325 = ( V_324 + 1 ) % V_122 ;
V_32 -> V_329 -= V_332 ;
return V_332 ;
}
static void F_109 ( struct V_14 * V_15 , const struct V_48 * V_49 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_332 ;
unsigned int V_311 ;
void T_4 * V_313 =
V_32 -> V_36 + V_276 ;
unsigned int V_324 ;
do {
V_324 = V_32 -> V_325 ;
V_311 = F_35 ( V_313 ) ;
if ( V_311 >=
V_32 -> V_124 [ V_324 ] &&
V_311 <
V_32 -> V_124 [ V_324 ] +
V_119 )
return;
V_332 = F_105 ( V_15 , V_49 ) ;
} while ( V_332 >= V_119 );
}
static void F_110 ( struct V_14 * V_15 ,
unsigned short V_163 , unsigned int V_314 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
struct V_158 * V_159 = V_15 -> V_262 ;
struct V_279 * V_280 ;
struct V_48 * V_49 ;
T_2 V_335 ;
unsigned long V_34 ;
if ( V_159 == NULL )
return;
V_280 = V_159 -> V_280 ;
V_49 = & V_280 -> V_49 ;
F_26 ( & V_15 -> V_35 , V_34 ) ;
V_335 = F_98 ( V_32 -> V_36 + V_257 ) ;
if ( V_314 & V_336 ) {
if ( ( V_335 & V_253 ) &&
! ( V_335 & V_328 ) )
F_84 ( V_253 | V_255 ,
V_32 -> V_36 + V_257 ) ;
else
F_84 ( V_255 ,
V_32 -> V_36 + V_257 ) ;
F_28 ( & V_15 -> V_35 , V_34 ) ;
if ( V_335 & V_253 ) {
F_109 ( V_15 , V_49 ) ;
if ( F_103 ( V_15 , V_335 ) )
F_104 ( V_15 ) ;
}
} else {
F_28 ( & V_15 -> V_35 , V_34 ) ;
}
if ( ( V_163 & V_337 ) ) {
V_280 -> V_317 |= V_318 ;
if ( F_102 ( V_15 , V_49 ) )
V_280 -> V_317 |= V_319 ;
}
F_99 ( V_15 , V_159 ) ;
}
static T_5 F_111 ( int V_338 , void * V_339 )
{
struct V_14 * V_15 = V_339 ;
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned short V_163 ;
T_3 V_314 ;
T_3 V_340 ;
V_314 = F_35 ( V_32 -> V_36 + V_38 ) ;
V_163 = F_56 ( V_32 -> V_46 + V_164 ) ;
if ( ! V_15 -> V_341 )
return V_342 ;
F_97 ( V_15 , V_163 , V_314 ) ;
F_110 ( V_15 , V_163 , V_314 ) ;
if ( V_314 & V_343 ) {
V_340 = F_35 ( V_32 -> V_36 + V_344 ) ;
F_30 ( V_340 , V_32 -> V_36 + V_344 ) ;
}
return V_342 ;
}
static int F_112 ( struct V_14 * V_15 , struct V_158 * V_159 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned long V_34 ;
F_26 ( & V_15 -> V_35 , V_34 ) ;
if ( V_32 -> V_298 == 0 ) {
F_28 ( & V_15 -> V_35 , V_34 ) ;
return 0 ;
}
V_32 -> V_298 = 0 ;
F_28 ( & V_15 -> V_35 , V_34 ) ;
F_37 ( V_15 ) ;
F_25 ( V_15 , 1 ) ;
return 0 ;
}
static int F_113 ( struct V_14 * V_15 , struct V_158 * V_159 ,
struct V_160 * V_161 , unsigned int * V_153 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
int V_345 = F_58 ( V_161 -> V_170 ) ;
int V_23 = F_59 ( V_161 -> V_170 ) ;
F_32 ( 0 , V_32 -> V_46 + V_346 ) ;
F_23 ( V_15 , & V_32 -> V_111 , V_345 , V_23 ) ;
F_32 ( V_32 -> V_111 ,
V_32 -> V_46 + V_347 ) ;
if ( V_17 -> V_10 == V_11 ) {
F_32 ( V_153 [ 0 ] & 0xff ,
V_32 -> V_46 + F_2 ( V_345 ) ) ;
F_32 ( ( V_153 [ 0 ] >> 8 ) & 0xf ,
V_32 -> V_46 + F_3 ( V_345 ) ) ;
} else {
F_32 ( V_153 [ 0 ] , V_32 -> V_46 + F_1 ( V_345 ) ) ;
}
V_32 -> V_348 [ V_345 ] = V_153 [ 0 ] ;
return 1 ;
}
static int F_114 ( struct V_14 * V_15 ,
struct V_158 * V_159 ,
struct V_160 * V_161 , unsigned int * V_153 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
V_153 [ 0 ] = V_32 -> V_348 [ F_58 ( V_161 -> V_170 ) ] ;
return 1 ;
}
static void F_115 ( struct V_14 * V_15 ,
const struct V_48 * V_49 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_25 = V_349 | V_350 |
V_351 | V_352 ;
if ( V_49 -> V_233 == V_234 ) {
V_25 |= V_353 ;
if ( V_49 -> V_288 & V_294 )
V_25 |= V_354 ;
} else {
V_25 |= V_355 ;
}
if ( V_49 -> V_226 == V_234 ) {
V_25 |= V_356 ;
if ( V_49 -> V_227 & V_294 )
V_25 |= V_357 ;
}
F_32 ( V_25 , V_32 -> V_46 + V_346 ) ;
}
static void F_116 ( struct V_14 * V_15 ,
const struct V_48 * V_49 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
int V_117 ;
for ( V_117 = 0 ; V_117 < V_49 -> V_228 ; V_117 ++ ) {
int V_1 , V_23 ;
V_1 = F_58 ( V_49 -> V_244 [ V_117 ] ) ;
V_23 = F_59 ( V_49 -> V_244 [ V_117 ] ) ;
F_23 ( V_15 , & V_32 -> V_111 , V_1 ,
V_23 ) ;
}
V_32 -> V_111 |= V_358 ;
F_32 ( V_32 -> V_111 ,
V_32 -> V_46 + V_347 ) ;
}
static void F_117 ( struct V_14 * V_15 ,
const struct V_48 * V_49 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
T_1 V_25 ;
unsigned int V_245 , V_359 ;
V_245 = F_58 ( V_49 -> V_244 [ 0 ] ) ;
V_359 = F_58 ( V_49 -> V_244 [ V_49 -> V_228 - 1 ] ) ;
if ( V_359 < V_245 )
F_21 ( V_15 , L_14 ) ;
V_25 = ( V_245 & 0x7 ) | ( V_359 & 0x7 ) << 3 ;
F_32 ( V_25 , V_32 -> V_46 + V_360 ) ;
}
static unsigned int F_118 ( unsigned int V_208 , unsigned int V_34 )
{
return F_68 ( V_208 , V_34 ) - 2 ;
}
static void F_119 ( struct V_14 * V_15 ,
const struct V_48 * V_49 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_200 ;
if ( V_49 -> V_226 != V_223 )
return;
V_200 = F_118 ( V_49 -> V_227 , V_49 -> V_34 ) ;
if ( V_200 > V_218 ) {
F_21 ( V_15 , L_15 ) ;
V_200 = V_218 ;
}
F_32 ( V_200 & 0xffff ,
V_32 -> V_46 + V_361 ) ;
F_32 ( ( V_200 >> 16 ) & 0xff ,
V_32 -> V_46 + V_362 ) ;
}
static int F_120 ( struct V_14 * V_15 , const struct V_48 * V_49 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_332 ;
int V_117 ;
F_32 ( 0 , V_32 -> V_46 + V_265 ) ;
F_32 ( 0 , V_32 -> V_46 + V_264 ) ;
V_332 = ( V_363 / 2 ) * V_199 ;
if ( V_49 -> V_239 == V_238 &&
V_332 / V_199 > V_32 -> V_329 )
V_332 = V_32 -> V_329 * V_199 ;
V_332 = F_107 ( V_15 -> V_262 ,
V_32 -> V_364 ,
V_332 ) ;
for ( V_117 = 0 ; V_117 < V_332 / V_199 ; V_117 ++ ) {
F_32 ( V_32 -> V_364 [ V_117 ] ,
V_32 -> V_46 + V_140 ) ;
}
V_32 -> V_329 -= V_332 / V_199 ;
if ( V_49 -> V_239 == V_238 && V_32 -> V_329 == 0 )
return 0 ;
V_332 = F_105 ( V_15 , V_49 ) ;
if ( V_332 == 0 )
return - 1 ;
F_109 ( V_15 , V_49 ) ;
F_83 ( V_15 , 0 ) ;
return 0 ;
}
static inline int F_121 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
if ( V_15 -> V_300 -> V_263 )
return 0 ;
if ( V_17 -> V_10 == V_11 )
return 0 ;
else if ( F_86 ( & V_15 -> V_300 -> V_280 -> V_49 ) )
return 0 ;
return 1 ;
}
static int F_122 ( struct V_14 * V_15 , struct V_158 * V_159 ,
unsigned int V_365 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
struct V_48 * V_49 = & V_159 -> V_280 -> V_49 ;
int V_98 ;
if ( V_365 != 0 )
return - V_195 ;
V_98 = F_120 ( V_15 , V_49 ) ;
if ( V_98 < 0 )
return - V_366 ;
F_115 ( V_15 , V_49 ) ;
if ( V_49 -> V_233 == V_367 )
F_32 ( 0 , V_32 -> V_46 + V_368 ) ;
V_159 -> V_280 -> V_369 = NULL ;
return 0 ;
}
static int F_123 ( struct V_14 * V_15 , struct V_158 * V_159 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
struct V_48 * V_49 = & V_159 -> V_280 -> V_49 ;
if ( F_121 ( V_15 ) ) {
F_46 ( V_15 ) ;
return - V_166 ;
}
F_32 ( 0x0 , V_32 -> V_46 + V_346 ) ;
V_32 -> V_325 = 0 ;
V_32 -> V_329 = V_49 -> V_243 * V_49 -> V_228 ;
F_117 ( V_15 , V_49 ) ;
F_119 ( V_15 , V_49 ) ;
F_88 ( V_15 , 0 , V_32 -> V_129 |
V_137 | V_138 ) ;
F_116 ( V_15 , V_49 ) ;
V_159 -> V_280 -> V_369 = F_122 ;
return 0 ;
}
static int F_124 ( struct V_14 * V_15 , struct V_158 * V_159 ,
struct V_48 * V_49 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
int V_229 = 0 ;
unsigned int V_230 ;
int V_117 ;
V_229 |= F_71 ( & V_49 -> V_233 , V_367 | V_234 ) ;
V_229 |= F_71 ( & V_49 -> V_226 ,
V_223 | V_234 ) ;
V_229 |= F_71 ( & V_49 -> V_222 , V_225 ) ;
V_229 |= F_71 ( & V_49 -> V_237 , V_238 ) ;
V_229 |= F_71 ( & V_49 -> V_239 , V_240 ) ;
if ( V_229 )
return 1 ;
V_229 |= F_72 ( V_49 -> V_233 ) ;
V_229 |= F_72 ( V_49 -> V_226 ) ;
if ( V_49 -> V_222 == V_234 && V_49 -> V_226 == V_223 )
V_229 |= - V_195 ;
if ( V_49 -> V_239 != V_238 &&
V_49 -> V_239 != V_240 && V_49 -> V_239 != V_234 )
V_229 |= - V_195 ;
if ( V_229 )
return 2 ;
if ( V_49 -> V_226 == V_223 ) {
V_229 |= F_74 ( & V_49 -> V_227 ,
V_17 -> V_370 ) ;
if ( F_118 ( V_49 -> V_227 , V_49 -> V_34 ) >
V_218 ) {
V_49 -> V_227 = ( V_218 + 2 ) *
V_211 ;
V_229 |= - V_195 ;
}
}
V_229 |= F_74 ( & V_49 -> V_228 , 1 ) ;
V_229 |= F_73 ( & V_49 -> V_242 , V_49 -> V_228 ) ;
if ( V_229 )
return 3 ;
if ( V_49 -> V_226 == V_223 ) {
V_230 = V_49 -> V_227 ;
V_49 -> V_227 = F_68 ( V_49 -> V_227 ,
V_49 -> V_34 ) * V_211 ;
if ( V_230 != V_49 -> V_227 )
V_229 ++ ;
}
if ( V_229 )
return 4 ;
if ( V_49 -> V_244 ) {
unsigned int V_245 = F_58 ( V_49 -> V_244 [ 0 ] ) ;
for ( V_117 = 1 ; V_117 < V_49 -> V_228 ; V_117 ++ ) {
if ( F_58 ( V_49 -> V_244 [ V_117 ] ) != V_245 + V_117 ) {
F_21 ( V_15 ,
L_9 ) ;
V_229 ++ ;
break;
}
}
}
if ( V_229 )
return 5 ;
return 0 ;
}
static int F_125 ( struct V_14 * V_15 , struct V_158 * V_159 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
F_32 ( 0x0 , V_32 -> V_46 + V_346 ) ;
F_25 ( V_15 , 0 ) ;
return 0 ;
}
static int F_126 ( int V_371 , int V_372 , int V_153 , unsigned long V_373 )
{
void T_4 * V_374 = ( void T_4 * ) V_373 ;
if ( V_371 ) {
F_84 ( V_153 , V_374 + V_372 ) ;
return 0 ;
} else {
return F_98 ( V_374 + V_372 ) ;
}
}
static int F_127 ( int V_371 , int V_372 , int V_153 , unsigned long V_373 )
{
void T_4 * V_374 = ( void T_4 * ) V_373 ;
if ( V_371 ) {
F_32 ( V_153 , V_374 + 2 * V_372 ) ;
return 0 ;
} else {
return F_56 ( V_374 + 2 * V_372 ) ;
}
}
static int F_128 ( struct V_14 * V_15 , struct V_158 * V_159 ,
struct V_160 * V_161 , unsigned int * V_153 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_25 ;
V_25 = F_98 ( V_32 -> V_191 + V_375 ) ;
V_25 &= 0xf ;
V_153 [ 1 ] = V_25 ;
V_153 [ 0 ] = 0 ;
return V_161 -> V_167 ;
}
static int F_129 ( struct V_14 * V_15 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
unsigned int * V_153 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
if ( F_130 ( V_159 , V_153 ) )
F_84 ( V_159 -> V_141 , V_32 -> V_191 + V_376 ) ;
V_153 [ 1 ] = V_159 -> V_141 ;
return V_161 -> V_167 ;
}
static int F_131 ( struct V_14 * V_15 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
unsigned int * V_153 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
int V_169 ;
V_169 = F_132 ( V_15 , V_159 , V_161 , V_153 , 0 ) ;
if ( V_169 )
return V_169 ;
F_84 ( V_159 -> V_377 ,
V_32 -> V_191 + V_378 ) ;
return V_161 -> V_167 ;
}
static int F_133 ( struct V_14 * V_15 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
unsigned int * V_153 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
if ( F_130 ( V_159 , V_153 ) ) {
F_84 ( V_159 -> V_141 ,
V_32 -> V_191 + V_379 ) ;
}
V_153 [ 1 ] = F_98 ( V_32 -> V_191 + V_379 ) ;
return V_161 -> V_167 ;
}
static int F_134 ( struct V_14 * V_15 , unsigned int V_152 ,
T_2 V_380 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
static const int V_381 = 8 ;
static const int V_382 = 11 ;
unsigned int V_155 = ( ( V_152 & 0x7 ) << 8 ) | V_380 ;
unsigned int V_150 , V_383 ;
static const int V_384 = 1 ;
if ( V_152 >= V_381 ) {
F_21 ( V_15 , L_16 ) ;
return - 1 ;
}
for ( V_150 = 1 << ( V_382 - 1 ) ; V_150 ; V_150 >>= 1 ) {
V_383 = 0 ;
if ( V_155 & V_150 )
V_383 |= V_385 ;
F_48 ( V_384 ) ;
F_32 ( V_383 , V_32 -> V_46 + V_109 ) ;
V_383 |= V_386 ;
F_48 ( V_384 ) ;
F_32 ( V_383 , V_32 -> V_46 + V_109 ) ;
}
F_48 ( V_384 ) ;
F_32 ( V_387 , V_32 -> V_46 + V_109 ) ;
F_48 ( V_384 ) ;
F_32 ( 0 , V_32 -> V_46 + V_109 ) ;
F_48 ( V_384 ) ;
return 0 ;
}
static int F_135 ( struct V_14 * V_15 ,
unsigned int V_388 , unsigned int V_380 )
{
T_2 V_389 [ 3 ] ;
T_2 V_390 ;
enum T_6 {
V_391 = 0x1 ,
V_392 = 0x2 ,
V_393 = 0x4 ,
V_394 = 0x8 ,
};
enum T_7 {
V_395 = 0x20 ,
};
switch ( V_388 ) {
case 0 :
V_390 = V_396 ;
V_389 [ 0 ] = V_391 ;
break;
case 1 :
V_390 = V_396 ;
V_389 [ 0 ] = V_393 ;
break;
case 2 :
V_390 = V_397 ;
V_389 [ 0 ] = V_391 ;
break;
case 3 :
V_390 = V_397 ;
V_389 [ 0 ] = V_393 ;
break;
case 4 :
V_390 = V_396 ;
V_389 [ 0 ] = V_392 ;
break;
case 5 :
V_390 = V_396 ;
V_389 [ 0 ] = V_394 ;
break;
case 6 :
V_390 = V_397 ;
V_389 [ 0 ] = V_392 ;
break;
case 7 :
V_390 = V_397 ;
V_389 [ 0 ] = V_394 ;
break;
default:
F_21 ( V_15 , L_17 ) ;
return - 1 ;
break;
}
V_389 [ 1 ] = V_395 | ( ( V_380 >> 8 ) & 0xf ) ;
V_389 [ 2 ] = V_380 & 0xff ;
F_54 ( V_15 , V_390 , V_389 , 3 ) ;
return 0 ;
}
static void F_136 ( struct V_14 * V_15 , unsigned int V_1 ,
unsigned int V_380 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
V_32 -> V_398 [ V_1 ] = V_380 ;
switch ( V_17 -> V_10 ) {
case V_19 :
case V_18 :
F_134 ( V_15 , V_1 , V_380 ) ;
break;
case V_11 :
F_135 ( V_15 , V_1 , V_380 ) ;
break;
default:
break;
}
}
static int F_137 ( struct V_14 * V_15 ,
struct V_158 * V_159 ,
struct V_160 * V_161 , unsigned int * V_153 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
int V_1 = F_58 ( V_161 -> V_170 ) ;
if ( V_32 -> V_398 [ V_1 ] == V_153 [ 0 ] )
return 1 ;
F_136 ( V_15 , V_1 , V_153 [ 0 ] ) ;
return 1 ;
}
static int F_138 ( struct V_14 * V_15 ,
struct V_158 * V_159 , struct V_160 * V_161 ,
unsigned int * V_153 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_1 = F_58 ( V_161 -> V_170 ) ;
V_153 [ 0 ] = V_32 -> V_398 [ V_1 ] ;
return 1 ;
}
static void F_139 ( struct V_14 * V_15 , unsigned int V_1 ,
unsigned int V_380 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
static const int V_382 = 10 ;
unsigned int V_150 , V_383 ;
unsigned int V_155 = ( ( V_1 & 0x3 ) << 8 ) | ( V_380 & 0xff ) ;
static const int V_399 = 1 ;
V_32 -> V_400 [ V_1 ] = V_380 ;
V_383 = V_401 ;
F_48 ( V_399 ) ;
F_32 ( V_383 , V_32 -> V_46 + V_109 ) ;
for ( V_150 = 1 << ( V_382 - 1 ) ; V_150 ; V_150 >>= 1 ) {
if ( V_155 & V_150 )
V_383 |= V_385 ;
else
V_383 &= ~ V_385 ;
F_48 ( V_399 ) ;
F_32 ( V_383 , V_32 -> V_46 + V_109 ) ;
F_48 ( V_399 ) ;
F_32 ( V_383 | V_386 ,
V_32 -> V_46 + V_109 ) ;
}
F_48 ( V_399 ) ;
F_32 ( 0 , V_32 -> V_46 + V_109 ) ;
}
static int F_140 ( struct V_14 * V_15 ,
struct V_158 * V_159 ,
struct V_160 * V_161 , unsigned int * V_153 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
int V_1 = F_58 ( V_161 -> V_170 ) ;
if ( V_32 -> V_400 [ V_1 ] == V_153 [ 0 ] )
return 1 ;
V_32 -> V_400 [ V_1 ] = V_153 [ 0 ] ;
F_139 ( V_15 , V_1 , V_153 [ 0 ] ) ;
return 1 ;
}
static int F_141 ( struct V_14 * V_15 ,
struct V_158 * V_159 ,
struct V_160 * V_161 , unsigned int * V_153 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_1 = F_58 ( V_161 -> V_170 ) ;
V_153 [ 0 ] = V_32 -> V_400 [ V_1 ] ;
return 1 ;
}
static T_1 F_142 ( struct V_14 * V_15 , T_2 V_152 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
static const int V_382 = 11 ;
static const int V_402 = 0x6 ;
unsigned int V_155 = ( V_402 << 8 ) | V_152 ;
unsigned int V_150 ;
void T_4 * const V_144 =
V_32 -> V_36 + V_54 ;
T_1 V_380 ;
static const int V_403 = 16 ;
static const int V_404 = 1 ;
F_48 ( V_404 ) ;
V_32 -> V_53 &= ~ V_405 & ~ V_157 ;
V_32 -> V_53 |= V_148 ;
F_30 ( V_32 -> V_53 , V_144 ) ;
F_48 ( V_404 ) ;
V_32 -> V_53 |= V_157 ;
F_30 ( V_32 -> V_53 , V_144 ) ;
for ( V_150 = 1 << ( V_382 - 1 ) ; V_150 ; V_150 >>= 1 ) {
F_48 ( V_404 ) ;
if ( V_155 & V_150 )
V_32 -> V_53 |= V_143 ;
else
V_32 -> V_53 &= ~ V_143 ;
F_30 ( V_32 -> V_53 , V_144 ) ;
F_48 ( V_404 ) ;
V_32 -> V_53 |= V_405 ;
F_30 ( V_32 -> V_53 , V_144 ) ;
F_48 ( V_404 ) ;
V_32 -> V_53 &= ~ V_405 ;
F_30 ( V_32 -> V_53 , V_144 ) ;
}
V_380 = 0 ;
for ( V_150 = 1 << ( V_403 - 1 ) ; V_150 ; V_150 >>= 1 ) {
F_48 ( V_404 ) ;
V_32 -> V_53 |= V_405 ;
F_30 ( V_32 -> V_53 , V_144 ) ;
F_48 ( V_404 ) ;
V_32 -> V_53 &= ~ V_405 ;
F_30 ( V_32 -> V_53 , V_144 ) ;
F_48 ( V_404 ) ;
if ( F_35 ( V_144 ) & V_406 )
V_380 |= V_150 ;
}
F_48 ( V_404 ) ;
V_32 -> V_53 &= ~ V_157 ;
F_30 ( V_32 -> V_53 , V_144 ) ;
return V_380 ;
}
static int F_143 ( struct V_14 * V_15 ,
struct V_158 * V_159 ,
struct V_160 * V_161 , unsigned int * V_153 )
{
V_153 [ 0 ] = F_142 ( V_15 , F_58 ( V_161 -> V_170 ) ) ;
return 1 ;
}
static int F_144 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
struct V_158 * V_159 ;
void T_4 * V_407 ;
int V_117 ;
int V_169 ;
V_169 = F_145 ( V_15 , 10 ) ;
if ( V_169 )
return V_169 ;
V_159 = & V_15 -> V_408 [ 0 ] ;
V_15 -> V_300 = V_159 ;
V_159 -> type = V_409 ;
V_159 -> V_410 = V_411 | V_412 | V_413 | V_414 ;
if ( V_17 -> V_10 == V_19 )
V_159 -> V_410 |= V_415 | V_416 ;
else if ( V_17 -> V_10 == V_18 )
V_159 -> V_410 |= V_416 ;
V_159 -> V_417 = V_17 -> V_418 ;
V_159 -> V_419 = 0x2000 ;
V_159 -> V_420 = ( 1 << V_17 -> V_421 ) - 1 ;
V_159 -> V_422 = V_17 -> V_24 ;
V_159 -> V_423 = F_57 ;
V_159 -> V_424 = F_67 ;
V_159 -> V_425 = F_89 ;
V_159 -> V_426 = F_70 ;
V_159 -> V_427 = F_112 ;
if ( V_17 -> V_10 == V_11 ) {
T_2 V_153 ;
V_32 -> V_185 = F_15 ( 4 ) ;
for ( V_117 = 0 ; V_117 < V_159 -> V_417 ; V_117 ++ )
V_32 -> V_185 |= F_16 ( V_117 ) ;
V_153 = V_32 -> V_185 ;
F_54 ( V_15 , V_187 , & V_153 , sizeof( V_153 ) ) ;
}
V_159 = & V_15 -> V_408 [ 1 ] ;
if ( V_17 -> V_30 ) {
V_159 -> type = V_428 ;
V_159 -> V_410 = V_411 | V_429 |
V_412 | V_430 ;
V_159 -> V_417 = V_17 -> V_30 ;
V_159 -> V_420 = ( 1 << V_17 -> V_431 ) - 1 ;
V_159 -> V_422 = V_17 -> V_432 ;
V_159 -> V_423 = F_114 ;
V_159 -> V_433 = F_113 ;
if ( F_24 ( V_17 ) ) {
V_15 -> V_262 = V_159 ;
V_159 -> V_426 = F_124 ;
V_159 -> V_425 = F_123 ;
V_159 -> V_419 = V_17 -> V_30 ;
V_159 -> V_427 = F_125 ;
}
} else {
V_159 -> type = V_434 ;
}
V_159 = & V_15 -> V_408 [ 2 ] ;
if ( V_17 -> V_10 == V_18 ) {
V_159 -> type = V_435 ;
V_159 -> V_410 = V_411 ;
V_159 -> V_417 = 4 ;
V_159 -> V_420 = 1 ;
V_159 -> V_422 = & V_436 ;
V_159 -> V_437 = F_128 ;
} else
V_159 -> type = V_434 ;
if ( V_17 -> V_10 == V_18 ) {
V_159 = & V_15 -> V_408 [ 3 ] ;
V_159 -> type = V_438 ;
V_159 -> V_410 = V_429 | V_411 ;
V_159 -> V_417 = 4 ;
V_159 -> V_420 = 1 ;
V_159 -> V_422 = & V_436 ;
V_159 -> V_437 = F_129 ;
} else
V_159 -> type = V_434 ;
V_159 = & V_15 -> V_408 [ 4 ] ;
if ( V_17 -> V_439 ) {
if ( V_17 -> V_10 == V_11 ) {
V_407 = V_32 -> V_46 + V_440 ;
V_169 = F_146 ( V_15 , V_159 , F_127 ,
( unsigned long ) V_407 ) ;
} else {
V_407 =
V_32 -> V_191 + V_441 ;
V_169 = F_146 ( V_15 , V_159 , F_126 ,
( unsigned long ) V_407 ) ;
}
if ( V_169 )
return V_169 ;
} else {
V_159 -> type = V_434 ;
}
V_159 = & V_15 -> V_408 [ 5 ] ;
if ( V_17 -> V_10 == V_19 ) {
V_159 -> type = V_442 ;
V_159 -> V_410 = V_429 | V_411 ;
V_159 -> V_417 = 8 ;
V_159 -> V_420 = 1 ;
V_159 -> V_422 = & V_436 ;
V_159 -> V_424 = F_131 ;
V_159 -> V_437 = F_133 ;
} else
V_159 -> type = V_434 ;
V_159 = & V_15 -> V_408 [ 6 ] ;
V_159 -> type = V_443 ;
V_159 -> V_410 = V_411 | V_429 | V_444 ;
V_159 -> V_417 = 8 ;
if ( V_17 -> V_10 == V_11 )
V_159 -> V_420 = 0xfff ;
else
V_159 -> V_420 = 0xff ;
V_159 -> V_423 = F_138 ;
V_159 -> V_433 = F_137 ;
for ( V_117 = 0 ; V_117 < V_159 -> V_417 ; V_117 ++ )
F_136 ( V_15 , V_117 , V_159 -> V_420 / 2 ) ;
V_159 = & V_15 -> V_408 [ 7 ] ;
if ( V_17 -> V_10 == V_18 ) {
V_159 -> type = V_443 ;
V_159 -> V_410 = V_411 | V_429 | V_444 ;
V_159 -> V_417 = 2 ;
V_159 -> V_423 = F_141 ;
V_159 -> V_433 = F_140 ;
V_159 -> V_420 = 0xff ;
for ( V_117 = 0 ; V_117 < V_159 -> V_417 ; V_117 ++ )
F_139 ( V_15 , V_117 , V_159 -> V_420 / 2 ) ;
} else
V_159 -> type = V_434 ;
V_159 = & V_15 -> V_408 [ 8 ] ;
if ( F_35 ( V_32 -> V_36 + V_54 ) & V_445 ) {
V_159 -> type = V_446 ;
V_159 -> V_410 = V_411 | V_444 ;
V_159 -> V_417 = 128 ;
V_159 -> V_420 = 0xffff ;
V_159 -> V_423 = F_143 ;
} else
V_159 -> type = V_434 ;
V_159 = & V_15 -> V_408 [ 9 ] ;
V_159 -> type = V_434 ;
return 0 ;
}
static int F_147 ( struct V_14 * V_15 ,
unsigned long V_162 )
{
struct V_115 * V_116 = F_43 ( V_15 ) ;
const struct V_8 * V_17 = NULL ;
struct V_31 * V_32 ;
T_3 V_447 , V_448 ;
int V_98 ;
if ( V_162 < F_148 ( V_449 ) )
V_17 = & V_449 [ V_162 ] ;
if ( ! V_17 )
return - V_450 ;
V_15 -> V_451 = V_17 ;
V_32 = F_149 ( V_15 , sizeof( * V_32 ) ) ;
if ( ! V_32 )
return - V_121 ;
V_98 = F_150 ( V_15 ) ;
if ( V_98 )
return V_98 ;
F_151 ( V_116 ) ;
V_15 -> V_452 = V_17 -> V_453 ;
V_32 -> V_454 = F_152 ( V_116 , 2 ) ;
V_32 -> V_455 = F_152 ( V_116 , 3 ) ;
V_32 -> V_36 = F_153 ( V_116 , 0 ) ;
V_32 -> V_46 = F_153 ( V_116 , 2 ) ;
V_32 -> V_191 = F_153 ( V_116 , 3 ) ;
if ( ! V_32 -> V_36 || ! V_32 -> V_46
|| ! V_32 -> V_191 ) {
F_154 ( V_15 -> V_194 , L_18 ) ;
return - V_121 ;
}
V_447 = F_35 ( V_32 -> V_36 + V_456 ) &
V_457 ;
V_448 = F_35 ( V_32 -> V_36 + V_458 ) &
V_447 & V_459 ;
V_32 -> V_134 = ( ( T_3 ) V_32 -> V_454 &
~ V_447 ) | V_448 ;
V_447 = F_35 ( V_32 -> V_36 + V_460 ) &
V_457 ;
V_448 = F_35 ( V_32 -> V_36 + V_461 ) &
V_447 & V_459 ;
V_32 -> V_132 = ( ( T_3 ) V_32 -> V_455 &
~ V_447 ) | V_448 ;
V_98 = F_42 ( V_15 ) ;
if ( V_98 < 0 )
return V_98 ;
V_32 -> F_22 =
F_22 ( V_15 , F_56 ( V_32 -> V_46 + V_164 ) ) ;
F_63 ( V_15 -> V_194 , L_19 ,
V_32 -> F_22 ) ;
F_34 ( V_15 ) ;
F_41 ( V_15 ) ;
if ( F_155 ( V_116 -> V_338 , F_111 , V_462 ,
L_20 , V_15 ) ) {
F_63 ( V_15 -> V_194 , L_21 ,
V_116 -> V_338 ) ;
return - V_195 ;
}
V_15 -> V_338 = V_116 -> V_338 ;
F_63 ( V_15 -> V_194 , L_22 , V_15 -> V_338 ) ;
V_98 = F_144 ( V_15 ) ;
if ( V_98 < 0 )
return V_98 ;
return 0 ;
}
static void F_156 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_115 * V_116 = F_43 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_117 ;
if ( V_15 -> V_338 )
F_157 ( V_15 -> V_338 , V_15 ) ;
if ( V_32 ) {
if ( V_116 ) {
if ( V_32 -> V_36 ) {
F_29 ( V_15 ) ;
F_158 ( V_32 -> V_36 ) ;
}
if ( V_32 -> V_46 )
F_158 ( V_32 -> V_46 ) ;
if ( V_32 -> V_191 )
F_158 ( V_32 -> V_191 ) ;
for ( V_117 = 0 ; V_117 < F_17 ( V_17 ) ; V_117 ++ ) {
if ( V_32 -> V_118 [ V_117 ] )
F_159 ( V_116 ,
V_119 ,
V_32 -> V_118 [ V_117 ] ,
V_32 -> V_120 [ V_117 ] ) ;
}
for ( V_117 = 0 ; V_117 < V_122 ; V_117 ++ ) {
if ( V_32 -> V_123 [ V_117 ] )
F_159 ( V_116 ,
V_119 ,
V_32 -> V_123 [ V_117 ] ,
V_32 -> V_124 [ V_117 ] ) ;
}
if ( V_32 -> V_125 )
F_159 ( V_116 ,
sizeof( struct V_126 ) *
F_17 ( V_17 ) ,
V_32 -> V_125 ,
V_32 -> V_127 ) ;
if ( V_32 -> V_128 )
F_159 ( V_116 ,
sizeof( struct V_126 ) *
V_122 ,
V_32 -> V_128 ,
V_32 -> V_129 ) ;
}
}
F_160 ( V_15 ) ;
}
static int F_161 ( struct V_115 * V_15 ,
const struct V_463 * V_204 )
{
return F_162 ( V_15 , & V_464 ,
V_204 -> V_465 ) ;
}
