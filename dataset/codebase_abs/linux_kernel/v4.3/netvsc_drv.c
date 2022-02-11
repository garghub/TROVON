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
static T_1 F_21 ( T_2 * V_53 , int V_54 , void * V_55 , int V_56 )
{
union V_57 V_58 ;
int V_59 = 4 ;
T_2 V_60 ;
int V_28 , V_61 ;
T_1 V_24 = 0 ;
V_58 . V_62 = 0 ;
V_58 . V_63 = F_22 ( * ( T_1 * ) V_53 ) ;
for ( V_28 = 0 ; V_28 < V_56 ; V_28 ++ ) {
V_58 . V_64 = V_53 [ V_59 ] ;
V_59 = ( V_59 + 1 ) % V_54 ;
V_60 = ( ( T_2 * ) V_55 ) [ V_28 ] ;
for ( V_61 = 0 ; V_61 < 8 ; V_61 ++ ) {
if ( V_60 & 0x80 )
V_24 ^= V_58 . V_63 ;
V_60 <<= 1 ;
V_58 . V_62 <<= 1 ;
}
}
return V_24 ;
}
static bool F_23 ( T_1 * V_65 , struct V_66 * V_67 )
{
struct V_68 V_69 ;
int V_70 ;
if ( ! F_24 ( V_67 , & V_69 , 0 ) ||
! ( V_69 . V_71 . V_72 == F_25 ( V_73 ) ||
V_69 . V_71 . V_72 == F_25 ( V_74 ) ) )
return false ;
if ( V_69 . V_71 . V_75 == V_76 )
V_70 = 12 ;
else
V_70 = 8 ;
* V_65 = F_21 ( V_77 , V_78 , & V_69 , V_70 ) ;
return true ;
}
static T_3 F_26 ( struct V_19 * V_11 , struct V_66 * V_67 ,
void * V_79 , T_4 V_80 )
{
struct V_3 * V_21 = F_6 ( V_11 ) ;
struct V_22 * V_81 = V_21 -> V_10 ;
struct V_6 * V_82 = F_3 ( V_81 ) ;
T_1 V_65 ;
T_3 V_83 = 0 ;
if ( V_82 == NULL || V_11 -> V_84 <= 1 )
return 0 ;
if ( F_23 ( & V_65 , V_67 ) ) {
V_83 = V_82 -> V_85 [ V_65 % V_86 ] %
V_11 -> V_84 ;
F_27 ( V_67 , V_65 , V_87 ) ;
}
return V_83 ;
}
void F_28 ( void * V_88 )
{
struct V_89 * V_90 = (struct V_89 * ) V_88 ;
struct V_66 * V_67 = (struct V_66 * )
( unsigned long ) V_90 -> V_91 ;
if ( V_67 )
F_29 ( V_67 ) ;
}
static T_1 F_30 ( struct V_92 * V_92 , T_1 V_93 , T_1 V_94 ,
struct V_95 * V_96 )
{
int V_61 = 0 ;
V_92 += ( V_93 >> V_97 ) ;
V_93 &= ~ V_98 ;
while ( V_94 > 0 ) {
unsigned long V_99 ;
V_99 = V_100 - V_93 ;
if ( V_99 > V_94 )
V_99 = V_94 ;
V_96 [ V_61 ] . V_101 = F_31 ( V_92 ) ;
V_96 [ V_61 ] . V_93 = V_93 ;
V_96 [ V_61 ] . V_94 = V_99 ;
V_93 += V_99 ;
V_94 -= V_99 ;
if ( V_93 == V_100 && V_94 ) {
V_92 ++ ;
V_93 = 0 ;
V_61 ++ ;
}
}
return V_61 + 1 ;
}
static T_1 F_32 ( void * V_102 , T_1 V_94 , struct V_66 * V_67 ,
struct V_89 * V_90 )
{
struct V_95 * V_96 = V_90 -> V_103 ;
T_1 V_104 = 0 ;
char * V_55 = V_67 -> V_55 ;
int V_105 = F_33 ( V_67 ) -> V_106 ;
int V_28 ;
if ( V_102 != NULL )
V_104 += F_30 ( F_34 ( V_102 ) ,
F_35 ( V_102 ) ,
V_94 , & V_96 [ V_104 ] ) ;
V_90 -> V_107 = V_94 ;
V_90 -> V_108 = V_104 ;
V_104 += F_30 ( F_34 ( V_55 ) ,
F_35 ( V_55 ) ,
F_36 ( V_67 ) , & V_96 [ V_104 ] ) ;
for ( V_28 = 0 ; V_28 < V_105 ; V_28 ++ ) {
T_5 * V_109 = F_33 ( V_67 ) -> V_105 + V_28 ;
V_104 += F_30 ( F_37 ( V_109 ) ,
V_109 -> V_110 ,
F_38 ( V_109 ) , & V_96 [ V_104 ] ) ;
}
return V_104 ;
}
static int F_39 ( struct V_66 * V_67 )
{
int V_28 , V_105 = F_33 ( V_67 ) -> V_106 ;
int V_111 = 0 ;
for ( V_28 = 0 ; V_28 < V_105 ; V_28 ++ ) {
T_5 * V_109 = F_33 ( V_67 ) -> V_105 + V_28 ;
unsigned long V_51 = F_38 ( V_109 ) ;
unsigned long V_93 = V_109 -> V_110 ;
V_93 &= ~ V_98 ;
V_111 += F_40 ( V_93 + V_51 ) ;
}
return V_111 ;
}
static int F_41 ( struct V_66 * V_67 )
{
char * V_55 = V_67 -> V_55 ;
unsigned int V_93 = F_35 ( V_55 ) ;
unsigned int V_94 = F_36 ( V_67 ) ;
int V_112 ;
int V_113 ;
V_112 = F_42 ( V_93 + V_94 , V_100 ) ;
V_113 = F_39 ( V_67 ) ;
return V_112 + V_113 ;
}
static T_1 F_43 ( struct V_66 * V_67 , T_1 * V_114 )
{
T_1 V_115 = V_116 ;
if ( ( F_44 ( V_67 ) -> V_117 != F_25 ( V_73 ) ) &&
( F_44 ( V_67 ) -> V_117 != F_25 ( V_74 ) ) ) {
goto V_118;
}
* V_114 = F_45 ( V_67 ) ;
if ( ( F_44 ( V_67 ) -> V_117 == F_25 ( V_73 ) ) ) {
struct V_119 * V_119 = F_46 ( V_67 ) ;
if ( V_119 -> V_120 == V_76 )
V_115 = V_121 ;
else if ( V_119 -> V_120 == V_122 )
V_115 = V_123 ;
} else {
if ( F_47 ( V_67 ) -> V_124 == V_76 )
V_115 = V_125 ;
else if ( F_47 ( V_67 ) -> V_124 == V_122 )
V_115 = V_126 ;
}
V_118:
return V_115 ;
}
static int F_48 ( struct V_66 * V_67 , struct V_19 * V_20 )
{
struct V_3 * V_21 = F_6 ( V_20 ) ;
struct V_89 * V_90 = NULL ;
int V_24 ;
unsigned int V_127 ;
struct V_39 * V_128 ;
struct V_43 * V_44 ;
T_1 V_129 ;
bool V_130 ;
bool V_131 = false ;
struct V_45 * V_46 ;
struct V_132 * V_133 ;
struct V_134 * V_135 ;
int V_136 ;
T_1 V_137 ;
T_1 V_65 ;
T_1 V_138 ;
T_1 V_139 ;
struct V_95 V_103 [ V_140 ] ;
struct V_141 * V_142 = F_49 ( V_21 -> V_142 ) ;
V_143:
V_138 = V_67 -> V_94 ;
V_127 = F_41 ( V_67 ) + 2 ;
if ( V_127 > V_140 && V_131 ) {
F_50 ( L_4 ,
V_127 , V_67 -> V_94 ) ;
V_24 = - V_144 ;
goto V_145;
} else if ( V_127 > V_140 ) {
if ( F_51 ( V_67 ) ) {
F_50 ( L_5 ) ;
V_24 = - V_146 ;
goto V_145;
}
V_131 = true ;
goto V_143;
}
V_139 = sizeof( struct V_89 ) + V_147 ;
V_24 = F_52 ( V_67 , V_139 ) ;
if ( V_24 ) {
F_11 ( V_20 , L_6 ) ;
V_24 = - V_146 ;
goto V_145;
}
V_90 = (struct V_89 * ) V_67 -> V_148 ;
V_90 -> V_149 = 0 ;
V_90 -> V_150 = V_67 -> V_150 ;
V_90 -> V_151 = V_67 -> V_151 ;
V_90 -> V_103 = V_103 ;
V_90 -> V_83 = F_53 ( V_67 ) ;
V_90 -> V_152 = true ;
V_90 -> V_153 = V_67 -> V_94 ;
V_90 -> V_128 = (struct V_39 * ) ( ( unsigned long ) V_90 +
sizeof( struct V_89 ) ) ;
memset ( V_90 -> V_128 , 0 , V_147 ) ;
V_90 -> V_154 = F_28 ;
V_90 -> V_155 = V_90 ;
V_90 -> V_91 = ( unsigned long ) V_67 ;
V_130 = V_90 -> V_151 & V_156 ;
V_128 = V_90 -> V_128 ;
V_128 -> V_157 = V_158 ;
V_128 -> V_159 = V_90 -> V_153 ;
V_44 = & V_128 -> V_40 . V_47 ;
V_44 -> V_48 = sizeof( struct V_43 ) ;
V_44 -> V_70 = V_90 -> V_153 ;
V_44 -> V_49 = sizeof( struct V_43 ) ;
V_129 = F_54 ( struct V_43 ) ;
V_65 = F_55 ( V_67 ) ;
if ( V_65 != 0 && V_20 -> V_84 > 1 ) {
V_129 += V_160 ;
V_46 = F_20 ( V_128 , V_160 ,
V_161 ) ;
* ( T_1 * ) ( ( void * ) V_46 + V_46 -> V_52 ) = V_65 ;
}
if ( V_130 ) {
struct V_162 * V_163 ;
V_129 += V_164 ;
V_46 = F_20 ( V_128 , V_164 ,
V_165 ) ;
V_163 = (struct V_162 * ) ( ( void * ) V_46 +
V_46 -> V_52 ) ;
V_163 -> V_166 = V_90 -> V_151 & V_167 ;
V_163 -> V_168 = ( V_90 -> V_151 & V_169 ) >>
V_170 ;
}
V_137 = F_43 ( V_67 , & V_136 ) ;
if ( V_137 == V_116 )
goto V_171;
if ( F_56 ( V_67 ) )
goto V_172;
if ( ( V_67 -> V_173 == V_174 ) ||
( V_67 -> V_173 == V_175 ) )
goto V_171;
V_129 += V_176 ;
V_46 = F_20 ( V_128 , V_176 ,
V_177 ) ;
V_133 = (struct V_132 * ) ( ( void * ) V_46 +
V_46 -> V_52 ) ;
if ( V_137 & ( V_178 << 16 ) )
V_133 -> V_179 . V_180 = 1 ;
else
V_133 -> V_179 . V_181 = 1 ;
if ( V_137 & V_182 ) {
V_133 -> V_179 . V_183 = 1 ;
V_133 -> V_179 . V_184 = V_136 ;
} else if ( V_137 & V_185 ) {
struct V_186 * V_187 ;
T_3 V_188 ;
V_24 = F_52 ( V_67 , 0 ) ;
if ( V_24 )
goto V_145;
V_187 = F_57 ( V_67 ) ;
V_188 = F_58 ( V_187 -> V_94 ) ;
V_187 -> V_189 = 0 ;
V_187 -> V_189 = F_59 ( F_46 ( V_67 ) -> V_190 ,
F_46 ( V_67 ) -> V_191 ,
V_188 , V_122 ,
F_60 ( V_187 , V_188 , 0 ) ) ;
if ( V_187 -> V_189 == 0 )
V_187 -> V_189 = V_192 ;
V_133 -> V_179 . V_193 = 0 ;
}
goto V_171;
V_172:
V_129 += V_194 ;
V_46 = F_20 ( V_128 , V_194 ,
V_195 ) ;
V_135 = (struct V_134 * ) ( ( void * ) V_46 +
V_46 -> V_52 ) ;
V_135 -> V_196 . type = V_197 ;
if ( V_137 & ( V_178 << 16 ) ) {
V_135 -> V_196 . V_198 =
V_199 ;
F_46 ( V_67 ) -> V_200 = 0 ;
F_46 ( V_67 ) -> V_189 = 0 ;
F_61 ( V_67 ) -> V_189 =
~ F_59 ( F_46 ( V_67 ) -> V_190 ,
F_46 ( V_67 ) -> V_191 , 0 , V_76 , 0 ) ;
} else {
V_135 -> V_196 . V_198 =
V_201 ;
F_47 ( V_67 ) -> V_202 = 0 ;
F_61 ( V_67 ) -> V_189 =
~ F_62 ( & F_47 ( V_67 ) -> V_190 ,
& F_47 ( V_67 ) -> V_191 , 0 , V_76 , 0 ) ;
}
V_135 -> V_196 . V_184 = V_136 ;
V_135 -> V_196 . V_203 = F_33 ( V_67 ) -> V_204 ;
V_171:
V_128 -> V_159 += V_129 ;
V_90 -> V_153 = V_128 -> V_159 ;
V_90 -> V_205 = F_32 ( V_128 , V_129 ,
V_67 , V_90 ) ;
V_24 = F_63 ( V_21 -> V_10 , V_90 ) ;
V_145:
if ( V_24 == 0 ) {
F_64 ( & V_142 -> V_206 ) ;
V_142 -> V_207 ++ ;
V_142 -> V_99 += V_138 ;
F_65 ( & V_142 -> V_206 ) ;
} else {
if ( V_24 != - V_208 ) {
F_29 ( V_67 ) ;
V_20 -> V_209 . V_210 ++ ;
}
}
return ( V_24 == - V_208 ) ? V_211 : V_212 ;
}
void F_66 ( struct V_22 * V_23 ,
struct V_39 * V_213 )
{
struct V_214 * V_215 = & V_213 -> V_40 . V_216 ;
struct V_19 * V_20 ;
struct V_3 * V_217 ;
struct V_6 * V_19 ;
struct V_8 * V_9 ;
V_19 = F_3 ( V_23 ) ;
V_9 = V_19 -> V_12 ;
switch ( V_215 -> V_149 ) {
case V_218 :
V_9 -> V_25 = false ;
break;
case V_219 :
V_9 -> V_25 = true ;
break;
case V_220 :
V_9 -> V_221 = true ;
break;
default:
return;
}
V_20 = V_19 -> V_11 ;
if ( ! V_20 || V_20 -> V_222 != V_223 )
return;
V_217 = F_6 ( V_20 ) ;
if ( ! V_9 -> V_25 ) {
F_67 ( & V_217 -> V_224 , 0 ) ;
F_67 ( & V_217 -> V_224 , F_68 ( 20 ) ) ;
} else {
F_67 ( & V_217 -> V_224 , 0 ) ;
}
}
int F_69 ( struct V_22 * V_23 ,
struct V_89 * V_90 ,
struct V_132 * V_133 )
{
struct V_19 * V_20 ;
struct V_3 * V_21 ;
struct V_66 * V_67 ;
struct V_141 * V_225 ;
V_20 = ( (struct V_6 * ) F_3 ( V_23 ) ) -> V_11 ;
if ( ! V_20 || V_20 -> V_222 != V_223 ) {
V_90 -> V_149 = V_226 ;
return 0 ;
}
V_21 = F_6 ( V_20 ) ;
V_225 = F_49 ( V_21 -> V_225 ) ;
V_67 = F_70 ( V_20 , V_90 -> V_153 ) ;
if ( F_71 ( ! V_67 ) ) {
++ V_20 -> V_209 . V_227 ;
V_90 -> V_149 = V_226 ;
return 0 ;
}
memcpy ( F_72 ( V_67 , V_90 -> V_153 ) , V_90 -> V_55 ,
V_90 -> V_153 ) ;
V_67 -> V_120 = F_73 ( V_67 , V_20 ) ;
if ( V_133 ) {
if ( V_133 -> V_228 . V_229 )
V_67 -> V_173 = V_175 ;
else
V_67 -> V_173 = V_174 ;
}
if ( V_90 -> V_151 & V_156 )
F_74 ( V_67 , F_25 ( V_230 ) ,
V_90 -> V_151 ) ;
F_75 ( V_67 , V_90 -> V_231 ->
V_232 . V_233 . V_234 ) ;
F_64 ( & V_225 -> V_206 ) ;
V_225 -> V_207 ++ ;
V_225 -> V_99 += V_90 -> V_153 ;
F_65 ( & V_225 -> V_206 ) ;
F_76 ( V_67 ) ;
return 0 ;
}
static void F_77 ( struct V_19 * V_20 ,
struct V_235 * V_236 )
{
F_78 ( V_236 -> V_237 , V_238 , sizeof( V_236 -> V_237 ) ) ;
F_78 ( V_236 -> V_239 , L_7 , sizeof( V_236 -> V_239 ) ) ;
}
static void F_79 ( struct V_19 * V_20 ,
struct V_240 * V_231 )
{
struct V_3 * V_21 = F_6 ( V_20 ) ;
struct V_22 * V_241 = V_21 -> V_10 ;
struct V_6 * V_7 = F_3 ( V_241 ) ;
if ( V_7 ) {
V_231 -> V_242 = V_7 -> V_243 ;
V_231 -> V_244 = V_7 -> V_34 ;
}
}
static int F_80 ( struct V_19 * V_20 ,
struct V_240 * V_245 )
{
struct V_3 * V_21 = F_6 ( V_20 ) ;
struct V_22 * V_241 = V_21 -> V_10 ;
struct V_6 * V_7 = F_3 ( V_241 ) ;
struct V_246 V_247 ;
T_1 V_34 ;
T_1 V_243 ;
int V_24 = 0 ;
bool V_248 = false ;
if ( ! V_7 || V_7 -> V_249 )
return - V_250 ;
V_34 = V_7 -> V_34 ;
V_243 = F_81 ( T_1 , V_7 -> V_243 , F_82 () ) ;
if ( V_7 -> V_251 < V_252 ) {
F_83 ( L_8 ) ;
return - V_253 ;
}
if ( ! V_245 ||
V_245 -> V_254 ||
V_245 -> V_255 ||
V_245 -> V_256 ||
( V_245 -> V_244 < 1 ) )
return - V_253 ;
if ( V_245 -> V_244 > V_243 ) {
F_83 ( L_9 , V_243 ) ;
V_245 -> V_244 = V_243 ;
}
V_24 = F_14 ( V_20 ) ;
if ( V_24 )
goto V_257;
V_258:
V_7 -> V_259 = true ;
F_84 ( V_241 ) ;
V_7 -> V_34 = V_245 -> V_244 ;
V_21 -> V_10 = V_241 ;
F_85 ( V_241 , V_20 ) ;
memset ( & V_247 , 0 , sizeof( V_247 ) ) ;
V_247 . V_34 = V_7 -> V_34 ;
V_247 . V_260 = V_260 ;
V_247 . V_261 = V_261 ;
V_24 = F_86 ( V_241 , & V_247 ) ;
if ( V_24 ) {
if ( V_248 ) {
F_11 ( V_20 , L_10 , V_24 ) ;
return V_24 ;
}
goto V_262;
}
V_7 = F_3 ( V_241 ) ;
V_24 = F_87 ( V_20 , V_7 -> V_34 ) ;
if ( V_24 ) {
if ( V_248 ) {
F_11 ( V_20 , L_11 , V_24 ) ;
return V_24 ;
}
goto V_262;
}
V_24 = F_88 ( V_20 , V_7 -> V_34 ) ;
if ( V_24 ) {
if ( V_248 ) {
F_11 ( V_20 , L_12 , V_24 ) ;
return V_24 ;
}
goto V_262;
}
V_257:
F_8 ( V_20 ) ;
return V_24 ;
V_262:
F_11 ( V_20 , L_13 ) ;
V_248 = true ;
V_245 -> V_244 = V_34 ;
goto V_258;
}
static int F_89 ( struct V_19 * V_11 , int V_263 )
{
struct V_3 * V_4 = F_6 ( V_11 ) ;
struct V_22 * V_81 = V_4 -> V_10 ;
struct V_6 * V_7 = F_3 ( V_81 ) ;
struct V_246 V_247 ;
int V_264 = V_265 ;
int V_24 = 0 ;
if ( V_7 == NULL || V_7 -> V_249 )
return - V_250 ;
if ( V_7 -> V_251 >= V_266 )
V_264 = V_267 - V_268 ;
if ( V_263 < V_269 || V_263 > V_264 )
return - V_253 ;
V_24 = F_14 ( V_11 ) ;
if ( V_24 )
goto V_257;
V_7 -> V_259 = true ;
F_84 ( V_81 ) ;
V_11 -> V_263 = V_263 ;
V_4 -> V_10 = V_81 ;
F_85 ( V_81 , V_11 ) ;
memset ( & V_247 , 0 , sizeof( V_247 ) ) ;
V_247 . V_260 = V_260 ;
V_247 . V_34 = V_7 -> V_34 ;
V_247 . V_261 = V_261 ;
F_86 ( V_81 , & V_247 ) ;
V_257:
F_8 ( V_11 ) ;
return V_24 ;
}
static struct V_270 * F_90 ( struct V_19 * V_20 ,
struct V_270 * V_271 )
{
struct V_3 * V_217 = F_6 ( V_20 ) ;
int V_272 ;
F_91 (cpu) {
struct V_141 * V_142 = F_92 ( V_217 -> V_142 ,
V_272 ) ;
struct V_141 * V_225 = F_92 ( V_217 -> V_225 ,
V_272 ) ;
T_6 V_273 , V_274 , V_275 , V_276 ;
unsigned int V_277 ;
do {
V_277 = F_93 ( & V_142 -> V_206 ) ;
V_273 = V_142 -> V_207 ;
V_274 = V_142 -> V_99 ;
} while ( F_94 ( & V_142 -> V_206 , V_277 ) );
do {
V_277 = F_93 ( & V_225 -> V_206 ) ;
V_275 = V_225 -> V_207 ;
V_276 = V_225 -> V_99 ;
} while ( F_94 ( & V_225 -> V_206 , V_277 ) );
V_271 -> V_274 += V_274 ;
V_271 -> V_273 += V_273 ;
V_271 -> V_276 += V_276 ;
V_271 -> V_275 += V_275 ;
}
V_271 -> V_210 = V_20 -> V_209 . V_210 ;
V_271 -> V_278 = V_20 -> V_209 . V_210 ;
V_271 -> V_227 = V_20 -> V_209 . V_227 ;
V_271 -> V_279 = V_20 -> V_209 . V_279 ;
return V_271 ;
}
static int F_95 ( struct V_19 * V_11 , void * V_280 )
{
struct V_3 * V_4 = F_6 ( V_11 ) ;
struct V_22 * V_81 = V_4 -> V_10 ;
struct V_281 * V_282 = V_280 ;
char V_283 [ V_284 ] ;
unsigned char V_285 ;
int V_286 ;
memcpy ( V_283 , V_11 -> V_287 , V_284 ) ;
V_285 = V_11 -> V_288 ;
V_286 = F_96 ( V_11 , V_280 ) ;
if ( V_286 != 0 )
return V_286 ;
V_286 = F_97 ( V_81 , V_282 -> V_289 ) ;
if ( V_286 != 0 ) {
memcpy ( V_11 -> V_287 , V_283 , V_284 ) ;
V_11 -> V_288 = V_285 ;
}
return V_286 ;
}
static void F_98 ( struct V_19 * V_20 )
{
}
static void F_99 ( struct V_1 * V_2 )
{
struct V_3 * V_217 ;
struct V_19 * V_20 ;
struct V_6 * V_19 ;
struct V_8 * V_9 ;
bool V_290 , V_291 = false ;
char * V_292 [] = { L_14 , L_15 , NULL } ;
char * V_293 [] = { L_16 , L_17 , NULL } ;
F_100 () ;
V_217 = F_2 ( V_2 , struct V_3 , V_224 . V_5 ) ;
V_19 = F_3 ( V_217 -> V_10 ) ;
V_9 = V_19 -> V_12 ;
V_20 = V_19 -> V_11 ;
if ( V_9 -> V_25 ) {
F_9 ( V_20 ) ;
V_290 = false ;
} else {
F_13 ( V_20 ) ;
V_290 = true ;
if ( V_9 -> V_221 ) {
V_9 -> V_221 = false ;
V_291 = true ;
}
}
F_101 () ;
if ( V_291 )
F_102 ( V_292 [ 0 ] , V_292 , V_293 , V_294 ) ;
if ( V_290 )
F_103 ( V_20 ) ;
}
static void F_104 ( struct V_19 * V_295 )
{
struct V_3 * V_21 = F_6 ( V_295 ) ;
F_105 ( V_21 -> V_142 ) ;
F_105 ( V_21 -> V_225 ) ;
F_106 ( V_295 ) ;
}
static int F_107 ( struct V_22 * V_241 ,
const struct V_296 * V_297 )
{
struct V_19 * V_20 = NULL ;
struct V_3 * V_21 ;
struct V_246 V_247 ;
struct V_6 * V_7 ;
int V_24 ;
T_1 V_298 ;
V_20 = F_108 ( sizeof( struct V_3 ) ,
F_82 () ) ;
if ( ! V_20 )
return - V_146 ;
V_298 = sizeof( struct V_89 ) +
V_147 ;
F_9 ( V_20 ) ;
V_21 = F_6 ( V_20 ) ;
V_21 -> V_10 = V_241 ;
V_21 -> V_299 = F_109 ( V_300 , V_301 ) ;
if ( F_110 ( V_21 ) )
F_111 ( V_20 , L_18 ,
V_21 -> V_299 ) ;
V_21 -> V_142 = F_112 ( struct V_141 ) ;
if ( ! V_21 -> V_142 ) {
F_106 ( V_20 ) ;
return - V_146 ;
}
V_21 -> V_225 = F_112 ( struct V_141 ) ;
if ( ! V_21 -> V_225 ) {
F_105 ( V_21 -> V_142 ) ;
F_106 ( V_20 ) ;
return - V_146 ;
}
F_85 ( V_241 , V_20 ) ;
F_113 ( & V_21 -> V_224 , F_99 ) ;
F_114 ( & V_21 -> V_5 , F_1 ) ;
V_20 -> V_302 = & V_303 ;
V_20 -> V_304 = V_305 | V_306 | V_307 |
V_308 ;
V_20 -> V_309 = V_310 | V_306 | V_305 |
V_307 | V_308 ;
V_20 -> V_311 = & V_311 ;
F_115 ( V_20 , & V_241 -> V_312 ) ;
V_20 -> V_313 = V_298 ;
memset ( & V_247 , 0 , sizeof( V_247 ) ) ;
V_247 . V_260 = V_260 ;
V_247 . V_261 = V_261 ;
V_24 = F_86 ( V_241 , & V_247 ) ;
if ( V_24 != 0 ) {
F_11 ( V_20 , L_10 , V_24 ) ;
F_104 ( V_20 ) ;
F_85 ( V_241 , NULL ) ;
return V_24 ;
}
memcpy ( V_20 -> V_287 , V_247 . V_314 , V_284 ) ;
V_7 = F_3 ( V_241 ) ;
F_87 ( V_20 , V_7 -> V_34 ) ;
F_88 ( V_20 , V_7 -> V_34 ) ;
V_24 = F_116 ( V_20 ) ;
if ( V_24 != 0 ) {
F_117 ( L_19 ) ;
F_84 ( V_241 ) ;
F_104 ( V_20 ) ;
} else {
F_67 ( & V_21 -> V_224 , 0 ) ;
}
return V_24 ;
}
static int F_118 ( struct V_22 * V_241 )
{
struct V_19 * V_20 ;
struct V_3 * V_217 ;
struct V_6 * V_19 ;
V_19 = F_3 ( V_241 ) ;
V_20 = V_19 -> V_11 ;
if ( V_20 == NULL ) {
F_119 ( & V_241 -> V_312 , L_20 ) ;
return 0 ;
}
V_19 -> V_259 = true ;
V_217 = F_6 ( V_20 ) ;
F_120 ( & V_217 -> V_224 ) ;
F_16 ( & V_217 -> V_5 ) ;
F_15 ( V_20 ) ;
F_121 ( V_20 ) ;
F_84 ( V_241 ) ;
F_104 ( V_20 ) ;
return 0 ;
}
static void T_7 F_122 ( void )
{
F_123 ( & V_315 ) ;
}
static int T_8 F_124 ( void )
{
if ( V_260 < V_316 ) {
V_260 = V_316 ;
F_83 ( L_21 ,
V_260 ) ;
}
return F_125 ( & V_315 ) ;
}
