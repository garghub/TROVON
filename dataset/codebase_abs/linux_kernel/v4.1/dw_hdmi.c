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
static unsigned int F_14 ( unsigned int V_23 , unsigned long V_24 ,
unsigned int V_25 )
{
unsigned int V_13 = ( 128 * V_23 ) / 1000 ;
switch ( V_23 ) {
case 32000 :
if ( V_24 == 25170000 )
V_13 = ( V_25 == 150 ) ? 9152 : 4576 ;
else if ( V_24 == 27020000 )
V_13 = ( V_25 == 150 ) ? 8192 : 4096 ;
else if ( V_24 == 74170000 || V_24 == 148350000 )
V_13 = 11648 ;
else
V_13 = 4096 ;
break;
case 44100 :
if ( V_24 == 25170000 )
V_13 = 7007 ;
else if ( V_24 == 74170000 )
V_13 = 17836 ;
else if ( V_24 == 148350000 )
V_13 = ( V_25 == 150 ) ? 17836 : 8918 ;
else
V_13 = 6272 ;
break;
case 48000 :
if ( V_24 == 25170000 )
V_13 = ( V_25 == 150 ) ? 9152 : 6864 ;
else if ( V_24 == 27020000 )
V_13 = ( V_25 == 150 ) ? 8192 : 6144 ;
else if ( V_24 == 74170000 )
V_13 = 11648 ;
else if ( V_24 == 148350000 )
V_13 = ( V_25 == 150 ) ? 11648 : 5824 ;
else
V_13 = 6144 ;
break;
case 88200 :
V_13 = F_14 ( 44100 , V_24 , V_25 ) * 2 ;
break;
case 96000 :
V_13 = F_14 ( 48000 , V_24 , V_25 ) * 2 ;
break;
case 176400 :
V_13 = F_14 ( 44100 , V_24 , V_25 ) * 4 ;
break;
case 192000 :
V_13 = F_14 ( 48000 , V_24 , V_25 ) * 4 ;
break;
default:
break;
}
return V_13 ;
}
static unsigned int F_15 ( unsigned int V_23 , unsigned long V_24 ,
unsigned int V_25 )
{
unsigned int V_12 = 0 ;
F_16 ( L_1 , V_26 , V_23 ,
V_24 , V_25 ) ;
switch ( V_23 ) {
case 32000 :
if ( V_24 == 297000000 ) {
V_12 = 222750 ;
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
V_12 = V_24 / 1000 ;
break;
case 297000000 :
V_12 = 247500 ;
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
V_12 = 28000 ;
break;
case 27000000 :
V_12 = 30000 ;
break;
case 54000000 :
V_12 = 60000 ;
break;
case 74250000 :
V_12 = 82500 ;
break;
case 148500000 :
V_12 = 165000 ;
break;
case 297000000 :
V_12 = 247500 ;
break;
default:
break;
}
break;
default:
break;
}
if ( V_25 == 100 )
return V_12 ;
return ( V_12 * V_25 ) / 100 ;
}
static void F_17 ( struct V_1 * V_2 ,
unsigned long V_24 )
{
unsigned int V_27 , V_28 ;
V_27 = F_14 ( V_2 -> V_29 , V_24 ,
V_2 -> V_25 ) ;
V_28 = F_15 ( V_2 -> V_29 , V_24 ,
V_2 -> V_25 ) ;
if ( ! V_28 ) {
F_18 ( V_2 -> V_30 , L_2 ,
V_26 , V_24 ) ;
return;
}
F_18 ( V_2 -> V_30 , L_3 ,
V_26 , V_2 -> V_29 , V_2 -> V_25 ,
V_24 , V_27 , V_28 ) ;
F_13 ( V_2 , V_28 , V_27 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_20 ( & V_2 -> V_31 ) ;
F_17 ( V_2 , 74250000 ) ;
F_21 ( & V_2 -> V_31 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_20 ( & V_2 -> V_31 ) ;
F_17 ( V_2 , V_2 -> V_32 . V_33 . V_34 ) ;
F_21 ( & V_2 -> V_31 ) ;
}
static void F_23 ( struct V_1 * V_2 )
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
static int F_24 ( struct V_1 * V_2 )
{
return V_2 -> V_32 . V_36 != V_2 -> V_32 . V_55 ;
}
static int F_25 ( struct V_1 * V_2 )
{
if ( V_2 -> V_32 . V_55 != V_40 )
return 0 ;
if ( V_2 -> V_32 . V_36 == V_37 ||
V_2 -> V_32 . V_36 == V_39 )
return 1 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
if ( V_2 -> V_32 . V_36 != V_40 )
return 0 ;
if ( V_2 -> V_32 . V_55 == V_37 ||
V_2 -> V_32 . V_55 == V_39 )
return 1 ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
const F_28 ( * V_56 ) [ 3 ] [ 4 ] = & V_57 ;
unsigned V_58 ;
T_2 V_59 = 1 ;
if ( F_24 ( V_2 ) ) {
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
for ( V_58 = 0 ; V_58 < F_29 ( V_57 [ 0 ] ) ; V_58 ++ ) {
F_28 V_66 = ( * V_56 ) [ 0 ] [ V_58 ] ;
F_28 V_67 = ( * V_56 ) [ 1 ] [ V_58 ] ;
F_28 V_68 = ( * V_56 ) [ 2 ] [ V_58 ] ;
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
static void F_30 ( struct V_1 * V_2 )
{
int V_77 = 0 ;
int V_78 = V_79 ;
int V_80 = 0 ;
if ( F_26 ( V_2 ) )
V_78 = V_81 ;
else if ( F_25 ( V_2 ) )
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
F_27 ( V_2 ) ;
}
static void F_31 ( struct V_1 * V_2 )
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
static inline void F_32 ( struct V_1 * V_2 ,
unsigned char V_132 )
{
F_11 ( V_2 , V_132 << V_133 ,
V_134 , V_135 ) ;
}
static inline void F_33 ( struct V_1 * V_2 ,
unsigned char V_132 )
{
F_11 ( V_2 , V_132 << V_136 ,
V_137 , V_135 ) ;
}
static inline void F_34 ( struct V_1 * V_2 ,
unsigned char V_132 )
{
F_11 ( V_2 , V_132 << V_138 ,
V_139 , V_135 ) ;
}
static inline void F_35 ( struct V_1 * V_2 ,
unsigned char V_132 )
{
F_9 ( V_2 , V_132 , V_140 ) ;
}
static inline void F_36 ( struct V_1 * V_2 ,
unsigned char V_132 )
{
F_9 ( V_2 , V_132 , V_141 ) ;
}
static bool F_37 ( struct V_1 * V_2 , int V_142 )
{
T_2 V_3 ;
while ( ( V_3 = F_10 ( V_2 , V_143 ) & 0x3 ) == 0 ) {
if ( V_142 -- == 0 )
return false ;
F_38 ( 1000 ) ;
}
F_9 ( V_2 , V_3 , V_143 ) ;
return true ;
}
static void F_39 ( struct V_1 * V_2 , unsigned short V_8 ,
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
F_37 ( V_2 , 1000 ) ;
}
static int F_40 ( struct V_1 * V_2 , unsigned short V_8 ,
unsigned char V_144 )
{
F_39 ( V_2 , V_8 , V_144 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 , T_1 V_150 )
{
F_12 ( V_2 , V_150 , V_151 ,
V_152 ,
V_153 ) ;
}
static void F_42 ( struct V_1 * V_2 , T_1 V_150 )
{
F_12 ( V_2 , V_150 , V_151 ,
V_154 ,
V_155 ) ;
}
static void F_43 ( struct V_1 * V_2 , T_1 V_150 )
{
F_12 ( V_2 , V_150 , V_151 ,
V_156 ,
V_157 ) ;
}
static void F_44 ( struct V_1 * V_2 , T_1 V_150 )
{
F_12 ( V_2 , V_150 , V_151 ,
V_158 ,
V_159 ) ;
}
static void F_45 ( struct V_1 * V_2 , T_1 V_150 )
{
F_12 ( V_2 , V_150 , V_151 ,
V_160 ,
V_161 ) ;
}
static void F_46 ( struct V_1 * V_2 , T_1 V_150 )
{
F_12 ( V_2 , V_150 , V_151 ,
V_162 ,
V_163 ) ;
}
static void F_47 ( struct V_1 * V_2 , T_1 V_150 )
{
F_12 ( V_2 , V_150 , V_151 ,
V_164 ,
V_165 ) ;
}
static int F_48 ( struct V_1 * V_2 , unsigned char V_166 ,
unsigned char V_167 , int V_168 )
{
unsigned V_169 , V_58 ;
T_1 V_3 , V_142 ;
const struct V_170 * V_171 = V_2 -> V_171 ;
const struct V_172 * V_173 = V_171 -> V_174 ;
const struct V_175 * V_176 = V_171 -> V_177 ;
const struct V_178 * V_179 = V_171 -> V_179 ;
if ( V_166 )
return - V_180 ;
switch ( V_167 ) {
case 0 :
case 8 :
V_169 = V_181 ;
break;
case 10 :
V_169 = V_182 ;
break;
case 12 :
V_169 = V_183 ;
break;
default:
return - V_180 ;
}
if ( V_168 )
V_3 = V_184 ;
else
V_3 = V_185 ;
F_9 ( V_2 , V_3 , V_186 ) ;
F_45 ( V_2 , 0 ) ;
F_44 ( V_2 , 1 ) ;
F_9 ( V_2 , V_187 , V_188 ) ;
F_9 ( V_2 , V_189 , V_188 ) ;
F_9 ( V_2 , V_190 , V_191 ) ;
F_32 ( V_2 , 1 ) ;
F_9 ( V_2 , V_192 ,
V_193 ) ;
F_32 ( V_2 , 0 ) ;
for ( V_58 = 0 ; V_173 [ V_58 ] . V_34 != ( ~ 0UL ) ; V_58 ++ )
if ( V_2 -> V_32 . V_33 . V_34 <=
V_173 [ V_58 ] . V_34 )
break;
F_40 ( V_2 , V_173 [ V_58 ] . V_167 [ V_169 ] . V_194 , 0x06 ) ;
F_40 ( V_2 , V_173 [ V_58 ] . V_167 [ V_169 ] . V_195 , 0x15 ) ;
for ( V_58 = 0 ; V_176 [ V_58 ] . V_34 != ( ~ 0UL ) ; V_58 ++ )
if ( V_2 -> V_32 . V_33 . V_34 <=
V_176 [ V_58 ] . V_34 )
break;
if ( V_176 [ V_58 ] . V_34 == ( ~ 0UL ) ) {
F_49 ( V_2 -> V_30 , L_4 ,
V_2 -> V_32 . V_33 . V_34 ) ;
return - V_180 ;
}
F_40 ( V_2 , V_176 [ V_58 ] . V_196 [ V_169 ] , 0x10 ) ;
F_40 ( V_2 , 0x0000 , 0x13 ) ;
F_40 ( V_2 , 0x0006 , 0x17 ) ;
for ( V_58 = 0 ; V_179 [ V_58 ] . V_34 != ( ~ 0UL ) ; V_58 ++ )
if ( V_2 -> V_32 . V_33 . V_34 <=
V_179 [ V_58 ] . V_34 )
break;
F_40 ( V_2 , V_179 [ V_58 ] . V_197 , 0x19 ) ;
F_40 ( V_2 , V_179 [ V_58 ] . V_198 , 0x09 ) ;
F_40 ( V_2 , V_179 [ V_58 ] . V_199 , 0x0E ) ;
F_40 ( V_2 , 0x8000 , 0x05 ) ;
F_41 ( V_2 , 1 ) ;
F_42 ( V_2 , 0 ) ;
F_42 ( V_2 , 1 ) ;
F_45 ( V_2 , 1 ) ;
F_44 ( V_2 , 0 ) ;
if ( V_2 -> V_200 == V_201 )
F_43 ( V_2 , 1 ) ;
V_142 = 5 ;
do {
V_3 = F_10 ( V_2 , V_202 ) & V_203 ;
if ( ! V_3 )
break;
if ( V_142 == 0 ) {
F_49 ( V_2 -> V_30 , L_5 ) ;
return - V_204 ;
}
F_38 ( 1000 ) ;
V_142 -- ;
} while ( 1 );
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
int V_58 , V_205 ;
bool V_168 = false ;
V_168 = ( F_24 ( V_2 ) &&
! V_2 -> V_32 . V_33 . V_206 ) ;
for ( V_58 = 0 ; V_58 < 2 ; V_58 ++ ) {
F_46 ( V_2 , 1 ) ;
F_47 ( V_2 , 0 ) ;
F_42 ( V_2 , 0 ) ;
F_41 ( V_2 , 0 ) ;
V_205 = F_48 ( V_2 , 0 , 8 , V_168 ) ;
if ( V_205 )
return V_205 ;
}
V_2 -> V_207 = true ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 )
{
T_1 V_208 ;
if ( V_2 -> V_32 . V_33 . V_209 )
V_208 = V_210 ;
else
V_208 = V_211 ;
F_11 ( V_2 , V_212 ,
V_213 , V_214 ) ;
F_11 ( V_2 , V_208 , V_215 , V_216 ) ;
F_11 ( V_2 , V_217 ,
V_218 , V_219 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
T_1 V_3 , V_220 , V_221 ;
T_1 V_222 , V_223 , V_60 , V_224 ;
bool V_225 ;
V_225 = false ;
if ( V_2 -> V_32 . V_55 == V_39 )
V_220 = V_226 ;
else if ( V_2 -> V_32 . V_55 == V_40 )
V_220 = V_227 ;
else
V_220 = V_228 ;
V_221 = V_229 ;
V_3 = V_220 | V_221 |
V_230 |
V_231 ;
F_9 ( V_2 , V_3 , V_232 ) ;
if ( V_225 ) {
V_222 = V_233 ;
V_223 = V_234 ;
} else {
V_222 = V_235 ;
V_223 = V_236 ;
}
if ( V_2 -> V_32 . V_55 == V_237 ) {
V_60 = V_238 ;
if ( V_2 -> V_32 . V_60 == V_61 )
V_224 =
V_239 ;
else
V_224 =
V_240 ;
} else if ( V_2 -> V_32 . V_55 != V_37 ) {
if ( V_2 -> V_32 . V_60 == V_61 )
V_60 = V_241 ;
else
V_60 = V_242 ;
V_224 = V_239 ;
} else {
V_60 = V_243 ;
V_224 = V_239 ;
}
V_3 = V_60 | V_223 | V_222 ;
F_9 ( V_2 , V_3 , V_244 ) ;
V_3 = V_245 | V_224 |
V_246 |
V_247 ;
F_9 ( V_2 , V_3 , V_248 ) ;
F_9 ( V_2 , V_2 -> V_249 , V_250 ) ;
V_3 = ( ( ( V_2 -> V_32 . V_33 . V_251 + 1 ) <<
V_252 ) &
V_253 ) |
( ( V_2 -> V_32 . V_33 . V_254 <<
V_255 ) &
V_256 ) ;
F_9 ( V_2 , V_3 , V_257 ) ;
V_3 = V_258 |
V_259 ;
F_9 ( V_2 , V_3 , V_260 ) ;
F_9 ( V_2 , 0 , V_261 ) ;
F_9 ( V_2 , 0 , V_262 ) ;
F_9 ( V_2 , 0 , V_263 ) ;
F_9 ( V_2 , 0 , V_264 ) ;
F_9 ( V_2 , 0 , V_265 ) ;
F_9 ( V_2 , 0 , V_266 ) ;
F_9 ( V_2 , 0 , V_267 ) ;
F_9 ( V_2 , 0 , V_268 ) ;
}
static void F_53 ( struct V_1 * V_2 ,
const struct V_269 * V_270 )
{
T_1 V_271 ;
struct V_272 * V_273 = & V_2 -> V_32 . V_33 ;
int V_274 , V_275 , V_276 , V_277 , V_278 , V_279 ;
V_273 -> V_280 = ! ! ( V_270 -> V_281 & V_282 ) ;
V_273 -> V_283 = ! ! ( V_270 -> V_281 & V_284 ) ;
V_273 -> V_285 = ! ! ( V_270 -> V_281 & V_286 ) ;
V_273 -> V_34 = V_270 -> clock * 1000 ;
F_18 ( V_2 -> V_30 , L_6 , V_273 -> V_34 ) ;
V_271 = ( V_2 -> V_32 . V_287 ?
V_288 :
V_289 ) ;
V_271 |= ( V_273 -> V_283 ?
V_290 :
V_291 ) ;
V_271 |= ( V_273 -> V_280 ?
V_292 :
V_293 ) ;
V_271 |= ( V_273 -> V_209 ?
V_294 :
V_295 ) ;
if ( V_2 -> V_249 == 39 )
V_271 |= V_296 ;
else
V_271 |= ( V_273 -> V_285 ?
V_296 :
V_297 ) ;
V_271 |= ( V_273 -> V_285 ?
V_298 :
V_299 ) ;
V_271 |= ( V_273 -> V_206 ?
V_300 :
V_301 ) ;
F_9 ( V_2 , V_271 , V_302 ) ;
F_9 ( V_2 , V_270 -> V_303 >> 8 , V_304 ) ;
F_9 ( V_2 , V_270 -> V_303 , V_305 ) ;
F_9 ( V_2 , V_270 -> V_306 >> 8 , V_307 ) ;
F_9 ( V_2 , V_270 -> V_306 , V_308 ) ;
V_274 = V_270 -> V_309 - V_270 -> V_303 ;
F_9 ( V_2 , V_274 >> 8 , V_310 ) ;
F_9 ( V_2 , V_274 , V_311 ) ;
V_275 = V_270 -> V_312 - V_270 -> V_306 ;
F_9 ( V_2 , V_275 , V_313 ) ;
V_276 = V_270 -> V_314 - V_270 -> V_303 ;
F_9 ( V_2 , V_276 >> 8 , V_315 ) ;
F_9 ( V_2 , V_276 , V_316 ) ;
V_277 = V_270 -> V_317 - V_270 -> V_306 ;
F_9 ( V_2 , V_277 , V_318 ) ;
V_278 = V_270 -> V_319 - V_270 -> V_314 ;
F_9 ( V_2 , V_278 >> 8 , V_320 ) ;
F_9 ( V_2 , V_278 , V_321 ) ;
V_279 = V_270 -> V_322 - V_270 -> V_317 ;
F_9 ( V_2 , V_279 , V_323 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_207 )
return;
F_42 ( V_2 , 0 ) ;
F_41 ( V_2 , 0 ) ;
V_2 -> V_207 = false ;
}
static void F_55 ( struct V_1 * V_2 )
{
T_1 V_324 ;
F_9 ( V_2 , 12 , V_325 ) ;
F_9 ( V_2 , 32 , V_326 ) ;
F_9 ( V_2 , 1 , V_327 ) ;
F_9 ( V_2 , 0x0B , V_328 ) ;
F_9 ( V_2 , 0x16 , V_329 ) ;
F_9 ( V_2 , 0x21 , V_330 ) ;
V_324 = 0x7F ;
V_324 &= ~ V_331 ;
F_9 ( V_2 , V_324 , V_332 ) ;
V_324 &= ~ V_333 ;
F_9 ( V_2 , V_324 , V_332 ) ;
if ( F_24 ( V_2 ) ) {
V_324 &= ~ V_334 ;
F_9 ( V_2 , V_324 , V_332 ) ;
}
}
static void F_56 ( struct V_1 * V_2 )
{
F_11 ( V_2 , 0 , V_335 , V_332 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
int V_336 ;
T_1 V_3 ;
F_9 ( V_2 , ( T_1 ) ~ V_337 , V_338 ) ;
V_3 = F_10 ( V_2 , V_302 ) ;
if ( V_2 -> V_200 == V_339 ) {
F_9 ( V_2 , V_3 , V_302 ) ;
return;
}
for ( V_336 = 0 ; V_336 < 4 ; V_336 ++ )
F_9 ( V_2 , V_3 , V_302 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
F_9 ( V_2 , 0 , V_340 ) ;
F_9 ( V_2 , 0 , V_341 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_342 ,
V_341 ) ;
}
static int F_60 ( struct V_1 * V_2 , struct V_269 * V_270 )
{
int V_205 ;
F_59 ( V_2 ) ;
V_2 -> V_249 = F_61 ( V_270 ) ;
if ( ! V_2 -> V_249 ) {
F_18 ( V_2 -> V_30 , L_7 ) ;
V_2 -> V_32 . V_33 . V_206 = true ;
} else {
F_18 ( V_2 -> V_30 , L_8 , V_2 -> V_249 ) ;
V_2 -> V_32 . V_33 . V_206 = false ;
}
if ( ( V_2 -> V_249 == 6 ) || ( V_2 -> V_249 == 7 ) ||
( V_2 -> V_249 == 21 ) || ( V_2 -> V_249 == 22 ) ||
( V_2 -> V_249 == 2 ) || ( V_2 -> V_249 == 3 ) ||
( V_2 -> V_249 == 17 ) || ( V_2 -> V_249 == 18 ) )
V_2 -> V_32 . V_60 = V_61 ;
else
V_2 -> V_32 . V_60 = V_343 ;
if ( ( V_2 -> V_249 == 10 ) || ( V_2 -> V_249 == 11 ) ||
( V_2 -> V_249 == 12 ) || ( V_2 -> V_249 == 13 ) ||
( V_2 -> V_249 == 14 ) || ( V_2 -> V_249 == 15 ) ||
( V_2 -> V_249 == 25 ) || ( V_2 -> V_249 == 26 ) ||
( V_2 -> V_249 == 27 ) || ( V_2 -> V_249 == 28 ) ||
( V_2 -> V_249 == 29 ) || ( V_2 -> V_249 == 30 ) ||
( V_2 -> V_249 == 35 ) || ( V_2 -> V_249 == 36 ) ||
( V_2 -> V_249 == 37 ) || ( V_2 -> V_249 == 38 ) )
V_2 -> V_32 . V_33 . V_254 = 1 ;
else
V_2 -> V_32 . V_33 . V_254 = 0 ;
V_2 -> V_32 . V_33 . V_251 = 0 ;
V_2 -> V_32 . V_36 = V_37 ;
V_2 -> V_32 . V_55 = V_37 ;
V_2 -> V_32 . V_38 = 8 ;
V_2 -> V_32 . V_101 = 0 ;
V_2 -> V_32 . V_287 = 0 ;
V_2 -> V_32 . V_33 . V_209 = true ;
F_53 ( V_2 , V_270 ) ;
V_205 = F_50 ( V_2 ) ;
if ( V_205 )
return V_205 ;
F_55 ( V_2 ) ;
if ( V_2 -> V_32 . V_33 . V_206 ) {
F_18 ( V_2 -> V_30 , L_9 , V_26 ) ;
} else {
F_18 ( V_2 -> V_30 , L_10 , V_26 ) ;
F_22 ( V_2 ) ;
F_56 ( V_2 ) ;
F_52 ( V_2 ) ;
}
F_31 ( V_2 ) ;
F_30 ( V_2 ) ;
F_23 ( V_2 ) ;
F_51 ( V_2 ) ;
F_57 ( V_2 ) ;
if ( V_2 -> V_344 && ! V_2 -> V_32 . V_33 . V_206 )
F_58 ( V_2 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_345 ,
V_346 ) ;
F_9 ( V_2 , V_347 |
V_348 ,
V_349 ) ;
F_9 ( V_2 , ( T_1 ) ~ V_350 , V_351 ) ;
F_9 ( V_2 , V_352 , V_353 ) ;
return 0 ;
}
static void F_63 ( struct V_1 * V_2 )
{
T_1 V_354 ;
V_354 = F_10 ( V_2 , V_355 ) |
V_356 |
V_357 ;
F_9 ( V_2 , V_354 , V_355 ) ;
F_9 ( V_2 , 0xff , V_358 ) ;
F_9 ( V_2 , 0xff , V_359 ) ;
F_9 ( V_2 , 0xff , V_360 ) ;
F_9 ( V_2 , 0xff , V_340 ) ;
F_9 ( V_2 , 0xff , V_351 ) ;
F_9 ( V_2 , 0xff , V_346 ) ;
F_9 ( V_2 , 0xff , V_349 ) ;
F_9 ( V_2 , 0xff , V_361 ) ;
F_9 ( V_2 , 0xff , V_362 ) ;
F_9 ( V_2 , 0xff , V_363 ) ;
F_9 ( V_2 , 0xff , V_364 ) ;
F_9 ( V_2 , 0xff , V_365 ) ;
F_9 ( V_2 , 0xff , V_366 ) ;
F_9 ( V_2 , 0xff , V_367 ) ;
F_9 ( V_2 , 0xff , V_368 ) ;
F_9 ( V_2 , 0xff , V_369 ) ;
F_9 ( V_2 , 0xff , V_370 ) ;
F_9 ( V_2 , 0xff , V_341 ) ;
F_9 ( V_2 , 0xff , V_371 ) ;
F_9 ( V_2 , 0xff , V_372 ) ;
F_9 ( V_2 , 0xff , V_373 ) ;
F_9 ( V_2 , 0xff , V_374 ) ;
F_9 ( V_2 , 0xff , V_375 ) ;
F_9 ( V_2 , 0xff , V_376 ) ;
F_9 ( V_2 , 0xff , V_377 ) ;
V_354 &= ~ ( V_356 |
V_357 ) ;
F_9 ( V_2 , V_354 , V_355 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
F_60 ( V_2 , & V_2 -> V_378 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
F_54 ( V_2 ) ;
}
static void F_66 ( struct V_379 * V_380 ,
struct V_269 * V_381 ,
struct V_269 * V_270 )
{
struct V_1 * V_2 = V_380 -> V_382 ;
F_60 ( V_2 , V_270 ) ;
memcpy ( & V_2 -> V_378 , V_270 , sizeof( V_2 -> V_378 ) ) ;
}
static bool F_67 ( struct V_379 * V_380 ,
const struct V_269 * V_270 ,
struct V_269 * V_383 )
{
return true ;
}
static void F_68 ( struct V_379 * V_380 )
{
struct V_1 * V_2 = V_380 -> V_382 ;
F_65 ( V_2 ) ;
}
static void F_69 ( struct V_379 * V_380 )
{
struct V_1 * V_2 = V_380 -> V_382 ;
F_64 ( V_2 ) ;
}
static void F_70 ( struct V_379 * V_380 )
{
}
static enum V_384
F_71 ( struct V_385 * V_386 , bool V_387 )
{
struct V_1 * V_2 = F_72 ( V_386 , struct V_1 ,
V_386 ) ;
return F_10 ( V_2 , V_202 ) & V_350 ?
V_388 : V_389 ;
}
static int F_73 ( struct V_385 * V_386 )
{
struct V_1 * V_2 = F_72 ( V_386 , struct V_1 ,
V_386 ) ;
struct V_390 * V_390 ;
int V_205 ;
if ( ! V_2 -> V_391 )
return 0 ;
V_390 = F_74 ( V_386 , V_2 -> V_391 ) ;
if ( V_390 ) {
F_18 ( V_2 -> V_30 , L_11 ,
V_390 -> V_392 , V_390 -> V_393 ) ;
F_75 ( V_386 , V_390 ) ;
V_205 = F_76 ( V_386 , V_390 ) ;
F_77 ( V_390 ) ;
} else {
F_18 ( V_2 -> V_30 , L_12 ) ;
}
return 0 ;
}
static enum V_394
F_78 ( struct V_385 * V_386 ,
struct V_269 * V_270 )
{
struct V_1 * V_2 = F_72 ( V_386 ,
struct V_1 , V_386 ) ;
enum V_394 V_395 = V_396 ;
if ( V_2 -> V_171 -> V_397 )
V_395 = V_2 -> V_171 -> V_397 ( V_386 , V_270 ) ;
return V_395 ;
}
static struct V_398 * F_79 ( struct V_385
* V_386 )
{
struct V_1 * V_2 = F_72 ( V_386 , struct V_1 ,
V_386 ) ;
return V_2 -> V_399 ;
}
static void F_80 ( struct V_385 * V_386 )
{
F_81 ( V_386 ) ;
F_82 ( V_386 ) ;
}
static T_3 F_83 ( int V_400 , void * V_401 )
{
struct V_1 * V_2 = V_401 ;
T_1 V_402 ;
V_402 = F_10 ( V_2 , V_353 ) ;
if ( V_402 )
F_9 ( V_2 , ~ 0 , V_372 ) ;
return V_402 ? V_403 : V_404 ;
}
static T_3 F_84 ( int V_400 , void * V_401 )
{
struct V_1 * V_2 = V_401 ;
T_1 V_402 ;
T_1 V_405 ;
V_402 = F_10 ( V_2 , V_353 ) ;
V_405 = F_10 ( V_2 , V_406 ) ;
if ( V_402 & V_352 ) {
if ( V_405 & V_350 ) {
F_18 ( V_2 -> V_30 , L_13 ) ;
F_11 ( V_2 , 0 , V_350 , V_406 ) ;
F_64 ( V_2 ) ;
} else {
F_18 ( V_2 -> V_30 , L_14 ) ;
F_11 ( V_2 , V_350 , V_350 ,
V_406 ) ;
F_65 ( V_2 ) ;
}
F_85 ( V_2 -> V_386 . V_30 ) ;
}
F_9 ( V_2 , V_402 , V_353 ) ;
F_9 ( V_2 , ~ V_352 , V_372 ) ;
return V_407 ;
}
static int F_86 ( struct V_408 * V_409 , struct V_1 * V_2 )
{
struct V_398 * V_399 = V_2 -> V_399 ;
struct V_379 * V_380 ;
int V_205 ;
V_380 = F_87 ( V_409 -> V_30 , sizeof( * V_380 ) , V_410 ) ;
if ( ! V_380 ) {
F_88 ( L_15 ) ;
return - V_411 ;
}
V_2 -> V_380 = V_380 ;
V_380 -> V_382 = V_2 ;
V_380 -> V_412 = & V_413 ;
V_205 = F_89 ( V_409 , V_380 ) ;
if ( V_205 ) {
F_88 ( L_16 ) ;
return - V_180 ;
}
V_399 -> V_380 = V_380 ;
V_2 -> V_386 . V_414 = V_415 ;
F_90 ( & V_2 -> V_386 ,
& V_416 ) ;
F_91 ( V_409 , & V_2 -> V_386 , & V_417 ,
V_418 ) ;
V_2 -> V_386 . V_399 = V_399 ;
F_92 ( & V_2 -> V_386 , V_399 ) ;
return 0 ;
}
int F_93 ( struct V_419 * V_30 , struct V_419 * V_420 ,
void * V_8 , struct V_398 * V_399 ,
struct V_421 * V_422 , int V_400 ,
const struct V_170 * V_171 )
{
struct V_408 * V_409 = V_8 ;
struct V_423 * V_424 = V_30 -> V_425 ;
struct V_423 * V_426 ;
struct V_1 * V_2 ;
int V_205 ;
T_2 V_3 = 1 ;
V_2 = F_87 ( V_30 , sizeof( * V_2 ) , V_410 ) ;
if ( ! V_2 )
return - V_411 ;
V_2 -> V_171 = V_171 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_200 = V_171 -> V_200 ;
V_2 -> V_29 = 48000 ;
V_2 -> V_25 = 100 ;
V_2 -> V_399 = V_399 ;
F_94 ( & V_2 -> V_31 ) ;
F_95 ( V_424 , L_17 , & V_3 ) ;
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
F_49 ( V_30 , L_18 ) ;
return - V_180 ;
}
V_426 = F_96 ( V_424 , L_19 , 0 ) ;
if ( V_426 ) {
V_2 -> V_391 = F_97 ( V_426 ) ;
F_98 ( V_426 ) ;
if ( ! V_2 -> V_391 ) {
F_18 ( V_2 -> V_30 , L_20 ) ;
return - V_427 ;
}
} else {
F_18 ( V_2 -> V_30 , L_21 ) ;
}
V_2 -> V_5 = F_99 ( V_30 , V_422 ) ;
if ( F_100 ( V_2 -> V_5 ) )
return F_101 ( V_2 -> V_5 ) ;
V_2 -> V_428 = F_102 ( V_2 -> V_30 , L_22 ) ;
if ( F_100 ( V_2 -> V_428 ) ) {
V_205 = F_101 ( V_2 -> V_428 ) ;
F_49 ( V_2 -> V_30 , L_23 , V_205 ) ;
return V_205 ;
}
V_205 = F_103 ( V_2 -> V_428 ) ;
if ( V_205 ) {
F_49 ( V_2 -> V_30 , L_24 , V_205 ) ;
return V_205 ;
}
V_2 -> V_429 = F_102 ( V_2 -> V_30 , L_25 ) ;
if ( F_100 ( V_2 -> V_429 ) ) {
V_205 = F_101 ( V_2 -> V_429 ) ;
F_49 ( V_2 -> V_30 , L_26 , V_205 ) ;
goto V_430;
}
V_205 = F_103 ( V_2 -> V_429 ) ;
if ( V_205 ) {
F_49 ( V_2 -> V_30 , L_27 , V_205 ) ;
goto V_430;
}
F_104 ( V_30 ,
L_28 ,
F_10 ( V_2 , V_431 ) ,
F_10 ( V_2 , V_432 ) ,
F_10 ( V_2 , V_433 ) ,
F_10 ( V_2 , V_434 ) ) ;
F_63 ( V_2 ) ;
V_205 = F_105 ( V_30 , V_400 , F_83 ,
F_84 , V_435 ,
F_106 ( V_30 ) , V_2 ) ;
if ( V_205 )
goto V_436;
F_19 ( V_2 ) ;
F_9 ( V_2 , V_350 , V_406 ) ;
F_9 ( V_2 , V_352 , V_353 ) ;
V_205 = F_62 ( V_2 ) ;
if ( V_205 )
goto V_436;
V_205 = F_86 ( V_409 , V_2 ) ;
if ( V_205 )
goto V_436;
F_9 ( V_2 , ~ V_352 , V_372 ) ;
F_107 ( V_30 , V_2 ) ;
return 0 ;
V_436:
F_108 ( V_2 -> V_429 ) ;
V_430:
F_108 ( V_2 -> V_428 ) ;
return V_205 ;
}
void F_109 ( struct V_419 * V_30 , struct V_419 * V_420 , void * V_8 )
{
struct V_1 * V_2 = F_110 ( V_30 ) ;
F_9 ( V_2 , ~ 0 , V_372 ) ;
V_2 -> V_386 . V_412 -> V_437 ( & V_2 -> V_386 ) ;
V_2 -> V_399 -> V_412 -> V_437 ( V_2 -> V_399 ) ;
F_108 ( V_2 -> V_429 ) ;
F_108 ( V_2 -> V_428 ) ;
F_111 ( V_2 -> V_391 ) ;
}
