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
V_10 -> V_59 = F_13 ( F_14 ( V_11 ) ) ;
V_11 -> V_60 = V_2 -> V_61 . V_62 . V_63 ;
V_8 -> V_64 = - 1 ;
V_8 -> V_56 = 1 ;
V_8 -> V_65 = 1 ;
V_8 -> V_66 = 0 ;
V_8 -> V_67 = NULL ;
V_8 -> V_68 = 0 ;
if ( V_2 -> V_69 . V_70 )
V_8 -> V_57 = V_71 ;
else
V_8 -> V_57 = V_72 ;
F_15 ( V_11 ) ;
if ( V_8 -> V_43 ) {
V_8 -> V_73 = F_16 ( V_8 -> V_43 ) ;
V_18 = V_11 -> V_74 -> V_75 ( V_11 ) ;
if ( V_18 ) {
F_17 ( V_11 ) ;
goto V_37;
}
}
if ( V_11 -> V_74 -> V_76 ) {
V_18 = V_11 -> V_74 -> V_76 ( V_11 ) ;
if ( V_18 ) {
F_17 ( V_11 ) ;
goto V_37;
}
}
if ( ! V_6 ) {
V_18 = F_18 ( V_11 ) ;
if ( V_18 ) {
F_17 ( V_11 ) ;
goto V_37;
}
}
V_37:
return V_18 ;
V_26:
F_5 () ;
goto V_37;
}
int F_19 ( struct V_3 * V_4 , struct V_77 * V_78 , int V_79 )
{
struct V_80 * V_81 = (struct V_80 * ) V_78 ;
struct V_4 * V_11 = V_4 -> V_11 ;
struct V_7 * V_8 = F_11 ( V_11 ) ;
struct V_9 * V_10 = F_20 ( V_11 ) ;
struct V_2 * V_2 = F_14 ( V_11 ) ;
T_1 V_82 = 0 ;
unsigned short V_83 ;
int V_84 = 0 ;
int V_18 = 0 ;
if ( V_11 -> V_74 -> V_85 )
return V_11 -> V_74 -> V_85 ( V_11 , V_78 , V_79 ) ;
if ( V_79 < V_86 )
return - V_20 ;
if ( V_81 -> V_87 != V_88 )
return - V_89 ;
V_84 = F_21 ( & V_81 -> V_90 ) ;
if ( ( V_84 & V_91 ) && V_4 -> type == V_92 )
return - V_20 ;
V_83 = F_22 ( V_81 -> V_93 ) ;
if ( V_83 && V_83 < V_94 && ! F_7 ( V_2 -> V_29 , V_95 ) )
return - V_96 ;
F_23 ( V_11 ) ;
if ( V_11 -> V_97 != V_98 || V_8 -> V_43 ) {
V_18 = - V_20 ;
goto V_37;
}
if ( V_84 == V_99 ) {
int V_100 ;
if ( V_11 -> V_60 ) {
V_18 = - V_20 ;
goto V_37;
}
V_82 = V_81 -> V_90 . V_101 [ 3 ] ;
V_100 = F_24 ( V_2 , V_82 ) ;
if ( ! V_2 -> V_69 . V_102 &&
! ( V_8 -> V_103 || V_8 -> V_104 ) &&
V_82 != F_25 ( V_105 ) &&
V_100 != V_106 &&
V_100 != V_107 &&
V_100 != V_108 ) {
V_18 = - V_109 ;
goto V_37;
}
} else {
if ( V_84 != V_110 ) {
struct V_111 * V_112 = NULL ;
F_3 () ;
if ( F_26 ( V_84 ) ) {
if ( V_79 >= sizeof( struct V_80 ) &&
V_81 -> V_113 ) {
V_11 -> V_114 = V_81 -> V_113 ;
}
if ( ! V_11 -> V_114 ) {
V_18 = - V_20 ;
goto V_115;
}
V_112 = F_27 ( V_2 , V_11 -> V_114 ) ;
if ( ! V_112 ) {
V_18 = - V_116 ;
goto V_115;
}
}
V_82 = V_117 ;
if ( ! ( V_84 & V_91 ) ) {
if ( ! V_2 -> V_61 . V_62 . V_118 &&
! ( V_8 -> V_103 || V_8 -> V_104 ) &&
! F_28 ( V_2 , & V_81 -> V_90 ,
V_112 , 0 ) ) {
V_18 = - V_109 ;
goto V_115;
}
}
F_5 () ;
}
}
V_8 -> V_119 = V_82 ;
V_8 -> V_120 = V_82 ;
V_11 -> V_121 = V_81 -> V_90 ;
if ( ! ( V_84 & V_91 ) )
V_10 -> V_122 = V_81 -> V_90 ;
if ( ( V_83 || ! V_8 -> V_123 ) &&
V_11 -> V_74 -> V_124 ( V_11 , V_83 ) ) {
F_29 ( V_11 ) ;
V_18 = - V_125 ;
goto V_37;
}
if ( V_84 != V_110 ) {
V_11 -> V_126 |= V_127 ;
if ( V_84 != V_99 )
V_11 -> V_60 = 1 ;
}
if ( V_83 )
V_11 -> V_126 |= V_128 ;
V_8 -> V_73 = F_16 ( V_8 -> V_43 ) ;
V_8 -> V_129 = 0 ;
V_8 -> V_130 = 0 ;
V_37:
F_30 ( V_11 ) ;
return V_18 ;
V_115:
F_5 () ;
goto V_37;
}
int F_31 ( struct V_3 * V_4 )
{
struct V_4 * V_11 = V_4 -> V_11 ;
if ( ! V_11 )
return - V_20 ;
F_32 ( V_11 ) ;
F_33 ( V_11 ) ;
return F_34 ( V_4 ) ;
}
void F_35 ( struct V_4 * V_11 )
{
struct V_9 * V_10 = F_20 ( V_11 ) ;
struct V_131 * V_132 ;
struct V_133 * V_134 ;
V_132 = F_36 ( & V_10 -> V_135 , NULL ) ;
if ( V_132 )
F_37 ( V_132 ) ;
V_132 = F_36 ( & V_10 -> V_136 , NULL ) ;
if ( V_132 )
F_37 ( V_132 ) ;
F_38 ( V_11 ) ;
V_134 = F_36 ( ( V_137 struct V_133 * * ) & V_10 -> V_134 , NULL ) ;
if ( V_134 ) {
F_39 ( V_134 -> V_138 , & V_11 -> V_139 ) ;
F_40 ( V_134 ) ;
}
}
int F_41 ( struct V_3 * V_4 , struct V_77 * V_78 ,
int * V_140 , int V_141 )
{
struct V_80 * sin = (struct V_80 * ) V_78 ;
struct V_4 * V_11 = V_4 -> V_11 ;
struct V_7 * V_8 = F_11 ( V_11 ) ;
struct V_9 * V_10 = F_20 ( V_11 ) ;
sin -> V_87 = V_88 ;
sin -> V_142 = 0 ;
sin -> V_113 = 0 ;
if ( V_141 ) {
if ( ! V_8 -> V_129 )
return - V_143 ;
if ( ( ( 1 << V_11 -> V_97 ) & ( V_144 | V_145 ) ) &&
V_141 == 1 )
return - V_143 ;
sin -> V_93 = V_8 -> V_129 ;
sin -> V_90 = V_11 -> V_146 ;
if ( V_10 -> V_147 )
sin -> V_142 = V_10 -> V_148 ;
} else {
if ( F_42 ( & V_11 -> V_121 ) )
sin -> V_90 = V_10 -> V_122 ;
else
sin -> V_90 = V_11 -> V_121 ;
sin -> V_93 = V_8 -> V_73 ;
}
sin -> V_113 = F_43 ( & sin -> V_90 ,
V_11 -> V_114 ) ;
* V_140 = sizeof( * sin ) ;
return 0 ;
}
int F_44 ( struct V_3 * V_4 , unsigned int V_149 , unsigned long V_150 )
{
struct V_4 * V_11 = V_4 -> V_11 ;
struct V_2 * V_2 = F_14 ( V_11 ) ;
switch ( V_149 ) {
case V_151 :
return F_45 ( V_11 , (struct V_152 V_153 * ) V_150 ) ;
case V_154 :
return F_46 ( V_11 , (struct V_155 V_153 * ) V_150 ) ;
case V_156 :
case V_157 :
return F_47 ( V_2 , V_149 , ( void V_153 * ) V_150 ) ;
case V_158 :
return F_48 ( V_2 , ( void V_153 * ) V_150 ) ;
case V_159 :
return F_49 ( V_2 , ( void V_153 * ) V_150 ) ;
case V_160 :
return F_50 ( V_2 , ( void V_153 * ) V_150 ) ;
default:
if ( ! V_11 -> V_74 -> V_161 )
return - V_162 ;
return V_11 -> V_74 -> V_161 ( V_11 , V_149 , V_150 ) ;
}
return 0 ;
}
int F_51 ( struct V_12 * V_163 )
{
struct V_164 * V_165 ;
struct V_12 * V_13 ;
struct V_164 * V_166 ;
int V_5 = V_163 -> V_5 ;
int V_167 ;
F_52 ( & V_168 ) ;
V_167 = - V_20 ;
if ( V_163 -> type >= V_169 )
goto V_170;
V_13 = NULL ;
V_167 = - V_27 ;
V_166 = & V_171 [ V_163 -> type ] ;
F_53 (lh, &inetsw6[p->type]) {
V_13 = F_54 ( V_165 , struct V_12 , V_172 ) ;
if ( V_173 & V_13 -> V_33 ) {
if ( V_5 == V_13 -> V_5 )
break;
V_166 = V_165 ;
}
V_13 = NULL ;
}
if ( V_13 )
goto V_174;
F_55 ( & V_163 -> V_172 , V_166 ) ;
V_167 = 0 ;
V_37:
F_56 ( & V_168 ) ;
return V_167 ;
V_174:
F_57 ( L_3 , V_5 ) ;
goto V_37;
V_170:
F_57 ( L_4 ,
V_163 -> type ) ;
goto V_37;
}
void
F_58 ( struct V_12 * V_163 )
{
if ( V_173 & V_163 -> V_33 ) {
F_57 ( L_5 ,
V_163 -> V_5 ) ;
} else {
F_52 ( & V_168 ) ;
F_59 ( & V_163 -> V_172 ) ;
F_56 ( & V_168 ) ;
F_60 () ;
}
}
int F_61 ( struct V_4 * V_11 )
{
struct V_9 * V_10 = F_20 ( V_11 ) ;
struct V_175 * V_176 ;
V_176 = F_62 ( V_11 , V_10 -> V_177 ) ;
if ( ! V_176 ) {
struct V_7 * V_8 = F_11 ( V_11 ) ;
struct V_178 * V_179 , V_180 ;
struct V_181 V_182 ;
memset ( & V_182 , 0 , sizeof( V_182 ) ) ;
V_182 . V_183 = V_11 -> V_49 ;
V_182 . V_184 = V_11 -> V_146 ;
V_182 . V_122 = V_10 -> V_122 ;
V_182 . V_185 = V_10 -> V_148 ;
V_182 . V_186 = V_11 -> V_114 ;
V_182 . V_187 = V_11 -> V_188 ;
V_182 . V_189 = V_8 -> V_129 ;
V_182 . V_190 = V_8 -> V_73 ;
V_182 . V_191 = V_11 -> V_192 ;
F_63 ( V_11 , F_64 ( & V_182 ) ) ;
F_3 () ;
V_179 = F_65 ( & V_182 , F_66 ( V_10 -> V_134 ) ,
& V_180 ) ;
F_5 () ;
V_176 = F_67 ( V_11 , & V_182 , V_179 ) ;
if ( F_68 ( V_176 ) ) {
V_11 -> V_193 = 0 ;
V_11 -> V_194 = - F_69 ( V_176 ) ;
return F_69 ( V_176 ) ;
}
F_70 ( V_11 , V_176 , NULL , NULL ) ;
}
return 0 ;
}
bool F_71 ( const struct V_4 * V_11 , const struct V_131 * V_132 ,
const struct V_195 * V_134 )
{
const struct V_9 * V_10 = F_20 ( V_11 ) ;
if ( V_10 -> V_196 . V_197 ) {
if ( ( ( V_134 -> V_33 & V_198 ) &&
( V_10 -> V_196 . V_199 . V_200 || V_10 -> V_196 . V_199 . V_201 ) ) ||
( F_72 ( (struct V_202 * ) F_73 ( V_132 ) ) &&
V_10 -> V_196 . V_199 . V_203 ) ||
( V_134 -> V_204 && ( V_10 -> V_196 . V_199 . V_204 ||
V_10 -> V_196 . V_199 . V_205 ) ) ||
( ( V_134 -> V_206 || V_134 -> V_207 ) &&
( V_10 -> V_196 . V_199 . V_208 || V_10 -> V_196 . V_199 . V_209 ) ) )
return true ;
}
return false ;
}
static int T_2 F_74 ( void )
{
F_75 ( & V_210 ) ;
return 0 ;
}
static void F_76 ( void )
{
F_77 ( & V_210 ) ;
}
static int T_3 F_78 ( struct V_2 * V_2 )
{
int V_211 ;
V_2 -> V_212 . V_213 = F_79 ( struct V_214 ) ;
if ( ! V_2 -> V_212 . V_213 )
return - V_215 ;
V_2 -> V_212 . V_216 = F_79 ( struct V_214 ) ;
if ( ! V_2 -> V_212 . V_216 )
goto V_217;
V_2 -> V_212 . V_218 = F_79 ( struct V_219 ) ;
if ( ! V_2 -> V_212 . V_218 )
goto V_220;
F_80 (i) {
struct V_219 * V_221 ;
V_221 = F_81 ( V_2 -> V_212 . V_218 , V_211 ) ;
F_82 ( & V_221 -> V_222 ) ;
}
V_2 -> V_212 . V_223 = F_79 ( struct V_224 ) ;
if ( ! V_2 -> V_212 . V_223 )
goto V_225;
V_2 -> V_212 . V_226 = F_83 ( sizeof( struct V_227 ) ,
V_36 ) ;
if ( ! V_2 -> V_212 . V_226 )
goto V_228;
return 0 ;
V_228:
F_84 ( V_2 -> V_212 . V_223 ) ;
V_225:
F_84 ( V_2 -> V_212 . V_218 ) ;
V_220:
F_84 ( V_2 -> V_212 . V_216 ) ;
V_217:
F_84 ( V_2 -> V_212 . V_213 ) ;
return - V_215 ;
}
static void F_85 ( struct V_2 * V_2 )
{
F_84 ( V_2 -> V_212 . V_213 ) ;
F_84 ( V_2 -> V_212 . V_216 ) ;
F_84 ( V_2 -> V_212 . V_218 ) ;
F_84 ( V_2 -> V_212 . V_223 ) ;
F_86 ( V_2 -> V_212 . V_226 ) ;
}
static int T_3 F_87 ( struct V_2 * V_2 )
{
int V_18 = 0 ;
V_2 -> V_61 . V_62 . V_63 = 0 ;
V_2 -> V_61 . V_62 . V_229 = 1 * V_230 ;
V_2 -> V_61 . V_62 . V_231 = 1 ;
V_2 -> V_61 . V_62 . V_232 = V_233 ;
V_2 -> V_61 . V_62 . V_234 = 3 ;
V_2 -> V_61 . V_62 . V_235 = 1 * V_230 ;
V_2 -> V_61 . V_62 . V_236 = 0 ;
F_88 ( & V_2 -> V_61 . V_237 , 1 ) ;
V_18 = F_78 ( V_2 ) ;
if ( V_18 )
return V_18 ;
#ifdef F_89
V_18 = F_90 ( V_2 ) ;
if ( V_18 )
goto V_37;
V_18 = F_91 ( V_2 ) ;
if ( V_18 )
goto V_238;
V_18 = F_92 ( V_2 ) ;
if ( V_18 )
goto V_239;
#endif
return V_18 ;
#ifdef F_89
V_239:
F_93 ( V_2 ) ;
V_238:
F_94 ( V_2 ) ;
V_37:
F_85 ( V_2 ) ;
return V_18 ;
#endif
}
static void T_4 F_95 ( struct V_2 * V_2 )
{
#ifdef F_89
F_94 ( V_2 ) ;
F_93 ( V_2 ) ;
F_96 ( V_2 ) ;
#endif
F_85 ( V_2 ) ;
}
static int T_2 F_97 ( void )
{
struct V_164 * V_240 ;
int V_18 = 0 ;
F_98 ( sizeof( struct V_195 ) ) ;
for ( V_240 = & V_171 [ 0 ] ; V_240 < & V_171 [ V_169 ] ; ++ V_240 )
F_99 ( V_240 ) ;
if ( V_1 ) {
F_100 ( L_6 ) ;
goto V_37;
}
V_18 = F_101 ( & V_241 , 1 ) ;
if ( V_18 )
goto V_37;
V_18 = F_101 ( & V_242 , 1 ) ;
if ( V_18 )
goto V_243;
V_18 = F_101 ( & V_244 , 1 ) ;
if ( V_18 )
goto V_245;
V_18 = F_101 ( & V_246 , 1 ) ;
if ( V_18 )
goto V_247;
V_18 = F_101 ( & V_248 , 1 ) ;
if ( V_18 )
goto V_249;
V_18 = F_102 () ;
if ( V_18 )
goto V_250;
V_18 = F_103 ( & V_251 ) ;
if ( V_18 )
goto V_252;
V_18 = F_104 ( & V_253 ) ;
if ( V_18 )
goto V_254;
V_18 = F_105 () ;
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
V_259 = & V_260 ;
V_18 = F_109 () ;
if ( V_18 )
goto V_261;
#ifdef F_89
V_18 = - V_215 ;
if ( F_110 () )
goto V_262;
if ( F_111 () )
goto V_263;
if ( F_112 () )
goto V_264;
if ( F_113 () )
goto V_265;
#endif
V_18 = F_114 () ;
if ( V_18 )
goto V_266;
V_18 = F_115 () ;
if ( V_18 )
goto V_267;
V_18 = F_116 () ;
if ( V_18 )
goto V_268;
V_18 = F_117 () ;
if ( V_18 )
goto V_269;
V_18 = F_118 () ;
if ( V_18 )
goto V_270;
V_18 = F_119 () ;
if ( V_18 )
goto V_271;
V_18 = F_120 () ;
if ( V_18 )
goto V_272;
V_18 = F_121 () ;
if ( V_18 )
goto V_273;
V_18 = F_122 () ;
if ( V_18 )
goto V_274;
V_18 = F_123 () ;
if ( V_18 )
goto V_275;
V_18 = F_74 () ;
if ( V_18 )
goto V_276;
V_18 = F_124 () ;
if ( V_18 )
goto V_277;
V_18 = F_125 () ;
if ( V_18 )
goto V_278;
V_18 = F_126 () ;
if ( V_18 )
goto V_279;
#ifdef F_127
V_18 = F_128 () ;
if ( V_18 )
goto V_280;
#endif
V_37:
return V_18 ;
#ifdef F_127
V_280:
F_129 () ;
#endif
V_279:
F_130 () ;
V_278:
F_131 () ;
V_277:
F_76 () ;
V_276:
F_132 () ;
V_275:
F_133 () ;
V_274:
F_134 () ;
V_273:
F_135 () ;
V_272:
F_136 () ;
V_271:
F_137 () ;
V_270:
F_138 () ;
V_269:
F_139 () ;
V_268:
F_140 () ;
V_267:
F_141 () ;
V_266:
#ifdef F_89
F_142 () ;
V_265:
F_143 () ;
V_264:
F_144 () ;
V_263:
F_145 () ;
V_262:
#endif
F_146 () ;
V_261:
F_147 () ;
V_258:
F_148 () ;
V_257:
F_149 () ;
V_256:
F_150 () ;
V_255:
F_151 ( & V_253 ) ;
V_254:
F_152 ( V_25 ) ;
F_153 ( V_25 ) ;
V_252:
F_154 () ;
V_249:
F_155 ( & V_248 ) ;
V_250:
F_155 ( & V_246 ) ;
V_247:
F_155 ( & V_244 ) ;
V_245:
F_155 ( & V_242 ) ;
V_243:
F_155 ( & V_241 ) ;
goto V_37;
}
