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
static int F_18 ( struct V_1 * V_2 )
{
F_19 ( V_2 -> V_32 . V_51 , L_1 , V_52 ) ;
F_1 ( V_2 , ( T_1 * ) & V_2 -> V_32 . V_53 ) ;
memcpy ( V_2 -> V_32 . V_54 , V_55 ,
sizeof( V_55 ) ) ;
V_2 -> V_32 . V_56 = V_57 ;
V_2 -> V_32 . V_58 = V_59 ;
V_2 -> V_32 . V_60 =
F_20 ( V_61 ) |
F_20 ( V_62 ) |
F_20 ( V_63 ) |
F_20 ( V_64 ) |
F_20 ( V_65 ) |
F_20 ( V_66 ) |
F_20 ( V_67 ) |
F_20 ( V_68 ) |
F_20 ( V_69 ) |
F_20 ( V_70 ) |
F_20 ( V_71 ) |
F_20 ( V_72 ) |
F_20 ( V_73 ) |
F_20 ( V_74 ) |
F_20 ( V_75 ) |
F_20 ( V_76 ) |
F_20 ( V_77 ) |
F_20 ( V_78 ) |
F_20 ( V_79 ) ;
V_2 -> V_32 . V_60 |=
F_20 ( V_80 ) |
F_20 ( V_81 ) |
F_20 ( V_82 ) |
F_20 ( V_83 ) ;
V_2 -> V_32 . V_84 = V_85 ;
V_2 -> V_32 . V_86 = 1 ;
V_2 -> V_32 . V_87 = V_2 -> V_88 ;
V_2 -> V_32 . V_89 = V_90 ;
V_2 -> V_32 . V_91 = V_92 ;
V_2 -> V_32 . V_93 = V_94 ;
V_2 -> V_32 . V_95 = V_96 ;
V_2 -> V_32 . V_97 = F_17 ;
V_2 -> V_32 . V_98 = V_99 ;
V_2 -> V_32 . V_100 = V_101 ;
V_2 -> V_32 . V_102 = V_103 ;
V_2 -> V_32 . V_104 = V_105 ;
V_2 -> V_32 . V_106 = V_107 ;
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
V_2 -> V_32 . V_154 = & V_2 -> V_5 . V_155 -> V_2 ;
V_2 -> V_32 . V_156 = V_157 ;
if ( F_21 ( V_2 ) == V_158 ) {
V_2 -> V_32 . V_60 |=
F_20 ( V_159 ) |
F_20 ( V_160 ) |
F_20 ( V_161 ) |
F_20 ( V_162 ) |
F_20 ( V_163 ) ;
V_2 -> V_32 . V_164 = V_165 ;
V_2 -> V_32 . V_166 = V_167 ;
V_2 -> V_32 . V_168 = V_169 ;
V_2 -> V_32 . V_170 = V_171 ;
V_2 -> V_32 . V_172 = V_173 ;
}
return F_22 ( & V_2 -> V_32 , NULL ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
F_24 ( & V_2 -> V_28 ) ;
V_2 -> V_14 = F_25 ( sizeof( union V_7 ) *
V_13 , V_174 ) ;
if ( ! V_2 -> V_14 )
goto V_175;
F_26 ( & V_2 -> V_12 ) ;
V_2 -> V_176 = F_25 ( sizeof( struct V_177 * ) *
V_178 , V_174 ) ;
if ( ! V_2 -> V_176 )
goto V_175;
if ( V_2 -> V_179 . V_180 ) {
V_2 -> V_181 = F_25 ( sizeof( struct V_182 * ) *
V_183 , V_174 ) ;
if ( ! V_2 -> V_181 )
goto V_175;
}
V_2 -> V_184 = F_25 ( sizeof( V_185 ) * V_186 , V_174 ) ;
if ( V_2 -> V_184 == NULL )
goto V_175;
F_27 ( V_2 ) ;
F_26 ( & V_2 -> V_187 . V_188 ) ;
F_26 ( & V_2 -> V_189 ) ;
return 0 ;
V_175:
F_28 ( L_2 , V_190 , V_2 -> V_191 ) ;
return - V_192 ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_30 ( V_2 -> V_184 ) ;
F_30 ( V_2 -> V_181 ) ;
F_30 ( V_2 -> V_176 ) ;
F_30 ( V_2 -> V_14 ) ;
}
static T_2 F_31 ( struct V_31 * V_31 , struct V_193 * V_179 ,
char * V_194 )
{
struct V_1 * V_2 = F_32 ( V_31 ) ;
return F_33 ( V_194 , V_195 , L_3 , V_2 -> V_5 . V_155 -> V_196 ) ;
}
static T_2 F_34 ( struct V_31 * V_31 , struct V_193 * V_179 ,
char * V_194 )
{
struct V_1 * V_2 = F_32 ( V_31 ) ;
return F_33 ( V_194 , V_195 , L_4 , & V_2 -> V_179 . V_197 [ 0 ] ) ;
}
static T_2 F_35 ( struct V_31 * V_31 ,
struct V_193 * V_179 , char * V_194 )
{
struct V_1 * V_2 = F_32 ( V_31 ) ;
return F_33 ( V_194 , V_195 , L_4 , & V_2 -> V_198 [ 0 ] ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < F_37 ( V_199 ) ; V_9 ++ )
F_38 ( & V_2 -> V_32 . V_2 , V_199 [ V_9 ] ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
union V_7 * V_15 = & V_2 -> V_14 [ 0 ] ;
V_15 -> V_200 . V_201 = F_40 ( 0xfe80000000000000LL ) ;
F_1 ( V_2 , & V_15 -> V_202 [ 8 ] ) ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_18 * V_203 )
{
struct V_204 * V_205 ;
union V_7 V_20 ;
V_205 = F_42 ( V_203 ) ;
if ( V_205 ) {
F_43 (in_dev) {
F_15 ( V_41 -> V_43 ,
(struct V_44 * ) & V_20 ) ;
F_2 ( V_2 , & V_20 ) ;
}
F_44 ( V_205 ) ;
F_45 ( V_205 ) ;
}
}
static void F_46 ( struct V_1 * V_2 ,
struct V_18 * V_203 )
{
#if F_47 ( V_206 )
struct V_207 * V_208 ;
union V_7 * V_209 ;
struct V_45 * V_210 ;
V_208 = F_48 ( V_203 ) ;
if ( V_208 ) {
F_49 ( & V_208 -> V_188 ) ;
F_50 (ifp, &in6_dev->addr_list, if_list) {
V_209 = (union V_7 * ) & V_210 -> V_46 ;
F_2 ( V_2 , V_209 ) ;
}
F_51 ( & V_208 -> V_188 ) ;
F_52 ( V_208 ) ;
}
#endif
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_18 * V_211 ;
F_54 (&init_net, net_dev) {
struct V_18 * V_212 = F_7 ( V_211 ) ?
F_7 ( V_211 ) : V_211 ;
if ( V_212 == V_2 -> V_5 . V_19 ) {
F_39 ( V_2 ) ;
F_41 ( V_2 , V_211 ) ;
F_46 ( V_2 , V_211 ) ;
}
}
}
static struct V_1 * F_55 ( struct V_213 * V_214 )
{
int V_215 = 0 , V_9 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) F_56 ( sizeof( struct V_1 ) ) ;
if ( ! V_2 ) {
F_28 ( L_5 ) ;
return NULL ;
}
V_2 -> V_216 = F_25 ( sizeof( struct V_217 ) , V_174 ) ;
if ( ! V_2 -> V_216 )
goto V_218;
memcpy ( & V_2 -> V_5 , V_214 , sizeof( * V_214 ) ) ;
V_2 -> V_191 = F_57 ( & V_219 , NULL , 0 , 0 , V_174 ) ;
if ( V_2 -> V_191 < 0 )
goto V_218;
V_215 = F_58 ( V_2 ) ;
if ( V_215 )
goto V_220;
V_215 = F_23 ( V_2 ) ;
if ( V_215 )
goto V_175;
F_59 ( V_2 ) ;
F_53 ( V_2 ) ;
V_215 = F_18 ( V_2 ) ;
if ( V_215 )
goto V_175;
for ( V_9 = 0 ; V_9 < F_37 ( V_199 ) ; V_9 ++ )
if ( F_60 ( & V_2 -> V_32 . V_2 , V_199 [ V_9 ] ) )
goto V_221;
F_61 ( & V_222 ) ;
F_62 ( & V_2 -> V_223 , & V_224 ) ;
F_63 ( & V_222 ) ;
F_64 ( V_2 ) ;
F_65 ( & V_2 -> V_225 , V_226 ) ;
F_66 ( & V_2 -> V_225 , F_67 ( 1000 ) ) ;
F_68 ( L_6 ,
F_69 ( & V_2 -> V_5 . V_155 -> V_2 ) , F_70 ( V_2 ) ,
F_71 ( V_2 ) , V_2 -> V_198 ,
V_2 -> V_227 ) ;
F_68 ( L_7 ,
F_69 ( & V_2 -> V_5 . V_155 -> V_2 ) , V_2 -> V_191 ) ;
return V_2 ;
V_221:
F_36 ( V_2 ) ;
V_175:
F_29 ( V_2 ) ;
F_72 ( V_2 ) ;
V_220:
F_73 ( & V_219 , V_2 -> V_191 ) ;
V_218:
F_30 ( V_2 -> V_216 ) ;
F_74 ( & V_2 -> V_32 ) ;
F_28 ( L_8 , V_190 , V_215 ) ;
return NULL ;
}
static void F_75 ( struct V_228 * V_229 )
{
struct V_1 * V_2 = F_76 ( V_229 , struct V_1 , V_229 ) ;
F_73 ( & V_219 , V_2 -> V_191 ) ;
F_30 ( V_2 -> V_216 ) ;
F_74 ( & V_2 -> V_32 ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
F_78 ( & V_2 -> V_225 ) ;
F_36 ( V_2 ) ;
F_79 ( & V_2 -> V_32 ) ;
F_80 ( V_2 ) ;
F_61 ( & V_222 ) ;
F_81 ( & V_2 -> V_223 ) ;
F_63 ( & V_222 ) ;
F_29 ( V_2 ) ;
F_72 ( V_2 ) ;
F_82 ( & V_2 -> V_229 , F_75 ) ;
}
static int F_83 ( struct V_1 * V_2 )
{
struct V_21 V_230 ;
V_230 . V_17 = V_231 ;
V_230 . V_33 . V_34 = 1 ;
V_230 . V_31 = & V_2 -> V_32 ;
F_12 ( & V_230 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 )
{
int V_9 ;
struct V_182 * V_232 , * * V_233 ;
struct V_21 V_234 ;
struct V_235 V_236 ;
int V_237 = V_238 ;
V_236 . V_239 = V_240 ;
F_11 ( & V_2 -> V_28 ) ;
if ( V_2 -> V_181 ) {
V_233 = V_2 -> V_181 ;
for ( V_9 = 0 ; V_9 < V_183 ; V_9 ++ ) {
V_232 = V_233 [ V_9 ] ;
if ( V_232 && V_232 -> V_241 . V_242 != V_243 ) {
F_85 ( & V_232 -> V_241 , & V_236 , V_237 ) ;
V_234 . V_17 = V_244 ;
V_234 . V_33 . V_232 = & V_232 -> V_241 ;
V_234 . V_31 = & V_2 -> V_32 ;
F_12 ( & V_234 ) ;
}
}
}
F_13 ( & V_2 -> V_28 ) ;
V_234 . V_17 = V_245 ;
V_234 . V_33 . V_34 = 1 ;
V_234 . V_31 = & V_2 -> V_32 ;
F_12 ( & V_234 ) ;
return 0 ;
}
static void F_86 ( struct V_1 * V_2 )
{
F_84 ( V_2 ) ;
F_77 ( V_2 ) ;
}
static void F_87 ( struct V_1 * V_2 , T_3 V_17 )
{
switch ( V_17 ) {
case V_246 :
F_83 ( V_2 ) ;
break;
case V_247 :
F_84 ( V_2 ) ;
break;
case V_248 :
F_86 ( V_2 ) ;
break;
}
}
static void F_88 ( void )
{
#if F_47 ( V_206 )
F_89 ( & V_249 ) ;
#endif
}
static void F_90 ( void )
{
F_91 ( & V_250 ) ;
}
static int T_4 F_92 ( void )
{
int V_215 ;
F_93 () ;
V_215 = F_94 ( & V_250 ) ;
if ( V_215 )
return V_215 ;
#if F_47 ( V_206 )
V_215 = F_95 ( & V_249 ) ;
if ( V_215 )
goto V_251;
#endif
V_215 = F_96 ( & V_252 ) ;
if ( V_215 )
goto V_253;
return 0 ;
V_253:
#if F_47 ( V_206 )
F_88 () ;
V_251:
#endif
F_90 () ;
return V_215 ;
}
static void T_5 F_97 ( void )
{
F_98 ( & V_252 ) ;
F_88 () ;
F_90 () ;
F_99 () ;
}
