static void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_2 -> V_4 , V_5 ,
V_6 ,
V_3 << V_7 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_8 , int V_9 )
{
F_4 ( V_8 , V_2 -> V_10 + V_9 ) ;
}
static inline T_1 F_5 ( struct V_1 * V_2 , int V_9 )
{
return F_6 ( V_2 -> V_10 + V_9 ) ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_11 , T_1 V_12 , unsigned V_13 )
{
T_1 V_8 = F_5 ( V_2 , V_13 ) & ~ V_12 ;
V_8 |= V_11 & V_12 ;
F_3 ( V_2 , V_8 , V_13 ) ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_11 , unsigned int V_13 ,
T_1 V_14 , T_1 V_12 )
{
F_7 ( V_2 , V_11 << V_14 , V_12 , V_13 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
unsigned int V_15 )
{
F_3 ( V_2 , V_15 & 0xff , V_16 ) ;
F_3 ( V_2 , ( V_15 >> 8 ) & 0xff , V_17 ) ;
F_3 ( V_2 , ( V_15 >> 16 ) & 0x0f , V_18 ) ;
F_7 ( V_2 , 0 , V_19 , V_20 ) ;
}
static void F_10 ( struct V_1 * V_2 , unsigned int V_21 )
{
F_7 ( V_2 , 0 , V_22 , V_20 ) ;
F_3 ( V_2 , V_21 & 0xff , V_23 ) ;
F_3 ( V_2 , ( V_21 >> 8 ) & 0xff , V_24 ) ;
F_3 ( V_2 , ( ( V_21 >> 16 ) & V_25 ) |
V_22 , V_20 ) ;
}
static unsigned int F_11 ( unsigned int V_26 , unsigned long V_27 ,
unsigned int V_28 )
{
unsigned int V_29 = ( 128 * V_26 ) / 1000 ;
switch ( V_26 ) {
case 32000 :
if ( V_27 == 25170000 )
V_29 = ( V_28 == 150 ) ? 9152 : 4576 ;
else if ( V_27 == 27020000 )
V_29 = ( V_28 == 150 ) ? 8192 : 4096 ;
else if ( V_27 == 74170000 || V_27 == 148350000 )
V_29 = 11648 ;
else
V_29 = 4096 ;
break;
case 44100 :
if ( V_27 == 25170000 )
V_29 = 7007 ;
else if ( V_27 == 74170000 )
V_29 = 17836 ;
else if ( V_27 == 148350000 )
V_29 = ( V_28 == 150 ) ? 17836 : 8918 ;
else
V_29 = 6272 ;
break;
case 48000 :
if ( V_27 == 25170000 )
V_29 = ( V_28 == 150 ) ? 9152 : 6864 ;
else if ( V_27 == 27020000 )
V_29 = ( V_28 == 150 ) ? 8192 : 6144 ;
else if ( V_27 == 74170000 )
V_29 = 11648 ;
else if ( V_27 == 148350000 )
V_29 = ( V_28 == 150 ) ? 11648 : 5824 ;
else
V_29 = 6144 ;
break;
case 88200 :
V_29 = F_11 ( 44100 , V_27 , V_28 ) * 2 ;
break;
case 96000 :
V_29 = F_11 ( 48000 , V_27 , V_28 ) * 2 ;
break;
case 176400 :
V_29 = F_11 ( 44100 , V_27 , V_28 ) * 4 ;
break;
case 192000 :
V_29 = F_11 ( 48000 , V_27 , V_28 ) * 4 ;
break;
default:
break;
}
return V_29 ;
}
static unsigned int F_12 ( unsigned int V_26 , unsigned long V_27 ,
unsigned int V_28 )
{
unsigned int V_21 = 0 ;
F_13 ( L_1 , V_30 , V_26 ,
V_27 , V_28 ) ;
switch ( V_26 ) {
case 32000 :
if ( V_27 == 297000000 ) {
V_21 = 222750 ;
break;
}
case 48000 :
case 96000 :
case 192000 :
switch ( V_27 ) {
case 25200000 :
case 27000000 :
case 54000000 :
case 74250000 :
case 148500000 :
V_21 = V_27 / 1000 ;
break;
case 297000000 :
V_21 = 247500 ;
break;
default:
break;
}
break;
case 44100 :
case 88200 :
case 176400 :
switch ( V_27 ) {
case 25200000 :
V_21 = 28000 ;
break;
case 27000000 :
V_21 = 30000 ;
break;
case 54000000 :
V_21 = 60000 ;
break;
case 74250000 :
V_21 = 82500 ;
break;
case 148500000 :
V_21 = 165000 ;
break;
case 297000000 :
V_21 = 247500 ;
break;
default:
break;
}
break;
default:
break;
}
if ( V_28 == 100 )
return V_21 ;
else
return ( V_21 * V_28 ) / 100 ;
}
static void F_14 ( struct V_1 * V_2 ,
unsigned long V_27 )
{
unsigned int V_31 , V_32 ;
V_31 = F_11 ( V_2 -> V_33 , V_27 ,
V_2 -> V_28 ) ;
V_32 = F_12 ( V_2 -> V_33 , V_27 ,
V_2 -> V_28 ) ;
if ( ! V_32 ) {
F_15 ( V_2 -> V_34 , L_2 ,
V_30 , V_27 ) ;
return;
}
F_15 ( V_2 -> V_34 , L_3 ,
V_30 , V_2 -> V_33 , V_2 -> V_28 ,
V_27 , V_31 , V_32 ) ;
F_9 ( V_2 , V_31 ) ;
F_10 ( V_2 , V_32 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_14 ( V_2 , 74250000 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_14 ( V_2 , V_2 -> V_35 . V_36 . V_37 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
T_1 V_8 ;
if ( V_2 -> V_35 . V_39 == V_40 ) {
if ( V_2 -> V_35 . V_41 == 8 )
V_38 = 0x01 ;
else if ( V_2 -> V_35 . V_41 == 10 )
V_38 = 0x03 ;
else if ( V_2 -> V_35 . V_41 == 12 )
V_38 = 0x05 ;
else if ( V_2 -> V_35 . V_41 == 16 )
V_38 = 0x07 ;
else
return;
} else if ( V_2 -> V_35 . V_39 == V_42 ) {
if ( V_2 -> V_35 . V_41 == 8 )
V_38 = 0x09 ;
else if ( V_2 -> V_35 . V_41 == 10 )
V_38 = 0x0B ;
else if ( V_2 -> V_35 . V_41 == 12 )
V_38 = 0x0D ;
else if ( V_2 -> V_35 . V_41 == 16 )
V_38 = 0x0F ;
else
return;
} else if ( V_2 -> V_35 . V_39 == V_43 ) {
if ( V_2 -> V_35 . V_41 == 8 )
V_38 = 0x16 ;
else if ( V_2 -> V_35 . V_41 == 10 )
V_38 = 0x14 ;
else if ( V_2 -> V_35 . V_41 == 12 )
V_38 = 0x12 ;
else
return;
}
V_8 = V_44 |
( ( V_38 << V_45 ) &
V_46 ) ;
F_3 ( V_2 , V_8 , V_47 ) ;
V_8 = V_48 |
V_49 |
V_50 ;
F_3 ( V_2 , V_8 , V_51 ) ;
F_3 ( V_2 , 0x0 , V_52 ) ;
F_3 ( V_2 , 0x0 , V_53 ) ;
F_3 ( V_2 , 0x0 , V_54 ) ;
F_3 ( V_2 , 0x0 , V_55 ) ;
F_3 ( V_2 , 0x0 , V_56 ) ;
F_3 ( V_2 , 0x0 , V_57 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
return V_2 -> V_35 . V_39 != V_2 -> V_35 . V_58 ;
}
static int F_20 ( struct V_1 * V_2 )
{
if ( V_2 -> V_35 . V_58 != V_43 )
return 0 ;
if ( V_2 -> V_35 . V_39 == V_40 ||
V_2 -> V_35 . V_39 == V_42 )
return 1 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
if ( V_2 -> V_35 . V_39 != V_43 )
return 0 ;
if ( V_2 -> V_35 . V_58 == V_40 ||
V_2 -> V_35 . V_58 == V_42 )
return 1 ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
const F_23 ( * V_59 ) [ 3 ] [ 4 ] = & V_60 ;
unsigned V_61 ;
T_2 V_62 = 1 ;
if ( F_19 ( V_2 ) ) {
if ( V_2 -> V_35 . V_58 == V_40 ) {
if ( V_2 -> V_35 . V_63 ==
V_64 )
V_59 = & V_65 ;
else
V_59 = & V_66 ;
} else if ( V_2 -> V_35 . V_39 == V_40 ) {
if ( V_2 -> V_35 . V_63 ==
V_64 )
V_59 = & V_67 ;
else
V_59 = & V_68 ;
V_62 = 0 ;
}
}
for ( V_61 = 0 ; V_61 < F_24 ( V_60 [ 0 ] ) ; V_61 ++ ) {
F_23 V_69 = ( * V_59 ) [ 0 ] [ V_61 ] ;
F_23 V_70 = ( * V_59 ) [ 1 ] [ V_61 ] ;
F_23 V_71 = ( * V_59 ) [ 2 ] [ V_61 ] ;
F_3 ( V_2 , V_69 & 0xff ,
V_72 + V_61 * 2 ) ;
F_3 ( V_2 , V_69 >> 8 , V_73 + V_61 * 2 ) ;
F_3 ( V_2 , V_70 & 0xff , V_74 + V_61 * 2 ) ;
F_3 ( V_2 , V_70 >> 8 , V_75 + V_61 * 2 ) ;
F_3 ( V_2 , V_71 & 0xff ,
V_76 + V_61 * 2 ) ;
F_3 ( V_2 , V_71 >> 8 , V_77 + V_61 * 2 ) ;
}
F_7 ( V_2 , V_62 , V_78 ,
V_79 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
int V_80 = 0 ;
int V_81 = V_82 ;
int V_83 = 0 ;
if ( F_21 ( V_2 ) )
V_81 = V_84 ;
else if ( F_20 ( V_2 ) )
V_83 = V_85 ;
if ( V_2 -> V_35 . V_41 == 8 )
V_80 = V_86 ;
else if ( V_2 -> V_35 . V_41 == 10 )
V_80 = V_87 ;
else if ( V_2 -> V_35 . V_41 == 12 )
V_80 = V_88 ;
else if ( V_2 -> V_35 . V_41 == 16 )
V_80 = V_89 ;
else
return;
F_3 ( V_2 , V_81 | V_83 , V_90 ) ;
F_7 ( V_2 , V_80 , V_91 ,
V_79 ) ;
F_22 ( V_2 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
unsigned int V_80 = 0 ;
unsigned int V_92 = V_93 ;
unsigned int V_94 = V_95 ;
struct V_96 * V_35 = & V_2 -> V_35 ;
T_1 V_8 , V_97 ;
if ( V_35 -> V_58 == V_40
|| V_35 -> V_58 == V_42 ) {
if ( ! V_35 -> V_41 )
V_94 = V_98 ;
else if ( V_35 -> V_41 == 8 ) {
V_80 = 4 ;
V_94 = V_98 ;
} else if ( V_35 -> V_41 == 10 )
V_80 = 5 ;
else if ( V_35 -> V_41 == 12 )
V_80 = 6 ;
else if ( V_35 -> V_41 == 16 )
V_80 = 7 ;
else
return;
} else if ( V_35 -> V_58 == V_43 ) {
if ( ! V_35 -> V_41 ||
V_35 -> V_41 == 8 )
V_92 = V_93 ;
else if ( V_35 -> V_41 == 10 )
V_92 = V_99 ;
else if ( V_35 -> V_41 == 12 )
V_92 = V_100 ;
else
return;
V_94 = V_101 ;
} else
return;
V_8 = ( ( V_80 << V_102 ) &
V_103 ) |
( ( V_35 -> V_104 <<
V_105 ) &
V_106 ) ;
F_3 ( V_2 , V_8 , V_107 ) ;
F_7 ( V_2 , V_108 ,
V_109 , V_110 ) ;
if ( V_35 -> V_104 > 1 ) {
V_97 = V_111 |
V_112 ;
} else {
V_97 = V_113 |
V_114 ;
}
F_7 ( V_2 , V_97 ,
V_115 |
V_116 , V_117 ) ;
F_7 ( V_2 , 1 << V_118 ,
V_119 , V_110 ) ;
F_3 ( V_2 , V_92 , V_120 ) ;
if ( V_94 == V_95 ) {
V_97 = V_121 |
V_122 |
V_123 ;
} else if ( V_94 == V_101 ) {
V_97 = V_121 |
V_124 |
V_125 ;
} else if ( V_94 == V_98 ) {
V_97 = V_126 |
V_124 |
V_123 ;
} else {
return;
}
F_7 ( V_2 , V_97 ,
V_127 | V_128 |
V_129 , V_117 ) ;
F_7 ( V_2 , V_130 |
V_131 ,
V_132 |
V_133 , V_110 ) ;
F_7 ( V_2 , V_94 , V_134 ,
V_117 ) ;
}
static inline void F_27 ( struct V_1 * V_2 ,
unsigned char V_135 )
{
F_7 ( V_2 , V_135 << V_136 ,
V_137 , V_138 ) ;
}
static inline void F_28 ( struct V_1 * V_2 ,
unsigned char V_135 )
{
F_7 ( V_2 , V_135 << V_139 ,
V_140 , V_138 ) ;
}
static inline void F_29 ( struct V_1 * V_2 ,
unsigned char V_135 )
{
F_7 ( V_2 , V_135 << V_141 ,
V_142 , V_138 ) ;
}
static inline void F_30 ( struct V_1 * V_2 ,
unsigned char V_135 )
{
F_3 ( V_2 , V_135 , V_143 ) ;
}
static inline void F_31 ( struct V_1 * V_2 ,
unsigned char V_135 )
{
F_3 ( V_2 , V_135 , V_144 ) ;
}
static bool F_32 ( struct V_1 * V_2 , int V_145 )
{
while ( ( F_5 ( V_2 , V_146 ) & 0x3 ) == 0 ) {
if ( V_145 -- == 0 )
return false ;
F_33 ( 1000 ) ;
}
return true ;
}
static void F_34 ( struct V_1 * V_2 , unsigned short V_11 ,
unsigned char V_147 )
{
F_3 ( V_2 , 0xFF , V_146 ) ;
F_3 ( V_2 , V_147 , V_148 ) ;
F_3 ( V_2 , ( unsigned char ) ( V_11 >> 8 ) ,
V_149 ) ;
F_3 ( V_2 , ( unsigned char ) ( V_11 >> 0 ) ,
V_150 ) ;
F_3 ( V_2 , V_151 ,
V_152 ) ;
F_32 ( V_2 , 1000 ) ;
}
static int F_35 ( struct V_1 * V_2 , unsigned short V_11 ,
unsigned char V_147 )
{
F_34 ( V_2 , V_11 , V_147 ) ;
return 0 ;
}
static void F_36 ( struct V_1 * V_2 , T_1 V_153 )
{
F_8 ( V_2 , V_153 , V_154 ,
V_155 ,
V_156 ) ;
}
static void F_37 ( struct V_1 * V_2 , T_1 V_153 )
{
F_8 ( V_2 , V_153 , V_154 ,
V_157 ,
V_158 ) ;
}
static void F_38 ( struct V_1 * V_2 , T_1 V_153 )
{
F_8 ( V_2 , V_153 , V_154 ,
V_159 ,
V_160 ) ;
}
static void F_39 ( struct V_1 * V_2 , T_1 V_153 )
{
F_8 ( V_2 , V_153 , V_154 ,
V_161 ,
V_162 ) ;
}
static void F_40 ( struct V_1 * V_2 , T_1 V_153 )
{
F_8 ( V_2 , V_153 , V_154 ,
V_163 ,
V_164 ) ;
}
static void F_41 ( struct V_1 * V_2 , T_1 V_153 )
{
F_8 ( V_2 , V_153 , V_154 ,
V_165 ,
V_166 ) ;
}
static int F_42 ( struct V_1 * V_2 , unsigned char V_167 ,
unsigned char V_168 , int V_169 )
{
unsigned V_170 , V_61 ;
T_1 V_8 , V_145 ;
if ( V_167 )
return - V_171 ;
switch ( V_168 ) {
case 0 :
case 8 :
V_170 = V_172 ;
break;
case 10 :
V_170 = V_173 ;
break;
case 12 :
V_170 = V_174 ;
break;
default:
return - V_171 ;
}
if ( V_169 )
V_8 = V_175 ;
else
V_8 = V_176 ;
F_3 ( V_2 , V_8 , V_177 ) ;
F_39 ( V_2 , 0 ) ;
F_38 ( V_2 , 1 ) ;
F_3 ( V_2 , V_178 , V_179 ) ;
F_3 ( V_2 , V_180 , V_179 ) ;
F_3 ( V_2 , V_181 , V_182 ) ;
F_27 ( V_2 , 1 ) ;
F_3 ( V_2 , V_183 ,
V_184 ) ;
F_27 ( V_2 , 0 ) ;
for ( V_61 = 0 ; V_61 < F_24 ( V_185 ) - 1 ; V_61 ++ )
if ( V_2 -> V_35 . V_36 . V_37 <=
V_185 [ V_61 ] . V_37 )
break;
F_35 ( V_2 , V_185 [ V_61 ] . V_168 [ V_170 ] . V_186 , 0x06 ) ;
F_35 ( V_2 , V_185 [ V_61 ] . V_168 [ V_170 ] . V_187 , 0x15 ) ;
for ( V_61 = 0 ; V_61 < F_24 ( V_188 ) ; V_61 ++ )
if ( V_2 -> V_35 . V_36 . V_37 <=
V_188 [ V_61 ] . V_37 )
break;
if ( V_61 >= F_24 ( V_188 ) ) {
F_43 ( V_2 -> V_34 ,
L_4 ,
V_2 -> V_35 . V_36 . V_37 ) ;
return - V_171 ;
}
F_35 ( V_2 , V_188 [ V_61 ] . V_189 [ V_170 ] , 0x10 ) ;
F_35 ( V_2 , 0x0000 , 0x13 ) ;
F_35 ( V_2 , 0x0006 , 0x17 ) ;
F_35 ( V_2 , 0x0005 , 0x19 ) ;
F_35 ( V_2 , 0x800d , 0x09 ) ;
F_35 ( V_2 , 0x01ad , 0x0E ) ;
F_35 ( V_2 , 0x8000 , 0x05 ) ;
F_36 ( V_2 , 1 ) ;
F_37 ( V_2 , 0 ) ;
F_37 ( V_2 , 1 ) ;
F_39 ( V_2 , 1 ) ;
F_38 ( V_2 , 0 ) ;
V_145 = 5 ;
do {
V_8 = F_5 ( V_2 , V_190 ) & V_191 ;
if ( ! V_8 )
break;
if ( V_145 == 0 ) {
F_43 ( V_2 -> V_34 , L_5 ) ;
return - V_192 ;
}
F_33 ( 1000 ) ;
V_145 -- ;
} while ( 1 );
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_61 , V_193 ;
bool V_169 = false ;
V_169 = ( F_19 ( V_2 ) &&
! V_2 -> V_35 . V_36 . V_194 ) ;
for ( V_61 = 0 ; V_61 < 2 ; V_61 ++ ) {
F_40 ( V_2 , 1 ) ;
F_41 ( V_2 , 0 ) ;
F_37 ( V_2 , 0 ) ;
F_36 ( V_2 , 0 ) ;
V_193 = F_42 ( V_2 , 0 , 8 , V_169 ) ;
if ( V_193 )
return V_193 ;
}
V_2 -> V_195 = true ;
return 0 ;
}
static void F_45 ( struct V_1 * V_2 )
{
T_1 V_196 ;
if ( V_2 -> V_35 . V_36 . V_197 )
V_196 = V_198 ;
else
V_196 = V_199 ;
F_7 ( V_2 , V_200 ,
V_201 , V_202 ) ;
F_7 ( V_2 , V_196 , V_203 , V_204 ) ;
F_7 ( V_2 , V_205 ,
V_206 , V_207 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
T_1 V_8 , V_208 , V_209 ;
T_1 V_210 , V_211 , V_63 , V_212 ;
bool V_213 ;
V_213 = false ;
if ( V_2 -> V_35 . V_58 == V_42 )
V_208 = V_214 ;
else if ( V_2 -> V_35 . V_58 == V_43 )
V_208 = V_215 ;
else
V_208 = V_216 ;
V_209 = V_217 ;
V_8 = V_208 | V_209 |
V_218 |
V_219 ;
F_3 ( V_2 , V_8 , V_220 ) ;
if ( V_213 ) {
V_210 = V_221 ;
V_211 = V_222 ;
} else {
V_210 = V_223 ;
V_211 = V_224 ;
}
if ( V_2 -> V_35 . V_58 == V_225 ) {
V_63 = V_226 ;
if ( V_2 -> V_35 . V_63 == V_64 )
V_212 =
V_227 ;
else
V_212 =
V_228 ;
} else if ( V_2 -> V_35 . V_58 != V_40 ) {
if ( V_2 -> V_35 . V_63 == V_64 )
V_63 = V_229 ;
else
V_63 = V_230 ;
V_212 = V_227 ;
} else {
V_63 = V_231 ;
V_212 = V_227 ;
}
V_8 = V_63 | V_211 | V_210 ;
F_3 ( V_2 , V_8 , V_232 ) ;
V_8 = V_233 | V_212 |
V_234 |
V_235 ;
F_3 ( V_2 , V_8 , V_236 ) ;
F_3 ( V_2 , V_2 -> V_237 , V_238 ) ;
V_8 = ( ( ( V_2 -> V_35 . V_36 . V_239 + 1 ) <<
V_240 ) &
V_241 ) |
( ( V_2 -> V_35 . V_36 . V_242 <<
V_243 ) &
V_244 ) ;
F_3 ( V_2 , V_8 , V_245 ) ;
V_8 = V_246 |
V_247 ;
F_3 ( V_2 , V_8 , V_248 ) ;
F_3 ( V_2 , 0 , V_249 ) ;
F_3 ( V_2 , 0 , V_250 ) ;
F_3 ( V_2 , 0 , V_251 ) ;
F_3 ( V_2 , 0 , V_252 ) ;
F_3 ( V_2 , 0 , V_253 ) ;
F_3 ( V_2 , 0 , V_254 ) ;
F_3 ( V_2 , 0 , V_255 ) ;
F_3 ( V_2 , 0 , V_256 ) ;
}
static void F_47 ( struct V_1 * V_2 ,
const struct V_257 * V_258 )
{
T_1 V_259 ;
struct V_260 * V_261 = & V_2 -> V_35 . V_36 ;
int V_262 , V_263 , V_264 , V_265 , V_266 , V_267 ;
V_261 -> V_268 = ! ! ( V_258 -> V_269 & V_270 ) ;
V_261 -> V_271 = ! ! ( V_258 -> V_269 & V_272 ) ;
V_261 -> V_273 = ! ! ( V_258 -> V_269 & V_274 ) ;
V_261 -> V_37 = V_258 -> clock * 1000 ;
F_15 ( V_2 -> V_34 , L_6 , V_261 -> V_37 ) ;
V_259 = ( V_2 -> V_35 . V_275 ?
V_276 :
V_277 ) ;
V_259 |= ( V_261 -> V_271 ?
V_278 :
V_279 ) ;
V_259 |= ( V_261 -> V_268 ?
V_280 :
V_281 ) ;
V_259 |= ( V_261 -> V_197 ?
V_282 :
V_283 ) ;
if ( V_2 -> V_237 == 39 )
V_259 |= V_284 ;
else
V_259 |= ( V_261 -> V_273 ?
V_284 :
V_285 ) ;
V_259 |= ( V_261 -> V_273 ?
V_286 :
V_287 ) ;
V_259 |= ( V_261 -> V_194 ?
V_288 :
V_289 ) ;
F_3 ( V_2 , V_259 , V_290 ) ;
F_3 ( V_2 , V_258 -> V_291 >> 8 , V_292 ) ;
F_3 ( V_2 , V_258 -> V_291 , V_293 ) ;
F_3 ( V_2 , V_258 -> V_294 >> 8 , V_295 ) ;
F_3 ( V_2 , V_258 -> V_294 , V_296 ) ;
V_262 = V_258 -> V_297 - V_258 -> V_291 ;
F_3 ( V_2 , V_262 >> 8 , V_298 ) ;
F_3 ( V_2 , V_262 , V_299 ) ;
V_263 = V_258 -> V_300 - V_258 -> V_294 ;
F_3 ( V_2 , V_263 , V_301 ) ;
V_264 = V_258 -> V_302 - V_258 -> V_291 ;
F_3 ( V_2 , V_264 >> 8 , V_303 ) ;
F_3 ( V_2 , V_264 , V_304 ) ;
V_265 = V_258 -> V_305 - V_258 -> V_294 ;
F_3 ( V_2 , V_265 , V_306 ) ;
V_266 = V_258 -> V_307 - V_258 -> V_302 ;
F_3 ( V_2 , V_266 >> 8 , V_308 ) ;
F_3 ( V_2 , V_266 , V_309 ) ;
V_267 = V_258 -> V_310 - V_258 -> V_305 ;
F_3 ( V_2 , V_267 , V_311 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_195 )
return;
F_37 ( V_2 , 0 ) ;
F_36 ( V_2 , 0 ) ;
V_2 -> V_195 = false ;
}
static void F_49 ( struct V_1 * V_2 )
{
T_1 V_312 ;
F_3 ( V_2 , 12 , V_313 ) ;
F_3 ( V_2 , 32 , V_314 ) ;
F_3 ( V_2 , 1 , V_315 ) ;
F_3 ( V_2 , 0x0B , V_316 ) ;
F_3 ( V_2 , 0x16 , V_317 ) ;
F_3 ( V_2 , 0x21 , V_318 ) ;
V_312 = 0x7F ;
V_312 &= ~ V_319 ;
F_3 ( V_2 , V_312 , V_320 ) ;
V_312 &= ~ V_321 ;
F_3 ( V_2 , V_312 , V_320 ) ;
if ( F_19 ( V_2 ) ) {
V_312 &= ~ V_322 ;
F_3 ( V_2 , V_312 , V_320 ) ;
}
}
static void F_50 ( struct V_1 * V_2 )
{
F_7 ( V_2 , 0 , V_323 , V_320 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
int V_324 ;
T_1 V_8 ;
F_3 ( V_2 , ( T_1 ) ~ V_325 , V_326 ) ;
V_8 = F_5 ( V_2 , V_290 ) ;
if ( V_2 -> V_327 == V_328 ) {
F_3 ( V_2 , V_8 , V_290 ) ;
return;
}
for ( V_324 = 0 ; V_324 < 4 ; V_324 ++ )
F_3 ( V_2 , V_8 , V_290 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
F_3 ( V_2 , 0 , V_329 ) ;
F_3 ( V_2 , 0 , V_330 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_331 ,
V_330 ) ;
}
static int F_54 ( struct V_1 * V_2 , struct V_257 * V_258 )
{
int V_193 ;
F_53 ( V_2 ) ;
V_2 -> V_237 = F_55 ( V_258 ) ;
if ( ! V_2 -> V_237 ) {
F_15 ( V_2 -> V_34 , L_7 ) ;
V_2 -> V_35 . V_36 . V_194 = true ;
} else {
F_15 ( V_2 -> V_34 , L_8 , V_2 -> V_237 ) ;
V_2 -> V_35 . V_36 . V_194 = false ;
}
if ( ( V_2 -> V_237 == 6 ) || ( V_2 -> V_237 == 7 ) ||
( V_2 -> V_237 == 21 ) || ( V_2 -> V_237 == 22 ) ||
( V_2 -> V_237 == 2 ) || ( V_2 -> V_237 == 3 ) ||
( V_2 -> V_237 == 17 ) || ( V_2 -> V_237 == 18 ) )
V_2 -> V_35 . V_63 = V_64 ;
else
V_2 -> V_35 . V_63 = V_332 ;
if ( ( V_2 -> V_237 == 10 ) || ( V_2 -> V_237 == 11 ) ||
( V_2 -> V_237 == 12 ) || ( V_2 -> V_237 == 13 ) ||
( V_2 -> V_237 == 14 ) || ( V_2 -> V_237 == 15 ) ||
( V_2 -> V_237 == 25 ) || ( V_2 -> V_237 == 26 ) ||
( V_2 -> V_237 == 27 ) || ( V_2 -> V_237 == 28 ) ||
( V_2 -> V_237 == 29 ) || ( V_2 -> V_237 == 30 ) ||
( V_2 -> V_237 == 35 ) || ( V_2 -> V_237 == 36 ) ||
( V_2 -> V_237 == 37 ) || ( V_2 -> V_237 == 38 ) )
V_2 -> V_35 . V_36 . V_242 = 1 ;
else
V_2 -> V_35 . V_36 . V_242 = 0 ;
V_2 -> V_35 . V_36 . V_239 = 0 ;
V_2 -> V_35 . V_39 = V_40 ;
V_2 -> V_35 . V_58 = V_40 ;
V_2 -> V_35 . V_41 = 8 ;
V_2 -> V_35 . V_104 = 0 ;
V_2 -> V_35 . V_275 = 0 ;
V_2 -> V_35 . V_36 . V_197 = true ;
F_47 ( V_2 , V_258 ) ;
V_193 = F_44 ( V_2 ) ;
if ( V_193 )
return V_193 ;
F_49 ( V_2 ) ;
if ( V_2 -> V_35 . V_36 . V_194 )
F_15 ( V_2 -> V_34 , L_9 , V_30 ) ;
else {
F_15 ( V_2 -> V_34 , L_10 , V_30 ) ;
F_17 ( V_2 ) ;
F_50 ( V_2 ) ;
F_46 ( V_2 ) ;
}
F_26 ( V_2 ) ;
F_25 ( V_2 ) ;
F_18 ( V_2 ) ;
F_45 ( V_2 ) ;
F_51 ( V_2 ) ;
if ( V_2 -> V_333 && ! V_2 -> V_35 . V_36 . V_194 )
F_52 ( V_2 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_334 ,
V_335 ) ;
F_3 ( V_2 , V_336 |
V_337 ,
V_338 ) ;
F_3 ( V_2 , ( T_1 ) ~ V_339 , V_340 ) ;
F_3 ( V_2 , V_341 , V_342 ) ;
return 0 ;
}
static void F_57 ( struct V_1 * V_2 )
{
T_1 V_343 ;
V_343 = F_5 ( V_2 , V_344 ) |
V_345 |
V_346 ;
F_3 ( V_2 , V_343 , V_344 ) ;
F_3 ( V_2 , 0xff , V_347 ) ;
F_3 ( V_2 , 0xff , V_348 ) ;
F_3 ( V_2 , 0xff , V_349 ) ;
F_3 ( V_2 , 0xff , V_329 ) ;
F_3 ( V_2 , 0xff , V_340 ) ;
F_3 ( V_2 , 0xff , V_335 ) ;
F_3 ( V_2 , 0xff , V_338 ) ;
F_3 ( V_2 , 0xff , V_350 ) ;
F_3 ( V_2 , 0xff , V_351 ) ;
F_3 ( V_2 , 0xff , V_352 ) ;
F_3 ( V_2 , 0xff , V_353 ) ;
F_3 ( V_2 , 0xff , V_354 ) ;
F_3 ( V_2 , 0xff , V_355 ) ;
F_3 ( V_2 , 0xff , V_356 ) ;
F_3 ( V_2 , 0xff , V_357 ) ;
F_3 ( V_2 , 0xff , V_358 ) ;
F_3 ( V_2 , 0xff , V_359 ) ;
F_3 ( V_2 , 0xff , V_330 ) ;
F_3 ( V_2 , 0xff , V_360 ) ;
F_3 ( V_2 , 0xff , V_361 ) ;
F_3 ( V_2 , 0xff , V_362 ) ;
F_3 ( V_2 , 0xff , V_363 ) ;
F_3 ( V_2 , 0xff , V_364 ) ;
F_3 ( V_2 , 0xff , V_365 ) ;
F_3 ( V_2 , 0xff , V_366 ) ;
V_343 &= ~ ( V_345 |
V_346 ) ;
F_3 ( V_2 , V_343 , V_344 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
F_54 ( V_2 , & V_2 -> V_367 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
F_48 ( V_2 ) ;
}
static enum V_368 F_60 ( struct V_369
* V_370 , bool V_371 )
{
struct V_1 * V_2 = F_61 ( V_370 , struct V_1 ,
V_370 ) ;
return F_5 ( V_2 , V_190 ) & V_339 ?
V_372 : V_373 ;
}
static int F_62 ( struct V_369 * V_370 )
{
struct V_1 * V_2 = F_61 ( V_370 , struct V_1 ,
V_370 ) ;
struct V_374 * V_374 ;
int V_193 ;
if ( ! V_2 -> V_375 )
return 0 ;
V_374 = F_63 ( V_370 , V_2 -> V_375 ) ;
if ( V_374 ) {
F_15 ( V_2 -> V_34 , L_11 ,
V_374 -> V_376 , V_374 -> V_377 ) ;
F_64 ( V_370 , V_374 ) ;
V_193 = F_65 ( V_370 , V_374 ) ;
F_66 ( V_374 ) ;
} else {
F_15 ( V_2 -> V_34 , L_12 ) ;
}
return 0 ;
}
static struct V_378 * F_67 ( struct V_369
* V_370 )
{
struct V_1 * V_2 = F_61 ( V_370 , struct V_1 ,
V_370 ) ;
return & V_2 -> V_379 ;
}
static void F_68 ( struct V_378 * V_379 ,
struct V_257 * V_258 ,
struct V_257 * V_380 )
{
struct V_1 * V_2 = F_61 ( V_379 , struct V_1 , V_379 ) ;
F_54 ( V_2 , V_258 ) ;
memcpy ( & V_2 -> V_367 , V_258 , sizeof( V_2 -> V_367 ) ) ;
}
static bool F_69 ( struct V_378 * V_379 ,
const struct V_257 * V_258 ,
struct V_257 * V_380 )
{
return true ;
}
static void F_70 ( struct V_378 * V_379 )
{
}
static void F_71 ( struct V_378 * V_379 , int V_258 )
{
struct V_1 * V_2 = F_61 ( V_379 , struct V_1 , V_379 ) ;
if ( V_258 )
F_59 ( V_2 ) ;
else
F_58 ( V_2 ) ;
}
static void F_72 ( struct V_378 * V_379 )
{
struct V_1 * V_2 = F_61 ( V_379 , struct V_1 , V_379 ) ;
F_59 ( V_2 ) ;
F_73 ( V_379 , V_381 ) ;
}
static void F_74 ( struct V_378 * V_379 )
{
struct V_1 * V_2 = F_61 ( V_379 , struct V_1 , V_379 ) ;
int V_382 = F_75 ( V_2 -> V_34 -> V_383 , V_379 ) ;
F_1 ( V_2 , V_382 ) ;
F_58 ( V_2 ) ;
}
static T_3 F_76 ( int V_384 , void * V_385 )
{
struct V_1 * V_2 = V_385 ;
T_1 V_386 ;
V_386 = F_5 ( V_2 , V_342 ) ;
if ( V_386 )
F_3 ( V_2 , ~ 0 , V_361 ) ;
return V_386 ? V_387 : V_388 ;
}
static T_3 F_77 ( int V_384 , void * V_385 )
{
struct V_1 * V_2 = V_385 ;
T_1 V_386 ;
T_1 V_389 ;
V_386 = F_5 ( V_2 , V_342 ) ;
V_389 = F_5 ( V_2 , V_390 ) ;
if ( V_386 & V_341 ) {
if ( V_389 & V_339 ) {
F_15 ( V_2 -> V_34 , L_13 ) ;
F_7 ( V_2 , 0 , V_339 , V_390 ) ;
F_58 ( V_2 ) ;
} else {
F_15 ( V_2 -> V_34 , L_14 ) ;
F_7 ( V_2 , V_339 , V_339 ,
V_390 ) ;
F_59 ( V_2 ) ;
}
F_78 ( V_2 -> V_370 . V_34 ) ;
}
F_3 ( V_2 , V_386 , V_342 ) ;
F_3 ( V_2 , ~ V_341 , V_361 ) ;
return V_391 ;
}
static int F_79 ( struct V_392 * V_393 , struct V_1 * V_2 )
{
int V_193 ;
V_193 = F_80 ( V_393 , & V_2 -> V_379 ,
V_2 -> V_34 -> V_383 ) ;
if ( V_193 )
return V_193 ;
V_2 -> V_370 . V_394 = V_395 ;
F_81 ( & V_2 -> V_379 , & V_396 ) ;
F_82 ( V_393 , & V_2 -> V_379 , & V_397 ,
V_398 ) ;
F_83 ( & V_2 -> V_370 ,
& V_399 ) ;
F_84 ( V_393 , & V_2 -> V_370 , & V_400 ,
V_401 ) ;
V_2 -> V_370 . V_379 = & V_2 -> V_379 ;
F_85 ( & V_2 -> V_370 , & V_2 -> V_379 ) ;
return 0 ;
}
static int F_86 ( struct V_402 * V_34 , struct V_402 * V_403 , void * V_11 )
{
struct V_404 * V_405 = F_87 ( V_34 ) ;
const struct V_406 * V_407 =
F_88 ( V_408 , V_34 ) ;
struct V_392 * V_393 = V_11 ;
struct V_409 * V_410 = V_34 -> V_383 ;
struct V_409 * V_411 ;
struct V_1 * V_2 ;
struct V_412 * V_413 ;
int V_193 , V_384 ;
V_2 = F_89 ( V_34 , sizeof( * V_2 ) , V_414 ) ;
if ( ! V_2 )
return - V_415 ;
V_2 -> V_34 = V_34 ;
V_2 -> V_33 = 48000 ;
V_2 -> V_28 = 100 ;
if ( V_407 ) {
const struct V_416 * V_417 = V_407 -> V_11 ;
V_2 -> V_327 = V_417 -> V_418 ;
}
V_411 = F_90 ( V_410 , L_15 , 0 ) ;
if ( V_411 ) {
V_2 -> V_375 = F_91 ( V_411 ) ;
if ( ! V_2 -> V_375 )
F_15 ( V_2 -> V_34 , L_16 ) ;
F_92 ( V_411 ) ;
} else {
F_15 ( V_2 -> V_34 , L_17 ) ;
}
V_384 = F_93 ( V_405 , 0 ) ;
if ( V_384 < 0 )
return V_384 ;
V_193 = F_94 ( V_34 , V_384 , F_76 ,
F_77 , V_419 ,
F_95 ( V_34 ) , V_2 ) ;
if ( V_193 )
return V_193 ;
V_413 = F_96 ( V_405 , V_420 , 0 ) ;
V_2 -> V_10 = F_97 ( V_34 , V_413 ) ;
if ( F_98 ( V_2 -> V_10 ) )
return F_99 ( V_2 -> V_10 ) ;
V_2 -> V_4 = F_100 ( V_410 , L_18 ) ;
if ( F_98 ( V_2 -> V_4 ) )
return F_99 ( V_2 -> V_4 ) ;
V_2 -> V_421 = F_101 ( V_2 -> V_34 , L_19 ) ;
if ( F_98 ( V_2 -> V_421 ) ) {
V_193 = F_99 ( V_2 -> V_421 ) ;
F_43 ( V_2 -> V_34 ,
L_20 , V_193 ) ;
return V_193 ;
}
V_193 = F_102 ( V_2 -> V_421 ) ;
if ( V_193 ) {
F_43 ( V_2 -> V_34 ,
L_21 , V_193 ) ;
return V_193 ;
}
V_2 -> V_422 = F_101 ( V_2 -> V_34 , L_22 ) ;
if ( F_98 ( V_2 -> V_422 ) ) {
V_193 = F_99 ( V_2 -> V_422 ) ;
F_43 ( V_2 -> V_34 ,
L_23 , V_193 ) ;
goto V_423;
}
V_193 = F_102 ( V_2 -> V_422 ) ;
if ( V_193 ) {
F_43 ( V_2 -> V_34 ,
L_24 , V_193 ) ;
goto V_423;
}
F_103 ( V_34 ,
L_25 ,
F_5 ( V_2 , V_424 ) ,
F_5 ( V_2 , V_425 ) ,
F_5 ( V_2 , V_426 ) ,
F_5 ( V_2 , V_427 ) ) ;
F_57 ( V_2 ) ;
F_16 ( V_2 ) ;
F_3 ( V_2 , V_339 , V_390 ) ;
F_3 ( V_2 , V_341 , V_342 ) ;
V_193 = F_56 ( V_2 ) ;
if ( V_193 )
goto V_428;
V_193 = F_79 ( V_393 , V_2 ) ;
if ( V_193 )
goto V_428;
F_3 ( V_2 , ~ V_341 , V_361 ) ;
F_104 ( V_34 , V_2 ) ;
return 0 ;
V_428:
F_105 ( V_2 -> V_422 ) ;
V_423:
F_105 ( V_2 -> V_421 ) ;
return V_193 ;
}
static void F_106 ( struct V_402 * V_34 , struct V_402 * V_403 ,
void * V_11 )
{
struct V_1 * V_2 = F_107 ( V_34 ) ;
F_3 ( V_2 , ~ 0 , V_361 ) ;
V_2 -> V_370 . V_429 -> V_430 ( & V_2 -> V_370 ) ;
V_2 -> V_379 . V_429 -> V_430 ( & V_2 -> V_379 ) ;
F_105 ( V_2 -> V_422 ) ;
F_105 ( V_2 -> V_421 ) ;
F_108 ( V_2 -> V_375 ) ;
}
static int F_109 ( struct V_404 * V_405 )
{
return F_110 ( & V_405 -> V_34 , & V_431 ) ;
}
static int F_111 ( struct V_404 * V_405 )
{
F_112 ( & V_405 -> V_34 , & V_431 ) ;
return 0 ;
}
