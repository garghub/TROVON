static const char * F_1 ( unsigned int V_1 )
{
static const char * const V_2 [ 16 ] = {
[ V_3 ] = L_1 ,
[ V_4 ] = L_2 ,
[ V_5 ] = L_3 ,
[ V_6 ] = L_4 ,
[ V_7 ] = L_5 ,
[ V_8 ] = L_6 ,
[ V_9 ] = L_7 ,
[ V_10 ] = L_8 ,
[ V_11 ] = L_9 ,
} ;
if ( V_1 == - 1 )
return L_10 ;
V_1 &= 0xf ;
if ( V_2 [ V_1 ] )
return V_2 [ V_1 ] ;
else
return L_10 ;
}
static void F_2 ( struct V_12 * V_13 ,
struct V_14 * V_15 , T_1 V_16 ,
struct V_17 * V_18 )
{
int V_19 ;
struct V_20 * V_21 = V_18 -> V_22 , * V_23 ;
struct V_24 * V_25 ;
for ( V_19 = 0 ; V_19 < V_18 -> V_26 ; V_19 ++ ) {
V_23 = & V_21 [ V_19 ] ;
if ( V_23 -> V_16 == V_16 ) {
V_25 = V_23 -> V_25 ;
F_3 ( V_13 ,
L_11 ,
V_25 -> V_27 . V_28 , V_25 -> V_27 . V_29 + V_23 -> V_29 ,
V_25 -> V_27 . V_30 ) ;
if ( V_23 -> V_31 & V_32 )
F_3 ( V_13 ,
L_12
L_13 ,
F_4 ( V_25 ) ,
F_5 ( V_25 ) ? L_14 : L_15 ,
F_6 ( V_25 ) ,
F_7 ( V_25 ) ) ;
}
}
}
static void F_8 ( struct V_12 * V_13 ,
struct V_14 * V_15 , T_1 V_16 )
{
int type ;
struct V_33 * V_34 ;
F_9 (cpcm, &codec->pcm_list_head, list) {
for ( type = 0 ; type < 2 ; type ++ ) {
if ( V_34 -> V_35 [ type ] . V_16 != V_16 || V_34 -> V_36 == NULL )
continue;
F_3 ( V_13 , L_16
L_17 ,
V_34 -> V_28 ,
V_37 [ V_34 -> V_38 ] ,
V_34 -> V_36 -> V_30 ) ;
}
}
}
static void F_10 ( struct V_12 * V_13 ,
struct V_14 * V_15 , T_1 V_16 , int V_39 )
{
unsigned int V_40 ;
V_40 = F_11 ( V_15 , V_16 , V_39 == V_41 ?
V_42 : V_43 ) ;
if ( V_40 == - 1 || V_40 == 0 ) {
F_3 ( V_13 , L_18 ) ;
return;
}
F_3 ( V_13 , L_19
L_20 ,
V_40 & V_44 ,
( V_40 & V_45 ) >> V_46 ,
( V_40 & V_47 ) >> V_48 ,
( V_40 & V_49 ) >> V_50 ) ;
}
static bool F_12 ( struct V_14 * V_15 , T_1 V_16 ,
int V_39 , unsigned int V_51 , int V_52 )
{
T_1 V_53 ;
if ( V_51 & V_54 )
return true ;
if ( V_52 != 1 || V_39 != V_55 ||
F_13 ( V_51 ) != V_5 )
return false ;
if ( F_14 ( V_15 , V_16 , & V_53 , 1 ) < 0 )
return false ;
V_51 = F_15 ( V_15 , V_53 , V_56 ) ;
return ! ! ( V_51 & V_54 ) ;
}
static void F_16 ( struct V_12 * V_13 ,
struct V_14 * V_15 , T_1 V_16 ,
int V_39 , unsigned int V_51 , int V_52 )
{
unsigned int V_57 ;
bool V_58 ;
int V_19 ;
V_58 = F_12 ( V_15 , V_16 , V_39 , V_51 , V_52 ) ;
V_39 = V_39 == V_41 ? V_59 : V_60 ;
for ( V_19 = 0 ; V_19 < V_52 ; V_19 ++ ) {
F_3 ( V_13 , L_21 ) ;
V_57 = F_17 ( V_15 , V_16 , 0 ,
V_61 ,
V_62 | V_39 | V_19 ) ;
F_3 ( V_13 , L_22 , V_57 ) ;
if ( V_58 ) {
V_57 = F_17 ( V_15 , V_16 , 0 ,
V_61 ,
V_63 | V_39 | V_19 ) ;
F_3 ( V_13 , L_23 , V_57 ) ;
}
F_3 ( V_13 , L_24 ) ;
}
F_3 ( V_13 , L_25 ) ;
}
static void F_18 ( struct V_12 * V_13 , unsigned int V_36 )
{
static unsigned int V_64 [] = {
8000 , 11025 , 16000 , 22050 , 32000 , 44100 , 48000 , 88200 ,
96000 , 176400 , 192000 , 384000
} ;
int V_19 ;
V_36 &= V_65 ;
F_3 ( V_13 , L_26 , V_36 ) ;
for ( V_19 = 0 ; V_19 < F_19 ( V_64 ) ; V_19 ++ )
if ( V_36 & ( 1 << V_19 ) )
F_3 ( V_13 , L_27 , V_64 [ V_19 ] ) ;
F_3 ( V_13 , L_25 ) ;
}
static void F_20 ( struct V_12 * V_13 , unsigned int V_36 )
{
char V_66 [ V_67 ] ;
F_3 ( V_13 , L_28 , ( V_36 >> 16 ) & 0xff ) ;
F_21 ( V_36 , V_66 , sizeof( V_66 ) ) ;
F_3 ( V_13 , L_29 , V_66 ) ;
}
static void F_22 ( struct V_12 * V_13 ,
unsigned int V_68 )
{
F_3 ( V_13 , L_30 , V_68 & 0xf ) ;
if ( V_68 & V_69 )
F_3 ( V_13 , L_31 ) ;
if ( V_68 & V_70 )
F_3 ( V_13 , L_32 ) ;
if ( V_68 & V_71 )
F_3 ( V_13 , L_33 ) ;
F_3 ( V_13 , L_25 ) ;
}
static void F_23 ( struct V_12 * V_13 ,
struct V_14 * V_15 , T_1 V_16 )
{
unsigned int V_36 = F_11 ( V_15 , V_16 , V_72 ) ;
unsigned int V_35 = F_11 ( V_15 , V_16 , V_73 ) ;
if ( V_36 == - 1 || V_35 == - 1 ) {
F_3 ( V_13 , L_18 ) ;
return;
}
F_18 ( V_13 , V_36 ) ;
F_20 ( V_13 , V_36 ) ;
F_22 ( V_13 , V_35 ) ;
}
static const char * F_24 ( T_2 V_74 )
{
static const char * const V_2 [ 16 ] = {
L_34 , L_35 , L_36 , L_37 ,
L_38 , L_39 , L_40 , L_41 ,
L_42 , L_43 , L_44 , L_45 ,
NULL , NULL , NULL , L_46
} ;
V_74 = ( V_74 & V_75 ) >> V_76 ;
if ( V_2 [ V_74 ] )
return V_2 [ V_74 ] ;
else
return L_47 ;
}
static const char * F_25 ( T_2 V_74 )
{
static const char * const V_2 [ 16 ] = {
L_34 , L_48 , L_49 , L_50 ,
L_51 , L_52 , L_53 , L_54 ,
L_55 , L_56 , NULL , NULL ,
NULL , NULL , L_57 , L_46 ,
} ;
V_74 = ( V_74 & V_77 ) >> V_78 ;
if ( V_2 [ V_74 ] )
return V_2 [ V_74 ] ;
else
return L_47 ;
}
static const char * F_26 ( T_2 V_74 )
{
static const char * const V_79 [ 7 ] = {
L_58 , L_59 , L_60 , L_61 , L_62 , L_63 , L_64 ,
} ;
static const unsigned char V_80 [] = {
0x07 , 0x08 ,
0x17 , 0x18 , 0x19 ,
0x37 , 0x38
} ;
static const char * const V_81 [] = {
L_65 , L_66 ,
L_67 , L_68 , L_37 ,
L_69 , L_70
} ;
int V_19 ;
V_74 = ( V_74 & V_82 ) >> V_83 ;
if ( ( V_74 & 0x0f ) < 7 )
return V_79 [ V_74 & 0x0f ] ;
for ( V_19 = 0 ; V_19 < F_19 ( V_80 ) ; V_19 ++ ) {
if ( V_74 == V_80 [ V_19 ] )
return V_81 [ V_19 ] ;
}
return L_47 ;
}
static const char * F_27 ( T_2 V_74 )
{
static const char * const V_84 [ 4 ] = {
L_71 , L_72 , L_73 , L_74
} ;
return V_84 [ ( V_74 >> ( V_83 + 4 ) ) & 3 ] ;
}
static const char * F_28 ( T_2 V_74 )
{
static const char * const V_85 [ 16 ] = {
L_75 , L_76 , L_77 , L_78 ,
L_79 , L_80 , L_81 , L_82 ,
L_83 , L_84 , L_85 , L_86 ,
L_87 , L_88 , L_89 , L_46
} ;
return V_85 [ ( V_74 & V_86 )
>> V_87 ] ;
}
static void F_29 ( struct V_12 * V_13 ,
struct V_14 * V_15 , T_1 V_16 ,
int * V_88 )
{
static const char * const V_89 [ 4 ] = {
L_90 , L_58 , L_91 , L_92
} ;
unsigned int V_40 , V_57 ;
V_40 = F_11 ( V_15 , V_16 , V_90 ) ;
F_3 ( V_13 , L_93 , V_40 ) ;
if ( V_40 & V_91 )
F_3 ( V_13 , L_94 ) ;
if ( V_40 & V_92 )
F_3 ( V_13 , L_95 ) ;
if ( V_40 & V_93 )
F_3 ( V_13 , L_96 ) ;
if ( V_40 & V_94 )
F_3 ( V_13 , L_97 ) ;
if ( V_40 & V_95 )
F_3 ( V_13 , L_98 ) ;
if ( V_40 & V_96 )
F_3 ( V_13 , L_99 ) ;
if ( V_40 & V_97 ) {
if ( ( V_15 -> V_98 . V_99 >> 16 ) == 0x10ec )
F_3 ( V_13 , L_100 ) ;
else {
if ( V_40 & V_100 )
F_3 ( V_13 , L_101 ) ;
F_3 ( V_13 , L_102 ) ;
}
}
if ( V_40 & V_101 )
F_3 ( V_13 , L_103 ) ;
if ( V_40 & V_102 )
F_3 ( V_13 , L_104 ) ;
if ( V_40 & V_103 )
F_3 ( V_13 , L_105 ) ;
F_3 ( V_13 , L_25 ) ;
if ( V_40 & V_104 ) {
unsigned int V_105 =
( V_40 & V_104 ) >> V_106 ;
F_3 ( V_13 , L_106 ) ;
if ( V_105 & V_107 )
F_3 ( V_13 , L_107 ) ;
if ( V_105 & V_108 )
F_3 ( V_13 , L_108 ) ;
if ( V_105 & V_109 )
F_3 ( V_13 , L_109 ) ;
if ( V_105 & V_110 )
F_3 ( V_13 , L_110 ) ;
if ( V_105 & V_111 )
F_3 ( V_13 , L_111 ) ;
F_3 ( V_13 , L_25 ) ;
* V_88 = 1 ;
} else
* V_88 = 0 ;
if ( V_40 & V_94 ) {
V_57 = F_17 ( V_15 , V_16 , 0 ,
V_112 , 0 ) ;
F_3 ( V_13 , L_112 , V_57 ) ;
if ( V_57 & V_113 )
F_3 ( V_13 , L_113 ) ;
if ( V_57 & V_114 )
F_3 ( V_13 , L_97 ) ;
if ( V_57 & V_115 )
F_3 ( V_13 , L_100 ) ;
F_3 ( V_13 , L_25 ) ;
}
V_40 = F_17 ( V_15 , V_16 , 0 , V_116 , 0 ) ;
F_3 ( V_13 , L_114 , V_40 ,
V_89 [ ( V_40 & V_117 ) >> V_118 ] ,
F_28 ( V_40 ) ,
F_27 ( V_40 ) ,
F_26 ( V_40 ) ) ;
F_3 ( V_13 , L_115 ,
F_24 ( V_40 ) ,
F_25 ( V_40 ) ) ;
F_3 ( V_13 , L_116 ,
( V_40 & V_119 ) >> V_120 ,
V_40 & V_121 ) ;
if ( ( ( V_40 & V_122 ) >> V_123 ) &
V_124 ) {
F_3 ( V_13 , L_117 ) ;
}
}
static void F_30 ( struct V_12 * V_13 ,
struct V_14 * V_15 , T_1 V_16 ,
int V_88 )
{
unsigned int V_125 ;
V_125 = F_17 ( V_15 , V_16 , 0 ,
V_126 , 0 ) ;
F_3 ( V_13 , L_118 , V_125 ) ;
if ( V_125 & V_127 )
F_3 ( V_13 , L_94 ) ;
if ( V_125 & V_128 )
F_3 ( V_13 , L_95 ) ;
if ( V_125 & V_129 )
F_3 ( V_13 , L_96 ) ;
if ( V_88 ) {
int V_105 = V_125 & V_130 ;
switch ( V_105 ) {
case V_131 :
F_3 ( V_13 , L_119 ) ;
break;
case V_132 :
F_3 ( V_13 , L_120 ) ;
break;
case V_133 :
F_3 ( V_13 , L_121 ) ;
break;
case V_134 :
F_3 ( V_13 , L_122 ) ;
break;
case V_135 :
F_3 ( V_13 , L_123 ) ;
break;
}
}
F_3 ( V_13 , L_25 ) ;
}
static void F_31 ( struct V_12 * V_13 ,
struct V_14 * V_15 , T_1 V_16 )
{
unsigned int V_136 = F_11 ( V_15 , V_16 , V_137 ) ;
F_3 ( V_13 , L_124 ,
( V_136 >> 7 ) & 1 , V_136 & 0x7f ) ;
V_136 = F_17 ( V_15 , V_16 , 0 ,
V_138 , 0 ) ;
F_3 ( V_13 , L_125 ,
( V_136 >> 7 ) & 1 , V_136 & 0x7f ) ;
}
static void F_32 ( struct V_12 * V_13 ,
struct V_14 * V_15 , T_1 V_16 ,
unsigned int V_139 )
{
int V_140 = F_17 ( V_15 , V_16 , 0 , V_141 , 0 ) ;
F_3 ( V_13 ,
L_126 ,
( V_140 & V_142 ) >> V_143 ,
V_140 & V_144 ) ;
if ( V_139 == V_4 && ( V_140 & V_144 ) == 0 ) {
int V_145 = F_17 ( V_15 , V_16 , 0 ,
V_146 , 0 ) ;
F_3 ( V_13 , L_127 ,
V_145 & V_147 ) ;
}
}
static void F_33 ( struct V_12 * V_13 ,
struct V_14 * V_15 , T_1 V_16 )
{
unsigned int V_148 = F_17 ( V_15 , V_16 , 0 ,
V_149 , 0 ) ;
unsigned char V_150 = V_148 >> 8 ;
unsigned char V_151 = V_148 >> 16 ;
F_3 ( V_13 , L_128 ) ;
if ( V_148 & V_152 )
F_3 ( V_13 , L_129 ) ;
if ( V_148 & V_153 )
F_3 ( V_13 , L_130 ) ;
if ( V_148 & V_154 )
F_3 ( V_13 , L_131 ) ;
if ( V_148 & V_155 )
F_3 ( V_13 , L_132 ) ;
if ( V_148 & V_156 )
F_3 ( V_13 , L_133 ) ;
if ( V_148 & V_157 )
F_3 ( V_13 , L_134 ) ;
if ( V_148 & V_158 )
F_3 ( V_13 , L_135 ) ;
if ( V_148 & V_159 )
F_3 ( V_13 , L_136 ) ;
if ( V_151 & V_160 )
F_3 ( V_13 , L_137 ) ;
F_3 ( V_13 , L_25 ) ;
F_3 ( V_13 , L_138 ,
V_150 & V_161 ) ;
F_3 ( V_13 , L_139 ,
V_151 & V_162 ) ;
}
static const char * F_34 ( T_2 V_163 )
{
static const char * const V_66 [] = {
L_140 , L_141 , L_142 , L_143 , L_144
} ;
if ( V_163 < F_19 ( V_66 ) )
return V_66 [ V_163 ] ;
return L_47 ;
}
static void F_35 ( struct V_12 * V_13 ,
struct V_14 * V_15 , T_1 V_16 )
{
static const char * const V_2 [] = {
[ F_36 ( V_164 ) ] = L_140 ,
[ F_36 ( V_165 ) ] = L_141 ,
[ F_36 ( V_166 ) ] = L_142 ,
[ F_36 ( V_167 ) ] = L_143 ,
[ F_36 ( V_168 ) ] = L_144 ,
[ F_36 ( V_169 ) ] = L_145 ,
[ F_36 ( V_170 ) ] = L_146 ,
[ F_36 ( V_171 ) ] = L_147 ,
} ;
int V_172 = F_11 ( V_15 , V_16 , V_173 ) ;
int V_174 = F_17 ( V_15 , V_16 , 0 ,
V_175 , 0 ) ;
if ( V_172 != - 1 ) {
int V_19 ;
F_3 ( V_13 , L_148 ) ;
for ( V_19 = 0 ; V_19 < F_19 ( V_2 ) ; V_19 ++ ) {
if ( V_172 & ( 1U << V_19 ) )
F_3 ( V_13 , L_149 , V_2 [ V_19 ] ) ;
}
F_3 ( V_13 , L_25 ) ;
}
F_3 ( V_13 , L_150 ,
F_34 ( V_174 & V_176 ) ,
F_34 ( ( V_174 & V_177 ) >>
V_178 ) ) ;
if ( V_174 & V_179 )
F_3 ( V_13 , L_151 ) ;
if ( V_174 & V_180 )
F_3 ( V_13 , L_152 ) ;
if ( V_174 & V_181 )
F_3 ( V_13 , L_153 ) ;
F_3 ( V_13 , L_25 ) ;
}
static void F_37 ( struct V_12 * V_13 ,
struct V_14 * V_15 , T_1 V_16 )
{
int V_182 = F_17 ( V_15 , V_16 , 0 ,
V_183 , 0 ) ;
F_3 ( V_13 ,
L_154 ,
V_182 & V_184 ,
( V_182 & V_185 ) ? 1 : 0 ) ;
}
static inline bool F_38 ( struct V_14 * V_15 )
{
switch ( V_186 ) {
case 0 : return false ;
case 1 : return true ;
default: return V_15 -> V_186 ;
}
}
static void F_39 ( struct V_12 * V_13 ,
struct V_14 * V_15 , T_1 V_16 )
{
unsigned int V_19 , V_187 , V_188 ;
unsigned int V_189 = F_11 ( V_15 , V_16 , V_190 ) ;
V_187 = ( V_189 & V_191 ) >> V_192 ;
F_3 ( V_13 , L_155 ,
V_189 & V_193 , V_187 ) ;
if ( ! F_38 ( V_15 ) )
return;
V_188 = F_17 ( V_15 , V_16 , 0 , V_194 , 0 ) ;
for ( V_19 = 0 ; V_19 < V_187 ; V_19 ++ ) {
unsigned int V_57 ;
F_40 ( V_15 , V_16 , 0 , V_195 , V_19 ) ;
V_57 = F_17 ( V_15 , V_16 , 0 , V_196 ,
0 ) ;
F_3 ( V_13 , L_156 , V_19 , V_57 ) ;
}
F_40 ( V_15 , V_16 , 0 , V_195 , V_188 ) ;
}
static void F_41 ( struct V_12 * V_13 ,
struct V_14 * V_15 , T_1 V_16 ,
unsigned int V_139 , T_1 * V_53 ,
int V_197 )
{
int V_198 , V_199 = - 1 ;
const T_1 * V_22 ;
int V_200 ;
if ( V_197 > 1 &&
V_139 != V_5 &&
V_139 != V_9 &&
V_139 != V_8 )
V_199 = F_17 ( V_15 , V_16 , 0 ,
V_201 , 0 ) ;
F_3 ( V_13 , L_157 , V_197 ) ;
if ( V_197 > 0 ) {
F_3 ( V_13 , L_158 ) ;
for ( V_198 = 0 ; V_198 < V_197 ; V_198 ++ ) {
F_3 ( V_13 , L_23 , V_53 [ V_198 ] ) ;
if ( V_198 == V_199 )
F_3 ( V_13 , L_159 ) ;
}
F_3 ( V_13 , L_25 ) ;
}
V_200 = F_42 ( V_15 , V_16 , & V_22 ) ;
if ( V_200 >= 0 && ( V_200 != V_197 ||
memcmp ( V_22 , V_53 , V_197 ) != 0 ) ) {
F_3 ( V_13 , L_160 , V_200 ) ;
if ( V_200 > 0 ) {
F_3 ( V_13 , L_158 ) ;
for ( V_198 = 0 ; V_198 < V_200 ; V_198 ++ )
F_3 ( V_13 , L_23 , V_22 [ V_198 ] ) ;
F_3 ( V_13 , L_25 ) ;
}
}
}
static void F_43 ( struct V_12 * V_13 ,
struct V_14 * V_15 , T_1 V_16 )
{
unsigned int V_202 =
F_11 ( V_15 , V_15 -> V_98 . V_203 , V_204 ) ;
unsigned int V_205 , V_206 , V_207 , V_182 , V_208 , V_209 ;
int V_19 , V_210 ;
F_3 ( V_13 , L_161
L_162 ,
V_202 & V_211 ,
( V_202 & V_212 ) >> V_213 ,
( V_202 & V_214 ) >> V_215 ,
( V_202 & V_216 ) ? 1 : 0 ,
( V_202 & V_217 ) ? 1 : 0 ) ;
V_210 = V_202 & V_211 ;
if ( ! V_210 || V_210 > 8 )
return;
V_205 = F_17 ( V_15 , V_16 , 0 ,
V_218 , 0 ) ;
V_206 = F_17 ( V_15 , V_16 , 0 ,
V_219 , 0 ) ;
V_207 = F_17 ( V_15 , V_16 , 0 ,
V_220 , 0 ) ;
V_182 = F_17 ( V_15 , V_16 , 0 ,
V_221 , 0 ) ;
V_208 = F_17 ( V_15 , V_16 , 0 ,
V_222 , 0 ) ;
V_209 = F_17 ( V_15 , V_16 , 0 ,
V_223 , 0 ) ;
for ( V_19 = 0 ; V_19 < V_210 ; ++ V_19 )
F_3 ( V_13 ,
L_163
L_164 , V_19 ,
( V_205 & ( 1 << V_19 ) ) ? 1 : 0 ,
( V_206 & ( 1 << V_19 ) ) ? 1 : 0 ,
( V_207 & ( 1 << V_19 ) ) ? 1 : 0 ,
( V_208 & ( 1 << V_19 ) ) ? 1 : 0 ,
( V_209 & ( 1 << V_19 ) ) ? 1 : 0 ,
( V_182 & ( 1 << V_19 ) ) ? 1 : 0 ) ;
F_2 ( V_13 , V_15 , V_16 , & V_15 -> V_224 ) ;
F_2 ( V_13 , V_15 , V_16 , & V_15 -> V_225 ) ;
}
static void F_44 ( struct V_12 * V_13 ,
struct V_14 * V_15 , T_1 V_16 )
{
int V_19 , V_199 = - 1 ;
T_3 V_226 [ V_227 ] ;
int V_228 ;
V_228 = F_45 ( V_15 , V_16 , V_226 ,
V_227 ) ;
F_3 ( V_13 , L_165 , V_228 ) ;
if ( V_228 <= 0 )
return;
V_199 = F_17 ( V_15 , V_16 , 0 ,
V_229 , 0 ) ;
for ( V_19 = 0 ; V_19 < V_228 ; V_19 ++ ) {
if ( V_19 == V_199 )
F_3 ( V_13 , L_166 ) ;
else
F_3 ( V_13 , L_167 ) ;
F_3 ( V_13 ,
L_168 , V_19 ,
! ! ( V_226 [ V_19 ] & V_230 ) ,
! ! ( V_226 [ V_19 ] & V_231 ) ,
! ! ( V_226 [ V_19 ] & V_232 ) ) ;
}
}
static void F_46 ( struct V_233 * V_15 ,
struct V_12 * V_13 )
{
F_3 ( V_13 , L_169 ) ;
if ( V_15 -> V_234 && V_15 -> V_235 )
F_3 ( V_13 , L_170 ,
V_15 -> V_234 , V_15 -> V_235 ) ;
else
F_3 ( V_13 , L_171 ) ;
F_3 ( V_13 , L_172 , V_15 -> V_236 ) ;
if ( V_15 -> V_203 )
F_3 ( V_13 , L_173 ,
V_15 -> V_237 , V_15 -> V_238 ) ;
if ( V_15 -> V_239 )
F_3 ( V_13 , L_174 ,
V_15 -> V_240 , V_15 -> V_241 ) ;
F_3 ( V_13 , L_175 , V_15 -> V_99 ) ;
F_3 ( V_13 , L_176 , V_15 -> V_242 ) ;
F_3 ( V_13 , L_177 , V_15 -> V_243 ) ;
if ( V_15 -> V_239 )
F_3 ( V_13 , L_178 , V_15 -> V_239 ) ;
else
F_3 ( V_13 , L_179 ) ;
}
static void F_47 ( struct V_244 * V_245 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_245 -> V_246 ;
T_1 V_16 , V_247 ;
int V_19 , V_248 ;
F_46 ( & V_15 -> V_98 , V_13 ) ;
V_247 = V_15 -> V_98 . V_203 ;
if ( ! V_247 )
return;
F_48 ( V_15 ) ;
F_3 ( V_13 , L_180 ) ;
F_23 ( V_13 , V_15 , V_247 ) ;
F_3 ( V_13 , L_181 ) ;
F_10 ( V_13 , V_15 , V_247 , V_55 ) ;
F_3 ( V_13 , L_182 ) ;
F_10 ( V_13 , V_15 , V_247 , V_41 ) ;
F_3 ( V_13 , L_183 , V_247 ) ;
F_35 ( V_13 , V_15 , V_247 ) ;
V_248 = F_49 ( V_15 , V_247 , & V_16 ) ;
if ( ! V_16 || V_248 < 0 ) {
F_3 ( V_13 , L_184 ) ;
F_50 ( V_15 ) ;
return;
}
F_43 ( V_13 , V_15 , V_247 ) ;
if ( V_15 -> V_249 )
V_15 -> V_249 ( V_13 , V_15 , V_247 ) ;
for ( V_19 = 0 ; V_19 < V_248 ; V_19 ++ , V_16 ++ ) {
unsigned int V_250 =
F_11 ( V_15 , V_16 , V_56 ) ;
unsigned int V_139 = F_13 ( V_250 ) ;
T_1 * V_53 = NULL ;
int V_197 = 0 ;
F_3 ( V_13 , L_185 , V_16 ,
F_1 ( V_139 ) , V_250 ) ;
if ( V_250 & V_54 ) {
unsigned int V_251 = F_51 ( V_250 ) ;
if ( V_251 == 2 )
F_3 ( V_13 , L_186 ) ;
else
F_3 ( V_13 , L_187 , V_251 ) ;
} else
F_3 ( V_13 , L_188 ) ;
if ( V_250 & V_252 )
F_3 ( V_13 , L_189 ) ;
if ( V_250 & V_253 )
F_3 ( V_13 , L_190 ) ;
if ( V_250 & V_254 )
F_3 ( V_13 , L_191 ) ;
if ( V_250 & V_255 )
F_3 ( V_13 , L_192 ) ;
if ( V_250 & V_256 )
F_3 ( V_13 , L_100 ) ;
if ( V_250 & V_257 )
F_3 ( V_13 , L_193 ) ;
F_3 ( V_13 , L_25 ) ;
F_2 ( V_13 , V_15 , V_16 , & V_15 -> V_224 ) ;
F_2 ( V_13 , V_15 , V_16 , & V_15 -> V_225 ) ;
F_8 ( V_13 , V_15 , V_16 ) ;
if ( V_139 == V_9 )
V_250 |= V_258 ;
if ( V_250 & V_258 ) {
V_197 = F_52 ( V_15 , V_16 ) ;
if ( V_197 > 0 ) {
V_53 = F_53 ( sizeof( T_1 ) * V_197 ,
V_259 ) ;
if ( ! V_53 )
return;
if ( F_14 ( V_15 , V_16 , V_53 ,
V_197 ) < 0 )
V_197 = 0 ;
}
}
if ( V_250 & V_253 ) {
F_3 ( V_13 , L_194 ) ;
F_10 ( V_13 , V_15 , V_16 , V_55 ) ;
F_3 ( V_13 , L_195 ) ;
if ( V_139 == V_7 ||
( V_15 -> V_260 &&
V_139 == V_4 ) )
F_16 ( V_13 , V_15 , V_16 , V_55 ,
V_250 , 1 ) ;
else
F_16 ( V_13 , V_15 , V_16 , V_55 ,
V_250 , V_197 ) ;
}
if ( V_250 & V_254 ) {
F_3 ( V_13 , L_196 ) ;
F_10 ( V_13 , V_15 , V_16 , V_41 ) ;
F_3 ( V_13 , L_197 ) ;
if ( V_139 == V_7 &&
V_15 -> V_261 )
F_16 ( V_13 , V_15 , V_16 , V_41 ,
V_250 , V_197 ) ;
else
F_16 ( V_13 , V_15 , V_16 , V_41 ,
V_250 , 1 ) ;
}
switch ( V_139 ) {
case V_7 : {
int V_88 ;
F_29 ( V_13 , V_15 , V_16 , & V_88 ) ;
F_30 ( V_13 , V_15 , V_16 , V_88 ) ;
break;
}
case V_9 :
F_31 ( V_13 , V_15 , V_16 ) ;
break;
case V_3 :
case V_4 :
F_32 ( V_13 , V_15 , V_16 , V_139 ) ;
if ( V_250 & V_252 )
F_33 ( V_13 , V_15 , V_16 ) ;
if ( V_250 & V_262 ) {
F_3 ( V_13 , L_198 ) ;
F_23 ( V_13 , V_15 , V_16 ) ;
}
break;
}
if ( V_250 & V_263 )
F_37 ( V_13 , V_15 , V_16 ) ;
if ( V_250 & V_264 )
F_35 ( V_13 , V_15 , V_16 ) ;
if ( V_250 & V_265 )
F_3 ( V_13 , L_199 ,
( V_250 & V_265 ) >>
V_266 ) ;
if ( V_139 == V_7 && V_15 -> V_267 )
F_44 ( V_13 , V_15 , V_16 ) ;
if ( V_250 & V_258 )
F_41 ( V_13 , V_15 , V_16 , V_139 ,
V_53 , V_197 ) ;
if ( V_250 & V_268 )
F_39 ( V_13 , V_15 , V_16 ) ;
if ( V_15 -> V_249 )
V_15 -> V_249 ( V_13 , V_15 , V_16 ) ;
F_54 ( V_53 ) ;
}
F_50 ( V_15 ) ;
}
int F_55 ( struct V_14 * V_15 )
{
char V_28 [ 32 ] ;
struct V_244 * V_245 ;
int V_269 ;
snprintf ( V_28 , sizeof( V_28 ) , L_200 , V_15 -> V_98 . V_236 ) ;
V_269 = F_56 ( V_15 -> V_270 , V_28 , & V_245 ) ;
if ( V_269 < 0 )
return V_269 ;
F_57 ( V_245 , V_15 , F_47 ) ;
return 0 ;
}
