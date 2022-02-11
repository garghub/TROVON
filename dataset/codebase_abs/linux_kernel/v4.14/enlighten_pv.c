static void T_1 F_1 ( void )
{
unsigned V_1 = F_2 ( V_2 , NULL ) ;
struct V_3 V_4 ;
F_2 ( V_5 , & V_4 ) ;
F_3 ( L_1 , V_6 . V_7 ) ;
F_4 ( V_8 L_2 ,
V_1 >> 16 , V_1 & 0xffff , V_4 . V_9 ,
F_5 ( V_10 ) ? L_3 : L_4 ) ;
}
bool
F_6 ( unsigned int V_11 , unsigned int V_12 )
{
unsigned int V_1 ;
if ( ! F_7 () )
return false ;
V_1 = F_2 ( V_2 , NULL ) ;
if ( ( ( ( V_1 >> 16 ) == V_11 ) && ( ( V_1 & 0xffff ) >= V_12 ) ) ||
( ( V_1 >> 16 ) > V_11 ) )
return true ;
return false ;
}
static void F_8 ( unsigned int * V_13 , unsigned int * V_14 ,
unsigned int * V_15 , unsigned int * V_16 )
{
unsigned V_17 = ~ 0 ;
switch ( * V_13 ) {
case V_18 :
* V_13 = 0 ;
* V_14 = 0 ;
* V_15 = V_19 ;
* V_16 = V_20 ;
return;
case 0xb :
V_17 = 0 ;
break;
}
asm(XEN_EMULATE_PREFIX "cpuid"
: "=a" (*ax),
"=b" (*bx),
"=c" (*cx),
"=d" (*dx)
: "0" (*ax), "2" (*cx));
* V_14 &= V_17 ;
}
static bool T_1 F_9 ( void )
{
#ifdef F_10
struct V_21 V_22 = {
. V_23 = V_24 ,
. V_25 . V_26 . V_27 = - 1 ,
. V_25 . V_26 . type = V_28 ,
} ;
T_2 V_29 [ 3 ] ;
unsigned int V_13 , V_14 , V_15 , V_16 ;
unsigned int V_30 ;
if ( ! F_11 () )
return false ;
if ( ! F_6 ( 4 , 2 ) )
return false ;
V_13 = 1 ;
V_15 = 0 ;
F_12 ( & V_13 , & V_14 , & V_15 , & V_16 ) ;
V_30 = ( 1 << ( V_31 % 32 ) ) |
( 1 << ( V_32 % 32 ) ) ;
if ( ( V_15 & V_30 ) != V_30 )
return false ;
V_13 = V_18 ;
V_14 = 0 ;
V_15 = 0 ;
V_16 = 0 ;
F_12 ( & V_13 , & V_14 , & V_15 , & V_16 ) ;
V_29 [ 0 ] = V_33 ;
V_29 [ 1 ] = 1 ;
V_29 [ 2 ] = ( V_34 | V_35 ) ;
F_13 ( V_22 . V_25 . V_26 . V_36 , V_29 ) ;
if ( ( F_14 ( & V_22 ) == 0 ) &&
( V_29 [ 2 ] & ( V_37 | V_38 ) ) ) {
V_19 = V_15 ;
V_20 = V_16 ;
}
return true ;
#else
return false ;
#endif
}
static bool T_1 F_15 ( void )
{
unsigned int V_15 , V_39 ;
V_15 = F_16 ( 1 ) ;
V_39 = ( 1 << ( V_40 % 32 ) ) |
( 1 << ( V_41 % 32 ) ) ;
return ( V_15 & V_39 ) == V_39 ;
}
static void T_1 F_17 ( void )
{
F_18 ( V_42 ) ;
F_19 ( V_43 ) ;
F_19 ( V_44 ) ;
F_19 ( V_45 ) ;
F_19 ( V_46 ) ;
F_19 ( V_47 ) ;
F_19 ( V_48 ) ;
F_19 ( V_49 ) ;
if ( ! F_11 () )
F_19 ( V_50 ) ;
if ( F_9 () )
F_18 ( V_32 ) ;
else
F_19 ( V_32 ) ;
if ( ! F_15 () ) {
F_19 ( V_40 ) ;
F_19 ( V_41 ) ;
}
}
static void F_20 ( int V_51 , unsigned long V_52 )
{
F_21 ( V_51 , V_52 ) ;
}
static unsigned long F_22 ( int V_51 )
{
return F_23 ( V_51 ) ;
}
static void F_24 ( struct V_53 * V_54 )
{
F_25 () ;
F_26 ( V_54 ) ;
}
static unsigned long F_27 ( void )
{
return 0 ;
}
static void F_28 ( void * V_55 , T_3 V_56 )
{
int V_57 ;
T_4 * V_58 ;
T_4 V_59 ;
unsigned long V_60 ;
struct V_61 * V_61 ;
unsigned char V_62 ;
V_58 = F_29 ( ( unsigned long ) V_55 , & V_57 ) ;
F_30 ( V_58 == NULL ) ;
V_60 = F_31 ( * V_58 ) ;
V_61 = F_32 ( V_60 ) ;
V_59 = F_33 ( V_60 , V_56 ) ;
F_34 () ;
F_35 ( & V_62 , V_55 , 1 ) ;
if ( F_36 ( ( unsigned long ) V_55 , V_59 , 0 ) )
F_37 () ;
if ( ! F_38 ( V_61 ) ) {
void * V_63 = F_39 ( F_40 ( V_60 ) ) ;
if ( V_63 != V_55 )
if ( F_36 ( ( unsigned long ) V_63 , V_59 , 0 ) )
F_37 () ;
} else
F_41 () ;
F_42 () ;
}
static void F_43 ( struct V_64 * V_65 , unsigned V_66 )
{
const unsigned V_67 = V_68 / V_69 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_66 ; V_70 += V_67 )
F_28 ( V_65 + V_70 , V_71 ) ;
}
static void F_44 ( struct V_64 * V_65 , unsigned V_66 )
{
const unsigned V_67 = V_68 / V_69 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_66 ; V_70 += V_67 )
F_28 ( V_65 + V_70 , V_72 ) ;
}
static void F_45 ( const void * V_73 , unsigned V_66 )
{
struct V_74 * V_22 ;
struct V_75 V_76 = F_46 ( sizeof( * V_22 ) ) ;
F_47 ( V_73 , V_66 ) ;
V_22 = V_76 . args ;
V_22 -> V_23 = V_77 ;
V_22 -> V_78 . V_79 = ( unsigned long ) V_73 ;
V_22 -> V_80 . V_81 = V_66 ;
F_48 ( V_76 . V_82 , V_22 , 1 , NULL , V_83 ) ;
F_49 ( V_84 ) ;
}
static void F_50 ( const struct V_85 * V_86 )
{
unsigned long V_87 = V_86 -> V_88 ;
unsigned int V_89 = V_86 -> V_89 + 1 ;
unsigned V_90 = F_51 ( V_89 , V_68 ) ;
unsigned long V_91 [ V_90 ] ;
int V_92 ;
F_30 ( V_89 > 65536 ) ;
F_30 ( V_87 & ~ V_93 ) ;
for ( V_92 = 0 ; V_87 < V_86 -> V_88 + V_89 ; V_87 += V_68 , V_92 ++ ) {
int V_57 ;
T_4 * V_58 ;
unsigned long V_60 , V_94 ;
void * V_95 ;
V_58 = F_29 ( V_87 , & V_57 ) ;
F_30 ( V_58 == NULL ) ;
V_60 = F_31 ( * V_58 ) ;
V_94 = F_52 ( V_60 ) ;
V_95 = F_39 ( F_40 ( V_60 ) ) ;
V_91 [ V_92 ] = V_94 ;
F_53 ( ( void * ) V_87 ) ;
F_53 ( V_95 ) ;
}
if ( F_54 ( V_91 , V_89 / sizeof( struct V_64 ) ) )
F_37 () ;
}
static void T_1 F_55 ( const struct V_85 * V_86 )
{
unsigned long V_87 = V_86 -> V_88 ;
unsigned int V_89 = V_86 -> V_89 + 1 ;
unsigned V_90 = F_51 ( V_89 , V_68 ) ;
unsigned long V_91 [ V_90 ] ;
int V_92 ;
F_30 ( V_89 > 65536 ) ;
F_30 ( V_87 & ~ V_93 ) ;
for ( V_92 = 0 ; V_87 < V_86 -> V_88 + V_89 ; V_87 += V_68 , V_92 ++ ) {
T_4 V_59 ;
unsigned long V_60 , V_94 ;
V_60 = F_56 ( V_87 ) ;
V_94 = F_52 ( V_60 ) ;
V_59 = F_33 ( V_60 , V_71 ) ;
if ( F_36 ( ( unsigned long ) V_87 , V_59 , 0 ) )
F_37 () ;
V_91 [ V_92 ] = V_94 ;
}
if ( F_54 ( V_91 , V_89 / sizeof( struct V_64 ) ) )
F_37 () ;
}
static inline bool F_57 ( const struct V_64 * V_96 ,
const struct V_64 * V_97 )
{
return ! memcmp ( V_96 , V_97 , sizeof( * V_96 ) ) ;
}
static void F_58 ( struct V_98 * V_99 ,
unsigned int V_100 , unsigned int V_70 )
{
struct V_64 * V_101 = & F_59 ( V_102 , V_100 ) . V_103 [ V_70 ] ;
struct V_64 * V_104 ;
T_5 V_105 ;
struct V_75 V_82 ;
if ( F_57 ( V_101 , & V_99 -> V_106 [ V_70 ] ) )
return;
* V_101 = V_99 -> V_106 [ V_70 ] ;
V_104 = F_60 ( V_100 ) ;
V_105 = F_61 ( & V_104 [ V_107 + V_70 ] ) ;
V_82 = F_62 ( 0 ) ;
F_63 ( V_82 . V_82 , V_105 . V_105 , V_99 -> V_106 [ V_70 ] ) ;
}
static void F_64 ( struct V_98 * V_99 , unsigned int V_100 )
{
if ( F_65 () == V_84 ) {
#ifdef F_66
F_67 ( 0 ) ;
#else
F_68 ( V_108 , 0 ) ;
#endif
}
F_69 () ;
F_58 ( V_99 , V_100 , 0 ) ;
F_58 ( V_99 , V_100 , 1 ) ;
F_58 ( V_99 , V_100 , 2 ) ;
F_49 ( V_84 ) ;
}
static void F_70 ( unsigned int V_109 )
{
if ( F_71 ( V_110 , V_109 ) )
F_37 () ;
}
static void F_72 ( struct V_64 * V_111 , int V_112 ,
const void * V_113 )
{
T_5 V_114 = F_61 ( & V_111 [ V_112 ] ) ;
T_6 V_115 = * ( T_6 * ) V_113 ;
F_73 ( V_111 , V_112 , V_115 ) ;
F_34 () ;
F_25 () ;
if ( F_74 ( V_114 . V_105 , V_115 ) )
F_37 () ;
F_42 () ;
}
static bool F_75 ( void * * V_73 , unsigned int V_116 )
{
unsigned int V_117 ;
bool V_118 = false ;
for ( V_117 = 0 ; V_117 < F_76 ( V_119 ) ; V_117 ++ ) {
struct V_120 * V_115 = V_119 + V_117 ;
if ( * V_73 == V_115 -> V_121 ) {
* V_73 = V_115 -> V_122 ;
V_118 = V_115 -> V_118 ;
break;
}
}
if ( F_77 ( V_116 != 0 && ! V_118 ) )
return false ;
return true ;
}
static int F_78 ( int V_123 , const T_7 * V_52 ,
struct V_124 * V_125 )
{
unsigned long V_73 ;
if ( V_52 -> V_126 . type != V_127 && V_52 -> V_126 . type != V_128 )
return 0 ;
V_125 -> V_123 = V_123 ;
V_73 = F_79 ( V_52 ) ;
#ifdef F_80
if ( ! F_75 ( ( void * * ) & V_73 , V_52 -> V_126 . V_116 ) )
return 0 ;
#endif
V_125 -> V_88 = V_73 ;
V_125 -> V_129 = F_81 ( V_52 ) ;
V_125 -> V_130 = V_52 -> V_126 . V_131 ;
if ( V_52 -> V_126 . type == V_128 )
V_125 -> V_130 |= 1 << 2 ;
return 1 ;
}
static void F_82 ( T_7 * V_111 , int V_112 , const T_7 * V_132 )
{
unsigned long V_133 = ( unsigned long ) & V_111 [ V_112 ] ;
unsigned long V_134 , V_135 ;
F_83 ( V_111 , V_112 , V_132 ) ;
F_34 () ;
V_134 = F_84 ( V_136 . V_88 ) ;
V_135 = V_134 + F_84 ( V_136 . V_89 ) + 1 ;
F_25 () ;
F_85 ( V_111 , V_112 , V_132 ) ;
if ( V_133 >= V_134 && ( V_133 + 8 ) <= V_135 ) {
struct V_124 V_125 [ 2 ] ;
V_125 [ 1 ] . V_88 = 0 ;
if ( F_78 ( V_112 , V_132 , & V_125 [ 0 ] ) )
if ( F_86 ( V_125 ) )
F_37 () ;
}
F_42 () ;
}
static void F_87 ( const struct V_85 * V_103 ,
struct V_124 * V_137 )
{
unsigned V_138 , V_139 , V_140 ;
V_140 = ( V_103 -> V_89 + 1 ) / sizeof( T_7 ) ;
F_30 ( V_140 > 256 ) ;
for ( V_138 = V_139 = 0 ; V_138 < V_140 ; V_138 ++ ) {
T_7 * V_115 = ( T_7 * ) ( V_103 -> V_88 ) + V_138 ;
if ( F_78 ( V_138 , V_115 , & V_137 [ V_139 ] ) )
V_139 ++ ;
}
V_137 [ V_139 ] . V_88 = 0 ;
}
void F_88 ( struct V_124 * V_137 )
{
const struct V_85 * V_103 = F_89 ( & V_136 ) ;
F_87 ( V_103 , V_137 ) ;
}
static void F_90 ( const struct V_85 * V_103 )
{
static F_91 ( V_141 ) ;
static struct V_124 V_137 [ 257 ] ;
F_92 ( V_103 ) ;
F_93 ( & V_141 ) ;
memcpy ( F_89 ( & V_136 ) , V_103 , sizeof( V_136 ) ) ;
F_87 ( V_103 , V_137 ) ;
F_25 () ;
if ( F_86 ( V_137 ) )
F_37 () ;
F_94 ( & V_141 ) ;
}
static void F_95 ( struct V_64 * V_111 , int V_115 ,
const void * V_103 , int type )
{
F_96 ( V_111 , V_115 , V_103 , type ) ;
F_34 () ;
switch ( type ) {
case V_142 :
case V_143 :
break;
default: {
T_5 V_105 = F_61 ( & V_111 [ V_115 ] ) ;
F_25 () ;
if ( F_74 ( V_105 . V_105 , * ( T_6 * ) V_103 ) )
F_37 () ;
}
}
F_42 () ;
}
static void T_1 F_97 ( struct V_64 * V_111 , int V_115 ,
const void * V_103 , int type )
{
F_96 ( V_111 , V_115 , V_103 , type ) ;
switch ( type ) {
case V_142 :
case V_143 :
break;
default: {
T_5 V_105 = F_98 ( & V_111 [ V_115 ] ) ;
if ( F_74 ( V_105 . V_105 , * ( T_6 * ) V_103 ) )
V_111 [ V_115 ] = * (struct V_64 * ) V_103 ;
}
}
}
static void F_99 ( struct V_144 * V_145 ,
struct V_98 * V_146 )
{
struct V_75 V_76 ;
V_76 = F_46 ( 0 ) ;
F_100 ( V_76 . V_82 , V_147 , V_146 -> V_148 ) ;
F_49 ( V_84 ) ;
V_145 -> V_149 . V_148 = V_146 -> V_148 ;
}
void F_101 ( unsigned V_150 )
{
struct V_151 V_152 ;
V_152 . V_153 = ( V_150 == 0 ) ? 1 : ( V_150 >> 12 ) & 3 ;
F_102 ( V_154 , & V_152 ) ;
}
static void F_103 ( void )
{
}
static unsigned long F_104 ( void )
{
unsigned long V_155 = F_105 ( V_156 ) ;
if ( F_106 ( V_155 == 0 ) ) {
V_155 = F_107 () ;
F_108 ( V_156 , V_155 ) ;
}
return V_155 ;
}
static void F_109 ( unsigned long V_155 )
{
struct V_75 V_76 ;
F_108 ( V_156 , V_155 ) ;
V_76 = F_46 ( 0 ) ;
F_110 ( V_76 . V_82 , ( V_155 & V_157 ) != 0 ) ;
F_49 ( V_84 ) ;
}
static void F_111 ( unsigned long V_158 )
{
V_158 &= ~ ( V_159 | V_160 | V_161 ) ;
F_112 ( V_158 ) ;
}
static inline unsigned long F_113 ( void )
{
return 0 ;
}
static inline void F_114 ( unsigned long V_52 )
{
F_30 ( V_52 ) ;
}
static T_6 F_115 ( unsigned int V_162 , int * V_163 )
{
T_6 V_52 ;
if ( F_116 ( V_162 , & V_52 , V_163 ) )
return V_52 ;
V_52 = F_117 ( V_162 , V_163 ) ;
switch ( V_162 ) {
case V_164 :
#ifdef F_118
if ( ! ( F_16 ( 1 ) & ( 1 << ( V_47 & 31 ) ) ) )
#endif
V_52 &= ~ V_165 ;
break;
}
return V_52 ;
}
static int F_119 ( unsigned int V_162 , unsigned V_166 , unsigned V_167 )
{
int V_168 ;
V_168 = 0 ;
switch ( V_162 ) {
#ifdef F_80
unsigned V_169 ;
T_6 V_170 ;
case V_171 : V_169 = V_172 ; goto V_173;
case V_174 : V_169 = V_175 ; goto V_173;
case V_176 : V_169 = V_177 ; goto V_173;
V_173:
V_170 = ( ( T_6 ) V_167 << 32 ) | V_166 ;
if ( F_71 ( V_169 , V_170 ) != 0 )
V_168 = - V_178 ;
break;
#endif
case V_179 :
case V_180 :
case V_181 :
case V_182 :
case V_183 :
case V_184 :
case V_185 :
break;
default:
if ( ! F_120 ( V_162 , V_166 , V_167 , & V_168 ) )
V_168 = F_121 ( V_162 , V_166 , V_167 ) ;
}
return V_168 ;
}
static T_6 F_122 ( unsigned int V_162 )
{
int V_163 ;
return F_115 ( V_162 , & V_163 ) ;
}
static void F_123 ( unsigned int V_162 , unsigned V_166 , unsigned V_167 )
{
F_119 ( V_162 , V_166 , V_167 ) ;
}
void F_124 ( void )
{
F_125 ( V_186 , V_187 -> V_188 ) ;
V_189 =
(struct V_188 * ) F_126 ( V_186 ) ;
F_127 () ;
if ( V_190 == V_191 ) {
#ifndef F_128
F_129 () ;
#endif
F_130 () ;
}
}
void T_8 F_129 ( void )
{
int V_100 ;
F_131 (cpu) {
F_59 ( V_192 , V_100 ) = V_100 ;
( void ) F_132 ( V_100 ) ;
}
if ( V_193 ) {
V_194 . V_195 = F_133 ( V_196 ) ;
V_194 . V_197 = F_133 ( V_198 ) ;
V_194 . V_199 = F_133 ( V_200 ) ;
V_194 . V_201 = F_133 ( V_202 ) ;
V_203 . V_204 = V_205 ;
}
}
static void F_134 ( char * V_206 )
{
F_135 ( V_207 ) ;
}
static void F_136 ( void )
{
F_135 ( V_208 ) ;
}
static void F_137 ( void )
{
if ( V_209 )
V_209 () ;
F_135 ( V_208 ) ;
}
static void F_138 ( struct V_210 * V_211 )
{
F_135 ( V_212 ) ;
}
static unsigned char F_139 ( void )
{
unsigned char V_213 = 0 ;
if ( F_140 ( V_214 ,
& V_189 -> V_215 . V_216 ) )
V_213 |= V_217 ;
if ( F_140 ( V_218 ,
& V_189 -> V_215 . V_216 ) )
V_213 |= V_219 ;
return V_213 ;
}
static void T_1 F_141 ( void )
{
#if F_142 ( V_220 )
struct V_21 V_22 ;
struct V_221 * V_221 ;
T_9 * V_222 ;
unsigned V_117 ;
int V_168 ;
V_221 = V_223 . V_224 ;
V_222 = V_223 . V_225 ;
V_22 . V_23 = V_226 ;
V_22 . V_25 . V_227 . type = V_228 ;
for ( V_117 = 0 ; V_117 < V_229 ; V_117 ++ ) {
struct V_221 * V_125 = V_221 + V_117 ;
V_22 . V_25 . V_227 . V_230 = V_117 ;
V_125 -> V_231 . V_232 = sizeof( V_125 -> V_231 ) ;
F_13 ( V_22 . V_25 . V_227 . V_25 . V_233 . V_234 ,
& V_125 -> V_231 ) ;
V_168 = F_14 ( & V_22 ) ;
if ( V_168 )
break;
#define F_143 ( T_10 ) info->x = op.u.firmware_info.u.disk_info.x
F_143 ( V_235 ) ;
F_143 ( V_1 ) ;
F_143 ( V_236 ) ;
F_143 ( V_237 ) ;
F_143 ( V_238 ) ;
F_143 ( V_239 ) ;
#undef F_143
}
V_223 . V_240 = V_117 ;
V_22 . V_25 . V_227 . type = V_241 ;
for ( V_117 = 0 ; V_117 < V_242 ; V_117 ++ ) {
V_22 . V_25 . V_227 . V_230 = V_117 ;
V_168 = F_14 ( & V_22 ) ;
if ( V_168 )
break;
V_222 [ V_117 ] = V_22 . V_25 . V_227 . V_25 . V_243 . V_222 ;
}
V_223 . V_244 = V_117 ;
#endif
}
static void F_144 ( int V_100 )
{
V_245 . V_246 = F_97 ;
V_245 . V_247 = F_55 ;
F_145 ( 0 ) ;
F_146 ( 0 ) ;
V_245 . V_246 = F_95 ;
V_245 . V_247 = F_50 ;
}
static void T_1 F_147 ( void )
{
V_248 . V_249 . V_250 = 1 ;
}
T_11 T_12 void T_1 F_148 ( void )
{
struct V_151 V_152 ;
unsigned long V_251 = 0 ;
int V_252 ;
if ( ! V_187 )
return;
V_253 = V_254 ;
F_149 () ;
F_150 () ;
V_6 = V_255 ;
V_256 . V_257 = V_258 ;
V_245 = V_259 ;
V_248 . V_260 = F_139 ;
V_261 . V_262 . V_263 = V_264 ;
V_261 . V_265 . V_266 = V_267 ;
V_261 . V_265 . V_268 = F_1 ;
F_151 () ;
V_269 &= ~ V_270 ;
V_271 &= ~ V_272 ;
F_152 () ;
F_153 () ;
F_144 ( 0 ) ;
F_154 () ;
F_17 () ;
#ifdef F_155
F_156 () ;
#endif
if ( F_5 ( V_10 ) ) {
V_203 . V_273 = V_274 ;
V_203 . V_275 = V_276 ;
}
V_277 = V_278 ;
V_279 = & F_59 ( V_280 , 0 ) ;
F_157 () ;
#ifdef F_158
V_281 = - 1 ;
#endif
F_59 ( V_192 , 0 ) = 0 ;
F_159 ( 0 ) ;
F_77 ( F_160 ( V_282 , V_283 ) ) ;
F_161 () ;
V_284 = true ;
F_162 ( L_5 ) ;
F_163 ( ( V_285 * ) V_187 -> V_286 ,
V_187 -> V_287 ) ;
F_164 () ;
#ifdef F_66
V_6 . V_288 = 1 ;
if ( F_5 ( V_289 ) )
V_6 . V_288 = 0 ;
#else
V_6 . V_288 = 0 ;
#endif
F_165 () ;
V_152 . V_153 = 1 ;
V_252 = F_102 ( V_154 , & V_152 ) ;
if ( V_252 != 0 )
F_166 ( L_6 , V_252 ) ;
#ifdef F_66
F_167 ( & V_290 ) ;
F_168 ( & V_290 , V_291 ) ;
V_290 . V_292 [ V_293 ] = F_169 ( 1 ) ;
#endif
if ( V_187 -> V_294 ) {
if ( V_187 -> V_130 & V_295 )
V_251 = F_40 ( V_187 -> V_294 ) ;
else
V_251 = F_170 ( V_187 -> V_294 ) ;
}
V_223 . V_296 . V_297 = ( 9 << 4 ) | 0 ;
V_223 . V_296 . V_298 = V_251 ;
V_223 . V_296 . V_299 = V_187 -> V_300 ;
V_223 . V_296 . V_301 = F_170 ( V_187 -> V_302 ) ;
V_223 . V_296 . V_303 = V_304 ;
if ( ! F_11 () ) {
F_171 ( L_7 , 0 , NULL ) ;
F_171 ( L_8 , 0 , NULL ) ;
F_171 ( L_9 , 0 , NULL ) ;
if ( V_305 )
V_261 . V_306 . V_307 = V_308 ;
} else {
const struct V_309 * V_125 =
( void * ) ( ( char * ) V_187 +
V_187 -> V_310 . V_311 . V_312 ) ;
struct V_21 V_22 = {
. V_23 = V_226 ,
. V_313 = V_314 ,
. V_25 . V_227 . type = V_315 ,
} ;
V_248 . V_316 =
F_147 ;
F_172 ( V_125 , V_187 -> V_310 . V_311 . V_317 ) ;
V_187 -> V_310 . V_318 . V_94 = 0 ;
V_187 -> V_310 . V_318 . V_319 = 0 ;
if ( F_14 ( & V_22 ) == 0 )
V_223 . V_320 = V_22 . V_25 . V_227 . V_25 . V_321 ;
F_173 () ;
F_174 () ;
V_261 . V_322 . V_323 = V_324 ;
V_261 . V_322 . V_325 = V_326 ;
F_141 () ;
}
#ifdef F_175
V_327 &= ~ V_328 ;
#endif
F_162 ( L_10 ) ;
F_176 ( 0 ) ;
F_177 () ;
#ifdef F_66
F_178 () ;
#else
F_179 () ;
F_180 ( ( char * ) F_181 ( & V_223 ) ) ;
#endif
}
static int V_282 ( unsigned int V_100 )
{
int V_252 ;
if ( F_59 ( V_329 , V_100 ) == NULL )
return - V_330 ;
F_182 ( V_100 ) ;
V_252 = F_183 ( V_100 ) ;
if ( V_252 ) {
F_184 ( 1 , L_11 ,
V_100 , V_252 ) ;
return V_252 ;
}
V_252 = F_185 ( V_100 ) ;
if ( V_252 ) {
F_184 ( 1 , L_12 ,
V_100 , V_252 ) ;
return V_252 ;
}
return 0 ;
}
static int V_283 ( unsigned int V_100 )
{
F_186 ( V_100 ) ;
F_187 ( V_100 ) ;
F_188 ( V_100 ) ;
return 0 ;
}
static T_2 T_1 F_189 ( void )
{
if ( F_190 () )
return F_191 () ;
return 0 ;
}
