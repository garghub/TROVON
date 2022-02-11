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
const struct V_8 * V_9 = V_15 -> V_17 ;
if ( ( V_9 -> V_10 == V_18 && ! V_16 ) ||
( V_9 -> V_10 == V_19 && V_16 ) )
return V_20 ;
return 0 ;
}
static unsigned int F_19 ( const struct V_14 * V_15 ,
unsigned int V_21 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
return V_9 -> V_22 [ V_21 ] << 8 ;
}
static unsigned int F_20 ( const struct V_14 * V_15 ,
T_1 V_5 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
if ( V_9 -> V_10 == V_11 )
return ( V_5 >> 13 ) & 0x7 ;
return ( V_5 >> 12 ) & 0xf ;
}
static void F_21 ( struct V_14 * V_15 ,
T_1 * V_23 , unsigned int V_1 ,
unsigned int V_24 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
unsigned int V_25 = V_9 -> V_26 [ V_24 ] ;
if ( V_1 > 1 )
F_22 ( V_15 -> V_27 , L_1 ) ;
if ( V_25 & ~ 0x3 )
F_22 ( V_15 -> V_27 , L_2 ) ;
* V_23 &= ~ ( 0x3 << ( 2 * V_1 ) ) ;
* V_23 |= V_25 << ( 2 * V_1 ) ;
}
static inline int F_23 ( const struct V_8 * V_9 )
{
return V_9 -> V_28 && V_9 -> V_10 != V_11 ;
}
static void F_24 ( struct V_14 * V_15 , unsigned int V_1 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned long V_32 ;
F_25 ( & V_15 -> V_33 , V_32 ) ;
F_26 ( V_30 -> V_34 , V_1 ) ;
F_27 ( & V_15 -> V_33 , V_32 ) ;
}
static void F_28 ( struct V_14 * V_15 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
V_30 -> V_35 = 0 ;
F_29 ( V_30 -> V_35 ,
V_30 -> V_34 + V_36 ) ;
}
static void F_30 ( struct V_14 * V_15 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned long V_32 ;
F_25 ( & V_15 -> V_33 , V_32 ) ;
V_30 -> V_37 &=
~ V_38 & ~ V_39 &
~ V_40 & ~ V_41 &
~ V_42 & ~ V_43 ;
F_31 ( V_30 -> V_37 ,
V_30 -> V_44 + V_45 ) ;
F_27 ( & V_15 -> V_33 , V_32 ) ;
}
static void F_32 ( struct V_14 * V_15 ,
const struct V_46 * V_47 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
struct V_29 * V_30 = V_15 -> V_31 ;
T_3 V_23 ;
unsigned long V_32 ;
V_23 = V_42 | V_39 |
V_40 | V_41 ;
if ( V_47 -> V_32 & V_48 ) {
if ( V_9 -> V_10 != V_11 )
V_23 |= V_49 | V_38 ;
}
F_25 ( & V_15 -> V_33 , V_32 ) ;
V_30 -> V_37 |= V_23 ;
F_31 ( V_30 -> V_37 ,
V_30 -> V_44 + V_45 ) ;
F_27 ( & V_15 -> V_33 , V_32 ) ;
}
static void F_33 ( struct V_14 * V_15 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
struct V_29 * V_30 = V_15 -> V_31 ;
T_3 V_23 ;
void T_4 * V_50 = V_30 -> V_34 ;
V_30 -> V_51 =
F_34 ( V_30 -> V_34 + V_52 ) ;
#ifdef F_35
V_23 = V_53 | V_54 ;
#else
V_23 = 0 ;
#endif
F_29 ( V_23 , V_30 -> V_34 + V_55 ) ;
F_28 ( V_15 ) ;
F_24 ( V_15 , 0 ) ;
F_24 ( V_15 , 1 ) ;
V_23 = 0 ;
V_23 |= V_56 ;
V_23 |= V_57 ;
V_23 |= V_58 ;
V_23 |= V_59 ;
V_23 |= V_60 ;
V_23 |= V_61 ;
V_23 |= V_62 ;
V_23 |= V_63 ;
if ( V_9 -> V_10 == V_11 )
V_23 |= V_64 ;
else
V_23 |= V_65 ;
F_29 ( V_23 , V_50 + V_66 ) ;
if ( F_23 ( V_9 ) )
F_29 ( V_23 , V_50 + V_67 ) ;
V_30 -> V_35 |=
V_68 | V_69 | V_70 | V_71 | V_72 | V_73 |
V_74 | V_75 ;
F_29 ( V_30 -> V_35 ,
V_30 -> V_34 + V_36 ) ;
}
static void F_36 ( struct V_14 * V_15 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned long V_32 ;
F_30 ( V_15 ) ;
F_25 ( & V_15 -> V_33 , V_32 ) ;
V_30 -> V_76 &= ~ V_77 ;
F_31 ( V_30 -> V_76 ,
V_30 -> V_44 + V_78 ) ;
F_27 ( & V_15 -> V_33 , V_32 ) ;
F_31 ( V_79 | V_80 | V_81 ,
V_30 -> V_44 + V_82 ) ;
}
static int F_37 ( struct V_14 * V_15 ,
unsigned int V_83 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
struct V_29 * V_30 = V_15 -> V_31 ;
static const int V_84 = 0x100 ;
const struct V_85 * const V_86 = V_9 -> V_87 ;
unsigned int V_88 ;
T_1 V_23 ;
if ( V_83 < V_84 )
V_83 = V_84 ;
if ( V_83 > V_86 -> V_89 )
V_83 = V_86 -> V_89 ;
V_88 = ( V_83 + V_84 / 2 ) / V_84 ;
V_23 = ( ~ ( V_88 - 1 ) ) & V_86 -> V_90 ;
V_30 -> V_91 &= ~ V_86 -> V_90 ;
V_30 -> V_91 |= V_23 ;
F_31 ( V_30 -> V_91 ,
V_30 -> V_44 + V_92 ) ;
V_30 -> V_93 = V_88 * V_84 ;
return V_30 -> V_93 ;
}
static int F_38 ( struct V_14 * V_15 , unsigned int V_94 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
unsigned int V_95 ;
int V_96 ;
const struct V_85 * const V_86 = V_9 -> V_87 ;
V_95 = V_94 / V_86 -> V_97 ;
V_96 = F_37 ( V_15 ,
V_95 /
V_86 -> V_98 ) ;
if ( V_96 < 0 )
return V_96 ;
V_94 = V_96 * V_86 -> V_98 * V_86 -> V_97 ;
return V_94 ;
}
static unsigned int F_39 ( struct V_14 * V_15 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
struct V_29 * V_30 = V_15 -> V_31 ;
return V_30 -> V_93 *
V_9 -> V_87 -> V_98 *
V_9 -> V_87 -> V_97 ;
}
static void F_40 ( struct V_14 * V_15 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
struct V_29 * V_30 = V_15 -> V_31 ;
T_1 V_23 ;
unsigned long V_32 ;
F_25 ( & V_15 -> V_33 , V_32 ) ;
if ( 1 )
V_30 -> V_76 |= V_99 ;
F_31 ( V_30 -> V_76 ,
V_30 -> V_44 + V_78 ) ;
F_31 ( 0xff , V_30 -> V_44 + V_100 ) ;
V_23 = V_101 | V_102 ;
if ( V_9 -> V_10 == V_11 )
V_23 |= V_103 ;
V_30 -> V_104 |= V_23 ;
F_31 ( V_30 -> V_104 ,
V_30 -> V_44 + V_105 ) ;
F_31 ( 0 , V_30 -> V_44 + V_106 ) ;
F_31 ( 0 , V_30 -> V_44 + V_107 ) ;
F_27 ( & V_15 -> V_33 , V_32 ) ;
V_30 -> V_91 |= V_108 ;
F_37 ( V_15 , V_9 -> V_87 -> V_89 ) ;
V_30 -> V_109 = V_110 ;
V_30 -> V_37 =
V_111 | V_112 ;
F_31 ( V_30 -> V_37 ,
V_30 -> V_44 + V_45 ) ;
F_36 ( V_15 ) ;
}
static int F_41 ( struct V_14 * V_15 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
struct V_113 * V_114 = F_42 ( V_15 ) ;
struct V_29 * V_30 = V_15 -> V_31 ;
int V_115 ;
for ( V_115 = 0 ; V_115 < F_17 ( V_9 ) ; V_115 ++ ) {
V_30 -> V_116 [ V_115 ] =
F_43 ( V_114 , V_117 ,
& V_30 -> V_118 [ V_115 ] ) ;
if ( ! V_30 -> V_116 [ V_115 ] )
return - V_119 ;
}
for ( V_115 = 0 ; V_115 < V_120 ; V_115 ++ ) {
if ( F_23 ( V_9 ) ) {
V_30 -> V_121 [ V_115 ] =
F_43 ( V_114 , V_117 ,
& V_30 ->
V_122 [ V_115 ] ) ;
if ( ! V_30 -> V_121 [ V_115 ] )
return - V_119 ;
}
}
V_30 -> V_123 =
F_43 ( V_114 , sizeof( struct V_124 ) *
F_17 ( V_9 ) ,
& V_30 -> V_125 ) ;
if ( ! V_30 -> V_123 )
return - V_119 ;
if ( F_23 ( V_9 ) ) {
V_30 -> V_126 =
F_43 ( V_114 ,
sizeof( struct V_124 ) *
V_120 ,
& V_30 -> V_127 ) ;
if ( ! V_30 -> V_126 )
return - V_119 ;
}
for ( V_115 = 0 ; V_115 < F_17 ( V_9 ) ; V_115 ++ ) {
V_30 -> V_123 [ V_115 ] . V_128 =
F_44 ( V_30 -> V_118 [ V_115 ] ) ;
if ( V_9 -> V_10 == V_11 )
V_30 -> V_123 [ V_115 ] . V_129 =
F_44 ( V_30 -> V_130 +
V_131 ) ;
else
V_30 -> V_123 [ V_115 ] . V_129 =
F_44 ( V_30 -> V_132 +
V_131 ) ;
V_30 -> V_123 [ V_115 ] . V_133 = F_44 ( 0 ) ;
V_30 -> V_123 [ V_115 ] . V_134 =
F_44 ( ( V_30 -> V_125 +
( ( V_115 + 1 ) % F_17 ( V_9 ) ) *
sizeof( V_30 -> V_123 [ 0 ] ) ) |
V_135 | V_136 |
V_137 ) ;
}
if ( F_23 ( V_9 ) ) {
for ( V_115 = 0 ; V_115 < V_120 ; V_115 ++ ) {
V_30 -> V_126 [ V_115 ] . V_128 =
F_44 ( V_30 -> V_122 [ V_115 ] ) ;
V_30 -> V_126 [ V_115 ] . V_129 =
F_44 ( V_30 -> V_132 +
V_138 ) ;
V_30 -> V_126 [ V_115 ] . V_133 = F_44 ( 0 ) ;
V_30 -> V_126 [ V_115 ] . V_134 =
F_44 ( ( V_30 -> V_127 +
( ( V_115 + 1 ) % ( V_120 ) ) *
sizeof( V_30 -> V_126 [ 0 ] ) ) |
V_135 |
V_136 ) ;
}
}
return 0 ;
}
static void F_45 ( struct V_14 * V_15 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
struct V_113 * V_114 = F_42 ( V_15 ) ;
struct V_29 * V_30 = V_15 -> V_31 ;
int V_115 ;
if ( ! V_30 )
return;
for ( V_115 = 0 ; V_115 < F_17 ( V_9 ) ; V_115 ++ ) {
if ( V_30 -> V_116 [ V_115 ] )
F_46 ( V_114 ,
V_117 ,
V_30 -> V_116 [ V_115 ] ,
V_30 -> V_118 [ V_115 ] ) ;
}
for ( V_115 = 0 ; V_115 < V_120 ; V_115 ++ ) {
if ( V_30 -> V_121 [ V_115 ] )
F_46 ( V_114 ,
V_117 ,
V_30 -> V_121 [ V_115 ] ,
V_30 -> V_122 [ V_115 ] ) ;
}
if ( V_30 -> V_123 )
F_46 ( V_114 ,
sizeof( struct V_124 ) *
F_17 ( V_9 ) ,
V_30 -> V_123 ,
V_30 -> V_125 ) ;
if ( V_30 -> V_126 )
F_46 ( V_114 ,
sizeof( struct V_124 ) *
V_120 ,
V_30 -> V_126 ,
V_30 -> V_127 ) ;
}
static inline void F_47 ( struct V_14 * V_15 )
{
F_22 ( V_15 -> V_27 ,
L_3 ) ;
F_22 ( V_15 -> V_27 ,
L_4 ) ;
}
static void F_48 ( struct V_14 * V_15 , int V_139 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
static const int V_140 = V_141 ;
void T_4 * V_142 = V_30 -> V_34 +
V_52 ;
if ( V_139 ) {
V_30 -> V_51 &= ~ V_140 ;
F_29 ( V_30 -> V_51 , V_142 ) ;
F_49 ( V_143 ) ;
} else {
V_30 -> V_51 |= V_140 ;
F_29 ( V_30 -> V_51 , V_142 ) ;
F_49 ( V_144 ) ;
}
}
static void F_50 ( struct V_14 * V_15 , int V_139 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
static const int V_145 = V_146 ;
void T_4 * V_142 = V_30 -> V_34 +
V_52 ;
if ( V_139 ) {
V_30 -> V_51 &= ~ V_145 ;
F_29 ( V_30 -> V_51 , V_142 ) ;
F_49 ( V_143 ) ;
} else {
V_30 -> V_51 |= V_145 ;
F_29 ( V_30 -> V_51 , V_142 ) ;
F_49 ( V_144 ) ;
}
}
static void F_51 ( struct V_14 * V_15 , T_2 V_147 )
{
T_2 V_148 ;
unsigned int V_149 = 8 ;
for ( V_148 = 1 << ( V_149 - 1 ) ; V_148 ; V_148 >>= 1 ) {
F_50 ( V_15 , 0 ) ;
if ( ( V_147 & V_148 ) )
F_48 ( V_15 , 1 ) ;
else
F_48 ( V_15 , 0 ) ;
F_50 ( V_15 , 1 ) ;
}
}
static int F_52 ( struct V_14 * V_15 )
{
F_50 ( V_15 , 0 ) ;
F_48 ( V_15 , 1 ) ;
F_50 ( V_15 , 1 ) ;
return 0 ;
}
static void F_53 ( struct V_14 * V_15 )
{
F_50 ( V_15 , 1 ) ;
F_48 ( V_15 , 1 ) ;
F_48 ( V_15 , 0 ) ;
}
static void F_54 ( struct V_14 * V_15 )
{
F_50 ( V_15 , 0 ) ;
F_48 ( V_15 , 0 ) ;
F_50 ( V_15 , 1 ) ;
F_48 ( V_15 , 1 ) ;
}
static void F_55 ( struct V_14 * V_15 , unsigned int V_150 ,
const T_2 * V_151 , unsigned int V_152 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned int V_115 ;
T_2 V_153 ;
static const int V_154 = 0x1 ;
V_30 -> V_51 &= ~ V_155 ;
F_54 ( V_15 ) ;
F_53 ( V_15 ) ;
V_153 = ( V_150 << 1 ) & ~ V_154 ;
F_51 ( V_15 , V_153 ) ;
if ( F_52 ( V_15 ) != 0 ) {
F_22 ( V_15 -> V_27 , L_5 ) ;
F_54 ( V_15 ) ;
return;
}
for ( V_115 = 0 ; V_115 < V_152 ; V_115 ++ ) {
F_51 ( V_15 , V_151 [ V_115 ] ) ;
if ( F_52 ( V_15 ) != 0 ) {
F_22 ( V_15 -> V_27 , L_5 ) ;
F_54 ( V_15 ) ;
return;
}
}
F_54 ( V_15 ) ;
}
static int F_56 ( struct V_14 * V_15 ,
struct V_156 * V_157 ,
struct V_158 * V_159 ,
unsigned long V_160 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned int V_161 ;
V_161 = F_57 ( V_30 -> V_44 + V_162 ) ;
if ( V_9 -> V_10 == V_11 ) {
V_161 = F_57 ( V_30 -> V_44 + V_163 ) ;
if ( V_161 )
return 0 ;
} else {
if ( F_11 ( V_161 ) )
return 0 ;
}
return - V_164 ;
}
static int F_58 ( struct V_14 * V_15 , struct V_156 * V_157 ,
struct V_158 * V_159 , unsigned int * V_151 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned int V_23 = 0 , V_165 ;
unsigned int V_1 , V_24 , V_166 ;
unsigned long V_32 ;
int V_167 ;
V_1 = F_59 ( V_159 -> V_168 ) ;
V_24 = F_60 ( V_159 -> V_168 ) ;
V_166 = F_61 ( V_159 -> V_168 ) ;
F_36 ( V_15 ) ;
F_25 ( & V_15 -> V_33 , V_32 ) ;
if ( V_159 -> V_168 & V_169 )
V_30 -> V_76 |= V_170 ;
else
V_30 -> V_76 &= ~ V_170 ;
F_31 ( V_30 -> V_76 ,
V_30 -> V_44 + V_78 ) ;
F_27 ( & V_15 -> V_33 , V_32 ) ;
if ( V_9 -> V_10 != V_11 ) {
V_30 -> V_104 &= ~ V_171 ;
F_31 ( V_30 -> V_104 ,
V_30 -> V_44 + V_105 ) ;
if ( V_159 -> V_168 & V_172 ) {
unsigned int V_173 ;
if ( V_9 -> V_10 == V_19 )
V_173 = V_174 ;
else
V_173 = V_175 ;
F_31 ( V_173 |
F_8 ( V_30 -> V_176 ) ,
V_30 -> V_44 + V_107 ) ;
} else {
F_31 ( 0 , V_30 -> V_44 + V_107 ) ;
}
V_23 = 0 ;
V_23 |= F_19 ( V_15 , F_60 ( V_159 -> V_168 ) ) ;
V_23 |= F_18 ( V_15 , V_166 == V_177 ) ;
if ( V_166 == V_178 )
V_23 |= V_179 ;
V_23 |= F_10 ( V_1 ) ;
F_31 ( F_10 ( V_1 ) ,
V_30 -> V_44 + V_180 ) ;
F_31 ( V_23 , V_30 -> V_44 + V_181 ) ;
} else {
T_2 V_182 = V_30 -> V_183 ;
V_30 -> V_183 &= ~ V_7 ;
if ( V_159 -> V_168 & V_172 ) {
V_30 -> V_183 |=
F_15 ( V_30 -> V_176 ) ;
} else {
V_30 -> V_183 |= F_15 ( 4 ) ;
}
if ( V_24 == 0 )
V_30 -> V_183 |= F_16 ( V_1 ) ;
else
V_30 -> V_183 &= ~ F_16 ( V_1 ) ;
if ( V_182 != V_30 -> V_183 ) {
T_2 V_184 = V_30 -> V_183 ;
F_55 ( V_15 , V_185 , & V_184 ,
sizeof( V_184 ) ) ;
}
F_31 ( 0 , V_30 -> V_44 + V_100 ) ;
F_31 ( 2 , V_30 -> V_44 + V_186 ) ;
}
for ( V_165 = 0 ; V_165 < V_159 -> V_165 ; V_165 ++ ) {
F_31 ( 0 , V_30 -> V_44 + V_187 ) ;
F_31 ( F_9 ( F_59 ( V_159 -> V_168 ) ) ,
V_30 -> V_44 + V_188 ) ;
V_167 = F_62 ( V_15 , V_157 , V_159 , F_56 , 0 ) ;
if ( V_167 )
return V_167 ;
if ( V_9 -> V_10 == V_11 )
V_151 [ V_165 ] = F_34 ( V_15 -> V_189 + V_131 ) & 0xffff ;
else
V_151 [ V_165 ] = F_57 ( V_30 -> V_44 + V_190 ) ;
}
return V_165 ;
}
static int F_63 ( struct V_14 * V_15 ,
unsigned int * V_151 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned int V_4 = V_151 [ 1 ] ;
int V_191 ;
if ( V_9 -> V_10 == V_19 )
V_191 = 16 ;
else
V_191 = 8 ;
if ( V_4 >= V_191 ) {
F_64 ( V_15 -> V_27 , L_6 ,
V_4 ) ;
return - V_192 ;
}
V_30 -> V_176 = V_4 ;
return 2 ;
}
static int F_65 ( struct V_14 * V_15 , unsigned int * V_151 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
int V_193 ;
const struct V_85 * const V_86 = V_9 -> V_87 ;
unsigned int V_194 , V_195 ;
int V_96 ;
V_195 = V_151 [ 1 ] ;
if ( V_195 ) {
V_193 = V_195 * V_86 -> V_98 /
V_196 ;
V_96 = F_38 ( V_15 , V_193 ) ;
if ( V_96 < 0 )
return V_96 ;
}
V_194 = F_39 ( V_15 ) / V_86 -> V_98 * V_196 ;
V_151 [ 1 ] = V_194 ;
return 2 ;
}
static int F_66 ( struct V_14 * V_15 ,
unsigned int * V_151 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned int V_197 = V_151 [ 4 ] ;
int V_96 = 0 ;
if ( V_197 < 2 ) {
V_197 = 2 ;
V_96 = - V_198 ;
}
switch ( V_151 [ 1 ] ) {
case V_199 :
V_30 -> V_200 . V_197 = V_197 ;
V_30 -> V_200 . V_168 = V_151 [ 2 ] ;
break;
default:
return - V_192 ;
}
V_151 [ 4 ] = V_197 ;
return V_96 ? V_96 : 5 ;
}
static int F_67 ( struct V_14 * V_15 , unsigned int * V_151 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
switch ( V_9 -> V_10 ) {
case V_11 :
return F_66 ( V_15 , V_151 ) ;
default:
return - V_192 ;
}
return - V_192 ;
}
static int F_68 ( struct V_14 * V_15 , struct V_156 * V_157 ,
struct V_158 * V_159 , unsigned int * V_151 )
{
int V_201 = V_151 [ 0 ] ;
switch ( V_201 ) {
case V_202 :
return F_63 ( V_15 , V_151 ) ;
case V_203 :
return F_65 ( V_15 , V_151 ) ;
case V_204 :
return F_67 ( V_15 , V_151 ) ;
default:
return - V_192 ;
}
return - V_192 ;
}
static unsigned int F_69 ( unsigned int V_205 , unsigned int V_32 )
{
unsigned int V_197 ;
switch ( V_32 & V_206 ) {
case V_207 :
V_197 = ( V_205 + V_208 - 1 ) / V_208 ;
break;
case V_209 :
V_197 = V_205 / V_208 ;
break;
case V_210 :
default:
V_197 = ( V_205 + V_208 / 2 ) / V_208 ;
break;
}
return V_197 ;
}
static void F_70 ( struct V_14 * V_15 , struct V_46 * V_47 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
unsigned long long V_211 = 0 ;
unsigned int V_212 ;
static const int V_213 = 3 ;
static const int V_214 =
V_215 + V_213 ;
static const int V_216 = 2 ;
unsigned long long V_217 , V_218 ;
if ( V_47 -> V_219 == V_220 ) {
if ( V_9 -> V_10 == V_11 ) {
V_47 -> V_221 = 0 ;
} else {
V_211 = F_69 ( V_47 -> V_221 ,
V_47 -> V_32 ) ;
if ( V_211 > V_214 )
V_211 = V_214 ;
if ( V_211 < V_213 )
V_211 = V_213 ;
V_47 -> V_221 = V_211 * V_208 ;
}
} else if ( V_47 -> V_219 == V_222 ) {
V_47 -> V_221 = 0 ;
}
if ( V_47 -> V_223 == V_220 ) {
V_212 = F_69 ( V_47 -> V_224 , V_47 -> V_32 ) ;
if ( V_47 -> V_219 == V_220 ) {
V_218 = V_211 * V_47 -> V_225 ;
V_217 =
( V_211 * V_47 -> V_225 - 1 ) +
V_215 ;
} else {
V_218 = V_216 ;
V_217 = V_215 + V_218 ;
}
if ( V_212 > V_217 )
V_212 = V_217 ;
if ( V_212 < V_218 )
V_212 = V_218 ;
V_47 -> V_224 = V_212 * V_208 ;
}
}
static int F_71 ( struct V_14 * V_15 ,
struct V_156 * V_157 ,
struct V_46 * V_47 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
unsigned int V_226 = F_61 ( V_47 -> V_227 [ 0 ] ) ;
int V_115 ;
for ( V_115 = 1 ; V_115 < V_47 -> V_225 ; V_115 ++ ) {
unsigned int V_166 = F_61 ( V_47 -> V_227 [ V_115 ] ) ;
if ( V_166 != V_226 ) {
F_64 ( V_15 -> V_27 ,
L_7 ) ;
return - V_192 ;
}
}
if ( V_9 -> V_10 == V_11 ) {
unsigned int V_228 = F_59 ( V_47 -> V_227 [ 0 ] ) ;
for ( V_115 = 1 ; V_115 < V_47 -> V_225 ; V_115 ++ ) {
unsigned int V_229 = F_59 ( V_47 -> V_227 [ V_115 ] ) ;
if ( V_229 != ( V_228 + V_115 ) ) {
F_64 ( V_15 -> V_27 ,
L_8 ) ;
return - V_192 ;
}
}
if ( V_47 -> V_225 == 3 ) {
F_64 ( V_15 -> V_27 ,
L_9 ) ;
return - V_192 ;
}
}
return 0 ;
}
static int F_72 ( struct V_14 * V_15 , struct V_156 * V_157 ,
struct V_46 * V_47 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
int V_230 = 0 ;
unsigned int V_231 , V_232 ;
unsigned int V_233 ;
V_230 |= F_73 ( & V_47 -> V_234 , V_222 | V_235 ) ;
V_233 = V_220 ;
if ( V_9 -> V_10 == V_11 )
V_233 |= V_236 ;
else
V_233 |= V_237 ;
V_230 |= F_73 ( & V_47 -> V_223 , V_233 ) ;
V_233 = V_220 ;
if ( V_9 -> V_10 == V_11 )
V_233 |= V_222 ;
else
V_233 |= V_235 ;
V_230 |= F_73 ( & V_47 -> V_219 , V_233 ) ;
V_230 |= F_73 ( & V_47 -> V_238 , V_239 ) ;
V_230 |= F_73 ( & V_47 -> V_240 ,
V_239 | V_235 | V_241 ) ;
if ( V_230 )
return 1 ;
V_230 |= F_74 ( V_47 -> V_234 ) ;
V_230 |= F_74 ( V_47 -> V_223 ) ;
V_230 |= F_74 ( V_47 -> V_219 ) ;
V_230 |= F_74 ( V_47 -> V_240 ) ;
if ( V_47 -> V_219 == V_235 && V_47 -> V_223 == V_220 )
V_230 |= - V_192 ;
if ( V_230 )
return 2 ;
switch ( V_47 -> V_234 ) {
case V_222 :
V_230 |= F_75 ( & V_47 -> V_242 , 0 ) ;
break;
case V_235 :
break;
}
if ( V_47 -> V_219 == V_220 ) {
if ( V_9 -> V_10 == V_11 ) {
V_230 |= F_75 ( & V_47 -> V_221 ,
0 ) ;
} else {
V_230 |= F_76 ( & V_47 -> V_221 ,
V_9 -> V_243 ) ;
if ( V_47 -> V_223 == V_220 ) {
V_230 |= F_76 (
& V_47 -> V_224 ,
V_47 -> V_221 *
V_47 -> V_225 ) ;
}
}
}
V_230 |= F_76 ( & V_47 -> V_225 , 1 ) ;
V_230 |= F_75 ( & V_47 -> V_244 ,
V_47 -> V_225 ) ;
switch ( V_47 -> V_240 ) {
case V_235 :
break;
case V_239 :
V_230 |= F_76 ( & V_47 -> V_245 , 1 ) ;
break;
case V_241 :
V_230 |= F_75 ( & V_47 -> V_245 , 0 ) ;
break;
default:
break;
}
if ( V_230 )
return 3 ;
if ( V_47 -> V_219 == V_220 ) {
V_231 = V_47 -> V_221 ;
V_232 = V_47 -> V_224 ;
F_70 ( V_15 , V_47 ) ;
if ( V_231 != V_47 -> V_221 )
V_230 ++ ;
if ( V_232 != V_47 -> V_224 )
V_230 ++ ;
}
if ( V_230 )
return 4 ;
if ( V_47 -> V_227 && V_47 -> V_225 > 0 )
V_230 |= F_71 ( V_15 , V_157 , V_47 ) ;
if ( V_230 )
return 5 ;
return 0 ;
}
static int F_77 ( struct V_46 * V_47 )
{
return 0 ;
if ( V_47 -> V_240 == V_239 && V_47 -> V_245 <= V_215 )
return 1 ;
return 0 ;
}
static void F_78 ( struct V_14 * V_15 ,
struct V_46 * V_47 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
if ( F_77 ( V_47 ) ) {
F_31 ( V_47 -> V_245 & 0xffff ,
V_30 -> V_44 + V_246 ) ;
F_31 ( ( V_47 -> V_245 >> 16 ) & 0xff ,
V_30 -> V_44 + V_247 ) ;
} else {
F_31 ( 1 , V_30 -> V_44 + V_246 ) ;
}
}
static inline unsigned int F_79 ( struct V_14 * V_15 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned int V_94 ;
V_94 = V_30 -> V_93 *
V_9 -> V_87 -> V_97 ;
if ( V_94 > V_117 / sizeof( T_1 ) )
V_94 = V_117 / sizeof( T_1 ) ;
return V_94 ;
}
static T_3 F_80 ( const struct V_14 * V_15 ,
const struct V_46 * V_47 )
{
return V_47 -> V_221 / V_208 - 3 ;
}
static T_3 F_81 ( struct V_14 * V_15 ,
struct V_46 * V_47 )
{
T_3 V_248 ;
switch ( V_47 -> V_223 ) {
case V_220 :
V_248 = ( V_47 -> V_224 -
( V_47 -> V_221 * ( V_47 -> V_225 - 1 ) ) ) /
V_208 ;
break;
case V_237 :
V_248 = V_47 -> V_221 / V_208 ;
break;
default:
return 0 ;
}
return V_248 - 3 ;
}
static T_3 F_82 ( struct V_14 * V_15 ,
struct V_46 * V_47 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned int V_197 ;
switch ( V_47 -> V_223 ) {
case V_220 :
V_197 = V_47 -> V_224 / V_208 ;
break;
case V_236 :
V_197 = V_30 -> V_200 . V_197 ;
break;
default:
F_22 ( V_15 -> V_27 , L_10 ) ;
V_197 = 1000 ;
break;
}
return V_197 - 2 ;
}
static void F_83 ( struct V_14 * V_15 ,
const struct V_46 * V_47 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
V_30 -> V_104 &= ~ V_249 ;
if ( V_47 -> V_223 == V_236 ) {
int V_168 = V_30 -> V_200 . V_168 ;
if ( F_59 ( V_168 ) )
V_30 -> V_104 |= V_250 ;
else
V_30 -> V_104 |= V_251 ;
} else {
V_30 -> V_104 |= V_103 ;
}
F_31 ( V_30 -> V_104 ,
V_30 -> V_44 + V_105 ) ;
}
static void F_84 ( struct V_14 * V_15 ,
const struct V_46 * V_47 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
switch ( V_9 -> V_10 ) {
case V_11 :
F_83 ( V_15 , V_47 ) ;
break;
default:
break;
}
}
static inline void F_85 ( struct V_14 * V_15 ,
unsigned int V_1 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned long V_32 ;
F_25 ( & V_15 -> V_33 , V_32 ) ;
if ( V_1 )
F_86 ( V_252 | V_253 |
V_254 ,
V_30 -> V_34 + V_255 ) ;
else
F_86 ( V_252 | V_253 |
V_254 ,
V_30 -> V_34 + V_256 ) ;
F_27 ( & V_15 -> V_33 , V_32 ) ;
}
static void F_87 ( struct V_14 * V_15 , struct V_46 * V_47 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
struct V_29 * V_30 = V_15 -> V_31 ;
T_3 V_257 = 0 , V_258 = 0 ;
F_70 ( V_15 , V_47 ) ;
F_84 ( V_15 , V_47 ) ;
if ( V_9 -> V_10 == V_11 ) {
V_257 = F_82 ( V_15 , V_47 ) ;
} else {
V_257 = F_80 ( V_15 , V_47 ) ;
V_258 = F_81 ( V_15 , V_47 ) ;
}
F_31 ( V_257 & 0xffff ,
V_30 -> V_44 + V_186 ) ;
F_31 ( ( V_257 >> 16 ) & 0xff ,
V_30 -> V_44 + V_100 ) ;
F_31 ( V_258 & 0xffff ,
V_30 -> V_44 + V_259 ) ;
F_31 ( ( V_258 >> 16 ) & 0xff ,
V_30 -> V_44 + V_260 ) ;
}
static int F_88 ( const struct V_46 * V_47 )
{
int V_115 ;
for ( V_115 = 0 ; V_115 + 1 < V_47 -> V_225 ; V_115 ++ ) {
if ( F_59 ( V_47 -> V_227 [ V_115 + 1 ] ) !=
F_59 ( V_47 -> V_227 [ V_115 ] ) + 1 )
return 0 ;
if ( F_60 ( V_47 -> V_227 [ V_115 + 1 ] ) !=
F_60 ( V_47 -> V_227 [ V_115 ] ) )
return 0 ;
if ( F_61 ( V_47 -> V_227 [ V_115 + 1 ] ) != F_61 ( V_47 -> V_227 [ V_115 ] ) )
return 0 ;
}
return 1 ;
}
static int F_89 ( struct V_14 * V_15 ,
const struct V_46 * V_47 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned short V_23 ;
int V_115 ;
if ( V_9 -> V_10 != V_11 ) {
if ( F_88 ( V_47 ) ) {
V_30 -> V_104 &= ~ V_171 ;
F_31 ( V_30 -> V_104 ,
V_30 -> V_44 + V_105 ) ;
V_23 = 0 ;
V_23 |= F_10 ( F_59 ( V_47 -> V_227 [ 0 ] ) ) ;
V_23 |= F_19 ( V_15 ,
F_60 ( V_47 -> V_227 [ 0 ] ) ) ;
V_23 |= F_18 ( V_15 ,
F_61 ( V_47 -> V_227 [ 0 ] ) ==
V_177 ) ;
if ( F_61 ( V_47 -> V_227 [ 0 ] ) == V_178 )
V_23 |= V_179 ;
F_31 ( F_10
( F_59 ( V_47 -> V_227 [ V_47 -> V_225 - 1 ] ) ) ,
V_30 -> V_44 + V_180 ) ;
F_31 ( V_23 ,
V_30 -> V_44 + V_181 ) ;
} else {
if ( V_15 -> V_261 && V_15 -> V_261 -> V_262 ) {
F_47 ( V_15 ) ;
return - V_164 ;
}
V_30 -> V_104 |= V_171 ;
F_31 ( V_30 -> V_104 ,
V_30 -> V_44 + V_105 ) ;
F_31 ( 0 ,
V_30 -> V_44 + V_263 ) ;
F_31 ( 0 , V_30 -> V_44 + V_264 ) ;
for ( V_115 = 0 ; V_115 < V_47 -> V_225 ; V_115 ++ ) {
V_23 = 0 ;
V_23 |= F_10 ( F_59 ( V_47 ->
V_227 [ V_115 ] ) ) ;
V_23 |= F_19 ( V_15 ,
F_60 ( V_47 ->
V_227
[ V_115 ] ) ) ;
V_23 |= F_18 ( V_15 ,
F_61 ( V_47 ->
V_227 [ V_115 ] ) ==
V_177 ) ;
if ( F_61 ( V_47 -> V_227 [ V_115 ] ) == V_178 )
V_23 |= V_179 ;
if ( V_115 == V_47 -> V_225 - 1 )
V_23 |= V_265 |
V_266 ;
F_31 ( V_23 ,
V_30 -> V_44 +
V_267 ) ;
}
F_31 ( 0 , V_30 -> V_44 + V_264 ) ;
F_31 ( 0 , V_30 -> V_44 + V_181 ) ;
}
} else {
unsigned short V_182 = V_30 -> V_183 ;
V_30 -> V_183 &= ~ V_7 ;
V_30 -> V_183 |= F_15 ( 4 ) ;
for ( V_115 = 0 ; V_115 < V_47 -> V_225 ; V_115 ++ ) {
unsigned int V_1 = F_59 ( V_47 -> V_227 [ V_115 ] ) ;
unsigned int V_24 = F_60 ( V_47 -> V_227 [ V_115 ] ) ;
if ( V_24 == 0 )
V_30 -> V_183 |=
F_16 ( V_1 ) ;
else
V_30 -> V_183 &=
~ F_16 ( V_1 ) ;
}
if ( V_182 != V_30 -> V_183 ) {
T_2 V_184 = V_30 -> V_183 ;
F_55 ( V_15 , V_185 , & V_184 ,
sizeof( V_184 ) ) ;
}
}
return 0 ;
}
static inline void F_90 ( struct V_14 * V_15 ,
unsigned int V_268 ,
unsigned int V_269 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
if ( V_268 ) {
F_29 ( 0 ,
V_30 -> V_34 + V_270 ) ;
F_29 ( 0 , V_30 -> V_34 + V_271 ) ;
F_29 ( 0 ,
V_30 -> V_34 + V_272 ) ;
F_29 ( V_269 ,
V_30 -> V_34 + V_273 ) ;
} else {
F_29 ( 0 ,
V_30 -> V_34 + V_274 ) ;
F_29 ( 0 , V_30 -> V_34 + V_275 ) ;
F_29 ( 0 ,
V_30 -> V_34 + V_276 ) ;
F_29 ( V_269 ,
V_30 -> V_34 + V_277 ) ;
}
}
static int F_91 ( struct V_14 * V_15 , struct V_156 * V_157 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_278 * V_279 = V_157 -> V_279 ;
struct V_46 * V_47 = & V_279 -> V_47 ;
T_3 V_23 ;
unsigned int V_115 ;
unsigned long V_32 ;
int V_96 ;
F_36 ( V_15 ) ;
F_24 ( V_15 , 1 ) ;
V_96 = F_89 ( V_15 , V_47 ) ;
if ( V_96 < 0 )
return V_96 ;
F_31 ( 0 , V_30 -> V_44 + V_107 ) ;
F_87 ( V_15 , V_47 ) ;
F_78 ( V_15 , V_47 ) ;
F_32 ( V_15 , V_47 ) ;
F_25 ( & V_15 -> V_33 , V_32 ) ;
V_30 -> V_76 |= V_77 ;
V_30 -> V_76 &= ~ V_170 ;
if ( V_9 -> V_10 != V_11 ) {
V_30 -> V_76 &= ~ V_280 ;
if ( V_47 -> V_219 == V_235 )
V_30 -> V_76 |= F_7 ( 13 ) ;
else
V_30 -> V_76 |= F_7 ( 8 ) ;
} else {
V_30 -> V_76 &= ~ V_281 ;
if ( V_47 -> V_225 == 4 )
V_30 -> V_76 |= V_282 ;
else if ( V_47 -> V_225 == 2 )
V_30 -> V_76 |= V_283 ;
V_30 -> V_76 &= ~ V_284 ;
V_30 -> V_76 |=
F_5 ( F_59 ( V_47 -> V_227 [ 0 ] ) ) ;
V_30 -> V_76 &= ~ V_285 ;
V_30 -> V_76 |=
F_6 ( F_59 ( V_47 -> V_227
[ V_47 -> V_225 - 1 ] ) ) ;
}
F_31 ( V_30 -> V_76 ,
V_30 -> V_44 + V_78 ) ;
F_27 ( & V_15 -> V_33 , V_32 ) ;
F_31 ( 0 , V_30 -> V_44 + V_187 ) ;
if ( ( V_47 -> V_32 & V_48 ) == 0 ||
V_9 -> V_10 == V_11 ) {
V_30 -> V_286 = 0 ;
for ( V_115 = 0 ; V_115 < F_17 ( V_9 ) ; V_115 ++ )
V_30 -> V_123 [ V_115 ] . V_133 =
F_44 ( F_79 ( V_15 ) *
sizeof( T_1 ) ) ;
F_90 ( V_15 , 1 ,
V_30 -> V_125 |
V_135 |
V_136 |
V_137 ) ;
F_85 ( V_15 , 1 ) ;
}
if ( V_9 -> V_10 == V_11 ) {
V_23 = 0 ;
if ( V_47 -> V_234 == V_235 && F_59 ( V_47 -> V_242 ) )
V_23 |= V_287 ;
if ( V_47 -> V_240 == V_235 && F_59 ( V_47 -> V_245 ) )
V_23 |= V_288 ;
F_31 ( V_23 , V_30 -> V_44 + V_289 ) ;
}
F_25 ( & V_15 -> V_33 , V_32 ) ;
V_23 = V_290 | V_80 | V_81 ;
if ( V_47 -> V_32 & V_48 )
V_23 |= V_79 ;
if ( V_47 -> V_234 == V_235 ) {
V_23 |= V_291 ;
if ( V_47 -> V_242 & V_292 )
V_23 |= V_293 ;
} else if ( V_47 -> V_234 == V_222 ) {
V_23 |= V_294 ;
}
if ( F_77 ( V_47 ) )
V_23 |= V_295 ;
F_31 ( V_23 , V_30 -> V_44 + V_82 ) ;
V_30 -> V_296 = 1 ;
F_27 ( & V_15 -> V_33 , V_32 ) ;
if ( V_47 -> V_234 == V_222 )
F_31 ( 0 , V_30 -> V_44 + V_297 ) ;
return 0 ;
}
static void F_92 ( struct V_14 * V_15 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_156 * V_157 = V_15 -> V_298 ;
unsigned int V_115 ;
T_1 V_6 ;
int V_299 , V_300 , V_301 , V_302 ;
int V_94 ;
do {
V_300 = F_57 ( V_30 -> V_44 + V_303 ) &
0x7fff ;
V_302 = F_57 ( V_30 -> V_44 + V_163 ) &
0x7fff ;
V_6 = F_57 ( V_30 -> V_44 + V_304 ) ;
V_299 = F_13 ( V_6 ) ;
V_301 = F_14 ( V_6 ) ;
if ( V_299 != V_301 )
V_94 =
V_30 -> V_93 - V_300 ;
else
V_94 = V_302 - V_300 ;
if ( V_94 < 0 ) {
F_22 ( V_15 -> V_27 ,
L_11 ) ;
break;
}
V_94 = F_93 ( V_157 , V_94 ) ;
if ( V_94 == 0 )
break;
for ( V_115 = 0 ; V_115 < V_94 ; V_115 ++ ) {
unsigned short V_305 ;
V_305 = F_57 ( V_30 -> V_44 + V_131 ) ;
F_94 ( V_157 , & V_305 , 1 ) ;
}
} while ( V_299 != V_301 );
}
static void F_95 ( struct V_14 * V_15 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_156 * V_157 = V_15 -> V_298 ;
unsigned int V_306 ;
unsigned int V_115 ;
T_3 V_307 ;
int V_308 =
F_57 ( V_30 -> V_44 + V_163 ) & 0x7fff ;
int V_309 =
F_57 ( V_30 -> V_44 + V_303 ) & 0x7fff ;
V_306 = F_93 ( V_157 , 100000 ) ;
for ( V_115 = 0 ; V_309 != V_308 && V_115 < V_306 ; ) {
unsigned short V_305 ;
V_307 = F_34 ( V_15 -> V_189 + V_131 ) ;
V_305 = V_307 & 0xffff ;
F_94 ( V_157 , & V_305 , 1 ) ;
V_115 ++ ;
if ( V_115 < V_306 ) {
V_305 = ( V_307 >> 16 ) & 0xffff ;
F_94 ( V_157 , & V_305 , 1 ) ;
V_115 ++ ;
}
V_309 = F_57 ( V_30 -> V_44 + V_303 ) &
0x7fff ;
}
}
static void F_96 ( struct V_14 * V_15 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
if ( V_9 -> V_10 == V_11 )
F_95 ( V_15 ) ;
else
F_92 ( V_15 ) ;
}
static void F_97 ( struct V_14 * V_15 , unsigned int V_1 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_156 * V_157 = V_15 -> V_298 ;
T_3 V_310 ;
int V_311 ;
int V_94 = 0 ;
void T_4 * V_312 ;
if ( V_1 )
V_312 =
V_30 -> V_34 + V_271 ;
else
V_312 =
V_30 -> V_34 + V_275 ;
for ( V_311 = 0 , V_310 = F_34 ( V_312 ) ;
( V_310 <
V_30 -> V_118 [ V_30 -> V_286 ] ||
V_310 >=
V_30 -> V_118 [ V_30 -> V_286 ] +
V_117 ) && V_311 < F_17 ( V_9 ) ; V_311 ++ ) {
V_94 = F_93 ( V_157 , F_79 ( V_15 ) ) ;
F_94 ( V_157 ,
V_30 -> V_116 [ V_30 -> V_286 ] ,
V_94 ) ;
V_30 -> V_286 = ( V_30 -> V_286 + 1 ) %
F_17 ( V_9 ) ;
}
}
static void F_98 ( struct V_14 * V_15 ,
unsigned short V_161 ,
unsigned int V_313 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_156 * V_157 = V_15 -> V_298 ;
struct V_278 * V_279 = V_157 -> V_279 ;
struct V_46 * V_47 = & V_279 -> V_47 ;
T_2 V_314 ;
unsigned long V_32 ;
if ( V_161 & V_315 ) {
F_22 ( V_15 -> V_27 , L_12 ) ;
V_279 -> V_316 |= V_317 ;
}
F_25 ( & V_15 -> V_33 , V_32 ) ;
V_314 = F_99 ( V_30 -> V_34 + V_255 ) ;
if ( V_313 & V_318 ) {
F_86 ( ( V_314 & V_252 ) | V_254 ,
V_30 -> V_34 + V_255 ) ;
if ( V_314 & V_252 )
F_97 ( V_15 , 1 ) ;
}
F_27 ( & V_15 -> V_33 , V_32 ) ;
if ( ( V_161 & V_319 ) ||
( ( V_47 -> V_32 & V_48 ) &&
( V_161 & V_320 ) &&
( V_9 -> V_10 != V_11 ) ) ) {
F_25 ( & V_15 -> V_33 , V_32 ) ;
if ( V_30 -> V_296 ) {
F_27 ( & V_15 -> V_33 , V_32 ) ;
F_96 ( V_15 ) ;
} else {
F_27 ( & V_15 -> V_33 , V_32 ) ;
}
}
if ( ( V_47 -> V_240 == V_239 &&
V_279 -> V_321 >= V_47 -> V_245 ) ||
( V_47 -> V_240 == V_235 && ( V_161 & V_322 ) ) )
V_279 -> V_316 |= V_323 ;
F_100 ( V_15 , V_157 ) ;
}
static inline unsigned int F_101 ( struct V_14 * V_15 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned int V_324 ;
if ( V_30 -> V_325 == 0 )
V_324 = V_120 - 1 ;
else
V_324 = V_30 -> V_325 - 1 ;
return V_324 ;
}
static int F_102 ( struct V_14 * V_15 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned int V_324 ;
unsigned int V_326 ;
unsigned short V_327 ;
V_324 = F_101 ( V_15 ) ;
V_327 = F_99 ( V_30 -> V_34 + V_256 ) ;
if ( ( V_327 & V_328 ) == 0 )
return 0 ;
V_326 =
F_34 ( V_30 -> V_34 + V_275 ) ;
if ( V_326 != V_30 -> V_122 [ V_324 ] )
return 0 ;
return 1 ;
}
static inline int F_103 ( struct V_14 * V_15 ,
unsigned short V_327 )
{
if ( ( V_327 & V_328 ) == 0 ||
( V_327 & V_252 ) == 0 )
return 0 ;
if ( F_102 ( V_15 ) )
return 0 ;
return 1 ;
}
static void F_104 ( struct V_14 * V_15 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned int V_329 ;
V_329 =
F_34 ( V_30 -> V_34 + V_277 ) ;
V_329 &= ~ V_330 ;
F_90 ( V_15 , 0 , V_329 ) ;
F_85 ( V_15 , 0 ) ;
}
static unsigned int F_105 ( struct V_14 * V_15 ,
struct V_156 * V_157 ,
unsigned short * V_331 ,
unsigned int V_332 )
{
unsigned int V_306 = F_106 ( V_157 , V_332 ) ;
unsigned int V_333 ;
V_306 = F_93 ( V_157 , V_306 ) ;
V_333 = F_107 ( V_157 , V_331 , V_306 ) ;
return F_106 ( V_157 , V_333 ) ;
}
static unsigned int F_108 ( struct V_14 * V_15 ,
const struct V_46 * V_47 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_156 * V_157 = V_15 -> V_261 ;
unsigned int V_324 = V_30 -> V_325 ;
unsigned int V_334 = F_101 ( V_15 ) ;
unsigned int V_306 ;
unsigned int V_335 ;
unsigned int V_336 ;
V_306 = F_105 ( V_15 , V_157 ,
V_30 -> V_121 [ V_324 ] ,
V_117 ) ;
if ( V_306 == 0 )
return 0 ;
V_335 = F_109 ( V_157 , V_306 ) ;
V_30 -> V_126 [ V_324 ] . V_133 = F_44 ( V_335 ) ;
V_336 = F_110 ( V_30 -> V_126 [ V_324 ] . V_134 ) ;
V_336 |= V_330 ;
V_30 -> V_126 [ V_324 ] . V_134 = F_44 ( V_336 ) ;
V_336 = F_110 ( V_30 -> V_126 [ V_334 ] . V_134 ) ;
V_336 &= ~ V_330 ;
V_30 -> V_126 [ V_334 ] . V_134 = F_44 ( V_336 ) ;
V_30 -> V_325 = ( V_324 + 1 ) % V_120 ;
return V_335 ;
}
static void F_111 ( struct V_14 * V_15 , const struct V_46 * V_47 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned int V_337 ;
unsigned int V_310 ;
void T_4 * V_312 =
V_30 -> V_34 + V_275 ;
unsigned int V_324 ;
do {
V_324 = V_30 -> V_325 ;
V_310 = F_34 ( V_312 ) ;
if ( V_310 >=
V_30 -> V_122 [ V_324 ] &&
V_310 <
V_30 -> V_122 [ V_324 ] +
V_117 )
return;
V_337 = F_108 ( V_15 , V_47 ) ;
} while ( V_337 >= V_117 );
}
static void F_112 ( struct V_14 * V_15 ,
unsigned short V_161 , unsigned int V_313 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_156 * V_157 = V_15 -> V_261 ;
struct V_278 * V_279 ;
struct V_46 * V_47 ;
T_2 V_338 ;
unsigned long V_32 ;
if ( ! V_157 )
return;
V_279 = V_157 -> V_279 ;
V_47 = & V_279 -> V_47 ;
F_25 ( & V_15 -> V_33 , V_32 ) ;
V_338 = F_99 ( V_30 -> V_34 + V_256 ) ;
if ( V_313 & V_339 ) {
if ( ( V_338 & V_252 ) &&
! ( V_338 & V_328 ) )
F_86 ( V_252 | V_254 ,
V_30 -> V_34 + V_256 ) ;
else
F_86 ( V_254 ,
V_30 -> V_34 + V_256 ) ;
F_27 ( & V_15 -> V_33 , V_32 ) ;
if ( V_338 & V_252 ) {
F_111 ( V_15 , V_47 ) ;
if ( F_103 ( V_15 , V_338 ) )
F_104 ( V_15 ) ;
}
} else {
F_27 ( & V_15 -> V_33 , V_32 ) ;
}
if ( ( V_161 & V_340 ) ) {
if ( ( V_47 -> V_240 == V_239 &&
V_279 -> V_321 >= V_47 -> V_245 ) ||
F_102 ( V_15 ) )
V_279 -> V_316 |= V_323 ;
else
V_279 -> V_316 |= V_317 ;
}
F_100 ( V_15 , V_157 ) ;
}
static T_5 F_113 ( int V_341 , void * V_342 )
{
struct V_14 * V_15 = V_342 ;
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned short V_161 ;
T_3 V_313 ;
T_3 V_343 ;
V_313 = F_34 ( V_30 -> V_34 + V_36 ) ;
V_161 = F_57 ( V_30 -> V_44 + V_162 ) ;
if ( ! V_15 -> V_344 )
return V_345 ;
F_98 ( V_15 , V_161 , V_313 ) ;
F_112 ( V_15 , V_161 , V_313 ) ;
if ( V_313 & V_346 ) {
V_343 = F_34 ( V_30 -> V_34 + V_347 ) ;
F_29 ( V_343 , V_30 -> V_34 + V_347 ) ;
}
return V_345 ;
}
static int F_114 ( struct V_14 * V_15 , struct V_156 * V_157 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned long V_32 ;
F_25 ( & V_15 -> V_33 , V_32 ) ;
if ( V_30 -> V_296 == 0 ) {
F_27 ( & V_15 -> V_33 , V_32 ) ;
return 0 ;
}
V_30 -> V_296 = 0 ;
F_27 ( & V_15 -> V_33 , V_32 ) ;
F_36 ( V_15 ) ;
F_24 ( V_15 , 1 ) ;
return 0 ;
}
static int F_115 ( struct V_14 * V_15 , struct V_156 * V_157 ,
struct V_158 * V_159 , unsigned int * V_151 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
struct V_29 * V_30 = V_15 -> V_31 ;
int V_229 = F_59 ( V_159 -> V_168 ) ;
int V_24 = F_60 ( V_159 -> V_168 ) ;
F_31 ( 0 , V_30 -> V_44 + V_348 ) ;
F_21 ( V_15 , & V_30 -> V_109 , V_229 , V_24 ) ;
F_31 ( V_30 -> V_109 ,
V_30 -> V_44 + V_349 ) ;
if ( V_9 -> V_10 == V_11 ) {
F_31 ( V_151 [ 0 ] & 0xff ,
V_30 -> V_44 + F_2 ( V_229 ) ) ;
F_31 ( ( V_151 [ 0 ] >> 8 ) & 0xf ,
V_30 -> V_44 + F_3 ( V_229 ) ) ;
} else {
F_31 ( V_151 [ 0 ] , V_30 -> V_44 + F_1 ( V_229 ) ) ;
}
V_157 -> V_350 [ V_229 ] = V_151 [ 0 ] ;
return 1 ;
}
static void F_116 ( struct V_14 * V_15 ,
const struct V_46 * V_47 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned int V_23 = V_351 | V_352 |
V_353 | V_354 ;
if ( V_47 -> V_234 == V_235 ) {
V_23 |= V_355 ;
if ( V_47 -> V_242 & V_292 )
V_23 |= V_356 ;
} else {
V_23 |= V_357 ;
}
if ( V_47 -> V_223 == V_235 ) {
V_23 |= V_358 ;
if ( V_47 -> V_224 & V_292 )
V_23 |= V_359 ;
}
F_31 ( V_23 , V_30 -> V_44 + V_348 ) ;
}
static void F_117 ( struct V_14 * V_15 ,
const struct V_46 * V_47 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
int V_115 ;
for ( V_115 = 0 ; V_115 < V_47 -> V_225 ; V_115 ++ ) {
int V_1 , V_24 ;
V_1 = F_59 ( V_47 -> V_227 [ V_115 ] ) ;
V_24 = F_60 ( V_47 -> V_227 [ V_115 ] ) ;
F_21 ( V_15 , & V_30 -> V_109 , V_1 ,
V_24 ) ;
}
V_30 -> V_109 |= V_360 ;
F_31 ( V_30 -> V_109 ,
V_30 -> V_44 + V_349 ) ;
}
static void F_118 ( struct V_14 * V_15 ,
const struct V_46 * V_47 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
T_1 V_23 ;
unsigned int V_361 , V_362 ;
V_361 = F_59 ( V_47 -> V_227 [ 0 ] ) ;
V_362 = F_59 ( V_47 -> V_227 [ V_47 -> V_225 - 1 ] ) ;
if ( V_362 < V_361 )
F_22 ( V_15 -> V_27 ,
L_13 ) ;
V_23 = ( V_361 & 0x7 ) | ( V_362 & 0x7 ) << 3 ;
F_31 ( V_23 , V_30 -> V_44 + V_363 ) ;
}
static unsigned int F_119 ( unsigned int V_205 , unsigned int V_32 )
{
return F_69 ( V_205 , V_32 ) - 2 ;
}
static void F_120 ( struct V_14 * V_15 ,
const struct V_46 * V_47 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned int V_197 ;
if ( V_47 -> V_223 != V_220 )
return;
V_197 = F_119 ( V_47 -> V_224 , V_47 -> V_32 ) ;
if ( V_197 > V_215 ) {
F_22 ( V_15 -> V_27 , L_14 ) ;
V_197 = V_215 ;
}
F_31 ( V_197 & 0xffff ,
V_30 -> V_44 + V_364 ) ;
F_31 ( ( V_197 >> 16 ) & 0xff ,
V_30 -> V_44 + V_365 ) ;
}
static int F_121 ( struct V_14 * V_15 , const struct V_46 * V_47 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_156 * V_157 = V_15 -> V_261 ;
unsigned int V_306 ;
unsigned int V_335 ;
int V_115 ;
F_31 ( 0 , V_30 -> V_44 + V_264 ) ;
F_31 ( 0 , V_30 -> V_44 + V_263 ) ;
V_306 = F_105 ( V_15 , V_157 ,
V_30 -> V_366 ,
V_367 ) ;
if ( V_306 == 0 )
return - 1 ;
for ( V_115 = 0 ; V_115 < V_306 ; V_115 ++ ) {
F_31 ( V_30 -> V_366 [ V_115 ] ,
V_30 -> V_44 + V_138 ) ;
}
if ( V_47 -> V_240 == V_239 &&
V_157 -> V_279 -> V_321 >= V_47 -> V_245 )
return 0 ;
V_335 = F_108 ( V_15 , V_47 ) ;
if ( V_335 == 0 )
return - 1 ;
F_111 ( V_15 , V_47 ) ;
F_85 ( V_15 , 0 ) ;
return 0 ;
}
static inline int F_122 ( struct V_14 * V_15 ,
struct V_156 * V_157 ,
struct V_46 * V_47 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
if ( V_157 -> V_262 )
return 0 ;
if ( V_9 -> V_10 == V_11 )
return 0 ;
else if ( F_88 ( V_47 ) )
return 0 ;
return 1 ;
}
static int F_123 ( struct V_14 * V_15 , struct V_156 * V_157 ,
unsigned int V_368 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_46 * V_47 = & V_157 -> V_279 -> V_47 ;
int V_96 ;
if ( V_368 != V_47 -> V_242 )
return - V_192 ;
V_96 = F_121 ( V_15 , V_47 ) ;
if ( V_96 < 0 )
return - V_369 ;
F_116 ( V_15 , V_47 ) ;
if ( V_47 -> V_234 == V_370 )
F_31 ( 0 , V_30 -> V_44 + V_371 ) ;
V_157 -> V_279 -> V_372 = NULL ;
return 0 ;
}
static int F_124 ( struct V_14 * V_15 , struct V_156 * V_157 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_46 * V_47 = & V_157 -> V_279 -> V_47 ;
if ( F_122 ( V_15 , V_157 , V_47 ) ) {
F_47 ( V_15 ) ;
return - V_164 ;
}
F_31 ( 0x0 , V_30 -> V_44 + V_348 ) ;
V_30 -> V_325 = 0 ;
F_118 ( V_15 , V_47 ) ;
F_120 ( V_15 , V_47 ) ;
F_90 ( V_15 , 0 , V_30 -> V_127 |
V_135 | V_136 ) ;
F_117 ( V_15 , V_47 ) ;
V_157 -> V_279 -> V_372 = F_123 ;
return 0 ;
}
static int F_125 ( struct V_14 * V_15 ,
struct V_156 * V_157 ,
struct V_46 * V_47 )
{
unsigned int V_228 = F_59 ( V_47 -> V_227 [ 0 ] ) ;
int V_115 ;
for ( V_115 = 1 ; V_115 < V_47 -> V_225 ; V_115 ++ ) {
unsigned int V_229 = F_59 ( V_47 -> V_227 [ V_115 ] ) ;
if ( V_229 != ( V_228 + V_115 ) ) {
F_64 ( V_15 -> V_27 ,
L_8 ) ;
return - V_192 ;
}
}
return 0 ;
}
static int F_126 ( struct V_14 * V_15 , struct V_156 * V_157 ,
struct V_46 * V_47 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
int V_230 = 0 ;
unsigned int V_231 ;
V_230 |= F_73 ( & V_47 -> V_234 , V_370 | V_235 ) ;
V_230 |= F_73 ( & V_47 -> V_223 ,
V_220 | V_235 ) ;
V_230 |= F_73 ( & V_47 -> V_219 , V_222 ) ;
V_230 |= F_73 ( & V_47 -> V_238 , V_239 ) ;
V_230 |= F_73 ( & V_47 -> V_240 , V_241 ) ;
if ( V_230 )
return 1 ;
V_230 |= F_74 ( V_47 -> V_234 ) ;
V_230 |= F_74 ( V_47 -> V_223 ) ;
if ( V_47 -> V_219 == V_235 && V_47 -> V_223 == V_220 )
V_230 |= - V_192 ;
if ( V_47 -> V_240 != V_239 &&
V_47 -> V_240 != V_241 && V_47 -> V_240 != V_235 )
V_230 |= - V_192 ;
if ( V_230 )
return 2 ;
V_230 |= F_75 ( & V_47 -> V_242 , 0 ) ;
if ( V_47 -> V_223 == V_220 ) {
V_230 |= F_76 ( & V_47 -> V_224 ,
V_9 -> V_373 ) ;
if ( F_119 ( V_47 -> V_224 , V_47 -> V_32 ) >
V_215 ) {
V_47 -> V_224 = ( V_215 + 2 ) *
V_208 ;
V_230 |= - V_192 ;
}
}
V_230 |= F_76 ( & V_47 -> V_225 , 1 ) ;
V_230 |= F_75 ( & V_47 -> V_244 ,
V_47 -> V_225 ) ;
if ( V_230 )
return 3 ;
if ( V_47 -> V_223 == V_220 ) {
V_231 = V_47 -> V_224 ;
V_47 -> V_224 = F_69 ( V_47 -> V_224 ,
V_47 -> V_32 ) * V_208 ;
if ( V_231 != V_47 -> V_224 )
V_230 ++ ;
}
if ( V_230 )
return 4 ;
if ( V_47 -> V_227 && V_47 -> V_225 > 0 )
V_230 |= F_125 ( V_15 , V_157 , V_47 ) ;
if ( V_230 )
return 5 ;
return 0 ;
}
static int F_127 ( struct V_14 * V_15 , struct V_156 * V_157 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
F_31 ( 0x0 , V_30 -> V_44 + V_348 ) ;
F_24 ( V_15 , 0 ) ;
return 0 ;
}
static int F_128 ( struct V_14 * V_15 ,
int V_374 , int V_375 , int V_151 , unsigned long V_376 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
if ( V_374 ) {
F_31 ( V_151 , V_30 -> V_44 + V_376 + 2 * V_375 ) ;
return 0 ;
}
return F_57 ( V_30 -> V_44 + V_376 + 2 * V_375 ) ;
}
static int F_129 ( struct V_14 * V_15 , struct V_156 * V_157 ,
struct V_158 * V_159 , unsigned int * V_151 )
{
unsigned int V_23 ;
V_23 = F_99 ( V_15 -> V_189 + V_377 ) ;
V_23 &= 0xf ;
V_151 [ 1 ] = V_23 ;
V_151 [ 0 ] = 0 ;
return V_159 -> V_165 ;
}
static int F_130 ( struct V_14 * V_15 ,
struct V_156 * V_157 ,
struct V_158 * V_159 ,
unsigned int * V_151 )
{
if ( F_131 ( V_157 , V_151 ) )
F_86 ( V_157 -> V_139 , V_15 -> V_189 + V_378 ) ;
V_151 [ 1 ] = V_157 -> V_139 ;
return V_159 -> V_165 ;
}
static int F_132 ( struct V_14 * V_15 ,
struct V_156 * V_157 ,
struct V_158 * V_159 ,
unsigned int * V_151 )
{
int V_167 ;
V_167 = F_133 ( V_15 , V_157 , V_159 , V_151 , 0 ) ;
if ( V_167 )
return V_167 ;
F_86 ( V_157 -> V_379 , V_15 -> V_189 + V_380 ) ;
return V_159 -> V_165 ;
}
static int F_134 ( struct V_14 * V_15 ,
struct V_156 * V_157 ,
struct V_158 * V_159 ,
unsigned int * V_151 )
{
if ( F_131 ( V_157 , V_151 ) )
F_86 ( V_157 -> V_139 , V_15 -> V_189 + V_381 ) ;
V_151 [ 1 ] = F_99 ( V_15 -> V_189 + V_381 ) ;
return V_159 -> V_165 ;
}
static int F_135 ( struct V_14 * V_15 , unsigned int V_150 ,
T_2 V_382 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
static const int V_383 = 8 ;
static const int V_384 = 11 ;
unsigned int V_153 = ( ( V_150 & 0x7 ) << 8 ) | V_382 ;
unsigned int V_148 , V_385 ;
static const int V_386 = 1 ;
if ( V_150 >= V_383 ) {
F_22 ( V_15 -> V_27 , L_15 ) ;
return - 1 ;
}
for ( V_148 = 1 << ( V_384 - 1 ) ; V_148 ; V_148 >>= 1 ) {
V_385 = 0 ;
if ( V_153 & V_148 )
V_385 |= V_387 ;
F_49 ( V_386 ) ;
F_31 ( V_385 , V_30 -> V_44 + V_107 ) ;
V_385 |= V_388 ;
F_49 ( V_386 ) ;
F_31 ( V_385 , V_30 -> V_44 + V_107 ) ;
}
F_49 ( V_386 ) ;
F_31 ( V_389 , V_30 -> V_44 + V_107 ) ;
F_49 ( V_386 ) ;
F_31 ( 0 , V_30 -> V_44 + V_107 ) ;
F_49 ( V_386 ) ;
return 0 ;
}
static int F_136 ( struct V_14 * V_15 ,
unsigned int V_390 , unsigned int V_382 )
{
T_2 V_391 [ 3 ] ;
T_2 V_392 ;
enum T_6 {
V_393 = 0x1 ,
V_394 = 0x2 ,
V_395 = 0x4 ,
V_396 = 0x8 ,
};
enum T_7 {
V_397 = 0x20 ,
};
switch ( V_390 ) {
case 0 :
V_392 = V_398 ;
V_391 [ 0 ] = V_393 ;
break;
case 1 :
V_392 = V_398 ;
V_391 [ 0 ] = V_395 ;
break;
case 2 :
V_392 = V_399 ;
V_391 [ 0 ] = V_393 ;
break;
case 3 :
V_392 = V_399 ;
V_391 [ 0 ] = V_395 ;
break;
case 4 :
V_392 = V_398 ;
V_391 [ 0 ] = V_394 ;
break;
case 5 :
V_392 = V_398 ;
V_391 [ 0 ] = V_396 ;
break;
case 6 :
V_392 = V_399 ;
V_391 [ 0 ] = V_394 ;
break;
case 7 :
V_392 = V_399 ;
V_391 [ 0 ] = V_396 ;
break;
default:
F_22 ( V_15 -> V_27 , L_16 ) ;
return - 1 ;
}
V_391 [ 1 ] = V_397 | ( ( V_382 >> 8 ) & 0xf ) ;
V_391 [ 2 ] = V_382 & 0xff ;
F_55 ( V_15 , V_392 , V_391 , 3 ) ;
return 0 ;
}
static void F_137 ( struct V_14 * V_15 , unsigned int V_1 ,
unsigned int V_382 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
switch ( V_9 -> V_10 ) {
case V_19 :
case V_18 :
F_135 ( V_15 , V_1 , V_382 ) ;
break;
case V_11 :
F_136 ( V_15 , V_1 , V_382 ) ;
break;
default:
break;
}
}
static int F_138 ( struct V_14 * V_15 ,
struct V_156 * V_157 ,
struct V_158 * V_159 ,
unsigned int * V_151 )
{
unsigned int V_229 = F_59 ( V_159 -> V_168 ) ;
if ( V_159 -> V_165 ) {
unsigned int V_305 = V_151 [ V_159 -> V_165 - 1 ] ;
if ( V_157 -> V_350 [ V_229 ] != V_305 ) {
F_137 ( V_15 , V_229 , V_305 ) ;
V_157 -> V_350 [ V_229 ] = V_305 ;
}
}
return V_159 -> V_165 ;
}
static void F_139 ( struct V_14 * V_15 , unsigned int V_1 ,
unsigned int V_382 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
static const int V_384 = 10 ;
unsigned int V_148 , V_385 ;
unsigned int V_153 = ( ( V_1 & 0x3 ) << 8 ) | ( V_382 & 0xff ) ;
static const int V_400 = 1 ;
V_385 = V_401 ;
F_49 ( V_400 ) ;
F_31 ( V_385 , V_30 -> V_44 + V_107 ) ;
for ( V_148 = 1 << ( V_384 - 1 ) ; V_148 ; V_148 >>= 1 ) {
if ( V_153 & V_148 )
V_385 |= V_387 ;
else
V_385 &= ~ V_387 ;
F_49 ( V_400 ) ;
F_31 ( V_385 , V_30 -> V_44 + V_107 ) ;
F_49 ( V_400 ) ;
F_31 ( V_385 | V_388 ,
V_30 -> V_44 + V_107 ) ;
}
F_49 ( V_400 ) ;
F_31 ( 0 , V_30 -> V_44 + V_107 ) ;
}
static int F_140 ( struct V_14 * V_15 ,
struct V_156 * V_157 ,
struct V_158 * V_159 ,
unsigned int * V_151 )
{
unsigned int V_229 = F_59 ( V_159 -> V_168 ) ;
if ( V_159 -> V_165 ) {
unsigned int V_305 = V_151 [ V_159 -> V_165 - 1 ] ;
if ( V_157 -> V_350 [ V_229 ] != V_305 ) {
F_139 ( V_15 , V_229 , V_305 ) ;
V_157 -> V_350 [ V_229 ] = V_305 ;
}
}
return V_159 -> V_165 ;
}
static T_1 F_141 ( struct V_14 * V_15 , T_2 V_150 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
static const int V_384 = 11 ;
static const int V_402 = 0x6 ;
unsigned int V_153 = ( V_402 << 8 ) | V_150 ;
unsigned int V_148 ;
void T_4 * const V_142 =
V_30 -> V_34 + V_52 ;
T_1 V_382 ;
static const int V_403 = 16 ;
static const int V_404 = 1 ;
F_49 ( V_404 ) ;
V_30 -> V_51 &= ~ V_405 & ~ V_155 ;
V_30 -> V_51 |= V_146 ;
F_29 ( V_30 -> V_51 , V_142 ) ;
F_49 ( V_404 ) ;
V_30 -> V_51 |= V_155 ;
F_29 ( V_30 -> V_51 , V_142 ) ;
for ( V_148 = 1 << ( V_384 - 1 ) ; V_148 ; V_148 >>= 1 ) {
F_49 ( V_404 ) ;
if ( V_153 & V_148 )
V_30 -> V_51 |= V_141 ;
else
V_30 -> V_51 &= ~ V_141 ;
F_29 ( V_30 -> V_51 , V_142 ) ;
F_49 ( V_404 ) ;
V_30 -> V_51 |= V_405 ;
F_29 ( V_30 -> V_51 , V_142 ) ;
F_49 ( V_404 ) ;
V_30 -> V_51 &= ~ V_405 ;
F_29 ( V_30 -> V_51 , V_142 ) ;
}
V_382 = 0 ;
for ( V_148 = 1 << ( V_403 - 1 ) ; V_148 ; V_148 >>= 1 ) {
F_49 ( V_404 ) ;
V_30 -> V_51 |= V_405 ;
F_29 ( V_30 -> V_51 , V_142 ) ;
F_49 ( V_404 ) ;
V_30 -> V_51 &= ~ V_405 ;
F_29 ( V_30 -> V_51 , V_142 ) ;
F_49 ( V_404 ) ;
if ( F_34 ( V_142 ) & V_406 )
V_382 |= V_148 ;
}
F_49 ( V_404 ) ;
V_30 -> V_51 &= ~ V_155 ;
F_29 ( V_30 -> V_51 , V_142 ) ;
return V_382 ;
}
static int F_142 ( struct V_14 * V_15 ,
struct V_156 * V_157 ,
struct V_158 * V_159 , unsigned int * V_151 )
{
V_151 [ 0 ] = F_141 ( V_15 , F_59 ( V_159 -> V_168 ) ) ;
return 1 ;
}
static int F_143 ( struct V_14 * V_15 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_156 * V_157 ;
int V_115 ;
int V_167 ;
V_167 = F_144 ( V_15 , 10 ) ;
if ( V_167 )
return V_167 ;
V_157 = & V_15 -> V_407 [ 0 ] ;
V_15 -> V_298 = V_157 ;
V_157 -> type = V_408 ;
V_157 -> V_409 = V_410 | V_411 | V_412 | V_413 ;
if ( V_9 -> V_10 == V_19 )
V_157 -> V_409 |= V_414 | V_415 ;
else if ( V_9 -> V_10 == V_18 )
V_157 -> V_409 |= V_415 ;
V_157 -> V_416 = V_9 -> V_417 ;
V_157 -> V_418 = 0x2000 ;
V_157 -> V_419 = ( 1 << V_9 -> V_420 ) - 1 ;
V_157 -> V_421 = V_9 -> V_422 ;
V_157 -> V_423 = F_58 ;
V_157 -> V_424 = F_68 ;
V_157 -> V_425 = F_91 ;
V_157 -> V_426 = F_72 ;
V_157 -> V_427 = F_114 ;
if ( V_9 -> V_10 == V_11 ) {
T_2 V_151 ;
V_30 -> V_183 = F_15 ( 4 ) ;
for ( V_115 = 0 ; V_115 < V_157 -> V_416 ; V_115 ++ )
V_30 -> V_183 |= F_16 ( V_115 ) ;
V_151 = V_30 -> V_183 ;
F_55 ( V_15 , V_185 , & V_151 , sizeof( V_151 ) ) ;
}
V_157 = & V_15 -> V_407 [ 1 ] ;
if ( V_9 -> V_28 ) {
V_157 -> type = V_428 ;
V_157 -> V_409 = V_410 | V_429 |
V_411 | V_430 ;
V_157 -> V_416 = V_9 -> V_28 ;
V_157 -> V_419 = ( 1 << V_9 -> V_431 ) - 1 ;
V_157 -> V_421 = V_9 -> V_432 ;
V_157 -> V_433 = F_115 ;
V_167 = F_145 ( V_157 ) ;
if ( V_167 )
return V_167 ;
if ( F_23 ( V_9 ) ) {
V_15 -> V_261 = V_157 ;
V_157 -> V_426 = F_126 ;
V_157 -> V_425 = F_124 ;
V_157 -> V_418 = V_9 -> V_28 ;
V_157 -> V_427 = F_127 ;
}
} else {
V_157 -> type = V_434 ;
}
V_157 = & V_15 -> V_407 [ 2 ] ;
if ( V_9 -> V_10 == V_18 ) {
V_157 -> type = V_435 ;
V_157 -> V_409 = V_410 ;
V_157 -> V_416 = 4 ;
V_157 -> V_419 = 1 ;
V_157 -> V_421 = & V_436 ;
V_157 -> V_437 = F_129 ;
} else {
V_157 -> type = V_434 ;
}
if ( V_9 -> V_10 == V_18 ) {
V_157 = & V_15 -> V_407 [ 3 ] ;
V_157 -> type = V_438 ;
V_157 -> V_409 = V_429 ;
V_157 -> V_416 = 4 ;
V_157 -> V_419 = 1 ;
V_157 -> V_421 = & V_436 ;
V_157 -> V_437 = F_130 ;
} else {
V_157 -> type = V_434 ;
}
V_157 = & V_15 -> V_407 [ 4 ] ;
if ( V_9 -> V_439 ) {
if ( V_9 -> V_10 == V_11 ) {
V_167 = F_146 ( V_15 , V_157 , F_128 ,
V_440 ) ;
} else {
V_167 = F_147 ( V_15 , V_157 , NULL ,
V_441 ) ;
}
if ( V_167 )
return V_167 ;
} else {
V_157 -> type = V_434 ;
}
V_157 = & V_15 -> V_407 [ 5 ] ;
if ( V_9 -> V_10 == V_19 ) {
V_157 -> type = V_442 ;
V_157 -> V_409 = V_429 | V_410 ;
V_157 -> V_416 = 8 ;
V_157 -> V_419 = 1 ;
V_157 -> V_421 = & V_436 ;
V_157 -> V_424 = F_132 ;
V_157 -> V_437 = F_134 ;
} else {
V_157 -> type = V_434 ;
}
V_157 = & V_15 -> V_407 [ 6 ] ;
V_157 -> type = V_443 ;
V_157 -> V_409 = V_410 | V_429 | V_444 ;
V_157 -> V_416 = 8 ;
if ( V_9 -> V_10 == V_11 )
V_157 -> V_419 = 0xfff ;
else
V_157 -> V_419 = 0xff ;
V_157 -> V_433 = F_138 ;
V_167 = F_145 ( V_157 ) ;
if ( V_167 )
return V_167 ;
for ( V_115 = 0 ; V_115 < V_157 -> V_416 ; V_115 ++ ) {
F_137 ( V_15 , V_115 , V_157 -> V_419 / 2 ) ;
V_157 -> V_350 [ V_115 ] = V_157 -> V_419 / 2 ;
}
V_157 = & V_15 -> V_407 [ 7 ] ;
if ( V_9 -> V_10 == V_18 ) {
V_157 -> type = V_443 ;
V_157 -> V_409 = V_410 | V_429 | V_444 ;
V_157 -> V_416 = 2 ;
V_157 -> V_419 = 0xff ;
V_157 -> V_433 = F_140 ;
V_167 = F_145 ( V_157 ) ;
if ( V_167 )
return V_167 ;
for ( V_115 = 0 ; V_115 < V_157 -> V_416 ; V_115 ++ ) {
F_139 ( V_15 , V_115 , V_157 -> V_419 / 2 ) ;
V_157 -> V_350 [ V_115 ] = V_157 -> V_419 / 2 ;
}
} else {
V_157 -> type = V_434 ;
}
V_157 = & V_15 -> V_407 [ 8 ] ;
if ( F_34 ( V_30 -> V_34 + V_52 ) & V_445 ) {
V_157 -> type = V_446 ;
V_157 -> V_409 = V_410 | V_444 ;
V_157 -> V_416 = 128 ;
V_157 -> V_419 = 0xffff ;
V_157 -> V_423 = F_142 ;
} else {
V_157 -> type = V_434 ;
}
V_157 = & V_15 -> V_407 [ 9 ] ;
V_157 -> type = V_434 ;
return 0 ;
}
static int F_148 ( struct V_14 * V_15 ,
unsigned long V_160 )
{
struct V_113 * V_114 = F_42 ( V_15 ) ;
const struct V_8 * V_9 = NULL ;
struct V_29 * V_30 ;
T_3 V_447 , V_448 ;
int V_96 ;
if ( V_160 < F_149 ( V_449 ) )
V_9 = & V_449 [ V_160 ] ;
if ( ! V_9 )
return - V_450 ;
V_15 -> V_17 = V_9 ;
V_30 = F_150 ( V_15 , sizeof( * V_30 ) ) ;
if ( ! V_30 )
return - V_119 ;
V_96 = F_151 ( V_15 ) ;
if ( V_96 )
return V_96 ;
F_152 ( V_114 ) ;
V_15 -> V_451 = V_9 -> V_452 ;
V_30 -> V_453 = F_153 ( V_114 , 2 ) ;
V_30 -> V_454 = F_153 ( V_114 , 3 ) ;
V_30 -> V_34 = F_154 ( V_114 , 0 ) ;
V_30 -> V_44 = F_154 ( V_114 , 2 ) ;
V_15 -> V_189 = F_154 ( V_114 , 3 ) ;
if ( ! V_30 -> V_34 || ! V_30 -> V_44 || ! V_15 -> V_189 ) {
F_155 ( V_15 -> V_27 , L_17 ) ;
return - V_119 ;
}
V_447 = F_34 ( V_30 -> V_34 + V_455 ) &
V_456 ;
V_448 = F_34 ( V_30 -> V_34 + V_457 ) &
V_447 & V_458 ;
V_30 -> V_132 = ( ( T_3 ) V_30 -> V_453 &
~ V_447 ) | V_448 ;
V_447 = F_34 ( V_30 -> V_34 + V_459 ) &
V_456 ;
V_448 = F_34 ( V_30 -> V_34 + V_460 ) &
V_447 & V_458 ;
V_30 -> V_130 = ( ( T_3 ) V_30 -> V_454 &
~ V_447 ) | V_448 ;
V_96 = F_41 ( V_15 ) ;
if ( V_96 < 0 )
return V_96 ;
V_30 -> F_20 =
F_20 ( V_15 , F_57 ( V_30 -> V_44 + V_162 ) ) ;
F_64 ( V_15 -> V_27 , L_18 ,
V_30 -> F_20 ) ;
F_33 ( V_15 ) ;
F_40 ( V_15 ) ;
V_96 = F_156 ( V_114 -> V_341 , F_113 , V_461 ,
V_15 -> V_451 , V_15 ) ;
if ( V_96 ) {
F_64 ( V_15 -> V_27 , L_19 ,
V_114 -> V_341 ) ;
return V_96 ;
}
V_15 -> V_341 = V_114 -> V_341 ;
F_64 ( V_15 -> V_27 , L_20 , V_15 -> V_341 ) ;
V_96 = F_143 ( V_15 ) ;
if ( V_96 < 0 )
return V_96 ;
return 0 ;
}
static void F_157 ( struct V_14 * V_15 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
if ( V_15 -> V_341 )
F_158 ( V_15 -> V_341 , V_15 ) ;
if ( V_30 ) {
if ( V_30 -> V_34 ) {
F_28 ( V_15 ) ;
F_159 ( V_30 -> V_34 ) ;
}
if ( V_30 -> V_44 )
F_159 ( V_30 -> V_44 ) ;
if ( V_15 -> V_189 )
F_159 ( V_15 -> V_189 ) ;
}
F_160 ( V_15 ) ;
F_45 ( V_15 ) ;
}
static int F_161 ( struct V_113 * V_15 ,
const struct V_462 * V_201 )
{
return F_162 ( V_15 , & V_463 ,
V_201 -> V_464 ) ;
}
