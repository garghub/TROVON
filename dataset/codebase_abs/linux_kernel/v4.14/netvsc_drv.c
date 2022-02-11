static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 -> V_6 ) ;
F_4 ( V_6 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_7 = F_2 ( V_2 ) ;
struct V_1 * V_8 = F_3 ( V_7 -> V_8 ) ;
struct V_5 * V_6 = F_3 ( V_7 -> V_6 ) ;
struct V_9 * V_10 ;
int V_11 = 0 ;
F_6 ( V_2 ) ;
V_11 = F_7 ( V_6 ) ;
if ( V_11 != 0 ) {
F_8 ( V_2 , L_1 , V_11 ) ;
return V_11 ;
}
F_9 ( V_2 ) ;
V_10 = V_6 -> V_12 ;
if ( ! V_10 -> V_13 )
F_10 ( V_2 ) ;
if ( V_8 ) {
V_11 = F_11 ( V_8 ) ;
if ( V_11 )
F_12 ( V_2 ,
L_2 ,
V_8 -> V_14 , V_11 ) ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_8
= F_3 ( V_4 -> V_8 ) ;
struct V_5 * V_6 = F_3 ( V_4 -> V_6 ) ;
int V_11 = 0 ;
T_1 V_15 , V_16 , V_17 = 10 , V_18 = 0 , V_19 = 20 ;
struct V_20 * V_21 ;
F_14 ( V_2 ) ;
if ( ! V_6 )
goto V_22;
V_11 = F_15 ( V_6 ) ;
if ( V_11 != 0 ) {
F_8 ( V_2 , L_3 , V_11 ) ;
return V_11 ;
}
while ( true ) {
V_15 = 0 ;
for ( V_16 = 0 ; V_16 < V_6 -> V_23 ; V_16 ++ ) {
V_21 = V_6 -> V_24 [ V_16 ] . V_25 ;
if ( ! V_21 )
continue;
V_15 = F_16 ( & V_21 -> V_26 ) ;
if ( V_15 )
break;
V_15 = F_16 ( & V_21 -> V_27 ) ;
if ( V_15 )
break;
}
V_18 ++ ;
if ( V_18 > V_19 || V_15 == 0 )
break;
F_17 ( V_17 ) ;
if ( V_17 < 1000 )
V_17 *= 2 ;
}
if ( V_15 ) {
F_8 ( V_2 , L_4 ) ;
V_11 = - V_28 ;
}
V_22:
if ( V_8 )
F_18 ( V_8 ) ;
return V_11 ;
}
static void * F_19 ( struct V_29 * V_30 , T_1 V_31 ,
int V_32 )
{
struct V_33 * V_34 ;
struct V_35 * V_36 ;
V_34 = & V_30 -> V_30 . V_37 ;
V_34 -> V_38 += V_31 ;
V_36 = (struct V_35 * ) ( ( void * ) V_34 +
V_34 -> V_39 + V_34 -> V_40 ) ;
V_36 -> V_41 = V_31 ;
V_36 -> type = V_32 ;
V_36 -> V_42 = sizeof( struct V_35 ) ;
V_34 -> V_40 += V_31 ;
return V_36 ;
}
static inline T_1 F_20 (
struct V_43 * V_44 ,
const struct V_3 * V_45 )
{
struct V_46 V_47 ;
T_1 V_48 ;
static T_1 T_2 V_49 ;
F_21 ( & T_2 , sizeof( T_2 ) ) ;
if ( ! F_22 ( V_44 , & V_47 , 0 ) )
return 0 ;
if ( V_47 . V_50 . V_51 == V_52 ||
( V_47 . V_50 . V_51 == V_53 &&
( ( V_47 . V_50 . V_54 == F_23 ( V_55 ) && V_45 -> V_56 ) ||
( V_47 . V_50 . V_54 == F_23 ( V_57 ) &&
V_45 -> V_58 ) ) ) ) {
return F_24 ( V_44 ) ;
} else {
if ( V_47 . V_50 . V_54 == F_23 ( V_55 ) )
V_48 = F_25 ( ( T_1 * ) & V_47 . V_59 . V_60 , 2 , T_2 ) ;
else if ( V_47 . V_50 . V_54 == F_23 ( V_57 ) )
V_48 = F_25 ( ( T_1 * ) & V_47 . V_59 . V_61 , 8 , T_2 ) ;
else
V_48 = 0 ;
F_26 ( V_44 , V_48 , V_62 ) ;
}
return V_48 ;
}
static inline int F_27 ( struct V_1 * V_63 ,
struct V_43 * V_44 , int V_64 )
{
const struct V_3 * V_45 = F_2 ( V_63 ) ;
struct V_65 * V_66 = V_44 -> V_66 ;
int V_67 ;
V_67 = V_45 -> V_68 [ F_20 ( V_44 , V_45 ) &
( V_69 - 1 ) ] ;
if ( V_67 != V_64 &&
V_66 && F_28 ( V_66 ) && F_29 ( V_66 -> V_70 ) )
F_30 ( V_66 , V_67 ) ;
return V_67 ;
}
static T_3 F_31 ( struct V_1 * V_63 , struct V_43 * V_44 )
{
int V_67 = F_32 ( V_44 -> V_66 ) ;
if ( V_67 < 0 || V_44 -> V_71 || V_67 >= V_63 -> V_72 ) {
if ( F_33 ( V_44 ) )
V_67 = F_34 ( V_44 ) ;
else
V_67 = F_27 ( V_63 , V_44 , V_67 ) ;
}
return V_67 ;
}
static T_3 F_35 ( struct V_1 * V_63 , struct V_43 * V_44 ,
void * V_73 ,
T_4 V_74 )
{
struct V_3 * V_45 = F_2 ( V_63 ) ;
struct V_1 * V_8 ;
T_3 V_75 ;
F_36 () ;
V_8 = F_37 ( V_45 -> V_8 ) ;
if ( V_8 ) {
V_75 = F_33 ( V_44 ) ? F_34 ( V_44 ) : 0 ;
F_38 ( V_44 ) -> V_76 = V_44 -> V_77 ;
} else {
V_75 = F_31 ( V_63 , V_44 ) ;
}
F_39 () ;
while ( F_40 ( V_75 >= V_63 -> V_72 ) )
V_75 -= V_63 -> V_72 ;
return V_75 ;
}
static T_1 F_41 ( struct V_78 * V_78 , T_1 V_79 , T_1 V_80 ,
struct V_81 * V_82 )
{
int V_83 = 0 ;
V_78 += ( V_79 >> V_84 ) ;
V_79 &= ~ V_85 ;
while ( V_80 > 0 ) {
unsigned long V_86 ;
V_86 = V_87 - V_79 ;
if ( V_86 > V_80 )
V_86 = V_80 ;
V_82 [ V_83 ] . V_88 = F_42 ( V_78 ) ;
V_82 [ V_83 ] . V_79 = V_79 ;
V_82 [ V_83 ] . V_80 = V_86 ;
V_79 += V_86 ;
V_80 -= V_86 ;
if ( V_79 == V_87 && V_80 ) {
V_78 ++ ;
V_79 = 0 ;
V_83 ++ ;
}
}
return V_83 + 1 ;
}
static T_1 F_43 ( void * V_89 , T_1 V_80 , struct V_43 * V_44 ,
struct V_90 * V_91 ,
struct V_81 * V_82 )
{
T_1 V_92 = 0 ;
char * V_93 = V_44 -> V_93 ;
int V_94 = F_44 ( V_44 ) -> V_95 ;
int V_16 ;
V_92 += F_41 ( F_45 ( V_89 ) ,
F_46 ( V_89 ) ,
V_80 , & V_82 [ V_92 ] ) ;
V_91 -> V_96 = V_80 ;
V_91 -> V_97 = V_92 ;
V_92 += F_41 ( F_45 ( V_93 ) ,
F_46 ( V_93 ) ,
F_47 ( V_44 ) , & V_82 [ V_92 ] ) ;
for ( V_16 = 0 ; V_16 < V_94 ; V_16 ++ ) {
T_5 * V_98 = F_44 ( V_44 ) -> V_94 + V_16 ;
V_92 += F_41 ( F_48 ( V_98 ) ,
V_98 -> V_99 ,
F_49 ( V_98 ) , & V_82 [ V_92 ] ) ;
}
return V_92 ;
}
static int F_50 ( struct V_43 * V_44 )
{
int V_16 , V_94 = F_44 ( V_44 ) -> V_95 ;
int V_100 = 0 ;
for ( V_16 = 0 ; V_16 < V_94 ; V_16 ++ ) {
T_5 * V_98 = F_44 ( V_44 ) -> V_94 + V_16 ;
unsigned long V_41 = F_49 ( V_98 ) ;
unsigned long V_79 = V_98 -> V_99 ;
V_79 &= ~ V_85 ;
V_100 += F_51 ( V_79 + V_41 ) ;
}
return V_100 ;
}
static int F_52 ( struct V_43 * V_44 )
{
char * V_93 = V_44 -> V_93 ;
unsigned int V_79 = F_46 ( V_93 ) ;
unsigned int V_80 = F_47 ( V_44 ) ;
int V_101 ;
int V_102 ;
V_101 = F_53 ( V_79 + V_80 , V_87 ) ;
V_102 = F_50 ( V_44 ) ;
return V_101 + V_102 ;
}
static T_1 F_54 ( struct V_43 * V_44 )
{
if ( V_44 -> V_103 == F_23 ( V_55 ) ) {
struct V_104 * V_105 = F_55 ( V_44 ) ;
if ( V_105 -> V_103 == V_52 )
return V_106 ;
else if ( V_105 -> V_103 == V_53 )
return V_107 ;
} else {
struct V_108 * V_109 = F_56 ( V_44 ) ;
if ( V_109 -> V_110 == V_52 )
return V_111 ;
else if ( V_109 -> V_110 == V_53 )
return V_112 ;
}
return V_113 ;
}
static int F_57 ( struct V_1 * V_2 , struct V_1 * V_8 ,
struct V_43 * V_44 )
{
struct V_3 * V_7 = F_2 ( V_2 ) ;
unsigned int V_80 = V_44 -> V_80 ;
int V_114 ;
V_44 -> V_115 = V_8 ;
V_44 -> V_77 = F_38 ( V_44 ) -> V_76 ;
V_114 = F_58 ( V_44 ) ;
if ( F_59 ( V_114 == V_116 || V_114 == V_117 ) ) {
struct V_118 * V_119
= F_60 ( V_7 -> V_120 ) ;
F_61 ( & V_119 -> V_121 ) ;
V_119 -> V_122 ++ ;
V_119 -> V_123 += V_80 ;
F_62 ( & V_119 -> V_121 ) ;
} else {
F_63 ( V_7 -> V_120 -> V_124 ) ;
}
return V_114 ;
}
static int F_64 ( struct V_43 * V_44 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_90 * V_91 = NULL ;
int V_11 ;
unsigned int V_125 ;
struct V_29 * V_126 ;
struct V_33 * V_34 ;
struct V_1 * V_8 ;
T_1 V_127 ;
struct V_35 * V_36 ;
T_1 V_48 ;
struct V_81 V_82 [ V_128 ] ;
V_8 = F_65 ( V_4 -> V_8 ) ;
if ( V_8 && F_66 ( V_8 ) &&
! F_67 ( V_2 ) )
return F_57 ( V_2 , V_8 , V_44 ) ;
V_125 = F_52 ( V_44 ) + 2 ;
if ( F_40 ( V_125 > V_128 ) ) {
++ V_4 -> V_129 . V_130 ;
if ( F_68 ( V_44 ) )
goto V_131;
V_125 = F_52 ( V_44 ) + 2 ;
if ( V_125 > V_128 ) {
++ V_4 -> V_129 . V_132 ;
goto V_133;
}
}
V_11 = F_69 ( V_44 , V_134 ) ;
if ( V_11 )
goto V_131;
F_70 ( sizeof( struct V_90 ) >
F_71 ( struct V_43 , V_135 ) ) ;
V_91 = (struct V_90 * ) V_44 -> V_135 ;
V_91 -> V_67 = F_72 ( V_44 ) ;
V_91 -> V_136 = V_44 -> V_80 ;
V_91 -> V_137 = V_44 -> V_80 ;
V_91 -> V_138 = 1 ;
V_126 = (struct V_29 * ) V_44 -> V_139 ;
memset ( V_126 , 0 , V_134 ) ;
V_126 -> V_140 = V_141 ;
V_126 -> V_142 = V_91 -> V_136 ;
V_34 = & V_126 -> V_30 . V_37 ;
V_34 -> V_38 = sizeof( struct V_33 ) ;
V_34 -> V_143 = V_91 -> V_136 ;
V_34 -> V_39 = sizeof( struct V_33 ) ;
V_127 = F_73 ( struct V_33 ) ;
V_48 = F_74 ( V_44 ) ;
if ( V_48 != 0 && V_2 -> V_72 > 1 ) {
V_127 += V_144 ;
V_36 = F_19 ( V_126 , V_144 ,
V_145 ) ;
* ( T_1 * ) ( ( void * ) V_36 + V_36 -> V_42 ) = V_48 ;
}
if ( F_75 ( V_44 ) ) {
struct V_146 * V_147 ;
V_127 += V_148 ;
V_36 = F_19 ( V_126 , V_148 ,
V_149 ) ;
V_147 = ( void * ) V_36 + V_36 -> V_42 ;
V_147 -> V_150 = V_44 -> V_151 & V_152 ;
V_147 -> V_153 = ( V_44 -> V_151 & V_154 ) >>
V_155 ;
}
if ( F_76 ( V_44 ) ) {
struct V_156 * V_157 ;
V_127 += V_158 ;
V_36 = F_19 ( V_126 , V_158 ,
V_159 ) ;
V_157 = ( void * ) V_36 + V_36 -> V_42 ;
V_157 -> V_160 . type = V_161 ;
if ( V_44 -> V_103 == F_23 ( V_55 ) ) {
V_157 -> V_160 . V_162 =
V_163 ;
F_55 ( V_44 ) -> V_164 = 0 ;
F_55 ( V_44 ) -> V_165 = 0 ;
F_77 ( V_44 ) -> V_165 =
~ F_78 ( F_55 ( V_44 ) -> V_166 ,
F_55 ( V_44 ) -> V_167 , 0 , V_52 , 0 ) ;
} else {
V_157 -> V_160 . V_162 =
V_168 ;
F_56 ( V_44 ) -> V_169 = 0 ;
F_77 ( V_44 ) -> V_165 =
~ F_79 ( & F_56 ( V_44 ) -> V_166 ,
& F_56 ( V_44 ) -> V_167 , 0 , V_52 , 0 ) ;
}
V_157 -> V_160 . V_170 = F_80 ( V_44 ) ;
V_157 -> V_160 . V_171 = F_44 ( V_44 ) -> V_172 ;
} else if ( V_44 -> V_173 == V_174 ) {
if ( F_54 ( V_44 ) & V_4 -> V_175 ) {
struct V_176 * V_177 ;
V_127 += V_178 ;
V_36 = F_19 ( V_126 , V_178 ,
V_179 ) ;
V_177 = (struct V_176 * ) ( ( void * ) V_36 +
V_36 -> V_42 ) ;
V_177 -> V_180 . V_170 = F_80 ( V_44 ) ;
if ( V_44 -> V_103 == F_23 ( V_55 ) ) {
V_177 -> V_180 . V_181 = 1 ;
if ( F_55 ( V_44 ) -> V_103 == V_52 )
V_177 -> V_180 . V_182 = 1 ;
else
V_177 -> V_180 . V_183 = 1 ;
} else {
V_177 -> V_180 . V_184 = 1 ;
if ( F_56 ( V_44 ) -> V_110 == V_52 )
V_177 -> V_180 . V_182 = 1 ;
else
V_177 -> V_180 . V_183 = 1 ;
}
} else {
if ( F_81 ( V_44 ) )
goto V_133;
}
}
V_126 -> V_142 += V_127 ;
V_91 -> V_136 = V_126 -> V_142 ;
V_91 -> V_185 = F_43 ( V_126 , V_127 ,
V_44 , V_91 , V_82 ) ;
F_82 ( V_44 ) ;
V_11 = F_83 ( V_4 , V_91 , V_126 , V_82 , V_44 ) ;
if ( F_59 ( V_11 == 0 ) )
return V_186 ;
if ( V_11 == - V_187 ) {
++ V_4 -> V_129 . V_188 ;
return V_189 ;
}
if ( V_11 == - V_190 )
++ V_4 -> V_129 . V_191 ;
V_133:
F_84 ( V_44 ) ;
V_2 -> V_192 . V_124 ++ ;
return V_186 ;
V_131:
++ V_4 -> V_129 . V_193 ;
goto V_133;
}
void F_85 ( struct V_194 * V_195 ,
struct V_29 * V_196 )
{
struct V_197 * V_198 = & V_196 -> V_30 . V_199 ;
struct V_1 * V_2 ;
struct V_3 * V_7 ;
struct V_200 * V_201 ;
unsigned long V_202 ;
V_2 = F_86 ( V_195 ) ;
if ( ! V_2 )
return;
V_7 = F_2 ( V_2 ) ;
if ( V_198 -> V_203 == V_204 ) {
T_1 V_205 ;
V_205 = * ( T_1 * ) ( ( void * ) V_198
+ V_198 -> V_206 ) / 10000 ;
V_7 -> V_205 = V_205 ;
return;
}
if ( V_198 -> V_203 != V_207 &&
V_198 -> V_203 != V_208 &&
V_198 -> V_203 != V_209 )
return;
if ( V_2 -> V_210 != V_211 )
return;
V_201 = F_87 ( sizeof( * V_201 ) , V_212 ) ;
if ( ! V_201 )
return;
V_201 -> V_201 = V_198 -> V_203 ;
F_88 ( & V_7 -> V_213 , V_202 ) ;
F_89 ( & V_201 -> V_214 , & V_7 -> V_215 ) ;
F_90 ( & V_7 -> V_213 , V_202 ) ;
F_91 ( & V_7 -> V_216 , 0 ) ;
}
static struct V_43 * F_92 ( struct V_1 * V_2 ,
struct V_217 * V_218 ,
const struct V_176 * V_177 ,
const struct V_146 * V_147 ,
void * V_93 , T_1 V_219 )
{
struct V_43 * V_44 ;
V_44 = F_93 ( V_218 , V_219 ) ;
if ( ! V_44 )
return V_44 ;
F_94 ( V_44 , V_93 , V_219 ) ;
V_44 -> V_103 = F_95 ( V_44 , V_2 ) ;
F_96 ( V_44 ) ;
if ( V_177 && ( V_2 -> V_220 & V_221 ) ) {
if ( V_177 -> V_222 . V_223 ||
V_177 -> V_222 . V_224 )
V_44 -> V_173 = V_225 ;
}
if ( V_147 ) {
T_3 V_151 = V_147 -> V_150 | ( V_147 -> V_153 << V_155 ) ;
F_97 ( V_44 , F_23 ( V_226 ) ,
V_151 ) ;
}
return V_44 ;
}
int F_98 ( struct V_1 * V_2 ,
struct V_20 * V_25 ,
void * V_93 , T_1 V_80 ,
const struct V_176 * V_177 ,
const struct V_146 * V_147 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_1 ;
T_3 V_67 = V_25 -> V_227 . V_228 . V_229 ;
struct V_230 * V_231 ;
struct V_43 * V_44 ;
struct V_232 * V_233 ;
if ( V_2 -> V_210 != V_211 )
return V_234 ;
F_36 () ;
V_1 = F_37 ( V_4 -> V_6 ) ;
if ( F_40 ( ! V_1 ) )
goto V_133;
V_231 = & V_1 -> V_24 [ V_67 ] ;
V_44 = F_92 ( V_2 , & V_231 -> V_218 ,
V_177 , V_147 , V_93 , V_80 ) ;
if ( F_40 ( ! V_44 ) ) {
V_133:
++ V_2 -> V_192 . V_235 ;
F_39 () ;
return V_234 ;
}
F_99 ( V_44 , V_67 ) ;
V_233 = & V_231 -> V_233 ;
F_61 ( & V_233 -> V_121 ) ;
V_233 -> V_236 ++ ;
V_233 -> V_86 += V_80 ;
if ( V_44 -> V_32 == V_237 )
++ V_233 -> V_238 ;
else if ( V_44 -> V_32 == V_239 )
++ V_233 -> V_240 ;
F_62 ( & V_233 -> V_121 ) ;
F_100 ( & V_231 -> V_218 , V_44 ) ;
F_39 () ;
return 0 ;
}
static void F_101 ( struct V_1 * V_2 ,
struct V_241 * V_242 )
{
F_102 ( V_242 -> V_243 , V_244 , sizeof( V_242 -> V_243 ) ) ;
F_102 ( V_242 -> V_245 , L_5 , sizeof( V_242 -> V_245 ) ) ;
}
static void F_103 ( struct V_1 * V_2 ,
struct V_246 * V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 -> V_6 ) ;
if ( V_6 ) {
V_25 -> V_247 = V_6 -> V_248 ;
V_25 -> V_249 = V_6 -> V_23 ;
}
}
static int F_104 ( struct V_1 * V_2 ,
struct V_246 * V_250 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_194 * V_115 = V_4 -> V_251 ;
struct V_5 * V_6 = F_3 ( V_4 -> V_6 ) ;
unsigned int V_252 , V_253 = V_250 -> V_249 ;
struct V_254 V_255 ;
bool V_256 ;
int V_11 = 0 ;
if ( V_253 == 0 ||
V_250 -> V_257 || V_250 -> V_258 || V_250 -> V_259 )
return - V_260 ;
if ( ! V_6 || V_6 -> V_261 )
return - V_262 ;
if ( V_6 -> V_263 < V_264 )
return - V_260 ;
if ( V_253 > V_6 -> V_248 )
return - V_260 ;
V_252 = V_6 -> V_23 ;
V_256 = F_105 ( V_6 ) ;
if ( V_256 )
F_15 ( V_6 ) ;
memset ( & V_255 , 0 , sizeof( V_255 ) ) ;
V_255 . V_23 = V_253 ;
V_255 . V_265 = V_265 ;
V_255 . V_266 = V_6 -> V_267 ;
V_255 . V_268 = V_6 -> V_268 ;
V_255 . V_269 = V_6 -> V_270 ;
V_255 . V_271 = V_6 -> V_271 ;
F_106 ( V_115 , V_6 ) ;
V_6 = F_107 ( V_115 , & V_255 ) ;
if ( F_108 ( V_6 ) ) {
V_11 = F_109 ( V_6 ) ;
V_255 . V_23 = V_252 ;
V_6 = F_107 ( V_115 , & V_255 ) ;
if ( F_108 ( V_6 ) ) {
F_8 ( V_2 , L_6 ,
F_109 ( V_6 ) ) ;
return V_11 ;
}
}
if ( V_256 )
F_7 ( V_6 ) ;
V_4 -> V_272 = 0 ;
F_91 ( & V_4 -> V_216 , 0 ) ;
return V_11 ;
}
static bool
F_110 ( const struct V_273 * V_274 )
{
struct V_273 V_275 = * V_274 ;
struct V_273 V_276 = {} ;
V_275 . V_277 . V_205 = 0 ;
V_275 . V_277 . V_278 = 0 ;
F_111 ( & V_275 , V_279 ) ;
V_275 . V_277 . V_274 = 0 ;
V_276 . V_277 . V_280 = V_281 ;
return ! memcmp ( & V_275 , & V_276 , sizeof( V_275 ) ) ;
}
static void F_112 ( struct V_1 * V_115 )
{
struct V_3 * V_45 = F_2 ( V_115 ) ;
V_45 -> V_56 = true ;
V_45 -> V_58 = true ;
V_45 -> V_205 = V_282 ;
V_45 -> V_278 = V_283 ;
}
static int F_113 ( struct V_1 * V_115 ,
struct V_273 * V_274 )
{
struct V_3 * V_45 = F_2 ( V_115 ) ;
V_274 -> V_277 . V_205 = V_45 -> V_205 ;
V_274 -> V_277 . V_278 = V_45 -> V_278 ;
V_274 -> V_277 . V_280 = V_281 ;
return 0 ;
}
static int F_114 ( struct V_1 * V_115 ,
const struct V_273 * V_274 )
{
struct V_3 * V_45 = F_2 ( V_115 ) ;
T_1 V_205 ;
V_205 = V_274 -> V_277 . V_205 ;
if ( ! F_115 ( V_205 ) ||
! F_116 ( V_274 -> V_277 . V_278 ) ||
! F_110 ( V_274 ) )
return - V_260 ;
V_45 -> V_205 = V_205 ;
V_45 -> V_278 = V_274 -> V_277 . V_278 ;
return 0 ;
}
static int F_117 ( struct V_1 * V_63 , int V_284 )
{
struct V_3 * V_285 = F_2 ( V_63 ) ;
struct V_1 * V_8 = F_3 ( V_285 -> V_8 ) ;
struct V_5 * V_6 = F_3 ( V_285 -> V_6 ) ;
struct V_194 * V_286 = V_285 -> V_251 ;
int V_287 = V_63 -> V_284 ;
struct V_254 V_255 ;
bool V_256 ;
int V_11 = 0 ;
if ( ! V_6 || V_6 -> V_261 )
return - V_262 ;
if ( V_8 ) {
V_11 = F_118 ( V_8 , V_284 ) ;
if ( V_11 )
return V_11 ;
}
F_119 ( V_63 ) ;
V_256 = F_105 ( V_6 ) ;
if ( V_256 )
F_15 ( V_6 ) ;
memset ( & V_255 , 0 , sizeof( V_255 ) ) ;
V_255 . V_265 = V_265 ;
V_255 . V_23 = V_6 -> V_23 ;
V_255 . V_266 = V_6 -> V_267 ;
V_255 . V_268 = V_6 -> V_268 ;
V_255 . V_269 = V_6 -> V_270 ;
V_255 . V_271 = V_6 -> V_271 ;
F_106 ( V_286 , V_6 ) ;
V_63 -> V_284 = V_284 ;
V_6 = F_107 ( V_286 , & V_255 ) ;
if ( F_108 ( V_6 ) ) {
V_11 = F_109 ( V_6 ) ;
V_63 -> V_284 = V_287 ;
V_6 = F_107 ( V_286 , & V_255 ) ;
if ( V_8 )
F_118 ( V_8 , V_287 ) ;
if ( F_108 ( V_6 ) ) {
F_8 ( V_63 , L_7 ,
F_109 ( V_6 ) ) ;
return V_11 ;
}
}
if ( V_256 )
F_7 ( V_6 ) ;
F_120 ( V_63 ) ;
F_91 ( & V_285 -> V_216 , 0 ) ;
return V_11 ;
}
static void F_121 ( struct V_1 * V_2 ,
struct V_118 * V_288 )
{
struct V_3 * V_7 = F_2 ( V_2 ) ;
int V_16 ;
memset ( V_288 , 0 , sizeof( * V_288 ) ) ;
F_122 (i) {
const struct V_118 * V_192
= F_123 ( V_7 -> V_120 , V_16 ) ;
T_6 V_289 , V_290 , V_122 , V_123 ;
unsigned int V_291 ;
do {
V_291 = F_124 ( & V_192 -> V_121 ) ;
V_289 = V_192 -> V_289 ;
V_122 = V_192 -> V_122 ;
V_290 = V_192 -> V_290 ;
V_123 = V_192 -> V_123 ;
} while ( F_125 ( & V_192 -> V_121 , V_291 ) );
V_288 -> V_289 += V_289 ;
V_288 -> V_122 += V_122 ;
V_288 -> V_290 += V_290 ;
V_288 -> V_123 += V_123 ;
V_288 -> V_124 += V_192 -> V_124 ;
}
}
static void F_126 ( struct V_1 * V_2 ,
struct V_292 * V_293 )
{
struct V_3 * V_7 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_127 ( V_7 -> V_6 ) ;
struct V_118 V_294 ;
int V_16 ;
if ( ! V_6 )
return;
F_128 ( V_293 , & V_2 -> V_192 ) ;
F_121 ( V_2 , & V_294 ) ;
V_293 -> V_289 += V_294 . V_289 ;
V_293 -> V_122 += V_294 . V_122 ;
V_293 -> V_290 += V_294 . V_290 ;
V_293 -> V_123 += V_294 . V_123 ;
V_293 -> V_124 += V_294 . V_124 ;
for ( V_16 = 0 ; V_16 < V_6 -> V_23 ; V_16 ++ ) {
const struct V_230 * V_231 = & V_6 -> V_24 [ V_16 ] ;
const struct V_232 * V_192 ;
T_6 V_236 , V_86 , V_240 ;
unsigned int V_291 ;
V_192 = & V_231 -> V_295 ;
do {
V_291 = F_124 ( & V_192 -> V_121 ) ;
V_236 = V_192 -> V_236 ;
V_86 = V_192 -> V_86 ;
} while ( F_125 ( & V_192 -> V_121 , V_291 ) );
V_293 -> V_123 += V_86 ;
V_293 -> V_122 += V_236 ;
V_192 = & V_231 -> V_233 ;
do {
V_291 = F_124 ( & V_192 -> V_121 ) ;
V_236 = V_192 -> V_236 ;
V_86 = V_192 -> V_86 ;
V_240 = V_192 -> V_240 + V_192 -> V_238 ;
} while ( F_125 ( & V_192 -> V_121 , V_291 ) );
V_293 -> V_290 += V_86 ;
V_293 -> V_289 += V_236 ;
V_293 -> V_240 += V_240 ;
}
}
static int F_129 ( struct V_1 * V_63 , void * V_296 )
{
struct V_3 * V_45 = F_2 ( V_63 ) ;
struct V_1 * V_8 = F_3 ( V_45 -> V_8 ) ;
struct V_5 * V_6 = F_3 ( V_45 -> V_6 ) ;
struct V_297 * V_298 = V_296 ;
int V_299 ;
V_299 = F_130 ( V_63 , V_296 ) ;
if ( V_299 )
return V_299 ;
if ( ! V_6 )
return - V_262 ;
if ( V_8 ) {
V_299 = F_131 ( V_8 , V_298 ) ;
if ( V_299 )
return V_299 ;
}
V_299 = F_132 ( V_6 , V_298 -> V_300 ) ;
if ( ! V_299 ) {
F_133 ( V_63 , V_296 ) ;
} else if ( V_8 ) {
memcpy ( V_298 -> V_300 , V_63 -> V_301 , V_302 ) ;
F_131 ( V_8 , V_298 ) ;
}
return V_299 ;
}
static int F_134 ( struct V_1 * V_115 , int V_303 )
{
struct V_3 * V_45 = F_2 ( V_115 ) ;
struct V_5 * V_6 = F_3 ( V_45 -> V_6 ) ;
if ( ! V_6 )
return - V_262 ;
switch ( V_303 ) {
case V_304 :
return V_305
+ V_306
+ F_135 ( V_6 ) ;
default:
return - V_260 ;
}
}
static void F_136 ( struct V_1 * V_115 ,
struct V_307 * V_192 , T_6 * V_93 )
{
struct V_3 * V_45 = F_2 ( V_115 ) ;
struct V_5 * V_6 = F_3 ( V_45 -> V_6 ) ;
const void * V_308 = & V_45 -> V_129 ;
const struct V_232 * V_309 ;
struct V_118 V_310 ;
unsigned int V_291 ;
T_6 V_236 , V_86 ;
int V_16 , V_83 ;
if ( ! V_6 )
return;
for ( V_16 = 0 ; V_16 < V_305 ; V_16 ++ )
V_93 [ V_16 ] = * ( unsigned long * ) ( V_308 + V_232 [ V_16 ] . V_79 ) ;
F_121 ( V_115 , & V_310 ) ;
for ( V_83 = 0 ; V_83 < V_306 ; V_83 ++ )
V_93 [ V_16 ++ ] = * ( T_6 * ) ( ( void * ) & V_310 + V_120 [ V_83 ] . V_79 ) ;
for ( V_83 = 0 ; V_83 < V_6 -> V_23 ; V_83 ++ ) {
V_309 = & V_6 -> V_24 [ V_83 ] . V_295 ;
do {
V_291 = F_124 ( & V_309 -> V_121 ) ;
V_236 = V_309 -> V_236 ;
V_86 = V_309 -> V_86 ;
} while ( F_125 ( & V_309 -> V_121 , V_291 ) );
V_93 [ V_16 ++ ] = V_236 ;
V_93 [ V_16 ++ ] = V_86 ;
V_309 = & V_6 -> V_24 [ V_83 ] . V_233 ;
do {
V_291 = F_124 ( & V_309 -> V_121 ) ;
V_236 = V_309 -> V_236 ;
V_86 = V_309 -> V_86 ;
} while ( F_125 ( & V_309 -> V_121 , V_291 ) );
V_93 [ V_16 ++ ] = V_236 ;
V_93 [ V_16 ++ ] = V_86 ;
}
}
static void F_137 ( struct V_1 * V_115 , T_1 V_311 , T_7 * V_93 )
{
struct V_3 * V_45 = F_2 ( V_115 ) ;
struct V_5 * V_6 = F_3 ( V_45 -> V_6 ) ;
T_7 * V_296 = V_93 ;
int V_16 ;
if ( ! V_6 )
return;
switch ( V_311 ) {
case V_304 :
for ( V_16 = 0 ; V_16 < F_138 ( V_232 ) ; V_16 ++ ) {
memcpy ( V_296 , V_232 [ V_16 ] . V_14 , V_312 ) ;
V_296 += V_312 ;
}
for ( V_16 = 0 ; V_16 < F_138 ( V_120 ) ; V_16 ++ ) {
memcpy ( V_296 , V_120 [ V_16 ] . V_14 , V_312 ) ;
V_296 += V_312 ;
}
for ( V_16 = 0 ; V_16 < V_6 -> V_23 ; V_16 ++ ) {
sprintf ( V_296 , L_8 , V_16 ) ;
V_296 += V_312 ;
sprintf ( V_296 , L_9 , V_16 ) ;
V_296 += V_312 ;
sprintf ( V_296 , L_10 , V_16 ) ;
V_296 += V_312 ;
sprintf ( V_296 , L_11 , V_16 ) ;
V_296 += V_312 ;
}
break;
}
}
static int
F_139 ( struct V_3 * V_45 ,
struct V_313 * V_242 )
{
V_242 -> V_93 = V_314 | V_315 ;
switch ( V_242 -> V_316 ) {
case V_317 :
case V_318 :
V_242 -> V_93 |= V_319 | V_320 ;
break;
case V_321 :
if ( V_45 -> V_56 )
V_242 -> V_93 |= V_319 | V_320 ;
break;
case V_322 :
if ( V_45 -> V_58 )
V_242 -> V_93 |= V_319 | V_320 ;
break;
case V_323 :
case V_324 :
break;
default:
V_242 -> V_93 = 0 ;
break;
}
return 0 ;
}
static int
F_140 ( struct V_1 * V_115 , struct V_313 * V_242 ,
T_1 * V_325 )
{
struct V_3 * V_45 = F_2 ( V_115 ) ;
struct V_5 * V_6 = F_3 ( V_45 -> V_6 ) ;
if ( ! V_6 )
return - V_262 ;
switch ( V_242 -> V_274 ) {
case V_326 :
V_242 -> V_93 = V_6 -> V_23 ;
return 0 ;
case V_327 :
return F_139 ( V_45 , V_242 ) ;
}
return - V_328 ;
}
static int F_141 ( struct V_3 * V_45 ,
struct V_313 * V_242 )
{
if ( V_242 -> V_93 == ( V_314 | V_315 |
V_319 | V_320 ) ) {
if ( V_242 -> V_316 == V_321 )
V_45 -> V_56 = true ;
else if ( V_242 -> V_316 == V_322 )
V_45 -> V_58 = true ;
else
return - V_328 ;
return 0 ;
}
if ( V_242 -> V_93 == ( V_314 | V_315 ) ) {
if ( V_242 -> V_316 == V_321 )
V_45 -> V_56 = false ;
else if ( V_242 -> V_316 == V_322 )
V_45 -> V_58 = false ;
else
return - V_328 ;
return 0 ;
}
return - V_328 ;
}
static int
F_142 ( struct V_1 * V_63 , struct V_313 * V_242 )
{
struct V_3 * V_45 = F_2 ( V_63 ) ;
if ( V_242 -> V_274 == V_329 )
return F_141 ( V_45 , V_242 ) ;
return - V_328 ;
}
static void F_143 ( struct V_1 * V_115 )
{
struct V_3 * V_45 = F_2 ( V_115 ) ;
struct V_5 * V_63 ;
int V_16 ;
F_36 () ;
V_63 = F_37 ( V_45 -> V_6 ) ;
if ( V_63 ) {
for ( V_16 = 0 ; V_16 < V_63 -> V_23 ; V_16 ++ ) {
struct V_230 * V_231 = & V_63 -> V_24 [ V_16 ] ;
F_144 ( & V_231 -> V_218 ) ;
}
}
F_39 () ;
}
static T_1 F_145 ( struct V_1 * V_115 )
{
return V_330 ;
}
static T_1 F_146 ( struct V_1 * V_115 )
{
return V_331 ;
}
static int F_147 ( struct V_1 * V_115 , T_1 * V_332 , T_7 * V_333 ,
T_7 * V_334 )
{
struct V_3 * V_45 = F_2 ( V_115 ) ;
struct V_5 * V_63 = F_3 ( V_45 -> V_6 ) ;
struct V_9 * V_335 ;
int V_16 ;
if ( ! V_63 )
return - V_262 ;
if ( V_334 )
* V_334 = V_336 ;
V_335 = V_63 -> V_12 ;
if ( V_332 ) {
for ( V_16 = 0 ; V_16 < V_331 ; V_16 ++ )
V_332 [ V_16 ] = V_335 -> V_337 [ V_16 ] ;
}
if ( V_333 )
memcpy ( V_333 , V_335 -> V_338 , V_330 ) ;
return 0 ;
}
static int F_148 ( struct V_1 * V_115 , const T_1 * V_332 ,
const T_7 * V_333 , const T_7 V_334 )
{
struct V_3 * V_45 = F_2 ( V_115 ) ;
struct V_5 * V_63 = F_3 ( V_45 -> V_6 ) ;
struct V_9 * V_335 ;
int V_16 ;
if ( ! V_63 )
return - V_262 ;
if ( V_334 != V_339 && V_334 != V_336 )
return - V_328 ;
V_335 = V_63 -> V_12 ;
if ( V_332 ) {
for ( V_16 = 0 ; V_16 < V_331 ; V_16 ++ )
if ( V_332 [ V_16 ] >= V_63 -> V_23 )
return - V_260 ;
for ( V_16 = 0 ; V_16 < V_331 ; V_16 ++ )
V_335 -> V_337 [ V_16 ] = V_332 [ V_16 ] ;
}
if ( ! V_333 ) {
if ( ! V_332 )
return 0 ;
V_333 = V_335 -> V_338 ;
}
return F_149 ( V_335 , V_333 ) ;
}
static void F_150 ( struct V_5 * V_6 ,
struct V_340 * V_341 )
{
T_1 V_342 ;
V_341 -> V_343 = V_6 -> V_270 ;
V_341 -> V_344 = V_6 -> V_267 ;
if ( V_6 -> V_263 <= V_345 )
V_342 = V_346 ;
else
V_342 = V_347 ;
V_341 -> V_348 = V_342 / V_6 -> V_271 ;
V_341 -> V_349 = V_350
/ V_6 -> V_268 ;
}
static void F_151 ( struct V_1 * V_63 ,
struct V_340 * V_341 )
{
struct V_3 * V_285 = F_2 ( V_63 ) ;
struct V_5 * V_6 = F_3 ( V_285 -> V_6 ) ;
if ( ! V_6 )
return;
F_150 ( V_6 , V_341 ) ;
}
static int F_152 ( struct V_1 * V_63 ,
struct V_340 * V_341 )
{
struct V_3 * V_285 = F_2 ( V_63 ) ;
struct V_5 * V_6 = F_3 ( V_285 -> V_6 ) ;
struct V_194 * V_286 = V_285 -> V_251 ;
struct V_254 V_255 ;
struct V_340 V_252 ;
T_1 V_351 , V_352 ;
bool V_256 ;
int V_11 = 0 ;
if ( ! V_6 || V_6 -> V_261 )
return - V_262 ;
memset ( & V_252 , 0 , sizeof( V_252 ) ) ;
F_150 ( V_6 , & V_252 ) ;
V_351 = F_153 ( T_1 , V_341 -> V_344 ,
V_353 , V_252 . V_349 ) ;
V_352 = F_153 ( T_1 , V_341 -> V_343 ,
V_354 , V_252 . V_348 ) ;
if ( V_351 == V_252 . V_344 &&
V_352 == V_252 . V_343 )
return 0 ;
memset ( & V_255 , 0 , sizeof( V_255 ) ) ;
V_255 . V_23 = V_6 -> V_23 ;
V_255 . V_265 = V_265 ;
V_255 . V_266 = V_351 ;
V_255 . V_268 = V_6 -> V_268 ;
V_255 . V_269 = V_352 ;
V_255 . V_271 = V_6 -> V_271 ;
F_119 ( V_63 ) ;
V_256 = F_105 ( V_6 ) ;
if ( V_256 )
F_15 ( V_6 ) ;
F_106 ( V_286 , V_6 ) ;
V_6 = F_107 ( V_286 , & V_255 ) ;
if ( F_108 ( V_6 ) ) {
V_11 = F_109 ( V_6 ) ;
V_255 . V_266 = V_252 . V_344 ;
V_255 . V_269 = V_252 . V_343 ;
V_6 = F_107 ( V_286 , & V_255 ) ;
if ( F_108 ( V_6 ) ) {
F_8 ( V_63 , L_12 ,
F_109 ( V_6 ) ) ;
return V_11 ;
}
}
if ( V_256 )
F_7 ( V_6 ) ;
F_120 ( V_63 ) ;
V_285 -> V_272 = 0 ;
F_91 ( & V_285 -> V_216 , 0 ) ;
return V_11 ;
}
static void F_154 ( struct V_355 * V_356 )
{
struct V_3 * V_7 =
F_155 ( V_356 , struct V_3 , V_216 . V_357 ) ;
struct V_194 * V_195 = V_7 -> V_251 ;
struct V_1 * V_2 = F_86 ( V_195 ) ;
struct V_5 * V_1 ;
struct V_9 * V_10 ;
struct V_200 * V_201 = NULL ;
bool V_358 = false , V_359 = false ;
unsigned long V_202 , V_360 , V_361 ;
if ( ! F_156 () ) {
F_91 ( & V_7 -> V_216 , V_362 ) ;
return;
}
V_1 = F_3 ( V_7 -> V_6 ) ;
if ( ! V_1 )
goto V_363;
V_10 = V_1 -> V_12 ;
V_360 = V_7 -> V_272 + V_362 ;
if ( F_157 ( V_360 ) ) {
V_361 = V_360 - V_364 ;
V_361 = V_361 < V_362 ? V_361 : V_362 ;
F_91 ( & V_7 -> V_216 , V_361 ) ;
goto V_363;
}
V_7 -> V_272 = V_364 ;
F_88 ( & V_7 -> V_213 , V_202 ) ;
if ( ! F_158 ( & V_7 -> V_215 ) ) {
V_201 = F_159 ( & V_7 -> V_215 ,
struct V_200 , V_214 ) ;
F_160 ( & V_201 -> V_214 ) ;
V_359 = ! F_158 ( & V_7 -> V_215 ) ;
}
F_90 ( & V_7 -> V_213 , V_202 ) ;
if ( ! V_201 )
goto V_363;
switch ( V_201 -> V_201 ) {
case V_208 :
if ( V_10 -> V_13 ) {
V_10 -> V_13 = false ;
F_10 ( V_2 ) ;
F_9 ( V_2 ) ;
} else {
V_358 = true ;
}
F_161 ( V_201 ) ;
break;
case V_209 :
if ( ! V_10 -> V_13 ) {
V_10 -> V_13 = true ;
F_6 ( V_2 ) ;
F_162 ( V_2 ) ;
}
F_161 ( V_201 ) ;
break;
case V_207 :
if ( ! V_10 -> V_13 ) {
V_10 -> V_13 = true ;
F_6 ( V_2 ) ;
F_162 ( V_2 ) ;
V_201 -> V_201 = V_208 ;
F_88 ( & V_7 -> V_213 , V_202 ) ;
F_163 ( & V_201 -> V_214 , & V_7 -> V_215 ) ;
F_90 ( & V_7 -> V_213 , V_202 ) ;
V_359 = true ;
}
break;
}
F_164 () ;
if ( V_358 )
F_165 ( V_2 ) ;
if ( V_359 )
F_91 ( & V_7 -> V_216 , V_362 ) ;
return;
V_363:
F_164 () ;
}
static struct V_1 * F_166 ( const T_7 * V_365 )
{
struct V_1 * V_115 ;
F_167 () ;
F_168 (&init_net, dev) {
if ( V_115 -> V_366 != & V_367 )
continue;
if ( F_169 ( V_365 , V_115 -> V_368 ) )
return V_115 ;
}
return NULL ;
}
static struct V_1 * F_170 ( struct V_1 * V_8 )
{
struct V_1 * V_115 ;
F_167 () ;
F_168 (&init_net, dev) {
struct V_3 * V_4 ;
if ( V_115 -> V_366 != & V_367 )
continue;
V_4 = F_2 ( V_115 ) ;
if ( ! F_3 ( V_4 -> V_6 ) )
continue;
if ( F_3 ( V_4 -> V_8 ) == V_8 )
return V_115 ;
}
return NULL ;
}
static T_8 F_171 ( struct V_43 * * V_369 )
{
struct V_43 * V_44 = * V_369 ;
struct V_1 * V_63 = F_37 ( V_44 -> V_115 -> V_370 ) ;
struct V_3 * V_7 = F_2 ( V_63 ) ;
struct V_118 * V_119
= F_60 ( V_7 -> V_120 ) ;
V_44 -> V_115 = V_63 ;
F_61 ( & V_119 -> V_121 ) ;
V_119 -> V_289 ++ ;
V_119 -> V_290 += V_44 -> V_80 ;
F_62 ( & V_119 -> V_121 ) ;
return V_371 ;
}
static int F_172 ( struct V_1 * V_8 ,
struct V_1 * V_63 )
{
struct V_3 * V_7 = F_2 ( V_63 ) ;
int V_11 ;
V_11 = F_173 ( V_8 ,
F_171 , V_63 ) ;
if ( V_11 != 0 ) {
F_8 ( V_8 ,
L_13 ,
V_11 ) ;
goto V_372;
}
V_11 = F_174 ( V_8 , V_63 ) ;
if ( V_11 != 0 ) {
F_8 ( V_8 ,
L_14 ,
V_63 -> V_14 , V_11 ) ;
goto V_373;
}
V_8 -> V_202 |= V_374 ;
F_91 ( & V_7 -> V_375 , V_376 ) ;
F_175 ( V_377 , V_8 ) ;
F_176 ( V_8 , L_15 , V_63 -> V_14 ) ;
return 0 ;
V_373:
F_177 ( V_8 ) ;
V_372:
return V_11 ;
}
static void F_178 ( struct V_1 * V_63 ,
struct V_1 * V_8 )
{
int V_11 ;
V_11 = F_118 ( V_8 , V_63 -> V_284 ) ;
if ( V_11 )
F_12 ( V_8 ,
L_16 , V_63 -> V_284 ) ;
if ( F_66 ( V_63 ) ) {
V_11 = F_11 ( V_8 ) ;
if ( V_11 )
F_12 ( V_8 ,
L_17 , V_11 ) ;
}
}
static void F_179 ( struct V_355 * V_356 )
{
struct V_3 * V_7
= F_155 ( V_356 , struct V_3 , V_375 . V_357 ) ;
struct V_1 * V_63 = F_86 ( V_7 -> V_251 ) ;
struct V_1 * V_8 ;
if ( ! F_156 () ) {
F_91 ( & V_7 -> V_375 , 0 ) ;
return;
}
V_8 = F_3 ( V_7 -> V_8 ) ;
if ( V_8 )
F_178 ( V_63 , V_8 ) ;
F_164 () ;
}
static int F_180 ( struct V_1 * V_8 )
{
struct V_1 * V_63 ;
struct V_3 * V_4 ;
struct V_5 * V_378 ;
if ( V_8 -> V_379 != V_302 )
return V_380 ;
V_63 = F_166 ( V_8 -> V_368 ) ;
if ( ! V_63 )
return V_380 ;
V_4 = F_2 ( V_63 ) ;
V_378 = F_3 ( V_4 -> V_6 ) ;
if ( ! V_378 || F_3 ( V_4 -> V_8 ) )
return V_380 ;
if ( F_172 ( V_8 , V_63 ) != 0 )
return V_380 ;
F_176 ( V_63 , L_18 , V_8 -> V_14 ) ;
F_181 ( V_8 ) ;
F_182 ( V_4 -> V_8 , V_8 ) ;
return V_381 ;
}
static int F_183 ( struct V_1 * V_8 )
{
struct V_3 * V_4 ;
struct V_5 * V_378 ;
struct V_1 * V_63 ;
bool V_382 = F_66 ( V_8 ) ;
V_63 = F_170 ( V_8 ) ;
if ( ! V_63 )
return V_380 ;
V_4 = F_2 ( V_63 ) ;
V_378 = F_3 ( V_4 -> V_6 ) ;
if ( ! V_378 )
return V_380 ;
F_184 ( V_63 , V_382 ) ;
F_176 ( V_63 , L_19 ,
V_382 ? L_20 : L_21 , V_8 -> V_14 ) ;
return V_381 ;
}
static int F_185 ( struct V_1 * V_8 )
{
struct V_1 * V_63 ;
struct V_3 * V_4 ;
V_63 = F_170 ( V_8 ) ;
if ( ! V_63 )
return V_380 ;
V_4 = F_2 ( V_63 ) ;
F_186 ( & V_4 -> V_375 ) ;
F_176 ( V_63 , L_22 , V_8 -> V_14 ) ;
F_177 ( V_8 ) ;
F_187 ( V_8 , V_63 ) ;
F_188 ( V_4 -> V_8 , NULL ) ;
F_189 ( V_8 ) ;
return V_381 ;
}
static int F_190 ( struct V_194 * V_115 ,
const struct V_383 * V_384 )
{
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
struct V_254 V_255 ;
struct V_5 * V_6 ;
int V_11 = - V_385 ;
V_2 = F_191 ( sizeof( struct V_3 ) ,
V_386 ) ;
if ( ! V_2 )
goto V_387;
F_6 ( V_2 ) ;
F_112 ( V_2 ) ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_251 = V_115 ;
V_4 -> V_388 = F_192 ( V_389 , V_390 ) ;
if ( F_193 ( V_4 ) )
F_194 ( V_2 , L_23 ,
V_4 -> V_388 ) ;
F_195 ( V_115 , V_2 ) ;
F_196 ( & V_4 -> V_216 , F_154 ) ;
F_197 ( & V_4 -> V_213 ) ;
F_198 ( & V_4 -> V_215 ) ;
F_196 ( & V_4 -> V_375 , F_179 ) ;
V_4 -> V_120
= F_199 ( struct V_118 ) ;
if ( ! V_4 -> V_120 )
goto V_391;
V_2 -> V_366 = & V_367 ;
V_2 -> V_392 = & V_392 ;
F_200 ( V_2 , & V_115 -> V_393 ) ;
V_2 -> V_394 = V_134 ;
memset ( & V_255 , 0 , sizeof( V_255 ) ) ;
V_255 . V_265 = V_265 ;
V_255 . V_23 = V_395 ;
V_255 . V_266 = V_396 ;
V_255 . V_268 = V_397 ;
V_255 . V_269 = V_398 ;
V_255 . V_271 = V_399 ;
V_6 = F_107 ( V_115 , & V_255 ) ;
if ( F_108 ( V_6 ) ) {
V_11 = F_109 ( V_6 ) ;
F_8 ( V_2 , L_24 , V_11 ) ;
goto V_400;
}
memcpy ( V_2 -> V_301 , V_255 . V_401 , V_302 ) ;
V_2 -> V_220 = V_2 -> V_402 |
V_403 | V_404 |
V_405 | V_406 ;
V_2 -> V_407 = V_2 -> V_220 ;
F_201 ( V_2 ) ;
V_2 -> V_408 = V_409 ;
if ( V_6 -> V_263 >= V_345 )
V_2 -> V_410 = V_411 - V_412 ;
else
V_2 -> V_410 = V_413 ;
V_11 = F_202 ( V_2 ) ;
if ( V_11 != 0 ) {
F_203 ( L_25 ) ;
goto V_414;
}
return V_11 ;
V_414:
F_106 ( V_115 , V_6 ) ;
V_400:
F_204 ( V_4 -> V_120 ) ;
V_391:
F_195 ( V_115 , NULL ) ;
F_205 ( V_2 ) ;
V_387:
return V_11 ;
}
static int F_206 ( struct V_194 * V_115 )
{
struct V_3 * V_7 ;
struct V_1 * V_8 ;
struct V_1 * V_2 ;
V_2 = F_86 ( V_115 ) ;
if ( V_2 == NULL ) {
F_207 ( & V_115 -> V_393 , L_26 ) ;
return 0 ;
}
V_7 = F_2 ( V_2 ) ;
F_119 ( V_2 ) ;
F_186 ( & V_7 -> V_216 ) ;
F_208 () ;
V_8 = F_3 ( V_7 -> V_8 ) ;
if ( V_8 )
F_185 ( V_8 ) ;
F_209 ( V_2 ) ;
F_106 ( V_115 ,
F_3 ( V_7 -> V_6 ) ) ;
F_164 () ;
F_195 ( V_115 , NULL ) ;
F_204 ( V_7 -> V_120 ) ;
F_205 ( V_2 ) ;
return 0 ;
}
static int F_210 ( struct V_415 * V_416 ,
unsigned long V_201 , void * V_417 )
{
struct V_1 * V_418 = F_211 ( V_417 ) ;
if ( V_418 -> V_366 == & V_367 )
return V_380 ;
if ( V_418 -> type != V_419 )
return V_380 ;
if ( F_212 ( V_418 ) )
return V_380 ;
if ( ( V_418 -> V_420 & V_421 ) &&
( V_418 -> V_202 & V_422 ) )
return V_380 ;
switch ( V_201 ) {
case V_423 :
return F_180 ( V_418 ) ;
case V_424 :
return F_185 ( V_418 ) ;
case V_425 :
case V_426 :
return F_183 ( V_418 ) ;
default:
return V_380 ;
}
}
static void T_9 F_213 ( void )
{
F_214 ( & V_427 ) ;
F_215 ( & V_428 ) ;
}
static int T_10 F_216 ( void )
{
int V_11 ;
if ( V_265 < V_429 ) {
V_265 = V_429 ;
F_217 ( L_27 ,
V_265 ) ;
}
V_11 = F_218 ( & V_428 ) ;
if ( V_11 )
return V_11 ;
F_219 ( & V_427 ) ;
return 0 ;
}
