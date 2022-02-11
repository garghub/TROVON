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
return V_13 ;
}
static inline unsigned short F_18 ( struct V_14 * V_15 ,
int V_16 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
if ( ( V_17 -> V_10 == V_18 && ! V_16 ) ||
( V_17 -> V_10 == V_19 && V_16 ) )
return V_20 ;
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
F_21 ( V_15 -> V_27 , L_1 , V_28 ) ;
break;
}
if ( V_23 -> V_29 == 0 )
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
T_1 * V_25 , unsigned int V_1 ,
unsigned int V_23 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
unsigned int V_30 = V_17 -> V_31 [ V_23 ] ;
if ( V_1 > 1 )
F_21 ( V_15 -> V_27 , L_2 ) ;
if ( V_30 & ~ 0x3 )
F_21 ( V_15 -> V_27 , L_3 ) ;
* V_25 &= ~ ( 0x3 << ( 2 * V_1 ) ) ;
* V_25 |= V_30 << ( 2 * V_1 ) ;
}
static inline int F_24 ( const struct V_8 * V_9 )
{
return V_9 -> V_32 && V_9 -> V_10 != V_11 ;
}
static void F_25 ( struct V_14 * V_15 , unsigned int V_1 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
unsigned long V_36 ;
F_26 ( & V_15 -> V_37 , V_36 ) ;
F_27 ( V_34 -> V_38 , V_1 ) ;
F_28 ( & V_15 -> V_37 , V_36 ) ;
}
static void F_29 ( struct V_14 * V_15 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
V_34 -> V_39 = 0 ;
F_30 ( V_34 -> V_39 ,
V_34 -> V_38 + V_40 ) ;
}
static void F_31 ( struct V_14 * V_15 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
unsigned long V_36 ;
F_26 ( & V_15 -> V_37 , V_36 ) ;
V_34 -> V_41 &=
~ V_42 & ~ V_43 &
~ V_44 & ~ V_45 &
~ V_46 & ~ V_47 ;
F_32 ( V_34 -> V_41 ,
V_34 -> V_48 + V_49 ) ;
F_28 ( & V_15 -> V_37 , V_36 ) ;
}
static void F_33 ( struct V_14 * V_15 ,
const struct V_50 * V_51 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_33 * V_34 = V_15 -> V_35 ;
T_3 V_25 ;
unsigned long V_36 ;
V_25 = V_46 | V_43 |
V_44 | V_45 ;
if ( V_51 -> V_36 & V_52 ) {
if ( V_17 -> V_10 != V_11 )
V_25 |= V_53 | V_42 ;
}
F_26 ( & V_15 -> V_37 , V_36 ) ;
V_34 -> V_41 |= V_25 ;
F_32 ( V_34 -> V_41 ,
V_34 -> V_48 + V_49 ) ;
F_28 ( & V_15 -> V_37 , V_36 ) ;
}
static void F_34 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_33 * V_34 = V_15 -> V_35 ;
T_3 V_25 ;
void T_4 * V_54 = V_34 -> V_38 ;
V_34 -> V_55 =
F_35 ( V_34 -> V_38 + V_56 ) ;
#ifdef F_36
V_25 = V_57 | V_58 ;
#else
V_25 = 0 ;
#endif
F_30 ( V_25 , V_34 -> V_38 + V_59 ) ;
F_29 ( V_15 ) ;
F_25 ( V_15 , 0 ) ;
F_25 ( V_15 , 1 ) ;
V_25 = 0 ;
V_25 |= V_60 ;
V_25 |= V_61 ;
V_25 |= V_62 ;
V_25 |= V_63 ;
V_25 |= V_64 ;
V_25 |= V_65 ;
V_25 |= V_66 ;
V_25 |= V_67 ;
if ( V_17 -> V_10 == V_11 )
V_25 |= V_68 ;
else
V_25 |= V_69 ;
F_30 ( V_25 , V_54 + V_70 ) ;
if ( F_24 ( V_17 ) )
F_30 ( V_25 , V_54 + V_71 ) ;
V_34 -> V_39 |=
V_72 | V_73 | V_74 | V_75 | V_76 | V_77 |
V_78 | V_79 ;
F_30 ( V_34 -> V_39 ,
V_34 -> V_38 + V_40 ) ;
}
static void F_37 ( struct V_14 * V_15 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
unsigned long V_36 ;
F_31 ( V_15 ) ;
F_26 ( & V_15 -> V_37 , V_36 ) ;
V_34 -> V_80 &= ~ V_81 ;
F_32 ( V_34 -> V_80 ,
V_34 -> V_48 + V_82 ) ;
F_28 ( & V_15 -> V_37 , V_36 ) ;
F_32 ( V_83 | V_84 | V_85 ,
V_34 -> V_48 + V_86 ) ;
}
static int F_38 ( struct V_14 * V_15 ,
unsigned int V_87 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_33 * V_34 = V_15 -> V_35 ;
static const int V_88 = 0x100 ;
const struct V_89 * const V_90 = V_17 -> V_91 ;
unsigned int V_92 ;
T_1 V_25 ;
if ( V_87 < V_88 )
V_87 = V_88 ;
if ( V_87 > V_90 -> V_93 )
V_87 = V_90 -> V_93 ;
V_92 = ( V_87 + V_88 / 2 ) / V_88 ;
V_25 = ( ~ ( V_92 - 1 ) ) & V_90 -> V_94 ;
V_34 -> V_95 &= ~ V_90 -> V_94 ;
V_34 -> V_95 |= V_25 ;
F_32 ( V_34 -> V_95 ,
V_34 -> V_48 + V_96 ) ;
V_34 -> V_97 = V_92 * V_88 ;
return V_34 -> V_97 ;
}
static int F_39 ( struct V_14 * V_15 , unsigned int V_98 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
unsigned int V_99 ;
int V_100 ;
const struct V_89 * const V_90 = V_17 -> V_91 ;
V_99 = V_98 / V_90 -> V_101 ;
V_100 = F_38 ( V_15 ,
V_99 /
V_90 -> V_102 ) ;
if ( V_100 < 0 )
return V_100 ;
V_98 = V_100 * V_90 -> V_102 * V_90 -> V_101 ;
return V_98 ;
}
static unsigned int F_40 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_33 * V_34 = V_15 -> V_35 ;
return V_34 -> V_97 *
V_17 -> V_91 -> V_102 *
V_17 -> V_91 -> V_101 ;
}
static void F_41 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_33 * V_34 = V_15 -> V_35 ;
T_1 V_25 ;
unsigned long V_36 ;
F_26 ( & V_15 -> V_37 , V_36 ) ;
if ( 1 )
V_34 -> V_80 |= V_103 ;
F_32 ( V_34 -> V_80 ,
V_34 -> V_48 + V_82 ) ;
F_32 ( 0xff , V_34 -> V_48 + V_104 ) ;
V_25 = V_105 | V_106 ;
if ( V_17 -> V_10 == V_11 )
V_25 |= V_107 ;
V_34 -> V_108 |= V_25 ;
F_32 ( V_34 -> V_108 ,
V_34 -> V_48 + V_109 ) ;
F_32 ( 0 , V_34 -> V_48 + V_110 ) ;
F_32 ( 0 , V_34 -> V_48 + V_111 ) ;
F_28 ( & V_15 -> V_37 , V_36 ) ;
V_34 -> V_95 |= V_112 ;
F_38 ( V_15 ,
V_17 -> V_91 -> V_93 ) ;
V_34 -> V_113 = V_114 ;
V_34 -> V_41 =
V_115 | V_116 ;
F_32 ( V_34 -> V_41 ,
V_34 -> V_48 + V_49 ) ;
F_37 ( V_15 ) ;
}
static int F_42 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_117 * V_118 = F_43 ( V_15 ) ;
struct V_33 * V_34 = V_15 -> V_35 ;
int V_119 ;
for ( V_119 = 0 ; V_119 < F_17 ( V_17 ) ; V_119 ++ ) {
V_34 -> V_120 [ V_119 ] =
F_44 ( V_118 , V_121 ,
& V_34 -> V_122 [ V_119 ] ) ;
if ( V_34 -> V_120 [ V_119 ] == NULL )
return - V_123 ;
}
for ( V_119 = 0 ; V_119 < V_124 ; V_119 ++ ) {
if ( F_24 ( V_17 ) ) {
V_34 -> V_125 [ V_119 ] =
F_44 ( V_118 , V_121 ,
& V_34 ->
V_126 [ V_119 ] ) ;
if ( V_34 -> V_125 [ V_119 ] == NULL )
return - V_123 ;
}
}
V_34 -> V_127 =
F_44 ( V_118 , sizeof( struct V_128 ) *
F_17 ( V_17 ) ,
& V_34 -> V_129 ) ;
if ( V_34 -> V_127 == NULL )
return - V_123 ;
if ( F_24 ( V_17 ) ) {
V_34 -> V_130 =
F_44 ( V_118 ,
sizeof( struct V_128 ) *
V_124 ,
& V_34 -> V_131 ) ;
if ( V_34 -> V_130 == NULL )
return - V_123 ;
}
for ( V_119 = 0 ; V_119 < F_17 ( V_17 ) ; V_119 ++ ) {
V_34 -> V_127 [ V_119 ] . V_132 =
F_45 ( V_34 -> V_122 [ V_119 ] ) ;
if ( V_17 -> V_10 == V_11 )
V_34 -> V_127 [ V_119 ] . V_133 =
F_45 ( V_34 -> V_134 +
V_135 ) ;
else
V_34 -> V_127 [ V_119 ] . V_133 =
F_45 ( V_34 -> V_136 +
V_135 ) ;
V_34 -> V_127 [ V_119 ] . V_137 = F_45 ( 0 ) ;
V_34 -> V_127 [ V_119 ] . V_138 =
F_45 ( ( V_34 -> V_129 +
( ( V_119 + 1 ) % F_17 ( V_17 ) ) *
sizeof( V_34 -> V_127 [ 0 ] ) ) |
V_139 | V_140 |
V_141 ) ;
}
if ( F_24 ( V_17 ) ) {
for ( V_119 = 0 ; V_119 < V_124 ; V_119 ++ ) {
V_34 -> V_130 [ V_119 ] . V_132 =
F_45 ( V_34 -> V_126 [ V_119 ] ) ;
V_34 -> V_130 [ V_119 ] . V_133 =
F_45 ( V_34 -> V_136 +
V_142 ) ;
V_34 -> V_130 [ V_119 ] . V_137 = F_45 ( 0 ) ;
V_34 -> V_130 [ V_119 ] . V_138 =
F_45 ( ( V_34 -> V_131 +
( ( V_119 + 1 ) % ( V_124 ) ) *
sizeof( V_34 -> V_130 [ 0 ] ) ) |
V_139 |
V_140 ) ;
}
}
return 0 ;
}
static inline void F_46 ( struct V_14 * V_15 )
{
F_21 ( V_15 -> V_27 ,
L_4 ) ;
F_21 ( V_15 -> V_27 ,
L_5 ) ;
}
static void F_47 ( struct V_14 * V_15 , int V_143 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
static const int V_144 = V_145 ;
void T_4 * V_146 = V_34 -> V_38 +
V_56 ;
if ( V_143 ) {
V_34 -> V_55 &= ~ V_144 ;
F_30 ( V_34 -> V_55 , V_146 ) ;
F_48 ( V_147 ) ;
} else {
V_34 -> V_55 |= V_144 ;
F_30 ( V_34 -> V_55 , V_146 ) ;
F_48 ( V_148 ) ;
}
}
static void F_49 ( struct V_14 * V_15 , int V_143 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
static const int V_149 = V_150 ;
void T_4 * V_146 = V_34 -> V_38 +
V_56 ;
if ( V_143 ) {
V_34 -> V_55 &= ~ V_149 ;
F_30 ( V_34 -> V_55 , V_146 ) ;
F_48 ( V_147 ) ;
} else {
V_34 -> V_55 |= V_149 ;
F_30 ( V_34 -> V_55 , V_146 ) ;
F_48 ( V_148 ) ;
}
}
static void F_50 ( struct V_14 * V_15 , T_2 V_151 )
{
T_2 V_152 ;
unsigned int V_153 = 8 ;
for ( V_152 = 1 << ( V_153 - 1 ) ; V_152 ; V_152 >>= 1 ) {
F_49 ( V_15 , 0 ) ;
if ( ( V_151 & V_152 ) )
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
static void F_54 ( struct V_14 * V_15 , unsigned int V_154 ,
const T_2 * V_155 , unsigned int V_156 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
unsigned int V_119 ;
T_2 V_157 ;
static const int V_158 = 0x1 ;
V_34 -> V_55 &= ~ V_159 ;
F_53 ( V_15 ) ;
F_52 ( V_15 ) ;
V_157 = ( V_154 << 1 ) & ~ V_158 ;
F_50 ( V_15 , V_157 ) ;
if ( F_51 ( V_15 ) != 0 ) {
F_21 ( V_15 -> V_27 , L_6 ,
V_28 ) ;
F_53 ( V_15 ) ;
return;
}
for ( V_119 = 0 ; V_119 < V_156 ; V_119 ++ ) {
F_50 ( V_15 , V_155 [ V_119 ] ) ;
if ( F_51 ( V_15 ) != 0 ) {
F_21 ( V_15 -> V_27 , L_6 ,
V_28 ) ;
F_53 ( V_15 ) ;
return;
}
}
F_53 ( V_15 ) ;
}
static int F_55 ( struct V_14 * V_15 ,
struct V_160 * V_161 ,
struct V_162 * V_163 ,
unsigned long V_164 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_33 * V_34 = V_15 -> V_35 ;
unsigned int V_165 ;
V_165 = F_56 ( V_34 -> V_48 + V_166 ) ;
if ( V_17 -> V_10 == V_11 ) {
V_165 = F_56 ( V_34 -> V_48 + V_167 ) ;
if ( V_165 )
return 0 ;
} else {
if ( F_11 ( V_165 ) )
return 0 ;
}
return - V_168 ;
}
static int F_57 ( struct V_14 * V_15 , struct V_160 * V_161 ,
struct V_162 * V_163 , unsigned int * V_155 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_33 * V_34 = V_15 -> V_35 ;
unsigned int V_25 = 0 , V_169 ;
unsigned int V_1 , V_23 , V_170 ;
unsigned long V_36 ;
int V_171 ;
V_1 = F_58 ( V_163 -> V_172 ) ;
V_23 = F_59 ( V_163 -> V_172 ) ;
V_170 = F_60 ( V_163 -> V_172 ) ;
F_37 ( V_15 ) ;
F_26 ( & V_15 -> V_37 , V_36 ) ;
if ( V_163 -> V_172 & V_173 )
V_34 -> V_80 |= V_174 ;
else
V_34 -> V_80 &= ~ V_174 ;
F_32 ( V_34 -> V_80 ,
V_34 -> V_48 + V_82 ) ;
F_28 ( & V_15 -> V_37 , V_36 ) ;
if ( V_17 -> V_10 != V_11 ) {
V_34 -> V_108 &= ~ V_175 ;
F_32 ( V_34 -> V_108 ,
V_34 -> V_48 + V_109 ) ;
if ( V_163 -> V_172 & V_176 ) {
unsigned int V_177 ;
if ( V_17 -> V_10 == V_19 )
V_177 = V_178 ;
else
V_177 = V_179 ;
F_32 ( V_177 |
F_8 ( V_34 -> V_180 ) ,
V_34 -> V_48 + V_111 ) ;
} else {
F_32 ( 0 , V_34 -> V_48 + V_111 ) ;
}
V_25 = 0 ;
V_25 |= F_20 ( V_15 , F_59 ( V_163 -> V_172 ) ) ;
V_25 |= F_18 ( V_15 , V_170 == V_181 ) ;
if ( V_170 == V_182 )
V_25 |= V_183 ;
V_25 |= F_10 ( V_1 ) ;
F_32 ( F_10 ( V_1 ) ,
V_34 -> V_48 + V_184 ) ;
F_32 ( V_25 , V_34 -> V_48 + V_185 ) ;
} else {
T_2 V_186 = V_34 -> V_187 ;
V_34 -> V_187 &= ~ V_7 ;
if ( V_163 -> V_172 & V_176 ) {
V_34 -> V_187 |=
F_15 ( V_34 -> V_180 ) ;
} else {
V_34 -> V_187 |= F_15 ( 4 ) ;
}
if ( V_23 == 0 )
V_34 -> V_187 |= F_16 ( V_1 ) ;
else
V_34 -> V_187 &= ~ F_16 ( V_1 ) ;
if ( V_186 != V_34 -> V_187 ) {
T_2 V_188 = V_34 -> V_187 ;
F_54 ( V_15 , V_189 , & V_188 ,
sizeof( V_188 ) ) ;
}
F_32 ( 0 , V_34 -> V_48 + V_104 ) ;
F_32 ( 2 , V_34 -> V_48 + V_190 ) ;
}
for ( V_169 = 0 ; V_169 < V_163 -> V_169 ; V_169 ++ ) {
F_32 ( 0 , V_34 -> V_48 + V_191 ) ;
F_32 ( F_9 ( F_58 ( V_163 -> V_172 ) ) ,
V_34 -> V_48 + V_192 ) ;
V_171 = F_61 ( V_15 , V_161 , V_163 , F_55 , 0 ) ;
if ( V_171 )
return V_171 ;
if ( V_17 -> V_10 == V_11 )
V_155 [ V_169 ] = F_35 ( V_15 -> V_193 + V_135 ) & 0xffff ;
else
V_155 [ V_169 ] = F_56 ( V_34 -> V_48 + V_194 ) ;
}
return V_169 ;
}
static int F_62 ( struct V_14 * V_15 ,
unsigned int * V_155 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_33 * V_34 = V_15 -> V_35 ;
unsigned int V_4 = V_155 [ 1 ] ;
int V_195 ;
if ( V_17 -> V_10 == V_19 )
V_195 = 16 ;
else
V_195 = 8 ;
if ( V_4 >= V_195 ) {
F_63 ( V_15 -> V_27 , L_7 ,
V_4 ) ;
return - V_196 ;
}
V_34 -> V_180 = V_4 ;
return 2 ;
}
static int F_64 ( struct V_14 * V_15 , unsigned int * V_155 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
int V_197 ;
const struct V_89 * const V_90 = V_17 -> V_91 ;
unsigned int V_198 , V_199 ;
int V_100 ;
V_199 = V_155 [ 1 ] ;
if ( V_199 ) {
V_197 = V_199 * V_90 -> V_102 /
V_200 ;
V_100 = F_39 ( V_15 , V_197 ) ;
if ( V_100 < 0 )
return V_100 ;
}
V_198 = F_40 ( V_15 ) / V_90 -> V_102 * V_200 ;
V_155 [ 1 ] = V_198 ;
return 2 ;
}
static int F_65 ( struct V_14 * V_15 ,
unsigned int * V_155 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
unsigned int V_201 = V_155 [ 4 ] ;
int V_100 = 0 ;
if ( V_201 < 2 ) {
V_201 = 2 ;
V_100 = - V_202 ;
}
switch ( V_155 [ 1 ] ) {
case V_203 :
V_34 -> V_204 . V_201 = V_201 ;
V_34 -> V_204 . V_172 = V_155 [ 2 ] ;
break;
default:
return - V_196 ;
}
V_155 [ 4 ] = V_201 ;
return V_100 ? V_100 : 5 ;
}
static int F_66 ( struct V_14 * V_15 , unsigned int * V_155 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
switch ( V_17 -> V_10 ) {
case V_11 :
return F_65 ( V_15 , V_155 ) ;
default:
return - V_196 ;
}
return - V_196 ;
}
static int F_67 ( struct V_14 * V_15 , struct V_160 * V_161 ,
struct V_162 * V_163 , unsigned int * V_155 )
{
int V_205 = V_155 [ 0 ] ;
switch ( V_205 ) {
case V_206 :
return F_62 ( V_15 , V_155 ) ;
case V_207 :
return F_64 ( V_15 , V_155 ) ;
case V_208 :
return F_66 ( V_15 , V_155 ) ;
default:
return - V_196 ;
}
return - V_196 ;
}
static unsigned int F_68 ( unsigned int V_209 , unsigned int V_36 )
{
unsigned int V_201 ;
switch ( V_36 & V_210 ) {
case V_211 :
V_201 = ( V_209 + V_212 - 1 ) / V_212 ;
break;
case V_213 :
V_201 = V_209 / V_212 ;
break;
case V_214 :
default:
V_201 = ( V_209 + V_212 / 2 ) / V_212 ;
break;
}
return V_201 ;
}
static void F_69 ( struct V_14 * V_15 , struct V_50 * V_51 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
unsigned int V_215 = 0 , V_216 ;
static const int V_217 = 3 ;
static const int V_218 =
V_219 + V_217 ;
static const int V_220 = 2 ;
unsigned long long V_221 , V_222 ;
if ( V_51 -> V_223 == V_224 ) {
if ( V_17 -> V_10 == V_11 ) {
V_51 -> V_225 = 0 ;
} else {
V_215 = F_68 ( V_51 -> V_225 ,
V_51 -> V_36 ) ;
if ( V_215 > V_218 )
V_215 = V_218 ;
if ( V_215 < V_217 )
V_215 = V_217 ;
V_51 -> V_225 = V_215 * V_212 ;
}
} else if ( V_51 -> V_223 == V_226 ) {
V_51 -> V_225 = 0 ;
}
if ( V_51 -> V_227 == V_224 ) {
V_216 = F_68 ( V_51 -> V_228 , V_51 -> V_36 ) ;
if ( V_51 -> V_223 == V_224 ) {
V_222 = V_215 * V_51 -> V_229 ;
V_221 =
( V_215 * V_51 -> V_229 - 1 ) +
V_219 ;
} else {
V_222 = V_220 ;
V_221 = V_219 + V_222 ;
}
if ( V_216 > V_221 )
V_216 = V_221 ;
if ( V_216 < V_222 )
V_216 = V_222 ;
V_51 -> V_228 = V_216 * V_212 ;
}
}
static int F_70 ( struct V_14 * V_15 ,
struct V_160 * V_161 ,
struct V_50 * V_51 )
{
const struct V_8 * V_9 = F_19 ( V_15 ) ;
unsigned int V_230 = F_60 ( V_51 -> V_231 [ 0 ] ) ;
int V_119 ;
for ( V_119 = 1 ; V_119 < V_51 -> V_229 ; V_119 ++ ) {
unsigned int V_170 = F_60 ( V_51 -> V_231 [ V_119 ] ) ;
if ( V_170 != V_230 ) {
F_63 ( V_15 -> V_27 ,
L_8 ) ;
return - V_196 ;
}
}
if ( V_9 -> V_10 == V_11 ) {
unsigned int V_232 = F_58 ( V_51 -> V_231 [ 0 ] ) ;
for ( V_119 = 1 ; V_119 < V_51 -> V_229 ; V_119 ++ ) {
unsigned int V_233 = F_58 ( V_51 -> V_231 [ V_119 ] ) ;
if ( V_233 != ( V_232 + V_119 ) ) {
F_63 ( V_15 -> V_27 ,
L_9 ) ;
return - V_196 ;
}
}
if ( V_51 -> V_229 == 3 ) {
F_63 ( V_15 -> V_27 ,
L_10 ) ;
return - V_196 ;
}
}
return 0 ;
}
static int F_71 ( struct V_14 * V_15 , struct V_160 * V_161 ,
struct V_50 * V_51 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
int V_234 = 0 ;
unsigned int V_235 , V_236 ;
unsigned int V_237 ;
V_234 |= F_72 ( & V_51 -> V_238 , V_226 | V_239 ) ;
V_237 = V_224 ;
if ( V_17 -> V_10 == V_11 )
V_237 |= V_240 ;
else
V_237 |= V_241 ;
V_234 |= F_72 ( & V_51 -> V_227 , V_237 ) ;
V_237 = V_224 ;
if ( V_17 -> V_10 == V_11 )
V_237 |= V_226 ;
else
V_237 |= V_239 ;
V_234 |= F_72 ( & V_51 -> V_223 , V_237 ) ;
V_234 |= F_72 ( & V_51 -> V_242 , V_243 ) ;
V_234 |= F_72 ( & V_51 -> V_244 ,
V_243 | V_239 | V_245 ) ;
if ( V_234 )
return 1 ;
V_234 |= F_73 ( V_51 -> V_238 ) ;
V_234 |= F_73 ( V_51 -> V_227 ) ;
V_234 |= F_73 ( V_51 -> V_223 ) ;
V_234 |= F_73 ( V_51 -> V_244 ) ;
if ( V_51 -> V_223 == V_239 && V_51 -> V_227 == V_224 )
V_234 |= - V_196 ;
if ( V_234 )
return 2 ;
switch ( V_51 -> V_238 ) {
case V_226 :
V_234 |= F_74 ( & V_51 -> V_246 , 0 ) ;
break;
case V_239 :
break;
}
if ( V_51 -> V_223 == V_224 ) {
if ( V_17 -> V_10 == V_11 ) {
V_234 |= F_74 ( & V_51 -> V_225 , 0 ) ;
} else {
V_234 |= F_75 ( & V_51 -> V_225 ,
V_17 -> V_247 ) ;
if ( V_51 -> V_227 == V_224 )
V_234 |= F_75 (
& V_51 -> V_228 ,
V_51 -> V_225 *
V_51 -> V_229 ) ;
}
}
V_234 |= F_75 ( & V_51 -> V_229 , 1 ) ;
V_234 |= F_74 ( & V_51 -> V_248 , V_51 -> V_229 ) ;
switch ( V_51 -> V_244 ) {
case V_239 :
break;
case V_243 :
V_234 |= F_75 ( & V_51 -> V_249 , 1 ) ;
break;
case V_245 :
V_234 |= F_74 ( & V_51 -> V_249 , 0 ) ;
break;
default:
break;
}
if ( V_234 )
return 3 ;
if ( V_51 -> V_223 == V_224 ) {
V_235 = V_51 -> V_225 ;
V_236 = V_51 -> V_228 ;
F_69 ( V_15 , V_51 ) ;
if ( V_235 != V_51 -> V_225 )
V_234 ++ ;
if ( V_236 != V_51 -> V_228 )
V_234 ++ ;
}
if ( V_234 )
return 4 ;
if ( V_51 -> V_231 && V_51 -> V_229 > 0 )
V_234 |= F_70 ( V_15 , V_161 , V_51 ) ;
if ( V_234 )
return 5 ;
return 0 ;
}
static int F_76 ( struct V_50 * V_51 )
{
return 0 ;
if ( V_51 -> V_244 == V_243 && V_51 -> V_249 <= V_219 )
return 1 ;
return 0 ;
}
static void F_77 ( struct V_14 * V_15 ,
struct V_50 * V_51 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
if ( V_51 -> V_244 == V_243 ) {
V_34 -> V_250 = V_51 -> V_249 * V_51 -> V_229 ;
}
if ( F_76 ( V_51 ) ) {
F_32 ( V_51 -> V_249 & 0xffff ,
V_34 -> V_48 + V_251 ) ;
F_32 ( ( V_51 -> V_249 >> 16 ) & 0xff ,
V_34 -> V_48 + V_252 ) ;
} else {
F_32 ( 1 , V_34 -> V_48 + V_251 ) ;
}
}
static inline unsigned int F_78 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_33 * V_34 = V_15 -> V_35 ;
unsigned int V_98 ;
V_98 = V_34 -> V_97 *
V_17 -> V_91 -> V_101 ;
if ( V_98 > V_121 / sizeof( T_1 ) )
V_98 = V_121 / sizeof( T_1 ) ;
return V_98 ;
}
static T_3 F_79 ( const struct V_14 * V_15 ,
const struct V_50 * V_51 )
{
return V_51 -> V_225 / V_212 - 3 ;
}
static T_3 F_80 ( struct V_14 * V_15 ,
struct V_50 * V_51 )
{
T_3 V_253 ;
switch ( V_51 -> V_227 ) {
case V_224 :
V_253 = ( V_51 -> V_228 -
( V_51 -> V_225 * ( V_51 -> V_229 - 1 ) ) ) /
V_212 ;
break;
case V_241 :
V_253 = V_51 -> V_225 / V_212 ;
break;
default:
return 0 ;
}
return V_253 - 3 ;
}
static T_3 F_81 ( struct V_14 * V_15 ,
struct V_50 * V_51 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
unsigned int V_201 ;
switch ( V_51 -> V_227 ) {
case V_224 :
V_201 = V_51 -> V_228 / V_212 ;
break;
case V_240 :
V_201 = V_34 -> V_204 . V_201 ;
break;
default:
F_21 ( V_15 -> V_27 , L_11 ) ;
V_201 = 1000 ;
break;
}
return V_201 - 2 ;
}
static void F_82 ( struct V_14 * V_15 ,
const struct V_50 * V_51 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
V_34 -> V_108 &= ~ V_254 ;
if ( V_51 -> V_227 == V_240 ) {
int V_172 = V_34 -> V_204 . V_172 ;
if ( F_58 ( V_172 ) )
V_34 -> V_108 |= V_255 ;
else
V_34 -> V_108 |= V_256 ;
} else {
V_34 -> V_108 |= V_107 ;
}
F_32 ( V_34 -> V_108 ,
V_34 -> V_48 + V_109 ) ;
}
static void F_83 ( struct V_14 * V_15 ,
const struct V_50 * V_51 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
switch ( V_17 -> V_10 ) {
case V_11 :
F_82 ( V_15 , V_51 ) ;
break;
default:
break;
}
}
static inline void F_84 ( struct V_14 * V_15 ,
unsigned int V_1 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
unsigned long V_36 ;
F_26 ( & V_15 -> V_37 , V_36 ) ;
if ( V_1 )
F_85 ( V_257 | V_258 |
V_259 ,
V_34 -> V_38 + V_260 ) ;
else
F_85 ( V_257 | V_258 |
V_259 ,
V_34 -> V_38 + V_261 ) ;
F_28 ( & V_15 -> V_37 , V_36 ) ;
}
static void F_86 ( struct V_14 * V_15 , struct V_50 * V_51 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_33 * V_34 = V_15 -> V_35 ;
T_3 V_262 = 0 , V_263 = 0 ;
F_69 ( V_15 , V_51 ) ;
F_83 ( V_15 , V_51 ) ;
if ( V_17 -> V_10 == V_11 ) {
V_262 = F_81 ( V_15 , V_51 ) ;
} else {
V_262 = F_79 ( V_15 , V_51 ) ;
V_263 = F_80 ( V_15 , V_51 ) ;
}
F_32 ( V_262 & 0xffff ,
V_34 -> V_48 + V_190 ) ;
F_32 ( ( V_262 >> 16 ) & 0xff ,
V_34 -> V_48 + V_104 ) ;
F_32 ( V_263 & 0xffff ,
V_34 -> V_48 + V_264 ) ;
F_32 ( ( V_263 >> 16 ) & 0xff ,
V_34 -> V_48 + V_265 ) ;
}
static int F_87 ( const struct V_50 * V_51 )
{
int V_119 ;
for ( V_119 = 0 ; V_119 + 1 < V_51 -> V_229 ; V_119 ++ ) {
if ( F_58 ( V_51 -> V_231 [ V_119 + 1 ] ) !=
F_58 ( V_51 -> V_231 [ V_119 ] ) + 1 )
return 0 ;
if ( F_59 ( V_51 -> V_231 [ V_119 + 1 ] ) !=
F_59 ( V_51 -> V_231 [ V_119 ] ) )
return 0 ;
if ( F_60 ( V_51 -> V_231 [ V_119 + 1 ] ) != F_60 ( V_51 -> V_231 [ V_119 ] ) )
return 0 ;
}
return 1 ;
}
static int F_88 ( struct V_14 * V_15 ,
const struct V_50 * V_51 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_33 * V_34 = V_15 -> V_35 ;
unsigned short V_25 ;
int V_119 ;
if ( V_17 -> V_10 != V_11 ) {
if ( F_87 ( V_51 ) ) {
V_34 -> V_108 &= ~ V_175 ;
F_32 ( V_34 -> V_108 ,
V_34 -> V_48 + V_109 ) ;
V_25 = 0 ;
V_25 |= F_10 ( F_58 ( V_51 -> V_231 [ 0 ] ) ) ;
V_25 |= F_20 ( V_15 ,
F_59 ( V_51 -> V_231 [ 0 ] ) ) ;
V_25 |= F_18 ( V_15 ,
F_60 ( V_51 -> V_231 [ 0 ] ) ==
V_181 ) ;
if ( F_60 ( V_51 -> V_231 [ 0 ] ) == V_182 )
V_25 |= V_183 ;
F_32 ( F_10
( F_58 ( V_51 -> V_231 [ V_51 -> V_229 - 1 ] ) ) ,
V_34 -> V_48 + V_184 ) ;
F_32 ( V_25 ,
V_34 -> V_48 + V_185 ) ;
} else {
if ( V_15 -> V_266 && V_15 -> V_266 -> V_267 ) {
F_46 ( V_15 ) ;
return - V_168 ;
}
V_34 -> V_108 |= V_175 ;
F_32 ( V_34 -> V_108 ,
V_34 -> V_48 + V_109 ) ;
F_32 ( 0 ,
V_34 -> V_48 + V_268 ) ;
F_32 ( 0 , V_34 -> V_48 + V_269 ) ;
for ( V_119 = 0 ; V_119 < V_51 -> V_229 ; V_119 ++ ) {
V_25 = 0 ;
V_25 |= F_10 ( F_58 ( V_51 ->
V_231 [ V_119 ] ) ) ;
V_25 |= F_20 ( V_15 ,
F_59 ( V_51 ->
V_231
[ V_119 ] ) ) ;
V_25 |= F_18 ( V_15 ,
F_60 ( V_51 ->
V_231 [ V_119 ] ) ==
V_181 ) ;
if ( F_60 ( V_51 -> V_231 [ V_119 ] ) == V_182 )
V_25 |= V_183 ;
if ( V_119 == V_51 -> V_229 - 1 )
V_25 |= V_270 |
V_271 ;
F_32 ( V_25 ,
V_34 -> V_48 +
V_272 ) ;
}
F_32 ( 0 , V_34 -> V_48 + V_269 ) ;
F_32 ( 0 , V_34 -> V_48 + V_185 ) ;
}
} else {
unsigned short V_186 = V_34 -> V_187 ;
V_34 -> V_187 &= ~ V_7 ;
V_34 -> V_187 |= F_15 ( 4 ) ;
for ( V_119 = 0 ; V_119 < V_51 -> V_229 ; V_119 ++ ) {
unsigned int V_1 = F_58 ( V_51 -> V_231 [ V_119 ] ) ;
unsigned int V_23 = F_59 ( V_51 -> V_231 [ V_119 ] ) ;
if ( V_23 == 0 )
V_34 -> V_187 |=
F_16 ( V_1 ) ;
else
V_34 -> V_187 &=
~ F_16 ( V_1 ) ;
}
if ( V_186 != V_34 -> V_187 ) {
T_2 V_188 = V_34 -> V_187 ;
F_54 ( V_15 , V_189 , & V_188 ,
sizeof( V_188 ) ) ;
}
}
return 0 ;
}
static inline void F_89 ( struct V_14 * V_15 ,
unsigned int V_273 ,
unsigned int V_274 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
if ( V_273 ) {
F_30 ( 0 ,
V_34 -> V_38 + V_275 ) ;
F_30 ( 0 , V_34 -> V_38 + V_276 ) ;
F_30 ( 0 ,
V_34 -> V_38 + V_277 ) ;
F_30 ( V_274 ,
V_34 -> V_38 + V_278 ) ;
} else {
F_30 ( 0 ,
V_34 -> V_38 + V_279 ) ;
F_30 ( 0 , V_34 -> V_38 + V_280 ) ;
F_30 ( 0 ,
V_34 -> V_38 + V_281 ) ;
F_30 ( V_274 ,
V_34 -> V_38 + V_282 ) ;
}
}
static int F_90 ( struct V_14 * V_15 , struct V_160 * V_161 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_33 * V_34 = V_15 -> V_35 ;
struct V_283 * V_284 = V_161 -> V_284 ;
struct V_50 * V_51 = & V_284 -> V_51 ;
T_3 V_25 ;
unsigned int V_119 ;
unsigned long V_36 ;
int V_100 ;
F_37 ( V_15 ) ;
F_25 ( V_15 , 1 ) ;
V_100 = F_88 ( V_15 , V_51 ) ;
if ( V_100 < 0 )
return V_100 ;
F_32 ( 0 , V_34 -> V_48 + V_111 ) ;
F_86 ( V_15 , V_51 ) ;
F_77 ( V_15 , V_51 ) ;
F_33 ( V_15 , V_51 ) ;
F_26 ( & V_15 -> V_37 , V_36 ) ;
V_34 -> V_80 |= V_81 ;
V_34 -> V_80 &= ~ V_174 ;
if ( V_17 -> V_10 != V_11 ) {
V_34 -> V_80 &= ~ V_285 ;
if ( V_51 -> V_223 == V_239 )
V_34 -> V_80 |= F_7 ( 13 ) ;
else
V_34 -> V_80 |= F_7 ( 8 ) ;
} else {
V_34 -> V_80 &= ~ V_286 ;
if ( V_51 -> V_229 == 4 )
V_34 -> V_80 |= V_287 ;
else if ( V_51 -> V_229 == 2 )
V_34 -> V_80 |= V_288 ;
V_34 -> V_80 &= ~ V_289 ;
V_34 -> V_80 |=
F_5 ( F_58 ( V_51 -> V_231 [ 0 ] ) ) ;
V_34 -> V_80 &= ~ V_290 ;
V_34 -> V_80 |=
F_6 ( F_58 ( V_51 -> V_231
[ V_51 -> V_229 - 1 ] ) ) ;
}
F_32 ( V_34 -> V_80 ,
V_34 -> V_48 + V_82 ) ;
F_28 ( & V_15 -> V_37 , V_36 ) ;
F_32 ( 0 , V_34 -> V_48 + V_191 ) ;
if ( ( V_51 -> V_36 & V_52 ) == 0 ||
V_17 -> V_10 == V_11 ) {
V_34 -> V_291 = 0 ;
for ( V_119 = 0 ; V_119 < F_17 ( V_17 ) ; V_119 ++ )
V_34 -> V_127 [ V_119 ] . V_137 =
F_45 ( F_78 ( V_15 ) *
sizeof( T_1 ) ) ;
F_89 ( V_15 , 1 ,
V_34 -> V_129 |
V_139 |
V_140 |
V_141 ) ;
F_84 ( V_15 , 1 ) ;
}
if ( V_17 -> V_10 == V_11 ) {
V_25 = 0 ;
if ( V_51 -> V_238 == V_239 && F_58 ( V_51 -> V_246 ) )
V_25 |= V_292 ;
if ( V_51 -> V_244 == V_239 && F_58 ( V_51 -> V_249 ) )
V_25 |= V_293 ;
F_32 ( V_25 , V_34 -> V_48 + V_294 ) ;
}
F_26 ( & V_15 -> V_37 , V_36 ) ;
V_25 = V_295 | V_84 | V_85 ;
if ( V_51 -> V_36 & V_52 )
V_25 |= V_83 ;
if ( V_51 -> V_238 == V_239 ) {
V_25 |= V_296 ;
if ( V_51 -> V_246 & V_297 )
V_25 |= V_298 ;
} else if ( V_51 -> V_238 == V_226 )
V_25 |= V_299 ;
if ( F_76 ( V_51 ) )
V_25 |= V_300 ;
F_32 ( V_25 , V_34 -> V_48 + V_86 ) ;
V_34 -> V_301 = 1 ;
F_28 ( & V_15 -> V_37 , V_36 ) ;
if ( V_51 -> V_238 == V_226 )
F_32 ( 0 , V_34 -> V_48 + V_302 ) ;
return 0 ;
}
static void F_91 ( struct V_14 * V_15 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
struct V_160 * V_161 = V_15 -> V_303 ;
struct V_283 * V_284 = V_161 -> V_284 ;
struct V_50 * V_51 = & V_284 -> V_51 ;
unsigned int V_119 ;
T_1 V_6 ;
int V_304 , V_305 , V_306 , V_307 ;
int V_98 ;
do {
V_305 = F_56 ( V_34 -> V_48 + V_308 ) &
0x7fff ;
V_307 = F_56 ( V_34 -> V_48 + V_167 ) &
0x7fff ;
V_6 = F_56 ( V_34 -> V_48 + V_309 ) ;
V_304 = F_13 ( V_6 ) ;
V_306 = F_14 ( V_6 ) ;
if ( V_304 != V_306 )
V_98 =
V_34 -> V_97 - V_305 ;
else
V_98 = V_307 - V_305 ;
if ( V_51 -> V_244 == V_243 ) {
if ( V_34 -> V_250 == 0 )
break;
if ( V_98 > V_34 -> V_250 )
V_98 = V_34 -> V_250 ;
V_34 -> V_250 -= V_98 ;
}
if ( V_98 < 0 ) {
F_21 ( V_15 -> V_27 ,
L_12 ) ;
break;
}
for ( V_119 = 0 ; V_119 < V_98 ; V_119 ++ ) {
F_92 ( V_161 ,
F_56 ( V_34 -> V_48 +
V_135 ) ) ;
}
} while ( V_304 != V_306 );
}
static void F_93 ( struct V_14 * V_15 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
struct V_160 * V_161 = V_15 -> V_303 ;
struct V_283 * V_284 = V_161 -> V_284 ;
struct V_50 * V_51 = & V_284 -> V_51 ;
unsigned int V_119 ;
unsigned int V_310 = 100000 ;
T_3 V_311 ;
int V_312 =
F_56 ( V_34 -> V_48 + V_167 ) & 0x7fff ;
int V_313 =
F_56 ( V_34 -> V_48 + V_308 ) & 0x7fff ;
if ( V_51 -> V_244 == V_243 ) {
if ( V_310 > V_34 -> V_250 )
V_310 = V_34 -> V_250 ;
}
for ( V_119 = 0 ; V_313 != V_312 && V_119 < V_310 ; ) {
V_311 = F_35 ( V_15 -> V_193 + V_135 ) ;
F_92 ( V_161 , V_311 & 0xffff ) ;
V_119 ++ ;
if ( V_119 < V_310 ) {
F_92 ( V_161 , ( V_311 >> 16 ) & 0xffff ) ;
V_119 ++ ;
}
V_313 = F_56 ( V_34 -> V_48 + V_308 ) &
0x7fff ;
}
V_34 -> V_250 -= V_119 ;
}
static void F_94 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
if ( V_17 -> V_10 == V_11 )
F_93 ( V_15 ) ;
else
F_91 ( V_15 ) ;
}
static void F_95 ( struct V_14 * V_15 , unsigned int V_1 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_33 * V_34 = V_15 -> V_35 ;
struct V_283 * V_284 = V_15 -> V_303 -> V_284 ;
struct V_50 * V_51 = & V_284 -> V_51 ;
T_3 V_314 ;
int V_315 ;
int V_98 = 0 ;
void T_4 * V_316 ;
if ( V_1 )
V_316 =
V_34 -> V_38 + V_276 ;
else
V_316 =
V_34 -> V_38 + V_280 ;
for ( V_315 = 0 , V_314 = F_35 ( V_316 ) ;
( V_314 <
V_34 -> V_122 [ V_34 -> V_291 ] ||
V_314 >=
V_34 -> V_122 [ V_34 -> V_291 ] +
V_121 ) && V_315 < F_17 ( V_17 ) ; V_315 ++ ) {
V_98 = F_78 ( V_15 ) ;
if ( V_51 -> V_244 == V_243 ) {
if ( V_98 > V_34 -> V_250 )
V_98 = V_34 -> V_250 ;
V_34 -> V_250 -= V_98 ;
}
F_96 ( V_15 -> V_303 ,
V_34 -> V_120 [ V_34 ->
V_291 ] ,
V_98 * sizeof( T_1 ) ) ;
V_34 -> V_291 = ( V_34 -> V_291 + 1 ) %
F_17 ( V_17 ) ;
}
}
static void F_97 ( struct V_14 * V_15 ,
unsigned short V_165 ,
unsigned int V_317 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_33 * V_34 = V_15 -> V_35 ;
struct V_160 * V_161 = V_15 -> V_303 ;
struct V_283 * V_284 = V_161 -> V_284 ;
struct V_50 * V_51 = & V_284 -> V_51 ;
T_2 V_318 ;
unsigned long V_36 ;
if ( V_165 & V_319 ) {
F_21 ( V_15 -> V_27 , L_13 ) ;
V_284 -> V_320 |= V_321 | V_322 ;
}
F_26 ( & V_15 -> V_37 , V_36 ) ;
V_318 = F_98 ( V_34 -> V_38 + V_260 ) ;
if ( V_317 & V_323 ) {
F_85 ( ( V_318 & V_257 ) | V_259 ,
V_34 -> V_38 + V_260 ) ;
if ( V_318 & V_257 )
F_95 ( V_15 , 1 ) ;
}
F_28 ( & V_15 -> V_37 , V_36 ) ;
if ( ( V_165 & V_324 ) ||
( ( V_51 -> V_36 & V_52 ) &&
( V_165 & V_325 ) &&
( V_17 -> V_10 != V_11 ) ) ) {
F_26 ( & V_15 -> V_37 , V_36 ) ;
if ( V_34 -> V_301 ) {
F_28 ( & V_15 -> V_37 , V_36 ) ;
F_94 ( V_15 ) ;
} else
F_28 ( & V_15 -> V_37 , V_36 ) ;
}
if ( ( V_51 -> V_244 == V_243 && ( int ) V_34 -> V_250 <= 0 ) ||
( V_51 -> V_244 == V_239 && ( V_165 & V_326 ) ) ) {
V_284 -> V_320 |= V_321 ;
}
F_99 ( V_15 , V_161 ) ;
}
static inline unsigned int F_100 ( struct V_14 * V_15 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
unsigned int V_327 ;
if ( V_34 -> V_328 == 0 )
V_327 = V_124 - 1 ;
else
V_327 = V_34 -> V_328 - 1 ;
return V_327 ;
}
static int F_101 ( struct V_14 * V_15 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
unsigned int V_327 ;
unsigned int V_329 ;
unsigned short V_330 ;
V_327 = F_100 ( V_15 ) ;
V_330 = F_98 ( V_34 -> V_38 + V_261 ) ;
if ( ( V_330 & V_331 ) == 0 )
return 0 ;
V_329 =
F_35 ( V_34 -> V_38 + V_280 ) ;
if ( V_329 != V_34 -> V_126 [ V_327 ] )
return 0 ;
return 1 ;
}
static int F_102 ( struct V_14 * V_15 ,
const struct V_50 * V_51 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
if ( V_51 -> V_244 == V_245 )
return 1 ;
if ( V_51 -> V_244 == V_243 ) {
if ( V_34 -> V_332 )
return 1 ;
if ( F_101 ( V_15 ) == 0 )
return 1 ;
}
return 0 ;
}
static inline int F_103 ( struct V_14 * V_15 ,
unsigned short V_330 )
{
if ( ( V_330 & V_331 ) == 0 ||
( V_330 & V_257 ) == 0 )
return 0 ;
if ( F_101 ( V_15 ) )
return 0 ;
return 1 ;
}
static void F_104 ( struct V_14 * V_15 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
unsigned int V_333 ;
V_333 =
F_35 ( V_34 -> V_38 + V_282 ) ;
V_333 &= ~ V_334 ;
F_89 ( V_15 , 0 , V_333 ) ;
F_84 ( V_15 , 0 ) ;
}
static unsigned int F_105 ( struct V_14 * V_15 ,
const struct V_50 * V_51 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
unsigned int V_335 , V_327 , V_336 ;
unsigned int V_337 ;
V_327 = V_34 -> V_328 ;
V_336 = F_100 ( V_15 ) ;
V_335 = F_106 ( V_15 -> V_266 ) ;
if ( V_335 > V_121 )
V_335 = V_121 ;
if ( V_51 -> V_244 == V_243 && V_335 > V_34 -> V_332 )
V_335 = V_34 -> V_332 ;
V_335 -= V_335 % V_200 ;
if ( V_335 == 0 )
return 0 ;
V_335 = F_107 ( V_15 -> V_266 ,
V_34 ->
V_125 [ V_327 ] ,
V_335 ) ;
V_34 -> V_130 [ V_327 ] . V_137 =
F_45 ( V_335 ) ;
V_337 = F_108 ( V_34 -> V_130 [ V_327 ] . V_138 ) ;
V_337 |= V_334 ;
V_34 -> V_130 [ V_327 ] . V_138 = F_45 ( V_337 ) ;
V_337 = F_108 ( V_34 -> V_130 [ V_336 ] . V_138 ) ;
V_337 &= ~ V_334 ;
V_34 -> V_130 [ V_336 ] . V_138 = F_45 ( V_337 ) ;
V_34 -> V_328 = ( V_327 + 1 ) % V_124 ;
V_34 -> V_332 -= V_335 ;
return V_335 ;
}
static void F_109 ( struct V_14 * V_15 , const struct V_50 * V_51 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
unsigned int V_335 ;
unsigned int V_314 ;
void T_4 * V_316 =
V_34 -> V_38 + V_280 ;
unsigned int V_327 ;
do {
V_327 = V_34 -> V_328 ;
V_314 = F_35 ( V_316 ) ;
if ( V_314 >=
V_34 -> V_126 [ V_327 ] &&
V_314 <
V_34 -> V_126 [ V_327 ] +
V_121 )
return;
V_335 = F_105 ( V_15 , V_51 ) ;
} while ( V_335 >= V_121 );
}
static void F_110 ( struct V_14 * V_15 ,
unsigned short V_165 , unsigned int V_317 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
struct V_160 * V_161 = V_15 -> V_266 ;
struct V_283 * V_284 ;
struct V_50 * V_51 ;
T_2 V_338 ;
unsigned long V_36 ;
if ( V_161 == NULL )
return;
V_284 = V_161 -> V_284 ;
V_51 = & V_284 -> V_51 ;
F_26 ( & V_15 -> V_37 , V_36 ) ;
V_338 = F_98 ( V_34 -> V_38 + V_261 ) ;
if ( V_317 & V_339 ) {
if ( ( V_338 & V_257 ) &&
! ( V_338 & V_331 ) )
F_85 ( V_257 | V_259 ,
V_34 -> V_38 + V_261 ) ;
else
F_85 ( V_259 ,
V_34 -> V_38 + V_261 ) ;
F_28 ( & V_15 -> V_37 , V_36 ) ;
if ( V_338 & V_257 ) {
F_109 ( V_15 , V_51 ) ;
if ( F_103 ( V_15 , V_338 ) )
F_104 ( V_15 ) ;
}
} else {
F_28 ( & V_15 -> V_37 , V_36 ) ;
}
if ( ( V_165 & V_340 ) ) {
V_284 -> V_320 |= V_321 ;
if ( F_102 ( V_15 , V_51 ) )
V_284 -> V_320 |= V_322 ;
}
F_99 ( V_15 , V_161 ) ;
}
static T_5 F_111 ( int V_341 , void * V_342 )
{
struct V_14 * V_15 = V_342 ;
struct V_33 * V_34 = V_15 -> V_35 ;
unsigned short V_165 ;
T_3 V_317 ;
T_3 V_343 ;
V_317 = F_35 ( V_34 -> V_38 + V_40 ) ;
V_165 = F_56 ( V_34 -> V_48 + V_166 ) ;
if ( ! V_15 -> V_344 )
return V_345 ;
F_97 ( V_15 , V_165 , V_317 ) ;
F_110 ( V_15 , V_165 , V_317 ) ;
if ( V_317 & V_346 ) {
V_343 = F_35 ( V_34 -> V_38 + V_347 ) ;
F_30 ( V_343 , V_34 -> V_38 + V_347 ) ;
}
return V_345 ;
}
static int F_112 ( struct V_14 * V_15 , struct V_160 * V_161 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
unsigned long V_36 ;
F_26 ( & V_15 -> V_37 , V_36 ) ;
if ( V_34 -> V_301 == 0 ) {
F_28 ( & V_15 -> V_37 , V_36 ) ;
return 0 ;
}
V_34 -> V_301 = 0 ;
F_28 ( & V_15 -> V_37 , V_36 ) ;
F_37 ( V_15 ) ;
F_25 ( V_15 , 1 ) ;
return 0 ;
}
static int F_113 ( struct V_14 * V_15 , struct V_160 * V_161 ,
struct V_162 * V_163 , unsigned int * V_155 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_33 * V_34 = V_15 -> V_35 ;
int V_233 = F_58 ( V_163 -> V_172 ) ;
int V_23 = F_59 ( V_163 -> V_172 ) ;
F_32 ( 0 , V_34 -> V_48 + V_348 ) ;
F_23 ( V_15 , & V_34 -> V_113 , V_233 , V_23 ) ;
F_32 ( V_34 -> V_113 ,
V_34 -> V_48 + V_349 ) ;
if ( V_17 -> V_10 == V_11 ) {
F_32 ( V_155 [ 0 ] & 0xff ,
V_34 -> V_48 + F_2 ( V_233 ) ) ;
F_32 ( ( V_155 [ 0 ] >> 8 ) & 0xf ,
V_34 -> V_48 + F_3 ( V_233 ) ) ;
} else {
F_32 ( V_155 [ 0 ] , V_34 -> V_48 + F_1 ( V_233 ) ) ;
}
V_34 -> V_350 [ V_233 ] = V_155 [ 0 ] ;
return 1 ;
}
static int F_114 ( struct V_14 * V_15 ,
struct V_160 * V_161 ,
struct V_162 * V_163 , unsigned int * V_155 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
V_155 [ 0 ] = V_34 -> V_350 [ F_58 ( V_163 -> V_172 ) ] ;
return 1 ;
}
static void F_115 ( struct V_14 * V_15 ,
const struct V_50 * V_51 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
unsigned int V_25 = V_351 | V_352 |
V_353 | V_354 ;
if ( V_51 -> V_238 == V_239 ) {
V_25 |= V_355 ;
if ( V_51 -> V_246 & V_297 )
V_25 |= V_356 ;
} else {
V_25 |= V_357 ;
}
if ( V_51 -> V_227 == V_239 ) {
V_25 |= V_358 ;
if ( V_51 -> V_228 & V_297 )
V_25 |= V_359 ;
}
F_32 ( V_25 , V_34 -> V_48 + V_348 ) ;
}
static void F_116 ( struct V_14 * V_15 ,
const struct V_50 * V_51 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
int V_119 ;
for ( V_119 = 0 ; V_119 < V_51 -> V_229 ; V_119 ++ ) {
int V_1 , V_23 ;
V_1 = F_58 ( V_51 -> V_231 [ V_119 ] ) ;
V_23 = F_59 ( V_51 -> V_231 [ V_119 ] ) ;
F_23 ( V_15 , & V_34 -> V_113 , V_1 ,
V_23 ) ;
}
V_34 -> V_113 |= V_360 ;
F_32 ( V_34 -> V_113 ,
V_34 -> V_48 + V_349 ) ;
}
static void F_117 ( struct V_14 * V_15 ,
const struct V_50 * V_51 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
T_1 V_25 ;
unsigned int V_361 , V_362 ;
V_361 = F_58 ( V_51 -> V_231 [ 0 ] ) ;
V_362 = F_58 ( V_51 -> V_231 [ V_51 -> V_229 - 1 ] ) ;
if ( V_362 < V_361 )
F_21 ( V_15 -> V_27 ,
L_14 ) ;
V_25 = ( V_361 & 0x7 ) | ( V_362 & 0x7 ) << 3 ;
F_32 ( V_25 , V_34 -> V_48 + V_363 ) ;
}
static unsigned int F_118 ( unsigned int V_209 , unsigned int V_36 )
{
return F_68 ( V_209 , V_36 ) - 2 ;
}
static void F_119 ( struct V_14 * V_15 ,
const struct V_50 * V_51 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
unsigned int V_201 ;
if ( V_51 -> V_227 != V_224 )
return;
V_201 = F_118 ( V_51 -> V_228 , V_51 -> V_36 ) ;
if ( V_201 > V_219 ) {
F_21 ( V_15 -> V_27 , L_15 ) ;
V_201 = V_219 ;
}
F_32 ( V_201 & 0xffff ,
V_34 -> V_48 + V_364 ) ;
F_32 ( ( V_201 >> 16 ) & 0xff ,
V_34 -> V_48 + V_365 ) ;
}
static int F_120 ( struct V_14 * V_15 , const struct V_50 * V_51 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
unsigned int V_335 ;
int V_119 ;
F_32 ( 0 , V_34 -> V_48 + V_269 ) ;
F_32 ( 0 , V_34 -> V_48 + V_268 ) ;
V_335 = ( V_366 / 2 ) * V_200 ;
if ( V_51 -> V_244 == V_243 &&
V_335 / V_200 > V_34 -> V_332 )
V_335 = V_34 -> V_332 * V_200 ;
V_335 = F_107 ( V_15 -> V_266 ,
V_34 -> V_367 ,
V_335 ) ;
for ( V_119 = 0 ; V_119 < V_335 / V_200 ; V_119 ++ ) {
F_32 ( V_34 -> V_367 [ V_119 ] ,
V_34 -> V_48 + V_142 ) ;
}
V_34 -> V_332 -= V_335 / V_200 ;
if ( V_51 -> V_244 == V_243 && V_34 -> V_332 == 0 )
return 0 ;
V_335 = F_105 ( V_15 , V_51 ) ;
if ( V_335 == 0 )
return - 1 ;
F_109 ( V_15 , V_51 ) ;
F_84 ( V_15 , 0 ) ;
return 0 ;
}
static inline int F_121 ( struct V_14 * V_15 ,
struct V_160 * V_161 ,
struct V_50 * V_51 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
if ( V_161 -> V_267 )
return 0 ;
if ( V_17 -> V_10 == V_11 )
return 0 ;
else if ( F_87 ( V_51 ) )
return 0 ;
return 1 ;
}
static int F_122 ( struct V_14 * V_15 , struct V_160 * V_161 ,
unsigned int V_368 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
struct V_50 * V_51 = & V_161 -> V_284 -> V_51 ;
int V_100 ;
if ( V_368 != V_51 -> V_246 )
return - V_196 ;
V_100 = F_120 ( V_15 , V_51 ) ;
if ( V_100 < 0 )
return - V_369 ;
F_115 ( V_15 , V_51 ) ;
if ( V_51 -> V_238 == V_370 )
F_32 ( 0 , V_34 -> V_48 + V_371 ) ;
V_161 -> V_284 -> V_372 = NULL ;
return 0 ;
}
static int F_123 ( struct V_14 * V_15 , struct V_160 * V_161 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
struct V_50 * V_51 = & V_161 -> V_284 -> V_51 ;
if ( F_121 ( V_15 , V_161 , V_51 ) ) {
F_46 ( V_15 ) ;
return - V_168 ;
}
F_32 ( 0x0 , V_34 -> V_48 + V_348 ) ;
V_34 -> V_328 = 0 ;
V_34 -> V_332 = V_51 -> V_249 * V_51 -> V_229 ;
F_117 ( V_15 , V_51 ) ;
F_119 ( V_15 , V_51 ) ;
F_89 ( V_15 , 0 , V_34 -> V_131 |
V_139 | V_140 ) ;
F_116 ( V_15 , V_51 ) ;
V_161 -> V_284 -> V_372 = F_122 ;
return 0 ;
}
static int F_124 ( struct V_14 * V_15 ,
struct V_160 * V_161 ,
struct V_50 * V_51 )
{
unsigned int V_232 = F_58 ( V_51 -> V_231 [ 0 ] ) ;
int V_119 ;
for ( V_119 = 1 ; V_119 < V_51 -> V_229 ; V_119 ++ ) {
unsigned int V_233 = F_58 ( V_51 -> V_231 [ V_119 ] ) ;
if ( V_233 != ( V_232 + V_119 ) ) {
F_63 ( V_15 -> V_27 ,
L_9 ) ;
return - V_196 ;
}
}
return 0 ;
}
static int F_125 ( struct V_14 * V_15 , struct V_160 * V_161 ,
struct V_50 * V_51 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
int V_234 = 0 ;
unsigned int V_235 ;
V_234 |= F_72 ( & V_51 -> V_238 , V_370 | V_239 ) ;
V_234 |= F_72 ( & V_51 -> V_227 ,
V_224 | V_239 ) ;
V_234 |= F_72 ( & V_51 -> V_223 , V_226 ) ;
V_234 |= F_72 ( & V_51 -> V_242 , V_243 ) ;
V_234 |= F_72 ( & V_51 -> V_244 , V_245 ) ;
if ( V_234 )
return 1 ;
V_234 |= F_73 ( V_51 -> V_238 ) ;
V_234 |= F_73 ( V_51 -> V_227 ) ;
if ( V_51 -> V_223 == V_239 && V_51 -> V_227 == V_224 )
V_234 |= - V_196 ;
if ( V_51 -> V_244 != V_243 &&
V_51 -> V_244 != V_245 && V_51 -> V_244 != V_239 )
V_234 |= - V_196 ;
if ( V_234 )
return 2 ;
V_234 |= F_74 ( & V_51 -> V_246 , 0 ) ;
if ( V_51 -> V_227 == V_224 ) {
V_234 |= F_75 ( & V_51 -> V_228 ,
V_17 -> V_373 ) ;
if ( F_118 ( V_51 -> V_228 , V_51 -> V_36 ) >
V_219 ) {
V_51 -> V_228 = ( V_219 + 2 ) *
V_212 ;
V_234 |= - V_196 ;
}
}
V_234 |= F_75 ( & V_51 -> V_229 , 1 ) ;
V_234 |= F_74 ( & V_51 -> V_248 , V_51 -> V_229 ) ;
if ( V_234 )
return 3 ;
if ( V_51 -> V_227 == V_224 ) {
V_235 = V_51 -> V_228 ;
V_51 -> V_228 = F_68 ( V_51 -> V_228 ,
V_51 -> V_36 ) * V_212 ;
if ( V_235 != V_51 -> V_228 )
V_234 ++ ;
}
if ( V_234 )
return 4 ;
if ( V_51 -> V_231 && V_51 -> V_229 > 0 )
V_234 |= F_124 ( V_15 , V_161 , V_51 ) ;
if ( V_234 )
return 5 ;
return 0 ;
}
static int F_126 ( struct V_14 * V_15 , struct V_160 * V_161 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
F_32 ( 0x0 , V_34 -> V_48 + V_348 ) ;
F_25 ( V_15 , 0 ) ;
return 0 ;
}
static int F_127 ( int V_374 , int V_375 , int V_155 , unsigned long V_376 )
{
void T_4 * V_377 = ( void T_4 * ) V_376 ;
if ( V_374 ) {
F_85 ( V_155 , V_377 + V_375 ) ;
return 0 ;
}
return F_98 ( V_377 + V_375 ) ;
}
static int F_128 ( int V_374 , int V_375 , int V_155 , unsigned long V_376 )
{
void T_4 * V_377 = ( void T_4 * ) V_376 ;
if ( V_374 ) {
F_32 ( V_155 , V_377 + 2 * V_375 ) ;
return 0 ;
}
return F_56 ( V_377 + 2 * V_375 ) ;
}
static int F_129 ( struct V_14 * V_15 , struct V_160 * V_161 ,
struct V_162 * V_163 , unsigned int * V_155 )
{
unsigned int V_25 ;
V_25 = F_98 ( V_15 -> V_193 + V_378 ) ;
V_25 &= 0xf ;
V_155 [ 1 ] = V_25 ;
V_155 [ 0 ] = 0 ;
return V_163 -> V_169 ;
}
static int F_130 ( struct V_14 * V_15 ,
struct V_160 * V_161 ,
struct V_162 * V_163 ,
unsigned int * V_155 )
{
if ( F_131 ( V_161 , V_155 ) )
F_85 ( V_161 -> V_143 , V_15 -> V_193 + V_379 ) ;
V_155 [ 1 ] = V_161 -> V_143 ;
return V_163 -> V_169 ;
}
static int F_132 ( struct V_14 * V_15 ,
struct V_160 * V_161 ,
struct V_162 * V_163 ,
unsigned int * V_155 )
{
int V_171 ;
V_171 = F_133 ( V_15 , V_161 , V_163 , V_155 , 0 ) ;
if ( V_171 )
return V_171 ;
F_85 ( V_161 -> V_380 , V_15 -> V_193 + V_381 ) ;
return V_163 -> V_169 ;
}
static int F_134 ( struct V_14 * V_15 ,
struct V_160 * V_161 ,
struct V_162 * V_163 ,
unsigned int * V_155 )
{
if ( F_131 ( V_161 , V_155 ) )
F_85 ( V_161 -> V_143 , V_15 -> V_193 + V_382 ) ;
V_155 [ 1 ] = F_98 ( V_15 -> V_193 + V_382 ) ;
return V_163 -> V_169 ;
}
static int F_135 ( struct V_14 * V_15 , unsigned int V_154 ,
T_2 V_383 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
static const int V_384 = 8 ;
static const int V_385 = 11 ;
unsigned int V_157 = ( ( V_154 & 0x7 ) << 8 ) | V_383 ;
unsigned int V_152 , V_386 ;
static const int V_387 = 1 ;
if ( V_154 >= V_384 ) {
F_21 ( V_15 -> V_27 , L_16 ) ;
return - 1 ;
}
for ( V_152 = 1 << ( V_385 - 1 ) ; V_152 ; V_152 >>= 1 ) {
V_386 = 0 ;
if ( V_157 & V_152 )
V_386 |= V_388 ;
F_48 ( V_387 ) ;
F_32 ( V_386 , V_34 -> V_48 + V_111 ) ;
V_386 |= V_389 ;
F_48 ( V_387 ) ;
F_32 ( V_386 , V_34 -> V_48 + V_111 ) ;
}
F_48 ( V_387 ) ;
F_32 ( V_390 , V_34 -> V_48 + V_111 ) ;
F_48 ( V_387 ) ;
F_32 ( 0 , V_34 -> V_48 + V_111 ) ;
F_48 ( V_387 ) ;
return 0 ;
}
static int F_136 ( struct V_14 * V_15 ,
unsigned int V_391 , unsigned int V_383 )
{
T_2 V_392 [ 3 ] ;
T_2 V_393 ;
enum T_6 {
V_394 = 0x1 ,
V_395 = 0x2 ,
V_396 = 0x4 ,
V_397 = 0x8 ,
};
enum T_7 {
V_398 = 0x20 ,
};
switch ( V_391 ) {
case 0 :
V_393 = V_399 ;
V_392 [ 0 ] = V_394 ;
break;
case 1 :
V_393 = V_399 ;
V_392 [ 0 ] = V_396 ;
break;
case 2 :
V_393 = V_400 ;
V_392 [ 0 ] = V_394 ;
break;
case 3 :
V_393 = V_400 ;
V_392 [ 0 ] = V_396 ;
break;
case 4 :
V_393 = V_399 ;
V_392 [ 0 ] = V_395 ;
break;
case 5 :
V_393 = V_399 ;
V_392 [ 0 ] = V_397 ;
break;
case 6 :
V_393 = V_400 ;
V_392 [ 0 ] = V_395 ;
break;
case 7 :
V_393 = V_400 ;
V_392 [ 0 ] = V_397 ;
break;
default:
F_21 ( V_15 -> V_27 , L_17 ) ;
return - 1 ;
}
V_392 [ 1 ] = V_398 | ( ( V_383 >> 8 ) & 0xf ) ;
V_392 [ 2 ] = V_383 & 0xff ;
F_54 ( V_15 , V_393 , V_392 , 3 ) ;
return 0 ;
}
static void F_137 ( struct V_14 * V_15 , unsigned int V_1 ,
unsigned int V_383 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_33 * V_34 = V_15 -> V_35 ;
V_34 -> V_401 [ V_1 ] = V_383 ;
switch ( V_17 -> V_10 ) {
case V_19 :
case V_18 :
F_135 ( V_15 , V_1 , V_383 ) ;
break;
case V_11 :
F_136 ( V_15 , V_1 , V_383 ) ;
break;
default:
break;
}
}
static int F_138 ( struct V_14 * V_15 ,
struct V_160 * V_161 ,
struct V_162 * V_163 , unsigned int * V_155 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
int V_1 = F_58 ( V_163 -> V_172 ) ;
if ( V_34 -> V_401 [ V_1 ] == V_155 [ 0 ] )
return 1 ;
F_137 ( V_15 , V_1 , V_155 [ 0 ] ) ;
return 1 ;
}
static int F_139 ( struct V_14 * V_15 ,
struct V_160 * V_161 , struct V_162 * V_163 ,
unsigned int * V_155 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
unsigned int V_1 = F_58 ( V_163 -> V_172 ) ;
V_155 [ 0 ] = V_34 -> V_401 [ V_1 ] ;
return 1 ;
}
static void F_140 ( struct V_14 * V_15 , unsigned int V_1 ,
unsigned int V_383 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
static const int V_385 = 10 ;
unsigned int V_152 , V_386 ;
unsigned int V_157 = ( ( V_1 & 0x3 ) << 8 ) | ( V_383 & 0xff ) ;
static const int V_402 = 1 ;
V_34 -> V_403 [ V_1 ] = V_383 ;
V_386 = V_404 ;
F_48 ( V_402 ) ;
F_32 ( V_386 , V_34 -> V_48 + V_111 ) ;
for ( V_152 = 1 << ( V_385 - 1 ) ; V_152 ; V_152 >>= 1 ) {
if ( V_157 & V_152 )
V_386 |= V_388 ;
else
V_386 &= ~ V_388 ;
F_48 ( V_402 ) ;
F_32 ( V_386 , V_34 -> V_48 + V_111 ) ;
F_48 ( V_402 ) ;
F_32 ( V_386 | V_389 ,
V_34 -> V_48 + V_111 ) ;
}
F_48 ( V_402 ) ;
F_32 ( 0 , V_34 -> V_48 + V_111 ) ;
}
static int F_141 ( struct V_14 * V_15 ,
struct V_160 * V_161 ,
struct V_162 * V_163 , unsigned int * V_155 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
int V_1 = F_58 ( V_163 -> V_172 ) ;
if ( V_34 -> V_403 [ V_1 ] == V_155 [ 0 ] )
return 1 ;
V_34 -> V_403 [ V_1 ] = V_155 [ 0 ] ;
F_140 ( V_15 , V_1 , V_155 [ 0 ] ) ;
return 1 ;
}
static int F_142 ( struct V_14 * V_15 ,
struct V_160 * V_161 ,
struct V_162 * V_163 , unsigned int * V_155 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
unsigned int V_1 = F_58 ( V_163 -> V_172 ) ;
V_155 [ 0 ] = V_34 -> V_403 [ V_1 ] ;
return 1 ;
}
static T_1 F_143 ( struct V_14 * V_15 , T_2 V_154 )
{
struct V_33 * V_34 = V_15 -> V_35 ;
static const int V_385 = 11 ;
static const int V_405 = 0x6 ;
unsigned int V_157 = ( V_405 << 8 ) | V_154 ;
unsigned int V_152 ;
void T_4 * const V_146 =
V_34 -> V_38 + V_56 ;
T_1 V_383 ;
static const int V_406 = 16 ;
static const int V_407 = 1 ;
F_48 ( V_407 ) ;
V_34 -> V_55 &= ~ V_408 & ~ V_159 ;
V_34 -> V_55 |= V_150 ;
F_30 ( V_34 -> V_55 , V_146 ) ;
F_48 ( V_407 ) ;
V_34 -> V_55 |= V_159 ;
F_30 ( V_34 -> V_55 , V_146 ) ;
for ( V_152 = 1 << ( V_385 - 1 ) ; V_152 ; V_152 >>= 1 ) {
F_48 ( V_407 ) ;
if ( V_157 & V_152 )
V_34 -> V_55 |= V_145 ;
else
V_34 -> V_55 &= ~ V_145 ;
F_30 ( V_34 -> V_55 , V_146 ) ;
F_48 ( V_407 ) ;
V_34 -> V_55 |= V_408 ;
F_30 ( V_34 -> V_55 , V_146 ) ;
F_48 ( V_407 ) ;
V_34 -> V_55 &= ~ V_408 ;
F_30 ( V_34 -> V_55 , V_146 ) ;
}
V_383 = 0 ;
for ( V_152 = 1 << ( V_406 - 1 ) ; V_152 ; V_152 >>= 1 ) {
F_48 ( V_407 ) ;
V_34 -> V_55 |= V_408 ;
F_30 ( V_34 -> V_55 , V_146 ) ;
F_48 ( V_407 ) ;
V_34 -> V_55 &= ~ V_408 ;
F_30 ( V_34 -> V_55 , V_146 ) ;
F_48 ( V_407 ) ;
if ( F_35 ( V_146 ) & V_409 )
V_383 |= V_152 ;
}
F_48 ( V_407 ) ;
V_34 -> V_55 &= ~ V_159 ;
F_30 ( V_34 -> V_55 , V_146 ) ;
return V_383 ;
}
static int F_144 ( struct V_14 * V_15 ,
struct V_160 * V_161 ,
struct V_162 * V_163 , unsigned int * V_155 )
{
V_155 [ 0 ] = F_143 ( V_15 , F_58 ( V_163 -> V_172 ) ) ;
return 1 ;
}
static int F_145 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_33 * V_34 = V_15 -> V_35 ;
struct V_160 * V_161 ;
void T_4 * V_410 ;
int V_119 ;
int V_171 ;
V_171 = F_146 ( V_15 , 10 ) ;
if ( V_171 )
return V_171 ;
V_161 = & V_15 -> V_411 [ 0 ] ;
V_15 -> V_303 = V_161 ;
V_161 -> type = V_412 ;
V_161 -> V_413 = V_414 | V_415 | V_416 | V_417 ;
if ( V_17 -> V_10 == V_19 )
V_161 -> V_413 |= V_418 | V_419 ;
else if ( V_17 -> V_10 == V_18 )
V_161 -> V_413 |= V_419 ;
V_161 -> V_420 = V_17 -> V_421 ;
V_161 -> V_422 = 0x2000 ;
V_161 -> V_423 = ( 1 << V_17 -> V_424 ) - 1 ;
V_161 -> V_425 = V_17 -> V_24 ;
V_161 -> V_426 = F_57 ;
V_161 -> V_427 = F_67 ;
V_161 -> V_428 = F_90 ;
V_161 -> V_429 = F_71 ;
V_161 -> V_430 = F_112 ;
if ( V_17 -> V_10 == V_11 ) {
T_2 V_155 ;
V_34 -> V_187 = F_15 ( 4 ) ;
for ( V_119 = 0 ; V_119 < V_161 -> V_420 ; V_119 ++ )
V_34 -> V_187 |= F_16 ( V_119 ) ;
V_155 = V_34 -> V_187 ;
F_54 ( V_15 , V_189 , & V_155 , sizeof( V_155 ) ) ;
}
V_161 = & V_15 -> V_411 [ 1 ] ;
if ( V_17 -> V_32 ) {
V_161 -> type = V_431 ;
V_161 -> V_413 = V_414 | V_432 |
V_415 | V_433 ;
V_161 -> V_420 = V_17 -> V_32 ;
V_161 -> V_423 = ( 1 << V_17 -> V_434 ) - 1 ;
V_161 -> V_425 = V_17 -> V_435 ;
V_161 -> V_426 = F_114 ;
V_161 -> V_436 = F_113 ;
if ( F_24 ( V_17 ) ) {
V_15 -> V_266 = V_161 ;
V_161 -> V_429 = F_125 ;
V_161 -> V_428 = F_123 ;
V_161 -> V_422 = V_17 -> V_32 ;
V_161 -> V_430 = F_126 ;
}
} else {
V_161 -> type = V_437 ;
}
V_161 = & V_15 -> V_411 [ 2 ] ;
if ( V_17 -> V_10 == V_18 ) {
V_161 -> type = V_438 ;
V_161 -> V_413 = V_414 ;
V_161 -> V_420 = 4 ;
V_161 -> V_423 = 1 ;
V_161 -> V_425 = & V_439 ;
V_161 -> V_440 = F_129 ;
} else
V_161 -> type = V_437 ;
if ( V_17 -> V_10 == V_18 ) {
V_161 = & V_15 -> V_411 [ 3 ] ;
V_161 -> type = V_441 ;
V_161 -> V_413 = V_432 | V_414 ;
V_161 -> V_420 = 4 ;
V_161 -> V_423 = 1 ;
V_161 -> V_425 = & V_439 ;
V_161 -> V_440 = F_130 ;
} else
V_161 -> type = V_437 ;
V_161 = & V_15 -> V_411 [ 4 ] ;
if ( V_17 -> V_442 ) {
if ( V_17 -> V_10 == V_11 ) {
V_410 = V_34 -> V_48 + V_443 ;
V_171 = F_147 ( V_15 , V_161 , F_128 ,
( unsigned long ) V_410 ) ;
} else {
V_410 = V_15 -> V_193 + V_444 ;
V_171 = F_147 ( V_15 , V_161 , F_127 ,
( unsigned long ) V_410 ) ;
}
if ( V_171 )
return V_171 ;
} else {
V_161 -> type = V_437 ;
}
V_161 = & V_15 -> V_411 [ 5 ] ;
if ( V_17 -> V_10 == V_19 ) {
V_161 -> type = V_445 ;
V_161 -> V_413 = V_432 | V_414 ;
V_161 -> V_420 = 8 ;
V_161 -> V_423 = 1 ;
V_161 -> V_425 = & V_439 ;
V_161 -> V_427 = F_132 ;
V_161 -> V_440 = F_134 ;
} else
V_161 -> type = V_437 ;
V_161 = & V_15 -> V_411 [ 6 ] ;
V_161 -> type = V_446 ;
V_161 -> V_413 = V_414 | V_432 | V_447 ;
V_161 -> V_420 = 8 ;
if ( V_17 -> V_10 == V_11 )
V_161 -> V_423 = 0xfff ;
else
V_161 -> V_423 = 0xff ;
V_161 -> V_426 = F_139 ;
V_161 -> V_436 = F_138 ;
for ( V_119 = 0 ; V_119 < V_161 -> V_420 ; V_119 ++ )
F_137 ( V_15 , V_119 , V_161 -> V_423 / 2 ) ;
V_161 = & V_15 -> V_411 [ 7 ] ;
if ( V_17 -> V_10 == V_18 ) {
V_161 -> type = V_446 ;
V_161 -> V_413 = V_414 | V_432 | V_447 ;
V_161 -> V_420 = 2 ;
V_161 -> V_426 = F_142 ;
V_161 -> V_436 = F_141 ;
V_161 -> V_423 = 0xff ;
for ( V_119 = 0 ; V_119 < V_161 -> V_420 ; V_119 ++ )
F_140 ( V_15 , V_119 , V_161 -> V_423 / 2 ) ;
} else
V_161 -> type = V_437 ;
V_161 = & V_15 -> V_411 [ 8 ] ;
if ( F_35 ( V_34 -> V_38 + V_56 ) & V_448 ) {
V_161 -> type = V_449 ;
V_161 -> V_413 = V_414 | V_447 ;
V_161 -> V_420 = 128 ;
V_161 -> V_423 = 0xffff ;
V_161 -> V_426 = F_144 ;
} else
V_161 -> type = V_437 ;
V_161 = & V_15 -> V_411 [ 9 ] ;
V_161 -> type = V_437 ;
return 0 ;
}
static int F_148 ( struct V_14 * V_15 ,
unsigned long V_164 )
{
struct V_117 * V_118 = F_43 ( V_15 ) ;
const struct V_8 * V_17 = NULL ;
struct V_33 * V_34 ;
T_3 V_450 , V_451 ;
int V_100 ;
if ( V_164 < F_149 ( V_452 ) )
V_17 = & V_452 [ V_164 ] ;
if ( ! V_17 )
return - V_453 ;
V_15 -> V_454 = V_17 ;
V_34 = F_150 ( V_15 , sizeof( * V_34 ) ) ;
if ( ! V_34 )
return - V_123 ;
V_100 = F_151 ( V_15 ) ;
if ( V_100 )
return V_100 ;
F_152 ( V_118 ) ;
V_15 -> V_455 = V_17 -> V_456 ;
V_34 -> V_457 = F_153 ( V_118 , 2 ) ;
V_34 -> V_458 = F_153 ( V_118 , 3 ) ;
V_34 -> V_38 = F_154 ( V_118 , 0 ) ;
V_34 -> V_48 = F_154 ( V_118 , 2 ) ;
V_15 -> V_193 = F_154 ( V_118 , 3 ) ;
if ( ! V_34 -> V_38 || ! V_34 -> V_48 || ! V_15 -> V_193 ) {
F_155 ( V_15 -> V_27 , L_18 ) ;
return - V_123 ;
}
V_450 = F_35 ( V_34 -> V_38 + V_459 ) &
V_460 ;
V_451 = F_35 ( V_34 -> V_38 + V_461 ) &
V_450 & V_462 ;
V_34 -> V_136 = ( ( T_3 ) V_34 -> V_457 &
~ V_450 ) | V_451 ;
V_450 = F_35 ( V_34 -> V_38 + V_463 ) &
V_460 ;
V_451 = F_35 ( V_34 -> V_38 + V_464 ) &
V_450 & V_462 ;
V_34 -> V_134 = ( ( T_3 ) V_34 -> V_458 &
~ V_450 ) | V_451 ;
V_100 = F_42 ( V_15 ) ;
if ( V_100 < 0 )
return V_100 ;
V_34 -> F_22 =
F_22 ( V_15 , F_56 ( V_34 -> V_48 + V_166 ) ) ;
F_63 ( V_15 -> V_27 , L_19 ,
V_34 -> F_22 ) ;
F_34 ( V_15 ) ;
F_41 ( V_15 ) ;
V_100 = F_156 ( V_118 -> V_341 , F_111 , V_465 ,
V_15 -> V_455 , V_15 ) ;
if ( V_100 ) {
F_63 ( V_15 -> V_27 , L_20 ,
V_118 -> V_341 ) ;
return V_100 ;
}
V_15 -> V_341 = V_118 -> V_341 ;
F_63 ( V_15 -> V_27 , L_21 , V_15 -> V_341 ) ;
V_100 = F_145 ( V_15 ) ;
if ( V_100 < 0 )
return V_100 ;
return 0 ;
}
static void F_157 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_117 * V_118 = F_43 ( V_15 ) ;
struct V_33 * V_34 = V_15 -> V_35 ;
unsigned int V_119 ;
if ( V_15 -> V_341 )
F_158 ( V_15 -> V_341 , V_15 ) ;
if ( V_34 ) {
if ( V_118 ) {
if ( V_34 -> V_38 ) {
F_29 ( V_15 ) ;
F_159 ( V_34 -> V_38 ) ;
}
if ( V_34 -> V_48 )
F_159 ( V_34 -> V_48 ) ;
if ( V_15 -> V_193 )
F_159 ( V_15 -> V_193 ) ;
for ( V_119 = 0 ; V_119 < F_17 ( V_17 ) ; V_119 ++ ) {
if ( V_34 -> V_120 [ V_119 ] )
F_160 ( V_118 ,
V_121 ,
V_34 -> V_120 [ V_119 ] ,
V_34 -> V_122 [ V_119 ] ) ;
}
for ( V_119 = 0 ; V_119 < V_124 ; V_119 ++ ) {
if ( V_34 -> V_125 [ V_119 ] )
F_160 ( V_118 ,
V_121 ,
V_34 -> V_125 [ V_119 ] ,
V_34 -> V_126 [ V_119 ] ) ;
}
if ( V_34 -> V_127 )
F_160 ( V_118 ,
sizeof( struct V_128 ) *
F_17 ( V_17 ) ,
V_34 -> V_127 ,
V_34 -> V_129 ) ;
if ( V_34 -> V_130 )
F_160 ( V_118 ,
sizeof( struct V_128 ) *
V_124 ,
V_34 -> V_130 ,
V_34 -> V_131 ) ;
}
}
F_161 ( V_15 ) ;
}
static int F_162 ( struct V_117 * V_15 ,
const struct V_466 * V_205 )
{
return F_163 ( V_15 , & V_467 ,
V_205 -> V_468 ) ;
}
