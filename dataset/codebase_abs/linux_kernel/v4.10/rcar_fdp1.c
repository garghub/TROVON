static int F_1 ( const struct V_1 * V_2 )
{
return V_2 -> V_2 <= 0x1b ;
}
static const struct V_1 * F_2 ( T_1 V_3 )
{
const struct V_1 * V_2 ;
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < F_3 ( V_5 ) ; V_4 ++ ) {
V_2 = & V_5 [ V_4 ] ;
if ( V_2 -> V_6 == V_3 )
return V_2 ;
}
return NULL ;
}
static inline struct V_7 * F_4 ( struct V_8 * V_9 )
{
return F_5 ( V_9 , struct V_7 , V_10 . V_9 ) ;
}
static inline struct V_11 * F_6 ( struct V_12 * V_13 )
{
return F_5 ( V_13 , struct V_11 , V_13 ) ;
}
static struct V_14 * F_7 ( struct V_11 * V_15 ,
enum V_16 type )
{
if ( F_8 ( type ) )
return & V_15 -> V_17 ;
else
return & V_15 -> V_18 ;
}
static struct V_19 * F_9 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_19 * V_24 ;
unsigned long V_25 ;
F_10 ( & V_21 -> V_26 , V_25 ) ;
V_24 = F_11 ( V_23 , struct V_19 , V_23 ) ;
if ( V_24 )
F_12 ( & V_24 -> V_23 ) ;
F_13 ( & V_21 -> V_26 , V_25 ) ;
return V_24 ;
}
static void F_14 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
struct V_19 * V_24 )
{
unsigned long V_25 ;
F_10 ( & V_21 -> V_26 , V_25 ) ;
F_15 ( & V_24 -> V_23 , V_23 ) ;
F_13 ( & V_21 -> V_26 , V_25 ) ;
}
static struct V_19 * F_16 ( struct V_20 * V_21 )
{
return F_9 ( V_21 , & V_21 -> V_27 ) ;
}
static void F_17 ( struct V_20 * V_21 , struct V_19 * V_24 )
{
memset ( V_24 , 0 , sizeof( struct V_19 ) ) ;
F_14 ( V_21 , & V_21 -> V_27 , V_24 ) ;
}
static void F_18 ( struct V_20 * V_21 , struct V_19 * V_24 )
{
F_14 ( V_21 , & V_21 -> V_28 , V_24 ) ;
}
static struct V_19 * F_19 ( struct V_20 * V_21 )
{
return F_9 ( V_21 , & V_21 -> V_28 ) ;
}
static void F_20 ( struct V_20 * V_21 , struct V_19 * V_24 )
{
F_14 ( V_21 , & V_21 -> V_29 , V_24 ) ;
}
static struct V_19 * F_21 ( struct V_20 * V_21 )
{
return F_9 ( V_21 , & V_21 -> V_29 ) ;
}
static void F_22 ( struct V_11 * V_15 ,
struct V_30 * V_31 )
{
if ( ! V_31 )
return;
if ( V_31 -> V_32 )
F_23 ( V_31 -> V_9 , V_33 ) ;
}
static void F_24 ( struct V_11 * V_15 ,
struct V_30 * V_31 )
{
unsigned long V_25 ;
F_10 ( & V_15 -> V_21 -> V_26 , V_25 ) ;
F_15 ( & V_31 -> V_23 , & V_15 -> V_34 ) ;
F_13 ( & V_15 -> V_21 -> V_26 , V_25 ) ;
V_15 -> V_35 ++ ;
}
static struct V_30 * F_25 ( struct V_11 * V_15 )
{
struct V_30 * V_31 ;
unsigned long V_25 ;
V_15 -> V_35 -- ;
F_10 ( & V_15 -> V_21 -> V_26 , V_25 ) ;
V_31 = F_11 ( & V_15 -> V_34 ,
struct V_30 , V_23 ) ;
if ( V_31 )
F_12 ( & V_31 -> V_23 ) ;
F_13 ( & V_15 -> V_21 -> V_26 , V_25 ) ;
return V_31 ;
}
static struct V_30 * F_26 ( struct V_11 * V_15 )
{
struct V_30 * V_31 ;
unsigned long V_25 ;
F_10 ( & V_15 -> V_21 -> V_26 , V_25 ) ;
V_31 = F_11 ( & V_15 -> V_34 ,
struct V_30 , V_23 ) ;
F_13 ( & V_15 -> V_21 -> V_26 , V_25 ) ;
return V_31 ;
}
static T_1 F_27 ( struct V_20 * V_21 , unsigned int V_36 )
{
T_1 V_37 = F_28 ( V_21 -> V_38 + V_36 ) ;
if ( V_39 >= 2 )
F_29 ( V_21 , L_1 , V_37 , V_36 ) ;
return V_37 ;
}
static void F_30 ( struct V_20 * V_21 , T_1 V_40 , unsigned int V_36 )
{
if ( V_39 >= 2 )
F_29 ( V_21 , L_2 , V_40 , V_36 ) ;
F_31 ( V_40 , V_21 -> V_38 + V_36 ) ;
}
static void F_32 ( struct V_11 * V_15 )
{
struct V_20 * V_21 = V_15 -> V_21 ;
F_30 ( V_21 , V_41 , V_42 ) ;
F_30 ( V_21 , V_43 , V_44 ) ;
F_30 ( V_21 , V_45 , V_46 ) ;
F_30 ( V_21 , V_47 , V_48 ) ;
F_30 ( V_21 , V_49 , V_50 ) ;
F_30 ( V_21 , V_51 , V_52 ) ;
F_30 ( V_21 , V_53 , V_54 ) ;
F_30 ( V_21 , V_55 , V_56 ) ;
F_30 ( V_21 , V_57 , V_58 ) ;
}
static void F_33 ( struct V_11 * V_15 )
{
struct V_20 * V_21 = V_15 -> V_21 ;
struct V_14 * V_59 = & V_15 -> V_17 ;
unsigned int V_60 , V_61 ;
unsigned int V_62 = V_59 -> V_63 . V_64 ;
unsigned int V_65 = V_59 -> V_63 . V_66 ;
V_60 = V_62 / 3 ;
V_61 = 2 * V_62 / 3 ;
F_30 ( V_21 , V_67 , V_68 ) ;
F_30 ( V_21 , V_69 , V_70 ) ;
F_30 ( V_21 , V_71 , V_72 ) ;
F_30 ( V_21 , V_73 , V_74 ) ;
F_30 ( V_21 , ( ( V_62 - 1 ) << V_75 ) |
( ( V_65 - 1 ) << V_76 ) ,
V_77 ) ;
F_30 ( V_21 , ( V_60 << V_78 ) |
( V_61 << V_79 ) ,
V_80 ) ;
}
static void F_34 ( struct V_20 * V_21 , const T_2 * V_81 ,
unsigned int V_82 , unsigned int V_83 )
{
unsigned int V_4 ;
T_2 V_84 ;
V_82 = F_35 ( V_82 , 256u ) ;
for ( V_4 = 0 ; V_4 < V_82 ; V_4 ++ )
F_30 ( V_21 , V_81 [ V_4 ] , V_83 + ( V_4 * 4 ) ) ;
V_84 = V_81 [ V_4 - 1 ] ;
for (; V_4 < 256 ; V_4 ++ )
F_30 ( V_21 , V_84 , V_83 + ( V_4 * 4 ) ) ;
}
static void F_36 ( struct V_20 * V_21 )
{
F_34 ( V_21 , V_85 , F_3 ( V_85 ) ,
V_86 ) ;
F_34 ( V_21 , V_87 , F_3 ( V_87 ) ,
V_88 ) ;
F_34 ( V_21 , V_89 , F_3 ( V_89 ) ,
V_90 ) ;
F_34 ( V_21 , V_91 , F_3 ( V_91 ) ,
V_92 ) ;
F_34 ( V_21 , V_93 , F_3 ( V_93 ) ,
V_94 ) ;
}
static void F_37 ( struct V_11 * V_15 ,
struct V_19 * V_24 )
{
struct V_20 * V_21 = V_15 -> V_21 ;
T_1 V_95 ;
T_1 V_96 ;
T_1 V_63 ;
T_1 V_97 ;
struct V_14 * V_98 = & V_15 -> V_17 ;
V_95 = ( V_98 -> V_63 . V_64 << V_99 )
| ( V_98 -> V_65 << V_100 ) ;
V_96 = V_98 -> V_101 << V_102 ;
if ( V_98 -> V_63 . V_103 > 1 )
V_96 |= V_98 -> V_104 << V_105 ;
V_63 = V_98 -> V_2 -> V_2 ;
if ( V_98 -> V_2 -> V_106 )
V_63 |= V_107 ;
if ( V_98 -> V_2 -> V_108 )
V_63 |= V_109 ;
if ( V_24 -> V_110 -> V_111 == V_112 ) {
V_63 |= V_113 ;
V_97 = V_15 -> V_97 [ 0 ] ;
} else {
V_97 = V_15 -> V_97 [ 1 ] ;
}
if ( V_15 -> V_114 )
V_63 |= V_115 ;
F_30 ( V_21 , V_63 , V_116 ) ;
F_30 ( V_21 , V_98 -> V_2 -> V_117 , V_118 ) ;
F_30 ( V_21 , V_95 , V_119 ) ;
F_30 ( V_21 , V_96 , V_120 ) ;
F_30 ( V_21 , V_97 , V_121 ) ;
if ( V_24 -> V_122 )
F_30 ( V_21 , V_24 -> V_122 -> V_123 [ 0 ] , V_124 ) ;
F_30 ( V_21 , V_24 -> V_110 -> V_123 [ 0 ] , V_125 ) ;
F_30 ( V_21 , V_24 -> V_110 -> V_123 [ 1 ] , V_126 ) ;
F_30 ( V_21 , V_24 -> V_110 -> V_123 [ 2 ] , V_127 ) ;
if ( V_24 -> V_128 )
F_30 ( V_21 , V_24 -> V_128 -> V_123 [ 0 ] , V_129 ) ;
}
static void F_38 ( struct V_11 * V_15 ,
struct V_19 * V_24 )
{
struct V_20 * V_21 = V_15 -> V_21 ;
struct V_14 * V_59 = & V_15 -> V_17 ;
struct V_14 * V_98 = & V_15 -> V_18 ;
T_1 V_96 ;
T_1 V_63 ;
T_1 V_117 ;
T_1 V_130 ;
V_96 = V_98 -> V_63 . V_131 [ 0 ] . V_132
<< V_133 ;
if ( V_98 -> V_63 . V_103 > 1 )
V_96 |= V_98 -> V_63 . V_131 [ 1 ] . V_132
<< V_134 ;
V_63 = V_98 -> V_2 -> V_2 ;
if ( V_98 -> V_2 -> V_106 )
V_63 |= V_135 ;
if ( V_98 -> V_2 -> V_108 )
V_63 |= V_136 ;
if ( F_1 ( V_98 -> V_2 ) ) {
V_63 |= V_137 ;
if ( V_59 -> V_63 . V_138 == V_139 )
V_63 |= V_140 ;
else if ( V_59 -> V_63 . V_141 ==
V_142 )
V_63 |= V_143 ;
else
V_63 |= V_144 ;
}
V_63 |= V_15 -> V_145 << V_146 ;
V_130 = V_147 ;
V_130 |= V_148 ;
V_117 = V_98 -> V_2 -> V_117 << V_149 ;
V_117 |= V_59 -> V_2 -> V_117 << V_150 ;
F_30 ( V_21 , V_63 , V_151 ) ;
F_30 ( V_21 , V_130 , V_152 ) ;
F_30 ( V_21 , V_117 , V_153 ) ;
F_30 ( V_21 , V_96 , V_154 ) ;
F_30 ( V_21 , V_24 -> V_155 -> V_123 [ 0 ] , V_156 ) ;
F_30 ( V_21 , V_24 -> V_155 -> V_123 [ 1 ] , V_157 ) ;
F_30 ( V_21 , V_24 -> V_155 -> V_123 [ 2 ] , V_158 ) ;
}
static void F_39 ( struct V_11 * V_15 ,
struct V_19 * V_24 )
{
struct V_20 * V_21 = V_15 -> V_21 ;
T_1 V_159 = V_160 ;
T_1 V_161 = V_162 ;
T_1 V_163 = V_164 | V_165 ;
switch ( V_15 -> V_114 ) {
default:
case V_166 :
F_29 ( V_21 , L_3 ) ;
V_159 |= V_167 ;
V_161 |= V_168 ;
break;
case V_169 :
F_29 ( V_21 , L_4 ) ;
if ( V_15 -> V_170 == 0 || V_15 -> V_171 )
V_161 |= V_168 ;
else
V_161 |= V_172 ;
if ( V_15 -> V_170 > 1 ) {
V_163 |= V_173 ;
V_163 |= V_174 | V_175 ;
}
if ( V_15 -> V_170 > 2 )
V_163 |= V_176 ;
break;
case V_177 :
F_29 ( V_21 , L_5 ) ;
V_161 |= V_178 ;
if ( ! ( V_15 -> V_170 == 0 || V_15 -> V_171 ) )
V_163 |= V_174 | V_175 ;
break;
case V_179 :
F_29 ( V_21 , L_6 ) ;
V_161 |= V_168 ;
break;
case V_180 :
F_29 ( V_21 , L_7 ) ;
V_161 |= V_181 ;
V_163 |= V_174 ;
break;
case V_182 :
F_29 ( V_21 , L_8 ) ;
V_161 |= V_183 ;
V_163 |= V_175 ;
break;
}
F_30 ( V_21 , V_163 , V_184 ) ;
F_30 ( V_21 , V_159 , V_185 ) ;
F_30 ( V_21 , V_161 , V_186 ) ;
}
static int F_40 ( struct V_11 * V_15 )
{
struct V_20 * V_21 = V_15 -> V_21 ;
struct V_19 * V_24 ;
unsigned long V_25 ;
F_10 ( & V_21 -> V_187 , V_25 ) ;
V_24 = F_19 ( V_21 ) ;
if ( ! V_24 ) {
F_13 ( & V_21 -> V_187 , V_25 ) ;
return 0 ;
}
F_30 ( V_21 , V_188 , V_189 ) ;
F_39 ( V_15 , V_24 ) ;
F_32 ( V_15 ) ;
F_33 ( V_15 ) ;
F_37 ( V_15 , V_24 ) ;
F_38 ( V_15 , V_24 ) ;
F_30 ( V_21 , V_190 , V_191 ) ;
F_30 ( V_21 , V_192 , V_193 ) ;
F_20 ( V_21 , V_24 ) ;
F_30 ( V_21 , V_194 , V_195 ) ;
F_30 ( V_21 , V_196 , V_197 ) ;
F_30 ( V_21 , V_198 , V_199 ) ;
F_13 ( & V_21 -> V_187 , V_25 ) ;
return 0 ;
}
static int F_41 ( void * V_200 )
{
struct V_11 * V_15 = V_200 ;
struct V_14 * V_59 = & V_15 -> V_17 ;
int V_201 = 1 ;
int V_202 = 1 ;
F_29 ( V_15 -> V_21 , L_9 ,
F_42 ( V_15 -> V_13 . V_203 ) ,
F_43 ( V_15 -> V_13 . V_203 ) ) ;
if ( F_44 ( V_59 -> V_63 . V_111 ) )
V_202 = 2 ;
if ( F_42 ( V_15 -> V_13 . V_203 ) < V_201
|| F_43 ( V_15 -> V_13 . V_203 ) < V_202 ) {
F_29 ( V_15 -> V_21 , L_10 ) ;
return 0 ;
}
return 1 ;
}
static void F_45 ( void * V_200 )
{
struct V_11 * V_15 = V_200 ;
F_29 ( V_15 -> V_21 , L_11 ) ;
V_15 -> V_171 = 1 ;
F_30 ( V_15 -> V_21 , 0 , V_199 ) ;
F_30 ( V_15 -> V_21 , V_204 , V_205 ) ;
}
static struct V_19 * F_46 ( struct V_11 * V_15 )
{
struct V_8 * V_206 ;
struct V_7 * V_31 ;
struct V_20 * V_21 = V_15 -> V_21 ;
struct V_19 * V_24 ;
unsigned int V_207 = 1 ;
F_29 ( V_21 , L_11 ) ;
if ( F_47 ( V_15 -> V_114 ) )
V_207 = 2 ;
if ( V_15 -> V_35 < V_207 )
return NULL ;
V_24 = F_16 ( V_21 ) ;
if ( ! V_24 ) {
F_29 ( V_21 , L_12 ) ;
return NULL ;
}
V_24 -> V_110 = F_25 ( V_15 ) ;
if ( ! V_24 -> V_110 ) {
F_29 ( V_21 , L_13 ) ;
F_17 ( V_21 , V_24 ) ;
return NULL ;
}
F_29 ( V_21 , L_14 ) ;
V_206 = F_48 ( V_15 -> V_13 . V_203 ) ;
V_31 = F_4 ( V_206 ) ;
V_24 -> V_155 = & V_31 -> V_208 [ 0 ] ;
V_24 -> V_110 -> V_9 -> V_170 = V_15 -> V_170 ;
V_24 -> V_155 -> V_9 -> V_170 = V_15 -> V_170 ;
V_15 -> V_170 ++ ;
if ( F_49 ( V_15 -> V_114 ) ) {
V_24 -> V_122 = V_15 -> V_122 ;
V_15 -> V_122 = V_24 -> V_110 ;
}
if ( F_47 ( V_15 -> V_114 ) ) {
V_24 -> V_128 = F_26 ( V_15 ) ;
}
V_24 -> V_155 -> V_9 -> V_209 . V_210 = V_24 -> V_110 -> V_9 -> V_209 . V_210 ;
V_24 -> V_155 -> V_9 -> V_25 = V_24 -> V_110 -> V_9 -> V_25 &
V_211 ;
V_15 -> V_212 ++ ;
F_18 ( V_21 , V_24 ) ;
F_29 ( V_21 , L_15 , V_15 -> V_212 ) ;
return V_24 ;
}
static void F_50 ( void * V_200 )
{
struct V_11 * V_15 = V_200 ;
struct V_20 * V_21 = V_15 -> V_21 ;
struct V_8 * V_213 ;
struct V_7 * V_214 ;
unsigned int V_4 ;
F_29 ( V_21 , L_11 ) ;
V_15 -> V_212 = 0 ;
V_213 = F_51 ( V_15 -> V_13 . V_203 ) ;
V_214 = F_4 ( V_213 ) ;
for ( V_4 = 0 ; V_4 < V_214 -> V_215 ; V_4 ++ ) {
struct V_30 * V_31 = & V_214 -> V_208 [ V_4 ] ;
F_24 ( V_15 , V_31 ) ;
F_29 ( V_21 , L_16 ,
V_4 , V_31 -> V_32 ) ;
}
while ( F_46 ( V_15 ) )
;
if ( V_15 -> V_212 == 0 ) {
F_29 ( V_21 , L_17 ) ;
F_52 ( V_21 -> V_216 , V_15 -> V_13 . V_203 ) ;
return;
}
F_40 ( V_15 ) ;
}
static void F_53 ( struct V_20 * V_21 ,
enum V_217 V_218 )
{
struct V_11 * V_15 ;
unsigned long V_25 ;
struct V_19 * V_24 = F_21 ( V_21 ) ;
F_29 ( V_21 , L_11 ) ;
V_15 = F_54 ( V_21 -> V_216 ) ;
if ( V_15 == NULL ) {
F_55 ( & V_21 -> V_219 ,
L_18 ) ;
return;
}
V_15 -> V_220 ++ ;
if ( F_49 ( V_15 -> V_114 ) )
F_22 ( V_15 , V_24 -> V_122 ) ;
else
F_22 ( V_15 , V_24 -> V_110 ) ;
F_10 ( & V_21 -> V_26 , V_25 ) ;
F_23 ( V_24 -> V_155 -> V_9 , V_218 ) ;
V_24 -> V_155 = NULL ;
F_13 ( & V_21 -> V_26 , V_25 ) ;
F_17 ( V_21 , V_24 ) ;
F_29 ( V_21 , L_19 ,
V_15 -> V_220 , V_15 -> V_212 ) ;
if ( V_15 -> V_220 == V_15 -> V_212 ||
V_15 -> V_171 ) {
F_29 ( V_15 -> V_21 , L_20 ) ;
V_15 -> V_220 = 0 ;
F_52 ( V_21 -> V_216 , V_15 -> V_13 . V_203 ) ;
} else {
F_40 ( V_15 ) ;
}
}
static int F_56 ( struct V_221 * V_221 , void * V_200 ,
struct V_222 * V_223 )
{
F_57 ( V_223 -> V_224 , V_225 , sizeof( V_223 -> V_224 ) ) ;
F_57 ( V_223 -> V_226 , V_225 , sizeof( V_223 -> V_226 ) ) ;
snprintf ( V_223 -> V_227 , sizeof( V_223 -> V_227 ) ,
L_21 , V_225 ) ;
return 0 ;
}
static int F_58 ( struct V_228 * V_229 , T_1 type )
{
unsigned int V_4 , V_230 ;
V_230 = 0 ;
for ( V_4 = 0 ; V_4 < F_3 ( V_5 ) ; ++ V_4 ) {
if ( V_5 [ V_4 ] . V_231 & type ) {
if ( V_230 == V_229 -> V_232 )
break;
++ V_230 ;
}
}
if ( V_4 >= F_3 ( V_5 ) )
return - V_233 ;
V_229 -> V_3 = V_5 [ V_4 ] . V_6 ;
return 0 ;
}
static int F_59 ( struct V_221 * V_221 , void * V_200 ,
struct V_228 * V_229 )
{
return F_58 ( V_229 , V_234 ) ;
}
static int F_60 ( struct V_221 * V_221 , void * V_200 ,
struct V_228 * V_229 )
{
return F_58 ( V_229 , V_235 ) ;
}
static int F_61 ( struct V_221 * V_221 , void * V_200 , struct V_236 * V_229 )
{
struct V_14 * V_98 ;
struct V_11 * V_15 = F_6 ( V_200 ) ;
if ( ! F_62 ( V_15 -> V_13 . V_203 , V_229 -> type ) )
return - V_233 ;
V_98 = F_7 ( V_15 , V_229 -> type ) ;
V_229 -> V_2 . V_237 = V_98 -> V_63 ;
return 0 ;
}
static void F_63 ( struct V_238 * V_239 ,
const struct V_1 * V_2 )
{
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < F_64 (unsigned int, fmt->num_planes, 2U ) ; ++ V_4 ) {
unsigned int V_240 = V_4 > 0 ? V_2 -> V_240 : 1 ;
unsigned int V_241 = V_4 > 0 ? V_2 -> V_241 : 1 ;
unsigned int V_242 = 128 ;
unsigned int V_243 ;
V_243 = F_65 (unsigned int, pix->plane_fmt[i].bytesperline,
pix->width / hsub * fmt->bpp[i] / 8 ,
round_down(FDP1_MAX_STRIDE, align)) ;
V_239 -> V_131 [ V_4 ] . V_132 = F_66 ( V_243 , V_242 ) ;
V_239 -> V_131 [ V_4 ] . V_244 = V_239 -> V_131 [ V_4 ] . V_132
* V_239 -> V_66 / V_241 ;
memset ( V_239 -> V_131 [ V_4 ] . V_245 , 0 ,
sizeof( V_239 -> V_131 [ V_4 ] . V_245 ) ) ;
}
if ( V_2 -> V_103 == 3 ) {
V_239 -> V_131 [ 2 ] . V_132 = V_239 -> V_131 [ 1 ] . V_132 ;
V_239 -> V_131 [ 2 ] . V_244 = V_239 -> V_131 [ 1 ] . V_244 ;
memset ( V_239 -> V_131 [ 2 ] . V_245 , 0 ,
sizeof( V_239 -> V_131 [ 2 ] . V_245 ) ) ;
}
}
static void F_67 ( struct V_11 * V_15 ,
const struct V_1 * * V_246 ,
struct V_238 * V_239 )
{
const struct V_1 * V_2 ;
unsigned int V_64 ;
unsigned int V_66 ;
V_2 = F_2 ( V_239 -> V_3 ) ;
if ( ! V_2 || ! ( V_2 -> V_231 & V_235 ) )
V_2 = F_2 ( V_247 ) ;
if ( V_246 )
* V_246 = V_2 ;
V_239 -> V_3 = V_2 -> V_6 ;
V_239 -> V_103 = V_2 -> V_103 ;
if ( V_239 -> V_111 != V_248 &&
V_239 -> V_111 != V_249 &&
! F_44 ( V_239 -> V_111 ) )
V_239 -> V_111 = V_250 ;
if ( V_239 -> V_251 == V_252 )
V_239 -> V_251 = V_253 ;
V_64 = F_68 ( V_239 -> V_64 , V_2 -> V_240 ) ;
V_239 -> V_64 = F_69 ( V_64 , V_254 , V_255 ) ;
V_66 = F_68 ( V_239 -> V_66 , V_2 -> V_241 ) ;
if ( V_239 -> V_111 == V_249 )
V_239 -> V_66 = F_69 ( V_66 , V_256 / 2 , V_257 / 2 ) ;
else
V_239 -> V_66 = F_69 ( V_66 , V_256 , V_257 ) ;
F_63 ( V_239 , V_2 ) ;
}
static void F_70 ( struct V_11 * V_15 ,
const struct V_1 * * V_246 ,
struct V_238 * V_239 )
{
struct V_14 * V_258 = & V_15 -> V_17 ;
enum V_259 V_251 ;
enum V_260 V_138 ;
enum V_261 V_141 ;
const struct V_1 * V_2 ;
bool V_262 ;
V_251 = V_258 -> V_63 . V_251 ;
V_138 = V_258 -> V_63 . V_138 ;
if ( V_138 == V_263 )
V_138 = F_71 ( V_251 ) ;
V_141 = V_258 -> V_63 . V_141 ;
if ( V_141 == V_264 )
V_141 = F_72 ( false , V_251 ,
V_138 ) ;
V_262 = V_138 == V_265 ||
( V_138 == V_139 &&
V_141 == V_266 ) ;
V_2 = F_2 ( V_239 -> V_3 ) ;
if ( ! V_2 || ( ! V_262 && F_1 ( V_2 ) ) )
V_2 = F_2 ( V_247 ) ;
if ( V_246 )
* V_246 = V_2 ;
V_239 -> V_3 = V_2 -> V_6 ;
V_239 -> V_103 = V_2 -> V_103 ;
V_239 -> V_111 = V_248 ;
V_239 -> V_251 = V_258 -> V_63 . V_251 ;
V_239 -> V_267 = V_258 -> V_63 . V_267 ;
if ( F_1 ( V_2 ) ) {
V_239 -> V_138 = V_263 ;
V_239 -> V_141 = V_264 ;
} else {
V_239 -> V_138 = V_258 -> V_63 . V_138 ;
V_239 -> V_141 = V_258 -> V_63 . V_141 ;
}
V_239 -> V_64 = V_258 -> V_63 . V_64 ;
if ( V_258 -> V_63 . V_111 == V_249 )
V_239 -> V_66 = 2 * V_258 -> V_63 . V_66 ;
else
V_239 -> V_66 = V_258 -> V_63 . V_66 ;
F_63 ( V_239 , V_2 ) ;
}
static int F_73 ( struct V_221 * V_221 , void * V_200 , struct V_236 * V_229 )
{
struct V_11 * V_15 = F_6 ( V_200 ) ;
if ( V_229 -> type == V_268 )
F_67 ( V_15 , NULL , & V_229 -> V_2 . V_237 ) ;
else
F_70 ( V_15 , NULL , & V_229 -> V_2 . V_237 ) ;
F_29 ( V_15 -> V_21 , L_22 ,
F_8 ( V_229 -> type ) ? L_23 : L_24 ,
( char * ) & V_229 -> V_2 . V_237 . V_3 , V_229 -> V_2 . V_237 . V_3 ,
V_229 -> V_2 . V_237 . V_64 , V_229 -> V_2 . V_237 . V_66 , V_229 -> V_2 . V_237 . V_111 ) ;
return 0 ;
}
static void F_74 ( struct V_11 * V_15 ,
struct V_238 * V_239 ,
enum V_16 type )
{
struct V_14 * V_98 = F_7 ( V_15 , type ) ;
const struct V_1 * V_246 ;
if ( type == V_268 )
F_67 ( V_15 , & V_246 , V_239 ) ;
else
F_70 ( V_15 , & V_246 , V_239 ) ;
V_98 -> V_2 = V_246 ;
V_98 -> V_63 = * V_239 ;
V_98 -> V_65 = V_239 -> V_66 ;
if ( V_239 -> V_111 != V_248 )
V_98 -> V_65 /= 2 ;
V_98 -> V_101 = V_239 -> V_131 [ 0 ] . V_132 ;
V_98 -> V_104 = V_239 -> V_131 [ 1 ] . V_132 ;
if ( V_239 -> V_111 == V_250 ||
V_239 -> V_111 == V_269 ||
V_239 -> V_111 == V_270 ) {
V_98 -> V_101 *= 2 ;
V_98 -> V_104 *= 2 ;
}
if ( type == V_268 ) {
struct V_14 * V_271 = & V_15 -> V_18 ;
V_271 -> V_63 = V_98 -> V_63 ;
memset ( V_271 -> V_63 . V_131 , 0 ,
sizeof( V_271 -> V_63 . V_131 ) ) ;
V_271 -> V_63 . V_111 = V_248 ;
if ( V_239 -> V_111 == V_249 )
V_271 -> V_63 . V_66 *= 2 ;
F_70 ( V_15 , & V_271 -> V_2 , & V_271 -> V_63 ) ;
V_271 -> V_65 = V_271 -> V_63 . V_66 ;
V_271 -> V_101 = V_271 -> V_63 . V_131 [ 0 ] . V_132 ;
V_271 -> V_104 = V_271 -> V_63 . V_131 [ 1 ] . V_132 ;
}
}
static int F_75 ( struct V_221 * V_221 , void * V_200 , struct V_236 * V_229 )
{
struct V_11 * V_15 = F_6 ( V_200 ) ;
struct V_272 * V_203 = V_15 -> V_13 . V_203 ;
struct V_273 * V_274 = F_62 ( V_203 , V_229 -> type ) ;
if ( F_76 ( V_274 ) ) {
F_55 ( & V_15 -> V_21 -> V_219 , L_25 , V_275 ) ;
return - V_276 ;
}
F_74 ( V_15 , & V_229 -> V_2 . V_237 , V_229 -> type ) ;
F_29 ( V_15 -> V_21 , L_26 ,
F_8 ( V_229 -> type ) ? L_23 : L_24 ,
( char * ) & V_229 -> V_2 . V_237 . V_3 , V_229 -> V_2 . V_237 . V_3 ,
V_229 -> V_2 . V_237 . V_64 , V_229 -> V_2 . V_237 . V_66 , V_229 -> V_2 . V_237 . V_111 ) ;
return 0 ;
}
static int F_77 ( struct V_277 * V_278 )
{
struct V_11 * V_15 =
F_5 ( V_278 -> V_279 , struct V_11 , V_280 ) ;
struct V_14 * V_59 = & V_15 -> V_17 ;
switch ( V_278 -> V_281 ) {
case V_282 :
if ( F_44 ( V_59 -> V_63 . V_111 ) )
V_278 -> V_40 = 2 ;
else
V_278 -> V_40 = 1 ;
return 0 ;
}
return 1 ;
}
static int F_78 ( struct V_277 * V_278 )
{
struct V_11 * V_15 =
F_5 ( V_278 -> V_279 , struct V_11 , V_280 ) ;
switch ( V_278 -> V_281 ) {
case V_283 :
V_15 -> V_145 = V_278 -> V_40 ;
break;
case V_284 :
V_15 -> V_114 = V_278 -> V_40 ;
break;
}
return 0 ;
}
static int F_79 ( struct V_273 * V_274 ,
unsigned int * V_285 , unsigned int * V_286 ,
unsigned int V_287 [] ,
struct V_288 * V_289 [] )
{
struct V_11 * V_15 = F_80 ( V_274 ) ;
struct V_14 * V_98 ;
unsigned int V_4 ;
V_98 = F_7 ( V_15 , V_274 -> type ) ;
if ( * V_286 ) {
if ( * V_286 > V_290 )
return - V_233 ;
return 0 ;
}
* V_286 = V_98 -> V_63 . V_103 ;
for ( V_4 = 0 ; V_4 < * V_286 ; V_4 ++ )
V_287 [ V_4 ] = V_98 -> V_63 . V_131 [ V_4 ] . V_244 ;
return 0 ;
}
static void F_81 ( struct V_14 * V_98 ,
struct V_8 * V_206 ,
unsigned int V_291 )
{
struct V_7 * V_214 = F_4 ( V_206 ) ;
struct V_30 * V_31 = & V_214 -> V_208 [ V_291 ] ;
unsigned int V_215 ;
unsigned int V_4 ;
V_215 = F_44 ( V_206 -> V_111 ) ? 2 : 1 ;
V_31 -> V_9 = V_206 ;
V_31 -> V_32 = ( V_291 + 1 ) == V_215 ;
for ( V_4 = 0 ; V_4 < V_206 -> V_209 . V_103 ; ++ V_4 )
V_31 -> V_123 [ V_4 ] = F_82 ( & V_206 -> V_209 , V_4 ) ;
switch ( V_206 -> V_111 ) {
case V_250 :
V_31 -> V_111 = ( V_98 -> V_63 . V_66 < 576 ) == V_291
? V_292 : V_112 ;
break;
case V_269 :
case V_293 :
V_31 -> V_111 = V_291 ? V_112 : V_292 ;
break;
case V_270 :
case V_294 :
V_31 -> V_111 = V_291 ? V_292 : V_112 ;
break;
default:
V_31 -> V_111 = V_206 -> V_111 ;
break;
}
if ( ! V_291 )
return;
switch ( V_206 -> V_111 ) {
case V_250 :
case V_269 :
case V_270 :
for ( V_4 = 0 ; V_4 < V_206 -> V_209 . V_103 ; V_4 ++ )
V_31 -> V_123 [ V_4 ] +=
( V_4 == 0 ? V_98 -> V_101 : V_98 -> V_104 ) ;
break;
case V_293 :
case V_294 :
for ( V_4 = 0 ; V_4 < V_206 -> V_209 . V_103 ; V_4 ++ )
V_31 -> V_123 [ V_4 ] += V_98 -> V_65 *
( V_4 == 0 ? V_98 -> V_101 : V_98 -> V_104 ) ;
break;
}
}
static int F_83 ( struct V_295 * V_9 )
{
struct V_11 * V_15 = F_80 ( V_9 -> V_273 ) ;
struct V_14 * V_98 = F_7 ( V_15 , V_9 -> V_273 -> type ) ;
struct V_8 * V_206 = F_84 ( V_9 ) ;
struct V_7 * V_214 = F_4 ( V_206 ) ;
unsigned int V_4 ;
if ( F_8 ( V_9 -> V_273 -> type ) ) {
bool V_296 = true ;
switch ( V_98 -> V_63 . V_111 ) {
case V_248 :
if ( V_206 -> V_111 != V_248 )
V_296 = false ;
break;
case V_249 :
if ( V_206 -> V_111 != V_292 &&
V_206 -> V_111 != V_112 )
V_296 = false ;
break;
case V_250 :
case V_293 :
case V_294 :
case V_269 :
case V_270 :
if ( V_206 -> V_111 != V_98 -> V_63 . V_111 )
V_296 = false ;
break;
}
if ( ! V_296 ) {
F_29 ( V_15 -> V_21 ,
L_27 ,
V_206 -> V_111 , V_98 -> V_63 . V_111 ) ;
return - V_233 ;
}
} else {
V_206 -> V_111 = V_248 ;
}
for ( V_4 = 0 ; V_4 < V_98 -> V_63 . V_103 ; V_4 ++ ) {
unsigned long V_297 = V_98 -> V_63 . V_131 [ V_4 ] . V_244 ;
if ( F_85 ( V_9 , V_4 ) < V_297 ) {
F_29 ( V_15 -> V_21 ,
L_28 ,
V_4 , V_98 -> V_63 . V_103 ,
F_85 ( V_9 , V_4 ) , V_297 ) ;
return - V_233 ;
}
F_86 ( V_9 , V_4 , V_297 ) ;
}
V_214 -> V_215 = F_44 ( V_206 -> V_111 ) ? 2 : 1 ;
for ( V_4 = 0 ; V_4 < V_214 -> V_215 ; ++ V_4 )
F_81 ( V_98 , V_206 , V_4 ) ;
return 0 ;
}
static void F_87 ( struct V_295 * V_9 )
{
struct V_8 * V_206 = F_84 ( V_9 ) ;
struct V_11 * V_15 = F_80 ( V_9 -> V_273 ) ;
F_88 ( V_15 -> V_13 . V_203 , V_206 ) ;
}
static int F_89 ( struct V_273 * V_298 , unsigned int V_299 )
{
struct V_11 * V_15 = F_80 ( V_298 ) ;
struct V_14 * V_98 = F_7 ( V_15 , V_298 -> type ) ;
if ( F_8 ( V_298 -> type ) ) {
if ( V_98 -> V_63 . V_111 == V_248 )
V_15 -> V_114 = V_166 ;
if ( V_15 -> V_114 == V_169 ) {
T_1 V_300 ;
T_3 V_301 ;
const T_1 V_302 = 2 ;
V_300 = F_66 ( V_98 -> V_63 . V_64 , 8 ) ;
V_15 -> V_303 = V_302 * V_300 * V_98 -> V_65 ;
V_15 -> V_304 = F_90 ( V_15 -> V_21 -> V_305 ,
V_15 -> V_303 , & V_301 , V_306 ) ;
if ( V_15 -> V_304 == NULL ) {
F_29 ( V_15 -> V_21 , L_29 ) ;
return - V_307 ;
}
V_15 -> V_97 [ 0 ] = V_301 ;
V_15 -> V_97 [ 1 ] = V_301 + ( V_15 -> V_303 / 2 ) ;
}
}
return 0 ;
}
static void F_91 ( struct V_273 * V_298 )
{
struct V_11 * V_15 = F_80 ( V_298 ) ;
struct V_8 * V_206 ;
unsigned long V_25 ;
while ( 1 ) {
if ( F_8 ( V_298 -> type ) )
V_206 = F_51 ( V_15 -> V_13 . V_203 ) ;
else
V_206 = F_48 ( V_15 -> V_13 . V_203 ) ;
if ( V_206 == NULL )
break;
F_10 ( & V_15 -> V_21 -> V_26 , V_25 ) ;
F_23 ( V_206 , V_308 ) ;
F_13 ( & V_15 -> V_21 -> V_26 , V_25 ) ;
}
if ( F_8 ( V_298 -> type ) ) {
struct V_30 * V_31 ;
V_31 = F_25 ( V_15 ) ;
while ( V_31 != NULL ) {
F_22 ( V_15 , V_31 ) ;
V_31 = F_25 ( V_15 ) ;
}
if ( V_15 -> V_304 ) {
F_92 ( V_15 -> V_21 -> V_305 , V_15 -> V_303 ,
V_15 -> V_304 , V_15 -> V_97 [ 0 ] ) ;
V_15 -> V_97 [ 0 ] = V_15 -> V_97 [ 1 ] = 0 ;
V_15 -> V_304 = NULL ;
}
F_93 ( ! F_94 ( & V_15 -> V_34 ) ,
L_30 ) ;
} else {
struct V_19 * V_24 ;
V_24 = F_19 ( V_15 -> V_21 ) ;
while ( V_24 ) {
if ( F_49 ( V_15 -> V_114 ) )
F_22 ( V_15 , V_24 -> V_122 ) ;
else
F_22 ( V_15 , V_24 -> V_110 ) ;
F_23 ( V_24 -> V_155 -> V_9 , V_308 ) ;
V_24 -> V_155 = NULL ;
V_24 = F_19 ( V_15 -> V_21 ) ;
}
F_22 ( V_15 , V_15 -> V_122 ) ;
F_93 ( ! F_94 ( & V_15 -> V_21 -> V_28 ) ,
L_31 ) ;
F_93 ( ! F_94 ( & V_15 -> V_21 -> V_29 ) ,
L_32 ) ;
}
}
static int F_95 ( void * V_200 , struct V_273 * V_309 ,
struct V_273 * V_310 )
{
struct V_11 * V_15 = V_200 ;
int V_311 ;
V_309 -> type = V_268 ;
V_309 -> V_312 = V_313 | V_314 | V_315 ;
V_309 -> V_316 = V_15 ;
V_309 -> V_317 = sizeof( struct V_7 ) ;
V_309 -> V_318 = & V_319 ;
V_309 -> V_320 = & V_321 ;
V_309 -> V_322 = V_323 ;
V_309 -> V_324 = & V_15 -> V_21 -> V_325 ;
V_309 -> V_305 = V_15 -> V_21 -> V_305 ;
V_311 = F_96 ( V_309 ) ;
if ( V_311 )
return V_311 ;
V_310 -> type = V_326 ;
V_310 -> V_312 = V_313 | V_314 | V_315 ;
V_310 -> V_316 = V_15 ;
V_310 -> V_317 = sizeof( struct V_7 ) ;
V_310 -> V_318 = & V_319 ;
V_310 -> V_320 = & V_321 ;
V_310 -> V_322 = V_323 ;
V_310 -> V_324 = & V_15 -> V_21 -> V_325 ;
V_310 -> V_305 = V_15 -> V_21 -> V_305 ;
return F_96 ( V_310 ) ;
}
static int F_97 ( struct V_221 * V_221 )
{
struct V_20 * V_21 = F_98 ( V_221 ) ;
struct V_238 V_63 ;
struct V_11 * V_15 = NULL ;
struct V_277 * V_278 ;
int V_311 = 0 ;
if ( F_99 ( & V_21 -> V_325 ) )
return - V_327 ;
V_15 = F_100 ( sizeof( * V_15 ) , V_306 ) ;
if ( ! V_15 ) {
V_311 = - V_307 ;
goto V_328;
}
F_101 ( & V_15 -> V_13 , F_102 ( V_221 ) ) ;
V_221 -> V_329 = & V_15 -> V_13 ;
V_15 -> V_21 = V_21 ;
F_103 ( & V_15 -> V_34 ) ;
V_15 -> V_212 = 1 ;
V_15 -> V_170 = 0 ;
F_104 ( & V_15 -> V_280 , 3 ) ;
F_105 ( & V_15 -> V_280 , & V_330 ,
V_284 ,
V_182 , F_106 ( 0 ) , V_177 ,
V_331 ) ;
V_278 = F_107 ( & V_15 -> V_280 , & V_330 ,
V_282 , 1 , 2 , 1 , 1 ) ;
if ( V_278 )
V_278 -> V_25 |= V_332 ;
F_107 ( & V_15 -> V_280 , & V_330 ,
V_283 , 0 , 255 , 1 , 255 ) ;
if ( V_15 -> V_280 . error ) {
V_311 = V_15 -> V_280 . error ;
F_108 ( & V_15 -> V_280 ) ;
goto V_328;
}
V_15 -> V_13 . V_333 = & V_15 -> V_280 ;
F_109 ( & V_15 -> V_280 ) ;
memset ( & V_63 , 0 , sizeof( V_63 ) ) ;
F_74 ( V_15 , & V_63 , V_268 ) ;
V_15 -> V_13 . V_203 = F_110 ( V_21 -> V_216 , V_15 , & F_95 ) ;
if ( F_111 ( V_15 -> V_13 . V_203 ) ) {
V_311 = F_112 ( V_15 -> V_13 . V_203 ) ;
F_108 ( & V_15 -> V_280 ) ;
F_113 ( V_15 ) ;
goto V_328;
}
F_114 ( V_21 -> V_305 ) ;
F_115 ( & V_15 -> V_13 ) ;
F_29 ( V_21 , L_33 ,
V_15 , V_15 -> V_13 . V_203 ) ;
V_328:
F_116 ( & V_21 -> V_325 ) ;
return V_311 ;
}
static int F_117 ( struct V_221 * V_221 )
{
struct V_20 * V_21 = F_98 ( V_221 ) ;
struct V_11 * V_15 = F_6 ( V_221 -> V_329 ) ;
F_29 ( V_21 , L_34 , V_15 ) ;
F_118 ( & V_15 -> V_13 ) ;
F_119 ( & V_15 -> V_13 ) ;
F_108 ( & V_15 -> V_280 ) ;
F_120 ( & V_21 -> V_325 ) ;
F_121 ( V_15 -> V_13 . V_203 ) ;
F_116 ( & V_21 -> V_325 ) ;
F_113 ( V_15 ) ;
F_122 ( V_21 -> V_305 ) ;
return 0 ;
}
static T_4 F_123 ( int V_334 , void * V_335 )
{
struct V_20 * V_21 = V_335 ;
T_1 V_336 ;
T_1 V_337 ;
T_1 V_338 ;
T_1 V_339 ;
V_336 = F_27 ( V_21 , V_340 ) ;
V_339 = F_27 ( V_21 , V_341 ) ;
V_337 = F_27 ( V_21 , V_342 ) ;
V_338 = ( V_337 & V_343 ) >>
V_344 ;
F_30 ( V_21 , ~ ( V_336 ) & V_192 , V_340 ) ;
if ( V_39 >= 2 ) {
F_29 ( V_21 , L_35 , V_336 ,
V_336 & V_345 ? L_36 : L_37 ,
V_336 & V_346 ? L_38 : L_39 ,
V_336 & V_347 ? L_40 : L_41 ) ;
F_29 ( V_21 , L_42 ,
V_339 , V_339 / ( V_21 -> V_348 / 1000 ) ) ;
F_29 ( V_21 ,
L_43 ,
V_337 , V_338 ,
V_337 & V_349 ? L_44 : L_45 ,
V_337 & V_350 ? L_46 : L_45 ,
V_337 & V_351 ? L_47 : L_45 ,
V_337 & V_352 ? L_48 : L_45 ) ;
F_29 ( V_21 , L_49 ) ;
}
if ( ! ( V_192 & V_336 ) )
return V_353 ;
if ( V_345 & V_336 )
F_53 ( V_21 , V_308 ) ;
else if ( V_347 & V_336 )
F_53 ( V_21 , V_33 ) ;
return V_354 ;
}
static int F_124 ( struct V_355 * V_356 )
{
struct V_20 * V_21 ;
struct V_357 * V_358 ;
struct V_359 * V_360 ;
struct V_361 * V_362 ;
struct V_363 * V_363 ;
unsigned int V_4 ;
int V_311 ;
int V_364 ;
V_21 = F_125 ( & V_356 -> V_305 , sizeof( * V_21 ) , V_306 ) ;
if ( ! V_21 )
return - V_307 ;
F_103 ( & V_21 -> V_27 ) ;
F_103 ( & V_21 -> V_28 ) ;
F_103 ( & V_21 -> V_29 ) ;
for ( V_4 = 0 ; V_4 < F_3 ( V_21 -> V_365 ) ; V_4 ++ )
F_126 ( & V_21 -> V_365 [ V_4 ] . V_23 , & V_21 -> V_27 ) ;
F_127 ( & V_21 -> V_325 ) ;
F_128 ( & V_21 -> V_26 ) ;
F_128 ( & V_21 -> V_187 ) ;
V_21 -> V_305 = & V_356 -> V_305 ;
F_129 ( V_356 , V_21 ) ;
V_362 = F_130 ( V_356 , V_366 , 0 ) ;
V_21 -> V_38 = F_131 ( & V_356 -> V_305 , V_362 ) ;
if ( F_111 ( V_21 -> V_38 ) )
return F_112 ( V_21 -> V_38 ) ;
V_21 -> V_334 = V_311 = F_132 ( V_356 , 0 ) ;
if ( V_311 < 0 ) {
F_133 ( & V_356 -> V_305 , L_50 ) ;
return V_311 ;
}
V_311 = F_134 ( & V_356 -> V_305 , V_21 -> V_334 , F_123 , 0 ,
F_135 ( & V_356 -> V_305 ) , V_21 ) ;
if ( V_311 ) {
F_133 ( & V_356 -> V_305 , L_51 , V_21 -> V_334 ) ;
return V_311 ;
}
V_360 = F_136 ( V_356 -> V_305 . V_367 , L_52 , 0 ) ;
if ( V_360 ) {
V_21 -> V_368 = F_137 ( V_360 ) ;
F_138 ( V_360 ) ;
if ( F_111 ( V_21 -> V_368 ) ) {
F_133 ( & V_356 -> V_305 , L_53 ,
F_112 ( V_21 -> V_368 ) ) ;
return F_112 ( V_21 -> V_368 ) ;
}
}
V_363 = F_139 ( & V_356 -> V_305 , NULL ) ;
if ( F_111 ( V_363 ) )
return F_112 ( V_363 ) ;
V_21 -> V_348 = F_140 ( V_363 ) ;
F_141 ( V_363 ) ;
V_311 = F_142 ( & V_356 -> V_305 , & V_21 -> V_219 ) ;
if ( V_311 ) {
F_55 ( & V_21 -> V_219 , L_54 ) ;
return V_311 ;
}
V_21 -> V_216 = F_143 ( & V_369 ) ;
if ( F_111 ( V_21 -> V_216 ) ) {
F_55 ( & V_21 -> V_219 , L_55 ) ;
V_311 = F_112 ( V_21 -> V_216 ) ;
goto V_370;
}
V_21 -> V_358 = V_371 ;
V_358 = & V_21 -> V_358 ;
V_358 -> V_324 = & V_21 -> V_325 ;
V_358 -> V_219 = & V_21 -> V_219 ;
F_144 ( V_358 , V_21 ) ;
F_57 ( V_358 -> V_372 , V_371 . V_372 , sizeof( V_358 -> V_372 ) ) ;
V_311 = F_145 ( V_358 , V_373 , 0 ) ;
if ( V_311 ) {
F_55 ( & V_21 -> V_219 , L_54 ) ;
goto V_374;
}
F_146 ( & V_21 -> V_219 ,
L_56 , V_358 -> V_230 ) ;
F_147 ( & V_356 -> V_305 ) ;
F_114 ( V_21 -> V_305 ) ;
V_364 = F_27 ( V_21 , V_375 ) ;
switch ( V_364 ) {
case V_376 :
F_29 ( V_21 , L_57 ) ;
break;
case V_377 :
F_29 ( V_21 , L_58 ) ;
break;
default:
F_133 ( V_21 -> V_305 , L_59 ,
V_364 ) ;
}
F_122 ( V_21 -> V_305 ) ;
return 0 ;
V_374:
F_148 ( V_21 -> V_216 ) ;
V_370:
F_149 ( & V_21 -> V_219 ) ;
return V_311 ;
}
static int F_150 ( struct V_355 * V_356 )
{
struct V_20 * V_21 = F_151 ( V_356 ) ;
F_148 ( V_21 -> V_216 ) ;
F_152 ( & V_21 -> V_358 ) ;
F_149 ( & V_21 -> V_219 ) ;
F_153 ( & V_356 -> V_305 ) ;
return 0 ;
}
static int T_5 F_154 ( struct V_288 * V_305 )
{
struct V_20 * V_21 = F_155 ( V_305 ) ;
F_156 ( V_21 -> V_368 ) ;
return 0 ;
}
static int T_5 F_157 ( struct V_288 * V_305 )
{
struct V_20 * V_21 = F_155 ( V_305 ) ;
F_36 ( V_21 ) ;
return F_158 ( V_21 -> V_368 ) ;
}
