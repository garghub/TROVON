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
F_47 ( V_4 ) ;
V_75:
F_48 ( V_4 -> V_69 ) ;
return V_19 ;
}
static int F_49 ( struct V_3 * V_4 )
{
T_3 V_93 ;
F_33 ( V_4 , & V_93 , V_94 ) ;
memcpy ( V_4 -> V_95 , & V_93 , sizeof( V_93 ) ) ;
F_33 ( V_4 , & V_93 , V_96 ) ;
memcpy ( V_4 -> V_95 + sizeof( V_93 ) , & V_93 , sizeof( V_93 ) ) ;
F_33 ( V_4 , & V_93 , V_97 ) ;
memcpy ( V_4 -> V_95 + 2 * sizeof( V_93 ) , & V_93 ,
V_98 / 8 ) ;
F_50 ( V_4 ) ;
return 0 ;
}
static int F_51 ( struct V_3 * V_4 , bool V_99 ,
const T_2 * V_100 , const T_4 * V_101 )
{
T_3 V_93 ;
if ( V_101 )
memcpy ( V_4 -> V_95 , V_101 , sizeof( V_93 ) ) ;
memcpy ( & V_93 , V_4 -> V_95 , sizeof( V_93 ) ) ;
F_52 ( V_4 , & V_93 , V_102 ) ;
F_53 ( sizeof( V_4 -> V_95 ) <
2 * sizeof( V_93 ) + V_98 / 8 ||
V_103 != 0 ) ;
memcpy ( & V_93 , V_4 -> V_95 , sizeof( V_93 ) ) ;
F_52 ( V_4 , & V_93 , V_94 ) ;
memcpy ( & V_93 , V_4 -> V_95 + sizeof( V_93 ) , sizeof( V_93 ) ) ;
F_52 ( V_4 , & V_93 , V_96 ) ;
F_54 ( V_93 , V_104 , 1 ,
V_105 , 1 ) ;
memcpy ( & V_93 , V_4 -> V_95 + 2 * sizeof( V_93 ) ,
V_98 / 8 ) ;
F_52 ( V_4 , & V_93 , V_97 ) ;
memcpy ( V_4 -> V_100 , V_100 ,
sizeof( V_4 -> V_100 ) ) ;
F_55 ( V_4 ) ;
return 0 ;
}
static int F_56 ( struct V_3 * V_4 )
{
T_3 V_93 ;
int V_19 ;
V_19 = F_57 ( V_4 ) ;
if ( V_19 )
return V_19 ;
F_33 ( V_4 , & V_93 , V_106 ) ;
F_58 ( V_93 , V_107 , 1 ) ;
F_52 ( V_4 , & V_93 , V_106 ) ;
F_33 ( V_4 , & V_93 , V_108 ) ;
F_58 ( V_93 , V_109 , 0 ) ;
F_58 ( V_93 , V_110 , 1 ) ;
F_52 ( V_4 , & V_93 , V_108 ) ;
F_33 ( V_4 , & V_93 , V_111 ) ;
F_58 ( V_93 , V_112 , 0 ) ;
F_58 ( V_93 , V_113 , 1 ) ;
F_58 ( V_93 , V_114 , 1 ) ;
F_58 ( V_93 , V_115 , 1 ) ;
F_58 ( V_93 , V_116 , 1 ) ;
F_58 ( V_93 , V_117 ,
V_118 >> 5 ) ;
F_52 ( V_4 , & V_93 , V_111 ) ;
F_51 ( V_4 , false , V_4 -> V_100 , NULL ) ;
V_4 -> V_119 = true ;
V_19 = F_59 ( V_4 , true , false , 0 ) ;
if ( V_19 )
return V_19 ;
F_60 ( V_93 , V_120 , 0 ) ;
F_52 ( V_4 , & V_93 , V_121 ) ;
F_60 ( V_93 , V_122 , 1 ) ;
F_52 ( V_4 , & V_93 , V_123 ) ;
F_61 ( V_4 ) ;
return 0 ;
}
static void F_62 ( struct V_3 * V_4 )
{
F_63 ( V_4 ) ;
F_45 ( V_4 , & V_4 -> V_83 ) ;
F_10 ( V_4 , V_18 ) ;
F_46 ( V_4 ) ;
F_47 ( V_4 ) ;
F_48 ( V_4 -> V_69 ) ;
V_4 -> V_69 = NULL ;
}
static T_5 F_64 ( struct V_3 * V_4 , T_4 * V_124 )
{
return F_65 ( V_125 , V_126 ,
V_127 , V_124 ) ;
}
static int F_66 ( struct V_3 * V_4 )
{
struct V_68 * V_69 = V_4 -> V_69 ;
T_6 * V_128 = V_69 -> V_128 ;
T_7 * V_129 ;
T_7 V_130 , V_131 ;
V_129 = V_4 -> V_132 . V_86 ;
V_131 = V_129 [ V_133 ] ;
if ( V_131 == V_134 )
return 0 ;
F_67 () ;
F_68 ( V_125 , V_126 , V_127 ,
V_128 , V_4 -> V_132 . V_86 , false ) ;
F_67 () ;
V_130 = V_129 [ V_135 ] ;
if ( V_131 != V_130 )
return - V_136 ;
F_69 ( V_4 ,
& V_128 [ V_137 ] ) ;
F_70 ( & V_128 [ V_138 ] ,
V_128 [ V_139 ] -
V_128 [ V_140 ] ) ;
V_128 [ V_141 ] =
V_128 [ V_142 ] +
V_128 [ V_143 ] +
V_128 [ V_144 ] +
V_128 [ V_145 ] ;
F_70 ( & V_128 [ V_146 ] ,
V_128 [ V_147 ] -
V_128 [ V_148 ] ) ;
F_71 ( V_4 , V_128 ) ;
return 0 ;
}
static T_5 F_72 ( struct V_3 * V_4 , T_6 * V_149 ,
struct V_150 * V_151 )
{
struct V_68 * V_69 = V_4 -> V_69 ;
T_6 * V_128 = V_69 -> V_128 ;
int V_152 ;
for ( V_152 = 0 ; V_152 < 100 ; ++ V_152 ) {
if ( F_66 ( V_4 ) == 0 )
break;
F_73 ( 100 ) ;
}
if ( V_149 )
memcpy ( V_149 , V_128 , sizeof( T_6 ) * V_126 ) ;
if ( V_151 ) {
V_151 -> V_153 = V_128 [ V_154 ] ;
V_151 -> V_155 = V_128 [ V_156 ] ;
V_151 -> V_157 = V_128 [ V_147 ] ;
V_151 -> V_158 = V_128 [ V_139 ] ;
V_151 -> V_159 = V_128 [ V_137 ] +
V_128 [ V_160 ] +
V_128 [ V_161 ] ;
V_151 -> V_162 = V_128 [ V_163 ] ;
V_151 -> V_164 = V_128 [ V_141 ] ;
V_151 -> V_165 =
V_128 [ V_166 ] +
V_128 [ V_167 ] ;
V_151 -> V_168 = V_128 [ V_169 ] ;
V_151 -> V_170 = V_128 [ V_171 ] ;
V_151 -> V_172 = V_128 [ V_173 ] ;
V_151 -> V_174 =
V_128 [ V_145 ] ;
V_151 -> V_175 = ( V_151 -> V_165 +
V_151 -> V_168 +
V_151 -> V_170 +
V_128 [ V_176 ] ) ;
V_151 -> V_177 = ( V_151 -> V_174 +
V_128 [ V_178 ] ) ;
}
return V_126 ;
}
static int F_74 ( struct V_3 * V_4 )
{
F_75 ( V_179 , V_180 ) ;
int V_19 ;
F_53 ( V_180 !=
V_181 +
sizeof( V_4 -> V_182 ) ) ;
F_76 ( V_4 ) ;
F_77 ( ! F_78 ( & V_4 -> V_183 ) ) ;
V_19 = F_6 ( V_4 ) ;
if ( V_19 != 0 )
return V_19 ;
memcpy ( F_79 ( V_179 , V_184 ) ,
V_4 -> V_182 . V_185 , sizeof( V_4 -> V_182 ) ) ;
return F_80 ( V_4 , V_186 ,
V_179 , sizeof( V_179 ) , NULL , 0 , NULL ) ;
}
static void F_81 ( struct V_3 * V_4 , struct V_187 * V_188 )
{
struct V_68 * V_69 = V_4 -> V_69 ;
V_188 -> V_189 = V_190 ;
if ( V_69 -> V_191 != - 1 )
V_188 -> V_192 = V_190 ;
else
V_188 -> V_192 = 0 ;
memset ( & V_188 -> V_193 , 0 , sizeof( V_188 -> V_193 ) ) ;
}
static int F_82 ( struct V_3 * V_4 , T_2 type )
{
struct V_68 * V_69 = V_4 -> V_69 ;
int V_19 ;
if ( type & ~ V_190 )
return - V_54 ;
if ( type & V_190 ) {
if ( V_69 -> V_191 != - 1 )
F_83 ( V_4 ,
V_69 -> V_191 ) ;
V_19 = F_84 ( V_4 , V_4 -> V_59 -> V_194 ,
& V_69 -> V_191 ) ;
if ( V_19 )
goto V_195;
F_85 ( V_4 -> V_57 , true ) ;
} else {
V_19 = F_86 ( V_4 ) ;
V_69 -> V_191 = - 1 ;
F_85 ( V_4 -> V_57 , false ) ;
if ( V_19 )
goto V_195;
}
return 0 ;
V_195:
F_32 ( V_4 , V_196 , V_4 -> V_59 , L_5 ,
V_197 , type , V_19 ) ;
return V_19 ;
}
static void F_36 ( struct V_3 * V_4 )
{
struct V_68 * V_69 = V_4 -> V_69 ;
int V_19 ;
V_19 = F_87 ( V_4 , & V_69 -> V_191 ) ;
if ( V_19 != 0 ) {
F_86 ( V_4 ) ;
V_69 -> V_191 = - 1 ;
} else if ( V_69 -> V_191 != - 1 ) {
F_85 ( V_4 -> V_57 , true ) ;
}
}
static void F_88 ( struct V_3 * V_4 ,
const T_1 * V_198 , T_5 V_199 ,
const T_1 * V_200 , T_5 V_201 )
{
unsigned V_202 = V_25 + F_89 ( V_4 ) ;
unsigned V_203 = V_25 + F_90 ( V_4 ) ;
unsigned int V_204 ;
unsigned int V_205 = F_91 ( V_201 , 4 ) ;
F_92 ( V_199 != 4 ) ;
F_93 ( V_4 , V_198 , V_202 ) ;
for ( V_204 = 0 ; V_204 < V_205 ; V_204 ++ )
F_93 ( V_4 , & V_200 [ V_204 ] , V_202 + V_199 + 4 * V_204 ) ;
F_94 () ;
F_15 ( V_4 , ( V_206 V_207 ) 0x45789abc , V_203 ) ;
}
static bool F_95 ( struct V_3 * V_4 )
{
unsigned int V_202 = V_25 + F_89 ( V_4 ) ;
T_1 V_198 ;
F_96 ( V_4 , & V_198 , V_202 ) ;
return F_97 ( V_198 , V_208 ) != 0xffffffff &&
F_97 ( V_198 , V_209 ) ;
}
static void F_98 ( struct V_3 * V_4 , T_1 * V_210 ,
T_5 V_211 , T_5 V_212 )
{
unsigned int V_202 = V_25 + F_89 ( V_4 ) ;
unsigned int V_213 = F_91 ( V_212 , 4 ) ;
int V_204 ;
for ( V_204 = 0 ; V_204 < V_213 ; V_204 ++ )
F_96 ( V_4 , & V_210 [ V_204 ] , V_202 + V_211 + 4 * V_204 ) ;
}
static int F_99 ( struct V_3 * V_4 )
{
struct V_68 * V_69 = V_4 -> V_69 ;
unsigned int V_86 = V_25 + F_100 ( V_4 ) ;
T_1 V_70 ;
T_2 V_214 ;
F_96 ( V_4 , & V_70 , V_86 ) ;
V_214 = F_97 ( V_70 , V_208 ) ;
if ( V_214 == 0 )
return 0 ;
F_101 ( V_70 ) ;
F_93 ( V_4 , & V_70 , V_86 ) ;
V_69 -> V_128 [ V_138 ] = 0 ;
V_69 -> V_128 [ V_146 ] = 0 ;
if ( V_214 == V_215 )
return - V_216 ;
else
return - V_217 ;
}
static int F_102 ( struct V_3 * V_4 ,
struct V_218 * V_219 ,
unsigned int type )
{
const struct V_220 * V_221 ;
T_5 V_222 , V_223 ;
bool V_224 ;
int V_19 ;
if ( type >= F_12 ( V_225 ) ||
V_225 [ type ] . V_226 == NULL )
return - V_74 ;
V_221 = & V_225 [ type ] ;
if ( V_221 -> V_227 != F_103 ( V_4 ) )
return - V_74 ;
V_19 = F_104 ( V_4 , type , & V_222 , & V_223 , & V_224 ) ;
if ( V_19 )
return V_19 ;
if ( V_224 )
return - V_74 ;
V_219 -> V_228 = type ;
V_219 -> V_229 . V_230 = L_6 ;
V_219 -> V_229 . V_231 = V_221 -> V_226 ;
V_219 -> V_229 . V_232 . type = V_233 ;
V_219 -> V_229 . V_232 . V_43 = V_234 ;
V_219 -> V_229 . V_232 . V_222 = V_222 ;
V_219 -> V_229 . V_232 . V_235 = V_223 ;
return 0 ;
}
static int F_105 ( struct V_3 * V_4 ,
struct V_218 * V_236 ,
T_5 V_237 )
{
T_8 V_238 [
V_239 ] ;
T_5 V_204 ;
int V_19 ;
V_19 = F_25 ( V_4 , NULL , V_238 , NULL ) ;
if ( V_19 )
return V_19 ;
for ( V_204 = 0 ; V_204 < V_237 ; V_204 ++ )
V_236 [ V_204 ] . V_240 = V_238 [ V_236 [ V_204 ] . V_228 ] ;
return 0 ;
}
static int F_106 ( struct V_3 * V_4 )
{
struct V_218 * V_236 ;
T_2 V_241 ;
unsigned int type ;
T_5 V_237 ;
int V_19 ;
F_107 () ;
V_19 = F_108 ( V_4 , & V_241 ) ;
if ( V_19 )
return V_19 ;
V_236 = F_109 ( F_110 ( V_241 ) , sizeof( * V_236 ) , V_71 ) ;
if ( ! V_236 )
return - V_72 ;
type = 0 ;
V_237 = 0 ;
while ( V_241 != 0 ) {
if ( V_241 & 1 ) {
V_19 = F_102 ( V_4 , & V_236 [ V_237 ] ,
type ) ;
if ( V_19 == 0 )
V_237 ++ ;
else if ( V_19 != - V_74 )
goto V_195;
}
type ++ ;
V_241 >>= 1 ;
}
V_19 = F_105 ( V_4 , V_236 , V_237 ) ;
if ( V_19 )
goto V_195;
V_19 = F_111 ( V_4 , & V_236 [ 0 ] . V_229 , V_237 , sizeof( * V_236 ) ) ;
V_195:
if ( V_19 )
F_48 ( V_236 ) ;
return V_19 ;
}
