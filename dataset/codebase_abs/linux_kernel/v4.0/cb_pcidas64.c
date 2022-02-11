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
const struct V_8 * V_17 = V_15 -> V_18 ;
if ( ( V_17 -> V_10 == V_19 && ! V_16 ) ||
( V_17 -> V_10 == V_20 && V_16 ) )
return V_21 ;
return 0 ;
}
static unsigned int F_19 ( const struct V_14 * V_15 ,
unsigned int V_22 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
return V_17 -> V_23 [ V_22 ] << 8 ;
}
static unsigned int F_20 ( const struct V_14 * V_15 ,
T_1 V_5 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
if ( V_17 -> V_10 == V_11 )
return ( V_5 >> 13 ) & 0x7 ;
return ( V_5 >> 12 ) & 0xf ;
}
static void F_21 ( struct V_14 * V_15 ,
T_1 * V_24 , unsigned int V_1 ,
unsigned int V_25 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
unsigned int V_26 = V_17 -> V_27 [ V_25 ] ;
if ( V_1 > 1 )
F_22 ( V_15 -> V_28 , L_1 ) ;
if ( V_26 & ~ 0x3 )
F_22 ( V_15 -> V_28 , L_2 ) ;
* V_24 &= ~ ( 0x3 << ( 2 * V_1 ) ) ;
* V_24 |= V_26 << ( 2 * V_1 ) ;
}
static inline int F_23 ( const struct V_8 * V_9 )
{
return V_9 -> V_29 && V_9 -> V_10 != V_11 ;
}
static void F_24 ( struct V_14 * V_15 , unsigned int V_1 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
unsigned long V_33 ;
F_25 ( & V_15 -> V_34 , V_33 ) ;
F_26 ( V_31 -> V_35 , V_1 ) ;
F_27 ( & V_15 -> V_34 , V_33 ) ;
}
static void F_28 ( struct V_14 * V_15 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
V_31 -> V_36 = 0 ;
F_29 ( V_31 -> V_36 ,
V_31 -> V_35 + V_37 ) ;
}
static void F_30 ( struct V_14 * V_15 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
unsigned long V_33 ;
F_25 ( & V_15 -> V_34 , V_33 ) ;
V_31 -> V_38 &=
~ V_39 & ~ V_40 &
~ V_41 & ~ V_42 &
~ V_43 & ~ V_44 ;
F_31 ( V_31 -> V_38 ,
V_31 -> V_45 + V_46 ) ;
F_27 ( & V_15 -> V_34 , V_33 ) ;
}
static void F_32 ( struct V_14 * V_15 ,
const struct V_47 * V_48 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_30 * V_31 = V_15 -> V_32 ;
T_3 V_24 ;
unsigned long V_33 ;
V_24 = V_43 | V_40 |
V_41 | V_42 ;
if ( V_48 -> V_33 & V_49 ) {
if ( V_17 -> V_10 != V_11 )
V_24 |= V_50 | V_39 ;
}
F_25 ( & V_15 -> V_34 , V_33 ) ;
V_31 -> V_38 |= V_24 ;
F_31 ( V_31 -> V_38 ,
V_31 -> V_45 + V_46 ) ;
F_27 ( & V_15 -> V_34 , V_33 ) ;
}
static void F_33 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_30 * V_31 = V_15 -> V_32 ;
T_3 V_24 ;
void T_4 * V_51 = V_31 -> V_35 ;
V_31 -> V_52 =
F_34 ( V_31 -> V_35 + V_53 ) ;
#ifdef F_35
V_24 = V_54 | V_55 ;
#else
V_24 = 0 ;
#endif
F_29 ( V_24 , V_31 -> V_35 + V_56 ) ;
F_28 ( V_15 ) ;
F_24 ( V_15 , 0 ) ;
F_24 ( V_15 , 1 ) ;
V_24 = 0 ;
V_24 |= V_57 ;
V_24 |= V_58 ;
V_24 |= V_59 ;
V_24 |= V_60 ;
V_24 |= V_61 ;
V_24 |= V_62 ;
V_24 |= V_63 ;
V_24 |= V_64 ;
if ( V_17 -> V_10 == V_11 )
V_24 |= V_65 ;
else
V_24 |= V_66 ;
F_29 ( V_24 , V_51 + V_67 ) ;
if ( F_23 ( V_17 ) )
F_29 ( V_24 , V_51 + V_68 ) ;
V_31 -> V_36 |=
V_69 | V_70 | V_71 | V_72 | V_73 | V_74 |
V_75 | V_76 ;
F_29 ( V_31 -> V_36 ,
V_31 -> V_35 + V_37 ) ;
}
static void F_36 ( struct V_14 * V_15 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
unsigned long V_33 ;
F_30 ( V_15 ) ;
F_25 ( & V_15 -> V_34 , V_33 ) ;
V_31 -> V_77 &= ~ V_78 ;
F_31 ( V_31 -> V_77 ,
V_31 -> V_45 + V_79 ) ;
F_27 ( & V_15 -> V_34 , V_33 ) ;
F_31 ( V_80 | V_81 | V_82 ,
V_31 -> V_45 + V_83 ) ;
}
static int F_37 ( struct V_14 * V_15 ,
unsigned int V_84 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_30 * V_31 = V_15 -> V_32 ;
static const int V_85 = 0x100 ;
const struct V_86 * const V_87 = V_17 -> V_88 ;
unsigned int V_89 ;
T_1 V_24 ;
if ( V_84 < V_85 )
V_84 = V_85 ;
if ( V_84 > V_87 -> V_90 )
V_84 = V_87 -> V_90 ;
V_89 = ( V_84 + V_85 / 2 ) / V_85 ;
V_24 = ( ~ ( V_89 - 1 ) ) & V_87 -> V_91 ;
V_31 -> V_92 &= ~ V_87 -> V_91 ;
V_31 -> V_92 |= V_24 ;
F_31 ( V_31 -> V_92 ,
V_31 -> V_45 + V_93 ) ;
V_31 -> V_94 = V_89 * V_85 ;
return V_31 -> V_94 ;
}
static int F_38 ( struct V_14 * V_15 , unsigned int V_95 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
unsigned int V_96 ;
int V_97 ;
const struct V_86 * const V_87 = V_17 -> V_88 ;
V_96 = V_95 / V_87 -> V_98 ;
V_97 = F_37 ( V_15 ,
V_96 /
V_87 -> V_99 ) ;
if ( V_97 < 0 )
return V_97 ;
V_95 = V_97 * V_87 -> V_99 * V_87 -> V_98 ;
return V_95 ;
}
static unsigned int F_39 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_30 * V_31 = V_15 -> V_32 ;
return V_31 -> V_94 *
V_17 -> V_88 -> V_99 *
V_17 -> V_88 -> V_98 ;
}
static void F_40 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_30 * V_31 = V_15 -> V_32 ;
T_1 V_24 ;
unsigned long V_33 ;
F_25 ( & V_15 -> V_34 , V_33 ) ;
if ( 1 )
V_31 -> V_77 |= V_100 ;
F_31 ( V_31 -> V_77 ,
V_31 -> V_45 + V_79 ) ;
F_31 ( 0xff , V_31 -> V_45 + V_101 ) ;
V_24 = V_102 | V_103 ;
if ( V_17 -> V_10 == V_11 )
V_24 |= V_104 ;
V_31 -> V_105 |= V_24 ;
F_31 ( V_31 -> V_105 ,
V_31 -> V_45 + V_106 ) ;
F_31 ( 0 , V_31 -> V_45 + V_107 ) ;
F_31 ( 0 , V_31 -> V_45 + V_108 ) ;
F_27 ( & V_15 -> V_34 , V_33 ) ;
V_31 -> V_92 |= V_109 ;
F_37 ( V_15 ,
V_17 -> V_88 -> V_90 ) ;
V_31 -> V_110 = V_111 ;
V_31 -> V_38 =
V_112 | V_113 ;
F_31 ( V_31 -> V_38 ,
V_31 -> V_45 + V_46 ) ;
F_36 ( V_15 ) ;
}
static int F_41 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_114 * V_115 = F_42 ( V_15 ) ;
struct V_30 * V_31 = V_15 -> V_32 ;
int V_116 ;
for ( V_116 = 0 ; V_116 < F_17 ( V_17 ) ; V_116 ++ ) {
V_31 -> V_117 [ V_116 ] =
F_43 ( V_115 , V_118 ,
& V_31 -> V_119 [ V_116 ] ) ;
if ( V_31 -> V_117 [ V_116 ] == NULL )
return - V_120 ;
}
for ( V_116 = 0 ; V_116 < V_121 ; V_116 ++ ) {
if ( F_23 ( V_17 ) ) {
V_31 -> V_122 [ V_116 ] =
F_43 ( V_115 , V_118 ,
& V_31 ->
V_123 [ V_116 ] ) ;
if ( V_31 -> V_122 [ V_116 ] == NULL )
return - V_120 ;
}
}
V_31 -> V_124 =
F_43 ( V_115 , sizeof( struct V_125 ) *
F_17 ( V_17 ) ,
& V_31 -> V_126 ) ;
if ( V_31 -> V_124 == NULL )
return - V_120 ;
if ( F_23 ( V_17 ) ) {
V_31 -> V_127 =
F_43 ( V_115 ,
sizeof( struct V_125 ) *
V_121 ,
& V_31 -> V_128 ) ;
if ( V_31 -> V_127 == NULL )
return - V_120 ;
}
for ( V_116 = 0 ; V_116 < F_17 ( V_17 ) ; V_116 ++ ) {
V_31 -> V_124 [ V_116 ] . V_129 =
F_44 ( V_31 -> V_119 [ V_116 ] ) ;
if ( V_17 -> V_10 == V_11 )
V_31 -> V_124 [ V_116 ] . V_130 =
F_44 ( V_31 -> V_131 +
V_132 ) ;
else
V_31 -> V_124 [ V_116 ] . V_130 =
F_44 ( V_31 -> V_133 +
V_132 ) ;
V_31 -> V_124 [ V_116 ] . V_134 = F_44 ( 0 ) ;
V_31 -> V_124 [ V_116 ] . V_135 =
F_44 ( ( V_31 -> V_126 +
( ( V_116 + 1 ) % F_17 ( V_17 ) ) *
sizeof( V_31 -> V_124 [ 0 ] ) ) |
V_136 | V_137 |
V_138 ) ;
}
if ( F_23 ( V_17 ) ) {
for ( V_116 = 0 ; V_116 < V_121 ; V_116 ++ ) {
V_31 -> V_127 [ V_116 ] . V_129 =
F_44 ( V_31 -> V_123 [ V_116 ] ) ;
V_31 -> V_127 [ V_116 ] . V_130 =
F_44 ( V_31 -> V_133 +
V_139 ) ;
V_31 -> V_127 [ V_116 ] . V_134 = F_44 ( 0 ) ;
V_31 -> V_127 [ V_116 ] . V_135 =
F_44 ( ( V_31 -> V_128 +
( ( V_116 + 1 ) % ( V_121 ) ) *
sizeof( V_31 -> V_127 [ 0 ] ) ) |
V_136 |
V_137 ) ;
}
}
return 0 ;
}
static void F_45 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_114 * V_115 = F_42 ( V_15 ) ;
struct V_30 * V_31 = V_15 -> V_32 ;
int V_116 ;
if ( ! V_31 )
return;
for ( V_116 = 0 ; V_116 < F_17 ( V_17 ) ; V_116 ++ ) {
if ( V_31 -> V_117 [ V_116 ] )
F_46 ( V_115 ,
V_118 ,
V_31 -> V_117 [ V_116 ] ,
V_31 -> V_119 [ V_116 ] ) ;
}
for ( V_116 = 0 ; V_116 < V_121 ; V_116 ++ ) {
if ( V_31 -> V_122 [ V_116 ] )
F_46 ( V_115 ,
V_118 ,
V_31 -> V_122 [ V_116 ] ,
V_31 -> V_123 [ V_116 ] ) ;
}
if ( V_31 -> V_124 )
F_46 ( V_115 ,
sizeof( struct V_125 ) *
F_17 ( V_17 ) ,
V_31 -> V_124 ,
V_31 -> V_126 ) ;
if ( V_31 -> V_127 )
F_46 ( V_115 ,
sizeof( struct V_125 ) *
V_121 ,
V_31 -> V_127 ,
V_31 -> V_128 ) ;
}
static inline void F_47 ( struct V_14 * V_15 )
{
F_22 ( V_15 -> V_28 ,
L_3 ) ;
F_22 ( V_15 -> V_28 ,
L_4 ) ;
}
static void F_48 ( struct V_14 * V_15 , int V_140 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
static const int V_141 = V_142 ;
void T_4 * V_143 = V_31 -> V_35 +
V_53 ;
if ( V_140 ) {
V_31 -> V_52 &= ~ V_141 ;
F_29 ( V_31 -> V_52 , V_143 ) ;
F_49 ( V_144 ) ;
} else {
V_31 -> V_52 |= V_141 ;
F_29 ( V_31 -> V_52 , V_143 ) ;
F_49 ( V_145 ) ;
}
}
static void F_50 ( struct V_14 * V_15 , int V_140 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
static const int V_146 = V_147 ;
void T_4 * V_143 = V_31 -> V_35 +
V_53 ;
if ( V_140 ) {
V_31 -> V_52 &= ~ V_146 ;
F_29 ( V_31 -> V_52 , V_143 ) ;
F_49 ( V_144 ) ;
} else {
V_31 -> V_52 |= V_146 ;
F_29 ( V_31 -> V_52 , V_143 ) ;
F_49 ( V_145 ) ;
}
}
static void F_51 ( struct V_14 * V_15 , T_2 V_148 )
{
T_2 V_149 ;
unsigned int V_150 = 8 ;
for ( V_149 = 1 << ( V_150 - 1 ) ; V_149 ; V_149 >>= 1 ) {
F_50 ( V_15 , 0 ) ;
if ( ( V_148 & V_149 ) )
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
static void F_55 ( struct V_14 * V_15 , unsigned int V_151 ,
const T_2 * V_152 , unsigned int V_153 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
unsigned int V_116 ;
T_2 V_154 ;
static const int V_155 = 0x1 ;
V_31 -> V_52 &= ~ V_156 ;
F_54 ( V_15 ) ;
F_53 ( V_15 ) ;
V_154 = ( V_151 << 1 ) & ~ V_155 ;
F_51 ( V_15 , V_154 ) ;
if ( F_52 ( V_15 ) != 0 ) {
F_22 ( V_15 -> V_28 , L_5 ,
V_157 ) ;
F_54 ( V_15 ) ;
return;
}
for ( V_116 = 0 ; V_116 < V_153 ; V_116 ++ ) {
F_51 ( V_15 , V_152 [ V_116 ] ) ;
if ( F_52 ( V_15 ) != 0 ) {
F_22 ( V_15 -> V_28 , L_5 ,
V_157 ) ;
F_54 ( V_15 ) ;
return;
}
}
F_54 ( V_15 ) ;
}
static int F_56 ( struct V_14 * V_15 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
unsigned long V_162 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_30 * V_31 = V_15 -> V_32 ;
unsigned int V_163 ;
V_163 = F_57 ( V_31 -> V_45 + V_164 ) ;
if ( V_17 -> V_10 == V_11 ) {
V_163 = F_57 ( V_31 -> V_45 + V_165 ) ;
if ( V_163 )
return 0 ;
} else {
if ( F_11 ( V_163 ) )
return 0 ;
}
return - V_166 ;
}
static int F_58 ( struct V_14 * V_15 , struct V_158 * V_159 ,
struct V_160 * V_161 , unsigned int * V_152 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_30 * V_31 = V_15 -> V_32 ;
unsigned int V_24 = 0 , V_167 ;
unsigned int V_1 , V_25 , V_168 ;
unsigned long V_33 ;
int V_169 ;
V_1 = F_59 ( V_161 -> V_170 ) ;
V_25 = F_60 ( V_161 -> V_170 ) ;
V_168 = F_61 ( V_161 -> V_170 ) ;
F_36 ( V_15 ) ;
F_25 ( & V_15 -> V_34 , V_33 ) ;
if ( V_161 -> V_170 & V_171 )
V_31 -> V_77 |= V_172 ;
else
V_31 -> V_77 &= ~ V_172 ;
F_31 ( V_31 -> V_77 ,
V_31 -> V_45 + V_79 ) ;
F_27 ( & V_15 -> V_34 , V_33 ) ;
if ( V_17 -> V_10 != V_11 ) {
V_31 -> V_105 &= ~ V_173 ;
F_31 ( V_31 -> V_105 ,
V_31 -> V_45 + V_106 ) ;
if ( V_161 -> V_170 & V_174 ) {
unsigned int V_175 ;
if ( V_17 -> V_10 == V_20 )
V_175 = V_176 ;
else
V_175 = V_177 ;
F_31 ( V_175 |
F_8 ( V_31 -> V_178 ) ,
V_31 -> V_45 + V_108 ) ;
} else {
F_31 ( 0 , V_31 -> V_45 + V_108 ) ;
}
V_24 = 0 ;
V_24 |= F_19 ( V_15 , F_60 ( V_161 -> V_170 ) ) ;
V_24 |= F_18 ( V_15 , V_168 == V_179 ) ;
if ( V_168 == V_180 )
V_24 |= V_181 ;
V_24 |= F_10 ( V_1 ) ;
F_31 ( F_10 ( V_1 ) ,
V_31 -> V_45 + V_182 ) ;
F_31 ( V_24 , V_31 -> V_45 + V_183 ) ;
} else {
T_2 V_184 = V_31 -> V_185 ;
V_31 -> V_185 &= ~ V_7 ;
if ( V_161 -> V_170 & V_174 ) {
V_31 -> V_185 |=
F_15 ( V_31 -> V_178 ) ;
} else {
V_31 -> V_185 |= F_15 ( 4 ) ;
}
if ( V_25 == 0 )
V_31 -> V_185 |= F_16 ( V_1 ) ;
else
V_31 -> V_185 &= ~ F_16 ( V_1 ) ;
if ( V_184 != V_31 -> V_185 ) {
T_2 V_186 = V_31 -> V_185 ;
F_55 ( V_15 , V_187 , & V_186 ,
sizeof( V_186 ) ) ;
}
F_31 ( 0 , V_31 -> V_45 + V_101 ) ;
F_31 ( 2 , V_31 -> V_45 + V_188 ) ;
}
for ( V_167 = 0 ; V_167 < V_161 -> V_167 ; V_167 ++ ) {
F_31 ( 0 , V_31 -> V_45 + V_189 ) ;
F_31 ( F_9 ( F_59 ( V_161 -> V_170 ) ) ,
V_31 -> V_45 + V_190 ) ;
V_169 = F_62 ( V_15 , V_159 , V_161 , F_56 , 0 ) ;
if ( V_169 )
return V_169 ;
if ( V_17 -> V_10 == V_11 )
V_152 [ V_167 ] = F_34 ( V_15 -> V_191 + V_132 ) & 0xffff ;
else
V_152 [ V_167 ] = F_57 ( V_31 -> V_45 + V_192 ) ;
}
return V_167 ;
}
static int F_63 ( struct V_14 * V_15 ,
unsigned int * V_152 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_30 * V_31 = V_15 -> V_32 ;
unsigned int V_4 = V_152 [ 1 ] ;
int V_193 ;
if ( V_17 -> V_10 == V_20 )
V_193 = 16 ;
else
V_193 = 8 ;
if ( V_4 >= V_193 ) {
F_64 ( V_15 -> V_28 , L_6 ,
V_4 ) ;
return - V_194 ;
}
V_31 -> V_178 = V_4 ;
return 2 ;
}
static int F_65 ( struct V_14 * V_15 , unsigned int * V_152 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
int V_195 ;
const struct V_86 * const V_87 = V_17 -> V_88 ;
unsigned int V_196 , V_197 ;
int V_97 ;
V_197 = V_152 [ 1 ] ;
if ( V_197 ) {
V_195 = V_197 * V_87 -> V_99 /
V_198 ;
V_97 = F_38 ( V_15 , V_195 ) ;
if ( V_97 < 0 )
return V_97 ;
}
V_196 = F_39 ( V_15 ) / V_87 -> V_99 * V_198 ;
V_152 [ 1 ] = V_196 ;
return 2 ;
}
static int F_66 ( struct V_14 * V_15 ,
unsigned int * V_152 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
unsigned int V_199 = V_152 [ 4 ] ;
int V_97 = 0 ;
if ( V_199 < 2 ) {
V_199 = 2 ;
V_97 = - V_200 ;
}
switch ( V_152 [ 1 ] ) {
case V_201 :
V_31 -> V_202 . V_199 = V_199 ;
V_31 -> V_202 . V_170 = V_152 [ 2 ] ;
break;
default:
return - V_194 ;
}
V_152 [ 4 ] = V_199 ;
return V_97 ? V_97 : 5 ;
}
static int F_67 ( struct V_14 * V_15 , unsigned int * V_152 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
switch ( V_17 -> V_10 ) {
case V_11 :
return F_66 ( V_15 , V_152 ) ;
default:
return - V_194 ;
}
return - V_194 ;
}
static int F_68 ( struct V_14 * V_15 , struct V_158 * V_159 ,
struct V_160 * V_161 , unsigned int * V_152 )
{
int V_203 = V_152 [ 0 ] ;
switch ( V_203 ) {
case V_204 :
return F_63 ( V_15 , V_152 ) ;
case V_205 :
return F_65 ( V_15 , V_152 ) ;
case V_206 :
return F_67 ( V_15 , V_152 ) ;
default:
return - V_194 ;
}
return - V_194 ;
}
static unsigned int F_69 ( unsigned int V_207 , unsigned int V_33 )
{
unsigned int V_199 ;
switch ( V_33 & V_208 ) {
case V_209 :
V_199 = ( V_207 + V_210 - 1 ) / V_210 ;
break;
case V_211 :
V_199 = V_207 / V_210 ;
break;
case V_212 :
default:
V_199 = ( V_207 + V_210 / 2 ) / V_210 ;
break;
}
return V_199 ;
}
static void F_70 ( struct V_14 * V_15 , struct V_47 * V_48 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
unsigned int V_213 = 0 , V_214 ;
static const int V_215 = 3 ;
static const int V_216 =
V_217 + V_215 ;
static const int V_218 = 2 ;
unsigned long long V_219 , V_220 ;
if ( V_48 -> V_221 == V_222 ) {
if ( V_17 -> V_10 == V_11 ) {
V_48 -> V_223 = 0 ;
} else {
V_213 = F_69 ( V_48 -> V_223 ,
V_48 -> V_33 ) ;
if ( V_213 > V_216 )
V_213 = V_216 ;
if ( V_213 < V_215 )
V_213 = V_215 ;
V_48 -> V_223 = V_213 * V_210 ;
}
} else if ( V_48 -> V_221 == V_224 ) {
V_48 -> V_223 = 0 ;
}
if ( V_48 -> V_225 == V_222 ) {
V_214 = F_69 ( V_48 -> V_226 , V_48 -> V_33 ) ;
if ( V_48 -> V_221 == V_222 ) {
V_220 = V_213 * V_48 -> V_227 ;
V_219 =
( V_213 * V_48 -> V_227 - 1 ) +
V_217 ;
} else {
V_220 = V_218 ;
V_219 = V_217 + V_220 ;
}
if ( V_214 > V_219 )
V_214 = V_219 ;
if ( V_214 < V_220 )
V_214 = V_220 ;
V_48 -> V_226 = V_214 * V_210 ;
}
}
static int F_71 ( struct V_14 * V_15 ,
struct V_158 * V_159 ,
struct V_47 * V_48 )
{
const struct V_8 * V_9 = V_15 -> V_18 ;
unsigned int V_228 = F_61 ( V_48 -> V_229 [ 0 ] ) ;
int V_116 ;
for ( V_116 = 1 ; V_116 < V_48 -> V_227 ; V_116 ++ ) {
unsigned int V_168 = F_61 ( V_48 -> V_229 [ V_116 ] ) ;
if ( V_168 != V_228 ) {
F_64 ( V_15 -> V_28 ,
L_7 ) ;
return - V_194 ;
}
}
if ( V_9 -> V_10 == V_11 ) {
unsigned int V_230 = F_59 ( V_48 -> V_229 [ 0 ] ) ;
for ( V_116 = 1 ; V_116 < V_48 -> V_227 ; V_116 ++ ) {
unsigned int V_231 = F_59 ( V_48 -> V_229 [ V_116 ] ) ;
if ( V_231 != ( V_230 + V_116 ) ) {
F_64 ( V_15 -> V_28 ,
L_8 ) ;
return - V_194 ;
}
}
if ( V_48 -> V_227 == 3 ) {
F_64 ( V_15 -> V_28 ,
L_9 ) ;
return - V_194 ;
}
}
return 0 ;
}
static int F_72 ( struct V_14 * V_15 , struct V_158 * V_159 ,
struct V_47 * V_48 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
int V_232 = 0 ;
unsigned int V_233 , V_234 ;
unsigned int V_235 ;
V_232 |= F_73 ( & V_48 -> V_236 , V_224 | V_237 ) ;
V_235 = V_222 ;
if ( V_17 -> V_10 == V_11 )
V_235 |= V_238 ;
else
V_235 |= V_239 ;
V_232 |= F_73 ( & V_48 -> V_225 , V_235 ) ;
V_235 = V_222 ;
if ( V_17 -> V_10 == V_11 )
V_235 |= V_224 ;
else
V_235 |= V_237 ;
V_232 |= F_73 ( & V_48 -> V_221 , V_235 ) ;
V_232 |= F_73 ( & V_48 -> V_240 , V_241 ) ;
V_232 |= F_73 ( & V_48 -> V_242 ,
V_241 | V_237 | V_243 ) ;
if ( V_232 )
return 1 ;
V_232 |= F_74 ( V_48 -> V_236 ) ;
V_232 |= F_74 ( V_48 -> V_225 ) ;
V_232 |= F_74 ( V_48 -> V_221 ) ;
V_232 |= F_74 ( V_48 -> V_242 ) ;
if ( V_48 -> V_221 == V_237 && V_48 -> V_225 == V_222 )
V_232 |= - V_194 ;
if ( V_232 )
return 2 ;
switch ( V_48 -> V_236 ) {
case V_224 :
V_232 |= F_75 ( & V_48 -> V_244 , 0 ) ;
break;
case V_237 :
break;
}
if ( V_48 -> V_221 == V_222 ) {
if ( V_17 -> V_10 == V_11 ) {
V_232 |= F_75 ( & V_48 -> V_223 , 0 ) ;
} else {
V_232 |= F_76 ( & V_48 -> V_223 ,
V_17 -> V_245 ) ;
if ( V_48 -> V_225 == V_222 )
V_232 |= F_76 (
& V_48 -> V_226 ,
V_48 -> V_223 *
V_48 -> V_227 ) ;
}
}
V_232 |= F_76 ( & V_48 -> V_227 , 1 ) ;
V_232 |= F_75 ( & V_48 -> V_246 , V_48 -> V_227 ) ;
switch ( V_48 -> V_242 ) {
case V_237 :
break;
case V_241 :
V_232 |= F_76 ( & V_48 -> V_247 , 1 ) ;
break;
case V_243 :
V_232 |= F_75 ( & V_48 -> V_247 , 0 ) ;
break;
default:
break;
}
if ( V_232 )
return 3 ;
if ( V_48 -> V_221 == V_222 ) {
V_233 = V_48 -> V_223 ;
V_234 = V_48 -> V_226 ;
F_70 ( V_15 , V_48 ) ;
if ( V_233 != V_48 -> V_223 )
V_232 ++ ;
if ( V_234 != V_48 -> V_226 )
V_232 ++ ;
}
if ( V_232 )
return 4 ;
if ( V_48 -> V_229 && V_48 -> V_227 > 0 )
V_232 |= F_71 ( V_15 , V_159 , V_48 ) ;
if ( V_232 )
return 5 ;
return 0 ;
}
static int F_77 ( struct V_47 * V_48 )
{
return 0 ;
if ( V_48 -> V_242 == V_241 && V_48 -> V_247 <= V_217 )
return 1 ;
return 0 ;
}
static void F_78 ( struct V_14 * V_15 ,
struct V_47 * V_48 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
if ( F_77 ( V_48 ) ) {
F_31 ( V_48 -> V_247 & 0xffff ,
V_31 -> V_45 + V_248 ) ;
F_31 ( ( V_48 -> V_247 >> 16 ) & 0xff ,
V_31 -> V_45 + V_249 ) ;
} else {
F_31 ( 1 , V_31 -> V_45 + V_248 ) ;
}
}
static inline unsigned int F_79 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_30 * V_31 = V_15 -> V_32 ;
unsigned int V_95 ;
V_95 = V_31 -> V_94 *
V_17 -> V_88 -> V_98 ;
if ( V_95 > V_118 / sizeof( T_1 ) )
V_95 = V_118 / sizeof( T_1 ) ;
return V_95 ;
}
static T_3 F_80 ( const struct V_14 * V_15 ,
const struct V_47 * V_48 )
{
return V_48 -> V_223 / V_210 - 3 ;
}
static T_3 F_81 ( struct V_14 * V_15 ,
struct V_47 * V_48 )
{
T_3 V_250 ;
switch ( V_48 -> V_225 ) {
case V_222 :
V_250 = ( V_48 -> V_226 -
( V_48 -> V_223 * ( V_48 -> V_227 - 1 ) ) ) /
V_210 ;
break;
case V_239 :
V_250 = V_48 -> V_223 / V_210 ;
break;
default:
return 0 ;
}
return V_250 - 3 ;
}
static T_3 F_82 ( struct V_14 * V_15 ,
struct V_47 * V_48 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
unsigned int V_199 ;
switch ( V_48 -> V_225 ) {
case V_222 :
V_199 = V_48 -> V_226 / V_210 ;
break;
case V_238 :
V_199 = V_31 -> V_202 . V_199 ;
break;
default:
F_22 ( V_15 -> V_28 , L_10 ) ;
V_199 = 1000 ;
break;
}
return V_199 - 2 ;
}
static void F_83 ( struct V_14 * V_15 ,
const struct V_47 * V_48 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
V_31 -> V_105 &= ~ V_251 ;
if ( V_48 -> V_225 == V_238 ) {
int V_170 = V_31 -> V_202 . V_170 ;
if ( F_59 ( V_170 ) )
V_31 -> V_105 |= V_252 ;
else
V_31 -> V_105 |= V_253 ;
} else {
V_31 -> V_105 |= V_104 ;
}
F_31 ( V_31 -> V_105 ,
V_31 -> V_45 + V_106 ) ;
}
static void F_84 ( struct V_14 * V_15 ,
const struct V_47 * V_48 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
switch ( V_17 -> V_10 ) {
case V_11 :
F_83 ( V_15 , V_48 ) ;
break;
default:
break;
}
}
static inline void F_85 ( struct V_14 * V_15 ,
unsigned int V_1 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
unsigned long V_33 ;
F_25 ( & V_15 -> V_34 , V_33 ) ;
if ( V_1 )
F_86 ( V_254 | V_255 |
V_256 ,
V_31 -> V_35 + V_257 ) ;
else
F_86 ( V_254 | V_255 |
V_256 ,
V_31 -> V_35 + V_258 ) ;
F_27 ( & V_15 -> V_34 , V_33 ) ;
}
static void F_87 ( struct V_14 * V_15 , struct V_47 * V_48 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_30 * V_31 = V_15 -> V_32 ;
T_3 V_259 = 0 , V_260 = 0 ;
F_70 ( V_15 , V_48 ) ;
F_84 ( V_15 , V_48 ) ;
if ( V_17 -> V_10 == V_11 ) {
V_259 = F_82 ( V_15 , V_48 ) ;
} else {
V_259 = F_80 ( V_15 , V_48 ) ;
V_260 = F_81 ( V_15 , V_48 ) ;
}
F_31 ( V_259 & 0xffff ,
V_31 -> V_45 + V_188 ) ;
F_31 ( ( V_259 >> 16 ) & 0xff ,
V_31 -> V_45 + V_101 ) ;
F_31 ( V_260 & 0xffff ,
V_31 -> V_45 + V_261 ) ;
F_31 ( ( V_260 >> 16 ) & 0xff ,
V_31 -> V_45 + V_262 ) ;
}
static int F_88 ( const struct V_47 * V_48 )
{
int V_116 ;
for ( V_116 = 0 ; V_116 + 1 < V_48 -> V_227 ; V_116 ++ ) {
if ( F_59 ( V_48 -> V_229 [ V_116 + 1 ] ) !=
F_59 ( V_48 -> V_229 [ V_116 ] ) + 1 )
return 0 ;
if ( F_60 ( V_48 -> V_229 [ V_116 + 1 ] ) !=
F_60 ( V_48 -> V_229 [ V_116 ] ) )
return 0 ;
if ( F_61 ( V_48 -> V_229 [ V_116 + 1 ] ) != F_61 ( V_48 -> V_229 [ V_116 ] ) )
return 0 ;
}
return 1 ;
}
static int F_89 ( struct V_14 * V_15 ,
const struct V_47 * V_48 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_30 * V_31 = V_15 -> V_32 ;
unsigned short V_24 ;
int V_116 ;
if ( V_17 -> V_10 != V_11 ) {
if ( F_88 ( V_48 ) ) {
V_31 -> V_105 &= ~ V_173 ;
F_31 ( V_31 -> V_105 ,
V_31 -> V_45 + V_106 ) ;
V_24 = 0 ;
V_24 |= F_10 ( F_59 ( V_48 -> V_229 [ 0 ] ) ) ;
V_24 |= F_19 ( V_15 ,
F_60 ( V_48 -> V_229 [ 0 ] ) ) ;
V_24 |= F_18 ( V_15 ,
F_61 ( V_48 -> V_229 [ 0 ] ) ==
V_179 ) ;
if ( F_61 ( V_48 -> V_229 [ 0 ] ) == V_180 )
V_24 |= V_181 ;
F_31 ( F_10
( F_59 ( V_48 -> V_229 [ V_48 -> V_227 - 1 ] ) ) ,
V_31 -> V_45 + V_182 ) ;
F_31 ( V_24 ,
V_31 -> V_45 + V_183 ) ;
} else {
if ( V_15 -> V_263 && V_15 -> V_263 -> V_264 ) {
F_47 ( V_15 ) ;
return - V_166 ;
}
V_31 -> V_105 |= V_173 ;
F_31 ( V_31 -> V_105 ,
V_31 -> V_45 + V_106 ) ;
F_31 ( 0 ,
V_31 -> V_45 + V_265 ) ;
F_31 ( 0 , V_31 -> V_45 + V_266 ) ;
for ( V_116 = 0 ; V_116 < V_48 -> V_227 ; V_116 ++ ) {
V_24 = 0 ;
V_24 |= F_10 ( F_59 ( V_48 ->
V_229 [ V_116 ] ) ) ;
V_24 |= F_19 ( V_15 ,
F_60 ( V_48 ->
V_229
[ V_116 ] ) ) ;
V_24 |= F_18 ( V_15 ,
F_61 ( V_48 ->
V_229 [ V_116 ] ) ==
V_179 ) ;
if ( F_61 ( V_48 -> V_229 [ V_116 ] ) == V_180 )
V_24 |= V_181 ;
if ( V_116 == V_48 -> V_227 - 1 )
V_24 |= V_267 |
V_268 ;
F_31 ( V_24 ,
V_31 -> V_45 +
V_269 ) ;
}
F_31 ( 0 , V_31 -> V_45 + V_266 ) ;
F_31 ( 0 , V_31 -> V_45 + V_183 ) ;
}
} else {
unsigned short V_184 = V_31 -> V_185 ;
V_31 -> V_185 &= ~ V_7 ;
V_31 -> V_185 |= F_15 ( 4 ) ;
for ( V_116 = 0 ; V_116 < V_48 -> V_227 ; V_116 ++ ) {
unsigned int V_1 = F_59 ( V_48 -> V_229 [ V_116 ] ) ;
unsigned int V_25 = F_60 ( V_48 -> V_229 [ V_116 ] ) ;
if ( V_25 == 0 )
V_31 -> V_185 |=
F_16 ( V_1 ) ;
else
V_31 -> V_185 &=
~ F_16 ( V_1 ) ;
}
if ( V_184 != V_31 -> V_185 ) {
T_2 V_186 = V_31 -> V_185 ;
F_55 ( V_15 , V_187 , & V_186 ,
sizeof( V_186 ) ) ;
}
}
return 0 ;
}
static inline void F_90 ( struct V_14 * V_15 ,
unsigned int V_270 ,
unsigned int V_271 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
if ( V_270 ) {
F_29 ( 0 ,
V_31 -> V_35 + V_272 ) ;
F_29 ( 0 , V_31 -> V_35 + V_273 ) ;
F_29 ( 0 ,
V_31 -> V_35 + V_274 ) ;
F_29 ( V_271 ,
V_31 -> V_35 + V_275 ) ;
} else {
F_29 ( 0 ,
V_31 -> V_35 + V_276 ) ;
F_29 ( 0 , V_31 -> V_35 + V_277 ) ;
F_29 ( 0 ,
V_31 -> V_35 + V_278 ) ;
F_29 ( V_271 ,
V_31 -> V_35 + V_279 ) ;
}
}
static int F_91 ( struct V_14 * V_15 , struct V_158 * V_159 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_30 * V_31 = V_15 -> V_32 ;
struct V_280 * V_281 = V_159 -> V_281 ;
struct V_47 * V_48 = & V_281 -> V_48 ;
T_3 V_24 ;
unsigned int V_116 ;
unsigned long V_33 ;
int V_97 ;
F_36 ( V_15 ) ;
F_24 ( V_15 , 1 ) ;
V_97 = F_89 ( V_15 , V_48 ) ;
if ( V_97 < 0 )
return V_97 ;
F_31 ( 0 , V_31 -> V_45 + V_108 ) ;
F_87 ( V_15 , V_48 ) ;
F_78 ( V_15 , V_48 ) ;
F_32 ( V_15 , V_48 ) ;
F_25 ( & V_15 -> V_34 , V_33 ) ;
V_31 -> V_77 |= V_78 ;
V_31 -> V_77 &= ~ V_172 ;
if ( V_17 -> V_10 != V_11 ) {
V_31 -> V_77 &= ~ V_282 ;
if ( V_48 -> V_221 == V_237 )
V_31 -> V_77 |= F_7 ( 13 ) ;
else
V_31 -> V_77 |= F_7 ( 8 ) ;
} else {
V_31 -> V_77 &= ~ V_283 ;
if ( V_48 -> V_227 == 4 )
V_31 -> V_77 |= V_284 ;
else if ( V_48 -> V_227 == 2 )
V_31 -> V_77 |= V_285 ;
V_31 -> V_77 &= ~ V_286 ;
V_31 -> V_77 |=
F_5 ( F_59 ( V_48 -> V_229 [ 0 ] ) ) ;
V_31 -> V_77 &= ~ V_287 ;
V_31 -> V_77 |=
F_6 ( F_59 ( V_48 -> V_229
[ V_48 -> V_227 - 1 ] ) ) ;
}
F_31 ( V_31 -> V_77 ,
V_31 -> V_45 + V_79 ) ;
F_27 ( & V_15 -> V_34 , V_33 ) ;
F_31 ( 0 , V_31 -> V_45 + V_189 ) ;
if ( ( V_48 -> V_33 & V_49 ) == 0 ||
V_17 -> V_10 == V_11 ) {
V_31 -> V_288 = 0 ;
for ( V_116 = 0 ; V_116 < F_17 ( V_17 ) ; V_116 ++ )
V_31 -> V_124 [ V_116 ] . V_134 =
F_44 ( F_79 ( V_15 ) *
sizeof( T_1 ) ) ;
F_90 ( V_15 , 1 ,
V_31 -> V_126 |
V_136 |
V_137 |
V_138 ) ;
F_85 ( V_15 , 1 ) ;
}
if ( V_17 -> V_10 == V_11 ) {
V_24 = 0 ;
if ( V_48 -> V_236 == V_237 && F_59 ( V_48 -> V_244 ) )
V_24 |= V_289 ;
if ( V_48 -> V_242 == V_237 && F_59 ( V_48 -> V_247 ) )
V_24 |= V_290 ;
F_31 ( V_24 , V_31 -> V_45 + V_291 ) ;
}
F_25 ( & V_15 -> V_34 , V_33 ) ;
V_24 = V_292 | V_81 | V_82 ;
if ( V_48 -> V_33 & V_49 )
V_24 |= V_80 ;
if ( V_48 -> V_236 == V_237 ) {
V_24 |= V_293 ;
if ( V_48 -> V_244 & V_294 )
V_24 |= V_295 ;
} else if ( V_48 -> V_236 == V_224 )
V_24 |= V_296 ;
if ( F_77 ( V_48 ) )
V_24 |= V_297 ;
F_31 ( V_24 , V_31 -> V_45 + V_83 ) ;
V_31 -> V_298 = 1 ;
F_27 ( & V_15 -> V_34 , V_33 ) ;
if ( V_48 -> V_236 == V_224 )
F_31 ( 0 , V_31 -> V_45 + V_299 ) ;
return 0 ;
}
static void F_92 ( struct V_14 * V_15 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
struct V_158 * V_159 = V_15 -> V_300 ;
unsigned int V_116 ;
T_1 V_6 ;
int V_301 , V_302 , V_303 , V_304 ;
int V_95 ;
do {
V_302 = F_57 ( V_31 -> V_45 + V_305 ) &
0x7fff ;
V_304 = F_57 ( V_31 -> V_45 + V_165 ) &
0x7fff ;
V_6 = F_57 ( V_31 -> V_45 + V_306 ) ;
V_301 = F_13 ( V_6 ) ;
V_303 = F_14 ( V_6 ) ;
if ( V_301 != V_303 )
V_95 =
V_31 -> V_94 - V_302 ;
else
V_95 = V_304 - V_302 ;
if ( V_95 < 0 ) {
F_22 ( V_15 -> V_28 ,
L_11 ) ;
break;
}
V_95 = F_93 ( V_159 , V_95 ) ;
if ( V_95 == 0 )
break;
for ( V_116 = 0 ; V_116 < V_95 ; V_116 ++ ) {
unsigned short V_307 ;
V_307 = F_57 ( V_31 -> V_45 + V_132 ) ;
F_94 ( V_159 , & V_307 , 1 ) ;
}
} while ( V_301 != V_303 );
}
static void F_95 ( struct V_14 * V_15 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
struct V_158 * V_159 = V_15 -> V_300 ;
unsigned int V_308 ;
unsigned int V_116 ;
T_3 V_309 ;
int V_310 =
F_57 ( V_31 -> V_45 + V_165 ) & 0x7fff ;
int V_311 =
F_57 ( V_31 -> V_45 + V_305 ) & 0x7fff ;
V_308 = F_93 ( V_159 , 100000 ) ;
for ( V_116 = 0 ; V_311 != V_310 && V_116 < V_308 ; ) {
unsigned short V_307 ;
V_309 = F_34 ( V_15 -> V_191 + V_132 ) ;
V_307 = V_309 & 0xffff ;
F_94 ( V_159 , & V_307 , 1 ) ;
V_116 ++ ;
if ( V_116 < V_308 ) {
V_307 = ( V_309 >> 16 ) & 0xffff ;
F_94 ( V_159 , & V_307 , 1 ) ;
V_116 ++ ;
}
V_311 = F_57 ( V_31 -> V_45 + V_305 ) &
0x7fff ;
}
}
static void F_96 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
if ( V_17 -> V_10 == V_11 )
F_95 ( V_15 ) ;
else
F_92 ( V_15 ) ;
}
static void F_97 ( struct V_14 * V_15 , unsigned int V_1 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_30 * V_31 = V_15 -> V_32 ;
struct V_158 * V_159 = V_15 -> V_300 ;
T_3 V_312 ;
int V_313 ;
int V_95 = 0 ;
void T_4 * V_314 ;
if ( V_1 )
V_314 =
V_31 -> V_35 + V_273 ;
else
V_314 =
V_31 -> V_35 + V_277 ;
for ( V_313 = 0 , V_312 = F_34 ( V_314 ) ;
( V_312 <
V_31 -> V_119 [ V_31 -> V_288 ] ||
V_312 >=
V_31 -> V_119 [ V_31 -> V_288 ] +
V_118 ) && V_313 < F_17 ( V_17 ) ; V_313 ++ ) {
V_95 = F_93 ( V_159 , F_79 ( V_15 ) ) ;
F_94 ( V_159 ,
V_31 -> V_117 [ V_31 -> V_288 ] ,
V_95 ) ;
V_31 -> V_288 = ( V_31 -> V_288 + 1 ) %
F_17 ( V_17 ) ;
}
}
static void F_98 ( struct V_14 * V_15 ,
unsigned short V_163 ,
unsigned int V_315 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_30 * V_31 = V_15 -> V_32 ;
struct V_158 * V_159 = V_15 -> V_300 ;
struct V_280 * V_281 = V_159 -> V_281 ;
struct V_47 * V_48 = & V_281 -> V_48 ;
T_2 V_316 ;
unsigned long V_33 ;
if ( V_163 & V_317 ) {
F_22 ( V_15 -> V_28 , L_12 ) ;
V_281 -> V_318 |= V_319 ;
}
F_25 ( & V_15 -> V_34 , V_33 ) ;
V_316 = F_99 ( V_31 -> V_35 + V_257 ) ;
if ( V_315 & V_320 ) {
F_86 ( ( V_316 & V_254 ) | V_256 ,
V_31 -> V_35 + V_257 ) ;
if ( V_316 & V_254 )
F_97 ( V_15 , 1 ) ;
}
F_27 ( & V_15 -> V_34 , V_33 ) ;
if ( ( V_163 & V_321 ) ||
( ( V_48 -> V_33 & V_49 ) &&
( V_163 & V_322 ) &&
( V_17 -> V_10 != V_11 ) ) ) {
F_25 ( & V_15 -> V_34 , V_33 ) ;
if ( V_31 -> V_298 ) {
F_27 ( & V_15 -> V_34 , V_33 ) ;
F_96 ( V_15 ) ;
} else
F_27 ( & V_15 -> V_34 , V_33 ) ;
}
if ( ( V_48 -> V_242 == V_241 &&
V_281 -> V_323 >= V_48 -> V_247 ) ||
( V_48 -> V_242 == V_237 && ( V_163 & V_324 ) ) )
V_281 -> V_318 |= V_325 ;
F_100 ( V_15 , V_159 ) ;
}
static inline unsigned int F_101 ( struct V_14 * V_15 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
unsigned int V_326 ;
if ( V_31 -> V_327 == 0 )
V_326 = V_121 - 1 ;
else
V_326 = V_31 -> V_327 - 1 ;
return V_326 ;
}
static int F_102 ( struct V_14 * V_15 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
unsigned int V_326 ;
unsigned int V_328 ;
unsigned short V_329 ;
V_326 = F_101 ( V_15 ) ;
V_329 = F_99 ( V_31 -> V_35 + V_258 ) ;
if ( ( V_329 & V_330 ) == 0 )
return 0 ;
V_328 =
F_34 ( V_31 -> V_35 + V_277 ) ;
if ( V_328 != V_31 -> V_123 [ V_326 ] )
return 0 ;
return 1 ;
}
static inline int F_103 ( struct V_14 * V_15 ,
unsigned short V_329 )
{
if ( ( V_329 & V_330 ) == 0 ||
( V_329 & V_254 ) == 0 )
return 0 ;
if ( F_102 ( V_15 ) )
return 0 ;
return 1 ;
}
static void F_104 ( struct V_14 * V_15 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
unsigned int V_331 ;
V_331 =
F_34 ( V_31 -> V_35 + V_279 ) ;
V_331 &= ~ V_332 ;
F_90 ( V_15 , 0 , V_331 ) ;
F_85 ( V_15 , 0 ) ;
}
static unsigned int F_105 ( struct V_14 * V_15 ,
struct V_158 * V_159 ,
unsigned short * V_333 ,
unsigned int V_334 )
{
unsigned int V_308 = F_106 ( V_159 , V_334 ) ;
unsigned int V_335 ;
V_308 = F_93 ( V_159 , V_308 ) ;
V_335 = F_107 ( V_159 , V_333 , V_308 ) ;
return F_106 ( V_159 , V_335 ) ;
}
static unsigned int F_108 ( struct V_14 * V_15 ,
const struct V_47 * V_48 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
struct V_158 * V_159 = V_15 -> V_263 ;
unsigned int V_326 = V_31 -> V_327 ;
unsigned int V_336 = F_101 ( V_15 ) ;
unsigned int V_308 ;
unsigned int V_337 ;
unsigned int V_338 ;
V_308 = F_105 ( V_15 , V_159 ,
V_31 -> V_122 [ V_326 ] ,
V_118 ) ;
if ( V_308 == 0 )
return 0 ;
V_337 = F_109 ( V_159 , V_308 ) ;
V_31 -> V_127 [ V_326 ] . V_134 = F_44 ( V_337 ) ;
V_338 = F_110 ( V_31 -> V_127 [ V_326 ] . V_135 ) ;
V_338 |= V_332 ;
V_31 -> V_127 [ V_326 ] . V_135 = F_44 ( V_338 ) ;
V_338 = F_110 ( V_31 -> V_127 [ V_336 ] . V_135 ) ;
V_338 &= ~ V_332 ;
V_31 -> V_127 [ V_336 ] . V_135 = F_44 ( V_338 ) ;
V_31 -> V_327 = ( V_326 + 1 ) % V_121 ;
return V_337 ;
}
static void F_111 ( struct V_14 * V_15 , const struct V_47 * V_48 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
unsigned int V_339 ;
unsigned int V_312 ;
void T_4 * V_314 =
V_31 -> V_35 + V_277 ;
unsigned int V_326 ;
do {
V_326 = V_31 -> V_327 ;
V_312 = F_34 ( V_314 ) ;
if ( V_312 >=
V_31 -> V_123 [ V_326 ] &&
V_312 <
V_31 -> V_123 [ V_326 ] +
V_118 )
return;
V_339 = F_108 ( V_15 , V_48 ) ;
} while ( V_339 >= V_118 );
}
static void F_112 ( struct V_14 * V_15 ,
unsigned short V_163 , unsigned int V_315 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
struct V_158 * V_159 = V_15 -> V_263 ;
struct V_280 * V_281 ;
struct V_47 * V_48 ;
T_2 V_340 ;
unsigned long V_33 ;
if ( V_159 == NULL )
return;
V_281 = V_159 -> V_281 ;
V_48 = & V_281 -> V_48 ;
F_25 ( & V_15 -> V_34 , V_33 ) ;
V_340 = F_99 ( V_31 -> V_35 + V_258 ) ;
if ( V_315 & V_341 ) {
if ( ( V_340 & V_254 ) &&
! ( V_340 & V_330 ) )
F_86 ( V_254 | V_256 ,
V_31 -> V_35 + V_258 ) ;
else
F_86 ( V_256 ,
V_31 -> V_35 + V_258 ) ;
F_27 ( & V_15 -> V_34 , V_33 ) ;
if ( V_340 & V_254 ) {
F_111 ( V_15 , V_48 ) ;
if ( F_103 ( V_15 , V_340 ) )
F_104 ( V_15 ) ;
}
} else {
F_27 ( & V_15 -> V_34 , V_33 ) ;
}
if ( ( V_163 & V_342 ) ) {
if ( ( V_48 -> V_242 == V_241 &&
V_281 -> V_323 >= V_48 -> V_247 ) ||
F_102 ( V_15 ) )
V_281 -> V_318 |= V_325 ;
else
V_281 -> V_318 |= V_319 ;
}
F_100 ( V_15 , V_159 ) ;
}
static T_5 F_113 ( int V_343 , void * V_344 )
{
struct V_14 * V_15 = V_344 ;
struct V_30 * V_31 = V_15 -> V_32 ;
unsigned short V_163 ;
T_3 V_315 ;
T_3 V_345 ;
V_315 = F_34 ( V_31 -> V_35 + V_37 ) ;
V_163 = F_57 ( V_31 -> V_45 + V_164 ) ;
if ( ! V_15 -> V_346 )
return V_347 ;
F_98 ( V_15 , V_163 , V_315 ) ;
F_112 ( V_15 , V_163 , V_315 ) ;
if ( V_315 & V_348 ) {
V_345 = F_34 ( V_31 -> V_35 + V_349 ) ;
F_29 ( V_345 , V_31 -> V_35 + V_349 ) ;
}
return V_347 ;
}
static int F_114 ( struct V_14 * V_15 , struct V_158 * V_159 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
unsigned long V_33 ;
F_25 ( & V_15 -> V_34 , V_33 ) ;
if ( V_31 -> V_298 == 0 ) {
F_27 ( & V_15 -> V_34 , V_33 ) ;
return 0 ;
}
V_31 -> V_298 = 0 ;
F_27 ( & V_15 -> V_34 , V_33 ) ;
F_36 ( V_15 ) ;
F_24 ( V_15 , 1 ) ;
return 0 ;
}
static int F_115 ( struct V_14 * V_15 , struct V_158 * V_159 ,
struct V_160 * V_161 , unsigned int * V_152 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_30 * V_31 = V_15 -> V_32 ;
int V_231 = F_59 ( V_161 -> V_170 ) ;
int V_25 = F_60 ( V_161 -> V_170 ) ;
F_31 ( 0 , V_31 -> V_45 + V_350 ) ;
F_21 ( V_15 , & V_31 -> V_110 , V_231 , V_25 ) ;
F_31 ( V_31 -> V_110 ,
V_31 -> V_45 + V_351 ) ;
if ( V_17 -> V_10 == V_11 ) {
F_31 ( V_152 [ 0 ] & 0xff ,
V_31 -> V_45 + F_2 ( V_231 ) ) ;
F_31 ( ( V_152 [ 0 ] >> 8 ) & 0xf ,
V_31 -> V_45 + F_3 ( V_231 ) ) ;
} else {
F_31 ( V_152 [ 0 ] , V_31 -> V_45 + F_1 ( V_231 ) ) ;
}
V_159 -> V_352 [ V_231 ] = V_152 [ 0 ] ;
return 1 ;
}
static void F_116 ( struct V_14 * V_15 ,
const struct V_47 * V_48 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
unsigned int V_24 = V_353 | V_354 |
V_355 | V_356 ;
if ( V_48 -> V_236 == V_237 ) {
V_24 |= V_357 ;
if ( V_48 -> V_244 & V_294 )
V_24 |= V_358 ;
} else {
V_24 |= V_359 ;
}
if ( V_48 -> V_225 == V_237 ) {
V_24 |= V_360 ;
if ( V_48 -> V_226 & V_294 )
V_24 |= V_361 ;
}
F_31 ( V_24 , V_31 -> V_45 + V_350 ) ;
}
static void F_117 ( struct V_14 * V_15 ,
const struct V_47 * V_48 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
int V_116 ;
for ( V_116 = 0 ; V_116 < V_48 -> V_227 ; V_116 ++ ) {
int V_1 , V_25 ;
V_1 = F_59 ( V_48 -> V_229 [ V_116 ] ) ;
V_25 = F_60 ( V_48 -> V_229 [ V_116 ] ) ;
F_21 ( V_15 , & V_31 -> V_110 , V_1 ,
V_25 ) ;
}
V_31 -> V_110 |= V_362 ;
F_31 ( V_31 -> V_110 ,
V_31 -> V_45 + V_351 ) ;
}
static void F_118 ( struct V_14 * V_15 ,
const struct V_47 * V_48 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
T_1 V_24 ;
unsigned int V_363 , V_364 ;
V_363 = F_59 ( V_48 -> V_229 [ 0 ] ) ;
V_364 = F_59 ( V_48 -> V_229 [ V_48 -> V_227 - 1 ] ) ;
if ( V_364 < V_363 )
F_22 ( V_15 -> V_28 ,
L_13 ) ;
V_24 = ( V_363 & 0x7 ) | ( V_364 & 0x7 ) << 3 ;
F_31 ( V_24 , V_31 -> V_45 + V_365 ) ;
}
static unsigned int F_119 ( unsigned int V_207 , unsigned int V_33 )
{
return F_69 ( V_207 , V_33 ) - 2 ;
}
static void F_120 ( struct V_14 * V_15 ,
const struct V_47 * V_48 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
unsigned int V_199 ;
if ( V_48 -> V_225 != V_222 )
return;
V_199 = F_119 ( V_48 -> V_226 , V_48 -> V_33 ) ;
if ( V_199 > V_217 ) {
F_22 ( V_15 -> V_28 , L_14 ) ;
V_199 = V_217 ;
}
F_31 ( V_199 & 0xffff ,
V_31 -> V_45 + V_366 ) ;
F_31 ( ( V_199 >> 16 ) & 0xff ,
V_31 -> V_45 + V_367 ) ;
}
static int F_121 ( struct V_14 * V_15 , const struct V_47 * V_48 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
struct V_158 * V_159 = V_15 -> V_263 ;
unsigned int V_308 ;
unsigned int V_337 ;
int V_116 ;
F_31 ( 0 , V_31 -> V_45 + V_266 ) ;
F_31 ( 0 , V_31 -> V_45 + V_265 ) ;
V_308 = F_105 ( V_15 , V_159 ,
V_31 -> V_368 ,
V_369 ) ;
if ( V_308 == 0 )
return - 1 ;
for ( V_116 = 0 ; V_116 < V_308 ; V_116 ++ ) {
F_31 ( V_31 -> V_368 [ V_116 ] ,
V_31 -> V_45 + V_139 ) ;
}
if ( V_48 -> V_242 == V_241 &&
V_159 -> V_281 -> V_323 >= V_48 -> V_247 )
return 0 ;
V_337 = F_108 ( V_15 , V_48 ) ;
if ( V_337 == 0 )
return - 1 ;
F_111 ( V_15 , V_48 ) ;
F_85 ( V_15 , 0 ) ;
return 0 ;
}
static inline int F_122 ( struct V_14 * V_15 ,
struct V_158 * V_159 ,
struct V_47 * V_48 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
if ( V_159 -> V_264 )
return 0 ;
if ( V_17 -> V_10 == V_11 )
return 0 ;
else if ( F_88 ( V_48 ) )
return 0 ;
return 1 ;
}
static int F_123 ( struct V_14 * V_15 , struct V_158 * V_159 ,
unsigned int V_370 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
struct V_47 * V_48 = & V_159 -> V_281 -> V_48 ;
int V_97 ;
if ( V_370 != V_48 -> V_244 )
return - V_194 ;
V_97 = F_121 ( V_15 , V_48 ) ;
if ( V_97 < 0 )
return - V_371 ;
F_116 ( V_15 , V_48 ) ;
if ( V_48 -> V_236 == V_372 )
F_31 ( 0 , V_31 -> V_45 + V_373 ) ;
V_159 -> V_281 -> V_374 = NULL ;
return 0 ;
}
static int F_124 ( struct V_14 * V_15 , struct V_158 * V_159 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
struct V_47 * V_48 = & V_159 -> V_281 -> V_48 ;
if ( F_122 ( V_15 , V_159 , V_48 ) ) {
F_47 ( V_15 ) ;
return - V_166 ;
}
F_31 ( 0x0 , V_31 -> V_45 + V_350 ) ;
V_31 -> V_327 = 0 ;
F_118 ( V_15 , V_48 ) ;
F_120 ( V_15 , V_48 ) ;
F_90 ( V_15 , 0 , V_31 -> V_128 |
V_136 | V_137 ) ;
F_117 ( V_15 , V_48 ) ;
V_159 -> V_281 -> V_374 = F_123 ;
return 0 ;
}
static int F_125 ( struct V_14 * V_15 ,
struct V_158 * V_159 ,
struct V_47 * V_48 )
{
unsigned int V_230 = F_59 ( V_48 -> V_229 [ 0 ] ) ;
int V_116 ;
for ( V_116 = 1 ; V_116 < V_48 -> V_227 ; V_116 ++ ) {
unsigned int V_231 = F_59 ( V_48 -> V_229 [ V_116 ] ) ;
if ( V_231 != ( V_230 + V_116 ) ) {
F_64 ( V_15 -> V_28 ,
L_8 ) ;
return - V_194 ;
}
}
return 0 ;
}
static int F_126 ( struct V_14 * V_15 , struct V_158 * V_159 ,
struct V_47 * V_48 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
int V_232 = 0 ;
unsigned int V_233 ;
V_232 |= F_73 ( & V_48 -> V_236 , V_372 | V_237 ) ;
V_232 |= F_73 ( & V_48 -> V_225 ,
V_222 | V_237 ) ;
V_232 |= F_73 ( & V_48 -> V_221 , V_224 ) ;
V_232 |= F_73 ( & V_48 -> V_240 , V_241 ) ;
V_232 |= F_73 ( & V_48 -> V_242 , V_243 ) ;
if ( V_232 )
return 1 ;
V_232 |= F_74 ( V_48 -> V_236 ) ;
V_232 |= F_74 ( V_48 -> V_225 ) ;
if ( V_48 -> V_221 == V_237 && V_48 -> V_225 == V_222 )
V_232 |= - V_194 ;
if ( V_48 -> V_242 != V_241 &&
V_48 -> V_242 != V_243 && V_48 -> V_242 != V_237 )
V_232 |= - V_194 ;
if ( V_232 )
return 2 ;
V_232 |= F_75 ( & V_48 -> V_244 , 0 ) ;
if ( V_48 -> V_225 == V_222 ) {
V_232 |= F_76 ( & V_48 -> V_226 ,
V_17 -> V_375 ) ;
if ( F_119 ( V_48 -> V_226 , V_48 -> V_33 ) >
V_217 ) {
V_48 -> V_226 = ( V_217 + 2 ) *
V_210 ;
V_232 |= - V_194 ;
}
}
V_232 |= F_76 ( & V_48 -> V_227 , 1 ) ;
V_232 |= F_75 ( & V_48 -> V_246 , V_48 -> V_227 ) ;
if ( V_232 )
return 3 ;
if ( V_48 -> V_225 == V_222 ) {
V_233 = V_48 -> V_226 ;
V_48 -> V_226 = F_69 ( V_48 -> V_226 ,
V_48 -> V_33 ) * V_210 ;
if ( V_233 != V_48 -> V_226 )
V_232 ++ ;
}
if ( V_232 )
return 4 ;
if ( V_48 -> V_229 && V_48 -> V_227 > 0 )
V_232 |= F_125 ( V_15 , V_159 , V_48 ) ;
if ( V_232 )
return 5 ;
return 0 ;
}
static int F_127 ( struct V_14 * V_15 , struct V_158 * V_159 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
F_31 ( 0x0 , V_31 -> V_45 + V_350 ) ;
F_24 ( V_15 , 0 ) ;
return 0 ;
}
static int F_128 ( struct V_14 * V_15 ,
int V_376 , int V_377 , int V_152 , unsigned long V_378 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
if ( V_376 ) {
F_31 ( V_152 , V_31 -> V_45 + V_378 + 2 * V_377 ) ;
return 0 ;
}
return F_57 ( V_31 -> V_45 + V_378 + 2 * V_377 ) ;
}
static int F_129 ( struct V_14 * V_15 , struct V_158 * V_159 ,
struct V_160 * V_161 , unsigned int * V_152 )
{
unsigned int V_24 ;
V_24 = F_99 ( V_15 -> V_191 + V_379 ) ;
V_24 &= 0xf ;
V_152 [ 1 ] = V_24 ;
V_152 [ 0 ] = 0 ;
return V_161 -> V_167 ;
}
static int F_130 ( struct V_14 * V_15 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
unsigned int * V_152 )
{
if ( F_131 ( V_159 , V_152 ) )
F_86 ( V_159 -> V_140 , V_15 -> V_191 + V_380 ) ;
V_152 [ 1 ] = V_159 -> V_140 ;
return V_161 -> V_167 ;
}
static int F_132 ( struct V_14 * V_15 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
unsigned int * V_152 )
{
int V_169 ;
V_169 = F_133 ( V_15 , V_159 , V_161 , V_152 , 0 ) ;
if ( V_169 )
return V_169 ;
F_86 ( V_159 -> V_381 , V_15 -> V_191 + V_382 ) ;
return V_161 -> V_167 ;
}
static int F_134 ( struct V_14 * V_15 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
unsigned int * V_152 )
{
if ( F_131 ( V_159 , V_152 ) )
F_86 ( V_159 -> V_140 , V_15 -> V_191 + V_383 ) ;
V_152 [ 1 ] = F_99 ( V_15 -> V_191 + V_383 ) ;
return V_161 -> V_167 ;
}
static int F_135 ( struct V_14 * V_15 , unsigned int V_151 ,
T_2 V_384 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
static const int V_385 = 8 ;
static const int V_386 = 11 ;
unsigned int V_154 = ( ( V_151 & 0x7 ) << 8 ) | V_384 ;
unsigned int V_149 , V_387 ;
static const int V_388 = 1 ;
if ( V_151 >= V_385 ) {
F_22 ( V_15 -> V_28 , L_15 ) ;
return - 1 ;
}
for ( V_149 = 1 << ( V_386 - 1 ) ; V_149 ; V_149 >>= 1 ) {
V_387 = 0 ;
if ( V_154 & V_149 )
V_387 |= V_389 ;
F_49 ( V_388 ) ;
F_31 ( V_387 , V_31 -> V_45 + V_108 ) ;
V_387 |= V_390 ;
F_49 ( V_388 ) ;
F_31 ( V_387 , V_31 -> V_45 + V_108 ) ;
}
F_49 ( V_388 ) ;
F_31 ( V_391 , V_31 -> V_45 + V_108 ) ;
F_49 ( V_388 ) ;
F_31 ( 0 , V_31 -> V_45 + V_108 ) ;
F_49 ( V_388 ) ;
return 0 ;
}
static int F_136 ( struct V_14 * V_15 ,
unsigned int V_392 , unsigned int V_384 )
{
T_2 V_393 [ 3 ] ;
T_2 V_394 ;
enum T_6 {
V_395 = 0x1 ,
V_396 = 0x2 ,
V_397 = 0x4 ,
V_398 = 0x8 ,
};
enum T_7 {
V_399 = 0x20 ,
};
switch ( V_392 ) {
case 0 :
V_394 = V_400 ;
V_393 [ 0 ] = V_395 ;
break;
case 1 :
V_394 = V_400 ;
V_393 [ 0 ] = V_397 ;
break;
case 2 :
V_394 = V_401 ;
V_393 [ 0 ] = V_395 ;
break;
case 3 :
V_394 = V_401 ;
V_393 [ 0 ] = V_397 ;
break;
case 4 :
V_394 = V_400 ;
V_393 [ 0 ] = V_396 ;
break;
case 5 :
V_394 = V_400 ;
V_393 [ 0 ] = V_398 ;
break;
case 6 :
V_394 = V_401 ;
V_393 [ 0 ] = V_396 ;
break;
case 7 :
V_394 = V_401 ;
V_393 [ 0 ] = V_398 ;
break;
default:
F_22 ( V_15 -> V_28 , L_16 ) ;
return - 1 ;
}
V_393 [ 1 ] = V_399 | ( ( V_384 >> 8 ) & 0xf ) ;
V_393 [ 2 ] = V_384 & 0xff ;
F_55 ( V_15 , V_394 , V_393 , 3 ) ;
return 0 ;
}
static void F_137 ( struct V_14 * V_15 , unsigned int V_1 ,
unsigned int V_384 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
switch ( V_17 -> V_10 ) {
case V_20 :
case V_19 :
F_135 ( V_15 , V_1 , V_384 ) ;
break;
case V_11 :
F_136 ( V_15 , V_1 , V_384 ) ;
break;
default:
break;
}
}
static int F_138 ( struct V_14 * V_15 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
unsigned int * V_152 )
{
unsigned int V_231 = F_59 ( V_161 -> V_170 ) ;
if ( V_161 -> V_167 ) {
unsigned int V_307 = V_152 [ V_161 -> V_167 - 1 ] ;
if ( V_159 -> V_352 [ V_231 ] != V_307 ) {
F_137 ( V_15 , V_231 , V_307 ) ;
V_159 -> V_352 [ V_231 ] = V_307 ;
}
}
return V_161 -> V_167 ;
}
static void F_139 ( struct V_14 * V_15 , unsigned int V_1 ,
unsigned int V_384 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
static const int V_386 = 10 ;
unsigned int V_149 , V_387 ;
unsigned int V_154 = ( ( V_1 & 0x3 ) << 8 ) | ( V_384 & 0xff ) ;
static const int V_402 = 1 ;
V_387 = V_403 ;
F_49 ( V_402 ) ;
F_31 ( V_387 , V_31 -> V_45 + V_108 ) ;
for ( V_149 = 1 << ( V_386 - 1 ) ; V_149 ; V_149 >>= 1 ) {
if ( V_154 & V_149 )
V_387 |= V_389 ;
else
V_387 &= ~ V_389 ;
F_49 ( V_402 ) ;
F_31 ( V_387 , V_31 -> V_45 + V_108 ) ;
F_49 ( V_402 ) ;
F_31 ( V_387 | V_390 ,
V_31 -> V_45 + V_108 ) ;
}
F_49 ( V_402 ) ;
F_31 ( 0 , V_31 -> V_45 + V_108 ) ;
}
static int F_140 ( struct V_14 * V_15 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
unsigned int * V_152 )
{
unsigned int V_231 = F_59 ( V_161 -> V_170 ) ;
if ( V_161 -> V_167 ) {
unsigned int V_307 = V_152 [ V_161 -> V_167 - 1 ] ;
if ( V_159 -> V_352 [ V_231 ] != V_307 ) {
F_139 ( V_15 , V_231 , V_307 ) ;
V_159 -> V_352 [ V_231 ] = V_307 ;
}
}
return V_161 -> V_167 ;
}
static T_1 F_141 ( struct V_14 * V_15 , T_2 V_151 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
static const int V_386 = 11 ;
static const int V_404 = 0x6 ;
unsigned int V_154 = ( V_404 << 8 ) | V_151 ;
unsigned int V_149 ;
void T_4 * const V_143 =
V_31 -> V_35 + V_53 ;
T_1 V_384 ;
static const int V_405 = 16 ;
static const int V_406 = 1 ;
F_49 ( V_406 ) ;
V_31 -> V_52 &= ~ V_407 & ~ V_156 ;
V_31 -> V_52 |= V_147 ;
F_29 ( V_31 -> V_52 , V_143 ) ;
F_49 ( V_406 ) ;
V_31 -> V_52 |= V_156 ;
F_29 ( V_31 -> V_52 , V_143 ) ;
for ( V_149 = 1 << ( V_386 - 1 ) ; V_149 ; V_149 >>= 1 ) {
F_49 ( V_406 ) ;
if ( V_154 & V_149 )
V_31 -> V_52 |= V_142 ;
else
V_31 -> V_52 &= ~ V_142 ;
F_29 ( V_31 -> V_52 , V_143 ) ;
F_49 ( V_406 ) ;
V_31 -> V_52 |= V_407 ;
F_29 ( V_31 -> V_52 , V_143 ) ;
F_49 ( V_406 ) ;
V_31 -> V_52 &= ~ V_407 ;
F_29 ( V_31 -> V_52 , V_143 ) ;
}
V_384 = 0 ;
for ( V_149 = 1 << ( V_405 - 1 ) ; V_149 ; V_149 >>= 1 ) {
F_49 ( V_406 ) ;
V_31 -> V_52 |= V_407 ;
F_29 ( V_31 -> V_52 , V_143 ) ;
F_49 ( V_406 ) ;
V_31 -> V_52 &= ~ V_407 ;
F_29 ( V_31 -> V_52 , V_143 ) ;
F_49 ( V_406 ) ;
if ( F_34 ( V_143 ) & V_408 )
V_384 |= V_149 ;
}
F_49 ( V_406 ) ;
V_31 -> V_52 &= ~ V_156 ;
F_29 ( V_31 -> V_52 , V_143 ) ;
return V_384 ;
}
static int F_142 ( struct V_14 * V_15 ,
struct V_158 * V_159 ,
struct V_160 * V_161 , unsigned int * V_152 )
{
V_152 [ 0 ] = F_141 ( V_15 , F_59 ( V_161 -> V_170 ) ) ;
return 1 ;
}
static int F_143 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_30 * V_31 = V_15 -> V_32 ;
struct V_158 * V_159 ;
int V_116 ;
int V_169 ;
V_169 = F_144 ( V_15 , 10 ) ;
if ( V_169 )
return V_169 ;
V_159 = & V_15 -> V_409 [ 0 ] ;
V_15 -> V_300 = V_159 ;
V_159 -> type = V_410 ;
V_159 -> V_411 = V_412 | V_413 | V_414 | V_415 ;
if ( V_17 -> V_10 == V_20 )
V_159 -> V_411 |= V_416 | V_417 ;
else if ( V_17 -> V_10 == V_19 )
V_159 -> V_411 |= V_417 ;
V_159 -> V_418 = V_17 -> V_419 ;
V_159 -> V_420 = 0x2000 ;
V_159 -> V_421 = ( 1 << V_17 -> V_422 ) - 1 ;
V_159 -> V_423 = V_17 -> V_424 ;
V_159 -> V_425 = F_58 ;
V_159 -> V_426 = F_68 ;
V_159 -> V_427 = F_91 ;
V_159 -> V_428 = F_72 ;
V_159 -> V_429 = F_114 ;
if ( V_17 -> V_10 == V_11 ) {
T_2 V_152 ;
V_31 -> V_185 = F_15 ( 4 ) ;
for ( V_116 = 0 ; V_116 < V_159 -> V_418 ; V_116 ++ )
V_31 -> V_185 |= F_16 ( V_116 ) ;
V_152 = V_31 -> V_185 ;
F_55 ( V_15 , V_187 , & V_152 , sizeof( V_152 ) ) ;
}
V_159 = & V_15 -> V_409 [ 1 ] ;
if ( V_17 -> V_29 ) {
V_159 -> type = V_430 ;
V_159 -> V_411 = V_412 | V_431 |
V_413 | V_432 ;
V_159 -> V_418 = V_17 -> V_29 ;
V_159 -> V_421 = ( 1 << V_17 -> V_433 ) - 1 ;
V_159 -> V_423 = V_17 -> V_434 ;
V_159 -> V_435 = F_115 ;
V_169 = F_145 ( V_159 ) ;
if ( V_169 )
return V_169 ;
if ( F_23 ( V_17 ) ) {
V_15 -> V_263 = V_159 ;
V_159 -> V_428 = F_126 ;
V_159 -> V_427 = F_124 ;
V_159 -> V_420 = V_17 -> V_29 ;
V_159 -> V_429 = F_127 ;
}
} else {
V_159 -> type = V_436 ;
}
V_159 = & V_15 -> V_409 [ 2 ] ;
if ( V_17 -> V_10 == V_19 ) {
V_159 -> type = V_437 ;
V_159 -> V_411 = V_412 ;
V_159 -> V_418 = 4 ;
V_159 -> V_421 = 1 ;
V_159 -> V_423 = & V_438 ;
V_159 -> V_439 = F_129 ;
} else
V_159 -> type = V_436 ;
if ( V_17 -> V_10 == V_19 ) {
V_159 = & V_15 -> V_409 [ 3 ] ;
V_159 -> type = V_440 ;
V_159 -> V_411 = V_431 ;
V_159 -> V_418 = 4 ;
V_159 -> V_421 = 1 ;
V_159 -> V_423 = & V_438 ;
V_159 -> V_439 = F_130 ;
} else
V_159 -> type = V_436 ;
V_159 = & V_15 -> V_409 [ 4 ] ;
if ( V_17 -> V_441 ) {
if ( V_17 -> V_10 == V_11 ) {
V_169 = F_146 ( V_15 , V_159 , F_128 ,
V_442 ) ;
} else {
V_169 = F_147 ( V_15 , V_159 , NULL ,
V_443 ) ;
}
if ( V_169 )
return V_169 ;
} else {
V_159 -> type = V_436 ;
}
V_159 = & V_15 -> V_409 [ 5 ] ;
if ( V_17 -> V_10 == V_20 ) {
V_159 -> type = V_444 ;
V_159 -> V_411 = V_431 | V_412 ;
V_159 -> V_418 = 8 ;
V_159 -> V_421 = 1 ;
V_159 -> V_423 = & V_438 ;
V_159 -> V_426 = F_132 ;
V_159 -> V_439 = F_134 ;
} else
V_159 -> type = V_436 ;
V_159 = & V_15 -> V_409 [ 6 ] ;
V_159 -> type = V_445 ;
V_159 -> V_411 = V_412 | V_431 | V_446 ;
V_159 -> V_418 = 8 ;
if ( V_17 -> V_10 == V_11 )
V_159 -> V_421 = 0xfff ;
else
V_159 -> V_421 = 0xff ;
V_159 -> V_435 = F_138 ;
V_169 = F_145 ( V_159 ) ;
if ( V_169 )
return V_169 ;
for ( V_116 = 0 ; V_116 < V_159 -> V_418 ; V_116 ++ ) {
F_137 ( V_15 , V_116 , V_159 -> V_421 / 2 ) ;
V_159 -> V_352 [ V_116 ] = V_159 -> V_421 / 2 ;
}
V_159 = & V_15 -> V_409 [ 7 ] ;
if ( V_17 -> V_10 == V_19 ) {
V_159 -> type = V_445 ;
V_159 -> V_411 = V_412 | V_431 | V_446 ;
V_159 -> V_418 = 2 ;
V_159 -> V_421 = 0xff ;
V_159 -> V_435 = F_140 ;
V_169 = F_145 ( V_159 ) ;
if ( V_169 )
return V_169 ;
for ( V_116 = 0 ; V_116 < V_159 -> V_418 ; V_116 ++ ) {
F_139 ( V_15 , V_116 , V_159 -> V_421 / 2 ) ;
V_159 -> V_352 [ V_116 ] = V_159 -> V_421 / 2 ;
}
} else
V_159 -> type = V_436 ;
V_159 = & V_15 -> V_409 [ 8 ] ;
if ( F_34 ( V_31 -> V_35 + V_53 ) & V_447 ) {
V_159 -> type = V_448 ;
V_159 -> V_411 = V_412 | V_446 ;
V_159 -> V_418 = 128 ;
V_159 -> V_421 = 0xffff ;
V_159 -> V_425 = F_142 ;
} else
V_159 -> type = V_436 ;
V_159 = & V_15 -> V_409 [ 9 ] ;
V_159 -> type = V_436 ;
return 0 ;
}
static int F_148 ( struct V_14 * V_15 ,
unsigned long V_162 )
{
struct V_114 * V_115 = F_42 ( V_15 ) ;
const struct V_8 * V_17 = NULL ;
struct V_30 * V_31 ;
T_3 V_449 , V_450 ;
int V_97 ;
if ( V_162 < F_149 ( V_451 ) )
V_17 = & V_451 [ V_162 ] ;
if ( ! V_17 )
return - V_452 ;
V_15 -> V_18 = V_17 ;
V_31 = F_150 ( V_15 , sizeof( * V_31 ) ) ;
if ( ! V_31 )
return - V_120 ;
V_97 = F_151 ( V_15 ) ;
if ( V_97 )
return V_97 ;
F_152 ( V_115 ) ;
V_15 -> V_453 = V_17 -> V_454 ;
V_31 -> V_455 = F_153 ( V_115 , 2 ) ;
V_31 -> V_456 = F_153 ( V_115 , 3 ) ;
V_31 -> V_35 = F_154 ( V_115 , 0 ) ;
V_31 -> V_45 = F_154 ( V_115 , 2 ) ;
V_15 -> V_191 = F_154 ( V_115 , 3 ) ;
if ( ! V_31 -> V_35 || ! V_31 -> V_45 || ! V_15 -> V_191 ) {
F_155 ( V_15 -> V_28 , L_17 ) ;
return - V_120 ;
}
V_449 = F_34 ( V_31 -> V_35 + V_457 ) &
V_458 ;
V_450 = F_34 ( V_31 -> V_35 + V_459 ) &
V_449 & V_460 ;
V_31 -> V_133 = ( ( T_3 ) V_31 -> V_455 &
~ V_449 ) | V_450 ;
V_449 = F_34 ( V_31 -> V_35 + V_461 ) &
V_458 ;
V_450 = F_34 ( V_31 -> V_35 + V_462 ) &
V_449 & V_460 ;
V_31 -> V_131 = ( ( T_3 ) V_31 -> V_456 &
~ V_449 ) | V_450 ;
V_97 = F_41 ( V_15 ) ;
if ( V_97 < 0 )
return V_97 ;
V_31 -> F_20 =
F_20 ( V_15 , F_57 ( V_31 -> V_45 + V_164 ) ) ;
F_64 ( V_15 -> V_28 , L_18 ,
V_31 -> F_20 ) ;
F_33 ( V_15 ) ;
F_40 ( V_15 ) ;
V_97 = F_156 ( V_115 -> V_343 , F_113 , V_463 ,
V_15 -> V_453 , V_15 ) ;
if ( V_97 ) {
F_64 ( V_15 -> V_28 , L_19 ,
V_115 -> V_343 ) ;
return V_97 ;
}
V_15 -> V_343 = V_115 -> V_343 ;
F_64 ( V_15 -> V_28 , L_20 , V_15 -> V_343 ) ;
V_97 = F_143 ( V_15 ) ;
if ( V_97 < 0 )
return V_97 ;
return 0 ;
}
static void F_157 ( struct V_14 * V_15 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
if ( V_15 -> V_343 )
F_158 ( V_15 -> V_343 , V_15 ) ;
if ( V_31 ) {
if ( V_31 -> V_35 ) {
F_28 ( V_15 ) ;
F_159 ( V_31 -> V_35 ) ;
}
if ( V_31 -> V_45 )
F_159 ( V_31 -> V_45 ) ;
if ( V_15 -> V_191 )
F_159 ( V_15 -> V_191 ) ;
}
F_160 ( V_15 ) ;
F_45 ( V_15 ) ;
}
static int F_161 ( struct V_114 * V_15 ,
const struct V_464 * V_203 )
{
return F_162 ( V_15 , & V_465 ,
V_203 -> V_466 ) ;
}
