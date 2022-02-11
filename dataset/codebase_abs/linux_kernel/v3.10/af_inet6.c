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
if ( F_24 ( V_85 ) ) {
if ( V_80 >= sizeof( struct V_81 ) &&
V_82 -> V_115 ) {
V_10 -> V_116 = V_82 -> V_115 ;
}
if ( ! V_10 -> V_116 ) {
V_18 = - V_88 ;
goto V_117;
}
V_114 = F_25 ( V_1 , V_10 -> V_116 ) ;
if ( ! V_114 ) {
V_18 = - V_118 ;
goto V_117;
}
}
V_83 = V_119 ;
if ( ! ( V_85 & V_93 ) ) {
if ( ! ( V_7 -> V_105 || V_7 -> V_106 ) &&
! F_26 ( V_1 , & V_82 -> V_92 ,
V_114 , 0 ) ) {
V_18 = - V_111 ;
goto V_117;
}
}
F_5 () ;
}
}
V_7 -> V_120 = V_83 ;
V_7 -> V_121 = V_83 ;
V_9 -> V_122 = V_82 -> V_92 ;
if ( ! ( V_85 & V_93 ) )
V_9 -> V_123 = V_82 -> V_92 ;
if ( V_10 -> V_75 -> V_124 ( V_10 , V_84 ) ) {
F_27 ( V_10 ) ;
V_18 = - V_125 ;
goto V_38;
}
if ( V_85 != V_112 ) {
V_10 -> V_126 |= V_127 ;
if ( V_85 != V_101 )
V_9 -> V_61 = 1 ;
}
if ( V_84 )
V_10 -> V_126 |= V_128 ;
V_7 -> V_74 = F_14 ( V_7 -> V_45 ) ;
V_7 -> V_129 = 0 ;
V_7 -> V_130 = 0 ;
V_38:
F_28 ( V_10 ) ;
return V_18 ;
V_117:
F_5 () ;
goto V_38;
}
int F_29 ( struct V_2 * V_3 )
{
struct V_3 * V_10 = V_3 -> V_10 ;
if ( V_10 == NULL )
return - V_88 ;
F_30 ( V_10 ) ;
F_31 ( V_10 ) ;
return F_32 ( V_3 ) ;
}
void F_33 ( struct V_3 * V_10 )
{
struct V_8 * V_9 = F_17 ( V_10 ) ;
struct V_131 * V_132 ;
struct V_133 * V_134 ;
V_132 = F_34 ( & V_9 -> V_135 , NULL ) ;
if ( V_132 != NULL )
F_35 ( V_132 ) ;
V_132 = F_34 ( & V_9 -> V_136 , NULL ) ;
if ( V_132 != NULL )
F_35 ( V_132 ) ;
F_36 ( V_10 ) ;
V_134 = F_34 ( & V_9 -> V_134 , NULL ) ;
if ( V_134 != NULL )
F_37 ( V_10 , V_134 , V_134 -> V_137 ) ;
}
int F_38 ( struct V_2 * V_3 , struct V_78 * V_79 ,
int * V_138 , int V_139 )
{
struct V_81 * sin = (struct V_81 * ) V_79 ;
struct V_3 * V_10 = V_3 -> V_10 ;
struct V_6 * V_7 = F_11 ( V_10 ) ;
struct V_8 * V_9 = F_17 ( V_10 ) ;
sin -> V_89 = V_90 ;
sin -> V_140 = 0 ;
sin -> V_115 = 0 ;
if ( V_139 ) {
if ( ! V_7 -> V_129 )
return - V_141 ;
if ( ( ( 1 << V_10 -> V_99 ) & ( V_142 | V_143 ) ) &&
V_139 == 1 )
return - V_141 ;
sin -> V_95 = V_7 -> V_129 ;
sin -> V_92 = V_9 -> V_144 ;
if ( V_9 -> V_145 )
sin -> V_140 = V_9 -> V_146 ;
} else {
if ( F_39 ( & V_9 -> V_122 ) )
sin -> V_92 = V_9 -> V_123 ;
else
sin -> V_92 = V_9 -> V_122 ;
sin -> V_95 = V_7 -> V_74 ;
}
sin -> V_115 = F_40 ( & sin -> V_92 ,
V_10 -> V_116 ) ;
* V_138 = sizeof( * sin ) ;
return 0 ;
}
int F_41 ( struct V_2 * V_3 , unsigned int V_147 , unsigned long V_148 )
{
struct V_3 * V_10 = V_3 -> V_10 ;
struct V_1 * V_1 = F_18 ( V_10 ) ;
switch ( V_147 ) {
case V_149 :
return F_42 ( V_10 , (struct V_150 V_151 * ) V_148 ) ;
case V_152 :
return F_43 ( V_10 , (struct V_153 V_151 * ) V_148 ) ;
case V_154 :
case V_155 :
return F_44 ( V_1 , V_147 , ( void V_151 * ) V_148 ) ;
case V_156 :
return F_45 ( V_1 , ( void V_151 * ) V_148 ) ;
case V_157 :
return F_46 ( V_1 , ( void V_151 * ) V_148 ) ;
case V_158 :
return F_47 ( V_1 , ( void V_151 * ) V_148 ) ;
default:
if ( ! V_10 -> V_75 -> V_159 )
return - V_160 ;
return V_10 -> V_75 -> V_159 ( V_10 , V_147 , V_148 ) ;
}
return 0 ;
}
int F_48 ( struct V_11 * V_161 )
{
struct V_162 * V_163 ;
struct V_11 * V_12 ;
struct V_162 * V_164 ;
int V_4 = V_161 -> V_4 ;
int V_165 ;
F_49 ( & V_166 ) ;
V_165 = - V_88 ;
if ( V_161 -> type >= V_167 )
goto V_168;
V_12 = NULL ;
V_165 = - V_28 ;
V_164 = & V_169 [ V_161 -> type ] ;
F_50 (lh, &inetsw6[p->type]) {
V_12 = F_51 ( V_163 , struct V_11 , V_170 ) ;
if ( V_171 & V_12 -> V_34 ) {
if ( V_4 == V_12 -> V_4 )
break;
V_164 = V_163 ;
}
V_12 = NULL ;
}
if ( V_12 )
goto V_172;
F_52 ( & V_161 -> V_170 , V_164 ) ;
V_165 = 0 ;
V_38:
F_53 ( & V_166 ) ;
return V_165 ;
V_172:
F_54 ( L_3 , V_4 ) ;
goto V_38;
V_168:
F_54 ( L_4 ,
V_161 -> type ) ;
goto V_38;
}
void
F_55 ( struct V_11 * V_161 )
{
if ( V_171 & V_161 -> V_34 ) {
F_54 ( L_5 ,
V_161 -> V_4 ) ;
} else {
F_49 ( & V_166 ) ;
F_56 ( & V_161 -> V_170 ) ;
F_53 ( & V_166 ) ;
F_57 () ;
}
}
int F_58 ( struct V_3 * V_10 )
{
struct V_8 * V_9 = F_17 ( V_10 ) ;
struct V_173 * V_174 ;
V_174 = F_59 ( V_10 , V_9 -> V_175 ) ;
if ( V_174 == NULL ) {
struct V_6 * V_7 = F_11 ( V_10 ) ;
struct V_176 * V_177 , V_178 ;
struct V_179 V_180 ;
memset ( & V_180 , 0 , sizeof( V_180 ) ) ;
V_180 . V_181 = V_10 -> V_51 ;
V_180 . V_144 = V_9 -> V_144 ;
V_180 . V_123 = V_9 -> V_123 ;
V_180 . V_182 = V_9 -> V_146 ;
V_180 . V_183 = V_10 -> V_116 ;
V_180 . V_184 = V_10 -> V_185 ;
V_180 . V_186 = V_7 -> V_129 ;
V_180 . V_187 = V_7 -> V_74 ;
F_60 ( V_10 , F_61 ( & V_180 ) ) ;
V_177 = F_62 ( & V_180 , V_9 -> V_134 , & V_178 ) ;
V_174 = F_63 ( V_10 , & V_180 , V_177 , false ) ;
if ( F_64 ( V_174 ) ) {
V_10 -> V_188 = 0 ;
V_10 -> V_189 = - F_65 ( V_174 ) ;
return F_65 ( V_174 ) ;
}
F_66 ( V_10 , V_174 , NULL , NULL ) ;
}
return 0 ;
}
bool F_67 ( const struct V_3 * V_10 , const struct V_131 * V_132 )
{
const struct V_8 * V_9 = F_17 ( V_10 ) ;
const struct V_190 * V_134 = F_68 ( V_132 ) ;
if ( V_9 -> V_191 . V_192 ) {
if ( ( V_134 -> V_193 && ( V_9 -> V_191 . V_194 . V_195 ||
V_9 -> V_191 . V_194 . V_196 ) ) ||
( ( V_197 &
* ( T_1 * ) F_69 ( V_132 ) ) &&
V_9 -> V_191 . V_194 . V_198 ) ||
( V_134 -> V_199 && ( V_9 -> V_191 . V_194 . V_199 ||
V_9 -> V_191 . V_194 . V_200 ) ) ||
( ( V_134 -> V_201 || V_134 -> V_202 ) &&
( V_9 -> V_191 . V_194 . V_203 || V_9 -> V_191 . V_194 . V_204 ) ) )
return true ;
}
return false ;
}
static int T_2 F_70 ( void )
{
F_71 ( & V_205 ) ;
return 0 ;
}
static void F_72 ( void )
{
F_73 ( & V_205 ) ;
}
static int T_3 F_74 ( struct V_1 * V_1 )
{
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
if ( F_75 ( ( void V_206 * * ) V_1 -> V_207 . V_216 ,
sizeof( struct V_217 ) ,
F_76 ( struct V_217 ) ) < 0 )
goto V_218;
V_1 -> V_207 . V_219 = F_77 ( sizeof( struct V_220 ) ,
V_37 ) ;
if ( ! V_1 -> V_207 . V_219 )
goto V_221;
return 0 ;
V_221:
F_78 ( ( void V_206 * * ) V_1 -> V_207 . V_216 ) ;
V_218:
F_78 ( ( void V_206 * * ) V_1 -> V_207 . V_213 ) ;
V_215:
F_78 ( ( void V_206 * * ) V_1 -> V_207 . V_211 ) ;
V_212:
F_78 ( ( void V_206 * * ) V_1 -> V_207 . V_208 ) ;
return - V_210 ;
}
static void F_79 ( struct V_1 * V_1 )
{
F_78 ( ( void V_206 * * ) V_1 -> V_207 . V_208 ) ;
F_78 ( ( void V_206 * * ) V_1 -> V_207 . V_211 ) ;
F_78 ( ( void V_206 * * ) V_1 -> V_207 . V_213 ) ;
F_78 ( ( void V_206 * * ) V_1 -> V_207 . V_216 ) ;
F_80 ( V_1 -> V_207 . V_219 ) ;
}
static int T_3 F_81 ( struct V_1 * V_1 )
{
int V_18 = 0 ;
V_1 -> V_62 . V_63 . V_64 = 0 ;
V_1 -> V_62 . V_63 . V_222 = 1 * V_223 ;
V_18 = F_74 ( V_1 ) ;
if ( V_18 )
return V_18 ;
#ifdef F_82
V_18 = F_83 ( V_1 ) ;
if ( V_18 )
goto V_38;
V_18 = F_84 ( V_1 ) ;
if ( V_18 )
goto V_224;
V_18 = F_85 ( V_1 ) ;
if ( V_18 )
goto V_225;
#endif
return V_18 ;
#ifdef F_82
V_225:
F_86 ( V_1 ) ;
V_224:
F_87 ( V_1 ) ;
V_38:
F_79 ( V_1 ) ;
return V_18 ;
#endif
}
static void T_4 F_88 ( struct V_1 * V_1 )
{
#ifdef F_82
F_87 ( V_1 ) ;
F_86 ( V_1 ) ;
F_89 ( V_1 ) ;
#endif
F_79 ( V_1 ) ;
}
static int T_2 F_90 ( void )
{
struct V_162 * V_226 ;
int V_18 = 0 ;
F_91 ( sizeof( struct V_190 ) > F_92 ( struct V_131 , V_227 ) ) ;
for ( V_226 = & V_169 [ 0 ] ; V_226 < & V_169 [ V_167 ] ; ++ V_226 )
F_93 ( V_226 ) ;
if ( V_228 ) {
F_94 ( L_6 ) ;
goto V_38;
}
V_18 = F_95 ( & V_229 , 1 ) ;
if ( V_18 )
goto V_38;
V_18 = F_95 ( & V_230 , 1 ) ;
if ( V_18 )
goto V_231;
V_18 = F_95 ( & V_232 , 1 ) ;
if ( V_18 )
goto V_233;
V_18 = F_95 ( & V_234 , 1 ) ;
if ( V_18 )
goto V_235;
V_18 = F_96 () ;
if ( V_18 )
goto V_236;
V_18 = F_97 ( & V_237 ) ;
if ( V_18 )
goto V_238;
V_229 . V_239 = V_240 . V_241 . V_242 ;
V_18 = F_98 ( & V_243 ) ;
if ( V_18 )
goto V_244;
V_18 = F_99 () ;
if ( V_18 )
goto V_245;
V_18 = F_100 () ;
if ( V_18 )
goto V_246;
V_18 = F_101 () ;
if ( V_18 )
goto V_247;
V_18 = F_102 () ;
if ( V_18 )
goto V_248;
V_18 = F_103 () ;
if ( V_18 )
goto V_249;
#ifdef F_82
V_18 = - V_210 ;
if ( F_104 () )
goto V_250;
if ( F_105 () )
goto V_251;
if ( F_106 () )
goto V_252;
if ( F_107 () )
goto V_253;
#endif
V_18 = F_108 () ;
if ( V_18 )
goto V_254;
V_18 = F_109 () ;
if ( V_18 )
goto V_255;
V_18 = F_110 () ;
if ( V_18 )
goto V_256;
V_18 = F_111 () ;
if ( V_18 )
goto V_257;
V_18 = F_112 () ;
if ( V_18 )
goto V_258;
V_18 = F_113 () ;
if ( V_18 )
goto V_259;
V_18 = F_114 () ;
if ( V_18 )
goto V_260;
V_18 = F_115 () ;
if ( V_18 )
goto V_261;
V_18 = F_70 () ;
if ( V_18 )
goto V_262;
#ifdef F_116
V_18 = F_117 () ;
if ( V_18 )
goto V_263;
#endif
V_38:
return V_18 ;
#ifdef F_116
V_263:
F_72 () ;
#endif
V_262:
F_118 () ;
V_261:
F_119 () ;
V_260:
F_120 () ;
V_259:
F_121 () ;
V_258:
F_122 () ;
V_257:
F_123 () ;
V_256:
F_124 () ;
V_255:
F_125 () ;
V_254:
#ifdef F_82
F_126 () ;
V_253:
F_127 () ;
V_252:
F_128 () ;
V_251:
F_129 () ;
V_250:
#endif
F_130 () ;
V_249:
F_131 () ;
V_248:
F_132 () ;
V_247:
F_133 () ;
V_246:
F_134 () ;
V_245:
F_135 ( & V_243 ) ;
V_244:
F_136 ( V_26 ) ;
F_137 ( V_26 ) ;
V_238:
F_138 () ;
V_236:
F_139 ( & V_234 ) ;
V_235:
F_139 ( & V_232 ) ;
V_233:
F_139 ( & V_230 ) ;
V_231:
F_139 ( & V_229 ) ;
goto V_38;
}
static void T_5 F_140 ( void )
{
if ( V_228 )
return;
F_136 ( V_26 ) ;
F_137 ( V_26 ) ;
F_120 () ;
F_119 () ;
F_118 () ;
F_72 () ;
F_121 () ;
F_122 () ;
F_123 () ;
F_124 () ;
F_125 () ;
#ifdef F_82
F_126 () ;
F_127 () ;
F_128 () ;
F_129 () ;
#endif
F_130 () ;
F_131 () ;
F_132 () ;
F_133 () ;
F_134 () ;
F_138 () ;
F_135 ( & V_243 ) ;
F_139 ( & V_234 ) ;
F_139 ( & V_232 ) ;
F_139 ( & V_230 ) ;
F_139 ( & V_229 ) ;
F_141 () ;
}
