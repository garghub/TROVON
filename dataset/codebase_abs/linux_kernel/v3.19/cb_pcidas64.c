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
if ( F_77 ( V_52 ) ) {
F_31 ( V_52 -> V_250 & 0xffff ,
V_35 -> V_49 + V_251 ) ;
F_31 ( ( V_52 -> V_250 >> 16 ) & 0xff ,
V_35 -> V_49 + V_252 ) ;
} else {
F_31 ( 1 , V_35 -> V_49 + V_251 ) ;
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
T_3 V_253 ;
switch ( V_52 -> V_228 ) {
case V_225 :
V_253 = ( V_52 -> V_229 -
( V_52 -> V_226 * ( V_52 -> V_230 - 1 ) ) ) /
V_213 ;
break;
case V_242 :
V_253 = V_52 -> V_226 / V_213 ;
break;
default:
return 0 ;
}
return V_253 - 3 ;
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
V_35 -> V_109 &= ~ V_254 ;
if ( V_52 -> V_228 == V_241 ) {
int V_173 = V_35 -> V_205 . V_173 ;
if ( F_59 ( V_173 ) )
V_35 -> V_109 |= V_255 ;
else
V_35 -> V_109 |= V_256 ;
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
F_86 ( V_257 | V_258 |
V_259 ,
V_35 -> V_39 + V_260 ) ;
else
F_86 ( V_257 | V_258 |
V_259 ,
V_35 -> V_39 + V_261 ) ;
F_27 ( & V_15 -> V_38 , V_37 ) ;
}
static void F_87 ( struct V_14 * V_15 , struct V_51 * V_52 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_34 * V_35 = V_15 -> V_36 ;
T_3 V_262 = 0 , V_263 = 0 ;
F_70 ( V_15 , V_52 ) ;
F_84 ( V_15 , V_52 ) ;
if ( V_17 -> V_10 == V_11 ) {
V_262 = F_82 ( V_15 , V_52 ) ;
} else {
V_262 = F_80 ( V_15 , V_52 ) ;
V_263 = F_81 ( V_15 , V_52 ) ;
}
F_31 ( V_262 & 0xffff ,
V_35 -> V_49 + V_191 ) ;
F_31 ( ( V_262 >> 16 ) & 0xff ,
V_35 -> V_49 + V_105 ) ;
F_31 ( V_263 & 0xffff ,
V_35 -> V_49 + V_264 ) ;
F_31 ( ( V_263 >> 16 ) & 0xff ,
V_35 -> V_49 + V_265 ) ;
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
if ( V_15 -> V_266 && V_15 -> V_266 -> V_267 ) {
F_47 ( V_15 ) ;
return - V_169 ;
}
V_35 -> V_109 |= V_176 ;
F_31 ( V_35 -> V_109 ,
V_35 -> V_49 + V_110 ) ;
F_31 ( 0 ,
V_35 -> V_49 + V_268 ) ;
F_31 ( 0 , V_35 -> V_49 + V_269 ) ;
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
V_26 |= V_270 |
V_271 ;
F_31 ( V_26 ,
V_35 -> V_49 +
V_272 ) ;
}
F_31 ( 0 , V_35 -> V_49 + V_269 ) ;
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
unsigned int V_273 ,
unsigned int V_274 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
if ( V_273 ) {
F_29 ( 0 ,
V_35 -> V_39 + V_275 ) ;
F_29 ( 0 , V_35 -> V_39 + V_276 ) ;
F_29 ( 0 ,
V_35 -> V_39 + V_277 ) ;
F_29 ( V_274 ,
V_35 -> V_39 + V_278 ) ;
} else {
F_29 ( 0 ,
V_35 -> V_39 + V_279 ) ;
F_29 ( 0 , V_35 -> V_39 + V_280 ) ;
F_29 ( 0 ,
V_35 -> V_39 + V_281 ) ;
F_29 ( V_274 ,
V_35 -> V_39 + V_282 ) ;
}
}
static int F_91 ( struct V_14 * V_15 , struct V_161 * V_162 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_34 * V_35 = V_15 -> V_36 ;
struct V_283 * V_284 = V_162 -> V_284 ;
struct V_51 * V_52 = & V_284 -> V_52 ;
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
V_35 -> V_81 &= ~ V_285 ;
if ( V_52 -> V_224 == V_240 )
V_35 -> V_81 |= F_7 ( 13 ) ;
else
V_35 -> V_81 |= F_7 ( 8 ) ;
} else {
V_35 -> V_81 &= ~ V_286 ;
if ( V_52 -> V_230 == 4 )
V_35 -> V_81 |= V_287 ;
else if ( V_52 -> V_230 == 2 )
V_35 -> V_81 |= V_288 ;
V_35 -> V_81 &= ~ V_289 ;
V_35 -> V_81 |=
F_5 ( F_59 ( V_52 -> V_232 [ 0 ] ) ) ;
V_35 -> V_81 &= ~ V_290 ;
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
V_35 -> V_291 = 0 ;
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
V_26 |= V_292 ;
if ( V_52 -> V_245 == V_240 && F_59 ( V_52 -> V_250 ) )
V_26 |= V_293 ;
F_31 ( V_26 , V_35 -> V_49 + V_294 ) ;
}
F_25 ( & V_15 -> V_38 , V_37 ) ;
V_26 = V_295 | V_85 | V_86 ;
if ( V_52 -> V_37 & V_53 )
V_26 |= V_84 ;
if ( V_52 -> V_239 == V_240 ) {
V_26 |= V_296 ;
if ( V_52 -> V_247 & V_297 )
V_26 |= V_298 ;
} else if ( V_52 -> V_239 == V_227 )
V_26 |= V_299 ;
if ( F_77 ( V_52 ) )
V_26 |= V_300 ;
F_31 ( V_26 , V_35 -> V_49 + V_87 ) ;
V_35 -> V_301 = 1 ;
F_27 ( & V_15 -> V_38 , V_37 ) ;
if ( V_52 -> V_239 == V_227 )
F_31 ( 0 , V_35 -> V_49 + V_302 ) ;
return 0 ;
}
static void F_92 ( struct V_14 * V_15 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
struct V_161 * V_162 = V_15 -> V_303 ;
unsigned int V_120 ;
T_1 V_6 ;
int V_304 , V_305 , V_306 , V_307 ;
int V_99 ;
do {
V_305 = F_57 ( V_35 -> V_49 + V_308 ) &
0x7fff ;
V_307 = F_57 ( V_35 -> V_49 + V_168 ) &
0x7fff ;
V_6 = F_57 ( V_35 -> V_49 + V_309 ) ;
V_304 = F_13 ( V_6 ) ;
V_306 = F_14 ( V_6 ) ;
if ( V_304 != V_306 )
V_99 =
V_35 -> V_98 - V_305 ;
else
V_99 = V_307 - V_305 ;
if ( V_99 < 0 ) {
F_20 ( V_15 -> V_28 ,
L_12 ) ;
break;
}
V_99 = F_93 ( V_162 , V_99 ) ;
if ( V_99 == 0 )
break;
for ( V_120 = 0 ; V_120 < V_99 ; V_120 ++ ) {
unsigned short V_310 ;
V_310 = F_57 ( V_35 -> V_49 + V_136 ) ;
F_94 ( V_162 , & V_310 , 1 ) ;
}
} while ( V_304 != V_306 );
}
static void F_95 ( struct V_14 * V_15 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
struct V_161 * V_162 = V_15 -> V_303 ;
unsigned int V_311 ;
unsigned int V_120 ;
T_3 V_312 ;
int V_313 =
F_57 ( V_35 -> V_49 + V_168 ) & 0x7fff ;
int V_314 =
F_57 ( V_35 -> V_49 + V_308 ) & 0x7fff ;
V_311 = F_93 ( V_162 , 100000 ) ;
for ( V_120 = 0 ; V_314 != V_313 && V_120 < V_311 ; ) {
unsigned short V_310 ;
V_312 = F_34 ( V_15 -> V_194 + V_136 ) ;
V_310 = V_312 & 0xffff ;
F_94 ( V_162 , & V_310 , 1 ) ;
V_120 ++ ;
if ( V_120 < V_311 ) {
V_310 = ( V_312 >> 16 ) & 0xffff ;
F_94 ( V_162 , & V_310 , 1 ) ;
V_120 ++ ;
}
V_314 = F_57 ( V_35 -> V_49 + V_308 ) &
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
struct V_34 * V_35 = V_15 -> V_36 ;
struct V_161 * V_162 = V_15 -> V_303 ;
T_3 V_315 ;
int V_316 ;
int V_99 = 0 ;
void T_4 * V_317 ;
if ( V_1 )
V_317 =
V_35 -> V_39 + V_276 ;
else
V_317 =
V_35 -> V_39 + V_280 ;
for ( V_316 = 0 , V_315 = F_34 ( V_317 ) ;
( V_315 <
V_35 -> V_123 [ V_35 -> V_291 ] ||
V_315 >=
V_35 -> V_123 [ V_35 -> V_291 ] +
V_122 ) && V_316 < F_17 ( V_17 ) ; V_316 ++ ) {
V_99 = F_93 ( V_162 , F_79 ( V_15 ) ) ;
F_94 ( V_162 ,
V_35 -> V_121 [ V_35 -> V_291 ] ,
V_99 ) ;
V_35 -> V_291 = ( V_35 -> V_291 + 1 ) %
F_17 ( V_17 ) ;
}
}
static void F_98 ( struct V_14 * V_15 ,
unsigned short V_166 ,
unsigned int V_318 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_34 * V_35 = V_15 -> V_36 ;
struct V_161 * V_162 = V_15 -> V_303 ;
struct V_283 * V_284 = V_162 -> V_284 ;
struct V_51 * V_52 = & V_284 -> V_52 ;
T_2 V_319 ;
unsigned long V_37 ;
if ( V_166 & V_320 ) {
F_20 ( V_15 -> V_28 , L_13 ) ;
V_284 -> V_321 |= V_322 | V_323 ;
}
F_25 ( & V_15 -> V_38 , V_37 ) ;
V_319 = F_99 ( V_35 -> V_39 + V_260 ) ;
if ( V_318 & V_324 ) {
F_86 ( ( V_319 & V_257 ) | V_259 ,
V_35 -> V_39 + V_260 ) ;
if ( V_319 & V_257 )
F_97 ( V_15 , 1 ) ;
}
F_27 ( & V_15 -> V_38 , V_37 ) ;
if ( ( V_166 & V_325 ) ||
( ( V_52 -> V_37 & V_53 ) &&
( V_166 & V_326 ) &&
( V_17 -> V_10 != V_11 ) ) ) {
F_25 ( & V_15 -> V_38 , V_37 ) ;
if ( V_35 -> V_301 ) {
F_27 ( & V_15 -> V_38 , V_37 ) ;
F_96 ( V_15 ) ;
} else
F_27 ( & V_15 -> V_38 , V_37 ) ;
}
if ( ( V_52 -> V_245 == V_244 &&
V_284 -> V_327 >= V_52 -> V_250 ) ||
( V_52 -> V_245 == V_240 && ( V_166 & V_328 ) ) )
V_284 -> V_321 |= V_322 ;
F_100 ( V_15 , V_162 ) ;
}
static inline unsigned int F_101 ( struct V_14 * V_15 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
unsigned int V_329 ;
if ( V_35 -> V_330 == 0 )
V_329 = V_125 - 1 ;
else
V_329 = V_35 -> V_330 - 1 ;
return V_329 ;
}
static int F_102 ( struct V_14 * V_15 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
unsigned int V_329 ;
unsigned int V_331 ;
unsigned short V_332 ;
V_329 = F_101 ( V_15 ) ;
V_332 = F_99 ( V_35 -> V_39 + V_261 ) ;
if ( ( V_332 & V_333 ) == 0 )
return 0 ;
V_331 =
F_34 ( V_35 -> V_39 + V_280 ) ;
if ( V_331 != V_35 -> V_127 [ V_329 ] )
return 0 ;
return 1 ;
}
static inline int F_103 ( struct V_14 * V_15 ,
unsigned short V_332 )
{
if ( ( V_332 & V_333 ) == 0 ||
( V_332 & V_257 ) == 0 )
return 0 ;
if ( F_102 ( V_15 ) )
return 0 ;
return 1 ;
}
static void F_104 ( struct V_14 * V_15 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
unsigned int V_334 ;
V_334 =
F_34 ( V_35 -> V_39 + V_282 ) ;
V_334 &= ~ V_335 ;
F_90 ( V_15 , 0 , V_334 ) ;
F_85 ( V_15 , 0 ) ;
}
static unsigned int F_105 ( struct V_14 * V_15 ,
struct V_161 * V_162 ,
unsigned short * V_336 ,
unsigned int V_337 )
{
unsigned int V_311 = F_106 ( V_162 , V_337 ) ;
unsigned int V_338 ;
V_311 = F_93 ( V_162 , V_311 ) ;
V_338 = F_107 ( V_162 , V_336 , V_311 ) ;
return F_106 ( V_162 , V_338 ) ;
}
static unsigned int F_108 ( struct V_14 * V_15 ,
const struct V_51 * V_52 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
struct V_161 * V_162 = V_15 -> V_266 ;
unsigned int V_329 = V_35 -> V_330 ;
unsigned int V_339 = F_101 ( V_15 ) ;
unsigned int V_311 ;
unsigned int V_340 ;
unsigned int V_341 ;
V_311 = F_105 ( V_15 , V_162 ,
V_35 -> V_126 [ V_329 ] ,
V_122 ) ;
if ( V_311 == 0 )
return 0 ;
V_340 = F_109 ( V_162 , V_311 ) ;
V_35 -> V_131 [ V_329 ] . V_138 = F_44 ( V_340 ) ;
V_341 = F_110 ( V_35 -> V_131 [ V_329 ] . V_139 ) ;
V_341 |= V_335 ;
V_35 -> V_131 [ V_329 ] . V_139 = F_44 ( V_341 ) ;
V_341 = F_110 ( V_35 -> V_131 [ V_339 ] . V_139 ) ;
V_341 &= ~ V_335 ;
V_35 -> V_131 [ V_339 ] . V_139 = F_44 ( V_341 ) ;
V_35 -> V_330 = ( V_329 + 1 ) % V_125 ;
return V_340 ;
}
static void F_111 ( struct V_14 * V_15 , const struct V_51 * V_52 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
unsigned int V_342 ;
unsigned int V_315 ;
void T_4 * V_317 =
V_35 -> V_39 + V_280 ;
unsigned int V_329 ;
do {
V_329 = V_35 -> V_330 ;
V_315 = F_34 ( V_317 ) ;
if ( V_315 >=
V_35 -> V_127 [ V_329 ] &&
V_315 <
V_35 -> V_127 [ V_329 ] +
V_122 )
return;
V_342 = F_108 ( V_15 , V_52 ) ;
} while ( V_342 >= V_122 );
}
static void F_112 ( struct V_14 * V_15 ,
unsigned short V_166 , unsigned int V_318 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
struct V_161 * V_162 = V_15 -> V_266 ;
struct V_283 * V_284 ;
struct V_51 * V_52 ;
T_2 V_343 ;
unsigned long V_37 ;
if ( V_162 == NULL )
return;
V_284 = V_162 -> V_284 ;
V_52 = & V_284 -> V_52 ;
F_25 ( & V_15 -> V_38 , V_37 ) ;
V_343 = F_99 ( V_35 -> V_39 + V_261 ) ;
if ( V_318 & V_344 ) {
if ( ( V_343 & V_257 ) &&
! ( V_343 & V_333 ) )
F_86 ( V_257 | V_259 ,
V_35 -> V_39 + V_261 ) ;
else
F_86 ( V_259 ,
V_35 -> V_39 + V_261 ) ;
F_27 ( & V_15 -> V_38 , V_37 ) ;
if ( V_343 & V_257 ) {
F_111 ( V_15 , V_52 ) ;
if ( F_103 ( V_15 , V_343 ) )
F_104 ( V_15 ) ;
}
} else {
F_27 ( & V_15 -> V_38 , V_37 ) ;
}
if ( ( V_166 & V_345 ) ) {
if ( ( V_52 -> V_245 == V_244 &&
V_284 -> V_327 >= V_52 -> V_250 ) ||
F_102 ( V_15 ) )
V_284 -> V_321 |= V_322 ;
else
V_284 -> V_321 |= V_323 ;
}
F_100 ( V_15 , V_162 ) ;
}
static T_5 F_113 ( int V_346 , void * V_347 )
{
struct V_14 * V_15 = V_347 ;
struct V_34 * V_35 = V_15 -> V_36 ;
unsigned short V_166 ;
T_3 V_318 ;
T_3 V_348 ;
V_318 = F_34 ( V_35 -> V_39 + V_41 ) ;
V_166 = F_57 ( V_35 -> V_49 + V_167 ) ;
if ( ! V_15 -> V_349 )
return V_350 ;
F_98 ( V_15 , V_166 , V_318 ) ;
F_112 ( V_15 , V_166 , V_318 ) ;
if ( V_318 & V_351 ) {
V_348 = F_34 ( V_35 -> V_39 + V_352 ) ;
F_29 ( V_348 , V_35 -> V_39 + V_352 ) ;
}
return V_350 ;
}
static int F_114 ( struct V_14 * V_15 , struct V_161 * V_162 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
unsigned long V_37 ;
F_25 ( & V_15 -> V_38 , V_37 ) ;
if ( V_35 -> V_301 == 0 ) {
F_27 ( & V_15 -> V_38 , V_37 ) ;
return 0 ;
}
V_35 -> V_301 = 0 ;
F_27 ( & V_15 -> V_38 , V_37 ) ;
F_36 ( V_15 ) ;
F_24 ( V_15 , 1 ) ;
return 0 ;
}
static int F_115 ( struct V_14 * V_15 , struct V_161 * V_162 ,
struct V_163 * V_164 , unsigned int * V_156 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_34 * V_35 = V_15 -> V_36 ;
int V_234 = F_59 ( V_164 -> V_173 ) ;
int V_24 = F_60 ( V_164 -> V_173 ) ;
F_31 ( 0 , V_35 -> V_49 + V_353 ) ;
F_22 ( V_15 , & V_35 -> V_114 , V_234 , V_24 ) ;
F_31 ( V_35 -> V_114 ,
V_35 -> V_49 + V_354 ) ;
if ( V_17 -> V_10 == V_11 ) {
F_31 ( V_156 [ 0 ] & 0xff ,
V_35 -> V_49 + F_2 ( V_234 ) ) ;
F_31 ( ( V_156 [ 0 ] >> 8 ) & 0xf ,
V_35 -> V_49 + F_3 ( V_234 ) ) ;
} else {
F_31 ( V_156 [ 0 ] , V_35 -> V_49 + F_1 ( V_234 ) ) ;
}
V_162 -> V_355 [ V_234 ] = V_156 [ 0 ] ;
return 1 ;
}
static void F_116 ( struct V_14 * V_15 ,
const struct V_51 * V_52 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
unsigned int V_26 = V_356 | V_357 |
V_358 | V_359 ;
if ( V_52 -> V_239 == V_240 ) {
V_26 |= V_360 ;
if ( V_52 -> V_247 & V_297 )
V_26 |= V_361 ;
} else {
V_26 |= V_362 ;
}
if ( V_52 -> V_228 == V_240 ) {
V_26 |= V_363 ;
if ( V_52 -> V_229 & V_297 )
V_26 |= V_364 ;
}
F_31 ( V_26 , V_35 -> V_49 + V_353 ) ;
}
static void F_117 ( struct V_14 * V_15 ,
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
V_35 -> V_114 |= V_365 ;
F_31 ( V_35 -> V_114 ,
V_35 -> V_49 + V_354 ) ;
}
static void F_118 ( struct V_14 * V_15 ,
const struct V_51 * V_52 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
T_1 V_26 ;
unsigned int V_366 , V_367 ;
V_366 = F_59 ( V_52 -> V_232 [ 0 ] ) ;
V_367 = F_59 ( V_52 -> V_232 [ V_52 -> V_230 - 1 ] ) ;
if ( V_367 < V_366 )
F_20 ( V_15 -> V_28 ,
L_14 ) ;
V_26 = ( V_366 & 0x7 ) | ( V_367 & 0x7 ) << 3 ;
F_31 ( V_26 , V_35 -> V_49 + V_368 ) ;
}
static unsigned int F_119 ( unsigned int V_210 , unsigned int V_37 )
{
return F_69 ( V_210 , V_37 ) - 2 ;
}
static void F_120 ( struct V_14 * V_15 ,
const struct V_51 * V_52 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
unsigned int V_202 ;
if ( V_52 -> V_228 != V_225 )
return;
V_202 = F_119 ( V_52 -> V_229 , V_52 -> V_37 ) ;
if ( V_202 > V_220 ) {
F_20 ( V_15 -> V_28 , L_15 ) ;
V_202 = V_220 ;
}
F_31 ( V_202 & 0xffff ,
V_35 -> V_49 + V_369 ) ;
F_31 ( ( V_202 >> 16 ) & 0xff ,
V_35 -> V_49 + V_370 ) ;
}
static int F_121 ( struct V_14 * V_15 , const struct V_51 * V_52 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
struct V_161 * V_162 = V_15 -> V_266 ;
unsigned int V_311 ;
unsigned int V_340 ;
int V_120 ;
F_31 ( 0 , V_35 -> V_49 + V_269 ) ;
F_31 ( 0 , V_35 -> V_49 + V_268 ) ;
V_311 = F_105 ( V_15 , V_162 ,
V_35 -> V_371 ,
V_372 ) ;
if ( V_311 == 0 )
return - 1 ;
for ( V_120 = 0 ; V_120 < V_311 ; V_120 ++ ) {
F_31 ( V_35 -> V_371 [ V_120 ] ,
V_35 -> V_49 + V_143 ) ;
}
if ( V_52 -> V_245 == V_244 &&
V_162 -> V_284 -> V_327 >= V_52 -> V_250 )
return 0 ;
V_340 = F_108 ( V_15 , V_52 ) ;
if ( V_340 == 0 )
return - 1 ;
F_111 ( V_15 , V_52 ) ;
F_85 ( V_15 , 0 ) ;
return 0 ;
}
static inline int F_122 ( struct V_14 * V_15 ,
struct V_161 * V_162 ,
struct V_51 * V_52 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
if ( V_162 -> V_267 )
return 0 ;
if ( V_17 -> V_10 == V_11 )
return 0 ;
else if ( F_88 ( V_52 ) )
return 0 ;
return 1 ;
}
static int F_123 ( struct V_14 * V_15 , struct V_161 * V_162 ,
unsigned int V_373 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
struct V_51 * V_52 = & V_162 -> V_284 -> V_52 ;
int V_101 ;
if ( V_373 != V_52 -> V_247 )
return - V_197 ;
V_101 = F_121 ( V_15 , V_52 ) ;
if ( V_101 < 0 )
return - V_374 ;
F_116 ( V_15 , V_52 ) ;
if ( V_52 -> V_239 == V_375 )
F_31 ( 0 , V_35 -> V_49 + V_376 ) ;
V_162 -> V_284 -> V_377 = NULL ;
return 0 ;
}
static int F_124 ( struct V_14 * V_15 , struct V_161 * V_162 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
struct V_51 * V_52 = & V_162 -> V_284 -> V_52 ;
if ( F_122 ( V_15 , V_162 , V_52 ) ) {
F_47 ( V_15 ) ;
return - V_169 ;
}
F_31 ( 0x0 , V_35 -> V_49 + V_353 ) ;
V_35 -> V_330 = 0 ;
F_118 ( V_15 , V_52 ) ;
F_120 ( V_15 , V_52 ) ;
F_90 ( V_15 , 0 , V_35 -> V_132 |
V_140 | V_141 ) ;
F_117 ( V_15 , V_52 ) ;
V_162 -> V_284 -> V_377 = F_123 ;
return 0 ;
}
static int F_125 ( struct V_14 * V_15 ,
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
static int F_126 ( struct V_14 * V_15 , struct V_161 * V_162 ,
struct V_51 * V_52 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
int V_235 = 0 ;
unsigned int V_236 ;
V_235 |= F_73 ( & V_52 -> V_239 , V_375 | V_240 ) ;
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
V_17 -> V_378 ) ;
if ( F_119 ( V_52 -> V_229 , V_52 -> V_37 ) >
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
V_235 |= F_125 ( V_15 , V_162 , V_52 ) ;
if ( V_235 )
return 5 ;
return 0 ;
}
static int F_127 ( struct V_14 * V_15 , struct V_161 * V_162 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
F_31 ( 0x0 , V_35 -> V_49 + V_353 ) ;
F_24 ( V_15 , 0 ) ;
return 0 ;
}
static int F_128 ( struct V_14 * V_15 ,
int V_379 , int V_380 , int V_156 , unsigned long V_381 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
if ( V_379 ) {
F_31 ( V_156 , V_35 -> V_49 + V_381 + 2 * V_380 ) ;
return 0 ;
}
return F_57 ( V_35 -> V_49 + V_381 + 2 * V_380 ) ;
}
static int F_129 ( struct V_14 * V_15 , struct V_161 * V_162 ,
struct V_163 * V_164 , unsigned int * V_156 )
{
unsigned int V_26 ;
V_26 = F_99 ( V_15 -> V_194 + V_382 ) ;
V_26 &= 0xf ;
V_156 [ 1 ] = V_26 ;
V_156 [ 0 ] = 0 ;
return V_164 -> V_170 ;
}
static int F_130 ( struct V_14 * V_15 ,
struct V_161 * V_162 ,
struct V_163 * V_164 ,
unsigned int * V_156 )
{
if ( F_131 ( V_162 , V_156 ) )
F_86 ( V_162 -> V_144 , V_15 -> V_194 + V_383 ) ;
V_156 [ 1 ] = V_162 -> V_144 ;
return V_164 -> V_170 ;
}
static int F_132 ( struct V_14 * V_15 ,
struct V_161 * V_162 ,
struct V_163 * V_164 ,
unsigned int * V_156 )
{
int V_172 ;
V_172 = F_133 ( V_15 , V_162 , V_164 , V_156 , 0 ) ;
if ( V_172 )
return V_172 ;
F_86 ( V_162 -> V_384 , V_15 -> V_194 + V_385 ) ;
return V_164 -> V_170 ;
}
static int F_134 ( struct V_14 * V_15 ,
struct V_161 * V_162 ,
struct V_163 * V_164 ,
unsigned int * V_156 )
{
if ( F_131 ( V_162 , V_156 ) )
F_86 ( V_162 -> V_144 , V_15 -> V_194 + V_386 ) ;
V_156 [ 1 ] = F_99 ( V_15 -> V_194 + V_386 ) ;
return V_164 -> V_170 ;
}
static int F_135 ( struct V_14 * V_15 , unsigned int V_155 ,
T_2 V_387 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
static const int V_388 = 8 ;
static const int V_389 = 11 ;
unsigned int V_158 = ( ( V_155 & 0x7 ) << 8 ) | V_387 ;
unsigned int V_153 , V_390 ;
static const int V_391 = 1 ;
if ( V_155 >= V_388 ) {
F_20 ( V_15 -> V_28 , L_16 ) ;
return - 1 ;
}
for ( V_153 = 1 << ( V_389 - 1 ) ; V_153 ; V_153 >>= 1 ) {
V_390 = 0 ;
if ( V_158 & V_153 )
V_390 |= V_392 ;
F_49 ( V_391 ) ;
F_31 ( V_390 , V_35 -> V_49 + V_112 ) ;
V_390 |= V_393 ;
F_49 ( V_391 ) ;
F_31 ( V_390 , V_35 -> V_49 + V_112 ) ;
}
F_49 ( V_391 ) ;
F_31 ( V_394 , V_35 -> V_49 + V_112 ) ;
F_49 ( V_391 ) ;
F_31 ( 0 , V_35 -> V_49 + V_112 ) ;
F_49 ( V_391 ) ;
return 0 ;
}
static int F_136 ( struct V_14 * V_15 ,
unsigned int V_395 , unsigned int V_387 )
{
T_2 V_396 [ 3 ] ;
T_2 V_397 ;
enum T_6 {
V_398 = 0x1 ,
V_399 = 0x2 ,
V_400 = 0x4 ,
V_401 = 0x8 ,
};
enum T_7 {
V_402 = 0x20 ,
};
switch ( V_395 ) {
case 0 :
V_397 = V_403 ;
V_396 [ 0 ] = V_398 ;
break;
case 1 :
V_397 = V_403 ;
V_396 [ 0 ] = V_400 ;
break;
case 2 :
V_397 = V_404 ;
V_396 [ 0 ] = V_398 ;
break;
case 3 :
V_397 = V_404 ;
V_396 [ 0 ] = V_400 ;
break;
case 4 :
V_397 = V_403 ;
V_396 [ 0 ] = V_399 ;
break;
case 5 :
V_397 = V_403 ;
V_396 [ 0 ] = V_401 ;
break;
case 6 :
V_397 = V_404 ;
V_396 [ 0 ] = V_399 ;
break;
case 7 :
V_397 = V_404 ;
V_396 [ 0 ] = V_401 ;
break;
default:
F_20 ( V_15 -> V_28 , L_17 ) ;
return - 1 ;
}
V_396 [ 1 ] = V_402 | ( ( V_387 >> 8 ) & 0xf ) ;
V_396 [ 2 ] = V_387 & 0xff ;
F_55 ( V_15 , V_397 , V_396 , 3 ) ;
return 0 ;
}
static void F_137 ( struct V_14 * V_15 , unsigned int V_1 ,
unsigned int V_387 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
switch ( V_17 -> V_10 ) {
case V_20 :
case V_19 :
F_135 ( V_15 , V_1 , V_387 ) ;
break;
case V_11 :
F_136 ( V_15 , V_1 , V_387 ) ;
break;
default:
break;
}
}
static int F_138 ( struct V_14 * V_15 ,
struct V_161 * V_162 ,
struct V_163 * V_164 ,
unsigned int * V_156 )
{
unsigned int V_234 = F_59 ( V_164 -> V_173 ) ;
if ( V_164 -> V_170 ) {
unsigned int V_310 = V_156 [ V_164 -> V_170 - 1 ] ;
if ( V_162 -> V_355 [ V_234 ] != V_310 ) {
F_137 ( V_15 , V_234 , V_310 ) ;
V_162 -> V_355 [ V_234 ] = V_310 ;
}
}
return V_164 -> V_170 ;
}
static void F_139 ( struct V_14 * V_15 , unsigned int V_1 ,
unsigned int V_387 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
static const int V_389 = 10 ;
unsigned int V_153 , V_390 ;
unsigned int V_158 = ( ( V_1 & 0x3 ) << 8 ) | ( V_387 & 0xff ) ;
static const int V_405 = 1 ;
V_390 = V_406 ;
F_49 ( V_405 ) ;
F_31 ( V_390 , V_35 -> V_49 + V_112 ) ;
for ( V_153 = 1 << ( V_389 - 1 ) ; V_153 ; V_153 >>= 1 ) {
if ( V_158 & V_153 )
V_390 |= V_392 ;
else
V_390 &= ~ V_392 ;
F_49 ( V_405 ) ;
F_31 ( V_390 , V_35 -> V_49 + V_112 ) ;
F_49 ( V_405 ) ;
F_31 ( V_390 | V_393 ,
V_35 -> V_49 + V_112 ) ;
}
F_49 ( V_405 ) ;
F_31 ( 0 , V_35 -> V_49 + V_112 ) ;
}
static int F_140 ( struct V_14 * V_15 ,
struct V_161 * V_162 ,
struct V_163 * V_164 ,
unsigned int * V_156 )
{
unsigned int V_234 = F_59 ( V_164 -> V_173 ) ;
if ( V_164 -> V_170 ) {
unsigned int V_310 = V_156 [ V_164 -> V_170 - 1 ] ;
if ( V_162 -> V_355 [ V_234 ] != V_310 ) {
F_139 ( V_15 , V_234 , V_310 ) ;
V_162 -> V_355 [ V_234 ] = V_310 ;
}
}
return V_164 -> V_170 ;
}
static T_1 F_141 ( struct V_14 * V_15 , T_2 V_155 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
static const int V_389 = 11 ;
static const int V_407 = 0x6 ;
unsigned int V_158 = ( V_407 << 8 ) | V_155 ;
unsigned int V_153 ;
void T_4 * const V_147 =
V_35 -> V_39 + V_57 ;
T_1 V_387 ;
static const int V_408 = 16 ;
static const int V_409 = 1 ;
F_49 ( V_409 ) ;
V_35 -> V_56 &= ~ V_410 & ~ V_160 ;
V_35 -> V_56 |= V_151 ;
F_29 ( V_35 -> V_56 , V_147 ) ;
F_49 ( V_409 ) ;
V_35 -> V_56 |= V_160 ;
F_29 ( V_35 -> V_56 , V_147 ) ;
for ( V_153 = 1 << ( V_389 - 1 ) ; V_153 ; V_153 >>= 1 ) {
F_49 ( V_409 ) ;
if ( V_158 & V_153 )
V_35 -> V_56 |= V_146 ;
else
V_35 -> V_56 &= ~ V_146 ;
F_29 ( V_35 -> V_56 , V_147 ) ;
F_49 ( V_409 ) ;
V_35 -> V_56 |= V_410 ;
F_29 ( V_35 -> V_56 , V_147 ) ;
F_49 ( V_409 ) ;
V_35 -> V_56 &= ~ V_410 ;
F_29 ( V_35 -> V_56 , V_147 ) ;
}
V_387 = 0 ;
for ( V_153 = 1 << ( V_408 - 1 ) ; V_153 ; V_153 >>= 1 ) {
F_49 ( V_409 ) ;
V_35 -> V_56 |= V_410 ;
F_29 ( V_35 -> V_56 , V_147 ) ;
F_49 ( V_409 ) ;
V_35 -> V_56 &= ~ V_410 ;
F_29 ( V_35 -> V_56 , V_147 ) ;
F_49 ( V_409 ) ;
if ( F_34 ( V_147 ) & V_411 )
V_387 |= V_153 ;
}
F_49 ( V_409 ) ;
V_35 -> V_56 &= ~ V_160 ;
F_29 ( V_35 -> V_56 , V_147 ) ;
return V_387 ;
}
static int F_142 ( struct V_14 * V_15 ,
struct V_161 * V_162 ,
struct V_163 * V_164 , unsigned int * V_156 )
{
V_156 [ 0 ] = F_141 ( V_15 , F_59 ( V_164 -> V_173 ) ) ;
return 1 ;
}
static int F_143 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = V_15 -> V_18 ;
struct V_34 * V_35 = V_15 -> V_36 ;
struct V_161 * V_162 ;
int V_120 ;
int V_172 ;
V_172 = F_144 ( V_15 , 10 ) ;
if ( V_172 )
return V_172 ;
V_162 = & V_15 -> V_412 [ 0 ] ;
V_15 -> V_303 = V_162 ;
V_162 -> type = V_413 ;
V_162 -> V_414 = V_415 | V_416 | V_417 | V_418 ;
if ( V_17 -> V_10 == V_20 )
V_162 -> V_414 |= V_419 | V_420 ;
else if ( V_17 -> V_10 == V_19 )
V_162 -> V_414 |= V_420 ;
V_162 -> V_421 = V_17 -> V_422 ;
V_162 -> V_423 = 0x2000 ;
V_162 -> V_424 = ( 1 << V_17 -> V_425 ) - 1 ;
V_162 -> V_426 = V_17 -> V_25 ;
V_162 -> V_427 = F_58 ;
V_162 -> V_428 = F_68 ;
V_162 -> V_429 = F_91 ;
V_162 -> V_430 = F_72 ;
V_162 -> V_431 = F_114 ;
if ( V_17 -> V_10 == V_11 ) {
T_2 V_156 ;
V_35 -> V_188 = F_15 ( 4 ) ;
for ( V_120 = 0 ; V_120 < V_162 -> V_421 ; V_120 ++ )
V_35 -> V_188 |= F_16 ( V_120 ) ;
V_156 = V_35 -> V_188 ;
F_55 ( V_15 , V_190 , & V_156 , sizeof( V_156 ) ) ;
}
V_162 = & V_15 -> V_412 [ 1 ] ;
if ( V_17 -> V_33 ) {
V_162 -> type = V_432 ;
V_162 -> V_414 = V_415 | V_433 |
V_416 | V_434 ;
V_162 -> V_421 = V_17 -> V_33 ;
V_162 -> V_424 = ( 1 << V_17 -> V_435 ) - 1 ;
V_162 -> V_426 = V_17 -> V_436 ;
V_162 -> V_437 = F_115 ;
V_172 = F_145 ( V_162 ) ;
if ( V_172 )
return V_172 ;
if ( F_23 ( V_17 ) ) {
V_15 -> V_266 = V_162 ;
V_162 -> V_430 = F_126 ;
V_162 -> V_429 = F_124 ;
V_162 -> V_423 = V_17 -> V_33 ;
V_162 -> V_431 = F_127 ;
}
} else {
V_162 -> type = V_438 ;
}
V_162 = & V_15 -> V_412 [ 2 ] ;
if ( V_17 -> V_10 == V_19 ) {
V_162 -> type = V_439 ;
V_162 -> V_414 = V_415 ;
V_162 -> V_421 = 4 ;
V_162 -> V_424 = 1 ;
V_162 -> V_426 = & V_440 ;
V_162 -> V_441 = F_129 ;
} else
V_162 -> type = V_438 ;
if ( V_17 -> V_10 == V_19 ) {
V_162 = & V_15 -> V_412 [ 3 ] ;
V_162 -> type = V_442 ;
V_162 -> V_414 = V_433 ;
V_162 -> V_421 = 4 ;
V_162 -> V_424 = 1 ;
V_162 -> V_426 = & V_440 ;
V_162 -> V_441 = F_130 ;
} else
V_162 -> type = V_438 ;
V_162 = & V_15 -> V_412 [ 4 ] ;
if ( V_17 -> V_443 ) {
if ( V_17 -> V_10 == V_11 ) {
V_172 = F_146 ( V_15 , V_162 , F_128 ,
V_444 ) ;
} else {
V_172 = F_147 ( V_15 , V_162 , NULL ,
V_445 ) ;
}
if ( V_172 )
return V_172 ;
} else {
V_162 -> type = V_438 ;
}
V_162 = & V_15 -> V_412 [ 5 ] ;
if ( V_17 -> V_10 == V_20 ) {
V_162 -> type = V_446 ;
V_162 -> V_414 = V_433 | V_415 ;
V_162 -> V_421 = 8 ;
V_162 -> V_424 = 1 ;
V_162 -> V_426 = & V_440 ;
V_162 -> V_428 = F_132 ;
V_162 -> V_441 = F_134 ;
} else
V_162 -> type = V_438 ;
V_162 = & V_15 -> V_412 [ 6 ] ;
V_162 -> type = V_447 ;
V_162 -> V_414 = V_415 | V_433 | V_448 ;
V_162 -> V_421 = 8 ;
if ( V_17 -> V_10 == V_11 )
V_162 -> V_424 = 0xfff ;
else
V_162 -> V_424 = 0xff ;
V_162 -> V_437 = F_138 ;
V_172 = F_145 ( V_162 ) ;
if ( V_172 )
return V_172 ;
for ( V_120 = 0 ; V_120 < V_162 -> V_421 ; V_120 ++ ) {
F_137 ( V_15 , V_120 , V_162 -> V_424 / 2 ) ;
V_162 -> V_355 [ V_120 ] = V_162 -> V_424 / 2 ;
}
V_162 = & V_15 -> V_412 [ 7 ] ;
if ( V_17 -> V_10 == V_19 ) {
V_162 -> type = V_447 ;
V_162 -> V_414 = V_415 | V_433 | V_448 ;
V_162 -> V_421 = 2 ;
V_162 -> V_424 = 0xff ;
V_162 -> V_437 = F_140 ;
V_172 = F_145 ( V_162 ) ;
if ( V_172 )
return V_172 ;
for ( V_120 = 0 ; V_120 < V_162 -> V_421 ; V_120 ++ ) {
F_139 ( V_15 , V_120 , V_162 -> V_424 / 2 ) ;
V_162 -> V_355 [ V_120 ] = V_162 -> V_424 / 2 ;
}
} else
V_162 -> type = V_438 ;
V_162 = & V_15 -> V_412 [ 8 ] ;
if ( F_34 ( V_35 -> V_39 + V_57 ) & V_449 ) {
V_162 -> type = V_450 ;
V_162 -> V_414 = V_415 | V_448 ;
V_162 -> V_421 = 128 ;
V_162 -> V_424 = 0xffff ;
V_162 -> V_427 = F_142 ;
} else
V_162 -> type = V_438 ;
V_162 = & V_15 -> V_412 [ 9 ] ;
V_162 -> type = V_438 ;
return 0 ;
}
static int F_148 ( struct V_14 * V_15 ,
unsigned long V_165 )
{
struct V_118 * V_119 = F_42 ( V_15 ) ;
const struct V_8 * V_17 = NULL ;
struct V_34 * V_35 ;
T_3 V_451 , V_452 ;
int V_101 ;
if ( V_165 < F_149 ( V_453 ) )
V_17 = & V_453 [ V_165 ] ;
if ( ! V_17 )
return - V_454 ;
V_15 -> V_18 = V_17 ;
V_35 = F_150 ( V_15 , sizeof( * V_35 ) ) ;
if ( ! V_35 )
return - V_124 ;
V_101 = F_151 ( V_15 ) ;
if ( V_101 )
return V_101 ;
F_152 ( V_119 ) ;
V_15 -> V_455 = V_17 -> V_456 ;
V_35 -> V_457 = F_153 ( V_119 , 2 ) ;
V_35 -> V_458 = F_153 ( V_119 , 3 ) ;
V_35 -> V_39 = F_154 ( V_119 , 0 ) ;
V_35 -> V_49 = F_154 ( V_119 , 2 ) ;
V_15 -> V_194 = F_154 ( V_119 , 3 ) ;
if ( ! V_35 -> V_39 || ! V_35 -> V_49 || ! V_15 -> V_194 ) {
F_155 ( V_15 -> V_28 , L_18 ) ;
return - V_124 ;
}
V_451 = F_34 ( V_35 -> V_39 + V_459 ) &
V_460 ;
V_452 = F_34 ( V_35 -> V_39 + V_461 ) &
V_451 & V_462 ;
V_35 -> V_137 = ( ( T_3 ) V_35 -> V_457 &
~ V_451 ) | V_452 ;
V_451 = F_34 ( V_35 -> V_39 + V_463 ) &
V_460 ;
V_452 = F_34 ( V_35 -> V_39 + V_464 ) &
V_451 & V_462 ;
V_35 -> V_135 = ( ( T_3 ) V_35 -> V_458 &
~ V_451 ) | V_452 ;
V_101 = F_41 ( V_15 ) ;
if ( V_101 < 0 )
return V_101 ;
V_35 -> F_21 =
F_21 ( V_15 , F_57 ( V_35 -> V_49 + V_167 ) ) ;
F_64 ( V_15 -> V_28 , L_19 ,
V_35 -> F_21 ) ;
F_33 ( V_15 ) ;
F_40 ( V_15 ) ;
V_101 = F_156 ( V_119 -> V_346 , F_113 , V_465 ,
V_15 -> V_455 , V_15 ) ;
if ( V_101 ) {
F_64 ( V_15 -> V_28 , L_20 ,
V_119 -> V_346 ) ;
return V_101 ;
}
V_15 -> V_346 = V_119 -> V_346 ;
F_64 ( V_15 -> V_28 , L_21 , V_15 -> V_346 ) ;
V_101 = F_143 ( V_15 ) ;
if ( V_101 < 0 )
return V_101 ;
return 0 ;
}
static void F_157 ( struct V_14 * V_15 )
{
struct V_34 * V_35 = V_15 -> V_36 ;
if ( V_15 -> V_346 )
F_158 ( V_15 -> V_346 , V_15 ) ;
if ( V_35 ) {
if ( V_35 -> V_39 ) {
F_28 ( V_15 ) ;
F_159 ( V_35 -> V_39 ) ;
}
if ( V_35 -> V_49 )
F_159 ( V_35 -> V_49 ) ;
if ( V_15 -> V_194 )
F_159 ( V_15 -> V_194 ) ;
}
F_160 ( V_15 ) ;
F_45 ( V_15 ) ;
}
static int F_161 ( struct V_118 * V_15 ,
const struct V_466 * V_206 )
{
return F_162 ( V_15 , & V_467 ,
V_206 -> V_468 ) ;
}
