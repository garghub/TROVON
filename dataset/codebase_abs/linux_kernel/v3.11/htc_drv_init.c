static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( F_2 ( & V_2 -> V_4 -> V_5 ) > 0 ) {
F_3 ( & V_2 -> V_4 -> V_5 ) ;
return 0 ;
}
V_3 = F_4 ( & V_2 -> V_4 -> V_6 , V_7 ) ;
if ( ! V_3 ) {
F_5 ( V_2 -> V_8 , L_1 ) ;
return - V_9 ;
}
F_3 ( & V_2 -> V_4 -> V_5 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_10 ) ;
F_8 ( V_2 -> V_10 ) ;
V_2 -> V_10 = NULL ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
F_10 ( V_12 -> V_13 ) ;
F_11 ( V_2 ) ;
F_12 ( V_12 ) ;
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
F_6 ( V_2 ) ;
}
static inline int F_15 ( struct V_1 * V_2 ,
T_1 V_14 ,
void (* F_16) ( void * ,
struct V_15 * ,
enum V_16 ,
bool V_17 ) ,
enum V_16 * V_18 )
{
struct V_19 V_20 ;
memset ( & V_20 , 0 , sizeof( struct V_19 ) ) ;
V_20 . V_14 = V_14 ;
V_20 . V_21 . V_2 = V_2 ;
V_20 . V_21 . V_22 = V_23 ;
V_20 . V_21 . F_16 = F_16 ;
return F_17 ( V_2 -> V_4 , & V_20 , V_18 ) ;
}
static int F_18 ( struct V_1 * V_2 , T_1 V_24 ,
T_2 V_25 )
{
int V_26 ;
V_26 = F_19 ( V_2 -> V_4 , V_2 -> V_27 , & V_2 -> V_28 ) ;
if ( V_26 )
goto V_29;
V_26 = F_15 ( V_2 , V_30 , V_31 ,
& V_2 -> V_32 ) ;
if ( V_26 )
goto V_29;
V_26 = F_15 ( V_2 , V_33 , V_34 ,
& V_2 -> V_35 ) ;
if ( V_26 )
goto V_29;
V_26 = F_15 ( V_2 , V_36 , V_34 ,
& V_2 -> V_37 ) ;
if ( V_26 )
goto V_29;
V_26 = F_15 ( V_2 , V_38 , V_34 ,
& V_2 -> V_39 ) ;
if ( V_26 )
goto V_29;
V_26 = F_15 ( V_2 , V_40 , V_34 ,
& V_2 -> V_41 ) ;
if ( V_26 )
goto V_29;
V_26 = F_15 ( V_2 , V_42 , V_34 ,
& V_2 -> V_43 ) ;
if ( V_26 )
goto V_29;
V_26 = F_15 ( V_2 , V_44 , V_34 ,
& V_2 -> V_45 ) ;
if ( V_26 )
goto V_29;
V_26 = F_15 ( V_2 , V_46 , V_34 ,
& V_2 -> V_47 ) ;
if ( V_26 )
goto V_29;
if ( F_20 ( V_25 ) )
V_2 -> V_4 -> V_48 = 45 ;
else
V_2 -> V_4 -> V_48 = 33 ;
V_26 = F_21 ( V_2 -> V_4 ) ;
if ( V_26 )
goto V_29;
F_22 ( V_2 -> V_8 , L_2 ,
V_2 -> V_4 -> V_48 ) ;
return 0 ;
V_29:
F_5 ( V_2 -> V_8 , L_3 ) ;
return V_26 ;
}
static void F_23 ( struct V_13 * V_13 ,
struct V_49 * V_50 )
{
struct V_11 * V_12 = F_24 ( V_13 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
F_25 ( V_13 , V_50 ,
F_26 ( V_2 -> V_10 ) ) ;
}
static unsigned int F_27 ( void * V_51 , T_2 V_52 )
{
struct V_53 * V_10 = (struct V_53 * ) V_51 ;
struct V_54 * V_55 = F_28 ( V_10 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_55 -> V_2 ;
T_3 V_56 , V_57 = F_29 ( V_52 ) ;
int V_58 ;
V_58 = F_30 ( V_2 -> V_27 , V_59 ,
( V_60 * ) & V_57 , sizeof( V_57 ) ,
( V_60 * ) & V_56 , sizeof( V_56 ) ,
100 ) ;
if ( F_31 ( V_58 ) ) {
F_32 ( V_55 , V_61 , L_4 ,
V_52 , V_58 ) ;
return - V_62 ;
}
return F_33 ( V_56 ) ;
}
static void F_34 ( void * V_51 , T_2 * V_63 ,
T_2 * V_56 , T_1 V_64 )
{
struct V_53 * V_10 = (struct V_53 * ) V_51 ;
struct V_54 * V_55 = F_28 ( V_10 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_55 -> V_2 ;
T_3 V_65 [ 8 ] ;
T_3 V_66 [ 8 ] ;
int V_67 , V_26 ;
for ( V_67 = 0 ; V_67 < V_64 ; V_67 ++ ) {
V_65 [ V_67 ] = F_29 ( V_63 [ V_67 ] ) ;
}
V_26 = F_30 ( V_2 -> V_27 , V_59 ,
( V_60 * ) V_65 , sizeof( T_2 ) * V_64 ,
( V_60 * ) V_66 , sizeof( T_2 ) * V_64 ,
100 ) ;
if ( F_31 ( V_26 ) ) {
F_32 ( V_55 , V_61 ,
L_5 , V_64 ) ;
}
for ( V_67 = 0 ; V_67 < V_64 ; V_67 ++ ) {
V_56 [ V_67 ] = F_33 ( V_66 [ V_67 ] ) ;
}
}
static void F_35 ( void * V_51 , T_2 V_56 , T_2 V_52 )
{
struct V_53 * V_10 = (struct V_53 * ) V_51 ;
struct V_54 * V_55 = F_28 ( V_10 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_55 -> V_2 ;
const T_3 V_68 [ 2 ] = {
F_29 ( V_52 ) ,
F_29 ( V_56 ) ,
} ;
int V_58 ;
V_58 = F_30 ( V_2 -> V_27 , V_69 ,
( V_60 * ) & V_68 , sizeof( V_68 ) ,
( V_60 * ) & V_56 , sizeof( V_56 ) ,
100 ) ;
if ( F_31 ( V_58 ) ) {
F_32 ( V_55 , V_61 , L_6 ,
V_52 , V_58 ) ;
}
}
static void F_36 ( void * V_51 , T_2 V_56 , T_2 V_52 )
{
struct V_53 * V_10 = (struct V_53 * ) V_51 ;
struct V_54 * V_55 = F_28 ( V_10 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_55 -> V_2 ;
T_2 V_70 ;
int V_58 ;
F_37 ( & V_2 -> V_27 -> V_71 ) ;
V_2 -> V_27 -> V_72 [ V_2 -> V_27 -> V_73 ] . V_57 =
F_29 ( V_52 ) ;
V_2 -> V_27 -> V_72 [ V_2 -> V_27 -> V_73 ] . V_56 =
F_29 ( V_56 ) ;
V_2 -> V_27 -> V_73 ++ ;
if ( V_2 -> V_27 -> V_73 == V_74 ) {
V_58 = F_30 ( V_2 -> V_27 , V_69 ,
( V_60 * ) & V_2 -> V_27 -> V_72 ,
sizeof( struct V_75 ) * V_2 -> V_27 -> V_73 ,
( V_60 * ) & V_70 , sizeof( V_70 ) ,
100 ) ;
if ( F_31 ( V_58 ) ) {
F_32 ( V_55 , V_61 ,
L_7 ,
V_2 -> V_27 -> V_73 ) ;
}
V_2 -> V_27 -> V_73 = 0 ;
}
F_38 ( & V_2 -> V_27 -> V_71 ) ;
}
static void F_39 ( void * V_51 , T_2 V_56 , T_2 V_52 )
{
struct V_53 * V_10 = (struct V_53 * ) V_51 ;
struct V_54 * V_55 = F_28 ( V_10 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_55 -> V_2 ;
if ( F_2 ( & V_2 -> V_27 -> V_76 ) )
F_36 ( V_51 , V_56 , V_52 ) ;
else
F_35 ( V_51 , V_56 , V_52 ) ;
}
static void F_40 ( void * V_51 )
{
struct V_53 * V_10 = (struct V_53 * ) V_51 ;
struct V_54 * V_55 = F_28 ( V_10 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_55 -> V_2 ;
F_41 ( & V_2 -> V_27 -> V_76 ) ;
}
static void F_42 ( void * V_51 )
{
struct V_53 * V_10 = (struct V_53 * ) V_51 ;
struct V_54 * V_55 = F_28 ( V_10 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_55 -> V_2 ;
T_2 V_70 ;
int V_58 ;
F_3 ( & V_2 -> V_27 -> V_76 ) ;
F_37 ( & V_2 -> V_27 -> V_71 ) ;
if ( V_2 -> V_27 -> V_73 ) {
V_58 = F_30 ( V_2 -> V_27 , V_69 ,
( V_60 * ) & V_2 -> V_27 -> V_72 ,
sizeof( struct V_75 ) * V_2 -> V_27 -> V_73 ,
( V_60 * ) & V_70 , sizeof( V_70 ) ,
100 ) ;
if ( F_31 ( V_58 ) ) {
F_32 ( V_55 , V_61 ,
L_7 ,
V_2 -> V_27 -> V_73 ) ;
}
V_2 -> V_27 -> V_73 = 0 ;
}
F_38 ( & V_2 -> V_27 -> V_71 ) ;
}
static T_2 F_43 ( void * V_51 , T_2 V_52 , T_2 V_77 , T_2 V_78 )
{
T_2 V_56 ;
V_56 = F_27 ( V_51 , V_52 ) ;
V_56 &= ~ V_78 ;
V_56 |= V_77 ;
F_39 ( V_51 , V_56 , V_52 ) ;
return V_56 ;
}
static void F_44 ( struct V_54 * V_55 , int * V_79 )
{
* V_79 = V_80 >> 2 ;
}
static bool F_45 ( struct V_54 * V_55 , T_2 V_81 , T_1 * V_82 )
{
struct V_53 * V_10 = (struct V_53 * ) V_55 -> V_10 ;
( void ) F_46 ( V_10 , V_83 + ( V_81 << V_84 ) ) ;
if ( ! F_47 ( V_10 ,
V_85 ,
V_86 |
V_87 , 0 ,
V_88 ) )
return false ;
* V_82 = F_48 ( F_46 ( V_10 , V_85 ) ,
V_89 ) ;
return true ;
}
static void F_49 ( struct V_1 * V_2 ,
struct V_90 * V_91 )
{
struct V_54 * V_55 = F_28 ( V_2 -> V_10 ) ;
V_60 V_92 , V_93 ;
int V_67 ;
V_91 -> V_94 = true ;
V_91 -> V_95 = V_96 |
V_97 |
V_98 |
V_99 ;
if ( V_2 -> V_10 -> V_100 . V_101 & V_102 )
V_91 -> V_95 |= V_103 ;
V_91 -> V_95 |= ( 1 << V_104 ) ;
V_91 -> V_105 = V_106 ;
V_91 -> V_107 = V_108 ;
memset ( & V_91 -> V_109 , 0 , sizeof( V_91 -> V_109 ) ) ;
V_92 = F_50 ( V_2 -> V_10 -> V_110 , 2 ) ;
V_93 = F_50 ( V_2 -> V_10 -> V_111 , 2 ) ;
F_32 ( V_55 , V_112 , L_8 ,
V_92 , V_93 ) ;
if ( V_92 >= 2 )
V_91 -> V_95 |= V_113 ;
if ( V_92 != V_93 ) {
V_91 -> V_109 . V_114 |= V_115 ;
V_91 -> V_109 . V_114 |= ( ( V_92 - 1 ) <<
V_116 ) ;
}
for ( V_67 = 0 ; V_67 < V_93 ; V_67 ++ )
V_91 -> V_109 . V_117 [ V_67 ] = 0xff ;
V_91 -> V_109 . V_114 |= V_118 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = F_28 ( V_2 -> V_10 ) ;
int V_67 ;
for ( V_67 = 0 ; V_67 < F_52 ( V_2 -> V_119 ) ; V_67 ++ )
V_2 -> V_119 [ V_67 ] = - 1 ;
V_2 -> V_120 = F_53 ( V_2 -> V_10 ) ;
if ( V_2 -> V_120 == - 1 ) {
F_54 ( V_55 , L_9 ) ;
goto V_29;
}
V_2 -> V_121 = F_55 ( V_2 ) ;
if ( V_2 -> V_121 == - 1 ) {
F_54 ( V_55 , L_10 ) ;
goto V_29;
}
if ( ! F_56 ( V_2 , V_122 ) ) {
F_54 ( V_55 , L_11 ) ;
goto V_29;
}
if ( ! F_56 ( V_2 , V_123 ) ) {
F_54 ( V_55 , L_12 ) ;
goto V_29;
}
if ( ! F_56 ( V_2 , V_124 ) ) {
F_54 ( V_55 , L_13 ) ;
goto V_29;
}
if ( ! F_56 ( V_2 , V_125 ) ) {
F_54 ( V_55 , L_14 ) ;
goto V_29;
}
return 0 ;
V_29:
return - V_126 ;
}
static void F_57 ( struct V_1 * V_2 )
{
if ( V_2 -> V_10 -> V_100 . V_101 & V_127 ) {
V_2 -> V_128 [ V_129 ] . V_130 =
V_131 ;
V_2 -> V_128 [ V_129 ] . V_132 = V_129 ;
V_2 -> V_128 [ V_129 ] . V_133 =
F_52 ( V_131 ) ;
V_2 -> V_128 [ V_129 ] . V_134 = V_135 ;
V_2 -> V_128 [ V_129 ] . V_136 =
F_52 ( V_135 ) ;
}
if ( V_2 -> V_10 -> V_100 . V_101 & V_137 ) {
V_2 -> V_128 [ V_138 ] . V_130 = V_139 ;
V_2 -> V_128 [ V_138 ] . V_132 = V_138 ;
V_2 -> V_128 [ V_138 ] . V_133 =
F_52 ( V_139 ) ;
V_2 -> V_128 [ V_138 ] . V_134 =
V_135 + 4 ;
V_2 -> V_128 [ V_138 ] . V_136 =
F_52 ( V_135 ) - 4 ;
}
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = F_28 ( V_2 -> V_10 ) ;
memcpy ( V_55 -> V_140 , V_141 , V_142 ) ;
V_2 -> V_10 -> V_143 = V_144 ;
}
static int F_59 ( struct V_1 * V_2 ,
T_1 V_24 , char * V_145 ,
T_2 V_25 )
{
struct V_53 * V_10 = NULL ;
struct V_54 * V_55 ;
int V_67 , V_26 = 0 , V_79 = 0 ;
F_60 ( V_146 , & V_2 -> V_147 ) ;
V_10 = F_61 ( sizeof( struct V_53 ) , V_148 ) ;
if ( ! V_10 )
return - V_149 ;
V_10 -> V_150 . V_24 = V_24 ;
V_10 -> V_150 . V_151 = V_25 ;
V_10 -> V_152 |= V_153 ;
V_10 -> V_154 . V_155 = F_27 ;
V_10 -> V_154 . V_156 = F_34 ;
V_10 -> V_154 . V_157 = F_39 ;
V_10 -> V_154 . V_158 = F_40 ;
V_10 -> V_154 . V_159 = F_42 ;
V_10 -> V_154 . V_160 = F_43 ;
V_2 -> V_10 = V_10 ;
V_55 = F_28 ( V_10 ) ;
V_55 -> V_161 = & V_10 -> V_154 ;
V_55 -> V_162 = & V_163 ;
V_55 -> V_10 = V_10 ;
V_55 -> V_12 = V_2 -> V_12 ;
V_55 -> V_2 = V_2 ;
V_55 -> V_164 = V_165 ;
V_55 -> V_166 = V_167 == 1 ;
F_62 ( & V_2 -> V_168 ) ;
F_62 ( & V_2 -> F_16 . V_169 ) ;
F_63 ( & V_2 -> V_170 ) ;
F_63 ( & V_2 -> V_171 ) ;
F_64 ( & V_2 -> V_172 , V_173 ,
( unsigned long ) V_2 ) ;
F_64 ( & V_2 -> V_174 , V_175 ,
( unsigned long ) V_2 ) ;
F_65 ( & V_2 -> V_176 , V_177 ) ;
F_66 ( & V_2 -> V_178 , V_179 ) ;
F_66 ( & V_2 -> V_180 , V_181 ) ;
F_67 ( & V_2 -> F_16 . V_182 , V_183 ,
( unsigned long ) V_2 ) ;
F_68 ( V_55 , & V_79 ) ;
V_55 -> V_184 = V_79 << 2 ;
V_26 = F_69 ( V_10 ) ;
if ( V_26 ) {
F_54 ( V_55 ,
L_15 ,
V_26 ) ;
goto V_185;
}
V_26 = F_51 ( V_2 ) ;
if ( V_26 )
goto V_186;
for ( V_67 = 0 ; V_67 < V_187 ; V_67 ++ )
V_2 -> V_188 . V_189 [ V_67 ] = NULL ;
F_70 ( V_10 ) ;
F_57 ( V_2 ) ;
F_58 ( V_2 ) ;
F_71 ( V_2 , V_145 ) ;
return 0 ;
V_186:
F_7 ( V_10 ) ;
V_185:
F_8 ( V_10 ) ;
V_2 -> V_10 = NULL ;
return V_26 ;
}
static void F_72 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_54 * V_55 = F_28 ( V_2 -> V_10 ) ;
struct V_190 * V_191 ;
V_12 -> V_192 = V_193 |
V_194 |
V_195 |
V_196 |
V_197 |
V_198 |
V_199 |
V_200 |
V_201 |
V_202 ;
V_12 -> V_13 -> V_203 =
F_73 ( V_144 ) |
F_73 ( V_204 ) |
F_73 ( V_205 ) |
F_73 ( V_206 ) |
F_73 ( V_207 ) |
F_73 ( V_208 ) ;
V_12 -> V_13 -> V_209 = & V_210 ;
V_12 -> V_13 -> V_211 = 1 ;
V_12 -> V_13 -> V_192 &= ~ V_212 ;
V_12 -> V_13 -> V_192 |= V_213 |
V_214 ;
V_12 -> V_215 = 4 ;
V_12 -> V_216 = 5000 ;
V_12 -> V_217 = 1 ;
V_12 -> V_218 = sizeof( struct V_219 ) ;
V_12 -> V_220 = sizeof( struct V_221 ) ;
V_12 -> V_222 = sizeof( struct V_223 ) +
sizeof( struct V_224 ) + 4 ;
if ( V_2 -> V_10 -> V_100 . V_101 & V_127 )
V_12 -> V_13 -> V_225 [ V_129 ] =
& V_2 -> V_128 [ V_129 ] ;
if ( V_2 -> V_10 -> V_100 . V_101 & V_137 )
V_12 -> V_13 -> V_225 [ V_138 ] =
& V_2 -> V_128 [ V_138 ] ;
if ( V_2 -> V_10 -> V_100 . V_101 & V_226 ) {
if ( V_2 -> V_10 -> V_100 . V_101 & V_127 )
F_49 ( V_2 ,
& V_2 -> V_128 [ V_129 ] . V_227 ) ;
if ( V_2 -> V_10 -> V_100 . V_101 & V_137 )
F_49 ( V_2 ,
& V_2 -> V_128 [ V_138 ] . V_227 ) ;
}
V_191 = F_74 ( V_2 ) ;
if ( V_191 ) {
V_12 -> V_13 -> V_228 = V_191 -> V_229 ;
V_12 -> V_13 -> V_230 = V_191 -> V_231 ;
}
F_75 ( V_12 , V_55 -> V_232 ) ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_233 V_234 ;
int V_26 ;
memset ( & V_234 , 0 , sizeof( V_234 ) ) ;
F_77 ( V_235 ) ;
if ( V_26 )
return - V_126 ;
V_2 -> V_236 = F_78 ( V_234 . V_237 ) ;
V_2 -> V_238 = F_78 ( V_234 . V_239 ) ;
snprintf ( V_12 -> V_13 -> V_240 , sizeof( V_12 -> V_13 -> V_240 ) , L_16 ,
V_2 -> V_236 ,
V_2 -> V_238 ) ;
F_22 ( V_2 -> V_8 , L_17 ,
V_2 -> V_236 ,
V_2 -> V_238 ) ;
if ( V_2 -> V_236 != V_241 ||
V_2 -> V_238 < V_242 ) {
F_5 ( V_2 -> V_8 , L_18 ,
V_241 , V_242 ) ;
return - V_126 ;
}
return 0 ;
}
static int F_79 ( struct V_1 * V_2 ,
T_1 V_24 , char * V_145 , T_2 V_25 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_54 * V_55 ;
struct V_53 * V_10 ;
int error = 0 ;
struct V_243 * V_57 ;
char V_244 [ 64 ] ;
error = F_59 ( V_2 , V_24 , V_145 , V_25 ) ;
if ( error != 0 )
goto V_245;
V_10 = V_2 -> V_10 ;
V_55 = F_28 ( V_10 ) ;
F_72 ( V_2 , V_12 ) ;
error = F_76 ( V_2 ) ;
if ( error != 0 )
goto V_246;
error = F_80 ( & V_55 -> V_247 , V_2 -> V_12 -> V_13 ,
F_23 ) ;
if ( error )
goto V_248;
V_57 = & V_55 -> V_247 ;
error = F_81 ( V_2 ) ;
if ( error != 0 )
goto V_249;
error = F_82 ( V_2 ) ;
if ( error != 0 )
goto V_250;
F_83 ( V_2 -> V_10 ) ;
#ifdef F_84
V_2 -> V_251 . V_252 = F_85 ( V_2 -> V_12 ,
V_253 , V_254 ,
F_52 ( V_254 ) ) ;
#endif
error = F_86 ( V_12 ) ;
if ( error )
goto V_255;
if ( ! F_87 ( V_57 ) ) {
error = F_88 ( V_12 -> V_13 , V_57 -> V_256 ) ;
if ( error )
goto V_257;
}
error = F_89 ( V_2 -> V_10 ) ;
if ( error ) {
F_54 ( V_55 , L_19 ) ;
goto V_257;
}
F_32 ( V_55 , V_112 ,
L_20 ,
V_2 -> V_28 ,
V_2 -> V_32 ,
V_2 -> V_35 ,
V_2 -> V_37 ,
V_2 -> V_39 ,
V_2 -> V_41 ,
V_2 -> V_43 ,
V_2 -> V_45 ,
V_2 -> V_47 ) ;
F_90 ( V_2 -> V_10 , V_244 , sizeof( V_244 ) ) ;
F_91 ( V_12 -> V_13 , L_21 , V_244 ) ;
F_92 ( V_2 ) ;
F_93 ( V_2 ) ;
return 0 ;
V_257:
F_12 ( V_12 ) ;
V_255:
F_13 ( V_2 ) ;
V_250:
F_14 ( V_2 ) ;
V_249:
V_248:
V_246:
F_6 ( V_2 ) ;
V_245:
return error ;
}
int F_94 ( struct V_258 * V_259 , struct V_260 * V_8 ,
T_1 V_24 , char * V_145 , T_2 V_25 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 ;
int V_26 ;
V_12 = F_95 ( sizeof( struct V_1 ) , & V_261 ) ;
if ( ! V_12 )
return - V_149 ;
V_2 = V_12 -> V_2 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_4 = V_259 ;
V_2 -> V_8 = V_8 ;
V_259 -> V_262 = V_2 ;
F_96 ( V_12 , V_2 -> V_8 ) ;
V_26 = F_1 ( V_2 ) ;
if ( V_26 )
goto V_263;
V_2 -> V_27 = F_97 ( V_2 ) ;
if ( ! V_2 -> V_27 ) {
V_26 = - V_126 ;
goto V_263;
}
V_26 = F_18 ( V_2 , V_24 , V_25 ) ;
if ( V_26 )
goto V_245;
V_26 = F_79 ( V_2 , V_24 , V_145 , V_25 ) ;
if ( V_26 )
goto V_245;
return 0 ;
V_245:
F_98 ( V_2 ) ;
V_263:
F_99 ( V_12 ) ;
return V_26 ;
}
void F_100 ( struct V_258 * V_259 , bool V_264 )
{
if ( V_259 -> V_262 ) {
if ( V_264 )
V_259 -> V_262 -> V_10 -> V_152 |= V_265 ;
F_9 ( V_259 -> V_262 ) ;
F_98 ( V_259 -> V_262 ) ;
F_99 ( V_259 -> V_262 -> V_12 ) ;
}
}
void F_101 ( struct V_258 * V_259 )
{
F_102 ( V_259 -> V_262 , V_266 ) ;
}
int F_103 ( struct V_258 * V_259 )
{
struct V_1 * V_2 = V_259 -> V_262 ;
int V_26 ;
V_26 = F_1 ( V_2 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_18 ( V_2 , V_2 -> V_10 -> V_150 . V_24 ,
V_2 -> V_10 -> V_150 . V_151 ) ;
return V_26 ;
}
static int T_4 F_104 ( void )
{
if ( F_105 () < 0 ) {
F_106 ( L_22 ) ;
return - V_267 ;
}
return 0 ;
}
static void T_5 F_107 ( void )
{
F_108 () ;
F_109 ( L_23 ) ;
}
