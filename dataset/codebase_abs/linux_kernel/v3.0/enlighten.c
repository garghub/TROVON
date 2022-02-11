static void F_1 ( void )
{
#ifdef F_2
if ( V_1 > V_2 )
V_1 = V_2 ;
#endif
}
static void F_3 ( int V_3 )
{
struct V_4 V_5 ;
int V_6 ;
struct V_7 * V_8 ;
F_4 ( V_9 == & V_10 ) ;
if ( V_3 < V_2 )
F_5 ( V_11 , V_3 ) = & V_9 -> V_7 [ V_3 ] ;
if ( ! V_12 ) {
if ( V_3 >= V_2 )
F_1 () ;
return;
}
V_8 = & F_5 ( V_13 , V_3 ) ;
V_5 . V_14 = F_6 ( V_8 ) ;
V_5 . V_15 = F_7 ( V_8 ) ;
V_6 = F_8 ( V_16 , V_3 , & V_5 ) ;
if ( V_6 ) {
F_9 ( V_17 L_1 , V_6 ) ;
V_12 = 0 ;
F_1 () ;
} else {
F_5 ( V_11 , V_3 ) = V_8 ;
}
}
void F_10 ( void )
{
int V_3 ;
F_11 (cpu) {
bool V_18 = ( V_3 != F_12 () ) ;
if ( V_18 &&
F_8 ( V_19 , V_3 , NULL ) )
F_13 () ;
F_14 ( V_3 ) ;
if ( V_12 )
F_3 ( V_3 ) ;
if ( V_18 &&
F_8 ( V_20 , V_3 , NULL ) )
F_13 () ;
}
}
static void T_1 F_15 ( void )
{
unsigned V_21 = F_16 ( V_22 , NULL ) ;
struct V_23 V_24 ;
F_16 ( V_25 , & V_24 ) ;
F_9 ( V_26 L_2 ,
V_27 . V_28 ) ;
F_9 ( V_26 L_3 ,
V_21 >> 16 , V_21 & 0xffff , V_24 . V_29 ,
F_17 ( V_30 ) ? L_4 : L_5 ) ;
}
static void F_18 ( unsigned int * V_31 , unsigned int * V_32 ,
unsigned int * V_33 , unsigned int * V_34 )
{
unsigned V_35 = ~ 0 ;
unsigned V_36 = ~ 0 ;
unsigned V_37 = ~ 0 ;
switch ( * V_31 ) {
case 1 :
V_36 = V_38 ;
V_37 = V_39 ;
break;
case 0xb :
V_35 = 0 ;
break;
}
asm(XEN_EMULATE_PREFIX "cpuid"
: "=a" (*ax),
"=b" (*bx),
"=c" (*cx),
"=d" (*dx)
: "0" (*ax), "2" (*cx));
* V_32 &= V_35 ;
* V_33 &= V_36 ;
* V_34 &= V_37 ;
}
static void T_1 F_19 ( void )
{
unsigned int V_31 , V_32 , V_33 , V_34 ;
unsigned int V_40 ;
V_39 =
~ ( ( 1 << V_41 ) |
( 1 << V_42 ) |
( 1 << V_43 ) |
( 1 << V_44 ) ) ;
if ( ! F_20 () )
V_39 &=
~ ( ( 1 << V_45 ) |
( 1 << V_46 ) ) ;
V_31 = 1 ;
F_18 ( & V_31 , & V_32 , & V_33 , & V_34 ) ;
V_40 =
( 1 << ( V_47 % 32 ) ) |
( 1 << ( V_48 % 32 ) ) ;
if ( ( V_33 & V_40 ) != V_40 )
V_38 &= ~ V_40 ;
}
static void F_21 ( int V_49 , unsigned long V_50 )
{
F_22 ( V_49 , V_50 ) ;
}
static unsigned long F_23 ( int V_49 )
{
return F_24 ( V_49 ) ;
}
static void F_25 ( struct V_51 * V_52 )
{
F_26 () ;
F_27 ( V_52 ) ;
}
static unsigned long F_28 ( void )
{
return 0 ;
}
static void F_29 ( void * V_53 , T_2 V_54 )
{
int V_55 ;
T_3 * V_56 ;
T_3 V_57 ;
unsigned long V_58 ;
struct V_59 * V_59 ;
V_56 = F_30 ( ( unsigned long ) V_53 , & V_55 ) ;
F_4 ( V_56 == NULL ) ;
V_58 = F_31 ( * V_56 ) ;
V_59 = F_32 ( V_58 ) ;
V_57 = F_33 ( V_58 , V_54 ) ;
if ( F_34 ( ( unsigned long ) V_53 , V_57 , 0 ) )
F_13 () ;
if ( ! F_35 ( V_59 ) ) {
void * V_60 = F_36 ( F_37 ( V_58 ) ) ;
if ( V_60 != V_53 )
if ( F_34 ( ( unsigned long ) V_60 , V_57 , 0 ) )
F_13 () ;
} else
F_38 () ;
}
static void F_39 ( struct V_61 * V_62 , unsigned V_63 )
{
const unsigned V_64 = V_65 / V_66 ;
int V_67 ;
for( V_67 = 0 ; V_67 < V_63 ; V_67 += V_64 )
F_29 ( V_62 + V_67 , V_68 ) ;
}
static void F_40 ( struct V_61 * V_62 , unsigned V_63 )
{
const unsigned V_64 = V_65 / V_66 ;
int V_67 ;
for( V_67 = 0 ; V_67 < V_63 ; V_67 += V_64 )
F_29 ( V_62 + V_67 , V_69 ) ;
}
static void F_41 ( const void * V_70 , unsigned V_63 )
{
struct V_71 * V_72 ;
struct V_73 V_74 = F_42 ( sizeof( * V_72 ) ) ;
V_72 = V_74 . args ;
V_72 -> V_75 = V_76 ;
V_72 -> V_77 . V_78 = ( unsigned long ) V_70 ;
V_72 -> V_79 . V_80 = V_63 ;
F_43 ( V_74 . V_81 , V_72 , 1 , NULL , V_82 ) ;
F_44 ( V_83 ) ;
}
static void F_45 ( const struct V_84 * V_85 )
{
unsigned long V_86 = V_85 -> V_87 ;
unsigned int V_88 = V_85 -> V_88 + 1 ;
unsigned V_89 = ( V_88 + V_65 - 1 ) / V_65 ;
unsigned long V_90 [ V_89 ] ;
int V_91 ;
F_4 ( V_88 > 65536 ) ;
F_4 ( V_86 & ~ V_92 ) ;
for ( V_91 = 0 ; V_86 < V_85 -> V_87 + V_88 ; V_86 += V_65 , V_91 ++ ) {
int V_55 ;
T_3 * V_56 ;
unsigned long V_58 , V_14 ;
void * V_93 ;
V_56 = F_30 ( V_86 , & V_55 ) ;
F_4 ( V_56 == NULL ) ;
V_58 = F_31 ( * V_56 ) ;
V_14 = F_46 ( V_58 ) ;
V_93 = F_36 ( F_37 ( V_58 ) ) ;
V_90 [ V_91 ] = V_14 ;
F_47 ( ( void * ) V_86 ) ;
F_47 ( V_93 ) ;
}
if ( F_48 ( V_90 , V_88 / sizeof( struct V_61 ) ) )
F_13 () ;
}
static void T_1 F_49 ( const struct V_84 * V_85 )
{
unsigned long V_86 = V_85 -> V_87 ;
unsigned int V_88 = V_85 -> V_88 + 1 ;
unsigned V_89 = ( V_88 + V_65 - 1 ) / V_65 ;
unsigned long V_90 [ V_89 ] ;
int V_91 ;
F_4 ( V_88 > 65536 ) ;
F_4 ( V_86 & ~ V_92 ) ;
for ( V_91 = 0 ; V_86 < V_85 -> V_87 + V_88 ; V_86 += V_65 , V_91 ++ ) {
T_3 V_57 ;
unsigned long V_58 , V_14 ;
V_58 = F_50 ( V_86 ) ;
V_14 = F_46 ( V_58 ) ;
V_57 = F_33 ( V_58 , V_68 ) ;
if ( F_34 ( ( unsigned long ) V_86 , V_57 , 0 ) )
F_13 () ;
V_90 [ V_91 ] = V_14 ;
}
if ( F_48 ( V_90 , V_88 / sizeof( struct V_61 ) ) )
F_13 () ;
}
static void F_51 ( struct V_94 * V_95 ,
unsigned int V_3 , unsigned int V_67 )
{
struct V_61 * V_96 = F_52 ( V_3 ) ;
T_4 V_97 = F_53 ( & V_96 [ V_98 + V_67 ] ) ;
struct V_73 V_81 = F_54 ( 0 ) ;
F_55 ( V_81 . V_81 , V_97 . V_97 , V_95 -> V_99 [ V_67 ] ) ;
}
static void F_56 ( struct V_94 * V_95 , unsigned int V_3 )
{
if ( F_57 () == V_83 ) {
#ifdef F_58
F_59 ( 0 ) ;
#else
F_60 ( V_100 , 0 ) ;
#endif
}
F_61 () ;
F_51 ( V_95 , V_3 , 0 ) ;
F_51 ( V_95 , V_3 , 1 ) ;
F_51 ( V_95 , V_3 , 2 ) ;
F_44 ( V_83 ) ;
}
static void F_62 ( unsigned int V_101 )
{
if ( F_63 ( V_102 , V_101 ) )
F_13 () ;
}
static void F_64 ( struct V_61 * V_103 , int V_104 ,
const void * V_105 )
{
T_4 V_106 = F_53 ( & V_103 [ V_104 ] ) ;
T_5 V_107 = * ( T_5 * ) V_105 ;
F_65 () ;
F_26 () ;
if ( F_66 ( V_106 . V_97 , V_107 ) )
F_13 () ;
F_67 () ;
}
static int F_68 ( int V_108 , const T_6 * V_50 ,
struct V_109 * V_5 )
{
unsigned long V_70 ;
if ( V_50 -> type != V_110 && V_50 -> type != V_111 )
return 0 ;
V_5 -> V_108 = V_108 ;
V_70 = F_69 ( * V_50 ) ;
#ifdef F_70
if ( V_70 == ( unsigned long ) V_112 )
V_70 = ( unsigned long ) V_113 ;
else if ( V_70 == ( unsigned long ) V_114 )
V_70 = ( unsigned long ) V_115 ;
else if ( V_70 == ( unsigned long ) V_116 )
V_70 = ( unsigned long ) V_117 ;
else if ( V_70 == ( unsigned long ) V_118 ||
V_70 == ( unsigned long ) V_119 ) {
return 0 ;
#ifdef F_71
} else if ( V_70 == ( unsigned long ) V_120 ) {
return 0 ;
#endif
} else {
if ( F_72 ( V_50 -> V_121 != 0 ) )
return 0 ;
}
#endif
V_5 -> V_87 = V_70 ;
V_5 -> V_122 = F_73 ( * V_50 ) ;
V_5 -> V_123 = V_50 -> V_124 ;
if ( V_50 -> type == V_111 )
V_5 -> V_123 |= 1 << 2 ;
return 1 ;
}
static void F_74 ( T_6 * V_103 , int V_104 , const T_6 * V_125 )
{
unsigned long V_126 = ( unsigned long ) & V_103 [ V_104 ] ;
unsigned long V_127 , V_128 ;
F_65 () ;
V_127 = F_75 ( V_129 . V_87 ) ;
V_128 = V_127 + F_75 ( V_129 . V_88 ) + 1 ;
F_26 () ;
F_76 ( V_103 , V_104 , V_125 ) ;
if ( V_126 >= V_127 && ( V_126 + 8 ) <= V_128 ) {
struct V_109 V_5 [ 2 ] ;
V_5 [ 1 ] . V_87 = 0 ;
if ( F_68 ( V_104 , V_125 , & V_5 [ 0 ] ) )
if ( F_77 ( V_5 ) )
F_13 () ;
}
F_67 () ;
}
static void F_78 ( const struct V_84 * V_130 ,
struct V_109 * V_131 )
{
unsigned V_132 , V_133 , V_134 ;
V_134 = ( V_130 -> V_88 + 1 ) / sizeof( T_6 ) ;
F_4 ( V_134 > 256 ) ;
for ( V_132 = V_133 = 0 ; V_132 < V_134 ; V_132 ++ ) {
T_6 * V_107 = ( T_6 * ) ( V_130 -> V_87 ) + V_132 ;
if ( F_68 ( V_132 , V_107 , & V_131 [ V_133 ] ) )
V_133 ++ ;
}
V_131 [ V_133 ] . V_87 = 0 ;
}
void F_79 ( struct V_109 * V_131 )
{
const struct V_84 * V_130 = & F_80 ( V_129 ) ;
F_78 ( V_130 , V_131 ) ;
}
static void F_81 ( const struct V_84 * V_130 )
{
static F_82 ( V_135 ) ;
static struct V_109 V_131 [ 257 ] ;
F_83 ( & V_135 ) ;
F_80 ( V_129 ) = * V_130 ;
F_78 ( V_130 , V_131 ) ;
F_26 () ;
if ( F_77 ( V_131 ) )
F_13 () ;
F_84 ( & V_135 ) ;
}
static void F_85 ( struct V_61 * V_103 , int V_107 ,
const void * V_130 , int type )
{
F_65 () ;
switch ( type ) {
case V_136 :
case V_137 :
break;
default: {
T_4 V_97 = F_53 ( & V_103 [ V_107 ] ) ;
F_26 () ;
if ( F_66 ( V_97 . V_97 , * ( T_5 * ) V_130 ) )
F_13 () ;
}
}
F_67 () ;
}
static void T_1 F_86 ( struct V_61 * V_103 , int V_107 ,
const void * V_130 , int type )
{
switch ( type ) {
case V_136 :
case V_137 :
break;
default: {
T_4 V_97 = F_87 ( & V_103 [ V_107 ] ) ;
if ( F_66 ( V_97 . V_97 , * ( T_5 * ) V_130 ) )
V_103 [ V_107 ] = * (struct V_61 * ) V_130 ;
}
}
}
static void F_88 ( struct V_138 * V_139 ,
struct V_94 * V_140 )
{
struct V_73 V_74 = F_42 ( 0 ) ;
F_89 ( V_74 . V_81 , V_141 , V_140 -> V_142 ) ;
F_44 ( V_83 ) ;
}
static void F_90 ( unsigned V_143 )
{
struct V_144 V_145 ;
V_145 . V_146 = ( V_143 == 0 ) ? 1 : ( V_143 >> 12 ) & 3 ;
F_91 ( V_147 , & V_145 ) ;
}
static void F_92 ( void )
{
}
static T_7 F_93 ( T_7 V_49 )
{
return 0 ;
}
static void F_94 ( T_7 V_49 , T_7 V_50 )
{
F_72 ( 1 ) ;
}
static T_5 F_95 ( void )
{
return 0 ;
}
static void F_96 ( T_7 V_148 , T_7 V_149 )
{
F_72 ( 1 ) ;
}
static void F_97 ( void )
{
return;
}
static T_7 F_98 ( void )
{
return 0 ;
}
static void F_99 ( void )
{
V_150 -> V_151 = F_93 ;
V_150 -> V_152 = F_94 ;
V_150 -> V_153 = F_95 ;
V_150 -> V_154 = F_96 ;
V_150 -> V_155 = F_97 ;
V_150 -> V_156 = F_98 ;
}
static void F_100 ( void )
{
struct V_73 V_74 ;
V_74 = F_42 ( 0 ) ;
F_101 ( V_74 . V_81 , 0 ) ;
F_44 ( V_83 ) ;
}
static unsigned long F_102 ( void )
{
unsigned long V_157 = F_103 ( V_158 ) ;
if ( F_104 ( V_157 == 0 ) ) {
V_157 = F_105 () ;
F_106 ( V_158 , V_157 ) ;
}
return V_157 ;
}
static void F_107 ( unsigned long V_157 )
{
struct V_73 V_74 ;
F_106 ( V_158 , V_157 ) ;
V_74 = F_42 ( 0 ) ;
F_101 ( V_74 . V_81 , ( V_157 & V_159 ) != 0 ) ;
F_44 ( V_83 ) ;
}
static void F_108 ( unsigned long V_160 )
{
V_160 &= ~ V_161 ;
V_160 &= ~ V_162 ;
F_109 ( V_160 ) ;
}
static int F_110 ( unsigned int V_163 , unsigned V_148 , unsigned V_164 )
{
int V_165 ;
V_165 = 0 ;
switch ( V_163 ) {
#ifdef F_70
unsigned V_166 ;
T_5 V_167 ;
case V_168 : V_166 = V_169 ; goto V_170;
case V_171 : V_166 = V_172 ; goto V_170;
case V_173 : V_166 = V_174 ; goto V_170;
V_170:
V_167 = ( ( T_5 ) V_164 << 32 ) | V_148 ;
if ( F_63 ( V_166 , V_167 ) != 0 )
V_165 = - V_175 ;
break;
#endif
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
case V_182 :
break;
case V_183 :
if ( F_12 () == 0 )
F_111 ( ( ( T_5 ) V_164 << 32 ) | V_148 ) ;
break;
default:
V_165 = F_112 ( V_163 , V_148 , V_164 ) ;
}
return V_165 ;
}
void F_113 ( void )
{
if ( ! F_17 ( V_184 ) ) {
F_114 ( V_185 ,
V_186 -> V_187 ) ;
V_9 =
(struct V_187 * ) F_115 ( V_185 ) ;
} else
V_9 =
(struct V_187 * ) F_36 ( V_186 -> V_187 ) ;
#ifndef F_2
F_116 () ;
#endif
F_117 () ;
}
void F_116 ( void )
{
int V_3 ;
F_118 (cpu)
F_3 ( V_3 ) ;
if ( V_12 ) {
V_188 . V_189 = F_119 ( V_190 ) ;
V_188 . V_191 = F_119 ( V_192 ) ;
V_188 . V_193 = F_119 ( V_194 ) ;
V_188 . V_195 = F_119 ( V_196 ) ;
V_197 . V_198 = V_199 ;
}
}
static unsigned F_120 ( T_8 type , T_9 V_200 , void * V_201 ,
unsigned long V_70 , unsigned V_202 )
{
char * V_127 , * V_128 , * V_203 ;
unsigned V_165 ;
V_127 = V_128 = V_203 = NULL ;
#define F_121 ( V_72 , T_10 ) \
case PARAVIRT_PATCH(op.x): \
if (have_vcpu_info_placement) { \
start = (char *)xen_##x##_direct; \
end = xen_##x##_direct_end; \
reloc = xen_##x##_direct_reloc; \
} \
goto patch_site
switch ( type ) {
F_121 ( V_188 , V_195 ) ;
F_121 ( V_188 , V_193 ) ;
F_121 ( V_188 , V_189 ) ;
F_121 ( V_188 , V_191 ) ;
#undef F_121
V_204:
if ( V_127 == NULL || ( V_128 - V_127 ) > V_202 )
goto V_205;
V_165 = F_122 ( V_201 , V_202 , V_127 , V_128 ) ;
if ( V_203 > V_127 && V_203 < V_128 ) {
int V_206 = V_203 - V_127 ;
long * V_207 = ( long * ) ( V_201 + V_206 ) ;
long V_208 = V_127 - ( char * ) V_70 ;
* V_207 += V_208 ;
}
break;
V_205:
default:
V_165 = F_123 ( type , V_200 , V_201 ,
V_70 , V_202 ) ;
break;
}
return V_165 ;
}
static void F_124 ( int V_209 )
{
struct V_210 V_211 = { . V_209 = V_209 } ;
if ( F_125 ( V_212 , & V_211 ) )
F_13 () ;
}
static void F_126 ( char * V_213 )
{
F_124 ( V_214 ) ;
}
static void F_127 ( void )
{
F_124 ( V_214 ) ;
}
static void F_128 ( void )
{
F_124 ( V_215 ) ;
}
static void F_129 ( void )
{
if ( V_216 )
V_216 () ;
F_124 ( V_215 ) ;
}
static void F_130 ( struct V_217 * V_218 )
{
F_124 ( V_219 ) ;
}
static int
F_131 ( struct V_220 * V_221 , unsigned long V_222 , void * V_105 )
{
F_124 ( V_219 ) ;
return V_223 ;
}
int F_132 ( void )
{
F_133 ( & V_224 , & V_225 ) ;
return 0 ;
}
static void T_1 F_134 ( void )
{
V_226 . V_227 = F_86 ;
V_226 . V_228 = F_49 ;
F_135 ( 0 ) ;
F_136 ( 0 ) ;
V_226 . V_227 = F_85 ;
V_226 . V_228 = F_45 ;
}
T_11 void T_1 F_137 ( void )
{
struct V_144 V_145 ;
int V_229 ;
T_12 * V_230 ;
if ( ! V_186 )
return;
V_231 = V_232 ;
F_138 () ;
V_27 = V_233 ;
V_234 = V_235 ;
V_226 = V_236 ;
V_237 = V_238 ;
V_239 . V_240 . V_241 = V_242 ;
V_239 . V_243 . V_244 = V_245 ;
V_239 . V_243 . V_246 = F_15 ;
F_139 () ;
F_140 () ;
V_247 &= ~ V_248 ;
if ( ! F_20 () )
V_247 &= ~ ( V_249 | V_250 ) ;
V_247 |= V_251 ;
V_252 &= ~ V_253 ;
F_141 () ;
F_142 () ;
if ( ! F_17 ( V_184 ) )
F_143 () ;
F_134 () ;
F_144 () ;
F_19 () ;
#ifdef F_145
F_99 () ;
#endif
if ( F_17 ( V_30 ) ) {
V_197 . V_254 = V_255 ;
V_197 . V_256 = V_257 ;
}
V_258 = V_259 ;
V_260 = & F_5 ( V_261 , 0 ) ;
F_146 () ;
#ifdef F_147
V_262 = - 1 ;
#endif
V_230 = ( T_12 * ) V_186 -> V_263 ;
if ( ! F_20 () )
V_247 &= ~ ( V_249 | V_250 ) ;
V_247 |= V_251 ;
F_5 ( V_11 , 0 ) = & V_9 -> V_7 [ 0 ] ;
F_148 () ;
V_264 = true ;
F_149 () ;
F_150 ( L_6 ) ;
V_230 = F_151 ( V_230 , V_186 -> V_265 ) ;
F_152 () ;
F_153 () ;
#ifdef F_58
V_27 . V_266 = 1 ;
if ( F_17 ( V_267 ) )
V_27 . V_266 = 0 ;
#else
V_27 . V_266 = 0 ;
#endif
F_154 () ;
V_145 . V_146 = 1 ;
V_229 = F_91 ( V_147 , & V_145 ) ;
if ( V_229 != 0 )
F_155 ( L_7 , V_229 ) ;
#ifdef F_58
F_156 ( & V_268 ) ;
V_268 . V_269 = 1 ;
V_268 . V_270 = 1 ;
V_268 . V_271 [ 0 ] = F_157 ( 1 ) ;
#endif
V_272 . V_273 . V_274 = ( 9 << 4 ) | 0 ;
V_272 . V_273 . V_275 = V_186 -> V_276
? F_158 ( V_186 -> V_276 ) : 0 ;
V_272 . V_273 . V_277 = V_186 -> V_278 ;
V_272 . V_273 . V_279 = F_158 ( V_186 -> V_280 ) ;
if ( ! F_20 () ) {
F_159 ( L_8 , 0 , NULL ) ;
F_159 ( L_9 , 0 , NULL ) ;
F_159 ( L_10 , 0 , NULL ) ;
if ( V_281 )
V_239 . V_282 . V_283 = V_284 ;
} else {
F_160 () ;
}
F_150 ( L_11 ) ;
F_14 ( 0 ) ;
#ifdef F_58
F_161 () ;
#else
F_162 ( ( char * ) F_163 ( & V_272 ) ) ;
#endif
}
static int F_164 ( int * V_285 , int * V_286 )
{
T_13 V_287 , V_288 , V_289 , V_290 , V_89 , V_163 , V_167 ;
T_5 V_58 ;
V_167 = F_165 () ;
F_166 ( V_167 + 1 , & V_287 , & V_288 , & V_289 , & V_290 ) ;
* V_285 = V_287 >> 16 ;
* V_286 = V_287 & 0xffff ;
F_9 ( V_26 L_12 , * V_285 , * V_286 ) ;
F_166 ( V_167 + 2 , & V_89 , & V_163 , & V_289 , & V_290 ) ;
V_58 = F_158 ( V_291 ) ;
F_167 ( V_163 , ( T_7 ) V_58 , ( T_7 ) ( V_58 >> 32 ) ) ;
F_142 () ;
V_27 . V_28 = L_13 ;
V_231 = V_292 ;
return 0 ;
}
void T_14 F_168 ( void )
{
int V_3 ;
struct V_293 V_294 ;
static struct V_187 * V_295 = 0 ;
if ( ! V_295 )
V_295 = (struct V_187 * )
F_169 ( V_65 , V_65 ) ;
V_294 . V_296 = V_82 ;
V_294 . V_101 = 0 ;
V_294 . V_297 = V_298 ;
V_294 . V_299 = F_158 ( V_295 ) >> V_300 ;
if ( F_170 ( V_301 , & V_294 ) )
F_13 () ;
V_9 = (struct V_187 * ) V_295 ;
F_11 (cpu) {
F_5 ( V_11 , V_3 ) = & V_9 -> V_7 [ V_3 ] ;
}
}
static int T_15 F_171 ( struct V_220 * V_302 ,
unsigned long V_303 , void * V_304 )
{
int V_3 = ( long ) V_304 ;
switch ( V_303 ) {
case V_305 :
F_5 ( V_11 , V_3 ) = & V_9 -> V_7 [ V_3 ] ;
if ( V_306 )
F_172 ( V_3 ) ;
break;
default:
break;
}
return V_307 ;
}
static void T_1 F_173 ( void )
{
int V_211 ;
int V_285 , V_286 ;
V_211 = F_164 ( & V_285 , & V_286 ) ;
if ( V_211 < 0 )
return;
F_168 () ;
if ( F_17 ( V_308 ) )
V_306 = 1 ;
F_174 () ;
F_175 ( & V_309 ) ;
F_176 () ;
V_12 = 0 ;
V_239 . V_310 . V_311 = V_312 ;
F_177 () ;
F_178 () ;
}
static bool T_1 F_179 ( void )
{
if ( F_180 () )
return false ;
if ( ! F_165 () )
return false ;
return true ;
}
bool F_181 ( void )
{
if ( F_180 () )
return false ;
if ( ! F_182 () )
return false ;
if ( F_17 ( V_313 ) && V_306 )
return false ;
return true ;
}
