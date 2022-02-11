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
V_67 = F_3 ( * ( ( V_71 * ) ( V_64 -> V_72 ) ) ) ;
if ( V_62 )
* V_62 = V_67 ;
switch ( V_65 ) {
case V_73 :
F_2 ( V_2 -> V_6 , V_68 ,
L_6 ,
V_67 ) ;
break;
case V_74 :
F_2 ( V_2 -> V_6 , V_68 ,
L_7 ,
V_67 ) ;
break;
case V_75 :
F_2 ( V_2 -> V_6 , V_68 ,
L_8 ,
V_67 ) ;
break;
case V_76 :
F_2 ( V_2 -> V_6 , V_68 ,
L_9 ,
V_67 ) ;
default:
break;
}
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_77 * V_78 )
{
struct V_79 * V_80 =
& V_4 -> V_17 . V_80 ;
if ( V_78 ) {
V_78 -> V_81 = F_12 ( V_80 -> V_81 ) ;
V_78 -> V_82 = F_12 ( V_80 -> V_82 ) ;
V_78 -> V_83 = F_12 ( V_80 -> V_83 ) ;
V_78 -> V_84 = F_12 ( V_80 -> V_84 ) ;
V_78 -> V_85 = F_12 ( V_80 -> V_85 ) ;
V_78 -> V_86 = F_12 ( V_80 -> V_86 ) ;
V_78 -> V_87 = F_12 ( V_80 -> V_87 ) ;
V_78 -> V_88 = F_12 ( V_80 -> V_88 ) ;
V_78 -> V_89 = F_12 ( V_80 -> V_89 ) ;
V_78 -> V_90 = F_12 ( V_80 -> V_90 ) ;
V_78 -> V_91 = F_12 ( V_80 -> V_91 ) ;
V_78 -> V_92 = F_12 ( V_80 -> V_92 ) ;
V_78 -> V_93 [ 0 ] =
F_12 ( V_80 -> V_94 [ 0 ] ) ;
V_78 -> V_93 [ 1 ] =
F_12 ( V_80 -> V_94 [ 1 ] ) ;
V_78 -> V_93 [ 2 ] =
F_12 ( V_80 -> V_94 [ 2 ] ) ;
V_78 -> V_93 [ 3 ] =
F_12 ( V_80 -> V_94 [ 3 ] ) ;
V_78 -> V_95 = F_12 ( V_80 -> V_95 ) ;
V_78 -> V_96 = F_12 ( V_80 -> V_96 ) ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_97 * V_98 = & V_4 -> V_17 . V_99 ;
struct V_100 * V_101 ;
struct V_102 * V_103 ;
T_2 V_104 , V_105 , V_106 ;
T_3 * V_107 ;
T_1 V_108 ;
V_107 = ( ( T_3 * ) V_98 ) + sizeof( struct V_97 ) ;
V_106 = F_3 ( V_4 -> V_109 ) - V_110 - sizeof( * V_98 ) ;
while ( V_106 >= sizeof( * V_103 ) ) {
V_103 = (struct V_102 * ) V_107 ;
V_104 = F_3 ( V_103 -> type ) ;
V_105 = F_3 ( V_103 -> V_111 ) ;
if ( V_106 < ( sizeof( * V_103 ) + V_105 ) )
break;
switch ( V_104 ) {
case V_112 :
V_101 = (struct V_100 * ) V_107 ;
V_2 -> V_113 [ 0 ] =
F_3 ( V_101 -> V_114 ) ;
V_2 -> V_113 [ 1 ] =
F_3 ( V_101 -> V_115 ) ;
for ( V_108 = 0 ;
V_108 <
sizeof( V_101 -> V_116 ) /
sizeof( T_2 ) ; V_108 ++ )
V_2 -> V_113 [ 2 + V_108 ] =
F_3 ( V_101 ->
V_116 [ V_108 ] ) ;
if ( V_2 -> V_6 -> V_117 == V_118 ) {
for ( V_108 = 0 ; V_108 < F_14 ( V_101 ->
V_119 ) ;
V_108 ++ )
V_2 -> V_113 [ 10 + V_108 ] =
F_3 ( V_101 ->
V_119 [ V_108 ] ) ;
}
break;
}
V_107 += ( sizeof( * V_103 ) + V_105 ) ;
V_106 -= ( sizeof( * V_103 ) + V_105 ) ;
}
V_2 -> V_120 = F_15 ( V_2 ) ;
if ( V_2 -> V_120 )
V_2 -> V_121 = 0 ;
else
return F_9 ( V_2 , V_122 ,
V_70 , 0 , NULL , false ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , void * V_62 )
{
int V_123 , V_124 = - 1 , V_125 = - 1 ;
struct V_126 * V_127 ;
struct V_128 * V_129 ;
if ( ! V_62 )
return - 1 ;
V_127 = (struct V_126 * ) ( ( T_3 * ) V_62 ) ;
V_129 = (struct V_128 * )
( ( T_3 * ) V_127 + sizeof( struct V_126 ) ) ;
V_123 = F_3 ( V_127 -> V_123 ) ;
if ( V_123 < sizeof( struct V_128 ) )
return 0 ;
V_124 = V_129 -> V_130 ;
V_125 = V_129 -> V_131 ;
V_123 -= sizeof( struct V_128 ) ;
while ( V_123 >= sizeof( struct V_128 ) ) {
V_129 ++ ;
if ( V_124 < V_129 -> V_130 )
V_124 = V_129 -> V_130 ;
if ( V_125 > V_129 -> V_131 )
V_125 = V_129 -> V_131 ;
V_123 -= sizeof( struct V_128 ) ;
}
V_2 -> V_132 = ( T_3 ) V_125 ;
V_2 -> V_133 = ( T_3 ) V_124 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_134 * V_135 = & V_4 -> V_17 . V_135 ;
struct V_126 * V_127 ;
struct V_128 * V_129 ;
T_2 V_19 = F_3 ( V_135 -> V_19 ) ;
T_2 V_106 ;
V_127 = (struct V_126 * )
( ( T_3 * ) V_135 +
sizeof( struct V_134 ) ) ;
V_129 = (struct V_128 * )
( ( T_3 * ) V_127 +
sizeof( struct V_126 ) ) ;
V_106 = F_3 ( V_4 -> V_109 ) - V_110 - sizeof( * V_135 ) ;
if ( V_106 <
F_3 ( V_127 -> V_123 ) + sizeof( * V_127 ) )
return 0 ;
switch ( V_19 ) {
case V_70 :
if ( V_6 -> V_136 == V_137 )
F_16 ( V_2 , V_127 ) ;
V_2 -> V_138 = ( T_2 ) V_129 -> V_131 ;
break;
case V_139 :
if ( ! F_12 ( V_135 -> V_140 ) )
break;
if ( V_129 -> V_130 == V_129 -> V_131 )
V_2 -> V_138 = ( T_2 ) V_129 -> V_131 ;
break;
default:
F_2 ( V_6 , ERROR ,
L_10 ,
V_19 ) ;
return 0 ;
}
F_2 ( V_6 , V_68 ,
L_11 ,
V_2 -> V_138 , V_2 -> V_133 ,
V_2 -> V_132 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_141 * V_142 = & V_4 -> V_17 . V_142 ;
T_2 V_19 = F_3 ( V_142 -> V_19 ) ;
V_2 -> V_138 = F_3 ( V_142 -> V_143 ) ;
if ( V_19 == V_70 ) {
V_2 -> V_133 = V_142 -> V_124 ;
V_2 -> V_132 = V_142 -> V_125 ;
}
F_2 ( V_2 -> V_6 , V_68 ,
L_12 ,
V_2 -> V_138 , V_2 -> V_133 ,
V_2 -> V_132 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_144 * V_145 = & V_4 -> V_17 . V_145 ;
struct V_146 * V_147 = & V_4 -> V_17 . V_147 ;
struct V_5 * V_6 = V_2 -> V_6 ;
if ( V_6 -> V_148 == V_149 ) {
V_2 -> V_150 = F_3 ( V_145 -> V_151 ) ;
V_2 -> V_152 = F_3 ( V_145 -> V_153 ) ;
F_2 ( V_6 , V_68 ,
L_13
L_14 ,
F_3 ( V_145 -> V_154 ) ,
F_3 ( V_145 -> V_151 ) ,
F_3 ( V_145 -> V_155 ) ,
F_3 ( V_145 -> V_153 ) ) ;
} else {
V_2 -> V_150 = F_3 ( V_147 -> V_156 ) ;
V_2 -> V_152 = F_3 ( V_147 -> V_156 ) ;
F_2 ( V_6 , V_68 ,
L_15 ,
F_3 ( V_147 -> V_19 ) ,
F_3 ( V_147 -> V_156 ) ) ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_157 * V_158 =
& V_4 -> V_17 . V_159 ;
memcpy ( V_2 -> V_160 , V_158 -> V_159 , V_161 ) ;
F_2 ( V_2 -> V_6 , V_68 ,
L_16 , V_2 -> V_160 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_2 -> V_162 = V_4 -> V_17 . V_162 . V_162 ;
V_2 -> V_163 = V_4 -> V_17 . V_162 . V_164 ;
if ( ! V_2 -> V_120 )
V_2 -> V_121 =
F_23 ( V_2 , V_2 -> V_162 ,
V_2 -> V_163 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
V_6 -> V_165 . V_166 ++ ;
if ( ! memcmp ( V_4 -> V_17 . V_167 . V_159 ,
& V_2 -> V_168 . V_169 . V_170 ,
sizeof( V_4 -> V_17 . V_167 . V_159 ) ) )
F_25 ( V_2 , V_171 ,
false ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_25 ( V_2 , V_171 , false ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_172 * V_173 =
& V_4 -> V_17 . V_174 ;
if ( F_3 ( V_173 -> V_19 ) == V_139 ) {
if ( ( F_3 ( V_173 -> V_175 . V_176 ) & V_177 ) ) {
F_2 ( V_2 -> V_6 , V_68 ,
L_17 ) ;
V_2 -> V_178 = true ;
V_2 -> V_179 = false ;
V_2 -> V_180 = true ;
}
}
memset ( V_2 -> V_181 . V_175 . V_173 , 0 ,
sizeof( V_173 -> V_175 . V_173 ) ) ;
V_2 -> V_181 . V_175 . V_182 = V_173 -> V_175 . V_182 ;
memcpy ( V_2 -> V_181 . V_175 . V_173 , V_173 -> V_175 . V_173 ,
F_3 ( V_2 -> V_181 . V_175 . V_182 ) ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_183 * V_184 ;
V_71 V_111 ;
V_184 = & V_4 -> V_17 . V_185 ;
if ( F_3 ( V_184 -> V_19 ) == V_139 ) {
if ( ( F_3 ( V_184 -> V_175 . V_176 ) & V_177 ) ) {
F_2 ( V_2 -> V_6 , V_68 , L_17 ) ;
V_2 -> V_178 = true ;
V_2 -> V_179 = false ;
V_2 -> V_180 = true ;
}
}
if ( V_184 -> V_175 . V_186 != V_187 )
return 0 ;
memset ( V_2 -> V_188 . V_175 . V_189 . V_190 . V_173 , 0 ,
V_191 ) ;
V_2 -> V_188 . V_175 . V_189 . V_190 . V_182 =
V_184 -> V_175 . V_189 . V_190 . V_182 ;
V_111 = V_2 -> V_188 . V_175 . V_189 . V_190 . V_182 ;
memcpy ( V_2 -> V_188 . V_175 . V_189 . V_190 . V_173 ,
V_184 -> V_175 . V_189 . V_190 . V_173 , F_3 ( V_111 ) ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_2 -> V_6 -> V_192 == V_193 )
return F_28 ( V_2 , V_4 ) ;
else
return F_27 ( V_2 , V_4 ) ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_194 * V_195 =
& V_4 -> V_17 . V_196 ;
struct V_197 * V_198 = & V_195 -> V_198 ;
T_2 V_19 = F_3 ( V_195 -> V_19 ) ;
T_3 V_199 ;
V_199 = ( T_3 ) ( ( F_3 ( V_198 -> V_200 . V_111 )
- V_201 )
/ sizeof( struct V_202 ) ) ;
F_2 ( V_2 -> V_6 , V_68 ,
L_18 ,
V_199 ) ;
if ( V_199 > V_203 ) {
F_2 ( V_2 -> V_6 , V_204 ,
L_19 ,
V_199 ) ;
return - 1 ;
}
switch ( V_19 ) {
case V_139 :
break;
case V_70 :
break;
default:
F_2 ( V_2 -> V_6 , ERROR ,
L_20 , V_195 -> V_19 ) ;
return - 1 ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_205 * V_206 )
{
struct V_205 * V_207 = & V_4 -> V_17 . V_208 ;
if ( V_206 ) {
V_206 -> V_209 = V_207 -> V_209 ;
memcpy ( V_206 -> V_210 , V_207 -> V_210 ,
sizeof( char ) * 128 ) ;
memcpy ( V_2 -> V_210 , V_207 -> V_210 , 128 ) ;
}
return 0 ;
}
static int
F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_211 * V_212 )
{
struct V_211 * V_213 = & V_4 -> V_17 . V_212 ;
if ( V_212 )
memcpy ( V_212 , V_213 , sizeof( * V_212 ) ) ;
return 0 ;
}
static int
F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_62 )
{
struct V_214 * V_215 = & V_4 -> V_17 . V_215 ;
if ( V_62 )
* ( ( T_2 * ) V_62 ) = F_3 ( V_215 -> V_140 ) ;
return 0 ;
}
static int
F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 , void * V_216 )
{
struct V_217 * V_218 = ( void * ) & V_4 -> V_17 . V_218 ;
V_2 -> V_219 . V_220 = F_12 ( V_218 -> V_220 ) ;
V_2 -> V_219 . V_72 = F_12 ( V_218 -> V_72 ) ;
return 0 ;
}
static int F_35 ( T_2 type , struct V_3 * V_4 ,
void * V_62 )
{
struct V_221 * V_222 ;
struct V_223 * V_224 ;
union T_4 {
struct V_225 * V_226 ;
struct V_227 * V_228 ;
struct V_229 * V_230 ;
struct V_231 * V_232 ;
struct V_233 * V_224 ;
} V_234 ;
if ( ! V_62 )
return 0 ;
V_222 = V_62 ;
V_224 = V_62 ;
switch ( type ) {
case V_235 :
V_234 . V_226 = & V_4 -> V_17 . V_236 ;
V_222 -> V_237 = ( T_1 ) F_3 ( V_234 . V_226 -> V_237 ) ;
V_222 -> V_72 = F_12 ( V_234 . V_226 -> V_72 ) ;
break;
case V_238 :
V_234 . V_228 = & V_4 -> V_17 . V_239 ;
V_222 -> V_237 = ( T_1 ) F_3 ( V_234 . V_228 -> V_237 ) ;
V_222 -> V_72 = ( T_1 ) V_234 . V_228 -> V_72 ;
break;
case V_240 :
V_234 . V_230 = & V_4 -> V_17 . V_241 ;
V_222 -> V_237 = ( T_1 ) F_3 ( V_234 . V_230 -> V_237 ) ;
V_222 -> V_72 = ( T_1 ) V_234 . V_228 -> V_72 ;
break;
case V_242 :
V_234 . V_232 = & V_4 -> V_17 . V_243 ;
V_222 -> V_237 = ( T_1 ) F_3 ( V_234 . V_232 -> V_237 ) ;
V_222 -> V_72 = ( T_1 ) V_234 . V_232 -> V_72 ;
break;
case V_244 :
V_234 . V_230 = & V_4 -> V_17 . V_241 ;
V_222 -> V_237 = ( T_1 ) F_3 ( V_234 . V_230 -> V_237 ) ;
V_222 -> V_72 = ( T_1 ) V_234 . V_230 -> V_72 ;
break;
case V_245 :
V_234 . V_224 = & V_4 -> V_17 . V_224 ;
F_36 ( L_21 ,
F_3 ( V_234 . V_224 -> V_246 ) ) ;
if ( V_224 -> V_246 < F_3 ( V_234 . V_224 -> V_246 ) ) {
V_224 -> V_246 = 0 ;
F_36 ( L_22 ) ;
return - 1 ;
}
V_224 -> V_237 = F_3 ( V_234 . V_224 -> V_237 ) ;
V_224 -> V_246 = F_3 ( V_234 . V_224 -> V_246 ) ;
if ( V_224 -> V_246 > 0 )
memcpy ( & V_224 -> V_72 , & V_234 . V_224 -> V_72 ,
F_37 ( ( T_2 ) V_247 , V_224 -> V_246 ) ) ;
break;
default:
return - 1 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_248 * V_249 =
& ( V_4 -> V_17 . V_250 ) ;
if ( F_3 ( V_249 -> V_19 ) == V_139 )
return 0 ;
F_2 ( V_2 -> V_6 , V_68 ,
L_23 , V_249 -> V_251 ) ;
if ( F_39 ( V_249 -> V_251 ) ) {
F_2 ( V_2 -> V_6 , V_204 , L_24 ) ;
return 0 ;
}
if ( ! F_40 ( V_2 -> V_168 . V_169 . V_170 , V_249 -> V_251 ) ) {
memcpy ( V_2 -> V_168 . V_169 . V_170 ,
V_249 -> V_251 , V_161 ) ;
V_2 -> V_168 . V_169 . V_252
= F_3 ( V_249 -> V_253 ) ;
V_2 -> V_168 . V_169 . V_254 =
( T_3 ) F_3 ( V_249 -> V_255 ) ;
V_2 -> V_256 = V_257 ;
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_258 * V_259 = & V_4 -> V_17 . V_260 ;
T_2 V_261 = F_3 ( V_259 -> V_261 ) ;
T_2 V_19 = F_3 ( V_259 -> V_262 ) ;
struct V_263 * V_264 =
F_42 ( V_2 , V_259 -> V_265 ) ;
switch ( V_19 ) {
case V_266 :
if ( V_261 ) {
if ( ! V_264 || V_261 == V_267 )
F_2 ( V_2 -> V_6 , V_33 ,
L_25 ,
V_259 -> V_265 , V_261 ) ;
else
F_2 ( V_2 -> V_6 , ERROR ,
L_25 ,
V_259 -> V_265 , V_261 ) ;
} else {
F_2 ( V_2 -> V_6 , V_33 ,
L_26 ,
V_259 -> V_265 ) ;
}
break;
case V_268 :
if ( V_261 ) {
F_2 ( V_2 -> V_6 , ERROR ,
L_27 ,
V_259 -> V_265 , V_261 ) ;
if ( V_264 && V_261 != V_269 )
V_264 -> V_270 = V_271 ;
} else {
F_2 ( V_2 -> V_6 , V_33 ,
L_28 ,
V_259 -> V_265 ) ;
}
break;
case V_272 :
if ( V_261 ) {
F_2 ( V_2 -> V_6 , ERROR ,
L_29 ,
V_259 -> V_265 , V_261 ) ;
if ( V_264 )
V_264 -> V_270 = V_271 ;
} else {
F_2 ( V_2 -> V_6 , V_33 ,
L_30 ,
V_259 -> V_265 ) ;
}
break;
default:
F_2 ( V_2 -> V_6 , ERROR ,
L_31 , V_19 ) ;
return - 1 ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_273 * V_274 =
& V_4 -> V_17 . V_37 ;
F_2 ( V_2 -> V_6 , V_275 ,
L_32 ,
F_3 ( V_274 -> V_49 ) ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_276 * V_277 =
& V_4 -> V_17 . V_277 ;
struct V_278 * V_279 = ( void * ) & V_277 -> V_104 ;
int V_108 ;
struct V_263 * V_280 ;
for ( V_108 = 0 ; V_108 < ( F_3 ( V_277 -> V_281 ) ) ; V_108 ++ ) {
V_280 = F_42 ( V_2 , V_279 -> V_226 ) ;
if ( F_45 ( ! V_280 ) )
continue;
V_280 -> V_78 . V_282 = V_279 -> V_282 ;
V_279 ++ ;
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_11 != V_283 ) {
F_2 ( V_2 -> V_6 , ERROR , L_33 ) ;
return - 1 ;
}
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_284 * V_285 =
& V_4 -> V_17 . V_286 ;
V_6 -> V_287 = V_285 -> V_288 ;
V_6 -> V_289 = F_3 ( V_285 -> V_290 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
bool * V_291 )
{
struct V_292 * V_293 = & V_4 -> V_17 . V_293 ;
struct V_294 * V_295 ;
T_2 V_19 = F_3 ( V_293 -> V_19 ) ;
T_1 V_140 ;
V_295 = (struct V_294
* ) ( ( T_3 * ) V_293 + sizeof( struct V_292 ) ) ;
if ( V_19 == V_70 ) {
V_140 = F_12 ( V_295 -> V_140 ) ;
if ( V_140 == V_296 )
* V_291 = true ;
else
* V_291 = false ;
}
return 0 ;
}
static struct V_297 *
F_49 ( struct V_1 * V_2 ,
T_3 * V_298 , T_2 V_299 )
{
T_2 V_300 = V_299 / 2 ;
struct V_297 * V_301 ;
struct V_302 * V_303 ;
bool V_304 ;
int V_305 , V_306 , V_307 , V_308 = 0 ;
T_1 V_309 , V_310 = 0 ;
T_3 V_311 , V_312 = 0 , V_313 = 0 ;
if ( F_50 ( V_300 > V_314 ) )
return F_51 ( - V_315 ) ;
V_305 = sizeof( struct V_297 ) +
V_300 * sizeof( struct V_302 ) ;
V_301 = F_52 ( V_305 , V_316 ) ;
if ( ! V_301 )
return F_51 ( - V_317 ) ;
for ( V_306 = 0 ; V_306 < V_300 ; V_306 ++ ) {
T_3 V_318 ;
enum V_319 V_320 ;
V_318 = * V_298 ++ ;
if ( ! V_318 ) {
F_53 ( V_301 ) ;
return NULL ;
}
V_311 = * V_298 ++ ;
V_320 = ( V_318 <= 14 ) ? V_321 : V_322 ;
V_307 = F_54 ( V_318 , V_320 ) ;
V_304 = false ;
if ( V_311 & V_323 )
continue;
if ( V_320 == V_322 ) {
if ( ! ( V_311 & V_324 ) )
V_309 = F_55 ( 80 ) ;
else if ( ! ( V_311 & V_325 ) )
V_309 = F_55 ( 40 ) ;
else
V_309 = F_55 ( 20 ) ;
} else {
if ( ! ( V_311 & V_325 ) )
V_309 = F_55 ( 40 ) ;
else
V_309 = F_55 ( 20 ) ;
}
if ( V_306 == 0 || V_312 != V_311 || V_310 != V_309 ||
V_307 - V_308 > 20 ) {
V_313 ++ ;
V_304 = true ;
}
V_303 = & V_301 -> V_326 [ V_313 - 1 ] ;
V_303 -> V_327 . V_328 = F_55 ( V_307 + 10 ) ;
V_312 = V_311 ;
V_308 = V_307 ;
V_310 = V_309 ;
if ( ! V_304 )
continue;
V_303 -> V_327 . V_329 = F_55 ( V_307 - 10 ) ;
V_303 -> V_330 . V_331 = F_56 ( 19 ) ;
if ( V_311 & V_332 )
V_303 -> V_9 = V_333 ;
if ( V_311 & V_334 )
V_303 -> V_9 = V_335 ;
V_303 -> V_327 . V_336 = V_309 ;
}
V_301 -> V_337 = V_313 ;
V_301 -> V_338 [ 0 ] = '9' ;
V_301 -> V_338 [ 1 ] = '9' ;
return V_301 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_339 * T_4 = & V_4 -> V_17 . V_340 ;
T_2 V_19 = F_3 ( T_4 -> V_19 ) ;
T_2 V_104 , V_105 , V_106 ;
struct V_102 * V_103 ;
struct V_297 * V_301 ;
T_3 * V_107 ;
if ( V_19 != V_70 )
return 0 ;
V_107 = ( T_3 * ) T_4 + sizeof( * T_4 ) ;
V_106 = F_3 ( V_4 -> V_109 ) - V_110 - sizeof( * T_4 ) ;
while ( V_106 >= sizeof( * V_103 ) ) {
V_103 = (struct V_102 * ) V_107 ;
V_104 = F_3 ( V_103 -> type ) ;
V_105 = F_3 ( V_103 -> V_111 ) ;
if ( V_106 < ( sizeof( * V_103 ) + V_105 ) )
break;
switch ( V_104 ) {
case V_341 :
F_58 ( V_2 -> V_6 , V_342 , L_34 ,
( T_3 * ) V_103 + sizeof( * V_103 ) ,
V_105 ) ;
V_301 = F_49 ( V_2 ,
( T_3 * ) V_103 + sizeof( * V_103 ) , V_105 ) ;
if ( ! F_59 ( V_301 ) )
V_2 -> V_6 -> V_301 = V_301 ;
break;
}
V_107 += ( sizeof( * V_103 ) + V_105 ) ;
V_106 -= ( sizeof( * V_103 ) + V_105 ) ;
}
return 0 ;
}
int F_60 ( struct V_1 * V_2 , T_2 V_343 ,
struct V_3 * V_4 )
{
int V_344 = 0 ;
struct V_5 * V_6 = V_2 -> V_6 ;
void * V_62 = V_6 -> V_12 -> V_62 ;
if ( V_4 -> V_11 != V_283 ) {
F_1 ( V_2 , V_4 ) ;
return - 1 ;
}
switch ( V_343 ) {
case V_345 :
V_344 = F_61 ( V_2 , V_4 ) ;
break;
case V_346 :
V_344 = F_46 ( V_2 , V_4 ) ;
break;
case V_31 :
break;
case V_347 :
V_344 = F_20 ( V_2 , V_4 ) ;
break;
case V_348 :
V_344 = F_21 ( V_2 , V_4 ) ;
break;
case V_349 :
V_344 = F_13 ( V_2 , V_4 ) ;
break;
case V_27 :
V_344 = F_62 ( V_2 , V_4 ) ;
V_6 -> V_12 -> V_13 = false ;
break;
case V_28 :
V_344 = F_63 ( V_2 , V_4 ) ;
V_6 -> V_12 -> V_13 = false ;
break;
case V_350 :
V_344 = F_62 ( V_2 , V_4 ) ;
F_64 ( V_2 -> V_351 . V_352 ) ;
F_2 ( V_6 , V_353 ,
L_35 ) ;
break;
case V_354 :
break;
case V_355 :
V_344 = F_17 ( V_2 , V_4 ) ;
break;
case V_356 :
V_344 = F_18 ( V_2 , V_4 ) ;
break;
case V_357 :
V_344 = F_19 ( V_2 , V_4 ) ;
break;
case V_16 :
V_344 = F_65 ( V_2 , V_4 , V_62 ) ;
break;
case V_358 :
V_344 = F_66 ( V_2 , V_4 ) ;
break;
case V_359 :
V_344 = F_67 ( V_2 , V_4 ) ;
break;
case V_360 :
V_344 = F_24 ( V_2 , V_4 ) ;
break;
case V_361 :
case V_362 :
V_344 = F_68 ( V_2 , V_4 ) ;
break;
case V_363 :
V_344 = F_26 ( V_2 , V_4 ) ;
break;
case V_364 :
V_344 = F_11 ( V_2 , V_4 , V_62 ) ;
break;
case V_365 :
V_344 = F_8 ( V_2 , V_4 ) ;
break;
case V_366 :
V_344 = F_10 ( V_2 , V_4 , V_62 ) ;
break;
case V_122 :
V_344 = F_22 ( V_2 , V_4 ) ;
break;
case V_367 :
V_344 = F_31 ( V_2 , V_4 , V_62 ) ;
break;
case V_368 :
V_344 = F_32 ( V_2 , V_4 , V_62 ) ;
break;
case V_369 :
break;
case V_370 :
V_344 = F_33 ( V_2 , V_4 , V_62 ) ;
break;
case V_371 :
case V_372 :
case V_373 :
break;
case V_374 :
V_344 = F_29 ( V_2 , V_4 ) ;
break;
case V_375 :
V_344 = F_30 ( V_2 , V_4 ) ;
break;
case V_376 :
V_344 = F_69 ( V_2 , V_4 ) ;
break;
case V_377 :
V_344 = F_70 ( V_2 , V_4 ) ;
break;
case V_378 :
V_344 = F_71 ( V_2 , V_4 ) ;
break;
case V_379 :
if ( 0xffff == ( T_2 ) F_3 ( V_4 -> V_17 . V_380 . V_381 ) ) {
if ( V_6 -> V_382 == V_383 &&
V_6 -> V_384 ) {
if ( V_6 -> V_385 . V_386 )
V_6 -> V_385 .
V_386 ( V_6 ) ;
V_6 -> V_384 = false ;
V_6 -> V_387 = false ;
}
break;
}
V_6 -> V_388 = ( T_2 ) F_3 ( V_4 -> V_17 .
V_380 . V_381 ) ;
V_6 -> V_388 = ( V_6 -> V_388
/ V_389 )
* V_389 ;
V_6 -> V_390 = V_6 -> V_388 ;
F_2 ( V_6 , V_353 , L_36 ,
V_6 -> V_390 ) ;
if ( V_6 -> V_385 . V_391 )
V_6 -> V_385 . V_391 ( V_6 ,
F_3 ( V_4 -> V_17 . V_380 . V_392 ) ) ;
break;
case V_393 :
break;
case V_394 :
V_344 = F_72 ( V_2 , V_4 ) ;
break;
case V_395 :
V_344 = F_38 ( V_2 , V_4 ) ;
break;
case V_396 :
V_344 = F_34 ( V_2 , V_4 , V_62 ) ;
break;
case V_235 :
case V_238 :
case V_240 :
case V_242 :
case V_244 :
case V_245 :
V_344 = F_35 ( V_343 , V_4 , V_62 ) ;
break;
case V_397 :
break;
case V_398 :
break;
case V_399 :
break;
case V_61 :
V_344 = F_43 ( V_2 , V_4 ) ;
break;
case V_400 :
break;
case V_401 :
V_344 = F_44 ( V_2 , V_4 ) ;
break;
case V_402 :
V_6 -> V_387 = false ;
V_6 -> V_403 = false ;
V_6 -> V_404 = false ;
V_2 -> V_405 = 1 ;
break;
case V_406 :
V_2 -> V_405 = 0 ;
break;
case V_407 :
break;
case V_408 :
break;
case V_409 :
break;
case V_410 :
break;
case V_411 :
V_344 = F_41 ( V_2 , V_4 ) ;
case V_412 :
break;
case V_413 :
break;
case V_32 :
V_344 = F_47 ( V_2 , V_4 ) ;
break;
case V_414 :
V_344 = F_73 ( V_2 , V_4 , V_62 ) ;
break;
case V_415 :
break;
case V_416 :
V_344 = F_48 ( V_2 , V_4 , V_62 ) ;
break;
case V_417 :
break;
case V_418 :
V_344 = F_57 ( V_2 , V_4 ) ;
break;
default:
F_2 ( V_6 , ERROR ,
L_37 ,
V_4 -> V_10 ) ;
break;
}
return V_344 ;
}
