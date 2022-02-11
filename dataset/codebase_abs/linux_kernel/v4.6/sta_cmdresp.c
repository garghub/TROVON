static void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = NULL , * V_7 ;
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_10 * V_11 ;
unsigned long V_12 ;
F_2 ( V_9 , ERROR ,
L_1 ,
V_4 -> V_13 , V_4 -> V_14 ) ;
if ( V_9 -> V_15 -> V_16 )
V_9 -> V_17 . V_18 = - 1 ;
switch ( F_3 ( V_4 -> V_13 ) ) {
case V_19 :
V_11 = & V_4 -> V_20 . V_21 ;
F_2 ( V_9 , ERROR ,
L_2 ,
V_4 -> V_14 , F_3 ( V_11 -> V_22 ) ) ;
if ( F_3 ( V_11 -> V_22 ) == V_23 &&
( F_3 ( V_11 -> V_20 . V_24 ) & V_25 ) &&
V_2 -> V_26 == V_27 )
V_9 -> V_28 = V_29 ;
break;
case V_30 :
case V_31 :
F_4 ( & V_9 -> V_32 , V_12 ) ;
F_5 (cmd_node, tmp_node,
&adapter->scan_pending_q, list) {
F_6 ( & V_6 -> V_33 ) ;
F_7 ( & V_9 -> V_32 ,
V_12 ) ;
F_8 ( V_9 , V_6 ) ;
F_4 ( & V_9 -> V_32 , V_12 ) ;
}
F_7 ( & V_9 -> V_32 , V_12 ) ;
F_4 ( & V_9 -> V_34 , V_12 ) ;
V_9 -> V_35 = false ;
F_7 ( & V_9 -> V_34 , V_12 ) ;
break;
case V_36 :
break;
case V_37 :
F_2 ( V_9 , V_38 ,
L_3 ) ;
break;
default:
break;
}
F_9 ( V_9 , V_9 -> V_15 ) ;
F_4 ( & V_9 -> V_34 , V_12 ) ;
V_9 -> V_15 = NULL ;
F_7 ( & V_9 -> V_34 , V_12 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_39 * V_40 =
& V_4 -> V_20 . V_40 ;
struct V_41 * V_42 =
& V_2 -> V_43 ;
V_2 -> V_44 = F_3 ( V_40 -> V_44 ) ;
V_2 -> V_45 = F_3 ( V_40 -> V_45 ) ;
V_2 -> V_46 = F_3 ( V_40 -> V_46 ) ;
V_2 -> V_47 = F_3 ( V_40 -> V_47 ) ;
V_2 -> V_48 = F_3 ( V_40 -> V_48 ) ;
V_2 -> V_49 = F_3 ( V_40 -> V_49 ) ;
V_2 -> V_50 = F_3 ( V_40 -> V_50 ) ;
V_2 -> V_51 = F_3 ( V_40 -> V_51 ) ;
if ( V_2 -> V_52 == V_53 )
return 0 ;
memset ( V_42 , 0x00 , sizeof( struct V_41 ) ) ;
V_42 -> V_54 = V_55 | V_56 ;
V_42 -> V_22 = V_57 ;
if ( V_2 -> V_52 == V_58 ) {
V_42 -> V_59 . V_60 = abs ( V_2 -> V_50 -
V_2 -> V_61 ) ;
V_42 -> V_62 . V_60 = abs ( V_2 -> V_63 ) ;
} else if ( V_2 -> V_52 == V_64 ) {
V_42 -> V_59 . V_60 = abs ( V_2 -> V_63 ) ;
V_42 -> V_62 . V_60 = abs ( V_2 -> V_50 +
V_2 -> V_61 ) ;
}
V_42 -> V_59 . V_65 = 1 ;
V_42 -> V_62 . V_65 = 1 ;
V_2 -> V_52 = V_53 ;
F_11 ( V_2 , V_66 ,
0 , 0 , V_42 , false ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_67 )
{
struct V_68 * V_69 = & V_4 -> V_20 . V_69 ;
T_2 V_70 = F_3 ( V_69 -> V_70 ) ;
T_2 V_71 = F_3 ( V_69 -> V_71 ) ;
T_1 V_72 ;
F_2 ( V_2 -> V_9 , V_73 ,
L_4
L_5 ,
V_70 , V_71 , F_3 ( V_69 -> V_74 ) ) ;
if ( V_71 == V_75 ) {
V_72 = F_3 ( * ( ( V_76 * ) ( V_69 -> V_77 ) ) ) ;
if ( V_67 )
* V_67 = V_72 ;
switch ( V_70 ) {
case V_78 :
F_2 ( V_2 -> V_9 , V_73 ,
L_6 ,
V_72 ) ;
break;
case V_79 :
F_2 ( V_2 -> V_9 , V_73 ,
L_7 ,
V_72 ) ;
break;
case V_80 :
F_2 ( V_2 -> V_9 , V_73 ,
L_8 ,
V_72 ) ;
break;
case V_81 :
F_2 ( V_2 -> V_9 , V_73 ,
L_9 ,
V_72 ) ;
default:
break;
}
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_82 * V_83 )
{
struct V_84 * V_85 =
& V_4 -> V_20 . V_85 ;
if ( V_83 ) {
V_83 -> V_86 = F_14 ( V_85 -> V_86 ) ;
V_83 -> V_87 = F_14 ( V_85 -> V_87 ) ;
V_83 -> V_88 = F_14 ( V_85 -> V_88 ) ;
V_83 -> V_89 = F_14 ( V_85 -> V_89 ) ;
V_83 -> V_90 = F_14 ( V_85 -> V_90 ) ;
V_83 -> V_91 = F_14 ( V_85 -> V_91 ) ;
V_83 -> V_92 = F_14 ( V_85 -> V_92 ) ;
V_83 -> V_93 = F_14 ( V_85 -> V_93 ) ;
V_83 -> V_94 = F_14 ( V_85 -> V_94 ) ;
V_83 -> V_95 = F_14 ( V_85 -> V_95 ) ;
V_83 -> V_96 = F_14 ( V_85 -> V_96 ) ;
V_83 -> V_97 = F_14 ( V_85 -> V_97 ) ;
V_83 -> V_98 [ 0 ] =
F_14 ( V_85 -> V_99 [ 0 ] ) ;
V_83 -> V_98 [ 1 ] =
F_14 ( V_85 -> V_99 [ 1 ] ) ;
V_83 -> V_98 [ 2 ] =
F_14 ( V_85 -> V_99 [ 2 ] ) ;
V_83 -> V_98 [ 3 ] =
F_14 ( V_85 -> V_99 [ 3 ] ) ;
V_83 -> V_100 = F_14 ( V_85 -> V_100 ) ;
V_83 -> V_101 = F_14 ( V_85 -> V_101 ) ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_102 * V_103 = & V_4 -> V_20 . V_104 ;
struct V_105 * V_106 ;
struct V_107 * V_108 ;
T_2 V_109 , V_110 , V_111 ;
T_3 * V_112 ;
T_1 V_113 ;
V_112 = ( ( T_3 * ) V_103 ) + sizeof( struct V_102 ) ;
V_111 = F_3 ( V_4 -> V_114 ) - V_115 - sizeof( * V_103 ) ;
while ( V_111 >= sizeof( * V_108 ) ) {
V_108 = (struct V_107 * ) V_112 ;
V_109 = F_3 ( V_108 -> type ) ;
V_110 = F_3 ( V_108 -> V_116 ) ;
if ( V_111 < ( sizeof( * V_108 ) + V_110 ) )
break;
switch ( V_109 ) {
case V_117 :
V_106 = (struct V_105 * ) V_112 ;
V_2 -> V_118 [ 0 ] =
F_3 ( V_106 -> V_119 ) ;
V_2 -> V_118 [ 1 ] =
F_3 ( V_106 -> V_120 ) ;
for ( V_113 = 0 ;
V_113 <
sizeof( V_106 -> V_121 ) /
sizeof( T_2 ) ; V_113 ++ )
V_2 -> V_118 [ 2 + V_113 ] =
F_3 ( V_106 ->
V_121 [ V_113 ] ) ;
if ( V_2 -> V_9 -> V_122 == V_123 ) {
for ( V_113 = 0 ; V_113 < F_16 ( V_106 ->
V_124 ) ;
V_113 ++ )
V_2 -> V_118 [ 10 + V_113 ] =
F_3 ( V_106 ->
V_124 [ V_113 ] ) ;
}
break;
}
V_112 += ( sizeof( * V_108 ) + V_110 ) ;
V_111 -= ( sizeof( * V_108 ) + V_110 ) ;
}
V_2 -> V_125 = F_17 ( V_2 ) ;
if ( V_2 -> V_125 )
V_2 -> V_126 = 0 ;
else
return F_11 ( V_2 , V_127 ,
V_75 , 0 , NULL , false ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , void * V_67 )
{
int V_128 , V_129 = - 1 , V_130 = - 1 ;
struct V_131 * V_132 ;
struct V_133 * V_134 ;
if ( ! V_67 )
return - 1 ;
V_132 = (struct V_131 * ) ( ( T_3 * ) V_67 ) ;
V_134 = (struct V_133 * )
( ( T_3 * ) V_132 + sizeof( struct V_131 ) ) ;
V_128 = F_3 ( V_132 -> V_128 ) ;
if ( V_128 < sizeof( struct V_133 ) )
return 0 ;
V_129 = V_134 -> V_135 ;
V_130 = V_134 -> V_136 ;
V_128 -= sizeof( struct V_133 ) ;
while ( V_128 >= sizeof( struct V_133 ) ) {
V_134 ++ ;
if ( V_129 < V_134 -> V_135 )
V_129 = V_134 -> V_135 ;
if ( V_130 > V_134 -> V_136 )
V_130 = V_134 -> V_136 ;
V_128 -= sizeof( struct V_133 ) ;
}
V_2 -> V_137 = ( T_3 ) V_130 ;
V_2 -> V_138 = ( T_3 ) V_129 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_139 * V_140 = & V_4 -> V_20 . V_140 ;
struct V_131 * V_132 ;
struct V_133 * V_134 ;
T_2 V_22 = F_3 ( V_140 -> V_22 ) ;
T_2 V_111 ;
V_132 = (struct V_131 * )
( ( T_3 * ) V_140 +
sizeof( struct V_139 ) ) ;
V_134 = (struct V_133 * )
( ( T_3 * ) V_132 +
sizeof( struct V_131 ) ) ;
V_111 = F_3 ( V_4 -> V_114 ) - V_115 - sizeof( * V_140 ) ;
if ( V_111 <
F_3 ( V_132 -> V_128 ) + sizeof( * V_132 ) )
return 0 ;
switch ( V_22 ) {
case V_75 :
if ( V_9 -> V_141 == V_142 )
F_18 ( V_2 , V_132 ) ;
V_2 -> V_143 = ( T_2 ) V_134 -> V_136 ;
break;
case V_144 :
if ( ! F_14 ( V_140 -> V_145 ) )
break;
if ( V_134 -> V_135 == V_134 -> V_136 )
V_2 -> V_143 = ( T_2 ) V_134 -> V_136 ;
break;
default:
F_2 ( V_9 , ERROR ,
L_10 ,
V_22 ) ;
return 0 ;
}
F_2 ( V_9 , V_73 ,
L_11 ,
V_2 -> V_143 , V_2 -> V_138 ,
V_2 -> V_137 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_146 * V_147 = & V_4 -> V_20 . V_147 ;
T_2 V_22 = F_3 ( V_147 -> V_22 ) ;
V_2 -> V_143 = F_3 ( V_147 -> V_148 ) ;
if ( V_22 == V_75 ) {
V_2 -> V_138 = V_147 -> V_129 ;
V_2 -> V_137 = V_147 -> V_130 ;
}
F_2 ( V_2 -> V_9 , V_73 ,
L_12 ,
V_2 -> V_143 , V_2 -> V_138 ,
V_2 -> V_137 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_149 * V_150 = & V_4 -> V_20 . V_150 ;
struct V_151 * V_152 = & V_4 -> V_20 . V_152 ;
struct V_8 * V_9 = V_2 -> V_9 ;
if ( V_9 -> V_153 == V_154 )
F_2 ( V_9 , V_73 ,
L_13
L_14 ,
F_3 ( V_150 -> V_155 ) ,
F_3 ( V_150 -> V_156 ) ,
F_3 ( V_150 -> V_157 ) ,
F_3 ( V_150 -> V_158 ) ) ;
else
F_2 ( V_9 , V_73 ,
L_15 ,
F_3 ( V_152 -> V_22 ) ,
F_3 ( V_152 -> V_159 ) ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_160 * V_161 =
& V_4 -> V_20 . V_162 ;
memcpy ( V_2 -> V_163 , V_161 -> V_162 , V_164 ) ;
F_2 ( V_2 -> V_9 , V_73 ,
L_16 , V_2 -> V_163 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_2 -> V_165 = V_4 -> V_20 . V_165 . V_165 ;
V_2 -> V_166 = V_4 -> V_20 . V_165 . V_167 ;
if ( ! V_2 -> V_125 )
V_2 -> V_126 =
F_25 ( V_2 , V_2 -> V_165 ,
V_2 -> V_166 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
V_9 -> V_168 . V_169 ++ ;
if ( ! memcmp ( V_4 -> V_20 . V_170 . V_162 ,
& V_2 -> V_171 . V_172 . V_173 ,
sizeof( V_4 -> V_20 . V_170 . V_162 ) ) )
F_27 ( V_2 , V_174 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_27 ( V_2 , V_174 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_175 * V_176 =
& V_4 -> V_20 . V_177 ;
if ( F_3 ( V_176 -> V_22 ) == V_144 ) {
if ( ( F_3 ( V_176 -> V_178 . V_179 ) & V_180 ) ) {
F_2 ( V_2 -> V_9 , V_73 ,
L_17 ) ;
V_2 -> V_181 = true ;
V_2 -> V_182 = false ;
V_2 -> V_183 = true ;
}
}
memset ( V_2 -> V_184 . V_178 . V_176 , 0 ,
sizeof( V_176 -> V_178 . V_176 ) ) ;
V_2 -> V_184 . V_178 . V_185 = V_176 -> V_178 . V_185 ;
memcpy ( V_2 -> V_184 . V_178 . V_176 , V_176 -> V_178 . V_176 ,
F_3 ( V_2 -> V_184 . V_178 . V_185 ) ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_186 * V_187 ;
V_76 V_116 ;
V_187 = & V_4 -> V_20 . V_188 ;
if ( F_3 ( V_187 -> V_22 ) == V_144 ) {
if ( ( F_3 ( V_187 -> V_178 . V_179 ) & V_180 ) ) {
F_2 ( V_2 -> V_9 , V_73 , L_17 ) ;
V_2 -> V_181 = true ;
V_2 -> V_182 = false ;
V_2 -> V_183 = true ;
}
}
if ( V_187 -> V_178 . V_189 != V_190 )
return 0 ;
memset ( V_2 -> V_191 . V_178 . V_192 . V_193 . V_176 , 0 ,
V_194 ) ;
V_2 -> V_191 . V_178 . V_192 . V_193 . V_185 =
V_187 -> V_178 . V_192 . V_193 . V_185 ;
V_116 = V_2 -> V_191 . V_178 . V_192 . V_193 . V_185 ;
memcpy ( V_2 -> V_191 . V_178 . V_192 . V_193 . V_176 ,
V_187 -> V_178 . V_192 . V_193 . V_176 , F_3 ( V_116 ) ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_2 -> V_9 -> V_195 == V_196 )
return F_30 ( V_2 , V_4 ) ;
else
return F_29 ( V_2 , V_4 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_197 * V_198 =
& V_4 -> V_20 . V_199 ;
struct V_200 * V_201 = & V_198 -> V_201 ;
T_2 V_22 = F_3 ( V_198 -> V_22 ) ;
T_3 V_202 ;
V_202 = ( T_3 ) ( ( F_3 ( V_201 -> V_203 . V_116 )
- V_204 )
/ sizeof( struct V_205 ) ) ;
F_2 ( V_2 -> V_9 , V_73 ,
L_18 ,
V_202 ) ;
if ( V_202 > V_206 ) {
F_2 ( V_2 -> V_9 , V_207 ,
L_19 ,
V_202 ) ;
return - 1 ;
}
switch ( V_22 ) {
case V_144 :
break;
case V_75 :
break;
default:
F_2 ( V_2 -> V_9 , ERROR ,
L_20 , V_198 -> V_22 ) ;
return - 1 ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_208 * V_209 )
{
struct V_208 * V_210 = & V_4 -> V_20 . V_211 ;
if ( V_209 ) {
V_209 -> V_212 = V_210 -> V_212 ;
memcpy ( V_209 -> V_213 , V_210 -> V_213 ,
sizeof( char ) * 128 ) ;
memcpy ( V_2 -> V_213 , V_210 -> V_213 , 128 ) ;
}
return 0 ;
}
static int
F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_214 * V_215 )
{
struct V_214 * V_216 = & V_4 -> V_20 . V_215 ;
if ( V_215 )
memcpy ( V_215 , V_216 , sizeof( * V_215 ) ) ;
return 0 ;
}
static int
F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_67 )
{
struct V_217 * V_218 = & V_4 -> V_20 . V_218 ;
if ( V_67 )
* ( ( T_2 * ) V_67 ) = F_3 ( V_218 -> V_145 ) ;
return 0 ;
}
static int
F_36 ( struct V_1 * V_2 ,
struct V_3 * V_4 , void * V_219 )
{
struct V_220 * V_221 = ( void * ) & V_4 -> V_20 . V_221 ;
V_2 -> V_222 . V_223 = F_14 ( V_221 -> V_223 ) ;
V_2 -> V_222 . V_77 = F_14 ( V_221 -> V_77 ) ;
return 0 ;
}
static int F_37 ( T_2 type , struct V_3 * V_4 ,
void * V_67 )
{
struct V_224 * V_225 ;
struct V_226 * V_227 ;
union T_4 {
struct V_228 * V_229 ;
struct V_230 * V_231 ;
struct V_232 * V_233 ;
struct V_234 * V_235 ;
struct V_236 * V_227 ;
} V_237 ;
if ( ! V_67 )
return 0 ;
V_225 = V_67 ;
V_227 = V_67 ;
switch ( type ) {
case V_238 :
V_237 . V_229 = & V_4 -> V_20 . V_239 ;
V_225 -> V_240 = F_38 ( ( T_1 ) F_3 ( V_237 . V_229 -> V_240 ) ) ;
V_225 -> V_77 = V_237 . V_229 -> V_77 ;
break;
case V_241 :
V_237 . V_231 = & V_4 -> V_20 . V_242 ;
V_225 -> V_240 = F_38 ( ( T_1 ) F_3 ( V_237 . V_231 -> V_240 ) ) ;
V_225 -> V_77 = F_38 ( ( T_1 ) V_237 . V_231 -> V_77 ) ;
break;
case V_243 :
V_237 . V_233 = & V_4 -> V_20 . V_244 ;
V_225 -> V_240 = F_38 ( ( T_1 ) F_3 ( V_237 . V_233 -> V_240 ) ) ;
V_225 -> V_77 = F_38 ( ( T_1 ) V_237 . V_231 -> V_77 ) ;
break;
case V_245 :
V_237 . V_235 = & V_4 -> V_20 . V_246 ;
V_225 -> V_240 = F_38 ( ( T_1 ) F_3 ( V_237 . V_235 -> V_240 ) ) ;
V_225 -> V_77 = F_38 ( ( T_1 ) V_237 . V_235 -> V_77 ) ;
break;
case V_247 :
V_237 . V_233 = & V_4 -> V_20 . V_244 ;
V_225 -> V_240 = F_38 ( ( T_1 ) F_3 ( V_237 . V_233 -> V_240 ) ) ;
V_225 -> V_77 = F_38 ( ( T_1 ) V_237 . V_233 -> V_77 ) ;
break;
case V_248 :
V_237 . V_227 = & V_4 -> V_20 . V_227 ;
F_39 ( L_21 , V_237 . V_227 -> V_249 ) ;
if ( F_3 ( V_227 -> V_249 ) <
F_3 ( V_237 . V_227 -> V_249 ) ) {
V_227 -> V_249 = F_40 ( 0 ) ;
F_39 ( L_22 ) ;
return - 1 ;
}
V_227 -> V_240 = V_237 . V_227 -> V_240 ;
V_227 -> V_249 = V_237 . V_227 -> V_249 ;
if ( F_3 ( V_227 -> V_249 ) > 0 )
memcpy ( & V_227 -> V_77 , & V_237 . V_227 -> V_77 ,
F_3 ( V_237 . V_227 -> V_249 ) ) ;
break;
default:
return - 1 ;
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_250 * V_251 =
& ( V_4 -> V_20 . V_252 ) ;
if ( F_3 ( V_251 -> V_22 ) == V_144 )
return 0 ;
F_2 ( V_2 -> V_9 , V_73 ,
L_23 , V_251 -> V_253 ) ;
if ( F_42 ( V_251 -> V_253 ) ) {
F_2 ( V_2 -> V_9 , V_207 , L_24 ) ;
return 0 ;
}
if ( ! F_43 ( V_2 -> V_171 . V_172 . V_173 , V_251 -> V_253 ) ) {
memcpy ( V_2 -> V_171 . V_172 . V_173 ,
V_251 -> V_253 , V_164 ) ;
V_2 -> V_171 . V_172 . V_254
= F_3 ( V_251 -> V_255 ) ;
V_2 -> V_171 . V_172 . V_256 =
( T_3 ) F_3 ( V_251 -> V_257 ) ;
V_2 -> V_258 = V_259 ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_260 * V_261 = & V_4 -> V_20 . V_262 ;
T_2 V_263 = F_3 ( V_261 -> V_263 ) ;
T_2 V_22 = F_3 ( V_261 -> V_264 ) ;
struct V_265 * V_266 =
F_45 ( V_2 , V_261 -> V_267 ) ;
switch ( V_22 ) {
case V_268 :
if ( V_263 ) {
if ( ! V_266 || V_263 == V_269 )
F_2 ( V_2 -> V_9 , V_38 ,
L_25 ,
V_261 -> V_267 , V_263 ) ;
else
F_2 ( V_2 -> V_9 , ERROR ,
L_25 ,
V_261 -> V_267 , V_263 ) ;
} else {
F_2 ( V_2 -> V_9 , V_38 ,
L_26 ,
V_261 -> V_267 ) ;
}
break;
case V_270 :
if ( V_263 ) {
F_2 ( V_2 -> V_9 , ERROR ,
L_27 ,
V_261 -> V_267 , V_263 ) ;
if ( V_266 && V_263 != V_271 )
V_266 -> V_272 = V_273 ;
} else {
F_2 ( V_2 -> V_9 , V_38 ,
L_28 ,
V_261 -> V_267 ) ;
}
break;
case V_274 :
if ( V_263 ) {
F_2 ( V_2 -> V_9 , ERROR ,
L_29 ,
V_261 -> V_267 , V_263 ) ;
if ( V_266 )
V_266 -> V_272 = V_273 ;
} else {
F_2 ( V_2 -> V_9 , V_38 ,
L_30 ,
V_261 -> V_267 ) ;
}
break;
default:
F_2 ( V_2 -> V_9 , ERROR ,
L_31 , V_22 ) ;
return - 1 ;
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_275 * V_276 =
& V_4 -> V_20 . V_42 ;
F_2 ( V_2 -> V_9 , V_277 ,
L_32 ,
F_3 ( V_276 -> V_54 ) ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_278 * V_279 =
& V_4 -> V_20 . V_279 ;
struct V_280 * V_281 = ( void * ) & V_279 -> V_109 ;
int V_113 ;
struct V_265 * V_282 ;
for ( V_113 = 0 ; V_113 < V_279 -> V_283 ; V_113 ++ ) {
V_282 = F_45 ( V_2 , V_281 -> V_229 ) ;
if ( F_48 ( ! V_282 ) )
continue;
V_282 -> V_83 . V_284 = V_281 -> V_284 ;
V_281 ++ ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_14 != V_285 ) {
F_2 ( V_2 -> V_9 , ERROR , L_33 ) ;
return - 1 ;
}
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_286 * V_287 =
& V_4 -> V_20 . V_288 ;
V_9 -> V_289 = V_287 -> V_290 ;
V_9 -> V_291 = F_3 ( V_287 -> V_292 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
bool * V_293 )
{
struct V_294 * V_295 = & V_4 -> V_20 . V_295 ;
struct V_296 * V_297 ;
T_2 V_22 = F_3 ( V_295 -> V_22 ) ;
T_1 V_145 ;
V_297 = (struct V_296
* ) ( ( T_3 * ) V_295 + sizeof( struct V_294 ) ) ;
if ( V_22 == V_75 ) {
V_145 = F_14 ( V_297 -> V_145 ) ;
if ( V_145 == V_298 )
* V_293 = true ;
else
* V_293 = false ;
}
return 0 ;
}
int F_52 ( struct V_1 * V_2 , T_2 V_299 ,
struct V_3 * V_4 )
{
int V_300 = 0 ;
struct V_8 * V_9 = V_2 -> V_9 ;
void * V_67 = V_9 -> V_15 -> V_67 ;
if ( V_4 -> V_14 != V_285 ) {
F_1 ( V_2 , V_4 ) ;
return - 1 ;
}
switch ( V_299 ) {
case V_301 :
V_300 = F_53 ( V_2 , V_4 ) ;
break;
case V_302 :
V_300 = F_49 ( V_2 , V_4 ) ;
break;
case V_36 :
break;
case V_303 :
V_300 = F_22 ( V_2 , V_4 ) ;
break;
case V_304 :
V_300 = F_23 ( V_2 , V_4 ) ;
break;
case V_305 :
V_300 = F_15 ( V_2 , V_4 ) ;
break;
case V_30 :
V_300 = F_54 ( V_2 , V_4 ) ;
V_9 -> V_15 -> V_16 = false ;
break;
case V_31 :
V_300 = F_55 ( V_2 , V_4 ) ;
V_9 -> V_15 -> V_16 = false ;
break;
case V_306 :
V_300 = F_54 ( V_2 , V_4 ) ;
F_56 ( V_2 -> V_307 . V_308 ) ;
F_2 ( V_9 , V_309 ,
L_34 ) ;
break;
case V_310 :
break;
case V_311 :
V_300 = F_19 ( V_2 , V_4 ) ;
break;
case V_312 :
V_300 = F_20 ( V_2 , V_4 ) ;
break;
case V_313 :
V_300 = F_21 ( V_2 , V_4 ) ;
break;
case V_19 :
V_300 = F_57 ( V_2 , V_4 , V_67 ) ;
break;
case V_314 :
V_300 = F_58 ( V_2 , V_4 ) ;
break;
case V_315 :
V_300 = F_59 ( V_2 , V_4 ) ;
break;
case V_316 :
V_300 = F_26 ( V_2 , V_4 ) ;
break;
case V_317 :
case V_318 :
V_300 = F_60 ( V_2 , V_4 ) ;
break;
case V_319 :
V_300 = F_28 ( V_2 , V_4 ) ;
break;
case V_320 :
V_300 = F_13 ( V_2 , V_4 , V_67 ) ;
break;
case V_321 :
V_300 = F_10 ( V_2 , V_4 ) ;
break;
case V_322 :
V_300 = F_12 ( V_2 , V_4 , V_67 ) ;
break;
case V_127 :
V_300 = F_24 ( V_2 , V_4 ) ;
break;
case V_323 :
V_300 = F_33 ( V_2 , V_4 , V_67 ) ;
break;
case V_324 :
V_300 = F_34 ( V_2 , V_4 , V_67 ) ;
break;
case V_325 :
break;
case V_326 :
V_300 = F_35 ( V_2 , V_4 , V_67 ) ;
break;
case V_327 :
case V_328 :
case V_329 :
break;
case V_330 :
V_300 = F_31 ( V_2 , V_4 ) ;
break;
case V_331 :
V_300 = F_32 ( V_2 , V_4 ) ;
break;
case V_332 :
V_300 = F_61 ( V_2 , V_4 ) ;
break;
case V_333 :
V_300 = F_62 ( V_2 , V_4 ) ;
break;
case V_334 :
V_300 = F_63 ( V_2 , V_4 ) ;
break;
case V_335 :
if ( 0xffff == ( T_2 ) F_3 ( V_4 -> V_20 . V_336 . V_337 ) ) {
if ( V_9 -> V_338 == V_339 &&
V_9 -> V_340 ) {
if ( V_9 -> V_341 . V_342 )
V_9 -> V_341 .
V_342 ( V_9 ) ;
V_9 -> V_340 = false ;
V_9 -> V_343 = false ;
}
break;
}
V_9 -> V_344 = ( T_2 ) F_3 ( V_4 -> V_20 .
V_336 . V_337 ) ;
V_9 -> V_344 = ( V_9 -> V_344
/ V_345 )
* V_345 ;
V_9 -> V_346 = V_9 -> V_344 ;
F_2 ( V_9 , V_309 , L_35 ,
V_9 -> V_346 ) ;
if ( V_9 -> V_341 . V_347 )
V_9 -> V_341 . V_347 ( V_9 ,
F_3 ( V_4 -> V_20 . V_336 . V_348 ) ) ;
break;
case V_349 :
break;
case V_350 :
V_300 = F_64 ( V_2 , V_4 ) ;
break;
case V_351 :
V_300 = F_41 ( V_2 , V_4 ) ;
break;
case V_352 :
V_300 = F_36 ( V_2 , V_4 , V_67 ) ;
break;
case V_238 :
case V_241 :
case V_243 :
case V_245 :
case V_247 :
case V_248 :
V_300 = F_37 ( V_299 , V_4 , V_67 ) ;
break;
case V_353 :
break;
case V_354 :
break;
case V_355 :
break;
case V_66 :
V_300 = F_46 ( V_2 , V_4 ) ;
break;
case V_356 :
break;
case V_357 :
V_300 = F_47 ( V_2 , V_4 ) ;
break;
case V_358 :
V_9 -> V_343 = false ;
V_9 -> V_359 = false ;
V_9 -> V_360 = false ;
V_2 -> V_361 = 1 ;
break;
case V_362 :
V_2 -> V_361 = 0 ;
break;
case V_363 :
break;
case V_364 :
break;
case V_365 :
break;
case V_366 :
break;
case V_367 :
V_300 = F_44 ( V_2 , V_4 ) ;
case V_368 :
break;
case V_369 :
break;
case V_37 :
V_300 = F_50 ( V_2 , V_4 ) ;
break;
case V_370 :
V_300 = F_65 ( V_2 , V_4 , V_67 ) ;
break;
case V_371 :
break;
case V_372 :
V_300 = F_51 ( V_2 , V_4 , V_67 ) ;
break;
default:
F_2 ( V_9 , ERROR ,
L_36 ,
V_4 -> V_13 ) ;
break;
}
return V_300 ;
}
