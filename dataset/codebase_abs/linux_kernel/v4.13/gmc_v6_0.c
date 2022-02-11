static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 ;
if ( V_2 -> V_6 . V_7 )
F_2 ( V_2 , V_4 ) ;
F_3 ( ( void * ) V_2 ) ;
V_5 = F_4 ( V_8 ) ;
if ( F_5 ( V_5 , V_9 , V_10 ) != 1 ) {
F_6 ( V_11 , 0 ) ;
V_5 = F_7 ( V_5 ,
V_9 , V_10 , 0 ) ;
F_6 ( V_8 , V_5 | 1 ) ;
}
F_8 ( 100 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_12 ;
V_12 = F_4 ( V_8 ) ;
V_12 = F_7 ( V_12 , V_9 , V_10 , 0 ) ;
F_6 ( V_8 , V_12 ) ;
V_12 = F_7 ( 0 , V_13 , V_14 , 1 ) ;
V_12 = F_7 ( V_12 , V_13 , V_15 , 1 ) ;
F_6 ( V_11 , V_12 ) ;
if ( V_2 -> V_6 . V_7 )
F_10 ( V_2 , V_4 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
const char * V_16 ;
char V_17 [ 30 ] ;
int V_18 ;
bool V_19 = false ;
F_12 ( L_1 ) ;
switch ( V_2 -> V_20 ) {
case V_21 :
V_16 = L_2 ;
break;
case V_22 :
V_16 = L_3 ;
break;
case V_23 :
V_16 = L_4 ;
break;
case V_24 :
V_16 = L_5 ;
break;
case V_25 :
V_16 = L_6 ;
break;
default: F_13 () ;
}
if ( ( ( F_4 ( V_26 ) & 0xff000000 ) >> 24 ) == 0x58 )
V_19 = true ;
if ( V_19 )
snprintf ( V_17 , sizeof( V_17 ) , L_7 ) ;
else
snprintf ( V_17 , sizeof( V_17 ) , L_8 , V_16 ) ;
V_18 = F_14 ( & V_2 -> V_27 . V_28 , V_17 , V_2 -> V_29 ) ;
if ( V_18 )
goto V_30;
V_18 = F_15 ( V_2 -> V_27 . V_28 ) ;
V_30:
if ( V_18 ) {
F_16 ( V_2 -> V_29 ,
L_9 ,
V_17 ) ;
F_17 ( V_2 -> V_27 . V_28 ) ;
V_2 -> V_27 . V_28 = NULL ;
}
return V_18 ;
}
static int F_18 ( struct V_1 * V_2 )
{
const T_2 * V_31 = NULL ;
T_1 V_32 ;
const T_2 * V_33 = NULL ;
int V_34 , V_35 , V_36 ;
const struct V_37 * V_38 ;
if ( ! V_2 -> V_27 . V_28 )
return - V_39 ;
V_38 = ( const struct V_37 * ) V_2 -> V_27 . V_28 -> V_40 ;
F_19 ( & V_38 -> V_41 ) ;
V_2 -> V_27 . V_42 = F_20 ( V_38 -> V_41 . V_43 ) ;
V_35 = F_20 ( V_38 -> V_44 ) / ( 4 * 2 ) ;
V_33 = ( const T_2 * )
( V_2 -> V_27 . V_28 -> V_40 + F_20 ( V_38 -> V_45 ) ) ;
V_36 = F_20 ( V_38 -> V_41 . V_46 ) / 4 ;
V_31 = ( const T_2 * )
( V_2 -> V_27 . V_28 -> V_40 + F_20 ( V_38 -> V_41 . V_47 ) ) ;
V_32 = F_4 ( V_48 ) & V_49 ;
if ( V_32 == 0 ) {
F_6 ( V_48 , 0x00000008 ) ;
F_6 ( V_48 , 0x00000010 ) ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ ) {
F_6 ( V_50 , F_21 ( V_33 ++ ) ) ;
F_6 ( V_51 , F_21 ( V_33 ++ ) ) ;
}
for ( V_34 = 0 ; V_34 < V_36 ; V_34 ++ ) {
F_6 ( V_52 , F_21 ( V_31 ++ ) ) ;
}
F_6 ( V_48 , 0x00000008 ) ;
F_6 ( V_48 , 0x00000004 ) ;
F_6 ( V_48 , 0x00000001 ) ;
for ( V_34 = 0 ; V_34 < V_2 -> V_53 ; V_34 ++ ) {
if ( F_4 ( V_54 ) & V_55 )
break;
F_8 ( 1 ) ;
}
for ( V_34 = 0 ; V_34 < V_2 -> V_53 ; V_34 ++ ) {
if ( F_4 ( V_54 ) & V_56 )
break;
F_8 ( 1 ) ;
}
}
return 0 ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_57 * V_27 )
{
if ( V_27 -> V_58 > 0xFFC0000000ULL ) {
F_23 ( V_2 -> V_29 , L_10 ) ;
V_27 -> V_59 = 0xFFC0000000ULL ;
V_27 -> V_58 = 0xFFC0000000ULL ;
}
F_24 ( V_2 , & V_2 -> V_27 , 0 ) ;
V_2 -> V_27 . V_60 = 0 ;
F_25 ( V_2 , V_27 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
T_1 V_12 ;
int V_34 , V_61 ;
for ( V_34 = 0 , V_61 = 0 ; V_34 < 32 ; V_34 ++ , V_61 += 0x6 ) {
F_6 ( ( 0xb05 + V_61 ) , 0x00000000 ) ;
F_6 ( ( 0xb06 + V_61 ) , 0x00000000 ) ;
F_6 ( ( 0xb07 + V_61 ) , 0x00000000 ) ;
F_6 ( ( 0xb08 + V_61 ) , 0x00000000 ) ;
F_6 ( ( 0xb09 + V_61 ) , 0x00000000 ) ;
}
F_6 ( V_62 , 0 ) ;
if ( V_2 -> V_6 . V_7 )
F_27 ( V_2 , false ) ;
F_1 ( V_2 , & V_4 ) ;
if ( F_3 ( ( void * ) V_2 ) ) {
F_23 ( V_2 -> V_29 , L_11 ) ;
}
F_6 ( V_63 , V_64 ) ;
F_6 ( V_65 ,
V_2 -> V_27 . V_66 >> 12 ) ;
F_6 ( V_67 ,
V_2 -> V_27 . V_68 >> 12 ) ;
F_6 ( V_69 ,
V_2 -> V_70 . V_71 >> 12 ) ;
V_12 = ( ( V_2 -> V_27 . V_68 >> 24 ) & 0xFFFF ) << 16 ;
V_12 |= ( ( V_2 -> V_27 . V_66 >> 24 ) & 0xFFFF ) ;
F_6 ( V_72 , V_12 ) ;
F_6 ( V_73 , ( V_2 -> V_27 . V_66 >> 8 ) ) ;
F_6 ( V_74 , ( 2 << 7 ) | ( 1 << 30 ) ) ;
F_6 ( V_75 , 0x3FFFFFFF ) ;
F_6 ( V_76 , 0 ) ;
F_6 ( V_77 , 0x0FFFFFFF ) ;
F_6 ( V_78 , 0x0FFFFFFF ) ;
if ( F_3 ( ( void * ) V_2 ) ) {
F_23 ( V_2 -> V_29 , L_11 ) ;
}
F_9 ( V_2 , & V_4 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
T_1 V_12 ;
int V_79 , V_80 ;
V_12 = F_4 ( V_81 ) ;
if ( V_12 & ( 1 << 11 ) ) {
V_79 = 16 ;
} else if ( V_12 & V_82 ) {
V_79 = 64 ;
} else {
V_79 = 32 ;
}
V_12 = F_4 ( V_83 ) ;
switch ( ( V_12 & V_84 ) >> V_85 ) {
case 0 :
default:
V_80 = 1 ;
break;
case 1 :
V_80 = 2 ;
break;
case 2 :
V_80 = 4 ;
break;
case 3 :
V_80 = 8 ;
break;
case 4 :
V_80 = 3 ;
break;
case 5 :
V_80 = 6 ;
break;
case 6 :
V_80 = 10 ;
break;
case 7 :
V_80 = 12 ;
break;
case 8 :
V_80 = 16 ;
break;
}
V_2 -> V_27 . V_86 = V_80 * V_79 ;
V_2 -> V_27 . V_87 = F_29 ( V_2 -> V_88 , 0 ) ;
V_2 -> V_27 . V_89 = F_30 ( V_2 -> V_88 , 0 ) ;
V_2 -> V_27 . V_58 = F_4 ( V_90 ) * 1024ULL * 1024ULL ;
V_2 -> V_27 . V_59 = F_4 ( V_90 ) * 1024ULL * 1024ULL ;
V_2 -> V_27 . V_91 = V_2 -> V_27 . V_89 ;
if ( V_92 == - 1 )
V_2 -> V_27 . V_93 = F_31 ( ( V_94 << 20 ) ,
V_2 -> V_27 . V_58 ) ;
else
V_2 -> V_27 . V_93 = ( V_95 ) V_92 << 20 ;
F_22 ( V_2 , & V_2 -> V_27 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_2 ,
T_3 V_96 )
{
F_6 ( V_97 , 0 ) ;
F_6 ( V_98 , 1 << V_96 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
void * V_99 ,
T_3 V_100 ,
V_95 V_101 ,
V_95 V_102 )
{
void T_4 * V_103 = ( void * ) V_99 ;
V_95 V_104 ;
V_104 = V_101 & 0xFFFFFFFFFFFFF000ULL ;
V_104 |= V_102 ;
F_34 ( V_104 , V_103 + ( V_100 * 8 ) ) ;
return 0 ;
}
static V_95 F_35 ( struct V_1 * V_2 ,
T_3 V_102 )
{
V_95 V_105 = 0 ;
if ( V_102 & V_106 )
V_105 |= V_107 ;
if ( V_102 & V_108 )
V_105 |= V_109 ;
if ( V_102 & V_110 )
V_105 |= V_111 ;
return V_105 ;
}
static V_95 F_36 ( struct V_1 * V_2 , V_95 V_101 )
{
F_37 ( V_101 & 0xFFFFFF0000000FFFULL ) ;
return V_101 ;
}
static void F_38 ( struct V_1 * V_2 ,
bool V_104 )
{
T_1 V_12 ;
V_12 = F_4 ( V_112 ) ;
V_12 = F_7 ( V_12 , V_113 ,
V_114 , V_104 ) ;
V_12 = F_7 ( V_12 , V_113 ,
V_115 , V_104 ) ;
V_12 = F_7 ( V_12 , V_113 ,
V_116 , V_104 ) ;
V_12 = F_7 ( V_12 , V_113 ,
V_117 , V_104 ) ;
V_12 = F_7 ( V_12 , V_113 ,
V_118 , V_104 ) ;
V_12 = F_7 ( V_12 , V_113 ,
V_119 , V_104 ) ;
F_6 ( V_112 , V_12 ) ;
}
static void F_39 ( struct V_1 * V_2 , bool V_120 )
{
T_1 V_12 ;
if ( V_120 && ! V_2 -> V_27 . V_121 ) {
F_23 ( V_2 -> V_29 , L_12 ) ;
V_2 -> V_27 . V_121 = true ;
}
V_12 = F_4 ( V_122 ) ;
V_12 = F_7 ( V_12 , V_123 ,
V_124 ,
V_120 ) ;
V_12 = F_7 ( V_12 , V_123 ,
V_125 ,
V_120 ) ;
V_12 = F_7 ( V_12 , V_123 ,
V_126 ,
V_120 ) ;
V_12 = F_7 ( V_12 , V_123 ,
V_127 ,
V_120 ) ;
F_6 ( V_122 , V_12 ) ;
if ( V_120 ) {
T_3 V_128 = V_129 >> V_130 ;
T_3 V_131 = V_2 -> V_132 . V_133 ;
F_6 ( V_134 , V_128 ) ;
F_6 ( V_135 , V_128 ) ;
F_6 ( V_136 , V_128 ) ;
F_6 ( V_137 , V_128 ) ;
F_6 ( V_138 , V_131 ) ;
F_6 ( V_139 , V_131 ) ;
F_6 ( V_140 , V_131 ) ;
F_6 ( V_141 , V_131 ) ;
} else {
F_6 ( V_134 , 0xfffffff ) ;
F_6 ( V_135 , 0xfffffff ) ;
F_6 ( V_136 , 0xfffffff ) ;
F_6 ( V_137 , 0xfffffff ) ;
F_6 ( V_138 , 0x0 ) ;
F_6 ( V_139 , 0x0 ) ;
F_6 ( V_140 , 0x0 ) ;
F_6 ( V_141 , 0x0 ) ;
}
}
static int F_40 ( struct V_1 * V_2 )
{
int V_142 , V_34 ;
if ( V_2 -> V_143 . V_144 == NULL ) {
F_16 ( V_2 -> V_29 , L_13 ) ;
return - V_39 ;
}
V_142 = F_41 ( V_2 ) ;
if ( V_142 )
return V_142 ;
F_6 ( V_145 ,
( 0xA << 7 ) |
V_146 |
V_147 |
V_148 |
V_149 |
( 0UL << V_150 ) ) ;
F_6 ( V_151 ,
V_152 |
V_153 |
V_154 |
V_155 |
( 7UL << V_156 ) |
( 1UL << V_157 ) ) ;
F_6 ( V_158 ,
V_159 |
V_160 ) ;
F_6 ( V_161 ,
V_162 |
( 4UL << V_163 ) |
( 4UL << V_164 ) ) ;
F_6 ( V_165 , V_2 -> V_27 . V_166 >> 12 ) ;
F_6 ( V_167 , V_2 -> V_27 . V_168 >> 12 ) ;
F_6 ( V_169 , V_2 -> V_143 . V_170 >> 12 ) ;
F_6 ( V_171 ,
( T_1 ) ( V_2 -> V_172 . V_101 >> 12 ) ) ;
F_6 ( V_173 , 0 ) ;
F_6 ( V_174 ,
V_175 |
( 0UL << V_176 ) |
V_177 ) ;
F_6 ( 0x575 , 0 ) ;
F_6 ( 0x576 , 0 ) ;
F_6 ( 0x577 , 0 ) ;
F_6 ( V_178 , 0 ) ;
F_6 ( V_179 , V_2 -> V_132 . V_133 - 1 ) ;
for ( V_34 = 1 ; V_34 < 16 ; V_34 ++ ) {
if ( V_34 < 8 )
F_6 ( V_169 + V_34 ,
V_2 -> V_143 . V_170 >> 12 ) ;
else
F_6 ( V_180 + V_34 - 8 ,
V_2 -> V_143 . V_170 >> 12 ) ;
}
F_6 ( V_181 ,
( T_1 ) ( V_2 -> V_172 . V_101 >> 12 ) ) ;
F_6 ( V_182 , 4 ) ;
F_6 ( V_112 ,
V_183 |
( 1UL << V_184 ) |
( ( V_2 -> V_132 . V_185 - 9 )
<< V_186 ) ) ;
if ( V_187 == V_188 )
F_38 ( V_2 , false ) ;
else
F_38 ( V_2 , true ) ;
F_32 ( V_2 , 0 ) ;
F_42 ( V_2 -> V_29 , L_14 ,
( unsigned ) ( V_2 -> V_27 . V_93 >> 20 ) ,
( unsigned long long ) V_2 -> V_143 . V_170 ) ;
V_2 -> V_143 . V_189 = true ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_142 ;
if ( V_2 -> V_143 . V_144 ) {
F_23 ( V_2 -> V_29 , L_15 ) ;
return 0 ;
}
V_142 = F_44 ( V_2 ) ;
if ( V_142 )
return V_142 ;
V_2 -> V_143 . V_190 = V_2 -> V_143 . V_191 * 8 ;
V_2 -> V_143 . V_192 = 0 ;
return F_45 ( V_2 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
F_6 ( V_174 , 0 ) ;
F_6 ( V_112 , 0 ) ;
F_6 ( V_145 ,
V_148 |
( 0UL << V_150 ) ) ;
F_6 ( V_151 ,
V_154 |
V_155 |
( 7UL << V_156 ) |
( 1UL << V_157 ) ) ;
F_6 ( V_158 , 0 ) ;
F_6 ( V_161 ,
V_162 |
( 0UL << V_164 ) ) ;
F_47 ( V_2 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_49 ( V_2 ) ;
F_50 ( V_2 ) ;
}
static void F_51 ( struct V_1 * V_2 ,
T_1 V_193 , T_1 V_101 , T_1 V_194 )
{
T_1 V_195 ;
T_1 V_96 = F_5 ( V_193 , V_196 , V_197 ) ;
T_1 V_198 = F_5 ( V_193 , V_196 ,
V_199 ) ;
char V_200 [ 5 ] = { V_194 >> 24 , ( V_194 >> 16 ) & 0xff ,
( V_194 >> 8 ) & 0xff , V_194 & 0xff , 0 } ;
V_195 = F_5 ( V_193 , V_196 ,
V_201 ) ;
F_16 ( V_2 -> V_29 , L_16 ,
V_198 , V_96 , V_101 ,
F_5 ( V_193 , V_196 ,
V_202 ) ?
L_17 : L_18 , V_200 , V_194 , V_195 ) ;
}
static int F_52 ( int V_203 )
{
switch ( V_203 ) {
case V_204 :
return V_205 ;
case V_206 :
return V_207 ;
case V_208 :
return V_209 ;
case V_210 :
return V_211 ;
case V_212 :
return V_213 ;
case V_214 :
return V_215 ;
default:
return V_216 ;
}
}
static int F_53 ( void * V_217 )
{
struct V_1 * V_2 = (struct V_1 * ) V_217 ;
F_54 ( V_2 ) ;
F_55 ( V_2 ) ;
return 0 ;
}
static int F_56 ( void * V_217 )
{
struct V_1 * V_2 = (struct V_1 * ) V_217 ;
if ( V_187 != V_188 )
return F_57 ( V_2 , & V_2 -> V_27 . V_218 , 0 ) ;
else
return 0 ;
}
static int F_58 ( void * V_217 )
{
int V_142 ;
int V_219 ;
struct V_1 * V_2 = (struct V_1 * ) V_217 ;
if ( V_2 -> V_102 & V_220 ) {
V_2 -> V_27 . V_221 = V_216 ;
} else {
T_1 V_12 = F_4 ( V_26 ) ;
V_12 &= V_222 ;
V_2 -> V_27 . V_221 = F_52 ( V_12 ) ;
}
V_142 = F_59 ( V_2 , V_223 , 146 , & V_2 -> V_27 . V_218 ) ;
if ( V_142 )
return V_142 ;
V_142 = F_59 ( V_2 , V_223 , 147 , & V_2 -> V_27 . V_218 ) ;
if ( V_142 )
return V_142 ;
F_60 ( V_2 , 64 ) ;
V_2 -> V_132 . V_133 = V_2 -> V_132 . V_224 << 18 ;
V_2 -> V_27 . V_225 = 0xffffffffffULL ;
V_2 -> V_27 . V_226 = 256 * 1024 ;
V_2 -> V_227 = false ;
V_219 = V_2 -> V_227 ? 32 : 40 ;
V_142 = F_61 ( V_2 -> V_88 , F_62 ( V_219 ) ) ;
if ( V_142 ) {
V_2 -> V_227 = true ;
V_219 = 32 ;
F_23 ( V_2 -> V_29 , L_19 ) ;
}
V_142 = F_63 ( V_2 -> V_88 , F_62 ( V_219 ) ) ;
if ( V_142 ) {
F_63 ( V_2 -> V_88 , F_62 ( 32 ) ) ;
F_23 ( V_2 -> V_29 , L_20 ) ;
}
V_142 = F_11 ( V_2 ) ;
if ( V_142 ) {
F_16 ( V_2 -> V_29 , L_21 ) ;
return V_142 ;
}
V_142 = F_28 ( V_2 ) ;
if ( V_142 )
return V_142 ;
V_142 = F_64 ( V_2 ) ;
if ( V_142 )
return V_142 ;
V_142 = F_43 ( V_2 ) ;
if ( V_142 )
return V_142 ;
V_2 -> V_132 . V_228 [ 0 ] . V_229 = V_230 ;
V_2 -> V_132 . V_231 = 1 ;
F_65 ( V_2 ) ;
if ( V_2 -> V_102 & V_220 ) {
T_5 V_12 = F_4 ( V_232 ) ;
V_12 <<= 22 ;
V_2 -> V_132 . V_233 = V_12 ;
} else {
V_2 -> V_132 . V_233 = 0 ;
}
return 0 ;
}
static int F_66 ( void * V_217 )
{
struct V_1 * V_2 = (struct V_1 * ) V_217 ;
F_67 ( V_2 ) ;
F_48 ( V_2 ) ;
F_68 ( V_2 ) ;
F_69 ( V_2 ) ;
return 0 ;
}
static int F_70 ( void * V_217 )
{
int V_142 ;
struct V_1 * V_2 = (struct V_1 * ) V_217 ;
F_26 ( V_2 ) ;
if ( ! ( V_2 -> V_102 & V_220 ) ) {
V_142 = F_18 ( V_2 ) ;
if ( V_142 ) {
F_16 ( V_2 -> V_29 , L_22 ) ;
return V_142 ;
}
}
V_142 = F_40 ( V_2 ) ;
if ( V_142 )
return V_142 ;
return V_142 ;
}
static int F_71 ( void * V_217 )
{
struct V_1 * V_2 = (struct V_1 * ) V_217 ;
F_72 ( V_2 , & V_2 -> V_27 . V_218 , 0 ) ;
F_46 ( V_2 ) ;
return 0 ;
}
static int F_73 ( void * V_217 )
{
struct V_1 * V_2 = (struct V_1 * ) V_217 ;
F_71 ( V_2 ) ;
return 0 ;
}
static int F_74 ( void * V_217 )
{
int V_142 ;
struct V_1 * V_2 = (struct V_1 * ) V_217 ;
V_142 = F_70 ( V_2 ) ;
if ( V_142 )
return V_142 ;
F_75 ( V_2 ) ;
return 0 ;
}
static bool F_76 ( void * V_217 )
{
struct V_1 * V_2 = (struct V_1 * ) V_217 ;
T_1 V_12 = F_4 ( V_234 ) ;
if ( V_12 & ( V_235 | V_236 |
V_237 | V_238 | V_239 ) )
return false ;
return true ;
}
static int F_3 ( void * V_217 )
{
unsigned V_34 ;
struct V_1 * V_2 = (struct V_1 * ) V_217 ;
for ( V_34 = 0 ; V_34 < V_2 -> V_53 ; V_34 ++ ) {
if ( F_76 ( V_217 ) )
return 0 ;
F_8 ( 1 ) ;
}
return - V_240 ;
}
static int F_77 ( void * V_217 )
{
struct V_1 * V_2 = (struct V_1 * ) V_217 ;
struct V_3 V_4 ;
T_1 V_241 = 0 ;
T_1 V_12 = F_4 ( V_234 ) ;
if ( V_12 & V_239 )
V_241 = F_7 ( V_241 ,
V_242 , V_243 , 1 ) ;
if ( V_12 & ( V_235 | V_236 |
V_237 | V_238 ) ) {
if ( ! ( V_2 -> V_102 & V_220 ) )
V_241 = F_7 ( V_241 ,
V_242 , V_244 , 1 ) ;
}
if ( V_241 ) {
F_1 ( V_2 , & V_4 ) ;
if ( F_3 ( V_2 ) ) {
F_23 ( V_2 -> V_29 , L_23 ) ;
}
V_12 = F_4 ( V_245 ) ;
V_12 |= V_241 ;
F_42 ( V_2 -> V_29 , L_24 , V_12 ) ;
F_6 ( V_245 , V_12 ) ;
V_12 = F_4 ( V_245 ) ;
F_8 ( 50 ) ;
V_12 &= ~ V_241 ;
F_6 ( V_245 , V_12 ) ;
V_12 = F_4 ( V_245 ) ;
F_8 ( 50 ) ;
F_9 ( V_2 , & V_4 ) ;
F_8 ( 50 ) ;
}
return 0 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_246 * V_247 ,
unsigned type ,
enum V_248 V_249 )
{
T_1 V_12 ;
T_1 V_250 = ( V_251 |
V_252 |
V_253 |
V_254 |
V_255 |
V_256 ) ;
switch ( V_249 ) {
case V_257 :
V_12 = F_4 ( V_174 ) ;
V_12 &= ~ V_250 ;
F_6 ( V_174 , V_12 ) ;
V_12 = F_4 ( V_112 ) ;
V_12 &= ~ V_250 ;
F_6 ( V_112 , V_12 ) ;
break;
case V_258 :
V_12 = F_4 ( V_174 ) ;
V_12 |= V_250 ;
F_6 ( V_174 , V_12 ) ;
V_12 = F_4 ( V_112 ) ;
V_12 |= V_250 ;
F_6 ( V_112 , V_12 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_246 * V_259 ,
struct V_260 * V_261 )
{
T_1 V_101 , V_193 ;
V_101 = F_4 ( V_262 ) ;
V_193 = F_4 ( V_263 ) ;
F_80 ( V_182 , 1 , ~ 1 ) ;
if ( ! V_101 && ! V_193 )
return 0 ;
if ( V_187 == V_264 )
F_38 ( V_2 , false ) ;
if ( F_81 () ) {
F_16 ( V_2 -> V_29 , L_25 ,
V_261 -> V_265 , V_261 -> V_266 [ 0 ] ) ;
F_16 ( V_2 -> V_29 , L_26 ,
V_101 ) ;
F_16 ( V_2 -> V_29 , L_27 ,
V_193 ) ;
F_51 ( V_2 , V_193 , V_101 , 0 ) ;
}
return 0 ;
}
static int F_82 ( void * V_217 ,
enum V_267 V_249 )
{
return 0 ;
}
static int F_83 ( void * V_217 ,
enum V_268 V_249 )
{
return 0 ;
}
static void F_54 ( struct V_1 * V_2 )
{
if ( V_2 -> V_143 . V_269 == NULL )
V_2 -> V_143 . V_269 = & V_270 ;
}
static void F_55 ( struct V_1 * V_2 )
{
V_2 -> V_27 . V_218 . V_271 = 1 ;
V_2 -> V_27 . V_218 . V_272 = & V_273 ;
}
