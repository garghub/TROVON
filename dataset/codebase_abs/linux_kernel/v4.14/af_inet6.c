bool F_1 ( void )
{
return V_1 == 0 ;
}
static int F_2 ( struct V_2 * V_2 , struct V_3 * V_4 , int V_5 ,
int V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_4 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
unsigned char V_16 ;
int V_17 = 0 ;
int V_18 ;
if ( V_5 < 0 || V_5 >= V_19 )
return - V_20 ;
V_21:
V_18 = - V_22 ;
F_3 () ;
F_4 (answer, &inetsw6[sock->type], list) {
V_18 = 0 ;
if ( V_5 == V_13 -> V_5 ) {
if ( V_5 != V_23 )
break;
} else {
if ( V_23 == V_5 ) {
V_5 = V_13 -> V_5 ;
break;
}
if ( V_23 == V_13 -> V_5 )
break;
}
V_18 = - V_24 ;
}
if ( V_18 ) {
if ( V_17 < 2 ) {
F_5 () ;
if ( ++ V_17 == 1 )
F_6 ( L_1 ,
V_25 , V_5 , V_4 -> type ) ;
else
F_6 ( L_2 ,
V_25 , V_5 ) ;
goto V_21;
} else
goto V_26;
}
V_18 = - V_27 ;
if ( V_4 -> type == V_28 && ! V_6 &&
! F_7 ( V_2 -> V_29 , V_30 ) )
goto V_26;
V_4 -> V_31 = V_13 -> V_31 ;
V_15 = V_13 -> V_32 ;
V_16 = V_13 -> V_33 ;
F_5 () ;
F_8 ( ! V_15 -> V_34 ) ;
V_18 = - V_35 ;
V_11 = F_9 ( V_2 , V_25 , V_36 , V_15 , V_6 ) ;
if ( ! V_11 )
goto V_37;
F_10 ( V_4 , V_11 ) ;
V_18 = 0 ;
if ( V_38 & V_16 )
V_11 -> V_39 = V_40 ;
V_8 = F_11 ( V_11 ) ;
V_8 -> V_41 = ( V_42 & V_16 ) != 0 ;
if ( V_28 == V_4 -> type ) {
V_8 -> V_43 = V_5 ;
if ( V_44 == V_5 )
V_8 -> V_45 = 1 ;
}
V_11 -> V_46 = V_47 ;
V_11 -> V_48 = V_25 ;
V_11 -> V_49 = V_5 ;
V_11 -> V_50 = V_13 -> V_32 -> V_51 ;
F_11 ( V_11 ) -> V_52 = V_10 = F_12 ( V_11 ) ;
V_10 -> V_53 = - 1 ;
V_10 -> V_54 = V_55 ;
V_10 -> V_56 = 1 ;
V_10 -> V_57 = V_58 ;
V_10 -> V_59 = F_13 ( V_2 ) ;
V_10 -> V_60 = V_2 -> V_61 . V_62 . V_63 ;
V_11 -> V_64 = V_2 -> V_61 . V_62 . V_65 ;
V_8 -> V_66 = - 1 ;
V_8 -> V_56 = 1 ;
V_8 -> V_67 = 1 ;
V_8 -> V_68 = 0 ;
V_8 -> V_69 = NULL ;
V_8 -> V_70 = 0 ;
if ( V_2 -> V_71 . V_72 )
V_8 -> V_57 = V_73 ;
else
V_8 -> V_57 = V_74 ;
F_14 ( V_11 ) ;
if ( V_8 -> V_43 ) {
V_8 -> V_75 = F_15 ( V_8 -> V_43 ) ;
V_18 = V_11 -> V_76 -> V_77 ( V_11 ) ;
if ( V_18 ) {
F_16 ( V_11 ) ;
goto V_37;
}
}
if ( V_11 -> V_76 -> V_78 ) {
V_18 = V_11 -> V_76 -> V_78 ( V_11 ) ;
if ( V_18 ) {
F_16 ( V_11 ) ;
goto V_37;
}
}
if ( ! V_6 ) {
V_18 = F_17 ( V_11 ) ;
if ( V_18 ) {
F_16 ( V_11 ) ;
goto V_37;
}
}
V_37:
return V_18 ;
V_26:
F_5 () ;
goto V_37;
}
int F_18 ( struct V_3 * V_4 , struct V_79 * V_80 , int V_81 )
{
struct V_82 * V_83 = (struct V_82 * ) V_80 ;
struct V_4 * V_11 = V_4 -> V_11 ;
struct V_7 * V_8 = F_11 ( V_11 ) ;
struct V_9 * V_10 = F_19 ( V_11 ) ;
struct V_2 * V_2 = F_20 ( V_11 ) ;
T_1 V_84 = 0 ;
unsigned short V_85 ;
int V_86 = 0 ;
int V_18 = 0 ;
if ( V_11 -> V_76 -> V_87 )
return V_11 -> V_76 -> V_87 ( V_11 , V_80 , V_81 ) ;
if ( V_81 < V_88 )
return - V_20 ;
if ( V_83 -> V_89 != V_90 )
return - V_91 ;
V_86 = F_21 ( & V_83 -> V_92 ) ;
if ( ( V_86 & V_93 ) && V_4 -> type == V_94 )
return - V_20 ;
V_85 = F_22 ( V_83 -> V_95 ) ;
if ( V_85 && V_85 < F_23 ( V_2 ) &&
! F_7 ( V_2 -> V_29 , V_96 ) )
return - V_97 ;
F_24 ( V_11 ) ;
if ( V_11 -> V_98 != V_99 || V_8 -> V_43 ) {
V_18 = - V_20 ;
goto V_37;
}
if ( V_86 == V_100 ) {
int V_101 ;
if ( V_11 -> V_64 ) {
V_18 = - V_20 ;
goto V_37;
}
V_84 = V_83 -> V_92 . V_102 [ 3 ] ;
V_101 = F_25 ( V_2 , V_84 ) ;
if ( ! V_2 -> V_71 . V_103 &&
! ( V_8 -> V_104 || V_8 -> V_105 ) &&
V_84 != F_26 ( V_106 ) &&
V_101 != V_107 &&
V_101 != V_108 &&
V_101 != V_109 ) {
V_18 = - V_110 ;
goto V_37;
}
} else {
if ( V_86 != V_111 ) {
struct V_112 * V_113 = NULL ;
F_3 () ;
if ( F_27 ( V_86 ) ) {
if ( V_81 >= sizeof( struct V_82 ) &&
V_83 -> V_114 ) {
V_11 -> V_115 = V_83 -> V_114 ;
}
if ( ! V_11 -> V_115 ) {
V_18 = - V_20 ;
goto V_116;
}
V_113 = F_28 ( V_2 , V_11 -> V_115 ) ;
if ( ! V_113 ) {
V_18 = - V_117 ;
goto V_116;
}
}
V_84 = V_118 ;
if ( ! ( V_86 & V_93 ) ) {
if ( ! V_2 -> V_61 . V_62 . V_119 &&
! ( V_8 -> V_104 || V_8 -> V_105 ) &&
! F_29 ( V_2 , & V_83 -> V_92 ,
V_113 , 0 ) ) {
V_18 = - V_110 ;
goto V_116;
}
}
F_5 () ;
}
}
V_8 -> V_120 = V_84 ;
V_8 -> V_121 = V_84 ;
V_11 -> V_122 = V_83 -> V_92 ;
if ( ! ( V_86 & V_93 ) )
V_10 -> V_123 = V_83 -> V_92 ;
if ( ( V_85 || ! V_8 -> V_124 ) &&
V_11 -> V_76 -> V_125 ( V_11 , V_85 ) ) {
F_30 ( V_11 ) ;
V_18 = - V_126 ;
goto V_37;
}
if ( V_86 != V_111 ) {
V_11 -> V_127 |= V_128 ;
if ( V_86 != V_100 )
V_11 -> V_64 = 1 ;
}
if ( V_85 )
V_11 -> V_127 |= V_129 ;
V_8 -> V_75 = F_15 ( V_8 -> V_43 ) ;
V_8 -> V_130 = 0 ;
V_8 -> V_131 = 0 ;
V_37:
F_31 ( V_11 ) ;
return V_18 ;
V_116:
F_5 () ;
goto V_37;
}
int F_32 ( struct V_3 * V_4 )
{
struct V_4 * V_11 = V_4 -> V_11 ;
if ( ! V_11 )
return - V_20 ;
F_33 ( V_11 ) ;
F_34 ( V_11 ) ;
return F_35 ( V_4 ) ;
}
void F_36 ( struct V_4 * V_11 )
{
struct V_9 * V_10 = F_19 ( V_11 ) ;
struct V_132 * V_133 ;
struct V_134 * V_135 ;
V_133 = F_37 ( & V_10 -> V_136 , NULL ) ;
if ( V_133 )
F_38 ( V_133 ) ;
V_133 = F_37 ( & V_10 -> V_137 , NULL ) ;
if ( V_133 )
F_38 ( V_133 ) ;
F_39 ( V_11 ) ;
V_135 = F_37 ( ( V_138 struct V_134 * * ) & V_10 -> V_135 , NULL ) ;
if ( V_135 ) {
F_40 ( V_135 -> V_139 , & V_11 -> V_140 ) ;
F_41 ( V_135 ) ;
}
}
int F_42 ( struct V_3 * V_4 , struct V_79 * V_80 ,
int * V_141 , int V_142 )
{
struct V_82 * sin = (struct V_82 * ) V_80 ;
struct V_4 * V_11 = V_4 -> V_11 ;
struct V_7 * V_8 = F_11 ( V_11 ) ;
struct V_9 * V_10 = F_19 ( V_11 ) ;
sin -> V_89 = V_90 ;
sin -> V_143 = 0 ;
sin -> V_114 = 0 ;
if ( V_142 ) {
if ( ! V_8 -> V_130 )
return - V_144 ;
if ( ( ( 1 << V_11 -> V_98 ) & ( V_145 | V_146 ) ) &&
V_142 == 1 )
return - V_144 ;
sin -> V_95 = V_8 -> V_130 ;
sin -> V_92 = V_11 -> V_147 ;
if ( V_10 -> V_148 )
sin -> V_143 = V_10 -> V_149 ;
} else {
if ( F_43 ( & V_11 -> V_122 ) )
sin -> V_92 = V_10 -> V_123 ;
else
sin -> V_92 = V_11 -> V_122 ;
sin -> V_95 = V_8 -> V_75 ;
}
sin -> V_114 = F_44 ( & sin -> V_92 ,
V_11 -> V_115 ) ;
* V_141 = sizeof( * sin ) ;
return 0 ;
}
int F_45 ( struct V_3 * V_4 , unsigned int V_150 , unsigned long V_151 )
{
struct V_4 * V_11 = V_4 -> V_11 ;
struct V_2 * V_2 = F_20 ( V_11 ) ;
switch ( V_150 ) {
case V_152 :
return F_46 ( V_11 , (struct V_153 V_154 * ) V_151 ) ;
case V_155 :
return F_47 ( V_11 , (struct V_156 V_154 * ) V_151 ) ;
case V_157 :
case V_158 :
return F_48 ( V_2 , V_150 , ( void V_154 * ) V_151 ) ;
case V_159 :
return F_49 ( V_2 , ( void V_154 * ) V_151 ) ;
case V_160 :
return F_50 ( V_2 , ( void V_154 * ) V_151 ) ;
case V_161 :
return F_51 ( V_2 , ( void V_154 * ) V_151 ) ;
default:
if ( ! V_11 -> V_76 -> V_162 )
return - V_163 ;
return V_11 -> V_76 -> V_162 ( V_11 , V_150 , V_151 ) ;
}
return 0 ;
}
int F_52 ( struct V_12 * V_164 )
{
struct V_165 * V_166 ;
struct V_12 * V_13 ;
struct V_165 * V_167 ;
int V_5 = V_164 -> V_5 ;
int V_168 ;
F_53 ( & V_169 ) ;
V_168 = - V_20 ;
if ( V_164 -> type >= V_170 )
goto V_171;
V_13 = NULL ;
V_168 = - V_27 ;
V_167 = & V_172 [ V_164 -> type ] ;
F_54 (lh, &inetsw6[p->type]) {
V_13 = F_55 ( V_166 , struct V_12 , V_173 ) ;
if ( V_174 & V_13 -> V_33 ) {
if ( V_5 == V_13 -> V_5 )
break;
V_167 = V_166 ;
}
V_13 = NULL ;
}
if ( V_13 )
goto V_175;
F_56 ( & V_164 -> V_173 , V_167 ) ;
V_168 = 0 ;
V_37:
F_57 ( & V_169 ) ;
return V_168 ;
V_175:
F_58 ( L_3 , V_5 ) ;
goto V_37;
V_171:
F_58 ( L_4 ,
V_164 -> type ) ;
goto V_37;
}
void
F_59 ( struct V_12 * V_164 )
{
if ( V_174 & V_164 -> V_33 ) {
F_58 ( L_5 ,
V_164 -> V_5 ) ;
} else {
F_53 ( & V_169 ) ;
F_60 ( & V_164 -> V_173 ) ;
F_57 ( & V_169 ) ;
F_61 () ;
}
}
int F_62 ( struct V_4 * V_11 )
{
struct V_9 * V_10 = F_19 ( V_11 ) ;
struct V_176 * V_177 ;
V_177 = F_63 ( V_11 , V_10 -> V_178 ) ;
if ( ! V_177 ) {
struct V_7 * V_8 = F_11 ( V_11 ) ;
struct V_179 * V_180 , V_181 ;
struct V_182 V_183 ;
memset ( & V_183 , 0 , sizeof( V_183 ) ) ;
V_183 . V_184 = V_11 -> V_49 ;
V_183 . V_185 = V_11 -> V_147 ;
V_183 . V_123 = V_10 -> V_123 ;
V_183 . V_186 = V_10 -> V_149 ;
V_183 . V_187 = V_11 -> V_115 ;
V_183 . V_188 = V_11 -> V_189 ;
V_183 . V_190 = V_8 -> V_130 ;
V_183 . V_191 = V_8 -> V_75 ;
V_183 . V_192 = V_11 -> V_193 ;
F_64 ( V_11 , F_65 ( & V_183 ) ) ;
F_3 () ;
V_180 = F_66 ( & V_183 , F_67 ( V_10 -> V_135 ) ,
& V_181 ) ;
F_5 () ;
V_177 = F_68 ( V_11 , & V_183 , V_180 ) ;
if ( F_69 ( V_177 ) ) {
V_11 -> V_194 = 0 ;
V_11 -> V_195 = - F_70 ( V_177 ) ;
return F_70 ( V_177 ) ;
}
F_71 ( V_11 , V_177 , NULL , NULL ) ;
}
return 0 ;
}
bool F_72 ( const struct V_4 * V_11 , const struct V_132 * V_133 ,
const struct V_196 * V_135 )
{
const struct V_9 * V_10 = F_19 ( V_11 ) ;
if ( V_10 -> V_197 . V_198 ) {
if ( ( ( V_135 -> V_33 & V_199 ) &&
( V_10 -> V_197 . V_200 . V_201 || V_10 -> V_197 . V_200 . V_202 ) ) ||
( F_73 ( (struct V_203 * ) F_74 ( V_133 ) ) &&
V_10 -> V_197 . V_200 . V_204 ) ||
( V_135 -> V_205 && ( V_10 -> V_197 . V_200 . V_205 ||
V_10 -> V_197 . V_200 . V_206 ) ) ||
( ( V_135 -> V_207 || V_135 -> V_208 ) &&
( V_10 -> V_197 . V_200 . V_209 || V_10 -> V_197 . V_200 . V_210 ) ) )
return true ;
}
return false ;
}
static int T_2 F_75 ( void )
{
F_76 ( & V_211 ) ;
return 0 ;
}
static void F_77 ( void )
{
F_78 ( & V_211 ) ;
}
static int T_3 F_79 ( struct V_2 * V_2 )
{
int V_212 ;
V_2 -> V_213 . V_214 = F_80 ( struct V_215 ) ;
if ( ! V_2 -> V_213 . V_214 )
return - V_216 ;
V_2 -> V_213 . V_217 = F_80 ( struct V_215 ) ;
if ( ! V_2 -> V_213 . V_217 )
goto V_218;
V_2 -> V_213 . V_219 = F_80 ( struct V_220 ) ;
if ( ! V_2 -> V_213 . V_219 )
goto V_221;
F_81 (i) {
struct V_220 * V_222 ;
V_222 = F_82 ( V_2 -> V_213 . V_219 , V_212 ) ;
F_83 ( & V_222 -> V_223 ) ;
}
V_2 -> V_213 . V_224 = F_80 ( struct V_225 ) ;
if ( ! V_2 -> V_213 . V_224 )
goto V_226;
V_2 -> V_213 . V_227 = F_84 ( sizeof( struct V_228 ) ,
V_36 ) ;
if ( ! V_2 -> V_213 . V_227 )
goto V_229;
return 0 ;
V_229:
F_85 ( V_2 -> V_213 . V_224 ) ;
V_226:
F_85 ( V_2 -> V_213 . V_219 ) ;
V_221:
F_85 ( V_2 -> V_213 . V_217 ) ;
V_218:
F_85 ( V_2 -> V_213 . V_214 ) ;
return - V_216 ;
}
static void F_86 ( struct V_2 * V_2 )
{
F_85 ( V_2 -> V_213 . V_214 ) ;
F_85 ( V_2 -> V_213 . V_217 ) ;
F_85 ( V_2 -> V_213 . V_219 ) ;
F_85 ( V_2 -> V_213 . V_224 ) ;
F_87 ( V_2 -> V_213 . V_227 ) ;
}
static int T_3 F_88 ( struct V_2 * V_2 )
{
int V_18 = 0 ;
V_2 -> V_61 . V_62 . V_65 = 0 ;
V_2 -> V_61 . V_62 . V_230 = 1 * V_231 ;
V_2 -> V_61 . V_62 . V_232 = 1 ;
V_2 -> V_61 . V_62 . V_233 = V_234 ;
V_2 -> V_61 . V_62 . V_235 = 3 ;
V_2 -> V_61 . V_62 . V_236 = 1 * V_231 ;
V_2 -> V_61 . V_62 . V_237 = 0 ;
F_89 ( & V_2 -> V_61 . V_238 , 1 ) ;
V_18 = F_79 ( V_2 ) ;
if ( V_18 )
return V_18 ;
#ifdef F_90
V_18 = F_91 ( V_2 ) ;
if ( V_18 )
goto V_37;
V_18 = F_92 ( V_2 ) ;
if ( V_18 )
goto V_239;
V_18 = F_93 ( V_2 ) ;
if ( V_18 )
goto V_240;
#endif
return V_18 ;
#ifdef F_90
V_240:
F_94 ( V_2 ) ;
V_239:
F_95 ( V_2 ) ;
V_37:
F_86 ( V_2 ) ;
return V_18 ;
#endif
}
static void T_4 F_96 ( struct V_2 * V_2 )
{
#ifdef F_90
F_95 ( V_2 ) ;
F_94 ( V_2 ) ;
F_97 ( V_2 ) ;
#endif
F_86 ( V_2 ) ;
}
static int T_2 F_98 ( void )
{
struct V_165 * V_241 ;
int V_18 = 0 ;
F_99 ( sizeof( struct V_196 ) ) ;
for ( V_241 = & V_172 [ 0 ] ; V_241 < & V_172 [ V_170 ] ; ++ V_241 )
F_100 ( V_241 ) ;
if ( V_1 ) {
F_101 ( L_6 ) ;
goto V_37;
}
V_18 = F_102 ( & V_242 , 1 ) ;
if ( V_18 )
goto V_37;
V_18 = F_102 ( & V_243 , 1 ) ;
if ( V_18 )
goto V_244;
V_18 = F_102 ( & V_245 , 1 ) ;
if ( V_18 )
goto V_246;
V_18 = F_102 ( & V_247 , 1 ) ;
if ( V_18 )
goto V_248;
V_18 = F_102 ( & V_249 , 1 ) ;
if ( V_18 )
goto V_250;
V_18 = F_103 () ;
if ( V_18 )
goto V_251;
V_18 = F_104 ( & V_252 ) ;
if ( V_18 )
goto V_253;
V_18 = F_105 ( & V_254 ) ;
if ( V_18 )
goto V_255;
V_18 = F_106 () ;
if ( V_18 )
goto V_256;
V_18 = F_107 () ;
if ( V_18 )
goto V_257;
V_18 = F_108 () ;
if ( V_18 )
goto V_258;
V_18 = F_109 () ;
if ( V_18 )
goto V_259;
V_18 = F_110 () ;
if ( V_18 )
goto V_260;
#ifdef F_90
V_18 = - V_216 ;
if ( F_111 () )
goto V_261;
if ( F_112 () )
goto V_262;
if ( F_113 () )
goto V_263;
if ( F_114 () )
goto V_264;
#endif
V_18 = F_115 () ;
if ( V_18 )
goto V_265;
V_18 = F_116 () ;
if ( V_18 )
goto V_266;
V_18 = F_117 () ;
if ( V_18 )
goto V_267;
V_18 = F_118 () ;
if ( V_18 )
goto V_268;
V_18 = F_119 () ;
if ( V_18 )
goto V_269;
V_18 = F_120 () ;
if ( V_18 )
goto V_270;
V_18 = F_121 () ;
if ( V_18 )
goto V_271;
V_18 = F_122 () ;
if ( V_18 )
goto V_272;
V_18 = F_123 () ;
if ( V_18 )
goto V_273;
V_18 = F_124 () ;
if ( V_18 )
goto V_274;
V_18 = F_75 () ;
if ( V_18 )
goto V_275;
V_18 = F_125 () ;
if ( V_18 )
goto V_276;
V_18 = F_126 () ;
if ( V_18 )
goto V_277;
V_18 = F_127 () ;
if ( V_18 )
goto V_278;
V_18 = F_128 () ;
if ( V_18 )
goto V_279;
#ifdef F_129
V_18 = F_130 () ;
if ( V_18 )
goto V_280;
#endif
F_131 () ;
V_281 = & V_282 ;
V_37:
return V_18 ;
#ifdef F_129
V_280:
F_132 () ;
#endif
V_279:
F_133 () ;
V_278:
F_134 () ;
V_277:
F_135 () ;
V_276:
F_77 () ;
V_275:
F_136 () ;
V_274:
F_137 () ;
V_273:
F_138 () ;
V_272:
F_139 () ;
V_271:
F_140 () ;
V_270:
F_141 () ;
V_269:
F_142 () ;
V_268:
F_143 () ;
V_267:
F_144 () ;
V_266:
F_145 () ;
V_265:
#ifdef F_90
F_146 () ;
V_264:
F_147 () ;
V_263:
F_148 () ;
V_262:
F_149 () ;
V_261:
#endif
F_150 () ;
V_260:
F_151 () ;
V_259:
F_152 () ;
V_258:
F_153 () ;
V_257:
F_154 ( & V_254 ) ;
V_256:
F_155 () ;
V_255:
F_156 ( V_25 ) ;
F_157 ( V_25 ) ;
V_253:
F_158 () ;
V_250:
F_159 ( & V_249 ) ;
V_251:
F_159 ( & V_247 ) ;
V_248:
F_159 ( & V_245 ) ;
V_246:
F_159 ( & V_243 ) ;
V_244:
F_159 ( & V_242 ) ;
goto V_37;
}
