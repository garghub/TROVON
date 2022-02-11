static char * F_1 ( unsigned int V_1 , char * V_2 [] , int V_3 )
{
int V_4 , V_5 ;
static char V_6 [ 128 ] ;
for ( V_4 = 0 , V_5 = 0 ; V_4 < V_3 ; V_4 ++ ) {
if ( V_1 & ( 1U << V_4 ) && V_2 [ V_4 ] )
V_5 += snprintf ( V_6 + V_5 , sizeof( V_6 ) - V_5 , L_1 ,
V_2 [ V_4 ] ) ;
}
V_6 [ V_5 ] = '\0' ;
return V_6 ;
}
static const char * F_2 ( unsigned int V_7 )
{
static char * V_2 [ 16 ] = {
[ V_8 ] = L_2 ,
[ V_9 ] = L_3 ,
[ V_10 ] = L_4 ,
[ V_11 ] = L_5 ,
[ V_12 ] = L_6 ,
[ V_13 ] = L_7 ,
[ V_14 ] = L_8 ,
[ V_15 ] = L_9 ,
[ V_16 ] = L_10 ,
} ;
if ( V_7 == - 1 )
return L_11 ;
V_7 &= 0xf ;
if ( V_2 [ V_7 ] )
return V_2 [ V_7 ] ;
else
return L_11 ;
}
static void F_3 ( struct V_17 * V_18 ,
struct V_19 * V_20 , T_1 V_21 ,
struct V_22 * V_23 )
{
int V_4 ;
struct V_24 * V_25 = V_23 -> V_26 , * V_27 ;
struct V_28 * V_29 ;
for ( V_4 = 0 ; V_4 < V_23 -> V_30 ; V_4 ++ ) {
V_27 = & V_25 [ V_4 ] ;
if ( V_27 -> V_21 == V_21 ) {
V_29 = V_27 -> V_29 ;
F_4 ( V_18 ,
L_12 ,
V_29 -> V_31 . V_32 , V_29 -> V_31 . V_33 + V_27 -> V_33 ,
V_29 -> V_31 . V_34 ) ;
if ( V_27 -> V_35 & V_36 )
F_4 ( V_18 ,
L_13
L_14 ,
F_5 ( V_29 ) ,
F_6 ( V_29 ) ? L_15 : L_16 ,
F_7 ( V_29 ) ,
F_8 ( V_29 ) ) ;
}
}
}
static void F_9 ( struct V_17 * V_18 ,
struct V_19 * V_20 , T_1 V_21 )
{
int type ;
struct V_37 * V_38 ;
F_10 (cpcm, &codec->pcm_list_head, list) {
for ( type = 0 ; type < 2 ; type ++ ) {
if ( V_38 -> V_39 [ type ] . V_21 != V_21 || V_38 -> V_40 == NULL )
continue;
F_4 ( V_18 , L_17
L_18 ,
V_38 -> V_32 ,
V_41 [ V_38 -> V_42 ] ,
V_38 -> V_40 -> V_34 ) ;
}
}
}
static void F_11 ( struct V_17 * V_18 ,
struct V_19 * V_20 , T_1 V_21 , int V_43 )
{
unsigned int V_44 ;
V_44 = F_12 ( V_20 , V_21 , V_43 == V_45 ?
V_46 : V_47 ) ;
if ( V_44 == - 1 || V_44 == 0 ) {
F_4 ( V_18 , L_19 ) ;
return;
}
F_4 ( V_18 , L_20
L_21 ,
V_44 & V_48 ,
( V_44 & V_49 ) >> V_50 ,
( V_44 & V_51 ) >> V_52 ,
( V_44 & V_53 ) >> V_54 ) ;
}
static bool F_13 ( struct V_19 * V_20 , T_1 V_21 ,
int V_43 , unsigned int V_55 , int V_56 )
{
T_1 V_57 ;
if ( V_55 & V_58 )
return true ;
if ( V_56 != 1 || V_43 != V_59 ||
F_14 ( V_55 ) != V_10 )
return false ;
if ( F_15 ( V_20 , V_21 , & V_57 , 1 ) < 0 )
return false ;
V_55 = F_16 ( V_20 , V_57 , V_60 ) ;
return ! ! ( V_55 & V_58 ) ;
}
static void F_17 ( struct V_17 * V_18 ,
struct V_19 * V_20 , T_1 V_21 ,
int V_43 , unsigned int V_55 , int V_56 )
{
unsigned int V_61 ;
bool V_62 ;
int V_4 ;
V_62 = F_13 ( V_20 , V_21 , V_43 , V_55 , V_56 ) ;
V_43 = V_43 == V_45 ? V_63 : V_64 ;
for ( V_4 = 0 ; V_4 < V_56 ; V_4 ++ ) {
F_4 ( V_18 , L_22 ) ;
V_61 = F_18 ( V_20 , V_21 , 0 ,
V_65 ,
V_66 | V_43 | V_4 ) ;
F_4 ( V_18 , L_23 , V_61 ) ;
if ( V_62 ) {
V_61 = F_18 ( V_20 , V_21 , 0 ,
V_65 ,
V_67 | V_43 | V_4 ) ;
F_4 ( V_18 , L_24 , V_61 ) ;
}
F_4 ( V_18 , L_25 ) ;
}
F_4 ( V_18 , L_26 ) ;
}
static void F_19 ( struct V_17 * V_18 , unsigned int V_40 )
{
static unsigned int V_68 [] = {
8000 , 11025 , 16000 , 22050 , 32000 , 44100 , 48000 , 88200 ,
96000 , 176400 , 192000 , 384000
} ;
int V_4 ;
V_40 &= V_69 ;
F_4 ( V_18 , L_27 , V_40 ) ;
for ( V_4 = 0 ; V_4 < F_20 ( V_68 ) ; V_4 ++ )
if ( V_40 & ( 1 << V_4 ) )
F_4 ( V_18 , L_28 , V_68 [ V_4 ] ) ;
F_4 ( V_18 , L_26 ) ;
}
static void F_21 ( struct V_17 * V_18 , unsigned int V_40 )
{
char V_6 [ V_70 ] ;
F_4 ( V_18 , L_29 , ( V_40 >> 16 ) & 0xff ) ;
F_22 ( V_40 , V_6 , sizeof( V_6 ) ) ;
F_4 ( V_18 , L_30 , V_6 ) ;
}
static void F_23 ( struct V_17 * V_18 ,
unsigned int V_71 )
{
F_4 ( V_18 , L_31 , V_71 & 0xf ) ;
if ( V_71 & V_72 )
F_4 ( V_18 , L_32 ) ;
if ( V_71 & V_73 )
F_4 ( V_18 , L_33 ) ;
if ( V_71 & V_74 )
F_4 ( V_18 , L_34 ) ;
F_4 ( V_18 , L_26 ) ;
}
static void F_24 ( struct V_17 * V_18 ,
struct V_19 * V_20 , T_1 V_21 )
{
unsigned int V_40 = F_12 ( V_20 , V_21 , V_75 ) ;
unsigned int V_39 = F_12 ( V_20 , V_21 , V_76 ) ;
if ( V_40 == - 1 || V_39 == - 1 ) {
F_4 ( V_18 , L_19 ) ;
return;
}
F_19 ( V_18 , V_40 ) ;
F_21 ( V_18 , V_40 ) ;
F_23 ( V_18 , V_39 ) ;
}
static const char * F_25 ( T_2 V_77 )
{
static char * V_2 [ 16 ] = {
L_35 , L_36 , L_37 , L_38 ,
L_39 , L_40 , L_41 , L_42 ,
L_43 , L_44 , L_45 , L_46 ,
NULL , NULL , NULL , L_47
} ;
V_77 = ( V_77 & V_78 ) >> V_79 ;
if ( V_2 [ V_77 ] )
return V_2 [ V_77 ] ;
else
return L_48 ;
}
static const char * F_26 ( T_2 V_77 )
{
static char * V_2 [ 16 ] = {
L_35 , L_49 , L_50 , L_51 ,
L_52 , L_53 , L_54 , L_55 ,
L_56 , L_57 , NULL , NULL ,
NULL , NULL , L_58 , L_47 ,
} ;
V_77 = ( V_77 & V_80 ) >> V_81 ;
if ( V_2 [ V_77 ] )
return V_2 [ V_77 ] ;
else
return L_48 ;
}
static void F_27 ( struct V_17 * V_18 ,
struct V_19 * V_20 , T_1 V_21 ,
int * V_82 )
{
static char * V_83 [ 4 ] = { L_59 , L_60 , L_61 , L_62 } ;
unsigned int V_44 , V_61 ;
V_44 = F_12 ( V_20 , V_21 , V_84 ) ;
F_4 ( V_18 , L_63 , V_44 ) ;
if ( V_44 & V_85 )
F_4 ( V_18 , L_64 ) ;
if ( V_44 & V_86 )
F_4 ( V_18 , L_65 ) ;
if ( V_44 & V_87 )
F_4 ( V_18 , L_66 ) ;
if ( V_44 & V_88 )
F_4 ( V_18 , L_67 ) ;
if ( V_44 & V_89 )
F_4 ( V_18 , L_68 ) ;
if ( V_44 & V_90 )
F_4 ( V_18 , L_69 ) ;
if ( V_44 & V_91 ) {
if ( ( V_20 -> V_92 . V_93 >> 16 ) == 0x10ec )
F_4 ( V_18 , L_70 ) ;
else {
if ( V_44 & V_94 )
F_4 ( V_18 , L_71 ) ;
F_4 ( V_18 , L_72 ) ;
}
}
if ( V_44 & V_95 )
F_4 ( V_18 , L_73 ) ;
if ( V_44 & V_96 )
F_4 ( V_18 , L_74 ) ;
if ( V_44 & V_97 )
F_4 ( V_18 , L_75 ) ;
F_4 ( V_18 , L_26 ) ;
if ( V_44 & V_98 ) {
unsigned int V_99 =
( V_44 & V_98 ) >> V_100 ;
F_4 ( V_18 , L_76 ) ;
if ( V_99 & V_101 )
F_4 ( V_18 , L_77 ) ;
if ( V_99 & V_102 )
F_4 ( V_18 , L_78 ) ;
if ( V_99 & V_103 )
F_4 ( V_18 , L_79 ) ;
if ( V_99 & V_104 )
F_4 ( V_18 , L_80 ) ;
if ( V_99 & V_105 )
F_4 ( V_18 , L_81 ) ;
F_4 ( V_18 , L_26 ) ;
* V_82 = 1 ;
} else
* V_82 = 0 ;
if ( V_44 & V_88 ) {
V_61 = F_18 ( V_20 , V_21 , 0 ,
V_106 , 0 ) ;
F_4 ( V_18 , L_82 , V_61 ) ;
if ( V_61 & V_107 )
F_4 ( V_18 , L_83 ) ;
if ( V_61 & V_108 )
F_4 ( V_18 , L_67 ) ;
if ( V_61 & V_109 )
F_4 ( V_18 , L_70 ) ;
F_4 ( V_18 , L_26 ) ;
}
V_44 = F_18 ( V_20 , V_21 , 0 , V_110 , 0 ) ;
F_4 ( V_18 , L_84 , V_44 ,
V_83 [ ( V_44 & V_111 ) >> V_112 ] ,
F_28 ( V_44 ) ,
F_29 ( V_44 ) ,
F_30 ( V_44 ) ) ;
F_4 ( V_18 , L_85 ,
F_25 ( V_44 ) ,
F_26 ( V_44 ) ) ;
F_4 ( V_18 , L_86 ,
( V_44 & V_113 ) >> V_114 ,
V_44 & V_115 ) ;
if ( ( ( V_44 & V_116 ) >> V_117 ) &
V_118 ) {
F_4 ( V_18 , L_87 ) ;
}
}
static void F_31 ( struct V_17 * V_18 ,
struct V_19 * V_20 , T_1 V_21 ,
int V_82 )
{
unsigned int V_119 ;
V_119 = F_18 ( V_20 , V_21 , 0 ,
V_120 , 0 ) ;
F_4 ( V_18 , L_88 , V_119 ) ;
if ( V_119 & V_121 )
F_4 ( V_18 , L_64 ) ;
if ( V_119 & V_122 )
F_4 ( V_18 , L_65 ) ;
if ( V_119 & V_123 )
F_4 ( V_18 , L_66 ) ;
if ( V_82 ) {
int V_99 = V_119 & V_124 ;
switch ( V_99 ) {
case V_125 :
F_4 ( V_18 , L_89 ) ;
break;
case V_126 :
F_4 ( V_18 , L_90 ) ;
break;
case V_127 :
F_4 ( V_18 , L_91 ) ;
break;
case V_128 :
F_4 ( V_18 , L_92 ) ;
break;
case V_129 :
F_4 ( V_18 , L_93 ) ;
break;
}
}
F_4 ( V_18 , L_26 ) ;
}
static void F_32 ( struct V_17 * V_18 ,
struct V_19 * V_20 , T_1 V_21 )
{
unsigned int V_130 = F_12 ( V_20 , V_21 , V_131 ) ;
F_4 ( V_18 , L_94 ,
( V_130 >> 7 ) & 1 , V_130 & 0x7f ) ;
V_130 = F_18 ( V_20 , V_21 , 0 ,
V_132 , 0 ) ;
F_4 ( V_18 , L_95 ,
( V_130 >> 7 ) & 1 , V_130 & 0x7f ) ;
}
static void F_33 ( struct V_17 * V_18 ,
struct V_19 * V_20 , T_1 V_21 ,
unsigned int V_133 )
{
int V_134 = F_18 ( V_20 , V_21 , 0 , V_135 , 0 ) ;
F_4 ( V_18 ,
L_96 ,
( V_134 & V_136 ) >> V_137 ,
V_134 & V_138 ) ;
if ( V_133 == V_9 && ( V_134 & V_138 ) == 0 ) {
int V_139 = F_18 ( V_20 , V_21 , 0 ,
V_140 , 0 ) ;
F_4 ( V_18 , L_97 ,
V_139 & V_141 ) ;
}
}
static void F_34 ( struct V_17 * V_18 ,
struct V_19 * V_20 , T_1 V_21 )
{
unsigned int V_142 = F_18 ( V_20 , V_21 , 0 ,
V_143 , 0 ) ;
unsigned char V_144 = V_142 >> 8 ;
unsigned char V_145 = V_142 >> 16 ;
F_4 ( V_18 , L_98 ) ;
if ( V_142 & V_146 )
F_4 ( V_18 , L_99 ) ;
if ( V_142 & V_147 )
F_4 ( V_18 , L_100 ) ;
if ( V_142 & V_148 )
F_4 ( V_18 , L_101 ) ;
if ( V_142 & V_149 )
F_4 ( V_18 , L_102 ) ;
if ( V_142 & V_150 )
F_4 ( V_18 , L_103 ) ;
if ( V_142 & V_151 )
F_4 ( V_18 , L_104 ) ;
if ( V_142 & V_152 )
F_4 ( V_18 , L_105 ) ;
if ( V_142 & V_153 )
F_4 ( V_18 , L_106 ) ;
if ( V_145 & V_154 )
F_4 ( V_18 , L_107 ) ;
F_4 ( V_18 , L_26 ) ;
F_4 ( V_18 , L_108 ,
V_144 & V_155 ) ;
F_4 ( V_18 , L_109 ,
V_145 & V_156 ) ;
}
static const char * F_35 ( T_2 V_157 )
{
static const char * const V_6 [] = {
L_110 , L_111 , L_112 , L_113 , L_114
} ;
if ( V_157 < F_20 ( V_6 ) )
return V_6 [ V_157 ] ;
return L_48 ;
}
static void F_36 ( struct V_17 * V_18 ,
struct V_19 * V_20 , T_1 V_21 )
{
static char * V_2 [] = {
[ F_37 ( V_158 ) ] = L_110 ,
[ F_37 ( V_159 ) ] = L_111 ,
[ F_37 ( V_160 ) ] = L_112 ,
[ F_37 ( V_161 ) ] = L_113 ,
[ F_37 ( V_162 ) ] = L_114 ,
[ F_37 ( V_163 ) ] = L_115 ,
[ F_37 ( V_164 ) ] = L_116 ,
[ F_37 ( V_165 ) ] = L_117 ,
} ;
int V_166 = F_12 ( V_20 , V_21 , V_167 ) ;
int V_168 = F_18 ( V_20 , V_21 , 0 ,
V_169 , 0 ) ;
if ( V_166 != - 1 )
F_4 ( V_18 , L_118 ,
F_1 ( V_166 , V_2 , F_20 ( V_2 ) ) ) ;
F_4 ( V_18 , L_119 ,
F_35 ( V_168 & V_170 ) ,
F_35 ( ( V_168 & V_171 ) >>
V_172 ) ) ;
if ( V_168 & V_173 )
F_4 ( V_18 , L_120 ) ;
if ( V_168 & V_174 )
F_4 ( V_18 , L_121 ) ;
if ( V_168 & V_175 )
F_4 ( V_18 , L_122 ) ;
F_4 ( V_18 , L_26 ) ;
}
static void F_38 ( struct V_17 * V_18 ,
struct V_19 * V_20 , T_1 V_21 )
{
int V_176 = F_18 ( V_20 , V_21 , 0 ,
V_177 , 0 ) ;
F_4 ( V_18 ,
L_123 ,
V_176 & V_178 ,
( V_176 & V_179 ) ? 1 : 0 ) ;
}
static inline bool F_39 ( struct V_19 * V_20 )
{
switch ( V_180 ) {
case 0 : return false ;
case 1 : return true ;
default: return V_20 -> V_180 ;
}
}
static void F_40 ( struct V_17 * V_18 ,
struct V_19 * V_20 , T_1 V_21 )
{
unsigned int V_4 , V_181 , V_182 ;
unsigned int V_183 = F_12 ( V_20 , V_21 , V_184 ) ;
V_181 = ( V_183 & V_185 ) >> V_186 ;
F_4 ( V_18 , L_124 ,
V_183 & V_187 , V_181 ) ;
if ( ! F_39 ( V_20 ) )
return;
V_182 = F_18 ( V_20 , V_21 , 0 , V_188 , 0 ) ;
for ( V_4 = 0 ; V_4 < V_181 ; V_4 ++ ) {
unsigned int V_61 ;
F_41 ( V_20 , V_21 , 0 , V_189 , V_4 ) ;
V_61 = F_18 ( V_20 , V_21 , 0 , V_190 ,
0 ) ;
F_4 ( V_18 , L_125 , V_4 , V_61 ) ;
}
F_41 ( V_20 , V_21 , 0 , V_189 , V_182 ) ;
}
static void F_42 ( struct V_17 * V_18 ,
struct V_19 * V_20 , T_1 V_21 ,
unsigned int V_133 , T_1 * V_57 ,
int V_191 )
{
int V_192 , V_193 = - 1 ;
const T_1 * V_26 ;
int V_194 ;
if ( V_191 > 1 &&
V_133 != V_10 &&
V_133 != V_14 &&
V_133 != V_13 )
V_193 = F_18 ( V_20 , V_21 , 0 ,
V_195 , 0 ) ;
F_4 ( V_18 , L_126 , V_191 ) ;
if ( V_191 > 0 ) {
F_4 ( V_18 , L_127 ) ;
for ( V_192 = 0 ; V_192 < V_191 ; V_192 ++ ) {
F_4 ( V_18 , L_24 , V_57 [ V_192 ] ) ;
if ( V_192 == V_193 )
F_4 ( V_18 , L_128 ) ;
}
F_4 ( V_18 , L_26 ) ;
}
V_194 = F_43 ( V_20 , V_21 , & V_26 ) ;
if ( V_194 >= 0 && ( V_194 != V_191 ||
memcmp ( V_26 , V_57 , V_191 ) != 0 ) ) {
F_4 ( V_18 , L_129 , V_194 ) ;
if ( V_194 > 0 ) {
F_4 ( V_18 , L_127 ) ;
for ( V_192 = 0 ; V_192 < V_194 ; V_192 ++ )
F_4 ( V_18 , L_24 , V_26 [ V_192 ] ) ;
F_4 ( V_18 , L_26 ) ;
}
}
}
static void F_44 ( struct V_17 * V_18 ,
struct V_19 * V_20 , T_1 V_21 )
{
unsigned int V_196 =
F_12 ( V_20 , V_20 -> V_92 . V_197 , V_198 ) ;
unsigned int V_199 , V_200 , V_201 , V_176 , V_202 , V_203 ;
int V_4 , V_204 ;
F_4 ( V_18 , L_130
L_131 ,
V_196 & V_205 ,
( V_196 & V_206 ) >> V_207 ,
( V_196 & V_208 ) >> V_209 ,
( V_196 & V_210 ) ? 1 : 0 ,
( V_196 & V_211 ) ? 1 : 0 ) ;
V_204 = V_196 & V_205 ;
if ( ! V_204 || V_204 > 8 )
return;
V_199 = F_18 ( V_20 , V_21 , 0 ,
V_212 , 0 ) ;
V_200 = F_18 ( V_20 , V_21 , 0 ,
V_213 , 0 ) ;
V_201 = F_18 ( V_20 , V_21 , 0 ,
V_214 , 0 ) ;
V_176 = F_18 ( V_20 , V_21 , 0 ,
V_215 , 0 ) ;
V_202 = F_18 ( V_20 , V_21 , 0 ,
V_216 , 0 ) ;
V_203 = F_18 ( V_20 , V_21 , 0 ,
V_217 , 0 ) ;
for ( V_4 = 0 ; V_4 < V_204 ; ++ V_4 )
F_4 ( V_18 ,
L_132
L_133 , V_4 ,
( V_199 & ( 1 << V_4 ) ) ? 1 : 0 ,
( V_200 & ( 1 << V_4 ) ) ? 1 : 0 ,
( V_201 & ( 1 << V_4 ) ) ? 1 : 0 ,
( V_202 & ( 1 << V_4 ) ) ? 1 : 0 ,
( V_203 & ( 1 << V_4 ) ) ? 1 : 0 ,
( V_176 & ( 1 << V_4 ) ) ? 1 : 0 ) ;
F_3 ( V_18 , V_20 , V_21 , & V_20 -> V_218 ) ;
F_3 ( V_18 , V_20 , V_21 , & V_20 -> V_219 ) ;
}
static void F_45 ( struct V_17 * V_18 ,
struct V_19 * V_20 , T_1 V_21 )
{
int V_4 , V_193 = - 1 ;
T_3 V_220 [ V_221 ] ;
int V_222 ;
V_222 = F_46 ( V_20 , V_21 , V_220 ,
V_221 ) ;
F_4 ( V_18 , L_134 , V_222 ) ;
if ( V_222 <= 0 )
return;
V_193 = F_18 ( V_20 , V_21 , 0 ,
V_223 , 0 ) ;
for ( V_4 = 0 ; V_4 < V_222 ; V_4 ++ ) {
if ( V_4 == V_193 )
F_4 ( V_18 , L_135 ) ;
else
F_4 ( V_18 , L_136 ) ;
F_4 ( V_18 ,
L_137 , V_4 ,
! ! ( V_220 [ V_4 ] & V_224 ) ,
! ! ( V_220 [ V_4 ] & V_225 ) ,
! ! ( V_220 [ V_4 ] & V_226 ) ) ;
}
}
static void F_47 ( struct V_227 * V_20 ,
struct V_17 * V_18 )
{
F_4 ( V_18 , L_138 ) ;
if ( V_20 -> V_228 && V_20 -> V_229 )
F_4 ( V_18 , L_139 ,
V_20 -> V_228 , V_20 -> V_229 ) ;
else
F_4 ( V_18 , L_140 ) ;
F_4 ( V_18 , L_141 , V_20 -> V_230 ) ;
if ( V_20 -> V_197 )
F_4 ( V_18 , L_142 ,
V_20 -> V_231 , V_20 -> V_232 ) ;
if ( V_20 -> V_233 )
F_4 ( V_18 , L_143 ,
V_20 -> V_234 , V_20 -> V_235 ) ;
F_4 ( V_18 , L_144 , V_20 -> V_93 ) ;
F_4 ( V_18 , L_145 , V_20 -> V_236 ) ;
F_4 ( V_18 , L_146 , V_20 -> V_237 ) ;
if ( V_20 -> V_233 )
F_4 ( V_18 , L_147 , V_20 -> V_233 ) ;
else
F_4 ( V_18 , L_148 ) ;
}
static void F_48 ( struct V_238 * V_239 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 = V_239 -> V_240 ;
T_1 V_21 , V_241 ;
int V_4 , V_242 ;
F_47 ( & V_20 -> V_92 , V_18 ) ;
V_241 = V_20 -> V_92 . V_197 ;
if ( ! V_241 )
return;
F_49 ( V_20 ) ;
F_4 ( V_18 , L_149 ) ;
F_24 ( V_18 , V_20 , V_241 ) ;
F_4 ( V_18 , L_150 ) ;
F_11 ( V_18 , V_20 , V_241 , V_59 ) ;
F_4 ( V_18 , L_151 ) ;
F_11 ( V_18 , V_20 , V_241 , V_45 ) ;
F_4 ( V_18 , L_152 , V_241 ) ;
F_36 ( V_18 , V_20 , V_241 ) ;
V_242 = F_50 ( V_20 , V_241 , & V_21 ) ;
if ( ! V_21 || V_242 < 0 ) {
F_4 ( V_18 , L_153 ) ;
F_51 ( V_20 ) ;
return;
}
F_44 ( V_18 , V_20 , V_241 ) ;
if ( V_20 -> V_243 )
V_20 -> V_243 ( V_18 , V_20 , V_241 ) ;
for ( V_4 = 0 ; V_4 < V_242 ; V_4 ++ , V_21 ++ ) {
unsigned int V_244 =
F_12 ( V_20 , V_21 , V_60 ) ;
unsigned int V_133 = F_14 ( V_244 ) ;
T_1 * V_57 = NULL ;
int V_191 = 0 ;
F_4 ( V_18 , L_154 , V_21 ,
F_2 ( V_133 ) , V_244 ) ;
if ( V_244 & V_58 ) {
unsigned int V_245 = F_52 ( V_244 ) ;
if ( V_245 == 2 )
F_4 ( V_18 , L_155 ) ;
else
F_4 ( V_18 , L_156 , V_245 ) ;
} else
F_4 ( V_18 , L_157 ) ;
if ( V_244 & V_246 )
F_4 ( V_18 , L_158 ) ;
if ( V_244 & V_247 )
F_4 ( V_18 , L_159 ) ;
if ( V_244 & V_248 )
F_4 ( V_18 , L_160 ) ;
if ( V_244 & V_249 )
F_4 ( V_18 , L_161 ) ;
if ( V_244 & V_250 )
F_4 ( V_18 , L_70 ) ;
if ( V_244 & V_251 )
F_4 ( V_18 , L_162 ) ;
F_4 ( V_18 , L_26 ) ;
F_3 ( V_18 , V_20 , V_21 , & V_20 -> V_218 ) ;
F_3 ( V_18 , V_20 , V_21 , & V_20 -> V_219 ) ;
F_9 ( V_18 , V_20 , V_21 ) ;
if ( V_133 == V_14 )
V_244 |= V_252 ;
if ( V_244 & V_252 ) {
V_191 = F_53 ( V_20 , V_21 ) ;
if ( V_191 > 0 ) {
V_57 = F_54 ( sizeof( T_1 ) * V_191 ,
V_253 ) ;
if ( ! V_57 )
return;
if ( F_15 ( V_20 , V_21 , V_57 ,
V_191 ) < 0 )
V_191 = 0 ;
}
}
if ( V_244 & V_247 ) {
F_4 ( V_18 , L_163 ) ;
F_11 ( V_18 , V_20 , V_21 , V_59 ) ;
F_4 ( V_18 , L_164 ) ;
if ( V_133 == V_12 ||
( V_20 -> V_254 &&
V_133 == V_9 ) )
F_17 ( V_18 , V_20 , V_21 , V_59 ,
V_244 , 1 ) ;
else
F_17 ( V_18 , V_20 , V_21 , V_59 ,
V_244 , V_191 ) ;
}
if ( V_244 & V_248 ) {
F_4 ( V_18 , L_165 ) ;
F_11 ( V_18 , V_20 , V_21 , V_45 ) ;
F_4 ( V_18 , L_166 ) ;
if ( V_133 == V_12 &&
V_20 -> V_255 )
F_17 ( V_18 , V_20 , V_21 , V_45 ,
V_244 , V_191 ) ;
else
F_17 ( V_18 , V_20 , V_21 , V_45 ,
V_244 , 1 ) ;
}
switch ( V_133 ) {
case V_12 : {
int V_82 ;
F_27 ( V_18 , V_20 , V_21 , & V_82 ) ;
F_31 ( V_18 , V_20 , V_21 , V_82 ) ;
break;
}
case V_14 :
F_32 ( V_18 , V_20 , V_21 ) ;
break;
case V_8 :
case V_9 :
F_33 ( V_18 , V_20 , V_21 , V_133 ) ;
if ( V_244 & V_246 )
F_34 ( V_18 , V_20 , V_21 ) ;
if ( V_244 & V_256 ) {
F_4 ( V_18 , L_167 ) ;
F_24 ( V_18 , V_20 , V_21 ) ;
}
break;
}
if ( V_244 & V_257 )
F_38 ( V_18 , V_20 , V_21 ) ;
if ( V_244 & V_258 )
F_36 ( V_18 , V_20 , V_21 ) ;
if ( V_244 & V_259 )
F_4 ( V_18 , L_168 ,
( V_244 & V_259 ) >>
V_260 ) ;
if ( V_133 == V_12 && V_20 -> V_261 )
F_45 ( V_18 , V_20 , V_21 ) ;
if ( V_244 & V_252 )
F_42 ( V_18 , V_20 , V_21 , V_133 ,
V_57 , V_191 ) ;
if ( V_244 & V_262 )
F_40 ( V_18 , V_20 , V_21 ) ;
if ( V_20 -> V_243 )
V_20 -> V_243 ( V_18 , V_20 , V_21 ) ;
F_55 ( V_57 ) ;
}
F_51 ( V_20 ) ;
}
int F_56 ( struct V_19 * V_20 )
{
char V_32 [ 32 ] ;
struct V_238 * V_239 ;
int V_263 ;
snprintf ( V_32 , sizeof( V_32 ) , L_169 , V_20 -> V_92 . V_230 ) ;
V_263 = F_57 ( V_20 -> V_264 , V_32 , & V_239 ) ;
if ( V_263 < 0 )
return V_263 ;
F_58 ( V_239 , V_20 , F_48 ) ;
return 0 ;
}
