static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_5 ) ;
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
struct V_11 * V_12 = V_4 -> V_12 ;
struct V_13 * V_14 ;
if ( ! V_12 )
return;
V_14 = V_12 -> V_15 ;
if ( V_14 == NULL )
return;
if ( V_10 -> V_16 & V_17 )
F_4 ( V_14 ,
V_18 ) ;
else
F_4 ( V_14 ,
V_19 |
V_20 |
V_21 ) ;
}
static void F_5 ( struct V_9 * V_22 )
{
struct V_3 * V_23 = F_6 ( V_22 ) ;
F_7 ( & V_23 -> V_5 ) ;
}
static int F_8 ( struct V_9 * V_22 )
{
struct V_11 * V_12 = F_9 ( V_22 ) ;
struct V_13 * V_14 ;
int V_24 = 0 ;
F_10 ( V_22 ) ;
V_24 = F_11 ( V_12 ) ;
if ( V_24 != 0 ) {
F_12 ( V_22 , L_1 , V_24 ) ;
return V_24 ;
}
F_13 ( V_22 ) ;
V_14 = V_12 -> V_15 ;
if ( ! V_14 -> V_25 )
F_14 ( V_22 ) ;
return V_24 ;
}
static int F_15 ( struct V_9 * V_22 )
{
struct V_3 * V_23 = F_6 ( V_22 ) ;
struct V_11 * V_12 = V_23 -> V_12 ;
int V_24 ;
T_1 V_26 , V_27 , V_28 , V_29 = 10 , V_30 = 0 , V_31 = 20 ;
struct V_32 * V_33 ;
F_16 ( V_22 ) ;
F_17 ( & V_23 -> V_5 ) ;
V_24 = F_18 ( V_12 ) ;
if ( V_24 != 0 ) {
F_12 ( V_22 , L_2 , V_24 ) ;
return V_24 ;
}
while ( true ) {
V_26 = 0 ;
for ( V_28 = 0 ; V_28 < V_12 -> V_34 ; V_28 ++ ) {
V_33 = V_12 -> V_35 [ V_28 ] . V_36 ;
if ( ! V_33 )
continue;
F_19 ( & V_33 -> V_37 , & V_26 ,
& V_27 ) ;
if ( V_26 )
break;
F_19 ( & V_33 -> V_38 , & V_26 ,
& V_27 ) ;
if ( V_26 )
break;
}
V_30 ++ ;
if ( V_30 > V_31 || V_26 == 0 )
break;
F_20 ( V_29 ) ;
if ( V_29 < 1000 )
V_29 *= 2 ;
}
if ( V_26 ) {
F_12 ( V_22 , L_3 ) ;
V_24 = - V_39 ;
}
return V_24 ;
}
static void * F_21 ( struct V_40 * V_41 , T_1 V_42 ,
int V_43 )
{
struct V_44 * V_45 ;
struct V_46 * V_47 ;
V_45 = & V_41 -> V_41 . V_48 ;
V_45 -> V_49 += V_42 ;
V_47 = (struct V_46 * ) ( ( void * ) V_45 +
V_45 -> V_50 + V_45 -> V_51 ) ;
V_47 -> V_52 = V_42 ;
V_47 -> type = V_43 ;
V_47 -> V_53 = sizeof( struct V_46 ) ;
V_45 -> V_51 += V_42 ;
return V_47 ;
}
static T_2 F_22 ( struct V_9 * V_10 , struct V_54 * V_55 ,
void * V_56 , T_3 V_57 )
{
struct V_3 * V_23 = F_6 ( V_10 ) ;
unsigned int V_58 = V_10 -> V_59 ;
struct V_60 * V_61 = V_55 -> V_61 ;
int V_62 = F_23 ( V_61 ) ;
if ( V_62 < 0 || V_55 -> V_63 || V_62 >= V_58 ) {
T_2 V_64 = F_24 ( V_10 , V_55 , V_65 ) ;
int V_66 ;
V_66 = V_23 -> V_67 [ V_64 ] % V_58 ;
if ( V_62 != V_66 && V_61 &&
F_25 ( V_61 ) && F_26 ( V_61 -> V_68 ) )
F_27 ( V_61 , V_66 ) ;
V_62 = V_66 ;
}
return V_62 ;
}
static T_1 F_28 ( struct V_69 * V_69 , T_1 V_70 , T_1 V_71 ,
struct V_72 * V_73 )
{
int V_74 = 0 ;
V_69 += ( V_70 >> V_75 ) ;
V_70 &= ~ V_76 ;
while ( V_71 > 0 ) {
unsigned long V_77 ;
V_77 = V_78 - V_70 ;
if ( V_77 > V_71 )
V_77 = V_71 ;
V_73 [ V_74 ] . V_79 = F_29 ( V_69 ) ;
V_73 [ V_74 ] . V_70 = V_70 ;
V_73 [ V_74 ] . V_71 = V_77 ;
V_70 += V_77 ;
V_71 -= V_77 ;
if ( V_70 == V_78 && V_71 ) {
V_69 ++ ;
V_70 = 0 ;
V_74 ++ ;
}
}
return V_74 + 1 ;
}
static T_1 F_30 ( void * V_80 , T_1 V_71 , struct V_54 * V_55 ,
struct V_81 * V_82 ,
struct V_72 * * V_83 )
{
struct V_72 * V_73 = * V_83 ;
T_1 V_84 = 0 ;
char * V_85 = V_55 -> V_85 ;
int V_86 = F_31 ( V_55 ) -> V_87 ;
int V_28 ;
if ( V_80 != NULL )
V_84 += F_28 ( F_32 ( V_80 ) ,
F_33 ( V_80 ) ,
V_71 , & V_73 [ V_84 ] ) ;
V_82 -> V_88 = V_71 ;
V_82 -> V_89 = V_84 ;
V_84 += F_28 ( F_32 ( V_85 ) ,
F_33 ( V_85 ) ,
F_34 ( V_55 ) , & V_73 [ V_84 ] ) ;
for ( V_28 = 0 ; V_28 < V_86 ; V_28 ++ ) {
T_4 * V_90 = F_31 ( V_55 ) -> V_86 + V_28 ;
V_84 += F_28 ( F_35 ( V_90 ) ,
V_90 -> V_91 ,
F_36 ( V_90 ) , & V_73 [ V_84 ] ) ;
}
return V_84 ;
}
static int F_37 ( struct V_54 * V_55 )
{
int V_28 , V_86 = F_31 ( V_55 ) -> V_87 ;
int V_92 = 0 ;
for ( V_28 = 0 ; V_28 < V_86 ; V_28 ++ ) {
T_4 * V_90 = F_31 ( V_55 ) -> V_86 + V_28 ;
unsigned long V_52 = F_36 ( V_90 ) ;
unsigned long V_70 = V_90 -> V_91 ;
V_70 &= ~ V_76 ;
V_92 += F_38 ( V_70 + V_52 ) ;
}
return V_92 ;
}
static int F_39 ( struct V_54 * V_55 )
{
char * V_85 = V_55 -> V_85 ;
unsigned int V_70 = F_33 ( V_85 ) ;
unsigned int V_71 = F_34 ( V_55 ) ;
int V_93 ;
int V_94 ;
V_93 = F_40 ( V_70 + V_71 , V_78 ) ;
V_94 = F_37 ( V_55 ) ;
return V_93 + V_94 ;
}
static T_1 F_41 ( struct V_54 * V_55 )
{
if ( V_55 -> V_95 == F_42 ( V_96 ) ) {
struct V_97 * V_98 = F_43 ( V_55 ) ;
if ( V_98 -> V_95 == V_99 )
return V_100 ;
else if ( V_98 -> V_95 == V_101 )
return V_102 ;
} else {
struct V_103 * V_104 = F_44 ( V_55 ) ;
if ( V_104 -> V_105 == V_99 )
return V_106 ;
else if ( F_44 ( V_55 ) -> V_105 == V_101 )
return V_107 ;
}
return V_108 ;
}
static int F_45 ( struct V_54 * V_55 , struct V_9 * V_22 )
{
struct V_3 * V_23 = F_6 ( V_22 ) ;
struct V_81 * V_82 = NULL ;
int V_24 ;
unsigned int V_109 ;
struct V_40 * V_110 ;
struct V_44 * V_45 ;
T_1 V_111 ;
struct V_46 * V_47 ;
T_1 V_64 ;
struct V_72 V_83 [ V_112 ] ;
struct V_72 * V_73 = V_83 ;
V_109 = F_39 ( V_55 ) + 2 ;
if ( F_46 ( V_109 > V_112 ) ) {
++ V_23 -> V_113 . V_114 ;
if ( F_47 ( V_55 ) )
goto V_115;
V_109 = F_39 ( V_55 ) + 2 ;
if ( V_109 > V_112 ) {
++ V_23 -> V_113 . V_116 ;
goto V_117;
}
}
V_24 = F_48 ( V_55 , V_118 ) ;
if ( V_24 )
goto V_115;
F_49 ( sizeof( struct V_81 ) >
F_50 ( struct V_54 , V_119 ) ) ;
V_82 = (struct V_81 * ) V_55 -> V_119 ;
V_82 -> V_62 = F_51 ( V_55 ) ;
V_82 -> V_120 = V_55 -> V_71 ;
V_82 -> V_121 = V_55 -> V_71 ;
V_82 -> V_122 = 1 ;
V_110 = (struct V_40 * ) V_55 -> V_123 ;
memset ( V_110 , 0 , V_118 ) ;
V_110 -> V_124 = V_125 ;
V_110 -> V_126 = V_82 -> V_120 ;
V_45 = & V_110 -> V_41 . V_48 ;
V_45 -> V_49 = sizeof( struct V_44 ) ;
V_45 -> V_127 = V_82 -> V_120 ;
V_45 -> V_50 = sizeof( struct V_44 ) ;
V_111 = F_52 ( struct V_44 ) ;
V_64 = F_53 ( V_55 ) ;
if ( V_64 != 0 && V_22 -> V_59 > 1 ) {
V_111 += V_128 ;
V_47 = F_21 ( V_110 , V_128 ,
V_129 ) ;
* ( T_1 * ) ( ( void * ) V_47 + V_47 -> V_53 ) = V_64 ;
}
if ( F_54 ( V_55 ) ) {
struct V_130 * V_131 ;
V_111 += V_132 ;
V_47 = F_21 ( V_110 , V_132 ,
V_133 ) ;
V_131 = (struct V_130 * ) ( ( void * ) V_47 +
V_47 -> V_53 ) ;
V_131 -> V_134 = V_55 -> V_135 & V_136 ;
V_131 -> V_137 = ( V_55 -> V_135 & V_138 ) >>
V_139 ;
}
if ( F_55 ( V_55 ) ) {
struct V_140 * V_141 ;
V_111 += V_142 ;
V_47 = F_21 ( V_110 , V_142 ,
V_143 ) ;
V_141 = (struct V_140 * ) ( ( void * ) V_47 +
V_47 -> V_53 ) ;
V_141 -> V_144 . type = V_145 ;
if ( V_55 -> V_95 == F_42 ( V_96 ) ) {
V_141 -> V_144 . V_146 =
V_147 ;
F_43 ( V_55 ) -> V_148 = 0 ;
F_43 ( V_55 ) -> V_149 = 0 ;
F_56 ( V_55 ) -> V_149 =
~ F_57 ( F_43 ( V_55 ) -> V_150 ,
F_43 ( V_55 ) -> V_151 , 0 , V_99 , 0 ) ;
} else {
V_141 -> V_144 . V_146 =
V_152 ;
F_44 ( V_55 ) -> V_153 = 0 ;
F_56 ( V_55 ) -> V_149 =
~ F_58 ( & F_44 ( V_55 ) -> V_150 ,
& F_44 ( V_55 ) -> V_151 , 0 , V_99 , 0 ) ;
}
V_141 -> V_144 . V_154 = F_59 ( V_55 ) ;
V_141 -> V_144 . V_155 = F_31 ( V_55 ) -> V_156 ;
} else if ( V_55 -> V_157 == V_158 ) {
if ( F_41 ( V_55 ) & V_23 -> V_159 ) {
struct V_160 * V_161 ;
V_111 += V_162 ;
V_47 = F_21 ( V_110 , V_162 ,
V_163 ) ;
V_161 = (struct V_160 * ) ( ( void * ) V_47 +
V_47 -> V_53 ) ;
V_161 -> V_164 . V_154 = F_59 ( V_55 ) ;
if ( V_55 -> V_95 == F_42 ( V_96 ) ) {
V_161 -> V_164 . V_165 = 1 ;
if ( F_43 ( V_55 ) -> V_95 == V_99 )
V_161 -> V_164 . V_166 = 1 ;
else
V_161 -> V_164 . V_167 = 1 ;
} else {
V_161 -> V_164 . V_168 = 1 ;
if ( F_44 ( V_55 ) -> V_105 == V_99 )
V_161 -> V_164 . V_166 = 1 ;
else
V_161 -> V_164 . V_167 = 1 ;
}
} else {
if ( F_60 ( V_55 ) )
goto V_117;
}
}
V_110 -> V_126 += V_111 ;
V_82 -> V_120 = V_110 -> V_126 ;
V_82 -> V_169 = F_30 ( V_110 , V_111 ,
V_55 , V_82 , & V_73 ) ;
F_61 ( V_55 ) ;
V_24 = F_62 ( V_23 -> V_8 , V_82 ,
V_110 , & V_73 , V_55 ) ;
if ( F_63 ( V_24 == 0 ) )
return V_170 ;
if ( V_24 == - V_171 ) {
++ V_23 -> V_113 . V_172 ;
return V_173 ;
}
if ( V_24 == - V_174 )
++ V_23 -> V_113 . V_175 ;
V_117:
F_64 ( V_55 ) ;
V_22 -> V_176 . V_177 ++ ;
return V_170 ;
V_115:
++ V_23 -> V_113 . V_178 ;
goto V_117;
}
void F_65 ( struct V_6 * V_7 ,
struct V_40 * V_179 )
{
struct V_180 * V_181 = & V_179 -> V_41 . V_182 ;
struct V_9 * V_22 ;
struct V_3 * V_183 ;
struct V_184 * V_185 ;
unsigned long V_16 ;
V_22 = F_3 ( V_7 ) ;
if ( ! V_22 )
return;
V_183 = F_6 ( V_22 ) ;
if ( V_181 -> V_186 == V_187 ) {
T_1 V_188 ;
V_188 = * ( T_1 * ) ( ( void * ) V_181 + V_181 ->
V_189 ) / 10000 ;
V_183 -> V_188 = V_188 ;
return;
}
if ( V_181 -> V_186 != V_190 &&
V_181 -> V_186 != V_191 &&
V_181 -> V_186 != V_192 )
return;
if ( V_22 -> V_193 != V_194 )
return;
V_185 = F_66 ( sizeof( * V_185 ) , V_195 ) ;
if ( ! V_185 )
return;
V_185 -> V_185 = V_181 -> V_186 ;
F_67 ( & V_183 -> V_196 , V_16 ) ;
F_68 ( & V_185 -> V_197 , & V_183 -> V_198 ) ;
F_69 ( & V_183 -> V_196 , V_16 ) ;
F_70 ( & V_183 -> V_199 , 0 ) ;
}
static struct V_54 * F_71 ( struct V_9 * V_22 ,
const struct V_160 * V_161 ,
const struct V_130 * V_131 ,
void * V_85 , T_1 V_200 )
{
struct V_54 * V_55 ;
V_55 = F_72 ( V_22 , V_200 ) ;
if ( ! V_55 )
return V_55 ;
memcpy ( F_73 ( V_55 , V_200 ) , V_85 , V_200 ) ;
V_55 -> V_95 = F_74 ( V_55 , V_22 ) ;
F_75 ( V_55 ) ;
if ( V_161 && ( V_22 -> V_201 & V_202 ) ) {
if ( V_161 -> V_203 . V_204 ||
V_161 -> V_203 . V_205 )
V_55 -> V_157 = V_206 ;
}
if ( V_131 ) {
T_2 V_135 = V_131 -> V_134 | ( V_131 -> V_137 << V_139 ) ;
F_76 ( V_55 , F_42 ( V_207 ) ,
V_135 ) ;
}
return V_55 ;
}
int F_77 ( struct V_9 * V_22 ,
struct V_32 * V_36 ,
void * V_85 , T_1 V_71 ,
const struct V_160 * V_161 ,
const struct V_130 * V_131 )
{
struct V_3 * V_23 = F_6 ( V_22 ) ;
struct V_11 * V_9 = V_23 -> V_12 ;
struct V_9 * V_208 ;
struct V_54 * V_55 ;
struct V_209 * V_210 ;
T_2 V_62 = V_36 -> V_211 . V_212 . V_213 ;
if ( V_22 -> V_193 != V_194 )
return V_214 ;
F_78 () ;
V_208 = F_79 ( V_23 -> V_208 ) ;
if ( V_208 && ( V_208 -> V_16 & V_215 ) )
V_22 = V_208 ;
V_55 = F_71 ( V_22 , V_161 , V_131 , V_85 , V_71 ) ;
if ( F_46 ( ! V_55 ) ) {
++ V_22 -> V_176 . V_216 ;
F_80 () ;
return V_214 ;
}
if ( V_22 != V_208 )
F_81 ( V_55 , V_62 ) ;
V_210 = & V_9 -> V_35 [ V_62 ] . V_210 ;
F_82 ( & V_210 -> V_217 ) ;
V_210 -> V_218 ++ ;
V_210 -> V_77 += V_71 ;
if ( V_55 -> V_43 == V_219 )
++ V_210 -> V_220 ;
else if ( V_55 -> V_43 == V_221 )
++ V_210 -> V_222 ;
F_83 ( & V_210 -> V_217 ) ;
F_84 ( V_55 ) ;
F_80 () ;
return 0 ;
}
static void F_85 ( struct V_9 * V_22 ,
struct V_223 * V_224 )
{
F_86 ( V_224 -> V_225 , V_226 , sizeof( V_224 -> V_225 ) ) ;
F_86 ( V_224 -> V_227 , L_4 , sizeof( V_224 -> V_227 ) ) ;
}
static void F_87 ( struct V_9 * V_22 ,
struct V_228 * V_36 )
{
struct V_3 * V_23 = F_6 ( V_22 ) ;
struct V_11 * V_12 = V_23 -> V_12 ;
if ( V_12 ) {
V_36 -> V_229 = V_12 -> V_230 ;
V_36 -> V_231 = V_12 -> V_34 ;
}
}
static int F_88 ( struct V_9 * V_22 , struct V_6 * V_232 ,
T_1 V_34 )
{
struct V_233 V_234 ;
int V_24 ;
memset ( & V_234 , 0 , sizeof( V_234 ) ) ;
V_234 . V_34 = V_34 ;
V_234 . V_235 = V_235 ;
V_234 . V_236 = V_34 ;
V_24 = F_89 ( V_232 , & V_234 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_90 ( V_22 , V_34 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_91 ( V_22 , V_34 ) ;
return V_24 ;
}
static int F_92 ( struct V_9 * V_22 ,
struct V_228 * V_237 )
{
struct V_3 * V_23 = F_6 ( V_22 ) ;
struct V_6 * V_232 = V_23 -> V_8 ;
struct V_11 * V_12 = V_23 -> V_12 ;
unsigned int V_238 = V_237 -> V_231 ;
int V_24 ;
if ( V_238 == 0 ||
V_237 -> V_239 || V_237 -> V_240 || V_237 -> V_241 )
return - V_242 ;
if ( V_238 > V_22 -> V_58 || V_238 > V_22 -> V_243 )
return - V_242 ;
if ( V_23 -> V_244 || ! V_12 || V_12 -> V_245 )
return - V_246 ;
if ( V_12 -> V_247 < V_248 )
return - V_242 ;
if ( V_238 > V_12 -> V_230 )
return - V_242 ;
V_24 = F_15 ( V_22 ) ;
if ( V_24 )
return V_24 ;
V_23 -> V_244 = true ;
F_93 ( V_232 , V_12 ) ;
V_24 = F_88 ( V_22 , V_232 , V_238 ) ;
if ( V_24 == 0 )
V_12 -> V_34 = V_238 ;
else
F_88 ( V_22 , V_232 , V_12 -> V_34 ) ;
F_8 ( V_22 ) ;
V_23 -> V_244 = false ;
F_70 ( & V_23 -> V_199 , 0 ) ;
return V_24 ;
}
static bool F_94 ( const struct V_249 * V_250 )
{
struct V_249 V_251 = * V_250 ;
struct V_249 V_252 = {} ;
F_95 ( & V_251 , 0 ) ;
V_251 . V_253 = 0 ;
V_251 . V_254 = 0 ;
V_251 . V_250 = 0 ;
V_252 . V_255 = V_256 ;
return ! memcmp ( & V_251 , & V_252 , sizeof( V_251 ) ) ;
}
static void F_96 ( struct V_9 * V_232 )
{
struct V_3 * V_257 = F_6 ( V_232 ) ;
V_257 -> V_188 = V_258 ;
V_257 -> V_253 = V_259 ;
}
static int F_97 ( struct V_9 * V_232 , struct V_249 * V_250 )
{
struct V_3 * V_257 = F_6 ( V_232 ) ;
F_95 ( V_250 , V_257 -> V_188 ) ;
V_250 -> V_253 = V_257 -> V_253 ;
V_250 -> V_255 = V_256 ;
return 0 ;
}
static int F_98 ( struct V_9 * V_232 , struct V_249 * V_250 )
{
struct V_3 * V_257 = F_6 ( V_232 ) ;
T_1 V_188 ;
V_188 = F_99 ( V_250 ) ;
if ( ! F_100 ( V_188 ) ||
! F_101 ( V_250 -> V_253 ) ||
! F_94 ( V_250 ) )
return - V_242 ;
V_257 -> V_188 = V_188 ;
V_257 -> V_253 = V_250 -> V_253 ;
return 0 ;
}
static int F_102 ( struct V_9 * V_10 , int V_260 )
{
struct V_3 * V_4 = F_6 ( V_10 ) ;
struct V_11 * V_12 = V_4 -> V_12 ;
struct V_6 * V_261 = V_4 -> V_8 ;
struct V_233 V_234 ;
int V_24 ;
if ( V_4 -> V_244 || ! V_12 || V_12 -> V_245 )
return - V_246 ;
V_24 = F_15 ( V_10 ) ;
if ( V_24 )
goto V_262;
memset ( & V_234 , 0 , sizeof( V_234 ) ) ;
V_234 . V_235 = V_235 ;
V_234 . V_34 = V_12 -> V_34 ;
V_234 . V_236 = V_12 -> V_34 ;
V_4 -> V_244 = true ;
F_93 ( V_261 , V_12 ) ;
V_10 -> V_260 = V_260 ;
F_89 ( V_261 , & V_234 ) ;
V_262:
F_8 ( V_10 ) ;
V_4 -> V_244 = false ;
F_70 ( & V_4 -> V_199 , 0 ) ;
return V_24 ;
}
static void F_103 ( struct V_9 * V_22 ,
struct V_263 * V_264 )
{
struct V_3 * V_183 = F_6 ( V_22 ) ;
struct V_11 * V_12 = V_183 -> V_12 ;
int V_28 ;
if ( ! V_12 )
return;
for ( V_28 = 0 ; V_28 < V_12 -> V_34 ; V_28 ++ ) {
const struct V_265 * V_266 = & V_12 -> V_35 [ V_28 ] ;
const struct V_209 * V_176 ;
T_5 V_218 , V_77 , V_222 ;
unsigned int V_267 ;
V_176 = & V_266 -> V_268 ;
do {
V_267 = F_104 ( & V_176 -> V_217 ) ;
V_218 = V_176 -> V_218 ;
V_77 = V_176 -> V_77 ;
} while ( F_105 ( & V_176 -> V_217 , V_267 ) );
V_264 -> V_269 += V_77 ;
V_264 -> V_270 += V_218 ;
V_176 = & V_266 -> V_210 ;
do {
V_267 = F_104 ( & V_176 -> V_217 ) ;
V_218 = V_176 -> V_218 ;
V_77 = V_176 -> V_77 ;
V_222 = V_176 -> V_222 + V_176 -> V_220 ;
} while ( F_105 ( & V_176 -> V_217 , V_267 ) );
V_264 -> V_271 += V_77 ;
V_264 -> V_272 += V_218 ;
V_264 -> V_222 += V_222 ;
}
V_264 -> V_177 = V_22 -> V_176 . V_177 ;
V_264 -> V_273 = V_22 -> V_176 . V_273 ;
V_264 -> V_216 = V_22 -> V_176 . V_216 ;
V_264 -> V_274 = V_22 -> V_176 . V_274 ;
}
static int F_106 ( struct V_9 * V_10 , void * V_275 )
{
struct V_276 * V_277 = V_275 ;
char V_278 [ V_279 ] ;
unsigned char V_280 ;
int V_281 ;
memcpy ( V_278 , V_10 -> V_282 , V_279 ) ;
V_280 = V_10 -> V_283 ;
V_281 = F_107 ( V_10 , V_275 ) ;
if ( V_281 != 0 )
return V_281 ;
V_281 = F_108 ( V_10 , V_277 -> V_284 ) ;
if ( V_281 != 0 ) {
memcpy ( V_10 -> V_282 , V_278 , V_279 ) ;
V_10 -> V_283 = V_280 ;
}
return V_281 ;
}
static int F_109 ( struct V_9 * V_232 , int V_285 )
{
struct V_3 * V_257 = F_6 ( V_232 ) ;
struct V_11 * V_12 = V_257 -> V_12 ;
switch ( V_285 ) {
case V_286 :
return V_287 + F_110 ( V_12 ) ;
default:
return - V_242 ;
}
}
static void F_111 ( struct V_9 * V_232 ,
struct V_288 * V_176 , T_5 * V_85 )
{
struct V_3 * V_257 = F_6 ( V_232 ) ;
struct V_11 * V_12 = V_257 -> V_12 ;
const void * V_289 = & V_257 -> V_113 ;
const struct V_209 * V_290 ;
unsigned int V_267 ;
T_5 V_218 , V_77 ;
int V_28 , V_74 ;
for ( V_28 = 0 ; V_28 < V_287 ; V_28 ++ )
V_85 [ V_28 ] = * ( unsigned long * ) ( V_289 + V_209 [ V_28 ] . V_70 ) ;
for ( V_74 = 0 ; V_74 < V_12 -> V_34 ; V_74 ++ ) {
V_290 = & V_12 -> V_35 [ V_74 ] . V_268 ;
do {
V_267 = F_104 ( & V_290 -> V_217 ) ;
V_218 = V_290 -> V_218 ;
V_77 = V_290 -> V_77 ;
} while ( F_105 ( & V_290 -> V_217 , V_267 ) );
V_85 [ V_28 ++ ] = V_218 ;
V_85 [ V_28 ++ ] = V_77 ;
V_290 = & V_12 -> V_35 [ V_74 ] . V_210 ;
do {
V_267 = F_104 ( & V_290 -> V_217 ) ;
V_218 = V_290 -> V_218 ;
V_77 = V_290 -> V_77 ;
} while ( F_105 ( & V_290 -> V_217 , V_267 ) );
V_85 [ V_28 ++ ] = V_218 ;
V_85 [ V_28 ++ ] = V_77 ;
}
}
static void F_112 ( struct V_9 * V_232 , T_1 V_291 , T_6 * V_85 )
{
struct V_3 * V_257 = F_6 ( V_232 ) ;
struct V_11 * V_12 = V_257 -> V_12 ;
T_6 * V_275 = V_85 ;
int V_28 ;
switch ( V_291 ) {
case V_286 :
for ( V_28 = 0 ; V_28 < F_113 ( V_209 ) ; V_28 ++ )
memcpy ( V_275 + V_28 * V_292 ,
V_209 [ V_28 ] . V_293 , V_292 ) ;
V_275 += V_28 * V_292 ;
for ( V_28 = 0 ; V_28 < V_12 -> V_34 ; V_28 ++ ) {
sprintf ( V_275 , L_5 , V_28 ) ;
V_275 += V_292 ;
sprintf ( V_275 , L_6 , V_28 ) ;
V_275 += V_292 ;
sprintf ( V_275 , L_7 , V_28 ) ;
V_275 += V_292 ;
sprintf ( V_275 , L_8 , V_28 ) ;
V_275 += V_292 ;
}
break;
}
}
static int
F_114 ( struct V_11 * V_12 ,
struct V_294 * V_224 )
{
V_224 -> V_85 = V_295 | V_296 ;
switch ( V_224 -> V_297 ) {
case V_298 :
case V_299 :
V_224 -> V_85 |= V_300 | V_301 ;
case V_302 :
case V_303 :
case V_304 :
case V_305 :
break;
default:
V_224 -> V_85 = 0 ;
break;
}
return 0 ;
}
static int
F_115 ( struct V_9 * V_232 , struct V_294 * V_224 ,
T_1 * V_306 )
{
struct V_3 * V_257 = F_6 ( V_232 ) ;
struct V_11 * V_12 = V_257 -> V_12 ;
switch ( V_224 -> V_250 ) {
case V_307 :
V_224 -> V_85 = V_12 -> V_34 ;
return 0 ;
case V_308 :
return F_114 ( V_12 , V_224 ) ;
}
return - V_309 ;
}
static void F_116 ( struct V_9 * V_22 )
{
}
static T_1 F_117 ( struct V_9 * V_232 )
{
return V_310 ;
}
static T_1 F_118 ( struct V_9 * V_232 )
{
return V_311 ;
}
static int F_119 ( struct V_9 * V_232 , T_1 * V_312 , T_6 * V_313 ,
T_6 * V_314 )
{
struct V_3 * V_257 = F_6 ( V_232 ) ;
struct V_11 * V_10 = V_257 -> V_12 ;
struct V_13 * V_315 = V_10 -> V_15 ;
int V_28 ;
if ( V_314 )
* V_314 = V_316 ;
if ( V_312 ) {
for ( V_28 = 0 ; V_28 < V_311 ; V_28 ++ )
V_312 [ V_28 ] = V_315 -> V_317 [ V_28 ] ;
}
if ( V_313 )
memcpy ( V_313 , V_315 -> V_318 , V_310 ) ;
return 0 ;
}
static int F_120 ( struct V_9 * V_232 , const T_1 * V_312 ,
const T_6 * V_313 , const T_6 V_314 )
{
struct V_3 * V_257 = F_6 ( V_232 ) ;
struct V_11 * V_10 = V_257 -> V_12 ;
struct V_13 * V_315 = V_10 -> V_15 ;
int V_28 ;
if ( V_314 != V_319 && V_314 != V_316 )
return - V_309 ;
if ( V_312 ) {
for ( V_28 = 0 ; V_28 < V_311 ; V_28 ++ )
if ( V_312 [ V_28 ] >= V_232 -> V_243 )
return - V_242 ;
for ( V_28 = 0 ; V_28 < V_311 ; V_28 ++ )
V_315 -> V_317 [ V_28 ] = V_312 [ V_28 ] ;
}
if ( ! V_313 ) {
if ( ! V_312 )
return 0 ;
V_313 = V_315 -> V_318 ;
}
return F_121 ( V_315 , V_313 , V_10 -> V_34 ) ;
}
static void F_122 ( struct V_1 * V_2 )
{
struct V_3 * V_183 =
F_2 ( V_2 , struct V_3 , V_199 . V_5 ) ;
struct V_6 * V_7 = V_183 -> V_8 ;
struct V_9 * V_22 = F_3 ( V_7 ) ;
struct V_11 * V_9 ;
struct V_13 * V_14 ;
struct V_184 * V_185 = NULL ;
bool V_320 = false , V_321 = false ;
unsigned long V_16 , V_322 , V_323 ;
F_123 () ;
if ( V_183 -> V_244 )
goto V_324;
V_9 = V_183 -> V_12 ;
V_14 = V_9 -> V_15 ;
V_322 = V_183 -> V_325 + V_326 ;
if ( F_124 ( V_322 ) ) {
V_323 = V_322 - V_327 ;
V_323 = V_323 < V_326 ? V_323 : V_326 ;
F_70 ( & V_183 -> V_199 , V_323 ) ;
goto V_324;
}
V_183 -> V_325 = V_327 ;
F_67 ( & V_183 -> V_196 , V_16 ) ;
if ( ! F_125 ( & V_183 -> V_198 ) ) {
V_185 = F_126 ( & V_183 -> V_198 ,
struct V_184 , V_197 ) ;
F_127 ( & V_185 -> V_197 ) ;
V_321 = ! F_125 ( & V_183 -> V_198 ) ;
}
F_69 ( & V_183 -> V_196 , V_16 ) ;
if ( ! V_185 )
goto V_324;
switch ( V_185 -> V_185 ) {
case V_191 :
if ( V_14 -> V_25 ) {
V_14 -> V_25 = false ;
F_14 ( V_22 ) ;
F_13 ( V_22 ) ;
} else {
V_320 = true ;
}
F_128 ( V_185 ) ;
break;
case V_192 :
if ( ! V_14 -> V_25 ) {
V_14 -> V_25 = true ;
F_10 ( V_22 ) ;
F_129 ( V_22 ) ;
}
F_128 ( V_185 ) ;
break;
case V_190 :
if ( ! V_14 -> V_25 ) {
V_14 -> V_25 = true ;
F_10 ( V_22 ) ;
F_129 ( V_22 ) ;
V_185 -> V_185 = V_191 ;
F_67 ( & V_183 -> V_196 , V_16 ) ;
F_130 ( & V_185 -> V_197 , & V_183 -> V_198 ) ;
F_69 ( & V_183 -> V_196 , V_16 ) ;
V_321 = true ;
}
break;
}
F_131 () ;
if ( V_320 )
F_132 ( V_22 ) ;
if ( V_321 )
F_70 ( & V_183 -> V_199 , V_326 ) ;
return;
V_324:
F_131 () ;
}
static struct V_9 * F_133 ( const T_6 * V_328 )
{
struct V_9 * V_232 ;
F_134 () ;
F_135 (&init_net, dev) {
if ( V_232 -> V_329 != & V_330 )
continue;
if ( F_136 ( V_328 , V_232 -> V_331 ) )
return V_232 ;
}
return NULL ;
}
static struct V_9 * F_137 ( struct V_9 * V_208 )
{
struct V_9 * V_232 ;
F_134 () ;
F_135 (&init_net, dev) {
struct V_3 * V_23 ;
if ( V_232 -> V_329 != & V_330 )
continue;
V_23 = F_6 ( V_232 ) ;
if ( V_23 -> V_12 == NULL )
continue;
if ( F_138 ( V_23 -> V_208 ) == V_208 )
return V_232 ;
}
return NULL ;
}
static int F_139 ( struct V_9 * V_208 )
{
struct V_9 * V_10 ;
struct V_3 * V_23 ;
struct V_11 * V_332 ;
if ( V_208 -> V_333 != V_279 )
return V_334 ;
V_10 = F_133 ( V_208 -> V_331 ) ;
if ( ! V_10 )
return V_334 ;
V_23 = F_6 ( V_10 ) ;
V_332 = V_23 -> V_12 ;
if ( ! V_332 || F_138 ( V_23 -> V_208 ) )
return V_334 ;
F_140 ( V_10 , L_9 , V_208 -> V_293 ) ;
F_141 ( V_335 ) ;
F_142 ( V_208 ) ;
F_143 ( V_23 -> V_208 , V_208 ) ;
return V_336 ;
}
static int F_144 ( struct V_9 * V_208 )
{
struct V_9 * V_10 ;
struct V_11 * V_332 ;
struct V_3 * V_23 ;
V_10 = F_137 ( V_208 ) ;
if ( ! V_10 )
return V_334 ;
V_23 = F_6 ( V_10 ) ;
V_332 = V_23 -> V_12 ;
F_140 ( V_10 , L_10 , V_208 -> V_293 ) ;
F_11 ( V_332 ) ;
F_145 ( V_10 , true ) ;
F_140 ( V_10 , L_11 , V_208 -> V_293 ) ;
F_10 ( V_10 ) ;
F_146 ( V_337 , V_208 ) ;
return V_336 ;
}
static int F_147 ( struct V_9 * V_208 )
{
struct V_9 * V_10 ;
struct V_11 * V_332 ;
struct V_3 * V_23 ;
V_10 = F_137 ( V_208 ) ;
if ( ! V_10 )
return V_334 ;
V_23 = F_6 ( V_10 ) ;
V_332 = V_23 -> V_12 ;
F_140 ( V_10 , L_12 , V_208 -> V_293 ) ;
F_145 ( V_10 , false ) ;
F_140 ( V_10 , L_13 , V_208 -> V_293 ) ;
F_18 ( V_332 ) ;
F_14 ( V_10 ) ;
F_146 ( V_337 , V_10 ) ;
return V_336 ;
}
static int F_148 ( struct V_9 * V_208 )
{
struct V_9 * V_10 ;
struct V_3 * V_23 ;
V_10 = F_137 ( V_208 ) ;
if ( ! V_10 )
return V_334 ;
V_23 = F_6 ( V_10 ) ;
F_140 ( V_10 , L_14 , V_208 -> V_293 ) ;
F_149 ( V_23 -> V_208 , NULL ) ;
F_150 ( V_208 ) ;
F_151 ( V_335 ) ;
return V_336 ;
}
static int F_152 ( struct V_6 * V_232 ,
const struct V_338 * V_339 )
{
struct V_9 * V_22 = NULL ;
struct V_3 * V_23 ;
struct V_233 V_234 ;
struct V_11 * V_12 ;
int V_24 ;
V_22 = F_153 ( sizeof( struct V_3 ) ,
V_340 ) ;
if ( ! V_22 )
return - V_341 ;
F_10 ( V_22 ) ;
F_96 ( V_22 ) ;
V_23 = F_6 ( V_22 ) ;
V_23 -> V_8 = V_232 ;
V_23 -> V_342 = F_154 ( V_343 , V_344 ) ;
if ( F_155 ( V_23 ) )
F_156 ( V_22 , L_15 ,
V_23 -> V_342 ) ;
F_157 ( V_232 , V_22 ) ;
V_23 -> V_244 = false ;
F_158 ( & V_23 -> V_199 , F_122 ) ;
F_159 ( & V_23 -> V_5 , F_1 ) ;
F_160 ( & V_23 -> V_196 ) ;
F_161 ( & V_23 -> V_198 ) ;
V_22 -> V_329 = & V_330 ;
V_22 -> V_345 = & V_345 ;
F_162 ( V_22 , & V_232 -> V_346 ) ;
V_22 -> V_347 = V_118 ;
memset ( & V_234 , 0 , sizeof( V_234 ) ) ;
V_234 . V_235 = V_235 ;
V_234 . V_236 = F_163 ( T_1 , V_348 ,
F_164 () ) ;
V_24 = F_89 ( V_232 , & V_234 ) ;
if ( V_24 != 0 ) {
F_12 ( V_22 , L_16 , V_24 ) ;
F_165 ( V_22 ) ;
F_157 ( V_232 , NULL ) ;
return V_24 ;
}
memcpy ( V_22 -> V_282 , V_234 . V_349 , V_279 ) ;
V_22 -> V_201 = V_22 -> V_350 |
V_351 | V_352 |
V_353 | V_354 ;
V_22 -> V_355 = V_22 -> V_201 ;
V_12 = V_23 -> V_12 ;
F_90 ( V_22 , V_12 -> V_34 ) ;
F_91 ( V_22 , V_12 -> V_34 ) ;
V_22 -> V_356 = V_357 ;
if ( V_12 -> V_247 >= V_358 )
V_22 -> V_359 = V_360 - V_361 ;
else
V_22 -> V_359 = V_362 ;
V_24 = F_166 ( V_22 ) ;
if ( V_24 != 0 ) {
F_167 ( L_17 ) ;
F_93 ( V_232 , V_12 ) ;
F_165 ( V_22 ) ;
}
return V_24 ;
}
static int F_168 ( struct V_6 * V_232 )
{
struct V_9 * V_22 ;
struct V_3 * V_183 ;
V_22 = F_3 ( V_232 ) ;
if ( V_22 == NULL ) {
F_169 ( & V_232 -> V_346 , L_18 ) ;
return 0 ;
}
V_183 = F_6 ( V_22 ) ;
F_123 () ;
V_183 -> V_244 = true ;
F_131 () ;
F_170 ( & V_183 -> V_199 ) ;
F_17 ( & V_183 -> V_5 ) ;
F_16 ( V_22 ) ;
F_171 ( V_22 ) ;
F_93 ( V_232 , V_183 -> V_12 ) ;
F_157 ( V_232 , NULL ) ;
F_165 ( V_22 ) ;
return 0 ;
}
static int F_172 ( struct V_363 * V_364 ,
unsigned long V_185 , void * V_365 )
{
struct V_9 * V_366 = F_173 ( V_365 ) ;
if ( V_366 -> V_329 == & V_330 )
return V_334 ;
if ( V_366 -> type != V_367 )
return V_334 ;
if ( F_174 ( V_366 ) )
return V_334 ;
if ( ( V_366 -> V_368 & V_369 ) &&
( V_366 -> V_16 & V_370 ) )
return V_334 ;
switch ( V_185 ) {
case V_371 :
return F_139 ( V_366 ) ;
case V_372 :
return F_148 ( V_366 ) ;
case V_373 :
return F_144 ( V_366 ) ;
case V_374 :
return F_147 ( V_366 ) ;
default:
return V_334 ;
}
}
static void T_7 F_175 ( void )
{
F_176 ( & V_375 ) ;
F_177 ( & V_376 ) ;
}
static int T_8 F_178 ( void )
{
int V_24 ;
if ( V_235 < V_377 ) {
V_235 = V_377 ;
F_179 ( L_19 ,
V_235 ) ;
}
V_24 = F_180 ( & V_376 ) ;
if ( V_24 )
return V_24 ;
F_181 ( & V_375 ) ;
return 0 ;
}
