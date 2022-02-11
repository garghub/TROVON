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
if ( F_33 ( V_6 ) )
V_6 -> V_98 = V_99 ;
else
V_6 -> V_98 = V_100 ;
V_6 -> V_101 = true ;
F_34 ( & V_6 -> V_54 ) ;
F_34 ( & V_6 -> V_102 ) ;
F_35 ( & V_6 -> V_103 ) ;
F_36 ( & V_6 -> V_104 ) ;
F_36 ( & V_6 -> V_105 ) ;
F_36 ( & V_6 -> V_106 ) ;
F_35 ( & V_6 -> V_107 ) ;
F_35 ( & V_6 -> V_108 ) ;
F_37 ( & V_6 -> V_109 , V_110 ) ;
F_37 ( & V_6 -> V_111 , V_112 ) ;
F_37 ( & V_6 -> V_113 , V_114 ) ;
F_37 ( & V_6 -> V_115 , V_116 ) ;
F_38 ( & V_6 -> V_117 , V_118 ) ;
F_38 ( & V_6 -> V_119 . V_120 , V_121 ) ;
F_38 ( & V_6 -> V_122 , V_123 ) ;
F_37 ( & V_6 -> V_124 , V_125 ) ;
F_35 ( & V_6 -> V_126 ) ;
F_35 ( & V_6 -> V_127 ) ;
F_39 ( & V_6 -> V_128 ) ;
F_40 ( & V_6 -> V_129 ) ;
F_40 ( & V_6 -> V_130 ) ;
F_41 ( & V_6 -> V_131 , 0 ) ;
F_42 ( V_6 -> V_62 , V_6 -> V_18 -> V_78 ) ;
F_38 ( & V_6 -> V_49 , F_18 ) ;
V_64 . V_4 = V_4 ;
V_64 . V_65 = V_65 ;
V_64 . V_132 = F_29 ( V_65 ) ;
switch ( V_87 . V_133 ) {
case V_134 :
case V_135 :
V_64 . V_136 = V_135 ;
break;
case V_137 :
V_64 . V_136 = V_137 ;
break;
case V_138 :
V_64 . V_136 = V_138 ;
break;
default:
F_3 ( L_5 , V_139 ,
V_87 . V_133 ) ;
V_64 . V_136 = V_135 ;
}
if ( V_6 -> V_26 -> V_140 )
V_64 . V_136 = V_135 ;
V_18 -> V_141 = true ;
V_64 . V_142 = true ;
V_64 . V_143 = V_144 ;
V_64 . V_145 = F_29 ( V_144 ) ;
if ( F_32 ( V_6 ) )
V_64 . V_146 = V_147 ;
else
V_64 . V_146 = V_148 ;
V_64 . V_149 = V_150 ;
V_64 . V_151 = true ;
V_64 . V_152 = F_43 ( struct V_153 ,
V_154 [ 2 ] ) ;
V_64 . V_155 = V_58 -> V_155 ;
V_64 . V_156 = V_157 ;
V_64 . V_158 =
F_44 ( V_6 , NULL , false , true ) ;
snprintf ( V_6 -> V_62 -> V_159 -> V_160 ,
sizeof( V_6 -> V_62 -> V_159 -> V_160 ) ,
L_6 , V_58 -> V_160 ) ;
F_45 ( V_6 -> V_18 , & V_64 ) ;
V_18 -> V_161 = V_162 ;
V_18 -> V_163 = V_6 -> V_58 -> V_163 ;
V_18 -> V_164 = V_6 -> V_58 -> V_164 ;
memcpy ( V_18 -> V_165 , V_6 -> V_58 -> V_165 ,
sizeof( V_18 -> V_165 ) ) ;
V_18 -> V_166 = V_6 -> V_58 -> V_166 ;
F_46 ( & V_6 -> V_167 ) ;
V_6 -> V_168 = F_47 ( V_18 ) ;
if ( ! V_6 -> V_168 ) {
F_48 ( V_6 , L_7 ) ;
goto V_85;
}
F_49 ( V_6 , L_8 ,
V_6 -> V_26 -> V_169 , V_6 -> V_18 -> V_19 ) ;
if ( V_87 . V_170 )
V_6 -> V_171 = V_87 . V_170 ;
else
F_50 ( V_6 -> V_18 -> V_78 ,
L_9 ) ;
V_67 = F_51 ( V_6 -> V_18 ) ;
if ( V_67 )
goto V_85;
F_20 ( & V_6 -> V_54 ) ;
F_52 ( V_6 , V_172 ) ;
if ( F_33 ( V_6 ) )
V_67 = F_53 ( V_6 , true ) ;
else
V_67 = F_54 ( V_6 , true ) ;
if ( ! V_67 || ! V_173 . V_174 )
F_55 ( V_6 ) ;
F_56 ( V_6 , V_172 ) ;
F_26 ( & V_6 -> V_54 ) ;
if ( V_67 < 0 && ! V_173 . V_174 ) {
F_48 ( V_6 , L_10 , V_67 ) ;
goto V_85;
}
V_68 = F_57 ( V_6 ) ;
V_6 -> V_175 = F_58 ( V_68 , V_176 ) ;
if ( ! V_6 -> V_175 )
goto V_85;
V_6 -> V_177 = true ;
V_67 = F_59 ( V_6 ) ;
if ( V_67 )
goto V_85;
V_6 -> V_178 = true ;
V_69 = F_17 ( V_18 , V_26 ) ;
F_60 ( V_6 , V_69 ) ;
V_67 = F_61 ( V_6 , V_60 ) ;
if ( V_67 )
goto V_179;
memset ( & V_6 -> V_180 , 0 , sizeof( struct V_181 ) ) ;
if ( F_62 ( V_6 ) )
F_63 ( V_6 -> V_18 ) ;
F_64 ( V_6 ) ;
return V_4 ;
V_179:
F_65 ( V_6 -> V_62 ) ;
V_6 -> V_178 = false ;
F_66 ( V_6 ) ;
F_67 ( V_6 ) ;
V_85:
F_68 ( & V_6 -> V_117 ) ;
F_69 ( V_6 -> V_168 ) ;
F_70 ( V_6 -> V_175 ) ;
F_71 ( V_18 ) ;
F_72 ( V_6 -> V_62 ) ;
return NULL ;
}
static void F_73 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
int V_182 ;
if ( F_62 ( V_6 ) )
F_74 ( V_6 -> V_18 ) ;
F_66 ( V_6 ) ;
F_67 ( V_6 ) ;
F_65 ( V_6 -> V_62 ) ;
F_70 ( V_6 -> V_175 ) ;
F_70 ( V_6 -> V_183 ) ;
V_6 -> V_183 = NULL ;
#if F_75 ( V_184 ) && F_75 ( V_185 )
F_70 ( V_6 -> V_186 ) ;
#endif
F_71 ( V_6 -> V_18 ) ;
F_69 ( V_6 -> V_168 ) ;
V_6 -> V_168 = NULL ;
F_76 ( V_6 -> V_187 ) ;
for ( V_182 = 0 ; V_182 < V_188 ; V_182 ++ )
F_70 ( V_6 -> V_189 [ V_182 ] . V_190 ) ;
F_77 ( V_6 ) ;
F_78 ( & V_6 -> V_54 ) ;
F_78 ( & V_6 -> V_102 ) ;
F_72 ( V_6 -> V_62 ) ;
}
void F_79 ( struct V_5 * V_6 )
{
struct V_191 * V_192 , * V_193 ;
F_80 ( & V_6 -> V_103 ) ;
F_81 (entry, tmp, &mvm->async_handlers_list, list) {
F_82 ( & V_192 -> V_194 ) ;
F_83 ( & V_192 -> V_195 ) ;
F_70 ( V_192 ) ;
}
F_84 ( & V_6 -> V_103 ) ;
}
static void V_110 ( struct V_47 * V_196 )
{
struct V_5 * V_6 =
F_19 ( V_196 , struct V_5 , V_109 ) ;
struct V_191 * V_192 , * V_193 ;
F_85 ( V_197 ) ;
F_80 ( & V_6 -> V_103 ) ;
F_86 ( & V_6 -> V_106 , & V_197 ) ;
F_84 ( & V_6 -> V_103 ) ;
F_81 (entry, tmp, &local_list, list) {
if ( V_192 -> V_198 == V_199 )
F_20 ( & V_6 -> V_54 ) ;
V_192 -> V_200 ( V_6 , & V_192 -> V_194 ) ;
F_82 ( & V_192 -> V_194 ) ;
F_83 ( & V_192 -> V_195 ) ;
if ( V_192 -> V_198 == V_199 )
F_26 ( & V_6 -> V_54 ) ;
F_70 ( V_192 ) ;
}
}
static inline void F_87 ( struct V_5 * V_6 ,
struct V_201 * V_202 )
{
struct V_203 * V_204 ;
struct V_205 * V_206 ;
int V_182 ;
if ( ! F_88 ( V_6 -> V_58 , V_207 ) )
return;
V_204 = F_89 ( V_6 -> V_58 , V_207 ) ;
V_206 = ( void * ) V_204 -> V_190 ;
if ( ! F_90 ( V_6 , NULL , V_204 ) )
return;
for ( V_182 = 0 ; V_182 < F_29 ( V_206 -> V_208 ) ; V_182 ++ ) {
if ( ! V_206 -> V_208 [ V_182 ] . V_209 )
break;
if ( V_206 -> V_208 [ V_182 ] . V_209 != V_202 -> V_210 . V_211 ||
V_206 -> V_208 [ V_182 ] . V_212 != V_202 -> V_210 . V_212 )
continue;
F_91 ( V_6 , V_204 ,
L_11 ,
V_202 -> V_210 . V_212 , V_202 -> V_210 . V_211 ) ;
break;
}
}
static void F_92 ( struct V_5 * V_6 ,
struct V_213 * V_194 ,
struct V_201 * V_202 )
{
int V_182 ;
F_87 ( V_6 , V_202 ) ;
F_93 ( & V_6 -> V_167 , V_202 ) ;
for ( V_182 = 0 ; V_182 < F_29 ( V_214 ) ; V_182 ++ ) {
const struct V_215 * V_216 = & V_214 [ V_182 ] ;
struct V_191 * V_192 ;
if ( V_216 -> V_209 != F_94 ( V_202 -> V_210 . V_212 , V_202 -> V_210 . V_211 ) )
continue;
if ( V_216 -> V_198 == V_217 ) {
V_216 -> V_200 ( V_6 , V_194 ) ;
return;
}
V_192 = F_95 ( sizeof( * V_192 ) , V_218 ) ;
if ( ! V_192 )
return;
V_192 -> V_194 . V_219 = F_96 ( V_194 ) ;
V_192 -> V_194 . V_220 = V_194 -> V_220 ;
V_192 -> V_194 . V_221 = V_194 -> V_221 ;
V_192 -> V_200 = V_216 -> V_200 ;
V_192 -> V_198 = V_216 -> V_198 ;
F_97 ( & V_6 -> V_103 ) ;
F_98 ( & V_192 -> V_195 , & V_6 -> V_106 ) ;
F_99 ( & V_6 -> V_103 ) ;
F_100 ( & V_6 -> V_109 ) ;
break;
}
}
static void F_101 ( struct V_3 * V_4 ,
struct V_222 * V_223 ,
struct V_213 * V_194 )
{
struct V_201 * V_202 = F_102 ( V_194 ) ;
struct V_5 * V_6 = F_9 ( V_4 ) ;
T_5 V_211 = F_94 ( V_202 -> V_210 . V_212 , V_202 -> V_210 . V_211 ) ;
if ( F_103 ( V_211 == F_94 ( V_224 , V_162 ) ) )
F_104 ( V_6 , V_223 , V_194 ) ;
else if ( V_211 == F_94 ( V_224 , V_225 ) )
F_105 ( V_6 , V_194 ) ;
else
F_92 ( V_6 , V_194 , V_202 ) ;
}
static void F_106 ( struct V_3 * V_4 ,
struct V_222 * V_223 ,
struct V_213 * V_194 )
{
struct V_201 * V_202 = F_102 ( V_194 ) ;
struct V_5 * V_6 = F_9 ( V_4 ) ;
T_5 V_211 = F_94 ( V_202 -> V_210 . V_212 , V_202 -> V_210 . V_211 ) ;
if ( F_103 ( V_211 == F_94 ( V_224 , V_162 ) ) )
F_107 ( V_6 , V_223 , V_194 , 0 ) ;
else if ( F_108 ( V_211 == F_94 ( V_226 ,
V_227 ) ) )
F_109 ( V_6 , V_194 , 0 ) ;
else if ( V_211 == F_94 ( V_224 , V_228 ) )
F_110 ( V_6 , V_223 , V_194 , 0 ) ;
else
F_92 ( V_6 , V_194 , V_202 ) ;
}
void F_111 ( struct V_5 * V_6 , unsigned long V_229 )
{
int V_230 ;
if ( F_112 ( ! V_229 ) )
return;
F_113 (q, &mq, IEEE80211_MAX_QUEUES) {
if ( F_114 ( & V_6 -> V_231 [ V_230 ] ) > 1 ) {
F_115 ( V_6 ,
L_12 , V_230 ) ;
continue;
}
F_116 ( V_6 -> V_62 , V_230 ) ;
}
}
static void F_117 ( struct V_3 * V_4 ,
const struct V_232 * V_211 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_118 ( V_6 -> V_18 , false ) ;
}
static void F_119 ( struct V_3 * V_4 , int V_233 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
unsigned long V_229 ;
F_80 ( & V_6 -> V_108 ) ;
V_229 = V_6 -> V_234 [ V_233 ] . V_235 ;
F_84 ( & V_6 -> V_108 ) ;
F_111 ( V_6 , V_229 ) ;
}
void F_120 ( struct V_5 * V_6 , unsigned long V_229 )
{
int V_230 ;
if ( F_112 ( ! V_229 ) )
return;
F_113 (q, &mq, IEEE80211_MAX_QUEUES) {
if ( F_121 ( & V_6 -> V_231 [ V_230 ] ) > 0 ) {
F_115 ( V_6 ,
L_13 , V_230 ) ;
continue;
}
F_122 ( V_6 -> V_62 , V_230 ) ;
}
}
static void F_123 ( struct V_3 * V_4 , int V_233 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
unsigned long V_229 ;
F_80 ( & V_6 -> V_108 ) ;
V_229 = V_6 -> V_234 [ V_233 ] . V_235 ;
F_84 ( & V_6 -> V_108 ) ;
F_120 ( V_6 , V_229 ) ;
}
void F_124 ( struct V_5 * V_6 , bool V_236 )
{
if ( V_236 )
F_125 ( V_237 , & V_6 -> V_238 ) ;
else
F_126 ( V_237 , & V_6 -> V_238 ) ;
F_127 ( V_6 -> V_62 -> V_159 , F_128 ( V_6 ) ) ;
}
static bool F_129 ( struct V_3 * V_4 , bool V_236 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
bool V_239 = F_130 ( V_6 -> V_239 ) ;
if ( V_236 )
F_125 ( V_240 , & V_6 -> V_238 ) ;
else
F_126 ( V_240 , & V_6 -> V_238 ) ;
F_127 ( V_6 -> V_62 -> V_159 , F_128 ( V_6 ) ) ;
if ( V_239 )
F_131 ( & V_6 -> V_167 ) ;
return V_236 && ( V_6 -> V_98 != V_100 || V_239 ) ;
}
static void F_132 ( struct V_3 * V_4 , struct V_241 * V_242 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
struct V_153 * V_243 ;
V_243 = F_133 ( V_242 ) ;
F_134 ( V_6 -> V_18 , V_243 -> V_154 [ 1 ] ) ;
F_135 ( V_6 -> V_62 , V_242 ) ;
}
static void F_136 ( struct V_47 * V_196 )
{
struct V_244 * V_245 ;
V_245 = F_19 ( V_196 , struct V_244 , V_48 ) ;
if ( F_137 ( V_245 -> V_78 ) )
F_138 ( V_245 -> V_78 , L_14 ) ;
F_70 ( V_245 ) ;
F_139 ( V_246 ) ;
}
static void V_118 ( struct V_47 * V_48 )
{
struct V_5 * V_6 =
F_19 ( V_48 , struct V_5 , V_117 . V_48 ) ;
if ( F_140 ( V_6 , V_247 ) )
return;
F_20 ( & V_6 -> V_54 ) ;
if ( V_6 -> V_26 -> V_27 == V_248 ) {
F_141 ( V_6 -> V_18 , V_249 , 0x100 ) ;
} else {
F_142 ( V_6 -> V_18 , V_250 , 0 ) ;
F_143 ( 100 ) ;
}
F_144 ( V_6 ) ;
F_112 ( ( ! F_145 ( V_251 , & V_6 -> V_18 -> V_238 ) ) &&
V_6 -> V_58 -> V_163 &&
F_146 ( V_6 , V_6 -> V_252 ) ) ;
F_26 ( & V_6 -> V_54 ) ;
F_56 ( V_6 , V_247 ) ;
}
void F_147 ( struct V_5 * V_6 , bool V_253 )
{
F_131 ( & V_6 -> V_167 ) ;
F_148 ( V_6 ) ;
if ( ! V_6 -> V_86 && V_253 ) {
F_149 ( V_6 , & V_254 ,
NULL ) ;
} else if ( F_150 ( V_255 ,
& V_6 -> V_238 ) ) {
struct V_244 * V_245 ;
F_48 ( V_6 ,
L_15 ) ;
if ( ! F_151 ( V_246 ) ) {
F_48 ( V_6 , L_16 ) ;
return;
}
V_245 = F_95 ( sizeof( * V_245 ) , V_218 ) ;
if ( ! V_245 ) {
F_139 ( V_246 ) ;
return;
}
V_245 -> V_78 = V_6 -> V_18 -> V_78 ;
F_37 ( & V_245 -> V_48 , F_136 ) ;
F_100 ( & V_245 -> V_48 ) ;
} else if ( V_6 -> V_98 == V_99 &&
V_6 -> V_178 ) {
F_52 ( V_6 , V_256 ) ;
if ( V_253 && V_6 -> V_86 > 0 )
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
struct V_50 * V_257 ,
struct V_258 * V_259 )
{
struct V_52 * V_53 = F_23 ( V_257 ) ;
struct V_260 * V_261 ;
T_4 V_262 = 0 ;
T_3 V_263 ;
if ( F_13 ( V_257 -> type != V_264 ||
V_53 -> V_265 == V_71 ) )
return false ;
V_261 = F_157 ( V_6 , V_53 -> V_265 ) ;
if ( ! V_261 )
return false ;
F_80 ( & V_261 -> V_266 ) ;
for ( V_263 = 0 ; V_263 < V_267 ; V_263 ++ ) {
struct V_268 * V_269 = & V_261 -> V_269 [ V_263 ] ;
if ( F_158 ( V_269 ) )
continue;
if ( V_269 -> V_236 != V_270 )
continue;
V_262 |= F_159 ( V_263 ) ;
}
F_84 ( & V_261 -> V_266 ) ;
if ( ! V_262 )
return true ;
V_259 -> V_271 = F_160 ( V_262 ) - 1 ;
return false ;
}
static void F_161 ( void * V_272 , T_3 * V_273 ,
struct V_50 * V_257 )
{
struct V_258 * V_190 = V_272 ;
struct V_5 * V_6 = V_190 -> V_6 ;
struct V_52 * V_53 = F_23 ( V_257 ) ;
T_4 V_274 = V_275 | V_276 | V_277 ;
F_162 ( V_6 , L_17 , V_257 -> V_278 ) ;
if ( V_257 -> type != V_264 ||
! V_257 -> V_279 . V_280 )
return;
if ( F_156 ( V_6 , V_257 , V_190 ) )
V_190 -> V_281 = true ;
F_163 ( V_6 , V_257 , true , V_274 ) ;
F_164 ( V_6 , V_257 , V_190 -> V_281 ,
false , V_274 ) ;
V_190 -> V_265 = V_53 -> V_265 ;
V_190 -> V_282 ++ ;
V_190 -> V_283 = V_257 ;
}
static void F_165 ( struct V_5 * V_6 ,
struct V_284 * V_211 ,
struct V_258 * V_259 )
{
struct V_285 * V_286 ;
struct V_260 * V_287 ;
if ( V_259 -> V_265 == V_71 )
return;
F_166 () ;
V_286 = F_167 ( V_6 -> V_70 [ V_259 -> V_265 ] ) ;
if ( F_168 ( V_286 ) )
goto V_288;
V_287 = F_169 ( V_286 ) ;
V_211 -> V_289 = V_286 -> V_290 . V_291 ;
V_211 -> V_271 = V_259 -> V_271 ;
V_211 -> V_274 = V_292 | V_293 |
V_294 | V_295 ;
F_170 ( V_287 , V_211 ) ;
V_288:
F_171 () ;
}
int F_172 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
T_4 V_274 = V_275 | V_276 | V_277 ;
int V_1 ;
struct V_258 V_296 = {
. V_6 = V_6 ,
} ;
struct V_284 V_297 = {
. V_298 = F_173 ( V_299 |
V_300 |
V_301 ) ,
} ;
struct V_302 V_303 = {
. V_304 = F_173 ( 1000 ) ,
. V_305 = F_173 ( V_306 ) ,
} ;
F_162 ( V_6 , L_18 ) ;
if ( F_112 ( V_6 -> V_98 != V_99 ) )
return - V_307 ;
F_125 ( V_308 , & V_6 -> V_238 ) ;
if ( F_174 ( V_6 ) ) {
F_162 ( V_6 -> V_18 , L_19 ) ;
F_126 ( V_308 , & V_6 -> V_238 ) ;
F_175 ( & V_6 -> V_129 ) ;
return 1 ;
}
F_176 ( V_6 -> V_62 ,
V_309 ,
F_161 ,
& V_296 ) ;
if ( V_296 . V_282 == 1 ) {
V_6 -> V_310 = V_296 . V_265 ;
V_6 -> V_311 = ! V_296 . V_281 ;
} else {
F_112 ( V_296 . V_282 > 1 ) ;
V_6 -> V_310 = V_71 ;
V_6 -> V_311 = false ;
}
F_177 () ;
V_1 = F_178 ( V_6 , F_179 ( V_6 ) , V_274 ) ;
if ( V_1 )
return V_1 ;
if ( V_6 -> V_310 != V_71 ) {
if ( ! F_180 ( & V_6 -> V_58 -> V_312 ,
V_313 ) )
V_297 . V_298 |=
F_173 ( V_314 ) ;
F_181 ( V_6 ,
V_296 . V_283 ,
true , V_274 ) ;
F_165 ( V_6 , & V_297 ,
& V_296 ) ;
V_1 = F_182 ( V_6 , V_315 , V_274 ,
sizeof( V_297 ) ,
& V_297 ) ;
if ( V_1 )
return V_1 ;
}
return F_182 ( V_6 , V_316 ,
V_274 | V_317 ,
sizeof( V_303 ) , & V_303 ) ;
}
static void F_183 ( void * V_272 , T_3 * V_273 ,
struct V_50 * V_257 )
{
struct V_5 * V_6 = V_272 ;
T_4 V_274 = V_275 | V_276 ;
F_162 ( V_6 , L_20 , V_257 -> V_278 ) ;
if ( V_257 -> type != V_264 ||
! V_257 -> V_279 . V_280 )
return;
F_163 ( V_6 , V_257 , false , V_274 ) ;
}
static void F_184 ( void * V_272 , T_3 * V_273 ,
struct V_50 * V_257 )
{
struct V_318 * V_190 = V_272 ;
struct V_52 * V_53 = F_23 ( V_257 ) ;
T_4 V_319 = V_190 -> V_320 ;
if ( V_257 -> type != V_264 || ! V_257 -> V_279 . V_280 ||
V_190 -> V_6 -> V_310 != V_53 -> V_265 )
return;
if ( V_319 & V_321 )
F_185 ( V_190 -> V_6 , V_257 , L_21 ) ;
else if ( V_319 & V_322 )
F_186 ( V_257 ) ;
else
F_187 ( V_190 -> V_6 , V_257 , V_190 -> V_238 ) ;
}
void F_188 ( struct V_5 * V_6 , T_6 * V_323 )
{
struct V_285 * V_324 = NULL ;
struct V_260 * V_287 ;
int V_182 ;
bool V_325 = false ;
F_189 ( & V_6 -> V_54 ) ;
F_80 ( & V_6 -> V_126 ) ;
if ( V_6 -> V_310 == V_71 )
goto V_288;
F_162 ( V_6 , L_22 ) ;
V_324 = F_21 (
V_6 -> V_70 [ V_6 -> V_310 ] ,
F_22 ( & V_6 -> V_54 ) ) ;
if ( F_168 ( V_324 ) ) {
V_324 = NULL ;
goto V_288;
}
if ( V_6 -> V_311 && V_323 ) {
V_287 = F_169 ( V_324 ) ;
for ( V_182 = 0 ; V_182 < V_267 ; V_182 ++ ) {
T_5 V_326 = F_190 ( V_323 [ V_182 ] ) ;
V_326 += 0x10 ;
V_287 -> V_269 [ V_182 ] . V_327 = V_326 ;
}
}
V_288:
while ( ! F_191 ( & V_6 -> V_128 ) ) {
struct V_241 * V_242 = F_192 ( & V_6 -> V_128 ) ;
if ( ! V_324 || F_193 ( V_6 , V_242 , V_324 ) )
F_135 ( V_6 -> V_62 , V_242 ) ;
V_325 = true ;
}
F_126 ( V_308 , & V_6 -> V_238 ) ;
F_175 ( & V_6 -> V_129 ) ;
V_6 -> V_310 = V_71 ;
if ( V_325 )
F_194 ( V_6 -> V_62 ) ;
F_84 ( & V_6 -> V_126 ) ;
}
static void V_116 ( struct V_47 * V_196 )
{
struct V_5 * V_6 = F_19 ( V_196 , struct V_5 , V_115 ) ;
struct V_328 V_329 = {
. V_330 = V_331 ,
. V_274 = V_276 | V_332 ,
} ;
struct V_318 V_259 = {
. V_6 = V_6 ,
} ;
struct V_333 * V_238 ;
int V_1 ;
T_4 V_320 = 0 ;
T_6 * V_323 = NULL ;
F_20 ( & V_6 -> V_54 ) ;
V_1 = F_195 ( V_6 , & V_329 ) ;
if ( V_1 )
goto V_288;
if ( ! V_329 . V_334 )
goto V_288;
V_238 = ( void * ) V_329 . V_334 -> V_190 ;
V_320 = F_196 ( V_238 -> V_320 ) ;
V_323 = V_238 -> V_335 ;
F_162 ( V_6 , L_23 , V_320 ) ;
V_259 . V_320 = V_320 ;
V_259 . V_238 = V_238 ;
F_197 ( V_6 -> V_62 ,
V_309 ,
F_184 ,
& V_259 ) ;
V_288:
F_188 ( V_6 , V_323 ) ;
F_15 ( V_6 , L_24 ,
V_320 ) ;
if ( V_329 . V_334 )
F_198 ( & V_329 ) ;
F_199 ( V_6 ) ;
F_56 ( V_6 , V_336 ) ;
F_26 ( & V_6 -> V_54 ) ;
}
int F_200 ( struct V_5 * V_6 )
{
T_4 V_274 = V_275 | V_276 | V_277 |
V_337 ;
int V_1 ;
F_162 ( V_6 , L_25 ) ;
if ( F_112 ( V_6 -> V_98 != V_99 ) )
return - V_307 ;
F_20 ( & V_6 -> V_102 ) ;
if ( F_145 ( V_338 , & V_6 -> V_339 ) ) {
F_162 ( V_6 , L_26 ) ;
F_201 ( V_340 , & V_6 -> V_339 ) ;
F_26 ( & V_6 -> V_102 ) ;
return 0 ;
}
F_26 ( & V_6 -> V_102 ) ;
V_1 = F_182 ( V_6 , V_341 , V_274 , 0 , NULL ) ;
if ( V_1 )
goto V_288;
F_176 ( V_6 -> V_62 ,
V_309 ,
F_183 ,
V_6 ) ;
V_288:
F_100 ( & V_6 -> V_115 ) ;
return V_1 ;
}
int F_202 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_52 ( V_6 , V_336 ) ;
return F_200 ( V_6 ) ;
}
static void F_203 ( struct V_3 * V_4 ,
struct V_222 * V_223 ,
struct V_213 * V_194 ,
unsigned int V_342 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
struct V_201 * V_202 = F_102 ( V_194 ) ;
T_5 V_211 = F_94 ( V_202 -> V_210 . V_212 , V_202 -> V_210 . V_211 ) ;
if ( F_108 ( V_211 == F_94 ( V_224 , V_228 ) ) )
F_110 ( V_6 , V_223 , V_194 , V_342 ) ;
else if ( F_108 ( V_211 == F_94 ( V_226 ,
V_227 ) ) )
F_109 ( V_6 , V_194 , V_342 ) ;
else if ( F_103 ( V_211 == F_94 ( V_224 , V_162 ) ) )
F_107 ( V_6 , V_223 , V_194 , V_342 ) ;
}
