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
if ( ! V_2 -> V_122 ) {
F_31 ( & V_2 -> V_98 ) ;
if ( F_32 ( V_6 , V_123 ) && F_33 ( V_6 , V_124 ) )
V_6 -> V_125 -- ;
}
V_2 -> V_15 . V_126 = true ;
F_34 ( & V_2 -> V_91 ) ;
F_35 ( & V_2 -> V_92 ) ;
F_36 ( & V_2 -> V_15 . V_89 ) ;
F_37 ( & V_2 -> V_69 . V_127 ) ;
F_38 ( V_2 -> V_128 ) ;
F_39 ( & V_2 -> V_15 . V_18 ) ;
for ( V_12 = V_53 ; V_12 < V_54 ; ++ V_12 ) {
if ( F_40 ( & V_2 -> V_55 [ V_12 ] ) )
F_41 ( V_2 ) ;
}
F_29 ( V_2 -> V_69 . V_129 ) ;
F_29 ( V_2 -> V_69 . V_130 ) ;
F_29 ( V_2 -> V_69 . V_131 ) ;
F_29 ( V_2 -> V_69 . V_132 ) ;
F_42 (pos, temp, &asoc->peer.transport_addr_list) {
V_119 = F_43 ( V_121 , struct V_118 , V_133 ) ;
F_44 ( V_121 ) ;
F_45 ( V_119 ) ;
}
V_2 -> V_69 . V_134 = 0 ;
F_46 ( V_2 ) ;
if ( V_2 -> V_135 != NULL )
F_29 ( V_2 -> V_135 ) ;
F_47 ( & V_2 -> V_105 ) ;
F_48 ( V_2 -> V_136 ) ;
F_41 ( V_2 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
if ( F_50 ( ! V_2 -> V_15 . V_126 ) ) {
F_51 ( 1 , L_2 , V_2 ) ;
return;
}
F_24 ( V_2 -> V_4 ) ;
F_23 ( V_2 -> V_15 . V_6 ) ;
if ( V_2 -> V_137 != 0 ) {
F_52 ( & V_138 ) ;
F_53 ( & V_139 , V_2 -> V_137 ) ;
F_54 ( & V_138 ) ;
}
F_55 ( F_56 ( & V_2 -> V_71 ) ) ;
F_29 ( V_2 ) ;
F_57 ( V_117 ) ;
}
void F_58 ( struct V_1 * V_2 ,
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
void F_59 ( struct V_1 * V_2 ,
struct V_118 * V_69 )
{
struct V_120 * V_121 ;
struct V_118 * V_119 ;
F_28 ( L_3 ,
V_154 , V_2 , & V_69 -> V_143 . V_155 ) ;
if ( V_2 -> V_69 . V_156 == V_69 )
F_60 ( V_2 ) ;
F_44 ( & V_69 -> V_133 ) ;
V_121 = V_2 -> V_69 . V_84 . V_157 ;
V_119 = F_43 ( V_121 , struct V_118 , V_133 ) ;
if ( V_2 -> V_69 . V_141 == V_69 )
F_58 ( V_2 , V_119 ) ;
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
if ( ! F_61 ( & V_69 -> V_162 ) ) {
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
F_45 ( V_69 ) ;
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
F_58 ( V_2 , V_69 ) ;
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
F_42 (pos, temp, &asoc->peer.transport_addr_list) {
V_119 = F_43 ( V_121 , struct V_118 , V_133 ) ;
if ( F_80 ( V_170 , & V_119 -> V_143 ) ) {
F_59 ( V_2 , V_119 ) ;
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
F_59 ( V_2 , V_187 ) ;
}
}
void F_83 ( struct V_1 * V_2 ,
struct V_118 * V_119 ,
T_4 V_189 ,
T_5 error )
{
struct V_118 * V_187 = NULL ;
struct V_118 * V_190 ;
struct V_118 * V_191 ;
struct V_192 * V_193 ;
struct V_194 V_170 ;
int V_195 = 0 ;
bool V_196 = true ;
switch ( V_189 ) {
case V_197 :
if ( V_185 == V_119 -> V_20 &&
V_198 == error )
V_195 = V_199 ;
else
V_195 = V_200 ;
if ( V_119 -> V_20 == V_201 ) {
V_196 = false ;
V_119 -> V_179 = V_2 -> V_39 ;
}
V_119 -> V_20 = V_145 ;
break;
case V_202 :
if ( V_119 -> V_20 != V_185 )
V_119 -> V_20 = V_203 ;
else {
F_84 ( V_119 -> V_204 ) ;
V_119 -> V_204 = NULL ;
}
V_195 = V_205 ;
break;
case V_206 :
V_119 -> V_20 = V_201 ;
V_196 = false ;
break;
default:
return;
}
if ( V_196 ) {
memset ( & V_170 , 0 , sizeof( struct V_194 ) ) ;
memcpy ( & V_170 , & V_119 -> V_143 ,
V_119 -> V_207 -> V_208 ) ;
V_193 = F_85 ( V_2 , & V_170 ,
0 , V_195 , error , V_209 ) ;
if ( V_193 )
F_86 ( & V_2 -> V_92 , V_193 ) ;
}
V_190 = NULL ; V_191 = NULL ;
F_62 (t, &asoc->peer.transport_addr_list,
transports) {
if ( ( V_187 -> V_20 == V_203 ) ||
( V_187 -> V_20 == V_185 ) ||
( V_187 -> V_20 == V_201 ) )
continue;
if ( ! V_190 || V_187 -> V_210 > V_190 -> V_210 ) {
V_191 = V_190 ;
V_190 = V_187 ;
} else if ( ! V_191 ||
V_187 -> V_210 > V_191 -> V_210 )
V_191 = V_187 ;
}
if ( ( ( V_2 -> V_69 . V_141 -> V_20 == V_145 ) ||
( V_2 -> V_69 . V_141 -> V_20 == V_146 ) ) &&
V_190 != V_2 -> V_69 . V_141 ) {
V_191 = V_190 ;
V_190 = V_2 -> V_69 . V_141 ;
}
if ( ! V_191 )
V_191 = V_190 ;
if ( ! V_190 ) {
V_190 = V_2 -> V_69 . V_141 ;
V_191 = V_2 -> V_69 . V_141 ;
}
V_2 -> V_69 . V_147 = V_190 ;
V_2 -> V_69 . V_156 = V_191 ;
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
V_180 F_90 ( struct V_1 * V_2 )
{
V_180 V_211 = V_2 -> V_76 ;
V_2 -> V_76 ++ ;
V_2 -> V_212 ++ ;
return V_211 ;
}
int F_80 ( const union V_144 * V_213 ,
const union V_144 * V_214 )
{
struct V_215 * V_216 ;
V_216 = F_91 ( V_213 -> V_155 . V_217 ) ;
if ( F_50 ( ! V_216 ) )
return 0 ;
return V_216 -> V_218 ( V_213 , V_214 ) ;
}
struct V_164 * F_92 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_219 )
return NULL ;
return F_93 ( V_2 , V_2 -> V_220 ) ;
}
struct V_118 * F_94 ( struct V_1 * V_2 ,
V_180 V_221 )
{
struct V_118 * V_163 ;
struct V_118 * V_222 ;
struct V_118 * V_119 ;
struct V_164 * V_223 ;
T_6 V_224 = F_95 ( V_221 ) ;
V_222 = NULL ;
V_163 = V_2 -> V_69 . V_147 ;
F_62 (chunk, &active->transmitted,
transmitted_list) {
if ( V_224 == V_223 -> V_225 . V_226 -> V_221 ) {
V_222 = V_163 ;
goto V_227;
}
}
F_62 (transport, &asoc->peer.transport_addr_list,
transports) {
if ( V_119 == V_163 )
continue;
F_62 (chunk, &transport->transmitted,
transmitted_list) {
if ( V_224 == V_223 -> V_225 . V_226 -> V_221 ) {
V_222 = V_119 ;
goto V_227;
}
}
}
V_227:
return V_222 ;
}
struct V_118 * F_96 ( struct V_1 * V_2 ,
struct V_9 * V_9 ,
const union V_144 * V_228 ,
const union V_144 * V_229 )
{
struct V_118 * V_119 ;
if ( ( F_21 ( V_2 -> V_15 . V_18 . V_19 ) == V_228 -> V_172 . V_173 ) &&
( F_21 ( V_2 -> V_69 . V_19 ) == V_229 -> V_172 . V_173 ) &&
F_97 ( F_2 ( V_2 -> V_15 . V_6 ) , V_9 ) ) {
V_119 = F_68 ( V_2 , V_229 ) ;
if ( ! V_119 )
goto V_227;
if ( F_98 ( & V_2 -> V_15 . V_18 , V_228 ,
F_3 ( V_2 -> V_15 . V_6 ) ) )
goto V_227;
}
V_119 = NULL ;
V_227:
return V_119 ;
}
static void V_90 ( struct V_230 * V_231 )
{
struct V_1 * V_2 =
F_99 ( V_231 , struct V_1 ,
V_15 . V_89 . V_232 ) ;
struct V_9 * V_9 = F_2 ( V_2 -> V_15 . V_6 ) ;
struct V_3 * V_4 ;
struct V_164 * V_223 ;
struct V_233 * V_89 ;
int V_20 ;
T_7 V_234 ;
int error = 0 ;
V_4 = V_2 -> V_4 ;
V_89 = & V_2 -> V_15 . V_89 ;
F_87 ( V_2 ) ;
while ( NULL != ( V_223 = F_100 ( V_89 ) ) ) {
V_20 = V_2 -> V_20 ;
V_234 = F_101 ( V_223 -> V_235 -> type ) ;
if ( F_102 ( V_234 . V_223 , V_2 ) && ! V_223 -> V_236 )
continue;
if ( F_103 ( V_223 ) )
V_2 -> V_69 . V_158 = V_223 -> V_119 ;
else {
F_104 ( V_9 , V_237 ) ;
V_2 -> V_238 . V_239 ++ ;
if ( V_223 -> V_235 -> type == V_240 )
V_2 -> V_238 . V_241 ++ ;
}
if ( V_223 -> V_119 )
V_223 -> V_119 -> V_210 = V_168 ;
error = F_105 ( V_9 , V_242 , V_234 ,
V_20 , V_4 , V_2 , V_223 , V_209 ) ;
if ( V_2 -> V_15 . V_126 )
break;
if ( error && V_223 )
V_223 -> V_243 = 1 ;
}
F_41 ( V_2 ) ;
}
void F_106 ( struct V_1 * V_117 , struct V_5 * V_244 )
{
struct V_10 * V_245 = F_3 ( V_244 ) ;
struct V_5 * V_246 = V_117 -> V_15 . V_6 ;
F_107 ( & V_117 -> V_98 ) ;
if ( F_32 ( V_246 , V_123 ) )
V_246 -> V_125 -- ;
F_24 ( V_117 -> V_4 ) ;
F_23 ( V_117 -> V_15 . V_6 ) ;
V_117 -> V_4 = V_245 -> V_4 ;
F_4 ( V_117 -> V_4 ) ;
V_117 -> V_15 . V_6 = V_244 ;
F_5 ( V_117 -> V_15 . V_6 ) ;
F_108 ( V_245 -> V_4 , V_117 ) ;
}
void F_109 ( struct V_1 * V_2 ,
struct V_1 * V_247 )
{
struct V_118 * V_248 ;
struct V_120 * V_121 , * V_122 ;
V_2 -> V_57 = V_247 -> V_57 ;
V_2 -> V_69 . V_67 = V_247 -> V_69 . V_67 ;
V_2 -> V_69 . V_85 = V_247 -> V_69 . V_85 ;
V_2 -> V_69 . V_12 = V_247 -> V_69 . V_12 ;
F_110 ( & V_2 -> V_69 . V_127 , V_249 ,
V_2 -> V_69 . V_12 . V_75 , V_209 ) ;
F_42 (pos, temp, &asoc->peer.transport_addr_list) {
V_248 = F_43 ( V_121 , struct V_118 , V_133 ) ;
if ( ! F_68 ( V_247 , & V_248 -> V_143 ) ) {
F_59 ( V_2 , V_248 ) ;
continue;
}
if ( V_2 -> V_20 >= V_250 )
F_111 ( V_248 ) ;
}
if ( V_2 -> V_20 >= V_250 ) {
V_2 -> V_76 = V_247 -> V_76 ;
V_2 -> V_77 = V_247 -> V_77 ;
V_2 -> V_78 = V_247 -> V_78 ;
F_112 ( V_2 -> V_128 ) ;
F_113 ( & V_2 -> V_92 ) ;
V_2 -> V_251 = 0 ;
} else {
F_62 (trans, &new->peer.transport_addr_list,
transports) {
if ( ! F_68 ( V_2 , & V_248 -> V_143 ) )
F_67 ( V_2 , & V_248 -> V_143 ,
V_209 , V_248 -> V_20 ) ;
}
V_2 -> V_77 = V_2 -> V_76 - 1 ;
V_2 -> V_78 = V_2 -> V_77 ;
if ( ! V_2 -> V_128 ) {
V_2 -> V_128 = V_247 -> V_128 ;
V_247 -> V_128 = NULL ;
}
if ( ! V_2 -> V_137 ) {
F_114 ( V_2 , V_209 ) ;
}
}
F_29 ( V_2 -> V_69 . V_130 ) ;
V_2 -> V_69 . V_130 = V_247 -> V_69 . V_130 ;
V_247 -> V_69 . V_130 = NULL ;
F_29 ( V_2 -> V_69 . V_131 ) ;
V_2 -> V_69 . V_131 = V_247 -> V_69 . V_131 ;
V_247 -> V_69 . V_131 = NULL ;
F_29 ( V_2 -> V_69 . V_132 ) ;
V_2 -> V_69 . V_132 = V_247 -> V_69 . V_132 ;
V_247 -> V_69 . V_132 = NULL ;
F_48 ( V_2 -> V_136 ) ;
F_115 ( V_2 , V_209 ) ;
}
static T_8 F_116 ( const struct V_118 * V_248 )
{
return V_252 [ V_248 -> V_20 ] ;
}
static struct V_118 * F_117 ( struct V_118 * V_253 ,
struct V_118 * V_254 )
{
if ( V_254 == NULL )
return V_253 ;
return F_116 ( V_253 ) > F_116 ( V_254 ) ? V_253 : V_254 ;
}
void F_60 ( struct V_1 * V_2 )
{
struct V_118 * V_248 = V_2 -> V_69 . V_156 ;
struct V_118 * V_255 = NULL ;
if ( V_2 -> V_69 . V_134 == 1 )
return;
if ( V_2 -> V_69 . V_147 == V_2 -> V_69 . V_156 &&
V_2 -> V_69 . V_147 -> V_20 == V_145 )
return;
for ( V_248 = F_118 ( V_248 , V_133 ) ; 1 ;
V_248 = F_118 ( V_248 , V_133 ) ) {
if ( & V_248 -> V_133 == & V_2 -> V_69 . V_84 )
continue;
if ( V_248 -> V_20 == V_185 )
continue;
V_255 = F_117 ( V_248 , V_255 ) ;
if ( V_255 -> V_20 == V_145 )
break;
if ( V_248 == V_2 -> V_69 . V_156 )
break;
}
V_2 -> V_69 . V_156 = V_255 ;
F_28 ( L_6 ,
V_154 , V_2 , & V_2 -> V_69 . V_156 -> V_143 . V_155 ) ;
}
struct V_118 *
F_119 ( struct V_1 * V_2 ,
struct V_118 * V_256 )
{
if ( V_256 == NULL ) {
return V_2 -> V_69 . V_147 ;
} else {
if ( V_256 == V_2 -> V_69 . V_156 )
F_60 ( V_2 ) ;
return V_2 -> V_69 . V_156 ;
}
}
void F_120 ( struct V_5 * V_6 , struct V_1 * V_2 )
{
struct V_118 * V_187 ;
V_180 V_257 = 0 ;
if ( ! V_2 )
return;
F_62 (t, &asoc->peer.transport_addr_list,
transports) {
if ( V_187 -> V_176 && V_187 -> V_204 ) {
F_121 ( V_6 , V_187 , F_122 ( V_187 -> V_204 ) ) ;
V_187 -> V_176 = 0 ;
}
if ( ! V_257 || ( V_187 -> V_39 < V_257 ) )
V_257 = V_187 -> V_39 ;
}
if ( V_257 ) {
V_2 -> V_39 = V_257 ;
V_2 -> V_177 = F_73 ( V_2 , V_257 ) ;
}
F_28 ( L_7 , V_154 , V_2 ,
V_2 -> V_39 , V_2 -> V_177 ) ;
}
static inline bool F_123 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_2 ( V_2 -> V_15 . V_6 ) ;
switch ( V_2 -> V_20 ) {
case V_250 :
case V_258 :
case V_259 :
case V_260 :
if ( ( V_2 -> V_67 > V_2 -> V_68 ) &&
( ( V_2 -> V_67 - V_2 -> V_68 ) >= F_76 ( V_180 ,
( V_2 -> V_15 . V_6 -> V_65 >> V_9 -> V_29 . V_261 ) ,
V_2 -> V_39 ) ) )
return true ;
break;
default:
break;
}
return false ;
}
void F_124 ( struct V_1 * V_2 , unsigned int V_262 )
{
struct V_164 * V_263 ;
struct V_264 * V_265 ;
if ( V_2 -> V_266 ) {
if ( V_2 -> V_266 >= V_262 ) {
V_2 -> V_266 -= V_262 ;
} else {
V_2 -> V_67 += ( V_262 - V_2 -> V_266 ) ;
V_2 -> V_266 = 0 ;
}
} else {
V_2 -> V_67 += V_262 ;
}
if ( V_2 -> V_267 && V_2 -> V_67 >= V_2 -> V_267 ) {
int V_268 = F_75 ( V_2 -> V_39 , V_2 -> V_267 ) ;
V_2 -> V_67 += V_268 ;
V_2 -> V_267 -= V_268 ;
}
F_28 ( L_8 ,
V_154 , V_2 , V_262 , V_2 -> V_67 , V_2 -> V_266 ,
V_2 -> V_68 ) ;
if ( F_123 ( V_2 ) ) {
V_2 -> V_68 = V_2 -> V_67 ;
F_28 ( L_9
L_10 , V_154 , V_2 , V_2 -> V_67 ,
V_2 -> V_68 ) ;
V_263 = F_125 ( V_2 ) ;
if ( ! V_263 )
return;
V_2 -> V_69 . V_85 = 0 ;
F_126 ( & V_2 -> V_91 , V_263 ) ;
V_265 = & V_2 -> V_55 [ V_49 ] ;
if ( F_40 ( V_265 ) )
F_41 ( V_2 ) ;
}
}
void F_127 ( struct V_1 * V_2 , unsigned int V_262 )
{
int V_269 ;
int V_270 = 0 ;
if ( F_50 ( ! V_2 -> V_67 || V_2 -> V_266 ) )
F_28 ( L_11
L_12 , V_154 , V_2 ,
V_2 -> V_67 , V_2 -> V_266 ) ;
if ( V_2 -> V_4 -> V_271 )
V_269 = F_56 ( & V_2 -> V_71 ) ;
else
V_269 = F_56 ( & V_2 -> V_15 . V_6 -> V_272 ) ;
if ( V_269 >= V_2 -> V_15 . V_6 -> V_65 )
V_270 = 1 ;
if ( V_2 -> V_67 >= V_262 ) {
V_2 -> V_67 -= V_262 ;
if ( V_270 ) {
V_2 -> V_267 += V_2 -> V_67 ;
V_2 -> V_67 = 0 ;
}
} else {
V_2 -> V_266 = V_262 - V_2 -> V_67 ;
V_2 -> V_67 = 0 ;
}
F_28 ( L_13 ,
V_154 , V_2 , V_262 , V_2 -> V_67 , V_2 -> V_266 ,
V_2 -> V_267 ) ;
}
int F_128 ( struct V_1 * V_2 ,
T_1 V_7 , T_2 V_8 )
{
int V_273 ;
V_273 = ( V_96 == V_2 -> V_15 . V_6 -> V_95 ) ? V_274 : 0 ;
if ( V_2 -> V_69 . V_94 )
V_273 |= V_275 ;
if ( V_2 -> V_69 . V_97 )
V_273 |= V_276 ;
return F_129 ( F_2 ( V_2 -> V_15 . V_6 ) ,
& V_2 -> V_15 . V_18 ,
& V_2 -> V_4 -> V_15 . V_18 ,
V_7 , V_8 , V_273 ) ;
}
int F_130 ( struct V_1 * V_2 ,
struct V_277 * V_129 ,
T_2 V_8 )
{
int V_278 = F_20 ( V_129 -> V_279 -> V_235 . V_110 ) ;
int V_280 = V_129 -> V_281 ;
T_9 * V_282 = ( T_9 * ) V_129 -> V_279 + V_278 ;
return F_131 ( & V_2 -> V_15 . V_18 , V_282 , V_280 ,
V_2 -> V_4 -> V_15 . V_18 . V_19 , V_8 ) ;
}
int F_132 ( struct V_1 * V_2 ,
const union V_144 * V_228 )
{
int V_283 = 0 ;
if ( ( V_2 -> V_15 . V_18 . V_19 == F_20 ( V_228 -> V_172 . V_173 ) ) &&
F_98 ( & V_2 -> V_15 . V_18 , V_228 ,
F_3 ( V_2 -> V_15 . V_6 ) ) )
V_283 = 1 ;
return V_283 ;
}
int F_114 ( struct V_1 * V_2 , T_2 V_8 )
{
bool V_284 = V_8 & V_285 ;
int V_286 ;
if ( V_2 -> V_137 )
return 0 ;
if ( V_284 )
F_133 ( V_8 ) ;
F_52 ( & V_138 ) ;
V_286 = F_134 ( & V_139 , V_2 , 1 , 0 , V_287 ) ;
F_54 ( & V_138 ) ;
if ( V_284 )
F_135 () ;
if ( V_286 < 0 )
return V_286 ;
V_2 -> V_137 = ( V_288 ) V_286 ;
return 0 ;
}
static void F_136 ( struct V_1 * V_2 )
{
struct V_164 * V_289 ;
struct V_164 * V_290 ;
F_82 (asconf, tmp, &asoc->addip_chunk_list, list) {
F_107 ( & V_289 -> V_291 ) ;
F_137 ( V_289 ) ;
}
}
static void F_138 ( struct V_1 * V_2 )
{
struct V_164 * V_292 ;
struct V_164 * V_290 ;
F_82 (ack, tmp, &asoc->asconf_ack_list,
transmitted_list) {
F_107 ( & V_292 -> V_293 ) ;
F_137 ( V_292 ) ;
}
}
void F_139 ( const struct V_1 * V_2 )
{
struct V_164 * V_292 ;
struct V_164 * V_290 ;
F_82 (ack, tmp, &asoc->asconf_ack_list,
transmitted_list) {
if ( V_292 -> V_225 . V_294 -> V_295 ==
F_95 ( V_2 -> V_69 . V_81 ) )
break;
F_107 ( & V_292 -> V_293 ) ;
F_137 ( V_292 ) ;
}
}
struct V_164 * F_140 (
const struct V_1 * V_2 ,
T_6 V_295 )
{
struct V_164 * V_292 ;
F_62 (ack, &asoc->asconf_ack_list, transmitted_list) {
if ( V_292 -> V_225 . V_294 -> V_295 == V_295 ) {
F_141 ( V_292 ) ;
return V_292 ;
}
}
return NULL ;
}
void F_46 ( struct V_1 * V_2 )
{
F_138 ( V_2 ) ;
F_136 ( V_2 ) ;
if ( V_2 -> V_161 )
F_137 ( V_2 -> V_161 ) ;
}
