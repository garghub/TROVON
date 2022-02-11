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
( unsigned long ) V_10 -> V_58 * V_59 ;
for ( V_11 = V_48 ; V_11 < V_60 ; ++ V_11 )
F_8 ( & V_2 -> V_61 [ V_11 ] , V_62 [ V_11 ] ,
( unsigned long ) V_2 ) ;
V_2 -> V_63 . V_64 = V_10 -> V_65 . V_64 ;
V_2 -> V_63 . V_66 = V_10 -> V_65 . V_66 ;
V_2 -> V_67 = V_10 -> V_65 . V_68 ;
V_2 -> V_69 =
F_7 ( V_10 -> V_65 . V_70 ) ;
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
F_5 ( & V_2 -> V_81 , 0 ) ;
F_9 ( & V_2 -> V_82 ) ;
V_2 -> V_63 . V_83 = F_10 ( V_4 ) ;
V_2 -> V_78 . V_11 . V_84 = 0 ;
V_2 -> V_63 . V_85 = 0 ;
V_2 -> V_63 . V_86 = 0 ;
V_2 -> V_63 . V_87 = 0 ;
V_2 -> V_63 . V_88 = V_4 -> V_14 . V_19 . V_20 ;
V_2 -> V_63 . V_89 = F_11 ( V_4 ) ;
V_2 -> V_90 = V_2 -> V_63 . V_89 ;
V_2 -> V_91 = V_2 -> V_90 - 1 ;
V_2 -> V_92 = V_2 -> V_91 ;
V_2 -> V_93 = V_2 -> V_91 ;
V_2 -> V_94 = V_2 -> V_91 ;
V_2 -> V_95 = 0 ;
V_2 -> V_96 = V_2 -> V_63 . V_89 ;
F_12 ( & V_2 -> V_97 ) ;
F_12 ( & V_2 -> V_98 ) ;
F_12 ( & V_2 -> V_78 . V_99 ) ;
V_2 -> V_78 . V_100 = 0 ;
V_2 -> V_78 . V_101 = 1 ;
V_2 -> V_78 . V_102 = 0 ;
V_2 -> V_78 . V_103 = 0 ;
if ( V_104 )
V_2 -> V_78 . V_103 = 1 ;
F_13 ( & V_2 -> V_14 . V_105 ) ;
F_14 ( & V_2 -> V_14 . V_105 , V_106 ) ;
F_15 ( V_2 , & V_2 -> V_107 ) ;
if ( ! F_16 ( & V_2 -> V_108 , V_2 ) )
goto V_109;
memset ( & V_2 -> V_78 . V_110 , 0 , sizeof( struct V_111 ) ) ;
V_2 -> V_112 = 0 ;
V_2 -> V_113 = 0 ;
V_2 -> V_78 . V_114 = 1 ;
if ( V_2 -> V_14 . V_6 -> V_115 == V_116 )
V_2 -> V_78 . V_117 = 1 ;
F_12 ( & V_2 -> V_118 ) ;
V_2 -> V_58 = V_10 -> V_58 ;
V_2 -> V_119 = V_10 -> V_119 ;
V_2 -> V_120 = V_10 -> V_120 ;
V_2 -> V_121 = V_10 -> V_121 ;
V_2 -> V_122 = V_10 -> V_122 ;
V_2 -> V_123 = V_10 -> V_123 ;
V_2 -> V_124 = V_10 -> V_124 ;
F_12 ( & V_2 -> V_125 ) ;
V_13 = F_17 ( V_4 , V_2 , V_8 ) ;
if ( V_13 )
goto V_109;
V_2 -> V_126 = V_4 -> V_126 ;
V_2 -> V_127 = NULL ;
V_2 -> V_128 = 0 ;
if ( V_4 -> V_129 )
memcpy ( V_2 -> V_63 . V_130 , V_4 -> V_129 ,
F_18 ( V_4 -> V_129 -> V_131 . V_132 ) ) ;
if ( V_4 -> V_133 )
memcpy ( V_2 -> V_63 . V_134 , V_4 -> V_133 ,
F_18 ( V_4 -> V_133 -> V_131 . V_132 ) ) ;
V_12 = ( T_3 * ) V_2 -> V_63 . V_135 ;
V_12 -> type = V_136 ;
V_12 -> V_132 = F_19 ( sizeof( T_3 ) + V_137 ) ;
F_20 ( V_12 + 1 , V_137 ) ;
return V_2 ;
V_109:
F_21 ( V_2 -> V_4 ) ;
F_22 ( V_2 -> V_14 . V_6 ) ;
return NULL ;
}
struct V_1 * F_23 ( const struct V_3 * V_4 ,
const struct V_5 * V_6 ,
T_1 V_7 ,
T_2 V_8 )
{
struct V_1 * V_2 ;
V_2 = F_24 ( struct V_1 , V_8 ) ;
if ( ! V_2 )
goto V_138;
if ( ! F_1 ( V_2 , V_4 , V_6 , V_7 , V_8 ) )
goto V_109;
V_2 -> V_14 . V_18 = 1 ;
F_25 ( V_139 ) ;
F_26 ( L_1 , V_2 ) ;
return V_2 ;
V_109:
F_27 ( V_2 ) ;
V_138:
return NULL ;
}
void F_28 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_14 . V_6 ;
struct V_140 * V_141 ;
struct V_142 * V_143 , * V_144 ;
int V_11 ;
if ( ! V_2 -> V_144 ) {
F_29 ( & V_2 -> V_118 ) ;
if ( F_30 ( V_6 , V_145 ) && F_31 ( V_6 , V_146 ) )
V_6 -> V_147 -- ;
}
V_2 -> V_14 . V_17 = 1 ;
F_32 ( & V_2 -> V_107 ) ;
F_33 ( & V_2 -> V_108 ) ;
F_34 ( & V_2 -> V_14 . V_105 ) ;
F_35 ( & V_2 -> V_78 . V_110 ) ;
F_36 ( V_2 -> V_71 ) ;
F_37 ( & V_2 -> V_14 . V_19 ) ;
for ( V_11 = V_48 ; V_11 < V_60 ; ++ V_11 ) {
if ( F_38 ( & V_2 -> V_61 [ V_11 ] ) &&
F_39 ( & V_2 -> V_61 [ V_11 ] ) )
F_40 ( V_2 ) ;
}
F_27 ( V_2 -> V_78 . V_148 ) ;
F_27 ( V_2 -> V_78 . V_149 ) ;
F_27 ( V_2 -> V_78 . V_150 ) ;
F_27 ( V_2 -> V_78 . V_151 ) ;
F_41 (pos, temp, &asoc->peer.transport_addr_list) {
V_141 = F_42 ( V_143 , struct V_140 , V_152 ) ;
F_29 ( V_143 ) ;
F_43 ( V_141 ) ;
}
V_2 -> V_78 . V_100 = 0 ;
F_44 ( V_2 ) ;
F_45 ( & V_2 -> V_125 ) ;
F_46 ( V_2 -> V_127 ) ;
F_40 ( V_2 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
F_48 (asoc->base.dead, L_2 , return) ;
F_21 ( V_2 -> V_4 ) ;
F_22 ( V_2 -> V_14 . V_6 ) ;
if ( V_2 -> V_113 != 0 ) {
F_49 ( & V_153 ) ;
F_50 ( & V_154 , V_2 -> V_113 ) ;
F_51 ( & V_153 ) ;
}
F_52 ( F_53 ( & V_2 -> V_81 ) ) ;
if ( V_2 -> V_14 . V_18 ) {
F_27 ( V_2 ) ;
F_54 ( V_139 ) ;
}
}
void F_55 ( struct V_1 * V_2 ,
struct V_140 * V_141 )
{
int V_155 = 0 ;
if ( V_2 -> V_78 . V_156 != NULL &&
V_2 -> V_78 . V_156 != V_141 )
V_155 = 1 ;
V_2 -> V_78 . V_156 = V_141 ;
memcpy ( & V_2 -> V_78 . V_157 , & V_141 -> V_158 ,
sizeof( union V_159 ) ) ;
if ( ( V_141 -> V_21 == V_160 ) ||
( V_141 -> V_21 == V_161 ) )
V_2 -> V_78 . V_162 = V_141 ;
if ( ! V_2 -> V_107 . V_163 && ! V_2 -> V_107 . V_164 )
return;
if ( V_141 -> V_165 . V_166 )
V_141 -> V_165 . V_167 = V_155 ;
V_141 -> V_165 . V_166 = V_155 ;
V_141 -> V_165 . V_168 = V_2 -> V_90 ;
}
void F_56 ( struct V_1 * V_2 ,
struct V_140 * V_78 )
{
struct V_142 * V_143 ;
struct V_140 * V_141 ;
F_57 ( L_3 ,
L_4 ,
V_2 ,
( & V_78 -> V_158 ) ,
F_18 ( V_78 -> V_158 . V_169 . V_170 ) ) ;
if ( V_2 -> V_78 . V_171 == V_78 )
F_58 ( V_2 ) ;
F_29 ( & V_78 -> V_152 ) ;
V_143 = V_2 -> V_78 . V_99 . V_172 ;
V_141 = F_42 ( V_143 , struct V_140 , V_152 ) ;
if ( V_2 -> V_78 . V_156 == V_78 )
F_55 ( V_2 , V_141 ) ;
if ( V_2 -> V_78 . V_162 == V_78 )
V_2 -> V_78 . V_162 = V_141 ;
if ( V_2 -> V_78 . V_171 == V_78 )
V_2 -> V_78 . V_171 = V_141 ;
if ( V_2 -> V_78 . V_173 == V_78 )
V_2 -> V_78 . V_173 = V_141 ;
if ( V_2 -> V_174 == V_78 )
V_2 -> V_174 = NULL ;
if ( V_2 -> V_175 == V_78 )
V_2 -> V_175 = NULL ;
if ( V_2 -> V_176 &&
V_2 -> V_176 -> V_141 == V_78 )
V_2 -> V_176 -> V_141 = NULL ;
if ( ! F_59 ( & V_78 -> V_177 ) ) {
struct V_140 * V_178 = V_2 -> V_78 . V_162 ;
struct V_179 * V_180 ;
F_60 (ch, &peer->transmitted,
transmitted_list) {
V_180 -> V_141 = NULL ;
V_180 -> V_181 = 0 ;
}
F_61 ( & V_78 -> V_177 ,
& V_178 -> V_177 ) ;
if ( ! F_38 ( & V_178 -> V_182 ) )
if ( ! F_62 ( & V_178 -> V_182 ,
V_183 + V_178 -> V_184 ) )
F_63 ( V_178 ) ;
}
V_2 -> V_78 . V_100 -- ;
F_43 ( V_78 ) ;
}
struct V_140 * F_64 ( struct V_1 * V_2 ,
const union V_159 * V_185 ,
const T_2 V_8 ,
const int V_186 )
{
struct V_140 * V_78 ;
struct V_9 * V_10 ;
unsigned short V_20 ;
V_10 = F_2 ( V_2 -> V_14 . V_6 ) ;
V_20 = F_18 ( V_185 -> V_169 . V_170 ) ;
F_57 ( L_5 ,
L_6 ,
V_2 ,
V_185 ,
V_20 ,
V_186 ) ;
if ( 0 == V_2 -> V_78 . V_20 )
V_2 -> V_78 . V_20 = V_20 ;
V_78 = F_65 ( V_2 , V_185 ) ;
if ( V_78 ) {
if ( V_78 -> V_21 == V_161 ) {
V_78 -> V_21 = V_160 ;
}
return V_78 ;
}
V_78 = F_66 ( V_185 , V_8 ) ;
if ( ! V_78 )
return NULL ;
F_67 ( V_78 , V_2 ) ;
V_78 -> V_40 = V_2 -> V_40 ;
V_78 -> V_41 = V_2 -> V_41 ;
V_78 -> V_43 = V_2 -> V_43 ;
V_78 -> V_44 = V_2 -> V_44 ;
V_78 -> V_45 = V_2 -> V_45 ;
F_68 ( V_78 , NULL , V_10 ) ;
if ( V_78 -> V_45 & V_187 ) {
if ( V_2 -> V_42 )
V_78 -> V_42 = V_2 -> V_42 ;
else
V_78 -> V_42 = V_188 ;
}
if ( V_2 -> V_42 )
V_2 -> V_42 = F_69 ( int , V_78 -> V_42 , V_2 -> V_42 ) ;
else
V_2 -> V_42 = V_78 -> V_42 ;
F_26 ( L_7
L_8 , V_2 , V_2 -> V_42 ) ;
V_78 -> V_189 = 0 ;
V_2 -> V_28 = F_70 ( V_2 , V_2 -> V_42 ) ;
F_71 ( & V_78 -> V_190 , V_78 , V_2 -> V_14 . V_19 . V_20 ,
V_2 -> V_78 . V_20 ) ;
V_78 -> V_191 = F_72 ( 4 * V_2 -> V_42 , F_73 ( V_192 , 2 * V_2 -> V_42 , 4380 ) ) ;
V_78 -> V_193 = V_79 ;
V_78 -> V_194 = 0 ;
V_78 -> V_195 = 0 ;
V_78 -> V_196 = 0 ;
V_78 -> V_184 = V_2 -> V_32 ;
V_78 -> V_21 = V_186 ;
F_74 ( & V_78 -> V_152 , & V_2 -> V_78 . V_99 ) ;
V_2 -> V_78 . V_100 ++ ;
if ( ! V_2 -> V_78 . V_156 ) {
F_55 ( V_2 , V_78 ) ;
V_2 -> V_78 . V_171 = V_78 ;
}
if ( V_2 -> V_78 . V_162 == V_2 -> V_78 . V_171 &&
V_78 -> V_21 != V_197 ) {
V_2 -> V_78 . V_171 = V_78 ;
}
return V_78 ;
}
void F_75 ( struct V_1 * V_2 ,
const union V_159 * V_185 )
{
struct V_142 * V_143 ;
struct V_142 * V_144 ;
struct V_140 * V_141 ;
F_41 (pos, temp, &asoc->peer.transport_addr_list) {
V_141 = F_42 ( V_143 , struct V_140 , V_152 ) ;
if ( F_76 ( V_185 , & V_141 -> V_158 ) ) {
F_56 ( V_2 , V_141 ) ;
break;
}
}
}
struct V_140 * F_65 (
const struct V_1 * V_2 ,
const union V_159 * V_198 )
{
struct V_140 * V_199 ;
F_60 (t, &asoc->peer.transport_addr_list,
transports) {
if ( F_76 ( V_198 , & V_199 -> V_158 ) )
return V_199 ;
}
return NULL ;
}
void F_77 ( struct V_1 * V_2 ,
struct V_140 * V_200 )
{
struct V_140 * V_144 ;
struct V_140 * V_199 ;
F_78 (t, temp, &asoc->peer.transport_addr_list,
transports) {
if ( V_199 != V_200 )
F_56 ( V_2 , V_199 ) ;
}
}
void F_79 ( struct V_1 * V_2 ,
struct V_140 * V_141 ,
T_4 V_201 ,
T_5 error )
{
struct V_140 * V_199 = NULL ;
struct V_140 * V_202 ;
struct V_140 * V_203 ;
struct V_204 * V_205 ;
struct V_206 V_185 ;
int V_207 = 0 ;
switch ( V_201 ) {
case V_208 :
if ( V_197 == V_141 -> V_21 &&
V_209 == error )
V_207 = V_210 ;
else
V_207 = V_211 ;
V_141 -> V_21 = V_160 ;
break;
case V_212 :
if ( V_141 -> V_21 != V_197 )
V_141 -> V_21 = V_213 ;
else {
F_80 ( V_141 -> V_214 ) ;
V_141 -> V_214 = NULL ;
}
V_207 = V_215 ;
break;
default:
return;
}
memset ( & V_185 , 0 , sizeof( struct V_206 ) ) ;
memcpy ( & V_185 , & V_141 -> V_158 , V_141 -> V_216 -> V_217 ) ;
V_205 = F_81 ( V_2 , & V_185 ,
0 , V_207 , error , V_218 ) ;
if ( V_205 )
F_82 ( & V_2 -> V_108 , V_205 ) ;
V_202 = NULL ; V_203 = NULL ;
F_60 (t, &asoc->peer.transport_addr_list,
transports) {
if ( ( V_199 -> V_21 == V_213 ) ||
( V_199 -> V_21 == V_197 ) )
continue;
if ( ! V_202 || V_199 -> V_219 > V_202 -> V_219 ) {
V_203 = V_202 ;
V_202 = V_199 ;
}
if ( ! V_203 || V_199 -> V_219 > V_203 -> V_219 )
V_203 = V_199 ;
}
if ( ( ( V_2 -> V_78 . V_156 -> V_21 == V_160 ) ||
( V_2 -> V_78 . V_156 -> V_21 == V_161 ) ) &&
V_202 != V_2 -> V_78 . V_156 ) {
V_203 = V_202 ;
V_202 = V_2 -> V_78 . V_156 ;
}
if ( ! V_202 ) {
V_202 = V_2 -> V_78 . V_156 ;
V_203 = V_2 -> V_78 . V_156 ;
}
V_2 -> V_78 . V_162 = V_202 ;
V_2 -> V_78 . V_171 = V_203 ;
}
void F_83 ( struct V_1 * V_2 )
{
F_84 ( & V_2 -> V_14 . V_16 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
if ( F_85 ( & V_2 -> V_14 . V_16 ) )
F_47 ( V_2 ) ;
}
V_192 F_86 ( struct V_1 * V_2 )
{
V_192 V_220 = V_2 -> V_90 ;
V_2 -> V_90 ++ ;
V_2 -> V_95 ++ ;
return V_220 ;
}
int F_76 ( const union V_159 * V_221 ,
const union V_159 * V_222 )
{
struct V_223 * V_224 ;
V_224 = F_87 ( V_221 -> V_225 . V_226 ) ;
if ( F_88 ( ! V_224 ) )
return 0 ;
return V_224 -> V_227 ( V_221 , V_222 ) ;
}
struct V_179 * F_89 ( struct V_1 * V_2 )
{
struct V_179 * V_228 ;
if ( V_2 -> V_112 )
V_228 = F_90 ( V_2 , V_2 -> V_229 ) ;
else
V_228 = NULL ;
return V_228 ;
}
struct V_140 * F_91 ( struct V_1 * V_2 ,
V_192 V_230 )
{
struct V_140 * V_178 ;
struct V_140 * V_231 ;
struct V_140 * V_141 ;
struct V_179 * V_228 ;
T_6 V_232 = F_92 ( V_230 ) ;
V_231 = NULL ;
V_178 = V_2 -> V_78 . V_162 ;
F_60 (chunk, &active->transmitted,
transmitted_list) {
if ( V_232 == V_228 -> V_233 . V_234 -> V_230 ) {
V_231 = V_178 ;
goto V_235;
}
}
F_60 (transport, &asoc->peer.transport_addr_list,
transports) {
if ( V_141 == V_178 )
break;
F_60 (chunk, &transport->transmitted,
transmitted_list) {
if ( V_232 == V_228 -> V_233 . V_234 -> V_230 ) {
V_231 = V_141 ;
goto V_235;
}
}
}
V_235:
return V_231 ;
}
struct V_140 * F_93 ( struct V_1 * V_2 ,
const union V_159 * V_236 ,
const union V_159 * V_237 )
{
struct V_140 * V_141 ;
if ( ( F_19 ( V_2 -> V_14 . V_19 . V_20 ) == V_236 -> V_169 . V_170 ) &&
( F_19 ( V_2 -> V_78 . V_20 ) == V_237 -> V_169 . V_170 ) ) {
V_141 = F_65 ( V_2 , V_237 ) ;
if ( ! V_141 )
goto V_235;
if ( F_94 ( & V_2 -> V_14 . V_19 , V_236 ,
F_2 ( V_2 -> V_14 . V_6 ) ) )
goto V_235;
}
V_141 = NULL ;
V_235:
return V_141 ;
}
static void V_106 ( struct V_238 * V_239 )
{
struct V_1 * V_2 =
F_95 ( V_239 , struct V_1 ,
V_14 . V_105 . V_240 ) ;
struct V_3 * V_4 ;
struct V_179 * V_228 ;
struct V_241 * V_105 ;
int V_21 ;
T_7 V_242 ;
int error = 0 ;
V_4 = V_2 -> V_4 ;
V_105 = & V_2 -> V_14 . V_105 ;
F_83 ( V_2 ) ;
while ( NULL != ( V_228 = F_96 ( V_105 ) ) ) {
V_21 = V_2 -> V_21 ;
V_242 = F_97 ( V_228 -> V_243 -> type ) ;
if ( F_98 ( V_242 . V_228 , V_2 ) && ! V_228 -> V_244 )
continue;
if ( F_99 ( V_228 ) )
V_2 -> V_78 . V_173 = V_228 -> V_141 ;
else
F_100 ( V_245 ) ;
if ( V_228 -> V_141 )
V_228 -> V_141 -> V_219 = V_183 ;
error = F_101 ( V_246 , V_242 ,
V_21 , V_4 , V_2 , V_228 , V_218 ) ;
if ( V_2 -> V_14 . V_17 )
break;
if ( error && V_228 )
V_228 -> V_247 = 1 ;
}
F_40 ( V_2 ) ;
}
void F_102 ( struct V_1 * V_139 , struct V_5 * V_248 )
{
struct V_9 * V_249 = F_2 ( V_248 ) ;
struct V_5 * V_250 = V_139 -> V_14 . V_6 ;
F_103 ( & V_139 -> V_118 ) ;
if ( F_30 ( V_250 , V_145 ) )
V_250 -> V_147 -- ;
F_21 ( V_139 -> V_4 ) ;
F_22 ( V_139 -> V_14 . V_6 ) ;
V_139 -> V_4 = V_249 -> V_4 ;
F_3 ( V_139 -> V_4 ) ;
V_139 -> V_14 . V_6 = V_248 ;
F_4 ( V_139 -> V_14 . V_6 ) ;
F_104 ( V_249 -> V_4 , V_139 ) ;
}
void F_105 ( struct V_1 * V_2 ,
struct V_1 * V_251 )
{
struct V_140 * V_252 ;
struct V_142 * V_143 , * V_144 ;
V_2 -> V_63 = V_251 -> V_63 ;
V_2 -> V_78 . V_74 = V_251 -> V_78 . V_74 ;
V_2 -> V_78 . V_101 = V_251 -> V_78 . V_101 ;
V_2 -> V_78 . V_11 = V_251 -> V_78 . V_11 ;
F_106 ( & V_2 -> V_78 . V_110 , V_253 ,
V_2 -> V_78 . V_11 . V_89 , V_218 ) ;
F_41 (pos, temp, &asoc->peer.transport_addr_list) {
V_252 = F_42 ( V_143 , struct V_140 , V_152 ) ;
if ( ! F_65 ( V_251 , & V_252 -> V_158 ) ) {
F_56 ( V_2 , V_252 ) ;
continue;
}
if ( V_2 -> V_21 >= V_254 )
F_107 ( V_252 ) ;
}
if ( V_2 -> V_21 >= V_254 ) {
V_2 -> V_90 = V_251 -> V_90 ;
V_2 -> V_91 = V_251 -> V_91 ;
V_2 -> V_92 = V_251 -> V_92 ;
F_108 ( V_2 -> V_71 ) ;
F_109 ( & V_2 -> V_108 ) ;
V_2 -> V_39 = 0 ;
} else {
F_60 (trans, &new->peer.transport_addr_list,
transports) {
if ( ! F_65 ( V_2 , & V_252 -> V_158 ) )
F_64 ( V_2 , & V_252 -> V_158 ,
V_218 , V_252 -> V_21 ) ;
}
V_2 -> V_91 = V_2 -> V_90 - 1 ;
V_2 -> V_92 = V_2 -> V_91 ;
if ( ! V_2 -> V_71 ) {
V_2 -> V_71 = V_251 -> V_71 ;
V_251 -> V_71 = NULL ;
}
if ( ! V_2 -> V_113 ) {
F_110 ( V_2 , V_218 ) ;
}
}
F_27 ( V_2 -> V_78 . V_149 ) ;
V_2 -> V_78 . V_149 = V_251 -> V_78 . V_149 ;
V_251 -> V_78 . V_149 = NULL ;
F_27 ( V_2 -> V_78 . V_150 ) ;
V_2 -> V_78 . V_150 = V_251 -> V_78 . V_150 ;
V_251 -> V_78 . V_150 = NULL ;
F_27 ( V_2 -> V_78 . V_151 ) ;
V_2 -> V_78 . V_151 = V_251 -> V_78 . V_151 ;
V_251 -> V_78 . V_151 = NULL ;
F_46 ( V_2 -> V_127 ) ;
F_111 ( V_2 , V_218 ) ;
}
void F_58 ( struct V_1 * V_2 )
{
struct V_140 * V_199 , * V_172 ;
struct V_142 * V_255 = & V_2 -> V_78 . V_99 ;
struct V_142 * V_143 ;
if ( V_2 -> V_78 . V_100 == 1 )
return;
V_199 = V_2 -> V_78 . V_171 ;
V_143 = & V_199 -> V_152 ;
V_172 = NULL ;
while ( 1 ) {
if ( V_143 -> V_172 == V_255 )
V_143 = V_255 -> V_172 ;
else
V_143 = V_143 -> V_172 ;
V_199 = F_42 ( V_143 , struct V_140 , V_152 ) ;
if ( V_199 == V_2 -> V_78 . V_171 ) {
V_199 = V_172 ;
break;
}
if ( ( V_199 -> V_21 == V_160 ) ||
( V_199 -> V_21 == V_161 ) ) {
break;
} else {
if ( V_199 -> V_21 != V_197 && ! V_172 )
V_172 = V_199 ;
}
}
if ( V_199 )
V_2 -> V_78 . V_171 = V_199 ;
else
V_199 = V_2 -> V_78 . V_171 ;
F_57 ( L_9
L_10 ,
L_4 ,
V_2 ,
( & V_199 -> V_158 ) ,
F_18 ( V_199 -> V_158 . V_169 . V_170 ) ) ;
}
struct V_140 * F_112 (
struct V_1 * V_2 , struct V_140 * V_256 )
{
if ( ! V_256 )
return V_2 -> V_78 . V_162 ;
else {
if ( V_256 == V_2 -> V_78 . V_171 )
F_58 ( V_2 ) ;
return V_2 -> V_78 . V_171 ;
}
}
void F_113 ( struct V_1 * V_2 )
{
struct V_140 * V_199 ;
V_192 V_257 = 0 ;
if ( ! V_2 )
return;
F_60 (t, &asoc->peer.transport_addr_list,
transports) {
if ( V_199 -> V_189 && V_199 -> V_214 ) {
F_114 ( V_199 , F_115 ( V_199 -> V_214 ) ) ;
V_199 -> V_189 = 0 ;
}
if ( ! V_257 || ( V_199 -> V_42 < V_257 ) )
V_257 = V_199 -> V_42 ;
}
if ( V_257 ) {
V_2 -> V_42 = V_257 ;
V_2 -> V_28 = F_70 ( V_2 , V_257 ) ;
}
F_26 ( L_11 ,
V_258 , V_2 , V_2 -> V_42 , V_2 -> V_28 ) ;
}
static inline int F_116 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_21 ) {
case V_254 :
case V_259 :
case V_260 :
case V_261 :
if ( ( V_2 -> V_74 > V_2 -> V_75 ) &&
( ( V_2 -> V_74 - V_2 -> V_75 ) >= F_73 ( V_192 ,
( V_2 -> V_14 . V_6 -> V_72 >> V_262 ) ,
V_2 -> V_42 ) ) )
return 1 ;
break;
default:
break;
}
return 0 ;
}
void F_117 ( struct V_1 * V_2 , unsigned V_263 )
{
struct V_179 * V_264 ;
struct V_265 * V_266 ;
if ( V_2 -> V_76 ) {
if ( V_2 -> V_76 >= V_263 ) {
V_2 -> V_76 -= V_263 ;
} else {
V_2 -> V_74 += ( V_263 - V_2 -> V_76 ) ;
V_2 -> V_76 = 0 ;
}
} else {
V_2 -> V_74 += V_263 ;
}
if ( V_2 -> V_77 && V_2 -> V_74 >= V_2 -> V_77 ) {
int V_267 = F_72 ( V_2 -> V_42 , V_2 -> V_77 ) ;
V_2 -> V_74 += V_267 ;
V_2 -> V_77 -= V_267 ;
}
F_26 ( L_12
L_13 , V_258 , V_2 , V_263 , V_2 -> V_74 ,
V_2 -> V_76 , V_2 -> V_75 ) ;
if ( F_116 ( V_2 ) ) {
V_2 -> V_75 = V_2 -> V_74 ;
F_26 ( L_14
L_15 , V_258 ,
V_2 , V_2 -> V_74 , V_2 -> V_75 ) ;
V_264 = F_118 ( V_2 ) ;
if ( ! V_264 )
return;
V_2 -> V_78 . V_101 = 0 ;
F_119 ( & V_2 -> V_107 , V_264 ) ;
V_266 = & V_2 -> V_61 [ V_56 ] ;
if ( F_38 ( V_266 ) && F_39 ( V_266 ) )
F_40 ( V_2 ) ;
}
}
void F_120 ( struct V_1 * V_2 , unsigned V_263 )
{
int V_268 ;
int V_269 = 0 ;
F_48 (asoc->rwnd, L_16 , return) ;
F_48 (!asoc->rwnd_over, L_17 , return) ;
if ( V_2 -> V_4 -> V_270 )
V_268 = F_53 ( & V_2 -> V_81 ) ;
else
V_268 = F_53 ( & V_2 -> V_14 . V_6 -> V_271 ) ;
if ( V_268 >= V_2 -> V_14 . V_6 -> V_72 )
V_269 = 1 ;
if ( V_2 -> V_74 >= V_263 ) {
V_2 -> V_74 -= V_263 ;
if ( V_269 ) {
V_2 -> V_77 += V_2 -> V_74 ;
V_2 -> V_74 = 0 ;
}
} else {
V_2 -> V_76 = V_263 - V_2 -> V_74 ;
V_2 -> V_74 = 0 ;
}
F_26 ( L_18 ,
V_258 , V_2 , V_263 , V_2 -> V_74 ,
V_2 -> V_76 , V_2 -> V_77 ) ;
}
int F_121 ( struct V_1 * V_2 ,
T_1 V_7 , T_2 V_8 )
{
int V_272 ;
V_272 = ( V_116 == V_2 -> V_14 . V_6 -> V_115 ) ? V_273 : 0 ;
if ( V_2 -> V_78 . V_114 )
V_272 |= V_274 ;
if ( V_2 -> V_78 . V_117 )
V_272 |= V_275 ;
return F_122 ( & V_2 -> V_14 . V_19 ,
& V_2 -> V_4 -> V_14 . V_19 ,
V_7 , V_8 , V_272 ) ;
}
int F_123 ( struct V_1 * V_2 ,
struct V_276 * V_148 ,
T_2 V_8 )
{
int V_277 = F_18 ( V_148 -> V_278 -> V_243 . V_132 ) ;
int V_279 = V_148 -> V_280 ;
T_8 * V_281 = ( T_8 * ) V_148 -> V_278 + V_277 ;
return F_124 ( & V_2 -> V_14 . V_19 , V_281 , V_279 ,
V_2 -> V_4 -> V_14 . V_19 . V_20 , V_8 ) ;
}
int F_125 ( struct V_1 * V_2 ,
const union V_159 * V_236 )
{
int V_282 = 0 ;
if ( ( V_2 -> V_14 . V_19 . V_20 == F_18 ( V_236 -> V_169 . V_170 ) ) &&
F_94 ( & V_2 -> V_14 . V_19 , V_236 ,
F_2 ( V_2 -> V_14 . V_6 ) ) )
V_282 = 1 ;
return V_282 ;
}
int F_110 ( struct V_1 * V_2 , T_2 V_8 )
{
int V_113 ;
int error = 0 ;
if ( V_2 -> V_113 )
return error ;
V_283:
if ( F_88 ( ! F_126 ( & V_154 , V_8 ) ) )
return - V_284 ;
F_49 ( & V_153 ) ;
error = F_127 ( & V_154 , ( void * ) V_2 ,
V_285 , & V_113 ) ;
if ( ! error ) {
V_285 = V_113 + 1 ;
if ( V_285 == V_286 )
V_285 = 1 ;
}
F_51 ( & V_153 ) ;
if ( error == - V_287 )
goto V_283;
else if ( error )
return error ;
V_2 -> V_113 = ( V_288 ) V_113 ;
return error ;
}
static void F_128 ( struct V_1 * V_2 )
{
struct V_179 * V_289 ;
struct V_179 * V_290 ;
F_78 (asconf, tmp, &asoc->addip_chunk_list, list) {
F_103 ( & V_289 -> V_291 ) ;
F_129 ( V_289 ) ;
}
}
static void F_130 ( struct V_1 * V_2 )
{
struct V_179 * V_292 ;
struct V_179 * V_290 ;
F_78 (ack, tmp, &asoc->asconf_ack_list,
transmitted_list) {
F_103 ( & V_292 -> V_293 ) ;
F_129 ( V_292 ) ;
}
}
void F_131 ( const struct V_1 * V_2 )
{
struct V_179 * V_292 ;
struct V_179 * V_290 ;
F_78 (ack, tmp, &asoc->asconf_ack_list,
transmitted_list) {
if ( V_292 -> V_233 . V_294 -> V_295 ==
F_92 ( V_2 -> V_78 . V_96 ) )
break;
F_103 ( & V_292 -> V_293 ) ;
F_129 ( V_292 ) ;
}
}
struct V_179 * F_132 (
const struct V_1 * V_2 ,
T_6 V_295 )
{
struct V_179 * V_292 ;
F_60 (ack, &asoc->asconf_ack_list, transmitted_list) {
if ( V_292 -> V_233 . V_294 -> V_295 == V_295 ) {
F_133 ( V_292 ) ;
return V_292 ;
}
}
return NULL ;
}
void F_44 ( struct V_1 * V_2 )
{
F_130 ( V_2 ) ;
F_128 ( V_2 ) ;
if ( V_2 -> V_176 )
F_129 ( V_2 -> V_176 ) ;
}
