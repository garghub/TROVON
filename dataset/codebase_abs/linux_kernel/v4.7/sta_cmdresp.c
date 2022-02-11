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
if ( V_6 -> V_148 == V_149 )
F_2 ( V_6 , V_68 ,
L_13
L_14 ,
F_3 ( V_145 -> V_150 ) ,
F_3 ( V_145 -> V_151 ) ,
F_3 ( V_145 -> V_152 ) ,
F_3 ( V_145 -> V_153 ) ) ;
else
F_2 ( V_6 , V_68 ,
L_15 ,
F_3 ( V_147 -> V_19 ) ,
F_3 ( V_147 -> V_154 ) ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_155 * V_156 =
& V_4 -> V_17 . V_157 ;
memcpy ( V_2 -> V_158 , V_156 -> V_157 , V_159 ) ;
F_2 ( V_2 -> V_6 , V_68 ,
L_16 , V_2 -> V_158 ) ;
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
V_2 -> V_160 = V_4 -> V_17 . V_160 . V_160 ;
V_2 -> V_161 = V_4 -> V_17 . V_160 . V_162 ;
if ( ! V_2 -> V_120 )
V_2 -> V_121 =
F_23 ( V_2 , V_2 -> V_160 ,
V_2 -> V_161 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
V_6 -> V_163 . V_164 ++ ;
if ( ! memcmp ( V_4 -> V_17 . V_165 . V_157 ,
& V_2 -> V_166 . V_167 . V_168 ,
sizeof( V_4 -> V_17 . V_165 . V_157 ) ) )
F_25 ( V_2 , V_169 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_25 ( V_2 , V_169 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_170 * V_171 =
& V_4 -> V_17 . V_172 ;
if ( F_3 ( V_171 -> V_19 ) == V_139 ) {
if ( ( F_3 ( V_171 -> V_173 . V_174 ) & V_175 ) ) {
F_2 ( V_2 -> V_6 , V_68 ,
L_17 ) ;
V_2 -> V_176 = true ;
V_2 -> V_177 = false ;
V_2 -> V_178 = true ;
}
}
memset ( V_2 -> V_179 . V_173 . V_171 , 0 ,
sizeof( V_171 -> V_173 . V_171 ) ) ;
V_2 -> V_179 . V_173 . V_180 = V_171 -> V_173 . V_180 ;
memcpy ( V_2 -> V_179 . V_173 . V_171 , V_171 -> V_173 . V_171 ,
F_3 ( V_2 -> V_179 . V_173 . V_180 ) ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_181 * V_182 ;
V_71 V_111 ;
V_182 = & V_4 -> V_17 . V_183 ;
if ( F_3 ( V_182 -> V_19 ) == V_139 ) {
if ( ( F_3 ( V_182 -> V_173 . V_174 ) & V_175 ) ) {
F_2 ( V_2 -> V_6 , V_68 , L_17 ) ;
V_2 -> V_176 = true ;
V_2 -> V_177 = false ;
V_2 -> V_178 = true ;
}
}
if ( V_182 -> V_173 . V_184 != V_185 )
return 0 ;
memset ( V_2 -> V_186 . V_173 . V_187 . V_188 . V_171 , 0 ,
V_189 ) ;
V_2 -> V_186 . V_173 . V_187 . V_188 . V_180 =
V_182 -> V_173 . V_187 . V_188 . V_180 ;
V_111 = V_2 -> V_186 . V_173 . V_187 . V_188 . V_180 ;
memcpy ( V_2 -> V_186 . V_173 . V_187 . V_188 . V_171 ,
V_182 -> V_173 . V_187 . V_188 . V_171 , F_3 ( V_111 ) ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_2 -> V_6 -> V_190 == V_191 )
return F_28 ( V_2 , V_4 ) ;
else
return F_27 ( V_2 , V_4 ) ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_192 * V_193 =
& V_4 -> V_17 . V_194 ;
struct V_195 * V_196 = & V_193 -> V_196 ;
T_2 V_19 = F_3 ( V_193 -> V_19 ) ;
T_3 V_197 ;
V_197 = ( T_3 ) ( ( F_3 ( V_196 -> V_198 . V_111 )
- V_199 )
/ sizeof( struct V_200 ) ) ;
F_2 ( V_2 -> V_6 , V_68 ,
L_18 ,
V_197 ) ;
if ( V_197 > V_201 ) {
F_2 ( V_2 -> V_6 , V_202 ,
L_19 ,
V_197 ) ;
return - 1 ;
}
switch ( V_19 ) {
case V_139 :
break;
case V_70 :
break;
default:
F_2 ( V_2 -> V_6 , ERROR ,
L_20 , V_193 -> V_19 ) ;
return - 1 ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_203 * V_204 )
{
struct V_203 * V_205 = & V_4 -> V_17 . V_206 ;
if ( V_204 ) {
V_204 -> V_207 = V_205 -> V_207 ;
memcpy ( V_204 -> V_208 , V_205 -> V_208 ,
sizeof( char ) * 128 ) ;
memcpy ( V_2 -> V_208 , V_205 -> V_208 , 128 ) ;
}
return 0 ;
}
static int
F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_209 * V_210 )
{
struct V_209 * V_211 = & V_4 -> V_17 . V_210 ;
if ( V_210 )
memcpy ( V_210 , V_211 , sizeof( * V_210 ) ) ;
return 0 ;
}
static int
F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_62 )
{
struct V_212 * V_213 = & V_4 -> V_17 . V_213 ;
if ( V_62 )
* ( ( T_2 * ) V_62 ) = F_3 ( V_213 -> V_140 ) ;
return 0 ;
}
static int
F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 , void * V_214 )
{
struct V_215 * V_216 = ( void * ) & V_4 -> V_17 . V_216 ;
V_2 -> V_217 . V_218 = F_12 ( V_216 -> V_218 ) ;
V_2 -> V_217 . V_72 = F_12 ( V_216 -> V_72 ) ;
return 0 ;
}
static int F_35 ( T_2 type , struct V_3 * V_4 ,
void * V_62 )
{
struct V_219 * V_220 ;
struct V_221 * V_222 ;
union T_4 {
struct V_223 * V_224 ;
struct V_225 * V_226 ;
struct V_227 * V_228 ;
struct V_229 * V_230 ;
struct V_231 * V_222 ;
} V_232 ;
if ( ! V_62 )
return 0 ;
V_220 = V_62 ;
V_222 = V_62 ;
switch ( type ) {
case V_233 :
V_232 . V_224 = & V_4 -> V_17 . V_234 ;
V_220 -> V_235 = F_36 ( ( T_1 ) F_3 ( V_232 . V_224 -> V_235 ) ) ;
V_220 -> V_72 = V_232 . V_224 -> V_72 ;
break;
case V_236 :
V_232 . V_226 = & V_4 -> V_17 . V_237 ;
V_220 -> V_235 = F_36 ( ( T_1 ) F_3 ( V_232 . V_226 -> V_235 ) ) ;
V_220 -> V_72 = F_36 ( ( T_1 ) V_232 . V_226 -> V_72 ) ;
break;
case V_238 :
V_232 . V_228 = & V_4 -> V_17 . V_239 ;
V_220 -> V_235 = F_36 ( ( T_1 ) F_3 ( V_232 . V_228 -> V_235 ) ) ;
V_220 -> V_72 = F_36 ( ( T_1 ) V_232 . V_226 -> V_72 ) ;
break;
case V_240 :
V_232 . V_230 = & V_4 -> V_17 . V_241 ;
V_220 -> V_235 = F_36 ( ( T_1 ) F_3 ( V_232 . V_230 -> V_235 ) ) ;
V_220 -> V_72 = F_36 ( ( T_1 ) V_232 . V_230 -> V_72 ) ;
break;
case V_242 :
V_232 . V_228 = & V_4 -> V_17 . V_239 ;
V_220 -> V_235 = F_36 ( ( T_1 ) F_3 ( V_232 . V_228 -> V_235 ) ) ;
V_220 -> V_72 = F_36 ( ( T_1 ) V_232 . V_228 -> V_72 ) ;
break;
case V_243 :
V_232 . V_222 = & V_4 -> V_17 . V_222 ;
F_37 ( L_21 , V_232 . V_222 -> V_244 ) ;
if ( F_3 ( V_222 -> V_244 ) <
F_3 ( V_232 . V_222 -> V_244 ) ) {
V_222 -> V_244 = F_38 ( 0 ) ;
F_37 ( L_22 ) ;
return - 1 ;
}
V_222 -> V_235 = V_232 . V_222 -> V_235 ;
V_222 -> V_244 = V_232 . V_222 -> V_244 ;
if ( F_3 ( V_222 -> V_244 ) > 0 )
memcpy ( & V_222 -> V_72 , & V_232 . V_222 -> V_72 ,
F_3 ( V_232 . V_222 -> V_244 ) ) ;
break;
default:
return - 1 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_245 * V_246 =
& ( V_4 -> V_17 . V_247 ) ;
if ( F_3 ( V_246 -> V_19 ) == V_139 )
return 0 ;
F_2 ( V_2 -> V_6 , V_68 ,
L_23 , V_246 -> V_248 ) ;
if ( F_40 ( V_246 -> V_248 ) ) {
F_2 ( V_2 -> V_6 , V_202 , L_24 ) ;
return 0 ;
}
if ( ! F_41 ( V_2 -> V_166 . V_167 . V_168 , V_246 -> V_248 ) ) {
memcpy ( V_2 -> V_166 . V_167 . V_168 ,
V_246 -> V_248 , V_159 ) ;
V_2 -> V_166 . V_167 . V_249
= F_3 ( V_246 -> V_250 ) ;
V_2 -> V_166 . V_167 . V_251 =
( T_3 ) F_3 ( V_246 -> V_252 ) ;
V_2 -> V_253 = V_254 ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_255 * V_256 = & V_4 -> V_17 . V_257 ;
T_2 V_258 = F_3 ( V_256 -> V_258 ) ;
T_2 V_19 = F_3 ( V_256 -> V_259 ) ;
struct V_260 * V_261 =
F_43 ( V_2 , V_256 -> V_262 ) ;
switch ( V_19 ) {
case V_263 :
if ( V_258 ) {
if ( ! V_261 || V_258 == V_264 )
F_2 ( V_2 -> V_6 , V_33 ,
L_25 ,
V_256 -> V_262 , V_258 ) ;
else
F_2 ( V_2 -> V_6 , ERROR ,
L_25 ,
V_256 -> V_262 , V_258 ) ;
} else {
F_2 ( V_2 -> V_6 , V_33 ,
L_26 ,
V_256 -> V_262 ) ;
}
break;
case V_265 :
if ( V_258 ) {
F_2 ( V_2 -> V_6 , ERROR ,
L_27 ,
V_256 -> V_262 , V_258 ) ;
if ( V_261 && V_258 != V_266 )
V_261 -> V_267 = V_268 ;
} else {
F_2 ( V_2 -> V_6 , V_33 ,
L_28 ,
V_256 -> V_262 ) ;
}
break;
case V_269 :
if ( V_258 ) {
F_2 ( V_2 -> V_6 , ERROR ,
L_29 ,
V_256 -> V_262 , V_258 ) ;
if ( V_261 )
V_261 -> V_267 = V_268 ;
} else {
F_2 ( V_2 -> V_6 , V_33 ,
L_30 ,
V_256 -> V_262 ) ;
}
break;
default:
F_2 ( V_2 -> V_6 , ERROR ,
L_31 , V_19 ) ;
return - 1 ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_270 * V_271 =
& V_4 -> V_17 . V_37 ;
F_2 ( V_2 -> V_6 , V_272 ,
L_32 ,
F_3 ( V_271 -> V_49 ) ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_273 * V_274 =
& V_4 -> V_17 . V_274 ;
struct V_275 * V_276 = ( void * ) & V_274 -> V_104 ;
int V_108 ;
struct V_260 * V_277 ;
for ( V_108 = 0 ; V_108 < V_274 -> V_278 ; V_108 ++ ) {
V_277 = F_43 ( V_2 , V_276 -> V_224 ) ;
if ( F_46 ( ! V_277 ) )
continue;
V_277 -> V_78 . V_279 = V_276 -> V_279 ;
V_276 ++ ;
}
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_11 != V_280 ) {
F_2 ( V_2 -> V_6 , ERROR , L_33 ) ;
return - 1 ;
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_281 * V_282 =
& V_4 -> V_17 . V_283 ;
V_6 -> V_284 = V_282 -> V_285 ;
V_6 -> V_286 = F_3 ( V_282 -> V_287 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
bool * V_288 )
{
struct V_289 * V_290 = & V_4 -> V_17 . V_290 ;
struct V_291 * V_292 ;
T_2 V_19 = F_3 ( V_290 -> V_19 ) ;
T_1 V_140 ;
V_292 = (struct V_291
* ) ( ( T_3 * ) V_290 + sizeof( struct V_289 ) ) ;
if ( V_19 == V_70 ) {
V_140 = F_12 ( V_292 -> V_140 ) ;
if ( V_140 == V_293 )
* V_288 = true ;
else
* V_288 = false ;
}
return 0 ;
}
int F_50 ( struct V_1 * V_2 , T_2 V_294 ,
struct V_3 * V_4 )
{
int V_295 = 0 ;
struct V_5 * V_6 = V_2 -> V_6 ;
void * V_62 = V_6 -> V_12 -> V_62 ;
if ( V_4 -> V_11 != V_280 ) {
F_1 ( V_2 , V_4 ) ;
return - 1 ;
}
switch ( V_294 ) {
case V_296 :
V_295 = F_51 ( V_2 , V_4 ) ;
break;
case V_297 :
V_295 = F_47 ( V_2 , V_4 ) ;
break;
case V_31 :
break;
case V_298 :
V_295 = F_20 ( V_2 , V_4 ) ;
break;
case V_299 :
V_295 = F_21 ( V_2 , V_4 ) ;
break;
case V_300 :
V_295 = F_13 ( V_2 , V_4 ) ;
break;
case V_27 :
V_295 = F_52 ( V_2 , V_4 ) ;
V_6 -> V_12 -> V_13 = false ;
break;
case V_28 :
V_295 = F_53 ( V_2 , V_4 ) ;
V_6 -> V_12 -> V_13 = false ;
break;
case V_301 :
V_295 = F_52 ( V_2 , V_4 ) ;
F_54 ( V_2 -> V_302 . V_303 ) ;
F_2 ( V_6 , V_304 ,
L_34 ) ;
break;
case V_305 :
break;
case V_306 :
V_295 = F_17 ( V_2 , V_4 ) ;
break;
case V_307 :
V_295 = F_18 ( V_2 , V_4 ) ;
break;
case V_308 :
V_295 = F_19 ( V_2 , V_4 ) ;
break;
case V_16 :
V_295 = F_55 ( V_2 , V_4 , V_62 ) ;
break;
case V_309 :
V_295 = F_56 ( V_2 , V_4 ) ;
break;
case V_310 :
V_295 = F_57 ( V_2 , V_4 ) ;
break;
case V_311 :
V_295 = F_24 ( V_2 , V_4 ) ;
break;
case V_312 :
case V_313 :
V_295 = F_58 ( V_2 , V_4 ) ;
break;
case V_314 :
V_295 = F_26 ( V_2 , V_4 ) ;
break;
case V_315 :
V_295 = F_11 ( V_2 , V_4 , V_62 ) ;
break;
case V_316 :
V_295 = F_8 ( V_2 , V_4 ) ;
break;
case V_317 :
V_295 = F_10 ( V_2 , V_4 , V_62 ) ;
break;
case V_122 :
V_295 = F_22 ( V_2 , V_4 ) ;
break;
case V_318 :
V_295 = F_31 ( V_2 , V_4 , V_62 ) ;
break;
case V_319 :
V_295 = F_32 ( V_2 , V_4 , V_62 ) ;
break;
case V_320 :
break;
case V_321 :
V_295 = F_33 ( V_2 , V_4 , V_62 ) ;
break;
case V_322 :
case V_323 :
case V_324 :
break;
case V_325 :
V_295 = F_29 ( V_2 , V_4 ) ;
break;
case V_326 :
V_295 = F_30 ( V_2 , V_4 ) ;
break;
case V_327 :
V_295 = F_59 ( V_2 , V_4 ) ;
break;
case V_328 :
V_295 = F_60 ( V_2 , V_4 ) ;
break;
case V_329 :
V_295 = F_61 ( V_2 , V_4 ) ;
break;
case V_330 :
if ( 0xffff == ( T_2 ) F_3 ( V_4 -> V_17 . V_331 . V_332 ) ) {
if ( V_6 -> V_333 == V_334 &&
V_6 -> V_335 ) {
if ( V_6 -> V_336 . V_337 )
V_6 -> V_336 .
V_337 ( V_6 ) ;
V_6 -> V_335 = false ;
V_6 -> V_338 = false ;
}
break;
}
V_6 -> V_339 = ( T_2 ) F_3 ( V_4 -> V_17 .
V_331 . V_332 ) ;
V_6 -> V_339 = ( V_6 -> V_339
/ V_340 )
* V_340 ;
V_6 -> V_341 = V_6 -> V_339 ;
F_2 ( V_6 , V_304 , L_35 ,
V_6 -> V_341 ) ;
if ( V_6 -> V_336 . V_342 )
V_6 -> V_336 . V_342 ( V_6 ,
F_3 ( V_4 -> V_17 . V_331 . V_343 ) ) ;
break;
case V_344 :
break;
case V_345 :
V_295 = F_62 ( V_2 , V_4 ) ;
break;
case V_346 :
V_295 = F_39 ( V_2 , V_4 ) ;
break;
case V_347 :
V_295 = F_34 ( V_2 , V_4 , V_62 ) ;
break;
case V_233 :
case V_236 :
case V_238 :
case V_240 :
case V_242 :
case V_243 :
V_295 = F_35 ( V_294 , V_4 , V_62 ) ;
break;
case V_348 :
break;
case V_349 :
break;
case V_350 :
break;
case V_61 :
V_295 = F_44 ( V_2 , V_4 ) ;
break;
case V_351 :
break;
case V_352 :
V_295 = F_45 ( V_2 , V_4 ) ;
break;
case V_353 :
V_6 -> V_338 = false ;
V_6 -> V_354 = false ;
V_6 -> V_355 = false ;
V_2 -> V_356 = 1 ;
break;
case V_357 :
V_2 -> V_356 = 0 ;
break;
case V_358 :
break;
case V_359 :
break;
case V_360 :
break;
case V_361 :
break;
case V_362 :
V_295 = F_42 ( V_2 , V_4 ) ;
case V_363 :
break;
case V_364 :
break;
case V_32 :
V_295 = F_48 ( V_2 , V_4 ) ;
break;
case V_365 :
V_295 = F_63 ( V_2 , V_4 , V_62 ) ;
break;
case V_366 :
break;
case V_367 :
V_295 = F_49 ( V_2 , V_4 , V_62 ) ;
break;
case V_368 :
break;
default:
F_2 ( V_6 , ERROR ,
L_36 ,
V_4 -> V_10 ) ;
break;
}
return V_295 ;
}
