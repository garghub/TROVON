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
V_10 -> V_56 = V_1 -> V_57 . V_58 . V_59 ;
V_7 -> V_60 = - 1 ;
V_7 -> V_53 = 1 ;
V_7 -> V_61 = 1 ;
V_7 -> V_62 = 0 ;
V_7 -> V_63 = NULL ;
V_7 -> V_64 = 0 ;
if ( V_1 -> V_65 . V_66 )
V_7 -> V_54 = V_67 ;
else
V_7 -> V_54 = V_68 ;
F_12 ( V_10 ) ;
if ( V_7 -> V_40 ) {
V_7 -> V_69 = F_13 ( V_7 -> V_40 ) ;
V_10 -> V_70 -> V_71 ( V_10 ) ;
}
if ( V_10 -> V_70 -> V_72 ) {
V_17 = V_10 -> V_70 -> V_72 ( V_10 ) ;
if ( V_17 ) {
F_14 ( V_10 ) ;
goto V_34;
}
}
V_34:
return V_17 ;
V_23:
F_4 () ;
goto V_34;
}
int F_15 ( struct V_2 * V_3 , struct V_73 * V_74 , int V_75 )
{
struct V_76 * V_77 = (struct V_76 * ) V_74 ;
struct V_3 * V_10 = V_3 -> V_10 ;
struct V_6 * V_7 = F_10 ( V_10 ) ;
struct V_8 * V_9 = F_16 ( V_10 ) ;
struct V_1 * V_1 = F_17 ( V_10 ) ;
T_1 V_78 = 0 ;
unsigned short V_79 ;
int V_80 = 0 ;
int V_17 = 0 ;
if ( V_10 -> V_70 -> V_81 )
return V_10 -> V_70 -> V_81 ( V_10 , V_74 , V_75 ) ;
if ( V_75 < V_82 )
return - V_83 ;
if ( V_77 -> V_84 != V_85 )
return - V_86 ;
V_80 = F_18 ( & V_77 -> V_87 ) ;
if ( ( V_80 & V_88 ) && V_3 -> type == V_89 )
return - V_83 ;
V_79 = F_19 ( V_77 -> V_90 ) ;
if ( V_79 && V_79 < V_91 && ! F_6 ( V_1 -> V_26 , V_92 ) )
return - V_93 ;
F_20 ( V_10 ) ;
if ( V_10 -> V_94 != V_95 || V_7 -> V_40 ) {
V_17 = - V_83 ;
goto V_34;
}
if ( V_80 == V_96 ) {
int V_97 ;
if ( V_10 -> V_56 ) {
V_17 = - V_83 ;
goto V_34;
}
V_78 = V_77 -> V_87 . V_98 [ 3 ] ;
V_97 = F_21 ( V_1 , V_78 ) ;
if ( ! V_1 -> V_65 . V_99 &&
! ( V_7 -> V_100 || V_7 -> V_101 ) &&
V_78 != F_22 ( V_102 ) &&
V_97 != V_103 &&
V_97 != V_104 &&
V_97 != V_105 ) {
V_17 = - V_106 ;
goto V_34;
}
} else {
if ( V_80 != V_107 ) {
struct V_108 * V_109 = NULL ;
F_2 () ;
if ( F_23 ( V_80 ) ) {
if ( V_75 >= sizeof( struct V_76 ) &&
V_77 -> V_110 ) {
V_10 -> V_111 = V_77 -> V_110 ;
}
if ( ! V_10 -> V_111 ) {
V_17 = - V_83 ;
goto V_112;
}
V_109 = F_24 ( V_1 , V_10 -> V_111 ) ;
if ( ! V_109 ) {
V_17 = - V_113 ;
goto V_112;
}
}
V_78 = V_114 ;
if ( ! ( V_80 & V_88 ) ) {
if ( ! ( V_7 -> V_100 || V_7 -> V_101 ) &&
! F_25 ( V_1 , & V_77 -> V_87 ,
V_109 , 0 ) ) {
V_17 = - V_106 ;
goto V_112;
}
}
F_4 () ;
}
}
V_7 -> V_115 = V_78 ;
V_7 -> V_116 = V_78 ;
V_10 -> V_117 = V_77 -> V_87 ;
if ( ! ( V_80 & V_88 ) )
V_9 -> V_118 = V_77 -> V_87 ;
if ( ( V_79 || ! V_7 -> V_119 ) &&
V_10 -> V_70 -> V_120 ( V_10 , V_79 ) ) {
F_26 ( V_10 ) ;
V_17 = - V_121 ;
goto V_34;
}
if ( V_80 != V_107 ) {
V_10 -> V_122 |= V_123 ;
if ( V_80 != V_96 )
V_10 -> V_56 = 1 ;
}
if ( V_79 )
V_10 -> V_122 |= V_124 ;
V_7 -> V_69 = F_13 ( V_7 -> V_40 ) ;
V_7 -> V_125 = 0 ;
V_7 -> V_126 = 0 ;
V_34:
F_27 ( V_10 ) ;
return V_17 ;
V_112:
F_4 () ;
goto V_34;
}
int F_28 ( struct V_2 * V_3 )
{
struct V_3 * V_10 = V_3 -> V_10 ;
if ( ! V_10 )
return - V_83 ;
F_29 ( V_10 ) ;
F_30 ( V_10 ) ;
return F_31 ( V_3 ) ;
}
void F_32 ( struct V_3 * V_10 )
{
struct V_8 * V_9 = F_16 ( V_10 ) ;
struct V_127 * V_128 ;
struct V_129 * V_130 ;
V_128 = F_33 ( & V_9 -> V_131 , NULL ) ;
if ( V_128 )
F_34 ( V_128 ) ;
V_128 = F_33 ( & V_9 -> V_132 , NULL ) ;
if ( V_128 )
F_34 ( V_128 ) ;
F_35 ( V_10 ) ;
V_130 = F_33 ( & V_9 -> V_130 , NULL ) ;
if ( V_130 )
F_36 ( V_10 , V_130 , V_130 -> V_133 ) ;
}
int F_37 ( struct V_2 * V_3 , struct V_73 * V_74 ,
int * V_134 , int V_135 )
{
struct V_76 * sin = (struct V_76 * ) V_74 ;
struct V_3 * V_10 = V_3 -> V_10 ;
struct V_6 * V_7 = F_10 ( V_10 ) ;
struct V_8 * V_9 = F_16 ( V_10 ) ;
sin -> V_84 = V_85 ;
sin -> V_136 = 0 ;
sin -> V_110 = 0 ;
if ( V_135 ) {
if ( ! V_7 -> V_125 )
return - V_137 ;
if ( ( ( 1 << V_10 -> V_94 ) & ( V_138 | V_139 ) ) &&
V_135 == 1 )
return - V_137 ;
sin -> V_90 = V_7 -> V_125 ;
sin -> V_87 = V_10 -> V_140 ;
if ( V_9 -> V_141 )
sin -> V_136 = V_9 -> V_142 ;
} else {
if ( F_38 ( & V_10 -> V_117 ) )
sin -> V_87 = V_9 -> V_118 ;
else
sin -> V_87 = V_10 -> V_117 ;
sin -> V_90 = V_7 -> V_69 ;
}
sin -> V_110 = F_39 ( & sin -> V_87 ,
V_10 -> V_111 ) ;
* V_134 = sizeof( * sin ) ;
return 0 ;
}
int F_40 ( struct V_2 * V_3 , unsigned int V_143 , unsigned long V_144 )
{
struct V_3 * V_10 = V_3 -> V_10 ;
struct V_1 * V_1 = F_17 ( V_10 ) ;
switch ( V_143 ) {
case V_145 :
return F_41 ( V_10 , (struct V_146 V_147 * ) V_144 ) ;
case V_148 :
return F_42 ( V_10 , (struct V_149 V_147 * ) V_144 ) ;
case V_150 :
case V_151 :
return F_43 ( V_1 , V_143 , ( void V_147 * ) V_144 ) ;
case V_152 :
return F_44 ( V_1 , ( void V_147 * ) V_144 ) ;
case V_153 :
return F_45 ( V_1 , ( void V_147 * ) V_144 ) ;
case V_154 :
return F_46 ( V_1 , ( void V_147 * ) V_144 ) ;
default:
if ( ! V_10 -> V_70 -> V_155 )
return - V_156 ;
return V_10 -> V_70 -> V_155 ( V_10 , V_143 , V_144 ) ;
}
return 0 ;
}
int F_47 ( struct V_11 * V_157 )
{
struct V_158 * V_159 ;
struct V_11 * V_12 ;
struct V_158 * V_160 ;
int V_4 = V_157 -> V_4 ;
int V_161 ;
F_48 ( & V_162 ) ;
V_161 = - V_83 ;
if ( V_157 -> type >= V_163 )
goto V_164;
V_12 = NULL ;
V_161 = - V_24 ;
V_160 = & V_165 [ V_157 -> type ] ;
F_49 (lh, &inetsw6[p->type]) {
V_12 = F_50 ( V_159 , struct V_11 , V_166 ) ;
if ( V_167 & V_12 -> V_30 ) {
if ( V_4 == V_12 -> V_4 )
break;
V_160 = V_159 ;
}
V_12 = NULL ;
}
if ( V_12 )
goto V_168;
F_51 ( & V_157 -> V_166 , V_160 ) ;
V_161 = 0 ;
V_34:
F_52 ( & V_162 ) ;
return V_161 ;
V_168:
F_53 ( L_3 , V_4 ) ;
goto V_34;
V_164:
F_53 ( L_4 ,
V_157 -> type ) ;
goto V_34;
}
void
F_54 ( struct V_11 * V_157 )
{
if ( V_167 & V_157 -> V_30 ) {
F_53 ( L_5 ,
V_157 -> V_4 ) ;
} else {
F_48 ( & V_162 ) ;
F_55 ( & V_157 -> V_166 ) ;
F_52 ( & V_162 ) ;
F_56 () ;
}
}
int F_57 ( struct V_3 * V_10 )
{
struct V_8 * V_9 = F_16 ( V_10 ) ;
struct V_169 * V_170 ;
V_170 = F_58 ( V_10 , V_9 -> V_171 ) ;
if ( ! V_170 ) {
struct V_6 * V_7 = F_10 ( V_10 ) ;
struct V_172 * V_173 , V_174 ;
struct V_175 V_176 ;
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
V_176 . V_177 = V_10 -> V_46 ;
V_176 . V_178 = V_10 -> V_140 ;
V_176 . V_118 = V_9 -> V_118 ;
V_176 . V_179 = V_9 -> V_142 ;
V_176 . V_180 = V_10 -> V_111 ;
V_176 . V_181 = V_10 -> V_182 ;
V_176 . V_183 = V_7 -> V_125 ;
V_176 . V_184 = V_7 -> V_69 ;
F_59 ( V_10 , F_60 ( & V_176 ) ) ;
V_173 = F_61 ( & V_176 , V_9 -> V_130 , & V_174 ) ;
V_170 = F_62 ( V_10 , & V_176 , V_173 ) ;
if ( F_63 ( V_170 ) ) {
V_10 -> V_185 = 0 ;
V_10 -> V_186 = - F_64 ( V_170 ) ;
return F_64 ( V_170 ) ;
}
F_65 ( V_10 , V_170 , NULL , NULL ) ;
}
return 0 ;
}
bool F_66 ( const struct V_3 * V_10 , const struct V_127 * V_128 ,
const struct V_187 * V_130 )
{
const struct V_8 * V_9 = F_16 ( V_10 ) ;
if ( V_9 -> V_188 . V_189 ) {
if ( ( V_130 -> V_190 && ( V_9 -> V_188 . V_191 . V_192 ||
V_9 -> V_188 . V_191 . V_193 ) ) ||
( F_67 ( (struct V_194 * ) F_68 ( V_128 ) ) &&
V_9 -> V_188 . V_191 . V_195 ) ||
( V_130 -> V_196 && ( V_9 -> V_188 . V_191 . V_196 ||
V_9 -> V_188 . V_191 . V_197 ) ) ||
( ( V_130 -> V_198 || V_130 -> V_199 ) &&
( V_9 -> V_188 . V_191 . V_200 || V_9 -> V_188 . V_191 . V_201 ) ) )
return true ;
}
return false ;
}
static int T_2 F_69 ( void )
{
F_70 ( & V_202 ) ;
return 0 ;
}
static void F_71 ( void )
{
F_72 ( & V_202 ) ;
}
static int T_3 F_73 ( struct V_1 * V_1 )
{
int V_203 ;
V_1 -> V_204 . V_205 = F_74 ( struct V_206 ) ;
if ( ! V_1 -> V_204 . V_205 )
return - V_207 ;
V_1 -> V_204 . V_208 = F_74 ( struct V_206 ) ;
if ( ! V_1 -> V_204 . V_208 )
goto V_209;
V_1 -> V_204 . V_210 = F_74 ( struct V_211 ) ;
if ( ! V_1 -> V_204 . V_210 )
goto V_212;
F_75 (i) {
struct V_211 * V_213 ;
V_213 = F_76 ( V_1 -> V_204 . V_210 , V_203 ) ;
F_77 ( & V_213 -> V_214 ) ;
}
V_1 -> V_204 . V_215 = F_74 ( struct V_216 ) ;
if ( ! V_1 -> V_204 . V_215 )
goto V_217;
V_1 -> V_204 . V_218 = F_78 ( sizeof( struct V_219 ) ,
V_33 ) ;
if ( ! V_1 -> V_204 . V_218 )
goto V_220;
return 0 ;
V_220:
F_79 ( V_1 -> V_204 . V_215 ) ;
V_217:
F_79 ( V_1 -> V_204 . V_210 ) ;
V_212:
F_79 ( V_1 -> V_204 . V_208 ) ;
V_209:
F_79 ( V_1 -> V_204 . V_205 ) ;
return - V_207 ;
}
static void F_80 ( struct V_1 * V_1 )
{
F_79 ( V_1 -> V_204 . V_205 ) ;
F_79 ( V_1 -> V_204 . V_208 ) ;
F_79 ( V_1 -> V_204 . V_210 ) ;
F_79 ( V_1 -> V_204 . V_215 ) ;
F_81 ( V_1 -> V_204 . V_218 ) ;
}
static int T_3 F_82 ( struct V_1 * V_1 )
{
int V_17 = 0 ;
V_1 -> V_57 . V_58 . V_59 = 0 ;
V_1 -> V_57 . V_58 . V_221 = 1 * V_222 ;
V_1 -> V_57 . V_58 . V_223 = 1 ;
V_1 -> V_57 . V_58 . V_224 = 0 ;
V_1 -> V_57 . V_58 . V_225 = 3 ;
V_1 -> V_57 . V_58 . V_226 = 1 * V_222 ;
V_1 -> V_57 . V_58 . V_227 = 1 ;
F_83 ( & V_1 -> V_57 . V_228 , 1 ) ;
V_17 = F_73 ( V_1 ) ;
if ( V_17 )
return V_17 ;
#ifdef F_84
V_17 = F_85 ( V_1 ) ;
if ( V_17 )
goto V_34;
V_17 = F_86 ( V_1 ) ;
if ( V_17 )
goto V_229;
V_17 = F_87 ( V_1 ) ;
if ( V_17 )
goto V_230;
#endif
return V_17 ;
#ifdef F_84
V_230:
F_88 ( V_1 ) ;
V_229:
F_89 ( V_1 ) ;
V_34:
F_80 ( V_1 ) ;
return V_17 ;
#endif
}
static void T_4 F_90 ( struct V_1 * V_1 )
{
#ifdef F_84
F_89 ( V_1 ) ;
F_88 ( V_1 ) ;
F_91 ( V_1 ) ;
#endif
F_80 ( V_1 ) ;
}
static int T_2 F_92 ( void )
{
struct V_158 * V_231 ;
int V_17 = 0 ;
F_93 ( sizeof( struct V_187 ) ) ;
for ( V_231 = & V_165 [ 0 ] ; V_231 < & V_165 [ V_163 ] ; ++ V_231 )
F_94 ( V_231 ) ;
if ( V_232 ) {
F_95 ( L_6 ) ;
goto V_34;
}
V_17 = F_96 ( & V_233 , 1 ) ;
if ( V_17 )
goto V_34;
V_17 = F_96 ( & V_234 , 1 ) ;
if ( V_17 )
goto V_235;
V_17 = F_96 ( & V_236 , 1 ) ;
if ( V_17 )
goto V_237;
V_17 = F_96 ( & V_238 , 1 ) ;
if ( V_17 )
goto V_239;
V_17 = F_96 ( & V_240 , 1 ) ;
if ( V_17 )
goto V_241;
V_17 = F_97 () ;
if ( V_17 )
goto V_242;
V_17 = F_98 ( & V_243 ) ;
if ( V_17 )
goto V_244;
V_17 = F_99 ( & V_245 ) ;
if ( V_17 )
goto V_246;
V_17 = F_100 () ;
if ( V_17 )
goto V_247;
V_17 = F_101 () ;
if ( V_17 )
goto V_248;
V_17 = F_102 () ;
if ( V_17 )
goto V_249;
V_17 = F_103 () ;
if ( V_17 )
goto V_250;
V_251 = & V_252 ;
V_17 = F_104 () ;
if ( V_17 )
goto V_253;
#ifdef F_84
V_17 = - V_207 ;
if ( F_105 () )
goto V_254;
if ( F_106 () )
goto V_255;
if ( F_107 () )
goto V_256;
if ( F_108 () )
goto V_257;
#endif
V_17 = F_109 () ;
if ( V_17 )
goto V_258;
V_17 = F_110 () ;
if ( V_17 )
goto V_259;
V_17 = F_111 () ;
if ( V_17 )
goto V_260;
V_17 = F_112 () ;
if ( V_17 )
goto V_261;
V_17 = F_113 () ;
if ( V_17 )
goto V_262;
V_17 = F_114 () ;
if ( V_17 )
goto V_263;
V_17 = F_115 () ;
if ( V_17 )
goto V_264;
V_17 = F_116 () ;
if ( V_17 )
goto V_265;
V_17 = F_117 () ;
if ( V_17 )
goto V_266;
V_17 = F_69 () ;
if ( V_17 )
goto V_267;
V_17 = F_118 () ;
if ( V_17 )
goto V_268;
#ifdef F_119
V_17 = F_120 () ;
if ( V_17 )
goto V_269;
#endif
V_34:
return V_17 ;
#ifdef F_119
V_269:
F_121 () ;
#endif
V_268:
F_71 () ;
V_267:
F_122 () ;
V_266:
F_123 () ;
V_265:
F_124 () ;
V_264:
F_125 () ;
V_263:
F_126 () ;
V_262:
F_127 () ;
V_261:
F_128 () ;
V_260:
F_129 () ;
V_259:
F_130 () ;
V_258:
#ifdef F_84
F_131 () ;
V_257:
F_132 () ;
V_256:
F_133 () ;
V_255:
F_134 () ;
V_254:
#endif
F_135 () ;
V_253:
F_136 () ;
V_250:
F_137 () ;
V_249:
F_138 () ;
V_248:
F_139 () ;
V_247:
F_140 ( & V_245 ) ;
V_246:
F_141 ( V_22 ) ;
F_142 ( V_22 ) ;
V_244:
F_143 () ;
V_241:
F_144 ( & V_240 ) ;
V_242:
F_144 ( & V_238 ) ;
V_239:
F_144 ( & V_236 ) ;
V_237:
F_144 ( & V_234 ) ;
V_235:
F_144 ( & V_233 ) ;
goto V_34;
}
