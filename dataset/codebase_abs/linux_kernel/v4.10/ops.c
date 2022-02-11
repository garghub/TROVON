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
F_39 ( & V_6 -> V_129 ) ;
F_40 ( & V_6 -> V_130 , 0 ) ;
F_41 ( V_6 -> V_62 , V_6 -> V_18 -> V_78 ) ;
F_37 ( & V_6 -> V_49 , F_18 ) ;
V_64 . V_4 = V_4 ;
V_64 . V_65 = V_65 ;
V_64 . V_131 = F_29 ( V_65 ) ;
switch ( V_87 . V_132 ) {
case V_133 :
case V_134 :
V_64 . V_135 = V_134 ;
break;
case V_136 :
V_64 . V_135 = V_136 ;
break;
case V_137 :
V_64 . V_135 = V_137 ;
break;
default:
F_3 ( L_5 , V_138 ,
V_87 . V_132 ) ;
V_64 . V_135 = V_134 ;
}
if ( V_6 -> V_26 -> V_139 )
V_64 . V_135 = V_134 ;
V_18 -> V_140 = true ;
V_64 . V_141 = true ;
V_64 . V_142 = V_143 ;
V_64 . V_144 = F_29 ( V_143 ) ;
if ( F_32 ( V_6 ) )
V_64 . V_145 = V_146 ;
else
V_64 . V_145 = V_147 ;
V_64 . V_148 = V_149 ;
V_64 . V_150 = true ;
V_64 . V_151 = F_42 ( struct V_152 ,
V_153 [ 2 ] ) ;
V_64 . V_154 = V_58 -> V_154 ;
V_64 . V_155 = V_156 ;
V_64 . V_157 =
F_43 ( V_6 , NULL , false , true ) ;
snprintf ( V_6 -> V_62 -> V_158 -> V_159 ,
sizeof( V_6 -> V_62 -> V_158 -> V_159 ) ,
L_6 , V_58 -> V_159 ) ;
F_44 ( V_6 -> V_18 , & V_64 ) ;
V_18 -> V_160 = V_161 ;
V_18 -> V_162 = V_6 -> V_58 -> V_162 ;
V_18 -> V_163 = V_6 -> V_58 -> V_163 ;
memcpy ( V_18 -> V_164 , V_6 -> V_58 -> V_164 ,
sizeof( V_18 -> V_164 ) ) ;
V_18 -> V_165 = V_6 -> V_58 -> V_165 ;
F_45 ( & V_6 -> V_166 ) ;
V_6 -> V_167 = F_46 ( V_18 ) ;
if ( ! V_6 -> V_167 ) {
F_47 ( V_6 , L_7 ) ;
goto V_85;
}
F_48 ( V_6 , L_8 ,
V_6 -> V_26 -> V_168 , V_6 -> V_18 -> V_19 ) ;
if ( V_87 . V_169 )
V_6 -> V_170 = V_87 . V_169 ;
else
F_49 ( V_6 -> V_18 -> V_78 ,
L_9 ) ;
V_67 = F_50 ( V_6 -> V_18 ) ;
if ( V_67 )
goto V_85;
F_20 ( & V_6 -> V_54 ) ;
F_51 ( V_6 , V_171 ) ;
V_67 = F_52 ( V_6 , true ) ;
if ( ! V_67 || ! V_172 . V_173 )
F_53 ( V_6 ) ;
F_54 ( V_6 , V_171 ) ;
F_26 ( & V_6 -> V_54 ) ;
if ( V_67 < 0 && ! V_172 . V_173 ) {
F_47 ( V_6 , L_10 , V_67 ) ;
goto V_85;
}
V_68 = F_55 ( V_6 ) ;
V_6 -> V_174 = F_56 ( V_68 , V_175 ) ;
if ( ! V_6 -> V_174 )
goto V_85;
V_6 -> V_176 = true ;
V_67 = F_57 ( V_6 ) ;
if ( V_67 )
goto V_85;
V_69 = F_17 ( V_18 , V_26 ) ;
F_58 ( V_6 , V_69 ) ;
V_67 = F_59 ( V_6 , V_60 ) ;
if ( V_67 )
goto V_177;
memset ( & V_6 -> V_178 , 0 , sizeof( struct V_179 ) ) ;
if ( F_60 ( V_6 ) )
F_61 ( V_6 -> V_18 ) ;
F_62 ( V_6 ) ;
return V_4 ;
V_177:
F_63 ( V_6 -> V_62 ) ;
F_64 ( V_6 ) ;
F_65 ( V_6 ) ;
V_85:
F_66 ( & V_6 -> V_116 ) ;
F_67 ( V_6 -> V_167 ) ;
F_68 ( V_6 -> V_174 ) ;
F_69 ( V_18 ) ;
F_70 ( V_6 -> V_62 ) ;
return NULL ;
}
static void F_71 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
int V_180 ;
if ( F_60 ( V_6 ) )
F_72 ( V_6 -> V_18 ) ;
F_64 ( V_6 ) ;
F_65 ( V_6 ) ;
F_63 ( V_6 -> V_62 ) ;
F_68 ( V_6 -> V_174 ) ;
F_68 ( V_6 -> V_181 ) ;
V_6 -> V_181 = NULL ;
#if F_73 ( V_182 ) && F_73 ( V_183 )
F_68 ( V_6 -> V_184 ) ;
#endif
F_69 ( V_6 -> V_18 ) ;
F_67 ( V_6 -> V_167 ) ;
V_6 -> V_167 = NULL ;
F_74 ( V_6 -> V_185 ) ;
for ( V_180 = 0 ; V_180 < V_186 ; V_180 ++ )
F_68 ( V_6 -> V_187 [ V_180 ] . V_188 ) ;
F_75 ( V_6 ) ;
F_76 ( & V_6 -> V_54 ) ;
F_76 ( & V_6 -> V_101 ) ;
F_70 ( V_6 -> V_62 ) ;
}
void F_77 ( struct V_5 * V_6 )
{
struct V_189 * V_190 , * V_191 ;
F_78 ( & V_6 -> V_102 ) ;
F_79 (entry, tmp, &mvm->async_handlers_list, list) {
F_80 ( & V_190 -> V_192 ) ;
F_81 ( & V_190 -> V_193 ) ;
F_68 ( V_190 ) ;
}
F_82 ( & V_6 -> V_102 ) ;
}
static void V_109 ( struct V_47 * V_194 )
{
struct V_5 * V_6 =
F_19 ( V_194 , struct V_5 , V_108 ) ;
struct V_189 * V_190 , * V_191 ;
F_83 ( V_195 ) ;
F_78 ( & V_6 -> V_102 ) ;
F_84 ( & V_6 -> V_105 , & V_195 ) ;
F_82 ( & V_6 -> V_102 ) ;
F_79 (entry, tmp, &local_list, list) {
if ( V_190 -> V_196 == V_197 )
F_20 ( & V_6 -> V_54 ) ;
V_190 -> V_198 ( V_6 , & V_190 -> V_192 ) ;
F_80 ( & V_190 -> V_192 ) ;
F_81 ( & V_190 -> V_193 ) ;
if ( V_190 -> V_196 == V_197 )
F_26 ( & V_6 -> V_54 ) ;
F_68 ( V_190 ) ;
}
}
static inline void F_85 ( struct V_5 * V_6 ,
struct V_199 * V_200 )
{
struct V_201 * V_202 ;
struct V_203 * V_204 ;
int V_180 ;
if ( ! F_86 ( V_6 -> V_58 , V_205 ) )
return;
V_202 = F_87 ( V_6 -> V_58 , V_205 ) ;
V_204 = ( void * ) V_202 -> V_188 ;
if ( ! F_88 ( V_6 , NULL , V_202 ) )
return;
for ( V_180 = 0 ; V_180 < F_29 ( V_204 -> V_206 ) ; V_180 ++ ) {
if ( ! V_204 -> V_206 [ V_180 ] . V_207 )
break;
if ( V_204 -> V_206 [ V_180 ] . V_207 != V_200 -> V_208 . V_209 ||
V_204 -> V_206 [ V_180 ] . V_210 != V_200 -> V_208 . V_210 )
continue;
F_89 ( V_6 , V_202 ,
L_11 ,
V_200 -> V_208 . V_210 , V_200 -> V_208 . V_209 ) ;
break;
}
}
static void F_90 ( struct V_5 * V_6 ,
struct V_211 * V_192 ,
struct V_199 * V_200 )
{
int V_180 ;
F_85 ( V_6 , V_200 ) ;
F_91 ( & V_6 -> V_166 , V_200 ) ;
for ( V_180 = 0 ; V_180 < F_29 ( V_212 ) ; V_180 ++ ) {
const struct V_213 * V_214 = & V_212 [ V_180 ] ;
struct V_189 * V_190 ;
if ( V_214 -> V_207 != F_92 ( V_200 -> V_208 . V_210 , V_200 -> V_208 . V_209 ) )
continue;
if ( V_214 -> V_196 == V_215 ) {
V_214 -> V_198 ( V_6 , V_192 ) ;
return;
}
V_190 = F_93 ( sizeof( * V_190 ) , V_216 ) ;
if ( ! V_190 )
return;
V_190 -> V_192 . V_217 = F_94 ( V_192 ) ;
V_190 -> V_192 . V_218 = V_192 -> V_218 ;
V_190 -> V_192 . V_219 = V_192 -> V_219 ;
V_190 -> V_198 = V_214 -> V_198 ;
V_190 -> V_196 = V_214 -> V_196 ;
F_95 ( & V_6 -> V_102 ) ;
F_96 ( & V_190 -> V_193 , & V_6 -> V_105 ) ;
F_97 ( & V_6 -> V_102 ) ;
F_98 ( & V_6 -> V_108 ) ;
break;
}
}
static void F_99 ( struct V_3 * V_4 ,
struct V_220 * V_221 ,
struct V_211 * V_192 )
{
struct V_199 * V_200 = F_100 ( V_192 ) ;
struct V_5 * V_6 = F_9 ( V_4 ) ;
T_5 V_209 = F_92 ( V_200 -> V_208 . V_210 , V_200 -> V_208 . V_209 ) ;
if ( F_101 ( V_209 == F_92 ( V_222 , V_161 ) ) )
F_102 ( V_6 , V_221 , V_192 ) ;
else if ( V_209 == F_92 ( V_222 , V_223 ) )
F_103 ( V_6 , V_192 ) ;
else
F_90 ( V_6 , V_192 , V_200 ) ;
}
static void F_104 ( struct V_3 * V_4 ,
struct V_220 * V_221 ,
struct V_211 * V_192 )
{
struct V_199 * V_200 = F_100 ( V_192 ) ;
struct V_5 * V_6 = F_9 ( V_4 ) ;
T_5 V_209 = F_92 ( V_200 -> V_208 . V_210 , V_200 -> V_208 . V_209 ) ;
if ( F_101 ( V_209 == F_92 ( V_222 , V_161 ) ) )
F_105 ( V_6 , V_221 , V_192 , 0 ) ;
else if ( F_106 ( V_209 == F_92 ( V_224 ,
V_225 ) ) )
F_107 ( V_6 , V_192 , 0 ) ;
else if ( V_209 == F_92 ( V_222 , V_226 ) )
F_108 ( V_6 , V_221 , V_192 , 0 ) ;
else
F_90 ( V_6 , V_192 , V_200 ) ;
}
void F_109 ( struct V_5 * V_6 , unsigned long V_227 )
{
int V_228 ;
if ( F_110 ( ! V_227 ) )
return;
F_111 (q, &mq, IEEE80211_MAX_QUEUES) {
if ( F_112 ( & V_6 -> V_229 [ V_228 ] ) > 1 ) {
F_113 ( V_6 ,
L_12 , V_228 ) ;
continue;
}
F_114 ( V_6 -> V_62 , V_228 ) ;
}
}
static void F_115 ( struct V_3 * V_4 ,
const struct V_230 * V_209 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_116 ( V_6 -> V_18 , false ) ;
}
static void F_117 ( struct V_3 * V_4 , int V_231 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
unsigned long V_227 ;
F_78 ( & V_6 -> V_107 ) ;
V_227 = V_6 -> V_232 [ V_231 ] . V_233 ;
F_82 ( & V_6 -> V_107 ) ;
F_109 ( V_6 , V_227 ) ;
}
void F_118 ( struct V_5 * V_6 , unsigned long V_227 )
{
int V_228 ;
if ( F_110 ( ! V_227 ) )
return;
F_111 (q, &mq, IEEE80211_MAX_QUEUES) {
if ( F_119 ( & V_6 -> V_229 [ V_228 ] ) > 0 ) {
F_113 ( V_6 ,
L_13 , V_228 ) ;
continue;
}
F_120 ( V_6 -> V_62 , V_228 ) ;
}
}
static void F_121 ( struct V_3 * V_4 , int V_231 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
unsigned long V_227 ;
F_78 ( & V_6 -> V_107 ) ;
V_227 = V_6 -> V_232 [ V_231 ] . V_233 ;
F_82 ( & V_6 -> V_107 ) ;
F_118 ( V_6 , V_227 ) ;
}
void F_122 ( struct V_5 * V_6 , bool V_234 )
{
if ( V_234 )
F_123 ( V_235 , & V_6 -> V_236 ) ;
else
F_124 ( V_235 , & V_6 -> V_236 ) ;
F_125 ( V_6 -> V_62 -> V_158 , F_126 ( V_6 ) ) ;
}
static bool F_127 ( struct V_3 * V_4 , bool V_234 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
bool V_237 = F_128 ( V_6 -> V_237 ) ;
if ( V_234 )
F_123 ( V_238 , & V_6 -> V_236 ) ;
else
F_124 ( V_238 , & V_6 -> V_236 ) ;
F_125 ( V_6 -> V_62 -> V_158 , F_126 ( V_6 ) ) ;
if ( V_237 )
F_129 ( & V_6 -> V_166 ) ;
return V_234 && ( V_6 -> V_98 != V_99 || V_237 ) ;
}
static void F_130 ( struct V_3 * V_4 , struct V_239 * V_240 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
struct V_152 * V_241 ;
V_241 = F_131 ( V_240 ) ;
F_132 ( V_6 -> V_18 , V_241 -> V_153 [ 1 ] ) ;
F_133 ( V_6 -> V_62 , V_240 ) ;
}
static void F_134 ( struct V_47 * V_194 )
{
struct V_242 * V_243 ;
V_243 = F_19 ( V_194 , struct V_242 , V_48 ) ;
if ( F_135 ( V_243 -> V_78 ) )
F_136 ( V_243 -> V_78 , L_14 ) ;
F_68 ( V_243 ) ;
F_137 ( V_244 ) ;
}
static void V_117 ( struct V_47 * V_48 )
{
struct V_5 * V_6 =
F_19 ( V_48 , struct V_5 , V_116 . V_48 ) ;
if ( F_138 ( V_6 , V_245 ) )
return;
F_20 ( & V_6 -> V_54 ) ;
if ( V_6 -> V_26 -> V_27 == V_246 ) {
F_139 ( V_6 -> V_18 , V_247 , 0x100 ) ;
} else {
F_140 ( V_6 -> V_18 , V_248 , 0 ) ;
F_141 ( 100 ) ;
}
F_142 ( V_6 ) ;
F_110 ( ( ! F_143 ( V_249 , & V_6 -> V_18 -> V_236 ) ) &&
V_6 -> V_58 -> V_162 &&
F_144 ( V_6 , V_6 -> V_250 ) ) ;
F_26 ( & V_6 -> V_54 ) ;
F_54 ( V_6 , V_245 ) ;
}
void F_145 ( struct V_5 * V_6 , bool V_251 )
{
F_129 ( & V_6 -> V_166 ) ;
F_146 ( V_6 ) ;
if ( ! V_6 -> V_86 && V_251 ) {
F_147 ( V_6 , & V_252 ,
NULL ) ;
} else if ( F_148 ( V_253 ,
& V_6 -> V_236 ) ) {
struct V_242 * V_243 ;
F_47 ( V_6 ,
L_15 ) ;
if ( ! F_149 ( V_244 ) ) {
F_47 ( V_6 , L_16 ) ;
return;
}
V_243 = F_93 ( sizeof( * V_243 ) , V_216 ) ;
if ( ! V_243 ) {
F_137 ( V_244 ) ;
return;
}
V_243 -> V_78 = V_6 -> V_18 -> V_78 ;
F_36 ( & V_243 -> V_48 , F_134 ) ;
F_98 ( & V_243 -> V_48 ) ;
} else if ( V_6 -> V_98 == V_254 ) {
F_51 ( V_6 , V_255 ) ;
if ( V_251 && V_6 -> V_86 > 0 )
V_6 -> V_86 -- ;
F_150 ( V_6 -> V_62 ) ;
}
}
static void F_151 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_152 ( V_6 ) ;
F_145 ( V_6 , true ) ;
}
static void F_153 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_13 ( 1 ) ;
F_145 ( V_6 , true ) ;
}
static bool F_154 ( struct V_5 * V_6 ,
struct V_50 * V_256 ,
struct V_257 * V_258 )
{
struct V_52 * V_53 = F_23 ( V_256 ) ;
struct V_259 * V_260 ;
T_4 V_261 = 0 ;
T_3 V_262 ;
if ( F_13 ( V_256 -> type != V_263 ||
V_53 -> V_264 == V_71 ) )
return false ;
V_260 = F_155 ( V_6 , V_53 -> V_264 ) ;
if ( ! V_260 )
return false ;
F_78 ( & V_260 -> V_265 ) ;
for ( V_262 = 0 ; V_262 < V_266 ; V_262 ++ ) {
struct V_267 * V_268 = & V_260 -> V_268 [ V_262 ] ;
if ( F_156 ( V_268 ) )
continue;
if ( V_268 -> V_234 != V_269 )
continue;
V_261 |= F_157 ( V_262 ) ;
}
F_82 ( & V_260 -> V_265 ) ;
if ( ! V_261 )
return true ;
V_258 -> V_270 = F_158 ( V_261 ) - 1 ;
return false ;
}
static void F_159 ( void * V_271 , T_3 * V_272 ,
struct V_50 * V_256 )
{
struct V_257 * V_188 = V_271 ;
struct V_5 * V_6 = V_188 -> V_6 ;
struct V_52 * V_53 = F_23 ( V_256 ) ;
T_4 V_273 = V_274 | V_275 | V_276 ;
F_160 ( V_6 , L_17 , V_256 -> V_277 ) ;
if ( V_256 -> type != V_263 ||
! V_256 -> V_278 . V_279 )
return;
if ( F_154 ( V_6 , V_256 , V_188 ) )
V_188 -> V_280 = true ;
F_161 ( V_6 , V_256 , true , V_273 ) ;
F_162 ( V_6 , V_256 , V_188 -> V_280 ,
false , V_273 ) ;
V_188 -> V_264 = V_53 -> V_264 ;
V_188 -> V_281 ++ ;
V_188 -> V_282 = V_256 ;
}
static void F_163 ( struct V_5 * V_6 ,
struct V_283 * V_209 ,
struct V_257 * V_258 )
{
struct V_284 * V_285 ;
struct V_259 * V_286 ;
if ( V_258 -> V_264 == V_71 )
return;
F_164 () ;
V_285 = F_165 ( V_6 -> V_70 [ V_258 -> V_264 ] ) ;
if ( F_166 ( V_285 ) )
goto V_287;
V_286 = F_167 ( V_285 ) ;
V_209 -> V_288 = V_285 -> V_289 . V_290 ;
V_209 -> V_270 = V_258 -> V_270 ;
V_209 -> V_273 = V_291 | V_292 |
V_293 | V_294 ;
F_168 ( V_286 , V_209 ) ;
V_287:
F_169 () ;
}
int F_170 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
T_4 V_273 = V_274 | V_275 | V_276 ;
int V_1 ;
struct V_257 V_295 = {
. V_6 = V_6 ,
} ;
struct V_283 V_296 = {
. V_297 = F_171 ( V_298 |
V_299 |
V_300 ) ,
} ;
struct V_301 V_302 = {
. V_303 = F_171 ( 1000 ) ,
. V_304 = F_171 ( V_305 ) ,
} ;
F_160 ( V_6 , L_18 ) ;
if ( F_110 ( V_6 -> V_98 != V_254 ) )
return - V_306 ;
F_123 ( V_307 , & V_6 -> V_236 ) ;
if ( F_172 ( V_6 ) ) {
F_160 ( V_6 -> V_18 , L_19 ) ;
F_124 ( V_307 , & V_6 -> V_236 ) ;
F_173 ( & V_6 -> V_128 ) ;
return 1 ;
}
F_174 ( V_6 -> V_62 ,
V_308 ,
F_159 ,
& V_295 ) ;
if ( V_295 . V_281 == 1 ) {
V_6 -> V_309 = V_295 . V_264 ;
V_6 -> V_310 = ! V_295 . V_280 ;
} else {
F_110 ( V_295 . V_281 > 1 ) ;
V_6 -> V_309 = V_71 ;
V_6 -> V_310 = false ;
}
F_175 () ;
V_1 = F_176 ( V_6 , F_177 ( V_6 ) , V_273 ) ;
if ( V_1 )
return V_1 ;
if ( V_6 -> V_309 != V_71 ) {
if ( ! F_178 ( & V_6 -> V_58 -> V_311 ,
V_312 ) )
V_296 . V_297 |=
F_171 ( V_313 ) ;
F_179 ( V_6 ,
V_295 . V_282 ,
true , V_273 ) ;
F_163 ( V_6 , & V_296 ,
& V_295 ) ;
V_1 = F_180 ( V_6 , V_314 , V_273 ,
sizeof( V_296 ) ,
& V_296 ) ;
if ( V_1 )
return V_1 ;
}
return F_180 ( V_6 , V_315 ,
V_273 | V_316 ,
sizeof( V_302 ) , & V_302 ) ;
}
static void F_181 ( void * V_271 , T_3 * V_272 ,
struct V_50 * V_256 )
{
struct V_5 * V_6 = V_271 ;
T_4 V_273 = V_274 | V_275 ;
F_160 ( V_6 , L_20 , V_256 -> V_277 ) ;
if ( V_256 -> type != V_263 ||
! V_256 -> V_278 . V_279 )
return;
F_161 ( V_6 , V_256 , false , V_273 ) ;
}
static void F_182 ( void * V_271 , T_3 * V_272 ,
struct V_50 * V_256 )
{
struct V_317 * V_188 = V_271 ;
struct V_52 * V_53 = F_23 ( V_256 ) ;
T_4 V_318 = V_188 -> V_319 ;
if ( V_256 -> type != V_263 || ! V_256 -> V_278 . V_279 ||
V_188 -> V_6 -> V_309 != V_53 -> V_264 )
return;
if ( V_318 & V_320 )
F_183 ( V_188 -> V_6 , V_256 , L_21 ) ;
else if ( V_318 & V_321 )
F_184 ( V_256 ) ;
else
F_185 ( V_188 -> V_6 , V_256 , V_188 -> V_236 ) ;
}
void F_186 ( struct V_5 * V_6 , T_6 * V_322 )
{
struct V_284 * V_323 = NULL ;
struct V_259 * V_286 ;
int V_180 ;
bool V_324 = false ;
F_187 ( & V_6 -> V_54 ) ;
F_78 ( & V_6 -> V_125 ) ;
if ( V_6 -> V_309 == V_71 )
goto V_287;
F_160 ( V_6 , L_22 ) ;
V_323 = F_21 (
V_6 -> V_70 [ V_6 -> V_309 ] ,
F_22 ( & V_6 -> V_54 ) ) ;
if ( F_166 ( V_323 ) ) {
V_323 = NULL ;
goto V_287;
}
if ( V_6 -> V_310 && V_322 ) {
V_286 = F_167 ( V_323 ) ;
for ( V_180 = 0 ; V_180 < V_266 ; V_180 ++ ) {
T_5 V_325 = F_188 ( V_322 [ V_180 ] ) ;
V_325 += 0x10 ;
V_286 -> V_268 [ V_180 ] . V_326 = V_325 ;
}
}
V_287:
while ( ! F_189 ( & V_6 -> V_127 ) ) {
struct V_239 * V_240 = F_190 ( & V_6 -> V_127 ) ;
if ( ! V_323 || F_191 ( V_6 , V_240 , V_323 ) )
F_133 ( V_6 -> V_62 , V_240 ) ;
V_324 = true ;
}
F_124 ( V_307 , & V_6 -> V_236 ) ;
F_173 ( & V_6 -> V_128 ) ;
V_6 -> V_309 = V_71 ;
if ( V_324 )
F_192 ( V_6 -> V_62 ) ;
F_82 ( & V_6 -> V_125 ) ;
}
static void V_115 ( struct V_47 * V_194 )
{
struct V_5 * V_6 = F_19 ( V_194 , struct V_5 , V_114 ) ;
struct V_327 V_328 = {
. V_329 = V_330 ,
. V_273 = V_275 | V_331 ,
} ;
struct V_317 V_258 = {
. V_6 = V_6 ,
} ;
struct V_332 * V_236 ;
int V_1 ;
T_4 V_319 = 0 ;
T_6 * V_322 = NULL ;
F_20 ( & V_6 -> V_54 ) ;
V_1 = F_193 ( V_6 , & V_328 ) ;
if ( V_1 )
goto V_287;
if ( ! V_328 . V_333 )
goto V_287;
V_236 = ( void * ) V_328 . V_333 -> V_188 ;
V_319 = F_194 ( V_236 -> V_319 ) ;
V_322 = V_236 -> V_334 ;
F_160 ( V_6 , L_23 , V_319 ) ;
V_258 . V_319 = V_319 ;
V_258 . V_236 = V_236 ;
F_195 ( V_6 -> V_62 ,
V_308 ,
F_182 ,
& V_258 ) ;
V_287:
F_186 ( V_6 , V_322 ) ;
F_15 ( V_6 , L_24 ,
V_319 ) ;
if ( V_328 . V_333 )
F_196 ( & V_328 ) ;
F_197 ( V_6 ) ;
F_54 ( V_6 , V_335 ) ;
F_26 ( & V_6 -> V_54 ) ;
}
int F_198 ( struct V_5 * V_6 )
{
T_4 V_273 = V_274 | V_275 | V_276 |
V_336 ;
int V_1 ;
F_160 ( V_6 , L_25 ) ;
if ( F_110 ( V_6 -> V_98 != V_254 ) )
return - V_306 ;
F_20 ( & V_6 -> V_101 ) ;
if ( F_143 ( V_337 , & V_6 -> V_338 ) ) {
F_160 ( V_6 , L_26 ) ;
F_199 ( V_339 , & V_6 -> V_338 ) ;
F_26 ( & V_6 -> V_101 ) ;
return 0 ;
}
F_26 ( & V_6 -> V_101 ) ;
V_1 = F_180 ( V_6 , V_340 , V_273 , 0 , NULL ) ;
if ( V_1 )
goto V_287;
F_174 ( V_6 -> V_62 ,
V_308 ,
F_181 ,
V_6 ) ;
V_287:
F_98 ( & V_6 -> V_114 ) ;
return V_1 ;
}
int F_200 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_51 ( V_6 , V_335 ) ;
return F_198 ( V_6 ) ;
}
static void F_201 ( struct V_3 * V_4 ,
struct V_220 * V_221 ,
struct V_211 * V_192 ,
unsigned int V_341 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
struct V_199 * V_200 = F_100 ( V_192 ) ;
T_5 V_209 = F_92 ( V_200 -> V_208 . V_210 , V_200 -> V_208 . V_209 ) ;
if ( F_106 ( V_209 == F_92 ( V_222 , V_226 ) ) )
F_108 ( V_6 , V_221 , V_192 , V_341 ) ;
else if ( F_106 ( V_209 == F_92 ( V_224 ,
V_225 ) ) )
F_107 ( V_6 , V_192 , V_341 ) ;
else if ( F_101 ( V_209 == F_92 ( V_222 , V_161 ) ) )
F_105 ( V_6 , V_221 , V_192 , V_341 ) ;
}
