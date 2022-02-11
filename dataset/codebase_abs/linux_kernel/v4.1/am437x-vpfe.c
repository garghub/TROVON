static struct V_1 * F_1 ( unsigned int V_2 )
{
struct V_1 * V_3 ;
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; V_4 ++ ) {
V_3 = & V_5 [ V_4 ] ;
if ( V_3 -> V_2 == V_2 )
return V_3 ;
}
return NULL ;
}
static struct V_1 * F_3 ( unsigned int V_6 )
{
struct V_1 * V_3 ;
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; V_4 ++ ) {
V_3 = & V_5 [ V_4 ] ;
if ( V_3 -> V_7 == V_6 )
return V_3 ;
}
return NULL ;
}
static void
F_4 ( struct V_8 * V_9 ,
const struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_14 )
{
struct V_15 * V_16 = V_9 -> V_17 ;
unsigned int V_18 = V_16 -> V_19 . V_18 ;
struct V_1 * V_3 ;
V_3 = F_1 ( V_11 -> V_2 ) ;
if ( F_5 ( V_3 == NULL ) ) {
F_6 ( L_1 ) ;
* V_14 = 1 ;
return;
}
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
F_7 ( V_13 , V_11 ) ;
V_13 -> V_6 = V_3 -> V_7 ;
* V_14 = ( V_18 == 10 ) ? V_3 -> V_20 . V_14 : V_3 -> V_21 . V_14 ;
V_13 -> V_22 = F_8 ( V_13 -> V_23 * * V_14 , 32 ) ;
V_13 -> V_24 = V_13 -> V_22 * V_13 -> V_25 ;
}
static void F_9 ( struct V_8 * V_9 ,
struct V_12 * V_26 ,
struct V_10 * V_27 )
{
struct V_1 * V_3 ;
V_3 = F_3 ( V_26 -> V_6 ) ;
if ( ! V_3 ) {
F_10 ( 3 , V_9 , L_2 ,
V_26 -> V_6 ) ;
V_3 = & V_5 [ 0 ] ;
}
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
F_11 ( V_27 , V_26 , V_3 -> V_2 ) ;
}
static char * F_12 ( T_1 V_3 )
{
static char V_2 [ 5 ] ;
V_2 [ 0 ] = ( unsigned char ) ( V_3 & 0xff ) ;
V_2 [ 1 ] = ( unsigned char ) ( ( V_3 >> 8 ) & 0xff ) ;
V_2 [ 2 ] = ( unsigned char ) ( ( V_3 >> 16 ) & 0xff ) ;
V_2 [ 3 ] = ( unsigned char ) ( ( V_3 >> 24 ) & 0xff ) ;
V_2 [ 4 ] = '\0' ;
return V_2 ;
}
static int
F_13 ( const struct V_28 * V_29 , const struct V_28 * V_30 )
{
return V_29 -> type == V_30 -> type &&
V_29 -> V_3 . V_13 . V_23 == V_30 -> V_3 . V_13 . V_23 &&
V_29 -> V_3 . V_13 . V_25 == V_30 -> V_3 . V_13 . V_25 &&
V_29 -> V_3 . V_13 . V_6 == V_30 -> V_3 . V_13 . V_6 &&
V_29 -> V_3 . V_13 . V_31 == V_30 -> V_3 . V_13 . V_31 &&
V_29 -> V_3 . V_13 . V_32 == V_30 -> V_3 . V_13 . V_32 &&
V_29 -> V_3 . V_13 . V_33 == V_30 -> V_3 . V_13 . V_33 &&
V_29 -> V_3 . V_13 . V_34 == V_30 -> V_3 . V_13 . V_34 ;
}
static inline T_1 F_14 ( struct V_35 * V_36 , T_1 V_37 )
{
return F_15 ( V_36 -> V_38 . V_39 + V_37 ) ;
}
static inline void F_16 ( struct V_35 * V_36 , T_1 V_40 , T_1 V_37 )
{
F_17 ( V_40 , V_36 -> V_38 . V_39 + V_37 ) ;
}
static inline struct V_8 * F_18 ( struct V_35 * V_36 )
{
return F_19 ( V_36 , struct V_8 , V_36 ) ;
}
static inline struct V_41 * F_20 ( struct V_42 * V_43 )
{
return F_19 ( V_43 , struct V_41 , V_43 ) ;
}
static inline void F_21 ( struct V_35 * V_36 , int V_44 )
{
F_16 ( V_36 , ! ! V_44 , V_45 ) ;
}
static void F_22 ( struct V_35 * V_36 , int V_44 )
{
unsigned int V_46 ;
if ( ! V_44 ) {
V_46 = F_14 ( V_36 , V_47 ) ;
V_46 &= ~ ( V_48 << V_49 ) ;
} else {
V_46 = V_48 << V_49 ;
}
F_16 ( V_36 , V_46 , V_47 ) ;
}
static void F_23 ( struct V_35 * V_36 ,
struct V_50 * V_51 ,
enum V_52 V_53 ,
int V_14 )
{
int V_54 , V_55 ;
int V_56 , V_57 ;
int V_40 , V_58 ;
V_54 = V_51 -> V_59 * V_14 ;
V_55 = ( V_51 -> V_23 * V_14 ) - 1 ;
F_16 ( V_36 , ( V_54 << V_60 ) |
V_55 , V_61 ) ;
V_56 = V_51 -> V_62 ;
if ( V_53 == V_63 ) {
V_57 = ( V_51 -> V_25 >> 1 ) - 1 ;
V_56 >>= 1 ;
V_56 += 1 ;
V_40 = ( V_56 << V_64 ) ;
} else {
V_56 += 1 ;
V_57 = V_51 -> V_25 - 1 ;
V_58 = V_56 + ( V_51 -> V_25 / 2 ) ;
V_40 = ( V_56 << V_64 ) |
( V_58 & V_65 ) ;
}
F_16 ( V_36 , V_40 , V_66 ) ;
F_16 ( V_36 , ( V_56 << V_67 ) |
V_56 , V_68 ) ;
F_16 ( V_36 , V_57 , V_69 ) ;
}
static void F_24 ( struct V_35 * V_36 )
{
struct V_8 * V_9 = F_18 ( V_36 ) ;
F_10 ( 3 , V_9 , L_3 , F_14 ( V_36 , V_70 ) ) ;
F_10 ( 3 , V_9 , L_4 , F_14 ( V_36 , V_71 ) ) ;
F_10 ( 3 , V_9 , L_5 , F_14 ( V_36 , V_72 ) ) ;
F_10 ( 3 , V_9 , L_6 , F_14 ( V_36 , V_73 ) ) ;
F_10 ( 3 , V_9 , L_7 , F_14 ( V_36 , V_74 ) ) ;
F_10 ( 3 , V_9 , L_8 , F_14 ( V_36 , V_75 ) ) ;
F_10 ( 3 , V_9 , L_9 ,
F_14 ( V_36 , V_76 ) ) ;
F_10 ( 3 , V_9 , L_10 ,
F_14 ( V_36 , V_77 ) ) ;
F_10 ( 3 , V_9 , L_11 ,
F_14 ( V_36 , V_61 ) ) ;
F_10 ( 3 , V_9 , L_12 ,
F_14 ( V_36 , V_68 ) ) ;
F_10 ( 3 , V_9 , L_13 ,
F_14 ( V_36 , V_69 ) ) ;
}
static int
F_25 ( struct V_35 * V_36 ,
struct V_78 * V_79 )
{
struct V_8 * V_9 = F_18 ( V_36 ) ;
T_2 V_80 , V_81 ;
if ( ! V_79 -> V_82 . V_83 )
return 0 ;
V_80 = F_26 ( V_79 -> V_82 . V_84 ) ;
V_81 = F_27 ( V_79 -> V_85 ) ;
if ( V_79 -> V_82 . V_84 > V_86 ||
V_79 -> V_82 . V_84 < V_87 ||
V_80 > V_81 ) {
F_10 ( 1 , V_9 , L_14 ) ;
return - V_88 ;
}
return 0 ;
}
static void
F_28 ( struct V_35 * V_36 ,
struct V_78 * V_89 )
{
struct V_78 * V_90 =
& V_36 -> V_38 . V_91 . V_90 ;
V_90 = V_89 ;
}
static void F_29 ( struct V_35 * V_36 )
{
int V_92 ;
F_21 ( V_36 , 0 ) ;
for ( V_92 = 4 ; V_92 <= 0x94 ; V_92 += 4 )
F_16 ( V_36 , 0 , V_92 ) ;
F_16 ( V_36 , V_93 , V_94 ) ;
F_16 ( V_36 , V_95 , V_70 ) ;
}
static int F_30 ( struct V_35 * V_36 , struct V_96 * V_97 )
{
int V_98 , V_92 , V_99 ;
for ( V_92 = 0 ; V_92 < 10 ; V_92 ++ ) {
F_31 ( 5000 , 6000 ) ;
V_99 = F_14 ( V_36 , V_45 ) ;
if ( ! V_99 )
break;
F_21 ( V_36 , 0 ) ;
}
F_29 ( V_36 ) ;
for ( V_92 = 0 ; V_92 < 10 ; V_92 ++ ) {
V_98 = F_14 ( V_36 , V_100 ) ;
if ( ! ( V_98 & V_101 ) )
break;
F_16 ( V_36 , V_98 , V_100 ) ;
F_31 ( 5000 , 6000 ) ;
}
F_22 ( V_36 , 0 ) ;
F_32 ( V_97 ) ;
return 0 ;
}
static int F_33 ( struct V_35 * V_36 , void T_3 * V_102 )
{
struct V_8 * V_9 = F_19 ( V_36 , struct V_8 , V_36 ) ;
struct V_78 V_89 ;
int V_103 ;
if ( V_36 -> V_38 . V_104 != V_105 )
return - V_88 ;
V_103 = F_34 ( & V_89 , V_102 , sizeof( V_89 ) ) ;
if ( V_103 ) {
F_10 ( 1 , V_9 ,
L_15 ,
V_103 ) ;
return - V_106 ;
}
if ( ! F_25 ( V_36 , & V_89 ) ) {
F_28 ( V_36 , & V_89 ) ;
return 0 ;
}
return - V_88 ;
}
static void F_35 ( struct V_35 * V_36 )
{
struct V_8 * V_9 = F_19 ( V_36 , struct V_8 , V_36 ) ;
struct V_107 * V_102 = & V_36 -> V_38 . V_108 ;
T_1 V_109 ;
F_10 ( 3 , V_9 , L_16 ) ;
F_29 ( V_36 ) ;
V_109 = ( ( ( V_102 -> V_26 & V_110 ) <<
V_111 ) |
( ( V_102 -> V_53 & V_112 ) <<
V_113 ) | V_114 |
V_115 | V_116 ) ;
if ( V_102 -> V_117 ) {
F_16 ( V_36 , V_118 , V_119 ) ;
V_109 |= V_120 ;
if ( V_36 -> V_38 . V_104 == V_121 )
V_109 |= V_122 ;
else
V_109 |= V_123 ;
} else {
V_109 |= ( ( ( V_102 -> V_124 & V_125 ) <<
V_126 ) |
( ( V_102 -> V_127 & V_128 ) <<
V_129 ) |
( ( V_102 -> V_130 & V_131 ) <<
V_132 ) ) ;
}
F_16 ( V_36 , V_109 , V_76 ) ;
F_23 ( V_36 , & V_102 -> V_133 ,
V_102 -> V_53 , V_102 -> V_134 ) ;
if ( V_36 -> V_38 . V_104 == V_121 )
F_16 ( V_36 ,
( V_102 -> V_135 << V_136 ) |
V_137 |
V_138 , V_139 ) ;
else
F_16 ( V_36 ,
( V_102 -> V_135 << V_136 ) |
V_137 , V_139 ) ;
F_16 ( V_36 , V_102 -> V_22 , V_77 ) ;
if ( V_102 -> V_140 == V_141 )
F_16 ( V_36 , V_142 ,
V_75 ) ;
}
static void
F_36 ( struct V_35 * V_36 ,
struct V_143 * V_144 )
{
T_1 V_40 ;
if ( ! V_144 -> V_83 ) {
V_40 = ( V_144 -> V_145 ) & V_146 ;
F_16 ( V_36 , V_40 , V_72 ) ;
F_16 ( V_36 , V_147 , V_71 ) ;
return;
}
V_40 = ( ( V_144 -> V_148 & V_149 ) |
( ( V_144 -> V_150 & V_151 ) <<
V_152 ) |
( ( V_144 -> V_153 & V_154 ) <<
V_155 ) |
( ( V_144 -> V_156 & V_157 ) <<
V_158 ) | V_159 ) ;
F_16 ( V_36 , V_40 , V_71 ) ;
F_16 ( V_36 , V_160 , V_72 ) ;
}
static void
F_37 ( struct V_35 * V_36 ,
struct V_161 * V_162 )
{
T_1 V_40 ;
V_40 = ( ( V_162 -> V_163 & V_164 ) |
( ( V_162 -> V_165 & V_164 ) <<
V_166 ) |
( ( V_162 -> V_167 & V_164 ) <<
V_168 ) |
( ( V_162 -> V_169 & V_164 ) <<
V_170 ) ) ;
F_16 ( V_36 , V_40 , V_73 ) ;
}
static void F_38 ( struct V_35 * V_36 )
{
struct V_8 * V_9 = F_19 ( V_36 , struct V_8 , V_36 ) ;
struct V_78 * V_90 =
& V_36 -> V_38 . V_91 . V_90 ;
struct V_171 * V_102 = & V_36 -> V_38 . V_91 ;
unsigned int V_109 ;
unsigned int V_40 ;
F_10 ( 3 , V_9 , L_17 ) ;
F_29 ( V_36 ) ;
F_16 ( V_36 , V_137 , V_139 ) ;
V_109 = ( ( ( V_102 -> V_130 & V_131 ) << V_132 ) |
( ( V_102 -> V_127 & V_128 ) << V_129 ) |
( ( V_102 -> V_124 & V_125 ) <<
V_126 ) | ( ( V_102 -> V_53 &
V_172 ) << V_173 ) |
( ( V_90 -> V_85 & V_174 ) <<
V_175 ) | ( ( V_102 -> V_26 &
V_176 ) << V_177 ) |
V_115 | V_114 ) ;
if ( V_90 -> V_82 . V_83 ) {
V_40 = ( ( V_90 -> V_82 . V_84 &
V_178 ) | V_179 ) ;
F_16 ( V_36 , V_40 , V_70 ) ;
F_10 ( 3 , V_9 , L_18 , V_40 ) ;
}
F_23 ( V_36 , & V_102 -> V_133 , V_102 -> V_53 ,
V_102 -> V_134 ) ;
F_36 ( V_36 , & V_90 -> V_180 ) ;
F_37 ( V_36 , & V_90 -> V_181 ) ;
if ( ( V_90 -> V_85 == V_182 ) ||
V_90 -> V_82 . V_83 )
V_109 |= V_116 ;
F_16 ( V_36 , V_102 -> V_22 , V_77 ) ;
F_10 ( 3 , V_9 , L_19 ,
V_102 -> V_22 , V_102 -> V_22 ) ;
if ( V_102 -> V_53 == V_63 ) {
if ( V_102 -> V_183 ) {
F_16 ( V_36 , V_184 ,
V_75 ) ;
} else {
F_16 ( V_36 , V_185 ,
V_75 ) ;
}
} else if ( V_102 -> V_53 == V_186 ) {
F_16 ( V_36 , V_187 ,
V_75 ) ;
}
F_16 ( V_36 , V_109 , V_76 ) ;
F_24 ( V_36 ) ;
}
static inline int
F_39 ( struct V_35 * V_36 ,
enum V_188 V_140 )
{
if ( V_36 -> V_38 . V_104 == V_105 )
V_36 -> V_38 . V_91 . V_140 = V_140 ;
else
V_36 -> V_38 . V_108 . V_140 = V_140 ;
return 0 ;
}
static inline enum V_188 F_40 ( struct V_35 * V_36 )
{
if ( V_36 -> V_38 . V_104 == V_105 )
return V_36 -> V_38 . V_91 . V_140 ;
return V_36 -> V_38 . V_108 . V_140 ;
}
static int F_41 ( struct V_35 * V_36 , T_1 V_189 )
{
struct V_8 * V_9 = F_19 ( V_36 , struct V_8 , V_36 ) ;
F_10 ( 1 , V_9 , L_20 ,
V_36 -> V_38 . V_104 , F_12 ( V_189 ) ) ;
if ( V_36 -> V_38 . V_104 == V_105 ) {
V_36 -> V_38 . V_91 . V_26 = V_190 ;
V_36 -> V_38 . V_91 . V_90 . V_82 . V_83 = 0 ;
switch ( V_189 ) {
case V_191 :
V_36 -> V_38 . V_91 . V_90 . V_82 . V_83 = 1 ;
break;
case V_192 :
case V_193 :
case V_194 :
case V_195 :
case V_196 :
break;
case V_197 :
default:
return - V_88 ;
}
} else {
switch ( V_189 ) {
case V_192 :
V_36 -> V_38 . V_108 . V_135 = V_198 ;
break;
case V_193 :
V_36 -> V_38 . V_108 . V_135 = V_199 ;
break;
default:
return - V_88 ;
}
}
return 0 ;
}
static T_1 F_42 ( struct V_35 * V_36 )
{
T_1 V_189 ;
if ( V_36 -> V_38 . V_104 == V_105 ) {
V_189 = V_192 ;
} else {
if ( V_36 -> V_38 . V_108 . V_135 == V_198 )
V_189 = V_192 ;
else
V_189 = V_193 ;
}
return V_189 ;
}
static int
F_43 ( struct V_35 * V_36 ,
struct V_50 * V_133 , unsigned int V_14 )
{
if ( V_36 -> V_38 . V_104 == V_105 ) {
V_36 -> V_38 . V_91 . V_133 = * V_133 ;
V_36 -> V_38 . V_91 . V_134 = V_14 ;
V_36 -> V_38 . V_91 . V_22 = F_8 ( V_133 -> V_23 * V_14 , 32 ) ;
} else {
V_36 -> V_38 . V_108 . V_133 = * V_133 ;
V_36 -> V_38 . V_108 . V_134 = V_14 ;
V_36 -> V_38 . V_108 . V_22 = F_8 ( V_133 -> V_23 * V_14 , 32 ) ;
}
return 0 ;
}
static inline void
F_44 ( struct V_35 * V_36 ,
struct V_50 * V_133 )
{
if ( V_36 -> V_38 . V_104 == V_105 )
* V_133 = V_36 -> V_38 . V_91 . V_133 ;
else
* V_133 = V_36 -> V_38 . V_108 . V_133 ;
}
static inline unsigned int F_45 ( struct V_35 * V_36 )
{
if ( V_36 -> V_38 . V_104 == V_105 )
return V_36 -> V_38 . V_91 . V_22 ;
return V_36 -> V_38 . V_108 . V_22 ;
}
static inline int
F_46 ( struct V_35 * V_36 ,
enum V_52 V_53 )
{
if ( V_36 -> V_38 . V_104 == V_105 )
V_36 -> V_38 . V_91 . V_53 = V_53 ;
else
V_36 -> V_38 . V_108 . V_53 = V_53 ;
return 0 ;
}
static inline enum V_52
F_47 ( struct V_35 * V_36 )
{
if ( V_36 -> V_38 . V_104 == V_105 )
return V_36 -> V_38 . V_91 . V_53 ;
return V_36 -> V_38 . V_108 . V_53 ;
}
static inline int F_48 ( struct V_35 * V_36 )
{
return ( F_14 ( V_36 , V_76 ) >> 15 ) & 1 ;
}
static inline void F_49 ( struct V_35 * V_36 , unsigned long V_200 )
{
F_16 ( V_36 , V_200 & 0xffffffe0 , V_201 ) ;
}
static int F_50 ( struct V_35 * V_36 ,
struct V_202 * V_102 )
{
struct V_8 * V_9 = F_19 ( V_36 , struct V_8 , V_36 ) ;
V_36 -> V_38 . V_104 = V_102 -> V_104 ;
switch ( V_102 -> V_104 ) {
case V_203 :
case V_204 :
case V_205 :
case V_121 :
V_36 -> V_38 . V_108 . V_130 = V_102 -> V_206 ;
V_36 -> V_38 . V_108 . V_127 = V_102 -> V_207 ;
break;
case V_105 :
V_36 -> V_38 . V_91 . V_130 = V_102 -> V_206 ;
V_36 -> V_38 . V_91 . V_127 = V_102 -> V_207 ;
if ( V_102 -> V_18 == 10 )
V_36 -> V_38 . V_91 . V_90 . V_85 =
V_208 ;
else
V_36 -> V_38 . V_91 . V_90 . V_85 =
V_182 ;
F_10 ( 1 , V_9 , L_21 ,
V_102 -> V_18 ) ;
F_10 ( 1 , V_9 , L_22 ,
V_36 -> V_38 . V_91 . V_90 . V_85 ) ;
break;
default:
return - V_88 ;
}
return 0 ;
}
static void F_51 ( struct V_35 * V_36 , int V_209 )
{
unsigned int V_210 ;
V_210 = F_14 ( V_36 , V_211 ) ;
switch ( V_209 ) {
case V_212 :
V_210 &= ~ V_212 ;
V_210 |= V_212 ;
break;
case V_213 :
V_210 &= ~ V_213 ;
V_210 |= V_213 ;
break;
case V_214 :
V_210 &= ~ V_214 ;
V_210 |= V_214 ;
break;
default:
V_210 &= ~ ( V_212 |
V_213 |
V_214 ) ;
V_210 |= ( V_212 |
V_213 |
V_214 ) ;
break;
}
F_16 ( V_36 , V_210 , V_211 ) ;
V_210 = F_14 ( V_36 , V_211 ) ;
F_16 ( V_36 , 1 , V_215 ) ;
}
static void F_52 ( struct V_35 * V_36 )
{
V_36 -> V_38 . V_104 = V_105 ;
V_36 -> V_38 . V_108 . V_26 = V_216 ;
V_36 -> V_38 . V_108 . V_53 = V_63 ;
V_36 -> V_38 . V_108 . V_124 = V_217 ;
V_36 -> V_38 . V_108 . V_130 = V_217 ;
V_36 -> V_38 . V_108 . V_127 = V_217 ;
V_36 -> V_38 . V_108 . V_135 = V_199 ;
V_36 -> V_38 . V_108 . V_140 = V_141 ;
V_36 -> V_38 . V_108 . V_133 . V_59 = 0 ;
V_36 -> V_38 . V_108 . V_133 . V_62 = 0 ;
V_36 -> V_38 . V_108 . V_133 . V_23 = 720 ;
V_36 -> V_38 . V_108 . V_133 . V_25 = 576 ;
V_36 -> V_38 . V_108 . V_117 = 1 ;
V_36 -> V_38 . V_91 . V_26 = V_190 ;
V_36 -> V_38 . V_91 . V_53 = V_186 ;
V_36 -> V_38 . V_91 . V_124 = V_217 ;
V_36 -> V_38 . V_91 . V_130 = V_217 ;
V_36 -> V_38 . V_91 . V_127 = V_217 ;
V_36 -> V_38 . V_91 . V_133 . V_59 = 0 ;
V_36 -> V_38 . V_91 . V_133 . V_62 = 0 ;
V_36 -> V_38 . V_91 . V_133 . V_23 = 800 ;
V_36 -> V_38 . V_91 . V_133 . V_25 = 600 ;
V_36 -> V_38 . V_91 . V_90 . V_85 = V_182 ;
V_36 -> V_38 . V_91 . V_90 . V_82 . V_84 =
V_86 ;
}
static int F_53 ( struct V_8 * V_9 ,
struct V_28 * V_218 )
{
struct V_50 V_51 ;
enum V_188 V_140 ;
enum V_52 V_53 ;
memset ( V_218 , 0 , sizeof( * V_218 ) ) ;
V_218 -> type = V_219 ;
F_44 ( & V_9 -> V_36 , & V_51 ) ;
V_218 -> V_3 . V_13 . V_23 = V_51 . V_23 ;
V_218 -> V_3 . V_13 . V_25 = V_51 . V_25 ;
V_218 -> V_3 . V_13 . V_22 = F_45 ( & V_9 -> V_36 ) ;
V_218 -> V_3 . V_13 . V_24 = V_218 -> V_3 . V_13 . V_22 *
V_218 -> V_3 . V_13 . V_25 ;
V_140 = F_40 ( & V_9 -> V_36 ) ;
V_218 -> V_3 . V_13 . V_6 = F_42 ( & V_9 -> V_36 ) ;
V_53 = F_47 ( & V_9 -> V_36 ) ;
if ( V_53 == V_186 ) {
V_218 -> V_3 . V_13 . V_31 = V_220 ;
} else if ( V_53 == V_63 ) {
if ( V_140 == V_141 ) {
V_218 -> V_3 . V_13 . V_31 = V_221 ;
} else if ( V_140 == V_222 ) {
V_218 -> V_3 . V_13 . V_31 = V_223 ;
} else {
F_54 ( V_9 , L_23 ) ;
return - V_88 ;
}
} else {
F_54 ( V_9 , L_24 ) ;
return - V_88 ;
}
return 0 ;
}
static int F_55 ( struct V_8 * V_9 )
{
enum V_52 V_53 = V_63 ;
int V_224 ;
F_10 ( 2 , V_9 , L_25 ) ;
F_10 ( 1 , V_9 , L_26 ,
F_12 ( V_9 -> V_3 . V_3 . V_13 . V_6 ) ) ;
if ( F_41 ( & V_9 -> V_36 ,
V_9 -> V_3 . V_3 . V_13 . V_6 ) < 0 ) {
F_54 ( V_9 , L_27 ) ;
return - V_88 ;
}
F_43 ( & V_9 -> V_36 , & V_9 -> V_225 , V_9 -> V_14 ) ;
switch ( V_9 -> V_3 . V_3 . V_13 . V_31 ) {
case V_221 :
V_224 = F_39 (
& V_9 -> V_36 ,
V_141 ) ;
break;
case V_220 :
V_53 = V_186 ;
break;
case V_223 :
V_224 = F_39 (
& V_9 -> V_36 ,
V_222 ) ;
break;
default:
return - V_88 ;
}
if ( V_224 )
return V_224 ;
return F_46 ( & V_9 -> V_36 , V_53 ) ;
}
static int F_56 ( struct V_8 * V_9 ,
T_4 V_226 )
{
struct V_12 * V_13 = & V_9 -> V_3 . V_3 . V_13 ;
int V_92 , V_224 ;
for ( V_92 = 0 ; V_92 < F_2 ( V_227 ) ; V_92 ++ ) {
if ( V_227 [ V_92 ] . V_226 & V_226 ) {
V_9 -> V_228 . V_229 =
V_227 [ V_92 ] . V_23 ;
V_9 -> V_228 . V_230 =
V_227 [ V_92 ] . V_25 ;
V_9 -> V_228 . V_231 =
V_227 [ V_92 ] . V_231 ;
V_9 -> V_232 = V_92 ;
break;
}
}
if ( V_92 == F_2 ( V_227 ) ) {
F_54 ( V_9 , L_28 ) ;
return - V_88 ;
}
V_9 -> V_225 . V_62 = V_9 -> V_225 . V_59 = 0 ;
V_9 -> V_225 . V_23 = V_9 -> V_228 . V_229 ;
V_9 -> V_225 . V_25 = V_9 -> V_228 . V_230 ;
V_13 -> V_23 = V_9 -> V_225 . V_23 ;
V_13 -> V_25 = V_9 -> V_225 . V_25 ;
V_13 -> V_6 = V_192 ;
if ( V_9 -> V_228 . V_231 )
V_13 -> V_31 = V_221 ;
else
V_13 -> V_31 = V_220 ;
V_224 = F_57 ( V_9 , & V_9 -> V_3 , & V_9 -> V_14 ) ;
if ( V_224 )
return V_224 ;
V_9 -> V_225 . V_23 = V_13 -> V_23 ;
V_9 -> V_225 . V_25 = V_13 -> V_25 ;
return F_55 ( V_9 ) ;
}
static int F_58 ( struct V_8 * V_9 )
{
struct V_15 * V_16 ;
int V_224 ;
V_16 = & V_9 -> V_46 -> V_233 [ 0 ] ;
V_16 -> V_234 = V_9 -> V_234 [ 0 ] ;
V_9 -> V_235 = 0 ;
V_9 -> V_232 = 0 ;
V_224 = F_56 ( V_9 ,
V_227 [ V_9 -> V_232 ] . V_226 ) ;
if ( V_224 )
return V_224 ;
F_59 ( V_9 -> V_236 ) ;
F_22 ( & V_9 -> V_36 , 1 ) ;
F_29 ( & V_9 -> V_36 ) ;
F_51 ( & V_9 -> V_36 , - 1 ) ;
return V_224 ;
}
static int F_60 ( struct V_237 * V_237 )
{
struct V_8 * V_9 = F_61 ( V_237 ) ;
int V_224 ;
F_62 ( & V_9 -> V_238 ) ;
if ( F_63 ( V_237 ) )
F_30 ( & V_9 -> V_36 , V_9 -> V_236 ) ;
V_224 = F_64 ( V_237 , NULL ) ;
F_65 ( & V_9 -> V_238 ) ;
return V_224 ;
}
static int F_66 ( struct V_237 * V_237 )
{
struct V_8 * V_9 = F_61 ( V_237 ) ;
int V_224 ;
F_62 ( & V_9 -> V_238 ) ;
V_224 = F_67 ( V_237 ) ;
if ( V_224 ) {
F_54 ( V_9 , L_29 ) ;
goto V_239;
}
if ( ! F_63 ( V_237 ) )
goto V_239;
if ( F_58 ( V_9 ) ) {
F_68 ( V_237 ) ;
V_224 = - V_240 ;
}
V_239:
F_65 ( & V_9 -> V_238 ) ;
return V_224 ;
}
static inline void F_69 ( struct V_8 * V_9 )
{
V_9 -> V_241 = F_70 ( V_9 -> V_242 . V_243 ,
struct V_41 , V_244 ) ;
F_71 ( & V_9 -> V_241 -> V_244 ) ;
F_49 ( & V_9 -> V_36 ,
F_72 ( & V_9 -> V_241 -> V_43 , 0 ) ) ;
}
static inline void F_73 ( struct V_8 * V_9 )
{
unsigned long V_200 ;
V_200 = F_72 ( & V_9 -> V_241 -> V_43 , 0 ) +
V_9 -> V_245 ;
F_49 ( & V_9 -> V_36 , V_200 ) ;
}
static inline void F_74 ( struct V_8 * V_9 )
{
F_75 ( & V_9 -> V_246 -> V_43 . V_247 . V_248 ) ;
V_9 -> V_246 -> V_43 . V_247 . V_31 = V_9 -> V_3 . V_3 . V_13 . V_31 ;
V_9 -> V_246 -> V_43 . V_247 . V_249 = V_9 -> V_249 ++ ;
F_76 ( & V_9 -> V_246 -> V_43 , V_250 ) ;
V_9 -> V_246 = V_9 -> V_241 ;
}
static T_5 F_77 ( int V_251 , void * V_97 )
{
struct V_8 * V_9 = (struct V_8 * ) V_97 ;
enum V_252 V_31 ;
int V_253 ;
int V_254 ;
V_253 = F_14 ( & V_9 -> V_36 , V_211 ) ;
if ( V_253 & V_212 ) {
V_31 = V_9 -> V_3 . V_3 . V_13 . V_31 ;
if ( V_31 == V_220 ) {
if ( V_9 -> V_246 != V_9 -> V_241 )
F_74 ( V_9 ) ;
goto V_255;
}
V_254 = F_48 ( & V_9 -> V_36 ) ;
V_9 -> V_31 ^= 1 ;
if ( V_254 == V_9 -> V_31 ) {
if ( V_254 == 0 ) {
if ( V_9 -> V_246 != V_9 -> V_241 )
F_74 ( V_9 ) ;
if ( V_31 == V_223 )
F_73 ( V_9 ) ;
goto V_255;
}
F_78 ( & V_9 -> V_256 ) ;
if ( ! F_79 ( & V_9 -> V_242 ) &&
V_9 -> V_246 == V_9 -> V_241 )
F_69 ( V_9 ) ;
F_80 ( & V_9 -> V_256 ) ;
} else if ( V_254 == 0 ) {
V_9 -> V_31 = V_254 ;
}
}
V_255:
if ( V_253 & V_213 ) {
F_78 ( & V_9 -> V_256 ) ;
if ( V_9 -> V_3 . V_3 . V_13 . V_31 == V_220 &&
! F_79 ( & V_9 -> V_242 ) &&
V_9 -> V_246 == V_9 -> V_241 )
F_69 ( V_9 ) ;
F_80 ( & V_9 -> V_256 ) ;
}
F_51 ( & V_9 -> V_36 , V_253 ) ;
return V_257 ;
}
static inline void F_81 ( struct V_8 * V_9 )
{
unsigned int V_258 = V_212 ;
enum V_52 V_231 ;
V_231 = F_47 ( & V_9 -> V_36 ) ;
if ( V_231 == V_186 )
V_258 |= V_213 ;
F_16 ( & V_9 -> V_36 , V_258 , V_259 ) ;
}
static inline void F_82 ( struct V_8 * V_9 )
{
unsigned int V_258 = V_212 ;
enum V_52 V_231 ;
V_231 = F_47 ( & V_9 -> V_36 ) ;
if ( V_231 == V_186 )
V_258 |= V_213 ;
F_16 ( & V_9 -> V_36 , V_258 , V_260 ) ;
}
static int F_83 ( struct V_237 * V_237 , void * V_261 ,
struct V_262 * V_263 )
{
struct V_8 * V_9 = F_61 ( V_237 ) ;
F_10 ( 2 , V_9 , L_30 ) ;
F_84 ( V_263 -> V_264 , V_265 , sizeof( V_263 -> V_264 ) ) ;
F_84 ( V_263 -> V_266 , L_31 , sizeof( V_263 -> V_266 ) ) ;
snprintf ( V_263 -> V_267 , sizeof( V_263 -> V_267 ) ,
L_32 , V_9 -> V_268 . V_269 ) ;
V_263 -> V_270 = V_271 | V_272 |
V_273 ;
V_263 -> V_274 = V_263 -> V_270 | V_275 ;
return 0 ;
}
static int F_57 ( struct V_8 * V_9 ,
struct V_28 * V_276 , unsigned int * V_14 )
{
struct V_10 V_27 ;
struct V_15 * V_16 ;
struct V_277 V_3 ;
int V_224 ;
V_16 = V_9 -> V_17 ;
if ( ! V_16 -> V_234 )
return - V_88 ;
V_3 . V_278 = V_279 ;
V_3 . V_280 = 0 ;
V_224 = F_85 ( V_16 -> V_234 , V_280 , V_281 , NULL , & V_3 ) ;
if ( V_224 && V_224 != - V_282 && V_224 != - V_240 )
return V_224 ;
if ( ! V_224 ) {
F_7 ( & V_276 -> V_3 . V_13 , & V_3 . V_276 ) ;
F_4 ( V_9 , & V_3 . V_276 , & V_276 -> V_3 . V_13 , V_14 ) ;
} else {
V_224 = F_86 ( & V_9 -> V_268 ,
V_16 -> V_283 ,
V_284 , V_285 ,
& V_27 ) ;
if ( V_224 && V_224 != - V_282 && V_224 != - V_240 )
return V_224 ;
F_7 ( & V_276 -> V_3 . V_13 , & V_27 ) ;
F_4 ( V_9 , & V_27 , & V_276 -> V_3 . V_13 , V_14 ) ;
}
V_276 -> type = V_9 -> V_3 . type ;
F_10 ( 1 , V_9 ,
L_33 ,
V_286 , V_276 -> V_3 . V_13 . V_23 , V_276 -> V_3 . V_13 . V_25 ,
F_12 ( V_276 -> V_3 . V_13 . V_6 ) ,
V_276 -> V_3 . V_13 . V_22 , V_276 -> V_3 . V_13 . V_24 , * V_14 ) ;
return 0 ;
}
static int F_87 ( struct V_8 * V_9 ,
struct V_28 * V_276 , unsigned int * V_14 )
{
struct V_10 V_27 ;
struct V_15 * V_16 ;
struct V_277 V_3 ;
int V_224 ;
F_10 ( 2 , V_9 , L_34 ) ;
V_16 = V_9 -> V_17 ;
if ( ! V_16 -> V_234 )
return - V_88 ;
V_3 . V_278 = V_279 ;
V_3 . V_280 = 0 ;
F_9 ( V_9 , & V_276 -> V_3 . V_13 , & V_3 . V_276 ) ;
V_224 = F_85 ( V_16 -> V_234 , V_280 , V_287 , NULL , & V_3 ) ;
if ( V_224 && V_224 != - V_282 && V_224 != - V_240 )
return V_224 ;
if ( ! V_224 ) {
F_7 ( & V_276 -> V_3 . V_13 , & V_3 . V_276 ) ;
F_4 ( V_9 , & V_3 . V_276 , & V_276 -> V_3 . V_13 , V_14 ) ;
} else {
V_224 = F_86 ( & V_9 -> V_268 ,
V_16 -> V_283 ,
V_284 , V_288 ,
& V_27 ) ;
if ( V_224 && V_224 != - V_282 && V_224 != - V_240 )
return V_224 ;
F_7 ( & V_276 -> V_3 . V_13 , & V_27 ) ;
F_4 ( V_9 , & V_27 , & V_276 -> V_3 . V_13 , V_14 ) ;
}
V_276 -> type = V_9 -> V_3 . type ;
F_10 ( 1 , V_9 ,
L_33 ,
V_286 , V_276 -> V_3 . V_13 . V_23 , V_276 -> V_3 . V_13 . V_25 ,
F_12 ( V_276 -> V_3 . V_13 . V_6 ) ,
V_276 -> V_3 . V_13 . V_22 , V_276 -> V_3 . V_13 . V_24 , * V_14 ) ;
return 0 ;
}
static int F_88 ( struct V_237 * V_237 , void * V_261 ,
struct V_28 * V_3 )
{
struct V_8 * V_9 = F_61 ( V_237 ) ;
F_10 ( 2 , V_9 , L_35 ) ;
* V_3 = V_9 -> V_3 ;
return 0 ;
}
static int F_89 ( struct V_237 * V_237 , void * V_261 ,
struct V_289 * V_218 )
{
struct V_8 * V_9 = F_61 ( V_237 ) ;
struct V_15 * V_16 ;
struct V_1 * V_3 = NULL ;
unsigned int V_4 ;
F_10 ( 2 , V_9 , L_36 ,
V_218 -> V_290 ) ;
V_16 = V_9 -> V_17 ;
if ( ! V_16 -> V_234 )
return - V_88 ;
if ( V_218 -> V_290 > F_2 ( V_5 ) )
return - V_88 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; V_4 ++ ) {
if ( V_5 [ V_4 ] . V_290 == V_218 -> V_290 ) {
V_3 = & V_5 [ V_4 ] ;
break;
}
}
if ( ! V_3 )
return - V_88 ;
strncpy ( V_218 -> V_291 , V_3 -> V_269 , sizeof( V_218 -> V_291 ) - 1 ) ;
V_218 -> V_6 = V_3 -> V_7 ;
V_218 -> type = V_9 -> V_3 . type ;
F_10 ( 1 , V_9 , L_37 ,
V_218 -> V_290 , V_3 -> V_2 , F_12 ( V_3 -> V_7 ) , V_3 -> V_269 ) ;
return 0 ;
}
static int F_90 ( struct V_237 * V_237 , void * V_261 ,
struct V_28 * V_3 )
{
struct V_8 * V_9 = F_61 ( V_237 ) ;
unsigned int V_14 ;
F_10 ( 2 , V_9 , L_38 ) ;
return F_57 ( V_9 , V_3 , & V_14 ) ;
}
static int F_91 ( struct V_237 * V_237 , void * V_261 ,
struct V_28 * V_3 )
{
struct V_8 * V_9 = F_61 ( V_237 ) ;
struct V_28 V_276 ;
unsigned int V_14 ;
int V_224 ;
F_10 ( 2 , V_9 , L_39 ) ;
if ( F_92 ( & V_9 -> V_292 ) ) {
F_54 ( V_9 , L_40 , V_286 ) ;
return - V_293 ;
}
V_224 = F_90 ( V_237 , V_261 , V_3 ) ;
if ( V_224 )
return V_224 ;
if ( ! F_13 ( V_3 , & V_276 ) ) {
V_224 = F_87 ( V_9 , V_3 , & V_14 ) ;
if ( V_224 )
return V_224 ;
} else
* V_3 = V_276 ;
F_81 ( V_9 ) ;
V_9 -> V_3 = * V_3 ;
V_9 -> V_14 = V_14 ;
V_9 -> V_225 . V_23 = V_3 -> V_3 . V_13 . V_23 ;
V_9 -> V_225 . V_25 = V_3 -> V_3 . V_13 . V_25 ;
return F_55 ( V_9 ) ;
}
static int F_93 ( struct V_237 * V_237 , void * V_261 ,
struct V_294 * V_295 )
{
struct V_8 * V_9 = F_61 ( V_237 ) ;
struct V_296 V_297 ;
struct V_15 * V_16 ;
struct V_10 V_11 ;
struct V_12 V_13 ;
struct V_1 * V_3 ;
int V_224 ;
F_10 ( 2 , V_9 , L_41 ) ;
V_3 = F_3 ( V_295 -> V_298 ) ;
if ( ! V_3 ) {
F_10 ( 3 , V_9 , L_2 ,
V_295 -> V_298 ) ;
return - V_88 ;
}
memset ( V_295 -> V_299 , 0x0 , sizeof( V_295 -> V_299 ) ) ;
V_16 = V_9 -> V_17 ;
if ( ! V_16 -> V_234 )
return - V_88 ;
memset ( & V_13 , 0x0 , sizeof( V_13 ) ) ;
V_13 . V_6 = V_295 -> V_298 ;
V_13 . V_23 = 640 ;
V_13 . V_25 = 480 ;
V_13 . V_32 = V_300 ;
V_13 . V_31 = V_220 ;
F_9 ( V_9 , & V_13 , & V_11 ) ;
memset ( & V_297 , 0x0 , sizeof( V_297 ) ) ;
V_297 . V_290 = V_295 -> V_290 ;
V_297 . V_280 = 0 ;
V_297 . V_2 = V_11 . V_2 ;
V_297 . V_278 = V_279 ;
V_224 = F_85 ( V_16 -> V_234 , V_280 , V_301 , NULL , & V_297 ) ;
if ( V_224 )
return - V_88 ;
F_10 ( 1 , V_9 , L_42 ,
V_297 . V_290 , V_297 . V_2 , V_297 . V_302 , V_297 . V_303 ,
V_297 . V_304 , V_297 . V_305 ) ;
V_295 -> type = V_306 ;
V_295 -> V_307 . V_23 = V_297 . V_303 ;
V_295 -> V_307 . V_25 = V_297 . V_305 ;
F_10 ( 1 , V_9 , L_43 ,
V_295 -> V_290 , F_12 ( V_295 -> V_298 ) ,
V_295 -> V_307 . V_23 , V_295 -> V_307 . V_25 ) ;
return 0 ;
}
static int
F_94 ( struct V_8 * V_9 ,
int * V_308 ,
int * V_309 ,
int V_310 )
{
struct V_311 * V_46 = V_9 -> V_46 ;
struct V_15 * V_16 ;
int V_92 , V_312 = 0 ;
for ( V_92 = 0 ; V_92 < F_2 ( V_9 -> V_46 -> V_313 ) ; V_92 ++ ) {
V_16 = & V_46 -> V_233 [ V_92 ] ;
if ( V_310 < ( V_312 + 1 ) ) {
* V_308 = V_92 ;
* V_309 = V_310 - V_312 ;
return 0 ;
}
V_312 ++ ;
}
return - V_88 ;
}
static int F_95 ( struct V_8 * V_9 ,
int * V_310 )
{
struct V_311 * V_46 = V_9 -> V_46 ;
struct V_15 * V_16 ;
struct V_314 * V_315 ;
struct V_314 * V_316 ;
int V_92 , V_312 = 0 ;
V_316 = F_96 ( V_9 -> V_17 -> V_234 ) ;
for ( V_92 = 0 ; V_92 < F_2 ( V_9 -> V_46 -> V_313 ) ; V_92 ++ ) {
V_16 = & V_46 -> V_233 [ V_92 ] ;
V_315 = F_96 ( V_16 -> V_234 ) ;
if ( V_315 -> V_200 == V_316 -> V_200 &&
V_315 -> V_317 -> V_318 == V_315 -> V_317 -> V_318 ) {
if ( V_9 -> V_235 >= 1 )
return - 1 ;
* V_310 = V_312 + V_9 -> V_235 ;
return 0 ;
}
V_312 ++ ;
}
return - V_88 ;
}
static int F_97 ( struct V_237 * V_237 , void * V_261 ,
struct V_319 * V_320 )
{
struct V_8 * V_9 = F_61 ( V_237 ) ;
struct V_15 * V_16 ;
int V_321 , V_290 ;
F_10 ( 2 , V_9 , L_44 ) ;
if ( F_94 ( V_9 , & V_321 , & V_290 ,
V_320 -> V_290 ) < 0 ) {
F_10 ( 1 , V_9 ,
L_45 ) ;
return - V_88 ;
}
V_16 = & V_9 -> V_46 -> V_233 [ V_321 ] ;
* V_320 = V_16 -> V_322 [ V_290 ] ;
return 0 ;
}
static int F_98 ( struct V_237 * V_237 , void * V_261 , unsigned int * V_290 )
{
struct V_8 * V_9 = F_61 ( V_237 ) ;
F_10 ( 2 , V_9 , L_46 ) ;
return F_95 ( V_9 , V_290 ) ;
}
static int F_99 ( struct V_8 * V_9 , unsigned int V_290 )
{
int V_308 = 0 , V_323 = 0 ;
struct V_15 * V_16 ;
struct V_324 * V_325 ;
T_1 V_326 , V_327 ;
int V_224 ;
F_10 ( 2 , V_9 , L_47 , V_290 ) ;
if ( F_92 ( & V_9 -> V_292 ) ) {
F_54 ( V_9 , L_40 , V_286 ) ;
return - V_293 ;
}
V_224 = F_94 ( V_9 ,
& V_308 ,
& V_323 ,
V_290 ) ;
if ( V_224 < 0 ) {
F_54 ( V_9 , L_48 , V_290 ) ;
goto V_328;
}
V_16 = & V_9 -> V_46 -> V_233 [ V_308 ] ;
V_16 -> V_234 = V_9 -> V_234 [ V_308 ] ;
V_325 = & V_16 -> V_329 [ V_323 ] ;
if ( V_325 && V_16 -> V_330 ) {
V_326 = V_325 -> V_326 ;
V_327 = V_325 -> V_327 ;
if ( V_16 -> V_234 ) {
V_224 = F_85 ( V_16 -> V_234 , V_284 ,
V_331 , V_326 , V_327 , 0 ) ;
if ( V_224 ) {
F_54 ( V_9 , L_49 ) ;
V_224 = - V_88 ;
goto V_328;
}
}
}
V_9 -> V_17 = V_16 ;
if ( V_16 -> V_234 )
V_9 -> V_268 . V_332 = V_16 -> V_234 -> V_332 ;
V_9 -> V_235 = V_290 ;
V_9 -> V_232 = 0 ;
V_224 = F_50 ( & V_9 -> V_36 , & V_16 -> V_19 ) ;
if ( V_224 )
return V_224 ;
return F_56 ( V_9 ,
V_227 [ V_9 -> V_232 ] . V_226 ) ;
V_328:
return V_224 ;
}
static int F_100 ( struct V_237 * V_237 , void * V_261 , unsigned int V_290 )
{
struct V_8 * V_9 = F_61 ( V_237 ) ;
F_10 ( 2 , V_9 ,
L_50 , V_290 ) ;
return F_99 ( V_9 , V_290 ) ;
}
static int F_101 ( struct V_237 * V_237 , void * V_261 , T_4 * V_226 )
{
struct V_8 * V_9 = F_61 ( V_237 ) ;
struct V_15 * V_16 ;
F_10 ( 2 , V_9 , L_51 ) ;
V_16 = V_9 -> V_17 ;
if ( ! ( V_16 -> V_322 [ 0 ] . V_274 & V_333 ) )
return - V_334 ;
return F_86 ( & V_9 -> V_268 , V_16 -> V_283 ,
V_284 , V_335 , V_226 ) ;
}
static int F_102 ( struct V_237 * V_237 , void * V_261 , T_4 V_226 )
{
struct V_8 * V_9 = F_61 ( V_237 ) ;
struct V_15 * V_16 ;
int V_224 ;
F_10 ( 2 , V_9 , L_52 ) ;
V_16 = V_9 -> V_17 ;
if ( ! ( V_16 -> V_322 [ 0 ] . V_274 & V_333 ) )
return - V_334 ;
if ( F_92 ( & V_9 -> V_292 ) ) {
F_54 ( V_9 , L_40 , V_286 ) ;
V_224 = - V_293 ;
return V_224 ;
}
V_224 = F_86 ( & V_9 -> V_268 , V_16 -> V_283 ,
V_284 , V_336 , V_226 ) ;
if ( V_224 < 0 ) {
F_54 ( V_9 , L_53 ) ;
return V_224 ;
}
V_224 = F_56 ( V_9 , V_226 ) ;
return V_224 ;
}
static int F_103 ( struct V_237 * V_237 , void * V_261 , T_4 * V_226 )
{
struct V_8 * V_9 = F_61 ( V_237 ) ;
struct V_15 * V_16 ;
F_10 ( 2 , V_9 , L_54 ) ;
V_16 = V_9 -> V_17 ;
if ( V_16 -> V_322 [ 0 ] . V_274 != V_333 )
return - V_334 ;
* V_226 = V_227 [ V_9 -> V_232 ] . V_226 ;
return 0 ;
}
static void F_104 ( struct V_8 * V_9 )
{
struct V_50 V_51 ;
F_10 ( 2 , V_9 , L_55 ) ;
F_44 ( & V_9 -> V_36 , & V_51 ) ;
V_9 -> V_245 = V_51 . V_25 * V_51 . V_23 ;
}
static int F_105 ( struct V_337 * V_338 ,
const struct V_28 * V_3 ,
unsigned int * V_339 , unsigned int * V_340 ,
unsigned int V_341 [] , void * V_342 [] )
{
struct V_8 * V_9 = F_106 ( V_338 ) ;
if ( V_3 && V_3 -> V_3 . V_13 . V_24 < V_9 -> V_3 . V_3 . V_13 . V_24 )
return - V_88 ;
if ( V_338 -> V_343 + * V_339 < 3 )
* V_339 = 3 - V_338 -> V_343 ;
* V_340 = 1 ;
V_341 [ 0 ] = V_3 ? V_3 -> V_3 . V_13 . V_24 : V_9 -> V_3 . V_3 . V_13 . V_24 ;
V_342 [ 0 ] = V_9 -> V_344 ;
F_10 ( 1 , V_9 ,
L_56 , * V_339 , V_341 [ 0 ] ) ;
F_104 ( V_9 ) ;
return 0 ;
}
static int F_107 ( struct V_42 * V_43 )
{
struct V_8 * V_9 = F_106 ( V_43 -> V_337 ) ;
F_108 ( V_43 , 0 , V_9 -> V_3 . V_3 . V_13 . V_24 ) ;
if ( F_109 ( V_43 , 0 ) > F_110 ( V_43 , 0 ) )
return - V_88 ;
V_43 -> V_247 . V_31 = V_9 -> V_3 . V_3 . V_13 . V_31 ;
return 0 ;
}
static void F_111 ( struct V_42 * V_43 )
{
struct V_8 * V_9 = F_106 ( V_43 -> V_337 ) ;
struct V_41 * V_345 = F_20 ( V_43 ) ;
unsigned long V_346 = 0 ;
F_112 ( & V_9 -> V_256 , V_346 ) ;
F_113 ( & V_345 -> V_244 , & V_9 -> V_242 ) ;
F_114 ( & V_9 -> V_256 , V_346 ) ;
}
static int F_115 ( struct V_337 * V_338 , unsigned int V_347 )
{
struct V_8 * V_9 = F_106 ( V_338 ) ;
struct V_41 * V_345 , * V_348 ;
struct V_15 * V_16 ;
unsigned long V_346 ;
unsigned long V_200 ;
int V_224 ;
F_112 ( & V_9 -> V_256 , V_346 ) ;
V_9 -> V_31 = 0 ;
V_9 -> V_249 = 0 ;
V_16 = V_9 -> V_17 ;
F_82 ( V_9 ) ;
if ( V_9 -> V_36 . V_38 . V_104 == V_105 )
F_38 ( & V_9 -> V_36 ) ;
else
F_35 ( & V_9 -> V_36 ) ;
V_9 -> V_241 = F_70 ( V_9 -> V_242 . V_243 ,
struct V_41 , V_244 ) ;
V_9 -> V_246 = V_9 -> V_241 ;
F_71 ( & V_9 -> V_246 -> V_244 ) ;
F_114 ( & V_9 -> V_256 , V_346 ) ;
V_200 = F_72 ( & V_9 -> V_246 -> V_43 , 0 ) ;
F_49 ( & V_9 -> V_36 , ( unsigned long ) ( V_200 ) ) ;
F_21 ( & V_9 -> V_36 , 1 ) ;
V_224 = F_85 ( V_16 -> V_234 , V_284 , V_349 , 1 ) ;
if ( V_224 < 0 ) {
F_54 ( V_9 , L_57 ) ;
goto V_350;
}
return 0 ;
V_350:
F_116 (buf, tmp, &vpfe->dma_queue, list) {
F_71 ( & V_345 -> V_244 ) ;
F_76 ( & V_345 -> V_43 , V_351 ) ;
}
return V_224 ;
}
static void F_117 ( struct V_337 * V_338 )
{
struct V_8 * V_9 = F_106 ( V_338 ) ;
struct V_15 * V_16 ;
unsigned long V_346 ;
int V_224 ;
F_21 ( & V_9 -> V_36 , 0 ) ;
F_81 ( V_9 ) ;
V_16 = V_9 -> V_17 ;
V_224 = F_85 ( V_16 -> V_234 , V_284 , V_349 , 0 ) ;
if ( V_224 && V_224 != - V_282 && V_224 != - V_240 )
F_10 ( 1 , V_9 , L_58 ) ;
F_112 ( & V_9 -> V_256 , V_346 ) ;
if ( V_9 -> V_246 == V_9 -> V_241 ) {
F_76 ( & V_9 -> V_246 -> V_43 , V_352 ) ;
} else {
if ( V_9 -> V_246 != NULL )
F_76 ( & V_9 -> V_246 -> V_43 ,
V_352 ) ;
if ( V_9 -> V_241 != NULL )
F_76 ( & V_9 -> V_241 -> V_43 ,
V_352 ) ;
}
while ( ! F_79 ( & V_9 -> V_242 ) ) {
V_9 -> V_241 = F_70 ( V_9 -> V_242 . V_243 ,
struct V_41 , V_244 ) ;
F_71 ( & V_9 -> V_241 -> V_244 ) ;
F_76 ( & V_9 -> V_241 -> V_43 , V_352 ) ;
}
F_114 ( & V_9 -> V_256 , V_346 ) ;
}
static int F_118 ( struct V_237 * V_237 , void * V_261 ,
struct V_353 * V_225 )
{
struct V_8 * V_9 = F_61 ( V_237 ) ;
F_10 ( 2 , V_9 , L_59 ) ;
if ( V_9 -> V_232 >= F_2 ( V_227 ) )
return - V_88 ;
memset ( V_225 , 0 , sizeof( struct V_353 ) ) ;
V_225 -> type = V_219 ;
V_225 -> V_354 . V_23 = V_227 [ V_9 -> V_232 ] . V_23 ;
V_225 -> V_355 . V_23 = V_225 -> V_354 . V_23 ;
V_225 -> V_354 . V_25 = V_227 [ V_9 -> V_232 ] . V_25 ;
V_225 -> V_355 . V_25 = V_225 -> V_354 . V_25 ;
V_225 -> V_356 = V_227 [ V_9 -> V_232 ] . V_356 ;
return 0 ;
}
static int
F_119 ( struct V_237 * V_237 , void * V_357 , struct V_358 * V_21 )
{
struct V_8 * V_9 = F_61 ( V_237 ) ;
switch ( V_21 -> V_359 ) {
case V_360 :
case V_361 :
V_21 -> V_169 . V_59 = V_21 -> V_169 . V_62 = 0 ;
V_21 -> V_169 . V_23 = V_9 -> V_225 . V_23 ;
V_21 -> V_169 . V_25 = V_9 -> V_225 . V_25 ;
break;
case V_362 :
V_21 -> V_169 = V_9 -> V_225 ;
break;
default:
return - V_88 ;
}
return 0 ;
}
static int F_120 ( struct V_50 * V_363 , struct V_50 * V_163 )
{
if ( V_363 -> V_59 < V_163 -> V_59 || V_363 -> V_62 < V_163 -> V_62 )
return 0 ;
if ( V_363 -> V_59 + V_363 -> V_23 > V_163 -> V_59 + V_163 -> V_23 )
return 0 ;
if ( V_363 -> V_62 + V_363 -> V_25 > V_163 -> V_62 + V_163 -> V_25 )
return 0 ;
return 1 ;
}
static int
F_121 ( struct V_237 * V_237 , void * V_357 , struct V_358 * V_21 )
{
struct V_8 * V_9 = F_61 ( V_237 ) ;
struct V_50 V_364 = V_9 -> V_225 ;
struct V_50 V_169 = V_21 -> V_169 ;
if ( F_92 ( & V_9 -> V_292 ) ) {
F_54 ( V_9 , L_40 , V_286 ) ;
return - V_293 ;
}
if ( V_21 -> type != V_219 ||
V_21 -> V_359 != V_362 )
return - V_88 ;
F_122 ( & V_169 . V_23 , 0 , V_364 . V_23 , 0 ,
& V_169 . V_25 , 0 , V_364 . V_25 , 0 , 0 ) ;
V_169 . V_59 = F_123 (unsigned int, r.left, 0 , cr.width - r.width) ;
V_169 . V_62 = F_123 (unsigned int, r.top, 0 , cr.height - r.height) ;
if ( V_21 -> V_346 & V_365 && ! F_120 ( & V_169 , & V_21 -> V_169 ) )
return - V_366 ;
if ( V_21 -> V_346 & V_367 && ! F_120 ( & V_21 -> V_169 , & V_169 ) )
return - V_366 ;
V_21 -> V_169 = V_9 -> V_225 = V_169 ;
F_43 ( & V_9 -> V_36 , & V_169 , V_9 -> V_14 ) ;
V_9 -> V_3 . V_3 . V_13 . V_23 = V_169 . V_23 ;
V_9 -> V_3 . V_3 . V_13 . V_25 = V_169 . V_25 ;
V_9 -> V_3 . V_3 . V_13 . V_22 = F_45 ( & V_9 -> V_36 ) ;
V_9 -> V_3 . V_3 . V_13 . V_24 = V_9 -> V_3 . V_3 . V_13 . V_22 *
V_9 -> V_3 . V_3 . V_13 . V_25 ;
F_10 ( 1 , V_9 , L_60 ,
V_169 . V_59 , V_169 . V_62 , V_169 . V_23 , V_169 . V_25 , V_364 . V_23 , V_364 . V_25 ) ;
return 0 ;
}
static long F_124 ( struct V_237 * V_237 , void * V_261 ,
bool V_368 , unsigned int V_369 , void * V_370 )
{
struct V_8 * V_9 = F_61 ( V_237 ) ;
int V_224 ;
F_10 ( 2 , V_9 , L_61 ) ;
if ( ! V_368 ) {
F_54 ( V_9 , L_40 , V_286 ) ;
return - V_293 ;
}
if ( F_92 ( & V_9 -> V_292 ) ) {
F_54 ( V_9 , L_40 , V_286 ) ;
return - V_293 ;
}
switch ( V_369 ) {
case V_371 :
V_224 = F_33 ( & V_9 -> V_36 , ( void T_3 * ) V_370 ) ;
if ( V_224 ) {
F_10 ( 2 , V_9 ,
L_62 ) ;
return V_224 ;
}
V_224 = F_53 ( V_9 ,
& V_9 -> V_3 ) ;
if ( V_224 < 0 ) {
F_10 ( 2 , V_9 ,
L_63 ) ;
return V_224 ;
}
break;
default:
V_224 = - V_372 ;
break;
}
return V_224 ;
}
static int
F_125 ( struct V_373 * V_374 ,
struct V_375 * V_321 ,
struct V_376 * V_313 )
{
struct V_8 * V_9 = F_19 ( V_374 -> V_268 ,
struct V_8 , V_268 ) ;
struct V_377 V_378 ;
struct V_15 * V_16 ;
bool V_379 = false ;
int V_92 , V_312 ;
F_10 ( 1 , V_9 , L_64 ) ;
for ( V_92 = 0 ; V_92 < F_2 ( V_9 -> V_46 -> V_313 ) ; V_92 ++ ) {
if ( V_9 -> V_46 -> V_313 [ V_92 ] -> V_380 . V_381 . V_382 == V_313 [ V_92 ] . V_380 . V_381 . V_382 ) {
V_16 = & V_9 -> V_46 -> V_233 [ V_92 ] ;
V_9 -> V_234 [ V_92 ] = V_321 ;
V_9 -> V_234 [ V_92 ] -> V_283 = V_16 -> V_283 ;
V_379 = true ;
break;
}
}
if ( ! V_379 ) {
F_126 ( V_9 , L_65 , V_321 -> V_269 ) ;
return - V_88 ;
}
V_9 -> V_383 . V_384 |= V_16 -> V_322 [ 0 ] . V_385 ;
for ( V_312 = 0 , V_92 = 0 ; ; ++ V_312 ) {
struct V_1 * V_3 ;
int V_224 ;
memset ( & V_378 , 0 , sizeof( V_378 ) ) ;
V_378 . V_290 = V_312 ;
V_378 . V_278 = V_279 ;
V_224 = F_85 ( V_321 , V_280 , V_386 ,
NULL , & V_378 ) ;
if ( V_224 )
break;
V_3 = F_1 ( V_378 . V_2 ) ;
if ( ! V_3 )
continue;
V_3 -> V_387 = true ;
V_3 -> V_290 = V_92 ++ ;
}
return 0 ;
}
static int F_127 ( struct V_8 * V_9 )
{
struct V_388 * V_389 ;
struct V_337 * V_390 ;
int V_350 ;
F_128 ( & V_9 -> V_256 ) ;
F_129 ( & V_9 -> V_238 ) ;
V_9 -> V_3 . type = V_219 ;
V_9 -> V_17 = & V_9 -> V_46 -> V_233 [ 0 ] ;
V_9 -> V_268 . V_332 = V_9 -> V_234 [ 0 ] -> V_332 ;
V_350 = F_99 ( V_9 , 0 ) ;
if ( V_350 )
goto V_391;
V_9 -> V_344 = F_130 ( V_9 -> V_236 ) ;
if ( F_131 ( V_9 -> V_344 ) ) {
F_54 ( V_9 , L_66 ) ;
V_350 = F_132 ( V_9 -> V_344 ) ;
goto V_391;
}
V_390 = & V_9 -> V_292 ;
V_390 -> type = V_219 ;
V_390 -> V_392 = V_393 | V_394 | V_395 ;
V_390 -> V_396 = V_9 ;
V_390 -> V_397 = & V_398 ;
V_390 -> V_399 = & V_400 ;
V_390 -> V_401 = sizeof( struct V_41 ) ;
V_390 -> V_402 = V_403 ;
V_390 -> V_238 = & V_9 -> V_238 ;
V_390 -> V_404 = 1 ;
V_350 = F_133 ( V_390 ) ;
if ( V_350 ) {
F_54 ( V_9 , L_67 ) ;
F_134 ( V_9 -> V_344 ) ;
goto V_391;
}
F_135 ( & V_9 -> V_242 ) ;
V_389 = & V_9 -> V_383 ;
F_84 ( V_389 -> V_269 , V_265 , sizeof( V_389 -> V_269 ) ) ;
V_389 -> V_405 = V_406 ;
V_389 -> V_407 = & V_408 ;
V_389 -> V_409 = & V_410 ;
V_389 -> V_268 = & V_9 -> V_268 ;
V_389 -> V_411 = V_412 ;
V_389 -> V_413 = V_390 ;
V_389 -> V_238 = & V_9 -> V_238 ;
F_136 ( V_389 , V_9 ) ;
V_350 = F_137 ( & V_9 -> V_383 , V_414 , - 1 ) ;
if ( V_350 ) {
F_54 ( V_9 ,
L_68 ) ;
goto V_391;
}
return 0 ;
V_391:
F_138 ( & V_9 -> V_268 ) ;
return V_350 ;
}
static int F_139 ( struct V_373 * V_374 )
{
struct V_8 * V_9 = F_19 ( V_374 -> V_268 ,
struct V_8 , V_268 ) ;
return F_127 ( V_9 ) ;
}
static struct V_311 *
F_140 ( struct V_415 * V_236 )
{
struct V_416 * V_417 = NULL ;
struct V_418 V_419 ;
struct V_15 * V_16 ;
struct V_311 * V_420 ;
unsigned int V_346 ;
unsigned int V_92 ;
int V_350 ;
F_141 ( & V_236 -> V_97 , L_69 ) ;
if ( ! F_142 ( V_421 ) || ! V_236 -> V_97 . V_422 )
return V_236 -> V_97 . V_423 ;
V_420 = F_143 ( & V_236 -> V_97 , sizeof( * V_420 ) , V_424 ) ;
if ( ! V_420 )
return NULL ;
for ( V_92 = 0 ; ; V_92 ++ ) {
struct V_416 * V_425 ;
V_417 = F_144 ( V_236 -> V_97 . V_422 ,
V_417 ) ;
if ( ! V_417 )
break;
V_16 = & V_420 -> V_233 [ V_92 ] ;
V_16 -> V_283 = 0 ;
V_16 -> V_322 [ 0 ] . V_290 = V_92 ;
strcpy ( V_16 -> V_322 [ 0 ] . V_269 , L_70 ) ;
V_16 -> V_322 [ 0 ] . type = V_426 ;
V_16 -> V_322 [ 0 ] . V_385 = V_427 ;
V_16 -> V_322 [ 0 ] . V_274 = V_333 ;
V_16 -> V_330 = 0 ;
V_16 -> V_329 = NULL ;
F_145 ( V_417 , L_71 ,
& V_16 -> V_19 . V_104 ) ;
if ( V_16 -> V_19 . V_104 < 0 ||
V_16 -> V_19 . V_104 > 4 ) {
V_16 -> V_19 . V_104 = V_105 ;
}
V_350 = F_146 ( V_417 , & V_419 ) ;
if ( V_350 ) {
F_147 ( & V_236 -> V_97 , L_72 ) ;
goto V_428;
}
V_16 -> V_19 . V_18 = V_419 . V_429 . V_430 . V_18 ;
if ( V_16 -> V_19 . V_18 < 8 ||
V_16 -> V_19 . V_18 > 16 ) {
F_147 ( & V_236 -> V_97 , L_73 ) ;
goto V_428;
}
V_346 = V_419 . V_429 . V_430 . V_346 ;
if ( V_346 & V_431 )
V_16 -> V_19 . V_207 = 1 ;
if ( V_346 & V_432 )
V_16 -> V_19 . V_206 = 1 ;
V_425 = F_148 ( V_417 ) ;
if ( ! V_425 ) {
F_147 ( & V_236 -> V_97 , L_74 ,
V_417 -> V_433 ) ;
goto V_428;
}
V_420 -> V_313 [ V_92 ] = F_143 ( & V_236 -> V_97 ,
sizeof( struct V_376 ) ,
V_424 ) ;
if ( ! V_420 -> V_313 [ V_92 ] ) {
F_149 ( V_425 ) ;
V_420 = NULL ;
goto V_428;
}
V_420 -> V_313 [ V_92 ] -> V_434 = V_435 ;
V_420 -> V_313 [ V_92 ] -> V_380 . V_381 . V_382 = V_425 ;
F_149 ( V_425 ) ;
}
F_149 ( V_417 ) ;
return V_420 ;
V_428:
F_149 ( V_417 ) ;
return NULL ;
}
static int F_150 ( struct V_415 * V_236 )
{
struct V_311 * V_436 = F_140 ( V_236 ) ;
struct V_8 * V_9 ;
struct V_35 * V_36 ;
struct V_437 * V_438 ;
int V_224 ;
if ( ! V_436 ) {
F_147 ( & V_236 -> V_97 , L_75 ) ;
return - V_88 ;
}
V_9 = F_143 ( & V_236 -> V_97 , sizeof( * V_9 ) , V_424 ) ;
if ( ! V_9 )
return - V_439 ;
V_9 -> V_236 = & V_236 -> V_97 ;
V_9 -> V_46 = V_436 ;
V_36 = & V_9 -> V_36 ;
V_438 = F_151 ( V_236 , V_440 , 0 ) ;
V_36 -> V_38 . V_39 = F_152 ( & V_236 -> V_97 , V_438 ) ;
if ( F_131 ( V_36 -> V_38 . V_39 ) )
return F_132 ( V_36 -> V_38 . V_39 ) ;
V_9 -> V_251 = F_153 ( V_236 , 0 ) ;
if ( V_9 -> V_251 <= 0 ) {
F_147 ( & V_236 -> V_97 , L_76 ) ;
return - V_240 ;
}
V_224 = F_154 ( V_9 -> V_236 , V_9 -> V_251 , F_77 , 0 ,
L_77 , V_9 ) ;
if ( V_224 ) {
F_147 ( & V_236 -> V_97 , L_78 ) ;
return - V_88 ;
}
V_224 = F_155 ( & V_236 -> V_97 , & V_9 -> V_268 ) ;
if ( V_224 ) {
F_54 ( V_9 ,
L_79 ) ;
return V_224 ;
}
F_156 ( V_236 , V_9 ) ;
F_157 ( & V_236 -> V_97 ) ;
F_59 ( & V_236 -> V_97 ) ;
F_52 ( V_36 ) ;
F_32 ( & V_236 -> V_97 ) ;
V_9 -> V_234 = F_143 ( & V_236 -> V_97 , sizeof( struct V_375 * ) *
F_2 ( V_9 -> V_46 -> V_313 ) , V_424 ) ;
if ( ! V_9 -> V_234 ) {
V_224 = - V_439 ;
goto V_441;
}
V_9 -> V_374 . V_442 = V_9 -> V_46 -> V_313 ;
V_9 -> V_374 . V_443 = F_2 ( V_9 -> V_46 -> V_313 ) ;
V_9 -> V_374 . V_444 = F_125 ;
V_9 -> V_374 . V_445 = F_139 ;
V_224 = F_158 ( & V_9 -> V_268 ,
& V_9 -> V_374 ) ;
if ( V_224 ) {
F_54 ( V_9 , L_80 ) ;
V_224 = - V_88 ;
goto V_441;
}
return 0 ;
V_441:
F_138 ( & V_9 -> V_268 ) ;
return V_224 ;
}
static int F_159 ( struct V_415 * V_236 )
{
struct V_8 * V_9 = F_160 ( V_236 ) ;
F_10 ( 2 , V_9 , L_81 ) ;
F_161 ( & V_236 -> V_97 ) ;
F_162 ( & V_9 -> V_374 ) ;
F_138 ( & V_9 -> V_268 ) ;
F_163 ( & V_9 -> V_383 ) ;
return 0 ;
}
static void F_164 ( struct V_35 * V_36 )
{
V_36 -> V_446 [ V_45 >> 2 ] = F_14 ( V_36 , V_45 ) ;
V_36 -> V_446 [ V_76 >> 2 ] = F_14 ( V_36 , V_76 ) ;
V_36 -> V_446 [ V_75 >> 2 ] = F_14 ( V_36 , V_75 ) ;
V_36 -> V_446 [ V_201 >> 2 ] = F_14 ( V_36 , V_201 ) ;
V_36 -> V_446 [ V_71 >> 2 ] = F_14 ( V_36 , V_71 ) ;
V_36 -> V_446 [ V_72 >> 2 ] = F_14 ( V_36 , V_72 ) ;
V_36 -> V_446 [ V_74 >> 2 ] = F_14 ( V_36 , V_74 ) ;
V_36 -> V_446 [ V_73 >> 2 ] = F_14 ( V_36 , V_73 ) ;
V_36 -> V_446 [ V_66 >> 2 ] = F_14 ( V_36 , V_66 ) ;
V_36 -> V_446 [ V_70 >> 2 ] = F_14 ( V_36 , V_70 ) ;
V_36 -> V_446 [ V_119 >> 2 ] = F_14 ( V_36 , V_119 ) ;
V_36 -> V_446 [ V_139 >> 2 ] = F_14 ( V_36 , V_139 ) ;
V_36 -> V_446 [ V_94 >> 2 ] = F_14 ( V_36 , V_94 ) ;
V_36 -> V_446 [ V_447 >> 2 ] = F_14 ( V_36 ,
V_447 ) ;
V_36 -> V_446 [ V_448 >> 2 ] = F_14 ( V_36 ,
V_448 ) ;
V_36 -> V_446 [ V_61 >> 2 ] = F_14 ( V_36 ,
V_61 ) ;
V_36 -> V_446 [ V_68 >> 2 ] = F_14 ( V_36 ,
V_68 ) ;
V_36 -> V_446 [ V_69 >> 2 ] = F_14 ( V_36 ,
V_69 ) ;
V_36 -> V_446 [ V_77 >> 2 ] = F_14 ( V_36 ,
V_77 ) ;
}
static int F_165 ( struct V_96 * V_97 )
{
struct V_415 * V_236 = F_166 ( V_97 ) ;
struct V_8 * V_9 = F_160 ( V_236 ) ;
struct V_35 * V_36 = & V_9 -> V_36 ;
if ( ! F_167 ( & V_9 -> V_292 ) )
return 0 ;
F_59 ( V_97 ) ;
F_22 ( V_36 , 1 ) ;
F_164 ( V_36 ) ;
F_21 ( V_36 , 0 ) ;
F_22 ( V_36 , 0 ) ;
F_32 ( V_97 ) ;
F_168 ( V_97 ) ;
return 0 ;
}
static void F_169 ( struct V_35 * V_36 )
{
F_16 ( V_36 , V_36 -> V_446 [ V_76 >> 2 ] , V_76 ) ;
F_16 ( V_36 , V_36 -> V_446 [ V_94 >> 2 ] , V_94 ) ;
F_16 ( V_36 , V_36 -> V_446 [ V_75 >> 2 ] , V_75 ) ;
F_16 ( V_36 , V_36 -> V_446 [ V_201 >> 2 ] , V_201 ) ;
F_16 ( V_36 , V_36 -> V_446 [ V_71 >> 2 ] , V_71 ) ;
F_16 ( V_36 , V_36 -> V_446 [ V_72 >> 2 ] , V_72 ) ;
F_16 ( V_36 , V_36 -> V_446 [ V_74 >> 2 ] , V_74 ) ;
F_16 ( V_36 , V_36 -> V_446 [ V_73 >> 2 ] , V_73 ) ;
F_16 ( V_36 , V_36 -> V_446 [ V_66 >> 2 ] , V_66 ) ;
F_16 ( V_36 , V_36 -> V_446 [ V_70 >> 2 ] , V_70 ) ;
F_16 ( V_36 , V_36 -> V_446 [ V_119 >> 2 ] , V_119 ) ;
F_16 ( V_36 , V_36 -> V_446 [ V_139 >> 2 ] , V_139 ) ;
F_16 ( V_36 , V_36 -> V_446 [ V_45 >> 2 ] , V_45 ) ;
F_16 ( V_36 , V_36 -> V_446 [ V_447 >> 2 ] ,
V_447 ) ;
F_16 ( V_36 , V_36 -> V_446 [ V_448 >> 2 ] ,
V_448 ) ;
F_16 ( V_36 , V_36 -> V_446 [ V_61 >> 2 ] ,
V_61 ) ;
F_16 ( V_36 , V_36 -> V_446 [ V_68 >> 2 ] ,
V_68 ) ;
F_16 ( V_36 , V_36 -> V_446 [ V_69 >> 2 ] ,
V_69 ) ;
F_16 ( V_36 , V_36 -> V_446 [ V_77 >> 2 ] ,
V_77 ) ;
}
static int F_170 ( struct V_96 * V_97 )
{
struct V_415 * V_236 = F_166 ( V_97 ) ;
struct V_8 * V_9 = F_160 ( V_236 ) ;
struct V_35 * V_36 = & V_9 -> V_36 ;
if ( ! F_167 ( & V_9 -> V_292 ) )
return 0 ;
F_59 ( V_97 ) ;
F_22 ( V_36 , 1 ) ;
F_169 ( V_36 ) ;
F_22 ( V_36 , 0 ) ;
F_32 ( V_97 ) ;
F_171 ( V_97 ) ;
return 0 ;
}
