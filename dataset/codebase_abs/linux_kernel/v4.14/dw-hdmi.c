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
static void F_39 ( struct V_1 * V_2 , bool V_99 )
{
if ( V_99 )
V_2 -> V_100 &= ~ V_101 ;
else
V_2 -> V_100 |= V_101 ;
F_1 ( V_2 , V_2 -> V_100 , V_102 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
F_30 ( V_2 , V_2 -> V_92 , V_2 -> V_91 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
F_30 ( V_2 , V_2 -> V_92 , 0 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_30 ( V_2 , V_2 -> V_92 , V_2 -> V_91 ) ;
F_39 ( V_2 , true ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
F_39 ( V_2 , false ) ;
}
void F_44 ( struct V_1 * V_2 )
{
unsigned long V_54 ;
F_45 ( & V_2 -> V_90 , V_54 ) ;
V_2 -> V_93 = true ;
if ( V_2 -> V_103 )
V_2 -> V_103 ( V_2 ) ;
F_46 ( & V_2 -> V_90 , V_54 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
unsigned long V_54 ;
F_45 ( & V_2 -> V_90 , V_54 ) ;
V_2 -> V_93 = false ;
if ( V_2 -> V_104 )
V_2 -> V_104 ( V_2 ) ;
F_46 ( & V_2 -> V_90 , V_54 ) ;
}
static bool F_48 ( unsigned int V_105 )
{
switch ( V_105 ) {
case V_106 :
case V_107 :
case V_108 :
case V_109 :
return true ;
default:
return false ;
}
}
static bool F_49 ( unsigned int V_105 )
{
switch ( V_105 ) {
case V_110 :
case V_111 :
case V_112 :
case V_113 :
return true ;
default:
return false ;
}
}
static bool F_50 ( unsigned int V_105 )
{
switch ( V_105 ) {
case V_114 :
case V_115 :
case V_116 :
return true ;
default:
return false ;
}
}
static int F_51 ( unsigned int V_105 )
{
switch ( V_105 ) {
case V_106 :
case V_110 :
case V_114 :
case V_117 :
return 8 ;
case V_107 :
case V_111 :
case V_115 :
case V_118 :
return 10 ;
case V_108 :
case V_112 :
case V_116 :
case V_119 :
return 12 ;
case V_109 :
case V_113 :
case V_120 :
return 16 ;
default:
return 0 ;
}
}
static void F_52 ( struct V_1 * V_2 )
{
int V_121 = 0 ;
T_1 V_3 ;
switch ( V_2 -> V_95 . V_122 ) {
case V_106 :
V_121 = 0x01 ;
break;
case V_107 :
V_121 = 0x03 ;
break;
case V_108 :
V_121 = 0x05 ;
break;
case V_109 :
V_121 = 0x07 ;
break;
case V_110 :
case V_117 :
V_121 = 0x09 ;
break;
case V_111 :
case V_118 :
V_121 = 0x0B ;
break;
case V_112 :
case V_119 :
V_121 = 0x0D ;
break;
case V_113 :
case V_120 :
V_121 = 0x0F ;
break;
case V_114 :
V_121 = 0x16 ;
break;
case V_115 :
V_121 = 0x14 ;
break;
case V_116 :
V_121 = 0x12 ;
break;
default:
return;
}
V_3 = V_123 |
( ( V_121 << V_124 ) &
V_125 ) ;
F_1 ( V_2 , V_3 , V_126 ) ;
V_3 = V_127 |
V_128 |
V_129 ;
F_1 ( V_2 , V_3 , V_130 ) ;
F_1 ( V_2 , 0x0 , V_131 ) ;
F_1 ( V_2 , 0x0 , V_132 ) ;
F_1 ( V_2 , 0x0 , V_133 ) ;
F_1 ( V_2 , 0x0 , V_134 ) ;
F_1 ( V_2 , 0x0 , V_135 ) ;
F_1 ( V_2 , 0x0 , V_136 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
return V_2 -> V_95 . V_122 != V_2 -> V_95 . V_137 ;
}
static int F_54 ( struct V_1 * V_2 )
{
if ( ! F_50 ( V_2 -> V_95 . V_137 ) )
return 0 ;
if ( F_48 ( V_2 -> V_95 . V_122 ) ||
F_49 ( V_2 -> V_95 . V_122 ) )
return 1 ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
if ( ! F_50 ( V_2 -> V_95 . V_122 ) )
return 0 ;
if ( F_48 ( V_2 -> V_95 . V_137 ) ||
F_49 ( V_2 -> V_95 . V_137 ) )
return 1 ;
return 0 ;
}
static void F_56 ( struct V_1 * V_2 )
{
const F_57 ( * V_138 ) [ 3 ] [ 4 ] = & V_139 ;
unsigned V_48 ;
T_2 V_140 = 1 ;
if ( F_53 ( V_2 ) ) {
if ( F_48 ( V_2 -> V_95 . V_137 ) ) {
if ( V_2 -> V_95 . V_141 ==
V_142 )
V_138 = & V_143 ;
else
V_138 = & V_144 ;
} else if ( F_48 (
V_2 -> V_95 . V_122 ) ) {
if ( V_2 -> V_95 . V_141 ==
V_142 )
V_138 = & V_145 ;
else
V_138 = & V_146 ;
V_140 = 0 ;
}
}
for ( V_48 = 0 ; V_48 < F_58 ( V_139 [ 0 ] ) ; V_48 ++ ) {
F_57 V_147 = ( * V_138 ) [ 0 ] [ V_48 ] ;
F_57 V_148 = ( * V_138 ) [ 1 ] [ V_48 ] ;
F_57 V_149 = ( * V_138 ) [ 2 ] [ V_48 ] ;
F_1 ( V_2 , V_147 & 0xff , V_150 + V_48 * 2 ) ;
F_1 ( V_2 , V_147 >> 8 , V_151 + V_48 * 2 ) ;
F_1 ( V_2 , V_148 & 0xff , V_152 + V_48 * 2 ) ;
F_1 ( V_2 , V_148 >> 8 , V_153 + V_48 * 2 ) ;
F_1 ( V_2 , V_149 & 0xff , V_154 + V_48 * 2 ) ;
F_1 ( V_2 , V_149 >> 8 , V_155 + V_48 * 2 ) ;
}
F_5 ( V_2 , V_140 , V_156 ,
V_157 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
int V_158 = 0 ;
int V_159 = V_160 ;
int V_161 = 0 ;
if ( F_55 ( V_2 ) )
V_159 = V_162 ;
else if ( F_54 ( V_2 ) )
V_161 = V_163 ;
switch ( F_51 ( V_2 -> V_95 . V_137 ) ) {
case 8 :
V_158 = V_164 ;
break;
case 10 :
V_158 = V_165 ;
break;
case 12 :
V_158 = V_166 ;
break;
case 16 :
V_158 = V_167 ;
break;
default:
return;
}
F_1 ( V_2 , V_159 | V_161 , V_168 ) ;
F_5 ( V_2 , V_158 , V_169 ,
V_157 ) ;
F_56 ( V_2 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
unsigned int V_158 = 0 ;
unsigned int V_170 = V_171 ;
unsigned int V_172 = V_173 ;
struct V_174 * V_95 = & V_2 -> V_95 ;
T_1 V_3 , V_175 ;
if ( F_48 ( V_2 -> V_95 . V_137 ) ||
F_49 ( V_2 -> V_95 . V_137 ) ) {
switch ( F_51 (
V_2 -> V_95 . V_137 ) ) {
case 8 :
V_158 = 4 ;
V_172 = V_176 ;
break;
case 10 :
V_158 = 5 ;
break;
case 12 :
V_158 = 6 ;
break;
case 16 :
V_158 = 7 ;
break;
default:
V_172 = V_176 ;
}
} else if ( F_50 ( V_2 -> V_95 . V_137 ) ) {
switch ( F_51 (
V_2 -> V_95 . V_137 ) ) {
case 0 :
case 8 :
V_170 = V_171 ;
break;
case 10 :
V_170 = V_177 ;
break;
case 12 :
V_170 = V_178 ;
break;
default:
return;
}
V_172 = V_179 ;
} else {
return;
}
V_3 = ( ( V_158 << V_180 ) &
V_181 ) |
( ( V_95 -> V_182 <<
V_183 ) &
V_184 ) ;
F_1 ( V_2 , V_3 , V_185 ) ;
F_5 ( V_2 , V_186 ,
V_187 , V_188 ) ;
if ( V_95 -> V_182 > 1 ) {
V_175 = V_189 |
V_190 ;
} else {
V_175 = V_191 |
V_192 ;
}
F_5 ( V_2 , V_175 ,
V_193 |
V_194 , V_195 ) ;
F_5 ( V_2 , 1 << V_196 ,
V_197 , V_188 ) ;
F_1 ( V_2 , V_170 , V_198 ) ;
if ( V_172 == V_173 ) {
V_175 = V_199 |
V_200 |
V_201 ;
} else if ( V_172 == V_179 ) {
V_175 = V_199 |
V_202 |
V_203 ;
} else if ( V_172 == V_176 ) {
V_175 = V_204 |
V_202 |
V_201 ;
} else {
return;
}
F_5 ( V_2 , V_175 ,
V_205 | V_206 |
V_207 , V_195 ) ;
F_5 ( V_2 , V_208 |
V_209 ,
V_210 |
V_211 , V_188 ) ;
F_5 ( V_2 , V_172 , V_212 ,
V_195 ) ;
}
static inline void F_61 ( struct V_1 * V_2 ,
unsigned char V_213 )
{
F_5 ( V_2 , V_213 << V_214 ,
V_215 , V_216 ) ;
}
static bool F_62 ( struct V_1 * V_2 , int V_217 )
{
T_2 V_3 ;
while ( ( V_3 = F_3 ( V_2 , V_218 ) & 0x3 ) == 0 ) {
if ( V_217 -- == 0 )
return false ;
F_63 ( 1000 ) ;
}
F_1 ( V_2 , V_3 , V_218 ) ;
return true ;
}
void F_64 ( struct V_1 * V_2 , unsigned short V_7 ,
unsigned char V_47 )
{
F_1 ( V_2 , 0xFF , V_218 ) ;
F_1 ( V_2 , V_47 , V_219 ) ;
F_1 ( V_2 , ( unsigned char ) ( V_7 >> 8 ) ,
V_220 ) ;
F_1 ( V_2 , ( unsigned char ) ( V_7 >> 0 ) ,
V_221 ) ;
F_1 ( V_2 , V_222 ,
V_223 ) ;
F_62 ( V_2 , 1000 ) ;
}
static void F_65 ( struct V_1 * V_2 , bool V_99 )
{
F_7 ( V_2 , ! V_99 , V_224 ,
V_225 ,
V_226 ) ;
}
static void F_66 ( struct V_1 * V_2 , T_1 V_99 )
{
F_7 ( V_2 , V_99 , V_224 ,
V_227 ,
V_228 ) ;
}
static void F_67 ( struct V_1 * V_2 , T_1 V_99 )
{
F_7 ( V_2 , V_99 , V_224 ,
V_229 ,
V_230 ) ;
}
static void F_68 ( struct V_1 * V_2 , T_1 V_99 )
{
F_7 ( V_2 , V_99 , V_224 ,
V_231 ,
V_232 ) ;
}
static void F_69 ( struct V_1 * V_2 , T_1 V_99 )
{
F_7 ( V_2 , V_99 , V_224 ,
V_233 ,
V_234 ) ;
}
static void F_70 ( struct V_1 * V_2 , T_1 V_99 )
{
F_7 ( V_2 , V_99 , V_224 ,
V_235 ,
V_236 ) ;
}
static void F_71 ( struct V_1 * V_2 , T_1 V_99 )
{
F_7 ( V_2 , V_99 , V_224 ,
V_237 ,
V_238 ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
const struct V_239 * V_240 = V_2 -> V_240 . V_7 ;
unsigned int V_48 ;
F_57 V_3 ;
if ( V_240 -> V_241 == 1 ) {
F_66 ( V_2 , 0 ) ;
F_65 ( V_2 , true ) ;
return;
}
F_69 ( V_2 , 0 ) ;
for ( V_48 = 0 ; V_48 < 5 ; ++ V_48 ) {
V_3 = F_3 ( V_2 , V_242 ) ;
if ( ! ( V_3 & V_243 ) )
break;
F_73 ( 1000 , 2000 ) ;
}
if ( V_3 & V_243 )
F_27 ( V_2 -> V_28 , L_9 ) ;
else
F_10 ( V_2 -> V_28 , L_10 , V_48 ) ;
F_68 ( V_2 , 1 ) ;
}
static int F_74 ( struct V_1 * V_2 )
{
const struct V_239 * V_240 = V_2 -> V_240 . V_7 ;
unsigned int V_48 ;
T_1 V_3 ;
if ( V_240 -> V_241 == 1 ) {
F_65 ( V_2 , false ) ;
F_66 ( V_2 , 0 ) ;
F_66 ( V_2 , 1 ) ;
return 0 ;
}
F_69 ( V_2 , 1 ) ;
F_68 ( V_2 , 0 ) ;
for ( V_48 = 0 ; V_48 < 5 ; ++ V_48 ) {
V_3 = F_3 ( V_2 , V_242 ) & V_243 ;
if ( V_3 )
break;
F_73 ( 1000 , 2000 ) ;
}
if ( ! V_3 ) {
F_75 ( V_2 -> V_28 , L_11 ) ;
return - V_244 ;
}
F_10 ( V_2 -> V_28 , L_12 , V_48 ) ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 ,
const struct V_245 * V_246 ,
unsigned long V_97 )
{
const struct V_247 * V_248 = V_246 -> V_249 ;
const struct V_250 * V_251 = V_246 -> V_252 ;
const struct V_253 * V_254 = V_246 -> V_254 ;
for (; V_248 -> V_97 != ~ 0UL ; V_248 ++ )
if ( V_97 <= V_248 -> V_97 )
break;
for (; V_251 -> V_97 != ~ 0UL ; V_251 ++ )
if ( V_97 <= V_251 -> V_97 )
break;
for (; V_254 -> V_97 != ~ 0UL ; V_254 ++ )
if ( V_97 <= V_254 -> V_97 )
break;
if ( V_248 -> V_97 == ~ 0UL ||
V_251 -> V_97 == ~ 0UL ||
V_254 -> V_97 == ~ 0UL )
return - V_255 ;
F_64 ( V_2 , V_248 -> V_256 [ 0 ] . V_257 ,
V_258 ) ;
F_64 ( V_2 , V_248 -> V_256 [ 0 ] . V_259 ,
V_260 ) ;
F_64 ( V_2 , V_251 -> V_261 [ 0 ] ,
V_262 ) ;
F_64 ( V_2 , 0 , V_263 ) ;
F_64 ( V_2 , V_264 ,
V_265 ) ;
F_64 ( V_2 , V_254 -> V_266 , V_267 ) ;
F_64 ( V_2 , V_254 -> V_268 ,
V_269 ) ;
F_64 ( V_2 , V_254 -> V_270 ,
V_271 ) ;
F_64 ( V_2 , V_272 ,
V_273 ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 )
{
const struct V_239 * V_240 = V_2 -> V_240 . V_7 ;
const struct V_245 * V_246 = V_2 -> V_274 ;
unsigned long V_97 = V_2 -> V_95 . V_96 . V_97 ;
int V_49 ;
F_72 ( V_2 ) ;
if ( V_240 -> V_275 )
F_67 ( V_2 , 1 ) ;
F_1 ( V_2 , V_276 , V_277 ) ;
F_1 ( V_2 , 0 , V_277 ) ;
F_1 ( V_2 , V_278 , V_279 ) ;
F_61 ( V_2 , 1 ) ;
F_1 ( V_2 , V_280 ,
V_281 ) ;
F_61 ( V_2 , 0 ) ;
if ( V_246 -> V_282 )
V_49 = V_246 -> V_282 ( V_2 , V_246 , V_97 ) ;
else
V_49 = V_240 -> V_283 ( V_2 , V_246 , V_97 ) ;
if ( V_49 ) {
F_75 ( V_2 -> V_28 , L_13 ,
V_97 ) ;
return V_49 ;
}
return F_74 ( V_2 ) ;
}
static int F_78 ( struct V_1 * V_2 , void * V_7 ,
struct V_284 * V_285 )
{
int V_48 , V_49 ;
for ( V_48 = 0 ; V_48 < 2 ; V_48 ++ ) {
F_70 ( V_2 , 1 ) ;
F_71 ( V_2 , 0 ) ;
V_49 = F_77 ( V_2 ) ;
if ( V_49 )
return V_49 ;
}
return 0 ;
}
static void F_79 ( struct V_1 * V_2 , void * V_7 )
{
F_72 ( V_2 ) ;
}
static enum V_286 F_80 ( struct V_1 * V_2 ,
void * V_7 )
{
return F_3 ( V_2 , V_242 ) & V_287 ?
V_288 : V_289 ;
}
static void F_81 ( struct V_1 * V_2 , void * V_7 ,
bool V_290 , bool V_291 , bool V_292 )
{
T_1 V_293 = V_2 -> V_294 ;
if ( V_290 || V_291 || ! V_292 )
V_2 -> V_294 |= V_295 ;
else
V_2 -> V_294 &= ~ V_295 ;
if ( V_293 != V_2 -> V_294 )
F_1 ( V_2 , V_2 -> V_294 , V_296 ) ;
}
static void F_82 ( struct V_1 * V_2 , void * V_7 )
{
F_1 ( V_2 , V_287 | V_295 , V_297 ) ;
F_1 ( V_2 , V_298 | V_299 ,
V_300 ) ;
F_1 ( V_2 , V_2 -> V_294 , V_296 ) ;
F_1 ( V_2 , V_298 | V_299 ,
V_300 ) ;
F_1 ( V_2 , ~ ( V_298 | V_299 ) ,
V_301 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
T_1 V_302 ;
if ( V_2 -> V_95 . V_96 . V_303 )
V_302 = V_304 ;
else
V_302 = V_305 ;
F_5 ( V_2 , V_306 ,
V_307 , V_308 ) ;
F_5 ( V_2 , V_302 , V_309 , V_310 ) ;
F_5 ( V_2 , V_311 ,
V_312 , V_313 ) ;
}
static void F_84 ( struct V_1 * V_2 , struct V_284 * V_285 )
{
struct V_314 V_315 ;
T_1 V_3 ;
F_85 ( & V_315 , V_285 , false ) ;
if ( F_49 ( V_2 -> V_95 . V_137 ) )
V_315 . V_316 = V_317 ;
else if ( F_50 ( V_2 -> V_95 . V_137 ) )
V_315 . V_316 = V_318 ;
else
V_315 . V_316 = V_319 ;
switch ( V_2 -> V_95 . V_141 ) {
case V_142 :
if ( V_2 -> V_95 . V_320 == V_321 )
V_315 . V_322 = V_323 ;
else
V_315 . V_322 = V_324 ;
V_315 . V_325 =
V_326 ;
break;
case V_327 :
if ( V_2 -> V_95 . V_320 == V_328 )
V_315 . V_322 = V_323 ;
else
V_315 . V_322 = V_329 ;
V_315 . V_325 =
V_330 ;
break;
default:
V_315 . V_322 = V_324 ;
V_315 . V_325 =
V_326 ;
break;
}
V_315 . V_331 = V_332 ;
V_3 = ( V_315 . V_331 & 3 ) << 4 | ( V_315 . V_316 & 3 ) ;
if ( V_315 . V_333 & 15 )
V_3 |= V_334 ;
if ( V_315 . V_335 || V_315 . V_336 )
V_3 |= V_337 ;
if ( V_315 . V_338 || V_315 . V_339 )
V_3 |= V_340 ;
F_1 ( V_2 , V_3 , V_341 ) ;
V_3 = ( ( V_315 . V_322 & 0x3 ) << 6 ) |
( ( V_315 . V_342 & 0x3 ) << 4 ) |
( V_315 . V_333 & 0xf ) ;
F_1 ( V_2 , V_3 , V_343 ) ;
V_3 = ( ( V_315 . V_325 & 0x7 ) << 4 ) |
( ( V_315 . V_344 & 0x3 ) << 2 ) |
( V_315 . V_345 & 0x3 ) ;
if ( V_315 . V_346 )
V_3 |= V_347 ;
F_1 ( V_2 , V_3 , V_348 ) ;
V_3 = V_315 . V_349 & 0x7f ;
F_1 ( V_2 , V_3 , V_350 ) ;
V_3 = ( ( ( V_2 -> V_95 . V_96 . V_351 + 1 ) <<
V_352 ) &
V_353 ) |
( ( V_2 -> V_95 . V_96 . V_354 <<
V_355 ) &
V_356 ) ;
F_1 ( V_2 , V_3 , V_357 ) ;
V_3 = ( ( V_315 . V_358 & 0x3 ) << 2 ) |
( V_315 . V_359 & 0x3 ) ;
F_1 ( V_2 , V_3 , V_360 ) ;
F_1 ( V_2 , V_315 . V_335 & 0xff , V_361 ) ;
F_1 ( V_2 , ( V_315 . V_335 >> 8 ) & 0xff , V_362 ) ;
F_1 ( V_2 , V_315 . V_336 & 0xff , V_363 ) ;
F_1 ( V_2 , ( V_315 . V_336 >> 8 ) & 0xff , V_364 ) ;
F_1 ( V_2 , V_315 . V_338 & 0xff , V_365 ) ;
F_1 ( V_2 , ( V_315 . V_338 >> 8 ) & 0xff , V_366 ) ;
F_1 ( V_2 , V_315 . V_339 & 0xff , V_367 ) ;
F_1 ( V_2 , ( V_315 . V_339 >> 8 ) & 0xff , V_368 ) ;
}
static void F_86 ( struct V_1 * V_2 ,
struct V_284 * V_285 )
{
struct V_369 V_315 ;
T_1 V_370 [ 10 ] ;
T_4 V_371 ;
V_371 = F_87 ( & V_315 , V_285 ) ;
if ( V_371 < 0 )
return;
V_371 = F_88 ( & V_315 , V_370 , sizeof( V_370 ) ) ;
if ( V_371 < 0 ) {
F_75 ( V_2 -> V_28 , L_14 ,
V_371 ) ;
return;
}
F_7 ( V_2 , 0 , V_372 , V_373 ,
V_374 ) ;
F_1 ( V_2 , V_370 [ 2 ] , V_375 ) ;
F_1 ( V_2 , V_370 [ 4 ] , V_376 ) ;
F_1 ( V_2 , V_370 [ 5 ] , V_377 ) ;
F_1 ( V_2 , V_370 [ 6 ] , V_378 ) ;
F_1 ( V_2 , V_370 [ 7 ] , V_379 ) ;
F_1 ( V_2 , V_370 [ 8 ] , V_380 ) ;
if ( V_315 . V_381 >= V_382 )
F_1 ( V_2 , V_370 [ 9 ] , V_383 ) ;
F_1 ( V_2 , 1 , V_384 ) ;
F_1 ( V_2 , 0x11 , V_385 ) ;
F_7 ( V_2 , 1 , V_372 , V_373 ,
V_374 ) ;
}
static void F_89 ( struct V_1 * V_2 ,
const struct V_284 * V_285 )
{
T_1 V_386 ;
struct V_387 * V_388 = & V_2 -> V_95 . V_96 ;
int V_389 , V_390 , V_391 , V_392 , V_393 , V_394 ;
unsigned int V_395 ;
V_388 -> V_97 = V_285 -> clock * 1000 ;
F_10 ( V_2 -> V_28 , L_15 , V_388 -> V_97 ) ;
V_386 = ( V_2 -> V_95 . V_396 ?
V_397 :
V_398 ) ;
V_386 |= V_285 -> V_54 & V_399 ?
V_400 :
V_401 ;
V_386 |= V_285 -> V_54 & V_402 ?
V_403 :
V_404 ;
V_386 |= ( V_388 -> V_303 ?
V_405 :
V_406 ) ;
if ( V_2 -> V_407 == 39 )
V_386 |= V_408 ;
else
V_386 |= V_285 -> V_54 & V_409 ?
V_408 :
V_410 ;
V_386 |= V_285 -> V_54 & V_409 ?
V_411 :
V_412 ;
V_386 |= V_2 -> V_413 ?
V_414 :
V_415 ;
F_1 ( V_2 , V_386 , V_416 ) ;
V_395 = V_285 -> V_395 ;
V_390 = V_285 -> V_417 - V_285 -> V_395 ;
V_392 = V_285 -> V_418 - V_285 -> V_395 ;
V_394 = V_285 -> V_419 - V_285 -> V_418 ;
if ( V_285 -> V_54 & V_409 ) {
V_395 /= 2 ;
V_390 /= 2 ;
V_392 /= 2 ;
V_394 /= 2 ;
}
F_1 ( V_2 , V_285 -> V_420 >> 8 , V_421 ) ;
F_1 ( V_2 , V_285 -> V_420 , V_422 ) ;
F_1 ( V_2 , V_395 >> 8 , V_423 ) ;
F_1 ( V_2 , V_395 , V_424 ) ;
V_389 = V_285 -> V_425 - V_285 -> V_420 ;
F_1 ( V_2 , V_389 >> 8 , V_426 ) ;
F_1 ( V_2 , V_389 , V_427 ) ;
F_1 ( V_2 , V_390 , V_428 ) ;
V_391 = V_285 -> V_429 - V_285 -> V_420 ;
F_1 ( V_2 , V_391 >> 8 , V_430 ) ;
F_1 ( V_2 , V_391 , V_431 ) ;
F_1 ( V_2 , V_392 , V_432 ) ;
V_393 = V_285 -> V_433 - V_285 -> V_429 ;
F_1 ( V_2 , V_393 >> 8 , V_434 ) ;
F_1 ( V_2 , V_393 , V_435 ) ;
F_1 ( V_2 , V_394 , V_436 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 12 , V_437 ) ;
F_1 ( V_2 , 32 , V_438 ) ;
F_1 ( V_2 , 1 , V_439 ) ;
F_1 ( V_2 , 0x0B , V_440 ) ;
F_1 ( V_2 , 0x16 , V_441 ) ;
F_1 ( V_2 , 0x21 , V_442 ) ;
V_2 -> V_100 |= V_443 |
V_444 |
V_101 |
V_445 |
V_446 ;
V_2 -> V_100 &= ~ V_447 ;
F_1 ( V_2 , V_2 -> V_100 , V_102 ) ;
V_2 -> V_100 &= ~ V_446 ;
F_1 ( V_2 , V_2 -> V_100 , V_102 ) ;
if ( F_53 ( V_2 ) ) {
V_2 -> V_100 &= ~ V_444 ;
F_1 ( V_2 , V_2 -> V_100 , V_102 ) ;
}
if ( F_53 ( V_2 ) )
F_1 ( V_2 , V_448 ,
V_449 ) ;
else
F_1 ( V_2 , V_450 ,
V_449 ) ;
}
static void F_91 ( struct V_1 * V_2 )
{
unsigned int V_451 ;
unsigned int V_48 ;
T_1 V_3 ;
switch ( V_2 -> V_452 ) {
case 0x130a :
V_451 = 4 ;
break;
case 0x131a :
V_451 = 1 ;
break;
default:
return;
}
F_1 ( V_2 , ( T_1 ) ~ V_453 , V_454 ) ;
V_3 = F_3 ( V_2 , V_416 ) ;
for ( V_48 = 0 ; V_48 < V_451 ; V_48 ++ )
F_1 ( V_2 , V_3 , V_416 ) ;
}
static void F_92 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0 , V_455 ) ;
F_1 ( V_2 , 0 , V_456 ) ;
}
static void F_93 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_457 ,
V_456 ) ;
}
static int F_94 ( struct V_1 * V_2 , struct V_284 * V_285 )
{
int V_49 ;
F_93 ( V_2 ) ;
V_2 -> V_407 = F_95 ( V_285 ) ;
if ( ! V_2 -> V_407 ) {
F_10 ( V_2 -> V_28 , L_16 ) ;
} else {
F_10 ( V_2 -> V_28 , L_17 , V_2 -> V_407 ) ;
}
if ( ( V_2 -> V_407 == 6 ) || ( V_2 -> V_407 == 7 ) ||
( V_2 -> V_407 == 21 ) || ( V_2 -> V_407 == 22 ) ||
( V_2 -> V_407 == 2 ) || ( V_2 -> V_407 == 3 ) ||
( V_2 -> V_407 == 17 ) || ( V_2 -> V_407 == 18 ) )
V_2 -> V_95 . V_141 = V_142 ;
else
V_2 -> V_95 . V_141 = V_327 ;
V_2 -> V_95 . V_96 . V_354 = 0 ;
V_2 -> V_95 . V_96 . V_351 = 0 ;
if ( V_2 -> V_274 -> V_458 )
V_2 -> V_95 . V_122 =
V_2 -> V_274 -> V_458 ;
else
V_2 -> V_95 . V_122 = V_106 ;
if ( V_2 -> V_274 -> V_459 )
V_2 -> V_95 . V_320 =
V_2 -> V_274 -> V_459 ;
else
V_2 -> V_95 . V_320 = V_460 ;
V_2 -> V_95 . V_137 = V_106 ;
V_2 -> V_95 . V_182 = 0 ;
V_2 -> V_95 . V_396 = 0 ;
V_2 -> V_95 . V_96 . V_303 = true ;
F_89 ( V_2 , V_285 ) ;
V_49 = V_2 -> V_240 . V_461 -> V_462 ( V_2 , V_2 -> V_240 . V_7 , & V_2 -> V_463 ) ;
if ( V_49 )
return V_49 ;
V_2 -> V_240 . V_464 = true ;
F_90 ( V_2 ) ;
if ( V_2 -> V_465 ) {
F_10 ( V_2 -> V_28 , L_18 ) ;
F_37 ( V_2 ) ;
F_39 ( V_2 , true ) ;
}
if ( V_2 -> V_413 ) {
F_10 ( V_2 -> V_28 , L_19 , V_89 ) ;
F_84 ( V_2 , V_285 ) ;
F_86 ( V_2 , V_285 ) ;
} else {
F_10 ( V_2 -> V_28 , L_20 , V_89 ) ;
}
F_60 ( V_2 ) ;
F_59 ( V_2 ) ;
F_52 ( V_2 ) ;
F_83 ( V_2 ) ;
F_91 ( V_2 ) ;
if ( V_2 -> V_466 && V_2 -> V_413 )
F_92 ( V_2 ) ;
return 0 ;
}
static void F_96 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_467 ,
V_468 ) ;
F_1 ( V_2 , V_469 |
V_470 ,
V_471 ) ;
}
static void F_97 ( struct V_1 * V_2 )
{
T_1 V_472 ;
V_472 = F_3 ( V_2 , V_473 ) |
V_474 |
V_475 ;
F_1 ( V_2 , V_472 , V_473 ) ;
F_1 ( V_2 , 0xff , V_476 ) ;
F_1 ( V_2 , 0xff , V_477 ) ;
F_1 ( V_2 , 0xff , V_478 ) ;
F_1 ( V_2 , 0xff , V_455 ) ;
F_1 ( V_2 , 0xff , V_296 ) ;
F_1 ( V_2 , 0xff , V_468 ) ;
F_1 ( V_2 , 0xff , V_471 ) ;
F_1 ( V_2 , 0xff , V_479 ) ;
F_1 ( V_2 , 0xff , V_480 ) ;
F_1 ( V_2 , 0xff , V_481 ) ;
F_1 ( V_2 , 0xff , V_482 ) ;
F_1 ( V_2 , 0xff , V_483 ) ;
F_1 ( V_2 , 0xff , V_14 ) ;
F_1 ( V_2 , 0xff , V_17 ) ;
F_1 ( V_2 , 0xff , V_484 ) ;
F_1 ( V_2 , 0xff , V_485 ) ;
F_1 ( V_2 , 0xff , V_456 ) ;
F_1 ( V_2 , 0xff , V_486 ) ;
F_1 ( V_2 , 0xff , V_301 ) ;
F_1 ( V_2 , 0xff , V_21 ) ;
F_1 ( V_2 , 0xff , V_487 ) ;
F_1 ( V_2 , 0xff , V_488 ) ;
F_1 ( V_2 , 0xff , V_489 ) ;
F_1 ( V_2 , 0xff , V_490 ) ;
V_472 &= ~ ( V_474 |
V_475 ) ;
F_1 ( V_2 , V_472 , V_473 ) ;
}
static void F_98 ( struct V_1 * V_2 )
{
V_2 -> V_491 = true ;
F_94 ( V_2 , & V_2 -> V_463 ) ;
}
static void F_99 ( struct V_1 * V_2 )
{
if ( V_2 -> V_240 . V_464 ) {
V_2 -> V_240 . V_461 -> V_492 ( V_2 , V_2 -> V_240 . V_7 ) ;
V_2 -> V_240 . V_464 = false ;
}
V_2 -> V_491 = false ;
}
static void F_100 ( struct V_1 * V_2 )
{
int V_290 = V_2 -> V_290 ;
if ( V_2 -> V_291 ) {
V_290 = V_493 ;
} else if ( V_290 == V_494 ) {
if ( V_2 -> V_292 )
V_290 = V_495 ;
else
V_290 = V_493 ;
}
if ( V_290 == V_493 ) {
if ( V_2 -> V_491 )
F_99 ( V_2 ) ;
} else {
if ( ! V_2 -> V_491 )
F_98 ( V_2 ) ;
}
}
static void F_101 ( struct V_1 * V_2 )
{
if ( V_2 -> V_240 . V_461 -> V_496 )
V_2 -> V_240 . V_461 -> V_496 ( V_2 , V_2 -> V_240 . V_7 ,
V_2 -> V_290 , V_2 -> V_291 ,
V_2 -> V_292 ) ;
}
static enum V_286
F_102 ( struct V_497 * V_498 , bool V_290 )
{
struct V_1 * V_2 = F_103 ( V_498 , struct V_1 ,
V_498 ) ;
F_16 ( & V_2 -> V_499 ) ;
V_2 -> V_290 = V_494 ;
F_100 ( V_2 ) ;
F_101 ( V_2 ) ;
F_17 ( & V_2 -> V_499 ) ;
return V_2 -> V_240 . V_461 -> V_500 ( V_2 , V_2 -> V_240 . V_7 ) ;
}
static int F_104 ( struct V_497 * V_498 )
{
struct V_1 * V_2 = F_103 ( V_498 , struct V_1 ,
V_498 ) ;
struct V_501 * V_501 ;
int V_49 = 0 ;
if ( ! V_2 -> V_502 )
return 0 ;
V_501 = F_105 ( V_498 , V_2 -> V_502 ) ;
if ( V_501 ) {
F_10 ( V_2 -> V_28 , L_21 ,
V_501 -> V_503 , V_501 -> V_504 ) ;
V_2 -> V_413 = F_106 ( V_501 ) ;
V_2 -> V_465 = F_107 ( V_501 ) ;
F_108 ( V_498 , V_501 ) ;
F_109 ( V_2 -> V_505 , V_501 ) ;
V_49 = F_110 ( V_498 , V_501 ) ;
F_111 ( V_498 , V_501 ) ;
F_112 ( V_501 ) ;
} else {
F_10 ( V_2 -> V_28 , L_22 ) ;
}
return V_49 ;
}
static void F_113 ( struct V_497 * V_498 )
{
struct V_1 * V_2 = F_103 ( V_498 , struct V_1 ,
V_498 ) ;
F_16 ( & V_2 -> V_499 ) ;
V_2 -> V_290 = V_498 -> V_290 ;
F_100 ( V_2 ) ;
F_101 ( V_2 ) ;
F_17 ( & V_2 -> V_499 ) ;
}
static int F_114 ( struct V_506 * V_507 )
{
struct V_1 * V_2 = V_507 -> V_508 ;
struct V_509 * V_510 = V_507 -> V_510 ;
struct V_497 * V_498 = & V_2 -> V_498 ;
V_498 -> V_511 = 1 ;
V_498 -> V_512 = V_513 ;
F_115 ( V_498 , & V_514 ) ;
F_116 ( V_507 -> V_28 , V_498 , & V_515 ,
V_516 ) ;
F_117 ( V_498 , V_510 ) ;
return 0 ;
}
static enum V_517
F_118 ( struct V_506 * V_507 ,
const struct V_284 * V_285 )
{
struct V_1 * V_2 = V_507 -> V_508 ;
struct V_497 * V_498 = & V_2 -> V_498 ;
enum V_517 V_518 = V_519 ;
if ( V_285 -> V_54 & V_520 )
return V_521 ;
if ( V_2 -> V_274 -> V_522 )
V_518 = V_2 -> V_274 -> V_522 ( V_498 , V_285 ) ;
return V_518 ;
}
static void F_119 ( struct V_506 * V_507 ,
struct V_284 * V_523 ,
struct V_284 * V_285 )
{
struct V_1 * V_2 = V_507 -> V_508 ;
F_16 ( & V_2 -> V_499 ) ;
memcpy ( & V_2 -> V_463 , V_285 , sizeof( V_2 -> V_463 ) ) ;
F_17 ( & V_2 -> V_499 ) ;
}
static void F_120 ( struct V_506 * V_507 )
{
struct V_1 * V_2 = V_507 -> V_508 ;
F_16 ( & V_2 -> V_499 ) ;
V_2 -> V_291 = true ;
F_100 ( V_2 ) ;
F_101 ( V_2 ) ;
F_17 ( & V_2 -> V_499 ) ;
}
static void F_121 ( struct V_506 * V_507 )
{
struct V_1 * V_2 = V_507 -> V_508 ;
F_16 ( & V_2 -> V_499 ) ;
V_2 -> V_291 = false ;
F_100 ( V_2 ) ;
F_101 ( V_2 ) ;
F_17 ( & V_2 -> V_499 ) ;
}
static T_5 F_122 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_25 ;
unsigned int V_26 ;
V_26 = F_3 ( V_2 , V_20 ) ;
if ( ! V_26 )
return V_524 ;
F_1 ( V_2 , V_26 , V_20 ) ;
V_25 -> V_26 = V_26 ;
F_123 ( & V_25 -> V_30 ) ;
return V_525 ;
}
static T_5 F_124 ( int V_526 , void * V_527 )
{
struct V_1 * V_2 = V_527 ;
T_1 V_528 ;
T_5 V_49 = V_524 ;
if ( V_2 -> V_25 )
V_49 = F_122 ( V_2 ) ;
V_528 = F_3 ( V_2 , V_300 ) ;
if ( V_528 ) {
F_1 ( V_2 , ~ 0 , V_301 ) ;
return V_529 ;
}
return V_49 ;
}
void F_125 ( struct V_1 * V_2 , bool V_530 , bool V_531 )
{
F_16 ( & V_2 -> V_499 ) ;
if ( ! V_2 -> V_290 ) {
if ( ! V_531 )
V_2 -> V_292 = false ;
if ( V_530 )
V_2 -> V_292 = true ;
F_100 ( V_2 ) ;
F_101 ( V_2 ) ;
}
F_17 ( & V_2 -> V_499 ) ;
}
void F_126 ( struct V_532 * V_28 , bool V_530 , bool V_531 )
{
struct V_1 * V_2 = F_127 ( V_28 ) ;
F_125 ( V_2 , V_530 , V_531 ) ;
}
static T_5 F_128 ( int V_526 , void * V_527 )
{
struct V_1 * V_2 = V_527 ;
T_1 V_528 , V_533 , V_534 , V_535 ;
V_528 = F_3 ( V_2 , V_300 ) ;
V_533 = F_3 ( V_2 , V_297 ) ;
V_535 = F_3 ( V_2 , V_242 ) ;
V_534 = 0 ;
if ( V_528 & V_298 )
V_534 |= V_287 ;
if ( V_528 & V_536 )
V_534 |= V_537 ;
if ( V_528 & V_538 )
V_534 |= V_539 ;
if ( V_528 & V_540 )
V_534 |= V_541 ;
if ( V_528 & V_542 )
V_534 |= V_543 ;
if ( V_534 )
F_5 ( V_2 , ~ V_533 , V_534 , V_297 ) ;
if ( V_528 &
( V_299 | V_298 ) ) {
F_125 ( V_2 ,
V_535 & V_287 ,
V_535 & V_295 ) ;
if ( ( V_535 & ( V_295 | V_287 ) ) == 0 )
F_129 ( V_2 -> V_505 ,
V_544 ) ;
}
if ( V_528 & V_298 ) {
F_10 ( V_2 -> V_28 , L_23 ,
V_533 & V_287 ? L_24 : L_25 ) ;
if ( V_2 -> V_507 . V_28 )
F_130 ( V_2 -> V_507 . V_28 ) ;
}
F_1 ( V_2 , V_528 , V_300 ) ;
F_1 ( V_2 , ~ ( V_298 | V_299 ) ,
V_301 ) ;
return V_525 ;
}
static int F_131 ( struct V_1 * V_2 )
{
unsigned int V_48 ;
T_1 V_545 ;
V_545 = F_3 ( V_2 , V_546 ) ;
if ( V_545 == V_547 ) {
if ( ! V_2 -> V_274 -> V_548 || ! V_2 -> V_274 -> V_549 ) {
F_75 ( V_2 -> V_28 ,
L_26 ) ;
return - V_550 ;
}
V_2 -> V_240 . V_461 = V_2 -> V_274 -> V_548 ;
V_2 -> V_240 . V_7 = V_2 -> V_274 -> V_551 ;
V_2 -> V_240 . V_71 = V_2 -> V_274 -> V_549 ;
return 0 ;
}
for ( V_48 = 0 ; V_48 < F_58 ( V_552 ) ; ++ V_48 ) {
if ( V_552 [ V_48 ] . type == V_545 ) {
V_2 -> V_240 . V_461 = & V_553 ;
V_2 -> V_240 . V_71 = V_552 [ V_48 ] . V_71 ;
V_2 -> V_240 . V_7 = ( void * ) & V_552 [ V_48 ] ;
if ( ! V_552 [ V_48 ] . V_283 &&
! V_2 -> V_274 -> V_282 ) {
F_75 ( V_2 -> V_28 , L_27 ,
V_2 -> V_240 . V_71 ) ;
return - V_550 ;
}
return 0 ;
}
}
F_75 ( V_2 -> V_28 , L_28 , V_545 ) ;
return - V_550 ;
}
static void F_132 ( struct V_1 * V_2 )
{
F_16 ( & V_2 -> V_499 ) ;
V_2 -> V_100 &= ~ V_554 ;
F_1 ( V_2 , V_2 -> V_100 , V_102 ) ;
F_17 ( & V_2 -> V_499 ) ;
}
static void F_133 ( struct V_1 * V_2 )
{
F_16 ( & V_2 -> V_499 ) ;
V_2 -> V_100 |= V_554 ;
F_1 ( V_2 , V_2 -> V_100 , V_102 ) ;
F_17 ( & V_2 -> V_499 ) ;
}
static struct V_1 *
F_134 ( struct V_555 * V_556 ,
const struct V_245 * V_274 )
{
struct V_532 * V_28 = & V_556 -> V_28 ;
struct V_557 * V_558 = V_28 -> V_559 ;
struct V_560 V_561 ;
struct V_557 * V_562 ;
struct V_563 V_564 ;
struct V_1 * V_2 ;
struct V_565 * V_566 = NULL ;
int V_526 ;
int V_49 ;
T_2 V_3 = 1 ;
T_1 V_567 ;
T_1 V_568 ;
T_1 V_569 ;
T_1 V_570 ;
V_2 = F_20 ( V_28 , sizeof( * V_2 ) , V_62 ) ;
if ( ! V_2 )
return F_21 ( - V_63 ) ;
V_2 -> V_274 = V_274 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_86 = 48000 ;
V_2 -> V_291 = true ;
V_2 -> V_292 = true ;
V_2 -> V_294 = ( T_1 ) ~ ( V_287 | V_295 ) ;
V_2 -> V_100 = 0x7f ;
F_22 ( & V_2 -> V_499 ) ;
F_22 ( & V_2 -> V_94 ) ;
F_135 ( & V_2 -> V_90 ) ;
V_562 = F_136 ( V_558 , L_29 , 0 ) ;
if ( V_562 ) {
V_2 -> V_502 = F_137 ( V_562 ) ;
F_138 ( V_562 ) ;
if ( ! V_2 -> V_502 ) {
F_10 ( V_2 -> V_28 , L_30 ) ;
return F_21 ( - V_571 ) ;
}
} else {
F_10 ( V_2 -> V_28 , L_31 ) ;
}
if ( ! V_274 -> V_5 ) {
const struct V_572 * V_573 ;
F_139 ( V_558 , L_32 , & V_3 ) ;
switch ( V_3 ) {
case 4 :
V_573 = & V_574 ;
V_2 -> V_6 = 2 ;
break;
case 1 :
V_573 = & V_575 ;
break;
default:
F_75 ( V_28 , L_33 ) ;
return F_21 ( - V_255 ) ;
}
V_566 = F_140 ( V_556 , V_576 , 0 ) ;
V_2 -> V_577 = F_141 ( V_28 , V_566 ) ;
if ( F_142 ( V_2 -> V_577 ) ) {
V_49 = F_143 ( V_2 -> V_577 ) ;
goto V_578;
}
V_2 -> V_5 = F_144 ( V_28 , V_2 -> V_577 , V_573 ) ;
if ( F_142 ( V_2 -> V_5 ) ) {
F_75 ( V_28 , L_34 ) ;
V_49 = F_143 ( V_2 -> V_5 ) ;
goto V_578;
}
} else {
V_2 -> V_5 = V_274 -> V_5 ;
}
V_2 -> V_579 = F_145 ( V_2 -> V_28 , L_35 ) ;
if ( F_142 ( V_2 -> V_579 ) ) {
V_49 = F_143 ( V_2 -> V_579 ) ;
F_75 ( V_2 -> V_28 , L_36 , V_49 ) ;
goto V_578;
}
V_49 = F_146 ( V_2 -> V_579 ) ;
if ( V_49 ) {
F_75 ( V_2 -> V_28 , L_37 , V_49 ) ;
goto V_578;
}
V_2 -> V_580 = F_145 ( V_2 -> V_28 , L_38 ) ;
if ( F_142 ( V_2 -> V_580 ) ) {
V_49 = F_143 ( V_2 -> V_580 ) ;
F_75 ( V_2 -> V_28 , L_39 , V_49 ) ;
goto V_581;
}
V_49 = F_146 ( V_2 -> V_580 ) ;
if ( V_49 ) {
F_75 ( V_2 -> V_28 , L_40 , V_49 ) ;
goto V_581;
}
V_2 -> V_452 = ( F_3 ( V_2 , V_582 ) << 8 )
| ( F_3 ( V_2 , V_583 ) << 0 ) ;
V_567 = F_3 ( V_2 , V_584 ) ;
V_568 = F_3 ( V_2 , V_585 ) ;
if ( V_567 != V_586 ||
( V_568 & ~ V_587 ) != V_588 ) {
F_75 ( V_28 , L_41 ,
V_2 -> V_452 , V_567 , V_568 ) ;
V_49 = - V_550 ;
goto V_589;
}
V_49 = F_131 ( V_2 ) ;
if ( V_49 < 0 )
goto V_589;
F_29 ( V_28 , L_42 ,
V_2 -> V_452 >> 12 , V_2 -> V_452 & 0xfff ,
V_568 & V_587 ? L_43 : L_44 ,
V_2 -> V_240 . V_71 ) ;
F_97 ( V_2 ) ;
V_526 = F_147 ( V_556 , 0 ) ;
if ( V_526 < 0 ) {
V_49 = V_526 ;
goto V_589;
}
V_49 = F_148 ( V_28 , V_526 , F_124 ,
F_128 , V_590 ,
F_149 ( V_28 ) , V_2 ) ;
if ( V_49 )
goto V_589;
V_2 -> V_505 = F_150 ( V_28 ) ;
if ( ! V_2 -> V_505 ) {
V_49 = - V_63 ;
goto V_589;
}
F_36 ( V_2 ) ;
if ( ! V_2 -> V_502 ) {
V_2 -> V_502 = F_19 ( V_2 ) ;
if ( F_142 ( V_2 -> V_502 ) )
V_2 -> V_502 = NULL ;
}
V_2 -> V_507 . V_508 = V_2 ;
V_2 -> V_507 . V_591 = & V_592 ;
#ifdef F_151
V_2 -> V_507 . V_559 = V_556 -> V_28 . V_559 ;
#endif
F_96 ( V_2 ) ;
if ( V_2 -> V_240 . V_461 -> V_593 )
V_2 -> V_240 . V_461 -> V_593 ( V_2 , V_2 -> V_240 . V_7 ) ;
memset ( & V_561 , 0 , sizeof( V_561 ) ) ;
V_561 . V_68 = V_28 ;
V_561 . V_594 = V_595 ;
V_569 = F_3 ( V_2 , V_596 ) ;
V_570 = F_3 ( V_2 , V_597 ) ;
if ( V_566 && V_570 & V_598 ) {
struct V_599 V_600 ;
V_600 . V_601 = V_566 -> V_602 ;
V_600 . V_603 = V_2 -> V_577 ;
V_600 . V_526 = V_526 ;
V_600 . V_2 = V_2 ;
V_600 . V_604 = V_2 -> V_498 . V_604 ;
V_2 -> V_103 = F_40 ;
V_2 -> V_104 = F_41 ;
V_561 . V_71 = L_45 ;
V_561 . V_7 = & V_600 ;
V_561 . V_605 = sizeof( V_600 ) ;
V_561 . V_606 = F_152 ( 32 ) ;
V_2 -> V_600 = F_153 ( & V_561 ) ;
} else if ( V_569 & V_607 ) {
struct V_608 V_600 ;
V_600 . V_2 = V_2 ;
V_600 . V_609 = F_1 ;
V_600 . V_610 = F_3 ;
V_2 -> V_103 = F_42 ;
V_2 -> V_104 = F_43 ;
V_561 . V_71 = L_46 ;
V_561 . V_7 = & V_600 ;
V_561 . V_605 = sizeof( V_600 ) ;
V_561 . V_606 = F_152 ( 32 ) ;
V_2 -> V_600 = F_153 ( & V_561 ) ;
}
if ( V_569 & V_611 ) {
V_564 . V_2 = V_2 ;
V_564 . V_461 = & V_612 ;
V_564 . V_526 = V_526 ;
V_561 . V_71 = L_47 ;
V_561 . V_7 = & V_564 ;
V_561 . V_605 = sizeof( V_564 ) ;
V_561 . V_606 = 0 ;
V_2 -> V_564 = F_153 ( & V_561 ) ;
}
if ( V_2 -> V_25 )
F_8 ( V_2 ) ;
F_154 ( V_556 , V_2 ) ;
return V_2 ;
V_589:
if ( V_2 -> V_25 ) {
F_155 ( & V_2 -> V_25 -> V_43 ) ;
V_2 -> V_502 = NULL ;
}
if ( V_2 -> V_505 )
F_156 ( V_2 -> V_505 ) ;
F_157 ( V_2 -> V_580 ) ;
V_581:
F_157 ( V_2 -> V_579 ) ;
V_578:
F_158 ( V_2 -> V_502 ) ;
return F_21 ( V_49 ) ;
}
static void F_159 ( struct V_1 * V_2 )
{
if ( V_2 -> V_600 && ! F_142 ( V_2 -> V_600 ) )
F_160 ( V_2 -> V_600 ) ;
if ( ! F_142 ( V_2 -> V_564 ) )
F_160 ( V_2 -> V_564 ) ;
F_1 ( V_2 , ~ 0 , V_301 ) ;
if ( V_2 -> V_505 )
F_156 ( V_2 -> V_505 ) ;
F_157 ( V_2 -> V_580 ) ;
F_157 ( V_2 -> V_579 ) ;
if ( V_2 -> V_25 )
F_155 ( & V_2 -> V_25 -> V_43 ) ;
else
F_158 ( V_2 -> V_502 ) ;
}
int F_161 ( struct V_555 * V_556 ,
const struct V_245 * V_274 )
{
struct V_1 * V_2 ;
V_2 = F_134 ( V_556 , V_274 ) ;
if ( F_142 ( V_2 ) )
return F_143 ( V_2 ) ;
F_162 ( & V_2 -> V_507 ) ;
return 0 ;
}
void F_163 ( struct V_555 * V_556 )
{
struct V_1 * V_2 = F_164 ( V_556 ) ;
F_165 ( & V_2 -> V_507 ) ;
F_159 ( V_2 ) ;
}
int F_166 ( struct V_555 * V_556 , struct V_509 * V_510 ,
const struct V_245 * V_274 )
{
struct V_1 * V_2 ;
int V_49 ;
V_2 = F_134 ( V_556 , V_274 ) ;
if ( F_142 ( V_2 ) )
return F_143 ( V_2 ) ;
V_49 = F_167 ( V_510 , & V_2 -> V_507 , NULL ) ;
if ( V_49 ) {
F_163 ( V_556 ) ;
F_168 ( L_48 ) ;
return V_49 ;
}
return 0 ;
}
void F_169 ( struct V_532 * V_28 )
{
struct V_1 * V_2 = F_127 ( V_28 ) ;
F_159 ( V_2 ) ;
}
