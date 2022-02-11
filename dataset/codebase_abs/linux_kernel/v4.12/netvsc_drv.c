static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 -> V_6 ) ;
F_4 ( V_6 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_6 ( V_2 ) ;
struct V_7 * V_8 ;
int V_9 = 0 ;
F_7 ( V_2 ) ;
V_9 = F_8 ( V_6 ) ;
if ( V_9 != 0 ) {
F_9 ( V_2 , L_1 , V_9 ) ;
return V_9 ;
}
F_10 ( V_2 ) ;
V_8 = V_6 -> V_10 ;
if ( ! V_8 -> V_11 )
F_11 ( V_2 ) ;
return V_9 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 -> V_6 ) ;
int V_9 ;
T_1 V_12 , V_13 , V_14 , V_15 = 10 , V_16 = 0 , V_17 = 20 ;
struct V_18 * V_19 ;
F_13 ( V_2 ) ;
V_9 = F_14 ( V_6 ) ;
if ( V_9 != 0 ) {
F_9 ( V_2 , L_2 , V_9 ) ;
return V_9 ;
}
while ( true ) {
V_12 = 0 ;
for ( V_14 = 0 ; V_14 < V_6 -> V_20 ; V_14 ++ ) {
V_19 = V_6 -> V_21 [ V_14 ] . V_22 ;
if ( ! V_19 )
continue;
F_15 ( & V_19 -> V_23 , & V_12 ,
& V_13 ) ;
if ( V_12 )
break;
F_15 ( & V_19 -> V_24 , & V_12 ,
& V_13 ) ;
if ( V_12 )
break;
}
V_16 ++ ;
if ( V_16 > V_17 || V_12 == 0 )
break;
F_16 ( V_15 ) ;
if ( V_15 < 1000 )
V_15 *= 2 ;
}
if ( V_12 ) {
F_9 ( V_2 , L_3 ) ;
V_9 = - V_25 ;
}
return V_9 ;
}
static void * F_17 ( struct V_26 * V_27 , T_1 V_28 ,
int V_29 )
{
struct V_30 * V_31 ;
struct V_32 * V_33 ;
V_31 = & V_27 -> V_27 . V_34 ;
V_31 -> V_35 += V_28 ;
V_33 = (struct V_32 * ) ( ( void * ) V_31 +
V_31 -> V_36 + V_31 -> V_37 ) ;
V_33 -> V_38 = V_28 ;
V_33 -> type = V_29 ;
V_33 -> V_39 = sizeof( struct V_32 ) ;
V_31 -> V_37 += V_28 ;
return V_33 ;
}
static inline T_1 F_18 ( struct V_40 * V_41 , struct V_42 * V_43 )
{
struct V_44 V_45 ;
T_1 V_46 ;
static T_1 T_2 V_47 ;
F_19 ( & T_2 , sizeof( T_2 ) ) ;
if ( ! F_20 ( V_41 , & V_45 , 0 ) )
return 0 ;
if ( V_45 . V_48 . V_49 == V_50 ) {
return F_21 ( V_41 ) ;
} else {
if ( V_45 . V_48 . V_51 == F_22 ( V_52 ) )
V_46 = F_23 ( ( T_1 * ) & V_45 . V_53 . V_54 , 2 , T_2 ) ;
else if ( V_45 . V_48 . V_51 == F_22 ( V_55 ) )
V_46 = F_23 ( ( T_1 * ) & V_45 . V_53 . V_56 , 8 , T_2 ) ;
else
V_46 = 0 ;
F_24 ( V_41 , V_46 , V_57 ) ;
}
return V_46 ;
}
static inline int F_25 ( struct V_1 * V_58 ,
struct V_40 * V_41 , int V_59 )
{
const struct V_3 * V_60 = F_2 ( V_58 ) ;
struct V_42 * V_43 = V_41 -> V_43 ;
int V_61 ;
V_61 = V_60 -> V_62 [ F_18 ( V_41 , V_43 ) &
( V_63 - 1 ) ] ;
if ( V_61 != V_59 &&
V_43 && F_26 ( V_43 ) && F_27 ( V_43 -> V_64 ) )
F_28 ( V_43 , V_61 ) ;
return V_61 ;
}
static T_3 F_29 ( struct V_1 * V_58 , struct V_40 * V_41 ,
void * V_65 , T_4 V_66 )
{
unsigned int V_67 = V_58 -> V_68 ;
int V_61 = F_30 ( V_41 -> V_43 ) ;
if ( V_61 < 0 || V_41 -> V_69 ) {
if ( F_31 ( V_41 ) )
V_61 = F_32 ( V_41 ) ;
else
V_61 = F_25 ( V_58 , V_41 , V_61 ) ;
}
while ( F_33 ( V_61 >= V_67 ) )
V_61 -= V_67 ;
return V_61 ;
}
static T_1 F_34 ( struct V_70 * V_70 , T_1 V_71 , T_1 V_72 ,
struct V_73 * V_74 )
{
int V_75 = 0 ;
V_70 += ( V_71 >> V_76 ) ;
V_71 &= ~ V_77 ;
while ( V_72 > 0 ) {
unsigned long V_78 ;
V_78 = V_79 - V_71 ;
if ( V_78 > V_72 )
V_78 = V_72 ;
V_74 [ V_75 ] . V_80 = F_35 ( V_70 ) ;
V_74 [ V_75 ] . V_71 = V_71 ;
V_74 [ V_75 ] . V_72 = V_78 ;
V_71 += V_78 ;
V_72 -= V_78 ;
if ( V_71 == V_79 && V_72 ) {
V_70 ++ ;
V_71 = 0 ;
V_75 ++ ;
}
}
return V_75 + 1 ;
}
static T_1 F_36 ( void * V_81 , T_1 V_72 , struct V_40 * V_41 ,
struct V_82 * V_83 ,
struct V_73 * * V_84 )
{
struct V_73 * V_74 = * V_84 ;
T_1 V_85 = 0 ;
char * V_86 = V_41 -> V_86 ;
int V_87 = F_37 ( V_41 ) -> V_88 ;
int V_14 ;
if ( V_81 != NULL )
V_85 += F_34 ( F_38 ( V_81 ) ,
F_39 ( V_81 ) ,
V_72 , & V_74 [ V_85 ] ) ;
V_83 -> V_89 = V_72 ;
V_83 -> V_90 = V_85 ;
V_85 += F_34 ( F_38 ( V_86 ) ,
F_39 ( V_86 ) ,
F_40 ( V_41 ) , & V_74 [ V_85 ] ) ;
for ( V_14 = 0 ; V_14 < V_87 ; V_14 ++ ) {
T_5 * V_91 = F_37 ( V_41 ) -> V_87 + V_14 ;
V_85 += F_34 ( F_41 ( V_91 ) ,
V_91 -> V_92 ,
F_42 ( V_91 ) , & V_74 [ V_85 ] ) ;
}
return V_85 ;
}
static int F_43 ( struct V_40 * V_41 )
{
int V_14 , V_87 = F_37 ( V_41 ) -> V_88 ;
int V_93 = 0 ;
for ( V_14 = 0 ; V_14 < V_87 ; V_14 ++ ) {
T_5 * V_91 = F_37 ( V_41 ) -> V_87 + V_14 ;
unsigned long V_38 = F_42 ( V_91 ) ;
unsigned long V_71 = V_91 -> V_92 ;
V_71 &= ~ V_77 ;
V_93 += F_44 ( V_71 + V_38 ) ;
}
return V_93 ;
}
static int F_45 ( struct V_40 * V_41 )
{
char * V_86 = V_41 -> V_86 ;
unsigned int V_71 = F_39 ( V_86 ) ;
unsigned int V_72 = F_40 ( V_41 ) ;
int V_94 ;
int V_95 ;
V_94 = F_46 ( V_71 + V_72 , V_79 ) ;
V_95 = F_43 ( V_41 ) ;
return V_94 + V_95 ;
}
static T_1 F_47 ( struct V_40 * V_41 )
{
if ( V_41 -> V_96 == F_22 ( V_52 ) ) {
struct V_97 * V_98 = F_48 ( V_41 ) ;
if ( V_98 -> V_96 == V_50 )
return V_99 ;
else if ( V_98 -> V_96 == V_100 )
return V_101 ;
} else {
struct V_102 * V_103 = F_49 ( V_41 ) ;
if ( V_103 -> V_104 == V_50 )
return V_105 ;
else if ( F_49 ( V_41 ) -> V_104 == V_100 )
return V_106 ;
}
return V_107 ;
}
static int F_50 ( struct V_40 * V_41 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_82 * V_83 = NULL ;
int V_9 ;
unsigned int V_108 ;
struct V_26 * V_109 ;
struct V_30 * V_31 ;
T_1 V_110 ;
struct V_32 * V_33 ;
T_1 V_46 ;
struct V_73 V_84 [ V_111 ] ;
struct V_73 * V_74 = V_84 ;
V_108 = F_45 ( V_41 ) + 2 ;
if ( F_33 ( V_108 > V_111 ) ) {
++ V_4 -> V_112 . V_113 ;
if ( F_51 ( V_41 ) )
goto V_114;
V_108 = F_45 ( V_41 ) + 2 ;
if ( V_108 > V_111 ) {
++ V_4 -> V_112 . V_115 ;
goto V_116;
}
}
V_9 = F_52 ( V_41 , V_117 ) ;
if ( V_9 )
goto V_114;
F_53 ( sizeof( struct V_82 ) >
F_54 ( struct V_40 , V_118 ) ) ;
V_83 = (struct V_82 * ) V_41 -> V_118 ;
V_83 -> V_61 = F_55 ( V_41 ) ;
V_83 -> V_119 = V_41 -> V_72 ;
V_83 -> V_120 = V_41 -> V_72 ;
V_83 -> V_121 = 1 ;
V_109 = (struct V_26 * ) V_41 -> V_122 ;
memset ( V_109 , 0 , V_117 ) ;
V_109 -> V_123 = V_124 ;
V_109 -> V_125 = V_83 -> V_119 ;
V_31 = & V_109 -> V_27 . V_34 ;
V_31 -> V_35 = sizeof( struct V_30 ) ;
V_31 -> V_126 = V_83 -> V_119 ;
V_31 -> V_36 = sizeof( struct V_30 ) ;
V_110 = F_56 ( struct V_30 ) ;
V_46 = F_57 ( V_41 ) ;
if ( V_46 != 0 && V_2 -> V_68 > 1 ) {
V_110 += V_127 ;
V_33 = F_17 ( V_109 , V_127 ,
V_128 ) ;
* ( T_1 * ) ( ( void * ) V_33 + V_33 -> V_39 ) = V_46 ;
}
if ( F_58 ( V_41 ) ) {
struct V_129 * V_130 ;
V_110 += V_131 ;
V_33 = F_17 ( V_109 , V_131 ,
V_132 ) ;
V_130 = (struct V_129 * ) ( ( void * ) V_33 +
V_33 -> V_39 ) ;
V_130 -> V_133 = V_41 -> V_134 & V_135 ;
V_130 -> V_136 = ( V_41 -> V_134 & V_137 ) >>
V_138 ;
}
if ( F_59 ( V_41 ) ) {
struct V_139 * V_140 ;
V_110 += V_141 ;
V_33 = F_17 ( V_109 , V_141 ,
V_142 ) ;
V_140 = (struct V_139 * ) ( ( void * ) V_33 +
V_33 -> V_39 ) ;
V_140 -> V_143 . type = V_144 ;
if ( V_41 -> V_96 == F_22 ( V_52 ) ) {
V_140 -> V_143 . V_145 =
V_146 ;
F_48 ( V_41 ) -> V_147 = 0 ;
F_48 ( V_41 ) -> V_148 = 0 ;
F_60 ( V_41 ) -> V_148 =
~ F_61 ( F_48 ( V_41 ) -> V_149 ,
F_48 ( V_41 ) -> V_150 , 0 , V_50 , 0 ) ;
} else {
V_140 -> V_143 . V_145 =
V_151 ;
F_49 ( V_41 ) -> V_152 = 0 ;
F_60 ( V_41 ) -> V_148 =
~ F_62 ( & F_49 ( V_41 ) -> V_149 ,
& F_49 ( V_41 ) -> V_150 , 0 , V_50 , 0 ) ;
}
V_140 -> V_143 . V_153 = F_63 ( V_41 ) ;
V_140 -> V_143 . V_154 = F_37 ( V_41 ) -> V_155 ;
} else if ( V_41 -> V_156 == V_157 ) {
if ( F_47 ( V_41 ) & V_4 -> V_158 ) {
struct V_159 * V_160 ;
V_110 += V_161 ;
V_33 = F_17 ( V_109 , V_161 ,
V_162 ) ;
V_160 = (struct V_159 * ) ( ( void * ) V_33 +
V_33 -> V_39 ) ;
V_160 -> V_163 . V_153 = F_63 ( V_41 ) ;
if ( V_41 -> V_96 == F_22 ( V_52 ) ) {
V_160 -> V_163 . V_164 = 1 ;
if ( F_48 ( V_41 ) -> V_96 == V_50 )
V_160 -> V_163 . V_165 = 1 ;
else
V_160 -> V_163 . V_166 = 1 ;
} else {
V_160 -> V_163 . V_167 = 1 ;
if ( F_49 ( V_41 ) -> V_104 == V_50 )
V_160 -> V_163 . V_165 = 1 ;
else
V_160 -> V_163 . V_166 = 1 ;
}
} else {
if ( F_64 ( V_41 ) )
goto V_116;
}
}
V_109 -> V_125 += V_110 ;
V_83 -> V_119 = V_109 -> V_125 ;
V_83 -> V_168 = F_36 ( V_109 , V_110 ,
V_41 , V_83 , & V_74 ) ;
F_65 ( V_41 ) ;
V_9 = F_66 ( V_4 -> V_169 , V_83 ,
V_109 , & V_74 , V_41 ) ;
if ( F_67 ( V_9 == 0 ) )
return V_170 ;
if ( V_9 == - V_171 ) {
++ V_4 -> V_112 . V_172 ;
return V_173 ;
}
if ( V_9 == - V_174 )
++ V_4 -> V_112 . V_175 ;
V_116:
F_68 ( V_41 ) ;
V_2 -> V_176 . V_177 ++ ;
return V_170 ;
V_114:
++ V_4 -> V_112 . V_178 ;
goto V_116;
}
void F_69 ( struct V_179 * V_180 ,
struct V_26 * V_181 )
{
struct V_182 * V_183 = & V_181 -> V_27 . V_184 ;
struct V_1 * V_2 ;
struct V_3 * V_185 ;
struct V_186 * V_187 ;
unsigned long V_188 ;
V_2 = F_70 ( V_180 ) ;
if ( ! V_2 )
return;
V_185 = F_2 ( V_2 ) ;
if ( V_183 -> V_189 == V_190 ) {
T_1 V_191 ;
V_191 = * ( T_1 * ) ( ( void * ) V_183 + V_183 ->
V_192 ) / 10000 ;
V_185 -> V_191 = V_191 ;
return;
}
if ( V_183 -> V_189 != V_193 &&
V_183 -> V_189 != V_194 &&
V_183 -> V_189 != V_195 )
return;
if ( V_2 -> V_196 != V_197 )
return;
V_187 = F_71 ( sizeof( * V_187 ) , V_198 ) ;
if ( ! V_187 )
return;
V_187 -> V_187 = V_183 -> V_189 ;
F_72 ( & V_185 -> V_199 , V_188 ) ;
F_73 ( & V_187 -> V_200 , & V_185 -> V_201 ) ;
F_74 ( & V_185 -> V_199 , V_188 ) ;
F_75 ( & V_185 -> V_202 , 0 ) ;
}
static struct V_40 * F_76 ( struct V_1 * V_2 ,
struct V_203 * V_204 ,
const struct V_159 * V_160 ,
const struct V_129 * V_130 ,
void * V_86 , T_1 V_205 )
{
struct V_40 * V_41 ;
V_41 = F_77 ( V_204 , V_205 ) ;
if ( ! V_41 )
return V_41 ;
memcpy ( F_78 ( V_41 , V_205 ) , V_86 , V_205 ) ;
V_41 -> V_96 = F_79 ( V_41 , V_2 ) ;
F_80 ( V_41 ) ;
if ( V_160 && ( V_2 -> V_206 & V_207 ) ) {
if ( V_160 -> V_208 . V_209 ||
V_160 -> V_208 . V_210 )
V_41 -> V_156 = V_211 ;
}
if ( V_130 ) {
T_3 V_134 = V_130 -> V_133 | ( V_130 -> V_136 << V_138 ) ;
F_81 ( V_41 , F_22 ( V_212 ) ,
V_134 ) ;
}
return V_41 ;
}
int F_82 ( struct V_1 * V_2 ,
struct V_18 * V_22 ,
void * V_86 , T_1 V_72 ,
const struct V_159 * V_160 ,
const struct V_129 * V_130 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_1 ;
T_3 V_61 = V_22 -> V_213 . V_214 . V_215 ;
struct V_216 * V_217 ;
struct V_1 * V_218 ;
struct V_40 * V_41 ;
struct V_219 * V_220 ;
if ( V_2 -> V_196 != V_197 )
return V_221 ;
F_83 () ;
V_1 = F_84 ( V_4 -> V_6 ) ;
if ( F_33 ( ! V_1 ) )
goto V_116;
V_217 = & V_1 -> V_21 [ V_61 ] ;
V_218 = F_84 ( V_4 -> V_218 ) ;
if ( V_218 && ( V_218 -> V_188 & V_222 ) )
V_2 = V_218 ;
V_41 = F_76 ( V_2 , & V_217 -> V_204 ,
V_160 , V_130 , V_86 , V_72 ) ;
if ( F_33 ( ! V_41 ) ) {
V_116:
++ V_2 -> V_176 . V_223 ;
F_85 () ;
return V_221 ;
}
if ( V_2 != V_218 )
F_86 ( V_41 , V_61 ) ;
V_220 = & V_217 -> V_220 ;
F_87 ( & V_220 -> V_224 ) ;
V_220 -> V_225 ++ ;
V_220 -> V_78 += V_72 ;
if ( V_41 -> V_29 == V_226 )
++ V_220 -> V_227 ;
else if ( V_41 -> V_29 == V_228 )
++ V_220 -> V_229 ;
F_88 ( & V_220 -> V_224 ) ;
F_89 ( & V_217 -> V_204 , V_41 ) ;
F_85 () ;
return 0 ;
}
static void F_90 ( struct V_1 * V_2 ,
struct V_230 * V_231 )
{
F_91 ( V_231 -> V_232 , V_233 , sizeof( V_231 -> V_232 ) ) ;
F_91 ( V_231 -> V_234 , L_4 , sizeof( V_231 -> V_234 ) ) ;
}
static void F_92 ( struct V_1 * V_2 ,
struct V_235 * V_22 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 -> V_6 ) ;
if ( V_6 ) {
V_22 -> V_236 = V_6 -> V_237 ;
V_22 -> V_238 = V_6 -> V_20 ;
}
}
static int F_93 ( struct V_1 * V_2 , struct V_179 * V_239 ,
T_1 V_20 )
{
struct V_240 V_241 ;
int V_9 ;
memset ( & V_241 , 0 , sizeof( V_241 ) ) ;
V_241 . V_20 = V_20 ;
V_241 . V_242 = V_242 ;
V_241 . V_243 = V_20 ;
V_9 = F_94 ( V_239 , & V_241 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_95 ( V_2 , V_20 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_96 ( V_2 , V_20 ) ;
return V_9 ;
}
static int F_97 ( struct V_1 * V_2 ,
struct V_235 * V_244 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_179 * V_239 = V_4 -> V_169 ;
struct V_5 * V_6 = F_3 ( V_4 -> V_6 ) ;
unsigned int V_245 = V_244 -> V_238 ;
bool V_246 ;
int V_9 ;
if ( V_245 == 0 ||
V_244 -> V_247 || V_244 -> V_248 || V_244 -> V_249 )
return - V_250 ;
if ( V_245 > V_2 -> V_67 || V_245 > V_251 )
return - V_250 ;
if ( ! V_6 || V_6 -> V_252 )
return - V_253 ;
if ( V_6 -> V_254 < V_255 )
return - V_250 ;
if ( V_245 > V_6 -> V_237 )
return - V_250 ;
V_246 = F_98 ( V_2 ) ;
if ( V_246 ) {
V_9 = F_12 ( V_2 ) ;
if ( V_9 )
return V_9 ;
}
F_99 ( V_239 , V_6 ) ;
V_9 = F_93 ( V_2 , V_239 , V_245 ) ;
if ( V_9 == 0 )
V_6 -> V_20 = V_245 ;
else
F_93 ( V_2 , V_239 , V_6 -> V_20 ) ;
if ( V_246 )
V_9 = F_5 ( V_2 ) ;
F_75 ( & V_4 -> V_202 , 0 ) ;
return V_9 ;
}
static bool
F_100 ( const struct V_256 * V_257 )
{
struct V_256 V_258 = * V_257 ;
struct V_256 V_259 = {} ;
V_258 . V_260 . V_191 = 0 ;
V_258 . V_260 . V_261 = 0 ;
F_101 ( & V_258 , V_262 ) ;
V_258 . V_260 . V_257 = 0 ;
V_259 . V_260 . V_263 = V_264 ;
return ! memcmp ( & V_258 , & V_259 , sizeof( V_258 ) ) ;
}
static void F_102 ( struct V_1 * V_239 )
{
struct V_3 * V_60 = F_2 ( V_239 ) ;
V_60 -> V_191 = V_265 ;
V_60 -> V_261 = V_266 ;
}
static int F_103 ( struct V_1 * V_239 ,
struct V_256 * V_257 )
{
struct V_3 * V_60 = F_2 ( V_239 ) ;
V_257 -> V_260 . V_191 = V_60 -> V_191 ;
V_257 -> V_260 . V_261 = V_60 -> V_261 ;
V_257 -> V_260 . V_263 = V_264 ;
return 0 ;
}
static int F_104 ( struct V_1 * V_239 ,
const struct V_256 * V_257 )
{
struct V_3 * V_60 = F_2 ( V_239 ) ;
T_1 V_191 ;
V_191 = V_257 -> V_260 . V_191 ;
if ( ! F_105 ( V_191 ) ||
! F_106 ( V_257 -> V_260 . V_261 ) ||
! F_100 ( V_257 ) )
return - V_250 ;
V_60 -> V_191 = V_191 ;
V_60 -> V_261 = V_257 -> V_260 . V_261 ;
return 0 ;
}
static int F_107 ( struct V_1 * V_58 , int V_267 )
{
struct V_3 * V_268 = F_2 ( V_58 ) ;
struct V_5 * V_6 = F_3 ( V_268 -> V_6 ) ;
struct V_179 * V_269 = V_268 -> V_169 ;
struct V_240 V_241 ;
bool V_246 ;
int V_9 = 0 ;
if ( ! V_6 || V_6 -> V_252 )
return - V_253 ;
V_246 = F_98 ( V_58 ) ;
if ( V_246 ) {
V_9 = F_12 ( V_58 ) ;
if ( V_9 )
return V_9 ;
}
memset ( & V_241 , 0 , sizeof( V_241 ) ) ;
V_241 . V_242 = V_242 ;
V_241 . V_20 = V_6 -> V_20 ;
V_241 . V_243 = V_6 -> V_20 ;
F_99 ( V_269 , V_6 ) ;
V_58 -> V_267 = V_267 ;
F_94 ( V_269 , & V_241 ) ;
if ( V_246 )
V_9 = F_5 ( V_58 ) ;
F_75 ( & V_268 -> V_202 , 0 ) ;
return V_9 ;
}
static void F_108 ( struct V_1 * V_2 ,
struct V_270 * V_271 )
{
struct V_3 * V_185 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_109 ( V_185 -> V_6 ) ;
int V_14 ;
if ( ! V_6 )
return;
for ( V_14 = 0 ; V_14 < V_6 -> V_20 ; V_14 ++ ) {
const struct V_216 * V_217 = & V_6 -> V_21 [ V_14 ] ;
const struct V_219 * V_176 ;
T_6 V_225 , V_78 , V_229 ;
unsigned int V_272 ;
V_176 = & V_217 -> V_273 ;
do {
V_272 = F_110 ( & V_176 -> V_224 ) ;
V_225 = V_176 -> V_225 ;
V_78 = V_176 -> V_78 ;
} while ( F_111 ( & V_176 -> V_224 , V_272 ) );
V_271 -> V_274 += V_78 ;
V_271 -> V_275 += V_225 ;
V_176 = & V_217 -> V_220 ;
do {
V_272 = F_110 ( & V_176 -> V_224 ) ;
V_225 = V_176 -> V_225 ;
V_78 = V_176 -> V_78 ;
V_229 = V_176 -> V_229 + V_176 -> V_227 ;
} while ( F_111 ( & V_176 -> V_224 , V_272 ) );
V_271 -> V_276 += V_78 ;
V_271 -> V_277 += V_225 ;
V_271 -> V_229 += V_229 ;
}
V_271 -> V_177 = V_2 -> V_176 . V_177 ;
V_271 -> V_278 = V_2 -> V_176 . V_278 ;
V_271 -> V_223 = V_2 -> V_176 . V_223 ;
V_271 -> V_279 = V_2 -> V_176 . V_279 ;
}
static int F_112 ( struct V_1 * V_58 , void * V_280 )
{
struct V_281 * V_282 = V_280 ;
char V_283 [ V_284 ] ;
unsigned char V_285 ;
int V_286 ;
memcpy ( V_283 , V_58 -> V_287 , V_284 ) ;
V_285 = V_58 -> V_288 ;
V_286 = F_113 ( V_58 , V_280 ) ;
if ( V_286 != 0 )
return V_286 ;
V_286 = F_114 ( V_58 , V_282 -> V_289 ) ;
if ( V_286 != 0 ) {
memcpy ( V_58 -> V_287 , V_283 , V_284 ) ;
V_58 -> V_288 = V_285 ;
}
return V_286 ;
}
static int F_115 ( struct V_1 * V_239 , int V_290 )
{
struct V_3 * V_60 = F_2 ( V_239 ) ;
struct V_5 * V_6 = F_3 ( V_60 -> V_6 ) ;
if ( ! V_6 )
return - V_253 ;
switch ( V_290 ) {
case V_291 :
return V_292 + F_116 ( V_6 ) ;
default:
return - V_250 ;
}
}
static void F_117 ( struct V_1 * V_239 ,
struct V_293 * V_176 , T_6 * V_86 )
{
struct V_3 * V_60 = F_2 ( V_239 ) ;
struct V_5 * V_6 = F_84 ( V_60 -> V_6 ) ;
const void * V_294 = & V_60 -> V_112 ;
const struct V_219 * V_295 ;
unsigned int V_272 ;
T_6 V_225 , V_78 ;
int V_14 , V_75 ;
if ( ! V_6 )
return;
for ( V_14 = 0 ; V_14 < V_292 ; V_14 ++ )
V_86 [ V_14 ] = * ( unsigned long * ) ( V_294 + V_219 [ V_14 ] . V_71 ) ;
for ( V_75 = 0 ; V_75 < V_6 -> V_20 ; V_75 ++ ) {
V_295 = & V_6 -> V_21 [ V_75 ] . V_273 ;
do {
V_272 = F_110 ( & V_295 -> V_224 ) ;
V_225 = V_295 -> V_225 ;
V_78 = V_295 -> V_78 ;
} while ( F_111 ( & V_295 -> V_224 , V_272 ) );
V_86 [ V_14 ++ ] = V_225 ;
V_86 [ V_14 ++ ] = V_78 ;
V_295 = & V_6 -> V_21 [ V_75 ] . V_220 ;
do {
V_272 = F_110 ( & V_295 -> V_224 ) ;
V_225 = V_295 -> V_225 ;
V_78 = V_295 -> V_78 ;
} while ( F_111 ( & V_295 -> V_224 , V_272 ) );
V_86 [ V_14 ++ ] = V_225 ;
V_86 [ V_14 ++ ] = V_78 ;
}
}
static void F_118 ( struct V_1 * V_239 , T_1 V_296 , T_7 * V_86 )
{
struct V_3 * V_60 = F_2 ( V_239 ) ;
struct V_5 * V_6 = F_84 ( V_60 -> V_6 ) ;
T_7 * V_280 = V_86 ;
int V_14 ;
if ( ! V_6 )
return;
switch ( V_296 ) {
case V_291 :
for ( V_14 = 0 ; V_14 < F_119 ( V_219 ) ; V_14 ++ )
memcpy ( V_280 + V_14 * V_297 ,
V_219 [ V_14 ] . V_298 , V_297 ) ;
V_280 += V_14 * V_297 ;
for ( V_14 = 0 ; V_14 < V_6 -> V_20 ; V_14 ++ ) {
sprintf ( V_280 , L_5 , V_14 ) ;
V_280 += V_297 ;
sprintf ( V_280 , L_6 , V_14 ) ;
V_280 += V_297 ;
sprintf ( V_280 , L_7 , V_14 ) ;
V_280 += V_297 ;
sprintf ( V_280 , L_8 , V_14 ) ;
V_280 += V_297 ;
}
break;
}
}
static int
F_120 ( struct V_5 * V_6 ,
struct V_299 * V_231 )
{
V_231 -> V_86 = V_300 | V_301 ;
switch ( V_231 -> V_302 ) {
case V_303 :
case V_304 :
V_231 -> V_86 |= V_305 | V_306 ;
case V_307 :
case V_308 :
case V_309 :
case V_310 :
break;
default:
V_231 -> V_86 = 0 ;
break;
}
return 0 ;
}
static int
F_121 ( struct V_1 * V_239 , struct V_299 * V_231 ,
T_1 * V_311 )
{
struct V_3 * V_60 = F_2 ( V_239 ) ;
struct V_5 * V_6 = F_84 ( V_60 -> V_6 ) ;
if ( ! V_6 )
return - V_253 ;
switch ( V_231 -> V_257 ) {
case V_312 :
V_231 -> V_86 = V_6 -> V_20 ;
return 0 ;
case V_313 :
return F_120 ( V_6 , V_231 ) ;
}
return - V_314 ;
}
static void F_122 ( struct V_1 * V_239 )
{
struct V_3 * V_60 = F_2 ( V_239 ) ;
struct V_5 * V_58 ;
int V_14 ;
F_83 () ;
V_58 = F_84 ( V_60 -> V_6 ) ;
if ( V_58 ) {
for ( V_14 = 0 ; V_14 < V_58 -> V_20 ; V_14 ++ ) {
struct V_216 * V_217 = & V_58 -> V_21 [ V_14 ] ;
F_123 ( & V_217 -> V_204 ) ;
}
}
F_85 () ;
}
static T_1 F_124 ( struct V_1 * V_239 )
{
return V_315 ;
}
static T_1 F_125 ( struct V_1 * V_239 )
{
return V_316 ;
}
static int F_126 ( struct V_1 * V_239 , T_1 * V_317 , T_7 * V_318 ,
T_7 * V_319 )
{
struct V_3 * V_60 = F_2 ( V_239 ) ;
struct V_5 * V_58 = F_84 ( V_60 -> V_6 ) ;
struct V_7 * V_320 ;
int V_14 ;
if ( ! V_58 )
return - V_253 ;
if ( V_319 )
* V_319 = V_321 ;
V_320 = V_58 -> V_10 ;
if ( V_317 ) {
for ( V_14 = 0 ; V_14 < V_316 ; V_14 ++ )
V_317 [ V_14 ] = V_320 -> V_322 [ V_14 ] ;
}
if ( V_318 )
memcpy ( V_318 , V_320 -> V_323 , V_315 ) ;
return 0 ;
}
static int F_127 ( struct V_1 * V_239 , const T_1 * V_317 ,
const T_7 * V_318 , const T_7 V_319 )
{
struct V_3 * V_60 = F_2 ( V_239 ) ;
struct V_5 * V_58 = F_3 ( V_60 -> V_6 ) ;
struct V_7 * V_320 ;
int V_14 ;
if ( ! V_58 )
return - V_253 ;
if ( V_319 != V_324 && V_319 != V_321 )
return - V_314 ;
V_320 = V_58 -> V_10 ;
if ( V_317 ) {
for ( V_14 = 0 ; V_14 < V_316 ; V_14 ++ )
if ( V_317 [ V_14 ] >= V_251 )
return - V_250 ;
for ( V_14 = 0 ; V_14 < V_316 ; V_14 ++ )
V_320 -> V_322 [ V_14 ] = V_317 [ V_14 ] ;
}
if ( ! V_318 ) {
if ( ! V_317 )
return 0 ;
V_318 = V_320 -> V_323 ;
}
return F_128 ( V_320 , V_318 , V_58 -> V_20 ) ;
}
static void F_129 ( struct V_325 * V_326 )
{
struct V_3 * V_185 =
F_130 ( V_326 , struct V_3 , V_202 . V_327 ) ;
struct V_179 * V_180 = V_185 -> V_169 ;
struct V_1 * V_2 = F_70 ( V_180 ) ;
struct V_5 * V_1 ;
struct V_7 * V_8 ;
struct V_186 * V_187 = NULL ;
bool V_328 = false , V_329 = false ;
unsigned long V_188 , V_330 , V_331 ;
F_131 () ;
V_1 = F_3 ( V_185 -> V_6 ) ;
if ( ! V_1 )
goto V_332;
V_8 = V_1 -> V_10 ;
V_330 = V_185 -> V_333 + V_334 ;
if ( F_132 ( V_330 ) ) {
V_331 = V_330 - V_335 ;
V_331 = V_331 < V_334 ? V_331 : V_334 ;
F_75 ( & V_185 -> V_202 , V_331 ) ;
goto V_332;
}
V_185 -> V_333 = V_335 ;
F_72 ( & V_185 -> V_199 , V_188 ) ;
if ( ! F_133 ( & V_185 -> V_201 ) ) {
V_187 = F_134 ( & V_185 -> V_201 ,
struct V_186 , V_200 ) ;
F_135 ( & V_187 -> V_200 ) ;
V_329 = ! F_133 ( & V_185 -> V_201 ) ;
}
F_74 ( & V_185 -> V_199 , V_188 ) ;
if ( ! V_187 )
goto V_332;
switch ( V_187 -> V_187 ) {
case V_194 :
if ( V_8 -> V_11 ) {
V_8 -> V_11 = false ;
F_11 ( V_2 ) ;
F_10 ( V_2 ) ;
} else {
V_328 = true ;
}
F_136 ( V_187 ) ;
break;
case V_195 :
if ( ! V_8 -> V_11 ) {
V_8 -> V_11 = true ;
F_7 ( V_2 ) ;
F_137 ( V_2 ) ;
}
F_136 ( V_187 ) ;
break;
case V_193 :
if ( ! V_8 -> V_11 ) {
V_8 -> V_11 = true ;
F_7 ( V_2 ) ;
F_137 ( V_2 ) ;
V_187 -> V_187 = V_194 ;
F_72 ( & V_185 -> V_199 , V_188 ) ;
F_138 ( & V_187 -> V_200 , & V_185 -> V_201 ) ;
F_74 ( & V_185 -> V_199 , V_188 ) ;
V_329 = true ;
}
break;
}
F_139 () ;
if ( V_328 )
F_140 ( V_2 ) ;
if ( V_329 )
F_75 ( & V_185 -> V_202 , V_334 ) ;
return;
V_332:
F_139 () ;
}
static struct V_1 * F_141 ( const T_7 * V_336 )
{
struct V_1 * V_239 ;
F_142 () ;
F_143 (&init_net, dev) {
if ( V_239 -> V_337 != & V_338 )
continue;
if ( F_144 ( V_336 , V_239 -> V_339 ) )
return V_239 ;
}
return NULL ;
}
static struct V_1 * F_145 ( struct V_1 * V_218 )
{
struct V_1 * V_239 ;
F_142 () ;
F_143 (&init_net, dev) {
struct V_3 * V_4 ;
if ( V_239 -> V_337 != & V_338 )
continue;
V_4 = F_2 ( V_239 ) ;
if ( V_4 -> V_6 == NULL )
continue;
if ( F_3 ( V_4 -> V_218 ) == V_218 )
return V_239 ;
}
return NULL ;
}
static int F_146 ( struct V_1 * V_218 )
{
struct V_1 * V_58 ;
struct V_3 * V_4 ;
struct V_5 * V_340 ;
if ( V_218 -> V_341 != V_284 )
return V_342 ;
V_58 = F_141 ( V_218 -> V_339 ) ;
if ( ! V_58 )
return V_342 ;
V_4 = F_2 ( V_58 ) ;
V_340 = F_3 ( V_4 -> V_6 ) ;
if ( ! V_340 || F_3 ( V_4 -> V_218 ) )
return V_342 ;
F_147 ( V_58 , L_9 , V_218 -> V_298 ) ;
F_148 ( V_343 ) ;
F_149 ( V_218 ) ;
F_150 ( V_4 -> V_218 , V_218 ) ;
return V_344 ;
}
static int F_151 ( struct V_1 * V_218 )
{
struct V_1 * V_58 ;
struct V_5 * V_340 ;
struct V_3 * V_4 ;
V_58 = F_145 ( V_218 ) ;
if ( ! V_58 )
return V_342 ;
V_4 = F_2 ( V_58 ) ;
V_340 = F_3 ( V_4 -> V_6 ) ;
F_147 ( V_58 , L_10 , V_218 -> V_298 ) ;
F_8 ( V_340 ) ;
F_152 ( V_58 , true ) ;
F_147 ( V_58 , L_11 , V_218 -> V_298 ) ;
F_7 ( V_58 ) ;
F_153 ( V_345 , V_218 ) ;
return V_344 ;
}
static int F_154 ( struct V_1 * V_218 )
{
struct V_1 * V_58 ;
struct V_5 * V_340 ;
struct V_3 * V_4 ;
V_58 = F_145 ( V_218 ) ;
if ( ! V_58 )
return V_342 ;
V_4 = F_2 ( V_58 ) ;
V_340 = F_3 ( V_4 -> V_6 ) ;
F_147 ( V_58 , L_12 , V_218 -> V_298 ) ;
F_152 ( V_58 , false ) ;
F_147 ( V_58 , L_13 , V_218 -> V_298 ) ;
F_14 ( V_340 ) ;
F_11 ( V_58 ) ;
F_153 ( V_345 , V_58 ) ;
return V_344 ;
}
static int F_155 ( struct V_1 * V_218 )
{
struct V_1 * V_58 ;
struct V_3 * V_4 ;
V_58 = F_145 ( V_218 ) ;
if ( ! V_58 )
return V_342 ;
V_4 = F_2 ( V_58 ) ;
F_147 ( V_58 , L_14 , V_218 -> V_298 ) ;
F_156 ( V_4 -> V_218 , NULL ) ;
F_157 ( V_218 ) ;
F_158 ( V_343 ) ;
return V_344 ;
}
static int F_159 ( struct V_179 * V_239 ,
const struct V_346 * V_347 )
{
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
struct V_240 V_241 ;
struct V_5 * V_6 ;
int V_9 ;
V_2 = F_160 ( sizeof( struct V_3 ) ,
V_251 ) ;
if ( ! V_2 )
return - V_348 ;
F_7 ( V_2 ) ;
F_102 ( V_2 ) ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_169 = V_239 ;
V_4 -> V_349 = F_161 ( V_350 , V_351 ) ;
if ( F_162 ( V_4 ) )
F_163 ( V_2 , L_15 ,
V_4 -> V_349 ) ;
F_164 ( V_239 , V_2 ) ;
F_165 ( & V_4 -> V_202 , F_129 ) ;
F_166 ( & V_4 -> V_199 ) ;
F_167 ( & V_4 -> V_201 ) ;
V_2 -> V_337 = & V_338 ;
V_2 -> V_352 = & V_352 ;
F_168 ( V_2 , & V_239 -> V_353 ) ;
V_2 -> V_354 = V_117 ;
memset ( & V_241 , 0 , sizeof( V_241 ) ) ;
V_241 . V_242 = V_242 ;
V_241 . V_20 = V_355 ;
V_9 = F_94 ( V_239 , & V_241 ) ;
if ( V_9 != 0 ) {
F_9 ( V_2 , L_16 , V_9 ) ;
F_169 ( V_2 ) ;
F_164 ( V_239 , NULL ) ;
return V_9 ;
}
memcpy ( V_2 -> V_287 , V_241 . V_356 , V_284 ) ;
V_2 -> V_206 = V_2 -> V_357 |
V_358 | V_359 |
V_360 | V_361 ;
V_2 -> V_362 = V_2 -> V_206 ;
V_6 = V_4 -> V_6 ;
F_95 ( V_2 , V_6 -> V_20 ) ;
F_96 ( V_2 , V_6 -> V_20 ) ;
V_2 -> V_363 = V_364 ;
if ( V_6 -> V_254 >= V_365 )
V_2 -> V_366 = V_367 - V_368 ;
else
V_2 -> V_366 = V_369 ;
V_9 = F_170 ( V_2 ) ;
if ( V_9 != 0 ) {
F_171 ( L_17 ) ;
F_99 ( V_239 , V_6 ) ;
F_169 ( V_2 ) ;
}
return V_9 ;
}
static int F_172 ( struct V_179 * V_239 )
{
struct V_1 * V_2 ;
struct V_3 * V_185 ;
V_2 = F_70 ( V_239 ) ;
if ( V_2 == NULL ) {
F_173 ( & V_239 -> V_353 , L_18 ) ;
return 0 ;
}
V_185 = F_2 ( V_2 ) ;
F_174 ( V_2 ) ;
F_175 ( & V_185 -> V_202 ) ;
F_131 () ;
F_99 ( V_239 , V_185 -> V_6 ) ;
F_139 () ;
F_176 ( V_2 ) ;
F_164 ( V_239 , NULL ) ;
F_169 ( V_2 ) ;
return 0 ;
}
static int F_177 ( struct V_370 * V_371 ,
unsigned long V_187 , void * V_372 )
{
struct V_1 * V_373 = F_178 ( V_372 ) ;
if ( V_373 -> V_337 == & V_338 )
return V_342 ;
if ( V_373 -> type != V_374 )
return V_342 ;
if ( F_179 ( V_373 ) )
return V_342 ;
if ( ( V_373 -> V_375 & V_376 ) &&
( V_373 -> V_188 & V_377 ) )
return V_342 ;
switch ( V_187 ) {
case V_378 :
return F_146 ( V_373 ) ;
case V_379 :
return F_155 ( V_373 ) ;
case V_380 :
return F_151 ( V_373 ) ;
case V_381 :
return F_154 ( V_373 ) ;
default:
return V_342 ;
}
}
static void T_8 F_180 ( void )
{
F_181 ( & V_382 ) ;
F_182 ( & V_383 ) ;
}
static int T_9 F_183 ( void )
{
int V_9 ;
if ( V_242 < V_384 ) {
V_242 = V_384 ;
F_184 ( L_19 ,
V_242 ) ;
}
V_9 = F_185 ( & V_383 ) ;
if ( V_9 )
return V_9 ;
F_186 ( & V_382 ) ;
return 0 ;
}
