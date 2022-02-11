void F_1 ( void )
{
int V_1 ;
F_2 (cpu) {
bool V_2 = ( V_1 != F_3 () ) ;
bool V_3 = F_4 ( V_4 , F_5 ( V_1 ) ,
NULL ) ;
if ( V_2 && V_3 &&
F_4 ( V_5 , F_5 ( V_1 ) , NULL ) )
F_6 () ;
F_7 ( V_1 ) ;
if ( V_6 )
F_8 ( V_1 ) ;
if ( V_2 && V_3 &&
F_4 ( V_7 , F_5 ( V_1 ) , NULL ) )
F_6 () ;
}
}
static void T_1 F_9 ( void )
{
unsigned V_8 = F_10 ( V_9 , NULL ) ;
struct V_10 V_11 ;
F_10 ( V_12 , & V_11 ) ;
F_11 ( L_1 , V_13 . V_14 ) ;
F_12 ( V_15 L_2 ,
V_8 >> 16 , V_8 & 0xffff , V_11 . V_16 ,
F_13 ( V_17 ) ? L_3 : L_4 ) ;
}
bool
F_14 ( unsigned int V_18 , unsigned int V_19 )
{
unsigned int V_8 ;
if ( ! F_15 () )
return false ;
V_8 = F_10 ( V_9 , NULL ) ;
if ( ( ( ( V_8 >> 16 ) == V_18 ) && ( ( V_8 & 0xffff ) >= V_19 ) ) ||
( ( V_8 >> 16 ) > V_18 ) )
return true ;
return false ;
}
static void F_16 ( unsigned int * V_20 , unsigned int * V_21 ,
unsigned int * V_22 , unsigned int * V_23 )
{
unsigned V_24 = ~ 0 ;
switch ( * V_20 ) {
case V_25 :
* V_20 = 0 ;
* V_21 = 0 ;
* V_22 = V_26 ;
* V_23 = V_27 ;
return;
case 0xb :
V_24 = 0 ;
break;
}
asm(XEN_EMULATE_PREFIX "cpuid"
: "=a" (*ax),
"=b" (*bx),
"=c" (*cx),
"=d" (*dx)
: "0" (*ax), "2" (*cx));
* V_21 &= V_24 ;
}
static bool T_1 F_17 ( void )
{
#ifdef F_18
struct V_28 V_29 = {
. V_30 = V_31 ,
. V_32 . V_33 . V_34 = - 1 ,
. V_32 . V_33 . type = V_35 ,
} ;
T_2 V_36 [ 3 ] ;
unsigned int V_20 , V_21 , V_22 , V_23 ;
unsigned int V_37 ;
if ( ! F_19 () )
return false ;
if ( ! F_14 ( 4 , 2 ) )
return false ;
V_20 = 1 ;
V_22 = 0 ;
F_20 ( & V_20 , & V_21 , & V_22 , & V_23 ) ;
V_37 = ( 1 << ( V_38 % 32 ) ) |
( 1 << ( V_39 % 32 ) ) ;
if ( ( V_22 & V_37 ) != V_37 )
return false ;
V_20 = V_25 ;
V_21 = 0 ;
V_22 = 0 ;
V_23 = 0 ;
F_20 ( & V_20 , & V_21 , & V_22 , & V_23 ) ;
V_36 [ 0 ] = V_40 ;
V_36 [ 1 ] = 1 ;
V_36 [ 2 ] = ( V_41 | V_42 ) ;
F_21 ( V_29 . V_32 . V_33 . V_43 , V_36 ) ;
if ( ( F_22 ( & V_29 ) == 0 ) &&
( V_36 [ 2 ] & ( V_44 | V_45 ) ) ) {
V_26 = V_22 ;
V_27 = V_23 ;
}
return true ;
#else
return false ;
#endif
}
static bool T_1 F_23 ( void )
{
unsigned int V_22 , V_46 ;
V_22 = F_24 ( 1 ) ;
V_46 = ( 1 << ( V_47 % 32 ) ) |
( 1 << ( V_48 % 32 ) ) ;
return ( V_22 & V_46 ) == V_46 ;
}
static void T_1 F_25 ( void )
{
F_26 ( V_49 ) ;
F_27 ( V_50 ) ;
F_27 ( V_51 ) ;
F_27 ( V_52 ) ;
F_27 ( V_53 ) ;
F_27 ( V_54 ) ;
if ( ! F_19 () )
F_27 ( V_55 ) ;
if ( F_17 () )
F_26 ( V_39 ) ;
else
F_27 ( V_39 ) ;
if ( ! F_23 () ) {
F_27 ( V_47 ) ;
F_27 ( V_48 ) ;
}
}
static void F_28 ( int V_56 , unsigned long V_57 )
{
F_29 ( V_56 , V_57 ) ;
}
static unsigned long F_30 ( int V_56 )
{
return F_31 ( V_56 ) ;
}
static void F_32 ( struct V_58 * V_59 )
{
F_33 () ;
F_34 ( V_59 ) ;
}
static unsigned long F_35 ( void )
{
return 0 ;
}
static void F_36 ( void * V_60 , T_3 V_61 )
{
int V_62 ;
T_4 * V_63 ;
T_4 V_64 ;
unsigned long V_65 ;
struct V_66 * V_66 ;
unsigned char V_67 ;
V_63 = F_37 ( ( unsigned long ) V_60 , & V_62 ) ;
F_38 ( V_63 == NULL ) ;
V_65 = F_39 ( * V_63 ) ;
V_66 = F_40 ( V_65 ) ;
V_64 = F_41 ( V_65 , V_61 ) ;
F_42 () ;
F_43 ( & V_67 , V_60 , 1 ) ;
if ( F_44 ( ( unsigned long ) V_60 , V_64 , 0 ) )
F_6 () ;
if ( ! F_45 ( V_66 ) ) {
void * V_68 = F_46 ( F_47 ( V_65 ) ) ;
if ( V_68 != V_60 )
if ( F_44 ( ( unsigned long ) V_68 , V_64 , 0 ) )
F_6 () ;
} else
F_48 () ;
F_49 () ;
}
static void F_50 ( struct V_69 * V_70 , unsigned V_71 )
{
const unsigned V_72 = V_73 / V_74 ;
int V_75 ;
for ( V_75 = 0 ; V_75 < V_71 ; V_75 += V_72 )
F_36 ( V_70 + V_75 , V_76 ) ;
}
static void F_51 ( struct V_69 * V_70 , unsigned V_71 )
{
const unsigned V_72 = V_73 / V_74 ;
int V_75 ;
for ( V_75 = 0 ; V_75 < V_71 ; V_75 += V_72 )
F_36 ( V_70 + V_75 , V_77 ) ;
}
static void F_52 ( const void * V_78 , unsigned V_71 )
{
struct V_79 * V_29 ;
struct V_80 V_81 = F_53 ( sizeof( * V_29 ) ) ;
F_54 ( V_78 , V_71 ) ;
V_29 = V_81 . args ;
V_29 -> V_30 = V_82 ;
V_29 -> V_83 . V_84 = ( unsigned long ) V_78 ;
V_29 -> V_85 . V_86 = V_71 ;
F_55 ( V_81 . V_87 , V_29 , 1 , NULL , V_88 ) ;
F_56 ( V_89 ) ;
}
static void F_57 ( const struct V_90 * V_91 )
{
unsigned long V_92 = V_91 -> V_93 ;
unsigned int V_94 = V_91 -> V_94 + 1 ;
unsigned V_95 = F_58 ( V_94 , V_73 ) ;
unsigned long V_96 [ V_95 ] ;
int V_97 ;
F_38 ( V_94 > 65536 ) ;
F_38 ( V_92 & ~ V_98 ) ;
for ( V_97 = 0 ; V_92 < V_91 -> V_93 + V_94 ; V_92 += V_73 , V_97 ++ ) {
int V_62 ;
T_4 * V_63 ;
unsigned long V_65 , V_99 ;
void * V_100 ;
V_63 = F_37 ( V_92 , & V_62 ) ;
F_38 ( V_63 == NULL ) ;
V_65 = F_39 ( * V_63 ) ;
V_99 = F_59 ( V_65 ) ;
V_100 = F_46 ( F_47 ( V_65 ) ) ;
V_96 [ V_97 ] = V_99 ;
F_60 ( ( void * ) V_92 ) ;
F_60 ( V_100 ) ;
}
if ( F_61 ( V_96 , V_94 / sizeof( struct V_69 ) ) )
F_6 () ;
}
static void T_1 F_62 ( const struct V_90 * V_91 )
{
unsigned long V_92 = V_91 -> V_93 ;
unsigned int V_94 = V_91 -> V_94 + 1 ;
unsigned V_95 = F_58 ( V_94 , V_73 ) ;
unsigned long V_96 [ V_95 ] ;
int V_97 ;
F_38 ( V_94 > 65536 ) ;
F_38 ( V_92 & ~ V_98 ) ;
for ( V_97 = 0 ; V_92 < V_91 -> V_93 + V_94 ; V_92 += V_73 , V_97 ++ ) {
T_4 V_64 ;
unsigned long V_65 , V_99 ;
V_65 = F_63 ( V_92 ) ;
V_99 = F_59 ( V_65 ) ;
V_64 = F_41 ( V_65 , V_76 ) ;
if ( F_44 ( ( unsigned long ) V_92 , V_64 , 0 ) )
F_6 () ;
V_96 [ V_97 ] = V_99 ;
}
if ( F_61 ( V_96 , V_94 / sizeof( struct V_69 ) ) )
F_6 () ;
}
static inline bool F_64 ( const struct V_69 * V_101 ,
const struct V_69 * V_102 )
{
return V_101 -> V_103 == V_102 -> V_103 && V_101 -> V_104 == V_102 -> V_104 ;
}
static void F_65 ( struct V_105 * V_106 ,
unsigned int V_1 , unsigned int V_75 )
{
struct V_69 * V_107 = & F_66 ( V_108 , V_1 ) . V_109 [ V_75 ] ;
struct V_69 * V_110 ;
T_5 V_111 ;
struct V_80 V_87 ;
if ( F_64 ( V_107 , & V_106 -> V_112 [ V_75 ] ) )
return;
* V_107 = V_106 -> V_112 [ V_75 ] ;
V_110 = F_67 ( V_1 ) ;
V_111 = F_68 ( & V_110 [ V_113 + V_75 ] ) ;
V_87 = F_69 ( 0 ) ;
F_70 ( V_87 . V_87 , V_111 . V_111 , V_106 -> V_112 [ V_75 ] ) ;
}
static void F_71 ( struct V_105 * V_106 , unsigned int V_1 )
{
if ( F_72 () == V_89 ) {
#ifdef F_73
F_74 ( 0 ) ;
#else
F_75 ( V_114 , 0 ) ;
#endif
}
F_76 () ;
F_65 ( V_106 , V_1 , 0 ) ;
F_65 ( V_106 , V_1 , 1 ) ;
F_65 ( V_106 , V_1 , 2 ) ;
F_56 ( V_89 ) ;
}
static void F_77 ( unsigned int V_115 )
{
if ( F_78 ( V_116 , V_115 ) )
F_6 () ;
}
static void F_79 ( struct V_69 * V_117 , int V_118 ,
const void * V_119 )
{
T_5 V_120 = F_68 ( & V_117 [ V_118 ] ) ;
T_6 V_121 = * ( T_6 * ) V_119 ;
F_80 ( V_117 , V_118 , V_121 ) ;
F_42 () ;
F_33 () ;
if ( F_81 ( V_120 . V_111 , V_121 ) )
F_6 () ;
F_49 () ;
}
static int F_82 ( int V_122 , const T_7 * V_57 ,
struct V_123 * V_124 )
{
unsigned long V_78 ;
if ( V_57 -> type != V_125 && V_57 -> type != V_126 )
return 0 ;
V_124 -> V_122 = V_122 ;
V_78 = F_83 ( * V_57 ) ;
#ifdef F_84
if ( V_78 == ( unsigned long ) V_127 )
V_78 = ( unsigned long ) V_128 ;
else if ( V_78 == ( unsigned long ) V_129 )
V_78 = ( unsigned long ) V_130 ;
else if ( V_78 == ( unsigned long ) V_131 )
V_78 = ( unsigned long ) V_132 ;
else if ( V_78 == ( unsigned long ) V_133 ) {
return 0 ;
#ifdef F_85
} else if ( V_78 == ( unsigned long ) V_134 ) {
;
#endif
} else if ( V_78 == ( unsigned long ) V_135 )
;
else {
if ( F_86 ( V_57 -> V_136 != 0 ) )
return 0 ;
}
#endif
V_124 -> V_93 = V_78 ;
V_124 -> V_137 = F_87 ( * V_57 ) ;
V_124 -> V_138 = V_57 -> V_139 ;
if ( V_57 -> type == V_126 )
V_124 -> V_138 |= 1 << 2 ;
return 1 ;
}
static void F_88 ( T_7 * V_117 , int V_118 , const T_7 * V_140 )
{
unsigned long V_141 = ( unsigned long ) & V_117 [ V_118 ] ;
unsigned long V_142 , V_143 ;
F_89 ( V_117 , V_118 , V_140 ) ;
F_42 () ;
V_142 = F_90 ( V_144 . V_93 ) ;
V_143 = V_142 + F_90 ( V_144 . V_94 ) + 1 ;
F_33 () ;
F_91 ( V_117 , V_118 , V_140 ) ;
if ( V_141 >= V_142 && ( V_141 + 8 ) <= V_143 ) {
struct V_123 V_124 [ 2 ] ;
V_124 [ 1 ] . V_93 = 0 ;
if ( F_82 ( V_118 , V_140 , & V_124 [ 0 ] ) )
if ( F_92 ( V_124 ) )
F_6 () ;
}
F_49 () ;
}
static void F_93 ( const struct V_90 * V_109 ,
struct V_123 * V_145 )
{
unsigned V_146 , V_147 , V_148 ;
V_148 = ( V_109 -> V_94 + 1 ) / sizeof( T_7 ) ;
F_38 ( V_148 > 256 ) ;
for ( V_146 = V_147 = 0 ; V_146 < V_148 ; V_146 ++ ) {
T_7 * V_121 = ( T_7 * ) ( V_109 -> V_93 ) + V_146 ;
if ( F_82 ( V_146 , V_121 , & V_145 [ V_147 ] ) )
V_147 ++ ;
}
V_145 [ V_147 ] . V_93 = 0 ;
}
void F_94 ( struct V_123 * V_145 )
{
const struct V_90 * V_109 = F_95 ( & V_144 ) ;
F_93 ( V_109 , V_145 ) ;
}
static void F_96 ( const struct V_90 * V_109 )
{
static F_97 ( V_149 ) ;
static struct V_123 V_145 [ 257 ] ;
F_98 ( V_109 ) ;
F_99 ( & V_149 ) ;
memcpy ( F_95 ( & V_144 ) , V_109 , sizeof( V_144 ) ) ;
F_93 ( V_109 , V_145 ) ;
F_33 () ;
if ( F_92 ( V_145 ) )
F_6 () ;
F_100 ( & V_149 ) ;
}
static void F_101 ( struct V_69 * V_117 , int V_121 ,
const void * V_109 , int type )
{
F_102 ( V_117 , V_121 , V_109 , type ) ;
F_42 () ;
switch ( type ) {
case V_150 :
case V_151 :
break;
default: {
T_5 V_111 = F_68 ( & V_117 [ V_121 ] ) ;
F_33 () ;
if ( F_81 ( V_111 . V_111 , * ( T_6 * ) V_109 ) )
F_6 () ;
}
}
F_49 () ;
}
static void T_1 F_103 ( struct V_69 * V_117 , int V_121 ,
const void * V_109 , int type )
{
F_102 ( V_117 , V_121 , V_109 , type ) ;
switch ( type ) {
case V_150 :
case V_151 :
break;
default: {
T_5 V_111 = F_104 ( & V_117 [ V_121 ] ) ;
if ( F_81 ( V_111 . V_111 , * ( T_6 * ) V_109 ) )
V_117 [ V_121 ] = * (struct V_69 * ) V_109 ;
}
}
}
static void F_105 ( struct V_152 * V_153 ,
struct V_105 * V_154 )
{
struct V_80 V_81 ;
V_81 = F_53 ( 0 ) ;
F_106 ( V_81 . V_87 , V_155 , V_154 -> V_156 ) ;
F_56 ( V_89 ) ;
V_153 -> V_157 . V_156 = V_154 -> V_156 ;
}
void F_107 ( unsigned V_158 )
{
struct V_159 V_160 ;
V_160 . V_161 = ( V_158 == 0 ) ? 1 : ( V_158 >> 12 ) & 3 ;
F_108 ( V_162 , & V_160 ) ;
}
static void F_109 ( void )
{
}
static unsigned long F_110 ( void )
{
unsigned long V_163 = F_111 ( V_164 ) ;
if ( F_112 ( V_163 == 0 ) ) {
V_163 = F_113 () ;
F_114 ( V_164 , V_163 ) ;
}
return V_163 ;
}
static void F_115 ( unsigned long V_163 )
{
struct V_80 V_81 ;
F_114 ( V_164 , V_163 ) ;
V_81 = F_53 ( 0 ) ;
F_116 ( V_81 . V_87 , ( V_163 & V_165 ) != 0 ) ;
F_56 ( V_89 ) ;
}
static void F_117 ( unsigned long V_166 )
{
V_166 &= ~ ( V_167 | V_168 | V_169 ) ;
F_118 ( V_166 ) ;
}
static inline unsigned long F_119 ( void )
{
return 0 ;
}
static inline void F_120 ( unsigned long V_57 )
{
F_38 ( V_57 ) ;
}
static T_6 F_121 ( unsigned int V_170 , int * V_171 )
{
T_6 V_57 ;
if ( F_122 ( V_170 , & V_57 , V_171 ) )
return V_57 ;
V_57 = F_123 ( V_170 , V_171 ) ;
switch ( V_170 ) {
case V_172 :
#ifdef F_124
if ( ! ( F_24 ( 1 ) & ( 1 << ( V_54 & 31 ) ) ) )
#endif
V_57 &= ~ V_173 ;
break;
}
return V_57 ;
}
static int F_125 ( unsigned int V_170 , unsigned V_174 , unsigned V_175 )
{
int V_176 ;
V_176 = 0 ;
switch ( V_170 ) {
#ifdef F_84
unsigned V_177 ;
T_6 V_178 ;
case V_179 : V_177 = V_180 ; goto V_181;
case V_182 : V_177 = V_183 ; goto V_181;
case V_184 : V_177 = V_185 ; goto V_181;
V_181:
V_178 = ( ( T_6 ) V_175 << 32 ) | V_174 ;
if ( F_78 ( V_177 , V_178 ) != 0 )
V_176 = - V_186 ;
break;
#endif
case V_187 :
case V_188 :
case V_189 :
case V_190 :
case V_191 :
case V_192 :
case V_193 :
break;
default:
if ( ! F_126 ( V_170 , V_174 , V_175 , & V_176 ) )
V_176 = F_127 ( V_170 , V_174 , V_175 ) ;
}
return V_176 ;
}
static T_6 F_128 ( unsigned int V_170 )
{
int V_171 ;
return F_121 ( V_170 , & V_171 ) ;
}
static void F_129 ( unsigned int V_170 , unsigned V_174 , unsigned V_175 )
{
F_125 ( V_170 , V_174 , V_175 ) ;
}
void F_130 ( void )
{
F_131 ( V_194 , V_195 -> V_196 ) ;
V_197 =
(struct V_196 * ) F_132 ( V_194 ) ;
#ifndef F_133
F_134 () ;
#endif
F_135 () ;
if ( V_198 == V_199 )
F_136 () ;
}
void F_134 ( void )
{
int V_1 ;
F_2 (cpu) {
F_66 ( V_200 , V_1 ) = V_1 ;
F_8 ( V_1 ) ;
}
if ( V_6 ) {
V_201 . V_202 = F_137 ( V_203 ) ;
V_201 . V_204 = F_137 ( V_205 ) ;
V_201 . V_206 = F_137 ( V_207 ) ;
V_201 . V_208 = F_137 ( V_209 ) ;
V_210 . V_211 = V_212 ;
}
}
static unsigned F_138 ( T_8 type , T_9 V_213 , void * V_214 ,
unsigned long V_78 , unsigned V_215 )
{
char * V_142 , * V_143 , * V_216 ;
unsigned V_176 ;
V_142 = V_143 = V_216 = NULL ;
#define F_139 ( V_29 , T_10 ) \
case PARAVIRT_PATCH(op.x): \
if (xen_have_vcpu_info_placement) { \
start = (char *)xen_##x##_direct; \
end = xen_##x##_direct_end; \
reloc = xen_##x##_direct_reloc; \
} \
goto patch_site
switch ( type ) {
F_139 ( V_201 , V_208 ) ;
F_139 ( V_201 , V_206 ) ;
F_139 ( V_201 , V_202 ) ;
F_139 ( V_201 , V_204 ) ;
#undef F_139
V_217:
if ( V_142 == NULL || ( V_143 - V_142 ) > V_215 )
goto V_218;
V_176 = F_140 ( V_214 , V_215 , V_142 , V_143 ) ;
if ( V_216 > V_142 && V_216 < V_143 ) {
int V_219 = V_216 - V_142 ;
long * V_220 = ( long * ) ( V_214 + V_219 ) ;
long V_221 = V_142 - ( char * ) V_78 ;
* V_220 += V_221 ;
}
break;
V_218:
default:
V_176 = F_141 ( type , V_213 , V_214 ,
V_78 , V_215 ) ;
break;
}
return V_176 ;
}
static void F_142 ( char * V_222 )
{
F_143 ( V_223 ) ;
}
static void F_144 ( void )
{
F_143 ( V_224 ) ;
}
static void F_145 ( void )
{
if ( V_225 )
V_225 () ;
F_143 ( V_224 ) ;
}
static void F_146 ( struct V_226 * V_227 )
{
F_143 ( V_228 ) ;
}
static unsigned char F_147 ( void )
{
unsigned char V_229 = 0 ;
if ( F_148 ( V_230 ,
& V_197 -> V_231 . V_232 ) )
V_229 |= V_233 ;
if ( F_148 ( V_234 ,
& V_197 -> V_231 . V_232 ) )
V_229 |= V_235 ;
return V_229 ;
}
static void T_1 F_149 ( void )
{
#if F_150 ( V_236 )
struct V_28 V_29 ;
struct V_237 * V_237 ;
T_11 * V_238 ;
unsigned V_239 ;
int V_176 ;
V_237 = V_240 . V_241 ;
V_238 = V_240 . V_242 ;
V_29 . V_30 = V_243 ;
V_29 . V_32 . V_244 . type = V_245 ;
for ( V_239 = 0 ; V_239 < V_246 ; V_239 ++ ) {
struct V_237 * V_124 = V_237 + V_239 ;
V_29 . V_32 . V_244 . V_247 = V_239 ;
V_124 -> V_248 . V_249 = sizeof( V_124 -> V_248 ) ;
F_21 ( V_29 . V_32 . V_244 . V_32 . V_250 . V_251 ,
& V_124 -> V_248 ) ;
V_176 = F_22 ( & V_29 ) ;
if ( V_176 )
break;
#define F_151 ( T_10 ) info->x = op.u.firmware_info.u.disk_info.x
F_151 ( V_252 ) ;
F_151 ( V_8 ) ;
F_151 ( V_253 ) ;
F_151 ( V_254 ) ;
F_151 ( V_255 ) ;
F_151 ( V_256 ) ;
#undef F_151
}
V_240 . V_257 = V_239 ;
V_29 . V_32 . V_244 . type = V_258 ;
for ( V_239 = 0 ; V_239 < V_259 ; V_239 ++ ) {
V_29 . V_32 . V_244 . V_247 = V_239 ;
V_176 = F_22 ( & V_29 ) ;
if ( V_176 )
break;
V_238 [ V_239 ] = V_29 . V_32 . V_244 . V_32 . V_260 . V_238 ;
}
V_240 . V_261 = V_239 ;
#endif
}
static void F_152 ( int V_1 )
{
V_262 . V_263 = F_103 ;
V_262 . V_264 = F_62 ;
F_153 ( 0 ) ;
F_154 ( 0 ) ;
V_262 . V_263 = F_101 ;
V_262 . V_264 = F_57 ;
}
static void T_1 F_155 ( void )
{
V_265 . V_266 . V_267 = 1 ;
}
T_12 T_13 void T_1 F_156 ( void )
{
struct V_159 V_160 ;
unsigned long V_268 = 0 ;
int V_269 ;
if ( ! V_195 )
return;
V_270 = V_271 ;
F_157 () ;
F_158 () ;
V_13 = V_272 ;
V_273 = V_274 ;
V_262 = V_275 ;
V_265 . V_276 = F_147 ;
V_277 . V_278 . V_279 = V_280 ;
V_277 . V_281 . V_282 = V_283 ;
V_277 . V_281 . V_284 = F_9 ;
F_159 () ;
V_285 &= ~ V_286 ;
V_287 &= ~ V_288 ;
F_160 () ;
F_161 () ;
F_152 ( 0 ) ;
F_162 () ;
F_25 () ;
#ifdef F_163
F_164 () ;
#endif
if ( F_13 ( V_17 ) ) {
V_210 . V_289 = V_290 ;
V_210 . V_291 = V_292 ;
}
V_293 = V_294 ;
V_295 = & F_66 ( V_296 , 0 ) ;
F_165 () ;
#ifdef F_166
V_297 = - 1 ;
#endif
F_66 ( V_298 , 0 ) = & V_197 -> V_299 [ 0 ] ;
F_86 ( F_167 ( V_300 , V_301 ) ) ;
F_168 () ;
V_302 = true ;
F_169 ( L_5 ) ;
F_170 ( ( V_303 * ) V_195 -> V_304 ,
V_195 -> V_305 ) ;
F_171 () ;
#ifdef F_73
V_13 . V_306 = 1 ;
if ( F_13 ( V_307 ) )
V_13 . V_306 = 0 ;
#else
V_13 . V_306 = 0 ;
#endif
F_172 () ;
V_160 . V_161 = 1 ;
V_269 = F_108 ( V_162 , & V_160 ) ;
if ( V_269 != 0 )
F_173 ( L_6 , V_269 ) ;
#ifdef F_73
F_174 ( & V_308 ) ;
F_175 ( & V_308 , V_309 ) ;
V_308 . V_310 [ V_311 ] = F_176 ( 1 ) ;
#endif
if ( V_195 -> V_312 ) {
if ( V_195 -> V_138 & V_313 )
V_268 = F_47 ( V_195 -> V_312 ) ;
else
V_268 = F_177 ( V_195 -> V_312 ) ;
}
V_240 . V_314 . V_315 = ( 9 << 4 ) | 0 ;
V_240 . V_314 . V_316 = V_268 ;
V_240 . V_314 . V_317 = V_195 -> V_318 ;
V_240 . V_314 . V_319 = F_177 ( V_195 -> V_320 ) ;
V_240 . V_314 . V_321 = V_322 ;
if ( ! F_19 () ) {
F_178 ( L_7 , 0 , NULL ) ;
F_178 ( L_8 , 0 , NULL ) ;
F_178 ( L_9 , 0 , NULL ) ;
if ( V_323 )
V_277 . V_324 . V_325 = V_326 ;
} else {
const struct V_327 * V_124 =
( void * ) ( ( char * ) V_195 +
V_195 -> V_328 . V_329 . V_330 ) ;
struct V_28 V_29 = {
. V_30 = V_243 ,
. V_331 = V_332 ,
. V_32 . V_244 . type = V_333 ,
} ;
V_265 . V_334 =
F_155 ;
F_179 ( V_124 , V_195 -> V_328 . V_329 . V_335 ) ;
V_195 -> V_328 . V_336 . V_99 = 0 ;
V_195 -> V_328 . V_336 . V_337 = 0 ;
if ( F_22 ( & V_29 ) == 0 )
V_240 . V_338 = V_29 . V_32 . V_244 . V_32 . V_339 ;
F_180 () ;
F_181 () ;
V_277 . V_340 . V_341 = V_342 ;
V_277 . V_340 . V_343 = V_344 ;
F_149 () ;
}
#ifdef F_182
V_345 &= ~ V_346 ;
#endif
F_169 ( L_10 ) ;
F_66 ( V_200 , 0 ) = 0 ;
F_7 ( 0 ) ;
F_183 () ;
#ifdef F_73
F_184 () ;
#else
F_185 () ;
F_186 ( ( char * ) F_187 ( & V_240 ) ) ;
#endif
}
static int V_300 ( unsigned int V_1 )
{
int V_269 ;
F_188 ( V_1 ) ;
V_269 = F_189 ( V_1 ) ;
if ( V_269 ) {
F_190 ( 1 , L_11 ,
V_1 , V_269 ) ;
return V_269 ;
}
V_269 = F_191 ( V_1 ) ;
if ( V_269 ) {
F_190 ( 1 , L_12 ,
V_1 , V_269 ) ;
return V_269 ;
}
return 0 ;
}
static int V_301 ( unsigned int V_1 )
{
F_192 ( V_1 ) ;
F_193 ( V_1 ) ;
F_194 ( V_1 ) ;
return 0 ;
}
static T_2 T_1 F_195 ( void )
{
if ( F_196 () )
return F_197 () ;
return 0 ;
}
