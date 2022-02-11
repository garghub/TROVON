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
F_41 ( V_9 ) ;
F_42 ( V_9 ) ;
return 0 ;
V_88:
F_43 ( V_9 , & V_9 -> V_79 ) ;
V_80:
V_78:
F_44 ( V_9 ) ;
V_72:
F_45 ( V_9 -> V_66 ) ;
return V_18 ;
}
static void F_46 ( struct V_11 * V_9 )
{
T_3 V_89 ;
memcpy ( & V_89 , V_9 -> V_90 , sizeof( V_89 ) ) ;
F_47 ( V_9 , & V_89 , V_91 ) ;
F_48 ( sizeof( V_9 -> V_90 ) <
2 * sizeof( V_89 ) + V_92 / 8 ||
V_93 != 0 ) ;
memcpy ( & V_89 , V_9 -> V_90 , sizeof( V_89 ) ) ;
F_47 ( V_9 , & V_89 , V_94 ) ;
memcpy ( & V_89 , V_9 -> V_90 + sizeof( V_89 ) , sizeof( V_89 ) ) ;
F_47 ( V_9 , & V_89 , V_95 ) ;
F_49 ( V_89 , V_96 , 1 ,
V_97 , 1 ) ;
memcpy ( & V_89 , V_9 -> V_90 + 2 * sizeof( V_89 ) ,
V_92 / 8 ) ;
F_47 ( V_9 , & V_89 , V_98 ) ;
F_50 ( V_9 ) ;
}
static int F_51 ( struct V_11 * V_9 )
{
T_3 V_89 ;
int V_18 ;
V_18 = F_52 ( V_9 ) ;
if ( V_18 )
return V_18 ;
F_32 ( V_9 , & V_89 , V_99 ) ;
F_53 ( V_89 , V_100 , 1 ) ;
F_47 ( V_9 , & V_89 , V_99 ) ;
F_32 ( V_9 , & V_89 , V_101 ) ;
F_53 ( V_89 , V_102 , 0 ) ;
F_53 ( V_89 , V_103 , 1 ) ;
F_47 ( V_9 , & V_89 , V_101 ) ;
F_32 ( V_9 , & V_89 , V_104 ) ;
F_53 ( V_89 , V_105 , 0 ) ;
F_53 ( V_89 , V_106 , 1 ) ;
F_53 ( V_89 , V_107 , 1 ) ;
F_53 ( V_89 , V_108 , 1 ) ;
F_53 ( V_89 , V_109 , 1 ) ;
F_53 ( V_89 , V_110 ,
V_111 >> 5 ) ;
F_47 ( V_9 , & V_89 , V_104 ) ;
F_46 ( V_9 ) ;
V_18 = F_54 ( V_9 , true , false , 0 ) ;
if ( V_18 )
return V_18 ;
F_55 ( V_89 , V_112 , 0 ) ;
F_47 ( V_9 , & V_89 , V_113 ) ;
F_55 ( V_89 , V_114 , 1 ) ;
F_47 ( V_9 , & V_89 , V_115 ) ;
F_56 ( V_9 ) ;
return 0 ;
}
static void F_57 ( struct V_11 * V_9 )
{
F_58 ( V_9 ) ;
F_43 ( V_9 , & V_9 -> V_79 ) ;
F_9 ( V_9 , V_17 ) ;
F_44 ( V_9 ) ;
F_45 ( V_9 -> V_66 ) ;
V_9 -> V_66 = NULL ;
}
static T_4 F_59 ( struct V_11 * V_9 , T_5 * V_116 )
{
return F_60 ( V_117 , V_118 ,
V_119 , V_116 ) ;
}
static int F_61 ( struct V_11 * V_9 )
{
struct V_65 * V_66 = V_9 -> V_66 ;
T_6 * V_120 = V_66 -> V_120 ;
T_7 * V_121 ;
T_7 V_122 , V_123 ;
V_121 = V_9 -> V_124 . V_82 ;
V_123 = V_121 [ V_125 ] ;
if ( V_123 == V_126 )
return 0 ;
F_62 () ;
F_63 ( V_117 , V_118 , V_119 ,
V_120 , V_9 -> V_124 . V_82 , false ) ;
F_62 () ;
V_122 = V_121 [ V_127 ] ;
if ( V_123 != V_122 )
return - V_128 ;
F_64 ( V_9 ,
& V_120 [ V_129 ] ) ;
F_65 ( & V_120 [ V_130 ] ,
V_120 [ V_131 ] -
V_120 [ V_132 ] ) ;
V_120 [ V_133 ] =
V_120 [ V_134 ] +
V_120 [ V_135 ] +
V_120 [ V_136 ] +
V_120 [ V_137 ] ;
F_65 ( & V_120 [ V_138 ] ,
V_120 [ V_139 ] -
V_120 [ V_140 ] ) ;
F_66 ( V_9 , V_120 ) ;
return 0 ;
}
static T_4 F_67 ( struct V_11 * V_9 , T_6 * V_141 ,
struct V_142 * V_143 )
{
struct V_65 * V_66 = V_9 -> V_66 ;
T_6 * V_120 = V_66 -> V_120 ;
int V_144 ;
for ( V_144 = 0 ; V_144 < 100 ; ++ V_144 ) {
if ( F_61 ( V_9 ) == 0 )
break;
F_68 ( 100 ) ;
}
if ( V_141 )
memcpy ( V_141 , V_120 , sizeof( T_6 ) * V_118 ) ;
if ( V_143 ) {
V_143 -> V_145 = V_120 [ V_146 ] ;
V_143 -> V_147 = V_120 [ V_148 ] ;
V_143 -> V_149 = V_120 [ V_139 ] ;
V_143 -> V_150 = V_120 [ V_131 ] ;
V_143 -> V_151 = V_120 [ V_129 ] +
V_120 [ V_152 ] +
V_120 [ V_153 ] ;
V_143 -> V_154 = V_120 [ V_155 ] ;
V_143 -> V_156 = V_120 [ V_133 ] ;
V_143 -> V_157 =
V_120 [ V_158 ] +
V_120 [ V_159 ] ;
V_143 -> V_160 = V_120 [ V_161 ] ;
V_143 -> V_162 = V_120 [ V_163 ] ;
V_143 -> V_164 = V_120 [ V_165 ] ;
V_143 -> V_166 =
V_120 [ V_137 ] ;
V_143 -> V_167 = ( V_143 -> V_157 +
V_143 -> V_160 +
V_143 -> V_162 +
V_120 [ V_168 ] ) ;
V_143 -> V_169 = ( V_143 -> V_166 +
V_120 [ V_170 ] ) ;
}
return V_118 ;
}
static int F_69 ( struct V_11 * V_9 )
{
F_70 ( V_171 , V_172 ) ;
int V_18 ;
F_48 ( V_172 !=
V_173 +
sizeof( V_9 -> V_174 ) ) ;
F_71 ( V_9 ) ;
F_72 ( ! F_73 ( & V_9 -> V_175 ) ) ;
V_18 = F_5 ( V_9 ) ;
if ( V_18 != 0 )
return V_18 ;
memcpy ( F_74 ( V_171 , V_176 ) ,
V_9 -> V_174 . V_177 , sizeof( V_9 -> V_174 ) ) ;
return F_75 ( V_9 , V_178 ,
V_171 , sizeof( V_171 ) , NULL , 0 , NULL ) ;
}
static void F_76 ( struct V_11 * V_9 , struct V_179 * V_180 )
{
struct V_65 * V_66 = V_9 -> V_66 ;
V_180 -> V_181 = V_182 ;
if ( V_66 -> V_183 != - 1 )
V_180 -> V_184 = V_182 ;
else
V_180 -> V_184 = 0 ;
memset ( & V_180 -> V_185 , 0 , sizeof( V_180 -> V_185 ) ) ;
}
static int F_77 ( struct V_11 * V_9 , T_2 type )
{
struct V_65 * V_66 = V_9 -> V_66 ;
int V_18 ;
if ( type & ~ V_182 )
return - V_53 ;
if ( type & V_182 ) {
if ( V_66 -> V_183 != - 1 )
F_78 ( V_9 ,
V_66 -> V_183 ) ;
V_18 = F_79 ( V_9 , V_9 -> V_58 -> V_186 ,
& V_66 -> V_183 ) ;
if ( V_18 )
goto V_187;
F_80 ( V_9 -> V_56 , true ) ;
} else {
V_18 = F_81 ( V_9 ) ;
V_66 -> V_183 = - 1 ;
F_80 ( V_9 -> V_56 , false ) ;
if ( V_18 )
goto V_187;
}
return 0 ;
V_187:
F_31 ( V_9 , V_188 , V_9 -> V_58 , L_5 ,
V_189 , type , V_18 ) ;
return V_18 ;
}
static void F_35 ( struct V_11 * V_9 )
{
struct V_65 * V_66 = V_9 -> V_66 ;
int V_18 ;
V_18 = F_82 ( V_9 , & V_66 -> V_183 ) ;
if ( V_18 != 0 ) {
F_81 ( V_9 ) ;
V_66 -> V_183 = - 1 ;
} else if ( V_66 -> V_183 != - 1 ) {
F_80 ( V_9 -> V_56 , true ) ;
}
}
static void F_83 ( struct V_11 * V_9 ,
const T_1 * V_190 , T_4 V_191 ,
const T_1 * V_192 , T_4 V_193 )
{
unsigned V_194 = V_24 + F_84 ( V_9 ) ;
unsigned V_195 = V_24 + F_85 ( V_9 ) ;
unsigned int V_196 ;
unsigned int V_197 = F_86 ( V_193 , 4 ) ;
F_87 ( V_191 != 4 ) ;
F_88 ( V_9 , V_190 , V_194 ) ;
for ( V_196 = 0 ; V_196 < V_197 ; V_196 ++ )
F_88 ( V_9 , & V_192 [ V_196 ] , V_194 + V_191 + 4 * V_196 ) ;
F_89 () ;
F_14 ( V_9 , ( V_198 V_199 ) 0x45789abc , V_195 ) ;
}
static bool F_90 ( struct V_11 * V_9 )
{
unsigned int V_194 = V_24 + F_84 ( V_9 ) ;
T_1 V_190 ;
F_91 ( V_9 , & V_190 , V_194 ) ;
return F_92 ( V_190 , V_200 ) != 0xffffffff &&
F_92 ( V_190 , V_201 ) ;
}
static void F_93 ( struct V_11 * V_9 , T_1 * V_202 ,
T_4 V_203 , T_4 V_204 )
{
unsigned int V_194 = V_24 + F_84 ( V_9 ) ;
unsigned int V_205 = F_86 ( V_204 , 4 ) ;
int V_196 ;
for ( V_196 = 0 ; V_196 < V_205 ; V_196 ++ )
F_91 ( V_9 , & V_202 [ V_196 ] , V_194 + V_203 + 4 * V_196 ) ;
}
static int F_94 ( struct V_11 * V_9 )
{
struct V_65 * V_66 = V_9 -> V_66 ;
unsigned int V_82 = V_24 + F_95 ( V_9 ) ;
T_1 V_67 ;
T_2 V_206 ;
F_91 ( V_9 , & V_67 , V_82 ) ;
V_206 = F_92 ( V_67 , V_200 ) ;
if ( V_206 == 0 )
return 0 ;
F_96 ( V_67 ) ;
F_88 ( V_9 , & V_67 , V_82 ) ;
V_66 -> V_120 [ V_130 ] = 0 ;
V_66 -> V_120 [ V_138 ] = 0 ;
if ( V_206 == V_207 )
return - V_208 ;
else
return - V_209 ;
}
static int F_97 ( struct V_11 * V_9 ,
struct V_210 * V_211 ,
unsigned int type )
{
const struct V_212 * V_213 ;
T_4 V_214 , V_215 ;
bool V_216 ;
int V_18 ;
if ( type >= F_11 ( V_217 ) ||
V_217 [ type ] . V_218 == NULL )
return - V_71 ;
V_213 = & V_217 [ type ] ;
if ( V_213 -> V_219 != F_98 ( V_9 ) )
return - V_71 ;
V_18 = F_99 ( V_9 , type , & V_214 , & V_215 , & V_216 ) ;
if ( V_18 )
return V_18 ;
if ( V_216 )
return - V_71 ;
V_211 -> V_220 = type ;
V_211 -> V_221 . V_222 = L_6 ;
V_211 -> V_221 . V_223 = V_213 -> V_218 ;
V_211 -> V_221 . V_224 . type = V_225 ;
V_211 -> V_221 . V_224 . V_42 = V_226 ;
V_211 -> V_221 . V_224 . V_214 = V_214 ;
V_211 -> V_221 . V_224 . V_227 = V_215 ;
return 0 ;
}
static int F_100 ( struct V_11 * V_9 ,
struct V_210 * V_228 ,
T_4 V_229 )
{
T_8 V_230 [
V_231 ] ;
T_4 V_196 ;
int V_18 ;
V_18 = F_24 ( V_9 , NULL , V_230 , NULL ) ;
if ( V_18 )
return V_18 ;
for ( V_196 = 0 ; V_196 < V_229 ; V_196 ++ )
V_228 [ V_196 ] . V_232 = V_230 [ V_228 [ V_196 ] . V_220 ] ;
return 0 ;
}
static int F_101 ( struct V_11 * V_9 )
{
struct V_210 * V_228 ;
T_2 V_233 ;
unsigned int type ;
T_4 V_229 ;
int V_18 ;
F_102 () ;
V_18 = F_103 ( V_9 , & V_233 ) ;
if ( V_18 )
return V_18 ;
V_228 = F_104 ( F_105 ( V_233 ) , sizeof( * V_228 ) , V_68 ) ;
if ( ! V_228 )
return - V_69 ;
type = 0 ;
V_229 = 0 ;
while ( V_233 != 0 ) {
if ( V_233 & 1 ) {
V_18 = F_97 ( V_9 , & V_228 [ V_229 ] ,
type ) ;
if ( V_18 == 0 )
V_229 ++ ;
else if ( V_18 != - V_71 )
goto V_187;
}
type ++ ;
V_233 >>= 1 ;
}
V_18 = F_100 ( V_9 , V_228 , V_229 ) ;
if ( V_18 )
goto V_187;
V_18 = F_106 ( V_9 , & V_228 [ 0 ] . V_221 , V_229 , sizeof( * V_228 ) ) ;
V_187:
if ( V_18 )
F_45 ( V_228 ) ;
return V_18 ;
}
