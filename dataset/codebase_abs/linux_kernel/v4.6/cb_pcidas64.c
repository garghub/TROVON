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
V_88 = F_38 ( V_83 , V_84 ) ;
V_23 = ( ~ ( V_88 - 1 ) ) & V_86 -> V_90 ;
V_30 -> V_91 &= ~ V_86 -> V_90 ;
V_30 -> V_91 |= V_23 ;
F_31 ( V_30 -> V_91 ,
V_30 -> V_44 + V_92 ) ;
V_30 -> V_93 = V_88 * V_84 ;
return V_30 -> V_93 ;
}
static int F_39 ( struct V_14 * V_15 , unsigned int V_94 )
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
static unsigned int F_40 ( struct V_14 * V_15 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
struct V_29 * V_30 = V_15 -> V_31 ;
return V_30 -> V_93 *
V_9 -> V_87 -> V_98 *
V_9 -> V_87 -> V_97 ;
}
static void F_41 ( struct V_14 * V_15 )
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
static int F_42 ( struct V_14 * V_15 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
struct V_113 * V_114 = F_43 ( V_15 ) ;
struct V_29 * V_30 = V_15 -> V_31 ;
int V_115 ;
for ( V_115 = 0 ; V_115 < F_17 ( V_9 ) ; V_115 ++ ) {
V_30 -> V_116 [ V_115 ] =
F_44 ( & V_114 -> V_15 , V_117 ,
& V_30 -> V_118 [ V_115 ] ,
V_119 ) ;
if ( ! V_30 -> V_116 [ V_115 ] )
return - V_120 ;
}
for ( V_115 = 0 ; V_115 < V_121 ; V_115 ++ ) {
if ( F_23 ( V_9 ) ) {
V_30 -> V_122 [ V_115 ] =
F_44 ( & V_114 -> V_15 ,
V_117 ,
& V_30 ->
V_123 [ V_115 ] ,
V_119 ) ;
if ( ! V_30 -> V_122 [ V_115 ] )
return - V_120 ;
}
}
V_30 -> V_124 =
F_44 ( & V_114 -> V_15 , sizeof( struct V_125 ) *
F_17 ( V_9 ) ,
& V_30 -> V_126 , V_119 ) ;
if ( ! V_30 -> V_124 )
return - V_120 ;
if ( F_23 ( V_9 ) ) {
V_30 -> V_127 =
F_44 ( & V_114 -> V_15 ,
sizeof( struct V_125 ) *
V_121 ,
& V_30 -> V_128 ,
V_119 ) ;
if ( ! V_30 -> V_127 )
return - V_120 ;
}
for ( V_115 = 0 ; V_115 < F_17 ( V_9 ) ; V_115 ++ ) {
V_30 -> V_124 [ V_115 ] . V_129 =
F_45 ( V_30 -> V_118 [ V_115 ] ) ;
if ( V_9 -> V_10 == V_11 )
V_30 -> V_124 [ V_115 ] . V_130 =
F_45 ( V_30 -> V_131 +
V_132 ) ;
else
V_30 -> V_124 [ V_115 ] . V_130 =
F_45 ( V_30 -> V_133 +
V_132 ) ;
V_30 -> V_124 [ V_115 ] . V_134 = F_45 ( 0 ) ;
V_30 -> V_124 [ V_115 ] . V_135 =
F_45 ( ( V_30 -> V_126 +
( ( V_115 + 1 ) % F_17 ( V_9 ) ) *
sizeof( V_30 -> V_124 [ 0 ] ) ) |
V_136 | V_137 |
V_138 ) ;
}
if ( F_23 ( V_9 ) ) {
for ( V_115 = 0 ; V_115 < V_121 ; V_115 ++ ) {
V_30 -> V_127 [ V_115 ] . V_129 =
F_45 ( V_30 -> V_123 [ V_115 ] ) ;
V_30 -> V_127 [ V_115 ] . V_130 =
F_45 ( V_30 -> V_133 +
V_139 ) ;
V_30 -> V_127 [ V_115 ] . V_134 = F_45 ( 0 ) ;
V_30 -> V_127 [ V_115 ] . V_135 =
F_45 ( ( V_30 -> V_128 +
( ( V_115 + 1 ) % ( V_121 ) ) *
sizeof( V_30 -> V_127 [ 0 ] ) ) |
V_136 |
V_137 ) ;
}
}
return 0 ;
}
static void F_46 ( struct V_14 * V_15 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
struct V_113 * V_114 = F_43 ( V_15 ) ;
struct V_29 * V_30 = V_15 -> V_31 ;
int V_115 ;
if ( ! V_30 )
return;
for ( V_115 = 0 ; V_115 < F_17 ( V_9 ) ; V_115 ++ ) {
if ( V_30 -> V_116 [ V_115 ] )
F_47 ( & V_114 -> V_15 ,
V_117 ,
V_30 -> V_116 [ V_115 ] ,
V_30 -> V_118 [ V_115 ] ) ;
}
for ( V_115 = 0 ; V_115 < V_121 ; V_115 ++ ) {
if ( V_30 -> V_122 [ V_115 ] )
F_47 ( & V_114 -> V_15 ,
V_117 ,
V_30 -> V_122 [ V_115 ] ,
V_30 -> V_123 [ V_115 ] ) ;
}
if ( V_30 -> V_124 )
F_47 ( & V_114 -> V_15 ,
sizeof( struct V_125 ) *
F_17 ( V_9 ) ,
V_30 -> V_124 ,
V_30 -> V_126 ) ;
if ( V_30 -> V_127 )
F_47 ( & V_114 -> V_15 ,
sizeof( struct V_125 ) *
V_121 ,
V_30 -> V_127 ,
V_30 -> V_128 ) ;
}
static inline void F_48 ( struct V_14 * V_15 )
{
F_22 ( V_15 -> V_27 ,
L_3 ) ;
F_22 ( V_15 -> V_27 ,
L_4 ) ;
}
static void F_49 ( struct V_14 * V_15 , int V_140 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
static const int V_141 = V_142 ;
void T_4 * V_143 = V_30 -> V_34 +
V_52 ;
if ( V_140 ) {
V_30 -> V_51 &= ~ V_141 ;
F_29 ( V_30 -> V_51 , V_143 ) ;
F_50 ( V_144 ) ;
} else {
V_30 -> V_51 |= V_141 ;
F_29 ( V_30 -> V_51 , V_143 ) ;
F_50 ( V_145 ) ;
}
}
static void F_51 ( struct V_14 * V_15 , int V_140 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
static const int V_146 = V_147 ;
void T_4 * V_143 = V_30 -> V_34 +
V_52 ;
if ( V_140 ) {
V_30 -> V_51 &= ~ V_146 ;
F_29 ( V_30 -> V_51 , V_143 ) ;
F_50 ( V_144 ) ;
} else {
V_30 -> V_51 |= V_146 ;
F_29 ( V_30 -> V_51 , V_143 ) ;
F_50 ( V_145 ) ;
}
}
static void F_52 ( struct V_14 * V_15 , T_2 V_148 )
{
T_2 V_149 ;
unsigned int V_150 = 8 ;
for ( V_149 = 1 << ( V_150 - 1 ) ; V_149 ; V_149 >>= 1 ) {
F_51 ( V_15 , 0 ) ;
if ( ( V_148 & V_149 ) )
F_49 ( V_15 , 1 ) ;
else
F_49 ( V_15 , 0 ) ;
F_51 ( V_15 , 1 ) ;
}
}
static int F_53 ( struct V_14 * V_15 )
{
F_51 ( V_15 , 0 ) ;
F_49 ( V_15 , 1 ) ;
F_51 ( V_15 , 1 ) ;
return 0 ;
}
static void F_54 ( struct V_14 * V_15 )
{
F_51 ( V_15 , 1 ) ;
F_49 ( V_15 , 1 ) ;
F_49 ( V_15 , 0 ) ;
}
static void F_55 ( struct V_14 * V_15 )
{
F_51 ( V_15 , 0 ) ;
F_49 ( V_15 , 0 ) ;
F_51 ( V_15 , 1 ) ;
F_49 ( V_15 , 1 ) ;
}
static void F_56 ( struct V_14 * V_15 , unsigned int V_151 ,
const T_2 * V_152 , unsigned int V_153 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned int V_115 ;
T_2 V_154 ;
static const int V_155 = 0x1 ;
V_30 -> V_51 &= ~ V_156 ;
F_55 ( V_15 ) ;
F_54 ( V_15 ) ;
V_154 = ( V_151 << 1 ) & ~ V_155 ;
F_52 ( V_15 , V_154 ) ;
if ( F_53 ( V_15 ) != 0 ) {
F_22 ( V_15 -> V_27 , L_5 ) ;
F_55 ( V_15 ) ;
return;
}
for ( V_115 = 0 ; V_115 < V_153 ; V_115 ++ ) {
F_52 ( V_15 , V_152 [ V_115 ] ) ;
if ( F_53 ( V_15 ) != 0 ) {
F_22 ( V_15 -> V_27 , L_5 ) ;
F_55 ( V_15 ) ;
return;
}
}
F_55 ( V_15 ) ;
}
static int F_57 ( struct V_14 * V_15 ,
struct V_157 * V_158 ,
struct V_159 * V_160 ,
unsigned long V_161 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned int V_162 ;
V_162 = F_58 ( V_30 -> V_44 + V_163 ) ;
if ( V_9 -> V_10 == V_11 ) {
V_162 = F_58 ( V_30 -> V_44 + V_164 ) ;
if ( V_162 )
return 0 ;
} else {
if ( F_11 ( V_162 ) )
return 0 ;
}
return - V_165 ;
}
static int F_59 ( struct V_14 * V_15 , struct V_157 * V_158 ,
struct V_159 * V_160 , unsigned int * V_152 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned int V_23 = 0 , V_166 ;
unsigned int V_1 , V_24 , V_167 ;
unsigned long V_32 ;
int V_168 ;
V_1 = F_60 ( V_160 -> V_169 ) ;
V_24 = F_61 ( V_160 -> V_169 ) ;
V_167 = F_62 ( V_160 -> V_169 ) ;
F_36 ( V_15 ) ;
F_25 ( & V_15 -> V_33 , V_32 ) ;
if ( V_160 -> V_169 & V_170 )
V_30 -> V_76 |= V_171 ;
else
V_30 -> V_76 &= ~ V_171 ;
F_31 ( V_30 -> V_76 ,
V_30 -> V_44 + V_78 ) ;
F_27 ( & V_15 -> V_33 , V_32 ) ;
if ( V_9 -> V_10 != V_11 ) {
V_30 -> V_104 &= ~ V_172 ;
F_31 ( V_30 -> V_104 ,
V_30 -> V_44 + V_105 ) ;
if ( V_160 -> V_169 & V_173 ) {
unsigned int V_174 ;
if ( V_9 -> V_10 == V_19 )
V_174 = V_175 ;
else
V_174 = V_176 ;
F_31 ( V_174 |
F_8 ( V_30 -> V_177 ) ,
V_30 -> V_44 + V_107 ) ;
} else {
F_31 ( 0 , V_30 -> V_44 + V_107 ) ;
}
V_23 = 0 ;
V_23 |= F_19 ( V_15 , F_61 ( V_160 -> V_169 ) ) ;
V_23 |= F_18 ( V_15 , V_167 == V_178 ) ;
if ( V_167 == V_179 )
V_23 |= V_180 ;
V_23 |= F_10 ( V_1 ) ;
F_31 ( F_10 ( V_1 ) ,
V_30 -> V_44 + V_181 ) ;
F_31 ( V_23 , V_30 -> V_44 + V_182 ) ;
} else {
T_2 V_183 = V_30 -> V_184 ;
V_30 -> V_184 &= ~ V_7 ;
if ( V_160 -> V_169 & V_173 ) {
V_30 -> V_184 |=
F_15 ( V_30 -> V_177 ) ;
} else {
V_30 -> V_184 |= F_15 ( 4 ) ;
}
if ( V_24 == 0 )
V_30 -> V_184 |= F_16 ( V_1 ) ;
else
V_30 -> V_184 &= ~ F_16 ( V_1 ) ;
if ( V_183 != V_30 -> V_184 ) {
T_2 V_185 = V_30 -> V_184 ;
F_56 ( V_15 , V_186 , & V_185 ,
sizeof( V_185 ) ) ;
}
F_31 ( 0 , V_30 -> V_44 + V_100 ) ;
F_31 ( 2 , V_30 -> V_44 + V_187 ) ;
}
for ( V_166 = 0 ; V_166 < V_160 -> V_166 ; V_166 ++ ) {
F_31 ( 0 , V_30 -> V_44 + V_188 ) ;
F_31 ( F_9 ( F_60 ( V_160 -> V_169 ) ) ,
V_30 -> V_44 + V_189 ) ;
V_168 = F_63 ( V_15 , V_158 , V_160 , F_57 , 0 ) ;
if ( V_168 )
return V_168 ;
if ( V_9 -> V_10 == V_11 )
V_152 [ V_166 ] = F_34 ( V_15 -> V_190 + V_132 ) & 0xffff ;
else
V_152 [ V_166 ] = F_58 ( V_30 -> V_44 + V_191 ) ;
}
return V_166 ;
}
static int F_64 ( struct V_14 * V_15 ,
unsigned int * V_152 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned int V_4 = V_152 [ 1 ] ;
int V_192 ;
if ( V_9 -> V_10 == V_19 )
V_192 = 16 ;
else
V_192 = 8 ;
if ( V_4 >= V_192 ) {
F_65 ( V_15 -> V_27 , L_6 ,
V_4 ) ;
return - V_193 ;
}
V_30 -> V_177 = V_4 ;
return 2 ;
}
static int F_66 ( struct V_14 * V_15 , unsigned int * V_152 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
int V_194 ;
const struct V_85 * const V_86 = V_9 -> V_87 ;
unsigned int V_195 , V_196 ;
int V_96 ;
V_196 = V_152 [ 1 ] ;
if ( V_196 ) {
V_194 = V_196 * V_86 -> V_98 /
V_197 ;
V_96 = F_39 ( V_15 , V_194 ) ;
if ( V_96 < 0 )
return V_96 ;
}
V_195 = F_40 ( V_15 ) / V_86 -> V_98 * V_197 ;
V_152 [ 1 ] = V_195 ;
return 2 ;
}
static int F_67 ( struct V_14 * V_15 ,
unsigned int * V_152 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned int V_198 = V_152 [ 4 ] ;
int V_96 = 0 ;
if ( V_198 < 2 ) {
V_198 = 2 ;
V_96 = - V_199 ;
}
switch ( V_152 [ 1 ] ) {
case V_200 :
V_30 -> V_201 . V_198 = V_198 ;
V_30 -> V_201 . V_169 = V_152 [ 2 ] ;
break;
default:
return - V_193 ;
}
V_152 [ 4 ] = V_198 ;
return V_96 ? V_96 : 5 ;
}
static int F_68 ( struct V_14 * V_15 , unsigned int * V_152 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
switch ( V_9 -> V_10 ) {
case V_11 :
return F_67 ( V_15 , V_152 ) ;
default:
return - V_193 ;
}
return - V_193 ;
}
static int F_69 ( struct V_14 * V_15 , struct V_157 * V_158 ,
struct V_159 * V_160 , unsigned int * V_152 )
{
int V_202 = V_152 [ 0 ] ;
switch ( V_202 ) {
case V_203 :
return F_64 ( V_15 , V_152 ) ;
case V_204 :
return F_66 ( V_15 , V_152 ) ;
case V_205 :
return F_68 ( V_15 , V_152 ) ;
default:
return - V_193 ;
}
return - V_193 ;
}
static unsigned int F_70 ( unsigned int V_206 , unsigned int V_32 )
{
unsigned int V_198 ;
switch ( V_32 & V_207 ) {
case V_208 :
V_198 = ( V_206 + V_209 - 1 ) / V_209 ;
break;
case V_210 :
V_198 = V_206 / V_209 ;
break;
case V_211 :
default:
V_198 = F_38 ( V_206 , V_209 ) ;
break;
}
return V_198 ;
}
static void F_71 ( struct V_14 * V_15 , struct V_46 * V_47 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
unsigned long long V_212 = 0 ;
unsigned int V_213 ;
static const int V_214 = 3 ;
static const int V_215 =
V_216 + V_214 ;
static const int V_217 = 2 ;
unsigned long long V_218 , V_219 ;
if ( V_47 -> V_220 == V_221 ) {
if ( V_9 -> V_10 == V_11 ) {
V_47 -> V_222 = 0 ;
} else {
V_212 = F_70 ( V_47 -> V_222 ,
V_47 -> V_32 ) ;
if ( V_212 > V_215 )
V_212 = V_215 ;
if ( V_212 < V_214 )
V_212 = V_214 ;
V_47 -> V_222 = V_212 * V_209 ;
}
} else if ( V_47 -> V_220 == V_223 ) {
V_47 -> V_222 = 0 ;
}
if ( V_47 -> V_224 == V_221 ) {
V_213 = F_70 ( V_47 -> V_225 , V_47 -> V_32 ) ;
if ( V_47 -> V_220 == V_221 ) {
V_219 = V_212 * V_47 -> V_226 ;
V_218 =
( V_212 * V_47 -> V_226 - 1 ) +
V_216 ;
} else {
V_219 = V_217 ;
V_218 = V_216 + V_219 ;
}
if ( V_213 > V_218 )
V_213 = V_218 ;
if ( V_213 < V_219 )
V_213 = V_219 ;
V_47 -> V_225 = V_213 * V_209 ;
}
}
static int F_72 ( struct V_14 * V_15 ,
struct V_157 * V_158 ,
struct V_46 * V_47 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
unsigned int V_227 = F_62 ( V_47 -> V_228 [ 0 ] ) ;
int V_115 ;
for ( V_115 = 1 ; V_115 < V_47 -> V_226 ; V_115 ++ ) {
unsigned int V_167 = F_62 ( V_47 -> V_228 [ V_115 ] ) ;
if ( V_167 != V_227 ) {
F_65 ( V_15 -> V_27 ,
L_7 ) ;
return - V_193 ;
}
}
if ( V_9 -> V_10 == V_11 ) {
unsigned int V_229 = F_60 ( V_47 -> V_228 [ 0 ] ) ;
for ( V_115 = 1 ; V_115 < V_47 -> V_226 ; V_115 ++ ) {
unsigned int V_230 = F_60 ( V_47 -> V_228 [ V_115 ] ) ;
if ( V_230 != ( V_229 + V_115 ) ) {
F_65 ( V_15 -> V_27 ,
L_8 ) ;
return - V_193 ;
}
}
if ( V_47 -> V_226 == 3 ) {
F_65 ( V_15 -> V_27 ,
L_9 ) ;
return - V_193 ;
}
}
return 0 ;
}
static int F_73 ( struct V_14 * V_15 , struct V_157 * V_158 ,
struct V_46 * V_47 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
int V_231 = 0 ;
unsigned int V_232 , V_233 ;
unsigned int V_234 ;
V_231 |= F_74 ( & V_47 -> V_235 , V_223 | V_236 ) ;
V_234 = V_221 ;
if ( V_9 -> V_10 == V_11 )
V_234 |= V_237 ;
else
V_234 |= V_238 ;
V_231 |= F_74 ( & V_47 -> V_224 , V_234 ) ;
V_234 = V_221 ;
if ( V_9 -> V_10 == V_11 )
V_234 |= V_223 ;
else
V_234 |= V_236 ;
V_231 |= F_74 ( & V_47 -> V_220 , V_234 ) ;
V_231 |= F_74 ( & V_47 -> V_239 , V_240 ) ;
V_231 |= F_74 ( & V_47 -> V_241 ,
V_240 | V_236 | V_242 ) ;
if ( V_231 )
return 1 ;
V_231 |= F_75 ( V_47 -> V_235 ) ;
V_231 |= F_75 ( V_47 -> V_224 ) ;
V_231 |= F_75 ( V_47 -> V_220 ) ;
V_231 |= F_75 ( V_47 -> V_241 ) ;
if ( V_47 -> V_220 == V_236 && V_47 -> V_224 == V_221 )
V_231 |= - V_193 ;
if ( V_231 )
return 2 ;
switch ( V_47 -> V_235 ) {
case V_223 :
V_231 |= F_76 ( & V_47 -> V_243 , 0 ) ;
break;
case V_236 :
break;
}
if ( V_47 -> V_220 == V_221 ) {
if ( V_9 -> V_10 == V_11 ) {
V_231 |= F_76 ( & V_47 -> V_222 ,
0 ) ;
} else {
V_231 |= F_77 ( & V_47 -> V_222 ,
V_9 -> V_244 ) ;
if ( V_47 -> V_224 == V_221 ) {
V_231 |= F_77 (
& V_47 -> V_225 ,
V_47 -> V_222 *
V_47 -> V_226 ) ;
}
}
}
V_231 |= F_77 ( & V_47 -> V_226 , 1 ) ;
V_231 |= F_76 ( & V_47 -> V_245 ,
V_47 -> V_226 ) ;
switch ( V_47 -> V_241 ) {
case V_236 :
break;
case V_240 :
V_231 |= F_77 ( & V_47 -> V_246 , 1 ) ;
break;
case V_242 :
V_231 |= F_76 ( & V_47 -> V_246 , 0 ) ;
break;
default:
break;
}
if ( V_231 )
return 3 ;
if ( V_47 -> V_220 == V_221 ) {
V_232 = V_47 -> V_222 ;
V_233 = V_47 -> V_225 ;
F_71 ( V_15 , V_47 ) ;
if ( V_232 != V_47 -> V_222 )
V_231 ++ ;
if ( V_233 != V_47 -> V_225 )
V_231 ++ ;
}
if ( V_231 )
return 4 ;
if ( V_47 -> V_228 && V_47 -> V_226 > 0 )
V_231 |= F_72 ( V_15 , V_158 , V_47 ) ;
if ( V_231 )
return 5 ;
return 0 ;
}
static int F_78 ( struct V_46 * V_47 )
{
return 0 ;
if ( V_47 -> V_241 == V_240 && V_47 -> V_246 <= V_216 )
return 1 ;
return 0 ;
}
static void F_79 ( struct V_14 * V_15 ,
struct V_46 * V_47 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
if ( F_78 ( V_47 ) ) {
F_31 ( V_47 -> V_246 & 0xffff ,
V_30 -> V_44 + V_247 ) ;
F_31 ( ( V_47 -> V_246 >> 16 ) & 0xff ,
V_30 -> V_44 + V_248 ) ;
} else {
F_31 ( 1 , V_30 -> V_44 + V_247 ) ;
}
}
static inline unsigned int F_80 ( struct V_14 * V_15 )
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
static T_3 F_81 ( const struct V_14 * V_15 ,
const struct V_46 * V_47 )
{
return V_47 -> V_222 / V_209 - 3 ;
}
static T_3 F_82 ( struct V_14 * V_15 ,
struct V_46 * V_47 )
{
T_3 V_249 ;
switch ( V_47 -> V_224 ) {
case V_221 :
V_249 = ( V_47 -> V_225 -
( V_47 -> V_222 * ( V_47 -> V_226 - 1 ) ) ) /
V_209 ;
break;
case V_238 :
V_249 = V_47 -> V_222 / V_209 ;
break;
default:
return 0 ;
}
return V_249 - 3 ;
}
static T_3 F_83 ( struct V_14 * V_15 ,
struct V_46 * V_47 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned int V_198 ;
switch ( V_47 -> V_224 ) {
case V_221 :
V_198 = V_47 -> V_225 / V_209 ;
break;
case V_237 :
V_198 = V_30 -> V_201 . V_198 ;
break;
default:
F_22 ( V_15 -> V_27 , L_10 ) ;
V_198 = 1000 ;
break;
}
return V_198 - 2 ;
}
static void F_84 ( struct V_14 * V_15 ,
const struct V_46 * V_47 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
V_30 -> V_104 &= ~ V_250 ;
if ( V_47 -> V_224 == V_237 ) {
int V_169 = V_30 -> V_201 . V_169 ;
if ( F_60 ( V_169 ) )
V_30 -> V_104 |= V_251 ;
else
V_30 -> V_104 |= V_252 ;
} else {
V_30 -> V_104 |= V_103 ;
}
F_31 ( V_30 -> V_104 ,
V_30 -> V_44 + V_105 ) ;
}
static void F_85 ( struct V_14 * V_15 ,
const struct V_46 * V_47 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
switch ( V_9 -> V_10 ) {
case V_11 :
F_84 ( V_15 , V_47 ) ;
break;
default:
break;
}
}
static inline void F_86 ( struct V_14 * V_15 ,
unsigned int V_1 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned long V_32 ;
F_25 ( & V_15 -> V_33 , V_32 ) ;
if ( V_1 )
F_87 ( V_253 | V_254 |
V_255 ,
V_30 -> V_34 + V_256 ) ;
else
F_87 ( V_253 | V_254 |
V_255 ,
V_30 -> V_34 + V_257 ) ;
F_27 ( & V_15 -> V_33 , V_32 ) ;
}
static void F_88 ( struct V_14 * V_15 , struct V_46 * V_47 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
struct V_29 * V_30 = V_15 -> V_31 ;
T_3 V_258 = 0 , V_259 = 0 ;
F_71 ( V_15 , V_47 ) ;
F_85 ( V_15 , V_47 ) ;
if ( V_9 -> V_10 == V_11 ) {
V_258 = F_83 ( V_15 , V_47 ) ;
} else {
V_258 = F_81 ( V_15 , V_47 ) ;
V_259 = F_82 ( V_15 , V_47 ) ;
}
F_31 ( V_258 & 0xffff ,
V_30 -> V_44 + V_187 ) ;
F_31 ( ( V_258 >> 16 ) & 0xff ,
V_30 -> V_44 + V_100 ) ;
F_31 ( V_259 & 0xffff ,
V_30 -> V_44 + V_260 ) ;
F_31 ( ( V_259 >> 16 ) & 0xff ,
V_30 -> V_44 + V_261 ) ;
}
static int F_89 ( const struct V_46 * V_47 )
{
int V_115 ;
for ( V_115 = 0 ; V_115 + 1 < V_47 -> V_226 ; V_115 ++ ) {
if ( F_60 ( V_47 -> V_228 [ V_115 + 1 ] ) !=
F_60 ( V_47 -> V_228 [ V_115 ] ) + 1 )
return 0 ;
if ( F_61 ( V_47 -> V_228 [ V_115 + 1 ] ) !=
F_61 ( V_47 -> V_228 [ V_115 ] ) )
return 0 ;
if ( F_62 ( V_47 -> V_228 [ V_115 + 1 ] ) != F_62 ( V_47 -> V_228 [ V_115 ] ) )
return 0 ;
}
return 1 ;
}
static int F_90 ( struct V_14 * V_15 ,
const struct V_46 * V_47 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned short V_23 ;
int V_115 ;
if ( V_9 -> V_10 != V_11 ) {
if ( F_89 ( V_47 ) ) {
V_30 -> V_104 &= ~ V_172 ;
F_31 ( V_30 -> V_104 ,
V_30 -> V_44 + V_105 ) ;
V_23 = 0 ;
V_23 |= F_10 ( F_60 ( V_47 -> V_228 [ 0 ] ) ) ;
V_23 |= F_19 ( V_15 ,
F_61 ( V_47 -> V_228 [ 0 ] ) ) ;
V_23 |= F_18 ( V_15 ,
F_62 ( V_47 -> V_228 [ 0 ] ) ==
V_178 ) ;
if ( F_62 ( V_47 -> V_228 [ 0 ] ) == V_179 )
V_23 |= V_180 ;
F_31 ( F_10
( F_60 ( V_47 -> V_228 [ V_47 -> V_226 - 1 ] ) ) ,
V_30 -> V_44 + V_181 ) ;
F_31 ( V_23 ,
V_30 -> V_44 + V_182 ) ;
} else {
if ( V_15 -> V_262 && V_15 -> V_262 -> V_263 ) {
F_48 ( V_15 ) ;
return - V_165 ;
}
V_30 -> V_104 |= V_172 ;
F_31 ( V_30 -> V_104 ,
V_30 -> V_44 + V_105 ) ;
F_31 ( 0 ,
V_30 -> V_44 + V_264 ) ;
F_31 ( 0 , V_30 -> V_44 + V_265 ) ;
for ( V_115 = 0 ; V_115 < V_47 -> V_226 ; V_115 ++ ) {
V_23 = 0 ;
V_23 |= F_10 ( F_60 ( V_47 ->
V_228 [ V_115 ] ) ) ;
V_23 |= F_19 ( V_15 ,
F_61 ( V_47 ->
V_228
[ V_115 ] ) ) ;
V_23 |= F_18 ( V_15 ,
F_62 ( V_47 ->
V_228 [ V_115 ] ) ==
V_178 ) ;
if ( F_62 ( V_47 -> V_228 [ V_115 ] ) == V_179 )
V_23 |= V_180 ;
if ( V_115 == V_47 -> V_226 - 1 )
V_23 |= V_266 |
V_267 ;
F_31 ( V_23 ,
V_30 -> V_44 +
V_268 ) ;
}
F_31 ( 0 , V_30 -> V_44 + V_265 ) ;
F_31 ( 0 , V_30 -> V_44 + V_182 ) ;
}
} else {
unsigned short V_183 = V_30 -> V_184 ;
V_30 -> V_184 &= ~ V_7 ;
V_30 -> V_184 |= F_15 ( 4 ) ;
for ( V_115 = 0 ; V_115 < V_47 -> V_226 ; V_115 ++ ) {
unsigned int V_1 = F_60 ( V_47 -> V_228 [ V_115 ] ) ;
unsigned int V_24 = F_61 ( V_47 -> V_228 [ V_115 ] ) ;
if ( V_24 == 0 )
V_30 -> V_184 |=
F_16 ( V_1 ) ;
else
V_30 -> V_184 &=
~ F_16 ( V_1 ) ;
}
if ( V_183 != V_30 -> V_184 ) {
T_2 V_185 = V_30 -> V_184 ;
F_56 ( V_15 , V_186 , & V_185 ,
sizeof( V_185 ) ) ;
}
}
return 0 ;
}
static inline void F_91 ( struct V_14 * V_15 ,
unsigned int V_269 ,
unsigned int V_270 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
if ( V_269 ) {
F_29 ( 0 ,
V_30 -> V_34 + V_271 ) ;
F_29 ( 0 , V_30 -> V_34 + V_272 ) ;
F_29 ( 0 ,
V_30 -> V_34 + V_273 ) ;
F_29 ( V_270 ,
V_30 -> V_34 + V_274 ) ;
} else {
F_29 ( 0 ,
V_30 -> V_34 + V_275 ) ;
F_29 ( 0 , V_30 -> V_34 + V_276 ) ;
F_29 ( 0 ,
V_30 -> V_34 + V_277 ) ;
F_29 ( V_270 ,
V_30 -> V_34 + V_278 ) ;
}
}
static int F_92 ( struct V_14 * V_15 , struct V_157 * V_158 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_279 * V_280 = V_158 -> V_280 ;
struct V_46 * V_47 = & V_280 -> V_47 ;
T_3 V_23 ;
unsigned int V_115 ;
unsigned long V_32 ;
int V_96 ;
F_36 ( V_15 ) ;
F_24 ( V_15 , 1 ) ;
V_96 = F_90 ( V_15 , V_47 ) ;
if ( V_96 < 0 )
return V_96 ;
F_31 ( 0 , V_30 -> V_44 + V_107 ) ;
F_88 ( V_15 , V_47 ) ;
F_79 ( V_15 , V_47 ) ;
F_32 ( V_15 , V_47 ) ;
F_25 ( & V_15 -> V_33 , V_32 ) ;
V_30 -> V_76 |= V_77 ;
V_30 -> V_76 &= ~ V_171 ;
if ( V_9 -> V_10 != V_11 ) {
V_30 -> V_76 &= ~ V_281 ;
if ( V_47 -> V_220 == V_236 )
V_30 -> V_76 |= F_7 ( 13 ) ;
else
V_30 -> V_76 |= F_7 ( 8 ) ;
} else {
V_30 -> V_76 &= ~ V_282 ;
if ( V_47 -> V_226 == 4 )
V_30 -> V_76 |= V_283 ;
else if ( V_47 -> V_226 == 2 )
V_30 -> V_76 |= V_284 ;
V_30 -> V_76 &= ~ V_285 ;
V_30 -> V_76 |=
F_5 ( F_60 ( V_47 -> V_228 [ 0 ] ) ) ;
V_30 -> V_76 &= ~ V_286 ;
V_30 -> V_76 |=
F_6 ( F_60 ( V_47 -> V_228
[ V_47 -> V_226 - 1 ] ) ) ;
}
F_31 ( V_30 -> V_76 ,
V_30 -> V_44 + V_78 ) ;
F_27 ( & V_15 -> V_33 , V_32 ) ;
F_31 ( 0 , V_30 -> V_44 + V_188 ) ;
if ( ( V_47 -> V_32 & V_48 ) == 0 ||
V_9 -> V_10 == V_11 ) {
V_30 -> V_287 = 0 ;
for ( V_115 = 0 ; V_115 < F_17 ( V_9 ) ; V_115 ++ )
V_30 -> V_124 [ V_115 ] . V_134 =
F_45 ( F_80 ( V_15 ) *
sizeof( T_1 ) ) ;
F_91 ( V_15 , 1 ,
V_30 -> V_126 |
V_136 |
V_137 |
V_138 ) ;
F_86 ( V_15 , 1 ) ;
}
if ( V_9 -> V_10 == V_11 ) {
V_23 = 0 ;
if ( V_47 -> V_235 == V_236 && F_60 ( V_47 -> V_243 ) )
V_23 |= V_288 ;
if ( V_47 -> V_241 == V_236 && F_60 ( V_47 -> V_246 ) )
V_23 |= V_289 ;
F_31 ( V_23 , V_30 -> V_44 + V_290 ) ;
}
F_25 ( & V_15 -> V_33 , V_32 ) ;
V_23 = V_291 | V_80 | V_81 ;
if ( V_47 -> V_32 & V_48 )
V_23 |= V_79 ;
if ( V_47 -> V_235 == V_236 ) {
V_23 |= V_292 ;
if ( V_47 -> V_243 & V_293 )
V_23 |= V_294 ;
} else if ( V_47 -> V_235 == V_223 ) {
V_23 |= V_295 ;
}
if ( F_78 ( V_47 ) )
V_23 |= V_296 ;
F_31 ( V_23 , V_30 -> V_44 + V_82 ) ;
V_30 -> V_297 = 1 ;
F_27 ( & V_15 -> V_33 , V_32 ) ;
if ( V_47 -> V_235 == V_223 )
F_31 ( 0 , V_30 -> V_44 + V_298 ) ;
return 0 ;
}
static void F_93 ( struct V_14 * V_15 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_157 * V_158 = V_15 -> V_299 ;
unsigned int V_115 ;
T_1 V_6 ;
int V_300 , V_301 , V_302 , V_303 ;
int V_94 ;
do {
V_301 = F_58 ( V_30 -> V_44 + V_304 ) &
0x7fff ;
V_303 = F_58 ( V_30 -> V_44 + V_164 ) &
0x7fff ;
V_6 = F_58 ( V_30 -> V_44 + V_305 ) ;
V_300 = F_13 ( V_6 ) ;
V_302 = F_14 ( V_6 ) ;
if ( V_300 != V_302 )
V_94 =
V_30 -> V_93 - V_301 ;
else
V_94 = V_303 - V_301 ;
if ( V_94 < 0 ) {
F_22 ( V_15 -> V_27 ,
L_11 ) ;
break;
}
V_94 = F_94 ( V_158 , V_94 ) ;
if ( V_94 == 0 )
break;
for ( V_115 = 0 ; V_115 < V_94 ; V_115 ++ ) {
unsigned short V_306 ;
V_306 = F_58 ( V_30 -> V_44 + V_132 ) ;
F_95 ( V_158 , & V_306 , 1 ) ;
}
} while ( V_300 != V_302 );
}
static void F_96 ( struct V_14 * V_15 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_157 * V_158 = V_15 -> V_299 ;
unsigned int V_307 ;
unsigned int V_115 ;
T_3 V_308 ;
int V_309 =
F_58 ( V_30 -> V_44 + V_164 ) & 0x7fff ;
int V_310 =
F_58 ( V_30 -> V_44 + V_304 ) & 0x7fff ;
V_307 = F_94 ( V_158 , 100000 ) ;
for ( V_115 = 0 ; V_310 != V_309 && V_115 < V_307 ; ) {
unsigned short V_306 ;
V_308 = F_34 ( V_15 -> V_190 + V_132 ) ;
V_306 = V_308 & 0xffff ;
F_95 ( V_158 , & V_306 , 1 ) ;
V_115 ++ ;
if ( V_115 < V_307 ) {
V_306 = ( V_308 >> 16 ) & 0xffff ;
F_95 ( V_158 , & V_306 , 1 ) ;
V_115 ++ ;
}
V_310 = F_58 ( V_30 -> V_44 + V_304 ) &
0x7fff ;
}
}
static void F_97 ( struct V_14 * V_15 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
if ( V_9 -> V_10 == V_11 )
F_96 ( V_15 ) ;
else
F_93 ( V_15 ) ;
}
static void F_98 ( struct V_14 * V_15 , unsigned int V_1 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_157 * V_158 = V_15 -> V_299 ;
T_3 V_311 ;
int V_312 ;
int V_94 = 0 ;
void T_4 * V_313 ;
if ( V_1 )
V_313 =
V_30 -> V_34 + V_272 ;
else
V_313 =
V_30 -> V_34 + V_276 ;
for ( V_312 = 0 , V_311 = F_34 ( V_313 ) ;
( V_311 <
V_30 -> V_118 [ V_30 -> V_287 ] ||
V_311 >=
V_30 -> V_118 [ V_30 -> V_287 ] +
V_117 ) && V_312 < F_17 ( V_9 ) ; V_312 ++ ) {
V_94 = F_94 ( V_158 , F_80 ( V_15 ) ) ;
F_95 ( V_158 ,
V_30 -> V_116 [ V_30 -> V_287 ] ,
V_94 ) ;
V_30 -> V_287 = ( V_30 -> V_287 + 1 ) %
F_17 ( V_9 ) ;
}
}
static void F_99 ( struct V_14 * V_15 ,
unsigned short V_162 ,
unsigned int V_314 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_157 * V_158 = V_15 -> V_299 ;
struct V_279 * V_280 = V_158 -> V_280 ;
struct V_46 * V_47 = & V_280 -> V_47 ;
T_2 V_315 ;
unsigned long V_32 ;
if ( V_162 & V_316 ) {
F_22 ( V_15 -> V_27 , L_12 ) ;
V_280 -> V_317 |= V_318 ;
}
F_25 ( & V_15 -> V_33 , V_32 ) ;
V_315 = F_100 ( V_30 -> V_34 + V_256 ) ;
if ( V_314 & V_319 ) {
F_87 ( ( V_315 & V_253 ) | V_255 ,
V_30 -> V_34 + V_256 ) ;
if ( V_315 & V_253 )
F_98 ( V_15 , 1 ) ;
}
F_27 ( & V_15 -> V_33 , V_32 ) ;
if ( ( V_162 & V_320 ) ||
( ( V_47 -> V_32 & V_48 ) &&
( V_162 & V_321 ) &&
( V_9 -> V_10 != V_11 ) ) ) {
F_25 ( & V_15 -> V_33 , V_32 ) ;
if ( V_30 -> V_297 ) {
F_27 ( & V_15 -> V_33 , V_32 ) ;
F_97 ( V_15 ) ;
} else {
F_27 ( & V_15 -> V_33 , V_32 ) ;
}
}
if ( ( V_47 -> V_241 == V_240 &&
V_280 -> V_322 >= V_47 -> V_246 ) ||
( V_47 -> V_241 == V_236 && ( V_162 & V_323 ) ) )
V_280 -> V_317 |= V_324 ;
F_101 ( V_15 , V_158 ) ;
}
static inline unsigned int F_102 ( struct V_14 * V_15 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned int V_325 ;
if ( V_30 -> V_326 == 0 )
V_325 = V_121 - 1 ;
else
V_325 = V_30 -> V_326 - 1 ;
return V_325 ;
}
static int F_103 ( struct V_14 * V_15 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned int V_325 ;
unsigned int V_327 ;
unsigned short V_328 ;
V_325 = F_102 ( V_15 ) ;
V_328 = F_100 ( V_30 -> V_34 + V_257 ) ;
if ( ( V_328 & V_329 ) == 0 )
return 0 ;
V_327 =
F_34 ( V_30 -> V_34 + V_276 ) ;
if ( V_327 != V_30 -> V_123 [ V_325 ] )
return 0 ;
return 1 ;
}
static inline int F_104 ( struct V_14 * V_15 ,
unsigned short V_328 )
{
if ( ( V_328 & V_329 ) == 0 ||
( V_328 & V_253 ) == 0 )
return 0 ;
if ( F_103 ( V_15 ) )
return 0 ;
return 1 ;
}
static void F_105 ( struct V_14 * V_15 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned int V_330 ;
V_330 =
F_34 ( V_30 -> V_34 + V_278 ) ;
V_330 &= ~ V_331 ;
F_91 ( V_15 , 0 , V_330 ) ;
F_86 ( V_15 , 0 ) ;
}
static unsigned int F_106 ( struct V_14 * V_15 ,
struct V_157 * V_158 ,
unsigned short * V_332 ,
unsigned int V_333 )
{
unsigned int V_307 = F_107 ( V_158 , V_333 ) ;
unsigned int V_334 ;
V_307 = F_94 ( V_158 , V_307 ) ;
V_334 = F_108 ( V_158 , V_332 , V_307 ) ;
return F_107 ( V_158 , V_334 ) ;
}
static unsigned int F_109 ( struct V_14 * V_15 ,
const struct V_46 * V_47 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_157 * V_158 = V_15 -> V_262 ;
unsigned int V_325 = V_30 -> V_326 ;
unsigned int V_335 = F_102 ( V_15 ) ;
unsigned int V_307 ;
unsigned int V_336 ;
unsigned int V_337 ;
V_307 = F_106 ( V_15 , V_158 ,
V_30 -> V_122 [ V_325 ] ,
V_117 ) ;
if ( V_307 == 0 )
return 0 ;
V_336 = F_110 ( V_158 , V_307 ) ;
V_30 -> V_127 [ V_325 ] . V_134 = F_45 ( V_336 ) ;
V_337 = F_111 ( V_30 -> V_127 [ V_325 ] . V_135 ) ;
V_337 |= V_331 ;
V_30 -> V_127 [ V_325 ] . V_135 = F_45 ( V_337 ) ;
V_337 = F_111 ( V_30 -> V_127 [ V_335 ] . V_135 ) ;
V_337 &= ~ V_331 ;
V_30 -> V_127 [ V_335 ] . V_135 = F_45 ( V_337 ) ;
V_30 -> V_326 = ( V_325 + 1 ) % V_121 ;
return V_336 ;
}
static void F_112 ( struct V_14 * V_15 , const struct V_46 * V_47 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned int V_338 ;
unsigned int V_311 ;
void T_4 * V_313 =
V_30 -> V_34 + V_276 ;
unsigned int V_325 ;
do {
V_325 = V_30 -> V_326 ;
V_311 = F_34 ( V_313 ) ;
if ( V_311 >=
V_30 -> V_123 [ V_325 ] &&
V_311 <
V_30 -> V_123 [ V_325 ] +
V_117 )
return;
V_338 = F_109 ( V_15 , V_47 ) ;
} while ( V_338 >= V_117 );
}
static void F_113 ( struct V_14 * V_15 ,
unsigned short V_162 , unsigned int V_314 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_157 * V_158 = V_15 -> V_262 ;
struct V_279 * V_280 ;
struct V_46 * V_47 ;
T_2 V_339 ;
unsigned long V_32 ;
if ( ! V_158 )
return;
V_280 = V_158 -> V_280 ;
V_47 = & V_280 -> V_47 ;
F_25 ( & V_15 -> V_33 , V_32 ) ;
V_339 = F_100 ( V_30 -> V_34 + V_257 ) ;
if ( V_314 & V_340 ) {
if ( ( V_339 & V_253 ) &&
! ( V_339 & V_329 ) )
F_87 ( V_253 | V_255 ,
V_30 -> V_34 + V_257 ) ;
else
F_87 ( V_255 ,
V_30 -> V_34 + V_257 ) ;
F_27 ( & V_15 -> V_33 , V_32 ) ;
if ( V_339 & V_253 ) {
F_112 ( V_15 , V_47 ) ;
if ( F_104 ( V_15 , V_339 ) )
F_105 ( V_15 ) ;
}
} else {
F_27 ( & V_15 -> V_33 , V_32 ) ;
}
if ( ( V_162 & V_341 ) ) {
if ( ( V_47 -> V_241 == V_240 &&
V_280 -> V_322 >= V_47 -> V_246 ) ||
F_103 ( V_15 ) )
V_280 -> V_317 |= V_324 ;
else
V_280 -> V_317 |= V_318 ;
}
F_101 ( V_15 , V_158 ) ;
}
static T_5 F_114 ( int V_342 , void * V_343 )
{
struct V_14 * V_15 = V_343 ;
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned short V_162 ;
T_3 V_314 ;
T_3 V_344 ;
V_314 = F_34 ( V_30 -> V_34 + V_36 ) ;
V_162 = F_58 ( V_30 -> V_44 + V_163 ) ;
if ( ! V_15 -> V_345 )
return V_346 ;
F_99 ( V_15 , V_162 , V_314 ) ;
F_113 ( V_15 , V_162 , V_314 ) ;
if ( V_314 & V_347 ) {
V_344 = F_34 ( V_30 -> V_34 + V_348 ) ;
F_29 ( V_344 , V_30 -> V_34 + V_348 ) ;
}
return V_346 ;
}
static int F_115 ( struct V_14 * V_15 , struct V_157 * V_158 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned long V_32 ;
F_25 ( & V_15 -> V_33 , V_32 ) ;
if ( V_30 -> V_297 == 0 ) {
F_27 ( & V_15 -> V_33 , V_32 ) ;
return 0 ;
}
V_30 -> V_297 = 0 ;
F_27 ( & V_15 -> V_33 , V_32 ) ;
F_36 ( V_15 ) ;
F_24 ( V_15 , 1 ) ;
return 0 ;
}
static int F_116 ( struct V_14 * V_15 , struct V_157 * V_158 ,
struct V_159 * V_160 , unsigned int * V_152 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
struct V_29 * V_30 = V_15 -> V_31 ;
int V_230 = F_60 ( V_160 -> V_169 ) ;
int V_24 = F_61 ( V_160 -> V_169 ) ;
F_31 ( 0 , V_30 -> V_44 + V_349 ) ;
F_21 ( V_15 , & V_30 -> V_109 , V_230 , V_24 ) ;
F_31 ( V_30 -> V_109 ,
V_30 -> V_44 + V_350 ) ;
if ( V_9 -> V_10 == V_11 ) {
F_31 ( V_152 [ 0 ] & 0xff ,
V_30 -> V_44 + F_2 ( V_230 ) ) ;
F_31 ( ( V_152 [ 0 ] >> 8 ) & 0xf ,
V_30 -> V_44 + F_3 ( V_230 ) ) ;
} else {
F_31 ( V_152 [ 0 ] , V_30 -> V_44 + F_1 ( V_230 ) ) ;
}
V_158 -> V_351 [ V_230 ] = V_152 [ 0 ] ;
return 1 ;
}
static void F_117 ( struct V_14 * V_15 ,
const struct V_46 * V_47 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned int V_23 = V_352 | V_353 |
V_354 | V_355 ;
if ( V_47 -> V_235 == V_236 ) {
V_23 |= V_356 ;
if ( V_47 -> V_243 & V_293 )
V_23 |= V_357 ;
} else {
V_23 |= V_358 ;
}
if ( V_47 -> V_224 == V_236 ) {
V_23 |= V_359 ;
if ( V_47 -> V_225 & V_293 )
V_23 |= V_360 ;
}
F_31 ( V_23 , V_30 -> V_44 + V_349 ) ;
}
static void F_118 ( struct V_14 * V_15 ,
const struct V_46 * V_47 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
int V_115 ;
for ( V_115 = 0 ; V_115 < V_47 -> V_226 ; V_115 ++ ) {
int V_1 , V_24 ;
V_1 = F_60 ( V_47 -> V_228 [ V_115 ] ) ;
V_24 = F_61 ( V_47 -> V_228 [ V_115 ] ) ;
F_21 ( V_15 , & V_30 -> V_109 , V_1 ,
V_24 ) ;
}
V_30 -> V_109 |= V_361 ;
F_31 ( V_30 -> V_109 ,
V_30 -> V_44 + V_350 ) ;
}
static void F_119 ( struct V_14 * V_15 ,
const struct V_46 * V_47 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
T_1 V_23 ;
unsigned int V_362 , V_363 ;
V_362 = F_60 ( V_47 -> V_228 [ 0 ] ) ;
V_363 = F_60 ( V_47 -> V_228 [ V_47 -> V_226 - 1 ] ) ;
if ( V_363 < V_362 )
F_22 ( V_15 -> V_27 ,
L_13 ) ;
V_23 = ( V_362 & 0x7 ) | ( V_363 & 0x7 ) << 3 ;
F_31 ( V_23 , V_30 -> V_44 + V_364 ) ;
}
static unsigned int F_120 ( unsigned int V_206 , unsigned int V_32 )
{
return F_70 ( V_206 , V_32 ) - 2 ;
}
static void F_121 ( struct V_14 * V_15 ,
const struct V_46 * V_47 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
unsigned int V_198 ;
if ( V_47 -> V_224 != V_221 )
return;
V_198 = F_120 ( V_47 -> V_225 , V_47 -> V_32 ) ;
if ( V_198 > V_216 ) {
F_22 ( V_15 -> V_27 , L_14 ) ;
V_198 = V_216 ;
}
F_31 ( V_198 & 0xffff ,
V_30 -> V_44 + V_365 ) ;
F_31 ( ( V_198 >> 16 ) & 0xff ,
V_30 -> V_44 + V_366 ) ;
}
static int F_122 ( struct V_14 * V_15 , const struct V_46 * V_47 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_157 * V_158 = V_15 -> V_262 ;
unsigned int V_307 ;
unsigned int V_336 ;
int V_115 ;
F_31 ( 0 , V_30 -> V_44 + V_265 ) ;
F_31 ( 0 , V_30 -> V_44 + V_264 ) ;
V_307 = F_106 ( V_15 , V_158 ,
V_30 -> V_367 ,
V_368 ) ;
if ( V_307 == 0 )
return - 1 ;
for ( V_115 = 0 ; V_115 < V_307 ; V_115 ++ ) {
F_31 ( V_30 -> V_367 [ V_115 ] ,
V_30 -> V_44 + V_139 ) ;
}
if ( V_47 -> V_241 == V_240 &&
V_158 -> V_280 -> V_322 >= V_47 -> V_246 )
return 0 ;
V_336 = F_109 ( V_15 , V_47 ) ;
if ( V_336 == 0 )
return - 1 ;
F_112 ( V_15 , V_47 ) ;
F_86 ( V_15 , 0 ) ;
return 0 ;
}
static inline int F_123 ( struct V_14 * V_15 ,
struct V_157 * V_158 ,
struct V_46 * V_47 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
if ( V_158 -> V_263 )
return 0 ;
if ( V_9 -> V_10 == V_11 )
return 0 ;
else if ( F_89 ( V_47 ) )
return 0 ;
return 1 ;
}
static int F_124 ( struct V_14 * V_15 , struct V_157 * V_158 ,
unsigned int V_369 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_46 * V_47 = & V_158 -> V_280 -> V_47 ;
int V_96 ;
if ( V_369 != V_47 -> V_243 )
return - V_193 ;
V_96 = F_122 ( V_15 , V_47 ) ;
if ( V_96 < 0 )
return - V_370 ;
F_117 ( V_15 , V_47 ) ;
if ( V_47 -> V_235 == V_371 )
F_31 ( 0 , V_30 -> V_44 + V_372 ) ;
V_158 -> V_280 -> V_373 = NULL ;
return 0 ;
}
static int F_125 ( struct V_14 * V_15 , struct V_157 * V_158 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_46 * V_47 = & V_158 -> V_280 -> V_47 ;
if ( F_123 ( V_15 , V_158 , V_47 ) ) {
F_48 ( V_15 ) ;
return - V_165 ;
}
F_31 ( 0x0 , V_30 -> V_44 + V_349 ) ;
V_30 -> V_326 = 0 ;
F_119 ( V_15 , V_47 ) ;
F_121 ( V_15 , V_47 ) ;
F_91 ( V_15 , 0 , V_30 -> V_128 |
V_136 | V_137 ) ;
F_118 ( V_15 , V_47 ) ;
V_158 -> V_280 -> V_373 = F_124 ;
return 0 ;
}
static int F_126 ( struct V_14 * V_15 ,
struct V_157 * V_158 ,
struct V_46 * V_47 )
{
unsigned int V_229 = F_60 ( V_47 -> V_228 [ 0 ] ) ;
int V_115 ;
for ( V_115 = 1 ; V_115 < V_47 -> V_226 ; V_115 ++ ) {
unsigned int V_230 = F_60 ( V_47 -> V_228 [ V_115 ] ) ;
if ( V_230 != ( V_229 + V_115 ) ) {
F_65 ( V_15 -> V_27 ,
L_8 ) ;
return - V_193 ;
}
}
return 0 ;
}
static int F_127 ( struct V_14 * V_15 , struct V_157 * V_158 ,
struct V_46 * V_47 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
int V_231 = 0 ;
unsigned int V_232 ;
V_231 |= F_74 ( & V_47 -> V_235 , V_371 | V_236 ) ;
V_231 |= F_74 ( & V_47 -> V_224 ,
V_221 | V_236 ) ;
V_231 |= F_74 ( & V_47 -> V_220 , V_223 ) ;
V_231 |= F_74 ( & V_47 -> V_239 , V_240 ) ;
V_231 |= F_74 ( & V_47 -> V_241 , V_242 ) ;
if ( V_231 )
return 1 ;
V_231 |= F_75 ( V_47 -> V_235 ) ;
V_231 |= F_75 ( V_47 -> V_224 ) ;
if ( V_47 -> V_220 == V_236 && V_47 -> V_224 == V_221 )
V_231 |= - V_193 ;
if ( V_47 -> V_241 != V_240 &&
V_47 -> V_241 != V_242 && V_47 -> V_241 != V_236 )
V_231 |= - V_193 ;
if ( V_231 )
return 2 ;
V_231 |= F_76 ( & V_47 -> V_243 , 0 ) ;
if ( V_47 -> V_224 == V_221 ) {
V_231 |= F_77 ( & V_47 -> V_225 ,
V_9 -> V_374 ) ;
if ( F_120 ( V_47 -> V_225 , V_47 -> V_32 ) >
V_216 ) {
V_47 -> V_225 = ( V_216 + 2 ) *
V_209 ;
V_231 |= - V_193 ;
}
}
V_231 |= F_77 ( & V_47 -> V_226 , 1 ) ;
V_231 |= F_76 ( & V_47 -> V_245 ,
V_47 -> V_226 ) ;
if ( V_231 )
return 3 ;
if ( V_47 -> V_224 == V_221 ) {
V_232 = V_47 -> V_225 ;
V_47 -> V_225 = F_70 ( V_47 -> V_225 ,
V_47 -> V_32 ) * V_209 ;
if ( V_232 != V_47 -> V_225 )
V_231 ++ ;
}
if ( V_231 )
return 4 ;
if ( V_47 -> V_228 && V_47 -> V_226 > 0 )
V_231 |= F_126 ( V_15 , V_158 , V_47 ) ;
if ( V_231 )
return 5 ;
return 0 ;
}
static int F_128 ( struct V_14 * V_15 , struct V_157 * V_158 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
F_31 ( 0x0 , V_30 -> V_44 + V_349 ) ;
F_24 ( V_15 , 0 ) ;
return 0 ;
}
static int F_129 ( struct V_14 * V_15 ,
int V_375 , int V_376 , int V_152 , unsigned long V_377 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
if ( V_375 ) {
F_31 ( V_152 , V_30 -> V_44 + V_377 + 2 * V_376 ) ;
return 0 ;
}
return F_58 ( V_30 -> V_44 + V_377 + 2 * V_376 ) ;
}
static int F_130 ( struct V_14 * V_15 , struct V_157 * V_158 ,
struct V_159 * V_160 , unsigned int * V_152 )
{
unsigned int V_23 ;
V_23 = F_100 ( V_15 -> V_190 + V_378 ) ;
V_23 &= 0xf ;
V_152 [ 1 ] = V_23 ;
V_152 [ 0 ] = 0 ;
return V_160 -> V_166 ;
}
static int F_131 ( struct V_14 * V_15 ,
struct V_157 * V_158 ,
struct V_159 * V_160 ,
unsigned int * V_152 )
{
if ( F_132 ( V_158 , V_152 ) )
F_87 ( V_158 -> V_140 , V_15 -> V_190 + V_379 ) ;
V_152 [ 1 ] = V_158 -> V_140 ;
return V_160 -> V_166 ;
}
static int F_133 ( struct V_14 * V_15 ,
struct V_157 * V_158 ,
struct V_159 * V_160 ,
unsigned int * V_152 )
{
int V_168 ;
V_168 = F_134 ( V_15 , V_158 , V_160 , V_152 , 0 ) ;
if ( V_168 )
return V_168 ;
F_87 ( V_158 -> V_380 , V_15 -> V_190 + V_381 ) ;
return V_160 -> V_166 ;
}
static int F_135 ( struct V_14 * V_15 ,
struct V_157 * V_158 ,
struct V_159 * V_160 ,
unsigned int * V_152 )
{
if ( F_132 ( V_158 , V_152 ) )
F_87 ( V_158 -> V_140 , V_15 -> V_190 + V_382 ) ;
V_152 [ 1 ] = F_100 ( V_15 -> V_190 + V_382 ) ;
return V_160 -> V_166 ;
}
static int F_136 ( struct V_14 * V_15 , unsigned int V_151 ,
T_2 V_383 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
static const int V_384 = 8 ;
static const int V_385 = 11 ;
unsigned int V_154 = ( ( V_151 & 0x7 ) << 8 ) | V_383 ;
unsigned int V_149 , V_386 ;
static const int V_387 = 1 ;
if ( V_151 >= V_384 ) {
F_22 ( V_15 -> V_27 , L_15 ) ;
return - 1 ;
}
for ( V_149 = 1 << ( V_385 - 1 ) ; V_149 ; V_149 >>= 1 ) {
V_386 = 0 ;
if ( V_154 & V_149 )
V_386 |= V_388 ;
F_50 ( V_387 ) ;
F_31 ( V_386 , V_30 -> V_44 + V_107 ) ;
V_386 |= V_389 ;
F_50 ( V_387 ) ;
F_31 ( V_386 , V_30 -> V_44 + V_107 ) ;
}
F_50 ( V_387 ) ;
F_31 ( V_390 , V_30 -> V_44 + V_107 ) ;
F_50 ( V_387 ) ;
F_31 ( 0 , V_30 -> V_44 + V_107 ) ;
F_50 ( V_387 ) ;
return 0 ;
}
static int F_137 ( struct V_14 * V_15 ,
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
F_22 ( V_15 -> V_27 , L_16 ) ;
return - 1 ;
}
V_392 [ 1 ] = V_398 | ( ( V_383 >> 8 ) & 0xf ) ;
V_392 [ 2 ] = V_383 & 0xff ;
F_56 ( V_15 , V_393 , V_392 , 3 ) ;
return 0 ;
}
static void F_138 ( struct V_14 * V_15 , unsigned int V_1 ,
unsigned int V_383 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
switch ( V_9 -> V_10 ) {
case V_19 :
case V_18 :
F_136 ( V_15 , V_1 , V_383 ) ;
break;
case V_11 :
F_137 ( V_15 , V_1 , V_383 ) ;
break;
default:
break;
}
}
static int F_139 ( struct V_14 * V_15 ,
struct V_157 * V_158 ,
struct V_159 * V_160 ,
unsigned int * V_152 )
{
unsigned int V_230 = F_60 ( V_160 -> V_169 ) ;
if ( V_160 -> V_166 ) {
unsigned int V_306 = V_152 [ V_160 -> V_166 - 1 ] ;
if ( V_158 -> V_351 [ V_230 ] != V_306 ) {
F_138 ( V_15 , V_230 , V_306 ) ;
V_158 -> V_351 [ V_230 ] = V_306 ;
}
}
return V_160 -> V_166 ;
}
static void F_140 ( struct V_14 * V_15 , unsigned int V_1 ,
unsigned int V_383 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
static const int V_385 = 10 ;
unsigned int V_149 , V_386 ;
unsigned int V_154 = ( ( V_1 & 0x3 ) << 8 ) | ( V_383 & 0xff ) ;
static const int V_401 = 1 ;
V_386 = V_402 ;
F_50 ( V_401 ) ;
F_31 ( V_386 , V_30 -> V_44 + V_107 ) ;
for ( V_149 = 1 << ( V_385 - 1 ) ; V_149 ; V_149 >>= 1 ) {
if ( V_154 & V_149 )
V_386 |= V_388 ;
else
V_386 &= ~ V_388 ;
F_50 ( V_401 ) ;
F_31 ( V_386 , V_30 -> V_44 + V_107 ) ;
F_50 ( V_401 ) ;
F_31 ( V_386 | V_389 ,
V_30 -> V_44 + V_107 ) ;
}
F_50 ( V_401 ) ;
F_31 ( 0 , V_30 -> V_44 + V_107 ) ;
}
static int F_141 ( struct V_14 * V_15 ,
struct V_157 * V_158 ,
struct V_159 * V_160 ,
unsigned int * V_152 )
{
unsigned int V_230 = F_60 ( V_160 -> V_169 ) ;
if ( V_160 -> V_166 ) {
unsigned int V_306 = V_152 [ V_160 -> V_166 - 1 ] ;
if ( V_158 -> V_351 [ V_230 ] != V_306 ) {
F_140 ( V_15 , V_230 , V_306 ) ;
V_158 -> V_351 [ V_230 ] = V_306 ;
}
}
return V_160 -> V_166 ;
}
static T_1 F_142 ( struct V_14 * V_15 , T_2 V_151 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
static const int V_385 = 11 ;
static const int V_403 = 0x6 ;
unsigned int V_154 = ( V_403 << 8 ) | V_151 ;
unsigned int V_149 ;
void T_4 * const V_143 =
V_30 -> V_34 + V_52 ;
T_1 V_383 ;
static const int V_404 = 16 ;
static const int V_405 = 1 ;
F_50 ( V_405 ) ;
V_30 -> V_51 &= ~ V_406 & ~ V_156 ;
V_30 -> V_51 |= V_147 ;
F_29 ( V_30 -> V_51 , V_143 ) ;
F_50 ( V_405 ) ;
V_30 -> V_51 |= V_156 ;
F_29 ( V_30 -> V_51 , V_143 ) ;
for ( V_149 = 1 << ( V_385 - 1 ) ; V_149 ; V_149 >>= 1 ) {
F_50 ( V_405 ) ;
if ( V_154 & V_149 )
V_30 -> V_51 |= V_142 ;
else
V_30 -> V_51 &= ~ V_142 ;
F_29 ( V_30 -> V_51 , V_143 ) ;
F_50 ( V_405 ) ;
V_30 -> V_51 |= V_406 ;
F_29 ( V_30 -> V_51 , V_143 ) ;
F_50 ( V_405 ) ;
V_30 -> V_51 &= ~ V_406 ;
F_29 ( V_30 -> V_51 , V_143 ) ;
}
V_383 = 0 ;
for ( V_149 = 1 << ( V_404 - 1 ) ; V_149 ; V_149 >>= 1 ) {
F_50 ( V_405 ) ;
V_30 -> V_51 |= V_406 ;
F_29 ( V_30 -> V_51 , V_143 ) ;
F_50 ( V_405 ) ;
V_30 -> V_51 &= ~ V_406 ;
F_29 ( V_30 -> V_51 , V_143 ) ;
F_50 ( V_405 ) ;
if ( F_34 ( V_143 ) & V_407 )
V_383 |= V_149 ;
}
F_50 ( V_405 ) ;
V_30 -> V_51 &= ~ V_156 ;
F_29 ( V_30 -> V_51 , V_143 ) ;
return V_383 ;
}
static int F_143 ( struct V_14 * V_15 ,
struct V_157 * V_158 ,
struct V_159 * V_160 , unsigned int * V_152 )
{
V_152 [ 0 ] = F_142 ( V_15 , F_60 ( V_160 -> V_169 ) ) ;
return 1 ;
}
static int F_144 ( struct V_14 * V_15 )
{
const struct V_8 * V_9 = V_15 -> V_17 ;
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_157 * V_158 ;
int V_115 ;
int V_168 ;
V_168 = F_145 ( V_15 , 10 ) ;
if ( V_168 )
return V_168 ;
V_158 = & V_15 -> V_408 [ 0 ] ;
V_15 -> V_299 = V_158 ;
V_158 -> type = V_409 ;
V_158 -> V_410 = V_411 | V_412 | V_413 | V_414 ;
if ( V_9 -> V_10 == V_19 )
V_158 -> V_410 |= V_415 | V_416 ;
else if ( V_9 -> V_10 == V_18 )
V_158 -> V_410 |= V_416 ;
V_158 -> V_417 = V_9 -> V_418 ;
V_158 -> V_419 = 0x2000 ;
V_158 -> V_420 = ( 1 << V_9 -> V_421 ) - 1 ;
V_158 -> V_422 = V_9 -> V_423 ;
V_158 -> V_424 = F_59 ;
V_158 -> V_425 = F_69 ;
V_158 -> V_426 = F_92 ;
V_158 -> V_427 = F_73 ;
V_158 -> V_428 = F_115 ;
if ( V_9 -> V_10 == V_11 ) {
T_2 V_152 ;
V_30 -> V_184 = F_15 ( 4 ) ;
for ( V_115 = 0 ; V_115 < V_158 -> V_417 ; V_115 ++ )
V_30 -> V_184 |= F_16 ( V_115 ) ;
V_152 = V_30 -> V_184 ;
F_56 ( V_15 , V_186 , & V_152 , sizeof( V_152 ) ) ;
}
V_158 = & V_15 -> V_408 [ 1 ] ;
if ( V_9 -> V_28 ) {
V_158 -> type = V_429 ;
V_158 -> V_410 = V_411 | V_430 |
V_412 | V_431 ;
V_158 -> V_417 = V_9 -> V_28 ;
V_158 -> V_420 = ( 1 << V_9 -> V_432 ) - 1 ;
V_158 -> V_422 = V_9 -> V_433 ;
V_158 -> V_434 = F_116 ;
V_168 = F_146 ( V_158 ) ;
if ( V_168 )
return V_168 ;
if ( F_23 ( V_9 ) ) {
V_15 -> V_262 = V_158 ;
V_158 -> V_427 = F_127 ;
V_158 -> V_426 = F_125 ;
V_158 -> V_419 = V_9 -> V_28 ;
V_158 -> V_428 = F_128 ;
}
} else {
V_158 -> type = V_435 ;
}
V_158 = & V_15 -> V_408 [ 2 ] ;
if ( V_9 -> V_10 == V_18 ) {
V_158 -> type = V_436 ;
V_158 -> V_410 = V_411 ;
V_158 -> V_417 = 4 ;
V_158 -> V_420 = 1 ;
V_158 -> V_422 = & V_437 ;
V_158 -> V_438 = F_130 ;
} else {
V_158 -> type = V_435 ;
}
if ( V_9 -> V_10 == V_18 ) {
V_158 = & V_15 -> V_408 [ 3 ] ;
V_158 -> type = V_439 ;
V_158 -> V_410 = V_430 ;
V_158 -> V_417 = 4 ;
V_158 -> V_420 = 1 ;
V_158 -> V_422 = & V_437 ;
V_158 -> V_438 = F_131 ;
} else {
V_158 -> type = V_435 ;
}
V_158 = & V_15 -> V_408 [ 4 ] ;
if ( V_9 -> V_440 ) {
if ( V_9 -> V_10 == V_11 ) {
V_168 = F_147 ( V_15 , V_158 , F_129 ,
V_441 ) ;
} else {
V_168 = F_148 ( V_15 , V_158 , NULL ,
V_442 ) ;
}
if ( V_168 )
return V_168 ;
} else {
V_158 -> type = V_435 ;
}
V_158 = & V_15 -> V_408 [ 5 ] ;
if ( V_9 -> V_10 == V_19 ) {
V_158 -> type = V_443 ;
V_158 -> V_410 = V_430 | V_411 ;
V_158 -> V_417 = 8 ;
V_158 -> V_420 = 1 ;
V_158 -> V_422 = & V_437 ;
V_158 -> V_425 = F_133 ;
V_158 -> V_438 = F_135 ;
} else {
V_158 -> type = V_435 ;
}
V_158 = & V_15 -> V_408 [ 6 ] ;
V_158 -> type = V_444 ;
V_158 -> V_410 = V_411 | V_430 | V_445 ;
V_158 -> V_417 = 8 ;
if ( V_9 -> V_10 == V_11 )
V_158 -> V_420 = 0xfff ;
else
V_158 -> V_420 = 0xff ;
V_158 -> V_434 = F_139 ;
V_168 = F_146 ( V_158 ) ;
if ( V_168 )
return V_168 ;
for ( V_115 = 0 ; V_115 < V_158 -> V_417 ; V_115 ++ ) {
F_138 ( V_15 , V_115 , V_158 -> V_420 / 2 ) ;
V_158 -> V_351 [ V_115 ] = V_158 -> V_420 / 2 ;
}
V_158 = & V_15 -> V_408 [ 7 ] ;
if ( V_9 -> V_10 == V_18 ) {
V_158 -> type = V_444 ;
V_158 -> V_410 = V_411 | V_430 | V_445 ;
V_158 -> V_417 = 2 ;
V_158 -> V_420 = 0xff ;
V_158 -> V_434 = F_141 ;
V_168 = F_146 ( V_158 ) ;
if ( V_168 )
return V_168 ;
for ( V_115 = 0 ; V_115 < V_158 -> V_417 ; V_115 ++ ) {
F_140 ( V_15 , V_115 , V_158 -> V_420 / 2 ) ;
V_158 -> V_351 [ V_115 ] = V_158 -> V_420 / 2 ;
}
} else {
V_158 -> type = V_435 ;
}
V_158 = & V_15 -> V_408 [ 8 ] ;
if ( F_34 ( V_30 -> V_34 + V_52 ) & V_446 ) {
V_158 -> type = V_447 ;
V_158 -> V_410 = V_411 | V_445 ;
V_158 -> V_417 = 128 ;
V_158 -> V_420 = 0xffff ;
V_158 -> V_424 = F_143 ;
} else {
V_158 -> type = V_435 ;
}
V_158 = & V_15 -> V_408 [ 9 ] ;
V_158 -> type = V_435 ;
return 0 ;
}
static int F_149 ( struct V_14 * V_15 ,
unsigned long V_161 )
{
struct V_113 * V_114 = F_43 ( V_15 ) ;
const struct V_8 * V_9 = NULL ;
struct V_29 * V_30 ;
T_3 V_448 , V_449 ;
int V_96 ;
if ( V_161 < F_150 ( V_450 ) )
V_9 = & V_450 [ V_161 ] ;
if ( ! V_9 )
return - V_451 ;
V_15 -> V_17 = V_9 ;
V_30 = F_151 ( V_15 , sizeof( * V_30 ) ) ;
if ( ! V_30 )
return - V_120 ;
V_96 = F_152 ( V_15 ) ;
if ( V_96 )
return V_96 ;
F_153 ( V_114 ) ;
V_15 -> V_452 = V_9 -> V_453 ;
V_30 -> V_454 = F_154 ( V_114 , 2 ) ;
V_30 -> V_455 = F_154 ( V_114 , 3 ) ;
V_30 -> V_34 = F_155 ( V_114 , 0 ) ;
V_30 -> V_44 = F_155 ( V_114 , 2 ) ;
V_15 -> V_190 = F_155 ( V_114 , 3 ) ;
if ( ! V_30 -> V_34 || ! V_30 -> V_44 || ! V_15 -> V_190 ) {
F_156 ( V_15 -> V_27 , L_17 ) ;
return - V_120 ;
}
V_448 = F_34 ( V_30 -> V_34 + V_456 ) &
V_457 ;
V_449 = F_34 ( V_30 -> V_34 + V_458 ) &
V_448 & V_459 ;
V_30 -> V_133 = ( ( T_3 ) V_30 -> V_454 &
~ V_448 ) | V_449 ;
V_448 = F_34 ( V_30 -> V_34 + V_460 ) &
V_457 ;
V_449 = F_34 ( V_30 -> V_34 + V_461 ) &
V_448 & V_459 ;
V_30 -> V_131 = ( ( T_3 ) V_30 -> V_455 &
~ V_448 ) | V_449 ;
V_96 = F_42 ( V_15 ) ;
if ( V_96 < 0 )
return V_96 ;
V_30 -> F_20 =
F_20 ( V_15 , F_58 ( V_30 -> V_44 + V_163 ) ) ;
F_65 ( V_15 -> V_27 , L_18 ,
V_30 -> F_20 ) ;
F_33 ( V_15 ) ;
F_41 ( V_15 ) ;
V_96 = F_157 ( V_114 -> V_342 , F_114 , V_462 ,
V_15 -> V_452 , V_15 ) ;
if ( V_96 ) {
F_65 ( V_15 -> V_27 , L_19 ,
V_114 -> V_342 ) ;
return V_96 ;
}
V_15 -> V_342 = V_114 -> V_342 ;
F_65 ( V_15 -> V_27 , L_20 , V_15 -> V_342 ) ;
V_96 = F_144 ( V_15 ) ;
if ( V_96 < 0 )
return V_96 ;
return 0 ;
}
static void F_158 ( struct V_14 * V_15 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
if ( V_15 -> V_342 )
F_159 ( V_15 -> V_342 , V_15 ) ;
if ( V_30 ) {
if ( V_30 -> V_34 ) {
F_28 ( V_15 ) ;
F_160 ( V_30 -> V_34 ) ;
}
if ( V_30 -> V_44 )
F_160 ( V_30 -> V_44 ) ;
if ( V_15 -> V_190 )
F_160 ( V_15 -> V_190 ) ;
}
F_161 ( V_15 ) ;
F_46 ( V_15 ) ;
}
static int F_162 ( struct V_113 * V_15 ,
const struct V_463 * V_202 )
{
return F_163 ( V_15 , & V_464 ,
V_202 -> V_465 ) ;
}
