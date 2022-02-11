static struct V_1 * F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_5 * V_6 ,
T_1 V_7 ,
T_2 V_8 )
{
struct V_9 * V_9 = F_2 ( V_6 ) ;
struct V_10 * V_11 ;
T_3 * V_12 ;
int V_13 ;
V_11 = F_3 ( (struct V_5 * ) V_6 ) ;
V_2 -> V_4 = (struct V_3 * ) V_4 ;
V_2 -> V_14 . V_6 = (struct V_5 * ) V_6 ;
F_4 ( V_2 -> V_4 ) ;
F_5 ( V_2 -> V_14 . V_6 ) ;
V_2 -> V_14 . type = V_15 ;
F_6 ( & V_2 -> V_14 . V_16 , 1 ) ;
F_7 ( & V_2 -> V_14 . V_17 , V_4 -> V_14 . V_17 . V_18 ) ;
V_2 -> V_19 = V_20 ;
V_2 -> V_21 = F_8 ( V_11 -> V_22 . V_23 ) ;
V_2 -> V_24 = V_11 -> V_24 ;
V_2 -> V_25 = V_11 -> V_22 . V_26 ;
V_2 -> V_27 = V_9 -> V_28 . V_27 ;
V_2 -> V_29 = F_9 ( V_11 -> V_30 . V_31 ) ;
V_2 -> V_32 = F_9 ( V_11 -> V_30 . V_33 ) ;
V_2 -> V_34 = F_9 ( V_11 -> V_30 . V_35 ) ;
V_2 -> V_36 = F_9 ( V_11 -> V_36 ) ;
V_2 -> V_37 = V_11 -> V_37 ;
V_2 -> V_38 = V_11 -> V_38 ;
V_2 -> V_39 = F_9 ( V_11 -> V_39 ) ;
V_2 -> V_40 = V_11 -> V_40 ;
V_2 -> V_41 = V_11 -> V_41 ;
V_2 -> V_42 = V_11 -> V_42 ;
V_2 -> V_43 [ V_44 ] = V_2 -> V_29 ;
V_2 -> V_43 [ V_45 ] = V_2 -> V_29 ;
V_2 -> V_43 [ V_46 ] = V_2 -> V_29 ;
V_2 -> V_43 [ V_47 ]
= 5 * V_2 -> V_32 ;
V_2 -> V_43 [ V_48 ] = V_2 -> V_39 ;
V_2 -> V_43 [ V_49 ] = V_11 -> V_50 * V_51 ;
for ( V_13 = V_52 ; V_13 < V_53 ; ++ V_13 )
F_10 ( & V_2 -> V_54 [ V_13 ] , V_55 [ V_13 ] ,
( unsigned long ) V_2 ) ;
V_2 -> V_56 . V_57 = V_11 -> V_58 . V_57 ;
V_2 -> V_56 . V_59 = V_11 -> V_58 . V_59 ;
V_2 -> V_60 = V_11 -> V_58 . V_61 ;
V_2 -> V_62 =
F_9 ( V_11 -> V_58 . V_63 ) ;
if ( ( V_6 -> V_64 / 2 ) < V_65 )
V_2 -> V_66 = V_65 ;
else
V_2 -> V_66 = V_6 -> V_64 / 2 ;
V_2 -> V_67 = V_2 -> V_66 ;
V_2 -> V_68 . V_66 = V_69 ;
F_6 ( & V_2 -> V_70 , 0 ) ;
F_11 ( & V_2 -> V_71 ) ;
V_2 -> V_56 . V_72 = F_12 ( V_4 ) ;
V_2 -> V_56 . V_73 = V_4 -> V_14 . V_17 . V_18 ;
V_2 -> V_56 . V_74 = F_13 ( V_4 ) ;
V_2 -> V_75 = V_2 -> V_56 . V_74 ;
V_2 -> V_76 = V_2 -> V_75 - 1 ;
V_2 -> V_77 = V_2 -> V_76 ;
V_2 -> V_78 = V_2 -> V_76 ;
V_2 -> V_79 = V_2 -> V_76 ;
V_2 -> V_80 = V_2 -> V_56 . V_74 ;
V_2 -> V_81 = V_2 -> V_56 . V_74 ;
F_14 ( & V_2 -> V_82 ) ;
F_14 ( & V_2 -> V_83 ) ;
F_14 ( & V_2 -> V_68 . V_84 ) ;
V_2 -> V_68 . V_85 = 1 ;
V_2 -> V_68 . V_86 = 1 ;
if ( V_9 -> V_28 . V_87 )
V_2 -> V_68 . V_88 = 1 ;
F_15 ( & V_2 -> V_14 . V_89 ) ;
F_16 ( & V_2 -> V_14 . V_89 , V_90 ) ;
F_17 ( V_2 , & V_2 -> V_91 ) ;
if ( ! F_18 ( & V_2 -> V_92 , V_2 ) )
goto V_93;
if ( F_19 ( V_2 , V_8 ) )
goto V_93;
V_2 -> V_68 . V_94 = 1 ;
if ( V_2 -> V_14 . V_6 -> V_95 == V_96 )
V_2 -> V_68 . V_97 = 1 ;
F_14 ( & V_2 -> V_98 ) ;
V_2 -> V_99 = V_11 -> V_99 ;
V_2 -> V_100 = V_11 -> V_100 ;
V_2 -> V_101 = V_11 -> V_101 ;
V_2 -> V_102 = V_11 -> V_102 ;
V_2 -> V_103 = V_11 -> V_103 ;
V_2 -> V_104 = V_11 -> V_104 ;
F_14 ( & V_2 -> V_105 ) ;
if ( F_20 ( V_4 , V_2 , V_8 ) )
goto V_106;
V_2 -> V_107 = V_4 -> V_107 ;
V_2 -> V_108 = V_4 -> V_108 ;
V_2 -> V_109 = V_4 -> V_109 ;
V_2 -> V_110 = V_4 -> V_110 ;
if ( V_4 -> V_111 )
memcpy ( V_2 -> V_56 . V_112 , V_4 -> V_111 ,
F_21 ( V_4 -> V_111 -> V_113 . V_114 ) ) ;
if ( V_4 -> V_115 )
memcpy ( V_2 -> V_56 . V_116 , V_4 -> V_115 ,
F_21 ( V_4 -> V_115 -> V_113 . V_114 ) ) ;
V_12 = ( T_3 * ) V_2 -> V_56 . V_117 ;
V_12 -> type = V_118 ;
V_12 -> V_114 = F_22 ( sizeof( T_3 ) + V_119 ) ;
F_23 ( V_12 + 1 , V_119 ) ;
return V_2 ;
V_106:
F_24 ( V_2 -> V_120 ) ;
V_93:
F_25 ( V_2 -> V_14 . V_6 ) ;
F_26 ( V_2 -> V_4 ) ;
return NULL ;
}
struct V_1 * F_27 ( const struct V_3 * V_4 ,
const struct V_5 * V_6 ,
T_1 V_7 ,
T_2 V_8 )
{
struct V_1 * V_2 ;
V_2 = F_28 ( sizeof( * V_2 ) , V_8 ) ;
if ( ! V_2 )
goto V_121;
if ( ! F_1 ( V_2 , V_4 , V_6 , V_7 , V_8 ) )
goto V_93;
F_29 ( V_122 ) ;
F_30 ( L_1 , V_2 ) ;
return V_2 ;
V_93:
F_31 ( V_2 ) ;
V_121:
return NULL ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_14 . V_6 ;
struct V_123 * V_124 ;
struct V_125 * V_126 , * V_127 ;
int V_13 ;
if ( ! F_33 ( & V_2 -> V_98 ) ) {
F_34 ( & V_2 -> V_98 ) ;
if ( F_35 ( V_6 , V_128 ) && F_36 ( V_6 , V_129 ) )
V_6 -> V_130 -- ;
}
V_2 -> V_14 . V_131 = true ;
F_37 ( & V_2 -> V_91 ) ;
F_38 ( & V_2 -> V_92 ) ;
F_39 ( & V_2 -> V_14 . V_89 ) ;
F_40 ( & V_2 -> V_68 . V_132 ) ;
F_24 ( V_2 -> V_120 ) ;
if ( V_2 -> V_133 )
F_41 ( V_2 -> V_133 ) ;
F_42 ( & V_2 -> V_14 . V_17 ) ;
for ( V_13 = V_52 ; V_13 < V_53 ; ++ V_13 ) {
if ( F_43 ( & V_2 -> V_54 [ V_13 ] ) )
F_44 ( V_2 ) ;
}
F_31 ( V_2 -> V_68 . V_134 ) ;
F_31 ( V_2 -> V_68 . V_135 ) ;
F_31 ( V_2 -> V_68 . V_136 ) ;
F_31 ( V_2 -> V_68 . V_137 ) ;
F_45 (pos, temp, &asoc->peer.transport_addr_list) {
V_124 = F_46 ( V_126 , struct V_123 , V_138 ) ;
F_47 ( V_126 ) ;
F_48 ( V_124 ) ;
F_49 ( V_124 ) ;
}
V_2 -> V_68 . V_139 = 0 ;
F_50 ( V_2 ) ;
F_31 ( V_2 -> V_140 ) ;
F_51 ( & V_2 -> V_105 ) ;
F_52 ( V_2 -> V_141 ) ;
F_44 ( V_2 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
if ( F_54 ( ! V_2 -> V_14 . V_131 ) ) {
F_55 ( 1 , L_2 , V_2 ) ;
return;
}
F_26 ( V_2 -> V_4 ) ;
F_25 ( V_2 -> V_14 . V_6 ) ;
if ( V_2 -> V_142 != 0 ) {
F_56 ( & V_143 ) ;
F_57 ( & V_144 , V_2 -> V_142 ) ;
F_58 ( & V_143 ) ;
}
F_59 ( F_60 ( & V_2 -> V_70 ) ) ;
F_31 ( V_2 ) ;
F_61 ( V_122 ) ;
}
void F_62 ( struct V_1 * V_2 ,
struct V_123 * V_124 )
{
int V_145 = 0 ;
if ( V_2 -> V_68 . V_146 != NULL &&
V_2 -> V_68 . V_146 != V_124 )
V_145 = 1 ;
V_2 -> V_68 . V_146 = V_124 ;
memcpy ( & V_2 -> V_68 . V_147 , & V_124 -> V_148 ,
sizeof( union V_149 ) ) ;
if ( ( V_124 -> V_19 == V_150 ) ||
( V_124 -> V_19 == V_151 ) )
V_2 -> V_68 . V_152 = V_124 ;
if ( ! V_2 -> V_91 . V_153 && ! V_2 -> V_91 . V_154 )
return;
if ( V_124 -> V_155 . V_156 )
V_124 -> V_155 . V_157 = V_145 ;
V_124 -> V_155 . V_156 = V_145 ;
V_124 -> V_155 . V_158 = V_2 -> V_75 ;
}
void F_63 ( struct V_1 * V_2 ,
struct V_123 * V_68 )
{
struct V_125 * V_126 ;
struct V_123 * V_124 ;
F_30 ( L_3 ,
V_159 , V_2 , & V_68 -> V_148 . V_160 ) ;
if ( V_2 -> V_68 . V_161 == V_68 )
F_64 ( V_2 ) ;
F_47 ( & V_68 -> V_138 ) ;
F_48 ( V_68 ) ;
V_126 = V_2 -> V_68 . V_84 . V_162 ;
V_124 = F_46 ( V_126 , struct V_123 , V_138 ) ;
if ( V_2 -> V_68 . V_146 == V_68 )
F_62 ( V_2 , V_124 ) ;
if ( V_2 -> V_68 . V_152 == V_68 )
V_2 -> V_68 . V_152 = V_124 ;
if ( V_2 -> V_68 . V_161 == V_68 )
V_2 -> V_68 . V_161 = V_124 ;
if ( V_2 -> V_68 . V_163 == V_68 )
V_2 -> V_68 . V_163 = V_124 ;
if ( V_2 -> V_133 &&
V_2 -> V_133 -> V_124 == V_68 ) {
V_2 -> V_133 -> V_124 = V_124 ;
F_65 ( V_124 ) ;
}
if ( V_2 -> V_164 == V_68 )
V_2 -> V_164 = NULL ;
if ( V_2 -> V_165 == V_68 )
V_2 -> V_165 = NULL ;
if ( V_2 -> V_166 &&
V_2 -> V_166 -> V_124 == V_68 )
V_2 -> V_166 -> V_124 = NULL ;
if ( ! F_33 ( & V_68 -> V_167 ) ) {
struct V_123 * V_168 = V_2 -> V_68 . V_152 ;
struct V_169 * V_170 ;
F_66 (ch, &peer->transmitted,
transmitted_list) {
V_170 -> V_124 = NULL ;
V_170 -> V_171 = 0 ;
}
F_67 ( & V_68 -> V_167 ,
& V_168 -> V_167 ) ;
if ( ! F_68 ( & V_168 -> V_172 ) )
if ( ! F_69 ( & V_168 -> V_172 ,
V_173 + V_168 -> V_174 ) )
F_70 ( V_168 ) ;
}
V_2 -> V_68 . V_139 -- ;
F_49 ( V_68 ) ;
}
struct V_123 * F_71 ( struct V_1 * V_2 ,
const union V_149 * V_175 ,
const T_2 V_8 ,
const int V_176 )
{
struct V_9 * V_9 = F_2 ( V_2 -> V_14 . V_6 ) ;
struct V_123 * V_68 ;
struct V_10 * V_11 ;
unsigned short V_18 ;
V_11 = F_3 ( V_2 -> V_14 . V_6 ) ;
V_18 = F_21 ( V_175 -> V_177 . V_178 ) ;
F_30 ( L_4 , V_159 ,
V_2 , & V_175 -> V_160 , V_176 ) ;
if ( 0 == V_2 -> V_68 . V_18 )
V_2 -> V_68 . V_18 = V_18 ;
V_68 = F_72 ( V_2 , V_175 ) ;
if ( V_68 ) {
if ( V_68 -> V_19 == V_151 ) {
V_68 -> V_19 = V_150 ;
}
return V_68 ;
}
V_68 = F_73 ( V_9 , V_175 , V_8 ) ;
if ( ! V_68 )
return NULL ;
F_74 ( V_68 , V_2 ) ;
V_68 -> V_36 = V_2 -> V_36 ;
V_68 -> V_37 = V_2 -> V_37 ;
V_68 -> V_27 = V_2 -> V_27 ;
V_68 -> V_39 = V_2 -> V_39 ;
V_68 -> V_40 = V_2 -> V_40 ;
V_68 -> V_41 = V_2 -> V_41 ;
F_75 ( V_68 , NULL , V_11 ) ;
if ( V_68 -> V_41 & V_179 ) {
if ( V_2 -> V_38 )
V_68 -> V_38 = V_2 -> V_38 ;
else
V_68 -> V_38 = V_180 ;
}
if ( V_2 -> V_38 )
V_2 -> V_38 = F_76 ( int , V_68 -> V_38 , V_2 -> V_38 ) ;
else
V_2 -> V_38 = V_68 -> V_38 ;
F_30 ( L_5 , V_159 , V_2 ,
V_2 -> V_38 ) ;
V_68 -> V_181 = 0 ;
V_2 -> V_182 = F_77 ( V_2 , V_2 -> V_38 ) ;
F_78 ( & V_68 -> V_183 , V_68 , V_2 -> V_14 . V_17 . V_18 ,
V_2 -> V_68 . V_18 ) ;
V_68 -> V_184 = F_79 ( 4 * V_2 -> V_38 , F_80 ( V_185 , 2 * V_2 -> V_38 , 4380 ) ) ;
V_68 -> V_186 = V_69 ;
V_68 -> V_187 = 0 ;
V_68 -> V_188 = 0 ;
V_68 -> V_189 = 0 ;
V_68 -> V_174 = V_2 -> V_29 ;
F_81 ( V_2 , V_68 ) ;
V_68 -> V_19 = V_176 ;
if ( F_82 ( V_68 ) ) {
F_49 ( V_68 ) ;
return NULL ;
}
F_83 ( & V_68 -> V_138 , & V_2 -> V_68 . V_84 ) ;
V_2 -> V_68 . V_139 ++ ;
if ( ! V_2 -> V_68 . V_146 ) {
F_62 ( V_2 , V_68 ) ;
V_2 -> V_68 . V_161 = V_68 ;
}
if ( V_2 -> V_68 . V_152 == V_2 -> V_68 . V_161 &&
V_68 -> V_19 != V_190 ) {
V_2 -> V_68 . V_161 = V_68 ;
}
return V_68 ;
}
void F_84 ( struct V_1 * V_2 ,
const union V_149 * V_175 )
{
struct V_125 * V_126 ;
struct V_125 * V_127 ;
struct V_123 * V_124 ;
F_45 (pos, temp, &asoc->peer.transport_addr_list) {
V_124 = F_46 ( V_126 , struct V_123 , V_138 ) ;
if ( F_85 ( V_175 , & V_124 -> V_148 ) ) {
F_63 ( V_2 , V_124 ) ;
break;
}
}
}
struct V_123 * F_72 (
const struct V_1 * V_2 ,
const union V_149 * V_191 )
{
struct V_123 * V_192 ;
F_66 (t, &asoc->peer.transport_addr_list,
transports) {
if ( F_85 ( V_191 , & V_192 -> V_148 ) )
return V_192 ;
}
return NULL ;
}
void F_86 ( struct V_1 * V_2 ,
struct V_123 * V_193 )
{
struct V_123 * V_127 ;
struct V_123 * V_192 ;
F_87 (t, temp, &asoc->peer.transport_addr_list,
transports) {
if ( V_192 != V_193 )
F_63 ( V_2 , V_192 ) ;
}
}
void F_88 ( struct V_1 * V_2 ,
struct V_123 * V_124 ,
T_4 V_194 ,
T_5 error )
{
struct V_195 * V_196 ;
struct V_197 V_175 ;
int V_198 = 0 ;
bool V_199 = true ;
switch ( V_194 ) {
case V_200 :
if ( V_190 == V_124 -> V_19 &&
V_201 == error )
V_198 = V_202 ;
else
V_198 = V_203 ;
if ( V_124 -> V_19 == V_204 ) {
V_199 = false ;
V_124 -> V_184 = V_2 -> V_38 ;
}
V_124 -> V_19 = V_150 ;
break;
case V_205 :
if ( V_124 -> V_19 != V_190 )
V_124 -> V_19 = V_206 ;
else {
F_89 ( V_124 ) ;
V_199 = false ;
}
V_198 = V_207 ;
break;
case V_208 :
V_124 -> V_19 = V_204 ;
V_199 = false ;
break;
default:
return;
}
if ( V_199 ) {
memset ( & V_175 , 0 , sizeof( struct V_197 ) ) ;
memcpy ( & V_175 , & V_124 -> V_148 ,
V_124 -> V_209 -> V_210 ) ;
V_196 = F_90 ( V_2 , & V_175 ,
0 , V_198 , error , V_211 ) ;
if ( V_196 )
F_91 ( & V_2 -> V_92 , V_196 ) ;
}
F_92 ( V_2 ) ;
}
void F_93 ( struct V_1 * V_2 )
{
F_94 ( & V_2 -> V_14 . V_16 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
if ( F_95 ( & V_2 -> V_14 . V_16 ) )
F_53 ( V_2 ) ;
}
V_185 F_96 ( struct V_1 * V_2 )
{
V_185 V_212 = V_2 -> V_75 ;
V_2 -> V_75 ++ ;
V_2 -> V_213 ++ ;
return V_212 ;
}
int F_85 ( const union V_149 * V_214 ,
const union V_149 * V_215 )
{
struct V_216 * V_217 ;
V_217 = F_97 ( V_214 -> V_160 . V_218 ) ;
if ( F_54 ( ! V_217 ) )
return 0 ;
return V_217 -> V_219 ( V_214 , V_215 ) ;
}
struct V_169 * F_98 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_220 )
return NULL ;
return F_99 ( V_2 , V_2 -> V_221 ) ;
}
struct V_123 * F_100 ( struct V_1 * V_2 ,
V_185 V_222 )
{
struct V_123 * V_168 ;
struct V_123 * V_223 ;
struct V_123 * V_124 ;
struct V_169 * V_224 ;
T_6 V_225 = F_101 ( V_222 ) ;
V_223 = NULL ;
V_168 = V_2 -> V_68 . V_152 ;
F_66 (chunk, &active->transmitted,
transmitted_list) {
if ( V_225 == V_224 -> V_226 . V_227 -> V_222 ) {
V_223 = V_168 ;
goto V_228;
}
}
F_66 (transport, &asoc->peer.transport_addr_list,
transports) {
if ( V_124 == V_168 )
continue;
F_66 (chunk, &transport->transmitted,
transmitted_list) {
if ( V_225 == V_224 -> V_226 . V_227 -> V_222 ) {
V_223 = V_124 ;
goto V_228;
}
}
}
V_228:
return V_223 ;
}
struct V_123 * F_102 ( struct V_1 * V_2 ,
struct V_9 * V_9 ,
const union V_149 * V_229 ,
const union V_149 * V_230 )
{
struct V_123 * V_124 ;
if ( ( F_22 ( V_2 -> V_14 . V_17 . V_18 ) == V_229 -> V_177 . V_178 ) &&
( F_22 ( V_2 -> V_68 . V_18 ) == V_230 -> V_177 . V_178 ) &&
F_103 ( F_2 ( V_2 -> V_14 . V_6 ) , V_9 ) ) {
V_124 = F_72 ( V_2 , V_230 ) ;
if ( ! V_124 )
goto V_228;
if ( F_104 ( & V_2 -> V_14 . V_17 , V_229 ,
F_3 ( V_2 -> V_14 . V_6 ) ) )
goto V_228;
}
V_124 = NULL ;
V_228:
return V_124 ;
}
static void V_90 ( struct V_231 * V_232 )
{
struct V_1 * V_2 =
F_105 ( V_232 , struct V_1 ,
V_14 . V_89 . V_233 ) ;
struct V_9 * V_9 = F_2 ( V_2 -> V_14 . V_6 ) ;
struct V_3 * V_4 ;
struct V_169 * V_224 ;
struct V_234 * V_89 ;
int V_19 ;
T_7 V_235 ;
int error = 0 ;
V_4 = V_2 -> V_4 ;
V_89 = & V_2 -> V_14 . V_89 ;
F_93 ( V_2 ) ;
while ( NULL != ( V_224 = F_106 ( V_89 ) ) ) {
V_19 = V_2 -> V_19 ;
V_235 = F_107 ( V_224 -> V_236 -> type ) ;
if ( F_108 ( V_235 . V_224 , V_2 ) && ! V_224 -> V_237 )
continue;
if ( F_109 ( V_224 ) )
V_2 -> V_68 . V_163 = V_224 -> V_124 ;
else {
F_110 ( V_9 , V_238 ) ;
V_2 -> V_239 . V_240 ++ ;
if ( V_224 -> V_236 -> type == V_241 )
V_2 -> V_239 . V_242 ++ ;
}
if ( V_224 -> V_124 )
V_224 -> V_124 -> V_243 = F_111 () ;
error = F_112 ( V_9 , V_244 , V_235 ,
V_19 , V_4 , V_2 , V_224 , V_211 ) ;
if ( V_2 -> V_14 . V_131 )
break;
if ( error && V_224 )
V_224 -> V_245 = 1 ;
}
F_44 ( V_2 ) ;
}
void F_113 ( struct V_1 * V_122 , struct V_5 * V_246 )
{
struct V_10 * V_247 = F_3 ( V_246 ) ;
struct V_5 * V_248 = V_122 -> V_14 . V_6 ;
F_114 ( & V_122 -> V_98 ) ;
if ( F_35 ( V_248 , V_128 ) )
V_248 -> V_130 -- ;
F_26 ( V_122 -> V_4 ) ;
F_25 ( V_122 -> V_14 . V_6 ) ;
V_122 -> V_4 = V_247 -> V_4 ;
F_4 ( V_122 -> V_4 ) ;
V_122 -> V_14 . V_6 = V_246 ;
F_5 ( V_122 -> V_14 . V_6 ) ;
F_115 ( V_247 -> V_4 , V_122 ) ;
}
void F_116 ( struct V_1 * V_2 ,
struct V_1 * V_249 )
{
struct V_123 * V_250 ;
struct V_125 * V_126 , * V_127 ;
V_2 -> V_56 = V_249 -> V_56 ;
V_2 -> V_68 . V_66 = V_249 -> V_68 . V_66 ;
V_2 -> V_68 . V_85 = V_249 -> V_68 . V_85 ;
V_2 -> V_68 . V_251 = V_249 -> V_68 . V_251 ;
V_2 -> V_68 . V_13 = V_249 -> V_68 . V_13 ;
F_117 ( & V_2 -> V_68 . V_132 , V_252 ,
V_2 -> V_68 . V_13 . V_74 , V_211 ) ;
F_45 (pos, temp, &asoc->peer.transport_addr_list) {
V_250 = F_46 ( V_126 , struct V_123 , V_138 ) ;
if ( ! F_72 ( V_249 , & V_250 -> V_148 ) ) {
F_63 ( V_2 , V_250 ) ;
continue;
}
if ( V_2 -> V_19 >= V_253 )
F_118 ( V_250 ) ;
}
if ( V_2 -> V_19 >= V_253 ) {
V_2 -> V_75 = V_249 -> V_75 ;
V_2 -> V_76 = V_249 -> V_76 ;
V_2 -> V_77 = V_249 -> V_77 ;
F_119 ( V_2 -> V_120 ) ;
F_120 ( & V_2 -> V_92 ) ;
V_2 -> V_254 = 0 ;
} else {
F_66 (trans, &new->peer.transport_addr_list,
transports) {
if ( ! F_72 ( V_2 , & V_250 -> V_148 ) )
F_71 ( V_2 , & V_250 -> V_148 ,
V_211 , V_250 -> V_19 ) ;
}
V_2 -> V_76 = V_2 -> V_75 - 1 ;
V_2 -> V_77 = V_2 -> V_76 ;
if ( ! V_2 -> V_120 ) {
V_2 -> V_120 = V_249 -> V_120 ;
V_249 -> V_120 = NULL ;
}
if ( ! V_2 -> V_142 ) {
F_121 ( V_2 , V_211 ) ;
}
}
F_31 ( V_2 -> V_68 . V_135 ) ;
V_2 -> V_68 . V_135 = V_249 -> V_68 . V_135 ;
V_249 -> V_68 . V_135 = NULL ;
F_31 ( V_2 -> V_68 . V_136 ) ;
V_2 -> V_68 . V_136 = V_249 -> V_68 . V_136 ;
V_249 -> V_68 . V_136 = NULL ;
F_31 ( V_2 -> V_68 . V_137 ) ;
V_2 -> V_68 . V_137 = V_249 -> V_68 . V_137 ;
V_249 -> V_68 . V_137 = NULL ;
F_122 ( V_2 , V_211 ) ;
}
static T_8 F_123 ( const struct V_123 * V_250 )
{
switch ( V_250 -> V_19 ) {
case V_150 :
return 3 ;
case V_151 :
return 2 ;
case V_204 :
return 1 ;
default:
return 0 ;
}
}
static struct V_123 * F_124 ( struct V_123 * V_255 ,
struct V_123 * V_256 )
{
if ( V_255 -> V_257 > V_256 -> V_257 ) {
return V_256 ;
} else if ( V_255 -> V_257 == V_256 -> V_257 &&
F_125 ( V_256 -> V_243 ,
V_255 -> V_243 ) ) {
return V_256 ;
} else {
return V_255 ;
}
}
static struct V_123 * F_126 ( struct V_123 * V_258 ,
struct V_123 * V_259 )
{
T_8 V_260 , V_261 ;
if ( V_259 == NULL || V_258 == V_259 )
return V_258 ;
V_260 = F_123 ( V_258 ) ;
V_261 = F_123 ( V_259 ) ;
if ( V_260 > V_261 )
return V_258 ;
else if ( V_260 == V_261 )
return F_124 ( V_259 , V_258 ) ;
else
return V_259 ;
}
void F_64 ( struct V_1 * V_2 )
{
struct V_123 * V_250 = V_2 -> V_68 . V_161 ;
struct V_123 * V_262 = NULL ;
if ( V_2 -> V_68 . V_139 == 1 )
return;
if ( V_2 -> V_68 . V_152 == V_2 -> V_68 . V_161 &&
V_2 -> V_68 . V_152 -> V_19 == V_150 )
return;
for ( V_250 = F_127 ( V_250 , V_138 ) ; 1 ;
V_250 = F_127 ( V_250 , V_138 ) ) {
if ( & V_250 -> V_138 == & V_2 -> V_68 . V_84 )
continue;
if ( V_250 -> V_19 == V_190 )
continue;
V_262 = F_126 ( V_250 , V_262 ) ;
if ( V_262 -> V_19 == V_150 )
break;
if ( V_250 == V_2 -> V_68 . V_161 )
break;
}
V_2 -> V_68 . V_161 = V_262 ;
F_30 ( L_6 ,
V_159 , V_2 , & V_2 -> V_68 . V_161 -> V_148 . V_160 ) ;
}
static void F_92 ( struct V_1 * V_2 )
{
struct V_123 * V_250 , * V_263 = NULL , * V_264 = NULL ;
struct V_123 * V_265 = NULL ;
F_66 (trans, &asoc->peer.transport_addr_list,
transports) {
if ( V_250 -> V_19 == V_206 ||
V_250 -> V_19 == V_190 )
continue;
if ( V_250 -> V_19 == V_204 ) {
V_265 = F_126 ( V_250 , V_265 ) ;
continue;
}
if ( V_263 == NULL ||
F_125 ( V_250 -> V_243 ,
V_263 -> V_243 ) ) {
V_264 = V_263 ;
V_263 = V_250 ;
} else if ( V_264 == NULL ||
F_125 ( V_250 -> V_243 ,
V_264 -> V_243 ) ) {
V_264 = V_250 ;
}
}
if ( ( V_2 -> V_68 . V_146 -> V_19 == V_150 ||
V_2 -> V_68 . V_146 -> V_19 == V_151 ) &&
V_2 -> V_68 . V_146 != V_263 ) {
V_264 = V_263 ;
V_263 = V_2 -> V_68 . V_146 ;
}
if ( V_264 == NULL )
V_264 = V_263 ;
if ( V_263 == NULL ) {
V_263 = F_126 ( V_2 -> V_68 . V_152 , V_265 ) ;
V_264 = V_263 ;
}
V_2 -> V_68 . V_152 = V_263 ;
V_2 -> V_68 . V_161 = V_264 ;
}
struct V_123 *
F_128 ( struct V_1 * V_2 ,
struct V_123 * V_266 )
{
if ( V_266 == NULL ) {
return V_2 -> V_68 . V_152 ;
} else {
if ( V_266 == V_2 -> V_68 . V_161 )
F_64 ( V_2 ) ;
return V_2 -> V_68 . V_161 ;
}
}
void F_129 ( struct V_1 * V_2 )
{
struct V_123 * V_192 ;
V_185 V_267 = 0 ;
if ( ! V_2 )
return;
F_66 (t, &asoc->peer.transport_addr_list,
transports) {
if ( V_192 -> V_181 && V_192 -> V_268 ) {
F_130 (
V_192 , F_131 ( F_132 ( V_192 -> V_268 ) ) ) ;
V_192 -> V_181 = 0 ;
}
if ( ! V_267 || ( V_192 -> V_38 < V_267 ) )
V_267 = V_192 -> V_38 ;
}
if ( V_267 ) {
V_2 -> V_38 = V_267 ;
V_2 -> V_182 = F_77 ( V_2 , V_267 ) ;
}
F_30 ( L_7 , V_159 , V_2 ,
V_2 -> V_38 , V_2 -> V_182 ) ;
}
static inline bool F_133 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_2 ( V_2 -> V_14 . V_6 ) ;
switch ( V_2 -> V_19 ) {
case V_253 :
case V_269 :
case V_270 :
case V_271 :
if ( ( V_2 -> V_66 > V_2 -> V_67 ) &&
( ( V_2 -> V_66 - V_2 -> V_67 ) >= F_80 ( V_185 ,
( V_2 -> V_14 . V_6 -> V_64 >> V_9 -> V_28 . V_272 ) ,
V_2 -> V_38 ) ) )
return true ;
break;
default:
break;
}
return false ;
}
void F_134 ( struct V_1 * V_2 , unsigned int V_273 )
{
struct V_169 * V_274 ;
struct V_275 * V_276 ;
if ( V_2 -> V_277 ) {
if ( V_2 -> V_277 >= V_273 ) {
V_2 -> V_277 -= V_273 ;
} else {
V_2 -> V_66 += ( V_273 - V_2 -> V_277 ) ;
V_2 -> V_277 = 0 ;
}
} else {
V_2 -> V_66 += V_273 ;
}
if ( V_2 -> V_278 ) {
int V_279 = F_79 ( V_2 -> V_38 , V_2 -> V_278 ) ;
V_2 -> V_66 += V_279 ;
V_2 -> V_278 -= V_279 ;
}
F_30 ( L_8 ,
V_159 , V_2 , V_273 , V_2 -> V_66 , V_2 -> V_277 ,
V_2 -> V_67 ) ;
if ( F_133 ( V_2 ) ) {
V_2 -> V_67 = V_2 -> V_66 ;
F_30 ( L_9
L_10 , V_159 , V_2 , V_2 -> V_66 ,
V_2 -> V_67 ) ;
V_274 = F_135 ( V_2 ) ;
if ( ! V_274 )
return;
V_2 -> V_68 . V_85 = 0 ;
F_136 ( & V_2 -> V_91 , V_274 , V_211 ) ;
V_276 = & V_2 -> V_54 [ V_48 ] ;
if ( F_43 ( V_276 ) )
F_44 ( V_2 ) ;
}
}
void F_137 ( struct V_1 * V_2 , unsigned int V_273 )
{
int V_280 ;
int V_281 = 0 ;
if ( F_54 ( ! V_2 -> V_66 || V_2 -> V_277 ) )
F_30 ( L_11
L_12 , V_159 , V_2 ,
V_2 -> V_66 , V_2 -> V_277 ) ;
if ( V_2 -> V_4 -> V_282 )
V_280 = F_60 ( & V_2 -> V_70 ) ;
else
V_280 = F_60 ( & V_2 -> V_14 . V_6 -> V_283 ) ;
if ( V_280 >= V_2 -> V_14 . V_6 -> V_64 )
V_281 = 1 ;
if ( V_2 -> V_66 >= V_273 ) {
V_2 -> V_66 -= V_273 ;
if ( V_281 ) {
V_2 -> V_278 += V_2 -> V_66 ;
V_2 -> V_66 = 0 ;
}
} else {
V_2 -> V_277 += V_273 - V_2 -> V_66 ;
V_2 -> V_66 = 0 ;
}
F_30 ( L_13 ,
V_159 , V_2 , V_273 , V_2 -> V_66 , V_2 -> V_277 ,
V_2 -> V_278 ) ;
}
int F_138 ( struct V_1 * V_2 ,
T_1 V_7 , T_2 V_8 )
{
int V_284 ;
V_284 = ( V_96 == V_2 -> V_14 . V_6 -> V_95 ) ? V_285 : 0 ;
if ( V_2 -> V_68 . V_94 )
V_284 |= V_286 ;
if ( V_2 -> V_68 . V_97 )
V_284 |= V_287 ;
return F_139 ( F_2 ( V_2 -> V_14 . V_6 ) ,
& V_2 -> V_14 . V_17 ,
& V_2 -> V_4 -> V_14 . V_17 ,
V_7 , V_8 , V_284 ) ;
}
int F_140 ( struct V_1 * V_2 ,
struct V_288 * V_134 ,
T_2 V_8 )
{
int V_289 = F_21 ( V_134 -> V_290 -> V_236 . V_114 ) ;
int V_291 = V_134 -> V_292 ;
T_9 * V_293 = ( T_9 * ) V_134 -> V_290 + V_289 ;
return F_141 ( & V_2 -> V_14 . V_17 , V_293 , V_291 ,
V_2 -> V_4 -> V_14 . V_17 . V_18 , V_8 ) ;
}
int F_142 ( struct V_1 * V_2 ,
const union V_149 * V_229 )
{
int V_294 = 0 ;
if ( ( V_2 -> V_14 . V_17 . V_18 == F_21 ( V_229 -> V_177 . V_178 ) ) &&
F_104 ( & V_2 -> V_14 . V_17 , V_229 ,
F_3 ( V_2 -> V_14 . V_6 ) ) )
V_294 = 1 ;
return V_294 ;
}
int F_121 ( struct V_1 * V_2 , T_2 V_8 )
{
bool V_295 = F_143 ( V_8 ) ;
int V_296 ;
if ( V_2 -> V_142 )
return 0 ;
if ( V_295 )
F_144 ( V_8 ) ;
F_56 ( & V_143 ) ;
V_296 = F_145 ( & V_144 , V_2 , 1 , 0 , V_297 ) ;
F_58 ( & V_143 ) ;
if ( V_295 )
F_146 () ;
if ( V_296 < 0 )
return V_296 ;
V_2 -> V_142 = ( V_298 ) V_296 ;
return 0 ;
}
static void F_147 ( struct V_1 * V_2 )
{
struct V_169 * V_299 ;
struct V_169 * V_300 ;
F_87 (asconf, tmp, &asoc->addip_chunk_list, list) {
F_114 ( & V_299 -> V_301 ) ;
F_41 ( V_299 ) ;
}
}
static void F_148 ( struct V_1 * V_2 )
{
struct V_169 * V_302 ;
struct V_169 * V_300 ;
F_87 (ack, tmp, &asoc->asconf_ack_list,
transmitted_list) {
F_114 ( & V_302 -> V_303 ) ;
F_41 ( V_302 ) ;
}
}
void F_149 ( const struct V_1 * V_2 )
{
struct V_169 * V_302 ;
struct V_169 * V_300 ;
F_87 (ack, tmp, &asoc->asconf_ack_list,
transmitted_list) {
if ( V_302 -> V_226 . V_304 -> V_305 ==
F_101 ( V_2 -> V_68 . V_80 ) )
break;
F_114 ( & V_302 -> V_303 ) ;
F_41 ( V_302 ) ;
}
}
struct V_169 * F_150 (
const struct V_1 * V_2 ,
T_6 V_305 )
{
struct V_169 * V_302 ;
F_66 (ack, &asoc->asconf_ack_list, transmitted_list) {
if ( F_151 ( V_302 ) )
continue;
if ( V_302 -> V_226 . V_304 -> V_305 == V_305 ) {
F_152 ( V_302 ) ;
return V_302 ;
}
}
return NULL ;
}
void F_50 ( struct V_1 * V_2 )
{
F_148 ( V_2 ) ;
F_147 ( V_2 ) ;
if ( V_2 -> V_166 )
F_41 ( V_2 -> V_166 ) ;
}
