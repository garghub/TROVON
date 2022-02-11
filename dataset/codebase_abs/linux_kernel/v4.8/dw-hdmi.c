static void F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + ( V_4 << 2 ) ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , int V_4 )
{
return F_4 ( V_2 -> V_5 + ( V_4 << 2 ) ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
F_6 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 , int V_4 )
{
return F_8 ( V_2 -> V_5 + V_4 ) ;
}
static inline void F_9 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
V_2 -> V_6 ( V_2 , V_3 , V_4 ) ;
}
static inline T_1 F_10 ( struct V_1 * V_2 , int V_4 )
{
return V_2 -> V_7 ( V_2 , V_4 ) ;
}
static void F_11 ( struct V_1 * V_2 , T_1 V_8 , T_1 V_9 , unsigned V_10 )
{
T_1 V_3 = F_10 ( V_2 , V_10 ) & ~ V_9 ;
V_3 |= V_8 & V_9 ;
F_9 ( V_2 , V_3 , V_10 ) ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_8 , unsigned int V_10 ,
T_1 V_11 , T_1 V_9 )
{
F_11 ( V_2 , V_8 << V_11 , V_9 , V_10 ) ;
}
static void F_13 ( struct V_1 * V_2 , unsigned int V_12 ,
unsigned int V_13 )
{
F_11 ( V_2 , 0 , V_14 , V_15 ) ;
F_11 ( V_2 , 0 , V_16 , V_15 ) ;
F_9 ( V_2 , ( ( V_12 >> 16 ) & V_17 ) |
V_14 , V_15 ) ;
F_9 ( V_2 , ( V_12 >> 8 ) & 0xff , V_18 ) ;
F_9 ( V_2 , V_12 & 0xff , V_19 ) ;
F_9 ( V_2 , ( V_13 >> 16 ) & 0x0f , V_20 ) ;
F_9 ( V_2 , ( V_13 >> 8 ) & 0xff , V_21 ) ;
F_9 ( V_2 , V_13 & 0xff , V_22 ) ;
}
static unsigned int F_14 ( unsigned int V_23 , unsigned long V_24 )
{
unsigned int V_13 = ( 128 * V_23 ) / 1000 ;
unsigned int V_25 = 1 ;
while ( V_23 > 48000 ) {
V_25 *= 2 ;
V_23 /= 2 ;
}
switch ( V_23 ) {
case 32000 :
if ( V_24 == 25175000 )
V_13 = 4576 ;
else if ( V_24 == 27027000 )
V_13 = 4096 ;
else if ( V_24 == 74176000 || V_24 == 148352000 )
V_13 = 11648 ;
else
V_13 = 4096 ;
V_13 *= V_25 ;
break;
case 44100 :
if ( V_24 == 25175000 )
V_13 = 7007 ;
else if ( V_24 == 74176000 )
V_13 = 17836 ;
else if ( V_24 == 148352000 )
V_13 = 8918 ;
else
V_13 = 6272 ;
V_13 *= V_25 ;
break;
case 48000 :
if ( V_24 == 25175000 )
V_13 = 6864 ;
else if ( V_24 == 27027000 )
V_13 = 6144 ;
else if ( V_24 == 74176000 )
V_13 = 11648 ;
else if ( V_24 == 148352000 )
V_13 = 5824 ;
else
V_13 = 6144 ;
V_13 *= V_25 ;
break;
default:
break;
}
return V_13 ;
}
static void F_15 ( struct V_1 * V_2 ,
unsigned long V_24 , unsigned int V_26 )
{
unsigned long V_27 = V_24 ;
unsigned int V_13 , V_12 ;
T_2 V_28 ;
V_13 = F_14 ( V_26 , V_24 ) ;
V_28 = ( T_2 ) V_27 * V_13 ;
F_16 ( V_28 , 128 * V_26 ) ;
V_12 = V_28 ;
F_17 ( V_2 -> V_29 , L_1 ,
V_30 , V_26 , V_27 / 1000000 , ( V_27 / 1000 ) % 1000 ,
V_13 , V_12 ) ;
F_18 ( & V_2 -> V_31 ) ;
V_2 -> V_32 = V_13 ;
V_2 -> V_33 = V_12 ;
F_13 ( V_2 , V_12 , V_2 -> V_34 ? V_13 : 0 ) ;
F_19 ( & V_2 -> V_31 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_21 ( & V_2 -> V_35 ) ;
F_15 ( V_2 , 74250000 , V_2 -> V_26 ) ;
F_22 ( & V_2 -> V_35 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_21 ( & V_2 -> V_35 ) ;
F_15 ( V_2 , V_2 -> V_36 . V_37 . V_38 ,
V_2 -> V_26 ) ;
F_22 ( & V_2 -> V_35 ) ;
}
void F_24 ( struct V_1 * V_2 , unsigned int V_39 )
{
F_21 ( & V_2 -> V_35 ) ;
V_2 -> V_26 = V_39 ;
F_15 ( V_2 , V_2 -> V_36 . V_37 . V_38 ,
V_2 -> V_26 ) ;
F_22 ( & V_2 -> V_35 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
unsigned long V_40 ;
F_26 ( & V_2 -> V_31 , V_40 ) ;
V_2 -> V_34 = true ;
F_13 ( V_2 , V_2 -> V_33 , V_2 -> V_32 ) ;
F_27 ( & V_2 -> V_31 , V_40 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
unsigned long V_40 ;
F_26 ( & V_2 -> V_31 , V_40 ) ;
V_2 -> V_34 = false ;
F_13 ( V_2 , V_2 -> V_33 , 0 ) ;
F_27 ( & V_2 -> V_31 , V_40 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
int V_41 = 0 ;
T_1 V_3 ;
if ( V_2 -> V_36 . V_42 == V_43 ) {
if ( V_2 -> V_36 . V_44 == 8 )
V_41 = 0x01 ;
else if ( V_2 -> V_36 . V_44 == 10 )
V_41 = 0x03 ;
else if ( V_2 -> V_36 . V_44 == 12 )
V_41 = 0x05 ;
else if ( V_2 -> V_36 . V_44 == 16 )
V_41 = 0x07 ;
else
return;
} else if ( V_2 -> V_36 . V_42 == V_45 ) {
if ( V_2 -> V_36 . V_44 == 8 )
V_41 = 0x09 ;
else if ( V_2 -> V_36 . V_44 == 10 )
V_41 = 0x0B ;
else if ( V_2 -> V_36 . V_44 == 12 )
V_41 = 0x0D ;
else if ( V_2 -> V_36 . V_44 == 16 )
V_41 = 0x0F ;
else
return;
} else if ( V_2 -> V_36 . V_42 == V_46 ) {
if ( V_2 -> V_36 . V_44 == 8 )
V_41 = 0x16 ;
else if ( V_2 -> V_36 . V_44 == 10 )
V_41 = 0x14 ;
else if ( V_2 -> V_36 . V_44 == 12 )
V_41 = 0x12 ;
else
return;
}
V_3 = V_47 |
( ( V_41 << V_48 ) &
V_49 ) ;
F_9 ( V_2 , V_3 , V_50 ) ;
V_3 = V_51 |
V_52 |
V_53 ;
F_9 ( V_2 , V_3 , V_54 ) ;
F_9 ( V_2 , 0x0 , V_55 ) ;
F_9 ( V_2 , 0x0 , V_56 ) ;
F_9 ( V_2 , 0x0 , V_57 ) ;
F_9 ( V_2 , 0x0 , V_58 ) ;
F_9 ( V_2 , 0x0 , V_59 ) ;
F_9 ( V_2 , 0x0 , V_60 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
return V_2 -> V_36 . V_42 != V_2 -> V_36 . V_61 ;
}
static int F_31 ( struct V_1 * V_2 )
{
if ( V_2 -> V_36 . V_61 != V_46 )
return 0 ;
if ( V_2 -> V_36 . V_42 == V_43 ||
V_2 -> V_36 . V_42 == V_45 )
return 1 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
if ( V_2 -> V_36 . V_42 != V_46 )
return 0 ;
if ( V_2 -> V_36 . V_61 == V_43 ||
V_2 -> V_36 . V_61 == V_45 )
return 1 ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
const F_34 ( * V_62 ) [ 3 ] [ 4 ] = & V_63 ;
unsigned V_64 ;
T_3 V_65 = 1 ;
if ( F_30 ( V_2 ) ) {
if ( V_2 -> V_36 . V_61 == V_43 ) {
if ( V_2 -> V_36 . V_66 ==
V_67 )
V_62 = & V_68 ;
else
V_62 = & V_69 ;
} else if ( V_2 -> V_36 . V_42 == V_43 ) {
if ( V_2 -> V_36 . V_66 ==
V_67 )
V_62 = & V_70 ;
else
V_62 = & V_71 ;
V_65 = 0 ;
}
}
for ( V_64 = 0 ; V_64 < F_35 ( V_63 [ 0 ] ) ; V_64 ++ ) {
F_34 V_72 = ( * V_62 ) [ 0 ] [ V_64 ] ;
F_34 V_73 = ( * V_62 ) [ 1 ] [ V_64 ] ;
F_34 V_74 = ( * V_62 ) [ 2 ] [ V_64 ] ;
F_9 ( V_2 , V_72 & 0xff , V_75 + V_64 * 2 ) ;
F_9 ( V_2 , V_72 >> 8 , V_76 + V_64 * 2 ) ;
F_9 ( V_2 , V_73 & 0xff , V_77 + V_64 * 2 ) ;
F_9 ( V_2 , V_73 >> 8 , V_78 + V_64 * 2 ) ;
F_9 ( V_2 , V_74 & 0xff , V_79 + V_64 * 2 ) ;
F_9 ( V_2 , V_74 >> 8 , V_80 + V_64 * 2 ) ;
}
F_11 ( V_2 , V_65 , V_81 ,
V_82 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
int V_83 = 0 ;
int V_84 = V_85 ;
int V_86 = 0 ;
if ( F_32 ( V_2 ) )
V_84 = V_87 ;
else if ( F_31 ( V_2 ) )
V_86 = V_88 ;
if ( V_2 -> V_36 . V_44 == 8 )
V_83 = V_89 ;
else if ( V_2 -> V_36 . V_44 == 10 )
V_83 = V_90 ;
else if ( V_2 -> V_36 . V_44 == 12 )
V_83 = V_91 ;
else if ( V_2 -> V_36 . V_44 == 16 )
V_83 = V_92 ;
else
return;
F_9 ( V_2 , V_84 | V_86 , V_93 ) ;
F_11 ( V_2 , V_83 , V_94 ,
V_82 ) ;
F_33 ( V_2 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
unsigned int V_83 = 0 ;
unsigned int V_95 = V_96 ;
unsigned int V_97 = V_98 ;
struct V_99 * V_36 = & V_2 -> V_36 ;
T_1 V_3 , V_100 ;
if ( V_36 -> V_61 == V_43 ||
V_36 -> V_61 == V_45 ) {
if ( ! V_36 -> V_44 ) {
V_97 = V_101 ;
} else if ( V_36 -> V_44 == 8 ) {
V_83 = 4 ;
V_97 = V_101 ;
} else if ( V_36 -> V_44 == 10 ) {
V_83 = 5 ;
} else if ( V_36 -> V_44 == 12 ) {
V_83 = 6 ;
} else if ( V_36 -> V_44 == 16 ) {
V_83 = 7 ;
} else {
return;
}
} else if ( V_36 -> V_61 == V_46 ) {
if ( ! V_36 -> V_44 ||
V_36 -> V_44 == 8 )
V_95 = V_96 ;
else if ( V_36 -> V_44 == 10 )
V_95 = V_102 ;
else if ( V_36 -> V_44 == 12 )
V_95 = V_103 ;
else
return;
V_97 = V_104 ;
} else {
return;
}
V_3 = ( ( V_83 << V_105 ) &
V_106 ) |
( ( V_36 -> V_107 <<
V_108 ) &
V_109 ) ;
F_9 ( V_2 , V_3 , V_110 ) ;
F_11 ( V_2 , V_111 ,
V_112 , V_113 ) ;
if ( V_36 -> V_107 > 1 ) {
V_100 = V_114 |
V_115 ;
} else {
V_100 = V_116 |
V_117 ;
}
F_11 ( V_2 , V_100 ,
V_118 |
V_119 , V_120 ) ;
F_11 ( V_2 , 1 << V_121 ,
V_122 , V_113 ) ;
F_9 ( V_2 , V_95 , V_123 ) ;
if ( V_97 == V_98 ) {
V_100 = V_124 |
V_125 |
V_126 ;
} else if ( V_97 == V_104 ) {
V_100 = V_124 |
V_127 |
V_128 ;
} else if ( V_97 == V_101 ) {
V_100 = V_129 |
V_127 |
V_126 ;
} else {
return;
}
F_11 ( V_2 , V_100 ,
V_130 | V_131 |
V_132 , V_120 ) ;
F_11 ( V_2 , V_133 |
V_134 ,
V_135 |
V_136 , V_113 ) ;
F_11 ( V_2 , V_97 , V_137 ,
V_120 ) ;
}
static inline void F_38 ( struct V_1 * V_2 ,
unsigned char V_138 )
{
F_11 ( V_2 , V_138 << V_139 ,
V_140 , V_141 ) ;
}
static inline void F_39 ( struct V_1 * V_2 ,
unsigned char V_138 )
{
F_11 ( V_2 , V_138 << V_142 ,
V_143 , V_141 ) ;
}
static inline void F_40 ( struct V_1 * V_2 ,
unsigned char V_138 )
{
F_11 ( V_2 , V_138 << V_144 ,
V_145 , V_141 ) ;
}
static inline void F_41 ( struct V_1 * V_2 ,
unsigned char V_138 )
{
F_9 ( V_2 , V_138 , V_146 ) ;
}
static inline void F_42 ( struct V_1 * V_2 ,
unsigned char V_138 )
{
F_9 ( V_2 , V_138 , V_147 ) ;
}
static bool F_43 ( struct V_1 * V_2 , int V_148 )
{
T_3 V_3 ;
while ( ( V_3 = F_10 ( V_2 , V_149 ) & 0x3 ) == 0 ) {
if ( V_148 -- == 0 )
return false ;
F_44 ( 1000 ) ;
}
F_9 ( V_2 , V_3 , V_149 ) ;
return true ;
}
static void F_45 ( struct V_1 * V_2 , unsigned short V_8 ,
unsigned char V_150 )
{
F_9 ( V_2 , 0xFF , V_149 ) ;
F_9 ( V_2 , V_150 , V_151 ) ;
F_9 ( V_2 , ( unsigned char ) ( V_8 >> 8 ) ,
V_152 ) ;
F_9 ( V_2 , ( unsigned char ) ( V_8 >> 0 ) ,
V_153 ) ;
F_9 ( V_2 , V_154 ,
V_155 ) ;
F_43 ( V_2 , 1000 ) ;
}
static int F_46 ( struct V_1 * V_2 , unsigned short V_8 ,
unsigned char V_150 )
{
F_45 ( V_2 , V_8 , V_150 ) ;
return 0 ;
}
static void F_47 ( struct V_1 * V_2 , bool V_156 )
{
F_12 ( V_2 , ! V_156 , V_157 ,
V_158 ,
V_159 ) ;
}
static void F_48 ( struct V_1 * V_2 , T_1 V_156 )
{
F_12 ( V_2 , V_156 , V_157 ,
V_160 ,
V_161 ) ;
}
static void F_49 ( struct V_1 * V_2 , T_1 V_156 )
{
F_12 ( V_2 , V_156 , V_157 ,
V_162 ,
V_163 ) ;
}
static void F_50 ( struct V_1 * V_2 , T_1 V_156 )
{
F_12 ( V_2 , V_156 , V_157 ,
V_164 ,
V_165 ) ;
}
static void F_51 ( struct V_1 * V_2 , T_1 V_156 )
{
F_12 ( V_2 , V_156 , V_157 ,
V_166 ,
V_167 ) ;
}
static void F_52 ( struct V_1 * V_2 , T_1 V_156 )
{
F_12 ( V_2 , V_156 , V_157 ,
V_168 ,
V_169 ) ;
}
static void F_53 ( struct V_1 * V_2 , T_1 V_156 )
{
F_12 ( V_2 , V_156 , V_157 ,
V_170 ,
V_171 ) ;
}
static int F_54 ( struct V_1 * V_2 , unsigned char V_172 ,
unsigned char V_173 , int V_174 )
{
unsigned V_175 ;
T_1 V_3 , V_148 ;
const struct V_176 * V_177 = V_2 -> V_178 ;
const struct V_179 * V_180 = V_177 -> V_181 ;
const struct V_182 * V_183 = V_177 -> V_184 ;
const struct V_185 * V_186 = V_177 -> V_186 ;
if ( V_172 )
return - V_187 ;
switch ( V_173 ) {
case 0 :
case 8 :
V_175 = V_188 ;
break;
case 10 :
V_175 = V_189 ;
break;
case 12 :
V_175 = V_190 ;
break;
default:
return - V_187 ;
}
for (; V_180 -> V_38 != ~ 0UL ; V_180 ++ )
if ( V_2 -> V_36 . V_37 . V_38 <=
V_180 -> V_38 )
break;
for (; V_183 -> V_38 != ~ 0UL ; V_183 ++ )
if ( V_2 -> V_36 . V_37 . V_38 <=
V_183 -> V_38 )
break;
for (; V_186 -> V_38 != ~ 0UL ; V_186 ++ )
if ( V_2 -> V_36 . V_37 . V_38 <=
V_186 -> V_38 )
break;
if ( V_180 -> V_38 == ~ 0UL ||
V_183 -> V_38 == ~ 0UL ||
V_186 -> V_38 == ~ 0UL ) {
F_55 ( V_2 -> V_29 , L_2 ,
V_2 -> V_36 . V_37 . V_38 ) ;
return - V_187 ;
}
if ( V_174 )
V_3 = V_191 ;
else
V_3 = V_192 ;
F_9 ( V_2 , V_3 , V_193 ) ;
F_51 ( V_2 , 0 ) ;
F_50 ( V_2 , 1 ) ;
F_9 ( V_2 , V_194 , V_195 ) ;
F_9 ( V_2 , V_196 , V_195 ) ;
F_9 ( V_2 , V_197 , V_198 ) ;
F_38 ( V_2 , 1 ) ;
F_9 ( V_2 , V_199 ,
V_200 ) ;
F_38 ( V_2 , 0 ) ;
F_46 ( V_2 , V_180 -> V_173 [ V_175 ] . V_201 , 0x06 ) ;
F_46 ( V_2 , V_180 -> V_173 [ V_175 ] . V_202 , 0x15 ) ;
F_46 ( V_2 , V_183 -> V_203 [ V_175 ] , 0x10 ) ;
F_46 ( V_2 , 0x0000 , 0x13 ) ;
F_46 ( V_2 , 0x0006 , 0x17 ) ;
F_46 ( V_2 , V_186 -> V_204 , 0x19 ) ;
F_46 ( V_2 , V_186 -> V_205 , 0x09 ) ;
F_46 ( V_2 , V_186 -> V_206 , 0x0E ) ;
F_46 ( V_2 , 0x8000 , 0x05 ) ;
F_47 ( V_2 , false ) ;
F_48 ( V_2 , 0 ) ;
F_48 ( V_2 , 1 ) ;
F_51 ( V_2 , 1 ) ;
F_50 ( V_2 , 0 ) ;
if ( V_2 -> V_207 == V_208 )
F_49 ( V_2 , 1 ) ;
V_148 = 5 ;
do {
V_3 = F_10 ( V_2 , V_209 ) & V_210 ;
if ( ! V_3 )
break;
if ( V_148 == 0 ) {
F_55 ( V_2 -> V_29 , L_3 ) ;
return - V_211 ;
}
F_44 ( 1000 ) ;
V_148 -- ;
} while ( 1 );
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
int V_64 , V_212 ;
bool V_174 ;
V_174 = V_2 -> V_213 && F_30 ( V_2 ) ;
for ( V_64 = 0 ; V_64 < 2 ; V_64 ++ ) {
F_52 ( V_2 , 1 ) ;
F_53 ( V_2 , 0 ) ;
F_48 ( V_2 , 0 ) ;
F_47 ( V_2 , true ) ;
V_212 = F_54 ( V_2 , 0 , 8 , V_174 ) ;
if ( V_212 )
return V_212 ;
}
V_2 -> V_214 = true ;
return 0 ;
}
static void F_57 ( struct V_1 * V_2 )
{
T_1 V_215 ;
if ( V_2 -> V_36 . V_37 . V_216 )
V_215 = V_217 ;
else
V_215 = V_218 ;
F_11 ( V_2 , V_219 ,
V_220 , V_221 ) ;
F_11 ( V_2 , V_215 , V_222 , V_223 ) ;
F_11 ( V_2 , V_224 ,
V_225 , V_226 ) ;
}
static void F_58 ( struct V_1 * V_2 , struct V_227 * V_228 )
{
struct V_229 V_230 ;
T_1 V_3 ;
F_59 ( & V_230 , V_228 ) ;
if ( V_2 -> V_36 . V_61 == V_45 )
V_230 . V_231 = V_232 ;
else if ( V_2 -> V_36 . V_61 == V_46 )
V_230 . V_231 = V_233 ;
else
V_230 . V_231 = V_234 ;
if ( V_2 -> V_36 . V_61 == V_235 ) {
V_230 . V_66 = V_236 ;
if ( V_2 -> V_36 . V_66 == V_67 )
V_230 . V_237 =
V_238 ;
else
V_230 . V_237 =
V_239 ;
} else if ( V_2 -> V_36 . V_61 != V_43 ) {
V_230 . V_66 = V_2 -> V_36 . V_66 ;
V_230 . V_237 = V_238 ;
} else {
V_230 . V_66 = V_240 ;
V_230 . V_237 = V_238 ;
}
V_230 . V_241 = V_242 ;
V_3 = ( V_230 . V_231 & 3 ) << 4 | ( V_230 . V_241 & 0x3 ) ;
if ( V_230 . V_243 & 15 )
V_3 |= V_244 ;
if ( V_230 . V_245 || V_230 . V_246 )
V_3 |= V_247 ;
if ( V_230 . V_248 || V_230 . V_249 )
V_3 |= V_250 ;
F_9 ( V_2 , V_3 , V_251 ) ;
V_3 = ( ( V_230 . V_66 & 0x3 ) << 6 ) |
( ( V_230 . V_252 & 0x3 ) << 4 ) |
( V_230 . V_243 & 0xf ) ;
F_9 ( V_2 , V_3 , V_253 ) ;
V_3 = ( ( V_230 . V_237 & 0x7 ) << 4 ) |
( ( V_230 . V_254 & 0x3 ) << 2 ) |
( V_230 . V_255 & 0x3 ) ;
if ( V_230 . V_256 )
V_3 |= V_257 ;
F_9 ( V_2 , V_3 , V_258 ) ;
V_3 = V_230 . V_259 & 0x7f ;
F_9 ( V_2 , V_3 , V_260 ) ;
V_3 = ( ( ( V_2 -> V_36 . V_37 . V_261 + 1 ) <<
V_262 ) &
V_263 ) |
( ( V_2 -> V_36 . V_37 . V_264 <<
V_265 ) &
V_266 ) ;
F_9 ( V_2 , V_3 , V_267 ) ;
V_3 = ( ( V_230 . V_268 & 0x3 ) << 2 ) |
( V_230 . V_269 & 0x3 ) ;
F_9 ( V_2 , V_3 , V_270 ) ;
F_9 ( V_2 , V_230 . V_245 & 0xff , V_271 ) ;
F_9 ( V_2 , ( V_230 . V_245 >> 8 ) & 0xff , V_272 ) ;
F_9 ( V_2 , V_230 . V_246 & 0xff , V_273 ) ;
F_9 ( V_2 , ( V_230 . V_246 >> 8 ) & 0xff , V_274 ) ;
F_9 ( V_2 , V_230 . V_248 & 0xff , V_275 ) ;
F_9 ( V_2 , ( V_230 . V_248 >> 8 ) & 0xff , V_276 ) ;
F_9 ( V_2 , V_230 . V_249 & 0xff , V_277 ) ;
F_9 ( V_2 , ( V_230 . V_249 >> 8 ) & 0xff , V_278 ) ;
}
static void F_60 ( struct V_1 * V_2 ,
const struct V_227 * V_228 )
{
T_1 V_279 ;
struct V_280 * V_281 = & V_2 -> V_36 . V_37 ;
int V_282 , V_283 , V_284 , V_285 , V_286 , V_287 ;
unsigned int V_288 ;
V_281 -> V_38 = V_228 -> clock * 1000 ;
F_17 ( V_2 -> V_29 , L_4 , V_281 -> V_38 ) ;
V_279 = ( V_2 -> V_36 . V_289 ?
V_290 :
V_291 ) ;
V_279 |= V_228 -> V_40 & V_292 ?
V_293 :
V_294 ;
V_279 |= V_228 -> V_40 & V_295 ?
V_296 :
V_297 ;
V_279 |= ( V_281 -> V_216 ?
V_298 :
V_299 ) ;
if ( V_2 -> V_300 == 39 )
V_279 |= V_301 ;
else
V_279 |= V_228 -> V_40 & V_302 ?
V_301 :
V_303 ;
V_279 |= V_228 -> V_40 & V_302 ?
V_304 :
V_305 ;
V_279 |= V_2 -> V_213 ?
V_306 :
V_307 ;
F_9 ( V_2 , V_279 , V_308 ) ;
V_288 = V_228 -> V_288 ;
V_283 = V_228 -> V_309 - V_228 -> V_288 ;
V_285 = V_228 -> V_310 - V_228 -> V_288 ;
V_287 = V_228 -> V_311 - V_228 -> V_310 ;
if ( V_228 -> V_40 & V_302 ) {
V_288 /= 2 ;
V_283 /= 2 ;
V_285 /= 2 ;
V_287 /= 2 ;
}
F_9 ( V_2 , V_228 -> V_312 >> 8 , V_313 ) ;
F_9 ( V_2 , V_228 -> V_312 , V_314 ) ;
F_9 ( V_2 , V_288 >> 8 , V_315 ) ;
F_9 ( V_2 , V_288 , V_316 ) ;
V_282 = V_228 -> V_317 - V_228 -> V_312 ;
F_9 ( V_2 , V_282 >> 8 , V_318 ) ;
F_9 ( V_2 , V_282 , V_319 ) ;
F_9 ( V_2 , V_283 , V_320 ) ;
V_284 = V_228 -> V_321 - V_228 -> V_312 ;
F_9 ( V_2 , V_284 >> 8 , V_322 ) ;
F_9 ( V_2 , V_284 , V_323 ) ;
F_9 ( V_2 , V_285 , V_324 ) ;
V_286 = V_228 -> V_325 - V_228 -> V_321 ;
F_9 ( V_2 , V_286 >> 8 , V_326 ) ;
F_9 ( V_2 , V_286 , V_327 ) ;
F_9 ( V_2 , V_287 , V_328 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_214 )
return;
F_48 ( V_2 , 0 ) ;
F_47 ( V_2 , true ) ;
V_2 -> V_214 = false ;
}
static void F_62 ( struct V_1 * V_2 )
{
T_1 V_329 ;
F_9 ( V_2 , 12 , V_330 ) ;
F_9 ( V_2 , 32 , V_331 ) ;
F_9 ( V_2 , 1 , V_332 ) ;
F_9 ( V_2 , 0x0B , V_333 ) ;
F_9 ( V_2 , 0x16 , V_334 ) ;
F_9 ( V_2 , 0x21 , V_335 ) ;
V_329 = 0x7F ;
V_329 &= ~ V_336 ;
F_9 ( V_2 , V_329 , V_337 ) ;
V_329 &= ~ V_338 ;
F_9 ( V_2 , V_329 , V_337 ) ;
if ( F_30 ( V_2 ) ) {
V_329 &= ~ V_339 ;
F_9 ( V_2 , V_329 , V_337 ) ;
}
}
static void F_63 ( struct V_1 * V_2 )
{
F_11 ( V_2 , 0 , V_340 , V_337 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
int V_341 ;
T_1 V_3 ;
F_9 ( V_2 , ( T_1 ) ~ V_342 , V_343 ) ;
V_3 = F_10 ( V_2 , V_308 ) ;
if ( V_2 -> V_207 == V_344 ) {
F_9 ( V_2 , V_3 , V_308 ) ;
return;
}
for ( V_341 = 0 ; V_341 < 4 ; V_341 ++ )
F_9 ( V_2 , V_3 , V_308 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
F_9 ( V_2 , 0 , V_345 ) ;
F_9 ( V_2 , 0 , V_346 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_347 ,
V_346 ) ;
}
static int F_67 ( struct V_1 * V_2 , struct V_227 * V_228 )
{
int V_212 ;
F_66 ( V_2 ) ;
V_2 -> V_300 = F_68 ( V_228 ) ;
if ( ! V_2 -> V_300 ) {
F_17 ( V_2 -> V_29 , L_5 ) ;
} else {
F_17 ( V_2 -> V_29 , L_6 , V_2 -> V_300 ) ;
}
if ( ( V_2 -> V_300 == 6 ) || ( V_2 -> V_300 == 7 ) ||
( V_2 -> V_300 == 21 ) || ( V_2 -> V_300 == 22 ) ||
( V_2 -> V_300 == 2 ) || ( V_2 -> V_300 == 3 ) ||
( V_2 -> V_300 == 17 ) || ( V_2 -> V_300 == 18 ) )
V_2 -> V_36 . V_66 = V_67 ;
else
V_2 -> V_36 . V_66 = V_348 ;
V_2 -> V_36 . V_37 . V_264 = 0 ;
V_2 -> V_36 . V_37 . V_261 = 0 ;
V_2 -> V_36 . V_42 = V_43 ;
V_2 -> V_36 . V_61 = V_43 ;
V_2 -> V_36 . V_44 = 8 ;
V_2 -> V_36 . V_107 = 0 ;
V_2 -> V_36 . V_289 = 0 ;
V_2 -> V_36 . V_37 . V_216 = true ;
F_60 ( V_2 , V_228 ) ;
V_212 = F_56 ( V_2 ) ;
if ( V_212 )
return V_212 ;
F_62 ( V_2 ) ;
if ( V_2 -> V_349 ) {
F_17 ( V_2 -> V_29 , L_7 ) ;
F_23 ( V_2 ) ;
F_63 ( V_2 ) ;
}
if ( V_2 -> V_213 ) {
F_17 ( V_2 -> V_29 , L_8 , V_30 ) ;
F_58 ( V_2 , V_228 ) ;
} else {
F_17 ( V_2 -> V_29 , L_9 , V_30 ) ;
}
F_37 ( V_2 ) ;
F_36 ( V_2 ) ;
F_29 ( V_2 ) ;
F_57 ( V_2 ) ;
F_64 ( V_2 ) ;
if ( V_2 -> V_350 && V_2 -> V_213 )
F_65 ( V_2 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_351 ,
V_352 ) ;
F_9 ( V_2 , V_353 |
V_354 ,
V_355 ) ;
F_9 ( V_2 , V_2 -> V_356 , V_357 ) ;
F_9 ( V_2 , V_358 | V_359 ,
V_360 ) ;
return 0 ;
}
static void F_70 ( struct V_1 * V_2 )
{
T_1 V_361 ;
V_361 = F_10 ( V_2 , V_362 ) |
V_363 |
V_364 ;
F_9 ( V_2 , V_361 , V_362 ) ;
F_9 ( V_2 , 0xff , V_365 ) ;
F_9 ( V_2 , 0xff , V_366 ) ;
F_9 ( V_2 , 0xff , V_367 ) ;
F_9 ( V_2 , 0xff , V_345 ) ;
F_9 ( V_2 , 0xff , V_357 ) ;
F_9 ( V_2 , 0xff , V_352 ) ;
F_9 ( V_2 , 0xff , V_355 ) ;
F_9 ( V_2 , 0xff , V_368 ) ;
F_9 ( V_2 , 0xff , V_369 ) ;
F_9 ( V_2 , 0xff , V_370 ) ;
F_9 ( V_2 , 0xff , V_371 ) ;
F_9 ( V_2 , 0xff , V_372 ) ;
F_9 ( V_2 , 0xff , V_373 ) ;
F_9 ( V_2 , 0xff , V_374 ) ;
F_9 ( V_2 , 0xff , V_375 ) ;
F_9 ( V_2 , 0xff , V_376 ) ;
F_9 ( V_2 , 0xff , V_377 ) ;
F_9 ( V_2 , 0xff , V_346 ) ;
F_9 ( V_2 , 0xff , V_378 ) ;
F_9 ( V_2 , 0xff , V_379 ) ;
F_9 ( V_2 , 0xff , V_380 ) ;
F_9 ( V_2 , 0xff , V_381 ) ;
F_9 ( V_2 , 0xff , V_382 ) ;
F_9 ( V_2 , 0xff , V_383 ) ;
F_9 ( V_2 , 0xff , V_384 ) ;
V_361 &= ~ ( V_363 |
V_364 ) ;
F_9 ( V_2 , V_361 , V_362 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
V_2 -> V_385 = true ;
F_67 ( V_2 , & V_2 -> V_386 ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
F_61 ( V_2 ) ;
V_2 -> V_385 = false ;
}
static void F_73 ( struct V_1 * V_2 )
{
int V_387 = V_2 -> V_387 ;
if ( V_2 -> V_388 ) {
V_387 = V_389 ;
} else if ( V_387 == V_390 ) {
if ( V_2 -> V_391 )
V_387 = V_392 ;
else
V_387 = V_389 ;
}
if ( V_387 == V_389 ) {
if ( V_2 -> V_385 )
F_72 ( V_2 ) ;
} else {
if ( ! V_2 -> V_385 )
F_71 ( V_2 ) ;
}
}
static void F_74 ( struct V_1 * V_2 )
{
T_1 V_393 = V_2 -> V_356 ;
if ( V_2 -> V_387 || V_2 -> V_388 || ! V_2 -> V_391 )
V_2 -> V_356 |= V_394 ;
else
V_2 -> V_356 &= ~ V_394 ;
if ( V_393 != V_2 -> V_356 )
F_9 ( V_2 , V_2 -> V_356 , V_357 ) ;
}
static void F_75 ( struct V_395 * V_396 ,
struct V_227 * V_397 ,
struct V_227 * V_228 )
{
struct V_1 * V_2 = V_396 -> V_398 ;
F_21 ( & V_2 -> V_399 ) ;
memcpy ( & V_2 -> V_386 , V_228 , sizeof( V_2 -> V_386 ) ) ;
F_22 ( & V_2 -> V_399 ) ;
}
static void F_76 ( struct V_395 * V_396 )
{
struct V_1 * V_2 = V_396 -> V_398 ;
F_21 ( & V_2 -> V_399 ) ;
V_2 -> V_388 = true ;
F_73 ( V_2 ) ;
F_74 ( V_2 ) ;
F_22 ( & V_2 -> V_399 ) ;
}
static void F_77 ( struct V_395 * V_396 )
{
struct V_1 * V_2 = V_396 -> V_398 ;
F_21 ( & V_2 -> V_399 ) ;
V_2 -> V_388 = false ;
F_73 ( V_2 ) ;
F_74 ( V_2 ) ;
F_22 ( & V_2 -> V_399 ) ;
}
static enum V_400
F_78 ( struct V_401 * V_402 , bool V_387 )
{
struct V_1 * V_2 = F_79 ( V_402 , struct V_1 ,
V_402 ) ;
F_21 ( & V_2 -> V_399 ) ;
V_2 -> V_387 = V_390 ;
F_73 ( V_2 ) ;
F_74 ( V_2 ) ;
F_22 ( & V_2 -> V_399 ) ;
return F_10 ( V_2 , V_209 ) & V_403 ?
V_404 : V_405 ;
}
static int F_80 ( struct V_401 * V_402 )
{
struct V_1 * V_2 = F_79 ( V_402 , struct V_1 ,
V_402 ) ;
struct V_406 * V_406 ;
int V_212 = 0 ;
if ( ! V_2 -> V_407 )
return 0 ;
V_406 = F_81 ( V_402 , V_2 -> V_407 ) ;
if ( V_406 ) {
F_17 ( V_2 -> V_29 , L_10 ,
V_406 -> V_408 , V_406 -> V_409 ) ;
V_2 -> V_213 = F_82 ( V_406 ) ;
V_2 -> V_349 = F_83 ( V_406 ) ;
F_84 ( V_402 , V_406 ) ;
V_212 = F_85 ( V_402 , V_406 ) ;
F_86 ( V_402 , V_406 ) ;
F_87 ( V_406 ) ;
} else {
F_17 ( V_2 -> V_29 , L_11 ) ;
}
return V_212 ;
}
static enum V_410
F_88 ( struct V_401 * V_402 ,
struct V_227 * V_228 )
{
struct V_1 * V_2 = F_79 ( V_402 ,
struct V_1 , V_402 ) ;
enum V_410 V_411 = V_412 ;
if ( V_228 -> V_40 & V_413 )
return V_414 ;
if ( V_2 -> V_178 -> V_415 )
V_411 = V_2 -> V_178 -> V_415 ( V_402 , V_228 ) ;
return V_411 ;
}
static void F_89 ( struct V_401 * V_402 )
{
F_90 ( V_402 ) ;
F_91 ( V_402 ) ;
}
static void F_92 ( struct V_401 * V_402 )
{
struct V_1 * V_2 = F_79 ( V_402 , struct V_1 ,
V_402 ) ;
F_21 ( & V_2 -> V_399 ) ;
V_2 -> V_387 = V_402 -> V_387 ;
F_73 ( V_2 ) ;
F_74 ( V_2 ) ;
F_22 ( & V_2 -> V_399 ) ;
}
static T_4 F_93 ( int V_416 , void * V_417 )
{
struct V_1 * V_2 = V_417 ;
T_1 V_418 ;
V_418 = F_10 ( V_2 , V_360 ) ;
if ( V_418 )
F_9 ( V_2 , ~ 0 , V_379 ) ;
return V_418 ? V_419 : V_420 ;
}
static T_4 F_94 ( int V_416 , void * V_417 )
{
struct V_1 * V_2 = V_417 ;
T_1 V_418 , V_421 , V_422 , V_423 ;
V_418 = F_10 ( V_2 , V_360 ) ;
V_421 = F_10 ( V_2 , V_424 ) ;
V_423 = F_10 ( V_2 , V_209 ) ;
V_422 = 0 ;
if ( V_418 & V_358 )
V_422 |= V_403 ;
if ( V_418 & V_425 )
V_422 |= V_426 ;
if ( V_418 & V_427 )
V_422 |= V_428 ;
if ( V_418 & V_429 )
V_422 |= V_430 ;
if ( V_418 & V_431 )
V_422 |= V_432 ;
if ( V_422 )
F_11 ( V_2 , ~ V_421 , V_422 , V_424 ) ;
if ( V_418 &
( V_359 | V_358 ) ) {
F_21 ( & V_2 -> V_399 ) ;
if ( ! V_2 -> V_388 && ! V_2 -> V_387 ) {
if ( ! ( V_423 & V_394 ) )
V_2 -> V_391 = false ;
if ( V_423 & V_403 )
V_2 -> V_391 = true ;
F_73 ( V_2 ) ;
F_74 ( V_2 ) ;
}
F_22 ( & V_2 -> V_399 ) ;
}
if ( V_418 & V_358 ) {
F_17 ( V_2 -> V_29 , L_12 ,
V_421 & V_403 ? L_13 : L_14 ) ;
F_95 ( V_2 -> V_396 -> V_29 ) ;
}
F_9 ( V_2 , V_418 , V_360 ) ;
F_9 ( V_2 , ~ ( V_358 | V_359 ) ,
V_379 ) ;
return V_433 ;
}
static int F_96 ( struct V_434 * V_435 , struct V_1 * V_2 )
{
struct V_436 * V_437 = V_2 -> V_437 ;
struct V_395 * V_396 ;
int V_212 ;
V_396 = F_97 ( V_435 -> V_29 , sizeof( * V_396 ) , V_438 ) ;
if ( ! V_396 ) {
F_98 ( L_15 ) ;
return - V_439 ;
}
V_2 -> V_396 = V_396 ;
V_396 -> V_398 = V_2 ;
V_396 -> V_440 = & V_441 ;
V_212 = F_99 ( V_435 , V_396 ) ;
if ( V_212 ) {
F_98 ( L_16 ) ;
return - V_187 ;
}
V_437 -> V_396 = V_396 ;
V_2 -> V_402 . V_442 = V_443 ;
F_100 ( & V_2 -> V_402 ,
& V_444 ) ;
F_101 ( V_435 , & V_2 -> V_402 ,
& V_445 ,
V_446 ) ;
F_102 ( & V_2 -> V_402 , V_437 ) ;
return 0 ;
}
int F_103 ( struct V_447 * V_29 , struct V_447 * V_448 ,
void * V_8 , struct V_436 * V_437 ,
struct V_449 * V_450 , int V_416 ,
const struct V_176 * V_178 )
{
struct V_434 * V_435 = V_8 ;
struct V_451 * V_452 = V_29 -> V_453 ;
struct V_454 V_455 ;
struct V_451 * V_456 ;
struct V_457 V_458 ;
struct V_1 * V_2 ;
int V_212 ;
T_3 V_3 = 1 ;
V_2 = F_97 ( V_29 , sizeof( * V_2 ) , V_438 ) ;
if ( ! V_2 )
return - V_439 ;
V_2 -> V_402 . V_459 = 1 ;
V_2 -> V_178 = V_178 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_207 = V_178 -> V_207 ;
V_2 -> V_26 = 48000 ;
V_2 -> V_437 = V_437 ;
V_2 -> V_388 = true ;
V_2 -> V_391 = true ;
V_2 -> V_356 = ( T_1 ) ~ ( V_403 | V_394 ) ;
F_104 ( & V_2 -> V_399 ) ;
F_104 ( & V_2 -> V_35 ) ;
F_105 ( & V_2 -> V_31 ) ;
F_106 ( V_452 , L_17 , & V_3 ) ;
switch ( V_3 ) {
case 4 :
V_2 -> V_6 = F_1 ;
V_2 -> V_7 = F_3 ;
break;
case 1 :
V_2 -> V_6 = F_5 ;
V_2 -> V_7 = F_7 ;
break;
default:
F_55 ( V_29 , L_18 ) ;
return - V_187 ;
}
V_456 = F_107 ( V_452 , L_19 , 0 ) ;
if ( V_456 ) {
V_2 -> V_407 = F_108 ( V_456 ) ;
F_109 ( V_456 ) ;
if ( ! V_2 -> V_407 ) {
F_17 ( V_2 -> V_29 , L_20 ) ;
return - V_460 ;
}
} else {
F_17 ( V_2 -> V_29 , L_21 ) ;
}
V_2 -> V_5 = F_110 ( V_29 , V_450 ) ;
if ( F_111 ( V_2 -> V_5 ) )
return F_112 ( V_2 -> V_5 ) ;
V_2 -> V_461 = F_113 ( V_2 -> V_29 , L_22 ) ;
if ( F_111 ( V_2 -> V_461 ) ) {
V_212 = F_112 ( V_2 -> V_461 ) ;
F_55 ( V_2 -> V_29 , L_23 , V_212 ) ;
return V_212 ;
}
V_212 = F_114 ( V_2 -> V_461 ) ;
if ( V_212 ) {
F_55 ( V_2 -> V_29 , L_24 , V_212 ) ;
return V_212 ;
}
V_2 -> V_462 = F_113 ( V_2 -> V_29 , L_25 ) ;
if ( F_111 ( V_2 -> V_462 ) ) {
V_212 = F_112 ( V_2 -> V_462 ) ;
F_55 ( V_2 -> V_29 , L_26 , V_212 ) ;
goto V_463;
}
V_212 = F_114 ( V_2 -> V_462 ) ;
if ( V_212 ) {
F_55 ( V_2 -> V_29 , L_27 , V_212 ) ;
goto V_463;
}
F_115 ( V_29 ,
L_28 ,
F_10 ( V_2 , V_464 ) ,
F_10 ( V_2 , V_465 ) ,
F_10 ( V_2 , V_466 ) ,
F_10 ( V_2 , V_467 ) ) ;
F_70 ( V_2 ) ;
V_212 = F_116 ( V_29 , V_416 , F_93 ,
F_94 , V_468 ,
F_117 ( V_29 ) , V_2 ) ;
if ( V_212 )
goto V_469;
F_20 ( V_2 ) ;
F_9 ( V_2 , V_403 | V_394 , V_424 ) ;
F_9 ( V_2 , V_358 | V_359 ,
V_360 ) ;
V_212 = F_69 ( V_2 ) ;
if ( V_212 )
goto V_469;
V_212 = F_96 ( V_435 , V_2 ) ;
if ( V_212 )
goto V_469;
F_9 ( V_2 , ~ ( V_358 | V_359 ) ,
V_379 ) ;
memset ( & V_455 , 0 , sizeof( V_455 ) ) ;
V_455 . V_470 = V_29 ;
V_455 . V_471 = V_472 ;
if ( F_10 ( V_2 , V_473 ) & V_474 ) {
V_458 . V_475 = V_450 -> V_476 ;
V_458 . V_477 = V_2 -> V_5 ;
V_458 . V_416 = V_416 ;
V_458 . V_2 = V_2 ;
V_458 . V_478 = V_2 -> V_402 . V_478 ;
V_455 . V_479 = L_29 ;
V_455 . V_8 = & V_458 ;
V_455 . V_480 = sizeof( V_458 ) ;
V_455 . V_481 = F_118 ( 32 ) ;
V_2 -> V_458 = F_119 ( & V_455 ) ;
}
F_120 ( V_29 , V_2 ) ;
return 0 ;
V_469:
F_121 ( V_2 -> V_462 ) ;
V_463:
F_121 ( V_2 -> V_461 ) ;
return V_212 ;
}
void F_122 ( struct V_447 * V_29 , struct V_447 * V_448 , void * V_8 )
{
struct V_1 * V_2 = F_123 ( V_29 ) ;
if ( V_2 -> V_458 && ! F_111 ( V_2 -> V_458 ) )
F_124 ( V_2 -> V_458 ) ;
F_9 ( V_2 , ~ 0 , V_379 ) ;
V_2 -> V_402 . V_440 -> V_482 ( & V_2 -> V_402 ) ;
V_2 -> V_437 -> V_440 -> V_482 ( V_2 -> V_437 ) ;
F_121 ( V_2 -> V_462 ) ;
F_121 ( V_2 -> V_461 ) ;
F_125 ( V_2 -> V_407 ) ;
}
