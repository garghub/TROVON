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
if ( ! F_22 ( V_55 , & V_57 ) ||
! ( V_57 . V_59 . V_60 == F_23 ( V_61 ) ||
V_57 . V_59 . V_60 == F_23 ( V_62 ) ) )
return false ;
if ( V_57 . V_59 . V_63 == V_64 )
V_58 = 12 ;
else
V_58 = 8 ;
* V_53 = F_19 ( V_65 , V_66 , & V_57 , V_58 ) ;
return true ;
}
static T_3 F_24 ( struct V_19 * V_11 , struct V_54 * V_55 ,
void * V_67 , T_4 V_68 )
{
struct V_3 * V_21 = F_6 ( V_11 ) ;
struct V_22 * V_69 = V_21 -> V_10 ;
struct V_6 * V_70 = F_3 ( V_69 ) ;
T_1 V_53 ;
T_3 V_71 = 0 ;
if ( V_70 == NULL || V_11 -> V_72 <= 1 )
return 0 ;
if ( F_21 ( & V_53 , V_55 ) ) {
V_71 = V_70 -> V_73 [ V_53 % V_74 ] %
V_11 -> V_72 ;
F_25 ( V_55 , V_53 , V_75 ) ;
}
return V_71 ;
}
void F_26 ( void * V_76 )
{
struct V_77 * V_78 = (struct V_77 * ) V_76 ;
struct V_54 * V_55 = (struct V_54 * )
( unsigned long ) V_78 -> V_79 ;
if ( V_55 )
F_27 ( V_55 ) ;
}
static T_1 F_28 ( struct V_80 * V_80 , T_1 V_81 , T_1 V_82 ,
struct V_83 * V_84 )
{
int V_49 = 0 ;
V_80 += ( V_81 >> V_85 ) ;
V_81 &= ~ V_86 ;
while ( V_82 > 0 ) {
unsigned long V_87 ;
V_87 = V_88 - V_81 ;
if ( V_87 > V_82 )
V_87 = V_82 ;
V_84 [ V_49 ] . V_89 = F_29 ( V_80 ) ;
V_84 [ V_49 ] . V_81 = V_81 ;
V_84 [ V_49 ] . V_82 = V_87 ;
V_81 += V_87 ;
V_82 -= V_87 ;
if ( V_81 == V_88 && V_82 ) {
V_80 ++ ;
V_81 = 0 ;
V_49 ++ ;
}
}
return V_49 + 1 ;
}
static T_1 F_30 ( void * V_90 , T_1 V_82 , struct V_54 * V_55 ,
struct V_77 * V_78 )
{
struct V_83 * V_84 = V_78 -> V_91 ;
T_1 V_92 = 0 ;
char * V_42 = V_55 -> V_42 ;
int V_93 = F_31 ( V_55 ) -> V_94 ;
int V_48 ;
if ( V_90 != NULL )
V_92 += F_28 ( F_32 ( V_90 ) ,
F_33 ( V_90 ) ,
V_82 , & V_84 [ V_92 ] ) ;
V_78 -> V_95 = V_82 ;
V_78 -> V_96 = V_92 ;
V_92 += F_28 ( F_32 ( V_42 ) ,
F_33 ( V_42 ) ,
F_34 ( V_55 ) , & V_84 [ V_92 ] ) ;
for ( V_48 = 0 ; V_48 < V_93 ; V_48 ++ ) {
T_5 * V_97 = F_31 ( V_55 ) -> V_93 + V_48 ;
V_92 += F_28 ( F_35 ( V_97 ) ,
V_97 -> V_98 ,
F_36 ( V_97 ) , & V_84 [ V_92 ] ) ;
}
return V_92 ;
}
static int F_37 ( struct V_54 * V_55 )
{
int V_48 , V_93 = F_31 ( V_55 ) -> V_94 ;
int V_99 = 0 ;
for ( V_48 = 0 ; V_48 < V_93 ; V_48 ++ ) {
T_5 * V_97 = F_31 ( V_55 ) -> V_93 + V_48 ;
unsigned long V_38 = F_36 ( V_97 ) ;
unsigned long V_81 = V_97 -> V_98 ;
V_81 &= ~ V_86 ;
V_99 += F_38 ( V_81 + V_38 ) ;
}
return V_99 ;
}
static int F_39 ( struct V_54 * V_55 )
{
char * V_42 = V_55 -> V_42 ;
unsigned int V_81 = F_33 ( V_42 ) ;
unsigned int V_82 = F_34 ( V_55 ) ;
int V_100 ;
int V_101 ;
V_100 = F_40 ( V_81 + V_82 , V_88 ) ;
V_101 = F_37 ( V_55 ) ;
return V_100 + V_101 ;
}
static T_1 F_41 ( struct V_54 * V_55 , T_1 * V_102 )
{
T_1 V_103 = V_104 ;
if ( ( F_42 ( V_55 ) -> V_105 != F_23 ( V_61 ) ) &&
( F_42 ( V_55 ) -> V_105 != F_23 ( V_62 ) ) ) {
goto V_106;
}
* V_102 = F_43 ( V_55 ) ;
if ( ( F_42 ( V_55 ) -> V_105 == F_23 ( V_61 ) ) ) {
struct V_107 * V_107 = F_44 ( V_55 ) ;
if ( V_107 -> V_108 == V_64 )
V_103 = V_109 ;
else if ( V_107 -> V_108 == V_110 )
V_103 = V_111 ;
} else {
if ( F_45 ( V_55 ) -> V_112 == V_64 )
V_103 = V_113 ;
else if ( F_45 ( V_55 ) -> V_112 == V_110 )
V_103 = V_114 ;
}
V_106:
return V_103 ;
}
static int F_46 ( struct V_54 * V_55 , struct V_19 * V_20 )
{
struct V_3 * V_21 = F_6 ( V_20 ) ;
struct V_77 * V_78 = NULL ;
int V_24 ;
unsigned int V_115 ;
struct V_26 * V_116 ;
struct V_30 * V_31 ;
T_1 V_117 ;
bool V_118 ;
bool V_119 = false ;
struct V_32 * V_33 ;
struct V_120 * V_121 ;
struct V_122 * V_123 ;
int V_124 ;
T_1 V_125 ;
T_1 V_53 ;
T_1 V_126 ;
T_1 V_127 ;
struct V_83 V_91 [ V_128 ] ;
struct V_129 * V_130 = F_47 ( V_21 -> V_130 ) ;
V_131:
V_126 = V_55 -> V_82 ;
V_115 = F_39 ( V_55 ) + 2 ;
if ( V_115 > V_128 && V_119 ) {
F_48 ( L_3 ,
V_115 , V_55 -> V_82 ) ;
V_24 = - V_132 ;
goto V_133;
} else if ( V_115 > V_128 ) {
if ( F_49 ( V_55 ) ) {
F_48 ( L_4 ) ;
V_24 = - V_134 ;
goto V_133;
}
V_119 = true ;
goto V_131;
}
V_127 = sizeof( struct V_77 ) + V_135 ;
V_24 = F_50 ( V_55 , V_127 ) ;
if ( V_24 ) {
F_11 ( V_20 , L_5 ) ;
V_24 = - V_134 ;
goto V_133;
}
V_78 = (struct V_77 * ) V_55 -> V_136 ;
V_78 -> V_137 = 0 ;
V_78 -> V_138 = V_55 -> V_138 ;
V_78 -> V_139 = V_55 -> V_139 ;
V_78 -> V_91 = V_91 ;
V_78 -> V_71 = F_51 ( V_55 ) ;
V_78 -> V_140 = true ;
V_78 -> V_141 = V_55 -> V_82 ;
V_78 -> V_116 = (struct V_26 * ) ( ( unsigned long ) V_78 +
sizeof( struct V_77 ) ) ;
memset ( V_78 -> V_116 , 0 , V_135 ) ;
V_78 -> V_142 = F_26 ;
V_78 -> V_143 = V_78 ;
V_78 -> V_79 = ( unsigned long ) V_55 ;
V_118 = V_78 -> V_139 & V_144 ;
V_116 = V_78 -> V_116 ;
V_116 -> V_145 = V_146 ;
V_116 -> V_147 = V_78 -> V_141 ;
V_31 = & V_116 -> V_27 . V_34 ;
V_31 -> V_35 = sizeof( struct V_30 ) ;
V_31 -> V_58 = V_78 -> V_141 ;
V_31 -> V_36 = sizeof( struct V_30 ) ;
V_117 = F_52 ( struct V_30 ) ;
V_53 = F_53 ( V_55 ) ;
if ( V_53 != 0 && V_20 -> V_72 > 1 ) {
V_117 += V_148 ;
V_33 = F_18 ( V_116 , V_148 ,
V_149 ) ;
* ( T_1 * ) ( ( void * ) V_33 + V_33 -> V_39 ) = V_53 ;
}
if ( V_118 ) {
struct V_150 * V_151 ;
V_117 += V_152 ;
V_33 = F_18 ( V_116 , V_152 ,
V_153 ) ;
V_151 = (struct V_150 * ) ( ( void * ) V_33 +
V_33 -> V_39 ) ;
V_151 -> V_154 = V_78 -> V_139 & V_155 ;
V_151 -> V_156 = ( V_78 -> V_139 & V_157 ) >>
V_158 ;
}
V_125 = F_41 ( V_55 , & V_124 ) ;
if ( V_125 == V_104 )
goto V_159;
if ( F_54 ( V_55 ) )
goto V_160;
if ( ( V_55 -> V_161 == V_162 ) ||
( V_55 -> V_161 == V_163 ) )
goto V_159;
V_117 += V_164 ;
V_33 = F_18 ( V_116 , V_164 ,
V_165 ) ;
V_121 = (struct V_120 * ) ( ( void * ) V_33 +
V_33 -> V_39 ) ;
if ( V_125 & ( V_166 << 16 ) )
V_121 -> V_167 . V_168 = 1 ;
else
V_121 -> V_167 . V_169 = 1 ;
if ( V_125 & V_170 ) {
V_121 -> V_167 . V_171 = 1 ;
V_121 -> V_167 . V_172 = V_124 ;
} else if ( V_125 & V_173 ) {
struct V_174 * V_175 ;
T_3 V_176 ;
V_24 = F_50 ( V_55 , 0 ) ;
if ( V_24 )
goto V_133;
V_175 = F_55 ( V_55 ) ;
V_176 = F_56 ( V_175 -> V_82 ) ;
V_175 -> V_177 = 0 ;
V_175 -> V_177 = F_57 ( F_44 ( V_55 ) -> V_178 ,
F_44 ( V_55 ) -> V_179 ,
V_176 , V_110 ,
F_58 ( V_175 , V_176 , 0 ) ) ;
if ( V_175 -> V_177 == 0 )
V_175 -> V_177 = V_180 ;
V_121 -> V_167 . V_181 = 0 ;
}
goto V_159;
V_160:
V_117 += V_182 ;
V_33 = F_18 ( V_116 , V_182 ,
V_183 ) ;
V_123 = (struct V_122 * ) ( ( void * ) V_33 +
V_33 -> V_39 ) ;
V_123 -> V_184 . type = V_185 ;
if ( V_125 & ( V_166 << 16 ) ) {
V_123 -> V_184 . V_186 =
V_187 ;
F_44 ( V_55 ) -> V_188 = 0 ;
F_44 ( V_55 ) -> V_177 = 0 ;
F_59 ( V_55 ) -> V_177 =
~ F_57 ( F_44 ( V_55 ) -> V_178 ,
F_44 ( V_55 ) -> V_179 , 0 , V_64 , 0 ) ;
} else {
V_123 -> V_184 . V_186 =
V_189 ;
F_45 ( V_55 ) -> V_190 = 0 ;
F_59 ( V_55 ) -> V_177 =
~ F_60 ( & F_45 ( V_55 ) -> V_178 ,
& F_45 ( V_55 ) -> V_179 , 0 , V_64 , 0 ) ;
}
V_123 -> V_184 . V_172 = V_124 ;
V_123 -> V_184 . V_191 = F_31 ( V_55 ) -> V_192 ;
V_159:
V_116 -> V_147 += V_117 ;
V_78 -> V_141 = V_116 -> V_147 ;
V_78 -> V_193 = F_30 ( V_116 , V_117 ,
V_55 , V_78 ) ;
V_24 = F_61 ( V_21 -> V_10 , V_78 ) ;
V_133:
if ( V_24 == 0 ) {
F_62 ( & V_130 -> V_194 ) ;
V_130 -> V_195 ++ ;
V_130 -> V_87 += V_126 ;
F_63 ( & V_130 -> V_194 ) ;
} else {
if ( V_24 != - V_196 ) {
F_27 ( V_55 ) ;
V_20 -> V_197 . V_198 ++ ;
}
}
return ( V_24 == - V_196 ) ? V_199 : V_200 ;
}
void F_64 ( struct V_22 * V_23 ,
struct V_26 * V_201 )
{
struct V_202 * V_203 = & V_201 -> V_27 . V_204 ;
struct V_19 * V_20 ;
struct V_3 * V_205 ;
struct V_6 * V_19 ;
struct V_8 * V_9 ;
V_19 = F_3 ( V_23 ) ;
V_9 = V_19 -> V_12 ;
switch ( V_203 -> V_137 ) {
case V_206 :
V_9 -> V_25 = false ;
break;
case V_207 :
V_9 -> V_25 = true ;
break;
case V_208 :
V_9 -> V_209 = true ;
break;
default:
return;
}
V_20 = V_19 -> V_11 ;
if ( ! V_20 || V_20 -> V_210 != V_211 )
return;
V_205 = F_6 ( V_20 ) ;
if ( ! V_9 -> V_25 ) {
F_65 ( & V_205 -> V_212 , 0 ) ;
F_65 ( & V_205 -> V_212 , F_66 ( 20 ) ) ;
} else {
F_65 ( & V_205 -> V_212 , 0 ) ;
}
}
int F_67 ( struct V_22 * V_23 ,
struct V_77 * V_78 ,
struct V_120 * V_121 )
{
struct V_19 * V_20 ;
struct V_3 * V_21 ;
struct V_54 * V_55 ;
struct V_129 * V_213 ;
V_20 = ( (struct V_6 * ) F_3 ( V_23 ) ) -> V_11 ;
if ( ! V_20 || V_20 -> V_210 != V_211 ) {
V_78 -> V_137 = V_214 ;
return 0 ;
}
V_21 = F_6 ( V_20 ) ;
V_213 = F_47 ( V_21 -> V_213 ) ;
V_55 = F_68 ( V_20 , V_78 -> V_141 ) ;
if ( F_69 ( ! V_55 ) ) {
++ V_20 -> V_197 . V_215 ;
V_78 -> V_137 = V_214 ;
return 0 ;
}
memcpy ( F_70 ( V_55 , V_78 -> V_141 ) , V_78 -> V_42 ,
V_78 -> V_141 ) ;
V_55 -> V_108 = F_71 ( V_55 , V_20 ) ;
if ( V_121 ) {
if ( V_121 -> V_216 . V_217 )
V_55 -> V_161 = V_163 ;
else
V_55 -> V_161 = V_162 ;
}
if ( V_78 -> V_139 & V_144 )
F_72 ( V_55 , F_23 ( V_218 ) ,
V_78 -> V_139 ) ;
F_73 ( V_55 , V_78 -> V_219 ->
V_220 . V_221 . V_222 ) ;
F_62 ( & V_213 -> V_194 ) ;
V_213 -> V_195 ++ ;
V_213 -> V_87 += V_78 -> V_141 ;
F_63 ( & V_213 -> V_194 ) ;
F_74 ( V_55 ) ;
return 0 ;
}
static void F_75 ( struct V_19 * V_20 ,
struct V_223 * V_224 )
{
F_76 ( V_224 -> V_225 , V_226 , sizeof( V_224 -> V_225 ) ) ;
F_76 ( V_224 -> V_227 , L_6 , sizeof( V_224 -> V_227 ) ) ;
}
static void F_77 ( struct V_19 * V_20 ,
struct V_228 * V_219 )
{
struct V_3 * V_21 = F_6 ( V_20 ) ;
struct V_22 * V_229 = V_21 -> V_10 ;
struct V_6 * V_7 = F_3 ( V_229 ) ;
if ( V_7 ) {
V_219 -> V_230 = V_7 -> V_231 ;
V_219 -> V_232 = V_7 -> V_233 ;
}
}
static int F_78 ( struct V_19 * V_11 , int V_234 )
{
struct V_3 * V_4 = F_6 ( V_11 ) ;
struct V_22 * V_69 = V_4 -> V_10 ;
struct V_6 * V_7 = F_3 ( V_69 ) ;
struct V_235 V_236 ;
int V_237 = V_238 ;
if ( V_7 == NULL || V_7 -> V_239 )
return - V_240 ;
if ( V_7 -> V_241 >= V_242 )
V_237 = V_243 - V_244 ;
if ( V_234 < V_238 || V_234 > V_237 )
return - V_245 ;
V_7 -> V_246 = true ;
F_16 ( & V_4 -> V_5 ) ;
F_15 ( V_11 ) ;
F_79 ( V_69 ) ;
V_11 -> V_234 = V_234 ;
V_4 -> V_10 = V_69 ;
F_80 ( V_69 , V_11 ) ;
V_236 . V_247 = V_247 ;
V_236 . V_248 = V_248 ;
F_81 ( V_69 , & V_236 ) ;
F_82 ( V_11 ) ;
return 0 ;
}
static struct V_249 * F_83 ( struct V_19 * V_20 ,
struct V_249 * V_250 )
{
struct V_3 * V_205 = F_6 ( V_20 ) ;
int V_251 ;
F_84 (cpu) {
struct V_129 * V_130 = F_85 ( V_205 -> V_130 ,
V_251 ) ;
struct V_129 * V_213 = F_85 ( V_205 -> V_213 ,
V_251 ) ;
T_6 V_252 , V_253 , V_254 , V_255 ;
unsigned int V_256 ;
do {
V_256 = F_86 ( & V_130 -> V_194 ) ;
V_252 = V_130 -> V_195 ;
V_253 = V_130 -> V_87 ;
} while ( F_87 ( & V_130 -> V_194 , V_256 ) );
do {
V_256 = F_86 ( & V_213 -> V_194 ) ;
V_254 = V_213 -> V_195 ;
V_255 = V_213 -> V_87 ;
} while ( F_87 ( & V_213 -> V_194 , V_256 ) );
V_250 -> V_253 += V_253 ;
V_250 -> V_252 += V_252 ;
V_250 -> V_255 += V_255 ;
V_250 -> V_254 += V_254 ;
}
V_250 -> V_198 = V_20 -> V_197 . V_198 ;
V_250 -> V_257 = V_20 -> V_197 . V_198 ;
V_250 -> V_215 = V_20 -> V_197 . V_215 ;
V_250 -> V_258 = V_20 -> V_197 . V_258 ;
return V_250 ;
}
static int F_88 ( struct V_19 * V_11 , void * V_259 )
{
struct V_3 * V_4 = F_6 ( V_11 ) ;
struct V_22 * V_69 = V_4 -> V_10 ;
struct V_260 * V_261 = V_259 ;
char V_262 [ V_263 ] ;
unsigned char V_264 ;
int V_265 ;
memcpy ( V_262 , V_11 -> V_266 , V_263 ) ;
V_264 = V_11 -> V_267 ;
V_265 = F_89 ( V_11 , V_259 ) ;
if ( V_265 != 0 )
return V_265 ;
V_265 = F_90 ( V_69 , V_261 -> V_268 ) ;
if ( V_265 != 0 ) {
memcpy ( V_11 -> V_266 , V_262 , V_263 ) ;
V_11 -> V_267 = V_264 ;
}
return V_265 ;
}
static void F_91 ( struct V_19 * V_20 )
{
}
static void F_92 ( struct V_1 * V_2 )
{
struct V_3 * V_205 ;
struct V_19 * V_20 ;
struct V_6 * V_19 ;
struct V_8 * V_9 ;
bool V_269 , V_270 = false ;
char * V_271 [] = { L_7 , L_8 , NULL } ;
char * V_272 [] = { L_9 , L_10 , NULL } ;
F_93 () ;
V_205 = F_2 ( V_2 , struct V_3 , V_212 . V_5 ) ;
V_19 = F_3 ( V_205 -> V_10 ) ;
V_9 = V_19 -> V_12 ;
V_20 = V_19 -> V_11 ;
if ( V_9 -> V_25 ) {
F_9 ( V_20 ) ;
V_269 = false ;
} else {
F_13 ( V_20 ) ;
V_269 = true ;
if ( V_9 -> V_209 ) {
V_9 -> V_209 = false ;
V_270 = true ;
}
}
F_94 () ;
if ( V_270 )
F_95 ( V_271 [ 0 ] , V_271 , V_272 , V_273 ) ;
if ( V_269 )
F_96 ( V_20 ) ;
}
static void F_97 ( struct V_19 * V_274 )
{
struct V_3 * V_21 = F_6 ( V_274 ) ;
F_98 ( V_21 -> V_130 ) ;
F_98 ( V_21 -> V_213 ) ;
F_99 ( V_274 ) ;
}
static int F_100 ( struct V_22 * V_229 ,
const struct V_275 * V_276 )
{
struct V_19 * V_20 = NULL ;
struct V_3 * V_21 ;
struct V_235 V_236 ;
struct V_6 * V_7 ;
int V_24 ;
T_1 V_277 ;
V_20 = F_101 ( sizeof( struct V_3 ) ,
F_102 () ) ;
if ( ! V_20 )
return - V_134 ;
V_277 = sizeof( struct V_77 ) +
V_135 ;
F_9 ( V_20 ) ;
V_21 = F_6 ( V_20 ) ;
V_21 -> V_10 = V_229 ;
V_21 -> V_278 = F_103 ( V_279 , V_280 ) ;
if ( F_104 ( V_21 ) )
F_105 ( V_20 , L_11 ,
V_21 -> V_278 ) ;
V_21 -> V_130 = F_106 ( struct V_129 ) ;
if ( ! V_21 -> V_130 ) {
F_99 ( V_20 ) ;
return - V_134 ;
}
V_21 -> V_213 = F_106 ( struct V_129 ) ;
if ( ! V_21 -> V_213 ) {
F_98 ( V_21 -> V_130 ) ;
F_99 ( V_20 ) ;
return - V_134 ;
}
F_80 ( V_229 , V_20 ) ;
F_107 ( & V_21 -> V_212 , F_92 ) ;
F_108 ( & V_21 -> V_5 , F_1 ) ;
V_20 -> V_281 = & V_282 ;
V_20 -> V_283 = V_284 | V_285 | V_286 |
V_287 ;
V_20 -> V_288 = V_289 | V_285 | V_284 |
V_286 | V_287 ;
V_20 -> V_290 = & V_290 ;
F_109 ( V_20 , & V_229 -> V_291 ) ;
V_20 -> V_292 = V_277 ;
V_236 . V_247 = V_247 ;
V_236 . V_248 = V_248 ;
V_24 = F_81 ( V_229 , & V_236 ) ;
if ( V_24 != 0 ) {
F_11 ( V_20 , L_12 , V_24 ) ;
F_97 ( V_20 ) ;
F_80 ( V_229 , NULL ) ;
return V_24 ;
}
memcpy ( V_20 -> V_266 , V_236 . V_293 , V_263 ) ;
V_7 = F_3 ( V_229 ) ;
F_110 ( V_20 , V_7 -> V_233 ) ;
F_111 ( V_20 , V_7 -> V_233 ) ;
V_24 = F_112 ( V_20 ) ;
if ( V_24 != 0 ) {
F_113 ( L_13 ) ;
F_79 ( V_229 ) ;
F_97 ( V_20 ) ;
} else {
F_65 ( & V_21 -> V_212 , 0 ) ;
}
return V_24 ;
}
static int F_114 ( struct V_22 * V_229 )
{
struct V_19 * V_20 ;
struct V_3 * V_205 ;
struct V_6 * V_19 ;
V_19 = F_3 ( V_229 ) ;
V_20 = V_19 -> V_11 ;
if ( V_20 == NULL ) {
F_115 ( & V_229 -> V_291 , L_14 ) ;
return 0 ;
}
V_19 -> V_246 = true ;
V_205 = F_6 ( V_20 ) ;
F_116 ( & V_205 -> V_212 ) ;
F_16 ( & V_205 -> V_5 ) ;
F_15 ( V_20 ) ;
F_117 ( V_20 ) ;
F_79 ( V_229 ) ;
F_97 ( V_20 ) ;
return 0 ;
}
static void T_7 F_118 ( void )
{
F_119 ( & V_294 ) ;
}
static int T_8 F_120 ( void )
{
if ( V_247 < V_295 ) {
V_247 = V_295 ;
F_121 ( L_15 ,
V_247 ) ;
}
return F_122 ( & V_294 ) ;
}
