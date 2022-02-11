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
V_18:
V_17 = - V_19 ;
F_2 () ;
F_3 (answer, &inetsw6[sock->type], list) {
V_17 = 0 ;
if ( V_4 == V_12 -> V_4 ) {
if ( V_4 != V_20 )
break;
} else {
if ( V_20 == V_4 ) {
V_4 = V_12 -> V_4 ;
break;
}
if ( V_20 == V_12 -> V_4 )
break;
}
V_17 = - V_21 ;
}
if ( V_17 ) {
if ( V_16 < 2 ) {
F_4 () ;
if ( ++ V_16 == 1 )
F_5 ( L_1 ,
V_22 , V_4 , V_3 -> type ) ;
else
F_5 ( L_2 ,
V_22 , V_4 ) ;
goto V_18;
} else
goto V_23;
}
V_17 = - V_24 ;
if ( V_3 -> type == V_25 && ! V_5 &&
! F_6 ( V_1 -> V_26 , V_27 ) )
goto V_23;
V_3 -> V_28 = V_12 -> V_28 ;
V_14 = V_12 -> V_29 ;
V_15 = V_12 -> V_30 ;
F_4 () ;
F_7 ( ! V_14 -> V_31 ) ;
V_17 = - V_32 ;
V_10 = F_8 ( V_1 , V_22 , V_33 , V_14 , V_5 ) ;
if ( ! V_10 )
goto V_34;
F_9 ( V_3 , V_10 ) ;
V_17 = 0 ;
if ( V_35 & V_15 )
V_10 -> V_36 = V_37 ;
V_7 = F_10 ( V_10 ) ;
V_7 -> V_38 = ( V_39 & V_15 ) != 0 ;
if ( V_25 == V_3 -> type ) {
V_7 -> V_40 = V_4 ;
if ( V_41 == V_4 )
V_7 -> V_42 = 1 ;
}
V_10 -> V_43 = V_44 ;
V_10 -> V_45 = V_22 ;
V_10 -> V_46 = V_4 ;
V_10 -> V_47 = V_12 -> V_29 -> V_48 ;
F_10 ( V_10 ) -> V_49 = V_9 = F_11 ( V_10 ) ;
V_9 -> V_50 = - 1 ;
V_9 -> V_51 = V_52 ;
V_9 -> V_53 = 1 ;
V_9 -> V_54 = V_55 ;
V_9 -> V_56 = F_12 ( F_13 ( V_10 ) ) ;
V_10 -> V_57 = V_1 -> V_58 . V_59 . V_60 ;
V_7 -> V_61 = - 1 ;
V_7 -> V_53 = 1 ;
V_7 -> V_62 = 1 ;
V_7 -> V_63 = 0 ;
V_7 -> V_64 = NULL ;
V_7 -> V_65 = 0 ;
if ( V_1 -> V_66 . V_67 )
V_7 -> V_54 = V_68 ;
else
V_7 -> V_54 = V_69 ;
F_14 ( V_10 ) ;
if ( V_7 -> V_40 ) {
V_7 -> V_70 = F_15 ( V_7 -> V_40 ) ;
V_10 -> V_71 -> V_72 ( V_10 ) ;
}
if ( V_10 -> V_71 -> V_73 ) {
V_17 = V_10 -> V_71 -> V_73 ( V_10 ) ;
if ( V_17 ) {
F_16 ( V_10 ) ;
goto V_34;
}
}
V_34:
return V_17 ;
V_23:
F_4 () ;
goto V_34;
}
int F_17 ( struct V_2 * V_3 , struct V_74 * V_75 , int V_76 )
{
struct V_77 * V_78 = (struct V_77 * ) V_75 ;
struct V_3 * V_10 = V_3 -> V_10 ;
struct V_6 * V_7 = F_10 ( V_10 ) ;
struct V_8 * V_9 = F_18 ( V_10 ) ;
struct V_1 * V_1 = F_13 ( V_10 ) ;
T_1 V_79 = 0 ;
unsigned short V_80 ;
int V_81 = 0 ;
int V_17 = 0 ;
if ( V_10 -> V_71 -> V_82 )
return V_10 -> V_71 -> V_82 ( V_10 , V_75 , V_76 ) ;
if ( V_76 < V_83 )
return - V_84 ;
if ( V_78 -> V_85 != V_86 )
return - V_87 ;
V_81 = F_19 ( & V_78 -> V_88 ) ;
if ( ( V_81 & V_89 ) && V_3 -> type == V_90 )
return - V_84 ;
V_80 = F_20 ( V_78 -> V_91 ) ;
if ( V_80 && V_80 < V_92 && ! F_6 ( V_1 -> V_26 , V_93 ) )
return - V_94 ;
F_21 ( V_10 ) ;
if ( V_10 -> V_95 != V_96 || V_7 -> V_40 ) {
V_17 = - V_84 ;
goto V_34;
}
if ( V_81 == V_97 ) {
int V_98 ;
if ( V_10 -> V_57 ) {
V_17 = - V_84 ;
goto V_34;
}
V_79 = V_78 -> V_88 . V_99 [ 3 ] ;
V_98 = F_22 ( V_1 , V_79 ) ;
if ( ! V_1 -> V_66 . V_100 &&
! ( V_7 -> V_101 || V_7 -> V_102 ) &&
V_79 != F_23 ( V_103 ) &&
V_98 != V_104 &&
V_98 != V_105 &&
V_98 != V_106 ) {
V_17 = - V_107 ;
goto V_34;
}
} else {
if ( V_81 != V_108 ) {
struct V_109 * V_110 = NULL ;
F_2 () ;
if ( F_24 ( V_81 ) ) {
if ( V_76 >= sizeof( struct V_77 ) &&
V_78 -> V_111 ) {
V_10 -> V_112 = V_78 -> V_111 ;
}
if ( ! V_10 -> V_112 ) {
V_17 = - V_84 ;
goto V_113;
}
V_110 = F_25 ( V_1 , V_10 -> V_112 ) ;
if ( ! V_110 ) {
V_17 = - V_114 ;
goto V_113;
}
}
V_79 = V_115 ;
if ( ! ( V_81 & V_89 ) ) {
if ( ! V_1 -> V_58 . V_59 . V_116 &&
! ( V_7 -> V_101 || V_7 -> V_102 ) &&
! F_26 ( V_1 , & V_78 -> V_88 ,
V_110 , 0 ) ) {
V_17 = - V_107 ;
goto V_113;
}
}
F_4 () ;
}
}
V_7 -> V_117 = V_79 ;
V_7 -> V_118 = V_79 ;
V_10 -> V_119 = V_78 -> V_88 ;
if ( ! ( V_81 & V_89 ) )
V_9 -> V_120 = V_78 -> V_88 ;
if ( ( V_80 || ! V_7 -> V_121 ) &&
V_10 -> V_71 -> V_122 ( V_10 , V_80 ) ) {
F_27 ( V_10 ) ;
V_17 = - V_123 ;
goto V_34;
}
if ( V_81 != V_108 ) {
V_10 -> V_124 |= V_125 ;
if ( V_81 != V_97 )
V_10 -> V_57 = 1 ;
}
if ( V_80 )
V_10 -> V_124 |= V_126 ;
V_7 -> V_70 = F_15 ( V_7 -> V_40 ) ;
V_7 -> V_127 = 0 ;
V_7 -> V_128 = 0 ;
V_34:
F_28 ( V_10 ) ;
return V_17 ;
V_113:
F_4 () ;
goto V_34;
}
int F_29 ( struct V_2 * V_3 )
{
struct V_3 * V_10 = V_3 -> V_10 ;
if ( ! V_10 )
return - V_84 ;
F_30 ( V_10 ) ;
F_31 ( V_10 ) ;
return F_32 ( V_3 ) ;
}
void F_33 ( struct V_3 * V_10 )
{
struct V_8 * V_9 = F_18 ( V_10 ) ;
struct V_129 * V_130 ;
struct V_131 * V_132 ;
V_130 = F_34 ( & V_9 -> V_133 , NULL ) ;
if ( V_130 )
F_35 ( V_130 ) ;
V_130 = F_34 ( & V_9 -> V_134 , NULL ) ;
if ( V_130 )
F_35 ( V_130 ) ;
F_36 ( V_10 ) ;
V_132 = F_34 ( & V_9 -> V_132 , NULL ) ;
if ( V_132 )
F_37 ( V_10 , V_132 , V_132 -> V_135 ) ;
}
int F_38 ( struct V_2 * V_3 , struct V_74 * V_75 ,
int * V_136 , int V_137 )
{
struct V_77 * sin = (struct V_77 * ) V_75 ;
struct V_3 * V_10 = V_3 -> V_10 ;
struct V_6 * V_7 = F_10 ( V_10 ) ;
struct V_8 * V_9 = F_18 ( V_10 ) ;
sin -> V_85 = V_86 ;
sin -> V_138 = 0 ;
sin -> V_111 = 0 ;
if ( V_137 ) {
if ( ! V_7 -> V_127 )
return - V_139 ;
if ( ( ( 1 << V_10 -> V_95 ) & ( V_140 | V_141 ) ) &&
V_137 == 1 )
return - V_139 ;
sin -> V_91 = V_7 -> V_127 ;
sin -> V_88 = V_10 -> V_142 ;
if ( V_9 -> V_143 )
sin -> V_138 = V_9 -> V_144 ;
} else {
if ( F_39 ( & V_10 -> V_119 ) )
sin -> V_88 = V_9 -> V_120 ;
else
sin -> V_88 = V_10 -> V_119 ;
sin -> V_91 = V_7 -> V_70 ;
}
sin -> V_111 = F_40 ( & sin -> V_88 ,
V_10 -> V_112 ) ;
* V_136 = sizeof( * sin ) ;
return 0 ;
}
int F_41 ( struct V_2 * V_3 , unsigned int V_145 , unsigned long V_146 )
{
struct V_3 * V_10 = V_3 -> V_10 ;
struct V_1 * V_1 = F_13 ( V_10 ) ;
switch ( V_145 ) {
case V_147 :
return F_42 ( V_10 , (struct V_148 V_149 * ) V_146 ) ;
case V_150 :
return F_43 ( V_10 , (struct V_151 V_149 * ) V_146 ) ;
case V_152 :
case V_153 :
return F_44 ( V_1 , V_145 , ( void V_149 * ) V_146 ) ;
case V_154 :
return F_45 ( V_1 , ( void V_149 * ) V_146 ) ;
case V_155 :
return F_46 ( V_1 , ( void V_149 * ) V_146 ) ;
case V_156 :
return F_47 ( V_1 , ( void V_149 * ) V_146 ) ;
default:
if ( ! V_10 -> V_71 -> V_157 )
return - V_158 ;
return V_10 -> V_71 -> V_157 ( V_10 , V_145 , V_146 ) ;
}
return 0 ;
}
int F_48 ( struct V_11 * V_159 )
{
struct V_160 * V_161 ;
struct V_11 * V_12 ;
struct V_160 * V_162 ;
int V_4 = V_159 -> V_4 ;
int V_163 ;
F_49 ( & V_164 ) ;
V_163 = - V_84 ;
if ( V_159 -> type >= V_165 )
goto V_166;
V_12 = NULL ;
V_163 = - V_24 ;
V_162 = & V_167 [ V_159 -> type ] ;
F_50 (lh, &inetsw6[p->type]) {
V_12 = F_51 ( V_161 , struct V_11 , V_168 ) ;
if ( V_169 & V_12 -> V_30 ) {
if ( V_4 == V_12 -> V_4 )
break;
V_162 = V_161 ;
}
V_12 = NULL ;
}
if ( V_12 )
goto V_170;
F_52 ( & V_159 -> V_168 , V_162 ) ;
V_163 = 0 ;
V_34:
F_53 ( & V_164 ) ;
return V_163 ;
V_170:
F_54 ( L_3 , V_4 ) ;
goto V_34;
V_166:
F_54 ( L_4 ,
V_159 -> type ) ;
goto V_34;
}
void
F_55 ( struct V_11 * V_159 )
{
if ( V_169 & V_159 -> V_30 ) {
F_54 ( L_5 ,
V_159 -> V_4 ) ;
} else {
F_49 ( & V_164 ) ;
F_56 ( & V_159 -> V_168 ) ;
F_53 ( & V_164 ) ;
F_57 () ;
}
}
int F_58 ( struct V_3 * V_10 )
{
struct V_8 * V_9 = F_18 ( V_10 ) ;
struct V_171 * V_172 ;
V_172 = F_59 ( V_10 , V_9 -> V_173 ) ;
if ( ! V_172 ) {
struct V_6 * V_7 = F_10 ( V_10 ) ;
struct V_174 * V_175 , V_176 ;
struct V_177 V_178 ;
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
V_178 . V_179 = V_10 -> V_46 ;
V_178 . V_180 = V_10 -> V_142 ;
V_178 . V_120 = V_9 -> V_120 ;
V_178 . V_181 = V_9 -> V_144 ;
V_178 . V_182 = V_10 -> V_112 ;
V_178 . V_183 = V_10 -> V_184 ;
V_178 . V_185 = V_7 -> V_127 ;
V_178 . V_186 = V_7 -> V_70 ;
F_60 ( V_10 , F_61 ( & V_178 ) ) ;
V_175 = F_62 ( & V_178 , V_9 -> V_132 , & V_176 ) ;
V_172 = F_63 ( V_10 , & V_178 , V_175 ) ;
if ( F_64 ( V_172 ) ) {
V_10 -> V_187 = 0 ;
V_10 -> V_188 = - F_65 ( V_172 ) ;
return F_65 ( V_172 ) ;
}
F_66 ( V_10 , V_172 , NULL , NULL ) ;
}
return 0 ;
}
bool F_67 ( const struct V_3 * V_10 , const struct V_129 * V_130 ,
const struct V_189 * V_132 )
{
const struct V_8 * V_9 = F_18 ( V_10 ) ;
if ( V_9 -> V_190 . V_191 ) {
if ( ( ( V_132 -> V_30 & V_192 ) &&
( V_9 -> V_190 . V_193 . V_194 || V_9 -> V_190 . V_193 . V_195 ) ) ||
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
V_1 -> V_206 . V_207 = F_75 ( struct V_208 ) ;
if ( ! V_1 -> V_206 . V_207 )
return - V_209 ;
V_1 -> V_206 . V_210 = F_75 ( struct V_208 ) ;
if ( ! V_1 -> V_206 . V_210 )
goto V_211;
V_1 -> V_206 . V_212 = F_75 ( struct V_213 ) ;
if ( ! V_1 -> V_206 . V_212 )
goto V_214;
F_76 (i) {
struct V_213 * V_215 ;
V_215 = F_77 ( V_1 -> V_206 . V_212 , V_205 ) ;
F_78 ( & V_215 -> V_216 ) ;
}
V_1 -> V_206 . V_217 = F_75 ( struct V_218 ) ;
if ( ! V_1 -> V_206 . V_217 )
goto V_219;
V_1 -> V_206 . V_220 = F_79 ( sizeof( struct V_221 ) ,
V_33 ) ;
if ( ! V_1 -> V_206 . V_220 )
goto V_222;
return 0 ;
V_222:
F_80 ( V_1 -> V_206 . V_217 ) ;
V_219:
F_80 ( V_1 -> V_206 . V_212 ) ;
V_214:
F_80 ( V_1 -> V_206 . V_210 ) ;
V_211:
F_80 ( V_1 -> V_206 . V_207 ) ;
return - V_209 ;
}
static void F_81 ( struct V_1 * V_1 )
{
F_80 ( V_1 -> V_206 . V_207 ) ;
F_80 ( V_1 -> V_206 . V_210 ) ;
F_80 ( V_1 -> V_206 . V_212 ) ;
F_80 ( V_1 -> V_206 . V_217 ) ;
F_82 ( V_1 -> V_206 . V_220 ) ;
}
static int T_3 F_83 ( struct V_1 * V_1 )
{
int V_17 = 0 ;
V_1 -> V_58 . V_59 . V_60 = 0 ;
V_1 -> V_58 . V_59 . V_223 = 1 * V_224 ;
V_1 -> V_58 . V_59 . V_225 = 1 ;
V_1 -> V_58 . V_59 . V_226 = V_227 ;
V_1 -> V_58 . V_59 . V_228 = 3 ;
V_1 -> V_58 . V_59 . V_229 = 1 * V_224 ;
V_1 -> V_58 . V_59 . V_230 = 0 ;
F_84 ( & V_1 -> V_58 . V_231 , 1 ) ;
V_17 = F_74 ( V_1 ) ;
if ( V_17 )
return V_17 ;
#ifdef F_85
V_17 = F_86 ( V_1 ) ;
if ( V_17 )
goto V_34;
V_17 = F_87 ( V_1 ) ;
if ( V_17 )
goto V_232;
V_17 = F_88 ( V_1 ) ;
if ( V_17 )
goto V_233;
#endif
return V_17 ;
#ifdef F_85
V_233:
F_89 ( V_1 ) ;
V_232:
F_90 ( V_1 ) ;
V_34:
F_81 ( V_1 ) ;
return V_17 ;
#endif
}
static void T_4 F_91 ( struct V_1 * V_1 )
{
#ifdef F_85
F_90 ( V_1 ) ;
F_89 ( V_1 ) ;
F_92 ( V_1 ) ;
#endif
F_81 ( V_1 ) ;
}
static int T_2 F_93 ( void )
{
struct V_160 * V_234 ;
int V_17 = 0 ;
F_94 ( sizeof( struct V_189 ) ) ;
for ( V_234 = & V_167 [ 0 ] ; V_234 < & V_167 [ V_165 ] ; ++ V_234 )
F_95 ( V_234 ) ;
if ( V_235 ) {
F_96 ( L_6 ) ;
goto V_34;
}
V_17 = F_97 ( & V_236 , 1 ) ;
if ( V_17 )
goto V_34;
V_17 = F_97 ( & V_237 , 1 ) ;
if ( V_17 )
goto V_238;
V_17 = F_97 ( & V_239 , 1 ) ;
if ( V_17 )
goto V_240;
V_17 = F_97 ( & V_241 , 1 ) ;
if ( V_17 )
goto V_242;
V_17 = F_97 ( & V_243 , 1 ) ;
if ( V_17 )
goto V_244;
V_17 = F_98 () ;
if ( V_17 )
goto V_245;
V_17 = F_99 ( & V_246 ) ;
if ( V_17 )
goto V_247;
V_17 = F_100 ( & V_248 ) ;
if ( V_17 )
goto V_249;
V_17 = F_101 () ;
if ( V_17 )
goto V_250;
V_17 = F_102 () ;
if ( V_17 )
goto V_251;
V_17 = F_103 () ;
if ( V_17 )
goto V_252;
V_17 = F_104 () ;
if ( V_17 )
goto V_253;
V_254 = & V_255 ;
V_17 = F_105 () ;
if ( V_17 )
goto V_256;
#ifdef F_85
V_17 = - V_209 ;
if ( F_106 () )
goto V_257;
if ( F_107 () )
goto V_258;
if ( F_108 () )
goto V_259;
if ( F_109 () )
goto V_260;
#endif
V_17 = F_110 () ;
if ( V_17 )
goto V_261;
V_17 = F_111 () ;
if ( V_17 )
goto V_262;
V_17 = F_112 () ;
if ( V_17 )
goto V_263;
V_17 = F_113 () ;
if ( V_17 )
goto V_264;
V_17 = F_114 () ;
if ( V_17 )
goto V_265;
V_17 = F_115 () ;
if ( V_17 )
goto V_266;
V_17 = F_116 () ;
if ( V_17 )
goto V_267;
V_17 = F_117 () ;
if ( V_17 )
goto V_268;
V_17 = F_118 () ;
if ( V_17 )
goto V_269;
V_17 = F_70 () ;
if ( V_17 )
goto V_270;
V_17 = F_119 () ;
if ( V_17 )
goto V_271;
#ifdef F_120
V_17 = F_121 () ;
if ( V_17 )
goto V_272;
#endif
V_34:
return V_17 ;
#ifdef F_120
V_272:
F_122 () ;
#endif
V_271:
F_72 () ;
V_270:
F_123 () ;
V_269:
F_124 () ;
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
#ifdef F_85
F_132 () ;
V_260:
F_133 () ;
V_259:
F_134 () ;
V_258:
F_135 () ;
V_257:
#endif
F_136 () ;
V_256:
F_137 () ;
V_253:
F_138 () ;
V_252:
F_139 () ;
V_251:
F_140 () ;
V_250:
F_141 ( & V_248 ) ;
V_249:
F_142 ( V_22 ) ;
F_143 ( V_22 ) ;
V_247:
F_144 () ;
V_244:
F_145 ( & V_243 ) ;
V_245:
F_145 ( & V_241 ) ;
V_242:
F_145 ( & V_239 ) ;
V_240:
F_145 ( & V_237 ) ;
V_238:
F_145 ( & V_236 ) ;
goto V_34;
}
