static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 , int V_4 ,
int V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_3 * V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
unsigned char V_15 ;
char V_16 ;
int V_17 = 0 ;
int V_18 ;
V_19:
V_18 = - V_20 ;
F_2 () ;
F_3 (answer, &inetsw6[sock->type], list) {
V_18 = 0 ;
if ( V_4 == V_12 -> V_4 ) {
if ( V_4 != V_21 )
break;
} else {
if ( V_21 == V_4 ) {
V_4 = V_12 -> V_4 ;
break;
}
if ( V_21 == V_12 -> V_4 )
break;
}
V_18 = - V_22 ;
}
if ( V_18 ) {
if ( V_17 < 2 ) {
F_4 () ;
if ( ++ V_17 == 1 )
F_5 ( L_1 ,
V_23 , V_4 , V_3 -> type ) ;
else
F_5 ( L_2 ,
V_23 , V_4 ) ;
goto V_19;
} else
goto V_24;
}
V_18 = - V_25 ;
if ( V_3 -> type == V_26 && ! V_5 &&
! F_6 ( V_1 -> V_27 , V_28 ) )
goto V_24;
V_3 -> V_29 = V_12 -> V_29 ;
V_14 = V_12 -> V_30 ;
V_16 = V_12 -> V_31 ;
V_15 = V_12 -> V_32 ;
F_4 () ;
F_7 ( V_14 -> V_33 == NULL ) ;
V_18 = - V_34 ;
V_10 = F_8 ( V_1 , V_23 , V_35 , V_14 ) ;
if ( V_10 == NULL )
goto V_36;
F_9 ( V_3 , V_10 ) ;
V_18 = 0 ;
V_10 -> V_37 = V_16 ;
if ( V_38 & V_15 )
V_10 -> V_39 = V_40 ;
V_7 = F_10 ( V_10 ) ;
V_7 -> V_41 = ( V_42 & V_15 ) != 0 ;
if ( V_26 == V_3 -> type ) {
V_7 -> V_43 = V_4 ;
if ( V_44 == V_4 )
V_7 -> V_45 = 1 ;
}
V_10 -> V_46 = V_47 ;
V_10 -> V_48 = V_23 ;
V_10 -> V_49 = V_4 ;
V_10 -> V_50 = V_12 -> V_30 -> V_51 ;
F_10 ( V_10 ) -> V_52 = V_9 = F_11 ( V_10 ) ;
V_9 -> V_53 = - 1 ;
V_9 -> V_54 = V_55 ;
V_9 -> V_56 = 1 ;
V_9 -> V_57 = V_58 ;
V_9 -> V_59 = V_1 -> V_60 . V_61 . V_62 ;
V_7 -> V_63 = - 1 ;
V_7 -> V_56 = 1 ;
V_7 -> V_64 = 1 ;
V_7 -> V_65 = 0 ;
V_7 -> V_66 = NULL ;
V_7 -> V_67 = 0 ;
if ( V_1 -> V_68 . V_69 )
V_7 -> V_57 = V_70 ;
else
V_7 -> V_57 = V_71 ;
F_12 ( V_10 ) ;
if ( V_7 -> V_43 ) {
V_7 -> V_72 = F_13 ( V_7 -> V_43 ) ;
V_10 -> V_73 -> V_74 ( V_10 ) ;
}
if ( V_10 -> V_73 -> V_75 ) {
V_18 = V_10 -> V_73 -> V_75 ( V_10 ) ;
if ( V_18 ) {
F_14 ( V_10 ) ;
goto V_36;
}
}
V_36:
return V_18 ;
V_24:
F_4 () ;
goto V_36;
}
int F_15 ( struct V_2 * V_3 , struct V_76 * V_77 , int V_78 )
{
struct V_79 * V_80 = (struct V_79 * ) V_77 ;
struct V_3 * V_10 = V_3 -> V_10 ;
struct V_6 * V_7 = F_10 ( V_10 ) ;
struct V_8 * V_9 = F_16 ( V_10 ) ;
struct V_1 * V_1 = F_17 ( V_10 ) ;
T_1 V_81 = 0 ;
unsigned short V_82 ;
int V_83 = 0 ;
int V_18 = 0 ;
if ( V_10 -> V_73 -> V_84 )
return V_10 -> V_73 -> V_84 ( V_10 , V_77 , V_78 ) ;
if ( V_78 < V_85 )
return - V_86 ;
if ( V_80 -> V_87 != V_88 )
return - V_89 ;
V_83 = F_18 ( & V_80 -> V_90 ) ;
if ( ( V_83 & V_91 ) && V_3 -> type == V_92 )
return - V_86 ;
V_82 = F_19 ( V_80 -> V_93 ) ;
if ( V_82 && V_82 < V_94 && ! F_6 ( V_1 -> V_27 , V_95 ) )
return - V_96 ;
F_20 ( V_10 ) ;
if ( V_10 -> V_97 != V_98 || V_7 -> V_43 ) {
V_18 = - V_86 ;
goto V_36;
}
if ( V_83 == V_99 ) {
int V_100 ;
if ( V_9 -> V_59 ) {
V_18 = - V_86 ;
goto V_36;
}
V_81 = V_80 -> V_90 . V_101 [ 3 ] ;
V_100 = F_21 ( V_1 , V_81 ) ;
if ( ! V_102 &&
! ( V_7 -> V_103 || V_7 -> V_104 ) &&
V_81 != F_22 ( V_105 ) &&
V_100 != V_106 &&
V_100 != V_107 &&
V_100 != V_108 ) {
V_18 = - V_109 ;
goto V_36;
}
} else {
if ( V_83 != V_110 ) {
struct V_111 * V_112 = NULL ;
F_2 () ;
if ( F_23 ( V_83 ) ) {
if ( V_78 >= sizeof( struct V_79 ) &&
V_80 -> V_113 ) {
V_10 -> V_114 = V_80 -> V_113 ;
}
if ( ! V_10 -> V_114 ) {
V_18 = - V_86 ;
goto V_115;
}
V_112 = F_24 ( V_1 , V_10 -> V_114 ) ;
if ( ! V_112 ) {
V_18 = - V_116 ;
goto V_115;
}
}
V_81 = V_117 ;
if ( ! ( V_83 & V_91 ) ) {
if ( ! ( V_7 -> V_103 || V_7 -> V_104 ) &&
! F_25 ( V_1 , & V_80 -> V_90 ,
V_112 , 0 ) ) {
V_18 = - V_109 ;
goto V_115;
}
}
F_4 () ;
}
}
V_7 -> V_118 = V_81 ;
V_7 -> V_119 = V_81 ;
V_10 -> V_120 = V_80 -> V_90 ;
if ( ! ( V_83 & V_91 ) )
V_9 -> V_121 = V_80 -> V_90 ;
if ( V_10 -> V_73 -> V_122 ( V_10 , V_82 ) ) {
F_26 ( V_10 ) ;
V_18 = - V_123 ;
goto V_36;
}
if ( V_83 != V_110 ) {
V_10 -> V_124 |= V_125 ;
if ( V_83 != V_99 )
V_9 -> V_59 = 1 ;
}
if ( V_82 )
V_10 -> V_124 |= V_126 ;
V_7 -> V_72 = F_13 ( V_7 -> V_43 ) ;
V_7 -> V_127 = 0 ;
V_7 -> V_128 = 0 ;
V_36:
F_27 ( V_10 ) ;
return V_18 ;
V_115:
F_4 () ;
goto V_36;
}
int F_28 ( struct V_2 * V_3 )
{
struct V_3 * V_10 = V_3 -> V_10 ;
if ( V_10 == NULL )
return - V_86 ;
F_29 ( V_10 ) ;
F_30 ( V_10 ) ;
return F_31 ( V_3 ) ;
}
void F_32 ( struct V_3 * V_10 )
{
struct V_8 * V_9 = F_16 ( V_10 ) ;
struct V_129 * V_130 ;
struct V_131 * V_132 ;
V_130 = F_33 ( & V_9 -> V_133 , NULL ) ;
if ( V_130 != NULL )
F_34 ( V_130 ) ;
V_130 = F_33 ( & V_9 -> V_134 , NULL ) ;
if ( V_130 != NULL )
F_34 ( V_130 ) ;
F_35 ( V_10 ) ;
V_132 = F_33 ( & V_9 -> V_132 , NULL ) ;
if ( V_132 != NULL )
F_36 ( V_10 , V_132 , V_132 -> V_135 ) ;
}
int F_37 ( struct V_2 * V_3 , struct V_76 * V_77 ,
int * V_136 , int V_137 )
{
struct V_79 * sin = (struct V_79 * ) V_77 ;
struct V_3 * V_10 = V_3 -> V_10 ;
struct V_6 * V_7 = F_10 ( V_10 ) ;
struct V_8 * V_9 = F_16 ( V_10 ) ;
sin -> V_87 = V_88 ;
sin -> V_138 = 0 ;
sin -> V_113 = 0 ;
if ( V_137 ) {
if ( ! V_7 -> V_127 )
return - V_139 ;
if ( ( ( 1 << V_10 -> V_97 ) & ( V_140 | V_141 ) ) &&
V_137 == 1 )
return - V_139 ;
sin -> V_93 = V_7 -> V_127 ;
sin -> V_90 = V_10 -> V_142 ;
if ( V_9 -> V_143 )
sin -> V_138 = V_9 -> V_144 ;
} else {
if ( F_38 ( & V_10 -> V_120 ) )
sin -> V_90 = V_9 -> V_121 ;
else
sin -> V_90 = V_10 -> V_120 ;
sin -> V_93 = V_7 -> V_72 ;
}
sin -> V_113 = F_39 ( & sin -> V_90 ,
V_10 -> V_114 ) ;
* V_136 = sizeof( * sin ) ;
return 0 ;
}
int F_40 ( struct V_2 * V_3 , unsigned int V_145 , unsigned long V_146 )
{
struct V_3 * V_10 = V_3 -> V_10 ;
struct V_1 * V_1 = F_17 ( V_10 ) ;
switch ( V_145 ) {
case V_147 :
return F_41 ( V_10 , (struct V_148 V_149 * ) V_146 ) ;
case V_150 :
return F_42 ( V_10 , (struct V_151 V_149 * ) V_146 ) ;
case V_152 :
case V_153 :
return F_43 ( V_1 , V_145 , ( void V_149 * ) V_146 ) ;
case V_154 :
return F_44 ( V_1 , ( void V_149 * ) V_146 ) ;
case V_155 :
return F_45 ( V_1 , ( void V_149 * ) V_146 ) ;
case V_156 :
return F_46 ( V_1 , ( void V_149 * ) V_146 ) ;
default:
if ( ! V_10 -> V_73 -> V_157 )
return - V_158 ;
return V_10 -> V_73 -> V_157 ( V_10 , V_145 , V_146 ) ;
}
return 0 ;
}
int F_47 ( struct V_11 * V_159 )
{
struct V_160 * V_161 ;
struct V_11 * V_12 ;
struct V_160 * V_162 ;
int V_4 = V_159 -> V_4 ;
int V_163 ;
F_48 ( & V_164 ) ;
V_163 = - V_86 ;
if ( V_159 -> type >= V_165 )
goto V_166;
V_12 = NULL ;
V_163 = - V_25 ;
V_162 = & V_167 [ V_159 -> type ] ;
F_49 (lh, &inetsw6[p->type]) {
V_12 = F_50 ( V_161 , struct V_11 , V_168 ) ;
if ( V_169 & V_12 -> V_32 ) {
if ( V_4 == V_12 -> V_4 )
break;
V_162 = V_161 ;
}
V_12 = NULL ;
}
if ( V_12 )
goto V_170;
F_51 ( & V_159 -> V_168 , V_162 ) ;
V_163 = 0 ;
V_36:
F_52 ( & V_164 ) ;
return V_163 ;
V_170:
F_53 ( L_3 , V_4 ) ;
goto V_36;
V_166:
F_53 ( L_4 ,
V_159 -> type ) ;
goto V_36;
}
void
F_54 ( struct V_11 * V_159 )
{
if ( V_169 & V_159 -> V_32 ) {
F_53 ( L_5 ,
V_159 -> V_4 ) ;
} else {
F_48 ( & V_164 ) ;
F_55 ( & V_159 -> V_168 ) ;
F_52 ( & V_164 ) ;
F_56 () ;
}
}
int F_57 ( struct V_3 * V_10 )
{
struct V_8 * V_9 = F_16 ( V_10 ) ;
struct V_171 * V_172 ;
V_172 = F_58 ( V_10 , V_9 -> V_173 ) ;
if ( V_172 == NULL ) {
struct V_6 * V_7 = F_10 ( V_10 ) ;
struct V_174 * V_175 , V_176 ;
struct V_177 V_178 ;
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
V_178 . V_179 = V_10 -> V_49 ;
V_178 . V_180 = V_10 -> V_142 ;
V_178 . V_121 = V_9 -> V_121 ;
V_178 . V_181 = V_9 -> V_144 ;
V_178 . V_182 = V_10 -> V_114 ;
V_178 . V_183 = V_10 -> V_184 ;
V_178 . V_185 = V_7 -> V_127 ;
V_178 . V_186 = V_7 -> V_72 ;
F_59 ( V_10 , F_60 ( & V_178 ) ) ;
V_175 = F_61 ( & V_178 , V_9 -> V_132 , & V_176 ) ;
V_172 = F_62 ( V_10 , & V_178 , V_175 ) ;
if ( F_63 ( V_172 ) ) {
V_10 -> V_187 = 0 ;
V_10 -> V_188 = - F_64 ( V_172 ) ;
return F_64 ( V_172 ) ;
}
F_65 ( V_10 , V_172 , NULL , NULL ) ;
}
return 0 ;
}
bool F_66 ( const struct V_3 * V_10 , const struct V_129 * V_130 )
{
const struct V_8 * V_9 = F_16 ( V_10 ) ;
const struct V_189 * V_132 = F_67 ( V_130 ) ;
if ( V_9 -> V_190 . V_191 ) {
if ( ( V_132 -> V_192 && ( V_9 -> V_190 . V_193 . V_194 ||
V_9 -> V_190 . V_193 . V_195 ) ) ||
( F_68 ( (struct V_196 * ) F_69 ( V_130 ) ) &&
V_9 -> V_190 . V_193 . V_197 ) ||
( V_132 -> V_198 && ( V_9 -> V_190 . V_193 . V_198 ||
V_9 -> V_190 . V_193 . V_199 ) ) ||
( ( V_132 -> V_200 || V_132 -> V_201 ) &&
( V_9 -> V_190 . V_193 . V_202 || V_9 -> V_190 . V_193 . V_203 ) ) )
return true ;
}
return false ;
}
static int T_2 F_70 ( void )
{
F_71 ( & V_204 ) ;
return 0 ;
}
static void F_72 ( void )
{
F_73 ( & V_204 ) ;
}
static int T_3 F_74 ( struct V_1 * V_1 )
{
int V_205 ;
if ( F_75 ( ( void V_206 * * ) V_1 -> V_207 . V_208 ,
sizeof( struct V_209 ) ,
F_76 ( struct V_209 ) ) < 0 )
return - V_210 ;
if ( F_75 ( ( void V_206 * * ) V_1 -> V_207 . V_211 ,
sizeof( struct V_209 ) ,
F_76 ( struct V_209 ) ) < 0 )
goto V_212;
if ( F_75 ( ( void V_206 * * ) V_1 -> V_207 . V_213 ,
sizeof( struct V_214 ) ,
F_76 ( struct V_214 ) ) < 0 )
goto V_215;
F_77 (i) {
struct V_214 * V_216 ;
V_216 = F_78 ( V_1 -> V_207 . V_213 [ 0 ] , V_205 ) ;
F_79 ( & V_216 -> V_217 ) ;
#if V_218 == 2
V_216 = F_78 ( V_1 -> V_207 . V_213 [ 1 ] , V_205 ) ;
F_79 ( & V_216 -> V_217 ) ;
#endif
}
if ( F_75 ( ( void V_206 * * ) V_1 -> V_207 . V_219 ,
sizeof( struct V_220 ) ,
F_76 ( struct V_220 ) ) < 0 )
goto V_221;
V_1 -> V_207 . V_222 = F_80 ( sizeof( struct V_223 ) ,
V_35 ) ;
if ( ! V_1 -> V_207 . V_222 )
goto V_224;
return 0 ;
V_224:
F_81 ( ( void V_206 * * ) V_1 -> V_207 . V_219 ) ;
V_221:
F_81 ( ( void V_206 * * ) V_1 -> V_207 . V_213 ) ;
V_215:
F_81 ( ( void V_206 * * ) V_1 -> V_207 . V_211 ) ;
V_212:
F_81 ( ( void V_206 * * ) V_1 -> V_207 . V_208 ) ;
return - V_210 ;
}
static void F_82 ( struct V_1 * V_1 )
{
F_81 ( ( void V_206 * * ) V_1 -> V_207 . V_208 ) ;
F_81 ( ( void V_206 * * ) V_1 -> V_207 . V_211 ) ;
F_81 ( ( void V_206 * * ) V_1 -> V_207 . V_213 ) ;
F_81 ( ( void V_206 * * ) V_1 -> V_207 . V_219 ) ;
F_83 ( V_1 -> V_207 . V_222 ) ;
}
static int T_3 F_84 ( struct V_1 * V_1 )
{
int V_18 = 0 ;
V_1 -> V_60 . V_61 . V_62 = 0 ;
V_1 -> V_60 . V_61 . V_225 = 1 * V_226 ;
V_1 -> V_60 . V_61 . V_227 = 1 ;
F_85 ( & V_1 -> V_60 . V_228 , 0 ) ;
V_18 = F_74 ( V_1 ) ;
if ( V_18 )
return V_18 ;
#ifdef F_86
V_18 = F_87 ( V_1 ) ;
if ( V_18 )
goto V_36;
V_18 = F_88 ( V_1 ) ;
if ( V_18 )
goto V_229;
V_18 = F_89 ( V_1 ) ;
if ( V_18 )
goto V_230;
#endif
return V_18 ;
#ifdef F_86
V_230:
F_90 ( V_1 ) ;
V_229:
F_91 ( V_1 ) ;
V_36:
F_82 ( V_1 ) ;
return V_18 ;
#endif
}
static void T_4 F_92 ( struct V_1 * V_1 )
{
#ifdef F_86
F_91 ( V_1 ) ;
F_90 ( V_1 ) ;
F_93 ( V_1 ) ;
#endif
F_82 ( V_1 ) ;
}
static int T_2 F_94 ( void )
{
struct V_160 * V_231 ;
int V_18 = 0 ;
F_95 ( sizeof( struct V_189 ) > F_96 ( struct V_129 , V_232 ) ) ;
for ( V_231 = & V_167 [ 0 ] ; V_231 < & V_167 [ V_165 ] ; ++ V_231 )
F_97 ( V_231 ) ;
if ( V_233 ) {
F_98 ( L_6 ) ;
goto V_36;
}
V_18 = F_99 ( & V_234 , 1 ) ;
if ( V_18 )
goto V_36;
V_18 = F_99 ( & V_235 , 1 ) ;
if ( V_18 )
goto V_236;
V_18 = F_99 ( & V_237 , 1 ) ;
if ( V_18 )
goto V_238;
V_18 = F_99 ( & V_239 , 1 ) ;
if ( V_18 )
goto V_240;
V_18 = F_99 ( & V_241 , 1 ) ;
if ( V_18 )
goto V_242;
V_18 = F_100 () ;
if ( V_18 )
goto V_243;
V_18 = F_101 ( & V_244 ) ;
if ( V_18 )
goto V_245;
V_18 = F_102 ( & V_246 ) ;
if ( V_18 )
goto V_247;
V_18 = F_103 () ;
if ( V_18 )
goto V_248;
V_18 = F_104 () ;
if ( V_18 )
goto V_249;
V_18 = F_105 () ;
if ( V_18 )
goto V_250;
V_18 = F_106 () ;
if ( V_18 )
goto V_251;
V_252 = & V_253 ;
V_18 = F_107 () ;
if ( V_18 )
goto V_254;
#ifdef F_86
V_18 = - V_210 ;
if ( F_108 () )
goto V_255;
if ( F_109 () )
goto V_256;
if ( F_110 () )
goto V_257;
if ( F_111 () )
goto V_258;
#endif
V_18 = F_112 () ;
if ( V_18 )
goto V_259;
V_18 = F_113 () ;
if ( V_18 )
goto V_260;
V_18 = F_114 () ;
if ( V_18 )
goto V_261;
V_18 = F_115 () ;
if ( V_18 )
goto V_262;
V_18 = F_116 () ;
if ( V_18 )
goto V_263;
V_18 = F_117 () ;
if ( V_18 )
goto V_264;
V_18 = F_118 () ;
if ( V_18 )
goto V_265;
V_18 = F_119 () ;
if ( V_18 )
goto V_266;
V_18 = F_120 () ;
if ( V_18 )
goto V_267;
V_18 = F_70 () ;
if ( V_18 )
goto V_268;
V_18 = F_121 () ;
if ( V_18 )
goto V_269;
#ifdef F_122
V_18 = F_123 () ;
if ( V_18 )
goto V_270;
#endif
V_36:
return V_18 ;
#ifdef F_122
V_270:
F_124 () ;
#endif
V_269:
F_72 () ;
V_268:
F_125 () ;
V_267:
F_126 () ;
V_266:
F_127 () ;
V_265:
F_128 () ;
V_264:
F_129 () ;
V_263:
F_130 () ;
V_262:
F_131 () ;
V_261:
F_132 () ;
V_260:
F_133 () ;
V_259:
#ifdef F_86
F_134 () ;
V_258:
F_135 () ;
V_257:
F_136 () ;
V_256:
F_137 () ;
V_255:
#endif
F_138 () ;
V_254:
F_139 () ;
V_251:
F_140 () ;
V_250:
F_141 () ;
V_249:
F_142 () ;
V_248:
F_143 ( & V_246 ) ;
V_247:
F_144 ( V_23 ) ;
F_145 ( V_23 ) ;
V_245:
F_146 () ;
V_242:
F_147 ( & V_241 ) ;
V_243:
F_147 ( & V_239 ) ;
V_240:
F_147 ( & V_237 ) ;
V_238:
F_147 ( & V_235 ) ;
V_236:
F_147 ( & V_234 ) ;
goto V_36;
}
