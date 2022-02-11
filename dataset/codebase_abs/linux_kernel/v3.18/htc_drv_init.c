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
static void F_35 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = (struct V_1 * ) V_55 -> V_2 ;
T_2 V_68 ;
int V_58 ;
V_58 = F_30 ( V_2 -> V_27 , V_69 ,
( V_60 * ) & V_2 -> V_27 -> V_70 ,
sizeof( struct V_71 ) * V_2 -> V_27 -> V_72 ,
( V_60 * ) & V_68 , sizeof( V_68 ) ,
100 ) ;
if ( F_31 ( V_58 ) ) {
F_32 ( V_55 , V_61 ,
L_6 ,
V_2 -> V_27 -> V_72 ) ;
}
V_2 -> V_27 -> V_72 = 0 ;
}
static void F_36 ( void * V_51 , T_2 V_56 , T_2 V_52 )
{
struct V_53 * V_10 = (struct V_53 * ) V_51 ;
struct V_54 * V_55 = F_28 ( V_10 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_55 -> V_2 ;
const T_3 V_73 [ 2 ] = {
F_29 ( V_52 ) ,
F_29 ( V_56 ) ,
} ;
int V_58 ;
V_58 = F_30 ( V_2 -> V_27 , V_69 ,
( V_60 * ) & V_73 , sizeof( V_73 ) ,
( V_60 * ) & V_56 , sizeof( V_56 ) ,
100 ) ;
if ( F_31 ( V_58 ) ) {
F_32 ( V_55 , V_61 , L_7 ,
V_52 , V_58 ) ;
}
}
static void F_37 ( void * V_51 , T_2 V_56 , T_2 V_52 )
{
struct V_53 * V_10 = (struct V_53 * ) V_51 ;
struct V_54 * V_55 = F_28 ( V_10 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_55 -> V_2 ;
F_38 ( & V_2 -> V_27 -> V_74 ) ;
V_2 -> V_27 -> V_70 [ V_2 -> V_27 -> V_72 ] . V_57 =
F_29 ( V_52 ) ;
V_2 -> V_27 -> V_70 [ V_2 -> V_27 -> V_72 ] . V_56 =
F_29 ( V_56 ) ;
V_2 -> V_27 -> V_72 ++ ;
if ( V_2 -> V_27 -> V_72 == V_75 )
F_35 ( V_55 ) ;
F_39 ( & V_2 -> V_27 -> V_74 ) ;
}
static void F_40 ( void * V_51 , T_2 V_56 , T_2 V_52 )
{
struct V_53 * V_10 = (struct V_53 * ) V_51 ;
struct V_54 * V_55 = F_28 ( V_10 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_55 -> V_2 ;
if ( F_2 ( & V_2 -> V_27 -> V_76 ) )
F_37 ( V_51 , V_56 , V_52 ) ;
else
F_36 ( V_51 , V_56 , V_52 ) ;
}
static void F_41 ( void * V_51 )
{
struct V_53 * V_10 = (struct V_53 * ) V_51 ;
struct V_54 * V_55 = F_28 ( V_10 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_55 -> V_2 ;
F_42 ( & V_2 -> V_27 -> V_76 ) ;
}
static void F_43 ( void * V_51 )
{
struct V_53 * V_10 = (struct V_53 * ) V_51 ;
struct V_54 * V_55 = F_28 ( V_10 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_55 -> V_2 ;
F_3 ( & V_2 -> V_27 -> V_76 ) ;
F_38 ( & V_2 -> V_27 -> V_74 ) ;
if ( V_2 -> V_27 -> V_72 )
F_35 ( V_55 ) ;
F_39 ( & V_2 -> V_27 -> V_74 ) ;
}
static T_2 F_44 ( void * V_51 , T_2 V_52 , T_2 V_77 , T_2 V_78 )
{
T_2 V_56 ;
V_56 = F_27 ( V_51 , V_52 ) ;
V_56 &= ~ V_78 ;
V_56 |= V_77 ;
F_40 ( V_51 , V_56 , V_52 ) ;
return V_56 ;
}
static void F_45 ( struct V_54 * V_55 , int * V_79 )
{
* V_79 = V_80 >> 2 ;
}
static bool F_46 ( struct V_54 * V_55 , T_2 V_81 , T_1 * V_82 )
{
struct V_53 * V_10 = (struct V_53 * ) V_55 -> V_10 ;
( void ) F_47 ( V_10 , V_83 + ( V_81 << V_84 ) ) ;
if ( ! F_48 ( V_10 ,
V_85 ,
V_86 |
V_87 , 0 ,
V_88 ) )
return false ;
* V_82 = F_49 ( F_47 ( V_10 , V_85 ) ,
V_89 ) ;
return true ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = F_28 ( V_2 -> V_10 ) ;
int V_67 ;
for ( V_67 = 0 ; V_67 < F_51 ( V_2 -> V_90 ) ; V_67 ++ )
V_2 -> V_90 [ V_67 ] = - 1 ;
V_2 -> V_91 . V_92 = F_52 ( V_2 -> V_10 ) ;
if ( V_2 -> V_91 . V_92 == - 1 ) {
F_53 ( V_55 , L_8 ) ;
goto V_29;
}
V_2 -> V_93 = F_54 ( V_2 ) ;
if ( V_2 -> V_93 == - 1 ) {
F_53 ( V_55 , L_9 ) ;
goto V_29;
}
if ( ! F_55 ( V_2 , V_94 ) ) {
F_53 ( V_55 , L_10 ) ;
goto V_29;
}
if ( ! F_55 ( V_2 , V_95 ) ) {
F_53 ( V_55 , L_11 ) ;
goto V_29;
}
if ( ! F_55 ( V_2 , V_96 ) ) {
F_53 ( V_55 , L_12 ) ;
goto V_29;
}
if ( ! F_55 ( V_2 , V_97 ) ) {
F_53 ( V_55 , L_13 ) ;
goto V_29;
}
return 0 ;
V_29:
return - V_98 ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = F_28 ( V_2 -> V_10 ) ;
memcpy ( V_55 -> V_99 , V_100 , V_101 ) ;
V_55 -> V_102 = V_103 ;
V_2 -> V_10 -> V_104 = V_105 ;
}
static int F_57 ( struct V_1 * V_2 ,
T_1 V_24 , char * V_106 ,
T_2 V_25 )
{
struct V_53 * V_10 = NULL ;
struct V_54 * V_55 ;
int V_67 , V_26 = 0 , V_79 = 0 ;
V_10 = F_58 ( sizeof( struct V_53 ) , V_107 ) ;
if ( ! V_10 )
return - V_108 ;
V_10 -> V_8 = V_2 -> V_8 ;
V_10 -> V_12 = V_2 -> V_12 ;
V_10 -> V_109 . V_24 = V_24 ;
V_10 -> V_109 . V_110 = V_25 ;
V_10 -> V_111 |= V_112 ;
V_10 -> V_113 . V_114 = F_27 ;
V_10 -> V_113 . V_115 = F_34 ;
V_10 -> V_113 . V_116 = F_40 ;
V_10 -> V_113 . V_117 = F_41 ;
V_10 -> V_113 . V_118 = F_43 ;
V_10 -> V_113 . V_119 = F_44 ;
V_2 -> V_10 = V_10 ;
V_55 = F_28 ( V_10 ) ;
V_55 -> V_120 = & V_10 -> V_113 ;
V_55 -> V_121 = & V_122 ;
V_55 -> V_10 = V_10 ;
V_55 -> V_12 = V_2 -> V_12 ;
V_55 -> V_2 = V_2 ;
V_55 -> V_123 = V_124 ;
V_55 -> V_125 = V_126 == 1 ;
F_59 ( V_127 , & V_55 -> V_128 ) ;
F_60 ( & V_2 -> V_129 ) ;
F_60 ( & V_2 -> F_16 . V_130 ) ;
F_61 ( & V_2 -> V_131 ) ;
F_61 ( & V_2 -> V_132 ) ;
F_62 ( & V_2 -> V_133 , V_134 ,
( unsigned long ) V_2 ) ;
F_62 ( & V_2 -> V_135 , V_136 ,
( unsigned long ) V_2 ) ;
F_63 ( & V_2 -> V_137 , V_138 ) ;
F_64 ( & V_2 -> V_139 , V_140 ) ;
F_64 ( & V_2 -> V_141 , V_142 ) ;
F_65 ( & V_2 -> F_16 . V_143 , V_144 ,
( unsigned long ) V_2 ) ;
F_66 ( V_55 , & V_79 ) ;
V_55 -> V_145 = V_79 << 2 ;
V_26 = F_67 ( V_10 ) ;
if ( V_26 ) {
F_53 ( V_55 ,
L_14 ,
V_26 ) ;
goto V_146;
}
V_26 = F_50 ( V_2 ) ;
if ( V_26 )
goto V_147;
for ( V_67 = 0 ; V_67 < V_148 ; V_67 ++ )
V_2 -> V_91 . V_149 [ V_67 ] = NULL ;
V_2 -> V_91 . V_150 = V_151 ;
F_68 ( V_55 ) ;
F_69 ( V_10 ) ;
F_56 ( V_2 ) ;
F_70 ( V_2 , V_106 ) ;
return 0 ;
V_147:
F_7 ( V_10 ) ;
V_146:
F_8 ( V_10 ) ;
V_2 -> V_10 = NULL ;
return V_26 ;
}
static void F_71 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_53 * V_10 = V_2 -> V_10 ;
struct V_54 * V_55 = F_28 ( V_2 -> V_10 ) ;
struct V_152 * V_153 ;
V_12 -> V_154 = V_155 |
V_156 |
V_157 |
V_158 |
V_159 |
V_160 |
V_161 |
V_162 |
V_163 ;
if ( V_164 )
V_12 -> V_154 |= V_165 ;
V_12 -> V_13 -> V_166 =
F_72 ( V_105 ) |
F_72 ( V_167 ) |
F_72 ( V_168 ) |
F_72 ( V_169 ) |
F_72 ( V_170 ) |
F_72 ( V_171 ) ;
V_12 -> V_13 -> V_172 = & V_173 ;
V_12 -> V_13 -> V_174 = 1 ;
V_12 -> V_13 -> V_154 &= ~ V_175 ;
V_12 -> V_13 -> V_154 |= V_176 |
V_177 ;
V_12 -> V_13 -> V_154 |= V_178 ;
V_12 -> V_179 = 4 ;
V_12 -> V_180 = 1 ;
V_12 -> V_181 = sizeof( struct V_182 ) ;
V_12 -> V_183 = sizeof( struct V_184 ) ;
V_12 -> V_185 = sizeof( struct V_186 ) +
sizeof( struct V_187 ) + 4 ;
if ( V_2 -> V_10 -> V_188 . V_189 & V_190 )
V_12 -> V_13 -> V_191 [ V_192 ] =
& V_55 -> V_193 [ V_192 ] ;
if ( V_2 -> V_10 -> V_188 . V_189 & V_194 )
V_12 -> V_13 -> V_191 [ V_195 ] =
& V_55 -> V_193 [ V_195 ] ;
F_73 ( V_10 ) ;
V_153 = F_74 ( V_2 ) ;
if ( V_153 ) {
V_12 -> V_13 -> V_196 = V_153 -> V_197 ;
V_12 -> V_13 -> V_198 = V_153 -> V_199 ;
}
F_75 ( V_12 , V_55 -> V_200 ) ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_201 V_202 ;
int V_26 ;
memset ( & V_202 , 0 , sizeof( V_202 ) ) ;
F_77 ( V_203 ) ;
if ( V_26 )
return - V_98 ;
V_2 -> V_204 = F_78 ( V_202 . V_205 ) ;
V_2 -> V_206 = F_78 ( V_202 . V_207 ) ;
snprintf ( V_12 -> V_13 -> V_208 , sizeof( V_12 -> V_13 -> V_208 ) , L_15 ,
V_2 -> V_204 ,
V_2 -> V_206 ) ;
F_22 ( V_2 -> V_8 , L_16 ,
V_2 -> V_204 ,
V_2 -> V_206 ) ;
if ( V_2 -> V_204 != V_209 ||
V_2 -> V_206 < V_210 ) {
F_5 ( V_2 -> V_8 , L_17 ,
V_209 , V_210 ) ;
return - V_98 ;
}
return 0 ;
}
static int F_79 ( struct V_1 * V_2 ,
T_1 V_24 , char * V_106 , T_2 V_25 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_54 * V_55 ;
struct V_53 * V_10 ;
int error = 0 ;
struct V_211 * V_57 ;
char V_212 [ 64 ] ;
error = F_57 ( V_2 , V_24 , V_106 , V_25 ) ;
if ( error != 0 )
goto V_213;
V_10 = V_2 -> V_10 ;
V_55 = F_28 ( V_10 ) ;
F_71 ( V_2 , V_12 ) ;
error = F_76 ( V_2 ) ;
if ( error != 0 )
goto V_214;
error = F_80 ( & V_55 -> V_215 , V_2 -> V_12 -> V_13 ,
F_23 ) ;
if ( error )
goto V_216;
V_57 = & V_55 -> V_215 ;
error = F_81 ( V_2 ) ;
if ( error != 0 )
goto V_217;
error = F_82 ( V_2 ) ;
if ( error != 0 )
goto V_218;
F_83 ( V_2 -> V_10 ) ;
#ifdef F_84
V_2 -> V_219 . V_220 = F_85 ( V_2 -> V_12 ,
V_221 , V_222 ,
F_51 ( V_222 ) ) ;
#endif
error = F_86 ( V_12 ) ;
if ( error )
goto V_223;
if ( ! F_87 ( V_57 ) ) {
error = F_88 ( V_12 -> V_13 , V_57 -> V_224 ) ;
if ( error )
goto V_225;
}
error = F_89 ( V_2 -> V_10 ) ;
if ( error ) {
F_53 ( V_55 , L_18 ) ;
goto V_225;
}
F_32 ( V_55 , V_226 ,
L_19 ,
V_2 -> V_28 ,
V_2 -> V_32 ,
V_2 -> V_35 ,
V_2 -> V_37 ,
V_2 -> V_39 ,
V_2 -> V_41 ,
V_2 -> V_43 ,
V_2 -> V_45 ,
V_2 -> V_47 ) ;
F_90 ( V_2 -> V_10 , V_212 , sizeof( V_212 ) ) ;
F_91 ( V_12 -> V_13 , L_20 , V_212 ) ;
F_92 ( V_2 ) ;
F_93 ( V_2 ) ;
return 0 ;
V_225:
F_12 ( V_12 ) ;
V_223:
F_13 ( V_2 ) ;
V_218:
F_14 ( V_2 ) ;
V_217:
V_216:
V_214:
F_6 ( V_2 ) ;
V_213:
return error ;
}
int F_94 ( struct V_227 * V_228 , struct V_229 * V_8 ,
T_1 V_24 , char * V_106 , T_2 V_25 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 ;
int V_26 ;
V_12 = F_95 ( sizeof( struct V_1 ) , & V_230 ) ;
if ( ! V_12 )
return - V_108 ;
V_2 = V_12 -> V_2 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_4 = V_228 ;
V_2 -> V_8 = V_8 ;
V_228 -> V_231 = V_2 ;
F_96 ( V_12 , V_2 -> V_8 ) ;
V_26 = F_1 ( V_2 ) ;
if ( V_26 )
goto V_232;
V_2 -> V_27 = F_97 ( V_2 ) ;
if ( ! V_2 -> V_27 ) {
V_26 = - V_98 ;
goto V_232;
}
V_26 = F_18 ( V_2 , V_24 , V_25 ) ;
if ( V_26 )
goto V_213;
V_26 = F_79 ( V_2 , V_24 , V_106 , V_25 ) ;
if ( V_26 )
goto V_213;
return 0 ;
V_213:
F_98 ( V_2 ) ;
V_232:
F_99 ( V_12 ) ;
return V_26 ;
}
void F_100 ( struct V_227 * V_228 , bool V_233 )
{
if ( V_228 -> V_231 ) {
if ( V_233 )
V_228 -> V_231 -> V_10 -> V_111 |= V_234 ;
F_9 ( V_228 -> V_231 ) ;
F_98 ( V_228 -> V_231 ) ;
F_99 ( V_228 -> V_231 -> V_12 ) ;
}
}
void F_101 ( struct V_227 * V_228 )
{
F_102 ( V_228 -> V_231 , V_235 ) ;
}
int F_103 ( struct V_227 * V_228 )
{
struct V_1 * V_2 = V_228 -> V_231 ;
int V_26 ;
V_26 = F_1 ( V_2 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_18 ( V_2 , V_2 -> V_10 -> V_109 . V_24 ,
V_2 -> V_10 -> V_109 . V_110 ) ;
F_104 ( V_2 ) ;
return V_26 ;
}
static int T_4 F_105 ( void )
{
if ( F_106 () < 0 ) {
F_107 ( L_21 ) ;
return - V_236 ;
}
return 0 ;
}
static void T_5 F_108 ( void )
{
F_109 () ;
F_110 ( L_22 ) ;
}
