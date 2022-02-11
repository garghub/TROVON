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
const struct V_23 * V_24 =
& V_17 -> V_25 -> V_24 [ V_22 ] ;
unsigned int V_26 = 0 ;
switch ( V_24 -> V_27 ) {
case 10000000 :
V_26 = 0x000 ;
break;
case 5000000 :
V_26 = 0x100 ;
break;
case 2000000 :
case 2500000 :
V_26 = 0x200 ;
break;
case 1000000 :
case 1250000 :
V_26 = 0x300 ;
break;
case 500000 :
V_26 = 0x400 ;
break;
case 200000 :
case 250000 :
V_26 = 0x500 ;
break;
case 100000 :
V_26 = 0x600 ;
break;
case 50000 :
V_26 = 0x700 ;
break;
default:
F_20 ( V_15 -> V_28 , L_1 , V_29 ) ;
break;
}
if ( V_24 -> V_30 == 0 )
V_26 += 0x900 ;
return V_26 ;
}
static unsigned int F_21 ( const struct V_14 * V_15 ,
T_1 V_5 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
if ( V_17 -> V_10 == V_11 )
return ( V_5 >> 13 ) & 0x7 ;
return ( V_5 >> 12 ) & 0xf ;
}
static void F_22 ( struct V_14 * V_15 ,
T_1 * V_26 , unsigned int V_1 ,
unsigned int V_24 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
unsigned int V_31 = V_17 -> V_32 [ V_24 ] ;
if ( V_1 > 1 )
F_20 ( V_15 -> V_28 , L_2 ) ;
if ( V_31 & ~ 0x3 )
F_20 ( V_15 -> V_28 , L_3 ) ;
* V_26 &= ~ ( 0x3 << ( 2 * V_1 ) ) ;
* V_26 |= V_31 << ( 2 * V_1 ) ;
}
static inline int F_23 ( const struct V_8 * V_9 )
{
return V_9 -> V_33 && V_9 -> V_10 != V_11 ;
}
static void F_24 ( struct V_14 * V_15 , unsigned int V_1 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
unsigned long V_37 ;
F_25 ( & V_15 -> V_38 , V_37 ) ;
F_26 ( V_35 -> V_39 , V_1 ) ;
F_27 ( & V_15 -> V_38 , V_37 ) ;
}
static void F_28 ( struct V_14 * V_15 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
V_35 -> V_40 = 0 ;
F_29 ( V_35 -> V_40 ,
V_35 -> V_39 + V_41 ) ;
}
static void F_30 ( struct V_14 * V_15 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
unsigned long V_37 ;
F_25 ( & V_15 -> V_38 , V_37 ) ;
V_35 -> V_42 &=
~ V_43 & ~ V_44 &
~ V_45 & ~ V_46 &
~ V_47 & ~ V_48 ;
F_31 ( V_35 -> V_42 ,
V_35 -> V_49 + V_50 ) ;
F_27 ( & V_15 -> V_38 , V_37 ) ;
}
static void F_32 ( struct V_14 * V_15 ,
const struct V_51 * V_52 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_34 * V_35 = V_15 -> V_36 ;
T_3 V_26 ;
unsigned long V_37 ;
V_26 = V_47 | V_44 |
V_45 | V_46 ;
if ( V_52 -> V_37 & V_53 ) {
if ( V_17 -> V_10 != V_11 )
V_26 |= V_54 | V_43 ;
}
F_25 ( & V_15 -> V_38 , V_37 ) ;
V_35 -> V_42 |= V_26 ;
F_31 ( V_35 -> V_42 ,
V_35 -> V_49 + V_50 ) ;
F_27 ( & V_15 -> V_38 , V_37 ) ;
}
static void F_33 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_34 * V_35 = V_15 -> V_36 ;
T_3 V_26 ;
void T_4 * V_55 = V_35 -> V_39 ;
V_35 -> V_56 =
F_34 ( V_35 -> V_39 + V_57 ) ;
#ifdef F_35
V_26 = V_58 | V_59 ;
#else
V_26 = 0 ;
#endif
F_29 ( V_26 , V_35 -> V_39 + V_60 ) ;
F_28 ( V_15 ) ;
F_24 ( V_15 , 0 ) ;
F_24 ( V_15 , 1 ) ;
V_26 = 0 ;
V_26 |= V_61 ;
V_26 |= V_62 ;
V_26 |= V_63 ;
V_26 |= V_64 ;
V_26 |= V_65 ;
V_26 |= V_66 ;
V_26 |= V_67 ;
V_26 |= V_68 ;
if ( V_17 -> V_10 == V_11 )
V_26 |= V_69 ;
else
V_26 |= V_70 ;
F_29 ( V_26 , V_55 + V_71 ) ;
if ( F_23 ( V_17 ) )
F_29 ( V_26 , V_55 + V_72 ) ;
V_35 -> V_40 |=
V_73 | V_74 | V_75 | V_76 | V_77 | V_78 |
V_79 | V_80 ;
F_29 ( V_35 -> V_40 ,
V_35 -> V_39 + V_41 ) ;
}
static void F_36 ( struct V_14 * V_15 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
unsigned long V_37 ;
F_30 ( V_15 ) ;
F_25 ( & V_15 -> V_38 , V_37 ) ;
V_35 -> V_81 &= ~ V_82 ;
F_31 ( V_35 -> V_81 ,
V_35 -> V_49 + V_83 ) ;
F_27 ( & V_15 -> V_38 , V_37 ) ;
F_31 ( V_84 | V_85 | V_86 ,
V_35 -> V_49 + V_87 ) ;
}
static int F_37 ( struct V_14 * V_15 ,
unsigned int V_88 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_34 * V_35 = V_15 -> V_36 ;
static const int V_89 = 0x100 ;
const struct V_90 * const V_91 = V_17 -> V_92 ;
unsigned int V_93 ;
T_1 V_26 ;
if ( V_88 < V_89 )
V_88 = V_89 ;
if ( V_88 > V_91 -> V_94 )
V_88 = V_91 -> V_94 ;
V_93 = ( V_88 + V_89 / 2 ) / V_89 ;
V_26 = ( ~ ( V_93 - 1 ) ) & V_91 -> V_95 ;
V_35 -> V_96 &= ~ V_91 -> V_95 ;
V_35 -> V_96 |= V_26 ;
F_31 ( V_35 -> V_96 ,
V_35 -> V_49 + V_97 ) ;
V_35 -> V_98 = V_93 * V_89 ;
return V_35 -> V_98 ;
}
static int F_38 ( struct V_14 * V_15 , unsigned int V_99 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
unsigned int V_100 ;
int V_101 ;
const struct V_90 * const V_91 = V_17 -> V_92 ;
V_100 = V_99 / V_91 -> V_102 ;
V_101 = F_37 ( V_15 ,
V_100 /
V_91 -> V_103 ) ;
if ( V_101 < 0 )
return V_101 ;
V_99 = V_101 * V_91 -> V_103 * V_91 -> V_102 ;
return V_99 ;
}
static unsigned int F_39 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_34 * V_35 = V_15 -> V_36 ;
return V_35 -> V_98 *
V_17 -> V_92 -> V_103 *
V_17 -> V_92 -> V_102 ;
}
static void F_40 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_34 * V_35 = V_15 -> V_36 ;
T_1 V_26 ;
unsigned long V_37 ;
F_25 ( & V_15 -> V_38 , V_37 ) ;
if ( 1 )
V_35 -> V_81 |= V_104 ;
F_31 ( V_35 -> V_81 ,
V_35 -> V_49 + V_83 ) ;
F_31 ( 0xff , V_35 -> V_49 + V_105 ) ;
V_26 = V_106 | V_107 ;
if ( V_17 -> V_10 == V_11 )
V_26 |= V_108 ;
V_35 -> V_109 |= V_26 ;
F_31 ( V_35 -> V_109 ,
V_35 -> V_49 + V_110 ) ;
F_31 ( 0 , V_35 -> V_49 + V_111 ) ;
F_31 ( 0 , V_35 -> V_49 + V_112 ) ;
F_27 ( & V_15 -> V_38 , V_37 ) ;
V_35 -> V_96 |= V_113 ;
F_37 ( V_15 ,
V_17 -> V_92 -> V_94 ) ;
V_35 -> V_114 = V_115 ;
V_35 -> V_42 =
V_116 | V_117 ;
F_31 ( V_35 -> V_42 ,
V_35 -> V_49 + V_50 ) ;
F_36 ( V_15 ) ;
}
static int F_41 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_118 * V_119 = F_42 ( V_15 ) ;
struct V_34 * V_35 = V_15 -> V_36 ;
int V_120 ;
for ( V_120 = 0 ; V_120 < F_17 ( V_17 ) ; V_120 ++ ) {
V_35 -> V_121 [ V_120 ] =
F_43 ( V_119 , V_122 ,
& V_35 -> V_123 [ V_120 ] ) ;
if ( V_35 -> V_121 [ V_120 ] == NULL )
return - V_124 ;
}
for ( V_120 = 0 ; V_120 < V_125 ; V_120 ++ ) {
if ( F_23 ( V_17 ) ) {
V_35 -> V_126 [ V_120 ] =
F_43 ( V_119 , V_122 ,
& V_35 ->
V_127 [ V_120 ] ) ;
if ( V_35 -> V_126 [ V_120 ] == NULL )
return - V_124 ;
}
}
V_35 -> V_128 =
F_43 ( V_119 , sizeof( struct V_129 ) *
F_17 ( V_17 ) ,
& V_35 -> V_130 ) ;
if ( V_35 -> V_128 == NULL )
return - V_124 ;
if ( F_23 ( V_17 ) ) {
V_35 -> V_131 =
F_43 ( V_119 ,
sizeof( struct V_129 ) *
V_125 ,
& V_35 -> V_132 ) ;
if ( V_35 -> V_131 == NULL )
return - V_124 ;
}
for ( V_120 = 0 ; V_120 < F_17 ( V_17 ) ; V_120 ++ ) {
V_35 -> V_128 [ V_120 ] . V_133 =
F_44 ( V_35 -> V_123 [ V_120 ] ) ;
if ( V_17 -> V_10 == V_11 )
V_35 -> V_128 [ V_120 ] . V_134 =
F_44 ( V_35 -> V_135 +
V_136 ) ;
else
V_35 -> V_128 [ V_120 ] . V_134 =
F_44 ( V_35 -> V_137 +
V_136 ) ;
V_35 -> V_128 [ V_120 ] . V_138 = F_44 ( 0 ) ;
V_35 -> V_128 [ V_120 ] . V_139 =
F_44 ( ( V_35 -> V_130 +
( ( V_120 + 1 ) % F_17 ( V_17 ) ) *
sizeof( V_35 -> V_128 [ 0 ] ) ) |
V_140 | V_141 |
V_142 ) ;
}
if ( F_23 ( V_17 ) ) {
for ( V_120 = 0 ; V_120 < V_125 ; V_120 ++ ) {
V_35 -> V_131 [ V_120 ] . V_133 =
F_44 ( V_35 -> V_127 [ V_120 ] ) ;
V_35 -> V_131 [ V_120 ] . V_134 =
F_44 ( V_35 -> V_137 +
V_143 ) ;
V_35 -> V_131 [ V_120 ] . V_138 = F_44 ( 0 ) ;
V_35 -> V_131 [ V_120 ] . V_139 =
F_44 ( ( V_35 -> V_132 +
( ( V_120 + 1 ) % ( V_125 ) ) *
sizeof( V_35 -> V_131 [ 0 ] ) ) |
V_140 |
V_141 ) ;
}
}
return 0 ;
}
static void F_45 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_118 * V_119 = F_42 ( V_15 ) ;
struct V_34 * V_35 = V_15 -> V_36 ;
int V_120 ;
if ( ! V_35 )
return;
for ( V_120 = 0 ; V_120 < F_17 ( V_17 ) ; V_120 ++ ) {
if ( V_35 -> V_121 [ V_120 ] )
F_46 ( V_119 ,
V_122 ,
V_35 -> V_121 [ V_120 ] ,
V_35 -> V_123 [ V_120 ] ) ;
}
for ( V_120 = 0 ; V_120 < V_125 ; V_120 ++ ) {
if ( V_35 -> V_126 [ V_120 ] )
F_46 ( V_119 ,
V_122 ,
V_35 -> V_126 [ V_120 ] ,
V_35 -> V_127 [ V_120 ] ) ;
}
if ( V_35 -> V_128 )
F_46 ( V_119 ,
sizeof( struct V_129 ) *
F_17 ( V_17 ) ,
V_35 -> V_128 ,
V_35 -> V_130 ) ;
if ( V_35 -> V_131 )
F_46 ( V_119 ,
sizeof( struct V_129 ) *
V_125 ,
V_35 -> V_131 ,
V_35 -> V_132 ) ;
}
static inline void F_47 ( struct V_14 * V_15 )
{
F_20 ( V_15 -> V_28 ,
L_4 ) ;
F_20 ( V_15 -> V_28 ,
L_5 ) ;
}
static void F_48 ( struct V_14 * V_15 , int V_144 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
static const int V_145 = V_146 ;
void T_4 * V_147 = V_35 -> V_39 +
V_57 ;
if ( V_144 ) {
V_35 -> V_56 &= ~ V_145 ;
F_29 ( V_35 -> V_56 , V_147 ) ;
F_49 ( V_148 ) ;
} else {
V_35 -> V_56 |= V_145 ;
F_29 ( V_35 -> V_56 , V_147 ) ;
F_49 ( V_149 ) ;
}
}
static void F_50 ( struct V_14 * V_15 , int V_144 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
static const int V_150 = V_151 ;
void T_4 * V_147 = V_35 -> V_39 +
V_57 ;
if ( V_144 ) {
V_35 -> V_56 &= ~ V_150 ;
F_29 ( V_35 -> V_56 , V_147 ) ;
F_49 ( V_148 ) ;
} else {
V_35 -> V_56 |= V_150 ;
F_29 ( V_35 -> V_56 , V_147 ) ;
F_49 ( V_149 ) ;
}
}
static void F_51 ( struct V_14 * V_15 , T_2 V_152 )
{
T_2 V_153 ;
unsigned int V_154 = 8 ;
for ( V_153 = 1 << ( V_154 - 1 ) ; V_153 ; V_153 >>= 1 ) {
F_50 ( V_15 , 0 ) ;
if ( ( V_152 & V_153 ) )
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
static void F_55 ( struct V_14 * V_15 , unsigned int V_155 ,
const T_2 * V_156 , unsigned int V_157 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
unsigned int V_120 ;
T_2 V_158 ;
static const int V_159 = 0x1 ;
V_35 -> V_56 &= ~ V_160 ;
F_54 ( V_15 ) ;
F_53 ( V_15 ) ;
V_158 = ( V_155 << 1 ) & ~ V_159 ;
F_51 ( V_15 , V_158 ) ;
if ( F_52 ( V_15 ) != 0 ) {
F_20 ( V_15 -> V_28 , L_6 ,
V_29 ) ;
F_54 ( V_15 ) ;
return;
}
for ( V_120 = 0 ; V_120 < V_157 ; V_120 ++ ) {
F_51 ( V_15 , V_156 [ V_120 ] ) ;
if ( F_52 ( V_15 ) != 0 ) {
F_20 ( V_15 -> V_28 , L_6 ,
V_29 ) ;
F_54 ( V_15 ) ;
return;
}
}
F_54 ( V_15 ) ;
}
static int F_56 ( struct V_14 * V_15 ,
struct V_161 * V_162 ,
struct V_163 * V_164 ,
unsigned long V_165 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_34 * V_35 = V_15 -> V_36 ;
unsigned int V_166 ;
V_166 = F_57 ( V_35 -> V_49 + V_167 ) ;
if ( V_17 -> V_10 == V_11 ) {
V_166 = F_57 ( V_35 -> V_49 + V_168 ) ;
if ( V_166 )
return 0 ;
} else {
if ( F_11 ( V_166 ) )
return 0 ;
}
return - V_169 ;
}
static int F_58 ( struct V_14 * V_15 , struct V_161 * V_162 ,
struct V_163 * V_164 , unsigned int * V_156 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_34 * V_35 = V_15 -> V_36 ;
unsigned int V_26 = 0 , V_170 ;
unsigned int V_1 , V_24 , V_171 ;
unsigned long V_37 ;
int V_172 ;
V_1 = F_59 ( V_164 -> V_173 ) ;
V_24 = F_60 ( V_164 -> V_173 ) ;
V_171 = F_61 ( V_164 -> V_173 ) ;
F_36 ( V_15 ) ;
F_25 ( & V_15 -> V_38 , V_37 ) ;
if ( V_164 -> V_173 & V_174 )
V_35 -> V_81 |= V_175 ;
else
V_35 -> V_81 &= ~ V_175 ;
F_31 ( V_35 -> V_81 ,
V_35 -> V_49 + V_83 ) ;
F_27 ( & V_15 -> V_38 , V_37 ) ;
if ( V_17 -> V_10 != V_11 ) {
V_35 -> V_109 &= ~ V_176 ;
F_31 ( V_35 -> V_109 ,
V_35 -> V_49 + V_110 ) ;
if ( V_164 -> V_173 & V_177 ) {
unsigned int V_178 ;
if ( V_17 -> V_10 == V_20 )
V_178 = V_179 ;
else
V_178 = V_180 ;
F_31 ( V_178 |
F_8 ( V_35 -> V_181 ) ,
V_35 -> V_49 + V_112 ) ;
} else {
F_31 ( 0 , V_35 -> V_49 + V_112 ) ;
}
V_26 = 0 ;
V_26 |= F_19 ( V_15 , F_60 ( V_164 -> V_173 ) ) ;
V_26 |= F_18 ( V_15 , V_171 == V_182 ) ;
if ( V_171 == V_183 )
V_26 |= V_184 ;
V_26 |= F_10 ( V_1 ) ;
F_31 ( F_10 ( V_1 ) ,
V_35 -> V_49 + V_185 ) ;
F_31 ( V_26 , V_35 -> V_49 + V_186 ) ;
} else {
T_2 V_187 = V_35 -> V_188 ;
V_35 -> V_188 &= ~ V_7 ;
if ( V_164 -> V_173 & V_177 ) {
V_35 -> V_188 |=
F_15 ( V_35 -> V_181 ) ;
} else {
V_35 -> V_188 |= F_15 ( 4 ) ;
}
if ( V_24 == 0 )
V_35 -> V_188 |= F_16 ( V_1 ) ;
else
V_35 -> V_188 &= ~ F_16 ( V_1 ) ;
if ( V_187 != V_35 -> V_188 ) {
T_2 V_189 = V_35 -> V_188 ;
F_55 ( V_15 , V_190 , & V_189 ,
sizeof( V_189 ) ) ;
}
F_31 ( 0 , V_35 -> V_49 + V_105 ) ;
F_31 ( 2 , V_35 -> V_49 + V_191 ) ;
}
for ( V_170 = 0 ; V_170 < V_164 -> V_170 ; V_170 ++ ) {
F_31 ( 0 , V_35 -> V_49 + V_192 ) ;
F_31 ( F_9 ( F_59 ( V_164 -> V_173 ) ) ,
V_35 -> V_49 + V_193 ) ;
V_172 = F_62 ( V_15 , V_162 , V_164 , F_56 , 0 ) ;
if ( V_172 )
return V_172 ;
if ( V_17 -> V_10 == V_11 )
V_156 [ V_170 ] = F_34 ( V_15 -> V_194 + V_136 ) & 0xffff ;
else
V_156 [ V_170 ] = F_57 ( V_35 -> V_49 + V_195 ) ;
}
return V_170 ;
}
static int F_63 ( struct V_14 * V_15 ,
unsigned int * V_156 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_34 * V_35 = V_15 -> V_36 ;
unsigned int V_4 = V_156 [ 1 ] ;
int V_196 ;
if ( V_17 -> V_10 == V_20 )
V_196 = 16 ;
else
V_196 = 8 ;
if ( V_4 >= V_196 ) {
F_64 ( V_15 -> V_28 , L_7 ,
V_4 ) ;
return - V_197 ;
}
V_35 -> V_181 = V_4 ;
return 2 ;
}
static int F_65 ( struct V_14 * V_15 , unsigned int * V_156 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
int V_198 ;
const struct V_90 * const V_91 = V_17 -> V_92 ;
unsigned int V_199 , V_200 ;
int V_101 ;
V_200 = V_156 [ 1 ] ;
if ( V_200 ) {
V_198 = V_200 * V_91 -> V_103 /
V_201 ;
V_101 = F_38 ( V_15 , V_198 ) ;
if ( V_101 < 0 )
return V_101 ;
}
V_199 = F_39 ( V_15 ) / V_91 -> V_103 * V_201 ;
V_156 [ 1 ] = V_199 ;
return 2 ;
}
static int F_66 ( struct V_14 * V_15 ,
unsigned int * V_156 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
unsigned int V_202 = V_156 [ 4 ] ;
int V_101 = 0 ;
if ( V_202 < 2 ) {
V_202 = 2 ;
V_101 = - V_203 ;
}
switch ( V_156 [ 1 ] ) {
case V_204 :
V_35 -> V_205 . V_202 = V_202 ;
V_35 -> V_205 . V_173 = V_156 [ 2 ] ;
break;
default:
return - V_197 ;
}
V_156 [ 4 ] = V_202 ;
return V_101 ? V_101 : 5 ;
}
static int F_67 ( struct V_14 * V_15 , unsigned int * V_156 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
switch ( V_17 -> V_10 ) {
case V_11 :
return F_66 ( V_15 , V_156 ) ;
default:
return - V_197 ;
}
return - V_197 ;
}
static int F_68 ( struct V_14 * V_15 , struct V_161 * V_162 ,
struct V_163 * V_164 , unsigned int * V_156 )
{
int V_206 = V_156 [ 0 ] ;
switch ( V_206 ) {
case V_207 :
return F_63 ( V_15 , V_156 ) ;
case V_208 :
return F_65 ( V_15 , V_156 ) ;
case V_209 :
return F_67 ( V_15 , V_156 ) ;
default:
return - V_197 ;
}
return - V_197 ;
}
static unsigned int F_69 ( unsigned int V_210 , unsigned int V_37 )
{
unsigned int V_202 ;
switch ( V_37 & V_211 ) {
case V_212 :
V_202 = ( V_210 + V_213 - 1 ) / V_213 ;
break;
case V_214 :
V_202 = V_210 / V_213 ;
break;
case V_215 :
default:
V_202 = ( V_210 + V_213 / 2 ) / V_213 ;
break;
}
return V_202 ;
}
static void F_70 ( struct V_14 * V_15 , struct V_51 * V_52 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
unsigned int V_216 = 0 , V_217 ;
static const int V_218 = 3 ;
static const int V_219 =
V_220 + V_218 ;
static const int V_221 = 2 ;
unsigned long long V_222 , V_223 ;
if ( V_52 -> V_224 == V_225 ) {
if ( V_17 -> V_10 == V_11 ) {
V_52 -> V_226 = 0 ;
} else {
V_216 = F_69 ( V_52 -> V_226 ,
V_52 -> V_37 ) ;
if ( V_216 > V_219 )
V_216 = V_219 ;
if ( V_216 < V_218 )
V_216 = V_218 ;
V_52 -> V_226 = V_216 * V_213 ;
}
} else if ( V_52 -> V_224 == V_227 ) {
V_52 -> V_226 = 0 ;
}
if ( V_52 -> V_228 == V_225 ) {
V_217 = F_69 ( V_52 -> V_229 , V_52 -> V_37 ) ;
if ( V_52 -> V_224 == V_225 ) {
V_223 = V_216 * V_52 -> V_230 ;
V_222 =
( V_216 * V_52 -> V_230 - 1 ) +
V_220 ;
} else {
V_223 = V_221 ;
V_222 = V_220 + V_223 ;
}
if ( V_217 > V_222 )
V_217 = V_222 ;
if ( V_217 < V_223 )
V_217 = V_223 ;
V_52 -> V_229 = V_217 * V_213 ;
}
}
static int F_71 ( struct V_14 * V_15 ,
struct V_161 * V_162 ,
struct V_51 * V_52 )
{
const struct V_8 * V_9 = V_15 -> V_18 ;
unsigned int V_231 = F_61 ( V_52 -> V_232 [ 0 ] ) ;
int V_120 ;
for ( V_120 = 1 ; V_120 < V_52 -> V_230 ; V_120 ++ ) {
unsigned int V_171 = F_61 ( V_52 -> V_232 [ V_120 ] ) ;
if ( V_171 != V_231 ) {
F_64 ( V_15 -> V_28 ,
L_8 ) ;
return - V_197 ;
}
}
if ( V_9 -> V_10 == V_11 ) {
unsigned int V_233 = F_59 ( V_52 -> V_232 [ 0 ] ) ;
for ( V_120 = 1 ; V_120 < V_52 -> V_230 ; V_120 ++ ) {
unsigned int V_234 = F_59 ( V_52 -> V_232 [ V_120 ] ) ;
if ( V_234 != ( V_233 + V_120 ) ) {
F_64 ( V_15 -> V_28 ,
L_9 ) ;
return - V_197 ;
}
}
if ( V_52 -> V_230 == 3 ) {
F_64 ( V_15 -> V_28 ,
L_10 ) ;
return - V_197 ;
}
}
return 0 ;
}
static int F_72 ( struct V_14 * V_15 , struct V_161 * V_162 ,
struct V_51 * V_52 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
int V_235 = 0 ;
unsigned int V_236 , V_237 ;
unsigned int V_238 ;
V_235 |= F_73 ( & V_52 -> V_239 , V_227 | V_240 ) ;
V_238 = V_225 ;
if ( V_17 -> V_10 == V_11 )
V_238 |= V_241 ;
else
V_238 |= V_242 ;
V_235 |= F_73 ( & V_52 -> V_228 , V_238 ) ;
V_238 = V_225 ;
if ( V_17 -> V_10 == V_11 )
V_238 |= V_227 ;
else
V_238 |= V_240 ;
V_235 |= F_73 ( & V_52 -> V_224 , V_238 ) ;
V_235 |= F_73 ( & V_52 -> V_243 , V_244 ) ;
V_235 |= F_73 ( & V_52 -> V_245 ,
V_244 | V_240 | V_246 ) ;
if ( V_235 )
return 1 ;
V_235 |= F_74 ( V_52 -> V_239 ) ;
V_235 |= F_74 ( V_52 -> V_228 ) ;
V_235 |= F_74 ( V_52 -> V_224 ) ;
V_235 |= F_74 ( V_52 -> V_245 ) ;
if ( V_52 -> V_224 == V_240 && V_52 -> V_228 == V_225 )
V_235 |= - V_197 ;
if ( V_235 )
return 2 ;
switch ( V_52 -> V_239 ) {
case V_227 :
V_235 |= F_75 ( & V_52 -> V_247 , 0 ) ;
break;
case V_240 :
break;
}
if ( V_52 -> V_224 == V_225 ) {
if ( V_17 -> V_10 == V_11 ) {
V_235 |= F_75 ( & V_52 -> V_226 , 0 ) ;
} else {
V_235 |= F_76 ( & V_52 -> V_226 ,
V_17 -> V_248 ) ;
if ( V_52 -> V_228 == V_225 )
V_235 |= F_76 (
& V_52 -> V_229 ,
V_52 -> V_226 *
V_52 -> V_230 ) ;
}
}
V_235 |= F_76 ( & V_52 -> V_230 , 1 ) ;
V_235 |= F_75 ( & V_52 -> V_249 , V_52 -> V_230 ) ;
switch ( V_52 -> V_245 ) {
case V_240 :
break;
case V_244 :
V_235 |= F_76 ( & V_52 -> V_250 , 1 ) ;
break;
case V_246 :
V_235 |= F_75 ( & V_52 -> V_250 , 0 ) ;
break;
default:
break;
}
if ( V_235 )
return 3 ;
if ( V_52 -> V_224 == V_225 ) {
V_236 = V_52 -> V_226 ;
V_237 = V_52 -> V_229 ;
F_70 ( V_15 , V_52 ) ;
if ( V_236 != V_52 -> V_226 )
V_235 ++ ;
if ( V_237 != V_52 -> V_229 )
V_235 ++ ;
}
if ( V_235 )
return 4 ;
if ( V_52 -> V_232 && V_52 -> V_230 > 0 )
V_235 |= F_71 ( V_15 , V_162 , V_52 ) ;
if ( V_235 )
return 5 ;
return 0 ;
}
static int F_77 ( struct V_51 * V_52 )
{
return 0 ;
if ( V_52 -> V_245 == V_244 && V_52 -> V_250 <= V_220 )
return 1 ;
return 0 ;
}
static void F_78 ( struct V_14 * V_15 ,
struct V_51 * V_52 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
if ( V_52 -> V_245 == V_244 ) {
V_35 -> V_251 = V_52 -> V_250 * V_52 -> V_230 ;
}
if ( F_77 ( V_52 ) ) {
F_31 ( V_52 -> V_250 & 0xffff ,
V_35 -> V_49 + V_252 ) ;
F_31 ( ( V_52 -> V_250 >> 16 ) & 0xff ,
V_35 -> V_49 + V_253 ) ;
} else {
F_31 ( 1 , V_35 -> V_49 + V_252 ) ;
}
}
static inline unsigned int F_79 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_34 * V_35 = V_15 -> V_36 ;
unsigned int V_99 ;
V_99 = V_35 -> V_98 *
V_17 -> V_92 -> V_102 ;
if ( V_99 > V_122 / sizeof( T_1 ) )
V_99 = V_122 / sizeof( T_1 ) ;
return V_99 ;
}
static T_3 F_80 ( const struct V_14 * V_15 ,
const struct V_51 * V_52 )
{
return V_52 -> V_226 / V_213 - 3 ;
}
static T_3 F_81 ( struct V_14 * V_15 ,
struct V_51 * V_52 )
{
T_3 V_254 ;
switch ( V_52 -> V_228 ) {
case V_225 :
V_254 = ( V_52 -> V_229 -
( V_52 -> V_226 * ( V_52 -> V_230 - 1 ) ) ) /
V_213 ;
break;
case V_242 :
V_254 = V_52 -> V_226 / V_213 ;
break;
default:
return 0 ;
}
return V_254 - 3 ;
}
static T_3 F_82 ( struct V_14 * V_15 ,
struct V_51 * V_52 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
unsigned int V_202 ;
switch ( V_52 -> V_228 ) {
case V_225 :
V_202 = V_52 -> V_229 / V_213 ;
break;
case V_241 :
V_202 = V_35 -> V_205 . V_202 ;
break;
default:
F_20 ( V_15 -> V_28 , L_11 ) ;
V_202 = 1000 ;
break;
}
return V_202 - 2 ;
}
static void F_83 ( struct V_14 * V_15 ,
const struct V_51 * V_52 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
V_35 -> V_109 &= ~ V_255 ;
if ( V_52 -> V_228 == V_241 ) {
int V_173 = V_35 -> V_205 . V_173 ;
if ( F_59 ( V_173 ) )
V_35 -> V_109 |= V_256 ;
else
V_35 -> V_109 |= V_257 ;
} else {
V_35 -> V_109 |= V_108 ;
}
F_31 ( V_35 -> V_109 ,
V_35 -> V_49 + V_110 ) ;
}
static void F_84 ( struct V_14 * V_15 ,
const struct V_51 * V_52 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
switch ( V_17 -> V_10 ) {
case V_11 :
F_83 ( V_15 , V_52 ) ;
break;
default:
break;
}
}
static inline void F_85 ( struct V_14 * V_15 ,
unsigned int V_1 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
unsigned long V_37 ;
F_25 ( & V_15 -> V_38 , V_37 ) ;
if ( V_1 )
F_86 ( V_258 | V_259 |
V_260 ,
V_35 -> V_39 + V_261 ) ;
else
F_86 ( V_258 | V_259 |
V_260 ,
V_35 -> V_39 + V_262 ) ;
F_27 ( & V_15 -> V_38 , V_37 ) ;
}
static void F_87 ( struct V_14 * V_15 , struct V_51 * V_52 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_34 * V_35 = V_15 -> V_36 ;
T_3 V_263 = 0 , V_264 = 0 ;
F_70 ( V_15 , V_52 ) ;
F_84 ( V_15 , V_52 ) ;
if ( V_17 -> V_10 == V_11 ) {
V_263 = F_82 ( V_15 , V_52 ) ;
} else {
V_263 = F_80 ( V_15 , V_52 ) ;
V_264 = F_81 ( V_15 , V_52 ) ;
}
F_31 ( V_263 & 0xffff ,
V_35 -> V_49 + V_191 ) ;
F_31 ( ( V_263 >> 16 ) & 0xff ,
V_35 -> V_49 + V_105 ) ;
F_31 ( V_264 & 0xffff ,
V_35 -> V_49 + V_265 ) ;
F_31 ( ( V_264 >> 16 ) & 0xff ,
V_35 -> V_49 + V_266 ) ;
}
static int F_88 ( const struct V_51 * V_52 )
{
int V_120 ;
for ( V_120 = 0 ; V_120 + 1 < V_52 -> V_230 ; V_120 ++ ) {
if ( F_59 ( V_52 -> V_232 [ V_120 + 1 ] ) !=
F_59 ( V_52 -> V_232 [ V_120 ] ) + 1 )
return 0 ;
if ( F_60 ( V_52 -> V_232 [ V_120 + 1 ] ) !=
F_60 ( V_52 -> V_232 [ V_120 ] ) )
return 0 ;
if ( F_61 ( V_52 -> V_232 [ V_120 + 1 ] ) != F_61 ( V_52 -> V_232 [ V_120 ] ) )
return 0 ;
}
return 1 ;
}
static int F_89 ( struct V_14 * V_15 ,
const struct V_51 * V_52 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_34 * V_35 = V_15 -> V_36 ;
unsigned short V_26 ;
int V_120 ;
if ( V_17 -> V_10 != V_11 ) {
if ( F_88 ( V_52 ) ) {
V_35 -> V_109 &= ~ V_176 ;
F_31 ( V_35 -> V_109 ,
V_35 -> V_49 + V_110 ) ;
V_26 = 0 ;
V_26 |= F_10 ( F_59 ( V_52 -> V_232 [ 0 ] ) ) ;
V_26 |= F_19 ( V_15 ,
F_60 ( V_52 -> V_232 [ 0 ] ) ) ;
V_26 |= F_18 ( V_15 ,
F_61 ( V_52 -> V_232 [ 0 ] ) ==
V_182 ) ;
if ( F_61 ( V_52 -> V_232 [ 0 ] ) == V_183 )
V_26 |= V_184 ;
F_31 ( F_10
( F_59 ( V_52 -> V_232 [ V_52 -> V_230 - 1 ] ) ) ,
V_35 -> V_49 + V_185 ) ;
F_31 ( V_26 ,
V_35 -> V_49 + V_186 ) ;
} else {
if ( V_15 -> V_267 && V_15 -> V_267 -> V_268 ) {
F_47 ( V_15 ) ;
return - V_169 ;
}
V_35 -> V_109 |= V_176 ;
F_31 ( V_35 -> V_109 ,
V_35 -> V_49 + V_110 ) ;
F_31 ( 0 ,
V_35 -> V_49 + V_269 ) ;
F_31 ( 0 , V_35 -> V_49 + V_270 ) ;
for ( V_120 = 0 ; V_120 < V_52 -> V_230 ; V_120 ++ ) {
V_26 = 0 ;
V_26 |= F_10 ( F_59 ( V_52 ->
V_232 [ V_120 ] ) ) ;
V_26 |= F_19 ( V_15 ,
F_60 ( V_52 ->
V_232
[ V_120 ] ) ) ;
V_26 |= F_18 ( V_15 ,
F_61 ( V_52 ->
V_232 [ V_120 ] ) ==
V_182 ) ;
if ( F_61 ( V_52 -> V_232 [ V_120 ] ) == V_183 )
V_26 |= V_184 ;
if ( V_120 == V_52 -> V_230 - 1 )
V_26 |= V_271 |
V_272 ;
F_31 ( V_26 ,
V_35 -> V_49 +
V_273 ) ;
}
F_31 ( 0 , V_35 -> V_49 + V_270 ) ;
F_31 ( 0 , V_35 -> V_49 + V_186 ) ;
}
} else {
unsigned short V_187 = V_35 -> V_188 ;
V_35 -> V_188 &= ~ V_7 ;
V_35 -> V_188 |= F_15 ( 4 ) ;
for ( V_120 = 0 ; V_120 < V_52 -> V_230 ; V_120 ++ ) {
unsigned int V_1 = F_59 ( V_52 -> V_232 [ V_120 ] ) ;
unsigned int V_24 = F_60 ( V_52 -> V_232 [ V_120 ] ) ;
if ( V_24 == 0 )
V_35 -> V_188 |=
F_16 ( V_1 ) ;
else
V_35 -> V_188 &=
~ F_16 ( V_1 ) ;
}
if ( V_187 != V_35 -> V_188 ) {
T_2 V_189 = V_35 -> V_188 ;
F_55 ( V_15 , V_190 , & V_189 ,
sizeof( V_189 ) ) ;
}
}
return 0 ;
}
static inline void F_90 ( struct V_14 * V_15 ,
unsigned int V_274 ,
unsigned int V_275 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
if ( V_274 ) {
F_29 ( 0 ,
V_35 -> V_39 + V_276 ) ;
F_29 ( 0 , V_35 -> V_39 + V_277 ) ;
F_29 ( 0 ,
V_35 -> V_39 + V_278 ) ;
F_29 ( V_275 ,
V_35 -> V_39 + V_279 ) ;
} else {
F_29 ( 0 ,
V_35 -> V_39 + V_280 ) ;
F_29 ( 0 , V_35 -> V_39 + V_281 ) ;
F_29 ( 0 ,
V_35 -> V_39 + V_282 ) ;
F_29 ( V_275 ,
V_35 -> V_39 + V_283 ) ;
}
}
static int F_91 ( struct V_14 * V_15 , struct V_161 * V_162 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_34 * V_35 = V_15 -> V_36 ;
struct V_284 * V_285 = V_162 -> V_285 ;
struct V_51 * V_52 = & V_285 -> V_52 ;
T_3 V_26 ;
unsigned int V_120 ;
unsigned long V_37 ;
int V_101 ;
F_36 ( V_15 ) ;
F_24 ( V_15 , 1 ) ;
V_101 = F_89 ( V_15 , V_52 ) ;
if ( V_101 < 0 )
return V_101 ;
F_31 ( 0 , V_35 -> V_49 + V_112 ) ;
F_87 ( V_15 , V_52 ) ;
F_78 ( V_15 , V_52 ) ;
F_32 ( V_15 , V_52 ) ;
F_25 ( & V_15 -> V_38 , V_37 ) ;
V_35 -> V_81 |= V_82 ;
V_35 -> V_81 &= ~ V_175 ;
if ( V_17 -> V_10 != V_11 ) {
V_35 -> V_81 &= ~ V_286 ;
if ( V_52 -> V_224 == V_240 )
V_35 -> V_81 |= F_7 ( 13 ) ;
else
V_35 -> V_81 |= F_7 ( 8 ) ;
} else {
V_35 -> V_81 &= ~ V_287 ;
if ( V_52 -> V_230 == 4 )
V_35 -> V_81 |= V_288 ;
else if ( V_52 -> V_230 == 2 )
V_35 -> V_81 |= V_289 ;
V_35 -> V_81 &= ~ V_290 ;
V_35 -> V_81 |=
F_5 ( F_59 ( V_52 -> V_232 [ 0 ] ) ) ;
V_35 -> V_81 &= ~ V_291 ;
V_35 -> V_81 |=
F_6 ( F_59 ( V_52 -> V_232
[ V_52 -> V_230 - 1 ] ) ) ;
}
F_31 ( V_35 -> V_81 ,
V_35 -> V_49 + V_83 ) ;
F_27 ( & V_15 -> V_38 , V_37 ) ;
F_31 ( 0 , V_35 -> V_49 + V_192 ) ;
if ( ( V_52 -> V_37 & V_53 ) == 0 ||
V_17 -> V_10 == V_11 ) {
V_35 -> V_292 = 0 ;
for ( V_120 = 0 ; V_120 < F_17 ( V_17 ) ; V_120 ++ )
V_35 -> V_128 [ V_120 ] . V_138 =
F_44 ( F_79 ( V_15 ) *
sizeof( T_1 ) ) ;
F_90 ( V_15 , 1 ,
V_35 -> V_130 |
V_140 |
V_141 |
V_142 ) ;
F_85 ( V_15 , 1 ) ;
}
if ( V_17 -> V_10 == V_11 ) {
V_26 = 0 ;
if ( V_52 -> V_239 == V_240 && F_59 ( V_52 -> V_247 ) )
V_26 |= V_293 ;
if ( V_52 -> V_245 == V_240 && F_59 ( V_52 -> V_250 ) )
V_26 |= V_294 ;
F_31 ( V_26 , V_35 -> V_49 + V_295 ) ;
}
F_25 ( & V_15 -> V_38 , V_37 ) ;
V_26 = V_296 | V_85 | V_86 ;
if ( V_52 -> V_37 & V_53 )
V_26 |= V_84 ;
if ( V_52 -> V_239 == V_240 ) {
V_26 |= V_297 ;
if ( V_52 -> V_247 & V_298 )
V_26 |= V_299 ;
} else if ( V_52 -> V_239 == V_227 )
V_26 |= V_300 ;
if ( F_77 ( V_52 ) )
V_26 |= V_301 ;
F_31 ( V_26 , V_35 -> V_49 + V_87 ) ;
V_35 -> V_302 = 1 ;
F_27 ( & V_15 -> V_38 , V_37 ) ;
if ( V_52 -> V_239 == V_227 )
F_31 ( 0 , V_35 -> V_49 + V_303 ) ;
return 0 ;
}
static void F_92 ( struct V_14 * V_15 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
struct V_161 * V_162 = V_15 -> V_304 ;
struct V_284 * V_285 = V_162 -> V_285 ;
struct V_51 * V_52 = & V_285 -> V_52 ;
unsigned int V_120 ;
T_1 V_6 ;
int V_305 , V_306 , V_307 , V_308 ;
int V_99 ;
do {
V_306 = F_57 ( V_35 -> V_49 + V_309 ) &
0x7fff ;
V_308 = F_57 ( V_35 -> V_49 + V_168 ) &
0x7fff ;
V_6 = F_57 ( V_35 -> V_49 + V_310 ) ;
V_305 = F_13 ( V_6 ) ;
V_307 = F_14 ( V_6 ) ;
if ( V_305 != V_307 )
V_99 =
V_35 -> V_98 - V_306 ;
else
V_99 = V_308 - V_306 ;
if ( V_52 -> V_245 == V_244 ) {
if ( V_35 -> V_251 == 0 )
break;
if ( V_99 > V_35 -> V_251 )
V_99 = V_35 -> V_251 ;
V_35 -> V_251 -= V_99 ;
}
if ( V_99 < 0 ) {
F_20 ( V_15 -> V_28 ,
L_12 ) ;
break;
}
for ( V_120 = 0 ; V_120 < V_99 ; V_120 ++ ) {
F_93 ( V_162 ,
F_57 ( V_35 -> V_49 +
V_136 ) ) ;
}
} while ( V_305 != V_307 );
}
static void F_94 ( struct V_14 * V_15 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
struct V_161 * V_162 = V_15 -> V_304 ;
struct V_284 * V_285 = V_162 -> V_285 ;
struct V_51 * V_52 = & V_285 -> V_52 ;
unsigned int V_120 ;
unsigned int V_311 = 100000 ;
T_3 V_312 ;
int V_313 =
F_57 ( V_35 -> V_49 + V_168 ) & 0x7fff ;
int V_314 =
F_57 ( V_35 -> V_49 + V_309 ) & 0x7fff ;
if ( V_52 -> V_245 == V_244 ) {
if ( V_311 > V_35 -> V_251 )
V_311 = V_35 -> V_251 ;
}
for ( V_120 = 0 ; V_314 != V_313 && V_120 < V_311 ; ) {
V_312 = F_34 ( V_15 -> V_194 + V_136 ) ;
F_93 ( V_162 , V_312 & 0xffff ) ;
V_120 ++ ;
if ( V_120 < V_311 ) {
F_93 ( V_162 , ( V_312 >> 16 ) & 0xffff ) ;
V_120 ++ ;
}
V_314 = F_57 ( V_35 -> V_49 + V_309 ) &
0x7fff ;
}
V_35 -> V_251 -= V_120 ;
}
static void F_95 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
if ( V_17 -> V_10 == V_11 )
F_94 ( V_15 ) ;
else
F_92 ( V_15 ) ;
}
static void F_96 ( struct V_14 * V_15 , unsigned int V_1 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_34 * V_35 = V_15 -> V_36 ;
struct V_284 * V_285 = V_15 -> V_304 -> V_285 ;
struct V_51 * V_52 = & V_285 -> V_52 ;
T_3 V_315 ;
int V_316 ;
int V_99 = 0 ;
void T_4 * V_317 ;
if ( V_1 )
V_317 =
V_35 -> V_39 + V_277 ;
else
V_317 =
V_35 -> V_39 + V_281 ;
for ( V_316 = 0 , V_315 = F_34 ( V_317 ) ;
( V_315 <
V_35 -> V_123 [ V_35 -> V_292 ] ||
V_315 >=
V_35 -> V_123 [ V_35 -> V_292 ] +
V_122 ) && V_316 < F_17 ( V_17 ) ; V_316 ++ ) {
V_99 = F_79 ( V_15 ) ;
if ( V_52 -> V_245 == V_244 ) {
if ( V_99 > V_35 -> V_251 )
V_99 = V_35 -> V_251 ;
V_35 -> V_251 -= V_99 ;
}
F_97 ( V_15 -> V_304 ,
V_35 -> V_121 [ V_35 ->
V_292 ] ,
V_99 * sizeof( T_1 ) ) ;
V_35 -> V_292 = ( V_35 -> V_292 + 1 ) %
F_17 ( V_17 ) ;
}
}
static void F_98 ( struct V_14 * V_15 ,
unsigned short V_166 ,
unsigned int V_318 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_34 * V_35 = V_15 -> V_36 ;
struct V_161 * V_162 = V_15 -> V_304 ;
struct V_284 * V_285 = V_162 -> V_285 ;
struct V_51 * V_52 = & V_285 -> V_52 ;
T_2 V_319 ;
unsigned long V_37 ;
if ( V_166 & V_320 ) {
F_20 ( V_15 -> V_28 , L_13 ) ;
V_285 -> V_321 |= V_322 | V_323 ;
}
F_25 ( & V_15 -> V_38 , V_37 ) ;
V_319 = F_99 ( V_35 -> V_39 + V_261 ) ;
if ( V_318 & V_324 ) {
F_86 ( ( V_319 & V_258 ) | V_260 ,
V_35 -> V_39 + V_261 ) ;
if ( V_319 & V_258 )
F_96 ( V_15 , 1 ) ;
}
F_27 ( & V_15 -> V_38 , V_37 ) ;
if ( ( V_166 & V_325 ) ||
( ( V_52 -> V_37 & V_53 ) &&
( V_166 & V_326 ) &&
( V_17 -> V_10 != V_11 ) ) ) {
F_25 ( & V_15 -> V_38 , V_37 ) ;
if ( V_35 -> V_302 ) {
F_27 ( & V_15 -> V_38 , V_37 ) ;
F_95 ( V_15 ) ;
} else
F_27 ( & V_15 -> V_38 , V_37 ) ;
}
if ( ( V_52 -> V_245 == V_244 && ( int ) V_35 -> V_251 <= 0 ) ||
( V_52 -> V_245 == V_240 && ( V_166 & V_327 ) ) ) {
V_285 -> V_321 |= V_322 ;
}
F_100 ( V_15 , V_162 ) ;
}
static inline unsigned int F_101 ( struct V_14 * V_15 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
unsigned int V_328 ;
if ( V_35 -> V_329 == 0 )
V_328 = V_125 - 1 ;
else
V_328 = V_35 -> V_329 - 1 ;
return V_328 ;
}
static int F_102 ( struct V_14 * V_15 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
unsigned int V_328 ;
unsigned int V_330 ;
unsigned short V_331 ;
V_328 = F_101 ( V_15 ) ;
V_331 = F_99 ( V_35 -> V_39 + V_262 ) ;
if ( ( V_331 & V_332 ) == 0 )
return 0 ;
V_330 =
F_34 ( V_35 -> V_39 + V_281 ) ;
if ( V_330 != V_35 -> V_127 [ V_328 ] )
return 0 ;
return 1 ;
}
static int F_103 ( struct V_14 * V_15 ,
const struct V_51 * V_52 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
if ( V_52 -> V_245 == V_246 )
return 1 ;
if ( V_52 -> V_245 == V_244 ) {
if ( V_35 -> V_333 )
return 1 ;
if ( F_102 ( V_15 ) == 0 )
return 1 ;
}
return 0 ;
}
static inline int F_104 ( struct V_14 * V_15 ,
unsigned short V_331 )
{
if ( ( V_331 & V_332 ) == 0 ||
( V_331 & V_258 ) == 0 )
return 0 ;
if ( F_102 ( V_15 ) )
return 0 ;
return 1 ;
}
static void F_105 ( struct V_14 * V_15 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
unsigned int V_334 ;
V_334 =
F_34 ( V_35 -> V_39 + V_283 ) ;
V_334 &= ~ V_335 ;
F_90 ( V_15 , 0 , V_334 ) ;
F_85 ( V_15 , 0 ) ;
}
static unsigned int F_106 ( struct V_14 * V_15 ,
const struct V_51 * V_52 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
unsigned int V_336 , V_328 , V_337 ;
unsigned int V_338 ;
V_328 = V_35 -> V_329 ;
V_337 = F_101 ( V_15 ) ;
V_336 = F_107 ( V_15 -> V_267 ) ;
if ( V_336 > V_122 )
V_336 = V_122 ;
if ( V_52 -> V_245 == V_244 && V_336 > V_35 -> V_333 )
V_336 = V_35 -> V_333 ;
V_336 -= V_336 % V_201 ;
if ( V_336 == 0 )
return 0 ;
V_336 = F_108 ( V_15 -> V_267 ,
V_35 ->
V_126 [ V_328 ] ,
V_336 ) ;
V_35 -> V_131 [ V_328 ] . V_138 =
F_44 ( V_336 ) ;
V_338 = F_109 ( V_35 -> V_131 [ V_328 ] . V_139 ) ;
V_338 |= V_335 ;
V_35 -> V_131 [ V_328 ] . V_139 = F_44 ( V_338 ) ;
V_338 = F_109 ( V_35 -> V_131 [ V_337 ] . V_139 ) ;
V_338 &= ~ V_335 ;
V_35 -> V_131 [ V_337 ] . V_139 = F_44 ( V_338 ) ;
V_35 -> V_329 = ( V_328 + 1 ) % V_125 ;
V_35 -> V_333 -= V_336 ;
return V_336 ;
}
static void F_110 ( struct V_14 * V_15 , const struct V_51 * V_52 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
unsigned int V_336 ;
unsigned int V_315 ;
void T_4 * V_317 =
V_35 -> V_39 + V_281 ;
unsigned int V_328 ;
do {
V_328 = V_35 -> V_329 ;
V_315 = F_34 ( V_317 ) ;
if ( V_315 >=
V_35 -> V_127 [ V_328 ] &&
V_315 <
V_35 -> V_127 [ V_328 ] +
V_122 )
return;
V_336 = F_106 ( V_15 , V_52 ) ;
} while ( V_336 >= V_122 );
}
static void F_111 ( struct V_14 * V_15 ,
unsigned short V_166 , unsigned int V_318 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
struct V_161 * V_162 = V_15 -> V_267 ;
struct V_284 * V_285 ;
struct V_51 * V_52 ;
T_2 V_339 ;
unsigned long V_37 ;
if ( V_162 == NULL )
return;
V_285 = V_162 -> V_285 ;
V_52 = & V_285 -> V_52 ;
F_25 ( & V_15 -> V_38 , V_37 ) ;
V_339 = F_99 ( V_35 -> V_39 + V_262 ) ;
if ( V_318 & V_340 ) {
if ( ( V_339 & V_258 ) &&
! ( V_339 & V_332 ) )
F_86 ( V_258 | V_260 ,
V_35 -> V_39 + V_262 ) ;
else
F_86 ( V_260 ,
V_35 -> V_39 + V_262 ) ;
F_27 ( & V_15 -> V_38 , V_37 ) ;
if ( V_339 & V_258 ) {
F_110 ( V_15 , V_52 ) ;
if ( F_104 ( V_15 , V_339 ) )
F_105 ( V_15 ) ;
}
} else {
F_27 ( & V_15 -> V_38 , V_37 ) ;
}
if ( ( V_166 & V_341 ) ) {
V_285 -> V_321 |= V_322 ;
if ( F_103 ( V_15 , V_52 ) )
V_285 -> V_321 |= V_323 ;
}
F_100 ( V_15 , V_162 ) ;
}
static T_5 F_112 ( int V_342 , void * V_343 )
{
struct V_14 * V_15 = V_343 ;
struct V_34 * V_35 = V_15 -> V_36 ;
unsigned short V_166 ;
T_3 V_318 ;
T_3 V_344 ;
V_318 = F_34 ( V_35 -> V_39 + V_41 ) ;
V_166 = F_57 ( V_35 -> V_49 + V_167 ) ;
if ( ! V_15 -> V_345 )
return V_346 ;
F_98 ( V_15 , V_166 , V_318 ) ;
F_111 ( V_15 , V_166 , V_318 ) ;
if ( V_318 & V_347 ) {
V_344 = F_34 ( V_35 -> V_39 + V_348 ) ;
F_29 ( V_344 , V_35 -> V_39 + V_348 ) ;
}
return V_346 ;
}
static int F_113 ( struct V_14 * V_15 , struct V_161 * V_162 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
unsigned long V_37 ;
F_25 ( & V_15 -> V_38 , V_37 ) ;
if ( V_35 -> V_302 == 0 ) {
F_27 ( & V_15 -> V_38 , V_37 ) ;
return 0 ;
}
V_35 -> V_302 = 0 ;
F_27 ( & V_15 -> V_38 , V_37 ) ;
F_36 ( V_15 ) ;
F_24 ( V_15 , 1 ) ;
return 0 ;
}
static int F_114 ( struct V_14 * V_15 , struct V_161 * V_162 ,
struct V_163 * V_164 , unsigned int * V_156 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_34 * V_35 = V_15 -> V_36 ;
int V_234 = F_59 ( V_164 -> V_173 ) ;
int V_24 = F_60 ( V_164 -> V_173 ) ;
F_31 ( 0 , V_35 -> V_49 + V_349 ) ;
F_22 ( V_15 , & V_35 -> V_114 , V_234 , V_24 ) ;
F_31 ( V_35 -> V_114 ,
V_35 -> V_49 + V_350 ) ;
if ( V_17 -> V_10 == V_11 ) {
F_31 ( V_156 [ 0 ] & 0xff ,
V_35 -> V_49 + F_2 ( V_234 ) ) ;
F_31 ( ( V_156 [ 0 ] >> 8 ) & 0xf ,
V_35 -> V_49 + F_3 ( V_234 ) ) ;
} else {
F_31 ( V_156 [ 0 ] , V_35 -> V_49 + F_1 ( V_234 ) ) ;
}
V_162 -> V_351 [ V_234 ] = V_156 [ 0 ] ;
return 1 ;
}
static void F_115 ( struct V_14 * V_15 ,
const struct V_51 * V_52 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
unsigned int V_26 = V_352 | V_353 |
V_354 | V_355 ;
if ( V_52 -> V_239 == V_240 ) {
V_26 |= V_356 ;
if ( V_52 -> V_247 & V_298 )
V_26 |= V_357 ;
} else {
V_26 |= V_358 ;
}
if ( V_52 -> V_228 == V_240 ) {
V_26 |= V_359 ;
if ( V_52 -> V_229 & V_298 )
V_26 |= V_360 ;
}
F_31 ( V_26 , V_35 -> V_49 + V_349 ) ;
}
static void F_116 ( struct V_14 * V_15 ,
const struct V_51 * V_52 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
int V_120 ;
for ( V_120 = 0 ; V_120 < V_52 -> V_230 ; V_120 ++ ) {
int V_1 , V_24 ;
V_1 = F_59 ( V_52 -> V_232 [ V_120 ] ) ;
V_24 = F_60 ( V_52 -> V_232 [ V_120 ] ) ;
F_22 ( V_15 , & V_35 -> V_114 , V_1 ,
V_24 ) ;
}
V_35 -> V_114 |= V_361 ;
F_31 ( V_35 -> V_114 ,
V_35 -> V_49 + V_350 ) ;
}
static void F_117 ( struct V_14 * V_15 ,
const struct V_51 * V_52 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
T_1 V_26 ;
unsigned int V_362 , V_363 ;
V_362 = F_59 ( V_52 -> V_232 [ 0 ] ) ;
V_363 = F_59 ( V_52 -> V_232 [ V_52 -> V_230 - 1 ] ) ;
if ( V_363 < V_362 )
F_20 ( V_15 -> V_28 ,
L_14 ) ;
V_26 = ( V_362 & 0x7 ) | ( V_363 & 0x7 ) << 3 ;
F_31 ( V_26 , V_35 -> V_49 + V_364 ) ;
}
static unsigned int F_118 ( unsigned int V_210 , unsigned int V_37 )
{
return F_69 ( V_210 , V_37 ) - 2 ;
}
static void F_119 ( struct V_14 * V_15 ,
const struct V_51 * V_52 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
unsigned int V_202 ;
if ( V_52 -> V_228 != V_225 )
return;
V_202 = F_118 ( V_52 -> V_229 , V_52 -> V_37 ) ;
if ( V_202 > V_220 ) {
F_20 ( V_15 -> V_28 , L_15 ) ;
V_202 = V_220 ;
}
F_31 ( V_202 & 0xffff ,
V_35 -> V_49 + V_365 ) ;
F_31 ( ( V_202 >> 16 ) & 0xff ,
V_35 -> V_49 + V_366 ) ;
}
static int F_120 ( struct V_14 * V_15 , const struct V_51 * V_52 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
unsigned int V_336 ;
int V_120 ;
F_31 ( 0 , V_35 -> V_49 + V_270 ) ;
F_31 ( 0 , V_35 -> V_49 + V_269 ) ;
V_336 = ( V_367 / 2 ) * V_201 ;
if ( V_52 -> V_245 == V_244 &&
V_336 / V_201 > V_35 -> V_333 )
V_336 = V_35 -> V_333 * V_201 ;
V_336 = F_108 ( V_15 -> V_267 ,
V_35 -> V_368 ,
V_336 ) ;
for ( V_120 = 0 ; V_120 < V_336 / V_201 ; V_120 ++ ) {
F_31 ( V_35 -> V_368 [ V_120 ] ,
V_35 -> V_49 + V_143 ) ;
}
V_35 -> V_333 -= V_336 / V_201 ;
if ( V_52 -> V_245 == V_244 && V_35 -> V_333 == 0 )
return 0 ;
V_336 = F_106 ( V_15 , V_52 ) ;
if ( V_336 == 0 )
return - 1 ;
F_110 ( V_15 , V_52 ) ;
F_85 ( V_15 , 0 ) ;
return 0 ;
}
static inline int F_121 ( struct V_14 * V_15 ,
struct V_161 * V_162 ,
struct V_51 * V_52 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
if ( V_162 -> V_268 )
return 0 ;
if ( V_17 -> V_10 == V_11 )
return 0 ;
else if ( F_88 ( V_52 ) )
return 0 ;
return 1 ;
}
static int F_122 ( struct V_14 * V_15 , struct V_161 * V_162 ,
unsigned int V_369 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
struct V_51 * V_52 = & V_162 -> V_285 -> V_52 ;
int V_101 ;
if ( V_369 != V_52 -> V_247 )
return - V_197 ;
V_101 = F_120 ( V_15 , V_52 ) ;
if ( V_101 < 0 )
return - V_370 ;
F_115 ( V_15 , V_52 ) ;
if ( V_52 -> V_239 == V_371 )
F_31 ( 0 , V_35 -> V_49 + V_372 ) ;
V_162 -> V_285 -> V_373 = NULL ;
return 0 ;
}
static int F_123 ( struct V_14 * V_15 , struct V_161 * V_162 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
struct V_51 * V_52 = & V_162 -> V_285 -> V_52 ;
if ( F_121 ( V_15 , V_162 , V_52 ) ) {
F_47 ( V_15 ) ;
return - V_169 ;
}
F_31 ( 0x0 , V_35 -> V_49 + V_349 ) ;
V_35 -> V_329 = 0 ;
V_35 -> V_333 = V_52 -> V_250 * V_52 -> V_230 ;
F_117 ( V_15 , V_52 ) ;
F_119 ( V_15 , V_52 ) ;
F_90 ( V_15 , 0 , V_35 -> V_132 |
V_140 | V_141 ) ;
F_116 ( V_15 , V_52 ) ;
V_162 -> V_285 -> V_373 = F_122 ;
return 0 ;
}
static int F_124 ( struct V_14 * V_15 ,
struct V_161 * V_162 ,
struct V_51 * V_52 )
{
unsigned int V_233 = F_59 ( V_52 -> V_232 [ 0 ] ) ;
int V_120 ;
for ( V_120 = 1 ; V_120 < V_52 -> V_230 ; V_120 ++ ) {
unsigned int V_234 = F_59 ( V_52 -> V_232 [ V_120 ] ) ;
if ( V_234 != ( V_233 + V_120 ) ) {
F_64 ( V_15 -> V_28 ,
L_9 ) ;
return - V_197 ;
}
}
return 0 ;
}
static int F_125 ( struct V_14 * V_15 , struct V_161 * V_162 ,
struct V_51 * V_52 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
int V_235 = 0 ;
unsigned int V_236 ;
V_235 |= F_73 ( & V_52 -> V_239 , V_371 | V_240 ) ;
V_235 |= F_73 ( & V_52 -> V_228 ,
V_225 | V_240 ) ;
V_235 |= F_73 ( & V_52 -> V_224 , V_227 ) ;
V_235 |= F_73 ( & V_52 -> V_243 , V_244 ) ;
V_235 |= F_73 ( & V_52 -> V_245 , V_246 ) ;
if ( V_235 )
return 1 ;
V_235 |= F_74 ( V_52 -> V_239 ) ;
V_235 |= F_74 ( V_52 -> V_228 ) ;
if ( V_52 -> V_224 == V_240 && V_52 -> V_228 == V_225 )
V_235 |= - V_197 ;
if ( V_52 -> V_245 != V_244 &&
V_52 -> V_245 != V_246 && V_52 -> V_245 != V_240 )
V_235 |= - V_197 ;
if ( V_235 )
return 2 ;
V_235 |= F_75 ( & V_52 -> V_247 , 0 ) ;
if ( V_52 -> V_228 == V_225 ) {
V_235 |= F_76 ( & V_52 -> V_229 ,
V_17 -> V_374 ) ;
if ( F_118 ( V_52 -> V_229 , V_52 -> V_37 ) >
V_220 ) {
V_52 -> V_229 = ( V_220 + 2 ) *
V_213 ;
V_235 |= - V_197 ;
}
}
V_235 |= F_76 ( & V_52 -> V_230 , 1 ) ;
V_235 |= F_75 ( & V_52 -> V_249 , V_52 -> V_230 ) ;
if ( V_235 )
return 3 ;
if ( V_52 -> V_228 == V_225 ) {
V_236 = V_52 -> V_229 ;
V_52 -> V_229 = F_69 ( V_52 -> V_229 ,
V_52 -> V_37 ) * V_213 ;
if ( V_236 != V_52 -> V_229 )
V_235 ++ ;
}
if ( V_235 )
return 4 ;
if ( V_52 -> V_232 && V_52 -> V_230 > 0 )
V_235 |= F_124 ( V_15 , V_162 , V_52 ) ;
if ( V_235 )
return 5 ;
return 0 ;
}
static int F_126 ( struct V_14 * V_15 , struct V_161 * V_162 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
F_31 ( 0x0 , V_35 -> V_49 + V_349 ) ;
F_24 ( V_15 , 0 ) ;
return 0 ;
}
static int F_127 ( struct V_14 * V_15 ,
int V_375 , int V_376 , int V_156 , unsigned long V_377 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
if ( V_375 ) {
F_31 ( V_156 , V_35 -> V_49 + V_377 + 2 * V_376 ) ;
return 0 ;
}
return F_57 ( V_35 -> V_49 + V_377 + 2 * V_376 ) ;
}
static int F_128 ( struct V_14 * V_15 , struct V_161 * V_162 ,
struct V_163 * V_164 , unsigned int * V_156 )
{
unsigned int V_26 ;
V_26 = F_99 ( V_15 -> V_194 + V_378 ) ;
V_26 &= 0xf ;
V_156 [ 1 ] = V_26 ;
V_156 [ 0 ] = 0 ;
return V_164 -> V_170 ;
}
static int F_129 ( struct V_14 * V_15 ,
struct V_161 * V_162 ,
struct V_163 * V_164 ,
unsigned int * V_156 )
{
if ( F_130 ( V_162 , V_156 ) )
F_86 ( V_162 -> V_144 , V_15 -> V_194 + V_379 ) ;
V_156 [ 1 ] = V_162 -> V_144 ;
return V_164 -> V_170 ;
}
static int F_131 ( struct V_14 * V_15 ,
struct V_161 * V_162 ,
struct V_163 * V_164 ,
unsigned int * V_156 )
{
int V_172 ;
V_172 = F_132 ( V_15 , V_162 , V_164 , V_156 , 0 ) ;
if ( V_172 )
return V_172 ;
F_86 ( V_162 -> V_380 , V_15 -> V_194 + V_381 ) ;
return V_164 -> V_170 ;
}
static int F_133 ( struct V_14 * V_15 ,
struct V_161 * V_162 ,
struct V_163 * V_164 ,
unsigned int * V_156 )
{
if ( F_130 ( V_162 , V_156 ) )
F_86 ( V_162 -> V_144 , V_15 -> V_194 + V_382 ) ;
V_156 [ 1 ] = F_99 ( V_15 -> V_194 + V_382 ) ;
return V_164 -> V_170 ;
}
static int F_134 ( struct V_14 * V_15 , unsigned int V_155 ,
T_2 V_383 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
static const int V_384 = 8 ;
static const int V_385 = 11 ;
unsigned int V_158 = ( ( V_155 & 0x7 ) << 8 ) | V_383 ;
unsigned int V_153 , V_386 ;
static const int V_387 = 1 ;
if ( V_155 >= V_384 ) {
F_20 ( V_15 -> V_28 , L_16 ) ;
return - 1 ;
}
for ( V_153 = 1 << ( V_385 - 1 ) ; V_153 ; V_153 >>= 1 ) {
V_386 = 0 ;
if ( V_158 & V_153 )
V_386 |= V_388 ;
F_49 ( V_387 ) ;
F_31 ( V_386 , V_35 -> V_49 + V_112 ) ;
V_386 |= V_389 ;
F_49 ( V_387 ) ;
F_31 ( V_386 , V_35 -> V_49 + V_112 ) ;
}
F_49 ( V_387 ) ;
F_31 ( V_390 , V_35 -> V_49 + V_112 ) ;
F_49 ( V_387 ) ;
F_31 ( 0 , V_35 -> V_49 + V_112 ) ;
F_49 ( V_387 ) ;
return 0 ;
}
static int F_135 ( struct V_14 * V_15 ,
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
F_20 ( V_15 -> V_28 , L_17 ) ;
return - 1 ;
}
V_392 [ 1 ] = V_398 | ( ( V_383 >> 8 ) & 0xf ) ;
V_392 [ 2 ] = V_383 & 0xff ;
F_55 ( V_15 , V_393 , V_392 , 3 ) ;
return 0 ;
}
static void F_136 ( struct V_14 * V_15 , unsigned int V_1 ,
unsigned int V_383 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_34 * V_35 = V_15 -> V_36 ;
V_35 -> V_401 [ V_1 ] = V_383 ;
switch ( V_17 -> V_10 ) {
case V_20 :
case V_19 :
F_134 ( V_15 , V_1 , V_383 ) ;
break;
case V_11 :
F_135 ( V_15 , V_1 , V_383 ) ;
break;
default:
break;
}
}
static int F_137 ( struct V_14 * V_15 ,
struct V_161 * V_162 ,
struct V_163 * V_164 , unsigned int * V_156 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
int V_1 = F_59 ( V_164 -> V_173 ) ;
if ( V_35 -> V_401 [ V_1 ] == V_156 [ 0 ] )
return 1 ;
F_136 ( V_15 , V_1 , V_156 [ 0 ] ) ;
return 1 ;
}
static int F_138 ( struct V_14 * V_15 ,
struct V_161 * V_162 , struct V_163 * V_164 ,
unsigned int * V_156 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
unsigned int V_1 = F_59 ( V_164 -> V_173 ) ;
V_156 [ 0 ] = V_35 -> V_401 [ V_1 ] ;
return 1 ;
}
static void F_139 ( struct V_14 * V_15 , unsigned int V_1 ,
unsigned int V_383 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
static const int V_385 = 10 ;
unsigned int V_153 , V_386 ;
unsigned int V_158 = ( ( V_1 & 0x3 ) << 8 ) | ( V_383 & 0xff ) ;
static const int V_402 = 1 ;
V_35 -> V_403 [ V_1 ] = V_383 ;
V_386 = V_404 ;
F_49 ( V_402 ) ;
F_31 ( V_386 , V_35 -> V_49 + V_112 ) ;
for ( V_153 = 1 << ( V_385 - 1 ) ; V_153 ; V_153 >>= 1 ) {
if ( V_158 & V_153 )
V_386 |= V_388 ;
else
V_386 &= ~ V_388 ;
F_49 ( V_402 ) ;
F_31 ( V_386 , V_35 -> V_49 + V_112 ) ;
F_49 ( V_402 ) ;
F_31 ( V_386 | V_389 ,
V_35 -> V_49 + V_112 ) ;
}
F_49 ( V_402 ) ;
F_31 ( 0 , V_35 -> V_49 + V_112 ) ;
}
static int F_140 ( struct V_14 * V_15 ,
struct V_161 * V_162 ,
struct V_163 * V_164 , unsigned int * V_156 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
int V_1 = F_59 ( V_164 -> V_173 ) ;
if ( V_35 -> V_403 [ V_1 ] == V_156 [ 0 ] )
return 1 ;
V_35 -> V_403 [ V_1 ] = V_156 [ 0 ] ;
F_139 ( V_15 , V_1 , V_156 [ 0 ] ) ;
return 1 ;
}
static int F_141 ( struct V_14 * V_15 ,
struct V_161 * V_162 ,
struct V_163 * V_164 , unsigned int * V_156 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
unsigned int V_1 = F_59 ( V_164 -> V_173 ) ;
V_156 [ 0 ] = V_35 -> V_403 [ V_1 ] ;
return 1 ;
}
static T_1 F_142 ( struct V_14 * V_15 , T_2 V_155 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
static const int V_385 = 11 ;
static const int V_405 = 0x6 ;
unsigned int V_158 = ( V_405 << 8 ) | V_155 ;
unsigned int V_153 ;
void T_4 * const V_147 =
V_35 -> V_39 + V_57 ;
T_1 V_383 ;
static const int V_406 = 16 ;
static const int V_407 = 1 ;
F_49 ( V_407 ) ;
V_35 -> V_56 &= ~ V_408 & ~ V_160 ;
V_35 -> V_56 |= V_151 ;
F_29 ( V_35 -> V_56 , V_147 ) ;
F_49 ( V_407 ) ;
V_35 -> V_56 |= V_160 ;
F_29 ( V_35 -> V_56 , V_147 ) ;
for ( V_153 = 1 << ( V_385 - 1 ) ; V_153 ; V_153 >>= 1 ) {
F_49 ( V_407 ) ;
if ( V_158 & V_153 )
V_35 -> V_56 |= V_146 ;
else
V_35 -> V_56 &= ~ V_146 ;
F_29 ( V_35 -> V_56 , V_147 ) ;
F_49 ( V_407 ) ;
V_35 -> V_56 |= V_408 ;
F_29 ( V_35 -> V_56 , V_147 ) ;
F_49 ( V_407 ) ;
V_35 -> V_56 &= ~ V_408 ;
F_29 ( V_35 -> V_56 , V_147 ) ;
}
V_383 = 0 ;
for ( V_153 = 1 << ( V_406 - 1 ) ; V_153 ; V_153 >>= 1 ) {
F_49 ( V_407 ) ;
V_35 -> V_56 |= V_408 ;
F_29 ( V_35 -> V_56 , V_147 ) ;
F_49 ( V_407 ) ;
V_35 -> V_56 &= ~ V_408 ;
F_29 ( V_35 -> V_56 , V_147 ) ;
F_49 ( V_407 ) ;
if ( F_34 ( V_147 ) & V_409 )
V_383 |= V_153 ;
}
F_49 ( V_407 ) ;
V_35 -> V_56 &= ~ V_160 ;
F_29 ( V_35 -> V_56 , V_147 ) ;
return V_383 ;
}
static int F_143 ( struct V_14 * V_15 ,
struct V_161 * V_162 ,
struct V_163 * V_164 , unsigned int * V_156 )
{
V_156 [ 0 ] = F_142 ( V_15 , F_59 ( V_164 -> V_173 ) ) ;
return 1 ;
}
static int F_144 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_34 * V_35 = V_15 -> V_36 ;
struct V_161 * V_162 ;
int V_120 ;
int V_172 ;
V_172 = F_145 ( V_15 , 10 ) ;
if ( V_172 )
return V_172 ;
V_162 = & V_15 -> V_410 [ 0 ] ;
V_15 -> V_304 = V_162 ;
V_162 -> type = V_411 ;
V_162 -> V_412 = V_413 | V_414 | V_415 | V_416 ;
if ( V_17 -> V_10 == V_20 )
V_162 -> V_412 |= V_417 | V_418 ;
else if ( V_17 -> V_10 == V_19 )
V_162 -> V_412 |= V_418 ;
V_162 -> V_419 = V_17 -> V_420 ;
V_162 -> V_421 = 0x2000 ;
V_162 -> V_422 = ( 1 << V_17 -> V_423 ) - 1 ;
V_162 -> V_424 = V_17 -> V_25 ;
V_162 -> V_425 = F_58 ;
V_162 -> V_426 = F_68 ;
V_162 -> V_427 = F_91 ;
V_162 -> V_428 = F_72 ;
V_162 -> V_429 = F_113 ;
if ( V_17 -> V_10 == V_11 ) {
T_2 V_156 ;
V_35 -> V_188 = F_15 ( 4 ) ;
for ( V_120 = 0 ; V_120 < V_162 -> V_419 ; V_120 ++ )
V_35 -> V_188 |= F_16 ( V_120 ) ;
V_156 = V_35 -> V_188 ;
F_55 ( V_15 , V_190 , & V_156 , sizeof( V_156 ) ) ;
}
V_162 = & V_15 -> V_410 [ 1 ] ;
if ( V_17 -> V_33 ) {
V_162 -> type = V_430 ;
V_162 -> V_412 = V_413 | V_431 |
V_414 | V_432 ;
V_162 -> V_419 = V_17 -> V_33 ;
V_162 -> V_422 = ( 1 << V_17 -> V_433 ) - 1 ;
V_162 -> V_424 = V_17 -> V_434 ;
V_162 -> V_435 = F_114 ;
V_162 -> V_425 = V_436 ;
V_172 = F_146 ( V_162 ) ;
if ( V_172 )
return V_172 ;
if ( F_23 ( V_17 ) ) {
V_15 -> V_267 = V_162 ;
V_162 -> V_428 = F_125 ;
V_162 -> V_427 = F_123 ;
V_162 -> V_421 = V_17 -> V_33 ;
V_162 -> V_429 = F_126 ;
}
} else {
V_162 -> type = V_437 ;
}
V_162 = & V_15 -> V_410 [ 2 ] ;
if ( V_17 -> V_10 == V_19 ) {
V_162 -> type = V_438 ;
V_162 -> V_412 = V_413 ;
V_162 -> V_419 = 4 ;
V_162 -> V_422 = 1 ;
V_162 -> V_424 = & V_439 ;
V_162 -> V_440 = F_128 ;
} else
V_162 -> type = V_437 ;
if ( V_17 -> V_10 == V_19 ) {
V_162 = & V_15 -> V_410 [ 3 ] ;
V_162 -> type = V_441 ;
V_162 -> V_412 = V_431 | V_413 ;
V_162 -> V_419 = 4 ;
V_162 -> V_422 = 1 ;
V_162 -> V_424 = & V_439 ;
V_162 -> V_440 = F_129 ;
} else
V_162 -> type = V_437 ;
V_162 = & V_15 -> V_410 [ 4 ] ;
if ( V_17 -> V_442 ) {
if ( V_17 -> V_10 == V_11 ) {
V_172 = F_147 ( V_15 , V_162 , F_127 ,
V_443 ) ;
} else {
V_172 = F_148 ( V_15 , V_162 , NULL ,
V_444 ) ;
}
if ( V_172 )
return V_172 ;
} else {
V_162 -> type = V_437 ;
}
V_162 = & V_15 -> V_410 [ 5 ] ;
if ( V_17 -> V_10 == V_20 ) {
V_162 -> type = V_445 ;
V_162 -> V_412 = V_431 | V_413 ;
V_162 -> V_419 = 8 ;
V_162 -> V_422 = 1 ;
V_162 -> V_424 = & V_439 ;
V_162 -> V_426 = F_131 ;
V_162 -> V_440 = F_133 ;
} else
V_162 -> type = V_437 ;
V_162 = & V_15 -> V_410 [ 6 ] ;
V_162 -> type = V_446 ;
V_162 -> V_412 = V_413 | V_431 | V_447 ;
V_162 -> V_419 = 8 ;
if ( V_17 -> V_10 == V_11 )
V_162 -> V_422 = 0xfff ;
else
V_162 -> V_422 = 0xff ;
V_162 -> V_425 = F_138 ;
V_162 -> V_435 = F_137 ;
for ( V_120 = 0 ; V_120 < V_162 -> V_419 ; V_120 ++ )
F_136 ( V_15 , V_120 , V_162 -> V_422 / 2 ) ;
V_162 = & V_15 -> V_410 [ 7 ] ;
if ( V_17 -> V_10 == V_19 ) {
V_162 -> type = V_446 ;
V_162 -> V_412 = V_413 | V_431 | V_447 ;
V_162 -> V_419 = 2 ;
V_162 -> V_425 = F_141 ;
V_162 -> V_435 = F_140 ;
V_162 -> V_422 = 0xff ;
for ( V_120 = 0 ; V_120 < V_162 -> V_419 ; V_120 ++ )
F_139 ( V_15 , V_120 , V_162 -> V_422 / 2 ) ;
} else
V_162 -> type = V_437 ;
V_162 = & V_15 -> V_410 [ 8 ] ;
if ( F_34 ( V_35 -> V_39 + V_57 ) & V_448 ) {
V_162 -> type = V_449 ;
V_162 -> V_412 = V_413 | V_447 ;
V_162 -> V_419 = 128 ;
V_162 -> V_422 = 0xffff ;
V_162 -> V_425 = F_143 ;
} else
V_162 -> type = V_437 ;
V_162 = & V_15 -> V_410 [ 9 ] ;
V_162 -> type = V_437 ;
return 0 ;
}
static int F_149 ( struct V_14 * V_15 ,
unsigned long V_165 )
{
struct V_118 * V_119 = F_42 ( V_15 ) ;
const struct V_8 * V_17 = NULL ;
struct V_34 * V_35 ;
T_3 V_450 , V_451 ;
int V_101 ;
if ( V_165 < F_150 ( V_452 ) )
V_17 = & V_452 [ V_165 ] ;
if ( ! V_17 )
return - V_453 ;
V_15 -> V_18 = V_17 ;
V_35 = F_151 ( V_15 , sizeof( * V_35 ) ) ;
if ( ! V_35 )
return - V_124 ;
V_101 = F_152 ( V_15 ) ;
if ( V_101 )
return V_101 ;
F_153 ( V_119 ) ;
V_15 -> V_454 = V_17 -> V_455 ;
V_35 -> V_456 = F_154 ( V_119 , 2 ) ;
V_35 -> V_457 = F_154 ( V_119 , 3 ) ;
V_35 -> V_39 = F_155 ( V_119 , 0 ) ;
V_35 -> V_49 = F_155 ( V_119 , 2 ) ;
V_15 -> V_194 = F_155 ( V_119 , 3 ) ;
if ( ! V_35 -> V_39 || ! V_35 -> V_49 || ! V_15 -> V_194 ) {
F_156 ( V_15 -> V_28 , L_18 ) ;
return - V_124 ;
}
V_450 = F_34 ( V_35 -> V_39 + V_458 ) &
V_459 ;
V_451 = F_34 ( V_35 -> V_39 + V_460 ) &
V_450 & V_461 ;
V_35 -> V_137 = ( ( T_3 ) V_35 -> V_456 &
~ V_450 ) | V_451 ;
V_450 = F_34 ( V_35 -> V_39 + V_462 ) &
V_459 ;
V_451 = F_34 ( V_35 -> V_39 + V_463 ) &
V_450 & V_461 ;
V_35 -> V_135 = ( ( T_3 ) V_35 -> V_457 &
~ V_450 ) | V_451 ;
V_101 = F_41 ( V_15 ) ;
if ( V_101 < 0 )
return V_101 ;
V_35 -> F_21 =
F_21 ( V_15 , F_57 ( V_35 -> V_49 + V_167 ) ) ;
F_64 ( V_15 -> V_28 , L_19 ,
V_35 -> F_21 ) ;
F_33 ( V_15 ) ;
F_40 ( V_15 ) ;
V_101 = F_157 ( V_119 -> V_342 , F_112 , V_464 ,
V_15 -> V_454 , V_15 ) ;
if ( V_101 ) {
F_64 ( V_15 -> V_28 , L_20 ,
V_119 -> V_342 ) ;
return V_101 ;
}
V_15 -> V_342 = V_119 -> V_342 ;
F_64 ( V_15 -> V_28 , L_21 , V_15 -> V_342 ) ;
V_101 = F_144 ( V_15 ) ;
if ( V_101 < 0 )
return V_101 ;
return 0 ;
}
static void F_158 ( struct V_14 * V_15 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
if ( V_15 -> V_342 )
F_159 ( V_15 -> V_342 , V_15 ) ;
if ( V_35 ) {
if ( V_35 -> V_39 ) {
F_28 ( V_15 ) ;
F_160 ( V_35 -> V_39 ) ;
}
if ( V_35 -> V_49 )
F_160 ( V_35 -> V_49 ) ;
if ( V_15 -> V_194 )
F_160 ( V_15 -> V_194 ) ;
}
F_161 ( V_15 ) ;
F_45 ( V_15 ) ;
}
static int F_162 ( struct V_118 * V_15 ,
const struct V_465 * V_206 )
{
return F_163 ( V_15 , & V_466 ,
V_206 -> V_467 ) ;
}
