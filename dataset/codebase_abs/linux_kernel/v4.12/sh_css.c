static enum V_1
F_1 ( struct V_2 * V_3 )
{
enum V_4 V_5 = V_3 -> V_6 [ 0 ] . V_7 ;
unsigned int V_8 , V_9 = 0 ;
assert ( V_3 != NULL ) ;
assert ( V_3 -> V_10 != NULL ) ;
switch ( V_3 -> V_10 -> V_11 . V_12 . V_7 ) {
case V_13 :
case V_14 :
for ( V_8 = 0 ; V_8 < F_2 ( V_15 ) && ! V_9 ; V_8 ++ )
V_9 = ( V_5 == V_15 [ V_8 ] ) ;
break;
case V_16 :
case V_17 :
V_9 = ( V_5 == V_18 ) ;
break;
case V_19 :
for ( V_8 = 0 ; V_8 < F_2 ( V_20 ) && ! V_9 ; V_8 ++ )
V_9 = ( V_5 == V_20 [ V_8 ] ) ;
break;
case V_21 :
case V_22 :
V_9 = ( V_5 == V_23 ||
V_5 == V_18 ) ;
break;
case V_24 :
case V_25 :
case V_26 :
V_9 = ( V_5 == V_27 ||
V_5 == V_28 ) ;
break;
case V_29 :
case V_30 :
V_9 = ( V_5 == V_27 ||
V_5 == V_31 ) ;
break;
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
V_9 = ( V_5 == V_39 ) ||
( V_5 == V_40 ) ;
break;
case V_41 :
V_9 = ( V_5 == V_42 ) ;
break;
default:
break;
}
if ( ! V_9 )
return V_43 ;
return V_44 ;
}
unsigned int
F_3 ( struct V_45 * V_10 )
{
int V_46 = 0 ;
if ( V_10 != NULL )
V_46 = F_4 ( V_10 -> V_11 . V_12 . V_7 ,
V_10 -> V_11 . V_47 == 2 ) ;
return V_46 ;
}
static enum V_1
F_5 ( struct V_45 * V_10 )
{
unsigned int V_48 ;
struct V_2 * V_3 = V_10 -> V_49 ;
struct V_50 * V_51 = NULL ;
enum V_1 V_52 = V_44 ;
assert ( V_10 != NULL ) ;
assert ( V_3 != NULL ) ;
F_6 ( V_53 ,
L_1 ) ;
if ( V_3 -> V_54 . V_55 )
V_51 = V_3 -> V_54 . V_55 -> V_51 ;
V_52 = F_7 (
V_10 -> V_11 . V_12 . V_7 ,
V_10 -> V_56 . V_57 ,
& V_48 ) ;
if ( V_52 != V_44 )
return V_52 ;
F_8 ( V_48 ,
V_10 -> V_11 . V_58 ,
V_10 -> V_11 . V_59 ) ;
if ( ( V_51 && ( V_51 -> V_60 || V_10 -> V_11 . V_61 ) ) ||
V_3 -> V_11 . V_59 == V_62 ) {
V_52 = F_9 ( & V_10 -> V_11 ,
V_51 ) ;
if ( V_52 != V_44 )
return V_52 ;
}
if ( V_10 -> V_11 . V_59 == V_63 ||
V_10 -> V_11 . V_59 == V_64 ) {
unsigned int V_65 = 100 ,
V_66 = 6 ,
V_67 ,
V_68 ,
V_69 ;
V_67 = ( V_10 -> V_11 . V_12 . V_70 . V_67 ) / ( 1 + ( V_10 -> V_11 . V_47 == 2 ) ) ;
V_68 = V_10 -> V_11 . V_12 . V_70 . V_68 ;
V_69 = V_66 * ( V_67 + V_65 ) ;
F_10 ( V_67 , V_68 , V_65 ,
V_69 ) ;
#if F_11 ( V_71 )
if ( V_3 -> V_10 -> V_11 . V_59 == V_63 ) {
#define F_12 0x90058
F_13 ( F_12 , 0 ) ;
}
#endif
}
F_6 ( V_53 ,
L_2 ) ;
return V_44 ;
}
static unsigned int F_14 (
enum V_72 V_7 ,
unsigned int V_73 )
{
unsigned int V_74 ;
switch ( V_7 ) {
case V_13 :
V_74 = V_73 * 2 ;
break;
case V_14 :
case V_16 :
case V_17 :
V_74 = V_73 * 2 ;
break;
case V_19 :
case V_21 :
case V_22 :
V_74 = V_73 * 2 ;
break;
case V_24 :
case V_25 :
case V_26 :
case V_29 :
case V_30 :
V_74 = V_73 * 4 ;
break;
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_41 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
V_74 = V_73 ;
break;
default:
V_74 = 0 ;
break;
}
return V_74 ;
}
static bool F_15 (
struct V_83 * V_84 ,
T_1 * V_85 )
{
bool V_86 ;
V_86 = true ;
switch ( V_84 -> V_59 ) {
case V_63 :
if ( V_84 -> V_87 . V_88 . V_89 == V_90 ) {
V_85 -> V_91 = V_92 ;
} else if ( V_84 -> V_87 . V_88 . V_89 == V_93 ) {
V_85 -> V_91 = V_94 ;
} else if ( V_84 -> V_87 . V_88 . V_89 == V_95 ) {
V_85 -> V_91 = V_96 ;
}
break;
case V_64 :
if ( V_84 -> V_87 . V_97 . V_89 == V_98 ) {
V_85 -> V_91 = V_92 ;
} else if ( V_84 -> V_87 . V_97 . V_89 == V_99 ) {
V_85 -> V_91 = V_94 ;
} else if ( V_84 -> V_87 . V_97 . V_89 == V_100 ) {
V_85 -> V_91 = V_96 ;
}
break;
case V_101 :
if ( V_84 -> V_87 . V_102 . V_102 == V_103 ) {
V_85 -> V_91 = V_104 ;
} else if ( V_84 -> V_87 . V_102 . V_102 == V_105 ) {
V_85 -> V_91 = V_106 ;
} else if ( V_84 -> V_87 . V_102 . V_102 == V_107 ) {
V_85 -> V_91 = V_108 ;
}
break;
default:
V_86 = false ;
break;
}
return V_86 ;
}
static bool F_16 (
struct V_83 * V_84 ,
T_1 * V_85 )
{
bool V_86 ;
V_86 = true ;
switch ( V_84 -> V_59 ) {
case V_63 :
V_85 -> V_59 = V_109 ;
break;
case V_64 :
V_85 -> V_59 = V_110 ;
break;
case V_111 :
case V_101 :
V_85 -> V_59 = V_112 ;
break;
default:
V_86 = false ;
break;
}
return V_86 ;
}
static bool F_17 (
struct V_83 * V_84 ,
T_1 * V_85 ,
int V_113 )
{
bool V_86 ;
V_86 = true ;
switch ( V_84 -> V_59 ) {
case V_63 :
if ( V_84 -> V_87 . V_88 . V_59 == V_114 ) {
V_85 -> V_115 . V_59 = V_116 ;
} else if ( V_84 -> V_87 . V_88 . V_59 == V_117 ) {
V_85 -> V_115 . V_59 = V_118 ;
} else if ( V_84 -> V_87 . V_88 . V_59 == V_119 ) {
V_85 -> V_115 . V_59 = V_120 ;
} else {
V_86 = false ;
}
V_85 -> V_115 . V_121 . V_122 = 51 ;
V_85 -> V_115 . V_121 . V_123 = 102 ;
V_85 -> V_115 . V_121 . V_124 = 255 ;
V_85 -> V_115 . V_121 . V_125 = 0 ;
V_85 -> V_115 . V_121 . V_126 = 100 ;
V_85 -> V_115 . V_121 . V_127 = 160 ;
V_85 -> V_115 . V_128 . V_129 = V_84 -> V_87 . V_88 . V_130 ;
V_85 -> V_115 . V_128 . V_131 = V_84 -> V_87 . V_88 . V_132 ;
V_85 -> V_115 . V_128 . V_133 = V_84 -> V_87 . V_88 . V_134 ;
V_85 -> V_115 . V_135 . V_136 = V_84 -> V_87 . V_88 . V_137 ;
V_85 -> V_115 . V_135 . V_138 = V_84 -> V_87 . V_88 . V_139 ;
V_85 -> V_115 . V_140 . V_65 = 100 ;
V_85 -> V_115 . V_140 . V_69 = 100 ;
V_85 -> V_115 . V_140 . V_47 = V_84 -> V_47 ;
V_85 -> V_115 . V_140 . V_141 = ( V_142 ) ~ ( 0x0 ) ;
V_85 -> V_115 . V_140 . V_73 = V_84 -> V_143 [ V_144 ] . V_70 . V_67 ;
V_85 -> V_115 . V_140 . V_145 = V_84 -> V_143 [ V_144 ] . V_70 . V_68 ;
break;
case V_64 :
V_85 -> V_146 . V_147 = V_84 -> V_87 . V_97 . V_148 ;
V_85 -> V_146 . V_149 = V_84 -> V_87 . V_97 . V_149 ;
V_85 -> V_146 . V_140 . V_65 = 100 ;
V_85 -> V_146 . V_140 . V_69 = 100 ;
V_85 -> V_146 . V_140 . V_47 = V_84 -> V_47 ;
V_85 -> V_146 . V_140 . V_141 = ( V_142 ) ~ ( 0x0 ) ;
V_85 -> V_146 . V_140 . V_73 = V_84 -> V_143 [ V_144 ] . V_70 . V_67 ;
V_85 -> V_146 . V_140 . V_145 = V_84 -> V_143 [ V_144 ] . V_70 . V_68 ;
break;
case V_101 :
{
enum V_1 V_52 ;
unsigned int V_48 ;
V_52 = F_7 (
V_84 -> V_143 [ V_113 ] . V_7 ,
V_150 ,
& V_48 ) ;
if ( V_52 != V_44 )
V_86 = false ;
V_85 -> V_151 . V_152 = V_84 -> V_87 . V_102 . V_153 ;
V_85 -> V_151 . V_48 = V_48 ;
V_85 -> V_151 . V_154 = V_84 -> V_58 ;
#ifdef F_18
V_85 -> V_60 = V_84 -> V_60 ;
#endif
V_52 |= F_19 (
& V_84 -> V_87 . V_102 . V_155 ,
V_85 ) ;
if ( V_52 != V_44 )
V_86 = false ;
V_85 -> V_156 . V_157 = false ;
if ( V_84 -> V_158 . V_159 . V_68 > 0 ) {
V_52 = F_7 (
V_84 -> V_158 . V_160 ,
V_150 ,
& V_48 ) ;
if ( V_52 != V_44 )
V_86 = false ;
V_85 -> V_156 . V_48 = V_48 ;
V_85 -> V_156 . V_161 =
F_4 ( V_84 -> V_158 . V_160 , true ) ;
V_85 -> V_156 . V_73 = V_84 -> V_158 . V_159 . V_67 ;
V_85 -> V_156 . V_145 = V_84 -> V_158 . V_159 . V_68 ;
#ifdef F_18
if ( V_85 -> V_156 . V_145 > 0 )
V_85 -> V_156 . V_145 +=
( V_85 -> V_156 . V_145 & 1 ) ;
#endif
V_85 -> V_156 . V_162 =
F_20 ( V_84 -> V_158 . V_160 ) ;
V_85 -> V_156 . V_157 = true ;
}
break;
}
default:
V_86 = false ;
break;
}
return V_86 ;
}
static bool F_21 (
struct V_83 * V_84 ,
T_1 * V_85 ,
int V_113 )
{
unsigned int V_163 ;
unsigned int V_164 ;
unsigned int V_145 ;
unsigned int V_162 ;
enum V_72 V_48 ;
V_48 = V_84 -> V_143 [ V_113 ] . V_7 ;
if ( ( V_84 -> V_59 == V_111 ||
V_84 -> V_59 == V_101 ) &&
V_84 -> V_87 . V_102 . V_155 . type != V_165 ) {
if ( V_84 -> V_87 . V_102 . V_155 . V_166 ==
V_167 ) {
V_48 = V_35 ;
}
else if ( V_84 -> V_87 . V_102 . V_155 . V_166 ==
V_168 ) {
V_48 = V_36 ;
}
else
return false ;
}
V_163 =
F_22 ( V_48 ) ;
if ( V_163 == 0 )
return false ;
V_164 =
F_14 ( V_48 ,
V_84 -> V_143 [ V_113 ] . V_70 . V_67 ) ;
if ( V_164 == 0 )
return false ;
V_145 = V_84 -> V_143 [ V_113 ] . V_70 . V_68 ;
if ( V_145 == 0 )
return false ;
V_162 = F_20 ( V_48 ) ;
V_85 -> V_169 . V_161 = V_163 ;
V_85 -> V_169 . V_73 = V_164 ;
V_85 -> V_169 . V_145 = V_145 ;
V_85 -> V_169 . V_162 = V_162 ;
return true ;
}
static bool F_23 (
struct V_83 * V_84 ,
bool V_170 ,
T_1 * V_85 ,
int V_113 )
{
bool V_86 ;
F_6 ( V_53 ,
L_3 ) ;
V_86 = F_15 ( V_84 , V_85 ) ;
V_86 &= F_16 ( V_84 , V_85 ) ;
V_86 &= F_17 ( V_84 , V_85 , V_113 ) ;
V_86 &= F_21 ( V_84 , V_85 , V_113 ) ;
V_85 -> V_171 = V_84 -> V_172 ;
V_85 -> V_173 = ( V_174 ) V_84 -> V_143 [ V_113 ] . V_173 ;
V_85 -> V_175
= V_170 ? V_176
: V_177 ;
F_6 ( V_53 ,
L_4 ) ;
return V_86 ;
}
static bool F_24 (
struct V_50 * V_51 ,
T_1 * V_85 )
{
if ( ! V_51 )
return false ;
V_85 -> V_178 . V_179 = V_51 -> V_179 ;
V_85 -> V_178 . V_180 = V_51 -> V_181 -> V_182 . V_183 . V_184 ;
return true ;
}
static enum V_1
F_5 ( struct V_45 * V_10 )
{
bool V_86 ;
T_1 V_85 ;
unsigned int V_185 ;
struct V_186 * V_187 ;
struct V_2 * V_3 = NULL ;
struct V_50 * V_51 = NULL ;
int V_8 ;
V_142 V_188 ;
bool V_170 = false ;
assert ( V_10 != NULL ) ;
F_6 ( V_53 ,
L_5 , V_10 ) ;
if ( V_10 -> V_11 . V_61 == true ) {
if ( V_10 -> V_49 -> V_11 . V_59 == V_189 ) {
V_3 = V_10 -> V_49 ;
} else if ( V_10 -> V_49 -> V_11 . V_59 == V_190 ) {
V_3 = V_10 -> V_49 ;
} else if ( V_10 -> V_49 -> V_11 . V_59 == V_191 ) {
V_3 = V_10 -> V_49 -> V_192 . V_193 . V_194 ;
} else if ( V_10 -> V_49 -> V_11 . V_59 == V_195 ) {
V_3 = V_10 -> V_49 -> V_192 . V_196 . V_194 ;
}
} else {
V_3 = V_10 -> V_49 ;
if ( V_10 -> V_49 -> V_11 . V_59 == V_189 ) {
V_170 = true ;
}
}
assert ( V_3 != NULL ) ;
if ( V_3 == NULL )
return V_197 ;
if ( V_3 -> V_54 . V_55 != NULL )
if ( V_3 -> V_54 . V_55 -> V_51 != NULL )
V_51 = V_3 -> V_54 . V_55 -> V_51 ;
if ( V_51 ) {
F_25 ( V_3 , & V_51 -> V_198 ) ;
}
V_86 = F_26 ( F_27 ( V_3 ) , & V_185 ) ;
if ( V_86 != true )
return V_197 ;
V_187 = & ( V_199 . V_200 [ V_185 ] . V_183 ) ;
for ( V_8 = 0 ; V_8 < V_201 ; V_8 ++ ) {
memset ( ( void * ) ( & V_85 ) , 0 , sizeof( T_1 ) ) ;
V_187 -> V_202 . V_203 [ V_8 ] . V_204 = 0 ;
V_187 -> V_205 . V_206 [ V_8 ] . V_204 = 0 ;
if ( ! V_10 -> V_11 . V_143 [ V_8 ] . V_204 )
continue;
V_86 = F_23 (
& ( V_10 -> V_11 ) ,
V_170 ,
& ( V_85 ) , V_8 ) ;
if ( V_10 -> V_11 . V_60 ) {
V_86 &= F_24 (
V_51 ,
& ( V_85 ) ) ;
}
if ( V_86 != true )
return V_197 ;
V_188 = F_28 ( V_185 , V_8 ) ;
V_86 = F_29 (
& ( V_85 ) ,
& ( V_187 -> V_202 . V_203 [ V_8 ] ) ,
V_188 ) ;
if ( V_86 != true )
return V_197 ;
V_86 = F_30 (
& ( V_187 -> V_202 . V_203 [ V_8 ] ) ,
& ( V_85 ) ,
& ( V_187 -> V_205 . V_206 [ V_8 ] ) ) ;
if ( V_86 != true ) {
F_31 ( & ( V_187 -> V_202 . V_203 [ V_8 ] ) ) ;
return V_197 ;
}
}
F_6 ( V_53 ,
L_2 ) ;
return V_44 ;
}
static inline struct V_2 * F_32 (
struct V_45 * V_10 )
{
struct V_2 * V_49 = NULL ;
if ( V_10 != NULL )
V_49 = V_10 -> V_49 ;
return V_49 ;
}
static inline struct V_2 * F_33 (
struct V_45 * V_10 )
{
struct V_2 * V_194 = NULL ;
struct V_2 * V_49 = NULL ;
enum V_207 V_208 ;
V_49 = F_32 ( V_10 ) ;
if ( ( V_10 != NULL ) &&
( V_49 != NULL ) &&
( V_10 -> V_11 . V_61 ) ) {
V_208 = V_49 -> V_59 ;
switch ( V_208 ) {
case V_209 :
V_194 = V_49 -> V_192 . V_193 . V_194 ;
break;
case V_210 :
V_194 = V_49 -> V_192 . V_196 . V_194 ;
break;
default:
V_194 = NULL ;
break;
}
}
return V_194 ;
}
static inline struct V_2 * F_34 (
struct V_45 * V_10 )
{
struct V_2 * V_211 ;
if ( V_10 -> V_11 . V_61 ) {
V_211 = F_33 ( V_10 ) ;
} else {
V_211 = F_32 ( V_10 ) ;
}
return V_211 ;
}
static inline enum V_1 F_35 (
struct V_45 * V_10 )
{
return F_36 ( V_10 , V_212 ) ;
}
static inline enum V_1 F_37 (
struct V_45 * V_10 )
{
return F_36 ( V_10 , V_213 ) ;
}
static void F_38 ( char * V_214 , struct V_215 * V_216 )
{
unsigned V_8 ;
unsigned V_217 = 0 ;
unsigned V_218 = 0 ;
if ( V_216 == NULL )
return;
F_39 ( L_6 , V_214 , V_216 -> V_219 ) ;
F_39 ( L_7 , V_214 ) ;
for ( V_8 = 0 ; V_8 < V_216 -> V_219 ; V_8 ++ ) {
if ( ( V_216 -> V_220 [ V_8 ] == 0 ) && ( V_216 -> V_220 [ V_8 ] == V_216 -> V_221 [ V_8 ] ) )
continue;
F_39 ( L_8 ,
V_214 , V_8 , V_216 -> V_220 [ V_8 ] , V_216 -> V_221 [ V_8 ] ) ;
V_217 += V_216 -> V_220 [ V_8 ] ;
V_218 += V_216 -> V_221 [ V_8 ] ;
}
F_39 ( L_9
L_10 ,
V_214 , V_217 , V_218 , V_216 -> V_219 ) ;
}
static void F_40 ( void )
{
struct V_222 * V_223 ;
for ( V_223 = V_224 . V_225 ;
V_223 ;
V_223 = V_223 -> V_226 ) {
if ( V_223 -> V_59 == V_227 ||
V_223 -> V_59 == V_228 ) {
F_39 ( L_11 ,
V_223 -> V_89 ) ;
continue;
}
F_39 ( L_12 , V_223 -> V_89 ) ;
F_38 ( L_13 , & V_223 -> V_229 ) ;
F_38 ( L_14 , & V_223 -> V_230 ) ;
F_39 ( L_15
L_16 , V_223 -> V_89 ) ;
}
F_39 ( L_17 ) ;
}
static int F_41 ( void * V_231 )
{
int V_8 = 0 ;
( void ) V_231 ;
while ( true ) {
if ( V_232 ) {
F_42 () ;
#if V_233
for ( V_8 = 0 ; V_8 < V_234 ; V_8 ++ )
F_42 () ;
#endif
}
F_43 ( 10 , 50 ) ;
}
return 0 ;
}
static void F_44 ( void )
{
V_235 = F_45 ( F_41 , NULL , L_18 ) ;
F_46 ( 1 ) ;
}
static void F_47 ( struct V_236 V_237 )
{
F_39 ( L_19
L_20 ,
V_237 . V_238 . V_67 , V_237 . V_238 . V_68 , V_237 . V_7 ) ;
}
static void
F_48 ( struct V_2 * V_3 ,
struct V_50 * V_51 )
{
struct V_45 * V_10 ;
assert ( V_3 != NULL ) ;
( void ) V_51 ;
#if ! F_11 ( V_239 )
V_10 = V_3 -> V_10 ;
#else
( void ) V_3 ;
( void ) V_10 ;
#endif
if ( V_51 )
F_49 ( & V_51 -> V_223 ) ;
#if V_240
F_39 ( L_21
L_22 ,
V_241 , V_51 -> V_181 -> V_182 . V_89 ,
V_51 -> V_181 -> V_182 . V_157 . V_242 ) ;
F_47 ( V_51 -> V_198 ) ;
if ( V_51 && V_51 -> V_181 -> V_182 . V_54 . V_59 == V_243 )
V_232 = true ;
#endif
#if ! F_11 ( V_239 ) && ! F_11 ( F_18 )
if ( V_10 -> V_244 ) {
F_50 ( & V_3 -> V_10 -> V_56 ,
V_3 -> V_10 -> V_11 . V_59 ) ;
V_10 -> V_244 = false ;
}
#endif
}
static enum V_1
F_51 ( struct V_2 * V_3 ,
struct V_245 * V_246 )
{
( void ) V_246 ;
assert ( V_3 != NULL ) ;
assert ( V_3 -> V_10 != NULL ) ;
if ( ( V_3 == NULL ) || ( V_3 -> V_10 == NULL ) )
return V_43 ;
#if ! F_11 ( V_239 ) && ! F_11 ( F_18 )
if ( V_3 -> V_10 -> V_244 )
F_52 () ;
#endif
if ( V_3 -> V_10 -> V_11 . V_12 . V_7 != V_41 )
return V_197 ;
F_53 ( F_27 ( V_3 ) , V_246 , V_3 -> V_10 -> V_11 . V_47 == 2 ) ;
#if ! F_11 ( V_239 ) && ! F_11 ( F_18 )
if ( V_3 -> V_10 -> V_244 ) {
F_50 ( & V_3 -> V_10 -> V_56 , V_3 -> V_10 -> V_11 . V_59 ) ;
V_3 -> V_10 -> V_244 = false ;
}
#endif
return V_44 ;
}
void F_54 ( struct V_247 * args )
{
unsigned int V_8 ;
#ifndef F_55
for ( V_8 = 0 ; V_8 < V_248 ; V_8 ++ )
#else
for ( V_8 = 0 ; V_8 < V_249 ; V_8 ++ )
#endif
args -> V_250 [ V_8 ] = NULL ;
for ( V_8 = 0 ; V_8 < V_251 ; V_8 ++ )
args -> V_252 [ V_8 ] = NULL ;
args -> V_253 = NULL ;
for ( V_8 = 0 ; V_8 < V_254 ; V_8 ++ )
args -> V_246 [ V_8 ] = NULL ;
args -> V_255 = NULL ;
args -> V_256 = false ;
args -> V_257 = true ;
args -> V_258 = 0 ;
}
static void F_56 (
struct V_2 * V_259 ,
enum V_260 V_261 ,
enum V_262 V_263 )
{
#if F_11 ( V_239 )
( void ) V_263 ;
#endif
F_57 ( L_23 ,
V_259 , V_261 , V_263 ) ;
assert ( V_259 != NULL ) ;
F_58 (&me->pipeline,
me->mode,
(uint8_t)ia_css_pipe_get_pipe_num(me),
me->config.default_capture_config.enable_xnr != 0 ,
me->stream->config.pixels_per_clock == 2 ,
me->stream->config.continuous,
false,
me->required_bds_factor,
copy_ovrd,
input_mode,
&me->stream->config.metadata_config,
#ifndef F_55
&me->stream->info.metadata_info
#else
&me->stream->info.metadata_info,
#endif
#if ! F_11 ( V_239 )
#ifndef F_55
, (input_mode==IA_CSS_INPUT_MODE_MEMORY)?
#else
(input_mode == IA_CSS_INPUT_MODE_MEMORY) ?
#endif
(mipi_port_ID_t)0 :
#ifndef F_55
me->stream->config.source.port.port
#else
me->stream->config.source.port.port,
#endif
#endif
#ifndef F_55
) ;
#else
& V_259 -> V_11 . V_264 ,
V_259 -> V_10 -> V_265 ) ;
static void
F_59 ( enum V_266 V_267 )
{
#ifdef F_60
T_2 V_102 ;
#endif
bool V_268 = V_267 != V_269 ;
F_57 ( L_24 ) ;
F_61 ( V_270 , true ) ;
F_62 ( V_271 , V_268 ) ;
F_63 ( V_272 , true ) ;
F_63 (
( V_273 ) ( V_274 + V_275 ) ,
true ) ;
F_63 (
( V_273 ) ( V_276 + V_275 ) ,
true ) ;
#if ! F_11 ( V_277 )
F_63 (
( V_273 ) ( V_278 + V_275 ) ,
true ) ;
F_64 () ;
#endif
#ifdef F_60
for ( V_102 = 0 ; V_102 < V_279 ; V_102 ++ )
F_65 ( V_102 ) ;
#endif
F_66 ( L_24 ) ;
}
static bool F_67 ( const struct V_280 * V_281 ,
const char * V_282 ,
T_3 * V_283 )
{
if( ( V_281 == NULL ) || ( V_283 == NULL ) )
return false ;
V_283 -> V_284 = 0 ;
V_283 -> V_285 = ( char * ) ( V_282 ) ;
#if ! F_11 ( V_286 )
V_283 -> V_287 = V_281 -> V_288 . V_289 ;
V_283 -> V_290 = V_281 -> V_288 . V_291 ;
V_283 -> V_292 = V_281 -> V_288 . V_293 ;
V_283 -> V_294 = V_281 -> V_288 . V_294 ;
V_283 -> V_295 = V_281 -> V_288 . V_295 ;
V_283 -> V_296 = V_281 -> V_181 . V_297 . V_298 ;
V_283 -> V_299 = V_281 -> V_181 . V_297 . V_300 ;
V_283 -> V_301 = V_281 -> V_181 . V_297 . V_302 ;
V_283 -> V_303 = V_281 -> V_288 . V_304 ;
V_283 -> V_305 = V_281 -> V_288 . V_305 ;
V_283 -> V_284 = V_281 -> V_181 . V_297 . V_284 ;
#endif
return true ;
}
static bool F_68 ( const struct V_280 * V_281 ,
const char * V_282 ,
T_4 * V_306 )
{
if( ( V_281 == NULL ) || ( V_306 == NULL ) )
return false ;
V_306 -> V_307 = 0 ;
V_306 -> V_285 = ( char * ) ( V_282 ) ;
#if ! F_11 ( V_286 )
V_306 -> V_287 = V_281 -> V_288 . V_289 ;
V_306 -> V_290 = V_281 -> V_288 . V_291 ;
V_306 -> V_292 = V_281 -> V_288 . V_293 ;
V_306 -> V_294 = V_281 -> V_288 . V_294 ;
V_306 -> V_295 = V_281 -> V_288 . V_295 ;
V_306 -> V_308 = V_281 -> V_181 . V_182 . V_309 ;
V_306 -> V_310 = V_281 -> V_181 . V_182 . V_298 ;
V_306 -> V_303 = V_281 -> V_288 . V_304 ;
V_306 -> V_305 = V_281 -> V_288 . V_305 ;
V_306 -> V_307 = V_281 -> V_181 . V_182 . V_307 ;
#endif
return true ;
}
void
F_69 ( void )
{
if ( V_311 )
{
F_70 () ;
F_71 () ;
}
V_312 = false ;
}
static void
F_72 ( struct V_313 * V_314 )
{
struct V_313 V_315 ;
memset ( & V_315 , 0 , sizeof( V_315 ) ) ;
V_315 . V_316 = true ;
V_315 . V_317 = V_318 ;
V_315 . V_267 = V_269 ;
* V_314 = V_315 ;
}
bool
F_73 ( const struct V_319 * V_281 )
{
bool V_320 = false ;
if ( V_281 != NULL ) {
V_320 = F_74 ( V_281 -> V_231 ) ;
}
return V_320 ;
}
enum V_1
F_75 ( const struct V_321 * V_322 ,
const struct V_319 * V_281 )
{
enum V_1 V_52 ;
if ( V_322 == NULL )
return V_43 ;
if ( V_281 == NULL )
return V_43 ;
F_6 ( V_323 , L_25 ) ;
if ( V_324 . V_325 != V_322 -> V_326 . V_325 ) {
F_72 ( & V_324 ) ;
V_324 . V_325 = V_322 -> V_326 . V_325 ;
}
F_69 () ;
V_52 = F_76 ( V_281 -> V_231 , V_281 -> V_327 ) ;
if ( V_52 == V_44 ) {
V_52 = F_77 () ;
if ( V_52 == V_44 )
V_312 = true ;
}
F_6 ( V_323 , L_26 ) ;
return V_52 ;
}
enum V_1
F_78 ( const struct V_321 * V_322 ,
const struct V_319 * V_281 ,
V_142 V_328 ,
enum V_266 V_267 )
{
enum V_1 V_52 ;
T_4 V_306 ;
#if F_11 ( V_329 )
T_3 V_283 ;
#endif
void (* F_79)( struct V_330 * V_281 );
T_5 V_331 , V_157 ;
F_80 ( sizeof( struct V_332 ) != V_333 ) ;
F_80 ( sizeof( struct V_334 ) != V_335 ) ;
F_80 ( sizeof( struct V_336 ) != V_337 ) ;
F_80 ( sizeof( struct V_338 ) != V_339 ) ;
F_80 ( sizeof( struct V_340 ) != V_341 ) ;
F_80 ( sizeof( struct V_342 ) != V_343 ) ;
F_80 ( sizeof( struct V_344 ) != V_345 ) ;
F_80 ( sizeof( struct V_346 ) != V_347 ) ;
F_80 ( sizeof( struct V_348 ) != V_349 ) ;
F_80 ( sizeof( struct V_350 ) != V_351 ) ;
F_80 ( sizeof( struct V_352 ) != V_353 ) ;
if ( V_281 == NULL && ! V_312 )
return V_43 ;
if ( V_322 == NULL )
return V_43 ;
V_354 = V_322 -> V_355 . V_356 ;
F_81 ( L_27 ) ;
F_79 = V_322 -> V_326 . V_325 ;
F_82 () ;
F_83 () ;
F_84 () ;
F_85 ( & V_322 -> V_357 ) ;
V_331 = F_86 ( V_358 , V_359 )
& ( ~ V_360 ) ;
V_157 = F_86 ( V_358 , V_361 )
| V_360 ;
F_87 ( V_328 ) ;
#ifndef F_55
V_362 . V_363 = V_328 ;
#else
F_88 ( V_328 ) ;
#endif
F_72 ( & V_324 ) ;
V_362 . V_364 = * V_322 ;
V_324 . V_325 = F_79 ;
V_52 = F_89 () ;
if ( V_52 != V_44 ) {
F_90 ( V_52 ) ;
return V_52 ;
}
#ifndef F_55
F_91 ( L_28 , V_365 ) ;
#else
F_92 () ;
#endif
#ifndef F_55
if ( ! V_365 )
{
V_365 = true ;
V_362 . V_59 = V_366 ;
memset ( V_362 . V_367 , 0 , sizeof( struct V_368 ) * V_369 ) ;
F_91 ( L_29 , V_365 , V_362 . V_59 ) ;
}
#endif
F_93 () ;
#ifndef F_55
V_324 . V_370 = F_94 ( V_371 ) ;
#endif
V_324 . V_267 = V_267 ;
#ifndef F_55
V_362 . V_267 = V_267 ;
#else
F_95 ( V_267 ) ;
#endif
F_59 ( V_324 . V_267 ) ;
F_96 ( V_358 , V_359 , V_331 ) ;
F_96 ( V_358 , V_361 , V_157 ) ;
F_96 ( V_358 , V_372 , 0 ) ;
V_52 = F_97 ( V_373 ) ;
if ( V_52 != V_44 ) {
F_90 ( V_52 ) ;
return V_52 ;
}
V_52 = F_98 () ;
if ( V_52 != V_44 ) {
F_90 ( V_52 ) ;
return V_52 ;
}
if ( V_281 )
{
F_69 () ;
V_52 = F_76 ( V_281 -> V_231 , V_281 -> V_327 ) ;
if ( V_52 != V_44 ) {
F_90 ( V_52 ) ;
return V_52 ;
}
V_52 = F_77 () ;
if ( V_52 != V_44 ) {
F_90 ( V_52 ) ;
return V_52 ;
}
V_312 = false ;
#ifndef F_55
V_362 . V_374 = (struct V_319 * ) V_281 ;
#endif
}
if( ! F_68 ( & V_375 , V_376 , & V_306 ) )
return V_197 ;
V_52 = F_99 ( V_270 , & V_306 ) ;
if ( V_52 != V_44 ) {
F_90 ( V_52 ) ;
return V_52 ;
}
#if F_11 ( V_329 )
if ( ! F_67 ( & V_377 , V_378 , & V_283 ) )
return V_197 ;
V_52 = F_100 ( & V_283 ) ;
if ( V_52 != V_44 ) {
F_90 ( V_52 ) ;
return V_52 ;
}
#ifdef F_55
V_52 = F_101 ( & V_375 , V_379 ,
F_102 ( V_270 ) ) ;
#endif
if ( V_52 != V_44 ) {
F_90 ( V_52 ) ;
return V_52 ;
}
#endif
#if V_240
if ( ! V_380 ) {
V_380 ++ ;
F_39 ( L_30 ,
V_241 ) ;
F_44 () ;
}
#endif
if ( ! F_103 () ) {
F_90 ( V_381 ) ;
return V_381 ;
}
#if F_11 ( V_382 ) && F_11 ( V_383 )
#if F_11 ( F_60 )
F_104 ( V_384 , V_385 , 0 ) ;
#elif F_11 ( F_18 )
F_104 ( V_384 , V_385 , 1 ) ;
#endif
#endif
#if ! F_11 ( V_239 )
F_105 ( V_386 , V_387 ,
V_388 ) ;
if( F_106 () != V_389 )
V_52 = V_43 ;
#endif
F_107 () ;
F_90 ( V_52 ) ;
return V_52 ;
}
enum V_1 F_108 ( void )
{
int V_8 ;
F_6 ( V_323 , L_31 ) ;
V_362 . V_59 = V_390 ;
for( V_8 = 0 ; V_8 < V_369 ; V_8 ++ )
if ( V_362 . V_367 [ V_8 ] . V_10 != NULL )
{
F_6 ( V_323 , L_32 , V_8 , V_362 . V_367 [ V_8 ] . V_10 ) ;
F_109 ( V_362 . V_367 [ V_8 ] . V_10 ) ;
}
V_362 . V_59 = V_366 ;
F_110 () ;
F_111 () ;
for( V_8 = 0 ; V_8 < V_369 ; V_8 ++ )
F_6 ( V_323 , L_33 , V_8 , V_362 . V_367 [ V_8 ] . V_10 ) ;
F_6 ( V_323 , L_34 ) ;
return V_44 ;
}
enum V_1
F_112 ( void )
{
int V_8 , V_391 ;
enum V_1 V_52 ;
F_6 ( V_323 , L_35 ) ;
V_52 = F_78 ( & ( V_362 . V_364 ) , V_362 . V_374 , V_362 . V_363 , V_362 . V_267 ) ;
if ( V_52 != V_44 )
return V_52 ;
V_52 = F_113 () ;
if ( V_52 != V_44 )
return V_52 ;
V_362 . V_59 = V_392 ;
for( V_8 = 0 ; V_8 < V_369 ; V_8 ++ )
{
F_6 ( V_323 , L_36 , V_362 . V_367 [ V_8 ] . V_10 ) ;
if ( V_362 . V_367 [ V_8 ] . V_10 != NULL )
{
F_6 ( V_323 , L_37 , V_8 ) ;
V_52 = F_114 ( V_362 . V_367 [ V_8 ] . V_10 ) ;
if ( V_52 != V_44 )
{
if ( V_8 )
for( V_391 = 0 ; V_391 < V_8 ; V_391 ++ )
F_109 ( V_362 . V_367 [ V_391 ] . V_10 ) ;
return V_52 ;
}
V_52 = F_115 ( V_362 . V_367 [ V_8 ] . V_10 ) ;
if ( V_52 != V_44 )
{
for( V_391 = 0 ; V_391 <= V_8 ; V_391 ++ )
{
F_116 ( V_362 . V_367 [ V_391 ] . V_10 ) ;
F_109 ( V_362 . V_367 [ V_391 ] . V_10 ) ;
}
return V_52 ;
}
* V_362 . V_367 [ V_8 ] . V_393 = V_362 . V_367 [ V_8 ] . V_10 ;
for( V_391 = 0 ; V_391 < V_362 . V_367 [ V_8 ] . V_394 ; V_391 ++ )
* ( V_362 . V_367 [ V_8 ] . V_395 [ V_391 ] ) = V_362 . V_367 [ V_8 ] . V_396 [ V_391 ] ;
}
}
V_362 . V_59 = V_366 ;
F_6 ( V_323 , L_38 ) ;
return V_44 ;
}
enum V_1
F_117 ( bool V_157 )
{
if ( F_118 () )
return V_397 ;
F_119 ( V_157 ) ;
return V_44 ;
}
void * F_120 ( T_6 V_304 )
{
F_6 ( V_323 , L_39 , V_304 ) ;
if ( V_304 == 0 )
return NULL ;
if ( V_304 > V_398 )
return F_121 ( V_304 ) ;
return F_122 ( V_304 , V_399 ) ;
}
void * F_123 ( T_6 V_400 , T_6 V_304 )
{
void * V_401 ;
F_6 ( V_323 , L_40 , V_400 , V_304 ) ;
if ( V_304 > 0 ) {
V_401 = F_120 ( V_400 * V_304 ) ;
if ( V_401 )
memset ( V_401 , 0 , V_304 ) ;
}
return NULL ;
}
void F_124 ( void * V_402 )
{
if ( F_125 ( V_402 ) )
F_126 ( V_402 ) ;
else
F_127 ( V_402 ) ;
}
void
F_128 ( struct V_330 * V_281 )
{
F_6 ( V_323 , L_41 ) ;
if ( ( V_281 != NULL ) && ( V_324 . V_325 != NULL ) )
V_324 . V_325 ( V_281 ) ;
}
static enum V_1
F_129 ( struct V_45 * V_10 , bool V_403 )
{
struct V_2 * V_404 = NULL ;
struct V_2 * V_194 = NULL ;
struct V_2 * V_405 = NULL ;
struct V_2 * V_406 = NULL ;
enum V_1 V_52 = V_44 ;
enum V_207 V_208 ;
assert ( V_10 != NULL ) ;
F_57 ( L_42 , V_10 , V_403 ) ;
if ( V_10 == NULL ) {
F_130 ( V_43 ) ;
return V_43 ;
}
V_404 = V_10 -> V_49 ;
V_208 = V_404 -> V_59 ;
F_131 ( V_404 -> V_407 , V_403 ) ;
switch ( V_208 ) {
case V_209 :
V_194 = V_404 -> V_192 . V_193 . V_194 ;
V_405 = V_404 -> V_192 . V_193 . V_405 ;
V_406 = V_404 -> V_192 . V_193 . V_406 ;
break;
case V_210 :
V_194 = V_404 -> V_192 . V_196 . V_194 ;
V_405 = V_404 -> V_192 . V_196 . V_405 ;
break;
case V_408 :
case V_409 :
default:
break;
}
if ( V_406 ) {
F_131 ( V_406 -> V_407 , V_403 ) ;
}
if( V_405 ) {
F_131 ( V_405 -> V_407 , V_403 ) ;
}
if( V_194 ) {
F_131 ( V_194 -> V_407 , V_403 ) ;
}
if ( ! V_10 -> V_11 . V_61 ) {
int V_8 ;
for ( V_8 = 1 ; V_8 < V_10 -> V_394 ; V_8 ++ )
F_131 ( V_10 -> V_396 [ V_8 ] -> V_407 , V_403 ) ;
}
F_130 ( V_52 ) ;
return V_52 ;
}
static enum V_1
F_132 ( struct V_45 * V_10 )
{
struct V_2 * V_194 = NULL , * V_405 = NULL ;
struct V_2 * V_406 = NULL ;
enum V_207 V_208 ;
struct V_2 * V_404 = NULL ;
enum V_1 V_52 = V_44 ;
unsigned int V_410 = 0 ,
V_411 = 0 ;
assert ( V_10 != NULL ) ;
F_57 ( L_43 , V_10 ) ;
if ( V_10 == NULL ) {
F_130 ( V_43 ) ;
return V_43 ;
}
V_404 = V_10 -> V_49 ;
assert ( V_404 != NULL ) ;
if ( V_404 == NULL ) {
F_130 ( V_43 ) ;
return V_43 ;
}
V_208 = V_404 -> V_59 ;
switch ( V_208 ) {
case V_209 :
V_194 = V_404 -> V_192 . V_193 . V_194 ;
V_410 = V_404 -> V_412 ;
V_405 = V_404 -> V_192 . V_193 . V_405 ;
V_411 = V_413 ;
V_406 = V_404 -> V_192 . V_193 . V_406 ;
V_52 = F_133 ( & V_404 -> V_54 , V_404 -> V_59 , V_404 -> V_407 , V_404 -> V_412 ) ;
break;
case V_210 :
V_194 = V_404 -> V_192 . V_196 . V_194 ;
V_410 = V_404 -> V_412 ;
V_405 = V_404 -> V_192 . V_196 . V_405 ;
V_411 = V_413 ;
V_52 = F_133 ( & V_404 -> V_54 , V_404 -> V_59 , V_404 -> V_407 , V_404 -> V_412 ) ;
break;
case V_408 :
V_405 = V_404 ;
V_411 = V_404 -> V_412 ;
break;
case V_414 :
V_52 = F_133 ( & V_404 -> V_54 , V_404 -> V_59 ,
V_404 -> V_407 , V_404 -> V_412 ) ;
break;
case V_409 :
V_52 = F_133 ( & V_404 -> V_54 , V_404 -> V_59 , V_404 -> V_407 , V_404 -> V_412 ) ;
break;
default:
V_52 = V_43 ;
}
if ( ( V_44 == V_52 ) && V_194 ) {
V_52 = F_133 ( & V_194 -> V_54 ,
V_194 -> V_59 ,
V_194 -> V_407 ,
V_410 ) ;
}
if ( ( V_44 == V_52 ) && V_405 ) {
V_52 = F_133 ( & V_405 -> V_54 ,
V_405 -> V_59 ,
V_405 -> V_407 ,
V_411 ) ;
}
if ( ( V_44 == V_52 ) && V_406 ) {
V_52 = F_133 ( & V_406 -> V_54 , V_406 -> V_59 , V_406 -> V_407 , V_404 -> V_412 ) ;
}
if ( ! V_10 -> V_11 . V_61 ) {
int V_8 ;
for ( V_8 = 1 ; V_8 < V_10 -> V_394 && V_44 == V_52 ; V_8 ++ ) {
V_404 = V_10 -> V_396 [ V_8 ] ;
V_52 = F_133 ( & V_404 -> V_54 ,
V_404 -> V_59 ,
V_404 -> V_407 ,
V_404 -> V_412 ) ;
}
}
F_130 ( V_52 ) ;
return V_52 ;
}
static enum V_1
F_134 ( struct V_45 * V_10 )
{
struct V_2 * V_194 = NULL , * V_405 = NULL ;
struct V_2 * V_406 = NULL ;
enum V_207 V_208 ;
struct V_2 * V_404 = NULL ;
enum V_1 V_52 = V_44 ;
unsigned V_415 = 0 ;
F_57 ( L_43 , V_10 ) ;
if ( V_10 == NULL ) {
F_130 ( V_43 ) ;
return V_43 ;
}
V_404 = V_10 -> V_49 ;
V_208 = V_404 -> V_59 ;
if ( ( V_208 == V_209 ) ||
( V_208 == V_210 ) ) {
if ( V_10 -> V_11 . V_61 ||
( V_208 == V_209 && V_10 -> V_11 . V_59 != V_416 ) ) {
V_52 = F_135 ( V_404 , true ) ;
if ( V_52 != V_44 )
goto V_417;
}
}
#if F_11 ( F_60 )
if ( V_208 != V_409 ) {
V_52 = F_136 ( V_404 , & V_10 -> V_181 ) ;
if ( V_52 != V_44 )
goto V_417;
}
#elif F_11 ( F_18 )
if ( ( V_208 != V_409 ) &&
( V_404 -> V_11 . V_59 != V_62 ) ) {
V_52 = F_136 ( V_404 , & V_10 -> V_181 ) ;
if ( V_52 != V_44 )
goto V_417;
}
#endif
switch ( V_208 ) {
case V_209 :
V_194 = V_404 -> V_192 . V_193 . V_194 ;
V_405 = V_404 -> V_192 . V_193 . V_405 ;
V_406 = V_404 -> V_192 . V_193 . V_406 ;
V_415 =
V_404 -> V_192 . V_193 . V_418 . V_181 -> V_182 . V_183 . V_184 ;
V_52 = F_137 ( V_404 ) ;
if ( V_52 != V_44 )
goto V_417;
break;
case V_210 :
V_194 = V_404 -> V_192 . V_196 . V_194 ;
V_405 = V_404 -> V_192 . V_196 . V_405 ;
V_415 =
V_404 -> V_192 . V_196 . V_419 . V_181 -> V_182 . V_183 . V_184 ;
V_52 = F_138 ( V_404 ) ;
if ( V_52 != V_44 )
goto V_417;
break;
case V_408 :
V_405 = V_404 ;
break;
case V_414 :
V_52 = F_139 ( V_404 ) ;
if ( V_52 != V_44 )
goto V_417;
break;
case V_409 :
V_52 = F_140 ( V_404 ) ;
if ( V_52 != V_44 )
goto V_417;
break;
default:
V_52 = V_43 ;
}
if ( V_52 != V_44 )
goto V_417;
if( V_194 ) {
V_52 = F_141 ( V_194 , V_415 ,
V_404 -> V_420 [ 0 ] ) ;
if ( V_52 != V_44 )
goto V_417;
}
if( V_405 ) {
V_52 = F_142 ( V_405 ) ;
if ( V_52 != V_44 )
goto V_417;
}
if ( V_406 ) {
V_52 = F_140 ( V_406 ) ;
if ( V_52 != V_44 )
goto V_417;
}
if ( ! V_10 -> V_11 . V_61 ) {
int V_8 ;
for ( V_8 = 1 ; V_8 < V_10 -> V_394 && V_44 == V_52 ; V_8 ++ ) {
switch ( V_10 -> V_396 [ V_8 ] -> V_59 ) {
case V_209 :
V_52 = F_137 ( V_10 -> V_396 [ V_8 ] ) ;
break;
case V_210 :
V_52 = F_138 ( V_10 -> V_396 [ V_8 ] ) ;
break;
case V_408 :
V_52 = F_142 ( V_10 -> V_396 [ V_8 ] ) ;
break;
case V_414 :
V_52 = F_139 ( V_10 -> V_396 [ V_8 ] ) ;
break;
case V_409 :
V_52 = F_140 ( V_10 -> V_396 [ V_8 ] ) ;
break;
default:
V_52 = V_43 ;
}
if ( V_52 != V_44 )
goto V_417;
}
}
V_417:
F_130 ( V_52 ) ;
return V_52 ;
}
static enum V_1
F_143 ( enum V_421 V_59 ,
struct V_2 * V_3 ,
bool V_194 )
{
static struct V_2 V_422 = V_423 ;
static struct V_424 V_425 = V_426 ;
static struct V_427 V_428 = V_429 ;
static struct V_430 V_196 = V_431 ;
static struct V_432 V_433 = V_434 ;
if ( V_3 == NULL ) {
F_144 ( L_44 ) ;
return V_43 ;
}
* V_3 = V_422 ;
switch ( V_59 ) {
case V_191 :
V_3 -> V_59 = V_209 ;
V_3 -> V_192 . V_193 = V_425 ;
break;
case V_189 :
if ( V_194 ) {
V_3 -> V_59 = V_435 ;
} else {
V_3 -> V_59 = V_408 ;
}
V_3 -> V_192 . V_436 = V_428 ;
break;
case V_195 :
V_3 -> V_59 = V_210 ;
V_3 -> V_192 . V_196 = V_196 ;
break;
case V_437 :
V_3 -> V_59 = V_409 ;
break;
case V_62 :
V_3 -> V_59 = V_408 ;
break;
case V_190 :
V_3 -> V_59 = V_414 ;
V_3 -> V_192 . V_433 = V_433 ;
break;
default:
return V_43 ;
}
return V_44 ;
}
static void
F_82 ( void )
{
T_7 V_8 ;
V_324 . V_438 = 0 ;
for ( V_8 = 0 ; V_8 < V_439 ; V_8 ++ ) {
V_324 . V_440 [ V_8 ] = NULL ;
}
}
static enum V_1
F_145 ( const struct V_2 * V_3 , unsigned int * V_441 )
{
const T_7 V_442 = ( T_7 ) ~ ( 0 ) ;
T_7 V_407 = V_442 ;
T_7 V_8 ;
if ( V_3 == NULL ) {
F_144 ( L_44 ) ;
return V_43 ;
}
for ( V_8 = 0 ; V_8 < V_439 ; V_8 ++ ) {
if ( V_324 . V_440 [ V_8 ] == NULL ) {
V_324 . V_440 [ V_8 ] = (struct V_2 * ) V_3 ;
V_407 = V_8 ;
break;
}
}
if ( V_407 == V_442 ) {
F_144 ( L_45 ) ;
return V_443 ;
}
V_324 . V_438 ++ ;
F_91 ( L_46 , V_407 ) ;
* V_441 = V_407 ;
return V_44 ;
}
static void
F_146 ( unsigned int V_407 )
{
V_324 . V_440 [ V_407 ] = NULL ;
V_324 . V_438 -- ;
F_6 ( V_323 ,
L_47 , V_407 ) ;
}
static enum V_1
F_147 ( enum V_421 V_59 ,
struct V_2 * * V_3 ,
bool V_194 )
{
enum V_1 V_52 = V_44 ;
struct V_2 * V_259 ;
if ( V_3 == NULL ) {
F_144 ( L_44 ) ;
return V_43 ;
}
V_259 = F_122 ( sizeof( * V_259 ) , V_399 ) ;
if ( ! V_259 )
return V_444 ;
V_52 = F_143 ( V_59 , V_259 , V_194 ) ;
if ( V_52 != V_44 ) {
F_127 ( V_259 ) ;
return V_52 ;
}
V_52 = F_145 ( V_259 , & ( V_259 -> V_407 ) ) ;
if ( V_52 != V_44 ) {
F_127 ( V_259 ) ;
return V_52 ;
}
* V_3 = V_259 ;
return V_44 ;
}
struct V_2 *
F_148 ( V_142 V_407 )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < V_439 ; V_8 ++ ) {
if ( V_324 . V_440 [ V_8 ] &&
F_27 ( V_324 . V_440 [ V_8 ] ) == V_407 ) {
return V_324 . V_440 [ V_8 ] ;
}
}
return NULL ;
}
static void F_149 (
struct V_2 * V_3 )
{
struct V_445 * V_54 ;
struct V_446 * V_447 ;
assert ( V_3 != NULL ) ;
if ( V_3 == NULL ) {
F_144 ( L_48 ) ;
return;
}
V_54 = & V_3 -> V_54 ;
for ( V_447 = V_54 -> V_55 ; V_447 ; V_447 = V_447 -> V_226 ) {
struct V_280 * V_448 = (struct V_280 * )
V_447 -> V_448 ;
if ( V_448 )
F_150 ( V_3 , V_448 ) ;
}
}
enum V_1
F_151 ( struct V_2 * V_3 )
{
enum V_1 V_52 = V_44 ;
F_81 ( L_49 , V_3 ) ;
if ( V_3 == NULL ) {
F_90 ( V_43 ) ;
return V_43 ;
}
if ( V_3 -> V_10 != NULL ) {
F_91 ( L_50 ) ;
F_90 ( V_43 ) ;
return V_43 ;
}
switch ( V_3 -> V_11 . V_59 ) {
case V_191 :
if ( V_3 -> V_59 == V_209 ) {
F_152 ( V_318 ,
V_3 -> V_420 ) ;
F_153 ( V_318 ,
V_3 -> V_449 ) ;
if ( V_3 -> V_192 . V_193 . V_194 ) {
V_52 = F_151 ( V_3 -> V_192 . V_193 . V_194 ) ;
F_6 ( V_323 , L_51
L_52 , V_52 ) ;
}
}
break;
case V_195 :
if ( V_3 -> V_59 == V_210 ) {
F_152 ( V_318 ,
V_3 -> V_420 ) ;
F_153 ( V_318 ,
V_3 -> V_449 ) ;
if ( V_3 -> V_192 . V_196 . V_194 ) {
V_52 = F_151 ( V_3 -> V_192 . V_196 . V_194 ) ;
F_6 ( V_323 , L_51
L_52 , V_52 ) ;
}
}
#ifndef F_55
F_152 ( V_248 , V_3 -> V_192 . V_196 . V_250 ) ;
#else
F_152 ( V_249 , V_3 -> V_192 . V_196 . V_250 ) ;
#endif
F_152 ( V_251 , V_3 -> V_192 . V_196 . V_252 ) ;
break;
case V_189 :
F_152 ( V_251 , V_3 -> V_192 . V_436 . V_252 ) ;
break;
case V_437 :
F_149 ( V_3 ) ;
break;
case V_62 :
break;
case V_190 :
break;
}
#ifndef F_55
if ( V_3 -> V_450 != V_451 ) {
F_154 ( V_3 -> V_450 ) ;
V_3 -> V_450 = V_451 ;
}
#else
F_155 ( V_3 -> V_450 ) ;
V_3 -> V_450 = V_451 ;
#endif
V_324 . V_452 [ F_27 ( V_3 ) ] = NULL ;
F_156 ( V_3 ) ;
F_157 ( & V_3 -> V_54 ) ;
F_146 ( F_27 ( V_3 ) ) ;
if ( V_3 -> V_11 . V_453 ) {
F_150 ( V_3 , V_3 -> V_11 . V_453 ) ;
}
F_127 ( V_3 ) ;
F_158 ( L_53 , V_52 ) ;
return V_52 ;
}
void
F_111 ( void )
{
F_6 ( V_323 , L_54 ) ;
#if V_240
F_39 ( L_55 , V_241 ) ;
F_40 () ;
#endif
F_159 () ;
F_160 () ;
F_161 () ;
F_162 () ;
#if ! F_11 ( V_454 )
V_455 = true ;
#endif
if ( V_312 == false ) {
F_69 () ;
}
F_163 ( V_270 ) ;
F_164 ( false ) ;
#if F_11 ( V_329 )
F_165 () ;
#endif
#if F_11 ( F_60 ) || F_11 ( F_18 )
F_166 ( NULL ) ;
#endif
F_167 () ;
#if ! F_11 ( V_239 )
F_168 () ;
#endif
F_6 ( V_323 , L_56 ) ;
}
static void
F_87 ( T_5 V_456 )
{
int V_8 ;
F_6 ( V_53 , L_57 , V_456 ) ;
V_324 . V_370 = V_456 ;
for ( V_8 = 0 ; V_8 < ( int ) V_457 ; V_8 ++ ) {
T_8 V_458 = ( T_8 ) V_8 ;
F_169 ( V_458 , V_456 ) ;
F_170 ( V_458 ) ;
}
F_6 ( V_53 , L_58 ) ;
}
enum V_1 F_171 (
unsigned int * V_459 )
{
V_273 V_460 ;
enum V_461 V_462 = V_463 ;
unsigned int V_464 = 0 ;
F_6 ( V_323 , L_59 , V_459 ) ;
while ( V_462 == V_463 ) {
V_462 = F_172 ( & V_460 ) ;
if ( V_462 == V_465 )
return V_197 ;
#if V_240
F_39 ( L_60
L_61 , V_241 , V_460 ) ;
V_232 = 0 ;
#endif
switch ( V_460 ) {
case V_272 :
V_464 |= V_466 ;
break;
case V_467 :
break;
#if ! F_11 ( V_239 )
case V_468 :
V_464 |= V_469 ;
break;
case V_470 :
V_464 |= V_471 ;
break;
case V_472 :
V_464 |= V_473 ;
break;
#endif
#if ! F_11 ( V_454 )
case V_474 :
V_464 |= V_475 ;
break;
#endif
case V_476 :
V_464 |= V_477 ;
break;
case V_478 :
V_464 |= F_173 ( 0 ) ;
break;
case V_479 :
V_464 |= F_173 ( 1 ) ;
break;
default:
break;
}
}
if ( V_459 )
* V_459 = V_464 ;
F_6 ( V_323 , L_62
L_63 , V_464 ) ;
return V_44 ;
}
enum V_1 F_174 (
enum V_480 V_181 ,
bool V_157 )
{
V_273 V_460 = V_481 ;
F_81 ( L_64 , V_181 , V_157 ) ;
switch ( V_181 ) {
#if ! F_11 ( V_454 )
case V_469 :
V_460 = V_468 ;
break;
case V_471 :
V_460 = V_470 ;
break;
case V_473 :
V_460 = V_472 ;
break;
#endif
#if ! F_11 ( V_454 )
case V_475 :
V_460 = V_474 ;
break;
#endif
case V_477 :
V_460 = V_476 ;
break;
case V_482 :
V_460 = V_478 ;
break;
case V_483 :
V_460 = V_479 ;
break;
default:
F_90 ( V_43 ) ;
return V_43 ;
}
F_63 ( V_460 , V_157 ) ;
F_90 ( V_44 ) ;
return V_44 ;
}
void
F_175 ( struct V_50 * V_51 )
{
F_176 ( V_51 ) ;
}
static enum V_1
F_177 ( struct V_2 * V_3 )
{
F_57 ( L_49 , V_3 ) ;
if ( ( V_3 == NULL ) || ( V_3 -> V_59 != V_209 ) ) {
F_130 ( V_43 ) ;
return V_43 ;
}
F_175 ( & V_3 -> V_192 . V_193 . V_484 ) ;
F_175 ( & V_3 -> V_192 . V_193 . V_418 ) ;
F_175 ( & V_3 -> V_192 . V_193 . V_485 ) ;
F_130 ( V_44 ) ;
return V_44 ;
}
static const struct V_280 * F_178 (
const struct V_280 * V_281 )
{
const struct V_280 * V_486 = NULL ;
F_179 ( L_24 ) ;
for (; V_281 ; V_281 = V_281 -> V_226 ) {
const struct V_280 * V_181 = V_281 ;
if ( V_181 -> V_181 . V_487 . V_182 . V_157 . V_488 )
V_486 = V_281 ;
}
return V_486 ;
}
static enum V_1 F_180 (
struct V_445 * V_259 ,
struct V_50 * V_51 ,
const struct V_280 * V_281 ,
const struct V_280 * V_486 ,
unsigned int V_489 ,
struct V_245 * V_253 ,
struct V_245 * V_246 ,
struct V_245 * V_490 ,
struct V_446 * * V_491 ,
struct V_446 * * V_492 )
{
enum V_1 V_52 = V_44 ;
struct V_446 * V_493 = NULL ;
struct V_494 V_495 ;
F_6 ( V_53 ,
L_65 ) ;
for (; V_281 ; V_281 = V_281 -> V_226 ) {
struct V_245 * V_496 [ V_254 ] = { NULL } ;
struct V_245 * V_497 = NULL ;
struct V_245 * V_498 = NULL ;
if ( ( V_281 == V_486 ) && ( V_281 -> V_181 . V_487 . V_182 . V_157 . V_246 != 0 ) ) {
V_496 [ 0 ] = V_246 ;
}
if ( V_281 -> V_181 . V_487 . V_182 . V_157 . V_253 != 0 ) {
V_497 = V_253 ;
}
if ( V_281 -> V_181 . V_487 . V_182 . V_157 . V_246 != 0 ) {
V_498 = V_490 ;
}
F_181 ( & V_495 , V_51 ,
V_496 , V_497 , V_498 , V_281 , V_489 ) ;
V_52 = F_182 ( V_259 ,
& V_495 ,
& V_493 ) ;
if ( V_52 != V_44 )
return V_52 ;
if ( V_281 -> V_181 . V_487 . V_182 . V_157 . V_488 != 0 )
V_253 = V_493 -> args . V_246 [ 0 ] ;
if ( V_491 && ! * V_491 && V_493 )
* V_491 = V_493 ;
if ( V_492 && ! * V_492 && V_493 &&
V_281 -> V_181 . V_487 . V_182 . V_157 . V_499 )
* V_492 = V_493 ;
}
return V_52 ;
}
static enum V_1 F_183 (
struct V_2 * V_3 ,
struct V_245 * V_253 ,
struct V_245 * V_246 ,
struct V_50 * V_485 ,
struct V_446 * * V_500 )
{
struct V_445 * V_259 = NULL ;
const struct V_280 * V_486 = NULL ;
enum V_1 V_52 = V_44 ;
struct V_245 * V_501 [ V_254 ] ;
struct V_494 V_495 ;
if ( V_3 == NULL )
return V_43 ;
if ( V_253 == NULL )
return V_43 ;
if ( V_485 == NULL )
return V_43 ;
if ( V_500 == NULL )
return V_43 ;
F_184 ( V_501 ) ;
V_259 = & V_3 -> V_54 ;
F_6 ( V_53 ,
L_66 ) ;
* V_500 = NULL ;
V_486 = F_178 ( V_3 -> V_492 ) ;
if ( ! V_3 -> V_502 . V_503 ) {
if ( V_486 ) {
F_185 ( V_501 , 0 , NULL ) ;
F_186 ( & V_495 , V_485 ,
V_501 , V_253 , NULL ) ;
} else{
F_185 ( V_501 , 0 , V_246 ) ;
F_186 ( & V_495 , V_485 ,
V_501 , V_253 , NULL ) ;
}
V_52 = F_182 ( V_259 , & V_495 , V_500 ) ;
if ( V_52 != V_44 )
return V_52 ;
V_253 = ( * V_500 ) -> args . V_246 [ 0 ] ;
}
V_52 = F_180 ( V_259 , V_485 , V_3 -> V_492 , V_486 ,
V_228 ,
V_253 , V_246 , NULL ,
V_500 , NULL ) ;
return V_52 ;
}
static enum V_1 F_187 (
struct V_2 * V_3 ,
struct V_445 * V_259 ,
struct V_245 * V_253 ,
struct V_245 * V_246 ,
struct V_245 * V_504 ,
struct V_50 * V_505 ,
struct V_446 * * V_506 )
{
const struct V_280 * V_486 ;
enum V_1 V_52 = V_44 ;
struct V_245 * V_490 = NULL ;
struct V_245 * V_501 [ V_254 ] ;
struct V_494 V_495 ;
assert ( V_253 != NULL ) ;
assert ( V_3 != NULL ) ;
assert ( V_259 != NULL ) ;
assert ( V_505 != NULL ) ;
assert ( V_506 != NULL ) ;
F_6 ( V_53 ,
L_67 ) ;
* V_506 = NULL ;
F_184 ( V_501 ) ;
V_486 = F_178 ( V_3 -> V_507 ) ;
if( V_486 ) {
F_185 ( V_501 , 0 , NULL ) ;
F_186 ( & V_495 ,
V_505 , V_501 , V_253 , V_490 ) ;
} else {
F_185 ( V_501 , 0 , V_246 ) ;
F_185 ( V_501 , 1 , V_504 ) ;
F_186 ( & V_495 ,
V_505 , V_501 , V_253 , V_490 ) ;
}
V_52 = F_182 ( V_259 ,
& V_495 ,
V_506 ) ;
if ( V_52 != V_44 )
return V_52 ;
V_253 = ( * V_506 ) -> args . V_246 [ 0 ] ;
V_52 = F_180 ( V_259 , V_505 , V_3 -> V_507 , V_486 ,
V_508 ,
V_253 , V_246 , V_490 ,
NULL , V_506 ) ;
( * V_506 ) -> args . V_258 = V_505 -> V_258 ;
F_6 ( V_53 ,
L_68 ) ;
return V_52 ;
}
static enum V_1 F_188 (
struct V_2 * V_3 ,
struct V_445 * V_259 ,
struct V_245 * V_253 ,
struct V_245 * V_246 ,
struct V_50 * V_509 ,
struct V_446 * * V_510 )
{
const struct V_280 * V_486 = NULL ;
enum V_1 V_52 = V_44 ;
struct V_245 * V_490 = NULL ;
struct V_245 * V_501 [ V_254 ] ;
struct V_494 V_495 ;
assert ( V_253 != NULL ) ;
assert ( V_3 != NULL ) ;
assert ( V_259 != NULL ) ;
assert ( V_509 != NULL ) ;
assert ( V_510 != NULL ) ;
F_6 ( V_53 ,
L_69 ) ;
* V_510 = NULL ;
F_184 ( V_501 ) ;
V_486 = F_178 ( V_3 -> V_507 ) ;
V_52 = F_189 ( & V_490 ,
& V_509 -> V_511 ) ;
if ( V_52 != V_44 )
return V_52 ;
if( V_486 ) {
F_185 ( V_501 , 0 , NULL ) ;
F_186 ( & V_495 ,
V_509 , V_501 , NULL , V_490 ) ;
} else {
F_185 ( V_501 , 0 , V_246 ) ;
F_186 ( & V_495 ,
V_509 , V_501 , NULL , V_490 ) ;
}
V_52 = F_182 ( V_259 ,
& V_495 ,
V_510 ) ;
if ( V_52 != V_44 )
return V_52 ;
V_52 = F_180 ( V_259 , V_509 , V_3 -> V_507 , V_486 ,
V_508 ,
V_253 , V_246 , V_490 ,
NULL , V_510 ) ;
if ( * V_510 ) {
( * V_510 ) -> args . V_258 =
V_509 -> V_258 ;
}
return V_52 ;
}
static void F_190 ( void )
{
const struct V_280 * V_281 ;
unsigned int V_512 ;
F_191 () ;
F_192 () ;
V_281 = & V_375 ;
V_512 =
V_281 -> V_181 . V_182 . V_513 ;
F_193 () ;
F_194 ( V_270 ,
( unsigned int ) F_195 ( V_513 ) ,
( V_142 ) ( 1 ) ) ;
F_6 ( V_323 , L_70 ) ;
}
static enum V_1
F_196 ( struct V_2 * V_3 ,
struct V_245 * V_490 , unsigned int V_514 )
{
enum V_1 V_52 = V_44 ;
unsigned int V_515 ;
enum V_516 V_517 ;
assert ( V_490 != NULL ) ;
F_197 ( V_3 , & V_490 -> V_181 , V_514 ) ;
V_490 -> V_518 = false ;
V_490 -> V_519 = V_520 ;
F_26 ( F_27 ( V_3 ) , & V_515 ) ;
F_198 ( V_521 + V_514 , V_515 , & V_517 ) ;
V_490 -> V_522 = V_517 ;
V_490 -> V_523 = V_521 + V_514 ;
V_52 = F_199 ( V_490 ) ;
return V_52 ;
}
static unsigned int
F_200 (
const struct V_83 * V_11 )
{
assert ( V_11 != NULL ) ;
if ( ( V_524 == V_11 -> V_12 . V_525 )
|| ( V_526 == V_11 -> V_12 . V_525 ) )
return 1 ;
return 0 ;
}
static unsigned int
F_201 (
const struct V_83 * V_11 )
{
assert ( V_11 != NULL ) ;
if ( ( V_527 == V_11 -> V_12 . V_525 )
|| ( V_526 == V_11 -> V_12 . V_525 ) )
return 1 ;
return 0 ;
}
static void F_202 ( struct V_2 * V_3 ,
unsigned int * V_528 , unsigned int * V_529 )
{
enum V_207 V_208 = V_3 -> V_59 ;
unsigned int V_530 = 0 , V_531 = 0 ;
unsigned int V_8 ;
struct V_532 V_533 = V_3 -> V_11 . V_242 ;
switch ( V_208 ) {
case V_209 :
if ( V_3 -> V_192 . V_193 . V_418 . V_181 ) {
V_530 = V_3 -> V_192 . V_193 . V_418 . V_181 -> V_182 . V_54 . V_530 ;
V_531 = V_3 -> V_192 . V_193 . V_418 . V_181 -> V_182 . V_54 . V_531 ;
}
V_533 = V_3 -> V_192 . V_193 . V_418 . V_242 ;
break;
case V_210 :
if ( V_3 -> V_192 . V_196 . V_419 . V_181 ) {
V_530 = V_3 -> V_192 . V_196 . V_419 . V_181 -> V_182 . V_54 . V_530 ;
V_531 = V_3 -> V_192 . V_196 . V_419 . V_181 -> V_182 . V_54 . V_531 ;
}
V_533 = V_3 -> V_192 . V_196 . V_419 . V_242 ;
break;
case V_408 :
for ( V_8 = 0 ; V_8 < V_3 -> V_192 . V_436 . V_534 ; V_8 ++ ) {
if ( V_3 -> V_192 . V_436 . V_535 [ V_8 ] . V_181 ) {
V_530 += V_3 -> V_192 . V_436 . V_535 [ V_8 ] . V_181 -> V_182 . V_54 . V_530 ;
V_531 += V_3 -> V_192 . V_436 . V_535 [ V_8 ] . V_181 -> V_182 . V_54 . V_531 ;
}
V_533 . V_67 += V_3 -> V_192 . V_436 . V_535 [ V_8 ] . V_242 . V_67 ;
V_533 . V_68 += V_3 -> V_192 . V_436 . V_535 [ V_8 ] . V_242 . V_68 ;
}
break;
default:
break;
}
* V_528 = V_531 + V_533 . V_68 ;
* V_529 = V_530 + V_533 . V_67 ;
}
void
F_25 (
struct V_2 * V_3 ,
struct V_236 * V_253 )
{
unsigned int V_536 = 0 ;
unsigned int V_537 = 0 ;
struct V_532 * V_70 ;
struct V_532 * V_538 ;
unsigned int V_528 = 0 , V_539 = 0 ;
unsigned int V_540 , V_541 ;
assert ( V_3 != NULL ) ;
assert ( V_3 -> V_10 != NULL ) ;
assert ( V_253 != NULL ) ;
F_57 ( L_71 ,
V_3 , V_3 -> V_11 . V_542 . V_67 ,
V_3 -> V_11 . V_542 . V_68 ) ;
V_70 = & V_3 -> V_10 -> V_11 . V_12 . V_70 ;
#ifndef F_55
V_538 = & V_3 -> V_10 -> V_11 . V_12 . V_538 ;
#else
V_538 = & V_3 -> V_11 . V_542 ;
#endif
F_202 ( V_3 , & V_528 , & V_539 ) ;
V_253 -> V_543 = V_3 -> V_10 -> V_11 . V_12 . V_525 ;
V_540 = V_538 -> V_68 + V_528 ;
V_541 = V_538 -> V_67 + V_539 ;
if ( V_70 -> V_68 > V_540 ) {
V_536 = ( V_70 -> V_68 - V_540 ) / 2 ;
V_536 &= ~ 0x1 ;
}
if ( V_70 -> V_67 > V_541 ) {
V_537 = ( V_70 -> V_67 - V_541 ) / 2 ;
V_537 &= ~ 0x1 ;
}
V_537 += F_201 ( & V_3 -> V_10 -> V_11 ) ;
V_536 += F_200 ( & V_3 -> V_10 -> V_11 ) ;
V_253 -> V_544 . V_545 = V_537 ;
V_253 -> V_544 . V_546 = V_536 ;
F_66 ( L_72 , V_537 , V_536 ) ;
return;
}
static enum V_1
F_203 ( struct V_2 * V_3 ,
struct V_245 * V_547 , enum V_4 V_7 )
{
struct V_245 * V_253 ;
enum V_1 V_52 = V_44 ;
unsigned int V_515 ;
enum V_516 V_517 ;
assert ( V_547 != NULL ) ;
V_253 = V_547 ;
V_253 -> V_181 . V_7 = V_7 ;
#ifdef F_18
if ( V_7 == V_39 )
V_253 -> V_181 . V_7 = ( V_3 -> V_10 -> V_11 . V_172 ) ?
V_40 : V_39 ;
#endif
V_253 -> V_181 . V_238 . V_67 = V_3 -> V_10 -> V_11 . V_12 . V_70 . V_67 ;
V_253 -> V_181 . V_238 . V_68 = V_3 -> V_10 -> V_11 . V_12 . V_70 . V_68 ;
V_253 -> V_181 . V_548 =
F_204 ( V_3 ) ;
F_205 ( & V_253 -> V_181 , V_3 -> V_10 -> V_11 . V_12 . V_70 . V_67 , 0 ) ;
V_253 -> V_518 = false ;
V_253 -> V_519 = V_520 ;
F_26 ( F_27 ( V_3 ) , & V_515 ) ;
F_198 ( V_549 , V_515 , & V_517 ) ;
V_253 -> V_522 = V_517 ;
V_253 -> V_523 = V_549 ;
#ifdef F_18
F_25 ( V_3 , & V_253 -> V_181 ) ;
#endif
V_52 = F_199 ( V_253 ) ;
F_6 ( V_53 ,
L_73 , V_253 -> V_181 . V_543 ) ;
return V_52 ;
}
static enum V_1
F_206 ( struct V_2 * V_3 ,
struct V_245 * V_246 , unsigned int V_514 )
{
enum V_1 V_52 = V_44 ;
unsigned int V_515 ;
enum V_516 V_517 ;
assert ( V_246 != NULL ) ;
F_207 ( V_3 , & V_246 -> V_181 , V_514 ) ;
V_246 -> V_518 = false ;
V_246 -> V_519 = V_520 ;
F_26 ( F_27 ( V_3 ) , & V_515 ) ;
F_198 ( V_550 + V_514 , V_515 , & V_517 ) ;
V_246 -> V_522 = V_517 ;
V_246 -> V_523 = V_550 + V_514 ;
V_52 = F_199 ( V_246 ) ;
return V_52 ;
}
static enum V_1
F_140 ( struct V_2 * V_3 )
{
enum V_1 V_52 = V_44 ;
unsigned int V_8 ;
F_57 ( L_49 , V_3 ) ;
if ( ( V_3 == NULL ) || ( V_3 -> V_10 == NULL ) ) {
F_130 ( V_43 ) ;
return V_43 ;
}
V_3 -> V_54 . V_551 = V_3 -> V_11 . V_552 ;
if ( V_3 -> V_11 . V_453 )
V_3 -> V_54 . V_553 = 0 ;
{
const struct V_280 * V_281 = V_3 -> V_492 ;
for ( V_8 = 0 ; V_281 ; V_281 = V_281 -> V_226 ) {
V_52 = F_208 ( & V_3 -> V_54 , V_281 ) ;
if ( V_52 != V_44 )
goto V_417;
}
}
for ( V_8 = 0 ; V_8 < V_3 -> V_11 . V_554 ; V_8 ++ ) {
struct V_280 * V_281 = V_3 -> V_11 . V_555 [ V_8 ] ;
V_52 = F_208 ( & V_3 -> V_54 , V_281 ) ;
if ( V_52 != V_44 )
goto V_417;
}
F_209 ( & V_3 -> V_54 , V_3 -> V_10 -> V_11 . V_61 ) ;
V_417:
F_130 ( V_52 ) ;
return V_52 ;
}
static enum V_1
F_137 ( struct V_2 * V_3 )
{
struct V_446 * V_556 = NULL ;
struct V_446 * V_557 = NULL ;
struct V_446 * V_500 = NULL ;
struct V_494 V_495 ;
struct V_445 * V_259 = NULL ;
struct V_50 * V_484 , * V_418 , * V_485 = NULL ;
struct V_245 * V_253 = NULL ;
enum V_1 V_52 = V_44 ;
struct V_245 * V_246 ;
struct V_245 * V_501 [ V_254 ] ;
bool V_558 = false ;
#ifdef F_18
bool V_559 = false ;
bool V_560 = false ;
bool V_60 = false ;
bool V_61 = false ;
#endif
F_57 ( L_49 , V_3 ) ;
if ( ( V_3 == NULL ) || ( V_3 -> V_10 == NULL ) || ( V_3 -> V_59 != V_209 ) ) {
F_130 ( V_43 ) ;
return V_43 ;
}
F_184 ( V_501 ) ;
V_259 = & V_3 -> V_54 ;
F_210 ( V_259 ) ;
#ifdef F_18
V_559 = ( V_3 -> V_10 -> V_11 . V_59 == V_111 ) ;
V_560 = ( V_3 -> V_10 -> V_11 . V_59 == V_101 ) ;
V_60 = V_3 -> V_10 -> V_11 . V_60 ;
V_61 = V_3 -> V_10 -> V_11 . V_61 ;
V_558 =
! ( ( V_559 && ( V_60 || V_61 ) ) || ( V_560 && ( V_60 || V_61 ) ) ) ;
#else
V_558 = V_3 -> V_10 -> V_11 . V_59 == V_416 ;
#endif
if ( V_558 ) {
V_52 = F_203 ( V_3 , & V_259 -> V_253 , V_39 ) ;
if ( V_52 != V_44 )
goto V_417;
V_253 = & V_259 -> V_253 ;
} else {
V_253 = NULL ;
}
V_52 = F_206 ( V_3 , & V_259 -> V_246 [ 0 ] , 0 ) ;
if ( V_52 != V_44 )
goto V_417;
V_246 = & V_259 -> V_246 [ 0 ] ;
V_484 = & V_3 -> V_192 . V_193 . V_484 ;
V_418 = & V_3 -> V_192 . V_193 . V_418 ;
if ( V_3 -> V_192 . V_193 . V_485 . V_181 )
V_485 = & V_3 -> V_192 . V_193 . V_485 ;
if ( V_3 -> V_192 . V_193 . V_484 . V_181 ) {
F_185 ( V_501 , 0 , NULL ) ;
F_186 ( & V_495 , V_484 ,
V_501 , NULL , NULL ) ;
V_52 = F_182 ( V_259 ,
& V_495 ,
& V_556 ) ;
if ( V_52 != V_44 )
goto V_417;
V_253 = V_259 -> V_55 -> args . V_246 [ 0 ] ;
#ifndef F_55
} else {
#else
} else if ( V_3 -> V_10 -> V_11 . V_61 ) {
#endif
#ifdef F_18
if ( V_61 || ! V_60 ) {
V_253 = V_3 -> V_10 -> V_49 -> V_420 [ 0 ] ;
}
#else
V_253 = V_3 -> V_420 [ 0 ] ;
#endif
}
if ( V_485 ) {
F_185 ( V_501 , 0 , NULL ) ;
F_186 ( & V_495 , V_418 ,
V_501 , V_253 , NULL ) ;
} else {
F_185 ( V_501 , 0 , V_246 ) ;
F_186 ( & V_495 , V_418 ,
V_501 , V_253 , NULL ) ;
}
V_52 = F_182 ( V_259 ,
& V_495 ,
& V_557 ) ;
if ( V_52 != V_44 )
goto V_417;
V_557 -> args . V_256 =
V_418 -> V_181 -> V_182 . V_54 . V_59 == V_561 ;
V_557 -> args . V_257 = ! V_557 -> args . V_256 ;
if ( V_557 -> args . V_256 && ! V_557 -> args . V_255 ) {
V_557 -> args . V_255 =
V_557 -> args . V_246 [ 0 ] ;
}
if ( V_485 ) {
if ( V_418 -> V_181 -> V_182 . V_54 . V_59 == V_561 )
V_253 = V_557 -> args . V_255 ;
else
V_253 = V_557 -> args . V_246 [ 0 ] ;
V_52 = F_183 ( V_3 , V_253 , V_246 , V_485 ,
& V_500 ) ;
if ( V_52 != V_44 )
goto V_417;
}
V_3 -> V_54 . V_562 = false ;
F_209 ( & V_3 -> V_54 , V_3 -> V_10 -> V_11 . V_61 ) ;
V_417:
F_130 ( V_52 ) ;
return V_52 ;
}
static void F_211 ( struct V_2 * V_3 )
{
if ( V_3 -> V_10 -> V_11 . V_61 ) {
unsigned int V_8 ;
F_212
( V_3 -> V_10 -> V_11 . V_563 , true ) ;
F_212
( V_3 -> V_10 -> V_11 . V_564 , false ) ;
for ( V_8 = 0 ; V_8 < V_3 -> V_10 -> V_11 . V_563 ; V_8 ++ ) {
F_213 ( V_8 ,
V_3 -> V_420 [ V_8 ] , V_3 -> V_449 [ V_8 ] ) ;
}
}
return;
}
static enum V_1
F_214 ( struct V_2 * V_3 )
{
struct V_445 * V_259 ;
struct V_50 * V_484 , * V_418 , * V_485 = NULL ;
enum V_1 V_52 = V_44 ;
struct V_2 * V_194 , * V_405 ;
struct V_2 * V_406 ;
enum V_260 V_261 ;
enum V_262 V_565 ;
F_57 ( L_49 , V_3 ) ;
if ( ( V_3 == NULL ) || ( V_3 -> V_10 == NULL ) || ( V_3 -> V_59 != V_209 ) ) {
F_130 ( V_43 ) ;
return V_43 ;
}
V_259 = & V_3 -> V_54 ;
V_565 = V_3 -> V_10 -> V_11 . V_59 ;
V_194 = V_3 -> V_192 . V_193 . V_194 ;
V_405 = V_3 -> V_192 . V_193 . V_405 ;
V_406 = V_3 -> V_192 . V_193 . V_406 ;
V_484 = & V_3 -> V_192 . V_193 . V_484 ;
V_418 = & V_3 -> V_192 . V_193 . V_418 ;
if ( V_3 -> V_192 . V_193 . V_485 . V_181 )
V_485 = & V_3 -> V_192 . V_193 . V_485 ;
F_215 () ;
#if F_11 ( F_60 ) || F_11 ( F_18 )
V_52 = F_216 ( V_3 ) ;
if ( V_52 != V_44 )
goto V_417;
#endif
F_211 ( V_3 ) ;
{
unsigned int V_515 ;
F_26 ( F_27 ( V_3 ) , & V_515 ) ;
V_261 = 1 << V_515 ;
if ( V_3 -> V_10 -> V_566 ) {
F_26 ( F_27 ( V_405 ) , & V_515 ) ;
V_261 |= 1 << V_515 ;
}
}
if ( V_3 -> V_10 -> V_11 . V_61 ) {
F_58 (&copy_pipe->pipeline,
IA_CSS_PIPE_ID_COPY,
(uint8_t)ia_css_pipe_get_pipe_num(copy_pipe),
false,
pipe->stream->config.pixels_per_clock == 2 , false,
false, pipe->required_bds_factor,
copy_ovrd,
pipe->stream->config.mode,
&pipe->stream->config.metadata_config,
#ifndef F_55
&pipe->stream->info.metadata_info
#else
&pipe->stream->info.metadata_info,
#endif
#if ! F_11 ( V_239 )
#ifndef F_55
, pipe->stream->config.source.port.port
#else
pipe->stream->config.source.port.port,
#endif
#endif
#ifndef F_55
) ;
#else
& V_3 -> V_11 . V_264 ,
V_3 -> V_10 -> V_265 ) ;
#endif
V_565 = V_416 ;
}
V_1
F_217 ( struct V_2 * V_3 ,
const struct V_567 * V_568 )
{
enum V_1 V_569 = V_44 ;
unsigned int V_515 ;
enum V_516 V_517 ;
struct V_445 * V_54 ;
struct V_446 * V_447 ;
struct V_570 V_571 ;
struct V_570 * V_572 ;
struct V_344 V_573 ;
enum V_574 V_523 ;
enum V_207 V_208 ;
bool V_575 ;
F_81 ( L_74 , V_3 , V_568 ) ;
if ( ( V_3 == NULL ) || ( V_568 == NULL ) ) {
F_90 ( V_43 ) ;
return V_43 ;
}
V_523 = V_568 -> type ;
#if 0
if (buf_type == IA_CSS_BUFFER_TYPE_OUTPUT_FRAME) {
bool found_pipe = false;
for (i = 0; i < IA_CSS_PIPE_MAX_OUTPUT_STAGE; i++) {
if ((buffer->data.frame->info.res.width == pipe->output_info[i].res.width) &&
(buffer->data.frame->info.res.height == pipe->output_info[i].res.height)) {
buf_type += i;
found_pipe = true;
break;
}
}
if (!found_pipe)
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
if (buf_type == IA_CSS_BUFFER_TYPE_VF_OUTPUT_FRAME) {
bool found_pipe = false;
for (i = 0; i < IA_CSS_PIPE_MAX_OUTPUT_STAGE; i++) {
if ((buffer->data.frame->info.res.width == pipe->vf_output_info[i].res.width) &&
(buffer->data.frame->info.res.height == pipe->vf_output_info[i].res.height)) {
buf_type += i;
found_pipe = true;
break;
}
}
if (!found_pipe)
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
#endif
V_208 = V_3 -> V_59 ;
F_91 ( L_75 , V_208 , V_523 ) ;
assert ( V_208 < V_576 ) ;
assert ( V_523 < V_577 ) ;
if ( ( V_523 == V_578 ) ||
( V_523 >= V_577 ) ||
( V_208 >= V_576 ) ) {
F_90 ( V_197 ) ;
return V_197 ;
}
V_575 = F_26 ( F_27 ( V_3 ) , & V_515 ) ;
if ( ! V_575 ) {
F_90 ( V_43 ) ;
return V_43 ;
}
V_575 = F_198 ( V_523 , V_515 , & V_517 ) ;
if ( ! V_575 ) {
F_90 ( V_43 ) ;
return V_43 ;
}
if ( ( V_517 <= V_579 ) || ( V_517 >= V_580 ) ) {
F_90 ( V_43 ) ;
return V_43 ;
}
if ( ! F_118 () ) {
F_91 ( L_76 ) ;
F_90 ( V_397 ) ;
return V_397 ;
}
V_54 = & V_3 -> V_54 ;
assert ( V_54 != NULL ||
V_208 == V_435 ||
V_208 == V_409 ) ;
assert ( sizeof( NULL ) <= sizeof( V_573 . V_581 ) ) ;
V_573 . V_581 = F_218 ( NULL ) ;
V_573 . V_582 = V_568 -> V_583 ;
V_573 . V_584 = V_568 -> V_584 ;
if ( V_523 == V_585 ) {
if ( V_568 -> V_231 . V_586 == NULL ) {
F_90 ( V_43 ) ;
return V_43 ;
}
V_573 . V_581 = F_218 ( V_568 -> V_231 . V_586 ) ;
V_573 . V_587 . V_588 = * V_568 -> V_231 . V_586 ;
} else if ( V_523 == V_589 ) {
if ( V_568 -> V_231 . V_590 == NULL ) {
F_90 ( V_43 ) ;
return V_43 ;
}
V_573 . V_581 = F_218 ( V_568 -> V_231 . V_590 ) ;
V_573 . V_587 . V_591 = * V_568 -> V_231 . V_590 ;
} else if ( V_523 == V_592 ) {
if ( V_568 -> V_231 . V_156 == NULL ) {
F_90 ( V_43 ) ;
return V_43 ;
}
V_573 . V_581 = F_218 ( V_568 -> V_231 . V_156 ) ;
V_573 . V_587 . V_156 = * V_568 -> V_231 . V_156 ;
} else if ( ( V_523 == V_549 )
|| ( V_523 == V_550 )
|| ( V_523 == V_521 )
|| ( V_523 == V_593 )
|| ( V_523 == V_594 ) ) {
if ( V_568 -> V_231 . V_547 == NULL ) {
F_90 ( V_43 ) ;
return V_43 ;
}
V_573 . V_581 = F_218 ( V_568 -> V_231 . V_547 ) ;
V_573 . V_587 . V_547 . V_595 = V_568 -> V_231 . V_547 -> V_231 ;
V_573 . V_587 . V_547 . V_596 = 0 ;
F_6 ( V_323 ,
L_77 ,
V_523 , V_568 -> V_231 . V_547 -> V_231 ) ;
#if F_219 ()
V_569 = F_220 (
& V_568 -> V_231 . V_547 -> V_181 ,
& V_573 . V_587 . V_547 ) ;
if ( V_44 != V_569 ) {
F_90 ( V_569 ) ;
return V_569 ;
}
#endif
}
V_571 . V_597 = 0 ;
V_571 . V_598 = 0 ;
V_571 . V_304 = sizeof( struct V_344 ) ;
V_572 = & V_571 ;
F_221 ( V_599 , & V_572 ) ;
assert ( V_572 != NULL ) ;
assert ( V_572 -> V_597 != 0x0 ) ;
if ( ( V_572 == NULL ) || ( V_572 -> V_597 == 0x0 ) ) {
F_90 ( V_197 ) ;
return V_197 ;
}
F_222 ( V_572 -> V_597 ,
( void * ) ( & V_573 ) ,
sizeof( struct V_344 ) ) ;
if ( ( V_523 == V_585 )
|| ( V_523 == V_589 )
|| ( V_523 == V_600 ) ) {
if ( V_54 == NULL ) {
F_223 ( V_599 , & V_572 ) ;
F_91 ( L_78 ) ;
F_90 ( V_197 ) ;
return V_197 ;
}
for ( V_447 = V_54 -> V_55 ; V_447 ; V_447 = V_447 -> V_226 ) {
if ( F_224 ( V_447 ) ) {
V_569 = F_225 ( V_515 ,
V_517 ,
( V_142 ) V_572 -> V_597 ) ;
}
}
} else if ( ( V_523 == V_549 )
|| ( V_523 == V_550 )
|| ( V_523 == V_521 )
|| ( V_523 == V_593 )
|| ( V_523 == V_594 )
|| ( V_523 == V_592 ) ) {
V_569 = F_225 ( V_515 ,
V_517 ,
( V_142 ) V_572 -> V_597 ) ;
#if F_11 ( V_601 )
if ( ( V_569 == V_44 ) && ( V_550 == V_523 ) ) {
F_91 ( L_79 ,
V_573 . V_587 . V_547 . V_595 ,
V_517 , V_515 ) ;
}
#endif
}
if ( V_569 == V_44 ) {
#ifndef F_55
bool V_602 = false ;
V_602 = F_226 (
#else
struct sh_css_hmm_buffer_record *hmm_buffer_record = NULL;
hmm_buffer_record = sh_css_hmm_buffer_record_acquire(
#endif
h_vbuf, buf_type,
HOST_ADDRESS(ddr_buffer.kernel_ptr));
#ifndef F_55
if (found_record == true) {
#else
if (hmm_buffer_record) {
#endif
IA_CSS_LOG(L_80, h_vbuf);
} else {
return_err = IA_CSS_ERR_INTERNAL_ERROR;
IA_CSS_ERROR(L_81);
}
}
if (return_err == IA_CSS_SUCCESS) {
if (!sh_css_sp_is_running()) {
IA_CSS_LOG(L_76);
IA_CSS_LEAVE_ERR(IA_CSS_ERR_RESOURCE_NOT_AVAILABLE);
return IA_CSS_ERR_RESOURCE_NOT_AVAILABLE;
}
return_err = ia_css_bufq_enqueue_psys_event(
IA_CSS_PSYS_SW_EVENT_BUFFER_ENQUEUED,
(uint8_t)thread_id,
queue_id,
0);
} else {
ia_css_rmgr_rel_vbuf(hmm_buffer_pool, &h_vbuf);
IA_CSS_ERROR(L_82);
}
IA_CSS_LEAVE(L_83, return_err);
return return_err;
}
enum ia_css_err
ia_css_pipe_dequeue_buffer(struct ia_css_pipe *pipe,
struct ia_css_buffer *buffer)
{
enum ia_css_err return_err;
enum sh_css_queue_id queue_id;
hrt_vaddress ddr_buffer_addr = (hrt_vaddress)0;
struct sh_css_hmm_buffer ddr_buffer;
enum ia_css_buffer_type buf_type;
enum ia_css_pipe_id pipe_id;
unsigned int thread_id;
hrt_address kernel_ptr = 0;
bool ret_err;
IA_CSS_ENTER(L_74, pipe, buffer);
if ((pipe == NULL) || (buffer == NULL)) {
IA_CSS_LEAVE_ERR(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
pipe_id = pipe->mode;
buf_type = buffer->type;
IA_CSS_LOG(L_75, pipe_id, buf_type);
ddr_buffer.kernel_ptr = 0;
ret_err = ia_css_pipeline_get_sp_thread_id(ia_css_pipe_get_pipe_num(pipe), &thread_id);
if (!ret_err) {
IA_CSS_LEAVE_ERR(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
ret_err = ia_css_query_internal_queue_id(buf_type, thread_id, &queue_id);
if (!ret_err) {
IA_CSS_LEAVE_ERR(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
if ((queue_id <= SH_CSS_INVALID_QUEUE_ID) || (queue_id >= SH_CSS_MAX_NUM_QUEUES)) {
IA_CSS_LEAVE_ERR(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
if (!sh_css_sp_is_running()) {
IA_CSS_LOG(L_76);
IA_CSS_LEAVE_ERR(IA_CSS_ERR_RESOURCE_NOT_AVAILABLE);
return IA_CSS_ERR_RESOURCE_NOT_AVAILABLE;
}
return_err = ia_css_bufq_dequeue_buffer(queue_id,
(uint32_t *)&ddr_buffer_addr);
if (return_err == IA_CSS_SUCCESS) {
struct ia_css_frame *frame;
struct sh_css_hmm_buffer_record *hmm_buffer_record = NULL;
IA_CSS_LOG(L_84, (int)ddr_buffer_addr);
hmm_buffer_record = sh_css_hmm_buffer_record_validate(
ddr_buffer_addr, buf_type);
if (hmm_buffer_record != NULL) {
kernel_ptr = hmm_buffer_record->kernel_ptr;
ia_css_rmgr_rel_vbuf(hmm_buffer_pool, &hmm_buffer_record->h_vbuf);
sh_css_hmm_buffer_record_reset(hmm_buffer_record);
} else {
IA_CSS_ERROR(L_85,
ddr_buffer_addr, buf_type);
IA_CSS_LEAVE_ERR(IA_CSS_ERR_INTERNAL_ERROR);
return IA_CSS_ERR_INTERNAL_ERROR;
}
mmgr_load(ddr_buffer_addr,
&ddr_buffer,
sizeof(struct sh_css_hmm_buffer));
if ((ddr_buffer.kernel_ptr == 0) ||
(kernel_ptr != HOST_ADDRESS(ddr_buffer.kernel_ptr))) {
IA_CSS_ERROR(L_86);
IA_CSS_ERROR(L_87, kernel_ptr);
IA_CSS_ERROR(L_88, HOST_ADDRESS(ddr_buffer.kernel_ptr));
IA_CSS_ERROR(L_89, buf_type);
IA_CSS_LEAVE_ERR(IA_CSS_ERR_INTERNAL_ERROR);
return IA_CSS_ERR_INTERNAL_ERROR;
}
if (ddr_buffer.kernel_ptr != 0) {
buffer->exp_id = 0;
buffer->driver_cookie = ddr_buffer.cookie_ptr;
buffer->timing_data = ddr_buffer.timing_data;
if ((buf_type == IA_CSS_BUFFER_TYPE_OUTPUT_FRAME) ||
(buf_type == IA_CSS_BUFFER_TYPE_VF_OUTPUT_FRAME)) {
buffer->isys_eof_clock_tick.ticks = ddr_buffer.isys_eof_clock_tick;
}
switch (buf_type) {
case IA_CSS_BUFFER_TYPE_INPUT_FRAME:
case IA_CSS_BUFFER_TYPE_OUTPUT_FRAME:
case IA_CSS_BUFFER_TYPE_SEC_OUTPUT_FRAME:
if ((pipe) && (pipe->stop_requested == true))
{
#if F_11 ( F_60 )
return_err = free_mipi_frames(pipe);
if (return_err != IA_CSS_SUCCESS) {
IA_CSS_LOG(L_90);
IA_CSS_LEAVE_ERR(return_err);
return return_err;
}
#endif
pipe->stop_requested = false;
}
case IA_CSS_BUFFER_TYPE_VF_OUTPUT_FRAME:
case IA_CSS_BUFFER_TYPE_SEC_VF_OUTPUT_FRAME:
frame = (struct ia_css_frame*)HOST_ADDRESS(ddr_buffer.kernel_ptr);
buffer->data.frame = frame;
buffer->exp_id = ddr_buffer.payload.frame.exp_id;
frame->exp_id = ddr_buffer.payload.frame.exp_id;
frame->isp_config_id = ddr_buffer.payload.frame.isp_parameters_id;
if (ddr_buffer.payload.frame.flashed == 1)
frame->flash_state =
IA_CSS_FRAME_FLASH_STATE_PARTIAL;
if (ddr_buffer.payload.frame.flashed == 2)
frame->flash_state =
IA_CSS_FRAME_FLASH_STATE_FULL;
frame->valid = pipe->num_invalid_frames == 0;
if (!frame->valid)
pipe->num_invalid_frames--;
if (frame->info.format == IA_CSS_FRAME_FORMAT_BINARY_8) {
#ifdef F_18
frame->planes.binary.size = frame->data_bytes;
#else
frame->planes.binary.size =
sh_css_sp_get_binary_copy_size();
#endif
}
#if F_11 ( V_601 )
if (IA_CSS_BUFFER_TYPE_OUTPUT_FRAME == buf_type) {
IA_CSS_LOG(L_91,
frame->data, frame->isp_config_id, thread_id);
}
#endif
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
L_92,
buf_type, buffer->data.frame->data);
break;
case IA_CSS_BUFFER_TYPE_3A_STATISTICS:
buffer->data.stats_3a =
(struct ia_css_isp_3a_statistics*)HOST_ADDRESS(ddr_buffer.kernel_ptr);
buffer->exp_id = ddr_buffer.payload.s3a.exp_id;
buffer->data.stats_3a->exp_id = ddr_buffer.payload.s3a.exp_id;
buffer->data.stats_3a->isp_config_id = ddr_buffer.payload.s3a.isp_config_id;
break;
case IA_CSS_BUFFER_TYPE_DIS_STATISTICS:
buffer->data.stats_dvs =
(struct ia_css_isp_dvs_statistics*)
HOST_ADDRESS(ddr_buffer.kernel_ptr);
buffer->exp_id = ddr_buffer.payload.dis.exp_id;
buffer->data.stats_dvs->exp_id = ddr_buffer.payload.dis.exp_id;
break;
case IA_CSS_BUFFER_TYPE_LACE_STATISTICS:
break;
case IA_CSS_BUFFER_TYPE_METADATA:
buffer->data.metadata =
(struct ia_css_metadata*)HOST_ADDRESS(ddr_buffer.kernel_ptr);
buffer->exp_id = ddr_buffer.payload.metadata.exp_id;
buffer->data.metadata->exp_id = ddr_buffer.payload.metadata.exp_id;
break;
default:
return_err = IA_CSS_ERR_INTERNAL_ERROR;
break;
}
}
}
if (return_err == IA_CSS_SUCCESS){
if (!sh_css_sp_is_running()) {
IA_CSS_LOG(L_76);
IA_CSS_LEAVE_ERR(IA_CSS_ERR_RESOURCE_NOT_AVAILABLE);
return IA_CSS_ERR_RESOURCE_NOT_AVAILABLE;
}
ia_css_bufq_enqueue_psys_event(
IA_CSS_PSYS_SW_EVENT_BUFFER_DEQUEUED,
0,
queue_id,
0);
}
IA_CSS_LEAVE(L_93, buffer);
return return_err;
}
static enum ia_css_event_type convert_event_sp_to_host_domain[] = {
IA_CSS_EVENT_TYPE_OUTPUT_FRAME_DONE,
IA_CSS_EVENT_TYPE_SECOND_OUTPUT_FRAME_DONE,
IA_CSS_EVENT_TYPE_VF_OUTPUT_FRAME_DONE,
IA_CSS_EVENT_TYPE_SECOND_VF_OUTPUT_FRAME_DONE,
IA_CSS_EVENT_TYPE_3A_STATISTICS_DONE,
IA_CSS_EVENT_TYPE_DIS_STATISTICS_DONE,
IA_CSS_EVENT_TYPE_PIPELINE_DONE,
IA_CSS_EVENT_TYPE_FRAME_TAGGED,
IA_CSS_EVENT_TYPE_INPUT_FRAME_DONE,
IA_CSS_EVENT_TYPE_METADATA_DONE,
IA_CSS_EVENT_TYPE_LACE_STATISTICS_DONE,
IA_CSS_EVENT_TYPE_ACC_STAGE_COMPLETE,
IA_CSS_EVENT_TYPE_TIMER,
IA_CSS_EVENT_TYPE_PORT_EOF,
IA_CSS_EVENT_TYPE_FW_WARNING,
IA_CSS_EVENT_TYPE_FW_ASSERT,
0 ,
};
enum ia_css_err
ia_css_dequeue_event(struct ia_css_event *event)
{
return ia_css_dequeue_psys_event(event);
}
enum ia_css_err
ia_css_dequeue_psys_event(struct ia_css_event *event)
{
enum ia_css_pipe_id pipe_id = 0;
uint8_t payload[4] = {0 , 0 , 0 , 0};
enum ia_css_err ret_err;
if (event == NULL)
return IA_CSS_ERR_INVALID_ARGUMENTS;
if (!sh_css_sp_is_running()) {
return IA_CSS_ERR_RESOURCE_NOT_AVAILABLE;
}
ret_err = ia_css_bufq_dequeue_psys_event(payload);
if (ret_err != IA_CSS_SUCCESS)
return ret_err;
IA_CSS_LOG(L_94);
ia_css_bufq_enqueue_psys_event(
IA_CSS_PSYS_SW_EVENT_EVENT_DEQUEUED, 0, 0, 0);
event->type = convert_event_sp_to_host_domain[payload[0]];
event->pipe = NULL;
event->port = IA_CSS_CSI2_PORT0;
event->exp_id = 0;
event->fw_warning = IA_CSS_FW_WARNING_NONE;
event->fw_handle = 0;
event->timer_data = 0;
event->timer_code = 0;
event->timer_subcode = 0;
if (event->type == IA_CSS_EVENT_TYPE_TIMER) {
uint32_t tmp_data;
event->timer_data = ((payload[1] & 0xFF) | ((payload[3] & 0xFF) << 8));
event->timer_code = payload[2];
payload[0] = payload[1] = payload[2] = payload[3] = 0;
ret_err = ia_css_bufq_dequeue_psys_event(payload);
if (ret_err != IA_CSS_SUCCESS) {
IA_CSS_WARNING(L_95);
return ret_err;
}
ia_css_bufq_enqueue_psys_event(
IA_CSS_PSYS_SW_EVENT_EVENT_DEQUEUED, 0, 0, 0);
event->type = convert_event_sp_to_host_domain[payload[0]];
if (event->type == IA_CSS_EVENT_TYPE_TIMER) {
tmp_data = ((payload[1] & 0xFF) | ((payload[3] & 0xFF) << 8));
event->timer_data |= (tmp_data << 16);
event->timer_subcode = payload[2];
}
else {
event->timer_data = 0;
event->timer_code = 0;
event->timer_subcode = 0;
IA_CSS_ERROR(L_96);
}
}
if (event->type == IA_CSS_EVENT_TYPE_PORT_EOF) {
event->port = (enum ia_css_csi2_port)payload[1];
event->exp_id = payload[3];
} else if (event->type == IA_CSS_EVENT_TYPE_FW_WARNING) {
event->fw_warning = (enum ia_css_fw_warning)payload[1];
if (event->fw_warning == IA_CSS_FW_WARNING_EXP_ID_LOCKED ||
event->fw_warning == IA_CSS_FW_WARNING_TAG_EXP_ID_FAILED)
event->exp_id = payload[3];
} else if (event->type == IA_CSS_EVENT_TYPE_FW_ASSERT) {
event->fw_assert_module_id = payload[1];
event->fw_assert_line_no = (payload[2] << 8) + payload[3];
} else if (event->type != IA_CSS_EVENT_TYPE_TIMER) {
event->pipe = find_pipe_by_num(payload[1]);
pipe_id = (enum ia_css_pipe_id)payload[2];
if (!event->pipe)
return IA_CSS_ERR_RESOURCE_NOT_AVAILABLE;
if (event->type == IA_CSS_EVENT_TYPE_FRAME_TAGGED) {
int i, n;
n = event->pipe->stream->num_pipes;
for (i = 0; i < n; i++) {
struct ia_css_pipe *p =
event->pipe->stream->pipes[i];
if (p->config.mode == IA_CSS_PIPE_MODE_CAPTURE) {
event->pipe = p;
break;
}
}
event->exp_id = payload[3];
}
if (event->type == IA_CSS_EVENT_TYPE_ACC_STAGE_COMPLETE) {
uint32_t stage_num = (uint32_t)payload[3];
ret_err = ia_css_pipeline_get_fw_from_stage(
&(event->pipe->pipeline),
stage_num,
&(event->fw_handle));
if (ret_err != IA_CSS_SUCCESS) {
IA_CSS_ERROR(L_97,
stage_num);
return ret_err;
}
}
}
if (event->pipe)
IA_CSS_LEAVE(L_98, event->type, pipe_id);
else
IA_CSS_LEAVE(L_99, event->type);
return IA_CSS_SUCCESS;
}
enum ia_css_err
ia_css_dequeue_isys_event(struct ia_css_event *event)
{
uint8_t payload[4] = {0 , 0 , 0 , 0};
enum ia_css_err err = IA_CSS_SUCCESS;
if (event == NULL)
return IA_CSS_ERR_INVALID_ARGUMENTS;
if (!sh_css_sp_is_running()) {
return IA_CSS_ERR_RESOURCE_NOT_AVAILABLE;
}
err = ia_css_bufq_dequeue_isys_event(payload);
if (err != IA_CSS_SUCCESS)
return err;
IA_CSS_LOG(L_100);
ia_css_bufq_enqueue_isys_event(IA_CSS_ISYS_SW_EVENT_EVENT_DEQUEUED);
event->type = IA_CSS_EVENT_TYPE_PORT_EOF;
event->pipe = NULL;
event->port = payload[1];
event->exp_id = payload[3];
IA_CSS_LEAVE_ERR(err);
return err;
}
static void
acc_start(struct ia_css_pipe *pipe)
{
assert(pipe != NULL);
assert(pipe->stream != NULL);
start_pipe(pipe, SH_CSS_PIPE_CONFIG_OVRD_NO_OVRD,
pipe->stream->config.mode);
}
static enum ia_css_err
sh_css_pipe_start(struct ia_css_stream *stream)
{
enum ia_css_err err = IA_CSS_SUCCESS;
struct ia_css_pipe *pipe;
enum ia_css_pipe_id pipe_id;
unsigned int thread_id;
IA_CSS_ENTER_PRIVATE(L_43, stream);
if (stream == NULL) {
IA_CSS_LEAVE_ERR(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
pipe = stream->last_pipe;
if (pipe == NULL) {
IA_CSS_LEAVE_ERR(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
pipe_id = pipe->mode;
if(stream->started == true) {
IA_CSS_WARNING(L_101);
IA_CSS_LEAVE_ERR(err);
return err;
}
pipe->stop_requested = false;
switch (pipe_id) {
case IA_CSS_PIPE_ID_PREVIEW:
err = preview_start(pipe);
break;
case IA_CSS_PIPE_ID_VIDEO:
err = video_start(pipe);
break;
case IA_CSS_PIPE_ID_CAPTURE:
err = capture_start(pipe);
break;
case IA_CSS_PIPE_ID_YUVPP:
err = yuvpp_start(pipe);
break;
case IA_CSS_PIPE_ID_ACC:
acc_start(pipe);
break;
default:
err = IA_CSS_ERR_INVALID_ARGUMENTS;
}
if (!stream->config.continuous) {
int i;
for (i = 1; i < stream->num_pipes && IA_CSS_SUCCESS == err ; i++) {
switch (stream->pipes[i]->mode) {
case IA_CSS_PIPE_ID_PREVIEW:
stream->pipes[i]->stop_requested = false;
err = preview_start(stream->pipes[i]);
break;
case IA_CSS_PIPE_ID_VIDEO:
stream->pipes[i]->stop_requested = false;
err = video_start(stream->pipes[i]);
break;
case IA_CSS_PIPE_ID_CAPTURE:
stream->pipes[i]->stop_requested = false;
err = capture_start(stream->pipes[i]);
break;
case IA_CSS_PIPE_ID_YUVPP:
stream->pipes[i]->stop_requested = false;
err = yuvpp_start(stream->pipes[i]);
break;
case IA_CSS_PIPE_ID_ACC:
stream->pipes[i]->stop_requested = false;
acc_start(stream->pipes[i]);
break;
default:
err = IA_CSS_ERR_INVALID_ARGUMENTS;
}
}
}
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
if (!copy_on_sp(pipe)) {
sh_css_invalidate_params(stream);
err = sh_css_param_update_isp_params(pipe,
stream->isp_params_configs, true, NULL);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
}
ia_css_debug_pipe_graph_dump_epilogue();
ia_css_pipeline_get_sp_thread_id(ia_css_pipe_get_pipe_num(pipe), &thread_id);
if (!sh_css_sp_is_running()) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_RESOURCE_NOT_AVAILABLE);
return IA_CSS_ERR_RESOURCE_NOT_AVAILABLE;
}
ia_css_bufq_enqueue_psys_event(IA_CSS_PSYS_SW_EVENT_START_STREAM,
(uint8_t)thread_id, 0, 0);
if (!stream->config.continuous) {
int i;
for (i = 1; i < stream->num_pipes; i++) {
ia_css_pipeline_get_sp_thread_id(
ia_css_pipe_get_pipe_num(stream->pipes[i]),
&thread_id);
ia_css_bufq_enqueue_psys_event(
IA_CSS_PSYS_SW_EVENT_START_STREAM,
(uint8_t)thread_id, 0, 0);
}
}
if (pipe->stream->config.continuous) {
struct ia_css_pipe *copy_pipe = NULL;
if (pipe_id == IA_CSS_PIPE_ID_PREVIEW)
copy_pipe = pipe->pipe_settings.preview.copy_pipe;
else if (pipe_id == IA_CSS_PIPE_ID_VIDEO)
copy_pipe = pipe->pipe_settings.video.copy_pipe;
if (copy_pipe == NULL) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INTERNAL_ERROR);
return IA_CSS_ERR_INTERNAL_ERROR;
}
ia_css_pipeline_get_sp_thread_id(ia_css_pipe_get_pipe_num(copy_pipe), &thread_id);
ia_css_bufq_enqueue_psys_event(
IA_CSS_PSYS_SW_EVENT_START_STREAM,
(uint8_t)thread_id, 0, 0);
}
if (pipe->stream->cont_capt) {
struct ia_css_pipe *capture_pipe = NULL;
if (pipe_id == IA_CSS_PIPE_ID_PREVIEW)
capture_pipe = pipe->pipe_settings.preview.capture_pipe;
else if (pipe_id == IA_CSS_PIPE_ID_VIDEO)
capture_pipe = pipe->pipe_settings.video.capture_pipe;
if (capture_pipe == NULL) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INTERNAL_ERROR);
return IA_CSS_ERR_INTERNAL_ERROR;
}
ia_css_pipeline_get_sp_thread_id(ia_css_pipe_get_pipe_num(capture_pipe), &thread_id);
ia_css_bufq_enqueue_psys_event(
IA_CSS_PSYS_SW_EVENT_START_STREAM,
(uint8_t)thread_id, 0, 0);
}
if (pipe_id == IA_CSS_PIPE_ID_PREVIEW) {
struct ia_css_pipe *acc_pipe = NULL;
acc_pipe = pipe->pipe_settings.preview.acc_pipe;
if (acc_pipe){
ia_css_pipeline_get_sp_thread_id(ia_css_pipe_get_pipe_num(acc_pipe), &thread_id);
ia_css_bufq_enqueue_psys_event(
IA_CSS_PSYS_SW_EVENT_START_STREAM,
(uint8_t) thread_id, 0, 0);
}
}
stream->started = true;
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
#ifndef F_55
void
sh_css_enable_cont_capt(bool enable, bool stop_copy_preview)
{
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
L_102, enable);
my_css.stop_copy_preview = stop_copy_preview;
}
bool
sh_css_continuous_is_enabled(uint8_t pipe_num)
#else
static enum ia_css_err
sh_css_pipes_stop(struct ia_css_stream *stream)
#endif
{
#ifndef F_55
struct ia_css_pipe *pipe;
bool continuous;
#else
enum ia_css_err err = IA_CSS_SUCCESS;
struct ia_css_pipe *main_pipe;
enum ia_css_pipe_id main_pipe_id;
int i;
#endif
#ifndef F_55
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, L_103, pipe_num);
#else
assert(stream != NULL);
if (stream == NULL) {
IA_CSS_LOG(L_104);
err = IA_CSS_ERR_INTERNAL_ERROR;
goto ERR;
}
#endif
#ifndef F_55
pipe = find_pipe_by_num(pipe_num);
continuous = pipe && pipe->stream->config.continuous;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
L_105,
continuous);
return continuous;
}
#else
main_pipe = stream->last_pipe;
assert(main_pipe != NULL);
if (main_pipe == NULL) {
IA_CSS_LOG(L_106);
err = IA_CSS_ERR_INTERNAL_ERROR;
goto ERR;
}
#endif
#ifndef F_55
enum ia_css_err
ia_css_stream_get_max_buffer_depth(struct ia_css_stream *stream, int *buffer_depth)
{
if (buffer_depth == NULL)
return IA_CSS_ERR_INVALID_ARGUMENTS;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, L_107);
(void)stream;
*buffer_depth = NUM_CONTINUOUS_FRAMES;
return IA_CSS_SUCCESS;
}
#else
main_pipe_id = main_pipe->mode;
IA_CSS_ENTER_PRIVATE(L_108, main_pipe_id);
#endif
#ifndef F_55
enum ia_css_err
ia_css_stream_set_buffer_depth(struct ia_css_stream *stream, int buffer_depth)
{
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, L_109,buffer_depth);
(void)stream;
if (buffer_depth > NUM_CONTINUOUS_FRAMES || buffer_depth < 1)
return IA_CSS_ERR_INVALID_ARGUMENTS;
stream->config.target_num_cont_raw_buf = buffer_depth;
return IA_CSS_SUCCESS;
}
#else
for (i = 0; i < stream->num_pipes; i++) {
IA_CSS_LOG(L_110,
stream->pipes[i]->pipeline.pipe_id);
err = ia_css_pipeline_request_stop(&stream->pipes[i]->pipeline);
#endif
#ifndef F_55
enum ia_css_err
ia_css_stream_get_buffer_depth(struct ia_css_stream *stream, int *buffer_depth)
{
if (buffer_depth == NULL)
return IA_CSS_ERR_INVALID_ARGUMENTS;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, L_111);
#else
if (err != IA_CSS_SUCCESS) {
goto ERR;
}
}
if (main_pipe->stream->config.continuous) {
struct ia_css_pipe *copy_pipe = NULL;
if (main_pipe_id == IA_CSS_PIPE_ID_PREVIEW)
copy_pipe = main_pipe->pipe_settings.preview.copy_pipe;
else if (main_pipe_id == IA_CSS_PIPE_ID_VIDEO)
copy_pipe = main_pipe->pipe_settings.video.copy_pipe;
assert(copy_pipe != NULL);
if (copy_pipe == NULL) {
IA_CSS_LOG(L_112);
err = IA_CSS_ERR_INTERNAL_ERROR;
goto ERR;
}
IA_CSS_LOG(L_110,
copy_pipe->pipeline.pipe_id);
err = ia_css_pipeline_request_stop(&copy_pipe->pipeline);
}
ERR:
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
static bool
sh_css_pipes_have_stopped(struct ia_css_stream *stream)
{
bool rval = true;
struct ia_css_pipe *main_pipe;
enum ia_css_pipe_id main_pipe_id;
int i;
assert(stream != NULL);
if (stream == NULL) {
IA_CSS_LOG(L_104);
rval = false;
goto RET;
}
main_pipe = stream->last_pipe;
assert(main_pipe != NULL);
if (main_pipe == NULL) {
IA_CSS_LOG(L_106);
rval = false;
goto RET;
}
main_pipe_id = main_pipe->mode;
IA_CSS_ENTER_PRIVATE(L_108, main_pipe_id);
for (i = 0; i < stream->num_pipes; i++) {
rval = rval && ia_css_pipeline_has_stopped(&stream->pipes[i]->pipeline);
IA_CSS_LOG(L_113,
stream->pipes[i]->pipeline.pipe_id,
rval);
}
if (main_pipe->stream->config.continuous) {
struct ia_css_pipe *copy_pipe = NULL;
if (main_pipe_id == IA_CSS_PIPE_ID_PREVIEW)
copy_pipe = main_pipe->pipe_settings.preview.copy_pipe;
else if (main_pipe_id == IA_CSS_PIPE_ID_VIDEO)
copy_pipe = main_pipe->pipe_settings.video.copy_pipe;
assert(copy_pipe != NULL);
if (copy_pipe == NULL) {
IA_CSS_LOG(L_112);
rval = false;
goto RET;
}
rval = rval && ia_css_pipeline_has_stopped(&copy_pipe->pipeline);
IA_CSS_LOG(L_113,
copy_pipe->pipeline.pipe_id,
rval);
}
RET:
IA_CSS_LEAVE_PRIVATE(L_114, rval);
return rval;
}
bool
sh_css_continuous_is_enabled(uint8_t pipe_num)
{
struct ia_css_pipe *pipe;
bool continuous;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, L_103, pipe_num);
pipe = find_pipe_by_num(pipe_num);
continuous = pipe && pipe->stream->config.continuous;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
L_105,
continuous);
return continuous;
}
enum ia_css_err
ia_css_stream_get_max_buffer_depth(struct ia_css_stream *stream, int *buffer_depth)
{
if (buffer_depth == NULL)
return IA_CSS_ERR_INVALID_ARGUMENTS;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, L_107);
(void)stream;
*buffer_depth = NUM_CONTINUOUS_FRAMES;
return IA_CSS_SUCCESS;
}
enum ia_css_err
ia_css_stream_set_buffer_depth(struct ia_css_stream *stream, int buffer_depth)
{
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, L_109,buffer_depth);
(void)stream;
if (buffer_depth > NUM_CONTINUOUS_FRAMES || buffer_depth < 1)
return IA_CSS_ERR_INVALID_ARGUMENTS;
stream->config.target_num_cont_raw_buf = buffer_depth;
return IA_CSS_SUCCESS;
}
enum ia_css_err
ia_css_stream_get_buffer_depth(struct ia_css_stream *stream, int *buffer_depth)
{
if (buffer_depth == NULL)
return IA_CSS_ERR_INVALID_ARGUMENTS;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, L_111);
#endif
(void)stream;
*buffer_depth = stream->config.target_num_cont_raw_buf;
return IA_CSS_SUCCESS;
}
#if ! F_11 ( V_239 ) && F_11 ( F_60 )
unsigned int
sh_css_get_mipi_sizes_for_check(const unsigned int port, const unsigned int idx)
{
OP___assert(port < N_CSI_PORTS);
OP___assert(idx < IA_CSS_MIPI_SIZE_CHECK_MAX_NOF_ENTRIES_PER_PORT);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, L_115,
port, idx, my_css.mipi_sizes_for_check[port][idx]);
return my_css.mipi_sizes_for_check[port][idx];
}
#endif
static enum ia_css_err sh_css_pipe_configure_output(
struct ia_css_pipe *pipe,
unsigned int width,
unsigned int height,
unsigned int padded_width,
enum ia_css_frame_format format,
unsigned int idx)
{
enum ia_css_err err = IA_CSS_SUCCESS;
IA_CSS_ENTER_PRIVATE(L_116,
pipe, width, height, padded_width, format, idx);
if (pipe == NULL) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
err = ia_css_util_check_res(width, height);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
if (pipe->output_info[idx].res.width != width ||
pipe->output_info[idx].res.height != height ||
pipe->output_info[idx].format != format)
{
ia_css_frame_info_init(
&pipe->output_info[idx],
width,
height,
format,
padded_width);
}
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_SUCCESS);
return IA_CSS_SUCCESS;
}
static enum ia_css_err
sh_css_pipe_get_shading_info(struct ia_css_pipe *pipe,
#ifndef F_55
struct ia_css_shading_info *info)
#else
struct ia_css_shading_info *shading_info,
struct ia_css_pipe_config *pipe_config)
#endif
{
enum V_1 V_52 = V_44 ;
struct V_50 * V_51 = NULL ;
assert ( V_3 != NULL ) ;
#ifndef F_55
assert ( V_181 != NULL ) ;
#else
assert ( V_603 != NULL ) ;
assert ( V_604 != NULL ) ;
#endif
F_6 ( V_53 ,
L_117 ) ;
V_51 = F_227 ( V_3 ) ;
if ( V_51 ) {
V_52 = F_228 ( V_51 ,
V_605 ,
V_3 -> V_606 ,
( const struct V_83 * ) & V_3 -> V_10 -> V_11 ,
#ifndef F_55
V_181 ) ;
#else
V_603 , V_604 ) ;
#endif
} else {
#ifndef F_55
memset ( V_181 , 0 , sizeof( * V_181 ) ) ;
#else
memset ( V_603 , 0 , sizeof( * V_603 ) ) ;
#endif
}
return V_52 ;
}
static enum V_1
F_229 ( struct V_2 * V_3 ,
struct V_607 * V_181 )
{
enum V_1 V_52 = V_44 ;
struct V_50 * V_51 = NULL ;
assert ( V_3 != NULL ) ;
assert ( V_181 != NULL ) ;
F_57 ( L_24 ) ;
V_51 = F_230 ( V_3 ) ;
if ( V_51 ) {
V_52 = F_231 ( V_51 , V_181 , V_3 ) ;
if ( V_52 != V_44 )
goto V_417;
} else
memset ( & V_181 -> V_608 , 0 , sizeof( V_181 -> V_608 ) ) ;
V_51 = F_232 ( V_3 ) ;
if ( V_51 ) {
F_233 ( V_51 , V_181 , V_3 ) ;
F_234 ( V_51 , V_181 , V_3 ) ;
} else {
memset ( & V_181 -> V_609 . V_610 , 0 ,
sizeof( V_181 -> V_609 . V_610 ) ) ;
memset ( & V_181 -> V_609 . V_611 , 0 ,
sizeof( V_181 -> V_609 . V_611 ) ) ;
}
if ( V_51 != NULL ) {
V_181 -> V_612 = V_51 -> V_613 . V_238 . V_67 ;
V_181 -> V_614 = V_51 -> V_613 . V_238 . V_68 ;
}
#if F_11 ( V_615 )
V_181 -> V_616 = V_617 ;
#elif F_11 ( V_618 )
V_181 -> V_616 = V_619 ;
#else
#error "Unknown VAMEM version"
#endif
V_417:
F_130 ( V_52 ) ;
return V_52 ;
}
static enum V_1
F_235 ( struct V_2 * V_3 , enum V_4 V_7 )
{
const enum V_4 * V_620 ;
int V_621 ;
int V_9 = 0 ;
int V_8 ;
F_57 ( L_24 ) ;
if ( NULL == V_3 || NULL == V_3 -> V_192 . V_196 . V_419 . V_181 ) {
F_144 ( L_118 ) ;
F_130 ( V_43 ) ;
return V_43 ;
}
V_620 = V_3 -> V_192 . V_196 . V_419 . V_181 -> V_622 ;
V_621 = sizeof( V_3 -> V_192 . V_196 . V_419 . V_181 -> V_622 ) / sizeof( enum V_4 ) ;
for ( V_8 = 0 ; V_8 < V_621 && ! V_9 ; V_8 ++ ) {
if ( V_620 [ V_8 ] == V_7 ) {
V_9 = 1 ;
break;
}
}
if ( ! V_9 ) {
F_144 ( L_119 ) ;
F_130 ( V_43 ) ;
return V_43 ;
} else {
F_130 ( V_44 ) ;
return V_44 ;
}
}
static enum V_1 F_236 ( struct V_2 * V_3 )
{
struct V_236 V_623 , V_624 ,
* V_625 , V_626 , * V_627 , * V_628 ;
bool V_60 ;
enum V_1 V_52 = V_44 ;
bool V_61 = V_3 -> V_10 -> V_11 . V_61 ;
unsigned int V_8 ;
unsigned V_629 ;
struct V_236 V_630 ;
bool V_631 = false ;
bool V_632 = false ;
bool V_633 = false ;
int V_634 ;
struct V_430 * V_635 = & V_3 -> V_192 . V_196 ;
F_57 ( L_24 ) ;
assert ( V_3 != NULL ) ;
assert ( V_3 -> V_59 == V_210 ) ;
if ( V_635 -> V_419 . V_181 )
return V_44 ;
V_60 = V_3 -> V_10 -> V_11 . V_60 ;
V_627 = & V_3 -> V_6 [ 0 ] ;
V_628 = & V_3 -> V_636 [ 0 ] ;
assert ( V_627 != NULL ) ;
V_52 = F_237 ( & V_3 -> V_10 -> V_11 , false , false ) ;
if ( V_52 != V_44 )
return V_52 ;
if ( V_60 && V_3 -> V_10 -> V_11 . V_59 == V_416 )
return V_43 ;
if ( V_3 -> V_637 [ V_638 ] ) {
V_52 = F_238 ( V_627 ,
V_628 ) ;
if ( V_52 != V_44 )
return V_52 ;
} else {
V_52 = F_239 ( V_627 ) ;
if ( V_52 != V_44 )
return V_52 ;
}
if ( V_3 -> V_639 . V_238 . V_67 )
V_630 = V_3 -> V_639 ;
else
V_630 = * V_627 ;
if ( V_3 -> V_637 [ V_638 ] ) {
V_625 = V_628 ;
V_632 = ( V_625 -> V_238 . V_67 != V_630 . V_238 . V_67 ) ||
( V_625 -> V_238 . V_68 != V_630 . V_238 . V_68 ) ;
}
else {
V_625 = NULL ;
}
V_631 = F_240 ( V_630 . V_238 , V_627 -> V_238 ) ;
if ( V_631 ) {
struct V_640 V_641
= V_642 ;
V_630 . V_7 = V_643 ;
V_52 = F_241 (
& V_630 ,
V_627 ,
NULL ,
& V_641 ) ;
if ( V_52 != V_44 )
return V_52 ;
V_635 -> V_644 = V_641 . V_645 ;
V_635 -> V_505 = F_242 ( V_641 . V_645 *
sizeof( struct V_50 ) , V_399 ) ;
if ( V_635 -> V_505 == NULL ) {
V_52 = V_444 ;
return V_52 ;
}
V_635 -> V_646 = F_242 ( V_641 . V_645
* sizeof( bool ) , V_399 ) ;
if ( V_635 -> V_646 == NULL ) {
V_52 = V_444 ;
return V_52 ;
}
for ( V_8 = 0 ; V_8 < V_641 . V_645 ; V_8 ++ ) {
struct V_647 V_648 ;
V_635 -> V_646 [ V_8 ] = V_641 . V_646 [ V_8 ] ;
F_243 ( V_3 ,
& V_648 , & V_641 . V_649 [ V_8 ] ,
& V_641 . V_650 [ V_8 ] ,
& V_641 . V_651 [ V_8 ] ,
& V_641 . V_652 [ V_8 ] ) ;
V_52 = F_244 ( & V_648 ,
& V_635 -> V_505 [ V_8 ] ) ;
if ( V_52 != V_44 ) {
F_127 ( V_635 -> V_646 ) ;
V_635 -> V_646 = NULL ;
return V_52 ;
}
}
F_245 ( & V_641 ) ;
}
{
struct V_647 V_653 ;
enum V_4 V_654 ;
V_52 = F_246 ( V_3 ,
& V_653 , & V_623 , & V_626 , & V_630 , V_625 ,
V_3 -> V_10 -> V_11 . V_179 ) ;
if ( V_52 != V_44 )
return V_52 ;
V_52 = F_244 ( & V_653 ,
& V_635 -> V_419 ) ;
if ( V_52 != V_44 ) {
if ( V_625 ) {
V_633 = true ;
} else
return V_52 ;
} else if ( V_625 ) {
V_629 = V_635 -> V_419 . V_181 -> V_629 ;
V_634 = V_635 -> V_419 . V_258 ;
V_633 |= ( ( V_629 == 2 ) && V_632 ) ;
V_633 |= ( ( V_629 == 1 ) &&
( ( V_625 -> V_238 . V_67 << V_634 != V_627 -> V_238 . V_67 ) ||
( V_625 -> V_238 . V_68 << V_634 != V_627 -> V_238 . V_68 ) ) ) ;
}
if ( V_633 ) {
F_6 ( V_323 ,
L_120 ) ;
V_654 = V_625 -> V_7 ;
if ( ! V_3 -> V_11 . V_655 )
F_247 ( V_625 ,
V_656 ) ;
F_176 ( & V_635 -> V_419 ) ;
V_52 = F_244 ( & V_653 ,
& V_635 -> V_419 ) ;
F_247 ( V_625 ,
V_654 ) ;
if ( V_52 != V_44 )
return V_52 ;
}
}
if ( ! V_635 -> V_419 . V_181 -> V_182 . V_157 . V_657 )
V_3 -> V_412 = 0 ;
V_3 -> V_658 = V_3 -> V_412 ;
V_3 -> V_181 . V_658 = V_3 -> V_658 ;
if ( V_625 )
V_3 -> V_658 *= 2 ;
F_6 ( V_323 ,
L_121 ,
V_3 -> V_658 , V_3 -> V_412 ) ;
#if ! F_11 ( F_18 )
if ( ! V_60 && ! V_61 ) {
V_52 = F_248 ( V_3 ,
& V_635 -> V_484 ,
& V_635 -> V_419 ) ;
if ( V_52 != V_44 )
return V_52 ;
}
#else
( void ) V_61 ;
#endif
#if ! F_11 ( V_659 )
if ( V_3 -> V_637 [ V_638 ] && V_633 ) {
struct V_647 V_660 ;
if ( V_635 -> V_419 . V_511 . V_7
== V_656 ) {
F_249 ( V_3 , & V_660 ,
& V_635 -> V_419 . V_511 ,
V_628 ) ;
} else {
assert ( V_3 -> V_11 . V_655 == true ) ;
F_243 ( V_3 , & V_660 ,
& V_635 -> V_419 . V_511 ,
V_628 , NULL , NULL ) ;
}
V_52 = F_244 ( & V_660 ,
& V_635 -> V_485 ) ;
if ( V_52 != V_44 )
return V_52 ;
}
#endif
V_52 = F_250 ( V_3 ) ;
if ( V_52 != V_44 )
return V_52 ;
if ( V_635 -> V_419 . V_181 -> V_182 . V_157 . V_661 ) {
#ifdef F_55
unsigned int V_662 ;
unsigned int V_663 ;
#endif
V_624 = V_635 -> V_419 . V_664 [ 0 ] ;
#ifdef F_55
if ( V_3 -> V_11 . V_665 . V_67 && V_3 -> V_11 . V_665 . V_68 ) {
V_662 = V_3 -> V_11 . V_665 . V_67 ;
V_663 = V_3 -> V_11 . V_665 . V_68 ;
} else {
V_662 = V_624 . V_238 . V_67 ;
V_663 = V_624 . V_238 . V_68 ;
}
V_624 . V_238 . V_67 =
F_251 ( V_662 ,
( V_635 -> V_419 . V_181 -> V_182 . V_666 . V_667 * V_668 ) ) ;
V_624 . V_669 = V_624 . V_238 . V_67 ;
#endif
V_624 . V_238 . V_68 =
#ifndef F_55
F_251 (tnr_info.res.height,
#else
CEIL_MUL(tnr_height,
#endif
mycs->video_binary.info->sp.block.output_block_height);
} else {
tnr_info = mycs->video_binary.internal_frame_info;
}
tnr_info.format = IA_CSS_FRAME_FORMAT_YUV_LINE;
tnr_info.raw_bit_depth = SH_CSS_TNR_BIT_DEPTH;
#ifndef F_55
for (i = 0; i < NUM_VIDEO_TNR_FRAMES; i++) {
#else
for (i = 0; i < NUM_TNR_FRAMES; i++) {
#endif
if (mycs->tnr_frames[i]) {
ia_css_frame_free(mycs->tnr_frames[i]);
mycs->tnr_frames[i] = NULL;
}
err = ia_css_frame_allocate_from_info(
&mycs->tnr_frames[i],
&tnr_info);
if (err != IA_CSS_SUCCESS)
return err;
}
IA_CSS_LEAVE_PRIVATE(L_24);
return IA_CSS_SUCCESS;
}
static enum ia_css_err
unload_video_binaries(struct ia_css_pipe *pipe)
{
unsigned int i;
IA_CSS_ENTER_PRIVATE(L_49, pipe);
if ((pipe == NULL) || (pipe->mode != IA_CSS_PIPE_ID_VIDEO)) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
ia_css_binary_unload(&pipe->pipe_settings.video.copy_binary);
ia_css_binary_unload(&pipe->pipe_settings.video.video_binary);
ia_css_binary_unload(&pipe->pipe_settings.video.vf_pp_binary);
#ifndef F_55
ia_css_binary_unload(&pipe->pipe_settings.video.vf_pp_binary);
#endif
for (i = 0; i < pipe->pipe_settings.video.num_yuv_scaler; i++)
ia_css_binary_unload(&pipe->pipe_settings.video.yuv_scaler_binary[i]);
kfree(pipe->pipe_settings.video.is_output_stage);
pipe->pipe_settings.video.is_output_stage = NULL;
kfree(pipe->pipe_settings.video.yuv_scaler_binary);
pipe->pipe_settings.video.yuv_scaler_binary = NULL;
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_SUCCESS);
return IA_CSS_SUCCESS;
}
static enum ia_css_err video_start(struct ia_css_pipe *pipe)
{
struct ia_css_binary *copy_binary;
enum ia_css_err err = IA_CSS_SUCCESS;
struct ia_css_pipe *copy_pipe, *capture_pipe;
enum sh_css_pipe_config_override copy_ovrd;
enum ia_css_input_mode video_pipe_input_mode;
IA_CSS_ENTER_PRIVATE(L_49, pipe);
if ((pipe == NULL) || (pipe->mode != IA_CSS_PIPE_ID_VIDEO)) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
video_pipe_input_mode = pipe->stream->config.mode;
copy_pipe = pipe->pipe_settings.video.copy_pipe;
capture_pipe = pipe->pipe_settings.video.capture_pipe;
copy_binary = &pipe->pipe_settings.video.copy_binary;
sh_css_metrics_start_frame();
#if F_11 ( F_60 ) || F_11 ( F_18 )
err = send_mipi_frames(pipe);
if (err != IA_CSS_SUCCESS)
return err;
#endif
send_raw_frames(pipe);
{
unsigned int thread_id;
ia_css_pipeline_get_sp_thread_id(ia_css_pipe_get_pipe_num(pipe), &thread_id);
copy_ovrd = 1 << thread_id;
if (pipe->stream->cont_capt) {
ia_css_pipeline_get_sp_thread_id(ia_css_pipe_get_pipe_num(capture_pipe), &thread_id);
copy_ovrd |= 1 << thread_id;
}
}
if (pipe->stream->config.continuous) {
sh_css_sp_init_pipeline(&copy_pipe->pipeline,
IA_CSS_PIPE_ID_COPY,
(uint8_t)ia_css_pipe_get_pipe_num(copy_pipe),
false,
pipe->stream->config.pixels_per_clock == 2, false,
false, pipe->required_bds_factor,
copy_ovrd,
pipe->stream->config.mode,
&pipe->stream->config.metadata_config,
#ifndef F_55
&pipe->stream->info.metadata_info
#else
&pipe->stream->info.metadata_info,
#endif
#if ! F_11 ( V_239 )
#ifndef F_55
, pipe->stream->config.source.port.port
#else
pipe->stream->config.source.port.port,
#endif
#endif
#ifndef F_55
);
#else
&copy_pipe->config.internal_frame_origin_bqs_on_sctbl,
copy_pipe->stream->isp_params_configs) ;
#endif
V_670 = V_416 ;
}
if ( V_3 -> V_10 -> V_566 ) {
F_58 ( & V_405 -> V_54 ,
V_408 ,
( T_7 ) F_27 ( V_405 ) ,
V_405 -> V_11 . V_671 . V_672 != 0 ,
V_405 -> V_10 -> V_11 . V_47 == 2 ,
true ,
false ,
V_405 -> V_606 ,
0 ,
V_416 ,
& V_3 -> V_10 -> V_11 . V_158 ,
#ifndef F_55
& V_3 -> V_10 -> V_181 . V_673
#else
& V_3 -> V_10 -> V_181 . V_673 ,
#endif
#if ! F_11 ( V_239 )
#ifndef F_55
, ( T_2 ) 0
#else
( T_2 ) 0 ,
#endif
#endif
#ifndef F_55
) ;
#else
& V_405 -> V_11 . V_264 ,
V_405 -> V_10 -> V_265 ) ;
#endif
}
enum V_1 F_197 (
struct V_2 * V_3 ,
struct V_236 * V_181 ,
unsigned int V_514 )
{
assert ( V_3 != NULL ) ;
assert ( V_181 != NULL ) ;
F_6 ( V_53 , L_122 ) ;
if ( V_3 -> V_59 == V_408 &&
( V_3 -> V_11 . V_671 . V_59 == V_674 ||
V_3 -> V_11 . V_671 . V_59 == V_675 ) )
return V_676 ;
* V_181 = V_3 -> V_636 [ V_514 ] ;
F_6 ( V_53 ,
L_123 ,
V_181 -> V_238 . V_67 , V_181 -> V_238 . V_68 ,
V_181 -> V_669 , V_181 -> V_7 ,
V_181 -> V_548 , V_181 -> V_543 ) ;
return V_44 ;
}
static enum V_1
F_252 ( struct V_2 * V_3 , unsigned int V_67 ,
unsigned int V_68 , unsigned int V_677 ,
enum V_4 V_7 ,
unsigned int V_514 )
{
enum V_1 V_52 = V_44 ;
F_57 ( L_124 ,
V_3 , V_67 , V_68 , V_677 , V_7 , V_514 ) ;
if ( V_3 == NULL ) {
F_130 ( V_43 ) ;
return V_43 ;
}
V_52 = F_253 ( V_67 , V_68 ) ;
if ( V_52 != V_44 ) {
F_130 ( V_52 ) ;
return V_52 ;
}
if ( V_3 -> V_636 [ V_514 ] . V_238 . V_67 != V_67 ||
V_3 -> V_636 [ V_514 ] . V_238 . V_68 != V_68 ||
V_3 -> V_636 [ V_514 ] . V_7 != V_7 ) {
F_254 ( & V_3 -> V_636 [ V_514 ] , V_67 , V_68 ,
V_7 , V_677 ) ;
}
F_130 ( V_44 ) ;
return V_44 ;
}
static enum V_1 F_255 ( struct V_2 * V_3 )
{
enum V_1 V_52 = V_44 ;
assert ( V_3 != NULL ) ;
F_57 ( L_24 ) ;
assert ( V_3 -> V_59 == V_408 || V_3 -> V_59 == V_435 ) ;
if ( V_3 -> V_192 . V_436 . V_484 . V_181 )
return V_44 ;
V_52 = F_239 ( & V_3 -> V_6 [ 0 ] ) ;
if ( V_52 != V_44 )
goto V_417;
V_52 = F_1 ( V_3 ) ;
if ( V_52 != V_44 )
goto V_417;
V_52 = F_248 ( V_3 ,
& V_3 -> V_192 . V_436 . V_484 ,
NULL ) ;
V_417:
F_130 ( V_52 ) ;
return V_52 ;
}
static bool F_256 (
const struct V_2 * V_3 )
{
const struct V_236 * V_650 = & V_3 -> V_6 [ 0 ] ;
F_179 ( L_24 ) ;
assert ( V_3 != NULL ) ;
assert ( V_3 -> V_59 == V_408 ) ;
#ifdef F_55
if ( F_257 ( V_3 ) == true )
return false ;
#endif
if ( V_3 -> V_639 . V_238 . V_67 &&
( ( V_3 -> V_639 . V_238 . V_67 != V_650 -> V_238 . V_67 ) ||
( V_3 -> V_639 . V_238 . V_68 != V_650 -> V_238 . V_68 ) ) )
return true ;
if ( V_3 -> V_11 . V_671 . V_672 != 0 )
return true ;
if ( ( V_3 -> V_10 -> V_265 -> V_678 . V_679 < V_680 ) ||
( V_3 -> V_10 -> V_265 -> V_678 . V_681 < V_680 ) ||
V_3 -> V_11 . V_682 )
return true ;
return false ;
}
static bool F_257 (
const struct V_2 * V_3 )
{
F_179 ( L_24 ) ;
assert ( V_3 != NULL ) ;
assert ( V_3 -> V_59 == V_408 ) ;
return ( V_3 -> V_502 . V_683 ) ? true : false ;
}
static enum V_1 F_258 ( unsigned int * V_684 , enum V_685 V_686 )
{
enum V_1 V_52 = V_44 ;
if ( V_684 == NULL )
return V_43 ;
switch ( V_686 ) {
case V_687 :
* V_684 = V_688 ;
break;
case V_689 :
case V_690 :
* V_684 = V_691 ;
break;
default:
V_52 = V_43 ;
break;
}
return V_52 ;
}
static enum V_1
F_250 ( struct V_2 * V_3 )
{
unsigned int V_692 = 0 , V_8 = 0 ;
unsigned int V_412 = 0 ;
struct V_236 V_693 ;
enum V_1 V_52 = V_44 ;
enum V_207 V_59 = V_210 ;
struct V_245 * * V_252 = NULL ;
F_57 ( L_24 ) ;
if ( V_3 == NULL ) {
F_144 ( L_125 , V_3 ) ;
return V_43 ;
}
V_59 = V_3 -> V_59 ;
V_412 = V_3 -> V_412 ;
if ( V_412 > 0 )
V_692 = V_412 + 1 ;
switch ( V_59 ) {
case V_408 :
{
struct V_427 * V_694 = & V_3 -> V_192 . V_436 ;
( void ) V_694 ;
return V_52 ;
}
break;
case V_210 :
{
struct V_430 * V_695 = & V_3 -> V_192 . V_196 ;
V_693 = V_695 -> V_419 . V_613 ;
V_693 . V_7 = V_643 ;
V_252 = V_695 -> V_252 ;
}
break;
case V_209 :
{
struct V_424 * V_696 = & V_3 -> V_192 . V_193 ;
V_693 = V_696 -> V_418 . V_613 ;
V_693 . V_7 = V_643 ;
V_252 = V_696 -> V_252 ;
}
break;
default:
return V_43 ;
}
V_693 . V_548 = V_697 ;
assert ( V_692 <= V_251 ) ;
for ( V_8 = 0 ; V_8 < V_692 ; V_8 ++ ) {
V_52 = F_189 ( & V_252 [ V_8 ] , & V_693 ) ;
if ( V_52 != V_44 )
return V_52 ;
}
F_66 ( L_24 ) ;
return V_44 ;
}
static enum V_1 F_259 (
struct V_2 * V_3 )
{
struct V_236 V_698 , V_699 ,
V_700 , V_701 ,
V_652 , * V_702 , * V_627 ,
* V_628 ;
bool V_703 ;
bool V_704 = true ;
enum V_1 V_52 = V_44 ;
F_57 ( L_24 ) ;
assert ( V_3 != NULL ) ;
assert ( V_3 -> V_59 == V_408 || V_3 -> V_59 == V_435 ) ;
if ( V_3 -> V_192 . V_436 . V_705 . V_181 )
return V_44 ;
V_627 = & V_3 -> V_6 [ 0 ] ;
V_628 = & V_3 -> V_636 [ 0 ] ;
V_652 = * V_628 ;
V_52 = F_238 ( V_627 , & V_652 ) ;
if ( V_52 != V_44 )
return V_52 ;
V_703 = F_256 ( V_3 ) ;
F_247 ( & V_652 ,
V_656 ) ;
if ( V_703 ) {
struct V_647 V_706 ;
F_260 ( V_3 ,
& V_706 , & V_701 , V_627 , & V_652 ) ;
V_52 = F_244 ( & V_706 ,
& V_3 -> V_192 . V_436 . V_509 ) ;
if ( V_52 != V_44 )
return V_52 ;
} else {
V_701 = * V_627 ;
}
{
struct V_647 V_707 ;
F_261 ( V_3 ,
& V_707 , & V_700 , & V_701 , & V_652 ) ;
V_52 = F_244 ( & V_707 ,
& V_3 -> V_192 . V_436 . V_708 ) ;
if ( V_52 != V_44 )
return V_52 ;
}
{
struct V_647 V_709 ;
F_262 ( V_3 , & V_709 , & V_699 ,
& V_3 -> V_192 . V_436 . V_708 . V_198 ) ;
V_52 = F_244 ( & V_709 ,
& V_3 -> V_192 . V_436 . V_710 ) ;
if ( V_52 != V_44 )
return V_52 ;
}
V_3 -> V_192 . V_436 . V_710 . V_179 =
V_3 -> V_192 . V_436 . V_708 . V_179 ;
{
struct V_647 V_711 ;
F_263 ( V_3 , & V_711 , & V_698 ,
& V_3 -> V_192 . V_436 . V_710 . V_198 ) ;
V_52 = F_244 ( & V_711 ,
& V_3 -> V_192 . V_436 . V_705 ) ;
if ( V_52 != V_44 )
return V_52 ;
}
V_3 -> V_192 . V_436 . V_705 . V_179 =
V_3 -> V_192 . V_436 . V_710 . V_179 ;
if ( V_703 ) {
V_702 =
& V_3 -> V_192 . V_436 . V_509 . V_511 ;
} else {
V_702 =
& V_3 -> V_192 . V_436 . V_708 . V_511 ;
}
{
struct V_647 V_660 ;
F_249 ( V_3 ,
& V_660 , V_702 , V_628 ) ;
V_52 = F_244 ( & V_660 ,
& V_3 -> V_192 . V_436 . V_485 ) ;
if ( V_52 != V_44 )
return V_52 ;
}
#ifdef F_18
V_704 = V_3 -> V_10 -> V_11 . V_59 == V_111 ;
#endif
if ( V_704 )
F_248 ( V_3 ,
& V_3 -> V_192 . V_436 . V_484 ,
& V_3 -> V_192 . V_436 . V_705 ) ;
return V_52 ;
}
static enum V_1 F_264 (
struct V_2 * V_3 )
{
struct V_236 V_712 , * V_627 ;
enum V_1 V_52 = V_44 ;
struct V_647 V_713 ;
F_57 ( L_24 ) ;
assert ( V_3 != NULL ) ;
assert ( V_3 -> V_59 == V_408 || V_3 -> V_59 == V_435 ) ;
V_627 = & V_3 -> V_6 [ 0 ] ;
if ( V_3 -> V_192 . V_436 . V_705 . V_181 )
return V_44 ;
V_52 = F_239 ( V_627 ) ;
if ( V_52 != V_44 )
return V_52 ;
F_265 ( V_3 , & V_713 ,
& V_712 ,
V_627 ) ;
V_52 = F_244 ( & V_713 ,
& V_3 -> V_192 . V_436 . V_705 ) ;
return V_52 ;
}
static enum V_1 F_266 (
struct V_2 * V_3 )
{
struct V_236 V_698 , V_714 ,
V_700 , V_701 ,
V_652 , * V_628 , * V_627 ,
* V_702 ;
bool V_703 ;
bool V_704 = true ;
enum V_1 V_52 = V_44 ;
F_57 ( L_24 ) ;
assert ( V_3 != NULL ) ;
assert ( V_3 -> V_59 == V_408 || V_3 -> V_59 == V_435 ) ;
if ( V_3 -> V_192 . V_436 . V_705 . V_181 )
return V_44 ;
V_628 = & V_3 -> V_636 [ 0 ] ;
V_627 = & V_3 -> V_6 [ 0 ] ;
V_652 = * V_628 ;
V_52 = F_238 ( V_627 ,
& V_652 ) ;
if ( V_52 != V_44 )
return V_52 ;
V_703 = F_256 ( V_3 ) ;
F_247 ( & V_652 ,
V_656 ) ;
if ( V_703 ) {
struct V_647 V_706 ;
F_260 ( V_3 ,
& V_706 , & V_701 , V_627 , & V_652 ) ;
V_52 = F_244 ( & V_706 ,
& V_3 -> V_192 . V_436 . V_509 ) ;
if ( V_52 != V_44 )
return V_52 ;
} else {
V_701 = * V_627 ;
}
{
struct V_647 V_715 ;
F_267 ( V_3 ,
& V_715 , & V_700 , & V_701 , & V_652 ) ;
V_52 = F_244 ( & V_715 ,
& V_3 -> V_192 . V_436 . V_708 ) ;
if ( V_52 != V_44 )
return V_52 ;
}
{
struct V_647 V_716 ;
F_268 ( V_3 , & V_716 , & V_714 ,
& V_3 -> V_192 . V_436 . V_708 . V_198 ) ;
V_52 = F_244 ( & V_716 ,
& V_3 -> V_192 . V_436 . V_710 ) ;
if ( V_52 != V_44 )
return V_52 ;
}
V_3 -> V_192 . V_436 . V_710 . V_179 =
V_3 -> V_192 . V_436 . V_708 . V_179 ;
{
struct V_647 V_717 ;
F_269 ( V_3 , & V_717 , & V_698 ,
& V_3 -> V_192 . V_436 . V_710 . V_198 ) ;
V_52 = F_244 ( & V_717 ,
& V_3 -> V_192 . V_436 . V_705 ) ;
if ( V_52 != V_44 )
return V_52 ;
}
V_3 -> V_192 . V_436 . V_705 . V_179 =
V_3 -> V_192 . V_436 . V_710 . V_179 ;
if ( V_703 ) {
V_702 =
& V_3 -> V_192 . V_436 . V_509 . V_511 ;
} else {
V_702 =
& V_3 -> V_192 . V_436 . V_708 . V_511 ;
}
{
struct V_647 V_660 ;
F_249 ( V_3 ,
& V_660 , V_702 , V_628 ) ;
V_52 = F_244 ( & V_660 ,
& V_3 -> V_192 . V_436 . V_485 ) ;
if ( V_52 != V_44 )
return V_52 ;
}
#ifdef F_18
V_704 = V_3 -> V_10 -> V_11 . V_59 == V_111 ;
#endif
if ( V_704 )
V_52 = F_248 ( V_3 ,
& V_3 -> V_192 . V_436 . V_484 ,
& V_3 -> V_192 . V_436 . V_705 ) ;
return V_52 ;
}
static bool F_270 ( struct V_2 * V_3 )
{
bool V_74 ;
assert ( V_3 != NULL ) ;
F_6 ( V_53 , L_126 ) ;
V_74 = true ;
V_74 &= ( V_3 -> V_59 == V_408 ) ;
V_74 &= ( V_3 -> V_11 . V_671 . V_59 == V_674 ) ;
V_74 &= ( ( V_3 -> V_10 -> V_11 . V_12 . V_7 == V_41 ) ||
( V_3 -> V_11 . V_59 == V_62 ) ) ;
return V_74 ;
}
static enum V_1 F_271 (
struct V_2 * V_3 )
{
enum V_1 V_52 = V_44 ;
bool V_718 ;
F_57 ( L_24 ) ;
assert ( V_3 != NULL ) ;
assert ( V_3 -> V_59 == V_408 || V_3 -> V_59 == V_435 ) ;
if ( V_3 -> V_192 . V_436 . V_535 [ 0 ] . V_181 ) {
F_130 ( V_44 ) ;
return V_44 ;
}
V_718 =
V_3 -> V_11 . V_671 . V_59 == V_719 ||
V_3 -> V_11 . V_671 . V_59 == V_675 ||
V_3 -> V_11 . V_671 . V_59 == V_720 ;
V_52 = F_237 ( & V_3 -> V_10 -> V_11 , V_718 , false ) ;
if ( V_52 != V_44 ) {
F_130 ( V_52 ) ;
return V_52 ;
}
if ( F_270 ( V_3 ) &&
V_3 -> V_10 -> V_11 . V_12 . V_7 == V_41 ) {
F_254 (
& V_3 -> V_6 [ 0 ] ,
V_721 ,
1 ,
V_42 ,
0 ) ;
F_130 ( V_44 ) ;
return V_44 ;
}
switch ( V_3 -> V_11 . V_671 . V_59 ) {
case V_674 :
V_52 = F_255 ( V_3 ) ;
#if ! F_11 ( V_239 ) && F_11 ( F_18 )
if ( V_52 == V_44 )
V_3 -> V_192 . V_436 . V_484 . V_60 = V_3 -> V_10 -> V_11 . V_60 ;
#endif
break;
case V_675 :
V_52 = F_264 ( V_3 ) ;
break;
case V_722 :
V_52 = F_272 ( V_3 ) ;
break;
case V_719 :
V_52 = F_259 ( V_3 ) ;
break;
case V_720 :
V_52 = F_266 ( V_3 ) ;
break;
}
if ( V_52 != V_44 ) {
F_130 ( V_52 ) ;
return V_52 ;
}
F_130 ( V_52 ) ;
return V_52 ;
}
static enum V_1
F_273 ( struct V_2 * V_3 )
{
unsigned int V_8 ;
F_57 ( L_49 , V_3 ) ;
if ( ( V_3 == NULL ) || ( ( V_3 -> V_59 != V_408 ) && ( V_3 -> V_59 != V_435 ) ) ) {
F_130 ( V_43 ) ;
return V_43 ;
}
F_175 ( & V_3 -> V_192 . V_436 . V_484 ) ;
for ( V_8 = 0 ; V_8 < V_723 ; V_8 ++ )
F_175 ( & V_3 -> V_192 . V_436 . V_535 [ V_8 ] ) ;
F_175 ( & V_3 -> V_192 . V_436 . V_705 ) ;
F_175 ( & V_3 -> V_192 . V_436 . V_710 ) ;
F_175 ( & V_3 -> V_192 . V_436 . V_708 ) ;
F_175 ( & V_3 -> V_192 . V_436 . V_509 ) ;
F_175 ( & V_3 -> V_192 . V_436 . V_724 ) ;
F_175 ( & V_3 -> V_192 . V_436 . V_485 ) ;
for ( V_8 = 0 ; V_8 < V_3 -> V_192 . V_436 . V_644 ; V_8 ++ )
F_175 ( & V_3 -> V_192 . V_436 . V_505 [ V_8 ] ) ;
F_127 ( V_3 -> V_192 . V_436 . V_646 ) ;
V_3 -> V_192 . V_436 . V_646 = NULL ;
F_127 ( V_3 -> V_192 . V_436 . V_505 ) ;
V_3 -> V_192 . V_436 . V_505 = NULL ;
F_130 ( V_44 ) ;
return V_44 ;
}
static bool
F_240 ( const struct V_532 V_725 ,
const struct V_532 V_726 )
{
if ( V_725 . V_67 > V_726 . V_67 || V_725 . V_68 > V_726 . V_68 )
return true ;
return false ;
}
static bool
F_274 ( const struct V_2 * V_3 )
{
unsigned int V_8 ;
struct V_532 V_725 , V_726 ;
bool V_727 = false ;
F_57 ( L_24 ) ;
assert ( V_3 != NULL ) ;
assert ( V_3 -> V_59 == V_414 ) ;
V_727 =
( ( V_3 -> V_10 -> V_11 . V_12 . V_7 == V_13 ) &&
( V_3 -> V_6 [ 0 ] . V_7 != V_728 ) ) ;
V_725 = V_3 -> V_11 . V_542 ;
if ( V_3 -> V_11 . V_682 )
return true ;
if ( ( V_3 -> V_6 [ 0 ] . V_238 . V_67 != 0 ) && V_727 )
return true ;
for ( V_8 = 0 ; V_8 < V_729 ; V_8 ++ ) {
V_726 = V_3 -> V_6 [ V_8 ] . V_238 ;
if ( ( V_726 . V_67 != 0 ) && F_240 ( V_725 , V_726 ) )
return true ;
}
return false ;
}
static enum V_1 F_241 (
struct V_236 * V_730 ,
struct V_236 * V_731 ,
struct V_236 * V_732 ,
struct V_640 * V_733 )
{
unsigned int V_8 ;
unsigned int V_734 = 0 , V_735 = 0 ;
enum V_1 V_52 = V_44 ;
struct V_236 V_736 = V_737 ;
unsigned V_738 = V_739 ;
assert ( V_730 != NULL ) ;
assert ( V_731 != NULL ) ;
F_6 ( V_53 , L_127 ) ;
V_733 -> V_740 = 1 ;
V_734 = F_275 ( V_730 -> V_238 . V_67 , V_731 -> V_238 . V_67 ) ;
V_735 = F_275 ( V_730 -> V_238 . V_68 , V_731 -> V_238 . V_68 ) ;
assert ( V_734 == V_735 ) ;
V_8 = 1 ;
while ( V_8 < V_734 ) {
V_733 -> V_645 ++ ;
V_8 *= V_738 ;
}
V_733 -> V_649 = F_122 ( V_733 -> V_645 * sizeof( struct V_236 ) , V_399 ) ;
if ( V_733 -> V_649 == NULL ) {
V_52 = V_444 ;
goto V_417;
}
V_733 -> V_651 = F_122 ( V_733 -> V_645 * sizeof( struct V_236 ) , V_399 ) ;
if ( V_733 -> V_651 == NULL ) {
V_52 = V_444 ;
goto V_417;
}
V_733 -> V_650 = F_122 ( V_733 -> V_645 * sizeof( struct V_236 ) , V_399 ) ;
if ( V_733 -> V_650 == NULL ) {
V_52 = V_444 ;
goto V_417;
}
V_733 -> V_652 = F_122 ( V_733 -> V_645 * sizeof( struct V_236 ) , V_399 ) ;
if ( V_733 -> V_652 == NULL ) {
V_52 = V_444 ;
goto V_417;
}
V_733 -> V_646 = F_122 ( V_733 -> V_645 * sizeof( bool ) , V_399 ) ;
if ( V_733 -> V_646 == NULL ) {
V_52 = V_444 ;
goto V_417;
}
V_736 = * V_730 ;
for ( V_8 = 0 ; V_8 < V_733 -> V_645 ; V_8 ++ ) {
V_733 -> V_649 [ V_8 ] = V_736 ;
if ( ( V_736 . V_238 . V_67 / V_738 ) <= V_731 -> V_238 . V_67 ) {
V_733 -> V_646 [ V_8 ] = true ;
if ( ( V_733 -> V_740 > 1 ) && ( V_8 != ( V_733 -> V_645 - 1 ) ) ) {
V_733 -> V_651 [ V_8 ] . V_238 . V_67 = V_731 -> V_238 . V_67 ;
V_733 -> V_651 [ V_8 ] . V_238 . V_68 = V_731 -> V_238 . V_68 ;
V_733 -> V_651 [ V_8 ] . V_669 = V_731 -> V_669 ;
V_733 -> V_651 [ V_8 ] . V_7 = V_31 ;
} else {
assert ( V_8 == ( V_733 -> V_645 - 1 ) ) ;
V_733 -> V_651 [ V_8 ] . V_238 . V_67 = 0 ;
V_733 -> V_651 [ V_8 ] . V_238 . V_68 = 0 ;
}
V_733 -> V_650 [ V_8 ] . V_238 . V_67 = V_731 -> V_238 . V_67 ;
V_733 -> V_650 [ V_8 ] . V_238 . V_68 = V_731 -> V_238 . V_68 ;
V_733 -> V_650 [ V_8 ] . V_669 = V_731 -> V_669 ;
V_733 -> V_650 [ V_8 ] . V_7 = V_731 -> V_7 ;
if ( V_732 != NULL ) {
V_733 -> V_652 [ V_8 ] . V_238 . V_67 = V_732 -> V_238 . V_67 ;
V_733 -> V_652 [ V_8 ] . V_238 . V_68 = V_732 -> V_238 . V_68 ;
V_733 -> V_652 [ V_8 ] . V_669 = V_732 -> V_669 ;
F_247 ( & V_733 -> V_652 [ V_8 ] , V_656 ) ;
} else {
V_733 -> V_652 [ V_8 ] . V_238 . V_67 = 0 ;
V_733 -> V_652 [ V_8 ] . V_238 . V_68 = 0 ;
V_733 -> V_652 [ V_8 ] . V_669 = 0 ;
}
} else {
V_733 -> V_646 [ V_8 ] = false ;
V_733 -> V_651 [ V_8 ] . V_238 . V_67 = V_736 . V_238 . V_67 / V_738 ;
V_733 -> V_651 [ V_8 ] . V_238 . V_68 = V_736 . V_238 . V_68 / V_738 ;
V_733 -> V_651 [ V_8 ] . V_7 = V_31 ;
F_254 ( & V_733 -> V_651 [ V_8 ] ,
V_736 . V_238 . V_67 / V_738 ,
V_736 . V_238 . V_68 / V_738 ,
V_31 , 0 ) ;
V_733 -> V_650 [ V_8 ] . V_238 . V_67 = 0 ;
V_733 -> V_650 [ V_8 ] . V_238 . V_68 = 0 ;
V_733 -> V_652 [ V_8 ] . V_238 . V_67 = 0 ;
V_733 -> V_652 [ V_8 ] . V_238 . V_68 = 0 ;
}
V_736 = V_733 -> V_651 [ V_8 ] ;
}
V_417:
F_6 ( V_53 , L_128 ,
V_52 ) ;
return V_52 ;
}
static enum V_1 F_276 ( struct V_2 * V_3 ,
struct V_640 * V_733 )
{
struct V_236 V_649 = V_737 ;
struct V_236 * V_650 [ V_729 ] ;
struct V_236 * V_741 [ V_729 ] ;
struct V_236 V_736 = V_737 ;
unsigned int V_8 , V_391 ;
unsigned int V_742 [ V_729 ] ,
V_743 [ V_729 ] ,
V_744 = 0 ;
unsigned int V_745 = 0 ;
enum V_1 V_52 = V_44 ;
unsigned V_738 = V_739 ;
F_6 ( V_53 , L_127 ) ;
for ( V_8 = 0 ; V_8 < V_729 ; V_8 ++ ) {
V_650 [ V_8 ] = NULL ;
V_741 [ V_8 ] = NULL ;
V_742 [ V_8 ] = 0 ;
V_743 [ V_8 ] = 0 ;
}
V_649 . V_238 = V_3 -> V_11 . V_542 ;
V_649 . V_669 = V_649 . V_238 . V_67 ;
V_733 -> V_740 = 0 ;
for ( V_8 = 0 ; V_8 < V_729 ; V_8 ++ ) {
if ( V_3 -> V_6 [ V_8 ] . V_238 . V_67 != 0 ) {
V_650 [ V_8 ] = & V_3 -> V_6 [ V_8 ] ;
if ( V_3 -> V_636 [ V_8 ] . V_238 . V_67 != 0 )
V_741 [ V_8 ] = & V_3 -> V_636 [ V_8 ] ;
V_733 -> V_740 += 1 ;
}
if ( V_650 [ V_8 ] != NULL ) {
V_742 [ V_8 ] = F_275 ( V_649 . V_238 . V_67 , V_650 [ V_8 ] -> V_238 . V_67 ) ;
V_743 [ V_8 ] = F_275 ( V_649 . V_238 . V_68 , V_650 [ V_8 ] -> V_238 . V_68 ) ;
assert ( V_742 [ V_8 ] == V_743 [ V_8 ] ) ;
V_744 = 1 ;
do {
V_745 ++ ;
V_744 *= V_738 ;
} while ( V_744 < V_742 [ V_8 ] );
V_649 . V_238 = V_650 [ V_8 ] -> V_238 ;
}
}
if ( F_274 ( V_3 ) && ( V_745 == 0 ) )
V_745 = 1 ;
V_733 -> V_645 = V_745 ;
V_733 -> V_649 = F_122 ( V_733 -> V_645 * sizeof( struct V_236 ) , V_399 ) ;
if ( V_733 -> V_649 == NULL ) {
V_52 = V_444 ;
goto V_417;
}
V_733 -> V_651 = F_122 ( V_733 -> V_645 * sizeof( struct V_236 ) , V_399 ) ;
if ( V_733 -> V_651 == NULL ) {
V_52 = V_444 ;
goto V_417;
}
V_733 -> V_650 = F_122 ( V_733 -> V_645 * sizeof( struct V_236 ) , V_399 ) ;
if ( V_733 -> V_650 == NULL ) {
V_52 = V_444 ;
goto V_417;
}
V_733 -> V_652 = F_122 ( V_733 -> V_645 * sizeof( struct V_236 ) , V_399 ) ;
if ( V_733 -> V_652 == NULL ) {
V_52 = V_444 ;
goto V_417;
}
V_733 -> V_646 = F_122 ( V_733 -> V_645 * sizeof( bool ) , V_399 ) ;
if ( V_733 -> V_646 == NULL ) {
V_52 = V_444 ;
goto V_417;
}
for ( V_8 = 0 ; V_8 < V_729 ; V_8 ++ ) {
if ( V_650 [ V_8 ] ) {
if ( V_8 > 0 ) {
assert ( ( V_650 [ V_8 - 1 ] -> V_238 . V_67 >= V_650 [ V_8 ] -> V_238 . V_67 ) &&
( V_650 [ V_8 - 1 ] -> V_238 . V_68 >= V_650 [ V_8 ] -> V_238 . V_68 ) ) ;
}
}
}
V_736 . V_238 = V_3 -> V_11 . V_542 ;
V_736 . V_7 = V_31 ;
for ( V_8 = 0 , V_391 = 0 ; V_8 < V_733 -> V_645 ; V_8 ++ ) {
assert ( V_391 < 2 ) ;
assert ( V_650 [ V_391 ] != NULL ) ;
V_733 -> V_649 [ V_8 ] = V_736 ;
if ( ( V_736 . V_238 . V_67 / V_738 ) <= V_650 [ V_391 ] -> V_238 . V_67 ) {
V_733 -> V_646 [ V_8 ] = true ;
if ( ( V_733 -> V_740 > 1 ) && ( V_8 != ( V_733 -> V_645 - 1 ) ) ) {
V_733 -> V_651 [ V_8 ] . V_238 . V_67 = V_650 [ V_391 ] -> V_238 . V_67 ;
V_733 -> V_651 [ V_8 ] . V_238 . V_68 = V_650 [ V_391 ] -> V_238 . V_68 ;
V_733 -> V_651 [ V_8 ] . V_669 = V_650 [ V_391 ] -> V_669 ;
V_733 -> V_651 [ V_8 ] . V_7 = V_31 ;
} else {
assert ( V_8 == ( V_733 -> V_645 - 1 ) ) ;
V_733 -> V_651 [ V_8 ] . V_238 . V_67 = 0 ;
V_733 -> V_651 [ V_8 ] . V_238 . V_68 = 0 ;
}
V_733 -> V_650 [ V_8 ] . V_238 . V_67 = V_650 [ V_391 ] -> V_238 . V_67 ;
V_733 -> V_650 [ V_8 ] . V_238 . V_68 = V_650 [ V_391 ] -> V_238 . V_68 ;
V_733 -> V_650 [ V_8 ] . V_669 = V_650 [ V_391 ] -> V_669 ;
V_733 -> V_650 [ V_8 ] . V_7 = V_650 [ V_391 ] -> V_7 ;
if ( V_741 [ V_391 ] != NULL ) {
V_733 -> V_652 [ V_8 ] . V_238 . V_67 = V_741 [ V_391 ] -> V_238 . V_67 ;
V_733 -> V_652 [ V_8 ] . V_238 . V_68 = V_741 [ V_391 ] -> V_238 . V_68 ;
V_733 -> V_652 [ V_8 ] . V_669 = V_741 [ V_391 ] -> V_669 ;
F_247 ( & V_733 -> V_652 [ V_8 ] , V_656 ) ;
} else {
V_733 -> V_652 [ V_8 ] . V_238 . V_67 = 0 ;
V_733 -> V_652 [ V_8 ] . V_238 . V_68 = 0 ;
V_733 -> V_652 [ V_8 ] . V_669 = 0 ;
}
V_391 ++ ;
} else {
V_733 -> V_646 [ V_8 ] = false ;
V_733 -> V_651 [ V_8 ] . V_238 . V_67 = V_736 . V_238 . V_67 / V_738 ;
V_733 -> V_651 [ V_8 ] . V_238 . V_68 = V_736 . V_238 . V_68 / V_738 ;
V_733 -> V_651 [ V_8 ] . V_7 = V_31 ;
F_254 ( & V_733 -> V_651 [ V_8 ] ,
V_736 . V_238 . V_67 / V_738 ,
V_736 . V_238 . V_68 / V_738 ,
V_31 , 0 ) ;
V_733 -> V_650 [ V_8 ] . V_238 . V_67 = 0 ;
V_733 -> V_650 [ V_8 ] . V_238 . V_68 = 0 ;
V_733 -> V_652 [ V_8 ] . V_238 . V_67 = 0 ;
V_733 -> V_652 [ V_8 ] . V_238 . V_68 = 0 ;
}
V_736 = V_733 -> V_651 [ V_8 ] ;
}
V_417:
F_6 ( V_53 , L_128 ,
V_52 ) ;
return V_52 ;
}
static void F_245 ( struct V_640 * V_733 )
{
F_6 ( V_53 , L_129 ) ;
F_127 ( V_733 -> V_649 ) ;
V_733 -> V_649 = NULL ;
F_127 ( V_733 -> V_651 ) ;
V_733 -> V_651 = NULL ;
F_127 ( V_733 -> V_650 ) ;
V_733 -> V_650 = NULL ;
F_127 ( V_733 -> V_652 ) ;
V_733 -> V_652 = NULL ;
F_127 ( V_733 -> V_646 ) ;
V_733 -> V_646 = NULL ;
F_6 ( V_53 , L_130 ) ;
}
static enum V_1
F_277 ( struct V_2 * V_3 )
{
enum V_1 V_52 = V_44 ;
bool V_631 = false ;
struct V_236 * V_702 [ V_729 ] ;
struct V_432 * V_635 ;
struct V_50 * V_746 ;
struct V_640 V_641 = V_642 ;
unsigned int V_8 , V_391 ;
bool V_747 = false ;
F_57 ( L_24 ) ;
assert ( V_3 != NULL ) ;
assert ( V_3 -> V_10 != NULL ) ;
assert ( V_3 -> V_59 == V_414 ) ;
if ( V_3 -> V_192 . V_433 . V_484 . V_181 )
goto V_417;
V_52 = F_237 ( & V_3 -> V_10 -> V_11 , false , false ) ;
if ( V_52 != V_44 )
goto V_417;
V_635 = & V_3 -> V_192 . V_433 ;
for ( V_8 = 0 ; V_8 < V_729 ; V_8 ++ ) {
if ( V_3 -> V_636 [ V_8 ] . V_238 . V_67 != 0 ) {
V_52 = F_238 ( & V_3 -> V_6 [ V_8 ] ,
& V_3 -> V_636 [ V_8 ] ) ;
if ( V_52 != V_44 )
goto V_417;
}
V_702 [ V_8 ] = NULL ;
}
V_631 = F_274 ( V_3 ) ;
if ( V_631 ) {
struct V_647 V_648 ;
V_52 = F_276 ( V_3 ,
& V_641 ) ;
if ( V_52 != V_44 )
goto V_417;
V_635 -> V_748 = V_641 . V_740 ;
V_635 -> V_644 = V_641 . V_645 ;
V_635 -> V_505 = F_242 ( V_641 . V_645 *
sizeof( struct V_50 ) , V_399 ) ;
if ( V_635 -> V_505 == NULL ) {
V_52 = V_444 ;
goto V_417;
}
V_635 -> V_646 = F_242 ( V_641 . V_645 *
sizeof( bool ) , V_399 ) ;
if ( V_635 -> V_646 == NULL ) {
V_52 = V_444 ;
goto V_417;
}
for ( V_8 = 0 ; V_8 < V_641 . V_645 ; V_8 ++ ) {
V_635 -> V_646 [ V_8 ] = V_641 . V_646 [ V_8 ] ;
F_243 ( V_3 ,
& V_648 , & V_641 . V_649 [ V_8 ] ,
& V_641 . V_650 [ V_8 ] ,
& V_641 . V_651 [ V_8 ] ,
& V_641 . V_652 [ V_8 ] ) ;
V_52 = F_244 ( & V_648 ,
& V_635 -> V_505 [ V_8 ] ) ;
if ( V_52 != V_44 )
goto V_417;
}
F_245 ( & V_641 ) ;
} else {
V_635 -> V_748 = 1 ;
}
if ( V_631 ) {
V_746 = & V_635 -> V_505 [ 0 ] ;
} else {
V_746 = NULL ;
}
#if F_11 ( F_18 )
V_747 =
( V_3 -> V_10 -> V_11 . V_12 . V_7 == V_19 ) ;
#else
V_747 = true ;
#endif
if ( V_747 ) {
V_52 = F_248 ( V_3 ,
& V_635 -> V_484 ,
V_746 ) ;
if ( V_52 != V_44 )
goto V_417;
V_3 -> V_192 . V_436 . V_484 . V_60 = V_3 -> V_10 -> V_11 . V_60 ;
}
if ( V_631 ) {
for ( V_8 = 0 , V_391 = 0 ; V_8 < V_635 -> V_644 ; V_8 ++ ) {
if ( V_635 -> V_646 [ V_8 ] ) {
assert ( V_391 < 2 ) ;
V_702 [ V_391 ] =
& V_635 -> V_505 [ V_8 ] . V_511 ;
V_391 ++ ;
}
}
V_635 -> V_749 = V_391 ;
} else {
V_702 [ 0 ] =
& V_635 -> V_484 . V_511 ;
for ( V_8 = 1 ; V_8 < V_729 ; V_8 ++ ) {
V_702 [ V_8 ] = NULL ;
}
V_635 -> V_749 = 1 ;
}
V_635 -> V_485 = F_242 ( V_635 -> V_749 * sizeof( struct V_50 ) ,
V_399 ) ;
if ( V_635 -> V_485 == NULL ) {
V_52 = V_444 ;
goto V_417;
}
{
struct V_647 V_660 ;
for ( V_8 = 0 ; V_8 < V_635 -> V_749 ; V_8 ++ ) {
if ( V_3 -> V_636 [ V_8 ] . V_238 . V_67 != 0 ) {
F_249 ( V_3 ,
& V_660 , V_702 [ V_8 ] , & V_3 -> V_636 [ V_8 ] ) ;
V_52 = F_244 ( & V_660 , & V_635 -> V_485 [ V_8 ] ) ;
if ( V_52 != V_44 )
goto V_417;
}
}
}
if ( V_52 != V_44 )
goto V_417;
V_417:
if ( V_631 ) {
F_245 ( & V_641 ) ;
}
F_6 ( V_53 , L_131 ,
V_52 ) ;
return V_52 ;
}
static enum V_1
F_278 ( struct V_2 * V_3 )
{
unsigned int V_8 ;
F_57 ( L_49 , V_3 ) ;
if ( ( V_3 == NULL ) || ( V_3 -> V_59 != V_414 ) ) {
F_130 ( V_43 ) ;
return V_43 ;
}
F_175 ( & V_3 -> V_192 . V_433 . V_484 ) ;
for ( V_8 = 0 ; V_8 < V_3 -> V_192 . V_433 . V_644 ; V_8 ++ ) {
F_175 ( & V_3 -> V_192 . V_433 . V_505 [ V_8 ] ) ;
}
for ( V_8 = 0 ; V_8 < V_3 -> V_192 . V_433 . V_749 ; V_8 ++ ) {
F_175 ( & V_3 -> V_192 . V_433 . V_485 [ V_8 ] ) ;
}
F_127 ( V_3 -> V_192 . V_433 . V_646 ) ;
V_3 -> V_192 . V_433 . V_646 = NULL ;
F_127 ( V_3 -> V_192 . V_433 . V_505 ) ;
V_3 -> V_192 . V_433 . V_505 = NULL ;
F_127 ( V_3 -> V_192 . V_433 . V_485 ) ;
V_3 -> V_192 . V_433 . V_485 = NULL ;
F_130 ( V_44 ) ;
return V_44 ;
}
static enum V_1 F_279 ( struct V_2 * V_3 )
{
struct V_50 * V_484 ;
enum V_1 V_52 = V_44 ;
enum V_260 V_261 ;
enum V_262 V_750 ;
F_57 ( L_49 , V_3 ) ;
if ( ( V_3 == NULL ) || ( V_3 -> V_59 != V_414 ) ) {
F_130 ( V_43 ) ;
return V_43 ;
}
V_750 = V_3 -> V_10 -> V_11 . V_59 ;
V_484 = & V_3 -> V_192 . V_433 . V_484 ;
F_215 () ;
#if ! F_11 ( V_239 ) && ( F_11 ( F_60 ) || F_11 ( F_18 ) )
V_52 = F_216 ( V_3 ) ;
if ( V_52 != V_44 ) {
F_130 ( V_52 ) ;
return V_52 ;
}
#endif
{
unsigned int V_515 ;
F_26 ( F_27 ( V_3 ) , & V_515 ) ;
V_261 = 1 << V_515 ;
}
F_56 ( V_3 , V_261 , V_750 ) ;
F_130 ( V_52 ) ;
return V_52 ;
}
static enum V_1
F_280 ( struct V_2 * V_3 )
{
enum V_1 V_52 = V_44 ;
F_57 ( L_49 , V_3 ) ;
if ( V_3 == NULL ) {
F_130 ( V_43 ) ;
return V_43 ;
}
if ( V_3 -> V_11 . V_59 == V_62 ) {
F_130 ( V_44 ) ;
return V_44 ;
}
switch ( V_3 -> V_59 ) {
case V_209 :
V_52 = F_177 ( V_3 ) ;
break;
case V_210 :
V_52 = F_281 ( V_3 ) ;
break;
case V_408 :
V_52 = F_273 ( V_3 ) ;
break;
case V_414 :
V_52 = F_278 ( V_3 ) ;
break;
default:
break;
}
F_130 ( V_52 ) ;
return V_52 ;
}
static enum V_1
F_282 ( struct V_2 * V_3 )
{
enum V_1 V_52 = V_44 ;
assert ( V_3 != NULL ) ;
F_6 ( V_53 , L_132 ) ;
if ( V_3 -> V_11 . V_59 == V_62 )
return V_52 ;
switch ( V_3 -> V_59 ) {
case V_209 :
V_52 = F_283 ( V_3 ) ;
break;
case V_210 :
V_52 = F_236 ( V_3 ) ;
break;
case V_408 :
V_52 = F_271 ( V_3 ) ;
break;
case V_414 :
V_52 = F_277 ( V_3 ) ;
break;
case V_409 :
break;
default:
V_52 = V_197 ;
break;
}
if ( V_52 != V_44 ) {
if ( F_280 ( V_3 ) != V_44 ) {
V_52 = V_197 ;
}
}
return V_52 ;
}
static enum V_1
F_139 ( struct V_2 * V_3 )
{
struct V_445 * V_259 ;
enum V_1 V_52 = V_44 ;
struct V_446 * V_500 = NULL ,
* V_556 = NULL ,
* V_751 = NULL ;
struct V_50 * V_484 ,
* V_485 ,
* V_505 ;
bool V_631 = false ;
unsigned int V_645 , V_752 , V_740 ;
unsigned int V_8 , V_391 ;
struct V_245 * V_253 = NULL ;
struct V_245 * V_246 [ V_729 ] ;
struct V_245 * V_753 [ V_254 ] ;
struct V_245 * V_490 [ V_729 ] ;
struct V_494 V_495 ;
bool V_558 = false ;
#ifdef F_18
bool V_559 = false ;
bool V_560 = false ;
bool V_60 = false ;
bool V_61 = false ;
#endif
F_57 ( L_49 , V_3 ) ;
if ( ( V_3 == NULL ) || ( V_3 -> V_10 == NULL ) || ( V_3 -> V_59 != V_414 ) ) {
F_130 ( V_43 ) ;
return V_43 ;
}
V_259 = & V_3 -> V_54 ;
F_210 ( V_259 ) ;
for ( V_8 = 0 ; V_8 < V_729 ; V_8 ++ ) {
V_246 [ V_8 ] = NULL ;
V_490 [ V_8 ] = NULL ;
}
F_184 ( V_753 ) ;
V_645 = V_3 -> V_192 . V_433 . V_644 ;
V_752 = V_3 -> V_192 . V_433 . V_749 ;
V_740 = V_3 -> V_192 . V_433 . V_748 ;
#ifdef F_18
V_559 = V_3 -> V_10 -> V_11 . V_59 == V_111 ;
V_560 = V_3 -> V_10 -> V_11 . V_59 == V_101 ;
V_60 = V_3 -> V_10 -> V_11 . V_60 ;
V_61 = V_3 -> V_10 -> V_11 . V_61 ;
V_558 =
! ( ( V_559 && ( V_60 || V_61 ) ) || ( V_560 && V_61 ) ) ;
#else
V_558 = V_3 -> V_10 -> V_11 . V_59 == V_416 ;
#endif
if ( V_558 ) {
int V_754 ;
if ( V_3 -> V_10 -> V_11 . V_12 . V_7 == V_13 ) {
V_754 = V_728 ;
} else if ( V_3 -> V_10 -> V_11 . V_12 . V_7 == V_19 ) {
V_754 = V_39 ;
} else {
V_754 = V_643 ;
}
V_52 = F_203 ( V_3 ,
& V_259 -> V_253 ,
V_754 ) ;
if ( V_52 != V_44 ) {
F_130 ( V_52 ) ;
return V_52 ;
}
V_253 = & V_259 -> V_253 ;
} else {
V_253 = NULL ;
}
for ( V_8 = 0 ; V_8 < V_740 ; V_8 ++ ) {
assert ( V_8 < V_729 ) ;
if ( V_3 -> V_6 [ V_8 ] . V_238 . V_67 != 0 ) {
V_52 = F_206 ( V_3 , & V_259 -> V_246 [ V_8 ] , V_8 ) ;
if ( V_52 != V_44 ) {
F_130 ( V_52 ) ;
return V_52 ;
}
V_246 [ V_8 ] = & V_259 -> V_246 [ V_8 ] ;
}
if ( V_3 -> V_636 [ V_8 ] . V_238 . V_67 != 0 ) {
V_52 = F_196 ( V_3 , & V_259 -> V_490 [ V_8 ] , V_8 ) ;
if ( V_52 != V_44 ) {
F_130 ( V_52 ) ;
return V_52 ;
}
V_490 [ V_8 ] = & V_259 -> V_490 [ V_8 ] ;
}
}
V_484 = & V_3 -> V_192 . V_433 . V_484 ;
V_485 = V_3 -> V_192 . V_433 . V_485 ;
V_505 = V_3 -> V_192 . V_433 . V_505 ;
V_631 = F_274 ( V_3 ) ;
if ( V_3 -> V_192 . V_433 . V_484 . V_181 ) {
struct V_245 * V_755 = NULL ;
#ifdef F_18
if ( ! V_60 )
V_755 = V_253 ;
#endif
if ( V_631 ) {
F_185 ( V_753 , 0 , NULL ) ;
F_186 ( & V_495 , V_484 ,
V_753 , V_755 , NULL ) ;
} else {
F_185 ( V_753 , 0 , V_246 [ 0 ] ) ;
F_186 ( & V_495 , V_484 ,
V_753 , V_755 , NULL ) ;
}
V_52 = F_182 ( V_259 ,
& V_495 ,
& V_556 ) ;
if ( V_52 != V_44 ) {
F_130 ( V_52 ) ;
return V_52 ;
}
if ( V_556 ) {
V_556 -> args . V_256 = ! V_631 ;
V_556 -> args . V_257 = true ;
V_253 = V_556 -> args . V_246 [ 0 ] ;
}
}
if ( V_631 ) {
struct V_245 * V_756 = NULL ;
struct V_245 * V_757 = NULL ;
struct V_245 * V_758 = V_253 ;
for ( V_8 = 0 , V_391 = 0 ; V_8 < V_645 ; V_8 ++ ) {
assert ( V_391 < V_740 ) ;
if ( V_3 -> V_192 . V_433 . V_646 [ V_8 ] == true ) {
V_756 = V_246 [ V_391 ] ;
V_757 = V_490 [ V_391 ] ;
} else {
V_756 = NULL ;
V_757 = NULL ;
}
V_52 = F_187 ( V_3 , V_259 , V_758 , V_756 ,
NULL ,
& V_505 [ V_8 ] ,
& V_751 ) ;
if ( V_52 != V_44 ) {
F_130 ( V_52 ) ;
return V_52 ;
}
V_758 = V_751 -> args . V_246 [ 1 ] ;
if ( V_3 -> V_192 . V_433 . V_646 [ V_8 ] == true ) {
if ( V_757 && ( V_757 -> V_181 . V_238 . V_67 != 0 ) ) {
V_253 = V_751 -> args . V_255 ;
V_52 = F_183 ( V_3 , V_253 , V_757 , & V_485 [ V_391 ] ,
& V_500 ) ;
if ( V_52 != V_44 ) {
F_130 ( V_52 ) ;
return V_52 ;
}
}
V_391 ++ ;
}
}
} else if ( V_556 != NULL ) {
if ( V_490 [ 0 ] != NULL && V_490 [ 0 ] -> V_181 . V_238 . V_67 != 0 ) {
V_253 = V_556 -> args . V_255 ;
V_52 = F_183 ( V_3 , V_253 , V_490 [ 0 ] , & V_485 [ 0 ] ,
& V_500 ) ;
}
if ( V_52 != V_44 ) {
F_130 ( V_52 ) ;
return V_52 ;
}
}
F_209 ( & V_3 -> V_54 , V_3 -> V_10 -> V_11 . V_61 ) ;
F_130 ( V_44 ) ;
return V_44 ;
}
static enum V_1
F_141 ( struct V_2 * V_3 ,
unsigned V_415 ,
struct V_245 * V_246 )
{
struct V_445 * V_259 ;
enum V_1 V_52 = V_44 ;
struct V_494 V_495 ;
F_6 ( V_53 ,
L_133 ) ;
V_259 = & V_3 -> V_54 ;
F_210 ( V_259 ) ;
V_246 -> V_518 = false ;
V_246 -> V_519 = V_520 ;
if ( F_270 ( V_3 ) &&
V_3 -> V_10 -> V_11 . V_12 . V_7 == V_41 ) {
F_254 (
& V_246 -> V_181 ,
V_721 ,
1 ,
V_42 ,
0 ) ;
} else if ( V_246 -> V_181 . V_7 == V_39 ) {
V_246 -> V_181 . V_548 =
F_204 ( V_3 ) ;
}
V_259 -> V_745 = 1 ;
V_259 -> V_208 = V_435 ;
V_3 -> V_59 = V_435 ;
F_284 ( & V_495 , V_246 ,
V_759 , V_415 ) ;
V_52 = F_182 ( V_259 ,
& V_495 ,
NULL ) ;
F_209 ( & V_3 -> V_54 , V_3 -> V_10 -> V_11 . V_61 ) ;
F_6 ( V_53 ,
L_134 ) ;
return V_52 ;
}
static enum V_1
F_285 ( struct V_2 * V_3 )
{
struct V_445 * V_259 = & V_3 -> V_54 ;
enum V_1 V_52 = V_44 ;
struct V_494 V_495 ;
struct V_245 * V_246 = & V_259 -> V_246 [ 0 ] ;
struct V_446 * V_760 = NULL ;
unsigned int V_515 ;
enum V_516 V_517 ;
unsigned int V_415 = V_761 * V_762 ;
F_6 ( V_53 ,
L_135 ) ;
F_210 ( V_259 ) ;
V_52 = F_207 ( V_3 , & V_246 -> V_181 , 0 ) ;
if ( V_52 != V_44 )
return V_52 ;
V_246 -> V_518 = false ;
V_246 -> V_519 = V_520 ;
F_26 ( F_27 ( V_3 ) , & V_515 ) ;
F_198 ( V_550 , V_515 , & V_517 ) ;
V_246 -> V_522 = V_517 ;
V_246 -> V_523 = V_550 ;
V_259 -> V_745 = 1 ;
V_259 -> V_208 = V_408 ;
V_3 -> V_59 = V_408 ;
F_284 ( & V_495 , V_246 ,
V_763 , V_415 ) ;
V_52 = F_182 ( V_259 ,
& V_495 , & V_760 ) ;
if( V_52 != V_44 )
return V_52 ;
F_209 ( V_259 , V_3 -> V_10 -> V_11 . V_61 ) ;
F_6 ( V_53 ,
L_136 ) ;
return V_52 ;
}
static enum V_1
F_286 ( struct V_2 * V_3 )
{
struct V_445 * V_259 ;
enum V_1 V_52 = V_44 ;
enum V_764 V_59 ;
struct V_446 * V_765 = NULL ;
struct V_446 * V_751 = NULL ;
struct V_50 * V_484 ,
* V_535 [ V_723 ] ,
* V_485 ,
* V_705 ,
* V_710 ,
* V_708 ,
* V_505 ,
* V_509 ,
* V_724 ;
bool V_703 = false ;
bool V_766 ;
struct V_245 * V_253 ;
struct V_245 * V_246 ;
struct V_245 * V_501 [ V_254 ] ;
struct V_245 * V_490 ;
struct V_494 V_495 ;
bool V_558 = false ;
#ifdef F_18
bool V_559 = false ;
bool V_560 = false ;
bool V_60 = false ;
bool V_61 = false ;
#endif
unsigned int V_8 , V_644 , V_534 ;
bool V_767 = false ;
bool * V_646 = NULL ;
bool V_768 = false ;
F_57 ( L_24 ) ;
assert ( V_3 != NULL ) ;
assert ( V_3 -> V_10 != NULL ) ;
assert ( V_3 -> V_59 == V_408 || V_3 -> V_59 == V_435 ) ;
V_259 = & V_3 -> V_54 ;
V_59 = V_3 -> V_11 . V_671 . V_59 ;
V_766 = ( V_59 == V_674 ) ;
F_210 ( V_259 ) ;
F_184 ( V_501 ) ;
#ifdef F_18
V_559 = ( V_3 -> V_10 -> V_11 . V_59 == V_111 ) ;
V_560 = ( V_3 -> V_10 -> V_11 . V_59 == V_101 ) ;
V_60 = V_3 -> V_10 -> V_11 . V_60 ;
V_61 = V_3 -> V_10 -> V_11 . V_61 ;
V_558 =
! ( ( V_559 && ( V_60 || V_61 ) ) || ( V_560 && ( V_60 || V_61 ) ) ) ;
#else
V_558 = V_3 -> V_10 -> V_11 . V_59 == V_416 ;
#endif
if ( V_558 ) {
V_52 = F_203 ( V_3 , & V_259 -> V_253 , V_39 ) ;
if ( V_52 != V_44 ) {
F_130 ( V_52 ) ;
return V_52 ;
}
V_253 = & V_259 -> V_253 ;
} else {
V_253 = NULL ;
}
V_52 = F_206 ( V_3 , & V_259 -> V_246 [ 0 ] , 0 ) ;
if ( V_52 != V_44 ) {
F_130 ( V_52 ) ;
return V_52 ;
}
V_246 = & V_259 -> V_246 [ 0 ] ;
if ( V_3 -> V_637 [ V_638 ] ) {
if ( V_59 == V_674 || V_59 == V_675 ) {
V_490 = NULL ;
} else {
F_196 ( V_3 , & V_259 -> V_490 [ 0 ] , 0 ) ;
V_490 = & V_259 -> V_490 [ 0 ] ;
}
} else {
V_490 = NULL ;
}
V_484 = & V_3 -> V_192 . V_436 . V_484 ;
V_534 = V_3 -> V_192 . V_436 . V_534 ;
if ( ( V_534 == 0 ) && ( V_59 == V_722 ) ) {
F_130 ( V_197 ) ;
return V_197 ;
}
for ( V_8 = 0 ; V_8 < V_534 ; V_8 ++ ) {
V_535 [ V_8 ] = & V_3 -> V_192 . V_436 . V_535 [ V_8 ] ;
}
V_485 = & V_3 -> V_192 . V_436 . V_485 ;
V_705 = & V_3 -> V_192 . V_436 . V_705 ;
V_710 = & V_3 -> V_192 . V_436 . V_710 ;
V_708 = & V_3 -> V_192 . V_436 . V_708 ;
V_509 = & V_3 -> V_192 . V_436 . V_509 ;
V_505 = V_3 -> V_192 . V_436 . V_505 ;
V_644 = V_3 -> V_192 . V_436 . V_644 ;
V_646 = V_3 -> V_192 . V_436 . V_646 ;
V_724 = & V_3 -> V_192 . V_436 . V_724 ;
V_703 = ( F_256 ( V_3 ) || V_3 -> V_507 ) &&
V_59 != V_674 &&
V_59 != V_675 ;
V_767 = ( V_505 != NULL && V_505 -> V_181 != NULL ) ;
V_768 = ( V_724 != NULL && V_724 -> V_181 != NULL ) ;
if ( V_3 -> V_192 . V_436 . V_484 . V_181 ) {
if ( V_766 ) {
F_185 ( V_501 , 0 , V_246 ) ;
#if ! F_11 ( V_239 ) && F_11 ( F_18 )
if ( ! V_61 ) {
F_186 ( & V_495 , V_484 ,
V_501 , V_253 , NULL ) ;
} else {
V_253 = V_3 -> V_10 -> V_49 -> V_420 [ 0 ] ;
F_186 ( & V_495 , V_484 ,
V_501 , V_253 , NULL ) ;
}
#else
F_186 ( & V_495 , V_484 ,
V_501 , NULL , NULL ) ;
#endif
} else {
F_185 ( V_501 , 0 , V_253 ) ;
F_186 ( & V_495 , V_484 ,
V_501 , NULL , NULL ) ;
}
V_52 = F_182 ( V_259 ,
& V_495 ,
& V_765 ) ;
if ( V_52 != V_44 ) {
F_130 ( V_52 ) ;
return V_52 ;
}
} else if ( V_3 -> V_10 -> V_11 . V_61 ) {
V_253 = V_3 -> V_10 -> V_49 -> V_420 [ 0 ] ;
}
if ( V_59 == V_722 ) {
unsigned int V_769 ;
struct V_245 * V_770 = NULL ;
struct V_245 * V_771 = NULL ;
for ( V_8 = 0 ; V_8 < V_534 ; V_8 ++ ) {
if ( V_8 == 0 )
V_770 = V_253 ;
else
V_770 = NULL ;
#ifndef F_55
if ( ! V_703 && ( V_8 == V_534 - 1 ) )
#else
if ( ! V_703 && ( V_8 == V_534 - 1 ) && ! V_768 )
#endif
V_771 = V_246 ;
else
V_771 = NULL ;
F_185 ( V_501 , 0 , V_771 ) ;
F_186 ( & V_495 , V_535 [ V_8 ] ,
V_501 , V_770 , NULL ) ;
V_52 = F_182 ( V_259 ,
& V_495 ,
& V_765 ) ;
if ( V_52 != V_44 ) {
F_130 ( V_52 ) ;
return V_52 ;
}
}
( void ) V_769 ;
V_765 -> args . V_256 =
V_535 [ 0 ] -> V_181 -> V_182 . V_54 . V_59 ==
V_561 ;
V_765 -> args . V_257 = V_765 -> args . V_256 ;
} else if ( V_59 == V_719 ||
V_59 == V_720 ) {
F_185 ( V_501 , 0 , NULL ) ;
F_186 ( & V_495 , V_705 ,
V_501 , V_253 , NULL ) ;
V_52 = F_182 ( V_259 ,
& V_495 , NULL ) ;
if ( V_52 != V_44 ) {
F_130 ( V_52 ) ;
return V_52 ;
}
F_185 ( V_501 , 0 , NULL ) ;
F_186 ( & V_495 , V_710 ,
V_501 , NULL , NULL ) ;
V_52 = F_182 ( V_259 ,
& V_495 , NULL ) ;
if ( V_52 != V_44 ) {
F_130 ( V_52 ) ;
return V_52 ;
}
if( V_703 ) {
F_185 ( V_501 , 0 , NULL ) ;
F_186 ( & V_495 , V_708 ,
V_501 , NULL , NULL ) ;
} else {
F_185 ( V_501 , 0 , V_246 ) ;
F_186 ( & V_495 , V_708 ,
V_501 , NULL , NULL ) ;
}
V_52 = F_182 ( V_259 ,
& V_495 , & V_765 ) ;
if ( V_52 != V_44 ) {
F_130 ( V_52 ) ;
return V_52 ;
}
} else if ( V_59 == V_675 ) {
F_185 ( V_501 , 0 , V_246 ) ;
F_186 ( & V_495 , V_705 ,
V_501 , V_253 , NULL ) ;
V_52 = F_182 ( V_259 ,
& V_495 ,
NULL ) ;
if ( V_52 != V_44 ) {
F_130 ( V_52 ) ;
return V_52 ;
}
}
#ifndef F_55
if ( V_703 && V_765 ) {
struct V_245 * V_770 = NULL ;
V_770 = V_765 -> args . V_246 [ 0 ] ;
if( V_768 ) {
F_185 ( V_501 , 0 , NULL ) ;
F_186 ( & V_495 , V_724 ,
V_501 , V_770 , NULL ) ;
V_52 = F_182 ( V_259 ,
& V_495 ,
& V_765 ) ;
V_770 = V_765 -> args . V_246 [ 0 ] ;
}
V_52 = F_188 (pipe, me, local_in_frame, need_yuv_pp ? NULL : out_frame,
#else
if (need_ldc && current_stage) {
in_frame = current_stage->args.out_frame[0];
ia_css_pipe_util_set_output_frames(out_frames, 0, out_frame);
ia_css_pipe_get_generic_stage_desc(&stage_desc, capture_ldc_binary,
out_frames, in_frame, NULL);
err = ia_css_pipeline_create_and_add_stage(me,
&stage_desc,
NULL);
} else if (need_pp && current_stage) {
in_frame = current_stage->args.out_frame[0];
err = add_capture_pp_stage(pipe, me, in_frame, need_yuv_pp ? NULL : out_frame,
#endif
capture_pp_binary,
&current_stage);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
}
if (need_yuv_pp && current_stage) {
struct ia_css_frame *tmp_in_frame = current_stage->args.out_frame[0];
struct ia_css_frame *tmp_out_frame = NULL;
for (i = 0; i < num_yuv_scaler; i++) {
if (is_output_stage[i] == true)
tmp_out_frame = out_frame;
else
tmp_out_frame = NULL;
err = add_yuv_scaler_stage(pipe, me, tmp_in_frame, tmp_out_frame,
NULL,
&yuv_scaler_binary[i],
&yuv_scaler_stage);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
tmp_in_frame = yuv_scaler_stage->args.out_frame[1];
}
}
if (mode != IA_CSS_CAPTURE_MODE_RAW && mode != IA_CSS_CAPTURE_MODE_BAYER && current_stage && vf_frame) {
in_frame = current_stage->args.out_vf_frame;
err = add_vf_pp_stage(pipe, in_frame, vf_frame, vf_pp_binary,
&current_stage);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
}
ia_css_pipeline_finalize_stages(&pipe->pipeline, pipe->stream->config.continuous);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE,
L_137);
return IA_CSS_SUCCESS;
}
static enum ia_css_err
create_host_capture_pipeline(struct ia_css_pipe *pipe)
{
enum ia_css_err err = IA_CSS_SUCCESS;
IA_CSS_ENTER_PRIVATE(L_49, pipe);
if (pipe->config.mode == IA_CSS_PIPE_MODE_COPY)
err = create_host_isyscopy_capture_pipeline(pipe);
else
err = create_host_regular_capture_pipeline(pipe);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
static enum ia_css_err capture_start(
struct ia_css_pipe *pipe)
{
struct ia_css_pipeline *me;
enum ia_css_err err = IA_CSS_SUCCESS;
enum sh_css_pipe_config_override copy_ovrd;
IA_CSS_ENTER_PRIVATE(L_49, pipe);
if (pipe == NULL) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
me = &pipe->pipeline;
if ((pipe->config.default_capture_config.mode == IA_CSS_CAPTURE_MODE_RAW ||
pipe->config.default_capture_config.mode == IA_CSS_CAPTURE_MODE_BAYER ) &&
(pipe->config.mode != IA_CSS_PIPE_MODE_COPY)) {
if (copy_on_sp(pipe)) {
err = start_copy_on_sp(pipe, &me->out_frame[0]);
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
}
#if F_11 ( F_60 )
err = send_mipi_frames(pipe);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
#elif F_11 ( F_18 )
if (pipe->config.mode != IA_CSS_PIPE_MODE_COPY) {
err = send_mipi_frames(pipe);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
}
#endif
{
unsigned int thread_id;
ia_css_pipeline_get_sp_thread_id(ia_css_pipe_get_pipe_num(pipe), &thread_id);
copy_ovrd = 1 << thread_id;
}
start_pipe(pipe, copy_ovrd, pipe->stream->config.mode);
#if ! F_11 ( V_239 ) && ! F_11 ( F_18 )
if (pipe->config.mode == IA_CSS_PIPE_MODE_COPY && pipe->stream->reconfigure_css_rx) {
ia_css_isys_rx_configure(&pipe->stream->csi_rx_config, pipe->stream->config.mode);
pipe->stream->reconfigure_css_rx = false;
}
#endif
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
static enum ia_css_err
sh_css_pipe_get_output_frame_info(struct ia_css_pipe *pipe,
struct ia_css_frame_info *info,
unsigned int idx)
{
enum ia_css_err err = IA_CSS_SUCCESS;
assert(pipe != NULL);
assert(info != NULL);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE,
L_138);
*info = pipe->output_info[idx];
if (copy_on_sp(pipe) &&
pipe->stream->config.input_config.format == IA_CSS_STREAM_FORMAT_BINARY_8) {
ia_css_frame_info_init(
info,
JPEG_BYTES,
1,
IA_CSS_FRAME_FORMAT_BINARY_8,
0);
} else if (info->format == IA_CSS_FRAME_FORMAT_RAW ||
info->format == IA_CSS_FRAME_FORMAT_RAW_PACKED) {
info->raw_bit_depth =
ia_css_pipe_util_pipe_input_format_bpp(pipe);
}
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE,
L_139);
return err;
}
#if ! F_11 ( V_239 )
void
ia_css_stream_send_input_frame(const struct ia_css_stream *stream,
const unsigned short *data,
unsigned int width,
unsigned int height)
{
assert(stream != NULL);
ia_css_inputfifo_send_input_frame(
data, width, height,
stream->config.channel_id,
stream->config.input_config.format,
stream->config.pixels_per_clock == 2);
}
void
ia_css_stream_start_input_frame(const struct ia_css_stream *stream)
{
assert(stream != NULL);
ia_css_inputfifo_start_frame(
stream->config.channel_id,
stream->config.input_config.format,
stream->config.pixels_per_clock == 2);
}
void
ia_css_stream_send_input_line(const struct ia_css_stream *stream,
const unsigned short *data,
unsigned int width,
const unsigned short *data2,
unsigned int width2)
{
assert(stream != NULL);
ia_css_inputfifo_send_line(stream->config.channel_id,
data, width, data2, width2);
}
void
ia_css_stream_send_input_embedded_line(const struct ia_css_stream *stream,
enum ia_css_stream_format format,
const unsigned short *data,
unsigned int width)
{
assert(stream != NULL);
if (data == NULL || width == 0)
return;
ia_css_inputfifo_send_embedded_line(stream->config.channel_id,
format, data, width);
}
void
ia_css_stream_end_input_frame(const struct ia_css_stream *stream)
{
assert(stream != NULL);
ia_css_inputfifo_end_frame(stream->config.channel_id);
}
#endif
static void
append_firmware(struct ia_css_fw_info **l, struct ia_css_fw_info *firmware)
{
IA_CSS_ENTER_PRIVATE(L_140, l , firmware);
if (l == NULL) {
IA_CSS_ERROR(L_141);
IA_CSS_LEAVE_PRIVATE(L_24);
return;
}
while (*l)
l = &(*l)->next;
*l = firmware;
IA_CSS_LEAVE_PRIVATE(L_24);
}
static void
remove_firmware(struct ia_css_fw_info **l, struct ia_css_fw_info *firmware)
{
assert(*l);
assert(firmware);
(void)l;
(void)firmware;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, L_142);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, L_143);
return;
}
#if ! F_11 ( V_286 )
static enum ia_css_err
upload_isp_code(struct ia_css_fw_info *firmware)
{
hrt_vaddress binary;
if (firmware == NULL) {
IA_CSS_ERROR(L_144);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
binary = firmware->info.isp.xmem_addr;
if (!binary) {
unsigned size = firmware->blob.size;
const unsigned char *blob;
const unsigned char *binary_name;
binary_name =
(const unsigned char *)(IA_CSS_EXT_ISP_PROG_NAME(
firmware));
blob = binary_name +
strlen((const char *)binary_name) +
1;
binary = sh_css_load_blob(blob, size);
firmware->info.isp.xmem_addr = binary;
}
if (!binary)
return IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
return IA_CSS_SUCCESS;
}
#endif
static enum ia_css_err
acc_load_extension(struct ia_css_fw_info *firmware)
{
#if ! F_11 ( V_286 )
enum ia_css_err err;
struct ia_css_fw_info *hd = firmware;
while (hd){
err = upload_isp_code(hd);
if (err != IA_CSS_SUCCESS)
return err;
hd = hd->next;
}
#endif
if (firmware == NULL)
return IA_CSS_ERR_INVALID_ARGUMENTS;
firmware->loaded = true;
return IA_CSS_SUCCESS;
}
static void
acc_unload_extension(struct ia_css_fw_info *firmware)
{
struct ia_css_fw_info *hd = firmware;
struct ia_css_fw_info *hdn = NULL;
if (firmware == NULL)
return;
while (hd){
hdn = (hd->next) ? &(*hd->next) : NULL;
if (hd->info.isp.xmem_addr) {
hmm_free(hd->info.isp.xmem_addr);
hd->info.isp.xmem_addr = mmgr_NULL;
}
hd->isp_code = NULL;
hd->next = NULL;
hd = hdn;
}
firmware->loaded = false;
}
static enum ia_css_err
ia_css_pipe_load_extension(struct ia_css_pipe *pipe,
struct ia_css_fw_info *firmware)
{
enum ia_css_err err = IA_CSS_SUCCESS;
IA_CSS_ENTER_PRIVATE(L_145, firmware, pipe);
if ((firmware == NULL) || (pipe == NULL)) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
if (firmware->info.isp.type == IA_CSS_ACC_OUTPUT) {
if (&pipe->output_stage != NULL)
append_firmware(&pipe->output_stage, firmware);
else {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INTERNAL_ERROR);
return IA_CSS_ERR_INTERNAL_ERROR;
}
}
else if (firmware->info.isp.type == IA_CSS_ACC_VIEWFINDER) {
if (&pipe->vf_stage != NULL)
append_firmware(&pipe->vf_stage, firmware);
else {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INTERNAL_ERROR);
return IA_CSS_ERR_INTERNAL_ERROR;
}
}
err = acc_load_extension(firmware);
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
static void
ia_css_pipe_unload_extension(struct ia_css_pipe *pipe,
struct ia_css_fw_info *firmware)
{
IA_CSS_ENTER_PRIVATE(L_145, firmware, pipe);
if ((firmware == NULL) || (pipe == NULL)) {
IA_CSS_ERROR(L_146);
IA_CSS_LEAVE_PRIVATE(L_24);
return;
}
if (firmware->info.isp.type == IA_CSS_ACC_OUTPUT)
remove_firmware(&pipe->output_stage, firmware);
else if (firmware->info.isp.type == IA_CSS_ACC_VIEWFINDER)
remove_firmware(&pipe->vf_stage, firmware);
acc_unload_extension(firmware);
IA_CSS_LEAVE_PRIVATE(L_24);
}
bool
ia_css_pipeline_uses_params(struct ia_css_pipeline *me)
{
struct ia_css_pipeline_stage *stage;
assert(me != NULL);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
L_147, me);
for (stage = me->stages; stage; stage = stage->next)
if (stage->binary_info && stage->binary_info->enable.params) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
L_148
L_149);
return true;
}
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
L_150);
return false;
}
static enum ia_css_err
sh_css_pipeline_add_acc_stage(struct ia_css_pipeline *pipeline,
const void *acc_fw)
{
struct ia_css_fw_info *fw = (struct ia_css_fw_info *)acc_fw;
enum ia_css_err err = IA_CSS_SUCCESS;
if (fw->loaded == false)
err = acc_load_extension(fw);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
L_151
L_152, pipeline, acc_fw);
if (err == IA_CSS_SUCCESS) {
struct ia_css_pipeline_stage_desc stage_desc;
ia_css_pipe_get_acc_stage_desc(&stage_desc, NULL, fw);
err = ia_css_pipeline_create_and_add_stage(pipeline,
&stage_desc,
NULL);
}
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
L_153,err);
return err;
}
enum ia_css_err ia_css_stream_capture_frame(struct ia_css_stream *stream,
unsigned int exp_id)
{
struct sh_css_tag_descr tag_descr;
uint32_t encoded_tag_descr;
enum ia_css_err err;
assert(stream != NULL);
IA_CSS_ENTER(L_154, exp_id);
if (exp_id == 0 || !stream->config.continuous) {
IA_CSS_LEAVE_ERR(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
if (!sh_css_sp_is_running()) {
IA_CSS_LEAVE_ERR(IA_CSS_ERR_RESOURCE_NOT_AVAILABLE);
return IA_CSS_ERR_RESOURCE_NOT_AVAILABLE;
}
sh_css_create_tag_descr(0, 0, 0, exp_id, &tag_descr);
encoded_tag_descr = sh_css_encode_tag_descr(&tag_descr);
err= ia_css_bufq_enqueue_tag_cmd(encoded_tag_descr);
IA_CSS_LEAVE_ERR(err);
return err;
}
enum ia_css_err ia_css_stream_capture(
struct ia_css_stream *stream,
int num_captures,
unsigned int skip,
int offset)
{
struct sh_css_tag_descr tag_descr;
unsigned int encoded_tag_descr;
enum ia_css_err return_err;
if (stream == NULL)
return IA_CSS_ERR_INVALID_ARGUMENTS;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
L_155
L_156, num_captures, skip,offset);
if (num_captures < SH_CSS_MINIMUM_TAG_ID) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
L_157,
IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
sh_css_create_tag_descr(num_captures, skip, offset, 0, &tag_descr);
encoded_tag_descr = sh_css_encode_tag_descr(&tag_descr);
if (!sh_css_sp_is_running()) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
L_158
L_159);
return IA_CSS_ERR_RESOURCE_NOT_AVAILABLE;
}
return_err = ia_css_bufq_enqueue_tag_cmd((uint32_t)encoded_tag_descr);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
L_157,
return_err);
return return_err;
}
void ia_css_stream_request_flash(struct ia_css_stream *stream)
{
(void)stream;
assert(stream != NULL);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, L_160);
#ifndef F_55
sh_css_write_host2sp_command(host2sp_cmd_start_flash);
#else
if (sh_css_sp_is_running()) {
if (!sh_css_write_host2sp_command(host2sp_cmd_start_flash)) {
IA_CSS_ERROR(L_161);
ia_css_debug_dump_sp_sw_debug_info();
ia_css_debug_dump_debug_info(NULL);
}
} else
IA_CSS_LOG(L_76);
#endif
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
L_162);
}
static void
sh_css_init_host_sp_control_vars(void)
{
const struct ia_css_fw_info *fw;
unsigned int HIVE_ADDR_ia_css_ispctrl_sp_isp_started;
unsigned int HIVE_ADDR_host_sp_queues_initialized;
unsigned int HIVE_ADDR_sp_sleep_mode;
unsigned int HIVE_ADDR_ia_css_dmaproxy_sp_invalidate_tlb;
#ifndef F_55
unsigned int HIVE_ADDR_sp_stop_copy_preview;
#endif
unsigned int HIVE_ADDR_host_sp_com;
unsigned int o = offsetof(struct host_sp_communication, host2sp_command)
/ sizeof(int);
#if F_11 ( F_60 ) || F_11 ( F_18 )
unsigned int i;
#endif
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE,
L_163);
fw = &sh_css_sp_fw;
HIVE_ADDR_ia_css_ispctrl_sp_isp_started = fw->info.sp.isp_started;
HIVE_ADDR_host_sp_queues_initialized =
fw->info.sp.host_sp_queues_initialized;
HIVE_ADDR_sp_sleep_mode = fw->info.sp.sleep_mode;
HIVE_ADDR_ia_css_dmaproxy_sp_invalidate_tlb = fw->info.sp.invalidate_tlb;
#ifndef F_55
HIVE_ADDR_sp_stop_copy_preview = fw->info.sp.stop_copy_preview;
#endif
HIVE_ADDR_host_sp_com = fw->info.sp.host_sp_com;
(void)HIVE_ADDR_ia_css_ispctrl_sp_isp_started;
(void)HIVE_ADDR_sp_sleep_mode;
(void)HIVE_ADDR_ia_css_dmaproxy_sp_invalidate_tlb;
#ifndef F_55
(void)HIVE_ADDR_sp_stop_copy_preview;
#endif
(void)HIVE_ADDR_host_sp_com;
sp_dmem_store_uint32(SP0_ID,
(unsigned int)sp_address_of(ia_css_ispctrl_sp_isp_started),
(uint32_t)(0));
sp_dmem_store_uint32(SP0_ID,
(unsigned int)sp_address_of(host_sp_queues_initialized),
(uint32_t)(0));
sp_dmem_store_uint32(SP0_ID,
(unsigned int)sp_address_of(sp_sleep_mode),
(uint32_t)(0));
sp_dmem_store_uint32(SP0_ID,
(unsigned int)sp_address_of(ia_css_dmaproxy_sp_invalidate_tlb),
(uint32_t)(false));
#ifndef F_55
sp_dmem_store_uint32(SP0_ID,
(unsigned int)sp_address_of(sp_stop_copy_preview),
my_css.stop_copy_preview?(uint32_t)(1):(uint32_t)(0));
#endif
store_sp_array_uint(host_sp_com, o, host2sp_cmd_ready);
#if ! F_11 ( V_239 )
for (i = 0; i < N_CSI_PORTS; i++) {
sh_css_update_host2sp_num_mipi_frames
(my_css.num_mipi_frames[i]);
}
#endif
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE,
L_164);
}
void ia_css_pipe_config_defaults(struct ia_css_pipe_config *pipe_config)
{
struct ia_css_pipe_config def_config = DEFAULT_PIPE_CONFIG;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, L_165);
*pipe_config = def_config;
}
void
ia_css_pipe_extra_config_defaults(struct ia_css_pipe_extra_config *extra_config)
{
if (extra_config == NULL) {
IA_CSS_ERROR(L_144);
return;
}
extra_config->enable_raw_binning = false;
extra_config->enable_yuv_ds = false;
extra_config->enable_high_speed = false;
extra_config->enable_dvs_6axis = false;
extra_config->enable_reduced_pipe = false;
extra_config->disable_vf_pp = false;
extra_config->enable_fractional_ds = false;
}
void ia_css_stream_config_defaults(struct ia_css_stream_config *stream_config)
{
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, L_166);
assert(stream_config != NULL);
memset(stream_config, 0, sizeof(*stream_config));
stream_config->online = true;
stream_config->left_padding = -1;
stream_config->pixels_per_clock = 1;
stream_config->source.port.rxcount = 0x04040404;
}
static enum ia_css_err
ia_css_acc_pipe_create(struct ia_css_pipe *pipe)
{
enum ia_css_err err = IA_CSS_SUCCESS;
if (pipe == NULL) {
IA_CSS_ERROR(L_144);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
if (pipe->config.acc_num_execs == 0)
pipe->config.acc_num_execs = 1;
if (pipe->config.acc_extension) {
err = ia_css_pipe_load_extension(pipe, pipe->config.acc_extension);
}
return err;
}
enum ia_css_err
ia_css_pipe_create(const struct ia_css_pipe_config *config,
struct ia_css_pipe **pipe)
{
#ifndef F_55
if (config == NULL)
#else
enum ia_css_err err = IA_CSS_SUCCESS;
IA_CSS_ENTER_PRIVATE(L_167, config, pipe);
if (config == NULL) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
#endif
return IA_CSS_ERR_INVALID_ARGUMENTS;
#ifndef F_55
if (pipe == NULL)
#else
}
if (pipe == NULL) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
#endif
return IA_CSS_ERR_INVALID_ARGUMENTS;
#ifndef F_55
return ia_css_pipe_create_extra(config, NULL, pipe);
#else
}
err = ia_css_pipe_create_extra(config, NULL, pipe);
if(err == IA_CSS_SUCCESS) {
IA_CSS_LOG(L_168, *pipe);
}
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
#endif
}
enum ia_css_err
ia_css_pipe_create_extra(const struct ia_css_pipe_config *config,
const struct ia_css_pipe_extra_config *extra_config,
struct ia_css_pipe **pipe)
{
enum ia_css_err err = IA_CSS_ERR_INTERNAL_ERROR;
struct ia_css_pipe *internal_pipe = NULL;
unsigned int i;
IA_CSS_ENTER_PRIVATE(L_169, config, extra_config, pipe);
if (my_css.pipe_counter >= IA_CSS_PIPELINE_NUM_MAX) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_RESOURCE_EXHAUSTED);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
if ((pipe == NULL) || (config == NULL)) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
ia_css_debug_dump_pipe_config(config);
ia_css_debug_dump_pipe_extra_config(extra_config);
err = create_pipe(config->mode, &internal_pipe, false);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
internal_pipe->config = *config;
if (extra_config)
internal_pipe->extra_config = *extra_config;
else
ia_css_pipe_extra_config_defaults(&internal_pipe->extra_config);
if (config->mode == IA_CSS_PIPE_MODE_ACC) {
*pipe = internal_pipe;
if (!internal_pipe->config.acc_extension &&
internal_pipe->config.num_acc_stages == 0){
*pipe = NULL;
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_SUCCESS);
return IA_CSS_SUCCESS;
}
return ia_css_acc_pipe_create(internal_pipe);
}
if (internal_pipe->config.dvs_frame_delay == IA_CSS_FRAME_DELAY_2)
internal_pipe->dvs_frame_delay = 2;
else
internal_pipe->dvs_frame_delay = 1;
if (internal_pipe->extra_config.enable_raw_binning &&
internal_pipe->config.bayer_ds_out_res.width) {
}
if ((internal_pipe->config.vf_pp_in_res.width ||
internal_pipe->config.capt_pp_in_res.width)) {
enum ia_css_frame_format format;
if (internal_pipe->config.vf_pp_in_res.width) {
format = IA_CSS_FRAME_FORMAT_YUV_LINE;
ia_css_frame_info_init(
&internal_pipe->vf_yuv_ds_input_info,
internal_pipe->config.vf_pp_in_res.width,
internal_pipe->config.vf_pp_in_res.height,
format, 0);
}
if (internal_pipe->config.capt_pp_in_res.width) {
format = IA_CSS_FRAME_FORMAT_YUV420;
ia_css_frame_info_init(
&internal_pipe->out_yuv_ds_input_info,
internal_pipe->config.capt_pp_in_res.width,
internal_pipe->config.capt_pp_in_res.height,
format, 0);
}
}
if (internal_pipe->config.vf_pp_in_res.width &&
internal_pipe->config.mode == IA_CSS_PIPE_MODE_PREVIEW) {
ia_css_frame_info_init(
&internal_pipe->vf_yuv_ds_input_info,
internal_pipe->config.vf_pp_in_res.width,
internal_pipe->config.vf_pp_in_res.height,
IA_CSS_FRAME_FORMAT_YUV_LINE, 0);
}
if (internal_pipe->config.bayer_ds_out_res.width) {
ia_css_frame_info_init(
&internal_pipe->bds_output_info,
internal_pipe->config.bayer_ds_out_res.width,
internal_pipe->config.bayer_ds_out_res.height,
IA_CSS_FRAME_FORMAT_RAW, 0);
}
for (i = 0; i < IA_CSS_PIPE_MAX_OUTPUT_STAGE; i++) {
if (internal_pipe->config.output_info[i].res.width) {
err = sh_css_pipe_configure_output(
internal_pipe,
internal_pipe->config.output_info[i].res.width,
internal_pipe->config.output_info[i].res.height,
internal_pipe->config.output_info[i].padded_width,
internal_pipe->config.output_info[i].format,
i);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
sh_css_free(internal_pipe);
internal_pipe = NULL;
return err;
}
}
internal_pipe->enable_viewfinder[i] = (internal_pipe->config.vf_output_info[i].res.width != 0);
if (internal_pipe->config.vf_output_info[i].res.width) {
err = sh_css_pipe_configure_viewfinder(
internal_pipe,
internal_pipe->config.vf_output_info[i].res.width,
internal_pipe->config.vf_output_info[i].res.height,
internal_pipe->config.vf_output_info[i].padded_width,
internal_pipe->config.vf_output_info[i].format,
i);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
sh_css_free(internal_pipe);
internal_pipe = NULL;
return err;
}
}
}
if (internal_pipe->config.acc_extension) {
err = ia_css_pipe_load_extension(internal_pipe,
internal_pipe->config.acc_extension);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
sh_css_free(internal_pipe);
return err;
}
}
memset(&internal_pipe->info, 0, sizeof(internal_pipe->info));
*pipe = internal_pipe;
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_SUCCESS);
return IA_CSS_SUCCESS;
}
enum ia_css_err
ia_css_pipe_get_info(const struct ia_css_pipe *pipe,
struct ia_css_pipe_info *pipe_info)
{
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
L_170);
assert(pipe_info != NULL);
if (pipe_info == NULL) {
ia_css_debug_dtrace(IA_CSS_DEBUG_ERROR,
L_171);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
if (pipe == NULL || pipe->stream == NULL) {
ia_css_debug_dtrace(IA_CSS_DEBUG_ERROR,
L_172
L_173);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
*pipe_info = pipe->info;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, L_174);
return IA_CSS_SUCCESS;
}
bool ia_css_pipe_has_dvs_stats(struct ia_css_pipe_info *pipe_info)
{
unsigned int i;
if (pipe_info != NULL) {
for (i = 0; i < IA_CSS_DVS_STAT_NUM_OF_LEVELS; i++) {
if (pipe_info->grid_info.dvs_grid.dvs_stat_grid_info.grd_cfg[i].grd_start.enable)
return true;
}
}
return false;
}
#ifdef F_55
enum ia_css_err
ia_css_pipe_override_frame_format(struct ia_css_pipe *pipe,
int pin_index,
enum ia_css_frame_format new_format)
{
enum ia_css_err err = IA_CSS_SUCCESS;
IA_CSS_ENTER_PRIVATE(L_175, pipe, pin_index, new_format);
if (NULL == pipe) {
IA_CSS_ERROR(L_176);
err = IA_CSS_ERR_INVALID_ARGUMENTS;
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
if (0 != pin_index && 1 != pin_index) {
IA_CSS_ERROR(L_177);
err = IA_CSS_ERR_INVALID_ARGUMENTS;
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
if (IA_CSS_FRAME_FORMAT_NV12_TILEY != new_format) {
IA_CSS_ERROR(L_178);
err = IA_CSS_ERR_INVALID_ARGUMENTS;
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
} else {
err = ia_css_pipe_check_format(pipe, new_format);
if (IA_CSS_SUCCESS == err) {
if (pin_index == 0) {
pipe->output_info[0].format = new_format;
} else {
pipe->vf_output_info[0].format = new_format;
}
}
}
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
#endif
#if F_11 ( F_60 )
static enum ia_css_err
ia_css_stream_configure_rx(struct ia_css_stream *stream)
{
struct ia_css_input_port *config;
assert(stream != NULL);
config = &stream->config.source.port;
if (config->num_lanes == 1)
stream->csi_rx_config.mode = MONO_1L_1L_0L;
else if (config->num_lanes == 2)
stream->csi_rx_config.mode = MONO_2L_1L_0L;
else if (config->num_lanes == 3)
stream->csi_rx_config.mode = MONO_3L_1L_0L;
else if (config->num_lanes == 4)
stream->csi_rx_config.mode = MONO_4L_1L_0L;
else if (config->num_lanes != 0)
return IA_CSS_ERR_INVALID_ARGUMENTS;
if (config->port > IA_CSS_CSI2_PORT2)
return IA_CSS_ERR_INVALID_ARGUMENTS;
stream->csi_rx_config.port =
ia_css_isys_port_to_mipi_port(config->port);
stream->csi_rx_config.timeout = config->timeout;
stream->csi_rx_config.initcount = 0;
stream->csi_rx_config.synccount = 0x28282828;
stream->csi_rx_config.rxcount = config->rxcount;
if (config->compression.type == IA_CSS_CSI2_COMPRESSION_TYPE_NONE)
stream->csi_rx_config.comp = MIPI_PREDICTOR_NONE;
else {
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
stream->csi_rx_config.is_two_ppc = (stream->config.pixels_per_clock == 2);
stream->reconfigure_css_rx = true;
return IA_CSS_SUCCESS;
}
#endif
static struct ia_css_pipe *
find_pipe(struct ia_css_pipe *pipes[],
unsigned int num_pipes,
enum ia_css_pipe_mode mode,
bool copy_pipe)
{
unsigned i;
assert(pipes != NULL);
for (i = 0; i < num_pipes; i++) {
assert(pipes[i] != NULL);
if (pipes[i]->config.mode != mode)
continue;
if (copy_pipe && pipes[i]->mode != IA_CSS_PIPE_ID_COPY)
continue;
return pipes[i];
}
return NULL;
}
static enum ia_css_err
ia_css_acc_stream_create(struct ia_css_stream *stream)
{
int i;
enum ia_css_err err = IA_CSS_SUCCESS;
assert(stream != NULL);
IA_CSS_ENTER_PRIVATE(L_43, stream);
if (stream == NULL) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
for (i = 0; i < stream->num_pipes; i++) {
struct ia_css_pipe *pipe = stream->pipes[i];
assert(pipe != NULL);
if (pipe == NULL) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
pipe->stream = stream;
}
err = map_sp_threads(stream, true);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
for (i = 0; i < stream->num_pipes; i++) {
struct ia_css_pipe *pipe = stream->pipes[i];
assert(pipe != NULL);
ia_css_pipe_map_queue(pipe, true);
}
err = create_host_pipeline_structure(stream);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
stream->started = false;
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_SUCCESS);
return IA_CSS_SUCCESS;
}
static enum ia_css_err
metadata_info_init(const struct ia_css_metadata_config *mdc,
struct ia_css_metadata_info *md)
{
if ((mdc->resolution.height > 0) ^ (mdc->resolution.width > 0))
return IA_CSS_ERR_INVALID_ARGUMENTS;
md->resolution = mdc->resolution;
md->stride = CEIL_MUL(mdc->resolution.width, HIVE_ISP_DDR_WORD_BYTES);
md->size = mdc->resolution.height * md->stride;
return IA_CSS_SUCCESS;
}
#ifdef F_55
static enum ia_css_err check_pipe_resolutions(const struct ia_css_pipe *pipe)
{
enum ia_css_err err = IA_CSS_SUCCESS;
IA_CSS_ENTER_PRIVATE(L_24);
if (!pipe || !pipe->stream) {
IA_CSS_ERROR(L_179);
err = IA_CSS_ERR_INTERNAL_ERROR;
goto EXIT;
}
if (ia_css_util_check_res(pipe->config.input_effective_res.width,
pipe->config.input_effective_res.height) != IA_CSS_SUCCESS) {
IA_CSS_ERROR(L_180);
err = IA_CSS_ERR_INVALID_ARGUMENTS;
goto EXIT;
}
if (!ia_css_util_resolution_is_zero(pipe->stream->config.input_config.input_res)) {
if (!ia_css_util_res_leq(pipe->config.input_effective_res,
pipe->stream->config.input_config.input_res)) {
IA_CSS_ERROR(L_181);
err = IA_CSS_ERR_INVALID_ARGUMENTS;
goto EXIT;
}
}
if (!ia_css_util_resolution_is_even(pipe->config.output_info[0].res)) {
IA_CSS_ERROR(L_182);
err = IA_CSS_ERR_INVALID_ARGUMENTS;
goto EXIT;
}
if (!ia_css_util_resolution_is_even(pipe->config.vf_output_info[0].res)) {
IA_CSS_ERROR(L_183);
err = IA_CSS_ERR_INVALID_ARGUMENTS;
goto EXIT;
}
EXIT:
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
#endif
enum ia_css_err
ia_css_stream_create(const struct ia_css_stream_config *stream_config,
int num_pipes,
struct ia_css_pipe *pipes[],
struct ia_css_stream **stream)
{
struct ia_css_pipe *curr_pipe;
struct ia_css_stream *curr_stream = NULL;
bool spcopyonly;
bool sensor_binning_changed;
int i, j;
enum ia_css_err err = IA_CSS_ERR_INTERNAL_ERROR;
struct ia_css_metadata_info md_info;
#ifndef F_55
struct ia_css_resolution effective_res;
#else
#ifdef F_18
bool aspect_ratio_crop_enabled = false;
#endif
#endif
IA_CSS_ENTER(L_184, num_pipes);
ia_css_debug_dump_stream_config(stream_config, num_pipes);
if (num_pipes == 0 ||
stream == NULL ||
pipes == NULL) {
err = IA_CSS_ERR_INVALID_ARGUMENTS;
IA_CSS_LEAVE_ERR(err);
return err;
}
#if F_11 ( F_60 )
if (stream_config->input_config.format == IA_CSS_STREAM_FORMAT_BINARY_8 &&
stream_config->metadata_config.resolution.height > 0) {
err = IA_CSS_ERR_INVALID_ARGUMENTS;
IA_CSS_LEAVE_ERR(err);
return err;
}
#endif
#ifdef F_18
if (stream_config->online && stream_config->pack_raw_pixels) {
IA_CSS_LOG(L_185);
err = IA_CSS_ERR_INVALID_ARGUMENTS;
IA_CSS_LEAVE_ERR(err);
return err;
}
#endif
#if ! F_11 ( V_239 )
ia_css_debug_pipe_graph_dump_stream_config(stream_config);
if (stream_config->mode == IA_CSS_INPUT_MODE_BUFFERED_SENSOR)
#ifdef F_18
if (!stream_config->online)
#endif
{
unsigned int port = (unsigned int) stream_config->source.port.port;
if (port >= N_MIPI_PORT_ID) {
err = IA_CSS_ERR_INVALID_ARGUMENTS;
IA_CSS_LEAVE_ERR(err);
return err;
}
if (my_css.size_mem_words != 0){
my_css.mipi_frame_size[port] = my_css.size_mem_words;
} else if (stream_config->mipi_buffer_config.size_mem_words != 0) {
my_css.mipi_frame_size[port] = stream_config->mipi_buffer_config.size_mem_words;
} else {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
L_186);
assert(stream_config->mipi_buffer_config.size_mem_words != 0);
err = IA_CSS_ERR_INTERNAL_ERROR;
IA_CSS_LEAVE_ERR(err);
return err;
}
if (my_css.size_mem_words != 0) {
my_css.num_mipi_frames[port] = 2;
} else if (stream_config->mipi_buffer_config.nof_mipi_buffers != 0) {
my_css.num_mipi_frames[port] = stream_config->mipi_buffer_config.nof_mipi_buffers;
} else {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
L_187);
assert(stream_config->mipi_buffer_config.nof_mipi_buffers != 0);
err = IA_CSS_ERR_INTERNAL_ERROR;
IA_CSS_LEAVE_ERR(err);
return err;
}
}
#endif
err = metadata_info_init(&stream_config->metadata_config, &md_info);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR(err);
return err;
}
curr_stream = kmalloc(sizeof(struct ia_css_stream), GFP_KERNEL);
if (curr_stream == NULL) {
err = IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
IA_CSS_LEAVE_ERR(err);
return err;
}
memset(curr_stream, 0, sizeof(struct ia_css_stream));
curr_stream->info.metadata_info = md_info;
curr_stream->num_pipes = num_pipes;
curr_stream->pipes = kzalloc(num_pipes * sizeof(struct ia_css_pipe *), GFP_KERNEL);
if (curr_stream->pipes == NULL) {
curr_stream->num_pipes = 0;
kfree(curr_stream);
curr_stream = NULL;
err = IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
IA_CSS_LEAVE_ERR(err);
return err;
}
spcopyonly = (num_pipes == 1) && (pipes[0]->config.mode == IA_CSS_PIPE_MODE_COPY);
for (i = 0; i < num_pipes; i++)
curr_stream->pipes [i] = pipes[i];
curr_stream->last_pipe = curr_stream->pipes[0];
curr_stream->config = *stream_config;
#if F_11 ( F_18 ) && F_11 ( V_772 )
if (stream_config->mode == IA_CSS_INPUT_MODE_BUFFERED_SENSOR &&
stream_config->online)
curr_stream->config.online = false;
#endif
#ifdef F_18
if (curr_stream->config.online) {
curr_stream->config.source.port.num_lanes = stream_config->source.port.num_lanes;
curr_stream->config.mode = IA_CSS_INPUT_MODE_BUFFERED_SENSOR;
}
#endif
if (curr_stream->config.target_num_cont_raw_buf == 0)
curr_stream->config.target_num_cont_raw_buf = NUM_CONTINUOUS_FRAMES;
if (curr_stream->config.init_num_cont_raw_buf == 0)
curr_stream->config.init_num_cont_raw_buf = curr_stream->config.target_num_cont_raw_buf;
if (curr_stream->config.ia_css_enable_raw_buffer_locking)
sh_css_sp_configure_enable_raw_pool_locking(
curr_stream->config.lock_all);
switch (curr_stream->config.mode) {
case IA_CSS_INPUT_MODE_SENSOR:
case IA_CSS_INPUT_MODE_BUFFERED_SENSOR:
#if F_11 ( F_60 )
ia_css_stream_configure_rx(curr_stream);
#endif
break;
case IA_CSS_INPUT_MODE_TPG:
#if ! F_11 ( V_239 ) && F_11 ( F_60 )
IA_CSS_LOG(L_188,
curr_stream->config.source.tpg.x_mask,
curr_stream->config.source.tpg.y_mask,
curr_stream->config.source.tpg.x_delta,
curr_stream->config.source.tpg.y_delta,
curr_stream->config.source.tpg.xy_mask);
sh_css_sp_configure_tpg(
curr_stream->config.source.tpg.x_mask,
curr_stream->config.source.tpg.y_mask,
curr_stream->config.source.tpg.x_delta,
curr_stream->config.source.tpg.y_delta,
curr_stream->config.source.tpg.xy_mask);
#endif
break;
case IA_CSS_INPUT_MODE_PRBS:
#if ! F_11 ( V_239 ) && F_11 ( F_60 )
IA_CSS_LOG(L_189);
sh_css_sp_configure_prbs(curr_stream->config.source.prbs.seed);
#endif
break;
case IA_CSS_INPUT_MODE_MEMORY:
IA_CSS_LOG(L_190);
curr_stream->reconfigure_css_rx = false;
break;
default:
IA_CSS_LOG(L_191);
}
#ifdef F_55
#ifdef F_18
err = aspect_ratio_crop_init(curr_stream,
pipes,
&aspect_ratio_crop_enabled);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR(err);
return err;
}
#endif
#endif
for (i = 0; i < num_pipes; i++) {
#ifdef F_55
struct ia_css_resolution effective_res;
#endif
curr_pipe = pipes[i];
curr_pipe->stream = curr_stream;
effective_res = curr_pipe->config.input_effective_res;
if (effective_res.height == 0 || effective_res.width == 0) {
effective_res = curr_pipe->stream->config.input_config.effective_res;
#ifdef F_55
#if F_11 ( F_18 )
if (aspect_ratio_crop_check(aspect_ratio_crop_enabled, curr_pipe)) {
struct ia_css_resolution crop_res;
err = aspect_ratio_crop(curr_pipe, &crop_res);
if (err == IA_CSS_SUCCESS) {
effective_res = crop_res;
} else {
IA_CSS_LOG(L_192, err);
}
}
#endif
#endif
curr_pipe->config.input_effective_res = effective_res;
}
IA_CSS_LOG(L_193,
effective_res.width,
effective_res.height);
}
#ifdef F_55
for (i = 0; i < num_pipes; i++) {
if (pipes[i]->config.mode != IA_CSS_PIPE_MODE_ACC &&
pipes[i]->config.mode != IA_CSS_PIPE_MODE_COPY) {
err = check_pipe_resolutions(pipes[i]);
if (err != IA_CSS_SUCCESS) {
goto ERR;
}
}
}
#endif
err = ia_css_stream_isp_parameters_init(curr_stream);
if (err != IA_CSS_SUCCESS)
goto ERR;
IA_CSS_LOG(L_194, curr_stream->isp_params_configs);
if (num_pipes == 1 && pipes[0]->config.mode == IA_CSS_PIPE_MODE_ACC) {
*stream = curr_stream;
err = ia_css_acc_stream_create(curr_stream);
goto ERR;
}
if (!spcopyonly){
sensor_binning_changed =
sh_css_params_set_binning_factor(curr_stream, curr_stream->config.sensor_binning_factor);
} else {
sensor_binning_changed = false;
}
IA_CSS_LOG(L_195,
curr_stream->config.sensor_binning_factor, sensor_binning_changed);
IA_CSS_LOG(L_184, num_pipes);
curr_stream->cont_capt = false;
if (curr_stream->config.continuous) {
struct ia_css_pipe *preview_pipe;
struct ia_css_pipe *video_pipe;
struct ia_css_pipe *acc_pipe;
struct ia_css_pipe *capture_pipe = NULL;
struct ia_css_pipe *copy_pipe = NULL;
if (num_pipes >= 2) {
curr_stream->cont_capt = true;
curr_stream->disable_cont_vf = curr_stream->config.disable_cont_viewfinder;
#ifndef F_55
curr_stream->stop_copy_preview = my_css.stop_copy_preview;
#endif
}
preview_pipe = find_pipe(pipes, num_pipes,
IA_CSS_PIPE_MODE_PREVIEW, false);
video_pipe = find_pipe(pipes, num_pipes,
IA_CSS_PIPE_MODE_VIDEO, false);
acc_pipe = find_pipe(pipes, num_pipes,
IA_CSS_PIPE_MODE_ACC, false);
if (acc_pipe && num_pipes == 2 && curr_stream->cont_capt == true)
curr_stream->cont_capt = false;
if (curr_stream->cont_capt == true) {
capture_pipe = find_pipe(pipes, num_pipes,
IA_CSS_PIPE_MODE_CAPTURE, false);
if (capture_pipe == NULL) {
err = IA_CSS_ERR_INTERNAL_ERROR;
goto ERR;
}
}
if (preview_pipe && video_pipe) {
err = IA_CSS_ERR_INVALID_ARGUMENTS;
goto ERR;
}
if (preview_pipe && !preview_pipe->pipe_settings.preview.copy_pipe) {
err = create_pipe(IA_CSS_PIPE_MODE_CAPTURE, &copy_pipe, true);
if (err != IA_CSS_SUCCESS)
goto ERR;
ia_css_pipe_config_defaults(&copy_pipe->config);
preview_pipe->pipe_settings.preview.copy_pipe = copy_pipe;
copy_pipe->stream = curr_stream;
}
if (preview_pipe && (curr_stream->cont_capt == true)) {
preview_pipe->pipe_settings.preview.capture_pipe = capture_pipe;
}
if (video_pipe && !video_pipe->pipe_settings.video.copy_pipe) {
err = create_pipe(IA_CSS_PIPE_MODE_CAPTURE, &copy_pipe, true);
if (err != IA_CSS_SUCCESS)
goto ERR;
ia_css_pipe_config_defaults(&copy_pipe->config);
video_pipe->pipe_settings.video.copy_pipe = copy_pipe;
copy_pipe->stream = curr_stream;
}
if (video_pipe && (curr_stream->cont_capt == true)) {
video_pipe->pipe_settings.video.capture_pipe = capture_pipe;
}
if (preview_pipe && acc_pipe) {
preview_pipe->pipe_settings.preview.acc_pipe = acc_pipe;
}
}
for (i = 0; i < num_pipes; i++) {
curr_pipe = pipes[i];
curr_pipe->stream = curr_stream;
#ifndef F_55
effective_res = curr_pipe->config.input_effective_res;
#endif
#ifndef F_55
err = ia_css_util_check_res(
effective_res.width,
effective_res.height);
if (err != IA_CSS_SUCCESS)
goto ERR;
#endif
if (sensor_binning_changed)
sh_css_pipe_free_shading_table(curr_pipe);
}
for (i = 0; i < num_pipes; i++) {
struct ia_css_pipe_info *pipe_info = NULL;
curr_pipe = pipes[i];
err = sh_css_pipe_load_binaries(curr_pipe);
if (err != IA_CSS_SUCCESS)
goto ERR;
#if F_11 ( V_773 )
err = ia_css_update_cfg_stripe_info(curr_pipe);
if (err != IA_CSS_SUCCESS)
goto ERR;
#endif
pipe_info = &curr_pipe->info;
for (j = 0; j < IA_CSS_PIPE_MAX_OUTPUT_STAGE; j++) {
err = sh_css_pipe_get_output_frame_info(curr_pipe,
&pipe_info->output_info[j], j);
if (err != IA_CSS_SUCCESS)
goto ERR;
}
#ifdef F_55
pipe_info->output_system_in_res_info = curr_pipe->config.output_system_in_res;
#endif
if (!spcopyonly){
err = sh_css_pipe_get_shading_info(curr_pipe,
#ifndef F_55
&pipe_info->shading_info);
#else
&pipe_info->shading_info, &curr_pipe->config) ;
#endif
if ( V_52 != V_44 )
goto V_417;
V_52 = F_229 ( V_774 ,
& V_775 -> V_776 ) ;
if ( V_52 != V_44 )
goto V_417;
for ( V_391 = 0 ; V_391 < V_729 ; V_391 ++ ) {
F_197 ( V_774 ,
& V_775 -> V_636 [ V_391 ] , V_391 ) ;
if ( V_52 != V_44 )
goto V_417;
}
}
V_324 . V_452 [ F_27 ( V_774 ) ] = V_774 ;
}
enum V_1
F_287 ( const struct V_45 * V_10 ,
struct V_777 * V_778 )
{
F_6 ( V_323 , L_196 ) ;
assert ( V_10 != NULL ) ;
assert ( V_778 != NULL ) ;
* V_778 = V_10 -> V_181 ;
return V_44 ;
}
enum V_1
F_114 ( struct V_45 * V_10 )
{
#ifndef F_55
int V_8 ;
enum V_1 V_52 ;
assert ( V_10 != NULL ) ;
F_6 ( V_323 , L_197 ) ;
for( V_8 = 0 ; V_8 < V_369 ; V_8 ++ )
if ( V_362 . V_367 [ V_8 ] . V_10 == V_10 )
{
int V_391 ;
for( V_391 = 0 ; V_391 < V_362 . V_367 [ V_8 ] . V_394 ; V_391 ++ )
if ( ( V_52 = F_288 ( & ( V_362 . V_367 [ V_8 ] . V_604 [ V_391 ] ) , & V_362 . V_367 [ V_8 ] . V_396 [ V_391 ] ) ) != V_44 )
{
if ( V_391 )
{
int V_779 ;
for( V_779 = 0 ; V_779 < V_391 ; V_779 ++ )
F_151 ( V_362 . V_367 [ V_8 ] . V_396 [ V_779 ] ) ;
}
return V_52 ;
}
V_52 = F_289 ( & ( V_362 . V_367 [ V_8 ] . V_780 ) , V_362 . V_367 [ V_8 ] . V_394 ,
V_362 . V_367 [ V_8 ] . V_396 , & ( V_362 . V_367 [ V_8 ] . V_10 ) ) ;
if ( V_52 != V_44 )
{
F_290 ( V_10 ) ;
for( V_391 = 0 ; V_391 < V_362 . V_367 [ V_8 ] . V_394 ; V_391 ++ )
F_151 ( V_362 . V_367 [ V_8 ] . V_396 [ V_391 ] ) ;
return V_52 ;
}
break;
}
F_6 ( V_323 , L_198 ) ;
return V_44 ;
#else
( void ) V_10 ;
return V_781 ;
#endif
}
enum V_1
F_115 ( struct V_45 * V_10 )
{
enum V_1 V_52 = V_44 ;
F_81 ( L_43 , V_10 ) ;
if ( ( V_10 == NULL ) || ( V_10 -> V_49 == NULL ) ) {
F_90 ( V_43 ) ;
return V_43 ;
}
F_91 ( L_199 , V_10 -> V_49 -> V_59 ) ;
F_291 ( V_10 -> V_782 ) ;
V_52 = F_134 ( V_10 ) ;
if ( V_52 != V_44 ) {
F_90 ( V_52 ) ;
return V_52 ;
}
#if ! F_11 ( V_239 )
#if F_11 ( F_18 )
if( ( V_10 -> V_11 . V_59 == V_111 ) ||
( V_10 -> V_11 . V_59 == V_101 ) )
F_35 ( V_10 ) ;
#endif
#endif
#if ! F_11 ( V_239 ) && F_11 ( F_60 )
if ( V_10 -> V_11 . V_59 == V_101 )
{
unsigned int V_514 ;
unsigned int V_102 = ( unsigned int ) ( V_10 -> V_11 . V_87 . V_102 . V_102 ) ;
for ( V_514 = 0 ; V_514 < V_783 ; V_514 ++ ) {
V_199 . V_11 . V_784 [ V_102 ] [ V_514 ] = F_292 ( V_102 , V_514 ) ;
}
}
#endif
#if ! F_11 ( V_239 )
if ( V_10 -> V_11 . V_59 != V_416 ) {
V_52 = F_5 ( V_10 ) ;
if ( V_52 != V_44 )
return V_52 ;
}
#endif
V_52 = F_293 ( V_10 ) ;
F_90 ( V_52 ) ;
return V_52 ;
}
enum V_1
F_116 ( struct V_45 * V_10 )
{
enum V_1 V_52 = V_44 ;
F_6 ( V_323 , L_200 ) ;
assert ( V_10 != NULL ) ;
assert ( V_10 -> V_49 != NULL ) ;
F_6 ( V_323 , L_201 ,
V_10 -> V_49 -> V_59 ) ;
#if ! F_11 ( V_239 ) && F_11 ( F_60 )
if ( V_10 -> V_11 . V_59 == V_101 )
{
unsigned int V_514 ;
unsigned int V_102 = ( unsigned int ) ( V_10 -> V_11 . V_87 . V_102 . V_102 ) ;
for ( V_514 = 0 ; V_514 < V_783 ; V_514 ++ ) {
V_199 . V_11 . V_784 [ V_102 ] [ V_514 ] = 0 ;
}
}
#endif
#ifndef F_55
V_52 = F_294 ( & V_10 -> V_49 -> V_54 ) ;
#else
V_52 = F_295 ( V_10 ) ;
#endif
if ( V_52 != V_44 )
return V_52 ;
return V_52 ;
}
bool
F_296 ( struct V_45 * V_10 )
{
bool V_785 ;
assert ( V_10 != NULL ) ;
#ifndef F_55
V_785 = F_297 ( & V_10 -> V_49 -> V_54 ) ;
#else
V_785 = F_298 ( V_10 ) ;
#endif
return V_785 ;
}
enum V_1
F_109 ( struct V_45 * V_10 )
{
int V_8 ;
assert ( V_10 != NULL ) ;
F_6 ( V_323 , L_202 ) ;
assert ( V_10 != NULL ) ;
for( V_8 = 0 ; V_8 < V_369 ; V_8 ++ )
if ( V_362 . V_367 [ V_8 ] . V_10 == V_10 )
{
int V_391 ;
F_6 ( V_323 , L_203 , V_8 , V_362 . V_367 [ V_8 ] . V_10 ) ;
F_290 ( V_10 ) ;
for( V_391 = 0 ; V_391 < V_362 . V_367 [ V_8 ] . V_394 ; V_391 ++ )
F_151 ( V_362 . V_367 [ V_8 ] . V_396 [ V_391 ] ) ;
F_6 ( V_323 , L_204 , V_8 , V_362 . V_367 [ V_8 ] . V_10 ) ;
break;
}
F_6 ( V_323 , L_205 ) ;
return V_44 ;
}
enum V_1
F_299 ( const struct V_2 * V_3 , enum V_207 * V_208 )
{
F_6 ( V_323 , L_206 ) ;
if ( V_3 != NULL )
* V_208 = V_3 -> V_59 ;
else
* V_208 = V_435 ;
return V_44 ;
}
enum V_72
F_300 ( const struct V_45 * V_10 )
{
return V_10 -> V_11 . V_12 . V_7 ;
}
bool
F_301 ( const struct V_45 * V_10 )
{
return ( V_10 -> V_11 . V_47 == 2 ) ;
}
struct V_50 *
F_302 ( const struct V_45 * V_10 )
{
struct V_2 * V_3 ;
assert ( V_10 != NULL ) ;
V_3 = V_10 -> V_396 [ 0 ] ;
if ( V_10 -> V_394 == 2 ) {
assert ( V_10 -> V_396 [ 1 ] != NULL ) ;
if ( V_10 -> V_396 [ 1 ] -> V_11 . V_59 == V_195 ||
V_10 -> V_396 [ 1 ] -> V_11 . V_59 == V_191 )
V_3 = V_10 -> V_396 [ 1 ] ;
}
return F_227 ( V_3 ) ;
}
struct V_50 *
F_303 ( const struct V_45 * V_10 )
{
int V_8 ;
struct V_2 * V_786 = NULL ;
for ( V_8 = 0 ; V_8 < V_10 -> V_394 ; V_8 ++ ) {
struct V_2 * V_3 = V_10 -> V_396 [ V_8 ] ;
if ( V_3 -> V_11 . V_59 == V_195 ) {
V_786 = V_3 ;
break;
}
}
if ( V_786 )
return & V_786 -> V_192 . V_196 . V_419 ;
return NULL ;
}
struct V_50 *
F_304 ( const struct V_45 * V_10 )
{
struct V_2 * V_3 ;
struct V_50 * V_787 = NULL ;
assert ( V_10 != NULL ) ;
V_3 = V_10 -> V_396 [ 0 ] ;
if ( V_10 -> V_394 == 2 ) {
assert ( V_10 -> V_396 [ 1 ] != NULL ) ;
if ( V_10 -> V_396 [ 1 ] -> V_11 . V_59 == V_195 ||
V_10 -> V_396 [ 1 ] -> V_11 . V_59 == V_191 )
V_3 = V_10 -> V_396 [ 1 ] ;
}
V_787 = F_230 ( V_3 ) ;
return V_787 ;
}
enum V_1
F_305 ( struct V_45 * V_10 , unsigned int V_788 )
{
enum V_1 V_52 = V_44 ;
struct V_2 * V_3 ;
assert ( V_10 != NULL ) ;
V_3 = V_10 -> V_49 ;
assert ( V_3 != NULL ) ;
V_3 -> V_11 . V_6 [ V_638 ] . V_669 = V_788 ;
V_3 -> V_6 [ V_638 ] . V_669 = V_788 ;
return V_52 ;
}
static struct V_50 *
F_227 ( const struct V_2 * V_3 )
{
struct V_50 * V_51 = NULL ;
assert ( V_3 != NULL ) ;
switch ( V_3 -> V_11 . V_59 ) {
case V_191 :
V_51 = (struct V_50 * ) & V_3 -> V_192 . V_193 . V_418 ;
break;
case V_195 :
V_51 = (struct V_50 * ) & V_3 -> V_192 . V_196 . V_419 ;
break;
case V_189 :
if ( V_3 -> V_11 . V_671 . V_59 == V_722 ) {
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < V_3 -> V_192 . V_436 . V_534 ; V_8 ++ ) {
if ( V_3 -> V_192 . V_436 . V_535 [ V_8 ] . V_181 -> V_182 . V_157 . V_789 ) {
V_51 = (struct V_50 * ) & V_3 -> V_192 . V_436 . V_535 [ V_8 ] ;
break;
}
}
}
else if ( V_3 -> V_11 . V_671 . V_59 == V_675 )
V_51 = (struct V_50 * ) & V_3 -> V_192 . V_436 . V_705 ;
else if ( V_3 -> V_11 . V_671 . V_59 == V_719 ||
V_3 -> V_11 . V_671 . V_59 == V_720 ) {
if ( V_3 -> V_11 . V_790 == V_690 )
V_51 = (struct V_50 * ) & V_3 -> V_192 . V_436 . V_705 ;
else if ( V_3 -> V_11 . V_790 == V_689 )
V_51 = (struct V_50 * ) & V_3 -> V_192 . V_436 . V_708 ;
}
break;
default:
break;
}
if ( V_51 && V_51 -> V_181 -> V_182 . V_157 . V_789 )
return V_51 ;
return NULL ;
}
static struct V_50 *
F_230 ( const struct V_2 * V_3 )
{
struct V_50 * V_51 = NULL ;
assert ( V_3 != NULL ) ;
switch ( V_3 -> V_11 . V_59 ) {
case V_191 :
V_51 = (struct V_50 * ) & V_3 -> V_192 . V_193 . V_418 ;
break;
case V_195 :
V_51 = (struct V_50 * ) & V_3 -> V_192 . V_196 . V_419 ;
break;
case V_189 :
if ( V_3 -> V_11 . V_671 . V_59 == V_722 ) {
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < V_3 -> V_192 . V_436 . V_534 ; V_8 ++ ) {
if ( V_3 -> V_192 . V_436 . V_535 [ V_8 ] . V_181 -> V_182 . V_157 . V_588 ) {
V_51 = (struct V_50 * ) & V_3 -> V_192 . V_436 . V_535 [ V_8 ] ;
break;
}
}
}
else if ( V_3 -> V_11 . V_671 . V_59 == V_675 )
V_51 = (struct V_50 * ) & V_3 -> V_192 . V_436 . V_705 ;
else if ( V_3 -> V_11 . V_671 . V_59 == V_719 ||
V_3 -> V_11 . V_671 . V_59 == V_720 ) {
if ( V_3 -> V_11 . V_790 == V_690 )
V_51 = (struct V_50 * ) & V_3 -> V_192 . V_436 . V_705 ;
else if ( V_3 -> V_11 . V_790 == V_689 )
V_51 = (struct V_50 * ) & V_3 -> V_192 . V_436 . V_708 ;
else
assert ( 0 ) ;
}
break;
default:
break;
}
if ( V_51 && ! V_51 -> V_181 -> V_182 . V_157 . V_588 )
V_51 = NULL ;
return V_51 ;
}
static struct V_50 *
F_232 ( const struct V_2 * V_3 )
{
struct V_50 * V_51 = NULL ;
assert ( V_3 != NULL ) ;
switch ( V_3 -> V_11 . V_59 ) {
case V_195 :
V_51 = (struct V_50 * ) & V_3 -> V_192 . V_196 . V_419 ;
break;
default:
break;
}
if ( V_51 && ! V_51 -> V_181 -> V_182 . V_157 . V_591 )
V_51 = NULL ;
return V_51 ;
}
struct V_445 *
F_306 ( const struct V_2 * V_3 )
{
assert ( V_3 != NULL ) ;
return (struct V_445 * ) & V_3 -> V_54 ;
}
unsigned int
F_27 ( const struct V_2 * V_3 )
{
assert ( V_3 != NULL ) ;
assert ( V_3 -> V_407 < V_439 ) ;
if ( V_3 -> V_407 >= V_439 )
return ( V_439 - 1 ) ;
return V_3 -> V_407 ;
}
unsigned int
F_307 ( const struct V_2 * V_3 )
{
assert ( V_3 != NULL ) ;
return ( unsigned int ) V_3 -> V_11 . V_790 ;
}
static enum V_1
F_308 ( void )
{
enum V_1 V_52 = V_44 ;
unsigned long V_791 ;
F_81 ( L_24 ) ;
F_309 () ;
V_791 = V_792 ;
while( ( F_310 () == V_793 ) && V_791 ) {
V_791 -- ;
F_311 () ;
}
F_6 ( V_323 ,
L_207 , F_310 () ) ;
if ( V_791 == 0 ) {
F_6 ( V_794 ,
L_208 ) ;
V_52 = V_197 ;
}
if ( F_310 () != V_795 ) {
F_6 ( V_794 ,
L_209 ) ;
V_52 = V_197 ;
}
F_90 ( V_52 ) ;
return V_52 ;
}
enum V_1
F_113 ( void )
{
unsigned long V_791 ;
enum V_1 V_52 = V_44 ;
F_81 ( L_24 ) ;
#if F_11 ( V_329 )
V_52 = F_308 () ;
if ( V_52 != V_44 ) {
F_158 ( L_210 ) ;
return V_52 ;
}
#endif
F_312 () ;
V_791 = V_796 ;
while( ( F_313 ( V_270 ) != V_797 ) && V_791 ) {
V_791 -- ;
F_311 () ;
}
if ( V_791 == 0 ) {
F_144 ( L_211 ) ;
return V_197 ;
}
F_314 () ;
F_190 () ;
F_315 () ;
#ifdef F_55
if ( F_316 () == false ) {
F_317 ( V_798 ) ;
}
#endif
F_90 ( V_52 ) ;
return V_52 ;
}
enum V_1
F_110 ( void )
{
unsigned long V_791 ;
enum V_1 V_52 = V_44 ;
F_81 ( L_27 ) ;
if ( ! F_118 () ) {
V_52 = V_43 ;
F_158 ( L_212 , V_52 ) ;
return V_52 ;
}
#ifndef F_55
F_318 ( V_799 ) ;
#else
if ( ! F_318 ( V_799 ) ) {
F_144 ( L_161 ) ;
F_319 () ;
F_320 ( NULL ) ;
}
#endif
F_164 ( false ) ;
V_791 = V_800 ;
while ( ! F_321 ( V_270 ) && V_791 ) {
V_791 -- ;
F_311 () ;
}
if ( ( F_313 ( V_270 ) != V_801 ) )
F_322 ( L_213 ) ;
if ( V_791 == 0 ) {
F_322 ( L_214 ) ;
F_319 () ;
}
V_791 = V_800 ;
while ( ! F_323 ( V_802 , V_803 , V_804 ) && V_791 ) {
V_791 -- ;
F_311 () ;
}
if ( V_791 == 0 ) {
F_322 ( L_215 ) ;
F_319 () ;
}
F_324 () ;
#ifndef F_55
F_325 () ;
#else
if ( F_316 () == false ) {
F_325 () ;
F_317 ( V_805 ) ;
}
#endif
F_90 ( V_52 ) ;
return V_52 ;
}
enum V_1
F_326 ( struct V_45 * V_10 )
{
struct V_2 * V_3 ;
unsigned int V_8 ;
F_6 (
V_323 ,
L_216 ) ;
if ( V_10 == NULL ) {
F_6 (
V_323 ,
L_217 ) ;
return V_43 ;
}
V_3 = V_10 -> V_806 ;
for ( V_8 = V_10 -> V_11 . V_563 ;
V_8 < V_10 -> V_11 . V_564 ; V_8 ++ ) {
F_213 ( V_8 ,
V_3 -> V_420 [ V_8 ] , V_3 -> V_449 [ V_8 ] ) ;
}
F_212
( V_10 -> V_11 . V_564 , true ) ;
F_6 (
V_323 ,
L_218 ) ;
return V_44 ;
}
void F_327 ( struct V_2 * V_3 , bool V_403 )
{
unsigned int V_515 ;
enum V_207 V_208 ;
unsigned int V_407 ;
bool V_807 ;
F_81 ( L_24 ) ;
assert ( V_3 != NULL ) ;
V_208 = V_3 -> V_59 ;
V_407 = V_3 -> V_407 ;
F_26 ( V_407 , & V_515 ) ;
#if F_11 ( V_239 ) || F_11 ( F_18 )
V_807 = true ;
#else
V_807 = V_3 -> V_10 -> V_11 . V_59 == V_416 ;
#endif
if ( V_3 -> V_59 == V_209 ) {
if ( V_807 )
F_328 ( V_515 , V_549 , V_403 ) ;
F_328 ( V_515 , V_550 , V_403 ) ;
F_328 ( V_515 , V_808 , V_403 ) ;
F_328 ( V_515 , V_809 , V_403 ) ;
#if F_11 V_810
F_328 ( V_515 , V_592 , V_403 ) ;
#endif
if ( V_3 -> V_192 . V_193 . V_418 . V_181 &&
V_3 -> V_192 . V_193 . V_418 . V_181 -> V_182 . V_157 . V_588 )
F_328 ( V_515 , V_585 , V_403 ) ;
} else if ( V_3 -> V_59 == V_408 ) {
unsigned int V_8 ;
if ( V_807 )
F_328 ( V_515 , V_549 , V_403 ) ;
F_328 ( V_515 , V_550 , V_403 ) ;
F_328 ( V_515 , V_521 , V_403 ) ;
F_328 ( V_515 , V_808 , V_403 ) ;
F_328 ( V_515 , V_809 , V_403 ) ;
#if F_11 V_810
F_328 ( V_515 , V_592 , V_403 ) ;
#endif
if ( V_3 -> V_11 . V_671 . V_59 == V_722 ) {
for ( V_8 = 0 ; V_8 < V_3 -> V_192 . V_436 . V_534 ; V_8 ++ ) {
if ( V_3 -> V_192 . V_436 . V_535 [ V_8 ] . V_181 &&
V_3 -> V_192 . V_436 . V_535 [ V_8 ] . V_181 -> V_182 . V_157 . V_588 ) {
F_328 ( V_515 , V_585 , V_403 ) ;
break;
}
}
} else if ( V_3 -> V_11 . V_671 . V_59 == V_719 ||
V_3 -> V_11 . V_671 . V_59 == V_720 ||
V_3 -> V_11 . V_671 . V_59 == V_675 ) {
if ( V_3 -> V_192 . V_436 . V_705 . V_181 &&
V_3 -> V_192 . V_436 . V_705 . V_181 -> V_182 . V_157 . V_588 )
F_328 ( V_515 , V_585 , V_403 ) ;
}
} else if ( V_3 -> V_59 == V_210 ) {
if ( V_807 )
F_328 ( V_515 , V_549 , V_403 ) ;
F_328 ( V_515 , V_550 , V_403 ) ;
if ( V_3 -> V_637 [ V_638 ] )
F_328 ( V_515 , V_521 , V_403 ) ;
F_328 ( V_515 , V_808 , V_403 ) ;
F_328 ( V_515 , V_809 , V_403 ) ;
#if F_11 V_810
F_328 ( V_515 , V_592 , V_403 ) ;
#endif
if ( V_3 -> V_192 . V_196 . V_419 . V_181 &&
V_3 -> V_192 . V_196 . V_419 . V_181 -> V_182 . V_157 . V_588 )
F_328 ( V_515 , V_585 , V_403 ) ;
if ( V_3 -> V_192 . V_196 . V_419 . V_181 &&
( V_3 -> V_192 . V_196 . V_419 . V_181 -> V_182 . V_157 . V_591
) )
F_328 ( V_515 , V_589 , V_403 ) ;
} else if ( V_3 -> V_59 == V_435 ) {
if ( V_807 )
F_328 ( V_515 , V_549 , V_403 ) ;
if ( ! V_3 -> V_10 -> V_11 . V_61 )
F_328 ( V_515 , V_550 , V_403 ) ;
#if F_11 V_810
F_328 ( V_515 , V_592 , V_403 ) ;
#endif
} else if ( V_3 -> V_59 == V_409 ) {
if ( V_807 )
F_328 ( V_515 , V_549 , V_403 ) ;
F_328 ( V_515 , V_550 , V_403 ) ;
F_328 ( V_515 , V_808 , V_403 ) ;
F_328 ( V_515 , V_809 , V_403 ) ;
#if F_11 V_810
F_328 ( V_515 , V_592 , V_403 ) ;
#endif
} else if ( V_3 -> V_59 == V_414 ) {
unsigned int V_514 ;
for ( V_514 = 0 ; V_514 < V_729 ; V_514 ++ ) {
F_328 ( V_515 , V_550 + V_514 , V_403 ) ;
if ( V_3 -> V_637 [ V_514 ] )
F_328 ( V_515 , V_521 + V_514 , V_403 ) ;
}
if ( V_807 )
F_328 ( V_515 , V_549 , V_403 ) ;
F_328 ( V_515 , V_808 , V_403 ) ;
#if F_11 V_810
F_328 ( V_515 , V_592 , V_403 ) ;
#endif
}
F_158 ( L_24 ) ;
}
static enum V_1 F_220 ( struct V_236 * V_181 , struct V_811 * V_547 )
{
V_547 -> V_812 . V_669 = 0 ;
switch ( V_181 -> V_7 ) {
case V_31 :
case V_643 :
if ( V_181 -> V_669 > V_181 -> V_238 . V_67 )
{
V_547 -> V_812 . V_669 = V_181 -> V_669 ;
}
else if ( ( V_181 -> V_669 < V_181 -> V_238 . V_67 ) && ( V_181 -> V_669 > 0 ) )
{
return V_43 ;
}
break;
default:
break;
}
return V_44 ;
}
enum V_1
F_329 ( struct V_45 * V_10 , V_142 V_813 )
{
enum V_1 V_814 ;
F_81 ( L_24 ) ;
if ( V_10 == NULL || ! V_10 -> V_11 . V_61 ) {
F_144 ( L_219 ) ;
return V_43 ;
}
if ( V_813 > V_815 ||
V_813 < V_816 ) {
F_144 ( L_220 , V_813 ) ;
return V_43 ;
}
V_814 = F_330 (
V_817 , V_813 , 0 , 0 ) ;
F_90 ( V_814 ) ;
return V_814 ;
}
enum V_1
F_331 ( struct V_2 * V_3 , V_142 V_818 , bool V_157 )
{
unsigned int V_515 ;
struct V_446 * V_447 ;
enum V_1 V_52 = V_44 ;
F_81 ( L_24 ) ;
if ( V_3 == NULL || V_3 -> V_10 == NULL ) {
F_144 ( L_221 ) ;
V_52 = V_43 ;
} else if ( ! ( V_3 -> V_11 . V_453 ) ) {
F_144 ( L_222 ) ;
V_52 = V_43 ;
} else if ( ! F_118 () ) {
F_144 ( L_223 ) ;
V_52 = V_397 ;
} else {
F_26 ( F_27 ( V_3 ) , & V_515 ) ;
V_52 = F_332 ( & ( V_3 -> V_54 ) , V_818 , & V_447 ) ;
if ( V_52 == V_44 ) {
V_52 = F_330 (
( T_7 ) V_819 ,
( T_7 ) V_515 ,
( T_7 ) V_447 -> V_820 ,
( V_157 == true ) ? 1 : 0 ) ;
if ( V_52 == V_44 ) {
if( V_157 )
F_333 ( & ( V_199 . V_3 [ V_515 ] ) , V_447 -> V_820 ) ;
else
F_334 ( & ( V_199 . V_3 [ V_515 ] ) , V_447 -> V_820 ) ;
}
}
}
F_158 ( L_224 , V_52 , V_818 , V_157 ) ;
return V_52 ;
}
enum V_1
F_335 ( struct V_2 * V_3 , V_142 V_818 , bool * V_157 )
{
struct V_446 * V_447 ;
unsigned int V_515 ;
enum V_1 V_52 = V_44 ;
F_81 ( L_24 ) ;
if ( V_3 == NULL || V_3 -> V_10 == NULL ) {
F_144 ( L_221 ) ;
V_52 = V_43 ;
} else if ( ! ( V_3 -> V_11 . V_453 ) ) {
F_144 ( L_225 ) ;
V_52 = V_43 ;
} else if ( ! F_118 () ) {
F_144 ( L_223 ) ;
V_52 = V_397 ;
} else {
F_26 ( F_27 ( V_3 ) , & V_515 ) ;
V_52 = F_332 ( & V_3 -> V_54 , V_818 , & V_447 ) ;
if ( V_52 == V_44 ) {
* V_157 = ( F_336 ( & ( V_199 . V_3 [ V_515 ] ) , V_447 -> V_820 ) ) ? true : false ;
}
}
F_158 ( L_224 , V_52 , V_818 , * V_157 ) ;
return V_52 ;
}
enum V_1
F_337 ( struct V_2 * V_3 , V_142 V_818 ,
struct V_821 * V_822 , struct V_823 * V_824 )
{
unsigned int V_825 ;
static struct V_199 V_826 ;
static struct V_827 V_828 ;
static struct V_829 V_830 ;
const struct V_280 * V_281 ;
unsigned int V_515 ;
struct V_446 * V_447 ;
enum V_1 V_52 = V_44 ;
int V_820 = 0 ;
enum V_831 V_832 ;
bool V_833 ;
F_81 ( L_24 ) ;
V_281 = & V_375 ;
if ( V_3 == NULL || V_3 -> V_10 == NULL ) {
F_144 ( L_221 ) ;
V_52 = V_43 ;
} else if ( ! ( V_3 -> V_11 . V_453 ) ) {
F_144 ( L_225 ) ;
V_52 = V_43 ;
} else if ( ! F_118 () ) {
F_144 ( L_223 ) ;
V_52 = V_397 ;
} else {
F_26 ( F_27 ( V_3 ) , & V_515 ) ;
V_52 = F_332 ( & ( V_3 -> V_54 ) , V_818 , & V_447 ) ;
if ( V_52 == V_44 ) {
V_833 = ( F_336 ( & ( V_199 . V_3 [ V_515 ] ) , V_447 -> V_820 ) ) ? true : false ;
if ( V_833 ) {
F_144 ( L_226 ) ;
V_52 = V_397 ;
} else {
V_820 = V_447 -> V_820 ;
V_825 = V_281 -> V_181 . V_182 . V_834 ;
F_338 ( V_270 ,
( unsigned int ) F_195 ( V_826 ) ,
& V_826 , sizeof( struct V_199 ) ) ;
F_339 ( V_826 . V_3 [ V_515 ] . V_835 [ V_820 ] ,
& V_828 , sizeof( struct V_827 ) ) ;
F_339 ( V_828 . V_836 ,
& V_830 , sizeof( struct V_829 ) ) ;
for ( V_832 = 0 ; V_832 < V_837 ; V_832 ++ ) {
V_830 . V_838 . V_839 [ V_840 ] [ V_832 ] . V_841 =
V_822 -> V_839 [ V_840 ] [ V_832 ] . V_841 ;
V_830 . V_838 . V_839 [ V_840 ] [ V_832 ] . V_304 =
V_822 -> V_839 [ V_840 ] [ V_832 ] . V_304 ;
V_830 . V_842 . V_838 . V_839 [ V_840 ] [ V_832 ] . V_841 =
V_824 -> V_839 [ V_840 ] [ V_832 ] . V_841 ;
V_830 . V_842 . V_838 . V_839 [ V_840 ] [ V_832 ] . V_304 =
V_824 -> V_839 [ V_840 ] [ V_832 ] . V_304 ;
}
F_222 ( V_828 . V_836 ,
& V_830 , sizeof( struct V_829 ) ) ;
}
}
}
F_158 ( L_227 , V_52 , V_818 ) ;
return V_52 ;
}
static enum V_1
F_340 ( struct V_45 * V_843 ,
struct V_2 * V_396 [] ,
bool * V_844 )
{
enum V_1 V_52 = V_44 ;
int V_8 ;
struct V_2 * V_774 ;
V_142 V_845 = 0 ;
if ( ( V_843 == NULL ) ||
( V_843 -> V_394 == 0 ) ||
( V_396 == NULL ) ||
( V_844 == NULL ) ) {
V_52 = V_43 ;
F_90 ( V_52 ) ;
return V_52 ;
}
for ( V_8 = 0 ; V_8 < V_843 -> V_394 ; V_8 ++ ) {
V_774 = V_396 [ V_8 ] ;
V_845 |= ( 1 << V_774 -> V_11 . V_59 ) ;
}
* V_844 =
( ( ( V_845 & ( 1 << V_191 ) ) ||
( V_845 & ( 1 << V_195 ) ) ) &&
( V_845 & ( 1 << V_189 ) ) &&
V_843 -> V_11 . V_61 ) ;
return V_44 ;
}
static bool
F_341 ( bool V_833 , struct V_2 * V_774 )
{
bool V_462 = false ;
if ( ( V_774 != NULL ) && V_833 ) {
if ( ( V_774 -> V_11 . V_59 == V_191 ) ||
( V_774 -> V_11 . V_59 == V_195 ) ||
( V_774 -> V_11 . V_59 == V_189 ) )
V_462 = true ;
}
return V_462 ;
}
static enum V_1
F_342 ( struct V_2 * V_774 ,
struct V_532 * V_538 )
{
enum V_1 V_52 = V_44 ;
struct V_532 V_846 ;
struct V_532 * V_725 = NULL ;
struct V_532 * V_726 = NULL ;
bool V_847 = false ;
bool V_848 = false ;
bool V_849 = false ;
if ( ( V_774 == NULL ) ||
( V_538 == NULL ) ) {
V_52 = V_43 ;
F_90 ( V_52 ) ;
return V_52 ;
}
if ( ( V_774 -> V_11 . V_59 != V_191 ) &&
( V_774 -> V_11 . V_59 != V_195 ) &&
( V_774 -> V_11 . V_59 != V_189 ) ) {
V_52 = V_43 ;
F_90 ( V_52 ) ;
return V_52 ;
}
V_847 =
( ( V_774 -> V_850 . V_238 . V_67 != 0 ) &&
( V_774 -> V_850 . V_238 . V_68 != 0 ) ) ;
V_848 =
( ( V_774 -> V_11 . V_851 . V_67 != 0 ) &&
( V_774 -> V_11 . V_851 . V_68 != 0 ) ) ;
V_849 =
( ( V_774 -> V_11 . V_852 . V_67 != 0 ) &&
( V_774 -> V_11 . V_852 . V_68 != 0 ) ) ;
V_725 = & V_774 -> V_10 -> V_11 . V_12 . V_538 ;
V_726 = & V_774 -> V_6 [ 0 ] . V_238 ;
switch ( V_774 -> V_11 . V_59 ) {
case V_191 :
if ( V_847 )
V_726 = & V_774 -> V_850 . V_238 ;
else if ( V_848 )
V_726 = & V_774 -> V_11 . V_851 ;
break;
case V_195 :
if ( V_847 )
V_726 = & V_774 -> V_850 . V_238 ;
break;
case V_189 :
if ( V_849 )
V_726 = & V_774 -> V_11 . V_852 ;
break;
case V_437 :
case V_62 :
case V_190 :
default:
F_144 ( L_228 ,
V_774 -> V_11 . V_59 ) ;
assert ( 0 ) ;
break;
}
V_52 = F_343 ( V_725 , V_726 , & V_846 ) ;
if ( V_52 == V_44 ) {
* V_538 = V_846 ;
} else {
F_91 ( L_229 , V_52 ) ;
}
return V_52 ;
}
static void
F_344 ( struct V_853 * V_854 )
{
assert ( V_854 != NULL ) ;
V_854 -> V_855 = false ;
V_854 -> type = V_578 ;
V_854 -> V_572 = NULL ;
V_854 -> V_581 = 0 ;
}
static struct V_853
* F_345 ( T_9 V_856 ,
enum V_574 type )
{
int V_8 ;
struct V_853 * V_854 = NULL ;
bool V_602 = false ;
V_854 = & V_857 [ 0 ] ;
for ( V_8 = 0 ; V_8 < V_858 ; V_8 ++ ) {
if ( ( V_854 -> V_855 == true ) &&
( V_854 -> type == type ) &&
( V_854 -> V_572 != NULL ) &&
( V_854 -> V_572 -> V_597 == V_856 ) ) {
V_602 = true ;
break;
}
V_854 ++ ;
}
if ( V_602 == true )
return V_854 ;
else
return NULL ;
}
