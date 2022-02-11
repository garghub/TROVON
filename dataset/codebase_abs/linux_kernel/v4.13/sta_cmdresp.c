static void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 ;
unsigned long V_9 ;
F_2 ( V_6 , ERROR ,
L_1 ,
V_4 -> V_10 , V_4 -> V_11 ) ;
if ( V_6 -> V_12 -> V_13 )
V_6 -> V_14 . V_15 = - 1 ;
switch ( F_3 ( V_4 -> V_10 ) ) {
case V_16 :
V_8 = & V_4 -> V_17 . V_18 ;
F_2 ( V_6 , ERROR ,
L_2 ,
V_4 -> V_11 , F_3 ( V_8 -> V_19 ) ) ;
if ( F_3 ( V_8 -> V_19 ) == V_20 &&
( F_3 ( V_8 -> V_17 . V_21 ) & V_22 ) &&
V_2 -> V_23 == V_24 )
V_6 -> V_25 = V_26 ;
break;
case V_27 :
case V_28 :
F_4 ( V_6 ) ;
F_5 ( & V_6 -> V_29 , V_9 ) ;
V_6 -> V_30 = false ;
F_6 ( & V_6 -> V_29 , V_9 ) ;
break;
case V_31 :
break;
case V_32 :
F_2 ( V_6 , V_33 ,
L_3 ) ;
break;
default:
break;
}
F_7 ( V_6 , V_6 -> V_12 ) ;
F_5 ( & V_6 -> V_29 , V_9 ) ;
V_6 -> V_12 = NULL ;
F_6 ( & V_6 -> V_29 , V_9 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_34 * V_35 =
& V_4 -> V_17 . V_35 ;
struct V_36 * V_37 =
& V_2 -> V_38 ;
V_2 -> V_39 = F_3 ( V_35 -> V_39 ) ;
V_2 -> V_40 = F_3 ( V_35 -> V_40 ) ;
V_2 -> V_41 = F_3 ( V_35 -> V_41 ) ;
V_2 -> V_42 = F_3 ( V_35 -> V_42 ) ;
V_2 -> V_43 = F_3 ( V_35 -> V_43 ) ;
V_2 -> V_44 = F_3 ( V_35 -> V_44 ) ;
V_2 -> V_45 = F_3 ( V_35 -> V_45 ) ;
V_2 -> V_46 = F_3 ( V_35 -> V_46 ) ;
if ( V_2 -> V_47 == V_48 )
return 0 ;
memset ( V_37 , 0x00 , sizeof( struct V_36 ) ) ;
V_37 -> V_49 = V_50 | V_51 ;
V_37 -> V_19 = V_52 ;
if ( V_2 -> V_47 == V_53 ) {
V_37 -> V_54 . V_55 = abs ( V_2 -> V_45 -
V_2 -> V_56 ) ;
V_37 -> V_57 . V_55 = abs ( V_2 -> V_58 ) ;
} else if ( V_2 -> V_47 == V_59 ) {
V_37 -> V_54 . V_55 = abs ( V_2 -> V_58 ) ;
V_37 -> V_57 . V_55 = abs ( V_2 -> V_45 +
V_2 -> V_56 ) ;
}
V_37 -> V_54 . V_60 = 1 ;
V_37 -> V_57 . V_60 = 1 ;
V_2 -> V_47 = V_48 ;
F_9 ( V_2 , V_61 ,
0 , 0 , V_37 , false ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_62 )
{
struct V_63 * V_64 = & V_4 -> V_17 . V_64 ;
T_2 V_65 = F_3 ( V_64 -> V_65 ) ;
T_2 V_66 = F_3 ( V_64 -> V_66 ) ;
T_1 V_67 ;
F_2 ( V_2 -> V_6 , V_68 ,
L_4
L_5 ,
V_65 , V_66 , F_3 ( V_64 -> V_69 ) ) ;
if ( V_66 == V_70 ) {
V_67 = F_11 ( V_64 -> V_71 ) ;
if ( V_62 )
* V_62 = V_67 ;
switch ( V_65 ) {
case V_72 :
F_2 ( V_2 -> V_6 , V_68 ,
L_6 ,
V_67 ) ;
break;
case V_73 :
F_2 ( V_2 -> V_6 , V_68 ,
L_7 ,
V_67 ) ;
break;
case V_74 :
F_2 ( V_2 -> V_6 , V_68 ,
L_8 ,
V_67 ) ;
break;
case V_75 :
F_2 ( V_2 -> V_6 , V_68 ,
L_9 ,
V_67 ) ;
default:
break;
}
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_76 * V_77 )
{
struct V_78 * V_79 =
& V_4 -> V_17 . V_79 ;
if ( V_77 ) {
V_77 -> V_80 = F_13 ( V_79 -> V_80 ) ;
V_77 -> V_81 = F_13 ( V_79 -> V_81 ) ;
V_77 -> V_82 = F_13 ( V_79 -> V_82 ) ;
V_77 -> V_83 = F_13 ( V_79 -> V_83 ) ;
V_77 -> V_84 = F_13 ( V_79 -> V_84 ) ;
V_77 -> V_85 = F_13 ( V_79 -> V_85 ) ;
V_77 -> V_86 = F_13 ( V_79 -> V_86 ) ;
V_77 -> V_87 = F_13 ( V_79 -> V_87 ) ;
V_77 -> V_88 = F_13 ( V_79 -> V_88 ) ;
V_77 -> V_89 = F_13 ( V_79 -> V_89 ) ;
V_77 -> V_90 = F_13 ( V_79 -> V_90 ) ;
V_77 -> V_91 = F_13 ( V_79 -> V_91 ) ;
V_77 -> V_92 [ 0 ] =
F_13 ( V_79 -> V_93 [ 0 ] ) ;
V_77 -> V_92 [ 1 ] =
F_13 ( V_79 -> V_93 [ 1 ] ) ;
V_77 -> V_92 [ 2 ] =
F_13 ( V_79 -> V_93 [ 2 ] ) ;
V_77 -> V_92 [ 3 ] =
F_13 ( V_79 -> V_93 [ 3 ] ) ;
V_77 -> V_94 = F_13 ( V_79 -> V_94 ) ;
V_77 -> V_95 = F_13 ( V_79 -> V_95 ) ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_96 * V_97 = & V_4 -> V_17 . V_98 ;
struct V_99 * V_100 ;
struct V_101 * V_102 ;
T_2 V_103 , V_104 , V_105 ;
T_3 * V_106 ;
T_1 V_107 ;
V_106 = ( ( T_3 * ) V_97 ) + sizeof( struct V_96 ) ;
V_105 = F_3 ( V_4 -> V_108 ) - V_109 - sizeof( * V_97 ) ;
while ( V_105 >= sizeof( * V_102 ) ) {
V_102 = (struct V_101 * ) V_106 ;
V_103 = F_3 ( V_102 -> type ) ;
V_104 = F_3 ( V_102 -> V_110 ) ;
if ( V_105 < ( sizeof( * V_102 ) + V_104 ) )
break;
switch ( V_103 ) {
case V_111 :
V_100 = (struct V_99 * ) V_106 ;
V_2 -> V_112 [ 0 ] =
F_3 ( V_100 -> V_113 ) ;
V_2 -> V_112 [ 1 ] =
F_3 ( V_100 -> V_114 ) ;
for ( V_107 = 0 ;
V_107 <
sizeof( V_100 -> V_115 ) /
sizeof( T_2 ) ; V_107 ++ )
V_2 -> V_112 [ 2 + V_107 ] =
F_3 ( V_100 ->
V_115 [ V_107 ] ) ;
if ( V_2 -> V_6 -> V_116 == V_117 ) {
for ( V_107 = 0 ; V_107 < F_15 ( V_100 ->
V_118 ) ;
V_107 ++ )
V_2 -> V_112 [ 10 + V_107 ] =
F_3 ( V_100 ->
V_118 [ V_107 ] ) ;
}
break;
}
V_106 += ( sizeof( * V_102 ) + V_104 ) ;
V_105 -= ( sizeof( * V_102 ) + V_104 ) ;
}
V_2 -> V_119 = F_16 ( V_2 ) ;
if ( V_2 -> V_119 )
V_2 -> V_120 = 0 ;
else
return F_9 ( V_2 , V_121 ,
V_70 , 0 , NULL , false ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , void * V_62 )
{
int V_122 , V_123 = - 1 , V_124 = - 1 ;
struct V_125 * V_126 ;
struct V_127 * V_128 ;
if ( ! V_62 )
return - 1 ;
V_126 = (struct V_125 * ) ( ( T_3 * ) V_62 ) ;
V_128 = (struct V_127 * )
( ( T_3 * ) V_126 + sizeof( struct V_125 ) ) ;
V_122 = F_3 ( V_126 -> V_122 ) ;
if ( V_122 < sizeof( struct V_127 ) )
return 0 ;
V_123 = V_128 -> V_129 ;
V_124 = V_128 -> V_130 ;
V_122 -= sizeof( struct V_127 ) ;
while ( V_122 >= sizeof( struct V_127 ) ) {
V_128 ++ ;
if ( V_123 < V_128 -> V_129 )
V_123 = V_128 -> V_129 ;
if ( V_124 > V_128 -> V_130 )
V_124 = V_128 -> V_130 ;
V_122 -= sizeof( struct V_127 ) ;
}
V_2 -> V_131 = ( T_3 ) V_124 ;
V_2 -> V_132 = ( T_3 ) V_123 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_133 * V_134 = & V_4 -> V_17 . V_134 ;
struct V_125 * V_126 ;
struct V_127 * V_128 ;
T_2 V_19 = F_3 ( V_134 -> V_19 ) ;
T_2 V_105 ;
V_126 = (struct V_125 * )
( ( T_3 * ) V_134 +
sizeof( struct V_133 ) ) ;
V_128 = (struct V_127 * )
( ( T_3 * ) V_126 +
sizeof( struct V_125 ) ) ;
V_105 = F_3 ( V_4 -> V_108 ) - V_109 - sizeof( * V_134 ) ;
if ( V_105 <
F_3 ( V_126 -> V_122 ) + sizeof( * V_126 ) )
return 0 ;
switch ( V_19 ) {
case V_70 :
if ( V_6 -> V_135 == V_136 )
F_17 ( V_2 , V_126 ) ;
V_2 -> V_137 = ( T_2 ) V_128 -> V_130 ;
break;
case V_138 :
if ( ! F_13 ( V_134 -> V_139 ) )
break;
if ( V_128 -> V_129 == V_128 -> V_130 )
V_2 -> V_137 = ( T_2 ) V_128 -> V_130 ;
break;
default:
F_2 ( V_6 , ERROR ,
L_10 ,
V_19 ) ;
return 0 ;
}
F_2 ( V_6 , V_68 ,
L_11 ,
V_2 -> V_137 , V_2 -> V_132 ,
V_2 -> V_131 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_140 * V_141 = & V_4 -> V_17 . V_141 ;
T_2 V_19 = F_3 ( V_141 -> V_19 ) ;
V_2 -> V_137 = F_3 ( V_141 -> V_142 ) ;
if ( V_19 == V_70 ) {
V_2 -> V_132 = V_141 -> V_123 ;
V_2 -> V_131 = V_141 -> V_124 ;
}
F_2 ( V_2 -> V_6 , V_68 ,
L_12 ,
V_2 -> V_137 , V_2 -> V_132 ,
V_2 -> V_131 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_143 * V_144 = & V_4 -> V_17 . V_144 ;
struct V_145 * V_146 = & V_4 -> V_17 . V_146 ;
struct V_5 * V_6 = V_2 -> V_6 ;
if ( V_6 -> V_147 == V_148 ) {
V_2 -> V_149 = F_3 ( V_144 -> V_150 ) ;
V_2 -> V_151 = F_3 ( V_144 -> V_152 ) ;
F_2 ( V_6 , V_68 ,
L_13
L_14 ,
F_3 ( V_144 -> V_153 ) ,
F_3 ( V_144 -> V_150 ) ,
F_3 ( V_144 -> V_154 ) ,
F_3 ( V_144 -> V_152 ) ) ;
} else {
V_2 -> V_149 = F_3 ( V_146 -> V_155 ) ;
V_2 -> V_151 = F_3 ( V_146 -> V_155 ) ;
F_2 ( V_6 , V_68 ,
L_15 ,
F_3 ( V_146 -> V_19 ) ,
F_3 ( V_146 -> V_155 ) ) ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_156 * V_157 =
& V_4 -> V_17 . V_158 ;
memcpy ( V_2 -> V_159 , V_157 -> V_158 , V_160 ) ;
F_2 ( V_2 -> V_6 , V_68 ,
L_16 , V_2 -> V_159 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_2 -> V_161 = V_4 -> V_17 . V_161 . V_161 ;
V_2 -> V_162 = V_4 -> V_17 . V_161 . V_163 ;
if ( ! V_2 -> V_119 )
V_2 -> V_120 =
F_24 ( V_2 , V_2 -> V_161 ,
V_2 -> V_162 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
V_6 -> V_164 . V_165 ++ ;
if ( ! memcmp ( V_4 -> V_17 . V_166 . V_158 ,
& V_2 -> V_167 . V_168 . V_169 ,
sizeof( V_4 -> V_17 . V_166 . V_158 ) ) )
F_26 ( V_2 , V_170 ,
false ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_26 ( V_2 , V_170 , false ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_171 * V_172 =
& V_4 -> V_17 . V_173 ;
if ( F_3 ( V_172 -> V_19 ) == V_138 ) {
if ( ( F_3 ( V_172 -> V_174 . V_175 ) & V_176 ) ) {
F_2 ( V_2 -> V_6 , V_68 ,
L_17 ) ;
V_2 -> V_177 = true ;
V_2 -> V_178 = false ;
V_2 -> V_179 = true ;
}
}
memset ( V_2 -> V_180 . V_174 . V_172 , 0 ,
sizeof( V_172 -> V_174 . V_172 ) ) ;
V_2 -> V_180 . V_174 . V_181 = V_172 -> V_174 . V_181 ;
memcpy ( V_2 -> V_180 . V_174 . V_172 , V_172 -> V_174 . V_172 ,
F_3 ( V_2 -> V_180 . V_174 . V_181 ) ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_182 * V_183 ;
T_4 V_110 ;
V_183 = & V_4 -> V_17 . V_184 ;
if ( F_3 ( V_183 -> V_19 ) == V_138 ) {
if ( ( F_3 ( V_183 -> V_174 . V_175 ) & V_176 ) ) {
F_2 ( V_2 -> V_6 , V_68 , L_17 ) ;
V_2 -> V_177 = true ;
V_2 -> V_178 = false ;
V_2 -> V_179 = true ;
}
}
if ( V_183 -> V_174 . V_185 != V_186 )
return 0 ;
memset ( V_2 -> V_187 . V_174 . V_188 . V_189 . V_172 , 0 ,
V_190 ) ;
V_2 -> V_187 . V_174 . V_188 . V_189 . V_181 =
V_183 -> V_174 . V_188 . V_189 . V_181 ;
V_110 = V_2 -> V_187 . V_174 . V_188 . V_189 . V_181 ;
memcpy ( V_2 -> V_187 . V_174 . V_188 . V_189 . V_172 ,
V_183 -> V_174 . V_188 . V_189 . V_172 , F_3 ( V_110 ) ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_2 -> V_6 -> V_191 == V_192 )
return F_29 ( V_2 , V_4 ) ;
else
return F_28 ( V_2 , V_4 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_193 * V_194 =
& V_4 -> V_17 . V_195 ;
struct V_196 * V_197 = & V_194 -> V_197 ;
T_2 V_19 = F_3 ( V_194 -> V_19 ) ;
T_3 V_198 ;
V_198 = ( T_3 ) ( ( F_3 ( V_197 -> V_199 . V_110 )
- V_200 )
/ sizeof( struct V_201 ) ) ;
F_2 ( V_2 -> V_6 , V_68 ,
L_18 ,
V_198 ) ;
if ( V_198 > V_202 ) {
F_2 ( V_2 -> V_6 , V_203 ,
L_19 ,
V_198 ) ;
return - 1 ;
}
switch ( V_19 ) {
case V_138 :
break;
case V_70 :
break;
default:
F_2 ( V_2 -> V_6 , ERROR ,
L_20 , V_194 -> V_19 ) ;
return - 1 ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_204 * V_205 )
{
struct V_204 * V_206 = & V_4 -> V_17 . V_207 ;
if ( V_205 ) {
V_205 -> V_208 = V_206 -> V_208 ;
memcpy ( V_205 -> V_209 , V_206 -> V_209 ,
sizeof( char ) * 128 ) ;
memcpy ( V_2 -> V_209 , V_206 -> V_209 , 128 ) ;
}
return 0 ;
}
static int
F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_210 * V_211 )
{
struct V_210 * V_212 = & V_4 -> V_17 . V_211 ;
if ( V_211 )
memcpy ( V_211 , V_212 , sizeof( * V_211 ) ) ;
return 0 ;
}
static int
F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_62 )
{
struct V_213 * V_214 = & V_4 -> V_17 . V_214 ;
if ( V_62 )
F_35 ( F_3 ( V_214 -> V_139 ) , V_62 ) ;
return 0 ;
}
static int
F_36 ( struct V_1 * V_2 ,
struct V_3 * V_4 , void * V_215 )
{
struct V_216 * V_217 = ( void * ) & V_4 -> V_17 . V_217 ;
V_2 -> V_218 . V_219 = F_13 ( V_217 -> V_219 ) ;
V_2 -> V_218 . V_71 = F_13 ( V_217 -> V_71 ) ;
return 0 ;
}
static int F_37 ( T_2 type , struct V_3 * V_4 ,
void * V_62 )
{
struct V_220 * V_221 ;
struct V_222 * V_223 ;
union T_5 {
struct V_224 * V_225 ;
struct V_226 * V_227 ;
struct V_228 * V_229 ;
struct V_230 * V_231 ;
struct V_232 * V_223 ;
} V_233 ;
if ( ! V_62 )
return 0 ;
V_221 = V_62 ;
V_223 = V_62 ;
switch ( type ) {
case V_234 :
V_233 . V_225 = & V_4 -> V_17 . V_235 ;
V_221 -> V_236 = ( T_1 ) F_3 ( V_233 . V_225 -> V_236 ) ;
V_221 -> V_71 = F_13 ( V_233 . V_225 -> V_71 ) ;
break;
case V_237 :
V_233 . V_227 = & V_4 -> V_17 . V_238 ;
V_221 -> V_236 = ( T_1 ) F_3 ( V_233 . V_227 -> V_236 ) ;
V_221 -> V_71 = ( T_1 ) V_233 . V_227 -> V_71 ;
break;
case V_239 :
V_233 . V_229 = & V_4 -> V_17 . V_240 ;
V_221 -> V_236 = ( T_1 ) F_3 ( V_233 . V_229 -> V_236 ) ;
V_221 -> V_71 = ( T_1 ) V_233 . V_227 -> V_71 ;
break;
case V_241 :
V_233 . V_231 = & V_4 -> V_17 . V_242 ;
V_221 -> V_236 = ( T_1 ) F_3 ( V_233 . V_231 -> V_236 ) ;
V_221 -> V_71 = ( T_1 ) V_233 . V_231 -> V_71 ;
break;
case V_243 :
V_233 . V_229 = & V_4 -> V_17 . V_240 ;
V_221 -> V_236 = ( T_1 ) F_3 ( V_233 . V_229 -> V_236 ) ;
V_221 -> V_71 = ( T_1 ) V_233 . V_229 -> V_71 ;
break;
case V_244 :
V_233 . V_223 = & V_4 -> V_17 . V_223 ;
F_38 ( L_21 ,
F_3 ( V_233 . V_223 -> V_245 ) ) ;
if ( V_223 -> V_245 < F_3 ( V_233 . V_223 -> V_245 ) ) {
V_223 -> V_245 = 0 ;
F_38 ( L_22 ) ;
return - 1 ;
}
V_223 -> V_236 = F_3 ( V_233 . V_223 -> V_236 ) ;
V_223 -> V_245 = F_3 ( V_233 . V_223 -> V_245 ) ;
if ( V_223 -> V_245 > 0 )
memcpy ( & V_223 -> V_71 , & V_233 . V_223 -> V_71 ,
F_39 ( ( T_2 ) V_246 , V_223 -> V_245 ) ) ;
break;
default:
return - 1 ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_247 * V_248 =
& ( V_4 -> V_17 . V_249 ) ;
if ( F_3 ( V_248 -> V_19 ) == V_138 )
return 0 ;
F_2 ( V_2 -> V_6 , V_68 ,
L_23 , V_248 -> V_250 ) ;
if ( F_41 ( V_248 -> V_250 ) ) {
F_2 ( V_2 -> V_6 , V_203 , L_24 ) ;
return 0 ;
}
if ( ! F_42 ( V_2 -> V_167 . V_168 . V_169 , V_248 -> V_250 ) ) {
memcpy ( V_2 -> V_167 . V_168 . V_169 ,
V_248 -> V_250 , V_160 ) ;
V_2 -> V_167 . V_168 . V_251
= F_3 ( V_248 -> V_252 ) ;
V_2 -> V_167 . V_168 . V_253 =
( T_3 ) F_3 ( V_248 -> V_254 ) ;
V_2 -> V_255 = V_256 ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_257 * V_258 = & V_4 -> V_17 . V_259 ;
T_2 V_260 = F_3 ( V_258 -> V_260 ) ;
T_2 V_19 = F_3 ( V_258 -> V_261 ) ;
struct V_262 * V_263 =
F_44 ( V_2 , V_258 -> V_264 ) ;
switch ( V_19 ) {
case V_265 :
if ( V_260 ) {
if ( ! V_263 || V_260 == V_266 )
F_2 ( V_2 -> V_6 , V_33 ,
L_25 ,
V_258 -> V_264 , V_260 ) ;
else
F_2 ( V_2 -> V_6 , ERROR ,
L_25 ,
V_258 -> V_264 , V_260 ) ;
} else {
F_2 ( V_2 -> V_6 , V_33 ,
L_26 ,
V_258 -> V_264 ) ;
}
break;
case V_267 :
if ( V_260 ) {
F_2 ( V_2 -> V_6 , ERROR ,
L_27 ,
V_258 -> V_264 , V_260 ) ;
if ( V_263 && V_260 != V_268 )
V_263 -> V_269 = V_270 ;
} else {
F_2 ( V_2 -> V_6 , V_33 ,
L_28 ,
V_258 -> V_264 ) ;
}
break;
case V_271 :
if ( V_260 ) {
F_2 ( V_2 -> V_6 , ERROR ,
L_29 ,
V_258 -> V_264 , V_260 ) ;
if ( V_263 )
V_263 -> V_269 = V_270 ;
} else {
F_2 ( V_2 -> V_6 , V_33 ,
L_30 ,
V_258 -> V_264 ) ;
}
break;
default:
F_2 ( V_2 -> V_6 , ERROR ,
L_31 , V_19 ) ;
return - 1 ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_272 * V_273 =
& V_4 -> V_17 . V_37 ;
F_2 ( V_2 -> V_6 , V_274 ,
L_32 ,
F_3 ( V_273 -> V_49 ) ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_275 * V_276 =
& V_4 -> V_17 . V_276 ;
struct V_277 * V_278 = ( void * ) & V_276 -> V_103 ;
int V_107 ;
struct V_262 * V_279 ;
for ( V_107 = 0 ; V_107 < ( F_3 ( V_276 -> V_280 ) ) ; V_107 ++ ) {
V_279 = F_44 ( V_2 , V_278 -> V_225 ) ;
if ( F_47 ( ! V_279 ) )
continue;
V_279 -> V_77 . V_281 = V_278 -> V_281 ;
V_278 ++ ;
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_11 != V_282 ) {
F_2 ( V_2 -> V_6 , ERROR , L_33 ) ;
return - 1 ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_283 * V_284 =
& V_4 -> V_17 . V_285 ;
V_6 -> V_286 = V_284 -> V_287 ;
V_6 -> V_288 = F_3 ( V_284 -> V_289 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
bool * V_290 )
{
struct V_291 * V_292 = & V_4 -> V_17 . V_292 ;
struct V_293 * V_294 ;
T_2 V_19 = F_3 ( V_292 -> V_19 ) ;
T_1 V_139 ;
V_294 = (struct V_293
* ) ( ( T_3 * ) V_292 + sizeof( struct V_291 ) ) ;
if ( V_19 == V_70 ) {
V_139 = F_13 ( V_294 -> V_139 ) ;
if ( V_139 == V_295 )
* V_290 = true ;
else
* V_290 = false ;
}
return 0 ;
}
static struct V_296 *
F_51 ( struct V_1 * V_2 ,
T_3 * V_297 , T_2 V_298 )
{
T_2 V_299 = V_298 / 2 ;
struct V_296 * V_300 ;
struct V_301 * V_302 ;
bool V_303 ;
int V_304 , V_305 , V_306 , V_307 = 0 ;
T_1 V_308 , V_309 = 0 ;
T_3 V_310 , V_311 = 0 , V_312 = 0 ;
if ( F_52 ( V_299 > V_313 ) )
return F_53 ( - V_314 ) ;
V_304 = sizeof( struct V_296 ) +
V_299 * sizeof( struct V_301 ) ;
V_300 = F_54 ( V_304 , V_315 ) ;
if ( ! V_300 )
return F_53 ( - V_316 ) ;
for ( V_305 = 0 ; V_305 < V_299 ; V_305 ++ ) {
T_3 V_317 ;
enum V_318 V_319 ;
V_317 = * V_297 ++ ;
if ( ! V_317 ) {
F_55 ( V_300 ) ;
return NULL ;
}
V_310 = * V_297 ++ ;
V_319 = ( V_317 <= 14 ) ? V_320 : V_321 ;
V_306 = F_56 ( V_317 , V_319 ) ;
V_303 = false ;
if ( V_310 & V_322 )
continue;
if ( V_319 == V_321 ) {
if ( ! ( V_310 & V_323 ) )
V_308 = F_57 ( 80 ) ;
else if ( ! ( V_310 & V_324 ) )
V_308 = F_57 ( 40 ) ;
else
V_308 = F_57 ( 20 ) ;
} else {
if ( ! ( V_310 & V_324 ) )
V_308 = F_57 ( 40 ) ;
else
V_308 = F_57 ( 20 ) ;
}
if ( V_305 == 0 || V_311 != V_310 || V_309 != V_308 ||
V_306 - V_307 > 20 ) {
V_312 ++ ;
V_303 = true ;
}
V_302 = & V_300 -> V_325 [ V_312 - 1 ] ;
V_302 -> V_326 . V_327 = F_57 ( V_306 + 10 ) ;
V_311 = V_310 ;
V_307 = V_306 ;
V_309 = V_308 ;
if ( ! V_303 )
continue;
V_302 -> V_326 . V_328 = F_57 ( V_306 - 10 ) ;
V_302 -> V_329 . V_330 = F_58 ( 19 ) ;
if ( V_310 & V_331 )
V_302 -> V_9 = V_332 ;
if ( V_310 & V_333 )
V_302 -> V_9 = V_334 ;
V_302 -> V_326 . V_335 = V_308 ;
}
V_300 -> V_336 = V_312 ;
V_300 -> V_337 [ 0 ] = '9' ;
V_300 -> V_337 [ 1 ] = '9' ;
return V_300 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_338 * T_5 = & V_4 -> V_17 . V_339 ;
T_2 V_19 = F_3 ( T_5 -> V_19 ) ;
T_2 V_103 , V_104 , V_105 ;
struct V_101 * V_102 ;
struct V_296 * V_300 ;
T_3 * V_106 ;
if ( V_19 != V_70 )
return 0 ;
V_106 = ( T_3 * ) T_5 + sizeof( * T_5 ) ;
V_105 = F_3 ( V_4 -> V_108 ) - V_109 - sizeof( * T_5 ) ;
while ( V_105 >= sizeof( * V_102 ) ) {
V_102 = (struct V_101 * ) V_106 ;
V_103 = F_3 ( V_102 -> type ) ;
V_104 = F_3 ( V_102 -> V_110 ) ;
if ( V_105 < ( sizeof( * V_102 ) + V_104 ) )
break;
switch ( V_103 ) {
case V_340 :
F_60 ( V_2 -> V_6 , V_341 , L_34 ,
( T_3 * ) V_102 + sizeof( * V_102 ) ,
V_104 ) ;
V_300 = F_51 ( V_2 ,
( T_3 * ) V_102 + sizeof( * V_102 ) , V_104 ) ;
if ( ! F_61 ( V_300 ) )
V_2 -> V_6 -> V_300 = V_300 ;
break;
}
V_106 += ( sizeof( * V_102 ) + V_104 ) ;
V_105 -= ( sizeof( * V_102 ) + V_104 ) ;
}
return 0 ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_342 * V_343 =
& V_4 -> V_17 . V_343 ;
struct V_5 * V_6 = V_2 -> V_6 ;
V_6 -> V_344 . V_287 = F_3 ( V_343 -> V_287 ) ;
if ( V_6 -> V_344 . V_287 )
V_6 -> V_345 = V_346 ;
V_6 -> V_344 . V_139 = V_347 ;
V_6 -> V_344 . V_348 =
F_3 ( V_343 -> V_348 ) ;
V_6 -> V_344 . V_349 =
F_3 ( V_343 -> V_349 ) ;
V_6 -> V_344 . V_350 =
F_3 ( V_343 -> V_350 ) ;
return 0 ;
}
int F_63 ( struct V_1 * V_2 , T_2 V_351 ,
struct V_3 * V_4 )
{
int V_352 = 0 ;
struct V_5 * V_6 = V_2 -> V_6 ;
void * V_62 = V_6 -> V_12 -> V_62 ;
if ( V_4 -> V_11 != V_282 ) {
F_1 ( V_2 , V_4 ) ;
return - 1 ;
}
switch ( V_351 ) {
case V_353 :
V_352 = F_64 ( V_2 , V_4 ) ;
break;
case V_354 :
V_352 = F_48 ( V_2 , V_4 ) ;
break;
case V_31 :
break;
case V_355 :
V_352 = F_21 ( V_2 , V_4 ) ;
break;
case V_356 :
V_352 = F_22 ( V_2 , V_4 ) ;
break;
case V_357 :
V_352 = F_14 ( V_2 , V_4 ) ;
break;
case V_27 :
V_352 = F_65 ( V_2 , V_4 ) ;
V_6 -> V_12 -> V_13 = false ;
break;
case V_28 :
V_352 = F_66 ( V_2 , V_4 ) ;
V_6 -> V_12 -> V_13 = false ;
break;
case V_358 :
V_352 = F_65 ( V_2 , V_4 ) ;
F_67 ( V_2 -> V_359 . V_360 , 0 ) ;
F_2 ( V_6 , V_361 ,
L_35 ) ;
break;
case V_362 :
break;
case V_363 :
V_352 = F_18 ( V_2 , V_4 ) ;
break;
case V_364 :
V_352 = F_19 ( V_2 , V_4 ) ;
break;
case V_365 :
V_352 = F_20 ( V_2 , V_4 ) ;
break;
case V_16 :
V_352 = F_68 ( V_2 , V_4 , V_62 ) ;
break;
case V_366 :
V_352 = F_69 ( V_2 , V_4 ) ;
break;
case V_367 :
V_352 = F_70 ( V_2 , V_4 ) ;
break;
case V_368 :
V_352 = F_25 ( V_2 , V_4 ) ;
break;
case V_369 :
case V_370 :
V_352 = F_71 ( V_2 , V_4 ) ;
break;
case V_371 :
V_352 = F_27 ( V_2 , V_4 ) ;
break;
case V_372 :
V_352 = F_12 ( V_2 , V_4 , V_62 ) ;
break;
case V_373 :
V_352 = F_8 ( V_2 , V_4 ) ;
break;
case V_374 :
V_352 = F_10 ( V_2 , V_4 , V_62 ) ;
break;
case V_121 :
V_352 = F_23 ( V_2 , V_4 ) ;
break;
case V_375 :
V_352 = F_32 ( V_2 , V_4 , V_62 ) ;
break;
case V_376 :
V_352 = F_33 ( V_2 , V_4 , V_62 ) ;
break;
case V_377 :
break;
case V_378 :
V_352 = F_62 ( V_2 , V_4 ) ;
break;
case V_379 :
V_352 = F_34 ( V_2 , V_4 , V_62 ) ;
break;
case V_380 :
case V_381 :
case V_382 :
break;
case V_383 :
V_352 = F_30 ( V_2 , V_4 ) ;
break;
case V_384 :
V_352 = F_31 ( V_2 , V_4 ) ;
break;
case V_385 :
V_352 = F_72 ( V_2 , V_4 ) ;
break;
case V_386 :
V_352 = F_73 ( V_2 , V_4 ) ;
break;
case V_387 :
V_352 = F_74 ( V_2 , V_4 ) ;
break;
case V_388 :
if ( 0xffff == ( T_2 ) F_3 ( V_4 -> V_17 . V_389 . V_390 ) ) {
if ( V_6 -> V_391 == V_392 &&
V_6 -> V_393 ) {
if ( V_6 -> V_394 . V_395 )
V_6 -> V_394 .
V_395 ( V_6 ) ;
V_6 -> V_393 = false ;
V_6 -> V_396 = false ;
}
break;
}
V_6 -> V_397 = ( T_2 ) F_3 ( V_4 -> V_17 .
V_389 . V_390 ) ;
V_6 -> V_397 = ( V_6 -> V_397
/ V_398 )
* V_398 ;
V_6 -> V_399 = V_6 -> V_397 ;
F_2 ( V_6 , V_361 , L_36 ,
V_6 -> V_399 ) ;
if ( V_6 -> V_394 . V_400 )
V_6 -> V_394 . V_400 ( V_6 ,
F_3 ( V_4 -> V_17 . V_389 . V_401 ) ) ;
break;
case V_402 :
break;
case V_403 :
V_352 = F_75 ( V_2 , V_4 ) ;
break;
case V_404 :
V_352 = F_40 ( V_2 , V_4 ) ;
break;
case V_405 :
V_352 = F_36 ( V_2 , V_4 , V_62 ) ;
break;
case V_234 :
case V_237 :
case V_239 :
case V_241 :
case V_243 :
case V_244 :
V_352 = F_37 ( V_351 , V_4 , V_62 ) ;
break;
case V_406 :
break;
case V_407 :
break;
case V_408 :
break;
case V_61 :
V_352 = F_45 ( V_2 , V_4 ) ;
break;
case V_409 :
break;
case V_410 :
V_352 = F_46 ( V_2 , V_4 ) ;
break;
case V_411 :
V_6 -> V_396 = false ;
V_6 -> V_412 = false ;
V_6 -> V_413 = false ;
V_2 -> V_414 = 1 ;
break;
case V_415 :
V_2 -> V_414 = 0 ;
break;
case V_416 :
break;
case V_417 :
break;
case V_418 :
break;
case V_419 :
break;
case V_420 :
V_352 = F_43 ( V_2 , V_4 ) ;
case V_421 :
break;
case V_422 :
break;
case V_32 :
V_352 = F_49 ( V_2 , V_4 ) ;
break;
case V_423 :
V_352 = F_76 ( V_2 , V_4 , V_62 ) ;
break;
case V_424 :
break;
case V_425 :
V_352 = F_50 ( V_2 , V_4 , V_62 ) ;
break;
case V_426 :
break;
case V_427 :
V_352 = F_59 ( V_2 , V_4 ) ;
break;
default:
F_2 ( V_6 , ERROR ,
L_37 ,
V_4 -> V_10 ) ;
break;
}
return V_352 ;
}
