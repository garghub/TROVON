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
F_12 ( L_1 ) ;
switch ( V_2 -> V_19 ) {
case V_20 :
V_16 = L_2 ;
break;
case V_21 :
V_16 = L_3 ;
break;
case V_22 :
V_16 = L_4 ;
break;
case V_23 :
V_16 = L_5 ;
break;
case V_24 :
V_16 = L_6 ;
break;
default: F_13 () ;
}
snprintf ( V_17 , sizeof( V_17 ) , L_7 , V_16 ) ;
V_18 = F_14 ( & V_2 -> V_25 . V_26 , V_17 , V_2 -> V_27 ) ;
if ( V_18 )
goto V_28;
V_18 = F_15 ( V_2 -> V_25 . V_26 ) ;
V_28:
if ( V_18 ) {
F_16 ( V_2 -> V_27 ,
L_8 ,
V_17 ) ;
F_17 ( V_2 -> V_25 . V_26 ) ;
V_2 -> V_25 . V_26 = NULL ;
}
return V_18 ;
}
static int F_18 ( struct V_1 * V_2 )
{
const T_2 * V_29 = NULL ;
T_1 V_30 ;
const T_2 * V_31 = NULL ;
int V_32 , V_33 , V_34 ;
const struct V_35 * V_36 ;
if ( ! V_2 -> V_25 . V_26 )
return - V_37 ;
V_36 = ( const struct V_35 * ) V_2 -> V_25 . V_26 -> V_38 ;
F_19 ( & V_36 -> V_39 ) ;
V_2 -> V_25 . V_40 = F_20 ( V_36 -> V_39 . V_41 ) ;
V_33 = F_20 ( V_36 -> V_42 ) / ( 4 * 2 ) ;
V_31 = ( const T_2 * )
( V_2 -> V_25 . V_26 -> V_38 + F_20 ( V_36 -> V_43 ) ) ;
V_34 = F_20 ( V_36 -> V_39 . V_44 ) / 4 ;
V_29 = ( const T_2 * )
( V_2 -> V_25 . V_26 -> V_38 + F_20 ( V_36 -> V_39 . V_45 ) ) ;
V_30 = F_4 ( V_46 ) & V_47 ;
if ( V_30 == 0 ) {
F_6 ( V_46 , 0x00000008 ) ;
F_6 ( V_46 , 0x00000010 ) ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ ) {
F_6 ( V_48 , F_21 ( V_31 ++ ) ) ;
F_6 ( V_49 , F_21 ( V_31 ++ ) ) ;
}
for ( V_32 = 0 ; V_32 < V_34 ; V_32 ++ ) {
F_6 ( V_50 , F_21 ( V_29 ++ ) ) ;
}
F_6 ( V_46 , 0x00000008 ) ;
F_6 ( V_46 , 0x00000004 ) ;
F_6 ( V_46 , 0x00000001 ) ;
for ( V_32 = 0 ; V_32 < V_2 -> V_51 ; V_32 ++ ) {
if ( F_4 ( V_52 ) & V_53 )
break;
F_8 ( 1 ) ;
}
for ( V_32 = 0 ; V_32 < V_2 -> V_51 ; V_32 ++ ) {
if ( F_4 ( V_52 ) & V_54 )
break;
F_8 ( 1 ) ;
}
}
return 0 ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_55 * V_25 )
{
if ( V_25 -> V_56 > 0xFFC0000000ULL ) {
F_23 ( V_2 -> V_27 , L_9 ) ;
V_25 -> V_57 = 0xFFC0000000ULL ;
V_25 -> V_56 = 0xFFC0000000ULL ;
}
F_24 ( V_2 , & V_2 -> V_25 , 0 ) ;
V_2 -> V_25 . V_58 = 0 ;
F_25 ( V_2 , V_25 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
T_1 V_12 ;
int V_32 , V_59 ;
for ( V_32 = 0 , V_59 = 0 ; V_32 < 32 ; V_32 ++ , V_59 += 0x6 ) {
F_6 ( ( 0xb05 + V_59 ) , 0x00000000 ) ;
F_6 ( ( 0xb06 + V_59 ) , 0x00000000 ) ;
F_6 ( ( 0xb07 + V_59 ) , 0x00000000 ) ;
F_6 ( ( 0xb08 + V_59 ) , 0x00000000 ) ;
F_6 ( ( 0xb09 + V_59 ) , 0x00000000 ) ;
}
F_6 ( V_60 , 0 ) ;
F_1 ( V_2 , & V_4 ) ;
if ( F_3 ( ( void * ) V_2 ) ) {
F_23 ( V_2 -> V_27 , L_10 ) ;
}
F_6 ( V_61 , V_62 ) ;
F_6 ( V_63 ,
V_2 -> V_25 . V_64 >> 12 ) ;
F_6 ( V_65 ,
V_2 -> V_25 . V_66 >> 12 ) ;
F_6 ( V_67 ,
V_2 -> V_68 . V_69 >> 12 ) ;
V_12 = ( ( V_2 -> V_25 . V_66 >> 24 ) & 0xFFFF ) << 16 ;
V_12 |= ( ( V_2 -> V_25 . V_64 >> 24 ) & 0xFFFF ) ;
F_6 ( V_70 , V_12 ) ;
F_6 ( V_71 , ( V_2 -> V_25 . V_64 >> 8 ) ) ;
F_6 ( V_72 , ( 2 << 7 ) | ( 1 << 30 ) ) ;
F_6 ( V_73 , 0x3FFFFFFF ) ;
F_6 ( V_74 , 0 ) ;
F_6 ( V_75 , 0x0FFFFFFF ) ;
F_6 ( V_76 , 0x0FFFFFFF ) ;
if ( F_3 ( ( void * ) V_2 ) ) {
F_23 ( V_2 -> V_27 , L_10 ) ;
}
F_9 ( V_2 , & V_4 ) ;
F_27 ( V_2 , false ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
T_1 V_12 ;
int V_77 , V_78 ;
V_12 = F_4 ( V_79 ) ;
if ( V_12 & V_80 ) {
V_77 = 16 ;
} else if ( V_12 & V_81 ) {
V_77 = 64 ;
} else {
V_77 = 32 ;
}
V_12 = F_4 ( V_82 ) ;
switch ( ( V_12 & V_83 ) >> V_84 ) {
case 0 :
default:
V_78 = 1 ;
break;
case 1 :
V_78 = 2 ;
break;
case 2 :
V_78 = 4 ;
break;
case 3 :
V_78 = 8 ;
break;
case 4 :
V_78 = 3 ;
break;
case 5 :
V_78 = 6 ;
break;
case 6 :
V_78 = 10 ;
break;
case 7 :
V_78 = 12 ;
break;
case 8 :
V_78 = 16 ;
break;
}
V_2 -> V_25 . V_85 = V_78 * V_77 ;
V_2 -> V_25 . V_86 = F_29 ( V_2 -> V_87 , 0 ) ;
V_2 -> V_25 . V_88 = F_30 ( V_2 -> V_87 , 0 ) ;
V_2 -> V_25 . V_56 = F_4 ( V_89 ) * 1024ULL * 1024ULL ;
V_2 -> V_25 . V_57 = F_4 ( V_89 ) * 1024ULL * 1024ULL ;
V_2 -> V_25 . V_90 = V_2 -> V_25 . V_88 ;
if ( V_91 == - 1 )
V_2 -> V_25 . V_92 = F_31 ( V_2 ) ;
else
V_2 -> V_25 . V_92 = ( V_93 ) V_91 << 20 ;
F_22 ( V_2 , & V_2 -> V_25 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_2 ,
T_3 V_94 )
{
F_6 ( V_95 , 0 ) ;
F_6 ( V_96 , 1 << V_94 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
void * V_97 ,
T_3 V_98 ,
V_93 V_99 ,
T_3 V_100 )
{
void T_4 * V_101 = ( void * ) V_97 ;
V_93 V_102 ;
V_102 = V_99 & 0xFFFFFFFFFFFFF000ULL ;
V_102 |= V_100 ;
F_34 ( V_102 , V_101 + ( V_98 * 8 ) ) ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 ,
bool V_102 )
{
T_1 V_12 ;
V_12 = F_4 ( V_103 ) ;
V_12 = F_7 ( V_12 , V_104 ,
V_105 , V_102 ) ;
V_12 = F_7 ( V_12 , V_104 ,
V_106 , V_102 ) ;
V_12 = F_7 ( V_12 , V_104 ,
V_107 , V_102 ) ;
V_12 = F_7 ( V_12 , V_104 ,
V_108 , V_102 ) ;
V_12 = F_7 ( V_12 , V_104 ,
V_109 , V_102 ) ;
V_12 = F_7 ( V_12 , V_104 ,
V_110 , V_102 ) ;
F_6 ( V_103 , V_12 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_111 , V_32 ;
if ( V_2 -> V_112 . V_113 == NULL ) {
F_16 ( V_2 -> V_27 , L_11 ) ;
return - V_37 ;
}
V_111 = F_37 ( V_2 ) ;
if ( V_111 )
return V_111 ;
F_6 ( V_114 ,
( 0xA << 7 ) |
V_115 |
V_116 |
V_117 |
V_118 |
V_119 ) ;
F_6 ( V_120 , V_121 |
V_122 |
V_123 |
V_124 |
F_38 ( 7 ) |
F_39 ( 1 ) ) ;
F_6 ( V_125 , V_126 | V_127 ) ;
F_6 ( V_128 , V_129 |
F_40 ( 4 ) |
F_41 ( 4 ) ) ;
F_6 ( V_130 , V_2 -> V_25 . V_131 >> 12 ) ;
F_6 ( V_132 , V_2 -> V_25 . V_133 >> 12 ) ;
F_6 ( V_134 , V_2 -> V_112 . V_135 >> 12 ) ;
F_6 ( V_136 ,
( T_1 ) ( V_2 -> V_137 . V_99 >> 12 ) ) ;
F_6 ( V_138 , 0 ) ;
F_6 ( V_139 , ( V_140 | F_42 ( 0 ) |
V_141 ) ) ;
F_6 ( 0x575 , 0 ) ;
F_6 ( 0x576 , 0 ) ;
F_6 ( 0x577 , 0 ) ;
F_6 ( V_142 , 0 ) ;
F_6 ( V_143 , V_2 -> V_144 . V_145 - 1 ) ;
for ( V_32 = 1 ; V_32 < 16 ; V_32 ++ ) {
if ( V_32 < 8 )
F_6 ( V_134 + V_32 ,
V_2 -> V_112 . V_135 >> 12 ) ;
else
F_6 ( V_146 + V_32 - 8 ,
V_2 -> V_112 . V_135 >> 12 ) ;
}
F_6 ( V_147 ,
( T_1 ) ( V_2 -> V_137 . V_99 >> 12 ) ) ;
F_6 ( V_148 , 4 ) ;
F_6 ( V_103 , V_140 | F_42 ( 1 ) |
F_43 ( V_149 - 9 ) |
V_150 |
V_141 |
V_151 |
V_152 |
V_153 |
V_154 |
V_155 |
V_156 |
V_157 |
V_158 |
V_159 |
V_160 ) ;
F_32 ( V_2 , 0 ) ;
F_44 ( V_2 -> V_27 , L_12 ,
( unsigned ) ( V_2 -> V_25 . V_92 >> 20 ) ,
( unsigned long long ) V_2 -> V_112 . V_135 ) ;
V_2 -> V_112 . V_161 = true ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
int V_111 ;
if ( V_2 -> V_112 . V_113 ) {
F_23 ( V_2 -> V_27 , L_13 ) ;
return 0 ;
}
V_111 = F_46 ( V_2 ) ;
if ( V_111 )
return V_111 ;
V_2 -> V_112 . V_162 = V_2 -> V_112 . V_163 * 8 ;
return F_47 ( V_2 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_6 ( V_139 , 0 ) ;
F_6 ( V_103 , 0 ) ;
F_6 ( V_114 , V_117 |
V_119 ) ;
F_6 ( V_120 , V_123 |
V_124 |
F_38 ( 7 ) |
F_39 ( 1 ) ) ;
F_6 ( V_125 , 0 ) ;
F_6 ( V_128 , V_129 |
F_41 ( 0 ) ) ;
F_49 ( V_2 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
V_2 -> V_144 . V_164 = V_165 ;
F_54 ( V_2 ) ;
if ( V_2 -> V_100 & V_166 ) {
T_5 V_12 = F_4 ( V_167 ) ;
V_12 <<= 22 ;
V_2 -> V_144 . V_168 = V_12 ;
} else
V_2 -> V_144 . V_168 = 0 ;
return 0 ;
}
static void F_55 ( struct V_1 * V_2 )
{
}
static void F_56 ( struct V_1 * V_2 ,
T_1 V_169 , T_1 V_99 , T_1 V_170 )
{
T_1 V_171 ;
T_1 V_94 = F_5 ( V_169 , V_172 , V_173 ) ;
T_1 V_174 = F_5 ( V_169 , V_172 ,
V_175 ) ;
char V_176 [ 5 ] = { V_170 >> 24 , ( V_170 >> 16 ) & 0xff ,
( V_170 >> 8 ) & 0xff , V_170 & 0xff , 0 } ;
V_171 = F_5 ( V_169 , V_172 ,
V_177 ) ;
F_16 ( V_2 -> V_27 , L_14 ,
V_174 , V_94 , V_99 ,
F_5 ( V_169 , V_172 ,
V_178 ) ?
L_15 : L_16 , V_176 , V_170 , V_171 ) ;
}
static int F_57 ( int V_179 )
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
static int F_58 ( void * V_193 )
{
struct V_1 * V_2 = (struct V_1 * ) V_193 ;
F_59 ( V_2 ) ;
F_60 ( V_2 ) ;
if ( V_2 -> V_100 & V_166 ) {
V_2 -> V_25 . V_194 = V_192 ;
} else {
T_1 V_12 = F_4 ( V_195 ) ;
V_12 &= V_196 ;
V_2 -> V_25 . V_194 = F_57 ( V_12 ) ;
}
return 0 ;
}
static int F_61 ( void * V_193 )
{
struct V_1 * V_2 = (struct V_1 * ) V_193 ;
return F_62 ( V_2 , & V_2 -> V_25 . V_197 , 0 ) ;
}
static int F_63 ( void * V_193 )
{
int V_111 ;
int V_198 ;
struct V_1 * V_2 = (struct V_1 * ) V_193 ;
V_111 = F_64 ( V_2 , 146 , & V_2 -> V_25 . V_197 ) ;
if ( V_111 )
return V_111 ;
V_111 = F_64 ( V_2 , 147 , & V_2 -> V_25 . V_197 ) ;
if ( V_111 )
return V_111 ;
V_2 -> V_144 . V_145 = V_199 << 18 ;
V_2 -> V_25 . V_200 = 0xffffffffffULL ;
V_2 -> V_201 = false ;
V_198 = V_2 -> V_201 ? 32 : 40 ;
V_111 = F_65 ( V_2 -> V_87 , F_66 ( V_198 ) ) ;
if ( V_111 ) {
V_2 -> V_201 = true ;
V_198 = 32 ;
F_23 ( V_2 -> V_27 , L_17 ) ;
}
V_111 = F_67 ( V_2 -> V_87 , F_66 ( V_198 ) ) ;
if ( V_111 ) {
F_67 ( V_2 -> V_87 , F_66 ( 32 ) ) ;
F_23 ( V_2 -> V_27 , L_18 ) ;
}
V_111 = F_11 ( V_2 ) ;
if ( V_111 ) {
F_16 ( V_2 -> V_27 , L_19 ) ;
return V_111 ;
}
V_111 = F_68 ( V_2 ) ;
if ( V_111 ) {
return V_111 ;
}
V_111 = F_28 ( V_2 ) ;
if ( V_111 )
return V_111 ;
V_111 = F_69 ( V_2 ) ;
if ( V_111 )
return V_111 ;
V_111 = F_45 ( V_2 ) ;
if ( V_111 )
return V_111 ;
if ( ! V_2 -> V_144 . V_202 ) {
V_111 = F_53 ( V_2 ) ;
if ( V_111 ) {
F_16 ( V_2 -> V_27 , L_20 , V_111 ) ;
return V_111 ;
}
V_2 -> V_144 . V_202 = true ;
}
return V_111 ;
}
static int F_70 ( void * V_193 )
{
struct V_1 * V_2 = (struct V_1 * ) V_193 ;
if ( V_2 -> V_144 . V_202 ) {
F_55 ( V_2 ) ;
V_2 -> V_144 . V_202 = false ;
}
F_50 ( V_2 ) ;
F_71 ( V_2 ) ;
F_72 ( V_2 ) ;
return 0 ;
}
static int F_73 ( void * V_193 )
{
int V_111 ;
struct V_1 * V_2 = (struct V_1 * ) V_193 ;
F_26 ( V_2 ) ;
if ( ! ( V_2 -> V_100 & V_166 ) ) {
V_111 = F_18 ( V_2 ) ;
if ( V_111 ) {
F_16 ( V_2 -> V_27 , L_21 ) ;
return V_111 ;
}
}
V_111 = F_36 ( V_2 ) ;
if ( V_111 )
return V_111 ;
return V_111 ;
}
static int F_74 ( void * V_193 )
{
struct V_1 * V_2 = (struct V_1 * ) V_193 ;
F_75 ( V_2 , & V_2 -> V_25 . V_197 , 0 ) ;
F_48 ( V_2 ) ;
return 0 ;
}
static int F_76 ( void * V_193 )
{
struct V_1 * V_2 = (struct V_1 * ) V_193 ;
if ( V_2 -> V_144 . V_202 ) {
F_55 ( V_2 ) ;
V_2 -> V_144 . V_202 = false ;
}
F_74 ( V_2 ) ;
return 0 ;
}
static int F_77 ( void * V_193 )
{
int V_111 ;
struct V_1 * V_2 = (struct V_1 * ) V_193 ;
V_111 = F_73 ( V_2 ) ;
if ( V_111 )
return V_111 ;
if ( ! V_2 -> V_144 . V_202 ) {
V_111 = F_53 ( V_2 ) ;
if ( V_111 ) {
F_16 ( V_2 -> V_27 , L_20 , V_111 ) ;
return V_111 ;
}
V_2 -> V_144 . V_202 = true ;
}
return V_111 ;
}
static bool F_78 ( void * V_193 )
{
struct V_1 * V_2 = (struct V_1 * ) V_193 ;
T_1 V_12 = F_4 ( V_203 ) ;
if ( V_12 & ( V_204 | V_205 |
V_206 | V_207 | V_208 ) )
return false ;
return true ;
}
static int F_3 ( void * V_193 )
{
unsigned V_32 ;
T_1 V_12 ;
struct V_1 * V_2 = (struct V_1 * ) V_193 ;
for ( V_32 = 0 ; V_32 < V_2 -> V_51 ; V_32 ++ ) {
V_12 = F_4 ( V_203 ) & ( V_204 |
V_205 |
V_206 |
V_207 |
V_208 ) ;
if ( ! V_12 )
return 0 ;
F_8 ( 1 ) ;
}
return - V_209 ;
}
static int F_79 ( void * V_193 )
{
struct V_1 * V_2 = (struct V_1 * ) V_193 ;
struct V_3 V_4 ;
T_1 V_210 = 0 ;
T_1 V_12 = F_4 ( V_203 ) ;
if ( V_12 & V_208 )
V_210 = F_7 ( V_210 ,
V_211 , V_212 , 1 ) ;
if ( V_12 & ( V_204 | V_205 |
V_206 | V_207 ) ) {
if ( ! ( V_2 -> V_100 & V_166 ) )
V_210 = F_7 ( V_210 ,
V_211 , V_213 , 1 ) ;
}
if ( V_210 ) {
F_1 ( V_2 , & V_4 ) ;
if ( F_3 ( V_2 ) ) {
F_23 ( V_2 -> V_27 , L_22 ) ;
}
V_12 = F_4 ( V_214 ) ;
V_12 |= V_210 ;
F_44 ( V_2 -> V_27 , L_23 , V_12 ) ;
F_6 ( V_214 , V_12 ) ;
V_12 = F_4 ( V_214 ) ;
F_8 ( 50 ) ;
V_12 &= ~ V_210 ;
F_6 ( V_214 , V_12 ) ;
V_12 = F_4 ( V_214 ) ;
F_8 ( 50 ) ;
F_9 ( V_2 , & V_4 ) ;
F_8 ( 50 ) ;
}
return 0 ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_215 * V_216 ,
unsigned type ,
enum V_217 V_218 )
{
T_1 V_12 ;
T_1 V_219 = ( V_220 |
V_221 |
V_222 |
V_223 |
V_224 |
V_225 ) ;
switch ( V_218 ) {
case V_226 :
V_12 = F_4 ( V_139 ) ;
V_12 &= ~ V_219 ;
F_6 ( V_139 , V_12 ) ;
V_12 = F_4 ( V_103 ) ;
V_12 &= ~ V_219 ;
F_6 ( V_103 , V_12 ) ;
break;
case V_227 :
V_12 = F_4 ( V_139 ) ;
V_12 |= V_219 ;
F_6 ( V_139 , V_12 ) ;
V_12 = F_4 ( V_103 ) ;
V_12 |= V_219 ;
F_6 ( V_103 , V_12 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_215 * V_228 ,
struct V_229 * V_230 )
{
T_1 V_99 , V_169 ;
V_99 = F_4 ( V_231 ) ;
V_169 = F_4 ( V_232 ) ;
F_82 ( V_148 , 1 , ~ 1 ) ;
if ( ! V_99 && ! V_169 )
return 0 ;
if ( V_233 == V_234 )
F_35 ( V_2 , false ) ;
F_16 ( V_2 -> V_27 , L_24 ,
V_230 -> V_235 , V_230 -> V_236 ) ;
F_16 ( V_2 -> V_27 , L_25 ,
V_99 ) ;
F_16 ( V_2 -> V_27 , L_26 ,
V_169 ) ;
F_56 ( V_2 , V_169 , V_99 , 0 ) ;
return 0 ;
}
static int F_83 ( void * V_193 ,
enum V_237 V_218 )
{
return 0 ;
}
static int F_84 ( void * V_193 ,
enum V_238 V_218 )
{
return 0 ;
}
static void F_59 ( struct V_1 * V_2 )
{
if ( V_2 -> V_112 . V_239 == NULL )
V_2 -> V_112 . V_239 = & V_240 ;
}
static void F_60 ( struct V_1 * V_2 )
{
V_2 -> V_25 . V_197 . V_241 = 1 ;
V_2 -> V_25 . V_197 . V_242 = & V_243 ;
}
