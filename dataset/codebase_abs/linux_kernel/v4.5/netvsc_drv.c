static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_5 ) ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
V_7 = F_3 ( V_4 -> V_10 ) ;
if ( V_7 == NULL || V_7 -> V_11 == NULL )
return;
V_9 = V_7 -> V_12 ;
if ( V_9 == NULL )
return;
if ( V_7 -> V_11 -> V_13 & V_14 )
F_4 ( V_9 ,
V_15 ) ;
else
F_4 ( V_9 ,
V_16 |
V_17 |
V_18 ) ;
}
static void F_5 ( struct V_19 * V_20 )
{
struct V_3 * V_21 = F_6 ( V_20 ) ;
F_7 ( & V_21 -> V_5 ) ;
}
static int F_8 ( struct V_19 * V_20 )
{
struct V_3 * V_21 = F_6 ( V_20 ) ;
struct V_22 * V_23 = V_21 -> V_10 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_24 = 0 ;
F_9 ( V_20 ) ;
V_24 = F_10 ( V_23 ) ;
if ( V_24 != 0 ) {
F_11 ( V_20 , L_1 , V_24 ) ;
return V_24 ;
}
F_12 ( V_20 ) ;
V_7 = F_3 ( V_23 ) ;
V_9 = V_7 -> V_12 ;
if ( ! V_9 -> V_25 )
F_13 ( V_20 ) ;
return V_24 ;
}
static int F_14 ( struct V_19 * V_20 )
{
struct V_3 * V_21 = F_6 ( V_20 ) ;
struct V_22 * V_23 = V_21 -> V_10 ;
struct V_6 * V_7 = F_3 ( V_23 ) ;
int V_24 ;
T_1 V_26 , V_27 , V_28 , V_29 = 10 , V_30 = 0 , V_31 = 20 ;
struct V_32 * V_33 ;
F_15 ( V_20 ) ;
F_16 ( & V_21 -> V_5 ) ;
V_24 = F_17 ( V_23 ) ;
if ( V_24 != 0 ) {
F_11 ( V_20 , L_2 , V_24 ) ;
return V_24 ;
}
while ( true ) {
V_26 = 0 ;
for ( V_28 = 0 ; V_28 < V_7 -> V_34 ; V_28 ++ ) {
V_33 = V_7 -> V_35 [ V_28 ] ;
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
F_11 ( V_20 , L_3 ) ;
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
static T_2 F_21 ( struct V_19 * V_11 , struct V_53 * V_54 ,
void * V_55 , T_3 V_56 )
{
struct V_3 * V_21 = F_6 ( V_11 ) ;
struct V_22 * V_57 = V_21 -> V_10 ;
struct V_6 * V_58 = F_3 ( V_57 ) ;
T_1 V_59 ;
T_2 V_60 = 0 ;
if ( V_58 == NULL || V_11 -> V_61 <= 1 )
return 0 ;
V_59 = F_22 ( V_54 ) ;
V_60 = V_58 -> V_62 [ V_59 % V_63 ] %
V_11 -> V_61 ;
if ( ! V_58 -> V_35 [ V_60 ] )
V_60 = 0 ;
return V_60 ;
}
static T_1 F_23 ( struct V_64 * V_64 , T_1 V_65 , T_1 V_66 ,
struct V_67 * V_68 )
{
int V_69 = 0 ;
V_64 += ( V_65 >> V_70 ) ;
V_65 &= ~ V_71 ;
while ( V_66 > 0 ) {
unsigned long V_72 ;
V_72 = V_73 - V_65 ;
if ( V_72 > V_66 )
V_72 = V_66 ;
V_68 [ V_69 ] . V_74 = F_24 ( V_64 ) ;
V_68 [ V_69 ] . V_65 = V_65 ;
V_68 [ V_69 ] . V_66 = V_72 ;
V_65 += V_72 ;
V_66 -= V_72 ;
if ( V_65 == V_73 && V_66 ) {
V_64 ++ ;
V_65 = 0 ;
V_69 ++ ;
}
}
return V_69 + 1 ;
}
static T_1 F_25 ( void * V_75 , T_1 V_66 , struct V_53 * V_54 ,
struct V_76 * V_77 ,
struct V_67 * * V_78 )
{
struct V_67 * V_68 = * V_78 ;
T_1 V_79 = 0 ;
char * V_80 = V_54 -> V_80 ;
int V_81 = F_26 ( V_54 ) -> V_82 ;
int V_28 ;
if ( V_75 != NULL )
V_79 += F_23 ( F_27 ( V_75 ) ,
F_28 ( V_75 ) ,
V_66 , & V_68 [ V_79 ] ) ;
V_77 -> V_83 = V_66 ;
V_77 -> V_84 = V_79 ;
V_79 += F_23 ( F_27 ( V_80 ) ,
F_28 ( V_80 ) ,
F_29 ( V_54 ) , & V_68 [ V_79 ] ) ;
for ( V_28 = 0 ; V_28 < V_81 ; V_28 ++ ) {
T_4 * V_85 = F_26 ( V_54 ) -> V_81 + V_28 ;
V_79 += F_23 ( F_30 ( V_85 ) ,
V_85 -> V_86 ,
F_31 ( V_85 ) , & V_68 [ V_79 ] ) ;
}
return V_79 ;
}
static int F_32 ( struct V_53 * V_54 )
{
int V_28 , V_81 = F_26 ( V_54 ) -> V_82 ;
int V_87 = 0 ;
for ( V_28 = 0 ; V_28 < V_81 ; V_28 ++ ) {
T_4 * V_85 = F_26 ( V_54 ) -> V_81 + V_28 ;
unsigned long V_51 = F_31 ( V_85 ) ;
unsigned long V_65 = V_85 -> V_86 ;
V_65 &= ~ V_71 ;
V_87 += F_33 ( V_65 + V_51 ) ;
}
return V_87 ;
}
static int F_34 ( struct V_53 * V_54 )
{
char * V_80 = V_54 -> V_80 ;
unsigned int V_65 = F_28 ( V_80 ) ;
unsigned int V_66 = F_29 ( V_54 ) ;
int V_88 ;
int V_89 ;
V_88 = F_35 ( V_65 + V_66 , V_73 ) ;
V_89 = F_32 ( V_54 ) ;
return V_88 + V_89 ;
}
static T_1 F_36 ( struct V_53 * V_54 , T_1 * V_90 )
{
T_1 V_91 = V_92 ;
if ( ( F_37 ( V_54 ) -> V_93 != F_38 ( V_94 ) ) &&
( F_37 ( V_54 ) -> V_93 != F_38 ( V_95 ) ) ) {
goto V_96;
}
* V_90 = F_39 ( V_54 ) ;
if ( ( F_37 ( V_54 ) -> V_93 == F_38 ( V_94 ) ) ) {
struct V_97 * V_97 = F_40 ( V_54 ) ;
if ( V_97 -> V_98 == V_99 )
V_91 = V_100 ;
else if ( V_97 -> V_98 == V_101 )
V_91 = V_102 ;
} else {
if ( F_41 ( V_54 ) -> V_103 == V_99 )
V_91 = V_104 ;
else if ( F_41 ( V_54 ) -> V_103 == V_101 )
V_91 = V_105 ;
}
V_96:
return V_91 ;
}
static int F_42 ( struct V_53 * V_54 , struct V_19 * V_20 )
{
struct V_3 * V_21 = F_6 ( V_20 ) ;
struct V_76 * V_77 = NULL ;
int V_24 ;
unsigned int V_106 ;
struct V_39 * V_107 ;
struct V_43 * V_44 ;
T_1 V_108 ;
bool V_109 ;
bool V_110 = false ;
struct V_45 * V_46 ;
struct V_111 * V_112 ;
struct V_113 * V_114 ;
int V_115 ;
T_1 V_116 ;
T_1 V_59 ;
T_1 V_117 ;
struct V_67 V_78 [ V_118 ] ;
struct V_67 * V_68 = V_78 ;
struct V_119 * V_120 = F_43 ( V_21 -> V_120 ) ;
V_121:
V_117 = V_54 -> V_66 ;
V_106 = F_34 ( V_54 ) + 2 ;
if ( V_106 > V_118 && V_110 ) {
F_44 ( L_4 ,
V_106 , V_54 -> V_66 ) ;
V_24 = - V_122 ;
goto V_123;
} else if ( V_106 > V_118 ) {
if ( F_45 ( V_54 ) ) {
F_44 ( L_5 ) ;
V_24 = - V_124 ;
goto V_123;
}
V_110 = true ;
goto V_121;
}
V_24 = F_46 ( V_54 , V_125 ) ;
if ( V_24 ) {
F_11 ( V_20 , L_6 ) ;
V_24 = - V_124 ;
goto V_123;
}
F_47 ( sizeof( struct V_76 ) >
F_48 ( struct V_53 , V_126 ) ) ;
V_77 = (struct V_76 * ) V_54 -> V_126 ;
V_77 -> V_60 = F_49 ( V_54 ) ;
V_77 -> V_127 = V_54 -> V_66 ;
V_107 = (struct V_39 * ) V_54 -> V_128 ;
memset ( V_107 , 0 , V_125 ) ;
V_109 = V_54 -> V_129 & V_130 ;
V_107 -> V_131 = V_132 ;
V_107 -> V_133 = V_77 -> V_127 ;
V_44 = & V_107 -> V_40 . V_47 ;
V_44 -> V_48 = sizeof( struct V_43 ) ;
V_44 -> V_134 = V_77 -> V_127 ;
V_44 -> V_49 = sizeof( struct V_43 ) ;
V_108 = F_50 ( struct V_43 ) ;
V_59 = F_51 ( V_54 ) ;
if ( V_59 != 0 && V_20 -> V_61 > 1 ) {
V_108 += V_135 ;
V_46 = F_20 ( V_107 , V_135 ,
V_136 ) ;
* ( T_1 * ) ( ( void * ) V_46 + V_46 -> V_52 ) = V_59 ;
}
if ( V_109 ) {
struct V_137 * V_138 ;
V_108 += V_139 ;
V_46 = F_20 ( V_107 , V_139 ,
V_140 ) ;
V_138 = (struct V_137 * ) ( ( void * ) V_46 +
V_46 -> V_52 ) ;
V_138 -> V_141 = V_54 -> V_129 & V_142 ;
V_138 -> V_143 = ( V_54 -> V_129 & V_144 ) >>
V_145 ;
}
V_116 = F_36 ( V_54 , & V_115 ) ;
if ( V_116 == V_92 )
goto V_146;
if ( F_52 ( V_54 ) )
goto V_147;
if ( ( V_54 -> V_148 == V_149 ) ||
( V_54 -> V_148 == V_150 ) )
goto V_146;
V_108 += V_151 ;
V_46 = F_20 ( V_107 , V_151 ,
V_152 ) ;
V_112 = (struct V_111 * ) ( ( void * ) V_46 +
V_46 -> V_52 ) ;
if ( V_116 & ( V_153 << 16 ) )
V_112 -> V_154 . V_155 = 1 ;
else
V_112 -> V_154 . V_156 = 1 ;
if ( V_116 & V_157 ) {
V_112 -> V_154 . V_158 = 1 ;
V_112 -> V_154 . V_159 = V_115 ;
} else if ( V_116 & V_160 ) {
struct V_161 * V_162 ;
T_2 V_163 ;
V_24 = F_46 ( V_54 , 0 ) ;
if ( V_24 )
goto V_123;
V_162 = F_53 ( V_54 ) ;
V_163 = F_54 ( V_162 -> V_66 ) ;
V_162 -> V_164 = 0 ;
V_162 -> V_164 = F_55 ( F_40 ( V_54 ) -> V_165 ,
F_40 ( V_54 ) -> V_166 ,
V_163 , V_101 ,
F_56 ( V_162 , V_163 , 0 ) ) ;
if ( V_162 -> V_164 == 0 )
V_162 -> V_164 = V_167 ;
V_112 -> V_154 . V_168 = 0 ;
}
goto V_146;
V_147:
V_108 += V_169 ;
V_46 = F_20 ( V_107 , V_169 ,
V_170 ) ;
V_114 = (struct V_113 * ) ( ( void * ) V_46 +
V_46 -> V_52 ) ;
V_114 -> V_171 . type = V_172 ;
if ( V_116 & ( V_153 << 16 ) ) {
V_114 -> V_171 . V_173 =
V_174 ;
F_40 ( V_54 ) -> V_175 = 0 ;
F_40 ( V_54 ) -> V_164 = 0 ;
F_57 ( V_54 ) -> V_164 =
~ F_55 ( F_40 ( V_54 ) -> V_165 ,
F_40 ( V_54 ) -> V_166 , 0 , V_99 , 0 ) ;
} else {
V_114 -> V_171 . V_173 =
V_176 ;
F_41 ( V_54 ) -> V_177 = 0 ;
F_57 ( V_54 ) -> V_164 =
~ F_58 ( & F_41 ( V_54 ) -> V_165 ,
& F_41 ( V_54 ) -> V_166 , 0 , V_99 , 0 ) ;
}
V_114 -> V_171 . V_159 = V_115 ;
V_114 -> V_171 . V_178 = F_26 ( V_54 ) -> V_179 ;
V_146:
V_107 -> V_133 += V_108 ;
V_77 -> V_127 = V_107 -> V_133 ;
V_77 -> V_180 = F_25 ( V_107 , V_108 ,
V_54 , V_77 , & V_68 ) ;
V_24 = F_59 ( V_21 -> V_10 , V_77 ,
V_107 , & V_68 , V_54 ) ;
V_123:
if ( V_24 == 0 ) {
F_60 ( & V_120 -> V_181 ) ;
V_120 -> V_182 ++ ;
V_120 -> V_72 += V_117 ;
F_61 ( & V_120 -> V_181 ) ;
} else {
if ( V_24 != - V_183 ) {
F_62 ( V_54 ) ;
V_20 -> V_184 . V_185 ++ ;
}
}
return ( V_24 == - V_183 ) ? V_186 : V_187 ;
}
void F_63 ( struct V_22 * V_23 ,
struct V_39 * V_188 )
{
struct V_189 * V_190 = & V_188 -> V_40 . V_191 ;
struct V_19 * V_20 ;
struct V_3 * V_192 ;
struct V_6 * V_19 ;
struct V_193 * V_194 ;
unsigned long V_13 ;
if ( V_190 -> V_195 != V_196 &&
V_190 -> V_195 != V_197 &&
V_190 -> V_195 != V_198 )
return;
V_19 = F_3 ( V_23 ) ;
V_20 = V_19 -> V_11 ;
if ( ! V_20 || V_20 -> V_199 != V_200 )
return;
V_192 = F_6 ( V_20 ) ;
V_194 = F_64 ( sizeof( * V_194 ) , V_201 ) ;
if ( ! V_194 )
return;
V_194 -> V_194 = V_190 -> V_195 ;
F_65 ( & V_192 -> V_202 , V_13 ) ;
F_66 ( & V_194 -> V_203 , & V_192 -> V_204 ) ;
F_67 ( & V_192 -> V_202 , V_13 ) ;
F_68 ( & V_192 -> V_205 , 0 ) ;
}
int F_69 ( struct V_22 * V_23 ,
struct V_76 * V_77 ,
void * * V_80 ,
struct V_111 * V_112 ,
struct V_32 * V_206 ,
T_2 V_129 )
{
struct V_19 * V_20 ;
struct V_3 * V_21 ;
struct V_53 * V_54 ;
struct V_119 * V_207 ;
V_20 = ( (struct V_6 * ) F_3 ( V_23 ) ) -> V_11 ;
if ( ! V_20 || V_20 -> V_199 != V_200 ) {
return V_208 ;
}
V_21 = F_6 ( V_20 ) ;
V_207 = F_43 ( V_21 -> V_207 ) ;
V_54 = F_70 ( V_20 , V_77 -> V_127 ) ;
if ( F_71 ( ! V_54 ) ) {
++ V_20 -> V_184 . V_209 ;
return V_208 ;
}
memcpy ( F_72 ( V_54 , V_77 -> V_127 ) , * V_80 ,
V_77 -> V_127 ) ;
V_54 -> V_98 = F_73 ( V_54 , V_20 ) ;
if ( V_112 ) {
if ( V_112 -> V_210 . V_211 )
V_54 -> V_148 = V_150 ;
else
V_54 -> V_148 = V_149 ;
}
if ( V_129 & V_130 )
F_74 ( V_54 , F_38 ( V_212 ) ,
V_129 ) ;
F_75 ( V_54 , V_206 ->
V_213 . V_214 . V_215 ) ;
F_60 ( & V_207 -> V_181 ) ;
V_207 -> V_182 ++ ;
V_207 -> V_72 += V_77 -> V_127 ;
F_61 ( & V_207 -> V_181 ) ;
F_76 ( V_54 ) ;
return 0 ;
}
static void F_77 ( struct V_19 * V_20 ,
struct V_216 * V_217 )
{
F_78 ( V_217 -> V_218 , V_219 , sizeof( V_217 -> V_218 ) ) ;
F_78 ( V_217 -> V_220 , L_7 , sizeof( V_217 -> V_220 ) ) ;
}
static void F_79 ( struct V_19 * V_20 ,
struct V_221 * V_206 )
{
struct V_3 * V_21 = F_6 ( V_20 ) ;
struct V_22 * V_222 = V_21 -> V_10 ;
struct V_6 * V_7 = F_3 ( V_222 ) ;
if ( V_7 ) {
V_206 -> V_223 = V_7 -> V_224 ;
V_206 -> V_225 = V_7 -> V_34 ;
}
}
static int F_80 ( struct V_19 * V_20 ,
struct V_221 * V_226 )
{
struct V_3 * V_21 = F_6 ( V_20 ) ;
struct V_22 * V_222 = V_21 -> V_10 ;
struct V_6 * V_7 = F_3 ( V_222 ) ;
struct V_227 V_228 ;
T_1 V_34 ;
T_1 V_224 ;
int V_24 = 0 ;
bool V_229 = false ;
if ( ! V_7 || V_7 -> V_230 )
return - V_231 ;
V_34 = V_7 -> V_34 ;
V_224 = F_81 ( T_1 , V_7 -> V_224 , F_82 () ) ;
if ( V_7 -> V_232 < V_233 ) {
F_83 ( L_8 ) ;
return - V_234 ;
}
if ( ! V_226 ||
V_226 -> V_235 ||
V_226 -> V_236 ||
V_226 -> V_237 ||
( V_226 -> V_225 < 1 ) )
return - V_234 ;
if ( V_226 -> V_225 > V_224 ) {
F_83 ( L_9 , V_224 ) ;
V_226 -> V_225 = V_224 ;
}
V_24 = F_14 ( V_20 ) ;
if ( V_24 )
goto V_238;
V_239:
V_7 -> V_240 = true ;
F_84 ( V_222 ) ;
V_7 -> V_34 = V_226 -> V_225 ;
V_21 -> V_10 = V_222 ;
F_85 ( V_222 , V_20 ) ;
memset ( & V_228 , 0 , sizeof( V_228 ) ) ;
V_228 . V_34 = V_7 -> V_34 ;
V_228 . V_241 = V_241 ;
V_228 . V_242 = V_242 ;
V_24 = F_86 ( V_222 , & V_228 ) ;
if ( V_24 ) {
if ( V_229 ) {
F_11 ( V_20 , L_10 , V_24 ) ;
return V_24 ;
}
goto V_243;
}
V_7 = F_3 ( V_222 ) ;
V_24 = F_87 ( V_20 , V_7 -> V_34 ) ;
if ( V_24 ) {
if ( V_229 ) {
F_11 ( V_20 , L_11 , V_24 ) ;
return V_24 ;
}
goto V_243;
}
V_24 = F_88 ( V_20 , V_7 -> V_34 ) ;
if ( V_24 ) {
if ( V_229 ) {
F_11 ( V_20 , L_12 , V_24 ) ;
return V_24 ;
}
goto V_243;
}
V_238:
F_8 ( V_20 ) ;
return V_24 ;
V_243:
F_11 ( V_20 , L_13 ) ;
V_229 = true ;
V_226 -> V_225 = V_34 ;
goto V_239;
}
static int F_89 ( struct V_19 * V_11 , int V_244 )
{
struct V_3 * V_4 = F_6 ( V_11 ) ;
struct V_22 * V_57 = V_4 -> V_10 ;
struct V_6 * V_7 = F_3 ( V_57 ) ;
struct V_227 V_228 ;
int V_245 = V_246 ;
int V_24 = 0 ;
if ( V_7 == NULL || V_7 -> V_230 )
return - V_231 ;
if ( V_7 -> V_232 >= V_247 )
V_245 = V_248 - V_249 ;
if ( V_244 < V_250 || V_244 > V_245 )
return - V_234 ;
V_24 = F_14 ( V_11 ) ;
if ( V_24 )
goto V_238;
V_7 -> V_240 = true ;
F_84 ( V_57 ) ;
V_11 -> V_244 = V_244 ;
V_4 -> V_10 = V_57 ;
F_85 ( V_57 , V_11 ) ;
memset ( & V_228 , 0 , sizeof( V_228 ) ) ;
V_228 . V_241 = V_241 ;
V_228 . V_34 = V_7 -> V_34 ;
V_228 . V_242 = V_242 ;
F_86 ( V_57 , & V_228 ) ;
V_238:
F_8 ( V_11 ) ;
return V_24 ;
}
static struct V_251 * F_90 ( struct V_19 * V_20 ,
struct V_251 * V_252 )
{
struct V_3 * V_192 = F_6 ( V_20 ) ;
int V_253 ;
F_91 (cpu) {
struct V_119 * V_120 = F_92 ( V_192 -> V_120 ,
V_253 ) ;
struct V_119 * V_207 = F_92 ( V_192 -> V_207 ,
V_253 ) ;
T_5 V_254 , V_255 , V_256 , V_257 ;
unsigned int V_258 ;
do {
V_258 = F_93 ( & V_120 -> V_181 ) ;
V_254 = V_120 -> V_182 ;
V_255 = V_120 -> V_72 ;
} while ( F_94 ( & V_120 -> V_181 , V_258 ) );
do {
V_258 = F_93 ( & V_207 -> V_181 ) ;
V_256 = V_207 -> V_182 ;
V_257 = V_207 -> V_72 ;
} while ( F_94 ( & V_207 -> V_181 , V_258 ) );
V_252 -> V_255 += V_255 ;
V_252 -> V_254 += V_254 ;
V_252 -> V_257 += V_257 ;
V_252 -> V_256 += V_256 ;
}
V_252 -> V_185 = V_20 -> V_184 . V_185 ;
V_252 -> V_259 = V_20 -> V_184 . V_185 ;
V_252 -> V_209 = V_20 -> V_184 . V_209 ;
V_252 -> V_260 = V_20 -> V_184 . V_260 ;
return V_252 ;
}
static int F_95 ( struct V_19 * V_11 , void * V_261 )
{
struct V_3 * V_4 = F_6 ( V_11 ) ;
struct V_22 * V_57 = V_4 -> V_10 ;
struct V_262 * V_263 = V_261 ;
char V_264 [ V_265 ] ;
unsigned char V_266 ;
int V_267 ;
memcpy ( V_264 , V_11 -> V_268 , V_265 ) ;
V_266 = V_11 -> V_269 ;
V_267 = F_96 ( V_11 , V_261 ) ;
if ( V_267 != 0 )
return V_267 ;
V_267 = F_97 ( V_57 , V_263 -> V_270 ) ;
if ( V_267 != 0 ) {
memcpy ( V_11 -> V_268 , V_264 , V_265 ) ;
V_11 -> V_269 = V_266 ;
}
return V_267 ;
}
static void F_98 ( struct V_19 * V_20 )
{
}
static void F_99 ( struct V_1 * V_2 )
{
struct V_3 * V_192 ;
struct V_19 * V_20 ;
struct V_6 * V_19 ;
struct V_8 * V_9 ;
struct V_193 * V_194 = NULL ;
bool V_271 = false , V_272 = false ;
unsigned long V_13 , V_273 , V_274 ;
V_192 = F_2 ( V_2 , struct V_3 , V_205 . V_5 ) ;
V_19 = F_3 ( V_192 -> V_10 ) ;
V_9 = V_19 -> V_12 ;
V_20 = V_19 -> V_11 ;
V_273 = V_192 -> V_275 + V_276 ;
if ( F_100 ( V_273 ) ) {
V_274 = V_273 - V_277 ;
V_274 = V_274 < V_276 ? V_274 : V_276 ;
F_68 ( & V_192 -> V_205 , V_274 ) ;
return;
}
V_192 -> V_275 = V_277 ;
F_65 ( & V_192 -> V_202 , V_13 ) ;
if ( ! F_101 ( & V_192 -> V_204 ) ) {
V_194 = F_102 ( & V_192 -> V_204 ,
struct V_193 , V_203 ) ;
F_103 ( & V_194 -> V_203 ) ;
V_272 = ! F_101 ( & V_192 -> V_204 ) ;
}
F_67 ( & V_192 -> V_202 , V_13 ) ;
if ( ! V_194 )
return;
F_104 () ;
switch ( V_194 -> V_194 ) {
case V_197 :
if ( V_9 -> V_25 ) {
V_9 -> V_25 = false ;
F_13 ( V_20 ) ;
F_12 ( V_20 ) ;
} else {
V_271 = true ;
}
F_105 ( V_194 ) ;
break;
case V_198 :
if ( ! V_9 -> V_25 ) {
V_9 -> V_25 = true ;
F_9 ( V_20 ) ;
F_106 ( V_20 ) ;
}
F_105 ( V_194 ) ;
break;
case V_196 :
if ( ! V_9 -> V_25 ) {
V_9 -> V_25 = true ;
F_9 ( V_20 ) ;
F_106 ( V_20 ) ;
V_194 -> V_194 = V_197 ;
F_65 ( & V_192 -> V_202 , V_13 ) ;
F_66 ( & V_194 -> V_203 , & V_192 -> V_204 ) ;
F_67 ( & V_192 -> V_202 , V_13 ) ;
V_272 = true ;
}
break;
}
F_107 () ;
if ( V_271 )
F_108 ( V_20 ) ;
if ( V_272 )
F_68 ( & V_192 -> V_205 , V_276 ) ;
}
static void F_109 ( struct V_19 * V_278 )
{
struct V_3 * V_21 = F_6 ( V_278 ) ;
F_110 ( V_21 -> V_120 ) ;
F_110 ( V_21 -> V_207 ) ;
F_111 ( V_278 ) ;
}
static int F_112 ( struct V_22 * V_222 ,
const struct V_279 * V_280 )
{
struct V_19 * V_20 = NULL ;
struct V_3 * V_21 ;
struct V_227 V_228 ;
struct V_6 * V_7 ;
int V_24 ;
V_20 = F_113 ( sizeof( struct V_3 ) ,
F_82 () ) ;
if ( ! V_20 )
return - V_124 ;
F_9 ( V_20 ) ;
V_21 = F_6 ( V_20 ) ;
V_21 -> V_10 = V_222 ;
V_21 -> V_281 = F_114 ( V_282 , V_283 ) ;
if ( F_115 ( V_21 ) )
F_116 ( V_20 , L_14 ,
V_21 -> V_281 ) ;
V_21 -> V_120 = F_117 ( struct V_119 ) ;
if ( ! V_21 -> V_120 ) {
F_111 ( V_20 ) ;
return - V_124 ;
}
V_21 -> V_207 = F_117 ( struct V_119 ) ;
if ( ! V_21 -> V_207 ) {
F_110 ( V_21 -> V_120 ) ;
F_111 ( V_20 ) ;
return - V_124 ;
}
F_85 ( V_222 , V_20 ) ;
F_118 ( & V_21 -> V_205 , F_99 ) ;
F_119 ( & V_21 -> V_5 , F_1 ) ;
F_120 ( & V_21 -> V_202 ) ;
F_121 ( & V_21 -> V_204 ) ;
V_20 -> V_284 = & V_285 ;
V_20 -> V_286 = V_287 | V_288 | V_289 |
V_290 ;
V_20 -> V_291 = V_292 | V_288 | V_287 |
V_289 | V_290 ;
V_20 -> V_293 = & V_293 ;
F_122 ( V_20 , & V_222 -> V_294 ) ;
V_20 -> V_295 = V_125 ;
memset ( & V_228 , 0 , sizeof( V_228 ) ) ;
V_228 . V_241 = V_241 ;
V_228 . V_242 = V_242 ;
V_24 = F_86 ( V_222 , & V_228 ) ;
if ( V_24 != 0 ) {
F_11 ( V_20 , L_10 , V_24 ) ;
F_109 ( V_20 ) ;
F_85 ( V_222 , NULL ) ;
return V_24 ;
}
memcpy ( V_20 -> V_268 , V_228 . V_296 , V_265 ) ;
V_7 = F_3 ( V_222 ) ;
F_87 ( V_20 , V_7 -> V_34 ) ;
F_88 ( V_20 , V_7 -> V_34 ) ;
V_24 = F_123 ( V_20 ) ;
if ( V_24 != 0 ) {
F_124 ( L_15 ) ;
F_84 ( V_222 ) ;
F_109 ( V_20 ) ;
}
return V_24 ;
}
static int F_125 ( struct V_22 * V_222 )
{
struct V_19 * V_20 ;
struct V_3 * V_192 ;
struct V_6 * V_19 ;
V_19 = F_3 ( V_222 ) ;
V_20 = V_19 -> V_11 ;
if ( V_20 == NULL ) {
F_126 ( & V_222 -> V_294 , L_16 ) ;
return 0 ;
}
V_19 -> V_240 = true ;
V_192 = F_6 ( V_20 ) ;
F_127 ( & V_192 -> V_205 ) ;
F_16 ( & V_192 -> V_5 ) ;
F_15 ( V_20 ) ;
F_128 ( V_20 ) ;
F_84 ( V_222 ) ;
F_109 ( V_20 ) ;
return 0 ;
}
static void T_6 F_129 ( void )
{
F_130 ( & V_297 ) ;
}
static int T_7 F_131 ( void )
{
if ( V_241 < V_298 ) {
V_241 = V_298 ;
F_83 ( L_17 ,
V_241 ) ;
}
return F_132 ( & V_297 ) ;
}
