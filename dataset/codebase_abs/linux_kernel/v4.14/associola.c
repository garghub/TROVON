static struct V_1 * F_1 (
struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_5 * V_6 ,
enum V_7 V_8 , T_1 V_9 )
{
struct V_10 * V_10 = F_2 ( V_6 ) ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int V_15 ;
V_12 = F_3 ( (struct V_5 * ) V_6 ) ;
V_2 -> V_4 = (struct V_3 * ) V_4 ;
V_2 -> V_16 . V_6 = (struct V_5 * ) V_6 ;
F_4 ( V_2 -> V_4 ) ;
F_5 ( V_2 -> V_16 . V_6 ) ;
V_2 -> V_16 . type = V_17 ;
F_6 ( & V_2 -> V_16 . V_18 , 1 ) ;
F_7 ( & V_2 -> V_16 . V_19 , V_4 -> V_16 . V_19 . V_20 ) ;
V_2 -> V_21 = V_22 ;
V_2 -> V_23 = F_8 ( V_12 -> V_24 . V_25 ) ;
V_2 -> V_26 = V_12 -> V_26 ;
V_2 -> V_27 = V_12 -> V_24 . V_28 ;
V_2 -> V_29 = V_10 -> V_30 . V_29 ;
V_2 -> V_31 = F_9 ( V_12 -> V_32 . V_33 ) ;
V_2 -> V_34 = F_9 ( V_12 -> V_32 . V_35 ) ;
V_2 -> V_36 = F_9 ( V_12 -> V_32 . V_37 ) ;
V_2 -> V_38 = F_9 ( V_12 -> V_38 ) ;
V_2 -> V_39 = V_12 -> V_39 ;
V_2 -> V_40 = V_12 -> V_40 ;
V_2 -> V_41 = F_9 ( V_12 -> V_41 ) ;
V_2 -> V_42 = V_12 -> V_42 ;
V_2 -> V_43 = V_12 -> V_43 ;
V_2 -> V_44 = V_12 -> V_44 ;
V_2 -> V_45 [ V_46 ] = V_2 -> V_31 ;
V_2 -> V_45 [ V_47 ] = V_2 -> V_31 ;
V_2 -> V_45 [ V_48 ] = V_2 -> V_31 ;
V_2 -> V_45 [ V_49 ]
= 5 * V_2 -> V_34 ;
V_2 -> V_45 [ V_50 ] = V_2 -> V_41 ;
V_2 -> V_45 [ V_51 ] = V_12 -> V_52 * V_53 ;
for ( V_15 = V_54 ; V_15 < V_55 ; ++ V_15 )
F_10 ( & V_2 -> V_56 [ V_15 ] , V_57 [ V_15 ] ,
( unsigned long ) V_2 ) ;
V_2 -> V_58 . V_59 = V_12 -> V_60 . V_59 ;
V_2 -> V_58 . V_61 = V_12 -> V_60 . V_61 ;
V_2 -> V_62 = V_12 -> V_60 . V_63 ;
V_2 -> V_64 =
F_9 ( V_12 -> V_60 . V_65 ) ;
if ( ( V_6 -> V_66 / 2 ) < V_67 )
V_2 -> V_68 = V_67 ;
else
V_2 -> V_68 = V_6 -> V_66 / 2 ;
V_2 -> V_69 = V_2 -> V_68 ;
V_2 -> V_70 . V_68 = V_71 ;
F_11 ( & V_2 -> V_72 , 0 ) ;
F_12 ( & V_2 -> V_73 ) ;
V_2 -> V_58 . V_74 = F_13 ( V_4 ) ;
V_2 -> V_58 . V_75 = V_4 -> V_16 . V_19 . V_20 ;
V_2 -> V_58 . V_76 = F_14 ( V_4 ) ;
V_2 -> V_77 = V_2 -> V_58 . V_76 ;
V_2 -> V_78 = V_2 -> V_77 - 1 ;
V_2 -> V_79 = V_2 -> V_78 ;
V_2 -> V_80 = V_2 -> V_78 ;
V_2 -> V_81 = V_2 -> V_78 ;
V_2 -> V_82 = V_2 -> V_58 . V_76 ;
V_2 -> V_83 = V_2 -> V_58 . V_76 ;
F_15 ( & V_2 -> V_84 ) ;
F_15 ( & V_2 -> V_85 ) ;
F_15 ( & V_2 -> V_70 . V_86 ) ;
V_2 -> V_70 . V_87 = 1 ;
V_2 -> V_70 . V_88 = 1 ;
if ( V_10 -> V_30 . V_89 )
V_2 -> V_70 . V_90 = 1 ;
F_16 ( & V_2 -> V_16 . V_91 ) ;
F_17 ( & V_2 -> V_16 . V_91 , V_92 ) ;
F_18 ( V_2 , & V_2 -> V_93 ) ;
if ( ! F_19 ( & V_2 -> V_94 , V_2 ) )
goto V_95;
if ( F_20 ( & V_2 -> V_96 , V_2 -> V_58 . V_61 ,
0 , V_9 ) )
goto V_95;
V_2 -> V_70 . V_97 = 1 ;
if ( V_2 -> V_16 . V_6 -> V_98 == V_99 )
V_2 -> V_70 . V_100 = 1 ;
F_15 ( & V_2 -> V_101 ) ;
V_2 -> V_102 = V_12 -> V_102 ;
V_2 -> V_103 = V_12 -> V_103 ;
V_2 -> V_104 = V_12 -> V_104 ;
V_2 -> V_105 = V_12 -> V_105 ;
V_2 -> V_106 = V_12 -> V_106 ;
V_2 -> V_107 = V_12 -> V_107 ;
F_15 ( & V_2 -> V_108 ) ;
if ( F_21 ( V_4 , V_2 , V_9 ) )
goto V_109;
V_2 -> V_110 = V_4 -> V_110 ;
V_2 -> V_111 = V_4 -> V_111 ;
V_2 -> V_112 = V_4 -> V_112 ;
V_2 -> V_113 = V_4 -> V_113 ;
if ( V_4 -> V_114 )
memcpy ( V_2 -> V_58 . V_115 , V_4 -> V_114 ,
F_22 ( V_4 -> V_114 -> V_116 . V_117 ) ) ;
if ( V_4 -> V_118 )
memcpy ( V_2 -> V_58 . V_119 , V_4 -> V_118 ,
F_22 ( V_4 -> V_118 -> V_116 . V_117 ) ) ;
V_14 = (struct V_13 * ) V_2 -> V_58 . V_120 ;
V_14 -> type = V_121 ;
V_14 -> V_117 = F_23 ( sizeof( * V_14 ) + V_122 ) ;
F_24 ( V_14 + 1 , V_122 ) ;
return V_2 ;
V_109:
F_25 ( & V_2 -> V_96 ) ;
V_95:
F_26 ( V_2 -> V_16 . V_6 ) ;
F_27 ( V_2 -> V_4 ) ;
return NULL ;
}
struct V_1 * F_28 ( const struct V_3 * V_4 ,
const struct V_5 * V_6 ,
enum V_7 V_8 , T_1 V_9 )
{
struct V_1 * V_2 ;
V_2 = F_29 ( sizeof( * V_2 ) , V_9 ) ;
if ( ! V_2 )
goto V_123;
if ( ! F_1 ( V_2 , V_4 , V_6 , V_8 , V_9 ) )
goto V_95;
F_30 ( V_124 ) ;
F_31 ( L_1 , V_2 ) ;
return V_2 ;
V_95:
F_32 ( V_2 ) ;
V_123:
return NULL ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_16 . V_6 ;
struct V_125 * V_126 ;
struct V_127 * V_128 , * V_129 ;
int V_15 ;
if ( ! F_34 ( & V_2 -> V_101 ) ) {
F_35 ( & V_2 -> V_101 ) ;
if ( F_36 ( V_6 , V_130 ) && F_37 ( V_6 , V_131 ) )
V_6 -> V_132 -- ;
}
V_2 -> V_16 . V_133 = true ;
F_38 ( & V_2 -> V_93 ) ;
F_39 ( & V_2 -> V_94 ) ;
F_40 ( & V_2 -> V_16 . V_91 ) ;
F_41 ( & V_2 -> V_70 . V_134 ) ;
F_25 ( & V_2 -> V_96 ) ;
if ( V_2 -> V_135 )
F_42 ( V_2 -> V_135 ) ;
F_43 ( & V_2 -> V_16 . V_19 ) ;
for ( V_15 = V_54 ; V_15 < V_55 ; ++ V_15 ) {
if ( F_44 ( & V_2 -> V_56 [ V_15 ] ) )
F_45 ( V_2 ) ;
}
F_32 ( V_2 -> V_70 . V_136 ) ;
F_32 ( V_2 -> V_70 . V_137 ) ;
F_32 ( V_2 -> V_70 . V_138 ) ;
F_32 ( V_2 -> V_70 . V_139 ) ;
F_46 (pos, temp, &asoc->peer.transport_addr_list) {
V_126 = F_47 ( V_128 , struct V_125 , V_140 ) ;
F_48 ( V_128 ) ;
F_49 ( V_126 ) ;
F_50 ( V_126 ) ;
}
V_2 -> V_70 . V_141 = 0 ;
F_51 ( V_2 ) ;
F_32 ( V_2 -> V_142 ) ;
F_52 ( & V_2 -> V_108 ) ;
F_53 ( V_2 -> V_143 ) ;
F_45 ( V_2 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
if ( F_55 ( ! V_2 -> V_16 . V_133 ) ) {
F_56 ( 1 , L_2 , V_2 ) ;
return;
}
F_27 ( V_2 -> V_4 ) ;
F_26 ( V_2 -> V_16 . V_6 ) ;
if ( V_2 -> V_144 != 0 ) {
F_57 ( & V_145 ) ;
F_58 ( & V_146 , V_2 -> V_144 ) ;
F_59 ( & V_145 ) ;
}
F_60 ( F_61 ( & V_2 -> V_72 ) ) ;
F_32 ( V_2 ) ;
F_62 ( V_124 ) ;
}
void F_63 ( struct V_1 * V_2 ,
struct V_125 * V_126 )
{
int V_147 = 0 ;
if ( V_2 -> V_70 . V_148 != NULL &&
V_2 -> V_70 . V_148 != V_126 )
V_147 = 1 ;
V_2 -> V_70 . V_148 = V_126 ;
memcpy ( & V_2 -> V_70 . V_149 , & V_126 -> V_150 ,
sizeof( union V_151 ) ) ;
if ( ( V_126 -> V_21 == V_152 ) ||
( V_126 -> V_21 == V_153 ) )
V_2 -> V_70 . V_154 = V_126 ;
if ( ! V_2 -> V_93 . V_155 && ! V_2 -> V_93 . V_156 )
return;
if ( V_126 -> V_157 . V_158 )
V_126 -> V_157 . V_159 = V_147 ;
V_126 -> V_157 . V_158 = V_147 ;
V_126 -> V_157 . V_160 = V_2 -> V_77 ;
}
void F_64 ( struct V_1 * V_2 ,
struct V_125 * V_70 )
{
struct V_127 * V_128 ;
struct V_125 * V_126 ;
F_31 ( L_3 ,
V_161 , V_2 , & V_70 -> V_150 . V_162 ) ;
if ( V_2 -> V_70 . V_163 == V_70 )
F_65 ( V_2 ) ;
F_48 ( & V_70 -> V_140 ) ;
F_49 ( V_70 ) ;
V_128 = V_2 -> V_70 . V_86 . V_164 ;
V_126 = F_47 ( V_128 , struct V_125 , V_140 ) ;
if ( V_2 -> V_70 . V_148 == V_70 )
F_63 ( V_2 , V_126 ) ;
if ( V_2 -> V_70 . V_154 == V_70 )
V_2 -> V_70 . V_154 = V_126 ;
if ( V_2 -> V_70 . V_163 == V_70 )
V_2 -> V_70 . V_163 = V_126 ;
if ( V_2 -> V_70 . V_165 == V_70 )
V_2 -> V_70 . V_165 = V_126 ;
if ( V_2 -> V_135 &&
V_2 -> V_135 -> V_126 == V_70 ) {
V_2 -> V_135 -> V_126 = V_126 ;
F_66 ( V_126 ) ;
}
if ( V_2 -> V_166 == V_70 )
V_2 -> V_166 = NULL ;
if ( V_2 -> V_167 == V_70 )
V_2 -> V_167 = NULL ;
if ( V_2 -> V_168 &&
V_2 -> V_168 -> V_126 == V_70 )
V_2 -> V_168 -> V_126 = NULL ;
if ( ! F_34 ( & V_70 -> V_169 ) ) {
struct V_125 * V_170 = V_2 -> V_70 . V_154 ;
struct V_171 * V_172 ;
F_67 (ch, &peer->transmitted,
transmitted_list) {
V_172 -> V_126 = NULL ;
V_172 -> V_173 = 0 ;
}
F_68 ( & V_70 -> V_169 ,
& V_170 -> V_169 ) ;
if ( ! F_69 ( & V_170 -> V_174 ) )
if ( ! F_70 ( & V_170 -> V_174 ,
V_175 + V_170 -> V_176 ) )
F_71 ( V_170 ) ;
}
V_2 -> V_70 . V_141 -- ;
F_50 ( V_70 ) ;
}
struct V_125 * F_72 ( struct V_1 * V_2 ,
const union V_151 * V_177 ,
const T_1 V_9 ,
const int V_178 )
{
struct V_10 * V_10 = F_2 ( V_2 -> V_16 . V_6 ) ;
struct V_125 * V_70 ;
struct V_11 * V_12 ;
unsigned short V_20 ;
V_12 = F_3 ( V_2 -> V_16 . V_6 ) ;
V_20 = F_22 ( V_177 -> V_179 . V_180 ) ;
F_31 ( L_4 , V_161 ,
V_2 , & V_177 -> V_162 , V_178 ) ;
if ( 0 == V_2 -> V_70 . V_20 )
V_2 -> V_70 . V_20 = V_20 ;
V_70 = F_73 ( V_2 , V_177 ) ;
if ( V_70 ) {
if ( V_70 -> V_21 == V_153 ) {
V_70 -> V_21 = V_152 ;
}
return V_70 ;
}
V_70 = F_74 ( V_10 , V_177 , V_9 ) ;
if ( ! V_70 )
return NULL ;
F_75 ( V_70 , V_2 ) ;
V_70 -> V_38 = V_2 -> V_38 ;
V_70 -> V_39 = V_2 -> V_39 ;
V_70 -> V_29 = V_2 -> V_29 ;
V_70 -> V_41 = V_2 -> V_41 ;
V_70 -> V_42 = V_2 -> V_42 ;
V_70 -> V_43 = V_2 -> V_43 ;
F_76 ( V_70 , NULL , V_12 ) ;
if ( V_70 -> V_43 & V_181 ) {
if ( V_2 -> V_40 )
V_70 -> V_40 = V_2 -> V_40 ;
else
V_70 -> V_40 = V_182 ;
}
if ( V_2 -> V_40 )
V_2 -> V_40 = F_77 ( int , V_70 -> V_40 , V_2 -> V_40 ) ;
else
V_2 -> V_40 = V_70 -> V_40 ;
F_31 ( L_5 , V_161 , V_2 ,
V_2 -> V_40 ) ;
V_70 -> V_183 = 0 ;
V_2 -> V_184 = F_78 ( V_2 , V_2 -> V_40 ) ;
F_79 ( & V_70 -> V_185 , V_70 , V_2 -> V_16 . V_19 . V_20 ,
V_2 -> V_70 . V_20 ) ;
V_70 -> V_186 = F_80 ( 4 * V_2 -> V_40 , F_81 ( V_187 , 2 * V_2 -> V_40 , 4380 ) ) ;
V_70 -> V_188 = V_71 ;
V_70 -> V_189 = 0 ;
V_70 -> V_190 = 0 ;
V_70 -> V_191 = 0 ;
V_70 -> V_176 = V_2 -> V_31 ;
F_82 ( V_2 , V_70 ) ;
V_70 -> V_21 = V_178 ;
if ( F_83 ( V_70 ) ) {
F_50 ( V_70 ) ;
return NULL ;
}
F_84 ( & V_70 -> V_140 , & V_2 -> V_70 . V_86 ) ;
V_2 -> V_70 . V_141 ++ ;
if ( ! V_2 -> V_70 . V_148 ) {
F_63 ( V_2 , V_70 ) ;
V_2 -> V_70 . V_163 = V_70 ;
}
if ( V_2 -> V_70 . V_154 == V_2 -> V_70 . V_163 &&
V_70 -> V_21 != V_192 ) {
V_2 -> V_70 . V_163 = V_70 ;
}
return V_70 ;
}
void F_85 ( struct V_1 * V_2 ,
const union V_151 * V_177 )
{
struct V_127 * V_128 ;
struct V_127 * V_129 ;
struct V_125 * V_126 ;
F_46 (pos, temp, &asoc->peer.transport_addr_list) {
V_126 = F_47 ( V_128 , struct V_125 , V_140 ) ;
if ( F_86 ( V_177 , & V_126 -> V_150 ) ) {
F_64 ( V_2 , V_126 ) ;
break;
}
}
}
struct V_125 * F_73 (
const struct V_1 * V_2 ,
const union V_151 * V_193 )
{
struct V_125 * V_194 ;
F_67 (t, &asoc->peer.transport_addr_list,
transports) {
if ( F_86 ( V_193 , & V_194 -> V_150 ) )
return V_194 ;
}
return NULL ;
}
void F_87 ( struct V_1 * V_2 ,
struct V_125 * V_195 )
{
struct V_125 * V_129 ;
struct V_125 * V_194 ;
F_88 (t, temp, &asoc->peer.transport_addr_list,
transports) {
if ( V_194 != V_195 )
F_64 ( V_2 , V_194 ) ;
}
}
void F_89 ( struct V_1 * V_2 ,
struct V_125 * V_126 ,
enum V_196 V_197 ,
T_2 error )
{
struct V_198 * V_199 ;
struct V_200 V_177 ;
int V_201 = 0 ;
bool V_202 = true ;
switch ( V_197 ) {
case V_203 :
if ( V_192 == V_126 -> V_21 &&
V_204 == error )
V_201 = V_205 ;
else
V_201 = V_206 ;
if ( V_126 -> V_21 == V_207 ) {
V_202 = false ;
V_126 -> V_186 = V_2 -> V_40 ;
}
V_126 -> V_21 = V_152 ;
break;
case V_208 :
if ( V_126 -> V_21 != V_192 )
V_126 -> V_21 = V_209 ;
else {
F_90 ( V_126 ) ;
V_202 = false ;
}
V_201 = V_210 ;
break;
case V_211 :
V_126 -> V_21 = V_207 ;
V_202 = false ;
break;
default:
return;
}
if ( V_202 ) {
memset ( & V_177 , 0 , sizeof( struct V_200 ) ) ;
memcpy ( & V_177 , & V_126 -> V_150 ,
V_126 -> V_212 -> V_213 ) ;
V_199 = F_91 ( V_2 , & V_177 ,
0 , V_201 , error , V_214 ) ;
if ( V_199 )
F_92 ( & V_2 -> V_94 , V_199 ) ;
}
F_93 ( V_2 ) ;
}
void F_94 ( struct V_1 * V_2 )
{
F_95 ( & V_2 -> V_16 . V_18 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
if ( F_96 ( & V_2 -> V_16 . V_18 ) )
F_54 ( V_2 ) ;
}
V_187 F_97 ( struct V_1 * V_2 )
{
V_187 V_215 = V_2 -> V_77 ;
V_2 -> V_77 ++ ;
V_2 -> V_216 ++ ;
return V_215 ;
}
int F_86 ( const union V_151 * V_217 ,
const union V_151 * V_218 )
{
struct V_219 * V_220 ;
V_220 = F_98 ( V_217 -> V_162 . V_221 ) ;
if ( F_55 ( ! V_220 ) )
return 0 ;
return V_220 -> V_222 ( V_217 , V_218 ) ;
}
struct V_171 * F_99 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_223 )
return NULL ;
return F_100 ( V_2 , V_2 -> V_224 ) ;
}
struct V_125 * F_101 ( struct V_1 * V_2 ,
V_187 V_225 )
{
struct V_125 * V_170 ;
struct V_125 * V_226 ;
struct V_125 * V_126 ;
struct V_171 * V_227 ;
T_3 V_228 = F_102 ( V_225 ) ;
V_226 = NULL ;
V_170 = V_2 -> V_70 . V_154 ;
F_67 (chunk, &active->transmitted,
transmitted_list) {
if ( V_228 == V_227 -> V_229 . V_230 -> V_225 ) {
V_226 = V_170 ;
goto V_231;
}
}
F_67 (transport, &asoc->peer.transport_addr_list,
transports) {
if ( V_126 == V_170 )
continue;
F_67 (chunk, &transport->transmitted,
transmitted_list) {
if ( V_228 == V_227 -> V_229 . V_230 -> V_225 ) {
V_226 = V_126 ;
goto V_231;
}
}
}
V_231:
return V_226 ;
}
struct V_125 * F_103 ( struct V_1 * V_2 ,
struct V_10 * V_10 ,
const union V_151 * V_232 ,
const union V_151 * V_233 )
{
struct V_125 * V_126 ;
if ( ( F_23 ( V_2 -> V_16 . V_19 . V_20 ) == V_232 -> V_179 . V_180 ) &&
( F_23 ( V_2 -> V_70 . V_20 ) == V_233 -> V_179 . V_180 ) &&
F_104 ( F_2 ( V_2 -> V_16 . V_6 ) , V_10 ) ) {
V_126 = F_73 ( V_2 , V_233 ) ;
if ( ! V_126 )
goto V_231;
if ( F_105 ( & V_2 -> V_16 . V_19 , V_232 ,
F_3 ( V_2 -> V_16 . V_6 ) ) )
goto V_231;
}
V_126 = NULL ;
V_231:
return V_126 ;
}
static void V_92 ( struct V_234 * V_235 )
{
struct V_1 * V_2 =
F_106 ( V_235 , struct V_1 ,
V_16 . V_91 . V_236 ) ;
struct V_10 * V_10 = F_2 ( V_2 -> V_16 . V_6 ) ;
union V_237 V_238 ;
struct V_3 * V_4 ;
struct V_171 * V_227 ;
struct V_239 * V_91 ;
int V_21 ;
int error = 0 ;
V_4 = V_2 -> V_4 ;
V_91 = & V_2 -> V_16 . V_91 ;
F_94 ( V_2 ) ;
while ( NULL != ( V_227 = F_107 ( V_91 ) ) ) {
V_21 = V_2 -> V_21 ;
V_238 = F_108 ( V_227 -> V_240 -> type ) ;
if ( F_109 ( V_238 . V_227 , V_2 ) && ! V_227 -> V_241 )
continue;
if ( F_110 ( V_227 ) )
V_2 -> V_70 . V_165 = V_227 -> V_126 ;
else {
F_111 ( V_10 , V_242 ) ;
V_2 -> V_243 . V_244 ++ ;
if ( V_227 -> V_240 -> type == V_245 )
V_2 -> V_243 . V_246 ++ ;
}
if ( V_227 -> V_126 )
V_227 -> V_126 -> V_247 = F_112 () ;
error = F_113 ( V_10 , V_248 , V_238 ,
V_21 , V_4 , V_2 , V_227 , V_214 ) ;
if ( V_2 -> V_16 . V_133 )
break;
if ( error && V_227 )
V_227 -> V_249 = 1 ;
}
F_45 ( V_2 ) ;
}
void F_114 ( struct V_1 * V_124 , struct V_5 * V_250 )
{
struct V_11 * V_251 = F_3 ( V_250 ) ;
struct V_5 * V_252 = V_124 -> V_16 . V_6 ;
F_115 ( & V_124 -> V_101 ) ;
if ( F_36 ( V_252 , V_130 ) )
V_252 -> V_132 -- ;
F_27 ( V_124 -> V_4 ) ;
F_26 ( V_124 -> V_16 . V_6 ) ;
V_124 -> V_4 = V_251 -> V_4 ;
F_4 ( V_124 -> V_4 ) ;
V_124 -> V_16 . V_6 = V_250 ;
F_5 ( V_124 -> V_16 . V_6 ) ;
F_116 ( V_251 -> V_4 , V_124 ) ;
}
int F_117 ( struct V_1 * V_2 ,
struct V_1 * V_253 )
{
struct V_125 * V_254 ;
struct V_127 * V_128 , * V_129 ;
V_2 -> V_58 = V_253 -> V_58 ;
V_2 -> V_70 . V_68 = V_253 -> V_70 . V_68 ;
V_2 -> V_70 . V_87 = V_253 -> V_70 . V_87 ;
V_2 -> V_70 . V_255 = V_253 -> V_70 . V_255 ;
V_2 -> V_70 . V_15 = V_253 -> V_70 . V_15 ;
if ( ! F_118 ( & V_2 -> V_70 . V_134 , V_256 ,
V_2 -> V_70 . V_15 . V_76 , V_214 ) )
return - V_257 ;
F_46 (pos, temp, &asoc->peer.transport_addr_list) {
V_254 = F_47 ( V_128 , struct V_125 , V_140 ) ;
if ( ! F_73 ( V_253 , & V_254 -> V_150 ) ) {
F_64 ( V_2 , V_254 ) ;
continue;
}
if ( V_2 -> V_21 >= V_258 )
F_119 ( V_254 ) ;
}
if ( V_2 -> V_21 >= V_258 ) {
V_2 -> V_77 = V_253 -> V_77 ;
V_2 -> V_78 = V_253 -> V_78 ;
V_2 -> V_79 = V_253 -> V_79 ;
F_120 ( & V_2 -> V_96 ) ;
F_121 ( & V_2 -> V_94 ) ;
V_2 -> V_259 = 0 ;
} else {
F_67 (trans, &new->peer.transport_addr_list,
transports)
if ( ! F_73 ( V_2 , & V_254 -> V_150 ) &&
! F_72 ( V_2 , & V_254 -> V_150 ,
V_214 , V_254 -> V_21 ) )
return - V_257 ;
V_2 -> V_78 = V_2 -> V_77 - 1 ;
V_2 -> V_79 = V_2 -> V_78 ;
if ( F_122 ( V_2 , V_260 ) )
F_123 ( & V_2 -> V_96 , & V_253 -> V_96 ) ;
if ( F_124 ( V_2 , V_214 ) )
return - V_257 ;
}
F_32 ( V_2 -> V_70 . V_137 ) ;
V_2 -> V_70 . V_137 = V_253 -> V_70 . V_137 ;
V_253 -> V_70 . V_137 = NULL ;
F_32 ( V_2 -> V_70 . V_138 ) ;
V_2 -> V_70 . V_138 = V_253 -> V_70 . V_138 ;
V_253 -> V_70 . V_138 = NULL ;
F_32 ( V_2 -> V_70 . V_139 ) ;
V_2 -> V_70 . V_139 = V_253 -> V_70 . V_139 ;
V_253 -> V_70 . V_139 = NULL ;
return F_125 ( V_2 , V_214 ) ;
}
static T_4 F_126 ( const struct V_125 * V_254 )
{
switch ( V_254 -> V_21 ) {
case V_152 :
return 3 ;
case V_153 :
return 2 ;
case V_207 :
return 1 ;
default:
return 0 ;
}
}
static struct V_125 * F_127 ( struct V_125 * V_261 ,
struct V_125 * V_262 )
{
if ( V_261 -> V_263 > V_262 -> V_263 ) {
return V_262 ;
} else if ( V_261 -> V_263 == V_262 -> V_263 &&
F_128 ( V_262 -> V_247 ,
V_261 -> V_247 ) ) {
return V_262 ;
} else {
return V_261 ;
}
}
static struct V_125 * F_129 ( struct V_125 * V_264 ,
struct V_125 * V_265 )
{
T_4 V_266 , V_267 ;
if ( V_265 == NULL || V_264 == V_265 )
return V_264 ;
V_266 = F_126 ( V_264 ) ;
V_267 = F_126 ( V_265 ) ;
if ( V_266 > V_267 )
return V_264 ;
else if ( V_266 == V_267 )
return F_127 ( V_265 , V_264 ) ;
else
return V_265 ;
}
void F_65 ( struct V_1 * V_2 )
{
struct V_125 * V_254 = V_2 -> V_70 . V_163 ;
struct V_125 * V_268 = NULL ;
if ( V_2 -> V_70 . V_141 == 1 )
return;
if ( V_2 -> V_70 . V_154 == V_2 -> V_70 . V_163 &&
V_2 -> V_70 . V_154 -> V_21 == V_152 )
return;
for ( V_254 = F_130 ( V_254 , V_140 ) ; 1 ;
V_254 = F_130 ( V_254 , V_140 ) ) {
if ( & V_254 -> V_140 == & V_2 -> V_70 . V_86 )
continue;
if ( V_254 -> V_21 == V_192 )
continue;
V_268 = F_129 ( V_254 , V_268 ) ;
if ( V_268 -> V_21 == V_152 )
break;
if ( V_254 == V_2 -> V_70 . V_163 )
break;
}
V_2 -> V_70 . V_163 = V_268 ;
F_31 ( L_6 ,
V_161 , V_2 , & V_2 -> V_70 . V_163 -> V_150 . V_162 ) ;
}
static void F_93 ( struct V_1 * V_2 )
{
struct V_125 * V_254 , * V_269 = NULL , * V_270 = NULL ;
struct V_125 * V_271 = NULL ;
F_67 (trans, &asoc->peer.transport_addr_list,
transports) {
if ( V_254 -> V_21 == V_209 ||
V_254 -> V_21 == V_192 )
continue;
if ( V_254 -> V_21 == V_207 ) {
V_271 = F_129 ( V_254 , V_271 ) ;
continue;
}
if ( V_269 == NULL ||
F_128 ( V_254 -> V_247 ,
V_269 -> V_247 ) ) {
V_270 = V_269 ;
V_269 = V_254 ;
} else if ( V_270 == NULL ||
F_128 ( V_254 -> V_247 ,
V_270 -> V_247 ) ) {
V_270 = V_254 ;
}
}
if ( ( V_2 -> V_70 . V_148 -> V_21 == V_152 ||
V_2 -> V_70 . V_148 -> V_21 == V_153 ) &&
V_2 -> V_70 . V_148 != V_269 ) {
V_270 = V_269 ;
V_269 = V_2 -> V_70 . V_148 ;
}
if ( V_270 == NULL )
V_270 = V_269 ;
if ( V_269 == NULL ) {
V_269 = F_129 ( V_2 -> V_70 . V_154 , V_271 ) ;
V_270 = V_269 ;
}
V_2 -> V_70 . V_154 = V_269 ;
V_2 -> V_70 . V_163 = V_270 ;
}
struct V_125 *
F_131 ( struct V_1 * V_2 ,
struct V_125 * V_272 )
{
if ( V_272 == NULL ) {
return V_2 -> V_70 . V_154 ;
} else {
if ( V_272 == V_2 -> V_70 . V_163 )
F_65 ( V_2 ) ;
return V_2 -> V_70 . V_163 ;
}
}
void F_132 ( struct V_1 * V_2 )
{
struct V_125 * V_194 ;
V_187 V_273 = 0 ;
if ( ! V_2 )
return;
F_67 (t, &asoc->peer.transport_addr_list,
transports) {
if ( V_194 -> V_183 && V_194 -> V_274 ) {
F_133 (
V_194 , F_134 ( F_135 ( V_194 -> V_274 ) ) ) ;
V_194 -> V_183 = 0 ;
}
if ( ! V_273 || ( V_194 -> V_40 < V_273 ) )
V_273 = V_194 -> V_40 ;
}
if ( V_273 ) {
V_2 -> V_40 = V_273 ;
V_2 -> V_184 = F_78 ( V_2 , V_273 ) ;
}
F_31 ( L_7 , V_161 , V_2 ,
V_2 -> V_40 , V_2 -> V_184 ) ;
}
static inline bool F_136 ( struct V_1 * V_2 )
{
struct V_10 * V_10 = F_2 ( V_2 -> V_16 . V_6 ) ;
switch ( V_2 -> V_21 ) {
case V_258 :
case V_275 :
case V_276 :
case V_277 :
if ( ( V_2 -> V_68 > V_2 -> V_69 ) &&
( ( V_2 -> V_68 - V_2 -> V_69 ) >= F_81 ( V_187 ,
( V_2 -> V_16 . V_6 -> V_66 >> V_10 -> V_30 . V_278 ) ,
V_2 -> V_40 ) ) )
return true ;
break;
default:
break;
}
return false ;
}
void F_137 ( struct V_1 * V_2 , unsigned int V_279 )
{
struct V_171 * V_280 ;
struct V_281 * V_282 ;
if ( V_2 -> V_283 ) {
if ( V_2 -> V_283 >= V_279 ) {
V_2 -> V_283 -= V_279 ;
} else {
V_2 -> V_68 += ( V_279 - V_2 -> V_283 ) ;
V_2 -> V_283 = 0 ;
}
} else {
V_2 -> V_68 += V_279 ;
}
if ( V_2 -> V_284 ) {
int V_285 = F_80 ( V_2 -> V_40 , V_2 -> V_284 ) ;
V_2 -> V_68 += V_285 ;
V_2 -> V_284 -= V_285 ;
}
F_31 ( L_8 ,
V_161 , V_2 , V_279 , V_2 -> V_68 , V_2 -> V_283 ,
V_2 -> V_69 ) ;
if ( F_136 ( V_2 ) ) {
V_2 -> V_69 = V_2 -> V_68 ;
F_31 ( L_9
L_10 , V_161 , V_2 , V_2 -> V_68 ,
V_2 -> V_69 ) ;
V_280 = F_138 ( V_2 ) ;
if ( ! V_280 )
return;
V_2 -> V_70 . V_87 = 0 ;
F_139 ( & V_2 -> V_93 , V_280 , V_214 ) ;
V_282 = & V_2 -> V_56 [ V_50 ] ;
if ( F_44 ( V_282 ) )
F_45 ( V_2 ) ;
}
}
void F_140 ( struct V_1 * V_2 , unsigned int V_279 )
{
int V_286 ;
int V_287 = 0 ;
if ( F_55 ( ! V_2 -> V_68 || V_2 -> V_283 ) )
F_31 ( L_11
L_12 , V_161 , V_2 ,
V_2 -> V_68 , V_2 -> V_283 ) ;
if ( V_2 -> V_4 -> V_288 )
V_286 = F_61 ( & V_2 -> V_72 ) ;
else
V_286 = F_61 ( & V_2 -> V_16 . V_6 -> V_289 ) ;
if ( V_286 >= V_2 -> V_16 . V_6 -> V_66 )
V_287 = 1 ;
if ( V_2 -> V_68 >= V_279 ) {
V_2 -> V_68 -= V_279 ;
if ( V_287 ) {
V_2 -> V_284 += V_2 -> V_68 ;
V_2 -> V_68 = 0 ;
}
} else {
V_2 -> V_283 += V_279 - V_2 -> V_68 ;
V_2 -> V_68 = 0 ;
}
F_31 ( L_13 ,
V_161 , V_2 , V_279 , V_2 -> V_68 , V_2 -> V_283 ,
V_2 -> V_284 ) ;
}
int F_141 ( struct V_1 * V_2 ,
enum V_7 V_8 , T_1 V_9 )
{
int V_290 ;
V_290 = ( V_99 == V_2 -> V_16 . V_6 -> V_98 ) ? V_291 : 0 ;
if ( V_2 -> V_70 . V_97 )
V_290 |= V_292 ;
if ( V_2 -> V_70 . V_100 )
V_290 |= V_293 ;
return F_142 ( F_2 ( V_2 -> V_16 . V_6 ) ,
& V_2 -> V_16 . V_19 ,
& V_2 -> V_4 -> V_16 . V_19 ,
V_8 , V_9 , V_290 ) ;
}
int F_143 ( struct V_1 * V_2 ,
struct V_294 * V_136 ,
T_1 V_9 )
{
int V_295 = F_22 ( V_136 -> V_296 -> V_240 . V_117 ) ;
int V_297 = V_136 -> V_298 ;
T_5 * V_299 = ( T_5 * ) V_136 -> V_296 + V_295 ;
return F_144 ( & V_2 -> V_16 . V_19 , V_299 , V_297 ,
V_2 -> V_4 -> V_16 . V_19 . V_20 , V_9 ) ;
}
int F_145 ( struct V_1 * V_2 ,
const union V_151 * V_232 )
{
int V_300 = 0 ;
if ( ( V_2 -> V_16 . V_19 . V_20 == F_22 ( V_232 -> V_179 . V_180 ) ) &&
F_105 ( & V_2 -> V_16 . V_19 , V_232 ,
F_3 ( V_2 -> V_16 . V_6 ) ) )
V_300 = 1 ;
return V_300 ;
}
int F_124 ( struct V_1 * V_2 , T_1 V_9 )
{
bool V_301 = F_146 ( V_9 ) ;
int V_302 ;
if ( V_2 -> V_144 )
return 0 ;
if ( V_301 )
F_147 ( V_9 ) ;
F_57 ( & V_145 ) ;
V_302 = F_148 ( & V_146 , V_2 , 1 , 0 , V_303 ) ;
F_59 ( & V_145 ) ;
if ( V_301 )
F_149 () ;
if ( V_302 < 0 )
return V_302 ;
V_2 -> V_144 = ( V_304 ) V_302 ;
return 0 ;
}
static void F_150 ( struct V_1 * V_2 )
{
struct V_171 * V_305 ;
struct V_171 * V_306 ;
F_88 (asconf, tmp, &asoc->addip_chunk_list, list) {
F_115 ( & V_305 -> V_307 ) ;
F_42 ( V_305 ) ;
}
}
static void F_151 ( struct V_1 * V_2 )
{
struct V_171 * V_308 ;
struct V_171 * V_306 ;
F_88 (ack, tmp, &asoc->asconf_ack_list,
transmitted_list) {
F_115 ( & V_308 -> V_309 ) ;
F_42 ( V_308 ) ;
}
}
void F_152 ( const struct V_1 * V_2 )
{
struct V_171 * V_308 ;
struct V_171 * V_306 ;
F_88 (ack, tmp, &asoc->asconf_ack_list,
transmitted_list) {
if ( V_308 -> V_229 . V_310 -> V_311 ==
F_102 ( V_2 -> V_70 . V_82 ) )
break;
F_115 ( & V_308 -> V_309 ) ;
F_42 ( V_308 ) ;
}
}
struct V_171 * F_153 (
const struct V_1 * V_2 ,
T_3 V_311 )
{
struct V_171 * V_308 ;
F_67 (ack, &asoc->asconf_ack_list, transmitted_list) {
if ( F_154 ( V_308 ) )
continue;
if ( V_308 -> V_229 . V_310 -> V_311 == V_311 ) {
F_155 ( V_308 ) ;
return V_308 ;
}
}
return NULL ;
}
void F_51 ( struct V_1 * V_2 )
{
F_151 ( V_2 ) ;
F_150 ( V_2 ) ;
if ( V_2 -> V_168 )
F_42 ( V_2 -> V_168 ) ;
}
