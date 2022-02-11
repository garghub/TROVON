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
F_33 ( L_4 , V_32 -> V_39 ) ;
}
static void F_34 ( struct V_14 * V_15 ,
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
F_33 ( L_4 , V_32 -> V_39 ) ;
F_28 ( & V_15 -> V_35 , V_34 ) ;
}
static void F_35 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
T_3 V_25 ;
void T_4 * V_52 = V_32 -> V_36 ;
V_32 -> V_53 =
F_36 ( V_32 -> V_36 + V_54 ) ;
F_33 ( L_5 ,
F_36 ( V_52 + V_38 ) ) ;
F_33 ( L_6 , F_36 ( V_52 + V_55 ) ) ;
F_33 ( L_7 , V_32 -> V_53 ) ;
F_33 ( L_8 ,
F_36 ( V_52 + V_56 ) ) ;
F_33 ( L_9 ,
F_36 ( V_52 + V_57 ) ) ;
F_33 ( L_10 ,
F_36 ( V_52 + V_58 ) ) ;
F_33 ( L_11 ,
F_36 ( V_52 + V_59 ) ) ;
F_33 ( L_12 ,
F_36 ( V_52 + V_60 ) ) ;
F_33 ( L_13 ,
F_36 ( V_52 + V_61 ) ) ;
F_33 ( L_14 ,
F_36 ( V_52 + V_62 ) ) ;
F_33 ( L_15 ,
F_36 ( V_52 + V_63 ) ) ;
F_33 ( L_16 ,
F_36 ( V_52 + V_64 ) ) ;
F_33 ( L_17 ,
F_36 ( V_52 + V_65 ) ) ;
F_33 ( L_18 ,
F_37 ( V_52 + V_66 ) ) ;
F_33 ( L_19 ,
F_36 ( V_52 + V_67 ) ) ;
F_33 ( L_20 , F_36 ( V_52 + V_68 ) ) ;
#ifdef F_38
V_25 = V_69 | V_70 ;
#else
V_25 = 0 ;
#endif
F_30 ( V_25 , V_32 -> V_36 + V_68 ) ;
F_29 ( V_15 ) ;
F_25 ( V_15 , 0 ) ;
F_25 ( V_15 , 1 ) ;
V_25 = 0 ;
V_25 |= V_71 ;
V_25 |= V_72 ;
V_25 |= V_73 ;
V_25 |= V_74 ;
V_25 |= V_75 ;
V_25 |= V_76 ;
V_25 |= V_77 ;
V_25 |= V_78 ;
if ( V_17 -> V_10 == V_11 )
V_25 |= V_79 ;
else
V_25 |= V_80 ;
F_30 ( V_25 , V_52 + V_61 ) ;
if ( F_24 ( V_17 ) )
F_30 ( V_25 , V_52 + V_60 ) ;
V_32 -> V_37 |=
V_81 | V_82 | V_83 | V_84 | V_85 | V_86 |
V_87 | V_88 ;
F_30 ( V_32 -> V_37 ,
V_32 -> V_36 + V_38 ) ;
}
static void F_39 ( struct V_14 * V_15 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned long V_34 ;
F_31 ( V_15 ) ;
F_26 ( & V_15 -> V_35 , V_34 ) ;
V_32 -> V_89 &= ~ V_90 ;
F_32 ( V_32 -> V_89 ,
V_32 -> V_46 + V_91 ) ;
F_28 ( & V_15 -> V_35 , V_34 ) ;
F_32 ( V_92 | V_93 | V_94 ,
V_32 -> V_46 + V_95 ) ;
}
static int F_40 ( struct V_14 * V_15 ,
unsigned int V_96 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
static const int V_97 = 0x100 ;
const struct V_98 * const V_99 = V_17 -> V_100 ;
unsigned int V_101 ;
T_1 V_25 ;
if ( V_96 < V_97 )
V_96 = V_97 ;
if ( V_96 > V_99 -> V_102 )
V_96 = V_99 -> V_102 ;
V_101 = ( V_96 + V_97 / 2 ) / V_97 ;
V_25 = ( ~ ( V_101 - 1 ) ) & V_99 -> V_103 ;
V_32 -> V_104 &= ~ V_99 -> V_103 ;
V_32 -> V_104 |= V_25 ;
F_32 ( V_32 -> V_104 ,
V_32 -> V_46 + V_105 ) ;
V_32 -> V_106 = V_101 * V_97 ;
F_33 ( L_21 ,
V_32 -> V_106 ) ;
return V_32 -> V_106 ;
}
static int F_41 ( struct V_14 * V_15 , unsigned int V_107 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
unsigned int V_108 ;
int V_109 ;
const struct V_98 * const V_99 = V_17 -> V_100 ;
V_108 = V_107 / V_99 -> V_110 ;
V_109 = F_40 ( V_15 ,
V_108 /
V_99 -> V_111 ) ;
if ( V_109 < 0 )
return V_109 ;
V_107 = V_109 * V_99 -> V_111 * V_99 -> V_110 ;
F_33 ( L_22 , V_107 ) ;
return V_107 ;
}
static unsigned int F_42 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
return V_32 -> V_106 *
V_17 -> V_100 -> V_111 *
V_17 -> V_100 -> V_110 ;
}
static void F_43 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
T_1 V_25 ;
unsigned long V_34 ;
F_26 ( & V_15 -> V_35 , V_34 ) ;
if ( 1 )
V_32 -> V_89 |= V_112 ;
F_32 ( V_32 -> V_89 ,
V_32 -> V_46 + V_91 ) ;
F_32 ( 0xff , V_32 -> V_46 + V_113 ) ;
V_25 = V_114 | V_115 ;
if ( V_17 -> V_10 == V_11 )
V_25 |= V_116 ;
V_32 -> V_117 |= V_25 ;
F_32 ( V_32 -> V_117 ,
V_32 -> V_46 + V_118 ) ;
F_32 ( 0 , V_32 -> V_46 + V_119 ) ;
F_32 ( 0 , V_32 -> V_46 + V_120 ) ;
F_28 ( & V_15 -> V_35 , V_34 ) ;
V_32 -> V_104 |= V_121 ;
F_40 ( V_15 ,
V_17 -> V_100 -> V_102 ) ;
V_32 -> V_122 = V_123 ;
V_32 -> V_39 =
V_124 | V_125 ;
F_32 ( V_32 -> V_39 ,
V_32 -> V_46 + V_47 ) ;
F_39 ( V_15 ) ;
}
static int F_44 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_126 * V_127 = F_45 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
int V_128 ;
for ( V_128 = 0 ; V_128 < F_17 ( V_17 ) ; V_128 ++ ) {
V_32 -> V_129 [ V_128 ] =
F_46 ( V_127 , V_130 ,
& V_32 -> V_131 [ V_128 ] ) ;
if ( V_32 -> V_129 [ V_128 ] == NULL )
return - V_132 ;
}
for ( V_128 = 0 ; V_128 < V_133 ; V_128 ++ ) {
if ( F_24 ( V_17 ) ) {
V_32 -> V_134 [ V_128 ] =
F_46 ( V_127 , V_130 ,
& V_32 ->
V_135 [ V_128 ] ) ;
if ( V_32 -> V_134 [ V_128 ] == NULL )
return - V_132 ;
}
}
V_32 -> V_136 =
F_46 ( V_127 , sizeof( struct V_137 ) *
F_17 ( V_17 ) ,
& V_32 -> V_138 ) ;
if ( V_32 -> V_136 == NULL )
return - V_132 ;
F_33 ( L_23 ,
( unsigned long long ) V_32 -> V_138 ) ;
if ( F_24 ( V_17 ) ) {
V_32 -> V_139 =
F_46 ( V_127 ,
sizeof( struct V_137 ) *
V_133 ,
& V_32 -> V_140 ) ;
if ( V_32 -> V_139 == NULL )
return - V_132 ;
F_33 ( L_24 ,
( unsigned long long ) V_32 -> V_140 ) ;
}
for ( V_128 = 0 ; V_128 < F_17 ( V_17 ) ; V_128 ++ ) {
V_32 -> V_136 [ V_128 ] . V_141 =
F_47 ( V_32 -> V_131 [ V_128 ] ) ;
if ( V_17 -> V_10 == V_11 )
V_32 -> V_136 [ V_128 ] . V_142 =
F_47 ( V_32 -> V_143 +
V_144 ) ;
else
V_32 -> V_136 [ V_128 ] . V_142 =
F_47 ( V_32 -> V_145 +
V_144 ) ;
V_32 -> V_136 [ V_128 ] . V_146 = F_47 ( 0 ) ;
V_32 -> V_136 [ V_128 ] . V_147 =
F_47 ( ( V_32 -> V_138 +
( ( V_128 + 1 ) % F_17 ( V_17 ) ) *
sizeof( V_32 -> V_136 [ 0 ] ) ) |
V_148 | V_149 |
V_150 ) ;
}
if ( F_24 ( V_17 ) ) {
for ( V_128 = 0 ; V_128 < V_133 ; V_128 ++ ) {
V_32 -> V_139 [ V_128 ] . V_141 =
F_47 ( V_32 -> V_135 [ V_128 ] ) ;
V_32 -> V_139 [ V_128 ] . V_142 =
F_47 ( V_32 -> V_145 +
V_151 ) ;
V_32 -> V_139 [ V_128 ] . V_146 = F_47 ( 0 ) ;
V_32 -> V_139 [ V_128 ] . V_147 =
F_47 ( ( V_32 -> V_140 +
( ( V_128 + 1 ) % ( V_133 ) ) *
sizeof( V_32 -> V_139 [ 0 ] ) ) |
V_148 |
V_149 ) ;
}
}
return 0 ;
}
static inline void F_48 ( struct V_14 * V_15 )
{
F_21 ( V_15 ,
L_25 ) ;
F_21 ( V_15 ,
L_26 ) ;
}
static void F_49 ( struct V_14 * V_15 , int V_152 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
static const int V_153 = V_154 ;
void T_4 * V_155 = V_32 -> V_36 +
V_54 ;
if ( V_152 ) {
V_32 -> V_53 &= ~ V_153 ;
F_30 ( V_32 -> V_53 , V_155 ) ;
F_50 ( V_156 ) ;
} else {
V_32 -> V_53 |= V_153 ;
F_30 ( V_32 -> V_53 , V_155 ) ;
F_50 ( V_157 ) ;
}
}
static void F_51 ( struct V_14 * V_15 , int V_152 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
static const int V_158 = V_159 ;
void T_4 * V_155 = V_32 -> V_36 +
V_54 ;
if ( V_152 ) {
V_32 -> V_53 &= ~ V_158 ;
F_30 ( V_32 -> V_53 , V_155 ) ;
F_50 ( V_156 ) ;
} else {
V_32 -> V_53 |= V_158 ;
F_30 ( V_32 -> V_53 , V_155 ) ;
F_50 ( V_157 ) ;
}
}
static void F_52 ( struct V_14 * V_15 , T_2 V_160 )
{
T_2 V_161 ;
unsigned int V_162 = 8 ;
F_33 ( L_27 , V_160 ) ;
for ( V_161 = 1 << ( V_162 - 1 ) ; V_161 ; V_161 >>= 1 ) {
F_51 ( V_15 , 0 ) ;
if ( ( V_160 & V_161 ) )
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
static void F_56 ( struct V_14 * V_15 , unsigned int V_163 ,
const T_2 * V_164 , unsigned int V_165 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_128 ;
T_2 V_166 ;
static const int V_167 = 0x1 ;
V_32 -> V_53 &= ~ V_168 ;
F_55 ( V_15 ) ;
F_54 ( V_15 ) ;
V_166 = ( V_163 << 1 ) & ~ V_167 ;
F_52 ( V_15 , V_166 ) ;
if ( F_53 ( V_15 ) != 0 ) {
F_21 ( V_15 , L_28 ) ;
F_55 ( V_15 ) ;
return;
}
for ( V_128 = 0 ; V_128 < V_165 ; V_128 ++ ) {
F_52 ( V_15 , V_164 [ V_128 ] ) ;
if ( F_53 ( V_15 ) != 0 ) {
F_21 ( V_15 , L_28 ) ;
F_55 ( V_15 ) ;
return;
}
}
F_55 ( V_15 ) ;
}
static int F_57 ( struct V_14 * V_15 , struct V_169 * V_170 ,
struct V_171 * V_172 , unsigned int * V_164 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_25 = 0 , V_173 , V_128 ;
unsigned int V_1 , V_23 , V_174 ;
unsigned long V_34 ;
static const int V_175 = 100 ;
F_33 ( L_29 , V_172 -> V_176 ) ;
V_1 = F_58 ( V_172 -> V_176 ) ;
V_23 = F_59 ( V_172 -> V_176 ) ;
V_174 = F_60 ( V_172 -> V_176 ) ;
F_39 ( V_15 ) ;
F_26 ( & V_15 -> V_35 , V_34 ) ;
if ( V_172 -> V_176 & V_177 )
V_32 -> V_89 |= V_178 ;
else
V_32 -> V_89 &= ~ V_178 ;
F_32 ( V_32 -> V_89 ,
V_32 -> V_46 + V_91 ) ;
F_28 ( & V_15 -> V_35 , V_34 ) ;
if ( V_17 -> V_10 != V_11 ) {
V_32 -> V_117 &= ~ V_179 ;
F_32 ( V_32 -> V_117 ,
V_32 -> V_46 + V_118 ) ;
if ( V_172 -> V_176 & V_180 ) {
unsigned int V_181 ;
F_33 ( L_30 ) ;
if ( V_17 -> V_10 == V_19 )
V_181 = V_182 ;
else
V_181 = V_183 ;
F_32 ( V_181 |
F_8 ( V_32 -> V_184 ) ,
V_32 -> V_46 + V_120 ) ;
} else {
F_32 ( 0 , V_32 -> V_46 + V_120 ) ;
}
V_25 = 0 ;
V_25 |= F_20 ( V_15 , F_59 ( V_172 -> V_176 ) ) ;
V_25 |= F_18 ( V_15 , V_174 == V_185 ) ;
if ( V_174 == V_186 )
V_25 |= V_187 ;
V_25 |= F_10 ( V_1 ) ;
F_32 ( F_10 ( V_1 ) ,
V_32 -> V_46 + V_188 ) ;
F_32 ( V_25 , V_32 -> V_46 + V_189 ) ;
} else {
T_2 V_190 = V_32 -> V_191 ;
V_32 -> V_191 &= ~ V_7 ;
if ( V_172 -> V_176 & V_180 ) {
F_33 ( L_30 ) ;
V_32 -> V_191 |=
F_15 ( V_32 -> V_184 ) ;
} else {
V_32 -> V_191 |= F_15 ( 4 ) ;
}
if ( V_23 == 0 )
V_32 -> V_191 |= F_16 ( V_1 ) ;
else
V_32 -> V_191 &= ~ F_16 ( V_1 ) ;
if ( V_190 != V_32 -> V_191 ) {
T_2 V_192 = V_32 -> V_191 ;
F_56 ( V_15 , V_193 , & V_192 ,
sizeof( V_192 ) ) ;
}
F_32 ( 0 , V_32 -> V_46 + V_113 ) ;
F_32 ( 2 , V_32 -> V_46 + V_194 ) ;
}
for ( V_173 = 0 ; V_173 < V_172 -> V_173 ; V_173 ++ ) {
F_32 ( 0 , V_32 -> V_46 + V_195 ) ;
F_32 ( F_9 ( F_58 ( V_172 -> V_176 ) ) ,
V_32 -> V_46 + V_196 ) ;
for ( V_128 = 0 ; V_128 < V_175 ; V_128 ++ ) {
V_25 = F_61 ( V_32 -> V_46 + V_197 ) ;
F_33 ( L_31 , F_11 ( V_25 ) ) ;
if ( V_17 -> V_10 == V_11 ) {
if ( F_61 ( V_32 -> V_46 +
V_198 ) )
break;
} else {
if ( F_11 ( V_25 ) )
break;
}
F_50 ( 1 ) ;
}
F_33 ( L_32 , V_128 ) ;
if ( V_128 == V_175 ) {
F_21 ( V_15 , L_33 ) ;
F_62 ( V_15 -> V_199 , L_34 , V_25 ) ;
return - V_200 ;
}
if ( V_17 -> V_10 == V_11 )
V_164 [ V_173 ] = F_36 ( V_32 -> V_201 +
V_144 ) & 0xffff ;
else
V_164 [ V_173 ] = F_61 ( V_32 -> V_46 + V_202 ) ;
}
return V_173 ;
}
static int F_63 ( struct V_14 * V_15 ,
unsigned int * V_164 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_4 = V_164 [ 1 ] ;
int V_203 ;
if ( V_17 -> V_10 == V_19 )
V_203 = 16 ;
else
V_203 = 8 ;
if ( V_4 >= V_203 ) {
F_64 ( V_15 -> V_199 , L_35 ,
V_4 ) ;
return - V_204 ;
}
F_33 ( L_36 , V_4 ) ;
V_32 -> V_184 = V_4 ;
return 2 ;
}
static int F_65 ( struct V_14 * V_15 , unsigned int * V_164 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
int V_205 ;
const struct V_98 * const V_99 = V_17 -> V_100 ;
unsigned int V_206 , V_207 ;
int V_109 ;
V_207 = V_164 [ 1 ] ;
if ( V_207 ) {
V_205 = V_207 * V_99 -> V_111 /
V_208 ;
V_109 = F_41 ( V_15 , V_205 ) ;
if ( V_109 < 0 )
return V_109 ;
}
V_206 = F_42 ( V_15 ) / V_99 -> V_111 * V_208 ;
V_164 [ 1 ] = V_206 ;
return 2 ;
}
static int F_66 ( struct V_14 * V_15 ,
unsigned int * V_164 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_209 = V_164 [ 4 ] ;
int V_109 = 0 ;
if ( V_209 < 2 ) {
V_209 = 2 ;
V_109 = - V_210 ;
}
switch ( V_164 [ 1 ] ) {
case V_211 :
V_32 -> V_212 . V_209 = V_209 ;
V_32 -> V_212 . V_176 = V_164 [ 2 ] ;
break;
default:
return - V_204 ;
break;
}
V_164 [ 4 ] = V_209 ;
return V_109 ? V_109 : 5 ;
}
static int F_67 ( struct V_14 * V_15 , unsigned int * V_164 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
switch ( V_17 -> V_10 ) {
case V_11 :
return F_66 ( V_15 , V_164 ) ;
break;
default:
return - V_204 ;
break;
}
return - V_204 ;
}
static int F_68 ( struct V_14 * V_15 , struct V_169 * V_170 ,
struct V_171 * V_172 , unsigned int * V_164 )
{
int V_213 = V_164 [ 0 ] ;
switch ( V_213 ) {
case V_214 :
return F_63 ( V_15 , V_164 ) ;
break;
case V_215 :
return F_65 ( V_15 , V_164 ) ;
break;
case V_216 :
return F_67 ( V_15 , V_164 ) ;
break;
default:
return - V_204 ;
break;
}
return - V_204 ;
}
static unsigned int F_69 ( unsigned int V_217 , unsigned int V_34 )
{
unsigned int V_209 ;
switch ( V_34 & V_218 ) {
case V_219 :
V_209 = ( V_217 + V_220 - 1 ) / V_220 ;
break;
case V_221 :
V_209 = V_217 / V_220 ;
break;
case V_222 :
default:
V_209 = ( V_217 + V_220 / 2 ) / V_220 ;
break;
}
return V_209 ;
}
static void F_70 ( struct V_14 * V_15 , struct V_48 * V_49 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
unsigned int V_223 = 0 , V_224 ;
static const int V_225 = 3 ;
static const int V_226 =
V_227 + V_225 ;
static const int V_228 = 2 ;
unsigned long long V_229 , V_230 ;
if ( V_49 -> V_231 == V_232 ) {
if ( V_17 -> V_10 == V_11 ) {
V_49 -> V_233 = 0 ;
} else {
V_223 = F_69 ( V_49 -> V_233 ,
V_49 -> V_34 ) ;
if ( V_223 > V_226 )
V_223 = V_226 ;
if ( V_223 < V_225 )
V_223 = V_225 ;
V_49 -> V_233 = V_223 * V_220 ;
}
} else if ( V_49 -> V_231 == V_234 ) {
V_49 -> V_233 = 0 ;
}
if ( V_49 -> V_235 == V_232 ) {
V_224 = F_69 ( V_49 -> V_236 , V_49 -> V_34 ) ;
if ( V_49 -> V_231 == V_232 ) {
V_230 = V_223 * V_49 -> V_237 ;
V_229 =
( V_223 * V_49 -> V_237 - 1 ) +
V_227 ;
} else {
V_230 = V_228 ;
V_229 = V_227 + V_230 ;
}
if ( V_224 > V_229 )
V_224 = V_229 ;
if ( V_224 < V_230 )
V_224 = V_230 ;
V_49 -> V_236 = V_224 * V_220 ;
}
return;
}
static int F_71 ( struct V_14 * V_15 , struct V_169 * V_170 ,
struct V_48 * V_49 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
int V_238 = 0 ;
unsigned int V_239 , V_240 ;
int V_128 ;
int V_174 ;
unsigned int V_241 ;
V_238 |= F_72 ( & V_49 -> V_242 , V_234 | V_243 ) ;
V_241 = V_232 ;
if ( V_17 -> V_10 == V_11 )
V_241 |= V_244 ;
else
V_241 |= V_245 ;
V_238 |= F_72 ( & V_49 -> V_235 , V_241 ) ;
V_241 = V_232 ;
if ( V_17 -> V_10 == V_11 )
V_241 |= V_234 ;
else
V_241 |= V_243 ;
V_238 |= F_72 ( & V_49 -> V_231 , V_241 ) ;
V_238 |= F_72 ( & V_49 -> V_246 , V_247 ) ;
V_238 |= F_72 ( & V_49 -> V_248 ,
V_247 | V_243 | V_249 ) ;
if ( V_238 )
return 1 ;
V_238 |= F_73 ( V_49 -> V_242 ) ;
V_238 |= F_73 ( V_49 -> V_235 ) ;
V_238 |= F_73 ( V_49 -> V_231 ) ;
V_238 |= F_73 ( V_49 -> V_248 ) ;
if ( V_49 -> V_231 == V_243 && V_49 -> V_235 == V_232 )
V_238 |= - V_204 ;
if ( V_49 -> V_248 != V_247 &&
V_49 -> V_248 != V_249 && V_49 -> V_248 != V_243 )
V_238 |= - V_204 ;
if ( V_238 )
return 2 ;
if ( V_49 -> V_231 == V_232 ) {
if ( V_17 -> V_10 == V_11 ) {
V_238 |= F_74 ( & V_49 -> V_233 , 0 ) ;
} else {
V_238 |= F_75 ( & V_49 -> V_233 ,
V_17 -> V_250 ) ;
if ( V_49 -> V_235 == V_232 )
V_238 |= F_75 (
& V_49 -> V_236 ,
V_49 -> V_233 *
V_49 -> V_237 ) ;
}
}
V_238 |= F_75 ( & V_49 -> V_237 , 1 ) ;
V_238 |= F_74 ( & V_49 -> V_251 , V_49 -> V_237 ) ;
switch ( V_49 -> V_248 ) {
case V_243 :
break;
case V_247 :
V_238 |= F_75 ( & V_49 -> V_252 , 1 ) ;
break;
case V_249 :
V_238 |= F_74 ( & V_49 -> V_252 , 0 ) ;
break;
default:
break;
}
if ( V_238 )
return 3 ;
if ( V_49 -> V_231 == V_232 ) {
V_239 = V_49 -> V_233 ;
V_240 = V_49 -> V_236 ;
F_70 ( V_15 , V_49 ) ;
if ( V_239 != V_49 -> V_233 )
V_238 ++ ;
if ( V_240 != V_49 -> V_236 )
V_238 ++ ;
}
if ( V_238 )
return 4 ;
if ( V_49 -> V_253 ) {
V_174 = F_60 ( V_49 -> V_253 [ 0 ] ) ;
for ( V_128 = 1 ; V_128 < V_49 -> V_237 ; V_128 ++ ) {
if ( V_174 != F_60 ( V_49 -> V_253 [ V_128 ] ) ) {
F_21 ( V_15 ,
L_37 ) ;
V_238 ++ ;
break;
}
}
if ( V_17 -> V_10 == V_11 ) {
unsigned int V_254 = F_58 ( V_49 -> V_253 [ 0 ] ) ;
for ( V_128 = 1 ; V_128 < V_49 -> V_237 ; V_128 ++ ) {
if ( F_58 ( V_49 -> V_253 [ V_128 ] ) !=
V_254 + V_128 ) {
F_21 ( V_15 ,
L_38 ) ;
V_238 ++ ;
break;
}
}
if ( V_49 -> V_237 == 3 ) {
F_21 ( V_15 ,
L_39 ) ;
V_238 ++ ;
}
}
}
if ( V_238 )
return 5 ;
return 0 ;
}
static int F_76 ( struct V_48 * V_49 )
{
return 0 ;
if ( V_49 -> V_248 == V_247 && V_49 -> V_252 <= V_227 )
return 1 ;
else
return 0 ;
}
static void F_77 ( struct V_14 * V_15 ,
struct V_48 * V_49 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
if ( V_49 -> V_248 == V_247 ) {
V_32 -> V_255 = V_49 -> V_252 * V_49 -> V_237 ;
}
if ( F_76 ( V_49 ) ) {
F_32 ( V_49 -> V_252 & 0xffff ,
V_32 -> V_46 + V_256 ) ;
F_32 ( ( V_49 -> V_252 >> 16 ) & 0xff ,
V_32 -> V_46 + V_257 ) ;
} else {
F_32 ( 1 , V_32 -> V_46 + V_256 ) ;
}
}
static inline unsigned int F_78 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_107 ;
V_107 = V_32 -> V_106 *
V_17 -> V_100 -> V_110 ;
if ( V_107 > V_130 / sizeof( T_1 ) )
V_107 = V_130 / sizeof( T_1 ) ;
return V_107 ;
}
static T_3 F_79 ( const struct V_14 * V_15 ,
const struct V_48 * V_49 )
{
return V_49 -> V_233 / V_220 - 3 ;
}
static T_3 F_80 ( struct V_14 * V_15 ,
struct V_48 * V_49 )
{
T_3 V_258 ;
switch ( V_49 -> V_235 ) {
case V_232 :
V_258 = ( V_49 -> V_236 -
( V_49 -> V_233 * ( V_49 -> V_237 - 1 ) ) ) /
V_220 ;
break;
case V_245 :
V_258 = V_49 -> V_233 / V_220 ;
break;
default:
return 0 ;
break;
}
return V_258 - 3 ;
}
static T_3 F_81 ( struct V_14 * V_15 ,
struct V_48 * V_49 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_209 ;
switch ( V_49 -> V_235 ) {
case V_232 :
V_209 = V_49 -> V_236 / V_220 ;
break;
case V_244 :
V_209 = V_32 -> V_212 . V_209 ;
break;
default:
F_21 ( V_15 , L_40 ) ;
V_209 = 1000 ;
break;
}
return V_209 - 2 ;
}
static void F_82 ( struct V_14 * V_15 ,
const struct V_48 * V_49 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
V_32 -> V_117 &= ~ V_259 ;
if ( V_49 -> V_235 == V_244 ) {
int V_176 = V_32 -> V_212 . V_176 ;
if ( F_58 ( V_176 ) )
V_32 -> V_117 |= V_260 ;
else
V_32 -> V_117 |= V_261 ;
} else {
V_32 -> V_117 |= V_116 ;
}
F_32 ( V_32 -> V_117 ,
V_32 -> V_46 + V_118 ) ;
}
static void F_83 ( struct V_14 * V_15 ,
const struct V_48 * V_49 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
switch ( V_17 -> V_10 ) {
case V_11 :
F_82 ( V_15 , V_49 ) ;
break;
default:
break;
}
}
static inline void F_84 ( struct V_14 * V_15 ,
unsigned int V_1 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned long V_34 ;
F_26 ( & V_15 -> V_35 , V_34 ) ;
if ( V_1 )
F_85 ( V_262 | V_263 |
V_264 ,
V_32 -> V_36 + V_265 ) ;
else
F_85 ( V_262 | V_263 |
V_264 ,
V_32 -> V_36 + V_66 ) ;
F_28 ( & V_15 -> V_35 , V_34 ) ;
}
static void F_86 ( struct V_14 * V_15 , struct V_48 * V_49 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
T_3 V_266 = 0 , V_267 = 0 ;
F_70 ( V_15 , V_49 ) ;
F_83 ( V_15 , V_49 ) ;
if ( V_17 -> V_10 == V_11 ) {
V_266 = F_81 ( V_15 , V_49 ) ;
} else {
V_266 = F_79 ( V_15 , V_49 ) ;
V_267 = F_80 ( V_15 , V_49 ) ;
}
F_32 ( V_266 & 0xffff ,
V_32 -> V_46 + V_194 ) ;
F_33 ( L_41 , V_266 ) ;
F_32 ( ( V_266 >> 16 ) & 0xff ,
V_32 -> V_46 + V_113 ) ;
F_32 ( V_267 & 0xffff ,
V_32 -> V_46 + V_268 ) ;
F_32 ( ( V_267 >> 16 ) & 0xff ,
V_32 -> V_46 + V_269 ) ;
F_33 ( L_42 , V_267 ) ;
}
static int F_87 ( const struct V_48 * V_49 )
{
int V_128 ;
for ( V_128 = 0 ; V_128 + 1 < V_49 -> V_237 ; V_128 ++ ) {
if ( F_58 ( V_49 -> V_253 [ V_128 + 1 ] ) !=
F_58 ( V_49 -> V_253 [ V_128 ] ) + 1 )
return 0 ;
if ( F_59 ( V_49 -> V_253 [ V_128 + 1 ] ) !=
F_59 ( V_49 -> V_253 [ V_128 ] ) )
return 0 ;
if ( F_60 ( V_49 -> V_253 [ V_128 + 1 ] ) != F_60 ( V_49 -> V_253 [ V_128 ] ) )
return 0 ;
}
return 1 ;
}
static int F_88 ( struct V_14 * V_15 ,
const struct V_48 * V_49 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned short V_25 ;
int V_128 ;
if ( V_17 -> V_10 != V_11 ) {
if ( F_87 ( V_49 ) ) {
V_32 -> V_117 &= ~ V_179 ;
F_32 ( V_32 -> V_117 ,
V_32 -> V_46 + V_118 ) ;
V_25 = 0 ;
V_25 |= F_10 ( F_58 ( V_49 -> V_253 [ 0 ] ) ) ;
V_25 |= F_20 ( V_15 ,
F_59 ( V_49 -> V_253 [ 0 ] ) ) ;
V_25 |= F_18 ( V_15 ,
F_60 ( V_49 -> V_253 [ 0 ] ) ==
V_185 ) ;
if ( F_60 ( V_49 -> V_253 [ 0 ] ) == V_186 )
V_25 |= V_187 ;
F_32 ( F_10
( F_58 ( V_49 -> V_253 [ V_49 -> V_237 - 1 ] ) ) ,
V_32 -> V_46 + V_188 ) ;
F_32 ( V_25 ,
V_32 -> V_46 + V_189 ) ;
} else {
if ( V_15 -> V_270 && V_15 -> V_270 -> V_271 ) {
F_48 ( V_15 ) ;
return - V_272 ;
}
V_32 -> V_117 |= V_179 ;
F_32 ( V_32 -> V_117 ,
V_32 -> V_46 + V_118 ) ;
F_32 ( 0 ,
V_32 -> V_46 + V_273 ) ;
F_32 ( 0 , V_32 -> V_46 + V_274 ) ;
for ( V_128 = 0 ; V_128 < V_49 -> V_237 ; V_128 ++ ) {
V_25 = 0 ;
V_25 |= F_10 ( F_58 ( V_49 ->
V_253 [ V_128 ] ) ) ;
V_25 |= F_20 ( V_15 ,
F_59 ( V_49 ->
V_253
[ V_128 ] ) ) ;
V_25 |= F_18 ( V_15 ,
F_60 ( V_49 ->
V_253 [ V_128 ] ) ==
V_185 ) ;
if ( F_60 ( V_49 -> V_253 [ V_128 ] ) == V_186 )
V_25 |= V_187 ;
if ( V_128 == V_49 -> V_237 - 1 )
V_25 |= V_275 |
V_276 ;
F_32 ( V_25 ,
V_32 -> V_46 +
V_277 ) ;
F_33 (
L_43 ,
V_25 ) ;
}
F_32 ( 0 , V_32 -> V_46 + V_274 ) ;
F_32 ( 0 , V_32 -> V_46 + V_189 ) ;
}
} else {
unsigned short V_190 = V_32 -> V_191 ;
V_32 -> V_191 &= ~ V_7 ;
V_32 -> V_191 |= F_15 ( 4 ) ;
for ( V_128 = 0 ; V_128 < V_49 -> V_237 ; V_128 ++ ) {
unsigned int V_1 = F_58 ( V_49 -> V_253 [ V_128 ] ) ;
unsigned int V_23 = F_59 ( V_49 -> V_253 [ V_128 ] ) ;
if ( V_23 == 0 )
V_32 -> V_191 |=
F_16 ( V_1 ) ;
else
V_32 -> V_191 &=
~ F_16 ( V_1 ) ;
}
if ( V_190 != V_32 -> V_191 ) {
T_2 V_192 = V_32 -> V_191 ;
F_56 ( V_15 , V_193 , & V_192 ,
sizeof( V_192 ) ) ;
}
}
return 0 ;
}
static inline void F_89 ( struct V_14 * V_15 ,
unsigned int V_278 ,
unsigned int V_279 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
if ( V_278 ) {
F_30 ( 0 ,
V_32 -> V_36 + V_280 ) ;
F_30 ( 0 , V_32 -> V_36 + V_281 ) ;
F_30 ( 0 ,
V_32 -> V_36 + V_282 ) ;
F_30 ( V_279 ,
V_32 -> V_36 + V_283 ) ;
} else {
F_30 ( 0 ,
V_32 -> V_36 + V_64 ) ;
F_30 ( 0 , V_32 -> V_36 + V_62 ) ;
F_30 ( 0 ,
V_32 -> V_36 + V_63 ) ;
F_30 ( V_279 ,
V_32 -> V_36 + V_65 ) ;
}
}
static int F_90 ( struct V_14 * V_15 , struct V_169 * V_170 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
struct V_284 * V_285 = V_170 -> V_285 ;
struct V_48 * V_49 = & V_285 -> V_49 ;
T_3 V_25 ;
unsigned int V_128 ;
unsigned long V_34 ;
int V_109 ;
F_39 ( V_15 ) ;
F_25 ( V_15 , 1 ) ;
V_109 = F_88 ( V_15 , V_49 ) ;
if ( V_109 < 0 )
return V_109 ;
F_32 ( 0 , V_32 -> V_46 + V_120 ) ;
F_86 ( V_15 , V_49 ) ;
F_77 ( V_15 , V_49 ) ;
F_34 ( V_15 , V_49 ) ;
F_26 ( & V_15 -> V_35 , V_34 ) ;
V_32 -> V_89 |= V_90 ;
V_32 -> V_89 &= ~ V_178 ;
if ( V_17 -> V_10 != V_11 ) {
V_32 -> V_89 &= ~ V_286 ;
if ( V_49 -> V_231 == V_243 )
V_32 -> V_89 |= F_7 ( 13 ) ;
else
V_32 -> V_89 |= F_7 ( 8 ) ;
} else {
V_32 -> V_89 &= ~ V_287 ;
if ( V_49 -> V_237 == 4 )
V_32 -> V_89 |= V_288 ;
else if ( V_49 -> V_237 == 2 )
V_32 -> V_89 |= V_289 ;
V_32 -> V_89 &= ~ V_290 ;
V_32 -> V_89 |=
F_5 ( F_58 ( V_49 -> V_253 [ 0 ] ) ) ;
V_32 -> V_89 &= ~ V_291 ;
V_32 -> V_89 |=
F_6 ( F_58 ( V_49 -> V_253
[ V_49 -> V_237 - 1 ] ) ) ;
}
F_32 ( V_32 -> V_89 ,
V_32 -> V_46 + V_91 ) ;
F_33 ( L_44 , V_32 -> V_89 ) ;
F_28 ( & V_15 -> V_35 , V_34 ) ;
F_32 ( 0 , V_32 -> V_46 + V_195 ) ;
if ( ( V_49 -> V_34 & V_50 ) == 0 ||
V_17 -> V_10 == V_11 ) {
V_32 -> V_292 = 0 ;
for ( V_128 = 0 ; V_128 < F_17 ( V_17 ) ; V_128 ++ )
V_32 -> V_136 [ V_128 ] . V_146 =
F_47 ( F_78 ( V_15 ) *
sizeof( T_1 ) ) ;
F_89 ( V_15 , 1 ,
V_32 -> V_138 |
V_148 |
V_149 |
V_150 ) ;
F_84 ( V_15 , 1 ) ;
}
if ( V_17 -> V_10 == V_11 ) {
V_25 = 0 ;
if ( V_49 -> V_242 == V_243 && F_58 ( V_49 -> V_293 ) )
V_25 |= V_294 ;
if ( V_49 -> V_248 == V_243 && F_58 ( V_49 -> V_252 ) )
V_25 |= V_295 ;
F_32 ( V_25 , V_32 -> V_46 + V_296 ) ;
}
F_26 ( & V_15 -> V_35 , V_34 ) ;
V_25 = V_297 | V_93 | V_94 ;
if ( V_49 -> V_34 & V_50 )
V_25 |= V_92 ;
if ( V_49 -> V_242 == V_243 ) {
V_25 |= V_298 ;
if ( V_49 -> V_293 & V_299 )
V_25 |= V_300 ;
} else if ( V_49 -> V_242 == V_234 )
V_25 |= V_301 ;
if ( F_76 ( V_49 ) )
V_25 |= V_302 ;
F_32 ( V_25 , V_32 -> V_46 + V_95 ) ;
F_33 ( L_45 , V_25 ) ;
V_32 -> V_303 = 1 ;
F_28 ( & V_15 -> V_35 , V_34 ) ;
if ( V_49 -> V_242 == V_234 ) {
F_32 ( 0 , V_32 -> V_46 + V_304 ) ;
F_33 ( L_46 ) ;
}
return 0 ;
}
static void F_91 ( struct V_14 * V_15 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
struct V_169 * V_170 = V_15 -> V_305 ;
struct V_284 * V_285 = V_170 -> V_285 ;
struct V_48 * V_49 = & V_285 -> V_49 ;
unsigned int V_128 ;
T_1 V_6 ;
int V_306 , V_307 , V_308 , V_309 ;
int V_107 ;
do {
V_307 = F_61 ( V_32 -> V_46 + V_310 ) &
0x7fff ;
V_309 = F_61 ( V_32 -> V_46 + V_198 ) &
0x7fff ;
V_6 = F_61 ( V_32 -> V_46 + V_311 ) ;
V_306 = F_13 ( V_6 ) ;
V_308 = F_14 ( V_6 ) ;
F_33 ( L_47 ,
V_306 , V_308 , V_307 ,
V_309 ) ;
if ( V_306 != V_308 )
V_107 =
V_32 -> V_106 - V_307 ;
else
V_107 = V_309 - V_307 ;
if ( V_49 -> V_248 == V_247 ) {
if ( V_32 -> V_255 == 0 )
break;
if ( V_107 > V_32 -> V_255 )
V_107 = V_32 -> V_255 ;
V_32 -> V_255 -= V_107 ;
}
if ( V_107 < 0 ) {
F_92 ( V_15 -> V_199 ,
L_48 ) ;
break;
}
F_33 ( L_49 , V_107 ) ;
for ( V_128 = 0 ; V_128 < V_107 ; V_128 ++ ) {
F_93 ( V_170 ,
F_61 ( V_32 -> V_46 +
V_144 ) ) ;
}
} while ( V_306 != V_308 );
}
static void F_94 ( struct V_14 * V_15 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
struct V_169 * V_170 = V_15 -> V_305 ;
struct V_284 * V_285 = V_170 -> V_285 ;
struct V_48 * V_49 = & V_285 -> V_49 ;
unsigned int V_128 ;
unsigned int V_312 = 100000 ;
T_3 V_313 ;
int V_314 =
F_61 ( V_32 -> V_46 + V_198 ) & 0x7fff ;
int V_315 =
F_61 ( V_32 -> V_46 + V_310 ) & 0x7fff ;
if ( V_49 -> V_248 == V_247 ) {
if ( V_312 > V_32 -> V_255 )
V_312 = V_32 -> V_255 ;
}
for ( V_128 = 0 ; V_315 != V_314 && V_128 < V_312 ; ) {
V_313 = F_36 ( V_32 -> V_201 + V_144 ) ;
F_93 ( V_170 , V_313 & 0xffff ) ;
V_128 ++ ;
if ( V_128 < V_312 ) {
F_93 ( V_170 , ( V_313 >> 16 ) & 0xffff ) ;
V_128 ++ ;
}
V_315 = F_61 ( V_32 -> V_46 + V_310 ) &
0x7fff ;
}
V_32 -> V_255 -= V_128 ;
}
static void F_95 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
if ( V_17 -> V_10 == V_11 )
F_94 ( V_15 ) ;
else
F_91 ( V_15 ) ;
}
static void F_96 ( struct V_14 * V_15 , unsigned int V_1 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
struct V_284 * V_285 = V_15 -> V_305 -> V_285 ;
T_3 V_316 ;
int V_317 ;
int V_107 = 0 ;
void T_4 * V_318 ;
if ( V_1 )
V_318 =
V_32 -> V_36 + V_281 ;
else
V_318 =
V_32 -> V_36 + V_62 ;
for ( V_317 = 0 , V_316 = F_36 ( V_318 ) ;
( V_316 <
V_32 -> V_131 [ V_32 -> V_292 ] ||
V_316 >=
V_32 -> V_131 [ V_32 -> V_292 ] +
V_130 ) && V_317 < F_17 ( V_17 ) ; V_317 ++ ) {
V_107 = F_78 ( V_15 ) ;
if ( V_285 -> V_49 . V_248 == V_247 ) {
if ( V_107 > V_32 -> V_255 )
V_107 = V_32 -> V_255 ;
V_32 -> V_255 -= V_107 ;
}
F_97 ( V_15 -> V_305 ,
V_32 -> V_129 [ V_32 ->
V_292 ] ,
V_107 * sizeof( T_1 ) ) ;
V_32 -> V_292 = ( V_32 -> V_292 + 1 ) %
F_17 ( V_17 ) ;
F_33 ( L_50 ,
( unsigned long ) V_32 ->
V_131 [ V_32 -> V_292 ] ) ;
F_33 ( L_51 , V_316 ) ;
}
}
static void F_98 ( struct V_14 * V_15 ,
unsigned short V_319 ,
unsigned int V_320 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
struct V_169 * V_170 = V_15 -> V_305 ;
struct V_284 * V_285 = V_170 -> V_285 ;
struct V_48 * V_49 = & V_285 -> V_49 ;
T_2 V_321 ;
unsigned long V_34 ;
if ( V_319 & V_322 ) {
F_21 ( V_15 , L_52 ) ;
V_285 -> V_323 |= V_324 | V_325 ;
}
F_26 ( & V_15 -> V_35 , V_34 ) ;
V_321 = F_37 ( V_32 -> V_36 + V_265 ) ;
if ( V_320 & V_326 ) {
F_85 ( ( V_321 & V_262 ) | V_264 ,
V_32 -> V_36 + V_265 ) ;
F_33 ( L_53 , V_321 ) ;
if ( V_321 & V_262 )
F_96 ( V_15 , 1 ) ;
F_33 ( L_54 ) ;
}
F_28 ( & V_15 -> V_35 , V_34 ) ;
if ( V_319 & V_327 )
F_33 ( L_55 ) ;
if ( ( V_319 & V_327 ) ||
( ( V_49 -> V_34 & V_50 ) &&
( V_319 & V_328 ) &&
( V_17 -> V_10 != V_11 ) ) ) {
F_33 ( L_56 ) ;
F_26 ( & V_15 -> V_35 , V_34 ) ;
if ( V_32 -> V_303 ) {
F_28 ( & V_15 -> V_35 , V_34 ) ;
F_95 ( V_15 ) ;
} else
F_28 ( & V_15 -> V_35 , V_34 ) ;
}
if ( ( V_49 -> V_248 == V_247 && ( int ) V_32 -> V_255 <= 0 ) ||
( V_49 -> V_248 == V_243 && ( V_319 & V_329 ) ) ) {
V_285 -> V_323 |= V_324 ;
}
F_99 ( V_15 , V_170 ) ;
}
static inline unsigned int F_100 ( struct V_14 * V_15 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_330 ;
if ( V_32 -> V_331 == 0 )
V_330 = V_133 - 1 ;
else
V_330 = V_32 -> V_331 - 1 ;
return V_330 ;
}
static int F_101 ( struct V_14 * V_15 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_330 ;
unsigned int V_332 ;
unsigned short V_333 ;
V_330 = F_100 ( V_15 ) ;
V_333 = F_37 ( V_32 -> V_36 + V_66 ) ;
if ( ( V_333 & V_334 ) == 0 )
return 0 ;
V_332 =
F_36 ( V_32 -> V_36 + V_62 ) ;
if ( V_332 != V_32 -> V_135 [ V_330 ] )
return 0 ;
return 1 ;
}
static int F_102 ( struct V_14 * V_15 ,
const struct V_48 * V_49 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
if ( V_49 -> V_248 == V_249 )
return 1 ;
if ( V_49 -> V_248 == V_247 ) {
if ( V_32 -> V_335 )
return 1 ;
if ( F_101 ( V_15 ) == 0 )
return 1 ;
}
return 0 ;
}
static inline int F_103 ( struct V_14 * V_15 ,
unsigned short V_333 )
{
if ( ( V_333 & V_334 ) == 0 ||
( V_333 & V_262 ) == 0 )
return 0 ;
if ( F_101 ( V_15 ) )
return 0 ;
return 1 ;
}
static void F_104 ( struct V_14 * V_15 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_336 ;
V_336 =
F_36 ( V_32 -> V_36 + V_65 ) ;
V_336 &= ~ V_337 ;
F_33 ( L_57 , V_336 ) ;
F_89 ( V_15 , 0 , V_336 ) ;
F_84 ( V_15 , 0 ) ;
}
static unsigned int F_105 ( struct V_14 * V_15 ,
const struct V_48 * V_49 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_338 , V_330 , V_339 ;
unsigned int V_340 ;
V_330 = V_32 -> V_331 ;
V_339 = F_100 ( V_15 ) ;
F_33 ( L_58 , V_330 ,
( unsigned long long ) V_32 -> V_135 [
V_330 ] ) ;
V_338 = F_106 ( V_15 -> V_270 -> V_285 ) ;
if ( V_338 > V_130 )
V_338 = V_130 ;
if ( V_49 -> V_248 == V_247 && V_338 > V_32 -> V_335 )
V_338 = V_32 -> V_335 ;
V_338 -= V_338 % V_208 ;
if ( V_338 == 0 )
return 0 ;
F_33 ( L_59 , V_338 ) ;
V_338 = F_107 ( V_15 -> V_270 ,
V_32 ->
V_134 [ V_330 ] ,
V_338 ) ;
V_32 -> V_139 [ V_330 ] . V_146 =
F_47 ( V_338 ) ;
V_340 = F_108 ( V_32 -> V_139 [ V_330 ] . V_147 ) ;
V_340 |= V_337 ;
V_32 -> V_139 [ V_330 ] . V_147 = F_47 ( V_340 ) ;
V_340 = F_108 ( V_32 -> V_139 [ V_339 ] . V_147 ) ;
V_340 &= ~ V_337 ;
V_32 -> V_139 [ V_339 ] . V_147 = F_47 ( V_340 ) ;
V_32 -> V_331 = ( V_330 + 1 ) % V_133 ;
V_32 -> V_335 -= V_338 ;
return V_338 ;
}
static void F_109 ( struct V_14 * V_15 , const struct V_48 * V_49 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_338 ;
unsigned int V_316 ;
void T_4 * V_318 =
V_32 -> V_36 + V_62 ;
unsigned int V_330 ;
do {
V_330 = V_32 -> V_331 ;
V_316 = F_36 ( V_318 ) ;
if ( V_316 >=
V_32 -> V_135 [ V_330 ] &&
V_316 <
V_32 -> V_135 [ V_330 ] +
V_130 )
return;
V_338 = F_105 ( V_15 , V_49 ) ;
} while ( V_338 >= V_130 );
}
static void F_110 ( struct V_14 * V_15 ,
unsigned short V_319 , unsigned int V_320 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
struct V_169 * V_170 = V_15 -> V_270 ;
struct V_284 * V_285 ;
struct V_48 * V_49 ;
T_2 V_341 ;
unsigned long V_34 ;
if ( V_170 == NULL )
return;
V_285 = V_170 -> V_285 ;
V_49 = & V_285 -> V_49 ;
F_26 ( & V_15 -> V_35 , V_34 ) ;
V_341 = F_37 ( V_32 -> V_36 + V_66 ) ;
if ( V_320 & V_342 ) {
if ( ( V_341 & V_262 ) &&
! ( V_341 & V_334 ) )
F_85 ( V_262 | V_264 ,
V_32 -> V_36 + V_66 ) ;
else
F_85 ( V_264 ,
V_32 -> V_36 + V_66 ) ;
F_28 ( & V_15 -> V_35 , V_34 ) ;
F_33 ( L_60 , V_341 ) ;
if ( V_341 & V_262 ) {
F_109 ( V_15 , V_49 ) ;
if ( F_103 ( V_15 , V_341 ) )
F_104 ( V_15 ) ;
}
F_33 ( L_61 ) ;
} else {
F_28 ( & V_15 -> V_35 , V_34 ) ;
}
if ( ( V_319 & V_343 ) ) {
V_285 -> V_323 |= V_324 ;
if ( F_102 ( V_15 , V_49 ) )
V_285 -> V_323 |= V_325 ;
F_33 ( L_62 ,
F_36 ( V_32 -> V_36 +
V_65 ) ) ;
F_33 ( L_63 ,
F_36 ( V_32 -> V_36 +
V_62 ) ) ;
}
F_99 ( V_15 , V_170 ) ;
}
static T_5 F_111 ( int V_344 , void * V_345 )
{
struct V_14 * V_15 = V_345 ;
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned short V_319 ;
T_3 V_320 ;
T_3 V_346 ;
V_320 = F_36 ( V_32 -> V_36 + V_38 ) ;
V_319 = F_61 ( V_32 -> V_46 + V_197 ) ;
F_33 ( L_64 , V_319 , V_320 ) ;
if ( ! V_15 -> V_347 ) {
F_33 ( L_65 ) ;
return V_348 ;
}
F_98 ( V_15 , V_319 , V_320 ) ;
F_110 ( V_15 , V_319 , V_320 ) ;
if ( V_320 & V_349 ) {
V_346 = F_36 ( V_32 -> V_36 + V_350 ) ;
F_30 ( V_346 , V_32 -> V_36 + V_350 ) ;
F_33 ( L_66 , V_346 ) ;
}
F_33 ( L_67 ) ;
return V_348 ;
}
static int F_112 ( struct V_14 * V_15 , struct V_169 * V_170 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned long V_34 ;
F_26 ( & V_15 -> V_35 , V_34 ) ;
if ( V_32 -> V_303 == 0 ) {
F_28 ( & V_15 -> V_35 , V_34 ) ;
return 0 ;
}
V_32 -> V_303 = 0 ;
F_28 ( & V_15 -> V_35 , V_34 ) ;
F_39 ( V_15 ) ;
F_25 ( V_15 , 1 ) ;
F_33 ( L_68 ) ;
return 0 ;
}
static int F_113 ( struct V_14 * V_15 , struct V_169 * V_170 ,
struct V_171 * V_172 , unsigned int * V_164 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
int V_351 = F_58 ( V_172 -> V_176 ) ;
int V_23 = F_59 ( V_172 -> V_176 ) ;
F_32 ( 0 , V_32 -> V_46 + V_352 ) ;
F_23 ( V_15 , & V_32 -> V_122 , V_351 , V_23 ) ;
F_32 ( V_32 -> V_122 ,
V_32 -> V_46 + V_353 ) ;
if ( V_17 -> V_10 == V_11 ) {
F_32 ( V_164 [ 0 ] & 0xff ,
V_32 -> V_46 + F_2 ( V_351 ) ) ;
F_32 ( ( V_164 [ 0 ] >> 8 ) & 0xf ,
V_32 -> V_46 + F_3 ( V_351 ) ) ;
} else {
F_32 ( V_164 [ 0 ] , V_32 -> V_46 + F_1 ( V_351 ) ) ;
}
V_32 -> V_354 [ V_351 ] = V_164 [ 0 ] ;
return 1 ;
}
static int F_114 ( struct V_14 * V_15 ,
struct V_169 * V_170 ,
struct V_171 * V_172 , unsigned int * V_164 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
V_164 [ 0 ] = V_32 -> V_354 [ F_58 ( V_172 -> V_176 ) ] ;
return 1 ;
}
static void F_115 ( struct V_14 * V_15 ,
const struct V_48 * V_49 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_25 = V_355 | V_356 |
V_357 | V_358 ;
if ( V_49 -> V_242 == V_243 ) {
V_25 |= V_359 ;
if ( V_49 -> V_293 & V_299 )
V_25 |= V_360 ;
} else {
V_25 |= V_361 ;
}
if ( V_49 -> V_235 == V_243 ) {
V_25 |= V_362 ;
if ( V_49 -> V_236 & V_299 )
V_25 |= V_363 ;
}
F_32 ( V_25 , V_32 -> V_46 + V_352 ) ;
}
static void F_116 ( struct V_14 * V_15 ,
const struct V_48 * V_49 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
int V_128 ;
for ( V_128 = 0 ; V_128 < V_49 -> V_237 ; V_128 ++ ) {
int V_1 , V_23 ;
V_1 = F_58 ( V_49 -> V_253 [ V_128 ] ) ;
V_23 = F_59 ( V_49 -> V_253 [ V_128 ] ) ;
F_23 ( V_15 , & V_32 -> V_122 , V_1 ,
V_23 ) ;
}
V_32 -> V_122 |= V_364 ;
F_32 ( V_32 -> V_122 ,
V_32 -> V_46 + V_353 ) ;
}
static void F_117 ( struct V_14 * V_15 ,
const struct V_48 * V_49 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
T_1 V_25 ;
unsigned int V_254 , V_365 ;
V_254 = F_58 ( V_49 -> V_253 [ 0 ] ) ;
V_365 = F_58 ( V_49 -> V_253 [ V_49 -> V_237 - 1 ] ) ;
if ( V_365 < V_254 )
F_21 ( V_15 , L_69 ) ;
V_25 = ( V_254 & 0x7 ) | ( V_365 & 0x7 ) << 3 ;
F_32 ( V_25 , V_32 -> V_46 + V_366 ) ;
}
static unsigned int F_118 ( unsigned int V_217 , unsigned int V_34 )
{
return F_69 ( V_217 , V_34 ) - 2 ;
}
static void F_119 ( struct V_14 * V_15 ,
const struct V_48 * V_49 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_209 ;
if ( V_49 -> V_235 != V_232 )
return;
V_209 = F_118 ( V_49 -> V_236 , V_49 -> V_34 ) ;
if ( V_209 > V_227 ) {
F_21 ( V_15 , L_70 ) ;
V_209 = V_227 ;
}
F_32 ( V_209 & 0xffff ,
V_32 -> V_46 + V_367 ) ;
F_32 ( ( V_209 >> 16 ) & 0xff ,
V_32 -> V_46 + V_368 ) ;
}
static int F_120 ( struct V_14 * V_15 , const struct V_48 * V_49 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_338 ;
int V_128 ;
F_32 ( 0 , V_32 -> V_46 + V_274 ) ;
F_32 ( 0 , V_32 -> V_46 + V_273 ) ;
V_338 = ( V_369 / 2 ) * V_208 ;
if ( V_49 -> V_248 == V_247 &&
V_338 / V_208 > V_32 -> V_335 )
V_338 = V_32 -> V_335 * V_208 ;
V_338 = F_107 ( V_15 -> V_270 ,
V_32 -> V_370 ,
V_338 ) ;
for ( V_128 = 0 ; V_128 < V_338 / V_208 ; V_128 ++ ) {
F_32 ( V_32 -> V_370 [ V_128 ] ,
V_32 -> V_46 + V_151 ) ;
}
V_32 -> V_335 -= V_338 / V_208 ;
if ( V_49 -> V_248 == V_247 && V_32 -> V_335 == 0 )
return 0 ;
V_338 = F_105 ( V_15 , V_49 ) ;
if ( V_338 == 0 )
return - 1 ;
F_109 ( V_15 , V_49 ) ;
F_84 ( V_15 , 0 ) ;
return 0 ;
}
static inline int F_121 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
if ( V_15 -> V_305 -> V_271 )
return 0 ;
if ( V_17 -> V_10 == V_11 )
return 0 ;
else if ( F_87 ( & V_15 -> V_305 -> V_285 -> V_49 ) )
return 0 ;
return 1 ;
}
static int F_122 ( struct V_14 * V_15 , struct V_169 * V_170 ,
unsigned int V_371 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
struct V_48 * V_49 = & V_170 -> V_285 -> V_49 ;
int V_109 ;
if ( V_371 != 0 )
return - V_204 ;
V_109 = F_120 ( V_15 , V_49 ) ;
if ( V_109 < 0 )
return - V_372 ;
F_115 ( V_15 , V_49 ) ;
if ( V_49 -> V_242 == V_373 )
F_32 ( 0 , V_32 -> V_46 + V_374 ) ;
V_170 -> V_285 -> V_375 = NULL ;
return 0 ;
}
static int F_123 ( struct V_14 * V_15 , struct V_169 * V_170 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
struct V_48 * V_49 = & V_170 -> V_285 -> V_49 ;
if ( F_121 ( V_15 ) ) {
F_48 ( V_15 ) ;
return - V_272 ;
}
F_32 ( 0x0 , V_32 -> V_46 + V_352 ) ;
V_32 -> V_331 = 0 ;
V_32 -> V_335 = V_49 -> V_252 * V_49 -> V_237 ;
F_117 ( V_15 , V_49 ) ;
F_119 ( V_15 , V_49 ) ;
F_89 ( V_15 , 0 , V_32 -> V_140 |
V_148 | V_149 ) ;
F_116 ( V_15 , V_49 ) ;
V_170 -> V_285 -> V_375 = F_122 ;
return 0 ;
}
static int F_124 ( struct V_14 * V_15 , struct V_169 * V_170 ,
struct V_48 * V_49 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
int V_238 = 0 ;
unsigned int V_239 ;
int V_128 ;
V_238 |= F_72 ( & V_49 -> V_242 , V_373 | V_243 ) ;
V_238 |= F_72 ( & V_49 -> V_235 ,
V_232 | V_243 ) ;
V_238 |= F_72 ( & V_49 -> V_231 , V_234 ) ;
V_238 |= F_72 ( & V_49 -> V_246 , V_247 ) ;
V_238 |= F_72 ( & V_49 -> V_248 , V_249 ) ;
if ( V_238 )
return 1 ;
V_238 |= F_73 ( V_49 -> V_242 ) ;
V_238 |= F_73 ( V_49 -> V_235 ) ;
if ( V_49 -> V_231 == V_243 && V_49 -> V_235 == V_232 )
V_238 |= - V_204 ;
if ( V_49 -> V_248 != V_247 &&
V_49 -> V_248 != V_249 && V_49 -> V_248 != V_243 )
V_238 |= - V_204 ;
if ( V_238 )
return 2 ;
if ( V_49 -> V_235 == V_232 ) {
V_238 |= F_75 ( & V_49 -> V_236 ,
V_17 -> V_376 ) ;
if ( F_118 ( V_49 -> V_236 , V_49 -> V_34 ) >
V_227 ) {
V_49 -> V_236 = ( V_227 + 2 ) *
V_220 ;
V_238 |= - V_204 ;
}
}
V_238 |= F_75 ( & V_49 -> V_237 , 1 ) ;
V_238 |= F_74 ( & V_49 -> V_251 , V_49 -> V_237 ) ;
if ( V_238 )
return 3 ;
if ( V_49 -> V_235 == V_232 ) {
V_239 = V_49 -> V_236 ;
V_49 -> V_236 = F_69 ( V_49 -> V_236 ,
V_49 -> V_34 ) * V_220 ;
if ( V_239 != V_49 -> V_236 )
V_238 ++ ;
}
if ( V_238 )
return 4 ;
if ( V_49 -> V_253 ) {
unsigned int V_254 = F_58 ( V_49 -> V_253 [ 0 ] ) ;
for ( V_128 = 1 ; V_128 < V_49 -> V_237 ; V_128 ++ ) {
if ( F_58 ( V_49 -> V_253 [ V_128 ] ) != V_254 + V_128 ) {
F_21 ( V_15 ,
L_38 ) ;
V_238 ++ ;
break;
}
}
}
if ( V_238 )
return 5 ;
return 0 ;
}
static int F_125 ( struct V_14 * V_15 , struct V_169 * V_170 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
F_32 ( 0x0 , V_32 -> V_46 + V_352 ) ;
F_25 ( V_15 , 0 ) ;
return 0 ;
}
static int F_126 ( int V_377 , int V_378 , int V_164 , unsigned long V_379 )
{
void T_4 * V_380 = ( void T_4 * ) V_379 ;
if ( V_377 ) {
F_85 ( V_164 , V_380 + V_378 ) ;
F_33 ( L_71 , V_164 , V_378 ) ;
return 0 ;
} else {
return F_37 ( V_380 + V_378 ) ;
}
}
static int F_127 ( int V_377 , int V_378 , int V_164 , unsigned long V_379 )
{
void T_4 * V_380 = ( void T_4 * ) V_379 ;
if ( V_377 ) {
F_32 ( V_164 , V_380 + 2 * V_378 ) ;
return 0 ;
} else {
return F_61 ( V_380 + 2 * V_378 ) ;
}
}
static int F_128 ( struct V_14 * V_15 , struct V_169 * V_170 ,
struct V_171 * V_172 , unsigned int * V_164 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_25 ;
V_25 = F_37 ( V_32 -> V_201 + V_381 ) ;
V_25 &= 0xf ;
V_164 [ 1 ] = V_25 ;
V_164 [ 0 ] = 0 ;
return V_172 -> V_173 ;
}
static int F_129 ( struct V_14 * V_15 , struct V_169 * V_170 ,
struct V_171 * V_172 , unsigned int * V_164 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
V_164 [ 0 ] &= 0xf ;
V_170 -> V_152 &= ~ V_164 [ 0 ] ;
V_170 -> V_152 |= V_164 [ 0 ] & V_164 [ 1 ] ;
F_85 ( V_170 -> V_152 , V_32 -> V_201 + V_382 ) ;
V_164 [ 1 ] = V_170 -> V_152 ;
return V_172 -> V_173 ;
}
static int F_130 ( struct V_14 * V_15 ,
struct V_169 * V_170 ,
struct V_171 * V_172 , unsigned int * V_164 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_383 ;
V_383 = 1 << F_58 ( V_172 -> V_176 ) ;
switch ( V_164 [ 0 ] ) {
case V_384 :
V_170 -> V_385 &= ~ V_383 ;
break;
case V_386 :
V_170 -> V_385 |= V_383 ;
break;
case V_387 :
V_164 [ 1 ] = ( V_170 -> V_385 & V_383 ) ? V_388 : V_389 ;
return 2 ;
default:
return - V_204 ;
}
F_85 ( V_170 -> V_385 ,
V_32 -> V_201 + V_390 ) ;
return 1 ;
}
static int F_131 ( struct V_14 * V_15 , struct V_169 * V_170 ,
struct V_171 * V_172 , unsigned int * V_164 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
if ( V_164 [ 0 ] ) {
V_170 -> V_152 &= ~ V_164 [ 0 ] ;
V_170 -> V_152 |= ( V_164 [ 0 ] & V_164 [ 1 ] ) ;
F_85 ( V_170 -> V_152 ,
V_32 -> V_201 + V_391 ) ;
}
V_164 [ 1 ] = F_37 ( V_32 -> V_201 + V_391 ) ;
return V_172 -> V_173 ;
}
static int F_132 ( struct V_14 * V_15 , unsigned int V_163 ,
T_2 V_392 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
static const int V_393 = 8 ;
static const int V_394 = 11 ;
unsigned int V_166 = ( ( V_163 & 0x7 ) << 8 ) | V_392 ;
unsigned int V_161 , V_395 ;
static const int V_396 = 1 ;
if ( V_163 >= V_393 ) {
F_21 ( V_15 , L_72 ) ;
return - 1 ;
}
for ( V_161 = 1 << ( V_394 - 1 ) ; V_161 ; V_161 >>= 1 ) {
V_395 = 0 ;
if ( V_166 & V_161 )
V_395 |= V_397 ;
F_50 ( V_396 ) ;
F_32 ( V_395 , V_32 -> V_46 + V_120 ) ;
V_395 |= V_398 ;
F_50 ( V_396 ) ;
F_32 ( V_395 , V_32 -> V_46 + V_120 ) ;
}
F_50 ( V_396 ) ;
F_32 ( V_399 , V_32 -> V_46 + V_120 ) ;
F_50 ( V_396 ) ;
F_32 ( 0 , V_32 -> V_46 + V_120 ) ;
F_50 ( V_396 ) ;
return 0 ;
}
static int F_133 ( struct V_14 * V_15 ,
unsigned int V_400 , unsigned int V_392 )
{
T_2 V_401 [ 3 ] ;
T_2 V_402 ;
enum T_6 {
V_403 = 0x1 ,
V_404 = 0x2 ,
V_405 = 0x4 ,
V_406 = 0x8 ,
};
enum T_7 {
V_407 = 0x20 ,
};
switch ( V_400 ) {
case 0 :
V_402 = V_408 ;
V_401 [ 0 ] = V_403 ;
break;
case 1 :
V_402 = V_408 ;
V_401 [ 0 ] = V_405 ;
break;
case 2 :
V_402 = V_409 ;
V_401 [ 0 ] = V_403 ;
break;
case 3 :
V_402 = V_409 ;
V_401 [ 0 ] = V_405 ;
break;
case 4 :
V_402 = V_408 ;
V_401 [ 0 ] = V_404 ;
break;
case 5 :
V_402 = V_408 ;
V_401 [ 0 ] = V_406 ;
break;
case 6 :
V_402 = V_409 ;
V_401 [ 0 ] = V_404 ;
break;
case 7 :
V_402 = V_409 ;
V_401 [ 0 ] = V_406 ;
break;
default:
F_21 ( V_15 , L_73 ) ;
return - 1 ;
break;
}
V_401 [ 1 ] = V_407 | ( ( V_392 >> 8 ) & 0xf ) ;
V_401 [ 2 ] = V_392 & 0xff ;
F_56 ( V_15 , V_402 , V_401 , 3 ) ;
return 0 ;
}
static void F_134 ( struct V_14 * V_15 , unsigned int V_1 ,
unsigned int V_392 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
V_32 -> V_410 [ V_1 ] = V_392 ;
switch ( V_17 -> V_10 ) {
case V_19 :
case V_18 :
F_132 ( V_15 , V_1 , V_392 ) ;
break;
case V_11 :
F_133 ( V_15 , V_1 , V_392 ) ;
break;
default:
break;
}
}
static int F_135 ( struct V_14 * V_15 ,
struct V_169 * V_170 ,
struct V_171 * V_172 , unsigned int * V_164 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
int V_1 = F_58 ( V_172 -> V_176 ) ;
if ( V_32 -> V_410 [ V_1 ] == V_164 [ 0 ] )
return 1 ;
F_134 ( V_15 , V_1 , V_164 [ 0 ] ) ;
return 1 ;
}
static int F_136 ( struct V_14 * V_15 ,
struct V_169 * V_170 , struct V_171 * V_172 ,
unsigned int * V_164 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_1 = F_58 ( V_172 -> V_176 ) ;
V_164 [ 0 ] = V_32 -> V_410 [ V_1 ] ;
return 1 ;
}
static void F_137 ( struct V_14 * V_15 , unsigned int V_1 ,
unsigned int V_392 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
static const int V_394 = 10 ;
unsigned int V_161 , V_395 ;
unsigned int V_166 = ( ( V_1 & 0x3 ) << 8 ) | ( V_392 & 0xff ) ;
static const int V_411 = 1 ;
V_32 -> V_412 [ V_1 ] = V_392 ;
V_395 = V_413 ;
F_50 ( V_411 ) ;
F_32 ( V_395 , V_32 -> V_46 + V_120 ) ;
for ( V_161 = 1 << ( V_394 - 1 ) ; V_161 ; V_161 >>= 1 ) {
if ( V_166 & V_161 )
V_395 |= V_397 ;
else
V_395 &= ~ V_397 ;
F_50 ( V_411 ) ;
F_32 ( V_395 , V_32 -> V_46 + V_120 ) ;
F_50 ( V_411 ) ;
F_32 ( V_395 | V_398 ,
V_32 -> V_46 + V_120 ) ;
}
F_50 ( V_411 ) ;
F_32 ( 0 , V_32 -> V_46 + V_120 ) ;
}
static int F_138 ( struct V_14 * V_15 ,
struct V_169 * V_170 ,
struct V_171 * V_172 , unsigned int * V_164 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
int V_1 = F_58 ( V_172 -> V_176 ) ;
if ( V_32 -> V_412 [ V_1 ] == V_164 [ 0 ] )
return 1 ;
V_32 -> V_412 [ V_1 ] = V_164 [ 0 ] ;
F_137 ( V_15 , V_1 , V_164 [ 0 ] ) ;
return 1 ;
}
static int F_139 ( struct V_14 * V_15 ,
struct V_169 * V_170 ,
struct V_171 * V_172 , unsigned int * V_164 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_1 = F_58 ( V_172 -> V_176 ) ;
V_164 [ 0 ] = V_32 -> V_412 [ V_1 ] ;
return 1 ;
}
static T_1 F_140 ( struct V_14 * V_15 , T_2 V_163 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
static const int V_394 = 11 ;
static const int V_414 = 0x6 ;
unsigned int V_166 = ( V_414 << 8 ) | V_163 ;
unsigned int V_161 ;
void T_4 * const V_155 =
V_32 -> V_36 + V_54 ;
T_1 V_392 ;
static const int V_415 = 16 ;
static const int V_416 = 1 ;
F_50 ( V_416 ) ;
V_32 -> V_53 &= ~ V_417 & ~ V_168 ;
V_32 -> V_53 |= V_159 ;
F_30 ( V_32 -> V_53 , V_155 ) ;
F_50 ( V_416 ) ;
V_32 -> V_53 |= V_168 ;
F_30 ( V_32 -> V_53 , V_155 ) ;
for ( V_161 = 1 << ( V_394 - 1 ) ; V_161 ; V_161 >>= 1 ) {
F_50 ( V_416 ) ;
if ( V_166 & V_161 )
V_32 -> V_53 |= V_154 ;
else
V_32 -> V_53 &= ~ V_154 ;
F_30 ( V_32 -> V_53 , V_155 ) ;
F_50 ( V_416 ) ;
V_32 -> V_53 |= V_417 ;
F_30 ( V_32 -> V_53 , V_155 ) ;
F_50 ( V_416 ) ;
V_32 -> V_53 &= ~ V_417 ;
F_30 ( V_32 -> V_53 , V_155 ) ;
}
V_392 = 0 ;
for ( V_161 = 1 << ( V_415 - 1 ) ; V_161 ; V_161 >>= 1 ) {
F_50 ( V_416 ) ;
V_32 -> V_53 |= V_417 ;
F_30 ( V_32 -> V_53 , V_155 ) ;
F_50 ( V_416 ) ;
V_32 -> V_53 &= ~ V_417 ;
F_30 ( V_32 -> V_53 , V_155 ) ;
F_50 ( V_416 ) ;
if ( F_36 ( V_155 ) & V_418 )
V_392 |= V_161 ;
}
F_50 ( V_416 ) ;
V_32 -> V_53 &= ~ V_168 ;
F_30 ( V_32 -> V_53 , V_155 ) ;
return V_392 ;
}
static int F_141 ( struct V_14 * V_15 ,
struct V_169 * V_170 ,
struct V_171 * V_172 , unsigned int * V_164 )
{
V_164 [ 0 ] = F_140 ( V_15 , F_58 ( V_172 -> V_176 ) ) ;
return 1 ;
}
static int F_142 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
struct V_169 * V_170 ;
void T_4 * V_419 ;
int V_128 ;
int V_420 ;
V_420 = F_143 ( V_15 , 10 ) ;
if ( V_420 )
return V_420 ;
V_170 = & V_15 -> V_421 [ 0 ] ;
V_15 -> V_305 = V_170 ;
V_170 -> type = V_422 ;
V_170 -> V_423 = V_424 | V_425 | V_426 | V_427 ;
if ( V_17 -> V_10 == V_19 )
V_170 -> V_423 |= V_428 | V_429 ;
else if ( V_17 -> V_10 == V_18 )
V_170 -> V_423 |= V_429 ;
V_170 -> V_430 = V_17 -> V_431 ;
V_170 -> V_432 = 0x2000 ;
V_170 -> V_433 = ( 1 << V_17 -> V_434 ) - 1 ;
V_170 -> V_435 = V_17 -> V_24 ;
V_170 -> V_436 = F_57 ;
V_170 -> V_437 = F_68 ;
V_170 -> V_438 = F_90 ;
V_170 -> V_439 = F_71 ;
V_170 -> V_440 = F_112 ;
if ( V_17 -> V_10 == V_11 ) {
T_2 V_164 ;
V_32 -> V_191 = F_15 ( 4 ) ;
for ( V_128 = 0 ; V_128 < V_170 -> V_430 ; V_128 ++ )
V_32 -> V_191 |= F_16 ( V_128 ) ;
V_164 = V_32 -> V_191 ;
F_56 ( V_15 , V_193 , & V_164 , sizeof( V_164 ) ) ;
}
V_170 = & V_15 -> V_421 [ 1 ] ;
if ( V_17 -> V_30 ) {
V_170 -> type = V_441 ;
V_170 -> V_423 = V_424 | V_442 |
V_425 | V_443 ;
V_170 -> V_430 = V_17 -> V_30 ;
V_170 -> V_433 = ( 1 << V_17 -> V_444 ) - 1 ;
V_170 -> V_435 = V_17 -> V_445 ;
V_170 -> V_436 = F_114 ;
V_170 -> V_446 = F_113 ;
if ( F_24 ( V_17 ) ) {
V_15 -> V_270 = V_170 ;
V_170 -> V_439 = F_124 ;
V_170 -> V_438 = F_123 ;
V_170 -> V_432 = V_17 -> V_30 ;
V_170 -> V_440 = F_125 ;
}
} else {
V_170 -> type = V_447 ;
}
V_170 = & V_15 -> V_421 [ 2 ] ;
if ( V_17 -> V_10 == V_18 ) {
V_170 -> type = V_448 ;
V_170 -> V_423 = V_424 ;
V_170 -> V_430 = 4 ;
V_170 -> V_433 = 1 ;
V_170 -> V_435 = & V_449 ;
V_170 -> V_450 = F_128 ;
} else
V_170 -> type = V_447 ;
if ( V_17 -> V_10 == V_18 ) {
V_170 = & V_15 -> V_421 [ 3 ] ;
V_170 -> type = V_451 ;
V_170 -> V_423 = V_442 | V_424 ;
V_170 -> V_430 = 4 ;
V_170 -> V_433 = 1 ;
V_170 -> V_435 = & V_449 ;
V_170 -> V_450 = F_129 ;
} else
V_170 -> type = V_447 ;
V_170 = & V_15 -> V_421 [ 4 ] ;
if ( V_17 -> V_452 ) {
if ( V_17 -> V_10 == V_11 ) {
V_419 = V_32 -> V_46 + V_453 ;
F_144 ( V_15 , V_170 , F_127 ,
( unsigned long ) V_419 ) ;
} else {
V_419 =
V_32 -> V_201 + V_454 ;
F_144 ( V_15 , V_170 , F_126 ,
( unsigned long ) V_419 ) ;
}
} else
V_170 -> type = V_447 ;
V_170 = & V_15 -> V_421 [ 5 ] ;
if ( V_17 -> V_10 == V_19 ) {
V_170 -> type = V_455 ;
V_170 -> V_423 = V_442 | V_424 ;
V_170 -> V_430 = 8 ;
V_170 -> V_433 = 1 ;
V_170 -> V_435 = & V_449 ;
V_170 -> V_437 = F_130 ;
V_170 -> V_450 = F_131 ;
} else
V_170 -> type = V_447 ;
V_170 = & V_15 -> V_421 [ 6 ] ;
V_170 -> type = V_456 ;
V_170 -> V_423 = V_424 | V_442 | V_457 ;
V_170 -> V_430 = 8 ;
if ( V_17 -> V_10 == V_11 )
V_170 -> V_433 = 0xfff ;
else
V_170 -> V_433 = 0xff ;
V_170 -> V_436 = F_136 ;
V_170 -> V_446 = F_135 ;
for ( V_128 = 0 ; V_128 < V_170 -> V_430 ; V_128 ++ )
F_134 ( V_15 , V_128 , V_170 -> V_433 / 2 ) ;
V_170 = & V_15 -> V_421 [ 7 ] ;
if ( V_17 -> V_10 == V_18 ) {
V_170 -> type = V_456 ;
V_170 -> V_423 = V_424 | V_442 | V_457 ;
V_170 -> V_430 = 2 ;
V_170 -> V_436 = F_139 ;
V_170 -> V_446 = F_138 ;
V_170 -> V_433 = 0xff ;
for ( V_128 = 0 ; V_128 < V_170 -> V_430 ; V_128 ++ )
F_137 ( V_15 , V_128 , V_170 -> V_433 / 2 ) ;
} else
V_170 -> type = V_447 ;
V_170 = & V_15 -> V_421 [ 8 ] ;
if ( F_36 ( V_32 -> V_36 + V_54 ) & V_458 ) {
V_170 -> type = V_459 ;
V_170 -> V_423 = V_424 | V_457 ;
V_170 -> V_430 = 128 ;
V_170 -> V_433 = 0xffff ;
V_170 -> V_436 = F_141 ;
} else
V_170 -> type = V_447 ;
V_170 = & V_15 -> V_421 [ 9 ] ;
V_170 -> type = V_447 ;
return 0 ;
}
static int F_145 ( struct V_14 * V_15 ,
unsigned long V_460 )
{
struct V_126 * V_127 = F_45 ( V_15 ) ;
const struct V_8 * V_17 = NULL ;
struct V_31 * V_32 ;
T_3 V_461 , V_462 ;
int V_109 ;
if ( V_460 < F_146 ( V_463 ) )
V_17 = & V_463 [ V_460 ] ;
if ( ! V_17 )
return - V_464 ;
V_15 -> V_465 = V_17 ;
V_32 = F_147 ( sizeof( * V_32 ) , V_466 ) ;
if ( ! V_32 )
return - V_132 ;
V_15 -> V_33 = V_32 ;
V_109 = F_148 ( V_15 ) ;
if ( V_109 )
return V_109 ;
F_149 ( V_127 ) ;
V_15 -> V_467 = V_17 -> V_468 ;
V_32 -> V_469 = F_150 ( V_127 , 2 ) ;
V_32 -> V_470 = F_150 ( V_127 , 3 ) ;
V_32 -> V_36 = F_151 ( V_127 , 0 ) ;
V_32 -> V_46 = F_151 ( V_127 , 2 ) ;
V_32 -> V_201 = F_151 ( V_127 , 3 ) ;
if ( ! V_32 -> V_36 || ! V_32 -> V_46
|| ! V_32 -> V_201 ) {
F_152 ( V_15 -> V_199 , L_74 ) ;
return - V_132 ;
}
F_33 ( L_75 , V_32 -> V_36 ) ;
F_33 ( L_76 , V_32 -> V_46 ) ;
F_33 ( L_77 ,
V_32 -> V_201 ) ;
V_461 = F_36 ( V_32 -> V_36 + V_471 ) &
V_472 ;
V_462 = F_36 ( V_32 -> V_36 + V_473 ) &
V_461 & V_474 ;
V_32 -> V_145 = ( ( T_3 ) V_32 -> V_469 &
~ V_461 ) | V_462 ;
V_461 = F_36 ( V_32 -> V_36 + V_475 ) &
V_472 ;
V_462 = F_36 ( V_32 -> V_36 + V_476 ) &
V_461 & V_474 ;
V_32 -> V_143 = ( ( T_3 ) V_32 -> V_470 &
~ V_461 ) | V_462 ;
F_33 ( L_78 , V_32 -> V_145 ) ;
F_33 ( L_79 , V_32 -> V_143 ) ;
V_109 = F_44 ( V_15 ) ;
if ( V_109 < 0 )
return V_109 ;
V_32 -> F_22 =
F_22 ( V_15 , F_61 ( V_32 -> V_46 + V_197 ) ) ;
F_64 ( V_15 -> V_199 , L_80 ,
V_32 -> F_22 ) ;
F_35 ( V_15 ) ;
F_43 ( V_15 ) ;
if ( F_153 ( V_127 -> V_344 , F_111 , V_477 ,
L_81 , V_15 ) ) {
F_64 ( V_15 -> V_199 , L_82 ,
V_127 -> V_344 ) ;
return - V_204 ;
}
V_15 -> V_344 = V_127 -> V_344 ;
F_64 ( V_15 -> V_199 , L_83 , V_15 -> V_344 ) ;
V_109 = F_142 ( V_15 ) ;
if ( V_109 < 0 )
return V_109 ;
return 0 ;
}
static void F_154 ( struct V_14 * V_15 )
{
const struct V_8 * V_17 = F_19 ( V_15 ) ;
struct V_126 * V_127 = F_45 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
unsigned int V_128 ;
if ( V_15 -> V_344 )
F_155 ( V_15 -> V_344 , V_15 ) ;
if ( V_32 ) {
if ( V_127 ) {
if ( V_32 -> V_36 ) {
F_29 ( V_15 ) ;
F_156 ( V_32 -> V_36 ) ;
}
if ( V_32 -> V_46 )
F_156 ( V_32 -> V_46 ) ;
if ( V_32 -> V_201 )
F_156 ( V_32 -> V_201 ) ;
for ( V_128 = 0 ; V_128 < F_17 ( V_17 ) ; V_128 ++ ) {
if ( V_32 -> V_129 [ V_128 ] )
F_157 ( V_127 ,
V_130 ,
V_32 -> V_129 [ V_128 ] ,
V_32 -> V_131 [ V_128 ] ) ;
}
for ( V_128 = 0 ; V_128 < V_133 ; V_128 ++ ) {
if ( V_32 -> V_134 [ V_128 ] )
F_157 ( V_127 ,
V_130 ,
V_32 -> V_134 [ V_128 ] ,
V_32 -> V_135 [ V_128 ] ) ;
}
if ( V_32 -> V_136 )
F_157 ( V_127 ,
sizeof( struct V_137 ) *
F_17 ( V_17 ) ,
V_32 -> V_136 ,
V_32 -> V_138 ) ;
if ( V_32 -> V_139 )
F_157 ( V_127 ,
sizeof( struct V_137 ) *
V_133 ,
V_32 -> V_139 ,
V_32 -> V_140 ) ;
}
}
F_158 ( V_15 ) ;
}
static int F_159 ( struct V_126 * V_15 ,
const struct V_478 * V_213 )
{
return F_160 ( V_15 , & V_479 ,
V_213 -> V_480 ) ;
}
