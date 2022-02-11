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
unsigned V_38 = 0 ;
switch ( * V_31 ) {
case 1 :
V_36 = V_39 ;
V_38 = V_40 ;
V_37 = V_41 ;
break;
case V_42 :
* V_31 = 0 ;
* V_32 = 0 ;
* V_33 = V_43 ;
* V_34 = V_44 ;
return;
case V_45 :
V_36 = ~ ( 1 << V_46 ) ;
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
* V_33 |= V_38 ;
* V_34 &= V_37 ;
}
static bool T_1 F_19 ( void )
{
#if F_20 ( V_47 ) && ! F_20 ( V_48 ) && \
! F_20 ( V_49 )
struct V_50 V_51 = {
. V_52 = V_53 ,
. V_54 . V_55 . V_56 = - 1 ,
. V_54 . V_55 . type = V_57 ,
} ;
T_2 V_58 [ 3 ] ;
unsigned int V_31 , V_32 , V_33 , V_34 ;
unsigned int V_59 ;
if ( ! F_21 () )
return false ;
V_31 = 1 ;
V_33 = 0 ;
F_22 ( & V_31 , & V_32 , & V_33 , & V_34 ) ;
V_59 = ( 1 << ( V_60 % 32 ) ) |
( 1 << ( V_61 % 32 ) ) ;
if ( ( V_33 & V_59 ) != V_59 )
return false ;
V_31 = V_42 ;
V_32 = 0 ;
V_33 = 0 ;
V_34 = 0 ;
F_22 ( & V_31 , & V_32 , & V_33 , & V_34 ) ;
V_58 [ 0 ] = V_62 ;
V_58 [ 1 ] = 1 ;
V_58 [ 2 ] = ( V_63 | V_64 ) ;
F_23 ( V_51 . V_54 . V_55 . V_65 , V_58 ) ;
if ( ( F_24 ( & V_51 ) == 0 ) &&
( V_58 [ 2 ] & ( V_66 | V_67 ) ) ) {
V_43 = V_33 ;
V_44 = V_34 ;
}
return true ;
#else
return false ;
#endif
}
static void T_1 F_25 ( void )
{
unsigned int V_31 , V_32 , V_33 , V_34 ;
unsigned int V_68 ;
V_41 =
~ ( ( 1 << V_69 ) |
( 1 << V_70 ) |
( 1 << V_71 ) |
( 1 << V_72 ) ) ;
if ( ! F_21 () )
V_41 &=
~ ( ( 1 << V_73 ) |
( 1 << V_74 ) ) ;
V_31 = 1 ;
V_33 = 0 ;
F_18 ( & V_31 , & V_32 , & V_33 , & V_34 ) ;
V_68 =
( 1 << ( V_75 % 32 ) ) |
( 1 << ( V_76 % 32 ) ) ;
if ( ( V_33 & V_68 ) != V_68 )
V_39 &= ~ V_68 ;
if ( F_19 () )
V_40 = ( 1 << ( V_61 % 32 ) ) ;
}
static void F_26 ( int V_77 , unsigned long V_78 )
{
F_27 ( V_77 , V_78 ) ;
}
static unsigned long F_28 ( int V_77 )
{
return F_29 ( V_77 ) ;
}
static void F_30 ( struct V_79 * V_80 )
{
F_31 () ;
F_32 ( V_80 ) ;
}
static unsigned long F_33 ( void )
{
return 0 ;
}
static void F_34 ( void * V_81 , T_3 V_82 )
{
int V_83 ;
T_4 * V_84 ;
T_4 V_85 ;
unsigned long V_86 ;
struct V_87 * V_87 ;
V_84 = F_35 ( ( unsigned long ) V_81 , & V_83 ) ;
F_4 ( V_84 == NULL ) ;
V_86 = F_36 ( * V_84 ) ;
V_87 = F_37 ( V_86 ) ;
V_85 = F_38 ( V_86 , V_82 ) ;
if ( F_39 ( ( unsigned long ) V_81 , V_85 , 0 ) )
F_13 () ;
if ( ! F_40 ( V_87 ) ) {
void * V_88 = F_41 ( F_42 ( V_86 ) ) ;
if ( V_88 != V_81 )
if ( F_39 ( ( unsigned long ) V_88 , V_85 , 0 ) )
F_13 () ;
} else
F_43 () ;
}
static void F_44 ( struct V_89 * V_90 , unsigned V_91 )
{
const unsigned V_92 = V_93 / V_94 ;
int V_95 ;
for( V_95 = 0 ; V_95 < V_91 ; V_95 += V_92 )
F_34 ( V_90 + V_95 , V_96 ) ;
}
static void F_45 ( struct V_89 * V_90 , unsigned V_91 )
{
const unsigned V_92 = V_93 / V_94 ;
int V_95 ;
for( V_95 = 0 ; V_95 < V_91 ; V_95 += V_92 )
F_34 ( V_90 + V_95 , V_97 ) ;
}
static void F_46 ( const void * V_98 , unsigned V_91 )
{
struct V_99 * V_51 ;
struct V_100 V_101 = F_47 ( sizeof( * V_51 ) ) ;
F_48 ( V_98 , V_91 ) ;
V_51 = V_101 . args ;
V_51 -> V_52 = V_102 ;
V_51 -> V_103 . V_104 = ( unsigned long ) V_98 ;
V_51 -> V_105 . V_106 = V_91 ;
F_49 ( V_101 . V_107 , V_51 , 1 , NULL , V_108 ) ;
F_50 ( V_109 ) ;
}
static void F_51 ( const struct V_110 * V_111 )
{
unsigned long V_112 = V_111 -> V_113 ;
unsigned int V_114 = V_111 -> V_114 + 1 ;
unsigned V_115 = ( V_114 + V_93 - 1 ) / V_93 ;
unsigned long V_116 [ V_115 ] ;
int V_117 ;
F_4 ( V_114 > 65536 ) ;
F_4 ( V_112 & ~ V_118 ) ;
for ( V_117 = 0 ; V_112 < V_111 -> V_113 + V_114 ; V_112 += V_93 , V_117 ++ ) {
int V_83 ;
T_4 * V_84 ;
unsigned long V_86 , V_14 ;
void * V_119 ;
V_84 = F_35 ( V_112 , & V_83 ) ;
F_4 ( V_84 == NULL ) ;
V_86 = F_36 ( * V_84 ) ;
V_14 = F_52 ( V_86 ) ;
V_119 = F_41 ( F_42 ( V_86 ) ) ;
V_116 [ V_117 ] = V_14 ;
F_53 ( ( void * ) V_112 ) ;
F_53 ( V_119 ) ;
}
if ( F_54 ( V_116 , V_114 / sizeof( struct V_89 ) ) )
F_13 () ;
}
static void T_1 F_55 ( const struct V_110 * V_111 )
{
unsigned long V_112 = V_111 -> V_113 ;
unsigned int V_114 = V_111 -> V_114 + 1 ;
unsigned V_115 = ( V_114 + V_93 - 1 ) / V_93 ;
unsigned long V_116 [ V_115 ] ;
int V_117 ;
F_4 ( V_114 > 65536 ) ;
F_4 ( V_112 & ~ V_118 ) ;
for ( V_117 = 0 ; V_112 < V_111 -> V_113 + V_114 ; V_112 += V_93 , V_117 ++ ) {
T_4 V_85 ;
unsigned long V_86 , V_14 ;
V_86 = F_56 ( V_112 ) ;
V_14 = F_52 ( V_86 ) ;
V_85 = F_38 ( V_86 , V_96 ) ;
if ( F_39 ( ( unsigned long ) V_112 , V_85 , 0 ) )
F_13 () ;
V_116 [ V_117 ] = V_14 ;
}
if ( F_54 ( V_116 , V_114 / sizeof( struct V_89 ) ) )
F_13 () ;
}
static void F_57 ( struct V_120 * V_121 ,
unsigned int V_3 , unsigned int V_95 )
{
struct V_89 * V_122 = F_58 ( V_3 ) ;
T_5 V_123 = F_59 ( & V_122 [ V_124 + V_95 ] ) ;
struct V_100 V_107 = F_60 ( 0 ) ;
F_61 ( V_107 . V_107 , V_123 . V_123 , V_121 -> V_125 [ V_95 ] ) ;
}
static void F_62 ( struct V_120 * V_121 , unsigned int V_3 )
{
if ( F_63 () == V_109 ) {
#ifdef F_64
F_65 ( 0 ) ;
#else
F_66 ( V_126 , 0 ) ;
#endif
}
F_67 () ;
F_57 ( V_121 , V_3 , 0 ) ;
F_57 ( V_121 , V_3 , 1 ) ;
F_57 ( V_121 , V_3 , 2 ) ;
F_50 ( V_109 ) ;
}
static void F_68 ( unsigned int V_127 )
{
if ( F_69 ( V_128 , V_127 ) )
F_13 () ;
}
static void F_70 ( struct V_89 * V_129 , int V_130 ,
const void * V_131 )
{
T_5 V_132 = F_59 ( & V_129 [ V_130 ] ) ;
T_6 V_133 = * ( T_6 * ) V_131 ;
F_71 ( V_129 , V_130 , V_133 ) ;
F_72 () ;
F_31 () ;
if ( F_73 ( V_132 . V_123 , V_133 ) )
F_13 () ;
F_74 () ;
}
static int F_75 ( int V_134 , const T_7 * V_78 ,
struct V_135 * V_5 )
{
unsigned long V_98 ;
if ( V_78 -> type != V_136 && V_78 -> type != V_137 )
return 0 ;
V_5 -> V_134 = V_134 ;
V_98 = F_76 ( * V_78 ) ;
#ifdef F_77
if ( V_98 == ( unsigned long ) V_138 )
V_98 = ( unsigned long ) V_139 ;
else if ( V_98 == ( unsigned long ) V_140 )
V_98 = ( unsigned long ) V_141 ;
else if ( V_98 == ( unsigned long ) V_142 )
V_98 = ( unsigned long ) V_143 ;
else if ( V_98 == ( unsigned long ) V_144 ||
V_98 == ( unsigned long ) V_145 ) {
return 0 ;
#ifdef F_78
} else if ( V_98 == ( unsigned long ) V_146 ) {
return 0 ;
#endif
} else {
if ( F_79 ( V_78 -> V_147 != 0 ) )
return 0 ;
}
#endif
V_5 -> V_113 = V_98 ;
V_5 -> V_148 = F_80 ( * V_78 ) ;
V_5 -> V_149 = V_78 -> V_150 ;
if ( V_78 -> type == V_137 )
V_5 -> V_149 |= 1 << 2 ;
return 1 ;
}
static void F_81 ( T_7 * V_129 , int V_130 , const T_7 * V_151 )
{
unsigned long V_152 = ( unsigned long ) & V_129 [ V_130 ] ;
unsigned long V_153 , V_154 ;
F_82 ( V_129 , V_130 , V_151 ) ;
F_72 () ;
V_153 = F_83 ( V_155 . V_113 ) ;
V_154 = V_153 + F_83 ( V_155 . V_114 ) + 1 ;
F_31 () ;
F_84 ( V_129 , V_130 , V_151 ) ;
if ( V_152 >= V_153 && ( V_152 + 8 ) <= V_154 ) {
struct V_135 V_5 [ 2 ] ;
V_5 [ 1 ] . V_113 = 0 ;
if ( F_75 ( V_130 , V_151 , & V_5 [ 0 ] ) )
if ( F_85 ( V_5 ) )
F_13 () ;
}
F_74 () ;
}
static void F_86 ( const struct V_110 * V_156 ,
struct V_135 * V_157 )
{
unsigned V_158 , V_159 , V_160 ;
V_160 = ( V_156 -> V_114 + 1 ) / sizeof( T_7 ) ;
F_4 ( V_160 > 256 ) ;
for ( V_158 = V_159 = 0 ; V_158 < V_160 ; V_158 ++ ) {
T_7 * V_133 = ( T_7 * ) ( V_156 -> V_113 ) + V_158 ;
if ( F_75 ( V_158 , V_133 , & V_157 [ V_159 ] ) )
V_159 ++ ;
}
V_157 [ V_159 ] . V_113 = 0 ;
}
void F_87 ( struct V_135 * V_157 )
{
const struct V_110 * V_156 = & F_88 ( V_155 ) ;
F_86 ( V_156 , V_157 ) ;
}
static void F_89 ( const struct V_110 * V_156 )
{
static F_90 ( V_161 ) ;
static struct V_135 V_157 [ 257 ] ;
F_91 ( V_156 ) ;
F_92 ( & V_161 ) ;
F_88 ( V_155 ) = * V_156 ;
F_86 ( V_156 , V_157 ) ;
F_31 () ;
if ( F_85 ( V_157 ) )
F_13 () ;
F_93 ( & V_161 ) ;
}
static void F_94 ( struct V_89 * V_129 , int V_133 ,
const void * V_156 , int type )
{
F_95 ( V_129 , V_133 , V_156 , type ) ;
F_72 () ;
switch ( type ) {
case V_162 :
case V_163 :
break;
default: {
T_5 V_123 = F_59 ( & V_129 [ V_133 ] ) ;
F_31 () ;
if ( F_73 ( V_123 . V_123 , * ( T_6 * ) V_156 ) )
F_13 () ;
}
}
F_74 () ;
}
static void T_1 F_96 ( struct V_89 * V_129 , int V_133 ,
const void * V_156 , int type )
{
F_95 ( V_129 , V_133 , V_156 , type ) ;
switch ( type ) {
case V_162 :
case V_163 :
break;
default: {
T_5 V_123 = F_97 ( & V_129 [ V_133 ] ) ;
if ( F_73 ( V_123 . V_123 , * ( T_6 * ) V_156 ) )
V_129 [ V_133 ] = * (struct V_89 * ) V_156 ;
}
}
}
static void F_98 ( struct V_164 * V_165 ,
struct V_120 * V_166 )
{
struct V_100 V_101 ;
V_101 = F_47 ( 0 ) ;
F_99 ( V_101 . V_107 , V_167 , V_166 -> V_168 ) ;
F_50 ( V_109 ) ;
}
static void F_100 ( unsigned V_169 )
{
struct V_170 V_171 ;
V_171 . V_172 = ( V_169 == 0 ) ? 1 : ( V_169 >> 12 ) & 3 ;
F_101 ( V_173 , & V_171 ) ;
}
static void F_102 ( void )
{
}
static unsigned long F_103 ( unsigned int V_174 )
{
F_79 ( 1 ) ;
return V_174 ;
}
static unsigned int F_104 ( unsigned long V_174 )
{
return ( ( V_174 ) >> 24 ) & 0xFFu ;
}
static T_8 F_105 ( T_8 V_77 )
{
struct V_50 V_51 = {
. V_52 = V_175 ,
. V_176 = V_177 ,
. V_54 . V_178 . F_18 = 0 ,
} ;
int V_179 = 0 ;
if ( ! F_21 () || F_12 () )
return 0 ;
if ( V_77 == V_180 )
return 0x10 ;
if ( V_77 != V_181 )
return 0 ;
V_179 = F_24 ( & V_51 ) ;
if ( V_179 )
return 0 ;
return V_51 . V_54 . V_178 . V_182 << 24 ;
}
static void F_106 ( T_8 V_77 , T_8 V_78 )
{
F_79 ( 1 ) ;
}
static T_6 F_107 ( void )
{
return 0 ;
}
static void F_108 ( T_8 V_183 , T_8 V_56 )
{
F_79 ( 1 ) ;
}
static void F_109 ( void )
{
return;
}
static T_8 F_110 ( void )
{
return 0 ;
}
static void F_111 ( void )
{
V_184 -> V_185 = F_105 ;
V_184 -> V_186 = F_106 ;
V_184 -> V_187 = F_107 ;
V_184 -> V_188 = F_108 ;
V_184 -> V_189 = F_109 ;
V_184 -> V_190 = F_110 ;
V_184 -> V_191 = F_103 ;
V_184 -> V_192 = F_104 ;
#ifdef F_2
V_184 -> V_193 = V_194 ;
V_184 -> V_195 = V_196 ;
V_184 -> V_197 = V_198 ;
V_184 -> V_199 = V_200 ;
V_184 -> V_201 = V_202 ;
#endif
}
static void F_112 ( void )
{
struct V_100 V_101 ;
V_101 = F_47 ( 0 ) ;
F_113 ( V_101 . V_107 , 0 ) ;
F_50 ( V_109 ) ;
}
static unsigned long F_114 ( void )
{
unsigned long V_203 = F_115 ( V_204 ) ;
if ( F_116 ( V_203 == 0 ) ) {
V_203 = F_117 () ;
F_118 ( V_204 , V_203 ) ;
}
return V_203 ;
}
static void F_119 ( unsigned long V_203 )
{
struct V_100 V_101 ;
F_118 ( V_204 , V_203 ) ;
V_101 = F_47 ( 0 ) ;
F_113 ( V_101 . V_107 , ( V_203 & V_205 ) != 0 ) ;
F_50 ( V_109 ) ;
}
static void F_120 ( unsigned long V_206 )
{
V_206 &= ~ V_207 ;
V_206 &= ~ V_208 ;
F_121 ( V_206 ) ;
}
static int F_122 ( unsigned int V_209 , unsigned V_183 , unsigned V_210 )
{
int V_179 ;
V_179 = 0 ;
switch ( V_209 ) {
#ifdef F_77
unsigned V_211 ;
T_6 V_212 ;
case V_213 : V_211 = V_214 ; goto V_215;
case V_216 : V_211 = V_217 ; goto V_215;
case V_218 : V_211 = V_219 ; goto V_215;
V_215:
V_212 = ( ( T_6 ) V_210 << 32 ) | V_183 ;
if ( F_69 ( V_211 , V_212 ) != 0 )
V_179 = - V_220 ;
break;
#endif
case V_221 :
case V_222 :
case V_223 :
case V_224 :
case V_225 :
case V_226 :
case V_227 :
break;
case V_228 :
if ( F_12 () == 0 )
F_123 ( ( ( T_6 ) V_210 << 32 ) | V_183 ) ;
break;
default:
V_179 = F_124 ( V_209 , V_183 , V_210 ) ;
}
return V_179 ;
}
void F_125 ( void )
{
if ( ! F_17 ( V_229 ) ) {
F_126 ( V_230 ,
V_231 -> V_232 ) ;
V_9 =
(struct V_232 * ) F_127 ( V_230 ) ;
} else
V_9 =
(struct V_232 * ) F_41 ( V_231 -> V_232 ) ;
#ifndef F_2
F_128 () ;
#endif
F_129 () ;
}
void F_128 ( void )
{
int V_3 ;
F_130 (cpu)
F_3 ( V_3 ) ;
if ( V_12 ) {
V_233 . V_234 = F_131 ( V_235 ) ;
V_233 . V_236 = F_131 ( V_237 ) ;
V_233 . V_238 = F_131 ( V_239 ) ;
V_233 . V_240 = F_131 ( V_241 ) ;
V_242 . V_243 = V_244 ;
}
}
static unsigned F_132 ( T_9 type , T_10 V_245 , void * V_246 ,
unsigned long V_98 , unsigned V_247 )
{
char * V_153 , * V_154 , * V_248 ;
unsigned V_179 ;
V_153 = V_154 = V_248 = NULL ;
#define F_133 ( V_51 , V_174 ) \
case PARAVIRT_PATCH(op.x): \
if (have_vcpu_info_placement) { \
start = (char *)xen_##x##_direct; \
end = xen_##x##_direct_end; \
reloc = xen_##x##_direct_reloc; \
} \
goto patch_site
switch ( type ) {
F_133 ( V_233 , V_240 ) ;
F_133 ( V_233 , V_238 ) ;
F_133 ( V_233 , V_234 ) ;
F_133 ( V_233 , V_236 ) ;
#undef F_133
V_249:
if ( V_153 == NULL || ( V_154 - V_153 ) > V_247 )
goto V_250;
V_179 = F_134 ( V_246 , V_247 , V_153 , V_154 ) ;
if ( V_248 > V_153 && V_248 < V_154 ) {
int V_251 = V_248 - V_153 ;
long * V_252 = ( long * ) ( V_246 + V_251 ) ;
long V_253 = V_153 - ( char * ) V_98 ;
* V_252 += V_253 ;
}
break;
V_250:
default:
V_179 = F_135 ( type , V_245 , V_246 ,
V_98 , V_247 ) ;
break;
}
return V_179 ;
}
static void F_136 ( int V_254 )
{
struct V_255 V_256 = { . V_254 = V_254 } ;
if ( F_137 ( V_257 , & V_256 ) )
F_13 () ;
}
static void F_138 ( char * V_258 )
{
F_136 ( V_259 ) ;
}
static void F_139 ( void )
{
F_136 ( V_259 ) ;
}
static void F_140 ( void )
{
F_136 ( V_260 ) ;
}
static void F_141 ( void )
{
if ( V_261 )
V_261 () ;
F_136 ( V_260 ) ;
}
static void F_142 ( struct V_262 * V_263 )
{
F_136 ( V_264 ) ;
}
static int
F_143 ( struct V_265 * V_266 , unsigned long V_267 , void * V_131 )
{
F_136 ( V_264 ) ;
return V_268 ;
}
int F_144 ( void )
{
F_145 ( & V_269 , & V_270 ) ;
return 0 ;
}
static void T_1 F_146 ( void )
{
V_271 . V_272 = F_96 ;
V_271 . V_273 = F_55 ;
F_147 ( 0 ) ;
F_148 ( 0 ) ;
V_271 . V_272 = F_94 ;
V_271 . V_273 = F_51 ;
}
T_11 void T_1 F_149 ( void )
{
struct V_170 V_171 ;
int V_274 ;
T_12 * V_275 ;
if ( ! V_231 )
return;
V_276 = V_277 ;
F_150 () ;
V_27 = V_278 ;
V_279 = V_280 ;
V_271 = V_281 ;
V_282 = V_283 ;
V_284 . V_285 . V_286 = V_287 ;
V_284 . V_288 . V_289 = V_290 ;
V_284 . V_288 . V_291 = F_15 ;
F_151 () ;
F_152 () ;
V_292 &= ~ V_293 ;
#if 0
if (!xen_initial_domain())
#endif
V_292 &= ~ ( V_294 | V_295 ) ;
V_292 |= V_296 ;
V_297 &= ~ V_298 ;
F_153 () ;
F_154 () ;
if ( ! F_17 ( V_229 ) )
F_155 () ;
F_146 () ;
F_156 () ;
F_25 () ;
#ifdef F_157
F_111 () ;
#endif
if ( F_17 ( V_30 ) ) {
V_242 . V_299 = V_300 ;
V_242 . V_301 = V_302 ;
}
V_303 = V_304 ;
V_305 = & F_5 ( V_306 , 0 ) ;
F_158 () ;
#ifdef F_159
V_307 = - 1 ;
#endif
V_275 = ( T_12 * ) V_231 -> V_308 ;
F_5 ( V_11 , 0 ) = & V_9 -> V_7 [ 0 ] ;
F_160 () ;
V_309 = true ;
F_161 ( L_6 ) ;
V_275 = F_162 ( V_275 , V_231 -> V_310 ) ;
F_163 () ;
#ifdef F_64
V_27 . V_311 = 1 ;
if ( F_17 ( V_312 ) )
V_27 . V_311 = 0 ;
#else
V_27 . V_311 = 0 ;
#endif
F_164 () ;
V_171 . V_172 = 1 ;
V_274 = F_101 ( V_173 , & V_171 ) ;
if ( V_274 != 0 )
F_165 ( L_7 , V_274 ) ;
#ifdef F_64
F_166 ( & V_313 ) ;
V_313 . V_314 = 1 ;
V_313 . V_315 = 1 ;
V_313 . V_316 [ 0 ] = F_167 ( 1 ) ;
#endif
V_317 . V_318 . V_319 = ( 9 << 4 ) | 0 ;
V_317 . V_318 . V_320 = V_231 -> V_321
? F_168 ( V_231 -> V_321 ) : 0 ;
V_317 . V_318 . V_322 = V_231 -> V_323 ;
V_317 . V_318 . V_324 = F_168 ( V_231 -> V_325 ) ;
if ( ! F_21 () ) {
F_169 ( L_8 , 0 , NULL ) ;
F_169 ( L_9 , 0 , NULL ) ;
F_169 ( L_10 , 0 , NULL ) ;
if ( V_326 )
V_284 . V_327 . V_328 = V_329 ;
} else {
const struct V_330 * V_5 =
( void * ) ( ( char * ) V_231 +
V_231 -> V_331 . V_332 . V_333 ) ;
F_170 ( V_5 , V_231 -> V_331 . V_332 . V_334 ) ;
V_231 -> V_331 . V_335 . V_14 = 0 ;
V_231 -> V_331 . V_335 . V_336 = 0 ;
F_171 () ;
F_172 () ;
F_173 () ;
}
#ifdef F_174
V_337 &= ~ V_338 ;
#endif
F_161 ( L_11 ) ;
F_14 ( 0 ) ;
#ifdef F_64
F_175 () ;
#else
F_176 ( ( char * ) F_177 ( & V_317 ) ) ;
#endif
}
static int F_178 ( int * V_339 , int * V_340 )
{
T_2 V_341 , V_342 , V_343 , V_344 , V_115 , V_209 , V_212 ;
T_6 V_86 ;
V_212 = F_179 () ;
F_180 ( V_212 + 1 , & V_341 , & V_342 , & V_343 , & V_344 ) ;
* V_339 = V_341 >> 16 ;
* V_340 = V_341 & 0xffff ;
F_9 ( V_26 L_12 , * V_339 , * V_340 ) ;
F_180 ( V_212 + 2 , & V_115 , & V_209 , & V_343 , & V_344 ) ;
V_86 = F_168 ( V_345 ) ;
F_181 ( V_209 , ( T_8 ) V_86 , ( T_8 ) ( V_86 >> 32 ) ) ;
F_154 () ;
V_27 . V_28 = L_13 ;
V_276 = V_346 ;
return 0 ;
}
void T_13 F_182 ( void )
{
int V_3 ;
struct V_347 V_348 ;
static struct V_232 * V_349 = 0 ;
if ( ! V_349 )
V_349 = (struct V_232 * )
F_183 ( V_93 , V_93 ) ;
V_348 . V_350 = V_108 ;
V_348 . V_127 = 0 ;
V_348 . V_351 = V_352 ;
V_348 . V_353 = F_168 ( V_349 ) >> V_354 ;
if ( F_184 ( V_355 , & V_348 ) )
F_13 () ;
V_9 = (struct V_232 * ) V_349 ;
F_11 (cpu) {
F_5 ( V_11 , V_3 ) = & V_9 -> V_7 [ V_3 ] ;
}
}
static int T_14 F_185 ( struct V_265 * V_356 ,
unsigned long V_357 , void * V_358 )
{
int V_3 = ( long ) V_358 ;
switch ( V_357 ) {
case V_359 :
F_3 ( V_3 ) ;
if ( V_360 )
F_186 ( V_3 ) ;
break;
default:
break;
}
return V_361 ;
}
static void T_1 F_187 ( void )
{
int V_256 ;
int V_339 , V_340 ;
V_256 = F_178 ( & V_339 , & V_340 ) ;
if ( V_256 < 0 )
return;
F_182 () ;
if ( F_17 ( V_362 ) )
V_360 = 1 ;
F_188 () ;
F_189 ( & V_363 ) ;
F_190 () ;
V_284 . V_364 . V_365 = V_366 ;
F_191 () ;
F_192 () ;
}
static bool T_1 F_193 ( void )
{
if ( F_194 () )
return false ;
if ( ! F_179 () )
return false ;
return true ;
}
bool F_195 ( void )
{
if ( F_194 () )
return false ;
if ( ! F_196 () )
return false ;
if ( F_17 ( V_367 ) && V_360 )
return false ;
return true ;
}
