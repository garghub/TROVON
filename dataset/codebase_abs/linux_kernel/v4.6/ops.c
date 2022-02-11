static int T_1 F_1 ( void )
{
int V_1 ;
V_1 = F_2 () ;
if ( V_1 ) {
F_3 ( L_1 , V_1 ) ;
return V_1 ;
}
V_1 = F_4 ( L_2 , & V_2 ) ;
if ( V_1 ) {
F_3 ( L_3 , V_1 ) ;
F_5 () ;
}
return V_1 ;
}
static void T_2 F_6 ( void )
{
F_7 ( L_2 ) ;
F_5 () ;
}
static void F_8 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
T_3 V_7 , V_8 , V_9 ;
T_4 V_10 = 0 ;
T_4 V_11 = F_10 ( V_6 ) ;
V_7 = ( V_11 & V_12 ) >>
V_13 ;
V_8 = ( V_11 & V_14 ) >>
V_15 ;
V_9 = ( V_11 & V_16 ) >>
V_17 ;
V_10 |= F_11 ( V_6 -> V_18 -> V_19 ) <<
V_20 ;
V_10 |= F_12 ( V_6 -> V_18 -> V_19 ) <<
V_21 ;
V_10 |= V_7 << V_22 ;
V_10 |= V_8 << V_23 ;
V_10 |= V_9 << V_24 ;
F_13 ( ( V_7 << V_22 ) &
~ V_25 ) ;
if ( V_6 -> V_18 -> V_26 -> V_27 != V_28 )
V_10 |= V_29 ;
F_14 ( V_6 -> V_18 , V_30 ,
V_31 |
V_32 |
V_25 |
V_33 |
V_34 |
V_29 |
V_35 ,
V_10 ) ;
F_15 ( V_6 , L_4 , V_7 ,
V_8 , V_9 ) ;
if ( ! V_6 -> V_18 -> V_26 -> V_36 )
F_16 ( V_6 -> V_18 , V_37 ,
V_38 ,
~ V_38 ) ;
}
static T_4 F_17 ( struct V_39 * V_18 , const struct V_40 * V_26 )
{
const struct V_41 * V_42 = V_26 -> V_43 ;
if ( ! V_42 )
return 0 ;
while ( V_42 -> V_44 ) {
if ( V_18 -> V_45 >= V_42 -> V_44 )
return V_42 -> V_46 ;
V_42 ++ ;
}
return 0 ;
}
static struct V_3 *
F_18 ( struct V_39 * V_18 , const struct V_40 * V_26 ,
const struct V_47 * V_48 , struct V_49 * V_50 )
{
struct V_51 * V_52 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_53 V_54 = {} ;
static const T_3 V_55 [] = {
V_56 ,
} ;
int V_57 , V_58 ;
T_4 V_59 ;
F_19 ( F_20 ( V_6 -> V_60 ) != V_61 ) ;
V_52 = F_21 ( sizeof( struct V_3 ) +
sizeof( struct V_5 ) ,
& V_62 ) ;
if ( ! V_52 )
return NULL ;
if ( V_26 -> V_63 )
V_52 -> V_64 = V_26 -> V_63 ;
if ( V_26 -> V_65 )
V_52 -> V_66 = V_26 -> V_65 ;
V_4 = V_52 -> V_67 ;
V_6 = F_9 ( V_4 ) ;
V_6 -> V_68 = V_18 -> V_68 ;
V_6 -> V_18 = V_18 ;
V_6 -> V_26 = V_26 ;
V_6 -> V_48 = V_48 ;
V_6 -> V_52 = V_52 ;
if ( F_22 ( V_6 ) ) {
V_4 -> V_69 = & V_70 ;
V_18 -> V_71 = sizeof( struct V_72 ) ;
} else {
V_4 -> V_69 = & V_2 ;
V_18 -> V_71 =
sizeof( struct V_73 ) ;
if ( F_13 ( V_18 -> V_74 > 1 ) )
goto V_75;
}
V_6 -> V_76 = V_77 . V_76 ? - 1 : 0 ;
V_6 -> V_78 = 15 ;
V_6 -> V_79 = 16 ;
V_6 -> V_80 = V_6 -> V_26 -> V_81 -> V_82 - 1 ;
if ( V_6 -> V_26 -> V_81 -> V_82 == 16 ) {
V_6 -> V_78 = 11 ;
V_6 -> V_79 = 12 ;
}
V_6 -> V_83 = V_84 ;
V_6 -> V_85 = V_86 ;
V_6 -> V_87 = true ;
F_23 ( & V_6 -> V_88 ) ;
F_23 ( & V_6 -> V_89 ) ;
F_24 ( & V_6 -> V_90 ) ;
F_25 ( & V_6 -> V_91 ) ;
F_25 ( & V_6 -> V_92 ) ;
F_25 ( & V_6 -> V_93 ) ;
F_24 ( & V_6 -> V_94 ) ;
F_24 ( & V_6 -> V_95 ) ;
F_26 ( & V_6 -> V_96 , V_97 ) ;
F_26 ( & V_6 -> V_98 , V_99 ) ;
F_26 ( & V_6 -> V_100 , V_101 ) ;
F_26 ( & V_6 -> V_102 , V_103 ) ;
F_27 ( & V_6 -> V_104 , V_105 ) ;
F_27 ( & V_6 -> V_106 . V_107 , V_108 ) ;
F_24 ( & V_6 -> V_109 ) ;
F_24 ( & V_6 -> V_110 ) ;
F_28 ( & V_6 -> V_111 ) ;
F_29 ( & V_6 -> V_112 ) ;
F_30 ( V_6 -> V_52 , V_6 -> V_18 -> V_68 ) ;
V_54 . V_4 = V_4 ;
V_54 . V_55 = V_55 ;
V_54 . V_113 = F_20 ( V_55 ) ;
switch ( V_77 . V_114 ) {
case V_115 :
V_54 . V_116 = V_115 ;
break;
case V_117 :
V_54 . V_116 = V_117 ;
break;
case V_118 :
V_54 . V_116 = V_118 ;
break;
default:
F_3 ( L_5 , V_119 ,
V_77 . V_114 ) ;
V_54 . V_116 = V_115 ;
}
V_54 . V_120 = F_31 ( & V_6 -> V_48 -> V_121 ,
V_122 ) ;
if ( V_6 -> V_48 -> V_121 . V_123 & V_124 )
V_54 . V_125 = true ;
V_54 . V_126 = V_127 ;
V_54 . V_128 = F_20 ( V_127 ) ;
V_54 . V_129 = V_130 ;
V_54 . V_131 = V_132 ;
V_54 . V_133 = true ;
V_54 . V_134 = V_48 -> V_134 ;
V_54 . V_135 = V_136 ;
V_54 . V_137 =
F_32 ( V_6 , NULL , false , true ) ;
snprintf ( V_6 -> V_52 -> V_138 -> V_139 ,
sizeof( V_6 -> V_52 -> V_138 -> V_139 ) ,
L_6 , V_48 -> V_139 ) ;
F_33 ( V_6 -> V_18 , & V_54 ) ;
V_18 -> V_140 = V_141 ;
V_18 -> V_142 = V_6 -> V_48 -> V_142 ;
V_18 -> V_143 = V_6 -> V_48 -> V_143 ;
memcpy ( V_18 -> V_144 , V_6 -> V_48 -> V_144 ,
sizeof( V_18 -> V_144 ) ) ;
V_18 -> V_145 = V_6 -> V_48 -> V_145 ;
F_34 ( & V_6 -> V_146 ) ;
V_6 -> V_147 = F_35 ( V_18 ) ;
if ( ! V_6 -> V_147 ) {
F_36 ( V_6 , L_7 ) ;
goto V_75;
}
F_37 ( V_6 , L_8 ,
V_6 -> V_26 -> V_148 , V_6 -> V_18 -> V_19 ) ;
if ( V_77 . V_149 )
V_6 -> V_150 = V_77 . V_149 ;
else
F_38 ( V_6 -> V_18 -> V_68 ,
L_9 ) ;
if ( F_39 ( V_26 -> V_151 && ! V_6 -> V_150 ,
L_10 ) )
goto V_75;
if ( V_26 -> V_151 && V_6 -> V_150 ) {
V_57 = F_40 ( V_6 , false ) ;
if ( V_57 )
goto V_75;
} else {
V_57 = F_41 ( V_6 -> V_18 ) ;
if ( V_57 )
goto V_75;
F_42 ( & V_6 -> V_88 ) ;
F_43 ( V_6 , V_152 ) ;
V_57 = F_44 ( V_6 , true ) ;
if ( ! V_57 || ! V_153 . V_154 )
F_45 ( V_6 ) ;
F_46 ( V_6 , V_152 ) ;
F_47 ( & V_6 -> V_88 ) ;
if ( V_57 < 0 && ! V_153 . V_154 ) {
F_36 ( V_6 , L_11 , V_57 ) ;
goto V_75;
}
}
V_58 = F_48 ( V_6 ) ;
V_6 -> V_155 = F_49 ( V_58 , V_156 ) ;
if ( ! V_6 -> V_155 )
goto V_75;
V_6 -> V_157 = true ;
V_57 = F_50 ( V_6 ) ;
if ( V_57 )
goto V_75;
V_59 = F_17 ( V_18 , V_26 ) ;
F_51 ( V_6 , V_59 ) ;
V_57 = F_52 ( V_6 , V_50 ) ;
if ( V_57 )
goto V_158;
memset ( & V_6 -> V_159 , 0 , sizeof( struct V_160 ) ) ;
if ( F_53 ( V_6 ) )
F_54 ( V_6 -> V_18 ) ;
F_55 ( V_6 ) ;
F_56 ( V_6 -> V_161 , sizeof( V_6 -> V_161 ) ) ;
return V_4 ;
V_158:
F_57 ( V_6 -> V_52 ) ;
F_58 ( V_6 ) ;
F_59 ( V_6 ) ;
V_75:
F_60 ( & V_6 -> V_104 ) ;
F_61 ( V_6 -> V_147 ) ;
F_62 ( V_6 -> V_155 ) ;
if ( ! V_26 -> V_151 || ! V_6 -> V_150 )
F_63 ( V_18 ) ;
F_64 ( V_6 -> V_52 ) ;
return NULL ;
}
static void F_65 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
int V_162 ;
if ( F_53 ( V_6 ) )
F_66 ( V_6 -> V_18 ) ;
F_58 ( V_6 ) ;
F_59 ( V_6 ) ;
F_57 ( V_6 -> V_52 ) ;
F_62 ( V_6 -> V_155 ) ;
F_62 ( V_6 -> V_163 ) ;
V_6 -> V_163 = NULL ;
#if F_67 ( V_164 ) && F_67 ( V_165 )
F_62 ( V_6 -> V_166 ) ;
#endif
F_63 ( V_6 -> V_18 ) ;
F_61 ( V_6 -> V_147 ) ;
V_6 -> V_147 = NULL ;
F_68 ( V_6 -> V_167 ) ;
for ( V_162 = 0 ; V_162 < V_168 ; V_162 ++ )
F_62 ( V_6 -> V_169 [ V_162 ] . V_170 ) ;
F_69 ( V_6 ) ;
F_64 ( V_6 -> V_52 ) ;
}
void F_70 ( struct V_5 * V_6 )
{
struct V_171 * V_172 , * V_173 ;
F_71 ( & V_6 -> V_90 ) ;
F_72 (entry, tmp, &mvm->async_handlers_list, list) {
F_73 ( & V_172 -> V_174 ) ;
F_74 ( & V_172 -> V_175 ) ;
F_62 ( V_172 ) ;
}
F_75 ( & V_6 -> V_90 ) ;
}
static void V_97 ( struct V_176 * V_177 )
{
struct V_5 * V_6 =
F_76 ( V_177 , struct V_5 , V_96 ) ;
struct V_171 * V_172 , * V_173 ;
struct V_178 V_179 ;
F_25 ( & V_179 ) ;
F_71 ( & V_6 -> V_90 ) ;
F_77 ( & V_6 -> V_93 , & V_179 ) ;
F_75 ( & V_6 -> V_90 ) ;
F_72 (entry, tmp, &local_list, list) {
if ( V_172 -> V_180 == V_181 )
F_42 ( & V_6 -> V_88 ) ;
V_172 -> V_182 ( V_6 , & V_172 -> V_174 ) ;
F_73 ( & V_172 -> V_174 ) ;
F_74 ( & V_172 -> V_175 ) ;
if ( V_172 -> V_180 == V_181 )
F_47 ( & V_6 -> V_88 ) ;
F_62 ( V_172 ) ;
}
}
static inline void F_78 ( struct V_5 * V_6 ,
struct V_183 * V_184 )
{
struct V_185 * V_186 ;
struct V_187 * V_188 ;
int V_162 ;
if ( ! F_79 ( V_6 -> V_48 , V_189 ) )
return;
V_186 = F_80 ( V_6 -> V_48 , V_189 ) ;
V_188 = ( void * ) V_186 -> V_170 ;
if ( ! F_81 ( V_6 , NULL , V_186 ) )
return;
for ( V_162 = 0 ; V_162 < F_20 ( V_188 -> V_190 ) ; V_162 ++ ) {
if ( ! V_188 -> V_190 [ V_162 ] . V_191 )
break;
if ( V_188 -> V_190 [ V_162 ] . V_191 != V_184 -> V_192 . V_193 ||
V_188 -> V_190 [ V_162 ] . V_194 != V_184 -> V_192 . V_194 )
continue;
F_82 ( V_6 , V_186 ,
L_12 ,
V_184 -> V_192 . V_194 , V_184 -> V_192 . V_193 ) ;
break;
}
}
static void F_83 ( struct V_5 * V_6 ,
struct V_195 * V_174 ,
struct V_183 * V_184 )
{
int V_162 ;
F_78 ( V_6 , V_184 ) ;
F_84 ( & V_6 -> V_146 , V_184 ) ;
for ( V_162 = 0 ; V_162 < F_20 ( V_196 ) ; V_162 ++ ) {
const struct V_197 * V_198 = & V_196 [ V_162 ] ;
struct V_171 * V_172 ;
if ( V_198 -> V_191 != F_85 ( V_184 -> V_192 . V_194 , V_184 -> V_192 . V_193 ) )
continue;
if ( V_198 -> V_180 == V_199 ) {
V_198 -> V_182 ( V_6 , V_174 ) ;
return;
}
V_172 = F_86 ( sizeof( * V_172 ) , V_200 ) ;
if ( ! V_172 )
return;
V_172 -> V_174 . V_201 = F_87 ( V_174 ) ;
V_172 -> V_174 . V_202 = V_174 -> V_202 ;
V_172 -> V_174 . V_203 = V_174 -> V_203 ;
V_172 -> V_182 = V_198 -> V_182 ;
V_172 -> V_180 = V_198 -> V_180 ;
F_88 ( & V_6 -> V_90 ) ;
F_89 ( & V_172 -> V_175 , & V_6 -> V_93 ) ;
F_90 ( & V_6 -> V_90 ) ;
F_91 ( & V_6 -> V_96 ) ;
break;
}
}
static void F_92 ( struct V_3 * V_4 ,
struct V_204 * V_205 ,
struct V_195 * V_174 )
{
struct V_183 * V_184 = F_93 ( V_174 ) ;
struct V_5 * V_6 = F_9 ( V_4 ) ;
if ( F_94 ( V_184 -> V_192 . V_193 == V_141 ) )
F_95 ( V_6 , V_205 , V_174 ) ;
else if ( V_184 -> V_192 . V_193 == V_206 )
F_96 ( V_6 , V_174 , 0 ) ;
else if ( V_184 -> V_192 . V_193 == V_207 )
F_97 ( V_6 , V_174 ) ;
else
F_83 ( V_6 , V_174 , V_184 ) ;
}
static void F_98 ( struct V_3 * V_4 ,
struct V_204 * V_205 ,
struct V_195 * V_174 )
{
struct V_183 * V_184 = F_93 ( V_174 ) ;
struct V_5 * V_6 = F_9 ( V_4 ) ;
if ( F_94 ( V_184 -> V_192 . V_193 == V_141 ) )
F_99 ( V_6 , V_205 , V_174 , 0 ) ;
else if ( V_184 -> V_192 . V_193 == V_207 )
F_100 ( V_6 , V_174 ) ;
else if ( F_101 ( V_184 -> V_192 . V_194 == V_208 &&
V_184 -> V_192 . V_193 == V_209 ) )
F_102 ( V_6 , V_174 , 0 ) ;
else
F_83 ( V_6 , V_174 , V_184 ) ;
}
void F_103 ( struct V_5 * V_6 , unsigned long V_210 )
{
int V_211 ;
if ( F_104 ( ! V_210 ) )
return;
F_105 (q, &mq, IEEE80211_MAX_QUEUES) {
if ( F_106 ( & V_6 -> V_212 [ V_211 ] ) > 1 ) {
F_107 ( V_6 ,
L_13 , V_211 ) ;
continue;
}
F_108 ( V_6 -> V_52 , V_211 ) ;
}
}
static void F_109 ( struct V_3 * V_4 ,
const struct V_213 * V_193 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_110 ( V_6 -> V_18 , false ) ;
}
static void F_111 ( struct V_3 * V_4 , int V_214 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
unsigned long V_210 ;
F_71 ( & V_6 -> V_95 ) ;
V_210 = V_6 -> V_215 [ V_214 ] . V_216 ;
F_75 ( & V_6 -> V_95 ) ;
F_103 ( V_6 , V_210 ) ;
}
void F_112 ( struct V_5 * V_6 , unsigned long V_210 )
{
int V_211 ;
if ( F_104 ( ! V_210 ) )
return;
F_105 (q, &mq, IEEE80211_MAX_QUEUES) {
if ( F_113 ( & V_6 -> V_212 [ V_211 ] ) > 0 ) {
F_107 ( V_6 ,
L_14 , V_211 ) ;
continue;
}
F_114 ( V_6 -> V_52 , V_211 ) ;
}
}
static void F_115 ( struct V_3 * V_4 , int V_214 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
unsigned long V_210 ;
F_71 ( & V_6 -> V_95 ) ;
V_210 = V_6 -> V_215 [ V_214 ] . V_216 ;
F_75 ( & V_6 -> V_95 ) ;
F_112 ( V_6 , V_210 ) ;
}
void F_116 ( struct V_5 * V_6 , bool V_217 )
{
if ( V_217 )
F_117 ( V_218 , & V_6 -> V_219 ) ;
else
F_118 ( V_218 , & V_6 -> V_219 ) ;
F_119 ( V_6 -> V_52 -> V_138 , F_120 ( V_6 ) ) ;
}
static bool F_121 ( struct V_3 * V_4 , bool V_217 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
bool V_220 = F_122 ( V_6 -> V_220 ) ;
if ( V_217 )
F_117 ( V_221 , & V_6 -> V_219 ) ;
else
F_118 ( V_221 , & V_6 -> V_219 ) ;
F_119 ( V_6 -> V_52 -> V_138 , F_120 ( V_6 ) ) ;
if ( V_220 )
F_123 ( & V_6 -> V_146 ) ;
return V_217 && ( V_6 -> V_85 != V_86 || V_220 ) ;
}
static void F_124 ( struct V_3 * V_4 , struct V_222 * V_223 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
struct V_224 * V_225 ;
V_225 = F_125 ( V_223 ) ;
F_126 ( V_6 -> V_18 , V_225 -> V_226 [ 1 ] ) ;
F_127 ( V_6 -> V_52 , V_223 ) ;
}
static void F_128 ( struct V_176 * V_177 )
{
struct V_227 * V_228 ;
V_228 = F_76 ( V_177 , struct V_227 , V_229 ) ;
if ( F_129 ( V_228 -> V_68 ) )
F_130 ( V_228 -> V_68 , L_15 ) ;
F_62 ( V_228 ) ;
F_131 ( V_230 ) ;
}
static void V_105 ( struct V_176 * V_229 )
{
struct V_5 * V_6 =
F_76 ( V_229 , struct V_5 , V_104 . V_229 ) ;
if ( F_132 ( V_6 , V_231 ) )
return;
F_42 ( & V_6 -> V_88 ) ;
if ( V_6 -> V_26 -> V_27 == V_232 ) {
F_133 ( V_6 -> V_18 , V_233 , 0x100 ) ;
} else {
F_134 ( V_6 -> V_18 , V_234 , 0 ) ;
F_135 ( 100 ) ;
}
F_136 ( V_6 ) ;
F_104 ( ( ! F_137 ( V_235 , & V_6 -> V_18 -> V_219 ) ) &&
V_6 -> V_48 -> V_142 &&
F_138 ( V_6 , V_6 -> V_236 ) ) ;
F_47 ( & V_6 -> V_88 ) ;
F_46 ( V_6 , V_231 ) ;
}
void F_139 ( struct V_5 * V_6 , bool V_237 )
{
F_123 ( & V_6 -> V_146 ) ;
F_140 ( V_6 ) ;
if ( ! V_6 -> V_76 && V_237 ) {
F_141 ( V_6 , & V_238 ,
NULL ) ;
} else if ( F_142 ( V_239 ,
& V_6 -> V_219 ) ) {
struct V_227 * V_228 ;
F_36 ( V_6 ,
L_16 ) ;
if ( ! F_143 ( V_230 ) ) {
F_36 ( V_6 , L_17 ) ;
return;
}
V_228 = F_86 ( sizeof( * V_228 ) , V_200 ) ;
if ( ! V_228 ) {
F_131 ( V_230 ) ;
return;
}
V_228 -> V_68 = V_6 -> V_18 -> V_68 ;
F_26 ( & V_228 -> V_229 , F_128 ) ;
F_91 ( & V_228 -> V_229 ) ;
} else if ( V_6 -> V_85 == V_240 ) {
F_43 ( V_6 , V_241 ) ;
if ( V_237 && V_6 -> V_76 > 0 )
V_6 -> V_76 -- ;
F_144 ( V_6 -> V_52 ) ;
}
}
static void F_145 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_146 ( V_6 ) ;
F_139 ( V_6 , true ) ;
}
static void F_147 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_13 ( 1 ) ;
F_139 ( V_6 , true ) ;
}
static bool F_148 ( struct V_5 * V_6 ,
struct V_242 * V_243 ,
struct V_244 * V_245 )
{
struct V_246 * V_247 = F_149 ( V_243 ) ;
struct V_248 * V_249 ;
struct V_250 * V_251 ;
T_4 V_252 = 0 ;
T_3 V_253 ;
if ( F_13 ( V_243 -> type != V_254 ||
V_247 -> V_255 == V_61 ) )
return false ;
V_249 = F_150 ( V_6 -> V_60 [ V_247 -> V_255 ] ) ;
if ( F_151 ( V_249 ) )
return false ;
V_251 = F_152 ( V_249 ) ;
F_71 ( & V_251 -> V_256 ) ;
for ( V_253 = 0 ; V_253 < V_257 ; V_253 ++ ) {
struct V_258 * V_259 = & V_251 -> V_259 [ V_253 ] ;
if ( F_153 ( V_259 ) )
continue;
if ( V_259 -> V_217 != V_260 )
continue;
V_252 |= F_154 ( V_253 ) ;
}
F_75 ( & V_251 -> V_256 ) ;
if ( ! V_252 )
return true ;
V_245 -> V_261 = F_155 ( V_252 ) - 1 ;
return false ;
}
static void F_156 ( void * V_262 , T_3 * V_263 ,
struct V_242 * V_243 )
{
struct V_244 * V_170 = V_262 ;
struct V_5 * V_6 = V_170 -> V_6 ;
struct V_246 * V_247 = F_149 ( V_243 ) ;
T_4 V_123 = V_264 | V_265 | V_266 ;
F_157 ( V_6 , L_18 , V_243 -> V_267 ) ;
if ( V_243 -> type != V_254 ||
! V_243 -> V_268 . V_269 )
return;
if ( F_148 ( V_6 , V_243 , V_170 ) )
V_170 -> V_270 = true ;
F_158 ( V_6 , V_243 , true , V_123 ) ;
F_159 ( V_6 , V_243 , V_170 -> V_270 ,
false , V_123 ) ;
V_170 -> V_255 = V_247 -> V_255 ;
V_170 -> V_271 ++ ;
V_170 -> V_272 = V_243 ;
}
static void F_160 ( struct V_5 * V_6 ,
struct V_273 * V_193 ,
struct V_244 * V_245 )
{
struct V_248 * V_249 ;
struct V_250 * V_274 ;
if ( V_245 -> V_255 == V_61 )
return;
F_161 () ;
V_249 = F_150 ( V_6 -> V_60 [ V_245 -> V_255 ] ) ;
if ( F_151 ( V_249 ) )
goto V_275;
V_274 = F_152 ( V_249 ) ;
V_193 -> V_276 = V_249 -> V_277 . V_278 ;
V_193 -> V_261 = V_245 -> V_261 ;
V_193 -> V_123 = V_279 | V_280 |
V_281 | V_282 ;
F_162 ( V_274 , V_193 ) ;
V_275:
F_163 () ;
}
int F_164 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
T_4 V_123 = V_264 | V_265 | V_266 ;
int V_1 ;
struct V_244 V_283 = {
. V_6 = V_6 ,
} ;
struct V_273 V_284 = {
. V_285 = F_165 ( V_286 |
V_287 |
V_288 ) ,
} ;
struct V_289 V_290 = {
. V_291 = F_165 ( 1000 ) ,
. V_292 = F_165 ( V_293 ) ,
} ;
F_157 ( V_6 , L_19 ) ;
if ( F_104 ( V_6 -> V_85 != V_240 ) )
return - V_294 ;
F_117 ( V_295 , & V_6 -> V_219 ) ;
if ( F_166 ( V_6 ) ) {
F_157 ( V_6 -> V_18 , L_20 ) ;
F_118 ( V_295 , & V_6 -> V_219 ) ;
F_167 ( & V_6 -> V_112 ) ;
return 1 ;
}
F_168 ( V_6 -> V_52 ,
V_296 ,
F_156 ,
& V_283 ) ;
if ( V_283 . V_271 == 1 ) {
V_6 -> V_297 = V_283 . V_255 ;
V_6 -> V_298 = ! V_283 . V_270 ;
} else {
F_104 ( V_283 . V_271 > 1 ) ;
V_6 -> V_297 = V_61 ;
V_6 -> V_298 = false ;
}
F_169 () ;
V_1 = F_170 ( V_6 , F_171 ( V_6 ) , V_123 ) ;
if ( V_1 )
return V_1 ;
if ( V_6 -> V_297 != V_61 ) {
if ( ! F_172 ( & V_6 -> V_48 -> V_121 ,
V_299 ) )
V_284 . V_285 |=
F_165 ( V_300 ) ;
F_173 ( V_6 ,
V_283 . V_272 ,
true , V_123 ) ;
F_160 ( V_6 , & V_284 ,
& V_283 ) ;
V_1 = F_174 ( V_6 , V_301 , V_123 ,
sizeof( V_284 ) ,
& V_284 ) ;
if ( V_1 )
return V_1 ;
}
return F_174 ( V_6 , V_302 ,
V_123 | V_303 ,
sizeof( V_290 ) , & V_290 ) ;
}
static void F_175 ( void * V_262 , T_3 * V_263 ,
struct V_242 * V_243 )
{
struct V_5 * V_6 = V_262 ;
T_4 V_123 = V_264 | V_265 ;
F_157 ( V_6 , L_21 , V_243 -> V_267 ) ;
if ( V_243 -> type != V_254 ||
! V_243 -> V_268 . V_269 )
return;
F_158 ( V_6 , V_243 , false , V_123 ) ;
}
static void F_176 ( void * V_262 , T_3 * V_263 ,
struct V_242 * V_243 )
{
struct V_304 * V_170 = V_262 ;
struct V_246 * V_247 = F_149 ( V_243 ) ;
T_4 V_305 = V_170 -> V_306 ;
if ( V_243 -> type != V_254 || ! V_243 -> V_268 . V_269 ||
V_170 -> V_6 -> V_297 != V_247 -> V_255 )
return;
if ( V_305 & V_307 )
F_177 ( V_170 -> V_6 , V_243 , L_22 ) ;
else if ( V_305 & V_308 )
F_178 ( V_243 ) ;
else
F_179 ( V_170 -> V_6 , V_243 , V_170 -> V_219 ) ;
}
void F_180 ( struct V_5 * V_6 , T_5 * V_309 )
{
struct V_248 * V_310 = NULL ;
struct V_250 * V_274 ;
int V_162 ;
bool V_311 = false ;
F_181 ( & V_6 -> V_88 ) ;
F_71 ( & V_6 -> V_109 ) ;
if ( V_6 -> V_297 == V_61 )
goto V_275;
F_157 ( V_6 , L_23 ) ;
V_310 = F_182 (
V_6 -> V_60 [ V_6 -> V_297 ] ,
F_183 ( & V_6 -> V_88 ) ) ;
if ( F_151 ( V_310 ) ) {
V_310 = NULL ;
goto V_275;
}
if ( V_6 -> V_298 && V_309 ) {
V_274 = F_152 ( V_310 ) ;
for ( V_162 = 0 ; V_162 < V_257 ; V_162 ++ ) {
T_6 V_312 = F_184 ( V_309 [ V_162 ] ) ;
V_312 += 0x10 ;
V_274 -> V_259 [ V_162 ] . V_313 = V_312 ;
}
}
V_275:
while ( ! F_185 ( & V_6 -> V_111 ) ) {
struct V_222 * V_223 = F_186 ( & V_6 -> V_111 ) ;
if ( ! V_310 || F_187 ( V_6 , V_223 , V_310 ) )
F_127 ( V_6 -> V_52 , V_223 ) ;
V_311 = true ;
}
F_118 ( V_295 , & V_6 -> V_219 ) ;
F_167 ( & V_6 -> V_112 ) ;
V_6 -> V_297 = V_61 ;
if ( V_311 )
F_188 ( V_6 -> V_52 ) ;
F_75 ( & V_6 -> V_109 ) ;
}
static void V_103 ( struct V_176 * V_177 )
{
struct V_5 * V_6 = F_76 ( V_177 , struct V_5 , V_102 ) ;
struct V_314 V_315 = {
. V_316 = V_317 ,
. V_123 = V_265 | V_318 ,
} ;
struct V_304 V_245 = {
. V_6 = V_6 ,
} ;
struct V_319 * V_219 ;
int V_1 ;
T_4 V_306 = 0 ;
T_5 * V_309 = NULL ;
F_42 ( & V_6 -> V_88 ) ;
V_1 = F_189 ( V_6 , & V_315 ) ;
if ( V_1 )
goto V_275;
if ( ! V_315 . V_320 )
goto V_275;
V_219 = ( void * ) V_315 . V_320 -> V_170 ;
V_306 = F_190 ( V_219 -> V_306 ) ;
V_309 = V_219 -> V_321 ;
F_157 ( V_6 , L_24 , V_306 ) ;
V_245 . V_306 = V_306 ;
V_245 . V_219 = V_219 ;
F_191 ( V_6 -> V_52 ,
V_296 ,
F_176 ,
& V_245 ) ;
V_275:
F_180 ( V_6 , V_309 ) ;
F_15 ( V_6 , L_25 ,
V_306 ) ;
if ( V_315 . V_320 )
F_192 ( & V_315 ) ;
F_193 ( V_6 ) ;
F_46 ( V_6 , V_322 ) ;
F_47 ( & V_6 -> V_88 ) ;
}
int F_194 ( struct V_5 * V_6 )
{
T_4 V_123 = V_264 | V_265 | V_266 |
V_323 ;
int V_1 ;
F_157 ( V_6 , L_26 ) ;
if ( F_104 ( V_6 -> V_85 != V_240 ) )
return - V_294 ;
F_42 ( & V_6 -> V_89 ) ;
if ( F_137 ( V_324 , & V_6 -> V_325 ) ) {
F_157 ( V_6 , L_27 ) ;
F_195 ( V_326 , & V_6 -> V_325 ) ;
F_47 ( & V_6 -> V_89 ) ;
return 0 ;
}
F_47 ( & V_6 -> V_89 ) ;
V_1 = F_174 ( V_6 , V_327 , V_123 , 0 , NULL ) ;
if ( V_1 )
goto V_275;
F_168 ( V_6 -> V_52 ,
V_296 ,
F_175 ,
V_6 ) ;
V_275:
F_91 ( & V_6 -> V_102 ) ;
return V_1 ;
}
int F_196 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_43 ( V_6 , V_322 ) ;
return F_194 ( V_6 ) ;
}
static void F_197 ( struct V_3 * V_4 ,
struct V_204 * V_205 ,
struct V_195 * V_174 ,
unsigned int V_328 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
struct V_183 * V_184 = F_93 ( V_174 ) ;
if ( F_101 ( V_184 -> V_192 . V_193 == V_206 ) )
F_96 ( V_6 , V_174 , V_328 ) ;
else if ( F_101 ( V_184 -> V_192 . V_193 == V_209 &&
V_184 -> V_192 . V_194 == V_208 ) )
F_102 ( V_6 , V_174 , V_328 ) ;
else
F_99 ( V_6 , V_205 , V_174 , V_328 ) ;
}
