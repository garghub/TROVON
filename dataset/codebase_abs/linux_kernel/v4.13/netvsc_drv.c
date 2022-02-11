static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 -> V_6 ) ;
F_4 ( V_6 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_7 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_7 -> V_6 ;
struct V_8 * V_9 ;
int V_10 = 0 ;
F_6 ( V_2 ) ;
V_10 = F_7 ( V_6 ) ;
if ( V_10 != 0 ) {
F_8 ( V_2 , L_1 , V_10 ) ;
return V_10 ;
}
F_9 ( V_2 ) ;
V_9 = V_6 -> V_11 ;
if ( ! V_9 -> V_12 && ! V_7 -> V_13 )
F_10 ( V_2 ) ;
return V_10 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 -> V_6 ) ;
int V_10 ;
T_1 V_14 , V_15 , V_16 = 10 , V_17 = 0 , V_18 = 20 ;
struct V_19 * V_20 ;
F_12 ( V_2 ) ;
V_10 = F_13 ( V_6 ) ;
if ( V_10 != 0 ) {
F_8 ( V_2 , L_2 , V_10 ) ;
return V_10 ;
}
while ( true ) {
V_14 = 0 ;
for ( V_15 = 0 ; V_15 < V_6 -> V_21 ; V_15 ++ ) {
V_20 = V_6 -> V_22 [ V_15 ] . V_23 ;
if ( ! V_20 )
continue;
V_14 = F_14 ( & V_20 -> V_24 ) ;
if ( V_14 )
break;
V_14 = F_14 ( & V_20 -> V_25 ) ;
if ( V_14 )
break;
}
V_17 ++ ;
if ( V_17 > V_18 || V_14 == 0 )
break;
F_15 ( V_16 ) ;
if ( V_16 < 1000 )
V_16 *= 2 ;
}
if ( V_14 ) {
F_8 ( V_2 , L_3 ) ;
V_10 = - V_26 ;
}
return V_10 ;
}
static void * F_16 ( struct V_27 * V_28 , T_1 V_29 ,
int V_30 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 ;
V_32 = & V_28 -> V_28 . V_35 ;
V_32 -> V_36 += V_29 ;
V_34 = (struct V_33 * ) ( ( void * ) V_32 +
V_32 -> V_37 + V_32 -> V_38 ) ;
V_34 -> V_39 = V_29 ;
V_34 -> type = V_30 ;
V_34 -> V_40 = sizeof( struct V_33 ) ;
V_32 -> V_38 += V_29 ;
return V_34 ;
}
static inline T_1 F_17 ( struct V_41 * V_42 , struct V_43 * V_44 )
{
struct V_45 V_46 ;
T_1 V_47 ;
static T_1 T_2 V_48 ;
F_18 ( & T_2 , sizeof( T_2 ) ) ;
if ( ! F_19 ( V_42 , & V_46 , 0 ) )
return 0 ;
if ( V_46 . V_49 . V_50 == V_51 ) {
return F_20 ( V_42 ) ;
} else {
if ( V_46 . V_49 . V_52 == F_21 ( V_53 ) )
V_47 = F_22 ( ( T_1 * ) & V_46 . V_54 . V_55 , 2 , T_2 ) ;
else if ( V_46 . V_49 . V_52 == F_21 ( V_56 ) )
V_47 = F_22 ( ( T_1 * ) & V_46 . V_54 . V_57 , 8 , T_2 ) ;
else
V_47 = 0 ;
F_23 ( V_42 , V_47 , V_58 ) ;
}
return V_47 ;
}
static inline int F_24 ( struct V_1 * V_59 ,
struct V_41 * V_42 , int V_60 )
{
const struct V_3 * V_61 = F_2 ( V_59 ) ;
struct V_43 * V_44 = V_42 -> V_44 ;
int V_62 ;
V_62 = V_61 -> V_63 [ F_17 ( V_42 , V_44 ) &
( V_64 - 1 ) ] ;
if ( V_62 != V_60 &&
V_44 && F_25 ( V_44 ) && F_26 ( V_44 -> V_65 ) )
F_27 ( V_44 , V_62 ) ;
return V_62 ;
}
static T_3 F_28 ( struct V_1 * V_59 , struct V_41 * V_42 ,
void * V_66 , T_4 V_67 )
{
unsigned int V_68 = V_59 -> V_69 ;
int V_62 = F_29 ( V_42 -> V_44 ) ;
if ( V_62 < 0 || V_42 -> V_70 ) {
if ( F_30 ( V_42 ) )
V_62 = F_31 ( V_42 ) ;
else
V_62 = F_24 ( V_59 , V_42 , V_62 ) ;
}
while ( F_32 ( V_62 >= V_68 ) )
V_62 -= V_68 ;
return V_62 ;
}
static T_1 F_33 ( struct V_71 * V_71 , T_1 V_72 , T_1 V_73 ,
struct V_74 * V_75 )
{
int V_76 = 0 ;
V_71 += ( V_72 >> V_77 ) ;
V_72 &= ~ V_78 ;
while ( V_73 > 0 ) {
unsigned long V_79 ;
V_79 = V_80 - V_72 ;
if ( V_79 > V_73 )
V_79 = V_73 ;
V_75 [ V_76 ] . V_81 = F_34 ( V_71 ) ;
V_75 [ V_76 ] . V_72 = V_72 ;
V_75 [ V_76 ] . V_73 = V_79 ;
V_72 += V_79 ;
V_73 -= V_79 ;
if ( V_72 == V_80 && V_73 ) {
V_71 ++ ;
V_72 = 0 ;
V_76 ++ ;
}
}
return V_76 + 1 ;
}
static T_1 F_35 ( void * V_82 , T_1 V_73 , struct V_41 * V_42 ,
struct V_83 * V_84 ,
struct V_74 * * V_85 )
{
struct V_74 * V_75 = * V_85 ;
T_1 V_86 = 0 ;
char * V_87 = V_42 -> V_87 ;
int V_88 = F_36 ( V_42 ) -> V_89 ;
int V_15 ;
if ( V_82 != NULL )
V_86 += F_33 ( F_37 ( V_82 ) ,
F_38 ( V_82 ) ,
V_73 , & V_75 [ V_86 ] ) ;
V_84 -> V_90 = V_73 ;
V_84 -> V_91 = V_86 ;
V_86 += F_33 ( F_37 ( V_87 ) ,
F_38 ( V_87 ) ,
F_39 ( V_42 ) , & V_75 [ V_86 ] ) ;
for ( V_15 = 0 ; V_15 < V_88 ; V_15 ++ ) {
T_5 * V_92 = F_36 ( V_42 ) -> V_88 + V_15 ;
V_86 += F_33 ( F_40 ( V_92 ) ,
V_92 -> V_93 ,
F_41 ( V_92 ) , & V_75 [ V_86 ] ) ;
}
return V_86 ;
}
static int F_42 ( struct V_41 * V_42 )
{
int V_15 , V_88 = F_36 ( V_42 ) -> V_89 ;
int V_94 = 0 ;
for ( V_15 = 0 ; V_15 < V_88 ; V_15 ++ ) {
T_5 * V_92 = F_36 ( V_42 ) -> V_88 + V_15 ;
unsigned long V_39 = F_41 ( V_92 ) ;
unsigned long V_72 = V_92 -> V_93 ;
V_72 &= ~ V_78 ;
V_94 += F_43 ( V_72 + V_39 ) ;
}
return V_94 ;
}
static int F_44 ( struct V_41 * V_42 )
{
char * V_87 = V_42 -> V_87 ;
unsigned int V_72 = F_38 ( V_87 ) ;
unsigned int V_73 = F_39 ( V_42 ) ;
int V_95 ;
int V_96 ;
V_95 = F_45 ( V_72 + V_73 , V_80 ) ;
V_96 = F_42 ( V_42 ) ;
return V_95 + V_96 ;
}
static T_1 F_46 ( struct V_41 * V_42 )
{
if ( V_42 -> V_97 == F_21 ( V_53 ) ) {
struct V_98 * V_99 = F_47 ( V_42 ) ;
if ( V_99 -> V_97 == V_51 )
return V_100 ;
else if ( V_99 -> V_97 == V_101 )
return V_102 ;
} else {
struct V_103 * V_104 = F_48 ( V_42 ) ;
if ( V_104 -> V_105 == V_51 )
return V_106 ;
else if ( F_48 ( V_42 ) -> V_105 == V_101 )
return V_107 ;
}
return V_108 ;
}
static int F_49 ( struct V_41 * V_42 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_83 * V_84 = NULL ;
int V_10 ;
unsigned int V_109 ;
struct V_27 * V_110 ;
struct V_31 * V_32 ;
T_1 V_111 ;
struct V_33 * V_34 ;
T_1 V_47 ;
struct V_74 V_85 [ V_112 ] ;
struct V_74 * V_75 = V_85 ;
V_109 = F_44 ( V_42 ) + 2 ;
if ( F_32 ( V_109 > V_112 ) ) {
++ V_4 -> V_113 . V_114 ;
if ( F_50 ( V_42 ) )
goto V_115;
V_109 = F_44 ( V_42 ) + 2 ;
if ( V_109 > V_112 ) {
++ V_4 -> V_113 . V_116 ;
goto V_117;
}
}
V_10 = F_51 ( V_42 , V_118 ) ;
if ( V_10 )
goto V_115;
F_52 ( sizeof( struct V_83 ) >
F_53 ( struct V_41 , V_119 ) ) ;
V_84 = (struct V_83 * ) V_42 -> V_119 ;
V_84 -> V_62 = F_54 ( V_42 ) ;
V_84 -> V_120 = V_42 -> V_73 ;
V_84 -> V_121 = V_42 -> V_73 ;
V_84 -> V_122 = 1 ;
V_110 = (struct V_27 * ) V_42 -> V_123 ;
memset ( V_110 , 0 , V_118 ) ;
V_110 -> V_124 = V_125 ;
V_110 -> V_126 = V_84 -> V_120 ;
V_32 = & V_110 -> V_28 . V_35 ;
V_32 -> V_36 = sizeof( struct V_31 ) ;
V_32 -> V_127 = V_84 -> V_120 ;
V_32 -> V_37 = sizeof( struct V_31 ) ;
V_111 = F_55 ( struct V_31 ) ;
V_47 = F_56 ( V_42 ) ;
if ( V_47 != 0 && V_2 -> V_69 > 1 ) {
V_111 += V_128 ;
V_34 = F_16 ( V_110 , V_128 ,
V_129 ) ;
* ( T_1 * ) ( ( void * ) V_34 + V_34 -> V_40 ) = V_47 ;
}
if ( F_57 ( V_42 ) ) {
struct V_130 * V_131 ;
V_111 += V_132 ;
V_34 = F_16 ( V_110 , V_132 ,
V_133 ) ;
V_131 = (struct V_130 * ) ( ( void * ) V_34 +
V_34 -> V_40 ) ;
V_131 -> V_134 = V_42 -> V_135 & V_136 ;
V_131 -> V_137 = ( V_42 -> V_135 & V_138 ) >>
V_139 ;
}
if ( F_58 ( V_42 ) ) {
struct V_140 * V_141 ;
V_111 += V_142 ;
V_34 = F_16 ( V_110 , V_142 ,
V_143 ) ;
V_141 = (struct V_140 * ) ( ( void * ) V_34 +
V_34 -> V_40 ) ;
V_141 -> V_144 . type = V_145 ;
if ( V_42 -> V_97 == F_21 ( V_53 ) ) {
V_141 -> V_144 . V_146 =
V_147 ;
F_47 ( V_42 ) -> V_148 = 0 ;
F_47 ( V_42 ) -> V_149 = 0 ;
F_59 ( V_42 ) -> V_149 =
~ F_60 ( F_47 ( V_42 ) -> V_150 ,
F_47 ( V_42 ) -> V_151 , 0 , V_51 , 0 ) ;
} else {
V_141 -> V_144 . V_146 =
V_152 ;
F_48 ( V_42 ) -> V_153 = 0 ;
F_59 ( V_42 ) -> V_149 =
~ F_61 ( & F_48 ( V_42 ) -> V_150 ,
& F_48 ( V_42 ) -> V_151 , 0 , V_51 , 0 ) ;
}
V_141 -> V_144 . V_154 = F_62 ( V_42 ) ;
V_141 -> V_144 . V_155 = F_36 ( V_42 ) -> V_156 ;
} else if ( V_42 -> V_157 == V_158 ) {
if ( F_46 ( V_42 ) & V_4 -> V_159 ) {
struct V_160 * V_161 ;
V_111 += V_162 ;
V_34 = F_16 ( V_110 , V_162 ,
V_163 ) ;
V_161 = (struct V_160 * ) ( ( void * ) V_34 +
V_34 -> V_40 ) ;
V_161 -> V_164 . V_154 = F_62 ( V_42 ) ;
if ( V_42 -> V_97 == F_21 ( V_53 ) ) {
V_161 -> V_164 . V_165 = 1 ;
if ( F_47 ( V_42 ) -> V_97 == V_51 )
V_161 -> V_164 . V_166 = 1 ;
else
V_161 -> V_164 . V_167 = 1 ;
} else {
V_161 -> V_164 . V_168 = 1 ;
if ( F_48 ( V_42 ) -> V_105 == V_51 )
V_161 -> V_164 . V_166 = 1 ;
else
V_161 -> V_164 . V_167 = 1 ;
}
} else {
if ( F_63 ( V_42 ) )
goto V_117;
}
}
V_110 -> V_126 += V_111 ;
V_84 -> V_120 = V_110 -> V_126 ;
V_84 -> V_169 = F_35 ( V_110 , V_111 ,
V_42 , V_84 , & V_75 ) ;
F_64 ( V_42 ) ;
V_10 = F_65 ( V_4 -> V_170 , V_84 ,
V_110 , & V_75 , V_42 ) ;
if ( F_66 ( V_10 == 0 ) )
return V_171 ;
if ( V_10 == - V_172 ) {
++ V_4 -> V_113 . V_173 ;
return V_174 ;
}
if ( V_10 == - V_175 )
++ V_4 -> V_113 . V_176 ;
V_117:
F_67 ( V_42 ) ;
V_2 -> V_177 . V_178 ++ ;
return V_171 ;
V_115:
++ V_4 -> V_113 . V_179 ;
goto V_117;
}
void F_68 ( struct V_180 * V_181 ,
struct V_27 * V_182 )
{
struct V_183 * V_184 = & V_182 -> V_28 . V_185 ;
struct V_1 * V_2 ;
struct V_3 * V_7 ;
struct V_186 * V_187 ;
unsigned long V_188 ;
V_2 = F_69 ( V_181 ) ;
if ( ! V_2 )
return;
V_7 = F_2 ( V_2 ) ;
if ( V_184 -> V_189 == V_190 ) {
T_1 V_191 ;
V_191 = * ( T_1 * ) ( ( void * ) V_184 + V_184 ->
V_192 ) / 10000 ;
V_7 -> V_191 = V_191 ;
return;
}
if ( V_184 -> V_189 != V_193 &&
V_184 -> V_189 != V_194 &&
V_184 -> V_189 != V_195 )
return;
if ( V_2 -> V_196 != V_197 )
return;
V_187 = F_70 ( sizeof( * V_187 ) , V_198 ) ;
if ( ! V_187 )
return;
V_187 -> V_187 = V_184 -> V_189 ;
F_71 ( & V_7 -> V_199 , V_188 ) ;
F_72 ( & V_187 -> V_200 , & V_7 -> V_201 ) ;
F_73 ( & V_7 -> V_199 , V_188 ) ;
F_74 ( & V_7 -> V_202 , 0 ) ;
}
static struct V_41 * F_75 ( struct V_1 * V_2 ,
struct V_203 * V_204 ,
const struct V_160 * V_161 ,
const struct V_130 * V_131 ,
void * V_87 , T_1 V_205 )
{
struct V_41 * V_42 ;
V_42 = F_76 ( V_204 , V_205 ) ;
if ( ! V_42 )
return V_42 ;
F_77 ( V_42 , V_87 , V_205 ) ;
V_42 -> V_97 = F_78 ( V_42 , V_2 ) ;
F_79 ( V_42 ) ;
if ( V_161 && ( V_2 -> V_206 & V_207 ) ) {
if ( V_161 -> V_208 . V_209 ||
V_161 -> V_208 . V_210 )
V_42 -> V_157 = V_211 ;
}
if ( V_131 ) {
T_3 V_135 = V_131 -> V_134 | ( V_131 -> V_137 << V_139 ) ;
F_80 ( V_42 , F_21 ( V_212 ) ,
V_135 ) ;
}
return V_42 ;
}
int F_81 ( struct V_1 * V_2 ,
struct V_19 * V_23 ,
void * V_87 , T_1 V_73 ,
const struct V_160 * V_161 ,
const struct V_130 * V_131 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_1 ;
T_3 V_62 = V_23 -> V_213 . V_214 . V_215 ;
struct V_216 * V_217 ;
struct V_1 * V_218 ;
struct V_41 * V_42 ;
struct V_219 * V_220 ;
if ( V_2 -> V_196 != V_197 )
return V_221 ;
F_82 () ;
V_1 = F_83 ( V_4 -> V_6 ) ;
if ( F_32 ( ! V_1 ) )
goto V_117;
V_217 = & V_1 -> V_22 [ V_62 ] ;
V_218 = F_83 ( V_4 -> V_218 ) ;
if ( V_218 && ( V_218 -> V_188 & V_222 ) )
V_2 = V_218 ;
V_42 = F_75 ( V_2 , & V_217 -> V_204 ,
V_161 , V_131 , V_87 , V_73 ) ;
if ( F_32 ( ! V_42 ) ) {
V_117:
++ V_2 -> V_177 . V_223 ;
F_84 () ;
return V_221 ;
}
if ( V_2 != V_218 )
F_85 ( V_42 , V_62 ) ;
V_220 = & V_217 -> V_220 ;
F_86 ( & V_220 -> V_224 ) ;
V_220 -> V_225 ++ ;
V_220 -> V_79 += V_73 ;
if ( V_42 -> V_30 == V_226 )
++ V_220 -> V_227 ;
else if ( V_42 -> V_30 == V_228 )
++ V_220 -> V_229 ;
F_87 ( & V_220 -> V_224 ) ;
F_88 ( & V_217 -> V_204 , V_42 ) ;
F_84 () ;
return 0 ;
}
static void F_89 ( struct V_1 * V_2 ,
struct V_230 * V_231 )
{
F_90 ( V_231 -> V_232 , V_233 , sizeof( V_231 -> V_232 ) ) ;
F_90 ( V_231 -> V_234 , L_4 , sizeof( V_231 -> V_234 ) ) ;
}
static void F_91 ( struct V_1 * V_2 ,
struct V_235 * V_23 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 -> V_6 ) ;
if ( V_6 ) {
V_23 -> V_236 = V_6 -> V_237 ;
V_23 -> V_238 = V_6 -> V_21 ;
}
}
static int F_92 ( struct V_1 * V_2 , struct V_180 * V_239 ,
T_1 V_21 )
{
struct V_240 V_241 ;
int V_10 ;
memset ( & V_241 , 0 , sizeof( V_241 ) ) ;
V_241 . V_21 = V_21 ;
V_241 . V_242 = V_242 ;
V_241 . V_243 = V_21 ;
V_10 = F_93 ( V_239 , & V_241 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_94 ( V_2 , V_21 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_95 ( V_2 , V_21 ) ;
return V_10 ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_235 * V_244 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_180 * V_239 = V_4 -> V_170 ;
struct V_5 * V_6 = F_3 ( V_4 -> V_6 ) ;
unsigned int V_245 = V_244 -> V_238 ;
bool V_246 ;
int V_10 ;
if ( V_245 == 0 ||
V_244 -> V_247 || V_244 -> V_248 || V_244 -> V_249 )
return - V_250 ;
if ( V_245 > V_2 -> V_68 || V_245 > V_251 )
return - V_250 ;
if ( ! V_6 || V_6 -> V_252 )
return - V_253 ;
if ( V_6 -> V_254 < V_255 )
return - V_250 ;
if ( V_245 > V_6 -> V_237 )
return - V_250 ;
V_246 = F_97 ( V_2 ) ;
if ( V_246 ) {
V_10 = F_11 ( V_2 ) ;
if ( V_10 )
return V_10 ;
}
F_98 ( V_239 , V_6 ) ;
V_10 = F_92 ( V_2 , V_239 , V_245 ) ;
if ( V_10 == 0 )
V_6 -> V_21 = V_245 ;
else
F_92 ( V_2 , V_239 , V_6 -> V_21 ) ;
if ( V_246 )
V_10 = F_5 ( V_2 ) ;
F_74 ( & V_4 -> V_202 , 0 ) ;
return V_10 ;
}
static bool
F_99 ( const struct V_256 * V_257 )
{
struct V_256 V_258 = * V_257 ;
struct V_256 V_259 = {} ;
V_258 . V_260 . V_191 = 0 ;
V_258 . V_260 . V_261 = 0 ;
F_100 ( & V_258 , V_262 ) ;
V_258 . V_260 . V_257 = 0 ;
V_259 . V_260 . V_263 = V_264 ;
return ! memcmp ( & V_258 , & V_259 , sizeof( V_258 ) ) ;
}
static void F_101 ( struct V_1 * V_239 )
{
struct V_3 * V_61 = F_2 ( V_239 ) ;
V_61 -> V_191 = V_265 ;
V_61 -> V_261 = V_266 ;
}
static int F_102 ( struct V_1 * V_239 ,
struct V_256 * V_257 )
{
struct V_3 * V_61 = F_2 ( V_239 ) ;
V_257 -> V_260 . V_191 = V_61 -> V_191 ;
V_257 -> V_260 . V_261 = V_61 -> V_261 ;
V_257 -> V_260 . V_263 = V_264 ;
return 0 ;
}
static int F_103 ( struct V_1 * V_239 ,
const struct V_256 * V_257 )
{
struct V_3 * V_61 = F_2 ( V_239 ) ;
T_1 V_191 ;
V_191 = V_257 -> V_260 . V_191 ;
if ( ! F_104 ( V_191 ) ||
! F_105 ( V_257 -> V_260 . V_261 ) ||
! F_99 ( V_257 ) )
return - V_250 ;
V_61 -> V_191 = V_191 ;
V_61 -> V_261 = V_257 -> V_260 . V_261 ;
return 0 ;
}
static int F_106 ( struct V_1 * V_59 , int V_267 )
{
struct V_3 * V_268 = F_2 ( V_59 ) ;
struct V_5 * V_6 = F_3 ( V_268 -> V_6 ) ;
struct V_180 * V_269 = V_268 -> V_170 ;
struct V_240 V_241 ;
bool V_246 ;
int V_10 = 0 ;
if ( ! V_6 || V_6 -> V_252 )
return - V_253 ;
V_246 = F_97 ( V_59 ) ;
if ( V_246 ) {
V_10 = F_11 ( V_59 ) ;
if ( V_10 )
return V_10 ;
}
memset ( & V_241 , 0 , sizeof( V_241 ) ) ;
V_241 . V_242 = V_242 ;
V_241 . V_21 = V_6 -> V_21 ;
V_241 . V_243 = V_6 -> V_21 ;
F_98 ( V_269 , V_6 ) ;
V_59 -> V_267 = V_267 ;
F_93 ( V_269 , & V_241 ) ;
if ( V_246 )
V_10 = F_5 ( V_59 ) ;
F_74 ( & V_268 -> V_202 , 0 ) ;
return V_10 ;
}
static void F_107 ( struct V_1 * V_2 ,
struct V_270 * V_271 )
{
struct V_3 * V_7 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_108 ( V_7 -> V_6 ) ;
int V_15 ;
if ( ! V_6 )
return;
for ( V_15 = 0 ; V_15 < V_6 -> V_21 ; V_15 ++ ) {
const struct V_216 * V_217 = & V_6 -> V_22 [ V_15 ] ;
const struct V_219 * V_177 ;
T_6 V_225 , V_79 , V_229 ;
unsigned int V_272 ;
V_177 = & V_217 -> V_273 ;
do {
V_272 = F_109 ( & V_177 -> V_224 ) ;
V_225 = V_177 -> V_225 ;
V_79 = V_177 -> V_79 ;
} while ( F_110 ( & V_177 -> V_224 , V_272 ) );
V_271 -> V_274 += V_79 ;
V_271 -> V_275 += V_225 ;
V_177 = & V_217 -> V_220 ;
do {
V_272 = F_109 ( & V_177 -> V_224 ) ;
V_225 = V_177 -> V_225 ;
V_79 = V_177 -> V_79 ;
V_229 = V_177 -> V_229 + V_177 -> V_227 ;
} while ( F_110 ( & V_177 -> V_224 , V_272 ) );
V_271 -> V_276 += V_79 ;
V_271 -> V_277 += V_225 ;
V_271 -> V_229 += V_229 ;
}
V_271 -> V_178 = V_2 -> V_177 . V_178 ;
V_271 -> V_278 = V_2 -> V_177 . V_278 ;
V_271 -> V_223 = V_2 -> V_177 . V_223 ;
V_271 -> V_279 = V_2 -> V_177 . V_279 ;
}
static int F_111 ( struct V_1 * V_59 , void * V_280 )
{
struct V_281 * V_282 = V_280 ;
char V_283 [ V_284 ] ;
unsigned char V_285 ;
int V_286 ;
memcpy ( V_283 , V_59 -> V_287 , V_284 ) ;
V_285 = V_59 -> V_288 ;
V_286 = F_112 ( V_59 , V_280 ) ;
if ( V_286 != 0 )
return V_286 ;
V_286 = F_113 ( V_59 , V_282 -> V_289 ) ;
if ( V_286 != 0 ) {
memcpy ( V_59 -> V_287 , V_283 , V_284 ) ;
V_59 -> V_288 = V_285 ;
}
return V_286 ;
}
static int F_114 ( struct V_1 * V_239 , int V_290 )
{
struct V_3 * V_61 = F_2 ( V_239 ) ;
struct V_5 * V_6 = F_3 ( V_61 -> V_6 ) ;
if ( ! V_6 )
return - V_253 ;
switch ( V_290 ) {
case V_291 :
return V_292 + F_115 ( V_6 ) ;
default:
return - V_250 ;
}
}
static void F_116 ( struct V_1 * V_239 ,
struct V_293 * V_177 , T_6 * V_87 )
{
struct V_3 * V_61 = F_2 ( V_239 ) ;
struct V_5 * V_6 = F_83 ( V_61 -> V_6 ) ;
const void * V_294 = & V_61 -> V_113 ;
const struct V_219 * V_295 ;
unsigned int V_272 ;
T_6 V_225 , V_79 ;
int V_15 , V_76 ;
if ( ! V_6 )
return;
for ( V_15 = 0 ; V_15 < V_292 ; V_15 ++ )
V_87 [ V_15 ] = * ( unsigned long * ) ( V_294 + V_219 [ V_15 ] . V_72 ) ;
for ( V_76 = 0 ; V_76 < V_6 -> V_21 ; V_76 ++ ) {
V_295 = & V_6 -> V_22 [ V_76 ] . V_273 ;
do {
V_272 = F_109 ( & V_295 -> V_224 ) ;
V_225 = V_295 -> V_225 ;
V_79 = V_295 -> V_79 ;
} while ( F_110 ( & V_295 -> V_224 , V_272 ) );
V_87 [ V_15 ++ ] = V_225 ;
V_87 [ V_15 ++ ] = V_79 ;
V_295 = & V_6 -> V_22 [ V_76 ] . V_220 ;
do {
V_272 = F_109 ( & V_295 -> V_224 ) ;
V_225 = V_295 -> V_225 ;
V_79 = V_295 -> V_79 ;
} while ( F_110 ( & V_295 -> V_224 , V_272 ) );
V_87 [ V_15 ++ ] = V_225 ;
V_87 [ V_15 ++ ] = V_79 ;
}
}
static void F_117 ( struct V_1 * V_239 , T_1 V_296 , T_7 * V_87 )
{
struct V_3 * V_61 = F_2 ( V_239 ) ;
struct V_5 * V_6 = F_83 ( V_61 -> V_6 ) ;
T_7 * V_280 = V_87 ;
int V_15 ;
if ( ! V_6 )
return;
switch ( V_296 ) {
case V_291 :
for ( V_15 = 0 ; V_15 < F_118 ( V_219 ) ; V_15 ++ )
memcpy ( V_280 + V_15 * V_297 ,
V_219 [ V_15 ] . V_298 , V_297 ) ;
V_280 += V_15 * V_297 ;
for ( V_15 = 0 ; V_15 < V_6 -> V_21 ; V_15 ++ ) {
sprintf ( V_280 , L_5 , V_15 ) ;
V_280 += V_297 ;
sprintf ( V_280 , L_6 , V_15 ) ;
V_280 += V_297 ;
sprintf ( V_280 , L_7 , V_15 ) ;
V_280 += V_297 ;
sprintf ( V_280 , L_8 , V_15 ) ;
V_280 += V_297 ;
}
break;
}
}
static int
F_119 ( struct V_5 * V_6 ,
struct V_299 * V_231 )
{
V_231 -> V_87 = V_300 | V_301 ;
switch ( V_231 -> V_302 ) {
case V_303 :
case V_304 :
V_231 -> V_87 |= V_305 | V_306 ;
case V_307 :
case V_308 :
case V_309 :
case V_310 :
break;
default:
V_231 -> V_87 = 0 ;
break;
}
return 0 ;
}
static int
F_120 ( struct V_1 * V_239 , struct V_299 * V_231 ,
T_1 * V_311 )
{
struct V_3 * V_61 = F_2 ( V_239 ) ;
struct V_5 * V_6 = F_83 ( V_61 -> V_6 ) ;
if ( ! V_6 )
return - V_253 ;
switch ( V_231 -> V_257 ) {
case V_312 :
V_231 -> V_87 = V_6 -> V_21 ;
return 0 ;
case V_313 :
return F_119 ( V_6 , V_231 ) ;
}
return - V_314 ;
}
static void F_121 ( struct V_1 * V_239 )
{
struct V_3 * V_61 = F_2 ( V_239 ) ;
struct V_5 * V_59 ;
int V_15 ;
F_82 () ;
V_59 = F_83 ( V_61 -> V_6 ) ;
if ( V_59 ) {
for ( V_15 = 0 ; V_15 < V_59 -> V_21 ; V_15 ++ ) {
struct V_216 * V_217 = & V_59 -> V_22 [ V_15 ] ;
F_122 ( & V_217 -> V_204 ) ;
}
}
F_84 () ;
}
static T_1 F_123 ( struct V_1 * V_239 )
{
return V_315 ;
}
static T_1 F_124 ( struct V_1 * V_239 )
{
return V_316 ;
}
static int F_125 ( struct V_1 * V_239 , T_1 * V_317 , T_7 * V_318 ,
T_7 * V_319 )
{
struct V_3 * V_61 = F_2 ( V_239 ) ;
struct V_5 * V_59 = F_83 ( V_61 -> V_6 ) ;
struct V_8 * V_320 ;
int V_15 ;
if ( ! V_59 )
return - V_253 ;
if ( V_319 )
* V_319 = V_321 ;
V_320 = V_59 -> V_11 ;
if ( V_317 ) {
for ( V_15 = 0 ; V_15 < V_316 ; V_15 ++ )
V_317 [ V_15 ] = V_320 -> V_322 [ V_15 ] ;
}
if ( V_318 )
memcpy ( V_318 , V_320 -> V_323 , V_315 ) ;
return 0 ;
}
static int F_126 ( struct V_1 * V_239 , const T_1 * V_317 ,
const T_7 * V_318 , const T_7 V_319 )
{
struct V_3 * V_61 = F_2 ( V_239 ) ;
struct V_5 * V_59 = F_3 ( V_61 -> V_6 ) ;
struct V_8 * V_320 ;
int V_15 ;
if ( ! V_59 )
return - V_253 ;
if ( V_319 != V_324 && V_319 != V_321 )
return - V_314 ;
V_320 = V_59 -> V_11 ;
if ( V_317 ) {
for ( V_15 = 0 ; V_15 < V_316 ; V_15 ++ )
if ( V_317 [ V_15 ] >= V_251 )
return - V_250 ;
for ( V_15 = 0 ; V_15 < V_316 ; V_15 ++ )
V_320 -> V_322 [ V_15 ] = V_317 [ V_15 ] ;
}
if ( ! V_318 ) {
if ( ! V_317 )
return 0 ;
V_318 = V_320 -> V_323 ;
}
return F_127 ( V_320 , V_318 , V_59 -> V_21 ) ;
}
static void F_128 ( struct V_325 * V_326 )
{
struct V_3 * V_7 =
F_129 ( V_326 , struct V_3 , V_202 . V_327 ) ;
struct V_180 * V_181 = V_7 -> V_170 ;
struct V_1 * V_2 = F_69 ( V_181 ) ;
struct V_5 * V_1 ;
struct V_8 * V_9 ;
struct V_186 * V_187 = NULL ;
bool V_328 = false , V_329 = false ;
unsigned long V_188 , V_330 , V_331 ;
if ( ! F_130 () ) {
F_74 ( & V_7 -> V_202 , V_332 ) ;
return;
}
V_1 = F_3 ( V_7 -> V_6 ) ;
if ( ! V_1 )
goto V_333;
V_9 = V_1 -> V_11 ;
V_330 = V_7 -> V_334 + V_332 ;
if ( F_131 ( V_330 ) ) {
V_331 = V_330 - V_335 ;
V_331 = V_331 < V_332 ? V_331 : V_332 ;
F_74 ( & V_7 -> V_202 , V_331 ) ;
goto V_333;
}
V_7 -> V_334 = V_335 ;
F_71 ( & V_7 -> V_199 , V_188 ) ;
if ( ! F_132 ( & V_7 -> V_201 ) ) {
V_187 = F_133 ( & V_7 -> V_201 ,
struct V_186 , V_200 ) ;
F_134 ( & V_187 -> V_200 ) ;
V_329 = ! F_132 ( & V_7 -> V_201 ) ;
}
F_73 ( & V_7 -> V_199 , V_188 ) ;
if ( ! V_187 )
goto V_333;
switch ( V_187 -> V_187 ) {
case V_194 :
if ( V_9 -> V_12 ) {
V_9 -> V_12 = false ;
if ( ! V_7 -> V_13 )
F_10 ( V_2 ) ;
F_9 ( V_2 ) ;
} else {
V_328 = true ;
}
F_135 ( V_187 ) ;
break;
case V_195 :
if ( ! V_9 -> V_12 ) {
V_9 -> V_12 = true ;
F_6 ( V_2 ) ;
F_136 ( V_2 ) ;
}
F_135 ( V_187 ) ;
break;
case V_193 :
if ( ! V_9 -> V_12 ) {
V_9 -> V_12 = true ;
F_6 ( V_2 ) ;
F_136 ( V_2 ) ;
V_187 -> V_187 = V_194 ;
F_71 ( & V_7 -> V_199 , V_188 ) ;
F_137 ( & V_187 -> V_200 , & V_7 -> V_201 ) ;
F_73 ( & V_7 -> V_199 , V_188 ) ;
V_329 = true ;
}
break;
}
F_138 () ;
if ( V_328 )
F_139 ( V_2 ) ;
if ( V_329 )
F_74 ( & V_7 -> V_202 , V_332 ) ;
return;
V_333:
F_138 () ;
}
static struct V_1 * F_140 ( const T_7 * V_336 )
{
struct V_1 * V_239 ;
F_141 () ;
F_142 (&init_net, dev) {
if ( V_239 -> V_337 != & V_338 )
continue;
if ( F_143 ( V_336 , V_239 -> V_339 ) )
return V_239 ;
}
return NULL ;
}
static struct V_1 * F_144 ( struct V_1 * V_218 )
{
struct V_1 * V_239 ;
F_141 () ;
F_142 (&init_net, dev) {
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
static int F_145 ( struct V_1 * V_218 )
{
struct V_1 * V_59 ;
struct V_3 * V_4 ;
struct V_5 * V_340 ;
if ( V_218 -> V_341 != V_284 )
return V_342 ;
V_59 = F_140 ( V_218 -> V_339 ) ;
if ( ! V_59 )
return V_342 ;
V_4 = F_2 ( V_59 ) ;
V_340 = F_3 ( V_4 -> V_6 ) ;
if ( ! V_340 || F_3 ( V_4 -> V_218 ) )
return V_342 ;
F_146 ( V_59 , L_9 , V_218 -> V_298 ) ;
F_147 ( V_343 ) ;
F_148 ( V_218 ) ;
F_149 ( V_4 -> V_218 , V_218 ) ;
return V_344 ;
}
static int F_150 ( struct V_1 * V_218 )
{
struct V_1 * V_59 ;
struct V_5 * V_340 ;
struct V_3 * V_4 ;
V_59 = F_144 ( V_218 ) ;
if ( ! V_59 )
return V_342 ;
V_4 = F_2 ( V_59 ) ;
V_340 = F_3 ( V_4 -> V_6 ) ;
F_146 ( V_59 , L_10 , V_218 -> V_298 ) ;
F_7 ( V_340 ) ;
F_151 ( V_59 , true ) ;
F_146 ( V_59 , L_11 , V_218 -> V_298 ) ;
F_6 ( V_59 ) ;
F_152 ( V_345 , V_218 ) ;
return V_344 ;
}
static int F_153 ( struct V_1 * V_218 )
{
struct V_1 * V_59 ;
struct V_5 * V_340 ;
struct V_3 * V_4 ;
V_59 = F_144 ( V_218 ) ;
if ( ! V_59 )
return V_342 ;
V_4 = F_2 ( V_59 ) ;
V_340 = F_3 ( V_4 -> V_6 ) ;
F_146 ( V_59 , L_12 , V_218 -> V_298 ) ;
F_151 ( V_59 , false ) ;
F_146 ( V_59 , L_13 , V_218 -> V_298 ) ;
F_13 ( V_340 ) ;
F_10 ( V_59 ) ;
F_152 ( V_345 , V_59 ) ;
return V_344 ;
}
static int F_154 ( struct V_1 * V_218 )
{
struct V_1 * V_59 ;
struct V_3 * V_4 ;
V_59 = F_144 ( V_218 ) ;
if ( ! V_59 )
return V_342 ;
V_4 = F_2 ( V_59 ) ;
F_146 ( V_59 , L_14 , V_218 -> V_298 ) ;
F_155 ( V_4 -> V_218 , NULL ) ;
F_156 ( V_218 ) ;
F_157 ( V_343 ) ;
return V_344 ;
}
static int F_158 ( struct V_180 * V_239 ,
const struct V_346 * V_347 )
{
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
struct V_240 V_241 ;
struct V_5 * V_6 ;
int V_10 ;
V_2 = F_159 ( sizeof( struct V_3 ) ,
V_251 ) ;
if ( ! V_2 )
return - V_348 ;
F_6 ( V_2 ) ;
F_101 ( V_2 ) ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_170 = V_239 ;
V_4 -> V_349 = F_160 ( V_350 , V_351 ) ;
if ( F_161 ( V_4 ) )
F_162 ( V_2 , L_15 ,
V_4 -> V_349 ) ;
F_163 ( V_239 , V_2 ) ;
F_164 ( & V_4 -> V_202 , F_128 ) ;
F_165 ( & V_4 -> V_199 ) ;
F_166 ( & V_4 -> V_201 ) ;
V_2 -> V_337 = & V_338 ;
V_2 -> V_352 = & V_352 ;
F_167 ( V_2 , & V_239 -> V_353 ) ;
V_2 -> V_354 = V_118 ;
memset ( & V_241 , 0 , sizeof( V_241 ) ) ;
V_241 . V_242 = V_242 ;
V_241 . V_21 = V_355 ;
V_10 = F_93 ( V_239 , & V_241 ) ;
if ( V_10 != 0 ) {
F_8 ( V_2 , L_16 , V_10 ) ;
F_168 ( V_2 ) ;
F_163 ( V_239 , NULL ) ;
return V_10 ;
}
memcpy ( V_2 -> V_287 , V_241 . V_356 , V_284 ) ;
V_2 -> V_206 = V_2 -> V_357 |
V_358 | V_359 |
V_360 | V_361 ;
V_2 -> V_362 = V_2 -> V_206 ;
V_6 = V_4 -> V_6 ;
F_94 ( V_2 , V_6 -> V_21 ) ;
F_95 ( V_2 , V_6 -> V_21 ) ;
V_2 -> V_363 = V_364 ;
if ( V_6 -> V_254 >= V_365 )
V_2 -> V_366 = V_367 - V_368 ;
else
V_2 -> V_366 = V_369 ;
V_10 = F_169 ( V_2 ) ;
if ( V_10 != 0 ) {
F_170 ( L_17 ) ;
F_98 ( V_239 , V_6 ) ;
F_168 ( V_2 ) ;
}
return V_10 ;
}
static int F_171 ( struct V_180 * V_239 )
{
struct V_1 * V_2 ;
struct V_3 * V_7 ;
V_2 = F_69 ( V_239 ) ;
if ( V_2 == NULL ) {
F_172 ( & V_239 -> V_353 , L_18 ) ;
return 0 ;
}
V_7 = F_2 ( V_2 ) ;
F_173 ( V_2 ) ;
F_174 ( & V_7 -> V_202 ) ;
F_175 () ;
F_98 ( V_239 , V_7 -> V_6 ) ;
F_138 () ;
F_176 ( V_2 ) ;
F_163 ( V_239 , NULL ) ;
F_168 ( V_2 ) ;
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
return F_145 ( V_373 ) ;
case V_379 :
return F_154 ( V_373 ) ;
case V_380 :
return F_150 ( V_373 ) ;
case V_381 :
return F_153 ( V_373 ) ;
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
int V_10 ;
if ( V_242 < V_384 ) {
V_242 = V_384 ;
F_184 ( L_19 ,
V_242 ) ;
}
V_10 = F_185 ( & V_383 ) ;
if ( V_10 )
return V_10 ;
F_186 ( & V_382 ) ;
return 0 ;
}
