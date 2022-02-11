void
F_1 ( void )
{
V_1 . V_2 = F_2 () ;
}
static void
F_3 ( void )
{
V_3 . V_4 = ( V_5 ) V_6 . V_7 . V_8 . V_4 ;
V_3 . V_9 = ( V_10 ) V_6 . V_7 . V_8 . V_9 ;
V_3 . V_11 = ( V_10 ) V_6 . V_7 . V_8 . V_11 ;
V_3 . V_12 = ( V_10 ) V_6 . V_7 . V_13 . V_12 ;
V_3 . V_14 . V_15 = V_6 . V_7 . V_14 . V_16 ;
V_3 . V_14 . V_17 = V_6 . V_7 . V_14 . V_17 ;
#ifdef F_4
V_3 . V_14 . V_18 = V_6 . V_7 . V_14 . V_18 ;
#endif
}
void
F_5 ( enum V_19 V_20 , unsigned int V_21 , unsigned V_22 )
{
unsigned int V_23 ;
F_6 ( V_21 , & V_23 ) ;
F_3 () ;
if ( V_20 != V_24 )
V_3 . V_25 =
F_7 ( V_21 , V_22 ) ;
V_26 . V_27 [ V_23 ] . V_28 [ V_22 ] =
F_8 ( V_21 , V_22 ) ;
V_3 . V_29 = false ;
}
static void
F_9 ( const struct V_30 * V_31 )
{
unsigned int V_32 = 0 ;
assert ( V_31 != NULL ) ;
switch ( V_31 -> type ) {
case V_33 :
V_32 = V_31 -> V_34 . V_35 . V_1 ;
break;
case V_36 :
V_32 = V_31 -> V_34 . V_37 . V_1 ;
break;
case V_38 :
return;
}
F_10 ( V_39 ,
( unsigned int ) F_11 ( V_40 ) ,
& V_1 ,
sizeof( V_1 ) ) ;
}
static void
F_12 ( enum V_19 V_41 ,
unsigned int V_21 ,
const struct V_30 * V_42 )
{
if ( ! V_42 )
V_42 = & V_43 ;
F_5 ( V_41 , V_21 , 0 ) ;
F_1 () ;
F_9 ( V_42 ) ;
}
void
F_13 ( struct V_44 * V_45 )
{
const struct V_30 * V_31 = & V_43 ;
unsigned int V_46 = V_31 -> V_34 . V_35 . V_47 ;
unsigned V_48 ;
unsigned V_49 = ( unsigned int ) F_14 ( struct V_50 , V_51 ) / sizeof( int ) ;
assert ( V_45 != NULL ) ;
( void ) V_46 ;
for ( V_48 = 0 ; V_48 < sizeof( * V_45 ) / sizeof( int ) ; V_48 ++ )
( ( unsigned * ) V_45 ) [ V_48 ] = F_15 ( V_52 , V_48 + V_49 ) ;
}
void
F_16 ( unsigned int V_21 , struct V_53 * V_54 ,
unsigned V_55 )
{
enum V_19 V_41 ;
unsigned int V_23 ;
struct V_56 * V_27 ;
V_5 V_57 = 0 ;
assert ( V_54 != NULL ) ;
V_41 = V_58 ;
F_6 ( V_21 , & V_23 ) ;
V_27 = & V_26 . V_27 [ V_23 ] ;
V_27 -> V_59 . V_60 . V_61 = V_54 -> V_62 ;
V_27 -> V_63 = 1 ;
V_27 -> V_41 = V_41 ;
V_27 -> V_21 = V_21 ;
V_27 -> V_23 = V_23 ;
V_27 -> V_64 = 0x0 ;
V_27 -> V_65 = V_66 ;
if ( V_27 -> V_67 == 0 ) {
F_17 ( V_27 -> V_67 ,
( V_5 ) V_68 ,
( V_5 ) V_69 , 1 ) ;
F_17 ( V_27 -> V_67 ,
( V_5 ) V_70 ,
( V_5 ) V_69 , 1 ) ;
}
F_18 ( L_1 ,
V_27 -> V_41 , V_27 -> V_67 ) ;
#if ! F_19 ( V_71 )
V_26 . V_72 . V_73 . V_74 = ( V_5 ) V_55 ;
#else
( void ) V_55 ;
#endif
V_3 . V_75 = V_57 ;
V_3 . V_76 = V_77 ;
V_3 . V_78 =
( unsigned int ) V_79 ;
F_20 ( V_54 , 0 ) ;
F_12 ( V_41 , V_21 , & V_43 ) ;
}
static void
F_21 ( struct V_53 * V_54 ,
unsigned V_21 ,
unsigned V_55 ,
unsigned V_80 ,
enum V_81 V_82 ,
unsigned int V_83 )
{
enum V_19 V_41 ;
unsigned int V_23 ;
V_5 V_57 = 0 ;
struct V_56 * V_27 ;
assert ( V_54 != NULL ) ;
{
V_5 V_29 ;
V_29 = V_3 . V_29 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . V_29 = V_29 ;
}
V_41 = V_24 ;
F_6 ( V_21 , & V_23 ) ;
V_27 = & V_26 . V_27 [ V_23 ] ;
V_27 -> V_59 . V_84 . V_85 = V_54 -> V_34 . V_86 . V_85 ;
V_27 -> V_59 . V_84 . V_87 = V_54 -> V_34 . V_86 . V_87 ;
V_27 -> V_59 . V_84 . V_88 = V_54 -> V_34 . V_88 ;
V_27 -> V_59 . V_84 . V_89 = V_54 -> V_34 . V_89 ;
V_27 -> V_59 . V_84 . V_80 = V_80 ;
V_27 -> V_63 = 1 ;
V_27 -> V_41 = V_41 ;
if ( V_82 == V_90 )
V_27 -> V_64 =
( V_91 << V_23 ) ;
else
V_27 -> V_64 = V_82 ;
V_27 -> V_65 = V_66 ;
if ( V_27 -> V_67 == 0 ) {
F_17 ( V_27 -> V_67 ,
( V_5 ) V_68 ,
( V_5 ) V_69 , 1 ) ;
F_17 ( V_27 -> V_67 ,
( V_5 ) V_70 ,
( V_5 ) V_69 , 1 ) ;
}
F_18 ( L_1 ,
V_27 -> V_41 , V_27 -> V_67 ) ;
#if ! F_19 ( V_71 )
V_26 . V_72 . V_73 . V_74 = ( V_5 ) V_55 ;
#else
( void ) V_55 ;
#endif
V_3 . V_75 = V_57 ;
V_3 . V_92 = 0x0 ;
V_3 . V_76 = V_77 ;
V_3 . V_78 = ( unsigned int ) V_93 ;
V_3 . V_83 = ( V_5 ) V_83 ;
F_20 ( V_54 , 0 ) ;
F_22 ( V_54 ) ;
}
static void
F_23 ( struct V_53 * V_54 ,
unsigned V_21 , unsigned V_80 , unsigned int V_83 )
{
enum V_19 V_41 ;
unsigned int V_23 ;
V_5 V_57 = 0 ;
struct V_56 * V_27 ;
#if F_19 V_94
enum V_95 V_96 ;
#endif
assert ( V_54 != NULL ) ;
{
V_5 V_29 ;
V_29 = V_3 . V_29 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . V_29 = V_29 ;
}
V_41 = V_24 ;
F_6 ( V_21 , & V_23 ) ;
V_27 = & V_26 . V_27 [ V_23 ] ;
V_27 -> V_59 . V_84 . V_85 = V_54 -> V_34 . V_86 . V_85 ;
V_27 -> V_59 . V_84 . V_87 = V_54 -> V_34 . V_86 . V_87 ;
V_27 -> V_59 . V_84 . V_88 = V_54 -> V_34 . V_88 ;
V_27 -> V_59 . V_84 . V_89 = V_54 -> V_34 . V_89 ;
V_27 -> V_59 . V_84 . V_80 = V_80 ;
V_27 -> V_63 = 1 ;
V_27 -> V_41 = V_41 ;
V_27 -> V_64 = 0x0 ;
V_27 -> V_65 = V_66 ;
F_24 ( & V_3 . V_97 ) ;
V_3 . V_75 = V_57 ;
V_3 . V_92 = 0x0 ;
V_3 . V_76 = V_77 ;
V_3 . V_78 = ( unsigned int ) V_98 ;
V_3 . V_83 = ( V_5 ) V_83 ;
F_20 ( V_54 , 0 ) ;
#if F_19 V_94
if ( V_27 -> V_99 . V_85 > 0 ) {
F_25 ( V_100 , V_23 , & V_96 ) ;
F_26 ( & V_3 . V_97 . V_101 , V_96 , V_102 , V_100 ) ;
}
#endif
F_22 ( V_54 ) ;
}
unsigned int
F_27 ( void )
{
const struct V_30 * V_31 = & V_43 ;
unsigned int V_46 = V_31 -> V_34 . V_35 . V_47 ;
unsigned int V_49 = ( unsigned int ) F_14 ( struct V_50 ,
V_103 ) / sizeof( int ) ;
( void ) V_46 ;
return F_15 ( V_52 , V_49 ) ;
}
unsigned int
F_28 ( unsigned int V_104 )
{
const struct V_30 * V_31 = & V_43 ;
unsigned int V_46 = V_31 -> V_34 . V_35 . V_47 ;
unsigned int V_49 = ( unsigned int ) F_14 ( struct V_50 , V_105 )
/ sizeof( int ) ;
( void ) V_46 ;
return F_15 ( V_52 , V_49 + V_104 ) ;
}
static void
F_26 ( struct V_106 * V_107 ,
const enum V_95 V_96 ,
const T_1 V_108 ,
const enum V_109 V_110 )
{
assert ( V_110 < V_111 ) ;
if ( V_96 > V_112 ) {
assert ( V_96 < V_113 ) ;
if ( ( V_96 < V_113 ) )
{
V_107 -> V_114 . V_96 = V_96 ;
}
} else {
assert ( V_108 != V_102 ) ;
V_107 -> V_114 . V_108 = V_108 ;
}
V_107 -> V_110 = V_110 ;
}
static void
F_29 ( struct V_115 * V_116 ,
const struct V_53 * V_117 )
{
assert ( V_117 != NULL ) ;
F_30 ( V_118 ,
L_2 ) ;
F_26 ( & V_116 -> V_119 ,
V_117 -> V_120 ,
V_117 -> V_121 ,
V_117 -> V_110 ) ;
F_31 ( & V_116 -> V_34 , & V_117 -> V_34 ) ;
switch ( V_117 -> V_34 . V_122 ) {
case V_123 :
case V_124 :
V_116 -> V_125 . V_84 . V_49 = V_117 -> V_125 . V_84 . V_49 ;
break;
case V_126 :
case V_127 :
V_116 -> V_125 . V_128 . V_49 = V_117 -> V_125 . V_128 . V_49 ;
break;
case V_129 :
V_116 -> V_125 . V_130 . V_131 . V_49 =
V_117 -> V_125 . V_130 . V_131 . V_49 ;
V_116 -> V_125 . V_130 . V_132 . V_49 =
V_117 -> V_125 . V_130 . V_132 . V_49 ;
V_116 -> V_125 . V_130 . V_133 . V_49 =
V_117 -> V_125 . V_130 . V_133 . V_49 ;
break;
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
V_116 -> V_125 . V_139 . V_49 = V_117 -> V_125 . V_139 . V_49 ;
break;
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
V_116 -> V_125 . V_147 . V_148 . V_49 =
V_117 -> V_125 . V_147 . V_148 . V_49 ;
V_116 -> V_125 . V_147 . V_149 . V_49 =
V_117 -> V_125 . V_147 . V_149 . V_49 ;
break;
case V_150 :
case V_151 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
V_116 -> V_125 . V_157 . V_148 . V_49 =
V_117 -> V_125 . V_157 . V_148 . V_49 ;
V_116 -> V_125 . V_157 . V_158 . V_49 =
V_117 -> V_125 . V_157 . V_158 . V_49 ;
V_116 -> V_125 . V_157 . V_159 . V_49 =
V_117 -> V_125 . V_157 . V_159 . V_49 ;
break;
case V_160 :
V_116 -> V_125 . V_161 . V_131 . V_49 =
V_117 -> V_125 . V_161 . V_131 . V_49 ;
V_116 -> V_125 . V_161 . V_162 . V_49 =
V_117 -> V_125 . V_161 . V_162 . V_49 ;
V_116 -> V_125 . V_161 . V_163 . V_49 =
V_117 -> V_125 . V_161 . V_163 . V_49 ;
V_116 -> V_125 . V_161 . V_164 . V_49 =
V_117 -> V_125 . V_161 . V_164 . V_49 ;
V_116 -> V_125 . V_161 . V_133 . V_49 =
V_117 -> V_125 . V_161 . V_133 . V_49 ;
V_116 -> V_125 . V_161 . V_165 . V_49 =
V_117 -> V_125 . V_161 . V_165 . V_49 ;
break;
case V_166 :
V_116 -> V_125 . V_167 . V_121 . V_49 =
V_117 -> V_125 . V_167 . V_121 . V_49 ;
break;
default:
memset ( & V_116 -> V_125 , 0 , sizeof( V_116 -> V_125 ) ) ;
break;
}
}
static enum V_168
F_32 ( const struct V_53 * V_169 )
{
if ( V_169 == NULL )
return V_170 ;
switch ( V_169 -> V_34 . V_122 ) {
case V_160 :
case V_153 :
case V_123 :
case V_124 :
case V_150 :
case V_134 :
case V_138 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_136 :
case V_137 :
case V_171 :
break;
default:
return V_170 ;
}
F_29 ( & V_3 . V_97 . V_172 , V_169 ) ;
return V_173 ;
}
static enum V_168
F_20 ( const struct V_53 * V_169 ,
unsigned V_174 )
{
if ( V_169 == NULL )
return V_170 ;
switch ( V_169 -> V_34 . V_122 ) {
case V_150 :
case V_151 :
case V_152 :
case V_155 :
case V_156 :
case V_153 :
case V_154 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_145 :
case V_144 :
case V_146 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_126 :
case V_127 :
case V_129 :
case V_124 :
case V_123 :
case V_160 :
case V_166 :
break;
default:
return V_170 ;
}
F_29 ( & V_3 . V_97 . V_175 [ V_174 ] , V_169 ) ;
return V_173 ;
}
static enum V_168
F_33 ( const struct V_53 * V_169 )
{
if ( V_169 == NULL )
return V_170 ;
switch ( V_169 -> V_34 . V_122 ) {
case V_141 :
case V_142 :
case V_144 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_150 :
case V_155 :
case V_143 :
case V_138 :
break;
default:
return V_170 ;
}
F_29 ( & V_3 . V_97 . V_176 , V_169 ) ;
return V_173 ;
}
void F_34 (
const T_2 * V_177 ,
const T_2 * V_178 ,
const V_5 V_83
)
{
assert ( V_83 < V_179 ) ;
assert ( V_177 != NULL ) ;
V_26 . V_72 . V_73 . V_180 [ V_83 ] . V_177 = * V_177 ;
V_26 . V_72 . V_73 . V_181 = true ;
if ( V_178 != NULL ) {
V_26 . V_72 . V_73 . V_180 [ V_83 ] . V_178 = * V_178 ;
V_26 . V_72 . V_73 . V_182 = true ;
}
return;
}
void
F_35 ( int V_183 ,
int V_184 ,
enum V_185 V_186 )
{
V_26 . V_72 . V_187 . V_188 = false ;
V_26 . V_72 . V_187 . V_183 = V_183 ;
V_26 . V_72 . V_187 . V_184 = V_184 ;
V_26 . V_72 . V_187 . V_186 = V_186 ;
V_26 . V_72 . V_189 = true ;
V_3 . V_29 = true ;
}
void
F_36 ( int V_87 , int V_85 ,
int V_190 ,
int V_191 )
{
V_26 . V_72 . V_192 . V_87 = V_87 ;
V_26 . V_72 . V_192 . V_85 = V_85 ;
V_26 . V_72 . V_192 . V_190 = V_190 ;
V_26 . V_72 . V_192 . V_191 = V_191 ;
}
void
F_37 ( int V_193 ,
int V_194 ,
int V_195 ,
int V_196 ,
int V_197 )
{
V_26 . V_72 . V_198 . V_193 = V_193 ;
V_26 . V_72 . V_198 . V_194 = V_194 ;
V_26 . V_72 . V_198 . V_195 = V_195 ;
V_26 . V_72 . V_198 . V_196 = V_196 ;
V_26 . V_72 . V_198 . V_197 = V_197 ;
}
void
F_38 ( int V_199 )
{
V_26 . V_72 . V_200 . V_199 = V_199 ;
}
void
F_39 ( bool V_201 )
{
V_26 . V_72 . V_202 = true ;
V_26 . V_72 . V_201 = V_201 ;
}
void
F_40 ( bool V_14 )
{
#if ! F_19 ( V_203 )
V_26 . V_72 . V_204 = V_14 ;
#else
( void ) V_14 ;
#endif
}
void
F_41 ( bool V_205 )
{
V_26 . V_72 . V_206 = V_205 ;
}
static enum V_168
F_42 ( const struct V_207 * args )
{
enum V_168 V_208 = V_173 ;
int V_48 ;
assert ( args != NULL ) ;
if ( args -> V_209 )
V_208 = F_32 ( args -> V_209 ) ;
if ( V_208 == V_173 && args -> V_210 )
V_208 = F_33 ( args -> V_210 ) ;
for ( V_48 = 0 ; V_48 < V_211 ; V_48 ++ ) {
if ( V_208 == V_173 && args -> V_54 [ V_48 ] )
V_208 = F_20 ( args -> V_54 [ V_48 ] , V_48 ) ;
}
if ( V_208 != V_173 ) assert ( false ) ;
return V_208 ;
}
static void
F_43 ( bool V_55 ,
enum V_212 V_213 ,
bool V_214 ,
V_5 V_83 )
{
#if ! F_19 ( V_71 )
V_26 . V_72 . V_73 . V_74 = V_55 ;
#else
( void ) V_55 ;
#endif
V_26 . V_72 . V_214 = ( V_5 ) V_214 ;
if ( V_83 == V_215 ) return;
#if ! F_19 ( V_71 )
assert ( V_83 < V_179 ) ;
V_26 . V_72 . V_73 . V_180 [ V_83 ] . V_216 = V_213 ;
#else
( void ) V_213 ;
#endif
}
void
F_44 ( struct V_217 * V_34 )
{
assert ( V_34 != NULL ) ;
V_6 . V_7 = * V_34 ;
}
static enum V_168
F_45 ( struct V_218 * V_167 )
{
enum V_168 V_208 ;
V_208 = F_46 (
& V_167 -> V_219 ,
& V_167 -> V_220 ,
V_221 ) ;
if ( V_208 != V_173 )
return V_208 ;
V_208 = F_46 (
& V_167 -> V_219 ,
& V_167 -> V_220 ,
V_222 ) ;
if ( V_208 != V_173 )
return V_208 ;
return V_173 ;
}
static bool
F_47 ( struct V_223 * V_22 )
{
assert ( V_22 != NULL ) ;
return V_22 -> V_224 != V_225 ;
}
static enum V_168
F_48 (
const struct V_56 * V_13 ,
const struct V_218 * V_167 ,
const struct V_207 * args ,
bool V_55 ,
bool V_226 )
{
enum V_168 V_208 = V_173 ;
#ifdef F_4
struct V_227 * V_27 = F_49 ( V_13 -> V_21 ) ;
const struct V_228 * V_86 ;
#endif
F_50 ( V_167 , & V_167 -> V_229 ) ;
F_51 ( V_167 , & args -> V_230 [ 0 ] -> V_34 ) ;
F_52 ( V_13 , V_167 , & V_167 -> V_229 ) ;
F_53 ( V_167 , & args -> V_54 [ 0 ] -> V_34 ) ;
F_54 ( V_167 , & args -> V_210 -> V_34 ) ;
F_55 ( V_167 , args -> V_231 ) ;
F_53 ( V_167 , & args -> V_54 [ 0 ] -> V_34 ) ;
#ifdef F_4
F_56 ( V_167 , V_13 -> V_232 . V_233 ,
V_13 -> V_232 . V_234 ) ;
#endif
F_57 ( V_167 , & args -> V_209 -> V_34 ) ;
F_58 ( V_167 , & args -> V_54 [ 0 ] -> V_34 ) ;
F_59 ( V_167 , & args -> V_54 [ 0 ] -> V_34 ) ;
F_60 ( V_13 , V_167 , & args -> V_209 -> V_34 , & V_167 -> V_229 , V_55 , V_226 ) ;
F_61 ( V_167 , ( const struct V_53 * * ) args -> V_230 , V_13 -> V_235 ) ;
F_62 ( V_167 , ( const struct V_53 * * ) args -> V_236 ) ;
F_63 ( V_167 , args ) ;
return V_208 ;
}
static void
F_64 ( const struct V_218 * V_167 )
{
unsigned int V_48 ;
if ( ! V_167 -> V_34 -> V_237 . V_238 . V_45 )
return;
for ( V_48 = 0 ; V_48 < V_239 ; V_48 ++ ) {
V_240 [ V_48 ] ( V_167 ) ;
}
}
static void
F_65 ( struct V_106 * V_119 )
{
V_119 -> V_114 . V_96 = V_112 ;
V_119 -> V_110 = V_241 ;
}
static void
F_24 ( struct V_242 * V_97 )
{
unsigned int V_48 ;
F_65 ( & V_97 -> V_172 . V_119 ) ;
for ( V_48 = 0 ; V_48 < V_211 ; V_48 ++ ) {
F_65 ( & V_97 -> V_175 [ V_48 ] . V_119 ) ;
}
F_65 ( & V_97 -> V_176 . V_119 ) ;
F_65 ( & V_97 -> V_243 ) ;
F_65 ( & V_97 -> V_244 ) ;
#if F_19 V_94
F_65 ( & V_97 -> V_101 ) ;
#endif
}
static enum V_168
F_66 ( struct V_223 * V_22 ,
unsigned int V_21 ,
bool V_245 ,
unsigned int V_83 ,
bool V_55 )
{
struct V_218 * V_167 ;
const struct V_30 * V_246 ;
const struct V_207 * args ;
unsigned V_57 ;
const char * V_247 = L_3 ;
const struct V_248 * V_34 = NULL ;
static struct V_218 V_249 ;
const struct V_250 * V_251 = NULL ;
struct V_252 V_253 ;
struct V_252 * V_254 = & V_253 ;
enum V_168 V_208 = V_173 ;
assert ( V_22 != NULL ) ;
V_167 = V_22 -> V_167 ;
V_246 = V_22 -> V_246 ;
args = & V_22 -> args ;
V_57 = V_22 -> V_57 ;
if ( V_167 ) {
V_34 = V_167 -> V_34 ;
V_247 = ( const char * ) ( V_34 -> V_255 -> V_256 ) ;
V_251 = & V_34 -> V_255 -> V_257 . V_255 ;
F_67 ( V_254 , & V_167 -> V_220 , & V_167 -> V_219 ) ;
} else if ( V_246 ) {
const struct V_258 * V_259 [ V_211 ] = { NULL } ;
if ( args -> V_54 [ 0 ] )
V_259 [ 0 ] = & args -> V_54 [ 0 ] -> V_34 ;
V_34 = & V_246 -> V_34 . V_260 ;
F_68 ( V_34 , false , false ,
V_261 ,
args -> V_209 ? & args -> V_209 -> V_34 : NULL ,
NULL ,
V_259 ,
args -> V_210 ? & args -> V_210 -> V_34
: NULL ,
& V_249 ,
NULL ,
- 1 , true ) ;
V_167 = & V_249 ;
V_167 -> V_34 = V_34 ;
V_247 = F_69 ( V_246 ) ;
V_251 = & V_246 -> V_255 ;
V_254 = (struct V_252 * ) & V_246 -> V_262 ;
} else {
assert ( V_22 -> V_224 != V_225 ) ;
return V_263 ;
}
V_208 = F_70 ( V_167 ,
( const char * ) V_247 ,
V_251 ,
args ,
V_21 ,
V_57 ,
V_245 ,
V_254 ,
V_83 ,
V_55 ) ;
return V_208 ;
}
static void
F_71 ( struct V_223 * V_22 ,
unsigned V_21 ,
bool V_55 ,
enum V_81 V_264 ,
unsigned int V_83 )
{
const struct V_207 * args = & V_22 -> args ;
assert ( V_22 != NULL ) ;
switch ( V_22 -> V_224 ) {
case V_93 :
F_21 ( args -> V_54 [ 0 ] ,
V_21 , V_55 ,
V_22 -> V_80 ,
V_264 , V_83 ) ;
break;
case V_79 :
assert ( false ) ;
case V_98 :
F_23 ( args -> V_54 [ 0 ] ,
V_21 , V_22 -> V_80 , V_83 ) ;
break;
case V_225 :
assert ( false ) ;
}
}
void
F_72 ( struct V_265 * V_266 ,
enum V_19 V_20 ,
V_5 V_21 ,
bool V_245 ,
bool V_55 ,
bool V_267 ,
bool V_268 ,
unsigned int V_269 ,
enum V_81 V_264 ,
enum V_185 V_186 ,
const struct V_270 * V_271 ,
const struct V_272 * V_273 ,
#if ! F_19 ( V_203 )
const T_3 V_274
#endif
#ifdef F_4
,
const struct V_275 * V_276 ,
const struct V_277 * V_278
#endif
)
{
struct V_223 * V_22 = NULL ;
struct V_218 * V_279 = NULL ;
struct V_227 * V_27 = NULL ;
unsigned V_75 ;
enum V_19 V_41 = V_20 ;
unsigned int V_23 ;
V_5 V_83 , V_280 ;
assert ( V_266 != NULL ) ;
#if ! F_19 ( V_203 )
assert ( V_266 -> V_281 != NULL ) ;
V_279 = V_266 -> V_281 -> V_167 ;
if ( V_186 == V_282 ||
V_186 == V_283 ) {
assert ( V_274 < V_284 ) ;
if ( V_274 >= V_284 )
return;
V_83 = ( V_5 ) ( V_274 - V_285 ) ;
} else if ( V_186 == V_286 ) {
V_83 = V_215 ;
} else {
V_83 = 0x0 ;
}
#else
( void ) V_186 ;
V_83 = V_215 ;
#endif
F_6 ( V_21 , & V_23 ) ;
memset ( & V_26 . V_27 [ V_23 ] , 0 , sizeof( struct V_56 ) ) ;
for ( V_22 = V_266 -> V_281 , V_75 = 0 ; V_22 ; V_22 = V_22 -> V_287 , V_75 ++ ) {
V_22 -> V_57 = V_75 ;
F_73 ( V_22 , V_20 ) ;
}
V_266 -> V_63 = V_75 ;
if ( V_279 != NULL ) {
F_43 ( V_55 , V_279 -> V_213 ,
V_268 , V_83 ) ;
}
#if F_19 ( V_288 ) || F_19 ( V_289 )
if ( ( V_266 -> V_63 == 1 ) && V_266 -> V_281 &&
( V_266 -> V_281 -> V_224 == V_98 ) )
V_26 . V_72 . V_214 = true ;
#endif
F_74 () ;
V_26 . V_27 [ V_23 ] . V_63 = 0 ;
V_26 . V_27 [ V_23 ] . V_41 = V_41 ;
V_26 . V_27 [ V_23 ] . V_23 = V_23 ;
V_26 . V_27 [ V_23 ] . V_21 = V_21 ;
V_26 . V_27 [ V_23 ] . V_290 = V_266 -> V_290 ;
V_26 . V_27 [ V_23 ] . V_65 = V_266 -> V_65 ;
V_26 . V_27 [ V_23 ] . V_269 = V_269 ;
#if ! F_19 ( V_203 )
V_26 . V_27 [ V_23 ] . V_291
= ( V_292 ) V_186 ;
V_26 . V_27 [ V_23 ] . V_274 = V_274 ;
#endif
V_26 . V_27 [ V_23 ] . V_235 = ( V_292 ) V_266 -> V_235 ;
if ( F_75 ( V_266 ) ) {
V_26 . V_27 [ V_23 ] . V_64 =
V_91 << V_23 ;
}
if ( V_267 )
V_26 . V_27 [ V_23 ] . V_64 = 0 ;
V_26 . V_27 [ V_23 ] . V_67 = V_266 -> V_67 ;
V_27 = F_49 ( V_21 ) ;
assert ( V_27 != NULL ) ;
if ( V_27 == NULL ) {
return;
}
V_26 . V_27 [ V_23 ] . V_293 = F_76 ( V_27 ) ;
#if F_19 ( V_94 )
if ( V_273 != NULL && V_273 -> V_294 > 0 ) {
V_26 . V_27 [ V_23 ] . V_99 . V_87 = V_273 -> V_295 . V_87 ;
V_26 . V_27 [ V_23 ] . V_99 . V_85 = V_273 -> V_295 . V_85 ;
V_26 . V_27 [ V_23 ] . V_99 . V_296 = V_273 -> V_296 ;
V_26 . V_27 [ V_23 ] . V_99 . V_294 = V_273 -> V_294 ;
F_77 (
V_271 -> V_297 , V_298 ,
& V_26 . V_27 [ V_23 ] . V_99 . V_122 ) ;
}
#else
( void ) V_271 ;
( void ) V_273 ;
#endif
#if F_19 ( V_299 )
V_26 . V_27 [ V_23 ] . V_300 = ( V_292 ) V_112 ;
if ( V_24 != V_41 ) {
F_25 ( V_301 , V_23 , (enum V_95 * ) ( & V_26 . V_27 [ V_23 ] . V_300 ) ) ;
}
#endif
#ifdef F_4
if ( V_276 != NULL &&
V_278 != NULL && V_278 -> V_302 . V_303 == 0 ) {
V_26 . V_27 [ V_23 ] . V_232 . V_233
= ( V_292 ) V_276 -> V_304 ;
V_26 . V_27 [ V_23 ] . V_232 . V_234
= ( V_292 ) V_276 -> V_148 ;
} else {
V_26 . V_27 [ V_23 ] . V_232 . V_233 = 0 ;
V_26 . V_27 [ V_23 ] . V_232 . V_234 = 0 ;
}
#endif
F_18 ( L_1 ,
V_41 , V_26 . V_27 [ V_23 ] . V_67 ) ;
for ( V_22 = V_266 -> V_281 , V_75 = 0 ; V_22 ; V_22 = V_22 -> V_287 , V_75 ++ ) {
V_26 . V_27 [ V_23 ] . V_63 ++ ;
if ( F_47 ( V_22 ) ) {
F_71 ( V_22 , V_21 , V_55 ,
V_264 , V_83 ) ;
} else {
if ( ( V_22 -> V_57 != 0 ) || F_78 ( V_266 -> V_67 ) )
V_280 = V_215 ;
else
V_280 = V_83 ;
F_66 ( V_22 , V_21 ,
V_245 , V_280 , V_55 ) ;
}
F_5 ( V_41 , V_21 , V_75 ) ;
}
V_26 . V_27 [ V_23 ] . V_64 |= ( V_292 )
( V_266 -> V_305 << V_306 ) ;
F_1 () ;
}
void
F_79 ( unsigned int V_21 )
{
unsigned int V_23 ;
F_6 ( V_21 , & V_23 ) ;
V_26 . V_27 [ V_23 ] . V_63 = 0 ;
}
bool F_80 ( enum V_307 V_308 )
{
unsigned int V_309 = V_43 . V_34 . V_35 . V_310 ;
unsigned int V_49 = ( unsigned int ) F_14 ( struct V_311 , V_308 )
/ sizeof( int ) ;
enum V_307 V_312 = V_313 ;
( void ) V_309 ;
V_312 = F_15 ( V_310 , V_49 ) ;
if ( V_312 != V_314 )
F_81 ( L_4 , V_312 ) ;
F_82 ( V_310 , V_49 , V_308 ) ;
return ( V_312 == V_314 ) ;
}
enum V_307
F_83 ( void )
{
unsigned int V_309 = V_43 . V_34 . V_35 . V_310 ;
unsigned int V_49 = ( unsigned int ) F_14 ( struct V_311 , V_308 )
/ sizeof( int ) ;
( void ) V_309 ;
return (enum V_307 ) F_15 ( V_310 , V_49 ) ;
}
void
F_74 ( void )
{
unsigned int V_309 = V_43 . V_34 . V_35 . V_310 ;
( void ) V_309 ;
}
void
F_84 (
unsigned V_315 ,
struct V_53 * V_169 ,
struct V_316 * V_99 )
{
unsigned int V_309 ;
unsigned int V_49 ;
( void ) V_309 ;
assert ( V_315 < V_317 ) ;
V_309 = V_43 . V_34 . V_35 . V_310 ;
V_49 = ( unsigned int ) F_14 ( struct V_311 , V_318 )
/ sizeof( int ) ;
V_49 += V_315 ;
F_82 ( V_310 , V_49 , V_169 ? V_169 -> V_121 : 0 ) ;
V_49 = ( unsigned int ) F_14 ( struct V_311 , V_319 )
/ sizeof( int ) ;
V_49 += V_315 ;
F_82 ( V_310 , V_49 , V_99 ? V_99 -> V_320 : 0 ) ;
}
void
F_85 (
unsigned V_315 ,
struct V_53 * V_169 )
{
unsigned int V_309 ;
unsigned int V_49 ;
( void ) V_309 ;
assert ( V_315 < ( V_321 * V_322 ) ) ;
V_309 = V_43 . V_34 . V_35 . V_310 ;
V_49 = ( unsigned int ) F_14 ( struct V_311 , V_323 )
/ sizeof( int ) ;
V_49 += V_315 ;
F_82 ( V_310 , V_49 ,
V_169 ? V_169 -> V_121 : 0 ) ;
}
void
F_86 (
unsigned V_315 ,
struct V_316 * V_99 )
{
unsigned int V_309 ;
unsigned int V_324 ;
( void ) V_309 ;
assert ( V_315 < ( V_321 * V_322 ) ) ;
V_309 = V_43 . V_34 . V_35 . V_310 ;
V_324 = F_14 ( struct V_311 , V_325 )
/ sizeof( int ) ;
V_324 += V_315 ;
F_82 ( V_310 , V_324 ,
V_99 ? V_99 -> V_320 : 0 ) ;
}
void
F_87 ( unsigned V_326 )
{
unsigned int V_309 ;
unsigned int V_49 ;
( void ) V_309 ;
V_309 = V_43 . V_34 . V_35 . V_310 ;
V_49 = ( unsigned int ) F_14 ( struct V_311 , V_327 )
/ sizeof( int ) ;
F_82 ( V_310 , V_49 , V_326 ) ;
}
void
F_88 ( unsigned V_326 , bool V_328 )
{
const struct V_30 * V_31 ;
unsigned int V_309 ;
unsigned int V_329 , V_330 ;
unsigned int V_49 , V_331 ;
( void ) V_309 ;
V_31 = & V_43 ;
V_309 = V_31 -> V_34 . V_35 . V_310 ;
if ( V_328 ) {
V_49 = ( unsigned int ) F_14 ( struct V_311 , V_332 )
/ sizeof( int ) ;
V_330 = F_15 ( V_310 , V_49 ) ;
V_329 = V_326 - V_330 ;
V_331 = ( unsigned int ) F_14 ( struct V_311 , V_333 )
/ sizeof( int ) ;
F_82 ( V_310 , V_331 , V_329 ) ;
} else
V_49 = ( unsigned int ) F_14 ( struct V_311 , V_334 )
/ sizeof( int ) ;
F_82 ( V_310 , V_49 , V_326 ) ;
}
void
F_89 ( void )
{
int V_48 ;
unsigned int V_309 = V_43 . V_34 . V_35 . V_310 ;
unsigned int V_49 ;
struct V_335 V_336 ;
V_336 . V_337 = V_338 ;
V_336 . V_339 = V_340 ;
( void ) V_309 ;
assert ( sizeof( V_336 ) % V_341 == 0 ) ;
for ( V_48 = 0 ; V_48 < V_342 ; V_48 ++ ) {
V_49 = ( unsigned int ) F_14 ( struct V_311 ,
V_343 [ V_48 ] ) ;
assert ( V_49 % V_341 == 0 ) ;
F_10 ( V_39 ,
( unsigned int ) F_11 ( V_310 ) + V_49 ,
& V_336 , sizeof( V_336 ) ) ;
}
}
enum V_168
F_90 ( struct V_227 * V_27 ,
unsigned int V_337 ,
unsigned int V_339 )
{
unsigned int V_309 = V_43 . V_34 . V_35 . V_310 ;
unsigned int V_49 ;
struct V_335 V_344 ;
unsigned int V_21 ;
assert ( V_27 != NULL ) ;
assert ( V_342 == V_345 ) ;
#ifndef F_91
assert ( V_337 <= V_346 ) ;
assert ( V_339 <= V_346 ) ;
#endif
( void ) V_309 ;
F_18 ( L_5 , V_337 , V_339 ) ;
V_344 . V_337 = ( V_10 ) V_337 ;
V_344 . V_339 = ( V_10 ) V_339 ;
V_21 = F_92 ( V_27 ) ;
if ( V_21 >= V_342 )
return V_263 ;
V_49 = ( unsigned int ) F_14 ( struct V_311 ,
V_343 [ V_21 ] ) ;
assert ( V_49 % V_341 == 0 ) ;
F_10 ( V_39 ,
( unsigned int ) F_11 ( V_310 ) + V_49 ,
& V_344 , sizeof( V_344 ) ) ;
return V_173 ;
}
enum V_168
F_93 ( const struct V_227 * V_27 ,
unsigned int * V_337 ,
unsigned int * V_339 )
{
unsigned int V_309 = V_43 . V_34 . V_35 . V_310 ;
unsigned int V_49 ;
struct V_335 V_344 ;
unsigned int V_21 ;
( void ) V_309 ;
F_94 ( L_3 ) ;
assert ( V_27 != NULL ) ;
assert ( V_342 == V_345 ) ;
V_21 = F_92 ( V_27 ) ;
if ( V_21 >= V_342 )
return V_263 ;
V_49 = ( unsigned int ) F_14 ( struct V_311 ,
V_343 [ V_21 ] ) ;
assert ( V_49 % V_341 == 0 ) ;
F_95 ( V_39 ,
( unsigned int ) F_11 ( V_310 ) + V_49 ,
& V_344 , sizeof( V_344 ) ) ;
if ( V_337 )
* V_337 = V_344 . V_337 ;
if ( V_339 )
* V_339 = V_344 . V_339 ;
return V_173 ;
}
void
F_96 ( bool V_205 )
{
V_347 = V_205 ;
}
bool
F_97 ( void )
{
return V_347 ;
}
void
F_98 ( void )
{
const struct V_30 * V_31 ;
unsigned int V_348 ;
V_31 = & V_43 ;
V_348 = V_31 -> V_34 . V_35 . V_349 ;
if ( V_347 )
return;
( void ) V_348 ;
F_1 () ;
F_9 ( V_31 ) ;
F_99 ( V_39 ,
( unsigned int ) F_11 ( V_350 ) ,
( V_292 ) ( V_351 ) ) ;
V_347 = true ;
F_100 () ;
F_101 () ;
F_102 ( V_39 ) ;
}
bool
F_103 ( void )
{
const struct V_30 * V_31 = & V_43 ;
unsigned int V_352 = V_31 -> V_34 . V_35 . V_353 ;
( void ) V_352 ;
return ( bool ) F_104 ( V_354 ) ;
}
bool
F_105 ( int V_355 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_356 ; V_48 ++ ) {
F_106 ( V_355 ,
V_48 ,
0 ,
true ) ;
F_106 ( V_355 ,
V_48 ,
1 ,
true ) ;
}
return true ;
}
bool
F_106 ( int V_355 ,
int V_357 ,
int V_358 ,
bool V_14 )
{
V_292 V_359 ;
V_292 V_360 ;
V_292 V_361 ;
V_292 V_362 ;
( void ) V_355 ;
assert ( V_357 >= 0 && V_357 < V_356 ) ;
assert ( V_358 >= 0 ) ;
V_359 =
V_26 . V_51 . V_363 ;
V_361 = ( 8 * V_358 ) + V_357 ;
V_362 = ~ ( 1 << V_361 ) ;
V_359 &= V_362 ;
V_360 = V_14 ? 1 : 0 ;
V_360 <<= V_361 ;
V_359 |= V_360 ;
V_26 . V_51 . V_363 = V_359 ;
return true ;
}
void
F_107 ( void )
{
memset ( & V_26 , 0 , sizeof( struct V_26 ) ) ;
memset ( & V_3 , 0 , sizeof( struct V_3 ) ) ;
memset ( & V_6 , 0 , sizeof( struct V_6 ) ) ;
memset ( & V_50 , 0 , sizeof( struct V_50 ) ) ;
memset ( & V_1 , 0 , sizeof( struct V_364 ) ) ;
}
