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
memset ( & V_2 -> V_132 , 0 , sizeof( struct V_133 ) ) ;
F_14 ( & V_2 -> V_134 ) ;
V_14 = F_19 ( V_4 , V_2 , V_8 ) ;
if ( V_14 )
goto V_115;
V_2 -> V_135 = V_4 -> V_135 ;
V_2 -> V_136 = NULL ;
V_2 -> V_137 = 0 ;
if ( V_4 -> V_138 )
memcpy ( V_2 -> V_65 . V_139 , V_4 -> V_138 ,
F_20 ( V_4 -> V_138 -> V_140 . V_141 ) ) ;
if ( V_4 -> V_142 )
memcpy ( V_2 -> V_65 . V_143 , V_4 -> V_142 ,
F_20 ( V_4 -> V_142 -> V_140 . V_141 ) ) ;
V_13 = ( T_3 * ) V_2 -> V_65 . V_144 ;
V_13 -> type = V_145 ;
V_13 -> V_141 = F_21 ( sizeof( T_3 ) + V_146 ) ;
F_22 ( V_13 + 1 , V_146 ) ;
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
goto V_147;
if ( ! F_1 ( V_2 , V_4 , V_6 , V_7 , V_8 ) )
goto V_115;
V_2 -> V_15 . V_19 = 1 ;
F_27 ( V_148 ) ;
F_28 ( L_1 , V_2 ) ;
return V_2 ;
V_115:
F_29 ( V_2 ) ;
V_147:
return NULL ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_15 . V_6 ;
struct V_149 * V_150 ;
struct V_151 * V_152 , * V_153 ;
int V_12 ;
if ( ! V_2 -> V_153 ) {
F_31 ( & V_2 -> V_124 ) ;
if ( F_32 ( V_6 , V_154 ) && F_33 ( V_6 , V_155 ) )
V_6 -> V_156 -- ;
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
F_29 ( V_2 -> V_80 . V_157 ) ;
F_29 ( V_2 -> V_80 . V_158 ) ;
F_29 ( V_2 -> V_80 . V_159 ) ;
F_29 ( V_2 -> V_80 . V_160 ) ;
F_43 (pos, temp, &asoc->peer.transport_addr_list) {
V_150 = F_44 ( V_152 , struct V_149 , V_161 ) ;
F_45 ( V_152 ) ;
F_46 ( V_150 ) ;
}
V_2 -> V_80 . V_102 = 0 ;
F_47 ( V_2 ) ;
if ( V_2 -> V_108 != NULL )
F_29 ( V_2 -> V_108 ) ;
F_48 ( & V_2 -> V_134 ) ;
F_49 ( V_2 -> V_136 ) ;
F_42 ( V_2 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_51 (asoc->base.dead, L_2 , return) ;
F_23 ( V_2 -> V_4 ) ;
F_24 ( V_2 -> V_15 . V_6 ) ;
if ( V_2 -> V_119 != 0 ) {
F_52 ( & V_162 ) ;
F_53 ( & V_163 , V_2 -> V_119 ) ;
F_54 ( & V_162 ) ;
}
F_55 ( F_56 ( & V_2 -> V_83 ) ) ;
if ( V_2 -> V_15 . V_19 ) {
F_29 ( V_2 ) ;
F_57 ( V_148 ) ;
}
}
void F_58 ( struct V_1 * V_2 ,
struct V_149 * V_150 )
{
int V_164 = 0 ;
if ( V_2 -> V_80 . V_165 != NULL &&
V_2 -> V_80 . V_165 != V_150 )
V_164 = 1 ;
V_2 -> V_80 . V_165 = V_150 ;
memcpy ( & V_2 -> V_80 . V_166 , & V_150 -> V_167 ,
sizeof( union V_168 ) ) ;
if ( ( V_150 -> V_22 == V_169 ) ||
( V_150 -> V_22 == V_170 ) )
V_2 -> V_80 . V_171 = V_150 ;
if ( ! V_2 -> V_113 . V_172 && ! V_2 -> V_113 . V_173 )
return;
if ( V_150 -> V_174 . V_175 )
V_150 -> V_174 . V_176 = V_164 ;
V_150 -> V_174 . V_175 = V_164 ;
V_150 -> V_174 . V_177 = V_2 -> V_92 ;
}
void F_59 ( struct V_1 * V_2 ,
struct V_149 * V_80 )
{
struct V_151 * V_152 ;
struct V_149 * V_150 ;
F_60 ( L_3 ,
L_4 ,
V_2 ,
( & V_80 -> V_167 ) ,
F_20 ( V_80 -> V_167 . V_178 . V_179 ) ) ;
if ( V_2 -> V_80 . V_180 == V_80 )
F_61 ( V_2 ) ;
F_45 ( & V_80 -> V_161 ) ;
V_152 = V_2 -> V_80 . V_101 . V_181 ;
V_150 = F_44 ( V_152 , struct V_149 , V_161 ) ;
if ( V_2 -> V_80 . V_165 == V_80 )
F_58 ( V_2 , V_150 ) ;
if ( V_2 -> V_80 . V_171 == V_80 )
V_2 -> V_80 . V_171 = V_150 ;
if ( V_2 -> V_80 . V_180 == V_80 )
V_2 -> V_80 . V_180 = V_150 ;
if ( V_2 -> V_80 . V_182 == V_80 )
V_2 -> V_80 . V_182 = V_150 ;
if ( V_2 -> V_183 == V_80 )
V_2 -> V_183 = NULL ;
if ( V_2 -> V_184 == V_80 )
V_2 -> V_184 = NULL ;
if ( V_2 -> V_185 &&
V_2 -> V_185 -> V_150 == V_80 )
V_2 -> V_185 -> V_150 = NULL ;
if ( ! F_62 ( & V_80 -> V_186 ) ) {
struct V_149 * V_187 = V_2 -> V_80 . V_171 ;
struct V_188 * V_189 ;
F_63 (ch, &peer->transmitted,
transmitted_list) {
V_189 -> V_150 = NULL ;
V_189 -> V_190 = 0 ;
}
F_64 ( & V_80 -> V_186 ,
& V_187 -> V_186 ) ;
if ( ! F_40 ( & V_187 -> V_191 ) )
if ( ! F_65 ( & V_187 -> V_191 ,
V_192 + V_187 -> V_193 ) )
F_66 ( V_187 ) ;
}
V_2 -> V_80 . V_102 -- ;
F_46 ( V_80 ) ;
}
struct V_149 * F_67 ( struct V_1 * V_2 ,
const union V_168 * V_194 ,
const T_2 V_8 ,
const int V_195 )
{
struct V_9 * V_9 = F_2 ( V_2 -> V_15 . V_6 ) ;
struct V_149 * V_80 ;
struct V_10 * V_11 ;
unsigned short V_21 ;
V_11 = F_3 ( V_2 -> V_15 . V_6 ) ;
V_21 = F_20 ( V_194 -> V_178 . V_179 ) ;
F_60 ( L_5 ,
L_6 ,
V_2 ,
V_194 ,
V_21 ,
V_195 ) ;
if ( 0 == V_2 -> V_80 . V_21 )
V_2 -> V_80 . V_21 = V_21 ;
V_80 = F_68 ( V_2 , V_194 ) ;
if ( V_80 ) {
if ( V_80 -> V_22 == V_170 ) {
V_80 -> V_22 = V_169 ;
}
return V_80 ;
}
V_80 = F_69 ( V_9 , V_194 , V_8 ) ;
if ( ! V_80 )
return NULL ;
F_70 ( V_80 , V_2 ) ;
V_80 -> V_43 = V_2 -> V_43 ;
V_80 -> V_44 = V_2 -> V_44 ;
V_80 -> V_33 = V_2 -> V_33 ;
V_80 -> V_46 = V_2 -> V_46 ;
V_80 -> V_47 = V_2 -> V_47 ;
V_80 -> V_48 = V_2 -> V_48 ;
F_71 ( V_80 , NULL , V_11 ) ;
if ( V_80 -> V_48 & V_196 ) {
if ( V_2 -> V_45 )
V_80 -> V_45 = V_2 -> V_45 ;
else
V_80 -> V_45 = V_197 ;
}
if ( V_2 -> V_45 )
V_2 -> V_45 = F_9 ( int , V_80 -> V_45 , V_2 -> V_45 ) ;
else
V_2 -> V_45 = V_80 -> V_45 ;
F_28 ( L_7
L_8 , V_2 , V_2 -> V_45 ) ;
V_80 -> V_198 = 0 ;
V_2 -> V_29 = F_72 ( V_2 , V_2 -> V_45 ) ;
F_73 ( & V_80 -> V_199 , V_80 , V_2 -> V_15 . V_20 . V_21 ,
V_2 -> V_80 . V_21 ) ;
V_80 -> V_200 = F_74 ( 4 * V_2 -> V_45 , F_75 ( V_201 , 2 * V_2 -> V_45 , 4380 ) ) ;
V_80 -> V_202 = V_81 ;
V_80 -> V_203 = 0 ;
V_80 -> V_204 = 0 ;
V_80 -> V_205 = 0 ;
V_80 -> V_193 = V_2 -> V_35 ;
F_76 ( V_2 , V_80 ) ;
V_80 -> V_22 = V_195 ;
F_77 ( & V_80 -> V_161 , & V_2 -> V_80 . V_101 ) ;
V_2 -> V_80 . V_102 ++ ;
if ( ! V_2 -> V_80 . V_165 ) {
F_58 ( V_2 , V_80 ) ;
V_2 -> V_80 . V_180 = V_80 ;
}
if ( V_2 -> V_80 . V_171 == V_2 -> V_80 . V_180 &&
V_80 -> V_22 != V_206 ) {
V_2 -> V_80 . V_180 = V_80 ;
}
return V_80 ;
}
void F_78 ( struct V_1 * V_2 ,
const union V_168 * V_194 )
{
struct V_151 * V_152 ;
struct V_151 * V_153 ;
struct V_149 * V_150 ;
F_43 (pos, temp, &asoc->peer.transport_addr_list) {
V_150 = F_44 ( V_152 , struct V_149 , V_161 ) ;
if ( F_79 ( V_194 , & V_150 -> V_167 ) ) {
F_59 ( V_2 , V_150 ) ;
break;
}
}
}
struct V_149 * F_68 (
const struct V_1 * V_2 ,
const union V_168 * V_207 )
{
struct V_149 * V_208 ;
F_63 (t, &asoc->peer.transport_addr_list,
transports) {
if ( F_79 ( V_207 , & V_208 -> V_167 ) )
return V_208 ;
}
return NULL ;
}
void F_80 ( struct V_1 * V_2 ,
struct V_149 * V_209 )
{
struct V_149 * V_153 ;
struct V_149 * V_208 ;
F_81 (t, temp, &asoc->peer.transport_addr_list,
transports) {
if ( V_208 != V_209 )
F_59 ( V_2 , V_208 ) ;
}
}
void F_82 ( struct V_1 * V_2 ,
struct V_149 * V_150 ,
T_4 V_210 ,
T_5 error )
{
struct V_149 * V_208 = NULL ;
struct V_149 * V_211 ;
struct V_149 * V_212 ;
struct V_213 * V_214 ;
struct V_215 V_194 ;
int V_216 = 0 ;
bool V_217 = true ;
switch ( V_210 ) {
case V_218 :
if ( V_206 == V_150 -> V_22 &&
V_219 == error )
V_216 = V_220 ;
else
V_216 = V_221 ;
if ( V_150 -> V_22 == V_222 ) {
V_217 = false ;
V_150 -> V_200 = 1 ;
}
V_150 -> V_22 = V_169 ;
break;
case V_223 :
if ( V_150 -> V_22 != V_206 )
V_150 -> V_22 = V_224 ;
else {
F_83 ( V_150 -> V_225 ) ;
V_150 -> V_225 = NULL ;
}
V_216 = V_226 ;
break;
case V_227 :
V_150 -> V_22 = V_222 ;
V_217 = false ;
break;
default:
return;
}
if ( V_217 ) {
memset ( & V_194 , 0 , sizeof( struct V_215 ) ) ;
memcpy ( & V_194 , & V_150 -> V_167 ,
V_150 -> V_228 -> V_229 ) ;
V_214 = F_84 ( V_2 , & V_194 ,
0 , V_216 , error , V_230 ) ;
if ( V_214 )
F_85 ( & V_2 -> V_114 , V_214 ) ;
}
V_211 = NULL ; V_212 = NULL ;
F_63 (t, &asoc->peer.transport_addr_list,
transports) {
if ( ( V_208 -> V_22 == V_224 ) ||
( V_208 -> V_22 == V_206 ) ||
( V_208 -> V_22 == V_222 ) )
continue;
if ( ! V_211 || V_208 -> V_231 > V_211 -> V_231 ) {
V_212 = V_211 ;
V_211 = V_208 ;
}
if ( ! V_212 || V_208 -> V_231 > V_212 -> V_231 )
V_212 = V_208 ;
}
if ( ( ( V_2 -> V_80 . V_165 -> V_22 == V_169 ) ||
( V_2 -> V_80 . V_165 -> V_22 == V_170 ) ) &&
V_211 != V_2 -> V_80 . V_165 ) {
V_212 = V_211 ;
V_211 = V_2 -> V_80 . V_165 ;
}
if ( ! V_211 ) {
V_211 = V_2 -> V_80 . V_165 ;
V_212 = V_2 -> V_80 . V_165 ;
}
V_2 -> V_80 . V_171 = V_211 ;
V_2 -> V_80 . V_180 = V_212 ;
}
void F_86 ( struct V_1 * V_2 )
{
F_87 ( & V_2 -> V_15 . V_17 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
if ( F_88 ( & V_2 -> V_15 . V_17 ) )
F_50 ( V_2 ) ;
}
V_201 F_89 ( struct V_1 * V_2 )
{
V_201 V_232 = V_2 -> V_92 ;
V_2 -> V_92 ++ ;
V_2 -> V_97 ++ ;
return V_232 ;
}
int F_79 ( const union V_168 * V_233 ,
const union V_168 * V_234 )
{
struct V_235 * V_236 ;
V_236 = F_90 ( V_233 -> V_237 . V_238 ) ;
if ( F_91 ( ! V_236 ) )
return 0 ;
return V_236 -> V_239 ( V_233 , V_234 ) ;
}
struct V_188 * F_92 ( struct V_1 * V_2 )
{
struct V_188 * V_240 ;
if ( V_2 -> V_118 )
V_240 = F_93 ( V_2 , V_2 -> V_241 ) ;
else
V_240 = NULL ;
return V_240 ;
}
struct V_149 * F_94 ( struct V_1 * V_2 ,
V_201 V_242 )
{
struct V_149 * V_187 ;
struct V_149 * V_243 ;
struct V_149 * V_150 ;
struct V_188 * V_240 ;
T_6 V_244 = F_95 ( V_242 ) ;
V_243 = NULL ;
V_187 = V_2 -> V_80 . V_171 ;
F_63 (chunk, &active->transmitted,
transmitted_list) {
if ( V_244 == V_240 -> V_245 . V_246 -> V_242 ) {
V_243 = V_187 ;
goto V_247;
}
}
F_63 (transport, &asoc->peer.transport_addr_list,
transports) {
if ( V_150 == V_187 )
break;
F_63 (chunk, &transport->transmitted,
transmitted_list) {
if ( V_244 == V_240 -> V_245 . V_246 -> V_242 ) {
V_243 = V_150 ;
goto V_247;
}
}
}
V_247:
return V_243 ;
}
struct V_149 * F_96 ( struct V_1 * V_2 ,
struct V_9 * V_9 ,
const union V_168 * V_248 ,
const union V_168 * V_249 )
{
struct V_149 * V_150 ;
if ( ( F_21 ( V_2 -> V_15 . V_20 . V_21 ) == V_248 -> V_178 . V_179 ) &&
( F_21 ( V_2 -> V_80 . V_21 ) == V_249 -> V_178 . V_179 ) &&
F_97 ( F_2 ( V_2 -> V_15 . V_6 ) , V_9 ) ) {
V_150 = F_68 ( V_2 , V_249 ) ;
if ( ! V_150 )
goto V_247;
if ( F_98 ( & V_2 -> V_15 . V_20 , V_248 ,
F_3 ( V_2 -> V_15 . V_6 ) ) )
goto V_247;
}
V_150 = NULL ;
V_247:
return V_150 ;
}
static void V_112 ( struct V_250 * V_251 )
{
struct V_1 * V_2 =
F_99 ( V_251 , struct V_1 ,
V_15 . V_111 . V_252 ) ;
struct V_9 * V_9 = F_2 ( V_2 -> V_15 . V_6 ) ;
struct V_3 * V_4 ;
struct V_188 * V_240 ;
struct V_253 * V_111 ;
int V_22 ;
T_7 V_254 ;
int error = 0 ;
V_4 = V_2 -> V_4 ;
V_111 = & V_2 -> V_15 . V_111 ;
F_86 ( V_2 ) ;
while ( NULL != ( V_240 = F_100 ( V_111 ) ) ) {
V_22 = V_2 -> V_22 ;
V_254 = F_101 ( V_240 -> V_255 -> type ) ;
if ( F_102 ( V_254 . V_240 , V_2 ) && ! V_240 -> V_256 )
continue;
if ( F_103 ( V_240 ) )
V_2 -> V_80 . V_182 = V_240 -> V_150 ;
else {
F_104 ( V_9 , V_257 ) ;
V_2 -> V_132 . V_258 ++ ;
if ( V_240 -> V_255 -> type == V_259 )
V_2 -> V_132 . V_260 ++ ;
}
if ( V_240 -> V_150 )
V_240 -> V_150 -> V_231 = V_192 ;
error = F_105 ( V_9 , V_261 , V_254 ,
V_22 , V_4 , V_2 , V_240 , V_230 ) ;
if ( V_2 -> V_15 . V_18 )
break;
if ( error && V_240 )
V_240 -> V_262 = 1 ;
}
F_42 ( V_2 ) ;
}
void F_106 ( struct V_1 * V_148 , struct V_5 * V_263 )
{
struct V_10 * V_264 = F_3 ( V_263 ) ;
struct V_5 * V_265 = V_148 -> V_15 . V_6 ;
F_107 ( & V_148 -> V_124 ) ;
if ( F_32 ( V_265 , V_154 ) )
V_265 -> V_156 -- ;
F_23 ( V_148 -> V_4 ) ;
F_24 ( V_148 -> V_15 . V_6 ) ;
V_148 -> V_4 = V_264 -> V_4 ;
F_4 ( V_148 -> V_4 ) ;
V_148 -> V_15 . V_6 = V_263 ;
F_5 ( V_148 -> V_15 . V_6 ) ;
F_108 ( V_264 -> V_4 , V_148 ) ;
}
void F_109 ( struct V_1 * V_2 ,
struct V_1 * V_266 )
{
struct V_149 * V_267 ;
struct V_151 * V_152 , * V_153 ;
V_2 -> V_65 = V_266 -> V_65 ;
V_2 -> V_80 . V_76 = V_266 -> V_80 . V_76 ;
V_2 -> V_80 . V_103 = V_266 -> V_80 . V_103 ;
V_2 -> V_80 . V_12 = V_266 -> V_80 . V_12 ;
F_110 ( & V_2 -> V_80 . V_116 , V_268 ,
V_2 -> V_80 . V_12 . V_91 , V_230 ) ;
F_43 (pos, temp, &asoc->peer.transport_addr_list) {
V_267 = F_44 ( V_152 , struct V_149 , V_161 ) ;
if ( ! F_68 ( V_266 , & V_267 -> V_167 ) ) {
F_59 ( V_2 , V_267 ) ;
continue;
}
if ( V_2 -> V_22 >= V_269 )
F_111 ( V_267 ) ;
}
if ( V_2 -> V_22 >= V_269 ) {
V_2 -> V_92 = V_266 -> V_92 ;
V_2 -> V_93 = V_266 -> V_93 ;
V_2 -> V_94 = V_266 -> V_94 ;
F_112 ( V_2 -> V_73 ) ;
F_113 ( & V_2 -> V_114 ) ;
V_2 -> V_42 = 0 ;
} else {
F_63 (trans, &new->peer.transport_addr_list,
transports) {
if ( ! F_68 ( V_2 , & V_267 -> V_167 ) )
F_67 ( V_2 , & V_267 -> V_167 ,
V_230 , V_267 -> V_22 ) ;
}
V_2 -> V_93 = V_2 -> V_92 - 1 ;
V_2 -> V_94 = V_2 -> V_93 ;
if ( ! V_2 -> V_73 ) {
V_2 -> V_73 = V_266 -> V_73 ;
V_266 -> V_73 = NULL ;
}
if ( ! V_2 -> V_119 ) {
F_114 ( V_2 , V_230 ) ;
}
}
F_29 ( V_2 -> V_80 . V_158 ) ;
V_2 -> V_80 . V_158 = V_266 -> V_80 . V_158 ;
V_266 -> V_80 . V_158 = NULL ;
F_29 ( V_2 -> V_80 . V_159 ) ;
V_2 -> V_80 . V_159 = V_266 -> V_80 . V_159 ;
V_266 -> V_80 . V_159 = NULL ;
F_29 ( V_2 -> V_80 . V_160 ) ;
V_2 -> V_80 . V_160 = V_266 -> V_80 . V_160 ;
V_266 -> V_80 . V_160 = NULL ;
F_49 ( V_2 -> V_136 ) ;
F_115 ( V_2 , V_230 ) ;
}
void F_61 ( struct V_1 * V_2 )
{
struct V_149 * V_208 , * V_181 ;
struct V_151 * V_270 = & V_2 -> V_80 . V_101 ;
struct V_151 * V_152 ;
if ( V_2 -> V_80 . V_102 == 1 )
return;
V_208 = V_2 -> V_80 . V_180 ;
V_152 = & V_208 -> V_161 ;
V_181 = NULL ;
while ( 1 ) {
if ( V_152 -> V_181 == V_270 )
V_152 = V_270 -> V_181 ;
else
V_152 = V_152 -> V_181 ;
V_208 = F_44 ( V_152 , struct V_149 , V_161 ) ;
if ( V_208 == V_2 -> V_80 . V_180 ) {
V_208 = V_181 ;
break;
}
if ( ( V_208 -> V_22 == V_169 ) ||
( V_208 -> V_22 == V_170 ) ) {
break;
} else {
if ( V_208 -> V_22 != V_206 && ! V_181 )
V_181 = V_208 ;
}
}
if ( V_208 )
V_2 -> V_80 . V_180 = V_208 ;
else
V_208 = V_2 -> V_80 . V_180 ;
F_60 ( L_9
L_10 ,
L_4 ,
V_2 ,
( & V_208 -> V_167 ) ,
F_20 ( V_208 -> V_167 . V_178 . V_179 ) ) ;
}
struct V_149 * F_116 (
struct V_1 * V_2 , struct V_149 * V_271 )
{
if ( ! V_271 )
return V_2 -> V_80 . V_171 ;
else {
if ( V_271 == V_2 -> V_80 . V_180 )
F_61 ( V_2 ) ;
return V_2 -> V_80 . V_180 ;
}
}
void F_117 ( struct V_5 * V_6 , struct V_1 * V_2 )
{
struct V_149 * V_208 ;
V_201 V_272 = 0 ;
if ( ! V_2 )
return;
F_63 (t, &asoc->peer.transport_addr_list,
transports) {
if ( V_208 -> V_198 && V_208 -> V_225 ) {
F_118 ( V_6 , V_208 , F_119 ( V_208 -> V_225 ) ) ;
V_208 -> V_198 = 0 ;
}
if ( ! V_272 || ( V_208 -> V_45 < V_272 ) )
V_272 = V_208 -> V_45 ;
}
if ( V_272 ) {
V_2 -> V_45 = V_272 ;
V_2 -> V_29 = F_72 ( V_2 , V_272 ) ;
}
F_28 ( L_11 ,
V_273 , V_2 , V_2 -> V_45 , V_2 -> V_29 ) ;
}
static inline int F_120 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_2 ( V_2 -> V_15 . V_6 ) ;
switch ( V_2 -> V_22 ) {
case V_269 :
case V_274 :
case V_275 :
case V_276 :
if ( ( V_2 -> V_76 > V_2 -> V_77 ) &&
( ( V_2 -> V_76 - V_2 -> V_77 ) >= F_75 ( V_201 ,
( V_2 -> V_15 . V_6 -> V_74 >> V_9 -> V_34 . V_277 ) ,
V_2 -> V_45 ) ) )
return 1 ;
break;
default:
break;
}
return 0 ;
}
void F_121 ( struct V_1 * V_2 , unsigned int V_278 )
{
struct V_188 * V_279 ;
struct V_280 * V_281 ;
if ( V_2 -> V_78 ) {
if ( V_2 -> V_78 >= V_278 ) {
V_2 -> V_78 -= V_278 ;
} else {
V_2 -> V_76 += ( V_278 - V_2 -> V_78 ) ;
V_2 -> V_78 = 0 ;
}
} else {
V_2 -> V_76 += V_278 ;
}
if ( V_2 -> V_79 && V_2 -> V_76 >= V_2 -> V_79 ) {
int V_282 = F_74 ( V_2 -> V_45 , V_2 -> V_79 ) ;
V_2 -> V_76 += V_282 ;
V_2 -> V_79 -= V_282 ;
}
F_28 ( L_12
L_13 , V_273 , V_2 , V_278 , V_2 -> V_76 ,
V_2 -> V_78 , V_2 -> V_77 ) ;
if ( F_120 ( V_2 ) ) {
V_2 -> V_77 = V_2 -> V_76 ;
F_28 ( L_14
L_15 , V_273 ,
V_2 , V_2 -> V_76 , V_2 -> V_77 ) ;
V_279 = F_122 ( V_2 ) ;
if ( ! V_279 )
return;
V_2 -> V_80 . V_103 = 0 ;
F_123 ( & V_2 -> V_113 , V_279 ) ;
V_281 = & V_2 -> V_63 [ V_59 ] ;
if ( F_40 ( V_281 ) && F_41 ( V_281 ) )
F_42 ( V_2 ) ;
}
}
void F_124 ( struct V_1 * V_2 , unsigned int V_278 )
{
int V_283 ;
int V_284 = 0 ;
F_51 (asoc->rwnd, L_16 , return) ;
F_51 (!asoc->rwnd_over, L_17 , return) ;
if ( V_2 -> V_4 -> V_285 )
V_283 = F_56 ( & V_2 -> V_83 ) ;
else
V_283 = F_56 ( & V_2 -> V_15 . V_6 -> V_286 ) ;
if ( V_283 >= V_2 -> V_15 . V_6 -> V_74 )
V_284 = 1 ;
if ( V_2 -> V_76 >= V_278 ) {
V_2 -> V_76 -= V_278 ;
if ( V_284 ) {
V_2 -> V_79 += V_2 -> V_76 ;
V_2 -> V_76 = 0 ;
}
} else {
V_2 -> V_78 = V_278 - V_2 -> V_76 ;
V_2 -> V_76 = 0 ;
}
F_28 ( L_18 ,
V_273 , V_2 , V_278 , V_2 -> V_76 ,
V_2 -> V_78 , V_2 -> V_79 ) ;
}
int F_125 ( struct V_1 * V_2 ,
T_1 V_7 , T_2 V_8 )
{
int V_287 ;
V_287 = ( V_122 == V_2 -> V_15 . V_6 -> V_121 ) ? V_288 : 0 ;
if ( V_2 -> V_80 . V_120 )
V_287 |= V_289 ;
if ( V_2 -> V_80 . V_123 )
V_287 |= V_290 ;
return F_126 ( F_2 ( V_2 -> V_15 . V_6 ) ,
& V_2 -> V_15 . V_20 ,
& V_2 -> V_4 -> V_15 . V_20 ,
V_7 , V_8 , V_287 ) ;
}
int F_127 ( struct V_1 * V_2 ,
struct V_291 * V_157 ,
T_2 V_8 )
{
int V_292 = F_20 ( V_157 -> V_293 -> V_255 . V_141 ) ;
int V_294 = V_157 -> V_295 ;
T_8 * V_296 = ( T_8 * ) V_157 -> V_293 + V_292 ;
return F_128 ( & V_2 -> V_15 . V_20 , V_296 , V_294 ,
V_2 -> V_4 -> V_15 . V_20 . V_21 , V_8 ) ;
}
int F_129 ( struct V_1 * V_2 ,
const union V_168 * V_248 )
{
int V_297 = 0 ;
if ( ( V_2 -> V_15 . V_20 . V_21 == F_20 ( V_248 -> V_178 . V_179 ) ) &&
F_98 ( & V_2 -> V_15 . V_20 , V_248 ,
F_3 ( V_2 -> V_15 . V_6 ) ) )
V_297 = 1 ;
return V_297 ;
}
int F_114 ( struct V_1 * V_2 , T_2 V_8 )
{
int V_119 ;
int error = 0 ;
if ( V_2 -> V_119 )
return error ;
V_298:
if ( F_91 ( ! F_130 ( & V_163 , V_8 ) ) )
return - V_299 ;
F_52 ( & V_162 ) ;
error = F_131 ( & V_163 , ( void * ) V_2 ,
V_300 , & V_119 ) ;
if ( ! error ) {
V_300 = V_119 + 1 ;
if ( V_300 == V_301 )
V_300 = 1 ;
}
F_54 ( & V_162 ) ;
if ( error == - V_302 )
goto V_298;
else if ( error )
return error ;
V_2 -> V_119 = ( V_303 ) V_119 ;
return error ;
}
static void F_132 ( struct V_1 * V_2 )
{
struct V_188 * V_304 ;
struct V_188 * V_305 ;
F_81 (asconf, tmp, &asoc->addip_chunk_list, list) {
F_107 ( & V_304 -> V_306 ) ;
F_133 ( V_304 ) ;
}
}
static void F_134 ( struct V_1 * V_2 )
{
struct V_188 * V_307 ;
struct V_188 * V_305 ;
F_81 (ack, tmp, &asoc->asconf_ack_list,
transmitted_list) {
F_107 ( & V_307 -> V_308 ) ;
F_133 ( V_307 ) ;
}
}
void F_135 ( const struct V_1 * V_2 )
{
struct V_188 * V_307 ;
struct V_188 * V_305 ;
F_81 (ack, tmp, &asoc->asconf_ack_list,
transmitted_list) {
if ( V_307 -> V_245 . V_309 -> V_310 ==
F_95 ( V_2 -> V_80 . V_98 ) )
break;
F_107 ( & V_307 -> V_308 ) ;
F_133 ( V_307 ) ;
}
}
struct V_188 * F_136 (
const struct V_1 * V_2 ,
T_6 V_310 )
{
struct V_188 * V_307 ;
F_63 (ack, &asoc->asconf_ack_list, transmitted_list) {
if ( V_307 -> V_245 . V_309 -> V_310 == V_310 ) {
F_137 ( V_307 ) ;
return V_307 ;
}
}
return NULL ;
}
void F_47 ( struct V_1 * V_2 )
{
F_134 ( V_2 ) ;
F_132 ( V_2 ) ;
if ( V_2 -> V_185 )
F_133 ( V_2 -> V_185 ) ;
}
