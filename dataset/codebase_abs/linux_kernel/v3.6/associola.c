static struct V_1 * F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_5 * V_6 ,
T_1 V_7 ,
T_2 V_8 )
{
struct V_9 * V_10 ;
int V_11 ;
T_3 * V_12 ;
int V_13 ;
V_10 = F_2 ( (struct V_5 * ) V_6 ) ;
V_2 -> V_4 = (struct V_3 * ) V_4 ;
F_3 ( V_2 -> V_4 ) ;
V_2 -> V_14 . V_6 = (struct V_5 * ) V_6 ;
F_4 ( V_2 -> V_14 . V_6 ) ;
V_2 -> V_14 . type = V_15 ;
F_5 ( & V_2 -> V_14 . V_16 , 1 ) ;
V_2 -> V_14 . V_17 = 0 ;
V_2 -> V_14 . V_18 = 0 ;
F_6 ( & V_2 -> V_14 . V_19 , V_4 -> V_14 . V_19 . V_20 ) ;
V_2 -> V_21 = V_22 ;
V_2 -> V_23 . V_24 = V_10 -> V_25 . V_26 / 1000 ;
V_2 -> V_23 . V_27 = ( V_10 -> V_25 . V_26 % 1000 )
* 1000 ;
V_2 -> V_28 = 0 ;
V_2 -> V_29 = V_10 -> V_29 ;
V_2 -> V_30 = V_10 -> V_25 . V_31 ;
V_2 -> V_32 = V_33 ;
V_2 -> V_34 = F_7 ( V_10 -> V_35 . V_36 ) ;
V_2 -> V_37 = F_7 ( V_10 -> V_35 . V_38 ) ;
V_2 -> V_39 = F_7 ( V_10 -> V_35 . V_40 ) ;
V_2 -> V_41 = 0 ;
V_2 -> V_42 = F_7 ( V_10 -> V_42 ) ;
V_2 -> V_43 = V_10 -> V_43 ;
V_2 -> V_44 = V_10 -> V_44 ;
V_2 -> V_45 = F_7 ( V_10 -> V_45 ) ;
V_2 -> V_46 = V_10 -> V_46 ;
V_2 -> V_47 = V_10 -> V_47 ;
V_2 -> V_48 = V_10 -> V_48 ;
V_2 -> V_49 [ V_50 ] = 0 ;
V_2 -> V_49 [ V_51 ] = V_2 -> V_34 ;
V_2 -> V_49 [ V_52 ] = V_2 -> V_34 ;
V_2 -> V_49 [ V_53 ] = V_2 -> V_34 ;
V_2 -> V_49 [ V_54 ] = 0 ;
V_2 -> V_49 [ V_55 ] = 0 ;
V_2 -> V_49 [ V_56 ]
= 5 * V_2 -> V_37 ;
V_2 -> V_49 [ V_57 ] = 0 ;
V_2 -> V_49 [ V_58 ] = V_2 -> V_45 ;
V_2 -> V_49 [ V_59 ] =
F_8 (unsigned long, sp->autoclose, sctp_max_autoclose) * V_60 ;
for ( V_11 = V_50 ; V_11 < V_61 ; ++ V_11 )
F_9 ( & V_2 -> V_62 [ V_11 ] , V_63 [ V_11 ] ,
( unsigned long ) V_2 ) ;
V_2 -> V_64 . V_65 = V_10 -> V_66 . V_65 ;
V_2 -> V_64 . V_67 = V_10 -> V_66 . V_67 ;
V_2 -> V_68 = V_10 -> V_66 . V_69 ;
V_2 -> V_70 =
F_7 ( V_10 -> V_66 . V_71 ) ;
V_2 -> V_72 = NULL ;
if ( ( V_6 -> V_73 / 2 ) < V_74 )
V_2 -> V_75 = V_74 ;
else
V_2 -> V_75 = V_6 -> V_73 / 2 ;
V_2 -> V_76 = V_2 -> V_75 ;
V_2 -> V_77 = 0 ;
V_2 -> V_78 = 0 ;
V_2 -> V_79 . V_75 = V_80 ;
V_2 -> V_81 = 0 ;
F_5 ( & V_2 -> V_82 , 0 ) ;
F_10 ( & V_2 -> V_83 ) ;
V_2 -> V_64 . V_84 = F_11 ( V_4 ) ;
V_2 -> V_79 . V_11 . V_85 = 0 ;
V_2 -> V_64 . V_86 = 0 ;
V_2 -> V_64 . V_87 = 0 ;
V_2 -> V_64 . V_88 = 0 ;
V_2 -> V_64 . V_89 = V_4 -> V_14 . V_19 . V_20 ;
V_2 -> V_64 . V_90 = F_12 ( V_4 ) ;
V_2 -> V_91 = V_2 -> V_64 . V_90 ;
V_2 -> V_92 = V_2 -> V_91 - 1 ;
V_2 -> V_93 = V_2 -> V_92 ;
V_2 -> V_94 = V_2 -> V_92 ;
V_2 -> V_95 = V_2 -> V_92 ;
V_2 -> V_96 = 0 ;
V_2 -> V_97 = V_2 -> V_64 . V_90 ;
F_13 ( & V_2 -> V_98 ) ;
F_13 ( & V_2 -> V_99 ) ;
F_13 ( & V_2 -> V_79 . V_100 ) ;
V_2 -> V_79 . V_101 = 0 ;
V_2 -> V_79 . V_102 = 1 ;
V_2 -> V_79 . V_103 = 0 ;
V_2 -> V_79 . V_104 = 1 ;
V_2 -> V_79 . V_105 = 0 ;
if ( V_106 )
V_2 -> V_79 . V_105 = 1 ;
V_2 -> V_107 = NULL ;
V_2 -> V_108 = 0 ;
V_2 -> V_109 = NULL ;
F_14 ( & V_2 -> V_14 . V_110 ) ;
F_15 ( & V_2 -> V_14 . V_110 , V_111 ) ;
F_16 ( V_2 , & V_2 -> V_112 ) ;
if ( ! F_17 ( & V_2 -> V_113 , V_2 ) )
goto V_114;
memset ( & V_2 -> V_79 . V_115 , 0 , sizeof( struct V_116 ) ) ;
V_2 -> V_117 = 0 ;
V_2 -> V_118 = 0 ;
V_2 -> V_79 . V_119 = 1 ;
if ( V_2 -> V_14 . V_6 -> V_120 == V_121 )
V_2 -> V_79 . V_122 = 1 ;
F_13 ( & V_2 -> V_123 ) ;
V_2 -> V_124 = V_10 -> V_124 ;
V_2 -> V_125 = V_10 -> V_125 ;
V_2 -> V_126 = V_10 -> V_126 ;
V_2 -> V_127 = V_10 -> V_127 ;
V_2 -> V_128 = V_10 -> V_128 ;
V_2 -> V_129 = V_10 -> V_129 ;
V_2 -> V_130 = V_10 -> V_130 ;
F_13 ( & V_2 -> V_131 ) ;
V_13 = F_18 ( V_4 , V_2 , V_8 ) ;
if ( V_13 )
goto V_114;
V_2 -> V_132 = V_4 -> V_132 ;
V_2 -> V_133 = NULL ;
V_2 -> V_134 = 0 ;
if ( V_4 -> V_135 )
memcpy ( V_2 -> V_64 . V_136 , V_4 -> V_135 ,
F_19 ( V_4 -> V_135 -> V_137 . V_138 ) ) ;
if ( V_4 -> V_139 )
memcpy ( V_2 -> V_64 . V_140 , V_4 -> V_139 ,
F_19 ( V_4 -> V_139 -> V_137 . V_138 ) ) ;
V_12 = ( T_3 * ) V_2 -> V_64 . V_141 ;
V_12 -> type = V_142 ;
V_12 -> V_138 = F_20 ( sizeof( T_3 ) + V_143 ) ;
F_21 ( V_12 + 1 , V_143 ) ;
return V_2 ;
V_114:
F_22 ( V_2 -> V_4 ) ;
F_23 ( V_2 -> V_14 . V_6 ) ;
return NULL ;
}
struct V_1 * F_24 ( const struct V_3 * V_4 ,
const struct V_5 * V_6 ,
T_1 V_7 ,
T_2 V_8 )
{
struct V_1 * V_2 ;
V_2 = F_25 ( struct V_1 , V_8 ) ;
if ( ! V_2 )
goto V_144;
if ( ! F_1 ( V_2 , V_4 , V_6 , V_7 , V_8 ) )
goto V_114;
V_2 -> V_14 . V_18 = 1 ;
F_26 ( V_145 ) ;
F_27 ( L_1 , V_2 ) ;
return V_2 ;
V_114:
F_28 ( V_2 ) ;
V_144:
return NULL ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_14 . V_6 ;
struct V_146 * V_147 ;
struct V_148 * V_149 , * V_150 ;
int V_11 ;
if ( ! V_2 -> V_150 ) {
F_30 ( & V_2 -> V_123 ) ;
if ( F_31 ( V_6 , V_151 ) && F_32 ( V_6 , V_152 ) )
V_6 -> V_153 -- ;
}
V_2 -> V_14 . V_17 = 1 ;
F_33 ( & V_2 -> V_112 ) ;
F_34 ( & V_2 -> V_113 ) ;
F_35 ( & V_2 -> V_14 . V_110 ) ;
F_36 ( & V_2 -> V_79 . V_115 ) ;
F_37 ( V_2 -> V_72 ) ;
F_38 ( & V_2 -> V_14 . V_19 ) ;
for ( V_11 = V_50 ; V_11 < V_61 ; ++ V_11 ) {
if ( F_39 ( & V_2 -> V_62 [ V_11 ] ) &&
F_40 ( & V_2 -> V_62 [ V_11 ] ) )
F_41 ( V_2 ) ;
}
F_28 ( V_2 -> V_79 . V_154 ) ;
F_28 ( V_2 -> V_79 . V_155 ) ;
F_28 ( V_2 -> V_79 . V_156 ) ;
F_28 ( V_2 -> V_79 . V_157 ) ;
F_42 (pos, temp, &asoc->peer.transport_addr_list) {
V_147 = F_43 ( V_149 , struct V_146 , V_158 ) ;
F_30 ( V_149 ) ;
F_44 ( V_147 ) ;
}
V_2 -> V_79 . V_101 = 0 ;
F_45 ( V_2 ) ;
if ( V_2 -> V_107 != NULL )
F_28 ( V_2 -> V_107 ) ;
F_46 ( & V_2 -> V_131 ) ;
F_47 ( V_2 -> V_133 ) ;
F_41 ( V_2 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_49 (asoc->base.dead, L_2 , return) ;
F_22 ( V_2 -> V_4 ) ;
F_23 ( V_2 -> V_14 . V_6 ) ;
if ( V_2 -> V_118 != 0 ) {
F_50 ( & V_159 ) ;
F_51 ( & V_160 , V_2 -> V_118 ) ;
F_52 ( & V_159 ) ;
}
F_53 ( F_54 ( & V_2 -> V_82 ) ) ;
if ( V_2 -> V_14 . V_18 ) {
F_28 ( V_2 ) ;
F_55 ( V_145 ) ;
}
}
void F_56 ( struct V_1 * V_2 ,
struct V_146 * V_147 )
{
int V_161 = 0 ;
if ( V_2 -> V_79 . V_162 != NULL &&
V_2 -> V_79 . V_162 != V_147 )
V_161 = 1 ;
V_2 -> V_79 . V_162 = V_147 ;
memcpy ( & V_2 -> V_79 . V_163 , & V_147 -> V_164 ,
sizeof( union V_165 ) ) ;
if ( ( V_147 -> V_21 == V_166 ) ||
( V_147 -> V_21 == V_167 ) )
V_2 -> V_79 . V_168 = V_147 ;
if ( ! V_2 -> V_112 . V_169 && ! V_2 -> V_112 . V_170 )
return;
if ( V_147 -> V_171 . V_172 )
V_147 -> V_171 . V_173 = V_161 ;
V_147 -> V_171 . V_172 = V_161 ;
V_147 -> V_171 . V_174 = V_2 -> V_91 ;
}
void F_57 ( struct V_1 * V_2 ,
struct V_146 * V_79 )
{
struct V_148 * V_149 ;
struct V_146 * V_147 ;
F_58 ( L_3 ,
L_4 ,
V_2 ,
( & V_79 -> V_164 ) ,
F_19 ( V_79 -> V_164 . V_175 . V_176 ) ) ;
if ( V_2 -> V_79 . V_177 == V_79 )
F_59 ( V_2 ) ;
F_30 ( & V_79 -> V_158 ) ;
V_149 = V_2 -> V_79 . V_100 . V_178 ;
V_147 = F_43 ( V_149 , struct V_146 , V_158 ) ;
if ( V_2 -> V_79 . V_162 == V_79 )
F_56 ( V_2 , V_147 ) ;
if ( V_2 -> V_79 . V_168 == V_79 )
V_2 -> V_79 . V_168 = V_147 ;
if ( V_2 -> V_79 . V_177 == V_79 )
V_2 -> V_79 . V_177 = V_147 ;
if ( V_2 -> V_79 . V_179 == V_79 )
V_2 -> V_79 . V_179 = V_147 ;
if ( V_2 -> V_180 == V_79 )
V_2 -> V_180 = NULL ;
if ( V_2 -> V_181 == V_79 )
V_2 -> V_181 = NULL ;
if ( V_2 -> V_182 &&
V_2 -> V_182 -> V_147 == V_79 )
V_2 -> V_182 -> V_147 = NULL ;
if ( ! F_60 ( & V_79 -> V_183 ) ) {
struct V_146 * V_184 = V_2 -> V_79 . V_168 ;
struct V_185 * V_186 ;
F_61 (ch, &peer->transmitted,
transmitted_list) {
V_186 -> V_147 = NULL ;
V_186 -> V_187 = 0 ;
}
F_62 ( & V_79 -> V_183 ,
& V_184 -> V_183 ) ;
if ( ! F_39 ( & V_184 -> V_188 ) )
if ( ! F_63 ( & V_184 -> V_188 ,
V_189 + V_184 -> V_190 ) )
F_64 ( V_184 ) ;
}
V_2 -> V_79 . V_101 -- ;
F_44 ( V_79 ) ;
}
struct V_146 * F_65 ( struct V_1 * V_2 ,
const union V_165 * V_191 ,
const T_2 V_8 ,
const int V_192 )
{
struct V_146 * V_79 ;
struct V_9 * V_10 ;
unsigned short V_20 ;
V_10 = F_2 ( V_2 -> V_14 . V_6 ) ;
V_20 = F_19 ( V_191 -> V_175 . V_176 ) ;
F_58 ( L_5 ,
L_6 ,
V_2 ,
V_191 ,
V_20 ,
V_192 ) ;
if ( 0 == V_2 -> V_79 . V_20 )
V_2 -> V_79 . V_20 = V_20 ;
V_79 = F_66 ( V_2 , V_191 ) ;
if ( V_79 ) {
if ( V_79 -> V_21 == V_167 ) {
V_79 -> V_21 = V_166 ;
}
return V_79 ;
}
V_79 = F_67 ( V_191 , V_8 ) ;
if ( ! V_79 )
return NULL ;
F_68 ( V_79 , V_2 ) ;
V_79 -> V_42 = V_2 -> V_42 ;
V_79 -> V_43 = V_2 -> V_43 ;
V_79 -> V_32 = V_2 -> V_32 ;
V_79 -> V_45 = V_2 -> V_45 ;
V_79 -> V_46 = V_2 -> V_46 ;
V_79 -> V_47 = V_2 -> V_47 ;
F_69 ( V_79 , NULL , V_10 ) ;
if ( V_79 -> V_47 & V_193 ) {
if ( V_2 -> V_44 )
V_79 -> V_44 = V_2 -> V_44 ;
else
V_79 -> V_44 = V_194 ;
}
if ( V_2 -> V_44 )
V_2 -> V_44 = F_8 ( int , V_79 -> V_44 , V_2 -> V_44 ) ;
else
V_2 -> V_44 = V_79 -> V_44 ;
F_27 ( L_7
L_8 , V_2 , V_2 -> V_44 ) ;
V_79 -> V_195 = 0 ;
V_2 -> V_28 = F_70 ( V_2 , V_2 -> V_44 ) ;
F_71 ( & V_79 -> V_196 , V_79 , V_2 -> V_14 . V_19 . V_20 ,
V_2 -> V_79 . V_20 ) ;
V_79 -> V_197 = F_72 ( 4 * V_2 -> V_44 , F_73 ( V_198 , 2 * V_2 -> V_44 , 4380 ) ) ;
V_79 -> V_199 = V_80 ;
V_79 -> V_200 = 0 ;
V_79 -> V_201 = 0 ;
V_79 -> V_202 = 0 ;
V_79 -> V_190 = V_2 -> V_34 ;
V_79 -> V_21 = V_192 ;
F_74 ( & V_79 -> V_158 , & V_2 -> V_79 . V_100 ) ;
V_2 -> V_79 . V_101 ++ ;
if ( ! V_2 -> V_79 . V_162 ) {
F_56 ( V_2 , V_79 ) ;
V_2 -> V_79 . V_177 = V_79 ;
}
if ( V_2 -> V_79 . V_168 == V_2 -> V_79 . V_177 &&
V_79 -> V_21 != V_203 ) {
V_2 -> V_79 . V_177 = V_79 ;
}
return V_79 ;
}
void F_75 ( struct V_1 * V_2 ,
const union V_165 * V_191 )
{
struct V_148 * V_149 ;
struct V_148 * V_150 ;
struct V_146 * V_147 ;
F_42 (pos, temp, &asoc->peer.transport_addr_list) {
V_147 = F_43 ( V_149 , struct V_146 , V_158 ) ;
if ( F_76 ( V_191 , & V_147 -> V_164 ) ) {
F_57 ( V_2 , V_147 ) ;
break;
}
}
}
struct V_146 * F_66 (
const struct V_1 * V_2 ,
const union V_165 * V_204 )
{
struct V_146 * V_205 ;
F_61 (t, &asoc->peer.transport_addr_list,
transports) {
if ( F_76 ( V_204 , & V_205 -> V_164 ) )
return V_205 ;
}
return NULL ;
}
void F_77 ( struct V_1 * V_2 ,
struct V_146 * V_206 )
{
struct V_146 * V_150 ;
struct V_146 * V_205 ;
F_78 (t, temp, &asoc->peer.transport_addr_list,
transports) {
if ( V_205 != V_206 )
F_57 ( V_2 , V_205 ) ;
}
}
void F_79 ( struct V_1 * V_2 ,
struct V_146 * V_147 ,
T_4 V_207 ,
T_5 error )
{
struct V_146 * V_205 = NULL ;
struct V_146 * V_208 ;
struct V_146 * V_209 ;
struct V_210 * V_211 ;
struct V_212 V_191 ;
int V_213 = 0 ;
bool V_214 = true ;
switch ( V_207 ) {
case V_215 :
if ( V_203 == V_147 -> V_21 &&
V_216 == error )
V_213 = V_217 ;
else
V_213 = V_218 ;
if ( V_147 -> V_21 == V_219 ) {
V_214 = false ;
V_147 -> V_197 = 1 ;
}
V_147 -> V_21 = V_166 ;
break;
case V_220 :
if ( V_147 -> V_21 != V_203 )
V_147 -> V_21 = V_221 ;
else {
F_80 ( V_147 -> V_222 ) ;
V_147 -> V_222 = NULL ;
}
V_213 = V_223 ;
break;
case V_224 :
V_147 -> V_21 = V_219 ;
V_214 = false ;
break;
default:
return;
}
if ( V_214 ) {
memset ( & V_191 , 0 , sizeof( struct V_212 ) ) ;
memcpy ( & V_191 , & V_147 -> V_164 ,
V_147 -> V_225 -> V_226 ) ;
V_211 = F_81 ( V_2 , & V_191 ,
0 , V_213 , error , V_227 ) ;
if ( V_211 )
F_82 ( & V_2 -> V_113 , V_211 ) ;
}
V_208 = NULL ; V_209 = NULL ;
F_61 (t, &asoc->peer.transport_addr_list,
transports) {
if ( ( V_205 -> V_21 == V_221 ) ||
( V_205 -> V_21 == V_203 ) ||
( V_205 -> V_21 == V_219 ) )
continue;
if ( ! V_208 || V_205 -> V_228 > V_208 -> V_228 ) {
V_209 = V_208 ;
V_208 = V_205 ;
}
if ( ! V_209 || V_205 -> V_228 > V_209 -> V_228 )
V_209 = V_205 ;
}
if ( ( ( V_2 -> V_79 . V_162 -> V_21 == V_166 ) ||
( V_2 -> V_79 . V_162 -> V_21 == V_167 ) ) &&
V_208 != V_2 -> V_79 . V_162 ) {
V_209 = V_208 ;
V_208 = V_2 -> V_79 . V_162 ;
}
if ( ! V_208 ) {
V_208 = V_2 -> V_79 . V_162 ;
V_209 = V_2 -> V_79 . V_162 ;
}
V_2 -> V_79 . V_168 = V_208 ;
V_2 -> V_79 . V_177 = V_209 ;
}
void F_83 ( struct V_1 * V_2 )
{
F_84 ( & V_2 -> V_14 . V_16 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
if ( F_85 ( & V_2 -> V_14 . V_16 ) )
F_48 ( V_2 ) ;
}
V_198 F_86 ( struct V_1 * V_2 )
{
V_198 V_229 = V_2 -> V_91 ;
V_2 -> V_91 ++ ;
V_2 -> V_96 ++ ;
return V_229 ;
}
int F_76 ( const union V_165 * V_230 ,
const union V_165 * V_231 )
{
struct V_232 * V_233 ;
V_233 = F_87 ( V_230 -> V_234 . V_235 ) ;
if ( F_88 ( ! V_233 ) )
return 0 ;
return V_233 -> V_236 ( V_230 , V_231 ) ;
}
struct V_185 * F_89 ( struct V_1 * V_2 )
{
struct V_185 * V_237 ;
if ( V_2 -> V_117 )
V_237 = F_90 ( V_2 , V_2 -> V_238 ) ;
else
V_237 = NULL ;
return V_237 ;
}
struct V_146 * F_91 ( struct V_1 * V_2 ,
V_198 V_239 )
{
struct V_146 * V_184 ;
struct V_146 * V_240 ;
struct V_146 * V_147 ;
struct V_185 * V_237 ;
T_6 V_241 = F_92 ( V_239 ) ;
V_240 = NULL ;
V_184 = V_2 -> V_79 . V_168 ;
F_61 (chunk, &active->transmitted,
transmitted_list) {
if ( V_241 == V_237 -> V_242 . V_243 -> V_239 ) {
V_240 = V_184 ;
goto V_244;
}
}
F_61 (transport, &asoc->peer.transport_addr_list,
transports) {
if ( V_147 == V_184 )
break;
F_61 (chunk, &transport->transmitted,
transmitted_list) {
if ( V_241 == V_237 -> V_242 . V_243 -> V_239 ) {
V_240 = V_147 ;
goto V_244;
}
}
}
V_244:
return V_240 ;
}
struct V_146 * F_93 ( struct V_1 * V_2 ,
const union V_165 * V_245 ,
const union V_165 * V_246 )
{
struct V_146 * V_147 ;
if ( ( F_20 ( V_2 -> V_14 . V_19 . V_20 ) == V_245 -> V_175 . V_176 ) &&
( F_20 ( V_2 -> V_79 . V_20 ) == V_246 -> V_175 . V_176 ) ) {
V_147 = F_66 ( V_2 , V_246 ) ;
if ( ! V_147 )
goto V_244;
if ( F_94 ( & V_2 -> V_14 . V_19 , V_245 ,
F_2 ( V_2 -> V_14 . V_6 ) ) )
goto V_244;
}
V_147 = NULL ;
V_244:
return V_147 ;
}
static void V_111 ( struct V_247 * V_248 )
{
struct V_1 * V_2 =
F_95 ( V_248 , struct V_1 ,
V_14 . V_110 . V_249 ) ;
struct V_3 * V_4 ;
struct V_185 * V_237 ;
struct V_250 * V_110 ;
int V_21 ;
T_7 V_251 ;
int error = 0 ;
V_4 = V_2 -> V_4 ;
V_110 = & V_2 -> V_14 . V_110 ;
F_83 ( V_2 ) ;
while ( NULL != ( V_237 = F_96 ( V_110 ) ) ) {
V_21 = V_2 -> V_21 ;
V_251 = F_97 ( V_237 -> V_252 -> type ) ;
if ( F_98 ( V_251 . V_237 , V_2 ) && ! V_237 -> V_253 )
continue;
if ( F_99 ( V_237 ) )
V_2 -> V_79 . V_179 = V_237 -> V_147 ;
else
F_100 ( V_254 ) ;
if ( V_237 -> V_147 )
V_237 -> V_147 -> V_228 = V_189 ;
error = F_101 ( V_255 , V_251 ,
V_21 , V_4 , V_2 , V_237 , V_227 ) ;
if ( V_2 -> V_14 . V_17 )
break;
if ( error && V_237 )
V_237 -> V_256 = 1 ;
}
F_41 ( V_2 ) ;
}
void F_102 ( struct V_1 * V_145 , struct V_5 * V_257 )
{
struct V_9 * V_258 = F_2 ( V_257 ) ;
struct V_5 * V_259 = V_145 -> V_14 . V_6 ;
F_103 ( & V_145 -> V_123 ) ;
if ( F_31 ( V_259 , V_151 ) )
V_259 -> V_153 -- ;
F_22 ( V_145 -> V_4 ) ;
F_23 ( V_145 -> V_14 . V_6 ) ;
V_145 -> V_4 = V_258 -> V_4 ;
F_3 ( V_145 -> V_4 ) ;
V_145 -> V_14 . V_6 = V_257 ;
F_4 ( V_145 -> V_14 . V_6 ) ;
F_104 ( V_258 -> V_4 , V_145 ) ;
}
void F_105 ( struct V_1 * V_2 ,
struct V_1 * V_260 )
{
struct V_146 * V_261 ;
struct V_148 * V_149 , * V_150 ;
V_2 -> V_64 = V_260 -> V_64 ;
V_2 -> V_79 . V_75 = V_260 -> V_79 . V_75 ;
V_2 -> V_79 . V_102 = V_260 -> V_79 . V_102 ;
V_2 -> V_79 . V_11 = V_260 -> V_79 . V_11 ;
F_106 ( & V_2 -> V_79 . V_115 , V_262 ,
V_2 -> V_79 . V_11 . V_90 , V_227 ) ;
F_42 (pos, temp, &asoc->peer.transport_addr_list) {
V_261 = F_43 ( V_149 , struct V_146 , V_158 ) ;
if ( ! F_66 ( V_260 , & V_261 -> V_164 ) ) {
F_57 ( V_2 , V_261 ) ;
continue;
}
if ( V_2 -> V_21 >= V_263 )
F_107 ( V_261 ) ;
}
if ( V_2 -> V_21 >= V_263 ) {
V_2 -> V_91 = V_260 -> V_91 ;
V_2 -> V_92 = V_260 -> V_92 ;
V_2 -> V_93 = V_260 -> V_93 ;
F_108 ( V_2 -> V_72 ) ;
F_109 ( & V_2 -> V_113 ) ;
V_2 -> V_41 = 0 ;
} else {
F_61 (trans, &new->peer.transport_addr_list,
transports) {
if ( ! F_66 ( V_2 , & V_261 -> V_164 ) )
F_65 ( V_2 , & V_261 -> V_164 ,
V_227 , V_261 -> V_21 ) ;
}
V_2 -> V_92 = V_2 -> V_91 - 1 ;
V_2 -> V_93 = V_2 -> V_92 ;
if ( ! V_2 -> V_72 ) {
V_2 -> V_72 = V_260 -> V_72 ;
V_260 -> V_72 = NULL ;
}
if ( ! V_2 -> V_118 ) {
F_110 ( V_2 , V_227 ) ;
}
}
F_28 ( V_2 -> V_79 . V_155 ) ;
V_2 -> V_79 . V_155 = V_260 -> V_79 . V_155 ;
V_260 -> V_79 . V_155 = NULL ;
F_28 ( V_2 -> V_79 . V_156 ) ;
V_2 -> V_79 . V_156 = V_260 -> V_79 . V_156 ;
V_260 -> V_79 . V_156 = NULL ;
F_28 ( V_2 -> V_79 . V_157 ) ;
V_2 -> V_79 . V_157 = V_260 -> V_79 . V_157 ;
V_260 -> V_79 . V_157 = NULL ;
F_47 ( V_2 -> V_133 ) ;
F_111 ( V_2 , V_227 ) ;
}
void F_59 ( struct V_1 * V_2 )
{
struct V_146 * V_205 , * V_178 ;
struct V_148 * V_264 = & V_2 -> V_79 . V_100 ;
struct V_148 * V_149 ;
if ( V_2 -> V_79 . V_101 == 1 )
return;
V_205 = V_2 -> V_79 . V_177 ;
V_149 = & V_205 -> V_158 ;
V_178 = NULL ;
while ( 1 ) {
if ( V_149 -> V_178 == V_264 )
V_149 = V_264 -> V_178 ;
else
V_149 = V_149 -> V_178 ;
V_205 = F_43 ( V_149 , struct V_146 , V_158 ) ;
if ( V_205 == V_2 -> V_79 . V_177 ) {
V_205 = V_178 ;
break;
}
if ( ( V_205 -> V_21 == V_166 ) ||
( V_205 -> V_21 == V_167 ) ) {
break;
} else {
if ( V_205 -> V_21 != V_203 && ! V_178 )
V_178 = V_205 ;
}
}
if ( V_205 )
V_2 -> V_79 . V_177 = V_205 ;
else
V_205 = V_2 -> V_79 . V_177 ;
F_58 ( L_9
L_10 ,
L_4 ,
V_2 ,
( & V_205 -> V_164 ) ,
F_19 ( V_205 -> V_164 . V_175 . V_176 ) ) ;
}
struct V_146 * F_112 (
struct V_1 * V_2 , struct V_146 * V_265 )
{
if ( ! V_265 )
return V_2 -> V_79 . V_168 ;
else {
if ( V_265 == V_2 -> V_79 . V_177 )
F_59 ( V_2 ) ;
return V_2 -> V_79 . V_177 ;
}
}
void F_113 ( struct V_5 * V_6 , struct V_1 * V_2 )
{
struct V_146 * V_205 ;
V_198 V_266 = 0 ;
if ( ! V_2 )
return;
F_61 (t, &asoc->peer.transport_addr_list,
transports) {
if ( V_205 -> V_195 && V_205 -> V_222 ) {
F_114 ( V_6 , V_205 , F_115 ( V_205 -> V_222 ) ) ;
V_205 -> V_195 = 0 ;
}
if ( ! V_266 || ( V_205 -> V_44 < V_266 ) )
V_266 = V_205 -> V_44 ;
}
if ( V_266 ) {
V_2 -> V_44 = V_266 ;
V_2 -> V_28 = F_70 ( V_2 , V_266 ) ;
}
F_27 ( L_11 ,
V_267 , V_2 , V_2 -> V_44 , V_2 -> V_28 ) ;
}
static inline int F_116 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_21 ) {
case V_263 :
case V_268 :
case V_269 :
case V_270 :
if ( ( V_2 -> V_75 > V_2 -> V_76 ) &&
( ( V_2 -> V_75 - V_2 -> V_76 ) >= F_73 ( V_198 ,
( V_2 -> V_14 . V_6 -> V_73 >> V_271 ) ,
V_2 -> V_44 ) ) )
return 1 ;
break;
default:
break;
}
return 0 ;
}
void F_117 ( struct V_1 * V_2 , unsigned int V_272 )
{
struct V_185 * V_273 ;
struct V_274 * V_275 ;
if ( V_2 -> V_77 ) {
if ( V_2 -> V_77 >= V_272 ) {
V_2 -> V_77 -= V_272 ;
} else {
V_2 -> V_75 += ( V_272 - V_2 -> V_77 ) ;
V_2 -> V_77 = 0 ;
}
} else {
V_2 -> V_75 += V_272 ;
}
if ( V_2 -> V_78 && V_2 -> V_75 >= V_2 -> V_78 ) {
int V_276 = F_72 ( V_2 -> V_44 , V_2 -> V_78 ) ;
V_2 -> V_75 += V_276 ;
V_2 -> V_78 -= V_276 ;
}
F_27 ( L_12
L_13 , V_267 , V_2 , V_272 , V_2 -> V_75 ,
V_2 -> V_77 , V_2 -> V_76 ) ;
if ( F_116 ( V_2 ) ) {
V_2 -> V_76 = V_2 -> V_75 ;
F_27 ( L_14
L_15 , V_267 ,
V_2 , V_2 -> V_75 , V_2 -> V_76 ) ;
V_273 = F_118 ( V_2 ) ;
if ( ! V_273 )
return;
V_2 -> V_79 . V_102 = 0 ;
F_119 ( & V_2 -> V_112 , V_273 ) ;
V_275 = & V_2 -> V_62 [ V_58 ] ;
if ( F_39 ( V_275 ) && F_40 ( V_275 ) )
F_41 ( V_2 ) ;
}
}
void F_120 ( struct V_1 * V_2 , unsigned int V_272 )
{
int V_277 ;
int V_278 = 0 ;
F_49 (asoc->rwnd, L_16 , return) ;
F_49 (!asoc->rwnd_over, L_17 , return) ;
if ( V_2 -> V_4 -> V_279 )
V_277 = F_54 ( & V_2 -> V_82 ) ;
else
V_277 = F_54 ( & V_2 -> V_14 . V_6 -> V_280 ) ;
if ( V_277 >= V_2 -> V_14 . V_6 -> V_73 )
V_278 = 1 ;
if ( V_2 -> V_75 >= V_272 ) {
V_2 -> V_75 -= V_272 ;
if ( V_278 ) {
V_2 -> V_78 += V_2 -> V_75 ;
V_2 -> V_75 = 0 ;
}
} else {
V_2 -> V_77 = V_272 - V_2 -> V_75 ;
V_2 -> V_75 = 0 ;
}
F_27 ( L_18 ,
V_267 , V_2 , V_272 , V_2 -> V_75 ,
V_2 -> V_77 , V_2 -> V_78 ) ;
}
int F_121 ( struct V_1 * V_2 ,
T_1 V_7 , T_2 V_8 )
{
int V_281 ;
V_281 = ( V_121 == V_2 -> V_14 . V_6 -> V_120 ) ? V_282 : 0 ;
if ( V_2 -> V_79 . V_119 )
V_281 |= V_283 ;
if ( V_2 -> V_79 . V_122 )
V_281 |= V_284 ;
return F_122 ( & V_2 -> V_14 . V_19 ,
& V_2 -> V_4 -> V_14 . V_19 ,
V_7 , V_8 , V_281 ) ;
}
int F_123 ( struct V_1 * V_2 ,
struct V_285 * V_154 ,
T_2 V_8 )
{
int V_286 = F_19 ( V_154 -> V_287 -> V_252 . V_138 ) ;
int V_288 = V_154 -> V_289 ;
T_8 * V_290 = ( T_8 * ) V_154 -> V_287 + V_286 ;
return F_124 ( & V_2 -> V_14 . V_19 , V_290 , V_288 ,
V_2 -> V_4 -> V_14 . V_19 . V_20 , V_8 ) ;
}
int F_125 ( struct V_1 * V_2 ,
const union V_165 * V_245 )
{
int V_291 = 0 ;
if ( ( V_2 -> V_14 . V_19 . V_20 == F_19 ( V_245 -> V_175 . V_176 ) ) &&
F_94 ( & V_2 -> V_14 . V_19 , V_245 ,
F_2 ( V_2 -> V_14 . V_6 ) ) )
V_291 = 1 ;
return V_291 ;
}
int F_110 ( struct V_1 * V_2 , T_2 V_8 )
{
int V_118 ;
int error = 0 ;
if ( V_2 -> V_118 )
return error ;
V_292:
if ( F_88 ( ! F_126 ( & V_160 , V_8 ) ) )
return - V_293 ;
F_50 ( & V_159 ) ;
error = F_127 ( & V_160 , ( void * ) V_2 ,
V_294 , & V_118 ) ;
if ( ! error ) {
V_294 = V_118 + 1 ;
if ( V_294 == V_295 )
V_294 = 1 ;
}
F_52 ( & V_159 ) ;
if ( error == - V_296 )
goto V_292;
else if ( error )
return error ;
V_2 -> V_118 = ( V_297 ) V_118 ;
return error ;
}
static void F_128 ( struct V_1 * V_2 )
{
struct V_185 * V_298 ;
struct V_185 * V_299 ;
F_78 (asconf, tmp, &asoc->addip_chunk_list, list) {
F_103 ( & V_298 -> V_300 ) ;
F_129 ( V_298 ) ;
}
}
static void F_130 ( struct V_1 * V_2 )
{
struct V_185 * V_301 ;
struct V_185 * V_299 ;
F_78 (ack, tmp, &asoc->asconf_ack_list,
transmitted_list) {
F_103 ( & V_301 -> V_302 ) ;
F_129 ( V_301 ) ;
}
}
void F_131 ( const struct V_1 * V_2 )
{
struct V_185 * V_301 ;
struct V_185 * V_299 ;
F_78 (ack, tmp, &asoc->asconf_ack_list,
transmitted_list) {
if ( V_301 -> V_242 . V_303 -> V_304 ==
F_92 ( V_2 -> V_79 . V_97 ) )
break;
F_103 ( & V_301 -> V_302 ) ;
F_129 ( V_301 ) ;
}
}
struct V_185 * F_132 (
const struct V_1 * V_2 ,
T_6 V_304 )
{
struct V_185 * V_301 ;
F_61 (ack, &asoc->asconf_ack_list, transmitted_list) {
if ( V_301 -> V_242 . V_303 -> V_304 == V_304 ) {
F_133 ( V_301 ) ;
return V_301 ;
}
}
return NULL ;
}
void F_45 ( struct V_1 * V_2 )
{
F_130 ( V_2 ) ;
F_128 ( V_2 ) ;
if ( V_2 -> V_182 )
F_129 ( V_2 -> V_182 ) ;
}
