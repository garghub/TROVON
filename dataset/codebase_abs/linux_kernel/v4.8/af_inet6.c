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
V_37:
return V_18 ;
V_26:
F_5 () ;
goto V_37;
}
int F_18 ( struct V_3 * V_4 , struct V_77 * V_78 , int V_79 )
{
struct V_80 * V_81 = (struct V_80 * ) V_78 ;
struct V_4 * V_11 = V_4 -> V_11 ;
struct V_7 * V_8 = F_11 ( V_11 ) ;
struct V_9 * V_10 = F_19 ( V_11 ) ;
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
V_84 = F_20 ( & V_81 -> V_90 ) ;
if ( ( V_84 & V_91 ) && V_4 -> type == V_92 )
return - V_20 ;
V_83 = F_21 ( V_81 -> V_93 ) ;
if ( V_83 && V_83 < V_94 && ! F_7 ( V_2 -> V_29 , V_95 ) )
return - V_96 ;
F_22 ( V_11 ) ;
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
V_100 = F_23 ( V_2 , V_82 ) ;
if ( ! V_2 -> V_69 . V_102 &&
! ( V_8 -> V_103 || V_8 -> V_104 ) &&
V_82 != F_24 ( V_105 ) &&
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
if ( F_25 ( V_84 ) ) {
if ( V_79 >= sizeof( struct V_80 ) &&
V_81 -> V_113 ) {
V_11 -> V_114 = V_81 -> V_113 ;
}
if ( ! V_11 -> V_114 ) {
V_18 = - V_20 ;
goto V_115;
}
V_112 = F_26 ( V_2 , V_11 -> V_114 ) ;
if ( ! V_112 ) {
V_18 = - V_116 ;
goto V_115;
}
}
V_82 = V_117 ;
if ( ! ( V_84 & V_91 ) ) {
if ( ! V_2 -> V_61 . V_62 . V_118 &&
! ( V_8 -> V_103 || V_8 -> V_104 ) &&
! F_27 ( V_2 , & V_81 -> V_90 ,
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
F_28 ( V_11 ) ;
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
F_29 ( V_11 ) ;
return V_18 ;
V_115:
F_5 () ;
goto V_37;
}
int F_30 ( struct V_3 * V_4 )
{
struct V_4 * V_11 = V_4 -> V_11 ;
if ( ! V_11 )
return - V_20 ;
F_31 ( V_11 ) ;
F_32 ( V_11 ) ;
return F_33 ( V_4 ) ;
}
void F_34 ( struct V_4 * V_11 )
{
struct V_9 * V_10 = F_19 ( V_11 ) ;
struct V_131 * V_132 ;
struct V_133 * V_134 ;
V_132 = F_35 ( & V_10 -> V_135 , NULL ) ;
if ( V_132 )
F_36 ( V_132 ) ;
V_132 = F_35 ( & V_10 -> V_136 , NULL ) ;
if ( V_132 )
F_36 ( V_132 ) ;
F_37 ( V_11 ) ;
V_134 = F_35 ( ( V_137 struct V_133 * * ) & V_10 -> V_134 , NULL ) ;
if ( V_134 ) {
F_38 ( V_134 -> V_138 , & V_11 -> V_139 ) ;
F_39 ( V_134 ) ;
}
}
int F_40 ( struct V_3 * V_4 , struct V_77 * V_78 ,
int * V_140 , int V_141 )
{
struct V_80 * sin = (struct V_80 * ) V_78 ;
struct V_4 * V_11 = V_4 -> V_11 ;
struct V_7 * V_8 = F_11 ( V_11 ) ;
struct V_9 * V_10 = F_19 ( V_11 ) ;
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
if ( F_41 ( & V_11 -> V_121 ) )
sin -> V_90 = V_10 -> V_122 ;
else
sin -> V_90 = V_11 -> V_121 ;
sin -> V_93 = V_8 -> V_73 ;
}
sin -> V_113 = F_42 ( & sin -> V_90 ,
V_11 -> V_114 ) ;
* V_140 = sizeof( * sin ) ;
return 0 ;
}
int F_43 ( struct V_3 * V_4 , unsigned int V_149 , unsigned long V_150 )
{
struct V_4 * V_11 = V_4 -> V_11 ;
struct V_2 * V_2 = F_14 ( V_11 ) ;
switch ( V_149 ) {
case V_151 :
return F_44 ( V_11 , (struct V_152 V_153 * ) V_150 ) ;
case V_154 :
return F_45 ( V_11 , (struct V_155 V_153 * ) V_150 ) ;
case V_156 :
case V_157 :
return F_46 ( V_2 , V_149 , ( void V_153 * ) V_150 ) ;
case V_158 :
return F_47 ( V_2 , ( void V_153 * ) V_150 ) ;
case V_159 :
return F_48 ( V_2 , ( void V_153 * ) V_150 ) ;
case V_160 :
return F_49 ( V_2 , ( void V_153 * ) V_150 ) ;
default:
if ( ! V_11 -> V_74 -> V_161 )
return - V_162 ;
return V_11 -> V_74 -> V_161 ( V_11 , V_149 , V_150 ) ;
}
return 0 ;
}
int F_50 ( struct V_12 * V_163 )
{
struct V_164 * V_165 ;
struct V_12 * V_13 ;
struct V_164 * V_166 ;
int V_5 = V_163 -> V_5 ;
int V_167 ;
F_51 ( & V_168 ) ;
V_167 = - V_20 ;
if ( V_163 -> type >= V_169 )
goto V_170;
V_13 = NULL ;
V_167 = - V_27 ;
V_166 = & V_171 [ V_163 -> type ] ;
F_52 (lh, &inetsw6[p->type]) {
V_13 = F_53 ( V_165 , struct V_12 , V_172 ) ;
if ( V_173 & V_13 -> V_33 ) {
if ( V_5 == V_13 -> V_5 )
break;
V_166 = V_165 ;
}
V_13 = NULL ;
}
if ( V_13 )
goto V_174;
F_54 ( & V_163 -> V_172 , V_166 ) ;
V_167 = 0 ;
V_37:
F_55 ( & V_168 ) ;
return V_167 ;
V_174:
F_56 ( L_3 , V_5 ) ;
goto V_37;
V_170:
F_56 ( L_4 ,
V_163 -> type ) ;
goto V_37;
}
void
F_57 ( struct V_12 * V_163 )
{
if ( V_173 & V_163 -> V_33 ) {
F_56 ( L_5 ,
V_163 -> V_5 ) ;
} else {
F_51 ( & V_168 ) ;
F_58 ( & V_163 -> V_172 ) ;
F_55 ( & V_168 ) ;
F_59 () ;
}
}
int F_60 ( struct V_4 * V_11 )
{
struct V_9 * V_10 = F_19 ( V_11 ) ;
struct V_175 * V_176 ;
V_176 = F_61 ( V_11 , V_10 -> V_177 ) ;
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
F_62 ( V_11 , F_63 ( & V_182 ) ) ;
F_3 () ;
V_179 = F_64 ( & V_182 , F_65 ( V_10 -> V_134 ) ,
& V_180 ) ;
F_5 () ;
V_176 = F_66 ( V_11 , & V_182 , V_179 ) ;
if ( F_67 ( V_176 ) ) {
V_11 -> V_191 = 0 ;
V_11 -> V_192 = - F_68 ( V_176 ) ;
return F_68 ( V_176 ) ;
}
F_69 ( V_11 , V_176 , NULL , NULL ) ;
}
return 0 ;
}
bool F_70 ( const struct V_4 * V_11 , const struct V_131 * V_132 ,
const struct V_193 * V_134 )
{
const struct V_9 * V_10 = F_19 ( V_11 ) ;
if ( V_10 -> V_194 . V_195 ) {
if ( ( ( V_134 -> V_33 & V_196 ) &&
( V_10 -> V_194 . V_197 . V_198 || V_10 -> V_194 . V_197 . V_199 ) ) ||
( F_71 ( (struct V_200 * ) F_72 ( V_132 ) ) &&
V_10 -> V_194 . V_197 . V_201 ) ||
( V_134 -> V_202 && ( V_10 -> V_194 . V_197 . V_202 ||
V_10 -> V_194 . V_197 . V_203 ) ) ||
( ( V_134 -> V_204 || V_134 -> V_205 ) &&
( V_10 -> V_194 . V_197 . V_206 || V_10 -> V_194 . V_197 . V_207 ) ) )
return true ;
}
return false ;
}
static int T_2 F_73 ( void )
{
F_74 ( & V_208 ) ;
return 0 ;
}
static void F_75 ( void )
{
F_76 ( & V_208 ) ;
}
static int T_3 F_77 ( struct V_2 * V_2 )
{
int V_209 ;
V_2 -> V_210 . V_211 = F_78 ( struct V_212 ) ;
if ( ! V_2 -> V_210 . V_211 )
return - V_213 ;
V_2 -> V_210 . V_214 = F_78 ( struct V_212 ) ;
if ( ! V_2 -> V_210 . V_214 )
goto V_215;
V_2 -> V_210 . V_216 = F_78 ( struct V_217 ) ;
if ( ! V_2 -> V_210 . V_216 )
goto V_218;
F_79 (i) {
struct V_217 * V_219 ;
V_219 = F_80 ( V_2 -> V_210 . V_216 , V_209 ) ;
F_81 ( & V_219 -> V_220 ) ;
}
V_2 -> V_210 . V_221 = F_78 ( struct V_222 ) ;
if ( ! V_2 -> V_210 . V_221 )
goto V_223;
V_2 -> V_210 . V_224 = F_82 ( sizeof( struct V_225 ) ,
V_36 ) ;
if ( ! V_2 -> V_210 . V_224 )
goto V_226;
return 0 ;
V_226:
F_83 ( V_2 -> V_210 . V_221 ) ;
V_223:
F_83 ( V_2 -> V_210 . V_216 ) ;
V_218:
F_83 ( V_2 -> V_210 . V_214 ) ;
V_215:
F_83 ( V_2 -> V_210 . V_211 ) ;
return - V_213 ;
}
static void F_84 ( struct V_2 * V_2 )
{
F_83 ( V_2 -> V_210 . V_211 ) ;
F_83 ( V_2 -> V_210 . V_214 ) ;
F_83 ( V_2 -> V_210 . V_216 ) ;
F_83 ( V_2 -> V_210 . V_221 ) ;
F_85 ( V_2 -> V_210 . V_224 ) ;
}
static int T_3 F_86 ( struct V_2 * V_2 )
{
int V_18 = 0 ;
V_2 -> V_61 . V_62 . V_63 = 0 ;
V_2 -> V_61 . V_62 . V_227 = 1 * V_228 ;
V_2 -> V_61 . V_62 . V_229 = 1 ;
V_2 -> V_61 . V_62 . V_230 = V_231 ;
V_2 -> V_61 . V_62 . V_232 = 3 ;
V_2 -> V_61 . V_62 . V_233 = 1 * V_228 ;
V_2 -> V_61 . V_62 . V_234 = 0 ;
F_87 ( & V_2 -> V_61 . V_235 , 1 ) ;
V_18 = F_77 ( V_2 ) ;
if ( V_18 )
return V_18 ;
#ifdef F_88
V_18 = F_89 ( V_2 ) ;
if ( V_18 )
goto V_37;
V_18 = F_90 ( V_2 ) ;
if ( V_18 )
goto V_236;
V_18 = F_91 ( V_2 ) ;
if ( V_18 )
goto V_237;
#endif
return V_18 ;
#ifdef F_88
V_237:
F_92 ( V_2 ) ;
V_236:
F_93 ( V_2 ) ;
V_37:
F_84 ( V_2 ) ;
return V_18 ;
#endif
}
static void T_4 F_94 ( struct V_2 * V_2 )
{
#ifdef F_88
F_93 ( V_2 ) ;
F_92 ( V_2 ) ;
F_95 ( V_2 ) ;
#endif
F_84 ( V_2 ) ;
}
static int T_2 F_96 ( void )
{
struct V_164 * V_238 ;
int V_18 = 0 ;
F_97 ( sizeof( struct V_193 ) ) ;
for ( V_238 = & V_171 [ 0 ] ; V_238 < & V_171 [ V_169 ] ; ++ V_238 )
F_98 ( V_238 ) ;
if ( V_1 ) {
F_99 ( L_6 ) ;
goto V_37;
}
V_18 = F_100 ( & V_239 , 1 ) ;
if ( V_18 )
goto V_37;
V_18 = F_100 ( & V_240 , 1 ) ;
if ( V_18 )
goto V_241;
V_18 = F_100 ( & V_242 , 1 ) ;
if ( V_18 )
goto V_243;
V_18 = F_100 ( & V_244 , 1 ) ;
if ( V_18 )
goto V_245;
V_18 = F_100 ( & V_246 , 1 ) ;
if ( V_18 )
goto V_247;
V_18 = F_101 () ;
if ( V_18 )
goto V_248;
V_18 = F_102 ( & V_249 ) ;
if ( V_18 )
goto V_250;
V_18 = F_103 ( & V_251 ) ;
if ( V_18 )
goto V_252;
V_18 = F_104 () ;
if ( V_18 )
goto V_253;
V_18 = F_105 () ;
if ( V_18 )
goto V_254;
V_18 = F_106 () ;
if ( V_18 )
goto V_255;
V_18 = F_107 () ;
if ( V_18 )
goto V_256;
V_257 = & V_258 ;
V_18 = F_108 () ;
if ( V_18 )
goto V_259;
#ifdef F_88
V_18 = - V_213 ;
if ( F_109 () )
goto V_260;
if ( F_110 () )
goto V_261;
if ( F_111 () )
goto V_262;
if ( F_112 () )
goto V_263;
#endif
V_18 = F_113 () ;
if ( V_18 )
goto V_264;
V_18 = F_114 () ;
if ( V_18 )
goto V_265;
V_18 = F_115 () ;
if ( V_18 )
goto V_266;
V_18 = F_116 () ;
if ( V_18 )
goto V_267;
V_18 = F_117 () ;
if ( V_18 )
goto V_268;
V_18 = F_118 () ;
if ( V_18 )
goto V_269;
V_18 = F_119 () ;
if ( V_18 )
goto V_270;
V_18 = F_120 () ;
if ( V_18 )
goto V_271;
V_18 = F_121 () ;
if ( V_18 )
goto V_272;
V_18 = F_122 () ;
if ( V_18 )
goto V_273;
V_18 = F_73 () ;
if ( V_18 )
goto V_274;
V_18 = F_123 () ;
if ( V_18 )
goto V_275;
V_18 = F_124 () ;
if ( V_18 )
goto V_276;
#ifdef F_125
V_18 = F_126 () ;
if ( V_18 )
goto V_277;
#endif
V_37:
return V_18 ;
#ifdef F_125
V_277:
F_127 () ;
#endif
V_276:
F_128 () ;
V_275:
F_75 () ;
V_274:
F_129 () ;
V_273:
F_130 () ;
V_272:
F_131 () ;
V_271:
F_132 () ;
V_270:
F_133 () ;
V_269:
F_134 () ;
V_268:
F_135 () ;
V_267:
F_136 () ;
V_266:
F_137 () ;
V_265:
F_138 () ;
V_264:
#ifdef F_88
F_139 () ;
V_263:
F_140 () ;
V_262:
F_141 () ;
V_261:
F_142 () ;
V_260:
#endif
F_143 () ;
V_259:
F_144 () ;
V_256:
F_145 () ;
V_255:
F_146 () ;
V_254:
F_147 () ;
V_253:
F_148 ( & V_251 ) ;
V_252:
F_149 ( V_25 ) ;
F_150 ( V_25 ) ;
V_250:
F_151 () ;
V_247:
F_152 ( & V_246 ) ;
V_248:
F_152 ( & V_244 ) ;
V_245:
F_152 ( & V_242 ) ;
V_243:
F_152 ( & V_240 ) ;
V_241:
F_152 ( & V_239 ) ;
goto V_37;
}
