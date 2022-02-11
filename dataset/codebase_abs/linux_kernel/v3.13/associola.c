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
V_2 -> V_15 . V_6 = (struct V_5 * ) V_6 ;
F_4 ( V_2 -> V_4 ) ;
F_5 ( V_2 -> V_15 . V_6 ) ;
V_2 -> V_15 . type = V_16 ;
F_6 ( & V_2 -> V_15 . V_17 , 1 ) ;
V_2 -> V_15 . V_18 = false ;
F_7 ( & V_2 -> V_15 . V_19 , V_4 -> V_15 . V_19 . V_20 ) ;
V_2 -> V_21 = V_22 ;
V_2 -> V_23 = F_8 ( V_11 -> V_24 . V_25 ) ;
V_2 -> V_26 = 0 ;
V_2 -> V_27 = V_11 -> V_27 ;
V_2 -> V_28 = V_11 -> V_24 . V_29 ;
V_2 -> V_30 = V_9 -> V_31 . V_30 ;
V_2 -> V_32 = F_9 ( V_11 -> V_33 . V_34 ) ;
V_2 -> V_35 = F_9 ( V_11 -> V_33 . V_36 ) ;
V_2 -> V_37 = F_9 ( V_11 -> V_33 . V_38 ) ;
V_2 -> V_39 = 0 ;
V_2 -> V_40 = F_9 ( V_11 -> V_40 ) ;
V_2 -> V_41 = V_11 -> V_41 ;
V_2 -> V_42 = V_11 -> V_42 ;
V_2 -> V_43 = F_9 ( V_11 -> V_43 ) ;
V_2 -> V_44 = V_11 -> V_44 ;
V_2 -> V_45 = V_11 -> V_45 ;
V_2 -> V_46 = V_11 -> V_46 ;
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
V_2 -> V_47 [ V_57 ] = V_11 -> V_58 * V_59 ;
for ( V_12 = V_48 ; V_12 < V_60 ; ++ V_12 )
F_10 ( & V_2 -> V_61 [ V_12 ] , V_62 [ V_12 ] ,
( unsigned long ) V_2 ) ;
V_2 -> V_63 . V_64 = V_11 -> V_65 . V_64 ;
V_2 -> V_63 . V_66 = V_11 -> V_65 . V_66 ;
V_2 -> V_67 = V_11 -> V_65 . V_68 ;
V_2 -> V_69 =
F_9 ( V_11 -> V_65 . V_70 ) ;
V_2 -> V_71 = NULL ;
if ( ( V_6 -> V_72 / 2 ) < V_73 )
V_2 -> V_74 = V_73 ;
else
V_2 -> V_74 = V_6 -> V_72 / 2 ;
V_2 -> V_75 = V_2 -> V_74 ;
V_2 -> V_76 = 0 ;
V_2 -> V_77 = 0 ;
V_2 -> V_78 . V_74 = V_79 ;
V_2 -> V_80 = 0 ;
F_6 ( & V_2 -> V_81 , 0 ) ;
F_11 ( & V_2 -> V_82 ) ;
V_2 -> V_63 . V_83 = F_12 ( V_4 ) ;
V_2 -> V_78 . V_12 . V_84 = 0 ;
V_2 -> V_63 . V_85 = 0 ;
V_2 -> V_63 . V_86 = 0 ;
V_2 -> V_63 . V_87 = 0 ;
V_2 -> V_63 . V_88 = V_4 -> V_15 . V_19 . V_20 ;
V_2 -> V_63 . V_89 = F_13 ( V_4 ) ;
V_2 -> V_90 = V_2 -> V_63 . V_89 ;
V_2 -> V_91 = V_2 -> V_90 - 1 ;
V_2 -> V_92 = V_2 -> V_91 ;
V_2 -> V_93 = V_2 -> V_91 ;
V_2 -> V_94 = V_2 -> V_91 ;
V_2 -> V_95 = 0 ;
V_2 -> V_96 = V_2 -> V_63 . V_89 ;
F_14 ( & V_2 -> V_97 ) ;
F_14 ( & V_2 -> V_98 ) ;
F_14 ( & V_2 -> V_78 . V_99 ) ;
V_2 -> V_78 . V_100 = 0 ;
V_2 -> V_78 . V_101 = 1 ;
V_2 -> V_78 . V_102 = 0 ;
V_2 -> V_78 . V_103 = 1 ;
V_2 -> V_78 . V_104 = 0 ;
if ( V_9 -> V_31 . V_105 )
V_2 -> V_78 . V_104 = 1 ;
V_2 -> V_106 = NULL ;
V_2 -> V_107 = 0 ;
V_2 -> V_108 = NULL ;
F_15 ( & V_2 -> V_15 . V_109 ) ;
F_16 ( & V_2 -> V_15 . V_109 , V_110 ) ;
F_17 ( V_2 , & V_2 -> V_111 ) ;
if ( ! F_18 ( & V_2 -> V_112 , V_2 ) )
goto V_113;
memset ( & V_2 -> V_78 . V_114 , 0 , sizeof( struct V_115 ) ) ;
V_2 -> V_116 = 0 ;
V_2 -> V_117 = 0 ;
V_2 -> V_78 . V_118 = 1 ;
if ( V_2 -> V_15 . V_6 -> V_119 == V_120 )
V_2 -> V_78 . V_121 = 1 ;
F_14 ( & V_2 -> V_122 ) ;
V_2 -> V_123 = V_11 -> V_123 ;
V_2 -> V_124 = V_11 -> V_124 ;
V_2 -> V_125 = V_11 -> V_125 ;
V_2 -> V_126 = V_11 -> V_126 ;
V_2 -> V_127 = V_11 -> V_127 ;
V_2 -> V_128 = V_11 -> V_128 ;
memset ( & V_2 -> V_129 , 0 , sizeof( struct V_130 ) ) ;
F_14 ( & V_2 -> V_131 ) ;
V_14 = F_19 ( V_4 , V_2 , V_8 ) ;
if ( V_14 )
goto V_113;
V_2 -> V_132 = V_4 -> V_132 ;
V_2 -> V_133 = NULL ;
V_2 -> V_134 = 0 ;
if ( V_4 -> V_135 )
memcpy ( V_2 -> V_63 . V_136 , V_4 -> V_135 ,
F_20 ( V_4 -> V_135 -> V_137 . V_138 ) ) ;
if ( V_4 -> V_139 )
memcpy ( V_2 -> V_63 . V_140 , V_4 -> V_139 ,
F_20 ( V_4 -> V_139 -> V_137 . V_138 ) ) ;
V_13 = ( T_3 * ) V_2 -> V_63 . V_141 ;
V_13 -> type = V_142 ;
V_13 -> V_138 = F_21 ( sizeof( T_3 ) + V_143 ) ;
F_22 ( V_13 + 1 , V_143 ) ;
return V_2 ;
V_113:
F_23 ( V_2 -> V_15 . V_6 ) ;
F_24 ( V_2 -> V_4 ) ;
return NULL ;
}
struct V_1 * F_25 ( const struct V_3 * V_4 ,
const struct V_5 * V_6 ,
T_1 V_7 ,
T_2 V_8 )
{
struct V_1 * V_2 ;
V_2 = F_26 ( sizeof( * V_2 ) , V_8 ) ;
if ( ! V_2 )
goto V_144;
if ( ! F_1 ( V_2 , V_4 , V_6 , V_7 , V_8 ) )
goto V_113;
F_27 ( V_145 ) ;
F_28 ( L_1 , V_2 ) ;
return V_2 ;
V_113:
F_29 ( V_2 ) ;
V_144:
return NULL ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_15 . V_6 ;
struct V_146 * V_147 ;
struct V_148 * V_149 , * V_150 ;
int V_12 ;
if ( ! V_2 -> V_150 ) {
F_31 ( & V_2 -> V_122 ) ;
if ( F_32 ( V_6 , V_151 ) && F_33 ( V_6 , V_152 ) )
V_6 -> V_153 -- ;
}
V_2 -> V_15 . V_18 = true ;
F_34 ( & V_2 -> V_111 ) ;
F_35 ( & V_2 -> V_112 ) ;
F_36 ( & V_2 -> V_15 . V_109 ) ;
F_37 ( & V_2 -> V_78 . V_114 ) ;
F_38 ( V_2 -> V_71 ) ;
F_39 ( & V_2 -> V_15 . V_19 ) ;
for ( V_12 = V_48 ; V_12 < V_60 ; ++ V_12 ) {
if ( F_40 ( & V_2 -> V_61 [ V_12 ] ) )
F_41 ( V_2 ) ;
}
F_29 ( V_2 -> V_78 . V_154 ) ;
F_29 ( V_2 -> V_78 . V_155 ) ;
F_29 ( V_2 -> V_78 . V_156 ) ;
F_29 ( V_2 -> V_78 . V_157 ) ;
F_42 (pos, temp, &asoc->peer.transport_addr_list) {
V_147 = F_43 ( V_149 , struct V_146 , V_158 ) ;
F_44 ( V_149 ) ;
F_45 ( V_147 ) ;
}
V_2 -> V_78 . V_100 = 0 ;
F_46 ( V_2 ) ;
if ( V_2 -> V_106 != NULL )
F_29 ( V_2 -> V_106 ) ;
F_47 ( & V_2 -> V_131 ) ;
F_48 ( V_2 -> V_133 ) ;
F_41 ( V_2 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
if ( F_50 ( ! V_2 -> V_15 . V_18 ) ) {
F_51 ( 1 , L_2 , V_2 ) ;
return;
}
F_24 ( V_2 -> V_4 ) ;
F_23 ( V_2 -> V_15 . V_6 ) ;
if ( V_2 -> V_117 != 0 ) {
F_52 ( & V_159 ) ;
F_53 ( & V_160 , V_2 -> V_117 ) ;
F_54 ( & V_159 ) ;
}
F_55 ( F_56 ( & V_2 -> V_81 ) ) ;
F_29 ( V_2 ) ;
F_57 ( V_145 ) ;
}
void F_58 ( struct V_1 * V_2 ,
struct V_146 * V_147 )
{
int V_161 = 0 ;
if ( V_2 -> V_78 . V_162 != NULL &&
V_2 -> V_78 . V_162 != V_147 )
V_161 = 1 ;
V_2 -> V_78 . V_162 = V_147 ;
memcpy ( & V_2 -> V_78 . V_163 , & V_147 -> V_164 ,
sizeof( union V_165 ) ) ;
if ( ( V_147 -> V_21 == V_166 ) ||
( V_147 -> V_21 == V_167 ) )
V_2 -> V_78 . V_168 = V_147 ;
if ( ! V_2 -> V_111 . V_169 && ! V_2 -> V_111 . V_170 )
return;
if ( V_147 -> V_171 . V_172 )
V_147 -> V_171 . V_173 = V_161 ;
V_147 -> V_171 . V_172 = V_161 ;
V_147 -> V_171 . V_174 = V_2 -> V_90 ;
}
void F_59 ( struct V_1 * V_2 ,
struct V_146 * V_78 )
{
struct V_148 * V_149 ;
struct V_146 * V_147 ;
F_28 ( L_3 ,
V_175 , V_2 , & V_78 -> V_164 . V_176 ) ;
if ( V_2 -> V_78 . V_177 == V_78 )
F_60 ( V_2 ) ;
F_44 ( & V_78 -> V_158 ) ;
V_149 = V_2 -> V_78 . V_99 . V_178 ;
V_147 = F_43 ( V_149 , struct V_146 , V_158 ) ;
if ( V_2 -> V_78 . V_162 == V_78 )
F_58 ( V_2 , V_147 ) ;
if ( V_2 -> V_78 . V_168 == V_78 )
V_2 -> V_78 . V_168 = V_147 ;
if ( V_2 -> V_78 . V_177 == V_78 )
V_2 -> V_78 . V_177 = V_147 ;
if ( V_2 -> V_78 . V_179 == V_78 )
V_2 -> V_78 . V_179 = V_147 ;
if ( V_2 -> V_180 == V_78 )
V_2 -> V_180 = NULL ;
if ( V_2 -> V_181 == V_78 )
V_2 -> V_181 = NULL ;
if ( V_2 -> V_182 &&
V_2 -> V_182 -> V_147 == V_78 )
V_2 -> V_182 -> V_147 = NULL ;
if ( ! F_61 ( & V_78 -> V_183 ) ) {
struct V_146 * V_184 = V_2 -> V_78 . V_168 ;
struct V_185 * V_186 ;
F_62 (ch, &peer->transmitted,
transmitted_list) {
V_186 -> V_147 = NULL ;
V_186 -> V_187 = 0 ;
}
F_63 ( & V_78 -> V_183 ,
& V_184 -> V_183 ) ;
if ( ! F_64 ( & V_184 -> V_188 ) )
if ( ! F_65 ( & V_184 -> V_188 ,
V_189 + V_184 -> V_190 ) )
F_66 ( V_184 ) ;
}
V_2 -> V_78 . V_100 -- ;
F_45 ( V_78 ) ;
}
struct V_146 * F_67 ( struct V_1 * V_2 ,
const union V_165 * V_191 ,
const T_2 V_8 ,
const int V_192 )
{
struct V_9 * V_9 = F_2 ( V_2 -> V_15 . V_6 ) ;
struct V_146 * V_78 ;
struct V_10 * V_11 ;
unsigned short V_20 ;
V_11 = F_3 ( V_2 -> V_15 . V_6 ) ;
V_20 = F_20 ( V_191 -> V_193 . V_194 ) ;
F_28 ( L_4 , V_175 ,
V_2 , & V_191 -> V_176 , V_192 ) ;
if ( 0 == V_2 -> V_78 . V_20 )
V_2 -> V_78 . V_20 = V_20 ;
V_78 = F_68 ( V_2 , V_191 ) ;
if ( V_78 ) {
if ( V_78 -> V_21 == V_167 ) {
V_78 -> V_21 = V_166 ;
}
return V_78 ;
}
V_78 = F_69 ( V_9 , V_191 , V_8 ) ;
if ( ! V_78 )
return NULL ;
F_70 ( V_78 , V_2 ) ;
V_78 -> V_40 = V_2 -> V_40 ;
V_78 -> V_41 = V_2 -> V_41 ;
V_78 -> V_30 = V_2 -> V_30 ;
V_78 -> V_43 = V_2 -> V_43 ;
V_78 -> V_44 = V_2 -> V_44 ;
V_78 -> V_45 = V_2 -> V_45 ;
F_71 ( V_78 , NULL , V_11 ) ;
if ( V_78 -> V_45 & V_195 ) {
if ( V_2 -> V_42 )
V_78 -> V_42 = V_2 -> V_42 ;
else
V_78 -> V_42 = V_196 ;
}
if ( V_2 -> V_42 )
V_2 -> V_42 = F_72 ( int , V_78 -> V_42 , V_2 -> V_42 ) ;
else
V_2 -> V_42 = V_78 -> V_42 ;
F_28 ( L_5 , V_175 , V_2 ,
V_2 -> V_42 ) ;
V_78 -> V_197 = 0 ;
V_2 -> V_26 = F_73 ( V_2 , V_2 -> V_42 ) ;
F_74 ( & V_78 -> V_198 , V_78 , V_2 -> V_15 . V_19 . V_20 ,
V_2 -> V_78 . V_20 ) ;
V_78 -> V_199 = F_75 ( 4 * V_2 -> V_42 , F_76 ( V_200 , 2 * V_2 -> V_42 , 4380 ) ) ;
V_78 -> V_201 = V_79 ;
V_78 -> V_202 = 0 ;
V_78 -> V_203 = 0 ;
V_78 -> V_204 = 0 ;
V_78 -> V_190 = V_2 -> V_32 ;
F_77 ( V_2 , V_78 ) ;
V_78 -> V_21 = V_192 ;
F_78 ( & V_78 -> V_158 , & V_2 -> V_78 . V_99 ) ;
V_2 -> V_78 . V_100 ++ ;
if ( ! V_2 -> V_78 . V_162 ) {
F_58 ( V_2 , V_78 ) ;
V_2 -> V_78 . V_177 = V_78 ;
}
if ( V_2 -> V_78 . V_168 == V_2 -> V_78 . V_177 &&
V_78 -> V_21 != V_205 ) {
V_2 -> V_78 . V_177 = V_78 ;
}
return V_78 ;
}
void F_79 ( struct V_1 * V_2 ,
const union V_165 * V_191 )
{
struct V_148 * V_149 ;
struct V_148 * V_150 ;
struct V_146 * V_147 ;
F_42 (pos, temp, &asoc->peer.transport_addr_list) {
V_147 = F_43 ( V_149 , struct V_146 , V_158 ) ;
if ( F_80 ( V_191 , & V_147 -> V_164 ) ) {
F_59 ( V_2 , V_147 ) ;
break;
}
}
}
struct V_146 * F_68 (
const struct V_1 * V_2 ,
const union V_165 * V_206 )
{
struct V_146 * V_207 ;
F_62 (t, &asoc->peer.transport_addr_list,
transports) {
if ( F_80 ( V_206 , & V_207 -> V_164 ) )
return V_207 ;
}
return NULL ;
}
void F_81 ( struct V_1 * V_2 ,
struct V_146 * V_208 )
{
struct V_146 * V_150 ;
struct V_146 * V_207 ;
F_82 (t, temp, &asoc->peer.transport_addr_list,
transports) {
if ( V_207 != V_208 )
F_59 ( V_2 , V_207 ) ;
}
}
void F_83 ( struct V_1 * V_2 ,
struct V_146 * V_147 ,
T_4 V_209 ,
T_5 error )
{
struct V_146 * V_207 = NULL ;
struct V_146 * V_210 ;
struct V_146 * V_211 ;
struct V_212 * V_213 ;
struct V_214 V_191 ;
int V_215 = 0 ;
bool V_216 = true ;
switch ( V_209 ) {
case V_217 :
if ( V_205 == V_147 -> V_21 &&
V_218 == error )
V_215 = V_219 ;
else
V_215 = V_220 ;
if ( V_147 -> V_21 == V_221 ) {
V_216 = false ;
V_147 -> V_199 = V_2 -> V_42 ;
}
V_147 -> V_21 = V_166 ;
break;
case V_222 :
if ( V_147 -> V_21 != V_205 )
V_147 -> V_21 = V_223 ;
else {
F_84 ( V_147 -> V_224 ) ;
V_147 -> V_224 = NULL ;
}
V_215 = V_225 ;
break;
case V_226 :
V_147 -> V_21 = V_221 ;
V_216 = false ;
break;
default:
return;
}
if ( V_216 ) {
memset ( & V_191 , 0 , sizeof( struct V_214 ) ) ;
memcpy ( & V_191 , & V_147 -> V_164 ,
V_147 -> V_227 -> V_228 ) ;
V_213 = F_85 ( V_2 , & V_191 ,
0 , V_215 , error , V_229 ) ;
if ( V_213 )
F_86 ( & V_2 -> V_112 , V_213 ) ;
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
} else if ( ! V_211 ||
V_207 -> V_230 > V_211 -> V_230 )
V_211 = V_207 ;
}
if ( ( ( V_2 -> V_78 . V_162 -> V_21 == V_166 ) ||
( V_2 -> V_78 . V_162 -> V_21 == V_167 ) ) &&
V_210 != V_2 -> V_78 . V_162 ) {
V_211 = V_210 ;
V_210 = V_2 -> V_78 . V_162 ;
}
if ( ! V_211 )
V_211 = V_210 ;
if ( ! V_210 ) {
V_210 = V_2 -> V_78 . V_162 ;
V_211 = V_2 -> V_78 . V_162 ;
}
V_2 -> V_78 . V_168 = V_210 ;
V_2 -> V_78 . V_177 = V_211 ;
}
void F_87 ( struct V_1 * V_2 )
{
F_88 ( & V_2 -> V_15 . V_17 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
if ( F_89 ( & V_2 -> V_15 . V_17 ) )
F_49 ( V_2 ) ;
}
V_200 F_90 ( struct V_1 * V_2 )
{
V_200 V_231 = V_2 -> V_90 ;
V_2 -> V_90 ++ ;
V_2 -> V_95 ++ ;
return V_231 ;
}
int F_80 ( const union V_165 * V_232 ,
const union V_165 * V_233 )
{
struct V_234 * V_235 ;
V_235 = F_91 ( V_232 -> V_176 . V_236 ) ;
if ( F_50 ( ! V_235 ) )
return 0 ;
return V_235 -> V_237 ( V_232 , V_233 ) ;
}
struct V_185 * F_92 ( struct V_1 * V_2 )
{
struct V_185 * V_238 ;
if ( V_2 -> V_116 )
V_238 = F_93 ( V_2 , V_2 -> V_239 ) ;
else
V_238 = NULL ;
return V_238 ;
}
struct V_146 * F_94 ( struct V_1 * V_2 ,
V_200 V_240 )
{
struct V_146 * V_184 ;
struct V_146 * V_241 ;
struct V_146 * V_147 ;
struct V_185 * V_238 ;
T_6 V_242 = F_95 ( V_240 ) ;
V_241 = NULL ;
V_184 = V_2 -> V_78 . V_168 ;
F_62 (chunk, &active->transmitted,
transmitted_list) {
if ( V_242 == V_238 -> V_243 . V_244 -> V_240 ) {
V_241 = V_184 ;
goto V_245;
}
}
F_62 (transport, &asoc->peer.transport_addr_list,
transports) {
if ( V_147 == V_184 )
continue;
F_62 (chunk, &transport->transmitted,
transmitted_list) {
if ( V_242 == V_238 -> V_243 . V_244 -> V_240 ) {
V_241 = V_147 ;
goto V_245;
}
}
}
V_245:
return V_241 ;
}
struct V_146 * F_96 ( struct V_1 * V_2 ,
struct V_9 * V_9 ,
const union V_165 * V_246 ,
const union V_165 * V_247 )
{
struct V_146 * V_147 ;
if ( ( F_21 ( V_2 -> V_15 . V_19 . V_20 ) == V_246 -> V_193 . V_194 ) &&
( F_21 ( V_2 -> V_78 . V_20 ) == V_247 -> V_193 . V_194 ) &&
F_97 ( F_2 ( V_2 -> V_15 . V_6 ) , V_9 ) ) {
V_147 = F_68 ( V_2 , V_247 ) ;
if ( ! V_147 )
goto V_245;
if ( F_98 ( & V_2 -> V_15 . V_19 , V_246 ,
F_3 ( V_2 -> V_15 . V_6 ) ) )
goto V_245;
}
V_147 = NULL ;
V_245:
return V_147 ;
}
static void V_110 ( struct V_248 * V_249 )
{
struct V_1 * V_2 =
F_99 ( V_249 , struct V_1 ,
V_15 . V_109 . V_250 ) ;
struct V_9 * V_9 = F_2 ( V_2 -> V_15 . V_6 ) ;
struct V_3 * V_4 ;
struct V_185 * V_238 ;
struct V_251 * V_109 ;
int V_21 ;
T_7 V_252 ;
int error = 0 ;
V_4 = V_2 -> V_4 ;
V_109 = & V_2 -> V_15 . V_109 ;
F_87 ( V_2 ) ;
while ( NULL != ( V_238 = F_100 ( V_109 ) ) ) {
V_21 = V_2 -> V_21 ;
V_252 = F_101 ( V_238 -> V_253 -> type ) ;
if ( F_102 ( V_252 . V_238 , V_2 ) && ! V_238 -> V_254 )
continue;
if ( F_103 ( V_238 ) )
V_2 -> V_78 . V_179 = V_238 -> V_147 ;
else {
F_104 ( V_9 , V_255 ) ;
V_2 -> V_129 . V_256 ++ ;
if ( V_238 -> V_253 -> type == V_257 )
V_2 -> V_129 . V_258 ++ ;
}
if ( V_238 -> V_147 )
V_238 -> V_147 -> V_230 = V_189 ;
error = F_105 ( V_9 , V_259 , V_252 ,
V_21 , V_4 , V_2 , V_238 , V_229 ) ;
if ( V_2 -> V_15 . V_18 )
break;
if ( error && V_238 )
V_238 -> V_260 = 1 ;
}
F_41 ( V_2 ) ;
}
void F_106 ( struct V_1 * V_145 , struct V_5 * V_261 )
{
struct V_10 * V_262 = F_3 ( V_261 ) ;
struct V_5 * V_263 = V_145 -> V_15 . V_6 ;
F_107 ( & V_145 -> V_122 ) ;
if ( F_32 ( V_263 , V_151 ) )
V_263 -> V_153 -- ;
F_24 ( V_145 -> V_4 ) ;
F_23 ( V_145 -> V_15 . V_6 ) ;
V_145 -> V_4 = V_262 -> V_4 ;
F_4 ( V_145 -> V_4 ) ;
V_145 -> V_15 . V_6 = V_261 ;
F_5 ( V_145 -> V_15 . V_6 ) ;
F_108 ( V_262 -> V_4 , V_145 ) ;
}
void F_109 ( struct V_1 * V_2 ,
struct V_1 * V_264 )
{
struct V_146 * V_265 ;
struct V_148 * V_149 , * V_150 ;
V_2 -> V_63 = V_264 -> V_63 ;
V_2 -> V_78 . V_74 = V_264 -> V_78 . V_74 ;
V_2 -> V_78 . V_101 = V_264 -> V_78 . V_101 ;
V_2 -> V_78 . V_12 = V_264 -> V_78 . V_12 ;
F_110 ( & V_2 -> V_78 . V_114 , V_266 ,
V_2 -> V_78 . V_12 . V_89 , V_229 ) ;
F_42 (pos, temp, &asoc->peer.transport_addr_list) {
V_265 = F_43 ( V_149 , struct V_146 , V_158 ) ;
if ( ! F_68 ( V_264 , & V_265 -> V_164 ) ) {
F_59 ( V_2 , V_265 ) ;
continue;
}
if ( V_2 -> V_21 >= V_267 )
F_111 ( V_265 ) ;
}
if ( V_2 -> V_21 >= V_267 ) {
V_2 -> V_90 = V_264 -> V_90 ;
V_2 -> V_91 = V_264 -> V_91 ;
V_2 -> V_92 = V_264 -> V_92 ;
F_112 ( V_2 -> V_71 ) ;
F_113 ( & V_2 -> V_112 ) ;
V_2 -> V_39 = 0 ;
} else {
F_62 (trans, &new->peer.transport_addr_list,
transports) {
if ( ! F_68 ( V_2 , & V_265 -> V_164 ) )
F_67 ( V_2 , & V_265 -> V_164 ,
V_229 , V_265 -> V_21 ) ;
}
V_2 -> V_91 = V_2 -> V_90 - 1 ;
V_2 -> V_92 = V_2 -> V_91 ;
if ( ! V_2 -> V_71 ) {
V_2 -> V_71 = V_264 -> V_71 ;
V_264 -> V_71 = NULL ;
}
if ( ! V_2 -> V_117 ) {
F_114 ( V_2 , V_229 ) ;
}
}
F_29 ( V_2 -> V_78 . V_155 ) ;
V_2 -> V_78 . V_155 = V_264 -> V_78 . V_155 ;
V_264 -> V_78 . V_155 = NULL ;
F_29 ( V_2 -> V_78 . V_156 ) ;
V_2 -> V_78 . V_156 = V_264 -> V_78 . V_156 ;
V_264 -> V_78 . V_156 = NULL ;
F_29 ( V_2 -> V_78 . V_157 ) ;
V_2 -> V_78 . V_157 = V_264 -> V_78 . V_157 ;
V_264 -> V_78 . V_157 = NULL ;
F_48 ( V_2 -> V_133 ) ;
F_115 ( V_2 , V_229 ) ;
}
void F_60 ( struct V_1 * V_2 )
{
struct V_146 * V_207 , * V_178 ;
struct V_148 * V_268 = & V_2 -> V_78 . V_99 ;
struct V_148 * V_149 ;
if ( V_2 -> V_78 . V_100 == 1 )
return;
V_207 = V_2 -> V_78 . V_177 ;
V_149 = & V_207 -> V_158 ;
V_178 = NULL ;
while ( 1 ) {
if ( V_149 -> V_178 == V_268 )
V_149 = V_268 -> V_178 ;
else
V_149 = V_149 -> V_178 ;
V_207 = F_43 ( V_149 , struct V_146 , V_158 ) ;
if ( V_207 == V_2 -> V_78 . V_177 ) {
V_207 = V_178 ;
break;
}
if ( ( V_207 -> V_21 == V_166 ) ||
( V_207 -> V_21 == V_167 ) ) {
break;
} else {
if ( V_207 -> V_21 != V_205 && ! V_178 )
V_178 = V_207 ;
}
}
if ( V_207 )
V_2 -> V_78 . V_177 = V_207 ;
else
V_207 = V_2 -> V_78 . V_177 ;
F_28 ( L_3 , V_175 , V_2 ,
& V_207 -> V_164 . V_176 ) ;
}
struct V_146 * F_116 (
struct V_1 * V_2 , struct V_146 * V_269 )
{
if ( ! V_269 )
return V_2 -> V_78 . V_168 ;
else {
if ( V_269 == V_2 -> V_78 . V_177 )
F_60 ( V_2 ) ;
return V_2 -> V_78 . V_177 ;
}
}
void F_117 ( struct V_5 * V_6 , struct V_1 * V_2 )
{
struct V_146 * V_207 ;
V_200 V_270 = 0 ;
if ( ! V_2 )
return;
F_62 (t, &asoc->peer.transport_addr_list,
transports) {
if ( V_207 -> V_197 && V_207 -> V_224 ) {
F_118 ( V_6 , V_207 , F_119 ( V_207 -> V_224 ) ) ;
V_207 -> V_197 = 0 ;
}
if ( ! V_270 || ( V_207 -> V_42 < V_270 ) )
V_270 = V_207 -> V_42 ;
}
if ( V_270 ) {
V_2 -> V_42 = V_270 ;
V_2 -> V_26 = F_73 ( V_2 , V_270 ) ;
}
F_28 ( L_6 , V_175 , V_2 ,
V_2 -> V_42 , V_2 -> V_26 ) ;
}
static inline int F_120 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_2 ( V_2 -> V_15 . V_6 ) ;
switch ( V_2 -> V_21 ) {
case V_267 :
case V_271 :
case V_272 :
case V_273 :
if ( ( V_2 -> V_74 > V_2 -> V_75 ) &&
( ( V_2 -> V_74 - V_2 -> V_75 ) >= F_76 ( V_200 ,
( V_2 -> V_15 . V_6 -> V_72 >> V_9 -> V_31 . V_274 ) ,
V_2 -> V_42 ) ) )
return 1 ;
break;
default:
break;
}
return 0 ;
}
void F_121 ( struct V_1 * V_2 , unsigned int V_275 )
{
struct V_185 * V_276 ;
struct V_277 * V_278 ;
if ( V_2 -> V_76 ) {
if ( V_2 -> V_76 >= V_275 ) {
V_2 -> V_76 -= V_275 ;
} else {
V_2 -> V_74 += ( V_275 - V_2 -> V_76 ) ;
V_2 -> V_76 = 0 ;
}
} else {
V_2 -> V_74 += V_275 ;
}
if ( V_2 -> V_77 && V_2 -> V_74 >= V_2 -> V_77 ) {
int V_279 = F_75 ( V_2 -> V_42 , V_2 -> V_77 ) ;
V_2 -> V_74 += V_279 ;
V_2 -> V_77 -= V_279 ;
}
F_28 ( L_7 ,
V_175 , V_2 , V_275 , V_2 -> V_74 , V_2 -> V_76 ,
V_2 -> V_75 ) ;
if ( F_120 ( V_2 ) ) {
V_2 -> V_75 = V_2 -> V_74 ;
F_28 ( L_8
L_9 , V_175 , V_2 , V_2 -> V_74 ,
V_2 -> V_75 ) ;
V_276 = F_122 ( V_2 ) ;
if ( ! V_276 )
return;
V_2 -> V_78 . V_101 = 0 ;
F_123 ( & V_2 -> V_111 , V_276 ) ;
V_278 = & V_2 -> V_61 [ V_56 ] ;
if ( F_40 ( V_278 ) )
F_41 ( V_2 ) ;
}
}
void F_124 ( struct V_1 * V_2 , unsigned int V_275 )
{
int V_280 ;
int V_281 = 0 ;
if ( F_50 ( ! V_2 -> V_74 || V_2 -> V_76 ) )
F_28 ( L_10
L_11 , V_175 , V_2 ,
V_2 -> V_74 , V_2 -> V_76 ) ;
if ( V_2 -> V_4 -> V_282 )
V_280 = F_56 ( & V_2 -> V_81 ) ;
else
V_280 = F_56 ( & V_2 -> V_15 . V_6 -> V_283 ) ;
if ( V_280 >= V_2 -> V_15 . V_6 -> V_72 )
V_281 = 1 ;
if ( V_2 -> V_74 >= V_275 ) {
V_2 -> V_74 -= V_275 ;
if ( V_281 ) {
V_2 -> V_77 += V_2 -> V_74 ;
V_2 -> V_74 = 0 ;
}
} else {
V_2 -> V_76 = V_275 - V_2 -> V_74 ;
V_2 -> V_74 = 0 ;
}
F_28 ( L_12 ,
V_175 , V_2 , V_275 , V_2 -> V_74 , V_2 -> V_76 ,
V_2 -> V_77 ) ;
}
int F_125 ( struct V_1 * V_2 ,
T_1 V_7 , T_2 V_8 )
{
int V_284 ;
V_284 = ( V_120 == V_2 -> V_15 . V_6 -> V_119 ) ? V_285 : 0 ;
if ( V_2 -> V_78 . V_118 )
V_284 |= V_286 ;
if ( V_2 -> V_78 . V_121 )
V_284 |= V_287 ;
return F_126 ( F_2 ( V_2 -> V_15 . V_6 ) ,
& V_2 -> V_15 . V_19 ,
& V_2 -> V_4 -> V_15 . V_19 ,
V_7 , V_8 , V_284 ) ;
}
int F_127 ( struct V_1 * V_2 ,
struct V_288 * V_154 ,
T_2 V_8 )
{
int V_289 = F_20 ( V_154 -> V_290 -> V_253 . V_138 ) ;
int V_291 = V_154 -> V_292 ;
T_8 * V_293 = ( T_8 * ) V_154 -> V_290 + V_289 ;
return F_128 ( & V_2 -> V_15 . V_19 , V_293 , V_291 ,
V_2 -> V_4 -> V_15 . V_19 . V_20 , V_8 ) ;
}
int F_129 ( struct V_1 * V_2 ,
const union V_165 * V_246 )
{
int V_294 = 0 ;
if ( ( V_2 -> V_15 . V_19 . V_20 == F_20 ( V_246 -> V_193 . V_194 ) ) &&
F_98 ( & V_2 -> V_15 . V_19 , V_246 ,
F_3 ( V_2 -> V_15 . V_6 ) ) )
V_294 = 1 ;
return V_294 ;
}
int F_114 ( struct V_1 * V_2 , T_2 V_8 )
{
bool V_295 = V_8 & V_296 ;
int V_297 ;
if ( V_2 -> V_117 )
return 0 ;
if ( V_295 )
F_130 ( V_8 ) ;
F_52 ( & V_159 ) ;
V_297 = F_131 ( & V_160 , V_2 , 1 , 0 , V_298 ) ;
F_54 ( & V_159 ) ;
if ( V_295 )
F_132 () ;
if ( V_297 < 0 )
return V_297 ;
V_2 -> V_117 = ( V_299 ) V_297 ;
return 0 ;
}
static void F_133 ( struct V_1 * V_2 )
{
struct V_185 * V_300 ;
struct V_185 * V_301 ;
F_82 (asconf, tmp, &asoc->addip_chunk_list, list) {
F_107 ( & V_300 -> V_302 ) ;
F_134 ( V_300 ) ;
}
}
static void F_135 ( struct V_1 * V_2 )
{
struct V_185 * V_303 ;
struct V_185 * V_301 ;
F_82 (ack, tmp, &asoc->asconf_ack_list,
transmitted_list) {
F_107 ( & V_303 -> V_304 ) ;
F_134 ( V_303 ) ;
}
}
void F_136 ( const struct V_1 * V_2 )
{
struct V_185 * V_303 ;
struct V_185 * V_301 ;
F_82 (ack, tmp, &asoc->asconf_ack_list,
transmitted_list) {
if ( V_303 -> V_243 . V_305 -> V_306 ==
F_95 ( V_2 -> V_78 . V_96 ) )
break;
F_107 ( & V_303 -> V_304 ) ;
F_134 ( V_303 ) ;
}
}
struct V_185 * F_137 (
const struct V_1 * V_2 ,
T_6 V_306 )
{
struct V_185 * V_303 ;
F_62 (ack, &asoc->asconf_ack_list, transmitted_list) {
if ( V_303 -> V_243 . V_305 -> V_306 == V_306 ) {
F_138 ( V_303 ) ;
return V_303 ;
}
}
return NULL ;
}
void F_46 ( struct V_1 * V_2 )
{
F_135 ( V_2 ) ;
F_133 ( V_2 ) ;
if ( V_2 -> V_182 )
F_134 ( V_2 -> V_182 ) ;
}
