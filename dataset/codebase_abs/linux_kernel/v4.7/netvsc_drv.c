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
struct V_3 * V_23 = F_6 ( V_22 ) ;
struct V_6 * V_7 = V_23 -> V_8 ;
struct V_11 * V_12 = V_23 -> V_12 ;
struct V_13 * V_14 ;
int V_24 = 0 ;
F_9 ( V_22 ) ;
V_24 = F_10 ( V_7 ) ;
if ( V_24 != 0 ) {
F_11 ( V_22 , L_1 , V_24 ) ;
return V_24 ;
}
F_12 ( V_22 ) ;
V_14 = V_12 -> V_15 ;
if ( ! V_14 -> V_25 )
F_13 ( V_22 ) ;
return V_24 ;
}
static int F_14 ( struct V_9 * V_22 )
{
struct V_3 * V_23 = F_6 ( V_22 ) ;
struct V_6 * V_7 = V_23 -> V_8 ;
struct V_11 * V_12 = V_23 -> V_12 ;
int V_24 ;
T_1 V_26 , V_27 , V_28 , V_29 = 10 , V_30 = 0 , V_31 = 20 ;
struct V_32 * V_33 ;
F_15 ( V_22 ) ;
F_16 ( & V_23 -> V_5 ) ;
V_24 = F_17 ( V_7 ) ;
if ( V_24 != 0 ) {
F_11 ( V_22 , L_2 , V_24 ) ;
return V_24 ;
}
while ( true ) {
V_26 = 0 ;
for ( V_28 = 0 ; V_28 < V_12 -> V_34 ; V_28 ++ ) {
V_33 = V_12 -> V_35 [ V_28 ] ;
if ( ! V_33 )
continue;
F_18 ( & V_33 -> V_36 , & V_26 ,
& V_27 ) ;
if ( V_26 )
break;
F_18 ( & V_33 -> V_37 , & V_26 ,
& V_27 ) ;
if ( V_26 )
break;
}
V_30 ++ ;
if ( V_30 > V_31 || V_26 == 0 )
break;
F_19 ( V_29 ) ;
if ( V_29 < 1000 )
V_29 *= 2 ;
}
if ( V_26 ) {
F_11 ( V_22 , L_3 ) ;
V_24 = - V_38 ;
}
return V_24 ;
}
static void * F_20 ( struct V_39 * V_40 , T_1 V_41 ,
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
static T_2 F_21 ( struct V_9 * V_10 , struct V_53 * V_54 ,
void * V_55 , T_3 V_56 )
{
struct V_3 * V_23 = F_6 ( V_10 ) ;
struct V_11 * V_57 = V_23 -> V_12 ;
T_1 V_58 ;
T_2 V_59 = 0 ;
if ( V_57 == NULL || V_10 -> V_60 <= 1 )
return 0 ;
V_58 = F_22 ( V_54 ) ;
V_59 = V_57 -> V_61 [ V_58 % V_62 ] %
V_10 -> V_60 ;
if ( ! V_57 -> V_35 [ V_59 ] )
V_59 = 0 ;
return V_59 ;
}
static T_1 F_23 ( struct V_63 * V_63 , T_1 V_64 , T_1 V_65 ,
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
V_67 [ V_68 ] . V_73 = F_24 ( V_63 ) ;
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
static T_1 F_25 ( void * V_74 , T_1 V_65 , struct V_53 * V_54 ,
struct V_75 * V_76 ,
struct V_66 * * V_77 )
{
struct V_66 * V_67 = * V_77 ;
T_1 V_78 = 0 ;
char * V_79 = V_54 -> V_79 ;
int V_80 = F_26 ( V_54 ) -> V_81 ;
int V_28 ;
if ( V_74 != NULL )
V_78 += F_23 ( F_27 ( V_74 ) ,
F_28 ( V_74 ) ,
V_65 , & V_67 [ V_78 ] ) ;
V_76 -> V_82 = V_65 ;
V_76 -> V_83 = V_78 ;
V_78 += F_23 ( F_27 ( V_79 ) ,
F_28 ( V_79 ) ,
F_29 ( V_54 ) , & V_67 [ V_78 ] ) ;
for ( V_28 = 0 ; V_28 < V_80 ; V_28 ++ ) {
T_4 * V_84 = F_26 ( V_54 ) -> V_80 + V_28 ;
V_78 += F_23 ( F_30 ( V_84 ) ,
V_84 -> V_85 ,
F_31 ( V_84 ) , & V_67 [ V_78 ] ) ;
}
return V_78 ;
}
static int F_32 ( struct V_53 * V_54 )
{
int V_28 , V_80 = F_26 ( V_54 ) -> V_81 ;
int V_86 = 0 ;
for ( V_28 = 0 ; V_28 < V_80 ; V_28 ++ ) {
T_4 * V_84 = F_26 ( V_54 ) -> V_80 + V_28 ;
unsigned long V_51 = F_31 ( V_84 ) ;
unsigned long V_64 = V_84 -> V_85 ;
V_64 &= ~ V_70 ;
V_86 += F_33 ( V_64 + V_51 ) ;
}
return V_86 ;
}
static int F_34 ( struct V_53 * V_54 )
{
char * V_79 = V_54 -> V_79 ;
unsigned int V_64 = F_28 ( V_79 ) ;
unsigned int V_65 = F_29 ( V_54 ) ;
int V_87 ;
int V_88 ;
V_87 = F_35 ( V_64 + V_65 , V_72 ) ;
V_88 = F_32 ( V_54 ) ;
return V_87 + V_88 ;
}
static T_1 F_36 ( struct V_53 * V_54 , T_1 * V_89 )
{
T_1 V_90 = V_91 ;
if ( ( F_37 ( V_54 ) -> V_92 != F_38 ( V_93 ) ) &&
( F_37 ( V_54 ) -> V_92 != F_38 ( V_94 ) ) ) {
goto V_95;
}
* V_89 = F_39 ( V_54 ) ;
if ( ( F_37 ( V_54 ) -> V_92 == F_38 ( V_93 ) ) ) {
struct V_96 * V_96 = F_40 ( V_54 ) ;
if ( V_96 -> V_97 == V_98 )
V_90 = V_99 ;
else if ( V_96 -> V_97 == V_100 )
V_90 = V_101 ;
} else {
if ( F_41 ( V_54 ) -> V_102 == V_98 )
V_90 = V_103 ;
else if ( F_41 ( V_54 ) -> V_102 == V_100 )
V_90 = V_104 ;
}
V_95:
return V_90 ;
}
static int F_42 ( struct V_53 * V_54 , struct V_9 * V_22 )
{
struct V_3 * V_23 = F_6 ( V_22 ) ;
struct V_75 * V_76 = NULL ;
int V_24 ;
unsigned int V_105 ;
struct V_39 * V_106 ;
struct V_43 * V_44 ;
T_1 V_107 ;
bool V_108 ;
bool V_109 = false ;
struct V_45 * V_46 ;
struct V_110 * V_111 ;
struct V_112 * V_113 ;
int V_114 ;
T_1 V_115 ;
T_1 V_58 ;
T_1 V_116 ;
struct V_66 V_77 [ V_117 ] ;
struct V_66 * V_67 = V_77 ;
struct V_118 * V_119 = F_43 ( V_23 -> V_119 ) ;
V_120:
V_116 = V_54 -> V_65 ;
V_105 = F_34 ( V_54 ) + 2 ;
if ( V_105 > V_117 && V_109 ) {
F_44 ( L_4 ,
V_105 , V_54 -> V_65 ) ;
V_24 = - V_121 ;
goto V_122;
} else if ( V_105 > V_117 ) {
if ( F_45 ( V_54 ) ) {
F_44 ( L_5 ) ;
V_24 = - V_123 ;
goto V_122;
}
V_109 = true ;
goto V_120;
}
V_24 = F_46 ( V_54 , V_124 ) ;
if ( V_24 ) {
F_11 ( V_22 , L_6 ) ;
V_24 = - V_123 ;
goto V_122;
}
F_47 ( sizeof( struct V_75 ) >
F_48 ( struct V_53 , V_125 ) ) ;
V_76 = (struct V_75 * ) V_54 -> V_125 ;
V_76 -> V_59 = F_49 ( V_54 ) ;
V_76 -> V_126 = V_54 -> V_65 ;
V_106 = (struct V_39 * ) V_54 -> V_127 ;
memset ( V_106 , 0 , V_124 ) ;
V_108 = V_54 -> V_128 & V_129 ;
V_106 -> V_130 = V_131 ;
V_106 -> V_132 = V_76 -> V_126 ;
V_44 = & V_106 -> V_40 . V_47 ;
V_44 -> V_48 = sizeof( struct V_43 ) ;
V_44 -> V_133 = V_76 -> V_126 ;
V_44 -> V_49 = sizeof( struct V_43 ) ;
V_107 = F_50 ( struct V_43 ) ;
V_58 = F_51 ( V_54 ) ;
if ( V_58 != 0 && V_22 -> V_60 > 1 ) {
V_107 += V_134 ;
V_46 = F_20 ( V_106 , V_134 ,
V_135 ) ;
* ( T_1 * ) ( ( void * ) V_46 + V_46 -> V_52 ) = V_58 ;
}
if ( V_108 ) {
struct V_136 * V_137 ;
V_107 += V_138 ;
V_46 = F_20 ( V_106 , V_138 ,
V_139 ) ;
V_137 = (struct V_136 * ) ( ( void * ) V_46 +
V_46 -> V_52 ) ;
V_137 -> V_140 = V_54 -> V_128 & V_141 ;
V_137 -> V_142 = ( V_54 -> V_128 & V_143 ) >>
V_144 ;
}
V_115 = F_36 ( V_54 , & V_114 ) ;
if ( V_115 == V_91 )
goto V_145;
if ( F_52 ( V_54 ) )
goto V_146;
if ( ( V_54 -> V_147 == V_148 ) ||
( V_54 -> V_147 == V_149 ) )
goto V_145;
V_107 += V_150 ;
V_46 = F_20 ( V_106 , V_150 ,
V_151 ) ;
V_111 = (struct V_110 * ) ( ( void * ) V_46 +
V_46 -> V_52 ) ;
if ( V_115 & ( V_152 << 16 ) )
V_111 -> V_153 . V_154 = 1 ;
else
V_111 -> V_153 . V_155 = 1 ;
if ( V_115 & V_156 ) {
V_111 -> V_153 . V_157 = 1 ;
V_111 -> V_153 . V_158 = V_114 ;
} else if ( V_115 & V_159 ) {
struct V_160 * V_161 ;
T_2 V_162 ;
V_24 = F_46 ( V_54 , 0 ) ;
if ( V_24 )
goto V_122;
V_161 = F_53 ( V_54 ) ;
V_162 = F_54 ( V_161 -> V_65 ) ;
V_161 -> V_163 = 0 ;
V_161 -> V_163 = F_55 ( F_40 ( V_54 ) -> V_164 ,
F_40 ( V_54 ) -> V_165 ,
V_162 , V_100 ,
F_56 ( V_161 , V_162 , 0 ) ) ;
if ( V_161 -> V_163 == 0 )
V_161 -> V_163 = V_166 ;
V_111 -> V_153 . V_167 = 0 ;
}
goto V_145;
V_146:
V_107 += V_168 ;
V_46 = F_20 ( V_106 , V_168 ,
V_169 ) ;
V_113 = (struct V_112 * ) ( ( void * ) V_46 +
V_46 -> V_52 ) ;
V_113 -> V_170 . type = V_171 ;
if ( V_115 & ( V_152 << 16 ) ) {
V_113 -> V_170 . V_172 =
V_173 ;
F_40 ( V_54 ) -> V_174 = 0 ;
F_40 ( V_54 ) -> V_163 = 0 ;
F_57 ( V_54 ) -> V_163 =
~ F_55 ( F_40 ( V_54 ) -> V_164 ,
F_40 ( V_54 ) -> V_165 , 0 , V_98 , 0 ) ;
} else {
V_113 -> V_170 . V_172 =
V_175 ;
F_41 ( V_54 ) -> V_176 = 0 ;
F_57 ( V_54 ) -> V_163 =
~ F_58 ( & F_41 ( V_54 ) -> V_164 ,
& F_41 ( V_54 ) -> V_165 , 0 , V_98 , 0 ) ;
}
V_113 -> V_170 . V_158 = V_114 ;
V_113 -> V_170 . V_177 = F_26 ( V_54 ) -> V_178 ;
V_145:
V_106 -> V_132 += V_107 ;
V_76 -> V_126 = V_106 -> V_132 ;
V_76 -> V_179 = F_25 ( V_106 , V_107 ,
V_54 , V_76 , & V_67 ) ;
F_59 ( V_54 ) ;
V_24 = F_60 ( V_23 -> V_8 , V_76 ,
V_106 , & V_67 , V_54 ) ;
V_122:
if ( V_24 == 0 ) {
F_61 ( & V_119 -> V_180 ) ;
V_119 -> V_181 ++ ;
V_119 -> V_71 += V_116 ;
F_62 ( & V_119 -> V_180 ) ;
} else {
if ( V_24 != - V_182 ) {
F_63 ( V_54 ) ;
V_22 -> V_183 . V_184 ++ ;
}
}
return ( V_24 == - V_182 ) ? V_185 : V_186 ;
}
void F_64 ( struct V_6 * V_7 ,
struct V_39 * V_187 )
{
struct V_188 * V_189 = & V_187 -> V_40 . V_190 ;
struct V_9 * V_22 ;
struct V_3 * V_191 ;
struct V_192 * V_193 ;
unsigned long V_16 ;
if ( V_189 -> V_194 != V_195 &&
V_189 -> V_194 != V_196 &&
V_189 -> V_194 != V_197 )
return;
V_22 = F_3 ( V_7 ) ;
if ( ! V_22 || V_22 -> V_198 != V_199 )
return;
V_191 = F_6 ( V_22 ) ;
V_193 = F_65 ( sizeof( * V_193 ) , V_200 ) ;
if ( ! V_193 )
return;
V_193 -> V_193 = V_189 -> V_194 ;
F_66 ( & V_191 -> V_201 , V_16 ) ;
F_67 ( & V_193 -> V_202 , & V_191 -> V_203 ) ;
F_68 ( & V_191 -> V_201 , V_16 ) ;
F_69 ( & V_191 -> V_204 , 0 ) ;
}
static struct V_53 * F_70 ( struct V_9 * V_22 ,
struct V_75 * V_76 ,
struct V_110 * V_111 ,
void * V_79 , T_2 V_128 )
{
struct V_53 * V_54 ;
V_54 = F_71 ( V_22 , V_76 -> V_126 ) ;
if ( ! V_54 )
return V_54 ;
memcpy ( F_72 ( V_54 , V_76 -> V_126 ) , V_79 ,
V_76 -> V_126 ) ;
V_54 -> V_97 = F_73 ( V_54 , V_22 ) ;
if ( V_111 ) {
if ( V_111 -> V_205 . V_206 )
V_54 -> V_147 = V_149 ;
else
V_54 -> V_147 = V_148 ;
}
if ( V_128 & V_129 )
F_74 ( V_54 , F_38 ( V_207 ) ,
V_128 ) ;
return V_54 ;
}
int F_75 ( struct V_6 * V_7 ,
struct V_75 * V_76 ,
void * * V_79 ,
struct V_110 * V_111 ,
struct V_32 * V_208 ,
T_2 V_128 )
{
struct V_9 * V_22 = F_3 ( V_7 ) ;
struct V_3 * V_23 = F_6 ( V_22 ) ;
struct V_53 * V_54 ;
struct V_53 * V_209 ;
struct V_118 * V_210 ;
struct V_11 * V_211 = V_23 -> V_12 ;
T_1 V_212 = V_76 -> V_126 ;
int V_24 = 0 ;
if ( ! V_22 || V_22 -> V_198 != V_199 )
return V_213 ;
if ( F_76 ( V_211 -> V_214 ) ) {
F_77 ( & V_211 -> V_215 ) ;
if ( ! F_76 ( V_211 -> V_214 ) ) {
F_78 ( & V_211 -> V_215 ) ;
goto V_216;
}
V_209 = F_70 ( V_211 -> V_217 , V_76 ,
V_111 , * V_79 , V_128 ) ;
if ( V_209 != NULL ) {
++ V_211 -> V_217 -> V_183 . V_218 ;
V_211 -> V_217 -> V_183 . V_219 += V_212 ;
F_79 ( V_209 ) ;
} else {
++ V_22 -> V_183 . V_220 ;
V_24 = V_213 ;
}
F_78 ( & V_211 -> V_215 ) ;
return V_24 ;
}
V_216:
V_23 = F_6 ( V_22 ) ;
V_210 = F_43 ( V_23 -> V_210 ) ;
V_54 = F_70 ( V_22 , V_76 , V_111 , * V_79 , V_128 ) ;
if ( F_80 ( ! V_54 ) ) {
++ V_22 -> V_183 . V_220 ;
return V_213 ;
}
F_81 ( V_54 , V_208 ->
V_221 . V_222 . V_223 ) ;
F_61 ( & V_210 -> V_180 ) ;
V_210 -> V_181 ++ ;
V_210 -> V_71 += V_76 -> V_126 ;
F_62 ( & V_210 -> V_180 ) ;
F_82 ( V_54 ) ;
return 0 ;
}
static void F_83 ( struct V_9 * V_22 ,
struct V_224 * V_225 )
{
F_84 ( V_225 -> V_226 , V_227 , sizeof( V_225 -> V_226 ) ) ;
F_84 ( V_225 -> V_228 , L_7 , sizeof( V_225 -> V_228 ) ) ;
}
static void F_85 ( struct V_9 * V_22 ,
struct V_229 * V_208 )
{
struct V_3 * V_23 = F_6 ( V_22 ) ;
struct V_11 * V_12 = V_23 -> V_12 ;
if ( V_12 ) {
V_208 -> V_230 = V_12 -> V_231 ;
V_208 -> V_232 = V_12 -> V_34 ;
}
}
static int F_86 ( struct V_9 * V_22 ,
struct V_229 * V_233 )
{
struct V_3 * V_23 = F_6 ( V_22 ) ;
struct V_6 * V_234 = V_23 -> V_8 ;
struct V_11 * V_12 = V_23 -> V_12 ;
struct V_235 V_236 ;
T_1 V_34 ;
T_1 V_231 ;
int V_24 = 0 ;
bool V_237 = false ;
if ( V_23 -> V_238 || ! V_12 || V_12 -> V_239 )
return - V_240 ;
V_34 = V_12 -> V_34 ;
V_231 = F_87 ( T_1 , V_12 -> V_231 , F_88 () ) ;
if ( V_12 -> V_241 < V_242 ) {
F_89 ( L_8 ) ;
return - V_243 ;
}
if ( ! V_233 ||
V_233 -> V_244 ||
V_233 -> V_245 ||
V_233 -> V_246 ||
( V_233 -> V_232 < 1 ) )
return - V_243 ;
if ( V_233 -> V_232 > V_231 ) {
F_89 ( L_9 , V_231 ) ;
V_233 -> V_232 = V_231 ;
}
V_24 = F_14 ( V_22 ) ;
if ( V_24 )
goto V_247;
V_248:
V_23 -> V_238 = true ;
F_90 ( V_234 ) ;
V_12 -> V_34 = V_233 -> V_232 ;
memset ( & V_236 , 0 , sizeof( V_236 ) ) ;
V_236 . V_34 = V_12 -> V_34 ;
V_236 . V_249 = V_249 ;
V_236 . V_250 = V_250 ;
V_24 = F_91 ( V_234 , & V_236 ) ;
if ( V_24 ) {
if ( V_237 ) {
F_11 ( V_22 , L_10 , V_24 ) ;
return V_24 ;
}
goto V_251;
}
V_12 = V_23 -> V_12 ;
V_24 = F_92 ( V_22 , V_12 -> V_34 ) ;
if ( V_24 ) {
if ( V_237 ) {
F_11 ( V_22 , L_11 , V_24 ) ;
return V_24 ;
}
goto V_251;
}
V_24 = F_93 ( V_22 , V_12 -> V_34 ) ;
if ( V_24 ) {
if ( V_237 ) {
F_11 ( V_22 , L_12 , V_24 ) ;
return V_24 ;
}
goto V_251;
}
V_247:
F_8 ( V_22 ) ;
V_23 -> V_238 = false ;
F_69 ( & V_23 -> V_204 , 0 ) ;
return V_24 ;
V_251:
F_11 ( V_22 , L_13 ) ;
V_237 = true ;
V_233 -> V_232 = V_34 ;
goto V_248;
}
static bool F_94 ( const struct V_252 * V_253 )
{
struct V_252 V_254 = * V_253 ;
struct V_252 V_255 = {} ;
F_95 ( & V_254 , 0 ) ;
V_254 . V_256 = 0 ;
V_254 . V_257 = 0 ;
V_254 . V_253 = 0 ;
V_255 . V_258 = V_259 ;
return ! memcmp ( & V_254 , & V_255 , sizeof( V_254 ) ) ;
}
static void F_96 ( struct V_9 * V_234 )
{
struct V_3 * V_260 = F_6 ( V_234 ) ;
V_260 -> V_261 = V_262 ;
V_260 -> V_256 = V_263 ;
}
static int F_97 ( struct V_9 * V_234 , struct V_252 * V_253 )
{
struct V_3 * V_260 = F_6 ( V_234 ) ;
F_95 ( V_253 , V_260 -> V_261 ) ;
V_253 -> V_256 = V_260 -> V_256 ;
V_253 -> V_258 = V_259 ;
return 0 ;
}
static int F_98 ( struct V_9 * V_234 , struct V_252 * V_253 )
{
struct V_3 * V_260 = F_6 ( V_234 ) ;
T_1 V_261 ;
V_261 = F_99 ( V_253 ) ;
if ( ! F_100 ( V_261 ) ||
! F_101 ( V_253 -> V_256 ) ||
! F_94 ( V_253 ) )
return - V_243 ;
V_260 -> V_261 = V_261 ;
V_260 -> V_256 = V_253 -> V_256 ;
return 0 ;
}
static int F_102 ( struct V_9 * V_10 , int V_264 )
{
struct V_3 * V_4 = F_6 ( V_10 ) ;
struct V_11 * V_12 = V_4 -> V_12 ;
struct V_6 * V_265 = V_4 -> V_8 ;
struct V_235 V_236 ;
int V_266 = V_267 ;
T_1 V_34 ;
int V_24 = 0 ;
if ( V_4 -> V_238 || ! V_12 || V_12 -> V_239 )
return - V_240 ;
if ( V_12 -> V_241 >= V_268 )
V_266 = V_269 - V_270 ;
if ( V_264 < V_271 || V_264 > V_266 )
return - V_243 ;
V_24 = F_14 ( V_10 ) ;
if ( V_24 )
goto V_247;
V_34 = V_12 -> V_34 ;
V_4 -> V_238 = true ;
F_90 ( V_265 ) ;
V_10 -> V_264 = V_264 ;
memset ( & V_236 , 0 , sizeof( V_236 ) ) ;
V_236 . V_249 = V_249 ;
V_236 . V_34 = V_34 ;
V_236 . V_250 = V_250 ;
F_91 ( V_265 , & V_236 ) ;
V_247:
F_8 ( V_10 ) ;
V_4 -> V_238 = false ;
F_69 ( & V_4 -> V_204 , 0 ) ;
return V_24 ;
}
static struct V_272 * F_103 ( struct V_9 * V_22 ,
struct V_272 * V_273 )
{
struct V_3 * V_191 = F_6 ( V_22 ) ;
int V_274 ;
F_104 (cpu) {
struct V_118 * V_119 = F_105 ( V_191 -> V_119 ,
V_274 ) ;
struct V_118 * V_210 = F_105 ( V_191 -> V_210 ,
V_274 ) ;
T_5 V_275 , V_276 , V_218 , V_219 ;
unsigned int V_277 ;
do {
V_277 = F_106 ( & V_119 -> V_180 ) ;
V_275 = V_119 -> V_181 ;
V_276 = V_119 -> V_71 ;
} while ( F_107 ( & V_119 -> V_180 , V_277 ) );
do {
V_277 = F_106 ( & V_210 -> V_180 ) ;
V_218 = V_210 -> V_181 ;
V_219 = V_210 -> V_71 ;
} while ( F_107 ( & V_210 -> V_180 , V_277 ) );
V_273 -> V_276 += V_276 ;
V_273 -> V_275 += V_275 ;
V_273 -> V_219 += V_219 ;
V_273 -> V_218 += V_218 ;
}
V_273 -> V_184 = V_22 -> V_183 . V_184 ;
V_273 -> V_278 = V_22 -> V_183 . V_184 ;
V_273 -> V_220 = V_22 -> V_183 . V_220 ;
V_273 -> V_279 = V_22 -> V_183 . V_279 ;
return V_273 ;
}
static int F_108 ( struct V_9 * V_10 , void * V_280 )
{
struct V_3 * V_4 = F_6 ( V_10 ) ;
struct V_6 * V_265 = V_4 -> V_8 ;
struct V_281 * V_282 = V_280 ;
char V_283 [ V_284 ] ;
unsigned char V_285 ;
int V_286 ;
memcpy ( V_283 , V_10 -> V_287 , V_284 ) ;
V_285 = V_10 -> V_288 ;
V_286 = F_109 ( V_10 , V_280 ) ;
if ( V_286 != 0 )
return V_286 ;
V_286 = F_110 ( V_265 , V_282 -> V_289 ) ;
if ( V_286 != 0 ) {
memcpy ( V_10 -> V_287 , V_283 , V_284 ) ;
V_10 -> V_288 = V_285 ;
}
return V_286 ;
}
static void F_111 ( struct V_9 * V_22 )
{
}
static void F_112 ( struct V_1 * V_2 )
{
struct V_3 * V_191 =
F_2 ( V_2 , struct V_3 , V_204 . V_5 ) ;
struct V_6 * V_7 = V_191 -> V_8 ;
struct V_9 * V_22 = F_3 ( V_7 ) ;
struct V_11 * V_9 ;
struct V_13 * V_14 ;
struct V_192 * V_193 = NULL ;
bool V_290 = false , V_291 = false ;
unsigned long V_16 , V_292 , V_293 ;
F_113 () ;
if ( V_191 -> V_238 )
goto V_294;
V_9 = V_191 -> V_12 ;
V_14 = V_9 -> V_15 ;
V_292 = V_191 -> V_295 + V_296 ;
if ( F_114 ( V_292 ) ) {
V_293 = V_292 - V_297 ;
V_293 = V_293 < V_296 ? V_293 : V_296 ;
F_69 ( & V_191 -> V_204 , V_293 ) ;
goto V_294;
}
V_191 -> V_295 = V_297 ;
F_66 ( & V_191 -> V_201 , V_16 ) ;
if ( ! F_115 ( & V_191 -> V_203 ) ) {
V_193 = F_116 ( & V_191 -> V_203 ,
struct V_192 , V_202 ) ;
F_117 ( & V_193 -> V_202 ) ;
V_291 = ! F_115 ( & V_191 -> V_203 ) ;
}
F_68 ( & V_191 -> V_201 , V_16 ) ;
if ( ! V_193 )
goto V_294;
switch ( V_193 -> V_193 ) {
case V_196 :
if ( V_14 -> V_25 ) {
V_14 -> V_25 = false ;
F_13 ( V_22 ) ;
F_12 ( V_22 ) ;
} else {
V_290 = true ;
}
F_118 ( V_193 ) ;
break;
case V_197 :
if ( ! V_14 -> V_25 ) {
V_14 -> V_25 = true ;
F_9 ( V_22 ) ;
F_119 ( V_22 ) ;
}
F_118 ( V_193 ) ;
break;
case V_195 :
if ( ! V_14 -> V_25 ) {
V_14 -> V_25 = true ;
F_9 ( V_22 ) ;
F_119 ( V_22 ) ;
V_193 -> V_193 = V_196 ;
F_66 ( & V_191 -> V_201 , V_16 ) ;
F_120 ( & V_193 -> V_202 , & V_191 -> V_203 ) ;
F_68 ( & V_191 -> V_201 , V_16 ) ;
V_291 = true ;
}
break;
}
F_121 () ;
if ( V_290 )
F_122 ( V_22 ) ;
if ( V_291 )
F_69 ( & V_191 -> V_204 , V_296 ) ;
return;
V_294:
F_121 () ;
}
static void F_123 ( struct V_9 * V_298 )
{
struct V_3 * V_23 = F_6 ( V_298 ) ;
F_124 ( V_23 -> V_119 ) ;
F_124 ( V_23 -> V_210 ) ;
F_125 ( V_298 ) ;
}
static void F_126 ( struct V_1 * V_299 )
{
struct V_300 * V_301 ;
V_301 = F_2 ( V_299 , struct V_300 , V_302 ) ;
F_122 ( V_301 -> V_298 ) ;
F_78 ( & V_301 -> V_211 -> V_215 ) ;
}
static struct V_9 * F_127 ( char * V_303 )
{
struct V_9 * V_234 , * V_304 = NULL ;
int V_305 ;
V_305 = F_128 () ;
F_129 (&init_net, dev) {
if ( memcmp ( V_234 -> V_287 , V_303 , V_284 ) == 0 ) {
if ( V_234 -> V_306 != & V_307 )
continue;
V_304 = V_234 ;
break;
}
}
if ( V_305 )
F_121 () ;
return V_304 ;
}
static int F_130 ( struct V_9 * V_217 )
{
struct V_9 * V_10 ;
struct V_3 * V_23 ;
struct V_11 * V_211 ;
const struct V_308 * V_309 = V_217 -> V_308 ;
if ( V_309 == NULL || V_309 == & V_308 )
return V_310 ;
V_10 = F_127 ( V_217 -> V_287 ) ;
if ( ! V_10 )
return V_310 ;
V_23 = F_6 ( V_10 ) ;
V_211 = V_23 -> V_12 ;
if ( V_211 == NULL )
return V_310 ;
F_131 ( V_10 , L_14 , V_217 -> V_311 ) ;
F_132 ( V_312 ) ;
V_211 -> V_217 = V_217 ;
return V_313 ;
}
static int F_133 ( struct V_9 * V_217 )
{
struct V_9 * V_10 ;
struct V_11 * V_211 ;
const struct V_308 * V_309 = V_217 -> V_308 ;
struct V_3 * V_23 ;
if ( V_309 == & V_308 )
return V_310 ;
V_10 = F_127 ( V_217 -> V_287 ) ;
if ( ! V_10 )
return V_310 ;
V_23 = F_6 ( V_10 ) ;
V_211 = V_23 -> V_12 ;
if ( ( V_211 == NULL ) || ( V_211 -> V_217 == NULL ) )
return V_310 ;
F_131 ( V_10 , L_15 , V_217 -> V_311 ) ;
V_211 -> V_214 = true ;
F_10 ( V_23 -> V_8 ) ;
F_134 ( V_10 , true ) ;
F_131 ( V_10 , L_16 , V_217 -> V_311 ) ;
F_9 ( V_10 ) ;
F_77 ( & V_211 -> V_215 ) ;
V_23 -> V_301 . V_298 = V_217 ;
V_23 -> V_301 . V_211 = V_211 ;
F_7 ( & V_23 -> V_301 . V_302 ) ;
return V_313 ;
}
static int F_135 ( struct V_9 * V_217 )
{
struct V_9 * V_10 ;
struct V_11 * V_211 ;
struct V_3 * V_23 ;
const struct V_308 * V_309 = V_217 -> V_308 ;
if ( V_309 == & V_308 )
return V_310 ;
V_10 = F_127 ( V_217 -> V_287 ) ;
if ( ! V_10 )
return V_310 ;
V_23 = F_6 ( V_10 ) ;
V_211 = V_23 -> V_12 ;
if ( ( V_211 == NULL ) || ( V_211 -> V_217 == NULL ) )
return V_310 ;
F_131 ( V_10 , L_17 , V_217 -> V_311 ) ;
V_211 -> V_214 = false ;
while ( F_136 ( & V_211 -> V_215 ) != 0 )
F_137 ( 50 ) ;
F_134 ( V_10 , false ) ;
F_131 ( V_10 , L_18 , V_217 -> V_311 ) ;
F_17 ( V_23 -> V_8 ) ;
F_13 ( V_10 ) ;
F_77 ( & V_211 -> V_215 ) ;
V_23 -> V_301 . V_298 = V_10 ;
V_23 -> V_301 . V_211 = V_211 ;
F_7 ( & V_23 -> V_301 . V_302 ) ;
return V_313 ;
}
static int F_138 ( struct V_9 * V_217 )
{
struct V_9 * V_10 ;
struct V_11 * V_211 ;
const struct V_308 * V_309 = V_217 -> V_308 ;
struct V_3 * V_23 ;
if ( V_309 == & V_308 )
return V_310 ;
V_10 = F_127 ( V_217 -> V_287 ) ;
if ( ! V_10 )
return V_310 ;
V_23 = F_6 ( V_10 ) ;
V_211 = V_23 -> V_12 ;
if ( V_211 == NULL )
return V_310 ;
F_131 ( V_10 , L_19 , V_217 -> V_311 ) ;
V_211 -> V_217 = NULL ;
F_139 ( V_312 ) ;
return V_313 ;
}
static int F_140 ( struct V_6 * V_234 ,
const struct V_314 * V_315 )
{
struct V_9 * V_22 = NULL ;
struct V_3 * V_23 ;
struct V_235 V_236 ;
struct V_11 * V_12 ;
int V_24 ;
V_22 = F_141 ( sizeof( struct V_3 ) ,
F_88 () ) ;
if ( ! V_22 )
return - V_123 ;
F_9 ( V_22 ) ;
V_23 = F_6 ( V_22 ) ;
V_23 -> V_8 = V_234 ;
V_23 -> V_316 = F_142 ( V_317 , V_318 ) ;
if ( F_143 ( V_23 ) )
F_144 ( V_22 , L_20 ,
V_23 -> V_316 ) ;
V_23 -> V_119 = F_145 ( struct V_118 ) ;
if ( ! V_23 -> V_119 ) {
F_125 ( V_22 ) ;
return - V_123 ;
}
V_23 -> V_210 = F_145 ( struct V_118 ) ;
if ( ! V_23 -> V_210 ) {
F_124 ( V_23 -> V_119 ) ;
F_125 ( V_22 ) ;
return - V_123 ;
}
F_146 ( V_234 , V_22 ) ;
V_23 -> V_238 = false ;
F_147 ( & V_23 -> V_204 , F_112 ) ;
F_148 ( & V_23 -> V_5 , F_1 ) ;
F_148 ( & V_23 -> V_301 . V_302 , F_126 ) ;
F_149 ( & V_23 -> V_201 ) ;
F_150 ( & V_23 -> V_203 ) ;
V_22 -> V_306 = & V_307 ;
V_22 -> V_319 = V_320 ;
V_22 -> V_321 = V_320 | V_322 ;
V_22 -> V_308 = & V_308 ;
F_151 ( V_22 , & V_234 -> V_323 ) ;
V_22 -> V_324 = V_124 ;
memset ( & V_236 , 0 , sizeof( V_236 ) ) ;
V_236 . V_249 = V_249 ;
V_236 . V_250 = V_250 ;
V_24 = F_91 ( V_234 , & V_236 ) ;
if ( V_24 != 0 ) {
F_11 ( V_22 , L_10 , V_24 ) ;
F_123 ( V_22 ) ;
F_146 ( V_234 , NULL ) ;
return V_24 ;
}
memcpy ( V_22 -> V_287 , V_236 . V_325 , V_284 ) ;
V_12 = V_23 -> V_12 ;
F_92 ( V_22 , V_12 -> V_34 ) ;
F_93 ( V_22 , V_12 -> V_34 ) ;
F_96 ( V_22 ) ;
V_24 = F_152 ( V_22 ) ;
if ( V_24 != 0 ) {
F_153 ( L_21 ) ;
F_90 ( V_234 ) ;
F_123 ( V_22 ) ;
}
return V_24 ;
}
static int F_154 ( struct V_6 * V_234 )
{
struct V_9 * V_22 ;
struct V_3 * V_191 ;
struct V_11 * V_9 ;
V_22 = F_3 ( V_234 ) ;
if ( V_22 == NULL ) {
F_155 ( & V_234 -> V_323 , L_22 ) ;
return 0 ;
}
V_191 = F_6 ( V_22 ) ;
V_9 = V_191 -> V_12 ;
F_113 () ;
V_191 -> V_238 = true ;
F_121 () ;
F_156 ( & V_191 -> V_204 ) ;
F_16 ( & V_191 -> V_5 ) ;
F_15 ( V_22 ) ;
F_157 ( V_22 ) ;
F_90 ( V_234 ) ;
F_146 ( V_234 , NULL ) ;
F_123 ( V_22 ) ;
return 0 ;
}
static int F_158 ( struct V_326 * V_327 ,
unsigned long V_193 , void * V_328 )
{
struct V_9 * V_329 = F_159 ( V_328 ) ;
switch ( V_193 ) {
case V_330 :
return F_130 ( V_329 ) ;
case V_331 :
return F_138 ( V_329 ) ;
case V_332 :
return F_133 ( V_329 ) ;
case V_333 :
return F_135 ( V_329 ) ;
default:
return V_310 ;
}
}
static void T_6 F_160 ( void )
{
F_161 ( & V_334 ) ;
F_162 ( & V_335 ) ;
}
static int T_7 F_163 ( void )
{
int V_24 ;
if ( V_249 < V_336 ) {
V_249 = V_336 ;
F_89 ( L_23 ,
V_249 ) ;
}
V_24 = F_164 ( & V_335 ) ;
if ( V_24 )
return V_24 ;
F_165 ( & V_334 ) ;
return 0 ;
}
