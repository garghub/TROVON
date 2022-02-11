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
static T_1 F_19 ( T_2 * V_40 , int V_41 , T_2 * V_42 , int V_43 )
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
V_47 = V_42 [ V_48 ] ;
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
struct V_56 * V_56 ;
int V_57 ;
bool V_24 = false ;
if ( F_22 ( V_55 ) -> V_58 != F_23 ( V_59 ) )
return false ;
V_56 = F_24 ( V_55 ) ;
if ( V_56 -> V_60 == 4 ) {
if ( V_56 -> V_61 == V_62 )
V_57 = 12 ;
else
V_57 = 8 ;
* V_53 = F_19 ( V_63 , V_64 ,
( T_2 * ) & V_56 -> V_65 , V_57 ) ;
V_24 = true ;
}
return V_24 ;
}
static T_3 F_25 ( struct V_19 * V_11 , struct V_54 * V_55 ,
void * V_66 , T_4 V_67 )
{
struct V_3 * V_21 = F_6 ( V_11 ) ;
struct V_22 * V_68 = V_21 -> V_10 ;
struct V_6 * V_69 = F_3 ( V_68 ) ;
T_1 V_53 ;
T_3 V_70 = 0 ;
if ( V_69 == NULL || V_11 -> V_71 <= 1 )
return 0 ;
if ( F_21 ( & V_53 , V_55 ) ) {
V_70 = V_69 -> V_72 [ V_53 % V_73 ] %
V_11 -> V_71 ;
F_26 ( V_55 , V_53 , V_74 ) ;
}
return V_70 ;
}
static void F_27 ( void * V_75 )
{
struct V_76 * V_77 = (struct V_76 * ) V_75 ;
struct V_54 * V_55 = (struct V_54 * )
( unsigned long ) V_77 -> V_78 ;
T_1 V_79 = V_77 -> V_80 ;
F_28 ( V_77 ) ;
if ( V_55 && ( V_79 == V_81 ) )
F_29 ( V_55 ) ;
}
static T_1 F_30 ( struct V_82 * V_82 , T_1 V_83 , T_1 V_84 ,
struct V_85 * V_86 )
{
int V_49 = 0 ;
V_82 += ( V_83 >> V_87 ) ;
V_83 &= ~ V_88 ;
while ( V_84 > 0 ) {
unsigned long V_89 ;
V_89 = V_90 - V_83 ;
if ( V_89 > V_84 )
V_89 = V_84 ;
V_86 [ V_49 ] . V_91 = F_31 ( V_82 ) ;
V_86 [ V_49 ] . V_83 = V_83 ;
V_86 [ V_49 ] . V_84 = V_89 ;
V_83 += V_89 ;
V_84 -= V_89 ;
if ( V_83 == V_90 && V_84 ) {
V_82 ++ ;
V_83 = 0 ;
V_49 ++ ;
}
}
return V_49 + 1 ;
}
static T_1 F_32 ( void * V_92 , T_1 V_84 , struct V_54 * V_55 ,
struct V_85 * V_86 )
{
T_1 V_93 = 0 ;
char * V_42 = V_55 -> V_42 ;
int V_94 = F_33 ( V_55 ) -> V_95 ;
int V_48 ;
if ( V_92 != NULL )
V_93 += F_30 ( F_34 ( V_92 ) ,
F_35 ( V_92 ) ,
V_84 , & V_86 [ V_93 ] ) ;
V_93 += F_30 ( F_34 ( V_42 ) ,
F_35 ( V_42 ) ,
F_36 ( V_55 ) , & V_86 [ V_93 ] ) ;
for ( V_48 = 0 ; V_48 < V_94 ; V_48 ++ ) {
T_5 * V_96 = F_33 ( V_55 ) -> V_94 + V_48 ;
V_93 += F_30 ( F_37 ( V_96 ) ,
V_96 -> V_97 ,
F_38 ( V_96 ) , & V_86 [ V_93 ] ) ;
}
return V_93 ;
}
static int F_39 ( struct V_54 * V_55 )
{
int V_48 , V_94 = F_33 ( V_55 ) -> V_95 ;
int V_98 = 0 ;
for ( V_48 = 0 ; V_48 < V_94 ; V_48 ++ ) {
T_5 * V_96 = F_33 ( V_55 ) -> V_94 + V_48 ;
unsigned long V_38 = F_38 ( V_96 ) ;
unsigned long V_83 = V_96 -> V_97 ;
V_83 &= ~ V_88 ;
V_98 += F_40 ( V_83 + V_38 ) ;
}
return V_98 ;
}
static int F_41 ( struct V_54 * V_55 )
{
char * V_42 = V_55 -> V_42 ;
unsigned int V_83 = F_35 ( V_42 ) ;
unsigned int V_84 = F_36 ( V_55 ) ;
int V_99 ;
int V_100 ;
V_99 = F_42 ( V_83 + V_84 , V_90 ) ;
V_100 = F_39 ( V_55 ) ;
return V_99 + V_100 ;
}
static T_1 F_43 ( struct V_54 * V_55 , T_1 * V_101 )
{
T_1 V_102 = V_103 ;
if ( ( F_22 ( V_55 ) -> V_58 != F_23 ( V_59 ) ) &&
( F_22 ( V_55 ) -> V_58 != F_23 ( V_104 ) ) ) {
goto V_105;
}
* V_101 = F_44 ( V_55 ) ;
if ( ( F_22 ( V_55 ) -> V_58 == F_23 ( V_59 ) ) ) {
struct V_56 * V_56 = F_24 ( V_55 ) ;
if ( V_56 -> V_61 == V_62 )
V_102 = V_106 ;
else if ( V_56 -> V_61 == V_107 )
V_102 = V_108 ;
} else {
if ( F_45 ( V_55 ) -> V_109 == V_62 )
V_102 = V_110 ;
else if ( F_45 ( V_55 ) -> V_109 == V_107 )
V_102 = V_111 ;
}
V_105:
return V_102 ;
}
static int F_46 ( struct V_54 * V_55 , struct V_19 * V_20 )
{
struct V_3 * V_21 = F_6 ( V_20 ) ;
struct V_76 * V_77 ;
int V_24 ;
unsigned int V_112 ;
struct V_26 * V_113 ;
struct V_30 * V_31 ;
T_1 V_114 ;
bool V_115 ;
struct V_32 * V_33 ;
struct V_116 * V_117 ;
struct V_118 * V_119 ;
int V_120 ;
T_1 V_121 ;
T_1 V_53 ;
V_112 = F_41 ( V_55 ) + 2 ;
if ( V_112 > V_122 ) {
F_11 ( V_20 , L_3 , V_55 -> V_84 ) ;
F_47 ( V_55 ) ;
V_20 -> V_123 . V_124 ++ ;
return V_125 ;
}
V_77 = F_48 ( sizeof( struct V_76 ) +
( V_112 * sizeof( struct V_85 ) ) +
sizeof( struct V_26 ) +
V_126 + V_127 +
V_128 + V_129 , V_130 ) ;
if ( ! V_77 ) {
F_11 ( V_20 , L_4 ) ;
F_47 ( V_55 ) ;
V_20 -> V_123 . V_124 ++ ;
return V_125 ;
}
V_77 -> V_131 = V_55 -> V_131 ;
V_77 -> V_70 = F_49 ( V_55 ) ;
V_77 -> V_132 = true ;
V_77 -> V_133 = V_55 -> V_84 ;
V_77 -> V_113 = (struct V_26 * ) ( ( unsigned long ) V_77 +
sizeof( struct V_76 ) +
( V_112 * sizeof( struct V_85 ) ) ) ;
V_77 -> V_134 = F_27 ;
V_77 -> V_135 = V_77 ;
V_77 -> V_78 = ( unsigned long ) V_55 ;
V_115 = V_77 -> V_131 & V_136 ;
V_113 = V_77 -> V_113 ;
V_113 -> V_137 = V_138 ;
V_113 -> V_139 = V_77 -> V_133 ;
V_31 = & V_113 -> V_27 . V_34 ;
V_31 -> V_35 = sizeof( struct V_30 ) ;
V_31 -> V_57 = V_77 -> V_133 ;
V_31 -> V_36 = sizeof( struct V_30 ) ;
V_114 = F_50 ( struct V_30 ) ;
V_53 = F_51 ( V_55 ) ;
if ( V_53 != 0 && V_20 -> V_71 > 1 ) {
V_114 += V_129 ;
V_33 = F_18 ( V_113 , V_129 ,
V_140 ) ;
* ( T_1 * ) ( ( void * ) V_33 + V_33 -> V_39 ) = V_53 ;
}
if ( V_115 ) {
struct V_141 * V_142 ;
V_114 += V_126 ;
V_33 = F_18 ( V_113 , V_126 ,
V_143 ) ;
V_142 = (struct V_141 * ) ( ( void * ) V_33 +
V_33 -> V_39 ) ;
V_142 -> V_144 = V_77 -> V_131 & V_145 ;
V_142 -> V_146 = ( V_77 -> V_131 & V_147 ) >>
V_148 ;
}
V_121 = F_43 ( V_55 , & V_120 ) ;
if ( V_121 == V_103 )
goto V_149;
if ( F_52 ( V_55 ) )
goto V_150;
if ( ( V_55 -> V_151 == V_152 ) ||
( V_55 -> V_151 == V_153 ) )
goto V_149;
V_114 += V_127 ;
V_33 = F_18 ( V_113 , V_127 ,
V_154 ) ;
V_117 = (struct V_116 * ) ( ( void * ) V_33 +
V_33 -> V_39 ) ;
if ( V_121 & ( V_155 << 16 ) )
V_117 -> V_156 . V_157 = 1 ;
else
V_117 -> V_156 . V_158 = 1 ;
if ( V_121 & V_159 ) {
V_117 -> V_156 . V_160 = 1 ;
V_117 -> V_156 . V_161 = V_120 ;
} else if ( V_121 & V_162 ) {
struct V_163 * V_164 ;
T_3 V_165 ;
V_24 = F_53 ( V_55 , 0 ) ;
if ( V_24 )
goto V_166;
V_164 = F_54 ( V_55 ) ;
V_165 = F_55 ( V_164 -> V_84 ) ;
V_164 -> V_167 = 0 ;
V_164 -> V_167 = F_56 ( F_24 ( V_55 ) -> V_65 ,
F_24 ( V_55 ) -> V_168 ,
V_165 , V_107 ,
F_57 ( V_164 , V_165 , 0 ) ) ;
if ( V_164 -> V_167 == 0 )
V_164 -> V_167 = V_169 ;
V_117 -> V_156 . V_170 = 0 ;
}
goto V_149;
V_150:
V_114 += V_128 ;
V_33 = F_18 ( V_113 , V_128 ,
V_171 ) ;
V_119 = (struct V_118 * ) ( ( void * ) V_33 +
V_33 -> V_39 ) ;
V_119 -> V_172 . type = V_173 ;
if ( V_121 & ( V_155 << 16 ) ) {
V_119 -> V_172 . V_174 =
V_175 ;
F_24 ( V_55 ) -> V_176 = 0 ;
F_24 ( V_55 ) -> V_167 = 0 ;
F_58 ( V_55 ) -> V_167 =
~ F_56 ( F_24 ( V_55 ) -> V_65 ,
F_24 ( V_55 ) -> V_168 , 0 , V_62 , 0 ) ;
} else {
V_119 -> V_172 . V_174 =
V_177 ;
F_45 ( V_55 ) -> V_178 = 0 ;
F_58 ( V_55 ) -> V_167 =
~ F_59 ( & F_45 ( V_55 ) -> V_65 ,
& F_45 ( V_55 ) -> V_168 , 0 , V_62 , 0 ) ;
}
V_119 -> V_172 . V_161 = V_120 ;
V_119 -> V_172 . V_179 = F_33 ( V_55 ) -> V_180 ;
V_149:
V_113 -> V_139 += V_114 ;
V_77 -> V_181 = F_32 ( V_113 , V_114 ,
V_55 , & V_77 -> V_182 [ 0 ] ) ;
V_24 = F_60 ( V_21 -> V_10 , V_77 ) ;
V_166:
if ( V_24 == 0 ) {
V_20 -> V_123 . V_183 += V_55 -> V_84 ;
V_20 -> V_123 . V_184 ++ ;
} else {
F_28 ( V_77 ) ;
if ( V_24 != - V_185 ) {
F_29 ( V_55 ) ;
V_20 -> V_123 . V_124 ++ ;
}
}
return ( V_24 == - V_185 ) ? V_186 : V_125 ;
}
void F_61 ( struct V_22 * V_23 ,
unsigned int V_187 )
{
struct V_19 * V_20 ;
struct V_3 * V_188 ;
struct V_6 * V_19 ;
struct V_8 * V_9 ;
V_19 = F_3 ( V_23 ) ;
V_9 = V_19 -> V_12 ;
V_9 -> V_25 = V_187 != 1 ;
V_20 = V_19 -> V_11 ;
if ( ! V_20 || V_20 -> V_189 != V_190 )
return;
V_188 = F_6 ( V_20 ) ;
if ( V_187 == 1 ) {
F_62 ( & V_188 -> V_191 , 0 ) ;
F_62 ( & V_188 -> V_191 , F_63 ( 20 ) ) ;
} else {
F_62 ( & V_188 -> V_191 , 0 ) ;
}
}
int F_64 ( struct V_22 * V_23 ,
struct V_76 * V_77 ,
struct V_116 * V_117 )
{
struct V_19 * V_20 ;
struct V_54 * V_55 ;
V_20 = ( (struct V_6 * ) F_3 ( V_23 ) ) -> V_11 ;
if ( ! V_20 || V_20 -> V_189 != V_190 ) {
V_77 -> V_187 = V_192 ;
return 0 ;
}
V_55 = F_65 ( V_20 , V_77 -> V_133 ) ;
if ( F_66 ( ! V_55 ) ) {
++ V_20 -> V_123 . V_193 ;
V_77 -> V_187 = V_192 ;
return 0 ;
}
memcpy ( F_67 ( V_55 , V_77 -> V_133 ) , V_77 -> V_42 ,
V_77 -> V_133 ) ;
V_55 -> V_61 = F_68 ( V_55 , V_20 ) ;
if ( V_117 ) {
if ( V_117 -> V_194 . V_195 )
V_55 -> V_151 = V_153 ;
else
V_55 -> V_151 = V_152 ;
}
if ( V_77 -> V_131 & V_136 )
F_69 ( V_55 , F_23 ( V_196 ) ,
V_77 -> V_131 ) ;
F_70 ( V_55 , V_77 -> V_197 ->
V_198 . V_199 . V_200 ) ;
V_20 -> V_123 . V_201 ++ ;
V_20 -> V_123 . V_202 += V_77 -> V_133 ;
F_71 ( V_55 ) ;
return 0 ;
}
static void F_72 ( struct V_19 * V_20 ,
struct V_203 * V_204 )
{
F_73 ( V_204 -> V_205 , V_206 , sizeof( V_204 -> V_205 ) ) ;
F_73 ( V_204 -> V_207 , L_5 , sizeof( V_204 -> V_207 ) ) ;
}
static int F_74 ( struct V_19 * V_11 , int V_208 )
{
struct V_3 * V_4 = F_6 ( V_11 ) ;
struct V_22 * V_68 = V_4 -> V_10 ;
struct V_6 * V_7 = F_3 ( V_68 ) ;
struct V_209 V_210 ;
int V_211 = V_212 ;
if ( V_7 == NULL || V_7 -> V_213 )
return - V_214 ;
if ( V_7 -> V_215 >= V_216 )
V_211 = V_217 ;
if ( V_208 < 68 || V_208 > V_211 )
return - V_218 ;
V_7 -> V_219 = true ;
F_16 ( & V_4 -> V_5 ) ;
F_15 ( V_11 ) ;
F_75 ( V_68 ) ;
V_11 -> V_208 = V_208 ;
V_4 -> V_10 = V_68 ;
F_76 ( V_68 , V_11 ) ;
V_210 . V_220 = V_220 ;
F_77 ( V_68 , & V_210 ) ;
F_78 ( V_11 ) ;
return 0 ;
}
static int F_79 ( struct V_19 * V_11 , void * V_221 )
{
struct V_3 * V_4 = F_6 ( V_11 ) ;
struct V_22 * V_68 = V_4 -> V_10 ;
struct V_222 * V_223 = V_221 ;
char V_224 [ V_225 ] ;
unsigned char V_226 ;
int V_227 ;
memcpy ( V_224 , V_11 -> V_228 , V_225 ) ;
V_226 = V_11 -> V_229 ;
V_227 = F_80 ( V_11 , V_221 ) ;
if ( V_227 != 0 )
return V_227 ;
V_227 = F_81 ( V_68 , V_223 -> V_230 ) ;
if ( V_227 != 0 ) {
memcpy ( V_11 -> V_228 , V_224 , V_225 ) ;
V_11 -> V_229 = V_226 ;
}
return V_227 ;
}
static void F_82 ( struct V_1 * V_2 )
{
struct V_3 * V_188 ;
struct V_19 * V_20 ;
struct V_6 * V_19 ;
struct V_8 * V_9 ;
bool V_231 ;
F_83 () ;
V_188 = F_2 ( V_2 , struct V_3 , V_191 . V_5 ) ;
V_19 = F_3 ( V_188 -> V_10 ) ;
V_9 = V_19 -> V_12 ;
V_20 = V_19 -> V_11 ;
if ( V_9 -> V_25 ) {
F_9 ( V_20 ) ;
V_231 = false ;
} else {
F_13 ( V_20 ) ;
V_231 = true ;
}
F_84 () ;
if ( V_231 )
F_85 ( V_20 ) ;
}
static int F_86 ( struct V_22 * V_232 ,
const struct V_233 * V_234 )
{
struct V_19 * V_20 = NULL ;
struct V_3 * V_21 ;
struct V_209 V_210 ;
struct V_6 * V_7 ;
int V_24 ;
V_20 = F_87 ( sizeof( struct V_3 ) ,
F_88 () ) ;
if ( ! V_20 )
return - V_235 ;
F_9 ( V_20 ) ;
V_21 = F_6 ( V_20 ) ;
V_21 -> V_10 = V_232 ;
F_76 ( V_232 , V_20 ) ;
F_89 ( & V_21 -> V_191 , F_82 ) ;
F_90 ( & V_21 -> V_5 , F_1 ) ;
V_20 -> V_236 = & V_237 ;
V_20 -> V_238 = V_239 | V_240 | V_241 |
V_242 ;
V_20 -> V_243 = V_244 | V_240 | V_239 |
V_241 | V_242 ;
V_20 -> V_245 = & V_245 ;
F_91 ( V_20 , & V_232 -> V_246 ) ;
V_210 . V_220 = V_220 ;
V_24 = F_77 ( V_232 , & V_210 ) ;
if ( V_24 != 0 ) {
F_11 ( V_20 , L_6 , V_24 ) ;
F_92 ( V_20 ) ;
F_76 ( V_232 , NULL ) ;
return V_24 ;
}
memcpy ( V_20 -> V_228 , V_210 . V_247 , V_225 ) ;
V_7 = F_3 ( V_232 ) ;
F_93 ( V_20 , V_7 -> V_248 ) ;
F_94 ( V_20 , V_7 -> V_248 ) ;
V_24 = F_95 ( V_20 ) ;
if ( V_24 != 0 ) {
F_96 ( L_7 ) ;
F_75 ( V_232 ) ;
F_92 ( V_20 ) ;
} else {
F_62 ( & V_21 -> V_191 , 0 ) ;
}
return V_24 ;
}
static int F_97 ( struct V_22 * V_232 )
{
struct V_19 * V_20 ;
struct V_3 * V_188 ;
struct V_6 * V_19 ;
V_19 = F_3 ( V_232 ) ;
V_20 = V_19 -> V_11 ;
if ( V_20 == NULL ) {
F_98 ( & V_232 -> V_246 , L_8 ) ;
return 0 ;
}
V_19 -> V_219 = true ;
V_188 = F_6 ( V_20 ) ;
F_99 ( & V_188 -> V_191 ) ;
F_16 ( & V_188 -> V_5 ) ;
F_15 ( V_20 ) ;
F_100 ( V_20 ) ;
F_75 ( V_232 ) ;
F_92 ( V_20 ) ;
return 0 ;
}
static void T_6 F_101 ( void )
{
F_102 ( & V_249 ) ;
}
static int T_7 F_103 ( void )
{
if ( V_220 < V_250 ) {
V_220 = V_250 ;
F_104 ( L_9 ,
V_220 ) ;
}
return F_105 ( & V_249 ) ;
}
