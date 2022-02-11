static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
F_2 ( V_2 -> V_5 , V_4 << V_2 -> V_6 , V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , int V_4 )
{
unsigned int V_3 = 0 ;
F_4 ( V_2 -> V_5 , V_4 << V_2 -> V_6 , & V_3 ) ;
return V_3 ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_7 , T_1 V_8 , unsigned V_9 )
{
F_6 ( V_2 -> V_5 , V_9 << V_2 -> V_6 , V_8 , V_7 ) ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_7 , unsigned int V_9 ,
T_1 V_10 , T_1 V_8 )
{
F_5 ( V_2 , V_7 << V_10 , V_8 , V_9 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0x00 , V_11 ) ;
F_1 ( V_2 , 0x00 , V_12 ) ;
F_1 ( V_2 , V_13 , V_14 ) ;
F_1 ( V_2 , V_15 | V_16 ,
V_17 ) ;
F_1 ( V_2 , V_18 | V_19 ,
V_20 ) ;
F_1 ( V_2 , V_18 | V_19 ,
V_21 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned char * V_22 , unsigned int V_23 )
{
struct V_24 * V_25 = V_2 -> V_25 ;
int V_26 ;
if ( ! V_25 -> V_27 ) {
F_10 ( V_2 -> V_28 , L_1 ) ;
V_25 -> V_29 = 0x00 ;
V_25 -> V_27 = true ;
}
while ( V_23 -- ) {
F_11 ( & V_25 -> V_30 ) ;
F_1 ( V_2 , V_25 -> V_29 ++ , V_31 ) ;
if ( V_25 -> V_32 )
F_1 ( V_2 , V_33 ,
V_34 ) ;
else
F_1 ( V_2 , V_35 ,
V_34 ) ;
V_26 = F_12 ( & V_25 -> V_30 , V_36 / 10 ) ;
if ( ! V_26 )
return - V_37 ;
if ( V_25 -> V_26 & V_18 )
return - V_38 ;
* V_22 ++ = F_3 ( V_2 , V_39 ) ;
}
V_25 -> V_32 = false ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
unsigned char * V_22 , unsigned int V_23 )
{
struct V_24 * V_25 = V_2 -> V_25 ;
int V_26 ;
if ( ! V_25 -> V_27 ) {
V_25 -> V_29 = V_22 [ 0 ] ;
V_23 -- ;
V_22 ++ ;
V_25 -> V_27 = true ;
}
while ( V_23 -- ) {
F_11 ( & V_25 -> V_30 ) ;
F_1 ( V_2 , * V_22 ++ , V_40 ) ;
F_1 ( V_2 , V_25 -> V_29 ++ , V_31 ) ;
F_1 ( V_2 , V_41 ,
V_34 ) ;
V_26 = F_12 ( & V_25 -> V_30 , V_36 / 10 ) ;
if ( ! V_26 )
return - V_37 ;
if ( V_25 -> V_26 & V_18 )
return - V_38 ;
}
return 0 ;
}
static int F_14 ( struct V_42 * V_43 ,
struct V_44 * V_45 , int V_46 )
{
struct V_1 * V_2 = F_15 ( V_43 ) ;
struct V_24 * V_25 = V_2 -> V_25 ;
T_1 V_47 = V_45 [ 0 ] . V_47 ;
int V_48 , V_49 = 0 ;
F_10 ( V_2 -> V_28 , L_2 , V_46 , V_47 ) ;
for ( V_48 = 0 ; V_48 < V_46 ; V_48 ++ ) {
if ( V_45 [ V_48 ] . V_50 == 0 ) {
F_10 ( V_2 -> V_28 ,
L_3 ,
V_48 + 1 , V_46 ) ;
return - V_51 ;
}
}
F_16 ( & V_25 -> V_52 ) ;
F_1 ( V_2 , 0x00 , V_21 ) ;
F_1 ( V_2 , V_47 , V_53 ) ;
V_25 -> V_27 = false ;
V_25 -> V_32 = false ;
for ( V_48 = 0 ; V_48 < V_46 ; V_48 ++ ) {
F_10 ( V_2 -> V_28 , L_4 ,
V_48 + 1 , V_46 , V_45 [ V_48 ] . V_50 , V_45 [ V_48 ] . V_54 ) ;
if ( V_45 [ V_48 ] . V_47 == V_55 && V_45 [ V_48 ] . V_50 == 1 ) {
V_25 -> V_32 = true ;
F_1 ( V_2 , V_55 , V_56 ) ;
F_1 ( V_2 , * V_45 [ V_48 ] . V_22 , V_57 ) ;
} else {
if ( V_45 [ V_48 ] . V_54 & V_58 )
V_49 = F_9 ( V_2 , V_45 [ V_48 ] . V_22 ,
V_45 [ V_48 ] . V_50 ) ;
else
V_49 = F_13 ( V_2 , V_45 [ V_48 ] . V_22 ,
V_45 [ V_48 ] . V_50 ) ;
}
if ( V_49 < 0 )
break;
}
if ( ! V_49 )
V_49 = V_46 ;
F_1 ( V_2 , V_18 | V_19 ,
V_21 ) ;
F_17 ( & V_25 -> V_52 ) ;
return V_49 ;
}
static T_2 F_18 ( struct V_42 * V_59 )
{
return V_60 | V_61 ;
}
static struct V_42 * F_19 ( struct V_1 * V_2 )
{
struct V_42 * V_43 ;
struct V_24 * V_25 ;
int V_49 ;
V_25 = F_20 ( V_2 -> V_28 , sizeof( * V_25 ) , V_62 ) ;
if ( ! V_25 )
return F_21 ( - V_63 ) ;
F_22 ( & V_25 -> V_52 ) ;
F_23 ( & V_25 -> V_30 ) ;
V_43 = & V_25 -> V_43 ;
V_43 -> V_64 = V_65 ;
V_43 -> V_66 = V_67 ;
V_43 -> V_28 . V_68 = V_2 -> V_28 ;
V_43 -> V_69 = & V_70 ;
F_24 ( V_43 -> V_71 , L_5 , sizeof( V_43 -> V_71 ) ) ;
F_25 ( V_43 , V_2 ) ;
V_49 = F_26 ( V_43 ) ;
if ( V_49 ) {
F_27 ( V_2 -> V_28 , L_6 , V_43 -> V_71 ) ;
F_28 ( V_2 -> V_28 , V_25 ) ;
return F_21 ( V_49 ) ;
}
V_2 -> V_25 = V_25 ;
F_29 ( V_2 -> V_28 , L_7 , V_43 -> V_71 ) ;
return V_43 ;
}
static void F_30 ( struct V_1 * V_2 , unsigned int V_72 ,
unsigned int V_73 )
{
F_5 ( V_2 , 0 , V_74 , V_75 ) ;
F_5 ( V_2 , 0 , V_76 , V_75 ) ;
F_1 ( V_2 , ( ( V_72 >> 16 ) & V_77 ) |
V_74 , V_75 ) ;
F_1 ( V_2 , ( V_72 >> 8 ) & 0xff , V_78 ) ;
F_1 ( V_2 , V_72 & 0xff , V_79 ) ;
F_1 ( V_2 , ( V_73 >> 16 ) & 0x0f , V_80 ) ;
F_1 ( V_2 , ( V_73 >> 8 ) & 0xff , V_81 ) ;
F_1 ( V_2 , V_73 & 0xff , V_82 ) ;
}
static unsigned int F_31 ( unsigned int V_83 , unsigned long V_84 )
{
unsigned int V_73 = ( 128 * V_83 ) / 1000 ;
unsigned int V_85 = 1 ;
while ( V_83 > 48000 ) {
V_85 *= 2 ;
V_83 /= 2 ;
}
switch ( V_83 ) {
case 32000 :
if ( V_84 == 25175000 )
V_73 = 4576 ;
else if ( V_84 == 27027000 )
V_73 = 4096 ;
else if ( V_84 == 74176000 || V_84 == 148352000 )
V_73 = 11648 ;
else
V_73 = 4096 ;
V_73 *= V_85 ;
break;
case 44100 :
if ( V_84 == 25175000 )
V_73 = 7007 ;
else if ( V_84 == 74176000 )
V_73 = 17836 ;
else if ( V_84 == 148352000 )
V_73 = 8918 ;
else
V_73 = 6272 ;
V_73 *= V_85 ;
break;
case 48000 :
if ( V_84 == 25175000 )
V_73 = 6864 ;
else if ( V_84 == 27027000 )
V_73 = 6144 ;
else if ( V_84 == 74176000 )
V_73 = 11648 ;
else if ( V_84 == 148352000 )
V_73 = 5824 ;
else
V_73 = 6144 ;
V_73 *= V_85 ;
break;
default:
break;
}
return V_73 ;
}
static void F_32 ( struct V_1 * V_2 ,
unsigned long V_84 , unsigned int V_86 )
{
unsigned long V_87 = V_84 ;
unsigned int V_73 , V_72 ;
T_3 V_88 ;
V_73 = F_31 ( V_86 , V_84 ) ;
V_88 = ( T_3 ) V_87 * V_73 ;
F_33 ( V_88 , 128 * V_86 ) ;
V_72 = V_88 ;
F_10 ( V_2 -> V_28 , L_8 ,
V_89 , V_86 , V_87 / 1000000 , ( V_87 / 1000 ) % 1000 ,
V_73 , V_72 ) ;
F_34 ( & V_2 -> V_90 ) ;
V_2 -> V_91 = V_73 ;
V_2 -> V_92 = V_72 ;
F_30 ( V_2 , V_72 , V_2 -> V_93 ? V_73 : 0 ) ;
F_35 ( & V_2 -> V_90 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_16 ( & V_2 -> V_94 ) ;
F_32 ( V_2 , 74250000 , V_2 -> V_86 ) ;
F_17 ( & V_2 -> V_94 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_16 ( & V_2 -> V_94 ) ;
F_32 ( V_2 , V_2 -> V_95 . V_96 . V_97 ,
V_2 -> V_86 ) ;
F_17 ( & V_2 -> V_94 ) ;
}
void F_38 ( struct V_1 * V_2 , unsigned int V_98 )
{
F_16 ( & V_2 -> V_94 ) ;
V_2 -> V_86 = V_98 ;
F_32 ( V_2 , V_2 -> V_95 . V_96 . V_97 ,
V_2 -> V_86 ) ;
F_17 ( & V_2 -> V_94 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
unsigned long V_54 ;
F_40 ( & V_2 -> V_90 , V_54 ) ;
V_2 -> V_93 = true ;
F_30 ( V_2 , V_2 -> V_92 , V_2 -> V_91 ) ;
F_41 ( & V_2 -> V_90 , V_54 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
unsigned long V_54 ;
F_40 ( & V_2 -> V_90 , V_54 ) ;
V_2 -> V_93 = false ;
F_30 ( V_2 , V_2 -> V_92 , 0 ) ;
F_41 ( & V_2 -> V_90 , V_54 ) ;
}
static bool F_43 ( unsigned int V_99 )
{
switch ( V_99 ) {
case V_100 :
case V_101 :
case V_102 :
case V_103 :
return true ;
default:
return false ;
}
}
static bool F_44 ( unsigned int V_99 )
{
switch ( V_99 ) {
case V_104 :
case V_105 :
case V_106 :
case V_107 :
return true ;
default:
return false ;
}
}
static bool F_45 ( unsigned int V_99 )
{
switch ( V_99 ) {
case V_108 :
case V_109 :
case V_110 :
return true ;
default:
return false ;
}
}
static int F_46 ( unsigned int V_99 )
{
switch ( V_99 ) {
case V_100 :
case V_104 :
case V_108 :
case V_111 :
return 8 ;
case V_101 :
case V_105 :
case V_109 :
case V_112 :
return 10 ;
case V_102 :
case V_106 :
case V_110 :
case V_113 :
return 12 ;
case V_103 :
case V_107 :
case V_114 :
return 16 ;
default:
return 0 ;
}
}
static void F_47 ( struct V_1 * V_2 )
{
int V_115 = 0 ;
T_1 V_3 ;
switch ( V_2 -> V_95 . V_116 ) {
case V_100 :
V_115 = 0x01 ;
break;
case V_101 :
V_115 = 0x03 ;
break;
case V_102 :
V_115 = 0x05 ;
break;
case V_103 :
V_115 = 0x07 ;
break;
case V_104 :
case V_111 :
V_115 = 0x09 ;
break;
case V_105 :
case V_112 :
V_115 = 0x0B ;
break;
case V_106 :
case V_113 :
V_115 = 0x0D ;
break;
case V_107 :
case V_114 :
V_115 = 0x0F ;
break;
case V_108 :
V_115 = 0x16 ;
break;
case V_109 :
V_115 = 0x14 ;
break;
case V_110 :
V_115 = 0x12 ;
break;
default:
return;
}
V_3 = V_117 |
( ( V_115 << V_118 ) &
V_119 ) ;
F_1 ( V_2 , V_3 , V_120 ) ;
V_3 = V_121 |
V_122 |
V_123 ;
F_1 ( V_2 , V_3 , V_124 ) ;
F_1 ( V_2 , 0x0 , V_125 ) ;
F_1 ( V_2 , 0x0 , V_126 ) ;
F_1 ( V_2 , 0x0 , V_127 ) ;
F_1 ( V_2 , 0x0 , V_128 ) ;
F_1 ( V_2 , 0x0 , V_129 ) ;
F_1 ( V_2 , 0x0 , V_130 ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
return V_2 -> V_95 . V_116 != V_2 -> V_95 . V_131 ;
}
static int F_49 ( struct V_1 * V_2 )
{
if ( ! F_45 ( V_2 -> V_95 . V_131 ) )
return 0 ;
if ( F_43 ( V_2 -> V_95 . V_116 ) ||
F_44 ( V_2 -> V_95 . V_116 ) )
return 1 ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
if ( ! F_45 ( V_2 -> V_95 . V_116 ) )
return 0 ;
if ( F_43 ( V_2 -> V_95 . V_131 ) ||
F_44 ( V_2 -> V_95 . V_131 ) )
return 1 ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 )
{
const F_52 ( * V_132 ) [ 3 ] [ 4 ] = & V_133 ;
unsigned V_48 ;
T_2 V_134 = 1 ;
if ( F_48 ( V_2 ) ) {
if ( F_43 ( V_2 -> V_95 . V_131 ) ) {
if ( V_2 -> V_95 . V_135 ==
V_136 )
V_132 = & V_137 ;
else
V_132 = & V_138 ;
} else if ( F_43 (
V_2 -> V_95 . V_116 ) ) {
if ( V_2 -> V_95 . V_135 ==
V_136 )
V_132 = & V_139 ;
else
V_132 = & V_140 ;
V_134 = 0 ;
}
}
for ( V_48 = 0 ; V_48 < F_53 ( V_133 [ 0 ] ) ; V_48 ++ ) {
F_52 V_141 = ( * V_132 ) [ 0 ] [ V_48 ] ;
F_52 V_142 = ( * V_132 ) [ 1 ] [ V_48 ] ;
F_52 V_143 = ( * V_132 ) [ 2 ] [ V_48 ] ;
F_1 ( V_2 , V_141 & 0xff , V_144 + V_48 * 2 ) ;
F_1 ( V_2 , V_141 >> 8 , V_145 + V_48 * 2 ) ;
F_1 ( V_2 , V_142 & 0xff , V_146 + V_48 * 2 ) ;
F_1 ( V_2 , V_142 >> 8 , V_147 + V_48 * 2 ) ;
F_1 ( V_2 , V_143 & 0xff , V_148 + V_48 * 2 ) ;
F_1 ( V_2 , V_143 >> 8 , V_149 + V_48 * 2 ) ;
}
F_5 ( V_2 , V_134 , V_150 ,
V_151 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
int V_152 = 0 ;
int V_153 = V_154 ;
int V_155 = 0 ;
if ( F_50 ( V_2 ) )
V_153 = V_156 ;
else if ( F_49 ( V_2 ) )
V_155 = V_157 ;
switch ( F_46 ( V_2 -> V_95 . V_131 ) ) {
case 8 :
V_152 = V_158 ;
break;
case 10 :
V_152 = V_159 ;
break;
case 12 :
V_152 = V_160 ;
break;
case 16 :
V_152 = V_161 ;
break;
default:
return;
}
F_1 ( V_2 , V_153 | V_155 , V_162 ) ;
F_5 ( V_2 , V_152 , V_163 ,
V_151 ) ;
F_51 ( V_2 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
unsigned int V_152 = 0 ;
unsigned int V_164 = V_165 ;
unsigned int V_166 = V_167 ;
struct V_168 * V_95 = & V_2 -> V_95 ;
T_1 V_3 , V_169 ;
if ( F_43 ( V_2 -> V_95 . V_131 ) ||
F_44 ( V_2 -> V_95 . V_131 ) ) {
switch ( F_46 (
V_2 -> V_95 . V_131 ) ) {
case 8 :
V_152 = 4 ;
V_166 = V_170 ;
break;
case 10 :
V_152 = 5 ;
break;
case 12 :
V_152 = 6 ;
break;
case 16 :
V_152 = 7 ;
break;
default:
V_166 = V_170 ;
}
} else if ( F_45 ( V_2 -> V_95 . V_131 ) ) {
switch ( F_46 (
V_2 -> V_95 . V_131 ) ) {
case 0 :
case 8 :
V_164 = V_165 ;
break;
case 10 :
V_164 = V_171 ;
break;
case 12 :
V_164 = V_172 ;
break;
default:
return;
}
V_166 = V_173 ;
} else {
return;
}
V_3 = ( ( V_152 << V_174 ) &
V_175 ) |
( ( V_95 -> V_176 <<
V_177 ) &
V_178 ) ;
F_1 ( V_2 , V_3 , V_179 ) ;
F_5 ( V_2 , V_180 ,
V_181 , V_182 ) ;
if ( V_95 -> V_176 > 1 ) {
V_169 = V_183 |
V_184 ;
} else {
V_169 = V_185 |
V_186 ;
}
F_5 ( V_2 , V_169 ,
V_187 |
V_188 , V_189 ) ;
F_5 ( V_2 , 1 << V_190 ,
V_191 , V_182 ) ;
F_1 ( V_2 , V_164 , V_192 ) ;
if ( V_166 == V_167 ) {
V_169 = V_193 |
V_194 |
V_195 ;
} else if ( V_166 == V_173 ) {
V_169 = V_193 |
V_196 |
V_197 ;
} else if ( V_166 == V_170 ) {
V_169 = V_198 |
V_196 |
V_195 ;
} else {
return;
}
F_5 ( V_2 , V_169 ,
V_199 | V_200 |
V_201 , V_189 ) ;
F_5 ( V_2 , V_202 |
V_203 ,
V_204 |
V_205 , V_182 ) ;
F_5 ( V_2 , V_166 , V_206 ,
V_189 ) ;
}
static inline void F_56 ( struct V_1 * V_2 ,
unsigned char V_207 )
{
F_5 ( V_2 , V_207 << V_208 ,
V_209 , V_210 ) ;
}
static bool F_57 ( struct V_1 * V_2 , int V_211 )
{
T_2 V_3 ;
while ( ( V_3 = F_3 ( V_2 , V_212 ) & 0x3 ) == 0 ) {
if ( V_211 -- == 0 )
return false ;
F_58 ( 1000 ) ;
}
F_1 ( V_2 , V_3 , V_212 ) ;
return true ;
}
void F_59 ( struct V_1 * V_2 , unsigned short V_7 ,
unsigned char V_47 )
{
F_1 ( V_2 , 0xFF , V_212 ) ;
F_1 ( V_2 , V_47 , V_213 ) ;
F_1 ( V_2 , ( unsigned char ) ( V_7 >> 8 ) ,
V_214 ) ;
F_1 ( V_2 , ( unsigned char ) ( V_7 >> 0 ) ,
V_215 ) ;
F_1 ( V_2 , V_216 ,
V_217 ) ;
F_57 ( V_2 , 1000 ) ;
}
static void F_60 ( struct V_1 * V_2 , bool V_218 )
{
F_7 ( V_2 , ! V_218 , V_219 ,
V_220 ,
V_221 ) ;
}
static void F_61 ( struct V_1 * V_2 , T_1 V_218 )
{
F_7 ( V_2 , V_218 , V_219 ,
V_222 ,
V_223 ) ;
}
static void F_62 ( struct V_1 * V_2 , T_1 V_218 )
{
F_7 ( V_2 , V_218 , V_219 ,
V_224 ,
V_225 ) ;
}
static void F_63 ( struct V_1 * V_2 , T_1 V_218 )
{
F_7 ( V_2 , V_218 , V_219 ,
V_226 ,
V_227 ) ;
}
static void F_64 ( struct V_1 * V_2 , T_1 V_218 )
{
F_7 ( V_2 , V_218 , V_219 ,
V_228 ,
V_229 ) ;
}
static void F_65 ( struct V_1 * V_2 , T_1 V_218 )
{
F_7 ( V_2 , V_218 , V_219 ,
V_230 ,
V_231 ) ;
}
static void F_66 ( struct V_1 * V_2 , T_1 V_218 )
{
F_7 ( V_2 , V_218 , V_219 ,
V_232 ,
V_233 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
const struct V_234 * V_235 = V_2 -> V_235 . V_7 ;
unsigned int V_48 ;
F_52 V_3 ;
if ( V_235 -> V_236 == 1 ) {
F_61 ( V_2 , 0 ) ;
F_60 ( V_2 , true ) ;
return;
}
F_64 ( V_2 , 0 ) ;
for ( V_48 = 0 ; V_48 < 5 ; ++ V_48 ) {
V_3 = F_3 ( V_2 , V_237 ) ;
if ( ! ( V_3 & V_238 ) )
break;
F_68 ( 1000 , 2000 ) ;
}
if ( V_3 & V_238 )
F_27 ( V_2 -> V_28 , L_9 ) ;
else
F_10 ( V_2 -> V_28 , L_10 , V_48 ) ;
F_63 ( V_2 , 1 ) ;
}
static int F_69 ( struct V_1 * V_2 )
{
const struct V_234 * V_235 = V_2 -> V_235 . V_7 ;
unsigned int V_48 ;
T_1 V_3 ;
if ( V_235 -> V_236 == 1 ) {
F_60 ( V_2 , false ) ;
F_61 ( V_2 , 0 ) ;
F_61 ( V_2 , 1 ) ;
return 0 ;
}
F_64 ( V_2 , 1 ) ;
F_63 ( V_2 , 0 ) ;
for ( V_48 = 0 ; V_48 < 5 ; ++ V_48 ) {
V_3 = F_3 ( V_2 , V_237 ) & V_238 ;
if ( V_3 )
break;
F_68 ( 1000 , 2000 ) ;
}
if ( ! V_3 ) {
F_70 ( V_2 -> V_28 , L_11 ) ;
return - V_239 ;
}
F_10 ( V_2 -> V_28 , L_12 , V_48 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 ,
const struct V_240 * V_241 ,
unsigned long V_97 )
{
const struct V_242 * V_243 = V_241 -> V_244 ;
const struct V_245 * V_246 = V_241 -> V_247 ;
const struct V_248 * V_249 = V_241 -> V_249 ;
for (; V_243 -> V_97 != ~ 0UL ; V_243 ++ )
if ( V_97 <= V_243 -> V_97 )
break;
for (; V_246 -> V_97 != ~ 0UL ; V_246 ++ )
if ( V_97 <= V_246 -> V_97 )
break;
for (; V_249 -> V_97 != ~ 0UL ; V_249 ++ )
if ( V_97 <= V_249 -> V_97 )
break;
if ( V_243 -> V_97 == ~ 0UL ||
V_246 -> V_97 == ~ 0UL ||
V_249 -> V_97 == ~ 0UL )
return - V_250 ;
F_59 ( V_2 , V_243 -> V_251 [ 0 ] . V_252 ,
V_253 ) ;
F_59 ( V_2 , V_243 -> V_251 [ 0 ] . V_254 ,
V_255 ) ;
F_59 ( V_2 , V_246 -> V_256 [ 0 ] ,
V_257 ) ;
F_59 ( V_2 , 0 , V_258 ) ;
F_59 ( V_2 , V_259 ,
V_260 ) ;
F_59 ( V_2 , V_249 -> V_261 , V_262 ) ;
F_59 ( V_2 , V_249 -> V_263 ,
V_264 ) ;
F_59 ( V_2 , V_249 -> V_265 ,
V_266 ) ;
F_59 ( V_2 , V_267 ,
V_268 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 )
{
const struct V_234 * V_235 = V_2 -> V_235 . V_7 ;
const struct V_240 * V_241 = V_2 -> V_269 ;
unsigned long V_97 = V_2 -> V_95 . V_96 . V_97 ;
int V_49 ;
F_67 ( V_2 ) ;
if ( V_235 -> V_270 )
F_62 ( V_2 , 1 ) ;
F_1 ( V_2 , V_271 , V_272 ) ;
F_1 ( V_2 , 0 , V_272 ) ;
F_1 ( V_2 , V_273 , V_274 ) ;
F_56 ( V_2 , 1 ) ;
F_1 ( V_2 , V_275 ,
V_276 ) ;
F_56 ( V_2 , 0 ) ;
if ( V_241 -> V_277 )
V_49 = V_241 -> V_277 ( V_2 , V_241 , V_97 ) ;
else
V_49 = V_235 -> V_278 ( V_2 , V_241 , V_97 ) ;
if ( V_49 ) {
F_70 ( V_2 -> V_28 , L_13 ,
V_97 ) ;
return V_49 ;
}
return F_69 ( V_2 ) ;
}
static int F_73 ( struct V_1 * V_2 , void * V_7 ,
struct V_279 * V_280 )
{
int V_48 , V_49 ;
for ( V_48 = 0 ; V_48 < 2 ; V_48 ++ ) {
F_65 ( V_2 , 1 ) ;
F_66 ( V_2 , 0 ) ;
V_49 = F_72 ( V_2 ) ;
if ( V_49 )
return V_49 ;
}
return 0 ;
}
static void F_74 ( struct V_1 * V_2 , void * V_7 )
{
F_67 ( V_2 ) ;
}
static enum V_281 F_75 ( struct V_1 * V_2 ,
void * V_7 )
{
return F_3 ( V_2 , V_237 ) & V_282 ?
V_283 : V_284 ;
}
static void F_76 ( struct V_1 * V_2 , void * V_7 ,
bool V_285 , bool V_286 , bool V_287 )
{
T_1 V_288 = V_2 -> V_289 ;
if ( V_285 || V_286 || ! V_287 )
V_2 -> V_289 |= V_290 ;
else
V_2 -> V_289 &= ~ V_290 ;
if ( V_288 != V_2 -> V_289 )
F_1 ( V_2 , V_2 -> V_289 , V_291 ) ;
}
static void F_77 ( struct V_1 * V_2 , void * V_7 )
{
F_1 ( V_2 , V_282 | V_290 , V_292 ) ;
F_1 ( V_2 , V_293 | V_294 ,
V_295 ) ;
F_1 ( V_2 , V_2 -> V_289 , V_291 ) ;
F_1 ( V_2 , V_293 | V_294 ,
V_295 ) ;
F_1 ( V_2 , ~ ( V_293 | V_294 ) ,
V_296 ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
T_1 V_297 ;
if ( V_2 -> V_95 . V_96 . V_298 )
V_297 = V_299 ;
else
V_297 = V_300 ;
F_5 ( V_2 , V_301 ,
V_302 , V_303 ) ;
F_5 ( V_2 , V_297 , V_304 , V_305 ) ;
F_5 ( V_2 , V_306 ,
V_307 , V_308 ) ;
}
static void F_79 ( struct V_1 * V_2 , struct V_279 * V_280 )
{
struct V_309 V_310 ;
T_1 V_3 ;
F_80 ( & V_310 , V_280 ) ;
if ( F_44 ( V_2 -> V_95 . V_131 ) )
V_310 . V_311 = V_312 ;
else if ( F_45 ( V_2 -> V_95 . V_131 ) )
V_310 . V_311 = V_313 ;
else
V_310 . V_311 = V_314 ;
switch ( V_2 -> V_95 . V_135 ) {
case V_136 :
if ( V_2 -> V_95 . V_315 == V_316 )
V_310 . V_317 = V_318 ;
else
V_310 . V_317 = V_319 ;
V_310 . V_320 =
V_321 ;
break;
case V_322 :
if ( V_2 -> V_95 . V_315 == V_323 )
V_310 . V_317 = V_318 ;
else
V_310 . V_317 = V_324 ;
V_310 . V_320 =
V_325 ;
break;
default:
V_310 . V_317 = V_319 ;
V_310 . V_320 =
V_321 ;
break;
}
V_310 . V_326 = V_327 ;
V_3 = ( V_310 . V_326 & 3 ) << 4 | ( V_310 . V_311 & 3 ) ;
if ( V_310 . V_328 & 15 )
V_3 |= V_329 ;
if ( V_310 . V_330 || V_310 . V_331 )
V_3 |= V_332 ;
if ( V_310 . V_333 || V_310 . V_334 )
V_3 |= V_335 ;
F_1 ( V_2 , V_3 , V_336 ) ;
V_3 = ( ( V_310 . V_317 & 0x3 ) << 6 ) |
( ( V_310 . V_337 & 0x3 ) << 4 ) |
( V_310 . V_328 & 0xf ) ;
F_1 ( V_2 , V_3 , V_338 ) ;
V_3 = ( ( V_310 . V_320 & 0x7 ) << 4 ) |
( ( V_310 . V_339 & 0x3 ) << 2 ) |
( V_310 . V_340 & 0x3 ) ;
if ( V_310 . V_341 )
V_3 |= V_342 ;
F_1 ( V_2 , V_3 , V_343 ) ;
V_3 = V_310 . V_344 & 0x7f ;
F_1 ( V_2 , V_3 , V_345 ) ;
V_3 = ( ( ( V_2 -> V_95 . V_96 . V_346 + 1 ) <<
V_347 ) &
V_348 ) |
( ( V_2 -> V_95 . V_96 . V_349 <<
V_350 ) &
V_351 ) ;
F_1 ( V_2 , V_3 , V_352 ) ;
V_3 = ( ( V_310 . V_353 & 0x3 ) << 2 ) |
( V_310 . V_354 & 0x3 ) ;
F_1 ( V_2 , V_3 , V_355 ) ;
F_1 ( V_2 , V_310 . V_330 & 0xff , V_356 ) ;
F_1 ( V_2 , ( V_310 . V_330 >> 8 ) & 0xff , V_357 ) ;
F_1 ( V_2 , V_310 . V_331 & 0xff , V_358 ) ;
F_1 ( V_2 , ( V_310 . V_331 >> 8 ) & 0xff , V_359 ) ;
F_1 ( V_2 , V_310 . V_333 & 0xff , V_360 ) ;
F_1 ( V_2 , ( V_310 . V_333 >> 8 ) & 0xff , V_361 ) ;
F_1 ( V_2 , V_310 . V_334 & 0xff , V_362 ) ;
F_1 ( V_2 , ( V_310 . V_334 >> 8 ) & 0xff , V_363 ) ;
}
static void F_81 ( struct V_1 * V_2 ,
struct V_279 * V_280 )
{
struct V_364 V_310 ;
T_1 V_365 [ 10 ] ;
T_4 V_366 ;
V_366 = F_82 ( & V_310 , V_280 ) ;
if ( V_366 < 0 )
return;
V_366 = F_83 ( & V_310 , V_365 , sizeof( V_365 ) ) ;
if ( V_366 < 0 ) {
F_70 ( V_2 -> V_28 , L_14 ,
V_366 ) ;
return;
}
F_7 ( V_2 , 0 , V_367 , V_368 ,
V_369 ) ;
F_1 ( V_2 , V_365 [ 2 ] , V_370 ) ;
F_1 ( V_2 , V_365 [ 4 ] , V_371 ) ;
F_1 ( V_2 , V_365 [ 5 ] , V_372 ) ;
F_1 ( V_2 , V_365 [ 6 ] , V_373 ) ;
F_1 ( V_2 , V_365 [ 7 ] , V_374 ) ;
F_1 ( V_2 , V_365 [ 8 ] , V_375 ) ;
if ( V_310 . V_376 >= V_377 )
F_1 ( V_2 , V_365 [ 9 ] , V_378 ) ;
F_1 ( V_2 , 1 , V_379 ) ;
F_1 ( V_2 , 0x11 , V_380 ) ;
F_7 ( V_2 , 1 , V_367 , V_368 ,
V_369 ) ;
}
static void F_84 ( struct V_1 * V_2 ,
const struct V_279 * V_280 )
{
T_1 V_381 ;
struct V_382 * V_383 = & V_2 -> V_95 . V_96 ;
int V_384 , V_385 , V_386 , V_387 , V_388 , V_389 ;
unsigned int V_390 ;
V_383 -> V_97 = V_280 -> clock * 1000 ;
F_10 ( V_2 -> V_28 , L_15 , V_383 -> V_97 ) ;
V_381 = ( V_2 -> V_95 . V_391 ?
V_392 :
V_393 ) ;
V_381 |= V_280 -> V_54 & V_394 ?
V_395 :
V_396 ;
V_381 |= V_280 -> V_54 & V_397 ?
V_398 :
V_399 ;
V_381 |= ( V_383 -> V_298 ?
V_400 :
V_401 ) ;
if ( V_2 -> V_402 == 39 )
V_381 |= V_403 ;
else
V_381 |= V_280 -> V_54 & V_404 ?
V_403 :
V_405 ;
V_381 |= V_280 -> V_54 & V_404 ?
V_406 :
V_407 ;
V_381 |= V_2 -> V_408 ?
V_409 :
V_410 ;
F_1 ( V_2 , V_381 , V_411 ) ;
V_390 = V_280 -> V_390 ;
V_385 = V_280 -> V_412 - V_280 -> V_390 ;
V_387 = V_280 -> V_413 - V_280 -> V_390 ;
V_389 = V_280 -> V_414 - V_280 -> V_413 ;
if ( V_280 -> V_54 & V_404 ) {
V_390 /= 2 ;
V_385 /= 2 ;
V_387 /= 2 ;
V_389 /= 2 ;
}
F_1 ( V_2 , V_280 -> V_415 >> 8 , V_416 ) ;
F_1 ( V_2 , V_280 -> V_415 , V_417 ) ;
F_1 ( V_2 , V_390 >> 8 , V_418 ) ;
F_1 ( V_2 , V_390 , V_419 ) ;
V_384 = V_280 -> V_420 - V_280 -> V_415 ;
F_1 ( V_2 , V_384 >> 8 , V_421 ) ;
F_1 ( V_2 , V_384 , V_422 ) ;
F_1 ( V_2 , V_385 , V_423 ) ;
V_386 = V_280 -> V_424 - V_280 -> V_415 ;
F_1 ( V_2 , V_386 >> 8 , V_425 ) ;
F_1 ( V_2 , V_386 , V_426 ) ;
F_1 ( V_2 , V_387 , V_427 ) ;
V_388 = V_280 -> V_428 - V_280 -> V_424 ;
F_1 ( V_2 , V_388 >> 8 , V_429 ) ;
F_1 ( V_2 , V_388 , V_430 ) ;
F_1 ( V_2 , V_389 , V_431 ) ;
}
static void F_85 ( struct V_1 * V_2 )
{
T_1 V_432 ;
F_1 ( V_2 , 12 , V_433 ) ;
F_1 ( V_2 , 32 , V_434 ) ;
F_1 ( V_2 , 1 , V_435 ) ;
F_1 ( V_2 , 0x0B , V_436 ) ;
F_1 ( V_2 , 0x16 , V_437 ) ;
F_1 ( V_2 , 0x21 , V_438 ) ;
V_432 = 0x7F ;
V_432 &= ~ V_439 ;
F_1 ( V_2 , V_432 , V_440 ) ;
V_432 &= ~ V_441 ;
F_1 ( V_2 , V_432 , V_440 ) ;
if ( F_48 ( V_2 ) ) {
V_432 &= ~ V_442 ;
F_1 ( V_2 , V_432 , V_440 ) ;
}
if ( F_48 ( V_2 ) )
F_1 ( V_2 , V_443 ,
V_444 ) ;
else
F_1 ( V_2 , V_445 ,
V_444 ) ;
}
static void F_86 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0 , V_446 , V_440 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
unsigned int V_447 ;
unsigned int V_48 ;
T_1 V_3 ;
switch ( V_2 -> V_448 ) {
case 0x130a :
V_447 = 4 ;
break;
case 0x131a :
V_447 = 1 ;
break;
default:
return;
}
F_1 ( V_2 , ( T_1 ) ~ V_449 , V_450 ) ;
V_3 = F_3 ( V_2 , V_411 ) ;
for ( V_48 = 0 ; V_48 < V_447 ; V_48 ++ )
F_1 ( V_2 , V_3 , V_411 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0 , V_451 ) ;
F_1 ( V_2 , 0 , V_452 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_453 ,
V_452 ) ;
}
static int F_90 ( struct V_1 * V_2 , struct V_279 * V_280 )
{
int V_49 ;
F_89 ( V_2 ) ;
V_2 -> V_402 = F_91 ( V_280 ) ;
if ( ! V_2 -> V_402 ) {
F_10 ( V_2 -> V_28 , L_16 ) ;
} else {
F_10 ( V_2 -> V_28 , L_17 , V_2 -> V_402 ) ;
}
if ( ( V_2 -> V_402 == 6 ) || ( V_2 -> V_402 == 7 ) ||
( V_2 -> V_402 == 21 ) || ( V_2 -> V_402 == 22 ) ||
( V_2 -> V_402 == 2 ) || ( V_2 -> V_402 == 3 ) ||
( V_2 -> V_402 == 17 ) || ( V_2 -> V_402 == 18 ) )
V_2 -> V_95 . V_135 = V_136 ;
else
V_2 -> V_95 . V_135 = V_322 ;
V_2 -> V_95 . V_96 . V_349 = 0 ;
V_2 -> V_95 . V_96 . V_346 = 0 ;
if ( V_2 -> V_269 -> V_454 )
V_2 -> V_95 . V_116 =
V_2 -> V_269 -> V_454 ;
else
V_2 -> V_95 . V_116 = V_100 ;
if ( V_2 -> V_269 -> V_455 )
V_2 -> V_95 . V_315 =
V_2 -> V_269 -> V_455 ;
else
V_2 -> V_95 . V_315 = V_456 ;
V_2 -> V_95 . V_131 = V_100 ;
V_2 -> V_95 . V_176 = 0 ;
V_2 -> V_95 . V_391 = 0 ;
V_2 -> V_95 . V_96 . V_298 = true ;
F_84 ( V_2 , V_280 ) ;
V_49 = V_2 -> V_235 . V_457 -> V_458 ( V_2 , V_2 -> V_235 . V_7 , & V_2 -> V_459 ) ;
if ( V_49 )
return V_49 ;
V_2 -> V_235 . V_460 = true ;
F_85 ( V_2 ) ;
if ( V_2 -> V_461 ) {
F_10 ( V_2 -> V_28 , L_18 ) ;
F_37 ( V_2 ) ;
F_86 ( V_2 ) ;
}
if ( V_2 -> V_408 ) {
F_10 ( V_2 -> V_28 , L_19 , V_89 ) ;
F_79 ( V_2 , V_280 ) ;
F_81 ( V_2 , V_280 ) ;
} else {
F_10 ( V_2 -> V_28 , L_20 , V_89 ) ;
}
F_55 ( V_2 ) ;
F_54 ( V_2 ) ;
F_47 ( V_2 ) ;
F_78 ( V_2 ) ;
F_87 ( V_2 ) ;
if ( V_2 -> V_462 && V_2 -> V_408 )
F_88 ( V_2 ) ;
return 0 ;
}
static void F_92 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_463 ,
V_464 ) ;
F_1 ( V_2 , V_465 |
V_466 ,
V_467 ) ;
}
static void F_93 ( struct V_1 * V_2 )
{
T_1 V_468 ;
V_468 = F_3 ( V_2 , V_469 ) |
V_470 |
V_471 ;
F_1 ( V_2 , V_468 , V_469 ) ;
F_1 ( V_2 , 0xff , V_472 ) ;
F_1 ( V_2 , 0xff , V_473 ) ;
F_1 ( V_2 , 0xff , V_474 ) ;
F_1 ( V_2 , 0xff , V_451 ) ;
F_1 ( V_2 , 0xff , V_291 ) ;
F_1 ( V_2 , 0xff , V_464 ) ;
F_1 ( V_2 , 0xff , V_467 ) ;
F_1 ( V_2 , 0xff , V_475 ) ;
F_1 ( V_2 , 0xff , V_476 ) ;
F_1 ( V_2 , 0xff , V_477 ) ;
F_1 ( V_2 , 0xff , V_478 ) ;
F_1 ( V_2 , 0xff , V_479 ) ;
F_1 ( V_2 , 0xff , V_480 ) ;
F_1 ( V_2 , 0xff , V_14 ) ;
F_1 ( V_2 , 0xff , V_17 ) ;
F_1 ( V_2 , 0xff , V_481 ) ;
F_1 ( V_2 , 0xff , V_482 ) ;
F_1 ( V_2 , 0xff , V_452 ) ;
F_1 ( V_2 , 0xff , V_483 ) ;
F_1 ( V_2 , 0xff , V_296 ) ;
F_1 ( V_2 , 0xff , V_21 ) ;
F_1 ( V_2 , 0xff , V_484 ) ;
F_1 ( V_2 , 0xff , V_485 ) ;
F_1 ( V_2 , 0xff , V_486 ) ;
F_1 ( V_2 , 0xff , V_487 ) ;
V_468 &= ~ ( V_470 |
V_471 ) ;
F_1 ( V_2 , V_468 , V_469 ) ;
}
static void F_94 ( struct V_1 * V_2 )
{
V_2 -> V_488 = true ;
F_90 ( V_2 , & V_2 -> V_459 ) ;
}
static void F_95 ( struct V_1 * V_2 )
{
if ( V_2 -> V_235 . V_460 ) {
V_2 -> V_235 . V_457 -> V_489 ( V_2 , V_2 -> V_235 . V_7 ) ;
V_2 -> V_235 . V_460 = false ;
}
V_2 -> V_488 = false ;
}
static void F_96 ( struct V_1 * V_2 )
{
int V_285 = V_2 -> V_285 ;
if ( V_2 -> V_286 ) {
V_285 = V_490 ;
} else if ( V_285 == V_491 ) {
if ( V_2 -> V_287 )
V_285 = V_492 ;
else
V_285 = V_490 ;
}
if ( V_285 == V_490 ) {
if ( V_2 -> V_488 )
F_95 ( V_2 ) ;
} else {
if ( ! V_2 -> V_488 )
F_94 ( V_2 ) ;
}
}
static void F_97 ( struct V_1 * V_2 )
{
if ( V_2 -> V_235 . V_457 -> V_493 )
V_2 -> V_235 . V_457 -> V_493 ( V_2 , V_2 -> V_235 . V_7 ,
V_2 -> V_285 , V_2 -> V_286 ,
V_2 -> V_287 ) ;
}
static enum V_281
F_98 ( struct V_494 * V_495 , bool V_285 )
{
struct V_1 * V_2 = F_99 ( V_495 , struct V_1 ,
V_495 ) ;
F_16 ( & V_2 -> V_496 ) ;
V_2 -> V_285 = V_491 ;
F_96 ( V_2 ) ;
F_97 ( V_2 ) ;
F_17 ( & V_2 -> V_496 ) ;
return V_2 -> V_235 . V_457 -> V_497 ( V_2 , V_2 -> V_235 . V_7 ) ;
}
static int F_100 ( struct V_494 * V_495 )
{
struct V_1 * V_2 = F_99 ( V_495 , struct V_1 ,
V_495 ) ;
struct V_498 * V_498 ;
int V_49 = 0 ;
if ( ! V_2 -> V_499 )
return 0 ;
V_498 = F_101 ( V_495 , V_2 -> V_499 ) ;
if ( V_498 ) {
F_10 ( V_2 -> V_28 , L_21 ,
V_498 -> V_500 , V_498 -> V_501 ) ;
V_2 -> V_408 = F_102 ( V_498 ) ;
V_2 -> V_461 = F_103 ( V_498 ) ;
F_104 ( V_495 , V_498 ) ;
V_49 = F_105 ( V_495 , V_498 ) ;
F_106 ( V_495 , V_498 ) ;
F_107 ( V_498 ) ;
} else {
F_10 ( V_2 -> V_28 , L_22 ) ;
}
return V_49 ;
}
static enum V_502
F_108 ( struct V_494 * V_495 ,
struct V_279 * V_280 )
{
struct V_1 * V_2 = F_99 ( V_495 ,
struct V_1 , V_495 ) ;
enum V_502 V_503 = V_504 ;
if ( V_280 -> V_54 & V_505 )
return V_506 ;
if ( V_2 -> V_269 -> V_507 )
V_503 = V_2 -> V_269 -> V_507 ( V_495 , V_280 ) ;
return V_503 ;
}
static void F_109 ( struct V_494 * V_495 )
{
struct V_1 * V_2 = F_99 ( V_495 , struct V_1 ,
V_495 ) ;
F_16 ( & V_2 -> V_496 ) ;
V_2 -> V_285 = V_495 -> V_285 ;
F_96 ( V_2 ) ;
F_97 ( V_2 ) ;
F_17 ( & V_2 -> V_496 ) ;
}
static int F_110 ( struct V_508 * V_509 )
{
struct V_1 * V_2 = V_509 -> V_510 ;
struct V_511 * V_512 = V_509 -> V_512 ;
struct V_494 * V_495 = & V_2 -> V_495 ;
V_495 -> V_513 = 1 ;
V_495 -> V_514 = V_515 ;
F_111 ( V_495 , & V_516 ) ;
F_112 ( V_509 -> V_28 , V_495 , & V_517 ,
V_518 ) ;
F_113 ( V_495 , V_512 ) ;
return 0 ;
}
static bool F_114 ( struct V_508 * V_509 ,
const struct V_279 * V_519 ,
struct V_279 * V_280 )
{
struct V_1 * V_2 = V_509 -> V_510 ;
struct V_494 * V_495 = & V_2 -> V_495 ;
enum V_502 V_520 ;
V_520 = F_108 ( V_495 , V_280 ) ;
if ( V_520 != V_504 )
return false ;
return true ;
}
static void F_115 ( struct V_508 * V_509 ,
struct V_279 * V_519 ,
struct V_279 * V_280 )
{
struct V_1 * V_2 = V_509 -> V_510 ;
F_16 ( & V_2 -> V_496 ) ;
memcpy ( & V_2 -> V_459 , V_280 , sizeof( V_2 -> V_459 ) ) ;
F_17 ( & V_2 -> V_496 ) ;
}
static void F_116 ( struct V_508 * V_509 )
{
struct V_1 * V_2 = V_509 -> V_510 ;
F_16 ( & V_2 -> V_496 ) ;
V_2 -> V_286 = true ;
F_96 ( V_2 ) ;
F_97 ( V_2 ) ;
F_17 ( & V_2 -> V_496 ) ;
}
static void F_117 ( struct V_508 * V_509 )
{
struct V_1 * V_2 = V_509 -> V_510 ;
F_16 ( & V_2 -> V_496 ) ;
V_2 -> V_286 = false ;
F_96 ( V_2 ) ;
F_97 ( V_2 ) ;
F_17 ( & V_2 -> V_496 ) ;
}
static T_5 F_118 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_25 ;
unsigned int V_26 ;
V_26 = F_3 ( V_2 , V_20 ) ;
if ( ! V_26 )
return V_521 ;
F_1 ( V_2 , V_26 , V_20 ) ;
V_25 -> V_26 = V_26 ;
F_119 ( & V_25 -> V_30 ) ;
return V_522 ;
}
static T_5 F_120 ( int V_523 , void * V_524 )
{
struct V_1 * V_2 = V_524 ;
T_1 V_525 ;
T_5 V_49 = V_521 ;
if ( V_2 -> V_25 )
V_49 = F_118 ( V_2 ) ;
V_525 = F_3 ( V_2 , V_295 ) ;
if ( V_525 ) {
F_1 ( V_2 , ~ 0 , V_296 ) ;
return V_526 ;
}
return V_49 ;
}
void F_121 ( struct V_1 * V_2 , bool V_527 , bool V_528 )
{
F_16 ( & V_2 -> V_496 ) ;
if ( ! V_2 -> V_285 ) {
if ( ! V_528 )
V_2 -> V_287 = false ;
if ( V_527 )
V_2 -> V_287 = true ;
F_96 ( V_2 ) ;
F_97 ( V_2 ) ;
}
F_17 ( & V_2 -> V_496 ) ;
}
void F_122 ( struct V_529 * V_28 , bool V_527 , bool V_528 )
{
struct V_1 * V_2 = F_123 ( V_28 ) ;
F_121 ( V_2 , V_527 , V_528 ) ;
}
static T_5 F_124 ( int V_523 , void * V_524 )
{
struct V_1 * V_2 = V_524 ;
T_1 V_525 , V_530 , V_531 , V_532 ;
V_525 = F_3 ( V_2 , V_295 ) ;
V_530 = F_3 ( V_2 , V_292 ) ;
V_532 = F_3 ( V_2 , V_237 ) ;
V_531 = 0 ;
if ( V_525 & V_293 )
V_531 |= V_282 ;
if ( V_525 & V_533 )
V_531 |= V_534 ;
if ( V_525 & V_535 )
V_531 |= V_536 ;
if ( V_525 & V_537 )
V_531 |= V_538 ;
if ( V_525 & V_539 )
V_531 |= V_540 ;
if ( V_531 )
F_5 ( V_2 , ~ V_530 , V_531 , V_292 ) ;
if ( V_525 &
( V_294 | V_293 ) )
F_121 ( V_2 ,
V_532 & V_282 ,
V_532 & V_290 ) ;
if ( V_525 & V_293 ) {
F_10 ( V_2 -> V_28 , L_23 ,
V_530 & V_282 ? L_24 : L_25 ) ;
if ( V_2 -> V_509 . V_28 )
F_125 ( V_2 -> V_509 . V_28 ) ;
}
F_1 ( V_2 , V_525 , V_295 ) ;
F_1 ( V_2 , ~ ( V_293 | V_294 ) ,
V_296 ) ;
return V_522 ;
}
static int F_126 ( struct V_1 * V_2 )
{
unsigned int V_48 ;
T_1 V_541 ;
V_541 = F_3 ( V_2 , V_542 ) ;
if ( V_541 == V_543 ) {
if ( ! V_2 -> V_269 -> V_544 || ! V_2 -> V_269 -> V_545 ) {
F_70 ( V_2 -> V_28 ,
L_26 ) ;
return - V_546 ;
}
V_2 -> V_235 . V_457 = V_2 -> V_269 -> V_544 ;
V_2 -> V_235 . V_7 = V_2 -> V_269 -> V_547 ;
V_2 -> V_235 . V_71 = V_2 -> V_269 -> V_545 ;
return 0 ;
}
for ( V_48 = 0 ; V_48 < F_53 ( V_548 ) ; ++ V_48 ) {
if ( V_548 [ V_48 ] . type == V_541 ) {
V_2 -> V_235 . V_457 = & V_549 ;
V_2 -> V_235 . V_71 = V_548 [ V_48 ] . V_71 ;
V_2 -> V_235 . V_7 = ( void * ) & V_548 [ V_48 ] ;
if ( ! V_548 [ V_48 ] . V_278 &&
! V_2 -> V_269 -> V_277 ) {
F_70 ( V_2 -> V_28 , L_27 ,
V_2 -> V_235 . V_71 ) ;
return - V_546 ;
}
return 0 ;
}
}
F_70 ( V_2 -> V_28 , L_28 , V_541 ) ;
return - V_546 ;
}
static struct V_1 *
F_127 ( struct V_550 * V_551 ,
const struct V_240 * V_269 )
{
struct V_529 * V_28 = & V_551 -> V_28 ;
struct V_552 * V_553 = V_28 -> V_554 ;
struct V_555 V_556 ;
struct V_552 * V_557 ;
struct V_1 * V_2 ;
struct V_558 * V_559 = NULL ;
int V_523 ;
int V_49 ;
T_2 V_3 = 1 ;
T_1 V_560 ;
T_1 V_561 ;
T_1 V_562 ;
T_1 V_563 ;
V_2 = F_20 ( V_28 , sizeof( * V_2 ) , V_62 ) ;
if ( ! V_2 )
return F_21 ( - V_63 ) ;
V_2 -> V_269 = V_269 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_86 = 48000 ;
V_2 -> V_286 = true ;
V_2 -> V_287 = true ;
V_2 -> V_289 = ( T_1 ) ~ ( V_282 | V_290 ) ;
F_22 ( & V_2 -> V_496 ) ;
F_22 ( & V_2 -> V_94 ) ;
F_128 ( & V_2 -> V_90 ) ;
V_557 = F_129 ( V_553 , L_29 , 0 ) ;
if ( V_557 ) {
V_2 -> V_499 = F_130 ( V_557 ) ;
F_131 ( V_557 ) ;
if ( ! V_2 -> V_499 ) {
F_10 ( V_2 -> V_28 , L_30 ) ;
return F_21 ( - V_564 ) ;
}
} else {
F_10 ( V_2 -> V_28 , L_31 ) ;
}
if ( ! V_269 -> V_5 ) {
const struct V_565 * V_566 ;
F_132 ( V_553 , L_32 , & V_3 ) ;
switch ( V_3 ) {
case 4 :
V_566 = & V_567 ;
V_2 -> V_6 = 2 ;
break;
case 1 :
V_566 = & V_568 ;
break;
default:
F_70 ( V_28 , L_33 ) ;
return F_21 ( - V_250 ) ;
}
V_559 = F_133 ( V_551 , V_569 , 0 ) ;
V_2 -> V_570 = F_134 ( V_28 , V_559 ) ;
if ( F_135 ( V_2 -> V_570 ) ) {
V_49 = F_136 ( V_2 -> V_570 ) ;
goto V_571;
}
V_2 -> V_5 = F_137 ( V_28 , V_2 -> V_570 , V_566 ) ;
if ( F_135 ( V_2 -> V_5 ) ) {
F_70 ( V_28 , L_34 ) ;
V_49 = F_136 ( V_2 -> V_5 ) ;
goto V_571;
}
} else {
V_2 -> V_5 = V_269 -> V_5 ;
}
V_2 -> V_572 = F_138 ( V_2 -> V_28 , L_35 ) ;
if ( F_135 ( V_2 -> V_572 ) ) {
V_49 = F_136 ( V_2 -> V_572 ) ;
F_70 ( V_2 -> V_28 , L_36 , V_49 ) ;
goto V_571;
}
V_49 = F_139 ( V_2 -> V_572 ) ;
if ( V_49 ) {
F_70 ( V_2 -> V_28 , L_37 , V_49 ) ;
goto V_571;
}
V_2 -> V_573 = F_138 ( V_2 -> V_28 , L_38 ) ;
if ( F_135 ( V_2 -> V_573 ) ) {
V_49 = F_136 ( V_2 -> V_573 ) ;
F_70 ( V_2 -> V_28 , L_39 , V_49 ) ;
goto V_574;
}
V_49 = F_139 ( V_2 -> V_573 ) ;
if ( V_49 ) {
F_70 ( V_2 -> V_28 , L_40 , V_49 ) ;
goto V_574;
}
V_2 -> V_448 = ( F_3 ( V_2 , V_575 ) << 8 )
| ( F_3 ( V_2 , V_576 ) << 0 ) ;
V_560 = F_3 ( V_2 , V_577 ) ;
V_561 = F_3 ( V_2 , V_578 ) ;
if ( V_560 != V_579 ||
( V_561 & ~ V_580 ) != V_581 ) {
F_70 ( V_28 , L_41 ,
V_2 -> V_448 , V_560 , V_561 ) ;
V_49 = - V_546 ;
goto V_582;
}
V_49 = F_126 ( V_2 ) ;
if ( V_49 < 0 )
goto V_582;
F_29 ( V_28 , L_42 ,
V_2 -> V_448 >> 12 , V_2 -> V_448 & 0xfff ,
V_561 & V_580 ? L_43 : L_44 ,
V_2 -> V_235 . V_71 ) ;
F_93 ( V_2 ) ;
V_523 = F_140 ( V_551 , 0 ) ;
if ( V_523 < 0 ) {
V_49 = V_523 ;
goto V_582;
}
V_49 = F_141 ( V_28 , V_523 , F_120 ,
F_124 , V_583 ,
F_142 ( V_28 ) , V_2 ) ;
if ( V_49 )
goto V_582;
F_36 ( V_2 ) ;
if ( ! V_2 -> V_499 ) {
V_2 -> V_499 = F_19 ( V_2 ) ;
if ( F_135 ( V_2 -> V_499 ) )
V_2 -> V_499 = NULL ;
}
V_2 -> V_509 . V_510 = V_2 ;
V_2 -> V_509 . V_584 = & V_585 ;
#ifdef F_143
V_2 -> V_509 . V_554 = V_551 -> V_28 . V_554 ;
#endif
F_92 ( V_2 ) ;
if ( V_2 -> V_235 . V_457 -> V_586 )
V_2 -> V_235 . V_457 -> V_586 ( V_2 , V_2 -> V_235 . V_7 ) ;
memset ( & V_556 , 0 , sizeof( V_556 ) ) ;
V_556 . V_68 = V_28 ;
V_556 . V_587 = V_588 ;
V_562 = F_3 ( V_2 , V_589 ) ;
V_563 = F_3 ( V_2 , V_590 ) ;
if ( V_559 && V_563 & V_591 ) {
struct V_592 V_593 ;
V_593 . V_594 = V_559 -> V_595 ;
V_593 . V_596 = V_2 -> V_570 ;
V_593 . V_523 = V_523 ;
V_593 . V_2 = V_2 ;
V_593 . V_597 = V_2 -> V_495 . V_597 ;
V_556 . V_71 = L_45 ;
V_556 . V_7 = & V_593 ;
V_556 . V_598 = sizeof( V_593 ) ;
V_556 . V_599 = F_144 ( 32 ) ;
V_2 -> V_593 = F_145 ( & V_556 ) ;
} else if ( V_562 & V_600 ) {
struct V_601 V_593 ;
V_593 . V_2 = V_2 ;
V_593 . V_602 = F_1 ;
V_593 . V_603 = F_3 ;
V_556 . V_71 = L_46 ;
V_556 . V_7 = & V_593 ;
V_556 . V_598 = sizeof( V_593 ) ;
V_556 . V_599 = F_144 ( 32 ) ;
V_2 -> V_593 = F_145 ( & V_556 ) ;
}
if ( V_2 -> V_25 )
F_8 ( V_2 ) ;
F_146 ( V_551 , V_2 ) ;
return V_2 ;
V_582:
if ( V_2 -> V_25 ) {
F_147 ( & V_2 -> V_25 -> V_43 ) ;
V_2 -> V_499 = NULL ;
}
F_148 ( V_2 -> V_573 ) ;
V_574:
F_148 ( V_2 -> V_572 ) ;
V_571:
F_149 ( V_2 -> V_499 ) ;
return F_21 ( V_49 ) ;
}
static void F_150 ( struct V_1 * V_2 )
{
if ( V_2 -> V_593 && ! F_135 ( V_2 -> V_593 ) )
F_151 ( V_2 -> V_593 ) ;
F_1 ( V_2 , ~ 0 , V_296 ) ;
F_148 ( V_2 -> V_573 ) ;
F_148 ( V_2 -> V_572 ) ;
if ( V_2 -> V_25 )
F_147 ( & V_2 -> V_25 -> V_43 ) ;
else
F_149 ( V_2 -> V_499 ) ;
}
int F_152 ( struct V_550 * V_551 ,
const struct V_240 * V_269 )
{
struct V_1 * V_2 ;
int V_49 ;
V_2 = F_127 ( V_551 , V_269 ) ;
if ( F_135 ( V_2 ) )
return F_136 ( V_2 ) ;
V_49 = F_153 ( & V_2 -> V_509 ) ;
if ( V_49 < 0 ) {
F_150 ( V_2 ) ;
return V_49 ;
}
return 0 ;
}
void F_154 ( struct V_550 * V_551 )
{
struct V_1 * V_2 = F_155 ( V_551 ) ;
F_156 ( & V_2 -> V_509 ) ;
F_150 ( V_2 ) ;
}
int F_157 ( struct V_550 * V_551 , struct V_511 * V_512 ,
const struct V_240 * V_269 )
{
struct V_1 * V_2 ;
int V_49 ;
V_2 = F_127 ( V_551 , V_269 ) ;
if ( F_135 ( V_2 ) )
return F_136 ( V_2 ) ;
V_49 = F_158 ( V_512 , & V_2 -> V_509 , NULL ) ;
if ( V_49 ) {
F_154 ( V_551 ) ;
F_159 ( L_47 ) ;
return V_49 ;
}
return 0 ;
}
void F_160 ( struct V_529 * V_28 )
{
struct V_1 * V_2 = F_123 ( V_28 ) ;
F_150 ( V_2 ) ;
}
