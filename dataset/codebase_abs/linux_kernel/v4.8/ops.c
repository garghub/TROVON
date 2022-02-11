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
static void F_18 ( struct V_47 * V_48 )
{
struct V_5 * V_6 =
F_19 ( V_48 , struct V_5 , V_49 . V_48 ) ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
F_20 ( & V_6 -> V_54 ) ;
V_51 =
F_21 ( V_6 -> V_55 ,
F_22 ( & V_6 -> V_54 ) ) ;
if ( ! V_51 )
goto V_56;
V_53 = F_23 ( V_51 ) ;
F_24 ( V_6 , V_53 , false ) ;
F_25 ( V_6 -> V_55 , NULL ) ;
V_56:
F_26 ( & V_6 -> V_54 ) ;
}
static struct V_3 *
F_27 ( struct V_39 * V_18 , const struct V_40 * V_26 ,
const struct V_57 * V_58 , struct V_59 * V_60 )
{
struct V_61 * V_62 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_63 V_64 = {} ;
static const T_3 V_65 [] = {
V_66 ,
} ;
int V_67 , V_68 ;
T_4 V_69 ;
F_28 ( F_29 ( V_6 -> V_70 ) != V_71 ) ;
V_62 = F_30 ( sizeof( struct V_3 ) +
sizeof( struct V_5 ) ,
& V_72 ) ;
if ( ! V_62 )
return NULL ;
if ( V_26 -> V_73 )
V_62 -> V_74 = V_26 -> V_73 ;
if ( V_26 -> V_75 )
V_62 -> V_76 = V_26 -> V_75 ;
V_4 = V_62 -> V_77 ;
V_6 = F_9 ( V_4 ) ;
V_6 -> V_78 = V_18 -> V_78 ;
V_6 -> V_18 = V_18 ;
V_6 -> V_26 = V_26 ;
V_6 -> V_58 = V_58 ;
V_6 -> V_62 = V_62 ;
if ( F_31 ( V_6 ) ) {
V_4 -> V_79 = & V_80 ;
V_18 -> V_81 = sizeof( struct V_82 ) ;
} else {
V_4 -> V_79 = & V_2 ;
V_18 -> V_81 =
sizeof( struct V_83 ) ;
if ( F_13 ( V_18 -> V_84 > 1 ) )
goto V_85;
}
V_6 -> V_86 = V_87 . V_86 ? - 1 : 0 ;
if ( ! F_32 ( V_6 ) ) {
V_6 -> V_88 = V_6 -> V_26 -> V_89 -> V_90 - 1 ;
if ( V_6 -> V_26 -> V_89 -> V_90 == 16 ) {
V_6 -> V_91 = 11 ;
V_6 -> V_92 = 12 ;
} else {
V_6 -> V_91 = 15 ;
V_6 -> V_92 = 16 ;
}
} else {
V_6 -> V_91 = V_93 ;
V_6 -> V_92 = V_94 ;
V_6 -> V_88 = V_95 ;
}
V_6 -> V_96 = V_97 ;
V_6 -> V_98 = V_99 ;
V_6 -> V_100 = true ;
F_33 ( & V_6 -> V_54 ) ;
F_33 ( & V_6 -> V_101 ) ;
F_34 ( & V_6 -> V_102 ) ;
F_35 ( & V_6 -> V_103 ) ;
F_35 ( & V_6 -> V_104 ) ;
F_35 ( & V_6 -> V_105 ) ;
F_34 ( & V_6 -> V_106 ) ;
F_34 ( & V_6 -> V_107 ) ;
F_36 ( & V_6 -> V_108 , V_109 ) ;
F_36 ( & V_6 -> V_110 , V_111 ) ;
F_36 ( & V_6 -> V_112 , V_113 ) ;
F_36 ( & V_6 -> V_114 , V_115 ) ;
F_37 ( & V_6 -> V_116 , V_117 ) ;
F_37 ( & V_6 -> V_118 . V_119 , V_120 ) ;
F_37 ( & V_6 -> V_121 , V_122 ) ;
F_36 ( & V_6 -> V_123 , V_124 ) ;
F_34 ( & V_6 -> V_125 ) ;
F_34 ( & V_6 -> V_126 ) ;
F_38 ( & V_6 -> V_127 ) ;
F_39 ( & V_6 -> V_128 ) ;
F_40 ( & V_6 -> V_129 , 0 ) ;
F_41 ( V_6 -> V_62 , V_6 -> V_18 -> V_78 ) ;
F_37 ( & V_6 -> V_49 , F_18 ) ;
V_64 . V_4 = V_4 ;
V_64 . V_65 = V_65 ;
V_64 . V_130 = F_29 ( V_65 ) ;
switch ( V_87 . V_131 ) {
case V_132 :
case V_133 :
V_64 . V_134 = V_133 ;
break;
case V_135 :
V_64 . V_134 = V_135 ;
break;
case V_136 :
V_64 . V_134 = V_136 ;
break;
default:
F_3 ( L_5 , V_137 ,
V_87 . V_131 ) ;
V_64 . V_134 = V_133 ;
}
if ( V_6 -> V_26 -> V_138 )
V_64 . V_134 = V_133 ;
V_64 . V_139 = F_42 ( & V_6 -> V_58 -> V_140 ,
V_141 ) ;
if ( V_6 -> V_58 -> V_140 . V_142 & V_143 )
V_64 . V_144 = true ;
V_64 . V_145 = V_146 ;
V_64 . V_147 = F_29 ( V_146 ) ;
if ( F_32 ( V_6 ) )
V_64 . V_148 = V_149 ;
else
V_64 . V_148 = V_150 ;
V_64 . V_151 = V_152 ;
V_64 . V_153 = true ;
V_64 . V_154 = F_43 ( struct V_155 ,
V_156 [ 2 ] ) ;
V_64 . V_157 = V_58 -> V_157 ;
V_64 . V_158 = V_159 ;
V_64 . V_160 =
F_44 ( V_6 , NULL , false , true ) ;
snprintf ( V_6 -> V_62 -> V_161 -> V_162 ,
sizeof( V_6 -> V_62 -> V_161 -> V_162 ) ,
L_6 , V_58 -> V_162 ) ;
F_45 ( V_6 -> V_18 , & V_64 ) ;
V_18 -> V_163 = V_164 ;
V_18 -> V_165 = V_6 -> V_58 -> V_165 ;
V_18 -> V_166 = V_6 -> V_58 -> V_166 ;
memcpy ( V_18 -> V_167 , V_6 -> V_58 -> V_167 ,
sizeof( V_18 -> V_167 ) ) ;
V_18 -> V_168 = V_6 -> V_58 -> V_168 ;
F_46 ( & V_6 -> V_169 ) ;
V_6 -> V_170 = F_47 ( V_18 ) ;
if ( ! V_6 -> V_170 ) {
F_48 ( V_6 , L_7 ) ;
goto V_85;
}
F_49 ( V_6 , L_8 ,
V_6 -> V_26 -> V_171 , V_6 -> V_18 -> V_19 ) ;
if ( V_87 . V_172 )
V_6 -> V_173 = V_87 . V_172 ;
else
F_50 ( V_6 -> V_18 -> V_78 ,
L_9 ) ;
if ( F_51 ( V_26 -> V_174 && ! V_6 -> V_173 ,
L_10 ) )
goto V_85;
if ( V_26 -> V_174 && V_6 -> V_173 ) {
V_67 = F_52 ( V_6 , false ) ;
if ( V_67 )
goto V_85;
} else {
V_67 = F_53 ( V_6 -> V_18 ) ;
if ( V_67 )
goto V_85;
F_20 ( & V_6 -> V_54 ) ;
F_54 ( V_6 , V_175 ) ;
V_67 = F_55 ( V_6 , true ) ;
if ( ! V_67 || ! V_176 . V_177 )
F_56 ( V_6 ) ;
F_57 ( V_6 , V_175 ) ;
F_26 ( & V_6 -> V_54 ) ;
if ( V_67 < 0 && ! V_176 . V_177 ) {
F_48 ( V_6 , L_11 , V_67 ) ;
goto V_85;
}
}
V_68 = F_58 ( V_6 ) ;
V_6 -> V_178 = F_59 ( V_68 , V_179 ) ;
if ( ! V_6 -> V_178 )
goto V_85;
V_6 -> V_180 = true ;
V_67 = F_60 ( V_6 ) ;
if ( V_67 )
goto V_85;
V_69 = F_17 ( V_18 , V_26 ) ;
F_61 ( V_6 , V_69 ) ;
V_67 = F_62 ( V_6 , V_60 ) ;
if ( V_67 )
goto V_181;
memset ( & V_6 -> V_182 , 0 , sizeof( struct V_183 ) ) ;
if ( F_63 ( V_6 ) )
F_64 ( V_6 -> V_18 ) ;
F_65 ( V_6 ) ;
return V_4 ;
V_181:
F_66 ( V_6 -> V_62 ) ;
F_67 ( V_6 ) ;
F_68 ( V_6 ) ;
V_85:
F_69 ( & V_6 -> V_116 ) ;
F_70 ( V_6 -> V_170 ) ;
F_71 ( V_6 -> V_178 ) ;
if ( ! V_26 -> V_174 || ! V_6 -> V_173 )
F_72 ( V_18 ) ;
F_73 ( V_6 -> V_62 ) ;
return NULL ;
}
static void F_74 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
int V_184 ;
if ( F_63 ( V_6 ) )
F_75 ( V_6 -> V_18 ) ;
F_67 ( V_6 ) ;
F_68 ( V_6 ) ;
F_66 ( V_6 -> V_62 ) ;
F_71 ( V_6 -> V_178 ) ;
F_71 ( V_6 -> V_185 ) ;
V_6 -> V_185 = NULL ;
#if F_76 ( V_186 ) && F_76 ( V_187 )
F_71 ( V_6 -> V_188 ) ;
#endif
F_72 ( V_6 -> V_18 ) ;
F_70 ( V_6 -> V_170 ) ;
V_6 -> V_170 = NULL ;
F_77 ( V_6 -> V_189 ) ;
for ( V_184 = 0 ; V_184 < V_190 ; V_184 ++ )
F_71 ( V_6 -> V_191 [ V_184 ] . V_192 ) ;
F_78 ( V_6 ) ;
F_79 ( & V_6 -> V_54 ) ;
F_79 ( & V_6 -> V_101 ) ;
F_73 ( V_6 -> V_62 ) ;
}
void F_80 ( struct V_5 * V_6 )
{
struct V_193 * V_194 , * V_195 ;
F_81 ( & V_6 -> V_102 ) ;
F_82 (entry, tmp, &mvm->async_handlers_list, list) {
F_83 ( & V_194 -> V_196 ) ;
F_84 ( & V_194 -> V_197 ) ;
F_71 ( V_194 ) ;
}
F_85 ( & V_6 -> V_102 ) ;
}
static void V_109 ( struct V_47 * V_198 )
{
struct V_5 * V_6 =
F_19 ( V_198 , struct V_5 , V_108 ) ;
struct V_193 * V_194 , * V_195 ;
struct V_199 V_200 ;
F_35 ( & V_200 ) ;
F_81 ( & V_6 -> V_102 ) ;
F_86 ( & V_6 -> V_105 , & V_200 ) ;
F_85 ( & V_6 -> V_102 ) ;
F_82 (entry, tmp, &local_list, list) {
if ( V_194 -> V_201 == V_202 )
F_20 ( & V_6 -> V_54 ) ;
V_194 -> V_203 ( V_6 , & V_194 -> V_196 ) ;
F_83 ( & V_194 -> V_196 ) ;
F_84 ( & V_194 -> V_197 ) ;
if ( V_194 -> V_201 == V_202 )
F_26 ( & V_6 -> V_54 ) ;
F_71 ( V_194 ) ;
}
}
static inline void F_87 ( struct V_5 * V_6 ,
struct V_204 * V_205 )
{
struct V_206 * V_207 ;
struct V_208 * V_209 ;
int V_184 ;
if ( ! F_88 ( V_6 -> V_58 , V_210 ) )
return;
V_207 = F_89 ( V_6 -> V_58 , V_210 ) ;
V_209 = ( void * ) V_207 -> V_192 ;
if ( ! F_90 ( V_6 , NULL , V_207 ) )
return;
for ( V_184 = 0 ; V_184 < F_29 ( V_209 -> V_211 ) ; V_184 ++ ) {
if ( ! V_209 -> V_211 [ V_184 ] . V_212 )
break;
if ( V_209 -> V_211 [ V_184 ] . V_212 != V_205 -> V_213 . V_214 ||
V_209 -> V_211 [ V_184 ] . V_215 != V_205 -> V_213 . V_215 )
continue;
F_91 ( V_6 , V_207 ,
L_12 ,
V_205 -> V_213 . V_215 , V_205 -> V_213 . V_214 ) ;
break;
}
}
static void F_92 ( struct V_5 * V_6 ,
struct V_216 * V_196 ,
struct V_204 * V_205 )
{
int V_184 ;
F_87 ( V_6 , V_205 ) ;
F_93 ( & V_6 -> V_169 , V_205 ) ;
for ( V_184 = 0 ; V_184 < F_29 ( V_217 ) ; V_184 ++ ) {
const struct V_218 * V_219 = & V_217 [ V_184 ] ;
struct V_193 * V_194 ;
if ( V_219 -> V_212 != F_94 ( V_205 -> V_213 . V_215 , V_205 -> V_213 . V_214 ) )
continue;
if ( V_219 -> V_201 == V_220 ) {
V_219 -> V_203 ( V_6 , V_196 ) ;
return;
}
V_194 = F_95 ( sizeof( * V_194 ) , V_221 ) ;
if ( ! V_194 )
return;
V_194 -> V_196 . V_222 = F_96 ( V_196 ) ;
V_194 -> V_196 . V_223 = V_196 -> V_223 ;
V_194 -> V_196 . V_224 = V_196 -> V_224 ;
V_194 -> V_203 = V_219 -> V_203 ;
V_194 -> V_201 = V_219 -> V_201 ;
F_97 ( & V_6 -> V_102 ) ;
F_98 ( & V_194 -> V_197 , & V_6 -> V_105 ) ;
F_99 ( & V_6 -> V_102 ) ;
F_100 ( & V_6 -> V_108 ) ;
break;
}
}
static void F_101 ( struct V_3 * V_4 ,
struct V_225 * V_226 ,
struct V_216 * V_196 )
{
struct V_204 * V_205 = F_102 ( V_196 ) ;
struct V_5 * V_6 = F_9 ( V_4 ) ;
if ( F_103 ( V_205 -> V_213 . V_214 == V_164 ) )
F_104 ( V_6 , V_226 , V_196 ) ;
else if ( V_205 -> V_213 . V_214 == V_227 )
F_105 ( V_6 , V_196 ) ;
else
F_92 ( V_6 , V_196 , V_205 ) ;
}
static void F_106 ( struct V_3 * V_4 ,
struct V_225 * V_226 ,
struct V_216 * V_196 )
{
struct V_204 * V_205 = F_102 ( V_196 ) ;
struct V_5 * V_6 = F_9 ( V_4 ) ;
if ( F_103 ( V_205 -> V_213 . V_214 == V_164 ) )
F_107 ( V_6 , V_226 , V_196 , 0 ) ;
else if ( F_108 ( V_205 -> V_213 . V_215 == V_228 &&
V_205 -> V_213 . V_214 == V_229 ) )
F_109 ( V_6 , V_196 , 0 ) ;
else if ( V_205 -> V_213 . V_214 == V_230 )
F_110 ( V_6 , V_226 , V_196 , 0 ) ;
else
F_92 ( V_6 , V_196 , V_205 ) ;
}
void F_111 ( struct V_5 * V_6 , unsigned long V_231 )
{
int V_232 ;
if ( F_112 ( ! V_231 ) )
return;
F_113 (q, &mq, IEEE80211_MAX_QUEUES) {
if ( F_114 ( & V_6 -> V_233 [ V_232 ] ) > 1 ) {
F_115 ( V_6 ,
L_13 , V_232 ) ;
continue;
}
F_116 ( V_6 -> V_62 , V_232 ) ;
}
}
static void F_117 ( struct V_3 * V_4 ,
const struct V_234 * V_214 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_118 ( V_6 -> V_18 , false ) ;
}
static void F_119 ( struct V_3 * V_4 , int V_235 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
unsigned long V_231 ;
F_81 ( & V_6 -> V_107 ) ;
V_231 = V_6 -> V_236 [ V_235 ] . V_237 ;
F_85 ( & V_6 -> V_107 ) ;
F_111 ( V_6 , V_231 ) ;
}
void F_120 ( struct V_5 * V_6 , unsigned long V_231 )
{
int V_232 ;
if ( F_112 ( ! V_231 ) )
return;
F_113 (q, &mq, IEEE80211_MAX_QUEUES) {
if ( F_121 ( & V_6 -> V_233 [ V_232 ] ) > 0 ) {
F_115 ( V_6 ,
L_14 , V_232 ) ;
continue;
}
F_122 ( V_6 -> V_62 , V_232 ) ;
}
}
static void F_123 ( struct V_3 * V_4 , int V_235 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
unsigned long V_231 ;
F_81 ( & V_6 -> V_107 ) ;
V_231 = V_6 -> V_236 [ V_235 ] . V_237 ;
F_85 ( & V_6 -> V_107 ) ;
F_120 ( V_6 , V_231 ) ;
}
void F_124 ( struct V_5 * V_6 , bool V_238 )
{
if ( V_238 )
F_125 ( V_239 , & V_6 -> V_240 ) ;
else
F_126 ( V_239 , & V_6 -> V_240 ) ;
F_127 ( V_6 -> V_62 -> V_161 , F_128 ( V_6 ) ) ;
}
static bool F_129 ( struct V_3 * V_4 , bool V_238 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
bool V_241 = F_130 ( V_6 -> V_241 ) ;
if ( V_238 )
F_125 ( V_242 , & V_6 -> V_240 ) ;
else
F_126 ( V_242 , & V_6 -> V_240 ) ;
F_127 ( V_6 -> V_62 -> V_161 , F_128 ( V_6 ) ) ;
if ( V_241 )
F_131 ( & V_6 -> V_169 ) ;
return V_238 && ( V_6 -> V_98 != V_99 || V_241 ) ;
}
static void F_132 ( struct V_3 * V_4 , struct V_243 * V_244 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
struct V_155 * V_245 ;
V_245 = F_133 ( V_244 ) ;
F_134 ( V_6 -> V_18 , V_245 -> V_156 [ 1 ] ) ;
F_135 ( V_6 -> V_62 , V_244 ) ;
}
static void F_136 ( struct V_47 * V_198 )
{
struct V_246 * V_247 ;
V_247 = F_19 ( V_198 , struct V_246 , V_48 ) ;
if ( F_137 ( V_247 -> V_78 ) )
F_138 ( V_247 -> V_78 , L_15 ) ;
F_71 ( V_247 ) ;
F_139 ( V_248 ) ;
}
static void V_117 ( struct V_47 * V_48 )
{
struct V_5 * V_6 =
F_19 ( V_48 , struct V_5 , V_116 . V_48 ) ;
if ( F_140 ( V_6 , V_249 ) )
return;
F_20 ( & V_6 -> V_54 ) ;
if ( V_6 -> V_26 -> V_27 == V_250 ) {
F_141 ( V_6 -> V_18 , V_251 , 0x100 ) ;
} else {
F_142 ( V_6 -> V_18 , V_252 , 0 ) ;
F_143 ( 100 ) ;
}
F_144 ( V_6 ) ;
F_112 ( ( ! F_145 ( V_253 , & V_6 -> V_18 -> V_240 ) ) &&
V_6 -> V_58 -> V_165 &&
F_146 ( V_6 , V_6 -> V_254 ) ) ;
F_26 ( & V_6 -> V_54 ) ;
F_57 ( V_6 , V_249 ) ;
}
void F_147 ( struct V_5 * V_6 , bool V_255 )
{
F_131 ( & V_6 -> V_169 ) ;
F_148 ( V_6 ) ;
if ( ! V_6 -> V_86 && V_255 ) {
F_149 ( V_6 , & V_256 ,
NULL ) ;
} else if ( F_150 ( V_257 ,
& V_6 -> V_240 ) ) {
struct V_246 * V_247 ;
F_48 ( V_6 ,
L_16 ) ;
if ( ! F_151 ( V_248 ) ) {
F_48 ( V_6 , L_17 ) ;
return;
}
V_247 = F_95 ( sizeof( * V_247 ) , V_221 ) ;
if ( ! V_247 ) {
F_139 ( V_248 ) ;
return;
}
V_247 -> V_78 = V_6 -> V_18 -> V_78 ;
F_36 ( & V_247 -> V_48 , F_136 ) ;
F_100 ( & V_247 -> V_48 ) ;
} else if ( V_6 -> V_98 == V_258 ) {
F_54 ( V_6 , V_259 ) ;
if ( V_255 && V_6 -> V_86 > 0 )
V_6 -> V_86 -- ;
F_152 ( V_6 -> V_62 ) ;
}
}
static void F_153 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_154 ( V_6 ) ;
F_147 ( V_6 , true ) ;
}
static void F_155 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_13 ( 1 ) ;
F_147 ( V_6 , true ) ;
}
static bool F_156 ( struct V_5 * V_6 ,
struct V_50 * V_260 ,
struct V_261 * V_262 )
{
struct V_52 * V_53 = F_23 ( V_260 ) ;
struct V_263 * V_264 ;
T_4 V_265 = 0 ;
T_3 V_266 ;
if ( F_13 ( V_260 -> type != V_267 ||
V_53 -> V_268 == V_71 ) )
return false ;
V_264 = F_157 ( V_6 , V_53 -> V_268 ) ;
if ( ! V_264 )
return false ;
F_81 ( & V_264 -> V_269 ) ;
for ( V_266 = 0 ; V_266 < V_270 ; V_266 ++ ) {
struct V_271 * V_272 = & V_264 -> V_272 [ V_266 ] ;
if ( F_158 ( V_272 ) )
continue;
if ( V_272 -> V_238 != V_273 )
continue;
V_265 |= F_159 ( V_266 ) ;
}
F_85 ( & V_264 -> V_269 ) ;
if ( ! V_265 )
return true ;
V_262 -> V_274 = F_160 ( V_265 ) - 1 ;
return false ;
}
static void F_161 ( void * V_275 , T_3 * V_276 ,
struct V_50 * V_260 )
{
struct V_261 * V_192 = V_275 ;
struct V_5 * V_6 = V_192 -> V_6 ;
struct V_52 * V_53 = F_23 ( V_260 ) ;
T_4 V_142 = V_277 | V_278 | V_279 ;
F_162 ( V_6 , L_18 , V_260 -> V_280 ) ;
if ( V_260 -> type != V_267 ||
! V_260 -> V_281 . V_282 )
return;
if ( F_156 ( V_6 , V_260 , V_192 ) )
V_192 -> V_283 = true ;
F_163 ( V_6 , V_260 , true , V_142 ) ;
F_164 ( V_6 , V_260 , V_192 -> V_283 ,
false , V_142 ) ;
V_192 -> V_268 = V_53 -> V_268 ;
V_192 -> V_284 ++ ;
V_192 -> V_285 = V_260 ;
}
static void F_165 ( struct V_5 * V_6 ,
struct V_286 * V_214 ,
struct V_261 * V_262 )
{
struct V_287 * V_288 ;
struct V_263 * V_289 ;
if ( V_262 -> V_268 == V_71 )
return;
F_166 () ;
V_288 = F_167 ( V_6 -> V_70 [ V_262 -> V_268 ] ) ;
if ( F_168 ( V_288 ) )
goto V_290;
V_289 = F_169 ( V_288 ) ;
V_214 -> V_291 = V_288 -> V_292 . V_293 ;
V_214 -> V_274 = V_262 -> V_274 ;
V_214 -> V_142 = V_294 | V_295 |
V_296 | V_297 ;
F_170 ( V_289 , V_214 ) ;
V_290:
F_171 () ;
}
int F_172 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
T_4 V_142 = V_277 | V_278 | V_279 ;
int V_1 ;
struct V_261 V_298 = {
. V_6 = V_6 ,
} ;
struct V_286 V_299 = {
. V_300 = F_173 ( V_301 |
V_302 |
V_303 ) ,
} ;
struct V_304 V_305 = {
. V_306 = F_173 ( 1000 ) ,
. V_307 = F_173 ( V_308 ) ,
} ;
F_162 ( V_6 , L_19 ) ;
if ( F_112 ( V_6 -> V_98 != V_258 ) )
return - V_309 ;
F_125 ( V_310 , & V_6 -> V_240 ) ;
if ( F_174 ( V_6 ) ) {
F_162 ( V_6 -> V_18 , L_20 ) ;
F_126 ( V_310 , & V_6 -> V_240 ) ;
F_175 ( & V_6 -> V_128 ) ;
return 1 ;
}
F_176 ( V_6 -> V_62 ,
V_311 ,
F_161 ,
& V_298 ) ;
if ( V_298 . V_284 == 1 ) {
V_6 -> V_312 = V_298 . V_268 ;
V_6 -> V_313 = ! V_298 . V_283 ;
} else {
F_112 ( V_298 . V_284 > 1 ) ;
V_6 -> V_312 = V_71 ;
V_6 -> V_313 = false ;
}
F_177 () ;
V_1 = F_178 ( V_6 , F_179 ( V_6 ) , V_142 ) ;
if ( V_1 )
return V_1 ;
if ( V_6 -> V_312 != V_71 ) {
if ( ! F_180 ( & V_6 -> V_58 -> V_140 ,
V_314 ) )
V_299 . V_300 |=
F_173 ( V_315 ) ;
F_181 ( V_6 ,
V_298 . V_285 ,
true , V_142 ) ;
F_165 ( V_6 , & V_299 ,
& V_298 ) ;
V_1 = F_182 ( V_6 , V_316 , V_142 ,
sizeof( V_299 ) ,
& V_299 ) ;
if ( V_1 )
return V_1 ;
}
return F_182 ( V_6 , V_317 ,
V_142 | V_318 ,
sizeof( V_305 ) , & V_305 ) ;
}
static void F_183 ( void * V_275 , T_3 * V_276 ,
struct V_50 * V_260 )
{
struct V_5 * V_6 = V_275 ;
T_4 V_142 = V_277 | V_278 ;
F_162 ( V_6 , L_21 , V_260 -> V_280 ) ;
if ( V_260 -> type != V_267 ||
! V_260 -> V_281 . V_282 )
return;
F_163 ( V_6 , V_260 , false , V_142 ) ;
}
static void F_184 ( void * V_275 , T_3 * V_276 ,
struct V_50 * V_260 )
{
struct V_319 * V_192 = V_275 ;
struct V_52 * V_53 = F_23 ( V_260 ) ;
T_4 V_320 = V_192 -> V_321 ;
if ( V_260 -> type != V_267 || ! V_260 -> V_281 . V_282 ||
V_192 -> V_6 -> V_312 != V_53 -> V_268 )
return;
if ( V_320 & V_322 )
F_185 ( V_192 -> V_6 , V_260 , L_22 ) ;
else if ( V_320 & V_323 )
F_186 ( V_260 ) ;
else
F_187 ( V_192 -> V_6 , V_260 , V_192 -> V_240 ) ;
}
void F_188 ( struct V_5 * V_6 , T_5 * V_324 )
{
struct V_287 * V_325 = NULL ;
struct V_263 * V_289 ;
int V_184 ;
bool V_326 = false ;
F_189 ( & V_6 -> V_54 ) ;
F_81 ( & V_6 -> V_125 ) ;
if ( V_6 -> V_312 == V_71 )
goto V_290;
F_162 ( V_6 , L_23 ) ;
V_325 = F_21 (
V_6 -> V_70 [ V_6 -> V_312 ] ,
F_22 ( & V_6 -> V_54 ) ) ;
if ( F_168 ( V_325 ) ) {
V_325 = NULL ;
goto V_290;
}
if ( V_6 -> V_313 && V_324 ) {
V_289 = F_169 ( V_325 ) ;
for ( V_184 = 0 ; V_184 < V_270 ; V_184 ++ ) {
T_6 V_327 = F_190 ( V_324 [ V_184 ] ) ;
V_327 += 0x10 ;
V_289 -> V_272 [ V_184 ] . V_328 = V_327 ;
}
}
V_290:
while ( ! F_191 ( & V_6 -> V_127 ) ) {
struct V_243 * V_244 = F_192 ( & V_6 -> V_127 ) ;
if ( ! V_325 || F_193 ( V_6 , V_244 , V_325 ) )
F_135 ( V_6 -> V_62 , V_244 ) ;
V_326 = true ;
}
F_126 ( V_310 , & V_6 -> V_240 ) ;
F_175 ( & V_6 -> V_128 ) ;
V_6 -> V_312 = V_71 ;
if ( V_326 )
F_194 ( V_6 -> V_62 ) ;
F_85 ( & V_6 -> V_125 ) ;
}
static void V_115 ( struct V_47 * V_198 )
{
struct V_5 * V_6 = F_19 ( V_198 , struct V_5 , V_114 ) ;
struct V_329 V_330 = {
. V_331 = V_332 ,
. V_142 = V_278 | V_333 ,
} ;
struct V_319 V_262 = {
. V_6 = V_6 ,
} ;
struct V_334 * V_240 ;
int V_1 ;
T_4 V_321 = 0 ;
T_5 * V_324 = NULL ;
F_20 ( & V_6 -> V_54 ) ;
V_1 = F_195 ( V_6 , & V_330 ) ;
if ( V_1 )
goto V_290;
if ( ! V_330 . V_335 )
goto V_290;
V_240 = ( void * ) V_330 . V_335 -> V_192 ;
V_321 = F_196 ( V_240 -> V_321 ) ;
V_324 = V_240 -> V_336 ;
F_162 ( V_6 , L_24 , V_321 ) ;
V_262 . V_321 = V_321 ;
V_262 . V_240 = V_240 ;
F_197 ( V_6 -> V_62 ,
V_311 ,
F_184 ,
& V_262 ) ;
V_290:
F_188 ( V_6 , V_324 ) ;
F_15 ( V_6 , L_25 ,
V_321 ) ;
if ( V_330 . V_335 )
F_198 ( & V_330 ) ;
F_199 ( V_6 ) ;
F_57 ( V_6 , V_337 ) ;
F_26 ( & V_6 -> V_54 ) ;
}
int F_200 ( struct V_5 * V_6 )
{
T_4 V_142 = V_277 | V_278 | V_279 |
V_338 ;
int V_1 ;
F_162 ( V_6 , L_26 ) ;
if ( F_112 ( V_6 -> V_98 != V_258 ) )
return - V_309 ;
F_20 ( & V_6 -> V_101 ) ;
if ( F_145 ( V_339 , & V_6 -> V_340 ) ) {
F_162 ( V_6 , L_27 ) ;
F_201 ( V_341 , & V_6 -> V_340 ) ;
F_26 ( & V_6 -> V_101 ) ;
return 0 ;
}
F_26 ( & V_6 -> V_101 ) ;
V_1 = F_182 ( V_6 , V_342 , V_142 , 0 , NULL ) ;
if ( V_1 )
goto V_290;
F_176 ( V_6 -> V_62 ,
V_311 ,
F_183 ,
V_6 ) ;
V_290:
F_100 ( & V_6 -> V_114 ) ;
return V_1 ;
}
int F_202 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_54 ( V_6 , V_337 ) ;
return F_200 ( V_6 ) ;
}
static void F_203 ( struct V_3 * V_4 ,
struct V_225 * V_226 ,
struct V_216 * V_196 ,
unsigned int V_343 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
struct V_204 * V_205 = F_102 ( V_196 ) ;
if ( F_108 ( V_205 -> V_213 . V_214 == V_230 ) )
F_110 ( V_6 , V_226 , V_196 , V_343 ) ;
else if ( F_108 ( V_205 -> V_213 . V_214 == V_229 &&
V_205 -> V_213 . V_215 == V_228 ) )
F_109 ( V_6 , V_196 , V_343 ) ;
else
F_107 ( V_6 , V_226 , V_196 , V_343 ) ;
}
