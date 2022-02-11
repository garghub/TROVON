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
V_33 = 0 ;
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
F_43 ( V_70 , V_63 ) ;
V_72 = V_74 . args ;
V_72 -> V_75 = V_76 ;
V_72 -> V_77 . V_78 = ( unsigned long ) V_70 ;
V_72 -> V_79 . V_80 = V_63 ;
F_44 ( V_74 . V_81 , V_72 , 1 , NULL , V_82 ) ;
F_45 ( V_83 ) ;
}
static void F_46 ( const struct V_84 * V_85 )
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
V_14 = F_47 ( V_58 ) ;
V_93 = F_36 ( F_37 ( V_58 ) ) ;
V_90 [ V_91 ] = V_14 ;
F_48 ( ( void * ) V_86 ) ;
F_48 ( V_93 ) ;
}
if ( F_49 ( V_90 , V_88 / sizeof( struct V_61 ) ) )
F_13 () ;
}
static void T_1 F_50 ( const struct V_84 * V_85 )
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
V_58 = F_51 ( V_86 ) ;
V_14 = F_47 ( V_58 ) ;
V_57 = F_33 ( V_58 , V_68 ) ;
if ( F_34 ( ( unsigned long ) V_86 , V_57 , 0 ) )
F_13 () ;
V_90 [ V_91 ] = V_14 ;
}
if ( F_49 ( V_90 , V_88 / sizeof( struct V_61 ) ) )
F_13 () ;
}
static void F_52 ( struct V_94 * V_95 ,
unsigned int V_3 , unsigned int V_67 )
{
struct V_61 * V_96 = F_53 ( V_3 ) ;
T_4 V_97 = F_54 ( & V_96 [ V_98 + V_67 ] ) ;
struct V_73 V_81 = F_55 ( 0 ) ;
F_56 ( V_81 . V_81 , V_97 . V_97 , V_95 -> V_99 [ V_67 ] ) ;
}
static void F_57 ( struct V_94 * V_95 , unsigned int V_3 )
{
if ( F_58 () == V_83 ) {
#ifdef F_59
F_60 ( 0 ) ;
#else
F_61 ( V_100 , 0 ) ;
#endif
}
F_62 () ;
F_52 ( V_95 , V_3 , 0 ) ;
F_52 ( V_95 , V_3 , 1 ) ;
F_52 ( V_95 , V_3 , 2 ) ;
F_45 ( V_83 ) ;
}
static void F_63 ( unsigned int V_101 )
{
if ( F_64 ( V_102 , V_101 ) )
F_13 () ;
}
static void F_65 ( struct V_61 * V_103 , int V_104 ,
const void * V_105 )
{
T_4 V_106 = F_54 ( & V_103 [ V_104 ] ) ;
T_5 V_107 = * ( T_5 * ) V_105 ;
F_66 ( V_103 , V_104 , V_107 ) ;
F_67 () ;
F_26 () ;
if ( F_68 ( V_106 . V_97 , V_107 ) )
F_13 () ;
F_69 () ;
}
static int F_70 ( int V_108 , const T_6 * V_50 ,
struct V_109 * V_5 )
{
unsigned long V_70 ;
if ( V_50 -> type != V_110 && V_50 -> type != V_111 )
return 0 ;
V_5 -> V_108 = V_108 ;
V_70 = F_71 ( * V_50 ) ;
#ifdef F_72
if ( V_70 == ( unsigned long ) V_112 )
V_70 = ( unsigned long ) V_113 ;
else if ( V_70 == ( unsigned long ) V_114 )
V_70 = ( unsigned long ) V_115 ;
else if ( V_70 == ( unsigned long ) V_116 )
V_70 = ( unsigned long ) V_117 ;
else if ( V_70 == ( unsigned long ) V_118 ||
V_70 == ( unsigned long ) V_119 ) {
return 0 ;
#ifdef F_73
} else if ( V_70 == ( unsigned long ) V_120 ) {
return 0 ;
#endif
} else {
if ( F_74 ( V_50 -> V_121 != 0 ) )
return 0 ;
}
#endif
V_5 -> V_87 = V_70 ;
V_5 -> V_122 = F_75 ( * V_50 ) ;
V_5 -> V_123 = V_50 -> V_124 ;
if ( V_50 -> type == V_111 )
V_5 -> V_123 |= 1 << 2 ;
return 1 ;
}
static void F_76 ( T_6 * V_103 , int V_104 , const T_6 * V_125 )
{
unsigned long V_126 = ( unsigned long ) & V_103 [ V_104 ] ;
unsigned long V_127 , V_128 ;
F_77 ( V_103 , V_104 , V_125 ) ;
F_67 () ;
V_127 = F_78 ( V_129 . V_87 ) ;
V_128 = V_127 + F_78 ( V_129 . V_88 ) + 1 ;
F_26 () ;
F_79 ( V_103 , V_104 , V_125 ) ;
if ( V_126 >= V_127 && ( V_126 + 8 ) <= V_128 ) {
struct V_109 V_5 [ 2 ] ;
V_5 [ 1 ] . V_87 = 0 ;
if ( F_70 ( V_104 , V_125 , & V_5 [ 0 ] ) )
if ( F_80 ( V_5 ) )
F_13 () ;
}
F_69 () ;
}
static void F_81 ( const struct V_84 * V_130 ,
struct V_109 * V_131 )
{
unsigned V_132 , V_133 , V_134 ;
V_134 = ( V_130 -> V_88 + 1 ) / sizeof( T_6 ) ;
F_4 ( V_134 > 256 ) ;
for ( V_132 = V_133 = 0 ; V_132 < V_134 ; V_132 ++ ) {
T_6 * V_107 = ( T_6 * ) ( V_130 -> V_87 ) + V_132 ;
if ( F_70 ( V_132 , V_107 , & V_131 [ V_133 ] ) )
V_133 ++ ;
}
V_131 [ V_133 ] . V_87 = 0 ;
}
void F_82 ( struct V_109 * V_131 )
{
const struct V_84 * V_130 = & F_83 ( V_129 ) ;
F_81 ( V_130 , V_131 ) ;
}
static void F_84 ( const struct V_84 * V_130 )
{
static F_85 ( V_135 ) ;
static struct V_109 V_131 [ 257 ] ;
F_86 ( V_130 ) ;
F_87 ( & V_135 ) ;
F_83 ( V_129 ) = * V_130 ;
F_81 ( V_130 , V_131 ) ;
F_26 () ;
if ( F_80 ( V_131 ) )
F_13 () ;
F_88 ( & V_135 ) ;
}
static void F_89 ( struct V_61 * V_103 , int V_107 ,
const void * V_130 , int type )
{
F_90 ( V_103 , V_107 , V_130 , type ) ;
F_67 () ;
switch ( type ) {
case V_136 :
case V_137 :
break;
default: {
T_4 V_97 = F_54 ( & V_103 [ V_107 ] ) ;
F_26 () ;
if ( F_68 ( V_97 . V_97 , * ( T_5 * ) V_130 ) )
F_13 () ;
}
}
F_69 () ;
}
static void T_1 F_91 ( struct V_61 * V_103 , int V_107 ,
const void * V_130 , int type )
{
F_90 ( V_103 , V_107 , V_130 , type ) ;
switch ( type ) {
case V_136 :
case V_137 :
break;
default: {
T_4 V_97 = F_92 ( & V_103 [ V_107 ] ) ;
if ( F_68 ( V_97 . V_97 , * ( T_5 * ) V_130 ) )
V_103 [ V_107 ] = * (struct V_61 * ) V_130 ;
}
}
}
static void F_93 ( struct V_138 * V_139 ,
struct V_94 * V_140 )
{
struct V_73 V_74 ;
V_74 = F_42 ( 0 ) ;
F_94 ( V_74 . V_81 , V_141 , V_140 -> V_142 ) ;
F_45 ( V_83 ) ;
}
static void F_95 ( unsigned V_143 )
{
struct V_144 V_145 ;
V_145 . V_146 = ( V_143 == 0 ) ? 1 : ( V_143 >> 12 ) & 3 ;
F_96 ( V_147 , & V_145 ) ;
}
static void F_97 ( void )
{
}
static T_7 F_98 ( T_7 V_49 )
{
return 0 ;
}
static void F_99 ( T_7 V_49 , T_7 V_50 )
{
F_74 ( 1 ) ;
}
static T_5 F_100 ( void )
{
return 0 ;
}
static void F_101 ( T_7 V_148 , T_7 V_149 )
{
F_74 ( 1 ) ;
}
static void F_102 ( void )
{
return;
}
static T_7 F_103 ( void )
{
return 0 ;
}
static void F_104 ( void )
{
V_150 -> V_151 = F_98 ;
V_150 -> V_152 = F_99 ;
V_150 -> V_153 = F_100 ;
V_150 -> V_154 = F_101 ;
V_150 -> V_155 = F_102 ;
V_150 -> V_156 = F_103 ;
}
static void F_105 ( void )
{
struct V_73 V_74 ;
V_74 = F_42 ( 0 ) ;
F_106 ( V_74 . V_81 , 0 ) ;
F_45 ( V_83 ) ;
}
static unsigned long F_107 ( void )
{
unsigned long V_157 = F_108 ( V_158 ) ;
if ( F_109 ( V_157 == 0 ) ) {
V_157 = F_110 () ;
F_111 ( V_158 , V_157 ) ;
}
return V_157 ;
}
static void F_112 ( unsigned long V_157 )
{
struct V_73 V_74 ;
F_111 ( V_158 , V_157 ) ;
V_74 = F_42 ( 0 ) ;
F_106 ( V_74 . V_81 , ( V_157 & V_159 ) != 0 ) ;
F_45 ( V_83 ) ;
}
static void F_113 ( unsigned long V_160 )
{
V_160 &= ~ V_161 ;
V_160 &= ~ V_162 ;
F_114 ( V_160 ) ;
}
static int F_115 ( unsigned int V_163 , unsigned V_148 , unsigned V_164 )
{
int V_165 ;
V_165 = 0 ;
switch ( V_163 ) {
#ifdef F_72
unsigned V_166 ;
T_5 V_167 ;
case V_168 : V_166 = V_169 ; goto V_170;
case V_171 : V_166 = V_172 ; goto V_170;
case V_173 : V_166 = V_174 ; goto V_170;
V_170:
V_167 = ( ( T_5 ) V_164 << 32 ) | V_148 ;
if ( F_64 ( V_166 , V_167 ) != 0 )
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
F_116 ( ( ( T_5 ) V_164 << 32 ) | V_148 ) ;
break;
default:
V_165 = F_117 ( V_163 , V_148 , V_164 ) ;
}
return V_165 ;
}
void F_118 ( void )
{
if ( ! F_17 ( V_184 ) ) {
F_119 ( V_185 ,
V_186 -> V_187 ) ;
V_9 =
(struct V_187 * ) F_120 ( V_185 ) ;
} else
V_9 =
(struct V_187 * ) F_36 ( V_186 -> V_187 ) ;
#ifndef F_2
F_121 () ;
#endif
F_122 () ;
}
void F_121 ( void )
{
int V_3 ;
F_123 (cpu)
F_3 ( V_3 ) ;
if ( V_12 ) {
V_188 . V_189 = F_124 ( V_190 ) ;
V_188 . V_191 = F_124 ( V_192 ) ;
V_188 . V_193 = F_124 ( V_194 ) ;
V_188 . V_195 = F_124 ( V_196 ) ;
V_197 . V_198 = V_199 ;
}
}
static unsigned F_125 ( T_8 type , T_9 V_200 , void * V_201 ,
unsigned long V_70 , unsigned V_202 )
{
char * V_127 , * V_128 , * V_203 ;
unsigned V_165 ;
V_127 = V_128 = V_203 = NULL ;
#define F_126 ( V_72 , T_10 ) \
case PARAVIRT_PATCH(op.x): \
if (have_vcpu_info_placement) { \
start = (char *)xen_##x##_direct; \
end = xen_##x##_direct_end; \
reloc = xen_##x##_direct_reloc; \
} \
goto patch_site
switch ( type ) {
F_126 ( V_188 , V_195 ) ;
F_126 ( V_188 , V_193 ) ;
F_126 ( V_188 , V_189 ) ;
F_126 ( V_188 , V_191 ) ;
#undef F_126
V_204:
if ( V_127 == NULL || ( V_128 - V_127 ) > V_202 )
goto V_205;
V_165 = F_127 ( V_201 , V_202 , V_127 , V_128 ) ;
if ( V_203 > V_127 && V_203 < V_128 ) {
int V_206 = V_203 - V_127 ;
long * V_207 = ( long * ) ( V_201 + V_206 ) ;
long V_208 = V_127 - ( char * ) V_70 ;
* V_207 += V_208 ;
}
break;
V_205:
default:
V_165 = F_128 ( type , V_200 , V_201 ,
V_70 , V_202 ) ;
break;
}
return V_165 ;
}
static void F_129 ( int V_209 )
{
struct V_210 V_211 = { . V_209 = V_209 } ;
if ( F_130 ( V_212 , & V_211 ) )
F_13 () ;
}
static void F_131 ( char * V_213 )
{
F_129 ( V_214 ) ;
}
static void F_132 ( void )
{
F_129 ( V_214 ) ;
}
static void F_133 ( void )
{
F_129 ( V_215 ) ;
}
static void F_134 ( void )
{
if ( V_216 )
V_216 () ;
F_129 ( V_215 ) ;
}
static void F_135 ( struct V_217 * V_218 )
{
F_129 ( V_219 ) ;
}
static int
F_136 ( struct V_220 * V_221 , unsigned long V_222 , void * V_105 )
{
F_129 ( V_219 ) ;
return V_223 ;
}
int F_137 ( void )
{
F_138 ( & V_224 , & V_225 ) ;
return 0 ;
}
static void T_1 F_139 ( void )
{
V_226 . V_227 = F_91 ;
V_226 . V_228 = F_50 ;
F_140 ( 0 ) ;
F_141 ( 0 ) ;
V_226 . V_227 = F_89 ;
V_226 . V_228 = F_46 ;
}
T_11 void T_1 F_142 ( void )
{
struct V_144 V_145 ;
int V_229 ;
T_12 * V_230 ;
if ( ! V_186 )
return;
V_231 = V_232 ;
F_143 () ;
V_27 = V_233 ;
V_234 = V_235 ;
V_226 = V_236 ;
V_237 = V_238 ;
V_239 . V_240 . V_241 = V_242 ;
V_239 . V_243 . V_244 = V_245 ;
V_239 . V_243 . V_246 = F_15 ;
F_144 () ;
F_145 () ;
V_247 &= ~ V_248 ;
#if 0
if (!xen_initial_domain())
#endif
V_247 &= ~ ( V_249 | V_250 ) ;
V_247 |= V_251 ;
V_252 &= ~ V_253 ;
F_146 () ;
F_147 () ;
if ( ! F_17 ( V_184 ) )
F_148 () ;
F_139 () ;
F_149 () ;
F_19 () ;
#ifdef F_150
F_104 () ;
#endif
if ( F_17 ( V_30 ) ) {
V_197 . V_254 = V_255 ;
V_197 . V_256 = V_257 ;
}
V_258 = V_259 ;
V_260 = & F_5 ( V_261 , 0 ) ;
F_151 () ;
#ifdef F_152
V_262 = - 1 ;
#endif
V_230 = ( T_12 * ) V_186 -> V_263 ;
F_5 ( V_11 , 0 ) = & V_9 -> V_7 [ 0 ] ;
F_153 () ;
V_264 = true ;
F_154 ( L_6 ) ;
V_230 = F_155 ( V_230 , V_186 -> V_265 ) ;
F_156 () ;
F_157 () ;
#ifdef F_59
V_27 . V_266 = 1 ;
if ( F_17 ( V_267 ) )
V_27 . V_266 = 0 ;
#else
V_27 . V_266 = 0 ;
#endif
F_158 () ;
V_145 . V_146 = 1 ;
V_229 = F_96 ( V_147 , & V_145 ) ;
if ( V_229 != 0 )
F_159 ( L_7 , V_229 ) ;
#ifdef F_59
F_160 ( & V_268 ) ;
V_268 . V_269 = 1 ;
V_268 . V_270 = 1 ;
V_268 . V_271 [ 0 ] = F_161 ( 1 ) ;
#endif
V_272 . V_273 . V_274 = ( 9 << 4 ) | 0 ;
V_272 . V_273 . V_275 = V_186 -> V_276
? F_162 ( V_186 -> V_276 ) : 0 ;
V_272 . V_273 . V_277 = V_186 -> V_278 ;
V_272 . V_273 . V_279 = F_162 ( V_186 -> V_280 ) ;
if ( ! F_20 () ) {
F_163 ( L_8 , 0 , NULL ) ;
F_163 ( L_9 , 0 , NULL ) ;
F_163 ( L_10 , 0 , NULL ) ;
if ( V_281 )
V_239 . V_282 . V_283 = V_284 ;
} else {
const struct V_285 * V_5 =
( void * ) ( ( char * ) V_186 +
V_186 -> V_286 . V_287 . V_288 ) ;
F_164 ( V_5 , V_186 -> V_286 . V_287 . V_289 ) ;
V_186 -> V_286 . V_290 . V_14 = 0 ;
V_186 -> V_286 . V_290 . V_291 = 0 ;
F_165 () ;
}
F_154 ( L_11 ) ;
F_14 ( 0 ) ;
#ifdef F_59
F_166 () ;
#else
F_167 ( ( char * ) F_168 ( & V_272 ) ) ;
#endif
}
static int F_169 ( int * V_292 , int * V_293 )
{
T_13 V_294 , V_295 , V_296 , V_297 , V_89 , V_163 , V_167 ;
T_5 V_58 ;
V_167 = F_170 () ;
F_171 ( V_167 + 1 , & V_294 , & V_295 , & V_296 , & V_297 ) ;
* V_292 = V_294 >> 16 ;
* V_293 = V_294 & 0xffff ;
F_9 ( V_26 L_12 , * V_292 , * V_293 ) ;
F_171 ( V_167 + 2 , & V_89 , & V_163 , & V_296 , & V_297 ) ;
V_58 = F_162 ( V_298 ) ;
F_172 ( V_163 , ( T_7 ) V_58 , ( T_7 ) ( V_58 >> 32 ) ) ;
F_147 () ;
V_27 . V_28 = L_13 ;
V_231 = V_299 ;
return 0 ;
}
void T_14 F_173 ( void )
{
int V_3 ;
struct V_300 V_301 ;
static struct V_187 * V_302 = 0 ;
if ( ! V_302 )
V_302 = (struct V_187 * )
F_174 ( V_65 , V_65 ) ;
V_301 . V_303 = V_82 ;
V_301 . V_101 = 0 ;
V_301 . V_304 = V_305 ;
V_301 . V_306 = F_162 ( V_302 ) >> V_307 ;
if ( F_175 ( V_308 , & V_301 ) )
F_13 () ;
V_9 = (struct V_187 * ) V_302 ;
F_11 (cpu) {
F_5 ( V_11 , V_3 ) = & V_9 -> V_7 [ V_3 ] ;
}
}
static int T_15 F_176 ( struct V_220 * V_309 ,
unsigned long V_310 , void * V_311 )
{
int V_3 = ( long ) V_311 ;
switch ( V_310 ) {
case V_312 :
F_3 ( V_3 ) ;
if ( V_313 )
F_177 ( V_3 ) ;
break;
default:
break;
}
return V_314 ;
}
static void T_1 F_178 ( void )
{
int V_211 ;
int V_292 , V_293 ;
V_211 = F_169 ( & V_292 , & V_293 ) ;
if ( V_211 < 0 )
return;
F_173 () ;
if ( F_17 ( V_315 ) )
V_313 = 1 ;
F_179 () ;
F_180 ( & V_316 ) ;
F_181 () ;
V_239 . V_317 . V_318 = V_319 ;
F_182 () ;
F_183 () ;
}
static bool T_1 F_184 ( void )
{
if ( F_185 () )
return false ;
if ( ! F_170 () )
return false ;
return true ;
}
bool F_186 ( void )
{
if ( F_185 () )
return false ;
if ( ! F_187 () )
return false ;
if ( F_17 ( V_320 ) && V_313 )
return false ;
return true ;
}
