void F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
T_1 V_4 [ 6 ] ;
memcpy ( & V_4 [ 0 ] , & V_2 -> V_5 . V_4 [ 0 ] , V_6 ) ;
V_3 [ 0 ] = V_4 [ 0 ] ^ 2 ;
V_3 [ 1 ] = V_4 [ 1 ] ;
V_3 [ 2 ] = V_4 [ 2 ] ;
V_3 [ 3 ] = 0xff ;
V_3 [ 4 ] = 0xfe ;
V_3 [ 5 ] = V_4 [ 3 ] ;
V_3 [ 6 ] = V_4 [ 4 ] ;
V_3 [ 7 ] = V_4 [ 5 ] ;
}
static bool F_2 ( struct V_1 * V_2 , union V_7 * V_8 )
{
int V_9 ;
unsigned long V_10 ;
memset ( & V_11 , 0 , sizeof( union V_7 ) ) ;
F_3 ( & V_2 -> V_12 , V_10 ) ;
for ( V_9 = 0 ; V_9 < V_13 ; V_9 ++ ) {
if ( ! memcmp ( & V_2 -> V_14 [ V_9 ] , & V_11 ,
sizeof( union V_7 ) ) ) {
memcpy ( & V_2 -> V_14 [ V_9 ] , V_8 ,
sizeof( union V_7 ) ) ;
F_4 ( & V_2 -> V_12 , V_10 ) ;
return true ;
} else if ( ! memcmp ( & V_2 -> V_14 [ V_9 ] , V_8 ,
sizeof( union V_7 ) ) ) {
F_4 ( & V_2 -> V_12 , V_10 ) ;
return false ;
}
}
F_4 ( & V_2 -> V_12 , V_10 ) ;
return false ;
}
static bool F_5 ( struct V_1 * V_2 , union V_7 * V_15 )
{
int V_16 = false ;
int V_9 ;
unsigned long V_10 ;
F_3 ( & V_2 -> V_12 , V_10 ) ;
for ( V_9 = 1 ; V_9 < V_13 ; V_9 ++ ) {
if ( ! memcmp ( & V_2 -> V_14 [ V_9 ] , V_15 , sizeof( union V_7 ) ) ) {
memset ( & V_2 -> V_14 [ V_9 ] , 0 , sizeof( union V_7 ) ) ;
V_16 = true ;
break;
}
}
F_4 ( & V_2 -> V_12 , V_10 ) ;
return V_16 ;
}
static int F_6 ( unsigned long V_17 , struct V_18 * V_19 ,
union V_7 * V_20 )
{
struct V_21 V_22 ;
struct V_1 * V_2 ;
bool V_16 = false ;
bool V_23 = false ;
bool V_24 = false ;
V_24 = V_19 -> V_25 & V_26 ;
if ( V_24 )
V_19 = F_7 ( V_19 ) ;
F_8 () ;
F_9 (dev, &ocrdma_dev_list, entry) {
if ( V_2 -> V_5 . V_19 == V_19 ) {
V_16 = true ;
break;
}
}
F_10 () ;
if ( ! V_16 )
return V_27 ;
F_11 ( & V_2 -> V_28 ) ;
switch ( V_17 ) {
case V_29 :
V_23 = F_2 ( V_2 , V_20 ) ;
break;
case V_30 :
V_23 = F_5 ( V_2 , V_20 ) ;
break;
default:
break;
}
if ( V_23 ) {
V_22 . V_31 = & V_2 -> V_32 ;
V_22 . V_33 . V_34 = 1 ;
V_22 . V_17 = V_35 ;
F_12 ( & V_22 ) ;
}
F_13 ( & V_2 -> V_28 ) ;
return V_36 ;
}
static int F_14 ( struct V_37 * V_38 ,
unsigned long V_17 , void * V_39 )
{
struct V_40 * V_41 = V_39 ;
union V_7 V_20 ;
struct V_18 * V_19 = V_41 -> V_42 -> V_2 ;
F_15 ( V_41 -> V_43 , (struct V_44 * ) & V_20 ) ;
return F_6 ( V_17 , V_19 , & V_20 ) ;
}
static int F_16 ( struct V_37 * V_38 ,
unsigned long V_17 , void * V_39 )
{
struct V_45 * V_41 = (struct V_45 * ) V_39 ;
union V_7 * V_20 = (union V_7 * ) & V_41 -> V_46 ;
struct V_18 * V_19 = V_41 -> V_47 -> V_2 ;
return F_6 ( V_17 , V_19 , V_20 ) ;
}
static enum V_48 F_17 ( struct V_49 * V_31 ,
T_1 V_34 )
{
return V_50 ;
}
static int F_18 ( struct V_49 * V_32 , T_1 V_34 ,
struct V_51 * V_52 )
{
struct V_53 V_54 ;
int V_55 ;
V_55 = F_19 ( V_32 , V_34 , & V_54 ) ;
if ( V_55 )
return V_55 ;
V_52 -> V_56 = V_54 . V_56 ;
V_52 -> V_57 = V_54 . V_57 ;
V_52 -> V_58 = V_59 ;
V_52 -> V_60 = V_61 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
F_21 ( V_2 -> V_32 . V_62 , L_1 , V_63 ) ;
F_1 ( V_2 , ( T_1 * ) & V_2 -> V_32 . V_64 ) ;
memcpy ( V_2 -> V_32 . V_65 , V_66 ,
sizeof( V_66 ) ) ;
V_2 -> V_32 . V_67 = V_68 ;
V_2 -> V_32 . V_69 = V_70 ;
V_2 -> V_32 . V_71 =
F_22 ( V_72 ) |
F_22 ( V_73 ) |
F_22 ( V_74 ) |
F_22 ( V_75 ) |
F_22 ( V_76 ) |
F_22 ( V_77 ) |
F_22 ( V_78 ) |
F_22 ( V_79 ) |
F_22 ( V_80 ) |
F_22 ( V_81 ) |
F_22 ( V_82 ) |
F_22 ( V_83 ) |
F_22 ( V_84 ) |
F_22 ( V_85 ) |
F_22 ( V_86 ) |
F_22 ( V_87 ) |
F_22 ( V_88 ) |
F_22 ( V_89 ) |
F_22 ( V_90 ) ;
V_2 -> V_32 . V_71 |=
F_22 ( V_91 ) |
F_22 ( V_92 ) |
F_22 ( V_93 ) |
F_22 ( V_94 ) ;
V_2 -> V_32 . V_95 = V_96 ;
V_2 -> V_32 . V_97 = 1 ;
V_2 -> V_32 . V_98 = V_2 -> V_99 ;
V_2 -> V_32 . V_100 = V_101 ;
V_2 -> V_32 . V_102 = F_19 ;
V_2 -> V_32 . V_103 = V_104 ;
V_2 -> V_32 . V_105 = V_106 ;
V_2 -> V_32 . V_107 = F_17 ;
V_2 -> V_32 . V_108 = V_109 ;
V_2 -> V_32 . V_110 = V_111 ;
V_2 -> V_32 . V_112 = V_113 ;
V_2 -> V_32 . V_114 = V_115 ;
V_2 -> V_32 . V_116 = V_117 ;
V_2 -> V_32 . V_118 = V_119 ;
V_2 -> V_32 . V_120 = V_121 ;
V_2 -> V_32 . V_122 = V_123 ;
V_2 -> V_32 . V_124 = V_125 ;
V_2 -> V_32 . V_126 = V_127 ;
V_2 -> V_32 . V_128 = V_129 ;
V_2 -> V_32 . V_130 = V_131 ;
V_2 -> V_32 . V_132 = V_133 ;
V_2 -> V_32 . V_134 = V_135 ;
V_2 -> V_32 . V_136 = V_137 ;
V_2 -> V_32 . V_138 = V_139 ;
V_2 -> V_32 . V_140 = V_141 ;
V_2 -> V_32 . V_142 = V_143 ;
V_2 -> V_32 . V_144 = V_145 ;
V_2 -> V_32 . V_146 = V_147 ;
V_2 -> V_32 . V_148 = V_149 ;
V_2 -> V_32 . V_150 = V_151 ;
V_2 -> V_32 . V_152 = V_153 ;
V_2 -> V_32 . V_154 = V_155 ;
V_2 -> V_32 . V_156 = V_157 ;
V_2 -> V_32 . V_158 = V_159 ;
V_2 -> V_32 . V_160 = V_161 ;
V_2 -> V_32 . V_162 = V_163 ;
V_2 -> V_32 . V_164 = & V_2 -> V_5 . V_165 -> V_2 ;
V_2 -> V_32 . V_166 = V_167 ;
V_2 -> V_32 . V_168 = F_18 ;
if ( F_23 ( V_2 ) == V_169 ) {
V_2 -> V_32 . V_71 |=
F_22 ( V_170 ) |
F_22 ( V_171 ) |
F_22 ( V_172 ) |
F_22 ( V_173 ) |
F_22 ( V_174 ) ;
V_2 -> V_32 . V_175 = V_176 ;
V_2 -> V_32 . V_177 = V_178 ;
V_2 -> V_32 . V_179 = V_180 ;
V_2 -> V_32 . V_181 = V_182 ;
V_2 -> V_32 . V_183 = V_184 ;
}
return F_24 ( & V_2 -> V_32 , NULL ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
F_26 ( & V_2 -> V_28 ) ;
V_2 -> V_14 = F_27 ( sizeof( union V_7 ) *
V_13 , V_185 ) ;
if ( ! V_2 -> V_14 )
goto V_186;
F_28 ( & V_2 -> V_12 ) ;
V_2 -> V_187 = F_27 ( sizeof( struct V_188 * ) *
V_189 , V_185 ) ;
if ( ! V_2 -> V_187 )
goto V_186;
if ( V_2 -> V_54 . V_190 ) {
V_2 -> V_191 = F_27 ( sizeof( struct V_192 * ) *
V_193 , V_185 ) ;
if ( ! V_2 -> V_191 )
goto V_186;
}
V_2 -> V_194 = F_27 ( sizeof( V_195 ) * V_196 , V_185 ) ;
if ( V_2 -> V_194 == NULL )
goto V_186;
F_29 ( V_2 ) ;
F_28 ( & V_2 -> V_197 . V_198 ) ;
F_28 ( & V_2 -> V_199 ) ;
return 0 ;
V_186:
F_30 ( L_2 , V_200 , V_2 -> V_201 ) ;
return - V_202 ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_32 ( V_2 -> V_194 ) ;
F_32 ( V_2 -> V_191 ) ;
F_32 ( V_2 -> V_187 ) ;
F_32 ( V_2 -> V_14 ) ;
}
static T_2 F_33 ( struct V_31 * V_31 , struct V_203 * V_54 ,
char * V_204 )
{
struct V_1 * V_2 = F_34 ( V_31 ) ;
return F_35 ( V_204 , V_205 , L_3 , V_2 -> V_5 . V_165 -> V_206 ) ;
}
static T_2 F_36 ( struct V_31 * V_31 , struct V_203 * V_54 ,
char * V_204 )
{
struct V_1 * V_2 = F_34 ( V_31 ) ;
return F_35 ( V_204 , V_205 , L_4 , & V_2 -> V_54 . V_207 [ 0 ] ) ;
}
static T_2 F_37 ( struct V_31 * V_31 ,
struct V_203 * V_54 , char * V_204 )
{
struct V_1 * V_2 = F_34 ( V_31 ) ;
return F_35 ( V_204 , V_205 , L_4 , & V_2 -> V_208 [ 0 ] ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < F_39 ( V_209 ) ; V_9 ++ )
F_40 ( & V_2 -> V_32 . V_2 , V_209 [ V_9 ] ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
union V_7 * V_15 = & V_2 -> V_14 [ 0 ] ;
V_15 -> V_210 . V_211 = F_42 ( 0xfe80000000000000LL ) ;
F_1 ( V_2 , & V_15 -> V_212 [ 8 ] ) ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_18 * V_213 )
{
struct V_214 * V_215 ;
union V_7 V_20 ;
V_215 = F_44 ( V_213 ) ;
if ( V_215 ) {
F_45 (in_dev) {
F_15 ( V_41 -> V_43 ,
(struct V_44 * ) & V_20 ) ;
F_2 ( V_2 , & V_20 ) ;
}
F_46 ( V_215 ) ;
F_47 ( V_215 ) ;
}
}
static void F_48 ( struct V_1 * V_2 ,
struct V_18 * V_213 )
{
#if F_49 ( V_216 )
struct V_217 * V_218 ;
union V_7 * V_219 ;
struct V_45 * V_220 ;
V_218 = F_50 ( V_213 ) ;
if ( V_218 ) {
F_51 ( & V_218 -> V_198 ) ;
F_52 (ifp, &in6_dev->addr_list, if_list) {
V_219 = (union V_7 * ) & V_220 -> V_46 ;
F_2 ( V_2 , V_219 ) ;
}
F_53 ( & V_218 -> V_198 ) ;
F_54 ( V_218 ) ;
}
#endif
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_18 * V_221 ;
F_56 (&init_net, net_dev) {
struct V_18 * V_222 = F_7 ( V_221 ) ?
F_7 ( V_221 ) : V_221 ;
if ( V_222 == V_2 -> V_5 . V_19 ) {
F_41 ( V_2 ) ;
F_43 ( V_2 , V_221 ) ;
F_48 ( V_2 , V_221 ) ;
}
}
}
static struct V_1 * F_57 ( struct V_223 * V_224 )
{
int V_225 = 0 , V_9 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) F_58 ( sizeof( struct V_1 ) ) ;
if ( ! V_2 ) {
F_30 ( L_5 ) ;
return NULL ;
}
V_2 -> V_226 = F_27 ( sizeof( struct V_227 ) , V_185 ) ;
if ( ! V_2 -> V_226 )
goto V_228;
memcpy ( & V_2 -> V_5 , V_224 , sizeof( * V_224 ) ) ;
V_2 -> V_201 = F_59 ( & V_229 , NULL , 0 , 0 , V_185 ) ;
if ( V_2 -> V_201 < 0 )
goto V_228;
V_225 = F_60 ( V_2 ) ;
if ( V_225 )
goto V_230;
V_225 = F_25 ( V_2 ) ;
if ( V_225 )
goto V_186;
F_61 ( V_2 ) ;
F_55 ( V_2 ) ;
V_225 = F_20 ( V_2 ) ;
if ( V_225 )
goto V_186;
for ( V_9 = 0 ; V_9 < F_39 ( V_209 ) ; V_9 ++ )
if ( F_62 ( & V_2 -> V_32 . V_2 , V_209 [ V_9 ] ) )
goto V_231;
F_63 ( & V_232 ) ;
F_64 ( & V_2 -> V_233 , & V_234 ) ;
F_65 ( & V_232 ) ;
F_66 ( V_2 ) ;
F_67 ( & V_2 -> V_235 , V_236 ) ;
F_68 ( & V_2 -> V_235 , F_69 ( 1000 ) ) ;
F_70 ( L_6 ,
F_71 ( & V_2 -> V_5 . V_165 -> V_2 ) , F_72 ( V_2 ) ,
F_73 ( V_2 ) , V_2 -> V_208 ,
V_2 -> V_237 ) ;
F_70 ( L_7 ,
F_71 ( & V_2 -> V_5 . V_165 -> V_2 ) , V_2 -> V_201 ) ;
return V_2 ;
V_231:
F_38 ( V_2 ) ;
V_186:
F_31 ( V_2 ) ;
F_74 ( V_2 ) ;
V_230:
F_75 ( & V_229 , V_2 -> V_201 ) ;
V_228:
F_32 ( V_2 -> V_226 ) ;
F_76 ( & V_2 -> V_32 ) ;
F_30 ( L_8 , V_200 , V_225 ) ;
return NULL ;
}
static void F_77 ( struct V_238 * V_239 )
{
struct V_1 * V_2 = F_78 ( V_239 , struct V_1 , V_239 ) ;
F_75 ( & V_229 , V_2 -> V_201 ) ;
F_32 ( V_2 -> V_226 ) ;
F_76 ( & V_2 -> V_32 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
F_80 ( & V_2 -> V_235 ) ;
F_38 ( V_2 ) ;
F_81 ( & V_2 -> V_32 ) ;
F_82 ( V_2 ) ;
F_63 ( & V_232 ) ;
F_83 ( & V_2 -> V_233 ) ;
F_65 ( & V_232 ) ;
F_31 ( V_2 ) ;
F_74 ( V_2 ) ;
F_84 ( & V_2 -> V_239 , F_77 ) ;
}
static int F_85 ( struct V_1 * V_2 )
{
struct V_21 V_240 ;
V_240 . V_17 = V_241 ;
V_240 . V_33 . V_34 = 1 ;
V_240 . V_31 = & V_2 -> V_32 ;
F_12 ( & V_240 ) ;
return 0 ;
}
static int F_86 ( struct V_1 * V_2 )
{
int V_9 ;
struct V_192 * V_242 , * * V_243 ;
struct V_21 V_244 ;
struct V_245 V_246 ;
int V_247 = V_248 ;
V_246 . V_249 = V_250 ;
F_11 ( & V_2 -> V_28 ) ;
if ( V_2 -> V_191 ) {
V_243 = V_2 -> V_191 ;
for ( V_9 = 0 ; V_9 < V_193 ; V_9 ++ ) {
V_242 = V_243 [ V_9 ] ;
if ( V_242 && V_242 -> V_251 . V_252 != V_253 ) {
F_87 ( & V_242 -> V_251 , & V_246 , V_247 ) ;
V_244 . V_17 = V_254 ;
V_244 . V_33 . V_242 = & V_242 -> V_251 ;
V_244 . V_31 = & V_2 -> V_32 ;
F_12 ( & V_244 ) ;
}
}
}
F_13 ( & V_2 -> V_28 ) ;
V_244 . V_17 = V_255 ;
V_244 . V_33 . V_34 = 1 ;
V_244 . V_31 = & V_2 -> V_32 ;
F_12 ( & V_244 ) ;
return 0 ;
}
static void F_88 ( struct V_1 * V_2 )
{
F_86 ( V_2 ) ;
F_79 ( V_2 ) ;
}
static void F_89 ( struct V_1 * V_2 , T_3 V_17 )
{
switch ( V_17 ) {
case V_256 :
F_85 ( V_2 ) ;
break;
case V_257 :
F_86 ( V_2 ) ;
break;
case V_258 :
F_88 ( V_2 ) ;
break;
}
}
static void F_90 ( void )
{
#if F_49 ( V_216 )
F_91 ( & V_259 ) ;
#endif
}
static void F_92 ( void )
{
F_93 ( & V_260 ) ;
}
static int T_4 F_94 ( void )
{
int V_225 ;
F_95 () ;
V_225 = F_96 ( & V_260 ) ;
if ( V_225 )
return V_225 ;
#if F_49 ( V_216 )
V_225 = F_97 ( & V_259 ) ;
if ( V_225 )
goto V_261;
#endif
V_225 = F_98 ( & V_262 ) ;
if ( V_225 )
goto V_263;
return 0 ;
V_263:
#if F_49 ( V_216 )
F_90 () ;
V_261:
#endif
F_92 () ;
return V_225 ;
}
static void T_5 F_99 ( void )
{
F_100 ( & V_262 ) ;
F_90 () ;
F_92 () ;
F_101 () ;
F_102 ( & V_229 ) ;
}
