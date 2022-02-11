static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 , int V_4 ,
int V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_3 * V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
unsigned char V_15 ;
int V_16 = 0 ;
int V_17 ;
if ( V_4 < 0 || V_4 >= V_18 )
return - V_19 ;
V_20:
V_17 = - V_21 ;
F_2 () ;
F_3 (answer, &inetsw6[sock->type], list) {
V_17 = 0 ;
if ( V_4 == V_12 -> V_4 ) {
if ( V_4 != V_22 )
break;
} else {
if ( V_22 == V_4 ) {
V_4 = V_12 -> V_4 ;
break;
}
if ( V_22 == V_12 -> V_4 )
break;
}
V_17 = - V_23 ;
}
if ( V_17 ) {
if ( V_16 < 2 ) {
F_4 () ;
if ( ++ V_16 == 1 )
F_5 ( L_1 ,
V_24 , V_4 , V_3 -> type ) ;
else
F_5 ( L_2 ,
V_24 , V_4 ) ;
goto V_20;
} else
goto V_25;
}
V_17 = - V_26 ;
if ( V_3 -> type == V_27 && ! V_5 &&
! F_6 ( V_1 -> V_28 , V_29 ) )
goto V_25;
V_3 -> V_30 = V_12 -> V_30 ;
V_14 = V_12 -> V_31 ;
V_15 = V_12 -> V_32 ;
F_4 () ;
F_7 ( ! V_14 -> V_33 ) ;
V_17 = - V_34 ;
V_10 = F_8 ( V_1 , V_24 , V_35 , V_14 , V_5 ) ;
if ( ! V_10 )
goto V_36;
F_9 ( V_3 , V_10 ) ;
V_17 = 0 ;
if ( V_37 & V_15 )
V_10 -> V_38 = V_39 ;
V_7 = F_10 ( V_10 ) ;
V_7 -> V_40 = ( V_41 & V_15 ) != 0 ;
if ( V_27 == V_3 -> type ) {
V_7 -> V_42 = V_4 ;
if ( V_43 == V_4 )
V_7 -> V_44 = 1 ;
}
V_10 -> V_45 = V_46 ;
V_10 -> V_47 = V_24 ;
V_10 -> V_48 = V_4 ;
V_10 -> V_49 = V_12 -> V_31 -> V_50 ;
F_10 ( V_10 ) -> V_51 = V_9 = F_11 ( V_10 ) ;
V_9 -> V_52 = - 1 ;
V_9 -> V_53 = V_54 ;
V_9 -> V_55 = 1 ;
V_9 -> V_56 = V_57 ;
V_9 -> V_58 = F_12 ( F_13 ( V_10 ) ) ;
V_10 -> V_59 = V_1 -> V_60 . V_61 . V_62 ;
V_7 -> V_63 = - 1 ;
V_7 -> V_55 = 1 ;
V_7 -> V_64 = 1 ;
V_7 -> V_65 = 0 ;
V_7 -> V_66 = NULL ;
V_7 -> V_67 = 0 ;
if ( V_1 -> V_68 . V_69 )
V_7 -> V_56 = V_70 ;
else
V_7 -> V_56 = V_71 ;
F_14 ( V_10 ) ;
if ( V_7 -> V_42 ) {
V_7 -> V_72 = F_15 ( V_7 -> V_42 ) ;
V_10 -> V_73 -> V_74 ( V_10 ) ;
}
if ( V_10 -> V_73 -> V_75 ) {
V_17 = V_10 -> V_73 -> V_75 ( V_10 ) ;
if ( V_17 ) {
F_16 ( V_10 ) ;
goto V_36;
}
}
V_36:
return V_17 ;
V_25:
F_4 () ;
goto V_36;
}
int F_17 ( struct V_2 * V_3 , struct V_76 * V_77 , int V_78 )
{
struct V_79 * V_80 = (struct V_79 * ) V_77 ;
struct V_3 * V_10 = V_3 -> V_10 ;
struct V_6 * V_7 = F_10 ( V_10 ) ;
struct V_8 * V_9 = F_18 ( V_10 ) ;
struct V_1 * V_1 = F_13 ( V_10 ) ;
T_1 V_81 = 0 ;
unsigned short V_82 ;
int V_83 = 0 ;
int V_17 = 0 ;
if ( V_10 -> V_73 -> V_84 )
return V_10 -> V_73 -> V_84 ( V_10 , V_77 , V_78 ) ;
if ( V_78 < V_85 )
return - V_19 ;
if ( V_80 -> V_86 != V_87 )
return - V_88 ;
V_83 = F_19 ( & V_80 -> V_89 ) ;
if ( ( V_83 & V_90 ) && V_3 -> type == V_91 )
return - V_19 ;
V_82 = F_20 ( V_80 -> V_92 ) ;
if ( V_82 && V_82 < V_93 && ! F_6 ( V_1 -> V_28 , V_94 ) )
return - V_95 ;
F_21 ( V_10 ) ;
if ( V_10 -> V_96 != V_97 || V_7 -> V_42 ) {
V_17 = - V_19 ;
goto V_36;
}
if ( V_83 == V_98 ) {
int V_99 ;
if ( V_10 -> V_59 ) {
V_17 = - V_19 ;
goto V_36;
}
V_81 = V_80 -> V_89 . V_100 [ 3 ] ;
V_99 = F_22 ( V_1 , V_81 ) ;
if ( ! V_1 -> V_68 . V_101 &&
! ( V_7 -> V_102 || V_7 -> V_103 ) &&
V_81 != F_23 ( V_104 ) &&
V_99 != V_105 &&
V_99 != V_106 &&
V_99 != V_107 ) {
V_17 = - V_108 ;
goto V_36;
}
} else {
if ( V_83 != V_109 ) {
struct V_110 * V_111 = NULL ;
F_2 () ;
if ( F_24 ( V_83 ) ) {
if ( V_78 >= sizeof( struct V_79 ) &&
V_80 -> V_112 ) {
V_10 -> V_113 = V_80 -> V_112 ;
}
if ( ! V_10 -> V_113 ) {
V_17 = - V_19 ;
goto V_114;
}
V_111 = F_25 ( V_1 , V_10 -> V_113 ) ;
if ( ! V_111 ) {
V_17 = - V_115 ;
goto V_114;
}
}
V_81 = V_116 ;
if ( ! ( V_83 & V_90 ) ) {
if ( ! V_1 -> V_60 . V_61 . V_117 &&
! ( V_7 -> V_102 || V_7 -> V_103 ) &&
! F_26 ( V_1 , & V_80 -> V_89 ,
V_111 , 0 ) ) {
V_17 = - V_108 ;
goto V_114;
}
}
F_4 () ;
}
}
V_7 -> V_118 = V_81 ;
V_7 -> V_119 = V_81 ;
V_10 -> V_120 = V_80 -> V_89 ;
if ( ! ( V_83 & V_90 ) )
V_9 -> V_121 = V_80 -> V_89 ;
if ( ( V_82 || ! V_7 -> V_122 ) &&
V_10 -> V_73 -> V_123 ( V_10 , V_82 ) ) {
F_27 ( V_10 ) ;
V_17 = - V_124 ;
goto V_36;
}
if ( V_83 != V_109 ) {
V_10 -> V_125 |= V_126 ;
if ( V_83 != V_98 )
V_10 -> V_59 = 1 ;
}
if ( V_82 )
V_10 -> V_125 |= V_127 ;
V_7 -> V_72 = F_15 ( V_7 -> V_42 ) ;
V_7 -> V_128 = 0 ;
V_7 -> V_129 = 0 ;
V_36:
F_28 ( V_10 ) ;
return V_17 ;
V_114:
F_4 () ;
goto V_36;
}
int F_29 ( struct V_2 * V_3 )
{
struct V_3 * V_10 = V_3 -> V_10 ;
if ( ! V_10 )
return - V_19 ;
F_30 ( V_10 ) ;
F_31 ( V_10 ) ;
return F_32 ( V_3 ) ;
}
void F_33 ( struct V_3 * V_10 )
{
struct V_8 * V_9 = F_18 ( V_10 ) ;
struct V_130 * V_131 ;
struct V_132 * V_133 ;
V_131 = F_34 ( & V_9 -> V_134 , NULL ) ;
if ( V_131 )
F_35 ( V_131 ) ;
V_131 = F_34 ( & V_9 -> V_135 , NULL ) ;
if ( V_131 )
F_35 ( V_131 ) ;
F_36 ( V_10 ) ;
V_133 = F_34 ( ( V_136 struct V_132 * * ) & V_9 -> V_133 , NULL ) ;
if ( V_133 ) {
F_37 ( V_133 -> V_137 , & V_10 -> V_138 ) ;
F_38 ( V_133 ) ;
}
}
int F_39 ( struct V_2 * V_3 , struct V_76 * V_77 ,
int * V_139 , int V_140 )
{
struct V_79 * sin = (struct V_79 * ) V_77 ;
struct V_3 * V_10 = V_3 -> V_10 ;
struct V_6 * V_7 = F_10 ( V_10 ) ;
struct V_8 * V_9 = F_18 ( V_10 ) ;
sin -> V_86 = V_87 ;
sin -> V_141 = 0 ;
sin -> V_112 = 0 ;
if ( V_140 ) {
if ( ! V_7 -> V_128 )
return - V_142 ;
if ( ( ( 1 << V_10 -> V_96 ) & ( V_143 | V_144 ) ) &&
V_140 == 1 )
return - V_142 ;
sin -> V_92 = V_7 -> V_128 ;
sin -> V_89 = V_10 -> V_145 ;
if ( V_9 -> V_146 )
sin -> V_141 = V_9 -> V_147 ;
} else {
if ( F_40 ( & V_10 -> V_120 ) )
sin -> V_89 = V_9 -> V_121 ;
else
sin -> V_89 = V_10 -> V_120 ;
sin -> V_92 = V_7 -> V_72 ;
}
sin -> V_112 = F_41 ( & sin -> V_89 ,
V_10 -> V_113 ) ;
* V_139 = sizeof( * sin ) ;
return 0 ;
}
int F_42 ( struct V_2 * V_3 , unsigned int V_148 , unsigned long V_149 )
{
struct V_3 * V_10 = V_3 -> V_10 ;
struct V_1 * V_1 = F_13 ( V_10 ) ;
switch ( V_148 ) {
case V_150 :
return F_43 ( V_10 , (struct V_151 V_152 * ) V_149 ) ;
case V_153 :
return F_44 ( V_10 , (struct V_154 V_152 * ) V_149 ) ;
case V_155 :
case V_156 :
return F_45 ( V_1 , V_148 , ( void V_152 * ) V_149 ) ;
case V_157 :
return F_46 ( V_1 , ( void V_152 * ) V_149 ) ;
case V_158 :
return F_47 ( V_1 , ( void V_152 * ) V_149 ) ;
case V_159 :
return F_48 ( V_1 , ( void V_152 * ) V_149 ) ;
default:
if ( ! V_10 -> V_73 -> V_160 )
return - V_161 ;
return V_10 -> V_73 -> V_160 ( V_10 , V_148 , V_149 ) ;
}
return 0 ;
}
int F_49 ( struct V_11 * V_162 )
{
struct V_163 * V_164 ;
struct V_11 * V_12 ;
struct V_163 * V_165 ;
int V_4 = V_162 -> V_4 ;
int V_166 ;
F_50 ( & V_167 ) ;
V_166 = - V_19 ;
if ( V_162 -> type >= V_168 )
goto V_169;
V_12 = NULL ;
V_166 = - V_26 ;
V_165 = & V_170 [ V_162 -> type ] ;
F_51 (lh, &inetsw6[p->type]) {
V_12 = F_52 ( V_164 , struct V_11 , V_171 ) ;
if ( V_172 & V_12 -> V_32 ) {
if ( V_4 == V_12 -> V_4 )
break;
V_165 = V_164 ;
}
V_12 = NULL ;
}
if ( V_12 )
goto V_173;
F_53 ( & V_162 -> V_171 , V_165 ) ;
V_166 = 0 ;
V_36:
F_54 ( & V_167 ) ;
return V_166 ;
V_173:
F_55 ( L_3 , V_4 ) ;
goto V_36;
V_169:
F_55 ( L_4 ,
V_162 -> type ) ;
goto V_36;
}
void
F_56 ( struct V_11 * V_162 )
{
if ( V_172 & V_162 -> V_32 ) {
F_55 ( L_5 ,
V_162 -> V_4 ) ;
} else {
F_50 ( & V_167 ) ;
F_57 ( & V_162 -> V_171 ) ;
F_54 ( & V_167 ) ;
F_58 () ;
}
}
int F_59 ( struct V_3 * V_10 )
{
struct V_8 * V_9 = F_18 ( V_10 ) ;
struct V_174 * V_175 ;
V_175 = F_60 ( V_10 , V_9 -> V_176 ) ;
if ( ! V_175 ) {
struct V_6 * V_7 = F_10 ( V_10 ) ;
struct V_177 * V_178 , V_179 ;
struct V_180 V_181 ;
memset ( & V_181 , 0 , sizeof( V_181 ) ) ;
V_181 . V_182 = V_10 -> V_48 ;
V_181 . V_183 = V_10 -> V_145 ;
V_181 . V_121 = V_9 -> V_121 ;
V_181 . V_184 = V_9 -> V_147 ;
V_181 . V_185 = V_10 -> V_113 ;
V_181 . V_186 = V_10 -> V_187 ;
V_181 . V_188 = V_7 -> V_128 ;
V_181 . V_189 = V_7 -> V_72 ;
F_61 ( V_10 , F_62 ( & V_181 ) ) ;
F_2 () ;
V_178 = F_63 ( & V_181 , F_64 ( V_9 -> V_133 ) ,
& V_179 ) ;
F_4 () ;
V_175 = F_65 ( V_10 , & V_181 , V_178 ) ;
if ( F_66 ( V_175 ) ) {
V_10 -> V_190 = 0 ;
V_10 -> V_191 = - F_67 ( V_175 ) ;
return F_67 ( V_175 ) ;
}
F_68 ( V_10 , V_175 , NULL , NULL ) ;
}
return 0 ;
}
bool F_69 ( const struct V_3 * V_10 , const struct V_130 * V_131 ,
const struct V_192 * V_133 )
{
const struct V_8 * V_9 = F_18 ( V_10 ) ;
if ( V_9 -> V_193 . V_194 ) {
if ( ( ( V_133 -> V_32 & V_195 ) &&
( V_9 -> V_193 . V_196 . V_197 || V_9 -> V_193 . V_196 . V_198 ) ) ||
( F_70 ( (struct V_199 * ) F_71 ( V_131 ) ) &&
V_9 -> V_193 . V_196 . V_200 ) ||
( V_133 -> V_201 && ( V_9 -> V_193 . V_196 . V_201 ||
V_9 -> V_193 . V_196 . V_202 ) ) ||
( ( V_133 -> V_203 || V_133 -> V_204 ) &&
( V_9 -> V_193 . V_196 . V_205 || V_9 -> V_193 . V_196 . V_206 ) ) )
return true ;
}
return false ;
}
static int T_2 F_72 ( void )
{
F_73 ( & V_207 ) ;
return 0 ;
}
static void F_74 ( void )
{
F_75 ( & V_207 ) ;
}
static int T_3 F_76 ( struct V_1 * V_1 )
{
int V_208 ;
V_1 -> V_209 . V_210 = F_77 ( struct V_211 ) ;
if ( ! V_1 -> V_209 . V_210 )
return - V_212 ;
V_1 -> V_209 . V_213 = F_77 ( struct V_211 ) ;
if ( ! V_1 -> V_209 . V_213 )
goto V_214;
V_1 -> V_209 . V_215 = F_77 ( struct V_216 ) ;
if ( ! V_1 -> V_209 . V_215 )
goto V_217;
F_78 (i) {
struct V_216 * V_218 ;
V_218 = F_79 ( V_1 -> V_209 . V_215 , V_208 ) ;
F_80 ( & V_218 -> V_219 ) ;
}
V_1 -> V_209 . V_220 = F_77 ( struct V_221 ) ;
if ( ! V_1 -> V_209 . V_220 )
goto V_222;
V_1 -> V_209 . V_223 = F_81 ( sizeof( struct V_224 ) ,
V_35 ) ;
if ( ! V_1 -> V_209 . V_223 )
goto V_225;
return 0 ;
V_225:
F_82 ( V_1 -> V_209 . V_220 ) ;
V_222:
F_82 ( V_1 -> V_209 . V_215 ) ;
V_217:
F_82 ( V_1 -> V_209 . V_213 ) ;
V_214:
F_82 ( V_1 -> V_209 . V_210 ) ;
return - V_212 ;
}
static void F_83 ( struct V_1 * V_1 )
{
F_82 ( V_1 -> V_209 . V_210 ) ;
F_82 ( V_1 -> V_209 . V_213 ) ;
F_82 ( V_1 -> V_209 . V_215 ) ;
F_82 ( V_1 -> V_209 . V_220 ) ;
F_84 ( V_1 -> V_209 . V_223 ) ;
}
static int T_3 F_85 ( struct V_1 * V_1 )
{
int V_17 = 0 ;
V_1 -> V_60 . V_61 . V_62 = 0 ;
V_1 -> V_60 . V_61 . V_226 = 1 * V_227 ;
V_1 -> V_60 . V_61 . V_228 = 1 ;
V_1 -> V_60 . V_61 . V_229 = V_230 ;
V_1 -> V_60 . V_61 . V_231 = 3 ;
V_1 -> V_60 . V_61 . V_232 = 1 * V_227 ;
V_1 -> V_60 . V_61 . V_233 = 0 ;
F_86 ( & V_1 -> V_60 . V_234 , 1 ) ;
V_17 = F_76 ( V_1 ) ;
if ( V_17 )
return V_17 ;
#ifdef F_87
V_17 = F_88 ( V_1 ) ;
if ( V_17 )
goto V_36;
V_17 = F_89 ( V_1 ) ;
if ( V_17 )
goto V_235;
V_17 = F_90 ( V_1 ) ;
if ( V_17 )
goto V_236;
#endif
return V_17 ;
#ifdef F_87
V_236:
F_91 ( V_1 ) ;
V_235:
F_92 ( V_1 ) ;
V_36:
F_83 ( V_1 ) ;
return V_17 ;
#endif
}
static void T_4 F_93 ( struct V_1 * V_1 )
{
#ifdef F_87
F_92 ( V_1 ) ;
F_91 ( V_1 ) ;
F_94 ( V_1 ) ;
#endif
F_83 ( V_1 ) ;
}
static int T_2 F_95 ( void )
{
struct V_163 * V_237 ;
int V_17 = 0 ;
F_96 ( sizeof( struct V_192 ) ) ;
for ( V_237 = & V_170 [ 0 ] ; V_237 < & V_170 [ V_168 ] ; ++ V_237 )
F_97 ( V_237 ) ;
if ( V_238 ) {
F_98 ( L_6 ) ;
goto V_36;
}
V_17 = F_99 ( & V_239 , 1 ) ;
if ( V_17 )
goto V_36;
V_17 = F_99 ( & V_240 , 1 ) ;
if ( V_17 )
goto V_241;
V_17 = F_99 ( & V_242 , 1 ) ;
if ( V_17 )
goto V_243;
V_17 = F_99 ( & V_244 , 1 ) ;
if ( V_17 )
goto V_245;
V_17 = F_99 ( & V_246 , 1 ) ;
if ( V_17 )
goto V_247;
V_17 = F_100 () ;
if ( V_17 )
goto V_248;
V_17 = F_101 ( & V_249 ) ;
if ( V_17 )
goto V_250;
V_17 = F_102 ( & V_251 ) ;
if ( V_17 )
goto V_252;
V_17 = F_103 () ;
if ( V_17 )
goto V_253;
V_17 = F_104 () ;
if ( V_17 )
goto V_254;
V_17 = F_105 () ;
if ( V_17 )
goto V_255;
V_17 = F_106 () ;
if ( V_17 )
goto V_256;
V_257 = & V_258 ;
V_17 = F_107 () ;
if ( V_17 )
goto V_259;
#ifdef F_87
V_17 = - V_212 ;
if ( F_108 () )
goto V_260;
if ( F_109 () )
goto V_261;
if ( F_110 () )
goto V_262;
if ( F_111 () )
goto V_263;
#endif
V_17 = F_112 () ;
if ( V_17 )
goto V_264;
V_17 = F_113 () ;
if ( V_17 )
goto V_265;
V_17 = F_114 () ;
if ( V_17 )
goto V_266;
V_17 = F_115 () ;
if ( V_17 )
goto V_267;
V_17 = F_116 () ;
if ( V_17 )
goto V_268;
V_17 = F_117 () ;
if ( V_17 )
goto V_269;
V_17 = F_118 () ;
if ( V_17 )
goto V_270;
V_17 = F_119 () ;
if ( V_17 )
goto V_271;
V_17 = F_120 () ;
if ( V_17 )
goto V_272;
V_17 = F_72 () ;
if ( V_17 )
goto V_273;
V_17 = F_121 () ;
if ( V_17 )
goto V_274;
#ifdef F_122
V_17 = F_123 () ;
if ( V_17 )
goto V_275;
#endif
V_36:
return V_17 ;
#ifdef F_122
V_275:
F_124 () ;
#endif
V_274:
F_74 () ;
V_273:
F_125 () ;
V_272:
F_126 () ;
V_271:
F_127 () ;
V_270:
F_128 () ;
V_269:
F_129 () ;
V_268:
F_130 () ;
V_267:
F_131 () ;
V_266:
F_132 () ;
V_265:
F_133 () ;
V_264:
#ifdef F_87
F_134 () ;
V_263:
F_135 () ;
V_262:
F_136 () ;
V_261:
F_137 () ;
V_260:
#endif
F_138 () ;
V_259:
F_139 () ;
V_256:
F_140 () ;
V_255:
F_141 () ;
V_254:
F_142 () ;
V_253:
F_143 ( & V_251 ) ;
V_252:
F_144 ( V_24 ) ;
F_145 ( V_24 ) ;
V_250:
F_146 () ;
V_247:
F_147 ( & V_246 ) ;
V_248:
F_147 ( & V_244 ) ;
V_245:
F_147 ( & V_242 ) ;
V_243:
F_147 ( & V_240 ) ;
V_241:
F_147 ( & V_239 ) ;
goto V_36;
}
