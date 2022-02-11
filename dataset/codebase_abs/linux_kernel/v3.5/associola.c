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
V_2 -> V_77 . V_102 = 1 ;
V_2 -> V_77 . V_103 = 0 ;
if ( V_104 )
V_2 -> V_77 . V_103 = 1 ;
V_2 -> V_105 = NULL ;
V_2 -> V_106 = 0 ;
V_2 -> V_107 = NULL ;
F_14 ( & V_2 -> V_14 . V_108 ) ;
F_15 ( & V_2 -> V_14 . V_108 , V_109 ) ;
F_16 ( V_2 , & V_2 -> V_110 ) ;
if ( ! F_17 ( & V_2 -> V_111 , V_2 ) )
goto V_112;
memset ( & V_2 -> V_77 . V_113 , 0 , sizeof( struct V_114 ) ) ;
V_2 -> V_115 = 0 ;
V_2 -> V_116 = 0 ;
V_2 -> V_77 . V_117 = 1 ;
if ( V_2 -> V_14 . V_6 -> V_118 == V_119 )
V_2 -> V_77 . V_120 = 1 ;
F_13 ( & V_2 -> V_121 ) ;
V_2 -> V_122 = V_10 -> V_122 ;
V_2 -> V_123 = V_10 -> V_123 ;
V_2 -> V_124 = V_10 -> V_124 ;
V_2 -> V_125 = V_10 -> V_125 ;
V_2 -> V_126 = V_10 -> V_126 ;
V_2 -> V_127 = V_10 -> V_127 ;
V_2 -> V_128 = V_10 -> V_128 ;
F_13 ( & V_2 -> V_129 ) ;
V_13 = F_18 ( V_4 , V_2 , V_8 ) ;
if ( V_13 )
goto V_112;
V_2 -> V_130 = V_4 -> V_130 ;
V_2 -> V_131 = NULL ;
V_2 -> V_132 = 0 ;
if ( V_4 -> V_133 )
memcpy ( V_2 -> V_62 . V_134 , V_4 -> V_133 ,
F_19 ( V_4 -> V_133 -> V_135 . V_136 ) ) ;
if ( V_4 -> V_137 )
memcpy ( V_2 -> V_62 . V_138 , V_4 -> V_137 ,
F_19 ( V_4 -> V_137 -> V_135 . V_136 ) ) ;
V_12 = ( T_3 * ) V_2 -> V_62 . V_139 ;
V_12 -> type = V_140 ;
V_12 -> V_136 = F_20 ( sizeof( T_3 ) + V_141 ) ;
F_21 ( V_12 + 1 , V_141 ) ;
return V_2 ;
V_112:
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
goto V_142;
if ( ! F_1 ( V_2 , V_4 , V_6 , V_7 , V_8 ) )
goto V_112;
V_2 -> V_14 . V_18 = 1 ;
F_26 ( V_143 ) ;
F_27 ( L_1 , V_2 ) ;
return V_2 ;
V_112:
F_28 ( V_2 ) ;
V_142:
return NULL ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_14 . V_6 ;
struct V_144 * V_145 ;
struct V_146 * V_147 , * V_148 ;
int V_11 ;
if ( ! V_2 -> V_148 ) {
F_30 ( & V_2 -> V_121 ) ;
if ( F_31 ( V_6 , V_149 ) && F_32 ( V_6 , V_150 ) )
V_6 -> V_151 -- ;
}
V_2 -> V_14 . V_17 = 1 ;
F_33 ( & V_2 -> V_110 ) ;
F_34 ( & V_2 -> V_111 ) ;
F_35 ( & V_2 -> V_14 . V_108 ) ;
F_36 ( & V_2 -> V_77 . V_113 ) ;
F_37 ( V_2 -> V_70 ) ;
F_38 ( & V_2 -> V_14 . V_19 ) ;
for ( V_11 = V_48 ; V_11 < V_59 ; ++ V_11 ) {
if ( F_39 ( & V_2 -> V_60 [ V_11 ] ) &&
F_40 ( & V_2 -> V_60 [ V_11 ] ) )
F_41 ( V_2 ) ;
}
F_28 ( V_2 -> V_77 . V_152 ) ;
F_28 ( V_2 -> V_77 . V_153 ) ;
F_28 ( V_2 -> V_77 . V_154 ) ;
F_28 ( V_2 -> V_77 . V_155 ) ;
F_42 (pos, temp, &asoc->peer.transport_addr_list) {
V_145 = F_43 ( V_147 , struct V_144 , V_156 ) ;
F_30 ( V_147 ) ;
F_44 ( V_145 ) ;
}
V_2 -> V_77 . V_99 = 0 ;
F_45 ( V_2 ) ;
if ( V_2 -> V_105 != NULL )
F_28 ( V_2 -> V_105 ) ;
F_46 ( & V_2 -> V_129 ) ;
F_47 ( V_2 -> V_131 ) ;
F_41 ( V_2 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_49 (asoc->base.dead, L_2 , return) ;
F_22 ( V_2 -> V_4 ) ;
F_23 ( V_2 -> V_14 . V_6 ) ;
if ( V_2 -> V_116 != 0 ) {
F_50 ( & V_157 ) ;
F_51 ( & V_158 , V_2 -> V_116 ) ;
F_52 ( & V_157 ) ;
}
F_53 ( F_54 ( & V_2 -> V_80 ) ) ;
if ( V_2 -> V_14 . V_18 ) {
F_28 ( V_2 ) ;
F_55 ( V_143 ) ;
}
}
void F_56 ( struct V_1 * V_2 ,
struct V_144 * V_145 )
{
int V_159 = 0 ;
if ( V_2 -> V_77 . V_160 != NULL &&
V_2 -> V_77 . V_160 != V_145 )
V_159 = 1 ;
V_2 -> V_77 . V_160 = V_145 ;
memcpy ( & V_2 -> V_77 . V_161 , & V_145 -> V_162 ,
sizeof( union V_163 ) ) ;
if ( ( V_145 -> V_21 == V_164 ) ||
( V_145 -> V_21 == V_165 ) )
V_2 -> V_77 . V_166 = V_145 ;
if ( ! V_2 -> V_110 . V_167 && ! V_2 -> V_110 . V_168 )
return;
if ( V_145 -> V_169 . V_170 )
V_145 -> V_169 . V_171 = V_159 ;
V_145 -> V_169 . V_170 = V_159 ;
V_145 -> V_169 . V_172 = V_2 -> V_89 ;
}
void F_57 ( struct V_1 * V_2 ,
struct V_144 * V_77 )
{
struct V_146 * V_147 ;
struct V_144 * V_145 ;
F_58 ( L_3 ,
L_4 ,
V_2 ,
( & V_77 -> V_162 ) ,
F_19 ( V_77 -> V_162 . V_173 . V_174 ) ) ;
if ( V_2 -> V_77 . V_175 == V_77 )
F_59 ( V_2 ) ;
F_30 ( & V_77 -> V_156 ) ;
V_147 = V_2 -> V_77 . V_98 . V_176 ;
V_145 = F_43 ( V_147 , struct V_144 , V_156 ) ;
if ( V_2 -> V_77 . V_160 == V_77 )
F_56 ( V_2 , V_145 ) ;
if ( V_2 -> V_77 . V_166 == V_77 )
V_2 -> V_77 . V_166 = V_145 ;
if ( V_2 -> V_77 . V_175 == V_77 )
V_2 -> V_77 . V_175 = V_145 ;
if ( V_2 -> V_77 . V_177 == V_77 )
V_2 -> V_77 . V_177 = V_145 ;
if ( V_2 -> V_178 == V_77 )
V_2 -> V_178 = NULL ;
if ( V_2 -> V_179 == V_77 )
V_2 -> V_179 = NULL ;
if ( V_2 -> V_180 &&
V_2 -> V_180 -> V_145 == V_77 )
V_2 -> V_180 -> V_145 = NULL ;
if ( ! F_60 ( & V_77 -> V_181 ) ) {
struct V_144 * V_182 = V_2 -> V_77 . V_166 ;
struct V_183 * V_184 ;
F_61 (ch, &peer->transmitted,
transmitted_list) {
V_184 -> V_145 = NULL ;
V_184 -> V_185 = 0 ;
}
F_62 ( & V_77 -> V_181 ,
& V_182 -> V_181 ) ;
if ( ! F_39 ( & V_182 -> V_186 ) )
if ( ! F_63 ( & V_182 -> V_186 ,
V_187 + V_182 -> V_188 ) )
F_64 ( V_182 ) ;
}
V_2 -> V_77 . V_99 -- ;
F_44 ( V_77 ) ;
}
struct V_144 * F_65 ( struct V_1 * V_2 ,
const union V_163 * V_189 ,
const T_2 V_8 ,
const int V_190 )
{
struct V_144 * V_77 ;
struct V_9 * V_10 ;
unsigned short V_20 ;
V_10 = F_2 ( V_2 -> V_14 . V_6 ) ;
V_20 = F_19 ( V_189 -> V_173 . V_174 ) ;
F_58 ( L_5 ,
L_6 ,
V_2 ,
V_189 ,
V_20 ,
V_190 ) ;
if ( 0 == V_2 -> V_77 . V_20 )
V_2 -> V_77 . V_20 = V_20 ;
V_77 = F_66 ( V_2 , V_189 ) ;
if ( V_77 ) {
if ( V_77 -> V_21 == V_165 ) {
V_77 -> V_21 = V_164 ;
}
return V_77 ;
}
V_77 = F_67 ( V_189 , V_8 ) ;
if ( ! V_77 )
return NULL ;
F_68 ( V_77 , V_2 ) ;
V_77 -> V_40 = V_2 -> V_40 ;
V_77 -> V_41 = V_2 -> V_41 ;
V_77 -> V_43 = V_2 -> V_43 ;
V_77 -> V_44 = V_2 -> V_44 ;
V_77 -> V_45 = V_2 -> V_45 ;
F_69 ( V_77 , NULL , V_10 ) ;
if ( V_77 -> V_45 & V_191 ) {
if ( V_2 -> V_42 )
V_77 -> V_42 = V_2 -> V_42 ;
else
V_77 -> V_42 = V_192 ;
}
if ( V_2 -> V_42 )
V_2 -> V_42 = F_8 ( int , V_77 -> V_42 , V_2 -> V_42 ) ;
else
V_2 -> V_42 = V_77 -> V_42 ;
F_27 ( L_7
L_8 , V_2 , V_2 -> V_42 ) ;
V_77 -> V_193 = 0 ;
V_2 -> V_28 = F_70 ( V_2 , V_2 -> V_42 ) ;
F_71 ( & V_77 -> V_194 , V_77 , V_2 -> V_14 . V_19 . V_20 ,
V_2 -> V_77 . V_20 ) ;
V_77 -> V_195 = F_72 ( 4 * V_2 -> V_42 , F_73 ( V_196 , 2 * V_2 -> V_42 , 4380 ) ) ;
V_77 -> V_197 = V_78 ;
V_77 -> V_198 = 0 ;
V_77 -> V_199 = 0 ;
V_77 -> V_200 = 0 ;
V_77 -> V_188 = V_2 -> V_32 ;
V_77 -> V_21 = V_190 ;
F_74 ( & V_77 -> V_156 , & V_2 -> V_77 . V_98 ) ;
V_2 -> V_77 . V_99 ++ ;
if ( ! V_2 -> V_77 . V_160 ) {
F_56 ( V_2 , V_77 ) ;
V_2 -> V_77 . V_175 = V_77 ;
}
if ( V_2 -> V_77 . V_166 == V_2 -> V_77 . V_175 &&
V_77 -> V_21 != V_201 ) {
V_2 -> V_77 . V_175 = V_77 ;
}
return V_77 ;
}
void F_75 ( struct V_1 * V_2 ,
const union V_163 * V_189 )
{
struct V_146 * V_147 ;
struct V_146 * V_148 ;
struct V_144 * V_145 ;
F_42 (pos, temp, &asoc->peer.transport_addr_list) {
V_145 = F_43 ( V_147 , struct V_144 , V_156 ) ;
if ( F_76 ( V_189 , & V_145 -> V_162 ) ) {
F_57 ( V_2 , V_145 ) ;
break;
}
}
}
struct V_144 * F_66 (
const struct V_1 * V_2 ,
const union V_163 * V_202 )
{
struct V_144 * V_203 ;
F_61 (t, &asoc->peer.transport_addr_list,
transports) {
if ( F_76 ( V_202 , & V_203 -> V_162 ) )
return V_203 ;
}
return NULL ;
}
void F_77 ( struct V_1 * V_2 ,
struct V_144 * V_204 )
{
struct V_144 * V_148 ;
struct V_144 * V_203 ;
F_78 (t, temp, &asoc->peer.transport_addr_list,
transports) {
if ( V_203 != V_204 )
F_57 ( V_2 , V_203 ) ;
}
}
void F_79 ( struct V_1 * V_2 ,
struct V_144 * V_145 ,
T_4 V_205 ,
T_5 error )
{
struct V_144 * V_203 = NULL ;
struct V_144 * V_206 ;
struct V_144 * V_207 ;
struct V_208 * V_209 ;
struct V_210 V_189 ;
int V_211 = 0 ;
switch ( V_205 ) {
case V_212 :
if ( V_201 == V_145 -> V_21 &&
V_213 == error )
V_211 = V_214 ;
else
V_211 = V_215 ;
V_145 -> V_21 = V_164 ;
break;
case V_216 :
if ( V_145 -> V_21 != V_201 )
V_145 -> V_21 = V_217 ;
else {
F_80 ( V_145 -> V_218 ) ;
V_145 -> V_218 = NULL ;
}
V_211 = V_219 ;
break;
default:
return;
}
memset ( & V_189 , 0 , sizeof( struct V_210 ) ) ;
memcpy ( & V_189 , & V_145 -> V_162 , V_145 -> V_220 -> V_221 ) ;
V_209 = F_81 ( V_2 , & V_189 ,
0 , V_211 , error , V_222 ) ;
if ( V_209 )
F_82 ( & V_2 -> V_111 , V_209 ) ;
V_206 = NULL ; V_207 = NULL ;
F_61 (t, &asoc->peer.transport_addr_list,
transports) {
if ( ( V_203 -> V_21 == V_217 ) ||
( V_203 -> V_21 == V_201 ) )
continue;
if ( ! V_206 || V_203 -> V_223 > V_206 -> V_223 ) {
V_207 = V_206 ;
V_206 = V_203 ;
}
if ( ! V_207 || V_203 -> V_223 > V_207 -> V_223 )
V_207 = V_203 ;
}
if ( ( ( V_2 -> V_77 . V_160 -> V_21 == V_164 ) ||
( V_2 -> V_77 . V_160 -> V_21 == V_165 ) ) &&
V_206 != V_2 -> V_77 . V_160 ) {
V_207 = V_206 ;
V_206 = V_2 -> V_77 . V_160 ;
}
if ( ! V_206 ) {
V_206 = V_2 -> V_77 . V_160 ;
V_207 = V_2 -> V_77 . V_160 ;
}
V_2 -> V_77 . V_166 = V_206 ;
V_2 -> V_77 . V_175 = V_207 ;
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
V_196 F_86 ( struct V_1 * V_2 )
{
V_196 V_224 = V_2 -> V_89 ;
V_2 -> V_89 ++ ;
V_2 -> V_94 ++ ;
return V_224 ;
}
int F_76 ( const union V_163 * V_225 ,
const union V_163 * V_226 )
{
struct V_227 * V_228 ;
V_228 = F_87 ( V_225 -> V_229 . V_230 ) ;
if ( F_88 ( ! V_228 ) )
return 0 ;
return V_228 -> V_231 ( V_225 , V_226 ) ;
}
struct V_183 * F_89 ( struct V_1 * V_2 )
{
struct V_183 * V_232 ;
if ( V_2 -> V_115 )
V_232 = F_90 ( V_2 , V_2 -> V_233 ) ;
else
V_232 = NULL ;
return V_232 ;
}
struct V_144 * F_91 ( struct V_1 * V_2 ,
V_196 V_234 )
{
struct V_144 * V_182 ;
struct V_144 * V_235 ;
struct V_144 * V_145 ;
struct V_183 * V_232 ;
T_6 V_236 = F_92 ( V_234 ) ;
V_235 = NULL ;
V_182 = V_2 -> V_77 . V_166 ;
F_61 (chunk, &active->transmitted,
transmitted_list) {
if ( V_236 == V_232 -> V_237 . V_238 -> V_234 ) {
V_235 = V_182 ;
goto V_239;
}
}
F_61 (transport, &asoc->peer.transport_addr_list,
transports) {
if ( V_145 == V_182 )
break;
F_61 (chunk, &transport->transmitted,
transmitted_list) {
if ( V_236 == V_232 -> V_237 . V_238 -> V_234 ) {
V_235 = V_145 ;
goto V_239;
}
}
}
V_239:
return V_235 ;
}
struct V_144 * F_93 ( struct V_1 * V_2 ,
const union V_163 * V_240 ,
const union V_163 * V_241 )
{
struct V_144 * V_145 ;
if ( ( F_20 ( V_2 -> V_14 . V_19 . V_20 ) == V_240 -> V_173 . V_174 ) &&
( F_20 ( V_2 -> V_77 . V_20 ) == V_241 -> V_173 . V_174 ) ) {
V_145 = F_66 ( V_2 , V_241 ) ;
if ( ! V_145 )
goto V_239;
if ( F_94 ( & V_2 -> V_14 . V_19 , V_240 ,
F_2 ( V_2 -> V_14 . V_6 ) ) )
goto V_239;
}
V_145 = NULL ;
V_239:
return V_145 ;
}
static void V_109 ( struct V_242 * V_243 )
{
struct V_1 * V_2 =
F_95 ( V_243 , struct V_1 ,
V_14 . V_108 . V_244 ) ;
struct V_3 * V_4 ;
struct V_183 * V_232 ;
struct V_245 * V_108 ;
int V_21 ;
T_7 V_246 ;
int error = 0 ;
V_4 = V_2 -> V_4 ;
V_108 = & V_2 -> V_14 . V_108 ;
F_83 ( V_2 ) ;
while ( NULL != ( V_232 = F_96 ( V_108 ) ) ) {
V_21 = V_2 -> V_21 ;
V_246 = F_97 ( V_232 -> V_247 -> type ) ;
if ( F_98 ( V_246 . V_232 , V_2 ) && ! V_232 -> V_248 )
continue;
if ( F_99 ( V_232 ) )
V_2 -> V_77 . V_177 = V_232 -> V_145 ;
else
F_100 ( V_249 ) ;
if ( V_232 -> V_145 )
V_232 -> V_145 -> V_223 = V_187 ;
error = F_101 ( V_250 , V_246 ,
V_21 , V_4 , V_2 , V_232 , V_222 ) ;
if ( V_2 -> V_14 . V_17 )
break;
if ( error && V_232 )
V_232 -> V_251 = 1 ;
}
F_41 ( V_2 ) ;
}
void F_102 ( struct V_1 * V_143 , struct V_5 * V_252 )
{
struct V_9 * V_253 = F_2 ( V_252 ) ;
struct V_5 * V_254 = V_143 -> V_14 . V_6 ;
F_103 ( & V_143 -> V_121 ) ;
if ( F_31 ( V_254 , V_149 ) )
V_254 -> V_151 -- ;
F_22 ( V_143 -> V_4 ) ;
F_23 ( V_143 -> V_14 . V_6 ) ;
V_143 -> V_4 = V_253 -> V_4 ;
F_3 ( V_143 -> V_4 ) ;
V_143 -> V_14 . V_6 = V_252 ;
F_4 ( V_143 -> V_14 . V_6 ) ;
F_104 ( V_253 -> V_4 , V_143 ) ;
}
void F_105 ( struct V_1 * V_2 ,
struct V_1 * V_255 )
{
struct V_144 * V_256 ;
struct V_146 * V_147 , * V_148 ;
V_2 -> V_62 = V_255 -> V_62 ;
V_2 -> V_77 . V_73 = V_255 -> V_77 . V_73 ;
V_2 -> V_77 . V_100 = V_255 -> V_77 . V_100 ;
V_2 -> V_77 . V_11 = V_255 -> V_77 . V_11 ;
F_106 ( & V_2 -> V_77 . V_113 , V_257 ,
V_2 -> V_77 . V_11 . V_88 , V_222 ) ;
F_42 (pos, temp, &asoc->peer.transport_addr_list) {
V_256 = F_43 ( V_147 , struct V_144 , V_156 ) ;
if ( ! F_66 ( V_255 , & V_256 -> V_162 ) ) {
F_57 ( V_2 , V_256 ) ;
continue;
}
if ( V_2 -> V_21 >= V_258 )
F_107 ( V_256 ) ;
}
if ( V_2 -> V_21 >= V_258 ) {
V_2 -> V_89 = V_255 -> V_89 ;
V_2 -> V_90 = V_255 -> V_90 ;
V_2 -> V_91 = V_255 -> V_91 ;
F_108 ( V_2 -> V_70 ) ;
F_109 ( & V_2 -> V_111 ) ;
V_2 -> V_39 = 0 ;
} else {
F_61 (trans, &new->peer.transport_addr_list,
transports) {
if ( ! F_66 ( V_2 , & V_256 -> V_162 ) )
F_65 ( V_2 , & V_256 -> V_162 ,
V_222 , V_256 -> V_21 ) ;
}
V_2 -> V_90 = V_2 -> V_89 - 1 ;
V_2 -> V_91 = V_2 -> V_90 ;
if ( ! V_2 -> V_70 ) {
V_2 -> V_70 = V_255 -> V_70 ;
V_255 -> V_70 = NULL ;
}
if ( ! V_2 -> V_116 ) {
F_110 ( V_2 , V_222 ) ;
}
}
F_28 ( V_2 -> V_77 . V_153 ) ;
V_2 -> V_77 . V_153 = V_255 -> V_77 . V_153 ;
V_255 -> V_77 . V_153 = NULL ;
F_28 ( V_2 -> V_77 . V_154 ) ;
V_2 -> V_77 . V_154 = V_255 -> V_77 . V_154 ;
V_255 -> V_77 . V_154 = NULL ;
F_28 ( V_2 -> V_77 . V_155 ) ;
V_2 -> V_77 . V_155 = V_255 -> V_77 . V_155 ;
V_255 -> V_77 . V_155 = NULL ;
F_47 ( V_2 -> V_131 ) ;
F_111 ( V_2 , V_222 ) ;
}
void F_59 ( struct V_1 * V_2 )
{
struct V_144 * V_203 , * V_176 ;
struct V_146 * V_259 = & V_2 -> V_77 . V_98 ;
struct V_146 * V_147 ;
if ( V_2 -> V_77 . V_99 == 1 )
return;
V_203 = V_2 -> V_77 . V_175 ;
V_147 = & V_203 -> V_156 ;
V_176 = NULL ;
while ( 1 ) {
if ( V_147 -> V_176 == V_259 )
V_147 = V_259 -> V_176 ;
else
V_147 = V_147 -> V_176 ;
V_203 = F_43 ( V_147 , struct V_144 , V_156 ) ;
if ( V_203 == V_2 -> V_77 . V_175 ) {
V_203 = V_176 ;
break;
}
if ( ( V_203 -> V_21 == V_164 ) ||
( V_203 -> V_21 == V_165 ) ) {
break;
} else {
if ( V_203 -> V_21 != V_201 && ! V_176 )
V_176 = V_203 ;
}
}
if ( V_203 )
V_2 -> V_77 . V_175 = V_203 ;
else
V_203 = V_2 -> V_77 . V_175 ;
F_58 ( L_9
L_10 ,
L_4 ,
V_2 ,
( & V_203 -> V_162 ) ,
F_19 ( V_203 -> V_162 . V_173 . V_174 ) ) ;
}
struct V_144 * F_112 (
struct V_1 * V_2 , struct V_144 * V_260 )
{
if ( ! V_260 )
return V_2 -> V_77 . V_166 ;
else {
if ( V_260 == V_2 -> V_77 . V_175 )
F_59 ( V_2 ) ;
return V_2 -> V_77 . V_175 ;
}
}
void F_113 ( struct V_1 * V_2 )
{
struct V_144 * V_203 ;
V_196 V_261 = 0 ;
if ( ! V_2 )
return;
F_61 (t, &asoc->peer.transport_addr_list,
transports) {
if ( V_203 -> V_193 && V_203 -> V_218 ) {
F_114 ( V_203 , F_115 ( V_203 -> V_218 ) ) ;
V_203 -> V_193 = 0 ;
}
if ( ! V_261 || ( V_203 -> V_42 < V_261 ) )
V_261 = V_203 -> V_42 ;
}
if ( V_261 ) {
V_2 -> V_42 = V_261 ;
V_2 -> V_28 = F_70 ( V_2 , V_261 ) ;
}
F_27 ( L_11 ,
V_262 , V_2 , V_2 -> V_42 , V_2 -> V_28 ) ;
}
static inline int F_116 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_21 ) {
case V_258 :
case V_263 :
case V_264 :
case V_265 :
if ( ( V_2 -> V_73 > V_2 -> V_74 ) &&
( ( V_2 -> V_73 - V_2 -> V_74 ) >= F_73 ( V_196 ,
( V_2 -> V_14 . V_6 -> V_71 >> V_266 ) ,
V_2 -> V_42 ) ) )
return 1 ;
break;
default:
break;
}
return 0 ;
}
void F_117 ( struct V_1 * V_2 , unsigned int V_267 )
{
struct V_183 * V_268 ;
struct V_269 * V_270 ;
if ( V_2 -> V_75 ) {
if ( V_2 -> V_75 >= V_267 ) {
V_2 -> V_75 -= V_267 ;
} else {
V_2 -> V_73 += ( V_267 - V_2 -> V_75 ) ;
V_2 -> V_75 = 0 ;
}
} else {
V_2 -> V_73 += V_267 ;
}
if ( V_2 -> V_76 && V_2 -> V_73 >= V_2 -> V_76 ) {
int V_271 = F_72 ( V_2 -> V_42 , V_2 -> V_76 ) ;
V_2 -> V_73 += V_271 ;
V_2 -> V_76 -= V_271 ;
}
F_27 ( L_12
L_13 , V_262 , V_2 , V_267 , V_2 -> V_73 ,
V_2 -> V_75 , V_2 -> V_74 ) ;
if ( F_116 ( V_2 ) ) {
V_2 -> V_74 = V_2 -> V_73 ;
F_27 ( L_14
L_15 , V_262 ,
V_2 , V_2 -> V_73 , V_2 -> V_74 ) ;
V_268 = F_118 ( V_2 ) ;
if ( ! V_268 )
return;
V_2 -> V_77 . V_100 = 0 ;
F_119 ( & V_2 -> V_110 , V_268 ) ;
V_270 = & V_2 -> V_60 [ V_56 ] ;
if ( F_39 ( V_270 ) && F_40 ( V_270 ) )
F_41 ( V_2 ) ;
}
}
void F_120 ( struct V_1 * V_2 , unsigned int V_267 )
{
int V_272 ;
int V_273 = 0 ;
F_49 (asoc->rwnd, L_16 , return) ;
F_49 (!asoc->rwnd_over, L_17 , return) ;
if ( V_2 -> V_4 -> V_274 )
V_272 = F_54 ( & V_2 -> V_80 ) ;
else
V_272 = F_54 ( & V_2 -> V_14 . V_6 -> V_275 ) ;
if ( V_272 >= V_2 -> V_14 . V_6 -> V_71 )
V_273 = 1 ;
if ( V_2 -> V_73 >= V_267 ) {
V_2 -> V_73 -= V_267 ;
if ( V_273 ) {
V_2 -> V_76 += V_2 -> V_73 ;
V_2 -> V_73 = 0 ;
}
} else {
V_2 -> V_75 = V_267 - V_2 -> V_73 ;
V_2 -> V_73 = 0 ;
}
F_27 ( L_18 ,
V_262 , V_2 , V_267 , V_2 -> V_73 ,
V_2 -> V_75 , V_2 -> V_76 ) ;
}
int F_121 ( struct V_1 * V_2 ,
T_1 V_7 , T_2 V_8 )
{
int V_276 ;
V_276 = ( V_119 == V_2 -> V_14 . V_6 -> V_118 ) ? V_277 : 0 ;
if ( V_2 -> V_77 . V_117 )
V_276 |= V_278 ;
if ( V_2 -> V_77 . V_120 )
V_276 |= V_279 ;
return F_122 ( & V_2 -> V_14 . V_19 ,
& V_2 -> V_4 -> V_14 . V_19 ,
V_7 , V_8 , V_276 ) ;
}
int F_123 ( struct V_1 * V_2 ,
struct V_280 * V_152 ,
T_2 V_8 )
{
int V_281 = F_19 ( V_152 -> V_282 -> V_247 . V_136 ) ;
int V_283 = V_152 -> V_284 ;
T_8 * V_285 = ( T_8 * ) V_152 -> V_282 + V_281 ;
return F_124 ( & V_2 -> V_14 . V_19 , V_285 , V_283 ,
V_2 -> V_4 -> V_14 . V_19 . V_20 , V_8 ) ;
}
int F_125 ( struct V_1 * V_2 ,
const union V_163 * V_240 )
{
int V_286 = 0 ;
if ( ( V_2 -> V_14 . V_19 . V_20 == F_19 ( V_240 -> V_173 . V_174 ) ) &&
F_94 ( & V_2 -> V_14 . V_19 , V_240 ,
F_2 ( V_2 -> V_14 . V_6 ) ) )
V_286 = 1 ;
return V_286 ;
}
int F_110 ( struct V_1 * V_2 , T_2 V_8 )
{
int V_116 ;
int error = 0 ;
if ( V_2 -> V_116 )
return error ;
V_287:
if ( F_88 ( ! F_126 ( & V_158 , V_8 ) ) )
return - V_288 ;
F_50 ( & V_157 ) ;
error = F_127 ( & V_158 , ( void * ) V_2 ,
V_289 , & V_116 ) ;
if ( ! error ) {
V_289 = V_116 + 1 ;
if ( V_289 == V_290 )
V_289 = 1 ;
}
F_52 ( & V_157 ) ;
if ( error == - V_291 )
goto V_287;
else if ( error )
return error ;
V_2 -> V_116 = ( V_292 ) V_116 ;
return error ;
}
static void F_128 ( struct V_1 * V_2 )
{
struct V_183 * V_293 ;
struct V_183 * V_294 ;
F_78 (asconf, tmp, &asoc->addip_chunk_list, list) {
F_103 ( & V_293 -> V_295 ) ;
F_129 ( V_293 ) ;
}
}
static void F_130 ( struct V_1 * V_2 )
{
struct V_183 * V_296 ;
struct V_183 * V_294 ;
F_78 (ack, tmp, &asoc->asconf_ack_list,
transmitted_list) {
F_103 ( & V_296 -> V_297 ) ;
F_129 ( V_296 ) ;
}
}
void F_131 ( const struct V_1 * V_2 )
{
struct V_183 * V_296 ;
struct V_183 * V_294 ;
F_78 (ack, tmp, &asoc->asconf_ack_list,
transmitted_list) {
if ( V_296 -> V_237 . V_298 -> V_299 ==
F_92 ( V_2 -> V_77 . V_95 ) )
break;
F_103 ( & V_296 -> V_297 ) ;
F_129 ( V_296 ) ;
}
}
struct V_183 * F_132 (
const struct V_1 * V_2 ,
T_6 V_299 )
{
struct V_183 * V_296 ;
F_61 (ack, &asoc->asconf_ack_list, transmitted_list) {
if ( V_296 -> V_237 . V_298 -> V_299 == V_299 ) {
F_133 ( V_296 ) ;
return V_296 ;
}
}
return NULL ;
}
void F_45 ( struct V_1 * V_2 )
{
F_130 ( V_2 ) ;
F_128 ( V_2 ) ;
if ( V_2 -> V_180 )
F_129 ( V_2 -> V_180 ) ;
}
