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
V_33 = V_12 -> V_35 [ V_28 ] ;
if ( ! V_33 )
continue;
F_19 ( & V_33 -> V_36 , & V_26 ,
& V_27 ) ;
if ( V_26 )
break;
F_19 ( & V_33 -> V_37 , & V_26 ,
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
V_24 = - V_38 ;
}
return V_24 ;
}
static void * F_21 ( struct V_39 * V_40 , T_1 V_41 ,
int V_42 )
{
struct V_43 * V_44 ;
struct V_45 * V_46 ;
V_44 = & V_40 -> V_40 . V_47 ;
V_44 -> V_48 += V_41 ;
V_46 = (struct V_45 * ) ( ( void * ) V_44 +
V_44 -> V_49 + V_44 -> V_50 ) ;
V_46 -> V_51 = V_41 ;
V_46 -> type = V_42 ;
V_46 -> V_52 = sizeof( struct V_45 ) ;
V_44 -> V_50 += V_41 ;
return V_46 ;
}
static T_2 F_22 ( struct V_9 * V_10 , struct V_53 * V_54 ,
void * V_55 , T_3 V_56 )
{
struct V_3 * V_23 = F_6 ( V_10 ) ;
struct V_11 * V_57 = V_23 -> V_12 ;
T_1 V_58 ;
T_2 V_59 = 0 ;
if ( V_57 == NULL || V_10 -> V_60 <= 1 )
return 0 ;
V_58 = F_23 ( V_54 ) ;
V_59 = V_57 -> V_61 [ V_58 % V_62 ] %
V_10 -> V_60 ;
if ( ! V_57 -> V_35 [ V_59 ] )
V_59 = 0 ;
return V_59 ;
}
static T_1 F_24 ( struct V_63 * V_63 , T_1 V_64 , T_1 V_65 ,
struct V_66 * V_67 )
{
int V_68 = 0 ;
V_63 += ( V_64 >> V_69 ) ;
V_64 &= ~ V_70 ;
while ( V_65 > 0 ) {
unsigned long V_71 ;
V_71 = V_72 - V_64 ;
if ( V_71 > V_65 )
V_71 = V_65 ;
V_67 [ V_68 ] . V_73 = F_25 ( V_63 ) ;
V_67 [ V_68 ] . V_64 = V_64 ;
V_67 [ V_68 ] . V_65 = V_71 ;
V_64 += V_71 ;
V_65 -= V_71 ;
if ( V_64 == V_72 && V_65 ) {
V_63 ++ ;
V_64 = 0 ;
V_68 ++ ;
}
}
return V_68 + 1 ;
}
static T_1 F_26 ( void * V_74 , T_1 V_65 , struct V_53 * V_54 ,
struct V_75 * V_76 ,
struct V_66 * * V_77 )
{
struct V_66 * V_67 = * V_77 ;
T_1 V_78 = 0 ;
char * V_79 = V_54 -> V_79 ;
int V_80 = F_27 ( V_54 ) -> V_81 ;
int V_28 ;
if ( V_74 != NULL )
V_78 += F_24 ( F_28 ( V_74 ) ,
F_29 ( V_74 ) ,
V_65 , & V_67 [ V_78 ] ) ;
V_76 -> V_82 = V_65 ;
V_76 -> V_83 = V_78 ;
V_78 += F_24 ( F_28 ( V_79 ) ,
F_29 ( V_79 ) ,
F_30 ( V_54 ) , & V_67 [ V_78 ] ) ;
for ( V_28 = 0 ; V_28 < V_80 ; V_28 ++ ) {
T_4 * V_84 = F_27 ( V_54 ) -> V_80 + V_28 ;
V_78 += F_24 ( F_31 ( V_84 ) ,
V_84 -> V_85 ,
F_32 ( V_84 ) , & V_67 [ V_78 ] ) ;
}
return V_78 ;
}
static int F_33 ( struct V_53 * V_54 )
{
int V_28 , V_80 = F_27 ( V_54 ) -> V_81 ;
int V_86 = 0 ;
for ( V_28 = 0 ; V_28 < V_80 ; V_28 ++ ) {
T_4 * V_84 = F_27 ( V_54 ) -> V_80 + V_28 ;
unsigned long V_51 = F_32 ( V_84 ) ;
unsigned long V_64 = V_84 -> V_85 ;
V_64 &= ~ V_70 ;
V_86 += F_34 ( V_64 + V_51 ) ;
}
return V_86 ;
}
static int F_35 ( struct V_53 * V_54 )
{
char * V_79 = V_54 -> V_79 ;
unsigned int V_64 = F_29 ( V_79 ) ;
unsigned int V_65 = F_30 ( V_54 ) ;
int V_87 ;
int V_88 ;
V_87 = F_36 ( V_64 + V_65 , V_72 ) ;
V_88 = F_33 ( V_54 ) ;
return V_87 + V_88 ;
}
static T_1 F_37 ( struct V_53 * V_54 , T_1 * V_89 )
{
T_1 V_90 = V_91 ;
if ( ( F_38 ( V_54 ) -> V_92 != F_39 ( V_93 ) ) &&
( F_38 ( V_54 ) -> V_92 != F_39 ( V_94 ) ) ) {
goto V_95;
}
* V_89 = F_40 ( V_54 ) ;
if ( ( F_38 ( V_54 ) -> V_92 == F_39 ( V_93 ) ) ) {
struct V_96 * V_96 = F_41 ( V_54 ) ;
if ( V_96 -> V_97 == V_98 )
V_90 = V_99 ;
else if ( V_96 -> V_97 == V_100 )
V_90 = V_101 ;
} else {
if ( F_42 ( V_54 ) -> V_102 == V_98 )
V_90 = V_103 ;
else if ( F_42 ( V_54 ) -> V_102 == V_100 )
V_90 = V_104 ;
}
V_95:
return V_90 ;
}
static int F_43 ( struct V_53 * V_54 , struct V_9 * V_22 )
{
struct V_3 * V_23 = F_6 ( V_22 ) ;
struct V_75 * V_76 = NULL ;
int V_24 ;
unsigned int V_105 ;
struct V_39 * V_106 ;
struct V_43 * V_44 ;
T_1 V_107 ;
struct V_45 * V_46 ;
struct V_108 * V_109 ;
int V_110 ;
T_1 V_111 ;
T_1 V_58 ;
T_1 V_112 ;
struct V_66 V_77 [ V_113 ] ;
struct V_66 * V_67 = V_77 ;
V_112 = V_54 -> V_65 ;
V_105 = F_35 ( V_54 ) + 2 ;
if ( F_44 ( V_105 > V_113 ) ) {
++ V_23 -> V_114 . V_115 ;
if ( F_45 ( V_54 ) )
goto V_116;
V_105 = F_35 ( V_54 ) + 2 ;
if ( V_105 > V_113 ) {
++ V_23 -> V_114 . V_117 ;
goto V_118;
}
}
V_24 = F_46 ( V_54 , V_119 ) ;
if ( V_24 )
goto V_116;
F_47 ( sizeof( struct V_75 ) >
F_48 ( struct V_53 , V_120 ) ) ;
V_76 = (struct V_75 * ) V_54 -> V_120 ;
V_76 -> V_59 = F_49 ( V_54 ) ;
V_76 -> V_121 = V_54 -> V_65 ;
V_106 = (struct V_39 * ) V_54 -> V_122 ;
memset ( V_106 , 0 , V_119 ) ;
V_106 -> V_123 = V_124 ;
V_106 -> V_125 = V_76 -> V_121 ;
V_44 = & V_106 -> V_40 . V_47 ;
V_44 -> V_48 = sizeof( struct V_43 ) ;
V_44 -> V_126 = V_76 -> V_121 ;
V_44 -> V_49 = sizeof( struct V_43 ) ;
V_107 = F_50 ( struct V_43 ) ;
V_58 = F_51 ( V_54 ) ;
if ( V_58 != 0 && V_22 -> V_60 > 1 ) {
V_107 += V_127 ;
V_46 = F_21 ( V_106 , V_127 ,
V_128 ) ;
* ( T_1 * ) ( ( void * ) V_46 + V_46 -> V_52 ) = V_58 ;
}
if ( F_52 ( V_54 ) ) {
struct V_129 * V_130 ;
V_107 += V_131 ;
V_46 = F_21 ( V_106 , V_131 ,
V_132 ) ;
V_130 = (struct V_129 * ) ( ( void * ) V_46 +
V_46 -> V_52 ) ;
V_130 -> V_133 = V_54 -> V_134 & V_135 ;
V_130 -> V_136 = ( V_54 -> V_134 & V_137 ) >>
V_138 ;
}
V_111 = F_37 ( V_54 , & V_110 ) ;
if ( ( V_111 & ( V_139 | V_140 ) ) && F_53 ( V_54 ) ) {
struct V_141 * V_142 ;
V_107 += V_143 ;
V_46 = F_21 ( V_106 , V_143 ,
V_144 ) ;
V_142 = (struct V_141 * ) ( ( void * ) V_46 +
V_46 -> V_52 ) ;
V_142 -> V_145 . type = V_146 ;
if ( V_111 & ( V_147 << 16 ) ) {
V_142 -> V_145 . V_148 =
V_149 ;
F_41 ( V_54 ) -> V_150 = 0 ;
F_41 ( V_54 ) -> V_151 = 0 ;
F_54 ( V_54 ) -> V_151 =
~ F_55 ( F_41 ( V_54 ) -> V_152 ,
F_41 ( V_54 ) -> V_153 , 0 , V_98 , 0 ) ;
} else {
V_142 -> V_145 . V_148 =
V_154 ;
F_42 ( V_54 ) -> V_155 = 0 ;
F_54 ( V_54 ) -> V_151 =
~ F_56 ( & F_42 ( V_54 ) -> V_152 ,
& F_42 ( V_54 ) -> V_153 , 0 , V_98 , 0 ) ;
}
V_142 -> V_145 . V_156 = V_110 ;
V_142 -> V_145 . V_157 = F_27 ( V_54 ) -> V_158 ;
} else if ( V_54 -> V_159 == V_160 ) {
if ( V_111 & V_139 ) {
V_107 += V_161 ;
V_46 = F_21 ( V_106 , V_161 ,
V_162 ) ;
V_109 = (struct V_108 * ) ( ( void * ) V_46 +
V_46 -> V_52 ) ;
if ( V_111 & ( V_147 << 16 ) )
V_109 -> V_163 . V_164 = 1 ;
else
V_109 -> V_163 . V_165 = 1 ;
V_109 -> V_163 . V_166 = 1 ;
V_109 -> V_163 . V_156 = V_110 ;
} else {
if ( F_57 ( V_54 ) )
goto V_118;
}
}
V_106 -> V_125 += V_107 ;
V_76 -> V_121 = V_106 -> V_125 ;
V_76 -> V_167 = F_26 ( V_106 , V_107 ,
V_54 , V_76 , & V_67 ) ;
F_58 ( V_54 ) ;
V_24 = F_59 ( V_23 -> V_8 , V_76 ,
V_106 , & V_67 , V_54 ) ;
if ( F_60 ( V_24 == 0 ) ) {
struct V_168 * V_169 = F_61 ( V_23 -> V_169 ) ;
F_62 ( & V_169 -> V_170 ) ;
V_169 -> V_171 ++ ;
V_169 -> V_71 += V_112 ;
F_63 ( & V_169 -> V_170 ) ;
return V_172 ;
}
if ( V_24 == - V_173 ) {
++ V_23 -> V_114 . V_174 ;
return V_175 ;
}
if ( V_24 == - V_176 )
++ V_23 -> V_114 . V_177 ;
V_118:
F_64 ( V_54 ) ;
V_22 -> V_178 . V_179 ++ ;
return V_172 ;
V_116:
++ V_23 -> V_114 . V_180 ;
goto V_118;
}
void F_65 ( struct V_6 * V_7 ,
struct V_39 * V_181 )
{
struct V_182 * V_183 = & V_181 -> V_40 . V_184 ;
struct V_9 * V_22 ;
struct V_3 * V_185 ;
struct V_186 * V_187 ;
unsigned long V_16 ;
V_22 = F_3 ( V_7 ) ;
if ( ! V_22 )
return;
V_185 = F_6 ( V_22 ) ;
if ( V_183 -> V_188 == V_189 ) {
T_1 V_190 ;
V_190 = * ( T_1 * ) ( ( void * ) V_183 + V_183 ->
V_191 ) / 10000 ;
V_185 -> V_190 = V_190 ;
return;
}
if ( V_183 -> V_188 != V_192 &&
V_183 -> V_188 != V_193 &&
V_183 -> V_188 != V_194 )
return;
if ( V_22 -> V_195 != V_196 )
return;
V_187 = F_66 ( sizeof( * V_187 ) , V_197 ) ;
if ( ! V_187 )
return;
V_187 -> V_187 = V_183 -> V_188 ;
F_67 ( & V_185 -> V_198 , V_16 ) ;
F_68 ( & V_187 -> V_199 , & V_185 -> V_200 ) ;
F_69 ( & V_185 -> V_198 , V_16 ) ;
F_70 ( & V_185 -> V_201 , 0 ) ;
}
static struct V_53 * F_71 ( struct V_9 * V_22 ,
struct V_75 * V_76 ,
struct V_108 * V_109 ,
void * V_79 , T_2 V_134 )
{
struct V_53 * V_54 ;
V_54 = F_72 ( V_22 , V_76 -> V_121 ) ;
if ( ! V_54 )
return V_54 ;
memcpy ( F_73 ( V_54 , V_76 -> V_121 ) , V_79 ,
V_76 -> V_121 ) ;
V_54 -> V_97 = F_74 ( V_54 , V_22 ) ;
F_75 ( V_54 ) ;
if ( V_109 && ( V_22 -> V_202 & V_203 ) ) {
if ( V_109 -> V_204 . V_205 ||
V_109 -> V_204 . V_206 )
V_54 -> V_159 = V_207 ;
}
if ( V_134 & V_208 )
F_76 ( V_54 , F_39 ( V_209 ) ,
V_134 ) ;
return V_54 ;
}
int F_77 ( struct V_6 * V_7 ,
struct V_75 * V_76 ,
void * * V_79 ,
struct V_108 * V_109 ,
struct V_32 * V_210 ,
T_2 V_134 )
{
struct V_9 * V_22 = F_3 ( V_7 ) ;
struct V_3 * V_23 = F_6 ( V_22 ) ;
struct V_9 * V_211 ;
struct V_53 * V_54 ;
struct V_168 * V_212 ;
if ( V_22 -> V_195 != V_196 )
return V_213 ;
V_211 = F_78 ( V_23 -> V_211 ) ;
if ( V_211 && ( V_211 -> V_16 & V_214 ) )
V_22 = V_211 ;
V_54 = F_71 ( V_22 , V_76 , V_109 , * V_79 , V_134 ) ;
if ( F_44 ( ! V_54 ) ) {
++ V_22 -> V_178 . V_215 ;
return V_213 ;
}
if ( V_22 != V_211 )
F_79 ( V_54 ,
V_210 -> V_216 . V_217 . V_218 ) ;
V_212 = F_61 ( V_23 -> V_212 ) ;
F_62 ( & V_212 -> V_170 ) ;
V_212 -> V_171 ++ ;
V_212 -> V_71 += V_76 -> V_121 ;
if ( V_54 -> V_42 == V_219 )
++ V_212 -> V_220 ;
else if ( V_54 -> V_42 == V_221 )
++ V_212 -> V_222 ;
F_63 ( & V_212 -> V_170 ) ;
F_80 ( V_54 ) ;
return 0 ;
}
static void F_81 ( struct V_9 * V_22 ,
struct V_223 * V_224 )
{
F_82 ( V_224 -> V_225 , V_226 , sizeof( V_224 -> V_225 ) ) ;
F_82 ( V_224 -> V_227 , L_4 , sizeof( V_224 -> V_227 ) ) ;
}
static void F_83 ( struct V_9 * V_22 ,
struct V_228 * V_210 )
{
struct V_3 * V_23 = F_6 ( V_22 ) ;
struct V_11 * V_12 = V_23 -> V_12 ;
if ( V_12 ) {
V_210 -> V_229 = V_12 -> V_230 ;
V_210 -> V_231 = V_12 -> V_34 ;
}
}
static int F_84 ( struct V_9 * V_22 ,
struct V_228 * V_232 )
{
struct V_3 * V_23 = F_6 ( V_22 ) ;
struct V_6 * V_233 = V_23 -> V_8 ;
struct V_11 * V_12 = V_23 -> V_12 ;
struct V_234 V_235 ;
T_1 V_34 ;
T_1 V_230 ;
int V_24 = 0 ;
bool V_236 = false ;
if ( V_23 -> V_237 || ! V_12 || V_12 -> V_238 )
return - V_239 ;
V_34 = V_12 -> V_34 ;
V_230 = F_85 ( T_1 , V_12 -> V_230 , F_86 () ) ;
if ( V_12 -> V_240 < V_241 ) {
F_87 ( L_5 ) ;
return - V_242 ;
}
if ( ! V_232 ||
V_232 -> V_243 ||
V_232 -> V_244 ||
V_232 -> V_245 ||
( V_232 -> V_231 < 1 ) )
return - V_242 ;
if ( V_232 -> V_231 > V_230 ) {
F_87 ( L_6 , V_230 ) ;
V_232 -> V_231 = V_230 ;
}
V_24 = F_15 ( V_22 ) ;
if ( V_24 )
goto V_246;
V_247:
V_23 -> V_237 = true ;
F_88 ( V_233 ) ;
V_12 -> V_34 = V_232 -> V_231 ;
memset ( & V_235 , 0 , sizeof( V_235 ) ) ;
V_235 . V_34 = V_12 -> V_34 ;
V_235 . V_248 = V_248 ;
V_235 . V_249 = V_249 ;
V_24 = F_89 ( V_233 , & V_235 ) ;
if ( V_24 ) {
if ( V_236 ) {
F_12 ( V_22 , L_7 , V_24 ) ;
return V_24 ;
}
goto V_250;
}
V_12 = V_23 -> V_12 ;
V_24 = F_90 ( V_22 , V_12 -> V_34 ) ;
if ( V_24 ) {
if ( V_236 ) {
F_12 ( V_22 , L_8 , V_24 ) ;
return V_24 ;
}
goto V_250;
}
V_24 = F_91 ( V_22 , V_12 -> V_34 ) ;
if ( V_24 ) {
if ( V_236 ) {
F_12 ( V_22 , L_9 , V_24 ) ;
return V_24 ;
}
goto V_250;
}
V_246:
F_8 ( V_22 ) ;
V_23 -> V_237 = false ;
F_70 ( & V_23 -> V_201 , 0 ) ;
return V_24 ;
V_250:
F_12 ( V_22 , L_10 ) ;
V_236 = true ;
V_232 -> V_231 = V_34 ;
goto V_247;
}
static bool F_92 ( const struct V_251 * V_252 )
{
struct V_251 V_253 = * V_252 ;
struct V_251 V_254 = {} ;
F_93 ( & V_253 , 0 ) ;
V_253 . V_255 = 0 ;
V_253 . V_256 = 0 ;
V_253 . V_252 = 0 ;
V_254 . V_257 = V_258 ;
return ! memcmp ( & V_253 , & V_254 , sizeof( V_253 ) ) ;
}
static void F_94 ( struct V_9 * V_233 )
{
struct V_3 * V_259 = F_6 ( V_233 ) ;
V_259 -> V_190 = V_260 ;
V_259 -> V_255 = V_261 ;
}
static int F_95 ( struct V_9 * V_233 , struct V_251 * V_252 )
{
struct V_3 * V_259 = F_6 ( V_233 ) ;
F_93 ( V_252 , V_259 -> V_190 ) ;
V_252 -> V_255 = V_259 -> V_255 ;
V_252 -> V_257 = V_258 ;
return 0 ;
}
static int F_96 ( struct V_9 * V_233 , struct V_251 * V_252 )
{
struct V_3 * V_259 = F_6 ( V_233 ) ;
T_1 V_190 ;
V_190 = F_97 ( V_252 ) ;
if ( ! F_98 ( V_190 ) ||
! F_99 ( V_252 -> V_255 ) ||
! F_92 ( V_252 ) )
return - V_242 ;
V_259 -> V_190 = V_190 ;
V_259 -> V_255 = V_252 -> V_255 ;
return 0 ;
}
static int F_100 ( struct V_9 * V_10 , int V_262 )
{
struct V_3 * V_4 = F_6 ( V_10 ) ;
struct V_11 * V_12 = V_4 -> V_12 ;
struct V_6 * V_263 = V_4 -> V_8 ;
struct V_234 V_235 ;
int V_264 = V_265 ;
T_1 V_34 ;
int V_24 = 0 ;
if ( V_4 -> V_237 || ! V_12 || V_12 -> V_238 )
return - V_239 ;
if ( V_12 -> V_240 >= V_266 )
V_264 = V_267 - V_268 ;
if ( V_262 < V_269 || V_262 > V_264 )
return - V_242 ;
V_24 = F_15 ( V_10 ) ;
if ( V_24 )
goto V_246;
V_34 = V_12 -> V_34 ;
V_4 -> V_237 = true ;
F_88 ( V_263 ) ;
V_10 -> V_262 = V_262 ;
memset ( & V_235 , 0 , sizeof( V_235 ) ) ;
V_235 . V_248 = V_248 ;
V_235 . V_34 = V_34 ;
V_235 . V_249 = V_249 ;
F_89 ( V_263 , & V_235 ) ;
V_246:
F_8 ( V_10 ) ;
V_4 -> V_237 = false ;
F_70 ( & V_4 -> V_201 , 0 ) ;
return V_24 ;
}
static struct V_270 * F_101 ( struct V_9 * V_22 ,
struct V_270 * V_271 )
{
struct V_3 * V_185 = F_6 ( V_22 ) ;
int V_272 ;
F_102 (cpu) {
struct V_168 * V_169 = F_103 ( V_185 -> V_169 ,
V_272 ) ;
struct V_168 * V_212 = F_103 ( V_185 -> V_212 ,
V_272 ) ;
T_5 V_273 , V_274 , V_275 , V_276 , V_277 ;
unsigned int V_278 ;
do {
V_278 = F_104 ( & V_169 -> V_170 ) ;
V_273 = V_169 -> V_171 ;
V_274 = V_169 -> V_71 ;
} while ( F_105 ( & V_169 -> V_170 , V_278 ) );
do {
V_278 = F_104 ( & V_212 -> V_170 ) ;
V_275 = V_212 -> V_171 ;
V_276 = V_212 -> V_71 ;
V_277 = V_212 -> V_222 + V_212 -> V_220 ;
} while ( F_105 ( & V_212 -> V_170 , V_278 ) );
V_271 -> V_274 += V_274 ;
V_271 -> V_273 += V_273 ;
V_271 -> V_276 += V_276 ;
V_271 -> V_275 += V_275 ;
V_271 -> V_222 += V_277 ;
}
V_271 -> V_179 = V_22 -> V_178 . V_179 ;
V_271 -> V_279 = V_22 -> V_178 . V_179 ;
V_271 -> V_215 = V_22 -> V_178 . V_215 ;
V_271 -> V_280 = V_22 -> V_178 . V_280 ;
return V_271 ;
}
static int F_106 ( struct V_9 * V_10 , void * V_281 )
{
struct V_282 * V_283 = V_281 ;
char V_284 [ V_285 ] ;
unsigned char V_286 ;
int V_287 ;
memcpy ( V_284 , V_10 -> V_288 , V_285 ) ;
V_286 = V_10 -> V_289 ;
V_287 = F_107 ( V_10 , V_281 ) ;
if ( V_287 != 0 )
return V_287 ;
V_287 = F_108 ( V_10 , V_283 -> V_290 ) ;
if ( V_287 != 0 ) {
memcpy ( V_10 -> V_288 , V_284 , V_285 ) ;
V_10 -> V_289 = V_286 ;
}
return V_287 ;
}
static int F_109 ( struct V_9 * V_233 , int V_291 )
{
switch ( V_291 ) {
case V_292 :
return F_110 ( V_168 ) ;
default:
return - V_242 ;
}
}
static void F_111 ( struct V_9 * V_233 ,
struct V_293 * V_178 , T_5 * V_79 )
{
struct V_3 * V_259 = F_6 ( V_233 ) ;
const void * V_294 = & V_259 -> V_114 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < F_110 ( V_168 ) ; V_28 ++ )
V_79 [ V_28 ] = * ( unsigned long * ) ( V_294 + V_168 [ V_28 ] . V_64 ) ;
}
static void F_112 ( struct V_9 * V_233 , T_1 V_295 , T_6 * V_79 )
{
int V_28 ;
switch ( V_295 ) {
case V_292 :
for ( V_28 = 0 ; V_28 < F_110 ( V_168 ) ; V_28 ++ )
memcpy ( V_79 + V_28 * V_296 ,
V_168 [ V_28 ] . V_297 , V_296 ) ;
break;
}
}
static void F_113 ( struct V_9 * V_22 )
{
}
static void F_114 ( struct V_1 * V_2 )
{
struct V_3 * V_185 =
F_2 ( V_2 , struct V_3 , V_201 . V_5 ) ;
struct V_6 * V_7 = V_185 -> V_8 ;
struct V_9 * V_22 = F_3 ( V_7 ) ;
struct V_11 * V_9 ;
struct V_13 * V_14 ;
struct V_186 * V_187 = NULL ;
bool V_298 = false , V_299 = false ;
unsigned long V_16 , V_300 , V_301 ;
F_115 () ;
if ( V_185 -> V_237 )
goto V_302;
V_9 = V_185 -> V_12 ;
V_14 = V_9 -> V_15 ;
V_300 = V_185 -> V_303 + V_304 ;
if ( F_116 ( V_300 ) ) {
V_301 = V_300 - V_305 ;
V_301 = V_301 < V_304 ? V_301 : V_304 ;
F_70 ( & V_185 -> V_201 , V_301 ) ;
goto V_302;
}
V_185 -> V_303 = V_305 ;
F_67 ( & V_185 -> V_198 , V_16 ) ;
if ( ! F_117 ( & V_185 -> V_200 ) ) {
V_187 = F_118 ( & V_185 -> V_200 ,
struct V_186 , V_199 ) ;
F_119 ( & V_187 -> V_199 ) ;
V_299 = ! F_117 ( & V_185 -> V_200 ) ;
}
F_69 ( & V_185 -> V_198 , V_16 ) ;
if ( ! V_187 )
goto V_302;
switch ( V_187 -> V_187 ) {
case V_193 :
if ( V_14 -> V_25 ) {
V_14 -> V_25 = false ;
F_14 ( V_22 ) ;
F_13 ( V_22 ) ;
} else {
V_298 = true ;
}
F_120 ( V_187 ) ;
break;
case V_194 :
if ( ! V_14 -> V_25 ) {
V_14 -> V_25 = true ;
F_10 ( V_22 ) ;
F_121 ( V_22 ) ;
}
F_120 ( V_187 ) ;
break;
case V_192 :
if ( ! V_14 -> V_25 ) {
V_14 -> V_25 = true ;
F_10 ( V_22 ) ;
F_121 ( V_22 ) ;
V_187 -> V_187 = V_193 ;
F_67 ( & V_185 -> V_198 , V_16 ) ;
F_122 ( & V_187 -> V_199 , & V_185 -> V_200 ) ;
F_69 ( & V_185 -> V_198 , V_16 ) ;
V_299 = true ;
}
break;
}
F_123 () ;
if ( V_298 )
F_124 ( V_22 ) ;
if ( V_299 )
F_70 ( & V_185 -> V_201 , V_304 ) ;
return;
V_302:
F_123 () ;
}
static void F_125 ( struct V_9 * V_306 )
{
struct V_3 * V_23 = F_6 ( V_306 ) ;
F_126 ( V_23 -> V_169 ) ;
F_126 ( V_23 -> V_212 ) ;
F_127 ( V_306 ) ;
}
static struct V_9 * F_128 ( const T_6 * V_307 )
{
struct V_9 * V_233 ;
F_129 () ;
F_130 (&init_net, dev) {
if ( V_233 -> V_308 != & V_309 )
continue;
if ( F_131 ( V_307 , V_233 -> V_310 ) )
return V_233 ;
}
return NULL ;
}
static struct V_9 * F_132 ( struct V_9 * V_211 )
{
struct V_9 * V_233 ;
F_129 () ;
F_130 (&init_net, dev) {
struct V_3 * V_23 ;
if ( V_233 -> V_308 != & V_309 )
continue;
V_23 = F_6 ( V_233 ) ;
if ( V_23 -> V_12 == NULL )
continue;
if ( F_133 ( V_23 -> V_211 ) == V_211 )
return V_233 ;
}
return NULL ;
}
static int F_134 ( struct V_9 * V_211 )
{
struct V_9 * V_10 ;
struct V_3 * V_23 ;
struct V_11 * V_311 ;
if ( V_211 -> V_312 != V_285 )
return V_313 ;
V_10 = F_128 ( V_211 -> V_310 ) ;
if ( ! V_10 )
return V_313 ;
V_23 = F_6 ( V_10 ) ;
V_311 = V_23 -> V_12 ;
if ( ! V_311 || F_133 ( V_23 -> V_211 ) )
return V_313 ;
F_135 ( V_10 , L_11 , V_211 -> V_297 ) ;
F_136 ( V_314 ) ;
F_137 ( V_211 ) ;
F_138 ( V_23 -> V_211 , V_211 ) ;
return V_315 ;
}
static int F_139 ( struct V_9 * V_211 )
{
struct V_9 * V_10 ;
struct V_11 * V_311 ;
struct V_3 * V_23 ;
V_10 = F_132 ( V_211 ) ;
if ( ! V_10 )
return V_313 ;
V_23 = F_6 ( V_10 ) ;
V_311 = V_23 -> V_12 ;
F_135 ( V_10 , L_12 , V_211 -> V_297 ) ;
F_11 ( V_311 ) ;
F_140 ( V_10 , true ) ;
F_135 ( V_10 , L_13 , V_211 -> V_297 ) ;
F_10 ( V_10 ) ;
F_141 ( V_316 , V_211 ) ;
return V_315 ;
}
static int F_142 ( struct V_9 * V_211 )
{
struct V_9 * V_10 ;
struct V_11 * V_311 ;
struct V_3 * V_23 ;
V_10 = F_132 ( V_211 ) ;
if ( ! V_10 )
return V_313 ;
V_23 = F_6 ( V_10 ) ;
V_311 = V_23 -> V_12 ;
F_135 ( V_10 , L_14 , V_211 -> V_297 ) ;
F_140 ( V_10 , false ) ;
F_135 ( V_10 , L_15 , V_211 -> V_297 ) ;
F_18 ( V_311 ) ;
F_14 ( V_10 ) ;
F_141 ( V_316 , V_10 ) ;
return V_315 ;
}
static int F_143 ( struct V_9 * V_211 )
{
struct V_9 * V_10 ;
struct V_11 * V_311 ;
struct V_3 * V_23 ;
V_10 = F_132 ( V_211 ) ;
if ( ! V_10 )
return V_313 ;
V_23 = F_6 ( V_10 ) ;
V_311 = V_23 -> V_12 ;
F_135 ( V_10 , L_16 , V_211 -> V_297 ) ;
F_144 ( V_23 -> V_211 , NULL ) ;
F_145 ( V_211 ) ;
F_146 ( V_314 ) ;
return V_315 ;
}
static int F_147 ( struct V_6 * V_233 ,
const struct V_317 * V_318 )
{
struct V_9 * V_22 = NULL ;
struct V_3 * V_23 ;
struct V_234 V_235 ;
struct V_11 * V_12 ;
int V_24 ;
V_22 = F_148 ( sizeof( struct V_3 ) ,
F_86 () ) ;
if ( ! V_22 )
return - V_319 ;
F_10 ( V_22 ) ;
F_94 ( V_22 ) ;
V_23 = F_6 ( V_22 ) ;
V_23 -> V_8 = V_233 ;
V_23 -> V_320 = F_149 ( V_321 , V_322 ) ;
if ( F_150 ( V_23 ) )
F_151 ( V_22 , L_17 ,
V_23 -> V_320 ) ;
V_23 -> V_169 = F_152 ( struct V_168 ) ;
if ( ! V_23 -> V_169 ) {
F_127 ( V_22 ) ;
return - V_319 ;
}
V_23 -> V_212 = F_152 ( struct V_168 ) ;
if ( ! V_23 -> V_212 ) {
F_126 ( V_23 -> V_169 ) ;
F_127 ( V_22 ) ;
return - V_319 ;
}
F_153 ( V_233 , V_22 ) ;
V_23 -> V_237 = false ;
F_154 ( & V_23 -> V_201 , F_114 ) ;
F_155 ( & V_23 -> V_5 , F_1 ) ;
F_156 ( & V_23 -> V_198 ) ;
F_157 ( & V_23 -> V_200 ) ;
V_22 -> V_308 = & V_309 ;
V_22 -> V_323 = V_324 ;
V_22 -> V_202 = V_324 | V_325 ;
V_22 -> V_326 = & V_326 ;
F_158 ( V_22 , & V_233 -> V_327 ) ;
V_22 -> V_328 = V_119 ;
memset ( & V_235 , 0 , sizeof( V_235 ) ) ;
V_235 . V_248 = V_248 ;
V_235 . V_249 = V_249 ;
V_24 = F_89 ( V_233 , & V_235 ) ;
if ( V_24 != 0 ) {
F_12 ( V_22 , L_7 , V_24 ) ;
F_125 ( V_22 ) ;
F_153 ( V_233 , NULL ) ;
return V_24 ;
}
memcpy ( V_22 -> V_288 , V_235 . V_329 , V_285 ) ;
V_12 = V_23 -> V_12 ;
F_90 ( V_22 , V_12 -> V_34 ) ;
F_91 ( V_22 , V_12 -> V_34 ) ;
F_159 ( V_22 , V_330 ) ;
V_24 = F_160 ( V_22 ) ;
if ( V_24 != 0 ) {
F_161 ( L_18 ) ;
F_88 ( V_233 ) ;
F_125 ( V_22 ) ;
}
return V_24 ;
}
static int F_162 ( struct V_6 * V_233 )
{
struct V_9 * V_22 ;
struct V_3 * V_185 ;
struct V_11 * V_9 ;
V_22 = F_3 ( V_233 ) ;
if ( V_22 == NULL ) {
F_163 ( & V_233 -> V_327 , L_19 ) ;
return 0 ;
}
V_185 = F_6 ( V_22 ) ;
V_9 = V_185 -> V_12 ;
F_115 () ;
V_185 -> V_237 = true ;
F_123 () ;
F_164 ( & V_185 -> V_201 ) ;
F_17 ( & V_185 -> V_5 ) ;
F_16 ( V_22 ) ;
F_165 ( V_22 ) ;
F_88 ( V_233 ) ;
F_153 ( V_233 , NULL ) ;
F_125 ( V_22 ) ;
return 0 ;
}
static int F_166 ( struct V_331 * V_332 ,
unsigned long V_187 , void * V_333 )
{
struct V_9 * V_334 = F_167 ( V_333 ) ;
if ( V_334 -> V_308 == & V_309 )
return V_313 ;
if ( V_334 -> type != V_335 )
return V_313 ;
if ( V_334 -> V_336 & V_337 )
return V_313 ;
if ( ( V_334 -> V_336 & V_338 ) &&
( V_334 -> V_16 & V_339 ) )
return V_313 ;
switch ( V_187 ) {
case V_340 :
return F_134 ( V_334 ) ;
case V_341 :
return F_143 ( V_334 ) ;
case V_342 :
return F_139 ( V_334 ) ;
case V_343 :
return F_142 ( V_334 ) ;
default:
return V_313 ;
}
}
static void T_7 F_168 ( void )
{
F_169 ( & V_344 ) ;
F_170 ( & V_345 ) ;
}
static int T_8 F_171 ( void )
{
int V_24 ;
if ( V_248 < V_346 ) {
V_248 = V_346 ;
F_87 ( L_20 ,
V_248 ) ;
}
V_24 = F_172 ( & V_345 ) ;
if ( V_24 )
return V_24 ;
F_173 ( & V_344 ) ;
return 0 ;
}
