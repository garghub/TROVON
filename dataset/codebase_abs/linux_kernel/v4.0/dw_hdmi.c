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
static void F_13 ( struct V_1 * V_2 ,
unsigned int V_12 )
{
F_9 ( V_2 , V_12 & 0xff , V_13 ) ;
F_9 ( V_2 , ( V_12 >> 8 ) & 0xff , V_14 ) ;
F_9 ( V_2 , ( V_12 >> 16 ) & 0x0f , V_15 ) ;
F_11 ( V_2 , 0 , V_16 , V_17 ) ;
}
static void F_14 ( struct V_1 * V_2 , unsigned int V_18 )
{
F_11 ( V_2 , 0 , V_19 , V_17 ) ;
F_9 ( V_2 , V_18 & 0xff , V_20 ) ;
F_9 ( V_2 , ( V_18 >> 8 ) & 0xff , V_21 ) ;
F_9 ( V_2 , ( ( V_18 >> 16 ) & V_22 ) |
V_19 , V_17 ) ;
}
static unsigned int F_15 ( unsigned int V_23 , unsigned long V_24 ,
unsigned int V_25 )
{
unsigned int V_26 = ( 128 * V_23 ) / 1000 ;
switch ( V_23 ) {
case 32000 :
if ( V_24 == 25170000 )
V_26 = ( V_25 == 150 ) ? 9152 : 4576 ;
else if ( V_24 == 27020000 )
V_26 = ( V_25 == 150 ) ? 8192 : 4096 ;
else if ( V_24 == 74170000 || V_24 == 148350000 )
V_26 = 11648 ;
else
V_26 = 4096 ;
break;
case 44100 :
if ( V_24 == 25170000 )
V_26 = 7007 ;
else if ( V_24 == 74170000 )
V_26 = 17836 ;
else if ( V_24 == 148350000 )
V_26 = ( V_25 == 150 ) ? 17836 : 8918 ;
else
V_26 = 6272 ;
break;
case 48000 :
if ( V_24 == 25170000 )
V_26 = ( V_25 == 150 ) ? 9152 : 6864 ;
else if ( V_24 == 27020000 )
V_26 = ( V_25 == 150 ) ? 8192 : 6144 ;
else if ( V_24 == 74170000 )
V_26 = 11648 ;
else if ( V_24 == 148350000 )
V_26 = ( V_25 == 150 ) ? 11648 : 5824 ;
else
V_26 = 6144 ;
break;
case 88200 :
V_26 = F_15 ( 44100 , V_24 , V_25 ) * 2 ;
break;
case 96000 :
V_26 = F_15 ( 48000 , V_24 , V_25 ) * 2 ;
break;
case 176400 :
V_26 = F_15 ( 44100 , V_24 , V_25 ) * 4 ;
break;
case 192000 :
V_26 = F_15 ( 48000 , V_24 , V_25 ) * 4 ;
break;
default:
break;
}
return V_26 ;
}
static unsigned int F_16 ( unsigned int V_23 , unsigned long V_24 ,
unsigned int V_25 )
{
unsigned int V_18 = 0 ;
F_17 ( L_1 , V_27 , V_23 ,
V_24 , V_25 ) ;
switch ( V_23 ) {
case 32000 :
if ( V_24 == 297000000 ) {
V_18 = 222750 ;
break;
}
case 48000 :
case 96000 :
case 192000 :
switch ( V_24 ) {
case 25200000 :
case 27000000 :
case 54000000 :
case 74250000 :
case 148500000 :
V_18 = V_24 / 1000 ;
break;
case 297000000 :
V_18 = 247500 ;
break;
default:
break;
}
break;
case 44100 :
case 88200 :
case 176400 :
switch ( V_24 ) {
case 25200000 :
V_18 = 28000 ;
break;
case 27000000 :
V_18 = 30000 ;
break;
case 54000000 :
V_18 = 60000 ;
break;
case 74250000 :
V_18 = 82500 ;
break;
case 148500000 :
V_18 = 165000 ;
break;
case 297000000 :
V_18 = 247500 ;
break;
default:
break;
}
break;
default:
break;
}
if ( V_25 == 100 )
return V_18 ;
return ( V_18 * V_25 ) / 100 ;
}
static void F_18 ( struct V_1 * V_2 ,
unsigned long V_24 )
{
unsigned int V_28 , V_29 ;
V_28 = F_15 ( V_2 -> V_30 , V_24 ,
V_2 -> V_25 ) ;
V_29 = F_16 ( V_2 -> V_30 , V_24 ,
V_2 -> V_25 ) ;
if ( ! V_29 ) {
F_19 ( V_2 -> V_31 , L_2 ,
V_27 , V_24 ) ;
return;
}
F_19 ( V_2 -> V_31 , L_3 ,
V_27 , V_2 -> V_30 , V_2 -> V_25 ,
V_24 , V_28 , V_29 ) ;
F_13 ( V_2 , V_28 ) ;
F_14 ( V_2 , V_29 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_18 ( V_2 , 74250000 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_2 -> V_32 . V_33 . V_34 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
int V_35 = 0 ;
T_1 V_3 ;
if ( V_2 -> V_32 . V_36 == V_37 ) {
if ( V_2 -> V_32 . V_38 == 8 )
V_35 = 0x01 ;
else if ( V_2 -> V_32 . V_38 == 10 )
V_35 = 0x03 ;
else if ( V_2 -> V_32 . V_38 == 12 )
V_35 = 0x05 ;
else if ( V_2 -> V_32 . V_38 == 16 )
V_35 = 0x07 ;
else
return;
} else if ( V_2 -> V_32 . V_36 == V_39 ) {
if ( V_2 -> V_32 . V_38 == 8 )
V_35 = 0x09 ;
else if ( V_2 -> V_32 . V_38 == 10 )
V_35 = 0x0B ;
else if ( V_2 -> V_32 . V_38 == 12 )
V_35 = 0x0D ;
else if ( V_2 -> V_32 . V_38 == 16 )
V_35 = 0x0F ;
else
return;
} else if ( V_2 -> V_32 . V_36 == V_40 ) {
if ( V_2 -> V_32 . V_38 == 8 )
V_35 = 0x16 ;
else if ( V_2 -> V_32 . V_38 == 10 )
V_35 = 0x14 ;
else if ( V_2 -> V_32 . V_38 == 12 )
V_35 = 0x12 ;
else
return;
}
V_3 = V_41 |
( ( V_35 << V_42 ) &
V_43 ) ;
F_9 ( V_2 , V_3 , V_44 ) ;
V_3 = V_45 |
V_46 |
V_47 ;
F_9 ( V_2 , V_3 , V_48 ) ;
F_9 ( V_2 , 0x0 , V_49 ) ;
F_9 ( V_2 , 0x0 , V_50 ) ;
F_9 ( V_2 , 0x0 , V_51 ) ;
F_9 ( V_2 , 0x0 , V_52 ) ;
F_9 ( V_2 , 0x0 , V_53 ) ;
F_9 ( V_2 , 0x0 , V_54 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
return V_2 -> V_32 . V_36 != V_2 -> V_32 . V_55 ;
}
static int F_24 ( struct V_1 * V_2 )
{
if ( V_2 -> V_32 . V_55 != V_40 )
return 0 ;
if ( V_2 -> V_32 . V_36 == V_37 ||
V_2 -> V_32 . V_36 == V_39 )
return 1 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
if ( V_2 -> V_32 . V_36 != V_40 )
return 0 ;
if ( V_2 -> V_32 . V_55 == V_37 ||
V_2 -> V_32 . V_55 == V_39 )
return 1 ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 )
{
const F_27 ( * V_56 ) [ 3 ] [ 4 ] = & V_57 ;
unsigned V_58 ;
T_2 V_59 = 1 ;
if ( F_23 ( V_2 ) ) {
if ( V_2 -> V_32 . V_55 == V_37 ) {
if ( V_2 -> V_32 . V_60 ==
V_61 )
V_56 = & V_62 ;
else
V_56 = & V_63 ;
} else if ( V_2 -> V_32 . V_36 == V_37 ) {
if ( V_2 -> V_32 . V_60 ==
V_61 )
V_56 = & V_64 ;
else
V_56 = & V_65 ;
V_59 = 0 ;
}
}
for ( V_58 = 0 ; V_58 < F_28 ( V_57 [ 0 ] ) ; V_58 ++ ) {
F_27 V_66 = ( * V_56 ) [ 0 ] [ V_58 ] ;
F_27 V_67 = ( * V_56 ) [ 1 ] [ V_58 ] ;
F_27 V_68 = ( * V_56 ) [ 2 ] [ V_58 ] ;
F_9 ( V_2 , V_66 & 0xff , V_69 + V_58 * 2 ) ;
F_9 ( V_2 , V_66 >> 8 , V_70 + V_58 * 2 ) ;
F_9 ( V_2 , V_67 & 0xff , V_71 + V_58 * 2 ) ;
F_9 ( V_2 , V_67 >> 8 , V_72 + V_58 * 2 ) ;
F_9 ( V_2 , V_68 & 0xff , V_73 + V_58 * 2 ) ;
F_9 ( V_2 , V_68 >> 8 , V_74 + V_58 * 2 ) ;
}
F_11 ( V_2 , V_59 , V_75 ,
V_76 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
int V_77 = 0 ;
int V_78 = V_79 ;
int V_80 = 0 ;
if ( F_25 ( V_2 ) )
V_78 = V_81 ;
else if ( F_24 ( V_2 ) )
V_80 = V_82 ;
if ( V_2 -> V_32 . V_38 == 8 )
V_77 = V_83 ;
else if ( V_2 -> V_32 . V_38 == 10 )
V_77 = V_84 ;
else if ( V_2 -> V_32 . V_38 == 12 )
V_77 = V_85 ;
else if ( V_2 -> V_32 . V_38 == 16 )
V_77 = V_86 ;
else
return;
F_9 ( V_2 , V_78 | V_80 , V_87 ) ;
F_11 ( V_2 , V_77 , V_88 ,
V_76 ) ;
F_26 ( V_2 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
unsigned int V_77 = 0 ;
unsigned int V_89 = V_90 ;
unsigned int V_91 = V_92 ;
struct V_93 * V_32 = & V_2 -> V_32 ;
T_1 V_3 , V_94 ;
if ( V_32 -> V_55 == V_37 ||
V_32 -> V_55 == V_39 ) {
if ( ! V_32 -> V_38 ) {
V_91 = V_95 ;
} else if ( V_32 -> V_38 == 8 ) {
V_77 = 4 ;
V_91 = V_95 ;
} else if ( V_32 -> V_38 == 10 ) {
V_77 = 5 ;
} else if ( V_32 -> V_38 == 12 ) {
V_77 = 6 ;
} else if ( V_32 -> V_38 == 16 ) {
V_77 = 7 ;
} else {
return;
}
} else if ( V_32 -> V_55 == V_40 ) {
if ( ! V_32 -> V_38 ||
V_32 -> V_38 == 8 )
V_89 = V_90 ;
else if ( V_32 -> V_38 == 10 )
V_89 = V_96 ;
else if ( V_32 -> V_38 == 12 )
V_89 = V_97 ;
else
return;
V_91 = V_98 ;
} else {
return;
}
V_3 = ( ( V_77 << V_99 ) &
V_100 ) |
( ( V_32 -> V_101 <<
V_102 ) &
V_103 ) ;
F_9 ( V_2 , V_3 , V_104 ) ;
F_11 ( V_2 , V_105 ,
V_106 , V_107 ) ;
if ( V_32 -> V_101 > 1 ) {
V_94 = V_108 |
V_109 ;
} else {
V_94 = V_110 |
V_111 ;
}
F_11 ( V_2 , V_94 ,
V_112 |
V_113 , V_114 ) ;
F_11 ( V_2 , 1 << V_115 ,
V_116 , V_107 ) ;
F_9 ( V_2 , V_89 , V_117 ) ;
if ( V_91 == V_92 ) {
V_94 = V_118 |
V_119 |
V_120 ;
} else if ( V_91 == V_98 ) {
V_94 = V_118 |
V_121 |
V_122 ;
} else if ( V_91 == V_95 ) {
V_94 = V_123 |
V_121 |
V_120 ;
} else {
return;
}
F_11 ( V_2 , V_94 ,
V_124 | V_125 |
V_126 , V_114 ) ;
F_11 ( V_2 , V_127 |
V_128 ,
V_129 |
V_130 , V_107 ) ;
F_11 ( V_2 , V_91 , V_131 ,
V_114 ) ;
}
static inline void F_31 ( struct V_1 * V_2 ,
unsigned char V_132 )
{
F_11 ( V_2 , V_132 << V_133 ,
V_134 , V_135 ) ;
}
static inline void F_32 ( struct V_1 * V_2 ,
unsigned char V_132 )
{
F_11 ( V_2 , V_132 << V_136 ,
V_137 , V_135 ) ;
}
static inline void F_33 ( struct V_1 * V_2 ,
unsigned char V_132 )
{
F_11 ( V_2 , V_132 << V_138 ,
V_139 , V_135 ) ;
}
static inline void F_34 ( struct V_1 * V_2 ,
unsigned char V_132 )
{
F_9 ( V_2 , V_132 , V_140 ) ;
}
static inline void F_35 ( struct V_1 * V_2 ,
unsigned char V_132 )
{
F_9 ( V_2 , V_132 , V_141 ) ;
}
static bool F_36 ( struct V_1 * V_2 , int V_142 )
{
T_2 V_3 ;
while ( ( V_3 = F_10 ( V_2 , V_143 ) & 0x3 ) == 0 ) {
if ( V_142 -- == 0 )
return false ;
F_37 ( 1000 ) ;
}
F_9 ( V_2 , V_3 , V_143 ) ;
return true ;
}
static void F_38 ( struct V_1 * V_2 , unsigned short V_8 ,
unsigned char V_144 )
{
F_9 ( V_2 , 0xFF , V_143 ) ;
F_9 ( V_2 , V_144 , V_145 ) ;
F_9 ( V_2 , ( unsigned char ) ( V_8 >> 8 ) ,
V_146 ) ;
F_9 ( V_2 , ( unsigned char ) ( V_8 >> 0 ) ,
V_147 ) ;
F_9 ( V_2 , V_148 ,
V_149 ) ;
F_36 ( V_2 , 1000 ) ;
}
static int F_39 ( struct V_1 * V_2 , unsigned short V_8 ,
unsigned char V_144 )
{
F_38 ( V_2 , V_8 , V_144 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_2 , T_1 V_150 )
{
F_12 ( V_2 , V_150 , V_151 ,
V_152 ,
V_153 ) ;
}
static void F_41 ( struct V_1 * V_2 , T_1 V_150 )
{
F_12 ( V_2 , V_150 , V_151 ,
V_154 ,
V_155 ) ;
}
static void F_42 ( struct V_1 * V_2 , T_1 V_150 )
{
F_12 ( V_2 , V_150 , V_151 ,
V_156 ,
V_157 ) ;
}
static void F_43 ( struct V_1 * V_2 , T_1 V_150 )
{
F_12 ( V_2 , V_150 , V_151 ,
V_158 ,
V_159 ) ;
}
static void F_44 ( struct V_1 * V_2 , T_1 V_150 )
{
F_12 ( V_2 , V_150 , V_151 ,
V_160 ,
V_161 ) ;
}
static void F_45 ( struct V_1 * V_2 , T_1 V_150 )
{
F_12 ( V_2 , V_150 , V_151 ,
V_162 ,
V_163 ) ;
}
static void F_46 ( struct V_1 * V_2 , T_1 V_150 )
{
F_12 ( V_2 , V_150 , V_151 ,
V_164 ,
V_165 ) ;
}
static int F_47 ( struct V_1 * V_2 , unsigned char V_166 ,
unsigned char V_167 , int V_168 )
{
unsigned V_169 , V_58 ;
T_1 V_3 , V_142 ;
const struct V_170 * V_171 =
V_2 -> V_172 -> V_173 ;
const struct V_174 * V_175 = V_2 -> V_172 -> V_176 ;
const struct V_177 * V_178 = V_2 -> V_172 -> V_178 ;
if ( V_166 )
return - V_179 ;
switch ( V_167 ) {
case 0 :
case 8 :
V_169 = V_180 ;
break;
case 10 :
V_169 = V_181 ;
break;
case 12 :
V_169 = V_182 ;
break;
default:
return - V_179 ;
}
if ( V_168 )
V_3 = V_183 ;
else
V_3 = V_184 ;
F_9 ( V_2 , V_3 , V_185 ) ;
F_44 ( V_2 , 0 ) ;
F_43 ( V_2 , 1 ) ;
F_9 ( V_2 , V_186 , V_187 ) ;
F_9 ( V_2 , V_188 , V_187 ) ;
F_9 ( V_2 , V_189 , V_190 ) ;
F_31 ( V_2 , 1 ) ;
F_9 ( V_2 , V_191 ,
V_192 ) ;
F_31 ( V_2 , 0 ) ;
for ( V_58 = 0 ; V_171 [ V_58 ] . V_34 != ( ~ 0UL ) ; V_58 ++ )
if ( V_2 -> V_32 . V_33 . V_34 <=
V_171 [ V_58 ] . V_34 )
break;
F_39 ( V_2 , V_171 [ V_58 ] . V_167 [ V_169 ] . V_193 , 0x06 ) ;
F_39 ( V_2 , V_171 [ V_58 ] . V_167 [ V_169 ] . V_194 , 0x15 ) ;
for ( V_58 = 0 ; V_175 [ V_58 ] . V_34 != ( ~ 0UL ) ; V_58 ++ )
if ( V_2 -> V_32 . V_33 . V_34 <=
V_175 [ V_58 ] . V_34 )
break;
if ( V_175 [ V_58 ] . V_34 == ( ~ 0UL ) ) {
F_48 ( V_2 -> V_31 , L_4 ,
V_2 -> V_32 . V_33 . V_34 ) ;
return - V_179 ;
}
F_39 ( V_2 , V_175 [ V_58 ] . V_195 [ V_169 ] , 0x10 ) ;
F_39 ( V_2 , 0x0000 , 0x13 ) ;
F_39 ( V_2 , 0x0006 , 0x17 ) ;
for ( V_58 = 0 ; V_178 [ V_58 ] . V_34 != ( ~ 0UL ) ; V_58 ++ )
if ( V_2 -> V_32 . V_33 . V_34 <=
V_178 [ V_58 ] . V_34 )
break;
F_39 ( V_2 , V_178 [ V_58 ] . V_196 , 0x19 ) ;
F_39 ( V_2 , V_178 [ V_58 ] . V_197 , 0x09 ) ;
F_39 ( V_2 , 0x01ad , 0x0E ) ;
F_39 ( V_2 , 0x8000 , 0x05 ) ;
F_40 ( V_2 , 1 ) ;
F_41 ( V_2 , 0 ) ;
F_41 ( V_2 , 1 ) ;
F_44 ( V_2 , 1 ) ;
F_43 ( V_2 , 0 ) ;
if ( V_2 -> V_198 == V_199 )
F_42 ( V_2 , 1 ) ;
V_142 = 5 ;
do {
V_3 = F_10 ( V_2 , V_200 ) & V_201 ;
if ( ! V_3 )
break;
if ( V_142 == 0 ) {
F_48 ( V_2 -> V_31 , L_5 ) ;
return - V_202 ;
}
F_37 ( 1000 ) ;
V_142 -- ;
} while ( 1 );
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_58 , V_203 ;
bool V_168 = false ;
V_168 = ( F_23 ( V_2 ) &&
! V_2 -> V_32 . V_33 . V_204 ) ;
for ( V_58 = 0 ; V_58 < 2 ; V_58 ++ ) {
F_45 ( V_2 , 1 ) ;
F_46 ( V_2 , 0 ) ;
F_41 ( V_2 , 0 ) ;
F_40 ( V_2 , 0 ) ;
V_203 = F_47 ( V_2 , 0 , 8 , V_168 ) ;
if ( V_203 )
return V_203 ;
}
V_2 -> V_205 = true ;
return 0 ;
}
static void F_50 ( struct V_1 * V_2 )
{
T_1 V_206 ;
if ( V_2 -> V_32 . V_33 . V_207 )
V_206 = V_208 ;
else
V_206 = V_209 ;
F_11 ( V_2 , V_210 ,
V_211 , V_212 ) ;
F_11 ( V_2 , V_206 , V_213 , V_214 ) ;
F_11 ( V_2 , V_215 ,
V_216 , V_217 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
T_1 V_3 , V_218 , V_219 ;
T_1 V_220 , V_221 , V_60 , V_222 ;
bool V_223 ;
V_223 = false ;
if ( V_2 -> V_32 . V_55 == V_39 )
V_218 = V_224 ;
else if ( V_2 -> V_32 . V_55 == V_40 )
V_218 = V_225 ;
else
V_218 = V_226 ;
V_219 = V_227 ;
V_3 = V_218 | V_219 |
V_228 |
V_229 ;
F_9 ( V_2 , V_3 , V_230 ) ;
if ( V_223 ) {
V_220 = V_231 ;
V_221 = V_232 ;
} else {
V_220 = V_233 ;
V_221 = V_234 ;
}
if ( V_2 -> V_32 . V_55 == V_235 ) {
V_60 = V_236 ;
if ( V_2 -> V_32 . V_60 == V_61 )
V_222 =
V_237 ;
else
V_222 =
V_238 ;
} else if ( V_2 -> V_32 . V_55 != V_37 ) {
if ( V_2 -> V_32 . V_60 == V_61 )
V_60 = V_239 ;
else
V_60 = V_240 ;
V_222 = V_237 ;
} else {
V_60 = V_241 ;
V_222 = V_237 ;
}
V_3 = V_60 | V_221 | V_220 ;
F_9 ( V_2 , V_3 , V_242 ) ;
V_3 = V_243 | V_222 |
V_244 |
V_245 ;
F_9 ( V_2 , V_3 , V_246 ) ;
F_9 ( V_2 , V_2 -> V_247 , V_248 ) ;
V_3 = ( ( ( V_2 -> V_32 . V_33 . V_249 + 1 ) <<
V_250 ) &
V_251 ) |
( ( V_2 -> V_32 . V_33 . V_252 <<
V_253 ) &
V_254 ) ;
F_9 ( V_2 , V_3 , V_255 ) ;
V_3 = V_256 |
V_257 ;
F_9 ( V_2 , V_3 , V_258 ) ;
F_9 ( V_2 , 0 , V_259 ) ;
F_9 ( V_2 , 0 , V_260 ) ;
F_9 ( V_2 , 0 , V_261 ) ;
F_9 ( V_2 , 0 , V_262 ) ;
F_9 ( V_2 , 0 , V_263 ) ;
F_9 ( V_2 , 0 , V_264 ) ;
F_9 ( V_2 , 0 , V_265 ) ;
F_9 ( V_2 , 0 , V_266 ) ;
}
static void F_52 ( struct V_1 * V_2 ,
const struct V_267 * V_268 )
{
T_1 V_269 ;
struct V_270 * V_271 = & V_2 -> V_32 . V_33 ;
int V_272 , V_273 , V_274 , V_275 , V_276 , V_277 ;
V_271 -> V_278 = ! ! ( V_268 -> V_279 & V_280 ) ;
V_271 -> V_281 = ! ! ( V_268 -> V_279 & V_282 ) ;
V_271 -> V_283 = ! ! ( V_268 -> V_279 & V_284 ) ;
V_271 -> V_34 = V_268 -> clock * 1000 ;
F_19 ( V_2 -> V_31 , L_6 , V_271 -> V_34 ) ;
V_269 = ( V_2 -> V_32 . V_285 ?
V_286 :
V_287 ) ;
V_269 |= ( V_271 -> V_281 ?
V_288 :
V_289 ) ;
V_269 |= ( V_271 -> V_278 ?
V_290 :
V_291 ) ;
V_269 |= ( V_271 -> V_207 ?
V_292 :
V_293 ) ;
if ( V_2 -> V_247 == 39 )
V_269 |= V_294 ;
else
V_269 |= ( V_271 -> V_283 ?
V_294 :
V_295 ) ;
V_269 |= ( V_271 -> V_283 ?
V_296 :
V_297 ) ;
V_269 |= ( V_271 -> V_204 ?
V_298 :
V_299 ) ;
F_9 ( V_2 , V_269 , V_300 ) ;
F_9 ( V_2 , V_268 -> V_301 >> 8 , V_302 ) ;
F_9 ( V_2 , V_268 -> V_301 , V_303 ) ;
F_9 ( V_2 , V_268 -> V_304 >> 8 , V_305 ) ;
F_9 ( V_2 , V_268 -> V_304 , V_306 ) ;
V_272 = V_268 -> V_307 - V_268 -> V_301 ;
F_9 ( V_2 , V_272 >> 8 , V_308 ) ;
F_9 ( V_2 , V_272 , V_309 ) ;
V_273 = V_268 -> V_310 - V_268 -> V_304 ;
F_9 ( V_2 , V_273 , V_311 ) ;
V_274 = V_268 -> V_312 - V_268 -> V_301 ;
F_9 ( V_2 , V_274 >> 8 , V_313 ) ;
F_9 ( V_2 , V_274 , V_314 ) ;
V_275 = V_268 -> V_315 - V_268 -> V_304 ;
F_9 ( V_2 , V_275 , V_316 ) ;
V_276 = V_268 -> V_317 - V_268 -> V_312 ;
F_9 ( V_2 , V_276 >> 8 , V_318 ) ;
F_9 ( V_2 , V_276 , V_319 ) ;
V_277 = V_268 -> V_320 - V_268 -> V_315 ;
F_9 ( V_2 , V_277 , V_321 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_205 )
return;
F_41 ( V_2 , 0 ) ;
F_40 ( V_2 , 0 ) ;
V_2 -> V_205 = false ;
}
static void F_54 ( struct V_1 * V_2 )
{
T_1 V_322 ;
F_9 ( V_2 , 12 , V_323 ) ;
F_9 ( V_2 , 32 , V_324 ) ;
F_9 ( V_2 , 1 , V_325 ) ;
F_9 ( V_2 , 0x0B , V_326 ) ;
F_9 ( V_2 , 0x16 , V_327 ) ;
F_9 ( V_2 , 0x21 , V_328 ) ;
V_322 = 0x7F ;
V_322 &= ~ V_329 ;
F_9 ( V_2 , V_322 , V_330 ) ;
V_322 &= ~ V_331 ;
F_9 ( V_2 , V_322 , V_330 ) ;
if ( F_23 ( V_2 ) ) {
V_322 &= ~ V_332 ;
F_9 ( V_2 , V_322 , V_330 ) ;
}
}
static void F_55 ( struct V_1 * V_2 )
{
F_11 ( V_2 , 0 , V_333 , V_330 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
int V_334 ;
T_1 V_3 ;
F_9 ( V_2 , ( T_1 ) ~ V_335 , V_336 ) ;
V_3 = F_10 ( V_2 , V_300 ) ;
if ( V_2 -> V_198 == V_337 ) {
F_9 ( V_2 , V_3 , V_300 ) ;
return;
}
for ( V_334 = 0 ; V_334 < 4 ; V_334 ++ )
F_9 ( V_2 , V_3 , V_300 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
F_9 ( V_2 , 0 , V_338 ) ;
F_9 ( V_2 , 0 , V_339 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_340 ,
V_339 ) ;
}
static int F_59 ( struct V_1 * V_2 , struct V_267 * V_268 )
{
int V_203 ;
F_58 ( V_2 ) ;
V_2 -> V_247 = F_60 ( V_268 ) ;
if ( ! V_2 -> V_247 ) {
F_19 ( V_2 -> V_31 , L_7 ) ;
V_2 -> V_32 . V_33 . V_204 = true ;
} else {
F_19 ( V_2 -> V_31 , L_8 , V_2 -> V_247 ) ;
V_2 -> V_32 . V_33 . V_204 = false ;
}
if ( ( V_2 -> V_247 == 6 ) || ( V_2 -> V_247 == 7 ) ||
( V_2 -> V_247 == 21 ) || ( V_2 -> V_247 == 22 ) ||
( V_2 -> V_247 == 2 ) || ( V_2 -> V_247 == 3 ) ||
( V_2 -> V_247 == 17 ) || ( V_2 -> V_247 == 18 ) )
V_2 -> V_32 . V_60 = V_61 ;
else
V_2 -> V_32 . V_60 = V_341 ;
if ( ( V_2 -> V_247 == 10 ) || ( V_2 -> V_247 == 11 ) ||
( V_2 -> V_247 == 12 ) || ( V_2 -> V_247 == 13 ) ||
( V_2 -> V_247 == 14 ) || ( V_2 -> V_247 == 15 ) ||
( V_2 -> V_247 == 25 ) || ( V_2 -> V_247 == 26 ) ||
( V_2 -> V_247 == 27 ) || ( V_2 -> V_247 == 28 ) ||
( V_2 -> V_247 == 29 ) || ( V_2 -> V_247 == 30 ) ||
( V_2 -> V_247 == 35 ) || ( V_2 -> V_247 == 36 ) ||
( V_2 -> V_247 == 37 ) || ( V_2 -> V_247 == 38 ) )
V_2 -> V_32 . V_33 . V_252 = 1 ;
else
V_2 -> V_32 . V_33 . V_252 = 0 ;
V_2 -> V_32 . V_33 . V_249 = 0 ;
V_2 -> V_32 . V_36 = V_37 ;
V_2 -> V_32 . V_55 = V_37 ;
V_2 -> V_32 . V_38 = 8 ;
V_2 -> V_32 . V_101 = 0 ;
V_2 -> V_32 . V_285 = 0 ;
V_2 -> V_32 . V_33 . V_207 = true ;
F_52 ( V_2 , V_268 ) ;
V_203 = F_49 ( V_2 ) ;
if ( V_203 )
return V_203 ;
F_54 ( V_2 ) ;
if ( V_2 -> V_32 . V_33 . V_204 ) {
F_19 ( V_2 -> V_31 , L_9 , V_27 ) ;
} else {
F_19 ( V_2 -> V_31 , L_10 , V_27 ) ;
F_21 ( V_2 ) ;
F_55 ( V_2 ) ;
F_51 ( V_2 ) ;
}
F_30 ( V_2 ) ;
F_29 ( V_2 ) ;
F_22 ( V_2 ) ;
F_50 ( V_2 ) ;
F_56 ( V_2 ) ;
if ( V_2 -> V_342 && ! V_2 -> V_32 . V_33 . V_204 )
F_57 ( V_2 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_343 ,
V_344 ) ;
F_9 ( V_2 , V_345 |
V_346 ,
V_347 ) ;
F_9 ( V_2 , ( T_1 ) ~ V_348 , V_349 ) ;
F_9 ( V_2 , V_350 , V_351 ) ;
return 0 ;
}
static void F_62 ( struct V_1 * V_2 )
{
T_1 V_352 ;
V_352 = F_10 ( V_2 , V_353 ) |
V_354 |
V_355 ;
F_9 ( V_2 , V_352 , V_353 ) ;
F_9 ( V_2 , 0xff , V_356 ) ;
F_9 ( V_2 , 0xff , V_357 ) ;
F_9 ( V_2 , 0xff , V_358 ) ;
F_9 ( V_2 , 0xff , V_338 ) ;
F_9 ( V_2 , 0xff , V_349 ) ;
F_9 ( V_2 , 0xff , V_344 ) ;
F_9 ( V_2 , 0xff , V_347 ) ;
F_9 ( V_2 , 0xff , V_359 ) ;
F_9 ( V_2 , 0xff , V_360 ) ;
F_9 ( V_2 , 0xff , V_361 ) ;
F_9 ( V_2 , 0xff , V_362 ) ;
F_9 ( V_2 , 0xff , V_363 ) ;
F_9 ( V_2 , 0xff , V_364 ) ;
F_9 ( V_2 , 0xff , V_365 ) ;
F_9 ( V_2 , 0xff , V_366 ) ;
F_9 ( V_2 , 0xff , V_367 ) ;
F_9 ( V_2 , 0xff , V_368 ) ;
F_9 ( V_2 , 0xff , V_339 ) ;
F_9 ( V_2 , 0xff , V_369 ) ;
F_9 ( V_2 , 0xff , V_370 ) ;
F_9 ( V_2 , 0xff , V_371 ) ;
F_9 ( V_2 , 0xff , V_372 ) ;
F_9 ( V_2 , 0xff , V_373 ) ;
F_9 ( V_2 , 0xff , V_374 ) ;
F_9 ( V_2 , 0xff , V_375 ) ;
V_352 &= ~ ( V_354 |
V_355 ) ;
F_9 ( V_2 , V_352 , V_353 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
F_59 ( V_2 , & V_2 -> V_376 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
F_53 ( V_2 ) ;
}
static void F_65 ( struct V_377 * V_378 ,
struct V_267 * V_379 ,
struct V_267 * V_268 )
{
struct V_1 * V_2 = V_378 -> V_380 ;
F_59 ( V_2 , V_268 ) ;
memcpy ( & V_2 -> V_376 , V_268 , sizeof( V_2 -> V_376 ) ) ;
}
static bool F_66 ( struct V_377 * V_378 ,
const struct V_267 * V_268 ,
struct V_267 * V_381 )
{
return true ;
}
static void F_67 ( struct V_377 * V_378 )
{
struct V_1 * V_2 = V_378 -> V_380 ;
F_64 ( V_2 ) ;
}
static void F_68 ( struct V_377 * V_378 )
{
struct V_1 * V_2 = V_378 -> V_380 ;
F_63 ( V_2 ) ;
}
static void F_69 ( struct V_377 * V_378 )
{
}
static enum V_382
F_70 ( struct V_383 * V_384 , bool V_385 )
{
struct V_1 * V_2 = F_71 ( V_384 , struct V_1 ,
V_384 ) ;
return F_10 ( V_2 , V_200 ) & V_348 ?
V_386 : V_387 ;
}
static int F_72 ( struct V_383 * V_384 )
{
struct V_1 * V_2 = F_71 ( V_384 , struct V_1 ,
V_384 ) ;
struct V_388 * V_388 ;
int V_203 ;
if ( ! V_2 -> V_389 )
return 0 ;
V_388 = F_73 ( V_384 , V_2 -> V_389 ) ;
if ( V_388 ) {
F_19 ( V_2 -> V_31 , L_11 ,
V_388 -> V_390 , V_388 -> V_391 ) ;
F_74 ( V_384 , V_388 ) ;
V_203 = F_75 ( V_384 , V_388 ) ;
F_76 ( V_388 ) ;
} else {
F_19 ( V_2 -> V_31 , L_12 ) ;
}
return 0 ;
}
static enum V_392
F_77 ( struct V_383 * V_384 ,
struct V_267 * V_268 )
{
struct V_1 * V_2 = F_71 ( V_384 ,
struct V_1 , V_384 ) ;
enum V_392 V_393 = V_394 ;
if ( V_2 -> V_172 -> V_395 )
V_393 = V_2 -> V_172 -> V_395 ( V_384 , V_268 ) ;
return V_393 ;
}
static struct V_396 * F_78 ( struct V_383
* V_384 )
{
struct V_1 * V_2 = F_71 ( V_384 , struct V_1 ,
V_384 ) ;
return V_2 -> V_397 ;
}
static void F_79 ( struct V_383 * V_384 )
{
F_80 ( V_384 ) ;
F_81 ( V_384 ) ;
}
static T_3 F_82 ( int V_398 , void * V_399 )
{
struct V_1 * V_2 = V_399 ;
T_1 V_400 ;
V_400 = F_10 ( V_2 , V_351 ) ;
if ( V_400 )
F_9 ( V_2 , ~ 0 , V_370 ) ;
return V_400 ? V_401 : V_402 ;
}
static T_3 F_83 ( int V_398 , void * V_399 )
{
struct V_1 * V_2 = V_399 ;
T_1 V_400 ;
T_1 V_403 ;
V_400 = F_10 ( V_2 , V_351 ) ;
V_403 = F_10 ( V_2 , V_404 ) ;
if ( V_400 & V_350 ) {
if ( V_403 & V_348 ) {
F_19 ( V_2 -> V_31 , L_13 ) ;
F_11 ( V_2 , 0 , V_348 , V_404 ) ;
F_63 ( V_2 ) ;
} else {
F_19 ( V_2 -> V_31 , L_14 ) ;
F_11 ( V_2 , V_348 , V_348 ,
V_404 ) ;
F_64 ( V_2 ) ;
}
F_84 ( V_2 -> V_384 . V_31 ) ;
}
F_9 ( V_2 , V_400 , V_351 ) ;
F_9 ( V_2 , ~ V_350 , V_370 ) ;
return V_405 ;
}
static int F_85 ( struct V_406 * V_407 , struct V_1 * V_2 )
{
struct V_396 * V_397 = V_2 -> V_397 ;
struct V_377 * V_378 ;
int V_203 ;
V_378 = F_86 ( V_407 -> V_31 , sizeof( * V_378 ) , V_408 ) ;
if ( ! V_378 ) {
F_87 ( L_15 ) ;
return - V_409 ;
}
V_2 -> V_378 = V_378 ;
V_378 -> V_380 = V_2 ;
V_378 -> V_410 = & V_411 ;
V_203 = F_88 ( V_407 , V_378 ) ;
if ( V_203 ) {
F_87 ( L_16 ) ;
return - V_179 ;
}
V_397 -> V_378 = V_378 ;
V_2 -> V_384 . V_412 = V_413 ;
F_89 ( & V_2 -> V_384 ,
& V_414 ) ;
F_90 ( V_407 , & V_2 -> V_384 , & V_415 ,
V_416 ) ;
V_2 -> V_384 . V_397 = V_397 ;
F_91 ( & V_2 -> V_384 , V_397 ) ;
return 0 ;
}
int F_92 ( struct V_417 * V_31 , struct V_417 * V_418 ,
void * V_8 , struct V_396 * V_397 ,
struct V_419 * V_420 , int V_398 ,
const struct V_421 * V_172 )
{
struct V_406 * V_407 = V_8 ;
struct V_422 * V_423 = V_31 -> V_424 ;
struct V_422 * V_425 ;
struct V_1 * V_2 ;
int V_203 ;
T_2 V_3 = 1 ;
V_2 = F_86 ( V_31 , sizeof( * V_2 ) , V_408 ) ;
if ( ! V_2 )
return - V_409 ;
V_2 -> V_172 = V_172 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_198 = V_172 -> V_198 ;
V_2 -> V_30 = 48000 ;
V_2 -> V_25 = 100 ;
V_2 -> V_397 = V_397 ;
F_93 ( V_423 , L_17 , & V_3 ) ;
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
F_48 ( V_31 , L_18 ) ;
return - V_179 ;
}
V_425 = F_94 ( V_423 , L_19 , 0 ) ;
if ( V_425 ) {
V_2 -> V_389 = F_95 ( V_425 ) ;
F_96 ( V_425 ) ;
if ( ! V_2 -> V_389 ) {
F_19 ( V_2 -> V_31 , L_20 ) ;
return - V_426 ;
}
} else {
F_19 ( V_2 -> V_31 , L_21 ) ;
}
V_2 -> V_5 = F_97 ( V_31 , V_420 ) ;
if ( F_98 ( V_2 -> V_5 ) )
return F_99 ( V_2 -> V_5 ) ;
V_2 -> V_427 = F_100 ( V_2 -> V_31 , L_22 ) ;
if ( F_98 ( V_2 -> V_427 ) ) {
V_203 = F_99 ( V_2 -> V_427 ) ;
F_48 ( V_2 -> V_31 , L_23 , V_203 ) ;
return V_203 ;
}
V_203 = F_101 ( V_2 -> V_427 ) ;
if ( V_203 ) {
F_48 ( V_2 -> V_31 , L_24 , V_203 ) ;
return V_203 ;
}
V_2 -> V_428 = F_100 ( V_2 -> V_31 , L_25 ) ;
if ( F_98 ( V_2 -> V_428 ) ) {
V_203 = F_99 ( V_2 -> V_428 ) ;
F_48 ( V_2 -> V_31 , L_26 , V_203 ) ;
goto V_429;
}
V_203 = F_101 ( V_2 -> V_428 ) ;
if ( V_203 ) {
F_48 ( V_2 -> V_31 , L_27 , V_203 ) ;
goto V_429;
}
F_102 ( V_31 ,
L_28 ,
F_10 ( V_2 , V_430 ) ,
F_10 ( V_2 , V_431 ) ,
F_10 ( V_2 , V_432 ) ,
F_10 ( V_2 , V_433 ) ) ;
F_62 ( V_2 ) ;
V_203 = F_103 ( V_31 , V_398 , F_82 ,
F_83 , V_434 ,
F_104 ( V_31 ) , V_2 ) ;
if ( V_203 )
goto V_435;
F_20 ( V_2 ) ;
F_9 ( V_2 , V_348 , V_404 ) ;
F_9 ( V_2 , V_350 , V_351 ) ;
V_203 = F_61 ( V_2 ) ;
if ( V_203 )
goto V_435;
V_203 = F_85 ( V_407 , V_2 ) ;
if ( V_203 )
goto V_435;
F_9 ( V_2 , ~ V_350 , V_370 ) ;
F_105 ( V_31 , V_2 ) ;
return 0 ;
V_435:
F_106 ( V_2 -> V_428 ) ;
V_429:
F_106 ( V_2 -> V_427 ) ;
return V_203 ;
}
void F_107 ( struct V_417 * V_31 , struct V_417 * V_418 , void * V_8 )
{
struct V_1 * V_2 = F_108 ( V_31 ) ;
F_9 ( V_2 , ~ 0 , V_370 ) ;
V_2 -> V_384 . V_410 -> V_436 ( & V_2 -> V_384 ) ;
V_2 -> V_397 -> V_410 -> V_436 ( V_2 -> V_397 ) ;
F_106 ( V_2 -> V_428 ) ;
F_106 ( V_2 -> V_427 ) ;
F_109 ( V_2 -> V_389 ) ;
}
