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
int V_24 ;
F_15 ( V_20 ) ;
F_16 ( & V_21 -> V_5 ) ;
V_24 = F_17 ( V_23 ) ;
if ( V_24 != 0 )
F_11 ( V_20 , L_2 , V_24 ) ;
return V_24 ;
}
static void * F_18 ( struct V_26 * V_27 , T_1 V_28 ,
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
static T_1 F_19 ( T_2 * V_40 , int V_41 , void * V_42 , int V_43 )
{
union V_44 V_45 ;
int V_46 = 4 ;
T_2 V_47 ;
int V_48 , V_49 ;
T_1 V_24 = 0 ;
V_45 . V_50 = 0 ;
V_45 . V_51 = F_20 ( * ( T_1 * ) V_40 ) ;
for ( V_48 = 0 ; V_48 < V_43 ; V_48 ++ ) {
V_45 . V_52 = V_40 [ V_46 ] ;
V_46 = ( V_46 + 1 ) % V_41 ;
V_47 = ( ( T_2 * ) V_42 ) [ V_48 ] ;
for ( V_49 = 0 ; V_49 < 8 ; V_49 ++ ) {
if ( V_47 & 0x80 )
V_24 ^= V_45 . V_51 ;
V_47 <<= 1 ;
V_45 . V_50 <<= 1 ;
}
}
return V_24 ;
}
static bool F_21 ( T_1 * V_53 , struct V_54 * V_55 )
{
struct V_56 V_57 ;
int V_58 ;
if ( ! F_22 ( V_55 , & V_57 ) || V_57 . V_59 != F_23 ( V_60 ) )
return false ;
if ( V_57 . V_61 == V_62 )
V_58 = 12 ;
else
V_58 = 8 ;
* V_53 = F_19 ( V_63 , V_64 , & V_57 , V_58 ) ;
return true ;
}
static T_3 F_24 ( struct V_19 * V_11 , struct V_54 * V_55 ,
void * V_65 , T_4 V_66 )
{
struct V_3 * V_21 = F_6 ( V_11 ) ;
struct V_22 * V_67 = V_21 -> V_10 ;
struct V_6 * V_68 = F_3 ( V_67 ) ;
T_1 V_53 ;
T_3 V_69 = 0 ;
if ( V_68 == NULL || V_11 -> V_70 <= 1 )
return 0 ;
if ( F_21 ( & V_53 , V_55 ) ) {
V_69 = V_68 -> V_71 [ V_53 % V_72 ] %
V_11 -> V_70 ;
F_25 ( V_55 , V_53 , V_73 ) ;
}
return V_69 ;
}
static void F_26 ( void * V_74 )
{
struct V_75 * V_76 = (struct V_75 * ) V_74 ;
struct V_54 * V_55 = (struct V_54 * )
( unsigned long ) V_76 -> V_77 ;
T_1 V_78 = V_76 -> V_79 ;
F_27 ( V_76 ) ;
if ( V_55 && ( V_78 == V_80 ) )
F_28 ( V_55 ) ;
}
static T_1 F_29 ( struct V_81 * V_81 , T_1 V_82 , T_1 V_83 ,
struct V_84 * V_85 )
{
int V_49 = 0 ;
V_81 += ( V_82 >> V_86 ) ;
V_82 &= ~ V_87 ;
while ( V_83 > 0 ) {
unsigned long V_88 ;
V_88 = V_89 - V_82 ;
if ( V_88 > V_83 )
V_88 = V_83 ;
V_85 [ V_49 ] . V_90 = F_30 ( V_81 ) ;
V_85 [ V_49 ] . V_82 = V_82 ;
V_85 [ V_49 ] . V_83 = V_88 ;
V_82 += V_88 ;
V_83 -= V_88 ;
if ( V_82 == V_89 && V_83 ) {
V_81 ++ ;
V_82 = 0 ;
V_49 ++ ;
}
}
return V_49 + 1 ;
}
static T_1 F_31 ( void * V_91 , T_1 V_83 , struct V_54 * V_55 ,
struct V_84 * V_85 )
{
T_1 V_92 = 0 ;
char * V_42 = V_55 -> V_42 ;
int V_93 = F_32 ( V_55 ) -> V_94 ;
int V_48 ;
if ( V_91 != NULL )
V_92 += F_29 ( F_33 ( V_91 ) ,
F_34 ( V_91 ) ,
V_83 , & V_85 [ V_92 ] ) ;
V_92 += F_29 ( F_33 ( V_42 ) ,
F_34 ( V_42 ) ,
F_35 ( V_55 ) , & V_85 [ V_92 ] ) ;
for ( V_48 = 0 ; V_48 < V_93 ; V_48 ++ ) {
T_5 * V_95 = F_32 ( V_55 ) -> V_93 + V_48 ;
V_92 += F_29 ( F_36 ( V_95 ) ,
V_95 -> V_96 ,
F_37 ( V_95 ) , & V_85 [ V_92 ] ) ;
}
return V_92 ;
}
static int F_38 ( struct V_54 * V_55 )
{
int V_48 , V_93 = F_32 ( V_55 ) -> V_94 ;
int V_97 = 0 ;
for ( V_48 = 0 ; V_48 < V_93 ; V_48 ++ ) {
T_5 * V_95 = F_32 ( V_55 ) -> V_93 + V_48 ;
unsigned long V_38 = F_37 ( V_95 ) ;
unsigned long V_82 = V_95 -> V_96 ;
V_82 &= ~ V_87 ;
V_97 += F_39 ( V_82 + V_38 ) ;
}
return V_97 ;
}
static int F_40 ( struct V_54 * V_55 )
{
char * V_42 = V_55 -> V_42 ;
unsigned int V_82 = F_34 ( V_42 ) ;
unsigned int V_83 = F_35 ( V_55 ) ;
int V_98 ;
int V_99 ;
V_98 = F_41 ( V_82 + V_83 , V_89 ) ;
V_99 = F_38 ( V_55 ) ;
return V_98 + V_99 ;
}
static T_1 F_42 ( struct V_54 * V_55 , T_1 * V_100 )
{
T_1 V_101 = V_102 ;
if ( ( F_43 ( V_55 ) -> V_103 != F_23 ( V_60 ) ) &&
( F_43 ( V_55 ) -> V_103 != F_23 ( V_104 ) ) ) {
goto V_105;
}
* V_100 = F_44 ( V_55 ) ;
if ( ( F_43 ( V_55 ) -> V_103 == F_23 ( V_60 ) ) ) {
struct V_106 * V_106 = F_45 ( V_55 ) ;
if ( V_106 -> V_107 == V_62 )
V_101 = V_108 ;
else if ( V_106 -> V_107 == V_109 )
V_101 = V_110 ;
} else {
if ( F_46 ( V_55 ) -> V_111 == V_62 )
V_101 = V_112 ;
else if ( F_46 ( V_55 ) -> V_111 == V_109 )
V_101 = V_113 ;
}
V_105:
return V_101 ;
}
static int F_47 ( struct V_54 * V_55 , struct V_19 * V_20 )
{
struct V_3 * V_21 = F_6 ( V_20 ) ;
struct V_75 * V_76 ;
int V_24 ;
unsigned int V_114 ;
struct V_26 * V_115 ;
struct V_30 * V_31 ;
T_1 V_116 ;
bool V_117 ;
struct V_32 * V_33 ;
struct V_118 * V_119 ;
struct V_120 * V_121 ;
int V_122 ;
T_1 V_123 ;
T_1 V_53 ;
T_1 V_124 = V_55 -> V_83 ;
V_114 = F_40 ( V_55 ) + 2 ;
if ( V_114 > V_125 ) {
F_11 ( V_20 , L_3 , V_55 -> V_83 ) ;
F_48 ( V_55 ) ;
V_20 -> V_126 . V_127 ++ ;
return V_128 ;
}
V_76 = F_49 ( sizeof( struct V_75 ) +
( V_114 * sizeof( struct V_84 ) ) +
sizeof( struct V_26 ) +
V_129 + V_130 +
V_131 + V_132 , V_133 ) ;
if ( ! V_76 ) {
F_11 ( V_20 , L_4 ) ;
F_48 ( V_55 ) ;
V_20 -> V_126 . V_127 ++ ;
return V_128 ;
}
V_76 -> V_134 = V_55 -> V_134 ;
V_76 -> V_69 = F_50 ( V_55 ) ;
V_76 -> V_135 = true ;
V_76 -> V_136 = V_55 -> V_83 ;
V_76 -> V_115 = (struct V_26 * ) ( ( unsigned long ) V_76 +
sizeof( struct V_75 ) +
( V_114 * sizeof( struct V_84 ) ) ) ;
V_76 -> V_137 = F_26 ;
V_76 -> V_138 = V_76 ;
V_76 -> V_77 = ( unsigned long ) V_55 ;
V_117 = V_76 -> V_134 & V_139 ;
V_115 = V_76 -> V_115 ;
V_115 -> V_140 = V_141 ;
V_115 -> V_142 = V_76 -> V_136 ;
V_31 = & V_115 -> V_27 . V_34 ;
V_31 -> V_35 = sizeof( struct V_30 ) ;
V_31 -> V_58 = V_76 -> V_136 ;
V_31 -> V_36 = sizeof( struct V_30 ) ;
V_116 = F_51 ( struct V_30 ) ;
V_53 = F_52 ( V_55 ) ;
if ( V_53 != 0 && V_20 -> V_70 > 1 ) {
V_116 += V_132 ;
V_33 = F_18 ( V_115 , V_132 ,
V_143 ) ;
* ( T_1 * ) ( ( void * ) V_33 + V_33 -> V_39 ) = V_53 ;
}
if ( V_117 ) {
struct V_144 * V_145 ;
V_116 += V_129 ;
V_33 = F_18 ( V_115 , V_129 ,
V_146 ) ;
V_145 = (struct V_144 * ) ( ( void * ) V_33 +
V_33 -> V_39 ) ;
V_145 -> V_147 = V_76 -> V_134 & V_148 ;
V_145 -> V_149 = ( V_76 -> V_134 & V_150 ) >>
V_151 ;
}
V_123 = F_42 ( V_55 , & V_122 ) ;
if ( V_123 == V_102 )
goto V_152;
if ( F_53 ( V_55 ) )
goto V_153;
if ( ( V_55 -> V_154 == V_155 ) ||
( V_55 -> V_154 == V_156 ) )
goto V_152;
V_116 += V_130 ;
V_33 = F_18 ( V_115 , V_130 ,
V_157 ) ;
V_119 = (struct V_118 * ) ( ( void * ) V_33 +
V_33 -> V_39 ) ;
if ( V_123 & ( V_158 << 16 ) )
V_119 -> V_159 . V_160 = 1 ;
else
V_119 -> V_159 . V_161 = 1 ;
if ( V_123 & V_162 ) {
V_119 -> V_159 . V_163 = 1 ;
V_119 -> V_159 . V_164 = V_122 ;
} else if ( V_123 & V_165 ) {
struct V_166 * V_167 ;
T_3 V_168 ;
V_24 = F_54 ( V_55 , 0 ) ;
if ( V_24 )
goto V_169;
V_167 = F_55 ( V_55 ) ;
V_168 = F_56 ( V_167 -> V_83 ) ;
V_167 -> V_170 = 0 ;
V_167 -> V_170 = F_57 ( F_45 ( V_55 ) -> V_171 ,
F_45 ( V_55 ) -> V_172 ,
V_168 , V_109 ,
F_58 ( V_167 , V_168 , 0 ) ) ;
if ( V_167 -> V_170 == 0 )
V_167 -> V_170 = V_173 ;
V_119 -> V_159 . V_174 = 0 ;
}
goto V_152;
V_153:
V_116 += V_131 ;
V_33 = F_18 ( V_115 , V_131 ,
V_175 ) ;
V_121 = (struct V_120 * ) ( ( void * ) V_33 +
V_33 -> V_39 ) ;
V_121 -> V_176 . type = V_177 ;
if ( V_123 & ( V_158 << 16 ) ) {
V_121 -> V_176 . V_178 =
V_179 ;
F_45 ( V_55 ) -> V_180 = 0 ;
F_45 ( V_55 ) -> V_170 = 0 ;
F_59 ( V_55 ) -> V_170 =
~ F_57 ( F_45 ( V_55 ) -> V_171 ,
F_45 ( V_55 ) -> V_172 , 0 , V_62 , 0 ) ;
} else {
V_121 -> V_176 . V_178 =
V_181 ;
F_46 ( V_55 ) -> V_182 = 0 ;
F_59 ( V_55 ) -> V_170 =
~ F_60 ( & F_46 ( V_55 ) -> V_171 ,
& F_46 ( V_55 ) -> V_172 , 0 , V_62 , 0 ) ;
}
V_121 -> V_176 . V_164 = V_122 ;
V_121 -> V_176 . V_183 = F_32 ( V_55 ) -> V_184 ;
V_152:
V_115 -> V_142 += V_116 ;
V_76 -> V_136 = V_115 -> V_142 ;
V_76 -> V_185 = F_31 ( V_115 , V_116 ,
V_55 , & V_76 -> V_186 [ 0 ] ) ;
V_24 = F_61 ( V_21 -> V_10 , V_76 ) ;
V_169:
if ( V_24 == 0 ) {
V_20 -> V_126 . V_187 += V_124 ;
V_20 -> V_126 . V_188 ++ ;
} else {
F_27 ( V_76 ) ;
if ( V_24 != - V_189 ) {
F_28 ( V_55 ) ;
V_20 -> V_126 . V_127 ++ ;
}
}
return ( V_24 == - V_189 ) ? V_190 : V_128 ;
}
void F_62 ( struct V_22 * V_23 ,
struct V_26 * V_191 )
{
struct V_192 * V_193 = & V_191 -> V_27 . V_194 ;
struct V_19 * V_20 ;
struct V_3 * V_195 ;
struct V_6 * V_19 ;
struct V_8 * V_9 ;
V_19 = F_3 ( V_23 ) ;
V_9 = V_19 -> V_12 ;
switch ( V_193 -> V_196 ) {
case V_197 :
V_9 -> V_25 = false ;
break;
case V_198 :
V_9 -> V_25 = true ;
break;
case V_199 :
V_9 -> V_200 = true ;
break;
default:
return;
}
V_20 = V_19 -> V_11 ;
if ( ! V_20 || V_20 -> V_201 != V_202 )
return;
V_195 = F_6 ( V_20 ) ;
if ( ! V_9 -> V_25 ) {
F_63 ( & V_195 -> V_203 , 0 ) ;
F_63 ( & V_195 -> V_203 , F_64 ( 20 ) ) ;
} else {
F_63 ( & V_195 -> V_203 , 0 ) ;
}
}
int F_65 ( struct V_22 * V_23 ,
struct V_75 * V_76 ,
struct V_118 * V_119 )
{
struct V_19 * V_20 ;
struct V_54 * V_55 ;
V_20 = ( (struct V_6 * ) F_3 ( V_23 ) ) -> V_11 ;
if ( ! V_20 || V_20 -> V_201 != V_202 ) {
V_76 -> V_196 = V_204 ;
return 0 ;
}
V_55 = F_66 ( V_20 , V_76 -> V_136 ) ;
if ( F_67 ( ! V_55 ) ) {
++ V_20 -> V_126 . V_205 ;
V_76 -> V_196 = V_204 ;
return 0 ;
}
memcpy ( F_68 ( V_55 , V_76 -> V_136 ) , V_76 -> V_42 ,
V_76 -> V_136 ) ;
V_55 -> V_107 = F_69 ( V_55 , V_20 ) ;
if ( V_119 ) {
if ( V_119 -> V_206 . V_207 )
V_55 -> V_154 = V_156 ;
else
V_55 -> V_154 = V_155 ;
}
if ( V_76 -> V_134 & V_139 )
F_70 ( V_55 , F_23 ( V_208 ) ,
V_76 -> V_134 ) ;
F_71 ( V_55 , V_76 -> V_209 ->
V_210 . V_211 . V_212 ) ;
V_20 -> V_126 . V_213 ++ ;
V_20 -> V_126 . V_214 += V_76 -> V_136 ;
F_72 ( V_55 ) ;
return 0 ;
}
static void F_73 ( struct V_19 * V_20 ,
struct V_215 * V_216 )
{
F_74 ( V_216 -> V_217 , V_218 , sizeof( V_216 -> V_217 ) ) ;
F_74 ( V_216 -> V_219 , L_5 , sizeof( V_216 -> V_219 ) ) ;
}
static int F_75 ( struct V_19 * V_11 , int V_220 )
{
struct V_3 * V_4 = F_6 ( V_11 ) ;
struct V_22 * V_67 = V_4 -> V_10 ;
struct V_6 * V_7 = F_3 ( V_67 ) ;
struct V_221 V_222 ;
int V_223 = V_224 ;
if ( V_7 == NULL || V_7 -> V_225 )
return - V_226 ;
if ( V_7 -> V_227 >= V_228 )
V_223 = V_229 ;
if ( V_220 < 68 || V_220 > V_223 )
return - V_230 ;
V_7 -> V_231 = true ;
F_16 ( & V_4 -> V_5 ) ;
F_15 ( V_11 ) ;
F_76 ( V_67 ) ;
V_11 -> V_220 = V_220 ;
V_4 -> V_10 = V_67 ;
F_77 ( V_67 , V_11 ) ;
V_222 . V_232 = V_232 ;
F_78 ( V_67 , & V_222 ) ;
F_79 ( V_11 ) ;
return 0 ;
}
static int F_80 ( struct V_19 * V_11 , void * V_233 )
{
struct V_3 * V_4 = F_6 ( V_11 ) ;
struct V_22 * V_67 = V_4 -> V_10 ;
struct V_234 * V_235 = V_233 ;
char V_236 [ V_237 ] ;
unsigned char V_238 ;
int V_239 ;
memcpy ( V_236 , V_11 -> V_240 , V_237 ) ;
V_238 = V_11 -> V_241 ;
V_239 = F_81 ( V_11 , V_233 ) ;
if ( V_239 != 0 )
return V_239 ;
V_239 = F_82 ( V_67 , V_235 -> V_242 ) ;
if ( V_239 != 0 ) {
memcpy ( V_11 -> V_240 , V_236 , V_237 ) ;
V_11 -> V_241 = V_238 ;
}
return V_239 ;
}
static void F_83 ( struct V_19 * V_20 )
{
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_3 * V_195 ;
struct V_19 * V_20 ;
struct V_6 * V_19 ;
struct V_8 * V_9 ;
bool V_243 , V_244 = false ;
char * V_245 [] = { L_6 , L_7 , NULL } ;
char * V_246 [] = { L_8 , L_9 , NULL } ;
F_85 () ;
V_195 = F_2 ( V_2 , struct V_3 , V_203 . V_5 ) ;
V_19 = F_3 ( V_195 -> V_10 ) ;
V_9 = V_19 -> V_12 ;
V_20 = V_19 -> V_11 ;
if ( V_9 -> V_25 ) {
F_9 ( V_20 ) ;
V_243 = false ;
} else {
F_13 ( V_20 ) ;
V_243 = true ;
if ( V_9 -> V_200 ) {
V_9 -> V_200 = false ;
V_244 = true ;
}
}
F_86 () ;
if ( V_244 )
F_87 ( V_245 [ 0 ] , V_245 , V_246 , V_247 ) ;
if ( V_243 )
F_88 ( V_20 ) ;
}
static int F_89 ( struct V_22 * V_248 ,
const struct V_249 * V_250 )
{
struct V_19 * V_20 = NULL ;
struct V_3 * V_21 ;
struct V_221 V_222 ;
struct V_6 * V_7 ;
int V_24 ;
V_20 = F_90 ( sizeof( struct V_3 ) ,
F_91 () ) ;
if ( ! V_20 )
return - V_251 ;
F_9 ( V_20 ) ;
V_21 = F_6 ( V_20 ) ;
V_21 -> V_10 = V_248 ;
F_77 ( V_248 , V_20 ) ;
F_92 ( & V_21 -> V_203 , F_84 ) ;
F_93 ( & V_21 -> V_5 , F_1 ) ;
V_20 -> V_252 = & V_253 ;
V_20 -> V_254 = V_255 | V_256 | V_257 |
V_258 ;
V_20 -> V_259 = V_260 | V_256 | V_255 |
V_257 | V_258 ;
V_20 -> V_261 = & V_261 ;
F_94 ( V_20 , & V_248 -> V_262 ) ;
V_222 . V_232 = V_232 ;
V_24 = F_78 ( V_248 , & V_222 ) ;
if ( V_24 != 0 ) {
F_11 ( V_20 , L_10 , V_24 ) ;
F_95 ( V_20 ) ;
F_77 ( V_248 , NULL ) ;
return V_24 ;
}
memcpy ( V_20 -> V_240 , V_222 . V_263 , V_237 ) ;
V_7 = F_3 ( V_248 ) ;
F_96 ( V_20 , V_7 -> V_264 ) ;
F_97 ( V_20 , V_7 -> V_264 ) ;
V_24 = F_98 ( V_20 ) ;
if ( V_24 != 0 ) {
F_99 ( L_11 ) ;
F_76 ( V_248 ) ;
F_95 ( V_20 ) ;
} else {
F_63 ( & V_21 -> V_203 , 0 ) ;
}
return V_24 ;
}
static int F_100 ( struct V_22 * V_248 )
{
struct V_19 * V_20 ;
struct V_3 * V_195 ;
struct V_6 * V_19 ;
V_19 = F_3 ( V_248 ) ;
V_20 = V_19 -> V_11 ;
if ( V_20 == NULL ) {
F_101 ( & V_248 -> V_262 , L_12 ) ;
return 0 ;
}
V_19 -> V_231 = true ;
V_195 = F_6 ( V_20 ) ;
F_102 ( & V_195 -> V_203 ) ;
F_16 ( & V_195 -> V_5 ) ;
F_15 ( V_20 ) ;
F_103 ( V_20 ) ;
F_76 ( V_248 ) ;
F_95 ( V_20 ) ;
return 0 ;
}
static void T_6 F_104 ( void )
{
F_105 ( & V_265 ) ;
}
static int T_7 F_106 ( void )
{
if ( V_232 < V_266 ) {
V_232 = V_266 ;
F_107 ( L_13 ,
V_232 ) ;
}
return F_108 ( & V_265 ) ;
}
