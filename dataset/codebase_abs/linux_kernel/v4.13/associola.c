static struct V_1 * F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_5 * V_6 ,
T_1 V_7 ,
T_2 V_8 )
{
struct V_9 * V_9 = F_2 ( V_6 ) ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
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
for ( V_14 = V_53 ; V_14 < V_54 ; ++ V_14 )
F_10 ( & V_2 -> V_55 [ V_14 ] , V_56 [ V_14 ] ,
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
F_11 ( & V_2 -> V_71 , 0 ) ;
F_12 ( & V_2 -> V_72 ) ;
V_2 -> V_57 . V_73 = F_13 ( V_4 ) ;
V_2 -> V_57 . V_74 = V_4 -> V_15 . V_18 . V_19 ;
V_2 -> V_57 . V_75 = F_14 ( V_4 ) ;
V_2 -> V_76 = V_2 -> V_57 . V_75 ;
V_2 -> V_77 = V_2 -> V_76 - 1 ;
V_2 -> V_78 = V_2 -> V_77 ;
V_2 -> V_79 = V_2 -> V_77 ;
V_2 -> V_80 = V_2 -> V_77 ;
V_2 -> V_81 = V_2 -> V_57 . V_75 ;
V_2 -> V_82 = V_2 -> V_57 . V_75 ;
F_15 ( & V_2 -> V_83 ) ;
F_15 ( & V_2 -> V_84 ) ;
F_15 ( & V_2 -> V_69 . V_85 ) ;
V_2 -> V_69 . V_86 = 1 ;
V_2 -> V_69 . V_87 = 1 ;
if ( V_9 -> V_29 . V_88 )
V_2 -> V_69 . V_89 = 1 ;
F_16 ( & V_2 -> V_15 . V_90 ) ;
F_17 ( & V_2 -> V_15 . V_90 , V_91 ) ;
F_18 ( V_2 , & V_2 -> V_92 ) ;
if ( ! F_19 ( & V_2 -> V_93 , V_2 ) )
goto V_94;
if ( F_20 ( & V_2 -> V_95 , V_2 -> V_57 . V_60 ,
0 , V_8 ) )
goto V_94;
V_2 -> V_69 . V_96 = 1 ;
if ( V_2 -> V_15 . V_6 -> V_97 == V_98 )
V_2 -> V_69 . V_99 = 1 ;
F_15 ( & V_2 -> V_100 ) ;
V_2 -> V_101 = V_11 -> V_101 ;
V_2 -> V_102 = V_11 -> V_102 ;
V_2 -> V_103 = V_11 -> V_103 ;
V_2 -> V_104 = V_11 -> V_104 ;
V_2 -> V_105 = V_11 -> V_105 ;
V_2 -> V_106 = V_11 -> V_106 ;
F_15 ( & V_2 -> V_107 ) ;
if ( F_21 ( V_4 , V_2 , V_8 ) )
goto V_108;
V_2 -> V_109 = V_4 -> V_109 ;
V_2 -> V_110 = V_4 -> V_110 ;
V_2 -> V_111 = V_4 -> V_111 ;
V_2 -> V_112 = V_4 -> V_112 ;
if ( V_4 -> V_113 )
memcpy ( V_2 -> V_57 . V_114 , V_4 -> V_113 ,
F_22 ( V_4 -> V_113 -> V_115 . V_116 ) ) ;
if ( V_4 -> V_117 )
memcpy ( V_2 -> V_57 . V_118 , V_4 -> V_117 ,
F_22 ( V_4 -> V_117 -> V_115 . V_116 ) ) ;
V_13 = (struct V_12 * ) V_2 -> V_57 . V_119 ;
V_13 -> type = V_120 ;
V_13 -> V_116 = F_23 ( sizeof( * V_13 ) + V_121 ) ;
F_24 ( V_13 + 1 , V_121 ) ;
return V_2 ;
V_108:
F_25 ( & V_2 -> V_95 ) ;
V_94:
F_26 ( V_2 -> V_15 . V_6 ) ;
F_27 ( V_2 -> V_4 ) ;
return NULL ;
}
struct V_1 * F_28 ( const struct V_3 * V_4 ,
const struct V_5 * V_6 ,
T_1 V_7 ,
T_2 V_8 )
{
struct V_1 * V_2 ;
V_2 = F_29 ( sizeof( * V_2 ) , V_8 ) ;
if ( ! V_2 )
goto V_122;
if ( ! F_1 ( V_2 , V_4 , V_6 , V_7 , V_8 ) )
goto V_94;
F_30 ( V_123 ) ;
F_31 ( L_1 , V_2 ) ;
return V_2 ;
V_94:
F_32 ( V_2 ) ;
V_122:
return NULL ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_15 . V_6 ;
struct V_124 * V_125 ;
struct V_126 * V_127 , * V_128 ;
int V_14 ;
if ( ! F_34 ( & V_2 -> V_100 ) ) {
F_35 ( & V_2 -> V_100 ) ;
if ( F_36 ( V_6 , V_129 ) && F_37 ( V_6 , V_130 ) )
V_6 -> V_131 -- ;
}
V_2 -> V_15 . V_132 = true ;
F_38 ( & V_2 -> V_92 ) ;
F_39 ( & V_2 -> V_93 ) ;
F_40 ( & V_2 -> V_15 . V_90 ) ;
F_41 ( & V_2 -> V_69 . V_133 ) ;
F_25 ( & V_2 -> V_95 ) ;
if ( V_2 -> V_134 )
F_42 ( V_2 -> V_134 ) ;
F_43 ( & V_2 -> V_15 . V_18 ) ;
for ( V_14 = V_53 ; V_14 < V_54 ; ++ V_14 ) {
if ( F_44 ( & V_2 -> V_55 [ V_14 ] ) )
F_45 ( V_2 ) ;
}
F_32 ( V_2 -> V_69 . V_135 ) ;
F_32 ( V_2 -> V_69 . V_136 ) ;
F_32 ( V_2 -> V_69 . V_137 ) ;
F_32 ( V_2 -> V_69 . V_138 ) ;
F_46 (pos, temp, &asoc->peer.transport_addr_list) {
V_125 = F_47 ( V_127 , struct V_124 , V_139 ) ;
F_48 ( V_127 ) ;
F_49 ( V_125 ) ;
F_50 ( V_125 ) ;
}
V_2 -> V_69 . V_140 = 0 ;
F_51 ( V_2 ) ;
F_32 ( V_2 -> V_141 ) ;
F_52 ( & V_2 -> V_107 ) ;
F_53 ( V_2 -> V_142 ) ;
F_45 ( V_2 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
if ( F_55 ( ! V_2 -> V_15 . V_132 ) ) {
F_56 ( 1 , L_2 , V_2 ) ;
return;
}
F_27 ( V_2 -> V_4 ) ;
F_26 ( V_2 -> V_15 . V_6 ) ;
if ( V_2 -> V_143 != 0 ) {
F_57 ( & V_144 ) ;
F_58 ( & V_145 , V_2 -> V_143 ) ;
F_59 ( & V_144 ) ;
}
F_60 ( F_61 ( & V_2 -> V_71 ) ) ;
F_32 ( V_2 ) ;
F_62 ( V_123 ) ;
}
void F_63 ( struct V_1 * V_2 ,
struct V_124 * V_125 )
{
int V_146 = 0 ;
if ( V_2 -> V_69 . V_147 != NULL &&
V_2 -> V_69 . V_147 != V_125 )
V_146 = 1 ;
V_2 -> V_69 . V_147 = V_125 ;
memcpy ( & V_2 -> V_69 . V_148 , & V_125 -> V_149 ,
sizeof( union V_150 ) ) ;
if ( ( V_125 -> V_20 == V_151 ) ||
( V_125 -> V_20 == V_152 ) )
V_2 -> V_69 . V_153 = V_125 ;
if ( ! V_2 -> V_92 . V_154 && ! V_2 -> V_92 . V_155 )
return;
if ( V_125 -> V_156 . V_157 )
V_125 -> V_156 . V_158 = V_146 ;
V_125 -> V_156 . V_157 = V_146 ;
V_125 -> V_156 . V_159 = V_2 -> V_76 ;
}
void F_64 ( struct V_1 * V_2 ,
struct V_124 * V_69 )
{
struct V_126 * V_127 ;
struct V_124 * V_125 ;
F_31 ( L_3 ,
V_160 , V_2 , & V_69 -> V_149 . V_161 ) ;
if ( V_2 -> V_69 . V_162 == V_69 )
F_65 ( V_2 ) ;
F_48 ( & V_69 -> V_139 ) ;
F_49 ( V_69 ) ;
V_127 = V_2 -> V_69 . V_85 . V_163 ;
V_125 = F_47 ( V_127 , struct V_124 , V_139 ) ;
if ( V_2 -> V_69 . V_147 == V_69 )
F_63 ( V_2 , V_125 ) ;
if ( V_2 -> V_69 . V_153 == V_69 )
V_2 -> V_69 . V_153 = V_125 ;
if ( V_2 -> V_69 . V_162 == V_69 )
V_2 -> V_69 . V_162 = V_125 ;
if ( V_2 -> V_69 . V_164 == V_69 )
V_2 -> V_69 . V_164 = V_125 ;
if ( V_2 -> V_134 &&
V_2 -> V_134 -> V_125 == V_69 ) {
V_2 -> V_134 -> V_125 = V_125 ;
F_66 ( V_125 ) ;
}
if ( V_2 -> V_165 == V_69 )
V_2 -> V_165 = NULL ;
if ( V_2 -> V_166 == V_69 )
V_2 -> V_166 = NULL ;
if ( V_2 -> V_167 &&
V_2 -> V_167 -> V_125 == V_69 )
V_2 -> V_167 -> V_125 = NULL ;
if ( ! F_34 ( & V_69 -> V_168 ) ) {
struct V_124 * V_169 = V_2 -> V_69 . V_153 ;
struct V_170 * V_171 ;
F_67 (ch, &peer->transmitted,
transmitted_list) {
V_171 -> V_125 = NULL ;
V_171 -> V_172 = 0 ;
}
F_68 ( & V_69 -> V_168 ,
& V_169 -> V_168 ) ;
if ( ! F_69 ( & V_169 -> V_173 ) )
if ( ! F_70 ( & V_169 -> V_173 ,
V_174 + V_169 -> V_175 ) )
F_71 ( V_169 ) ;
}
V_2 -> V_69 . V_140 -- ;
F_50 ( V_69 ) ;
}
struct V_124 * F_72 ( struct V_1 * V_2 ,
const union V_150 * V_176 ,
const T_2 V_8 ,
const int V_177 )
{
struct V_9 * V_9 = F_2 ( V_2 -> V_15 . V_6 ) ;
struct V_124 * V_69 ;
struct V_10 * V_11 ;
unsigned short V_19 ;
V_11 = F_3 ( V_2 -> V_15 . V_6 ) ;
V_19 = F_22 ( V_176 -> V_178 . V_179 ) ;
F_31 ( L_4 , V_160 ,
V_2 , & V_176 -> V_161 , V_177 ) ;
if ( 0 == V_2 -> V_69 . V_19 )
V_2 -> V_69 . V_19 = V_19 ;
V_69 = F_73 ( V_2 , V_176 ) ;
if ( V_69 ) {
if ( V_69 -> V_20 == V_152 ) {
V_69 -> V_20 = V_151 ;
}
return V_69 ;
}
V_69 = F_74 ( V_9 , V_176 , V_8 ) ;
if ( ! V_69 )
return NULL ;
F_75 ( V_69 , V_2 ) ;
V_69 -> V_37 = V_2 -> V_37 ;
V_69 -> V_38 = V_2 -> V_38 ;
V_69 -> V_28 = V_2 -> V_28 ;
V_69 -> V_40 = V_2 -> V_40 ;
V_69 -> V_41 = V_2 -> V_41 ;
V_69 -> V_42 = V_2 -> V_42 ;
F_76 ( V_69 , NULL , V_11 ) ;
if ( V_69 -> V_42 & V_180 ) {
if ( V_2 -> V_39 )
V_69 -> V_39 = V_2 -> V_39 ;
else
V_69 -> V_39 = V_181 ;
}
if ( V_2 -> V_39 )
V_2 -> V_39 = F_77 ( int , V_69 -> V_39 , V_2 -> V_39 ) ;
else
V_2 -> V_39 = V_69 -> V_39 ;
F_31 ( L_5 , V_160 , V_2 ,
V_2 -> V_39 ) ;
V_69 -> V_182 = 0 ;
V_2 -> V_183 = F_78 ( V_2 , V_2 -> V_39 ) ;
F_79 ( & V_69 -> V_184 , V_69 , V_2 -> V_15 . V_18 . V_19 ,
V_2 -> V_69 . V_19 ) ;
V_69 -> V_185 = F_80 ( 4 * V_2 -> V_39 , F_81 ( V_186 , 2 * V_2 -> V_39 , 4380 ) ) ;
V_69 -> V_187 = V_70 ;
V_69 -> V_188 = 0 ;
V_69 -> V_189 = 0 ;
V_69 -> V_190 = 0 ;
V_69 -> V_175 = V_2 -> V_30 ;
F_82 ( V_2 , V_69 ) ;
V_69 -> V_20 = V_177 ;
if ( F_83 ( V_69 ) ) {
F_50 ( V_69 ) ;
return NULL ;
}
F_84 ( & V_69 -> V_139 , & V_2 -> V_69 . V_85 ) ;
V_2 -> V_69 . V_140 ++ ;
if ( ! V_2 -> V_69 . V_147 ) {
F_63 ( V_2 , V_69 ) ;
V_2 -> V_69 . V_162 = V_69 ;
}
if ( V_2 -> V_69 . V_153 == V_2 -> V_69 . V_162 &&
V_69 -> V_20 != V_191 ) {
V_2 -> V_69 . V_162 = V_69 ;
}
return V_69 ;
}
void F_85 ( struct V_1 * V_2 ,
const union V_150 * V_176 )
{
struct V_126 * V_127 ;
struct V_126 * V_128 ;
struct V_124 * V_125 ;
F_46 (pos, temp, &asoc->peer.transport_addr_list) {
V_125 = F_47 ( V_127 , struct V_124 , V_139 ) ;
if ( F_86 ( V_176 , & V_125 -> V_149 ) ) {
F_64 ( V_2 , V_125 ) ;
break;
}
}
}
struct V_124 * F_73 (
const struct V_1 * V_2 ,
const union V_150 * V_192 )
{
struct V_124 * V_193 ;
F_67 (t, &asoc->peer.transport_addr_list,
transports) {
if ( F_86 ( V_192 , & V_193 -> V_149 ) )
return V_193 ;
}
return NULL ;
}
void F_87 ( struct V_1 * V_2 ,
struct V_124 * V_194 )
{
struct V_124 * V_128 ;
struct V_124 * V_193 ;
F_88 (t, temp, &asoc->peer.transport_addr_list,
transports) {
if ( V_193 != V_194 )
F_64 ( V_2 , V_193 ) ;
}
}
void F_89 ( struct V_1 * V_2 ,
struct V_124 * V_125 ,
T_3 V_195 ,
T_4 error )
{
struct V_196 * V_197 ;
struct V_198 V_176 ;
int V_199 = 0 ;
bool V_200 = true ;
switch ( V_195 ) {
case V_201 :
if ( V_191 == V_125 -> V_20 &&
V_202 == error )
V_199 = V_203 ;
else
V_199 = V_204 ;
if ( V_125 -> V_20 == V_205 ) {
V_200 = false ;
V_125 -> V_185 = V_2 -> V_39 ;
}
V_125 -> V_20 = V_151 ;
break;
case V_206 :
if ( V_125 -> V_20 != V_191 )
V_125 -> V_20 = V_207 ;
else {
F_90 ( V_125 ) ;
V_200 = false ;
}
V_199 = V_208 ;
break;
case V_209 :
V_125 -> V_20 = V_205 ;
V_200 = false ;
break;
default:
return;
}
if ( V_200 ) {
memset ( & V_176 , 0 , sizeof( struct V_198 ) ) ;
memcpy ( & V_176 , & V_125 -> V_149 ,
V_125 -> V_210 -> V_211 ) ;
V_197 = F_91 ( V_2 , & V_176 ,
0 , V_199 , error , V_212 ) ;
if ( V_197 )
F_92 ( & V_2 -> V_93 , V_197 ) ;
}
F_93 ( V_2 ) ;
}
void F_94 ( struct V_1 * V_2 )
{
F_95 ( & V_2 -> V_15 . V_17 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
if ( F_96 ( & V_2 -> V_15 . V_17 ) )
F_54 ( V_2 ) ;
}
V_186 F_97 ( struct V_1 * V_2 )
{
V_186 V_213 = V_2 -> V_76 ;
V_2 -> V_76 ++ ;
V_2 -> V_214 ++ ;
return V_213 ;
}
int F_86 ( const union V_150 * V_215 ,
const union V_150 * V_216 )
{
struct V_217 * V_218 ;
V_218 = F_98 ( V_215 -> V_161 . V_219 ) ;
if ( F_55 ( ! V_218 ) )
return 0 ;
return V_218 -> V_220 ( V_215 , V_216 ) ;
}
struct V_170 * F_99 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_221 )
return NULL ;
return F_100 ( V_2 , V_2 -> V_222 ) ;
}
struct V_124 * F_101 ( struct V_1 * V_2 ,
V_186 V_223 )
{
struct V_124 * V_169 ;
struct V_124 * V_224 ;
struct V_124 * V_125 ;
struct V_170 * V_225 ;
T_5 V_226 = F_102 ( V_223 ) ;
V_224 = NULL ;
V_169 = V_2 -> V_69 . V_153 ;
F_67 (chunk, &active->transmitted,
transmitted_list) {
if ( V_226 == V_225 -> V_227 . V_228 -> V_223 ) {
V_224 = V_169 ;
goto V_229;
}
}
F_67 (transport, &asoc->peer.transport_addr_list,
transports) {
if ( V_125 == V_169 )
continue;
F_67 (chunk, &transport->transmitted,
transmitted_list) {
if ( V_226 == V_225 -> V_227 . V_228 -> V_223 ) {
V_224 = V_125 ;
goto V_229;
}
}
}
V_229:
return V_224 ;
}
struct V_124 * F_103 ( struct V_1 * V_2 ,
struct V_9 * V_9 ,
const union V_150 * V_230 ,
const union V_150 * V_231 )
{
struct V_124 * V_125 ;
if ( ( F_23 ( V_2 -> V_15 . V_18 . V_19 ) == V_230 -> V_178 . V_179 ) &&
( F_23 ( V_2 -> V_69 . V_19 ) == V_231 -> V_178 . V_179 ) &&
F_104 ( F_2 ( V_2 -> V_15 . V_6 ) , V_9 ) ) {
V_125 = F_73 ( V_2 , V_231 ) ;
if ( ! V_125 )
goto V_229;
if ( F_105 ( & V_2 -> V_15 . V_18 , V_230 ,
F_3 ( V_2 -> V_15 . V_6 ) ) )
goto V_229;
}
V_125 = NULL ;
V_229:
return V_125 ;
}
static void V_91 ( struct V_232 * V_233 )
{
struct V_1 * V_2 =
F_106 ( V_233 , struct V_1 ,
V_15 . V_90 . V_234 ) ;
struct V_9 * V_9 = F_2 ( V_2 -> V_15 . V_6 ) ;
struct V_3 * V_4 ;
struct V_170 * V_225 ;
struct V_235 * V_90 ;
int V_20 ;
T_6 V_236 ;
int error = 0 ;
V_4 = V_2 -> V_4 ;
V_90 = & V_2 -> V_15 . V_90 ;
F_94 ( V_2 ) ;
while ( NULL != ( V_225 = F_107 ( V_90 ) ) ) {
V_20 = V_2 -> V_20 ;
V_236 = F_108 ( V_225 -> V_237 -> type ) ;
if ( F_109 ( V_236 . V_225 , V_2 ) && ! V_225 -> V_238 )
continue;
if ( F_110 ( V_225 ) )
V_2 -> V_69 . V_164 = V_225 -> V_125 ;
else {
F_111 ( V_9 , V_239 ) ;
V_2 -> V_240 . V_241 ++ ;
if ( V_225 -> V_237 -> type == V_242 )
V_2 -> V_240 . V_243 ++ ;
}
if ( V_225 -> V_125 )
V_225 -> V_125 -> V_244 = F_112 () ;
error = F_113 ( V_9 , V_245 , V_236 ,
V_20 , V_4 , V_2 , V_225 , V_212 ) ;
if ( V_2 -> V_15 . V_132 )
break;
if ( error && V_225 )
V_225 -> V_246 = 1 ;
}
F_45 ( V_2 ) ;
}
void F_114 ( struct V_1 * V_123 , struct V_5 * V_247 )
{
struct V_10 * V_248 = F_3 ( V_247 ) ;
struct V_5 * V_249 = V_123 -> V_15 . V_6 ;
F_115 ( & V_123 -> V_100 ) ;
if ( F_36 ( V_249 , V_129 ) )
V_249 -> V_131 -- ;
F_27 ( V_123 -> V_4 ) ;
F_26 ( V_123 -> V_15 . V_6 ) ;
V_123 -> V_4 = V_248 -> V_4 ;
F_4 ( V_123 -> V_4 ) ;
V_123 -> V_15 . V_6 = V_247 ;
F_5 ( V_123 -> V_15 . V_6 ) ;
F_116 ( V_248 -> V_4 , V_123 ) ;
}
int F_117 ( struct V_1 * V_2 ,
struct V_1 * V_250 )
{
struct V_124 * V_251 ;
struct V_126 * V_127 , * V_128 ;
V_2 -> V_57 = V_250 -> V_57 ;
V_2 -> V_69 . V_67 = V_250 -> V_69 . V_67 ;
V_2 -> V_69 . V_86 = V_250 -> V_69 . V_86 ;
V_2 -> V_69 . V_252 = V_250 -> V_69 . V_252 ;
V_2 -> V_69 . V_14 = V_250 -> V_69 . V_14 ;
if ( ! F_118 ( & V_2 -> V_69 . V_133 , V_253 ,
V_2 -> V_69 . V_14 . V_75 , V_212 ) )
return - V_254 ;
F_46 (pos, temp, &asoc->peer.transport_addr_list) {
V_251 = F_47 ( V_127 , struct V_124 , V_139 ) ;
if ( ! F_73 ( V_250 , & V_251 -> V_149 ) ) {
F_64 ( V_2 , V_251 ) ;
continue;
}
if ( V_2 -> V_20 >= V_255 )
F_119 ( V_251 ) ;
}
if ( V_2 -> V_20 >= V_255 ) {
V_2 -> V_76 = V_250 -> V_76 ;
V_2 -> V_77 = V_250 -> V_77 ;
V_2 -> V_78 = V_250 -> V_78 ;
F_120 ( & V_2 -> V_95 ) ;
F_121 ( & V_2 -> V_93 ) ;
V_2 -> V_256 = 0 ;
} else {
F_67 (trans, &new->peer.transport_addr_list,
transports)
if ( ! F_73 ( V_2 , & V_251 -> V_149 ) &&
! F_72 ( V_2 , & V_251 -> V_149 ,
V_212 , V_251 -> V_20 ) )
return - V_254 ;
V_2 -> V_77 = V_2 -> V_76 - 1 ;
V_2 -> V_78 = V_2 -> V_77 ;
if ( F_122 ( V_2 , V_257 ) )
F_123 ( & V_2 -> V_95 , & V_250 -> V_95 ) ;
if ( F_124 ( V_2 , V_212 ) )
return - V_254 ;
}
F_32 ( V_2 -> V_69 . V_136 ) ;
V_2 -> V_69 . V_136 = V_250 -> V_69 . V_136 ;
V_250 -> V_69 . V_136 = NULL ;
F_32 ( V_2 -> V_69 . V_137 ) ;
V_2 -> V_69 . V_137 = V_250 -> V_69 . V_137 ;
V_250 -> V_69 . V_137 = NULL ;
F_32 ( V_2 -> V_69 . V_138 ) ;
V_2 -> V_69 . V_138 = V_250 -> V_69 . V_138 ;
V_250 -> V_69 . V_138 = NULL ;
return F_125 ( V_2 , V_212 ) ;
}
static T_7 F_126 ( const struct V_124 * V_251 )
{
switch ( V_251 -> V_20 ) {
case V_151 :
return 3 ;
case V_152 :
return 2 ;
case V_205 :
return 1 ;
default:
return 0 ;
}
}
static struct V_124 * F_127 ( struct V_124 * V_258 ,
struct V_124 * V_259 )
{
if ( V_258 -> V_260 > V_259 -> V_260 ) {
return V_259 ;
} else if ( V_258 -> V_260 == V_259 -> V_260 &&
F_128 ( V_259 -> V_244 ,
V_258 -> V_244 ) ) {
return V_259 ;
} else {
return V_258 ;
}
}
static struct V_124 * F_129 ( struct V_124 * V_261 ,
struct V_124 * V_262 )
{
T_7 V_263 , V_264 ;
if ( V_262 == NULL || V_261 == V_262 )
return V_261 ;
V_263 = F_126 ( V_261 ) ;
V_264 = F_126 ( V_262 ) ;
if ( V_263 > V_264 )
return V_261 ;
else if ( V_263 == V_264 )
return F_127 ( V_262 , V_261 ) ;
else
return V_262 ;
}
void F_65 ( struct V_1 * V_2 )
{
struct V_124 * V_251 = V_2 -> V_69 . V_162 ;
struct V_124 * V_265 = NULL ;
if ( V_2 -> V_69 . V_140 == 1 )
return;
if ( V_2 -> V_69 . V_153 == V_2 -> V_69 . V_162 &&
V_2 -> V_69 . V_153 -> V_20 == V_151 )
return;
for ( V_251 = F_130 ( V_251 , V_139 ) ; 1 ;
V_251 = F_130 ( V_251 , V_139 ) ) {
if ( & V_251 -> V_139 == & V_2 -> V_69 . V_85 )
continue;
if ( V_251 -> V_20 == V_191 )
continue;
V_265 = F_129 ( V_251 , V_265 ) ;
if ( V_265 -> V_20 == V_151 )
break;
if ( V_251 == V_2 -> V_69 . V_162 )
break;
}
V_2 -> V_69 . V_162 = V_265 ;
F_31 ( L_6 ,
V_160 , V_2 , & V_2 -> V_69 . V_162 -> V_149 . V_161 ) ;
}
static void F_93 ( struct V_1 * V_2 )
{
struct V_124 * V_251 , * V_266 = NULL , * V_267 = NULL ;
struct V_124 * V_268 = NULL ;
F_67 (trans, &asoc->peer.transport_addr_list,
transports) {
if ( V_251 -> V_20 == V_207 ||
V_251 -> V_20 == V_191 )
continue;
if ( V_251 -> V_20 == V_205 ) {
V_268 = F_129 ( V_251 , V_268 ) ;
continue;
}
if ( V_266 == NULL ||
F_128 ( V_251 -> V_244 ,
V_266 -> V_244 ) ) {
V_267 = V_266 ;
V_266 = V_251 ;
} else if ( V_267 == NULL ||
F_128 ( V_251 -> V_244 ,
V_267 -> V_244 ) ) {
V_267 = V_251 ;
}
}
if ( ( V_2 -> V_69 . V_147 -> V_20 == V_151 ||
V_2 -> V_69 . V_147 -> V_20 == V_152 ) &&
V_2 -> V_69 . V_147 != V_266 ) {
V_267 = V_266 ;
V_266 = V_2 -> V_69 . V_147 ;
}
if ( V_267 == NULL )
V_267 = V_266 ;
if ( V_266 == NULL ) {
V_266 = F_129 ( V_2 -> V_69 . V_153 , V_268 ) ;
V_267 = V_266 ;
}
V_2 -> V_69 . V_153 = V_266 ;
V_2 -> V_69 . V_162 = V_267 ;
}
struct V_124 *
F_131 ( struct V_1 * V_2 ,
struct V_124 * V_269 )
{
if ( V_269 == NULL ) {
return V_2 -> V_69 . V_153 ;
} else {
if ( V_269 == V_2 -> V_69 . V_162 )
F_65 ( V_2 ) ;
return V_2 -> V_69 . V_162 ;
}
}
void F_132 ( struct V_1 * V_2 )
{
struct V_124 * V_193 ;
V_186 V_270 = 0 ;
if ( ! V_2 )
return;
F_67 (t, &asoc->peer.transport_addr_list,
transports) {
if ( V_193 -> V_182 && V_193 -> V_271 ) {
F_133 (
V_193 , F_134 ( F_135 ( V_193 -> V_271 ) ) ) ;
V_193 -> V_182 = 0 ;
}
if ( ! V_270 || ( V_193 -> V_39 < V_270 ) )
V_270 = V_193 -> V_39 ;
}
if ( V_270 ) {
V_2 -> V_39 = V_270 ;
V_2 -> V_183 = F_78 ( V_2 , V_270 ) ;
}
F_31 ( L_7 , V_160 , V_2 ,
V_2 -> V_39 , V_2 -> V_183 ) ;
}
static inline bool F_136 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_2 ( V_2 -> V_15 . V_6 ) ;
switch ( V_2 -> V_20 ) {
case V_255 :
case V_272 :
case V_273 :
case V_274 :
if ( ( V_2 -> V_67 > V_2 -> V_68 ) &&
( ( V_2 -> V_67 - V_2 -> V_68 ) >= F_81 ( V_186 ,
( V_2 -> V_15 . V_6 -> V_65 >> V_9 -> V_29 . V_275 ) ,
V_2 -> V_39 ) ) )
return true ;
break;
default:
break;
}
return false ;
}
void F_137 ( struct V_1 * V_2 , unsigned int V_276 )
{
struct V_170 * V_277 ;
struct V_278 * V_279 ;
if ( V_2 -> V_280 ) {
if ( V_2 -> V_280 >= V_276 ) {
V_2 -> V_280 -= V_276 ;
} else {
V_2 -> V_67 += ( V_276 - V_2 -> V_280 ) ;
V_2 -> V_280 = 0 ;
}
} else {
V_2 -> V_67 += V_276 ;
}
if ( V_2 -> V_281 ) {
int V_282 = F_80 ( V_2 -> V_39 , V_2 -> V_281 ) ;
V_2 -> V_67 += V_282 ;
V_2 -> V_281 -= V_282 ;
}
F_31 ( L_8 ,
V_160 , V_2 , V_276 , V_2 -> V_67 , V_2 -> V_280 ,
V_2 -> V_68 ) ;
if ( F_136 ( V_2 ) ) {
V_2 -> V_68 = V_2 -> V_67 ;
F_31 ( L_9
L_10 , V_160 , V_2 , V_2 -> V_67 ,
V_2 -> V_68 ) ;
V_277 = F_138 ( V_2 ) ;
if ( ! V_277 )
return;
V_2 -> V_69 . V_86 = 0 ;
F_139 ( & V_2 -> V_92 , V_277 , V_212 ) ;
V_279 = & V_2 -> V_55 [ V_49 ] ;
if ( F_44 ( V_279 ) )
F_45 ( V_2 ) ;
}
}
void F_140 ( struct V_1 * V_2 , unsigned int V_276 )
{
int V_283 ;
int V_284 = 0 ;
if ( F_55 ( ! V_2 -> V_67 || V_2 -> V_280 ) )
F_31 ( L_11
L_12 , V_160 , V_2 ,
V_2 -> V_67 , V_2 -> V_280 ) ;
if ( V_2 -> V_4 -> V_285 )
V_283 = F_61 ( & V_2 -> V_71 ) ;
else
V_283 = F_61 ( & V_2 -> V_15 . V_6 -> V_286 ) ;
if ( V_283 >= V_2 -> V_15 . V_6 -> V_65 )
V_284 = 1 ;
if ( V_2 -> V_67 >= V_276 ) {
V_2 -> V_67 -= V_276 ;
if ( V_284 ) {
V_2 -> V_281 += V_2 -> V_67 ;
V_2 -> V_67 = 0 ;
}
} else {
V_2 -> V_280 += V_276 - V_2 -> V_67 ;
V_2 -> V_67 = 0 ;
}
F_31 ( L_13 ,
V_160 , V_2 , V_276 , V_2 -> V_67 , V_2 -> V_280 ,
V_2 -> V_281 ) ;
}
int F_141 ( struct V_1 * V_2 ,
T_1 V_7 , T_2 V_8 )
{
int V_287 ;
V_287 = ( V_98 == V_2 -> V_15 . V_6 -> V_97 ) ? V_288 : 0 ;
if ( V_2 -> V_69 . V_96 )
V_287 |= V_289 ;
if ( V_2 -> V_69 . V_99 )
V_287 |= V_290 ;
return F_142 ( F_2 ( V_2 -> V_15 . V_6 ) ,
& V_2 -> V_15 . V_18 ,
& V_2 -> V_4 -> V_15 . V_18 ,
V_7 , V_8 , V_287 ) ;
}
int F_143 ( struct V_1 * V_2 ,
struct V_291 * V_135 ,
T_2 V_8 )
{
int V_292 = F_22 ( V_135 -> V_293 -> V_237 . V_116 ) ;
int V_294 = V_135 -> V_295 ;
T_8 * V_296 = ( T_8 * ) V_135 -> V_293 + V_292 ;
return F_144 ( & V_2 -> V_15 . V_18 , V_296 , V_294 ,
V_2 -> V_4 -> V_15 . V_18 . V_19 , V_8 ) ;
}
int F_145 ( struct V_1 * V_2 ,
const union V_150 * V_230 )
{
int V_297 = 0 ;
if ( ( V_2 -> V_15 . V_18 . V_19 == F_22 ( V_230 -> V_178 . V_179 ) ) &&
F_105 ( & V_2 -> V_15 . V_18 , V_230 ,
F_3 ( V_2 -> V_15 . V_6 ) ) )
V_297 = 1 ;
return V_297 ;
}
int F_124 ( struct V_1 * V_2 , T_2 V_8 )
{
bool V_298 = F_146 ( V_8 ) ;
int V_299 ;
if ( V_2 -> V_143 )
return 0 ;
if ( V_298 )
F_147 ( V_8 ) ;
F_57 ( & V_144 ) ;
V_299 = F_148 ( & V_145 , V_2 , 1 , 0 , V_300 ) ;
F_59 ( & V_144 ) ;
if ( V_298 )
F_149 () ;
if ( V_299 < 0 )
return V_299 ;
V_2 -> V_143 = ( V_301 ) V_299 ;
return 0 ;
}
static void F_150 ( struct V_1 * V_2 )
{
struct V_170 * V_302 ;
struct V_170 * V_303 ;
F_88 (asconf, tmp, &asoc->addip_chunk_list, list) {
F_115 ( & V_302 -> V_304 ) ;
F_42 ( V_302 ) ;
}
}
static void F_151 ( struct V_1 * V_2 )
{
struct V_170 * V_305 ;
struct V_170 * V_303 ;
F_88 (ack, tmp, &asoc->asconf_ack_list,
transmitted_list) {
F_115 ( & V_305 -> V_306 ) ;
F_42 ( V_305 ) ;
}
}
void F_152 ( const struct V_1 * V_2 )
{
struct V_170 * V_305 ;
struct V_170 * V_303 ;
F_88 (ack, tmp, &asoc->asconf_ack_list,
transmitted_list) {
if ( V_305 -> V_227 . V_307 -> V_308 ==
F_102 ( V_2 -> V_69 . V_81 ) )
break;
F_115 ( & V_305 -> V_306 ) ;
F_42 ( V_305 ) ;
}
}
struct V_170 * F_153 (
const struct V_1 * V_2 ,
T_5 V_308 )
{
struct V_170 * V_305 ;
F_67 (ack, &asoc->asconf_ack_list, transmitted_list) {
if ( F_154 ( V_305 ) )
continue;
if ( V_305 -> V_227 . V_307 -> V_308 == V_308 ) {
F_155 ( V_305 ) ;
return V_305 ;
}
}
return NULL ;
}
void F_51 ( struct V_1 * V_2 )
{
F_151 ( V_2 ) ;
F_150 ( V_2 ) ;
if ( V_2 -> V_167 )
F_42 ( V_2 -> V_167 ) ;
}
