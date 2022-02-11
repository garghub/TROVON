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
if ( V_4 -> V_107 )
memcpy ( V_2 -> V_57 . V_108 , V_4 -> V_107 ,
F_20 ( V_4 -> V_107 -> V_109 . V_110 ) ) ;
if ( V_4 -> V_111 )
memcpy ( V_2 -> V_57 . V_112 , V_4 -> V_111 ,
F_20 ( V_4 -> V_111 -> V_109 . V_110 ) ) ;
V_13 = ( T_3 * ) V_2 -> V_57 . V_113 ;
V_13 -> type = V_114 ;
V_13 -> V_110 = F_21 ( sizeof( T_3 ) + V_115 ) ;
F_22 ( V_13 + 1 , V_115 ) ;
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
goto V_116;
if ( ! F_1 ( V_2 , V_4 , V_6 , V_7 , V_8 ) )
goto V_93;
F_27 ( V_117 ) ;
F_28 ( L_1 , V_2 ) ;
return V_2 ;
V_93:
F_29 ( V_2 ) ;
V_116:
return NULL ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_15 . V_6 ;
struct V_118 * V_119 ;
struct V_120 * V_121 , * V_122 ;
int V_12 ;
if ( ! F_31 ( & V_2 -> V_98 ) ) {
F_32 ( & V_2 -> V_98 ) ;
if ( F_33 ( V_6 , V_123 ) && F_34 ( V_6 , V_124 ) )
V_6 -> V_125 -- ;
}
V_2 -> V_15 . V_126 = true ;
F_35 ( & V_2 -> V_91 ) ;
F_36 ( & V_2 -> V_92 ) ;
F_37 ( & V_2 -> V_15 . V_89 ) ;
F_38 ( & V_2 -> V_69 . V_127 ) ;
F_39 ( V_2 -> V_128 ) ;
F_40 ( & V_2 -> V_15 . V_18 ) ;
for ( V_12 = V_53 ; V_12 < V_54 ; ++ V_12 ) {
if ( F_41 ( & V_2 -> V_55 [ V_12 ] ) )
F_42 ( V_2 ) ;
}
F_29 ( V_2 -> V_69 . V_129 ) ;
F_29 ( V_2 -> V_69 . V_130 ) ;
F_29 ( V_2 -> V_69 . V_131 ) ;
F_29 ( V_2 -> V_69 . V_132 ) ;
F_43 (pos, temp, &asoc->peer.transport_addr_list) {
V_119 = F_44 ( V_121 , struct V_118 , V_133 ) ;
F_45 ( V_121 ) ;
F_46 ( V_119 ) ;
F_47 ( V_119 ) ;
}
V_2 -> V_69 . V_134 = 0 ;
F_48 ( V_2 ) ;
F_29 ( V_2 -> V_135 ) ;
F_49 ( & V_2 -> V_105 ) ;
F_50 ( V_2 -> V_136 ) ;
F_42 ( V_2 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
if ( F_52 ( ! V_2 -> V_15 . V_126 ) ) {
F_53 ( 1 , L_2 , V_2 ) ;
return;
}
F_24 ( V_2 -> V_4 ) ;
F_23 ( V_2 -> V_15 . V_6 ) ;
if ( V_2 -> V_137 != 0 ) {
F_54 ( & V_138 ) ;
F_55 ( & V_139 , V_2 -> V_137 ) ;
F_56 ( & V_138 ) ;
}
F_57 ( F_58 ( & V_2 -> V_71 ) ) ;
F_29 ( V_2 ) ;
F_59 ( V_117 ) ;
}
void F_60 ( struct V_1 * V_2 ,
struct V_118 * V_119 )
{
int V_140 = 0 ;
if ( V_2 -> V_69 . V_141 != NULL &&
V_2 -> V_69 . V_141 != V_119 )
V_140 = 1 ;
V_2 -> V_69 . V_141 = V_119 ;
memcpy ( & V_2 -> V_69 . V_142 , & V_119 -> V_143 ,
sizeof( union V_144 ) ) ;
if ( ( V_119 -> V_20 == V_145 ) ||
( V_119 -> V_20 == V_146 ) )
V_2 -> V_69 . V_147 = V_119 ;
if ( ! V_2 -> V_91 . V_148 && ! V_2 -> V_91 . V_149 )
return;
if ( V_119 -> V_150 . V_151 )
V_119 -> V_150 . V_152 = V_140 ;
V_119 -> V_150 . V_151 = V_140 ;
V_119 -> V_150 . V_153 = V_2 -> V_76 ;
}
void F_61 ( struct V_1 * V_2 ,
struct V_118 * V_69 )
{
struct V_120 * V_121 ;
struct V_118 * V_119 ;
F_28 ( L_3 ,
V_154 , V_2 , & V_69 -> V_143 . V_155 ) ;
if ( V_2 -> V_69 . V_156 == V_69 )
F_62 ( V_2 ) ;
F_45 ( & V_69 -> V_133 ) ;
F_46 ( V_69 ) ;
V_121 = V_2 -> V_69 . V_84 . V_157 ;
V_119 = F_44 ( V_121 , struct V_118 , V_133 ) ;
if ( V_2 -> V_69 . V_141 == V_69 )
F_60 ( V_2 , V_119 ) ;
if ( V_2 -> V_69 . V_147 == V_69 )
V_2 -> V_69 . V_147 = V_119 ;
if ( V_2 -> V_69 . V_156 == V_69 )
V_2 -> V_69 . V_156 = V_119 ;
if ( V_2 -> V_69 . V_158 == V_69 )
V_2 -> V_69 . V_158 = V_119 ;
if ( V_2 -> V_159 == V_69 )
V_2 -> V_159 = NULL ;
if ( V_2 -> V_160 == V_69 )
V_2 -> V_160 = NULL ;
if ( V_2 -> V_161 &&
V_2 -> V_161 -> V_119 == V_69 )
V_2 -> V_161 -> V_119 = NULL ;
if ( ! F_31 ( & V_69 -> V_162 ) ) {
struct V_118 * V_163 = V_2 -> V_69 . V_147 ;
struct V_164 * V_165 ;
F_63 (ch, &peer->transmitted,
transmitted_list) {
V_165 -> V_119 = NULL ;
V_165 -> V_166 = 0 ;
}
F_64 ( & V_69 -> V_162 ,
& V_163 -> V_162 ) ;
if ( ! F_65 ( & V_163 -> V_167 ) )
if ( ! F_66 ( & V_163 -> V_167 ,
V_168 + V_163 -> V_169 ) )
F_67 ( V_163 ) ;
}
V_2 -> V_69 . V_134 -- ;
F_47 ( V_69 ) ;
}
struct V_118 * F_68 ( struct V_1 * V_2 ,
const union V_144 * V_170 ,
const T_2 V_8 ,
const int V_171 )
{
struct V_9 * V_9 = F_2 ( V_2 -> V_15 . V_6 ) ;
struct V_118 * V_69 ;
struct V_10 * V_11 ;
unsigned short V_19 ;
V_11 = F_3 ( V_2 -> V_15 . V_6 ) ;
V_19 = F_20 ( V_170 -> V_172 . V_173 ) ;
F_28 ( L_4 , V_154 ,
V_2 , & V_170 -> V_155 , V_171 ) ;
if ( 0 == V_2 -> V_69 . V_19 )
V_2 -> V_69 . V_19 = V_19 ;
V_69 = F_69 ( V_2 , V_170 ) ;
if ( V_69 ) {
if ( V_69 -> V_20 == V_146 ) {
V_69 -> V_20 = V_145 ;
}
return V_69 ;
}
V_69 = F_70 ( V_9 , V_170 , V_8 ) ;
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
if ( V_69 -> V_42 & V_174 ) {
if ( V_2 -> V_39 )
V_69 -> V_39 = V_2 -> V_39 ;
else
V_69 -> V_39 = V_175 ;
}
if ( V_2 -> V_39 )
V_2 -> V_39 = F_73 ( int , V_69 -> V_39 , V_2 -> V_39 ) ;
else
V_2 -> V_39 = V_69 -> V_39 ;
F_28 ( L_5 , V_154 , V_2 ,
V_2 -> V_39 ) ;
V_69 -> V_176 = 0 ;
V_2 -> V_177 = F_74 ( V_2 , V_2 -> V_39 ) ;
F_75 ( & V_69 -> V_178 , V_69 , V_2 -> V_15 . V_18 . V_19 ,
V_2 -> V_69 . V_19 ) ;
V_69 -> V_179 = F_76 ( 4 * V_2 -> V_39 , F_77 ( V_180 , 2 * V_2 -> V_39 , 4380 ) ) ;
V_69 -> V_181 = V_70 ;
V_69 -> V_182 = 0 ;
V_69 -> V_183 = 0 ;
V_69 -> V_184 = 0 ;
V_69 -> V_169 = V_2 -> V_30 ;
F_78 ( V_2 , V_69 ) ;
V_69 -> V_20 = V_171 ;
F_79 ( & V_69 -> V_133 , & V_2 -> V_69 . V_84 ) ;
V_2 -> V_69 . V_134 ++ ;
F_80 ( V_69 ) ;
if ( ! V_2 -> V_69 . V_141 ) {
F_60 ( V_2 , V_69 ) ;
V_2 -> V_69 . V_156 = V_69 ;
}
if ( V_2 -> V_69 . V_147 == V_2 -> V_69 . V_156 &&
V_69 -> V_20 != V_185 ) {
V_2 -> V_69 . V_156 = V_69 ;
}
return V_69 ;
}
void F_81 ( struct V_1 * V_2 ,
const union V_144 * V_170 )
{
struct V_120 * V_121 ;
struct V_120 * V_122 ;
struct V_118 * V_119 ;
F_43 (pos, temp, &asoc->peer.transport_addr_list) {
V_119 = F_44 ( V_121 , struct V_118 , V_133 ) ;
if ( F_82 ( V_170 , & V_119 -> V_143 ) ) {
F_61 ( V_2 , V_119 ) ;
break;
}
}
}
struct V_118 * F_69 (
const struct V_1 * V_2 ,
const union V_144 * V_186 )
{
struct V_118 * V_187 ;
F_63 (t, &asoc->peer.transport_addr_list,
transports) {
if ( F_82 ( V_186 , & V_187 -> V_143 ) )
return V_187 ;
}
return NULL ;
}
void F_83 ( struct V_1 * V_2 ,
struct V_118 * V_188 )
{
struct V_118 * V_122 ;
struct V_118 * V_187 ;
F_84 (t, temp, &asoc->peer.transport_addr_list,
transports) {
if ( V_187 != V_188 )
F_61 ( V_2 , V_187 ) ;
}
}
void F_85 ( struct V_1 * V_2 ,
struct V_118 * V_119 ,
T_4 V_189 ,
T_5 error )
{
struct V_190 * V_191 ;
struct V_192 V_170 ;
int V_193 = 0 ;
bool V_194 = true ;
switch ( V_189 ) {
case V_195 :
if ( V_185 == V_119 -> V_20 &&
V_196 == error )
V_193 = V_197 ;
else
V_193 = V_198 ;
if ( V_119 -> V_20 == V_199 ) {
V_194 = false ;
V_119 -> V_179 = V_2 -> V_39 ;
}
V_119 -> V_20 = V_145 ;
break;
case V_200 :
if ( V_119 -> V_20 != V_185 )
V_119 -> V_20 = V_201 ;
else {
F_86 ( V_119 -> V_202 ) ;
V_119 -> V_202 = NULL ;
V_194 = false ;
}
V_193 = V_203 ;
break;
case V_204 :
V_119 -> V_20 = V_199 ;
V_194 = false ;
break;
default:
return;
}
if ( V_194 ) {
memset ( & V_170 , 0 , sizeof( struct V_192 ) ) ;
memcpy ( & V_170 , & V_119 -> V_143 ,
V_119 -> V_205 -> V_206 ) ;
V_191 = F_87 ( V_2 , & V_170 ,
0 , V_193 , error , V_207 ) ;
if ( V_191 )
F_88 ( & V_2 -> V_92 , V_191 ) ;
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
V_180 F_93 ( struct V_1 * V_2 )
{
V_180 V_208 = V_2 -> V_76 ;
V_2 -> V_76 ++ ;
V_2 -> V_209 ++ ;
return V_208 ;
}
int F_82 ( const union V_144 * V_210 ,
const union V_144 * V_211 )
{
struct V_212 * V_213 ;
V_213 = F_94 ( V_210 -> V_155 . V_214 ) ;
if ( F_52 ( ! V_213 ) )
return 0 ;
return V_213 -> V_215 ( V_210 , V_211 ) ;
}
struct V_164 * F_95 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_216 )
return NULL ;
return F_96 ( V_2 , V_2 -> V_217 ) ;
}
struct V_118 * F_97 ( struct V_1 * V_2 ,
V_180 V_218 )
{
struct V_118 * V_163 ;
struct V_118 * V_219 ;
struct V_118 * V_119 ;
struct V_164 * V_220 ;
T_6 V_221 = F_98 ( V_218 ) ;
V_219 = NULL ;
V_163 = V_2 -> V_69 . V_147 ;
F_63 (chunk, &active->transmitted,
transmitted_list) {
if ( V_221 == V_220 -> V_222 . V_223 -> V_218 ) {
V_219 = V_163 ;
goto V_224;
}
}
F_63 (transport, &asoc->peer.transport_addr_list,
transports) {
if ( V_119 == V_163 )
continue;
F_63 (chunk, &transport->transmitted,
transmitted_list) {
if ( V_221 == V_220 -> V_222 . V_223 -> V_218 ) {
V_219 = V_119 ;
goto V_224;
}
}
}
V_224:
return V_219 ;
}
struct V_118 * F_99 ( struct V_1 * V_2 ,
struct V_9 * V_9 ,
const union V_144 * V_225 ,
const union V_144 * V_226 )
{
struct V_118 * V_119 ;
if ( ( F_21 ( V_2 -> V_15 . V_18 . V_19 ) == V_225 -> V_172 . V_173 ) &&
( F_21 ( V_2 -> V_69 . V_19 ) == V_226 -> V_172 . V_173 ) &&
F_100 ( F_2 ( V_2 -> V_15 . V_6 ) , V_9 ) ) {
V_119 = F_69 ( V_2 , V_226 ) ;
if ( ! V_119 )
goto V_224;
if ( F_101 ( & V_2 -> V_15 . V_18 , V_225 ,
F_3 ( V_2 -> V_15 . V_6 ) ) )
goto V_224;
}
V_119 = NULL ;
V_224:
return V_119 ;
}
static void V_90 ( struct V_227 * V_228 )
{
struct V_1 * V_2 =
F_102 ( V_228 , struct V_1 ,
V_15 . V_89 . V_229 ) ;
struct V_9 * V_9 = F_2 ( V_2 -> V_15 . V_6 ) ;
struct V_3 * V_4 ;
struct V_164 * V_220 ;
struct V_230 * V_89 ;
int V_20 ;
T_7 V_231 ;
int error = 0 ;
V_4 = V_2 -> V_4 ;
V_89 = & V_2 -> V_15 . V_89 ;
F_90 ( V_2 ) ;
while ( NULL != ( V_220 = F_103 ( V_89 ) ) ) {
V_20 = V_2 -> V_20 ;
V_231 = F_104 ( V_220 -> V_232 -> type ) ;
if ( F_105 ( V_231 . V_220 , V_2 ) && ! V_220 -> V_233 )
continue;
if ( F_106 ( V_220 ) )
V_2 -> V_69 . V_158 = V_220 -> V_119 ;
else {
F_107 ( V_9 , V_234 ) ;
V_2 -> V_235 . V_236 ++ ;
if ( V_220 -> V_232 -> type == V_237 )
V_2 -> V_235 . V_238 ++ ;
}
if ( V_220 -> V_119 )
V_220 -> V_119 -> V_239 = F_108 () ;
error = F_109 ( V_9 , V_240 , V_231 ,
V_20 , V_4 , V_2 , V_220 , V_207 ) ;
if ( V_2 -> V_15 . V_126 )
break;
if ( error && V_220 )
V_220 -> V_241 = 1 ;
}
F_42 ( V_2 ) ;
}
void F_110 ( struct V_1 * V_117 , struct V_5 * V_242 )
{
struct V_10 * V_243 = F_3 ( V_242 ) ;
struct V_5 * V_244 = V_117 -> V_15 . V_6 ;
F_111 ( & V_117 -> V_98 ) ;
if ( F_33 ( V_244 , V_123 ) )
V_244 -> V_125 -- ;
F_24 ( V_117 -> V_4 ) ;
F_23 ( V_117 -> V_15 . V_6 ) ;
V_117 -> V_4 = V_243 -> V_4 ;
F_4 ( V_117 -> V_4 ) ;
V_117 -> V_15 . V_6 = V_242 ;
F_5 ( V_117 -> V_15 . V_6 ) ;
F_112 ( V_243 -> V_4 , V_117 ) ;
}
void F_113 ( struct V_1 * V_2 ,
struct V_1 * V_245 )
{
struct V_118 * V_246 ;
struct V_120 * V_121 , * V_122 ;
V_2 -> V_57 = V_245 -> V_57 ;
V_2 -> V_69 . V_67 = V_245 -> V_69 . V_67 ;
V_2 -> V_69 . V_85 = V_245 -> V_69 . V_85 ;
V_2 -> V_69 . V_247 = V_245 -> V_69 . V_247 ;
V_2 -> V_69 . V_12 = V_245 -> V_69 . V_12 ;
F_114 ( & V_2 -> V_69 . V_127 , V_248 ,
V_2 -> V_69 . V_12 . V_75 , V_207 ) ;
F_43 (pos, temp, &asoc->peer.transport_addr_list) {
V_246 = F_44 ( V_121 , struct V_118 , V_133 ) ;
if ( ! F_69 ( V_245 , & V_246 -> V_143 ) ) {
F_61 ( V_2 , V_246 ) ;
continue;
}
if ( V_2 -> V_20 >= V_249 )
F_115 ( V_246 ) ;
}
if ( V_2 -> V_20 >= V_249 ) {
V_2 -> V_76 = V_245 -> V_76 ;
V_2 -> V_77 = V_245 -> V_77 ;
V_2 -> V_78 = V_245 -> V_78 ;
F_116 ( V_2 -> V_128 ) ;
F_117 ( & V_2 -> V_92 ) ;
V_2 -> V_250 = 0 ;
} else {
F_63 (trans, &new->peer.transport_addr_list,
transports) {
if ( ! F_69 ( V_2 , & V_246 -> V_143 ) )
F_68 ( V_2 , & V_246 -> V_143 ,
V_207 , V_246 -> V_20 ) ;
}
V_2 -> V_77 = V_2 -> V_76 - 1 ;
V_2 -> V_78 = V_2 -> V_77 ;
if ( ! V_2 -> V_128 ) {
V_2 -> V_128 = V_245 -> V_128 ;
V_245 -> V_128 = NULL ;
}
if ( ! V_2 -> V_137 ) {
F_118 ( V_2 , V_207 ) ;
}
}
F_29 ( V_2 -> V_69 . V_130 ) ;
V_2 -> V_69 . V_130 = V_245 -> V_69 . V_130 ;
V_245 -> V_69 . V_130 = NULL ;
F_29 ( V_2 -> V_69 . V_131 ) ;
V_2 -> V_69 . V_131 = V_245 -> V_69 . V_131 ;
V_245 -> V_69 . V_131 = NULL ;
F_29 ( V_2 -> V_69 . V_132 ) ;
V_2 -> V_69 . V_132 = V_245 -> V_69 . V_132 ;
V_245 -> V_69 . V_132 = NULL ;
F_119 ( V_2 , V_207 ) ;
}
static T_8 F_120 ( const struct V_118 * V_246 )
{
switch ( V_246 -> V_20 ) {
case V_145 :
return 3 ;
case V_146 :
return 2 ;
case V_199 :
return 1 ;
default:
return 0 ;
}
}
static struct V_118 * F_121 ( struct V_118 * V_251 ,
struct V_118 * V_252 )
{
if ( V_251 -> V_253 > V_252 -> V_253 ) {
return V_252 ;
} else if ( V_251 -> V_253 == V_252 -> V_253 &&
F_122 ( V_252 -> V_239 ,
V_251 -> V_239 ) ) {
return V_252 ;
} else {
return V_251 ;
}
}
static struct V_118 * F_123 ( struct V_118 * V_254 ,
struct V_118 * V_255 )
{
T_8 V_256 , V_257 ;
if ( V_255 == NULL || V_254 == V_255 )
return V_254 ;
V_256 = F_120 ( V_254 ) ;
V_257 = F_120 ( V_255 ) ;
if ( V_256 > V_257 )
return V_254 ;
else if ( V_256 == V_257 )
return F_121 ( V_255 , V_254 ) ;
else
return V_255 ;
}
void F_62 ( struct V_1 * V_2 )
{
struct V_118 * V_246 = V_2 -> V_69 . V_156 ;
struct V_118 * V_258 = NULL ;
if ( V_2 -> V_69 . V_134 == 1 )
return;
if ( V_2 -> V_69 . V_147 == V_2 -> V_69 . V_156 &&
V_2 -> V_69 . V_147 -> V_20 == V_145 )
return;
for ( V_246 = F_124 ( V_246 , V_133 ) ; 1 ;
V_246 = F_124 ( V_246 , V_133 ) ) {
if ( & V_246 -> V_133 == & V_2 -> V_69 . V_84 )
continue;
if ( V_246 -> V_20 == V_185 )
continue;
V_258 = F_123 ( V_246 , V_258 ) ;
if ( V_258 -> V_20 == V_145 )
break;
if ( V_246 == V_2 -> V_69 . V_156 )
break;
}
V_2 -> V_69 . V_156 = V_258 ;
F_28 ( L_6 ,
V_154 , V_2 , & V_2 -> V_69 . V_156 -> V_143 . V_155 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_118 * V_246 , * V_259 = NULL , * V_260 = NULL ;
struct V_118 * V_261 = NULL ;
F_63 (trans, &asoc->peer.transport_addr_list,
transports) {
if ( V_246 -> V_20 == V_201 ||
V_246 -> V_20 == V_185 )
continue;
if ( V_246 -> V_20 == V_199 ) {
V_261 = F_123 ( V_246 , V_261 ) ;
continue;
}
if ( V_259 == NULL ||
F_122 ( V_246 -> V_239 ,
V_259 -> V_239 ) ) {
V_260 = V_259 ;
V_259 = V_246 ;
} else if ( V_260 == NULL ||
F_122 ( V_246 -> V_239 ,
V_260 -> V_239 ) ) {
V_260 = V_246 ;
}
}
if ( ( V_2 -> V_69 . V_141 -> V_20 == V_145 ||
V_2 -> V_69 . V_141 -> V_20 == V_146 ) &&
V_2 -> V_69 . V_141 != V_259 ) {
V_260 = V_259 ;
V_259 = V_2 -> V_69 . V_141 ;
}
if ( V_260 == NULL )
V_260 = V_259 ;
if ( V_259 == NULL ) {
V_259 = F_123 ( V_2 -> V_69 . V_147 , V_261 ) ;
V_260 = V_259 ;
}
V_2 -> V_69 . V_147 = V_259 ;
V_2 -> V_69 . V_156 = V_260 ;
}
struct V_118 *
F_125 ( struct V_1 * V_2 ,
struct V_118 * V_262 )
{
if ( V_262 == NULL ) {
return V_2 -> V_69 . V_147 ;
} else {
if ( V_262 == V_2 -> V_69 . V_156 )
F_62 ( V_2 ) ;
return V_2 -> V_69 . V_156 ;
}
}
void F_126 ( struct V_5 * V_6 , struct V_1 * V_2 )
{
struct V_118 * V_187 ;
V_180 V_263 = 0 ;
if ( ! V_2 )
return;
F_63 (t, &asoc->peer.transport_addr_list,
transports) {
if ( V_187 -> V_176 && V_187 -> V_202 ) {
F_127 ( V_6 , V_187 ,
F_128 ( F_129 ( V_187 -> V_202 ) ) ) ;
V_187 -> V_176 = 0 ;
}
if ( ! V_263 || ( V_187 -> V_39 < V_263 ) )
V_263 = V_187 -> V_39 ;
}
if ( V_263 ) {
V_2 -> V_39 = V_263 ;
V_2 -> V_177 = F_74 ( V_2 , V_263 ) ;
}
F_28 ( L_7 , V_154 , V_2 ,
V_2 -> V_39 , V_2 -> V_177 ) ;
}
static inline bool F_130 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_2 ( V_2 -> V_15 . V_6 ) ;
switch ( V_2 -> V_20 ) {
case V_249 :
case V_264 :
case V_265 :
case V_266 :
if ( ( V_2 -> V_67 > V_2 -> V_68 ) &&
( ( V_2 -> V_67 - V_2 -> V_68 ) >= F_77 ( V_180 ,
( V_2 -> V_15 . V_6 -> V_65 >> V_9 -> V_29 . V_267 ) ,
V_2 -> V_39 ) ) )
return true ;
break;
default:
break;
}
return false ;
}
void F_131 ( struct V_1 * V_2 , unsigned int V_268 )
{
struct V_164 * V_269 ;
struct V_270 * V_271 ;
if ( V_2 -> V_272 ) {
if ( V_2 -> V_272 >= V_268 ) {
V_2 -> V_272 -= V_268 ;
} else {
V_2 -> V_67 += ( V_268 - V_2 -> V_272 ) ;
V_2 -> V_272 = 0 ;
}
} else {
V_2 -> V_67 += V_268 ;
}
if ( V_2 -> V_273 && V_2 -> V_67 >= V_2 -> V_273 ) {
int V_274 = F_76 ( V_2 -> V_39 , V_2 -> V_273 ) ;
V_2 -> V_67 += V_274 ;
V_2 -> V_273 -= V_274 ;
}
F_28 ( L_8 ,
V_154 , V_2 , V_268 , V_2 -> V_67 , V_2 -> V_272 ,
V_2 -> V_68 ) ;
if ( F_130 ( V_2 ) ) {
V_2 -> V_68 = V_2 -> V_67 ;
F_28 ( L_9
L_10 , V_154 , V_2 , V_2 -> V_67 ,
V_2 -> V_68 ) ;
V_269 = F_132 ( V_2 ) ;
if ( ! V_269 )
return;
V_2 -> V_69 . V_85 = 0 ;
F_133 ( & V_2 -> V_91 , V_269 , V_207 ) ;
V_271 = & V_2 -> V_55 [ V_49 ] ;
if ( F_41 ( V_271 ) )
F_42 ( V_2 ) ;
}
}
void F_134 ( struct V_1 * V_2 , unsigned int V_268 )
{
int V_275 ;
int V_276 = 0 ;
if ( F_52 ( ! V_2 -> V_67 || V_2 -> V_272 ) )
F_28 ( L_11
L_12 , V_154 , V_2 ,
V_2 -> V_67 , V_2 -> V_272 ) ;
if ( V_2 -> V_4 -> V_277 )
V_275 = F_58 ( & V_2 -> V_71 ) ;
else
V_275 = F_58 ( & V_2 -> V_15 . V_6 -> V_278 ) ;
if ( V_275 >= V_2 -> V_15 . V_6 -> V_65 )
V_276 = 1 ;
if ( V_2 -> V_67 >= V_268 ) {
V_2 -> V_67 -= V_268 ;
if ( V_276 ) {
V_2 -> V_273 += V_2 -> V_67 ;
V_2 -> V_67 = 0 ;
}
} else {
V_2 -> V_272 = V_268 - V_2 -> V_67 ;
V_2 -> V_67 = 0 ;
}
F_28 ( L_13 ,
V_154 , V_2 , V_268 , V_2 -> V_67 , V_2 -> V_272 ,
V_2 -> V_273 ) ;
}
int F_135 ( struct V_1 * V_2 ,
T_1 V_7 , T_2 V_8 )
{
int V_279 ;
V_279 = ( V_96 == V_2 -> V_15 . V_6 -> V_95 ) ? V_280 : 0 ;
if ( V_2 -> V_69 . V_94 )
V_279 |= V_281 ;
if ( V_2 -> V_69 . V_97 )
V_279 |= V_282 ;
return F_136 ( F_2 ( V_2 -> V_15 . V_6 ) ,
& V_2 -> V_15 . V_18 ,
& V_2 -> V_4 -> V_15 . V_18 ,
V_7 , V_8 , V_279 ) ;
}
int F_137 ( struct V_1 * V_2 ,
struct V_283 * V_129 ,
T_2 V_8 )
{
int V_284 = F_20 ( V_129 -> V_285 -> V_232 . V_110 ) ;
int V_286 = V_129 -> V_287 ;
T_9 * V_288 = ( T_9 * ) V_129 -> V_285 + V_284 ;
return F_138 ( & V_2 -> V_15 . V_18 , V_288 , V_286 ,
V_2 -> V_4 -> V_15 . V_18 . V_19 , V_8 ) ;
}
int F_139 ( struct V_1 * V_2 ,
const union V_144 * V_225 )
{
int V_289 = 0 ;
if ( ( V_2 -> V_15 . V_18 . V_19 == F_20 ( V_225 -> V_172 . V_173 ) ) &&
F_101 ( & V_2 -> V_15 . V_18 , V_225 ,
F_3 ( V_2 -> V_15 . V_6 ) ) )
V_289 = 1 ;
return V_289 ;
}
int F_118 ( struct V_1 * V_2 , T_2 V_8 )
{
bool V_290 = F_140 ( V_8 ) ;
int V_291 ;
if ( V_2 -> V_137 )
return 0 ;
if ( V_290 )
F_141 ( V_8 ) ;
F_54 ( & V_138 ) ;
V_291 = F_142 ( & V_139 , V_2 , 1 , 0 , V_292 ) ;
F_56 ( & V_138 ) ;
if ( V_290 )
F_143 () ;
if ( V_291 < 0 )
return V_291 ;
V_2 -> V_137 = ( V_293 ) V_291 ;
return 0 ;
}
static void F_144 ( struct V_1 * V_2 )
{
struct V_164 * V_294 ;
struct V_164 * V_295 ;
F_84 (asconf, tmp, &asoc->addip_chunk_list, list) {
F_111 ( & V_294 -> V_296 ) ;
F_145 ( V_294 ) ;
}
}
static void F_146 ( struct V_1 * V_2 )
{
struct V_164 * V_297 ;
struct V_164 * V_295 ;
F_84 (ack, tmp, &asoc->asconf_ack_list,
transmitted_list) {
F_111 ( & V_297 -> V_298 ) ;
F_145 ( V_297 ) ;
}
}
void F_147 ( const struct V_1 * V_2 )
{
struct V_164 * V_297 ;
struct V_164 * V_295 ;
F_84 (ack, tmp, &asoc->asconf_ack_list,
transmitted_list) {
if ( V_297 -> V_222 . V_299 -> V_300 ==
F_98 ( V_2 -> V_69 . V_81 ) )
break;
F_111 ( & V_297 -> V_298 ) ;
F_145 ( V_297 ) ;
}
}
struct V_164 * F_148 (
const struct V_1 * V_2 ,
T_6 V_300 )
{
struct V_164 * V_297 ;
F_63 (ack, &asoc->asconf_ack_list, transmitted_list) {
if ( F_149 ( V_297 ) )
continue;
if ( V_297 -> V_222 . V_299 -> V_300 == V_300 ) {
F_150 ( V_297 ) ;
return V_297 ;
}
}
return NULL ;
}
void F_48 ( struct V_1 * V_2 )
{
F_146 ( V_2 ) ;
F_144 ( V_2 ) ;
if ( V_2 -> V_161 )
F_145 ( V_2 -> V_161 ) ;
}
