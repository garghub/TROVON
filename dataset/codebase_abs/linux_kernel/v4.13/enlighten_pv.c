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
if ( ! F_11 () )
F_19 ( V_48 ) ;
if ( F_9 () )
F_18 ( V_32 ) ;
else
F_19 ( V_32 ) ;
if ( ! F_15 () ) {
F_19 ( V_40 ) ;
F_19 ( V_41 ) ;
}
}
static void F_20 ( int V_49 , unsigned long V_50 )
{
F_21 ( V_49 , V_50 ) ;
}
static unsigned long F_22 ( int V_49 )
{
return F_23 ( V_49 ) ;
}
static void F_24 ( struct V_51 * V_52 )
{
F_25 () ;
F_26 ( V_52 ) ;
}
static unsigned long F_27 ( void )
{
return 0 ;
}
static void F_28 ( void * V_53 , T_3 V_54 )
{
int V_55 ;
T_4 * V_56 ;
T_4 V_57 ;
unsigned long V_58 ;
struct V_59 * V_59 ;
unsigned char V_60 ;
V_56 = F_29 ( ( unsigned long ) V_53 , & V_55 ) ;
F_30 ( V_56 == NULL ) ;
V_58 = F_31 ( * V_56 ) ;
V_59 = F_32 ( V_58 ) ;
V_57 = F_33 ( V_58 , V_54 ) ;
F_34 () ;
F_35 ( & V_60 , V_53 , 1 ) ;
if ( F_36 ( ( unsigned long ) V_53 , V_57 , 0 ) )
F_37 () ;
if ( ! F_38 ( V_59 ) ) {
void * V_61 = F_39 ( F_40 ( V_58 ) ) ;
if ( V_61 != V_53 )
if ( F_36 ( ( unsigned long ) V_61 , V_57 , 0 ) )
F_37 () ;
} else
F_41 () ;
F_42 () ;
}
static void F_43 ( struct V_62 * V_63 , unsigned V_64 )
{
const unsigned V_65 = V_66 / V_67 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_64 ; V_68 += V_65 )
F_28 ( V_63 + V_68 , V_69 ) ;
}
static void F_44 ( struct V_62 * V_63 , unsigned V_64 )
{
const unsigned V_65 = V_66 / V_67 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_64 ; V_68 += V_65 )
F_28 ( V_63 + V_68 , V_70 ) ;
}
static void F_45 ( const void * V_71 , unsigned V_64 )
{
struct V_72 * V_22 ;
struct V_73 V_74 = F_46 ( sizeof( * V_22 ) ) ;
F_47 ( V_71 , V_64 ) ;
V_22 = V_74 . args ;
V_22 -> V_23 = V_75 ;
V_22 -> V_76 . V_77 = ( unsigned long ) V_71 ;
V_22 -> V_78 . V_79 = V_64 ;
F_48 ( V_74 . V_80 , V_22 , 1 , NULL , V_81 ) ;
F_49 ( V_82 ) ;
}
static void F_50 ( const struct V_83 * V_84 )
{
unsigned long V_85 = V_84 -> V_86 ;
unsigned int V_87 = V_84 -> V_87 + 1 ;
unsigned V_88 = F_51 ( V_87 , V_66 ) ;
unsigned long V_89 [ V_88 ] ;
int V_90 ;
F_30 ( V_87 > 65536 ) ;
F_30 ( V_85 & ~ V_91 ) ;
for ( V_90 = 0 ; V_85 < V_84 -> V_86 + V_87 ; V_85 += V_66 , V_90 ++ ) {
int V_55 ;
T_4 * V_56 ;
unsigned long V_58 , V_92 ;
void * V_93 ;
V_56 = F_29 ( V_85 , & V_55 ) ;
F_30 ( V_56 == NULL ) ;
V_58 = F_31 ( * V_56 ) ;
V_92 = F_52 ( V_58 ) ;
V_93 = F_39 ( F_40 ( V_58 ) ) ;
V_89 [ V_90 ] = V_92 ;
F_53 ( ( void * ) V_85 ) ;
F_53 ( V_93 ) ;
}
if ( F_54 ( V_89 , V_87 / sizeof( struct V_62 ) ) )
F_37 () ;
}
static void T_1 F_55 ( const struct V_83 * V_84 )
{
unsigned long V_85 = V_84 -> V_86 ;
unsigned int V_87 = V_84 -> V_87 + 1 ;
unsigned V_88 = F_51 ( V_87 , V_66 ) ;
unsigned long V_89 [ V_88 ] ;
int V_90 ;
F_30 ( V_87 > 65536 ) ;
F_30 ( V_85 & ~ V_91 ) ;
for ( V_90 = 0 ; V_85 < V_84 -> V_86 + V_87 ; V_85 += V_66 , V_90 ++ ) {
T_4 V_57 ;
unsigned long V_58 , V_92 ;
V_58 = F_56 ( V_85 ) ;
V_92 = F_52 ( V_58 ) ;
V_57 = F_33 ( V_58 , V_69 ) ;
if ( F_36 ( ( unsigned long ) V_85 , V_57 , 0 ) )
F_37 () ;
V_89 [ V_90 ] = V_92 ;
}
if ( F_54 ( V_89 , V_87 / sizeof( struct V_62 ) ) )
F_37 () ;
}
static inline bool F_57 ( const struct V_62 * V_94 ,
const struct V_62 * V_95 )
{
return V_94 -> V_96 == V_95 -> V_96 && V_94 -> V_97 == V_95 -> V_97 ;
}
static void F_58 ( struct V_98 * V_99 ,
unsigned int V_100 , unsigned int V_68 )
{
struct V_62 * V_101 = & F_59 ( V_102 , V_100 ) . V_103 [ V_68 ] ;
struct V_62 * V_104 ;
T_5 V_105 ;
struct V_73 V_80 ;
if ( F_57 ( V_101 , & V_99 -> V_106 [ V_68 ] ) )
return;
* V_101 = V_99 -> V_106 [ V_68 ] ;
V_104 = F_60 ( V_100 ) ;
V_105 = F_61 ( & V_104 [ V_107 + V_68 ] ) ;
V_80 = F_62 ( 0 ) ;
F_63 ( V_80 . V_80 , V_105 . V_105 , V_99 -> V_106 [ V_68 ] ) ;
}
static void F_64 ( struct V_98 * V_99 , unsigned int V_100 )
{
if ( F_65 () == V_82 ) {
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
F_49 ( V_82 ) ;
}
static void F_70 ( unsigned int V_109 )
{
if ( F_71 ( V_110 , V_109 ) )
F_37 () ;
}
static void F_72 ( struct V_62 * V_111 , int V_112 ,
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
static int F_75 ( int V_116 , const T_7 * V_50 ,
struct V_117 * V_118 )
{
unsigned long V_71 ;
if ( V_50 -> type != V_119 && V_50 -> type != V_120 )
return 0 ;
V_118 -> V_116 = V_116 ;
V_71 = F_76 ( * V_50 ) ;
#ifdef F_77
if ( V_71 == ( unsigned long ) V_121 )
V_71 = ( unsigned long ) V_122 ;
else if ( V_71 == ( unsigned long ) V_123 )
V_71 = ( unsigned long ) V_124 ;
else if ( V_71 == ( unsigned long ) V_125 )
V_71 = ( unsigned long ) V_126 ;
else if ( V_71 == ( unsigned long ) V_127 ) {
return 0 ;
#ifdef F_78
} else if ( V_71 == ( unsigned long ) V_128 ) {
;
#endif
} else if ( V_71 == ( unsigned long ) V_129 )
;
else {
if ( F_79 ( V_50 -> V_130 != 0 ) )
return 0 ;
}
#endif
V_118 -> V_86 = V_71 ;
V_118 -> V_131 = F_80 ( * V_50 ) ;
V_118 -> V_132 = V_50 -> V_133 ;
if ( V_50 -> type == V_120 )
V_118 -> V_132 |= 1 << 2 ;
return 1 ;
}
static void F_81 ( T_7 * V_111 , int V_112 , const T_7 * V_134 )
{
unsigned long V_135 = ( unsigned long ) & V_111 [ V_112 ] ;
unsigned long V_136 , V_137 ;
F_82 ( V_111 , V_112 , V_134 ) ;
F_34 () ;
V_136 = F_83 ( V_138 . V_86 ) ;
V_137 = V_136 + F_83 ( V_138 . V_87 ) + 1 ;
F_25 () ;
F_84 ( V_111 , V_112 , V_134 ) ;
if ( V_135 >= V_136 && ( V_135 + 8 ) <= V_137 ) {
struct V_117 V_118 [ 2 ] ;
V_118 [ 1 ] . V_86 = 0 ;
if ( F_75 ( V_112 , V_134 , & V_118 [ 0 ] ) )
if ( F_85 ( V_118 ) )
F_37 () ;
}
F_42 () ;
}
static void F_86 ( const struct V_83 * V_103 ,
struct V_117 * V_139 )
{
unsigned V_140 , V_141 , V_142 ;
V_142 = ( V_103 -> V_87 + 1 ) / sizeof( T_7 ) ;
F_30 ( V_142 > 256 ) ;
for ( V_140 = V_141 = 0 ; V_140 < V_142 ; V_140 ++ ) {
T_7 * V_115 = ( T_7 * ) ( V_103 -> V_86 ) + V_140 ;
if ( F_75 ( V_140 , V_115 , & V_139 [ V_141 ] ) )
V_141 ++ ;
}
V_139 [ V_141 ] . V_86 = 0 ;
}
void F_87 ( struct V_117 * V_139 )
{
const struct V_83 * V_103 = F_88 ( & V_138 ) ;
F_86 ( V_103 , V_139 ) ;
}
static void F_89 ( const struct V_83 * V_103 )
{
static F_90 ( V_143 ) ;
static struct V_117 V_139 [ 257 ] ;
F_91 ( V_103 ) ;
F_92 ( & V_143 ) ;
memcpy ( F_88 ( & V_138 ) , V_103 , sizeof( V_138 ) ) ;
F_86 ( V_103 , V_139 ) ;
F_25 () ;
if ( F_85 ( V_139 ) )
F_37 () ;
F_93 ( & V_143 ) ;
}
static void F_94 ( struct V_62 * V_111 , int V_115 ,
const void * V_103 , int type )
{
F_95 ( V_111 , V_115 , V_103 , type ) ;
F_34 () ;
switch ( type ) {
case V_144 :
case V_145 :
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
static void T_1 F_96 ( struct V_62 * V_111 , int V_115 ,
const void * V_103 , int type )
{
F_95 ( V_111 , V_115 , V_103 , type ) ;
switch ( type ) {
case V_144 :
case V_145 :
break;
default: {
T_5 V_105 = F_97 ( & V_111 [ V_115 ] ) ;
if ( F_74 ( V_105 . V_105 , * ( T_6 * ) V_103 ) )
V_111 [ V_115 ] = * (struct V_62 * ) V_103 ;
}
}
}
static void F_98 ( struct V_146 * V_147 ,
struct V_98 * V_148 )
{
struct V_73 V_74 ;
V_74 = F_46 ( 0 ) ;
F_99 ( V_74 . V_80 , V_149 , V_148 -> V_150 ) ;
F_49 ( V_82 ) ;
V_147 -> V_151 . V_150 = V_148 -> V_150 ;
}
void F_100 ( unsigned V_152 )
{
struct V_153 V_154 ;
V_154 . V_155 = ( V_152 == 0 ) ? 1 : ( V_152 >> 12 ) & 3 ;
F_101 ( V_156 , & V_154 ) ;
}
static void F_102 ( void )
{
}
static unsigned long F_103 ( void )
{
unsigned long V_157 = F_104 ( V_158 ) ;
if ( F_105 ( V_157 == 0 ) ) {
V_157 = F_106 () ;
F_107 ( V_158 , V_157 ) ;
}
return V_157 ;
}
static void F_108 ( unsigned long V_157 )
{
struct V_73 V_74 ;
F_107 ( V_158 , V_157 ) ;
V_74 = F_46 ( 0 ) ;
F_109 ( V_74 . V_80 , ( V_157 & V_159 ) != 0 ) ;
F_49 ( V_82 ) ;
}
static void F_110 ( unsigned long V_160 )
{
V_160 &= ~ ( V_161 | V_162 | V_163 ) ;
F_111 ( V_160 ) ;
}
static inline unsigned long F_112 ( void )
{
return 0 ;
}
static inline void F_113 ( unsigned long V_50 )
{
F_30 ( V_50 ) ;
}
static T_6 F_114 ( unsigned int V_164 , int * V_165 )
{
T_6 V_50 ;
if ( F_115 ( V_164 , & V_50 , V_165 ) )
return V_50 ;
V_50 = F_116 ( V_164 , V_165 ) ;
switch ( V_164 ) {
case V_166 :
#ifdef F_117
if ( ! ( F_16 ( 1 ) & ( 1 << ( V_47 & 31 ) ) ) )
#endif
V_50 &= ~ V_167 ;
break;
}
return V_50 ;
}
static int F_118 ( unsigned int V_164 , unsigned V_168 , unsigned V_169 )
{
int V_170 ;
V_170 = 0 ;
switch ( V_164 ) {
#ifdef F_77
unsigned V_171 ;
T_6 V_172 ;
case V_173 : V_171 = V_174 ; goto V_175;
case V_176 : V_171 = V_177 ; goto V_175;
case V_178 : V_171 = V_179 ; goto V_175;
V_175:
V_172 = ( ( T_6 ) V_169 << 32 ) | V_168 ;
if ( F_71 ( V_171 , V_172 ) != 0 )
V_170 = - V_180 ;
break;
#endif
case V_181 :
case V_182 :
case V_183 :
case V_184 :
case V_185 :
case V_186 :
case V_187 :
break;
default:
if ( ! F_119 ( V_164 , V_168 , V_169 , & V_170 ) )
V_170 = F_120 ( V_164 , V_168 , V_169 ) ;
}
return V_170 ;
}
static T_6 F_121 ( unsigned int V_164 )
{
int V_165 ;
return F_114 ( V_164 , & V_165 ) ;
}
static void F_122 ( unsigned int V_164 , unsigned V_168 , unsigned V_169 )
{
F_118 ( V_164 , V_168 , V_169 ) ;
}
void F_123 ( void )
{
F_124 ( V_188 , V_189 -> V_190 ) ;
V_191 =
(struct V_190 * ) F_125 ( V_188 ) ;
F_126 () ;
if ( V_192 == V_193 ) {
#ifndef F_127
F_128 () ;
#endif
F_129 () ;
}
}
void T_8 F_128 ( void )
{
int V_100 ;
F_130 (cpu) {
F_59 ( V_194 , V_100 ) = V_100 ;
( void ) F_131 ( V_100 ) ;
}
if ( V_195 ) {
V_196 . V_197 = F_132 ( V_198 ) ;
V_196 . V_199 = F_132 ( V_200 ) ;
V_196 . V_201 = F_132 ( V_202 ) ;
V_196 . V_203 = F_132 ( V_204 ) ;
V_205 . V_206 = V_207 ;
}
}
static unsigned F_133 ( T_9 type , T_10 V_208 , void * V_209 ,
unsigned long V_71 , unsigned V_210 )
{
char * V_136 , * V_137 , * V_211 ;
unsigned V_170 ;
V_136 = V_137 = V_211 = NULL ;
#define F_134 ( V_22 , T_11 ) \
case PARAVIRT_PATCH(op.x): \
if (xen_have_vcpu_info_placement) { \
start = (char *)xen_##x##_direct; \
end = xen_##x##_direct_end; \
reloc = xen_##x##_direct_reloc; \
} \
goto patch_site
switch ( type ) {
F_134 ( V_196 , V_203 ) ;
F_134 ( V_196 , V_201 ) ;
F_134 ( V_196 , V_197 ) ;
F_134 ( V_196 , V_199 ) ;
#undef F_134
V_212:
if ( V_136 == NULL || ( V_137 - V_136 ) > V_210 )
goto V_213;
V_170 = F_135 ( V_209 , V_210 , V_136 , V_137 ) ;
if ( V_211 > V_136 && V_211 < V_137 ) {
int V_214 = V_211 - V_136 ;
long * V_215 = ( long * ) ( V_209 + V_214 ) ;
long V_216 = V_136 - ( char * ) V_71 ;
* V_215 += V_216 ;
}
break;
V_213:
default:
V_170 = F_136 ( type , V_208 , V_209 ,
V_71 , V_210 ) ;
break;
}
return V_170 ;
}
static void F_137 ( char * V_217 )
{
F_138 ( V_218 ) ;
}
static void F_139 ( void )
{
F_138 ( V_219 ) ;
}
static void F_140 ( void )
{
if ( V_220 )
V_220 () ;
F_138 ( V_219 ) ;
}
static void F_141 ( struct V_221 * V_222 )
{
F_138 ( V_223 ) ;
}
static unsigned char F_142 ( void )
{
unsigned char V_224 = 0 ;
if ( F_143 ( V_225 ,
& V_191 -> V_226 . V_227 ) )
V_224 |= V_228 ;
if ( F_143 ( V_229 ,
& V_191 -> V_226 . V_227 ) )
V_224 |= V_230 ;
return V_224 ;
}
static void T_1 F_144 ( void )
{
#if F_145 ( V_231 )
struct V_21 V_22 ;
struct V_232 * V_232 ;
T_12 * V_233 ;
unsigned V_234 ;
int V_170 ;
V_232 = V_235 . V_236 ;
V_233 = V_235 . V_237 ;
V_22 . V_23 = V_238 ;
V_22 . V_25 . V_239 . type = V_240 ;
for ( V_234 = 0 ; V_234 < V_241 ; V_234 ++ ) {
struct V_232 * V_118 = V_232 + V_234 ;
V_22 . V_25 . V_239 . V_242 = V_234 ;
V_118 -> V_243 . V_244 = sizeof( V_118 -> V_243 ) ;
F_13 ( V_22 . V_25 . V_239 . V_25 . V_245 . V_246 ,
& V_118 -> V_243 ) ;
V_170 = F_14 ( & V_22 ) ;
if ( V_170 )
break;
#define F_146 ( T_11 ) info->x = op.u.firmware_info.u.disk_info.x
F_146 ( V_247 ) ;
F_146 ( V_1 ) ;
F_146 ( V_248 ) ;
F_146 ( V_249 ) ;
F_146 ( V_250 ) ;
F_146 ( V_251 ) ;
#undef F_146
}
V_235 . V_252 = V_234 ;
V_22 . V_25 . V_239 . type = V_253 ;
for ( V_234 = 0 ; V_234 < V_254 ; V_234 ++ ) {
V_22 . V_25 . V_239 . V_242 = V_234 ;
V_170 = F_14 ( & V_22 ) ;
if ( V_170 )
break;
V_233 [ V_234 ] = V_22 . V_25 . V_239 . V_25 . V_255 . V_233 ;
}
V_235 . V_256 = V_234 ;
#endif
}
static void F_147 ( int V_100 )
{
V_257 . V_258 = F_96 ;
V_257 . V_259 = F_55 ;
F_148 ( 0 ) ;
F_149 ( 0 ) ;
V_257 . V_258 = F_94 ;
V_257 . V_259 = F_50 ;
}
static void T_1 F_150 ( void )
{
V_260 . V_261 . V_262 = 1 ;
}
T_13 T_14 void T_1 F_151 ( void )
{
struct V_153 V_154 ;
unsigned long V_263 = 0 ;
int V_264 ;
if ( ! V_189 )
return;
V_265 = V_266 ;
F_152 () ;
F_153 () ;
V_6 = V_267 ;
V_268 = V_269 ;
V_257 = V_270 ;
V_260 . V_271 = F_142 ;
V_272 . V_273 . V_274 = V_275 ;
V_272 . V_276 . V_277 = V_278 ;
V_272 . V_276 . V_279 = F_1 ;
F_154 () ;
V_280 &= ~ V_281 ;
V_282 &= ~ V_283 ;
F_155 () ;
F_156 () ;
F_147 ( 0 ) ;
F_157 () ;
F_17 () ;
#ifdef F_158
F_159 () ;
#endif
if ( F_5 ( V_10 ) ) {
V_205 . V_284 = V_285 ;
V_205 . V_286 = V_287 ;
}
V_288 = V_289 ;
V_290 = & F_59 ( V_291 , 0 ) ;
F_160 () ;
#ifdef F_161
V_292 = - 1 ;
#endif
F_59 ( V_194 , 0 ) = 0 ;
F_162 ( 0 ) ;
F_79 ( F_163 ( V_293 , V_294 ) ) ;
F_164 () ;
V_295 = true ;
F_165 ( L_5 ) ;
F_166 ( ( V_296 * ) V_189 -> V_297 ,
V_189 -> V_298 ) ;
F_167 () ;
#ifdef F_66
V_6 . V_299 = 1 ;
if ( F_5 ( V_300 ) )
V_6 . V_299 = 0 ;
#else
V_6 . V_299 = 0 ;
#endif
F_168 () ;
V_154 . V_155 = 1 ;
V_264 = F_101 ( V_156 , & V_154 ) ;
if ( V_264 != 0 )
F_169 ( L_6 , V_264 ) ;
#ifdef F_66
F_170 ( & V_301 ) ;
F_171 ( & V_301 , V_302 ) ;
V_301 . V_303 [ V_304 ] = F_172 ( 1 ) ;
#endif
if ( V_189 -> V_305 ) {
if ( V_189 -> V_132 & V_306 )
V_263 = F_40 ( V_189 -> V_305 ) ;
else
V_263 = F_173 ( V_189 -> V_305 ) ;
}
V_235 . V_307 . V_308 = ( 9 << 4 ) | 0 ;
V_235 . V_307 . V_309 = V_263 ;
V_235 . V_307 . V_310 = V_189 -> V_311 ;
V_235 . V_307 . V_312 = F_173 ( V_189 -> V_313 ) ;
V_235 . V_307 . V_314 = V_315 ;
if ( ! F_11 () ) {
F_174 ( L_7 , 0 , NULL ) ;
F_174 ( L_8 , 0 , NULL ) ;
F_174 ( L_9 , 0 , NULL ) ;
if ( V_316 )
V_272 . V_317 . V_318 = V_319 ;
} else {
const struct V_320 * V_118 =
( void * ) ( ( char * ) V_189 +
V_189 -> V_321 . V_322 . V_323 ) ;
struct V_21 V_22 = {
. V_23 = V_238 ,
. V_324 = V_325 ,
. V_25 . V_239 . type = V_326 ,
} ;
V_260 . V_327 =
F_150 ;
F_175 ( V_118 , V_189 -> V_321 . V_322 . V_328 ) ;
V_189 -> V_321 . V_329 . V_92 = 0 ;
V_189 -> V_321 . V_329 . V_330 = 0 ;
if ( F_14 ( & V_22 ) == 0 )
V_235 . V_331 = V_22 . V_25 . V_239 . V_25 . V_332 ;
F_176 () ;
F_177 () ;
V_272 . V_333 . V_334 = V_335 ;
V_272 . V_333 . V_336 = V_337 ;
F_144 () ;
}
#ifdef F_178
V_338 &= ~ V_339 ;
#endif
F_165 ( L_10 ) ;
F_179 ( 0 ) ;
F_180 () ;
#ifdef F_66
F_181 () ;
#else
F_182 () ;
F_183 ( ( char * ) F_184 ( & V_235 ) ) ;
#endif
}
static int V_293 ( unsigned int V_100 )
{
int V_264 ;
if ( F_59 ( V_340 , V_100 ) == NULL )
return - V_341 ;
F_185 ( V_100 ) ;
V_264 = F_186 ( V_100 ) ;
if ( V_264 ) {
F_187 ( 1 , L_11 ,
V_100 , V_264 ) ;
return V_264 ;
}
V_264 = F_188 ( V_100 ) ;
if ( V_264 ) {
F_187 ( 1 , L_12 ,
V_100 , V_264 ) ;
return V_264 ;
}
return 0 ;
}
static int V_294 ( unsigned int V_100 )
{
F_189 ( V_100 ) ;
F_190 ( V_100 ) ;
F_191 ( V_100 ) ;
return 0 ;
}
static T_2 T_1 F_192 ( void )
{
if ( F_193 () )
return F_194 () ;
return 0 ;
}
