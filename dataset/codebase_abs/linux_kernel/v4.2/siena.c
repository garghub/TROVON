static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
if ( V_2 -> V_4 )
F_2 ( V_3 ,
V_5 ,
V_6 ,
V_7 ,
V_2 -> V_4 - 1 ) ;
else
F_2 ( V_3 ,
V_5 ,
V_8 ,
V_7 , 0 ) ;
F_3 ( V_2 -> V_9 , & V_3 , V_10 ,
V_2 -> V_2 ) ;
}
void F_4 ( struct V_11 * V_9 )
{
if ( V_9 -> V_12 ++ == 0 )
F_5 ( V_9 ) ;
}
void F_6 ( struct V_11 * V_9 )
{
if ( -- V_9 -> V_12 == 0 )
F_5 ( V_9 ) ;
}
static int F_7 ( struct V_11 * V_9 , struct V_13 * V_14 )
{
enum V_15 V_16 = V_17 ;
int V_18 , V_19 ;
F_8 ( V_9 , V_16 ) ;
V_18 = F_9 ( V_9 , V_16 ) ;
if ( V_18 )
goto V_20;
V_14 -> V_21 =
F_10 ( V_9 , V_22 ,
F_11 ( V_22 ) )
? - 1 : 1 ;
V_18 = F_9 ( V_9 , V_16 ) ;
V_20:
V_19 = F_12 ( V_9 , V_16 , V_18 == 0 ) ;
return V_18 ? V_18 : V_19 ;
}
static void F_13 ( struct V_11 * V_9 , T_2 V_23 )
{
F_14 ( V_9 , F_15 ( V_23 ) ,
V_24 + V_25 ) ;
}
static int F_16 ( struct V_11 * V_9 ,
struct V_26 * V_27 )
{
int V_18 ;
switch ( V_27 -> V_28 ) {
case V_29 :
return F_17 ( V_9 ,
V_27 -> V_30 != V_31 ,
F_18 ( V_9 ) ) ;
case V_32 :
case V_33 :
case V_34 :
V_27 -> V_28 = V_32 ;
return F_17 ( V_9 , true , V_35 ) ;
case V_36 :
case V_37 :
case V_38 :
V_27 -> V_28 = V_36 ;
V_18 = F_17 ( V_9 , true ,
V_39 ) ;
if ( V_18 != 0 )
V_18 = F_17 ( V_9 , true , V_40 ) ;
return V_18 ;
default:
return - V_41 ;
}
}
static int F_19 ( T_2 * V_42 )
{
enum {
V_43 = ( V_44 | V_45 |
V_46 | V_47 |
V_48 ) ,
V_49 = ( V_43 |
V_50 << V_51 ) ,
};
if ( ( * V_42 & V_49 ) == V_49 ) {
* V_42 &= ~ V_49 ;
return V_52 ;
}
if ( ( * V_42 & V_43 ) == V_43 ) {
* V_42 &= ~ V_43 ;
return V_17 ;
}
return - V_53 ;
}
static void F_20 ( struct V_11 * V_9 )
{
struct V_54 * V_55 = F_21 ( V_9 -> V_56 ) ;
F_22 ( V_55 ) ;
}
static int F_23 ( struct V_11 * V_9 )
{
T_2 V_57 = 0 ;
int V_18 ;
V_18 = F_24 ( V_9 , V_9 -> V_58 -> V_59 , NULL , & V_57 ) ;
V_9 -> V_60 =
( V_57 & ( 1 << V_61 ) ) ?
3072 : 6144 ;
return V_18 ;
}
static int F_25 ( struct V_11 * V_9 )
{
F_26 ( V_9 , V_62 / 2 ) ;
return 0 ;
}
static unsigned int F_27 ( struct V_11 * V_9 )
{
return V_24 +
V_63 * V_64 ;
}
static int F_28 ( struct V_11 * V_9 )
{
struct V_65 * V_66 ;
T_3 V_67 ;
int V_18 ;
V_66 = F_29 ( sizeof( struct V_65 ) , V_68 ) ;
if ( ! V_66 )
return - V_69 ;
V_66 -> V_9 = V_9 ;
V_9 -> V_66 = V_66 ;
if ( F_30 ( V_9 ) != 0 ) {
F_31 ( V_9 , V_70 , V_9 -> V_58 ,
L_1 ) ;
V_18 = - V_71 ;
goto V_72;
}
V_9 -> V_73 = V_74 ;
F_32 ( V_9 , & V_67 , V_75 ) ;
V_9 -> V_76 = F_33 ( V_67 , V_77 ) - 1 ;
V_18 = F_34 ( V_9 ) ;
if ( V_18 )
goto V_72;
V_18 = F_9 ( V_9 , V_17 ) ;
if ( V_18 ) {
F_31 ( V_9 , V_70 , V_9 -> V_58 , L_2 ) ;
goto V_78;
}
F_35 ( V_9 ) ;
V_18 = F_36 ( V_9 , & V_9 -> V_79 , sizeof( T_3 ) ,
V_68 ) ;
if ( V_18 )
goto V_80;
F_37 ( V_9 -> V_79 . V_81 & 0x0f ) ;
F_38 ( V_9 , V_70 , V_9 -> V_58 ,
L_3 ,
( unsigned long long ) V_9 -> V_79 . V_81 ,
V_9 -> V_79 . V_82 ,
( unsigned long long ) F_39 ( V_9 -> V_79 . V_82 ) ) ;
V_18 = F_23 ( V_9 ) ;
if ( V_18 == - V_53 ) {
F_31 ( V_9 , V_70 , V_9 -> V_58 ,
L_4 ) ;
V_9 -> V_83 = V_84 ;
V_9 -> V_85 . V_86 = V_87 ;
} else if ( V_18 ) {
goto V_88;
}
V_18 = F_40 ( V_9 ) ;
if ( V_18 )
goto V_88;
#ifdef F_41
F_42 ( V_9 ) ;
#endif
F_43 ( V_9 ) ;
return 0 ;
V_88:
F_44 ( V_9 , & V_9 -> V_79 ) ;
V_80:
V_78:
F_45 ( V_9 ) ;
V_72:
F_46 ( V_9 -> V_66 ) ;
return V_18 ;
}
static int F_47 ( struct V_11 * V_9 , bool V_89 ,
const T_2 * V_90 )
{
T_3 V_91 ;
memcpy ( & V_91 , V_9 -> V_92 , sizeof( V_91 ) ) ;
F_48 ( V_9 , & V_91 , V_93 ) ;
F_49 ( sizeof( V_9 -> V_92 ) <
2 * sizeof( V_91 ) + V_94 / 8 ||
V_95 != 0 ) ;
memcpy ( & V_91 , V_9 -> V_92 , sizeof( V_91 ) ) ;
F_48 ( V_9 , & V_91 , V_96 ) ;
memcpy ( & V_91 , V_9 -> V_92 + sizeof( V_91 ) , sizeof( V_91 ) ) ;
F_48 ( V_9 , & V_91 , V_97 ) ;
F_50 ( V_91 , V_98 , 1 ,
V_99 , 1 ) ;
memcpy ( & V_91 , V_9 -> V_92 + 2 * sizeof( V_91 ) ,
V_94 / 8 ) ;
F_48 ( V_9 , & V_91 , V_100 ) ;
memcpy ( V_9 -> V_90 , V_90 ,
sizeof( V_9 -> V_90 ) ) ;
F_51 ( V_9 ) ;
return 0 ;
}
static int F_52 ( struct V_11 * V_9 )
{
T_3 V_91 ;
int V_18 ;
V_18 = F_53 ( V_9 ) ;
if ( V_18 )
return V_18 ;
F_32 ( V_9 , & V_91 , V_101 ) ;
F_54 ( V_91 , V_102 , 1 ) ;
F_48 ( V_9 , & V_91 , V_101 ) ;
F_32 ( V_9 , & V_91 , V_103 ) ;
F_54 ( V_91 , V_104 , 0 ) ;
F_54 ( V_91 , V_105 , 1 ) ;
F_48 ( V_9 , & V_91 , V_103 ) ;
F_32 ( V_9 , & V_91 , V_106 ) ;
F_54 ( V_91 , V_107 , 0 ) ;
F_54 ( V_91 , V_108 , 1 ) ;
F_54 ( V_91 , V_109 , 1 ) ;
F_54 ( V_91 , V_110 , 1 ) ;
F_54 ( V_91 , V_111 , 1 ) ;
F_54 ( V_91 , V_112 ,
V_113 >> 5 ) ;
F_48 ( V_9 , & V_91 , V_106 ) ;
F_47 ( V_9 , false , V_9 -> V_90 ) ;
V_18 = F_55 ( V_9 , true , false , 0 ) ;
if ( V_18 )
return V_18 ;
F_56 ( V_91 , V_114 , 0 ) ;
F_48 ( V_9 , & V_91 , V_115 ) ;
F_56 ( V_91 , V_116 , 1 ) ;
F_48 ( V_9 , & V_91 , V_117 ) ;
F_57 ( V_9 ) ;
return 0 ;
}
static void F_58 ( struct V_11 * V_9 )
{
F_59 ( V_9 ) ;
F_44 ( V_9 , & V_9 -> V_79 ) ;
F_9 ( V_9 , V_17 ) ;
F_45 ( V_9 ) ;
F_46 ( V_9 -> V_66 ) ;
V_9 -> V_66 = NULL ;
}
static T_4 F_60 ( struct V_11 * V_9 , T_5 * V_118 )
{
return F_61 ( V_119 , V_120 ,
V_121 , V_118 ) ;
}
static int F_62 ( struct V_11 * V_9 )
{
struct V_65 * V_66 = V_9 -> V_66 ;
T_6 * V_122 = V_66 -> V_122 ;
T_7 * V_123 ;
T_7 V_124 , V_125 ;
V_123 = V_9 -> V_126 . V_82 ;
V_125 = V_123 [ V_127 ] ;
if ( V_125 == V_128 )
return 0 ;
F_63 () ;
F_64 ( V_119 , V_120 , V_121 ,
V_122 , V_9 -> V_126 . V_82 , false ) ;
F_63 () ;
V_124 = V_123 [ V_129 ] ;
if ( V_125 != V_124 )
return - V_130 ;
F_65 ( V_9 ,
& V_122 [ V_131 ] ) ;
F_66 ( & V_122 [ V_132 ] ,
V_122 [ V_133 ] -
V_122 [ V_134 ] ) ;
V_122 [ V_135 ] =
V_122 [ V_136 ] +
V_122 [ V_137 ] +
V_122 [ V_138 ] +
V_122 [ V_139 ] ;
F_66 ( & V_122 [ V_140 ] ,
V_122 [ V_141 ] -
V_122 [ V_142 ] ) ;
F_67 ( V_9 , V_122 ) ;
return 0 ;
}
static T_4 F_68 ( struct V_11 * V_9 , T_6 * V_143 ,
struct V_144 * V_145 )
{
struct V_65 * V_66 = V_9 -> V_66 ;
T_6 * V_122 = V_66 -> V_122 ;
int V_146 ;
for ( V_146 = 0 ; V_146 < 100 ; ++ V_146 ) {
if ( F_62 ( V_9 ) == 0 )
break;
F_69 ( 100 ) ;
}
if ( V_143 )
memcpy ( V_143 , V_122 , sizeof( T_6 ) * V_120 ) ;
if ( V_145 ) {
V_145 -> V_147 = V_122 [ V_148 ] ;
V_145 -> V_149 = V_122 [ V_150 ] ;
V_145 -> V_151 = V_122 [ V_141 ] ;
V_145 -> V_152 = V_122 [ V_133 ] ;
V_145 -> V_153 = V_122 [ V_131 ] +
V_122 [ V_154 ] +
V_122 [ V_155 ] ;
V_145 -> V_156 = V_122 [ V_157 ] ;
V_145 -> V_158 = V_122 [ V_135 ] ;
V_145 -> V_159 =
V_122 [ V_160 ] +
V_122 [ V_161 ] ;
V_145 -> V_162 = V_122 [ V_163 ] ;
V_145 -> V_164 = V_122 [ V_165 ] ;
V_145 -> V_166 = V_122 [ V_167 ] ;
V_145 -> V_168 =
V_122 [ V_139 ] ;
V_145 -> V_169 = ( V_145 -> V_159 +
V_145 -> V_162 +
V_145 -> V_164 +
V_122 [ V_170 ] ) ;
V_145 -> V_171 = ( V_145 -> V_168 +
V_122 [ V_172 ] ) ;
}
return V_120 ;
}
static int F_70 ( struct V_11 * V_9 )
{
F_71 ( V_173 , V_174 ) ;
int V_18 ;
F_49 ( V_174 !=
V_175 +
sizeof( V_9 -> V_176 ) ) ;
F_72 ( V_9 ) ;
F_73 ( ! F_74 ( & V_9 -> V_177 ) ) ;
V_18 = F_5 ( V_9 ) ;
if ( V_18 != 0 )
return V_18 ;
memcpy ( F_75 ( V_173 , V_178 ) ,
V_9 -> V_176 . V_179 , sizeof( V_9 -> V_176 ) ) ;
return F_76 ( V_9 , V_180 ,
V_173 , sizeof( V_173 ) , NULL , 0 , NULL ) ;
}
static void F_77 ( struct V_11 * V_9 , struct V_181 * V_182 )
{
struct V_65 * V_66 = V_9 -> V_66 ;
V_182 -> V_183 = V_184 ;
if ( V_66 -> V_185 != - 1 )
V_182 -> V_186 = V_184 ;
else
V_182 -> V_186 = 0 ;
memset ( & V_182 -> V_187 , 0 , sizeof( V_182 -> V_187 ) ) ;
}
static int F_78 ( struct V_11 * V_9 , T_2 type )
{
struct V_65 * V_66 = V_9 -> V_66 ;
int V_18 ;
if ( type & ~ V_184 )
return - V_53 ;
if ( type & V_184 ) {
if ( V_66 -> V_185 != - 1 )
F_79 ( V_9 ,
V_66 -> V_185 ) ;
V_18 = F_80 ( V_9 , V_9 -> V_58 -> V_188 ,
& V_66 -> V_185 ) ;
if ( V_18 )
goto V_189;
F_81 ( V_9 -> V_56 , true ) ;
} else {
V_18 = F_82 ( V_9 ) ;
V_66 -> V_185 = - 1 ;
F_81 ( V_9 -> V_56 , false ) ;
if ( V_18 )
goto V_189;
}
return 0 ;
V_189:
F_31 ( V_9 , V_190 , V_9 -> V_58 , L_5 ,
V_191 , type , V_18 ) ;
return V_18 ;
}
static void F_35 ( struct V_11 * V_9 )
{
struct V_65 * V_66 = V_9 -> V_66 ;
int V_18 ;
V_18 = F_83 ( V_9 , & V_66 -> V_185 ) ;
if ( V_18 != 0 ) {
F_82 ( V_9 ) ;
V_66 -> V_185 = - 1 ;
} else if ( V_66 -> V_185 != - 1 ) {
F_81 ( V_9 -> V_56 , true ) ;
}
}
static void F_84 ( struct V_11 * V_9 ,
const T_1 * V_192 , T_4 V_193 ,
const T_1 * V_194 , T_4 V_195 )
{
unsigned V_196 = V_24 + F_85 ( V_9 ) ;
unsigned V_197 = V_24 + F_86 ( V_9 ) ;
unsigned int V_198 ;
unsigned int V_199 = F_87 ( V_195 , 4 ) ;
F_88 ( V_193 != 4 ) ;
F_89 ( V_9 , V_192 , V_196 ) ;
for ( V_198 = 0 ; V_198 < V_199 ; V_198 ++ )
F_89 ( V_9 , & V_194 [ V_198 ] , V_196 + V_193 + 4 * V_198 ) ;
F_90 () ;
F_14 ( V_9 , ( V_200 V_201 ) 0x45789abc , V_197 ) ;
}
static bool F_91 ( struct V_11 * V_9 )
{
unsigned int V_196 = V_24 + F_85 ( V_9 ) ;
T_1 V_192 ;
F_92 ( V_9 , & V_192 , V_196 ) ;
return F_93 ( V_192 , V_202 ) != 0xffffffff &&
F_93 ( V_192 , V_203 ) ;
}
static void F_94 ( struct V_11 * V_9 , T_1 * V_204 ,
T_4 V_205 , T_4 V_206 )
{
unsigned int V_196 = V_24 + F_85 ( V_9 ) ;
unsigned int V_207 = F_87 ( V_206 , 4 ) ;
int V_198 ;
for ( V_198 = 0 ; V_198 < V_207 ; V_198 ++ )
F_92 ( V_9 , & V_204 [ V_198 ] , V_196 + V_205 + 4 * V_198 ) ;
}
static int F_95 ( struct V_11 * V_9 )
{
struct V_65 * V_66 = V_9 -> V_66 ;
unsigned int V_82 = V_24 + F_96 ( V_9 ) ;
T_1 V_67 ;
T_2 V_208 ;
F_92 ( V_9 , & V_67 , V_82 ) ;
V_208 = F_93 ( V_67 , V_202 ) ;
if ( V_208 == 0 )
return 0 ;
F_97 ( V_67 ) ;
F_89 ( V_9 , & V_67 , V_82 ) ;
V_66 -> V_122 [ V_132 ] = 0 ;
V_66 -> V_122 [ V_140 ] = 0 ;
if ( V_208 == V_209 )
return - V_210 ;
else
return - V_211 ;
}
static int F_98 ( struct V_11 * V_9 ,
struct V_212 * V_213 ,
unsigned int type )
{
const struct V_214 * V_215 ;
T_4 V_216 , V_217 ;
bool V_218 ;
int V_18 ;
if ( type >= F_11 ( V_219 ) ||
V_219 [ type ] . V_220 == NULL )
return - V_71 ;
V_215 = & V_219 [ type ] ;
if ( V_215 -> V_221 != F_99 ( V_9 ) )
return - V_71 ;
V_18 = F_100 ( V_9 , type , & V_216 , & V_217 , & V_218 ) ;
if ( V_18 )
return V_18 ;
if ( V_218 )
return - V_71 ;
V_213 -> V_222 = type ;
V_213 -> V_223 . V_224 = L_6 ;
V_213 -> V_223 . V_225 = V_215 -> V_220 ;
V_213 -> V_223 . V_226 . type = V_227 ;
V_213 -> V_223 . V_226 . V_42 = V_228 ;
V_213 -> V_223 . V_226 . V_216 = V_216 ;
V_213 -> V_223 . V_226 . V_229 = V_217 ;
return 0 ;
}
static int F_101 ( struct V_11 * V_9 ,
struct V_212 * V_230 ,
T_4 V_231 )
{
T_8 V_232 [
V_233 ] ;
T_4 V_198 ;
int V_18 ;
V_18 = F_24 ( V_9 , NULL , V_232 , NULL ) ;
if ( V_18 )
return V_18 ;
for ( V_198 = 0 ; V_198 < V_231 ; V_198 ++ )
V_230 [ V_198 ] . V_234 = V_232 [ V_230 [ V_198 ] . V_222 ] ;
return 0 ;
}
static int F_102 ( struct V_11 * V_9 )
{
struct V_212 * V_230 ;
T_2 V_235 ;
unsigned int type ;
T_4 V_231 ;
int V_18 ;
F_103 () ;
V_18 = F_104 ( V_9 , & V_235 ) ;
if ( V_18 )
return V_18 ;
V_230 = F_105 ( F_106 ( V_235 ) , sizeof( * V_230 ) , V_68 ) ;
if ( ! V_230 )
return - V_69 ;
type = 0 ;
V_231 = 0 ;
while ( V_235 != 0 ) {
if ( V_235 & 1 ) {
V_18 = F_98 ( V_9 , & V_230 [ V_231 ] ,
type ) ;
if ( V_18 == 0 )
V_231 ++ ;
else if ( V_18 != - V_71 )
goto V_189;
}
type ++ ;
V_235 >>= 1 ;
}
V_18 = F_101 ( V_9 , V_230 , V_231 ) ;
if ( V_18 )
goto V_189;
V_18 = F_107 ( V_9 , & V_230 [ 0 ] . V_223 , V_231 , sizeof( * V_230 ) ) ;
V_189:
if ( V_18 )
F_46 ( V_230 ) ;
return V_18 ;
}
