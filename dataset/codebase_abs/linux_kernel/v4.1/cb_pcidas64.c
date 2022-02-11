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
if ( ! V_31 -> V_117 [ V_116 ] )
return - V_120 ;
}
for ( V_116 = 0 ; V_116 < V_121 ; V_116 ++ ) {
if ( F_23 ( V_17 ) ) {
V_31 -> V_122 [ V_116 ] =
F_43 ( V_115 , V_118 ,
& V_31 ->
V_123 [ V_116 ] ) ;
if ( ! V_31 -> V_122 [ V_116 ] )
return - V_120 ;
}
}
V_31 -> V_124 =
F_43 ( V_115 , sizeof( struct V_125 ) *
F_17 ( V_17 ) ,
& V_31 -> V_126 ) ;
if ( ! V_31 -> V_124 )
return - V_120 ;
if ( F_23 ( V_17 ) ) {
V_31 -> V_127 =
F_43 ( V_115 ,
sizeof( struct V_125 ) *
V_121 ,
& V_31 -> V_128 ) ;
if ( ! V_31 -> V_127 )
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
F_22 ( V_15 -> V_28 , L_5 ) ;
F_54 ( V_15 ) ;
return;
}
for ( V_116 = 0 ; V_116 < V_153 ; V_116 ++ ) {
F_51 ( V_15 , V_152 [ V_116 ] ) ;
if ( F_52 ( V_15 ) != 0 ) {
F_22 ( V_15 -> V_28 , L_5 ) ;
F_54 ( V_15 ) ;
return;
}
}
F_54 ( V_15 ) ;
}
static int F_56 ( struct V_14 * V_15 ,
struct V_157 * V_158 ,
struct V_159 * V_160 ,
unsigned long V_161 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_30 * V_31 = V_15 -> V_32 ;
unsigned int V_162 ;
V_162 = F_57 ( V_31 -> V_45 + V_163 ) ;
if ( V_17 -> V_10 == V_11 ) {
V_162 = F_57 ( V_31 -> V_45 + V_164 ) ;
if ( V_162 )
return 0 ;
} else {
if ( F_11 ( V_162 ) )
return 0 ;
}
return - V_165 ;
}
static int F_58 ( struct V_14 * V_15 , struct V_157 * V_158 ,
struct V_159 * V_160 , unsigned int * V_152 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_30 * V_31 = V_15 -> V_32 ;
unsigned int V_24 = 0 , V_166 ;
unsigned int V_1 , V_25 , V_167 ;
unsigned long V_33 ;
int V_168 ;
V_1 = F_59 ( V_160 -> V_169 ) ;
V_25 = F_60 ( V_160 -> V_169 ) ;
V_167 = F_61 ( V_160 -> V_169 ) ;
F_36 ( V_15 ) ;
F_25 ( & V_15 -> V_34 , V_33 ) ;
if ( V_160 -> V_169 & V_170 )
V_31 -> V_77 |= V_171 ;
else
V_31 -> V_77 &= ~ V_171 ;
F_31 ( V_31 -> V_77 ,
V_31 -> V_45 + V_79 ) ;
F_27 ( & V_15 -> V_34 , V_33 ) ;
if ( V_17 -> V_10 != V_11 ) {
V_31 -> V_105 &= ~ V_172 ;
F_31 ( V_31 -> V_105 ,
V_31 -> V_45 + V_106 ) ;
if ( V_160 -> V_169 & V_173 ) {
unsigned int V_174 ;
if ( V_17 -> V_10 == V_20 )
V_174 = V_175 ;
else
V_174 = V_176 ;
F_31 ( V_174 |
F_8 ( V_31 -> V_177 ) ,
V_31 -> V_45 + V_108 ) ;
} else {
F_31 ( 0 , V_31 -> V_45 + V_108 ) ;
}
V_24 = 0 ;
V_24 |= F_19 ( V_15 , F_60 ( V_160 -> V_169 ) ) ;
V_24 |= F_18 ( V_15 , V_167 == V_178 ) ;
if ( V_167 == V_179 )
V_24 |= V_180 ;
V_24 |= F_10 ( V_1 ) ;
F_31 ( F_10 ( V_1 ) ,
V_31 -> V_45 + V_181 ) ;
F_31 ( V_24 , V_31 -> V_45 + V_182 ) ;
} else {
T_2 V_183 = V_31 -> V_184 ;
V_31 -> V_184 &= ~ V_7 ;
if ( V_160 -> V_169 & V_173 ) {
V_31 -> V_184 |=
F_15 ( V_31 -> V_177 ) ;
} else {
V_31 -> V_184 |= F_15 ( 4 ) ;
}
if ( V_25 == 0 )
V_31 -> V_184 |= F_16 ( V_1 ) ;
else
V_31 -> V_184 &= ~ F_16 ( V_1 ) ;
if ( V_183 != V_31 -> V_184 ) {
T_2 V_185 = V_31 -> V_184 ;
F_55 ( V_15 , V_186 , & V_185 ,
sizeof( V_185 ) ) ;
}
F_31 ( 0 , V_31 -> V_45 + V_101 ) ;
F_31 ( 2 , V_31 -> V_45 + V_187 ) ;
}
for ( V_166 = 0 ; V_166 < V_160 -> V_166 ; V_166 ++ ) {
F_31 ( 0 , V_31 -> V_45 + V_188 ) ;
F_31 ( F_9 ( F_59 ( V_160 -> V_169 ) ) ,
V_31 -> V_45 + V_189 ) ;
V_168 = F_62 ( V_15 , V_158 , V_160 , F_56 , 0 ) ;
if ( V_168 )
return V_168 ;
if ( V_17 -> V_10 == V_11 )
V_152 [ V_166 ] = F_34 ( V_15 -> V_190 + V_132 ) & 0xffff ;
else
V_152 [ V_166 ] = F_57 ( V_31 -> V_45 + V_191 ) ;
}
return V_166 ;
}
static int F_63 ( struct V_14 * V_15 ,
unsigned int * V_152 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_30 * V_31 = V_15 -> V_32 ;
unsigned int V_4 = V_152 [ 1 ] ;
int V_192 ;
if ( V_17 -> V_10 == V_20 )
V_192 = 16 ;
else
V_192 = 8 ;
if ( V_4 >= V_192 ) {
F_64 ( V_15 -> V_28 , L_6 ,
V_4 ) ;
return - V_193 ;
}
V_31 -> V_177 = V_4 ;
return 2 ;
}
static int F_65 ( struct V_14 * V_15 , unsigned int * V_152 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
int V_194 ;
const struct V_86 * const V_87 = V_17 -> V_88 ;
unsigned int V_195 , V_196 ;
int V_97 ;
V_196 = V_152 [ 1 ] ;
if ( V_196 ) {
V_194 = V_196 * V_87 -> V_99 /
V_197 ;
V_97 = F_38 ( V_15 , V_194 ) ;
if ( V_97 < 0 )
return V_97 ;
}
V_195 = F_39 ( V_15 ) / V_87 -> V_99 * V_197 ;
V_152 [ 1 ] = V_195 ;
return 2 ;
}
static int F_66 ( struct V_14 * V_15 ,
unsigned int * V_152 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
unsigned int V_198 = V_152 [ 4 ] ;
int V_97 = 0 ;
if ( V_198 < 2 ) {
V_198 = 2 ;
V_97 = - V_199 ;
}
switch ( V_152 [ 1 ] ) {
case V_200 :
V_31 -> V_201 . V_198 = V_198 ;
V_31 -> V_201 . V_169 = V_152 [ 2 ] ;
break;
default:
return - V_193 ;
}
V_152 [ 4 ] = V_198 ;
return V_97 ? V_97 : 5 ;
}
static int F_67 ( struct V_14 * V_15 , unsigned int * V_152 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
switch ( V_17 -> V_10 ) {
case V_11 :
return F_66 ( V_15 , V_152 ) ;
default:
return - V_193 ;
}
return - V_193 ;
}
static int F_68 ( struct V_14 * V_15 , struct V_157 * V_158 ,
struct V_159 * V_160 , unsigned int * V_152 )
{
int V_202 = V_152 [ 0 ] ;
switch ( V_202 ) {
case V_203 :
return F_63 ( V_15 , V_152 ) ;
case V_204 :
return F_65 ( V_15 , V_152 ) ;
case V_205 :
return F_67 ( V_15 , V_152 ) ;
default:
return - V_193 ;
}
return - V_193 ;
}
static unsigned int F_69 ( unsigned int V_206 , unsigned int V_33 )
{
unsigned int V_198 ;
switch ( V_33 & V_207 ) {
case V_208 :
V_198 = ( V_206 + V_209 - 1 ) / V_209 ;
break;
case V_210 :
V_198 = V_206 / V_209 ;
break;
case V_211 :
default:
V_198 = ( V_206 + V_209 / 2 ) / V_209 ;
break;
}
return V_198 ;
}
static void F_70 ( struct V_14 * V_15 , struct V_47 * V_48 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
unsigned long long V_212 = 0 ;
unsigned int V_213 ;
static const int V_214 = 3 ;
static const int V_215 =
V_216 + V_214 ;
static const int V_217 = 2 ;
unsigned long long V_218 , V_219 ;
if ( V_48 -> V_220 == V_221 ) {
if ( V_17 -> V_10 == V_11 ) {
V_48 -> V_222 = 0 ;
} else {
V_212 = F_69 ( V_48 -> V_222 ,
V_48 -> V_33 ) ;
if ( V_212 > V_215 )
V_212 = V_215 ;
if ( V_212 < V_214 )
V_212 = V_214 ;
V_48 -> V_222 = V_212 * V_209 ;
}
} else if ( V_48 -> V_220 == V_223 ) {
V_48 -> V_222 = 0 ;
}
if ( V_48 -> V_224 == V_221 ) {
V_213 = F_69 ( V_48 -> V_225 , V_48 -> V_33 ) ;
if ( V_48 -> V_220 == V_221 ) {
V_219 = V_212 * V_48 -> V_226 ;
V_218 =
( V_212 * V_48 -> V_226 - 1 ) +
V_216 ;
} else {
V_219 = V_217 ;
V_218 = V_216 + V_219 ;
}
if ( V_213 > V_218 )
V_213 = V_218 ;
if ( V_213 < V_219 )
V_213 = V_219 ;
V_48 -> V_225 = V_213 * V_209 ;
}
}
static int F_71 ( struct V_14 * V_15 ,
struct V_157 * V_158 ,
struct V_47 * V_48 )
{
const struct V_8 * V_9 = V_15 -> V_18 ;
unsigned int V_227 = F_61 ( V_48 -> V_228 [ 0 ] ) ;
int V_116 ;
for ( V_116 = 1 ; V_116 < V_48 -> V_226 ; V_116 ++ ) {
unsigned int V_167 = F_61 ( V_48 -> V_228 [ V_116 ] ) ;
if ( V_167 != V_227 ) {
F_64 ( V_15 -> V_28 ,
L_7 ) ;
return - V_193 ;
}
}
if ( V_9 -> V_10 == V_11 ) {
unsigned int V_229 = F_59 ( V_48 -> V_228 [ 0 ] ) ;
for ( V_116 = 1 ; V_116 < V_48 -> V_226 ; V_116 ++ ) {
unsigned int V_230 = F_59 ( V_48 -> V_228 [ V_116 ] ) ;
if ( V_230 != ( V_229 + V_116 ) ) {
F_64 ( V_15 -> V_28 ,
L_8 ) ;
return - V_193 ;
}
}
if ( V_48 -> V_226 == 3 ) {
F_64 ( V_15 -> V_28 ,
L_9 ) ;
return - V_193 ;
}
}
return 0 ;
}
static int F_72 ( struct V_14 * V_15 , struct V_157 * V_158 ,
struct V_47 * V_48 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
int V_231 = 0 ;
unsigned int V_232 , V_233 ;
unsigned int V_234 ;
V_231 |= F_73 ( & V_48 -> V_235 , V_223 | V_236 ) ;
V_234 = V_221 ;
if ( V_17 -> V_10 == V_11 )
V_234 |= V_237 ;
else
V_234 |= V_238 ;
V_231 |= F_73 ( & V_48 -> V_224 , V_234 ) ;
V_234 = V_221 ;
if ( V_17 -> V_10 == V_11 )
V_234 |= V_223 ;
else
V_234 |= V_236 ;
V_231 |= F_73 ( & V_48 -> V_220 , V_234 ) ;
V_231 |= F_73 ( & V_48 -> V_239 , V_240 ) ;
V_231 |= F_73 ( & V_48 -> V_241 ,
V_240 | V_236 | V_242 ) ;
if ( V_231 )
return 1 ;
V_231 |= F_74 ( V_48 -> V_235 ) ;
V_231 |= F_74 ( V_48 -> V_224 ) ;
V_231 |= F_74 ( V_48 -> V_220 ) ;
V_231 |= F_74 ( V_48 -> V_241 ) ;
if ( V_48 -> V_220 == V_236 && V_48 -> V_224 == V_221 )
V_231 |= - V_193 ;
if ( V_231 )
return 2 ;
switch ( V_48 -> V_235 ) {
case V_223 :
V_231 |= F_75 ( & V_48 -> V_243 , 0 ) ;
break;
case V_236 :
break;
}
if ( V_48 -> V_220 == V_221 ) {
if ( V_17 -> V_10 == V_11 ) {
V_231 |= F_75 ( & V_48 -> V_222 ,
0 ) ;
} else {
V_231 |= F_76 ( & V_48 -> V_222 ,
V_17 ->
V_244 ) ;
if ( V_48 -> V_224 == V_221 ) {
V_231 |= F_76 (
& V_48 -> V_225 ,
V_48 -> V_222 *
V_48 -> V_226 ) ;
}
}
}
V_231 |= F_76 ( & V_48 -> V_226 , 1 ) ;
V_231 |= F_75 ( & V_48 -> V_245 ,
V_48 -> V_226 ) ;
switch ( V_48 -> V_241 ) {
case V_236 :
break;
case V_240 :
V_231 |= F_76 ( & V_48 -> V_246 , 1 ) ;
break;
case V_242 :
V_231 |= F_75 ( & V_48 -> V_246 , 0 ) ;
break;
default:
break;
}
if ( V_231 )
return 3 ;
if ( V_48 -> V_220 == V_221 ) {
V_232 = V_48 -> V_222 ;
V_233 = V_48 -> V_225 ;
F_70 ( V_15 , V_48 ) ;
if ( V_232 != V_48 -> V_222 )
V_231 ++ ;
if ( V_233 != V_48 -> V_225 )
V_231 ++ ;
}
if ( V_231 )
return 4 ;
if ( V_48 -> V_228 && V_48 -> V_226 > 0 )
V_231 |= F_71 ( V_15 , V_158 , V_48 ) ;
if ( V_231 )
return 5 ;
return 0 ;
}
static int F_77 ( struct V_47 * V_48 )
{
return 0 ;
if ( V_48 -> V_241 == V_240 && V_48 -> V_246 <= V_216 )
return 1 ;
return 0 ;
}
static void F_78 ( struct V_14 * V_15 ,
struct V_47 * V_48 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
if ( F_77 ( V_48 ) ) {
F_31 ( V_48 -> V_246 & 0xffff ,
V_31 -> V_45 + V_247 ) ;
F_31 ( ( V_48 -> V_246 >> 16 ) & 0xff ,
V_31 -> V_45 + V_248 ) ;
} else {
F_31 ( 1 , V_31 -> V_45 + V_247 ) ;
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
return V_48 -> V_222 / V_209 - 3 ;
}
static T_3 F_81 ( struct V_14 * V_15 ,
struct V_47 * V_48 )
{
T_3 V_249 ;
switch ( V_48 -> V_224 ) {
case V_221 :
V_249 = ( V_48 -> V_225 -
( V_48 -> V_222 * ( V_48 -> V_226 - 1 ) ) ) /
V_209 ;
break;
case V_238 :
V_249 = V_48 -> V_222 / V_209 ;
break;
default:
return 0 ;
}
return V_249 - 3 ;
}
static T_3 F_82 ( struct V_14 * V_15 ,
struct V_47 * V_48 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
unsigned int V_198 ;
switch ( V_48 -> V_224 ) {
case V_221 :
V_198 = V_48 -> V_225 / V_209 ;
break;
case V_237 :
V_198 = V_31 -> V_201 . V_198 ;
break;
default:
F_22 ( V_15 -> V_28 , L_10 ) ;
V_198 = 1000 ;
break;
}
return V_198 - 2 ;
}
static void F_83 ( struct V_14 * V_15 ,
const struct V_47 * V_48 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
V_31 -> V_105 &= ~ V_250 ;
if ( V_48 -> V_224 == V_237 ) {
int V_169 = V_31 -> V_201 . V_169 ;
if ( F_59 ( V_169 ) )
V_31 -> V_105 |= V_251 ;
else
V_31 -> V_105 |= V_252 ;
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
F_86 ( V_253 | V_254 |
V_255 ,
V_31 -> V_35 + V_256 ) ;
else
F_86 ( V_253 | V_254 |
V_255 ,
V_31 -> V_35 + V_257 ) ;
F_27 ( & V_15 -> V_34 , V_33 ) ;
}
static void F_87 ( struct V_14 * V_15 , struct V_47 * V_48 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_30 * V_31 = V_15 -> V_32 ;
T_3 V_258 = 0 , V_259 = 0 ;
F_70 ( V_15 , V_48 ) ;
F_84 ( V_15 , V_48 ) ;
if ( V_17 -> V_10 == V_11 ) {
V_258 = F_82 ( V_15 , V_48 ) ;
} else {
V_258 = F_80 ( V_15 , V_48 ) ;
V_259 = F_81 ( V_15 , V_48 ) ;
}
F_31 ( V_258 & 0xffff ,
V_31 -> V_45 + V_187 ) ;
F_31 ( ( V_258 >> 16 ) & 0xff ,
V_31 -> V_45 + V_101 ) ;
F_31 ( V_259 & 0xffff ,
V_31 -> V_45 + V_260 ) ;
F_31 ( ( V_259 >> 16 ) & 0xff ,
V_31 -> V_45 + V_261 ) ;
}
static int F_88 ( const struct V_47 * V_48 )
{
int V_116 ;
for ( V_116 = 0 ; V_116 + 1 < V_48 -> V_226 ; V_116 ++ ) {
if ( F_59 ( V_48 -> V_228 [ V_116 + 1 ] ) !=
F_59 ( V_48 -> V_228 [ V_116 ] ) + 1 )
return 0 ;
if ( F_60 ( V_48 -> V_228 [ V_116 + 1 ] ) !=
F_60 ( V_48 -> V_228 [ V_116 ] ) )
return 0 ;
if ( F_61 ( V_48 -> V_228 [ V_116 + 1 ] ) != F_61 ( V_48 -> V_228 [ V_116 ] ) )
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
V_31 -> V_105 &= ~ V_172 ;
F_31 ( V_31 -> V_105 ,
V_31 -> V_45 + V_106 ) ;
V_24 = 0 ;
V_24 |= F_10 ( F_59 ( V_48 -> V_228 [ 0 ] ) ) ;
V_24 |= F_19 ( V_15 ,
F_60 ( V_48 -> V_228 [ 0 ] ) ) ;
V_24 |= F_18 ( V_15 ,
F_61 ( V_48 -> V_228 [ 0 ] ) ==
V_178 ) ;
if ( F_61 ( V_48 -> V_228 [ 0 ] ) == V_179 )
V_24 |= V_180 ;
F_31 ( F_10
( F_59 ( V_48 -> V_228 [ V_48 -> V_226 - 1 ] ) ) ,
V_31 -> V_45 + V_181 ) ;
F_31 ( V_24 ,
V_31 -> V_45 + V_182 ) ;
} else {
if ( V_15 -> V_262 && V_15 -> V_262 -> V_263 ) {
F_47 ( V_15 ) ;
return - V_165 ;
}
V_31 -> V_105 |= V_172 ;
F_31 ( V_31 -> V_105 ,
V_31 -> V_45 + V_106 ) ;
F_31 ( 0 ,
V_31 -> V_45 + V_264 ) ;
F_31 ( 0 , V_31 -> V_45 + V_265 ) ;
for ( V_116 = 0 ; V_116 < V_48 -> V_226 ; V_116 ++ ) {
V_24 = 0 ;
V_24 |= F_10 ( F_59 ( V_48 ->
V_228 [ V_116 ] ) ) ;
V_24 |= F_19 ( V_15 ,
F_60 ( V_48 ->
V_228
[ V_116 ] ) ) ;
V_24 |= F_18 ( V_15 ,
F_61 ( V_48 ->
V_228 [ V_116 ] ) ==
V_178 ) ;
if ( F_61 ( V_48 -> V_228 [ V_116 ] ) == V_179 )
V_24 |= V_180 ;
if ( V_116 == V_48 -> V_226 - 1 )
V_24 |= V_266 |
V_267 ;
F_31 ( V_24 ,
V_31 -> V_45 +
V_268 ) ;
}
F_31 ( 0 , V_31 -> V_45 + V_265 ) ;
F_31 ( 0 , V_31 -> V_45 + V_182 ) ;
}
} else {
unsigned short V_183 = V_31 -> V_184 ;
V_31 -> V_184 &= ~ V_7 ;
V_31 -> V_184 |= F_15 ( 4 ) ;
for ( V_116 = 0 ; V_116 < V_48 -> V_226 ; V_116 ++ ) {
unsigned int V_1 = F_59 ( V_48 -> V_228 [ V_116 ] ) ;
unsigned int V_25 = F_60 ( V_48 -> V_228 [ V_116 ] ) ;
if ( V_25 == 0 )
V_31 -> V_184 |=
F_16 ( V_1 ) ;
else
V_31 -> V_184 &=
~ F_16 ( V_1 ) ;
}
if ( V_183 != V_31 -> V_184 ) {
T_2 V_185 = V_31 -> V_184 ;
F_55 ( V_15 , V_186 , & V_185 ,
sizeof( V_185 ) ) ;
}
}
return 0 ;
}
static inline void F_90 ( struct V_14 * V_15 ,
unsigned int V_269 ,
unsigned int V_270 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
if ( V_269 ) {
F_29 ( 0 ,
V_31 -> V_35 + V_271 ) ;
F_29 ( 0 , V_31 -> V_35 + V_272 ) ;
F_29 ( 0 ,
V_31 -> V_35 + V_273 ) ;
F_29 ( V_270 ,
V_31 -> V_35 + V_274 ) ;
} else {
F_29 ( 0 ,
V_31 -> V_35 + V_275 ) ;
F_29 ( 0 , V_31 -> V_35 + V_276 ) ;
F_29 ( 0 ,
V_31 -> V_35 + V_277 ) ;
F_29 ( V_270 ,
V_31 -> V_35 + V_278 ) ;
}
}
static int F_91 ( struct V_14 * V_15 , struct V_157 * V_158 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_30 * V_31 = V_15 -> V_32 ;
struct V_279 * V_280 = V_158 -> V_280 ;
struct V_47 * V_48 = & V_280 -> V_48 ;
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
V_31 -> V_77 &= ~ V_171 ;
if ( V_17 -> V_10 != V_11 ) {
V_31 -> V_77 &= ~ V_281 ;
if ( V_48 -> V_220 == V_236 )
V_31 -> V_77 |= F_7 ( 13 ) ;
else
V_31 -> V_77 |= F_7 ( 8 ) ;
} else {
V_31 -> V_77 &= ~ V_282 ;
if ( V_48 -> V_226 == 4 )
V_31 -> V_77 |= V_283 ;
else if ( V_48 -> V_226 == 2 )
V_31 -> V_77 |= V_284 ;
V_31 -> V_77 &= ~ V_285 ;
V_31 -> V_77 |=
F_5 ( F_59 ( V_48 -> V_228 [ 0 ] ) ) ;
V_31 -> V_77 &= ~ V_286 ;
V_31 -> V_77 |=
F_6 ( F_59 ( V_48 -> V_228
[ V_48 -> V_226 - 1 ] ) ) ;
}
F_31 ( V_31 -> V_77 ,
V_31 -> V_45 + V_79 ) ;
F_27 ( & V_15 -> V_34 , V_33 ) ;
F_31 ( 0 , V_31 -> V_45 + V_188 ) ;
if ( ( V_48 -> V_33 & V_49 ) == 0 ||
V_17 -> V_10 == V_11 ) {
V_31 -> V_287 = 0 ;
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
if ( V_48 -> V_235 == V_236 && F_59 ( V_48 -> V_243 ) )
V_24 |= V_288 ;
if ( V_48 -> V_241 == V_236 && F_59 ( V_48 -> V_246 ) )
V_24 |= V_289 ;
F_31 ( V_24 , V_31 -> V_45 + V_290 ) ;
}
F_25 ( & V_15 -> V_34 , V_33 ) ;
V_24 = V_291 | V_81 | V_82 ;
if ( V_48 -> V_33 & V_49 )
V_24 |= V_80 ;
if ( V_48 -> V_235 == V_236 ) {
V_24 |= V_292 ;
if ( V_48 -> V_243 & V_293 )
V_24 |= V_294 ;
} else if ( V_48 -> V_235 == V_223 ) {
V_24 |= V_295 ;
}
if ( F_77 ( V_48 ) )
V_24 |= V_296 ;
F_31 ( V_24 , V_31 -> V_45 + V_83 ) ;
V_31 -> V_297 = 1 ;
F_27 ( & V_15 -> V_34 , V_33 ) ;
if ( V_48 -> V_235 == V_223 )
F_31 ( 0 , V_31 -> V_45 + V_298 ) ;
return 0 ;
}
static void F_92 ( struct V_14 * V_15 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
struct V_157 * V_158 = V_15 -> V_299 ;
unsigned int V_116 ;
T_1 V_6 ;
int V_300 , V_301 , V_302 , V_303 ;
int V_95 ;
do {
V_301 = F_57 ( V_31 -> V_45 + V_304 ) &
0x7fff ;
V_303 = F_57 ( V_31 -> V_45 + V_164 ) &
0x7fff ;
V_6 = F_57 ( V_31 -> V_45 + V_305 ) ;
V_300 = F_13 ( V_6 ) ;
V_302 = F_14 ( V_6 ) ;
if ( V_300 != V_302 )
V_95 =
V_31 -> V_94 - V_301 ;
else
V_95 = V_303 - V_301 ;
if ( V_95 < 0 ) {
F_22 ( V_15 -> V_28 ,
L_11 ) ;
break;
}
V_95 = F_93 ( V_158 , V_95 ) ;
if ( V_95 == 0 )
break;
for ( V_116 = 0 ; V_116 < V_95 ; V_116 ++ ) {
unsigned short V_306 ;
V_306 = F_57 ( V_31 -> V_45 + V_132 ) ;
F_94 ( V_158 , & V_306 , 1 ) ;
}
} while ( V_300 != V_302 );
}
static void F_95 ( struct V_14 * V_15 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
struct V_157 * V_158 = V_15 -> V_299 ;
unsigned int V_307 ;
unsigned int V_116 ;
T_3 V_308 ;
int V_309 =
F_57 ( V_31 -> V_45 + V_164 ) & 0x7fff ;
int V_310 =
F_57 ( V_31 -> V_45 + V_304 ) & 0x7fff ;
V_307 = F_93 ( V_158 , 100000 ) ;
for ( V_116 = 0 ; V_310 != V_309 && V_116 < V_307 ; ) {
unsigned short V_306 ;
V_308 = F_34 ( V_15 -> V_190 + V_132 ) ;
V_306 = V_308 & 0xffff ;
F_94 ( V_158 , & V_306 , 1 ) ;
V_116 ++ ;
if ( V_116 < V_307 ) {
V_306 = ( V_308 >> 16 ) & 0xffff ;
F_94 ( V_158 , & V_306 , 1 ) ;
V_116 ++ ;
}
V_310 = F_57 ( V_31 -> V_45 + V_304 ) &
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
struct V_157 * V_158 = V_15 -> V_299 ;
T_3 V_311 ;
int V_312 ;
int V_95 = 0 ;
void T_4 * V_313 ;
if ( V_1 )
V_313 =
V_31 -> V_35 + V_272 ;
else
V_313 =
V_31 -> V_35 + V_276 ;
for ( V_312 = 0 , V_311 = F_34 ( V_313 ) ;
( V_311 <
V_31 -> V_119 [ V_31 -> V_287 ] ||
V_311 >=
V_31 -> V_119 [ V_31 -> V_287 ] +
V_118 ) && V_312 < F_17 ( V_17 ) ; V_312 ++ ) {
V_95 = F_93 ( V_158 , F_79 ( V_15 ) ) ;
F_94 ( V_158 ,
V_31 -> V_117 [ V_31 -> V_287 ] ,
V_95 ) ;
V_31 -> V_287 = ( V_31 -> V_287 + 1 ) %
F_17 ( V_17 ) ;
}
}
static void F_98 ( struct V_14 * V_15 ,
unsigned short V_162 ,
unsigned int V_314 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_30 * V_31 = V_15 -> V_32 ;
struct V_157 * V_158 = V_15 -> V_299 ;
struct V_279 * V_280 = V_158 -> V_280 ;
struct V_47 * V_48 = & V_280 -> V_48 ;
T_2 V_315 ;
unsigned long V_33 ;
if ( V_162 & V_316 ) {
F_22 ( V_15 -> V_28 , L_12 ) ;
V_280 -> V_317 |= V_318 ;
}
F_25 ( & V_15 -> V_34 , V_33 ) ;
V_315 = F_99 ( V_31 -> V_35 + V_256 ) ;
if ( V_314 & V_319 ) {
F_86 ( ( V_315 & V_253 ) | V_255 ,
V_31 -> V_35 + V_256 ) ;
if ( V_315 & V_253 )
F_97 ( V_15 , 1 ) ;
}
F_27 ( & V_15 -> V_34 , V_33 ) ;
if ( ( V_162 & V_320 ) ||
( ( V_48 -> V_33 & V_49 ) &&
( V_162 & V_321 ) &&
( V_17 -> V_10 != V_11 ) ) ) {
F_25 ( & V_15 -> V_34 , V_33 ) ;
if ( V_31 -> V_297 ) {
F_27 ( & V_15 -> V_34 , V_33 ) ;
F_96 ( V_15 ) ;
} else {
F_27 ( & V_15 -> V_34 , V_33 ) ;
}
}
if ( ( V_48 -> V_241 == V_240 &&
V_280 -> V_322 >= V_48 -> V_246 ) ||
( V_48 -> V_241 == V_236 && ( V_162 & V_323 ) ) )
V_280 -> V_317 |= V_324 ;
F_100 ( V_15 , V_158 ) ;
}
static inline unsigned int F_101 ( struct V_14 * V_15 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
unsigned int V_325 ;
if ( V_31 -> V_326 == 0 )
V_325 = V_121 - 1 ;
else
V_325 = V_31 -> V_326 - 1 ;
return V_325 ;
}
static int F_102 ( struct V_14 * V_15 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
unsigned int V_325 ;
unsigned int V_327 ;
unsigned short V_328 ;
V_325 = F_101 ( V_15 ) ;
V_328 = F_99 ( V_31 -> V_35 + V_257 ) ;
if ( ( V_328 & V_329 ) == 0 )
return 0 ;
V_327 =
F_34 ( V_31 -> V_35 + V_276 ) ;
if ( V_327 != V_31 -> V_123 [ V_325 ] )
return 0 ;
return 1 ;
}
static inline int F_103 ( struct V_14 * V_15 ,
unsigned short V_328 )
{
if ( ( V_328 & V_329 ) == 0 ||
( V_328 & V_253 ) == 0 )
return 0 ;
if ( F_102 ( V_15 ) )
return 0 ;
return 1 ;
}
static void F_104 ( struct V_14 * V_15 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
unsigned int V_330 ;
V_330 =
F_34 ( V_31 -> V_35 + V_278 ) ;
V_330 &= ~ V_331 ;
F_90 ( V_15 , 0 , V_330 ) ;
F_85 ( V_15 , 0 ) ;
}
static unsigned int F_105 ( struct V_14 * V_15 ,
struct V_157 * V_158 ,
unsigned short * V_332 ,
unsigned int V_333 )
{
unsigned int V_307 = F_106 ( V_158 , V_333 ) ;
unsigned int V_334 ;
V_307 = F_93 ( V_158 , V_307 ) ;
V_334 = F_107 ( V_158 , V_332 , V_307 ) ;
return F_106 ( V_158 , V_334 ) ;
}
static unsigned int F_108 ( struct V_14 * V_15 ,
const struct V_47 * V_48 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
struct V_157 * V_158 = V_15 -> V_262 ;
unsigned int V_325 = V_31 -> V_326 ;
unsigned int V_335 = F_101 ( V_15 ) ;
unsigned int V_307 ;
unsigned int V_336 ;
unsigned int V_337 ;
V_307 = F_105 ( V_15 , V_158 ,
V_31 -> V_122 [ V_325 ] ,
V_118 ) ;
if ( V_307 == 0 )
return 0 ;
V_336 = F_109 ( V_158 , V_307 ) ;
V_31 -> V_127 [ V_325 ] . V_134 = F_44 ( V_336 ) ;
V_337 = F_110 ( V_31 -> V_127 [ V_325 ] . V_135 ) ;
V_337 |= V_331 ;
V_31 -> V_127 [ V_325 ] . V_135 = F_44 ( V_337 ) ;
V_337 = F_110 ( V_31 -> V_127 [ V_335 ] . V_135 ) ;
V_337 &= ~ V_331 ;
V_31 -> V_127 [ V_335 ] . V_135 = F_44 ( V_337 ) ;
V_31 -> V_326 = ( V_325 + 1 ) % V_121 ;
return V_336 ;
}
static void F_111 ( struct V_14 * V_15 , const struct V_47 * V_48 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
unsigned int V_338 ;
unsigned int V_311 ;
void T_4 * V_313 =
V_31 -> V_35 + V_276 ;
unsigned int V_325 ;
do {
V_325 = V_31 -> V_326 ;
V_311 = F_34 ( V_313 ) ;
if ( V_311 >=
V_31 -> V_123 [ V_325 ] &&
V_311 <
V_31 -> V_123 [ V_325 ] +
V_118 )
return;
V_338 = F_108 ( V_15 , V_48 ) ;
} while ( V_338 >= V_118 );
}
static void F_112 ( struct V_14 * V_15 ,
unsigned short V_162 , unsigned int V_314 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
struct V_157 * V_158 = V_15 -> V_262 ;
struct V_279 * V_280 ;
struct V_47 * V_48 ;
T_2 V_339 ;
unsigned long V_33 ;
if ( ! V_158 )
return;
V_280 = V_158 -> V_280 ;
V_48 = & V_280 -> V_48 ;
F_25 ( & V_15 -> V_34 , V_33 ) ;
V_339 = F_99 ( V_31 -> V_35 + V_257 ) ;
if ( V_314 & V_340 ) {
if ( ( V_339 & V_253 ) &&
! ( V_339 & V_329 ) )
F_86 ( V_253 | V_255 ,
V_31 -> V_35 + V_257 ) ;
else
F_86 ( V_255 ,
V_31 -> V_35 + V_257 ) ;
F_27 ( & V_15 -> V_34 , V_33 ) ;
if ( V_339 & V_253 ) {
F_111 ( V_15 , V_48 ) ;
if ( F_103 ( V_15 , V_339 ) )
F_104 ( V_15 ) ;
}
} else {
F_27 ( & V_15 -> V_34 , V_33 ) ;
}
if ( ( V_162 & V_341 ) ) {
if ( ( V_48 -> V_241 == V_240 &&
V_280 -> V_322 >= V_48 -> V_246 ) ||
F_102 ( V_15 ) )
V_280 -> V_317 |= V_324 ;
else
V_280 -> V_317 |= V_318 ;
}
F_100 ( V_15 , V_158 ) ;
}
static T_5 F_113 ( int V_342 , void * V_343 )
{
struct V_14 * V_15 = V_343 ;
struct V_30 * V_31 = V_15 -> V_32 ;
unsigned short V_162 ;
T_3 V_314 ;
T_3 V_344 ;
V_314 = F_34 ( V_31 -> V_35 + V_37 ) ;
V_162 = F_57 ( V_31 -> V_45 + V_163 ) ;
if ( ! V_15 -> V_345 )
return V_346 ;
F_98 ( V_15 , V_162 , V_314 ) ;
F_112 ( V_15 , V_162 , V_314 ) ;
if ( V_314 & V_347 ) {
V_344 = F_34 ( V_31 -> V_35 + V_348 ) ;
F_29 ( V_344 , V_31 -> V_35 + V_348 ) ;
}
return V_346 ;
}
static int F_114 ( struct V_14 * V_15 , struct V_157 * V_158 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
unsigned long V_33 ;
F_25 ( & V_15 -> V_34 , V_33 ) ;
if ( V_31 -> V_297 == 0 ) {
F_27 ( & V_15 -> V_34 , V_33 ) ;
return 0 ;
}
V_31 -> V_297 = 0 ;
F_27 ( & V_15 -> V_34 , V_33 ) ;
F_36 ( V_15 ) ;
F_24 ( V_15 , 1 ) ;
return 0 ;
}
static int F_115 ( struct V_14 * V_15 , struct V_157 * V_158 ,
struct V_159 * V_160 , unsigned int * V_152 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_30 * V_31 = V_15 -> V_32 ;
int V_230 = F_59 ( V_160 -> V_169 ) ;
int V_25 = F_60 ( V_160 -> V_169 ) ;
F_31 ( 0 , V_31 -> V_45 + V_349 ) ;
F_21 ( V_15 , & V_31 -> V_110 , V_230 , V_25 ) ;
F_31 ( V_31 -> V_110 ,
V_31 -> V_45 + V_350 ) ;
if ( V_17 -> V_10 == V_11 ) {
F_31 ( V_152 [ 0 ] & 0xff ,
V_31 -> V_45 + F_2 ( V_230 ) ) ;
F_31 ( ( V_152 [ 0 ] >> 8 ) & 0xf ,
V_31 -> V_45 + F_3 ( V_230 ) ) ;
} else {
F_31 ( V_152 [ 0 ] , V_31 -> V_45 + F_1 ( V_230 ) ) ;
}
V_158 -> V_351 [ V_230 ] = V_152 [ 0 ] ;
return 1 ;
}
static void F_116 ( struct V_14 * V_15 ,
const struct V_47 * V_48 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
unsigned int V_24 = V_352 | V_353 |
V_354 | V_355 ;
if ( V_48 -> V_235 == V_236 ) {
V_24 |= V_356 ;
if ( V_48 -> V_243 & V_293 )
V_24 |= V_357 ;
} else {
V_24 |= V_358 ;
}
if ( V_48 -> V_224 == V_236 ) {
V_24 |= V_359 ;
if ( V_48 -> V_225 & V_293 )
V_24 |= V_360 ;
}
F_31 ( V_24 , V_31 -> V_45 + V_349 ) ;
}
static void F_117 ( struct V_14 * V_15 ,
const struct V_47 * V_48 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
int V_116 ;
for ( V_116 = 0 ; V_116 < V_48 -> V_226 ; V_116 ++ ) {
int V_1 , V_25 ;
V_1 = F_59 ( V_48 -> V_228 [ V_116 ] ) ;
V_25 = F_60 ( V_48 -> V_228 [ V_116 ] ) ;
F_21 ( V_15 , & V_31 -> V_110 , V_1 ,
V_25 ) ;
}
V_31 -> V_110 |= V_361 ;
F_31 ( V_31 -> V_110 ,
V_31 -> V_45 + V_350 ) ;
}
static void F_118 ( struct V_14 * V_15 ,
const struct V_47 * V_48 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
T_1 V_24 ;
unsigned int V_362 , V_363 ;
V_362 = F_59 ( V_48 -> V_228 [ 0 ] ) ;
V_363 = F_59 ( V_48 -> V_228 [ V_48 -> V_226 - 1 ] ) ;
if ( V_363 < V_362 )
F_22 ( V_15 -> V_28 ,
L_13 ) ;
V_24 = ( V_362 & 0x7 ) | ( V_363 & 0x7 ) << 3 ;
F_31 ( V_24 , V_31 -> V_45 + V_364 ) ;
}
static unsigned int F_119 ( unsigned int V_206 , unsigned int V_33 )
{
return F_69 ( V_206 , V_33 ) - 2 ;
}
static void F_120 ( struct V_14 * V_15 ,
const struct V_47 * V_48 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
unsigned int V_198 ;
if ( V_48 -> V_224 != V_221 )
return;
V_198 = F_119 ( V_48 -> V_225 , V_48 -> V_33 ) ;
if ( V_198 > V_216 ) {
F_22 ( V_15 -> V_28 , L_14 ) ;
V_198 = V_216 ;
}
F_31 ( V_198 & 0xffff ,
V_31 -> V_45 + V_365 ) ;
F_31 ( ( V_198 >> 16 ) & 0xff ,
V_31 -> V_45 + V_366 ) ;
}
static int F_121 ( struct V_14 * V_15 , const struct V_47 * V_48 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
struct V_157 * V_158 = V_15 -> V_262 ;
unsigned int V_307 ;
unsigned int V_336 ;
int V_116 ;
F_31 ( 0 , V_31 -> V_45 + V_265 ) ;
F_31 ( 0 , V_31 -> V_45 + V_264 ) ;
V_307 = F_105 ( V_15 , V_158 ,
V_31 -> V_367 ,
V_368 ) ;
if ( V_307 == 0 )
return - 1 ;
for ( V_116 = 0 ; V_116 < V_307 ; V_116 ++ ) {
F_31 ( V_31 -> V_367 [ V_116 ] ,
V_31 -> V_45 + V_139 ) ;
}
if ( V_48 -> V_241 == V_240 &&
V_158 -> V_280 -> V_322 >= V_48 -> V_246 )
return 0 ;
V_336 = F_108 ( V_15 , V_48 ) ;
if ( V_336 == 0 )
return - 1 ;
F_111 ( V_15 , V_48 ) ;
F_85 ( V_15 , 0 ) ;
return 0 ;
}
static inline int F_122 ( struct V_14 * V_15 ,
struct V_157 * V_158 ,
struct V_47 * V_48 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
if ( V_158 -> V_263 )
return 0 ;
if ( V_17 -> V_10 == V_11 )
return 0 ;
else if ( F_88 ( V_48 ) )
return 0 ;
return 1 ;
}
static int F_123 ( struct V_14 * V_15 , struct V_157 * V_158 ,
unsigned int V_369 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
struct V_47 * V_48 = & V_158 -> V_280 -> V_48 ;
int V_97 ;
if ( V_369 != V_48 -> V_243 )
return - V_193 ;
V_97 = F_121 ( V_15 , V_48 ) ;
if ( V_97 < 0 )
return - V_370 ;
F_116 ( V_15 , V_48 ) ;
if ( V_48 -> V_235 == V_371 )
F_31 ( 0 , V_31 -> V_45 + V_372 ) ;
V_158 -> V_280 -> V_373 = NULL ;
return 0 ;
}
static int F_124 ( struct V_14 * V_15 , struct V_157 * V_158 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
struct V_47 * V_48 = & V_158 -> V_280 -> V_48 ;
if ( F_122 ( V_15 , V_158 , V_48 ) ) {
F_47 ( V_15 ) ;
return - V_165 ;
}
F_31 ( 0x0 , V_31 -> V_45 + V_349 ) ;
V_31 -> V_326 = 0 ;
F_118 ( V_15 , V_48 ) ;
F_120 ( V_15 , V_48 ) ;
F_90 ( V_15 , 0 , V_31 -> V_128 |
V_136 | V_137 ) ;
F_117 ( V_15 , V_48 ) ;
V_158 -> V_280 -> V_373 = F_123 ;
return 0 ;
}
static int F_125 ( struct V_14 * V_15 ,
struct V_157 * V_158 ,
struct V_47 * V_48 )
{
unsigned int V_229 = F_59 ( V_48 -> V_228 [ 0 ] ) ;
int V_116 ;
for ( V_116 = 1 ; V_116 < V_48 -> V_226 ; V_116 ++ ) {
unsigned int V_230 = F_59 ( V_48 -> V_228 [ V_116 ] ) ;
if ( V_230 != ( V_229 + V_116 ) ) {
F_64 ( V_15 -> V_28 ,
L_8 ) ;
return - V_193 ;
}
}
return 0 ;
}
static int F_126 ( struct V_14 * V_15 , struct V_157 * V_158 ,
struct V_47 * V_48 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
int V_231 = 0 ;
unsigned int V_232 ;
V_231 |= F_73 ( & V_48 -> V_235 , V_371 | V_236 ) ;
V_231 |= F_73 ( & V_48 -> V_224 ,
V_221 | V_236 ) ;
V_231 |= F_73 ( & V_48 -> V_220 , V_223 ) ;
V_231 |= F_73 ( & V_48 -> V_239 , V_240 ) ;
V_231 |= F_73 ( & V_48 -> V_241 , V_242 ) ;
if ( V_231 )
return 1 ;
V_231 |= F_74 ( V_48 -> V_235 ) ;
V_231 |= F_74 ( V_48 -> V_224 ) ;
if ( V_48 -> V_220 == V_236 && V_48 -> V_224 == V_221 )
V_231 |= - V_193 ;
if ( V_48 -> V_241 != V_240 &&
V_48 -> V_241 != V_242 && V_48 -> V_241 != V_236 )
V_231 |= - V_193 ;
if ( V_231 )
return 2 ;
V_231 |= F_75 ( & V_48 -> V_243 , 0 ) ;
if ( V_48 -> V_224 == V_221 ) {
V_231 |= F_76 ( & V_48 -> V_225 ,
V_17 -> V_374 ) ;
if ( F_119 ( V_48 -> V_225 , V_48 -> V_33 ) >
V_216 ) {
V_48 -> V_225 = ( V_216 + 2 ) *
V_209 ;
V_231 |= - V_193 ;
}
}
V_231 |= F_76 ( & V_48 -> V_226 , 1 ) ;
V_231 |= F_75 ( & V_48 -> V_245 ,
V_48 -> V_226 ) ;
if ( V_231 )
return 3 ;
if ( V_48 -> V_224 == V_221 ) {
V_232 = V_48 -> V_225 ;
V_48 -> V_225 = F_69 ( V_48 -> V_225 ,
V_48 -> V_33 ) * V_209 ;
if ( V_232 != V_48 -> V_225 )
V_231 ++ ;
}
if ( V_231 )
return 4 ;
if ( V_48 -> V_228 && V_48 -> V_226 > 0 )
V_231 |= F_125 ( V_15 , V_158 , V_48 ) ;
if ( V_231 )
return 5 ;
return 0 ;
}
static int F_127 ( struct V_14 * V_15 , struct V_157 * V_158 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
F_31 ( 0x0 , V_31 -> V_45 + V_349 ) ;
F_24 ( V_15 , 0 ) ;
return 0 ;
}
static int F_128 ( struct V_14 * V_15 ,
int V_375 , int V_376 , int V_152 , unsigned long V_377 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
if ( V_375 ) {
F_31 ( V_152 , V_31 -> V_45 + V_377 + 2 * V_376 ) ;
return 0 ;
}
return F_57 ( V_31 -> V_45 + V_377 + 2 * V_376 ) ;
}
static int F_129 ( struct V_14 * V_15 , struct V_157 * V_158 ,
struct V_159 * V_160 , unsigned int * V_152 )
{
unsigned int V_24 ;
V_24 = F_99 ( V_15 -> V_190 + V_378 ) ;
V_24 &= 0xf ;
V_152 [ 1 ] = V_24 ;
V_152 [ 0 ] = 0 ;
return V_160 -> V_166 ;
}
static int F_130 ( struct V_14 * V_15 ,
struct V_157 * V_158 ,
struct V_159 * V_160 ,
unsigned int * V_152 )
{
if ( F_131 ( V_158 , V_152 ) )
F_86 ( V_158 -> V_140 , V_15 -> V_190 + V_379 ) ;
V_152 [ 1 ] = V_158 -> V_140 ;
return V_160 -> V_166 ;
}
static int F_132 ( struct V_14 * V_15 ,
struct V_157 * V_158 ,
struct V_159 * V_160 ,
unsigned int * V_152 )
{
int V_168 ;
V_168 = F_133 ( V_15 , V_158 , V_160 , V_152 , 0 ) ;
if ( V_168 )
return V_168 ;
F_86 ( V_158 -> V_380 , V_15 -> V_190 + V_381 ) ;
return V_160 -> V_166 ;
}
static int F_134 ( struct V_14 * V_15 ,
struct V_157 * V_158 ,
struct V_159 * V_160 ,
unsigned int * V_152 )
{
if ( F_131 ( V_158 , V_152 ) )
F_86 ( V_158 -> V_140 , V_15 -> V_190 + V_382 ) ;
V_152 [ 1 ] = F_99 ( V_15 -> V_190 + V_382 ) ;
return V_160 -> V_166 ;
}
static int F_135 ( struct V_14 * V_15 , unsigned int V_151 ,
T_2 V_383 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
static const int V_384 = 8 ;
static const int V_385 = 11 ;
unsigned int V_154 = ( ( V_151 & 0x7 ) << 8 ) | V_383 ;
unsigned int V_149 , V_386 ;
static const int V_387 = 1 ;
if ( V_151 >= V_384 ) {
F_22 ( V_15 -> V_28 , L_15 ) ;
return - 1 ;
}
for ( V_149 = 1 << ( V_385 - 1 ) ; V_149 ; V_149 >>= 1 ) {
V_386 = 0 ;
if ( V_154 & V_149 )
V_386 |= V_388 ;
F_49 ( V_387 ) ;
F_31 ( V_386 , V_31 -> V_45 + V_108 ) ;
V_386 |= V_389 ;
F_49 ( V_387 ) ;
F_31 ( V_386 , V_31 -> V_45 + V_108 ) ;
}
F_49 ( V_387 ) ;
F_31 ( V_390 , V_31 -> V_45 + V_108 ) ;
F_49 ( V_387 ) ;
F_31 ( 0 , V_31 -> V_45 + V_108 ) ;
F_49 ( V_387 ) ;
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
F_22 ( V_15 -> V_28 , L_16 ) ;
return - 1 ;
}
V_392 [ 1 ] = V_398 | ( ( V_383 >> 8 ) & 0xf ) ;
V_392 [ 2 ] = V_383 & 0xff ;
F_55 ( V_15 , V_393 , V_392 , 3 ) ;
return 0 ;
}
static void F_137 ( struct V_14 * V_15 , unsigned int V_1 ,
unsigned int V_383 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
switch ( V_17 -> V_10 ) {
case V_20 :
case V_19 :
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
struct V_157 * V_158 ,
struct V_159 * V_160 ,
unsigned int * V_152 )
{
unsigned int V_230 = F_59 ( V_160 -> V_169 ) ;
if ( V_160 -> V_166 ) {
unsigned int V_306 = V_152 [ V_160 -> V_166 - 1 ] ;
if ( V_158 -> V_351 [ V_230 ] != V_306 ) {
F_137 ( V_15 , V_230 , V_306 ) ;
V_158 -> V_351 [ V_230 ] = V_306 ;
}
}
return V_160 -> V_166 ;
}
static void F_139 ( struct V_14 * V_15 , unsigned int V_1 ,
unsigned int V_383 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
static const int V_385 = 10 ;
unsigned int V_149 , V_386 ;
unsigned int V_154 = ( ( V_1 & 0x3 ) << 8 ) | ( V_383 & 0xff ) ;
static const int V_401 = 1 ;
V_386 = V_402 ;
F_49 ( V_401 ) ;
F_31 ( V_386 , V_31 -> V_45 + V_108 ) ;
for ( V_149 = 1 << ( V_385 - 1 ) ; V_149 ; V_149 >>= 1 ) {
if ( V_154 & V_149 )
V_386 |= V_388 ;
else
V_386 &= ~ V_388 ;
F_49 ( V_401 ) ;
F_31 ( V_386 , V_31 -> V_45 + V_108 ) ;
F_49 ( V_401 ) ;
F_31 ( V_386 | V_389 ,
V_31 -> V_45 + V_108 ) ;
}
F_49 ( V_401 ) ;
F_31 ( 0 , V_31 -> V_45 + V_108 ) ;
}
static int F_140 ( struct V_14 * V_15 ,
struct V_157 * V_158 ,
struct V_159 * V_160 ,
unsigned int * V_152 )
{
unsigned int V_230 = F_59 ( V_160 -> V_169 ) ;
if ( V_160 -> V_166 ) {
unsigned int V_306 = V_152 [ V_160 -> V_166 - 1 ] ;
if ( V_158 -> V_351 [ V_230 ] != V_306 ) {
F_139 ( V_15 , V_230 , V_306 ) ;
V_158 -> V_351 [ V_230 ] = V_306 ;
}
}
return V_160 -> V_166 ;
}
static T_1 F_141 ( struct V_14 * V_15 , T_2 V_151 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
static const int V_385 = 11 ;
static const int V_403 = 0x6 ;
unsigned int V_154 = ( V_403 << 8 ) | V_151 ;
unsigned int V_149 ;
void T_4 * const V_143 =
V_31 -> V_35 + V_53 ;
T_1 V_383 ;
static const int V_404 = 16 ;
static const int V_405 = 1 ;
F_49 ( V_405 ) ;
V_31 -> V_52 &= ~ V_406 & ~ V_156 ;
V_31 -> V_52 |= V_147 ;
F_29 ( V_31 -> V_52 , V_143 ) ;
F_49 ( V_405 ) ;
V_31 -> V_52 |= V_156 ;
F_29 ( V_31 -> V_52 , V_143 ) ;
for ( V_149 = 1 << ( V_385 - 1 ) ; V_149 ; V_149 >>= 1 ) {
F_49 ( V_405 ) ;
if ( V_154 & V_149 )
V_31 -> V_52 |= V_142 ;
else
V_31 -> V_52 &= ~ V_142 ;
F_29 ( V_31 -> V_52 , V_143 ) ;
F_49 ( V_405 ) ;
V_31 -> V_52 |= V_406 ;
F_29 ( V_31 -> V_52 , V_143 ) ;
F_49 ( V_405 ) ;
V_31 -> V_52 &= ~ V_406 ;
F_29 ( V_31 -> V_52 , V_143 ) ;
}
V_383 = 0 ;
for ( V_149 = 1 << ( V_404 - 1 ) ; V_149 ; V_149 >>= 1 ) {
F_49 ( V_405 ) ;
V_31 -> V_52 |= V_406 ;
F_29 ( V_31 -> V_52 , V_143 ) ;
F_49 ( V_405 ) ;
V_31 -> V_52 &= ~ V_406 ;
F_29 ( V_31 -> V_52 , V_143 ) ;
F_49 ( V_405 ) ;
if ( F_34 ( V_143 ) & V_407 )
V_383 |= V_149 ;
}
F_49 ( V_405 ) ;
V_31 -> V_52 &= ~ V_156 ;
F_29 ( V_31 -> V_52 , V_143 ) ;
return V_383 ;
}
static int F_142 ( struct V_14 * V_15 ,
struct V_157 * V_158 ,
struct V_159 * V_160 , unsigned int * V_152 )
{
V_152 [ 0 ] = F_141 ( V_15 , F_59 ( V_160 -> V_169 ) ) ;
return 1 ;
}
static int F_143 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_30 * V_31 = V_15 -> V_32 ;
struct V_157 * V_158 ;
int V_116 ;
int V_168 ;
V_168 = F_144 ( V_15 , 10 ) ;
if ( V_168 )
return V_168 ;
V_158 = & V_15 -> V_408 [ 0 ] ;
V_15 -> V_299 = V_158 ;
V_158 -> type = V_409 ;
V_158 -> V_410 = V_411 | V_412 | V_413 | V_414 ;
if ( V_17 -> V_10 == V_20 )
V_158 -> V_410 |= V_415 | V_416 ;
else if ( V_17 -> V_10 == V_19 )
V_158 -> V_410 |= V_416 ;
V_158 -> V_417 = V_17 -> V_418 ;
V_158 -> V_419 = 0x2000 ;
V_158 -> V_420 = ( 1 << V_17 -> V_421 ) - 1 ;
V_158 -> V_422 = V_17 -> V_423 ;
V_158 -> V_424 = F_58 ;
V_158 -> V_425 = F_68 ;
V_158 -> V_426 = F_91 ;
V_158 -> V_427 = F_72 ;
V_158 -> V_428 = F_114 ;
if ( V_17 -> V_10 == V_11 ) {
T_2 V_152 ;
V_31 -> V_184 = F_15 ( 4 ) ;
for ( V_116 = 0 ; V_116 < V_158 -> V_417 ; V_116 ++ )
V_31 -> V_184 |= F_16 ( V_116 ) ;
V_152 = V_31 -> V_184 ;
F_55 ( V_15 , V_186 , & V_152 , sizeof( V_152 ) ) ;
}
V_158 = & V_15 -> V_408 [ 1 ] ;
if ( V_17 -> V_29 ) {
V_158 -> type = V_429 ;
V_158 -> V_410 = V_411 | V_430 |
V_412 | V_431 ;
V_158 -> V_417 = V_17 -> V_29 ;
V_158 -> V_420 = ( 1 << V_17 -> V_432 ) - 1 ;
V_158 -> V_422 = V_17 -> V_433 ;
V_158 -> V_434 = F_115 ;
V_168 = F_145 ( V_158 ) ;
if ( V_168 )
return V_168 ;
if ( F_23 ( V_17 ) ) {
V_15 -> V_262 = V_158 ;
V_158 -> V_427 = F_126 ;
V_158 -> V_426 = F_124 ;
V_158 -> V_419 = V_17 -> V_29 ;
V_158 -> V_428 = F_127 ;
}
} else {
V_158 -> type = V_435 ;
}
V_158 = & V_15 -> V_408 [ 2 ] ;
if ( V_17 -> V_10 == V_19 ) {
V_158 -> type = V_436 ;
V_158 -> V_410 = V_411 ;
V_158 -> V_417 = 4 ;
V_158 -> V_420 = 1 ;
V_158 -> V_422 = & V_437 ;
V_158 -> V_438 = F_129 ;
} else {
V_158 -> type = V_435 ;
}
if ( V_17 -> V_10 == V_19 ) {
V_158 = & V_15 -> V_408 [ 3 ] ;
V_158 -> type = V_439 ;
V_158 -> V_410 = V_430 ;
V_158 -> V_417 = 4 ;
V_158 -> V_420 = 1 ;
V_158 -> V_422 = & V_437 ;
V_158 -> V_438 = F_130 ;
} else {
V_158 -> type = V_435 ;
}
V_158 = & V_15 -> V_408 [ 4 ] ;
if ( V_17 -> V_440 ) {
if ( V_17 -> V_10 == V_11 ) {
V_168 = F_146 ( V_15 , V_158 , F_128 ,
V_441 ) ;
} else {
V_168 = F_147 ( V_15 , V_158 , NULL ,
V_442 ) ;
}
if ( V_168 )
return V_168 ;
} else {
V_158 -> type = V_435 ;
}
V_158 = & V_15 -> V_408 [ 5 ] ;
if ( V_17 -> V_10 == V_20 ) {
V_158 -> type = V_443 ;
V_158 -> V_410 = V_430 | V_411 ;
V_158 -> V_417 = 8 ;
V_158 -> V_420 = 1 ;
V_158 -> V_422 = & V_437 ;
V_158 -> V_425 = F_132 ;
V_158 -> V_438 = F_134 ;
} else {
V_158 -> type = V_435 ;
}
V_158 = & V_15 -> V_408 [ 6 ] ;
V_158 -> type = V_444 ;
V_158 -> V_410 = V_411 | V_430 | V_445 ;
V_158 -> V_417 = 8 ;
if ( V_17 -> V_10 == V_11 )
V_158 -> V_420 = 0xfff ;
else
V_158 -> V_420 = 0xff ;
V_158 -> V_434 = F_138 ;
V_168 = F_145 ( V_158 ) ;
if ( V_168 )
return V_168 ;
for ( V_116 = 0 ; V_116 < V_158 -> V_417 ; V_116 ++ ) {
F_137 ( V_15 , V_116 , V_158 -> V_420 / 2 ) ;
V_158 -> V_351 [ V_116 ] = V_158 -> V_420 / 2 ;
}
V_158 = & V_15 -> V_408 [ 7 ] ;
if ( V_17 -> V_10 == V_19 ) {
V_158 -> type = V_444 ;
V_158 -> V_410 = V_411 | V_430 | V_445 ;
V_158 -> V_417 = 2 ;
V_158 -> V_420 = 0xff ;
V_158 -> V_434 = F_140 ;
V_168 = F_145 ( V_158 ) ;
if ( V_168 )
return V_168 ;
for ( V_116 = 0 ; V_116 < V_158 -> V_417 ; V_116 ++ ) {
F_139 ( V_15 , V_116 , V_158 -> V_420 / 2 ) ;
V_158 -> V_351 [ V_116 ] = V_158 -> V_420 / 2 ;
}
} else {
V_158 -> type = V_435 ;
}
V_158 = & V_15 -> V_408 [ 8 ] ;
if ( F_34 ( V_31 -> V_35 + V_53 ) & V_446 ) {
V_158 -> type = V_447 ;
V_158 -> V_410 = V_411 | V_445 ;
V_158 -> V_417 = 128 ;
V_158 -> V_420 = 0xffff ;
V_158 -> V_424 = F_142 ;
} else {
V_158 -> type = V_435 ;
}
V_158 = & V_15 -> V_408 [ 9 ] ;
V_158 -> type = V_435 ;
return 0 ;
}
static int F_148 ( struct V_14 * V_15 ,
unsigned long V_161 )
{
struct V_114 * V_115 = F_42 ( V_15 ) ;
const struct V_8 * V_17 = NULL ;
struct V_30 * V_31 ;
T_3 V_448 , V_449 ;
int V_97 ;
if ( V_161 < F_149 ( V_450 ) )
V_17 = & V_450 [ V_161 ] ;
if ( ! V_17 )
return - V_451 ;
V_15 -> V_18 = V_17 ;
V_31 = F_150 ( V_15 , sizeof( * V_31 ) ) ;
if ( ! V_31 )
return - V_120 ;
V_97 = F_151 ( V_15 ) ;
if ( V_97 )
return V_97 ;
F_152 ( V_115 ) ;
V_15 -> V_452 = V_17 -> V_453 ;
V_31 -> V_454 = F_153 ( V_115 , 2 ) ;
V_31 -> V_455 = F_153 ( V_115 , 3 ) ;
V_31 -> V_35 = F_154 ( V_115 , 0 ) ;
V_31 -> V_45 = F_154 ( V_115 , 2 ) ;
V_15 -> V_190 = F_154 ( V_115 , 3 ) ;
if ( ! V_31 -> V_35 || ! V_31 -> V_45 || ! V_15 -> V_190 ) {
F_155 ( V_15 -> V_28 , L_17 ) ;
return - V_120 ;
}
V_448 = F_34 ( V_31 -> V_35 + V_456 ) &
V_457 ;
V_449 = F_34 ( V_31 -> V_35 + V_458 ) &
V_448 & V_459 ;
V_31 -> V_133 = ( ( T_3 ) V_31 -> V_454 &
~ V_448 ) | V_449 ;
V_448 = F_34 ( V_31 -> V_35 + V_460 ) &
V_457 ;
V_449 = F_34 ( V_31 -> V_35 + V_461 ) &
V_448 & V_459 ;
V_31 -> V_131 = ( ( T_3 ) V_31 -> V_455 &
~ V_448 ) | V_449 ;
V_97 = F_41 ( V_15 ) ;
if ( V_97 < 0 )
return V_97 ;
V_31 -> F_20 =
F_20 ( V_15 , F_57 ( V_31 -> V_45 + V_163 ) ) ;
F_64 ( V_15 -> V_28 , L_18 ,
V_31 -> F_20 ) ;
F_33 ( V_15 ) ;
F_40 ( V_15 ) ;
V_97 = F_156 ( V_115 -> V_342 , F_113 , V_462 ,
V_15 -> V_452 , V_15 ) ;
if ( V_97 ) {
F_64 ( V_15 -> V_28 , L_19 ,
V_115 -> V_342 ) ;
return V_97 ;
}
V_15 -> V_342 = V_115 -> V_342 ;
F_64 ( V_15 -> V_28 , L_20 , V_15 -> V_342 ) ;
V_97 = F_143 ( V_15 ) ;
if ( V_97 < 0 )
return V_97 ;
return 0 ;
}
static void F_157 ( struct V_14 * V_15 )
{
struct V_30 * V_31 = V_15 -> V_32 ;
if ( V_15 -> V_342 )
F_158 ( V_15 -> V_342 , V_15 ) ;
if ( V_31 ) {
if ( V_31 -> V_35 ) {
F_28 ( V_15 ) ;
F_159 ( V_31 -> V_35 ) ;
}
if ( V_31 -> V_45 )
F_159 ( V_31 -> V_45 ) ;
if ( V_15 -> V_190 )
F_159 ( V_15 -> V_190 ) ;
}
F_160 ( V_15 ) ;
F_45 ( V_15 ) ;
}
static int F_161 ( struct V_114 * V_15 ,
const struct V_463 * V_202 )
{
return F_162 ( V_15 , & V_464 ,
V_202 -> V_465 ) ;
}
