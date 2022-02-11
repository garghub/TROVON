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
F_5 ( V_2 , V_99 ? 0 : V_100 ,
V_100 , V_101 ) ;
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
if ( V_2 -> V_102 )
V_2 -> V_102 ( V_2 ) ;
F_46 ( & V_2 -> V_90 , V_54 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
unsigned long V_54 ;
F_45 ( & V_2 -> V_90 , V_54 ) ;
V_2 -> V_93 = false ;
if ( V_2 -> V_103 )
V_2 -> V_103 ( V_2 ) ;
F_46 ( & V_2 -> V_90 , V_54 ) ;
}
static bool F_48 ( unsigned int V_104 )
{
switch ( V_104 ) {
case V_105 :
case V_106 :
case V_107 :
case V_108 :
return true ;
default:
return false ;
}
}
static bool F_49 ( unsigned int V_104 )
{
switch ( V_104 ) {
case V_109 :
case V_110 :
case V_111 :
case V_112 :
return true ;
default:
return false ;
}
}
static bool F_50 ( unsigned int V_104 )
{
switch ( V_104 ) {
case V_113 :
case V_114 :
case V_115 :
return true ;
default:
return false ;
}
}
static int F_51 ( unsigned int V_104 )
{
switch ( V_104 ) {
case V_105 :
case V_109 :
case V_113 :
case V_116 :
return 8 ;
case V_106 :
case V_110 :
case V_114 :
case V_117 :
return 10 ;
case V_107 :
case V_111 :
case V_115 :
case V_118 :
return 12 ;
case V_108 :
case V_112 :
case V_119 :
return 16 ;
default:
return 0 ;
}
}
static void F_52 ( struct V_1 * V_2 )
{
int V_120 = 0 ;
T_1 V_3 ;
switch ( V_2 -> V_95 . V_121 ) {
case V_105 :
V_120 = 0x01 ;
break;
case V_106 :
V_120 = 0x03 ;
break;
case V_107 :
V_120 = 0x05 ;
break;
case V_108 :
V_120 = 0x07 ;
break;
case V_109 :
case V_116 :
V_120 = 0x09 ;
break;
case V_110 :
case V_117 :
V_120 = 0x0B ;
break;
case V_111 :
case V_118 :
V_120 = 0x0D ;
break;
case V_112 :
case V_119 :
V_120 = 0x0F ;
break;
case V_113 :
V_120 = 0x16 ;
break;
case V_114 :
V_120 = 0x14 ;
break;
case V_115 :
V_120 = 0x12 ;
break;
default:
return;
}
V_3 = V_122 |
( ( V_120 << V_123 ) &
V_124 ) ;
F_1 ( V_2 , V_3 , V_125 ) ;
V_3 = V_126 |
V_127 |
V_128 ;
F_1 ( V_2 , V_3 , V_129 ) ;
F_1 ( V_2 , 0x0 , V_130 ) ;
F_1 ( V_2 , 0x0 , V_131 ) ;
F_1 ( V_2 , 0x0 , V_132 ) ;
F_1 ( V_2 , 0x0 , V_133 ) ;
F_1 ( V_2 , 0x0 , V_134 ) ;
F_1 ( V_2 , 0x0 , V_135 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
return V_2 -> V_95 . V_121 != V_2 -> V_95 . V_136 ;
}
static int F_54 ( struct V_1 * V_2 )
{
if ( ! F_50 ( V_2 -> V_95 . V_136 ) )
return 0 ;
if ( F_48 ( V_2 -> V_95 . V_121 ) ||
F_49 ( V_2 -> V_95 . V_121 ) )
return 1 ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
if ( ! F_50 ( V_2 -> V_95 . V_121 ) )
return 0 ;
if ( F_48 ( V_2 -> V_95 . V_136 ) ||
F_49 ( V_2 -> V_95 . V_136 ) )
return 1 ;
return 0 ;
}
static void F_56 ( struct V_1 * V_2 )
{
const F_57 ( * V_137 ) [ 3 ] [ 4 ] = & V_138 ;
unsigned V_48 ;
T_2 V_139 = 1 ;
if ( F_53 ( V_2 ) ) {
if ( F_48 ( V_2 -> V_95 . V_136 ) ) {
if ( V_2 -> V_95 . V_140 ==
V_141 )
V_137 = & V_142 ;
else
V_137 = & V_143 ;
} else if ( F_48 (
V_2 -> V_95 . V_121 ) ) {
if ( V_2 -> V_95 . V_140 ==
V_141 )
V_137 = & V_144 ;
else
V_137 = & V_145 ;
V_139 = 0 ;
}
}
for ( V_48 = 0 ; V_48 < F_58 ( V_138 [ 0 ] ) ; V_48 ++ ) {
F_57 V_146 = ( * V_137 ) [ 0 ] [ V_48 ] ;
F_57 V_147 = ( * V_137 ) [ 1 ] [ V_48 ] ;
F_57 V_148 = ( * V_137 ) [ 2 ] [ V_48 ] ;
F_1 ( V_2 , V_146 & 0xff , V_149 + V_48 * 2 ) ;
F_1 ( V_2 , V_146 >> 8 , V_150 + V_48 * 2 ) ;
F_1 ( V_2 , V_147 & 0xff , V_151 + V_48 * 2 ) ;
F_1 ( V_2 , V_147 >> 8 , V_152 + V_48 * 2 ) ;
F_1 ( V_2 , V_148 & 0xff , V_153 + V_48 * 2 ) ;
F_1 ( V_2 , V_148 >> 8 , V_154 + V_48 * 2 ) ;
}
F_5 ( V_2 , V_139 , V_155 ,
V_156 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
int V_157 = 0 ;
int V_158 = V_159 ;
int V_160 = 0 ;
if ( F_55 ( V_2 ) )
V_158 = V_161 ;
else if ( F_54 ( V_2 ) )
V_160 = V_162 ;
switch ( F_51 ( V_2 -> V_95 . V_136 ) ) {
case 8 :
V_157 = V_163 ;
break;
case 10 :
V_157 = V_164 ;
break;
case 12 :
V_157 = V_165 ;
break;
case 16 :
V_157 = V_166 ;
break;
default:
return;
}
F_1 ( V_2 , V_158 | V_160 , V_167 ) ;
F_5 ( V_2 , V_157 , V_168 ,
V_156 ) ;
F_56 ( V_2 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
unsigned int V_157 = 0 ;
unsigned int V_169 = V_170 ;
unsigned int V_171 = V_172 ;
struct V_173 * V_95 = & V_2 -> V_95 ;
T_1 V_3 , V_174 ;
if ( F_48 ( V_2 -> V_95 . V_136 ) ||
F_49 ( V_2 -> V_95 . V_136 ) ) {
switch ( F_51 (
V_2 -> V_95 . V_136 ) ) {
case 8 :
V_157 = 4 ;
V_171 = V_175 ;
break;
case 10 :
V_157 = 5 ;
break;
case 12 :
V_157 = 6 ;
break;
case 16 :
V_157 = 7 ;
break;
default:
V_171 = V_175 ;
}
} else if ( F_50 ( V_2 -> V_95 . V_136 ) ) {
switch ( F_51 (
V_2 -> V_95 . V_136 ) ) {
case 0 :
case 8 :
V_169 = V_170 ;
break;
case 10 :
V_169 = V_176 ;
break;
case 12 :
V_169 = V_177 ;
break;
default:
return;
}
V_171 = V_178 ;
} else {
return;
}
V_3 = ( ( V_157 << V_179 ) &
V_180 ) |
( ( V_95 -> V_181 <<
V_182 ) &
V_183 ) ;
F_1 ( V_2 , V_3 , V_184 ) ;
F_5 ( V_2 , V_185 ,
V_186 , V_187 ) ;
if ( V_95 -> V_181 > 1 ) {
V_174 = V_188 |
V_189 ;
} else {
V_174 = V_190 |
V_191 ;
}
F_5 ( V_2 , V_174 ,
V_192 |
V_193 , V_194 ) ;
F_5 ( V_2 , 1 << V_195 ,
V_196 , V_187 ) ;
F_1 ( V_2 , V_169 , V_197 ) ;
if ( V_171 == V_172 ) {
V_174 = V_198 |
V_199 |
V_200 ;
} else if ( V_171 == V_178 ) {
V_174 = V_198 |
V_201 |
V_202 ;
} else if ( V_171 == V_175 ) {
V_174 = V_203 |
V_201 |
V_200 ;
} else {
return;
}
F_5 ( V_2 , V_174 ,
V_204 | V_205 |
V_206 , V_194 ) ;
F_5 ( V_2 , V_207 |
V_208 ,
V_209 |
V_210 , V_187 ) ;
F_5 ( V_2 , V_171 , V_211 ,
V_194 ) ;
}
static inline void F_61 ( struct V_1 * V_2 ,
unsigned char V_212 )
{
F_5 ( V_2 , V_212 << V_213 ,
V_214 , V_215 ) ;
}
static bool F_62 ( struct V_1 * V_2 , int V_216 )
{
T_2 V_3 ;
while ( ( V_3 = F_3 ( V_2 , V_217 ) & 0x3 ) == 0 ) {
if ( V_216 -- == 0 )
return false ;
F_63 ( 1000 ) ;
}
F_1 ( V_2 , V_3 , V_217 ) ;
return true ;
}
void F_64 ( struct V_1 * V_2 , unsigned short V_7 ,
unsigned char V_47 )
{
F_1 ( V_2 , 0xFF , V_217 ) ;
F_1 ( V_2 , V_47 , V_218 ) ;
F_1 ( V_2 , ( unsigned char ) ( V_7 >> 8 ) ,
V_219 ) ;
F_1 ( V_2 , ( unsigned char ) ( V_7 >> 0 ) ,
V_220 ) ;
F_1 ( V_2 , V_221 ,
V_222 ) ;
F_62 ( V_2 , 1000 ) ;
}
static void F_65 ( struct V_1 * V_2 , bool V_99 )
{
F_7 ( V_2 , ! V_99 , V_223 ,
V_224 ,
V_225 ) ;
}
static void F_66 ( struct V_1 * V_2 , T_1 V_99 )
{
F_7 ( V_2 , V_99 , V_223 ,
V_226 ,
V_227 ) ;
}
static void F_67 ( struct V_1 * V_2 , T_1 V_99 )
{
F_7 ( V_2 , V_99 , V_223 ,
V_228 ,
V_229 ) ;
}
static void F_68 ( struct V_1 * V_2 , T_1 V_99 )
{
F_7 ( V_2 , V_99 , V_223 ,
V_230 ,
V_231 ) ;
}
static void F_69 ( struct V_1 * V_2 , T_1 V_99 )
{
F_7 ( V_2 , V_99 , V_223 ,
V_232 ,
V_233 ) ;
}
static void F_70 ( struct V_1 * V_2 , T_1 V_99 )
{
F_7 ( V_2 , V_99 , V_223 ,
V_234 ,
V_235 ) ;
}
static void F_71 ( struct V_1 * V_2 , T_1 V_99 )
{
F_7 ( V_2 , V_99 , V_223 ,
V_236 ,
V_237 ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
const struct V_238 * V_239 = V_2 -> V_239 . V_7 ;
unsigned int V_48 ;
F_57 V_3 ;
if ( V_239 -> V_240 == 1 ) {
F_66 ( V_2 , 0 ) ;
F_65 ( V_2 , true ) ;
return;
}
F_69 ( V_2 , 0 ) ;
for ( V_48 = 0 ; V_48 < 5 ; ++ V_48 ) {
V_3 = F_3 ( V_2 , V_241 ) ;
if ( ! ( V_3 & V_242 ) )
break;
F_73 ( 1000 , 2000 ) ;
}
if ( V_3 & V_242 )
F_27 ( V_2 -> V_28 , L_9 ) ;
else
F_10 ( V_2 -> V_28 , L_10 , V_48 ) ;
F_68 ( V_2 , 1 ) ;
}
static int F_74 ( struct V_1 * V_2 )
{
const struct V_238 * V_239 = V_2 -> V_239 . V_7 ;
unsigned int V_48 ;
T_1 V_3 ;
if ( V_239 -> V_240 == 1 ) {
F_65 ( V_2 , false ) ;
F_66 ( V_2 , 0 ) ;
F_66 ( V_2 , 1 ) ;
return 0 ;
}
F_69 ( V_2 , 1 ) ;
F_68 ( V_2 , 0 ) ;
for ( V_48 = 0 ; V_48 < 5 ; ++ V_48 ) {
V_3 = F_3 ( V_2 , V_241 ) & V_242 ;
if ( V_3 )
break;
F_73 ( 1000 , 2000 ) ;
}
if ( ! V_3 ) {
F_75 ( V_2 -> V_28 , L_11 ) ;
return - V_243 ;
}
F_10 ( V_2 -> V_28 , L_12 , V_48 ) ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 ,
const struct V_244 * V_245 ,
unsigned long V_97 )
{
const struct V_246 * V_247 = V_245 -> V_248 ;
const struct V_249 * V_250 = V_245 -> V_251 ;
const struct V_252 * V_253 = V_245 -> V_253 ;
for (; V_247 -> V_97 != ~ 0UL ; V_247 ++ )
if ( V_97 <= V_247 -> V_97 )
break;
for (; V_250 -> V_97 != ~ 0UL ; V_250 ++ )
if ( V_97 <= V_250 -> V_97 )
break;
for (; V_253 -> V_97 != ~ 0UL ; V_253 ++ )
if ( V_97 <= V_253 -> V_97 )
break;
if ( V_247 -> V_97 == ~ 0UL ||
V_250 -> V_97 == ~ 0UL ||
V_253 -> V_97 == ~ 0UL )
return - V_254 ;
F_64 ( V_2 , V_247 -> V_255 [ 0 ] . V_256 ,
V_257 ) ;
F_64 ( V_2 , V_247 -> V_255 [ 0 ] . V_258 ,
V_259 ) ;
F_64 ( V_2 , V_250 -> V_260 [ 0 ] ,
V_261 ) ;
F_64 ( V_2 , 0 , V_262 ) ;
F_64 ( V_2 , V_263 ,
V_264 ) ;
F_64 ( V_2 , V_253 -> V_265 , V_266 ) ;
F_64 ( V_2 , V_253 -> V_267 ,
V_268 ) ;
F_64 ( V_2 , V_253 -> V_269 ,
V_270 ) ;
F_64 ( V_2 , V_271 ,
V_272 ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 )
{
const struct V_238 * V_239 = V_2 -> V_239 . V_7 ;
const struct V_244 * V_245 = V_2 -> V_273 ;
unsigned long V_97 = V_2 -> V_95 . V_96 . V_97 ;
int V_49 ;
F_72 ( V_2 ) ;
if ( V_239 -> V_274 )
F_67 ( V_2 , 1 ) ;
F_1 ( V_2 , V_275 , V_276 ) ;
F_1 ( V_2 , 0 , V_276 ) ;
F_1 ( V_2 , V_277 , V_278 ) ;
F_61 ( V_2 , 1 ) ;
F_1 ( V_2 , V_279 ,
V_280 ) ;
F_61 ( V_2 , 0 ) ;
if ( V_245 -> V_281 )
V_49 = V_245 -> V_281 ( V_2 , V_245 , V_97 ) ;
else
V_49 = V_239 -> V_282 ( V_2 , V_245 , V_97 ) ;
if ( V_49 ) {
F_75 ( V_2 -> V_28 , L_13 ,
V_97 ) ;
return V_49 ;
}
return F_74 ( V_2 ) ;
}
static int F_78 ( struct V_1 * V_2 , void * V_7 ,
struct V_283 * V_284 )
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
static enum V_285 F_80 ( struct V_1 * V_2 ,
void * V_7 )
{
return F_3 ( V_2 , V_241 ) & V_286 ?
V_287 : V_288 ;
}
static void F_81 ( struct V_1 * V_2 , void * V_7 ,
bool V_289 , bool V_290 , bool V_291 )
{
T_1 V_292 = V_2 -> V_293 ;
if ( V_289 || V_290 || ! V_291 )
V_2 -> V_293 |= V_294 ;
else
V_2 -> V_293 &= ~ V_294 ;
if ( V_292 != V_2 -> V_293 )
F_1 ( V_2 , V_2 -> V_293 , V_295 ) ;
}
static void F_82 ( struct V_1 * V_2 , void * V_7 )
{
F_1 ( V_2 , V_286 | V_294 , V_296 ) ;
F_1 ( V_2 , V_297 | V_298 ,
V_299 ) ;
F_1 ( V_2 , V_2 -> V_293 , V_295 ) ;
F_1 ( V_2 , V_297 | V_298 ,
V_299 ) ;
F_1 ( V_2 , ~ ( V_297 | V_298 ) ,
V_300 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
T_1 V_301 ;
if ( V_2 -> V_95 . V_96 . V_302 )
V_301 = V_303 ;
else
V_301 = V_304 ;
F_5 ( V_2 , V_305 ,
V_306 , V_307 ) ;
F_5 ( V_2 , V_301 , V_308 , V_309 ) ;
F_5 ( V_2 , V_310 ,
V_311 , V_312 ) ;
}
static void F_84 ( struct V_1 * V_2 , struct V_283 * V_284 )
{
struct V_313 V_314 ;
T_1 V_3 ;
F_85 ( & V_314 , V_284 ) ;
if ( F_49 ( V_2 -> V_95 . V_136 ) )
V_314 . V_315 = V_316 ;
else if ( F_50 ( V_2 -> V_95 . V_136 ) )
V_314 . V_315 = V_317 ;
else
V_314 . V_315 = V_318 ;
switch ( V_2 -> V_95 . V_140 ) {
case V_141 :
if ( V_2 -> V_95 . V_319 == V_320 )
V_314 . V_321 = V_322 ;
else
V_314 . V_321 = V_323 ;
V_314 . V_324 =
V_325 ;
break;
case V_326 :
if ( V_2 -> V_95 . V_319 == V_327 )
V_314 . V_321 = V_322 ;
else
V_314 . V_321 = V_328 ;
V_314 . V_324 =
V_329 ;
break;
default:
V_314 . V_321 = V_323 ;
V_314 . V_324 =
V_325 ;
break;
}
V_314 . V_330 = V_331 ;
V_3 = ( V_314 . V_330 & 3 ) << 4 | ( V_314 . V_315 & 3 ) ;
if ( V_314 . V_332 & 15 )
V_3 |= V_333 ;
if ( V_314 . V_334 || V_314 . V_335 )
V_3 |= V_336 ;
if ( V_314 . V_337 || V_314 . V_338 )
V_3 |= V_339 ;
F_1 ( V_2 , V_3 , V_340 ) ;
V_3 = ( ( V_314 . V_321 & 0x3 ) << 6 ) |
( ( V_314 . V_341 & 0x3 ) << 4 ) |
( V_314 . V_332 & 0xf ) ;
F_1 ( V_2 , V_3 , V_342 ) ;
V_3 = ( ( V_314 . V_324 & 0x7 ) << 4 ) |
( ( V_314 . V_343 & 0x3 ) << 2 ) |
( V_314 . V_344 & 0x3 ) ;
if ( V_314 . V_345 )
V_3 |= V_346 ;
F_1 ( V_2 , V_3 , V_347 ) ;
V_3 = V_314 . V_348 & 0x7f ;
F_1 ( V_2 , V_3 , V_349 ) ;
V_3 = ( ( ( V_2 -> V_95 . V_96 . V_350 + 1 ) <<
V_351 ) &
V_352 ) |
( ( V_2 -> V_95 . V_96 . V_353 <<
V_354 ) &
V_355 ) ;
F_1 ( V_2 , V_3 , V_356 ) ;
V_3 = ( ( V_314 . V_357 & 0x3 ) << 2 ) |
( V_314 . V_358 & 0x3 ) ;
F_1 ( V_2 , V_3 , V_359 ) ;
F_1 ( V_2 , V_314 . V_334 & 0xff , V_360 ) ;
F_1 ( V_2 , ( V_314 . V_334 >> 8 ) & 0xff , V_361 ) ;
F_1 ( V_2 , V_314 . V_335 & 0xff , V_362 ) ;
F_1 ( V_2 , ( V_314 . V_335 >> 8 ) & 0xff , V_363 ) ;
F_1 ( V_2 , V_314 . V_337 & 0xff , V_364 ) ;
F_1 ( V_2 , ( V_314 . V_337 >> 8 ) & 0xff , V_365 ) ;
F_1 ( V_2 , V_314 . V_338 & 0xff , V_366 ) ;
F_1 ( V_2 , ( V_314 . V_338 >> 8 ) & 0xff , V_367 ) ;
}
static void F_86 ( struct V_1 * V_2 ,
struct V_283 * V_284 )
{
struct V_368 V_314 ;
T_1 V_369 [ 10 ] ;
T_4 V_370 ;
V_370 = F_87 ( & V_314 , V_284 ) ;
if ( V_370 < 0 )
return;
V_370 = F_88 ( & V_314 , V_369 , sizeof( V_369 ) ) ;
if ( V_370 < 0 ) {
F_75 ( V_2 -> V_28 , L_14 ,
V_370 ) ;
return;
}
F_7 ( V_2 , 0 , V_371 , V_372 ,
V_373 ) ;
F_1 ( V_2 , V_369 [ 2 ] , V_374 ) ;
F_1 ( V_2 , V_369 [ 4 ] , V_375 ) ;
F_1 ( V_2 , V_369 [ 5 ] , V_376 ) ;
F_1 ( V_2 , V_369 [ 6 ] , V_377 ) ;
F_1 ( V_2 , V_369 [ 7 ] , V_378 ) ;
F_1 ( V_2 , V_369 [ 8 ] , V_379 ) ;
if ( V_314 . V_380 >= V_381 )
F_1 ( V_2 , V_369 [ 9 ] , V_382 ) ;
F_1 ( V_2 , 1 , V_383 ) ;
F_1 ( V_2 , 0x11 , V_384 ) ;
F_7 ( V_2 , 1 , V_371 , V_372 ,
V_373 ) ;
}
static void F_89 ( struct V_1 * V_2 ,
const struct V_283 * V_284 )
{
T_1 V_385 ;
struct V_386 * V_387 = & V_2 -> V_95 . V_96 ;
int V_388 , V_389 , V_390 , V_391 , V_392 , V_393 ;
unsigned int V_394 ;
V_387 -> V_97 = V_284 -> clock * 1000 ;
F_10 ( V_2 -> V_28 , L_15 , V_387 -> V_97 ) ;
V_385 = ( V_2 -> V_95 . V_395 ?
V_396 :
V_397 ) ;
V_385 |= V_284 -> V_54 & V_398 ?
V_399 :
V_400 ;
V_385 |= V_284 -> V_54 & V_401 ?
V_402 :
V_403 ;
V_385 |= ( V_387 -> V_302 ?
V_404 :
V_405 ) ;
if ( V_2 -> V_406 == 39 )
V_385 |= V_407 ;
else
V_385 |= V_284 -> V_54 & V_408 ?
V_407 :
V_409 ;
V_385 |= V_284 -> V_54 & V_408 ?
V_410 :
V_411 ;
V_385 |= V_2 -> V_412 ?
V_413 :
V_414 ;
F_1 ( V_2 , V_385 , V_415 ) ;
V_394 = V_284 -> V_394 ;
V_389 = V_284 -> V_416 - V_284 -> V_394 ;
V_391 = V_284 -> V_417 - V_284 -> V_394 ;
V_393 = V_284 -> V_418 - V_284 -> V_417 ;
if ( V_284 -> V_54 & V_408 ) {
V_394 /= 2 ;
V_389 /= 2 ;
V_391 /= 2 ;
V_393 /= 2 ;
}
F_1 ( V_2 , V_284 -> V_419 >> 8 , V_420 ) ;
F_1 ( V_2 , V_284 -> V_419 , V_421 ) ;
F_1 ( V_2 , V_394 >> 8 , V_422 ) ;
F_1 ( V_2 , V_394 , V_423 ) ;
V_388 = V_284 -> V_424 - V_284 -> V_419 ;
F_1 ( V_2 , V_388 >> 8 , V_425 ) ;
F_1 ( V_2 , V_388 , V_426 ) ;
F_1 ( V_2 , V_389 , V_427 ) ;
V_390 = V_284 -> V_428 - V_284 -> V_419 ;
F_1 ( V_2 , V_390 >> 8 , V_429 ) ;
F_1 ( V_2 , V_390 , V_430 ) ;
F_1 ( V_2 , V_391 , V_431 ) ;
V_392 = V_284 -> V_432 - V_284 -> V_428 ;
F_1 ( V_2 , V_392 >> 8 , V_433 ) ;
F_1 ( V_2 , V_392 , V_434 ) ;
F_1 ( V_2 , V_393 , V_435 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
T_1 V_436 ;
F_1 ( V_2 , 12 , V_437 ) ;
F_1 ( V_2 , 32 , V_438 ) ;
F_1 ( V_2 , 1 , V_439 ) ;
F_1 ( V_2 , 0x0B , V_440 ) ;
F_1 ( V_2 , 0x16 , V_441 ) ;
F_1 ( V_2 , 0x21 , V_442 ) ;
V_436 = 0x7F ;
V_436 &= ~ V_443 ;
F_1 ( V_2 , V_436 , V_101 ) ;
V_436 &= ~ V_444 ;
F_1 ( V_2 , V_436 , V_101 ) ;
if ( F_53 ( V_2 ) ) {
V_436 &= ~ V_445 ;
F_1 ( V_2 , V_436 , V_101 ) ;
}
if ( F_53 ( V_2 ) )
F_1 ( V_2 , V_446 ,
V_447 ) ;
else
F_1 ( V_2 , V_448 ,
V_447 ) ;
}
static void F_91 ( struct V_1 * V_2 )
{
unsigned int V_449 ;
unsigned int V_48 ;
T_1 V_3 ;
switch ( V_2 -> V_450 ) {
case 0x130a :
V_449 = 4 ;
break;
case 0x131a :
V_449 = 1 ;
break;
default:
return;
}
F_1 ( V_2 , ( T_1 ) ~ V_451 , V_452 ) ;
V_3 = F_3 ( V_2 , V_415 ) ;
for ( V_48 = 0 ; V_48 < V_449 ; V_48 ++ )
F_1 ( V_2 , V_3 , V_415 ) ;
}
static void F_92 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0 , V_453 ) ;
F_1 ( V_2 , 0 , V_454 ) ;
}
static void F_93 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_455 ,
V_454 ) ;
}
static int F_94 ( struct V_1 * V_2 , struct V_283 * V_284 )
{
int V_49 ;
F_93 ( V_2 ) ;
V_2 -> V_406 = F_95 ( V_284 ) ;
if ( ! V_2 -> V_406 ) {
F_10 ( V_2 -> V_28 , L_16 ) ;
} else {
F_10 ( V_2 -> V_28 , L_17 , V_2 -> V_406 ) ;
}
if ( ( V_2 -> V_406 == 6 ) || ( V_2 -> V_406 == 7 ) ||
( V_2 -> V_406 == 21 ) || ( V_2 -> V_406 == 22 ) ||
( V_2 -> V_406 == 2 ) || ( V_2 -> V_406 == 3 ) ||
( V_2 -> V_406 == 17 ) || ( V_2 -> V_406 == 18 ) )
V_2 -> V_95 . V_140 = V_141 ;
else
V_2 -> V_95 . V_140 = V_326 ;
V_2 -> V_95 . V_96 . V_353 = 0 ;
V_2 -> V_95 . V_96 . V_350 = 0 ;
if ( V_2 -> V_273 -> V_456 )
V_2 -> V_95 . V_121 =
V_2 -> V_273 -> V_456 ;
else
V_2 -> V_95 . V_121 = V_105 ;
if ( V_2 -> V_273 -> V_457 )
V_2 -> V_95 . V_319 =
V_2 -> V_273 -> V_457 ;
else
V_2 -> V_95 . V_319 = V_458 ;
V_2 -> V_95 . V_136 = V_105 ;
V_2 -> V_95 . V_181 = 0 ;
V_2 -> V_95 . V_395 = 0 ;
V_2 -> V_95 . V_96 . V_302 = true ;
F_89 ( V_2 , V_284 ) ;
V_49 = V_2 -> V_239 . V_459 -> V_460 ( V_2 , V_2 -> V_239 . V_7 , & V_2 -> V_461 ) ;
if ( V_49 )
return V_49 ;
V_2 -> V_239 . V_462 = true ;
F_90 ( V_2 ) ;
if ( V_2 -> V_463 ) {
F_10 ( V_2 -> V_28 , L_18 ) ;
F_37 ( V_2 ) ;
F_39 ( V_2 , true ) ;
}
if ( V_2 -> V_412 ) {
F_10 ( V_2 -> V_28 , L_19 , V_89 ) ;
F_84 ( V_2 , V_284 ) ;
F_86 ( V_2 , V_284 ) ;
} else {
F_10 ( V_2 -> V_28 , L_20 , V_89 ) ;
}
F_60 ( V_2 ) ;
F_59 ( V_2 ) ;
F_52 ( V_2 ) ;
F_83 ( V_2 ) ;
F_91 ( V_2 ) ;
if ( V_2 -> V_464 && V_2 -> V_412 )
F_92 ( V_2 ) ;
return 0 ;
}
static void F_96 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_465 ,
V_466 ) ;
F_1 ( V_2 , V_467 |
V_468 ,
V_469 ) ;
}
static void F_97 ( struct V_1 * V_2 )
{
T_1 V_470 ;
V_470 = F_3 ( V_2 , V_471 ) |
V_472 |
V_473 ;
F_1 ( V_2 , V_470 , V_471 ) ;
F_1 ( V_2 , 0xff , V_474 ) ;
F_1 ( V_2 , 0xff , V_475 ) ;
F_1 ( V_2 , 0xff , V_476 ) ;
F_1 ( V_2 , 0xff , V_453 ) ;
F_1 ( V_2 , 0xff , V_295 ) ;
F_1 ( V_2 , 0xff , V_466 ) ;
F_1 ( V_2 , 0xff , V_469 ) ;
F_1 ( V_2 , 0xff , V_477 ) ;
F_1 ( V_2 , 0xff , V_478 ) ;
F_1 ( V_2 , 0xff , V_479 ) ;
F_1 ( V_2 , 0xff , V_480 ) ;
F_1 ( V_2 , 0xff , V_481 ) ;
F_1 ( V_2 , 0xff , V_482 ) ;
F_1 ( V_2 , 0xff , V_14 ) ;
F_1 ( V_2 , 0xff , V_17 ) ;
F_1 ( V_2 , 0xff , V_483 ) ;
F_1 ( V_2 , 0xff , V_484 ) ;
F_1 ( V_2 , 0xff , V_454 ) ;
F_1 ( V_2 , 0xff , V_485 ) ;
F_1 ( V_2 , 0xff , V_300 ) ;
F_1 ( V_2 , 0xff , V_21 ) ;
F_1 ( V_2 , 0xff , V_486 ) ;
F_1 ( V_2 , 0xff , V_487 ) ;
F_1 ( V_2 , 0xff , V_488 ) ;
F_1 ( V_2 , 0xff , V_489 ) ;
V_470 &= ~ ( V_472 |
V_473 ) ;
F_1 ( V_2 , V_470 , V_471 ) ;
}
static void F_98 ( struct V_1 * V_2 )
{
V_2 -> V_490 = true ;
F_94 ( V_2 , & V_2 -> V_461 ) ;
}
static void F_99 ( struct V_1 * V_2 )
{
if ( V_2 -> V_239 . V_462 ) {
V_2 -> V_239 . V_459 -> V_491 ( V_2 , V_2 -> V_239 . V_7 ) ;
V_2 -> V_239 . V_462 = false ;
}
V_2 -> V_490 = false ;
}
static void F_100 ( struct V_1 * V_2 )
{
int V_289 = V_2 -> V_289 ;
if ( V_2 -> V_290 ) {
V_289 = V_492 ;
} else if ( V_289 == V_493 ) {
if ( V_2 -> V_291 )
V_289 = V_494 ;
else
V_289 = V_492 ;
}
if ( V_289 == V_492 ) {
if ( V_2 -> V_490 )
F_99 ( V_2 ) ;
} else {
if ( ! V_2 -> V_490 )
F_98 ( V_2 ) ;
}
}
static void F_101 ( struct V_1 * V_2 )
{
if ( V_2 -> V_239 . V_459 -> V_495 )
V_2 -> V_239 . V_459 -> V_495 ( V_2 , V_2 -> V_239 . V_7 ,
V_2 -> V_289 , V_2 -> V_290 ,
V_2 -> V_291 ) ;
}
static enum V_285
F_102 ( struct V_496 * V_497 , bool V_289 )
{
struct V_1 * V_2 = F_103 ( V_497 , struct V_1 ,
V_497 ) ;
F_16 ( & V_2 -> V_498 ) ;
V_2 -> V_289 = V_493 ;
F_100 ( V_2 ) ;
F_101 ( V_2 ) ;
F_17 ( & V_2 -> V_498 ) ;
return V_2 -> V_239 . V_459 -> V_499 ( V_2 , V_2 -> V_239 . V_7 ) ;
}
static int F_104 ( struct V_496 * V_497 )
{
struct V_1 * V_2 = F_103 ( V_497 , struct V_1 ,
V_497 ) ;
struct V_500 * V_500 ;
int V_49 = 0 ;
if ( ! V_2 -> V_501 )
return 0 ;
V_500 = F_105 ( V_497 , V_2 -> V_501 ) ;
if ( V_500 ) {
F_10 ( V_2 -> V_28 , L_21 ,
V_500 -> V_502 , V_500 -> V_503 ) ;
V_2 -> V_412 = F_106 ( V_500 ) ;
V_2 -> V_463 = F_107 ( V_500 ) ;
F_108 ( V_497 , V_500 ) ;
V_49 = F_109 ( V_497 , V_500 ) ;
F_110 ( V_497 , V_500 ) ;
F_111 ( V_500 ) ;
} else {
F_10 ( V_2 -> V_28 , L_22 ) ;
}
return V_49 ;
}
static void F_112 ( struct V_496 * V_497 )
{
struct V_1 * V_2 = F_103 ( V_497 , struct V_1 ,
V_497 ) ;
F_16 ( & V_2 -> V_498 ) ;
V_2 -> V_289 = V_497 -> V_289 ;
F_100 ( V_2 ) ;
F_101 ( V_2 ) ;
F_17 ( & V_2 -> V_498 ) ;
}
static int F_113 ( struct V_504 * V_505 )
{
struct V_1 * V_2 = V_505 -> V_506 ;
struct V_507 * V_508 = V_505 -> V_508 ;
struct V_496 * V_497 = & V_2 -> V_497 ;
V_497 -> V_509 = 1 ;
V_497 -> V_510 = V_511 ;
F_114 ( V_497 , & V_512 ) ;
F_115 ( V_505 -> V_28 , V_497 , & V_513 ,
V_514 ) ;
F_116 ( V_497 , V_508 ) ;
return 0 ;
}
static enum V_515
F_117 ( struct V_504 * V_505 ,
const struct V_283 * V_284 )
{
struct V_1 * V_2 = V_505 -> V_506 ;
struct V_496 * V_497 = & V_2 -> V_497 ;
enum V_515 V_516 = V_517 ;
if ( V_284 -> V_54 & V_518 )
return V_519 ;
if ( V_2 -> V_273 -> V_520 )
V_516 = V_2 -> V_273 -> V_520 ( V_497 , V_284 ) ;
return V_516 ;
}
static void F_118 ( struct V_504 * V_505 ,
struct V_283 * V_521 ,
struct V_283 * V_284 )
{
struct V_1 * V_2 = V_505 -> V_506 ;
F_16 ( & V_2 -> V_498 ) ;
memcpy ( & V_2 -> V_461 , V_284 , sizeof( V_2 -> V_461 ) ) ;
F_17 ( & V_2 -> V_498 ) ;
}
static void F_119 ( struct V_504 * V_505 )
{
struct V_1 * V_2 = V_505 -> V_506 ;
F_16 ( & V_2 -> V_498 ) ;
V_2 -> V_290 = true ;
F_100 ( V_2 ) ;
F_101 ( V_2 ) ;
F_17 ( & V_2 -> V_498 ) ;
}
static void F_120 ( struct V_504 * V_505 )
{
struct V_1 * V_2 = V_505 -> V_506 ;
F_16 ( & V_2 -> V_498 ) ;
V_2 -> V_290 = false ;
F_100 ( V_2 ) ;
F_101 ( V_2 ) ;
F_17 ( & V_2 -> V_498 ) ;
}
static T_5 F_121 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_25 ;
unsigned int V_26 ;
V_26 = F_3 ( V_2 , V_20 ) ;
if ( ! V_26 )
return V_522 ;
F_1 ( V_2 , V_26 , V_20 ) ;
V_25 -> V_26 = V_26 ;
F_122 ( & V_25 -> V_30 ) ;
return V_523 ;
}
static T_5 F_123 ( int V_524 , void * V_525 )
{
struct V_1 * V_2 = V_525 ;
T_1 V_526 ;
T_5 V_49 = V_522 ;
if ( V_2 -> V_25 )
V_49 = F_121 ( V_2 ) ;
V_526 = F_3 ( V_2 , V_299 ) ;
if ( V_526 ) {
F_1 ( V_2 , ~ 0 , V_300 ) ;
return V_527 ;
}
return V_49 ;
}
void F_124 ( struct V_1 * V_2 , bool V_528 , bool V_529 )
{
F_16 ( & V_2 -> V_498 ) ;
if ( ! V_2 -> V_289 ) {
if ( ! V_529 )
V_2 -> V_291 = false ;
if ( V_528 )
V_2 -> V_291 = true ;
F_100 ( V_2 ) ;
F_101 ( V_2 ) ;
}
F_17 ( & V_2 -> V_498 ) ;
}
void F_125 ( struct V_530 * V_28 , bool V_528 , bool V_529 )
{
struct V_1 * V_2 = F_126 ( V_28 ) ;
F_124 ( V_2 , V_528 , V_529 ) ;
}
static T_5 F_127 ( int V_524 , void * V_525 )
{
struct V_1 * V_2 = V_525 ;
T_1 V_526 , V_531 , V_532 , V_533 ;
V_526 = F_3 ( V_2 , V_299 ) ;
V_531 = F_3 ( V_2 , V_296 ) ;
V_533 = F_3 ( V_2 , V_241 ) ;
V_532 = 0 ;
if ( V_526 & V_297 )
V_532 |= V_286 ;
if ( V_526 & V_534 )
V_532 |= V_535 ;
if ( V_526 & V_536 )
V_532 |= V_537 ;
if ( V_526 & V_538 )
V_532 |= V_539 ;
if ( V_526 & V_540 )
V_532 |= V_541 ;
if ( V_532 )
F_5 ( V_2 , ~ V_531 , V_532 , V_296 ) ;
if ( V_526 &
( V_298 | V_297 ) )
F_124 ( V_2 ,
V_533 & V_286 ,
V_533 & V_294 ) ;
if ( V_526 & V_297 ) {
F_10 ( V_2 -> V_28 , L_23 ,
V_531 & V_286 ? L_24 : L_25 ) ;
if ( V_2 -> V_505 . V_28 )
F_128 ( V_2 -> V_505 . V_28 ) ;
}
F_1 ( V_2 , V_526 , V_299 ) ;
F_1 ( V_2 , ~ ( V_297 | V_298 ) ,
V_300 ) ;
return V_523 ;
}
static int F_129 ( struct V_1 * V_2 )
{
unsigned int V_48 ;
T_1 V_542 ;
V_542 = F_3 ( V_2 , V_543 ) ;
if ( V_542 == V_544 ) {
if ( ! V_2 -> V_273 -> V_545 || ! V_2 -> V_273 -> V_546 ) {
F_75 ( V_2 -> V_28 ,
L_26 ) ;
return - V_547 ;
}
V_2 -> V_239 . V_459 = V_2 -> V_273 -> V_545 ;
V_2 -> V_239 . V_7 = V_2 -> V_273 -> V_548 ;
V_2 -> V_239 . V_71 = V_2 -> V_273 -> V_546 ;
return 0 ;
}
for ( V_48 = 0 ; V_48 < F_58 ( V_549 ) ; ++ V_48 ) {
if ( V_549 [ V_48 ] . type == V_542 ) {
V_2 -> V_239 . V_459 = & V_550 ;
V_2 -> V_239 . V_71 = V_549 [ V_48 ] . V_71 ;
V_2 -> V_239 . V_7 = ( void * ) & V_549 [ V_48 ] ;
if ( ! V_549 [ V_48 ] . V_282 &&
! V_2 -> V_273 -> V_281 ) {
F_75 ( V_2 -> V_28 , L_27 ,
V_2 -> V_239 . V_71 ) ;
return - V_547 ;
}
return 0 ;
}
}
F_75 ( V_2 -> V_28 , L_28 , V_542 ) ;
return - V_547 ;
}
static struct V_1 *
F_130 ( struct V_551 * V_552 ,
const struct V_244 * V_273 )
{
struct V_530 * V_28 = & V_552 -> V_28 ;
struct V_553 * V_554 = V_28 -> V_555 ;
struct V_556 V_557 ;
struct V_553 * V_558 ;
struct V_1 * V_2 ;
struct V_559 * V_560 = NULL ;
int V_524 ;
int V_49 ;
T_2 V_3 = 1 ;
T_1 V_561 ;
T_1 V_562 ;
T_1 V_563 ;
T_1 V_564 ;
V_2 = F_20 ( V_28 , sizeof( * V_2 ) , V_62 ) ;
if ( ! V_2 )
return F_21 ( - V_63 ) ;
V_2 -> V_273 = V_273 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_86 = 48000 ;
V_2 -> V_290 = true ;
V_2 -> V_291 = true ;
V_2 -> V_293 = ( T_1 ) ~ ( V_286 | V_294 ) ;
F_22 ( & V_2 -> V_498 ) ;
F_22 ( & V_2 -> V_94 ) ;
F_131 ( & V_2 -> V_90 ) ;
V_558 = F_132 ( V_554 , L_29 , 0 ) ;
if ( V_558 ) {
V_2 -> V_501 = F_133 ( V_558 ) ;
F_134 ( V_558 ) ;
if ( ! V_2 -> V_501 ) {
F_10 ( V_2 -> V_28 , L_30 ) ;
return F_21 ( - V_565 ) ;
}
} else {
F_10 ( V_2 -> V_28 , L_31 ) ;
}
if ( ! V_273 -> V_5 ) {
const struct V_566 * V_567 ;
F_135 ( V_554 , L_32 , & V_3 ) ;
switch ( V_3 ) {
case 4 :
V_567 = & V_568 ;
V_2 -> V_6 = 2 ;
break;
case 1 :
V_567 = & V_569 ;
break;
default:
F_75 ( V_28 , L_33 ) ;
return F_21 ( - V_254 ) ;
}
V_560 = F_136 ( V_552 , V_570 , 0 ) ;
V_2 -> V_571 = F_137 ( V_28 , V_560 ) ;
if ( F_138 ( V_2 -> V_571 ) ) {
V_49 = F_139 ( V_2 -> V_571 ) ;
goto V_572;
}
V_2 -> V_5 = F_140 ( V_28 , V_2 -> V_571 , V_567 ) ;
if ( F_138 ( V_2 -> V_5 ) ) {
F_75 ( V_28 , L_34 ) ;
V_49 = F_139 ( V_2 -> V_5 ) ;
goto V_572;
}
} else {
V_2 -> V_5 = V_273 -> V_5 ;
}
V_2 -> V_573 = F_141 ( V_2 -> V_28 , L_35 ) ;
if ( F_138 ( V_2 -> V_573 ) ) {
V_49 = F_139 ( V_2 -> V_573 ) ;
F_75 ( V_2 -> V_28 , L_36 , V_49 ) ;
goto V_572;
}
V_49 = F_142 ( V_2 -> V_573 ) ;
if ( V_49 ) {
F_75 ( V_2 -> V_28 , L_37 , V_49 ) ;
goto V_572;
}
V_2 -> V_574 = F_141 ( V_2 -> V_28 , L_38 ) ;
if ( F_138 ( V_2 -> V_574 ) ) {
V_49 = F_139 ( V_2 -> V_574 ) ;
F_75 ( V_2 -> V_28 , L_39 , V_49 ) ;
goto V_575;
}
V_49 = F_142 ( V_2 -> V_574 ) ;
if ( V_49 ) {
F_75 ( V_2 -> V_28 , L_40 , V_49 ) ;
goto V_575;
}
V_2 -> V_450 = ( F_3 ( V_2 , V_576 ) << 8 )
| ( F_3 ( V_2 , V_577 ) << 0 ) ;
V_561 = F_3 ( V_2 , V_578 ) ;
V_562 = F_3 ( V_2 , V_579 ) ;
if ( V_561 != V_580 ||
( V_562 & ~ V_581 ) != V_582 ) {
F_75 ( V_28 , L_41 ,
V_2 -> V_450 , V_561 , V_562 ) ;
V_49 = - V_547 ;
goto V_583;
}
V_49 = F_129 ( V_2 ) ;
if ( V_49 < 0 )
goto V_583;
F_29 ( V_28 , L_42 ,
V_2 -> V_450 >> 12 , V_2 -> V_450 & 0xfff ,
V_562 & V_581 ? L_43 : L_44 ,
V_2 -> V_239 . V_71 ) ;
F_97 ( V_2 ) ;
V_524 = F_143 ( V_552 , 0 ) ;
if ( V_524 < 0 ) {
V_49 = V_524 ;
goto V_583;
}
V_49 = F_144 ( V_28 , V_524 , F_123 ,
F_127 , V_584 ,
F_145 ( V_28 ) , V_2 ) ;
if ( V_49 )
goto V_583;
F_36 ( V_2 ) ;
if ( ! V_2 -> V_501 ) {
V_2 -> V_501 = F_19 ( V_2 ) ;
if ( F_138 ( V_2 -> V_501 ) )
V_2 -> V_501 = NULL ;
}
V_2 -> V_505 . V_506 = V_2 ;
V_2 -> V_505 . V_585 = & V_586 ;
#ifdef F_146
V_2 -> V_505 . V_555 = V_552 -> V_28 . V_555 ;
#endif
F_96 ( V_2 ) ;
if ( V_2 -> V_239 . V_459 -> V_587 )
V_2 -> V_239 . V_459 -> V_587 ( V_2 , V_2 -> V_239 . V_7 ) ;
memset ( & V_557 , 0 , sizeof( V_557 ) ) ;
V_557 . V_68 = V_28 ;
V_557 . V_588 = V_589 ;
V_563 = F_3 ( V_2 , V_590 ) ;
V_564 = F_3 ( V_2 , V_591 ) ;
if ( V_560 && V_564 & V_592 ) {
struct V_593 V_594 ;
V_594 . V_595 = V_560 -> V_596 ;
V_594 . V_597 = V_2 -> V_571 ;
V_594 . V_524 = V_524 ;
V_594 . V_2 = V_2 ;
V_594 . V_598 = V_2 -> V_497 . V_598 ;
V_2 -> V_102 = F_40 ;
V_2 -> V_103 = F_41 ;
V_557 . V_71 = L_45 ;
V_557 . V_7 = & V_594 ;
V_557 . V_599 = sizeof( V_594 ) ;
V_557 . V_600 = F_147 ( 32 ) ;
V_2 -> V_594 = F_148 ( & V_557 ) ;
} else if ( V_563 & V_601 ) {
struct V_602 V_594 ;
V_594 . V_2 = V_2 ;
V_594 . V_603 = F_1 ;
V_594 . V_604 = F_3 ;
V_2 -> V_102 = F_42 ;
V_2 -> V_103 = F_43 ;
V_557 . V_71 = L_46 ;
V_557 . V_7 = & V_594 ;
V_557 . V_599 = sizeof( V_594 ) ;
V_557 . V_600 = F_147 ( 32 ) ;
V_2 -> V_594 = F_148 ( & V_557 ) ;
}
if ( V_2 -> V_25 )
F_8 ( V_2 ) ;
F_149 ( V_552 , V_2 ) ;
return V_2 ;
V_583:
if ( V_2 -> V_25 ) {
F_150 ( & V_2 -> V_25 -> V_43 ) ;
V_2 -> V_501 = NULL ;
}
F_151 ( V_2 -> V_574 ) ;
V_575:
F_151 ( V_2 -> V_573 ) ;
V_572:
F_152 ( V_2 -> V_501 ) ;
return F_21 ( V_49 ) ;
}
static void F_153 ( struct V_1 * V_2 )
{
if ( V_2 -> V_594 && ! F_138 ( V_2 -> V_594 ) )
F_154 ( V_2 -> V_594 ) ;
F_1 ( V_2 , ~ 0 , V_300 ) ;
F_151 ( V_2 -> V_574 ) ;
F_151 ( V_2 -> V_573 ) ;
if ( V_2 -> V_25 )
F_150 ( & V_2 -> V_25 -> V_43 ) ;
else
F_152 ( V_2 -> V_501 ) ;
}
int F_155 ( struct V_551 * V_552 ,
const struct V_244 * V_273 )
{
struct V_1 * V_2 ;
int V_49 ;
V_2 = F_130 ( V_552 , V_273 ) ;
if ( F_138 ( V_2 ) )
return F_139 ( V_2 ) ;
V_49 = F_156 ( & V_2 -> V_505 ) ;
if ( V_49 < 0 ) {
F_153 ( V_2 ) ;
return V_49 ;
}
return 0 ;
}
void F_157 ( struct V_551 * V_552 )
{
struct V_1 * V_2 = F_158 ( V_552 ) ;
F_159 ( & V_2 -> V_505 ) ;
F_153 ( V_2 ) ;
}
int F_160 ( struct V_551 * V_552 , struct V_507 * V_508 ,
const struct V_244 * V_273 )
{
struct V_1 * V_2 ;
int V_49 ;
V_2 = F_130 ( V_552 , V_273 ) ;
if ( F_138 ( V_2 ) )
return F_139 ( V_2 ) ;
V_49 = F_161 ( V_508 , & V_2 -> V_505 , NULL ) ;
if ( V_49 ) {
F_157 ( V_552 ) ;
F_162 ( L_47 ) ;
return V_49 ;
}
return 0 ;
}
void F_163 ( struct V_530 * V_28 )
{
struct V_1 * V_2 = F_126 ( V_28 ) ;
F_153 ( V_2 ) ;
}
