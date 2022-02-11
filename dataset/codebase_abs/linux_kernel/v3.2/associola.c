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
V_2 -> V_32 = F_7 ( V_10 -> V_33 . V_34 ) ;
V_2 -> V_35 = F_7 ( V_10 -> V_33 . V_36 ) ;
V_2 -> V_37 = F_7 ( V_10 -> V_33 . V_38 ) ;
V_2 -> V_39 = 0 ;
V_2 -> V_40 = F_7 ( V_10 -> V_40 ) ;
V_2 -> V_41 = V_10 -> V_41 ;
V_2 -> V_42 = V_10 -> V_42 ;
V_2 -> V_43 = F_7 ( V_10 -> V_43 ) ;
V_2 -> V_44 = V_10 -> V_44 ;
V_2 -> V_45 = V_10 -> V_45 ;
V_2 -> V_46 = V_10 -> V_46 ;
V_2 -> V_47 [ V_48 ] = 0 ;
V_2 -> V_47 [ V_49 ] = V_2 -> V_32 ;
V_2 -> V_47 [ V_50 ] = V_2 -> V_32 ;
V_2 -> V_47 [ V_51 ] = V_2 -> V_32 ;
V_2 -> V_47 [ V_52 ] = 0 ;
V_2 -> V_47 [ V_53 ] = 0 ;
V_2 -> V_47 [ V_54 ]
= 5 * V_2 -> V_35 ;
V_2 -> V_47 [ V_55 ] = 0 ;
V_2 -> V_47 [ V_56 ] = V_2 -> V_43 ;
V_2 -> V_47 [ V_57 ] =
F_8 (unsigned long, sp->autoclose, sctp_max_autoclose) * V_58 ;
for ( V_11 = V_48 ; V_11 < V_59 ; ++ V_11 )
F_9 ( & V_2 -> V_60 [ V_11 ] , V_61 [ V_11 ] ,
( unsigned long ) V_2 ) ;
V_2 -> V_62 . V_63 = V_10 -> V_64 . V_63 ;
V_2 -> V_62 . V_65 = V_10 -> V_64 . V_65 ;
V_2 -> V_66 = V_10 -> V_64 . V_67 ;
V_2 -> V_68 =
F_7 ( V_10 -> V_64 . V_69 ) ;
V_2 -> V_70 = NULL ;
if ( ( V_6 -> V_71 / 2 ) < V_72 )
V_2 -> V_73 = V_72 ;
else
V_2 -> V_73 = V_6 -> V_71 / 2 ;
V_2 -> V_74 = V_2 -> V_73 ;
V_2 -> V_75 = 0 ;
V_2 -> V_76 = 0 ;
V_2 -> V_77 . V_73 = V_78 ;
V_2 -> V_79 = 0 ;
F_5 ( & V_2 -> V_80 , 0 ) ;
F_10 ( & V_2 -> V_81 ) ;
V_2 -> V_62 . V_82 = F_11 ( V_4 ) ;
V_2 -> V_77 . V_11 . V_83 = 0 ;
V_2 -> V_62 . V_84 = 0 ;
V_2 -> V_62 . V_85 = 0 ;
V_2 -> V_62 . V_86 = 0 ;
V_2 -> V_62 . V_87 = V_4 -> V_14 . V_19 . V_20 ;
V_2 -> V_62 . V_88 = F_12 ( V_4 ) ;
V_2 -> V_89 = V_2 -> V_62 . V_88 ;
V_2 -> V_90 = V_2 -> V_89 - 1 ;
V_2 -> V_91 = V_2 -> V_90 ;
V_2 -> V_92 = V_2 -> V_90 ;
V_2 -> V_93 = V_2 -> V_90 ;
V_2 -> V_94 = 0 ;
V_2 -> V_95 = V_2 -> V_62 . V_88 ;
F_13 ( & V_2 -> V_96 ) ;
F_13 ( & V_2 -> V_97 ) ;
F_13 ( & V_2 -> V_77 . V_98 ) ;
V_2 -> V_77 . V_99 = 0 ;
V_2 -> V_77 . V_100 = 1 ;
V_2 -> V_77 . V_101 = 0 ;
V_2 -> V_77 . V_102 = 0 ;
if ( V_103 )
V_2 -> V_77 . V_102 = 1 ;
V_2 -> V_104 = NULL ;
V_2 -> V_105 = 0 ;
V_2 -> V_106 = NULL ;
F_14 ( & V_2 -> V_14 . V_107 ) ;
F_15 ( & V_2 -> V_14 . V_107 , V_108 ) ;
F_16 ( V_2 , & V_2 -> V_109 ) ;
if ( ! F_17 ( & V_2 -> V_110 , V_2 ) )
goto V_111;
memset ( & V_2 -> V_77 . V_112 , 0 , sizeof( struct V_113 ) ) ;
V_2 -> V_114 = 0 ;
V_2 -> V_115 = 0 ;
V_2 -> V_77 . V_116 = 1 ;
if ( V_2 -> V_14 . V_6 -> V_117 == V_118 )
V_2 -> V_77 . V_119 = 1 ;
F_13 ( & V_2 -> V_120 ) ;
V_2 -> V_121 = V_10 -> V_121 ;
V_2 -> V_122 = V_10 -> V_122 ;
V_2 -> V_123 = V_10 -> V_123 ;
V_2 -> V_124 = V_10 -> V_124 ;
V_2 -> V_125 = V_10 -> V_125 ;
V_2 -> V_126 = V_10 -> V_126 ;
V_2 -> V_127 = V_10 -> V_127 ;
F_13 ( & V_2 -> V_128 ) ;
V_13 = F_18 ( V_4 , V_2 , V_8 ) ;
if ( V_13 )
goto V_111;
V_2 -> V_129 = V_4 -> V_129 ;
V_2 -> V_130 = NULL ;
V_2 -> V_131 = 0 ;
if ( V_4 -> V_132 )
memcpy ( V_2 -> V_62 . V_133 , V_4 -> V_132 ,
F_19 ( V_4 -> V_132 -> V_134 . V_135 ) ) ;
if ( V_4 -> V_136 )
memcpy ( V_2 -> V_62 . V_137 , V_4 -> V_136 ,
F_19 ( V_4 -> V_136 -> V_134 . V_135 ) ) ;
V_12 = ( T_3 * ) V_2 -> V_62 . V_138 ;
V_12 -> type = V_139 ;
V_12 -> V_135 = F_20 ( sizeof( T_3 ) + V_140 ) ;
F_21 ( V_12 + 1 , V_140 ) ;
return V_2 ;
V_111:
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
goto V_141;
if ( ! F_1 ( V_2 , V_4 , V_6 , V_7 , V_8 ) )
goto V_111;
V_2 -> V_14 . V_18 = 1 ;
F_26 ( V_142 ) ;
F_27 ( L_1 , V_2 ) ;
return V_2 ;
V_111:
F_28 ( V_2 ) ;
V_141:
return NULL ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_14 . V_6 ;
struct V_143 * V_144 ;
struct V_145 * V_146 , * V_147 ;
int V_11 ;
if ( ! V_2 -> V_147 ) {
F_30 ( & V_2 -> V_120 ) ;
if ( F_31 ( V_6 , V_148 ) && F_32 ( V_6 , V_149 ) )
V_6 -> V_150 -- ;
}
V_2 -> V_14 . V_17 = 1 ;
F_33 ( & V_2 -> V_109 ) ;
F_34 ( & V_2 -> V_110 ) ;
F_35 ( & V_2 -> V_14 . V_107 ) ;
F_36 ( & V_2 -> V_77 . V_112 ) ;
F_37 ( V_2 -> V_70 ) ;
F_38 ( & V_2 -> V_14 . V_19 ) ;
for ( V_11 = V_48 ; V_11 < V_59 ; ++ V_11 ) {
if ( F_39 ( & V_2 -> V_60 [ V_11 ] ) &&
F_40 ( & V_2 -> V_60 [ V_11 ] ) )
F_41 ( V_2 ) ;
}
F_28 ( V_2 -> V_77 . V_151 ) ;
F_28 ( V_2 -> V_77 . V_152 ) ;
F_28 ( V_2 -> V_77 . V_153 ) ;
F_28 ( V_2 -> V_77 . V_154 ) ;
F_42 (pos, temp, &asoc->peer.transport_addr_list) {
V_144 = F_43 ( V_146 , struct V_143 , V_155 ) ;
F_30 ( V_146 ) ;
F_44 ( V_144 ) ;
}
V_2 -> V_77 . V_99 = 0 ;
F_45 ( V_2 ) ;
if ( V_2 -> V_104 != NULL )
F_28 ( V_2 -> V_104 ) ;
F_46 ( & V_2 -> V_128 ) ;
F_47 ( V_2 -> V_130 ) ;
F_41 ( V_2 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_49 (asoc->base.dead, L_2 , return) ;
F_22 ( V_2 -> V_4 ) ;
F_23 ( V_2 -> V_14 . V_6 ) ;
if ( V_2 -> V_115 != 0 ) {
F_50 ( & V_156 ) ;
F_51 ( & V_157 , V_2 -> V_115 ) ;
F_52 ( & V_156 ) ;
}
F_53 ( F_54 ( & V_2 -> V_80 ) ) ;
if ( V_2 -> V_14 . V_18 ) {
F_28 ( V_2 ) ;
F_55 ( V_142 ) ;
}
}
void F_56 ( struct V_1 * V_2 ,
struct V_143 * V_144 )
{
int V_158 = 0 ;
if ( V_2 -> V_77 . V_159 != NULL &&
V_2 -> V_77 . V_159 != V_144 )
V_158 = 1 ;
V_2 -> V_77 . V_159 = V_144 ;
memcpy ( & V_2 -> V_77 . V_160 , & V_144 -> V_161 ,
sizeof( union V_162 ) ) ;
if ( ( V_144 -> V_21 == V_163 ) ||
( V_144 -> V_21 == V_164 ) )
V_2 -> V_77 . V_165 = V_144 ;
if ( ! V_2 -> V_109 . V_166 && ! V_2 -> V_109 . V_167 )
return;
if ( V_144 -> V_168 . V_169 )
V_144 -> V_168 . V_170 = V_158 ;
V_144 -> V_168 . V_169 = V_158 ;
V_144 -> V_168 . V_171 = V_2 -> V_89 ;
}
void F_57 ( struct V_1 * V_2 ,
struct V_143 * V_77 )
{
struct V_145 * V_146 ;
struct V_143 * V_144 ;
F_58 ( L_3 ,
L_4 ,
V_2 ,
( & V_77 -> V_161 ) ,
F_19 ( V_77 -> V_161 . V_172 . V_173 ) ) ;
if ( V_2 -> V_77 . V_174 == V_77 )
F_59 ( V_2 ) ;
F_30 ( & V_77 -> V_155 ) ;
V_146 = V_2 -> V_77 . V_98 . V_175 ;
V_144 = F_43 ( V_146 , struct V_143 , V_155 ) ;
if ( V_2 -> V_77 . V_159 == V_77 )
F_56 ( V_2 , V_144 ) ;
if ( V_2 -> V_77 . V_165 == V_77 )
V_2 -> V_77 . V_165 = V_144 ;
if ( V_2 -> V_77 . V_174 == V_77 )
V_2 -> V_77 . V_174 = V_144 ;
if ( V_2 -> V_77 . V_176 == V_77 )
V_2 -> V_77 . V_176 = V_144 ;
if ( V_2 -> V_177 == V_77 )
V_2 -> V_177 = NULL ;
if ( V_2 -> V_178 == V_77 )
V_2 -> V_178 = NULL ;
if ( V_2 -> V_179 &&
V_2 -> V_179 -> V_144 == V_77 )
V_2 -> V_179 -> V_144 = NULL ;
if ( ! F_60 ( & V_77 -> V_180 ) ) {
struct V_143 * V_181 = V_2 -> V_77 . V_165 ;
struct V_182 * V_183 ;
F_61 (ch, &peer->transmitted,
transmitted_list) {
V_183 -> V_144 = NULL ;
V_183 -> V_184 = 0 ;
}
F_62 ( & V_77 -> V_180 ,
& V_181 -> V_180 ) ;
if ( ! F_39 ( & V_181 -> V_185 ) )
if ( ! F_63 ( & V_181 -> V_185 ,
V_186 + V_181 -> V_187 ) )
F_64 ( V_181 ) ;
}
V_2 -> V_77 . V_99 -- ;
F_44 ( V_77 ) ;
}
struct V_143 * F_65 ( struct V_1 * V_2 ,
const union V_162 * V_188 ,
const T_2 V_8 ,
const int V_189 )
{
struct V_143 * V_77 ;
struct V_9 * V_10 ;
unsigned short V_20 ;
V_10 = F_2 ( V_2 -> V_14 . V_6 ) ;
V_20 = F_19 ( V_188 -> V_172 . V_173 ) ;
F_58 ( L_5 ,
L_6 ,
V_2 ,
V_188 ,
V_20 ,
V_189 ) ;
if ( 0 == V_2 -> V_77 . V_20 )
V_2 -> V_77 . V_20 = V_20 ;
V_77 = F_66 ( V_2 , V_188 ) ;
if ( V_77 ) {
if ( V_77 -> V_21 == V_164 ) {
V_77 -> V_21 = V_163 ;
}
return V_77 ;
}
V_77 = F_67 ( V_188 , V_8 ) ;
if ( ! V_77 )
return NULL ;
F_68 ( V_77 , V_2 ) ;
V_77 -> V_40 = V_2 -> V_40 ;
V_77 -> V_41 = V_2 -> V_41 ;
V_77 -> V_43 = V_2 -> V_43 ;
V_77 -> V_44 = V_2 -> V_44 ;
V_77 -> V_45 = V_2 -> V_45 ;
F_69 ( V_77 , NULL , V_10 ) ;
if ( V_77 -> V_45 & V_190 ) {
if ( V_2 -> V_42 )
V_77 -> V_42 = V_2 -> V_42 ;
else
V_77 -> V_42 = V_191 ;
}
if ( V_2 -> V_42 )
V_2 -> V_42 = F_8 ( int , V_77 -> V_42 , V_2 -> V_42 ) ;
else
V_2 -> V_42 = V_77 -> V_42 ;
F_27 ( L_7
L_8 , V_2 , V_2 -> V_42 ) ;
V_77 -> V_192 = 0 ;
V_2 -> V_28 = F_70 ( V_2 , V_2 -> V_42 ) ;
F_71 ( & V_77 -> V_193 , V_77 , V_2 -> V_14 . V_19 . V_20 ,
V_2 -> V_77 . V_20 ) ;
V_77 -> V_194 = F_72 ( 4 * V_2 -> V_42 , F_73 ( V_195 , 2 * V_2 -> V_42 , 4380 ) ) ;
V_77 -> V_196 = V_78 ;
V_77 -> V_197 = 0 ;
V_77 -> V_198 = 0 ;
V_77 -> V_199 = 0 ;
V_77 -> V_187 = V_2 -> V_32 ;
V_77 -> V_21 = V_189 ;
F_74 ( & V_77 -> V_155 , & V_2 -> V_77 . V_98 ) ;
V_2 -> V_77 . V_99 ++ ;
if ( ! V_2 -> V_77 . V_159 ) {
F_56 ( V_2 , V_77 ) ;
V_2 -> V_77 . V_174 = V_77 ;
}
if ( V_2 -> V_77 . V_165 == V_2 -> V_77 . V_174 &&
V_77 -> V_21 != V_200 ) {
V_2 -> V_77 . V_174 = V_77 ;
}
return V_77 ;
}
void F_75 ( struct V_1 * V_2 ,
const union V_162 * V_188 )
{
struct V_145 * V_146 ;
struct V_145 * V_147 ;
struct V_143 * V_144 ;
F_42 (pos, temp, &asoc->peer.transport_addr_list) {
V_144 = F_43 ( V_146 , struct V_143 , V_155 ) ;
if ( F_76 ( V_188 , & V_144 -> V_161 ) ) {
F_57 ( V_2 , V_144 ) ;
break;
}
}
}
struct V_143 * F_66 (
const struct V_1 * V_2 ,
const union V_162 * V_201 )
{
struct V_143 * V_202 ;
F_61 (t, &asoc->peer.transport_addr_list,
transports) {
if ( F_76 ( V_201 , & V_202 -> V_161 ) )
return V_202 ;
}
return NULL ;
}
void F_77 ( struct V_1 * V_2 ,
struct V_143 * V_203 )
{
struct V_143 * V_147 ;
struct V_143 * V_202 ;
F_78 (t, temp, &asoc->peer.transport_addr_list,
transports) {
if ( V_202 != V_203 )
F_57 ( V_2 , V_202 ) ;
}
}
void F_79 ( struct V_1 * V_2 ,
struct V_143 * V_144 ,
T_4 V_204 ,
T_5 error )
{
struct V_143 * V_202 = NULL ;
struct V_143 * V_205 ;
struct V_143 * V_206 ;
struct V_207 * V_208 ;
struct V_209 V_188 ;
int V_210 = 0 ;
switch ( V_204 ) {
case V_211 :
if ( V_200 == V_144 -> V_21 &&
V_212 == error )
V_210 = V_213 ;
else
V_210 = V_214 ;
V_144 -> V_21 = V_163 ;
break;
case V_215 :
if ( V_144 -> V_21 != V_200 )
V_144 -> V_21 = V_216 ;
else {
F_80 ( V_144 -> V_217 ) ;
V_144 -> V_217 = NULL ;
}
V_210 = V_218 ;
break;
default:
return;
}
memset ( & V_188 , 0 , sizeof( struct V_209 ) ) ;
memcpy ( & V_188 , & V_144 -> V_161 , V_144 -> V_219 -> V_220 ) ;
V_208 = F_81 ( V_2 , & V_188 ,
0 , V_210 , error , V_221 ) ;
if ( V_208 )
F_82 ( & V_2 -> V_110 , V_208 ) ;
V_205 = NULL ; V_206 = NULL ;
F_61 (t, &asoc->peer.transport_addr_list,
transports) {
if ( ( V_202 -> V_21 == V_216 ) ||
( V_202 -> V_21 == V_200 ) )
continue;
if ( ! V_205 || V_202 -> V_222 > V_205 -> V_222 ) {
V_206 = V_205 ;
V_205 = V_202 ;
}
if ( ! V_206 || V_202 -> V_222 > V_206 -> V_222 )
V_206 = V_202 ;
}
if ( ( ( V_2 -> V_77 . V_159 -> V_21 == V_163 ) ||
( V_2 -> V_77 . V_159 -> V_21 == V_164 ) ) &&
V_205 != V_2 -> V_77 . V_159 ) {
V_206 = V_205 ;
V_205 = V_2 -> V_77 . V_159 ;
}
if ( ! V_205 ) {
V_205 = V_2 -> V_77 . V_159 ;
V_206 = V_2 -> V_77 . V_159 ;
}
V_2 -> V_77 . V_165 = V_205 ;
V_2 -> V_77 . V_174 = V_206 ;
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
V_195 F_86 ( struct V_1 * V_2 )
{
V_195 V_223 = V_2 -> V_89 ;
V_2 -> V_89 ++ ;
V_2 -> V_94 ++ ;
return V_223 ;
}
int F_76 ( const union V_162 * V_224 ,
const union V_162 * V_225 )
{
struct V_226 * V_227 ;
V_227 = F_87 ( V_224 -> V_228 . V_229 ) ;
if ( F_88 ( ! V_227 ) )
return 0 ;
return V_227 -> V_230 ( V_224 , V_225 ) ;
}
struct V_182 * F_89 ( struct V_1 * V_2 )
{
struct V_182 * V_231 ;
if ( V_2 -> V_114 )
V_231 = F_90 ( V_2 , V_2 -> V_232 ) ;
else
V_231 = NULL ;
return V_231 ;
}
struct V_143 * F_91 ( struct V_1 * V_2 ,
V_195 V_233 )
{
struct V_143 * V_181 ;
struct V_143 * V_234 ;
struct V_143 * V_144 ;
struct V_182 * V_231 ;
T_6 V_235 = F_92 ( V_233 ) ;
V_234 = NULL ;
V_181 = V_2 -> V_77 . V_165 ;
F_61 (chunk, &active->transmitted,
transmitted_list) {
if ( V_235 == V_231 -> V_236 . V_237 -> V_233 ) {
V_234 = V_181 ;
goto V_238;
}
}
F_61 (transport, &asoc->peer.transport_addr_list,
transports) {
if ( V_144 == V_181 )
break;
F_61 (chunk, &transport->transmitted,
transmitted_list) {
if ( V_235 == V_231 -> V_236 . V_237 -> V_233 ) {
V_234 = V_144 ;
goto V_238;
}
}
}
V_238:
return V_234 ;
}
struct V_143 * F_93 ( struct V_1 * V_2 ,
const union V_162 * V_239 ,
const union V_162 * V_240 )
{
struct V_143 * V_144 ;
if ( ( F_20 ( V_2 -> V_14 . V_19 . V_20 ) == V_239 -> V_172 . V_173 ) &&
( F_20 ( V_2 -> V_77 . V_20 ) == V_240 -> V_172 . V_173 ) ) {
V_144 = F_66 ( V_2 , V_240 ) ;
if ( ! V_144 )
goto V_238;
if ( F_94 ( & V_2 -> V_14 . V_19 , V_239 ,
F_2 ( V_2 -> V_14 . V_6 ) ) )
goto V_238;
}
V_144 = NULL ;
V_238:
return V_144 ;
}
static void V_108 ( struct V_241 * V_242 )
{
struct V_1 * V_2 =
F_95 ( V_242 , struct V_1 ,
V_14 . V_107 . V_243 ) ;
struct V_3 * V_4 ;
struct V_182 * V_231 ;
struct V_244 * V_107 ;
int V_21 ;
T_7 V_245 ;
int error = 0 ;
V_4 = V_2 -> V_4 ;
V_107 = & V_2 -> V_14 . V_107 ;
F_83 ( V_2 ) ;
while ( NULL != ( V_231 = F_96 ( V_107 ) ) ) {
V_21 = V_2 -> V_21 ;
V_245 = F_97 ( V_231 -> V_246 -> type ) ;
if ( F_98 ( V_245 . V_231 , V_2 ) && ! V_231 -> V_247 )
continue;
if ( F_99 ( V_231 ) )
V_2 -> V_77 . V_176 = V_231 -> V_144 ;
else
F_100 ( V_248 ) ;
if ( V_231 -> V_144 )
V_231 -> V_144 -> V_222 = V_186 ;
error = F_101 ( V_249 , V_245 ,
V_21 , V_4 , V_2 , V_231 , V_221 ) ;
if ( V_2 -> V_14 . V_17 )
break;
if ( error && V_231 )
V_231 -> V_250 = 1 ;
}
F_41 ( V_2 ) ;
}
void F_102 ( struct V_1 * V_142 , struct V_5 * V_251 )
{
struct V_9 * V_252 = F_2 ( V_251 ) ;
struct V_5 * V_253 = V_142 -> V_14 . V_6 ;
F_103 ( & V_142 -> V_120 ) ;
if ( F_31 ( V_253 , V_148 ) )
V_253 -> V_150 -- ;
F_22 ( V_142 -> V_4 ) ;
F_23 ( V_142 -> V_14 . V_6 ) ;
V_142 -> V_4 = V_252 -> V_4 ;
F_3 ( V_142 -> V_4 ) ;
V_142 -> V_14 . V_6 = V_251 ;
F_4 ( V_142 -> V_14 . V_6 ) ;
F_104 ( V_252 -> V_4 , V_142 ) ;
}
void F_105 ( struct V_1 * V_2 ,
struct V_1 * V_254 )
{
struct V_143 * V_255 ;
struct V_145 * V_146 , * V_147 ;
V_2 -> V_62 = V_254 -> V_62 ;
V_2 -> V_77 . V_73 = V_254 -> V_77 . V_73 ;
V_2 -> V_77 . V_100 = V_254 -> V_77 . V_100 ;
V_2 -> V_77 . V_11 = V_254 -> V_77 . V_11 ;
F_106 ( & V_2 -> V_77 . V_112 , V_256 ,
V_2 -> V_77 . V_11 . V_88 , V_221 ) ;
F_42 (pos, temp, &asoc->peer.transport_addr_list) {
V_255 = F_43 ( V_146 , struct V_143 , V_155 ) ;
if ( ! F_66 ( V_254 , & V_255 -> V_161 ) ) {
F_57 ( V_2 , V_255 ) ;
continue;
}
if ( V_2 -> V_21 >= V_257 )
F_107 ( V_255 ) ;
}
if ( V_2 -> V_21 >= V_257 ) {
V_2 -> V_89 = V_254 -> V_89 ;
V_2 -> V_90 = V_254 -> V_90 ;
V_2 -> V_91 = V_254 -> V_91 ;
F_108 ( V_2 -> V_70 ) ;
F_109 ( & V_2 -> V_110 ) ;
V_2 -> V_39 = 0 ;
} else {
F_61 (trans, &new->peer.transport_addr_list,
transports) {
if ( ! F_66 ( V_2 , & V_255 -> V_161 ) )
F_65 ( V_2 , & V_255 -> V_161 ,
V_221 , V_255 -> V_21 ) ;
}
V_2 -> V_90 = V_2 -> V_89 - 1 ;
V_2 -> V_91 = V_2 -> V_90 ;
if ( ! V_2 -> V_70 ) {
V_2 -> V_70 = V_254 -> V_70 ;
V_254 -> V_70 = NULL ;
}
if ( ! V_2 -> V_115 ) {
F_110 ( V_2 , V_221 ) ;
}
}
F_28 ( V_2 -> V_77 . V_152 ) ;
V_2 -> V_77 . V_152 = V_254 -> V_77 . V_152 ;
V_254 -> V_77 . V_152 = NULL ;
F_28 ( V_2 -> V_77 . V_153 ) ;
V_2 -> V_77 . V_153 = V_254 -> V_77 . V_153 ;
V_254 -> V_77 . V_153 = NULL ;
F_28 ( V_2 -> V_77 . V_154 ) ;
V_2 -> V_77 . V_154 = V_254 -> V_77 . V_154 ;
V_254 -> V_77 . V_154 = NULL ;
F_47 ( V_2 -> V_130 ) ;
F_111 ( V_2 , V_221 ) ;
}
void F_59 ( struct V_1 * V_2 )
{
struct V_143 * V_202 , * V_175 ;
struct V_145 * V_258 = & V_2 -> V_77 . V_98 ;
struct V_145 * V_146 ;
if ( V_2 -> V_77 . V_99 == 1 )
return;
V_202 = V_2 -> V_77 . V_174 ;
V_146 = & V_202 -> V_155 ;
V_175 = NULL ;
while ( 1 ) {
if ( V_146 -> V_175 == V_258 )
V_146 = V_258 -> V_175 ;
else
V_146 = V_146 -> V_175 ;
V_202 = F_43 ( V_146 , struct V_143 , V_155 ) ;
if ( V_202 == V_2 -> V_77 . V_174 ) {
V_202 = V_175 ;
break;
}
if ( ( V_202 -> V_21 == V_163 ) ||
( V_202 -> V_21 == V_164 ) ) {
break;
} else {
if ( V_202 -> V_21 != V_200 && ! V_175 )
V_175 = V_202 ;
}
}
if ( V_202 )
V_2 -> V_77 . V_174 = V_202 ;
else
V_202 = V_2 -> V_77 . V_174 ;
F_58 ( L_9
L_10 ,
L_4 ,
V_2 ,
( & V_202 -> V_161 ) ,
F_19 ( V_202 -> V_161 . V_172 . V_173 ) ) ;
}
struct V_143 * F_112 (
struct V_1 * V_2 , struct V_143 * V_259 )
{
if ( ! V_259 )
return V_2 -> V_77 . V_165 ;
else {
if ( V_259 == V_2 -> V_77 . V_174 )
F_59 ( V_2 ) ;
return V_2 -> V_77 . V_174 ;
}
}
void F_113 ( struct V_1 * V_2 )
{
struct V_143 * V_202 ;
V_195 V_260 = 0 ;
if ( ! V_2 )
return;
F_61 (t, &asoc->peer.transport_addr_list,
transports) {
if ( V_202 -> V_192 && V_202 -> V_217 ) {
F_114 ( V_202 , F_115 ( V_202 -> V_217 ) ) ;
V_202 -> V_192 = 0 ;
}
if ( ! V_260 || ( V_202 -> V_42 < V_260 ) )
V_260 = V_202 -> V_42 ;
}
if ( V_260 ) {
V_2 -> V_42 = V_260 ;
V_2 -> V_28 = F_70 ( V_2 , V_260 ) ;
}
F_27 ( L_11 ,
V_261 , V_2 , V_2 -> V_42 , V_2 -> V_28 ) ;
}
static inline int F_116 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_21 ) {
case V_257 :
case V_262 :
case V_263 :
case V_264 :
if ( ( V_2 -> V_73 > V_2 -> V_74 ) &&
( ( V_2 -> V_73 - V_2 -> V_74 ) >= F_73 ( V_195 ,
( V_2 -> V_14 . V_6 -> V_71 >> V_265 ) ,
V_2 -> V_42 ) ) )
return 1 ;
break;
default:
break;
}
return 0 ;
}
void F_117 ( struct V_1 * V_2 , unsigned V_266 )
{
struct V_182 * V_267 ;
struct V_268 * V_269 ;
if ( V_2 -> V_75 ) {
if ( V_2 -> V_75 >= V_266 ) {
V_2 -> V_75 -= V_266 ;
} else {
V_2 -> V_73 += ( V_266 - V_2 -> V_75 ) ;
V_2 -> V_75 = 0 ;
}
} else {
V_2 -> V_73 += V_266 ;
}
if ( V_2 -> V_76 && V_2 -> V_73 >= V_2 -> V_76 ) {
int V_270 = F_72 ( V_2 -> V_42 , V_2 -> V_76 ) ;
V_2 -> V_73 += V_270 ;
V_2 -> V_76 -= V_270 ;
}
F_27 ( L_12
L_13 , V_261 , V_2 , V_266 , V_2 -> V_73 ,
V_2 -> V_75 , V_2 -> V_74 ) ;
if ( F_116 ( V_2 ) ) {
V_2 -> V_74 = V_2 -> V_73 ;
F_27 ( L_14
L_15 , V_261 ,
V_2 , V_2 -> V_73 , V_2 -> V_74 ) ;
V_267 = F_118 ( V_2 ) ;
if ( ! V_267 )
return;
V_2 -> V_77 . V_100 = 0 ;
F_119 ( & V_2 -> V_109 , V_267 ) ;
V_269 = & V_2 -> V_60 [ V_56 ] ;
if ( F_39 ( V_269 ) && F_40 ( V_269 ) )
F_41 ( V_2 ) ;
}
}
void F_120 ( struct V_1 * V_2 , unsigned V_266 )
{
int V_271 ;
int V_272 = 0 ;
F_49 (asoc->rwnd, L_16 , return) ;
F_49 (!asoc->rwnd_over, L_17 , return) ;
if ( V_2 -> V_4 -> V_273 )
V_271 = F_54 ( & V_2 -> V_80 ) ;
else
V_271 = F_54 ( & V_2 -> V_14 . V_6 -> V_274 ) ;
if ( V_271 >= V_2 -> V_14 . V_6 -> V_71 )
V_272 = 1 ;
if ( V_2 -> V_73 >= V_266 ) {
V_2 -> V_73 -= V_266 ;
if ( V_272 ) {
V_2 -> V_76 += V_2 -> V_73 ;
V_2 -> V_73 = 0 ;
}
} else {
V_2 -> V_75 = V_266 - V_2 -> V_73 ;
V_2 -> V_73 = 0 ;
}
F_27 ( L_18 ,
V_261 , V_2 , V_266 , V_2 -> V_73 ,
V_2 -> V_75 , V_2 -> V_76 ) ;
}
int F_121 ( struct V_1 * V_2 ,
T_1 V_7 , T_2 V_8 )
{
int V_275 ;
V_275 = ( V_118 == V_2 -> V_14 . V_6 -> V_117 ) ? V_276 : 0 ;
if ( V_2 -> V_77 . V_116 )
V_275 |= V_277 ;
if ( V_2 -> V_77 . V_119 )
V_275 |= V_278 ;
return F_122 ( & V_2 -> V_14 . V_19 ,
& V_2 -> V_4 -> V_14 . V_19 ,
V_7 , V_8 , V_275 ) ;
}
int F_123 ( struct V_1 * V_2 ,
struct V_279 * V_151 ,
T_2 V_8 )
{
int V_280 = F_19 ( V_151 -> V_281 -> V_246 . V_135 ) ;
int V_282 = V_151 -> V_283 ;
T_8 * V_284 = ( T_8 * ) V_151 -> V_281 + V_280 ;
return F_124 ( & V_2 -> V_14 . V_19 , V_284 , V_282 ,
V_2 -> V_4 -> V_14 . V_19 . V_20 , V_8 ) ;
}
int F_125 ( struct V_1 * V_2 ,
const union V_162 * V_239 )
{
int V_285 = 0 ;
if ( ( V_2 -> V_14 . V_19 . V_20 == F_19 ( V_239 -> V_172 . V_173 ) ) &&
F_94 ( & V_2 -> V_14 . V_19 , V_239 ,
F_2 ( V_2 -> V_14 . V_6 ) ) )
V_285 = 1 ;
return V_285 ;
}
int F_110 ( struct V_1 * V_2 , T_2 V_8 )
{
int V_115 ;
int error = 0 ;
if ( V_2 -> V_115 )
return error ;
V_286:
if ( F_88 ( ! F_126 ( & V_157 , V_8 ) ) )
return - V_287 ;
F_50 ( & V_156 ) ;
error = F_127 ( & V_157 , ( void * ) V_2 ,
V_288 , & V_115 ) ;
if ( ! error ) {
V_288 = V_115 + 1 ;
if ( V_288 == V_289 )
V_288 = 1 ;
}
F_52 ( & V_156 ) ;
if ( error == - V_290 )
goto V_286;
else if ( error )
return error ;
V_2 -> V_115 = ( V_291 ) V_115 ;
return error ;
}
static void F_128 ( struct V_1 * V_2 )
{
struct V_182 * V_292 ;
struct V_182 * V_293 ;
F_78 (asconf, tmp, &asoc->addip_chunk_list, list) {
F_103 ( & V_292 -> V_294 ) ;
F_129 ( V_292 ) ;
}
}
static void F_130 ( struct V_1 * V_2 )
{
struct V_182 * V_295 ;
struct V_182 * V_293 ;
F_78 (ack, tmp, &asoc->asconf_ack_list,
transmitted_list) {
F_103 ( & V_295 -> V_296 ) ;
F_129 ( V_295 ) ;
}
}
void F_131 ( const struct V_1 * V_2 )
{
struct V_182 * V_295 ;
struct V_182 * V_293 ;
F_78 (ack, tmp, &asoc->asconf_ack_list,
transmitted_list) {
if ( V_295 -> V_236 . V_297 -> V_298 ==
F_92 ( V_2 -> V_77 . V_95 ) )
break;
F_103 ( & V_295 -> V_296 ) ;
F_129 ( V_295 ) ;
}
}
struct V_182 * F_132 (
const struct V_1 * V_2 ,
T_6 V_298 )
{
struct V_182 * V_295 ;
F_61 (ack, &asoc->asconf_ack_list, transmitted_list) {
if ( V_295 -> V_236 . V_297 -> V_298 == V_298 ) {
F_133 ( V_295 ) ;
return V_295 ;
}
}
return NULL ;
}
void F_45 ( struct V_1 * V_2 )
{
F_130 ( V_2 ) ;
F_128 ( V_2 ) ;
if ( V_2 -> V_179 )
F_129 ( V_2 -> V_179 ) ;
}
