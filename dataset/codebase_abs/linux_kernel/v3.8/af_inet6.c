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
if ( V_3 -> type != V_19 &&
V_3 -> type != V_20 &&
! V_21 )
F_2 () ;
V_22:
V_18 = - V_23 ;
F_3 () ;
F_4 (answer, &inetsw6[sock->type], list) {
V_18 = 0 ;
if ( V_4 == V_12 -> V_4 ) {
if ( V_4 != V_24 )
break;
} else {
if ( V_24 == V_4 ) {
V_4 = V_12 -> V_4 ;
break;
}
if ( V_24 == V_12 -> V_4 )
break;
}
V_18 = - V_25 ;
}
if ( V_18 ) {
if ( V_17 < 2 ) {
F_5 () ;
if ( ++ V_17 == 1 )
F_6 ( L_1 ,
V_26 , V_4 , V_3 -> type ) ;
else
F_6 ( L_2 ,
V_26 , V_4 ) ;
goto V_22;
} else
goto V_27;
}
V_18 = - V_28 ;
if ( V_3 -> type == V_19 && ! V_5 &&
! F_7 ( V_1 -> V_29 , V_30 ) )
goto V_27;
V_3 -> V_31 = V_12 -> V_31 ;
V_14 = V_12 -> V_32 ;
V_16 = V_12 -> V_33 ;
V_15 = V_12 -> V_34 ;
F_5 () ;
F_8 ( V_14 -> V_35 == NULL ) ;
V_18 = - V_36 ;
V_10 = F_9 ( V_1 , V_26 , V_37 , V_14 ) ;
if ( V_10 == NULL )
goto V_38;
F_10 ( V_3 , V_10 ) ;
V_18 = 0 ;
V_10 -> V_39 = V_16 ;
if ( V_40 & V_15 )
V_10 -> V_41 = V_42 ;
V_7 = F_11 ( V_10 ) ;
V_7 -> V_43 = ( V_44 & V_15 ) != 0 ;
if ( V_19 == V_3 -> type ) {
V_7 -> V_45 = V_4 ;
if ( V_46 == V_4 )
V_7 -> V_47 = 1 ;
}
V_10 -> V_48 = V_49 ;
V_10 -> V_50 = V_26 ;
V_10 -> V_51 = V_4 ;
V_10 -> V_52 = V_12 -> V_32 -> V_53 ;
F_11 ( V_10 ) -> V_54 = V_9 = F_12 ( V_10 ) ;
V_9 -> V_55 = - 1 ;
V_9 -> V_56 = V_57 ;
V_9 -> V_58 = 1 ;
V_9 -> V_59 = V_60 ;
V_9 -> V_61 = V_1 -> V_62 . V_63 . V_64 ;
V_7 -> V_65 = - 1 ;
V_7 -> V_58 = 1 ;
V_7 -> V_66 = 1 ;
V_7 -> V_67 = 0 ;
V_7 -> V_68 = NULL ;
V_7 -> V_69 = 0 ;
if ( V_70 . V_71 )
V_7 -> V_59 = V_72 ;
else
V_7 -> V_59 = V_73 ;
F_13 ( V_10 ) ;
if ( V_7 -> V_45 ) {
V_7 -> V_74 = F_14 ( V_7 -> V_45 ) ;
V_10 -> V_75 -> V_76 ( V_10 ) ;
}
if ( V_10 -> V_75 -> V_77 ) {
V_18 = V_10 -> V_75 -> V_77 ( V_10 ) ;
if ( V_18 ) {
F_15 ( V_10 ) ;
goto V_38;
}
}
V_38:
return V_18 ;
V_27:
F_5 () ;
goto V_38;
}
int F_16 ( struct V_2 * V_3 , struct V_78 * V_79 , int V_80 )
{
struct V_81 * V_82 = (struct V_81 * ) V_79 ;
struct V_3 * V_10 = V_3 -> V_10 ;
struct V_6 * V_7 = F_11 ( V_10 ) ;
struct V_8 * V_9 = F_17 ( V_10 ) ;
struct V_1 * V_1 = F_18 ( V_10 ) ;
T_1 V_83 = 0 ;
unsigned short V_84 ;
int V_85 = 0 ;
int V_18 = 0 ;
if ( V_10 -> V_75 -> V_86 )
return V_10 -> V_75 -> V_86 ( V_10 , V_79 , V_80 ) ;
if ( V_80 < V_87 )
return - V_88 ;
if ( V_82 -> V_89 != V_90 )
return - V_91 ;
V_85 = F_19 ( & V_82 -> V_92 ) ;
if ( ( V_85 & V_93 ) && V_3 -> type == V_94 )
return - V_88 ;
V_84 = F_20 ( V_82 -> V_95 ) ;
if ( V_84 && V_84 < V_96 && ! F_7 ( V_1 -> V_29 , V_97 ) )
return - V_98 ;
F_21 ( V_10 ) ;
if ( V_10 -> V_99 != V_100 || V_7 -> V_45 ) {
V_18 = - V_88 ;
goto V_38;
}
if ( V_85 == V_101 ) {
int V_102 ;
if ( V_9 -> V_61 ) {
V_18 = - V_88 ;
goto V_38;
}
V_83 = V_82 -> V_92 . V_103 [ 3 ] ;
V_102 = F_22 ( V_1 , V_83 ) ;
if ( ! V_104 &&
! ( V_7 -> V_105 || V_7 -> V_106 ) &&
V_83 != F_23 ( V_107 ) &&
V_102 != V_108 &&
V_102 != V_109 &&
V_102 != V_110 ) {
V_18 = - V_111 ;
goto V_38;
}
} else {
if ( V_85 != V_112 ) {
struct V_113 * V_114 = NULL ;
F_3 () ;
if ( V_85 & V_115 ) {
if ( V_80 >= sizeof( struct V_81 ) &&
V_82 -> V_116 ) {
V_10 -> V_117 = V_82 -> V_116 ;
}
if ( ! V_10 -> V_117 ) {
V_18 = - V_88 ;
goto V_118;
}
V_114 = F_24 ( V_1 , V_10 -> V_117 ) ;
if ( ! V_114 ) {
V_18 = - V_119 ;
goto V_118;
}
}
V_83 = V_120 ;
if ( ! ( V_85 & V_93 ) ) {
if ( ! ( V_7 -> V_105 || V_7 -> V_106 ) &&
! F_25 ( V_1 , & V_82 -> V_92 ,
V_114 , 0 ) ) {
V_18 = - V_111 ;
goto V_118;
}
}
F_5 () ;
}
}
V_7 -> V_121 = V_83 ;
V_7 -> V_122 = V_83 ;
V_9 -> V_123 = V_82 -> V_92 ;
if ( ! ( V_85 & V_93 ) )
V_9 -> V_124 = V_82 -> V_92 ;
if ( V_10 -> V_75 -> V_125 ( V_10 , V_84 ) ) {
F_26 ( V_10 ) ;
V_18 = - V_126 ;
goto V_38;
}
if ( V_85 != V_112 ) {
V_10 -> V_127 |= V_128 ;
if ( V_85 != V_101 )
V_9 -> V_61 = 1 ;
}
if ( V_84 )
V_10 -> V_127 |= V_129 ;
V_7 -> V_74 = F_14 ( V_7 -> V_45 ) ;
V_7 -> V_130 = 0 ;
V_7 -> V_131 = 0 ;
V_38:
F_27 ( V_10 ) ;
return V_18 ;
V_118:
F_5 () ;
goto V_38;
}
int F_28 ( struct V_2 * V_3 )
{
struct V_3 * V_10 = V_3 -> V_10 ;
if ( V_10 == NULL )
return - V_88 ;
F_29 ( V_10 ) ;
F_30 ( V_10 ) ;
return F_31 ( V_3 ) ;
}
void F_32 ( struct V_3 * V_10 )
{
struct V_8 * V_9 = F_17 ( V_10 ) ;
struct V_132 * V_133 ;
struct V_134 * V_135 ;
V_133 = F_33 ( & V_9 -> V_136 , NULL ) ;
if ( V_133 != NULL )
F_34 ( V_133 ) ;
V_133 = F_33 ( & V_9 -> V_137 , NULL ) ;
if ( V_133 != NULL )
F_34 ( V_133 ) ;
F_35 ( V_10 ) ;
V_135 = F_33 ( & V_9 -> V_135 , NULL ) ;
if ( V_135 != NULL )
F_36 ( V_10 , V_135 , V_135 -> V_138 ) ;
}
int F_37 ( struct V_2 * V_3 , struct V_78 * V_79 ,
int * V_139 , int V_140 )
{
struct V_81 * sin = (struct V_81 * ) V_79 ;
struct V_3 * V_10 = V_3 -> V_10 ;
struct V_6 * V_7 = F_11 ( V_10 ) ;
struct V_8 * V_9 = F_17 ( V_10 ) ;
sin -> V_89 = V_90 ;
sin -> V_141 = 0 ;
sin -> V_116 = 0 ;
if ( V_140 ) {
if ( ! V_7 -> V_130 )
return - V_142 ;
if ( ( ( 1 << V_10 -> V_99 ) & ( V_143 | V_144 ) ) &&
V_140 == 1 )
return - V_142 ;
sin -> V_95 = V_7 -> V_130 ;
sin -> V_92 = V_9 -> V_145 ;
if ( V_9 -> V_146 )
sin -> V_141 = V_9 -> V_147 ;
} else {
if ( F_38 ( & V_9 -> V_123 ) )
sin -> V_92 = V_9 -> V_124 ;
else
sin -> V_92 = V_9 -> V_123 ;
sin -> V_95 = V_7 -> V_74 ;
}
if ( F_19 ( & sin -> V_92 ) & V_115 )
sin -> V_116 = V_10 -> V_117 ;
* V_139 = sizeof( * sin ) ;
return 0 ;
}
int F_39 ( struct V_2 * V_3 , unsigned int V_148 , unsigned long V_149 )
{
struct V_3 * V_10 = V_3 -> V_10 ;
struct V_1 * V_1 = F_18 ( V_10 ) ;
switch ( V_148 ) {
case V_150 :
return F_40 ( V_10 , (struct V_151 V_152 * ) V_149 ) ;
case V_153 :
return F_41 ( V_10 , (struct V_154 V_152 * ) V_149 ) ;
case V_155 :
case V_156 :
return F_42 ( V_1 , V_148 , ( void V_152 * ) V_149 ) ;
case V_157 :
return F_43 ( V_1 , ( void V_152 * ) V_149 ) ;
case V_158 :
return F_44 ( V_1 , ( void V_152 * ) V_149 ) ;
case V_159 :
return F_45 ( V_1 , ( void V_152 * ) V_149 ) ;
default:
if ( ! V_10 -> V_75 -> V_160 )
return - V_161 ;
return V_10 -> V_75 -> V_160 ( V_10 , V_148 , V_149 ) ;
}
return 0 ;
}
int F_46 ( struct V_11 * V_162 )
{
struct V_163 * V_164 ;
struct V_11 * V_12 ;
struct V_163 * V_165 ;
int V_4 = V_162 -> V_4 ;
int V_166 ;
F_47 ( & V_167 ) ;
V_166 = - V_88 ;
if ( V_162 -> type >= V_168 )
goto V_169;
V_12 = NULL ;
V_166 = - V_28 ;
V_165 = & V_170 [ V_162 -> type ] ;
F_48 (lh, &inetsw6[p->type]) {
V_12 = F_49 ( V_164 , struct V_11 , V_171 ) ;
if ( V_172 & V_12 -> V_34 ) {
if ( V_4 == V_12 -> V_4 )
break;
V_165 = V_164 ;
}
V_12 = NULL ;
}
if ( V_12 )
goto V_173;
F_50 ( & V_162 -> V_171 , V_165 ) ;
V_166 = 0 ;
V_38:
F_51 ( & V_167 ) ;
return V_166 ;
V_173:
F_52 ( L_3 , V_4 ) ;
goto V_38;
V_169:
F_52 ( L_4 ,
V_162 -> type ) ;
goto V_38;
}
void
F_53 ( struct V_11 * V_162 )
{
if ( V_172 & V_162 -> V_34 ) {
F_52 ( L_5 ,
V_162 -> V_4 ) ;
} else {
F_47 ( & V_167 ) ;
F_54 ( & V_162 -> V_171 ) ;
F_51 ( & V_167 ) ;
F_55 () ;
}
}
int F_56 ( struct V_3 * V_10 )
{
struct V_8 * V_9 = F_17 ( V_10 ) ;
struct V_174 * V_175 ;
V_175 = F_57 ( V_10 , V_9 -> V_176 ) ;
if ( V_175 == NULL ) {
struct V_6 * V_7 = F_11 ( V_10 ) ;
struct V_177 * V_178 , V_179 ;
struct V_180 V_181 ;
memset ( & V_181 , 0 , sizeof( V_181 ) ) ;
V_181 . V_182 = V_10 -> V_51 ;
V_181 . V_145 = V_9 -> V_145 ;
V_181 . V_124 = V_9 -> V_124 ;
V_181 . V_183 = V_9 -> V_147 ;
V_181 . V_184 = V_10 -> V_117 ;
V_181 . V_185 = V_10 -> V_186 ;
V_181 . V_187 = V_7 -> V_130 ;
V_181 . V_188 = V_7 -> V_74 ;
F_58 ( V_10 , F_59 ( & V_181 ) ) ;
V_178 = F_60 ( & V_181 , V_9 -> V_135 , & V_179 ) ;
V_175 = F_61 ( V_10 , & V_181 , V_178 , false ) ;
if ( F_62 ( V_175 ) ) {
V_10 -> V_189 = 0 ;
V_10 -> V_190 = - F_63 ( V_175 ) ;
return F_63 ( V_175 ) ;
}
F_64 ( V_10 , V_175 , NULL , NULL ) ;
}
return 0 ;
}
bool F_65 ( const struct V_3 * V_10 , const struct V_132 * V_133 )
{
const struct V_8 * V_9 = F_17 ( V_10 ) ;
const struct V_191 * V_135 = F_66 ( V_133 ) ;
if ( V_9 -> V_192 . V_193 ) {
if ( ( V_135 -> V_194 && ( V_9 -> V_192 . V_195 . V_196 ||
V_9 -> V_192 . V_195 . V_197 ) ) ||
( ( V_198 &
* ( T_1 * ) F_67 ( V_133 ) ) &&
V_9 -> V_192 . V_195 . V_199 ) ||
( V_135 -> V_200 && ( V_9 -> V_192 . V_195 . V_200 ||
V_9 -> V_192 . V_195 . V_201 ) ) ||
( ( V_135 -> V_202 || V_135 -> V_203 ) &&
( V_9 -> V_192 . V_195 . V_204 || V_9 -> V_192 . V_195 . V_205 ) ) )
return true ;
}
return false ;
}
static int T_2 F_68 ( void )
{
F_69 ( & V_206 ) ;
return 0 ;
}
static void F_70 ( void )
{
F_71 ( & V_206 ) ;
}
static int T_3 F_72 ( struct V_1 * V_1 )
{
if ( F_73 ( ( void V_207 * * ) V_1 -> V_208 . V_209 ,
sizeof( struct V_210 ) ,
F_74 ( struct V_210 ) ) < 0 )
return - V_211 ;
if ( F_73 ( ( void V_207 * * ) V_1 -> V_208 . V_212 ,
sizeof( struct V_210 ) ,
F_74 ( struct V_210 ) ) < 0 )
goto V_213;
if ( F_73 ( ( void V_207 * * ) V_1 -> V_208 . V_214 ,
sizeof( struct V_215 ) ,
F_74 ( struct V_215 ) ) < 0 )
goto V_216;
if ( F_73 ( ( void V_207 * * ) V_1 -> V_208 . V_217 ,
sizeof( struct V_218 ) ,
F_74 ( struct V_218 ) ) < 0 )
goto V_219;
V_1 -> V_208 . V_220 = F_75 ( sizeof( struct V_221 ) ,
V_37 ) ;
if ( ! V_1 -> V_208 . V_220 )
goto V_222;
return 0 ;
V_222:
F_76 ( ( void V_207 * * ) V_1 -> V_208 . V_217 ) ;
V_219:
F_76 ( ( void V_207 * * ) V_1 -> V_208 . V_214 ) ;
V_216:
F_76 ( ( void V_207 * * ) V_1 -> V_208 . V_212 ) ;
V_213:
F_76 ( ( void V_207 * * ) V_1 -> V_208 . V_209 ) ;
return - V_211 ;
}
static void F_77 ( struct V_1 * V_1 )
{
F_76 ( ( void V_207 * * ) V_1 -> V_208 . V_209 ) ;
F_76 ( ( void V_207 * * ) V_1 -> V_208 . V_212 ) ;
F_76 ( ( void V_207 * * ) V_1 -> V_208 . V_214 ) ;
F_76 ( ( void V_207 * * ) V_1 -> V_208 . V_217 ) ;
F_78 ( V_1 -> V_208 . V_220 ) ;
}
static int T_3 F_79 ( struct V_1 * V_1 )
{
int V_18 = 0 ;
V_1 -> V_62 . V_63 . V_64 = 0 ;
V_1 -> V_62 . V_63 . V_223 = 1 * V_224 ;
V_18 = F_72 ( V_1 ) ;
if ( V_18 )
return V_18 ;
#ifdef F_80
V_18 = F_81 ( V_1 ) ;
if ( V_18 )
goto V_38;
V_18 = F_82 ( V_1 ) ;
if ( V_18 )
goto V_225;
V_18 = F_83 ( V_1 ) ;
if ( V_18 )
goto V_226;
#endif
return V_18 ;
#ifdef F_80
V_226:
F_84 ( V_1 ) ;
V_225:
F_85 ( V_1 ) ;
V_38:
F_77 ( V_1 ) ;
return V_18 ;
#endif
}
static void T_4 F_86 ( struct V_1 * V_1 )
{
#ifdef F_80
F_85 ( V_1 ) ;
F_84 ( V_1 ) ;
F_87 ( V_1 ) ;
#endif
F_77 ( V_1 ) ;
}
static int T_2 F_88 ( void )
{
struct V_132 * V_227 ;
struct V_163 * V_228 ;
int V_18 = 0 ;
F_89 ( sizeof( struct V_191 ) > sizeof( V_227 -> V_229 ) ) ;
for ( V_228 = & V_170 [ 0 ] ; V_228 < & V_170 [ V_168 ] ; ++ V_228 )
F_90 ( V_228 ) ;
if ( V_230 ) {
F_91 ( L_6 ) ;
goto V_38;
}
V_18 = F_92 ( & V_231 , 1 ) ;
if ( V_18 )
goto V_38;
V_18 = F_92 ( & V_232 , 1 ) ;
if ( V_18 )
goto V_233;
V_18 = F_92 ( & V_234 , 1 ) ;
if ( V_18 )
goto V_235;
V_18 = F_92 ( & V_236 , 1 ) ;
if ( V_18 )
goto V_237;
V_18 = F_93 () ;
if ( V_18 )
goto V_238;
V_18 = F_94 ( & V_239 ) ;
if ( V_18 )
goto V_240;
V_231 . V_241 = V_242 . V_243 . V_244 ;
V_18 = F_95 ( & V_245 ) ;
if ( V_18 )
goto V_246;
V_18 = F_96 () ;
if ( V_18 )
goto V_247;
V_18 = F_97 () ;
if ( V_18 )
goto V_248;
V_18 = F_98 () ;
if ( V_18 )
goto V_249;
V_18 = F_99 () ;
if ( V_18 )
goto V_250;
V_18 = F_100 () ;
if ( V_18 )
goto V_251;
#ifdef F_80
V_18 = - V_211 ;
if ( F_101 () )
goto V_252;
if ( F_102 () )
goto V_253;
if ( F_103 () )
goto V_254;
if ( F_104 () )
goto V_255;
#endif
V_18 = F_105 () ;
if ( V_18 )
goto V_256;
V_18 = F_106 () ;
if ( V_18 )
goto V_257;
V_18 = F_107 () ;
if ( V_18 )
goto V_258;
V_18 = F_108 () ;
if ( V_18 )
goto V_259;
V_18 = F_109 () ;
if ( V_18 )
goto V_260;
V_18 = F_110 () ;
if ( V_18 )
goto V_261;
V_18 = F_111 () ;
if ( V_18 )
goto V_262;
V_18 = F_112 () ;
if ( V_18 )
goto V_263;
V_18 = F_68 () ;
if ( V_18 )
goto V_264;
#ifdef F_113
V_18 = F_114 () ;
if ( V_18 )
goto V_265;
#endif
V_38:
return V_18 ;
#ifdef F_113
V_265:
F_70 () ;
#endif
V_264:
F_115 () ;
V_263:
F_116 () ;
V_262:
F_117 () ;
V_261:
F_118 () ;
V_260:
F_119 () ;
V_259:
F_120 () ;
V_258:
F_121 () ;
V_257:
F_122 () ;
V_256:
#ifdef F_80
F_123 () ;
V_255:
F_124 () ;
V_254:
F_125 () ;
V_253:
F_126 () ;
V_252:
#endif
F_127 () ;
V_251:
F_128 () ;
V_250:
F_129 () ;
V_249:
F_130 () ;
V_248:
F_131 () ;
V_247:
F_132 ( & V_245 ) ;
V_246:
F_133 ( V_26 ) ;
F_134 ( V_26 ) ;
V_240:
F_135 () ;
V_238:
F_136 ( & V_236 ) ;
V_237:
F_136 ( & V_234 ) ;
V_235:
F_136 ( & V_232 ) ;
V_233:
F_136 ( & V_231 ) ;
goto V_38;
}
static void T_5 F_137 ( void )
{
if ( V_230 )
return;
F_133 ( V_26 ) ;
F_134 ( V_26 ) ;
F_117 () ;
F_116 () ;
F_115 () ;
F_70 () ;
F_118 () ;
F_119 () ;
F_120 () ;
F_121 () ;
F_122 () ;
#ifdef F_80
F_123 () ;
F_124 () ;
F_125 () ;
F_126 () ;
#endif
F_127 () ;
F_128 () ;
F_129 () ;
F_130 () ;
F_131 () ;
F_135 () ;
F_132 ( & V_245 ) ;
F_136 ( & V_236 ) ;
F_136 ( & V_234 ) ;
F_136 ( & V_232 ) ;
F_136 ( & V_231 ) ;
F_138 () ;
}
