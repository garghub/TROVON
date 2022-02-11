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
if ( V_6 -> V_18 -> V_26 -> V_27 < V_28 )
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
static int F_27 ( void * V_57 )
{
struct V_5 * V_6 = V_57 ;
int V_1 ;
V_1 = F_28 ( V_6 , V_58 ) ;
if ( V_1 )
return V_1 ;
F_20 ( & V_6 -> V_54 ) ;
return 0 ;
}
static void F_29 ( void * V_57 )
{
struct V_5 * V_6 = V_57 ;
F_26 ( & V_6 -> V_54 ) ;
F_30 ( V_6 , V_58 ) ;
}
static struct V_3 *
F_31 ( struct V_39 * V_18 , const struct V_40 * V_26 ,
const struct V_59 * V_60 , struct V_61 * V_62 )
{
struct V_63 * V_64 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_65 V_66 = {} ;
static const T_3 V_67 [] = {
V_68 ,
} ;
int V_69 , V_70 ;
T_4 V_71 ;
F_32 ( F_33 ( V_6 -> V_72 ) != V_73 ) ;
V_64 = F_34 ( sizeof( struct V_3 ) +
sizeof( struct V_5 ) ,
& V_74 ) ;
if ( ! V_64 )
return NULL ;
if ( V_26 -> V_75 )
V_64 -> V_76 = V_26 -> V_75 ;
if ( V_26 -> V_77 )
V_64 -> V_78 = V_26 -> V_77 ;
V_4 = V_64 -> V_79 ;
V_6 = F_9 ( V_4 ) ;
V_6 -> V_80 = V_18 -> V_80 ;
V_6 -> V_18 = V_18 ;
V_6 -> V_26 = V_26 ;
V_6 -> V_60 = V_60 ;
V_6 -> V_64 = V_64 ;
F_35 ( & V_6 -> V_81 , V_18 , V_60 , & V_82 , V_6 ) ;
V_6 -> V_83 = 0 ;
if ( F_36 ( V_6 ) ) {
V_4 -> V_84 = & V_85 ;
V_18 -> V_86 = sizeof( struct V_87 ) ;
} else {
V_4 -> V_84 = & V_2 ;
V_18 -> V_86 =
sizeof( struct V_88 ) ;
if ( F_13 ( V_18 -> V_89 > 1 ) )
goto V_90;
}
V_6 -> V_91 = V_92 . V_91 ? - 1 : 0 ;
V_6 -> V_93 = V_94 ;
V_6 -> V_95 = V_96 ;
V_6 -> V_97 = V_98 ;
V_6 -> V_99 = V_100 ;
if ( F_37 ( V_6 ) )
F_38 ( & V_6 -> V_81 , V_101 ) ;
else
F_38 ( & V_6 -> V_81 , V_102 ) ;
V_6 -> V_103 = true ;
F_39 ( & V_6 -> V_54 ) ;
F_39 ( & V_6 -> V_104 ) ;
F_40 ( & V_6 -> V_105 ) ;
F_41 ( & V_6 -> V_106 ) ;
F_41 ( & V_6 -> V_107 ) ;
F_41 ( & V_6 -> V_108 ) ;
F_40 ( & V_6 -> V_109 ) ;
F_40 ( & V_6 -> V_110 ) ;
F_42 ( & V_6 -> V_111 , V_112 ) ;
F_42 ( & V_6 -> V_113 , V_114 ) ;
F_42 ( & V_6 -> V_115 , V_116 ) ;
F_43 ( & V_6 -> V_117 . V_118 , V_119 ) ;
F_43 ( & V_6 -> V_120 , V_121 ) ;
F_42 ( & V_6 -> V_122 , V_123 ) ;
F_40 ( & V_6 -> V_124 ) ;
F_40 ( & V_6 -> V_125 ) ;
F_44 ( & V_6 -> V_126 ) ;
F_45 ( & V_6 -> V_127 ) ;
F_45 ( & V_6 -> V_128 ) ;
F_46 ( & V_6 -> V_129 , 0 ) ;
F_47 ( V_6 -> V_64 , V_6 -> V_18 -> V_80 ) ;
F_43 ( & V_6 -> V_49 , F_18 ) ;
V_66 . V_4 = V_4 ;
V_66 . V_67 = V_67 ;
V_66 . V_130 = F_33 ( V_67 ) ;
switch ( V_92 . V_131 ) {
case V_132 :
case V_133 :
V_66 . V_134 = V_133 ;
break;
case V_135 :
V_66 . V_134 = V_135 ;
break;
case V_136 :
V_66 . V_134 = V_136 ;
break;
default:
F_3 ( L_5 , V_137 ,
V_92 . V_131 ) ;
V_66 . V_134 = V_133 ;
}
if ( V_6 -> V_26 -> V_138 )
V_66 . V_134 = V_133 ;
V_18 -> V_139 = true ;
V_66 . V_140 = true ;
V_66 . V_141 = V_142 ;
V_66 . V_143 = F_33 ( V_142 ) ;
V_66 . V_144 = V_145 ;
V_66 . V_146 = V_147 ;
V_66 . V_148 = true ;
V_66 . V_149 = F_48 ( struct V_150 ,
V_151 [ 2 ] ) ;
V_66 . V_152 = V_60 -> V_152 ;
V_66 . V_153 = V_154 ;
V_66 . V_155 =
F_49 ( V_6 , NULL , false , true ) ;
snprintf ( V_6 -> V_64 -> V_156 -> V_157 ,
sizeof( V_6 -> V_64 -> V_156 -> V_157 ) ,
L_6 , V_60 -> V_157 ) ;
F_50 ( V_6 -> V_18 , & V_66 ) ;
V_18 -> V_158 = V_159 ;
V_18 -> V_160 = V_6 -> V_60 -> V_160 ;
V_18 -> V_161 = V_6 -> V_60 -> V_161 ;
memcpy ( V_18 -> V_162 , V_6 -> V_60 -> V_162 ,
sizeof( V_18 -> V_162 ) ) ;
V_18 -> V_163 = V_6 -> V_60 -> V_163 ;
F_51 ( & V_6 -> V_164 ) ;
V_6 -> V_165 = F_52 ( V_18 ) ;
if ( ! V_6 -> V_165 ) {
F_53 ( V_6 , L_7 ) ;
goto V_90;
}
F_54 ( V_6 , L_8 ,
V_6 -> V_26 -> V_166 , V_6 -> V_18 -> V_19 ) ;
if ( V_92 . V_167 )
V_6 -> V_168 = V_92 . V_167 ;
else
F_55 ( V_6 -> V_18 -> V_80 ,
L_9 ) ;
V_69 = F_56 ( V_6 -> V_18 ) ;
if ( V_69 )
goto V_90;
F_20 ( & V_6 -> V_54 ) ;
F_57 ( V_6 , V_169 ) ;
V_69 = F_58 ( V_6 , true ) ;
if ( ! V_170 . V_171 )
F_59 ( V_6 ) ;
F_30 ( V_6 , V_169 ) ;
F_26 ( & V_6 -> V_54 ) ;
if ( V_69 < 0 ) {
F_53 ( V_6 , L_10 , V_69 ) ;
goto V_90;
}
V_70 = F_60 ( V_6 ) ;
V_6 -> V_172 = F_61 ( V_70 , V_173 ) ;
if ( ! V_6 -> V_172 )
goto V_90;
V_6 -> V_174 = true ;
V_69 = F_62 ( V_6 ) ;
if ( V_69 )
goto V_90;
V_6 -> V_175 = true ;
V_71 = F_17 ( V_18 , V_26 ) ;
F_63 ( V_6 , V_71 ) ;
V_69 = F_64 ( V_6 , V_62 ) ;
if ( V_69 )
goto V_176;
if ( ! F_65 ( V_6 ) )
memset ( & V_6 -> V_177 , 0 ,
sizeof( struct V_178 ) ) ;
else
memset ( & V_6 -> V_179 , 0 , sizeof( struct V_180 ) ) ;
if ( F_66 ( V_6 ) )
F_67 ( V_6 -> V_18 ) ;
F_68 ( V_6 ) ;
return V_4 ;
V_176:
if ( V_170 . V_171 )
return V_4 ;
F_69 ( V_6 -> V_64 ) ;
V_6 -> V_175 = false ;
F_70 ( V_6 ) ;
F_71 ( V_6 ) ;
V_90:
F_72 ( & V_6 -> V_81 ) ;
if ( V_170 . V_171 )
return V_4 ;
F_73 ( V_6 -> V_165 ) ;
F_74 ( V_6 -> V_172 ) ;
F_75 ( V_18 ) ;
F_76 ( V_6 -> V_64 ) ;
return NULL ;
}
static void F_77 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
int V_181 ;
if ( F_66 ( V_6 ) )
F_78 ( V_6 -> V_18 ) ;
F_70 ( V_6 ) ;
F_71 ( V_6 ) ;
if ( V_6 -> V_83 & V_182 ) {
F_69 ( V_6 -> V_64 ) ;
V_6 -> V_83 &= ~ V_182 ;
}
F_74 ( V_6 -> V_172 ) ;
F_74 ( V_6 -> V_183 ) ;
V_6 -> V_183 = NULL ;
#if F_79 ( V_184 ) && F_79 ( V_185 )
F_74 ( V_6 -> V_186 ) ;
#endif
F_75 ( V_6 -> V_18 ) ;
F_73 ( V_6 -> V_165 ) ;
V_6 -> V_165 = NULL ;
F_74 ( V_6 -> V_187 ) ;
for ( V_181 = 0 ; V_181 < V_188 ; V_181 ++ )
F_74 ( V_6 -> V_189 [ V_181 ] . V_190 ) ;
F_80 ( V_6 ) ;
F_81 ( & V_6 -> V_54 ) ;
F_81 ( & V_6 -> V_104 ) ;
F_76 ( V_6 -> V_64 ) ;
}
void F_82 ( struct V_5 * V_6 )
{
struct V_191 * V_192 , * V_193 ;
F_83 ( & V_6 -> V_105 ) ;
F_84 (entry, tmp, &mvm->async_handlers_list, list) {
F_85 ( & V_192 -> V_194 ) ;
F_86 ( & V_192 -> V_195 ) ;
F_74 ( V_192 ) ;
}
F_87 ( & V_6 -> V_105 ) ;
}
static void V_112 ( struct V_47 * V_196 )
{
struct V_5 * V_6 =
F_19 ( V_196 , struct V_5 , V_111 ) ;
struct V_191 * V_192 , * V_193 ;
F_88 ( V_197 ) ;
F_83 ( & V_6 -> V_105 ) ;
F_89 ( & V_6 -> V_108 , & V_197 ) ;
F_87 ( & V_6 -> V_105 ) ;
F_84 (entry, tmp, &local_list, list) {
if ( V_192 -> V_198 == V_199 )
F_20 ( & V_6 -> V_54 ) ;
V_192 -> V_200 ( V_6 , & V_192 -> V_194 ) ;
F_85 ( & V_192 -> V_194 ) ;
F_86 ( & V_192 -> V_195 ) ;
if ( V_192 -> V_198 == V_199 )
F_26 ( & V_6 -> V_54 ) ;
F_74 ( V_192 ) ;
}
}
static inline void F_90 ( struct V_5 * V_6 ,
struct V_201 * V_202 )
{
struct V_203 * V_204 ;
struct V_205 * V_206 ;
int V_181 ;
if ( ! F_91 ( V_6 -> V_60 , V_207 ) )
return;
V_204 = F_92 ( V_6 -> V_60 , V_207 ) ;
V_206 = ( void * ) V_204 -> V_190 ;
if ( ! F_93 ( & V_6 -> V_81 , NULL , V_204 ) )
return;
for ( V_181 = 0 ; V_181 < F_33 ( V_206 -> V_208 ) ; V_181 ++ ) {
if ( ! V_206 -> V_208 [ V_181 ] . V_209 )
break;
if ( V_206 -> V_208 [ V_181 ] . V_209 != V_202 -> V_210 . V_211 ||
V_206 -> V_208 [ V_181 ] . V_212 != V_202 -> V_210 . V_212 )
continue;
F_94 ( & V_6 -> V_81 , V_204 ,
L_11 ,
V_202 -> V_210 . V_212 , V_202 -> V_210 . V_211 ) ;
break;
}
}
static void F_95 ( struct V_5 * V_6 ,
struct V_213 * V_194 ,
struct V_201 * V_202 )
{
int V_181 ;
F_90 ( V_6 , V_202 ) ;
F_96 ( & V_6 -> V_164 , V_202 ) ;
for ( V_181 = 0 ; V_181 < F_33 ( V_214 ) ; V_181 ++ ) {
const struct V_215 * V_216 = & V_214 [ V_181 ] ;
struct V_191 * V_192 ;
if ( V_216 -> V_209 != F_97 ( V_202 -> V_210 . V_212 , V_202 -> V_210 . V_211 ) )
continue;
if ( V_216 -> V_198 == V_217 ) {
V_216 -> V_200 ( V_6 , V_194 ) ;
return;
}
V_192 = F_98 ( sizeof( * V_192 ) , V_218 ) ;
if ( ! V_192 )
return;
V_192 -> V_194 . V_219 = F_99 ( V_194 ) ;
V_192 -> V_194 . V_220 = V_194 -> V_220 ;
V_192 -> V_194 . V_221 = V_194 -> V_221 ;
V_192 -> V_200 = V_216 -> V_200 ;
V_192 -> V_198 = V_216 -> V_198 ;
F_100 ( & V_6 -> V_105 ) ;
F_101 ( & V_192 -> V_195 , & V_6 -> V_108 ) ;
F_102 ( & V_6 -> V_105 ) ;
F_103 ( & V_6 -> V_111 ) ;
return;
}
F_104 ( & V_6 -> V_81 , V_194 ) ;
}
static void F_105 ( struct V_3 * V_4 ,
struct V_222 * V_223 ,
struct V_213 * V_194 )
{
struct V_201 * V_202 = F_106 ( V_194 ) ;
struct V_5 * V_6 = F_9 ( V_4 ) ;
T_5 V_211 = F_97 ( V_202 -> V_210 . V_212 , V_202 -> V_210 . V_211 ) ;
if ( F_107 ( V_211 == F_97 ( V_224 , V_159 ) ) )
F_108 ( V_6 , V_223 , V_194 ) ;
else if ( V_211 == F_97 ( V_224 , V_225 ) )
F_109 ( V_6 , V_194 ) ;
else
F_95 ( V_6 , V_194 , V_202 ) ;
}
static void F_110 ( struct V_3 * V_4 ,
struct V_222 * V_223 ,
struct V_213 * V_194 )
{
struct V_201 * V_202 = F_106 ( V_194 ) ;
struct V_5 * V_6 = F_9 ( V_4 ) ;
T_5 V_211 = F_97 ( V_202 -> V_210 . V_212 , V_202 -> V_210 . V_211 ) ;
if ( F_107 ( V_211 == F_97 ( V_224 , V_159 ) ) )
F_111 ( V_6 , V_223 , V_194 , 0 ) ;
else if ( F_112 ( V_211 == F_97 ( V_226 ,
V_227 ) ) )
F_113 ( V_6 , V_194 , 0 ) ;
else if ( V_211 == F_97 ( V_224 , V_228 ) )
F_114 ( V_6 , V_223 , V_194 , 0 ) ;
else
F_95 ( V_6 , V_194 , V_202 ) ;
}
void F_115 ( struct V_5 * V_6 , unsigned long V_229 )
{
int V_230 ;
if ( F_116 ( ! V_229 ) )
return;
F_117 (q, &mq, IEEE80211_MAX_QUEUES) {
if ( F_118 ( & V_6 -> V_231 [ V_230 ] ) > 1 ) {
F_119 ( V_6 ,
L_12 , V_230 ) ;
continue;
}
F_120 ( V_6 -> V_64 , V_230 ) ;
}
}
static void F_121 ( struct V_3 * V_4 ,
const struct V_232 * V_211 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_122 ( V_6 -> V_18 , false ) ;
}
static void F_123 ( struct V_3 * V_4 , int V_233 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
unsigned long V_229 ;
F_83 ( & V_6 -> V_110 ) ;
V_229 = V_6 -> V_234 [ V_233 ] ;
F_87 ( & V_6 -> V_110 ) ;
F_115 ( V_6 , V_229 ) ;
}
void F_124 ( struct V_5 * V_6 , unsigned long V_229 )
{
int V_230 ;
if ( F_116 ( ! V_229 ) )
return;
F_117 (q, &mq, IEEE80211_MAX_QUEUES) {
if ( F_125 ( & V_6 -> V_231 [ V_230 ] ) > 0 ) {
F_119 ( V_6 ,
L_13 , V_230 ) ;
continue;
}
F_126 ( V_6 -> V_64 , V_230 ) ;
}
}
static void F_127 ( struct V_3 * V_4 , int V_233 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
unsigned long V_229 ;
F_83 ( & V_6 -> V_110 ) ;
V_229 = V_6 -> V_234 [ V_233 ] ;
F_87 ( & V_6 -> V_110 ) ;
F_124 ( V_6 , V_229 ) ;
}
static void F_128 ( struct V_5 * V_6 )
{
bool V_235 = F_129 ( V_6 ) ;
if ( V_235 )
F_130 ( & V_6 -> V_128 ) ;
F_131 ( V_6 -> V_64 -> V_156 , V_235 ) ;
}
void F_132 ( struct V_5 * V_6 , bool V_235 )
{
if ( V_235 )
F_133 ( V_236 , & V_6 -> V_237 ) ;
else
F_134 ( V_236 , & V_6 -> V_237 ) ;
F_128 ( V_6 ) ;
}
static bool F_135 ( struct V_3 * V_4 , bool V_235 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
bool V_238 = F_136 ( V_6 -> V_238 ) ;
if ( V_235 )
F_133 ( V_239 , & V_6 -> V_237 ) ;
else
F_134 ( V_239 , & V_6 -> V_237 ) ;
F_128 ( V_6 ) ;
if ( V_238 )
F_137 ( & V_6 -> V_164 ) ;
return V_235 && ( V_6 -> V_81 . V_240 != V_102 || V_238 ) ;
}
static void F_138 ( struct V_3 * V_4 , struct V_241 * V_242 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
struct V_150 * V_243 ;
V_243 = F_139 ( V_242 ) ;
F_140 ( V_6 -> V_18 , V_243 -> V_151 [ 1 ] ) ;
F_141 ( V_6 -> V_64 , V_242 ) ;
}
static void F_142 ( struct V_47 * V_196 )
{
struct V_244 * V_245 ;
V_245 = F_19 ( V_196 , struct V_244 , V_48 ) ;
if ( F_143 ( V_245 -> V_80 ) )
F_144 ( V_245 -> V_80 , L_14 ) ;
F_74 ( V_245 ) ;
F_145 ( V_246 ) ;
}
void F_146 ( struct V_5 * V_6 , bool V_247 )
{
F_137 ( & V_6 -> V_164 ) ;
F_147 ( V_6 ) ;
if ( ! V_6 -> V_91 && V_247 ) {
F_148 ( & V_6 -> V_81 , & V_248 ,
NULL ) ;
} else if ( F_149 ( V_249 , & V_6 -> V_237 ) ) {
struct V_244 * V_245 ;
F_53 ( V_6 ,
L_15 ) ;
if ( ! F_150 ( V_246 ) ) {
F_53 ( V_6 , L_16 ) ;
return;
}
V_245 = F_98 ( sizeof( * V_245 ) , V_218 ) ;
if ( ! V_245 ) {
F_145 ( V_246 ) ;
return;
}
V_245 -> V_80 = V_6 -> V_18 -> V_80 ;
F_42 ( & V_245 -> V_48 , F_142 ) ;
F_103 ( & V_245 -> V_48 ) ;
} else if ( V_6 -> V_81 . V_240 == V_101 &&
V_6 -> V_175 ) {
F_57 ( V_6 , V_250 ) ;
if ( V_247 && V_6 -> V_91 > 0 )
V_6 -> V_91 -- ;
F_133 ( V_251 , & V_6 -> V_237 ) ;
F_151 ( V_6 -> V_64 ) ;
}
}
static void F_152 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_153 ( V_6 ) ;
F_146 ( V_6 , true ) ;
}
static void F_154 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_13 ( 1 ) ;
F_146 ( V_6 , true ) ;
}
static bool F_155 ( struct V_5 * V_6 ,
struct V_50 * V_252 ,
struct V_253 * V_254 )
{
struct V_52 * V_53 = F_23 ( V_252 ) ;
struct V_255 * V_256 ;
T_4 V_257 = 0 ;
T_3 V_258 ;
if ( F_13 ( V_252 -> type != V_259 ||
V_53 -> V_260 == V_261 ) )
return false ;
V_256 = F_156 ( V_6 , V_53 -> V_260 ) ;
if ( ! V_256 )
return false ;
F_83 ( & V_256 -> V_262 ) ;
for ( V_258 = 0 ; V_258 < V_263 ; V_258 ++ ) {
struct V_264 * V_265 = & V_256 -> V_265 [ V_258 ] ;
if ( F_157 ( V_6 , V_265 ) )
continue;
if ( V_265 -> V_235 != V_266 )
continue;
V_257 |= F_158 ( V_258 ) ;
}
F_87 ( & V_256 -> V_262 ) ;
if ( ! V_257 )
return true ;
V_254 -> V_267 = F_159 ( V_257 ) - 1 ;
return false ;
}
static void F_160 ( void * V_268 , T_3 * V_269 ,
struct V_50 * V_252 )
{
struct V_253 * V_190 = V_268 ;
struct V_5 * V_6 = V_190 -> V_6 ;
struct V_52 * V_53 = F_23 ( V_252 ) ;
T_4 V_270 = V_271 | V_272 | V_273 ;
F_161 ( V_6 , L_17 , V_252 -> V_274 ) ;
if ( V_252 -> type != V_259 ||
! V_252 -> V_275 . V_276 )
return;
if ( F_155 ( V_6 , V_252 , V_190 ) )
V_190 -> V_277 = true ;
F_162 ( V_6 , V_252 , true , V_270 ) ;
F_163 ( V_6 , V_252 , V_190 -> V_277 ,
false , V_270 ) ;
V_190 -> V_260 = V_53 -> V_260 ;
V_190 -> V_278 ++ ;
V_190 -> V_279 = V_252 ;
}
static void F_164 ( struct V_5 * V_6 ,
struct V_280 * V_211 ,
struct V_253 * V_254 )
{
struct V_281 * V_282 ;
struct V_255 * V_283 ;
if ( V_254 -> V_260 == V_261 )
return;
F_165 () ;
V_282 = F_166 ( V_6 -> V_72 [ V_254 -> V_260 ] ) ;
if ( F_167 ( V_282 ) )
goto V_284;
V_283 = F_168 ( V_282 ) ;
V_211 -> V_285 = V_282 -> V_286 . V_287 ;
V_211 -> V_267 = V_254 -> V_267 ;
V_211 -> V_270 = V_288 | V_289 |
V_290 | V_291 ;
F_169 ( V_283 , V_211 ) ;
V_284:
F_170 () ;
}
int F_171 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
T_4 V_270 = V_271 | V_272 | V_273 ;
int V_1 ;
struct V_253 V_292 = {
. V_6 = V_6 ,
} ;
struct V_280 V_293 = {
. V_294 = F_172 ( V_295 |
V_296 |
V_297 ) ,
} ;
struct V_298 V_299 = {
. V_300 = F_172 ( 1000 ) ,
. V_301 = F_172 ( V_302 ) ,
} ;
F_161 ( V_6 , L_18 ) ;
if ( F_116 ( V_6 -> V_81 . V_240 != V_101 ) )
return - V_303 ;
F_133 ( V_304 , & V_6 -> V_237 ) ;
if ( F_173 ( V_6 ) ) {
F_161 ( V_6 -> V_18 , L_19 ) ;
F_134 ( V_304 , & V_6 -> V_237 ) ;
F_130 ( & V_6 -> V_127 ) ;
return 1 ;
}
F_174 ( V_6 -> V_64 ,
V_305 ,
F_160 ,
& V_292 ) ;
if ( V_292 . V_278 == 1 ) {
V_6 -> V_306 = V_292 . V_260 ;
V_6 -> V_307 = ! V_292 . V_277 ;
} else {
F_116 ( V_292 . V_278 > 1 ) ;
V_6 -> V_306 = V_261 ;
V_6 -> V_307 = false ;
}
F_175 () ;
if ( F_176 ( V_6 ) ) {
F_177 ( 1 , L_20 ) ;
} else {
V_1 = F_178 ( V_6 , F_179 ( V_6 ) ,
V_270 ) ;
if ( V_1 )
return V_1 ;
}
if ( V_6 -> V_306 != V_261 ) {
if ( ! F_180 ( & V_6 -> V_60 -> V_308 ,
V_309 ) )
V_293 . V_294 |=
F_172 ( V_310 ) ;
F_181 ( V_6 ,
V_292 . V_279 ,
true , V_270 ) ;
F_164 ( V_6 , & V_293 ,
& V_292 ) ;
V_1 = F_182 ( V_6 , V_311 , V_270 ,
sizeof( V_293 ) ,
& V_293 ) ;
if ( V_1 )
return V_1 ;
}
return F_182 ( V_6 , V_312 ,
V_270 | V_313 ,
sizeof( V_299 ) , & V_299 ) ;
}
static void F_183 ( void * V_268 , T_3 * V_269 ,
struct V_50 * V_252 )
{
struct V_5 * V_6 = V_268 ;
T_4 V_270 = V_271 | V_272 ;
F_161 ( V_6 , L_21 , V_252 -> V_274 ) ;
if ( V_252 -> type != V_259 ||
! V_252 -> V_275 . V_276 )
return;
F_162 ( V_6 , V_252 , false , V_270 ) ;
}
static void F_184 ( void * V_268 , T_3 * V_269 ,
struct V_50 * V_252 )
{
struct V_314 * V_190 = V_268 ;
struct V_52 * V_53 = F_23 ( V_252 ) ;
T_4 V_315 = V_190 -> V_316 ;
if ( V_252 -> type != V_259 || ! V_252 -> V_275 . V_276 ||
V_190 -> V_6 -> V_306 != V_53 -> V_260 )
return;
if ( V_315 & V_317 )
F_185 ( V_190 -> V_6 , V_252 , L_22 ) ;
else if ( V_315 & V_318 )
F_186 ( V_252 ) ;
else
F_187 ( V_190 -> V_6 , V_252 , V_190 -> V_237 ) ;
}
void F_188 ( struct V_5 * V_6 , T_6 * V_319 )
{
struct V_281 * V_320 = NULL ;
struct V_255 * V_283 ;
int V_181 ;
bool V_321 = false ;
F_189 ( & V_6 -> V_54 ) ;
F_83 ( & V_6 -> V_124 ) ;
if ( V_6 -> V_306 == V_261 )
goto V_284;
F_161 ( V_6 , L_23 ) ;
V_320 = F_21 (
V_6 -> V_72 [ V_6 -> V_306 ] ,
F_22 ( & V_6 -> V_54 ) ) ;
if ( F_167 ( V_320 ) ) {
V_320 = NULL ;
goto V_284;
}
if ( V_6 -> V_307 && V_319 ) {
V_283 = F_168 ( V_320 ) ;
for ( V_181 = 0 ; V_181 < V_263 ; V_181 ++ ) {
T_5 V_322 = F_190 ( V_319 [ V_181 ] ) ;
V_322 += 0x10 ;
V_283 -> V_265 [ V_181 ] . V_323 = V_322 ;
}
}
V_284:
while ( ! F_191 ( & V_6 -> V_126 ) ) {
struct V_241 * V_242 = F_192 ( & V_6 -> V_126 ) ;
if ( ! V_320 || F_193 ( V_6 , V_242 , V_320 ) )
F_141 ( V_6 -> V_64 , V_242 ) ;
V_321 = true ;
}
F_134 ( V_304 , & V_6 -> V_237 ) ;
F_130 ( & V_6 -> V_127 ) ;
V_6 -> V_306 = V_261 ;
if ( V_321 )
F_194 ( V_6 -> V_64 ) ;
F_87 ( & V_6 -> V_124 ) ;
}
static void V_116 ( struct V_47 * V_196 )
{
struct V_5 * V_6 = F_19 ( V_196 , struct V_5 , V_115 ) ;
struct V_324 V_325 = {
. V_326 = V_327 ,
. V_270 = V_272 | V_328 ,
} ;
struct V_314 V_254 = {
. V_6 = V_6 ,
} ;
struct V_329 * V_237 ;
int V_1 ;
T_4 V_316 = 0 ;
T_6 * V_319 = NULL ;
F_20 ( & V_6 -> V_54 ) ;
V_1 = F_195 ( V_6 , & V_325 ) ;
if ( V_1 )
goto V_284;
V_237 = ( void * ) V_325 . V_330 -> V_190 ;
V_316 = F_196 ( V_237 -> V_316 ) ;
V_319 = V_237 -> V_331 ;
F_161 ( V_6 , L_24 , V_316 ) ;
V_254 . V_316 = V_316 ;
V_254 . V_237 = V_237 ;
F_197 ( V_6 -> V_64 ,
V_305 ,
F_184 ,
& V_254 ) ;
V_284:
F_188 ( V_6 , V_319 ) ;
F_15 ( V_6 , L_25 ,
V_316 ) ;
if ( V_325 . V_330 )
F_198 ( & V_325 ) ;
F_199 ( V_6 ) ;
F_30 ( V_6 , V_332 ) ;
F_26 ( & V_6 -> V_54 ) ;
}
int F_200 ( struct V_5 * V_6 )
{
T_4 V_270 = V_271 | V_272 | V_273 |
V_333 ;
int V_1 ;
F_161 ( V_6 , L_26 ) ;
if ( F_116 ( V_6 -> V_81 . V_240 != V_101 ) )
return - V_303 ;
F_20 ( & V_6 -> V_104 ) ;
if ( F_149 ( V_334 , & V_6 -> V_335 ) ) {
F_161 ( V_6 , L_27 ) ;
F_201 ( V_336 , & V_6 -> V_335 ) ;
F_26 ( & V_6 -> V_104 ) ;
return 0 ;
}
F_26 ( & V_6 -> V_104 ) ;
V_1 = F_182 ( V_6 , V_337 , V_270 , 0 , NULL ) ;
if ( V_1 )
goto V_284;
F_174 ( V_6 -> V_64 ,
V_305 ,
F_183 ,
V_6 ) ;
V_284:
F_103 ( & V_6 -> V_115 ) ;
return V_1 ;
}
int F_202 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_57 ( V_6 , V_332 ) ;
return F_200 ( V_6 ) ;
}
static void F_203 ( struct V_3 * V_4 ,
struct V_222 * V_223 ,
struct V_213 * V_194 ,
unsigned int V_338 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
struct V_201 * V_202 = F_106 ( V_194 ) ;
T_5 V_211 = F_97 ( V_202 -> V_210 . V_212 , V_202 -> V_210 . V_211 ) ;
if ( F_112 ( V_211 == F_97 ( V_224 , V_228 ) ) )
F_114 ( V_6 , V_223 , V_194 , V_338 ) ;
else if ( F_112 ( V_211 == F_97 ( V_226 ,
V_227 ) ) )
F_113 ( V_6 , V_194 , V_338 ) ;
else if ( F_107 ( V_211 == F_97 ( V_224 , V_159 ) ) )
F_111 ( V_6 , V_223 , V_194 , V_338 ) ;
}
