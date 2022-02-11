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
if ( ! F_23 ( V_6 ) ) {
V_6 -> V_79 = 16 ;
V_6 -> V_80 = V_6 -> V_26 -> V_81 -> V_82 - 1 ;
} else {
V_6 -> V_79 = V_83 ;
V_6 -> V_80 = V_84 ;
}
if ( V_6 -> V_26 -> V_81 -> V_82 == 16 ) {
V_6 -> V_78 = 11 ;
V_6 -> V_79 = 12 ;
}
V_6 -> V_85 = V_86 ;
V_6 -> V_87 = V_88 ;
V_6 -> V_89 = true ;
F_24 ( & V_6 -> V_90 ) ;
F_24 ( & V_6 -> V_91 ) ;
F_25 ( & V_6 -> V_92 ) ;
F_26 ( & V_6 -> V_93 ) ;
F_26 ( & V_6 -> V_94 ) ;
F_26 ( & V_6 -> V_95 ) ;
F_25 ( & V_6 -> V_96 ) ;
F_25 ( & V_6 -> V_97 ) ;
F_27 ( & V_6 -> V_98 , V_99 ) ;
F_27 ( & V_6 -> V_100 , V_101 ) ;
F_27 ( & V_6 -> V_102 , V_103 ) ;
F_27 ( & V_6 -> V_104 , V_105 ) ;
F_28 ( & V_6 -> V_106 , V_107 ) ;
F_28 ( & V_6 -> V_108 . V_109 , V_110 ) ;
F_27 ( & V_6 -> V_111 , V_112 ) ;
F_25 ( & V_6 -> V_113 ) ;
F_25 ( & V_6 -> V_114 ) ;
F_29 ( & V_6 -> V_115 ) ;
F_30 ( & V_6 -> V_116 ) ;
F_31 ( & V_6 -> V_117 , 0 ) ;
F_32 ( V_6 -> V_52 , V_6 -> V_18 -> V_68 ) ;
V_54 . V_4 = V_4 ;
V_54 . V_55 = V_55 ;
V_54 . V_118 = F_20 ( V_55 ) ;
switch ( V_77 . V_119 ) {
case V_120 :
V_54 . V_121 = V_120 ;
break;
case V_122 :
V_54 . V_121 = V_122 ;
break;
case V_123 :
V_54 . V_121 = V_123 ;
break;
default:
F_3 ( L_5 , V_124 ,
V_77 . V_119 ) ;
V_54 . V_121 = V_120 ;
}
V_54 . V_125 = F_33 ( & V_6 -> V_48 -> V_126 ,
V_127 ) ;
if ( V_6 -> V_48 -> V_126 . V_128 & V_129 )
V_54 . V_130 = true ;
V_54 . V_131 = V_132 ;
V_54 . V_133 = F_20 ( V_132 ) ;
if ( F_23 ( V_6 ) )
V_54 . V_134 = V_135 ;
else
V_54 . V_134 = V_136 ;
V_54 . V_137 = V_138 ;
V_54 . V_139 = true ;
V_54 . V_140 = V_48 -> V_140 ;
V_54 . V_141 = V_142 ;
V_54 . V_143 =
F_34 ( V_6 , NULL , false , true ) ;
snprintf ( V_6 -> V_52 -> V_144 -> V_145 ,
sizeof( V_6 -> V_52 -> V_144 -> V_145 ) ,
L_6 , V_48 -> V_145 ) ;
F_35 ( V_6 -> V_18 , & V_54 ) ;
V_18 -> V_146 = V_147 ;
V_18 -> V_148 = V_6 -> V_48 -> V_148 ;
V_18 -> V_149 = V_6 -> V_48 -> V_149 ;
memcpy ( V_18 -> V_150 , V_6 -> V_48 -> V_150 ,
sizeof( V_18 -> V_150 ) ) ;
V_18 -> V_151 = V_6 -> V_48 -> V_151 ;
F_36 ( & V_6 -> V_152 ) ;
V_6 -> V_153 = F_37 ( V_18 ) ;
if ( ! V_6 -> V_153 ) {
F_38 ( V_6 , L_7 ) ;
goto V_75;
}
F_39 ( V_6 , L_8 ,
V_6 -> V_26 -> V_154 , V_6 -> V_18 -> V_19 ) ;
if ( V_77 . V_155 )
V_6 -> V_156 = V_77 . V_155 ;
else
F_40 ( V_6 -> V_18 -> V_68 ,
L_9 ) ;
if ( F_41 ( V_26 -> V_157 && ! V_6 -> V_156 ,
L_10 ) )
goto V_75;
if ( V_26 -> V_157 && V_6 -> V_156 ) {
V_57 = F_42 ( V_6 , false ) ;
if ( V_57 )
goto V_75;
} else {
V_57 = F_43 ( V_6 -> V_18 ) ;
if ( V_57 )
goto V_75;
F_44 ( & V_6 -> V_90 ) ;
F_45 ( V_6 , V_158 ) ;
V_57 = F_46 ( V_6 , true ) ;
if ( ! V_57 || ! V_159 . V_160 )
F_47 ( V_6 ) ;
F_48 ( V_6 , V_158 ) ;
F_49 ( & V_6 -> V_90 ) ;
if ( V_57 < 0 && ! V_159 . V_160 ) {
F_38 ( V_6 , L_11 , V_57 ) ;
goto V_75;
}
}
V_58 = F_50 ( V_6 ) ;
V_6 -> V_161 = F_51 ( V_58 , V_162 ) ;
if ( ! V_6 -> V_161 )
goto V_75;
V_6 -> V_163 = true ;
V_57 = F_52 ( V_6 ) ;
if ( V_57 )
goto V_75;
V_59 = F_17 ( V_18 , V_26 ) ;
F_53 ( V_6 , V_59 ) ;
V_57 = F_54 ( V_6 , V_50 ) ;
if ( V_57 )
goto V_164;
memset ( & V_6 -> V_165 , 0 , sizeof( struct V_166 ) ) ;
if ( F_55 ( V_6 ) )
F_56 ( V_6 -> V_18 ) ;
F_57 ( V_6 ) ;
F_58 ( & V_6 -> V_167 , V_168 ,
( unsigned long ) V_6 ) ;
return V_4 ;
V_164:
F_59 ( V_6 -> V_52 ) ;
F_60 ( V_6 ) ;
F_61 ( V_6 ) ;
V_75:
F_62 ( & V_6 -> V_106 ) ;
F_63 ( V_6 -> V_153 ) ;
F_64 ( V_6 -> V_161 ) ;
if ( ! V_26 -> V_157 || ! V_6 -> V_156 )
F_65 ( V_18 ) ;
F_66 ( V_6 -> V_52 ) ;
return NULL ;
}
static void F_67 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
int V_169 ;
if ( F_55 ( V_6 ) )
F_68 ( V_6 -> V_18 ) ;
F_60 ( V_6 ) ;
F_61 ( V_6 ) ;
F_59 ( V_6 -> V_52 ) ;
F_64 ( V_6 -> V_161 ) ;
F_64 ( V_6 -> V_170 ) ;
V_6 -> V_170 = NULL ;
#if F_69 ( V_171 ) && F_69 ( V_172 )
F_64 ( V_6 -> V_173 ) ;
#endif
F_65 ( V_6 -> V_18 ) ;
F_63 ( V_6 -> V_153 ) ;
V_6 -> V_153 = NULL ;
F_70 ( V_6 -> V_174 ) ;
for ( V_169 = 0 ; V_169 < V_175 ; V_169 ++ )
F_64 ( V_6 -> V_176 [ V_169 ] . V_177 ) ;
F_71 ( V_6 ) ;
F_72 ( & V_6 -> V_167 ) ;
F_73 ( & V_6 -> V_90 ) ;
F_73 ( & V_6 -> V_91 ) ;
F_66 ( V_6 -> V_52 ) ;
}
void F_74 ( struct V_5 * V_6 )
{
struct V_178 * V_179 , * V_180 ;
F_75 ( & V_6 -> V_92 ) ;
F_76 (entry, tmp, &mvm->async_handlers_list, list) {
F_77 ( & V_179 -> V_181 ) ;
F_78 ( & V_179 -> V_182 ) ;
F_64 ( V_179 ) ;
}
F_79 ( & V_6 -> V_92 ) ;
}
static void V_99 ( struct V_183 * V_184 )
{
struct V_5 * V_6 =
F_80 ( V_184 , struct V_5 , V_98 ) ;
struct V_178 * V_179 , * V_180 ;
struct V_185 V_186 ;
F_26 ( & V_186 ) ;
F_75 ( & V_6 -> V_92 ) ;
F_81 ( & V_6 -> V_95 , & V_186 ) ;
F_79 ( & V_6 -> V_92 ) ;
F_76 (entry, tmp, &local_list, list) {
if ( V_179 -> V_187 == V_188 )
F_44 ( & V_6 -> V_90 ) ;
V_179 -> V_189 ( V_6 , & V_179 -> V_181 ) ;
F_77 ( & V_179 -> V_181 ) ;
F_78 ( & V_179 -> V_182 ) ;
if ( V_179 -> V_187 == V_188 )
F_49 ( & V_6 -> V_90 ) ;
F_64 ( V_179 ) ;
}
}
static inline void F_82 ( struct V_5 * V_6 ,
struct V_190 * V_191 )
{
struct V_192 * V_193 ;
struct V_194 * V_195 ;
int V_169 ;
if ( ! F_83 ( V_6 -> V_48 , V_196 ) )
return;
V_193 = F_84 ( V_6 -> V_48 , V_196 ) ;
V_195 = ( void * ) V_193 -> V_177 ;
if ( ! F_85 ( V_6 , NULL , V_193 ) )
return;
for ( V_169 = 0 ; V_169 < F_20 ( V_195 -> V_197 ) ; V_169 ++ ) {
if ( ! V_195 -> V_197 [ V_169 ] . V_198 )
break;
if ( V_195 -> V_197 [ V_169 ] . V_198 != V_191 -> V_199 . V_200 ||
V_195 -> V_197 [ V_169 ] . V_201 != V_191 -> V_199 . V_201 )
continue;
F_86 ( V_6 , V_193 ,
L_12 ,
V_191 -> V_199 . V_201 , V_191 -> V_199 . V_200 ) ;
break;
}
}
static void F_87 ( struct V_5 * V_6 ,
struct V_202 * V_181 ,
struct V_190 * V_191 )
{
int V_169 ;
F_82 ( V_6 , V_191 ) ;
F_88 ( & V_6 -> V_152 , V_191 ) ;
for ( V_169 = 0 ; V_169 < F_20 ( V_203 ) ; V_169 ++ ) {
const struct V_204 * V_205 = & V_203 [ V_169 ] ;
struct V_178 * V_179 ;
if ( V_205 -> V_198 != F_89 ( V_191 -> V_199 . V_201 , V_191 -> V_199 . V_200 ) )
continue;
if ( V_205 -> V_187 == V_206 ) {
V_205 -> V_189 ( V_6 , V_181 ) ;
return;
}
V_179 = F_90 ( sizeof( * V_179 ) , V_207 ) ;
if ( ! V_179 )
return;
V_179 -> V_181 . V_208 = F_91 ( V_181 ) ;
V_179 -> V_181 . V_209 = V_181 -> V_209 ;
V_179 -> V_181 . V_210 = V_181 -> V_210 ;
V_179 -> V_189 = V_205 -> V_189 ;
V_179 -> V_187 = V_205 -> V_187 ;
F_92 ( & V_6 -> V_92 ) ;
F_93 ( & V_179 -> V_182 , & V_6 -> V_95 ) ;
F_94 ( & V_6 -> V_92 ) ;
F_95 ( & V_6 -> V_98 ) ;
break;
}
}
static void F_96 ( struct V_3 * V_4 ,
struct V_211 * V_212 ,
struct V_202 * V_181 )
{
struct V_190 * V_191 = F_97 ( V_181 ) ;
struct V_5 * V_6 = F_9 ( V_4 ) ;
if ( F_98 ( V_191 -> V_199 . V_200 == V_147 ) )
F_99 ( V_6 , V_212 , V_181 ) ;
else if ( V_191 -> V_199 . V_200 == V_213 )
F_100 ( V_6 , V_212 , V_181 , 0 ) ;
else if ( V_191 -> V_199 . V_200 == V_214 )
F_101 ( V_6 , V_181 ) ;
else
F_87 ( V_6 , V_181 , V_191 ) ;
}
static void F_102 ( struct V_3 * V_4 ,
struct V_211 * V_212 ,
struct V_202 * V_181 )
{
struct V_190 * V_191 = F_97 ( V_181 ) ;
struct V_5 * V_6 = F_9 ( V_4 ) ;
if ( F_98 ( V_191 -> V_199 . V_200 == V_147 ) )
F_103 ( V_6 , V_212 , V_181 , 0 ) ;
else if ( V_191 -> V_199 . V_200 == V_214 )
F_104 ( V_6 , V_181 ) ;
else if ( F_105 ( V_191 -> V_199 . V_201 == V_215 &&
V_191 -> V_199 . V_200 == V_216 ) )
F_106 ( V_6 , V_181 , 0 ) ;
else
F_87 ( V_6 , V_181 , V_191 ) ;
}
void F_107 ( struct V_5 * V_6 , unsigned long V_217 )
{
int V_218 ;
if ( F_108 ( ! V_217 ) )
return;
F_109 (q, &mq, IEEE80211_MAX_QUEUES) {
if ( F_110 ( & V_6 -> V_219 [ V_218 ] ) > 1 ) {
F_111 ( V_6 ,
L_13 , V_218 ) ;
continue;
}
F_112 ( V_6 -> V_52 , V_218 ) ;
}
}
static void F_113 ( struct V_3 * V_4 ,
const struct V_220 * V_200 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_114 ( V_6 -> V_18 , false ) ;
}
static void F_115 ( struct V_3 * V_4 , int V_221 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
unsigned long V_217 ;
F_75 ( & V_6 -> V_97 ) ;
V_217 = V_6 -> V_222 [ V_221 ] . V_223 ;
F_79 ( & V_6 -> V_97 ) ;
F_107 ( V_6 , V_217 ) ;
}
void F_116 ( struct V_5 * V_6 , unsigned long V_217 )
{
int V_218 ;
if ( F_108 ( ! V_217 ) )
return;
F_109 (q, &mq, IEEE80211_MAX_QUEUES) {
if ( F_117 ( & V_6 -> V_219 [ V_218 ] ) > 0 ) {
F_111 ( V_6 ,
L_14 , V_218 ) ;
continue;
}
F_118 ( V_6 -> V_52 , V_218 ) ;
}
}
static void F_119 ( struct V_3 * V_4 , int V_221 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
unsigned long V_217 ;
F_75 ( & V_6 -> V_97 ) ;
V_217 = V_6 -> V_222 [ V_221 ] . V_223 ;
F_79 ( & V_6 -> V_97 ) ;
F_116 ( V_6 , V_217 ) ;
}
void F_120 ( struct V_5 * V_6 , bool V_224 )
{
if ( V_224 )
F_121 ( V_225 , & V_6 -> V_226 ) ;
else
F_122 ( V_225 , & V_6 -> V_226 ) ;
F_123 ( V_6 -> V_52 -> V_144 , F_124 ( V_6 ) ) ;
}
static bool F_125 ( struct V_3 * V_4 , bool V_224 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
bool V_227 = F_126 ( V_6 -> V_227 ) ;
if ( V_224 )
F_121 ( V_228 , & V_6 -> V_226 ) ;
else
F_122 ( V_228 , & V_6 -> V_226 ) ;
F_123 ( V_6 -> V_52 -> V_144 , F_124 ( V_6 ) ) ;
if ( V_227 )
F_127 ( & V_6 -> V_152 ) ;
return V_224 && ( V_6 -> V_87 != V_88 || V_227 ) ;
}
static void F_128 ( struct V_3 * V_4 , struct V_229 * V_230 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
struct V_231 * V_232 ;
V_232 = F_129 ( V_230 ) ;
F_130 ( V_6 -> V_18 , V_232 -> V_233 [ 1 ] ) ;
F_131 ( V_6 -> V_52 , V_230 ) ;
}
static void F_132 ( struct V_183 * V_184 )
{
struct V_234 * V_235 ;
V_235 = F_80 ( V_184 , struct V_234 , V_236 ) ;
if ( F_133 ( V_235 -> V_68 ) )
F_134 ( V_235 -> V_68 , L_15 ) ;
F_64 ( V_235 ) ;
F_135 ( V_237 ) ;
}
static void V_107 ( struct V_183 * V_236 )
{
struct V_5 * V_6 =
F_80 ( V_236 , struct V_5 , V_106 . V_236 ) ;
if ( F_136 ( V_6 , V_238 ) )
return;
F_44 ( & V_6 -> V_90 ) ;
if ( V_6 -> V_26 -> V_27 == V_239 ) {
F_137 ( V_6 -> V_18 , V_240 , 0x100 ) ;
} else {
F_138 ( V_6 -> V_18 , V_241 , 0 ) ;
F_139 ( 100 ) ;
}
F_140 ( V_6 ) ;
F_108 ( ( ! F_141 ( V_242 , & V_6 -> V_18 -> V_226 ) ) &&
V_6 -> V_48 -> V_148 &&
F_142 ( V_6 , V_6 -> V_243 ) ) ;
F_49 ( & V_6 -> V_90 ) ;
F_48 ( V_6 , V_238 ) ;
}
void F_143 ( struct V_5 * V_6 , bool V_244 )
{
F_127 ( & V_6 -> V_152 ) ;
F_144 ( V_6 ) ;
if ( ! V_6 -> V_76 && V_244 ) {
F_145 ( V_6 , & V_245 ,
NULL ) ;
} else if ( F_146 ( V_246 ,
& V_6 -> V_226 ) ) {
struct V_234 * V_235 ;
F_38 ( V_6 ,
L_16 ) ;
if ( ! F_147 ( V_237 ) ) {
F_38 ( V_6 , L_17 ) ;
return;
}
V_235 = F_90 ( sizeof( * V_235 ) , V_207 ) ;
if ( ! V_235 ) {
F_135 ( V_237 ) ;
return;
}
V_235 -> V_68 = V_6 -> V_18 -> V_68 ;
F_27 ( & V_235 -> V_236 , F_132 ) ;
F_95 ( & V_235 -> V_236 ) ;
} else if ( V_6 -> V_87 == V_247 ) {
F_45 ( V_6 , V_248 ) ;
if ( V_244 && V_6 -> V_76 > 0 )
V_6 -> V_76 -- ;
F_148 ( V_6 -> V_52 ) ;
}
}
static void F_149 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_150 ( V_6 ) ;
F_143 ( V_6 , true ) ;
}
static void F_151 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_13 ( 1 ) ;
F_143 ( V_6 , true ) ;
}
static bool F_152 ( struct V_5 * V_6 ,
struct V_249 * V_250 ,
struct V_251 * V_252 )
{
struct V_253 * V_254 = F_153 ( V_250 ) ;
struct V_255 * V_256 ;
T_4 V_257 = 0 ;
T_3 V_258 ;
if ( F_13 ( V_250 -> type != V_259 ||
V_254 -> V_260 == V_61 ) )
return false ;
V_256 = F_154 ( V_6 , V_254 -> V_260 ) ;
if ( ! V_256 )
return false ;
F_75 ( & V_256 -> V_261 ) ;
for ( V_258 = 0 ; V_258 < V_262 ; V_258 ++ ) {
struct V_263 * V_264 = & V_256 -> V_264 [ V_258 ] ;
if ( F_155 ( V_264 ) )
continue;
if ( V_264 -> V_224 != V_265 )
continue;
V_257 |= F_156 ( V_258 ) ;
}
F_79 ( & V_256 -> V_261 ) ;
if ( ! V_257 )
return true ;
V_252 -> V_266 = F_157 ( V_257 ) - 1 ;
return false ;
}
static void F_158 ( void * V_267 , T_3 * V_268 ,
struct V_249 * V_250 )
{
struct V_251 * V_177 = V_267 ;
struct V_5 * V_6 = V_177 -> V_6 ;
struct V_253 * V_254 = F_153 ( V_250 ) ;
T_4 V_128 = V_269 | V_270 | V_271 ;
F_159 ( V_6 , L_18 , V_250 -> V_272 ) ;
if ( V_250 -> type != V_259 ||
! V_250 -> V_273 . V_274 )
return;
if ( F_152 ( V_6 , V_250 , V_177 ) )
V_177 -> V_275 = true ;
F_160 ( V_6 , V_250 , true , V_128 ) ;
F_161 ( V_6 , V_250 , V_177 -> V_275 ,
false , V_128 ) ;
V_177 -> V_260 = V_254 -> V_260 ;
V_177 -> V_276 ++ ;
V_177 -> V_277 = V_250 ;
}
static void F_162 ( struct V_5 * V_6 ,
struct V_278 * V_200 ,
struct V_251 * V_252 )
{
struct V_279 * V_280 ;
struct V_255 * V_281 ;
if ( V_252 -> V_260 == V_61 )
return;
F_163 () ;
V_280 = F_164 ( V_6 -> V_60 [ V_252 -> V_260 ] ) ;
if ( F_165 ( V_280 ) )
goto V_282;
V_281 = F_166 ( V_280 ) ;
V_200 -> V_283 = V_280 -> V_284 . V_285 ;
V_200 -> V_266 = V_252 -> V_266 ;
V_200 -> V_128 = V_286 | V_287 |
V_288 | V_289 ;
F_167 ( V_281 , V_200 ) ;
V_282:
F_168 () ;
}
int F_169 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
T_4 V_128 = V_269 | V_270 | V_271 ;
int V_1 ;
struct V_251 V_290 = {
. V_6 = V_6 ,
} ;
struct V_278 V_291 = {
. V_292 = F_170 ( V_293 |
V_294 |
V_295 ) ,
} ;
struct V_296 V_297 = {
. V_298 = F_170 ( 1000 ) ,
. V_299 = F_170 ( V_300 ) ,
} ;
F_159 ( V_6 , L_19 ) ;
if ( F_108 ( V_6 -> V_87 != V_247 ) )
return - V_301 ;
F_121 ( V_302 , & V_6 -> V_226 ) ;
if ( F_171 ( V_6 ) ) {
F_159 ( V_6 -> V_18 , L_20 ) ;
F_122 ( V_302 , & V_6 -> V_226 ) ;
F_172 ( & V_6 -> V_116 ) ;
return 1 ;
}
F_173 ( V_6 -> V_52 ,
V_303 ,
F_158 ,
& V_290 ) ;
if ( V_290 . V_276 == 1 ) {
V_6 -> V_304 = V_290 . V_260 ;
V_6 -> V_305 = ! V_290 . V_275 ;
} else {
F_108 ( V_290 . V_276 > 1 ) ;
V_6 -> V_304 = V_61 ;
V_6 -> V_305 = false ;
}
F_174 () ;
V_1 = F_175 ( V_6 , F_176 ( V_6 ) , V_128 ) ;
if ( V_1 )
return V_1 ;
if ( V_6 -> V_304 != V_61 ) {
if ( ! F_177 ( & V_6 -> V_48 -> V_126 ,
V_306 ) )
V_291 . V_292 |=
F_170 ( V_307 ) ;
F_178 ( V_6 ,
V_290 . V_277 ,
true , V_128 ) ;
F_162 ( V_6 , & V_291 ,
& V_290 ) ;
V_1 = F_179 ( V_6 , V_308 , V_128 ,
sizeof( V_291 ) ,
& V_291 ) ;
if ( V_1 )
return V_1 ;
}
return F_179 ( V_6 , V_309 ,
V_128 | V_310 ,
sizeof( V_297 ) , & V_297 ) ;
}
static void F_180 ( void * V_267 , T_3 * V_268 ,
struct V_249 * V_250 )
{
struct V_5 * V_6 = V_267 ;
T_4 V_128 = V_269 | V_270 ;
F_159 ( V_6 , L_21 , V_250 -> V_272 ) ;
if ( V_250 -> type != V_259 ||
! V_250 -> V_273 . V_274 )
return;
F_160 ( V_6 , V_250 , false , V_128 ) ;
}
static void F_181 ( void * V_267 , T_3 * V_268 ,
struct V_249 * V_250 )
{
struct V_311 * V_177 = V_267 ;
struct V_253 * V_254 = F_153 ( V_250 ) ;
T_4 V_312 = V_177 -> V_313 ;
if ( V_250 -> type != V_259 || ! V_250 -> V_273 . V_274 ||
V_177 -> V_6 -> V_304 != V_254 -> V_260 )
return;
if ( V_312 & V_314 )
F_182 ( V_177 -> V_6 , V_250 , L_22 ) ;
else if ( V_312 & V_315 )
F_183 ( V_250 ) ;
else
F_184 ( V_177 -> V_6 , V_250 , V_177 -> V_226 ) ;
}
void F_185 ( struct V_5 * V_6 , T_5 * V_316 )
{
struct V_279 * V_317 = NULL ;
struct V_255 * V_281 ;
int V_169 ;
bool V_318 = false ;
F_186 ( & V_6 -> V_90 ) ;
F_75 ( & V_6 -> V_113 ) ;
if ( V_6 -> V_304 == V_61 )
goto V_282;
F_159 ( V_6 , L_23 ) ;
V_317 = F_187 (
V_6 -> V_60 [ V_6 -> V_304 ] ,
F_188 ( & V_6 -> V_90 ) ) ;
if ( F_165 ( V_317 ) ) {
V_317 = NULL ;
goto V_282;
}
if ( V_6 -> V_305 && V_316 ) {
V_281 = F_166 ( V_317 ) ;
for ( V_169 = 0 ; V_169 < V_262 ; V_169 ++ ) {
T_6 V_319 = F_189 ( V_316 [ V_169 ] ) ;
V_319 += 0x10 ;
V_281 -> V_264 [ V_169 ] . V_320 = V_319 ;
}
}
V_282:
while ( ! F_190 ( & V_6 -> V_115 ) ) {
struct V_229 * V_230 = F_191 ( & V_6 -> V_115 ) ;
if ( ! V_317 || F_192 ( V_6 , V_230 , V_317 ) )
F_131 ( V_6 -> V_52 , V_230 ) ;
V_318 = true ;
}
F_122 ( V_302 , & V_6 -> V_226 ) ;
F_172 ( & V_6 -> V_116 ) ;
V_6 -> V_304 = V_61 ;
if ( V_318 )
F_193 ( V_6 -> V_52 ) ;
F_79 ( & V_6 -> V_113 ) ;
}
static void V_105 ( struct V_183 * V_184 )
{
struct V_5 * V_6 = F_80 ( V_184 , struct V_5 , V_104 ) ;
struct V_321 V_322 = {
. V_323 = V_324 ,
. V_128 = V_270 | V_325 ,
} ;
struct V_311 V_252 = {
. V_6 = V_6 ,
} ;
struct V_326 * V_226 ;
int V_1 ;
T_4 V_313 = 0 ;
T_5 * V_316 = NULL ;
F_44 ( & V_6 -> V_90 ) ;
V_1 = F_194 ( V_6 , & V_322 ) ;
if ( V_1 )
goto V_282;
if ( ! V_322 . V_327 )
goto V_282;
V_226 = ( void * ) V_322 . V_327 -> V_177 ;
V_313 = F_195 ( V_226 -> V_313 ) ;
V_316 = V_226 -> V_328 ;
F_159 ( V_6 , L_24 , V_313 ) ;
V_252 . V_313 = V_313 ;
V_252 . V_226 = V_226 ;
F_196 ( V_6 -> V_52 ,
V_303 ,
F_181 ,
& V_252 ) ;
V_282:
F_185 ( V_6 , V_316 ) ;
F_15 ( V_6 , L_25 ,
V_313 ) ;
if ( V_322 . V_327 )
F_197 ( & V_322 ) ;
F_198 ( V_6 ) ;
F_48 ( V_6 , V_329 ) ;
F_49 ( & V_6 -> V_90 ) ;
}
int F_199 ( struct V_5 * V_6 )
{
T_4 V_128 = V_269 | V_270 | V_271 |
V_330 ;
int V_1 ;
F_159 ( V_6 , L_26 ) ;
if ( F_108 ( V_6 -> V_87 != V_247 ) )
return - V_301 ;
F_44 ( & V_6 -> V_91 ) ;
if ( F_141 ( V_331 , & V_6 -> V_332 ) ) {
F_159 ( V_6 , L_27 ) ;
F_200 ( V_333 , & V_6 -> V_332 ) ;
F_49 ( & V_6 -> V_91 ) ;
return 0 ;
}
F_49 ( & V_6 -> V_91 ) ;
V_1 = F_179 ( V_6 , V_334 , V_128 , 0 , NULL ) ;
if ( V_1 )
goto V_282;
F_173 ( V_6 -> V_52 ,
V_303 ,
F_180 ,
V_6 ) ;
V_282:
F_95 ( & V_6 -> V_104 ) ;
return V_1 ;
}
int F_201 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_45 ( V_6 , V_329 ) ;
return F_199 ( V_6 ) ;
}
static void F_202 ( struct V_3 * V_4 ,
struct V_211 * V_212 ,
struct V_202 * V_181 ,
unsigned int V_335 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
struct V_190 * V_191 = F_97 ( V_181 ) ;
if ( F_105 ( V_191 -> V_199 . V_200 == V_213 ) )
F_100 ( V_6 , V_212 , V_181 , V_335 ) ;
else if ( F_105 ( V_191 -> V_199 . V_200 == V_216 &&
V_191 -> V_199 . V_201 == V_215 ) )
F_106 ( V_6 , V_181 , V_335 ) ;
else
F_103 ( V_6 , V_212 , V_181 , V_335 ) ;
}
