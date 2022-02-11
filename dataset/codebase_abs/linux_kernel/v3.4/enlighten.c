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
#if F_20 ( V_45 ) && ! F_20 ( V_46 ) && \
! F_20 ( V_47 )
struct V_48 V_49 = {
. V_50 = V_51 ,
. V_52 . V_53 . V_54 = - 1 ,
. V_52 . V_53 . type = V_55 ,
} ;
T_2 V_56 [ 3 ] ;
unsigned int V_31 , V_32 , V_33 , V_34 ;
unsigned int V_57 ;
if ( ! F_21 () )
return false ;
V_31 = 1 ;
V_33 = 0 ;
F_22 ( & V_31 , & V_32 , & V_33 , & V_34 ) ;
V_57 = ( 1 << ( V_58 % 32 ) ) |
( 1 << ( V_59 % 32 ) ) ;
if ( ( V_33 & V_57 ) != V_57 )
return false ;
V_31 = V_42 ;
V_32 = 0 ;
V_33 = 0 ;
V_34 = 0 ;
F_22 ( & V_31 , & V_32 , & V_33 , & V_34 ) ;
V_56 [ 0 ] = V_60 ;
V_56 [ 1 ] = 1 ;
V_56 [ 2 ] = ( V_61 | V_62 ) ;
F_23 ( V_49 . V_52 . V_53 . V_63 , V_56 ) ;
if ( ( F_24 ( & V_49 ) == 0 ) &&
( V_56 [ 2 ] & ( V_64 | V_65 ) ) ) {
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
unsigned int V_66 ;
V_41 =
~ ( ( 1 << V_67 ) |
( 1 << V_68 ) |
( 1 << V_69 ) |
( 1 << V_70 ) ) ;
if ( ! F_21 () )
V_41 &=
~ ( ( 1 << V_71 ) |
( 1 << V_72 ) ) ;
V_31 = 1 ;
V_33 = 0 ;
F_18 ( & V_31 , & V_32 , & V_33 , & V_34 ) ;
V_66 =
( 1 << ( V_73 % 32 ) ) |
( 1 << ( V_74 % 32 ) ) ;
if ( ( V_33 & V_66 ) != V_66 )
V_39 &= ~ V_66 ;
if ( F_19 () )
V_40 = ( 1 << ( V_59 % 32 ) ) ;
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
struct V_97 * V_49 ;
struct V_98 V_99 = F_47 ( sizeof( * V_49 ) ) ;
F_48 ( V_96 , V_89 ) ;
V_49 = V_99 . args ;
V_49 -> V_50 = V_100 ;
V_49 -> V_101 . V_102 = ( unsigned long ) V_96 ;
V_49 -> V_103 . V_104 = V_89 ;
F_49 ( V_99 . V_105 , V_49 , 1 , NULL , V_106 ) ;
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
static void F_57 ( struct V_118 * V_119 ,
unsigned int V_3 , unsigned int V_93 )
{
struct V_87 * V_120 = F_58 ( V_3 ) ;
T_5 V_121 = F_59 ( & V_120 [ V_122 + V_93 ] ) ;
struct V_98 V_105 = F_60 ( 0 ) ;
F_61 ( V_105 . V_105 , V_121 . V_121 , V_119 -> V_123 [ V_93 ] ) ;
}
static void F_62 ( struct V_118 * V_119 , unsigned int V_3 )
{
if ( F_63 () == V_107 ) {
#ifdef F_64
F_65 ( 0 ) ;
#else
F_66 ( V_124 , 0 ) ;
#endif
}
F_67 () ;
F_57 ( V_119 , V_3 , 0 ) ;
F_57 ( V_119 , V_3 , 1 ) ;
F_57 ( V_119 , V_3 , 2 ) ;
F_50 ( V_107 ) ;
}
static void F_68 ( unsigned int V_125 )
{
if ( F_69 ( V_126 , V_125 ) )
F_13 () ;
}
static void F_70 ( struct V_87 * V_127 , int V_128 ,
const void * V_129 )
{
T_5 V_130 = F_59 ( & V_127 [ V_128 ] ) ;
T_6 V_131 = * ( T_6 * ) V_129 ;
F_71 ( V_127 , V_128 , V_131 ) ;
F_72 () ;
F_31 () ;
if ( F_73 ( V_130 . V_121 , V_131 ) )
F_13 () ;
F_74 () ;
}
static int F_75 ( int V_132 , const T_7 * V_76 ,
struct V_133 * V_5 )
{
unsigned long V_96 ;
if ( V_76 -> type != V_134 && V_76 -> type != V_135 )
return 0 ;
V_5 -> V_132 = V_132 ;
V_96 = F_76 ( * V_76 ) ;
#ifdef F_77
if ( V_96 == ( unsigned long ) V_136 )
V_96 = ( unsigned long ) V_137 ;
else if ( V_96 == ( unsigned long ) V_138 )
V_96 = ( unsigned long ) V_139 ;
else if ( V_96 == ( unsigned long ) V_140 )
V_96 = ( unsigned long ) V_141 ;
else if ( V_96 == ( unsigned long ) V_142 ||
V_96 == ( unsigned long ) V_143 ) {
return 0 ;
#ifdef F_78
} else if ( V_96 == ( unsigned long ) V_144 ) {
return 0 ;
#endif
} else {
if ( F_79 ( V_76 -> V_145 != 0 ) )
return 0 ;
}
#endif
V_5 -> V_111 = V_96 ;
V_5 -> V_146 = F_80 ( * V_76 ) ;
V_5 -> V_147 = V_76 -> V_148 ;
if ( V_76 -> type == V_135 )
V_5 -> V_147 |= 1 << 2 ;
return 1 ;
}
static void F_81 ( T_7 * V_127 , int V_128 , const T_7 * V_149 )
{
unsigned long V_150 = ( unsigned long ) & V_127 [ V_128 ] ;
unsigned long V_151 , V_152 ;
F_82 ( V_127 , V_128 , V_149 ) ;
F_72 () ;
V_151 = F_83 ( V_153 . V_111 ) ;
V_152 = V_151 + F_83 ( V_153 . V_112 ) + 1 ;
F_31 () ;
F_84 ( V_127 , V_128 , V_149 ) ;
if ( V_150 >= V_151 && ( V_150 + 8 ) <= V_152 ) {
struct V_133 V_5 [ 2 ] ;
V_5 [ 1 ] . V_111 = 0 ;
if ( F_75 ( V_128 , V_149 , & V_5 [ 0 ] ) )
if ( F_85 ( V_5 ) )
F_13 () ;
}
F_74 () ;
}
static void F_86 ( const struct V_108 * V_154 ,
struct V_133 * V_155 )
{
unsigned V_156 , V_157 , V_158 ;
V_158 = ( V_154 -> V_112 + 1 ) / sizeof( T_7 ) ;
F_4 ( V_158 > 256 ) ;
for ( V_156 = V_157 = 0 ; V_156 < V_158 ; V_156 ++ ) {
T_7 * V_131 = ( T_7 * ) ( V_154 -> V_111 ) + V_156 ;
if ( F_75 ( V_156 , V_131 , & V_155 [ V_157 ] ) )
V_157 ++ ;
}
V_155 [ V_157 ] . V_111 = 0 ;
}
void F_87 ( struct V_133 * V_155 )
{
const struct V_108 * V_154 = & F_88 ( V_153 ) ;
F_86 ( V_154 , V_155 ) ;
}
static void F_89 ( const struct V_108 * V_154 )
{
static F_90 ( V_159 ) ;
static struct V_133 V_155 [ 257 ] ;
F_91 ( V_154 ) ;
F_92 ( & V_159 ) ;
F_88 ( V_153 ) = * V_154 ;
F_86 ( V_154 , V_155 ) ;
F_31 () ;
if ( F_85 ( V_155 ) )
F_13 () ;
F_93 ( & V_159 ) ;
}
static void F_94 ( struct V_87 * V_127 , int V_131 ,
const void * V_154 , int type )
{
F_95 ( V_127 , V_131 , V_154 , type ) ;
F_72 () ;
switch ( type ) {
case V_160 :
case V_161 :
break;
default: {
T_5 V_121 = F_59 ( & V_127 [ V_131 ] ) ;
F_31 () ;
if ( F_73 ( V_121 . V_121 , * ( T_6 * ) V_154 ) )
F_13 () ;
}
}
F_74 () ;
}
static void T_1 F_96 ( struct V_87 * V_127 , int V_131 ,
const void * V_154 , int type )
{
F_95 ( V_127 , V_131 , V_154 , type ) ;
switch ( type ) {
case V_160 :
case V_161 :
break;
default: {
T_5 V_121 = F_97 ( & V_127 [ V_131 ] ) ;
if ( F_73 ( V_121 . V_121 , * ( T_6 * ) V_154 ) )
V_127 [ V_131 ] = * (struct V_87 * ) V_154 ;
}
}
}
static void F_98 ( struct V_162 * V_163 ,
struct V_118 * V_164 )
{
struct V_98 V_99 ;
V_99 = F_47 ( 0 ) ;
F_99 ( V_99 . V_105 , V_165 , V_164 -> V_166 ) ;
F_50 ( V_107 ) ;
}
static void F_100 ( unsigned V_167 )
{
struct V_168 V_169 ;
V_169 . V_170 = ( V_167 == 0 ) ? 1 : ( V_167 >> 12 ) & 3 ;
F_101 ( V_171 , & V_169 ) ;
}
static void F_102 ( void )
{
}
static unsigned long F_103 ( unsigned int V_172 )
{
F_79 ( 1 ) ;
return V_172 ;
}
static unsigned int F_104 ( unsigned long V_172 )
{
return ( ( V_172 ) >> 24 ) & 0xFFu ;
}
static T_8 F_105 ( T_8 V_75 )
{
struct V_48 V_49 = {
. V_50 = V_173 ,
. V_174 = V_175 ,
. V_52 . V_176 . F_18 = 0 ,
} ;
int V_177 = 0 ;
if ( ! F_21 () || F_12 () )
return 0 ;
if ( V_75 == V_178 )
return 0x10 ;
if ( V_75 != V_179 )
return 0 ;
V_177 = F_24 ( & V_49 ) ;
if ( V_177 )
return 0 ;
return V_49 . V_52 . V_176 . V_180 << 24 ;
}
static void F_106 ( T_8 V_75 , T_8 V_76 )
{
F_79 ( 1 ) ;
}
static T_6 F_107 ( void )
{
return 0 ;
}
static void F_108 ( T_8 V_181 , T_8 V_54 )
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
V_182 -> V_183 = F_105 ;
V_182 -> V_184 = F_106 ;
V_182 -> V_185 = F_107 ;
V_182 -> V_186 = F_108 ;
V_182 -> V_187 = F_109 ;
V_182 -> V_188 = F_110 ;
V_182 -> V_189 = F_103 ;
V_182 -> V_190 = F_104 ;
}
static void F_112 ( void )
{
struct V_98 V_99 ;
V_99 = F_47 ( 0 ) ;
F_113 ( V_99 . V_105 , 0 ) ;
F_50 ( V_107 ) ;
}
static unsigned long F_114 ( void )
{
unsigned long V_191 = F_115 ( V_192 ) ;
if ( F_116 ( V_191 == 0 ) ) {
V_191 = F_117 () ;
F_118 ( V_192 , V_191 ) ;
}
return V_191 ;
}
static void F_119 ( unsigned long V_191 )
{
struct V_98 V_99 ;
F_118 ( V_192 , V_191 ) ;
V_99 = F_47 ( 0 ) ;
F_113 ( V_99 . V_105 , ( V_191 & V_193 ) != 0 ) ;
F_50 ( V_107 ) ;
}
static void F_120 ( unsigned long V_194 )
{
V_194 &= ~ V_195 ;
V_194 &= ~ V_196 ;
F_121 ( V_194 ) ;
}
static int F_122 ( unsigned int V_197 , unsigned V_181 , unsigned V_198 )
{
int V_177 ;
V_177 = 0 ;
switch ( V_197 ) {
#ifdef F_77
unsigned V_199 ;
T_6 V_200 ;
case V_201 : V_199 = V_202 ; goto V_203;
case V_204 : V_199 = V_205 ; goto V_203;
case V_206 : V_199 = V_207 ; goto V_203;
V_203:
V_200 = ( ( T_6 ) V_198 << 32 ) | V_181 ;
if ( F_69 ( V_199 , V_200 ) != 0 )
V_177 = - V_208 ;
break;
#endif
case V_209 :
case V_210 :
case V_211 :
case V_212 :
case V_213 :
case V_214 :
case V_215 :
break;
case V_216 :
if ( F_12 () == 0 )
F_123 ( ( ( T_6 ) V_198 << 32 ) | V_181 ) ;
break;
default:
V_177 = F_124 ( V_197 , V_181 , V_198 ) ;
}
return V_177 ;
}
void F_125 ( void )
{
if ( ! F_17 ( V_217 ) ) {
F_126 ( V_218 ,
V_219 -> V_220 ) ;
V_9 =
(struct V_220 * ) F_127 ( V_218 ) ;
} else
V_9 =
(struct V_220 * ) F_41 ( V_219 -> V_220 ) ;
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
V_221 . V_222 = F_131 ( V_223 ) ;
V_221 . V_224 = F_131 ( V_225 ) ;
V_221 . V_226 = F_131 ( V_227 ) ;
V_221 . V_228 = F_131 ( V_229 ) ;
V_230 . V_231 = V_232 ;
}
}
static unsigned F_132 ( T_9 type , T_10 V_233 , void * V_234 ,
unsigned long V_96 , unsigned V_235 )
{
char * V_151 , * V_152 , * V_236 ;
unsigned V_177 ;
V_151 = V_152 = V_236 = NULL ;
#define F_133 ( V_49 , V_172 ) \
case PARAVIRT_PATCH(op.x): \
if (have_vcpu_info_placement) { \
start = (char *)xen_##x##_direct; \
end = xen_##x##_direct_end; \
reloc = xen_##x##_direct_reloc; \
} \
goto patch_site
switch ( type ) {
F_133 ( V_221 , V_228 ) ;
F_133 ( V_221 , V_226 ) ;
F_133 ( V_221 , V_222 ) ;
F_133 ( V_221 , V_224 ) ;
#undef F_133
V_237:
if ( V_151 == NULL || ( V_152 - V_151 ) > V_235 )
goto V_238;
V_177 = F_134 ( V_234 , V_235 , V_151 , V_152 ) ;
if ( V_236 > V_151 && V_236 < V_152 ) {
int V_239 = V_236 - V_151 ;
long * V_240 = ( long * ) ( V_234 + V_239 ) ;
long V_241 = V_151 - ( char * ) V_96 ;
* V_240 += V_241 ;
}
break;
V_238:
default:
V_177 = F_135 ( type , V_233 , V_234 ,
V_96 , V_235 ) ;
break;
}
return V_177 ;
}
static void F_136 ( int V_242 )
{
struct V_243 V_244 = { . V_242 = V_242 } ;
if ( F_137 ( V_245 , & V_244 ) )
F_13 () ;
}
static void F_138 ( char * V_246 )
{
F_136 ( V_247 ) ;
}
static void F_139 ( void )
{
F_136 ( V_247 ) ;
}
static void F_140 ( void )
{
F_136 ( V_248 ) ;
}
static void F_141 ( void )
{
if ( V_249 )
V_249 () ;
F_136 ( V_248 ) ;
}
static void F_142 ( struct V_250 * V_251 )
{
F_136 ( V_252 ) ;
}
static int
F_143 ( struct V_253 * V_254 , unsigned long V_255 , void * V_129 )
{
F_136 ( V_252 ) ;
return V_256 ;
}
int F_144 ( void )
{
F_145 ( & V_257 , & V_258 ) ;
return 0 ;
}
static void T_1 F_146 ( void )
{
V_259 . V_260 = F_96 ;
V_259 . V_261 = F_55 ;
F_147 ( 0 ) ;
F_148 ( 0 ) ;
V_259 . V_260 = F_94 ;
V_259 . V_261 = F_51 ;
}
T_11 void T_1 F_149 ( void )
{
struct V_168 V_169 ;
int V_262 ;
T_12 * V_263 ;
if ( ! V_219 )
return;
V_264 = V_265 ;
F_150 () ;
V_27 = V_266 ;
V_267 = V_268 ;
V_259 = V_269 ;
V_270 = V_271 ;
V_272 . V_273 . V_274 = V_275 ;
V_272 . V_276 . V_277 = V_278 ;
V_272 . V_276 . V_279 = F_15 ;
F_151 () ;
F_152 () ;
V_280 &= ~ V_281 ;
#if 0
if (!xen_initial_domain())
#endif
V_280 &= ~ ( V_282 | V_283 ) ;
V_280 |= V_284 ;
V_285 &= ~ V_286 ;
F_153 () ;
F_154 () ;
if ( ! F_17 ( V_217 ) )
F_155 () ;
F_146 () ;
F_156 () ;
F_25 () ;
#ifdef F_157
F_111 () ;
#endif
if ( F_17 ( V_30 ) ) {
V_230 . V_287 = V_288 ;
V_230 . V_289 = V_290 ;
}
V_291 = V_292 ;
V_293 = & F_5 ( V_294 , 0 ) ;
F_158 () ;
#ifdef F_159
V_295 = - 1 ;
#endif
V_263 = ( T_12 * ) V_219 -> V_296 ;
F_5 ( V_11 , 0 ) = & V_9 -> V_7 [ 0 ] ;
F_160 () ;
V_297 = true ;
F_161 ( L_6 ) ;
V_263 = F_162 ( V_263 , V_219 -> V_298 ) ;
F_163 () ;
F_164 () ;
#ifdef F_64
V_27 . V_299 = 1 ;
if ( F_17 ( V_300 ) )
V_27 . V_299 = 0 ;
#else
V_27 . V_299 = 0 ;
#endif
F_165 () ;
V_169 . V_170 = 1 ;
V_262 = F_101 ( V_171 , & V_169 ) ;
if ( V_262 != 0 )
F_166 ( L_7 , V_262 ) ;
#ifdef F_64
F_167 ( & V_301 ) ;
V_301 . V_302 = 1 ;
V_301 . V_303 = 1 ;
V_301 . V_304 [ 0 ] = F_168 ( 1 ) ;
#endif
V_305 . V_306 . V_307 = ( 9 << 4 ) | 0 ;
V_305 . V_306 . V_308 = V_219 -> V_309
? F_169 ( V_219 -> V_309 ) : 0 ;
V_305 . V_306 . V_310 = V_219 -> V_311 ;
V_305 . V_306 . V_312 = F_169 ( V_219 -> V_313 ) ;
if ( ! F_21 () ) {
F_170 ( L_8 , 0 , NULL ) ;
F_170 ( L_9 , 0 , NULL ) ;
F_170 ( L_10 , 0 , NULL ) ;
if ( V_314 )
V_272 . V_315 . V_316 = V_317 ;
} else {
const struct V_318 * V_5 =
( void * ) ( ( char * ) V_219 +
V_219 -> V_319 . V_320 . V_321 ) ;
F_171 ( V_5 , V_219 -> V_319 . V_320 . V_322 ) ;
V_219 -> V_319 . V_323 . V_14 = 0 ;
V_219 -> V_319 . V_323 . V_324 = 0 ;
F_172 () ;
}
#ifdef F_173
V_325 &= ~ V_326 ;
#endif
F_161 ( L_11 ) ;
F_14 ( 0 ) ;
#ifdef F_64
F_174 () ;
#else
F_175 ( ( char * ) F_176 ( & V_305 ) ) ;
#endif
}
static int F_177 ( int * V_327 , int * V_328 )
{
T_2 V_329 , V_330 , V_331 , V_332 , V_113 , V_197 , V_200 ;
T_6 V_84 ;
V_200 = F_178 () ;
F_179 ( V_200 + 1 , & V_329 , & V_330 , & V_331 , & V_332 ) ;
* V_327 = V_329 >> 16 ;
* V_328 = V_329 & 0xffff ;
F_9 ( V_26 L_12 , * V_327 , * V_328 ) ;
F_179 ( V_200 + 2 , & V_113 , & V_197 , & V_331 , & V_332 ) ;
V_84 = F_169 ( V_333 ) ;
F_180 ( V_197 , ( T_8 ) V_84 , ( T_8 ) ( V_84 >> 32 ) ) ;
F_154 () ;
V_27 . V_28 = L_13 ;
V_264 = V_334 ;
return 0 ;
}
void T_13 F_181 ( void )
{
int V_3 ;
struct V_335 V_336 ;
static struct V_220 * V_337 = 0 ;
if ( ! V_337 )
V_337 = (struct V_220 * )
F_182 ( V_91 , V_91 ) ;
V_336 . V_338 = V_106 ;
V_336 . V_125 = 0 ;
V_336 . V_339 = V_340 ;
V_336 . V_341 = F_169 ( V_337 ) >> V_342 ;
if ( F_183 ( V_343 , & V_336 ) )
F_13 () ;
V_9 = (struct V_220 * ) V_337 ;
F_11 (cpu) {
F_5 ( V_11 , V_3 ) = & V_9 -> V_7 [ V_3 ] ;
}
}
static int T_14 F_184 ( struct V_253 * V_344 ,
unsigned long V_345 , void * V_346 )
{
int V_3 = ( long ) V_346 ;
switch ( V_345 ) {
case V_347 :
F_3 ( V_3 ) ;
if ( V_348 )
F_185 ( V_3 ) ;
break;
default:
break;
}
return V_349 ;
}
static void T_1 F_186 ( void )
{
int V_244 ;
int V_327 , V_328 ;
V_244 = F_177 ( & V_327 , & V_328 ) ;
if ( V_244 < 0 )
return;
F_181 () ;
if ( F_17 ( V_350 ) )
V_348 = 1 ;
F_187 () ;
F_188 ( & V_351 ) ;
F_189 () ;
V_272 . V_352 . V_353 = V_354 ;
F_190 () ;
F_191 () ;
}
static bool T_1 F_192 ( void )
{
if ( F_193 () )
return false ;
if ( ! F_178 () )
return false ;
return true ;
}
bool F_194 ( void )
{
if ( F_193 () )
return false ;
if ( ! F_195 () )
return false ;
if ( F_17 ( V_355 ) && V_348 )
return false ;
return true ;
}
