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
}
V_2 -> V_69 . V_134 = 0 ;
F_47 ( V_2 ) ;
F_29 ( V_2 -> V_135 ) ;
F_48 ( & V_2 -> V_105 ) ;
F_49 ( V_2 -> V_136 ) ;
F_42 ( V_2 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
if ( F_51 ( ! V_2 -> V_15 . V_126 ) ) {
F_52 ( 1 , L_2 , V_2 ) ;
return;
}
F_24 ( V_2 -> V_4 ) ;
F_23 ( V_2 -> V_15 . V_6 ) ;
if ( V_2 -> V_137 != 0 ) {
F_53 ( & V_138 ) ;
F_54 ( & V_139 , V_2 -> V_137 ) ;
F_55 ( & V_138 ) ;
}
F_56 ( F_57 ( & V_2 -> V_71 ) ) ;
F_29 ( V_2 ) ;
F_58 ( V_117 ) ;
}
void F_59 ( struct V_1 * V_2 ,
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
void F_60 ( struct V_1 * V_2 ,
struct V_118 * V_69 )
{
struct V_120 * V_121 ;
struct V_118 * V_119 ;
F_28 ( L_3 ,
V_154 , V_2 , & V_69 -> V_143 . V_155 ) ;
if ( V_2 -> V_69 . V_156 == V_69 )
F_61 ( V_2 ) ;
F_45 ( & V_69 -> V_133 ) ;
V_121 = V_2 -> V_69 . V_84 . V_157 ;
V_119 = F_44 ( V_121 , struct V_118 , V_133 ) ;
if ( V_2 -> V_69 . V_141 == V_69 )
F_59 ( V_2 , V_119 ) ;
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
F_62 (ch, &peer->transmitted,
transmitted_list) {
V_165 -> V_119 = NULL ;
V_165 -> V_166 = 0 ;
}
F_63 ( & V_69 -> V_162 ,
& V_163 -> V_162 ) ;
if ( ! F_64 ( & V_163 -> V_167 ) )
if ( ! F_65 ( & V_163 -> V_167 ,
V_168 + V_163 -> V_169 ) )
F_66 ( V_163 ) ;
}
V_2 -> V_69 . V_134 -- ;
F_46 ( V_69 ) ;
}
struct V_118 * F_67 ( struct V_1 * V_2 ,
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
V_69 = F_68 ( V_2 , V_170 ) ;
if ( V_69 ) {
if ( V_69 -> V_20 == V_146 ) {
V_69 -> V_20 = V_145 ;
}
return V_69 ;
}
V_69 = F_69 ( V_9 , V_170 , V_8 ) ;
if ( ! V_69 )
return NULL ;
F_70 ( V_69 , V_2 ) ;
V_69 -> V_37 = V_2 -> V_37 ;
V_69 -> V_38 = V_2 -> V_38 ;
V_69 -> V_28 = V_2 -> V_28 ;
V_69 -> V_40 = V_2 -> V_40 ;
V_69 -> V_41 = V_2 -> V_41 ;
V_69 -> V_42 = V_2 -> V_42 ;
F_71 ( V_69 , NULL , V_11 ) ;
if ( V_69 -> V_42 & V_174 ) {
if ( V_2 -> V_39 )
V_69 -> V_39 = V_2 -> V_39 ;
else
V_69 -> V_39 = V_175 ;
}
if ( V_2 -> V_39 )
V_2 -> V_39 = F_72 ( int , V_69 -> V_39 , V_2 -> V_39 ) ;
else
V_2 -> V_39 = V_69 -> V_39 ;
F_28 ( L_5 , V_154 , V_2 ,
V_2 -> V_39 ) ;
V_69 -> V_176 = 0 ;
V_2 -> V_177 = F_73 ( V_2 , V_2 -> V_39 ) ;
F_74 ( & V_69 -> V_178 , V_69 , V_2 -> V_15 . V_18 . V_19 ,
V_2 -> V_69 . V_19 ) ;
V_69 -> V_179 = F_75 ( 4 * V_2 -> V_39 , F_76 ( V_180 , 2 * V_2 -> V_39 , 4380 ) ) ;
V_69 -> V_181 = V_70 ;
V_69 -> V_182 = 0 ;
V_69 -> V_183 = 0 ;
V_69 -> V_184 = 0 ;
V_69 -> V_169 = V_2 -> V_30 ;
F_77 ( V_2 , V_69 ) ;
V_69 -> V_20 = V_171 ;
F_78 ( & V_69 -> V_133 , & V_2 -> V_69 . V_84 ) ;
V_2 -> V_69 . V_134 ++ ;
if ( ! V_2 -> V_69 . V_141 ) {
F_59 ( V_2 , V_69 ) ;
V_2 -> V_69 . V_156 = V_69 ;
}
if ( V_2 -> V_69 . V_147 == V_2 -> V_69 . V_156 &&
V_69 -> V_20 != V_185 ) {
V_2 -> V_69 . V_156 = V_69 ;
}
return V_69 ;
}
void F_79 ( struct V_1 * V_2 ,
const union V_144 * V_170 )
{
struct V_120 * V_121 ;
struct V_120 * V_122 ;
struct V_118 * V_119 ;
F_43 (pos, temp, &asoc->peer.transport_addr_list) {
V_119 = F_44 ( V_121 , struct V_118 , V_133 ) ;
if ( F_80 ( V_170 , & V_119 -> V_143 ) ) {
F_60 ( V_2 , V_119 ) ;
break;
}
}
}
struct V_118 * F_68 (
const struct V_1 * V_2 ,
const union V_144 * V_186 )
{
struct V_118 * V_187 ;
F_62 (t, &asoc->peer.transport_addr_list,
transports) {
if ( F_80 ( V_186 , & V_187 -> V_143 ) )
return V_187 ;
}
return NULL ;
}
void F_81 ( struct V_1 * V_2 ,
struct V_118 * V_188 )
{
struct V_118 * V_122 ;
struct V_118 * V_187 ;
F_82 (t, temp, &asoc->peer.transport_addr_list,
transports) {
if ( V_187 != V_188 )
F_60 ( V_2 , V_187 ) ;
}
}
void F_83 ( struct V_1 * V_2 ,
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
F_84 ( V_119 -> V_202 ) ;
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
V_191 = F_85 ( V_2 , & V_170 ,
0 , V_193 , error , V_207 ) ;
if ( V_191 )
F_86 ( & V_2 -> V_92 , V_191 ) ;
}
F_87 ( V_2 ) ;
}
void F_88 ( struct V_1 * V_2 )
{
F_89 ( & V_2 -> V_15 . V_17 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
if ( F_90 ( & V_2 -> V_15 . V_17 ) )
F_50 ( V_2 ) ;
}
V_180 F_91 ( struct V_1 * V_2 )
{
V_180 V_208 = V_2 -> V_76 ;
V_2 -> V_76 ++ ;
V_2 -> V_209 ++ ;
return V_208 ;
}
int F_80 ( const union V_144 * V_210 ,
const union V_144 * V_211 )
{
struct V_212 * V_213 ;
V_213 = F_92 ( V_210 -> V_155 . V_214 ) ;
if ( F_51 ( ! V_213 ) )
return 0 ;
return V_213 -> V_215 ( V_210 , V_211 ) ;
}
struct V_164 * F_93 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_216 )
return NULL ;
return F_94 ( V_2 , V_2 -> V_217 ) ;
}
struct V_118 * F_95 ( struct V_1 * V_2 ,
V_180 V_218 )
{
struct V_118 * V_163 ;
struct V_118 * V_219 ;
struct V_118 * V_119 ;
struct V_164 * V_220 ;
T_6 V_221 = F_96 ( V_218 ) ;
V_219 = NULL ;
V_163 = V_2 -> V_69 . V_147 ;
F_62 (chunk, &active->transmitted,
transmitted_list) {
if ( V_221 == V_220 -> V_222 . V_223 -> V_218 ) {
V_219 = V_163 ;
goto V_224;
}
}
F_62 (transport, &asoc->peer.transport_addr_list,
transports) {
if ( V_119 == V_163 )
continue;
F_62 (chunk, &transport->transmitted,
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
struct V_118 * F_97 ( struct V_1 * V_2 ,
struct V_9 * V_9 ,
const union V_144 * V_225 ,
const union V_144 * V_226 )
{
struct V_118 * V_119 ;
if ( ( F_21 ( V_2 -> V_15 . V_18 . V_19 ) == V_225 -> V_172 . V_173 ) &&
( F_21 ( V_2 -> V_69 . V_19 ) == V_226 -> V_172 . V_173 ) &&
F_98 ( F_2 ( V_2 -> V_15 . V_6 ) , V_9 ) ) {
V_119 = F_68 ( V_2 , V_226 ) ;
if ( ! V_119 )
goto V_224;
if ( F_99 ( & V_2 -> V_15 . V_18 , V_225 ,
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
F_100 ( V_228 , struct V_1 ,
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
F_88 ( V_2 ) ;
while ( NULL != ( V_220 = F_101 ( V_89 ) ) ) {
V_20 = V_2 -> V_20 ;
V_231 = F_102 ( V_220 -> V_232 -> type ) ;
if ( F_103 ( V_231 . V_220 , V_2 ) && ! V_220 -> V_233 )
continue;
if ( F_104 ( V_220 ) )
V_2 -> V_69 . V_158 = V_220 -> V_119 ;
else {
F_105 ( V_9 , V_234 ) ;
V_2 -> V_235 . V_236 ++ ;
if ( V_220 -> V_232 -> type == V_237 )
V_2 -> V_235 . V_238 ++ ;
}
if ( V_220 -> V_119 )
V_220 -> V_119 -> V_239 = F_106 () ;
error = F_107 ( V_9 , V_240 , V_231 ,
V_20 , V_4 , V_2 , V_220 , V_207 ) ;
if ( V_2 -> V_15 . V_126 )
break;
if ( error && V_220 )
V_220 -> V_241 = 1 ;
}
F_42 ( V_2 ) ;
}
void F_108 ( struct V_1 * V_117 , struct V_5 * V_242 )
{
struct V_10 * V_243 = F_3 ( V_242 ) ;
struct V_5 * V_244 = V_117 -> V_15 . V_6 ;
F_109 ( & V_117 -> V_98 ) ;
if ( F_33 ( V_244 , V_123 ) )
V_244 -> V_125 -- ;
F_24 ( V_117 -> V_4 ) ;
F_23 ( V_117 -> V_15 . V_6 ) ;
V_117 -> V_4 = V_243 -> V_4 ;
F_4 ( V_117 -> V_4 ) ;
V_117 -> V_15 . V_6 = V_242 ;
F_5 ( V_117 -> V_15 . V_6 ) ;
F_110 ( V_243 -> V_4 , V_117 ) ;
}
void F_111 ( struct V_1 * V_2 ,
struct V_1 * V_245 )
{
struct V_118 * V_246 ;
struct V_120 * V_121 , * V_122 ;
V_2 -> V_57 = V_245 -> V_57 ;
V_2 -> V_69 . V_67 = V_245 -> V_69 . V_67 ;
V_2 -> V_69 . V_85 = V_245 -> V_69 . V_85 ;
V_2 -> V_69 . V_247 = V_245 -> V_69 . V_247 ;
V_2 -> V_69 . V_12 = V_245 -> V_69 . V_12 ;
F_112 ( & V_2 -> V_69 . V_127 , V_248 ,
V_2 -> V_69 . V_12 . V_75 , V_207 ) ;
F_43 (pos, temp, &asoc->peer.transport_addr_list) {
V_246 = F_44 ( V_121 , struct V_118 , V_133 ) ;
if ( ! F_68 ( V_245 , & V_246 -> V_143 ) ) {
F_60 ( V_2 , V_246 ) ;
continue;
}
if ( V_2 -> V_20 >= V_249 )
F_113 ( V_246 ) ;
}
if ( V_2 -> V_20 >= V_249 ) {
V_2 -> V_76 = V_245 -> V_76 ;
V_2 -> V_77 = V_245 -> V_77 ;
V_2 -> V_78 = V_245 -> V_78 ;
F_114 ( V_2 -> V_128 ) ;
F_115 ( & V_2 -> V_92 ) ;
V_2 -> V_250 = 0 ;
} else {
F_62 (trans, &new->peer.transport_addr_list,
transports) {
if ( ! F_68 ( V_2 , & V_246 -> V_143 ) )
F_67 ( V_2 , & V_246 -> V_143 ,
V_207 , V_246 -> V_20 ) ;
}
V_2 -> V_77 = V_2 -> V_76 - 1 ;
V_2 -> V_78 = V_2 -> V_77 ;
if ( ! V_2 -> V_128 ) {
V_2 -> V_128 = V_245 -> V_128 ;
V_245 -> V_128 = NULL ;
}
if ( ! V_2 -> V_137 ) {
F_116 ( V_2 , V_207 ) ;
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
F_117 ( V_2 , V_207 ) ;
}
static T_8 F_118 ( const struct V_118 * V_246 )
{
return V_251 [ V_246 -> V_20 ] ;
}
static struct V_118 * F_119 ( struct V_118 * V_252 ,
struct V_118 * V_253 )
{
if ( V_252 -> V_254 > V_253 -> V_254 ) {
return V_253 ;
} else if ( V_252 -> V_254 == V_253 -> V_254 &&
F_120 ( V_253 -> V_239 ,
V_252 -> V_239 ) ) {
return V_253 ;
} else {
return V_252 ;
}
}
static struct V_118 * F_121 ( struct V_118 * V_255 ,
struct V_118 * V_256 )
{
T_8 V_257 , V_258 ;
if ( V_256 == NULL || V_255 == V_256 )
return V_255 ;
V_257 = F_118 ( V_255 ) ;
V_258 = F_118 ( V_256 ) ;
if ( V_257 > V_258 )
return V_255 ;
else if ( V_257 == V_258 )
return F_119 ( V_255 , V_256 ) ;
else
return V_256 ;
}
void F_61 ( struct V_1 * V_2 )
{
struct V_118 * V_246 = V_2 -> V_69 . V_156 ;
struct V_118 * V_259 = NULL ;
if ( V_2 -> V_69 . V_134 == 1 )
return;
if ( V_2 -> V_69 . V_147 == V_2 -> V_69 . V_156 &&
V_2 -> V_69 . V_147 -> V_20 == V_145 )
return;
for ( V_246 = F_122 ( V_246 , V_133 ) ; 1 ;
V_246 = F_122 ( V_246 , V_133 ) ) {
if ( & V_246 -> V_133 == & V_2 -> V_69 . V_84 )
continue;
if ( V_246 -> V_20 == V_185 )
continue;
V_259 = F_121 ( V_246 , V_259 ) ;
if ( V_259 -> V_20 == V_145 )
break;
if ( V_246 == V_2 -> V_69 . V_156 )
break;
}
V_2 -> V_69 . V_156 = V_259 ;
F_28 ( L_6 ,
V_154 , V_2 , & V_2 -> V_69 . V_156 -> V_143 . V_155 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_118 * V_246 , * V_260 = NULL , * V_261 = NULL ;
struct V_118 * V_262 = NULL ;
F_62 (trans, &asoc->peer.transport_addr_list,
transports) {
if ( V_246 -> V_20 == V_201 ||
V_246 -> V_20 == V_185 )
continue;
if ( V_246 -> V_20 == V_199 ) {
V_262 = F_121 ( V_246 , V_262 ) ;
continue;
}
if ( V_260 == NULL ||
F_120 ( V_246 -> V_239 ,
V_260 -> V_239 ) ) {
V_261 = V_260 ;
V_260 = V_246 ;
} else if ( V_261 == NULL ||
F_120 ( V_246 -> V_239 ,
V_261 -> V_239 ) ) {
V_261 = V_246 ;
}
}
if ( ( V_2 -> V_69 . V_141 -> V_20 == V_145 ||
V_2 -> V_69 . V_141 -> V_20 == V_146 ) &&
V_2 -> V_69 . V_141 != V_260 ) {
V_261 = V_260 ;
V_260 = V_2 -> V_69 . V_141 ;
}
if ( V_261 == NULL )
V_261 = V_260 ;
if ( V_260 == NULL ) {
V_260 = F_121 ( V_2 -> V_69 . V_147 , V_262 ) ;
V_261 = V_260 ;
}
V_2 -> V_69 . V_147 = V_260 ;
V_2 -> V_69 . V_156 = V_261 ;
}
struct V_118 *
F_123 ( struct V_1 * V_2 ,
struct V_118 * V_263 )
{
if ( V_263 == NULL ) {
return V_2 -> V_69 . V_147 ;
} else {
if ( V_263 == V_2 -> V_69 . V_156 )
F_61 ( V_2 ) ;
return V_2 -> V_69 . V_156 ;
}
}
void F_124 ( struct V_5 * V_6 , struct V_1 * V_2 )
{
struct V_118 * V_187 ;
V_180 V_264 = 0 ;
if ( ! V_2 )
return;
F_62 (t, &asoc->peer.transport_addr_list,
transports) {
if ( V_187 -> V_176 && V_187 -> V_202 ) {
F_125 ( V_6 , V_187 , F_126 ( V_187 -> V_202 ) ) ;
V_187 -> V_176 = 0 ;
}
if ( ! V_264 || ( V_187 -> V_39 < V_264 ) )
V_264 = V_187 -> V_39 ;
}
if ( V_264 ) {
V_2 -> V_39 = V_264 ;
V_2 -> V_177 = F_73 ( V_2 , V_264 ) ;
}
F_28 ( L_7 , V_154 , V_2 ,
V_2 -> V_39 , V_2 -> V_177 ) ;
}
static inline bool F_127 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_2 ( V_2 -> V_15 . V_6 ) ;
switch ( V_2 -> V_20 ) {
case V_249 :
case V_265 :
case V_266 :
case V_267 :
if ( ( V_2 -> V_67 > V_2 -> V_68 ) &&
( ( V_2 -> V_67 - V_2 -> V_68 ) >= F_76 ( V_180 ,
( V_2 -> V_15 . V_6 -> V_65 >> V_9 -> V_29 . V_268 ) ,
V_2 -> V_39 ) ) )
return true ;
break;
default:
break;
}
return false ;
}
void F_128 ( struct V_1 * V_2 , unsigned int V_269 )
{
struct V_164 * V_270 ;
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
if ( V_2 -> V_274 && V_2 -> V_67 >= V_2 -> V_274 ) {
int V_275 = F_75 ( V_2 -> V_39 , V_2 -> V_274 ) ;
V_2 -> V_67 += V_275 ;
V_2 -> V_274 -= V_275 ;
}
F_28 ( L_8 ,
V_154 , V_2 , V_269 , V_2 -> V_67 , V_2 -> V_273 ,
V_2 -> V_68 ) ;
if ( F_127 ( V_2 ) ) {
V_2 -> V_68 = V_2 -> V_67 ;
F_28 ( L_9
L_10 , V_154 , V_2 , V_2 -> V_67 ,
V_2 -> V_68 ) ;
V_270 = F_129 ( V_2 ) ;
if ( ! V_270 )
return;
V_2 -> V_69 . V_85 = 0 ;
F_130 ( & V_2 -> V_91 , V_270 ) ;
V_272 = & V_2 -> V_55 [ V_49 ] ;
if ( F_41 ( V_272 ) )
F_42 ( V_2 ) ;
}
}
void F_131 ( struct V_1 * V_2 , unsigned int V_269 )
{
int V_276 ;
int V_277 = 0 ;
if ( F_51 ( ! V_2 -> V_67 || V_2 -> V_273 ) )
F_28 ( L_11
L_12 , V_154 , V_2 ,
V_2 -> V_67 , V_2 -> V_273 ) ;
if ( V_2 -> V_4 -> V_278 )
V_276 = F_57 ( & V_2 -> V_71 ) ;
else
V_276 = F_57 ( & V_2 -> V_15 . V_6 -> V_279 ) ;
if ( V_276 >= V_2 -> V_15 . V_6 -> V_65 )
V_277 = 1 ;
if ( V_2 -> V_67 >= V_269 ) {
V_2 -> V_67 -= V_269 ;
if ( V_277 ) {
V_2 -> V_274 += V_2 -> V_67 ;
V_2 -> V_67 = 0 ;
}
} else {
V_2 -> V_273 = V_269 - V_2 -> V_67 ;
V_2 -> V_67 = 0 ;
}
F_28 ( L_13 ,
V_154 , V_2 , V_269 , V_2 -> V_67 , V_2 -> V_273 ,
V_2 -> V_274 ) ;
}
int F_132 ( struct V_1 * V_2 ,
T_1 V_7 , T_2 V_8 )
{
int V_280 ;
V_280 = ( V_96 == V_2 -> V_15 . V_6 -> V_95 ) ? V_281 : 0 ;
if ( V_2 -> V_69 . V_94 )
V_280 |= V_282 ;
if ( V_2 -> V_69 . V_97 )
V_280 |= V_283 ;
return F_133 ( F_2 ( V_2 -> V_15 . V_6 ) ,
& V_2 -> V_15 . V_18 ,
& V_2 -> V_4 -> V_15 . V_18 ,
V_7 , V_8 , V_280 ) ;
}
int F_134 ( struct V_1 * V_2 ,
struct V_284 * V_129 ,
T_2 V_8 )
{
int V_285 = F_20 ( V_129 -> V_286 -> V_232 . V_110 ) ;
int V_287 = V_129 -> V_288 ;
T_9 * V_289 = ( T_9 * ) V_129 -> V_286 + V_285 ;
return F_135 ( & V_2 -> V_15 . V_18 , V_289 , V_287 ,
V_2 -> V_4 -> V_15 . V_18 . V_19 , V_8 ) ;
}
int F_136 ( struct V_1 * V_2 ,
const union V_144 * V_225 )
{
int V_290 = 0 ;
if ( ( V_2 -> V_15 . V_18 . V_19 == F_20 ( V_225 -> V_172 . V_173 ) ) &&
F_99 ( & V_2 -> V_15 . V_18 , V_225 ,
F_3 ( V_2 -> V_15 . V_6 ) ) )
V_290 = 1 ;
return V_290 ;
}
int F_116 ( struct V_1 * V_2 , T_2 V_8 )
{
bool V_291 = ! ! ( V_8 & V_292 ) ;
int V_293 ;
if ( V_2 -> V_137 )
return 0 ;
if ( V_291 )
F_137 ( V_8 ) ;
F_53 ( & V_138 ) ;
V_293 = F_138 ( & V_139 , V_2 , 1 , 0 , V_294 ) ;
F_55 ( & V_138 ) ;
if ( V_291 )
F_139 () ;
if ( V_293 < 0 )
return V_293 ;
V_2 -> V_137 = ( V_295 ) V_293 ;
return 0 ;
}
static void F_140 ( struct V_1 * V_2 )
{
struct V_164 * V_296 ;
struct V_164 * V_297 ;
F_82 (asconf, tmp, &asoc->addip_chunk_list, list) {
F_109 ( & V_296 -> V_298 ) ;
F_141 ( V_296 ) ;
}
}
static void F_142 ( struct V_1 * V_2 )
{
struct V_164 * V_299 ;
struct V_164 * V_297 ;
F_82 (ack, tmp, &asoc->asconf_ack_list,
transmitted_list) {
F_109 ( & V_299 -> V_300 ) ;
F_141 ( V_299 ) ;
}
}
void F_143 ( const struct V_1 * V_2 )
{
struct V_164 * V_299 ;
struct V_164 * V_297 ;
F_82 (ack, tmp, &asoc->asconf_ack_list,
transmitted_list) {
if ( V_299 -> V_222 . V_301 -> V_302 ==
F_96 ( V_2 -> V_69 . V_81 ) )
break;
F_109 ( & V_299 -> V_300 ) ;
F_141 ( V_299 ) ;
}
}
struct V_164 * F_144 (
const struct V_1 * V_2 ,
T_6 V_302 )
{
struct V_164 * V_299 ;
F_62 (ack, &asoc->asconf_ack_list, transmitted_list) {
if ( F_145 ( V_299 ) )
continue;
if ( V_299 -> V_222 . V_301 -> V_302 == V_302 ) {
F_146 ( V_299 ) ;
return V_299 ;
}
}
return NULL ;
}
void F_47 ( struct V_1 * V_2 )
{
F_142 ( V_2 ) ;
F_140 ( V_2 ) ;
if ( V_2 -> V_161 )
F_141 ( V_2 -> V_161 ) ;
}
