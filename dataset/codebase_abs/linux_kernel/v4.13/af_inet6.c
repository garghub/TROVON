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
if ( V_83 && V_83 < F_23 ( V_2 ) &&
! F_7 ( V_2 -> V_29 , V_94 ) )
return - V_95 ;
F_24 ( V_11 ) ;
if ( V_11 -> V_96 != V_97 || V_8 -> V_43 ) {
V_18 = - V_20 ;
goto V_37;
}
if ( V_84 == V_98 ) {
int V_99 ;
if ( V_11 -> V_60 ) {
V_18 = - V_20 ;
goto V_37;
}
V_82 = V_81 -> V_90 . V_100 [ 3 ] ;
V_99 = F_25 ( V_2 , V_82 ) ;
if ( ! V_2 -> V_69 . V_101 &&
! ( V_8 -> V_102 || V_8 -> V_103 ) &&
V_82 != F_26 ( V_104 ) &&
V_99 != V_105 &&
V_99 != V_106 &&
V_99 != V_107 ) {
V_18 = - V_108 ;
goto V_37;
}
} else {
if ( V_84 != V_109 ) {
struct V_110 * V_111 = NULL ;
F_3 () ;
if ( F_27 ( V_84 ) ) {
if ( V_79 >= sizeof( struct V_80 ) &&
V_81 -> V_112 ) {
V_11 -> V_113 = V_81 -> V_112 ;
}
if ( ! V_11 -> V_113 ) {
V_18 = - V_20 ;
goto V_114;
}
V_111 = F_28 ( V_2 , V_11 -> V_113 ) ;
if ( ! V_111 ) {
V_18 = - V_115 ;
goto V_114;
}
}
V_82 = V_116 ;
if ( ! ( V_84 & V_91 ) ) {
if ( ! V_2 -> V_61 . V_62 . V_117 &&
! ( V_8 -> V_102 || V_8 -> V_103 ) &&
! F_29 ( V_2 , & V_81 -> V_90 ,
V_111 , 0 ) ) {
V_18 = - V_108 ;
goto V_114;
}
}
F_5 () ;
}
}
V_8 -> V_118 = V_82 ;
V_8 -> V_119 = V_82 ;
V_11 -> V_120 = V_81 -> V_90 ;
if ( ! ( V_84 & V_91 ) )
V_10 -> V_121 = V_81 -> V_90 ;
if ( ( V_83 || ! V_8 -> V_122 ) &&
V_11 -> V_74 -> V_123 ( V_11 , V_83 ) ) {
F_30 ( V_11 ) ;
V_18 = - V_124 ;
goto V_37;
}
if ( V_84 != V_109 ) {
V_11 -> V_125 |= V_126 ;
if ( V_84 != V_98 )
V_11 -> V_60 = 1 ;
}
if ( V_83 )
V_11 -> V_125 |= V_127 ;
V_8 -> V_73 = F_16 ( V_8 -> V_43 ) ;
V_8 -> V_128 = 0 ;
V_8 -> V_129 = 0 ;
V_37:
F_31 ( V_11 ) ;
return V_18 ;
V_114:
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
struct V_9 * V_10 = F_20 ( V_11 ) ;
struct V_130 * V_131 ;
struct V_132 * V_133 ;
V_131 = F_37 ( & V_10 -> V_134 , NULL ) ;
if ( V_131 )
F_38 ( V_131 ) ;
V_131 = F_37 ( & V_10 -> V_135 , NULL ) ;
if ( V_131 )
F_38 ( V_131 ) ;
F_39 ( V_11 ) ;
V_133 = F_37 ( ( V_136 struct V_132 * * ) & V_10 -> V_133 , NULL ) ;
if ( V_133 ) {
F_40 ( V_133 -> V_137 , & V_11 -> V_138 ) ;
F_41 ( V_133 ) ;
}
}
int F_42 ( struct V_3 * V_4 , struct V_77 * V_78 ,
int * V_139 , int V_140 )
{
struct V_80 * sin = (struct V_80 * ) V_78 ;
struct V_4 * V_11 = V_4 -> V_11 ;
struct V_7 * V_8 = F_11 ( V_11 ) ;
struct V_9 * V_10 = F_20 ( V_11 ) ;
sin -> V_87 = V_88 ;
sin -> V_141 = 0 ;
sin -> V_112 = 0 ;
if ( V_140 ) {
if ( ! V_8 -> V_128 )
return - V_142 ;
if ( ( ( 1 << V_11 -> V_96 ) & ( V_143 | V_144 ) ) &&
V_140 == 1 )
return - V_142 ;
sin -> V_93 = V_8 -> V_128 ;
sin -> V_90 = V_11 -> V_145 ;
if ( V_10 -> V_146 )
sin -> V_141 = V_10 -> V_147 ;
} else {
if ( F_43 ( & V_11 -> V_120 ) )
sin -> V_90 = V_10 -> V_121 ;
else
sin -> V_90 = V_11 -> V_120 ;
sin -> V_93 = V_8 -> V_73 ;
}
sin -> V_112 = F_44 ( & sin -> V_90 ,
V_11 -> V_113 ) ;
* V_139 = sizeof( * sin ) ;
return 0 ;
}
int F_45 ( struct V_3 * V_4 , unsigned int V_148 , unsigned long V_149 )
{
struct V_4 * V_11 = V_4 -> V_11 ;
struct V_2 * V_2 = F_14 ( V_11 ) ;
switch ( V_148 ) {
case V_150 :
return F_46 ( V_11 , (struct V_151 V_152 * ) V_149 ) ;
case V_153 :
return F_47 ( V_11 , (struct V_154 V_152 * ) V_149 ) ;
case V_155 :
case V_156 :
return F_48 ( V_2 , V_148 , ( void V_152 * ) V_149 ) ;
case V_157 :
return F_49 ( V_2 , ( void V_152 * ) V_149 ) ;
case V_158 :
return F_50 ( V_2 , ( void V_152 * ) V_149 ) ;
case V_159 :
return F_51 ( V_2 , ( void V_152 * ) V_149 ) ;
default:
if ( ! V_11 -> V_74 -> V_160 )
return - V_161 ;
return V_11 -> V_74 -> V_160 ( V_11 , V_148 , V_149 ) ;
}
return 0 ;
}
int F_52 ( struct V_12 * V_162 )
{
struct V_163 * V_164 ;
struct V_12 * V_13 ;
struct V_163 * V_165 ;
int V_5 = V_162 -> V_5 ;
int V_166 ;
F_53 ( & V_167 ) ;
V_166 = - V_20 ;
if ( V_162 -> type >= V_168 )
goto V_169;
V_13 = NULL ;
V_166 = - V_27 ;
V_165 = & V_170 [ V_162 -> type ] ;
F_54 (lh, &inetsw6[p->type]) {
V_13 = F_55 ( V_164 , struct V_12 , V_171 ) ;
if ( V_172 & V_13 -> V_33 ) {
if ( V_5 == V_13 -> V_5 )
break;
V_165 = V_164 ;
}
V_13 = NULL ;
}
if ( V_13 )
goto V_173;
F_56 ( & V_162 -> V_171 , V_165 ) ;
V_166 = 0 ;
V_37:
F_57 ( & V_167 ) ;
return V_166 ;
V_173:
F_58 ( L_3 , V_5 ) ;
goto V_37;
V_169:
F_58 ( L_4 ,
V_162 -> type ) ;
goto V_37;
}
void
F_59 ( struct V_12 * V_162 )
{
if ( V_172 & V_162 -> V_33 ) {
F_58 ( L_5 ,
V_162 -> V_5 ) ;
} else {
F_53 ( & V_167 ) ;
F_60 ( & V_162 -> V_171 ) ;
F_57 ( & V_167 ) ;
F_61 () ;
}
}
int F_62 ( struct V_4 * V_11 )
{
struct V_9 * V_10 = F_20 ( V_11 ) ;
struct V_174 * V_175 ;
V_175 = F_63 ( V_11 , V_10 -> V_176 ) ;
if ( ! V_175 ) {
struct V_7 * V_8 = F_11 ( V_11 ) ;
struct V_177 * V_178 , V_179 ;
struct V_180 V_181 ;
memset ( & V_181 , 0 , sizeof( V_181 ) ) ;
V_181 . V_182 = V_11 -> V_49 ;
V_181 . V_183 = V_11 -> V_145 ;
V_181 . V_121 = V_10 -> V_121 ;
V_181 . V_184 = V_10 -> V_147 ;
V_181 . V_185 = V_11 -> V_113 ;
V_181 . V_186 = V_11 -> V_187 ;
V_181 . V_188 = V_8 -> V_128 ;
V_181 . V_189 = V_8 -> V_73 ;
V_181 . V_190 = V_11 -> V_191 ;
F_64 ( V_11 , F_65 ( & V_181 ) ) ;
F_3 () ;
V_178 = F_66 ( & V_181 , F_67 ( V_10 -> V_133 ) ,
& V_179 ) ;
F_5 () ;
V_175 = F_68 ( V_11 , & V_181 , V_178 ) ;
if ( F_69 ( V_175 ) ) {
V_11 -> V_192 = 0 ;
V_11 -> V_193 = - F_70 ( V_175 ) ;
return F_70 ( V_175 ) ;
}
F_71 ( V_11 , V_175 , NULL , NULL ) ;
}
return 0 ;
}
bool F_72 ( const struct V_4 * V_11 , const struct V_130 * V_131 ,
const struct V_194 * V_133 )
{
const struct V_9 * V_10 = F_20 ( V_11 ) ;
if ( V_10 -> V_195 . V_196 ) {
if ( ( ( V_133 -> V_33 & V_197 ) &&
( V_10 -> V_195 . V_198 . V_199 || V_10 -> V_195 . V_198 . V_200 ) ) ||
( F_73 ( (struct V_201 * ) F_74 ( V_131 ) ) &&
V_10 -> V_195 . V_198 . V_202 ) ||
( V_133 -> V_203 && ( V_10 -> V_195 . V_198 . V_203 ||
V_10 -> V_195 . V_198 . V_204 ) ) ||
( ( V_133 -> V_205 || V_133 -> V_206 ) &&
( V_10 -> V_195 . V_198 . V_207 || V_10 -> V_195 . V_198 . V_208 ) ) )
return true ;
}
return false ;
}
static int T_2 F_75 ( void )
{
F_76 ( & V_209 ) ;
return 0 ;
}
static void F_77 ( void )
{
F_78 ( & V_209 ) ;
}
static int T_3 F_79 ( struct V_2 * V_2 )
{
int V_210 ;
V_2 -> V_211 . V_212 = F_80 ( struct V_213 ) ;
if ( ! V_2 -> V_211 . V_212 )
return - V_214 ;
V_2 -> V_211 . V_215 = F_80 ( struct V_213 ) ;
if ( ! V_2 -> V_211 . V_215 )
goto V_216;
V_2 -> V_211 . V_217 = F_80 ( struct V_218 ) ;
if ( ! V_2 -> V_211 . V_217 )
goto V_219;
F_81 (i) {
struct V_218 * V_220 ;
V_220 = F_82 ( V_2 -> V_211 . V_217 , V_210 ) ;
F_83 ( & V_220 -> V_221 ) ;
}
V_2 -> V_211 . V_222 = F_80 ( struct V_223 ) ;
if ( ! V_2 -> V_211 . V_222 )
goto V_224;
V_2 -> V_211 . V_225 = F_84 ( sizeof( struct V_226 ) ,
V_36 ) ;
if ( ! V_2 -> V_211 . V_225 )
goto V_227;
return 0 ;
V_227:
F_85 ( V_2 -> V_211 . V_222 ) ;
V_224:
F_85 ( V_2 -> V_211 . V_217 ) ;
V_219:
F_85 ( V_2 -> V_211 . V_215 ) ;
V_216:
F_85 ( V_2 -> V_211 . V_212 ) ;
return - V_214 ;
}
static void F_86 ( struct V_2 * V_2 )
{
F_85 ( V_2 -> V_211 . V_212 ) ;
F_85 ( V_2 -> V_211 . V_215 ) ;
F_85 ( V_2 -> V_211 . V_217 ) ;
F_85 ( V_2 -> V_211 . V_222 ) ;
F_87 ( V_2 -> V_211 . V_225 ) ;
}
static int T_3 F_88 ( struct V_2 * V_2 )
{
int V_18 = 0 ;
V_2 -> V_61 . V_62 . V_63 = 0 ;
V_2 -> V_61 . V_62 . V_228 = 1 * V_229 ;
V_2 -> V_61 . V_62 . V_230 = 1 ;
V_2 -> V_61 . V_62 . V_231 = V_232 ;
V_2 -> V_61 . V_62 . V_233 = 3 ;
V_2 -> V_61 . V_62 . V_234 = 1 * V_229 ;
V_2 -> V_61 . V_62 . V_235 = 0 ;
F_89 ( & V_2 -> V_61 . V_236 , 1 ) ;
V_18 = F_79 ( V_2 ) ;
if ( V_18 )
return V_18 ;
#ifdef F_90
V_18 = F_91 ( V_2 ) ;
if ( V_18 )
goto V_37;
V_18 = F_92 ( V_2 ) ;
if ( V_18 )
goto V_237;
V_18 = F_93 ( V_2 ) ;
if ( V_18 )
goto V_238;
#endif
return V_18 ;
#ifdef F_90
V_238:
F_94 ( V_2 ) ;
V_237:
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
struct V_163 * V_239 ;
int V_18 = 0 ;
F_99 ( sizeof( struct V_194 ) ) ;
for ( V_239 = & V_170 [ 0 ] ; V_239 < & V_170 [ V_168 ] ; ++ V_239 )
F_100 ( V_239 ) ;
if ( V_1 ) {
F_101 ( L_6 ) ;
goto V_37;
}
V_18 = F_102 ( & V_240 , 1 ) ;
if ( V_18 )
goto V_37;
V_18 = F_102 ( & V_241 , 1 ) ;
if ( V_18 )
goto V_242;
V_18 = F_102 ( & V_243 , 1 ) ;
if ( V_18 )
goto V_244;
V_18 = F_102 ( & V_245 , 1 ) ;
if ( V_18 )
goto V_246;
V_18 = F_102 ( & V_247 , 1 ) ;
if ( V_18 )
goto V_248;
V_18 = F_103 () ;
if ( V_18 )
goto V_249;
V_18 = F_104 ( & V_250 ) ;
if ( V_18 )
goto V_251;
V_18 = F_105 ( & V_252 ) ;
if ( V_18 )
goto V_253;
V_18 = F_106 () ;
if ( V_18 )
goto V_254;
V_18 = F_107 () ;
if ( V_18 )
goto V_255;
V_18 = F_108 () ;
if ( V_18 )
goto V_256;
V_18 = F_109 () ;
if ( V_18 )
goto V_257;
V_18 = F_110 () ;
if ( V_18 )
goto V_258;
#ifdef F_90
V_18 = - V_214 ;
if ( F_111 () )
goto V_259;
if ( F_112 () )
goto V_260;
if ( F_113 () )
goto V_261;
if ( F_114 () )
goto V_262;
#endif
V_18 = F_115 () ;
if ( V_18 )
goto V_263;
V_18 = F_116 () ;
if ( V_18 )
goto V_264;
V_18 = F_117 () ;
if ( V_18 )
goto V_265;
V_18 = F_118 () ;
if ( V_18 )
goto V_266;
V_18 = F_119 () ;
if ( V_18 )
goto V_267;
V_18 = F_120 () ;
if ( V_18 )
goto V_268;
V_18 = F_121 () ;
if ( V_18 )
goto V_269;
V_18 = F_122 () ;
if ( V_18 )
goto V_270;
V_18 = F_123 () ;
if ( V_18 )
goto V_271;
V_18 = F_124 () ;
if ( V_18 )
goto V_272;
V_18 = F_75 () ;
if ( V_18 )
goto V_273;
V_18 = F_125 () ;
if ( V_18 )
goto V_274;
V_18 = F_126 () ;
if ( V_18 )
goto V_275;
V_18 = F_127 () ;
if ( V_18 )
goto V_276;
V_18 = F_128 () ;
if ( V_18 )
goto V_277;
#ifdef F_129
V_18 = F_130 () ;
if ( V_18 )
goto V_278;
#endif
F_131 () ;
V_279 = & V_280 ;
V_37:
return V_18 ;
#ifdef F_129
V_278:
F_132 () ;
#endif
V_277:
F_133 () ;
V_276:
F_134 () ;
V_275:
F_135 () ;
V_274:
F_77 () ;
V_273:
F_136 () ;
V_272:
F_137 () ;
V_271:
F_138 () ;
V_270:
F_139 () ;
V_269:
F_140 () ;
V_268:
F_141 () ;
V_267:
F_142 () ;
V_266:
F_143 () ;
V_265:
F_144 () ;
V_264:
F_145 () ;
V_263:
#ifdef F_90
F_146 () ;
V_262:
F_147 () ;
V_261:
F_148 () ;
V_260:
F_149 () ;
V_259:
#endif
F_150 () ;
V_258:
F_151 () ;
V_257:
F_152 () ;
V_256:
F_153 () ;
V_255:
F_154 ( & V_252 ) ;
V_254:
F_155 () ;
V_253:
F_156 ( V_25 ) ;
F_157 ( V_25 ) ;
V_251:
F_158 () ;
V_248:
F_159 ( & V_247 ) ;
V_249:
F_159 ( & V_245 ) ;
V_246:
F_159 ( & V_243 ) ;
V_244:
F_159 ( & V_241 ) ;
V_242:
F_159 ( & V_240 ) ;
goto V_37;
}
