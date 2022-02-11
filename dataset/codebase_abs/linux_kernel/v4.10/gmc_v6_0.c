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
V_2 -> V_27 . V_93 = F_31 ( ( 1024ULL << 20 ) , V_2 -> V_27 . V_58 ) ;
else
V_2 -> V_27 . V_93 = ( V_94 ) V_92 << 20 ;
F_22 ( V_2 , & V_2 -> V_27 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_2 ,
T_3 V_95 )
{
F_6 ( V_96 , 0 ) ;
F_6 ( V_97 , 1 << V_95 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
void * V_98 ,
T_3 V_99 ,
V_94 V_100 ,
T_3 V_101 )
{
void T_4 * V_102 = ( void * ) V_98 ;
V_94 V_103 ;
V_103 = V_100 & 0xFFFFFFFFFFFFF000ULL ;
V_103 |= V_101 ;
F_34 ( V_103 , V_102 + ( V_99 * 8 ) ) ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 ,
bool V_103 )
{
T_1 V_12 ;
V_12 = F_4 ( V_104 ) ;
V_12 = F_7 ( V_12 , V_105 ,
V_106 , V_103 ) ;
V_12 = F_7 ( V_12 , V_105 ,
V_107 , V_103 ) ;
V_12 = F_7 ( V_12 , V_105 ,
V_108 , V_103 ) ;
V_12 = F_7 ( V_12 , V_105 ,
V_109 , V_103 ) ;
V_12 = F_7 ( V_12 , V_105 ,
V_110 , V_103 ) ;
V_12 = F_7 ( V_12 , V_105 ,
V_111 , V_103 ) ;
F_6 ( V_104 , V_12 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_112 , V_34 ;
if ( V_2 -> V_113 . V_114 == NULL ) {
F_16 ( V_2 -> V_29 , L_12 ) ;
return - V_39 ;
}
V_112 = F_37 ( V_2 ) ;
if ( V_112 )
return V_112 ;
F_6 ( V_115 ,
( 0xA << 7 ) |
V_116 |
V_117 |
V_118 |
V_119 |
( 0UL << V_120 ) ) ;
F_6 ( V_121 ,
V_122 |
V_123 |
V_124 |
V_125 |
( 7UL << V_126 ) |
( 1UL << V_127 ) ) ;
F_6 ( V_128 ,
V_129 |
V_130 ) ;
F_6 ( V_131 ,
V_132 |
( 4UL << V_133 ) |
( 4UL << V_134 ) ) ;
F_6 ( V_135 , V_2 -> V_27 . V_136 >> 12 ) ;
F_6 ( V_137 , V_2 -> V_27 . V_138 >> 12 ) ;
F_6 ( V_139 , V_2 -> V_113 . V_140 >> 12 ) ;
F_6 ( V_141 ,
( T_1 ) ( V_2 -> V_142 . V_100 >> 12 ) ) ;
F_6 ( V_143 , 0 ) ;
F_6 ( V_144 ,
V_145 |
( 0UL << V_146 ) |
V_147 ) ;
F_6 ( 0x575 , 0 ) ;
F_6 ( 0x576 , 0 ) ;
F_6 ( 0x577 , 0 ) ;
F_6 ( V_148 , 0 ) ;
F_6 ( V_149 , V_2 -> V_150 . V_151 - 1 ) ;
for ( V_34 = 1 ; V_34 < 16 ; V_34 ++ ) {
if ( V_34 < 8 )
F_6 ( V_139 + V_34 ,
V_2 -> V_113 . V_140 >> 12 ) ;
else
F_6 ( V_152 + V_34 - 8 ,
V_2 -> V_113 . V_140 >> 12 ) ;
}
F_6 ( V_153 ,
( T_1 ) ( V_2 -> V_142 . V_100 >> 12 ) ) ;
F_6 ( V_154 , 4 ) ;
F_6 ( V_104 ,
V_155 |
( 1UL << V_156 ) |
( ( V_157 - 9 ) << V_158 ) ) ;
if ( V_159 == V_160 )
F_35 ( V_2 , false ) ;
else
F_35 ( V_2 , true ) ;
F_32 ( V_2 , 0 ) ;
F_38 ( V_2 -> V_29 , L_13 ,
( unsigned ) ( V_2 -> V_27 . V_93 >> 20 ) ,
( unsigned long long ) V_2 -> V_113 . V_140 ) ;
V_2 -> V_113 . V_161 = true ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
int V_112 ;
if ( V_2 -> V_113 . V_114 ) {
F_23 ( V_2 -> V_29 , L_14 ) ;
return 0 ;
}
V_112 = F_40 ( V_2 ) ;
if ( V_112 )
return V_112 ;
V_2 -> V_113 . V_162 = V_2 -> V_113 . V_163 * 8 ;
return F_41 ( V_2 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_6 ( V_144 , 0 ) ;
F_6 ( V_104 , 0 ) ;
F_6 ( V_115 ,
V_118 |
( 0UL << V_120 ) ) ;
F_6 ( V_121 ,
V_124 |
V_125 |
( 7UL << V_126 ) |
( 1UL << V_127 ) ) ;
F_6 ( V_128 , 0 ) ;
F_6 ( V_131 ,
V_132 |
( 0UL << V_134 ) ) ;
F_43 ( V_2 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
V_2 -> V_150 . V_164 = V_165 ;
F_48 ( V_2 ) ;
if ( V_2 -> V_101 & V_166 ) {
T_5 V_12 = F_4 ( V_167 ) ;
V_12 <<= 22 ;
V_2 -> V_150 . V_168 = V_12 ;
} else
V_2 -> V_150 . V_168 = 0 ;
return 0 ;
}
static void F_49 ( struct V_1 * V_2 )
{
}
static void F_50 ( struct V_1 * V_2 ,
T_1 V_169 , T_1 V_100 , T_1 V_170 )
{
T_1 V_171 ;
T_1 V_95 = F_5 ( V_169 , V_172 , V_173 ) ;
T_1 V_174 = F_5 ( V_169 , V_172 ,
V_175 ) ;
char V_176 [ 5 ] = { V_170 >> 24 , ( V_170 >> 16 ) & 0xff ,
( V_170 >> 8 ) & 0xff , V_170 & 0xff , 0 } ;
V_171 = F_5 ( V_169 , V_172 ,
V_177 ) ;
F_16 ( V_2 -> V_29 , L_15 ,
V_174 , V_95 , V_100 ,
F_5 ( V_169 , V_172 ,
V_178 ) ?
L_16 : L_17 , V_176 , V_170 , V_171 ) ;
}
static int F_51 ( int V_179 )
{
switch ( V_179 ) {
case V_180 :
return V_181 ;
case V_182 :
return V_183 ;
case V_184 :
return V_185 ;
case V_186 :
return V_187 ;
case V_188 :
return V_189 ;
case V_190 :
return V_191 ;
default:
return V_192 ;
}
}
static int F_52 ( void * V_193 )
{
struct V_1 * V_2 = (struct V_1 * ) V_193 ;
F_53 ( V_2 ) ;
F_54 ( V_2 ) ;
if ( V_2 -> V_101 & V_166 ) {
V_2 -> V_27 . V_194 = V_192 ;
} else {
T_1 V_12 = F_4 ( V_26 ) ;
V_12 &= V_195 ;
V_2 -> V_27 . V_194 = F_51 ( V_12 ) ;
}
return 0 ;
}
static int F_55 ( void * V_193 )
{
struct V_1 * V_2 = (struct V_1 * ) V_193 ;
if ( V_159 != V_160 )
return F_56 ( V_2 , & V_2 -> V_27 . V_196 , 0 ) ;
else
return 0 ;
}
static int F_57 ( void * V_193 )
{
int V_112 ;
int V_197 ;
struct V_1 * V_2 = (struct V_1 * ) V_193 ;
V_112 = F_58 ( V_2 , 146 , & V_2 -> V_27 . V_196 ) ;
if ( V_112 )
return V_112 ;
V_112 = F_58 ( V_2 , 147 , & V_2 -> V_27 . V_196 ) ;
if ( V_112 )
return V_112 ;
V_2 -> V_150 . V_151 = V_198 << 18 ;
V_2 -> V_27 . V_199 = 0xffffffffffULL ;
V_2 -> V_200 = false ;
V_197 = V_2 -> V_200 ? 32 : 40 ;
V_112 = F_59 ( V_2 -> V_88 , F_60 ( V_197 ) ) ;
if ( V_112 ) {
V_2 -> V_200 = true ;
V_197 = 32 ;
F_23 ( V_2 -> V_29 , L_18 ) ;
}
V_112 = F_61 ( V_2 -> V_88 , F_60 ( V_197 ) ) ;
if ( V_112 ) {
F_61 ( V_2 -> V_88 , F_60 ( 32 ) ) ;
F_23 ( V_2 -> V_29 , L_19 ) ;
}
V_112 = F_11 ( V_2 ) ;
if ( V_112 ) {
F_16 ( V_2 -> V_29 , L_20 ) ;
return V_112 ;
}
V_112 = F_28 ( V_2 ) ;
if ( V_112 )
return V_112 ;
V_112 = F_62 ( V_2 ) ;
if ( V_112 )
return V_112 ;
V_112 = F_39 ( V_2 ) ;
if ( V_112 )
return V_112 ;
if ( ! V_2 -> V_150 . V_201 ) {
V_112 = F_47 ( V_2 ) ;
if ( V_112 ) {
F_16 ( V_2 -> V_29 , L_21 , V_112 ) ;
return V_112 ;
}
V_2 -> V_150 . V_201 = true ;
}
return V_112 ;
}
static int F_63 ( void * V_193 )
{
struct V_1 * V_2 = (struct V_1 * ) V_193 ;
if ( V_2 -> V_150 . V_201 ) {
F_49 ( V_2 ) ;
V_2 -> V_150 . V_201 = false ;
}
F_44 ( V_2 ) ;
F_64 ( V_2 ) ;
F_65 ( V_2 ) ;
return 0 ;
}
static int F_66 ( void * V_193 )
{
int V_112 ;
struct V_1 * V_2 = (struct V_1 * ) V_193 ;
F_26 ( V_2 ) ;
if ( ! ( V_2 -> V_101 & V_166 ) ) {
V_112 = F_18 ( V_2 ) ;
if ( V_112 ) {
F_16 ( V_2 -> V_29 , L_22 ) ;
return V_112 ;
}
}
V_112 = F_36 ( V_2 ) ;
if ( V_112 )
return V_112 ;
return V_112 ;
}
static int F_67 ( void * V_193 )
{
struct V_1 * V_2 = (struct V_1 * ) V_193 ;
F_68 ( V_2 , & V_2 -> V_27 . V_196 , 0 ) ;
F_42 ( V_2 ) ;
return 0 ;
}
static int F_69 ( void * V_193 )
{
struct V_1 * V_2 = (struct V_1 * ) V_193 ;
if ( V_2 -> V_150 . V_201 ) {
F_49 ( V_2 ) ;
V_2 -> V_150 . V_201 = false ;
}
F_67 ( V_2 ) ;
return 0 ;
}
static int F_70 ( void * V_193 )
{
int V_112 ;
struct V_1 * V_2 = (struct V_1 * ) V_193 ;
V_112 = F_66 ( V_2 ) ;
if ( V_112 )
return V_112 ;
if ( ! V_2 -> V_150 . V_201 ) {
V_112 = F_47 ( V_2 ) ;
if ( V_112 ) {
F_16 ( V_2 -> V_29 , L_21 , V_112 ) ;
return V_112 ;
}
V_2 -> V_150 . V_201 = true ;
}
return V_112 ;
}
static bool F_71 ( void * V_193 )
{
struct V_1 * V_2 = (struct V_1 * ) V_193 ;
T_1 V_12 = F_4 ( V_202 ) ;
if ( V_12 & ( V_203 | V_204 |
V_205 | V_206 | V_207 ) )
return false ;
return true ;
}
static int F_3 ( void * V_193 )
{
unsigned V_34 ;
T_1 V_12 ;
struct V_1 * V_2 = (struct V_1 * ) V_193 ;
for ( V_34 = 0 ; V_34 < V_2 -> V_53 ; V_34 ++ ) {
V_12 = F_4 ( V_202 ) & ( V_203 |
V_204 |
V_205 |
V_206 |
V_207 ) ;
if ( ! V_12 )
return 0 ;
F_8 ( 1 ) ;
}
return - V_208 ;
}
static int F_72 ( void * V_193 )
{
struct V_1 * V_2 = (struct V_1 * ) V_193 ;
struct V_3 V_4 ;
T_1 V_209 = 0 ;
T_1 V_12 = F_4 ( V_202 ) ;
if ( V_12 & V_207 )
V_209 = F_7 ( V_209 ,
V_210 , V_211 , 1 ) ;
if ( V_12 & ( V_203 | V_204 |
V_205 | V_206 ) ) {
if ( ! ( V_2 -> V_101 & V_166 ) )
V_209 = F_7 ( V_209 ,
V_210 , V_212 , 1 ) ;
}
if ( V_209 ) {
F_1 ( V_2 , & V_4 ) ;
if ( F_3 ( V_2 ) ) {
F_23 ( V_2 -> V_29 , L_23 ) ;
}
V_12 = F_4 ( V_213 ) ;
V_12 |= V_209 ;
F_38 ( V_2 -> V_29 , L_24 , V_12 ) ;
F_6 ( V_213 , V_12 ) ;
V_12 = F_4 ( V_213 ) ;
F_8 ( 50 ) ;
V_12 &= ~ V_209 ;
F_6 ( V_213 , V_12 ) ;
V_12 = F_4 ( V_213 ) ;
F_8 ( 50 ) ;
F_9 ( V_2 , & V_4 ) ;
F_8 ( 50 ) ;
}
return 0 ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_214 * V_215 ,
unsigned type ,
enum V_216 V_217 )
{
T_1 V_12 ;
T_1 V_218 = ( V_219 |
V_220 |
V_221 |
V_222 |
V_223 |
V_224 ) ;
switch ( V_217 ) {
case V_225 :
V_12 = F_4 ( V_144 ) ;
V_12 &= ~ V_218 ;
F_6 ( V_144 , V_12 ) ;
V_12 = F_4 ( V_104 ) ;
V_12 &= ~ V_218 ;
F_6 ( V_104 , V_12 ) ;
break;
case V_226 :
V_12 = F_4 ( V_144 ) ;
V_12 |= V_218 ;
F_6 ( V_144 , V_12 ) ;
V_12 = F_4 ( V_104 ) ;
V_12 |= V_218 ;
F_6 ( V_104 , V_12 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_214 * V_227 ,
struct V_228 * V_229 )
{
T_1 V_100 , V_169 ;
V_100 = F_4 ( V_230 ) ;
V_169 = F_4 ( V_231 ) ;
F_75 ( V_154 , 1 , ~ 1 ) ;
if ( ! V_100 && ! V_169 )
return 0 ;
if ( V_159 == V_232 )
F_35 ( V_2 , false ) ;
if ( F_76 () ) {
F_16 ( V_2 -> V_29 , L_25 ,
V_229 -> V_233 , V_229 -> V_234 ) ;
F_16 ( V_2 -> V_29 , L_26 ,
V_100 ) ;
F_16 ( V_2 -> V_29 , L_27 ,
V_169 ) ;
F_50 ( V_2 , V_169 , V_100 , 0 ) ;
}
return 0 ;
}
static int F_77 ( void * V_193 ,
enum V_235 V_217 )
{
return 0 ;
}
static int F_78 ( void * V_193 ,
enum V_236 V_217 )
{
return 0 ;
}
static void F_53 ( struct V_1 * V_2 )
{
if ( V_2 -> V_113 . V_237 == NULL )
V_2 -> V_113 . V_237 = & V_238 ;
}
static void F_54 ( struct V_1 * V_2 )
{
V_2 -> V_27 . V_196 . V_239 = 1 ;
V_2 -> V_27 . V_196 . V_240 = & V_241 ;
}
