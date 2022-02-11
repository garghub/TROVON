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
V_2 -> V_15 . V_18 = 0 ;
V_2 -> V_15 . V_19 = 0 ;
F_7 ( & V_2 -> V_15 . V_20 , V_4 -> V_15 . V_20 . V_21 ) ;
V_2 -> V_22 = V_23 ;
V_2 -> V_24 . V_25 = V_11 -> V_26 . V_27 / 1000 ;
V_2 -> V_24 . V_28 = ( V_11 -> V_26 . V_27 % 1000 )
* 1000 ;
V_2 -> V_29 = 0 ;
V_2 -> V_30 = V_11 -> V_30 ;
V_2 -> V_31 = V_11 -> V_26 . V_32 ;
V_2 -> V_33 = V_9 -> V_34 . V_33 ;
V_2 -> V_35 = F_8 ( V_11 -> V_36 . V_37 ) ;
V_2 -> V_38 = F_8 ( V_11 -> V_36 . V_39 ) ;
V_2 -> V_40 = F_8 ( V_11 -> V_36 . V_41 ) ;
V_2 -> V_42 = 0 ;
V_2 -> V_43 = F_8 ( V_11 -> V_43 ) ;
V_2 -> V_44 = V_11 -> V_44 ;
V_2 -> V_45 = V_11 -> V_45 ;
V_2 -> V_46 = F_8 ( V_11 -> V_46 ) ;
V_2 -> V_47 = V_11 -> V_47 ;
V_2 -> V_48 = V_11 -> V_48 ;
V_2 -> V_49 = V_11 -> V_49 ;
V_2 -> V_50 [ V_51 ] = 0 ;
V_2 -> V_50 [ V_52 ] = V_2 -> V_35 ;
V_2 -> V_50 [ V_53 ] = V_2 -> V_35 ;
V_2 -> V_50 [ V_54 ] = V_2 -> V_35 ;
V_2 -> V_50 [ V_55 ] = 0 ;
V_2 -> V_50 [ V_56 ] = 0 ;
V_2 -> V_50 [ V_57 ]
= 5 * V_2 -> V_38 ;
V_2 -> V_50 [ V_58 ] = 0 ;
V_2 -> V_50 [ V_59 ] = V_2 -> V_46 ;
V_2 -> V_50 [ V_60 ] =
F_9 (unsigned long, sp->autoclose, net->sctp.max_autoclose) * V_61 ;
for ( V_12 = V_51 ; V_12 < V_62 ; ++ V_12 )
F_10 ( & V_2 -> V_63 [ V_12 ] , V_64 [ V_12 ] ,
( unsigned long ) V_2 ) ;
V_2 -> V_65 . V_66 = V_11 -> V_67 . V_66 ;
V_2 -> V_65 . V_68 = V_11 -> V_67 . V_68 ;
V_2 -> V_69 = V_11 -> V_67 . V_70 ;
V_2 -> V_71 =
F_8 ( V_11 -> V_67 . V_72 ) ;
V_2 -> V_73 = NULL ;
if ( ( V_6 -> V_74 / 2 ) < V_75 )
V_2 -> V_76 = V_75 ;
else
V_2 -> V_76 = V_6 -> V_74 / 2 ;
V_2 -> V_77 = V_2 -> V_76 ;
V_2 -> V_78 = 0 ;
V_2 -> V_79 = 0 ;
V_2 -> V_80 . V_76 = V_81 ;
V_2 -> V_82 = 0 ;
F_6 ( & V_2 -> V_83 , 0 ) ;
F_11 ( & V_2 -> V_84 ) ;
V_2 -> V_65 . V_85 = F_12 ( V_4 ) ;
V_2 -> V_80 . V_12 . V_86 = 0 ;
V_2 -> V_65 . V_87 = 0 ;
V_2 -> V_65 . V_88 = 0 ;
V_2 -> V_65 . V_89 = 0 ;
V_2 -> V_65 . V_90 = V_4 -> V_15 . V_20 . V_21 ;
V_2 -> V_65 . V_91 = F_13 ( V_4 ) ;
V_2 -> V_92 = V_2 -> V_65 . V_91 ;
V_2 -> V_93 = V_2 -> V_92 - 1 ;
V_2 -> V_94 = V_2 -> V_93 ;
V_2 -> V_95 = V_2 -> V_93 ;
V_2 -> V_96 = V_2 -> V_93 ;
V_2 -> V_97 = 0 ;
V_2 -> V_98 = V_2 -> V_65 . V_91 ;
F_14 ( & V_2 -> V_99 ) ;
F_14 ( & V_2 -> V_100 ) ;
F_14 ( & V_2 -> V_80 . V_101 ) ;
V_2 -> V_80 . V_102 = 0 ;
V_2 -> V_80 . V_103 = 1 ;
V_2 -> V_80 . V_104 = 0 ;
V_2 -> V_80 . V_105 = 1 ;
V_2 -> V_80 . V_106 = 0 ;
if ( V_9 -> V_34 . V_107 )
V_2 -> V_80 . V_106 = 1 ;
V_2 -> V_108 = NULL ;
V_2 -> V_109 = 0 ;
V_2 -> V_110 = NULL ;
F_15 ( & V_2 -> V_15 . V_111 ) ;
F_16 ( & V_2 -> V_15 . V_111 , V_112 ) ;
F_17 ( V_2 , & V_2 -> V_113 ) ;
if ( ! F_18 ( & V_2 -> V_114 , V_2 ) )
goto V_115;
memset ( & V_2 -> V_80 . V_116 , 0 , sizeof( struct V_117 ) ) ;
V_2 -> V_118 = 0 ;
V_2 -> V_119 = 0 ;
V_2 -> V_80 . V_120 = 1 ;
if ( V_2 -> V_15 . V_6 -> V_121 == V_122 )
V_2 -> V_80 . V_123 = 1 ;
F_14 ( & V_2 -> V_124 ) ;
V_2 -> V_125 = V_11 -> V_125 ;
V_2 -> V_126 = V_11 -> V_126 ;
V_2 -> V_127 = V_11 -> V_127 ;
V_2 -> V_128 = V_11 -> V_128 ;
V_2 -> V_129 = V_11 -> V_129 ;
V_2 -> V_130 = V_11 -> V_130 ;
V_2 -> V_131 = V_11 -> V_131 ;
F_14 ( & V_2 -> V_132 ) ;
V_14 = F_19 ( V_4 , V_2 , V_8 ) ;
if ( V_14 )
goto V_115;
V_2 -> V_133 = V_4 -> V_133 ;
V_2 -> V_134 = NULL ;
V_2 -> V_135 = 0 ;
if ( V_4 -> V_136 )
memcpy ( V_2 -> V_65 . V_137 , V_4 -> V_136 ,
F_20 ( V_4 -> V_136 -> V_138 . V_139 ) ) ;
if ( V_4 -> V_140 )
memcpy ( V_2 -> V_65 . V_141 , V_4 -> V_140 ,
F_20 ( V_4 -> V_140 -> V_138 . V_139 ) ) ;
V_13 = ( T_3 * ) V_2 -> V_65 . V_142 ;
V_13 -> type = V_143 ;
V_13 -> V_139 = F_21 ( sizeof( T_3 ) + V_144 ) ;
F_22 ( V_13 + 1 , V_144 ) ;
return V_2 ;
V_115:
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
goto V_145;
if ( ! F_1 ( V_2 , V_4 , V_6 , V_7 , V_8 ) )
goto V_115;
V_2 -> V_15 . V_19 = 1 ;
F_27 ( V_146 ) ;
F_28 ( L_1 , V_2 ) ;
return V_2 ;
V_115:
F_29 ( V_2 ) ;
V_145:
return NULL ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_15 . V_6 ;
struct V_147 * V_148 ;
struct V_149 * V_150 , * V_151 ;
int V_12 ;
if ( ! V_2 -> V_151 ) {
F_31 ( & V_2 -> V_124 ) ;
if ( F_32 ( V_6 , V_152 ) && F_33 ( V_6 , V_153 ) )
V_6 -> V_154 -- ;
}
V_2 -> V_15 . V_18 = 1 ;
F_34 ( & V_2 -> V_113 ) ;
F_35 ( & V_2 -> V_114 ) ;
F_36 ( & V_2 -> V_15 . V_111 ) ;
F_37 ( & V_2 -> V_80 . V_116 ) ;
F_38 ( V_2 -> V_73 ) ;
F_39 ( & V_2 -> V_15 . V_20 ) ;
for ( V_12 = V_51 ; V_12 < V_62 ; ++ V_12 ) {
if ( F_40 ( & V_2 -> V_63 [ V_12 ] ) &&
F_41 ( & V_2 -> V_63 [ V_12 ] ) )
F_42 ( V_2 ) ;
}
F_29 ( V_2 -> V_80 . V_155 ) ;
F_29 ( V_2 -> V_80 . V_156 ) ;
F_29 ( V_2 -> V_80 . V_157 ) ;
F_29 ( V_2 -> V_80 . V_158 ) ;
F_43 (pos, temp, &asoc->peer.transport_addr_list) {
V_148 = F_44 ( V_150 , struct V_147 , V_159 ) ;
F_31 ( V_150 ) ;
F_45 ( V_148 ) ;
}
V_2 -> V_80 . V_102 = 0 ;
F_46 ( V_2 ) ;
if ( V_2 -> V_108 != NULL )
F_29 ( V_2 -> V_108 ) ;
F_47 ( & V_2 -> V_132 ) ;
F_48 ( V_2 -> V_134 ) ;
F_42 ( V_2 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_50 (asoc->base.dead, L_2 , return) ;
F_23 ( V_2 -> V_4 ) ;
F_24 ( V_2 -> V_15 . V_6 ) ;
if ( V_2 -> V_119 != 0 ) {
F_51 ( & V_160 ) ;
F_52 ( & V_161 , V_2 -> V_119 ) ;
F_53 ( & V_160 ) ;
}
F_54 ( F_55 ( & V_2 -> V_83 ) ) ;
if ( V_2 -> V_15 . V_19 ) {
F_29 ( V_2 ) ;
F_56 ( V_146 ) ;
}
}
void F_57 ( struct V_1 * V_2 ,
struct V_147 * V_148 )
{
int V_162 = 0 ;
if ( V_2 -> V_80 . V_163 != NULL &&
V_2 -> V_80 . V_163 != V_148 )
V_162 = 1 ;
V_2 -> V_80 . V_163 = V_148 ;
memcpy ( & V_2 -> V_80 . V_164 , & V_148 -> V_165 ,
sizeof( union V_166 ) ) ;
if ( ( V_148 -> V_22 == V_167 ) ||
( V_148 -> V_22 == V_168 ) )
V_2 -> V_80 . V_169 = V_148 ;
if ( ! V_2 -> V_113 . V_170 && ! V_2 -> V_113 . V_171 )
return;
if ( V_148 -> V_172 . V_173 )
V_148 -> V_172 . V_174 = V_162 ;
V_148 -> V_172 . V_173 = V_162 ;
V_148 -> V_172 . V_175 = V_2 -> V_92 ;
}
void F_58 ( struct V_1 * V_2 ,
struct V_147 * V_80 )
{
struct V_149 * V_150 ;
struct V_147 * V_148 ;
F_59 ( L_3 ,
L_4 ,
V_2 ,
( & V_80 -> V_165 ) ,
F_20 ( V_80 -> V_165 . V_176 . V_177 ) ) ;
if ( V_2 -> V_80 . V_178 == V_80 )
F_60 ( V_2 ) ;
F_31 ( & V_80 -> V_159 ) ;
V_150 = V_2 -> V_80 . V_101 . V_179 ;
V_148 = F_44 ( V_150 , struct V_147 , V_159 ) ;
if ( V_2 -> V_80 . V_163 == V_80 )
F_57 ( V_2 , V_148 ) ;
if ( V_2 -> V_80 . V_169 == V_80 )
V_2 -> V_80 . V_169 = V_148 ;
if ( V_2 -> V_80 . V_178 == V_80 )
V_2 -> V_80 . V_178 = V_148 ;
if ( V_2 -> V_80 . V_180 == V_80 )
V_2 -> V_80 . V_180 = V_148 ;
if ( V_2 -> V_181 == V_80 )
V_2 -> V_181 = NULL ;
if ( V_2 -> V_182 == V_80 )
V_2 -> V_182 = NULL ;
if ( V_2 -> V_183 &&
V_2 -> V_183 -> V_148 == V_80 )
V_2 -> V_183 -> V_148 = NULL ;
if ( ! F_61 ( & V_80 -> V_184 ) ) {
struct V_147 * V_185 = V_2 -> V_80 . V_169 ;
struct V_186 * V_187 ;
F_62 (ch, &peer->transmitted,
transmitted_list) {
V_187 -> V_148 = NULL ;
V_187 -> V_188 = 0 ;
}
F_63 ( & V_80 -> V_184 ,
& V_185 -> V_184 ) ;
if ( ! F_40 ( & V_185 -> V_189 ) )
if ( ! F_64 ( & V_185 -> V_189 ,
V_190 + V_185 -> V_191 ) )
F_65 ( V_185 ) ;
}
V_2 -> V_80 . V_102 -- ;
F_45 ( V_80 ) ;
}
struct V_147 * F_66 ( struct V_1 * V_2 ,
const union V_166 * V_192 ,
const T_2 V_8 ,
const int V_193 )
{
struct V_9 * V_9 = F_2 ( V_2 -> V_15 . V_6 ) ;
struct V_147 * V_80 ;
struct V_10 * V_11 ;
unsigned short V_21 ;
V_11 = F_3 ( V_2 -> V_15 . V_6 ) ;
V_21 = F_20 ( V_192 -> V_176 . V_177 ) ;
F_59 ( L_5 ,
L_6 ,
V_2 ,
V_192 ,
V_21 ,
V_193 ) ;
if ( 0 == V_2 -> V_80 . V_21 )
V_2 -> V_80 . V_21 = V_21 ;
V_80 = F_67 ( V_2 , V_192 ) ;
if ( V_80 ) {
if ( V_80 -> V_22 == V_168 ) {
V_80 -> V_22 = V_167 ;
}
return V_80 ;
}
V_80 = F_68 ( V_9 , V_192 , V_8 ) ;
if ( ! V_80 )
return NULL ;
F_69 ( V_80 , V_2 ) ;
V_80 -> V_43 = V_2 -> V_43 ;
V_80 -> V_44 = V_2 -> V_44 ;
V_80 -> V_33 = V_2 -> V_33 ;
V_80 -> V_46 = V_2 -> V_46 ;
V_80 -> V_47 = V_2 -> V_47 ;
V_80 -> V_48 = V_2 -> V_48 ;
F_70 ( V_80 , NULL , V_11 ) ;
if ( V_80 -> V_48 & V_194 ) {
if ( V_2 -> V_45 )
V_80 -> V_45 = V_2 -> V_45 ;
else
V_80 -> V_45 = V_195 ;
}
if ( V_2 -> V_45 )
V_2 -> V_45 = F_9 ( int , V_80 -> V_45 , V_2 -> V_45 ) ;
else
V_2 -> V_45 = V_80 -> V_45 ;
F_28 ( L_7
L_8 , V_2 , V_2 -> V_45 ) ;
V_80 -> V_196 = 0 ;
V_2 -> V_29 = F_71 ( V_2 , V_2 -> V_45 ) ;
F_72 ( & V_80 -> V_197 , V_80 , V_2 -> V_15 . V_20 . V_21 ,
V_2 -> V_80 . V_21 ) ;
V_80 -> V_198 = F_73 ( 4 * V_2 -> V_45 , F_74 ( V_199 , 2 * V_2 -> V_45 , 4380 ) ) ;
V_80 -> V_200 = V_81 ;
V_80 -> V_201 = 0 ;
V_80 -> V_202 = 0 ;
V_80 -> V_203 = 0 ;
V_80 -> V_191 = V_2 -> V_35 ;
V_80 -> V_22 = V_193 ;
F_75 ( & V_80 -> V_159 , & V_2 -> V_80 . V_101 ) ;
V_2 -> V_80 . V_102 ++ ;
if ( ! V_2 -> V_80 . V_163 ) {
F_57 ( V_2 , V_80 ) ;
V_2 -> V_80 . V_178 = V_80 ;
}
if ( V_2 -> V_80 . V_169 == V_2 -> V_80 . V_178 &&
V_80 -> V_22 != V_204 ) {
V_2 -> V_80 . V_178 = V_80 ;
}
return V_80 ;
}
void F_76 ( struct V_1 * V_2 ,
const union V_166 * V_192 )
{
struct V_149 * V_150 ;
struct V_149 * V_151 ;
struct V_147 * V_148 ;
F_43 (pos, temp, &asoc->peer.transport_addr_list) {
V_148 = F_44 ( V_150 , struct V_147 , V_159 ) ;
if ( F_77 ( V_192 , & V_148 -> V_165 ) ) {
F_58 ( V_2 , V_148 ) ;
break;
}
}
}
struct V_147 * F_67 (
const struct V_1 * V_2 ,
const union V_166 * V_205 )
{
struct V_147 * V_206 ;
F_62 (t, &asoc->peer.transport_addr_list,
transports) {
if ( F_77 ( V_205 , & V_206 -> V_165 ) )
return V_206 ;
}
return NULL ;
}
void F_78 ( struct V_1 * V_2 ,
struct V_147 * V_207 )
{
struct V_147 * V_151 ;
struct V_147 * V_206 ;
F_79 (t, temp, &asoc->peer.transport_addr_list,
transports) {
if ( V_206 != V_207 )
F_58 ( V_2 , V_206 ) ;
}
}
void F_80 ( struct V_1 * V_2 ,
struct V_147 * V_148 ,
T_4 V_208 ,
T_5 error )
{
struct V_147 * V_206 = NULL ;
struct V_147 * V_209 ;
struct V_147 * V_210 ;
struct V_211 * V_212 ;
struct V_213 V_192 ;
int V_214 = 0 ;
bool V_215 = true ;
switch ( V_208 ) {
case V_216 :
if ( V_204 == V_148 -> V_22 &&
V_217 == error )
V_214 = V_218 ;
else
V_214 = V_219 ;
if ( V_148 -> V_22 == V_220 ) {
V_215 = false ;
V_148 -> V_198 = 1 ;
}
V_148 -> V_22 = V_167 ;
break;
case V_221 :
if ( V_148 -> V_22 != V_204 )
V_148 -> V_22 = V_222 ;
else {
F_81 ( V_148 -> V_223 ) ;
V_148 -> V_223 = NULL ;
}
V_214 = V_224 ;
break;
case V_225 :
V_148 -> V_22 = V_220 ;
V_215 = false ;
break;
default:
return;
}
if ( V_215 ) {
memset ( & V_192 , 0 , sizeof( struct V_213 ) ) ;
memcpy ( & V_192 , & V_148 -> V_165 ,
V_148 -> V_226 -> V_227 ) ;
V_212 = F_82 ( V_2 , & V_192 ,
0 , V_214 , error , V_228 ) ;
if ( V_212 )
F_83 ( & V_2 -> V_114 , V_212 ) ;
}
V_209 = NULL ; V_210 = NULL ;
F_62 (t, &asoc->peer.transport_addr_list,
transports) {
if ( ( V_206 -> V_22 == V_222 ) ||
( V_206 -> V_22 == V_204 ) ||
( V_206 -> V_22 == V_220 ) )
continue;
if ( ! V_209 || V_206 -> V_229 > V_209 -> V_229 ) {
V_210 = V_209 ;
V_209 = V_206 ;
}
if ( ! V_210 || V_206 -> V_229 > V_210 -> V_229 )
V_210 = V_206 ;
}
if ( ( ( V_2 -> V_80 . V_163 -> V_22 == V_167 ) ||
( V_2 -> V_80 . V_163 -> V_22 == V_168 ) ) &&
V_209 != V_2 -> V_80 . V_163 ) {
V_210 = V_209 ;
V_209 = V_2 -> V_80 . V_163 ;
}
if ( ! V_209 ) {
V_209 = V_2 -> V_80 . V_163 ;
V_210 = V_2 -> V_80 . V_163 ;
}
V_2 -> V_80 . V_169 = V_209 ;
V_2 -> V_80 . V_178 = V_210 ;
}
void F_84 ( struct V_1 * V_2 )
{
F_85 ( & V_2 -> V_15 . V_17 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
if ( F_86 ( & V_2 -> V_15 . V_17 ) )
F_49 ( V_2 ) ;
}
V_199 F_87 ( struct V_1 * V_2 )
{
V_199 V_230 = V_2 -> V_92 ;
V_2 -> V_92 ++ ;
V_2 -> V_97 ++ ;
return V_230 ;
}
int F_77 ( const union V_166 * V_231 ,
const union V_166 * V_232 )
{
struct V_233 * V_234 ;
V_234 = F_88 ( V_231 -> V_235 . V_236 ) ;
if ( F_89 ( ! V_234 ) )
return 0 ;
return V_234 -> V_237 ( V_231 , V_232 ) ;
}
struct V_186 * F_90 ( struct V_1 * V_2 )
{
struct V_186 * V_238 ;
if ( V_2 -> V_118 )
V_238 = F_91 ( V_2 , V_2 -> V_239 ) ;
else
V_238 = NULL ;
return V_238 ;
}
struct V_147 * F_92 ( struct V_1 * V_2 ,
V_199 V_240 )
{
struct V_147 * V_185 ;
struct V_147 * V_241 ;
struct V_147 * V_148 ;
struct V_186 * V_238 ;
T_6 V_242 = F_93 ( V_240 ) ;
V_241 = NULL ;
V_185 = V_2 -> V_80 . V_169 ;
F_62 (chunk, &active->transmitted,
transmitted_list) {
if ( V_242 == V_238 -> V_243 . V_244 -> V_240 ) {
V_241 = V_185 ;
goto V_245;
}
}
F_62 (transport, &asoc->peer.transport_addr_list,
transports) {
if ( V_148 == V_185 )
break;
F_62 (chunk, &transport->transmitted,
transmitted_list) {
if ( V_242 == V_238 -> V_243 . V_244 -> V_240 ) {
V_241 = V_148 ;
goto V_245;
}
}
}
V_245:
return V_241 ;
}
struct V_147 * F_94 ( struct V_1 * V_2 ,
struct V_9 * V_9 ,
const union V_166 * V_246 ,
const union V_166 * V_247 )
{
struct V_147 * V_148 ;
if ( ( F_21 ( V_2 -> V_15 . V_20 . V_21 ) == V_246 -> V_176 . V_177 ) &&
( F_21 ( V_2 -> V_80 . V_21 ) == V_247 -> V_176 . V_177 ) &&
F_95 ( F_2 ( V_2 -> V_15 . V_6 ) , V_9 ) ) {
V_148 = F_67 ( V_2 , V_247 ) ;
if ( ! V_148 )
goto V_245;
if ( F_96 ( & V_2 -> V_15 . V_20 , V_246 ,
F_3 ( V_2 -> V_15 . V_6 ) ) )
goto V_245;
}
V_148 = NULL ;
V_245:
return V_148 ;
}
static void V_112 ( struct V_248 * V_249 )
{
struct V_1 * V_2 =
F_97 ( V_249 , struct V_1 ,
V_15 . V_111 . V_250 ) ;
struct V_9 * V_9 = F_2 ( V_2 -> V_15 . V_6 ) ;
struct V_3 * V_4 ;
struct V_186 * V_238 ;
struct V_251 * V_111 ;
int V_22 ;
T_7 V_252 ;
int error = 0 ;
V_4 = V_2 -> V_4 ;
V_111 = & V_2 -> V_15 . V_111 ;
F_84 ( V_2 ) ;
while ( NULL != ( V_238 = F_98 ( V_111 ) ) ) {
V_22 = V_2 -> V_22 ;
V_252 = F_99 ( V_238 -> V_253 -> type ) ;
if ( F_100 ( V_252 . V_238 , V_2 ) && ! V_238 -> V_254 )
continue;
if ( F_101 ( V_238 ) )
V_2 -> V_80 . V_180 = V_238 -> V_148 ;
else
F_102 ( V_9 , V_255 ) ;
if ( V_238 -> V_148 )
V_238 -> V_148 -> V_229 = V_190 ;
error = F_103 ( V_9 , V_256 , V_252 ,
V_22 , V_4 , V_2 , V_238 , V_228 ) ;
if ( V_2 -> V_15 . V_18 )
break;
if ( error && V_238 )
V_238 -> V_257 = 1 ;
}
F_42 ( V_2 ) ;
}
void F_104 ( struct V_1 * V_146 , struct V_5 * V_258 )
{
struct V_10 * V_259 = F_3 ( V_258 ) ;
struct V_5 * V_260 = V_146 -> V_15 . V_6 ;
F_105 ( & V_146 -> V_124 ) ;
if ( F_32 ( V_260 , V_152 ) )
V_260 -> V_154 -- ;
F_23 ( V_146 -> V_4 ) ;
F_24 ( V_146 -> V_15 . V_6 ) ;
V_146 -> V_4 = V_259 -> V_4 ;
F_4 ( V_146 -> V_4 ) ;
V_146 -> V_15 . V_6 = V_258 ;
F_5 ( V_146 -> V_15 . V_6 ) ;
F_106 ( V_259 -> V_4 , V_146 ) ;
}
void F_107 ( struct V_1 * V_2 ,
struct V_1 * V_261 )
{
struct V_147 * V_262 ;
struct V_149 * V_150 , * V_151 ;
V_2 -> V_65 = V_261 -> V_65 ;
V_2 -> V_80 . V_76 = V_261 -> V_80 . V_76 ;
V_2 -> V_80 . V_103 = V_261 -> V_80 . V_103 ;
V_2 -> V_80 . V_12 = V_261 -> V_80 . V_12 ;
F_108 ( & V_2 -> V_80 . V_116 , V_263 ,
V_2 -> V_80 . V_12 . V_91 , V_228 ) ;
F_43 (pos, temp, &asoc->peer.transport_addr_list) {
V_262 = F_44 ( V_150 , struct V_147 , V_159 ) ;
if ( ! F_67 ( V_261 , & V_262 -> V_165 ) ) {
F_58 ( V_2 , V_262 ) ;
continue;
}
if ( V_2 -> V_22 >= V_264 )
F_109 ( V_262 ) ;
}
if ( V_2 -> V_22 >= V_264 ) {
V_2 -> V_92 = V_261 -> V_92 ;
V_2 -> V_93 = V_261 -> V_93 ;
V_2 -> V_94 = V_261 -> V_94 ;
F_110 ( V_2 -> V_73 ) ;
F_111 ( & V_2 -> V_114 ) ;
V_2 -> V_42 = 0 ;
} else {
F_62 (trans, &new->peer.transport_addr_list,
transports) {
if ( ! F_67 ( V_2 , & V_262 -> V_165 ) )
F_66 ( V_2 , & V_262 -> V_165 ,
V_228 , V_262 -> V_22 ) ;
}
V_2 -> V_93 = V_2 -> V_92 - 1 ;
V_2 -> V_94 = V_2 -> V_93 ;
if ( ! V_2 -> V_73 ) {
V_2 -> V_73 = V_261 -> V_73 ;
V_261 -> V_73 = NULL ;
}
if ( ! V_2 -> V_119 ) {
F_112 ( V_2 , V_228 ) ;
}
}
F_29 ( V_2 -> V_80 . V_156 ) ;
V_2 -> V_80 . V_156 = V_261 -> V_80 . V_156 ;
V_261 -> V_80 . V_156 = NULL ;
F_29 ( V_2 -> V_80 . V_157 ) ;
V_2 -> V_80 . V_157 = V_261 -> V_80 . V_157 ;
V_261 -> V_80 . V_157 = NULL ;
F_29 ( V_2 -> V_80 . V_158 ) ;
V_2 -> V_80 . V_158 = V_261 -> V_80 . V_158 ;
V_261 -> V_80 . V_158 = NULL ;
F_48 ( V_2 -> V_134 ) ;
F_113 ( V_2 , V_228 ) ;
}
void F_60 ( struct V_1 * V_2 )
{
struct V_147 * V_206 , * V_179 ;
struct V_149 * V_265 = & V_2 -> V_80 . V_101 ;
struct V_149 * V_150 ;
if ( V_2 -> V_80 . V_102 == 1 )
return;
V_206 = V_2 -> V_80 . V_178 ;
V_150 = & V_206 -> V_159 ;
V_179 = NULL ;
while ( 1 ) {
if ( V_150 -> V_179 == V_265 )
V_150 = V_265 -> V_179 ;
else
V_150 = V_150 -> V_179 ;
V_206 = F_44 ( V_150 , struct V_147 , V_159 ) ;
if ( V_206 == V_2 -> V_80 . V_178 ) {
V_206 = V_179 ;
break;
}
if ( ( V_206 -> V_22 == V_167 ) ||
( V_206 -> V_22 == V_168 ) ) {
break;
} else {
if ( V_206 -> V_22 != V_204 && ! V_179 )
V_179 = V_206 ;
}
}
if ( V_206 )
V_2 -> V_80 . V_178 = V_206 ;
else
V_206 = V_2 -> V_80 . V_178 ;
F_59 ( L_9
L_10 ,
L_4 ,
V_2 ,
( & V_206 -> V_165 ) ,
F_20 ( V_206 -> V_165 . V_176 . V_177 ) ) ;
}
struct V_147 * F_114 (
struct V_1 * V_2 , struct V_147 * V_266 )
{
if ( ! V_266 )
return V_2 -> V_80 . V_169 ;
else {
if ( V_266 == V_2 -> V_80 . V_178 )
F_60 ( V_2 ) ;
return V_2 -> V_80 . V_178 ;
}
}
void F_115 ( struct V_5 * V_6 , struct V_1 * V_2 )
{
struct V_147 * V_206 ;
V_199 V_267 = 0 ;
if ( ! V_2 )
return;
F_62 (t, &asoc->peer.transport_addr_list,
transports) {
if ( V_206 -> V_196 && V_206 -> V_223 ) {
F_116 ( V_6 , V_206 , F_117 ( V_206 -> V_223 ) ) ;
V_206 -> V_196 = 0 ;
}
if ( ! V_267 || ( V_206 -> V_45 < V_267 ) )
V_267 = V_206 -> V_45 ;
}
if ( V_267 ) {
V_2 -> V_45 = V_267 ;
V_2 -> V_29 = F_71 ( V_2 , V_267 ) ;
}
F_28 ( L_11 ,
V_268 , V_2 , V_2 -> V_45 , V_2 -> V_29 ) ;
}
static inline int F_118 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_2 ( V_2 -> V_15 . V_6 ) ;
switch ( V_2 -> V_22 ) {
case V_264 :
case V_269 :
case V_270 :
case V_271 :
if ( ( V_2 -> V_76 > V_2 -> V_77 ) &&
( ( V_2 -> V_76 - V_2 -> V_77 ) >= F_74 ( V_199 ,
( V_2 -> V_15 . V_6 -> V_74 >> V_9 -> V_34 . V_272 ) ,
V_2 -> V_45 ) ) )
return 1 ;
break;
default:
break;
}
return 0 ;
}
void F_119 ( struct V_1 * V_2 , unsigned int V_273 )
{
struct V_186 * V_274 ;
struct V_275 * V_276 ;
if ( V_2 -> V_78 ) {
if ( V_2 -> V_78 >= V_273 ) {
V_2 -> V_78 -= V_273 ;
} else {
V_2 -> V_76 += ( V_273 - V_2 -> V_78 ) ;
V_2 -> V_78 = 0 ;
}
} else {
V_2 -> V_76 += V_273 ;
}
if ( V_2 -> V_79 && V_2 -> V_76 >= V_2 -> V_79 ) {
int V_277 = F_73 ( V_2 -> V_45 , V_2 -> V_79 ) ;
V_2 -> V_76 += V_277 ;
V_2 -> V_79 -= V_277 ;
}
F_28 ( L_12
L_13 , V_268 , V_2 , V_273 , V_2 -> V_76 ,
V_2 -> V_78 , V_2 -> V_77 ) ;
if ( F_118 ( V_2 ) ) {
V_2 -> V_77 = V_2 -> V_76 ;
F_28 ( L_14
L_15 , V_268 ,
V_2 , V_2 -> V_76 , V_2 -> V_77 ) ;
V_274 = F_120 ( V_2 ) ;
if ( ! V_274 )
return;
V_2 -> V_80 . V_103 = 0 ;
F_121 ( & V_2 -> V_113 , V_274 ) ;
V_276 = & V_2 -> V_63 [ V_59 ] ;
if ( F_40 ( V_276 ) && F_41 ( V_276 ) )
F_42 ( V_2 ) ;
}
}
void F_122 ( struct V_1 * V_2 , unsigned int V_273 )
{
int V_278 ;
int V_279 = 0 ;
F_50 (asoc->rwnd, L_16 , return) ;
F_50 (!asoc->rwnd_over, L_17 , return) ;
if ( V_2 -> V_4 -> V_280 )
V_278 = F_55 ( & V_2 -> V_83 ) ;
else
V_278 = F_55 ( & V_2 -> V_15 . V_6 -> V_281 ) ;
if ( V_278 >= V_2 -> V_15 . V_6 -> V_74 )
V_279 = 1 ;
if ( V_2 -> V_76 >= V_273 ) {
V_2 -> V_76 -= V_273 ;
if ( V_279 ) {
V_2 -> V_79 += V_2 -> V_76 ;
V_2 -> V_76 = 0 ;
}
} else {
V_2 -> V_78 = V_273 - V_2 -> V_76 ;
V_2 -> V_76 = 0 ;
}
F_28 ( L_18 ,
V_268 , V_2 , V_273 , V_2 -> V_76 ,
V_2 -> V_78 , V_2 -> V_79 ) ;
}
int F_123 ( struct V_1 * V_2 ,
T_1 V_7 , T_2 V_8 )
{
int V_282 ;
V_282 = ( V_122 == V_2 -> V_15 . V_6 -> V_121 ) ? V_283 : 0 ;
if ( V_2 -> V_80 . V_120 )
V_282 |= V_284 ;
if ( V_2 -> V_80 . V_123 )
V_282 |= V_285 ;
return F_124 ( F_2 ( V_2 -> V_15 . V_6 ) ,
& V_2 -> V_15 . V_20 ,
& V_2 -> V_4 -> V_15 . V_20 ,
V_7 , V_8 , V_282 ) ;
}
int F_125 ( struct V_1 * V_2 ,
struct V_286 * V_155 ,
T_2 V_8 )
{
int V_287 = F_20 ( V_155 -> V_288 -> V_253 . V_139 ) ;
int V_289 = V_155 -> V_290 ;
T_8 * V_291 = ( T_8 * ) V_155 -> V_288 + V_287 ;
return F_126 ( & V_2 -> V_15 . V_20 , V_291 , V_289 ,
V_2 -> V_4 -> V_15 . V_20 . V_21 , V_8 ) ;
}
int F_127 ( struct V_1 * V_2 ,
const union V_166 * V_246 )
{
int V_292 = 0 ;
if ( ( V_2 -> V_15 . V_20 . V_21 == F_20 ( V_246 -> V_176 . V_177 ) ) &&
F_96 ( & V_2 -> V_15 . V_20 , V_246 ,
F_3 ( V_2 -> V_15 . V_6 ) ) )
V_292 = 1 ;
return V_292 ;
}
int F_112 ( struct V_1 * V_2 , T_2 V_8 )
{
int V_119 ;
int error = 0 ;
if ( V_2 -> V_119 )
return error ;
V_293:
if ( F_89 ( ! F_128 ( & V_161 , V_8 ) ) )
return - V_294 ;
F_51 ( & V_160 ) ;
error = F_129 ( & V_161 , ( void * ) V_2 ,
V_295 , & V_119 ) ;
if ( ! error ) {
V_295 = V_119 + 1 ;
if ( V_295 == V_296 )
V_295 = 1 ;
}
F_53 ( & V_160 ) ;
if ( error == - V_297 )
goto V_293;
else if ( error )
return error ;
V_2 -> V_119 = ( V_298 ) V_119 ;
return error ;
}
static void F_130 ( struct V_1 * V_2 )
{
struct V_186 * V_299 ;
struct V_186 * V_300 ;
F_79 (asconf, tmp, &asoc->addip_chunk_list, list) {
F_105 ( & V_299 -> V_301 ) ;
F_131 ( V_299 ) ;
}
}
static void F_132 ( struct V_1 * V_2 )
{
struct V_186 * V_302 ;
struct V_186 * V_300 ;
F_79 (ack, tmp, &asoc->asconf_ack_list,
transmitted_list) {
F_105 ( & V_302 -> V_303 ) ;
F_131 ( V_302 ) ;
}
}
void F_133 ( const struct V_1 * V_2 )
{
struct V_186 * V_302 ;
struct V_186 * V_300 ;
F_79 (ack, tmp, &asoc->asconf_ack_list,
transmitted_list) {
if ( V_302 -> V_243 . V_304 -> V_305 ==
F_93 ( V_2 -> V_80 . V_98 ) )
break;
F_105 ( & V_302 -> V_303 ) ;
F_131 ( V_302 ) ;
}
}
struct V_186 * F_134 (
const struct V_1 * V_2 ,
T_6 V_305 )
{
struct V_186 * V_302 ;
F_62 (ack, &asoc->asconf_ack_list, transmitted_list) {
if ( V_302 -> V_243 . V_304 -> V_305 == V_305 ) {
F_135 ( V_302 ) ;
return V_302 ;
}
}
return NULL ;
}
void F_46 ( struct V_1 * V_2 )
{
F_132 ( V_2 ) ;
F_130 ( V_2 ) ;
if ( V_2 -> V_183 )
F_131 ( V_2 -> V_183 ) ;
}
