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
F_7 ( & V_2 -> V_15 . V_18 , V_4 -> V_15 . V_18 . V_19 ) ;
V_2 -> V_20 = V_21 ;
V_2 -> V_22 = F_8 ( V_11 -> V_23 . V_24 ) ;
V_2 -> V_25 = V_11 -> V_25 ;
V_2 -> V_26 = V_11 -> V_23 . V_27 ;
V_2 -> V_28 = V_9 -> V_29 . V_28 ;
V_2 -> V_30 = F_9 ( V_11 -> V_31 . V_32 ) ;
V_2 -> V_33 = F_9 ( V_11 -> V_31 . V_34 ) ;
V_2 -> V_35 = F_9 ( V_11 -> V_31 . V_36 ) ;
V_2 -> V_37 = F_9 ( V_11 -> V_37 ) ;
V_2 -> V_38 = V_11 -> V_38 ;
V_2 -> V_39 = V_11 -> V_39 ;
V_2 -> V_40 = F_9 ( V_11 -> V_40 ) ;
V_2 -> V_41 = V_11 -> V_41 ;
V_2 -> V_42 = V_11 -> V_42 ;
V_2 -> V_43 = V_11 -> V_43 ;
V_2 -> V_44 [ V_45 ] = V_2 -> V_30 ;
V_2 -> V_44 [ V_46 ] = V_2 -> V_30 ;
V_2 -> V_44 [ V_47 ] = V_2 -> V_30 ;
V_2 -> V_44 [ V_48 ]
= 5 * V_2 -> V_33 ;
V_2 -> V_44 [ V_49 ] = V_2 -> V_40 ;
V_2 -> V_44 [ V_50 ] = V_11 -> V_51 * V_52 ;
for ( V_12 = V_53 ; V_12 < V_54 ; ++ V_12 )
F_10 ( & V_2 -> V_55 [ V_12 ] , V_56 [ V_12 ] ,
( unsigned long ) V_2 ) ;
V_2 -> V_57 . V_58 = V_11 -> V_59 . V_58 ;
V_2 -> V_57 . V_60 = V_11 -> V_59 . V_60 ;
V_2 -> V_61 = V_11 -> V_59 . V_62 ;
V_2 -> V_63 =
F_9 ( V_11 -> V_59 . V_64 ) ;
if ( ( V_6 -> V_65 / 2 ) < V_66 )
V_2 -> V_67 = V_66 ;
else
V_2 -> V_67 = V_6 -> V_65 / 2 ;
V_2 -> V_68 = V_2 -> V_67 ;
V_2 -> V_69 . V_67 = V_70 ;
F_6 ( & V_2 -> V_71 , 0 ) ;
F_11 ( & V_2 -> V_72 ) ;
V_2 -> V_57 . V_73 = F_12 ( V_4 ) ;
V_2 -> V_57 . V_74 = V_4 -> V_15 . V_18 . V_19 ;
V_2 -> V_57 . V_75 = F_13 ( V_4 ) ;
V_2 -> V_76 = V_2 -> V_57 . V_75 ;
V_2 -> V_77 = V_2 -> V_76 - 1 ;
V_2 -> V_78 = V_2 -> V_77 ;
V_2 -> V_79 = V_2 -> V_77 ;
V_2 -> V_80 = V_2 -> V_77 ;
V_2 -> V_81 = V_2 -> V_57 . V_75 ;
F_14 ( & V_2 -> V_82 ) ;
F_14 ( & V_2 -> V_83 ) ;
F_14 ( & V_2 -> V_69 . V_84 ) ;
V_2 -> V_69 . V_85 = 1 ;
V_2 -> V_69 . V_86 = 1 ;
if ( V_9 -> V_29 . V_87 )
V_2 -> V_69 . V_88 = 1 ;
F_15 ( & V_2 -> V_15 . V_89 ) ;
F_16 ( & V_2 -> V_15 . V_89 , V_90 ) ;
F_17 ( V_2 , & V_2 -> V_91 ) ;
if ( ! F_18 ( & V_2 -> V_92 , V_2 ) )
goto V_93;
V_2 -> V_69 . V_94 = 1 ;
if ( V_2 -> V_15 . V_6 -> V_95 == V_96 )
V_2 -> V_69 . V_97 = 1 ;
F_14 ( & V_2 -> V_98 ) ;
V_2 -> V_99 = V_11 -> V_99 ;
V_2 -> V_100 = V_11 -> V_100 ;
V_2 -> V_101 = V_11 -> V_101 ;
V_2 -> V_102 = V_11 -> V_102 ;
V_2 -> V_103 = V_11 -> V_103 ;
V_2 -> V_104 = V_11 -> V_104 ;
F_14 ( & V_2 -> V_105 ) ;
V_14 = F_19 ( V_4 , V_2 , V_8 ) ;
if ( V_14 )
goto V_93;
V_2 -> V_106 = V_4 -> V_106 ;
V_2 -> V_107 = V_4 -> V_107 ;
if ( V_4 -> V_108 )
memcpy ( V_2 -> V_57 . V_109 , V_4 -> V_108 ,
F_20 ( V_4 -> V_108 -> V_110 . V_111 ) ) ;
if ( V_4 -> V_112 )
memcpy ( V_2 -> V_57 . V_113 , V_4 -> V_112 ,
F_20 ( V_4 -> V_112 -> V_110 . V_111 ) ) ;
V_13 = ( T_3 * ) V_2 -> V_57 . V_114 ;
V_13 -> type = V_115 ;
V_13 -> V_111 = F_21 ( sizeof( T_3 ) + V_116 ) ;
F_22 ( V_13 + 1 , V_116 ) ;
return V_2 ;
V_93:
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
goto V_117;
if ( ! F_1 ( V_2 , V_4 , V_6 , V_7 , V_8 ) )
goto V_93;
F_27 ( V_118 ) ;
F_28 ( L_1 , V_2 ) ;
return V_2 ;
V_93:
F_29 ( V_2 ) ;
V_117:
return NULL ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_15 . V_6 ;
struct V_119 * V_120 ;
struct V_121 * V_122 , * V_123 ;
int V_12 ;
if ( ! F_31 ( & V_2 -> V_98 ) ) {
F_32 ( & V_2 -> V_98 ) ;
if ( F_33 ( V_6 , V_124 ) && F_34 ( V_6 , V_125 ) )
V_6 -> V_126 -- ;
}
V_2 -> V_15 . V_127 = true ;
F_35 ( & V_2 -> V_91 ) ;
F_36 ( & V_2 -> V_92 ) ;
F_37 ( & V_2 -> V_15 . V_89 ) ;
F_38 ( & V_2 -> V_69 . V_128 ) ;
F_39 ( V_2 -> V_129 ) ;
F_40 ( & V_2 -> V_15 . V_18 ) ;
for ( V_12 = V_53 ; V_12 < V_54 ; ++ V_12 ) {
if ( F_41 ( & V_2 -> V_55 [ V_12 ] ) )
F_42 ( V_2 ) ;
}
F_29 ( V_2 -> V_69 . V_130 ) ;
F_29 ( V_2 -> V_69 . V_131 ) ;
F_29 ( V_2 -> V_69 . V_132 ) ;
F_29 ( V_2 -> V_69 . V_133 ) ;
F_43 (pos, temp, &asoc->peer.transport_addr_list) {
V_120 = F_44 ( V_122 , struct V_119 , V_134 ) ;
F_45 ( V_122 ) ;
F_46 ( V_120 ) ;
F_47 ( V_120 ) ;
}
V_2 -> V_69 . V_135 = 0 ;
F_48 ( V_2 ) ;
F_29 ( V_2 -> V_136 ) ;
F_49 ( & V_2 -> V_105 ) ;
F_50 ( V_2 -> V_137 ) ;
F_42 ( V_2 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
if ( F_52 ( ! V_2 -> V_15 . V_127 ) ) {
F_53 ( 1 , L_2 , V_2 ) ;
return;
}
F_24 ( V_2 -> V_4 ) ;
F_23 ( V_2 -> V_15 . V_6 ) ;
if ( V_2 -> V_138 != 0 ) {
F_54 ( & V_139 ) ;
F_55 ( & V_140 , V_2 -> V_138 ) ;
F_56 ( & V_139 ) ;
}
F_57 ( F_58 ( & V_2 -> V_71 ) ) ;
F_29 ( V_2 ) ;
F_59 ( V_118 ) ;
}
void F_60 ( struct V_1 * V_2 ,
struct V_119 * V_120 )
{
int V_141 = 0 ;
if ( V_2 -> V_69 . V_142 != NULL &&
V_2 -> V_69 . V_142 != V_120 )
V_141 = 1 ;
V_2 -> V_69 . V_142 = V_120 ;
memcpy ( & V_2 -> V_69 . V_143 , & V_120 -> V_144 ,
sizeof( union V_145 ) ) ;
if ( ( V_120 -> V_20 == V_146 ) ||
( V_120 -> V_20 == V_147 ) )
V_2 -> V_69 . V_148 = V_120 ;
if ( ! V_2 -> V_91 . V_149 && ! V_2 -> V_91 . V_150 )
return;
if ( V_120 -> V_151 . V_152 )
V_120 -> V_151 . V_153 = V_141 ;
V_120 -> V_151 . V_152 = V_141 ;
V_120 -> V_151 . V_154 = V_2 -> V_76 ;
}
void F_61 ( struct V_1 * V_2 ,
struct V_119 * V_69 )
{
struct V_121 * V_122 ;
struct V_119 * V_120 ;
F_28 ( L_3 ,
V_155 , V_2 , & V_69 -> V_144 . V_156 ) ;
if ( V_2 -> V_69 . V_157 == V_69 )
F_62 ( V_2 ) ;
F_45 ( & V_69 -> V_134 ) ;
F_46 ( V_69 ) ;
V_122 = V_2 -> V_69 . V_84 . V_158 ;
V_120 = F_44 ( V_122 , struct V_119 , V_134 ) ;
if ( V_2 -> V_69 . V_142 == V_69 )
F_60 ( V_2 , V_120 ) ;
if ( V_2 -> V_69 . V_148 == V_69 )
V_2 -> V_69 . V_148 = V_120 ;
if ( V_2 -> V_69 . V_157 == V_69 )
V_2 -> V_69 . V_157 = V_120 ;
if ( V_2 -> V_69 . V_159 == V_69 )
V_2 -> V_69 . V_159 = V_120 ;
if ( V_2 -> V_160 == V_69 )
V_2 -> V_160 = NULL ;
if ( V_2 -> V_161 == V_69 )
V_2 -> V_161 = NULL ;
if ( V_2 -> V_162 &&
V_2 -> V_162 -> V_120 == V_69 )
V_2 -> V_162 -> V_120 = NULL ;
if ( ! F_31 ( & V_69 -> V_163 ) ) {
struct V_119 * V_164 = V_2 -> V_69 . V_148 ;
struct V_165 * V_166 ;
F_63 (ch, &peer->transmitted,
transmitted_list) {
V_166 -> V_120 = NULL ;
V_166 -> V_167 = 0 ;
}
F_64 ( & V_69 -> V_163 ,
& V_164 -> V_163 ) ;
if ( ! F_65 ( & V_164 -> V_168 ) )
if ( ! F_66 ( & V_164 -> V_168 ,
V_169 + V_164 -> V_170 ) )
F_67 ( V_164 ) ;
}
V_2 -> V_69 . V_135 -- ;
F_47 ( V_69 ) ;
}
struct V_119 * F_68 ( struct V_1 * V_2 ,
const union V_145 * V_171 ,
const T_2 V_8 ,
const int V_172 )
{
struct V_9 * V_9 = F_2 ( V_2 -> V_15 . V_6 ) ;
struct V_119 * V_69 ;
struct V_10 * V_11 ;
unsigned short V_19 ;
V_11 = F_3 ( V_2 -> V_15 . V_6 ) ;
V_19 = F_20 ( V_171 -> V_173 . V_174 ) ;
F_28 ( L_4 , V_155 ,
V_2 , & V_171 -> V_156 , V_172 ) ;
if ( 0 == V_2 -> V_69 . V_19 )
V_2 -> V_69 . V_19 = V_19 ;
V_69 = F_69 ( V_2 , V_171 ) ;
if ( V_69 ) {
if ( V_69 -> V_20 == V_147 ) {
V_69 -> V_20 = V_146 ;
}
return V_69 ;
}
V_69 = F_70 ( V_9 , V_171 , V_8 ) ;
if ( ! V_69 )
return NULL ;
F_71 ( V_69 , V_2 ) ;
V_69 -> V_37 = V_2 -> V_37 ;
V_69 -> V_38 = V_2 -> V_38 ;
V_69 -> V_28 = V_2 -> V_28 ;
V_69 -> V_40 = V_2 -> V_40 ;
V_69 -> V_41 = V_2 -> V_41 ;
V_69 -> V_42 = V_2 -> V_42 ;
F_72 ( V_69 , NULL , V_11 ) ;
if ( V_69 -> V_42 & V_175 ) {
if ( V_2 -> V_39 )
V_69 -> V_39 = V_2 -> V_39 ;
else
V_69 -> V_39 = V_176 ;
}
if ( V_2 -> V_39 )
V_2 -> V_39 = F_73 ( int , V_69 -> V_39 , V_2 -> V_39 ) ;
else
V_2 -> V_39 = V_69 -> V_39 ;
F_28 ( L_5 , V_155 , V_2 ,
V_2 -> V_39 ) ;
V_69 -> V_177 = 0 ;
V_2 -> V_178 = F_74 ( V_2 , V_2 -> V_39 ) ;
F_75 ( & V_69 -> V_179 , V_69 , V_2 -> V_15 . V_18 . V_19 ,
V_2 -> V_69 . V_19 ) ;
V_69 -> V_180 = F_76 ( 4 * V_2 -> V_39 , F_77 ( V_181 , 2 * V_2 -> V_39 , 4380 ) ) ;
V_69 -> V_182 = V_70 ;
V_69 -> V_183 = 0 ;
V_69 -> V_184 = 0 ;
V_69 -> V_185 = 0 ;
V_69 -> V_170 = V_2 -> V_30 ;
F_78 ( V_2 , V_69 ) ;
V_69 -> V_20 = V_172 ;
if ( F_79 ( V_69 ) ) {
F_47 ( V_69 ) ;
return NULL ;
}
F_80 ( & V_69 -> V_134 , & V_2 -> V_69 . V_84 ) ;
V_2 -> V_69 . V_135 ++ ;
if ( ! V_2 -> V_69 . V_142 ) {
F_60 ( V_2 , V_69 ) ;
V_2 -> V_69 . V_157 = V_69 ;
}
if ( V_2 -> V_69 . V_148 == V_2 -> V_69 . V_157 &&
V_69 -> V_20 != V_186 ) {
V_2 -> V_69 . V_157 = V_69 ;
}
return V_69 ;
}
void F_81 ( struct V_1 * V_2 ,
const union V_145 * V_171 )
{
struct V_121 * V_122 ;
struct V_121 * V_123 ;
struct V_119 * V_120 ;
F_43 (pos, temp, &asoc->peer.transport_addr_list) {
V_120 = F_44 ( V_122 , struct V_119 , V_134 ) ;
if ( F_82 ( V_171 , & V_120 -> V_144 ) ) {
F_61 ( V_2 , V_120 ) ;
break;
}
}
}
struct V_119 * F_69 (
const struct V_1 * V_2 ,
const union V_145 * V_187 )
{
struct V_119 * V_188 ;
F_63 (t, &asoc->peer.transport_addr_list,
transports) {
if ( F_82 ( V_187 , & V_188 -> V_144 ) )
return V_188 ;
}
return NULL ;
}
void F_83 ( struct V_1 * V_2 ,
struct V_119 * V_189 )
{
struct V_119 * V_123 ;
struct V_119 * V_188 ;
F_84 (t, temp, &asoc->peer.transport_addr_list,
transports) {
if ( V_188 != V_189 )
F_61 ( V_2 , V_188 ) ;
}
}
void F_85 ( struct V_1 * V_2 ,
struct V_119 * V_120 ,
T_4 V_190 ,
T_5 error )
{
struct V_191 * V_192 ;
struct V_193 V_171 ;
int V_194 = 0 ;
bool V_195 = true ;
switch ( V_190 ) {
case V_196 :
if ( V_186 == V_120 -> V_20 &&
V_197 == error )
V_194 = V_198 ;
else
V_194 = V_199 ;
if ( V_120 -> V_20 == V_200 ) {
V_195 = false ;
V_120 -> V_180 = V_2 -> V_39 ;
}
V_120 -> V_20 = V_146 ;
break;
case V_201 :
if ( V_120 -> V_20 != V_186 )
V_120 -> V_20 = V_202 ;
else {
F_86 ( V_120 -> V_203 ) ;
V_120 -> V_203 = NULL ;
V_195 = false ;
}
V_194 = V_204 ;
break;
case V_205 :
V_120 -> V_20 = V_200 ;
V_195 = false ;
break;
default:
return;
}
if ( V_195 ) {
memset ( & V_171 , 0 , sizeof( struct V_193 ) ) ;
memcpy ( & V_171 , & V_120 -> V_144 ,
V_120 -> V_206 -> V_207 ) ;
V_192 = F_87 ( V_2 , & V_171 ,
0 , V_194 , error , V_208 ) ;
if ( V_192 )
F_88 ( & V_2 -> V_92 , V_192 ) ;
}
F_89 ( V_2 ) ;
}
void F_90 ( struct V_1 * V_2 )
{
F_91 ( & V_2 -> V_15 . V_17 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
if ( F_92 ( & V_2 -> V_15 . V_17 ) )
F_51 ( V_2 ) ;
}
V_181 F_93 ( struct V_1 * V_2 )
{
V_181 V_209 = V_2 -> V_76 ;
V_2 -> V_76 ++ ;
V_2 -> V_210 ++ ;
return V_209 ;
}
int F_82 ( const union V_145 * V_211 ,
const union V_145 * V_212 )
{
struct V_213 * V_214 ;
V_214 = F_94 ( V_211 -> V_156 . V_215 ) ;
if ( F_52 ( ! V_214 ) )
return 0 ;
return V_214 -> V_216 ( V_211 , V_212 ) ;
}
struct V_165 * F_95 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_217 )
return NULL ;
return F_96 ( V_2 , V_2 -> V_218 ) ;
}
struct V_119 * F_97 ( struct V_1 * V_2 ,
V_181 V_219 )
{
struct V_119 * V_164 ;
struct V_119 * V_220 ;
struct V_119 * V_120 ;
struct V_165 * V_221 ;
T_6 V_222 = F_98 ( V_219 ) ;
V_220 = NULL ;
V_164 = V_2 -> V_69 . V_148 ;
F_63 (chunk, &active->transmitted,
transmitted_list) {
if ( V_222 == V_221 -> V_223 . V_224 -> V_219 ) {
V_220 = V_164 ;
goto V_225;
}
}
F_63 (transport, &asoc->peer.transport_addr_list,
transports) {
if ( V_120 == V_164 )
continue;
F_63 (chunk, &transport->transmitted,
transmitted_list) {
if ( V_222 == V_221 -> V_223 . V_224 -> V_219 ) {
V_220 = V_120 ;
goto V_225;
}
}
}
V_225:
return V_220 ;
}
struct V_119 * F_99 ( struct V_1 * V_2 ,
struct V_9 * V_9 ,
const union V_145 * V_226 ,
const union V_145 * V_227 )
{
struct V_119 * V_120 ;
if ( ( F_21 ( V_2 -> V_15 . V_18 . V_19 ) == V_226 -> V_173 . V_174 ) &&
( F_21 ( V_2 -> V_69 . V_19 ) == V_227 -> V_173 . V_174 ) &&
F_100 ( F_2 ( V_2 -> V_15 . V_6 ) , V_9 ) ) {
V_120 = F_69 ( V_2 , V_227 ) ;
if ( ! V_120 )
goto V_225;
if ( F_101 ( & V_2 -> V_15 . V_18 , V_226 ,
F_3 ( V_2 -> V_15 . V_6 ) ) )
goto V_225;
}
V_120 = NULL ;
V_225:
return V_120 ;
}
static void V_90 ( struct V_228 * V_229 )
{
struct V_1 * V_2 =
F_102 ( V_229 , struct V_1 ,
V_15 . V_89 . V_230 ) ;
struct V_9 * V_9 = F_2 ( V_2 -> V_15 . V_6 ) ;
struct V_3 * V_4 ;
struct V_165 * V_221 ;
struct V_231 * V_89 ;
int V_20 ;
T_7 V_232 ;
int error = 0 ;
V_4 = V_2 -> V_4 ;
V_89 = & V_2 -> V_15 . V_89 ;
F_90 ( V_2 ) ;
while ( NULL != ( V_221 = F_103 ( V_89 ) ) ) {
V_20 = V_2 -> V_20 ;
V_232 = F_104 ( V_221 -> V_233 -> type ) ;
if ( F_105 ( V_232 . V_221 , V_2 ) && ! V_221 -> V_234 )
continue;
if ( F_106 ( V_221 ) )
V_2 -> V_69 . V_159 = V_221 -> V_120 ;
else {
F_107 ( V_9 , V_235 ) ;
V_2 -> V_236 . V_237 ++ ;
if ( V_221 -> V_233 -> type == V_238 )
V_2 -> V_236 . V_239 ++ ;
}
if ( V_221 -> V_120 )
V_221 -> V_120 -> V_240 = F_108 () ;
error = F_109 ( V_9 , V_241 , V_232 ,
V_20 , V_4 , V_2 , V_221 , V_208 ) ;
if ( V_2 -> V_15 . V_127 )
break;
if ( error && V_221 )
V_221 -> V_242 = 1 ;
}
F_42 ( V_2 ) ;
}
void F_110 ( struct V_1 * V_118 , struct V_5 * V_243 )
{
struct V_10 * V_244 = F_3 ( V_243 ) ;
struct V_5 * V_245 = V_118 -> V_15 . V_6 ;
F_111 ( & V_118 -> V_98 ) ;
if ( F_33 ( V_245 , V_124 ) )
V_245 -> V_126 -- ;
F_24 ( V_118 -> V_4 ) ;
F_23 ( V_118 -> V_15 . V_6 ) ;
V_118 -> V_4 = V_244 -> V_4 ;
F_4 ( V_118 -> V_4 ) ;
V_118 -> V_15 . V_6 = V_243 ;
F_5 ( V_118 -> V_15 . V_6 ) ;
F_112 ( V_244 -> V_4 , V_118 ) ;
}
void F_113 ( struct V_1 * V_2 ,
struct V_1 * V_246 )
{
struct V_119 * V_247 ;
struct V_121 * V_122 , * V_123 ;
V_2 -> V_57 = V_246 -> V_57 ;
V_2 -> V_69 . V_67 = V_246 -> V_69 . V_67 ;
V_2 -> V_69 . V_85 = V_246 -> V_69 . V_85 ;
V_2 -> V_69 . V_248 = V_246 -> V_69 . V_248 ;
V_2 -> V_69 . V_12 = V_246 -> V_69 . V_12 ;
F_114 ( & V_2 -> V_69 . V_128 , V_249 ,
V_2 -> V_69 . V_12 . V_75 , V_208 ) ;
F_43 (pos, temp, &asoc->peer.transport_addr_list) {
V_247 = F_44 ( V_122 , struct V_119 , V_134 ) ;
if ( ! F_69 ( V_246 , & V_247 -> V_144 ) ) {
F_61 ( V_2 , V_247 ) ;
continue;
}
if ( V_2 -> V_20 >= V_250 )
F_115 ( V_247 ) ;
}
if ( V_2 -> V_20 >= V_250 ) {
V_2 -> V_76 = V_246 -> V_76 ;
V_2 -> V_77 = V_246 -> V_77 ;
V_2 -> V_78 = V_246 -> V_78 ;
F_116 ( V_2 -> V_129 ) ;
F_117 ( & V_2 -> V_92 ) ;
V_2 -> V_251 = 0 ;
} else {
F_63 (trans, &new->peer.transport_addr_list,
transports) {
if ( ! F_69 ( V_2 , & V_247 -> V_144 ) )
F_68 ( V_2 , & V_247 -> V_144 ,
V_208 , V_247 -> V_20 ) ;
}
V_2 -> V_77 = V_2 -> V_76 - 1 ;
V_2 -> V_78 = V_2 -> V_77 ;
if ( ! V_2 -> V_129 ) {
V_2 -> V_129 = V_246 -> V_129 ;
V_246 -> V_129 = NULL ;
}
if ( ! V_2 -> V_138 ) {
F_118 ( V_2 , V_208 ) ;
}
}
F_29 ( V_2 -> V_69 . V_131 ) ;
V_2 -> V_69 . V_131 = V_246 -> V_69 . V_131 ;
V_246 -> V_69 . V_131 = NULL ;
F_29 ( V_2 -> V_69 . V_132 ) ;
V_2 -> V_69 . V_132 = V_246 -> V_69 . V_132 ;
V_246 -> V_69 . V_132 = NULL ;
F_29 ( V_2 -> V_69 . V_133 ) ;
V_2 -> V_69 . V_133 = V_246 -> V_69 . V_133 ;
V_246 -> V_69 . V_133 = NULL ;
F_119 ( V_2 , V_208 ) ;
}
static T_8 F_120 ( const struct V_119 * V_247 )
{
switch ( V_247 -> V_20 ) {
case V_146 :
return 3 ;
case V_147 :
return 2 ;
case V_200 :
return 1 ;
default:
return 0 ;
}
}
static struct V_119 * F_121 ( struct V_119 * V_252 ,
struct V_119 * V_253 )
{
if ( V_252 -> V_254 > V_253 -> V_254 ) {
return V_253 ;
} else if ( V_252 -> V_254 == V_253 -> V_254 &&
F_122 ( V_253 -> V_240 ,
V_252 -> V_240 ) ) {
return V_253 ;
} else {
return V_252 ;
}
}
static struct V_119 * F_123 ( struct V_119 * V_255 ,
struct V_119 * V_256 )
{
T_8 V_257 , V_258 ;
if ( V_256 == NULL || V_255 == V_256 )
return V_255 ;
V_257 = F_120 ( V_255 ) ;
V_258 = F_120 ( V_256 ) ;
if ( V_257 > V_258 )
return V_255 ;
else if ( V_257 == V_258 )
return F_121 ( V_256 , V_255 ) ;
else
return V_256 ;
}
void F_62 ( struct V_1 * V_2 )
{
struct V_119 * V_247 = V_2 -> V_69 . V_157 ;
struct V_119 * V_259 = NULL ;
if ( V_2 -> V_69 . V_135 == 1 )
return;
if ( V_2 -> V_69 . V_148 == V_2 -> V_69 . V_157 &&
V_2 -> V_69 . V_148 -> V_20 == V_146 )
return;
for ( V_247 = F_124 ( V_247 , V_134 ) ; 1 ;
V_247 = F_124 ( V_247 , V_134 ) ) {
if ( & V_247 -> V_134 == & V_2 -> V_69 . V_84 )
continue;
if ( V_247 -> V_20 == V_186 )
continue;
V_259 = F_123 ( V_247 , V_259 ) ;
if ( V_259 -> V_20 == V_146 )
break;
if ( V_247 == V_2 -> V_69 . V_157 )
break;
}
V_2 -> V_69 . V_157 = V_259 ;
F_28 ( L_6 ,
V_155 , V_2 , & V_2 -> V_69 . V_157 -> V_144 . V_156 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_119 * V_247 , * V_260 = NULL , * V_261 = NULL ;
struct V_119 * V_262 = NULL ;
F_63 (trans, &asoc->peer.transport_addr_list,
transports) {
if ( V_247 -> V_20 == V_202 ||
V_247 -> V_20 == V_186 )
continue;
if ( V_247 -> V_20 == V_200 ) {
V_262 = F_123 ( V_247 , V_262 ) ;
continue;
}
if ( V_260 == NULL ||
F_122 ( V_247 -> V_240 ,
V_260 -> V_240 ) ) {
V_261 = V_260 ;
V_260 = V_247 ;
} else if ( V_261 == NULL ||
F_122 ( V_247 -> V_240 ,
V_261 -> V_240 ) ) {
V_261 = V_247 ;
}
}
if ( ( V_2 -> V_69 . V_142 -> V_20 == V_146 ||
V_2 -> V_69 . V_142 -> V_20 == V_147 ) &&
V_2 -> V_69 . V_142 != V_260 ) {
V_261 = V_260 ;
V_260 = V_2 -> V_69 . V_142 ;
}
if ( V_261 == NULL )
V_261 = V_260 ;
if ( V_260 == NULL ) {
V_260 = F_123 ( V_2 -> V_69 . V_148 , V_262 ) ;
V_261 = V_260 ;
}
V_2 -> V_69 . V_148 = V_260 ;
V_2 -> V_69 . V_157 = V_261 ;
}
struct V_119 *
F_125 ( struct V_1 * V_2 ,
struct V_119 * V_263 )
{
if ( V_263 == NULL ) {
return V_2 -> V_69 . V_148 ;
} else {
if ( V_263 == V_2 -> V_69 . V_157 )
F_62 ( V_2 ) ;
return V_2 -> V_69 . V_157 ;
}
}
void F_126 ( struct V_5 * V_6 , struct V_1 * V_2 )
{
struct V_119 * V_188 ;
V_181 V_264 = 0 ;
if ( ! V_2 )
return;
F_63 (t, &asoc->peer.transport_addr_list,
transports) {
if ( V_188 -> V_177 && V_188 -> V_203 ) {
F_127 ( V_6 , V_188 ,
F_128 ( F_129 ( V_188 -> V_203 ) ) ) ;
V_188 -> V_177 = 0 ;
}
if ( ! V_264 || ( V_188 -> V_39 < V_264 ) )
V_264 = V_188 -> V_39 ;
}
if ( V_264 ) {
V_2 -> V_39 = V_264 ;
V_2 -> V_178 = F_74 ( V_2 , V_264 ) ;
}
F_28 ( L_7 , V_155 , V_2 ,
V_2 -> V_39 , V_2 -> V_178 ) ;
}
static inline bool F_130 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_2 ( V_2 -> V_15 . V_6 ) ;
switch ( V_2 -> V_20 ) {
case V_250 :
case V_265 :
case V_266 :
case V_267 :
if ( ( V_2 -> V_67 > V_2 -> V_68 ) &&
( ( V_2 -> V_67 - V_2 -> V_68 ) >= F_77 ( V_181 ,
( V_2 -> V_15 . V_6 -> V_65 >> V_9 -> V_29 . V_268 ) ,
V_2 -> V_39 ) ) )
return true ;
break;
default:
break;
}
return false ;
}
void F_131 ( struct V_1 * V_2 , unsigned int V_269 )
{
struct V_165 * V_270 ;
struct V_271 * V_272 ;
if ( V_2 -> V_273 ) {
if ( V_2 -> V_273 >= V_269 ) {
V_2 -> V_273 -= V_269 ;
} else {
V_2 -> V_67 += ( V_269 - V_2 -> V_273 ) ;
V_2 -> V_273 = 0 ;
}
} else {
V_2 -> V_67 += V_269 ;
}
if ( V_2 -> V_274 ) {
int V_275 = F_76 ( V_2 -> V_39 , V_2 -> V_274 ) ;
V_2 -> V_67 += V_275 ;
V_2 -> V_274 -= V_275 ;
}
F_28 ( L_8 ,
V_155 , V_2 , V_269 , V_2 -> V_67 , V_2 -> V_273 ,
V_2 -> V_68 ) ;
if ( F_130 ( V_2 ) ) {
V_2 -> V_68 = V_2 -> V_67 ;
F_28 ( L_9
L_10 , V_155 , V_2 , V_2 -> V_67 ,
V_2 -> V_68 ) ;
V_270 = F_132 ( V_2 ) ;
if ( ! V_270 )
return;
V_2 -> V_69 . V_85 = 0 ;
F_133 ( & V_2 -> V_91 , V_270 , V_208 ) ;
V_272 = & V_2 -> V_55 [ V_49 ] ;
if ( F_41 ( V_272 ) )
F_42 ( V_2 ) ;
}
}
void F_134 ( struct V_1 * V_2 , unsigned int V_269 )
{
int V_276 ;
int V_277 = 0 ;
if ( F_52 ( ! V_2 -> V_67 || V_2 -> V_273 ) )
F_28 ( L_11
L_12 , V_155 , V_2 ,
V_2 -> V_67 , V_2 -> V_273 ) ;
if ( V_2 -> V_4 -> V_278 )
V_276 = F_58 ( & V_2 -> V_71 ) ;
else
V_276 = F_58 ( & V_2 -> V_15 . V_6 -> V_279 ) ;
if ( V_276 >= V_2 -> V_15 . V_6 -> V_65 )
V_277 = 1 ;
if ( V_2 -> V_67 >= V_269 ) {
V_2 -> V_67 -= V_269 ;
if ( V_277 ) {
V_2 -> V_274 += V_2 -> V_67 ;
V_2 -> V_67 = 0 ;
}
} else {
V_2 -> V_273 += V_269 - V_2 -> V_67 ;
V_2 -> V_67 = 0 ;
}
F_28 ( L_13 ,
V_155 , V_2 , V_269 , V_2 -> V_67 , V_2 -> V_273 ,
V_2 -> V_274 ) ;
}
int F_135 ( struct V_1 * V_2 ,
T_1 V_7 , T_2 V_8 )
{
int V_280 ;
V_280 = ( V_96 == V_2 -> V_15 . V_6 -> V_95 ) ? V_281 : 0 ;
if ( V_2 -> V_69 . V_94 )
V_280 |= V_282 ;
if ( V_2 -> V_69 . V_97 )
V_280 |= V_283 ;
return F_136 ( F_2 ( V_2 -> V_15 . V_6 ) ,
& V_2 -> V_15 . V_18 ,
& V_2 -> V_4 -> V_15 . V_18 ,
V_7 , V_8 , V_280 ) ;
}
int F_137 ( struct V_1 * V_2 ,
struct V_284 * V_130 ,
T_2 V_8 )
{
int V_285 = F_20 ( V_130 -> V_286 -> V_233 . V_111 ) ;
int V_287 = V_130 -> V_288 ;
T_9 * V_289 = ( T_9 * ) V_130 -> V_286 + V_285 ;
return F_138 ( & V_2 -> V_15 . V_18 , V_289 , V_287 ,
V_2 -> V_4 -> V_15 . V_18 . V_19 , V_8 ) ;
}
int F_139 ( struct V_1 * V_2 ,
const union V_145 * V_226 )
{
int V_290 = 0 ;
if ( ( V_2 -> V_15 . V_18 . V_19 == F_20 ( V_226 -> V_173 . V_174 ) ) &&
F_101 ( & V_2 -> V_15 . V_18 , V_226 ,
F_3 ( V_2 -> V_15 . V_6 ) ) )
V_290 = 1 ;
return V_290 ;
}
int F_118 ( struct V_1 * V_2 , T_2 V_8 )
{
bool V_291 = F_140 ( V_8 ) ;
int V_292 ;
if ( V_2 -> V_138 )
return 0 ;
if ( V_291 )
F_141 ( V_8 ) ;
F_54 ( & V_139 ) ;
V_292 = F_142 ( & V_140 , V_2 , 1 , 0 , V_293 ) ;
F_56 ( & V_139 ) ;
if ( V_291 )
F_143 () ;
if ( V_292 < 0 )
return V_292 ;
V_2 -> V_138 = ( V_294 ) V_292 ;
return 0 ;
}
static void F_144 ( struct V_1 * V_2 )
{
struct V_165 * V_295 ;
struct V_165 * V_296 ;
F_84 (asconf, tmp, &asoc->addip_chunk_list, list) {
F_111 ( & V_295 -> V_297 ) ;
F_145 ( V_295 ) ;
}
}
static void F_146 ( struct V_1 * V_2 )
{
struct V_165 * V_298 ;
struct V_165 * V_296 ;
F_84 (ack, tmp, &asoc->asconf_ack_list,
transmitted_list) {
F_111 ( & V_298 -> V_299 ) ;
F_145 ( V_298 ) ;
}
}
void F_147 ( const struct V_1 * V_2 )
{
struct V_165 * V_298 ;
struct V_165 * V_296 ;
F_84 (ack, tmp, &asoc->asconf_ack_list,
transmitted_list) {
if ( V_298 -> V_223 . V_300 -> V_301 ==
F_98 ( V_2 -> V_69 . V_81 ) )
break;
F_111 ( & V_298 -> V_299 ) ;
F_145 ( V_298 ) ;
}
}
struct V_165 * F_148 (
const struct V_1 * V_2 ,
T_6 V_301 )
{
struct V_165 * V_298 ;
F_63 (ack, &asoc->asconf_ack_list, transmitted_list) {
if ( F_149 ( V_298 ) )
continue;
if ( V_298 -> V_223 . V_300 -> V_301 == V_301 ) {
F_150 ( V_298 ) ;
return V_298 ;
}
}
return NULL ;
}
void F_48 ( struct V_1 * V_2 )
{
F_146 ( V_2 ) ;
F_144 ( V_2 ) ;
if ( V_2 -> V_162 )
F_145 ( V_2 -> V_162 ) ;
}
