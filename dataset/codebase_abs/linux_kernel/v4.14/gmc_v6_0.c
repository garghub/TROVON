static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_2 ( ( void * ) V_2 ) ;
V_3 = F_3 ( V_4 ) ;
if ( F_4 ( V_3 , V_5 , V_6 ) != 1 ) {
F_5 ( V_7 , 0 ) ;
V_3 = F_6 ( V_3 ,
V_5 , V_6 , 0 ) ;
F_5 ( V_4 , V_3 | 1 ) ;
}
F_7 ( 100 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
T_1 V_8 ;
V_8 = F_3 ( V_4 ) ;
V_8 = F_6 ( V_8 , V_5 , V_6 , 0 ) ;
F_5 ( V_4 , V_8 ) ;
V_8 = F_6 ( 0 , V_9 , V_10 , 1 ) ;
V_8 = F_6 ( V_8 , V_9 , V_11 , 1 ) ;
F_5 ( V_7 , V_8 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
const char * V_12 ;
char V_13 [ 30 ] ;
int V_14 ;
bool V_15 = false ;
F_10 ( L_1 ) ;
switch ( V_2 -> V_16 ) {
case V_17 :
V_12 = L_2 ;
break;
case V_18 :
V_12 = L_3 ;
break;
case V_19 :
V_12 = L_4 ;
break;
case V_20 :
V_12 = L_5 ;
break;
case V_21 :
V_12 = L_6 ;
break;
default: F_11 () ;
}
if ( ( ( F_3 ( V_22 ) & 0xff000000 ) >> 24 ) == 0x58 )
V_15 = true ;
if ( V_15 )
snprintf ( V_13 , sizeof( V_13 ) , L_7 ) ;
else
snprintf ( V_13 , sizeof( V_13 ) , L_8 , V_12 ) ;
V_14 = F_12 ( & V_2 -> V_23 . V_24 , V_13 , V_2 -> V_25 ) ;
if ( V_14 )
goto V_26;
V_14 = F_13 ( V_2 -> V_23 . V_24 ) ;
V_26:
if ( V_14 ) {
F_14 ( V_2 -> V_25 ,
L_9 ,
V_13 ) ;
F_15 ( V_2 -> V_23 . V_24 ) ;
V_2 -> V_23 . V_24 = NULL ;
}
return V_14 ;
}
static int F_16 ( struct V_1 * V_2 )
{
const T_2 * V_27 = NULL ;
T_1 V_28 ;
const T_2 * V_29 = NULL ;
int V_30 , V_31 , V_32 ;
const struct V_33 * V_34 ;
if ( ! V_2 -> V_23 . V_24 )
return - V_35 ;
V_34 = ( const struct V_33 * ) V_2 -> V_23 . V_24 -> V_36 ;
F_17 ( & V_34 -> V_37 ) ;
V_2 -> V_23 . V_38 = F_18 ( V_34 -> V_37 . V_39 ) ;
V_31 = F_18 ( V_34 -> V_40 ) / ( 4 * 2 ) ;
V_29 = ( const T_2 * )
( V_2 -> V_23 . V_24 -> V_36 + F_18 ( V_34 -> V_41 ) ) ;
V_32 = F_18 ( V_34 -> V_37 . V_42 ) / 4 ;
V_27 = ( const T_2 * )
( V_2 -> V_23 . V_24 -> V_36 + F_18 ( V_34 -> V_37 . V_43 ) ) ;
V_28 = F_3 ( V_44 ) & V_45 ;
if ( V_28 == 0 ) {
F_5 ( V_44 , 0x00000008 ) ;
F_5 ( V_44 , 0x00000010 ) ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
F_5 ( V_46 , F_19 ( V_29 ++ ) ) ;
F_5 ( V_47 , F_19 ( V_29 ++ ) ) ;
}
for ( V_30 = 0 ; V_30 < V_32 ; V_30 ++ ) {
F_5 ( V_48 , F_19 ( V_27 ++ ) ) ;
}
F_5 ( V_44 , 0x00000008 ) ;
F_5 ( V_44 , 0x00000004 ) ;
F_5 ( V_44 , 0x00000001 ) ;
for ( V_30 = 0 ; V_30 < V_2 -> V_49 ; V_30 ++ ) {
if ( F_3 ( V_50 ) & V_51 )
break;
F_7 ( 1 ) ;
}
for ( V_30 = 0 ; V_30 < V_2 -> V_49 ; V_30 ++ ) {
if ( F_3 ( V_50 ) & V_52 )
break;
F_7 ( 1 ) ;
}
}
return 0 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_53 * V_23 )
{
T_3 V_54 = F_3 ( V_55 ) & 0xFFFF ;
V_54 <<= 24 ;
if ( V_23 -> V_56 > 0xFFC0000000ULL ) {
F_21 ( V_2 -> V_25 , L_10 ) ;
V_23 -> V_57 = 0xFFC0000000ULL ;
V_23 -> V_56 = 0xFFC0000000ULL ;
}
F_22 ( V_2 , & V_2 -> V_23 , V_54 ) ;
F_23 ( V_2 , V_23 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
int V_30 , V_58 ;
for ( V_30 = 0 , V_58 = 0 ; V_30 < 32 ; V_30 ++ , V_58 += 0x6 ) {
F_5 ( ( 0xb05 + V_58 ) , 0x00000000 ) ;
F_5 ( ( 0xb06 + V_58 ) , 0x00000000 ) ;
F_5 ( ( 0xb07 + V_58 ) , 0x00000000 ) ;
F_5 ( ( 0xb08 + V_58 ) , 0x00000000 ) ;
F_5 ( ( 0xb09 + V_58 ) , 0x00000000 ) ;
}
F_5 ( V_59 , 0 ) ;
if ( F_2 ( ( void * ) V_2 ) ) {
F_21 ( V_2 -> V_25 , L_11 ) ;
}
if ( V_2 -> V_60 . V_61 ) {
T_1 V_8 ;
V_8 = F_3 ( V_62 ) ;
V_8 |= V_63 ;
F_5 ( V_62 , V_8 ) ;
V_8 = F_3 ( V_64 ) ;
V_8 &= ~ V_65 ;
F_5 ( V_64 , V_8 ) ;
}
F_5 ( V_66 ,
V_2 -> V_23 . V_67 >> 12 ) ;
F_5 ( V_68 ,
V_2 -> V_23 . V_69 >> 12 ) ;
F_5 ( V_70 ,
V_2 -> V_71 . V_72 >> 12 ) ;
F_5 ( V_73 , 0 ) ;
F_5 ( V_74 , 0x0FFFFFFF ) ;
F_5 ( V_75 , 0x0FFFFFFF ) ;
if ( F_2 ( ( void * ) V_2 ) ) {
F_21 ( V_2 -> V_25 , L_11 ) ;
}
}
static int F_25 ( struct V_1 * V_2 )
{
T_1 V_8 ;
int V_76 , V_77 ;
V_8 = F_3 ( V_78 ) ;
if ( V_8 & ( 1 << 11 ) ) {
V_76 = 16 ;
} else if ( V_8 & V_79 ) {
V_76 = 64 ;
} else {
V_76 = 32 ;
}
V_8 = F_3 ( V_80 ) ;
switch ( ( V_8 & V_81 ) >> V_82 ) {
case 0 :
default:
V_77 = 1 ;
break;
case 1 :
V_77 = 2 ;
break;
case 2 :
V_77 = 4 ;
break;
case 3 :
V_77 = 8 ;
break;
case 4 :
V_77 = 3 ;
break;
case 5 :
V_77 = 6 ;
break;
case 6 :
V_77 = 10 ;
break;
case 7 :
V_77 = 12 ;
break;
case 8 :
V_77 = 16 ;
break;
}
V_2 -> V_23 . V_83 = V_77 * V_76 ;
V_2 -> V_23 . V_84 = F_26 ( V_2 -> V_85 , 0 ) ;
V_2 -> V_23 . V_86 = F_27 ( V_2 -> V_85 , 0 ) ;
V_2 -> V_23 . V_56 = F_3 ( V_87 ) * 1024ULL * 1024ULL ;
V_2 -> V_23 . V_57 = F_3 ( V_87 ) * 1024ULL * 1024ULL ;
V_2 -> V_23 . V_88 = V_2 -> V_23 . V_86 ;
if ( V_89 == - 1 ) {
switch ( V_2 -> V_16 ) {
case V_21 :
default:
V_2 -> V_23 . V_90 = 256ULL << 20 ;
break;
case V_19 :
case V_17 :
case V_18 :
case V_20 :
V_2 -> V_23 . V_90 = 1024ULL << 20 ;
break;
}
} else {
V_2 -> V_23 . V_90 = ( T_3 ) V_89 << 20 ;
}
F_20 ( V_2 , & V_2 -> V_23 ) ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 ,
T_4 V_91 )
{
F_5 ( V_92 , 0 ) ;
F_5 ( V_93 , 1 << V_91 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
void * V_94 ,
T_4 V_95 ,
T_5 V_96 ,
T_5 V_97 )
{
void T_6 * V_98 = ( void * ) V_94 ;
T_5 V_99 ;
V_99 = V_96 & 0xFFFFFFFFFFFFF000ULL ;
V_99 |= V_97 ;
F_30 ( V_99 , V_98 + ( V_95 * 8 ) ) ;
return 0 ;
}
static T_5 F_31 ( struct V_1 * V_2 ,
T_4 V_97 )
{
T_5 V_100 = 0 ;
if ( V_97 & V_101 )
V_100 |= V_102 ;
if ( V_97 & V_103 )
V_100 |= V_104 ;
if ( V_97 & V_105 )
V_100 |= V_106 ;
return V_100 ;
}
static T_5 F_32 ( struct V_1 * V_2 , T_5 V_96 )
{
F_33 ( V_96 & 0xFFFFFF0000000FFFULL ) ;
return V_96 ;
}
static void F_34 ( struct V_1 * V_2 ,
bool V_99 )
{
T_1 V_8 ;
V_8 = F_3 ( V_107 ) ;
V_8 = F_6 ( V_8 , V_108 ,
V_109 , V_99 ) ;
V_8 = F_6 ( V_8 , V_108 ,
V_110 , V_99 ) ;
V_8 = F_6 ( V_8 , V_108 ,
V_111 , V_99 ) ;
V_8 = F_6 ( V_8 , V_108 ,
V_112 , V_99 ) ;
V_8 = F_6 ( V_8 , V_108 ,
V_113 , V_99 ) ;
V_8 = F_6 ( V_8 , V_108 ,
V_114 , V_99 ) ;
F_5 ( V_107 , V_8 ) ;
}
static void F_35 ( struct V_1 * V_2 , bool V_115 )
{
T_1 V_8 ;
if ( V_115 && ! V_2 -> V_23 . V_116 ) {
F_21 ( V_2 -> V_25 , L_12 ) ;
V_2 -> V_23 . V_116 = true ;
}
V_8 = F_3 ( V_117 ) ;
V_8 = F_6 ( V_8 , V_118 ,
V_119 ,
V_115 ) ;
V_8 = F_6 ( V_8 , V_118 ,
V_120 ,
V_115 ) ;
V_8 = F_6 ( V_8 , V_118 ,
V_121 ,
V_115 ) ;
V_8 = F_6 ( V_8 , V_118 ,
V_122 ,
V_115 ) ;
F_5 ( V_117 , V_8 ) ;
if ( V_115 ) {
T_4 V_123 = V_124 >> V_125 ;
T_4 V_126 = V_2 -> V_127 . V_128 ;
F_5 ( V_129 , V_123 ) ;
F_5 ( V_130 , V_123 ) ;
F_5 ( V_131 , V_123 ) ;
F_5 ( V_132 , V_123 ) ;
F_5 ( V_133 , V_126 ) ;
F_5 ( V_134 , V_126 ) ;
F_5 ( V_135 , V_126 ) ;
F_5 ( V_136 , V_126 ) ;
} else {
F_5 ( V_129 , 0xfffffff ) ;
F_5 ( V_130 , 0xfffffff ) ;
F_5 ( V_131 , 0xfffffff ) ;
F_5 ( V_132 , 0xfffffff ) ;
F_5 ( V_133 , 0x0 ) ;
F_5 ( V_134 , 0x0 ) ;
F_5 ( V_135 , 0x0 ) ;
F_5 ( V_136 , 0x0 ) ;
}
}
static int F_36 ( struct V_1 * V_2 )
{
int V_137 , V_30 ;
T_1 V_138 ;
if ( V_2 -> V_139 . V_140 == NULL ) {
F_14 ( V_2 -> V_25 , L_13 ) ;
return - V_35 ;
}
V_137 = F_37 ( V_2 ) ;
if ( V_137 )
return V_137 ;
F_5 ( V_141 ,
( 0xA << 7 ) |
V_142 |
V_143 |
V_144 |
V_145 |
( 0UL << V_146 ) ) ;
F_5 ( V_147 ,
V_148 |
V_149 |
V_150 |
V_151 |
( 7UL << V_152 ) |
( 1UL << V_153 ) ) ;
F_5 ( V_154 ,
V_155 |
V_156 ) ;
V_138 = V_2 -> V_127 . V_157 ;
F_5 ( V_158 ,
V_159 |
( V_138 << V_160 ) |
( V_138 << V_161 ) ) ;
F_5 ( V_162 , V_2 -> V_23 . V_163 >> 12 ) ;
F_5 ( V_164 , V_2 -> V_23 . V_165 >> 12 ) ;
F_5 ( V_166 , V_2 -> V_139 . V_167 >> 12 ) ;
F_5 ( V_168 ,
( T_1 ) ( V_2 -> V_169 . V_96 >> 12 ) ) ;
F_5 ( V_170 , 0 ) ;
F_5 ( V_171 ,
V_172 |
( 0UL << V_173 ) |
V_174 ) ;
F_5 ( 0x575 , 0 ) ;
F_5 ( 0x576 , 0 ) ;
F_5 ( 0x577 , 0 ) ;
F_5 ( V_175 , 0 ) ;
F_5 ( V_176 , V_2 -> V_127 . V_128 - 1 ) ;
for ( V_30 = 1 ; V_30 < 16 ; V_30 ++ ) {
if ( V_30 < 8 )
F_5 ( V_166 + V_30 ,
V_2 -> V_139 . V_167 >> 12 ) ;
else
F_5 ( V_177 + V_30 - 8 ,
V_2 -> V_139 . V_167 >> 12 ) ;
}
F_5 ( V_178 ,
( T_1 ) ( V_2 -> V_169 . V_96 >> 12 ) ) ;
F_5 ( V_179 , 4 ) ;
F_5 ( V_107 ,
V_180 |
( 1UL << V_181 ) |
( ( V_2 -> V_127 . V_182 - 9 )
<< V_183 ) ) ;
if ( V_184 == V_185 )
F_34 ( V_2 , false ) ;
else
F_34 ( V_2 , true ) ;
F_28 ( V_2 , 0 ) ;
F_38 ( V_2 -> V_25 , L_14 ,
( unsigned ) ( V_2 -> V_23 . V_90 >> 20 ) ,
( unsigned long long ) V_2 -> V_139 . V_167 ) ;
V_2 -> V_139 . V_186 = true ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
int V_137 ;
if ( V_2 -> V_139 . V_140 ) {
F_21 ( V_2 -> V_25 , L_15 ) ;
return 0 ;
}
V_137 = F_40 ( V_2 ) ;
if ( V_137 )
return V_137 ;
V_2 -> V_139 . V_187 = V_2 -> V_139 . V_188 * 8 ;
V_2 -> V_139 . V_189 = 0 ;
return F_41 ( V_2 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_5 ( V_171 , 0 ) ;
F_5 ( V_107 , 0 ) ;
F_5 ( V_141 ,
V_144 |
( 0UL << V_146 ) ) ;
F_5 ( V_147 ,
V_150 |
V_151 |
( 7UL << V_152 ) |
( 1UL << V_153 ) ) ;
F_5 ( V_154 , 0 ) ;
F_5 ( V_158 ,
V_159 |
( 0UL << V_161 ) ) ;
F_43 ( V_2 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
}
static void F_47 ( struct V_1 * V_2 ,
T_1 V_190 , T_1 V_96 , T_1 V_191 )
{
T_1 V_192 ;
T_1 V_91 = F_4 ( V_190 , V_193 , V_194 ) ;
T_1 V_195 = F_4 ( V_190 , V_193 ,
V_196 ) ;
char V_197 [ 5 ] = { V_191 >> 24 , ( V_191 >> 16 ) & 0xff ,
( V_191 >> 8 ) & 0xff , V_191 & 0xff , 0 } ;
V_192 = F_4 ( V_190 , V_193 ,
V_198 ) ;
F_14 ( V_2 -> V_25 , L_16 ,
V_195 , V_91 , V_96 ,
F_4 ( V_190 , V_193 ,
V_199 ) ?
L_17 : L_18 , V_197 , V_191 , V_192 ) ;
}
static int F_48 ( int V_200 )
{
switch ( V_200 ) {
case V_201 :
return V_202 ;
case V_203 :
return V_204 ;
case V_205 :
return V_206 ;
case V_207 :
return V_208 ;
case V_209 :
return V_210 ;
case V_211 :
return V_212 ;
default:
return V_213 ;
}
}
static int F_49 ( void * V_214 )
{
struct V_1 * V_2 = (struct V_1 * ) V_214 ;
F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
return 0 ;
}
static int F_52 ( void * V_214 )
{
struct V_1 * V_2 = (struct V_1 * ) V_214 ;
if ( V_184 != V_185 )
return F_53 ( V_2 , & V_2 -> V_23 . V_215 , 0 ) ;
else
return 0 ;
}
static int F_54 ( void * V_214 )
{
int V_137 ;
int V_216 ;
struct V_1 * V_2 = (struct V_1 * ) V_214 ;
if ( V_2 -> V_97 & V_217 ) {
V_2 -> V_23 . V_218 = V_213 ;
} else {
T_1 V_8 = F_3 ( V_22 ) ;
V_8 &= V_219 ;
V_2 -> V_23 . V_218 = F_48 ( V_8 ) ;
}
V_137 = F_55 ( V_2 , V_220 , 146 , & V_2 -> V_23 . V_215 ) ;
if ( V_137 )
return V_137 ;
V_137 = F_55 ( V_2 , V_220 , 147 , & V_2 -> V_23 . V_215 ) ;
if ( V_137 )
return V_137 ;
F_56 ( V_2 , 64 , 4 ) ;
V_2 -> V_127 . V_128 = V_2 -> V_127 . V_221 << 18 ;
V_2 -> V_23 . V_222 = 0xffffffffffULL ;
V_2 -> V_23 . V_223 = 256 * 1024 ;
V_2 -> V_224 = false ;
V_216 = V_2 -> V_224 ? 32 : 40 ;
V_137 = F_57 ( V_2 -> V_85 , F_58 ( V_216 ) ) ;
if ( V_137 ) {
V_2 -> V_224 = true ;
V_216 = 32 ;
F_21 ( V_2 -> V_25 , L_19 ) ;
}
V_137 = F_59 ( V_2 -> V_85 , F_58 ( V_216 ) ) ;
if ( V_137 ) {
F_59 ( V_2 -> V_85 , F_58 ( 32 ) ) ;
F_21 ( V_2 -> V_25 , L_20 ) ;
}
V_137 = F_9 ( V_2 ) ;
if ( V_137 ) {
F_14 ( V_2 -> V_25 , L_21 ) ;
return V_137 ;
}
V_137 = F_25 ( V_2 ) ;
if ( V_137 )
return V_137 ;
V_137 = F_60 ( V_2 ) ;
if ( V_137 )
return V_137 ;
V_137 = F_39 ( V_2 ) ;
if ( V_137 )
return V_137 ;
V_2 -> V_127 . V_225 [ 0 ] . V_226 = V_227 ;
V_2 -> V_127 . V_228 = 1 ;
F_61 ( V_2 ) ;
if ( V_2 -> V_97 & V_217 ) {
T_3 V_8 = F_3 ( V_229 ) ;
V_8 <<= 22 ;
V_2 -> V_127 . V_230 = V_8 ;
} else {
V_2 -> V_127 . V_230 = 0 ;
}
return 0 ;
}
static int F_62 ( void * V_214 )
{
struct V_1 * V_2 = (struct V_1 * ) V_214 ;
F_63 ( V_2 ) ;
F_44 ( V_2 ) ;
F_64 ( V_2 ) ;
F_65 ( V_2 ) ;
return 0 ;
}
static int F_66 ( void * V_214 )
{
int V_137 ;
struct V_1 * V_2 = (struct V_1 * ) V_214 ;
F_24 ( V_2 ) ;
if ( ! ( V_2 -> V_97 & V_217 ) ) {
V_137 = F_16 ( V_2 ) ;
if ( V_137 ) {
F_14 ( V_2 -> V_25 , L_22 ) ;
return V_137 ;
}
}
V_137 = F_36 ( V_2 ) ;
if ( V_137 )
return V_137 ;
return V_137 ;
}
static int F_67 ( void * V_214 )
{
struct V_1 * V_2 = (struct V_1 * ) V_214 ;
F_68 ( V_2 , & V_2 -> V_23 . V_215 , 0 ) ;
F_42 ( V_2 ) ;
return 0 ;
}
static int F_69 ( void * V_214 )
{
struct V_1 * V_2 = (struct V_1 * ) V_214 ;
F_67 ( V_2 ) ;
return 0 ;
}
static int F_70 ( void * V_214 )
{
int V_137 ;
struct V_1 * V_2 = (struct V_1 * ) V_214 ;
V_137 = F_66 ( V_2 ) ;
if ( V_137 )
return V_137 ;
F_71 ( V_2 ) ;
return 0 ;
}
static bool F_72 ( void * V_214 )
{
struct V_1 * V_2 = (struct V_1 * ) V_214 ;
T_1 V_8 = F_3 ( V_231 ) ;
if ( V_8 & ( V_232 | V_233 |
V_234 | V_235 | V_236 ) )
return false ;
return true ;
}
static int F_2 ( void * V_214 )
{
unsigned V_30 ;
struct V_1 * V_2 = (struct V_1 * ) V_214 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_49 ; V_30 ++ ) {
if ( F_72 ( V_214 ) )
return 0 ;
F_7 ( 1 ) ;
}
return - V_237 ;
}
static int F_73 ( void * V_214 )
{
struct V_1 * V_2 = (struct V_1 * ) V_214 ;
T_1 V_238 = 0 ;
T_1 V_8 = F_3 ( V_231 ) ;
if ( V_8 & V_236 )
V_238 = F_6 ( V_238 ,
V_239 , V_240 , 1 ) ;
if ( V_8 & ( V_232 | V_233 |
V_234 | V_235 ) ) {
if ( ! ( V_2 -> V_97 & V_217 ) )
V_238 = F_6 ( V_238 ,
V_239 , V_241 , 1 ) ;
}
if ( V_238 ) {
F_1 ( V_2 ) ;
if ( F_2 ( V_2 ) ) {
F_21 ( V_2 -> V_25 , L_23 ) ;
}
V_8 = F_3 ( V_242 ) ;
V_8 |= V_238 ;
F_38 ( V_2 -> V_25 , L_24 , V_8 ) ;
F_5 ( V_242 , V_8 ) ;
V_8 = F_3 ( V_242 ) ;
F_7 ( 50 ) ;
V_8 &= ~ V_238 ;
F_5 ( V_242 , V_8 ) ;
V_8 = F_3 ( V_242 ) ;
F_7 ( 50 ) ;
F_8 ( V_2 ) ;
F_7 ( 50 ) ;
}
return 0 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_243 * V_244 ,
unsigned type ,
enum V_245 V_246 )
{
T_1 V_8 ;
T_1 V_247 = ( V_248 |
V_249 |
V_250 |
V_251 |
V_252 |
V_253 ) ;
switch ( V_246 ) {
case V_254 :
V_8 = F_3 ( V_171 ) ;
V_8 &= ~ V_247 ;
F_5 ( V_171 , V_8 ) ;
V_8 = F_3 ( V_107 ) ;
V_8 &= ~ V_247 ;
F_5 ( V_107 , V_8 ) ;
break;
case V_255 :
V_8 = F_3 ( V_171 ) ;
V_8 |= V_247 ;
F_5 ( V_171 , V_8 ) ;
V_8 = F_3 ( V_107 ) ;
V_8 |= V_247 ;
F_5 ( V_107 , V_8 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_243 * V_256 ,
struct V_257 * V_258 )
{
T_1 V_96 , V_190 ;
V_96 = F_3 ( V_259 ) ;
V_190 = F_3 ( V_260 ) ;
F_76 ( V_179 , 1 , ~ 1 ) ;
if ( ! V_96 && ! V_190 )
return 0 ;
if ( V_184 == V_261 )
F_34 ( V_2 , false ) ;
if ( F_77 () ) {
F_14 ( V_2 -> V_25 , L_25 ,
V_258 -> V_262 , V_258 -> V_263 [ 0 ] ) ;
F_14 ( V_2 -> V_25 , L_26 ,
V_96 ) ;
F_14 ( V_2 -> V_25 , L_27 ,
V_190 ) ;
F_47 ( V_2 , V_190 , V_96 , 0 ) ;
}
return 0 ;
}
static int F_78 ( void * V_214 ,
enum V_264 V_246 )
{
return 0 ;
}
static int F_79 ( void * V_214 ,
enum V_265 V_246 )
{
return 0 ;
}
static void F_50 ( struct V_1 * V_2 )
{
if ( V_2 -> V_139 . V_266 == NULL )
V_2 -> V_139 . V_266 = & V_267 ;
}
static void F_51 ( struct V_1 * V_2 )
{
V_2 -> V_23 . V_215 . V_268 = 1 ;
V_2 -> V_23 . V_215 . V_269 = & V_270 ;
}
