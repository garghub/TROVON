static void F_1 ( T_1 * V_1 , T_2 V_2 ,
struct V_3 * V_4 )
{
memcpy ( V_1 , V_4 -> V_5 , 3 ) ;
memcpy ( V_1 + 5 , V_4 -> V_5 + 3 , 3 ) ;
if ( V_2 < 0x1000 ) {
V_1 [ 3 ] = V_2 >> 8 ;
V_1 [ 4 ] = V_2 & 0xff ;
} else {
V_1 [ 3 ] = 0xff ;
V_1 [ 4 ] = 0xfe ;
}
V_1 [ 0 ] ^= 2 ;
}
static void F_2 ( struct V_3 * V_4 , union V_6 * V_7 )
{
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
V_7 -> V_8 [ 0 ] = 0xFE ;
V_7 -> V_8 [ 1 ] = 0x80 ;
F_1 ( & V_7 -> V_8 [ 8 ] , 0xffff , V_4 ) ;
}
int F_3 ( struct V_9 * V_10 , T_1 V_11 , int V_12 )
{
return V_12 * V_10 -> V_13 . V_14 + V_11 ;
}
static int F_4 ( struct V_9 * V_10 , T_1 V_11 , int V_12 ,
union V_6 * V_7 )
{
struct V_15 * V_4 = & V_10 -> V_16 -> V_4 ;
T_1 V_17 = 0 ;
if ( V_12 >= V_10 -> V_13 . V_18 [ V_11 ] ) {
F_5 ( V_4 , L_1 ,
V_12 , V_11 , V_10 -> V_13 . V_18 [ V_11 ] - 1 ) ;
return - V_19 ;
}
V_17 = F_3 ( V_10 , V_11 , V_12 ) ;
if ( ! memcmp ( V_7 , & V_10 -> V_20 . V_21 [ V_17 ] , sizeof( * V_7 ) ) )
return - V_19 ;
memcpy ( & V_10 -> V_20 . V_21 [ V_17 ] , V_7 , sizeof( * V_7 ) ) ;
V_10 -> V_22 -> V_23 ( V_10 , V_11 , V_12 , V_7 ) ;
return 0 ;
}
static void F_6 ( struct V_9 * V_10 , T_1 V_11 , T_1 * V_24 )
{
T_1 V_25 ;
T_3 V_26 = 0 ;
if ( ! memcmp ( V_10 -> V_5 [ V_11 ] , V_24 , V_27 ) )
return;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ )
V_10 -> V_5 [ V_11 ] [ V_26 ] = V_24 [ V_26 ] ;
V_25 = V_10 -> V_20 . V_25 [ V_11 ] ;
V_10 -> V_22 -> V_28 ( V_10 , V_25 , V_24 ) ;
}
static void F_7 ( struct V_9 * V_10 , T_1 V_11 , int V_29 )
{
T_1 V_25 = V_10 -> V_20 . V_25 [ V_11 ] ;
enum V_30 V_31 ;
V_31 = F_8 ( V_29 ) ;
if ( ! V_31 )
V_31 = V_32 ;
V_10 -> V_22 -> V_33 ( V_10 , V_25 , V_31 ) ;
}
static void F_9 ( struct V_9 * V_10 , int V_11 )
{
struct V_34 V_35 ;
V_35 . V_15 = & V_10 -> V_36 ;
V_35 . V_37 . V_38 = V_11 + 1 ;
V_35 . V_35 = V_39 ;
F_10 ( & V_35 ) ;
}
static int F_11 ( struct V_9 * V_10 , T_1 V_11 ,
unsigned long V_35 )
{
struct V_15 * V_4 = & V_10 -> V_16 -> V_4 ;
struct V_3 * V_40 ;
unsigned long V_41 ;
union V_6 V_7 ;
int V_42 = 0 ;
V_40 = V_10 -> V_20 . V_43 [ V_11 ] ;
if ( ! V_40 ) {
F_5 ( V_4 , L_2 , V_11 ) ;
return - V_44 ;
}
F_12 ( & V_10 -> V_20 . V_45 , V_41 ) ;
switch ( V_35 ) {
case V_46 :
case V_47 :
case V_48 :
case V_49 :
F_6 ( V_10 , V_11 , V_40 -> V_5 ) ;
F_2 ( V_40 , & V_7 ) ;
V_42 = F_4 ( V_10 , V_11 , 0 , & V_7 ) ;
if ( ! V_42 )
F_9 ( V_10 , V_11 ) ;
break;
case V_50 :
break;
default:
F_13 ( V_4 , L_3 , ( T_3 ) ( V_35 ) ) ;
break;
}
F_14 ( & V_10 -> V_20 . V_45 , V_41 ) ;
return V_42 ;
}
static int F_15 ( struct V_51 * V_52 ,
unsigned long V_35 , void * V_53 )
{
struct V_3 * V_4 = F_16 ( V_53 ) ;
struct V_54 * V_20 = NULL ;
struct V_9 * V_10 = NULL ;
T_1 V_11 = 0 ;
int V_42 = 0 ;
V_10 = F_17 ( V_52 , struct V_9 , V_20 . V_55 ) ;
V_20 = & V_10 -> V_20 ;
for ( V_11 = 0 ; V_11 < V_10 -> V_13 . V_14 ; V_11 ++ ) {
if ( V_4 == V_20 -> V_43 [ V_11 ] ) {
V_42 = F_11 ( V_10 , V_11 , V_35 ) ;
if ( V_42 )
return V_56 ;
break;
}
}
return V_56 ;
}
static void F_18 ( int V_35 , struct V_3 * V_57 ,
struct V_9 * V_10 , union V_6 * V_7 )
{
struct V_54 * V_20 = NULL ;
int V_18 = 0 ;
unsigned long V_41 ;
union V_6 V_58 ;
T_1 V_17 = 0 ;
T_1 V_11 = 0 ;
int V_26 = 0 ;
int free ;
struct V_3 * V_59 = F_19 ( V_57 ) ?
F_19 ( V_57 ) :
V_57 ;
if ( V_35 != V_46 && V_35 != V_50 )
return;
V_20 = & V_10 -> V_20 ;
while ( V_11 < V_10 -> V_13 . V_14 ) {
if ( V_59 == V_20 -> V_43 [ V_11 ] )
break;
V_11 ++ ;
}
if ( V_11 >= V_10 -> V_13 . V_14 ) {
F_13 ( & V_10 -> V_16 -> V_4 , L_4 ) ;
return;
}
memset ( V_58 . V_8 , 0 , sizeof( V_58 . V_8 ) ) ;
free = - 1 ;
V_18 = V_10 -> V_13 . V_18 [ V_11 ] ;
F_12 ( & V_10 -> V_20 . V_45 , V_41 ) ;
for ( V_26 = 0 ; V_26 < V_18 ; V_26 ++ ) {
V_17 = F_3 ( V_10 , V_11 , V_26 ) ;
if ( ! memcmp ( V_7 -> V_8 , V_20 -> V_21 [ V_17 ] . V_8 ,
sizeof( V_7 -> V_8 ) ) )
break;
if ( free < 0 && ! memcmp ( V_58 . V_8 ,
V_20 -> V_21 [ V_17 ] . V_8 , sizeof( V_58 . V_8 ) ) )
free = V_26 ;
}
if ( V_26 >= V_18 ) {
if ( free < 0 ) {
F_14 ( & V_10 -> V_20 . V_45 , V_41 ) ;
F_13 ( & V_10 -> V_16 -> V_4 ,
L_5 , V_11 ) ;
return;
}
if ( ! F_4 ( V_10 , V_11 , free , V_7 ) )
F_9 ( V_10 , V_11 ) ;
} else if ( V_35 == V_50 ) {
if ( ! F_4 ( V_10 , V_11 , V_26 , & V_58 ) )
F_9 ( V_10 , V_11 ) ;
}
F_14 ( & V_10 -> V_20 . V_45 , V_41 ) ;
}
static int F_20 ( struct V_51 * V_52 , unsigned long V_35 ,
void * V_53 )
{
struct V_60 * V_61 = V_53 ;
struct V_9 * V_10 ;
struct V_3 * V_4 = V_61 -> V_62 -> V_4 ;
union V_6 V_7 ;
F_21 ( V_61 -> V_63 , (struct V_64 * ) & V_7 ) ;
V_10 = F_17 ( V_52 , struct V_9 , V_20 . V_65 ) ;
F_18 ( V_35 , V_4 , V_10 , & V_7 ) ;
return V_56 ;
}
static int F_22 ( struct V_9 * V_10 )
{
struct V_60 * V_66 = NULL ;
union V_6 V_7 = { { 0 } } ;
T_3 V_67 = 0 ;
int V_68 = 0 ;
int V_42 = 0 ;
T_1 V_26 = 0 ;
for ( V_26 = 0 ; V_26 < V_10 -> V_13 . V_14 ; V_26 ++ ) {
F_7 ( V_10 , V_26 ,
F_23 ( V_10 -> V_13 . V_69 ) ) ;
F_6 ( V_10 , V_26 , V_10 -> V_20 . V_43 [ V_26 ] -> V_5 ) ;
if ( V_10 -> V_20 . V_43 [ V_26 ] -> V_70 ) {
V_66 = V_10 -> V_20 . V_43 [ V_26 ] -> V_70 -> V_66 ;
V_68 = 1 ;
while ( V_66 ) {
V_67 = V_66 -> V_63 ;
F_21 ( V_67 ,
(struct V_64 * ) & V_7 ) ;
V_42 = F_4 ( V_10 , V_26 , V_68 , & V_7 ) ;
if ( V_42 )
break;
V_68 ++ ;
V_66 = V_66 -> V_71 ;
}
F_9 ( V_10 , V_26 ) ;
}
}
return V_42 ;
}
static int F_24 ( struct V_72 * V_36 ,
struct V_73 * V_74 ,
struct V_75 * V_76 )
{
struct V_9 * V_10 = F_25 ( V_36 ) ;
memset ( V_74 , 0 , sizeof( * V_74 ) ) ;
V_74 -> V_77 = V_10 -> V_77 ;
V_74 -> V_78 = ( V_79 ) ( ~ ( 0ULL ) ) ;
V_74 -> V_80 = V_10 -> V_13 . V_80 ;
V_74 -> V_81 = V_10 -> V_81 ;
V_74 -> V_82 = V_10 -> V_82 ;
V_74 -> V_83 = V_10 -> V_84 ;
V_74 -> V_85 = V_10 -> V_13 . V_86 ;
V_74 -> V_87 = V_10 -> V_13 . V_88 ;
V_74 -> V_89 = V_90 |
V_91 ;
V_74 -> V_92 = V_10 -> V_13 . V_93 ;
V_74 -> V_94 = 1 ;
V_74 -> V_95 = V_10 -> V_13 . V_96 ;
V_74 -> V_97 = V_10 -> V_13 . V_98 ;
V_74 -> V_99 = V_10 -> V_13 . V_100 ;
V_74 -> V_101 = V_10 -> V_13 . V_102 ;
V_74 -> V_103 = V_10 -> V_13 . V_104 ;
V_74 -> V_105 = V_10 -> V_13 . V_106 ;
V_74 -> V_107 = V_108 ;
V_74 -> V_109 = 1 ;
V_74 -> V_110 = V_10 -> V_13 . V_110 ;
return 0 ;
}
static struct V_3 * F_26 ( struct V_72 * V_36 ,
T_1 V_38 )
{
struct V_9 * V_10 = F_25 ( V_36 ) ;
struct V_3 * V_111 ;
if ( V_38 < 1 || V_38 > V_10 -> V_13 . V_14 )
return NULL ;
F_27 () ;
V_111 = V_10 -> V_20 . V_43 [ V_38 - 1 ] ;
if ( V_111 )
F_28 ( V_111 ) ;
F_29 () ;
return V_111 ;
}
static int F_30 ( struct V_72 * V_36 , T_1 V_38 ,
struct V_112 * V_74 )
{
struct V_9 * V_10 = F_25 ( V_36 ) ;
struct V_15 * V_4 = & V_10 -> V_16 -> V_4 ;
struct V_3 * V_113 ;
unsigned long V_41 ;
enum V_30 V_29 ;
T_1 V_11 ;
assert ( V_38 > 0 ) ;
V_11 = V_38 - 1 ;
memset ( V_74 , 0 , sizeof( * V_74 ) ) ;
V_74 -> V_69 = V_10 -> V_13 . V_69 ;
V_74 -> V_114 = V_10 -> V_13 . V_18 [ V_11 ] ;
V_74 -> V_115 = V_116 | V_117 |
V_118 |
V_119 ;
V_74 -> V_120 = V_121 ;
V_74 -> V_122 = 1 ;
V_74 -> V_123 = V_124 ;
V_74 -> V_125 = 1 ;
F_12 ( & V_10 -> V_20 . V_45 , V_41 ) ;
V_113 = V_10 -> V_20 . V_43 [ V_11 ] ;
if ( ! V_113 ) {
F_14 ( & V_10 -> V_20 . V_45 , V_41 ) ;
F_5 ( V_4 , L_6 , V_11 ) ;
return - V_19 ;
}
V_29 = F_8 ( V_113 -> V_29 ) ;
V_74 -> V_126 = V_29 ? F_31 ( V_74 -> V_69 , V_29 ) : V_32 ;
V_74 -> V_127 = ( F_32 ( V_113 ) && F_33 ( V_113 ) ) ?
V_128 : V_129 ;
V_74 -> V_130 = ( V_74 -> V_127 == V_128 ) ? 5 : 3 ;
F_14 ( & V_10 -> V_20 . V_45 , V_41 ) ;
return 0 ;
}
static enum V_131 F_34 ( struct V_72 * V_15 ,
T_1 V_38 )
{
return V_132 ;
}
static int F_35 ( struct V_72 * V_36 , T_1 V_38 , int V_68 ,
union V_6 * V_7 )
{
struct V_9 * V_10 = F_25 ( V_36 ) ;
struct V_15 * V_4 = & V_10 -> V_16 -> V_4 ;
T_1 V_17 = 0 ;
T_1 V_11 ;
if ( V_38 < 1 || V_38 > V_10 -> V_13 . V_14 ||
V_68 >= V_10 -> V_13 . V_18 [ V_38 - 1 ] ) {
F_5 ( V_4 ,
L_7 ,
V_38 , V_68 , V_10 -> V_13 . V_14 ,
V_10 -> V_13 . V_18 [ V_38 - 1 ] - 1 ) ;
return - V_19 ;
}
V_11 = V_38 - 1 ;
V_17 = F_3 ( V_10 , V_11 , V_68 ) ;
if ( V_17 >= V_133 ) {
F_5 ( V_4 , L_8 ,
V_38 , V_68 , V_133 ) ;
return - V_19 ;
}
memcpy ( V_7 -> V_8 , V_10 -> V_20 . V_21 [ V_17 ] . V_8 ,
V_134 ) ;
return 0 ;
}
static int F_36 ( struct V_72 * V_36 , T_1 V_11 , T_2 V_68 ,
T_2 * V_135 )
{
* V_135 = V_136 ;
return 0 ;
}
static int F_37 ( struct V_72 * V_36 , int V_137 ,
struct V_138 * V_74 )
{
unsigned long V_41 ;
if ( V_137 & ~ V_139 )
return - V_140 ;
if ( V_137 & V_139 ) {
F_12 ( & F_25 ( V_36 ) -> V_141 , V_41 ) ;
memcpy ( V_36 -> V_142 , V_74 -> V_142 , V_143 ) ;
F_14 ( & F_25 ( V_36 ) -> V_141 , V_41 ) ;
}
return 0 ;
}
static int F_38 ( struct V_72 * V_36 , T_1 V_38 , int V_137 ,
struct V_144 * V_74 )
{
return 0 ;
}
static struct V_145 * F_39 ( struct V_72 * V_36 ,
struct V_75 * V_146 )
{
int V_42 = 0 ;
struct V_147 * V_148 ;
struct V_149 V_150 ;
struct V_9 * V_10 = F_25 ( V_36 ) ;
V_150 . V_151 = V_10 -> V_13 . V_86 ;
V_148 = F_40 ( sizeof( * V_148 ) , V_152 ) ;
if ( ! V_148 )
return F_41 ( - V_153 ) ;
V_42 = F_42 ( V_10 , & V_148 -> V_154 ) ;
if ( V_42 )
goto V_155;
V_42 = F_43 ( V_146 , & V_150 , sizeof( V_150 ) ) ;
if ( V_42 )
goto V_156;
return & V_148 -> V_157 ;
V_156:
F_44 ( V_10 , & V_148 -> V_154 ) ;
V_155:
F_45 ( V_148 ) ;
return F_41 ( V_42 ) ;
}
static int F_46 ( struct V_145 * V_158 )
{
struct V_147 * V_148 = F_47 ( V_158 ) ;
F_44 ( F_25 ( V_158 -> V_15 ) , & V_148 -> V_154 ) ;
F_45 ( V_148 ) ;
return 0 ;
}
static int F_48 ( struct V_145 * V_148 ,
struct V_159 * V_160 )
{
if ( ( ( V_160 -> V_161 - V_160 -> V_162 ) % V_163 ) != 0 )
return - V_19 ;
if ( V_160 -> V_164 == 0 ) {
V_160 -> V_165 = F_49 ( V_160 -> V_165 ) ;
if ( F_50 ( V_160 , V_160 -> V_162 ,
F_47 ( V_148 ) -> V_154 . V_166 ,
V_163 , V_160 -> V_165 ) )
return - V_167 ;
} else {
return - V_19 ;
}
return 0 ;
}
static int F_51 ( struct V_72 * V_36 , T_1 V_38 ,
struct V_168 * V_169 )
{
struct V_112 V_170 ;
int V_42 ;
V_42 = F_30 ( V_36 , V_38 , & V_170 ) ;
if ( V_42 )
return V_42 ;
V_169 -> V_122 = V_170 . V_122 ;
V_169 -> V_114 = V_170 . V_114 ;
V_169 -> V_171 = V_172 ;
V_169 -> V_173 = V_174 ;
return 0 ;
}
static void F_52 ( struct V_9 * V_10 )
{
struct V_54 * V_20 = & V_10 -> V_20 ;
F_53 ( & V_20 -> V_65 ) ;
F_54 ( & V_20 -> V_55 ) ;
F_55 ( & V_10 -> V_36 ) ;
}
static int F_56 ( struct V_9 * V_10 )
{
int V_42 ;
struct V_54 * V_20 = NULL ;
struct V_72 * V_36 = NULL ;
struct V_15 * V_4 = & V_10 -> V_16 -> V_4 ;
V_20 = & V_10 -> V_20 ;
F_57 ( & V_20 -> V_45 ) ;
V_36 = & V_10 -> V_36 ;
F_58 ( V_36 -> V_175 , L_9 , V_176 ) ;
V_36 -> V_177 = V_178 ;
V_36 -> V_179 = V_180 ;
V_36 -> V_181 = V_4 ;
V_36 -> V_182 = V_10 -> V_13 . V_14 ;
V_36 -> V_183 = V_10 -> V_13 . V_184 ;
V_36 -> V_185 = V_10 -> V_13 . V_185 ;
V_36 -> V_186 = 1 ;
V_36 -> V_187 =
( 1ULL << V_188 ) |
( 1ULL << V_189 ) |
( 1ULL << V_190 ) |
( 1ULL << V_191 ) |
( 1ULL << V_192 ) |
( 1ULL << V_193 ) |
( 1ULL << V_194 ) |
( 1ULL << V_195 ) |
( 1ULL << V_196 ) |
( 1ULL << V_197 ) |
( 1ULL << V_198 ) |
( 1ULL << V_199 ) |
( 1ULL << V_200 ) |
( 1ULL << V_201 ) ;
V_36 -> V_202 = F_37 ;
V_36 -> V_203 = F_24 ;
V_36 -> V_204 = F_30 ;
V_36 -> V_205 = F_38 ;
V_36 -> V_206 = F_34 ;
V_36 -> V_207 = F_26 ;
V_36 -> V_208 = F_35 ;
V_36 -> V_209 = F_36 ;
V_36 -> V_210 = F_39 ;
V_36 -> V_211 = F_46 ;
V_36 -> V_212 = F_48 ;
V_36 -> V_213 = V_214 ;
V_36 -> V_215 = V_216 ;
V_36 -> V_217 = V_218 ;
V_36 -> V_219 = V_220 ;
V_36 -> V_221 = V_222 ;
V_36 -> V_223 = V_224 ;
V_36 -> V_225 = V_226 ;
V_36 -> V_227 = V_10 -> V_22 -> V_227 ;
V_36 -> V_228 = V_10 -> V_22 -> V_228 ;
V_36 -> V_229 = V_10 -> V_22 -> V_229 ;
V_36 -> V_230 = V_10 -> V_22 -> V_230 ;
V_36 -> V_231 = V_232 ;
V_36 -> V_233 = V_234 ;
V_36 -> V_235 = V_10 -> V_22 -> V_235 ;
V_36 -> V_236 = V_10 -> V_22 -> V_236 ;
V_36 -> V_237 = V_238 ;
V_36 -> V_239 = V_240 ;
V_36 -> V_241 = V_242 ;
V_36 -> V_243 = F_51 ;
V_42 = F_59 ( V_36 , NULL ) ;
if ( V_42 ) {
F_5 ( V_4 , L_10 ) ;
return V_42 ;
}
V_42 = F_22 ( V_10 ) ;
if ( V_42 ) {
F_5 ( V_4 , L_11 ) ;
goto V_244;
}
V_20 -> V_55 . V_245 = F_15 ;
V_42 = F_60 ( & V_20 -> V_55 ) ;
if ( V_42 ) {
F_5 ( V_4 , L_12 ) ;
goto V_244;
}
V_20 -> V_65 . V_245 = F_20 ;
V_42 = F_61 ( & V_20 -> V_65 ) ;
if ( V_42 ) {
F_5 ( V_4 , L_13 ) ;
goto V_246;
}
return 0 ;
V_246:
F_54 ( & V_20 -> V_55 ) ;
V_244:
F_55 ( V_36 ) ;
return V_42 ;
}
static int F_62 ( struct V_15 * V_4 , void * V_247 )
{
return V_4 -> V_247 == V_247 ;
}
static struct
V_248 * F_63 ( struct V_249 * V_247 )
{
struct V_15 * V_4 ;
V_4 = F_64 ( & V_250 , NULL ,
V_247 , F_62 ) ;
return V_4 ? F_65 ( V_4 ) : NULL ;
}
static int F_66 ( struct V_9 * V_10 )
{
int V_26 ;
int V_42 ;
T_1 V_25 ;
int V_251 = 0 ;
struct V_15 * V_4 = & V_10 -> V_16 -> V_4 ;
struct V_252 * V_253 ;
struct V_3 * V_40 = NULL ;
struct V_248 * V_16 = NULL ;
struct V_254 * V_255 ;
if ( F_67 ( V_4 ) ) {
const struct V_256 * V_257 ;
V_257 = F_68 ( V_258 , V_4 -> V_259 ) ;
if ( ! V_257 ) {
F_5 ( V_4 , L_14 ) ;
return - V_260 ;
}
V_10 -> V_22 = (struct V_261 * ) V_257 -> V_262 ;
if ( ! V_10 -> V_22 ) {
F_5 ( V_4 , L_15 ) ;
return - V_260 ;
}
} else if ( F_69 ( V_4 -> V_247 ) ) {
const struct V_263 * V_264 ;
V_264 = F_70 ( V_265 , V_4 ) ;
if ( ! V_264 ) {
F_5 ( V_4 , L_14 ) ;
return - V_260 ;
}
V_10 -> V_22 = (struct V_261 * ) V_264 -> V_266 ;
if ( ! V_10 -> V_22 ) {
F_5 ( V_4 , L_16 ) ;
return - V_260 ;
}
} else {
F_5 ( V_4 , L_17 ) ;
return - V_260 ;
}
V_255 = F_71 ( V_10 -> V_16 , V_267 , 0 ) ;
if ( ! V_255 ) {
F_5 ( V_4 , L_18 ) ;
return - V_19 ;
}
V_10 -> V_268 = F_72 ( V_4 , V_255 ) ;
if ( F_73 ( V_10 -> V_268 ) )
return F_74 ( V_10 -> V_268 ) ;
V_42 = F_75 ( V_4 , L_19 ,
( T_1 * ) & V_10 -> V_36 . V_269 ,
V_270 ) ;
if ( V_42 ) {
F_5 ( V_4 , L_20 ) ;
return V_42 ;
}
for ( V_26 = 0 ; V_26 < V_271 ; V_26 ++ ) {
if ( F_67 ( V_4 ) ) {
V_253 = F_76 ( V_4 -> V_259 , L_21 ,
V_26 ) ;
if ( ! V_253 )
continue;
V_16 = F_77 ( V_253 ) ;
} else if ( F_69 ( V_4 -> V_247 ) ) {
struct V_272 args ;
struct V_249 * V_247 ;
V_42 = F_78 ( V_4 -> V_247 ,
L_21 ,
V_26 , & args ) ;
if ( V_42 )
continue;
V_247 = F_79 ( args . V_273 ) ;
V_16 = F_63 ( V_247 ) ;
} else {
F_5 ( V_4 , L_22 ) ;
return - V_260 ;
}
if ( V_16 ) {
V_40 = F_80 ( V_16 ) ;
V_25 = ( T_1 ) V_26 ;
if ( V_40 ) {
V_10 -> V_20 . V_43 [ V_251 ] = V_40 ;
V_10 -> V_20 . V_25 [ V_251 ] = V_25 ;
} else {
F_5 ( V_4 , L_23 ,
V_16 -> V_175 ) ;
return - V_44 ;
}
V_251 ++ ;
}
}
if ( V_251 == 0 ) {
F_5 ( V_4 , L_24 ) ;
return - V_19 ;
}
V_10 -> V_13 . V_14 = V_251 ;
V_10 -> V_274 = 1 ;
V_10 -> V_275 = 0 ;
V_42 = F_81 ( V_4 , L_25 ,
V_10 -> V_276 ,
V_277 ) ;
if ( V_42 < 0 ) {
F_5 ( V_4 , L_26 ) ;
return V_42 ;
}
for ( V_26 = 0 ; V_26 < V_277 ; V_26 ++ ) {
V_10 -> V_278 [ V_26 ] = F_82 ( V_10 -> V_16 , V_26 ) ;
if ( V_10 -> V_278 [ V_26 ] <= 0 ) {
F_5 ( V_4 , L_27 , V_26 ) ;
return - V_19 ;
}
}
return 0 ;
}
static int F_83 ( struct V_9 * V_10 )
{
int V_42 ;
struct V_15 * V_4 = & V_10 -> V_16 -> V_4 ;
V_42 = F_84 ( V_10 , & V_10 -> V_279 . V_280 ,
V_281 , V_10 -> V_13 . V_282 ,
V_10 -> V_13 . V_283 , 1 ) ;
if ( V_42 ) {
F_5 ( V_4 , L_28 ) ;
return V_42 ;
}
V_42 = F_84 ( V_10 , & V_10 -> V_279 . V_284 ,
V_285 , V_10 -> V_13 . V_286 ,
V_10 -> V_13 . V_100 , 1 ) ;
if ( V_42 ) {
F_5 ( V_4 , L_29 ) ;
goto V_287;
}
V_42 = F_84 ( V_10 , & V_10 -> V_288 . V_288 ,
V_289 , V_10 -> V_13 . V_290 ,
V_10 -> V_13 . V_86 , 1 ) ;
if ( V_42 ) {
F_5 ( V_4 , L_30 ) ;
goto V_291;
}
V_42 = F_84 ( V_10 , & V_10 -> V_288 . V_292 ,
V_293 ,
V_10 -> V_13 . V_294 *
V_10 -> V_13 . V_106 ,
V_10 -> V_13 . V_86 , 1 ) ;
if ( V_42 ) {
F_5 ( V_4 , L_31 ) ;
goto V_295;
}
V_42 = F_84 ( V_10 , & V_10 -> V_296 . V_297 ,
V_298 , V_10 -> V_13 . V_299 ,
V_10 -> V_13 . V_96 , 1 ) ;
if ( V_42 ) {
F_5 ( V_4 , L_32 ) ;
goto V_300;
}
return 0 ;
V_300:
F_85 ( V_10 , & V_10 -> V_288 . V_292 ) ;
V_295:
F_85 ( V_10 , & V_10 -> V_288 . V_288 ) ;
V_291:
F_85 ( V_10 , & V_10 -> V_279 . V_284 ) ;
V_287:
F_85 ( V_10 , & V_10 -> V_279 . V_280 ) ;
return V_42 ;
}
static int F_86 ( struct V_9 * V_10 )
{
int V_42 ;
struct V_15 * V_4 = & V_10 -> V_16 -> V_4 ;
F_57 ( & V_10 -> V_141 ) ;
F_57 ( & V_10 -> V_301 ) ;
V_42 = F_87 ( V_10 ) ;
if ( V_42 ) {
F_5 ( V_4 , L_33 ) ;
return V_42 ;
}
V_42 = F_42 ( V_10 , & V_10 -> V_302 ) ;
if ( V_42 ) {
F_5 ( V_4 , L_34 ) ;
goto V_303;
}
V_42 = F_88 ( V_10 ) ;
if ( V_42 ) {
F_5 ( V_4 , L_35 ) ;
goto V_304;
}
V_42 = F_89 ( V_10 ) ;
if ( V_42 ) {
F_5 ( V_4 , L_36 ) ;
goto V_305;
}
V_42 = F_90 ( V_10 ) ;
if ( V_42 ) {
F_5 ( V_4 , L_37 ) ;
goto V_306;
}
V_42 = F_91 ( V_10 ) ;
if ( V_42 ) {
F_5 ( V_4 , L_38 ) ;
goto V_307;
}
return 0 ;
V_307:
F_92 ( V_10 ) ;
V_306:
F_93 ( V_10 ) ;
V_305:
F_94 ( V_10 ) ;
V_304:
F_44 ( V_10 , & V_10 -> V_302 ) ;
V_303:
F_95 ( V_10 ) ;
return V_42 ;
}
static int F_96 ( struct V_248 * V_16 )
{
int V_42 ;
struct V_9 * V_10 ;
struct V_15 * V_4 = & V_16 -> V_4 ;
V_10 = (struct V_9 * ) F_97 ( sizeof( * V_10 ) ) ;
if ( ! V_10 )
return - V_153 ;
memset ( ( T_1 * ) V_10 + sizeof( struct V_72 ) , 0 ,
sizeof( struct V_9 ) - sizeof( struct V_72 ) ) ;
V_10 -> V_16 = V_16 ;
F_98 ( V_16 , V_10 ) ;
if ( F_99 ( V_4 , F_100 ( 64ULL ) ) &&
F_99 ( V_4 , F_100 ( 32ULL ) ) ) {
F_5 ( V_4 , L_39 ) ;
V_42 = - V_308 ;
goto V_309;
}
V_42 = F_66 ( V_10 ) ;
if ( V_42 ) {
F_5 ( V_4 , L_40 ) ;
goto V_309;
}
V_42 = V_10 -> V_22 -> V_310 ( V_10 , true ) ;
if ( V_42 ) {
F_5 ( V_4 , L_41 ) ;
goto V_309;
}
V_10 -> V_22 -> V_311 ( V_10 ) ;
V_42 = F_101 ( V_10 ) ;
if ( V_42 ) {
F_5 ( V_4 , L_42 ) ;
goto V_312;
}
V_42 = F_102 ( V_10 ) ;
if ( V_42 ) {
F_5 ( V_4 , L_43 ) ;
goto V_313;
}
if ( V_10 -> V_274 ) {
V_42 = F_103 ( V_10 ) ;
if ( V_42 ) {
F_5 ( V_4 , L_44 ) ;
goto V_314;
}
}
V_42 = F_83 ( V_10 ) ;
if ( V_42 ) {
F_5 ( V_4 , L_45 ) ;
goto V_315;
}
V_42 = F_86 ( V_10 ) ;
if ( V_42 ) {
F_5 ( V_4 , L_46 ) ;
goto V_316;
}
V_42 = V_10 -> V_22 -> V_317 ( V_10 ) ;
if ( V_42 ) {
F_5 ( V_4 , L_47 ) ;
goto V_318;
}
V_42 = F_56 ( V_10 ) ;
if ( V_42 )
goto V_319;
return 0 ;
V_319:
V_10 -> V_22 -> V_320 ( V_10 ) ;
V_318:
F_104 ( V_10 ) ;
V_316:
F_105 ( V_10 ) ;
V_315:
if ( V_10 -> V_274 )
F_106 ( V_10 ) ;
V_314:
F_107 ( V_10 ) ;
V_313:
F_108 ( V_10 ) ;
V_312:
V_42 = V_10 -> V_22 -> V_310 ( V_10 , false ) ;
if ( V_42 )
F_5 ( & V_10 -> V_16 -> V_4 , L_48 ) ;
V_309:
F_109 ( & V_10 -> V_36 ) ;
return V_42 ;
}
static int F_110 ( struct V_248 * V_16 )
{
struct V_9 * V_10 = F_80 ( V_16 ) ;
F_52 ( V_10 ) ;
V_10 -> V_22 -> V_320 ( V_10 ) ;
F_104 ( V_10 ) ;
F_105 ( V_10 ) ;
if ( V_10 -> V_274 )
F_106 ( V_10 ) ;
F_107 ( V_10 ) ;
F_108 ( V_10 ) ;
V_10 -> V_22 -> V_310 ( V_10 , false ) ;
F_109 ( & V_10 -> V_36 ) ;
return 0 ;
}
