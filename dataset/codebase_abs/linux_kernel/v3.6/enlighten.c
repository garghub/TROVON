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
( 1 << V_70 ) ) ;
if ( ! F_21 () )
V_41 &=
~ ( ( 1 << V_71 ) |
( 1 << V_72 ) ) ;
V_31 = 1 ;
V_33 = 0 ;
F_18 ( & V_31 , & V_32 , & V_33 , & V_34 ) ;
V_68 =
( 1 << ( V_73 % 32 ) ) |
( 1 << ( V_74 % 32 ) ) ;
if ( ( V_33 & V_68 ) != V_68 )
V_39 &= ~ V_68 ;
if ( F_19 () )
V_40 = ( 1 << ( V_61 % 32 ) ) ;
}
static void F_26 ( int V_75 , unsigned long V_76 )
{
F_27 ( V_75 , V_76 ) ;
}
static unsigned long F_28 ( int V_75 )
{
return F_29 ( V_75 ) ;
}
static void F_30 ( struct V_77 * V_78 )
{
F_31 () ;
F_32 ( V_78 ) ;
}
static unsigned long F_33 ( void )
{
return 0 ;
}
static void F_34 ( void * V_79 , T_3 V_80 )
{
int V_81 ;
T_4 * V_82 ;
T_4 V_83 ;
unsigned long V_84 ;
struct V_85 * V_85 ;
V_82 = F_35 ( ( unsigned long ) V_79 , & V_81 ) ;
F_4 ( V_82 == NULL ) ;
V_84 = F_36 ( * V_82 ) ;
V_85 = F_37 ( V_84 ) ;
V_83 = F_38 ( V_84 , V_80 ) ;
if ( F_39 ( ( unsigned long ) V_79 , V_83 , 0 ) )
F_13 () ;
if ( ! F_40 ( V_85 ) ) {
void * V_86 = F_41 ( F_42 ( V_84 ) ) ;
if ( V_86 != V_79 )
if ( F_39 ( ( unsigned long ) V_86 , V_83 , 0 ) )
F_13 () ;
} else
F_43 () ;
}
static void F_44 ( struct V_87 * V_88 , unsigned V_89 )
{
const unsigned V_90 = V_91 / V_92 ;
int V_93 ;
for( V_93 = 0 ; V_93 < V_89 ; V_93 += V_90 )
F_34 ( V_88 + V_93 , V_94 ) ;
}
static void F_45 ( struct V_87 * V_88 , unsigned V_89 )
{
const unsigned V_90 = V_91 / V_92 ;
int V_93 ;
for( V_93 = 0 ; V_93 < V_89 ; V_93 += V_90 )
F_34 ( V_88 + V_93 , V_95 ) ;
}
static void F_46 ( const void * V_96 , unsigned V_89 )
{
struct V_97 * V_51 ;
struct V_98 V_99 = F_47 ( sizeof( * V_51 ) ) ;
F_48 ( V_96 , V_89 ) ;
V_51 = V_99 . args ;
V_51 -> V_52 = V_100 ;
V_51 -> V_101 . V_102 = ( unsigned long ) V_96 ;
V_51 -> V_103 . V_104 = V_89 ;
F_49 ( V_99 . V_105 , V_51 , 1 , NULL , V_106 ) ;
F_50 ( V_107 ) ;
}
static void F_51 ( const struct V_108 * V_109 )
{
unsigned long V_110 = V_109 -> V_111 ;
unsigned int V_112 = V_109 -> V_112 + 1 ;
unsigned V_113 = ( V_112 + V_91 - 1 ) / V_91 ;
unsigned long V_114 [ V_113 ] ;
int V_115 ;
F_4 ( V_112 > 65536 ) ;
F_4 ( V_110 & ~ V_116 ) ;
for ( V_115 = 0 ; V_110 < V_109 -> V_111 + V_112 ; V_110 += V_91 , V_115 ++ ) {
int V_81 ;
T_4 * V_82 ;
unsigned long V_84 , V_14 ;
void * V_117 ;
V_82 = F_35 ( V_110 , & V_81 ) ;
F_4 ( V_82 == NULL ) ;
V_84 = F_36 ( * V_82 ) ;
V_14 = F_52 ( V_84 ) ;
V_117 = F_41 ( F_42 ( V_84 ) ) ;
V_114 [ V_115 ] = V_14 ;
F_53 ( ( void * ) V_110 ) ;
F_53 ( V_117 ) ;
}
if ( F_54 ( V_114 , V_112 / sizeof( struct V_87 ) ) )
F_13 () ;
}
static void T_1 F_55 ( const struct V_108 * V_109 )
{
unsigned long V_110 = V_109 -> V_111 ;
unsigned int V_112 = V_109 -> V_112 + 1 ;
unsigned V_113 = ( V_112 + V_91 - 1 ) / V_91 ;
unsigned long V_114 [ V_113 ] ;
int V_115 ;
F_4 ( V_112 > 65536 ) ;
F_4 ( V_110 & ~ V_116 ) ;
for ( V_115 = 0 ; V_110 < V_109 -> V_111 + V_112 ; V_110 += V_91 , V_115 ++ ) {
T_4 V_83 ;
unsigned long V_84 , V_14 ;
V_84 = F_56 ( V_110 ) ;
V_14 = F_52 ( V_84 ) ;
V_83 = F_38 ( V_84 , V_94 ) ;
if ( F_39 ( ( unsigned long ) V_110 , V_83 , 0 ) )
F_13 () ;
V_114 [ V_115 ] = V_14 ;
}
if ( F_54 ( V_114 , V_112 / sizeof( struct V_87 ) ) )
F_13 () ;
}
static inline bool F_57 ( const struct V_87 * V_118 ,
const struct V_87 * V_119 )
{
return V_118 -> V_120 == V_119 -> V_120 && V_118 -> V_121 == V_119 -> V_121 ;
}
static void F_58 ( struct V_122 * V_123 ,
unsigned int V_3 , unsigned int V_93 )
{
struct V_87 * V_124 = & F_5 ( V_125 , V_3 ) . V_126 [ V_93 ] ;
struct V_87 * V_127 ;
T_5 V_128 ;
struct V_98 V_105 ;
if ( F_57 ( V_124 , & V_123 -> V_129 [ V_93 ] ) )
return;
* V_124 = V_123 -> V_129 [ V_93 ] ;
V_127 = F_59 ( V_3 ) ;
V_128 = F_60 ( & V_127 [ V_130 + V_93 ] ) ;
V_105 = F_61 ( 0 ) ;
F_62 ( V_105 . V_105 , V_128 . V_128 , V_123 -> V_129 [ V_93 ] ) ;
}
static void F_63 ( struct V_122 * V_123 , unsigned int V_3 )
{
if ( F_64 () == V_107 ) {
#ifdef F_65
F_66 ( 0 ) ;
#else
F_67 ( V_131 , 0 ) ;
#endif
}
F_68 () ;
F_58 ( V_123 , V_3 , 0 ) ;
F_58 ( V_123 , V_3 , 1 ) ;
F_58 ( V_123 , V_3 , 2 ) ;
F_50 ( V_107 ) ;
}
static void F_69 ( unsigned int V_132 )
{
if ( F_70 ( V_133 , V_132 ) )
F_13 () ;
}
static void F_71 ( struct V_87 * V_134 , int V_135 ,
const void * V_136 )
{
T_5 V_137 = F_60 ( & V_134 [ V_135 ] ) ;
T_6 V_138 = * ( T_6 * ) V_136 ;
F_72 ( V_134 , V_135 , V_138 ) ;
F_73 () ;
F_31 () ;
if ( F_74 ( V_137 . V_128 , V_138 ) )
F_13 () ;
F_75 () ;
}
static int F_76 ( int V_139 , const T_7 * V_76 ,
struct V_140 * V_5 )
{
unsigned long V_96 ;
if ( V_76 -> type != V_141 && V_76 -> type != V_142 )
return 0 ;
V_5 -> V_139 = V_139 ;
V_96 = F_77 ( * V_76 ) ;
#ifdef F_78
if ( V_96 == ( unsigned long ) V_143 )
V_96 = ( unsigned long ) V_144 ;
else if ( V_96 == ( unsigned long ) V_145 )
V_96 = ( unsigned long ) V_146 ;
else if ( V_96 == ( unsigned long ) V_147 )
V_96 = ( unsigned long ) V_148 ;
else if ( V_96 == ( unsigned long ) V_149 ||
V_96 == ( unsigned long ) V_150 ) {
return 0 ;
#ifdef F_79
} else if ( V_96 == ( unsigned long ) V_151 ) {
;
#endif
} else {
if ( F_80 ( V_76 -> V_152 != 0 ) )
return 0 ;
}
#endif
V_5 -> V_111 = V_96 ;
V_5 -> V_153 = F_81 ( * V_76 ) ;
V_5 -> V_154 = V_76 -> V_155 ;
if ( V_76 -> type == V_142 )
V_5 -> V_154 |= 1 << 2 ;
return 1 ;
}
static void F_82 ( T_7 * V_134 , int V_135 , const T_7 * V_156 )
{
unsigned long V_157 = ( unsigned long ) & V_134 [ V_135 ] ;
unsigned long V_158 , V_159 ;
F_83 ( V_134 , V_135 , V_156 ) ;
F_73 () ;
V_158 = F_84 ( V_160 . V_111 ) ;
V_159 = V_158 + F_84 ( V_160 . V_112 ) + 1 ;
F_31 () ;
F_85 ( V_134 , V_135 , V_156 ) ;
if ( V_157 >= V_158 && ( V_157 + 8 ) <= V_159 ) {
struct V_140 V_5 [ 2 ] ;
V_5 [ 1 ] . V_111 = 0 ;
if ( F_76 ( V_135 , V_156 , & V_5 [ 0 ] ) )
if ( F_86 ( V_5 ) )
F_13 () ;
}
F_75 () ;
}
static void F_87 ( const struct V_108 * V_126 ,
struct V_140 * V_161 )
{
unsigned V_162 , V_163 , V_164 ;
V_164 = ( V_126 -> V_112 + 1 ) / sizeof( T_7 ) ;
F_4 ( V_164 > 256 ) ;
for ( V_162 = V_163 = 0 ; V_162 < V_164 ; V_162 ++ ) {
T_7 * V_138 = ( T_7 * ) ( V_126 -> V_111 ) + V_162 ;
if ( F_76 ( V_162 , V_138 , & V_161 [ V_163 ] ) )
V_163 ++ ;
}
V_161 [ V_163 ] . V_111 = 0 ;
}
void F_88 ( struct V_140 * V_161 )
{
const struct V_108 * V_126 = & F_89 ( V_160 ) ;
F_87 ( V_126 , V_161 ) ;
}
static void F_90 ( const struct V_108 * V_126 )
{
static F_91 ( V_165 ) ;
static struct V_140 V_161 [ 257 ] ;
F_92 ( V_126 ) ;
F_93 ( & V_165 ) ;
F_89 ( V_160 ) = * V_126 ;
F_87 ( V_126 , V_161 ) ;
F_31 () ;
if ( F_86 ( V_161 ) )
F_13 () ;
F_94 ( & V_165 ) ;
}
static void F_95 ( struct V_87 * V_134 , int V_138 ,
const void * V_126 , int type )
{
F_96 ( V_134 , V_138 , V_126 , type ) ;
F_73 () ;
switch ( type ) {
case V_166 :
case V_167 :
break;
default: {
T_5 V_128 = F_60 ( & V_134 [ V_138 ] ) ;
F_31 () ;
if ( F_74 ( V_128 . V_128 , * ( T_6 * ) V_126 ) )
F_13 () ;
}
}
F_75 () ;
}
static void T_1 F_97 ( struct V_87 * V_134 , int V_138 ,
const void * V_126 , int type )
{
F_96 ( V_134 , V_138 , V_126 , type ) ;
switch ( type ) {
case V_166 :
case V_167 :
break;
default: {
T_5 V_128 = F_98 ( & V_134 [ V_138 ] ) ;
if ( F_74 ( V_128 . V_128 , * ( T_6 * ) V_126 ) )
V_134 [ V_138 ] = * (struct V_87 * ) V_126 ;
}
}
}
static void F_99 ( struct V_168 * V_169 ,
struct V_122 * V_170 )
{
struct V_98 V_99 ;
V_99 = F_47 ( 0 ) ;
F_100 ( V_99 . V_105 , V_171 , V_170 -> V_172 ) ;
F_50 ( V_107 ) ;
}
static void F_101 ( unsigned V_173 )
{
struct V_174 V_175 ;
V_175 . V_176 = ( V_173 == 0 ) ? 1 : ( V_173 >> 12 ) & 3 ;
F_102 ( V_177 , & V_175 ) ;
}
static void F_103 ( void )
{
}
static unsigned long F_104 ( unsigned int V_178 )
{
F_80 ( 1 ) ;
return V_178 ;
}
static unsigned int F_105 ( unsigned long V_178 )
{
return ( ( V_178 ) >> 24 ) & 0xFFu ;
}
static T_8 F_106 ( T_8 V_75 )
{
struct V_50 V_51 = {
. V_52 = V_179 ,
. V_180 = V_181 ,
. V_54 . V_182 . F_18 = 0 ,
} ;
int V_183 = 0 ;
if ( ! F_21 () || F_12 () )
return 0 ;
if ( V_75 == V_184 )
return 0x10 ;
if ( V_75 != V_185 )
return 0 ;
V_183 = F_24 ( & V_51 ) ;
if ( V_183 )
return 0 ;
return V_51 . V_54 . V_182 . V_186 << 24 ;
}
static void F_107 ( T_8 V_75 , T_8 V_76 )
{
F_80 ( 1 ) ;
}
static T_6 F_108 ( void )
{
return 0 ;
}
static void F_109 ( T_8 V_187 , T_8 V_56 )
{
F_80 ( 1 ) ;
}
static void F_110 ( void )
{
return;
}
static T_8 F_111 ( void )
{
return 0 ;
}
static void F_112 ( void )
{
V_188 -> V_189 = F_106 ;
V_188 -> V_190 = F_107 ;
V_188 -> V_191 = F_108 ;
V_188 -> V_192 = F_109 ;
V_188 -> V_193 = F_110 ;
V_188 -> V_194 = F_111 ;
V_188 -> V_195 = F_104 ;
V_188 -> V_196 = F_105 ;
#ifdef F_2
V_188 -> V_197 = V_198 ;
V_188 -> V_199 = V_200 ;
V_188 -> V_201 = V_202 ;
V_188 -> V_203 = V_204 ;
V_188 -> V_205 = V_206 ;
#endif
}
static void F_113 ( void )
{
struct V_98 V_99 ;
V_99 = F_47 ( 0 ) ;
F_114 ( V_99 . V_105 , 0 ) ;
F_50 ( V_107 ) ;
}
static unsigned long F_115 ( void )
{
unsigned long V_207 = F_116 ( V_208 ) ;
if ( F_117 ( V_207 == 0 ) ) {
V_207 = F_118 () ;
F_119 ( V_208 , V_207 ) ;
}
return V_207 ;
}
static void F_120 ( unsigned long V_207 )
{
struct V_98 V_99 ;
F_119 ( V_208 , V_207 ) ;
V_99 = F_47 ( 0 ) ;
F_114 ( V_99 . V_105 , ( V_207 & V_209 ) != 0 ) ;
F_50 ( V_107 ) ;
}
static void F_121 ( unsigned long V_210 )
{
V_210 &= ~ V_211 ;
V_210 &= ~ V_212 ;
F_122 ( V_210 ) ;
}
static int F_123 ( unsigned int V_213 , unsigned V_187 , unsigned V_214 )
{
int V_183 ;
V_183 = 0 ;
switch ( V_213 ) {
#ifdef F_78
unsigned V_215 ;
T_6 V_216 ;
case V_217 : V_215 = V_218 ; goto V_219;
case V_220 : V_215 = V_221 ; goto V_219;
case V_222 : V_215 = V_223 ; goto V_219;
V_219:
V_216 = ( ( T_6 ) V_214 << 32 ) | V_187 ;
if ( F_70 ( V_215 , V_216 ) != 0 )
V_183 = - V_224 ;
break;
#endif
case V_225 :
case V_226 :
case V_227 :
case V_228 :
case V_229 :
case V_230 :
case V_231 :
break;
case V_232 :
if ( F_12 () == 0 )
F_124 ( ( ( T_6 ) V_214 << 32 ) | V_187 ) ;
break;
default:
V_183 = F_125 ( V_213 , V_187 , V_214 ) ;
}
return V_183 ;
}
void F_126 ( void )
{
if ( ! F_17 ( V_233 ) ) {
F_127 ( V_234 ,
V_235 -> V_236 ) ;
V_9 =
(struct V_236 * ) F_128 ( V_234 ) ;
} else
V_9 =
(struct V_236 * ) F_41 ( V_235 -> V_236 ) ;
#ifndef F_2
F_129 () ;
#endif
F_130 () ;
}
void F_129 ( void )
{
int V_3 ;
F_131 (cpu)
F_3 ( V_3 ) ;
if ( V_12 ) {
V_237 . V_238 = F_132 ( V_239 ) ;
V_237 . V_240 = F_132 ( V_241 ) ;
V_237 . V_242 = F_132 ( V_243 ) ;
V_237 . V_244 = F_132 ( V_245 ) ;
V_246 . V_247 = V_248 ;
}
}
static unsigned F_133 ( T_9 type , T_10 V_249 , void * V_250 ,
unsigned long V_96 , unsigned V_251 )
{
char * V_158 , * V_159 , * V_252 ;
unsigned V_183 ;
V_158 = V_159 = V_252 = NULL ;
#define F_134 ( V_51 , V_178 ) \
case PARAVIRT_PATCH(op.x): \
if (have_vcpu_info_placement) { \
start = (char *)xen_##x##_direct; \
end = xen_##x##_direct_end; \
reloc = xen_##x##_direct_reloc; \
} \
goto patch_site
switch ( type ) {
F_134 ( V_237 , V_244 ) ;
F_134 ( V_237 , V_242 ) ;
F_134 ( V_237 , V_238 ) ;
F_134 ( V_237 , V_240 ) ;
#undef F_134
V_253:
if ( V_158 == NULL || ( V_159 - V_158 ) > V_251 )
goto V_254;
V_183 = F_135 ( V_250 , V_251 , V_158 , V_159 ) ;
if ( V_252 > V_158 && V_252 < V_159 ) {
int V_255 = V_252 - V_158 ;
long * V_256 = ( long * ) ( V_250 + V_255 ) ;
long V_257 = V_158 - ( char * ) V_96 ;
* V_256 += V_257 ;
}
break;
V_254:
default:
V_183 = F_136 ( type , V_249 , V_250 ,
V_96 , V_251 ) ;
break;
}
return V_183 ;
}
static void F_137 ( int V_258 )
{
struct V_259 V_260 = { . V_258 = V_258 } ;
if ( F_138 ( V_261 , & V_260 ) )
F_13 () ;
}
static void F_139 ( char * V_262 )
{
F_137 ( V_263 ) ;
}
static void F_140 ( void )
{
F_137 ( V_263 ) ;
}
static void F_141 ( void )
{
F_137 ( V_264 ) ;
}
static void F_142 ( void )
{
if ( V_265 )
V_265 () ;
F_137 ( V_264 ) ;
}
static void F_143 ( struct V_266 * V_267 )
{
F_137 ( V_268 ) ;
}
static int
F_144 ( struct V_269 * V_270 , unsigned long V_271 , void * V_136 )
{
F_137 ( V_268 ) ;
return V_272 ;
}
int F_145 ( void )
{
F_146 ( & V_273 , & V_274 ) ;
return 0 ;
}
static void T_1 F_147 ( void )
{
V_275 . V_276 = F_97 ;
V_275 . V_277 = F_55 ;
F_148 ( 0 ) ;
F_149 ( 0 ) ;
V_275 . V_276 = F_95 ;
V_275 . V_277 = F_51 ;
}
T_11 void T_1 F_150 ( void )
{
struct V_174 V_175 ;
int V_278 ;
T_12 * V_279 ;
if ( ! V_235 )
return;
V_280 = V_281 ;
F_151 () ;
V_27 = V_282 ;
V_283 = V_284 ;
V_275 = V_285 ;
V_286 = V_287 ;
V_288 . V_289 . V_290 = V_291 ;
V_288 . V_292 . V_293 = V_294 ;
V_288 . V_292 . V_295 = F_15 ;
F_152 () ;
F_153 () ;
V_296 &= ~ V_297 ;
#if 0
if (!xen_initial_domain())
#endif
V_296 &= ~ ( V_298 | V_299 ) ;
V_296 |= V_300 ;
V_301 &= ~ V_302 ;
F_154 () ;
F_155 () ;
if ( ! F_17 ( V_233 ) )
F_156 () ;
F_147 () ;
F_157 () ;
F_25 () ;
#ifdef F_158
F_112 () ;
#endif
if ( F_17 ( V_30 ) ) {
V_246 . V_303 = V_304 ;
V_246 . V_305 = V_306 ;
}
V_307 = V_308 ;
V_309 = & F_5 ( V_310 , 0 ) ;
F_159 () ;
#ifdef F_160
V_311 = - 1 ;
#endif
V_279 = ( T_12 * ) V_235 -> V_312 ;
F_5 ( V_11 , 0 ) = & V_9 -> V_7 [ 0 ] ;
F_161 () ;
V_313 = true ;
F_162 ( L_6 ) ;
V_279 = F_163 ( V_279 , V_235 -> V_314 ) ;
F_164 () ;
#ifdef F_65
V_27 . V_315 = 1 ;
if ( F_17 ( V_316 ) )
V_27 . V_315 = 0 ;
#else
V_27 . V_315 = 0 ;
#endif
F_165 () ;
V_175 . V_176 = 1 ;
V_278 = F_102 ( V_177 , & V_175 ) ;
if ( V_278 != 0 )
F_166 ( L_7 , V_278 ) ;
#ifdef F_65
F_167 ( & V_317 ) ;
V_317 . V_318 = 1 ;
V_317 . V_319 = 1 ;
V_317 . V_320 [ 0 ] = F_168 ( 1 ) ;
#endif
V_321 . V_322 . V_323 = ( 9 << 4 ) | 0 ;
V_321 . V_322 . V_324 = V_235 -> V_325
? F_169 ( V_235 -> V_325 ) : 0 ;
V_321 . V_322 . V_326 = V_235 -> V_327 ;
V_321 . V_322 . V_328 = F_169 ( V_235 -> V_329 ) ;
if ( ! F_21 () ) {
F_170 ( L_8 , 0 , NULL ) ;
F_170 ( L_9 , 0 , NULL ) ;
F_170 ( L_10 , 0 , NULL ) ;
if ( V_330 )
V_288 . V_331 . V_332 = V_333 ;
} else {
const struct V_334 * V_5 =
( void * ) ( ( char * ) V_235 +
V_235 -> V_335 . V_336 . V_337 ) ;
F_171 ( V_5 , V_235 -> V_335 . V_336 . V_338 ) ;
V_235 -> V_335 . V_339 . V_14 = 0 ;
V_235 -> V_335 . V_339 . V_340 = 0 ;
F_172 () ;
F_173 () ;
F_174 () ;
V_288 . V_341 . V_342 = V_343 ;
V_288 . V_341 . V_344 = V_345 ;
}
#ifdef F_175
V_346 &= ~ V_347 ;
#endif
F_162 ( L_11 ) ;
F_14 ( 0 ) ;
#ifdef F_65
F_176 () ;
#else
F_177 ( ( char * ) F_178 ( & V_321 ) ) ;
#endif
}
void T_13 F_179 ( void )
{
int V_3 ;
struct V_348 V_349 ;
static struct V_236 * V_350 = 0 ;
if ( ! V_350 )
V_350 = (struct V_236 * )
F_180 ( V_91 , V_91 ) ;
V_349 . V_351 = V_106 ;
V_349 . V_132 = 0 ;
V_349 . V_352 = V_353 ;
V_349 . V_354 = F_169 ( V_350 ) >> V_355 ;
if ( F_181 ( V_356 , & V_349 ) )
F_13 () ;
V_9 = (struct V_236 * ) V_350 ;
F_11 (cpu) {
F_5 ( V_11 , V_3 ) = & V_9 -> V_7 [ V_3 ] ;
}
}
static void T_1 F_182 ( void )
{
int V_357 , V_358 ;
T_2 V_359 , V_360 , V_361 , V_362 , V_113 , V_213 , V_216 ;
T_6 V_84 ;
V_216 = F_183 () ;
F_184 ( V_216 + 1 , & V_359 , & V_360 , & V_361 , & V_362 ) ;
V_357 = V_359 >> 16 ;
V_358 = V_359 & 0xffff ;
F_9 ( V_26 L_12 , V_357 , V_358 ) ;
F_184 ( V_216 + 2 , & V_113 , & V_213 , & V_361 , & V_362 ) ;
V_84 = F_169 ( V_363 ) ;
F_185 ( V_213 , ( T_8 ) V_84 , ( T_8 ) ( V_84 >> 32 ) ) ;
F_155 () ;
V_27 . V_28 = L_13 ;
V_280 = V_364 ;
}
static int T_14 F_186 ( struct V_269 * V_365 ,
unsigned long V_366 , void * V_367 )
{
int V_3 = ( long ) V_367 ;
switch ( V_366 ) {
case V_368 :
F_3 ( V_3 ) ;
if ( V_369 )
F_187 ( V_3 ) ;
break;
default:
break;
}
return V_370 ;
}
static void T_1 F_188 ( void )
{
F_182 () ;
F_179 () ;
if ( F_17 ( V_371 ) )
V_369 = 1 ;
F_189 () ;
F_190 ( & V_372 ) ;
F_191 () ;
V_288 . V_373 . V_374 = V_375 ;
F_192 () ;
F_193 () ;
}
static bool T_1 F_194 ( void )
{
if ( F_195 () )
return false ;
if ( ! F_183 () )
return false ;
return true ;
}
bool F_196 ( void )
{
if ( F_195 () )
return false ;
if ( ! F_197 () )
return false ;
if ( F_17 ( V_376 ) && V_369 )
return false ;
return true ;
}
