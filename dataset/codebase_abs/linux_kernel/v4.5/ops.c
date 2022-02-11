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
} else {
V_4 -> V_69 = & V_2 ;
if ( F_13 ( V_18 -> V_71 > 1 ) )
goto V_72;
}
V_6 -> V_73 = V_74 . V_73 ? - 1 : 0 ;
V_6 -> V_75 = 15 ;
V_6 -> V_76 = 16 ;
V_6 -> V_77 = V_6 -> V_26 -> V_78 -> V_79 - 1 ;
if ( V_6 -> V_26 -> V_78 -> V_79 == 16 ) {
V_6 -> V_75 = 11 ;
V_6 -> V_76 = 12 ;
}
V_6 -> V_80 = V_81 ;
V_6 -> V_82 = V_83 ;
F_23 ( & V_6 -> V_84 ) ;
F_23 ( & V_6 -> V_85 ) ;
F_24 ( & V_6 -> V_86 ) ;
F_25 ( & V_6 -> V_87 ) ;
F_25 ( & V_6 -> V_88 ) ;
F_25 ( & V_6 -> V_89 ) ;
F_24 ( & V_6 -> V_90 ) ;
F_24 ( & V_6 -> V_91 ) ;
F_26 ( & V_6 -> V_92 , V_93 ) ;
F_26 ( & V_6 -> V_94 , V_95 ) ;
F_26 ( & V_6 -> V_96 , V_97 ) ;
F_26 ( & V_6 -> V_98 , V_99 ) ;
F_27 ( & V_6 -> V_100 , V_101 ) ;
F_27 ( & V_6 -> V_102 . V_103 , V_104 ) ;
F_24 ( & V_6 -> V_105 ) ;
F_24 ( & V_6 -> V_106 ) ;
F_28 ( & V_6 -> V_107 ) ;
F_29 ( & V_6 -> V_108 ) ;
F_30 ( V_6 -> V_52 , V_6 -> V_18 -> V_68 ) ;
V_54 . V_4 = V_4 ;
V_54 . V_55 = V_55 ;
V_54 . V_109 = F_20 ( V_55 ) ;
switch ( V_74 . V_110 ) {
case V_111 :
V_54 . V_112 = V_111 ;
break;
case V_113 :
V_54 . V_112 = V_113 ;
break;
case V_114 :
V_54 . V_112 = V_114 ;
break;
default:
F_3 ( L_5 , V_115 ,
V_74 . V_110 ) ;
V_54 . V_112 = V_111 ;
}
V_54 . V_116 = F_31 ( & V_6 -> V_48 -> V_117 ,
V_118 ) ;
if ( V_6 -> V_48 -> V_117 . V_119 & V_120 )
V_54 . V_121 = true ;
V_54 . V_122 = V_123 ;
V_54 . V_124 = F_20 ( V_123 ) ;
V_54 . V_125 = V_126 ;
V_54 . V_127 = V_128 ;
V_54 . V_129 = true ;
V_54 . V_130 = V_48 -> V_130 ;
V_54 . V_131 = V_132 ;
V_54 . V_133 =
F_32 ( V_6 , NULL , false , true ) ;
snprintf ( V_6 -> V_52 -> V_134 -> V_135 ,
sizeof( V_6 -> V_52 -> V_134 -> V_135 ) ,
L_6 , V_48 -> V_135 ) ;
F_33 ( V_6 -> V_18 , & V_54 ) ;
V_18 -> V_136 = V_137 ;
V_18 -> V_138 = sizeof( struct V_139 ) ;
V_18 -> V_140 = V_6 -> V_48 -> V_140 ;
V_18 -> V_141 = V_6 -> V_48 -> V_141 ;
memcpy ( V_18 -> V_142 , V_6 -> V_48 -> V_142 ,
sizeof( V_18 -> V_142 ) ) ;
V_18 -> V_143 = V_6 -> V_48 -> V_143 ;
F_34 ( & V_6 -> V_144 ) ;
V_6 -> V_145 = F_35 ( V_18 ) ;
if ( ! V_6 -> V_145 ) {
F_36 ( V_6 , L_7 ) ;
goto V_72;
}
F_37 ( V_6 , L_8 ,
V_6 -> V_26 -> V_146 , V_6 -> V_18 -> V_19 ) ;
V_59 = F_17 ( V_18 , V_26 ) ;
F_38 ( V_6 , V_59 ) ;
if ( V_74 . V_147 )
V_6 -> V_148 = V_74 . V_147 ;
else
F_39 ( V_6 -> V_18 -> V_68 ,
L_9 ) ;
if ( F_40 ( V_26 -> V_149 && ! V_6 -> V_148 ,
L_10 ) )
goto V_72;
if ( V_26 -> V_149 && V_6 -> V_148 ) {
V_57 = F_41 ( V_6 , false ) ;
if ( V_57 )
goto V_72;
} else {
V_57 = F_42 ( V_6 -> V_18 ) ;
if ( V_57 )
goto V_72;
F_43 ( & V_6 -> V_84 ) ;
F_44 ( V_6 , V_150 ) ;
V_57 = F_45 ( V_6 , true ) ;
if ( ! V_57 || ! V_151 . V_152 )
F_46 ( V_18 ) ;
F_47 ( V_6 , V_150 ) ;
F_48 ( & V_6 -> V_84 ) ;
if ( V_57 < 0 && ! V_151 . V_152 ) {
F_36 ( V_6 , L_11 , V_57 ) ;
goto V_72;
}
}
V_58 = F_49 ( V_6 ) ;
V_6 -> V_153 = F_50 ( V_58 , V_154 ) ;
if ( ! V_6 -> V_153 )
goto V_72;
V_6 -> V_155 = true ;
V_57 = F_51 ( V_6 ) ;
if ( V_57 )
goto V_72;
V_57 = F_52 ( V_6 , V_50 ) ;
if ( V_57 )
goto V_156;
memset ( & V_6 -> V_157 , 0 , sizeof( struct V_158 ) ) ;
F_53 ( V_6 -> V_18 ) ;
F_54 ( V_6 ) ;
return V_4 ;
V_156:
F_55 ( V_6 -> V_52 ) ;
F_56 ( V_6 ) ;
V_72:
F_57 ( & V_6 -> V_100 ) ;
F_58 ( V_6 -> V_145 ) ;
F_59 ( V_6 -> V_153 ) ;
if ( ! V_26 -> V_149 || ! V_6 -> V_148 )
F_60 ( V_18 ) ;
F_61 ( V_6 -> V_52 ) ;
return NULL ;
}
static void F_62 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
int V_159 ;
F_56 ( V_6 ) ;
F_63 ( V_6 ) ;
F_55 ( V_6 -> V_52 ) ;
F_59 ( V_6 -> V_153 ) ;
F_59 ( V_6 -> V_160 ) ;
V_6 -> V_160 = NULL ;
#if F_64 ( V_161 ) && F_64 ( V_162 )
F_59 ( V_6 -> V_163 ) ;
#endif
F_60 ( V_6 -> V_18 ) ;
F_58 ( V_6 -> V_145 ) ;
V_6 -> V_145 = NULL ;
F_65 ( V_6 -> V_164 ) ;
for ( V_159 = 0 ; V_159 < V_165 ; V_159 ++ )
F_59 ( V_6 -> V_166 [ V_159 ] . V_167 ) ;
F_66 ( V_6 ) ;
F_67 ( V_6 ) ;
F_61 ( V_6 -> V_52 ) ;
}
void F_68 ( struct V_5 * V_6 )
{
struct V_168 * V_169 , * V_170 ;
F_69 ( & V_6 -> V_86 ) ;
F_70 (entry, tmp, &mvm->async_handlers_list, list) {
F_71 ( & V_169 -> V_171 ) ;
F_72 ( & V_169 -> V_172 ) ;
F_59 ( V_169 ) ;
}
F_73 ( & V_6 -> V_86 ) ;
}
static void V_93 ( struct V_173 * V_174 )
{
struct V_5 * V_6 =
F_74 ( V_174 , struct V_5 , V_92 ) ;
struct V_168 * V_169 , * V_170 ;
struct V_175 V_176 ;
F_25 ( & V_176 ) ;
F_43 ( & V_6 -> V_84 ) ;
F_69 ( & V_6 -> V_86 ) ;
F_75 ( & V_6 -> V_89 , & V_176 ) ;
F_73 ( & V_6 -> V_86 ) ;
F_70 (entry, tmp, &local_list, list) {
V_169 -> V_177 ( V_6 , & V_169 -> V_171 ) ;
F_71 ( & V_169 -> V_171 ) ;
F_72 ( & V_169 -> V_172 ) ;
F_59 ( V_169 ) ;
}
F_48 ( & V_6 -> V_84 ) ;
}
static inline void F_76 ( struct V_5 * V_6 ,
struct V_178 * V_179 )
{
struct V_180 * V_181 ;
struct V_182 * V_183 ;
int V_159 ;
if ( ! F_77 ( V_6 -> V_48 , V_184 ) )
return;
V_181 = F_78 ( V_6 -> V_48 , V_184 ) ;
V_183 = ( void * ) V_181 -> V_167 ;
if ( ! F_79 ( V_6 , NULL , V_181 ) )
return;
for ( V_159 = 0 ; V_159 < F_20 ( V_183 -> V_185 ) ; V_159 ++ ) {
if ( ! V_183 -> V_185 [ V_159 ] . V_186 )
break;
if ( V_183 -> V_185 [ V_159 ] . V_186 != V_179 -> V_187 . V_188 ||
V_183 -> V_185 [ V_159 ] . V_189 != V_179 -> V_187 . V_189 )
continue;
F_80 ( V_6 , V_181 ,
L_12 ,
V_179 -> V_187 . V_189 , V_179 -> V_187 . V_188 ) ;
break;
}
}
static void F_81 ( struct V_5 * V_6 ,
struct V_190 * V_171 ,
struct V_178 * V_179 )
{
int V_159 ;
F_76 ( V_6 , V_179 ) ;
F_82 ( & V_6 -> V_144 , V_179 ) ;
for ( V_159 = 0 ; V_159 < F_20 ( V_191 ) ; V_159 ++ ) {
const struct V_192 * V_193 = & V_191 [ V_159 ] ;
struct V_168 * V_169 ;
if ( V_193 -> V_186 != F_83 ( V_179 -> V_187 . V_189 , V_179 -> V_187 . V_188 ) )
continue;
if ( ! V_193 -> V_194 ) {
V_193 -> V_177 ( V_6 , V_171 ) ;
return;
}
V_169 = F_84 ( sizeof( * V_169 ) , V_195 ) ;
if ( ! V_169 )
return;
V_169 -> V_171 . V_196 = F_85 ( V_171 ) ;
V_169 -> V_171 . V_197 = V_171 -> V_197 ;
V_169 -> V_171 . V_198 = V_171 -> V_198 ;
V_169 -> V_177 = V_193 -> V_177 ;
F_86 ( & V_6 -> V_86 ) ;
F_87 ( & V_169 -> V_172 , & V_6 -> V_89 ) ;
F_88 ( & V_6 -> V_86 ) ;
F_89 ( & V_6 -> V_92 ) ;
break;
}
}
static void F_90 ( struct V_3 * V_4 ,
struct V_199 * V_200 ,
struct V_190 * V_171 )
{
struct V_178 * V_179 = F_91 ( V_171 ) ;
struct V_5 * V_6 = F_9 ( V_4 ) ;
if ( F_92 ( V_179 -> V_187 . V_188 == V_137 ) )
F_93 ( V_6 , V_200 , V_171 ) ;
else if ( V_179 -> V_187 . V_188 == V_201 )
F_94 ( V_6 , V_171 , 0 ) ;
else if ( V_179 -> V_187 . V_188 == V_202 )
F_95 ( V_6 , V_171 ) ;
else
F_81 ( V_6 , V_171 , V_179 ) ;
}
static void F_96 ( struct V_3 * V_4 ,
struct V_199 * V_200 ,
struct V_190 * V_171 )
{
struct V_178 * V_179 = F_91 ( V_171 ) ;
struct V_5 * V_6 = F_9 ( V_4 ) ;
if ( F_92 ( V_179 -> V_187 . V_188 == V_137 ) )
F_97 ( V_6 , V_200 , V_171 , 0 ) ;
else if ( V_179 -> V_187 . V_188 == V_202 )
F_98 ( V_6 , V_171 ) ;
else
F_81 ( V_6 , V_171 , V_179 ) ;
}
static void F_99 ( struct V_3 * V_4 , int V_203 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
unsigned long V_204 ;
int V_205 ;
F_69 ( & V_6 -> V_91 ) ;
V_204 = V_6 -> V_206 [ V_203 ] . V_207 ;
F_73 ( & V_6 -> V_91 ) ;
if ( F_100 ( ! V_204 ) )
return;
F_101 (q, &mq, IEEE80211_MAX_QUEUES) {
if ( F_102 ( & V_6 -> V_208 [ V_205 ] ) > 1 ) {
F_103 ( V_6 ,
L_13 ,
V_203 , V_205 ) ;
continue;
}
F_104 ( V_6 -> V_52 , V_205 ) ;
}
}
static void F_105 ( struct V_3 * V_4 ,
const struct V_209 * V_188 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_106 ( V_6 -> V_18 , false ) ;
}
static void F_107 ( struct V_3 * V_4 , int V_203 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
unsigned long V_204 ;
int V_205 ;
F_69 ( & V_6 -> V_91 ) ;
V_204 = V_6 -> V_206 [ V_203 ] . V_207 ;
F_73 ( & V_6 -> V_91 ) ;
if ( F_100 ( ! V_204 ) )
return;
F_101 (q, &mq, IEEE80211_MAX_QUEUES) {
if ( F_108 ( & V_6 -> V_208 [ V_205 ] ) > 0 ) {
F_103 ( V_6 ,
L_14 ,
V_203 , V_205 ) ;
continue;
}
F_109 ( V_6 -> V_52 , V_205 ) ;
}
}
void F_110 ( struct V_5 * V_6 , bool V_210 )
{
if ( V_210 )
F_111 ( V_211 , & V_6 -> V_212 ) ;
else
F_112 ( V_211 , & V_6 -> V_212 ) ;
F_113 ( V_6 -> V_52 -> V_134 , F_114 ( V_6 ) ) ;
}
static bool F_115 ( struct V_3 * V_4 , bool V_210 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
bool V_213 = F_116 ( V_6 -> V_213 ) ;
if ( V_210 )
F_111 ( V_214 , & V_6 -> V_212 ) ;
else
F_112 ( V_214 , & V_6 -> V_212 ) ;
F_113 ( V_6 -> V_52 -> V_134 , F_114 ( V_6 ) ) ;
if ( V_213 )
F_117 ( & V_6 -> V_144 ) ;
return V_210 && ( V_6 -> V_82 != V_83 || V_213 ) ;
}
static void F_118 ( struct V_3 * V_4 , struct V_215 * V_216 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
struct V_217 * V_218 ;
V_218 = F_119 ( V_216 ) ;
F_120 ( V_6 -> V_18 , V_218 -> V_219 [ 1 ] ) ;
F_121 ( V_6 -> V_52 , V_216 ) ;
}
static void F_122 ( struct V_173 * V_174 )
{
struct V_220 * V_221 ;
V_221 = F_74 ( V_174 , struct V_220 , V_222 ) ;
if ( F_123 ( V_221 -> V_68 ) )
F_124 ( V_221 -> V_68 , L_15 ) ;
F_59 ( V_221 ) ;
F_125 ( V_223 ) ;
}
static void V_101 ( struct V_173 * V_222 )
{
struct V_5 * V_6 =
F_74 ( V_222 , struct V_5 , V_100 . V_222 ) ;
if ( F_126 ( V_6 , V_224 ) )
return;
F_43 ( & V_6 -> V_84 ) ;
if ( V_6 -> V_26 -> V_27 == V_225 ) {
F_127 ( V_6 -> V_18 , V_226 , 0x100 ) ;
} else {
F_128 ( V_6 -> V_18 , V_227 , 0 ) ;
F_129 ( 100 ) ;
}
F_130 ( V_6 ) ;
F_100 ( ( ! F_131 ( V_228 , & V_6 -> V_18 -> V_212 ) ) &&
V_6 -> V_48 -> V_140 &&
F_132 ( V_6 , V_6 -> V_229 ) ) ;
F_48 ( & V_6 -> V_84 ) ;
F_47 ( V_6 , V_224 ) ;
}
void F_133 ( struct V_5 * V_6 , bool V_230 )
{
F_117 ( & V_6 -> V_144 ) ;
F_134 ( V_6 ) ;
if ( ! V_6 -> V_73 && V_230 ) {
F_135 ( V_6 , & V_231 ,
NULL ) ;
} else if ( F_136 ( V_232 ,
& V_6 -> V_212 ) ) {
struct V_220 * V_221 ;
F_36 ( V_6 ,
L_16 ) ;
if ( ! F_137 ( V_223 ) ) {
F_36 ( V_6 , L_17 ) ;
return;
}
V_221 = F_84 ( sizeof( * V_221 ) , V_195 ) ;
if ( ! V_221 ) {
F_125 ( V_223 ) ;
return;
}
V_221 -> V_68 = V_6 -> V_18 -> V_68 ;
F_26 ( & V_221 -> V_222 , F_122 ) ;
F_89 ( & V_221 -> V_222 ) ;
} else if ( V_6 -> V_82 == V_233 ) {
F_44 ( V_6 , V_234 ) ;
if ( V_230 && V_6 -> V_73 > 0 )
V_6 -> V_73 -- ;
F_138 ( V_6 -> V_52 ) ;
}
}
static void F_139 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_140 ( V_6 ) ;
F_133 ( V_6 , true ) ;
}
static void F_141 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_13 ( 1 ) ;
F_133 ( V_6 , true ) ;
}
static bool F_142 ( struct V_5 * V_6 ,
struct V_235 * V_236 ,
struct V_237 * V_238 )
{
struct V_239 * V_240 = F_143 ( V_236 ) ;
struct V_241 * V_242 ;
struct V_243 * V_244 ;
T_4 V_245 = 0 ;
T_3 V_246 ;
if ( F_13 ( V_236 -> type != V_247 ||
V_240 -> V_248 == V_61 ) )
return false ;
V_242 = F_144 ( V_6 -> V_60 [ V_240 -> V_248 ] ) ;
if ( F_145 ( V_242 ) )
return false ;
V_244 = F_146 ( V_242 ) ;
F_69 ( & V_244 -> V_249 ) ;
for ( V_246 = 0 ; V_246 < V_250 ; V_246 ++ ) {
struct V_251 * V_252 = & V_244 -> V_252 [ V_246 ] ;
if ( F_147 ( V_252 ) )
continue;
if ( V_252 -> V_210 != V_253 )
continue;
V_245 |= F_148 ( V_246 ) ;
}
F_73 ( & V_244 -> V_249 ) ;
if ( ! V_245 )
return true ;
V_238 -> V_254 = F_149 ( V_245 ) - 1 ;
return false ;
}
static void F_150 ( void * V_255 , T_3 * V_256 ,
struct V_235 * V_236 )
{
struct V_237 * V_167 = V_255 ;
struct V_5 * V_6 = V_167 -> V_6 ;
struct V_239 * V_240 = F_143 ( V_236 ) ;
T_4 V_119 = V_257 | V_258 | V_259 ;
F_151 ( V_6 , L_18 , V_236 -> V_260 ) ;
if ( V_236 -> type != V_247 ||
! V_236 -> V_261 . V_262 )
return;
if ( F_142 ( V_6 , V_236 , V_167 ) )
V_167 -> V_263 = true ;
F_152 ( V_6 , V_236 , true , V_119 ) ;
F_153 ( V_6 , V_236 , V_167 -> V_263 ,
false , V_119 ) ;
V_167 -> V_248 = V_240 -> V_248 ;
V_167 -> V_264 ++ ;
V_167 -> V_265 = V_236 ;
}
static void F_154 ( struct V_5 * V_6 ,
struct V_266 * V_188 ,
struct V_237 * V_238 )
{
struct V_241 * V_242 ;
struct V_243 * V_267 ;
if ( V_238 -> V_248 == V_61 )
return;
F_155 () ;
V_242 = F_144 ( V_6 -> V_60 [ V_238 -> V_248 ] ) ;
if ( F_145 ( V_242 ) )
goto V_268;
V_267 = F_146 ( V_242 ) ;
V_188 -> V_269 = V_242 -> V_270 . V_271 ;
V_188 -> V_254 = V_238 -> V_254 ;
V_188 -> V_119 = V_272 | V_273 |
V_274 ;
F_156 ( V_267 , V_188 ) ;
V_268:
F_157 () ;
}
int F_158 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
T_4 V_119 = V_257 | V_258 | V_259 ;
int V_1 ;
struct V_237 V_275 = {
. V_6 = V_6 ,
} ;
struct V_266 V_276 = {
. V_277 = F_159 ( V_278 |
V_279 |
V_280 |
V_281 ) ,
} ;
struct V_282 V_283 = {
. V_284 = F_159 ( 1000 ) ,
. V_285 = F_159 ( V_286 ) ,
} ;
F_151 ( V_6 , L_19 ) ;
if ( F_100 ( V_6 -> V_82 != V_233 ) )
return - V_287 ;
F_111 ( V_288 , & V_6 -> V_212 ) ;
if ( F_160 ( V_6 ) ) {
F_151 ( V_6 -> V_18 , L_20 ) ;
F_112 ( V_288 , & V_6 -> V_212 ) ;
F_161 ( & V_6 -> V_108 ) ;
return 1 ;
}
F_162 ( V_6 -> V_52 ,
V_289 ,
F_150 ,
& V_275 ) ;
if ( V_275 . V_264 == 1 ) {
V_6 -> V_290 = V_275 . V_248 ;
V_6 -> V_291 = ! V_275 . V_263 ;
} else {
F_100 ( V_275 . V_264 > 1 ) ;
V_6 -> V_290 = V_61 ;
V_6 -> V_291 = false ;
}
F_163 () ;
V_1 = F_164 ( V_6 , F_165 ( V_6 ) , V_119 ) ;
if ( V_1 )
return V_1 ;
if ( V_6 -> V_290 != V_61 ) {
F_166 ( V_6 ,
V_275 . V_265 ,
true , V_119 ) ;
F_154 ( V_6 , & V_276 ,
& V_275 ) ;
V_1 = F_167 ( V_6 , V_292 , V_119 ,
sizeof( V_276 ) ,
& V_276 ) ;
if ( V_1 )
return V_1 ;
}
return F_167 ( V_6 , V_293 ,
V_119 | V_294 ,
sizeof( V_283 ) , & V_283 ) ;
}
static void F_168 ( void * V_255 , T_3 * V_256 ,
struct V_235 * V_236 )
{
struct V_5 * V_6 = V_255 ;
T_4 V_119 = V_257 | V_258 ;
F_151 ( V_6 , L_21 , V_236 -> V_260 ) ;
if ( V_236 -> type != V_247 ||
! V_236 -> V_261 . V_262 )
return;
F_152 ( V_6 , V_236 , false , V_119 ) ;
}
static void F_169 ( void * V_255 , T_3 * V_256 ,
struct V_235 * V_236 )
{
struct V_295 * V_167 = V_255 ;
struct V_239 * V_240 = F_143 ( V_236 ) ;
T_4 V_296 = V_167 -> V_297 ;
if ( V_236 -> type != V_247 || ! V_236 -> V_261 . V_262 ||
V_167 -> V_6 -> V_290 != V_240 -> V_248 )
return;
if ( V_296 & V_298 )
F_170 ( V_167 -> V_6 , V_236 , L_22 ) ;
else if ( V_296 & V_299 )
F_171 ( V_236 ) ;
else
F_172 ( V_167 -> V_6 , V_236 , V_167 -> V_212 ) ;
}
void F_173 ( struct V_5 * V_6 , T_5 * V_300 )
{
struct V_241 * V_301 = NULL ;
struct V_243 * V_267 ;
int V_159 ;
bool V_302 = false ;
F_174 ( & V_6 -> V_84 ) ;
F_69 ( & V_6 -> V_105 ) ;
if ( V_6 -> V_290 == V_61 )
goto V_268;
F_151 ( V_6 , L_23 ) ;
V_301 = F_175 (
V_6 -> V_60 [ V_6 -> V_290 ] ,
F_176 ( & V_6 -> V_84 ) ) ;
if ( F_145 ( V_301 ) ) {
V_301 = NULL ;
goto V_268;
}
if ( V_6 -> V_291 && V_300 ) {
V_267 = F_146 ( V_301 ) ;
for ( V_159 = 0 ; V_159 < V_250 ; V_159 ++ ) {
T_6 V_303 = F_177 ( V_300 [ V_159 ] ) ;
V_303 += 0x10 ;
V_267 -> V_252 [ V_159 ] . V_304 = V_303 ;
}
}
V_268:
while ( ! F_178 ( & V_6 -> V_107 ) ) {
struct V_215 * V_216 = F_179 ( & V_6 -> V_107 ) ;
if ( ! V_301 || F_180 ( V_6 , V_216 , V_301 ) )
F_121 ( V_6 -> V_52 , V_216 ) ;
V_302 = true ;
}
F_112 ( V_288 , & V_6 -> V_212 ) ;
F_161 ( & V_6 -> V_108 ) ;
V_6 -> V_290 = V_61 ;
if ( V_302 )
F_181 ( V_6 -> V_52 ) ;
F_73 ( & V_6 -> V_105 ) ;
}
static void V_99 ( struct V_173 * V_174 )
{
struct V_5 * V_6 = F_74 ( V_174 , struct V_5 , V_98 ) ;
struct V_305 V_306 = {
. V_307 = V_308 ,
. V_119 = V_258 | V_309 ,
} ;
struct V_295 V_238 = {
. V_6 = V_6 ,
} ;
struct V_310 * V_212 ;
int V_1 ;
T_4 V_297 = 0 ;
T_5 * V_300 = NULL ;
F_43 ( & V_6 -> V_84 ) ;
V_1 = F_182 ( V_6 , & V_306 ) ;
if ( V_1 )
goto V_268;
if ( ! V_306 . V_311 )
goto V_268;
V_212 = ( void * ) V_306 . V_311 -> V_167 ;
V_297 = F_183 ( V_212 -> V_297 ) ;
V_300 = V_212 -> V_312 ;
F_151 ( V_6 , L_24 , V_297 ) ;
V_238 . V_297 = V_297 ;
V_238 . V_212 = V_212 ;
F_184 ( V_6 -> V_52 ,
V_289 ,
F_169 ,
& V_238 ) ;
V_268:
F_173 ( V_6 , V_300 ) ;
F_15 ( V_6 , L_25 ,
V_297 ) ;
if ( V_306 . V_311 )
F_185 ( & V_306 ) ;
F_186 ( V_6 ) ;
F_47 ( V_6 , V_313 ) ;
F_48 ( & V_6 -> V_84 ) ;
}
int F_187 ( struct V_5 * V_6 )
{
T_4 V_119 = V_257 | V_258 | V_259 |
V_314 ;
int V_1 ;
F_151 ( V_6 , L_26 ) ;
if ( F_100 ( V_6 -> V_82 != V_233 ) )
return - V_287 ;
F_43 ( & V_6 -> V_85 ) ;
if ( F_131 ( V_315 , & V_6 -> V_316 ) ) {
F_151 ( V_6 , L_27 ) ;
F_188 ( V_317 , & V_6 -> V_316 ) ;
F_48 ( & V_6 -> V_85 ) ;
return 0 ;
}
F_48 ( & V_6 -> V_85 ) ;
V_1 = F_167 ( V_6 , V_318 , V_119 , 0 , NULL ) ;
if ( V_1 )
goto V_268;
F_162 ( V_6 -> V_52 ,
V_289 ,
F_168 ,
V_6 ) ;
V_268:
F_89 ( & V_6 -> V_98 ) ;
return V_1 ;
}
int F_189 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_44 ( V_6 , V_313 ) ;
return F_187 ( V_6 ) ;
}
static void F_190 ( struct V_3 * V_4 ,
struct V_199 * V_200 ,
struct V_190 * V_171 ,
unsigned int V_203 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
struct V_178 * V_179 = F_91 ( V_171 ) ;
if ( F_191 ( V_179 -> V_187 . V_188 == V_201 ) )
F_94 ( V_6 , V_171 , V_203 ) ;
else
F_97 ( V_6 , V_200 , V_171 , V_203 ) ;
}
