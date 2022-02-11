static void F_1 ( struct V_1 * V_2 )
{
F_2 ( (struct V_3 * ) V_2 -> V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( (struct V_3 * ) V_2 -> V_4 ) ;
}
static int F_5 ( struct V_3 * V_4 )
{
int V_5 ;
if ( F_6 ( & V_4 -> V_6 -> V_7 ) > 0 ) {
F_7 ( & V_4 -> V_6 -> V_7 ) ;
return 0 ;
}
V_5 = F_8 ( & V_4 -> V_6 -> V_8 , V_9 ) ;
if ( ! V_5 ) {
F_9 ( V_4 -> V_10 , L_1 ) ;
return - V_11 ;
}
F_7 ( & V_4 -> V_6 -> V_7 ) ;
return 0 ;
}
static void F_10 ( struct V_3 * V_4 )
{
F_11 ( V_4 -> V_12 ) ;
F_12 ( V_4 -> V_12 ) ;
V_4 -> V_12 = NULL ;
}
static void F_13 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = V_4 -> V_14 ;
F_14 ( V_14 -> V_15 ) ;
F_15 ( V_4 ) ;
F_16 ( V_4 ) ;
F_17 ( V_14 ) ;
F_18 ( V_4 ) ;
F_19 ( V_4 ) ;
F_10 ( V_4 ) ;
}
static inline int F_20 ( struct V_3 * V_4 ,
T_1 V_16 ,
void (* F_21) ( void * ,
struct V_17 * ,
enum V_18 ,
bool V_19 ) ,
enum V_18 * V_20 )
{
struct V_21 V_22 ;
memset ( & V_22 , 0 , sizeof( struct V_21 ) ) ;
V_22 . V_16 = V_16 ;
V_22 . V_23 . V_4 = V_4 ;
V_22 . V_23 . V_24 = V_25 ;
V_22 . V_23 . F_21 = F_21 ;
return F_22 ( V_4 -> V_6 , & V_22 , V_20 ) ;
}
static int F_23 ( struct V_3 * V_4 , T_1 V_26 ,
T_2 V_27 )
{
int V_28 ;
V_28 = F_24 ( V_4 -> V_6 , V_4 -> V_29 , & V_4 -> V_30 ) ;
if ( V_28 )
goto V_31;
V_28 = F_20 ( V_4 , V_32 , V_33 ,
& V_4 -> V_34 ) ;
if ( V_28 )
goto V_31;
V_28 = F_20 ( V_4 , V_35 , V_36 ,
& V_4 -> V_37 ) ;
if ( V_28 )
goto V_31;
V_28 = F_20 ( V_4 , V_38 , V_36 ,
& V_4 -> V_39 ) ;
if ( V_28 )
goto V_31;
V_28 = F_20 ( V_4 , V_40 , V_36 ,
& V_4 -> V_41 ) ;
if ( V_28 )
goto V_31;
V_28 = F_20 ( V_4 , V_42 , V_36 ,
& V_4 -> V_43 ) ;
if ( V_28 )
goto V_31;
V_28 = F_20 ( V_4 , V_44 , V_36 ,
& V_4 -> V_45 ) ;
if ( V_28 )
goto V_31;
V_28 = F_20 ( V_4 , V_46 , V_36 ,
& V_4 -> V_47 ) ;
if ( V_28 )
goto V_31;
V_28 = F_20 ( V_4 , V_48 , V_36 ,
& V_4 -> V_49 ) ;
if ( V_28 )
goto V_31;
if ( F_25 ( V_27 ) )
V_4 -> V_6 -> V_50 = 45 ;
else
V_4 -> V_6 -> V_50 = 33 ;
V_28 = F_26 ( V_4 -> V_6 ) ;
if ( V_28 )
goto V_31;
F_27 ( V_4 -> V_10 , L_2 ,
V_4 -> V_6 -> V_50 ) ;
return 0 ;
V_31:
F_9 ( V_4 -> V_10 , L_3 ) ;
return V_28 ;
}
static void F_28 ( struct V_15 * V_15 ,
struct V_51 * V_52 )
{
struct V_13 * V_14 = F_29 ( V_15 ) ;
struct V_3 * V_4 = V_14 -> V_4 ;
F_30 ( V_15 , V_52 ,
F_31 ( V_4 -> V_12 ) ) ;
}
static unsigned int F_32 ( void * V_53 , T_2 V_54 )
{
struct V_55 * V_12 = (struct V_55 * ) V_53 ;
struct V_1 * V_2 = F_33 ( V_12 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
T_3 V_56 , V_57 = F_34 ( V_54 ) ;
int V_58 ;
V_58 = F_35 ( V_4 -> V_29 , V_59 ,
( V_60 * ) & V_57 , sizeof( V_57 ) ,
( V_60 * ) & V_56 , sizeof( V_56 ) ,
100 ) ;
if ( F_36 ( V_58 ) ) {
F_37 ( V_2 , V_61 , L_4 ,
V_54 , V_58 ) ;
return - V_62 ;
}
return F_38 ( V_56 ) ;
}
static void F_39 ( void * V_53 , T_2 * V_63 ,
T_2 * V_56 , T_1 V_64 )
{
struct V_55 * V_12 = (struct V_55 * ) V_53 ;
struct V_1 * V_2 = F_33 ( V_12 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
T_3 V_65 [ 8 ] ;
T_3 V_66 [ 8 ] ;
int V_67 , V_28 ;
for ( V_67 = 0 ; V_67 < V_64 ; V_67 ++ ) {
V_65 [ V_67 ] = F_34 ( V_63 [ V_67 ] ) ;
}
V_28 = F_35 ( V_4 -> V_29 , V_59 ,
( V_60 * ) V_65 , sizeof( T_2 ) * V_64 ,
( V_60 * ) V_66 , sizeof( T_2 ) * V_64 ,
100 ) ;
if ( F_36 ( V_28 ) ) {
F_37 ( V_2 , V_61 ,
L_5 , V_64 ) ;
}
for ( V_67 = 0 ; V_67 < V_64 ; V_67 ++ ) {
V_56 [ V_67 ] = F_38 ( V_66 [ V_67 ] ) ;
}
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
T_2 V_68 ;
int V_58 ;
V_58 = F_35 ( V_4 -> V_29 , V_69 ,
( V_60 * ) & V_4 -> V_29 -> V_70 ,
sizeof( struct V_71 ) * V_4 -> V_29 -> V_72 ,
( V_60 * ) & V_68 , sizeof( V_68 ) ,
100 ) ;
if ( F_36 ( V_58 ) ) {
F_37 ( V_2 , V_61 ,
L_6 ,
V_4 -> V_29 -> V_72 ) ;
}
V_4 -> V_29 -> V_72 = 0 ;
}
static void F_41 ( void * V_53 , T_2 V_56 , T_2 V_54 )
{
struct V_55 * V_12 = (struct V_55 * ) V_53 ;
struct V_1 * V_2 = F_33 ( V_12 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
const T_3 V_73 [ 2 ] = {
F_34 ( V_54 ) ,
F_34 ( V_56 ) ,
} ;
int V_58 ;
V_58 = F_35 ( V_4 -> V_29 , V_69 ,
( V_60 * ) & V_73 , sizeof( V_73 ) ,
( V_60 * ) & V_56 , sizeof( V_56 ) ,
100 ) ;
if ( F_36 ( V_58 ) ) {
F_37 ( V_2 , V_61 , L_7 ,
V_54 , V_58 ) ;
}
}
static void F_42 ( void * V_53 , T_2 V_56 , T_2 V_54 )
{
struct V_55 * V_12 = (struct V_55 * ) V_53 ;
struct V_1 * V_2 = F_33 ( V_12 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
F_43 ( & V_4 -> V_29 -> V_74 ) ;
V_4 -> V_29 -> V_70 [ V_4 -> V_29 -> V_72 ] . V_57 =
F_34 ( V_54 ) ;
V_4 -> V_29 -> V_70 [ V_4 -> V_29 -> V_72 ] . V_56 =
F_34 ( V_56 ) ;
V_4 -> V_29 -> V_72 ++ ;
if ( V_4 -> V_29 -> V_72 == V_75 )
F_40 ( V_2 ) ;
F_44 ( & V_4 -> V_29 -> V_74 ) ;
}
static void F_45 ( void * V_53 , T_2 V_56 , T_2 V_54 )
{
struct V_55 * V_12 = (struct V_55 * ) V_53 ;
struct V_1 * V_2 = F_33 ( V_12 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
if ( F_6 ( & V_4 -> V_29 -> V_76 ) )
F_42 ( V_53 , V_56 , V_54 ) ;
else
F_41 ( V_53 , V_56 , V_54 ) ;
}
static void F_46 ( void * V_53 )
{
struct V_55 * V_12 = (struct V_55 * ) V_53 ;
struct V_1 * V_2 = F_33 ( V_12 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
F_47 ( & V_4 -> V_29 -> V_76 ) ;
}
static void F_48 ( void * V_53 )
{
struct V_55 * V_12 = (struct V_55 * ) V_53 ;
struct V_1 * V_2 = F_33 ( V_12 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
F_7 ( & V_4 -> V_29 -> V_76 ) ;
F_43 ( & V_4 -> V_29 -> V_74 ) ;
if ( V_4 -> V_29 -> V_72 )
F_40 ( V_2 ) ;
F_44 ( & V_4 -> V_29 -> V_74 ) ;
}
static T_2 F_49 ( void * V_53 , T_2 V_54 , T_2 V_77 , T_2 V_78 )
{
T_2 V_56 ;
V_56 = F_32 ( V_53 , V_54 ) ;
V_56 &= ~ V_78 ;
V_56 |= V_77 ;
F_45 ( V_53 , V_56 , V_54 ) ;
return V_56 ;
}
static void F_50 ( struct V_1 * V_2 , int * V_79 )
{
* V_79 = V_80 >> 2 ;
}
static bool F_51 ( struct V_1 * V_2 , T_2 V_81 , T_1 * V_82 )
{
struct V_55 * V_12 = (struct V_55 * ) V_2 -> V_12 ;
( void ) F_52 ( V_12 , V_83 + ( V_81 << V_84 ) ) ;
if ( ! F_53 ( V_12 ,
V_85 ,
V_86 |
V_87 , 0 ,
V_88 ) )
return false ;
* V_82 = F_54 ( F_52 ( V_12 , V_85 ) ,
V_89 ) ;
return true ;
}
static int F_55 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_33 ( V_4 -> V_12 ) ;
int V_67 ;
for ( V_67 = 0 ; V_67 < F_56 ( V_4 -> V_90 ) ; V_67 ++ )
V_4 -> V_90 [ V_67 ] = - 1 ;
V_4 -> V_91 . V_92 = F_57 ( V_4 -> V_12 ) ;
if ( V_4 -> V_91 . V_92 == - 1 ) {
F_58 ( V_2 , L_8 ) ;
goto V_31;
}
V_4 -> V_93 = F_59 ( V_4 ) ;
if ( V_4 -> V_93 == - 1 ) {
F_58 ( V_2 , L_9 ) ;
goto V_31;
}
if ( ! F_60 ( V_4 , V_94 ) ) {
F_58 ( V_2 , L_10 ) ;
goto V_31;
}
if ( ! F_60 ( V_4 , V_95 ) ) {
F_58 ( V_2 , L_11 ) ;
goto V_31;
}
if ( ! F_60 ( V_4 , V_96 ) ) {
F_58 ( V_2 , L_12 ) ;
goto V_31;
}
if ( ! F_60 ( V_4 , V_97 ) ) {
F_58 ( V_2 , L_13 ) ;
goto V_31;
}
return 0 ;
V_31:
return - V_98 ;
}
static void F_61 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_33 ( V_4 -> V_12 ) ;
memcpy ( V_2 -> V_99 , V_100 , V_101 ) ;
V_2 -> V_102 = V_103 ;
V_4 -> V_12 -> V_104 = V_105 ;
V_4 -> V_106 . V_12 = V_4 -> V_12 ;
V_4 -> V_106 . V_107 . V_108 = 0 ;
V_4 -> V_106 . V_107 . V_109 = false ;
V_4 -> V_106 . V_107 . V_64 = 8 ;
V_4 -> V_106 . V_107 . V_110 = false ;
V_4 -> V_106 . V_107 . V_111 = 0x12 ;
V_4 -> V_106 . V_107 . V_112 = 0x02 ;
}
static int F_62 ( struct V_3 * V_4 ,
T_1 V_26 , char * V_113 ,
T_2 V_27 )
{
struct V_55 * V_12 = NULL ;
struct V_1 * V_2 ;
int V_67 , V_28 = 0 , V_79 = 0 ;
V_12 = F_63 ( sizeof( struct V_55 ) , V_114 ) ;
if ( ! V_12 )
return - V_115 ;
V_12 -> V_10 = V_4 -> V_10 ;
V_12 -> V_14 = V_4 -> V_14 ;
V_12 -> V_116 . V_26 = V_26 ;
V_12 -> V_116 . V_117 = V_27 ;
V_12 -> V_118 |= V_119 ;
V_12 -> V_120 . V_121 = F_32 ;
V_12 -> V_120 . V_122 = F_39 ;
V_12 -> V_120 . V_123 = F_45 ;
V_12 -> V_120 . V_124 = F_46 ;
V_12 -> V_120 . V_125 = F_48 ;
V_12 -> V_120 . V_126 = F_49 ;
V_4 -> V_12 = V_12 ;
V_2 = F_33 ( V_12 ) ;
V_2 -> V_127 = & V_12 -> V_120 ;
V_2 -> V_128 = & V_129 ;
V_2 -> V_130 = & V_131 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_14 = V_4 -> V_14 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_132 = V_133 ;
V_2 -> V_134 = V_135 == 1 ;
F_64 ( V_136 , & V_2 -> V_137 ) ;
F_65 ( & V_4 -> V_138 ) ;
F_65 ( & V_4 -> F_21 . V_139 ) ;
F_66 ( & V_4 -> V_140 ) ;
F_66 ( & V_4 -> V_141 ) ;
F_67 ( & V_4 -> V_142 , V_143 ,
( unsigned long ) V_4 ) ;
F_67 ( & V_4 -> V_144 , V_145 ,
( unsigned long ) V_4 ) ;
F_68 ( & V_4 -> V_146 , V_147 ) ;
F_69 ( & V_4 -> V_148 , V_149 ) ;
F_69 ( & V_4 -> V_150 , V_151 ) ;
F_70 ( & V_4 -> F_21 . V_152 , V_153 ,
( unsigned long ) V_4 ) ;
F_71 ( V_2 , & V_79 ) ;
V_2 -> V_154 = V_79 << 2 ;
V_28 = F_72 ( V_12 ) ;
if ( V_28 ) {
F_58 ( V_2 ,
L_14 ,
V_28 ) ;
goto V_155;
}
V_28 = F_55 ( V_4 ) ;
if ( V_28 )
goto V_156;
for ( V_67 = 0 ; V_67 < V_157 ; V_67 ++ )
V_4 -> V_91 . V_158 [ V_67 ] = NULL ;
V_4 -> V_91 . V_159 = V_160 ;
F_73 ( V_2 ) ;
F_74 ( V_12 ) ;
F_61 ( V_4 ) ;
F_75 ( V_4 , V_113 ) ;
return 0 ;
V_156:
F_11 ( V_12 ) ;
V_155:
F_12 ( V_12 ) ;
V_4 -> V_12 = NULL ;
return V_28 ;
}
static void F_76 ( struct V_3 * V_4 ,
struct V_13 * V_14 )
{
struct V_55 * V_12 = V_4 -> V_12 ;
struct V_1 * V_2 = F_33 ( V_4 -> V_12 ) ;
struct V_161 * V_162 ;
V_14 -> V_163 = V_164 |
V_165 |
V_166 |
V_167 |
V_168 |
V_169 |
V_170 |
V_171 |
V_172 ;
if ( V_173 )
V_14 -> V_163 |= V_174 ;
V_14 -> V_15 -> V_175 =
F_77 ( V_105 ) |
F_77 ( V_176 ) |
F_77 ( V_177 ) |
F_77 ( V_178 ) |
F_77 ( V_179 ) |
F_77 ( V_180 ) ;
V_14 -> V_15 -> V_181 = & V_182 ;
V_14 -> V_15 -> V_183 = 1 ;
V_14 -> V_15 -> V_163 &= ~ V_184 ;
V_14 -> V_15 -> V_163 |= V_185 |
V_186 ;
V_14 -> V_15 -> V_163 |= V_187 ;
V_14 -> V_188 = 4 ;
V_14 -> V_189 = 1 ;
V_14 -> V_190 = sizeof( struct V_191 ) ;
V_14 -> V_192 = sizeof( struct V_193 ) ;
V_14 -> V_194 = sizeof( struct V_195 ) +
sizeof( struct V_196 ) + 4 ;
if ( V_4 -> V_12 -> V_197 . V_198 & V_199 )
V_14 -> V_15 -> V_200 [ V_201 ] =
& V_2 -> V_202 [ V_201 ] ;
if ( V_4 -> V_12 -> V_197 . V_198 & V_203 )
V_14 -> V_15 -> V_200 [ V_204 ] =
& V_2 -> V_202 [ V_204 ] ;
F_78 ( V_12 ) ;
V_162 = F_79 ( V_4 ) ;
if ( V_162 ) {
V_14 -> V_15 -> V_205 = V_162 -> V_206 ;
V_14 -> V_15 -> V_207 = V_162 -> V_208 ;
}
F_80 ( V_14 , V_2 -> V_209 ) ;
}
static int F_81 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = V_4 -> V_14 ;
struct V_210 V_211 ;
int V_28 ;
memset ( & V_211 , 0 , sizeof( V_211 ) ) ;
F_82 ( V_212 ) ;
if ( V_28 )
return - V_98 ;
V_4 -> V_213 = F_83 ( V_211 . V_214 ) ;
V_4 -> V_215 = F_83 ( V_211 . V_216 ) ;
snprintf ( V_14 -> V_15 -> V_217 , sizeof( V_14 -> V_15 -> V_217 ) , L_15 ,
V_4 -> V_213 ,
V_4 -> V_215 ) ;
F_27 ( V_4 -> V_10 , L_16 ,
V_4 -> V_213 ,
V_4 -> V_215 ) ;
if ( V_4 -> V_213 != V_218 ||
V_4 -> V_215 < V_219 ) {
F_9 ( V_4 -> V_10 , L_17 ,
V_218 , V_219 ) ;
return - V_98 ;
}
return 0 ;
}
static int F_84 ( struct V_3 * V_4 ,
T_1 V_26 , char * V_113 , T_2 V_27 )
{
struct V_13 * V_14 = V_4 -> V_14 ;
struct V_1 * V_2 ;
struct V_55 * V_12 ;
int error = 0 ;
struct V_220 * V_57 ;
char V_221 [ 64 ] ;
error = F_62 ( V_4 , V_26 , V_113 , V_27 ) ;
if ( error != 0 )
goto V_222;
V_12 = V_4 -> V_12 ;
V_2 = F_33 ( V_12 ) ;
F_76 ( V_4 , V_14 ) ;
error = F_81 ( V_4 ) ;
if ( error != 0 )
goto V_223;
error = F_85 ( & V_2 -> V_224 , V_4 -> V_14 -> V_15 ,
F_28 ) ;
if ( error )
goto V_225;
V_57 = & V_2 -> V_224 ;
error = F_86 ( V_4 ) ;
if ( error != 0 )
goto V_226;
error = F_87 ( V_4 ) ;
if ( error != 0 )
goto V_227;
F_88 ( V_4 -> V_12 ) ;
#ifdef F_89
V_4 -> V_228 . V_229 = F_90 ( V_4 -> V_14 ,
V_230 , V_231 ,
F_56 ( V_231 ) ) ;
#endif
error = F_91 ( V_14 ) ;
if ( error )
goto V_232;
if ( ! F_92 ( V_57 ) ) {
error = F_93 ( V_14 -> V_15 , V_57 -> V_233 ) ;
if ( error )
goto V_234;
}
error = F_94 ( V_4 -> V_12 ) ;
if ( error ) {
F_58 ( V_2 , L_18 ) ;
goto V_234;
}
F_37 ( V_2 , V_235 ,
L_19 ,
V_4 -> V_30 ,
V_4 -> V_34 ,
V_4 -> V_37 ,
V_4 -> V_39 ,
V_4 -> V_41 ,
V_4 -> V_43 ,
V_4 -> V_45 ,
V_4 -> V_47 ,
V_4 -> V_49 ) ;
F_95 ( V_4 -> V_12 , V_221 , sizeof( V_221 ) ) ;
F_96 ( V_14 -> V_15 , L_20 , V_221 ) ;
F_97 ( V_4 ) ;
F_98 ( V_4 ) ;
return 0 ;
V_234:
F_17 ( V_14 ) ;
V_232:
F_18 ( V_4 ) ;
V_227:
F_19 ( V_4 ) ;
V_226:
V_225:
V_223:
F_10 ( V_4 ) ;
V_222:
return error ;
}
int F_99 ( struct V_236 * V_237 , struct V_238 * V_10 ,
T_1 V_26 , char * V_113 , T_2 V_27 )
{
struct V_13 * V_14 ;
struct V_3 * V_4 ;
int V_28 ;
V_14 = F_100 ( sizeof( struct V_3 ) , & V_239 ) ;
if ( ! V_14 )
return - V_115 ;
V_4 = V_14 -> V_4 ;
V_4 -> V_14 = V_14 ;
V_4 -> V_6 = V_237 ;
V_4 -> V_10 = V_10 ;
V_237 -> V_240 = V_4 ;
F_101 ( V_14 , V_4 -> V_10 ) ;
V_28 = F_5 ( V_4 ) ;
if ( V_28 )
goto V_241;
V_4 -> V_29 = F_102 ( V_4 ) ;
if ( ! V_4 -> V_29 ) {
V_28 = - V_98 ;
goto V_241;
}
V_28 = F_23 ( V_4 , V_26 , V_27 ) ;
if ( V_28 )
goto V_222;
V_28 = F_84 ( V_4 , V_26 , V_113 , V_27 ) ;
if ( V_28 )
goto V_222;
return 0 ;
V_222:
F_103 ( V_4 ) ;
V_241:
F_104 ( V_14 ) ;
return V_28 ;
}
void F_105 ( struct V_236 * V_237 , bool V_242 )
{
if ( V_237 -> V_240 ) {
if ( V_242 )
V_237 -> V_240 -> V_12 -> V_118 |= V_243 ;
F_13 ( V_237 -> V_240 ) ;
F_103 ( V_237 -> V_240 ) ;
F_104 ( V_237 -> V_240 -> V_14 ) ;
}
}
void F_106 ( struct V_236 * V_237 )
{
F_107 ( V_237 -> V_240 , V_244 ) ;
}
int F_108 ( struct V_236 * V_237 )
{
struct V_3 * V_4 = V_237 -> V_240 ;
int V_28 ;
V_28 = F_5 ( V_4 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_23 ( V_4 , V_4 -> V_12 -> V_116 . V_26 ,
V_4 -> V_12 -> V_116 . V_117 ) ;
F_109 ( V_4 ) ;
return V_28 ;
}
static int T_4 F_110 ( void )
{
if ( F_111 () < 0 ) {
F_112 ( L_21 ) ;
return - V_245 ;
}
return 0 ;
}
static void T_5 F_113 ( void )
{
F_114 () ;
F_115 ( L_22 ) ;
}
