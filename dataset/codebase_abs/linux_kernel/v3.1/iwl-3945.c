static inline T_1 F_1 ( T_1 V_1 )
{
T_1 V_2 = V_3 [ V_1 ] . V_4 ;
if ( V_2 == V_5 )
V_2 = V_1 ;
return V_2 ;
}
void F_2 ( struct V_6 * V_7 )
{
int V_8 ;
T_2 V_9 ;
T_2 V_10 ;
T_2 V_11 ;
static const T_2 V_12 [ V_13 ] = {
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
0x00000000 ,
} ;
V_9 = F_3 ( V_7 -> V_14 . V_15 ) ;
if ( ! F_4 ( V_9 ) ) {
F_5 ( V_7 , L_1 , V_9 ) ;
return;
}
V_10 = F_6 ( V_7 , V_9 + ( 4 * sizeof( T_2 ) ) ) ;
V_11 = F_6 ( V_7 , V_9 + ( 5 * sizeof( T_2 ) ) ) ;
if ( V_16 && ( V_11 == V_13 ) ) {
F_7 ( V_7 , L_2 ,
V_10 ) ;
for ( V_8 = 0 ; V_8 < V_13 ; V_8 ++ )
F_8 ( V_7 ,
V_10 + ( V_8 * sizeof( T_2 ) ) ,
V_12 [ V_8 ] ) ;
} else {
F_7 ( V_7 , L_3 ) ;
F_7 ( V_7 , L_4 ) ;
F_7 ( V_7 , L_5 ,
V_10 , V_11 ) ;
}
}
static int F_9 ( T_1 V_17 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ )
if ( V_3 [ V_18 ] . V_17 == V_17 )
return V_18 ;
return - 1 ;
}
static const char * F_10 ( T_2 V_20 )
{
switch ( V_20 & V_21 ) {
case V_22 :
return L_6 ;
F_11 ( V_23 ) ;
F_11 ( V_24 ) ;
F_11 ( V_25 ) ;
F_11 ( V_26 ) ;
F_11 ( V_27 ) ;
F_11 ( V_28 ) ;
F_11 ( V_29 ) ;
F_11 ( V_30 ) ;
F_11 ( V_31 ) ;
F_11 ( V_32 ) ;
F_11 ( V_33 ) ;
F_11 ( V_34 ) ;
F_11 ( V_35 ) ;
F_11 ( V_36 ) ;
F_11 ( V_37 ) ;
F_11 ( V_38 ) ;
}
return L_7 ;
}
static inline const char * F_10 ( T_2 V_20 )
{
return L_8 ;
}
int F_12 ( struct V_6 * V_7 , int V_2 )
{
int V_39 = F_1 ( V_2 ) ;
switch ( V_7 -> V_40 ) {
case V_41 :
if ( V_2 == V_42 )
V_39 = V_43 ;
else if ( V_2 == V_44 )
V_39 = V_44 ;
break;
case V_45 :
if ( ! ( V_7 -> V_46 . V_47 & V_48 ) &&
F_13 ( V_7 , V_49 ) ) {
if ( V_2 == V_50 )
V_39 = V_51 ;
}
break;
default:
break;
}
return V_39 ;
}
static void F_14 ( struct V_6 * V_7 ,
int V_52 , int V_53 )
{
struct V_54 * V_55 = & V_7 -> V_55 [ V_52 ] ;
struct V_56 * V_57 = & V_55 -> V_57 ;
struct V_58 * V_59 ;
F_15 ( V_52 == V_60 ) ;
for ( V_53 = F_16 ( V_53 , V_57 -> V_61 ) ;
V_57 -> V_62 != V_53 ;
V_57 -> V_62 = F_16 ( V_57 -> V_62 , V_57 -> V_61 ) ) {
V_59 = & V_55 -> V_63 [ V_55 -> V_57 . V_62 ] ;
F_17 ( V_7 -> V_64 , V_59 -> V_65 ) ;
V_59 -> V_65 = NULL ;
V_7 -> V_66 -> V_67 -> V_68 -> V_69 ( V_7 , V_55 ) ;
}
if ( F_18 ( V_57 ) > V_57 -> V_70 && ( V_52 >= 0 ) &&
( V_52 != V_60 ) &&
V_7 -> V_71 )
F_19 ( V_7 , V_55 ) ;
}
static void F_20 ( struct V_6 * V_7 ,
struct V_72 * V_73 )
{
struct V_74 * V_75 = F_21 ( V_73 ) ;
T_3 V_76 = F_22 ( V_75 -> V_77 . V_76 ) ;
int V_52 = F_23 ( V_76 ) ;
int V_53 = F_24 ( V_76 ) ;
struct V_54 * V_55 = & V_7 -> V_55 [ V_52 ] ;
struct V_78 * V_79 ;
struct V_80 * V_81 = ( void * ) & V_75 -> V_82 . V_83 [ 0 ] ;
T_2 V_20 = F_3 ( V_81 -> V_20 ) ;
int V_84 ;
int V_85 ;
if ( ( V_53 >= V_55 -> V_57 . V_61 ) || ( F_25 ( & V_55 -> V_57 , V_53 ) == 0 ) ) {
F_5 ( V_7 , L_9
L_10 , V_52 ,
V_53 , V_55 -> V_57 . V_61 , V_55 -> V_57 . V_86 ,
V_55 -> V_57 . V_62 ) ;
return;
}
V_55 -> V_87 = V_88 ;
V_79 = F_26 ( V_55 -> V_63 [ V_55 -> V_57 . V_62 ] . V_65 ) ;
F_27 ( V_79 ) ;
V_84 = F_9 ( V_81 -> V_2 ) ;
if ( V_79 -> V_40 == V_41 )
V_84 -= V_89 ;
V_85 = V_81 -> V_90 ;
V_79 -> V_20 . V_91 [ 0 ] . V_18 = V_84 ;
V_79 -> V_20 . V_91 [ 0 ] . V_92 = V_85 + 1 ;
V_79 -> V_93 |= ( ( V_20 & V_21 ) == V_94 ) ?
V_95 : 0 ;
F_28 ( V_7 , L_11 ,
V_52 , F_10 ( V_20 ) , V_20 ,
V_81 -> V_2 , V_81 -> V_90 ) ;
F_29 ( V_7 , L_12 , V_53 ) ;
F_14 ( V_7 , V_52 , V_53 ) ;
if ( V_20 & V_96 )
F_5 ( V_7 , L_13 ) ;
}
static void F_30 ( struct V_6 * V_7 ,
T_4 * V_97 )
{
int V_8 ;
T_4 * V_98 ;
T_2 * V_99 ;
T_2 * V_100 , * V_101 ;
V_98 = ( T_4 * ) & V_7 -> V_46 . V_102 ;
V_99 = ( T_2 * ) & V_7 -> V_46 . V_103 ;
V_100 = ( T_2 * ) & V_7 -> V_46 . V_104 ;
V_101 = ( T_2 * ) & V_7 -> V_46 . V_101 ;
for ( V_8 = sizeof( T_4 ) ; V_8 < sizeof( struct V_105 ) ;
V_8 += sizeof( T_4 ) , V_97 ++ , V_98 ++ , V_100 ++ ,
V_101 ++ , V_99 ++ ) {
if ( F_3 ( * V_97 ) > F_3 ( * V_98 ) ) {
* V_100 = ( F_3 ( * V_97 ) -
F_3 ( * V_98 ) ) ;
* V_99 += * V_100 ;
if ( * V_100 > * V_101 )
* V_101 = * V_100 ;
}
}
V_7 -> V_46 . V_103 . V_106 . V_107 =
V_7 -> V_46 . V_102 . V_106 . V_107 ;
V_7 -> V_46 . V_103 . V_106 . V_108 =
V_7 -> V_46 . V_102 . V_106 . V_108 ;
}
void F_31 ( struct V_6 * V_7 ,
struct V_72 * V_73 )
{
struct V_74 * V_75 = F_21 ( V_73 ) ;
F_32 ( V_7 , L_14 ,
( int ) sizeof( struct V_105 ) ,
F_3 ( V_75 -> V_109 ) & V_110 ) ;
#ifdef F_33
F_30 ( V_7 , ( T_4 * ) & V_75 -> V_82 . V_83 ) ;
#endif
memcpy ( & V_7 -> V_46 . V_102 , V_75 -> V_82 . V_83 , sizeof( V_7 -> V_46 . V_102 ) ) ;
}
void F_34 ( struct V_6 * V_7 ,
struct V_72 * V_73 )
{
struct V_74 * V_75 = F_21 ( V_73 ) ;
T_4 * V_111 = ( T_4 * ) & V_75 -> V_82 . V_83 ;
if ( F_3 ( * V_111 ) & V_112 ) {
#ifdef F_33
memset ( & V_7 -> V_46 . V_103 , 0 ,
sizeof( struct V_105 ) ) ;
memset ( & V_7 -> V_46 . V_104 , 0 ,
sizeof( struct V_105 ) ) ;
memset ( & V_7 -> V_46 . V_101 , 0 ,
sizeof( struct V_105 ) ) ;
#endif
F_32 ( V_7 , L_15 ) ;
}
F_31 ( V_7 , V_73 ) ;
}
static int F_35 ( struct V_6 * V_7 ,
struct V_113 * V_114 )
{
switch ( V_7 -> V_115 ) {
case V_116 :
return ! F_36 ( V_114 -> V_117 , V_7 -> V_118 ) ;
case V_119 :
return ! F_36 ( V_114 -> V_120 , V_7 -> V_118 ) ;
default:
return 1 ;
}
}
static void F_37 ( struct V_6 * V_7 ,
struct V_72 * V_73 ,
struct V_121 * V_97 )
{
struct V_74 * V_75 = F_21 ( V_73 ) ;
struct V_113 * V_77 = (struct V_113 * ) F_38 ( V_75 ) ;
struct V_122 * V_123 = F_39 ( V_75 ) ;
struct V_124 * V_125 = F_40 ( V_75 ) ;
T_3 V_126 = F_22 ( V_123 -> V_126 ) ;
struct V_127 * V_65 ;
T_5 V_128 = V_77 -> V_129 ;
if ( F_41 ( V_126 + V_130 >
V_131 << V_7 -> V_132 . V_133 ) ) {
F_42 ( V_7 , L_16 ) ;
return;
}
if ( F_41 ( ! V_7 -> V_134 ) ) {
F_43 ( V_7 ,
L_17 ) ;
return;
}
V_65 = F_44 ( 128 ) ;
if ( ! V_65 ) {
F_5 ( V_7 , L_18 ) ;
return;
}
if ( ! V_135 . V_136 )
F_45 ( V_7 ,
(struct V_113 * ) F_21 ( V_73 ) ,
F_3 ( V_125 -> V_20 ) , V_97 ) ;
F_46 ( V_65 , 0 , V_73 -> V_137 ,
( void * ) V_123 -> V_138 - ( void * ) V_75 , V_126 ) ;
F_47 ( V_7 , false , V_128 , V_126 ) ;
memcpy ( F_48 ( V_65 ) , V_97 , sizeof( * V_97 ) ) ;
F_49 ( V_7 -> V_64 , V_65 ) ;
V_7 -> V_139 -- ;
V_73 -> V_137 = NULL ;
}
static void F_50 ( struct V_6 * V_7 ,
struct V_72 * V_73 )
{
struct V_113 * V_114 ;
struct V_121 V_140 ;
struct V_74 * V_75 = F_21 ( V_73 ) ;
struct V_141 * V_142 = F_51 ( V_75 ) ;
struct V_122 * V_123 = F_39 ( V_75 ) ;
struct V_124 * V_125 = F_40 ( V_75 ) ;
T_3 T_6 V_143 = F_22 ( V_142 -> V_144 ) ;
T_3 T_7 V_143 = F_22 ( V_142 -> V_145 ) ;
T_1 V_146 ;
V_140 . V_111 = 0 ;
V_140 . V_147 = F_52 ( V_125 -> V_148 ) ;
V_140 . V_40 = ( V_123 -> V_149 & V_150 ) ?
V_45 : V_41 ;
V_140 . V_151 =
F_53 ( F_22 ( V_123 -> V_152 ) ,
V_140 . V_40 ) ;
V_140 . V_84 = F_9 ( V_123 -> V_2 ) ;
if ( V_140 . V_40 == V_41 )
V_140 . V_84 -= V_89 ;
V_140 . V_153 = ( F_22 ( V_123 -> V_149 ) &
V_154 ) >> 4 ;
if ( V_123 -> V_149 & V_155 )
V_140 . V_111 |= V_156 ;
if ( ( F_41 ( V_142 -> V_157 > 20 ) ) ) {
F_42 ( V_7 , L_19 ,
V_142 -> V_157 ) ;
return;
}
if ( ! ( V_125 -> V_20 & V_158 )
|| ! ( V_125 -> V_20 & V_159 ) ) {
F_32 ( V_7 , L_20 , V_125 -> V_20 ) ;
return;
}
V_140 . signal = V_142 -> V_160 - V_161 ;
F_54 ( V_7 , L_21 ,
V_140 . signal , T_6 ,
T_7 ) ;
V_114 = (struct V_113 * ) F_38 ( V_75 ) ;
V_146 = F_35 ( V_7 , V_114 ) ;
F_55 ( V_7 , L_22 ,
V_146 ? '*' : ' ' ,
F_22 ( V_123 -> V_152 ) ,
V_140 . signal , V_140 . signal ,
V_140 . V_84 ) ;
F_56 ( V_7 , F_22 ( V_123 -> V_126 ) ,
V_114 ) ;
if ( V_146 ) {
V_7 -> V_46 . V_162 =
F_3 ( V_125 -> V_163 ) ;
V_7 -> V_46 . V_164 = F_52 ( V_125 -> V_148 ) ;
V_7 -> V_46 . V_165 = V_140 . signal ;
}
F_37 ( V_7 , V_73 , & V_140 ) ;
}
int F_57 ( struct V_6 * V_7 ,
struct V_54 * V_55 ,
T_8 V_166 , T_3 V_126 , T_1 V_167 , T_1 V_168 )
{
int V_92 ;
struct V_56 * V_57 ;
struct V_169 * V_170 , * V_171 ;
V_57 = & V_55 -> V_57 ;
V_171 = (struct V_169 * ) V_55 -> V_172 ;
V_170 = & V_171 [ V_57 -> V_86 ] ;
if ( V_167 )
memset ( V_170 , 0 , sizeof( * V_170 ) ) ;
V_92 = F_58 ( F_3 ( V_170 -> V_173 ) ) ;
if ( ( V_92 >= V_174 ) || ( V_92 < 0 ) ) {
F_5 ( V_7 , L_23 ,
V_174 ) ;
return - V_175 ;
}
V_170 -> V_176 [ V_92 ] . V_166 = F_59 ( V_166 ) ;
V_170 -> V_176 [ V_92 ] . V_126 = F_59 ( V_126 ) ;
V_92 ++ ;
V_170 -> V_173 = F_59 ( F_60 ( V_92 ) |
F_61 ( V_168 ) ) ;
return 0 ;
}
void F_62 ( struct V_6 * V_7 , struct V_54 * V_55 )
{
struct V_169 * V_171 = (struct V_169 * ) V_55 -> V_172 ;
int V_53 = V_55 -> V_57 . V_62 ;
struct V_169 * V_170 = & V_171 [ V_53 ] ;
struct V_177 * V_178 = V_7 -> V_177 ;
int V_8 ;
int V_179 ;
V_179 = F_58 ( F_3 ( V_170 -> V_173 ) ) ;
if ( V_179 > V_174 ) {
F_5 ( V_7 , L_24 , V_179 ) ;
return;
}
if ( V_179 )
F_63 ( V_178 ,
F_64 ( & V_55 -> V_180 [ V_53 ] , V_181 ) ,
F_65 ( & V_55 -> V_180 [ V_53 ] , V_126 ) ,
V_182 ) ;
for ( V_8 = 1 ; V_8 < V_179 ; V_8 ++ )
F_63 ( V_178 , F_3 ( V_170 -> V_176 [ V_8 ] . V_166 ) ,
F_3 ( V_170 -> V_176 [ V_8 ] . V_126 ) , V_182 ) ;
if ( V_55 -> V_63 ) {
struct V_127 * V_65 ;
V_65 = V_55 -> V_63 [ V_55 -> V_57 . V_62 ] . V_65 ;
if ( V_65 ) {
F_66 ( V_65 ) ;
V_55 -> V_63 [ V_55 -> V_57 . V_62 ] . V_65 = NULL ;
}
}
}
void F_67 ( struct V_6 * V_7 ,
struct V_183 * V_184 ,
struct V_78 * V_79 ,
struct V_113 * V_77 ,
int V_185 , int V_186 )
{
T_3 V_187 = F_68 ( V_7 -> V_64 , V_79 ) -> V_187 ;
T_3 V_1 = F_69 ( V_187 & 0xffff , V_19 ) ;
T_3 V_188 ;
int V_2 ;
T_1 V_189 ;
T_1 V_190 ;
T_4 V_191 ;
T_5 V_128 = V_77 -> V_129 ;
struct V_192 * V_193 = (struct V_192 * ) V_184 -> V_184 . V_138 ;
V_2 = V_3 [ V_1 ] . V_17 ;
V_191 = V_193 -> V_191 ;
V_188 = V_194 ;
if ( F_70 ( V_128 ) )
V_190 = 3 ;
else
V_190 = V_195 ;
V_193 -> V_190 = V_190 ;
if ( V_186 >= V_60 )
V_189 = 3 ;
else
V_189 = 7 ;
if ( V_190 < V_189 )
V_189 = V_190 ;
V_193 -> V_189 = V_189 ;
V_193 -> V_2 = V_2 ;
V_193 -> V_191 = V_191 ;
V_193 -> V_196 [ 0 ] =
( ( V_188 & V_48 ) >> V_89 ) & 0xFF ;
V_193 -> V_196 [ 1 ] = ( V_188 & 0xF ) ;
F_71 ( V_7 , L_25
L_26 , V_185 ,
V_193 -> V_2 , F_3 ( V_193 -> V_191 ) ,
V_193 -> V_196 [ 1 ] , V_193 -> V_196 [ 0 ] ) ;
}
static T_1 F_72 ( struct V_6 * V_7 , int V_185 , T_3 V_197 )
{
unsigned long V_198 ;
struct V_199 * V_200 ;
if ( V_185 == V_201 )
return V_201 ;
F_73 ( & V_7 -> V_202 , V_198 ) ;
V_200 = & V_7 -> V_203 [ V_185 ] ;
V_200 -> V_204 . V_204 . V_205 = V_206 ;
V_200 -> V_204 . V_207 = F_74 ( V_197 ) ;
V_200 -> V_204 . V_208 = V_209 ;
F_75 ( V_7 , & V_200 -> V_204 , V_210 ) ;
F_76 ( & V_7 -> V_202 , V_198 ) ;
F_71 ( V_7 , L_27 ,
V_185 , V_197 ) ;
return V_185 ;
}
static void F_77 ( struct V_6 * V_7 )
{
F_78 ( V_7 , V_211 ,
V_212 ,
~ V_213 ) ;
F_79 ( V_7 , V_214 , V_215 ,
V_216 , 5000 ) ;
}
static int F_80 ( struct V_6 * V_7 , struct V_217 * V_218 )
{
F_81 ( V_7 , F_82 ( 0 ) , V_218 -> V_219 ) ;
F_81 ( V_7 , F_83 ( 0 ) ,
V_218 -> V_220 ) ;
F_81 ( V_7 , F_84 ( 0 ) , 0 ) ;
F_81 ( V_7 , F_85 ( 0 ) ,
V_221 |
V_222 |
V_223 |
V_224 |
( V_225 << V_226 ) |
V_227 |
( 1 << V_228 ) |
V_229 ) ;
F_86 ( V_7 , V_230 ) ;
return 0 ;
}
static int F_87 ( struct V_6 * V_7 )
{
F_88 ( V_7 , V_231 , 0x2 ) ;
F_88 ( V_7 , V_232 , 0x01 ) ;
F_88 ( V_7 , V_233 , 0x3f ) ;
F_88 ( V_7 , V_234 , 0x010000 ) ;
F_88 ( V_7 , V_235 , 0x030002 ) ;
F_88 ( V_7 , V_236 , 0x000004 ) ;
F_88 ( V_7 , V_237 , 0x000005 ) ;
F_81 ( V_7 , V_238 ,
V_7 -> V_46 . V_239 ) ;
F_81 ( V_7 , V_240 ,
V_241 |
V_242 |
V_243 |
V_244 |
V_245 |
V_246 |
V_247 ) ;
return 0 ;
}
static int F_89 ( struct V_6 * V_7 )
{
int V_248 ;
int V_52 , V_249 ;
F_90 ( V_7 ) ;
V_248 = F_91 ( V_7 ) ;
if ( V_248 )
return V_248 ;
V_248 = F_87 ( V_7 ) ;
if ( V_248 )
goto error;
for ( V_52 = 0 ; V_52 < V_7 -> V_132 . V_250 ; V_52 ++ ) {
V_249 = ( V_52 == V_60 ) ?
V_251 : V_252 ;
V_248 = F_92 ( V_7 , & V_7 -> V_55 [ V_52 ] ,
V_249 , V_52 ) ;
if ( V_248 ) {
F_5 ( V_7 , L_28 , V_52 ) ;
goto error;
}
}
return V_248 ;
error:
F_90 ( V_7 ) ;
return V_248 ;
}
static int F_93 ( struct V_6 * V_7 )
{
int V_253 = F_94 ( V_7 ) ;
F_88 ( V_7 , V_254 , 0x0 ) ;
F_88 ( V_7 , V_255 , 0xFFFFFFFF ) ;
F_95 ( V_7 , V_211 ,
V_256 ) ;
F_96 ( 5 ) ;
F_97 ( V_7 , V_211 ,
V_256 ) ;
return V_253 ;
}
static void F_98 ( struct V_6 * V_7 )
{
struct V_257 * V_258 = (struct V_257 * ) V_7 -> V_258 ;
unsigned long V_93 ;
T_1 V_259 = V_7 -> V_177 -> V_260 ;
F_73 ( & V_7 -> V_261 , V_93 ) ;
F_7 ( V_7 , L_29 , V_259 ) ;
if ( V_259 & V_262 )
F_7 ( V_7 , L_30 ) ;
else if ( V_259 & V_263 ) {
F_7 ( V_7 , L_31 ) ;
F_99 ( V_7 , V_264 ,
V_265 ) ;
} else {
F_7 ( V_7 , L_32 ) ;
F_99 ( V_7 , V_264 ,
V_266 ) ;
}
if ( V_267 == V_258 -> V_268 ) {
F_7 ( V_7 , L_33 ) ;
F_99 ( V_7 , V_264 ,
V_269 ) ;
} else
F_7 ( V_7 , L_34 ) ;
if ( ( V_258 -> V_270 & 0xF0 ) == 0xD0 ) {
F_7 ( V_7 , L_35 ,
V_258 -> V_270 ) ;
F_99 ( V_7 , V_264 ,
V_271 ) ;
} else {
F_7 ( V_7 , L_35 ,
V_258 -> V_270 ) ;
F_100 ( V_7 , V_264 ,
V_271 ) ;
}
if ( V_258 -> V_272 <= 1 ) {
F_99 ( V_7 , V_264 ,
V_273 ) ;
F_7 ( V_7 , L_36 ,
V_258 -> V_272 ) ;
} else {
F_7 ( V_7 , L_37 ,
V_258 -> V_272 ) ;
F_99 ( V_7 , V_264 ,
V_274 ) ;
}
F_76 ( & V_7 -> V_261 , V_93 ) ;
if ( V_258 -> V_268 & V_275 )
F_101 ( V_7 , L_38 ) ;
if ( V_258 -> V_268 & V_276 )
F_101 ( V_7 , L_39 ) ;
}
int F_102 ( struct V_6 * V_7 )
{
int V_248 ;
unsigned long V_93 ;
struct V_217 * V_218 = & V_7 -> V_218 ;
F_73 ( & V_7 -> V_261 , V_93 ) ;
V_7 -> V_66 -> V_67 -> V_68 -> V_277 . V_278 ( V_7 ) ;
F_76 ( & V_7 -> V_261 , V_93 ) ;
F_77 ( V_7 ) ;
V_7 -> V_66 -> V_67 -> V_68 -> V_277 . V_279 ( V_7 ) ;
if ( ! V_218 -> V_280 ) {
V_248 = F_103 ( V_7 ) ;
if ( V_248 ) {
F_5 ( V_7 , L_40 ) ;
return - V_281 ;
}
} else
F_104 ( V_7 , V_218 ) ;
F_105 ( V_7 ) ;
F_80 ( V_7 , V_218 ) ;
F_81 ( V_7 , F_84 ( 0 ) , V_218 -> V_282 & ~ 7 ) ;
V_248 = F_89 ( V_7 ) ;
if ( V_248 )
return V_248 ;
F_106 ( V_283 , & V_7 -> V_20 ) ;
return 0 ;
}
void F_90 ( struct V_6 * V_7 )
{
int V_52 ;
if ( V_7 -> V_55 )
for ( V_52 = 0 ; V_52 < V_7 -> V_132 . V_250 ;
V_52 ++ )
if ( V_52 == V_60 )
F_107 ( V_7 ) ;
else
F_108 ( V_7 , V_52 ) ;
F_109 ( V_7 ) ;
}
void F_110 ( struct V_6 * V_7 )
{
int V_52 ;
F_88 ( V_7 , V_231 , 0 ) ;
F_88 ( V_7 , V_233 , 0 ) ;
for ( V_52 = 0 ; V_52 < V_7 -> V_132 . V_250 ; V_52 ++ ) {
F_81 ( V_7 , F_111 ( V_52 ) , 0x0 ) ;
F_112 ( V_7 , V_284 ,
F_113 ( V_52 ) ,
1000 ) ;
}
F_90 ( V_7 ) ;
}
static int F_114 ( int V_285 , int V_286 )
{
return ( V_285 - V_286 ) * ( - 11 ) / 100 ;
}
static inline int F_115 ( int V_107 )
{
return ( ( V_107 < - 260 ) || ( V_107 > 25 ) ) ? 1 : 0 ;
}
int F_116 ( struct V_6 * V_7 )
{
return F_117 ( V_7 , V_287 ) ;
}
static int F_118 ( struct V_6 * V_7 )
{
struct V_257 * V_258 = (struct V_257 * ) V_7 -> V_258 ;
int V_107 ;
V_107 = F_116 ( V_7 ) ;
F_7 ( V_7 , L_41 , V_107 + V_288 ) ;
if ( F_115 ( V_107 ) ) {
F_5 ( V_7 , L_42 , V_107 ) ;
if ( V_7 -> V_289 > 100 )
V_107 = V_258 -> V_290 [ 2 ] . V_107 ;
else
V_107 = V_7 -> V_289 ;
}
return V_107 ;
}
static int F_119 ( struct V_6 * V_7 )
{
int V_291 ;
V_7 -> V_107 = F_118 ( V_7 ) ;
V_291 = V_7 -> V_107 - V_7 -> V_289 ;
if ( V_291 < 0 ) {
F_120 ( V_7 , L_43 , V_291 ) ;
V_291 = - V_291 ;
} else if ( V_291 == 0 )
F_120 ( V_7 , L_44 ) ;
else
F_120 ( V_7 , L_45 , V_291 ) ;
if ( V_291 < V_292 ) {
F_120 ( V_7 , L_46 ) ;
return 0 ;
}
F_120 ( V_7 , L_47 ) ;
V_7 -> V_289 = V_7 -> V_107 ;
return 1 ;
}
static inline T_1 F_121 ( int V_53 )
{
if ( V_53 < 0 )
return 0 ;
if ( V_53 >= V_293 )
return V_293 - 1 ;
return ( T_1 ) V_53 ;
}
static void F_122 ( struct V_6 * V_7 , T_2 V_294 ,
T_9 V_1 , const T_10 * V_295 ,
struct V_296 * V_297 ,
int V_298 )
{
struct V_299 * V_300 ;
T_10 V_301 ;
T_1 V_302 ;
V_300 = & V_297 -> V_303 [ V_294 ] ;
V_301 = F_69 ( V_297 -> V_304 , V_295 [ V_305 ] ) ;
V_301 = F_69 ( V_301 , V_7 -> V_306 ) ;
V_300 -> V_307 = V_301 ;
V_302 = V_297 -> V_308 [ V_1 ] . V_309
- ( V_301 - V_297 -> V_308
[ V_305 ] . V_307 ) * 2 ;
V_302 = F_121 ( V_302 ) ;
V_300 -> V_309 = V_302 ;
V_300 -> V_310 . V_311 =
V_312 [ V_298 ] [ V_302 ] . V_311 ;
V_300 -> V_310 . V_313 =
V_312 [ V_298 ] [ V_302 ] . V_313 ;
}
static int F_123 ( struct V_6 * V_7 )
{
int V_84 , V_8 ;
const struct V_296 * V_297 = NULL ;
struct V_314 V_315 = {
. V_152 = V_7 -> V_316 [ V_49 ] . V_317 . V_152 ,
} ;
T_3 V_318 ;
if ( F_124 ( F_125 ( V_319 , & V_7 -> V_20 ) ,
L_48 ) )
return - V_320 ;
V_318 = F_22 ( V_7 -> V_316 [ V_49 ] . V_317 . V_152 ) ;
V_315 . V_40 = ( V_7 -> V_40 == V_41 ) ? 0 : 1 ;
V_297 = F_126 ( V_7 , V_7 -> V_40 , V_318 ) ;
if ( ! V_297 ) {
F_5 ( V_7 ,
L_49 ,
V_318 , V_7 -> V_40 ) ;
return - V_175 ;
}
if ( ! F_127 ( V_297 ) ) {
F_120 ( V_7 , L_50
L_51 ) ;
return 0 ;
}
for ( V_84 = V_89 , V_8 = 0 ;
V_84 <= V_321 ; V_84 ++ , V_8 ++ ) {
V_315 . V_301 [ V_8 ] . V_310 = V_297 -> V_308 [ V_8 ] . V_310 ;
V_315 . V_301 [ V_8 ] . V_2 = V_3 [ V_84 ] . V_17 ;
F_120 ( V_7 , L_52 ,
F_22 ( V_315 . V_152 ) ,
V_315 . V_40 ,
V_315 . V_301 [ V_8 ] . V_310 . V_311 ,
V_315 . V_301 [ V_8 ] . V_310 . V_313 ,
V_315 . V_301 [ V_8 ] . V_2 ) ;
}
for ( V_84 = V_322 ;
V_84 <= V_323 ; V_84 ++ , V_8 ++ ) {
V_315 . V_301 [ V_8 ] . V_310 = V_297 -> V_308 [ V_8 ] . V_310 ;
V_315 . V_301 [ V_8 ] . V_2 = V_3 [ V_84 ] . V_17 ;
F_120 ( V_7 , L_52 ,
F_22 ( V_315 . V_152 ) ,
V_315 . V_40 ,
V_315 . V_301 [ V_8 ] . V_310 . V_311 ,
V_315 . V_301 [ V_8 ] . V_310 . V_313 ,
V_315 . V_301 [ V_8 ] . V_2 ) ;
}
return F_128 ( V_7 , V_324 ,
sizeof( struct V_314 ) ,
& V_315 ) ;
}
static int F_129 ( struct V_6 * V_7 ,
struct V_296 * V_297 )
{
struct V_325 * V_308 ;
int V_326 = 0 ;
int V_8 ;
const T_10 * V_295 ;
int V_301 ;
V_295 = V_7 -> V_46 . V_327 [ V_297 -> V_328 ] . V_329 ;
V_308 = V_297 -> V_308 ;
for ( V_8 = V_305 ; V_8 <= V_330 ;
V_8 ++ , ++ V_308 ) {
int V_331 ;
V_301 = F_69 ( V_297 -> V_332 , V_295 [ V_8 ] ) ;
if ( V_301 == V_308 -> V_307 )
continue;
V_331 = ( V_301 - V_308 -> V_307 ) * 2 ;
V_308 -> V_333 -= V_331 ;
V_308 -> V_307 = V_301 ;
V_326 = 1 ;
}
if ( V_326 ) {
V_301 =
V_297 -> V_308 [ V_334 ] .
V_307 + V_335 ;
for ( V_8 = V_336 ; V_8 <= V_337 ; V_8 ++ ) {
V_308 -> V_307 = V_301 ;
V_308 -> V_333 =
V_297 -> V_308 [ V_334 ] .
V_333 + V_338 ;
++ V_308 ;
}
}
return 0 ;
}
static int F_130 ( struct V_296 * V_297 )
{
T_10 V_339 ;
#if 0
if (ch_info->tgd_data.max_power != 0)
max_power = min(ch_info->tgd_data.max_power,
ch_info->eeprom.max_power_avg);
else
#endif
V_339 = V_297 -> V_258 . V_340 ;
return F_69 ( V_339 , V_297 -> V_340 ) ;
}
static int F_131 ( struct V_6 * V_7 )
{
struct V_296 * V_297 = NULL ;
struct V_257 * V_258 = (struct V_257 * ) V_7 -> V_258 ;
int V_341 ;
const T_10 * V_295 ;
T_1 V_342 ;
T_1 V_1 ;
T_1 V_294 ;
T_1 V_8 ;
int V_343 ;
int V_107 = V_7 -> V_107 ;
if ( V_7 -> V_344 ||
F_125 ( V_345 , & V_7 -> V_20 ) ) {
return 0 ;
}
for ( V_8 = 0 ; V_8 < V_7 -> V_346 ; V_8 ++ ) {
V_297 = & V_7 -> V_347 [ V_8 ] ;
V_342 = F_132 ( V_297 ) ;
V_343 = ( V_348 ) V_258 -> V_290 [ V_297 -> V_328 ] .
V_107 ;
V_341 = F_114 ( V_107 ,
V_343 ) ;
for ( V_1 = 0 ; V_1 < V_19 ;
V_1 ++ ) {
int V_349 =
V_297 -> V_308 [ V_1 ] . V_333 ;
V_349 += V_341 ;
V_349 = F_121 ( V_349 ) ;
V_297 -> V_308 [ V_1 ] .
V_309 = ( T_1 ) V_349 ;
V_297 -> V_308 [ V_1 ] . V_310 =
V_312 [ V_342 ] [ V_349 ] ;
}
V_295 = V_7 -> V_46 . V_327 [ V_297 -> V_328 ] . V_329 ;
for ( V_294 = 0 ;
V_294 < V_350 ; V_294 ++ ) {
T_9 V_351 = ( V_294 == 0 ) ?
V_336 : V_305 ;
F_122 ( V_7 , V_294 ,
V_351 , V_295 ,
V_297 , V_342 ) ;
}
}
return V_7 -> V_66 -> V_67 -> V_68 -> V_352 ( V_7 ) ;
}
int F_133 ( struct V_6 * V_7 , T_10 V_301 )
{
struct V_296 * V_297 ;
T_10 V_339 ;
T_1 V_342 ;
T_1 V_8 ;
if ( V_7 -> V_306 == V_301 ) {
F_120 ( V_7 , L_53
L_54 , V_301 ) ;
return 0 ;
}
F_120 ( V_7 , L_55 , V_301 ) ;
V_7 -> V_306 = V_301 ;
for ( V_8 = 0 ; V_8 < V_7 -> V_346 ; V_8 ++ ) {
V_297 = & V_7 -> V_347 [ V_8 ] ;
V_342 = F_132 ( V_297 ) ;
V_339 = F_130 ( V_297 ) ;
V_339 = F_69 ( V_301 , V_339 ) ;
if ( V_339 != V_297 -> V_332 ) {
V_297 -> V_332 = V_339 ;
F_129 ( V_7 , V_297 ) ;
}
}
F_119 ( V_7 ) ;
F_131 ( V_7 ) ;
return 0 ;
}
static int F_134 ( struct V_6 * V_7 ,
struct V_353 * V_354 )
{
int V_248 = 0 ;
struct V_74 * V_75 ;
struct V_355 V_356 ;
struct V_357 V_184 = {
. V_358 = V_359 ,
. V_126 = sizeof( V_356 ) ,
. V_93 = V_360 ,
. V_361 = & V_356 ,
} ;
const struct V_362 * V_363 = & V_354 -> V_364 ;
const struct V_362 * V_365 = & V_354 -> V_317 ;
if ( ( V_363 -> V_93 == V_365 -> V_93 ) &&
( V_363 -> V_366 == V_365 -> V_366 ) &&
( V_363 -> V_367 == V_365 -> V_367 ) &&
( V_363 -> V_368 == V_365 -> V_368 ) ) {
F_7 ( V_7 , L_56 ) ;
return 0 ;
}
V_356 . V_93 = V_354 -> V_364 . V_93 ;
V_356 . V_366 = V_354 -> V_364 . V_366 ;
V_356 . V_368 = V_354 -> V_364 . V_368 ;
V_356 . V_367 = V_354 -> V_364 . V_367 ;
V_356 . V_369 = 0 ;
V_248 = F_135 ( V_7 , & V_184 ) ;
if ( V_248 )
return V_248 ;
V_75 = (struct V_74 * ) V_184 . V_370 ;
if ( V_75 -> V_77 . V_93 & V_371 ) {
F_5 ( V_7 , L_57 ) ;
V_248 = - V_372 ;
}
F_136 ( V_7 , V_184 . V_370 ) ;
return V_248 ;
}
int F_137 ( struct V_6 * V_7 , struct V_353 * V_354 )
{
struct V_373 * V_374 = ( void * ) & V_354 -> V_317 ;
struct V_373 * V_375 = ( void * ) & V_354 -> V_364 ;
int V_248 = 0 ;
bool V_376 = ! ! ( V_375 -> V_366 & V_377 ) ;
if ( F_125 ( V_378 , & V_7 -> V_20 ) )
return - V_175 ;
if ( ! F_138 ( V_7 ) )
return - 1 ;
V_375 -> V_93 |= V_379 ;
V_375 -> V_93 &=
~ ( V_380 | V_381 ) ;
V_375 -> V_93 |= F_139 ( V_7 ) ;
V_248 = F_140 ( V_7 , V_354 ) ;
if ( V_248 ) {
F_5 ( V_7 , L_58 ) ;
return - V_175 ;
}
if ( ! F_141 ( V_7 ,
& V_7 -> V_316 [ V_49 ] ) ) {
V_248 = F_142 ( V_7 ,
& V_7 -> V_316 [ V_49 ] ) ;
if ( V_248 ) {
F_5 ( V_7 , L_59
L_60 , V_248 ) ;
return V_248 ;
}
memcpy ( V_374 , V_375 , sizeof( * V_374 ) ) ;
F_143 ( V_7 , V_7 -> V_382 , false ) ;
return 0 ;
}
if ( F_13 ( V_7 , V_49 ) && V_376 ) {
F_7 ( V_7 , L_61 ) ;
V_374 -> V_366 &= ~ V_377 ;
V_374 -> V_383 = 0 ;
V_374 -> V_384 = 0 ;
V_248 = F_128 ( V_7 , V_385 ,
sizeof( struct V_373 ) ,
& V_7 -> V_316 [ V_49 ] . V_317 ) ;
if ( V_248 ) {
V_374 -> V_366 |= V_377 ;
F_5 ( V_7 , L_62
L_60 , V_248 ) ;
return V_248 ;
}
F_144 ( V_7 ,
& V_7 -> V_316 [ V_49 ] ) ;
F_145 ( V_7 ,
& V_7 -> V_316 [ V_49 ] ) ;
}
F_7 ( V_7 , L_63
L_64
L_65
L_66 ,
( V_376 ? L_8 : L_67 ) ,
F_22 ( V_375 -> V_152 ) ,
V_375 -> V_386 ) ;
V_375 -> V_383 = 0 ;
V_375 -> V_384 = 0 ;
F_146 ( V_7 , V_354 , ! V_135 . V_136 ) ;
V_248 = F_128 ( V_7 , V_385 ,
sizeof( struct V_373 ) ,
V_375 ) ;
if ( V_248 ) {
F_5 ( V_7 , L_68 , V_248 ) ;
return V_248 ;
}
memcpy ( V_374 , V_375 , sizeof( * V_374 ) ) ;
if ( ! V_376 ) {
F_144 ( V_7 ,
& V_7 -> V_316 [ V_49 ] ) ;
F_145 ( V_7 ,
& V_7 -> V_316 [ V_49 ] ) ;
}
V_248 = F_143 ( V_7 , V_7 -> V_382 , true ) ;
if ( V_248 ) {
F_5 ( V_7 , L_69 , V_248 ) ;
return V_248 ;
}
V_248 = F_147 ( V_7 ) ;
if ( V_248 ) {
F_5 ( V_7 , L_70 , V_248 ) ;
return - V_372 ;
}
return 0 ;
}
void F_148 ( struct V_6 * V_7 )
{
if ( ! F_119 ( V_7 ) )
goto V_387;
F_131 ( V_7 ) ;
V_387:
F_149 ( V_7 -> V_388 ,
& V_7 -> V_46 . V_389 , V_390 * V_391 ) ;
}
static void F_150 ( struct V_392 * V_393 )
{
struct V_6 * V_7 = F_151 ( V_393 , struct V_6 ,
V_46 . V_389 . V_393 ) ;
if ( F_125 ( V_378 , & V_7 -> V_20 ) )
return;
F_152 ( & V_7 -> V_394 ) ;
F_148 ( V_7 ) ;
F_153 ( & V_7 -> V_394 ) ;
}
static T_3 F_154 ( struct V_6 * V_7 ,
const struct V_296 * V_297 )
{
struct V_257 * V_258 = (struct V_257 * ) V_7 -> V_258 ;
struct V_395 * V_396 = & V_258 -> V_290 [ 0 ] ;
T_1 V_397 ;
T_3 V_328 = 0 ;
T_1 V_398 ;
if ( F_132 ( V_297 ) ) {
for ( V_397 = 1 ; V_397 < 5 ; V_397 ++ ) {
V_398 = V_396 [ V_397 ] . V_399 ;
if ( V_297 -> V_152 <= V_398 ) {
V_328 = V_397 ;
break;
}
}
if ( V_397 == 5 )
V_328 = 4 ;
} else
V_328 = 0 ;
F_120 ( V_7 , L_71 , V_297 -> V_152 ,
V_328 ) ;
return V_328 ;
}
static int F_155 ( struct V_6 * V_7 ,
T_10 V_307 ,
T_9 V_400 , T_9 * V_401 )
{
const struct V_395 * V_402 = NULL ;
struct V_257 * V_258 = (struct V_257 * ) V_7 -> V_258 ;
T_9 V_403 , V_404 ;
T_9 V_301 = 2 * V_307 ;
T_9 V_8 ;
const struct V_405 * V_406 ;
T_9 V_407 , V_408 ;
T_9 V_409 ;
T_9 V_410 ;
V_402 = & V_258 -> V_290 [ V_400 ] ;
V_406 = V_402 -> V_406 ;
for ( V_8 = 0 ; V_8 < 5 ; V_8 ++ ) {
if ( V_301 == V_406 [ V_8 ] . V_301 ) {
* V_401 = V_406 [ V_8 ] . V_411 ;
return 0 ;
}
}
if ( V_301 > V_406 [ 1 ] . V_301 ) {
V_403 = 0 ;
V_404 = 1 ;
} else if ( V_301 > V_406 [ 2 ] . V_301 ) {
V_403 = 1 ;
V_404 = 2 ;
} else if ( V_301 > V_406 [ 3 ] . V_301 ) {
V_403 = 2 ;
V_404 = 3 ;
} else {
V_403 = 3 ;
V_404 = 4 ;
}
V_410 = ( T_9 ) V_406 [ V_404 ] . V_301 - ( T_9 ) V_406 [ V_403 ] . V_301 ;
if ( V_410 == 0 )
return - V_175 ;
V_407 = ( T_9 ) V_406 [ V_403 ] . V_411 * ( 1 << 19 ) ;
V_408 = ( T_9 ) V_406 [ V_404 ] . V_411 * ( 1 << 19 ) ;
V_409 = V_407 + ( V_408 - V_407 ) *
( ( T_9 ) V_301 - ( T_9 ) V_406 [ V_403 ] . V_301 ) / V_410 +
( 1 << 18 ) ;
* V_401 = V_409 >> 19 ;
return 0 ;
}
static void F_156 ( struct V_6 * V_7 )
{
T_2 V_8 ;
T_9 V_1 ;
struct V_257 * V_258 = (struct V_257 * ) V_7 -> V_258 ;
const struct V_395 * V_397 ;
F_120 ( V_7 , L_72 ) ;
for ( V_8 = 0 ; V_8 < V_412 ; V_8 ++ ) {
T_10 * V_295 ;
T_10 V_413 ;
V_397 = & V_258 -> V_290 [ V_8 ] ;
if ( V_397 -> V_414 < 40 ) {
F_157 ( V_7 , L_73
L_74 ,
V_397 -> V_414 ) ;
return;
}
V_295 = ( T_10 * ) V_7 -> V_46 . V_327 [ V_8 ] . V_329 ;
V_413 = ( T_10 ) ( V_397 -> V_414 >> 1 ) ;
for ( V_1 = 0 ;
V_1 < V_19 ; V_1 ++ , V_295 ++ ) {
switch ( V_1 ) {
case V_415 :
if ( V_8 == 0 )
* V_295 = V_413 ;
else
* V_295 = V_413 - 5 ;
break;
case V_416 :
if ( V_8 == 0 )
* V_295 = V_413 - 7 ;
else
* V_295 = V_413 - 10 ;
break;
case V_330 :
if ( V_8 == 0 )
* V_295 = V_413 - 9 ;
else
* V_295 = V_413 - 12 ;
break;
default:
* V_295 = V_413 ;
break;
}
}
}
}
int F_158 ( struct V_6 * V_7 )
{
struct V_296 * V_297 = NULL ;
struct V_325 * V_417 ;
struct V_257 * V_258 = (struct V_257 * ) V_7 -> V_258 ;
int V_341 ;
T_1 V_1 ;
T_1 V_294 ;
const T_10 * V_295 ;
T_1 V_418 , V_313 ;
T_10 V_301 ;
T_1 V_419 , V_420 , V_342 ;
T_1 V_8 ;
int V_107 ;
V_107 = F_118 ( V_7 ) ;
V_7 -> V_289 = V_107 ;
F_156 ( V_7 ) ;
for ( V_8 = 0 , V_297 = V_7 -> V_347 ; V_8 < V_7 -> V_346 ;
V_8 ++ , V_297 ++ ) {
V_342 = F_132 ( V_297 ) ;
if ( ! F_127 ( V_297 ) )
continue;
V_297 -> V_328 =
F_154 ( V_7 , V_297 ) ;
V_295 = V_7 -> V_46 . V_327 [ V_297 -> V_328 ] . V_329 ;
V_341 = F_114 ( V_107 ,
V_258 -> V_290 [ V_297 -> V_328 ] .
V_107 ) ;
F_120 ( V_7 , L_75 ,
V_297 -> V_152 , V_341 , V_107 +
V_288 ) ;
for ( V_1 = 0 ; V_1 < V_421 ;
V_1 ++ ) {
T_9 V_422 ( V_349 ) ;
int V_248 ;
T_10 V_423 = F_69 ( V_297 -> V_340 ,
V_295 [ V_1 ] ) ;
V_417 = & V_297 -> V_308 [ V_1 ] ;
V_248 = F_155 ( V_7 , V_423 ,
V_297 -> V_328 ,
& V_349 ) ;
if ( V_248 ) {
F_5 ( V_7 , L_76 ) ;
return V_248 ;
}
V_417 -> V_333 = ( T_1 ) V_349 ;
V_349 += V_341 ;
V_349 = F_121 ( V_349 ) ;
V_417 -> V_307 = V_423 ;
V_417 -> V_309 = ( T_1 ) V_349 ;
V_417 -> V_310 . V_311 =
V_312 [ V_342 ] [ V_349 ] . V_311 ;
V_417 -> V_310 . V_313 =
V_312 [ V_342 ] [ V_349 ] . V_313 ;
}
V_417 = & V_297 -> V_308 [ V_334 ] ;
V_301 = V_417 -> V_307 +
V_335 ;
V_419 = V_417 -> V_309 +
V_338 ;
V_420 = V_417 -> V_333 +
V_338 ;
V_419 = F_121 ( V_419 ) ;
V_418 = V_312 [ V_342 ] [ V_419 ] . V_311 ;
V_313 = V_312 [ V_342 ] [ V_419 ] . V_313 ;
for ( V_1 = 0 ;
V_1 < V_424 ; V_1 ++ ) {
V_417 = & V_297 -> V_308 [ V_1 + V_421 ] ;
V_417 -> V_307 = V_301 ;
V_417 -> V_309 = V_419 ;
V_417 -> V_333 = V_420 ;
V_417 -> V_310 . V_311 = V_418 ;
V_417 -> V_310 . V_313 = V_313 ;
}
for ( V_294 = 0 ;
V_294 < V_350 ; V_294 ++ ) {
T_9 V_351 = ( V_294 == 0 ) ?
V_336 : V_305 ;
F_122 ( V_7 , V_294 ,
V_351 , V_295 , V_297 , V_342 ) ;
}
}
return 0 ;
}
int F_159 ( struct V_6 * V_7 )
{
int V_248 ;
F_81 ( V_7 , F_85 ( 0 ) , 0 ) ;
V_248 = F_112 ( V_7 , V_425 ,
V_426 , 1000 ) ;
if ( V_248 < 0 )
F_5 ( V_7 , L_77 ) ;
return 0 ;
}
int F_160 ( struct V_6 * V_7 , struct V_54 * V_55 )
{
int V_52 = V_55 -> V_57 . V_358 ;
struct V_427 * V_428 = V_7 -> V_46 . V_429 ;
V_428 -> V_430 [ V_52 ] = F_59 ( ( T_2 ) V_55 -> V_57 . V_431 ) ;
F_81 ( V_7 , F_161 ( V_52 ) , 0 ) ;
F_81 ( V_7 , F_162 ( V_52 ) , 0 ) ;
F_81 ( V_7 , F_111 ( V_52 ) ,
V_432 |
V_433 |
V_434 |
V_435 |
V_436 ) ;
F_117 ( V_7 , V_238 ) ;
return 0 ;
}
static T_3 F_163 ( T_1 V_437 , T_3 V_126 )
{
switch ( V_437 ) {
case V_385 :
return sizeof( struct V_373 ) ;
case V_438 :
return sizeof( struct V_439 ) ;
default:
return V_126 ;
}
}
static T_3 F_164 ( const struct V_440 * V_184 ,
T_1 * V_361 )
{
struct V_441 * V_442 = (struct V_441 * ) V_361 ;
V_442 -> V_208 = V_184 -> V_208 ;
memcpy ( & V_442 -> V_204 , & V_184 -> V_204 , sizeof( struct V_443 ) ) ;
memcpy ( & V_442 -> V_444 , & V_184 -> V_444 , sizeof( struct V_445 ) ) ;
V_442 -> V_446 = V_184 -> V_446 ;
V_442 -> V_447 = V_184 -> V_447 ;
V_442 -> V_448 = F_74 ( 0 ) ;
V_442 -> V_207 = V_184 -> V_207 ;
V_442 -> V_449 = V_184 -> V_449 ;
V_442 -> V_450 = V_184 -> V_450 ;
V_442 -> V_451 = V_184 -> V_451 ;
return ( T_3 ) sizeof( struct V_441 ) ;
}
static int F_165 ( struct V_6 * V_7 ,
const T_1 * V_166 , T_1 * V_452 )
{
struct V_353 * V_354 = & V_7 -> V_316 [ V_49 ] ;
int V_253 ;
T_1 V_185 ;
unsigned long V_93 ;
if ( V_452 )
* V_452 = V_201 ;
V_253 = F_166 ( V_7 , V_354 , V_166 , 0 , NULL , & V_185 ) ;
if ( V_253 ) {
F_5 ( V_7 , L_78 , V_166 ) ;
return V_253 ;
}
if ( V_452 )
* V_452 = V_185 ;
F_73 ( & V_7 -> V_202 , V_93 ) ;
V_7 -> V_203 [ V_185 ] . V_453 |= V_454 ;
F_76 ( & V_7 -> V_202 , V_93 ) ;
return 0 ;
}
static int F_167 ( struct V_6 * V_7 ,
struct V_455 * V_456 , bool V_457 )
{
struct V_458 * V_459 = ( void * ) V_456 -> V_460 ;
int V_253 ;
if ( V_457 ) {
V_253 = F_165 ( V_7 , V_456 -> V_461 . V_118 ,
& V_459 -> V_462 ) ;
if ( V_253 )
return V_253 ;
F_72 ( V_7 , V_459 -> V_462 ,
( V_7 -> V_40 == V_41 ) ?
V_463 : V_464 ) ;
F_168 ( V_7 -> V_64 , V_459 -> V_462 ) ;
return 0 ;
}
return F_169 ( V_7 , V_459 -> V_462 ,
V_456 -> V_461 . V_118 ) ;
}
int F_147 ( struct V_6 * V_7 )
{
int V_248 , V_8 , V_53 , V_465 ;
struct V_466 V_467 = {
. V_369 = { 0 , 0 , 0 } ,
} ;
struct V_468 * V_469 = V_467 . V_469 ;
for ( V_8 = 0 ; V_8 < F_170 ( V_3 ) ; V_8 ++ ) {
V_53 = V_3 [ V_8 ] . V_470 ;
V_469 [ V_53 ] . V_207 =
F_171 ( V_3 [ V_8 ] . V_17 , 0 ) ;
V_469 [ V_53 ] . V_471 = V_7 -> V_472 ;
V_465 = F_1 ( V_8 ) ;
V_469 [ V_53 ] . V_473 =
V_3 [ V_465 ] . V_470 ;
}
switch ( V_7 -> V_40 ) {
case V_41 :
F_71 ( V_7 , L_79 ) ;
for ( V_8 = V_336 ;
V_8 <= V_337 ; V_8 ++ )
V_469 [ V_8 ] . V_473 =
V_3 [ V_89 ] . V_470 ;
V_469 [ V_334 ] . V_473 =
V_474 ;
V_469 [ V_305 ] . V_473 =
V_3 [ V_89 ] . V_470 ;
break;
case V_45 :
F_71 ( V_7 , L_80 ) ;
if ( ! ( V_7 -> V_46 . V_47 & V_48 ) &&
F_13 ( V_7 , V_49 ) ) {
V_53 = V_322 ;
for ( V_8 = V_305 ;
V_8 <= V_330 ; V_8 ++ )
V_469 [ V_8 ] . V_473 =
V_3 [ V_53 ] . V_470 ;
V_53 = V_337 ;
V_469 [ V_53 ] . V_473 = V_475 ;
}
break;
default:
F_172 ( 1 ) ;
break;
}
V_467 . V_476 = 0 ;
V_248 = F_128 ( V_7 , V_477 , sizeof( V_467 ) ,
& V_467 ) ;
if ( V_248 )
return V_248 ;
V_467 . V_476 = 1 ;
return F_128 ( V_7 , V_477 , sizeof( V_467 ) ,
& V_467 ) ;
}
int F_173 ( struct V_6 * V_7 )
{
memset ( ( void * ) & V_7 -> V_132 , 0 ,
sizeof( struct V_478 ) ) ;
V_7 -> V_46 . V_429 =
F_174 ( & V_7 -> V_177 -> V_178 ,
sizeof( struct V_427 ) ,
& V_7 -> V_46 . V_239 , V_479 ) ;
if ( ! V_7 -> V_46 . V_429 ) {
F_5 ( V_7 , L_81 ) ;
return - V_281 ;
}
V_7 -> V_132 . V_250 = V_7 -> V_66 -> V_480 -> V_481 ;
V_7 -> V_132 . V_482 = sizeof( struct V_169 ) ;
V_7 -> V_132 . V_133 = F_175 ( V_483 ) ;
V_7 -> V_132 . V_484 = V_485 ;
V_7 -> V_132 . V_486 = V_225 ;
V_7 -> V_132 . V_487 = V_488 ;
V_7 -> V_316 [ V_49 ] . V_489 = V_490 ;
V_7 -> V_491 = V_492 ;
V_7 -> V_132 . V_493 = V_494 ;
V_7 -> V_132 . V_495 = V_496 ;
V_7 -> V_132 . V_497 = V_498 ;
return 0 ;
}
unsigned int F_176 ( struct V_6 * V_7 ,
struct V_499 * V_500 , T_1 V_2 )
{
struct V_501 * V_502 ;
unsigned int V_503 ;
V_502 = (struct V_501 * ) & V_500 -> V_82 ;
memset ( V_502 , 0 , sizeof( * V_502 ) ) ;
V_502 -> V_504 . V_185 =
V_7 -> V_316 [ V_49 ] . V_489 ;
V_502 -> V_504 . V_505 . V_506 = V_507 ;
V_503 = F_177 ( V_7 ,
V_502 -> V_500 ,
sizeof( V_500 -> V_82 ) - sizeof( * V_502 ) ) ;
F_15 ( V_503 > V_508 ) ;
V_502 -> V_504 . V_126 = F_74 ( ( T_3 ) V_503 ) ;
V_502 -> V_504 . V_2 = V_2 ;
V_502 -> V_504 . V_191 = ( V_509 |
V_510 ) ;
V_502 -> V_504 . V_196 [ 0 ] =
( V_511 >> V_89 ) & 0xFF ;
V_502 -> V_504 . V_196 [ 1 ] =
( V_512 & 0xF ) ;
return sizeof( struct V_501 ) + V_503 ;
}
void F_178 ( struct V_6 * V_7 )
{
V_7 -> V_513 [ V_514 ] = F_20 ;
V_7 -> V_513 [ V_515 ] = F_50 ;
}
void F_179 ( struct V_6 * V_7 )
{
F_180 ( & V_7 -> V_46 . V_389 ,
F_150 ) ;
}
void F_181 ( struct V_6 * V_7 )
{
F_182 ( & V_7 -> V_46 . V_389 ) ;
}
static int F_183 ( struct V_6 * V_7 )
{
T_4 * V_516 = V_7 -> V_517 . V_518 ;
T_2 V_126 = V_7 -> V_517 . V_126 ;
T_2 V_519 ;
T_2 V_520 ;
F_7 ( V_7 , L_82 ) ;
V_520 = F_184 ( V_7 , V_521 ) ;
for ( V_519 = V_522 ;
V_519 < V_522 + V_126 ;
V_519 += sizeof( T_2 ) , V_516 ++ ) {
V_520 = F_184 ( V_7 , V_519 ) ;
if ( V_520 != F_3 ( * V_516 ) ) {
F_5 ( V_7 , L_83
L_84 ,
V_522 ,
V_519 - V_522 , V_126 ,
V_520 , F_3 ( * V_516 ) ) ;
return - V_372 ;
}
}
F_7 ( V_7 , L_85 ) ;
return 0 ;
}
static int F_185 ( struct V_6 * V_7 )
{
F_186 ( V_7 , V_523 , V_524 ) ;
return 0 ;
}
static void F_187 ( struct V_6 * V_7 )
{
return;
}
static int F_188 ( struct V_6 * V_7 )
{
T_4 * V_516 = V_7 -> V_517 . V_518 ;
T_2 V_126 = V_7 -> V_517 . V_126 ;
T_8 V_525 ;
T_8 V_526 ;
T_2 V_527 ;
T_2 V_528 ;
int V_248 ;
int V_8 ;
T_2 V_529 ;
T_2 V_530 ;
F_7 ( V_7 , L_86 ) ;
if ( V_126 > V_531 )
return - V_175 ;
V_525 = V_7 -> V_532 . V_533 ;
V_526 = V_7 -> V_534 . V_533 ;
V_527 = V_7 -> V_532 . V_126 ;
V_528 = V_7 -> V_534 . V_126 ;
F_88 ( V_7 , V_535 , V_525 ) ;
F_88 ( V_7 , V_536 , V_526 ) ;
F_88 ( V_7 , V_537 , V_527 ) ;
F_88 ( V_7 , V_538 , V_528 ) ;
for ( V_530 = V_522 ;
V_530 < V_522 + V_126 ;
V_530 += sizeof( T_2 ) , V_516 ++ )
F_189 ( V_7 , V_530 ,
F_3 ( * V_516 ) ) ;
V_248 = F_183 ( V_7 ) ;
if ( V_248 )
return V_248 ;
F_88 ( V_7 , V_539 , 0x0 ) ;
F_88 ( V_7 , V_540 ,
V_541 ) ;
F_88 ( V_7 , V_521 , V_126 / sizeof( T_2 ) ) ;
F_88 ( V_7 , V_542 ,
V_543 ) ;
for ( V_8 = 0 ; V_8 < 100 ; V_8 ++ ) {
V_529 = F_184 ( V_7 , V_542 ) ;
if ( ! ( V_529 & V_543 ) )
break;
F_96 ( 10 ) ;
}
if ( V_8 < 100 )
F_7 ( V_7 , L_87 , V_8 ) ;
else {
F_5 ( V_7 , L_88 ) ;
return - V_372 ;
}
F_88 ( V_7 , V_542 ,
V_544 ) ;
return 0 ;
}
