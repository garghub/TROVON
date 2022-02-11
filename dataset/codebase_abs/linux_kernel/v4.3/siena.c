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
V_9 -> V_75 = V_74 ;
F_32 ( V_9 , & V_67 , V_76 ) ;
V_9 -> V_77 = F_33 ( V_67 , V_78 ) - 1 ;
V_18 = F_34 ( V_9 ) ;
if ( V_18 )
goto V_72;
V_18 = F_9 ( V_9 , V_17 ) ;
if ( V_18 ) {
F_31 ( V_9 , V_70 , V_9 -> V_58 , L_2 ) ;
goto V_79;
}
F_35 ( V_9 ) ;
V_18 = F_36 ( V_9 , & V_9 -> V_80 , sizeof( T_3 ) ,
V_68 ) ;
if ( V_18 )
goto V_81;
F_37 ( V_9 -> V_80 . V_82 & 0x0f ) ;
F_38 ( V_9 , V_70 , V_9 -> V_58 ,
L_3 ,
( unsigned long long ) V_9 -> V_80 . V_82 ,
V_9 -> V_80 . V_83 ,
( unsigned long long ) F_39 ( V_9 -> V_80 . V_83 ) ) ;
V_18 = F_23 ( V_9 ) ;
if ( V_18 == - V_53 ) {
F_31 ( V_9 , V_70 , V_9 -> V_58 ,
L_4 ) ;
V_9 -> V_84 = V_85 ;
V_9 -> V_86 . V_87 = V_88 ;
} else if ( V_18 ) {
goto V_89;
}
V_18 = F_40 ( V_9 ) ;
if ( V_18 )
goto V_89;
#ifdef F_41
F_42 ( V_9 ) ;
#endif
F_43 ( V_9 ) ;
return 0 ;
V_89:
F_44 ( V_9 , & V_9 -> V_80 ) ;
V_81:
V_79:
F_45 ( V_9 ) ;
V_72:
F_46 ( V_9 -> V_66 ) ;
return V_18 ;
}
static int F_47 ( struct V_11 * V_9 , bool V_90 ,
const T_2 * V_91 )
{
T_3 V_92 ;
memcpy ( & V_92 , V_9 -> V_93 , sizeof( V_92 ) ) ;
F_48 ( V_9 , & V_92 , V_94 ) ;
F_49 ( sizeof( V_9 -> V_93 ) <
2 * sizeof( V_92 ) + V_95 / 8 ||
V_96 != 0 ) ;
memcpy ( & V_92 , V_9 -> V_93 , sizeof( V_92 ) ) ;
F_48 ( V_9 , & V_92 , V_97 ) ;
memcpy ( & V_92 , V_9 -> V_93 + sizeof( V_92 ) , sizeof( V_92 ) ) ;
F_48 ( V_9 , & V_92 , V_98 ) ;
F_50 ( V_92 , V_99 , 1 ,
V_100 , 1 ) ;
memcpy ( & V_92 , V_9 -> V_93 + 2 * sizeof( V_92 ) ,
V_95 / 8 ) ;
F_48 ( V_9 , & V_92 , V_101 ) ;
memcpy ( V_9 -> V_91 , V_91 ,
sizeof( V_9 -> V_91 ) ) ;
F_51 ( V_9 ) ;
return 0 ;
}
static int F_52 ( struct V_11 * V_9 )
{
T_3 V_92 ;
int V_18 ;
V_18 = F_53 ( V_9 ) ;
if ( V_18 )
return V_18 ;
F_32 ( V_9 , & V_92 , V_102 ) ;
F_54 ( V_92 , V_103 , 1 ) ;
F_48 ( V_9 , & V_92 , V_102 ) ;
F_32 ( V_9 , & V_92 , V_104 ) ;
F_54 ( V_92 , V_105 , 0 ) ;
F_54 ( V_92 , V_106 , 1 ) ;
F_48 ( V_9 , & V_92 , V_104 ) ;
F_32 ( V_9 , & V_92 , V_107 ) ;
F_54 ( V_92 , V_108 , 0 ) ;
F_54 ( V_92 , V_109 , 1 ) ;
F_54 ( V_92 , V_110 , 1 ) ;
F_54 ( V_92 , V_111 , 1 ) ;
F_54 ( V_92 , V_112 , 1 ) ;
F_54 ( V_92 , V_113 ,
V_114 >> 5 ) ;
F_48 ( V_9 , & V_92 , V_107 ) ;
F_47 ( V_9 , false , V_9 -> V_91 ) ;
V_18 = F_55 ( V_9 , true , false , 0 ) ;
if ( V_18 )
return V_18 ;
F_56 ( V_92 , V_115 , 0 ) ;
F_48 ( V_9 , & V_92 , V_116 ) ;
F_56 ( V_92 , V_117 , 1 ) ;
F_48 ( V_9 , & V_92 , V_118 ) ;
F_57 ( V_9 ) ;
return 0 ;
}
static void F_58 ( struct V_11 * V_9 )
{
F_59 ( V_9 ) ;
F_44 ( V_9 , & V_9 -> V_80 ) ;
F_9 ( V_9 , V_17 ) ;
F_45 ( V_9 ) ;
F_46 ( V_9 -> V_66 ) ;
V_9 -> V_66 = NULL ;
}
static T_4 F_60 ( struct V_11 * V_9 , T_5 * V_119 )
{
return F_61 ( V_120 , V_121 ,
V_122 , V_119 ) ;
}
static int F_62 ( struct V_11 * V_9 )
{
struct V_65 * V_66 = V_9 -> V_66 ;
T_6 * V_123 = V_66 -> V_123 ;
T_7 * V_124 ;
T_7 V_125 , V_126 ;
V_124 = V_9 -> V_127 . V_83 ;
V_126 = V_124 [ V_128 ] ;
if ( V_126 == V_129 )
return 0 ;
F_63 () ;
F_64 ( V_120 , V_121 , V_122 ,
V_123 , V_9 -> V_127 . V_83 , false ) ;
F_63 () ;
V_125 = V_124 [ V_130 ] ;
if ( V_126 != V_125 )
return - V_131 ;
F_65 ( V_9 ,
& V_123 [ V_132 ] ) ;
F_66 ( & V_123 [ V_133 ] ,
V_123 [ V_134 ] -
V_123 [ V_135 ] ) ;
V_123 [ V_136 ] =
V_123 [ V_137 ] +
V_123 [ V_138 ] +
V_123 [ V_139 ] +
V_123 [ V_140 ] ;
F_66 ( & V_123 [ V_141 ] ,
V_123 [ V_142 ] -
V_123 [ V_143 ] ) ;
F_67 ( V_9 , V_123 ) ;
return 0 ;
}
static T_4 F_68 ( struct V_11 * V_9 , T_6 * V_144 ,
struct V_145 * V_146 )
{
struct V_65 * V_66 = V_9 -> V_66 ;
T_6 * V_123 = V_66 -> V_123 ;
int V_147 ;
for ( V_147 = 0 ; V_147 < 100 ; ++ V_147 ) {
if ( F_62 ( V_9 ) == 0 )
break;
F_69 ( 100 ) ;
}
if ( V_144 )
memcpy ( V_144 , V_123 , sizeof( T_6 ) * V_121 ) ;
if ( V_146 ) {
V_146 -> V_148 = V_123 [ V_149 ] ;
V_146 -> V_150 = V_123 [ V_151 ] ;
V_146 -> V_152 = V_123 [ V_142 ] ;
V_146 -> V_153 = V_123 [ V_134 ] ;
V_146 -> V_154 = V_123 [ V_132 ] +
V_123 [ V_155 ] +
V_123 [ V_156 ] ;
V_146 -> V_157 = V_123 [ V_158 ] ;
V_146 -> V_159 = V_123 [ V_136 ] ;
V_146 -> V_160 =
V_123 [ V_161 ] +
V_123 [ V_162 ] ;
V_146 -> V_163 = V_123 [ V_164 ] ;
V_146 -> V_165 = V_123 [ V_166 ] ;
V_146 -> V_167 = V_123 [ V_168 ] ;
V_146 -> V_169 =
V_123 [ V_140 ] ;
V_146 -> V_170 = ( V_146 -> V_160 +
V_146 -> V_163 +
V_146 -> V_165 +
V_123 [ V_171 ] ) ;
V_146 -> V_172 = ( V_146 -> V_169 +
V_123 [ V_173 ] ) ;
}
return V_121 ;
}
static int F_70 ( struct V_11 * V_9 )
{
F_71 ( V_174 , V_175 ) ;
int V_18 ;
F_49 ( V_175 !=
V_176 +
sizeof( V_9 -> V_177 ) ) ;
F_72 ( V_9 ) ;
F_73 ( ! F_74 ( & V_9 -> V_178 ) ) ;
V_18 = F_5 ( V_9 ) ;
if ( V_18 != 0 )
return V_18 ;
memcpy ( F_75 ( V_174 , V_179 ) ,
V_9 -> V_177 . V_180 , sizeof( V_9 -> V_177 ) ) ;
return F_76 ( V_9 , V_181 ,
V_174 , sizeof( V_174 ) , NULL , 0 , NULL ) ;
}
static void F_77 ( struct V_11 * V_9 , struct V_182 * V_183 )
{
struct V_65 * V_66 = V_9 -> V_66 ;
V_183 -> V_184 = V_185 ;
if ( V_66 -> V_186 != - 1 )
V_183 -> V_187 = V_185 ;
else
V_183 -> V_187 = 0 ;
memset ( & V_183 -> V_188 , 0 , sizeof( V_183 -> V_188 ) ) ;
}
static int F_78 ( struct V_11 * V_9 , T_2 type )
{
struct V_65 * V_66 = V_9 -> V_66 ;
int V_18 ;
if ( type & ~ V_185 )
return - V_53 ;
if ( type & V_185 ) {
if ( V_66 -> V_186 != - 1 )
F_79 ( V_9 ,
V_66 -> V_186 ) ;
V_18 = F_80 ( V_9 , V_9 -> V_58 -> V_189 ,
& V_66 -> V_186 ) ;
if ( V_18 )
goto V_190;
F_81 ( V_9 -> V_56 , true ) ;
} else {
V_18 = F_82 ( V_9 ) ;
V_66 -> V_186 = - 1 ;
F_81 ( V_9 -> V_56 , false ) ;
if ( V_18 )
goto V_190;
}
return 0 ;
V_190:
F_31 ( V_9 , V_191 , V_9 -> V_58 , L_5 ,
V_192 , type , V_18 ) ;
return V_18 ;
}
static void F_35 ( struct V_11 * V_9 )
{
struct V_65 * V_66 = V_9 -> V_66 ;
int V_18 ;
V_18 = F_83 ( V_9 , & V_66 -> V_186 ) ;
if ( V_18 != 0 ) {
F_82 ( V_9 ) ;
V_66 -> V_186 = - 1 ;
} else if ( V_66 -> V_186 != - 1 ) {
F_81 ( V_9 -> V_56 , true ) ;
}
}
static void F_84 ( struct V_11 * V_9 ,
const T_1 * V_193 , T_4 V_194 ,
const T_1 * V_195 , T_4 V_196 )
{
unsigned V_197 = V_24 + F_85 ( V_9 ) ;
unsigned V_198 = V_24 + F_86 ( V_9 ) ;
unsigned int V_199 ;
unsigned int V_200 = F_87 ( V_196 , 4 ) ;
F_88 ( V_194 != 4 ) ;
F_89 ( V_9 , V_193 , V_197 ) ;
for ( V_199 = 0 ; V_199 < V_200 ; V_199 ++ )
F_89 ( V_9 , & V_195 [ V_199 ] , V_197 + V_194 + 4 * V_199 ) ;
F_90 () ;
F_14 ( V_9 , ( V_201 V_202 ) 0x45789abc , V_198 ) ;
}
static bool F_91 ( struct V_11 * V_9 )
{
unsigned int V_197 = V_24 + F_85 ( V_9 ) ;
T_1 V_193 ;
F_92 ( V_9 , & V_193 , V_197 ) ;
return F_93 ( V_193 , V_203 ) != 0xffffffff &&
F_93 ( V_193 , V_204 ) ;
}
static void F_94 ( struct V_11 * V_9 , T_1 * V_205 ,
T_4 V_206 , T_4 V_207 )
{
unsigned int V_197 = V_24 + F_85 ( V_9 ) ;
unsigned int V_208 = F_87 ( V_207 , 4 ) ;
int V_199 ;
for ( V_199 = 0 ; V_199 < V_208 ; V_199 ++ )
F_92 ( V_9 , & V_205 [ V_199 ] , V_197 + V_206 + 4 * V_199 ) ;
}
static int F_95 ( struct V_11 * V_9 )
{
struct V_65 * V_66 = V_9 -> V_66 ;
unsigned int V_83 = V_24 + F_96 ( V_9 ) ;
T_1 V_67 ;
T_2 V_209 ;
F_92 ( V_9 , & V_67 , V_83 ) ;
V_209 = F_93 ( V_67 , V_203 ) ;
if ( V_209 == 0 )
return 0 ;
F_97 ( V_67 ) ;
F_89 ( V_9 , & V_67 , V_83 ) ;
V_66 -> V_123 [ V_133 ] = 0 ;
V_66 -> V_123 [ V_141 ] = 0 ;
if ( V_209 == V_210 )
return - V_211 ;
else
return - V_212 ;
}
static int F_98 ( struct V_11 * V_9 ,
struct V_213 * V_214 ,
unsigned int type )
{
const struct V_215 * V_216 ;
T_4 V_217 , V_218 ;
bool V_219 ;
int V_18 ;
if ( type >= F_11 ( V_220 ) ||
V_220 [ type ] . V_221 == NULL )
return - V_71 ;
V_216 = & V_220 [ type ] ;
if ( V_216 -> V_222 != F_99 ( V_9 ) )
return - V_71 ;
V_18 = F_100 ( V_9 , type , & V_217 , & V_218 , & V_219 ) ;
if ( V_18 )
return V_18 ;
if ( V_219 )
return - V_71 ;
V_214 -> V_223 = type ;
V_214 -> V_224 . V_225 = L_6 ;
V_214 -> V_224 . V_226 = V_216 -> V_221 ;
V_214 -> V_224 . V_227 . type = V_228 ;
V_214 -> V_224 . V_227 . V_42 = V_229 ;
V_214 -> V_224 . V_227 . V_217 = V_217 ;
V_214 -> V_224 . V_227 . V_230 = V_218 ;
return 0 ;
}
static int F_101 ( struct V_11 * V_9 ,
struct V_213 * V_231 ,
T_4 V_232 )
{
T_8 V_233 [
V_234 ] ;
T_4 V_199 ;
int V_18 ;
V_18 = F_24 ( V_9 , NULL , V_233 , NULL ) ;
if ( V_18 )
return V_18 ;
for ( V_199 = 0 ; V_199 < V_232 ; V_199 ++ )
V_231 [ V_199 ] . V_235 = V_233 [ V_231 [ V_199 ] . V_223 ] ;
return 0 ;
}
static int F_102 ( struct V_11 * V_9 )
{
struct V_213 * V_231 ;
T_2 V_236 ;
unsigned int type ;
T_4 V_232 ;
int V_18 ;
F_103 () ;
V_18 = F_104 ( V_9 , & V_236 ) ;
if ( V_18 )
return V_18 ;
V_231 = F_105 ( F_106 ( V_236 ) , sizeof( * V_231 ) , V_68 ) ;
if ( ! V_231 )
return - V_69 ;
type = 0 ;
V_232 = 0 ;
while ( V_236 != 0 ) {
if ( V_236 & 1 ) {
V_18 = F_98 ( V_9 , & V_231 [ V_232 ] ,
type ) ;
if ( V_18 == 0 )
V_232 ++ ;
else if ( V_18 != - V_71 )
goto V_190;
}
type ++ ;
V_236 >>= 1 ;
}
V_18 = F_101 ( V_9 , V_231 , V_232 ) ;
if ( V_18 )
goto V_190;
V_18 = F_107 ( V_9 , & V_231 [ 0 ] . V_224 , V_232 , sizeof( * V_231 ) ) ;
V_190:
if ( V_18 )
F_46 ( V_231 ) ;
return V_18 ;
}
