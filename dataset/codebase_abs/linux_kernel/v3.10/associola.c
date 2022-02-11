static struct V_1 * F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_5 * V_6 ,
T_1 V_7 ,
T_2 V_8 )
{
struct V_9 * V_9 = F_2 ( V_6 ) ;
struct V_10 * V_11 ;
int V_12 ;
T_3 * V_13 ;
int V_14 ;
V_11 = F_3 ( (struct V_5 * ) V_6 ) ;
V_2 -> V_4 = (struct V_3 * ) V_4 ;
F_4 ( V_2 -> V_4 ) ;
V_2 -> V_15 . V_6 = (struct V_5 * ) V_6 ;
F_5 ( V_2 -> V_15 . V_6 ) ;
V_2 -> V_15 . type = V_16 ;
F_6 ( & V_2 -> V_15 . V_17 , 1 ) ;
V_2 -> V_15 . V_18 = false ;
F_7 ( & V_2 -> V_15 . V_19 , V_4 -> V_15 . V_19 . V_20 ) ;
V_2 -> V_21 = V_22 ;
V_2 -> V_23 . V_24 = V_11 -> V_25 . V_26 / 1000 ;
V_2 -> V_23 . V_27 = ( V_11 -> V_25 . V_26 % 1000 )
* 1000 ;
V_2 -> V_28 = 0 ;
V_2 -> V_29 = V_11 -> V_29 ;
V_2 -> V_30 = V_11 -> V_25 . V_31 ;
V_2 -> V_32 = V_9 -> V_33 . V_32 ;
V_2 -> V_34 = F_8 ( V_11 -> V_35 . V_36 ) ;
V_2 -> V_37 = F_8 ( V_11 -> V_35 . V_38 ) ;
V_2 -> V_39 = F_8 ( V_11 -> V_35 . V_40 ) ;
V_2 -> V_41 = 0 ;
V_2 -> V_42 = F_8 ( V_11 -> V_42 ) ;
V_2 -> V_43 = V_11 -> V_43 ;
V_2 -> V_44 = V_11 -> V_44 ;
V_2 -> V_45 = F_8 ( V_11 -> V_45 ) ;
V_2 -> V_46 = V_11 -> V_46 ;
V_2 -> V_47 = V_11 -> V_47 ;
V_2 -> V_48 = V_11 -> V_48 ;
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
F_9 (unsigned long, sp->autoclose, net->sctp.max_autoclose) * V_60 ;
for ( V_12 = V_50 ; V_12 < V_61 ; ++ V_12 )
F_10 ( & V_2 -> V_62 [ V_12 ] , V_63 [ V_12 ] ,
( unsigned long ) V_2 ) ;
V_2 -> V_64 . V_65 = V_11 -> V_66 . V_65 ;
V_2 -> V_64 . V_67 = V_11 -> V_66 . V_67 ;
V_2 -> V_68 = V_11 -> V_66 . V_69 ;
V_2 -> V_70 =
F_8 ( V_11 -> V_66 . V_71 ) ;
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
F_6 ( & V_2 -> V_82 , 0 ) ;
F_11 ( & V_2 -> V_83 ) ;
V_2 -> V_64 . V_84 = F_12 ( V_4 ) ;
V_2 -> V_79 . V_12 . V_85 = 0 ;
V_2 -> V_64 . V_86 = 0 ;
V_2 -> V_64 . V_87 = 0 ;
V_2 -> V_64 . V_88 = 0 ;
V_2 -> V_64 . V_89 = V_4 -> V_15 . V_19 . V_20 ;
V_2 -> V_64 . V_90 = F_13 ( V_4 ) ;
V_2 -> V_91 = V_2 -> V_64 . V_90 ;
V_2 -> V_92 = V_2 -> V_91 - 1 ;
V_2 -> V_93 = V_2 -> V_92 ;
V_2 -> V_94 = V_2 -> V_92 ;
V_2 -> V_95 = V_2 -> V_92 ;
V_2 -> V_96 = 0 ;
V_2 -> V_97 = V_2 -> V_64 . V_90 ;
F_14 ( & V_2 -> V_98 ) ;
F_14 ( & V_2 -> V_99 ) ;
F_14 ( & V_2 -> V_79 . V_100 ) ;
V_2 -> V_79 . V_101 = 0 ;
V_2 -> V_79 . V_102 = 1 ;
V_2 -> V_79 . V_103 = 0 ;
V_2 -> V_79 . V_104 = 1 ;
V_2 -> V_79 . V_105 = 0 ;
if ( V_9 -> V_33 . V_106 )
V_2 -> V_79 . V_105 = 1 ;
V_2 -> V_107 = NULL ;
V_2 -> V_108 = 0 ;
V_2 -> V_109 = NULL ;
F_15 ( & V_2 -> V_15 . V_110 ) ;
F_16 ( & V_2 -> V_15 . V_110 , V_111 ) ;
F_17 ( V_2 , & V_2 -> V_112 ) ;
if ( ! F_18 ( & V_2 -> V_113 , V_2 ) )
goto V_114;
memset ( & V_2 -> V_79 . V_115 , 0 , sizeof( struct V_116 ) ) ;
V_2 -> V_117 = 0 ;
V_2 -> V_118 = 0 ;
V_2 -> V_79 . V_119 = 1 ;
if ( V_2 -> V_15 . V_6 -> V_120 == V_121 )
V_2 -> V_79 . V_122 = 1 ;
F_14 ( & V_2 -> V_123 ) ;
V_2 -> V_124 = V_11 -> V_124 ;
V_2 -> V_125 = V_11 -> V_125 ;
V_2 -> V_126 = V_11 -> V_126 ;
V_2 -> V_127 = V_11 -> V_127 ;
V_2 -> V_128 = V_11 -> V_128 ;
V_2 -> V_129 = V_11 -> V_129 ;
V_2 -> V_130 = V_11 -> V_130 ;
memset ( & V_2 -> V_131 , 0 , sizeof( struct V_132 ) ) ;
F_14 ( & V_2 -> V_133 ) ;
V_14 = F_19 ( V_4 , V_2 , V_8 ) ;
if ( V_14 )
goto V_114;
V_2 -> V_134 = V_4 -> V_134 ;
V_2 -> V_135 = NULL ;
V_2 -> V_136 = 0 ;
if ( V_4 -> V_137 )
memcpy ( V_2 -> V_64 . V_138 , V_4 -> V_137 ,
F_20 ( V_4 -> V_137 -> V_139 . V_140 ) ) ;
if ( V_4 -> V_141 )
memcpy ( V_2 -> V_64 . V_142 , V_4 -> V_141 ,
F_20 ( V_4 -> V_141 -> V_139 . V_140 ) ) ;
V_13 = ( T_3 * ) V_2 -> V_64 . V_143 ;
V_13 -> type = V_144 ;
V_13 -> V_140 = F_21 ( sizeof( T_3 ) + V_145 ) ;
F_22 ( V_13 + 1 , V_145 ) ;
return V_2 ;
V_114:
F_23 ( V_2 -> V_4 ) ;
F_24 ( V_2 -> V_15 . V_6 ) ;
return NULL ;
}
struct V_1 * F_25 ( const struct V_3 * V_4 ,
const struct V_5 * V_6 ,
T_1 V_7 ,
T_2 V_8 )
{
struct V_1 * V_2 ;
V_2 = F_26 ( struct V_1 , V_8 ) ;
if ( ! V_2 )
goto V_146;
if ( ! F_1 ( V_2 , V_4 , V_6 , V_7 , V_8 ) )
goto V_114;
F_27 ( V_147 ) ;
F_28 ( L_1 , V_2 ) ;
return V_2 ;
V_114:
F_29 ( V_2 ) ;
V_146:
return NULL ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_15 . V_6 ;
struct V_148 * V_149 ;
struct V_150 * V_151 , * V_152 ;
int V_12 ;
if ( ! V_2 -> V_152 ) {
F_31 ( & V_2 -> V_123 ) ;
if ( F_32 ( V_6 , V_153 ) && F_33 ( V_6 , V_154 ) )
V_6 -> V_155 -- ;
}
V_2 -> V_15 . V_18 = true ;
F_34 ( & V_2 -> V_112 ) ;
F_35 ( & V_2 -> V_113 ) ;
F_36 ( & V_2 -> V_15 . V_110 ) ;
F_37 ( & V_2 -> V_79 . V_115 ) ;
F_38 ( V_2 -> V_72 ) ;
F_39 ( & V_2 -> V_15 . V_19 ) ;
for ( V_12 = V_50 ; V_12 < V_61 ; ++ V_12 ) {
if ( F_40 ( & V_2 -> V_62 [ V_12 ] ) )
F_41 ( V_2 ) ;
}
F_29 ( V_2 -> V_79 . V_156 ) ;
F_29 ( V_2 -> V_79 . V_157 ) ;
F_29 ( V_2 -> V_79 . V_158 ) ;
F_29 ( V_2 -> V_79 . V_159 ) ;
F_42 (pos, temp, &asoc->peer.transport_addr_list) {
V_149 = F_43 ( V_151 , struct V_148 , V_160 ) ;
F_44 ( V_151 ) ;
F_45 ( V_149 ) ;
}
V_2 -> V_79 . V_101 = 0 ;
F_46 ( V_2 ) ;
if ( V_2 -> V_107 != NULL )
F_29 ( V_2 -> V_107 ) ;
F_47 ( & V_2 -> V_133 ) ;
F_48 ( V_2 -> V_135 ) ;
F_41 ( V_2 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_50 (asoc->base.dead, L_2 , return) ;
F_23 ( V_2 -> V_4 ) ;
F_24 ( V_2 -> V_15 . V_6 ) ;
if ( V_2 -> V_118 != 0 ) {
F_51 ( & V_161 ) ;
F_52 ( & V_162 , V_2 -> V_118 ) ;
F_53 ( & V_161 ) ;
}
F_54 ( F_55 ( & V_2 -> V_82 ) ) ;
F_29 ( V_2 ) ;
F_56 ( V_147 ) ;
}
void F_57 ( struct V_1 * V_2 ,
struct V_148 * V_149 )
{
int V_163 = 0 ;
if ( V_2 -> V_79 . V_164 != NULL &&
V_2 -> V_79 . V_164 != V_149 )
V_163 = 1 ;
V_2 -> V_79 . V_164 = V_149 ;
memcpy ( & V_2 -> V_79 . V_165 , & V_149 -> V_166 ,
sizeof( union V_167 ) ) ;
if ( ( V_149 -> V_21 == V_168 ) ||
( V_149 -> V_21 == V_169 ) )
V_2 -> V_79 . V_170 = V_149 ;
if ( ! V_2 -> V_112 . V_171 && ! V_2 -> V_112 . V_172 )
return;
if ( V_149 -> V_173 . V_174 )
V_149 -> V_173 . V_175 = V_163 ;
V_149 -> V_173 . V_174 = V_163 ;
V_149 -> V_173 . V_176 = V_2 -> V_91 ;
}
void F_58 ( struct V_1 * V_2 ,
struct V_148 * V_79 )
{
struct V_150 * V_151 ;
struct V_148 * V_149 ;
F_59 ( L_3 ,
L_4 ,
V_2 ,
( & V_79 -> V_166 ) ,
F_20 ( V_79 -> V_166 . V_177 . V_178 ) ) ;
if ( V_2 -> V_79 . V_179 == V_79 )
F_60 ( V_2 ) ;
F_44 ( & V_79 -> V_160 ) ;
V_151 = V_2 -> V_79 . V_100 . V_180 ;
V_149 = F_43 ( V_151 , struct V_148 , V_160 ) ;
if ( V_2 -> V_79 . V_164 == V_79 )
F_57 ( V_2 , V_149 ) ;
if ( V_2 -> V_79 . V_170 == V_79 )
V_2 -> V_79 . V_170 = V_149 ;
if ( V_2 -> V_79 . V_179 == V_79 )
V_2 -> V_79 . V_179 = V_149 ;
if ( V_2 -> V_79 . V_181 == V_79 )
V_2 -> V_79 . V_181 = V_149 ;
if ( V_2 -> V_182 == V_79 )
V_2 -> V_182 = NULL ;
if ( V_2 -> V_183 == V_79 )
V_2 -> V_183 = NULL ;
if ( V_2 -> V_184 &&
V_2 -> V_184 -> V_149 == V_79 )
V_2 -> V_184 -> V_149 = NULL ;
if ( ! F_61 ( & V_79 -> V_185 ) ) {
struct V_148 * V_186 = V_2 -> V_79 . V_170 ;
struct V_187 * V_188 ;
F_62 (ch, &peer->transmitted,
transmitted_list) {
V_188 -> V_149 = NULL ;
V_188 -> V_189 = 0 ;
}
F_63 ( & V_79 -> V_185 ,
& V_186 -> V_185 ) ;
if ( ! F_64 ( & V_186 -> V_190 ) )
if ( ! F_65 ( & V_186 -> V_190 ,
V_191 + V_186 -> V_192 ) )
F_66 ( V_186 ) ;
}
V_2 -> V_79 . V_101 -- ;
F_45 ( V_79 ) ;
}
struct V_148 * F_67 ( struct V_1 * V_2 ,
const union V_167 * V_193 ,
const T_2 V_8 ,
const int V_194 )
{
struct V_9 * V_9 = F_2 ( V_2 -> V_15 . V_6 ) ;
struct V_148 * V_79 ;
struct V_10 * V_11 ;
unsigned short V_20 ;
V_11 = F_3 ( V_2 -> V_15 . V_6 ) ;
V_20 = F_20 ( V_193 -> V_177 . V_178 ) ;
F_59 ( L_5 ,
L_6 ,
V_2 ,
V_193 ,
V_20 ,
V_194 ) ;
if ( 0 == V_2 -> V_79 . V_20 )
V_2 -> V_79 . V_20 = V_20 ;
V_79 = F_68 ( V_2 , V_193 ) ;
if ( V_79 ) {
if ( V_79 -> V_21 == V_169 ) {
V_79 -> V_21 = V_168 ;
}
return V_79 ;
}
V_79 = F_69 ( V_9 , V_193 , V_8 ) ;
if ( ! V_79 )
return NULL ;
F_70 ( V_79 , V_2 ) ;
V_79 -> V_42 = V_2 -> V_42 ;
V_79 -> V_43 = V_2 -> V_43 ;
V_79 -> V_32 = V_2 -> V_32 ;
V_79 -> V_45 = V_2 -> V_45 ;
V_79 -> V_46 = V_2 -> V_46 ;
V_79 -> V_47 = V_2 -> V_47 ;
F_71 ( V_79 , NULL , V_11 ) ;
if ( V_79 -> V_47 & V_195 ) {
if ( V_2 -> V_44 )
V_79 -> V_44 = V_2 -> V_44 ;
else
V_79 -> V_44 = V_196 ;
}
if ( V_2 -> V_44 )
V_2 -> V_44 = F_9 ( int , V_79 -> V_44 , V_2 -> V_44 ) ;
else
V_2 -> V_44 = V_79 -> V_44 ;
F_28 ( L_7
L_8 , V_2 , V_2 -> V_44 ) ;
V_79 -> V_197 = 0 ;
V_2 -> V_28 = F_72 ( V_2 , V_2 -> V_44 ) ;
F_73 ( & V_79 -> V_198 , V_79 , V_2 -> V_15 . V_19 . V_20 ,
V_2 -> V_79 . V_20 ) ;
V_79 -> V_199 = F_74 ( 4 * V_2 -> V_44 , F_75 ( V_200 , 2 * V_2 -> V_44 , 4380 ) ) ;
V_79 -> V_201 = V_80 ;
V_79 -> V_202 = 0 ;
V_79 -> V_203 = 0 ;
V_79 -> V_204 = 0 ;
V_79 -> V_192 = V_2 -> V_34 ;
F_76 ( V_2 , V_79 ) ;
V_79 -> V_21 = V_194 ;
F_77 ( & V_79 -> V_160 , & V_2 -> V_79 . V_100 ) ;
V_2 -> V_79 . V_101 ++ ;
if ( ! V_2 -> V_79 . V_164 ) {
F_57 ( V_2 , V_79 ) ;
V_2 -> V_79 . V_179 = V_79 ;
}
if ( V_2 -> V_79 . V_170 == V_2 -> V_79 . V_179 &&
V_79 -> V_21 != V_205 ) {
V_2 -> V_79 . V_179 = V_79 ;
}
return V_79 ;
}
void F_78 ( struct V_1 * V_2 ,
const union V_167 * V_193 )
{
struct V_150 * V_151 ;
struct V_150 * V_152 ;
struct V_148 * V_149 ;
F_42 (pos, temp, &asoc->peer.transport_addr_list) {
V_149 = F_43 ( V_151 , struct V_148 , V_160 ) ;
if ( F_79 ( V_193 , & V_149 -> V_166 ) ) {
F_58 ( V_2 , V_149 ) ;
break;
}
}
}
struct V_148 * F_68 (
const struct V_1 * V_2 ,
const union V_167 * V_206 )
{
struct V_148 * V_207 ;
F_62 (t, &asoc->peer.transport_addr_list,
transports) {
if ( F_79 ( V_206 , & V_207 -> V_166 ) )
return V_207 ;
}
return NULL ;
}
void F_80 ( struct V_1 * V_2 ,
struct V_148 * V_208 )
{
struct V_148 * V_152 ;
struct V_148 * V_207 ;
F_81 (t, temp, &asoc->peer.transport_addr_list,
transports) {
if ( V_207 != V_208 )
F_58 ( V_2 , V_207 ) ;
}
}
void F_82 ( struct V_1 * V_2 ,
struct V_148 * V_149 ,
T_4 V_209 ,
T_5 error )
{
struct V_148 * V_207 = NULL ;
struct V_148 * V_210 ;
struct V_148 * V_211 ;
struct V_212 * V_213 ;
struct V_214 V_193 ;
int V_215 = 0 ;
bool V_216 = true ;
switch ( V_209 ) {
case V_217 :
if ( V_205 == V_149 -> V_21 &&
V_218 == error )
V_215 = V_219 ;
else
V_215 = V_220 ;
if ( V_149 -> V_21 == V_221 ) {
V_216 = false ;
V_149 -> V_199 = 1 ;
}
V_149 -> V_21 = V_168 ;
break;
case V_222 :
if ( V_149 -> V_21 != V_205 )
V_149 -> V_21 = V_223 ;
else {
F_83 ( V_149 -> V_224 ) ;
V_149 -> V_224 = NULL ;
}
V_215 = V_225 ;
break;
case V_226 :
V_149 -> V_21 = V_221 ;
V_216 = false ;
break;
default:
return;
}
if ( V_216 ) {
memset ( & V_193 , 0 , sizeof( struct V_214 ) ) ;
memcpy ( & V_193 , & V_149 -> V_166 ,
V_149 -> V_227 -> V_228 ) ;
V_213 = F_84 ( V_2 , & V_193 ,
0 , V_215 , error , V_229 ) ;
if ( V_213 )
F_85 ( & V_2 -> V_113 , V_213 ) ;
}
V_210 = NULL ; V_211 = NULL ;
F_62 (t, &asoc->peer.transport_addr_list,
transports) {
if ( ( V_207 -> V_21 == V_223 ) ||
( V_207 -> V_21 == V_205 ) ||
( V_207 -> V_21 == V_221 ) )
continue;
if ( ! V_210 || V_207 -> V_230 > V_210 -> V_230 ) {
V_211 = V_210 ;
V_210 = V_207 ;
}
if ( ! V_211 || V_207 -> V_230 > V_211 -> V_230 )
V_211 = V_207 ;
}
if ( ( ( V_2 -> V_79 . V_164 -> V_21 == V_168 ) ||
( V_2 -> V_79 . V_164 -> V_21 == V_169 ) ) &&
V_210 != V_2 -> V_79 . V_164 ) {
V_211 = V_210 ;
V_210 = V_2 -> V_79 . V_164 ;
}
if ( ! V_210 ) {
V_210 = V_2 -> V_79 . V_164 ;
V_211 = V_2 -> V_79 . V_164 ;
}
V_2 -> V_79 . V_170 = V_210 ;
V_2 -> V_79 . V_179 = V_211 ;
}
void F_86 ( struct V_1 * V_2 )
{
F_87 ( & V_2 -> V_15 . V_17 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
if ( F_88 ( & V_2 -> V_15 . V_17 ) )
F_49 ( V_2 ) ;
}
V_200 F_89 ( struct V_1 * V_2 )
{
V_200 V_231 = V_2 -> V_91 ;
V_2 -> V_91 ++ ;
V_2 -> V_96 ++ ;
return V_231 ;
}
int F_79 ( const union V_167 * V_232 ,
const union V_167 * V_233 )
{
struct V_234 * V_235 ;
V_235 = F_90 ( V_232 -> V_236 . V_237 ) ;
if ( F_91 ( ! V_235 ) )
return 0 ;
return V_235 -> V_238 ( V_232 , V_233 ) ;
}
struct V_187 * F_92 ( struct V_1 * V_2 )
{
struct V_187 * V_239 ;
if ( V_2 -> V_117 )
V_239 = F_93 ( V_2 , V_2 -> V_240 ) ;
else
V_239 = NULL ;
return V_239 ;
}
struct V_148 * F_94 ( struct V_1 * V_2 ,
V_200 V_241 )
{
struct V_148 * V_186 ;
struct V_148 * V_242 ;
struct V_148 * V_149 ;
struct V_187 * V_239 ;
T_6 V_243 = F_95 ( V_241 ) ;
V_242 = NULL ;
V_186 = V_2 -> V_79 . V_170 ;
F_62 (chunk, &active->transmitted,
transmitted_list) {
if ( V_243 == V_239 -> V_244 . V_245 -> V_241 ) {
V_242 = V_186 ;
goto V_246;
}
}
F_62 (transport, &asoc->peer.transport_addr_list,
transports) {
if ( V_149 == V_186 )
continue;
F_62 (chunk, &transport->transmitted,
transmitted_list) {
if ( V_243 == V_239 -> V_244 . V_245 -> V_241 ) {
V_242 = V_149 ;
goto V_246;
}
}
}
V_246:
return V_242 ;
}
struct V_148 * F_96 ( struct V_1 * V_2 ,
struct V_9 * V_9 ,
const union V_167 * V_247 ,
const union V_167 * V_248 )
{
struct V_148 * V_149 ;
if ( ( F_21 ( V_2 -> V_15 . V_19 . V_20 ) == V_247 -> V_177 . V_178 ) &&
( F_21 ( V_2 -> V_79 . V_20 ) == V_248 -> V_177 . V_178 ) &&
F_97 ( F_2 ( V_2 -> V_15 . V_6 ) , V_9 ) ) {
V_149 = F_68 ( V_2 , V_248 ) ;
if ( ! V_149 )
goto V_246;
if ( F_98 ( & V_2 -> V_15 . V_19 , V_247 ,
F_3 ( V_2 -> V_15 . V_6 ) ) )
goto V_246;
}
V_149 = NULL ;
V_246:
return V_149 ;
}
static void V_111 ( struct V_249 * V_250 )
{
struct V_1 * V_2 =
F_99 ( V_250 , struct V_1 ,
V_15 . V_110 . V_251 ) ;
struct V_9 * V_9 = F_2 ( V_2 -> V_15 . V_6 ) ;
struct V_3 * V_4 ;
struct V_187 * V_239 ;
struct V_252 * V_110 ;
int V_21 ;
T_7 V_253 ;
int error = 0 ;
V_4 = V_2 -> V_4 ;
V_110 = & V_2 -> V_15 . V_110 ;
F_86 ( V_2 ) ;
while ( NULL != ( V_239 = F_100 ( V_110 ) ) ) {
V_21 = V_2 -> V_21 ;
V_253 = F_101 ( V_239 -> V_254 -> type ) ;
if ( F_102 ( V_253 . V_239 , V_2 ) && ! V_239 -> V_255 )
continue;
if ( F_103 ( V_239 ) )
V_2 -> V_79 . V_181 = V_239 -> V_149 ;
else {
F_104 ( V_9 , V_256 ) ;
V_2 -> V_131 . V_257 ++ ;
if ( V_239 -> V_254 -> type == V_258 )
V_2 -> V_131 . V_259 ++ ;
}
if ( V_239 -> V_149 )
V_239 -> V_149 -> V_230 = V_191 ;
error = F_105 ( V_9 , V_260 , V_253 ,
V_21 , V_4 , V_2 , V_239 , V_229 ) ;
if ( V_2 -> V_15 . V_18 )
break;
if ( error && V_239 )
V_239 -> V_261 = 1 ;
}
F_41 ( V_2 ) ;
}
void F_106 ( struct V_1 * V_147 , struct V_5 * V_262 )
{
struct V_10 * V_263 = F_3 ( V_262 ) ;
struct V_5 * V_264 = V_147 -> V_15 . V_6 ;
F_107 ( & V_147 -> V_123 ) ;
if ( F_32 ( V_264 , V_153 ) )
V_264 -> V_155 -- ;
F_23 ( V_147 -> V_4 ) ;
F_24 ( V_147 -> V_15 . V_6 ) ;
V_147 -> V_4 = V_263 -> V_4 ;
F_4 ( V_147 -> V_4 ) ;
V_147 -> V_15 . V_6 = V_262 ;
F_5 ( V_147 -> V_15 . V_6 ) ;
F_108 ( V_263 -> V_4 , V_147 ) ;
}
void F_109 ( struct V_1 * V_2 ,
struct V_1 * V_265 )
{
struct V_148 * V_266 ;
struct V_150 * V_151 , * V_152 ;
V_2 -> V_64 = V_265 -> V_64 ;
V_2 -> V_79 . V_75 = V_265 -> V_79 . V_75 ;
V_2 -> V_79 . V_102 = V_265 -> V_79 . V_102 ;
V_2 -> V_79 . V_12 = V_265 -> V_79 . V_12 ;
F_110 ( & V_2 -> V_79 . V_115 , V_267 ,
V_2 -> V_79 . V_12 . V_90 , V_229 ) ;
F_42 (pos, temp, &asoc->peer.transport_addr_list) {
V_266 = F_43 ( V_151 , struct V_148 , V_160 ) ;
if ( ! F_68 ( V_265 , & V_266 -> V_166 ) ) {
F_58 ( V_2 , V_266 ) ;
continue;
}
if ( V_2 -> V_21 >= V_268 )
F_111 ( V_266 ) ;
}
if ( V_2 -> V_21 >= V_268 ) {
V_2 -> V_91 = V_265 -> V_91 ;
V_2 -> V_92 = V_265 -> V_92 ;
V_2 -> V_93 = V_265 -> V_93 ;
F_112 ( V_2 -> V_72 ) ;
F_113 ( & V_2 -> V_113 ) ;
V_2 -> V_41 = 0 ;
} else {
F_62 (trans, &new->peer.transport_addr_list,
transports) {
if ( ! F_68 ( V_2 , & V_266 -> V_166 ) )
F_67 ( V_2 , & V_266 -> V_166 ,
V_229 , V_266 -> V_21 ) ;
}
V_2 -> V_92 = V_2 -> V_91 - 1 ;
V_2 -> V_93 = V_2 -> V_92 ;
if ( ! V_2 -> V_72 ) {
V_2 -> V_72 = V_265 -> V_72 ;
V_265 -> V_72 = NULL ;
}
if ( ! V_2 -> V_118 ) {
F_114 ( V_2 , V_229 ) ;
}
}
F_29 ( V_2 -> V_79 . V_157 ) ;
V_2 -> V_79 . V_157 = V_265 -> V_79 . V_157 ;
V_265 -> V_79 . V_157 = NULL ;
F_29 ( V_2 -> V_79 . V_158 ) ;
V_2 -> V_79 . V_158 = V_265 -> V_79 . V_158 ;
V_265 -> V_79 . V_158 = NULL ;
F_29 ( V_2 -> V_79 . V_159 ) ;
V_2 -> V_79 . V_159 = V_265 -> V_79 . V_159 ;
V_265 -> V_79 . V_159 = NULL ;
F_48 ( V_2 -> V_135 ) ;
F_115 ( V_2 , V_229 ) ;
}
void F_60 ( struct V_1 * V_2 )
{
struct V_148 * V_207 , * V_180 ;
struct V_150 * V_269 = & V_2 -> V_79 . V_100 ;
struct V_150 * V_151 ;
if ( V_2 -> V_79 . V_101 == 1 )
return;
V_207 = V_2 -> V_79 . V_179 ;
V_151 = & V_207 -> V_160 ;
V_180 = NULL ;
while ( 1 ) {
if ( V_151 -> V_180 == V_269 )
V_151 = V_269 -> V_180 ;
else
V_151 = V_151 -> V_180 ;
V_207 = F_43 ( V_151 , struct V_148 , V_160 ) ;
if ( V_207 == V_2 -> V_79 . V_179 ) {
V_207 = V_180 ;
break;
}
if ( ( V_207 -> V_21 == V_168 ) ||
( V_207 -> V_21 == V_169 ) ) {
break;
} else {
if ( V_207 -> V_21 != V_205 && ! V_180 )
V_180 = V_207 ;
}
}
if ( V_207 )
V_2 -> V_79 . V_179 = V_207 ;
else
V_207 = V_2 -> V_79 . V_179 ;
F_59 ( L_9
L_10 ,
L_4 ,
V_2 ,
( & V_207 -> V_166 ) ,
F_20 ( V_207 -> V_166 . V_177 . V_178 ) ) ;
}
struct V_148 * F_116 (
struct V_1 * V_2 , struct V_148 * V_270 )
{
if ( ! V_270 )
return V_2 -> V_79 . V_170 ;
else {
if ( V_270 == V_2 -> V_79 . V_179 )
F_60 ( V_2 ) ;
return V_2 -> V_79 . V_179 ;
}
}
void F_117 ( struct V_5 * V_6 , struct V_1 * V_2 )
{
struct V_148 * V_207 ;
V_200 V_271 = 0 ;
if ( ! V_2 )
return;
F_62 (t, &asoc->peer.transport_addr_list,
transports) {
if ( V_207 -> V_197 && V_207 -> V_224 ) {
F_118 ( V_6 , V_207 , F_119 ( V_207 -> V_224 ) ) ;
V_207 -> V_197 = 0 ;
}
if ( ! V_271 || ( V_207 -> V_44 < V_271 ) )
V_271 = V_207 -> V_44 ;
}
if ( V_271 ) {
V_2 -> V_44 = V_271 ;
V_2 -> V_28 = F_72 ( V_2 , V_271 ) ;
}
F_28 ( L_11 ,
V_272 , V_2 , V_2 -> V_44 , V_2 -> V_28 ) ;
}
static inline int F_120 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_2 ( V_2 -> V_15 . V_6 ) ;
switch ( V_2 -> V_21 ) {
case V_268 :
case V_273 :
case V_274 :
case V_275 :
if ( ( V_2 -> V_75 > V_2 -> V_76 ) &&
( ( V_2 -> V_75 - V_2 -> V_76 ) >= F_75 ( V_200 ,
( V_2 -> V_15 . V_6 -> V_73 >> V_9 -> V_33 . V_276 ) ,
V_2 -> V_44 ) ) )
return 1 ;
break;
default:
break;
}
return 0 ;
}
void F_121 ( struct V_1 * V_2 , unsigned int V_277 )
{
struct V_187 * V_278 ;
struct V_279 * V_280 ;
if ( V_2 -> V_77 ) {
if ( V_2 -> V_77 >= V_277 ) {
V_2 -> V_77 -= V_277 ;
} else {
V_2 -> V_75 += ( V_277 - V_2 -> V_77 ) ;
V_2 -> V_77 = 0 ;
}
} else {
V_2 -> V_75 += V_277 ;
}
if ( V_2 -> V_78 && V_2 -> V_75 >= V_2 -> V_78 ) {
int V_281 = F_74 ( V_2 -> V_44 , V_2 -> V_78 ) ;
V_2 -> V_75 += V_281 ;
V_2 -> V_78 -= V_281 ;
}
F_28 ( L_12
L_13 , V_272 , V_2 , V_277 , V_2 -> V_75 ,
V_2 -> V_77 , V_2 -> V_76 ) ;
if ( F_120 ( V_2 ) ) {
V_2 -> V_76 = V_2 -> V_75 ;
F_28 ( L_14
L_15 , V_272 ,
V_2 , V_2 -> V_75 , V_2 -> V_76 ) ;
V_278 = F_122 ( V_2 ) ;
if ( ! V_278 )
return;
V_2 -> V_79 . V_102 = 0 ;
F_123 ( & V_2 -> V_112 , V_278 ) ;
V_280 = & V_2 -> V_62 [ V_58 ] ;
if ( F_40 ( V_280 ) )
F_41 ( V_2 ) ;
}
}
void F_124 ( struct V_1 * V_2 , unsigned int V_277 )
{
int V_282 ;
int V_283 = 0 ;
F_50 (asoc->rwnd, L_16 , return) ;
F_50 (!asoc->rwnd_over, L_17 , return) ;
if ( V_2 -> V_4 -> V_284 )
V_282 = F_55 ( & V_2 -> V_82 ) ;
else
V_282 = F_55 ( & V_2 -> V_15 . V_6 -> V_285 ) ;
if ( V_282 >= V_2 -> V_15 . V_6 -> V_73 )
V_283 = 1 ;
if ( V_2 -> V_75 >= V_277 ) {
V_2 -> V_75 -= V_277 ;
if ( V_283 ) {
V_2 -> V_78 += V_2 -> V_75 ;
V_2 -> V_75 = 0 ;
}
} else {
V_2 -> V_77 = V_277 - V_2 -> V_75 ;
V_2 -> V_75 = 0 ;
}
F_28 ( L_18 ,
V_272 , V_2 , V_277 , V_2 -> V_75 ,
V_2 -> V_77 , V_2 -> V_78 ) ;
}
int F_125 ( struct V_1 * V_2 ,
T_1 V_7 , T_2 V_8 )
{
int V_286 ;
V_286 = ( V_121 == V_2 -> V_15 . V_6 -> V_120 ) ? V_287 : 0 ;
if ( V_2 -> V_79 . V_119 )
V_286 |= V_288 ;
if ( V_2 -> V_79 . V_122 )
V_286 |= V_289 ;
return F_126 ( F_2 ( V_2 -> V_15 . V_6 ) ,
& V_2 -> V_15 . V_19 ,
& V_2 -> V_4 -> V_15 . V_19 ,
V_7 , V_8 , V_286 ) ;
}
int F_127 ( struct V_1 * V_2 ,
struct V_290 * V_156 ,
T_2 V_8 )
{
int V_291 = F_20 ( V_156 -> V_292 -> V_254 . V_140 ) ;
int V_293 = V_156 -> V_294 ;
T_8 * V_295 = ( T_8 * ) V_156 -> V_292 + V_291 ;
return F_128 ( & V_2 -> V_15 . V_19 , V_295 , V_293 ,
V_2 -> V_4 -> V_15 . V_19 . V_20 , V_8 ) ;
}
int F_129 ( struct V_1 * V_2 ,
const union V_167 * V_247 )
{
int V_296 = 0 ;
if ( ( V_2 -> V_15 . V_19 . V_20 == F_20 ( V_247 -> V_177 . V_178 ) ) &&
F_98 ( & V_2 -> V_15 . V_19 , V_247 ,
F_3 ( V_2 -> V_15 . V_6 ) ) )
V_296 = 1 ;
return V_296 ;
}
int F_114 ( struct V_1 * V_2 , T_2 V_8 )
{
bool V_297 = V_8 & V_298 ;
int V_299 ;
if ( V_2 -> V_118 )
return 0 ;
if ( V_297 )
F_130 ( V_8 ) ;
F_51 ( & V_161 ) ;
V_299 = F_131 ( & V_162 , V_2 , 1 , 0 , V_300 ) ;
F_53 ( & V_161 ) ;
if ( V_297 )
F_132 () ;
if ( V_299 < 0 )
return V_299 ;
V_2 -> V_118 = ( V_301 ) V_299 ;
return 0 ;
}
static void F_133 ( struct V_1 * V_2 )
{
struct V_187 * V_302 ;
struct V_187 * V_303 ;
F_81 (asconf, tmp, &asoc->addip_chunk_list, list) {
F_107 ( & V_302 -> V_304 ) ;
F_134 ( V_302 ) ;
}
}
static void F_135 ( struct V_1 * V_2 )
{
struct V_187 * V_305 ;
struct V_187 * V_303 ;
F_81 (ack, tmp, &asoc->asconf_ack_list,
transmitted_list) {
F_107 ( & V_305 -> V_306 ) ;
F_134 ( V_305 ) ;
}
}
void F_136 ( const struct V_1 * V_2 )
{
struct V_187 * V_305 ;
struct V_187 * V_303 ;
F_81 (ack, tmp, &asoc->asconf_ack_list,
transmitted_list) {
if ( V_305 -> V_244 . V_307 -> V_308 ==
F_95 ( V_2 -> V_79 . V_97 ) )
break;
F_107 ( & V_305 -> V_306 ) ;
F_134 ( V_305 ) ;
}
}
struct V_187 * F_137 (
const struct V_1 * V_2 ,
T_6 V_308 )
{
struct V_187 * V_305 ;
F_62 (ack, &asoc->asconf_ack_list, transmitted_list) {
if ( V_305 -> V_244 . V_307 -> V_308 == V_308 ) {
F_138 ( V_305 ) ;
return V_305 ;
}
}
return NULL ;
}
void F_46 ( struct V_1 * V_2 )
{
F_135 ( V_2 ) ;
F_133 ( V_2 ) ;
if ( V_2 -> V_184 )
F_134 ( V_2 -> V_184 ) ;
}
