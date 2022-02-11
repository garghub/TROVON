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
V_29 -> V_3 . V_13 . V_34 == V_30 -> V_3 . V_13 . V_34 &&
V_29 -> V_3 . V_13 . V_35 == V_30 -> V_3 . V_13 . V_35 ;
}
static inline T_1 F_14 ( struct V_36 * V_37 , T_1 V_38 )
{
return F_15 ( V_37 -> V_39 . V_40 + V_38 ) ;
}
static inline void F_16 ( struct V_36 * V_37 , T_1 V_41 , T_1 V_38 )
{
F_17 ( V_41 , V_37 -> V_39 . V_40 + V_38 ) ;
}
static inline struct V_8 * F_18 ( struct V_36 * V_37 )
{
return F_19 ( V_37 , struct V_8 , V_37 ) ;
}
static inline
struct V_42 * F_20 ( struct V_43 * V_44 )
{
return F_19 ( V_44 , struct V_42 , V_44 ) ;
}
static inline void F_21 ( struct V_36 * V_37 , int V_45 )
{
F_16 ( V_37 , ! ! V_45 , V_46 ) ;
}
static void F_22 ( struct V_36 * V_37 , int V_45 )
{
unsigned int V_47 ;
if ( ! V_45 ) {
V_47 = F_14 ( V_37 , V_48 ) ;
V_47 &= ~ ( V_49 << V_50 ) ;
} else {
V_47 = V_49 << V_50 ;
}
F_16 ( V_37 , V_47 , V_48 ) ;
}
static void F_23 ( struct V_36 * V_37 ,
struct V_51 * V_52 ,
enum V_53 V_54 ,
int V_14 )
{
int V_55 , V_56 ;
int V_57 , V_58 ;
int V_41 , V_59 ;
V_55 = V_52 -> V_60 * V_14 ;
V_56 = ( V_52 -> V_23 * V_14 ) - 1 ;
F_16 ( V_37 , ( V_55 << V_61 ) |
V_56 , V_62 ) ;
V_57 = V_52 -> V_63 ;
if ( V_54 == V_64 ) {
V_58 = ( V_52 -> V_25 >> 1 ) - 1 ;
V_57 >>= 1 ;
V_57 += 1 ;
V_41 = ( V_57 << V_65 ) ;
} else {
V_57 += 1 ;
V_58 = V_52 -> V_25 - 1 ;
V_59 = V_57 + ( V_52 -> V_25 / 2 ) ;
V_41 = ( V_57 << V_65 ) |
( V_59 & V_66 ) ;
}
F_16 ( V_37 , V_41 , V_67 ) ;
F_16 ( V_37 , ( V_57 << V_68 ) |
V_57 , V_69 ) ;
F_16 ( V_37 , V_58 , V_70 ) ;
}
static void F_24 ( struct V_36 * V_37 )
{
struct V_8 * V_9 = F_18 ( V_37 ) ;
F_10 ( 3 , V_9 , L_3 , F_14 ( V_37 , V_71 ) ) ;
F_10 ( 3 , V_9 , L_4 , F_14 ( V_37 , V_72 ) ) ;
F_10 ( 3 , V_9 , L_5 , F_14 ( V_37 , V_73 ) ) ;
F_10 ( 3 , V_9 , L_6 , F_14 ( V_37 , V_74 ) ) ;
F_10 ( 3 , V_9 , L_7 , F_14 ( V_37 , V_75 ) ) ;
F_10 ( 3 , V_9 , L_8 , F_14 ( V_37 , V_76 ) ) ;
F_10 ( 3 , V_9 , L_9 ,
F_14 ( V_37 , V_77 ) ) ;
F_10 ( 3 , V_9 , L_10 ,
F_14 ( V_37 , V_78 ) ) ;
F_10 ( 3 , V_9 , L_11 ,
F_14 ( V_37 , V_62 ) ) ;
F_10 ( 3 , V_9 , L_12 ,
F_14 ( V_37 , V_69 ) ) ;
F_10 ( 3 , V_9 , L_13 ,
F_14 ( V_37 , V_70 ) ) ;
}
static int
F_25 ( struct V_36 * V_37 ,
struct V_79 * V_80 )
{
struct V_8 * V_9 = F_18 ( V_37 ) ;
T_2 V_81 , V_82 ;
if ( ! V_80 -> V_83 . V_84 )
return 0 ;
V_81 = F_26 ( V_80 -> V_83 . V_85 ) ;
V_82 = F_27 ( V_80 -> V_86 ) ;
if ( V_80 -> V_83 . V_85 > V_87 ||
V_80 -> V_83 . V_85 < V_88 ||
V_81 > V_82 ) {
F_10 ( 1 , V_9 , L_14 ) ;
return - V_89 ;
}
return 0 ;
}
static void
F_28 ( struct V_36 * V_37 ,
struct V_79 * V_90 )
{
struct V_79 * V_91 =
& V_37 -> V_39 . V_92 . V_91 ;
* V_91 = * V_90 ;
}
static void F_29 ( struct V_36 * V_37 )
{
int V_93 ;
F_21 ( V_37 , 0 ) ;
for ( V_93 = 4 ; V_93 <= 0x94 ; V_93 += 4 )
F_16 ( V_37 , 0 , V_93 ) ;
F_16 ( V_37 , V_94 , V_95 ) ;
F_16 ( V_37 , V_96 , V_71 ) ;
}
static int F_30 ( struct V_36 * V_37 , struct V_97 * V_98 )
{
int V_99 , V_93 , V_100 ;
for ( V_93 = 0 ; V_93 < 10 ; V_93 ++ ) {
F_31 ( 5000 , 6000 ) ;
V_100 = F_14 ( V_37 , V_46 ) ;
if ( ! V_100 )
break;
F_21 ( V_37 , 0 ) ;
}
F_29 ( V_37 ) ;
for ( V_93 = 0 ; V_93 < 10 ; V_93 ++ ) {
V_99 = F_14 ( V_37 , V_101 ) ;
if ( ! ( V_99 & V_102 ) )
break;
F_16 ( V_37 , V_99 , V_101 ) ;
F_31 ( 5000 , 6000 ) ;
}
F_22 ( V_37 , 0 ) ;
F_32 ( V_98 ) ;
return 0 ;
}
static int F_33 ( struct V_36 * V_37 , void T_3 * V_103 )
{
struct V_8 * V_9 = F_19 ( V_37 , struct V_8 , V_37 ) ;
struct V_79 V_90 ;
int V_104 ;
if ( V_37 -> V_39 . V_105 != V_106 )
return - V_89 ;
V_104 = F_34 ( & V_90 , V_103 , sizeof( V_90 ) ) ;
if ( V_104 ) {
F_10 ( 1 , V_9 ,
L_15 ,
V_104 ) ;
return - V_107 ;
}
if ( ! F_25 ( V_37 , & V_90 ) ) {
F_28 ( V_37 , & V_90 ) ;
return 0 ;
}
return - V_89 ;
}
static void F_35 ( struct V_36 * V_37 )
{
struct V_8 * V_9 = F_19 ( V_37 , struct V_8 , V_37 ) ;
struct V_108 * V_103 = & V_37 -> V_39 . V_109 ;
T_1 V_110 ;
F_10 ( 3 , V_9 , L_16 ) ;
F_29 ( V_37 ) ;
V_110 = ( ( ( V_103 -> V_26 & V_111 ) <<
V_112 ) |
( ( V_103 -> V_54 & V_113 ) <<
V_114 ) | V_115 |
V_116 | V_117 ) ;
if ( V_103 -> V_118 ) {
F_16 ( V_37 , V_119 , V_120 ) ;
V_110 |= V_121 ;
if ( V_37 -> V_39 . V_105 == V_122 )
V_110 |= V_123 ;
else
V_110 |= V_124 ;
} else {
V_110 |= ( ( ( V_103 -> V_125 & V_126 ) <<
V_127 ) |
( ( V_103 -> V_128 & V_129 ) <<
V_130 ) |
( ( V_103 -> V_131 & V_132 ) <<
V_133 ) ) ;
}
F_16 ( V_37 , V_110 , V_77 ) ;
F_23 ( V_37 , & V_103 -> V_134 ,
V_103 -> V_54 , V_103 -> V_135 ) ;
if ( V_37 -> V_39 . V_105 == V_122 )
F_16 ( V_37 ,
( V_103 -> V_136 << V_137 ) |
V_138 |
V_139 , V_140 ) ;
else
F_16 ( V_37 ,
( V_103 -> V_136 << V_137 ) |
V_138 , V_140 ) ;
F_16 ( V_37 , V_103 -> V_22 , V_78 ) ;
if ( V_103 -> V_141 == V_142 )
F_16 ( V_37 , V_143 ,
V_76 ) ;
}
static void
F_36 ( struct V_36 * V_37 ,
struct V_144 * V_145 )
{
T_1 V_41 ;
if ( ! V_145 -> V_84 ) {
V_41 = ( V_145 -> V_146 ) & V_147 ;
F_16 ( V_37 , V_41 , V_73 ) ;
F_16 ( V_37 , V_148 , V_72 ) ;
return;
}
V_41 = ( ( V_145 -> V_149 & V_150 ) |
( ( V_145 -> V_151 & V_152 ) <<
V_153 ) |
( ( V_145 -> V_154 & V_155 ) <<
V_156 ) |
( ( V_145 -> V_157 & V_158 ) <<
V_159 ) | V_160 ) ;
F_16 ( V_37 , V_41 , V_72 ) ;
F_16 ( V_37 , V_161 , V_73 ) ;
}
static void
F_37 ( struct V_36 * V_37 ,
struct V_162 * V_163 )
{
T_1 V_41 ;
V_41 = ( ( V_163 -> V_164 & V_165 ) |
( ( V_163 -> V_166 & V_165 ) <<
V_167 ) |
( ( V_163 -> V_168 & V_165 ) <<
V_169 ) |
( ( V_163 -> V_170 & V_165 ) <<
V_171 ) ) ;
F_16 ( V_37 , V_41 , V_74 ) ;
}
static void F_38 ( struct V_36 * V_37 )
{
struct V_8 * V_9 = F_19 ( V_37 , struct V_8 , V_37 ) ;
struct V_79 * V_91 =
& V_37 -> V_39 . V_92 . V_91 ;
struct V_172 * V_103 = & V_37 -> V_39 . V_92 ;
unsigned int V_110 ;
unsigned int V_41 ;
F_10 ( 3 , V_9 , L_17 ) ;
F_29 ( V_37 ) ;
F_16 ( V_37 , V_138 , V_140 ) ;
V_110 = ( ( ( V_103 -> V_131 & V_132 ) << V_133 ) |
( ( V_103 -> V_128 & V_129 ) << V_130 ) |
( ( V_103 -> V_125 & V_126 ) <<
V_127 ) | ( ( V_103 -> V_54 &
V_173 ) << V_174 ) |
( ( V_91 -> V_86 & V_175 ) <<
V_176 ) | ( ( V_103 -> V_26 &
V_177 ) << V_178 ) |
V_116 | V_115 ) ;
if ( V_91 -> V_83 . V_84 ) {
V_41 = ( ( V_91 -> V_83 . V_85 &
V_179 ) | V_180 ) ;
F_16 ( V_37 , V_41 , V_71 ) ;
F_10 ( 3 , V_9 , L_18 , V_41 ) ;
}
F_23 ( V_37 , & V_103 -> V_134 , V_103 -> V_54 ,
V_103 -> V_135 ) ;
F_36 ( V_37 , & V_91 -> V_181 ) ;
F_37 ( V_37 , & V_91 -> V_182 ) ;
if ( ( V_91 -> V_86 == V_183 ) ||
V_91 -> V_83 . V_84 )
V_110 |= V_117 ;
F_16 ( V_37 , V_103 -> V_22 , V_78 ) ;
F_10 ( 3 , V_9 , L_19 ,
V_103 -> V_22 , V_103 -> V_22 ) ;
if ( V_103 -> V_54 == V_64 ) {
if ( V_103 -> V_184 ) {
F_16 ( V_37 , V_185 ,
V_76 ) ;
} else {
F_16 ( V_37 , V_186 ,
V_76 ) ;
}
} else if ( V_103 -> V_54 == V_187 ) {
F_16 ( V_37 , V_188 ,
V_76 ) ;
}
F_16 ( V_37 , V_110 , V_77 ) ;
F_24 ( V_37 ) ;
}
static inline int
F_39 ( struct V_36 * V_37 ,
enum V_189 V_141 )
{
if ( V_37 -> V_39 . V_105 == V_106 )
V_37 -> V_39 . V_92 . V_141 = V_141 ;
else
V_37 -> V_39 . V_109 . V_141 = V_141 ;
return 0 ;
}
static inline enum V_189 F_40 ( struct V_36 * V_37 )
{
if ( V_37 -> V_39 . V_105 == V_106 )
return V_37 -> V_39 . V_92 . V_141 ;
return V_37 -> V_39 . V_109 . V_141 ;
}
static int F_41 ( struct V_36 * V_37 , T_1 V_190 )
{
struct V_8 * V_9 = F_19 ( V_37 , struct V_8 , V_37 ) ;
F_10 ( 1 , V_9 , L_20 ,
V_37 -> V_39 . V_105 , F_12 ( V_190 ) ) ;
if ( V_37 -> V_39 . V_105 == V_106 ) {
V_37 -> V_39 . V_92 . V_26 = V_191 ;
V_37 -> V_39 . V_92 . V_91 . V_83 . V_84 = 0 ;
switch ( V_190 ) {
case V_192 :
V_37 -> V_39 . V_92 . V_91 . V_83 . V_84 = 1 ;
break;
case V_193 :
case V_194 :
case V_195 :
case V_196 :
case V_197 :
break;
case V_198 :
default:
return - V_89 ;
}
} else {
switch ( V_190 ) {
case V_193 :
V_37 -> V_39 . V_109 . V_136 = V_199 ;
break;
case V_194 :
V_37 -> V_39 . V_109 . V_136 = V_200 ;
break;
default:
return - V_89 ;
}
}
return 0 ;
}
static T_1 F_42 ( struct V_36 * V_37 )
{
T_1 V_190 ;
if ( V_37 -> V_39 . V_105 == V_106 ) {
V_190 = V_193 ;
} else {
if ( V_37 -> V_39 . V_109 . V_136 == V_199 )
V_190 = V_193 ;
else
V_190 = V_194 ;
}
return V_190 ;
}
static int
F_43 ( struct V_36 * V_37 ,
struct V_51 * V_134 , unsigned int V_14 )
{
if ( V_37 -> V_39 . V_105 == V_106 ) {
V_37 -> V_39 . V_92 . V_134 = * V_134 ;
V_37 -> V_39 . V_92 . V_135 = V_14 ;
V_37 -> V_39 . V_92 . V_22 = F_8 ( V_134 -> V_23 * V_14 , 32 ) ;
} else {
V_37 -> V_39 . V_109 . V_134 = * V_134 ;
V_37 -> V_39 . V_109 . V_135 = V_14 ;
V_37 -> V_39 . V_109 . V_22 = F_8 ( V_134 -> V_23 * V_14 , 32 ) ;
}
return 0 ;
}
static inline void
F_44 ( struct V_36 * V_37 ,
struct V_51 * V_134 )
{
if ( V_37 -> V_39 . V_105 == V_106 )
* V_134 = V_37 -> V_39 . V_92 . V_134 ;
else
* V_134 = V_37 -> V_39 . V_109 . V_134 ;
}
static inline unsigned int F_45 ( struct V_36 * V_37 )
{
if ( V_37 -> V_39 . V_105 == V_106 )
return V_37 -> V_39 . V_92 . V_22 ;
return V_37 -> V_39 . V_109 . V_22 ;
}
static inline int
F_46 ( struct V_36 * V_37 ,
enum V_53 V_54 )
{
if ( V_37 -> V_39 . V_105 == V_106 )
V_37 -> V_39 . V_92 . V_54 = V_54 ;
else
V_37 -> V_39 . V_109 . V_54 = V_54 ;
return 0 ;
}
static inline enum V_53
F_47 ( struct V_36 * V_37 )
{
if ( V_37 -> V_39 . V_105 == V_106 )
return V_37 -> V_39 . V_92 . V_54 ;
return V_37 -> V_39 . V_109 . V_54 ;
}
static inline int F_48 ( struct V_36 * V_37 )
{
return ( F_14 ( V_37 , V_77 ) >> 15 ) & 1 ;
}
static inline void F_49 ( struct V_36 * V_37 , unsigned long V_201 )
{
F_16 ( V_37 , V_201 & 0xffffffe0 , V_202 ) ;
}
static int F_50 ( struct V_36 * V_37 ,
struct V_203 * V_103 )
{
struct V_8 * V_9 = F_19 ( V_37 , struct V_8 , V_37 ) ;
V_37 -> V_39 . V_105 = V_103 -> V_105 ;
switch ( V_103 -> V_105 ) {
case V_204 :
case V_205 :
case V_206 :
case V_122 :
V_37 -> V_39 . V_109 . V_131 = V_103 -> V_207 ;
V_37 -> V_39 . V_109 . V_128 = V_103 -> V_208 ;
break;
case V_106 :
V_37 -> V_39 . V_92 . V_131 = V_103 -> V_207 ;
V_37 -> V_39 . V_92 . V_128 = V_103 -> V_208 ;
if ( V_103 -> V_18 == 10 )
V_37 -> V_39 . V_92 . V_91 . V_86 =
V_209 ;
else
V_37 -> V_39 . V_92 . V_91 . V_86 =
V_183 ;
F_10 ( 1 , V_9 , L_21 ,
V_103 -> V_18 ) ;
F_10 ( 1 , V_9 , L_22 ,
V_37 -> V_39 . V_92 . V_91 . V_86 ) ;
break;
default:
return - V_89 ;
}
return 0 ;
}
static void F_51 ( struct V_36 * V_37 , int V_210 )
{
unsigned int V_211 ;
V_211 = F_14 ( V_37 , V_212 ) ;
switch ( V_210 ) {
case V_213 :
V_211 &= ~ V_213 ;
V_211 |= V_213 ;
break;
case V_214 :
V_211 &= ~ V_214 ;
V_211 |= V_214 ;
break;
case V_215 :
V_211 &= ~ V_215 ;
V_211 |= V_215 ;
break;
default:
V_211 &= ~ ( V_213 |
V_214 |
V_215 ) ;
V_211 |= ( V_213 |
V_214 |
V_215 ) ;
break;
}
F_16 ( V_37 , V_211 , V_212 ) ;
V_211 = F_14 ( V_37 , V_212 ) ;
F_16 ( V_37 , 1 , V_216 ) ;
}
static void F_52 ( struct V_36 * V_37 )
{
V_37 -> V_39 . V_105 = V_106 ;
V_37 -> V_39 . V_109 . V_26 = V_217 ;
V_37 -> V_39 . V_109 . V_54 = V_64 ;
V_37 -> V_39 . V_109 . V_125 = V_218 ;
V_37 -> V_39 . V_109 . V_131 = V_218 ;
V_37 -> V_39 . V_109 . V_128 = V_218 ;
V_37 -> V_39 . V_109 . V_136 = V_200 ;
V_37 -> V_39 . V_109 . V_141 = V_142 ;
V_37 -> V_39 . V_109 . V_134 . V_60 = 0 ;
V_37 -> V_39 . V_109 . V_134 . V_63 = 0 ;
V_37 -> V_39 . V_109 . V_134 . V_23 = 720 ;
V_37 -> V_39 . V_109 . V_134 . V_25 = 576 ;
V_37 -> V_39 . V_109 . V_118 = 1 ;
V_37 -> V_39 . V_92 . V_26 = V_191 ;
V_37 -> V_39 . V_92 . V_54 = V_187 ;
V_37 -> V_39 . V_92 . V_125 = V_218 ;
V_37 -> V_39 . V_92 . V_131 = V_218 ;
V_37 -> V_39 . V_92 . V_128 = V_218 ;
V_37 -> V_39 . V_92 . V_134 . V_60 = 0 ;
V_37 -> V_39 . V_92 . V_134 . V_63 = 0 ;
V_37 -> V_39 . V_92 . V_134 . V_23 = 800 ;
V_37 -> V_39 . V_92 . V_134 . V_25 = 600 ;
V_37 -> V_39 . V_92 . V_91 . V_86 = V_183 ;
V_37 -> V_39 . V_92 . V_91 . V_83 . V_85 =
V_87 ;
}
static int F_53 ( struct V_8 * V_9 ,
struct V_28 * V_219 )
{
struct V_51 V_52 ;
enum V_189 V_141 ;
enum V_53 V_54 ;
memset ( V_219 , 0 , sizeof( * V_219 ) ) ;
V_219 -> type = V_220 ;
F_44 ( & V_9 -> V_37 , & V_52 ) ;
V_219 -> V_3 . V_13 . V_23 = V_52 . V_23 ;
V_219 -> V_3 . V_13 . V_25 = V_52 . V_25 ;
V_219 -> V_3 . V_13 . V_22 = F_45 ( & V_9 -> V_37 ) ;
V_219 -> V_3 . V_13 . V_24 = V_219 -> V_3 . V_13 . V_22 *
V_219 -> V_3 . V_13 . V_25 ;
V_141 = F_40 ( & V_9 -> V_37 ) ;
V_219 -> V_3 . V_13 . V_6 = F_42 ( & V_9 -> V_37 ) ;
V_54 = F_47 ( & V_9 -> V_37 ) ;
if ( V_54 == V_187 ) {
V_219 -> V_3 . V_13 . V_31 = V_221 ;
} else if ( V_54 == V_64 ) {
if ( V_141 == V_142 ) {
V_219 -> V_3 . V_13 . V_31 = V_222 ;
} else if ( V_141 == V_223 ) {
V_219 -> V_3 . V_13 . V_31 = V_224 ;
} else {
F_54 ( V_9 , L_23 ) ;
return - V_89 ;
}
} else {
F_54 ( V_9 , L_24 ) ;
return - V_89 ;
}
return 0 ;
}
static int F_55 ( struct V_8 * V_9 )
{
enum V_53 V_54 = V_64 ;
int V_225 = 0 ;
F_10 ( 2 , V_9 , L_25 ) ;
F_10 ( 1 , V_9 , L_26 ,
F_12 ( V_9 -> V_3 . V_3 . V_13 . V_6 ) ) ;
if ( F_41 ( & V_9 -> V_37 ,
V_9 -> V_3 . V_3 . V_13 . V_6 ) < 0 ) {
F_54 ( V_9 , L_27 ) ;
return - V_89 ;
}
F_43 ( & V_9 -> V_37 , & V_9 -> V_226 , V_9 -> V_14 ) ;
switch ( V_9 -> V_3 . V_3 . V_13 . V_31 ) {
case V_222 :
V_225 = F_39 (
& V_9 -> V_37 ,
V_142 ) ;
break;
case V_221 :
V_54 = V_187 ;
break;
case V_224 :
V_225 = F_39 (
& V_9 -> V_37 ,
V_223 ) ;
break;
default:
return - V_89 ;
}
if ( V_225 )
return V_225 ;
return F_46 ( & V_9 -> V_37 , V_54 ) ;
}
static int F_56 ( struct V_8 * V_9 ,
T_4 V_227 )
{
struct V_12 * V_13 = & V_9 -> V_3 . V_3 . V_13 ;
int V_93 , V_225 ;
for ( V_93 = 0 ; V_93 < F_2 ( V_228 ) ; V_93 ++ ) {
if ( V_228 [ V_93 ] . V_227 & V_227 ) {
V_9 -> V_229 . V_230 =
V_228 [ V_93 ] . V_23 ;
V_9 -> V_229 . V_231 =
V_228 [ V_93 ] . V_25 ;
V_9 -> V_229 . V_232 =
V_228 [ V_93 ] . V_232 ;
V_9 -> V_233 = V_93 ;
break;
}
}
if ( V_93 == F_2 ( V_228 ) ) {
F_54 ( V_9 , L_28 ) ;
return - V_89 ;
}
V_9 -> V_226 . V_63 = V_9 -> V_226 . V_60 = 0 ;
V_9 -> V_226 . V_23 = V_9 -> V_229 . V_230 ;
V_9 -> V_226 . V_25 = V_9 -> V_229 . V_231 ;
V_13 -> V_23 = V_9 -> V_226 . V_23 ;
V_13 -> V_25 = V_9 -> V_226 . V_25 ;
V_13 -> V_6 = V_193 ;
if ( V_9 -> V_229 . V_232 )
V_13 -> V_31 = V_222 ;
else
V_13 -> V_31 = V_221 ;
V_225 = F_57 ( V_9 , & V_9 -> V_3 , & V_9 -> V_14 ) ;
if ( V_225 )
return V_225 ;
V_9 -> V_226 . V_23 = V_13 -> V_23 ;
V_9 -> V_226 . V_25 = V_13 -> V_25 ;
return F_55 ( V_9 ) ;
}
static int F_58 ( struct V_8 * V_9 )
{
struct V_15 * V_16 ;
int V_225 ;
V_16 = & V_9 -> V_47 -> V_234 [ 0 ] ;
V_16 -> V_235 = V_9 -> V_235 [ 0 ] ;
V_9 -> V_236 = 0 ;
V_9 -> V_233 = 0 ;
V_225 = F_56 ( V_9 ,
V_228 [ V_9 -> V_233 ] . V_227 ) ;
if ( V_225 )
return V_225 ;
F_59 ( V_9 -> V_237 ) ;
F_22 ( & V_9 -> V_37 , 1 ) ;
F_29 ( & V_9 -> V_37 ) ;
F_51 ( & V_9 -> V_37 , - 1 ) ;
return V_225 ;
}
static int F_60 ( struct V_238 * V_238 )
{
struct V_8 * V_9 = F_61 ( V_238 ) ;
bool V_239 ;
int V_225 ;
F_62 ( & V_9 -> V_240 ) ;
V_239 = F_63 ( V_238 ) ;
V_225 = F_64 ( V_238 , NULL ) ;
if ( V_239 )
F_30 ( & V_9 -> V_37 , V_9 -> V_237 ) ;
F_65 ( & V_9 -> V_240 ) ;
return V_225 ;
}
static int F_66 ( struct V_238 * V_238 )
{
struct V_8 * V_9 = F_61 ( V_238 ) ;
int V_225 ;
F_62 ( & V_9 -> V_240 ) ;
V_225 = F_67 ( V_238 ) ;
if ( V_225 ) {
F_54 ( V_9 , L_29 ) ;
goto V_241;
}
if ( ! F_63 ( V_238 ) )
goto V_241;
if ( F_58 ( V_9 ) ) {
F_68 ( V_238 ) ;
V_225 = - V_242 ;
}
V_241:
F_65 ( & V_9 -> V_240 ) ;
return V_225 ;
}
static inline void F_69 ( struct V_8 * V_9 )
{
V_9 -> V_243 = F_70 ( V_9 -> V_244 . V_245 ,
struct V_42 , V_246 ) ;
F_71 ( & V_9 -> V_243 -> V_246 ) ;
F_49 ( & V_9 -> V_37 ,
F_72 ( & V_9 -> V_243 -> V_44 . V_247 , 0 ) ) ;
}
static inline void F_73 ( struct V_8 * V_9 )
{
unsigned long V_201 ;
V_201 = F_72 ( & V_9 -> V_243 -> V_44 . V_247 , 0 ) +
V_9 -> V_248 ;
F_49 ( & V_9 -> V_37 , V_201 ) ;
}
static inline void F_74 ( struct V_8 * V_9 )
{
V_9 -> V_249 -> V_44 . V_247 . V_250 = F_75 () ;
V_9 -> V_249 -> V_44 . V_31 = V_9 -> V_3 . V_3 . V_13 . V_31 ;
V_9 -> V_249 -> V_44 . V_251 = V_9 -> V_251 ++ ;
F_76 ( & V_9 -> V_249 -> V_44 . V_247 , V_252 ) ;
V_9 -> V_249 = V_9 -> V_243 ;
}
static T_5 F_77 ( int V_253 , void * V_98 )
{
struct V_8 * V_9 = (struct V_8 * ) V_98 ;
enum V_254 V_31 ;
int V_255 ;
int V_256 ;
V_255 = F_14 ( & V_9 -> V_37 , V_212 ) ;
if ( V_255 & V_213 ) {
V_31 = V_9 -> V_3 . V_3 . V_13 . V_31 ;
if ( V_31 == V_221 ) {
if ( V_9 -> V_249 != V_9 -> V_243 )
F_74 ( V_9 ) ;
goto V_257;
}
V_256 = F_48 ( & V_9 -> V_37 ) ;
V_9 -> V_31 ^= 1 ;
if ( V_256 == V_9 -> V_31 ) {
if ( V_256 == 0 ) {
if ( V_9 -> V_249 != V_9 -> V_243 )
F_74 ( V_9 ) ;
if ( V_31 == V_224 )
F_73 ( V_9 ) ;
goto V_257;
}
F_78 ( & V_9 -> V_258 ) ;
if ( ! F_79 ( & V_9 -> V_244 ) &&
V_9 -> V_249 == V_9 -> V_243 )
F_69 ( V_9 ) ;
F_80 ( & V_9 -> V_258 ) ;
} else if ( V_256 == 0 ) {
V_9 -> V_31 = V_256 ;
}
}
V_257:
if ( V_255 & V_214 ) {
F_78 ( & V_9 -> V_258 ) ;
if ( V_9 -> V_3 . V_3 . V_13 . V_31 == V_221 &&
! F_79 ( & V_9 -> V_244 ) &&
V_9 -> V_249 == V_9 -> V_243 )
F_69 ( V_9 ) ;
F_80 ( & V_9 -> V_258 ) ;
}
F_51 ( & V_9 -> V_37 , V_255 ) ;
return V_259 ;
}
static inline void F_81 ( struct V_8 * V_9 )
{
unsigned int V_260 = V_213 ;
enum V_53 V_232 ;
V_232 = F_47 ( & V_9 -> V_37 ) ;
if ( V_232 == V_187 )
V_260 |= V_214 ;
F_16 ( & V_9 -> V_37 , V_260 , V_261 ) ;
}
static inline void F_82 ( struct V_8 * V_9 )
{
unsigned int V_260 = V_213 ;
enum V_53 V_232 ;
V_232 = F_47 ( & V_9 -> V_37 ) ;
if ( V_232 == V_187 )
V_260 |= V_214 ;
F_16 ( & V_9 -> V_37 , V_260 , V_262 ) ;
}
static int F_83 ( struct V_238 * V_238 , void * V_263 ,
struct V_264 * V_265 )
{
struct V_8 * V_9 = F_61 ( V_238 ) ;
F_10 ( 2 , V_9 , L_30 ) ;
F_84 ( V_265 -> V_266 , V_267 , sizeof( V_265 -> V_266 ) ) ;
F_84 ( V_265 -> V_268 , L_31 , sizeof( V_265 -> V_268 ) ) ;
snprintf ( V_265 -> V_269 , sizeof( V_265 -> V_269 ) ,
L_32 , V_9 -> V_270 . V_271 ) ;
V_265 -> V_272 = V_273 | V_274 |
V_275 ;
V_265 -> V_276 = V_265 -> V_272 | V_277 ;
return 0 ;
}
static int F_57 ( struct V_8 * V_9 ,
struct V_28 * V_278 , unsigned int * V_14 )
{
struct V_10 V_27 ;
struct V_15 * V_16 ;
struct V_279 V_3 ;
int V_225 ;
V_16 = V_9 -> V_17 ;
if ( ! V_16 -> V_235 )
return - V_89 ;
V_3 . V_280 = V_281 ;
V_3 . V_282 = 0 ;
V_225 = F_85 ( V_16 -> V_235 , V_282 , V_283 , NULL , & V_3 ) ;
if ( V_225 && V_225 != - V_284 && V_225 != - V_242 )
return V_225 ;
if ( ! V_225 ) {
F_7 ( & V_278 -> V_3 . V_13 , & V_3 . V_278 ) ;
F_4 ( V_9 , & V_3 . V_278 , & V_278 -> V_3 . V_13 , V_14 ) ;
} else {
V_225 = F_86 ( & V_9 -> V_270 ,
V_16 -> V_285 ,
V_282 , V_283 ,
NULL , & V_3 ) ;
if ( V_225 && V_225 != - V_284 && V_225 != - V_242 )
return V_225 ;
F_7 ( & V_278 -> V_3 . V_13 , & V_27 ) ;
F_4 ( V_9 , & V_27 , & V_278 -> V_3 . V_13 , V_14 ) ;
}
V_278 -> type = V_9 -> V_3 . type ;
F_10 ( 1 , V_9 ,
L_33 ,
V_286 , V_278 -> V_3 . V_13 . V_23 , V_278 -> V_3 . V_13 . V_25 ,
F_12 ( V_278 -> V_3 . V_13 . V_6 ) ,
V_278 -> V_3 . V_13 . V_22 , V_278 -> V_3 . V_13 . V_24 , * V_14 ) ;
return 0 ;
}
static int F_87 ( struct V_8 * V_9 ,
struct V_28 * V_278 , unsigned int * V_14 )
{
struct V_15 * V_16 ;
struct V_279 V_3 ;
int V_225 ;
F_10 ( 2 , V_9 , L_34 ) ;
V_16 = V_9 -> V_17 ;
if ( ! V_16 -> V_235 )
return - V_89 ;
V_3 . V_280 = V_281 ;
V_3 . V_282 = 0 ;
F_9 ( V_9 , & V_278 -> V_3 . V_13 , & V_3 . V_278 ) ;
V_225 = F_85 ( V_16 -> V_235 , V_282 , V_287 , NULL , & V_3 ) ;
if ( V_225 )
return V_225 ;
F_7 ( & V_278 -> V_3 . V_13 , & V_3 . V_278 ) ;
F_4 ( V_9 , & V_3 . V_278 , & V_278 -> V_3 . V_13 , V_14 ) ;
V_278 -> type = V_9 -> V_3 . type ;
F_10 ( 1 , V_9 ,
L_33 ,
V_286 , V_278 -> V_3 . V_13 . V_23 , V_278 -> V_3 . V_13 . V_25 ,
F_12 ( V_278 -> V_3 . V_13 . V_6 ) ,
V_278 -> V_3 . V_13 . V_22 , V_278 -> V_3 . V_13 . V_24 , * V_14 ) ;
return 0 ;
}
static int F_88 ( struct V_238 * V_238 , void * V_263 ,
struct V_28 * V_3 )
{
struct V_8 * V_9 = F_61 ( V_238 ) ;
F_10 ( 2 , V_9 , L_35 ) ;
* V_3 = V_9 -> V_3 ;
return 0 ;
}
static int F_89 ( struct V_238 * V_238 , void * V_263 ,
struct V_288 * V_219 )
{
struct V_8 * V_9 = F_61 ( V_238 ) ;
struct V_15 * V_16 ;
struct V_1 * V_3 = NULL ;
unsigned int V_4 ;
F_10 ( 2 , V_9 , L_36 ,
V_219 -> V_289 ) ;
V_16 = V_9 -> V_17 ;
if ( ! V_16 -> V_235 )
return - V_89 ;
if ( V_219 -> V_289 > F_2 ( V_5 ) )
return - V_89 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; V_4 ++ ) {
if ( V_5 [ V_4 ] . V_289 == V_219 -> V_289 ) {
V_3 = & V_5 [ V_4 ] ;
break;
}
}
if ( ! V_3 )
return - V_89 ;
strncpy ( V_219 -> V_290 , V_3 -> V_271 , sizeof( V_219 -> V_290 ) - 1 ) ;
V_219 -> V_6 = V_3 -> V_7 ;
V_219 -> type = V_9 -> V_3 . type ;
F_10 ( 1 , V_9 , L_37 ,
V_219 -> V_289 , V_3 -> V_2 , F_12 ( V_3 -> V_7 ) , V_3 -> V_271 ) ;
return 0 ;
}
static int F_90 ( struct V_238 * V_238 , void * V_263 ,
struct V_28 * V_3 )
{
struct V_8 * V_9 = F_61 ( V_238 ) ;
unsigned int V_14 ;
F_10 ( 2 , V_9 , L_38 ) ;
return F_57 ( V_9 , V_3 , & V_14 ) ;
}
static int F_91 ( struct V_238 * V_238 , void * V_263 ,
struct V_28 * V_3 )
{
struct V_8 * V_9 = F_61 ( V_238 ) ;
struct V_28 V_278 ;
unsigned int V_14 ;
int V_225 ;
F_10 ( 2 , V_9 , L_39 ) ;
if ( F_92 ( & V_9 -> V_291 ) ) {
F_54 ( V_9 , L_40 , V_286 ) ;
return - V_292 ;
}
V_225 = F_90 ( V_238 , V_263 , & V_278 ) ;
if ( V_225 )
return V_225 ;
if ( ! F_13 ( V_3 , & V_278 ) ) {
V_225 = F_87 ( V_9 , V_3 , & V_14 ) ;
if ( V_225 )
return V_225 ;
} else
* V_3 = V_278 ;
F_81 ( V_9 ) ;
V_9 -> V_3 = * V_3 ;
V_9 -> V_14 = V_14 ;
V_9 -> V_226 . V_23 = V_3 -> V_3 . V_13 . V_23 ;
V_9 -> V_226 . V_25 = V_3 -> V_3 . V_13 . V_25 ;
return F_55 ( V_9 ) ;
}
static int F_93 ( struct V_238 * V_238 , void * V_263 ,
struct V_293 * V_294 )
{
struct V_8 * V_9 = F_61 ( V_238 ) ;
struct V_295 V_296 ;
struct V_15 * V_16 ;
struct V_10 V_11 ;
struct V_12 V_13 ;
struct V_1 * V_3 ;
int V_225 ;
F_10 ( 2 , V_9 , L_41 ) ;
V_3 = F_3 ( V_294 -> V_297 ) ;
if ( ! V_3 ) {
F_10 ( 3 , V_9 , L_2 ,
V_294 -> V_297 ) ;
return - V_89 ;
}
memset ( V_294 -> V_298 , 0x0 , sizeof( V_294 -> V_298 ) ) ;
V_16 = V_9 -> V_17 ;
if ( ! V_16 -> V_235 )
return - V_89 ;
memset ( & V_13 , 0x0 , sizeof( V_13 ) ) ;
V_13 . V_6 = V_294 -> V_297 ;
V_13 . V_23 = 640 ;
V_13 . V_25 = 480 ;
V_13 . V_32 = V_299 ;
V_13 . V_31 = V_221 ;
F_9 ( V_9 , & V_13 , & V_11 ) ;
memset ( & V_296 , 0x0 , sizeof( V_296 ) ) ;
V_296 . V_289 = V_294 -> V_289 ;
V_296 . V_282 = 0 ;
V_296 . V_2 = V_11 . V_2 ;
V_296 . V_280 = V_281 ;
V_225 = F_85 ( V_16 -> V_235 , V_282 , V_300 , NULL , & V_296 ) ;
if ( V_225 )
return - V_89 ;
F_10 ( 1 , V_9 , L_42 ,
V_296 . V_289 , V_296 . V_2 , V_296 . V_301 , V_296 . V_302 ,
V_296 . V_303 , V_296 . V_304 ) ;
V_294 -> type = V_305 ;
V_294 -> V_306 . V_23 = V_296 . V_302 ;
V_294 -> V_306 . V_25 = V_296 . V_304 ;
F_10 ( 1 , V_9 , L_43 ,
V_294 -> V_289 , F_12 ( V_294 -> V_297 ) ,
V_294 -> V_306 . V_23 , V_294 -> V_306 . V_25 ) ;
return 0 ;
}
static int
F_94 ( struct V_8 * V_9 ,
int * V_307 ,
int * V_308 ,
int V_309 )
{
int V_93 , V_310 = 0 ;
for ( V_93 = 0 ; V_93 < F_2 ( V_9 -> V_47 -> V_311 ) ; V_93 ++ ) {
if ( V_309 < ( V_310 + 1 ) ) {
* V_307 = V_93 ;
* V_308 = V_309 - V_310 ;
return 0 ;
}
V_310 ++ ;
}
return - V_89 ;
}
static int F_95 ( struct V_8 * V_9 ,
int * V_309 )
{
struct V_312 * V_47 = V_9 -> V_47 ;
struct V_15 * V_16 ;
struct V_313 * V_314 ;
struct V_313 * V_315 ;
int V_93 , V_310 = 0 ;
V_315 = F_96 ( V_9 -> V_17 -> V_235 ) ;
for ( V_93 = 0 ; V_93 < F_2 ( V_9 -> V_47 -> V_311 ) ; V_93 ++ ) {
V_16 = & V_47 -> V_234 [ V_93 ] ;
V_314 = F_96 ( V_16 -> V_235 ) ;
if ( V_314 -> V_201 == V_315 -> V_201 &&
V_314 -> V_316 -> V_317 == V_315 -> V_316 -> V_317 ) {
if ( V_9 -> V_236 >= 1 )
return - 1 ;
* V_309 = V_310 + V_9 -> V_236 ;
return 0 ;
}
V_310 ++ ;
}
return - V_89 ;
}
static int F_97 ( struct V_238 * V_238 , void * V_263 ,
struct V_318 * V_319 )
{
struct V_8 * V_9 = F_61 ( V_238 ) ;
struct V_15 * V_16 ;
int V_320 , V_289 ;
F_10 ( 2 , V_9 , L_44 ) ;
if ( F_94 ( V_9 , & V_320 , & V_289 ,
V_319 -> V_289 ) < 0 ) {
F_10 ( 1 , V_9 ,
L_45 ) ;
return - V_89 ;
}
V_16 = & V_9 -> V_47 -> V_234 [ V_320 ] ;
* V_319 = V_16 -> V_321 [ V_289 ] ;
return 0 ;
}
static int F_98 ( struct V_238 * V_238 , void * V_263 , unsigned int * V_289 )
{
struct V_8 * V_9 = F_61 ( V_238 ) ;
F_10 ( 2 , V_9 , L_46 ) ;
return F_95 ( V_9 , V_289 ) ;
}
static int F_99 ( struct V_8 * V_9 , unsigned int V_289 )
{
int V_307 = 0 , V_322 = 0 ;
struct V_15 * V_16 ;
struct V_323 * V_324 ;
T_1 V_325 , V_326 ;
int V_225 ;
F_10 ( 2 , V_9 , L_47 , V_289 ) ;
if ( F_92 ( & V_9 -> V_291 ) ) {
F_54 ( V_9 , L_40 , V_286 ) ;
return - V_292 ;
}
V_225 = F_94 ( V_9 ,
& V_307 ,
& V_322 ,
V_289 ) ;
if ( V_225 < 0 ) {
F_54 ( V_9 , L_48 , V_289 ) ;
goto V_327;
}
V_16 = & V_9 -> V_47 -> V_234 [ V_307 ] ;
V_16 -> V_235 = V_9 -> V_235 [ V_307 ] ;
V_324 = & V_16 -> V_328 [ V_322 ] ;
if ( V_324 && V_16 -> V_329 ) {
V_325 = V_324 -> V_325 ;
V_326 = V_324 -> V_326 ;
if ( V_16 -> V_235 ) {
V_225 = F_85 ( V_16 -> V_235 , V_330 ,
V_331 , V_325 , V_326 , 0 ) ;
if ( V_225 ) {
F_54 ( V_9 , L_49 ) ;
V_225 = - V_89 ;
goto V_327;
}
}
}
V_9 -> V_17 = V_16 ;
if ( V_16 -> V_235 )
V_9 -> V_270 . V_332 = V_16 -> V_235 -> V_332 ;
V_9 -> V_236 = V_289 ;
V_9 -> V_233 = 0 ;
V_225 = F_50 ( & V_9 -> V_37 , & V_16 -> V_19 ) ;
if ( V_225 )
return V_225 ;
return F_56 ( V_9 ,
V_228 [ V_9 -> V_233 ] . V_227 ) ;
V_327:
return V_225 ;
}
static int F_100 ( struct V_238 * V_238 , void * V_263 , unsigned int V_289 )
{
struct V_8 * V_9 = F_61 ( V_238 ) ;
F_10 ( 2 , V_9 ,
L_50 , V_289 ) ;
return F_99 ( V_9 , V_289 ) ;
}
static int F_101 ( struct V_238 * V_238 , void * V_263 , T_4 * V_227 )
{
struct V_8 * V_9 = F_61 ( V_238 ) ;
struct V_15 * V_16 ;
F_10 ( 2 , V_9 , L_51 ) ;
V_16 = V_9 -> V_17 ;
if ( ! ( V_16 -> V_321 [ 0 ] . V_276 & V_333 ) )
return - V_334 ;
return F_86 ( & V_9 -> V_270 , V_16 -> V_285 ,
V_330 , V_335 , V_227 ) ;
}
static int F_102 ( struct V_238 * V_238 , void * V_263 , T_4 V_227 )
{
struct V_8 * V_9 = F_61 ( V_238 ) ;
struct V_15 * V_16 ;
int V_225 ;
F_10 ( 2 , V_9 , L_52 ) ;
V_16 = V_9 -> V_17 ;
if ( ! ( V_16 -> V_321 [ 0 ] . V_276 & V_333 ) )
return - V_334 ;
if ( F_92 ( & V_9 -> V_291 ) ) {
F_54 ( V_9 , L_40 , V_286 ) ;
V_225 = - V_292 ;
return V_225 ;
}
V_225 = F_86 ( & V_9 -> V_270 , V_16 -> V_285 ,
V_330 , V_336 , V_227 ) ;
if ( V_225 < 0 ) {
F_54 ( V_9 , L_53 ) ;
return V_225 ;
}
V_225 = F_56 ( V_9 , V_227 ) ;
return V_225 ;
}
static int F_103 ( struct V_238 * V_238 , void * V_263 , T_4 * V_227 )
{
struct V_8 * V_9 = F_61 ( V_238 ) ;
struct V_15 * V_16 ;
F_10 ( 2 , V_9 , L_54 ) ;
V_16 = V_9 -> V_17 ;
if ( V_16 -> V_321 [ 0 ] . V_276 != V_333 )
return - V_334 ;
* V_227 = V_228 [ V_9 -> V_233 ] . V_227 ;
return 0 ;
}
static void F_104 ( struct V_8 * V_9 )
{
struct V_51 V_52 ;
F_10 ( 2 , V_9 , L_55 ) ;
F_44 ( & V_9 -> V_37 , & V_52 ) ;
V_9 -> V_248 = V_52 . V_25 * V_52 . V_23 ;
}
static int F_105 ( struct V_337 * V_338 ,
unsigned int * V_339 , unsigned int * V_340 ,
unsigned int V_341 [] , struct V_97 * V_342 [] )
{
struct V_8 * V_9 = F_106 ( V_338 ) ;
unsigned V_343 = V_9 -> V_3 . V_3 . V_13 . V_24 ;
if ( V_338 -> V_344 + * V_339 < 3 )
* V_339 = 3 - V_338 -> V_344 ;
if ( * V_340 ) {
if ( V_341 [ 0 ] < V_343 )
return - V_89 ;
V_343 = V_341 [ 0 ] ;
}
* V_340 = 1 ;
V_341 [ 0 ] = V_343 ;
F_10 ( 1 , V_9 ,
L_56 , * V_339 , V_341 [ 0 ] ) ;
F_104 ( V_9 ) ;
return 0 ;
}
static int F_107 ( struct V_345 * V_44 )
{
struct V_43 * V_346 = F_108 ( V_44 ) ;
struct V_8 * V_9 = F_106 ( V_44 -> V_337 ) ;
F_109 ( V_44 , 0 , V_9 -> V_3 . V_3 . V_13 . V_24 ) ;
if ( F_110 ( V_44 , 0 ) > F_111 ( V_44 , 0 ) )
return - V_89 ;
V_346 -> V_31 = V_9 -> V_3 . V_3 . V_13 . V_31 ;
return 0 ;
}
static void F_112 ( struct V_345 * V_44 )
{
struct V_43 * V_346 = F_108 ( V_44 ) ;
struct V_8 * V_9 = F_106 ( V_44 -> V_337 ) ;
struct V_42 * V_347 = F_20 ( V_346 ) ;
unsigned long V_348 = 0 ;
F_113 ( & V_9 -> V_258 , V_348 ) ;
F_114 ( & V_347 -> V_246 , & V_9 -> V_244 ) ;
F_115 ( & V_9 -> V_258 , V_348 ) ;
}
static int F_116 ( struct V_337 * V_338 , unsigned int V_349 )
{
struct V_8 * V_9 = F_106 ( V_338 ) ;
struct V_42 * V_347 , * V_350 ;
struct V_15 * V_16 ;
unsigned long V_348 ;
unsigned long V_201 ;
int V_225 ;
F_113 ( & V_9 -> V_258 , V_348 ) ;
V_9 -> V_31 = 0 ;
V_9 -> V_251 = 0 ;
V_16 = V_9 -> V_17 ;
F_82 ( V_9 ) ;
if ( V_9 -> V_37 . V_39 . V_105 == V_106 )
F_38 ( & V_9 -> V_37 ) ;
else
F_35 ( & V_9 -> V_37 ) ;
V_9 -> V_243 = F_70 ( V_9 -> V_244 . V_245 ,
struct V_42 , V_246 ) ;
V_9 -> V_249 = V_9 -> V_243 ;
F_71 ( & V_9 -> V_249 -> V_246 ) ;
F_115 ( & V_9 -> V_258 , V_348 ) ;
V_201 = F_72 ( & V_9 -> V_249 -> V_44 . V_247 , 0 ) ;
F_49 ( & V_9 -> V_37 , ( unsigned long ) ( V_201 ) ) ;
F_21 ( & V_9 -> V_37 , 1 ) ;
V_225 = F_85 ( V_16 -> V_235 , V_330 , V_351 , 1 ) ;
if ( V_225 < 0 ) {
F_54 ( V_9 , L_57 ) ;
goto V_352;
}
return 0 ;
V_352:
F_117 (buf, tmp, &vpfe->dma_queue, list) {
F_71 ( & V_347 -> V_246 ) ;
F_76 ( & V_347 -> V_44 . V_247 , V_353 ) ;
}
return V_225 ;
}
static void F_118 ( struct V_337 * V_338 )
{
struct V_8 * V_9 = F_106 ( V_338 ) ;
struct V_15 * V_16 ;
unsigned long V_348 ;
int V_225 ;
F_21 ( & V_9 -> V_37 , 0 ) ;
F_81 ( V_9 ) ;
V_16 = V_9 -> V_17 ;
V_225 = F_85 ( V_16 -> V_235 , V_330 , V_351 , 0 ) ;
if ( V_225 && V_225 != - V_284 && V_225 != - V_242 )
F_10 ( 1 , V_9 , L_58 ) ;
F_113 ( & V_9 -> V_258 , V_348 ) ;
if ( V_9 -> V_249 == V_9 -> V_243 ) {
F_76 ( & V_9 -> V_249 -> V_44 . V_247 ,
V_354 ) ;
} else {
if ( V_9 -> V_249 != NULL )
F_76 ( & V_9 -> V_249 -> V_44 . V_247 ,
V_354 ) ;
if ( V_9 -> V_243 != NULL )
F_76 ( & V_9 -> V_243 -> V_44 . V_247 ,
V_354 ) ;
}
while ( ! F_79 ( & V_9 -> V_244 ) ) {
V_9 -> V_243 = F_70 ( V_9 -> V_244 . V_245 ,
struct V_42 , V_246 ) ;
F_71 ( & V_9 -> V_243 -> V_246 ) ;
F_76 ( & V_9 -> V_243 -> V_44 . V_247 ,
V_354 ) ;
}
F_115 ( & V_9 -> V_258 , V_348 ) ;
}
static int F_119 ( struct V_238 * V_238 , void * V_263 ,
struct V_355 * V_226 )
{
struct V_8 * V_9 = F_61 ( V_238 ) ;
F_10 ( 2 , V_9 , L_59 ) ;
if ( V_9 -> V_233 >= F_2 ( V_228 ) )
return - V_89 ;
memset ( V_226 , 0 , sizeof( struct V_355 ) ) ;
V_226 -> type = V_220 ;
V_226 -> V_356 . V_23 = V_228 [ V_9 -> V_233 ] . V_23 ;
V_226 -> V_357 . V_23 = V_226 -> V_356 . V_23 ;
V_226 -> V_356 . V_25 = V_228 [ V_9 -> V_233 ] . V_25 ;
V_226 -> V_357 . V_25 = V_226 -> V_356 . V_25 ;
V_226 -> V_358 = V_228 [ V_9 -> V_233 ] . V_358 ;
return 0 ;
}
static int
F_120 ( struct V_238 * V_238 , void * V_359 , struct V_360 * V_21 )
{
struct V_8 * V_9 = F_61 ( V_238 ) ;
switch ( V_21 -> V_361 ) {
case V_362 :
case V_363 :
V_21 -> V_170 . V_60 = V_21 -> V_170 . V_63 = 0 ;
V_21 -> V_170 . V_23 = V_9 -> V_226 . V_23 ;
V_21 -> V_170 . V_25 = V_9 -> V_226 . V_25 ;
break;
case V_364 :
V_21 -> V_170 = V_9 -> V_226 ;
break;
default:
return - V_89 ;
}
return 0 ;
}
static int F_121 ( struct V_51 * V_365 , struct V_51 * V_164 )
{
if ( V_365 -> V_60 < V_164 -> V_60 || V_365 -> V_63 < V_164 -> V_63 )
return 0 ;
if ( V_365 -> V_60 + V_365 -> V_23 > V_164 -> V_60 + V_164 -> V_23 )
return 0 ;
if ( V_365 -> V_63 + V_365 -> V_25 > V_164 -> V_63 + V_164 -> V_25 )
return 0 ;
return 1 ;
}
static int
F_122 ( struct V_238 * V_238 , void * V_359 , struct V_360 * V_21 )
{
struct V_8 * V_9 = F_61 ( V_238 ) ;
struct V_51 V_366 = V_9 -> V_226 ;
struct V_51 V_170 = V_21 -> V_170 ;
if ( F_92 ( & V_9 -> V_291 ) ) {
F_54 ( V_9 , L_40 , V_286 ) ;
return - V_292 ;
}
if ( V_21 -> type != V_220 ||
V_21 -> V_361 != V_364 )
return - V_89 ;
F_123 ( & V_170 . V_23 , 0 , V_366 . V_23 , 0 ,
& V_170 . V_25 , 0 , V_366 . V_25 , 0 , 0 ) ;
V_170 . V_60 = F_124 (unsigned int, r.left, 0 , cr.width - r.width) ;
V_170 . V_63 = F_124 (unsigned int, r.top, 0 , cr.height - r.height) ;
if ( V_21 -> V_348 & V_367 && ! F_121 ( & V_170 , & V_21 -> V_170 ) )
return - V_368 ;
if ( V_21 -> V_348 & V_369 && ! F_121 ( & V_21 -> V_170 , & V_170 ) )
return - V_368 ;
V_21 -> V_170 = V_9 -> V_226 = V_170 ;
F_43 ( & V_9 -> V_37 , & V_170 , V_9 -> V_14 ) ;
V_9 -> V_3 . V_3 . V_13 . V_23 = V_170 . V_23 ;
V_9 -> V_3 . V_3 . V_13 . V_25 = V_170 . V_25 ;
V_9 -> V_3 . V_3 . V_13 . V_22 = F_45 ( & V_9 -> V_37 ) ;
V_9 -> V_3 . V_3 . V_13 . V_24 = V_9 -> V_3 . V_3 . V_13 . V_22 *
V_9 -> V_3 . V_3 . V_13 . V_25 ;
F_10 ( 1 , V_9 , L_60 ,
V_170 . V_60 , V_170 . V_63 , V_170 . V_23 , V_170 . V_25 , V_366 . V_23 , V_366 . V_25 ) ;
return 0 ;
}
static long F_125 ( struct V_238 * V_238 , void * V_263 ,
bool V_370 , unsigned int V_371 , void * V_372 )
{
struct V_8 * V_9 = F_61 ( V_238 ) ;
int V_225 ;
F_10 ( 2 , V_9 , L_61 ) ;
if ( ! V_370 ) {
F_54 ( V_9 , L_40 , V_286 ) ;
return - V_292 ;
}
if ( F_92 ( & V_9 -> V_291 ) ) {
F_54 ( V_9 , L_40 , V_286 ) ;
return - V_292 ;
}
switch ( V_371 ) {
case V_373 :
V_225 = F_33 ( & V_9 -> V_37 , ( void T_3 * ) V_372 ) ;
if ( V_225 ) {
F_10 ( 2 , V_9 ,
L_62 ) ;
return V_225 ;
}
V_225 = F_53 ( V_9 ,
& V_9 -> V_3 ) ;
if ( V_225 < 0 ) {
F_10 ( 2 , V_9 ,
L_63 ) ;
return V_225 ;
}
break;
default:
V_225 = - V_374 ;
break;
}
return V_225 ;
}
static int
F_126 ( struct V_375 * V_376 ,
struct V_377 * V_320 ,
struct V_378 * V_311 )
{
struct V_8 * V_9 = F_19 ( V_376 -> V_270 ,
struct V_8 , V_270 ) ;
struct V_379 V_380 ;
struct V_15 * V_16 ;
bool V_381 = false ;
int V_93 , V_310 ;
F_10 ( 1 , V_9 , L_64 ) ;
for ( V_93 = 0 ; V_93 < F_2 ( V_9 -> V_47 -> V_311 ) ; V_93 ++ ) {
if ( V_9 -> V_47 -> V_311 [ V_93 ] -> V_382 . V_383 . V_384 == V_311 [ V_93 ] . V_382 . V_383 . V_384 ) {
V_16 = & V_9 -> V_47 -> V_234 [ V_93 ] ;
V_9 -> V_235 [ V_93 ] = V_320 ;
V_9 -> V_235 [ V_93 ] -> V_285 = V_16 -> V_285 ;
V_381 = true ;
break;
}
}
if ( ! V_381 ) {
F_127 ( V_9 , L_65 , V_320 -> V_271 ) ;
return - V_89 ;
}
V_9 -> V_385 . V_386 |= V_16 -> V_321 [ 0 ] . V_387 ;
for ( V_310 = 0 , V_93 = 0 ; ; ++ V_310 ) {
struct V_1 * V_3 ;
int V_225 ;
memset ( & V_380 , 0 , sizeof( V_380 ) ) ;
V_380 . V_289 = V_310 ;
V_380 . V_280 = V_281 ;
V_225 = F_85 ( V_320 , V_282 , V_388 ,
NULL , & V_380 ) ;
if ( V_225 )
break;
V_3 = F_1 ( V_380 . V_2 ) ;
if ( ! V_3 )
continue;
V_3 -> V_389 = true ;
V_3 -> V_289 = V_93 ++ ;
}
return 0 ;
}
static int F_128 ( struct V_8 * V_9 )
{
struct V_390 * V_391 ;
struct V_337 * V_392 ;
int V_352 ;
F_129 ( & V_9 -> V_258 ) ;
F_130 ( & V_9 -> V_240 ) ;
V_9 -> V_3 . type = V_220 ;
V_9 -> V_17 = & V_9 -> V_47 -> V_234 [ 0 ] ;
V_9 -> V_270 . V_332 = V_9 -> V_235 [ 0 ] -> V_332 ;
V_352 = F_99 ( V_9 , 0 ) ;
if ( V_352 )
goto V_393;
V_392 = & V_9 -> V_291 ;
V_392 -> type = V_220 ;
V_392 -> V_394 = V_395 | V_396 | V_397 ;
V_392 -> V_398 = V_9 ;
V_392 -> V_399 = & V_400 ;
V_392 -> V_401 = & V_402 ;
V_392 -> V_403 = sizeof( struct V_42 ) ;
V_392 -> V_404 = V_405 ;
V_392 -> V_240 = & V_9 -> V_240 ;
V_392 -> V_406 = 1 ;
V_392 -> V_98 = V_9 -> V_237 ;
V_352 = F_131 ( V_392 ) ;
if ( V_352 ) {
F_54 ( V_9 , L_66 ) ;
goto V_393;
}
F_132 ( & V_9 -> V_244 ) ;
V_391 = & V_9 -> V_385 ;
F_84 ( V_391 -> V_271 , V_267 , sizeof( V_391 -> V_271 ) ) ;
V_391 -> V_407 = V_408 ;
V_391 -> V_409 = & V_410 ;
V_391 -> V_411 = & V_412 ;
V_391 -> V_270 = & V_9 -> V_270 ;
V_391 -> V_413 = V_414 ;
V_391 -> V_415 = V_392 ;
V_391 -> V_240 = & V_9 -> V_240 ;
F_133 ( V_391 , V_9 ) ;
V_352 = F_134 ( & V_9 -> V_385 , V_416 , - 1 ) ;
if ( V_352 ) {
F_54 ( V_9 ,
L_67 ) ;
goto V_393;
}
return 0 ;
V_393:
F_135 ( & V_9 -> V_270 ) ;
return V_352 ;
}
static int F_136 ( struct V_375 * V_376 )
{
struct V_8 * V_9 = F_19 ( V_376 -> V_270 ,
struct V_8 , V_270 ) ;
return F_128 ( V_9 ) ;
}
static struct V_312 *
F_137 ( struct V_417 * V_237 )
{
struct V_418 * V_419 = NULL ;
struct V_420 V_421 ;
struct V_15 * V_16 ;
struct V_312 * V_422 ;
unsigned int V_348 ;
unsigned int V_93 ;
int V_352 ;
F_138 ( & V_237 -> V_98 , L_68 ) ;
if ( ! F_139 ( V_423 ) || ! V_237 -> V_98 . V_424 )
return V_237 -> V_98 . V_425 ;
V_422 = F_140 ( & V_237 -> V_98 , sizeof( * V_422 ) , V_426 ) ;
if ( ! V_422 )
return NULL ;
for ( V_93 = 0 ; ; V_93 ++ ) {
struct V_418 * V_427 ;
V_419 = F_141 ( V_237 -> V_98 . V_424 ,
V_419 ) ;
if ( ! V_419 )
break;
V_16 = & V_422 -> V_234 [ V_93 ] ;
V_16 -> V_285 = 0 ;
V_16 -> V_321 [ 0 ] . V_289 = V_93 ;
strcpy ( V_16 -> V_321 [ 0 ] . V_271 , L_69 ) ;
V_16 -> V_321 [ 0 ] . type = V_428 ;
V_16 -> V_321 [ 0 ] . V_387 = V_429 ;
V_16 -> V_321 [ 0 ] . V_276 = V_333 ;
V_16 -> V_329 = 0 ;
V_16 -> V_328 = NULL ;
F_142 ( V_419 , L_70 ,
& V_16 -> V_19 . V_105 ) ;
if ( V_16 -> V_19 . V_105 < 0 ||
V_16 -> V_19 . V_105 > 4 ) {
V_16 -> V_19 . V_105 = V_106 ;
}
V_352 = F_143 ( V_419 , & V_421 ) ;
if ( V_352 ) {
F_144 ( & V_237 -> V_98 , L_71 ) ;
goto V_430;
}
V_16 -> V_19 . V_18 = V_421 . V_431 . V_432 . V_18 ;
if ( V_16 -> V_19 . V_18 < 8 ||
V_16 -> V_19 . V_18 > 16 ) {
F_144 ( & V_237 -> V_98 , L_72 ) ;
goto V_430;
}
V_348 = V_421 . V_431 . V_432 . V_348 ;
if ( V_348 & V_433 )
V_16 -> V_19 . V_208 = 1 ;
if ( V_348 & V_434 )
V_16 -> V_19 . V_207 = 1 ;
V_427 = F_145 ( V_419 ) ;
if ( ! V_427 ) {
F_144 ( & V_237 -> V_98 , L_73 ,
V_419 -> V_435 ) ;
goto V_430;
}
V_422 -> V_311 [ V_93 ] = F_140 ( & V_237 -> V_98 ,
sizeof( struct V_378 ) ,
V_426 ) ;
if ( ! V_422 -> V_311 [ V_93 ] ) {
F_146 ( V_427 ) ;
V_422 = NULL ;
goto V_430;
}
V_422 -> V_311 [ V_93 ] -> V_436 = V_437 ;
V_422 -> V_311 [ V_93 ] -> V_382 . V_383 . V_384 = V_427 ;
F_146 ( V_427 ) ;
}
F_146 ( V_419 ) ;
return V_422 ;
V_430:
F_146 ( V_419 ) ;
return NULL ;
}
static int F_147 ( struct V_417 * V_237 )
{
struct V_312 * V_438 = F_137 ( V_237 ) ;
struct V_8 * V_9 ;
struct V_36 * V_37 ;
struct V_439 * V_440 ;
int V_225 ;
if ( ! V_438 ) {
F_144 ( & V_237 -> V_98 , L_74 ) ;
return - V_89 ;
}
V_9 = F_140 ( & V_237 -> V_98 , sizeof( * V_9 ) , V_426 ) ;
if ( ! V_9 )
return - V_441 ;
V_9 -> V_237 = & V_237 -> V_98 ;
V_9 -> V_47 = V_438 ;
V_37 = & V_9 -> V_37 ;
V_440 = F_148 ( V_237 , V_442 , 0 ) ;
V_37 -> V_39 . V_40 = F_149 ( & V_237 -> V_98 , V_440 ) ;
if ( F_150 ( V_37 -> V_39 . V_40 ) )
return F_151 ( V_37 -> V_39 . V_40 ) ;
V_225 = F_152 ( V_237 , 0 ) ;
if ( V_225 <= 0 ) {
F_144 ( & V_237 -> V_98 , L_75 ) ;
return - V_242 ;
}
V_9 -> V_253 = V_225 ;
V_225 = F_153 ( V_9 -> V_237 , V_9 -> V_253 , F_77 , 0 ,
L_76 , V_9 ) ;
if ( V_225 ) {
F_144 ( & V_237 -> V_98 , L_77 ) ;
return - V_89 ;
}
V_225 = F_154 ( & V_237 -> V_98 , & V_9 -> V_270 ) ;
if ( V_225 ) {
F_54 ( V_9 ,
L_78 ) ;
return V_225 ;
}
F_155 ( V_237 , V_9 ) ;
F_156 ( & V_237 -> V_98 ) ;
F_59 ( & V_237 -> V_98 ) ;
F_52 ( V_37 ) ;
F_32 ( & V_237 -> V_98 ) ;
V_9 -> V_235 = F_140 ( & V_237 -> V_98 , sizeof( struct V_377 * ) *
F_2 ( V_9 -> V_47 -> V_311 ) , V_426 ) ;
if ( ! V_9 -> V_235 ) {
V_225 = - V_441 ;
goto V_443;
}
V_9 -> V_376 . V_444 = V_9 -> V_47 -> V_311 ;
V_9 -> V_376 . V_445 = F_2 ( V_9 -> V_47 -> V_311 ) ;
V_9 -> V_376 . V_446 = F_126 ;
V_9 -> V_376 . V_447 = F_136 ;
V_225 = F_157 ( & V_9 -> V_270 ,
& V_9 -> V_376 ) ;
if ( V_225 ) {
F_54 ( V_9 , L_79 ) ;
V_225 = - V_89 ;
goto V_443;
}
return 0 ;
V_443:
F_135 ( & V_9 -> V_270 ) ;
return V_225 ;
}
static int F_158 ( struct V_417 * V_237 )
{
struct V_8 * V_9 = F_159 ( V_237 ) ;
F_10 ( 2 , V_9 , L_80 ) ;
F_160 ( & V_237 -> V_98 ) ;
F_161 ( & V_9 -> V_376 ) ;
F_135 ( & V_9 -> V_270 ) ;
F_162 ( & V_9 -> V_385 ) ;
return 0 ;
}
static void F_163 ( struct V_36 * V_37 )
{
V_37 -> V_448 [ V_46 >> 2 ] = F_14 ( V_37 , V_46 ) ;
V_37 -> V_448 [ V_77 >> 2 ] = F_14 ( V_37 , V_77 ) ;
V_37 -> V_448 [ V_76 >> 2 ] = F_14 ( V_37 , V_76 ) ;
V_37 -> V_448 [ V_202 >> 2 ] = F_14 ( V_37 , V_202 ) ;
V_37 -> V_448 [ V_72 >> 2 ] = F_14 ( V_37 , V_72 ) ;
V_37 -> V_448 [ V_73 >> 2 ] = F_14 ( V_37 , V_73 ) ;
V_37 -> V_448 [ V_75 >> 2 ] = F_14 ( V_37 , V_75 ) ;
V_37 -> V_448 [ V_74 >> 2 ] = F_14 ( V_37 , V_74 ) ;
V_37 -> V_448 [ V_67 >> 2 ] = F_14 ( V_37 , V_67 ) ;
V_37 -> V_448 [ V_71 >> 2 ] = F_14 ( V_37 , V_71 ) ;
V_37 -> V_448 [ V_120 >> 2 ] = F_14 ( V_37 , V_120 ) ;
V_37 -> V_448 [ V_140 >> 2 ] = F_14 ( V_37 , V_140 ) ;
V_37 -> V_448 [ V_95 >> 2 ] = F_14 ( V_37 , V_95 ) ;
V_37 -> V_448 [ V_449 >> 2 ] = F_14 ( V_37 ,
V_449 ) ;
V_37 -> V_448 [ V_450 >> 2 ] = F_14 ( V_37 ,
V_450 ) ;
V_37 -> V_448 [ V_62 >> 2 ] = F_14 ( V_37 ,
V_62 ) ;
V_37 -> V_448 [ V_69 >> 2 ] = F_14 ( V_37 ,
V_69 ) ;
V_37 -> V_448 [ V_70 >> 2 ] = F_14 ( V_37 ,
V_70 ) ;
V_37 -> V_448 [ V_78 >> 2 ] = F_14 ( V_37 ,
V_78 ) ;
}
static int F_164 ( struct V_97 * V_98 )
{
struct V_417 * V_237 = F_165 ( V_98 ) ;
struct V_8 * V_9 = F_159 ( V_237 ) ;
struct V_36 * V_37 = & V_9 -> V_37 ;
if ( ! F_166 ( & V_9 -> V_291 ) )
return 0 ;
F_59 ( V_98 ) ;
F_22 ( V_37 , 1 ) ;
F_163 ( V_37 ) ;
F_21 ( V_37 , 0 ) ;
F_22 ( V_37 , 0 ) ;
F_32 ( V_98 ) ;
F_167 ( V_98 ) ;
return 0 ;
}
static void F_168 ( struct V_36 * V_37 )
{
F_16 ( V_37 , V_37 -> V_448 [ V_77 >> 2 ] , V_77 ) ;
F_16 ( V_37 , V_37 -> V_448 [ V_95 >> 2 ] , V_95 ) ;
F_16 ( V_37 , V_37 -> V_448 [ V_76 >> 2 ] , V_76 ) ;
F_16 ( V_37 , V_37 -> V_448 [ V_202 >> 2 ] , V_202 ) ;
F_16 ( V_37 , V_37 -> V_448 [ V_72 >> 2 ] , V_72 ) ;
F_16 ( V_37 , V_37 -> V_448 [ V_73 >> 2 ] , V_73 ) ;
F_16 ( V_37 , V_37 -> V_448 [ V_75 >> 2 ] , V_75 ) ;
F_16 ( V_37 , V_37 -> V_448 [ V_74 >> 2 ] , V_74 ) ;
F_16 ( V_37 , V_37 -> V_448 [ V_67 >> 2 ] , V_67 ) ;
F_16 ( V_37 , V_37 -> V_448 [ V_71 >> 2 ] , V_71 ) ;
F_16 ( V_37 , V_37 -> V_448 [ V_120 >> 2 ] , V_120 ) ;
F_16 ( V_37 , V_37 -> V_448 [ V_140 >> 2 ] , V_140 ) ;
F_16 ( V_37 , V_37 -> V_448 [ V_46 >> 2 ] , V_46 ) ;
F_16 ( V_37 , V_37 -> V_448 [ V_449 >> 2 ] ,
V_449 ) ;
F_16 ( V_37 , V_37 -> V_448 [ V_450 >> 2 ] ,
V_450 ) ;
F_16 ( V_37 , V_37 -> V_448 [ V_62 >> 2 ] ,
V_62 ) ;
F_16 ( V_37 , V_37 -> V_448 [ V_69 >> 2 ] ,
V_69 ) ;
F_16 ( V_37 , V_37 -> V_448 [ V_70 >> 2 ] ,
V_70 ) ;
F_16 ( V_37 , V_37 -> V_448 [ V_78 >> 2 ] ,
V_78 ) ;
}
static int F_169 ( struct V_97 * V_98 )
{
struct V_417 * V_237 = F_165 ( V_98 ) ;
struct V_8 * V_9 = F_159 ( V_237 ) ;
struct V_36 * V_37 = & V_9 -> V_37 ;
if ( ! F_166 ( & V_9 -> V_291 ) )
return 0 ;
F_59 ( V_98 ) ;
F_22 ( V_37 , 1 ) ;
F_168 ( V_37 ) ;
F_22 ( V_37 , 0 ) ;
F_32 ( V_98 ) ;
F_170 ( V_98 ) ;
return 0 ;
}
