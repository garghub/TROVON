static void
F_1 ( struct V_1 * V_2 )
{
assert ( V_2 != NULL ) ;
if ( V_2 == NULL ) {
F_2 ( L_1 ) ;
return;
}
if ( V_2 -> V_3 )
F_3 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
static enum V_4
F_4 ( struct V_1 * V_2 )
{
enum V_5 V_6 = V_2 -> V_7 [ 0 ] . V_8 ;
unsigned int V_9 , V_10 = 0 ;
assert ( V_2 != NULL ) ;
assert ( V_2 -> V_11 != NULL ) ;
switch ( V_2 -> V_11 -> V_12 . V_13 . V_8 ) {
case V_14 :
case V_15 :
for ( V_9 = 0 ; V_9 < F_5 ( V_16 ) && ! V_10 ; V_9 ++ )
V_10 = ( V_6 == V_16 [ V_9 ] ) ;
break;
case V_17 :
case V_18 :
V_10 = ( V_6 == V_19 ) ;
break;
case V_20 :
for ( V_9 = 0 ; V_9 < F_5 ( V_21 ) && ! V_10 ; V_9 ++ )
V_10 = ( V_6 == V_21 [ V_9 ] ) ;
break;
case V_22 :
case V_23 :
V_10 = ( V_6 == V_24 ||
V_6 == V_19 ) ;
break;
case V_25 :
case V_26 :
case V_27 :
V_10 = ( V_6 == V_28 ||
V_6 == V_29 ) ;
break;
case V_30 :
case V_31 :
V_10 = ( V_6 == V_28 ||
V_6 == V_32 ) ;
break;
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
V_10 = ( V_6 == V_40 ) ||
( V_6 == V_41 ) ;
break;
case V_42 :
V_10 = ( V_6 == V_43 ) ;
break;
default:
break;
}
if ( ! V_10 )
return V_44 ;
return V_45 ;
}
unsigned int
F_6 ( struct V_46 * V_11 )
{
int V_47 = 0 ;
if ( V_11 != NULL )
V_47 = F_7 ( V_11 -> V_12 . V_13 . V_8 ,
V_11 -> V_12 . V_48 == 2 ) ;
return V_47 ;
}
static enum V_4
F_8 ( struct V_46 * V_11 )
{
unsigned int V_49 ;
struct V_1 * V_2 = V_11 -> V_50 ;
struct V_51 * V_52 = NULL ;
enum V_4 V_53 = V_45 ;
assert ( V_11 != NULL ) ;
assert ( V_2 != NULL ) ;
F_9 ( V_54 ,
L_2 ) ;
if ( V_2 -> V_55 . V_56 )
V_52 = V_2 -> V_55 . V_56 -> V_52 ;
V_53 = F_10 (
V_11 -> V_12 . V_13 . V_8 ,
V_11 -> V_57 . V_58 ,
& V_49 ) ;
if ( V_53 != V_45 )
return V_53 ;
F_11 ( V_49 ,
V_11 -> V_12 . V_59 ,
V_11 -> V_12 . V_60 ) ;
if ( ( V_52 && ( V_52 -> V_61 || V_11 -> V_12 . V_62 ) ) ||
V_2 -> V_12 . V_60 == V_63 ) {
V_53 = F_12 ( & V_11 -> V_12 ,
V_52 ) ;
if ( V_53 != V_45 )
return V_53 ;
}
if ( V_11 -> V_12 . V_60 == V_64 ||
V_11 -> V_12 . V_60 == V_65 ) {
unsigned int V_66 = 100 ,
V_67 = 6 ,
V_68 ,
V_69 ,
V_70 ;
V_68 = ( V_11 -> V_12 . V_13 . V_71 . V_68 ) / ( 1 + ( V_11 -> V_12 . V_48 == 2 ) ) ;
V_69 = V_11 -> V_12 . V_13 . V_71 . V_69 ;
V_70 = V_67 * ( V_68 + V_66 ) ;
F_13 ( V_68 , V_69 , V_66 ,
V_70 ) ;
#if F_14 ( V_72 )
if ( V_2 -> V_11 -> V_12 . V_60 == V_64 ) {
#define F_15 0x90058
F_16 ( F_15 , 0 ) ;
}
#endif
}
F_9 ( V_54 ,
L_3 ) ;
return V_45 ;
}
static unsigned int F_17 (
enum V_73 V_8 ,
unsigned int V_74 )
{
unsigned int V_75 ;
switch ( V_8 ) {
case V_14 :
V_75 = V_74 * 2 ;
break;
case V_15 :
case V_17 :
case V_18 :
V_75 = V_74 * 2 ;
break;
case V_20 :
case V_22 :
case V_23 :
V_75 = V_74 * 2 ;
break;
case V_25 :
case V_26 :
case V_27 :
case V_30 :
case V_31 :
V_75 = V_74 * 4 ;
break;
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_42 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
V_75 = V_74 ;
break;
default:
V_75 = 0 ;
break;
}
return V_75 ;
}
static bool F_18 (
struct V_84 * V_85 ,
T_1 * V_86 )
{
bool V_87 ;
V_87 = true ;
switch ( V_85 -> V_60 ) {
case V_64 :
if ( V_85 -> V_88 . V_89 . V_90 == V_91 ) {
V_86 -> V_92 = V_93 ;
} else if ( V_85 -> V_88 . V_89 . V_90 == V_94 ) {
V_86 -> V_92 = V_95 ;
} else if ( V_85 -> V_88 . V_89 . V_90 == V_96 ) {
V_86 -> V_92 = V_97 ;
}
break;
case V_65 :
if ( V_85 -> V_88 . V_98 . V_90 == V_99 ) {
V_86 -> V_92 = V_93 ;
} else if ( V_85 -> V_88 . V_98 . V_90 == V_100 ) {
V_86 -> V_92 = V_95 ;
} else if ( V_85 -> V_88 . V_98 . V_90 == V_101 ) {
V_86 -> V_92 = V_97 ;
}
break;
case V_102 :
if ( V_85 -> V_88 . V_103 . V_103 == V_104 ) {
V_86 -> V_92 = V_105 ;
} else if ( V_85 -> V_88 . V_103 . V_103 == V_106 ) {
V_86 -> V_92 = V_107 ;
} else if ( V_85 -> V_88 . V_103 . V_103 == V_108 ) {
V_86 -> V_92 = V_109 ;
}
break;
default:
V_87 = false ;
break;
}
return V_87 ;
}
static bool F_19 (
struct V_84 * V_85 ,
T_1 * V_86 )
{
bool V_87 ;
V_87 = true ;
switch ( V_85 -> V_60 ) {
case V_64 :
V_86 -> V_60 = V_110 ;
break;
case V_65 :
V_86 -> V_60 = V_111 ;
break;
case V_112 :
case V_102 :
V_86 -> V_60 = V_113 ;
break;
default:
V_87 = false ;
break;
}
return V_87 ;
}
static bool F_20 (
struct V_84 * V_85 ,
T_1 * V_86 ,
int V_114 )
{
bool V_87 ;
V_87 = true ;
switch ( V_85 -> V_60 ) {
case V_64 :
if ( V_85 -> V_88 . V_89 . V_60 == V_115 ) {
V_86 -> V_116 . V_60 = V_117 ;
} else if ( V_85 -> V_88 . V_89 . V_60 == V_118 ) {
V_86 -> V_116 . V_60 = V_119 ;
} else if ( V_85 -> V_88 . V_89 . V_60 == V_120 ) {
V_86 -> V_116 . V_60 = V_121 ;
} else {
V_87 = false ;
}
V_86 -> V_116 . V_122 . V_123 = 51 ;
V_86 -> V_116 . V_122 . V_124 = 102 ;
V_86 -> V_116 . V_122 . V_125 = 255 ;
V_86 -> V_116 . V_122 . V_126 = 0 ;
V_86 -> V_116 . V_122 . V_127 = 100 ;
V_86 -> V_116 . V_122 . V_128 = 160 ;
V_86 -> V_116 . V_129 . V_130 = V_85 -> V_88 . V_89 . V_131 ;
V_86 -> V_116 . V_129 . V_132 = V_85 -> V_88 . V_89 . V_133 ;
V_86 -> V_116 . V_129 . V_134 = V_85 -> V_88 . V_89 . V_135 ;
V_86 -> V_116 . V_136 . V_137 = V_85 -> V_88 . V_89 . V_138 ;
V_86 -> V_116 . V_136 . V_139 = V_85 -> V_88 . V_89 . V_140 ;
V_86 -> V_116 . V_141 . V_66 = 100 ;
V_86 -> V_116 . V_141 . V_70 = 100 ;
V_86 -> V_116 . V_141 . V_48 = V_85 -> V_48 ;
V_86 -> V_116 . V_141 . V_142 = ( V_143 ) ~ ( 0x0 ) ;
V_86 -> V_116 . V_141 . V_74 = V_85 -> V_144 [ V_145 ] . V_71 . V_68 ;
V_86 -> V_116 . V_141 . V_146 = V_85 -> V_144 [ V_145 ] . V_71 . V_69 ;
break;
case V_65 :
V_86 -> V_147 . V_148 = V_85 -> V_88 . V_98 . V_149 ;
V_86 -> V_147 . V_150 = V_85 -> V_88 . V_98 . V_150 ;
V_86 -> V_147 . V_141 . V_66 = 100 ;
V_86 -> V_147 . V_141 . V_70 = 100 ;
V_86 -> V_147 . V_141 . V_48 = V_85 -> V_48 ;
V_86 -> V_147 . V_141 . V_142 = ( V_143 ) ~ ( 0x0 ) ;
V_86 -> V_147 . V_141 . V_74 = V_85 -> V_144 [ V_145 ] . V_71 . V_68 ;
V_86 -> V_147 . V_141 . V_146 = V_85 -> V_144 [ V_145 ] . V_71 . V_69 ;
break;
case V_102 :
{
enum V_4 V_53 ;
unsigned int V_49 ;
V_53 = F_10 (
V_85 -> V_144 [ V_114 ] . V_8 ,
V_151 ,
& V_49 ) ;
if ( V_53 != V_45 )
V_87 = false ;
V_86 -> V_152 . V_153 = V_85 -> V_88 . V_103 . V_154 ;
V_86 -> V_152 . V_49 = V_49 ;
V_86 -> V_152 . V_155 = V_85 -> V_59 ;
#ifdef F_21
V_86 -> V_61 = V_85 -> V_61 ;
#endif
V_53 |= F_22 (
& V_85 -> V_88 . V_103 . V_156 ,
V_86 ) ;
if ( V_53 != V_45 )
V_87 = false ;
V_86 -> V_157 . V_158 = false ;
if ( V_85 -> V_159 . V_160 . V_69 > 0 ) {
V_53 = F_10 (
V_85 -> V_159 . V_161 ,
V_151 ,
& V_49 ) ;
if ( V_53 != V_45 )
V_87 = false ;
V_86 -> V_157 . V_49 = V_49 ;
V_86 -> V_157 . V_162 =
F_7 ( V_85 -> V_159 . V_161 , true ) ;
V_86 -> V_157 . V_74 = V_85 -> V_159 . V_160 . V_68 ;
V_86 -> V_157 . V_146 = V_85 -> V_159 . V_160 . V_69 ;
#ifdef F_21
if ( V_86 -> V_157 . V_146 > 0 )
V_86 -> V_157 . V_146 +=
( V_86 -> V_157 . V_146 & 1 ) ;
#endif
V_86 -> V_157 . V_163 =
F_23 ( V_85 -> V_159 . V_161 ) ;
V_86 -> V_157 . V_158 = true ;
}
break;
}
default:
V_87 = false ;
break;
}
return V_87 ;
}
static bool F_24 (
struct V_84 * V_85 ,
T_1 * V_86 ,
int V_114 )
{
unsigned int V_164 ;
unsigned int V_165 ;
unsigned int V_146 ;
unsigned int V_163 ;
enum V_73 V_49 ;
V_49 = V_85 -> V_144 [ V_114 ] . V_8 ;
if ( ( V_85 -> V_60 == V_112 ||
V_85 -> V_60 == V_102 ) &&
V_85 -> V_88 . V_103 . V_156 . type != V_166 ) {
if ( V_85 -> V_88 . V_103 . V_156 . V_167 ==
V_168 ) {
V_49 = V_36 ;
}
else if ( V_85 -> V_88 . V_103 . V_156 . V_167 ==
V_169 ) {
V_49 = V_37 ;
}
else
return false ;
}
V_164 =
F_25 ( V_49 ) ;
if ( V_164 == 0 )
return false ;
V_165 =
F_17 ( V_49 ,
V_85 -> V_144 [ V_114 ] . V_71 . V_68 ) ;
if ( V_165 == 0 )
return false ;
V_146 = V_85 -> V_144 [ V_114 ] . V_71 . V_69 ;
if ( V_146 == 0 )
return false ;
V_163 = F_23 ( V_49 ) ;
V_86 -> V_170 . V_162 = V_164 ;
V_86 -> V_170 . V_74 = V_165 ;
V_86 -> V_170 . V_146 = V_146 ;
V_86 -> V_170 . V_163 = V_163 ;
return true ;
}
static bool F_26 (
struct V_84 * V_85 ,
bool V_171 ,
T_1 * V_86 ,
int V_114 )
{
bool V_87 ;
F_9 ( V_54 ,
L_4 ) ;
V_87 = F_18 ( V_85 , V_86 ) ;
V_87 &= F_19 ( V_85 , V_86 ) ;
V_87 &= F_20 ( V_85 , V_86 , V_114 ) ;
V_87 &= F_24 ( V_85 , V_86 , V_114 ) ;
V_86 -> V_172 = V_85 -> V_173 ;
V_86 -> V_174 = ( V_175 ) V_85 -> V_144 [ V_114 ] . V_174 ;
V_86 -> V_176
= V_171 ? V_177
: V_178 ;
F_9 ( V_54 ,
L_5 ) ;
return V_87 ;
}
static bool F_27 (
struct V_51 * V_52 ,
T_1 * V_86 )
{
if ( ! V_52 )
return false ;
V_86 -> V_179 . V_180 = V_52 -> V_180 ;
V_86 -> V_179 . V_181 = V_52 -> V_182 -> V_183 . V_184 . V_185 ;
return true ;
}
static enum V_4
F_8 ( struct V_46 * V_11 )
{
bool V_87 ;
T_1 V_86 ;
unsigned int V_186 ;
struct V_187 * V_188 ;
struct V_1 * V_2 = NULL ;
struct V_51 * V_52 = NULL ;
int V_9 ;
V_143 V_189 ;
bool V_171 = false ;
assert ( V_11 != NULL ) ;
F_9 ( V_54 ,
L_6 , V_11 ) ;
if ( V_11 -> V_12 . V_62 == true ) {
if ( V_11 -> V_50 -> V_12 . V_60 == V_190 ) {
V_2 = V_11 -> V_50 ;
} else if ( V_11 -> V_50 -> V_12 . V_60 == V_191 ) {
V_2 = V_11 -> V_50 ;
} else if ( V_11 -> V_50 -> V_12 . V_60 == V_192 ) {
V_2 = V_11 -> V_50 -> V_193 . V_194 . V_195 ;
} else if ( V_11 -> V_50 -> V_12 . V_60 == V_196 ) {
V_2 = V_11 -> V_50 -> V_193 . V_197 . V_195 ;
}
} else {
V_2 = V_11 -> V_50 ;
if ( V_11 -> V_50 -> V_12 . V_60 == V_190 ) {
V_171 = true ;
}
}
assert ( V_2 != NULL ) ;
if ( V_2 == NULL )
return V_198 ;
if ( V_2 -> V_55 . V_56 != NULL )
if ( V_2 -> V_55 . V_56 -> V_52 != NULL )
V_52 = V_2 -> V_55 . V_56 -> V_52 ;
if ( V_52 ) {
F_28 ( V_2 , & V_52 -> V_199 ) ;
}
V_87 = F_29 ( F_30 ( V_2 ) , & V_186 ) ;
if ( V_87 != true )
return V_198 ;
V_188 = & ( V_200 . V_201 [ V_186 ] . V_184 ) ;
for ( V_9 = 0 ; V_9 < V_202 ; V_9 ++ ) {
memset ( ( void * ) ( & V_86 ) , 0 , sizeof( T_1 ) ) ;
V_188 -> V_203 . V_204 [ V_9 ] . V_205 = 0 ;
V_188 -> V_206 . V_207 [ V_9 ] . V_205 = 0 ;
if ( ! V_11 -> V_12 . V_144 [ V_9 ] . V_205 )
continue;
V_87 = F_26 (
& ( V_11 -> V_12 ) ,
V_171 ,
& ( V_86 ) , V_9 ) ;
if ( V_11 -> V_12 . V_61 ) {
V_87 &= F_27 (
V_52 ,
& ( V_86 ) ) ;
}
if ( V_87 != true )
return V_198 ;
V_189 = F_31 ( V_186 , V_9 ) ;
V_87 = F_32 (
& ( V_86 ) ,
& ( V_188 -> V_203 . V_204 [ V_9 ] ) ,
V_189 ) ;
if ( V_87 != true )
return V_198 ;
V_87 = F_33 (
& ( V_188 -> V_203 . V_204 [ V_9 ] ) ,
& ( V_86 ) ,
& ( V_188 -> V_206 . V_207 [ V_9 ] ) ) ;
if ( V_87 != true ) {
F_34 ( & ( V_188 -> V_203 . V_204 [ V_9 ] ) ) ;
return V_198 ;
}
}
F_9 ( V_54 ,
L_3 ) ;
return V_45 ;
}
static inline struct V_1 * F_35 (
struct V_46 * V_11 )
{
struct V_1 * V_50 = NULL ;
if ( V_11 != NULL )
V_50 = V_11 -> V_50 ;
return V_50 ;
}
static inline struct V_1 * F_36 (
struct V_46 * V_11 )
{
struct V_1 * V_195 = NULL ;
struct V_1 * V_50 = NULL ;
enum V_208 V_209 ;
V_50 = F_35 ( V_11 ) ;
if ( ( V_11 != NULL ) &&
( V_50 != NULL ) &&
( V_11 -> V_12 . V_62 ) ) {
V_209 = V_50 -> V_60 ;
switch ( V_209 ) {
case V_210 :
V_195 = V_50 -> V_193 . V_194 . V_195 ;
break;
case V_211 :
V_195 = V_50 -> V_193 . V_197 . V_195 ;
break;
default:
V_195 = NULL ;
break;
}
}
return V_195 ;
}
static inline struct V_1 * F_37 (
struct V_46 * V_11 )
{
struct V_1 * V_212 ;
if ( V_11 -> V_12 . V_62 ) {
V_212 = F_36 ( V_11 ) ;
} else {
V_212 = F_35 ( V_11 ) ;
}
return V_212 ;
}
static inline enum V_4 F_38 (
struct V_46 * V_11 )
{
return F_39 ( V_11 , V_213 ) ;
}
static inline enum V_4 F_40 (
struct V_46 * V_11 )
{
return F_39 ( V_11 , V_214 ) ;
}
static void F_41 ( char * V_215 , struct V_216 * V_217 )
{
unsigned V_9 ;
unsigned V_218 = 0 ;
unsigned V_219 = 0 ;
if ( V_217 == NULL )
return;
F_42 ( L_7 , V_215 , V_217 -> V_220 ) ;
F_42 ( L_8 , V_215 ) ;
for ( V_9 = 0 ; V_9 < V_217 -> V_220 ; V_9 ++ ) {
if ( ( V_217 -> V_221 [ V_9 ] == 0 ) && ( V_217 -> V_221 [ V_9 ] == V_217 -> V_222 [ V_9 ] ) )
continue;
F_42 ( L_9 ,
V_215 , V_9 , V_217 -> V_221 [ V_9 ] , V_217 -> V_222 [ V_9 ] ) ;
V_218 += V_217 -> V_221 [ V_9 ] ;
V_219 += V_217 -> V_222 [ V_9 ] ;
}
F_42 ( L_10
L_11 ,
V_215 , V_218 , V_219 , V_217 -> V_220 ) ;
}
static void F_43 ( void )
{
struct V_223 * V_224 ;
for ( V_224 = V_225 . V_226 ;
V_224 ;
V_224 = V_224 -> V_227 ) {
if ( V_224 -> V_60 == V_228 ||
V_224 -> V_60 == V_229 ) {
F_42 ( L_12 ,
V_224 -> V_90 ) ;
continue;
}
F_42 ( L_13 , V_224 -> V_90 ) ;
F_41 ( L_14 , & V_224 -> V_230 ) ;
F_41 ( L_15 , & V_224 -> V_231 ) ;
F_42 ( L_16
L_17 , V_224 -> V_90 ) ;
}
F_42 ( L_18 ) ;
}
static int F_44 ( void * V_232 )
{
int V_9 = 0 ;
( void ) V_232 ;
while ( true ) {
if ( V_233 ) {
F_45 () ;
#if V_234
for ( V_9 = 0 ; V_9 < V_235 ; V_9 ++ )
F_45 () ;
#endif
}
F_46 ( 10 , 50 ) ;
}
return 0 ;
}
static void F_47 ( void )
{
V_236 = F_48 ( F_44 , NULL , L_19 ) ;
F_49 ( 1 ) ;
}
static void F_50 ( struct V_237 V_238 )
{
F_42 ( L_20
L_21 ,
V_238 . V_239 . V_68 , V_238 . V_239 . V_69 , V_238 . V_8 ) ;
}
static void
F_51 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
struct V_46 * V_11 ;
assert ( V_2 != NULL ) ;
( void ) V_52 ;
#if ! F_14 ( V_240 )
V_11 = V_2 -> V_11 ;
#else
( void ) V_2 ;
( void ) V_11 ;
#endif
if ( V_52 )
F_52 ( & V_52 -> V_224 ) ;
#if V_241
F_42 ( L_22
L_23 ,
V_242 , V_52 -> V_182 -> V_183 . V_90 ,
V_52 -> V_182 -> V_183 . V_158 . V_243 ) ;
F_50 ( V_52 -> V_199 ) ;
if ( V_52 && V_52 -> V_182 -> V_183 . V_55 . V_60 == V_244 )
V_233 = true ;
#endif
#if ! F_14 ( V_240 ) && ! F_14 ( F_21 )
if ( V_11 -> V_245 ) {
F_53 ( & V_2 -> V_11 -> V_57 ,
V_2 -> V_11 -> V_12 . V_60 ) ;
V_11 -> V_245 = false ;
}
#endif
}
static enum V_4
F_54 ( struct V_1 * V_2 ,
struct V_246 * V_247 )
{
( void ) V_247 ;
assert ( V_2 != NULL ) ;
assert ( V_2 -> V_11 != NULL ) ;
if ( ( V_2 == NULL ) || ( V_2 -> V_11 == NULL ) )
return V_44 ;
#if ! F_14 ( V_240 ) && ! F_14 ( F_21 )
if ( V_2 -> V_11 -> V_245 )
F_55 () ;
#endif
if ( V_2 -> V_11 -> V_12 . V_13 . V_8 != V_42 )
return V_198 ;
F_56 ( F_30 ( V_2 ) , V_247 , V_2 -> V_11 -> V_12 . V_48 == 2 ) ;
#if ! F_14 ( V_240 ) && ! F_14 ( F_21 )
if ( V_2 -> V_11 -> V_245 ) {
F_53 ( & V_2 -> V_11 -> V_57 , V_2 -> V_11 -> V_12 . V_60 ) ;
V_2 -> V_11 -> V_245 = false ;
}
#endif
return V_45 ;
}
void F_57 ( struct V_248 * args )
{
unsigned int V_9 ;
#ifndef F_58
for ( V_9 = 0 ; V_9 < V_249 ; V_9 ++ )
#else
for ( V_9 = 0 ; V_9 < V_250 ; V_9 ++ )
#endif
args -> V_251 [ V_9 ] = NULL ;
for ( V_9 = 0 ; V_9 < V_252 ; V_9 ++ )
args -> V_253 [ V_9 ] = NULL ;
args -> V_254 = NULL ;
for ( V_9 = 0 ; V_9 < V_255 ; V_9 ++ )
args -> V_247 [ V_9 ] = NULL ;
args -> V_256 = NULL ;
args -> V_257 = false ;
args -> V_258 = true ;
args -> V_259 = 0 ;
}
static void F_59 (
struct V_1 * V_260 ,
enum V_261 V_262 ,
enum V_263 V_264 )
{
#if F_14 ( V_240 )
( void ) V_264 ;
#endif
F_60 ( L_24 ,
V_260 , V_262 , V_264 ) ;
assert ( V_260 != NULL ) ;
F_61 ( & V_260 -> V_55 ,
V_260 -> V_60 ,
( V_265 ) F_30 ( V_260 ) ,
V_260 -> V_12 . V_266 . V_267 != 0 ,
V_260 -> V_11 -> V_12 . V_48 == 2 ,
V_260 -> V_11 -> V_12 . V_62 ,
false ,
V_260 -> V_268 ,
V_262 ,
V_264 ,
& V_260 -> V_11 -> V_12 . V_159 ,
& V_260 -> V_11 -> V_182 . V_269
#if ! F_14 ( V_240 )
, ( V_264 == V_270 ) ?
( V_271 ) 0 :
V_260 -> V_11 -> V_12 . V_88 . V_103 . V_103
#endif
#ifdef F_58
, & V_260 -> V_12 . V_272 ,
V_260 -> V_11 -> V_273
#endif
) ;
if ( V_260 -> V_12 . V_60 != V_63 ) {
struct V_274 * V_275 ;
V_275 = V_260 -> V_55 . V_56 ;
if ( V_275 ) {
V_260 -> V_55 . V_276 = V_275 ;
F_51 ( V_260 , V_275 -> V_52 ) ;
}
}
F_62 ( L_25 ) ;
}
void
F_63 ( struct V_46 * V_11 )
{
int V_9 ;
assert ( V_11 != NULL ) ;
F_9 ( V_277 ,
L_26 ) ;
for ( V_9 = 0 ; V_9 < V_11 -> V_278 ; V_9 ++ ) {
assert ( V_11 -> V_279 [ V_9 ] != NULL ) ;
F_1 ( V_11 -> V_279 [ V_9 ] ) ;
}
F_9 ( V_277 ,
L_27 ) ;
}
static void
F_64 ( enum V_280 V_281 )
{
#ifdef F_65
V_271 V_103 ;
#endif
bool V_282 = V_281 != V_283 ;
F_60 ( L_28 ) ;
F_66 ( V_284 , true ) ;
F_67 ( V_285 , V_282 ) ;
F_68 ( V_286 , true ) ;
F_68 (
( V_287 ) ( V_288 + V_289 ) ,
true ) ;
F_68 (
( V_287 ) ( V_290 + V_289 ) ,
true ) ;
#if ! F_14 ( V_291 )
F_68 (
( V_287 ) ( V_292 + V_289 ) ,
true ) ;
F_69 () ;
#endif
#ifdef F_65
for ( V_103 = 0 ; V_103 < V_293 ; V_103 ++ )
F_70 ( V_103 ) ;
#endif
F_62 ( L_28 ) ;
}
static bool F_71 ( const struct V_294 * V_295 ,
const char * V_296 ,
T_2 * V_297 )
{
if( ( V_295 == NULL ) || ( V_297 == NULL ) )
return false ;
V_297 -> V_298 = 0 ;
V_297 -> V_299 = ( char * ) ( V_296 ) ;
V_297 -> V_300 = V_295 -> V_301 . V_302 ;
V_297 -> V_303 = V_295 -> V_301 . V_304 ;
V_297 -> V_305 = V_295 -> V_301 . V_306 ;
V_297 -> V_307 = V_295 -> V_301 . V_307 ;
V_297 -> V_308 = V_295 -> V_301 . V_308 ;
V_297 -> V_309 = V_295 -> V_182 . V_183 . V_310 ;
V_297 -> V_311 = V_295 -> V_182 . V_183 . V_312 ;
V_297 -> V_313 = V_295 -> V_301 . V_314 ;
V_297 -> V_315 = V_295 -> V_301 . V_315 ;
V_297 -> V_298 = V_295 -> V_182 . V_183 . V_298 ;
return true ;
}
void
F_72 ( void )
{
if ( V_316 )
{
F_73 () ;
F_74 () ;
}
V_317 = false ;
}
static void
F_75 ( struct V_318 * V_319 )
{
struct V_318 V_320 ;
memset ( & V_320 , 0 , sizeof( V_320 ) ) ;
V_320 . V_321 = true ;
V_320 . V_322 = V_323 ;
V_320 . V_281 = V_283 ;
* V_319 = V_320 ;
}
bool
F_76 ( const struct V_324 * V_295 )
{
bool V_325 = false ;
if ( V_295 != NULL ) {
V_325 = F_77 ( V_295 -> V_232 ) ;
}
return V_325 ;
}
enum V_4
F_78 ( const struct V_326 * V_327 ,
const struct V_324 * V_295 )
{
enum V_4 V_53 ;
if ( V_327 == NULL )
return V_44 ;
if ( V_295 == NULL )
return V_44 ;
F_9 ( V_277 , L_29 ) ;
if ( V_328 . V_329 != V_327 -> V_330 . V_329 ) {
F_75 ( & V_328 ) ;
V_328 . V_329 = V_327 -> V_330 . V_329 ;
}
F_72 () ;
V_53 = F_79 ( V_295 -> V_232 , V_295 -> V_331 ) ;
if ( V_53 == V_45 ) {
V_53 = F_80 () ;
if ( V_53 == V_45 )
V_317 = true ;
}
F_9 ( V_277 , L_30 ) ;
return V_53 ;
}
enum V_4
F_81 ( const struct V_326 * V_327 ,
const struct V_324 * V_295 ,
V_143 V_332 ,
enum V_280 V_281 )
{
enum V_4 V_53 ;
T_2 V_297 ;
void (* F_82)( struct V_333 * V_295 );
T_3 V_334 , V_158 ;
F_83 ( sizeof( struct V_335 ) != V_336 ) ;
F_83 ( sizeof( struct V_337 ) != V_338 ) ;
F_83 ( sizeof( struct V_339 ) != V_340 ) ;
F_83 ( sizeof( struct V_341 ) != V_342 ) ;
F_83 ( sizeof( struct V_343 ) != V_344 ) ;
F_83 ( sizeof( struct V_345 ) != V_346 ) ;
F_83 ( sizeof( struct V_347 ) != V_348 ) ;
F_83 ( sizeof( struct V_349 ) != V_350 ) ;
F_83 ( sizeof( struct V_351 ) != V_352 ) ;
F_83 ( sizeof( struct V_353 ) != V_354 ) ;
F_83 ( sizeof( struct V_355 ) != V_356 ) ;
if ( V_295 == NULL && ! V_317 )
return V_44 ;
if ( V_327 == NULL )
return V_44 ;
V_357 = V_327 -> V_358 . V_359 ;
F_84 ( L_25 ) ;
F_82 = V_327 -> V_330 . V_329 ;
F_85 () ;
F_86 () ;
F_87 () ;
F_88 ( & V_327 -> V_360 ) ;
V_334 = F_89 ( V_361 , V_362 )
& ( ~ V_363 ) ;
V_158 = F_89 ( V_361 , V_364 )
| V_363 ;
F_90 ( V_332 ) ;
#ifndef F_58
V_365 . V_366 = V_332 ;
#else
F_91 ( V_332 ) ;
#endif
F_75 ( & V_328 ) ;
V_365 . V_367 = * V_327 ;
V_328 . V_329 = F_82 ;
V_53 = F_92 () ;
if ( V_53 != V_45 ) {
F_93 ( V_53 ) ;
return V_53 ;
}
#ifndef F_58
F_94 ( L_31 , V_368 ) ;
#else
F_95 () ;
#endif
#ifndef F_58
if ( ! V_368 )
{
V_368 = true ;
V_365 . V_60 = V_369 ;
memset ( V_365 . V_370 , 0 , sizeof( struct V_371 ) * V_372 ) ;
F_94 ( L_32 , V_368 , V_365 . V_60 ) ;
}
#endif
F_96 () ;
#ifndef F_58
V_328 . V_373 = F_97 ( V_374 ) ;
#endif
V_328 . V_281 = V_281 ;
#ifndef F_58
V_365 . V_281 = V_281 ;
#else
F_98 ( V_281 ) ;
#endif
F_64 ( V_328 . V_281 ) ;
F_99 ( V_361 , V_362 , V_334 ) ;
F_99 ( V_361 , V_364 , V_158 ) ;
F_99 ( V_361 , V_375 , 0 ) ;
V_53 = F_100 ( V_376 ) ;
if ( V_53 != V_45 ) {
F_93 ( V_53 ) ;
return V_53 ;
}
V_53 = F_101 () ;
if ( V_53 != V_45 ) {
F_93 ( V_53 ) ;
return V_53 ;
}
if ( V_295 )
{
F_72 () ;
V_53 = F_79 ( V_295 -> V_232 , V_295 -> V_331 ) ;
if ( V_53 != V_45 ) {
F_93 ( V_53 ) ;
return V_53 ;
}
V_53 = F_80 () ;
if ( V_53 != V_45 ) {
F_93 ( V_53 ) ;
return V_53 ;
}
V_317 = false ;
#ifndef F_58
V_365 . V_377 = (struct V_324 * ) V_295 ;
#endif
}
if( ! F_71 ( & V_378 , V_379 , & V_297 ) )
return V_198 ;
V_53 = F_102 ( V_284 , & V_297 ) ;
if ( V_53 != V_45 ) {
F_93 ( V_53 ) ;
return V_53 ;
}
#if V_241
if ( ! V_380 ) {
V_380 ++ ;
F_42 ( L_33 ,
V_242 ) ;
F_47 () ;
}
#endif
if ( ! F_103 () ) {
F_93 ( V_381 ) ;
return V_381 ;
}
#if F_14 ( V_382 ) && F_14 ( V_383 )
#if F_14 ( F_65 )
F_104 ( V_384 , V_385 , 0 ) ;
#elif F_14 ( F_21 )
F_104 ( V_384 , V_385 , 1 ) ;
#endif
#endif
#if ! F_14 ( V_240 )
F_105 ( V_386 , V_387 ,
V_388 ) ;
if( F_106 () != V_389 )
V_53 = V_44 ;
#endif
F_107 () ;
F_93 ( V_53 ) ;
return V_53 ;
}
enum V_4 F_108 ( void )
{
int V_9 ;
F_9 ( V_277 , L_34 ) ;
V_365 . V_60 = V_390 ;
for( V_9 = 0 ; V_9 < V_372 ; V_9 ++ )
if ( V_365 . V_370 [ V_9 ] . V_11 != NULL )
{
F_9 ( V_277 , L_35 , V_9 , V_365 . V_370 [ V_9 ] . V_11 ) ;
F_109 ( V_365 . V_370 [ V_9 ] . V_11 ) ;
}
V_365 . V_60 = V_369 ;
F_110 () ;
F_111 () ;
for( V_9 = 0 ; V_9 < V_372 ; V_9 ++ )
F_9 ( V_277 , L_36 , V_9 , V_365 . V_370 [ V_9 ] . V_11 ) ;
F_9 ( V_277 , L_37 ) ;
return V_45 ;
}
enum V_4
F_112 ( void )
{
int V_9 , V_391 ;
enum V_4 V_53 ;
F_9 ( V_277 , L_38 ) ;
V_53 = F_81 ( & ( V_365 . V_367 ) , V_365 . V_377 , V_365 . V_366 , V_365 . V_281 ) ;
if ( V_53 != V_45 )
return V_53 ;
V_53 = F_113 () ;
if ( V_53 != V_45 )
return V_53 ;
V_365 . V_60 = V_392 ;
for( V_9 = 0 ; V_9 < V_372 ; V_9 ++ )
{
F_9 ( V_277 , L_39 , V_365 . V_370 [ V_9 ] . V_11 ) ;
if ( V_365 . V_370 [ V_9 ] . V_11 != NULL )
{
F_9 ( V_277 , L_40 , V_9 ) ;
V_53 = F_114 ( V_365 . V_370 [ V_9 ] . V_11 ) ;
if ( V_53 != V_45 )
{
if ( V_9 )
for( V_391 = 0 ; V_391 < V_9 ; V_391 ++ )
F_109 ( V_365 . V_370 [ V_391 ] . V_11 ) ;
return V_53 ;
}
V_53 = F_115 ( V_365 . V_370 [ V_9 ] . V_11 ) ;
if ( V_53 != V_45 )
{
for( V_391 = 0 ; V_391 <= V_9 ; V_391 ++ )
{
F_116 ( V_365 . V_370 [ V_391 ] . V_11 ) ;
F_109 ( V_365 . V_370 [ V_391 ] . V_11 ) ;
}
return V_53 ;
}
* V_365 . V_370 [ V_9 ] . V_393 = V_365 . V_370 [ V_9 ] . V_11 ;
for( V_391 = 0 ; V_391 < V_365 . V_370 [ V_9 ] . V_278 ; V_391 ++ )
* ( V_365 . V_370 [ V_9 ] . V_394 [ V_391 ] ) = V_365 . V_370 [ V_9 ] . V_279 [ V_391 ] ;
}
}
V_365 . V_60 = V_369 ;
F_9 ( V_277 , L_41 ) ;
return V_45 ;
}
enum V_4
F_117 ( bool V_158 )
{
if ( F_118 () )
return V_395 ;
F_119 ( V_158 ) ;
return V_45 ;
}
void * F_120 ( T_4 V_314 )
{
F_9 ( V_277 , L_42 , V_314 ) ;
if ( V_314 == 0 )
return NULL ;
if ( V_314 > V_396 )
return F_121 ( V_314 ) ;
return F_122 ( V_314 , V_397 ) ;
}
void * F_123 ( T_4 V_398 , T_4 V_314 )
{
void * V_399 ;
F_9 ( V_277 , L_43 , V_398 , V_314 ) ;
if ( V_314 > 0 ) {
V_399 = F_120 ( V_398 * V_314 ) ;
if ( V_399 )
memset ( V_399 , 0 , V_314 ) ;
}
return NULL ;
}
void F_124 ( void * V_400 )
{
if ( F_125 ( V_400 ) )
F_126 ( V_400 ) ;
else
F_127 ( V_400 ) ;
}
void
F_128 ( struct V_333 * V_295 )
{
F_9 ( V_277 , L_44 ) ;
if ( ( V_295 != NULL ) && ( V_328 . V_329 != NULL ) )
V_328 . V_329 ( V_295 ) ;
}
static enum V_4
F_129 ( struct V_46 * V_11 , bool V_401 )
{
struct V_1 * V_402 = NULL ;
struct V_1 * V_195 = NULL ;
struct V_1 * V_403 = NULL ;
struct V_1 * V_404 = NULL ;
enum V_4 V_53 = V_45 ;
enum V_208 V_209 ;
assert ( V_11 != NULL ) ;
F_60 ( L_45 ,
V_11 , V_401 ? L_46 : L_47 ) ;
if ( V_11 == NULL ) {
F_130 ( V_44 ) ;
return V_44 ;
}
V_402 = V_11 -> V_50 ;
V_209 = V_402 -> V_60 ;
F_131 ( V_402 -> V_405 , V_401 ) ;
switch ( V_209 ) {
case V_210 :
V_195 = V_402 -> V_193 . V_194 . V_195 ;
V_403 = V_402 -> V_193 . V_194 . V_403 ;
V_404 = V_402 -> V_193 . V_194 . V_404 ;
break;
case V_211 :
V_195 = V_402 -> V_193 . V_197 . V_195 ;
V_403 = V_402 -> V_193 . V_197 . V_403 ;
break;
case V_406 :
case V_407 :
default:
break;
}
if ( V_404 ) {
F_131 ( V_404 -> V_405 , V_401 ) ;
}
if( V_403 ) {
F_131 ( V_403 -> V_405 , V_401 ) ;
}
if( V_195 ) {
F_131 ( V_195 -> V_405 , V_401 ) ;
}
if ( ! V_11 -> V_12 . V_62 ) {
int V_9 ;
for ( V_9 = 1 ; V_9 < V_11 -> V_278 ; V_9 ++ )
F_131 ( V_11 -> V_279 [ V_9 ] -> V_405 , V_401 ) ;
}
F_130 ( V_53 ) ;
return V_53 ;
}
static enum V_4
F_132 ( struct V_46 * V_11 )
{
struct V_1 * V_195 = NULL , * V_403 = NULL ;
struct V_1 * V_404 = NULL ;
enum V_208 V_209 ;
struct V_1 * V_402 = NULL ;
enum V_4 V_53 = V_45 ;
unsigned int V_408 = 0 ,
V_409 = 0 ;
assert ( V_11 != NULL ) ;
F_60 ( L_48 , V_11 ) ;
if ( V_11 == NULL ) {
F_130 ( V_44 ) ;
return V_44 ;
}
V_402 = V_11 -> V_50 ;
assert ( V_402 != NULL ) ;
if ( V_402 == NULL ) {
F_130 ( V_44 ) ;
return V_44 ;
}
V_209 = V_402 -> V_60 ;
switch ( V_209 ) {
case V_210 :
V_195 = V_402 -> V_193 . V_194 . V_195 ;
V_408 = V_402 -> V_410 ;
V_403 = V_402 -> V_193 . V_194 . V_403 ;
V_409 = V_411 ;
V_404 = V_402 -> V_193 . V_194 . V_404 ;
V_53 = F_133 ( & V_402 -> V_55 , V_402 -> V_60 , V_402 -> V_405 , V_402 -> V_410 ) ;
break;
case V_211 :
V_195 = V_402 -> V_193 . V_197 . V_195 ;
V_408 = V_402 -> V_410 ;
V_403 = V_402 -> V_193 . V_197 . V_403 ;
V_409 = V_411 ;
V_53 = F_133 ( & V_402 -> V_55 , V_402 -> V_60 , V_402 -> V_405 , V_402 -> V_410 ) ;
break;
case V_406 :
V_403 = V_402 ;
V_409 = V_402 -> V_410 ;
break;
case V_412 :
V_53 = F_133 ( & V_402 -> V_55 , V_402 -> V_60 ,
V_402 -> V_405 , V_402 -> V_410 ) ;
break;
case V_407 :
V_53 = F_133 ( & V_402 -> V_55 , V_402 -> V_60 , V_402 -> V_405 , V_402 -> V_410 ) ;
break;
default:
V_53 = V_44 ;
}
if ( ( V_45 == V_53 ) && V_195 ) {
V_53 = F_133 ( & V_195 -> V_55 ,
V_195 -> V_60 ,
V_195 -> V_405 ,
V_408 ) ;
}
if ( ( V_45 == V_53 ) && V_403 ) {
V_53 = F_133 ( & V_403 -> V_55 ,
V_403 -> V_60 ,
V_403 -> V_405 ,
V_409 ) ;
}
if ( ( V_45 == V_53 ) && V_404 ) {
V_53 = F_133 ( & V_404 -> V_55 , V_404 -> V_60 , V_404 -> V_405 , V_402 -> V_410 ) ;
}
if ( ! V_11 -> V_12 . V_62 ) {
int V_9 ;
for ( V_9 = 1 ; V_9 < V_11 -> V_278 && V_45 == V_53 ; V_9 ++ ) {
V_402 = V_11 -> V_279 [ V_9 ] ;
V_53 = F_133 ( & V_402 -> V_55 ,
V_402 -> V_60 ,
V_402 -> V_405 ,
V_402 -> V_410 ) ;
}
}
F_130 ( V_53 ) ;
return V_53 ;
}
static enum V_4
F_134 ( struct V_46 * V_11 )
{
struct V_1 * V_195 = NULL , * V_403 = NULL ;
struct V_1 * V_404 = NULL ;
enum V_208 V_209 ;
struct V_1 * V_402 = NULL ;
enum V_4 V_53 = V_45 ;
unsigned V_413 = 0 ;
F_60 ( L_48 , V_11 ) ;
if ( V_11 == NULL ) {
F_130 ( V_44 ) ;
return V_44 ;
}
V_402 = V_11 -> V_50 ;
V_209 = V_402 -> V_60 ;
if ( ( V_209 == V_210 ) ||
( V_209 == V_211 ) ) {
if ( V_11 -> V_12 . V_62 ||
( V_209 == V_210 && V_11 -> V_12 . V_60 != V_270 ) ) {
V_53 = F_135 ( V_402 , true ) ;
if ( V_53 != V_45 )
goto V_414;
}
}
#if F_14 ( F_65 )
if ( V_209 != V_407 ) {
V_53 = F_136 ( V_402 , & V_11 -> V_182 ) ;
if ( V_53 != V_45 )
goto V_414;
}
#elif F_14 ( F_21 )
if ( ( V_209 != V_407 ) &&
( V_402 -> V_12 . V_60 != V_63 ) ) {
V_53 = F_136 ( V_402 , & V_11 -> V_182 ) ;
if ( V_53 != V_45 )
goto V_414;
}
#endif
switch ( V_209 ) {
case V_210 :
V_195 = V_402 -> V_193 . V_194 . V_195 ;
V_403 = V_402 -> V_193 . V_194 . V_403 ;
V_404 = V_402 -> V_193 . V_194 . V_404 ;
V_413 =
V_402 -> V_193 . V_194 . V_415 . V_182 -> V_183 . V_184 . V_185 ;
V_53 = F_137 ( V_402 ) ;
if ( V_53 != V_45 )
goto V_414;
break;
case V_211 :
V_195 = V_402 -> V_193 . V_197 . V_195 ;
V_403 = V_402 -> V_193 . V_197 . V_403 ;
V_413 =
V_402 -> V_193 . V_197 . V_416 . V_182 -> V_183 . V_184 . V_185 ;
V_53 = F_138 ( V_402 ) ;
if ( V_53 != V_45 )
goto V_414;
break;
case V_406 :
V_403 = V_402 ;
break;
case V_412 :
V_53 = F_139 ( V_402 ) ;
if ( V_53 != V_45 )
goto V_414;
break;
case V_407 :
V_53 = F_140 ( V_402 ) ;
if ( V_53 != V_45 )
goto V_414;
break;
default:
V_53 = V_44 ;
}
if ( V_53 != V_45 )
goto V_414;
if( V_195 ) {
V_53 = F_141 ( V_195 , V_413 ,
V_402 -> V_417 [ 0 ] ) ;
if ( V_53 != V_45 )
goto V_414;
}
if( V_403 ) {
V_53 = F_142 ( V_403 ) ;
if ( V_53 != V_45 )
goto V_414;
}
if ( V_404 ) {
V_53 = F_140 ( V_404 ) ;
if ( V_53 != V_45 )
goto V_414;
}
if ( ! V_11 -> V_12 . V_62 ) {
int V_9 ;
for ( V_9 = 1 ; V_9 < V_11 -> V_278 && V_45 == V_53 ; V_9 ++ ) {
switch ( V_11 -> V_279 [ V_9 ] -> V_60 ) {
case V_210 :
V_53 = F_137 ( V_11 -> V_279 [ V_9 ] ) ;
break;
case V_211 :
V_53 = F_138 ( V_11 -> V_279 [ V_9 ] ) ;
break;
case V_406 :
V_53 = F_142 ( V_11 -> V_279 [ V_9 ] ) ;
break;
case V_412 :
V_53 = F_139 ( V_11 -> V_279 [ V_9 ] ) ;
break;
case V_407 :
V_53 = F_140 ( V_11 -> V_279 [ V_9 ] ) ;
break;
default:
V_53 = V_44 ;
}
if ( V_53 != V_45 )
goto V_414;
}
}
V_414:
F_130 ( V_53 ) ;
return V_53 ;
}
static enum V_4
F_143 ( enum V_418 V_60 ,
struct V_1 * V_2 ,
bool V_195 )
{
static struct V_1 V_419 = V_420 ;
static struct V_421 V_422 = V_423 ;
static struct V_424 V_425 = V_426 ;
static struct V_427 V_197 = V_428 ;
static struct V_429 V_430 = V_431 ;
if ( V_2 == NULL ) {
F_2 ( L_49 ) ;
return V_44 ;
}
* V_2 = V_419 ;
switch ( V_60 ) {
case V_192 :
V_2 -> V_60 = V_210 ;
V_2 -> V_193 . V_194 = V_422 ;
break;
case V_190 :
if ( V_195 ) {
V_2 -> V_60 = V_432 ;
} else {
V_2 -> V_60 = V_406 ;
}
V_2 -> V_193 . V_433 = V_425 ;
break;
case V_196 :
V_2 -> V_60 = V_211 ;
V_2 -> V_193 . V_197 = V_197 ;
break;
case V_434 :
V_2 -> V_60 = V_407 ;
break;
case V_63 :
V_2 -> V_60 = V_406 ;
break;
case V_191 :
V_2 -> V_60 = V_412 ;
V_2 -> V_193 . V_430 = V_430 ;
break;
default:
return V_44 ;
}
return V_45 ;
}
static void
F_85 ( void )
{
V_265 V_9 ;
V_328 . V_435 = 0 ;
for ( V_9 = 0 ; V_9 < V_436 ; V_9 ++ ) {
V_328 . V_437 [ V_9 ] = NULL ;
}
}
static enum V_4
F_144 ( const struct V_1 * V_2 , unsigned int * V_438 )
{
const V_265 V_439 = ( V_265 ) ~ ( 0 ) ;
V_265 V_405 = V_439 ;
V_265 V_9 ;
if ( V_2 == NULL ) {
F_2 ( L_49 ) ;
return V_44 ;
}
for ( V_9 = 0 ; V_9 < V_436 ; V_9 ++ ) {
if ( V_328 . V_437 [ V_9 ] == NULL ) {
V_328 . V_437 [ V_9 ] = (struct V_1 * ) V_2 ;
V_405 = V_9 ;
break;
}
}
if ( V_405 == V_439 ) {
F_2 ( L_50 ) ;
return V_440 ;
}
V_328 . V_435 ++ ;
F_94 ( L_51 , V_405 ) ;
* V_438 = V_405 ;
return V_45 ;
}
static void
F_145 ( unsigned int V_405 )
{
V_328 . V_437 [ V_405 ] = NULL ;
V_328 . V_435 -- ;
F_9 ( V_277 ,
L_52 , V_405 ) ;
}
static enum V_4
F_146 ( enum V_418 V_60 ,
struct V_1 * * V_2 ,
bool V_195 )
{
enum V_4 V_53 = V_45 ;
struct V_1 * V_260 ;
if ( V_2 == NULL ) {
F_2 ( L_49 ) ;
return V_44 ;
}
V_260 = F_122 ( sizeof( * V_260 ) , V_397 ) ;
if ( ! V_260 )
return V_441 ;
V_53 = F_143 ( V_60 , V_260 , V_195 ) ;
if ( V_53 != V_45 ) {
F_127 ( V_260 ) ;
return V_53 ;
}
V_53 = F_144 ( V_260 , & ( V_260 -> V_405 ) ) ;
if ( V_53 != V_45 ) {
F_127 ( V_260 ) ;
return V_53 ;
}
* V_2 = V_260 ;
return V_45 ;
}
struct V_1 *
F_147 ( V_143 V_405 )
{
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < V_436 ; V_9 ++ ) {
if ( V_328 . V_437 [ V_9 ] &&
F_30 ( V_328 . V_437 [ V_9 ] ) == V_405 ) {
return V_328 . V_437 [ V_9 ] ;
}
}
return NULL ;
}
static void F_148 (
struct V_1 * V_2 )
{
struct V_442 * V_55 ;
struct V_274 * V_275 ;
assert ( V_2 != NULL ) ;
if ( V_2 == NULL ) {
F_2 ( L_53 ) ;
return;
}
V_55 = & V_2 -> V_55 ;
for ( V_275 = V_55 -> V_56 ; V_275 ; V_275 = V_275 -> V_227 ) {
struct V_294 * V_443 = (struct V_294 * )
V_275 -> V_443 ;
if ( V_443 )
F_149 ( V_2 , V_443 ) ;
}
}
enum V_4
F_150 ( struct V_1 * V_2 )
{
enum V_4 V_53 = V_45 ;
F_84 ( L_54 , V_2 ) ;
if ( V_2 == NULL ) {
F_93 ( V_44 ) ;
return V_44 ;
}
if ( V_2 -> V_11 != NULL ) {
F_94 ( L_55 ) ;
F_93 ( V_44 ) ;
return V_44 ;
}
switch ( V_2 -> V_12 . V_60 ) {
case V_192 :
if ( V_2 -> V_60 == V_210 ) {
F_151 ( V_323 ,
V_2 -> V_417 ) ;
F_152 ( V_323 ,
V_2 -> V_444 ) ;
if ( V_2 -> V_193 . V_194 . V_195 ) {
V_53 = F_150 ( V_2 -> V_193 . V_194 . V_195 ) ;
F_9 ( V_277 , L_56
L_57 , V_53 ) ;
}
}
break;
case V_196 :
if ( V_2 -> V_60 == V_211 ) {
F_151 ( V_323 ,
V_2 -> V_417 ) ;
F_152 ( V_323 ,
V_2 -> V_444 ) ;
if ( V_2 -> V_193 . V_197 . V_195 ) {
V_53 = F_150 ( V_2 -> V_193 . V_197 . V_195 ) ;
F_9 ( V_277 , L_56
L_57 , V_53 ) ;
}
}
#ifndef F_58
F_151 ( V_249 , V_2 -> V_193 . V_197 . V_251 ) ;
#else
F_151 ( V_250 , V_2 -> V_193 . V_197 . V_251 ) ;
#endif
F_151 ( V_252 , V_2 -> V_193 . V_197 . V_253 ) ;
break;
case V_190 :
F_151 ( V_252 , V_2 -> V_193 . V_433 . V_253 ) ;
break;
case V_434 :
F_148 ( V_2 ) ;
break;
case V_63 :
break;
case V_191 :
break;
}
F_153 ( V_2 -> V_445 ) ;
V_2 -> V_445 = V_446 ;
V_328 . V_447 [ F_30 ( V_2 ) ] = NULL ;
F_1 ( V_2 ) ;
F_154 ( & V_2 -> V_55 ) ;
F_145 ( F_30 ( V_2 ) ) ;
if ( V_2 -> V_12 . V_448 ) {
F_149 ( V_2 , V_2 -> V_12 . V_448 ) ;
}
F_127 ( V_2 ) ;
F_155 ( L_58 , V_53 ) ;
return V_53 ;
}
void
F_111 ( void )
{
F_9 ( V_277 , L_59 ) ;
#if V_241
F_42 ( L_60 , V_242 ) ;
F_43 () ;
#endif
F_156 () ;
F_157 () ;
F_158 () ;
F_159 () ;
#if ! F_14 ( V_449 )
V_450 = true ;
#endif
if ( V_317 == false ) {
F_72 () ;
}
F_160 ( V_284 ) ;
F_161 ( false ) ;
#if F_14 ( F_65 ) || F_14 ( F_21 )
F_162 ( NULL ) ;
#endif
F_163 () ;
#if ! F_14 ( V_240 )
F_164 () ;
#endif
F_9 ( V_277 , L_61 ) ;
}
enum V_4 F_165 (
unsigned int * V_451 )
{
V_287 V_452 ;
enum V_453 V_454 = V_455 ;
unsigned int V_456 = 0 ;
F_9 ( V_277 , L_62 , V_451 ) ;
while ( V_454 == V_455 ) {
V_454 = F_166 ( & V_452 ) ;
if ( V_454 == V_457 )
return V_198 ;
#if V_241
F_42 ( L_63
L_64 , V_242 , V_452 ) ;
V_233 = 0 ;
#endif
switch ( V_452 ) {
case V_286 :
V_456 |= V_458 ;
break;
case V_459 :
break;
#if ! F_14 ( V_240 )
case V_460 :
V_456 |= V_461 ;
break;
case V_462 :
V_456 |= V_463 ;
break;
case V_464 :
V_456 |= V_465 ;
break;
#endif
#if ! F_14 ( V_449 )
case V_466 :
V_456 |= V_467 ;
break;
#endif
case V_468 :
V_456 |= V_469 ;
break;
case V_470 :
V_456 |= F_167 ( 0 ) ;
break;
case V_471 :
V_456 |= F_167 ( 1 ) ;
break;
default:
break;
}
}
if ( V_451 )
* V_451 = V_456 ;
F_9 ( V_277 , L_65
L_66 , V_456 ) ;
return V_45 ;
}
enum V_4 F_168 (
enum V_472 V_182 ,
bool V_158 )
{
V_287 V_452 = V_473 ;
F_84 ( L_67 , V_182 , V_158 ) ;
switch ( V_182 ) {
#if ! F_14 ( V_449 )
case V_461 :
V_452 = V_460 ;
break;
case V_463 :
V_452 = V_462 ;
break;
case V_465 :
V_452 = V_464 ;
break;
#endif
#if ! F_14 ( V_449 )
case V_467 :
V_452 = V_466 ;
break;
#endif
case V_469 :
V_452 = V_468 ;
break;
case V_474 :
V_452 = V_470 ;
break;
case V_475 :
V_452 = V_471 ;
break;
default:
F_93 ( V_44 ) ;
return V_44 ;
}
F_68 ( V_452 , V_158 ) ;
F_93 ( V_45 ) ;
return V_45 ;
}
void
F_169 ( struct V_51 * V_52 )
{
F_170 ( V_52 ) ;
}
static enum V_4
F_171 ( struct V_1 * V_2 )
{
F_60 ( L_54 , V_2 ) ;
if ( ( V_2 == NULL ) || ( V_2 -> V_60 != V_210 ) ) {
F_130 ( V_44 ) ;
return V_44 ;
}
F_169 ( & V_2 -> V_193 . V_194 . V_476 ) ;
F_169 ( & V_2 -> V_193 . V_194 . V_415 ) ;
F_169 ( & V_2 -> V_193 . V_194 . V_477 ) ;
F_130 ( V_45 ) ;
return V_45 ;
}
static const struct V_294 * F_172 (
const struct V_294 * V_295 )
{
const struct V_294 * V_478 = NULL ;
F_173 ( L_28 ) ;
for (; V_295 ; V_295 = V_295 -> V_227 ) {
const struct V_294 * V_182 = V_295 ;
if ( V_182 -> V_182 . V_479 . V_183 . V_158 . V_480 )
V_478 = V_295 ;
}
return V_478 ;
}
static enum V_4 F_174 (
struct V_442 * V_260 ,
struct V_51 * V_52 ,
const struct V_294 * V_295 ,
const struct V_294 * V_478 ,
unsigned int V_481 ,
struct V_246 * V_254 ,
struct V_246 * V_247 ,
struct V_246 * V_482 ,
struct V_274 * * V_483 ,
struct V_274 * * V_484 )
{
enum V_4 V_53 = V_45 ;
struct V_274 * V_485 = NULL ;
struct V_486 V_487 ;
F_9 ( V_54 ,
L_68 ) ;
for (; V_295 ; V_295 = V_295 -> V_227 ) {
struct V_246 * V_488 [ V_255 ] = { NULL } ;
struct V_246 * V_489 = NULL ;
struct V_246 * V_490 = NULL ;
if ( ( V_295 == V_478 ) && ( V_295 -> V_182 . V_479 . V_183 . V_158 . V_247 != 0 ) ) {
V_488 [ 0 ] = V_247 ;
}
if ( V_295 -> V_182 . V_479 . V_183 . V_158 . V_254 != 0 ) {
V_489 = V_254 ;
}
if ( V_295 -> V_182 . V_479 . V_183 . V_158 . V_247 != 0 ) {
V_490 = V_482 ;
}
F_175 ( & V_487 , V_52 ,
V_488 , V_489 , V_490 , V_295 , V_481 ) ;
V_53 = F_176 ( V_260 ,
& V_487 ,
& V_485 ) ;
if ( V_53 != V_45 )
return V_53 ;
if ( V_295 -> V_182 . V_479 . V_183 . V_158 . V_480 != 0 )
V_254 = V_485 -> args . V_247 [ 0 ] ;
if ( V_483 && ! * V_483 && V_485 )
* V_483 = V_485 ;
if ( V_484 && ! * V_484 && V_485 &&
V_295 -> V_182 . V_479 . V_183 . V_158 . V_491 )
* V_484 = V_485 ;
}
return V_53 ;
}
static enum V_4 F_177 (
struct V_1 * V_2 ,
struct V_246 * V_254 ,
struct V_246 * V_247 ,
struct V_51 * V_477 ,
struct V_274 * * V_492 )
{
struct V_442 * V_260 = NULL ;
const struct V_294 * V_478 = NULL ;
enum V_4 V_53 = V_45 ;
struct V_246 * V_493 [ V_255 ] ;
struct V_486 V_487 ;
if ( V_2 == NULL )
return V_44 ;
if ( V_254 == NULL )
return V_44 ;
if ( V_477 == NULL )
return V_44 ;
if ( V_492 == NULL )
return V_44 ;
F_178 ( V_493 ) ;
V_260 = & V_2 -> V_55 ;
F_9 ( V_54 ,
L_69 ) ;
* V_492 = NULL ;
V_478 = F_172 ( V_2 -> V_484 ) ;
if ( ! V_2 -> V_494 . V_495 ) {
if ( V_478 ) {
F_179 ( V_493 , 0 , NULL ) ;
F_180 ( & V_487 , V_477 ,
V_493 , V_254 , NULL ) ;
} else{
F_179 ( V_493 , 0 , V_247 ) ;
F_180 ( & V_487 , V_477 ,
V_493 , V_254 , NULL ) ;
}
V_53 = F_176 ( V_260 , & V_487 , V_492 ) ;
if ( V_53 != V_45 )
return V_53 ;
V_254 = ( * V_492 ) -> args . V_247 [ 0 ] ;
}
V_53 = F_174 ( V_260 , V_477 , V_2 -> V_484 , V_478 ,
V_229 ,
V_254 , V_247 , NULL ,
V_492 , NULL ) ;
return V_53 ;
}
static enum V_4 F_181 (
struct V_1 * V_2 ,
struct V_442 * V_260 ,
struct V_246 * V_254 ,
struct V_246 * V_247 ,
struct V_246 * V_496 ,
struct V_51 * V_497 ,
struct V_274 * * V_498 )
{
const struct V_294 * V_478 ;
enum V_4 V_53 = V_45 ;
struct V_246 * V_482 = NULL ;
struct V_246 * V_493 [ V_255 ] ;
struct V_486 V_487 ;
assert ( V_254 != NULL ) ;
assert ( V_2 != NULL ) ;
assert ( V_260 != NULL ) ;
assert ( V_497 != NULL ) ;
assert ( V_498 != NULL ) ;
F_9 ( V_54 ,
L_70 ) ;
* V_498 = NULL ;
F_178 ( V_493 ) ;
V_478 = F_172 ( V_2 -> V_499 ) ;
if( V_478 ) {
F_179 ( V_493 , 0 , NULL ) ;
F_180 ( & V_487 ,
V_497 , V_493 , V_254 , V_482 ) ;
} else {
F_179 ( V_493 , 0 , V_247 ) ;
F_179 ( V_493 , 1 , V_496 ) ;
F_180 ( & V_487 ,
V_497 , V_493 , V_254 , V_482 ) ;
}
V_53 = F_176 ( V_260 ,
& V_487 ,
V_498 ) ;
if ( V_53 != V_45 )
return V_53 ;
V_254 = ( * V_498 ) -> args . V_247 [ 0 ] ;
V_53 = F_174 ( V_260 , V_497 , V_2 -> V_499 , V_478 ,
V_500 ,
V_254 , V_247 , V_482 ,
NULL , V_498 ) ;
( * V_498 ) -> args . V_259 = V_497 -> V_259 ;
F_9 ( V_54 ,
L_71 ) ;
return V_53 ;
}
static enum V_4 F_182 (
struct V_1 * V_2 ,
struct V_442 * V_260 ,
struct V_246 * V_254 ,
struct V_246 * V_247 ,
struct V_51 * V_501 ,
struct V_274 * * V_502 )
{
const struct V_294 * V_478 = NULL ;
enum V_4 V_53 = V_45 ;
struct V_246 * V_482 = NULL ;
struct V_246 * V_493 [ V_255 ] ;
struct V_486 V_487 ;
assert ( V_254 != NULL ) ;
assert ( V_2 != NULL ) ;
assert ( V_260 != NULL ) ;
assert ( V_501 != NULL ) ;
assert ( V_502 != NULL ) ;
F_9 ( V_54 ,
L_72 ) ;
* V_502 = NULL ;
F_178 ( V_493 ) ;
V_478 = F_172 ( V_2 -> V_499 ) ;
V_53 = F_183 ( & V_482 ,
& V_501 -> V_503 ) ;
if ( V_53 != V_45 )
return V_53 ;
if( V_478 ) {
F_179 ( V_493 , 0 , NULL ) ;
F_180 ( & V_487 ,
V_501 , V_493 , NULL , V_482 ) ;
} else {
F_179 ( V_493 , 0 , V_247 ) ;
F_180 ( & V_487 ,
V_501 , V_493 , NULL , V_482 ) ;
}
V_53 = F_176 ( V_260 ,
& V_487 ,
V_502 ) ;
if ( V_53 != V_45 )
return V_53 ;
V_53 = F_174 ( V_260 , V_501 , V_2 -> V_499 , V_478 ,
V_500 ,
V_254 , V_247 , V_482 ,
NULL , V_502 ) ;
if ( * V_502 ) {
( * V_502 ) -> args . V_259 =
V_501 -> V_259 ;
}
return V_53 ;
}
static void F_184 ( void )
{
const struct V_294 * V_295 ;
unsigned int V_504 ;
F_185 () ;
F_186 () ;
V_295 = & V_378 ;
V_504 =
V_295 -> V_182 . V_183 . V_505 ;
F_187 () ;
F_188 ( V_284 ,
( unsigned int ) F_189 ( V_505 ) ,
( V_143 ) ( 1 ) ) ;
F_9 ( V_277 , L_73 ) ;
}
static enum V_4
F_190 ( struct V_1 * V_2 ,
struct V_246 * V_482 , unsigned int V_506 )
{
enum V_4 V_53 = V_45 ;
unsigned int V_507 ;
enum V_508 V_509 ;
assert ( V_482 != NULL ) ;
F_191 ( V_2 , & V_482 -> V_182 , V_506 ) ;
V_482 -> V_510 = false ;
V_482 -> V_511 = V_512 ;
F_29 ( F_30 ( V_2 ) , & V_507 ) ;
F_192 ( V_513 + V_506 , V_507 , & V_509 ) ;
V_482 -> V_514 = V_509 ;
V_482 -> V_515 = V_513 + V_506 ;
V_53 = F_193 ( V_482 ) ;
return V_53 ;
}
static unsigned int
F_194 (
const struct V_84 * V_12 )
{
assert ( V_12 != NULL ) ;
if ( ( V_516 == V_12 -> V_13 . V_517 )
|| ( V_518 == V_12 -> V_13 . V_517 ) )
return 1 ;
return 0 ;
}
static unsigned int
F_195 (
const struct V_84 * V_12 )
{
assert ( V_12 != NULL ) ;
if ( ( V_519 == V_12 -> V_13 . V_517 )
|| ( V_518 == V_12 -> V_13 . V_517 ) )
return 1 ;
return 0 ;
}
static void F_196 ( struct V_1 * V_2 ,
unsigned int * V_520 , unsigned int * V_521 )
{
enum V_208 V_209 = V_2 -> V_60 ;
unsigned int V_522 = 0 , V_523 = 0 ;
unsigned int V_9 ;
struct V_524 V_525 = V_2 -> V_12 . V_243 ;
switch ( V_209 ) {
case V_210 :
if ( V_2 -> V_193 . V_194 . V_415 . V_182 ) {
V_522 = V_2 -> V_193 . V_194 . V_415 . V_182 -> V_183 . V_55 . V_522 ;
V_523 = V_2 -> V_193 . V_194 . V_415 . V_182 -> V_183 . V_55 . V_523 ;
}
V_525 = V_2 -> V_193 . V_194 . V_415 . V_243 ;
break;
case V_211 :
if ( V_2 -> V_193 . V_197 . V_416 . V_182 ) {
V_522 = V_2 -> V_193 . V_197 . V_416 . V_182 -> V_183 . V_55 . V_522 ;
V_523 = V_2 -> V_193 . V_197 . V_416 . V_182 -> V_183 . V_55 . V_523 ;
}
V_525 = V_2 -> V_193 . V_197 . V_416 . V_243 ;
break;
case V_406 :
for ( V_9 = 0 ; V_9 < V_2 -> V_193 . V_433 . V_526 ; V_9 ++ ) {
if ( V_2 -> V_193 . V_433 . V_527 [ V_9 ] . V_182 ) {
V_522 += V_2 -> V_193 . V_433 . V_527 [ V_9 ] . V_182 -> V_183 . V_55 . V_522 ;
V_523 += V_2 -> V_193 . V_433 . V_527 [ V_9 ] . V_182 -> V_183 . V_55 . V_523 ;
}
V_525 . V_68 += V_2 -> V_193 . V_433 . V_527 [ V_9 ] . V_243 . V_68 ;
V_525 . V_69 += V_2 -> V_193 . V_433 . V_527 [ V_9 ] . V_243 . V_69 ;
}
break;
default:
break;
}
* V_520 = V_523 + V_525 . V_69 ;
* V_521 = V_522 + V_525 . V_68 ;
}
void
F_28 (
struct V_1 * V_2 ,
struct V_237 * V_254 )
{
unsigned int V_528 = 0 ;
unsigned int V_529 = 0 ;
struct V_524 * V_71 ;
struct V_524 * V_530 ;
unsigned int V_520 = 0 , V_531 = 0 ;
unsigned int V_532 , V_533 ;
assert ( V_2 != NULL ) ;
assert ( V_2 -> V_11 != NULL ) ;
assert ( V_254 != NULL ) ;
F_60 ( L_74 ,
V_2 , V_2 -> V_12 . V_534 . V_68 ,
V_2 -> V_12 . V_534 . V_69 ) ;
V_71 = & V_2 -> V_11 -> V_12 . V_13 . V_71 ;
#ifndef F_58
V_530 = & V_2 -> V_11 -> V_12 . V_13 . V_530 ;
#else
V_530 = & V_2 -> V_12 . V_534 ;
#endif
F_196 ( V_2 , & V_520 , & V_531 ) ;
V_254 -> V_535 = V_2 -> V_11 -> V_12 . V_13 . V_517 ;
V_532 = V_530 -> V_69 + V_520 ;
V_533 = V_530 -> V_68 + V_531 ;
if ( V_71 -> V_69 > V_532 ) {
V_528 = ( V_71 -> V_69 - V_532 ) / 2 ;
V_528 &= ~ 0x1 ;
}
if ( V_71 -> V_68 > V_533 ) {
V_529 = ( V_71 -> V_68 - V_533 ) / 2 ;
V_529 &= ~ 0x1 ;
}
V_529 += F_195 ( & V_2 -> V_11 -> V_12 ) ;
V_528 += F_194 ( & V_2 -> V_11 -> V_12 ) ;
V_254 -> V_536 . V_537 = V_529 ;
V_254 -> V_536 . V_538 = V_528 ;
F_62 ( L_75 , V_529 , V_528 ) ;
return;
}
static enum V_4
F_197 ( struct V_1 * V_2 ,
struct V_246 * V_539 , enum V_5 V_8 )
{
struct V_246 * V_254 ;
enum V_4 V_53 = V_45 ;
unsigned int V_507 ;
enum V_508 V_509 ;
assert ( V_539 != NULL ) ;
V_254 = V_539 ;
V_254 -> V_182 . V_8 = V_8 ;
#ifdef F_21
if ( V_8 == V_40 )
V_254 -> V_182 . V_8 = ( V_2 -> V_11 -> V_12 . V_173 ) ?
V_41 : V_40 ;
#endif
V_254 -> V_182 . V_239 . V_68 = V_2 -> V_11 -> V_12 . V_13 . V_71 . V_68 ;
V_254 -> V_182 . V_239 . V_69 = V_2 -> V_11 -> V_12 . V_13 . V_71 . V_69 ;
V_254 -> V_182 . V_540 =
F_198 ( V_2 ) ;
F_199 ( & V_254 -> V_182 , V_2 -> V_11 -> V_12 . V_13 . V_71 . V_68 , 0 ) ;
V_254 -> V_510 = false ;
V_254 -> V_511 = V_512 ;
F_29 ( F_30 ( V_2 ) , & V_507 ) ;
F_192 ( V_541 , V_507 , & V_509 ) ;
V_254 -> V_514 = V_509 ;
V_254 -> V_515 = V_541 ;
#ifdef F_21
F_28 ( V_2 , & V_254 -> V_182 ) ;
#endif
V_53 = F_193 ( V_254 ) ;
F_9 ( V_54 ,
L_76 , V_254 -> V_182 . V_535 ) ;
return V_53 ;
}
static enum V_4
F_200 ( struct V_1 * V_2 ,
struct V_246 * V_247 , unsigned int V_506 )
{
enum V_4 V_53 = V_45 ;
unsigned int V_507 ;
enum V_508 V_509 ;
assert ( V_247 != NULL ) ;
F_201 ( V_2 , & V_247 -> V_182 , V_506 ) ;
V_247 -> V_510 = false ;
V_247 -> V_511 = V_512 ;
F_29 ( F_30 ( V_2 ) , & V_507 ) ;
F_192 ( V_542 + V_506 , V_507 , & V_509 ) ;
V_247 -> V_514 = V_509 ;
V_247 -> V_515 = V_542 + V_506 ;
V_53 = F_193 ( V_247 ) ;
return V_53 ;
}
static enum V_4
F_140 ( struct V_1 * V_2 )
{
enum V_4 V_53 = V_45 ;
unsigned int V_9 ;
F_60 ( L_54 , V_2 ) ;
if ( ( V_2 == NULL ) || ( V_2 -> V_11 == NULL ) ) {
F_130 ( V_44 ) ;
return V_44 ;
}
V_2 -> V_55 . V_543 = V_2 -> V_12 . V_544 ;
if ( V_2 -> V_12 . V_448 )
V_2 -> V_55 . V_545 = 0 ;
{
const struct V_294 * V_295 = V_2 -> V_484 ;
for ( V_9 = 0 ; V_295 ; V_295 = V_295 -> V_227 ) {
V_53 = F_202 ( & V_2 -> V_55 , V_295 ) ;
if ( V_53 != V_45 )
goto V_414;
}
}
for ( V_9 = 0 ; V_9 < V_2 -> V_12 . V_546 ; V_9 ++ ) {
struct V_294 * V_295 = V_2 -> V_12 . V_547 [ V_9 ] ;
V_53 = F_202 ( & V_2 -> V_55 , V_295 ) ;
if ( V_53 != V_45 )
goto V_414;
}
F_203 ( & V_2 -> V_55 , V_2 -> V_11 -> V_12 . V_62 ) ;
V_414:
F_130 ( V_53 ) ;
return V_53 ;
}
static enum V_4
F_137 ( struct V_1 * V_2 )
{
struct V_274 * V_548 = NULL ;
struct V_274 * V_549 = NULL ;
struct V_274 * V_492 = NULL ;
struct V_486 V_487 ;
struct V_442 * V_260 = NULL ;
struct V_51 * V_476 , * V_415 , * V_477 = NULL ;
struct V_246 * V_254 = NULL ;
enum V_4 V_53 = V_45 ;
struct V_246 * V_247 ;
struct V_246 * V_493 [ V_255 ] ;
bool V_550 = false ;
#ifdef F_21
bool V_551 = false ;
bool V_552 = false ;
bool V_61 = false ;
bool V_62 = false ;
#endif
F_60 ( L_54 , V_2 ) ;
if ( ( V_2 == NULL ) || ( V_2 -> V_11 == NULL ) || ( V_2 -> V_60 != V_210 ) ) {
F_130 ( V_44 ) ;
return V_44 ;
}
F_178 ( V_493 ) ;
V_260 = & V_2 -> V_55 ;
F_204 ( V_260 ) ;
#ifdef F_21
V_551 = ( V_2 -> V_11 -> V_12 . V_60 == V_112 ) ;
V_552 = ( V_2 -> V_11 -> V_12 . V_60 == V_102 ) ;
V_61 = V_2 -> V_11 -> V_12 . V_61 ;
V_62 = V_2 -> V_11 -> V_12 . V_62 ;
V_550 =
! ( ( V_551 && ( V_61 || V_62 ) ) || ( V_552 && ( V_61 || V_62 ) ) ) ;
#else
V_550 = V_2 -> V_11 -> V_12 . V_60 == V_270 ;
#endif
if ( V_550 ) {
V_53 = F_197 ( V_2 , & V_260 -> V_254 , V_40 ) ;
if ( V_53 != V_45 )
goto V_414;
V_254 = & V_260 -> V_254 ;
} else {
V_254 = NULL ;
}
V_53 = F_200 ( V_2 , & V_260 -> V_247 [ 0 ] , 0 ) ;
if ( V_53 != V_45 )
goto V_414;
V_247 = & V_260 -> V_247 [ 0 ] ;
V_476 = & V_2 -> V_193 . V_194 . V_476 ;
V_415 = & V_2 -> V_193 . V_194 . V_415 ;
if ( V_2 -> V_193 . V_194 . V_477 . V_182 )
V_477 = & V_2 -> V_193 . V_194 . V_477 ;
if ( V_2 -> V_193 . V_194 . V_476 . V_182 ) {
F_179 ( V_493 , 0 , NULL ) ;
F_180 ( & V_487 , V_476 ,
V_493 , NULL , NULL ) ;
V_53 = F_176 ( V_260 ,
& V_487 ,
& V_548 ) ;
if ( V_53 != V_45 )
goto V_414;
V_254 = V_260 -> V_56 -> args . V_247 [ 0 ] ;
#ifndef F_58
} else {
#else
} else if ( V_2 -> V_11 -> V_12 . V_62 ) {
#endif
#ifdef F_21
if ( V_62 || ! V_61 ) {
V_254 = V_2 -> V_11 -> V_50 -> V_417 [ 0 ] ;
}
#else
V_254 = V_2 -> V_417 [ 0 ] ;
#endif
}
if ( V_477 ) {
F_179 ( V_493 , 0 , NULL ) ;
F_180 ( & V_487 , V_415 ,
V_493 , V_254 , NULL ) ;
} else {
F_179 ( V_493 , 0 , V_247 ) ;
F_180 ( & V_487 , V_415 ,
V_493 , V_254 , NULL ) ;
}
V_53 = F_176 ( V_260 ,
& V_487 ,
& V_549 ) ;
if ( V_53 != V_45 )
goto V_414;
V_549 -> args . V_257 =
V_415 -> V_182 -> V_183 . V_55 . V_60 == V_553 ;
V_549 -> args . V_258 = ! V_549 -> args . V_257 ;
if ( V_549 -> args . V_257 && ! V_549 -> args . V_256 ) {
V_549 -> args . V_256 =
V_549 -> args . V_247 [ 0 ] ;
}
if ( V_477 ) {
if ( V_415 -> V_182 -> V_183 . V_55 . V_60 == V_553 )
V_254 = V_549 -> args . V_256 ;
else
V_254 = V_549 -> args . V_247 [ 0 ] ;
V_53 = F_177 ( V_2 , V_254 , V_247 , V_477 ,
& V_492 ) ;
if ( V_53 != V_45 )
goto V_414;
}
V_2 -> V_55 . V_554 = false ;
F_203 ( & V_2 -> V_55 , V_2 -> V_11 -> V_12 . V_62 ) ;
V_414:
F_130 ( V_53 ) ;
return V_53 ;
}
static void F_205 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 -> V_12 . V_62 ) {
unsigned int V_9 ;
F_206
( V_2 -> V_11 -> V_12 . V_555 , true ) ;
F_206
( V_2 -> V_11 -> V_12 . V_556 , false ) ;
for ( V_9 = 0 ; V_9 < V_2 -> V_11 -> V_12 . V_555 ; V_9 ++ ) {
F_207 ( V_9 ,
V_2 -> V_417 [ V_9 ] , V_2 -> V_444 [ V_9 ] ) ;
}
}
return;
}
static enum V_4
F_208 ( struct V_1 * V_2 )
{
struct V_442 * V_260 ;
struct V_51 * V_476 , * V_415 , * V_477 = NULL ;
enum V_4 V_53 = V_45 ;
struct V_1 * V_195 , * V_403 ;
struct V_1 * V_404 ;
enum V_261 V_262 ;
enum V_263 V_557 ;
F_60 ( L_54 , V_2 ) ;
if ( ( V_2 == NULL ) || ( V_2 -> V_11 == NULL ) || ( V_2 -> V_60 != V_210 ) ) {
F_130 ( V_44 ) ;
return V_44 ;
}
V_260 = & V_2 -> V_55 ;
V_557 = V_2 -> V_11 -> V_12 . V_60 ;
V_195 = V_2 -> V_193 . V_194 . V_195 ;
V_403 = V_2 -> V_193 . V_194 . V_403 ;
V_404 = V_2 -> V_193 . V_194 . V_404 ;
V_476 = & V_2 -> V_193 . V_194 . V_476 ;
V_415 = & V_2 -> V_193 . V_194 . V_415 ;
if ( V_2 -> V_193 . V_194 . V_477 . V_182 )
V_477 = & V_2 -> V_193 . V_194 . V_477 ;
F_209 () ;
#if F_14 ( F_65 ) || F_14 ( F_21 )
V_53 = F_210 ( V_2 ) ;
if ( V_53 != V_45 )
goto V_414;
#endif
F_205 ( V_2 ) ;
{
unsigned int V_507 ;
F_29 ( F_30 ( V_2 ) , & V_507 ) ;
V_262 = 1 << V_507 ;
if ( V_2 -> V_11 -> V_558 ) {
F_29 ( F_30 ( V_403 ) , & V_507 ) ;
V_262 |= 1 << V_507 ;
}
}
if ( V_2 -> V_11 -> V_12 . V_62 ) {
F_61 (&copy_pipe->pipeline,
IA_CSS_PIPE_ID_COPY,
(uint8_t)ia_css_pipe_get_pipe_num(copy_pipe),
false,
pipe->stream->config.pixels_per_clock == 2 , false,
false, pipe->required_bds_factor,
copy_ovrd,
pipe->stream->config.mode,
&pipe->stream->config.metadata_config,
#ifndef F_58
&pipe->stream->info.metadata_info
#else
&pipe->stream->info.metadata_info,
#endif
#if ! F_14 ( V_240 )
#ifndef F_58
, pipe->stream->config.source.port.port
#else
pipe->stream->config.source.port.port,
#endif
#endif
#ifndef F_58
) ;
#else
& V_2 -> V_12 . V_272 ,
V_2 -> V_11 -> V_273 ) ;
#endif
V_557 = V_270 ;
}
V_4
F_211 ( struct V_1 * V_2 ,
const struct V_559 * V_560 )
{
enum V_4 V_561 = V_45 ;
unsigned int V_507 ;
enum V_508 V_509 ;
struct V_442 * V_55 ;
struct V_274 * V_275 ;
struct V_562 V_563 ;
struct V_562 * V_564 ;
struct V_347 V_565 ;
enum V_566 V_515 ;
enum V_208 V_209 ;
bool V_567 ;
F_84 ( L_77 , V_2 , V_560 ) ;
if ( ( V_2 == NULL ) || ( V_560 == NULL ) ) {
F_93 ( V_44 ) ;
return V_44 ;
}
V_515 = V_560 -> type ;
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
V_209 = V_2 -> V_60 ;
F_94 ( L_78 , V_209 , V_515 ) ;
assert ( V_209 < V_568 ) ;
assert ( V_515 < V_569 ) ;
if ( ( V_515 == V_570 ) ||
( V_515 >= V_569 ) ||
( V_209 >= V_568 ) ) {
F_93 ( V_198 ) ;
return V_198 ;
}
V_567 = F_29 ( F_30 ( V_2 ) , & V_507 ) ;
if ( ! V_567 ) {
F_93 ( V_44 ) ;
return V_44 ;
}
V_567 = F_192 ( V_515 , V_507 , & V_509 ) ;
if ( ! V_567 ) {
F_93 ( V_44 ) ;
return V_44 ;
}
if ( ( V_509 <= V_571 ) || ( V_509 >= V_572 ) ) {
F_93 ( V_44 ) ;
return V_44 ;
}
if ( ! F_118 () ) {
F_94 ( L_79 ) ;
F_93 ( V_395 ) ;
return V_395 ;
}
V_55 = & V_2 -> V_55 ;
assert ( V_55 != NULL ||
V_209 == V_432 ||
V_209 == V_407 ) ;
assert ( sizeof( NULL ) <= sizeof( V_565 . V_573 ) ) ;
V_565 . V_573 = F_212 ( NULL ) ;
V_565 . V_574 = V_560 -> V_575 ;
V_565 . V_576 = V_560 -> V_576 ;
if ( V_515 == V_577 ) {
if ( V_560 -> V_232 . V_578 == NULL ) {
F_93 ( V_44 ) ;
return V_44 ;
}
V_565 . V_573 = F_212 ( V_560 -> V_232 . V_578 ) ;
V_565 . V_579 . V_580 = * V_560 -> V_232 . V_578 ;
} else if ( V_515 == V_581 ) {
if ( V_560 -> V_232 . V_582 == NULL ) {
F_93 ( V_44 ) ;
return V_44 ;
}
V_565 . V_573 = F_212 ( V_560 -> V_232 . V_582 ) ;
V_565 . V_579 . V_583 = * V_560 -> V_232 . V_582 ;
} else if ( V_515 == V_584 ) {
if ( V_560 -> V_232 . V_157 == NULL ) {
F_93 ( V_44 ) ;
return V_44 ;
}
V_565 . V_573 = F_212 ( V_560 -> V_232 . V_157 ) ;
V_565 . V_579 . V_157 = * V_560 -> V_232 . V_157 ;
} else if ( ( V_515 == V_541 )
|| ( V_515 == V_542 )
|| ( V_515 == V_513 )
|| ( V_515 == V_585 )
|| ( V_515 == V_586 ) ) {
if ( V_560 -> V_232 . V_539 == NULL ) {
F_93 ( V_44 ) ;
return V_44 ;
}
V_565 . V_573 = F_212 ( V_560 -> V_232 . V_539 ) ;
V_565 . V_579 . V_539 . V_587 = V_560 -> V_232 . V_539 -> V_232 ;
V_565 . V_579 . V_539 . V_588 = 0 ;
F_9 ( V_277 ,
L_80 ,
V_515 , V_560 -> V_232 . V_539 -> V_232 ) ;
#if F_213 ()
V_561 = F_214 (
& V_560 -> V_232 . V_539 -> V_182 ,
& V_565 . V_579 . V_539 ) ;
if ( V_45 != V_561 ) {
F_93 ( V_561 ) ;
return V_561 ;
}
#endif
}
V_563 . V_589 = 0 ;
V_563 . V_590 = 0 ;
V_563 . V_314 = sizeof( struct V_347 ) ;
V_564 = & V_563 ;
F_215 ( V_591 , & V_564 ) ;
assert ( V_564 != NULL ) ;
assert ( V_564 -> V_589 != 0x0 ) ;
if ( ( V_564 == NULL ) || ( V_564 -> V_589 == 0x0 ) ) {
F_93 ( V_198 ) ;
return V_198 ;
}
F_216 ( V_564 -> V_589 ,
( void * ) ( & V_565 ) ,
sizeof( struct V_347 ) ) ;
if ( ( V_515 == V_577 )
|| ( V_515 == V_581 )
|| ( V_515 == V_592 ) ) {
if ( V_55 == NULL ) {
F_217 ( V_591 , & V_564 ) ;
F_94 ( L_81 ) ;
F_93 ( V_198 ) ;
return V_198 ;
}
for ( V_275 = V_55 -> V_56 ; V_275 ; V_275 = V_275 -> V_227 ) {
if ( F_218 ( V_275 ) ) {
V_561 = F_219 ( V_507 ,
V_509 ,
( V_143 ) V_564 -> V_589 ) ;
}
}
} else if ( ( V_515 == V_541 )
|| ( V_515 == V_542 )
|| ( V_515 == V_513 )
|| ( V_515 == V_585 )
|| ( V_515 == V_586 )
|| ( V_515 == V_584 ) ) {
V_561 = F_219 ( V_507 ,
V_509 ,
( V_143 ) V_564 -> V_589 ) ;
#if F_14 ( V_593 )
if ( ( V_561 == V_45 ) && ( V_542 == V_515 ) ) {
F_94 ( L_82 ,
V_565 . V_579 . V_539 . V_587 ,
V_509 , V_507 ) ;
}
#endif
}
if ( V_561 == V_45 ) {
if ( F_220 (
V_564 , V_515 ,
F_212 ( V_565 . V_573 ) ) ) {
F_94 ( L_83 , V_564 ) ;
} else {
V_561 = V_198 ;
F_2 ( L_84 ) ;
}
}
if ( V_561 == V_45 ) {
if ( ! F_118 () ) {
F_94 ( L_79 ) ;
F_93 ( V_395 ) ;
return V_395 ;
}
V_561 = F_221 (
V_594 ,
( V_265 ) V_507 ,
V_509 ,
0 ) ;
} else {
F_217 ( V_591 , & V_564 ) ;
F_2 ( L_85 ) ;
}
F_155 ( L_86 , V_561 ) ;
return V_561 ;
}
enum V_4
F_222 ( struct V_1 * V_2 ,
struct V_559 * V_560 )
{
enum V_4 V_561 ;
enum V_508 V_509 ;
T_5 V_595 = ( T_5 ) 0 ;
struct V_347 V_565 ;
enum V_566 V_515 ;
enum V_208 V_209 ;
unsigned int V_507 ;
T_6 V_573 = 0 ;
bool V_567 ;
F_84 ( L_77 , V_2 , V_560 ) ;
if ( ( V_2 == NULL ) || ( V_560 == NULL ) ) {
F_93 ( V_44 ) ;
return V_44 ;
}
V_209 = V_2 -> V_60 ;
V_515 = V_560 -> type ;
F_94 ( L_78 , V_209 , V_515 ) ;
V_565 . V_573 = 0 ;
V_567 = F_29 ( F_30 ( V_2 ) , & V_507 ) ;
if ( ! V_567 ) {
F_93 ( V_44 ) ;
return V_44 ;
}
V_567 = F_192 ( V_515 , V_507 , & V_509 ) ;
if ( ! V_567 ) {
F_93 ( V_44 ) ;
return V_44 ;
}
if ( ( V_509 <= V_571 ) || ( V_509 >= V_572 ) ) {
F_93 ( V_44 ) ;
return V_44 ;
}
if ( ! F_118 () ) {
F_94 ( L_79 ) ;
F_93 ( V_395 ) ;
return V_395 ;
}
V_561 = F_223 ( V_509 ,
( V_143 * ) & V_595 ) ;
if ( V_561 == V_45 ) {
struct V_246 * V_539 ;
struct V_596 * V_597 = NULL ;
F_94 ( L_87 , ( int ) V_595 ) ;
V_597 = F_224 (
V_595 , V_515 ) ;
if ( V_597 != NULL ) {
V_573 = V_597 -> V_573 ;
F_217 ( V_591 , & V_597 -> V_564 ) ;
F_225 ( V_597 ) ;
} else {
F_2 ( L_88 ,
V_595 , V_515 ) ;
F_93 ( V_198 ) ;
return V_198 ;
}
F_226 ( V_595 ,
& V_565 ,
sizeof( struct V_347 ) ) ;
if ( ( V_565 . V_573 == 0 ) ||
( V_573 != F_212 ( V_565 . V_573 ) ) ) {
F_2 ( L_89 ) ;
F_2 ( L_90 , ( V_598 ) V_573 ) ;
F_2 ( L_91 , ( V_598 ) F_212 ( V_565 . V_573 ) ) ;
F_2 ( L_92 , V_515 ) ;
F_93 ( V_198 ) ;
return V_198 ;
}
if ( V_565 . V_573 != 0 ) {
V_560 -> V_599 = 0 ;
V_560 -> V_575 = V_565 . V_574 ;
V_560 -> V_576 = V_565 . V_576 ;
if ( ( V_515 == V_542 ) ||
( V_515 == V_513 ) ) {
V_560 -> V_600 . V_601 = V_565 . V_600 ;
}
switch ( V_515 ) {
case V_541 :
case V_542 :
case V_585 :
if ( ( V_2 ) && ( V_2 -> V_602 == true ) )
{
#if F_14 ( F_65 )
V_561 = F_162 ( V_2 ) ;
if ( V_561 != V_45 ) {
F_94 ( L_93 ) ;
F_93 ( V_561 ) ;
return V_561 ;
}
#endif
V_2 -> V_602 = false ;
}
case V_513 :
case V_586 :
V_539 = (struct V_246 * ) F_212 ( V_565 . V_573 ) ;
V_560 -> V_232 . V_539 = V_539 ;
V_560 -> V_599 = V_565 . V_579 . V_539 . V_599 ;
V_539 -> V_599 = V_565 . V_579 . V_539 . V_599 ;
V_539 -> V_603 = V_565 . V_579 . V_539 . V_604 ;
if ( V_565 . V_579 . V_539 . V_588 == 1 )
V_539 -> V_511 =
V_605 ;
if ( V_565 . V_579 . V_539 . V_588 == 2 )
V_539 -> V_511 =
V_606 ;
V_539 -> V_205 = V_2 -> V_607 == 0 ;
if ( ! V_539 -> V_205 )
V_2 -> V_607 -- ;
if ( V_539 -> V_182 . V_8 == V_43 ) {
#ifdef F_21
V_539 -> V_608 . V_52 . V_314 = V_539 -> V_609 ;
#else
V_539 -> V_608 . V_52 . V_314 =
F_227 () ;
#endif
}
#if F_14 ( V_593 )
if ( V_542 == V_515 ) {
F_94 ( L_94 ,
V_539 -> V_232 , V_539 -> V_603 , V_507 ) ;
}
#endif
F_9 ( V_277 ,
L_95 ,
V_515 , V_560 -> V_232 . V_539 -> V_232 ) ;
break;
case V_577 :
V_560 -> V_232 . V_578 =
(struct V_349 * ) F_212 ( V_565 . V_573 ) ;
V_560 -> V_599 = V_565 . V_579 . V_580 . V_599 ;
V_560 -> V_232 . V_578 -> V_599 = V_565 . V_579 . V_580 . V_599 ;
V_560 -> V_232 . V_578 -> V_603 = V_565 . V_579 . V_580 . V_603 ;
break;
case V_581 :
V_560 -> V_232 . V_582 =
(struct V_351 * )
F_212 ( V_565 . V_573 ) ;
V_560 -> V_599 = V_565 . V_579 . V_583 . V_599 ;
V_560 -> V_232 . V_582 -> V_599 = V_565 . V_579 . V_583 . V_599 ;
break;
case V_592 :
break;
case V_584 :
V_560 -> V_232 . V_157 =
(struct V_353 * ) F_212 ( V_565 . V_573 ) ;
V_560 -> V_599 = V_565 . V_579 . V_157 . V_599 ;
V_560 -> V_232 . V_157 -> V_599 = V_565 . V_579 . V_157 . V_599 ;
break;
default:
V_561 = V_198 ;
break;
}
}
}
if ( V_561 == V_45 ) {
if ( ! F_118 () ) {
F_94 ( L_79 ) ;
F_93 ( V_395 ) ;
return V_395 ;
}
F_221 (
V_610 ,
0 ,
V_509 ,
0 ) ;
}
F_155 ( L_96 , V_560 ) ;
return V_561 ;
}
enum V_4
F_228 ( struct V_611 * V_612 )
{
return F_229 ( V_612 ) ;
}
enum V_4
F_229 ( struct V_611 * V_612 )
{
enum V_208 V_209 = 0 ;
V_265 V_579 [ 4 ] = { 0 , 0 , 0 , 0 } ;
enum V_4 V_567 ;
if ( V_612 == NULL )
return V_44 ;
if ( ! F_118 () ) {
return V_395 ;
}
V_567 = F_230 ( V_579 ) ;
if ( V_567 != V_45 )
return V_567 ;
F_94 ( L_97 ) ;
F_221 (
V_613 , 0 , 0 , 0 ) ;
V_612 -> type = V_614 [ V_579 [ 0 ] ] ;
V_612 -> V_2 = NULL ;
V_612 -> V_103 = V_104 ;
V_612 -> V_599 = 0 ;
V_612 -> V_615 = V_616 ;
V_612 -> V_617 = 0 ;
V_612 -> V_618 = 0 ;
V_612 -> V_619 = 0 ;
V_612 -> V_620 = 0 ;
if ( V_612 -> type == V_621 ) {
V_143 V_622 ;
V_612 -> V_618 = ( ( V_579 [ 1 ] & 0xFF ) | ( ( V_579 [ 3 ] & 0xFF ) << 8 ) ) ;
V_612 -> V_619 = V_579 [ 2 ] ;
V_579 [ 0 ] = V_579 [ 1 ] = V_579 [ 2 ] = V_579 [ 3 ] = 0 ;
V_567 = F_230 ( V_579 ) ;
if ( V_567 != V_45 ) {
F_231 ( L_98 ) ;
return V_567 ;
}
F_221 (
V_613 , 0 , 0 , 0 ) ;
V_612 -> type = V_614 [ V_579 [ 0 ] ] ;
if ( V_612 -> type == V_621 ) {
V_622 = ( ( V_579 [ 1 ] & 0xFF ) | ( ( V_579 [ 3 ] & 0xFF ) << 8 ) ) ;
V_612 -> V_618 |= ( V_622 << 16 ) ;
V_612 -> V_620 = V_579 [ 2 ] ;
}
else {
V_612 -> V_618 = 0 ;
V_612 -> V_619 = 0 ;
V_612 -> V_620 = 0 ;
F_2 ( L_99 ) ;
}
}
if ( V_612 -> type == V_623 ) {
V_612 -> V_103 = (enum V_624 ) V_579 [ 1 ] ;
V_612 -> V_599 = V_579 [ 3 ] ;
} else if ( V_612 -> type == V_625 ) {
V_612 -> V_615 = (enum V_626 ) V_579 [ 1 ] ;
if ( V_612 -> V_615 == V_627 ||
V_612 -> V_615 == V_628 )
V_612 -> V_599 = V_579 [ 3 ] ;
} else if ( V_612 -> type == V_629 ) {
V_612 -> V_630 = V_579 [ 1 ] ;
V_612 -> V_631 = ( V_579 [ 2 ] << 8 ) + V_579 [ 3 ] ;
} else if ( V_612 -> type != V_621 ) {
V_612 -> V_2 = F_147 ( V_579 [ 1 ] ) ;
V_209 = (enum V_208 ) V_579 [ 2 ] ;
if ( ! V_612 -> V_2 )
return V_395 ;
if ( V_612 -> type == V_632 ) {
int V_9 , V_633 ;
V_633 = V_612 -> V_2 -> V_11 -> V_278 ;
for ( V_9 = 0 ; V_9 < V_633 ; V_9 ++ ) {
struct V_1 * V_399 =
V_612 -> V_2 -> V_11 -> V_279 [ V_9 ] ;
if ( V_399 -> V_12 . V_60 == V_190 ) {
V_612 -> V_2 = V_399 ;
break;
}
}
V_612 -> V_599 = V_579 [ 3 ] ;
}
if ( V_612 -> type == V_634 ) {
V_143 V_635 = ( V_143 ) V_579 [ 3 ] ;
V_567 = F_232 (
& ( V_612 -> V_2 -> V_55 ) ,
V_635 ,
& ( V_612 -> V_617 ) ) ;
if ( V_567 != V_45 ) {
F_2 ( L_100 ,
V_635 ) ;
return V_567 ;
}
}
}
if ( V_612 -> V_2 )
F_155 ( L_101 , V_612 -> type , V_209 ) ;
else
F_155 ( L_102 , V_612 -> type ) ;
return V_45 ;
}
enum V_4
F_233 ( struct V_611 * V_612 )
{
V_265 V_579 [ 4 ] = { 0 , 0 , 0 , 0 } ;
enum V_4 V_53 = V_45 ;
if ( V_612 == NULL )
return V_44 ;
if ( ! F_118 () ) {
return V_395 ;
}
V_53 = F_234 ( V_579 ) ;
if ( V_53 != V_45 )
return V_53 ;
F_94 ( L_103 ) ;
F_235 ( V_636 ) ;
V_612 -> type = V_623 ;
V_612 -> V_2 = NULL ;
V_612 -> V_103 = V_579 [ 1 ] ;
V_612 -> V_599 = V_579 [ 3 ] ;
F_93 ( V_53 ) ;
return V_53 ;
}
static void
F_236 ( struct V_1 * V_2 )
{
assert ( V_2 != NULL ) ;
assert ( V_2 -> V_11 != NULL ) ;
F_59 ( V_2 , V_637 ,
V_2 -> V_11 -> V_12 . V_60 ) ;
}
static enum V_4
F_237 ( struct V_46 * V_11 )
{
enum V_4 V_53 = V_45 ;
struct V_1 * V_2 ;
enum V_208 V_209 ;
unsigned int V_507 ;
F_60 ( L_48 , V_11 ) ;
if ( V_11 == NULL ) {
F_93 ( V_44 ) ;
return V_44 ;
}
V_2 = V_11 -> V_50 ;
if ( V_2 == NULL ) {
F_93 ( V_44 ) ;
return V_44 ;
}
V_209 = V_2 -> V_60 ;
if( V_11 -> V_638 == true ) {
F_231 ( L_104 ) ;
F_93 ( V_53 ) ;
return V_53 ;
}
V_2 -> V_602 = false ;
switch ( V_209 ) {
case V_210 :
V_53 = F_208 ( V_2 ) ;
break;
case V_211 :
V_53 = F_238 ( V_2 ) ;
break;
case V_406 :
V_53 = F_239 ( V_2 ) ;
break;
case V_412 :
V_53 = F_240 ( V_2 ) ;
break;
case V_407 :
F_236 ( V_2 ) ;
break;
default:
V_53 = V_44 ;
}
if ( ! V_11 -> V_12 . V_62 ) {
int V_9 ;
for ( V_9 = 1 ; V_9 < V_11 -> V_278 && V_45 == V_53 ; V_9 ++ ) {
switch ( V_11 -> V_279 [ V_9 ] -> V_60 ) {
case V_210 :
V_11 -> V_279 [ V_9 ] -> V_602 = false ;
V_53 = F_208 ( V_11 -> V_279 [ V_9 ] ) ;
break;
case V_211 :
V_11 -> V_279 [ V_9 ] -> V_602 = false ;
V_53 = F_238 ( V_11 -> V_279 [ V_9 ] ) ;
break;
case V_406 :
V_11 -> V_279 [ V_9 ] -> V_602 = false ;
V_53 = F_239 ( V_11 -> V_279 [ V_9 ] ) ;
break;
case V_412 :
V_11 -> V_279 [ V_9 ] -> V_602 = false ;
V_53 = F_240 ( V_11 -> V_279 [ V_9 ] ) ;
break;
case V_407 :
V_11 -> V_279 [ V_9 ] -> V_602 = false ;
F_236 ( V_11 -> V_279 [ V_9 ] ) ;
break;
default:
V_53 = V_44 ;
}
}
}
if ( V_53 != V_45 ) {
F_130 ( V_53 ) ;
return V_53 ;
}
if ( ! F_241 ( V_2 ) ) {
F_242 ( V_11 ) ;
V_53 = F_243 ( V_2 ,
V_11 -> V_273 , true , NULL ) ;
if ( V_53 != V_45 ) {
F_130 ( V_53 ) ;
return V_53 ;
}
}
F_244 () ;
F_29 ( F_30 ( V_2 ) , & V_507 ) ;
if ( ! F_118 () ) {
F_130 ( V_395 ) ;
return V_395 ;
}
F_221 ( V_639 ,
( V_265 ) V_507 , 0 , 0 ) ;
if ( ! V_11 -> V_12 . V_62 ) {
int V_9 ;
for ( V_9 = 1 ; V_9 < V_11 -> V_278 ; V_9 ++ ) {
F_29 (
F_30 ( V_11 -> V_279 [ V_9 ] ) ,
& V_507 ) ;
F_221 (
V_639 ,
( V_265 ) V_507 , 0 , 0 ) ;
}
}
if ( V_2 -> V_11 -> V_12 . V_62 ) {
struct V_1 * V_195 = NULL ;
if ( V_209 == V_210 )
V_195 = V_2 -> V_193 . V_194 . V_195 ;
else if ( V_209 == V_211 )
V_195 = V_2 -> V_193 . V_197 . V_195 ;
if ( V_195 == NULL ) {
F_130 ( V_198 ) ;
return V_198 ;
}
F_29 ( F_30 ( V_195 ) , & V_507 ) ;
F_221 (
V_639 ,
( V_265 ) V_507 , 0 , 0 ) ;
}
if ( V_2 -> V_11 -> V_558 ) {
struct V_1 * V_403 = NULL ;
if ( V_209 == V_210 )
V_403 = V_2 -> V_193 . V_194 . V_403 ;
else if ( V_209 == V_211 )
V_403 = V_2 -> V_193 . V_197 . V_403 ;
if ( V_403 == NULL ) {
F_130 ( V_198 ) ;
return V_198 ;
}
F_29 ( F_30 ( V_403 ) , & V_507 ) ;
F_221 (
V_639 ,
( V_265 ) V_507 , 0 , 0 ) ;
}
if ( V_209 == V_210 ) {
struct V_1 * V_404 = NULL ;
V_404 = V_2 -> V_193 . V_194 . V_404 ;
if ( V_404 ) {
F_29 ( F_30 ( V_404 ) , & V_507 ) ;
F_221 (
V_639 ,
( V_265 ) V_507 , 0 , 0 ) ;
}
}
V_11 -> V_638 = true ;
F_130 ( V_53 ) ;
return V_53 ;
}
void
F_245 ( bool V_158 , bool V_640 )
{
F_9 ( V_277 ,
L_105 , V_158 ) ;
V_328 . V_640 = V_640 ;
}
enum V_4
F_246 ( struct V_46 * V_11 , int * V_641 )
{
if ( V_641 == NULL )
return V_44 ;
F_9 ( V_277 , L_106 ) ;
( void ) V_11 ;
* V_641 = V_323 ;
return V_45 ;
}
enum V_4
F_247 ( struct V_46 * V_11 , int V_641 )
{
F_9 ( V_277 , L_107 , V_641 ) ;
( void ) V_11 ;
if ( V_641 > V_323 || V_641 < 1 )
return V_44 ;
V_11 -> V_12 . V_556 = V_641 ;
return V_45 ;
}
enum V_4
F_248 ( struct V_46 * V_11 , int * V_641 )
{
if ( V_641 == NULL )
return V_44 ;
F_9 ( V_277 , L_108 ) ;
#else
if ( V_53 != V_45 ) {
goto V_414;
}
}
static bool
F_249 ( struct V_46 * V_11 )
{
bool V_75 = true ;
struct V_1 * V_402 ;
enum V_208 V_642 ;
int V_9 ;
assert ( V_11 != NULL ) ;
if ( V_11 == NULL ) {
F_94 ( L_109 ) ;
V_75 = false ;
goto V_643;
}
V_402 = V_11 -> V_50 ;
assert ( V_402 != NULL ) ;
if ( V_402 == NULL ) {
F_94 ( L_110 ) ;
V_75 = false ;
goto V_643;
}
V_642 = V_402 -> V_60 ;
F_60 ( L_111 , V_642 ) ;
for ( V_9 = 0 ; V_9 < V_11 -> V_278 ; V_9 ++ ) {
V_75 = V_75 && F_250 ( & V_11 -> V_279 [ V_9 ] -> V_55 ) ;
F_94 ( L_112 ,
V_11 -> V_279 [ V_9 ] -> V_55 . V_209 ,
V_75 ) ;
}
if ( V_402 -> V_11 -> V_12 . V_62 ) {
struct V_1 * V_195 = NULL ;
if ( V_642 == V_210 )
V_195 = V_402 -> V_193 . V_194 . V_195 ;
else if ( V_642 == V_211 )
V_195 = V_402 -> V_193 . V_197 . V_195 ;
assert ( V_195 != NULL ) ;
if ( V_195 == NULL ) {
F_94 ( L_113 ) ;
V_75 = false ;
goto V_643;
}
V_75 = V_75 && F_250 ( & V_195 -> V_55 ) ;
F_94 ( L_112 ,
V_195 -> V_55 . V_209 ,
V_75 ) ;
}
V_643:
F_62 ( L_114 , V_75 ) ;
return V_75 ;
}
bool
F_251 ( V_265 V_405 )
{
struct V_1 * V_2 ;
bool V_62 ;
F_9 ( V_277 , L_115 , V_405 ) ;
V_2 = F_147 ( V_405 ) ;
V_62 = V_2 && V_2 -> V_11 -> V_12 . V_62 ;
F_9 ( V_277 ,
L_116 ,
V_62 ) ;
return V_62 ;
}
enum V_4
F_246 ( struct V_46 * V_11 , int * V_641 )
{
if ( V_641 == NULL )
return V_44 ;
F_9 ( V_277 , L_106 ) ;
( void ) V_11 ;
* V_641 = V_323 ;
return V_45 ;
}
enum V_4
F_247 ( struct V_46 * V_11 , int V_641 )
{
F_9 ( V_277 , L_107 , V_641 ) ;
( void ) V_11 ;
if ( V_641 > V_323 || V_641 < 1 )
return V_44 ;
V_11 -> V_12 . V_556 = V_641 ;
return V_45 ;
}
enum V_4
F_248 ( struct V_46 * V_11 , int * V_641 )
{
if ( V_641 == NULL )
return V_44 ;
F_9 ( V_277 , L_108 ) ;
#endif
( void ) V_11 ;
* V_641 = V_11 -> V_12 . V_556 ;
return V_45 ;
}
unsigned int
F_252 ( const unsigned int V_103 , const unsigned int V_506 )
{
F_253 ( V_103 < V_644 ) ;
F_253 ( V_506 < V_645 ) ;
F_9 ( V_54 , L_117 ,
V_103 , V_506 , V_328 . V_646 [ V_103 ] [ V_506 ] ) ;
return V_328 . V_646 [ V_103 ] [ V_506 ] ;
}
static enum V_4 F_254 (
struct V_1 * V_2 ,
unsigned int V_68 ,
unsigned int V_69 ,
unsigned int V_647 ,
enum V_5 V_8 ,
unsigned int V_506 )
{
enum V_4 V_53 = V_45 ;
F_60 ( L_118 ,
V_2 , V_68 , V_69 , V_647 , V_8 , V_506 ) ;
if ( V_2 == NULL ) {
F_130 ( V_44 ) ;
return V_44 ;
}
V_53 = F_255 ( V_68 , V_69 ) ;
if ( V_53 != V_45 ) {
F_130 ( V_53 ) ;
return V_53 ;
}
if ( V_2 -> V_7 [ V_506 ] . V_239 . V_68 != V_68 ||
V_2 -> V_7 [ V_506 ] . V_239 . V_69 != V_69 ||
V_2 -> V_7 [ V_506 ] . V_8 != V_8 )
{
F_256 (
& V_2 -> V_7 [ V_506 ] ,
V_68 ,
V_69 ,
V_8 ,
V_647 ) ;
}
F_130 ( V_45 ) ;
return V_45 ;
}
enum V_4
F_257 ( struct V_1 * V_2 ,
struct V_648 * V_182 )
{
enum V_4 V_53 = V_45 ;
struct V_51 * V_52 = NULL ;
assert ( V_2 != NULL ) ;
assert ( V_182 != NULL ) ;
F_60 ( L_28 ) ;
V_52 = F_258 ( V_2 ) ;
if ( V_52 ) {
V_53 = F_259 ( V_52 , V_182 , V_2 ) ;
if ( V_53 != V_45 )
goto V_414;
} else
memset ( & V_182 -> V_649 , 0 , sizeof( V_182 -> V_649 ) ) ;
V_52 = F_260 ( V_2 ) ;
if ( V_52 ) {
F_261 ( V_52 , V_182 , V_2 ) ;
F_262 ( V_52 , V_182 , V_2 ) ;
} else {
memset ( & V_182 -> V_650 . V_651 , 0 ,
sizeof( V_182 -> V_650 . V_651 ) ) ;
memset ( & V_182 -> V_650 . V_652 , 0 ,
sizeof( V_182 -> V_650 . V_652 ) ) ;
}
if ( V_52 != NULL ) {
V_182 -> V_653 = V_52 -> V_654 . V_239 . V_68 ;
V_182 -> V_655 = V_52 -> V_654 . V_239 . V_69 ;
}
#if F_14 ( V_656 )
V_182 -> V_657 = V_658 ;
#elif F_14 ( V_659 )
V_182 -> V_657 = V_660 ;
#else
#error "Unknown VAMEM version"
#endif
V_414:
F_130 ( V_53 ) ;
return V_53 ;
}
static enum V_4
F_263 ( struct V_1 * V_2 , enum V_5 V_8 )
{
const enum V_5 * V_661 ;
int V_662 ;
int V_10 = 0 ;
int V_9 ;
F_60 ( L_28 ) ;
if ( NULL == V_2 || NULL == V_2 -> V_193 . V_197 . V_416 . V_182 ) {
F_2 ( L_119 ) ;
F_130 ( V_44 ) ;
return V_44 ;
}
V_661 = V_2 -> V_193 . V_197 . V_416 . V_182 -> V_663 ;
V_662 = sizeof( V_2 -> V_193 . V_197 . V_416 . V_182 -> V_663 ) / sizeof( enum V_5 ) ;
for ( V_9 = 0 ; V_9 < V_662 && ! V_10 ; V_9 ++ ) {
if ( V_661 [ V_9 ] == V_8 ) {
V_10 = 1 ;
break;
}
}
if ( ! V_10 ) {
F_2 ( L_120 ) ;
F_130 ( V_44 ) ;
return V_44 ;
} else {
F_130 ( V_45 ) ;
return V_45 ;
}
}
static enum V_4 F_264 ( struct V_1 * V_2 )
{
struct V_237 V_664 , V_665 ,
* V_666 , V_667 , * V_668 , * V_669 ;
bool V_61 ;
enum V_4 V_53 = V_45 ;
bool V_62 = V_2 -> V_11 -> V_12 . V_62 ;
unsigned int V_9 ;
unsigned V_670 ;
struct V_237 V_671 ;
bool V_672 = false ;
bool V_673 = false ;
bool V_674 = false ;
int V_675 ;
struct V_427 * V_676 = & V_2 -> V_193 . V_197 ;
F_60 ( L_28 ) ;
assert ( V_2 != NULL ) ;
assert ( V_2 -> V_60 == V_211 ) ;
if ( V_676 -> V_416 . V_182 )
return V_45 ;
V_61 = V_2 -> V_11 -> V_12 . V_61 ;
V_668 = & V_2 -> V_7 [ 0 ] ;
V_669 = & V_2 -> V_677 [ 0 ] ;
assert ( V_668 != NULL ) ;
V_53 = F_265 ( & V_2 -> V_11 -> V_12 , false , false ) ;
if ( V_53 != V_45 )
return V_53 ;
if ( V_61 && V_2 -> V_11 -> V_12 . V_60 == V_270 )
return V_44 ;
if ( V_2 -> V_678 [ V_679 ] ) {
V_53 = F_266 ( V_668 ,
V_669 ) ;
if ( V_53 != V_45 )
return V_53 ;
} else {
V_53 = F_267 ( V_668 ) ;
if ( V_53 != V_45 )
return V_53 ;
}
if ( V_2 -> V_680 . V_239 . V_68 )
V_671 = V_2 -> V_680 ;
else
V_671 = * V_668 ;
if ( V_2 -> V_678 [ V_679 ] ) {
V_666 = V_669 ;
V_673 = ( V_666 -> V_239 . V_68 != V_671 . V_239 . V_68 ) ||
( V_666 -> V_239 . V_69 != V_671 . V_239 . V_69 ) ;
}
else {
V_666 = NULL ;
}
V_672 = F_268 ( V_671 . V_239 , V_668 -> V_239 ) ;
if ( V_672 ) {
struct V_681 V_682
= V_683 ;
V_671 . V_8 = V_684 ;
V_53 = F_269 (
& V_671 ,
V_668 ,
NULL ,
& V_682 ) ;
if ( V_53 != V_45 )
return V_53 ;
V_676 -> V_685 = V_682 . V_686 ;
V_676 -> V_497 = F_270 ( V_682 . V_686 *
sizeof( struct V_51 ) , V_397 ) ;
if ( V_676 -> V_497 == NULL ) {
V_53 = V_441 ;
return V_53 ;
}
V_676 -> V_687 = F_270 ( V_682 . V_686
* sizeof( bool ) , V_397 ) ;
if ( V_676 -> V_687 == NULL ) {
V_53 = V_441 ;
return V_53 ;
}
for ( V_9 = 0 ; V_9 < V_682 . V_686 ; V_9 ++ ) {
struct V_688 V_689 ;
V_676 -> V_687 [ V_9 ] = V_682 . V_687 [ V_9 ] ;
F_271 ( V_2 ,
& V_689 , & V_682 . V_690 [ V_9 ] ,
& V_682 . V_691 [ V_9 ] ,
& V_682 . V_692 [ V_9 ] ,
& V_682 . V_693 [ V_9 ] ) ;
V_53 = F_272 ( & V_689 ,
& V_676 -> V_497 [ V_9 ] ) ;
if ( V_53 != V_45 ) {
F_127 ( V_676 -> V_687 ) ;
V_676 -> V_687 = NULL ;
return V_53 ;
}
}
F_273 ( & V_682 ) ;
}
{
struct V_688 V_694 ;
enum V_5 V_695 ;
V_53 = F_274 ( V_2 ,
& V_694 , & V_664 , & V_667 , & V_671 , V_666 ,
V_2 -> V_11 -> V_12 . V_180 ) ;
if ( V_53 != V_45 )
return V_53 ;
V_53 = F_272 ( & V_694 ,
& V_676 -> V_416 ) ;
if ( V_53 != V_45 ) {
if ( V_666 ) {
V_674 = true ;
} else
return V_53 ;
} else if ( V_666 ) {
V_670 = V_676 -> V_416 . V_182 -> V_670 ;
V_675 = V_676 -> V_416 . V_259 ;
V_674 |= ( ( V_670 == 2 ) && V_673 ) ;
V_674 |= ( ( V_670 == 1 ) &&
( ( V_666 -> V_239 . V_68 << V_675 != V_668 -> V_239 . V_68 ) ||
( V_666 -> V_239 . V_69 << V_675 != V_668 -> V_239 . V_69 ) ) ) ;
}
if ( V_674 ) {
F_9 ( V_277 ,
L_121 ) ;
V_695 = V_666 -> V_8 ;
if ( ! V_2 -> V_12 . V_696 )
F_275 ( V_666 ,
V_697 ) ;
F_170 ( & V_676 -> V_416 ) ;
V_53 = F_272 ( & V_694 ,
& V_676 -> V_416 ) ;
F_275 ( V_666 ,
V_695 ) ;
if ( V_53 != V_45 )
return V_53 ;
}
}
if ( ! V_676 -> V_416 . V_182 -> V_183 . V_158 . V_698 )
V_2 -> V_410 = 0 ;
V_2 -> V_607 = V_2 -> V_410 ;
V_2 -> V_182 . V_607 = V_2 -> V_607 ;
if ( V_666 )
V_2 -> V_607 *= 2 ;
F_9 ( V_277 ,
L_122 ,
V_2 -> V_607 , V_2 -> V_410 ) ;
#if ! F_14 ( F_21 )
if ( ! V_61 && ! V_62 ) {
V_53 = F_276 ( V_2 ,
& V_676 -> V_476 ,
& V_676 -> V_416 ) ;
if ( V_53 != V_45 )
return V_53 ;
}
#else
( void ) V_62 ;
#endif
#if ! F_14 ( V_699 )
if ( V_2 -> V_678 [ V_679 ] && V_674 ) {
struct V_688 V_700 ;
if ( V_676 -> V_416 . V_503 . V_8
== V_697 ) {
F_277 ( V_2 , & V_700 ,
& V_676 -> V_416 . V_503 ,
V_669 ) ;
} else {
assert ( V_2 -> V_12 . V_696 == true ) ;
F_271 ( V_2 , & V_700 ,
& V_676 -> V_416 . V_503 ,
V_669 , NULL , NULL ) ;
}
V_53 = F_272 ( & V_700 ,
& V_676 -> V_477 ) ;
if ( V_53 != V_45 )
return V_53 ;
}
#endif
V_53 = F_278 ( V_2 ) ;
if ( V_53 != V_45 )
return V_53 ;
if ( V_676 -> V_416 . V_182 -> V_183 . V_158 . V_701 ) {
#ifdef F_58
unsigned int V_702 ;
unsigned int V_703 ;
#endif
V_665 = V_676 -> V_416 . V_704 [ 0 ] ;
#ifdef F_58
if ( V_2 -> V_12 . V_705 . V_68 && V_2 -> V_12 . V_705 . V_69 ) {
V_702 = V_2 -> V_12 . V_705 . V_68 ;
V_703 = V_2 -> V_12 . V_705 . V_69 ;
} else {
V_702 = V_665 . V_239 . V_68 ;
V_703 = V_665 . V_239 . V_69 ;
}
V_665 . V_239 . V_68 =
F_279 ( V_702 ,
( V_676 -> V_416 . V_182 -> V_183 . V_706 . V_707 * V_708 ) ) ;
V_665 . V_647 = V_665 . V_239 . V_68 ;
#endif
V_665 . V_239 . V_69 =
#ifndef F_58
F_279 (tnr_info.res.height,
#else
CEIL_MUL(tnr_height,
#endif
mycs->video_binary.info->sp.block.output_block_height);
} else {
tnr_info = mycs->video_binary.internal_frame_info;
}
tnr_info.format = IA_CSS_FRAME_FORMAT_YUV_LINE;
tnr_info.raw_bit_depth = SH_CSS_TNR_BIT_DEPTH;
#ifndef F_58
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
IA_CSS_LEAVE_PRIVATE(L_28);
return IA_CSS_SUCCESS;
}
static enum ia_css_err
unload_video_binaries(struct ia_css_pipe *pipe)
{
unsigned int i;
IA_CSS_ENTER_PRIVATE(L_54, pipe);
if ((pipe == NULL) || (pipe->mode != IA_CSS_PIPE_ID_VIDEO)) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
ia_css_binary_unload(&pipe->pipe_settings.video.copy_binary);
ia_css_binary_unload(&pipe->pipe_settings.video.video_binary);
ia_css_binary_unload(&pipe->pipe_settings.video.vf_pp_binary);
#ifndef F_58
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
IA_CSS_ENTER_PRIVATE(L_54, pipe);
if ((pipe == NULL) || (pipe->mode != IA_CSS_PIPE_ID_VIDEO)) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
video_pipe_input_mode = pipe->stream->config.mode;
copy_pipe = pipe->pipe_settings.video.copy_pipe;
capture_pipe = pipe->pipe_settings.video.capture_pipe;
copy_binary = &pipe->pipe_settings.video.copy_binary;
sh_css_metrics_start_frame();
#if F_14 ( F_65 ) || F_14 ( F_21 )
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
#ifndef F_58
&pipe->stream->info.metadata_info
#else
&pipe->stream->info.metadata_info,
#endif
#if ! F_14 ( V_240 )
#ifndef F_58
, pipe->stream->config.source.port.port
#else
pipe->stream->config.source.port.port,
#endif
#endif
#ifndef F_58
);
#else
&copy_pipe->config.internal_frame_origin_bqs_on_sctbl,
copy_pipe->stream->isp_params_configs) ;
#endif
V_709 = V_270 ;
}
if ( V_2 -> V_11 -> V_558 ) {
F_61 ( & V_403 -> V_55 ,
V_406 ,
( V_265 ) F_30 ( V_403 ) ,
V_403 -> V_12 . V_266 . V_267 != 0 ,
V_403 -> V_11 -> V_12 . V_48 == 2 ,
true ,
false ,
V_403 -> V_268 ,
0 ,
V_270 ,
& V_2 -> V_11 -> V_12 . V_159 ,
#ifndef F_58
& V_2 -> V_11 -> V_182 . V_269
#else
& V_2 -> V_11 -> V_182 . V_269 ,
#endif
#if ! F_14 ( V_240 )
#ifndef F_58
, ( V_271 ) 0
#else
( V_271 ) 0 ,
#endif
#endif
#ifndef F_58
) ;
#else
& V_403 -> V_12 . V_272 ,
V_403 -> V_11 -> V_273 ) ;
#endif
}
enum V_4 F_191 (
struct V_1 * V_2 ,
struct V_237 * V_182 ,
unsigned int V_506 )
{
assert ( V_2 != NULL ) ;
assert ( V_182 != NULL ) ;
F_9 ( V_54 , L_123 ) ;
if ( V_2 -> V_60 == V_406 &&
( V_2 -> V_12 . V_266 . V_60 == V_710 ||
V_2 -> V_12 . V_266 . V_60 == V_711 ) )
return V_712 ;
* V_182 = V_2 -> V_677 [ V_506 ] ;
F_9 ( V_54 ,
L_124 ,
V_182 -> V_239 . V_68 , V_182 -> V_239 . V_69 ,
V_182 -> V_647 , V_182 -> V_8 ,
V_182 -> V_540 , V_182 -> V_535 ) ;
return V_45 ;
}
static enum V_4
F_280 ( struct V_1 * V_2 , unsigned int V_68 ,
unsigned int V_69 , unsigned int V_713 ,
enum V_5 V_8 ,
unsigned int V_506 )
{
enum V_4 V_53 = V_45 ;
F_60 ( L_125 ,
V_2 , V_68 , V_69 , V_713 , V_8 , V_506 ) ;
if ( V_2 == NULL ) {
F_130 ( V_44 ) ;
return V_44 ;
}
V_53 = F_255 ( V_68 , V_69 ) ;
if ( V_53 != V_45 ) {
F_130 ( V_53 ) ;
return V_53 ;
}
if ( V_2 -> V_677 [ V_506 ] . V_239 . V_68 != V_68 ||
V_2 -> V_677 [ V_506 ] . V_239 . V_69 != V_69 ||
V_2 -> V_677 [ V_506 ] . V_8 != V_8 ) {
F_256 ( & V_2 -> V_677 [ V_506 ] , V_68 , V_69 ,
V_8 , V_713 ) ;
}
F_130 ( V_45 ) ;
return V_45 ;
}
static enum V_4 F_281 ( struct V_1 * V_2 )
{
enum V_4 V_53 = V_45 ;
assert ( V_2 != NULL ) ;
F_60 ( L_28 ) ;
assert ( V_2 -> V_60 == V_406 || V_2 -> V_60 == V_432 ) ;
if ( V_2 -> V_193 . V_433 . V_476 . V_182 )
return V_45 ;
V_53 = F_267 ( & V_2 -> V_7 [ 0 ] ) ;
if ( V_53 != V_45 )
goto V_414;
V_53 = F_4 ( V_2 ) ;
if ( V_53 != V_45 )
goto V_414;
V_53 = F_276 ( V_2 ,
& V_2 -> V_193 . V_433 . V_476 ,
NULL ) ;
V_414:
F_130 ( V_53 ) ;
return V_53 ;
}
static bool F_282 (
const struct V_1 * V_2 )
{
const struct V_237 * V_691 = & V_2 -> V_7 [ 0 ] ;
F_173 ( L_28 ) ;
assert ( V_2 != NULL ) ;
assert ( V_2 -> V_60 == V_406 ) ;
#ifdef F_58
if ( F_283 ( V_2 ) == true )
return false ;
#endif
if ( V_2 -> V_680 . V_239 . V_68 &&
( ( V_2 -> V_680 . V_239 . V_68 != V_691 -> V_239 . V_68 ) ||
( V_2 -> V_680 . V_239 . V_69 != V_691 -> V_239 . V_69 ) ) )
return true ;
if ( V_2 -> V_12 . V_266 . V_267 != 0 )
return true ;
if ( ( V_2 -> V_11 -> V_273 -> V_714 . V_715 < V_716 ) ||
( V_2 -> V_11 -> V_273 -> V_714 . V_717 < V_716 ) ||
V_2 -> V_12 . V_718 )
return true ;
return false ;
}
static bool F_283 (
const struct V_1 * V_2 )
{
F_173 ( L_28 ) ;
assert ( V_2 != NULL ) ;
assert ( V_2 -> V_60 == V_406 ) ;
return ( V_2 -> V_494 . V_719 ) ? true : false ;
}
static enum V_4 F_284 ( unsigned int * V_720 , enum V_721 V_722 )
{
enum V_4 V_53 = V_45 ;
if ( V_720 == NULL )
return V_44 ;
switch ( V_722 ) {
case V_723 :
* V_720 = V_724 ;
break;
case V_725 :
case V_726 :
* V_720 = V_727 ;
break;
default:
V_53 = V_44 ;
break;
}
return V_53 ;
}
static enum V_4
F_278 ( struct V_1 * V_2 )
{
unsigned int V_728 = 0 , V_9 = 0 ;
unsigned int V_410 = 0 ;
struct V_237 V_729 ;
enum V_4 V_53 = V_45 ;
enum V_208 V_60 = V_211 ;
struct V_246 * * V_253 = NULL ;
F_60 ( L_28 ) ;
if ( V_2 == NULL ) {
F_2 ( L_126 , V_2 ) ;
return V_44 ;
}
V_60 = V_2 -> V_60 ;
V_410 = V_2 -> V_410 ;
if ( V_410 > 0 )
V_728 = V_410 + 1 ;
switch ( V_60 ) {
case V_406 :
{
struct V_424 * V_730 = & V_2 -> V_193 . V_433 ;
( void ) V_730 ;
return V_53 ;
}
break;
case V_211 :
{
struct V_427 * V_731 = & V_2 -> V_193 . V_197 ;
V_729 = V_731 -> V_416 . V_654 ;
V_729 . V_8 = V_684 ;
V_253 = V_731 -> V_253 ;
}
break;
case V_210 :
{
struct V_421 * V_732 = & V_2 -> V_193 . V_194 ;
V_729 = V_732 -> V_415 . V_654 ;
V_729 . V_8 = V_684 ;
V_253 = V_732 -> V_253 ;
}
break;
default:
return V_44 ;
}
V_729 . V_540 = V_733 ;
assert ( V_728 <= V_252 ) ;
for ( V_9 = 0 ; V_9 < V_728 ; V_9 ++ ) {
V_53 = F_183 ( & V_253 [ V_9 ] , & V_729 ) ;
if ( V_53 != V_45 )
return V_53 ;
}
F_62 ( L_28 ) ;
return V_45 ;
}
static enum V_4 F_285 (
struct V_1 * V_2 )
{
struct V_237 V_734 , V_735 ,
V_736 , V_737 ,
V_693 , * V_738 , * V_668 ,
* V_669 ;
bool V_739 ;
bool V_740 = true ;
enum V_4 V_53 = V_45 ;
F_60 ( L_28 ) ;
assert ( V_2 != NULL ) ;
assert ( V_2 -> V_60 == V_406 || V_2 -> V_60 == V_432 ) ;
if ( V_2 -> V_193 . V_433 . V_741 . V_182 )
return V_45 ;
V_668 = & V_2 -> V_7 [ 0 ] ;
V_669 = & V_2 -> V_677 [ 0 ] ;
V_693 = * V_669 ;
V_53 = F_266 ( V_668 , & V_693 ) ;
if ( V_53 != V_45 )
return V_53 ;
V_739 = F_282 ( V_2 ) ;
F_275 ( & V_693 ,
V_697 ) ;
if ( V_739 ) {
struct V_688 V_742 ;
F_286 ( V_2 ,
& V_742 , & V_737 , V_668 , & V_693 ) ;
V_53 = F_272 ( & V_742 ,
& V_2 -> V_193 . V_433 . V_501 ) ;
if ( V_53 != V_45 )
return V_53 ;
} else {
V_737 = * V_668 ;
}
{
struct V_688 V_743 ;
F_287 ( V_2 ,
& V_743 , & V_736 , & V_737 , & V_693 ) ;
V_53 = F_272 ( & V_743 ,
& V_2 -> V_193 . V_433 . V_744 ) ;
if ( V_53 != V_45 )
return V_53 ;
}
{
struct V_688 V_745 ;
F_288 ( V_2 , & V_745 , & V_735 ,
& V_2 -> V_193 . V_433 . V_744 . V_199 ) ;
V_53 = F_272 ( & V_745 ,
& V_2 -> V_193 . V_433 . V_746 ) ;
if ( V_53 != V_45 )
return V_53 ;
}
V_2 -> V_193 . V_433 . V_746 . V_180 =
V_2 -> V_193 . V_433 . V_744 . V_180 ;
{
struct V_688 V_747 ;
F_289 ( V_2 , & V_747 , & V_734 ,
& V_2 -> V_193 . V_433 . V_746 . V_199 ) ;
V_53 = F_272 ( & V_747 ,
& V_2 -> V_193 . V_433 . V_741 ) ;
if ( V_53 != V_45 )
return V_53 ;
}
V_2 -> V_193 . V_433 . V_741 . V_180 =
V_2 -> V_193 . V_433 . V_746 . V_180 ;
if ( V_739 ) {
V_738 =
& V_2 -> V_193 . V_433 . V_501 . V_503 ;
} else {
V_738 =
& V_2 -> V_193 . V_433 . V_744 . V_503 ;
}
{
struct V_688 V_700 ;
F_277 ( V_2 ,
& V_700 , V_738 , V_669 ) ;
V_53 = F_272 ( & V_700 ,
& V_2 -> V_193 . V_433 . V_477 ) ;
if ( V_53 != V_45 )
return V_53 ;
}
#ifdef F_21
V_740 = V_2 -> V_11 -> V_12 . V_60 == V_112 ;
#endif
if ( V_740 )
F_276 ( V_2 ,
& V_2 -> V_193 . V_433 . V_476 ,
& V_2 -> V_193 . V_433 . V_741 ) ;
return V_53 ;
}
static enum V_4 F_290 (
struct V_1 * V_2 )
{
struct V_237 V_748 , * V_668 ;
enum V_4 V_53 = V_45 ;
struct V_688 V_749 ;
F_60 ( L_28 ) ;
assert ( V_2 != NULL ) ;
assert ( V_2 -> V_60 == V_406 || V_2 -> V_60 == V_432 ) ;
V_668 = & V_2 -> V_7 [ 0 ] ;
if ( V_2 -> V_193 . V_433 . V_741 . V_182 )
return V_45 ;
V_53 = F_267 ( V_668 ) ;
if ( V_53 != V_45 )
return V_53 ;
F_291 ( V_2 , & V_749 ,
& V_748 ,
V_668 ) ;
V_53 = F_272 ( & V_749 ,
& V_2 -> V_193 . V_433 . V_741 ) ;
return V_53 ;
}
static enum V_4 F_292 (
struct V_1 * V_2 )
{
struct V_237 V_734 , V_750 ,
V_736 , V_737 ,
V_693 , * V_669 , * V_668 ,
* V_738 ;
bool V_739 ;
bool V_740 = true ;
enum V_4 V_53 = V_45 ;
F_60 ( L_28 ) ;
assert ( V_2 != NULL ) ;
assert ( V_2 -> V_60 == V_406 || V_2 -> V_60 == V_432 ) ;
if ( V_2 -> V_193 . V_433 . V_741 . V_182 )
return V_45 ;
V_669 = & V_2 -> V_677 [ 0 ] ;
V_668 = & V_2 -> V_7 [ 0 ] ;
V_693 = * V_669 ;
V_53 = F_266 ( V_668 ,
& V_693 ) ;
if ( V_53 != V_45 )
return V_53 ;
V_739 = F_282 ( V_2 ) ;
F_275 ( & V_693 ,
V_697 ) ;
if ( V_739 ) {
struct V_688 V_742 ;
F_286 ( V_2 ,
& V_742 , & V_737 , V_668 , & V_693 ) ;
V_53 = F_272 ( & V_742 ,
& V_2 -> V_193 . V_433 . V_501 ) ;
if ( V_53 != V_45 )
return V_53 ;
} else {
V_737 = * V_668 ;
}
{
struct V_688 V_751 ;
F_293 ( V_2 ,
& V_751 , & V_736 , & V_737 , & V_693 ) ;
V_53 = F_272 ( & V_751 ,
& V_2 -> V_193 . V_433 . V_744 ) ;
if ( V_53 != V_45 )
return V_53 ;
}
{
struct V_688 V_752 ;
F_294 ( V_2 , & V_752 , & V_750 ,
& V_2 -> V_193 . V_433 . V_744 . V_199 ) ;
V_53 = F_272 ( & V_752 ,
& V_2 -> V_193 . V_433 . V_746 ) ;
if ( V_53 != V_45 )
return V_53 ;
}
V_2 -> V_193 . V_433 . V_746 . V_180 =
V_2 -> V_193 . V_433 . V_744 . V_180 ;
{
struct V_688 V_753 ;
F_295 ( V_2 , & V_753 , & V_734 ,
& V_2 -> V_193 . V_433 . V_746 . V_199 ) ;
V_53 = F_272 ( & V_753 ,
& V_2 -> V_193 . V_433 . V_741 ) ;
if ( V_53 != V_45 )
return V_53 ;
}
V_2 -> V_193 . V_433 . V_741 . V_180 =
V_2 -> V_193 . V_433 . V_746 . V_180 ;
if ( V_739 ) {
V_738 =
& V_2 -> V_193 . V_433 . V_501 . V_503 ;
} else {
V_738 =
& V_2 -> V_193 . V_433 . V_744 . V_503 ;
}
{
struct V_688 V_700 ;
F_277 ( V_2 ,
& V_700 , V_738 , V_669 ) ;
V_53 = F_272 ( & V_700 ,
& V_2 -> V_193 . V_433 . V_477 ) ;
if ( V_53 != V_45 )
return V_53 ;
}
#ifdef F_21
V_740 = V_2 -> V_11 -> V_12 . V_60 == V_112 ;
#endif
if ( V_740 )
V_53 = F_276 ( V_2 ,
& V_2 -> V_193 . V_433 . V_476 ,
& V_2 -> V_193 . V_433 . V_741 ) ;
return V_53 ;
}
static bool F_241 ( struct V_1 * V_2 )
{
bool V_75 ;
assert ( V_2 != NULL ) ;
F_9 ( V_54 , L_127 ) ;
V_75 = true ;
V_75 &= ( V_2 -> V_60 == V_406 ) ;
V_75 &= ( V_2 -> V_12 . V_266 . V_60 == V_710 ) ;
V_75 &= ( ( V_2 -> V_11 -> V_12 . V_13 . V_8 == V_42 ) ||
( V_2 -> V_12 . V_60 == V_63 ) ) ;
return V_75 ;
}
static enum V_4 F_296 (
struct V_1 * V_2 )
{
enum V_4 V_53 = V_45 ;
bool V_754 ;
F_60 ( L_28 ) ;
assert ( V_2 != NULL ) ;
assert ( V_2 -> V_60 == V_406 || V_2 -> V_60 == V_432 ) ;
if ( V_2 -> V_193 . V_433 . V_527 [ 0 ] . V_182 ) {
F_130 ( V_45 ) ;
return V_45 ;
}
V_754 =
V_2 -> V_12 . V_266 . V_60 == V_755 ||
V_2 -> V_12 . V_266 . V_60 == V_711 ||
V_2 -> V_12 . V_266 . V_60 == V_756 ;
V_53 = F_265 ( & V_2 -> V_11 -> V_12 , V_754 , false ) ;
if ( V_53 != V_45 ) {
F_130 ( V_53 ) ;
return V_53 ;
}
if ( F_241 ( V_2 ) &&
V_2 -> V_11 -> V_12 . V_13 . V_8 == V_42 ) {
F_256 (
& V_2 -> V_7 [ 0 ] ,
V_757 ,
1 ,
V_43 ,
0 ) ;
F_130 ( V_45 ) ;
return V_45 ;
}
switch ( V_2 -> V_12 . V_266 . V_60 ) {
case V_710 :
V_53 = F_281 ( V_2 ) ;
#if ! F_14 ( V_240 ) && F_14 ( F_21 )
if ( V_53 == V_45 )
V_2 -> V_193 . V_433 . V_476 . V_61 = V_2 -> V_11 -> V_12 . V_61 ;
#endif
break;
case V_711 :
V_53 = F_290 ( V_2 ) ;
break;
case V_758 :
V_53 = F_297 ( V_2 ) ;
break;
case V_755 :
V_53 = F_285 ( V_2 ) ;
break;
case V_756 :
V_53 = F_292 ( V_2 ) ;
break;
}
if ( V_53 != V_45 ) {
F_130 ( V_53 ) ;
return V_53 ;
}
F_130 ( V_53 ) ;
return V_53 ;
}
static enum V_4
F_298 ( struct V_1 * V_2 )
{
unsigned int V_9 ;
F_60 ( L_54 , V_2 ) ;
if ( ( V_2 == NULL ) || ( ( V_2 -> V_60 != V_406 ) && ( V_2 -> V_60 != V_432 ) ) ) {
F_130 ( V_44 ) ;
return V_44 ;
}
F_169 ( & V_2 -> V_193 . V_433 . V_476 ) ;
for ( V_9 = 0 ; V_9 < V_759 ; V_9 ++ )
F_169 ( & V_2 -> V_193 . V_433 . V_527 [ V_9 ] ) ;
F_169 ( & V_2 -> V_193 . V_433 . V_741 ) ;
F_169 ( & V_2 -> V_193 . V_433 . V_746 ) ;
F_169 ( & V_2 -> V_193 . V_433 . V_744 ) ;
F_169 ( & V_2 -> V_193 . V_433 . V_501 ) ;
F_169 ( & V_2 -> V_193 . V_433 . V_760 ) ;
F_169 ( & V_2 -> V_193 . V_433 . V_477 ) ;
for ( V_9 = 0 ; V_9 < V_2 -> V_193 . V_433 . V_685 ; V_9 ++ )
F_169 ( & V_2 -> V_193 . V_433 . V_497 [ V_9 ] ) ;
F_127 ( V_2 -> V_193 . V_433 . V_687 ) ;
V_2 -> V_193 . V_433 . V_687 = NULL ;
F_127 ( V_2 -> V_193 . V_433 . V_497 ) ;
V_2 -> V_193 . V_433 . V_497 = NULL ;
F_130 ( V_45 ) ;
return V_45 ;
}
static bool
F_268 ( const struct V_524 V_761 ,
const struct V_524 V_762 )
{
if ( V_761 . V_68 > V_762 . V_68 || V_761 . V_69 > V_762 . V_69 )
return true ;
return false ;
}
static bool
F_299 ( const struct V_1 * V_2 )
{
unsigned int V_9 ;
struct V_524 V_761 , V_762 ;
bool V_763 = false ;
F_60 ( L_28 ) ;
assert ( V_2 != NULL ) ;
assert ( V_2 -> V_60 == V_412 ) ;
V_763 =
( ( V_2 -> V_11 -> V_12 . V_13 . V_8 == V_14 ) &&
( V_2 -> V_7 [ 0 ] . V_8 != V_764 ) ) ;
V_761 = V_2 -> V_12 . V_534 ;
if ( V_2 -> V_12 . V_718 )
return true ;
if ( ( V_2 -> V_7 [ 0 ] . V_239 . V_68 != 0 ) && V_763 )
return true ;
for ( V_9 = 0 ; V_9 < V_765 ; V_9 ++ ) {
V_762 = V_2 -> V_7 [ V_9 ] . V_239 ;
if ( ( V_762 . V_68 != 0 ) && F_268 ( V_761 , V_762 ) )
return true ;
}
return false ;
}
static enum V_4 F_269 (
struct V_237 * V_766 ,
struct V_237 * V_767 ,
struct V_237 * V_768 ,
struct V_681 * V_769 )
{
unsigned int V_9 ;
unsigned int V_770 = 0 , V_771 = 0 ;
enum V_4 V_53 = V_45 ;
struct V_237 V_772 = V_773 ;
unsigned V_774 = V_775 ;
assert ( V_766 != NULL ) ;
assert ( V_767 != NULL ) ;
F_9 ( V_54 , L_128 ) ;
V_769 -> V_776 = 1 ;
V_770 = F_300 ( V_766 -> V_239 . V_68 , V_767 -> V_239 . V_68 ) ;
V_771 = F_300 ( V_766 -> V_239 . V_69 , V_767 -> V_239 . V_69 ) ;
assert ( V_770 == V_771 ) ;
V_9 = 1 ;
while ( V_9 < V_770 ) {
V_769 -> V_686 ++ ;
V_9 *= V_774 ;
}
V_769 -> V_690 = F_122 ( V_769 -> V_686 * sizeof( struct V_237 ) , V_397 ) ;
if ( V_769 -> V_690 == NULL ) {
V_53 = V_441 ;
goto V_414;
}
V_769 -> V_692 = F_122 ( V_769 -> V_686 * sizeof( struct V_237 ) , V_397 ) ;
if ( V_769 -> V_692 == NULL ) {
V_53 = V_441 ;
goto V_414;
}
V_769 -> V_691 = F_122 ( V_769 -> V_686 * sizeof( struct V_237 ) , V_397 ) ;
if ( V_769 -> V_691 == NULL ) {
V_53 = V_441 ;
goto V_414;
}
V_769 -> V_693 = F_122 ( V_769 -> V_686 * sizeof( struct V_237 ) , V_397 ) ;
if ( V_769 -> V_693 == NULL ) {
V_53 = V_441 ;
goto V_414;
}
V_769 -> V_687 = F_122 ( V_769 -> V_686 * sizeof( bool ) , V_397 ) ;
if ( V_769 -> V_687 == NULL ) {
V_53 = V_441 ;
goto V_414;
}
V_772 = * V_766 ;
for ( V_9 = 0 ; V_9 < V_769 -> V_686 ; V_9 ++ ) {
V_769 -> V_690 [ V_9 ] = V_772 ;
if ( ( V_772 . V_239 . V_68 / V_774 ) <= V_767 -> V_239 . V_68 ) {
V_769 -> V_687 [ V_9 ] = true ;
if ( ( V_769 -> V_776 > 1 ) && ( V_9 != ( V_769 -> V_686 - 1 ) ) ) {
V_769 -> V_692 [ V_9 ] . V_239 . V_68 = V_767 -> V_239 . V_68 ;
V_769 -> V_692 [ V_9 ] . V_239 . V_69 = V_767 -> V_239 . V_69 ;
V_769 -> V_692 [ V_9 ] . V_647 = V_767 -> V_647 ;
V_769 -> V_692 [ V_9 ] . V_8 = V_32 ;
} else {
assert ( V_9 == ( V_769 -> V_686 - 1 ) ) ;
V_769 -> V_692 [ V_9 ] . V_239 . V_68 = 0 ;
V_769 -> V_692 [ V_9 ] . V_239 . V_69 = 0 ;
}
V_769 -> V_691 [ V_9 ] . V_239 . V_68 = V_767 -> V_239 . V_68 ;
V_769 -> V_691 [ V_9 ] . V_239 . V_69 = V_767 -> V_239 . V_69 ;
V_769 -> V_691 [ V_9 ] . V_647 = V_767 -> V_647 ;
V_769 -> V_691 [ V_9 ] . V_8 = V_767 -> V_8 ;
if ( V_768 != NULL ) {
V_769 -> V_693 [ V_9 ] . V_239 . V_68 = V_768 -> V_239 . V_68 ;
V_769 -> V_693 [ V_9 ] . V_239 . V_69 = V_768 -> V_239 . V_69 ;
V_769 -> V_693 [ V_9 ] . V_647 = V_768 -> V_647 ;
F_275 ( & V_769 -> V_693 [ V_9 ] , V_697 ) ;
} else {
V_769 -> V_693 [ V_9 ] . V_239 . V_68 = 0 ;
V_769 -> V_693 [ V_9 ] . V_239 . V_69 = 0 ;
V_769 -> V_693 [ V_9 ] . V_647 = 0 ;
}
} else {
V_769 -> V_687 [ V_9 ] = false ;
V_769 -> V_692 [ V_9 ] . V_239 . V_68 = V_772 . V_239 . V_68 / V_774 ;
V_769 -> V_692 [ V_9 ] . V_239 . V_69 = V_772 . V_239 . V_69 / V_774 ;
V_769 -> V_692 [ V_9 ] . V_8 = V_32 ;
F_256 ( & V_769 -> V_692 [ V_9 ] ,
V_772 . V_239 . V_68 / V_774 ,
V_772 . V_239 . V_69 / V_774 ,
V_32 , 0 ) ;
V_769 -> V_691 [ V_9 ] . V_239 . V_68 = 0 ;
V_769 -> V_691 [ V_9 ] . V_239 . V_69 = 0 ;
V_769 -> V_693 [ V_9 ] . V_239 . V_68 = 0 ;
V_769 -> V_693 [ V_9 ] . V_239 . V_69 = 0 ;
}
V_772 = V_769 -> V_692 [ V_9 ] ;
}
V_414:
F_9 ( V_54 , L_129 ,
V_53 ) ;
return V_53 ;
}
static enum V_4 F_301 ( struct V_1 * V_2 ,
struct V_681 * V_769 )
{
struct V_237 V_690 = V_773 ;
struct V_237 * V_691 [ V_765 ] ;
struct V_237 * V_777 [ V_765 ] ;
struct V_237 V_772 = V_773 ;
unsigned int V_9 , V_391 ;
unsigned int V_778 [ V_765 ] ,
V_779 [ V_765 ] ,
V_780 = 0 ;
unsigned int V_781 = 0 ;
enum V_4 V_53 = V_45 ;
unsigned V_774 = V_775 ;
F_9 ( V_54 , L_128 ) ;
for ( V_9 = 0 ; V_9 < V_765 ; V_9 ++ ) {
V_691 [ V_9 ] = NULL ;
V_777 [ V_9 ] = NULL ;
V_778 [ V_9 ] = 0 ;
V_779 [ V_9 ] = 0 ;
}
V_690 . V_239 = V_2 -> V_12 . V_534 ;
V_690 . V_647 = V_690 . V_239 . V_68 ;
V_769 -> V_776 = 0 ;
for ( V_9 = 0 ; V_9 < V_765 ; V_9 ++ ) {
if ( V_2 -> V_7 [ V_9 ] . V_239 . V_68 != 0 ) {
V_691 [ V_9 ] = & V_2 -> V_7 [ V_9 ] ;
if ( V_2 -> V_677 [ V_9 ] . V_239 . V_68 != 0 )
V_777 [ V_9 ] = & V_2 -> V_677 [ V_9 ] ;
V_769 -> V_776 += 1 ;
}
if ( V_691 [ V_9 ] != NULL ) {
V_778 [ V_9 ] = F_300 ( V_690 . V_239 . V_68 , V_691 [ V_9 ] -> V_239 . V_68 ) ;
V_779 [ V_9 ] = F_300 ( V_690 . V_239 . V_69 , V_691 [ V_9 ] -> V_239 . V_69 ) ;
assert ( V_778 [ V_9 ] == V_779 [ V_9 ] ) ;
V_780 = 1 ;
do {
V_781 ++ ;
V_780 *= V_774 ;
} while ( V_780 < V_778 [ V_9 ] );
V_690 . V_239 = V_691 [ V_9 ] -> V_239 ;
}
}
if ( F_299 ( V_2 ) && ( V_781 == 0 ) )
V_781 = 1 ;
V_769 -> V_686 = V_781 ;
V_769 -> V_690 = F_122 ( V_769 -> V_686 * sizeof( struct V_237 ) , V_397 ) ;
if ( V_769 -> V_690 == NULL ) {
V_53 = V_441 ;
goto V_414;
}
V_769 -> V_692 = F_122 ( V_769 -> V_686 * sizeof( struct V_237 ) , V_397 ) ;
if ( V_769 -> V_692 == NULL ) {
V_53 = V_441 ;
goto V_414;
}
V_769 -> V_691 = F_122 ( V_769 -> V_686 * sizeof( struct V_237 ) , V_397 ) ;
if ( V_769 -> V_691 == NULL ) {
V_53 = V_441 ;
goto V_414;
}
V_769 -> V_693 = F_122 ( V_769 -> V_686 * sizeof( struct V_237 ) , V_397 ) ;
if ( V_769 -> V_693 == NULL ) {
V_53 = V_441 ;
goto V_414;
}
V_769 -> V_687 = F_122 ( V_769 -> V_686 * sizeof( bool ) , V_397 ) ;
if ( V_769 -> V_687 == NULL ) {
V_53 = V_441 ;
goto V_414;
}
for ( V_9 = 0 ; V_9 < V_765 ; V_9 ++ ) {
if ( V_691 [ V_9 ] ) {
if ( V_9 > 0 ) {
assert ( ( V_691 [ V_9 - 1 ] -> V_239 . V_68 >= V_691 [ V_9 ] -> V_239 . V_68 ) &&
( V_691 [ V_9 - 1 ] -> V_239 . V_69 >= V_691 [ V_9 ] -> V_239 . V_69 ) ) ;
}
}
}
V_772 . V_239 = V_2 -> V_12 . V_534 ;
V_772 . V_8 = V_32 ;
for ( V_9 = 0 , V_391 = 0 ; V_9 < V_769 -> V_686 ; V_9 ++ ) {
assert ( V_391 < 2 ) ;
assert ( V_691 [ V_391 ] != NULL ) ;
V_769 -> V_690 [ V_9 ] = V_772 ;
if ( ( V_772 . V_239 . V_68 / V_774 ) <= V_691 [ V_391 ] -> V_239 . V_68 ) {
V_769 -> V_687 [ V_9 ] = true ;
if ( ( V_769 -> V_776 > 1 ) && ( V_9 != ( V_769 -> V_686 - 1 ) ) ) {
V_769 -> V_692 [ V_9 ] . V_239 . V_68 = V_691 [ V_391 ] -> V_239 . V_68 ;
V_769 -> V_692 [ V_9 ] . V_239 . V_69 = V_691 [ V_391 ] -> V_239 . V_69 ;
V_769 -> V_692 [ V_9 ] . V_647 = V_691 [ V_391 ] -> V_647 ;
V_769 -> V_692 [ V_9 ] . V_8 = V_32 ;
} else {
assert ( V_9 == ( V_769 -> V_686 - 1 ) ) ;
V_769 -> V_692 [ V_9 ] . V_239 . V_68 = 0 ;
V_769 -> V_692 [ V_9 ] . V_239 . V_69 = 0 ;
}
V_769 -> V_691 [ V_9 ] . V_239 . V_68 = V_691 [ V_391 ] -> V_239 . V_68 ;
V_769 -> V_691 [ V_9 ] . V_239 . V_69 = V_691 [ V_391 ] -> V_239 . V_69 ;
V_769 -> V_691 [ V_9 ] . V_647 = V_691 [ V_391 ] -> V_647 ;
V_769 -> V_691 [ V_9 ] . V_8 = V_691 [ V_391 ] -> V_8 ;
if ( V_777 [ V_391 ] != NULL ) {
V_769 -> V_693 [ V_9 ] . V_239 . V_68 = V_777 [ V_391 ] -> V_239 . V_68 ;
V_769 -> V_693 [ V_9 ] . V_239 . V_69 = V_777 [ V_391 ] -> V_239 . V_69 ;
V_769 -> V_693 [ V_9 ] . V_647 = V_777 [ V_391 ] -> V_647 ;
F_275 ( & V_769 -> V_693 [ V_9 ] , V_697 ) ;
} else {
V_769 -> V_693 [ V_9 ] . V_239 . V_68 = 0 ;
V_769 -> V_693 [ V_9 ] . V_239 . V_69 = 0 ;
V_769 -> V_693 [ V_9 ] . V_647 = 0 ;
}
V_391 ++ ;
} else {
V_769 -> V_687 [ V_9 ] = false ;
V_769 -> V_692 [ V_9 ] . V_239 . V_68 = V_772 . V_239 . V_68 / V_774 ;
V_769 -> V_692 [ V_9 ] . V_239 . V_69 = V_772 . V_239 . V_69 / V_774 ;
V_769 -> V_692 [ V_9 ] . V_8 = V_32 ;
F_256 ( & V_769 -> V_692 [ V_9 ] ,
V_772 . V_239 . V_68 / V_774 ,
V_772 . V_239 . V_69 / V_774 ,
V_32 , 0 ) ;
V_769 -> V_691 [ V_9 ] . V_239 . V_68 = 0 ;
V_769 -> V_691 [ V_9 ] . V_239 . V_69 = 0 ;
V_769 -> V_693 [ V_9 ] . V_239 . V_68 = 0 ;
V_769 -> V_693 [ V_9 ] . V_239 . V_69 = 0 ;
}
V_772 = V_769 -> V_692 [ V_9 ] ;
}
V_414:
F_9 ( V_54 , L_129 ,
V_53 ) ;
return V_53 ;
}
static void F_273 ( struct V_681 * V_769 )
{
F_9 ( V_54 , L_130 ) ;
F_127 ( V_769 -> V_690 ) ;
V_769 -> V_690 = NULL ;
F_127 ( V_769 -> V_692 ) ;
V_769 -> V_692 = NULL ;
F_127 ( V_769 -> V_691 ) ;
V_769 -> V_691 = NULL ;
F_127 ( V_769 -> V_693 ) ;
V_769 -> V_693 = NULL ;
F_127 ( V_769 -> V_687 ) ;
V_769 -> V_687 = NULL ;
F_9 ( V_54 , L_131 ) ;
}
static enum V_4
F_302 ( struct V_1 * V_2 )
{
enum V_4 V_53 = V_45 ;
bool V_672 = false ;
struct V_237 * V_738 [ V_765 ] ;
struct V_429 * V_676 ;
struct V_51 * V_782 ;
struct V_681 V_682 = V_683 ;
unsigned int V_9 , V_391 ;
bool V_783 = false ;
F_60 ( L_28 ) ;
assert ( V_2 != NULL ) ;
assert ( V_2 -> V_11 != NULL ) ;
assert ( V_2 -> V_60 == V_412 ) ;
if ( V_2 -> V_193 . V_430 . V_476 . V_182 )
goto V_414;
V_53 = F_265 ( & V_2 -> V_11 -> V_12 , false , false ) ;
if ( V_53 != V_45 )
goto V_414;
V_676 = & V_2 -> V_193 . V_430 ;
for ( V_9 = 0 ; V_9 < V_765 ; V_9 ++ ) {
if ( V_2 -> V_677 [ V_9 ] . V_239 . V_68 != 0 ) {
V_53 = F_266 ( & V_2 -> V_7 [ V_9 ] ,
& V_2 -> V_677 [ V_9 ] ) ;
if ( V_53 != V_45 )
goto V_414;
}
V_738 [ V_9 ] = NULL ;
}
V_672 = F_299 ( V_2 ) ;
if ( V_672 ) {
struct V_688 V_689 ;
V_53 = F_301 ( V_2 ,
& V_682 ) ;
if ( V_53 != V_45 )
goto V_414;
V_676 -> V_784 = V_682 . V_776 ;
V_676 -> V_685 = V_682 . V_686 ;
V_676 -> V_497 = F_270 ( V_682 . V_686 *
sizeof( struct V_51 ) , V_397 ) ;
if ( V_676 -> V_497 == NULL ) {
V_53 = V_441 ;
goto V_414;
}
V_676 -> V_687 = F_270 ( V_682 . V_686 *
sizeof( bool ) , V_397 ) ;
if ( V_676 -> V_687 == NULL ) {
V_53 = V_441 ;
goto V_414;
}
for ( V_9 = 0 ; V_9 < V_682 . V_686 ; V_9 ++ ) {
V_676 -> V_687 [ V_9 ] = V_682 . V_687 [ V_9 ] ;
F_271 ( V_2 ,
& V_689 , & V_682 . V_690 [ V_9 ] ,
& V_682 . V_691 [ V_9 ] ,
& V_682 . V_692 [ V_9 ] ,
& V_682 . V_693 [ V_9 ] ) ;
V_53 = F_272 ( & V_689 ,
& V_676 -> V_497 [ V_9 ] ) ;
if ( V_53 != V_45 )
goto V_414;
}
F_273 ( & V_682 ) ;
} else {
V_676 -> V_784 = 1 ;
}
if ( V_672 ) {
V_782 = & V_676 -> V_497 [ 0 ] ;
} else {
V_782 = NULL ;
}
#if F_14 ( F_21 )
V_783 =
( V_2 -> V_11 -> V_12 . V_13 . V_8 == V_20 ) ;
#else
V_783 = true ;
#endif
if ( V_783 ) {
V_53 = F_276 ( V_2 ,
& V_676 -> V_476 ,
V_782 ) ;
if ( V_53 != V_45 )
goto V_414;
V_2 -> V_193 . V_433 . V_476 . V_61 = V_2 -> V_11 -> V_12 . V_61 ;
}
if ( V_672 ) {
for ( V_9 = 0 , V_391 = 0 ; V_9 < V_676 -> V_685 ; V_9 ++ ) {
if ( V_676 -> V_687 [ V_9 ] ) {
assert ( V_391 < 2 ) ;
V_738 [ V_391 ] =
& V_676 -> V_497 [ V_9 ] . V_503 ;
V_391 ++ ;
}
}
V_676 -> V_785 = V_391 ;
} else {
V_738 [ 0 ] =
& V_676 -> V_476 . V_503 ;
for ( V_9 = 1 ; V_9 < V_765 ; V_9 ++ ) {
V_738 [ V_9 ] = NULL ;
}
V_676 -> V_785 = 1 ;
}
V_676 -> V_477 = F_270 ( V_676 -> V_785 * sizeof( struct V_51 ) ,
V_397 ) ;
if ( V_676 -> V_477 == NULL ) {
V_53 = V_441 ;
goto V_414;
}
{
struct V_688 V_700 ;
for ( V_9 = 0 ; V_9 < V_676 -> V_785 ; V_9 ++ ) {
if ( V_2 -> V_677 [ V_9 ] . V_239 . V_68 != 0 ) {
F_277 ( V_2 ,
& V_700 , V_738 [ V_9 ] , & V_2 -> V_677 [ V_9 ] ) ;
V_53 = F_272 ( & V_700 , & V_676 -> V_477 [ V_9 ] ) ;
if ( V_53 != V_45 )
goto V_414;
}
}
}
if ( V_53 != V_45 )
goto V_414;
V_414:
if ( V_672 ) {
F_273 ( & V_682 ) ;
}
F_9 ( V_54 , L_132 ,
V_53 ) ;
return V_53 ;
}
static enum V_4
F_303 ( struct V_1 * V_2 )
{
unsigned int V_9 ;
F_60 ( L_54 , V_2 ) ;
if ( ( V_2 == NULL ) || ( V_2 -> V_60 != V_412 ) ) {
F_130 ( V_44 ) ;
return V_44 ;
}
F_169 ( & V_2 -> V_193 . V_430 . V_476 ) ;
for ( V_9 = 0 ; V_9 < V_2 -> V_193 . V_430 . V_685 ; V_9 ++ ) {
F_169 ( & V_2 -> V_193 . V_430 . V_497 [ V_9 ] ) ;
}
for ( V_9 = 0 ; V_9 < V_2 -> V_193 . V_430 . V_785 ; V_9 ++ ) {
F_169 ( & V_2 -> V_193 . V_430 . V_477 [ V_9 ] ) ;
}
F_127 ( V_2 -> V_193 . V_430 . V_687 ) ;
V_2 -> V_193 . V_430 . V_687 = NULL ;
F_127 ( V_2 -> V_193 . V_430 . V_497 ) ;
V_2 -> V_193 . V_430 . V_497 = NULL ;
F_127 ( V_2 -> V_193 . V_430 . V_477 ) ;
V_2 -> V_193 . V_430 . V_477 = NULL ;
F_130 ( V_45 ) ;
return V_45 ;
}
static enum V_4 F_240 ( struct V_1 * V_2 )
{
struct V_51 * V_476 ;
enum V_4 V_53 = V_45 ;
enum V_261 V_262 ;
enum V_263 V_786 ;
F_60 ( L_54 , V_2 ) ;
if ( ( V_2 == NULL ) || ( V_2 -> V_60 != V_412 ) ) {
F_130 ( V_44 ) ;
return V_44 ;
}
V_786 = V_2 -> V_11 -> V_12 . V_60 ;
V_476 = & V_2 -> V_193 . V_430 . V_476 ;
F_209 () ;
#if ! F_14 ( V_240 ) && ( F_14 ( F_65 ) || F_14 ( F_21 ) )
V_53 = F_210 ( V_2 ) ;
if ( V_53 != V_45 ) {
F_130 ( V_53 ) ;
return V_53 ;
}
#endif
{
unsigned int V_507 ;
F_29 ( F_30 ( V_2 ) , & V_507 ) ;
V_262 = 1 << V_507 ;
}
F_59 ( V_2 , V_262 , V_786 ) ;
F_130 ( V_53 ) ;
return V_53 ;
}
static enum V_4
F_304 ( struct V_1 * V_2 )
{
enum V_4 V_53 = V_45 ;
F_60 ( L_54 , V_2 ) ;
if ( V_2 == NULL ) {
F_130 ( V_44 ) ;
return V_44 ;
}
if ( V_2 -> V_12 . V_60 == V_63 ) {
F_130 ( V_45 ) ;
return V_45 ;
}
switch ( V_2 -> V_60 ) {
case V_210 :
V_53 = F_171 ( V_2 ) ;
break;
case V_211 :
V_53 = F_305 ( V_2 ) ;
break;
case V_406 :
V_53 = F_298 ( V_2 ) ;
break;
case V_412 :
V_53 = F_303 ( V_2 ) ;
break;
default:
break;
}
F_130 ( V_53 ) ;
return V_53 ;
}
static enum V_4
F_306 ( struct V_1 * V_2 )
{
enum V_4 V_53 = V_45 ;
assert ( V_2 != NULL ) ;
F_9 ( V_54 , L_133 ) ;
if ( V_2 -> V_12 . V_60 == V_63 )
return V_53 ;
switch ( V_2 -> V_60 ) {
case V_210 :
V_53 = F_307 ( V_2 ) ;
break;
case V_211 :
V_53 = F_264 ( V_2 ) ;
break;
case V_406 :
V_53 = F_296 ( V_2 ) ;
break;
case V_412 :
V_53 = F_302 ( V_2 ) ;
break;
case V_407 :
break;
default:
V_53 = V_198 ;
break;
}
if ( V_53 != V_45 ) {
if ( F_304 ( V_2 ) != V_45 ) {
V_53 = V_198 ;
}
}
return V_53 ;
}
static enum V_4
F_139 ( struct V_1 * V_2 )
{
struct V_442 * V_260 ;
enum V_4 V_53 = V_45 ;
struct V_274 * V_492 = NULL ,
* V_548 = NULL ,
* V_787 = NULL ;
struct V_51 * V_476 ,
* V_477 ,
* V_497 ;
bool V_672 = false ;
unsigned int V_686 , V_788 , V_776 ;
unsigned int V_9 , V_391 ;
struct V_246 * V_254 = NULL ;
struct V_246 * V_247 [ V_765 ] ;
struct V_246 * V_789 [ V_255 ] ;
struct V_246 * V_482 [ V_765 ] ;
struct V_486 V_487 ;
bool V_550 = false ;
#ifdef F_21
bool V_551 = false ;
bool V_552 = false ;
bool V_61 = false ;
bool V_62 = false ;
#endif
F_60 ( L_54 , V_2 ) ;
if ( ( V_2 == NULL ) || ( V_2 -> V_11 == NULL ) || ( V_2 -> V_60 != V_412 ) ) {
F_130 ( V_44 ) ;
return V_44 ;
}
V_260 = & V_2 -> V_55 ;
F_204 ( V_260 ) ;
for ( V_9 = 0 ; V_9 < V_765 ; V_9 ++ ) {
V_247 [ V_9 ] = NULL ;
V_482 [ V_9 ] = NULL ;
}
F_178 ( V_789 ) ;
V_686 = V_2 -> V_193 . V_430 . V_685 ;
V_788 = V_2 -> V_193 . V_430 . V_785 ;
V_776 = V_2 -> V_193 . V_430 . V_784 ;
#ifdef F_21
V_551 = V_2 -> V_11 -> V_12 . V_60 == V_112 ;
V_552 = V_2 -> V_11 -> V_12 . V_60 == V_102 ;
V_61 = V_2 -> V_11 -> V_12 . V_61 ;
V_62 = V_2 -> V_11 -> V_12 . V_62 ;
V_550 =
! ( ( V_551 && ( V_61 || V_62 ) ) || ( V_552 && V_62 ) ) ;
#else
V_550 = V_2 -> V_11 -> V_12 . V_60 == V_270 ;
#endif
if ( V_550 ) {
int V_790 ;
if ( V_2 -> V_11 -> V_12 . V_13 . V_8 == V_14 ) {
V_790 = V_764 ;
} else if ( V_2 -> V_11 -> V_12 . V_13 . V_8 == V_20 ) {
V_790 = V_40 ;
} else {
V_790 = V_684 ;
}
V_53 = F_197 ( V_2 ,
& V_260 -> V_254 ,
V_790 ) ;
if ( V_53 != V_45 ) {
F_130 ( V_53 ) ;
return V_53 ;
}
V_254 = & V_260 -> V_254 ;
} else {
V_254 = NULL ;
}
for ( V_9 = 0 ; V_9 < V_776 ; V_9 ++ ) {
assert ( V_9 < V_765 ) ;
if ( V_2 -> V_7 [ V_9 ] . V_239 . V_68 != 0 ) {
V_53 = F_200 ( V_2 , & V_260 -> V_247 [ V_9 ] , V_9 ) ;
if ( V_53 != V_45 ) {
F_130 ( V_53 ) ;
return V_53 ;
}
V_247 [ V_9 ] = & V_260 -> V_247 [ V_9 ] ;
}
if ( V_2 -> V_677 [ V_9 ] . V_239 . V_68 != 0 ) {
V_53 = F_190 ( V_2 , & V_260 -> V_482 [ V_9 ] , V_9 ) ;
if ( V_53 != V_45 ) {
F_130 ( V_53 ) ;
return V_53 ;
}
V_482 [ V_9 ] = & V_260 -> V_482 [ V_9 ] ;
}
}
V_476 = & V_2 -> V_193 . V_430 . V_476 ;
V_477 = V_2 -> V_193 . V_430 . V_477 ;
V_497 = V_2 -> V_193 . V_430 . V_497 ;
V_672 = F_299 ( V_2 ) ;
if ( V_2 -> V_193 . V_430 . V_476 . V_182 ) {
struct V_246 * V_791 = NULL ;
#ifdef F_21
if ( ! V_61 )
V_791 = V_254 ;
#endif
if ( V_672 ) {
F_179 ( V_789 , 0 , NULL ) ;
F_180 ( & V_487 , V_476 ,
V_789 , V_791 , NULL ) ;
} else {
F_179 ( V_789 , 0 , V_247 [ 0 ] ) ;
F_180 ( & V_487 , V_476 ,
V_789 , V_791 , NULL ) ;
}
V_53 = F_176 ( V_260 ,
& V_487 ,
& V_548 ) ;
if ( V_53 != V_45 ) {
F_130 ( V_53 ) ;
return V_53 ;
}
if ( V_548 ) {
V_548 -> args . V_257 = ! V_672 ;
V_548 -> args . V_258 = true ;
V_254 = V_548 -> args . V_247 [ 0 ] ;
}
}
if ( V_672 ) {
struct V_246 * V_792 = NULL ;
struct V_246 * V_793 = NULL ;
struct V_246 * V_794 = V_254 ;
for ( V_9 = 0 , V_391 = 0 ; V_9 < V_686 ; V_9 ++ ) {
assert ( V_391 < V_776 ) ;
if ( V_2 -> V_193 . V_430 . V_687 [ V_9 ] == true ) {
V_792 = V_247 [ V_391 ] ;
V_793 = V_482 [ V_391 ] ;
} else {
V_792 = NULL ;
V_793 = NULL ;
}
V_53 = F_181 ( V_2 , V_260 , V_794 , V_792 ,
NULL ,
& V_497 [ V_9 ] ,
& V_787 ) ;
if ( V_53 != V_45 ) {
F_130 ( V_53 ) ;
return V_53 ;
}
V_794 = V_787 -> args . V_247 [ 1 ] ;
if ( V_2 -> V_193 . V_430 . V_687 [ V_9 ] == true ) {
if ( V_793 && ( V_793 -> V_182 . V_239 . V_68 != 0 ) ) {
V_254 = V_787 -> args . V_256 ;
V_53 = F_177 ( V_2 , V_254 , V_793 , & V_477 [ V_391 ] ,
& V_492 ) ;
if ( V_53 != V_45 ) {
F_130 ( V_53 ) ;
return V_53 ;
}
}
V_391 ++ ;
}
}
} else if ( V_548 != NULL ) {
if ( V_482 [ 0 ] != NULL && V_482 [ 0 ] -> V_182 . V_239 . V_68 != 0 ) {
V_254 = V_548 -> args . V_256 ;
V_53 = F_177 ( V_2 , V_254 , V_482 [ 0 ] , & V_477 [ 0 ] ,
& V_492 ) ;
}
if ( V_53 != V_45 ) {
F_130 ( V_53 ) ;
return V_53 ;
}
}
F_203 ( & V_2 -> V_55 , V_2 -> V_11 -> V_12 . V_62 ) ;
F_130 ( V_45 ) ;
return V_45 ;
}
static enum V_4
F_141 ( struct V_1 * V_2 ,
unsigned V_413 ,
struct V_246 * V_247 )
{
struct V_442 * V_260 ;
enum V_4 V_53 = V_45 ;
struct V_486 V_487 ;
F_9 ( V_54 ,
L_134 ) ;
V_260 = & V_2 -> V_55 ;
F_204 ( V_260 ) ;
V_247 -> V_510 = false ;
V_247 -> V_511 = V_512 ;
if ( F_241 ( V_2 ) &&
V_2 -> V_11 -> V_12 . V_13 . V_8 == V_42 ) {
F_256 (
& V_247 -> V_182 ,
V_757 ,
1 ,
V_43 ,
0 ) ;
} else if ( V_247 -> V_182 . V_8 == V_40 ) {
V_247 -> V_182 . V_540 =
F_198 ( V_2 ) ;
}
V_260 -> V_781 = 1 ;
V_260 -> V_209 = V_432 ;
V_2 -> V_60 = V_432 ;
F_308 ( & V_487 , V_247 ,
V_795 , V_413 ) ;
V_53 = F_176 ( V_260 ,
& V_487 ,
NULL ) ;
F_203 ( & V_2 -> V_55 , V_2 -> V_11 -> V_12 . V_62 ) ;
F_9 ( V_54 ,
L_135 ) ;
return V_53 ;
}
static enum V_4
F_309 ( struct V_1 * V_2 )
{
struct V_442 * V_260 = & V_2 -> V_55 ;
enum V_4 V_53 = V_45 ;
struct V_486 V_487 ;
struct V_246 * V_247 = & V_260 -> V_247 [ 0 ] ;
struct V_274 * V_796 = NULL ;
unsigned int V_507 ;
enum V_508 V_509 ;
unsigned int V_413 = V_797 * V_798 ;
F_9 ( V_54 ,
L_136 ) ;
F_204 ( V_260 ) ;
V_53 = F_201 ( V_2 , & V_247 -> V_182 , 0 ) ;
if ( V_53 != V_45 )
return V_53 ;
V_247 -> V_510 = false ;
V_247 -> V_511 = V_512 ;
F_29 ( F_30 ( V_2 ) , & V_507 ) ;
F_192 ( V_542 , V_507 , & V_509 ) ;
V_247 -> V_514 = V_509 ;
V_247 -> V_515 = V_542 ;
V_260 -> V_781 = 1 ;
V_260 -> V_209 = V_406 ;
V_2 -> V_60 = V_406 ;
F_308 ( & V_487 , V_247 ,
V_799 , V_413 ) ;
V_53 = F_176 ( V_260 ,
& V_487 , & V_796 ) ;
if( V_53 != V_45 )
return V_53 ;
F_203 ( V_260 , V_2 -> V_11 -> V_12 . V_62 ) ;
F_9 ( V_54 ,
L_137 ) ;
return V_53 ;
}
static enum V_4
F_310 ( struct V_1 * V_2 )
{
struct V_442 * V_260 ;
enum V_4 V_53 = V_45 ;
enum V_800 V_60 ;
struct V_274 * V_276 = NULL ;
struct V_274 * V_787 = NULL ;
struct V_51 * V_476 ,
* V_527 [ V_759 ] ,
* V_477 ,
* V_741 ,
* V_746 ,
* V_744 ,
* V_497 ,
* V_501 ,
* V_760 ;
bool V_739 = false ;
bool V_801 ;
struct V_246 * V_254 ;
struct V_246 * V_247 ;
struct V_246 * V_493 [ V_255 ] ;
struct V_246 * V_482 ;
struct V_486 V_487 ;
bool V_550 = false ;
#ifdef F_21
bool V_551 = false ;
bool V_552 = false ;
bool V_61 = false ;
bool V_62 = false ;
#endif
unsigned int V_9 , V_685 , V_526 ;
bool V_802 = false ;
bool * V_687 = NULL ;
bool V_803 = false ;
F_60 ( L_28 ) ;
assert ( V_2 != NULL ) ;
assert ( V_2 -> V_11 != NULL ) ;
assert ( V_2 -> V_60 == V_406 || V_2 -> V_60 == V_432 ) ;
V_260 = & V_2 -> V_55 ;
V_60 = V_2 -> V_12 . V_266 . V_60 ;
V_801 = ( V_60 == V_710 ) ;
F_204 ( V_260 ) ;
F_178 ( V_493 ) ;
#ifdef F_21
V_551 = ( V_2 -> V_11 -> V_12 . V_60 == V_112 ) ;
V_552 = ( V_2 -> V_11 -> V_12 . V_60 == V_102 ) ;
V_61 = V_2 -> V_11 -> V_12 . V_61 ;
V_62 = V_2 -> V_11 -> V_12 . V_62 ;
V_550 =
! ( ( V_551 && ( V_61 || V_62 ) ) || ( V_552 && ( V_61 || V_62 ) ) ) ;
#else
V_550 = V_2 -> V_11 -> V_12 . V_60 == V_270 ;
#endif
if ( V_550 ) {
V_53 = F_197 ( V_2 , & V_260 -> V_254 , V_40 ) ;
if ( V_53 != V_45 ) {
F_130 ( V_53 ) ;
return V_53 ;
}
V_254 = & V_260 -> V_254 ;
} else {
V_254 = NULL ;
}
V_53 = F_200 ( V_2 , & V_260 -> V_247 [ 0 ] , 0 ) ;
if ( V_53 != V_45 ) {
F_130 ( V_53 ) ;
return V_53 ;
}
V_247 = & V_260 -> V_247 [ 0 ] ;
if ( V_2 -> V_678 [ V_679 ] ) {
if ( V_60 == V_710 || V_60 == V_711 ) {
V_482 = NULL ;
} else {
F_190 ( V_2 , & V_260 -> V_482 [ 0 ] , 0 ) ;
V_482 = & V_260 -> V_482 [ 0 ] ;
}
} else {
V_482 = NULL ;
}
V_476 = & V_2 -> V_193 . V_433 . V_476 ;
V_526 = V_2 -> V_193 . V_433 . V_526 ;
if ( ( V_526 == 0 ) && ( V_60 == V_758 ) ) {
F_130 ( V_198 ) ;
return V_198 ;
}
for ( V_9 = 0 ; V_9 < V_526 ; V_9 ++ ) {
V_527 [ V_9 ] = & V_2 -> V_193 . V_433 . V_527 [ V_9 ] ;
}
V_477 = & V_2 -> V_193 . V_433 . V_477 ;
V_741 = & V_2 -> V_193 . V_433 . V_741 ;
V_746 = & V_2 -> V_193 . V_433 . V_746 ;
V_744 = & V_2 -> V_193 . V_433 . V_744 ;
V_501 = & V_2 -> V_193 . V_433 . V_501 ;
V_497 = V_2 -> V_193 . V_433 . V_497 ;
V_685 = V_2 -> V_193 . V_433 . V_685 ;
V_687 = V_2 -> V_193 . V_433 . V_687 ;
V_760 = & V_2 -> V_193 . V_433 . V_760 ;
V_739 = ( F_282 ( V_2 ) || V_2 -> V_499 ) &&
V_60 != V_710 &&
V_60 != V_711 ;
V_802 = ( V_497 != NULL && V_497 -> V_182 != NULL ) ;
V_803 = ( V_760 != NULL && V_760 -> V_182 != NULL ) ;
if ( V_2 -> V_193 . V_433 . V_476 . V_182 ) {
if ( V_801 ) {
F_179 ( V_493 , 0 , V_247 ) ;
#if ! F_14 ( V_240 ) && F_14 ( F_21 )
if ( ! V_62 ) {
F_180 ( & V_487 , V_476 ,
V_493 , V_254 , NULL ) ;
} else {
V_254 = V_2 -> V_11 -> V_50 -> V_417 [ 0 ] ;
F_180 ( & V_487 , V_476 ,
V_493 , V_254 , NULL ) ;
}
#else
F_180 ( & V_487 , V_476 ,
V_493 , NULL , NULL ) ;
#endif
} else {
F_179 ( V_493 , 0 , V_254 ) ;
F_180 ( & V_487 , V_476 ,
V_493 , NULL , NULL ) ;
}
V_53 = F_176 ( V_260 ,
& V_487 ,
& V_276 ) ;
if ( V_53 != V_45 ) {
F_130 ( V_53 ) ;
return V_53 ;
}
} else if ( V_2 -> V_11 -> V_12 . V_62 ) {
V_254 = V_2 -> V_11 -> V_50 -> V_417 [ 0 ] ;
}
if ( V_60 == V_758 ) {
unsigned int V_804 ;
struct V_246 * V_805 = NULL ;
struct V_246 * V_806 = NULL ;
for ( V_9 = 0 ; V_9 < V_526 ; V_9 ++ ) {
if ( V_9 == 0 )
V_805 = V_254 ;
else
V_805 = NULL ;
#ifndef F_58
if ( ! V_739 && ( V_9 == V_526 - 1 ) )
#else
if ( ! V_739 && ( V_9 == V_526 - 1 ) && ! V_803 )
#endif
V_806 = V_247 ;
else
V_806 = NULL ;
F_179 ( V_493 , 0 , V_806 ) ;
F_180 ( & V_487 , V_527 [ V_9 ] ,
V_493 , V_805 , NULL ) ;
V_53 = F_176 ( V_260 ,
& V_487 ,
& V_276 ) ;
if ( V_53 != V_45 ) {
F_130 ( V_53 ) ;
return V_53 ;
}
}
( void ) V_804 ;
V_276 -> args . V_257 =
V_527 [ 0 ] -> V_182 -> V_183 . V_55 . V_60 ==
V_553 ;
V_276 -> args . V_258 = V_276 -> args . V_257 ;
} else if ( V_60 == V_755 ||
V_60 == V_756 ) {
F_179 ( V_493 , 0 , NULL ) ;
F_180 ( & V_487 , V_741 ,
V_493 , V_254 , NULL ) ;
V_53 = F_176 ( V_260 ,
& V_487 , NULL ) ;
if ( V_53 != V_45 ) {
F_130 ( V_53 ) ;
return V_53 ;
}
F_179 ( V_493 , 0 , NULL ) ;
F_180 ( & V_487 , V_746 ,
V_493 , NULL , NULL ) ;
V_53 = F_176 ( V_260 ,
& V_487 , NULL ) ;
if ( V_53 != V_45 ) {
F_130 ( V_53 ) ;
return V_53 ;
}
if( V_739 ) {
F_179 ( V_493 , 0 , NULL ) ;
F_180 ( & V_487 , V_744 ,
V_493 , NULL , NULL ) ;
} else {
F_179 ( V_493 , 0 , V_247 ) ;
F_180 ( & V_487 , V_744 ,
V_493 , NULL , NULL ) ;
}
V_53 = F_176 ( V_260 ,
& V_487 , & V_276 ) ;
if ( V_53 != V_45 ) {
F_130 ( V_53 ) ;
return V_53 ;
}
} else if ( V_60 == V_711 ) {
F_179 ( V_493 , 0 , V_247 ) ;
F_180 ( & V_487 , V_741 ,
V_493 , V_254 , NULL ) ;
V_53 = F_176 ( V_260 ,
& V_487 ,
NULL ) ;
if ( V_53 != V_45 ) {
F_130 ( V_53 ) ;
return V_53 ;
}
}
#ifndef F_58
if ( V_739 && V_276 ) {
struct V_246 * V_805 = NULL ;
V_805 = V_276 -> args . V_247 [ 0 ] ;
if( V_803 ) {
F_179 ( V_493 , 0 , NULL ) ;
F_180 ( & V_487 , V_760 ,
V_493 , V_805 , NULL ) ;
V_53 = F_176 ( V_260 ,
& V_487 ,
& V_276 ) ;
V_805 = V_276 -> args . V_247 [ 0 ] ;
}
V_53 = F_182 (pipe, me, local_in_frame, need_yuv_pp ? NULL : out_frame,
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
L_138);
return IA_CSS_SUCCESS;
}
static enum ia_css_err
create_host_capture_pipeline(struct ia_css_pipe *pipe)
{
enum ia_css_err err = IA_CSS_SUCCESS;
IA_CSS_ENTER_PRIVATE(L_54, pipe);
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
IA_CSS_ENTER_PRIVATE(L_54, pipe);
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
#if F_14 ( F_65 )
err = send_mipi_frames(pipe);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
#elif F_14 ( F_21 )
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
#if ! F_14 ( V_240 ) && ! F_14 ( F_21 )
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
L_139);
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
L_140);
return err;
}
#if ! F_14 ( V_240 )
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
IA_CSS_ENTER_PRIVATE(L_141, l , firmware);
if (l == NULL) {
IA_CSS_ERROR(L_142);
IA_CSS_LEAVE_PRIVATE(L_28);
return;
}
while (*l)
l = &(*l)->next;
*l = firmware;
IA_CSS_LEAVE_PRIVATE(L_28);
}
static void
remove_firmware(struct ia_css_fw_info **l, struct ia_css_fw_info *firmware)
{
assert(*l);
assert(firmware);
(void)l;
(void)firmware;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, L_143);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, L_144);
return;
}
static enum ia_css_err upload_isp_code(struct ia_css_fw_info *firmware)
{
hrt_vaddress binary;
if (firmware == NULL) {
IA_CSS_ERROR(L_1);
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
static enum ia_css_err
acc_load_extension(struct ia_css_fw_info *firmware)
{
enum ia_css_err err;
struct ia_css_fw_info *hd = firmware;
while (hd){
err = upload_isp_code(hd);
if (err != IA_CSS_SUCCESS)
return err;
hd = hd->next;
}
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
IA_CSS_LEAVE_PRIVATE(L_28);
return;
}
if (firmware->info.isp.type == IA_CSS_ACC_OUTPUT)
remove_firmware(&pipe->output_stage, firmware);
else if (firmware->info.isp.type == IA_CSS_ACC_VIEWFINDER)
remove_firmware(&pipe->vf_stage, firmware);
acc_unload_extension(firmware);
IA_CSS_LEAVE_PRIVATE(L_28);
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
#ifndef F_58
sh_css_write_host2sp_command(host2sp_cmd_start_flash);
#else
if (sh_css_sp_is_running()) {
if (!sh_css_write_host2sp_command(host2sp_cmd_start_flash)) {
IA_CSS_ERROR(L_161);
ia_css_debug_dump_sp_sw_debug_info();
ia_css_debug_dump_debug_info(NULL);
}
} else
IA_CSS_LOG(L_79);
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
#ifndef F_58
unsigned int HIVE_ADDR_sp_stop_copy_preview;
#endif
unsigned int HIVE_ADDR_host_sp_com;
unsigned int o = offsetof(struct host_sp_communication, host2sp_command)
/ sizeof(int);
#if F_14 ( F_65 ) || F_14 ( F_21 )
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
#ifndef F_58
HIVE_ADDR_sp_stop_copy_preview = fw->info.sp.stop_copy_preview;
#endif
HIVE_ADDR_host_sp_com = fw->info.sp.host_sp_com;
(void)HIVE_ADDR_ia_css_ispctrl_sp_isp_started;
(void)HIVE_ADDR_sp_sleep_mode;
(void)HIVE_ADDR_ia_css_dmaproxy_sp_invalidate_tlb;
#ifndef F_58
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
#ifndef F_58
sp_dmem_store_uint32(SP0_ID,
(unsigned int)sp_address_of(sp_stop_copy_preview),
my_css.stop_copy_preview?(uint32_t)(1):(uint32_t)(0));
#endif
store_sp_array_uint(host_sp_com, o, host2sp_cmd_ready);
#if ! F_14 ( V_240 )
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
IA_CSS_ERROR(L_1);
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
IA_CSS_ERROR(L_1);
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
#ifndef F_58
if (config == NULL)
#else
enum ia_css_err err = IA_CSS_SUCCESS;
IA_CSS_ENTER_PRIVATE(L_167, config, pipe);
if (config == NULL) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
#endif
return IA_CSS_ERR_INVALID_ARGUMENTS;
#ifndef F_58
if (pipe == NULL)
#else
}
if (pipe == NULL) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
#endif
return IA_CSS_ERR_INVALID_ARGUMENTS;
#ifndef F_58
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
#ifdef F_58
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
#if F_14 ( F_65 )
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
IA_CSS_ENTER_PRIVATE(L_48, stream);
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
#ifdef F_58
static enum ia_css_err check_pipe_resolutions(const struct ia_css_pipe *pipe)
{
enum ia_css_err err = IA_CSS_SUCCESS;
IA_CSS_ENTER_PRIVATE(L_28);
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
#ifndef F_58
struct ia_css_resolution effective_res;
#else
#ifdef F_21
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
#if F_14 ( F_65 )
if (stream_config->input_config.format == IA_CSS_STREAM_FORMAT_BINARY_8 &&
stream_config->metadata_config.resolution.height > 0) {
err = IA_CSS_ERR_INVALID_ARGUMENTS;
IA_CSS_LEAVE_ERR(err);
return err;
}
#endif
#ifdef F_21
if (stream_config->online && stream_config->pack_raw_pixels) {
IA_CSS_LOG(L_185);
err = IA_CSS_ERR_INVALID_ARGUMENTS;
IA_CSS_LEAVE_ERR(err);
return err;
}
#endif
#if ! F_14 ( V_240 )
ia_css_debug_pipe_graph_dump_stream_config(stream_config);
if (stream_config->mode == IA_CSS_INPUT_MODE_BUFFERED_SENSOR)
#ifdef F_21
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
#if F_14 ( F_21 ) && F_14 ( V_807 )
if (stream_config->mode == IA_CSS_INPUT_MODE_BUFFERED_SENSOR &&
stream_config->online)
curr_stream->config.online = false;
#endif
#ifdef F_21
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
#if F_14 ( F_65 )
ia_css_stream_configure_rx(curr_stream);
#endif
break;
case IA_CSS_INPUT_MODE_TPG:
#if ! F_14 ( V_240 ) && F_14 ( F_65 )
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
#if ! F_14 ( V_240 ) && F_14 ( F_65 )
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
#ifdef F_58
#ifdef F_21
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
#ifdef F_58
struct ia_css_resolution effective_res;
#endif
curr_pipe = pipes[i];
curr_pipe->stream = curr_stream;
effective_res = curr_pipe->config.input_effective_res;
if (effective_res.height == 0 || effective_res.width == 0) {
effective_res = curr_pipe->stream->config.input_config.effective_res;
#ifdef F_58
#if F_14 ( F_21 )
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
#ifdef F_58
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
#ifndef F_58
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
#ifndef F_58
effective_res = curr_pipe->config.input_effective_res;
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
pipe_info = &curr_pipe->info;
for (j = 0; j < IA_CSS_PIPE_MAX_OUTPUT_STAGE; j++) {
err = sh_css_pipe_get_output_frame_info(curr_pipe,
&pipe_info->output_info[j], j);
if (err != IA_CSS_SUCCESS)
goto ERR;
}
#ifdef F_58
pipe_info->output_system_in_res_info = curr_pipe->config.output_system_in_res;
#endif
if (!spcopyonly){
err = sh_css_pipe_get_shading_info(curr_pipe,
#ifndef F_58
&pipe_info->shading_info);
#else
&pipe_info->shading_info, &curr_pipe->config) ;
#endif
if ( V_53 != V_45 )
goto V_414;
V_53 = F_257 ( V_808 ,
& V_809 -> V_810 ) ;
if ( V_53 != V_45 )
goto V_414;
for ( V_391 = 0 ; V_391 < V_765 ; V_391 ++ ) {
F_191 ( V_808 ,
& V_809 -> V_677 [ V_391 ] , V_391 ) ;
if ( V_53 != V_45 )
goto V_414;
}
}
V_328 . V_447 [ F_30 ( V_808 ) ] = V_808 ;
}
enum V_4
F_311 ( const struct V_46 * V_11 ,
struct V_811 * V_812 )
{
F_9 ( V_277 , L_196 ) ;
assert ( V_11 != NULL ) ;
assert ( V_812 != NULL ) ;
* V_812 = V_11 -> V_182 ;
return V_45 ;
}
enum V_4
F_114 ( struct V_46 * V_11 )
{
#ifndef F_58
int V_9 ;
enum V_4 V_53 ;
assert ( V_11 != NULL ) ;
F_9 ( V_277 , L_197 ) ;
for( V_9 = 0 ; V_9 < V_372 ; V_9 ++ )
if ( V_365 . V_370 [ V_9 ] . V_11 == V_11 )
{
int V_391 ;
for( V_391 = 0 ; V_391 < V_365 . V_370 [ V_9 ] . V_278 ; V_391 ++ )
if ( ( V_53 = F_312 ( & ( V_365 . V_370 [ V_9 ] . V_813 [ V_391 ] ) , & V_365 . V_370 [ V_9 ] . V_279 [ V_391 ] ) ) != V_45 )
{
if ( V_391 )
{
int V_814 ;
for( V_814 = 0 ; V_814 < V_391 ; V_814 ++ )
F_150 ( V_365 . V_370 [ V_9 ] . V_279 [ V_814 ] ) ;
}
return V_53 ;
}
V_53 = F_313 ( & ( V_365 . V_370 [ V_9 ] . V_815 ) , V_365 . V_370 [ V_9 ] . V_278 ,
V_365 . V_370 [ V_9 ] . V_279 , & ( V_365 . V_370 [ V_9 ] . V_11 ) ) ;
if ( V_53 != V_45 )
{
F_314 ( V_11 ) ;
for( V_391 = 0 ; V_391 < V_365 . V_370 [ V_9 ] . V_278 ; V_391 ++ )
F_150 ( V_365 . V_370 [ V_9 ] . V_279 [ V_391 ] ) ;
return V_53 ;
}
break;
}
F_9 ( V_277 , L_198 ) ;
return V_45 ;
#else
( void ) V_11 ;
return V_816 ;
#endif
}
enum V_4
F_115 ( struct V_46 * V_11 )
{
enum V_4 V_53 = V_45 ;
F_84 ( L_48 , V_11 ) ;
if ( ( V_11 == NULL ) || ( V_11 -> V_50 == NULL ) ) {
F_93 ( V_44 ) ;
return V_44 ;
}
F_94 ( L_199 , V_11 -> V_50 -> V_60 ) ;
F_315 ( V_11 -> V_817 ) ;
V_53 = F_134 ( V_11 ) ;
if ( V_53 != V_45 ) {
F_93 ( V_53 ) ;
return V_53 ;
}
#if ! F_14 ( V_240 )
#if F_14 ( F_21 )
if( ( V_11 -> V_12 . V_60 == V_112 ) ||
( V_11 -> V_12 . V_60 == V_102 ) )
F_38 ( V_11 ) ;
#endif
#endif
#if ! F_14 ( V_240 ) && F_14 ( F_65 )
if ( V_11 -> V_12 . V_60 == V_102 )
{
unsigned int V_506 ;
unsigned int V_103 = ( unsigned int ) ( V_11 -> V_12 . V_88 . V_103 . V_103 ) ;
for ( V_506 = 0 ; V_506 < V_645 ; V_506 ++ ) {
V_200 . V_12 . V_646 [ V_103 ] [ V_506 ] = F_252 ( V_103 , V_506 ) ;
}
}
#endif
#if ! F_14 ( V_240 )
if ( V_11 -> V_12 . V_60 != V_270 ) {
V_53 = F_8 ( V_11 ) ;
if ( V_53 != V_45 )
return V_53 ;
}
#endif
V_53 = F_237 ( V_11 ) ;
F_93 ( V_53 ) ;
return V_53 ;
}
enum V_4
F_116 ( struct V_46 * V_11 )
{
enum V_4 V_53 = V_45 ;
F_9 ( V_277 , L_200 ) ;
assert ( V_11 != NULL ) ;
assert ( V_11 -> V_50 != NULL ) ;
F_9 ( V_277 , L_201 ,
V_11 -> V_50 -> V_60 ) ;
#if ! F_14 ( V_240 ) && F_14 ( F_65 )
if ( V_11 -> V_12 . V_60 == V_102 )
{
unsigned int V_506 ;
unsigned int V_103 = ( unsigned int ) ( V_11 -> V_12 . V_88 . V_103 . V_103 ) ;
for ( V_506 = 0 ; V_506 < V_645 ; V_506 ++ ) {
V_200 . V_12 . V_646 [ V_103 ] [ V_506 ] = 0 ;
}
}
#endif
#ifndef F_58
V_53 = F_316 ( & V_11 -> V_50 -> V_55 ) ;
#else
V_53 = F_317 ( V_11 ) ;
#endif
if ( V_53 != V_45 )
return V_53 ;
return V_53 ;
}
bool
F_318 ( struct V_46 * V_11 )
{
bool V_818 ;
assert ( V_11 != NULL ) ;
#ifndef F_58
V_818 = F_250 ( & V_11 -> V_50 -> V_55 ) ;
#else
V_818 = F_249 ( V_11 ) ;
#endif
return V_818 ;
}
enum V_4
F_109 ( struct V_46 * V_11 )
{
int V_9 ;
assert ( V_11 != NULL ) ;
F_9 ( V_277 , L_202 ) ;
assert ( V_11 != NULL ) ;
for( V_9 = 0 ; V_9 < V_372 ; V_9 ++ )
if ( V_365 . V_370 [ V_9 ] . V_11 == V_11 )
{
int V_391 ;
F_9 ( V_277 , L_203 , V_9 , V_365 . V_370 [ V_9 ] . V_11 ) ;
F_314 ( V_11 ) ;
for( V_391 = 0 ; V_391 < V_365 . V_370 [ V_9 ] . V_278 ; V_391 ++ )
F_150 ( V_365 . V_370 [ V_9 ] . V_279 [ V_391 ] ) ;
F_9 ( V_277 , L_204 , V_9 , V_365 . V_370 [ V_9 ] . V_11 ) ;
break;
}
F_9 ( V_277 , L_205 ) ;
return V_45 ;
}
enum V_4
F_319 ( const struct V_1 * V_2 , enum V_208 * V_209 )
{
F_9 ( V_277 , L_206 ) ;
if ( V_2 != NULL )
* V_209 = V_2 -> V_60 ;
else
* V_209 = V_432 ;
return V_45 ;
}
enum V_73
F_320 ( const struct V_46 * V_11 )
{
return V_11 -> V_12 . V_13 . V_8 ;
}
bool
F_321 ( const struct V_46 * V_11 )
{
return ( V_11 -> V_12 . V_48 == 2 ) ;
}
struct V_51 *
F_322 ( const struct V_46 * V_11 )
{
struct V_1 * V_2 ;
assert ( V_11 != NULL ) ;
V_2 = V_11 -> V_279 [ 0 ] ;
if ( V_11 -> V_278 == 2 ) {
assert ( V_11 -> V_279 [ 1 ] != NULL ) ;
if ( V_11 -> V_279 [ 1 ] -> V_12 . V_60 == V_196 ||
V_11 -> V_279 [ 1 ] -> V_12 . V_60 == V_192 )
V_2 = V_11 -> V_279 [ 1 ] ;
}
return F_323 ( V_2 ) ;
}
struct V_51 *
F_324 ( const struct V_46 * V_11 )
{
int V_9 ;
struct V_1 * V_819 = NULL ;
for ( V_9 = 0 ; V_9 < V_11 -> V_278 ; V_9 ++ ) {
struct V_1 * V_2 = V_11 -> V_279 [ V_9 ] ;
if ( V_2 -> V_12 . V_60 == V_196 ) {
V_819 = V_2 ;
break;
}
}
if ( V_819 )
return & V_819 -> V_193 . V_197 . V_416 ;
return NULL ;
}
struct V_51 *
F_325 ( const struct V_46 * V_11 )
{
struct V_1 * V_2 ;
struct V_51 * V_820 = NULL ;
assert ( V_11 != NULL ) ;
V_2 = V_11 -> V_279 [ 0 ] ;
if ( V_11 -> V_278 == 2 ) {
assert ( V_11 -> V_279 [ 1 ] != NULL ) ;
if ( V_11 -> V_279 [ 1 ] -> V_12 . V_60 == V_196 ||
V_11 -> V_279 [ 1 ] -> V_12 . V_60 == V_192 )
V_2 = V_11 -> V_279 [ 1 ] ;
}
V_820 = F_258 ( V_2 ) ;
return V_820 ;
}
enum V_4
F_326 ( struct V_46 * V_11 , unsigned int V_821 )
{
enum V_4 V_53 = V_45 ;
struct V_1 * V_2 ;
assert ( V_11 != NULL ) ;
V_2 = V_11 -> V_50 ;
assert ( V_2 != NULL ) ;
V_2 -> V_12 . V_7 [ V_679 ] . V_647 = V_821 ;
V_2 -> V_7 [ V_679 ] . V_647 = V_821 ;
return V_53 ;
}
static struct V_51 *
F_323 ( const struct V_1 * V_2 )
{
struct V_51 * V_52 = NULL ;
assert ( V_2 != NULL ) ;
switch ( V_2 -> V_12 . V_60 ) {
case V_192 :
V_52 = (struct V_51 * ) & V_2 -> V_193 . V_194 . V_415 ;
break;
case V_196 :
V_52 = (struct V_51 * ) & V_2 -> V_193 . V_197 . V_416 ;
break;
case V_190 :
if ( V_2 -> V_12 . V_266 . V_60 == V_758 ) {
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_193 . V_433 . V_526 ; V_9 ++ ) {
if ( V_2 -> V_193 . V_433 . V_527 [ V_9 ] . V_182 -> V_183 . V_158 . V_822 ) {
V_52 = (struct V_51 * ) & V_2 -> V_193 . V_433 . V_527 [ V_9 ] ;
break;
}
}
}
else if ( V_2 -> V_12 . V_266 . V_60 == V_711 )
V_52 = (struct V_51 * ) & V_2 -> V_193 . V_433 . V_741 ;
else if ( V_2 -> V_12 . V_266 . V_60 == V_755 ||
V_2 -> V_12 . V_266 . V_60 == V_756 ) {
if ( V_2 -> V_12 . V_823 == V_726 )
V_52 = (struct V_51 * ) & V_2 -> V_193 . V_433 . V_741 ;
else if ( V_2 -> V_12 . V_823 == V_725 )
V_52 = (struct V_51 * ) & V_2 -> V_193 . V_433 . V_744 ;
}
break;
default:
break;
}
if ( V_52 && V_52 -> V_182 -> V_183 . V_158 . V_822 )
return V_52 ;
return NULL ;
}
static struct V_51 *
F_258 ( const struct V_1 * V_2 )
{
struct V_51 * V_52 = NULL ;
assert ( V_2 != NULL ) ;
switch ( V_2 -> V_12 . V_60 ) {
case V_192 :
V_52 = (struct V_51 * ) & V_2 -> V_193 . V_194 . V_415 ;
break;
case V_196 :
V_52 = (struct V_51 * ) & V_2 -> V_193 . V_197 . V_416 ;
break;
case V_190 :
if ( V_2 -> V_12 . V_266 . V_60 == V_758 ) {
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_193 . V_433 . V_526 ; V_9 ++ ) {
if ( V_2 -> V_193 . V_433 . V_527 [ V_9 ] . V_182 -> V_183 . V_158 . V_580 ) {
V_52 = (struct V_51 * ) & V_2 -> V_193 . V_433 . V_527 [ V_9 ] ;
break;
}
}
}
else if ( V_2 -> V_12 . V_266 . V_60 == V_711 )
V_52 = (struct V_51 * ) & V_2 -> V_193 . V_433 . V_741 ;
else if ( V_2 -> V_12 . V_266 . V_60 == V_755 ||
V_2 -> V_12 . V_266 . V_60 == V_756 ) {
if ( V_2 -> V_12 . V_823 == V_726 )
V_52 = (struct V_51 * ) & V_2 -> V_193 . V_433 . V_741 ;
else if ( V_2 -> V_12 . V_823 == V_725 )
V_52 = (struct V_51 * ) & V_2 -> V_193 . V_433 . V_744 ;
else
assert ( 0 ) ;
}
break;
default:
break;
}
if ( V_52 && ! V_52 -> V_182 -> V_183 . V_158 . V_580 )
V_52 = NULL ;
return V_52 ;
}
static struct V_51 *
F_260 ( const struct V_1 * V_2 )
{
struct V_51 * V_52 = NULL ;
assert ( V_2 != NULL ) ;
switch ( V_2 -> V_12 . V_60 ) {
case V_196 :
V_52 = (struct V_51 * ) & V_2 -> V_193 . V_197 . V_416 ;
break;
default:
break;
}
if ( V_52 && ! V_52 -> V_182 -> V_183 . V_158 . V_583 )
V_52 = NULL ;
return V_52 ;
}
struct V_442 *
F_327 ( const struct V_1 * V_2 )
{
assert ( V_2 != NULL ) ;
return (struct V_442 * ) & V_2 -> V_55 ;
}
unsigned int
F_30 ( const struct V_1 * V_2 )
{
assert ( V_2 != NULL ) ;
assert ( V_2 -> V_405 < V_436 ) ;
if ( V_2 -> V_405 >= V_436 )
return ( V_436 - 1 ) ;
return V_2 -> V_405 ;
}
unsigned int
F_328 ( const struct V_1 * V_2 )
{
assert ( V_2 != NULL ) ;
return ( unsigned int ) V_2 -> V_12 . V_823 ;
}
enum V_4
F_113 ( void )
{
unsigned long V_824 ;
enum V_4 V_53 = V_45 ;
F_84 ( L_28 ) ;
F_329 () ;
V_824 = V_825 ;
while( ( F_330 ( V_284 ) != V_826 ) && V_824 ) {
V_824 -- ;
F_331 () ;
}
if ( V_824 == 0 ) {
F_2 ( L_207 ) ;
return V_198 ;
}
F_332 () ;
F_184 () ;
F_333 () ;
#ifdef F_58
if ( F_334 () == false ) {
F_335 ( V_827 ) ;
}
#endif
F_93 ( V_53 ) ;
return V_53 ;
}
enum V_4
F_110 ( void )
{
unsigned long V_824 ;
enum V_4 V_53 = V_45 ;
F_84 ( L_25 ) ;
if ( ! F_118 () ) {
V_53 = V_44 ;
F_155 ( L_208 , V_53 ) ;
return V_53 ;
}
#ifndef F_58
F_336 ( V_828 ) ;
#else
if ( ! F_336 ( V_828 ) ) {
F_2 ( L_161 ) ;
F_337 () ;
F_338 ( NULL ) ;
}
#endif
F_161 ( false ) ;
V_824 = V_829 ;
while ( ! F_339 ( V_284 ) && V_824 ) {
V_824 -- ;
F_331 () ;
}
if ( ( F_330 ( V_284 ) != V_830 ) )
F_231 ( L_209 ) ;
if ( V_824 == 0 ) {
F_231 ( L_210 ) ;
F_337 () ;
}
V_824 = V_829 ;
while ( ! F_340 ( V_831 , V_832 , V_833 ) && V_824 ) {
V_824 -- ;
F_331 () ;
}
if ( V_824 == 0 ) {
F_231 ( L_211 ) ;
F_337 () ;
}
F_341 () ;
#ifndef F_58
F_342 () ;
#else
if ( F_334 () == false ) {
F_342 () ;
F_335 ( V_834 ) ;
}
#endif
F_93 ( V_53 ) ;
return V_53 ;
}
enum V_4
F_343 ( struct V_46 * V_11 )
{
struct V_1 * V_2 ;
unsigned int V_9 ;
F_9 (
V_277 ,
L_212 ) ;
if ( V_11 == NULL ) {
F_9 (
V_277 ,
L_213 ) ;
return V_44 ;
}
V_2 = V_11 -> V_835 ;
for ( V_9 = V_11 -> V_12 . V_555 ;
V_9 < V_11 -> V_12 . V_556 ; V_9 ++ ) {
F_207 ( V_9 ,
V_2 -> V_417 [ V_9 ] , V_2 -> V_444 [ V_9 ] ) ;
}
F_206
( V_11 -> V_12 . V_556 , true ) ;
F_9 (
V_277 ,
L_214 ) ;
return V_45 ;
}
void F_344 ( struct V_1 * V_2 , bool V_401 )
{
unsigned int V_507 ;
enum V_208 V_209 ;
unsigned int V_405 ;
bool V_836 ;
F_84 ( L_28 ) ;
assert ( V_2 != NULL ) ;
V_209 = V_2 -> V_60 ;
V_405 = V_2 -> V_405 ;
F_29 ( V_405 , & V_507 ) ;
#if F_14 ( V_240 ) || F_14 ( F_21 )
V_836 = true ;
#else
V_836 = V_2 -> V_11 -> V_12 . V_60 == V_270 ;
#endif
if ( V_2 -> V_60 == V_210 ) {
if ( V_836 )
F_345 ( V_507 , V_541 , V_401 ) ;
F_345 ( V_507 , V_542 , V_401 ) ;
F_345 ( V_507 , V_837 , V_401 ) ;
F_345 ( V_507 , V_838 , V_401 ) ;
#if F_14 V_839
F_345 ( V_507 , V_584 , V_401 ) ;
#endif
if ( V_2 -> V_193 . V_194 . V_415 . V_182 &&
V_2 -> V_193 . V_194 . V_415 . V_182 -> V_183 . V_158 . V_580 )
F_345 ( V_507 , V_577 , V_401 ) ;
} else if ( V_2 -> V_60 == V_406 ) {
unsigned int V_9 ;
if ( V_836 )
F_345 ( V_507 , V_541 , V_401 ) ;
F_345 ( V_507 , V_542 , V_401 ) ;
F_345 ( V_507 , V_513 , V_401 ) ;
F_345 ( V_507 , V_837 , V_401 ) ;
F_345 ( V_507 , V_838 , V_401 ) ;
#if F_14 V_839
F_345 ( V_507 , V_584 , V_401 ) ;
#endif
if ( V_2 -> V_12 . V_266 . V_60 == V_758 ) {
for ( V_9 = 0 ; V_9 < V_2 -> V_193 . V_433 . V_526 ; V_9 ++ ) {
if ( V_2 -> V_193 . V_433 . V_527 [ V_9 ] . V_182 &&
V_2 -> V_193 . V_433 . V_527 [ V_9 ] . V_182 -> V_183 . V_158 . V_580 ) {
F_345 ( V_507 , V_577 , V_401 ) ;
break;
}
}
} else if ( V_2 -> V_12 . V_266 . V_60 == V_755 ||
V_2 -> V_12 . V_266 . V_60 == V_756 ||
V_2 -> V_12 . V_266 . V_60 == V_711 ) {
if ( V_2 -> V_193 . V_433 . V_741 . V_182 &&
V_2 -> V_193 . V_433 . V_741 . V_182 -> V_183 . V_158 . V_580 )
F_345 ( V_507 , V_577 , V_401 ) ;
}
} else if ( V_2 -> V_60 == V_211 ) {
if ( V_836 )
F_345 ( V_507 , V_541 , V_401 ) ;
F_345 ( V_507 , V_542 , V_401 ) ;
if ( V_2 -> V_678 [ V_679 ] )
F_345 ( V_507 , V_513 , V_401 ) ;
F_345 ( V_507 , V_837 , V_401 ) ;
F_345 ( V_507 , V_838 , V_401 ) ;
#if F_14 V_839
F_345 ( V_507 , V_584 , V_401 ) ;
#endif
if ( V_2 -> V_193 . V_197 . V_416 . V_182 &&
V_2 -> V_193 . V_197 . V_416 . V_182 -> V_183 . V_158 . V_580 )
F_345 ( V_507 , V_577 , V_401 ) ;
if ( V_2 -> V_193 . V_197 . V_416 . V_182 &&
( V_2 -> V_193 . V_197 . V_416 . V_182 -> V_183 . V_158 . V_583
) )
F_345 ( V_507 , V_581 , V_401 ) ;
} else if ( V_2 -> V_60 == V_432 ) {
if ( V_836 )
F_345 ( V_507 , V_541 , V_401 ) ;
if ( ! V_2 -> V_11 -> V_12 . V_62 )
F_345 ( V_507 , V_542 , V_401 ) ;
#if F_14 V_839
F_345 ( V_507 , V_584 , V_401 ) ;
#endif
} else if ( V_2 -> V_60 == V_407 ) {
if ( V_836 )
F_345 ( V_507 , V_541 , V_401 ) ;
F_345 ( V_507 , V_542 , V_401 ) ;
F_345 ( V_507 , V_837 , V_401 ) ;
F_345 ( V_507 , V_838 , V_401 ) ;
#if F_14 V_839
F_345 ( V_507 , V_584 , V_401 ) ;
#endif
} else if ( V_2 -> V_60 == V_412 ) {
unsigned int V_506 ;
for ( V_506 = 0 ; V_506 < V_765 ; V_506 ++ ) {
F_345 ( V_507 , V_542 + V_506 , V_401 ) ;
if ( V_2 -> V_678 [ V_506 ] )
F_345 ( V_507 , V_513 + V_506 , V_401 ) ;
}
if ( V_836 )
F_345 ( V_507 , V_541 , V_401 ) ;
F_345 ( V_507 , V_837 , V_401 ) ;
#if F_14 V_839
F_345 ( V_507 , V_584 , V_401 ) ;
#endif
}
F_155 ( L_28 ) ;
}
static enum V_4 F_214 ( struct V_237 * V_182 , struct V_840 * V_539 )
{
V_539 -> V_841 . V_647 = 0 ;
switch ( V_182 -> V_8 ) {
case V_32 :
case V_684 :
if ( V_182 -> V_647 > V_182 -> V_239 . V_68 )
{
V_539 -> V_841 . V_647 = V_182 -> V_647 ;
}
else if ( ( V_182 -> V_647 < V_182 -> V_239 . V_68 ) && ( V_182 -> V_647 > 0 ) )
{
return V_44 ;
}
break;
default:
break;
}
return V_45 ;
}
enum V_4
F_346 ( struct V_46 * V_11 , V_143 V_599 )
{
enum V_4 V_842 ;
F_84 ( L_28 ) ;
if ( V_11 == NULL || ! V_11 -> V_12 . V_62 ) {
F_2 ( L_215 ) ;
return V_44 ;
}
if ( V_599 > V_843 ||
V_599 < V_844 ) {
F_2 ( L_216 , V_599 ) ;
return V_44 ;
}
V_842 = F_221 (
V_845 , V_599 , 0 , 0 ) ;
F_93 ( V_842 ) ;
return V_842 ;
}
enum V_4
F_347 ( struct V_1 * V_2 , V_143 V_617 , bool V_158 )
{
unsigned int V_507 ;
struct V_274 * V_275 ;
enum V_4 V_53 = V_45 ;
F_84 ( L_28 ) ;
if ( V_2 == NULL || V_2 -> V_11 == NULL ) {
F_2 ( L_217 ) ;
V_53 = V_44 ;
} else if ( ! ( V_2 -> V_12 . V_448 ) ) {
F_2 ( L_218 ) ;
V_53 = V_44 ;
} else if ( ! F_118 () ) {
F_2 ( L_219 ) ;
V_53 = V_395 ;
} else {
F_29 ( F_30 ( V_2 ) , & V_507 ) ;
V_53 = F_348 ( & ( V_2 -> V_55 ) , V_617 , & V_275 ) ;
if ( V_53 == V_45 ) {
V_53 = F_221 (
( V_265 ) V_846 ,
( V_265 ) V_507 ,
( V_265 ) V_275 -> V_635 ,
( V_158 == true ) ? 1 : 0 ) ;
if ( V_53 == V_45 ) {
if( V_158 )
F_349 ( & ( V_200 . V_2 [ V_507 ] ) , V_275 -> V_635 ) ;
else
F_350 ( & ( V_200 . V_2 [ V_507 ] ) , V_275 -> V_635 ) ;
}
}
}
F_155 ( L_220 , V_53 , V_617 , V_158 ) ;
return V_53 ;
}
enum V_4
F_351 ( struct V_1 * V_2 , V_143 V_617 , bool * V_158 )
{
struct V_274 * V_275 ;
unsigned int V_507 ;
enum V_4 V_53 = V_45 ;
F_84 ( L_28 ) ;
if ( V_2 == NULL || V_2 -> V_11 == NULL ) {
F_2 ( L_217 ) ;
V_53 = V_44 ;
} else if ( ! ( V_2 -> V_12 . V_448 ) ) {
F_2 ( L_221 ) ;
V_53 = V_44 ;
} else if ( ! F_118 () ) {
F_2 ( L_219 ) ;
V_53 = V_395 ;
} else {
F_29 ( F_30 ( V_2 ) , & V_507 ) ;
V_53 = F_348 ( & V_2 -> V_55 , V_617 , & V_275 ) ;
if ( V_53 == V_45 ) {
* V_158 = ( F_352 ( & ( V_200 . V_2 [ V_507 ] ) , V_275 -> V_635 ) ) ? true : false ;
}
}
F_155 ( L_220 , V_53 , V_617 , * V_158 ) ;
return V_53 ;
}
enum V_4
F_353 ( struct V_1 * V_2 , V_143 V_617 ,
struct V_847 * V_848 , struct V_849 * V_850 )
{
unsigned int V_851 ;
static struct V_200 V_852 ;
static struct V_853 V_854 ;
static struct V_855 V_856 ;
const struct V_294 * V_295 ;
unsigned int V_507 ;
struct V_274 * V_275 ;
enum V_4 V_53 = V_45 ;
int V_635 = 0 ;
enum V_857 V_858 ;
bool V_859 ;
F_84 ( L_28 ) ;
V_295 = & V_378 ;
if ( V_2 == NULL || V_2 -> V_11 == NULL ) {
F_2 ( L_217 ) ;
V_53 = V_44 ;
} else if ( ! ( V_2 -> V_12 . V_448 ) ) {
F_2 ( L_221 ) ;
V_53 = V_44 ;
} else if ( ! F_118 () ) {
F_2 ( L_219 ) ;
V_53 = V_395 ;
} else {
F_29 ( F_30 ( V_2 ) , & V_507 ) ;
V_53 = F_348 ( & ( V_2 -> V_55 ) , V_617 , & V_275 ) ;
if ( V_53 == V_45 ) {
V_859 = ( F_352 ( & ( V_200 . V_2 [ V_507 ] ) , V_275 -> V_635 ) ) ? true : false ;
if ( V_859 ) {
F_2 ( L_222 ) ;
V_53 = V_395 ;
} else {
V_635 = V_275 -> V_635 ;
V_851 = V_295 -> V_182 . V_183 . V_860 ;
F_354 ( V_284 ,
( unsigned int ) F_189 ( V_852 ) ,
& V_852 , sizeof( struct V_200 ) ) ;
F_226 ( V_852 . V_2 [ V_507 ] . V_861 [ V_635 ] ,
& V_854 , sizeof( struct V_853 ) ) ;
F_226 ( V_854 . V_862 ,
& V_856 , sizeof( struct V_855 ) ) ;
for ( V_858 = 0 ; V_858 < V_863 ; V_858 ++ ) {
V_856 . V_864 . V_865 [ V_866 ] [ V_858 ] . V_867 =
V_848 -> V_865 [ V_866 ] [ V_858 ] . V_867 ;
V_856 . V_864 . V_865 [ V_866 ] [ V_858 ] . V_314 =
V_848 -> V_865 [ V_866 ] [ V_858 ] . V_314 ;
V_856 . V_868 . V_864 . V_865 [ V_866 ] [ V_858 ] . V_867 =
V_850 -> V_865 [ V_866 ] [ V_858 ] . V_867 ;
V_856 . V_868 . V_864 . V_865 [ V_866 ] [ V_858 ] . V_314 =
V_850 -> V_865 [ V_866 ] [ V_858 ] . V_314 ;
}
F_216 ( V_854 . V_862 ,
& V_856 , sizeof( struct V_855 ) ) ;
}
}
}
F_155 ( L_223 , V_53 , V_617 ) ;
return V_53 ;
}
static enum V_4
F_355 ( struct V_46 * V_869 ,
struct V_1 * V_279 [] ,
bool * V_870 )
{
enum V_4 V_53 = V_45 ;
int V_9 ;
struct V_1 * V_808 ;
V_143 V_871 = 0 ;
if ( ( V_869 == NULL ) ||
( V_869 -> V_278 == 0 ) ||
( V_279 == NULL ) ||
( V_870 == NULL ) ) {
V_53 = V_44 ;
F_93 ( V_53 ) ;
return V_53 ;
}
for ( V_9 = 0 ; V_9 < V_869 -> V_278 ; V_9 ++ ) {
V_808 = V_279 [ V_9 ] ;
V_871 |= ( 1 << V_808 -> V_12 . V_60 ) ;
}
* V_870 =
( ( ( V_871 & ( 1 << V_192 ) ) ||
( V_871 & ( 1 << V_196 ) ) ) &&
( V_871 & ( 1 << V_190 ) ) &&
V_869 -> V_12 . V_62 ) ;
return V_45 ;
}
static bool
F_356 ( bool V_859 , struct V_1 * V_808 )
{
bool V_454 = false ;
if ( ( V_808 != NULL ) && V_859 ) {
if ( ( V_808 -> V_12 . V_60 == V_192 ) ||
( V_808 -> V_12 . V_60 == V_196 ) ||
( V_808 -> V_12 . V_60 == V_190 ) )
V_454 = true ;
}
return V_454 ;
}
static enum V_4
F_357 ( struct V_1 * V_808 ,
struct V_524 * V_530 )
{
enum V_4 V_53 = V_45 ;
struct V_524 V_872 ;
struct V_524 * V_761 = NULL ;
struct V_524 * V_762 = NULL ;
bool V_873 = false ;
bool V_874 = false ;
bool V_875 = false ;
if ( ( V_808 == NULL ) ||
( V_530 == NULL ) ) {
V_53 = V_44 ;
F_93 ( V_53 ) ;
return V_53 ;
}
if ( ( V_808 -> V_12 . V_60 != V_192 ) &&
( V_808 -> V_12 . V_60 != V_196 ) &&
( V_808 -> V_12 . V_60 != V_190 ) ) {
V_53 = V_44 ;
F_93 ( V_53 ) ;
return V_53 ;
}
V_873 =
( ( V_808 -> V_876 . V_239 . V_68 != 0 ) &&
( V_808 -> V_876 . V_239 . V_69 != 0 ) ) ;
V_874 =
( ( V_808 -> V_12 . V_877 . V_68 != 0 ) &&
( V_808 -> V_12 . V_877 . V_69 != 0 ) ) ;
V_875 =
( ( V_808 -> V_12 . V_878 . V_68 != 0 ) &&
( V_808 -> V_12 . V_878 . V_69 != 0 ) ) ;
V_761 = & V_808 -> V_11 -> V_12 . V_13 . V_530 ;
V_762 = & V_808 -> V_7 [ 0 ] . V_239 ;
switch ( V_808 -> V_12 . V_60 ) {
case V_192 :
if ( V_873 )
V_762 = & V_808 -> V_876 . V_239 ;
else if ( V_874 )
V_762 = & V_808 -> V_12 . V_877 ;
break;
case V_196 :
if ( V_873 )
V_762 = & V_808 -> V_876 . V_239 ;
break;
case V_190 :
if ( V_875 )
V_762 = & V_808 -> V_12 . V_878 ;
break;
case V_434 :
case V_63 :
case V_191 :
default:
F_2 ( L_224 ,
V_808 -> V_12 . V_60 ) ;
assert ( 0 ) ;
break;
}
V_53 = F_358 ( V_761 , V_762 , & V_872 ) ;
if ( V_53 == V_45 ) {
* V_530 = V_872 ;
} else {
F_94 ( L_225 , V_53 ) ;
}
return V_53 ;
}
static void
F_225 ( struct V_596 * V_879 )
{
assert ( V_879 != NULL ) ;
V_879 -> V_880 = false ;
V_879 -> type = V_570 ;
V_879 -> V_564 = NULL ;
V_879 -> V_573 = 0 ;
}
static struct V_596
* F_220 ( struct V_562 * V_564 ,
enum V_566 type ,
T_6 V_573 )
{
int V_9 ;
struct V_596 * V_879 = NULL ;
struct V_596 * V_881 = NULL ;
assert ( V_564 != NULL ) ;
assert ( ( type > V_570 ) && ( type < V_569 ) ) ;
assert ( V_573 != 0 ) ;
V_879 = & V_597 [ 0 ] ;
for ( V_9 = 0 ; V_9 < V_882 ; V_9 ++ ) {
if ( V_879 -> V_880 == false ) {
V_879 -> V_880 = true ;
V_879 -> type = type ;
V_879 -> V_564 = V_564 ;
V_879 -> V_573 = V_573 ;
V_881 = V_879 ;
break;
}
V_879 ++ ;
}
return V_881 ;
}
static struct V_596
* F_224 ( T_5 V_595 ,
enum V_566 type )
{
int V_9 ;
struct V_596 * V_879 = NULL ;
bool V_883 = false ;
V_879 = & V_597 [ 0 ] ;
for ( V_9 = 0 ; V_9 < V_882 ; V_9 ++ ) {
if ( ( V_879 -> V_880 == true ) &&
( V_879 -> type == type ) &&
( V_879 -> V_564 != NULL ) &&
( V_879 -> V_564 -> V_589 == V_595 ) ) {
V_883 = true ;
break;
}
V_879 ++ ;
}
if ( V_883 == true )
return V_879 ;
else
return NULL ;
}
