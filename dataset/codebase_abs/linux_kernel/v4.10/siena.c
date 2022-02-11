static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_5 ;
if ( V_2 -> V_6 ) {
unsigned int V_7 ;
V_7 = F_2 ( V_4 , V_2 -> V_6 ) ;
F_3 ( V_5 ,
V_8 ,
V_9 ,
V_10 ,
V_7 - 1 ) ;
} else {
F_3 ( V_5 ,
V_8 ,
V_11 ,
V_10 , 0 ) ;
}
F_4 ( V_2 -> V_4 , & V_5 , V_12 ,
V_2 -> V_2 ) ;
}
void F_5 ( struct V_3 * V_4 )
{
if ( V_4 -> V_13 ++ == 0 )
F_6 ( V_4 ) ;
}
void F_7 ( struct V_3 * V_4 )
{
if ( -- V_4 -> V_13 == 0 )
F_6 ( V_4 ) ;
}
static int F_8 ( struct V_3 * V_4 , struct V_14 * V_15 )
{
enum V_16 V_17 = V_18 ;
int V_19 , V_20 ;
F_9 ( V_4 , V_17 ) ;
V_19 = F_10 ( V_4 , V_17 ) ;
if ( V_19 )
goto V_21;
V_15 -> V_22 =
F_11 ( V_4 , V_23 ,
F_12 ( V_23 ) )
? - 1 : 1 ;
V_19 = F_10 ( V_4 , V_17 ) ;
V_21:
V_20 = F_13 ( V_4 , V_17 , V_19 == 0 ) ;
return V_19 ? V_19 : V_20 ;
}
static void F_14 ( struct V_3 * V_4 , T_2 V_24 )
{
F_15 ( V_4 , F_16 ( V_24 ) ,
V_25 + V_26 ) ;
}
static int F_17 ( struct V_3 * V_4 ,
struct V_27 * V_28 )
{
int V_19 ;
switch ( V_28 -> V_29 ) {
case V_30 :
return F_18 ( V_4 ,
V_28 -> V_31 != V_32 ,
F_19 ( V_4 ) ) ;
case V_33 :
case V_34 :
case V_35 :
V_28 -> V_29 = V_33 ;
return F_18 ( V_4 , true , V_36 ) ;
case V_37 :
case V_38 :
case V_39 :
V_28 -> V_29 = V_37 ;
V_19 = F_18 ( V_4 , true ,
V_40 ) ;
if ( V_19 != 0 )
V_19 = F_18 ( V_4 , true , V_41 ) ;
return V_19 ;
default:
return - V_42 ;
}
}
static int F_20 ( T_2 * V_43 )
{
enum {
V_44 = ( V_45 | V_46 |
V_47 | V_48 |
V_49 ) ,
V_50 = ( V_44 |
V_51 << V_52 ) ,
};
if ( ( * V_43 & V_50 ) == V_50 ) {
* V_43 &= ~ V_50 ;
return V_53 ;
}
if ( ( * V_43 & V_44 ) == V_44 ) {
* V_43 &= ~ V_44 ;
return V_18 ;
}
return - V_54 ;
}
static void F_21 ( struct V_3 * V_4 )
{
struct V_55 * V_56 = F_22 ( V_4 -> V_57 ) ;
F_23 ( V_56 ) ;
}
static int F_24 ( struct V_3 * V_4 )
{
T_2 V_58 = 0 ;
int V_19 ;
V_19 = F_25 ( V_4 , V_4 -> V_59 -> V_60 , NULL , & V_58 ) ;
V_4 -> V_61 =
( V_58 & ( 1 << V_62 ) ) ?
3072 : 6144 ;
V_4 -> V_63 = V_4 -> type -> V_64 *
V_4 -> V_61 ;
return V_19 ;
}
static int F_26 ( struct V_3 * V_4 )
{
F_27 ( V_4 , V_65 / 2 ) ;
return 0 ;
}
static unsigned int F_28 ( struct V_3 * V_4 )
{
return V_25 +
V_66 * V_67 ;
}
static int F_29 ( struct V_3 * V_4 )
{
struct V_68 * V_69 ;
T_3 V_70 ;
int V_19 ;
V_69 = F_30 ( sizeof( struct V_68 ) , V_71 ) ;
if ( ! V_69 )
return - V_72 ;
V_69 -> V_4 = V_4 ;
V_4 -> V_69 = V_69 ;
if ( F_31 ( V_4 ) != 0 ) {
F_32 ( V_4 , V_73 , V_4 -> V_59 ,
L_1 ) ;
V_19 = - V_74 ;
goto V_75;
}
V_4 -> V_76 = V_77 ;
V_4 -> V_78 = V_77 ;
F_33 ( V_4 , & V_70 , V_79 ) ;
V_4 -> V_80 = F_34 ( V_70 , V_81 ) - 1 ;
V_19 = F_35 ( V_4 ) ;
if ( V_19 )
goto V_75;
V_19 = F_10 ( V_4 , V_18 ) ;
if ( V_19 ) {
F_32 ( V_4 , V_73 , V_4 -> V_59 , L_2 ) ;
goto V_82;
}
F_36 ( V_4 ) ;
V_19 = F_37 ( V_4 , & V_4 -> V_83 , sizeof( T_3 ) ,
V_71 ) ;
if ( V_19 )
goto V_84;
F_38 ( V_4 -> V_83 . V_85 & 0x0f ) ;
F_39 ( V_4 , V_73 , V_4 -> V_59 ,
L_3 ,
( unsigned long long ) V_4 -> V_83 . V_85 ,
V_4 -> V_83 . V_86 ,
( unsigned long long ) F_40 ( V_4 -> V_83 . V_86 ) ) ;
V_19 = F_24 ( V_4 ) ;
if ( V_19 == - V_54 ) {
F_32 ( V_4 , V_73 , V_4 -> V_59 ,
L_4 ) ;
V_4 -> V_87 = V_88 ;
V_4 -> V_89 . V_90 = V_91 ;
} else if ( V_19 ) {
goto V_92;
}
V_19 = F_41 ( V_4 ) ;
if ( V_19 )
goto V_92;
#ifdef F_42
F_43 ( V_4 ) ;
#endif
F_44 ( V_4 ) ;
return 0 ;
V_92:
F_45 ( V_4 , & V_4 -> V_83 ) ;
V_84:
V_82:
F_46 ( V_4 ) ;
V_75:
F_47 ( V_4 -> V_69 ) ;
return V_19 ;
}
static int F_48 ( struct V_3 * V_4 , bool V_93 ,
const T_2 * V_94 )
{
T_3 V_95 ;
memcpy ( & V_95 , V_4 -> V_96 , sizeof( V_95 ) ) ;
F_49 ( V_4 , & V_95 , V_97 ) ;
F_50 ( sizeof( V_4 -> V_96 ) <
2 * sizeof( V_95 ) + V_98 / 8 ||
V_99 != 0 ) ;
memcpy ( & V_95 , V_4 -> V_96 , sizeof( V_95 ) ) ;
F_49 ( V_4 , & V_95 , V_100 ) ;
memcpy ( & V_95 , V_4 -> V_96 + sizeof( V_95 ) , sizeof( V_95 ) ) ;
F_49 ( V_4 , & V_95 , V_101 ) ;
F_51 ( V_95 , V_102 , 1 ,
V_103 , 1 ) ;
memcpy ( & V_95 , V_4 -> V_96 + 2 * sizeof( V_95 ) ,
V_98 / 8 ) ;
F_49 ( V_4 , & V_95 , V_104 ) ;
memcpy ( V_4 -> V_94 , V_94 ,
sizeof( V_4 -> V_94 ) ) ;
F_52 ( V_4 ) ;
return 0 ;
}
static int F_53 ( struct V_3 * V_4 )
{
T_3 V_95 ;
int V_19 ;
V_19 = F_54 ( V_4 ) ;
if ( V_19 )
return V_19 ;
F_33 ( V_4 , & V_95 , V_105 ) ;
F_55 ( V_95 , V_106 , 1 ) ;
F_49 ( V_4 , & V_95 , V_105 ) ;
F_33 ( V_4 , & V_95 , V_107 ) ;
F_55 ( V_95 , V_108 , 0 ) ;
F_55 ( V_95 , V_109 , 1 ) ;
F_49 ( V_4 , & V_95 , V_107 ) ;
F_33 ( V_4 , & V_95 , V_110 ) ;
F_55 ( V_95 , V_111 , 0 ) ;
F_55 ( V_95 , V_112 , 1 ) ;
F_55 ( V_95 , V_113 , 1 ) ;
F_55 ( V_95 , V_114 , 1 ) ;
F_55 ( V_95 , V_115 , 1 ) ;
F_55 ( V_95 , V_116 ,
V_117 >> 5 ) ;
F_49 ( V_4 , & V_95 , V_110 ) ;
F_48 ( V_4 , false , V_4 -> V_94 ) ;
V_4 -> V_118 = true ;
V_19 = F_56 ( V_4 , true , false , 0 ) ;
if ( V_19 )
return V_19 ;
F_57 ( V_95 , V_119 , 0 ) ;
F_49 ( V_4 , & V_95 , V_120 ) ;
F_57 ( V_95 , V_121 , 1 ) ;
F_49 ( V_4 , & V_95 , V_122 ) ;
F_58 ( V_4 ) ;
return 0 ;
}
static void F_59 ( struct V_3 * V_4 )
{
F_60 ( V_4 ) ;
F_45 ( V_4 , & V_4 -> V_83 ) ;
F_10 ( V_4 , V_18 ) ;
F_46 ( V_4 ) ;
F_47 ( V_4 -> V_69 ) ;
V_4 -> V_69 = NULL ;
}
static T_4 F_61 ( struct V_3 * V_4 , T_5 * V_123 )
{
return F_62 ( V_124 , V_125 ,
V_126 , V_123 ) ;
}
static int F_63 ( struct V_3 * V_4 )
{
struct V_68 * V_69 = V_4 -> V_69 ;
T_6 * V_127 = V_69 -> V_127 ;
T_7 * V_128 ;
T_7 V_129 , V_130 ;
V_128 = V_4 -> V_131 . V_86 ;
V_130 = V_128 [ V_132 ] ;
if ( V_130 == V_133 )
return 0 ;
F_64 () ;
F_65 ( V_124 , V_125 , V_126 ,
V_127 , V_4 -> V_131 . V_86 , false ) ;
F_64 () ;
V_129 = V_128 [ V_134 ] ;
if ( V_130 != V_129 )
return - V_135 ;
F_66 ( V_4 ,
& V_127 [ V_136 ] ) ;
F_67 ( & V_127 [ V_137 ] ,
V_127 [ V_138 ] -
V_127 [ V_139 ] ) ;
V_127 [ V_140 ] =
V_127 [ V_141 ] +
V_127 [ V_142 ] +
V_127 [ V_143 ] +
V_127 [ V_144 ] ;
F_67 ( & V_127 [ V_145 ] ,
V_127 [ V_146 ] -
V_127 [ V_147 ] ) ;
F_68 ( V_4 , V_127 ) ;
return 0 ;
}
static T_4 F_69 ( struct V_3 * V_4 , T_6 * V_148 ,
struct V_149 * V_150 )
{
struct V_68 * V_69 = V_4 -> V_69 ;
T_6 * V_127 = V_69 -> V_127 ;
int V_151 ;
for ( V_151 = 0 ; V_151 < 100 ; ++ V_151 ) {
if ( F_63 ( V_4 ) == 0 )
break;
F_70 ( 100 ) ;
}
if ( V_148 )
memcpy ( V_148 , V_127 , sizeof( T_6 ) * V_125 ) ;
if ( V_150 ) {
V_150 -> V_152 = V_127 [ V_153 ] ;
V_150 -> V_154 = V_127 [ V_155 ] ;
V_150 -> V_156 = V_127 [ V_146 ] ;
V_150 -> V_157 = V_127 [ V_138 ] ;
V_150 -> V_158 = V_127 [ V_136 ] +
V_127 [ V_159 ] +
V_127 [ V_160 ] ;
V_150 -> V_161 = V_127 [ V_162 ] ;
V_150 -> V_163 = V_127 [ V_140 ] ;
V_150 -> V_164 =
V_127 [ V_165 ] +
V_127 [ V_166 ] ;
V_150 -> V_167 = V_127 [ V_168 ] ;
V_150 -> V_169 = V_127 [ V_170 ] ;
V_150 -> V_171 = V_127 [ V_172 ] ;
V_150 -> V_173 =
V_127 [ V_144 ] ;
V_150 -> V_174 = ( V_150 -> V_164 +
V_150 -> V_167 +
V_150 -> V_169 +
V_127 [ V_175 ] ) ;
V_150 -> V_176 = ( V_150 -> V_173 +
V_127 [ V_177 ] ) ;
}
return V_125 ;
}
static int F_71 ( struct V_3 * V_4 )
{
F_72 ( V_178 , V_179 ) ;
int V_19 ;
F_50 ( V_179 !=
V_180 +
sizeof( V_4 -> V_181 ) ) ;
F_73 ( V_4 ) ;
F_74 ( ! F_75 ( & V_4 -> V_182 ) ) ;
V_19 = F_6 ( V_4 ) ;
if ( V_19 != 0 )
return V_19 ;
memcpy ( F_76 ( V_178 , V_183 ) ,
V_4 -> V_181 . V_184 , sizeof( V_4 -> V_181 ) ) ;
return F_77 ( V_4 , V_185 ,
V_178 , sizeof( V_178 ) , NULL , 0 , NULL ) ;
}
static void F_78 ( struct V_3 * V_4 , struct V_186 * V_187 )
{
struct V_68 * V_69 = V_4 -> V_69 ;
V_187 -> V_188 = V_189 ;
if ( V_69 -> V_190 != - 1 )
V_187 -> V_191 = V_189 ;
else
V_187 -> V_191 = 0 ;
memset ( & V_187 -> V_192 , 0 , sizeof( V_187 -> V_192 ) ) ;
}
static int F_79 ( struct V_3 * V_4 , T_2 type )
{
struct V_68 * V_69 = V_4 -> V_69 ;
int V_19 ;
if ( type & ~ V_189 )
return - V_54 ;
if ( type & V_189 ) {
if ( V_69 -> V_190 != - 1 )
F_80 ( V_4 ,
V_69 -> V_190 ) ;
V_19 = F_81 ( V_4 , V_4 -> V_59 -> V_193 ,
& V_69 -> V_190 ) ;
if ( V_19 )
goto V_194;
F_82 ( V_4 -> V_57 , true ) ;
} else {
V_19 = F_83 ( V_4 ) ;
V_69 -> V_190 = - 1 ;
F_82 ( V_4 -> V_57 , false ) ;
if ( V_19 )
goto V_194;
}
return 0 ;
V_194:
F_32 ( V_4 , V_195 , V_4 -> V_59 , L_5 ,
V_196 , type , V_19 ) ;
return V_19 ;
}
static void F_36 ( struct V_3 * V_4 )
{
struct V_68 * V_69 = V_4 -> V_69 ;
int V_19 ;
V_19 = F_84 ( V_4 , & V_69 -> V_190 ) ;
if ( V_19 != 0 ) {
F_83 ( V_4 ) ;
V_69 -> V_190 = - 1 ;
} else if ( V_69 -> V_190 != - 1 ) {
F_82 ( V_4 -> V_57 , true ) ;
}
}
static void F_85 ( struct V_3 * V_4 ,
const T_1 * V_197 , T_4 V_198 ,
const T_1 * V_199 , T_4 V_200 )
{
unsigned V_201 = V_25 + F_86 ( V_4 ) ;
unsigned V_202 = V_25 + F_87 ( V_4 ) ;
unsigned int V_203 ;
unsigned int V_204 = F_88 ( V_200 , 4 ) ;
F_89 ( V_198 != 4 ) ;
F_90 ( V_4 , V_197 , V_201 ) ;
for ( V_203 = 0 ; V_203 < V_204 ; V_203 ++ )
F_90 ( V_4 , & V_199 [ V_203 ] , V_201 + V_198 + 4 * V_203 ) ;
F_91 () ;
F_15 ( V_4 , ( V_205 V_206 ) 0x45789abc , V_202 ) ;
}
static bool F_92 ( struct V_3 * V_4 )
{
unsigned int V_201 = V_25 + F_86 ( V_4 ) ;
T_1 V_197 ;
F_93 ( V_4 , & V_197 , V_201 ) ;
return F_94 ( V_197 , V_207 ) != 0xffffffff &&
F_94 ( V_197 , V_208 ) ;
}
static void F_95 ( struct V_3 * V_4 , T_1 * V_209 ,
T_4 V_210 , T_4 V_211 )
{
unsigned int V_201 = V_25 + F_86 ( V_4 ) ;
unsigned int V_212 = F_88 ( V_211 , 4 ) ;
int V_203 ;
for ( V_203 = 0 ; V_203 < V_212 ; V_203 ++ )
F_93 ( V_4 , & V_209 [ V_203 ] , V_201 + V_210 + 4 * V_203 ) ;
}
static int F_96 ( struct V_3 * V_4 )
{
struct V_68 * V_69 = V_4 -> V_69 ;
unsigned int V_86 = V_25 + F_97 ( V_4 ) ;
T_1 V_70 ;
T_2 V_213 ;
F_93 ( V_4 , & V_70 , V_86 ) ;
V_213 = F_94 ( V_70 , V_207 ) ;
if ( V_213 == 0 )
return 0 ;
F_98 ( V_70 ) ;
F_90 ( V_4 , & V_70 , V_86 ) ;
V_69 -> V_127 [ V_137 ] = 0 ;
V_69 -> V_127 [ V_145 ] = 0 ;
if ( V_213 == V_214 )
return - V_215 ;
else
return - V_216 ;
}
static int F_99 ( struct V_3 * V_4 ,
struct V_217 * V_218 ,
unsigned int type )
{
const struct V_219 * V_220 ;
T_4 V_221 , V_222 ;
bool V_223 ;
int V_19 ;
if ( type >= F_12 ( V_224 ) ||
V_224 [ type ] . V_225 == NULL )
return - V_74 ;
V_220 = & V_224 [ type ] ;
if ( V_220 -> V_226 != F_100 ( V_4 ) )
return - V_74 ;
V_19 = F_101 ( V_4 , type , & V_221 , & V_222 , & V_223 ) ;
if ( V_19 )
return V_19 ;
if ( V_223 )
return - V_74 ;
V_218 -> V_227 = type ;
V_218 -> V_228 . V_229 = L_6 ;
V_218 -> V_228 . V_230 = V_220 -> V_225 ;
V_218 -> V_228 . V_231 . type = V_232 ;
V_218 -> V_228 . V_231 . V_43 = V_233 ;
V_218 -> V_228 . V_231 . V_221 = V_221 ;
V_218 -> V_228 . V_231 . V_234 = V_222 ;
return 0 ;
}
static int F_102 ( struct V_3 * V_4 ,
struct V_217 * V_235 ,
T_4 V_236 )
{
T_8 V_237 [
V_238 ] ;
T_4 V_203 ;
int V_19 ;
V_19 = F_25 ( V_4 , NULL , V_237 , NULL ) ;
if ( V_19 )
return V_19 ;
for ( V_203 = 0 ; V_203 < V_236 ; V_203 ++ )
V_235 [ V_203 ] . V_239 = V_237 [ V_235 [ V_203 ] . V_227 ] ;
return 0 ;
}
static int F_103 ( struct V_3 * V_4 )
{
struct V_217 * V_235 ;
T_2 V_240 ;
unsigned int type ;
T_4 V_236 ;
int V_19 ;
F_104 () ;
V_19 = F_105 ( V_4 , & V_240 ) ;
if ( V_19 )
return V_19 ;
V_235 = F_106 ( F_107 ( V_240 ) , sizeof( * V_235 ) , V_71 ) ;
if ( ! V_235 )
return - V_72 ;
type = 0 ;
V_236 = 0 ;
while ( V_240 != 0 ) {
if ( V_240 & 1 ) {
V_19 = F_99 ( V_4 , & V_235 [ V_236 ] ,
type ) ;
if ( V_19 == 0 )
V_236 ++ ;
else if ( V_19 != - V_74 )
goto V_194;
}
type ++ ;
V_240 >>= 1 ;
}
V_19 = F_102 ( V_4 , V_235 , V_236 ) ;
if ( V_19 )
goto V_194;
V_19 = F_108 ( V_4 , & V_235 [ 0 ] . V_228 , V_236 , sizeof( * V_235 ) ) ;
V_194:
if ( V_19 )
F_47 ( V_235 ) ;
return V_19 ;
}
