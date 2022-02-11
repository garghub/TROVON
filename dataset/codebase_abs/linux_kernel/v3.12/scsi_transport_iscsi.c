static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 ) ;
}
static T_1
F_4 ( struct V_1 * V_2 , struct V_5 * V_6 ,
char * V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return sprintf ( V_7 , L_1 , ( unsigned long long ) F_5 ( V_4 -> V_8 ) ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_7 ( V_2 ) ;
F_3 ( V_10 ) ;
}
static T_1
F_8 ( struct V_1 * V_2 , struct V_5 * V_6 , char * V_7 )
{
struct V_9 * V_10 = F_7 ( V_2 ) ;
return sprintf ( V_7 , L_1 , ( unsigned long long ) V_10 -> V_11 ) ;
}
static int F_9 ( struct V_1 * V_2 , const void * V_12 )
{
struct V_9 * V_10 = F_7 ( V_2 ) ;
const T_2 * V_13 = V_12 ;
return * V_13 == V_10 -> V_11 ;
}
struct V_9 *
F_10 ( int V_14 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_2 V_11 ;
int V_15 ;
for ( V_11 = 1 ; V_11 < V_16 ; V_11 ++ ) {
V_2 = F_11 ( & V_17 , NULL , & V_11 ,
F_9 ) ;
if ( ! V_2 )
break;
}
if ( V_11 == V_16 ) {
F_12 ( V_18 L_2 ,
V_16 - 1 ) ;
return NULL ;
}
V_10 = F_13 ( sizeof( * V_10 ) + V_14 , V_19 ) ;
if ( ! V_10 )
return NULL ;
V_10 -> V_11 = V_11 ;
V_10 -> V_2 . V_20 = & V_17 ;
F_14 ( & V_10 -> V_2 , L_3 , ( unsigned long long ) V_11 ) ;
V_15 = F_15 ( & V_10 -> V_2 ) ;
if ( V_15 )
goto V_21;
V_15 = F_16 ( & V_10 -> V_2 . V_22 , & V_23 ) ;
if ( V_15 )
goto V_24;
if ( V_14 )
V_10 -> V_25 = & V_10 [ 1 ] ;
return V_10 ;
V_24:
F_17 ( & V_10 -> V_2 ) ;
return NULL ;
V_21:
F_3 ( V_10 ) ;
return NULL ;
}
void F_18 ( struct V_9 * V_10 )
{
F_19 ( & V_10 -> V_2 . V_22 , & V_23 ) ;
F_17 ( & V_10 -> V_2 ) ;
}
struct V_9 * F_20 ( T_3 V_26 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
V_2 = F_11 ( & V_17 , NULL , & V_26 ,
F_9 ) ;
if ( ! V_2 )
return NULL ;
V_10 = F_7 ( V_2 ) ;
F_21 ( V_2 ) ;
return V_10 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = F_23 ( V_2 ) ;
struct V_1 * V_29 = V_28 -> V_2 . V_29 ;
F_3 ( V_28 ) ;
F_21 ( V_29 ) ;
}
static T_4 F_24 ( struct V_30 * V_22 ,
struct V_31 * V_6 , int V_32 )
{
struct V_1 * V_2 = F_25 ( V_22 , struct V_1 , V_22 ) ;
struct V_27 * V_28 = F_23 ( V_2 ) ;
struct V_8 * V_33 = V_28 -> V_34 ;
int V_35 ;
if ( V_6 == & V_36 . V_6 )
V_35 = V_37 ;
else if ( V_6 == & V_38 . V_6 )
V_35 = V_39 ;
else if ( V_6 == & V_40 . V_6 )
V_35 = V_41 ;
else if ( V_6 == & V_42 . V_6 )
V_35 = V_43 ;
else if ( V_6 == & V_44 . V_6 )
V_35 = V_45 ;
else if ( V_6 == & V_46 . V_6 )
V_35 = V_47 ;
else if ( V_28 -> V_48 == V_49 ) {
if ( V_6 == & V_50 . V_6 )
V_35 = V_51 ;
else if ( V_6 == & V_52 . V_6 )
V_35 = V_53 ;
else if ( V_6 == & V_54 . V_6 )
V_35 = V_55 ;
else if ( V_6 == & V_56 . V_6 )
V_35 = V_57 ;
else
return 0 ;
} else if ( V_28 -> V_48 == V_58 ) {
if ( V_6 == & V_59 . V_6 )
V_35 = V_60 ;
else if ( V_6 == & V_61 . V_6 )
V_35 = V_62 ;
else if ( V_6 == & V_63 . V_6 )
V_35 = V_64 ;
else if ( V_6 == & V_65 . V_6 )
V_35 = V_66 ;
else if ( V_6 == & V_67 . V_6 )
V_35 = V_68 ;
else
return 0 ;
} else {
F_26 ( 1 , L_4 ) ;
return 0 ;
}
return V_33 -> V_69 ( V_70 , V_35 ) ;
}
struct V_27 *
F_27 ( struct V_71 * V_72 , struct V_8 * V_34 ,
T_5 V_48 , T_5 V_73 , int V_14 )
{
struct V_27 * V_28 ;
int V_15 ;
V_28 = F_13 ( sizeof( * V_28 ) + V_14 , V_19 ) ;
if ( ! V_28 )
return NULL ;
V_28 -> V_34 = V_34 ;
V_28 -> V_48 = V_48 ;
V_28 -> V_73 = V_73 ;
V_28 -> V_2 . V_74 = F_22 ;
V_28 -> V_2 . V_20 = & V_75 ;
V_28 -> V_2 . V_29 = F_28 ( & V_72 -> V_76 ) ;
if ( V_48 == V_49 )
F_14 ( & V_28 -> V_2 , L_5 , V_72 -> V_77 ,
V_73 ) ;
else
F_14 ( & V_28 -> V_2 , L_6 , V_72 -> V_77 ,
V_73 ) ;
V_15 = F_15 ( & V_28 -> V_2 ) ;
if ( V_15 )
goto V_78;
V_15 = F_16 ( & V_28 -> V_2 . V_22 , & V_79 ) ;
if ( V_15 )
goto V_80;
if ( V_14 )
V_28 -> V_25 = & V_28 [ 1 ] ;
return V_28 ;
V_80:
F_17 ( & V_28 -> V_2 ) ;
return NULL ;
V_78:
F_21 ( V_28 -> V_2 . V_29 ) ;
F_3 ( V_28 ) ;
return NULL ;
}
void F_29 ( struct V_27 * V_28 )
{
F_19 ( & V_28 -> V_2 . V_22 , & V_79 ) ;
F_17 ( & V_28 -> V_2 ) ;
}
static T_4 F_30 ( struct V_30 * V_22 ,
struct V_31 * V_6 ,
int V_32 )
{
struct V_1 * V_2 = F_25 ( V_22 , struct V_1 , V_22 ) ;
struct V_81 * V_82 =
F_31 ( V_2 ) ;
struct V_8 * V_33 = V_82 -> V_34 ;
int V_35 ;
if ( V_6 == & V_83 . V_6 ) {
V_35 = V_84 ;
} else if ( V_6 == & V_85 . V_6 ) {
V_35 = V_86 ;
} else if ( V_6 == & V_87 . V_6 ) {
V_35 = V_88 ;
} else if ( V_6 == & V_89 . V_6 ) {
V_35 = V_90 ;
} else if ( V_6 == & V_91 . V_6 ) {
V_35 = V_92 ;
} else if ( V_6 == & V_93 . V_6 ) {
V_35 = V_94 ;
} else if ( V_6 == & V_95 . V_6 ) {
V_35 = V_96 ;
} else if ( V_6 == & V_97 . V_6 ) {
V_35 = V_98 ;
} else if ( V_6 == & V_99 . V_6 ) {
V_35 = V_100 ;
} else if ( V_6 == & V_101 . V_6 ) {
V_35 = V_102 ;
} else if ( V_6 == & V_103 . V_6 ) {
V_35 = V_104 ;
} else if ( V_6 == & V_105 . V_6 ) {
V_35 = V_106 ;
} else if ( V_6 == & V_107 . V_6 ) {
V_35 = V_108 ;
} else if ( V_6 == & V_109 . V_6 ) {
V_35 = V_110 ;
} else if ( V_6 == & V_111 . V_6 ) {
V_35 = V_112 ;
} else if ( V_6 == & V_113 . V_6 ) {
V_35 = V_114 ;
} else if ( V_6 == & V_115 . V_6 ) {
V_35 = V_116 ;
} else if ( V_6 == & V_117 . V_6 ) {
V_35 = V_118 ;
} else if ( V_6 == & V_119 . V_6 ) {
V_35 = V_120 ;
} else if ( V_6 == & V_121 . V_6 ) {
V_35 = V_122 ;
} else if ( V_6 == & V_123 . V_6 ) {
V_35 = V_124 ;
} else if ( V_6 == & V_125 . V_6 ) {
V_35 = V_126 ;
} else if ( V_6 == & V_127 . V_6 ) {
V_35 = V_128 ;
} else if ( V_6 == & V_129 . V_6 ) {
V_35 = V_130 ;
} else if ( V_6 == & V_131 . V_6 ) {
V_35 = V_132 ;
} else if ( V_6 == & V_133 . V_6 ) {
V_35 = V_134 ;
} else if ( V_6 == & V_135 . V_6 ) {
V_35 = V_136 ;
} else if ( V_6 == & V_137 . V_6 ) {
V_35 = V_138 ;
} else if ( V_6 == & V_139 . V_6 ) {
V_35 = V_140 ;
} else if ( V_6 == & V_141 . V_6 ) {
V_35 = V_142 ;
} else if ( V_6 == & V_143 . V_6 ) {
V_35 = V_144 ;
} else if ( V_6 == & V_145 . V_6 ) {
V_35 = V_146 ;
} else if ( V_6 == & V_147 . V_6 ) {
V_35 = V_148 ;
} else {
F_26 ( 1 , L_7 ) ;
return 0 ;
}
return V_33 -> V_69 ( V_149 , V_35 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_81 * V_82 =
F_31 ( V_2 ) ;
F_3 ( V_82 -> V_150 ) ;
F_3 ( V_82 -> V_151 ) ;
F_3 ( V_82 -> V_152 ) ;
F_3 ( V_82 ) ;
}
static T_4 F_33 ( struct V_30 * V_22 ,
struct V_31 * V_6 ,
int V_32 )
{
struct V_1 * V_2 = F_25 ( V_22 , struct V_1 , V_22 ) ;
struct V_153 * V_154 = F_34 ( V_2 ) ;
struct V_8 * V_33 = V_154 -> V_34 ;
int V_35 ;
if ( V_6 == & V_155 . V_6 ) {
V_35 = V_156 ;
} else if ( V_6 == & V_157 . V_6 ) {
V_35 = V_158 ;
} else if ( V_6 == & V_159 . V_6 ) {
V_35 = V_160 ;
} else if ( V_6 == & V_161 . V_6 ) {
V_35 = V_162 ;
} else if ( V_6 == & V_163 . V_6 ) {
V_35 = V_164 ;
} else if ( V_6 == & V_165 . V_6 ) {
V_35 = V_166 ;
} else if ( V_6 == & V_167 . V_6 ) {
V_35 = V_168 ;
} else if ( V_6 == & V_169 . V_6 ) {
V_35 = V_170 ;
} else if ( V_6 == & V_171 . V_6 ) {
V_35 = V_172 ;
} else if ( V_6 == & V_173 . V_6 ) {
V_35 = V_174 ;
} else if ( V_6 == & V_175 . V_6 ) {
V_35 = V_176 ;
} else if ( V_6 == & V_177 . V_6 ) {
V_35 = V_178 ;
} else if ( V_6 == & V_179 . V_6 ) {
V_35 = V_180 ;
} else if ( V_6 == & V_181 . V_6 ) {
V_35 = V_182 ;
} else if ( V_6 == & V_183 . V_6 ) {
V_35 = V_184 ;
} else if ( V_6 == & V_185 . V_6 ) {
V_35 = V_186 ;
} else if ( V_6 == & V_187 . V_6 ) {
V_35 = V_188 ;
} else if ( V_6 == & V_189 . V_6 ) {
V_35 = V_190 ;
} else if ( V_6 == & V_191 . V_6 ) {
V_35 = V_192 ;
} else if ( V_6 == & V_193 . V_6 ) {
V_35 = V_194 ;
} else if ( V_6 == & V_195 . V_6 ) {
V_35 = V_196 ;
} else if ( V_6 == & V_197 . V_6 ) {
V_35 = V_198 ;
} else if ( V_6 == & V_199 . V_6 ) {
V_35 = V_200 ;
} else if ( V_6 == & V_201 . V_6 ) {
V_35 = V_202 ;
} else if ( V_6 == & V_203 . V_6 ) {
V_35 = V_204 ;
} else if ( V_6 == & V_205 . V_6 ) {
V_35 = V_206 ;
} else {
F_26 ( 1 , L_8 ) ;
return 0 ;
}
return V_33 -> V_69 ( V_149 , V_35 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_153 * V_154 = F_34 ( V_2 ) ;
F_3 ( V_154 -> V_207 ) ;
F_3 ( V_154 -> V_208 ) ;
F_3 ( V_154 -> V_209 ) ;
F_3 ( V_154 ) ;
}
int F_36 ( struct V_1 * V_2 ,
struct V_210 * V_211 )
{
if ( V_2 -> V_212 == & V_213 )
return 1 ;
return 0 ;
}
struct V_81 *
F_37 ( struct V_71 * V_72 , int V_214 ,
struct V_8 * V_34 ,
int V_14 )
{
struct V_81 * V_82 ;
int V_15 ;
V_82 = F_13 ( sizeof( * V_82 ) + V_14 , V_19 ) ;
if ( ! V_82 )
return NULL ;
V_82 -> V_34 = V_34 ;
V_82 -> V_215 = V_214 ;
V_82 -> V_2 . type = & V_216 ;
V_82 -> V_2 . V_212 = & V_213 ;
V_82 -> V_2 . V_29 = & V_72 -> V_76 ;
F_14 ( & V_82 -> V_2 , L_9 ,
V_72 -> V_77 , V_214 ) ;
V_15 = F_15 ( & V_82 -> V_2 ) ;
if ( V_15 )
goto V_217;
if ( V_14 )
V_82 -> V_25 = & V_82 [ 1 ] ;
return V_82 ;
V_217:
F_3 ( V_82 ) ;
return NULL ;
}
struct V_153 *
F_38 ( struct V_71 * V_72 ,
struct V_81 * V_82 ,
struct V_8 * V_34 ,
int V_14 )
{
struct V_153 * V_154 ;
int V_15 ;
V_154 = F_13 ( sizeof( * V_154 ) + V_14 , V_19 ) ;
if ( ! V_154 )
return NULL ;
V_154 -> V_34 = V_34 ;
V_154 -> V_2 . type = & V_218 ;
V_154 -> V_2 . V_212 = & V_213 ;
V_154 -> V_2 . V_29 = & V_82 -> V_2 ;
F_14 ( & V_154 -> V_2 , L_10 ,
V_72 -> V_77 , V_82 -> V_215 ) ;
V_15 = F_15 ( & V_154 -> V_2 ) ;
if ( V_15 )
goto V_219;
if ( V_14 )
V_154 -> V_25 = & V_154 [ 1 ] ;
return V_154 ;
V_219:
F_3 ( V_154 ) ;
return NULL ;
}
int F_39 ( struct V_1 * V_2 , void * V_12 )
{
return V_2 -> V_212 == & V_213 ;
}
static int F_40 ( struct V_153 * V_154 )
{
F_17 ( & V_154 -> V_2 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , void * V_12 )
{
struct V_81 * V_82 = NULL ;
int V_220 = 0 ;
if ( ! F_36 ( V_2 , NULL ) )
goto V_221;
V_82 = F_31 ( V_2 ) ;
V_220 = ( V_82 -> V_215 == * ( ( int * ) V_12 ) ) ? 1 : 0 ;
V_221:
return V_220 ;
}
static struct V_81 *
F_42 ( struct V_71 * V_72 , T_5 V_222 )
{
struct V_81 * V_82 = NULL ;
struct V_1 * V_2 ;
V_2 = F_43 ( & V_72 -> V_76 , & V_222 ,
F_41 ) ;
if ( V_2 )
V_82 = F_31 ( V_2 ) ;
return V_82 ;
}
struct V_1 *
F_44 ( struct V_71 * V_72 , void * V_12 ,
int (* F_45)( struct V_1 * V_2 , void * V_12 ) )
{
return F_43 ( & V_72 -> V_76 , V_12 , F_45 ) ;
}
struct V_1 *
F_46 ( struct V_81 * V_82 )
{
return F_43 ( & V_82 -> V_2 , NULL ,
F_39 ) ;
}
static int F_47 ( struct V_1 * V_2 , void * V_12 )
{
if ( ! F_39 ( V_2 , NULL ) )
return 0 ;
return F_40 ( F_34 ( V_2 ) ) ;
}
void F_48 ( struct V_81 * V_82 )
{
int V_15 ;
V_15 = F_49 ( & V_82 -> V_2 , NULL ,
F_47 ) ;
if ( V_15 )
F_50 ( L_11 ,
V_82 -> V_2 . V_22 . V_223 , V_15 ) ;
F_17 ( & V_82 -> V_2 ) ;
}
static int F_51 ( struct V_1 * V_2 , void * V_12 )
{
if ( ! F_36 ( V_2 , NULL ) )
return 0 ;
F_48 ( F_31 ( V_2 ) ) ;
return 0 ;
}
void F_52 ( struct V_71 * V_72 )
{
F_49 ( & V_72 -> V_76 , NULL ,
F_51 ) ;
}
static int F_53 ( struct V_224 * V_225 )
{
struct V_71 * V_72 = F_54 ( V_225 ) ;
struct V_226 * V_227 = V_225 -> V_228 ;
struct V_229 * V_230 = V_225 -> V_230 ;
struct V_3 * V_32 = F_55 ( V_72 -> V_231 ) ;
int V_232 = sizeof( T_5 ) ;
int V_220 ;
if ( V_225 -> V_233 < sizeof( T_5 ) ) {
V_220 = - V_234 ;
goto V_235;
}
switch ( V_227 -> V_236 ) {
case V_237 :
V_232 += sizeof( struct V_238 ) ;
if ( ( V_72 -> V_239 -> V_240 == 0L ) ||
( V_227 -> V_241 . V_242 . V_240 !=
V_72 -> V_239 -> V_240 ) ) {
V_220 = - V_243 ;
goto V_235;
}
break;
default:
V_220 = - V_244 ;
goto V_235;
}
if ( V_225 -> V_233 < V_232 ) {
V_220 = - V_234 ;
goto V_235;
}
V_220 = V_32 -> V_8 -> V_245 ( V_225 ) ;
if ( ! V_220 )
return 0 ;
V_235:
F_56 ( V_225 -> V_246 < sizeof( T_5 ) ) ;
V_230 -> V_247 = 0 ;
V_230 -> V_248 = V_220 ;
V_225 -> V_246 = sizeof( T_5 ) ;
F_57 ( V_225 , V_220 , 0 ) ;
return 0 ;
}
static int
F_58 ( struct V_71 * V_72 , struct V_249 * V_250 )
{
struct V_1 * V_2 = & V_72 -> V_76 ;
struct V_3 * V_32 = F_55 ( V_72 -> V_231 ) ;
struct V_251 * V_252 ;
char V_253 [ 20 ] ;
int V_220 ;
if ( ! V_32 -> V_8 -> V_245 )
return - V_254 ;
snprintf ( V_253 , sizeof( V_253 ) , L_12 , V_72 -> V_77 ) ;
V_252 = F_59 ( V_72 , V_255 ) ;
if ( ! V_252 )
return - V_256 ;
V_220 = F_60 ( V_2 , V_252 , V_253 , F_53 , 0 ) ;
if ( V_220 ) {
F_61 ( V_18 , V_72 , L_13
L_14 ) ;
F_62 ( V_252 ) ;
return V_220 ;
}
V_250 -> V_257 = V_252 ;
return 0 ;
}
static int F_63 ( struct V_258 * V_259 , struct V_1 * V_2 ,
struct V_1 * V_260 )
{
struct V_71 * V_72 = F_64 ( V_2 ) ;
struct V_249 * V_250 = V_72 -> V_261 ;
memset ( V_250 , 0 , sizeof( * V_250 ) ) ;
F_65 ( & V_250 -> V_262 , 0 ) ;
F_66 ( & V_250 -> V_263 ) ;
F_58 ( V_72 , V_250 ) ;
return 0 ;
}
static int F_67 ( struct V_258 * V_259 ,
struct V_1 * V_2 , struct V_1 * V_260 )
{
struct V_71 * V_72 = F_64 ( V_2 ) ;
struct V_249 * V_250 = V_72 -> V_261 ;
if ( V_250 -> V_257 ) {
F_68 ( V_250 -> V_257 ) ;
F_62 ( V_250 -> V_257 ) ;
}
return 0 ;
}
static T_5 F_69 ( struct V_264 * V_265 )
{
struct V_266 * V_267 = F_70 ( V_265 -> V_2 . V_29 ) ;
return V_267 -> V_268 ;
}
static struct V_266 * F_71 ( T_5 V_268 )
{
unsigned long V_269 ;
struct V_266 * V_267 ;
F_72 ( & V_270 , V_269 ) ;
F_73 (sess, &sesslist, sess_list) {
if ( V_267 -> V_268 == V_268 ) {
F_74 ( & V_270 , V_269 ) ;
return V_267 ;
}
}
F_74 ( & V_270 , V_269 ) ;
return NULL ;
}
static struct V_264 * F_75 ( T_5 V_268 , T_5 V_271 )
{
unsigned long V_269 ;
struct V_264 * V_265 ;
F_72 ( & V_272 , V_269 ) ;
F_73 (conn, &connlist, conn_list) {
if ( ( V_265 -> V_271 == V_271 ) && ( F_69 ( V_265 ) == V_268 ) ) {
F_74 ( & V_272 , V_269 ) ;
return V_265 ;
}
}
F_74 ( & V_272 , V_269 ) ;
return NULL ;
}
static const char * F_76 ( int V_273 )
{
int V_32 ;
char * V_223 = NULL ;
for ( V_32 = 0 ; V_32 < F_77 ( V_274 ) ; V_32 ++ ) {
if ( V_274 [ V_32 ] . V_275 == V_273 ) {
V_223 = V_274 [ V_32 ] . V_223 ;
break;
}
}
return V_223 ;
}
int F_78 ( struct V_266 * V_276 )
{
unsigned long V_269 ;
int V_15 ;
F_72 ( & V_276 -> V_277 , V_269 ) ;
switch ( V_276 -> V_273 ) {
case V_278 :
V_15 = 0 ;
break;
case V_279 :
V_15 = V_280 << 16 ;
break;
case V_281 :
V_15 = V_282 << 16 ;
break;
default:
V_15 = V_283 << 16 ;
break;
}
F_74 ( & V_276 -> V_277 , V_269 ) ;
return V_15 ;
}
int F_79 ( struct V_266 * V_276 )
{
unsigned long V_269 ;
int V_220 = 0 ;
F_72 ( & V_276 -> V_277 , V_269 ) ;
if ( V_276 -> V_273 == V_278 )
V_220 = 1 ;
F_74 ( & V_276 -> V_277 , V_269 ) ;
return V_220 ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_266 * V_276 = F_70 ( V_2 ) ;
struct V_71 * V_72 ;
V_72 = F_81 ( V_276 ) ;
F_82 ( V_72 ) ;
F_83 ( V_276 , L_15 ) ;
F_3 ( V_276 ) ;
}
int F_84 ( const struct V_1 * V_2 )
{
return V_2 -> V_74 == F_80 ;
}
static int F_85 ( struct V_1 * V_2 , void * V_12 )
{
void (* F_45) ( struct V_266 * ) = V_12 ;
if ( ! F_84 ( V_2 ) )
return 0 ;
F_45 ( F_70 ( V_2 ) ) ;
return 0 ;
}
void F_86 ( struct V_71 * V_72 ,
void (* F_45)( struct V_266 * ) )
{
F_49 ( & V_72 -> V_76 , F_45 ,
F_85 ) ;
}
int F_87 ( struct V_71 * V_72 , unsigned long time )
{
struct V_249 * V_250 = V_72 -> V_261 ;
return ! F_88 ( & V_250 -> V_262 ) ;
}
static int F_89 ( struct V_1 * V_2 , void * V_12 )
{
struct V_284 * V_285 = V_12 ;
struct V_266 * V_276 ;
struct V_71 * V_72 ;
struct V_249 * V_250 ;
unsigned long V_269 ;
unsigned int V_11 ;
if ( ! F_84 ( V_2 ) )
return 0 ;
V_276 = F_70 ( V_2 ) ;
F_83 ( V_276 , L_16 ) ;
V_72 = F_81 ( V_276 ) ;
V_250 = V_72 -> V_261 ;
F_90 ( & V_250 -> V_263 ) ;
F_72 ( & V_276 -> V_277 , V_269 ) ;
if ( V_276 -> V_273 != V_278 ) {
F_74 ( & V_276 -> V_277 , V_269 ) ;
goto V_286;
}
V_11 = V_276 -> V_215 ;
F_74 ( & V_276 -> V_277 , V_269 ) ;
if ( V_11 != V_287 ) {
if ( ( V_285 -> V_288 == V_289 ||
V_285 -> V_288 == 0 ) &&
( V_285 -> V_11 == V_289 ||
V_285 -> V_11 == V_11 ) )
F_91 ( & V_276 -> V_2 , 0 , V_11 ,
V_285 -> V_290 , 1 ) ;
}
V_286:
F_92 ( & V_250 -> V_263 ) ;
F_83 ( V_276 , L_17 ) ;
return 0 ;
}
static int F_93 ( struct V_71 * V_72 , T_6 V_288 ,
T_6 V_11 , T_6 V_290 )
{
struct V_284 V_285 ;
V_285 . V_288 = V_288 ;
V_285 . V_11 = V_11 ;
V_285 . V_290 = V_290 ;
return F_49 ( & V_72 -> V_76 , & V_285 ,
F_89 ) ;
}
static void F_94 ( struct V_291 * V_292 )
{
struct V_266 * V_276 =
F_25 ( V_292 , struct V_266 , V_293 ) ;
struct V_71 * V_72 = F_81 ( V_276 ) ;
struct V_249 * V_250 = V_72 -> V_261 ;
struct V_284 V_285 ;
V_285 . V_288 = 0 ;
V_285 . V_11 = V_289 ;
V_285 . V_290 = V_289 ;
F_89 ( & V_276 -> V_2 , & V_285 ) ;
F_95 ( & V_250 -> V_262 ) ;
}
int F_96 ( struct V_294 * V_295 )
{
struct V_266 * V_276 =
F_97 ( F_98 ( V_295 -> V_1 ) ) ;
unsigned long V_269 ;
int V_220 = 0 ;
F_72 ( & V_276 -> V_277 , V_269 ) ;
while ( V_276 -> V_273 != V_278 ) {
if ( V_276 -> V_273 == V_281 ) {
V_220 = V_296 ;
break;
}
F_74 ( & V_276 -> V_277 , V_269 ) ;
F_99 ( 1000 ) ;
F_72 ( & V_276 -> V_277 , V_269 ) ;
}
F_74 ( & V_276 -> V_277 , V_269 ) ;
return V_220 ;
}
static void F_100 ( struct V_291 * V_292 )
{
struct V_266 * V_276 =
F_25 ( V_292 , struct V_266 ,
V_297 . V_292 ) ;
unsigned long V_269 ;
F_101 ( V_298 , V_276 ,
L_18 ,
V_276 -> V_299 ) ;
F_72 ( & V_276 -> V_277 , V_269 ) ;
switch ( V_276 -> V_273 ) {
case V_279 :
V_276 -> V_273 = V_281 ;
break;
case V_278 :
case V_281 :
F_74 ( & V_276 -> V_277 , V_269 ) ;
return;
}
F_74 ( & V_276 -> V_277 , V_269 ) ;
if ( V_276 -> V_34 -> F_100 )
V_276 -> V_34 -> F_100 ( V_276 ) ;
F_83 ( V_276 , L_19 ) ;
F_102 ( & V_276 -> V_2 , V_300 ) ;
F_83 ( V_276 , L_20 ) ;
}
static void F_103 ( struct V_291 * V_292 )
{
struct V_266 * V_276 =
F_25 ( V_292 , struct V_266 ,
V_301 ) ;
struct V_71 * V_72 = F_81 ( V_276 ) ;
struct V_249 * V_250 = V_72 -> V_261 ;
unsigned long V_269 ;
F_83 ( V_276 , L_21 ) ;
F_104 ( & V_276 -> V_297 ) ;
F_72 ( & V_276 -> V_277 , V_269 ) ;
V_276 -> V_273 = V_278 ;
F_74 ( & V_276 -> V_277 , V_269 ) ;
F_102 ( & V_276 -> V_2 , V_302 ) ;
if ( V_72 -> V_239 -> V_303 ) {
if ( F_105 ( V_72 , & V_276 -> V_293 ) )
F_106 ( & V_250 -> V_262 ) ;
}
F_83 ( V_276 , L_22 ) ;
}
void F_107 ( struct V_266 * V_276 )
{
F_108 ( V_304 , & V_276 -> V_301 ) ;
F_109 ( V_304 ) ;
}
static void F_110 ( struct V_291 * V_292 )
{
struct V_266 * V_276 =
F_25 ( V_292 , struct V_266 ,
V_305 ) ;
unsigned long V_269 ;
F_83 ( V_276 , L_23 ) ;
F_72 ( & V_276 -> V_277 , V_269 ) ;
V_276 -> V_273 = V_279 ;
F_74 ( & V_276 -> V_277 , V_269 ) ;
F_111 ( & V_276 -> V_2 ) ;
F_83 ( V_276 , L_24 ) ;
if ( V_276 -> V_299 >= 0 )
F_112 ( V_304 ,
& V_276 -> V_297 ,
V_276 -> V_299 * V_306 ) ;
}
void F_113 ( struct V_266 * V_276 )
{
F_108 ( V_304 , & V_276 -> V_305 ) ;
}
static void F_114 ( struct V_291 * V_292 )
{
struct V_266 * V_276 =
F_25 ( V_292 , struct V_266 ,
V_307 ) ;
struct V_71 * V_72 = F_81 ( V_276 ) ;
struct V_249 * V_250 = V_72 -> V_261 ;
unsigned long V_269 ;
unsigned int V_215 ;
F_83 ( V_276 , L_25 ) ;
F_90 ( & V_250 -> V_263 ) ;
F_72 ( & V_276 -> V_277 , V_269 ) ;
if ( V_276 -> V_215 == V_287 ) {
F_74 ( & V_276 -> V_277 , V_269 ) ;
F_92 ( & V_250 -> V_263 ) ;
return;
}
V_215 = V_276 -> V_215 ;
V_276 -> V_215 = V_287 ;
F_74 ( & V_276 -> V_277 , V_269 ) ;
F_92 ( & V_250 -> V_263 ) ;
if ( V_276 -> V_308 )
F_115 ( & V_309 , V_215 ) ;
F_116 ( & V_276 -> V_2 ) ;
F_117 ( V_276 , V_310 ) ;
F_83 ( V_276 , L_26 ) ;
}
struct V_266 *
F_118 ( struct V_71 * V_72 , struct V_8 * V_34 ,
int V_14 )
{
struct V_266 * V_276 ;
V_276 = F_13 ( sizeof( * V_276 ) + V_14 ,
V_19 ) ;
if ( ! V_276 )
return NULL ;
V_276 -> V_34 = V_34 ;
V_276 -> V_311 = - 1 ;
V_276 -> V_299 = 120 ;
V_276 -> V_273 = V_281 ;
F_119 ( & V_276 -> V_297 , F_100 ) ;
F_120 ( & V_276 -> V_312 ) ;
F_121 ( & V_276 -> V_301 , F_103 ) ;
F_121 ( & V_276 -> V_305 , F_110 ) ;
F_121 ( & V_276 -> V_307 , F_114 ) ;
F_121 ( & V_276 -> V_293 , F_94 ) ;
F_122 ( & V_276 -> V_277 ) ;
F_123 ( V_72 ) ;
V_276 -> V_2 . V_29 = & V_72 -> V_76 ;
V_276 -> V_2 . V_74 = F_80 ;
F_124 ( & V_276 -> V_2 ) ;
if ( V_14 )
V_276 -> V_25 = & V_276 [ 1 ] ;
F_83 ( V_276 , L_27 ) ;
return V_276 ;
}
int F_125 ( struct V_266 * V_276 , unsigned int V_215 )
{
struct V_71 * V_72 = F_81 ( V_276 ) ;
struct V_249 * V_250 ;
unsigned long V_269 ;
int V_11 = 0 ;
int V_15 ;
V_250 = V_72 -> V_261 ;
V_276 -> V_268 = F_126 ( 1 , & V_313 ) ;
if ( V_215 == V_287 ) {
V_11 = F_127 ( & V_309 , 0 , 0 , V_19 ) ;
if ( V_11 < 0 ) {
F_101 ( V_18 , V_276 ,
L_28 ) ;
return V_11 ;
}
V_276 -> V_215 = ( unsigned int ) V_11 ;
V_276 -> V_308 = true ;
} else
V_276 -> V_215 = V_215 ;
F_14 ( & V_276 -> V_2 , L_29 , V_276 -> V_268 ) ;
V_15 = F_128 ( & V_276 -> V_2 ) ;
if ( V_15 ) {
F_101 ( V_18 , V_276 ,
L_30 ) ;
goto V_314;
}
F_129 ( & V_276 -> V_2 ) ;
F_72 ( & V_270 , V_269 ) ;
F_130 ( & V_276 -> V_312 , & V_315 ) ;
F_74 ( & V_270 , V_269 ) ;
F_117 ( V_276 , V_316 ) ;
F_83 ( V_276 , L_31 ) ;
return 0 ;
V_314:
if ( V_276 -> V_308 )
F_115 ( & V_309 , V_276 -> V_215 ) ;
return V_15 ;
}
struct V_266 *
F_131 ( struct V_71 * V_72 , struct V_8 * V_34 ,
int V_14 , unsigned int V_215 )
{
struct V_266 * V_276 ;
V_276 = F_118 ( V_72 , V_34 , V_14 ) ;
if ( ! V_276 )
return NULL ;
if ( F_125 ( V_276 , V_215 ) ) {
F_132 ( V_276 ) ;
return NULL ;
}
return V_276 ;
}
static void F_133 ( struct V_1 * V_2 )
{
struct V_264 * V_265 = F_134 ( V_2 ) ;
struct V_1 * V_29 = V_265 -> V_2 . V_29 ;
F_135 ( V_265 , L_32 ) ;
F_3 ( V_265 ) ;
F_21 ( V_29 ) ;
}
static int F_136 ( const struct V_1 * V_2 )
{
return V_2 -> V_74 == F_133 ;
}
static int F_137 ( struct V_1 * V_2 , void * V_12 )
{
if ( ! F_136 ( V_2 ) )
return 0 ;
return F_138 ( F_134 ( V_2 ) ) ;
}
void F_139 ( struct V_266 * V_276 )
{
struct V_71 * V_72 = F_81 ( V_276 ) ;
unsigned long V_269 ;
int V_15 ;
F_83 ( V_276 , L_33 ) ;
F_72 ( & V_270 , V_269 ) ;
F_140 ( & V_276 -> V_312 ) ;
F_74 ( & V_270 , V_269 ) ;
F_109 ( V_304 ) ;
if ( ! F_104 ( & V_276 -> V_297 ) )
F_109 ( V_304 ) ;
F_72 ( & V_276 -> V_277 , V_269 ) ;
V_276 -> V_273 = V_281 ;
F_74 ( & V_276 -> V_277 , V_269 ) ;
F_102 ( & V_276 -> V_2 , V_300 ) ;
F_141 ( V_72 ) ;
F_114 ( & V_276 -> V_307 ) ;
V_15 = F_49 ( & V_276 -> V_2 , NULL ,
F_137 ) ;
if ( V_15 )
F_101 ( V_18 , V_276 ,
L_34
L_35 , V_15 ) ;
F_142 ( & V_276 -> V_2 ) ;
F_83 ( V_276 , L_36 ) ;
F_143 ( & V_276 -> V_2 ) ;
}
void F_132 ( struct V_266 * V_276 )
{
F_83 ( V_276 , L_37 ) ;
F_117 ( V_276 , V_317 ) ;
F_21 ( & V_276 -> V_2 ) ;
}
int F_144 ( struct V_266 * V_276 )
{
F_139 ( V_276 ) ;
F_83 ( V_276 , L_38 ) ;
F_132 ( V_276 ) ;
return 0 ;
}
struct V_264 *
F_145 ( struct V_266 * V_276 , int V_14 , T_5 V_271 )
{
struct V_8 * V_34 = V_276 -> V_34 ;
struct V_264 * V_265 ;
unsigned long V_269 ;
int V_15 ;
V_265 = F_13 ( sizeof( * V_265 ) + V_14 , V_19 ) ;
if ( ! V_265 )
return NULL ;
if ( V_14 )
V_265 -> V_25 = & V_265 [ 1 ] ;
F_66 ( & V_265 -> V_318 ) ;
F_120 ( & V_265 -> V_319 ) ;
V_265 -> V_34 = V_34 ;
V_265 -> V_271 = V_271 ;
if ( ! F_28 ( & V_276 -> V_2 ) )
goto V_320;
F_14 ( & V_265 -> V_2 , L_39 , V_276 -> V_268 , V_271 ) ;
V_265 -> V_2 . V_29 = & V_276 -> V_2 ;
V_265 -> V_2 . V_74 = F_133 ;
V_15 = F_15 ( & V_265 -> V_2 ) ;
if ( V_15 ) {
F_101 ( V_18 , V_276 , L_40
L_41 ) ;
goto V_321;
}
F_129 ( & V_265 -> V_2 ) ;
F_72 ( & V_272 , V_269 ) ;
F_130 ( & V_265 -> V_319 , & V_322 ) ;
F_74 ( & V_272 , V_269 ) ;
F_135 ( V_265 , L_42 ) ;
return V_265 ;
V_321:
F_21 ( & V_276 -> V_2 ) ;
V_320:
F_3 ( V_265 ) ;
return NULL ;
}
int F_138 ( struct V_264 * V_265 )
{
unsigned long V_269 ;
F_72 ( & V_272 , V_269 ) ;
F_140 ( & V_265 -> V_319 ) ;
F_74 ( & V_272 , V_269 ) ;
F_142 ( & V_265 -> V_2 ) ;
F_135 ( V_265 , L_43 ) ;
F_17 ( & V_265 -> V_2 ) ;
return 0 ;
}
static struct V_3 *
F_146 ( struct V_8 * V_323 )
{
struct V_3 * V_4 ;
unsigned long V_269 ;
F_72 ( & V_324 , V_269 ) ;
F_73 (priv, &iscsi_transports, list) {
if ( V_323 == V_4 -> V_8 ) {
F_74 ( & V_324 , V_269 ) ;
return V_4 ;
}
}
F_74 ( & V_324 , V_269 ) ;
return NULL ;
}
static int
F_147 ( struct V_325 * V_326 , T_5 V_327 , T_7 V_328 )
{
return F_148 ( V_329 , V_326 , 0 , V_327 , V_328 ) ;
}
int F_149 ( struct V_264 * V_265 , struct V_330 * V_331 ,
char * V_12 , T_5 V_332 )
{
struct V_333 * V_334 ;
struct V_325 * V_326 ;
struct V_335 * V_336 ;
char * V_337 ;
struct V_3 * V_4 ;
int V_338 = F_150 ( sizeof( * V_336 ) + sizeof( struct V_330 ) +
V_332 ) ;
V_4 = F_146 ( V_265 -> V_34 ) ;
if ( ! V_4 )
return - V_339 ;
V_326 = F_151 ( V_338 , V_340 ) ;
if ( ! V_326 ) {
F_152 ( V_265 , V_341 ) ;
F_153 ( V_18 , V_265 , L_44
L_45 ) ;
return - V_256 ;
}
V_334 = F_154 ( V_326 , 0 , 0 , 0 , ( V_338 - sizeof( * V_334 ) ) , 0 ) ;
V_336 = F_155 ( V_334 ) ;
memset ( V_336 , 0 , sizeof( * V_336 ) ) ;
V_336 -> V_342 = F_5 ( V_265 -> V_34 ) ;
V_336 -> type = V_343 ;
V_336 -> V_344 . V_345 . V_271 = V_265 -> V_271 ;
V_336 -> V_344 . V_345 . V_268 = F_69 ( V_265 ) ;
V_337 = ( char * ) V_336 + sizeof( * V_336 ) ;
memcpy ( V_337 , V_331 , sizeof( struct V_330 ) ) ;
memcpy ( V_337 + sizeof( struct V_330 ) , V_12 , V_332 ) ;
return F_147 ( V_326 , V_346 , V_340 ) ;
}
int F_156 ( struct V_71 * V_72 ,
struct V_8 * V_34 , T_5 type ,
char * V_12 , T_8 V_332 )
{
struct V_333 * V_334 ;
struct V_325 * V_326 ;
struct V_335 * V_336 ;
int V_338 = F_150 ( sizeof( * V_336 ) + V_332 ) ;
V_326 = F_151 ( V_338 , V_340 ) ;
if ( ! V_326 ) {
F_12 ( V_18 L_46 ) ;
return - V_256 ;
}
V_334 = F_154 ( V_326 , 0 , 0 , 0 , ( V_338 - sizeof( * V_334 ) ) , 0 ) ;
V_336 = F_155 ( V_334 ) ;
memset ( V_336 , 0 , sizeof( * V_336 ) ) ;
V_336 -> type = type ;
V_336 -> V_342 = F_5 ( V_34 ) ;
switch ( type ) {
case V_347 :
V_336 -> V_344 . V_348 . V_77 = V_72 -> V_77 ;
break;
case V_349 :
V_336 -> V_344 . V_350 . V_77 = V_72 -> V_77 ;
break;
}
memcpy ( ( char * ) V_336 + sizeof( * V_336 ) , V_12 , V_332 ) ;
return F_147 ( V_326 , V_351 , V_340 ) ;
}
void F_152 ( struct V_264 * V_265 , enum V_352 error )
{
struct V_333 * V_334 ;
struct V_325 * V_326 ;
struct V_335 * V_336 ;
struct V_3 * V_4 ;
int V_338 = F_150 ( sizeof( * V_336 ) ) ;
V_4 = F_146 ( V_265 -> V_34 ) ;
if ( ! V_4 )
return;
V_326 = F_151 ( V_338 , V_340 ) ;
if ( ! V_326 ) {
F_153 ( V_18 , V_265 , L_47
L_48 , error ) ;
return;
}
V_334 = F_154 ( V_326 , 0 , 0 , 0 , ( V_338 - sizeof( * V_334 ) ) , 0 ) ;
V_336 = F_155 ( V_334 ) ;
V_336 -> V_342 = F_5 ( V_265 -> V_34 ) ;
V_336 -> type = V_353 ;
V_336 -> V_344 . V_354 . error = error ;
V_336 -> V_344 . V_354 . V_271 = V_265 -> V_271 ;
V_336 -> V_344 . V_354 . V_268 = F_69 ( V_265 ) ;
F_147 ( V_326 , V_346 , V_340 ) ;
F_153 ( V_298 , V_265 , L_49 ,
error ) ;
}
void F_157 ( struct V_264 * V_265 ,
enum V_355 V_273 )
{
struct V_333 * V_334 ;
struct V_325 * V_326 ;
struct V_335 * V_336 ;
struct V_3 * V_4 ;
int V_338 = F_150 ( sizeof( * V_336 ) ) ;
V_4 = F_146 ( V_265 -> V_34 ) ;
if ( ! V_4 )
return;
V_326 = F_151 ( V_338 , V_340 ) ;
if ( ! V_326 ) {
F_153 ( V_18 , V_265 , L_47
L_50 , V_273 ) ;
return;
}
V_334 = F_154 ( V_326 , 0 , 0 , 0 , ( V_338 - sizeof( * V_334 ) ) , 0 ) ;
V_336 = F_155 ( V_334 ) ;
V_336 -> V_342 = F_5 ( V_265 -> V_34 ) ;
V_336 -> type = V_356 ;
V_336 -> V_344 . V_357 . V_273 = V_273 ;
V_336 -> V_344 . V_357 . V_271 = V_265 -> V_271 ;
V_336 -> V_344 . V_357 . V_268 = F_69 ( V_265 ) ;
F_147 ( V_326 , V_346 , V_340 ) ;
F_153 ( V_298 , V_265 , L_51 ,
V_273 ) ;
}
void F_158 ( T_5 V_77 , struct V_8 * V_34 ,
enum V_358 V_359 , T_5 V_332 ,
T_9 * V_12 )
{
struct V_333 * V_334 ;
struct V_325 * V_326 ;
struct V_335 * V_336 ;
int V_338 = F_150 ( sizeof( * V_336 ) + V_332 ) ;
V_326 = F_151 ( V_338 , V_360 ) ;
if ( ! V_326 ) {
F_12 ( V_18 L_52 ,
V_77 , V_359 ) ;
return;
}
V_334 = F_154 ( V_326 , 0 , 0 , 0 , ( V_338 - sizeof( * V_334 ) ) , 0 ) ;
V_336 = F_155 ( V_334 ) ;
V_336 -> V_342 = F_5 ( V_34 ) ;
V_336 -> type = V_361 ;
V_336 -> V_344 . V_362 . V_77 = V_77 ;
V_336 -> V_344 . V_362 . V_359 = V_359 ;
V_336 -> V_344 . V_362 . V_332 = V_332 ;
if ( V_332 )
memcpy ( ( char * ) V_336 + sizeof( * V_336 ) , V_12 , V_332 ) ;
F_147 ( V_326 , V_346 , V_360 ) ;
}
void F_159 ( T_5 V_77 , struct V_8 * V_34 ,
T_5 V_363 , T_5 V_364 , T_5 V_332 ,
T_9 * V_12 )
{
struct V_333 * V_334 ;
struct V_325 * V_326 ;
struct V_335 * V_336 ;
int V_338 = F_150 ( sizeof( * V_336 ) + V_332 ) ;
V_326 = F_151 ( V_338 , V_360 ) ;
if ( ! V_326 ) {
F_12 ( V_18 L_53 ) ;
return;
}
V_334 = F_154 ( V_326 , 0 , 0 , 0 , ( V_338 - sizeof( * V_334 ) ) , 0 ) ;
V_336 = F_155 ( V_334 ) ;
V_336 -> V_342 = F_5 ( V_34 ) ;
V_336 -> type = V_365 ;
V_336 -> V_344 . V_366 . V_77 = V_77 ;
V_336 -> V_344 . V_366 . V_363 = V_363 ;
V_336 -> V_344 . V_366 . V_364 = V_364 ;
V_336 -> V_344 . V_366 . V_332 = V_332 ;
memcpy ( ( char * ) V_336 + sizeof( * V_336 ) , V_12 , V_332 ) ;
F_147 ( V_326 , V_346 , V_360 ) ;
}
static int
F_160 ( T_5 V_327 , int V_367 , int type , int V_368 , int V_369 ,
void * V_370 , int V_371 )
{
struct V_325 * V_326 ;
struct V_333 * V_334 ;
int V_338 = F_150 ( V_371 ) ;
int V_269 = V_369 ? V_372 : 0 ;
int V_33 = V_368 ? V_373 : type ;
V_326 = F_151 ( V_338 , V_340 ) ;
if ( ! V_326 ) {
F_12 ( V_18 L_54 ) ;
return - V_256 ;
}
V_334 = F_154 ( V_326 , 0 , 0 , V_33 , ( V_338 - sizeof( * V_334 ) ) , 0 ) ;
V_334 -> V_374 = V_269 ;
memcpy ( F_155 ( V_334 ) , V_370 , V_371 ) ;
return F_147 ( V_326 , V_327 , V_340 ) ;
}
static int
F_161 ( struct V_8 * V_34 , struct V_333 * V_334 )
{
struct V_335 * V_336 = F_155 ( V_334 ) ;
struct V_375 * V_376 ;
struct V_325 * V_377 ;
struct V_264 * V_265 ;
struct V_333 * V_378 ;
struct V_335 * V_379 ;
struct V_3 * V_4 ;
int V_338 = F_150 ( sizeof( * V_336 ) +
sizeof( struct V_375 ) +
sizeof( struct V_380 ) *
V_381 ) ;
int V_15 = 0 ;
V_4 = F_146 ( V_34 ) ;
if ( ! V_4 )
return - V_339 ;
V_265 = F_75 ( V_336 -> V_382 . V_383 . V_268 , V_336 -> V_382 . V_383 . V_271 ) ;
if ( ! V_265 )
return - V_384 ;
do {
int V_385 ;
V_377 = F_151 ( V_338 , V_340 ) ;
if ( ! V_377 ) {
F_153 ( V_18 , V_265 , L_55
L_56 ) ;
return - V_256 ;
}
V_378 = F_154 ( V_377 , 0 , 0 , 0 ,
( V_338 - sizeof( * V_378 ) ) , 0 ) ;
V_379 = F_155 ( V_378 ) ;
memset ( V_379 , 0 , sizeof( * V_379 ) ) ;
V_379 -> V_342 = F_5 ( V_265 -> V_34 ) ;
V_379 -> type = V_334 -> V_386 ;
V_379 -> V_382 . V_383 . V_271 =
V_336 -> V_382 . V_383 . V_271 ;
V_379 -> V_382 . V_383 . V_268 =
V_336 -> V_382 . V_383 . V_268 ;
V_376 = (struct V_375 * )
( ( char * ) V_379 + sizeof( * V_379 ) ) ;
memset ( V_376 , 0 , sizeof( * V_376 ) ) ;
V_34 -> V_383 ( V_265 , V_376 ) ;
V_385 = F_150 ( sizeof( struct V_335 ) +
sizeof( struct V_375 ) +
sizeof( struct V_380 ) *
V_376 -> V_387 ) ;
V_385 -= sizeof( * V_378 ) ;
V_385 = F_162 ( V_385 ) ;
F_163 ( V_377 , F_164 ( V_385 ) ) ;
V_378 -> V_388 = V_385 ;
V_15 = F_147 ( V_377 , V_346 ,
V_340 ) ;
} while ( V_15 < 0 && V_15 != - V_389 );
return V_15 ;
}
int F_117 ( struct V_266 * V_276 ,
enum V_390 V_391 )
{
struct V_3 * V_4 ;
struct V_71 * V_72 ;
struct V_335 * V_336 ;
struct V_325 * V_326 ;
struct V_333 * V_334 ;
int V_392 , V_338 = F_150 ( sizeof( * V_336 ) ) ;
V_4 = F_146 ( V_276 -> V_34 ) ;
if ( ! V_4 )
return - V_339 ;
V_72 = F_81 ( V_276 ) ;
V_326 = F_151 ( V_338 , V_19 ) ;
if ( ! V_326 ) {
F_101 ( V_18 , V_276 ,
L_57
L_58 , V_391 ) ;
return - V_256 ;
}
V_334 = F_154 ( V_326 , 0 , 0 , 0 , ( V_338 - sizeof( * V_334 ) ) , 0 ) ;
V_336 = F_155 ( V_334 ) ;
V_336 -> V_342 = F_5 ( V_276 -> V_34 ) ;
V_336 -> type = V_391 ;
switch ( V_391 ) {
case V_317 :
V_336 -> V_344 . V_393 . V_77 = V_72 -> V_77 ;
V_336 -> V_344 . V_393 . V_268 = V_276 -> V_268 ;
break;
case V_316 :
V_336 -> V_344 . V_394 . V_77 = V_72 -> V_77 ;
V_336 -> V_344 . V_394 . V_268 = V_276 -> V_268 ;
break;
case V_310 :
V_336 -> V_344 . V_395 . V_77 = V_72 -> V_77 ;
V_336 -> V_344 . V_395 . V_268 = V_276 -> V_268 ;
break;
default:
F_101 ( V_18 , V_276 , L_59
L_60 , V_391 ) ;
F_165 ( V_326 ) ;
return - V_339 ;
}
V_392 = F_147 ( V_326 , V_346 , V_19 ) ;
if ( V_392 == - V_243 )
F_101 ( V_18 , V_276 ,
L_57
L_61 ,
V_391 ) ;
F_83 ( V_276 , L_62 ,
V_391 , V_392 ) ;
return V_392 ;
}
static int
F_166 ( struct V_3 * V_4 , struct V_9 * V_10 ,
struct V_335 * V_336 , T_10 V_364 ,
T_5 V_396 , T_8 V_397 ,
T_8 V_398 )
{
struct V_8 * V_34 = V_4 -> V_8 ;
struct V_266 * V_276 ;
struct V_71 * V_72 ;
V_276 = V_34 -> V_399 ( V_10 , V_397 , V_398 ,
V_396 ) ;
if ( ! V_276 )
return - V_256 ;
V_276 -> V_311 = V_364 ;
V_72 = F_81 ( V_276 ) ;
V_336 -> V_344 . V_394 . V_77 = V_72 -> V_77 ;
V_336 -> V_344 . V_394 . V_268 = V_276 -> V_268 ;
F_83 ( V_276 ,
L_63 ) ;
return 0 ;
}
static int
F_167 ( struct V_8 * V_34 , struct V_335 * V_336 )
{
struct V_264 * V_265 ;
struct V_266 * V_276 ;
V_276 = F_71 ( V_336 -> V_382 . V_400 . V_268 ) ;
if ( ! V_276 ) {
F_12 ( V_18 L_64 ,
V_336 -> V_382 . V_400 . V_268 ) ;
return - V_339 ;
}
V_265 = V_34 -> V_401 ( V_276 , V_336 -> V_382 . V_400 . V_271 ) ;
if ( ! V_265 ) {
F_101 ( V_18 , V_276 ,
L_65 ) ;
return - V_256 ;
}
V_336 -> V_344 . V_402 . V_268 = V_276 -> V_268 ;
V_336 -> V_344 . V_402 . V_271 = V_265 -> V_271 ;
F_135 ( V_265 , L_66 ) ;
return 0 ;
}
static int
F_168 ( struct V_8 * V_34 , struct V_335 * V_336 )
{
struct V_264 * V_265 ;
V_265 = F_75 ( V_336 -> V_382 . V_403 . V_268 , V_336 -> V_382 . V_403 . V_271 ) ;
if ( ! V_265 )
return - V_339 ;
F_135 ( V_265 , L_67 ) ;
if ( V_34 -> V_404 )
V_34 -> V_404 ( V_265 ) ;
return 0 ;
}
static int
F_169 ( struct V_8 * V_34 , struct V_335 * V_336 )
{
char * V_12 = ( char * ) V_336 + sizeof( * V_336 ) ;
struct V_264 * V_265 ;
struct V_266 * V_276 ;
int V_15 = 0 , V_275 = 0 ;
V_276 = F_71 ( V_336 -> V_382 . V_405 . V_268 ) ;
V_265 = F_75 ( V_336 -> V_382 . V_405 . V_268 , V_336 -> V_382 . V_405 . V_271 ) ;
if ( ! V_265 || ! V_276 )
return - V_339 ;
switch ( V_336 -> V_382 . V_405 . V_35 ) {
case V_406 :
sscanf ( V_12 , L_68 , & V_275 ) ;
V_276 -> V_299 = V_275 ;
break;
default:
V_15 = V_34 -> V_405 ( V_265 , V_336 -> V_382 . V_405 . V_35 ,
V_12 , V_336 -> V_382 . V_405 . V_338 ) ;
}
return V_15 ;
}
static int F_170 ( struct V_8 * V_34 ,
struct V_335 * V_336 , int V_407 )
{
struct V_9 * V_10 ;
struct V_408 * V_409 ;
struct V_71 * V_72 = NULL ;
int V_410 , V_15 = 0 ;
if ( ! V_34 -> V_411 )
return - V_339 ;
if ( V_407 == V_412 ) {
V_72 = F_171 ( V_336 -> V_382 . V_413 . V_77 ) ;
if ( ! V_72 ) {
F_12 ( V_18 L_69
L_70 ,
V_336 -> V_382 . V_413 . V_77 ) ;
return - V_414 ;
}
V_410 = V_336 -> V_382 . V_413 . V_410 ;
} else
V_410 = V_336 -> V_382 . V_411 . V_410 ;
V_409 = (struct V_408 * ) ( ( char * ) V_336 + sizeof( * V_336 ) ) ;
V_10 = V_34 -> V_411 ( V_72 , V_409 , V_410 ) ;
if ( F_172 ( V_10 ) ) {
V_15 = F_173 ( V_10 ) ;
goto V_415;
}
V_336 -> V_344 . V_416 . V_26 = V_10 -> V_11 ;
V_415:
if ( V_72 )
F_82 ( V_72 ) ;
return V_15 ;
}
static int F_174 ( struct V_8 * V_34 ,
T_3 V_417 )
{
struct V_264 * V_265 ;
struct V_9 * V_10 ;
if ( ! V_34 -> V_418 )
return - V_339 ;
V_10 = F_20 ( V_417 ) ;
if ( ! V_10 )
return - V_339 ;
V_265 = V_10 -> V_265 ;
if ( V_265 ) {
F_90 ( & V_265 -> V_318 ) ;
V_265 -> V_10 = NULL ;
F_92 ( & V_265 -> V_318 ) ;
}
V_34 -> V_418 ( V_10 ) ;
return 0 ;
}
static int
F_175 ( struct V_8 * V_34 ,
struct V_335 * V_336 , int V_407 )
{
struct V_9 * V_10 ;
int V_392 = 0 ;
switch ( V_407 ) {
case V_412 :
case V_419 :
V_392 = F_170 ( V_34 , V_336 , V_407 ) ;
break;
case V_420 :
if ( ! V_34 -> V_421 )
return - V_339 ;
V_10 = F_20 ( V_336 -> V_382 . V_421 . V_417 ) ;
if ( ! V_10 )
return - V_339 ;
V_336 -> V_344 . V_422 = V_34 -> V_421 ( V_10 ,
V_336 -> V_382 . V_421 . V_423 ) ;
break;
case V_424 :
V_392 = F_174 ( V_34 ,
V_336 -> V_382 . V_418 . V_417 ) ;
break;
}
return V_392 ;
}
static int
F_176 ( struct V_8 * V_34 ,
struct V_335 * V_336 )
{
struct V_71 * V_72 ;
struct V_408 * V_409 ;
int V_15 ;
if ( ! V_34 -> V_425 )
return - V_339 ;
V_72 = F_171 ( V_336 -> V_382 . V_425 . V_77 ) ;
if ( ! V_72 ) {
F_12 ( V_18 L_71 ,
V_336 -> V_382 . V_425 . V_77 ) ;
return - V_414 ;
}
V_409 = (struct V_408 * ) ( ( char * ) V_336 + sizeof( * V_336 ) ) ;
V_15 = V_34 -> V_425 ( V_72 , V_336 -> V_382 . V_425 . type ,
V_336 -> V_382 . V_425 . V_426 , V_409 ) ;
F_82 ( V_72 ) ;
return V_15 ;
}
static int
F_177 ( struct V_8 * V_34 ,
struct V_335 * V_336 )
{
char * V_12 = ( char * ) V_336 + sizeof( * V_336 ) ;
struct V_71 * V_72 ;
int V_15 ;
if ( ! V_34 -> V_427 )
return - V_428 ;
V_72 = F_171 ( V_336 -> V_382 . V_427 . V_77 ) ;
if ( ! V_72 ) {
F_12 ( V_18 L_72 ,
V_336 -> V_382 . V_427 . V_77 ) ;
return - V_414 ;
}
V_15 = V_34 -> V_427 ( V_72 , V_336 -> V_382 . V_427 . V_35 ,
V_12 , V_336 -> V_382 . V_427 . V_338 ) ;
F_82 ( V_72 ) ;
return V_15 ;
}
static int
F_178 ( struct V_8 * V_34 , struct V_335 * V_336 )
{
struct V_71 * V_72 ;
struct V_429 * V_430 ;
int V_15 ;
if ( ! V_34 -> V_431 )
return - V_428 ;
V_72 = F_171 ( V_336 -> V_382 . V_431 . V_77 ) ;
if ( ! V_72 ) {
F_12 ( V_18 L_73 ,
V_336 -> V_382 . V_431 . V_77 ) ;
return - V_414 ;
}
V_430 = (struct V_429 * ) ( ( char * ) V_336 + sizeof( * V_336 ) ) ;
V_15 = V_34 -> V_431 ( V_72 , V_430 ) ;
F_82 ( V_72 ) ;
return V_15 ;
}
static int
F_179 ( struct V_8 * V_34 ,
struct V_335 * V_336 , T_5 V_338 )
{
char * V_12 = ( char * ) V_336 + sizeof( * V_336 ) ;
struct V_71 * V_72 ;
int V_15 ;
if ( ! V_34 -> V_432 )
return - V_428 ;
V_72 = F_171 ( V_336 -> V_382 . V_433 . V_77 ) ;
if ( ! V_72 ) {
F_12 ( V_18 L_74 ,
V_336 -> V_382 . V_433 . V_77 ) ;
return - V_414 ;
}
V_15 = V_34 -> V_432 ( V_72 , V_12 , V_338 ) ;
F_82 ( V_72 ) ;
return V_15 ;
}
static int
F_180 ( struct V_8 * V_34 , struct V_335 * V_336 )
{
struct V_71 * V_72 ;
struct V_408 * V_409 ;
int V_15 ;
if ( ! V_34 -> V_434 )
return - V_428 ;
V_72 = F_171 ( V_336 -> V_382 . V_435 . V_77 ) ;
if ( ! V_72 ) {
F_12 ( V_18 L_75 ,
V_336 -> V_382 . V_435 . V_77 ) ;
return - V_414 ;
}
V_409 = (struct V_408 * ) ( ( char * ) V_336 + sizeof( * V_336 ) ) ;
V_15 = V_34 -> V_434 ( V_72 , V_336 -> V_382 . V_435 . V_73 ,
V_336 -> V_382 . V_435 . V_48 ,
V_336 -> V_382 . V_435 . V_436 ,
V_336 -> V_382 . V_435 . V_364 ,
V_409 ) ;
F_82 ( V_72 ) ;
return V_15 ;
}
static int
F_181 ( struct V_8 * V_34 , struct V_333 * V_334 )
{
struct V_335 * V_336 = F_155 ( V_334 ) ;
struct V_71 * V_72 = NULL ;
struct V_437 * V_438 ;
struct V_3 * V_4 ;
struct V_325 * V_439 ;
struct V_333 * V_440 ;
struct V_335 * V_441 ;
T_5 V_442 ;
int V_338 , V_15 = 0 ;
char * V_7 ;
if ( ! V_34 -> V_443 )
return - V_339 ;
V_4 = F_146 ( V_34 ) ;
if ( ! V_4 )
return - V_339 ;
V_442 = ( V_336 -> V_382 . V_443 . V_444 * sizeof( * V_438 ) ) ;
V_338 = F_150 ( sizeof( * V_336 ) + V_442 ) ;
V_72 = F_171 ( V_336 -> V_382 . V_443 . V_77 ) ;
if ( ! V_72 ) {
F_12 ( V_18 L_76 ,
V_445 , V_336 -> V_382 . V_443 . V_77 ) ;
return - V_414 ;
}
do {
int V_385 ;
V_439 = F_151 ( V_338 , V_19 ) ;
if ( ! V_439 ) {
F_12 ( V_18 L_77 ) ;
V_15 = - V_256 ;
goto V_446;
}
V_440 = F_154 ( V_439 , 0 , 0 , 0 ,
( V_338 - sizeof( * V_440 ) ) , 0 ) ;
V_441 = F_155 ( V_440 ) ;
memset ( V_441 , 0 , sizeof( * V_441 ) ) ;
V_441 -> V_342 = F_5 ( V_34 ) ;
V_441 -> type = V_334 -> V_386 ;
V_441 -> V_382 . V_443 . V_77 = V_336 -> V_382 . V_443 . V_77 ;
V_441 -> V_382 . V_443 . V_447 = V_336 -> V_382 . V_443 . V_447 ;
V_441 -> V_382 . V_443 . V_444 = V_336 -> V_382 . V_443 . V_444 ;
V_7 = ( char * ) ( ( char * ) V_441 + sizeof( * V_441 ) ) ;
memset ( V_7 , 0 , V_442 ) ;
V_15 = V_34 -> V_443 ( V_72 , V_336 -> V_382 . V_443 . V_447 ,
& V_441 -> V_382 . V_443 . V_444 , V_7 ) ;
V_385 = F_150 ( sizeof( * V_336 ) + V_442 ) ;
F_163 ( V_439 , F_164 ( V_385 ) ) ;
V_440 -> V_388 = V_385 ;
V_15 = F_147 ( V_439 , V_346 ,
V_19 ) ;
} while ( V_15 < 0 && V_15 != - V_389 );
V_446:
F_82 ( V_72 ) ;
return V_15 ;
}
static int F_182 ( struct V_8 * V_34 ,
struct V_335 * V_336 )
{
struct V_71 * V_72 ;
int V_15 = 0 ;
if ( ! V_34 -> V_448 )
return - V_428 ;
V_72 = F_171 ( V_336 -> V_382 . V_448 . V_77 ) ;
if ( ! V_72 ) {
F_12 ( V_18 L_78 ,
V_445 , V_336 -> V_382 . V_448 . V_77 ) ;
return - V_414 ;
}
V_15 = V_34 -> V_448 ( V_72 , V_336 -> V_382 . V_448 . V_447 ) ;
F_82 ( V_72 ) ;
return V_15 ;
}
char * F_183 ( int V_449 )
{
int V_32 ;
char * V_273 = L_79 ;
for ( V_32 = 0 ; V_32 < F_77 ( V_450 ) ; V_32 ++ ) {
if ( V_450 [ V_32 ] . V_275 & V_449 ) {
V_273 = V_450 [ V_32 ] . V_223 ;
break;
}
}
return V_273 ;
}
static int F_184 ( struct V_8 * V_34 ,
struct V_335 * V_336 , T_5 V_338 )
{
char * V_12 = ( char * ) V_336 + sizeof( * V_336 ) ;
struct V_71 * V_72 ;
struct V_81 * V_82 ;
struct V_153 * V_154 ;
struct V_1 * V_2 ;
T_5 V_222 ;
int V_15 = 0 ;
if ( ! V_34 -> V_451 ) {
V_15 = - V_428 ;
goto V_452;
}
V_72 = F_171 ( V_336 -> V_382 . V_453 . V_77 ) ;
if ( ! V_72 ) {
F_50 ( L_78 ,
V_445 , V_336 -> V_382 . V_453 . V_77 ) ;
V_15 = - V_414 ;
goto V_454;
}
V_222 = V_336 -> V_382 . V_453 . V_455 ;
V_82 = F_42 ( V_72 , V_222 ) ;
if ( ! V_82 ) {
F_50 ( L_80 ,
V_445 , V_222 , V_336 -> V_382 . V_453 . V_77 ) ;
V_15 = - V_414 ;
goto V_454;
}
V_2 = F_46 ( V_82 ) ;
if ( ! V_2 ) {
V_15 = - V_414 ;
goto V_456;
}
V_154 = F_34 ( V_2 ) ;
V_15 = V_34 -> V_451 ( V_82 , V_154 , V_12 , V_338 ) ;
F_21 ( V_2 ) ;
V_456:
F_21 ( & V_82 -> V_2 ) ;
V_454:
F_82 ( V_72 ) ;
V_452:
return V_15 ;
}
static int F_185 ( struct V_8 * V_34 ,
struct V_335 * V_336 , T_5 V_338 )
{
char * V_12 = ( char * ) V_336 + sizeof( * V_336 ) ;
struct V_71 * V_72 ;
int V_214 ;
int V_15 = 0 ;
if ( ! V_34 -> V_457 ) {
V_15 = - V_428 ;
goto V_458;
}
V_72 = F_171 ( V_336 -> V_382 . V_457 . V_77 ) ;
if ( ! V_72 ) {
F_50 ( L_78 ,
V_445 , V_336 -> V_382 . V_457 . V_77 ) ;
V_15 = - V_414 ;
goto V_454;
}
V_214 = V_34 -> V_457 ( V_72 , V_12 , V_338 ) ;
if ( V_214 >= 0 )
V_336 -> V_344 . V_459 . V_455 = V_214 ;
else
V_15 = - V_460 ;
V_454:
F_82 ( V_72 ) ;
V_458:
return V_15 ;
}
static int F_186 ( struct V_8 * V_34 ,
struct V_335 * V_336 )
{
struct V_71 * V_72 ;
struct V_81 * V_82 ;
T_5 V_222 ;
int V_15 = 0 ;
if ( ! V_34 -> V_461 ) {
V_15 = - V_428 ;
goto V_462;
}
V_72 = F_171 ( V_336 -> V_382 . V_461 . V_77 ) ;
if ( ! V_72 ) {
F_50 ( L_78 ,
V_445 , V_336 -> V_382 . V_461 . V_77 ) ;
V_15 = - V_414 ;
goto V_454;
}
V_222 = V_336 -> V_382 . V_461 . V_455 ;
V_82 = F_42 ( V_72 , V_222 ) ;
if ( ! V_82 ) {
F_50 ( L_80 ,
V_445 , V_222 , V_336 -> V_382 . V_461 . V_77 ) ;
V_15 = - V_414 ;
goto V_454;
}
V_15 = V_34 -> V_461 ( V_82 ) ;
F_21 ( & V_82 -> V_2 ) ;
V_454:
F_82 ( V_72 ) ;
V_462:
return V_15 ;
}
static int F_187 ( struct V_8 * V_34 ,
struct V_335 * V_336 )
{
struct V_71 * V_72 ;
struct V_81 * V_82 ;
struct V_153 * V_154 ;
struct V_1 * V_2 ;
T_5 V_222 ;
int V_15 = 0 ;
if ( ! V_34 -> V_463 ) {
V_15 = - V_428 ;
goto V_464;
}
V_72 = F_171 ( V_336 -> V_382 . V_463 . V_77 ) ;
if ( ! V_72 ) {
F_50 ( L_78 ,
V_445 , V_336 -> V_382 . V_463 . V_77 ) ;
V_15 = - V_414 ;
goto V_454;
}
V_222 = V_336 -> V_382 . V_463 . V_455 ;
V_82 = F_42 ( V_72 , V_222 ) ;
if ( ! V_82 ) {
F_50 ( L_80 ,
V_445 , V_222 , V_336 -> V_382 . V_463 . V_77 ) ;
V_15 = - V_414 ;
goto V_454;
}
V_2 = F_46 ( V_82 ) ;
if ( ! V_2 ) {
V_15 = - V_414 ;
goto V_456;
}
V_154 = F_34 ( V_2 ) ;
V_15 = V_34 -> V_463 ( V_82 , V_154 ) ;
F_21 ( V_2 ) ;
V_456:
F_21 ( & V_82 -> V_2 ) ;
V_454:
F_82 ( V_72 ) ;
V_464:
return V_15 ;
}
static int F_188 ( struct V_8 * V_34 ,
struct V_335 * V_336 )
{
struct V_71 * V_72 ;
struct V_81 * V_82 ;
struct V_153 * V_154 ;
struct V_1 * V_2 ;
T_5 V_222 ;
int V_15 = 0 ;
if ( ! V_34 -> V_465 ) {
V_15 = - V_428 ;
goto V_466;
}
V_72 = F_171 ( V_336 -> V_382 . V_465 . V_77 ) ;
if ( ! V_72 ) {
F_50 ( L_78 ,
V_445 , V_336 -> V_382 . V_465 . V_77 ) ;
V_15 = - V_414 ;
goto V_454;
}
V_222 = V_336 -> V_382 . V_465 . V_455 ;
V_82 = F_42 ( V_72 , V_222 ) ;
if ( ! V_82 ) {
F_50 ( L_80 ,
V_445 , V_222 , V_336 -> V_382 . V_465 . V_77 ) ;
V_15 = - V_414 ;
goto V_454;
}
V_2 = F_46 ( V_82 ) ;
if ( ! V_2 ) {
V_15 = - V_414 ;
goto V_456;
}
V_154 = F_34 ( V_2 ) ;
V_15 = V_34 -> V_465 ( V_82 , V_154 ) ;
F_21 ( V_2 ) ;
V_456:
F_21 ( & V_82 -> V_2 ) ;
V_454:
F_82 ( V_72 ) ;
V_466:
return V_15 ;
}
static int F_189 ( struct V_8 * V_34 ,
struct V_335 * V_336 )
{
struct V_71 * V_72 ;
struct V_266 * V_276 ;
int V_15 = 0 ;
if ( ! V_34 -> V_467 ) {
V_15 = - V_428 ;
goto V_468;
}
V_72 = F_171 ( V_336 -> V_382 . V_467 . V_77 ) ;
if ( ! V_72 ) {
F_50 ( L_78 ,
V_445 , V_336 -> V_382 . V_465 . V_77 ) ;
V_15 = - V_414 ;
goto V_454;
}
V_276 = F_71 ( V_336 -> V_382 . V_467 . V_268 ) ;
if ( ! V_276 ) {
F_50 ( L_81 ,
V_445 , V_336 -> V_382 . V_467 . V_268 ) ;
V_15 = - V_339 ;
goto V_454;
}
V_15 = V_34 -> V_467 ( V_276 ) ;
V_454:
F_82 ( V_72 ) ;
V_468:
return V_15 ;
}
static int
F_190 ( struct V_325 * V_326 , struct V_333 * V_334 , T_5 * V_327 )
{
int V_15 = 0 ;
struct V_335 * V_336 = F_155 ( V_334 ) ;
struct V_8 * V_34 = NULL ;
struct V_3 * V_4 ;
struct V_266 * V_276 ;
struct V_264 * V_265 ;
struct V_9 * V_10 = NULL ;
if ( V_334 -> V_386 == V_469 )
* V_327 = V_351 ;
else
* V_327 = V_346 ;
V_4 = F_146 ( F_191 ( V_336 -> V_342 ) ) ;
if ( ! V_4 )
return - V_339 ;
V_34 = V_4 -> V_8 ;
if ( ! F_192 ( V_34 -> V_470 ) )
return - V_339 ;
switch ( V_334 -> V_386 ) {
case V_471 :
V_15 = F_166 ( V_4 , V_10 , V_336 ,
F_193 ( V_326 ) . V_472 ,
V_336 -> V_382 . V_473 . V_396 ,
V_336 -> V_382 . V_473 . V_397 ,
V_336 -> V_382 . V_473 . V_398 ) ;
break;
case V_474 :
V_10 = F_20 ( V_336 -> V_382 . V_475 . V_417 ) ;
if ( ! V_10 ) {
V_15 = - V_339 ;
break;
}
V_15 = F_166 ( V_4 , V_10 , V_336 ,
F_193 ( V_326 ) . V_472 ,
V_336 -> V_382 . V_475 . V_396 ,
V_336 -> V_382 . V_475 . V_397 ,
V_336 -> V_382 . V_475 . V_398 ) ;
break;
case V_476 :
V_276 = F_71 ( V_336 -> V_382 . V_393 . V_268 ) ;
if ( V_276 )
V_34 -> V_477 ( V_276 ) ;
else
V_15 = - V_339 ;
break;
case V_478 :
V_276 = F_71 ( V_336 -> V_382 . V_393 . V_268 ) ;
if ( V_276 )
F_105 ( F_81 ( V_276 ) ,
& V_276 -> V_307 ) ;
else
V_15 = - V_339 ;
break;
case V_479 :
V_15 = F_167 ( V_34 , V_336 ) ;
break;
case V_480 :
V_15 = F_168 ( V_34 , V_336 ) ;
break;
case V_481 :
V_276 = F_71 ( V_336 -> V_382 . V_482 . V_268 ) ;
V_265 = F_75 ( V_336 -> V_382 . V_482 . V_268 , V_336 -> V_382 . V_482 . V_271 ) ;
if ( V_265 && V_265 -> V_10 )
F_174 ( V_34 , V_265 -> V_10 -> V_11 ) ;
if ( ! V_276 || ! V_265 ) {
V_15 = - V_339 ;
break;
}
V_336 -> V_344 . V_422 = V_34 -> V_483 ( V_276 , V_265 ,
V_336 -> V_382 . V_482 . V_484 ,
V_336 -> V_382 . V_482 . V_485 ) ;
if ( V_336 -> V_344 . V_422 || ! V_34 -> V_411 )
break;
V_10 = F_20 ( V_336 -> V_382 . V_482 . V_484 ) ;
if ( V_10 ) {
V_10 -> V_265 = V_265 ;
F_90 ( & V_265 -> V_318 ) ;
V_265 -> V_10 = V_10 ;
F_92 ( & V_265 -> V_318 ) ;
} else
F_153 ( V_18 , V_265 ,
L_82
L_83 ) ;
break;
case V_486 :
V_15 = F_169 ( V_34 , V_336 ) ;
break;
case V_487 :
V_265 = F_75 ( V_336 -> V_382 . V_488 . V_268 , V_336 -> V_382 . V_488 . V_271 ) ;
if ( V_265 )
V_336 -> V_344 . V_422 = V_34 -> V_488 ( V_265 ) ;
else
V_15 = - V_339 ;
break;
case V_489 :
V_265 = F_75 ( V_336 -> V_382 . V_490 . V_268 , V_336 -> V_382 . V_490 . V_271 ) ;
if ( V_265 )
V_34 -> V_490 ( V_265 , V_336 -> V_382 . V_490 . V_491 ) ;
else
V_15 = - V_339 ;
break;
case V_492 :
V_265 = F_75 ( V_336 -> V_382 . V_493 . V_268 , V_336 -> V_382 . V_493 . V_271 ) ;
if ( V_265 )
V_336 -> V_344 . V_422 = V_34 -> V_493 ( V_265 ,
(struct V_330 * ) ( ( char * ) V_336 + sizeof( * V_336 ) ) ,
( char * ) V_336 + sizeof( * V_336 ) + V_336 -> V_382 . V_493 . V_494 ,
V_336 -> V_382 . V_493 . V_332 ) ;
else
V_15 = - V_339 ;
break;
case V_495 :
V_15 = F_161 ( V_34 , V_334 ) ;
break;
case V_419 :
case V_420 :
case V_424 :
case V_412 :
V_15 = F_175 ( V_34 , V_336 , V_334 -> V_386 ) ;
break;
case V_496 :
V_15 = F_176 ( V_34 , V_336 ) ;
break;
case V_497 :
V_15 = F_177 ( V_34 , V_336 ) ;
break;
case V_469 :
V_15 = F_178 ( V_34 , V_336 ) ;
break;
case V_498 :
V_15 = F_179 ( V_34 , V_336 ,
F_194 ( V_334 , sizeof( * V_336 ) ) ) ;
break;
case V_499 :
V_15 = F_180 ( V_34 , V_336 ) ;
break;
case V_500 :
V_15 = F_181 ( V_34 , V_334 ) ;
break;
case V_501 :
V_15 = F_182 ( V_34 , V_336 ) ;
break;
case V_502 :
V_15 = F_184 ( V_34 , V_336 ,
F_194 ( V_334 ,
sizeof( * V_336 ) ) ) ;
break;
case V_503 :
V_15 = F_185 ( V_34 , V_336 ,
F_194 ( V_334 , sizeof( * V_336 ) ) ) ;
break;
case V_504 :
V_15 = F_186 ( V_34 , V_336 ) ;
break;
case V_505 :
V_15 = F_187 ( V_34 , V_336 ) ;
break;
case V_506 :
V_15 = F_188 ( V_34 , V_336 ) ;
break;
case V_507 :
V_15 = F_189 ( V_34 , V_336 ) ;
break;
default:
V_15 = - V_428 ;
break;
}
F_195 ( V_34 -> V_470 ) ;
return V_15 ;
}
static void
F_196 ( struct V_325 * V_326 )
{
F_90 ( & V_508 ) ;
while ( V_326 -> V_338 >= V_509 ) {
int V_15 ;
T_5 V_510 ;
struct V_333 * V_334 ;
struct V_335 * V_336 ;
T_5 V_327 ;
V_334 = F_197 ( V_326 ) ;
if ( V_334 -> V_388 < sizeof( * V_334 ) ||
V_326 -> V_338 < V_334 -> V_388 ) {
break;
}
V_336 = F_155 ( V_334 ) ;
V_510 = F_164 ( V_334 -> V_388 ) ;
if ( V_510 > V_326 -> V_338 )
V_510 = V_326 -> V_338 ;
V_15 = F_190 ( V_326 , V_334 , & V_327 ) ;
if ( V_15 ) {
V_336 -> type = V_511 ;
V_336 -> V_512 = V_15 ;
}
do {
if ( V_336 -> type == V_495 && ! V_15 )
break;
if ( V_336 -> type == V_500 && ! V_15 )
break;
V_15 = F_160 ( V_327 , V_334 -> V_513 ,
V_334 -> V_386 , 0 , 0 , V_336 , sizeof( * V_336 ) ) ;
} while ( V_15 < 0 && V_15 != - V_389 && V_15 != - V_243 );
F_198 ( V_326 , V_510 ) ;
}
F_92 ( & V_508 ) ;
}
static T_4 F_199 ( struct V_30 * V_22 ,
struct V_31 * V_6 , int V_32 )
{
struct V_1 * V_260 = F_25 ( V_22 , struct V_1 , V_22 ) ;
struct V_264 * V_265 = F_200 ( V_260 ) ;
struct V_8 * V_33 = V_265 -> V_34 ;
int V_35 ;
if ( V_6 == & V_514 . V_6 )
V_35 = V_515 ;
else if ( V_6 == & V_516 . V_6 )
V_35 = V_517 ;
else if ( V_6 == & V_518 . V_6 )
V_35 = V_519 ;
else if ( V_6 == & V_520 . V_6 )
V_35 = V_521 ;
else if ( V_6 == & V_522 . V_6 )
V_35 = V_523 ;
else if ( V_6 == & V_524 . V_6 )
V_35 = V_525 ;
else if ( V_6 == & V_526 . V_6 )
V_35 = V_527 ;
else if ( V_6 == & V_528 . V_6 )
V_35 = V_529 ;
else if ( V_6 == & V_530 . V_6 )
V_35 = V_531 ;
else if ( V_6 == & V_532 . V_6 )
V_35 = V_533 ;
else if ( V_6 == & V_534 . V_6 )
V_35 = V_535 ;
else if ( V_6 == & V_536 . V_6 )
V_35 = V_537 ;
else if ( V_6 == & V_538 . V_6 )
V_35 = V_539 ;
else if ( V_6 == & V_540 . V_6 )
V_35 = V_541 ;
else if ( V_6 == & V_542 . V_6 )
V_35 = V_543 ;
else if ( V_6 == & V_544 . V_6 )
V_35 = V_545 ;
else if ( V_6 == & V_546 . V_6 )
V_35 = V_547 ;
else if ( V_6 == & V_548 . V_6 )
V_35 = V_549 ;
else if ( V_6 == & V_550 . V_6 )
V_35 = V_551 ;
else if ( V_6 == & V_552 . V_6 )
V_35 = V_553 ;
else if ( V_6 == & V_554 . V_6 )
V_35 = V_555 ;
else if ( V_6 == & V_556 . V_6 )
V_35 = V_557 ;
else if ( V_6 == & V_558 . V_6 )
V_35 = V_559 ;
else if ( V_6 == & V_560 . V_6 )
V_35 = V_561 ;
else if ( V_6 == & V_562 . V_6 )
V_35 = V_563 ;
else if ( V_6 == & V_564 . V_6 )
V_35 = V_565 ;
else if ( V_6 == & V_566 . V_6 )
V_35 = V_567 ;
else if ( V_6 == & V_568 . V_6 )
V_35 = V_569 ;
else if ( V_6 == & V_570 . V_6 )
V_35 = V_571 ;
else {
F_26 ( 1 , L_84 ) ;
return 0 ;
}
return V_33 -> V_69 ( V_572 , V_35 ) ;
}
static T_1
F_201 ( struct V_1 * V_2 , struct V_5 * V_6 ,
char * V_7 )
{
struct V_266 * V_276 = F_70 ( V_2 -> V_29 ) ;
return sprintf ( V_7 , L_85 , F_76 ( V_276 -> V_273 ) ) ;
}
static T_1
F_202 ( struct V_1 * V_2 , struct V_5 * V_6 ,
char * V_7 )
{
struct V_266 * V_276 = F_70 ( V_2 -> V_29 ) ;
return sprintf ( V_7 , L_86 , V_276 -> V_311 ) ;
}
static T_1
F_203 ( struct V_1 * V_2 , struct V_5 * V_6 ,
char * V_7 )
{
struct V_266 * V_276 = F_70 ( V_2 -> V_29 ) ;
return sprintf ( V_7 , L_86 , V_276 -> V_215 ) ;
}
static T_4 F_204 ( struct V_30 * V_22 ,
struct V_31 * V_6 , int V_32 )
{
struct V_1 * V_260 = F_25 ( V_22 , struct V_1 , V_22 ) ;
struct V_266 * V_276 = F_205 ( V_260 ) ;
struct V_8 * V_33 = V_276 -> V_34 ;
int V_35 ;
if ( V_6 == & V_573 . V_6 )
V_35 = V_574 ;
else if ( V_6 == & V_575 . V_6 )
V_35 = V_576 ;
else if ( V_6 == & V_577 . V_6 )
V_35 = V_578 ;
else if ( V_6 == & V_579 . V_6 )
V_35 = V_580 ;
else if ( V_6 == & V_581 . V_6 )
V_35 = V_582 ;
else if ( V_6 == & V_583 . V_6 )
V_35 = V_584 ;
else if ( V_6 == & V_585 . V_6 )
V_35 = V_586 ;
else if ( V_6 == & V_587 . V_6 )
V_35 = V_588 ;
else if ( V_6 == & V_589 . V_6 )
V_35 = V_590 ;
else if ( V_6 == & V_591 . V_6 )
V_35 = V_592 ;
else if ( V_6 == & V_593 . V_6 )
V_35 = V_594 ;
else if ( V_6 == & V_595 . V_6 )
V_35 = V_596 ;
else if ( V_6 == & V_597 . V_6 )
V_35 = V_598 ;
else if ( V_6 == & V_599 . V_6 )
V_35 = V_600 ;
else if ( V_6 == & V_601 . V_6 )
V_35 = V_602 ;
else if ( V_6 == & V_603 . V_6 )
V_35 = V_604 ;
else if ( V_6 == & V_605 . V_6 )
V_35 = V_606 ;
else if ( V_6 == & V_607 . V_6 )
V_35 = V_608 ;
else if ( V_6 == & V_609 . V_6 )
V_35 = V_610 ;
else if ( V_6 == & V_611 . V_6 )
V_35 = V_612 ;
else if ( V_6 == & V_613 . V_6 )
V_35 = V_614 ;
else if ( V_6 == & V_615 . V_6 )
V_35 = V_616 ;
else if ( V_6 == & V_617 . V_6 )
V_35 = V_618 ;
else if ( V_6 == & V_619 . V_6 )
V_35 = V_620 ;
else if ( V_6 == & V_621 . V_6 )
V_35 = V_622 ;
else if ( V_6 == & V_623 . V_6 )
V_35 = V_624 ;
else if ( V_6 == & V_625 . V_6 )
V_35 = V_626 ;
else if ( V_6 == & V_627 . V_6 )
V_35 = V_628 ;
else if ( V_6 == & V_629 . V_6 )
V_35 = V_630 ;
else if ( V_6 == & V_631 . V_6 )
V_35 = V_632 ;
else if ( V_6 == & V_633 . V_6 )
V_35 = V_634 ;
else if ( V_6 == & V_635 . V_6 )
V_35 = V_636 ;
else if ( V_6 == & V_637 . V_6 )
V_35 = V_638 ;
else if ( V_6 == & V_639 . V_6 )
V_35 = V_640 ;
else if ( V_6 == & V_641 . V_6 )
V_35 = V_642 ;
else if ( V_6 == & V_643 . V_6 )
V_35 = V_644 ;
else if ( V_6 == & V_645 . V_6 )
V_35 = V_646 ;
else if ( V_6 == & V_647 . V_6 )
V_35 = V_648 ;
else if ( V_6 == & V_649 . V_6 )
V_35 = V_650 ;
else if ( V_6 == & V_651 . V_6 )
V_35 = V_652 ;
else if ( V_6 == & V_653 . V_6 )
return V_654 | V_655 ;
else if ( V_6 == & V_656 . V_6 )
return V_654 ;
else if ( V_6 == & V_657 . V_6 )
return V_654 ;
else if ( V_6 == & V_658 . V_6 )
return V_654 ;
else {
F_26 ( 1 , L_87 ) ;
return 0 ;
}
return V_33 -> V_69 ( V_572 , V_35 ) ;
}
static T_4 F_206 ( struct V_30 * V_22 ,
struct V_31 * V_6 , int V_32 )
{
struct V_1 * V_260 = F_25 ( V_22 , struct V_1 , V_22 ) ;
struct V_71 * V_72 = F_207 ( V_260 ) ;
struct V_3 * V_4 = F_55 ( V_72 -> V_231 ) ;
int V_35 ;
if ( V_6 == & V_659 . V_6 )
V_35 = V_660 ;
else if ( V_6 == & V_661 . V_6 )
V_35 = V_662 ;
else if ( V_6 == & V_663 . V_6 )
V_35 = V_664 ;
else if ( V_6 == & V_665 . V_6 )
V_35 = V_666 ;
else if ( V_6 == & V_667 . V_6 )
V_35 = V_668 ;
else if ( V_6 == & V_669 . V_6 )
V_35 = V_670 ;
else {
F_26 ( 1 , L_88 ) ;
return 0 ;
}
return V_4 -> V_8 -> V_69 ( V_671 , V_35 ) ;
}
char * F_208 ( struct V_71 * V_72 )
{
int V_32 ;
char * V_672 = L_79 ;
struct V_249 * V_250 = V_72 -> V_261 ;
T_5 V_673 = V_250 -> V_673 ;
for ( V_32 = 0 ; V_32 < F_77 ( V_674 ) ; V_32 ++ ) {
if ( V_674 [ V_32 ] . V_275 & V_673 ) {
V_672 = V_674 [ V_32 ] . V_223 ;
break;
}
}
return V_672 ;
}
char * F_209 ( struct V_71 * V_72 )
{
int V_32 ;
char * V_273 = L_79 ;
struct V_249 * V_250 = V_72 -> V_261 ;
T_5 V_675 = V_250 -> V_675 ;
for ( V_32 = 0 ; V_32 < F_77 ( V_676 ) ; V_32 ++ ) {
if ( V_676 [ V_32 ] . V_275 & V_675 ) {
V_273 = V_676 [ V_32 ] . V_223 ;
break;
}
}
return V_273 ;
}
static int F_210 ( struct V_677 * V_678 ,
struct V_1 * V_2 )
{
struct V_266 * V_276 ;
struct V_71 * V_72 ;
struct V_3 * V_4 ;
if ( ! F_84 ( V_2 ) )
return 0 ;
V_276 = F_70 ( V_2 ) ;
V_72 = F_81 ( V_276 ) ;
if ( ! V_72 -> V_231 )
return 0 ;
V_4 = F_55 ( V_72 -> V_231 ) ;
if ( V_4 -> V_679 . V_680 . V_20 != & V_681 . V_20 )
return 0 ;
return & V_4 -> V_679 . V_680 == V_678 ;
}
static int F_211 ( struct V_677 * V_678 ,
struct V_1 * V_2 )
{
struct V_266 * V_276 ;
struct V_264 * V_265 ;
struct V_71 * V_72 ;
struct V_3 * V_4 ;
if ( ! F_136 ( V_2 ) )
return 0 ;
V_265 = F_134 ( V_2 ) ;
V_276 = F_70 ( V_265 -> V_2 . V_29 ) ;
V_72 = F_81 ( V_276 ) ;
if ( ! V_72 -> V_231 )
return 0 ;
V_4 = F_55 ( V_72 -> V_231 ) ;
if ( V_4 -> V_682 . V_680 . V_20 != & V_683 . V_20 )
return 0 ;
return & V_4 -> V_682 . V_680 == V_678 ;
}
static int F_212 ( struct V_677 * V_678 ,
struct V_1 * V_2 )
{
struct V_71 * V_72 ;
struct V_3 * V_4 ;
if ( ! F_213 ( V_2 ) )
return 0 ;
V_72 = F_64 ( V_2 ) ;
if ( ! V_72 -> V_231 ||
V_72 -> V_231 -> V_684 . V_680 . V_20 != & V_685 . V_20 )
return 0 ;
V_4 = F_55 ( V_72 -> V_231 ) ;
return & V_4 -> V_33 . V_684 . V_680 == V_678 ;
}
struct V_686 *
F_214 ( struct V_8 * V_323 )
{
struct V_3 * V_4 ;
unsigned long V_269 ;
int V_15 ;
F_56 ( ! V_323 ) ;
V_4 = F_146 ( V_323 ) ;
if ( V_4 )
return NULL ;
V_4 = F_13 ( sizeof( * V_4 ) , V_19 ) ;
if ( ! V_4 )
return NULL ;
F_120 ( & V_4 -> V_687 ) ;
V_4 -> V_8 = V_323 ;
V_4 -> V_33 . V_688 = F_93 ;
V_4 -> V_33 . V_689 = 1 ;
V_4 -> V_2 . V_20 = & V_690 ;
F_14 ( & V_4 -> V_2 , L_89 , V_323 -> V_223 ) ;
V_15 = F_15 ( & V_4 -> V_2 ) ;
if ( V_15 )
goto V_691;
V_15 = F_16 ( & V_4 -> V_2 . V_22 , & V_692 ) ;
if ( V_15 )
goto V_24;
V_4 -> V_33 . V_684 . V_680 . V_20 = & V_685 . V_20 ;
V_4 -> V_33 . V_684 . V_680 . V_693 = F_212 ;
V_4 -> V_33 . V_684 . V_680 . V_694 = & V_695 ;
V_4 -> V_33 . V_696 = sizeof( struct V_249 ) ;
F_215 ( & V_4 -> V_33 . V_684 ) ;
V_4 -> V_682 . V_680 . V_20 = & V_683 . V_20 ;
V_4 -> V_682 . V_680 . V_693 = F_211 ;
V_4 -> V_682 . V_680 . V_694 = & V_697 ;
F_215 ( & V_4 -> V_682 ) ;
V_4 -> V_679 . V_680 . V_20 = & V_681 . V_20 ;
V_4 -> V_679 . V_680 . V_693 = F_210 ;
V_4 -> V_679 . V_680 . V_694 = & V_698 ;
F_215 ( & V_4 -> V_679 ) ;
F_72 ( & V_324 , V_269 ) ;
F_130 ( & V_4 -> V_687 , & V_699 ) ;
F_74 ( & V_324 , V_269 ) ;
F_12 ( V_700 L_90 , V_323 -> V_223 ) ;
return & V_4 -> V_33 ;
V_24:
F_17 ( & V_4 -> V_2 ) ;
return NULL ;
V_691:
F_3 ( V_4 ) ;
return NULL ;
}
int F_216 ( struct V_8 * V_323 )
{
struct V_3 * V_4 ;
unsigned long V_269 ;
F_56 ( ! V_323 ) ;
F_90 ( & V_508 ) ;
V_4 = F_146 ( V_323 ) ;
F_56 ( ! V_4 ) ;
F_72 ( & V_324 , V_269 ) ;
F_140 ( & V_4 -> V_687 ) ;
F_74 ( & V_324 , V_269 ) ;
F_217 ( & V_4 -> V_682 ) ;
F_217 ( & V_4 -> V_679 ) ;
F_217 ( & V_4 -> V_33 . V_684 ) ;
F_19 ( & V_4 -> V_2 . V_22 , & V_692 ) ;
F_17 ( & V_4 -> V_2 ) ;
F_92 ( & V_508 ) ;
return 0 ;
}
static T_11 int F_218 ( void )
{
int V_15 ;
struct V_701 V_702 = {
. V_703 = 1 ,
. V_704 = F_196 ,
} ;
F_12 ( V_298 L_91 ,
V_705 ) ;
F_65 ( & V_313 , 0 ) ;
V_15 = F_219 ( & V_690 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_219 ( & V_17 ) ;
if ( V_15 )
goto V_706;
V_15 = F_219 ( & V_75 ) ;
if ( V_15 )
goto V_707;
V_15 = F_220 ( & V_685 ) ;
if ( V_15 )
goto V_708;
V_15 = F_220 ( & V_683 ) ;
if ( V_15 )
goto V_709;
V_15 = F_220 ( & V_681 ) ;
if ( V_15 )
goto V_710;
V_15 = F_221 ( & V_213 ) ;
if ( V_15 )
goto V_711;
V_329 = F_222 ( & V_712 , V_713 , & V_702 ) ;
if ( ! V_329 ) {
V_15 = - V_714 ;
goto V_715;
}
V_304 = F_223 ( L_92 ) ;
if ( ! V_304 ) {
V_15 = - V_256 ;
goto V_716;
}
return 0 ;
V_716:
F_224 ( V_329 ) ;
V_715:
F_225 ( & V_213 ) ;
V_711:
F_226 ( & V_681 ) ;
V_710:
F_226 ( & V_683 ) ;
V_709:
F_226 ( & V_685 ) ;
V_708:
F_227 ( & V_75 ) ;
V_707:
F_227 ( & V_17 ) ;
V_706:
F_227 ( & V_690 ) ;
return V_15 ;
}
static void T_12 F_228 ( void )
{
F_229 ( V_304 ) ;
F_224 ( V_329 ) ;
F_225 ( & V_213 ) ;
F_226 ( & V_683 ) ;
F_226 ( & V_681 ) ;
F_226 ( & V_685 ) ;
F_227 ( & V_17 ) ;
F_227 ( & V_75 ) ;
F_227 ( & V_690 ) ;
}
