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
static int F_23 ( struct V_13 * V_13 ,
struct V_49 * V_50 )
{
struct V_11 * V_12 = F_24 ( V_13 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
return F_25 ( V_13 , V_50 ,
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
F_32 ( V_55 , V_61 ,
L_4 ,
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
F_32 ( V_55 , V_61 ,
L_6 ,
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
V_92 = F_50 ( V_55 -> V_110 , 2 ) ;
V_93 = F_50 ( V_55 -> V_111 , 2 ) ;
F_32 ( V_55 , V_112 ,
L_8 ,
V_92 , V_93 ) ;
if ( V_92 != V_93 ) {
V_91 -> V_109 . V_113 |= V_114 ;
V_91 -> V_109 . V_113 |= ( ( V_92 - 1 ) <<
V_115 ) ;
}
for ( V_67 = 0 ; V_67 < V_93 ; V_67 ++ )
V_91 -> V_109 . V_116 [ V_67 ] = 0xff ;
V_91 -> V_109 . V_113 |= V_117 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = F_28 ( V_2 -> V_10 ) ;
int V_67 ;
for ( V_67 = 0 ; V_67 < F_52 ( V_2 -> V_118 ) ; V_67 ++ )
V_2 -> V_118 [ V_67 ] = - 1 ;
V_2 -> V_119 = F_53 ( V_2 -> V_10 ) ;
if ( V_2 -> V_119 == - 1 ) {
F_54 ( V_55 , L_9 ) ;
goto V_29;
}
V_2 -> V_120 = F_55 ( V_2 ) ;
if ( V_2 -> V_120 == - 1 ) {
F_54 ( V_55 , L_10 ) ;
goto V_29;
}
if ( ! F_56 ( V_2 , V_121 ) ) {
F_54 ( V_55 , L_11 ) ;
goto V_29;
}
if ( ! F_56 ( V_2 , V_122 ) ) {
F_54 ( V_55 , L_12 ) ;
goto V_29;
}
if ( ! F_56 ( V_2 , V_123 ) ) {
F_54 ( V_55 , L_13 ) ;
goto V_29;
}
if ( ! F_56 ( V_2 , V_124 ) ) {
F_54 ( V_55 , L_14 ) ;
goto V_29;
}
return 0 ;
V_29:
return - V_125 ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = F_28 ( V_2 -> V_10 ) ;
int V_67 = 0 ;
V_55 -> V_126 = V_127 ;
if ( V_2 -> V_10 -> V_128 & V_129 )
V_55 -> V_130 |= V_131 ;
for ( V_67 = 0 ; V_67 < V_55 -> V_126 ; V_67 ++ )
F_58 ( V_55 , ( T_1 ) V_67 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
if ( V_2 -> V_10 -> V_100 . V_101 & V_132 ) {
V_2 -> V_133 [ V_134 ] . V_135 =
V_136 ;
V_2 -> V_133 [ V_134 ] . V_137 = V_134 ;
V_2 -> V_133 [ V_134 ] . V_138 =
F_52 ( V_136 ) ;
V_2 -> V_133 [ V_134 ] . V_139 = V_140 ;
V_2 -> V_133 [ V_134 ] . V_141 =
F_52 ( V_140 ) ;
}
if ( V_2 -> V_10 -> V_100 . V_101 & V_142 ) {
V_2 -> V_133 [ V_143 ] . V_135 = V_144 ;
V_2 -> V_133 [ V_143 ] . V_137 = V_143 ;
V_2 -> V_133 [ V_143 ] . V_138 =
F_52 ( V_144 ) ;
V_2 -> V_133 [ V_143 ] . V_139 =
V_140 + 4 ;
V_2 -> V_133 [ V_143 ] . V_141 =
F_52 ( V_140 ) - 4 ;
}
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = F_28 ( V_2 -> V_10 ) ;
V_55 -> V_110 = V_2 -> V_10 -> V_100 . V_110 ;
V_55 -> V_111 = V_2 -> V_10 -> V_100 . V_111 ;
memcpy ( V_55 -> V_145 , V_146 , V_147 ) ;
V_2 -> V_10 -> V_148 = V_149 ;
}
static void F_61 ( struct V_1 * V_2 )
{
int V_150 ;
switch ( V_2 -> V_10 -> V_151 . V_152 ) {
case V_153 :
break;
case V_154 :
V_2 -> V_10 -> V_151 . V_155 = 7 ;
V_2 -> V_10 -> V_151 . V_156 = 6 ;
V_2 -> V_10 -> V_151 . V_157 = 8 ;
V_2 -> V_158 . V_159 = V_160 ;
F_62 ( V_2 -> V_10 ) ;
F_63 ( V_2 ) ;
V_150 = V_2 -> V_118 [ V_121 ] ;
F_64 ( V_2 -> V_10 , V_150 ) ;
break;
default:
F_65 ( 1 ) ;
break;
}
}
static int F_66 ( struct V_1 * V_2 ,
T_1 V_24 , char * V_161 ,
T_2 V_25 )
{
struct V_53 * V_10 = NULL ;
struct V_54 * V_55 ;
int V_67 , V_26 = 0 , V_79 = 0 ;
V_2 -> V_162 |= V_163 ;
V_10 = F_67 ( sizeof( struct V_53 ) , V_164 ) ;
if ( ! V_10 )
return - V_165 ;
V_10 -> V_166 . V_24 = V_24 ;
V_10 -> V_166 . V_167 = 0 ;
V_10 -> V_166 . V_168 = V_25 ;
V_10 -> V_169 |= V_170 ;
V_10 -> V_171 . V_172 = F_27 ;
V_10 -> V_171 . V_173 = F_34 ;
V_10 -> V_171 . V_174 = F_39 ;
V_10 -> V_171 . V_175 = F_40 ;
V_10 -> V_171 . V_176 = F_42 ;
V_10 -> V_171 . V_177 = F_43 ;
V_2 -> V_10 = V_10 ;
V_55 = F_28 ( V_10 ) ;
V_55 -> V_178 = & V_10 -> V_171 ;
V_55 -> V_179 = & V_180 ;
V_55 -> V_10 = V_10 ;
V_55 -> V_12 = V_2 -> V_12 ;
V_55 -> V_2 = V_2 ;
V_55 -> V_181 = V_182 ;
F_68 ( & V_2 -> V_183 ) ;
F_68 ( & V_2 -> F_16 . V_184 ) ;
F_69 ( & V_2 -> V_185 ) ;
F_69 ( & V_2 -> V_186 ) ;
F_70 ( & V_2 -> V_187 , V_188 ,
( unsigned long ) V_2 ) ;
F_70 ( & V_2 -> V_189 , V_190 ,
( unsigned long ) V_2 ) ;
F_71 ( & V_2 -> V_191 , V_192 ) ;
F_72 ( & V_2 -> V_193 , V_194 ) ;
F_72 ( & V_2 -> V_195 , V_196 ) ;
F_73 ( & V_2 -> F_16 . V_197 , V_198 ,
( unsigned long ) V_2 ) ;
F_74 ( V_55 , & V_79 ) ;
V_55 -> V_199 = V_79 << 2 ;
V_26 = F_75 ( V_10 ) ;
if ( V_26 ) {
F_54 ( V_55 ,
L_15 ,
V_26 ) ;
goto V_200;
}
V_26 = F_51 ( V_2 ) ;
if ( V_26 )
goto V_201;
for ( V_67 = 0 ; V_67 < V_202 ; V_67 ++ )
V_2 -> V_203 . V_204 [ V_67 ] = NULL ;
F_57 ( V_2 ) ;
F_59 ( V_2 ) ;
F_60 ( V_2 ) ;
if ( V_161 && strncmp ( V_161 , V_205 , 5 ) == 0 ) {
V_10 -> V_151 . V_152 = V_154 ;
F_61 ( V_2 ) ;
}
return 0 ;
V_201:
F_7 ( V_10 ) ;
V_200:
F_8 ( V_10 ) ;
V_2 -> V_10 = NULL ;
return V_26 ;
}
static void F_76 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_54 * V_55 = F_28 ( V_2 -> V_10 ) ;
V_12 -> V_206 = V_207 |
V_208 |
V_209 |
V_210 |
V_211 |
V_212 |
V_213 |
V_214 |
V_215 ;
V_12 -> V_13 -> V_216 =
F_77 ( V_149 ) |
F_77 ( V_217 ) |
F_77 ( V_218 ) |
F_77 ( V_219 ) |
F_77 ( V_220 ) ;
V_12 -> V_13 -> V_206 &= ~ V_221 ;
V_12 -> V_222 = 4 ;
V_12 -> V_223 = 5000 ;
V_12 -> V_224 = 10 ;
V_12 -> V_225 = sizeof( struct V_226 ) ;
V_12 -> V_227 = sizeof( struct V_228 ) ;
V_12 -> V_229 = sizeof( struct V_230 ) +
sizeof( struct V_231 ) + 4 ;
if ( V_2 -> V_10 -> V_100 . V_101 & V_132 )
V_12 -> V_13 -> V_232 [ V_134 ] =
& V_2 -> V_133 [ V_134 ] ;
if ( V_2 -> V_10 -> V_100 . V_101 & V_142 )
V_12 -> V_13 -> V_232 [ V_143 ] =
& V_2 -> V_133 [ V_143 ] ;
if ( V_2 -> V_10 -> V_100 . V_101 & V_233 ) {
if ( V_2 -> V_10 -> V_100 . V_101 & V_132 )
F_49 ( V_2 ,
& V_2 -> V_133 [ V_134 ] . V_234 ) ;
if ( V_2 -> V_10 -> V_100 . V_101 & V_142 )
F_49 ( V_2 ,
& V_2 -> V_133 [ V_143 ] . V_234 ) ;
}
F_78 ( V_12 , V_55 -> V_235 ) ;
}
static int F_79 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_236 V_237 ;
int V_26 ;
memset ( & V_237 , 0 , sizeof( V_237 ) ) ;
F_80 ( V_238 ) ;
if ( V_26 )
return - V_125 ;
V_2 -> V_239 = F_81 ( V_237 . V_240 ) ;
V_2 -> V_241 = F_81 ( V_237 . V_242 ) ;
snprintf ( V_12 -> V_13 -> V_243 , V_244 , L_16 ,
V_2 -> V_239 ,
V_2 -> V_241 ) ;
F_22 ( V_2 -> V_8 , L_17 ,
V_2 -> V_239 ,
V_2 -> V_241 ) ;
if ( V_2 -> V_239 != V_245 ||
V_2 -> V_241 != V_246 ) {
F_5 ( V_2 -> V_8 , L_18 ,
V_245 , V_246 ) ;
return - V_125 ;
}
return 0 ;
}
static int F_82 ( struct V_1 * V_2 ,
T_1 V_24 , char * V_161 , T_2 V_25 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_54 * V_55 ;
struct V_53 * V_10 ;
int error = 0 ;
struct V_247 * V_57 ;
char V_248 [ 64 ] ;
error = F_66 ( V_2 , V_24 , V_161 , V_25 ) ;
if ( error != 0 )
goto V_249;
V_10 = V_2 -> V_10 ;
V_55 = F_28 ( V_10 ) ;
F_76 ( V_2 , V_12 ) ;
error = F_79 ( V_2 ) ;
if ( error != 0 )
goto V_250;
error = F_83 ( & V_55 -> V_251 , V_2 -> V_12 -> V_13 ,
F_23 ) ;
if ( error )
goto V_252;
V_57 = & V_55 -> V_251 ;
error = F_84 ( V_2 ) ;
if ( error != 0 )
goto V_253;
error = F_85 ( V_2 ) ;
if ( error != 0 )
goto V_254;
#ifdef F_86
V_2 -> V_255 . V_256 = F_87 ( V_2 -> V_12 ,
V_257 , V_258 ,
F_52 ( V_258 ) ) ;
#endif
error = F_88 ( V_12 ) ;
if ( error )
goto V_259;
if ( ! F_89 ( V_57 ) ) {
error = F_90 ( V_12 -> V_13 , V_57 -> V_260 ) ;
if ( error )
goto V_261;
}
error = F_91 ( V_2 -> V_10 ) ;
if ( error ) {
F_54 ( V_55 , L_19 ) ;
goto V_261;
}
F_32 ( V_55 , V_112 ,
L_20
L_21 ,
V_2 -> V_28 ,
V_2 -> V_32 ,
V_2 -> V_35 ,
V_2 -> V_37 ,
V_2 -> V_39 ,
V_2 -> V_41 ,
V_2 -> V_43 ,
V_2 -> V_45 ,
V_2 -> V_47 ) ;
F_92 ( V_2 -> V_10 , V_248 , sizeof( V_248 ) ) ;
F_93 ( V_12 -> V_13 , L_22 , V_248 ) ;
F_94 ( V_2 ) ;
F_95 ( V_2 ) ;
return 0 ;
V_261:
F_12 ( V_12 ) ;
V_259:
F_13 ( V_2 ) ;
V_254:
F_14 ( V_2 ) ;
V_253:
V_252:
V_250:
F_6 ( V_2 ) ;
V_249:
return error ;
}
int F_96 ( struct V_262 * V_263 , struct V_264 * V_8 ,
T_1 V_24 , char * V_161 , T_2 V_25 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 ;
int V_26 ;
V_12 = F_97 ( sizeof( struct V_1 ) , & V_265 ) ;
if ( ! V_12 )
return - V_165 ;
V_2 = V_12 -> V_2 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_4 = V_263 ;
V_2 -> V_8 = V_8 ;
V_263 -> V_266 = V_2 ;
F_98 ( V_12 , V_2 -> V_8 ) ;
V_26 = F_1 ( V_2 ) ;
if ( V_26 )
goto V_267;
V_2 -> V_27 = F_99 ( V_2 ) ;
if ( ! V_2 -> V_27 ) {
V_26 = - V_125 ;
goto V_267;
}
V_26 = F_18 ( V_2 , V_24 , V_25 ) ;
if ( V_26 )
goto V_249;
V_26 = F_82 ( V_2 , V_24 , V_161 , V_25 ) ;
if ( V_26 )
goto V_249;
return 0 ;
V_249:
F_100 ( V_2 ) ;
V_267:
F_101 ( V_12 ) ;
return V_26 ;
}
void F_102 ( struct V_262 * V_263 , bool V_268 )
{
if ( V_263 -> V_266 ) {
if ( V_268 )
V_263 -> V_266 -> V_10 -> V_169 |= V_269 ;
F_9 ( V_263 -> V_266 ) ;
F_100 ( V_263 -> V_266 ) ;
F_101 ( V_263 -> V_266 -> V_12 ) ;
}
}
void F_103 ( struct V_262 * V_263 )
{
F_104 ( V_263 -> V_266 , V_270 ) ;
}
int F_105 ( struct V_262 * V_263 )
{
struct V_1 * V_2 = V_263 -> V_266 ;
int V_26 ;
V_26 = F_1 ( V_2 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_18 ( V_2 , V_2 -> V_10 -> V_166 . V_24 ,
V_2 -> V_10 -> V_166 . V_168 ) ;
return V_26 ;
}
static int T_4 F_106 ( void )
{
if ( F_107 () < 0 ) {
F_108 ( V_271
L_23
L_24 ) ;
return - V_272 ;
}
return 0 ;
}
static void T_5 F_109 ( void )
{
F_110 () ;
F_108 ( V_273 L_25 ) ;
}
