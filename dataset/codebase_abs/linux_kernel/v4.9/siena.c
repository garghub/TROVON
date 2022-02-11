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
V_19 = F_56 ( V_4 , true , false , 0 ) ;
if ( V_19 )
return V_19 ;
F_57 ( V_95 , V_118 , 0 ) ;
F_49 ( V_4 , & V_95 , V_119 ) ;
F_57 ( V_95 , V_120 , 1 ) ;
F_49 ( V_4 , & V_95 , V_121 ) ;
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
static T_4 F_61 ( struct V_3 * V_4 , T_5 * V_122 )
{
return F_62 ( V_123 , V_124 ,
V_125 , V_122 ) ;
}
static int F_63 ( struct V_3 * V_4 )
{
struct V_68 * V_69 = V_4 -> V_69 ;
T_6 * V_126 = V_69 -> V_126 ;
T_7 * V_127 ;
T_7 V_128 , V_129 ;
V_127 = V_4 -> V_130 . V_86 ;
V_129 = V_127 [ V_131 ] ;
if ( V_129 == V_132 )
return 0 ;
F_64 () ;
F_65 ( V_123 , V_124 , V_125 ,
V_126 , V_4 -> V_130 . V_86 , false ) ;
F_64 () ;
V_128 = V_127 [ V_133 ] ;
if ( V_129 != V_128 )
return - V_134 ;
F_66 ( V_4 ,
& V_126 [ V_135 ] ) ;
F_67 ( & V_126 [ V_136 ] ,
V_126 [ V_137 ] -
V_126 [ V_138 ] ) ;
V_126 [ V_139 ] =
V_126 [ V_140 ] +
V_126 [ V_141 ] +
V_126 [ V_142 ] +
V_126 [ V_143 ] ;
F_67 ( & V_126 [ V_144 ] ,
V_126 [ V_145 ] -
V_126 [ V_146 ] ) ;
F_68 ( V_4 , V_126 ) ;
return 0 ;
}
static T_4 F_69 ( struct V_3 * V_4 , T_6 * V_147 ,
struct V_148 * V_149 )
{
struct V_68 * V_69 = V_4 -> V_69 ;
T_6 * V_126 = V_69 -> V_126 ;
int V_150 ;
for ( V_150 = 0 ; V_150 < 100 ; ++ V_150 ) {
if ( F_63 ( V_4 ) == 0 )
break;
F_70 ( 100 ) ;
}
if ( V_147 )
memcpy ( V_147 , V_126 , sizeof( T_6 ) * V_124 ) ;
if ( V_149 ) {
V_149 -> V_151 = V_126 [ V_152 ] ;
V_149 -> V_153 = V_126 [ V_154 ] ;
V_149 -> V_155 = V_126 [ V_145 ] ;
V_149 -> V_156 = V_126 [ V_137 ] ;
V_149 -> V_157 = V_126 [ V_135 ] +
V_126 [ V_158 ] +
V_126 [ V_159 ] ;
V_149 -> V_160 = V_126 [ V_161 ] ;
V_149 -> V_162 = V_126 [ V_139 ] ;
V_149 -> V_163 =
V_126 [ V_164 ] +
V_126 [ V_165 ] ;
V_149 -> V_166 = V_126 [ V_167 ] ;
V_149 -> V_168 = V_126 [ V_169 ] ;
V_149 -> V_170 = V_126 [ V_171 ] ;
V_149 -> V_172 =
V_126 [ V_143 ] ;
V_149 -> V_173 = ( V_149 -> V_163 +
V_149 -> V_166 +
V_149 -> V_168 +
V_126 [ V_174 ] ) ;
V_149 -> V_175 = ( V_149 -> V_172 +
V_126 [ V_176 ] ) ;
}
return V_124 ;
}
static int F_71 ( struct V_3 * V_4 )
{
F_72 ( V_177 , V_178 ) ;
int V_19 ;
F_50 ( V_178 !=
V_179 +
sizeof( V_4 -> V_180 ) ) ;
F_73 ( V_4 ) ;
F_74 ( ! F_75 ( & V_4 -> V_181 ) ) ;
V_19 = F_6 ( V_4 ) ;
if ( V_19 != 0 )
return V_19 ;
memcpy ( F_76 ( V_177 , V_182 ) ,
V_4 -> V_180 . V_183 , sizeof( V_4 -> V_180 ) ) ;
return F_77 ( V_4 , V_184 ,
V_177 , sizeof( V_177 ) , NULL , 0 , NULL ) ;
}
static void F_78 ( struct V_3 * V_4 , struct V_185 * V_186 )
{
struct V_68 * V_69 = V_4 -> V_69 ;
V_186 -> V_187 = V_188 ;
if ( V_69 -> V_189 != - 1 )
V_186 -> V_190 = V_188 ;
else
V_186 -> V_190 = 0 ;
memset ( & V_186 -> V_191 , 0 , sizeof( V_186 -> V_191 ) ) ;
}
static int F_79 ( struct V_3 * V_4 , T_2 type )
{
struct V_68 * V_69 = V_4 -> V_69 ;
int V_19 ;
if ( type & ~ V_188 )
return - V_54 ;
if ( type & V_188 ) {
if ( V_69 -> V_189 != - 1 )
F_80 ( V_4 ,
V_69 -> V_189 ) ;
V_19 = F_81 ( V_4 , V_4 -> V_59 -> V_192 ,
& V_69 -> V_189 ) ;
if ( V_19 )
goto V_193;
F_82 ( V_4 -> V_57 , true ) ;
} else {
V_19 = F_83 ( V_4 ) ;
V_69 -> V_189 = - 1 ;
F_82 ( V_4 -> V_57 , false ) ;
if ( V_19 )
goto V_193;
}
return 0 ;
V_193:
F_32 ( V_4 , V_194 , V_4 -> V_59 , L_5 ,
V_195 , type , V_19 ) ;
return V_19 ;
}
static void F_36 ( struct V_3 * V_4 )
{
struct V_68 * V_69 = V_4 -> V_69 ;
int V_19 ;
V_19 = F_84 ( V_4 , & V_69 -> V_189 ) ;
if ( V_19 != 0 ) {
F_83 ( V_4 ) ;
V_69 -> V_189 = - 1 ;
} else if ( V_69 -> V_189 != - 1 ) {
F_82 ( V_4 -> V_57 , true ) ;
}
}
static void F_85 ( struct V_3 * V_4 ,
const T_1 * V_196 , T_4 V_197 ,
const T_1 * V_198 , T_4 V_199 )
{
unsigned V_200 = V_25 + F_86 ( V_4 ) ;
unsigned V_201 = V_25 + F_87 ( V_4 ) ;
unsigned int V_202 ;
unsigned int V_203 = F_88 ( V_199 , 4 ) ;
F_89 ( V_197 != 4 ) ;
F_90 ( V_4 , V_196 , V_200 ) ;
for ( V_202 = 0 ; V_202 < V_203 ; V_202 ++ )
F_90 ( V_4 , & V_198 [ V_202 ] , V_200 + V_197 + 4 * V_202 ) ;
F_91 () ;
F_15 ( V_4 , ( V_204 V_205 ) 0x45789abc , V_201 ) ;
}
static bool F_92 ( struct V_3 * V_4 )
{
unsigned int V_200 = V_25 + F_86 ( V_4 ) ;
T_1 V_196 ;
F_93 ( V_4 , & V_196 , V_200 ) ;
return F_94 ( V_196 , V_206 ) != 0xffffffff &&
F_94 ( V_196 , V_207 ) ;
}
static void F_95 ( struct V_3 * V_4 , T_1 * V_208 ,
T_4 V_209 , T_4 V_210 )
{
unsigned int V_200 = V_25 + F_86 ( V_4 ) ;
unsigned int V_211 = F_88 ( V_210 , 4 ) ;
int V_202 ;
for ( V_202 = 0 ; V_202 < V_211 ; V_202 ++ )
F_93 ( V_4 , & V_208 [ V_202 ] , V_200 + V_209 + 4 * V_202 ) ;
}
static int F_96 ( struct V_3 * V_4 )
{
struct V_68 * V_69 = V_4 -> V_69 ;
unsigned int V_86 = V_25 + F_97 ( V_4 ) ;
T_1 V_70 ;
T_2 V_212 ;
F_93 ( V_4 , & V_70 , V_86 ) ;
V_212 = F_94 ( V_70 , V_206 ) ;
if ( V_212 == 0 )
return 0 ;
F_98 ( V_70 ) ;
F_90 ( V_4 , & V_70 , V_86 ) ;
V_69 -> V_126 [ V_136 ] = 0 ;
V_69 -> V_126 [ V_144 ] = 0 ;
if ( V_212 == V_213 )
return - V_214 ;
else
return - V_215 ;
}
static int F_99 ( struct V_3 * V_4 ,
struct V_216 * V_217 ,
unsigned int type )
{
const struct V_218 * V_219 ;
T_4 V_220 , V_221 ;
bool V_222 ;
int V_19 ;
if ( type >= F_12 ( V_223 ) ||
V_223 [ type ] . V_224 == NULL )
return - V_74 ;
V_219 = & V_223 [ type ] ;
if ( V_219 -> V_225 != F_100 ( V_4 ) )
return - V_74 ;
V_19 = F_101 ( V_4 , type , & V_220 , & V_221 , & V_222 ) ;
if ( V_19 )
return V_19 ;
if ( V_222 )
return - V_74 ;
V_217 -> V_226 = type ;
V_217 -> V_227 . V_228 = L_6 ;
V_217 -> V_227 . V_229 = V_219 -> V_224 ;
V_217 -> V_227 . V_230 . type = V_231 ;
V_217 -> V_227 . V_230 . V_43 = V_232 ;
V_217 -> V_227 . V_230 . V_220 = V_220 ;
V_217 -> V_227 . V_230 . V_233 = V_221 ;
return 0 ;
}
static int F_102 ( struct V_3 * V_4 ,
struct V_216 * V_234 ,
T_4 V_235 )
{
T_8 V_236 [
V_237 ] ;
T_4 V_202 ;
int V_19 ;
V_19 = F_25 ( V_4 , NULL , V_236 , NULL ) ;
if ( V_19 )
return V_19 ;
for ( V_202 = 0 ; V_202 < V_235 ; V_202 ++ )
V_234 [ V_202 ] . V_238 = V_236 [ V_234 [ V_202 ] . V_226 ] ;
return 0 ;
}
static int F_103 ( struct V_3 * V_4 )
{
struct V_216 * V_234 ;
T_2 V_239 ;
unsigned int type ;
T_4 V_235 ;
int V_19 ;
F_104 () ;
V_19 = F_105 ( V_4 , & V_239 ) ;
if ( V_19 )
return V_19 ;
V_234 = F_106 ( F_107 ( V_239 ) , sizeof( * V_234 ) , V_71 ) ;
if ( ! V_234 )
return - V_72 ;
type = 0 ;
V_235 = 0 ;
while ( V_239 != 0 ) {
if ( V_239 & 1 ) {
V_19 = F_99 ( V_4 , & V_234 [ V_235 ] ,
type ) ;
if ( V_19 == 0 )
V_235 ++ ;
else if ( V_19 != - V_74 )
goto V_193;
}
type ++ ;
V_239 >>= 1 ;
}
V_19 = F_102 ( V_4 , V_234 , V_235 ) ;
if ( V_19 )
goto V_193;
V_19 = F_108 ( V_4 , & V_234 [ 0 ] . V_227 , V_235 , sizeof( * V_234 ) ) ;
V_193:
if ( V_19 )
F_47 ( V_234 ) ;
return V_19 ;
}
