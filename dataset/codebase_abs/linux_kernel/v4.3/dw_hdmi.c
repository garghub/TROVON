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
unsigned long V_24 , unsigned int V_27 , unsigned int V_25 )
{
unsigned int V_13 , V_12 ;
V_13 = F_14 ( V_27 , V_24 , V_25 ) ;
V_12 = F_15 ( V_27 , V_24 , V_25 ) ;
if ( ! V_12 ) {
F_18 ( V_2 -> V_28 ,
L_2 ,
V_26 , V_24 , V_27 ) ;
}
F_19 ( V_2 -> V_28 , L_3 ,
V_26 , V_27 , V_25 , V_24 , V_13 , V_12 ) ;
F_20 ( & V_2 -> V_29 ) ;
V_2 -> V_30 = V_13 ;
V_2 -> V_31 = V_12 ;
F_13 ( V_2 , V_12 , V_2 -> V_32 ? V_13 : 0 ) ;
F_21 ( & V_2 -> V_29 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_23 ( & V_2 -> V_33 ) ;
F_17 ( V_2 , 74250000 , V_2 -> V_27 ,
V_2 -> V_25 ) ;
F_24 ( & V_2 -> V_33 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_23 ( & V_2 -> V_33 ) ;
F_17 ( V_2 , V_2 -> V_34 . V_35 . V_36 ,
V_2 -> V_27 , V_2 -> V_25 ) ;
F_24 ( & V_2 -> V_33 ) ;
}
void F_26 ( struct V_1 * V_2 , unsigned int V_37 )
{
F_23 ( & V_2 -> V_33 ) ;
V_2 -> V_27 = V_37 ;
F_17 ( V_2 , V_2 -> V_34 . V_35 . V_36 ,
V_2 -> V_27 , V_2 -> V_25 ) ;
F_24 ( & V_2 -> V_33 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
unsigned long V_38 ;
F_28 ( & V_2 -> V_29 , V_38 ) ;
V_2 -> V_32 = true ;
F_13 ( V_2 , V_2 -> V_31 , V_2 -> V_30 ) ;
F_29 ( & V_2 -> V_29 , V_38 ) ;
}
void F_30 ( struct V_1 * V_2 )
{
unsigned long V_38 ;
F_28 ( & V_2 -> V_29 , V_38 ) ;
V_2 -> V_32 = false ;
F_13 ( V_2 , V_2 -> V_31 , 0 ) ;
F_29 ( & V_2 -> V_29 , V_38 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
int V_39 = 0 ;
T_1 V_3 ;
if ( V_2 -> V_34 . V_40 == V_41 ) {
if ( V_2 -> V_34 . V_42 == 8 )
V_39 = 0x01 ;
else if ( V_2 -> V_34 . V_42 == 10 )
V_39 = 0x03 ;
else if ( V_2 -> V_34 . V_42 == 12 )
V_39 = 0x05 ;
else if ( V_2 -> V_34 . V_42 == 16 )
V_39 = 0x07 ;
else
return;
} else if ( V_2 -> V_34 . V_40 == V_43 ) {
if ( V_2 -> V_34 . V_42 == 8 )
V_39 = 0x09 ;
else if ( V_2 -> V_34 . V_42 == 10 )
V_39 = 0x0B ;
else if ( V_2 -> V_34 . V_42 == 12 )
V_39 = 0x0D ;
else if ( V_2 -> V_34 . V_42 == 16 )
V_39 = 0x0F ;
else
return;
} else if ( V_2 -> V_34 . V_40 == V_44 ) {
if ( V_2 -> V_34 . V_42 == 8 )
V_39 = 0x16 ;
else if ( V_2 -> V_34 . V_42 == 10 )
V_39 = 0x14 ;
else if ( V_2 -> V_34 . V_42 == 12 )
V_39 = 0x12 ;
else
return;
}
V_3 = V_45 |
( ( V_39 << V_46 ) &
V_47 ) ;
F_9 ( V_2 , V_3 , V_48 ) ;
V_3 = V_49 |
V_50 |
V_51 ;
F_9 ( V_2 , V_3 , V_52 ) ;
F_9 ( V_2 , 0x0 , V_53 ) ;
F_9 ( V_2 , 0x0 , V_54 ) ;
F_9 ( V_2 , 0x0 , V_55 ) ;
F_9 ( V_2 , 0x0 , V_56 ) ;
F_9 ( V_2 , 0x0 , V_57 ) ;
F_9 ( V_2 , 0x0 , V_58 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
return V_2 -> V_34 . V_40 != V_2 -> V_34 . V_59 ;
}
static int F_33 ( struct V_1 * V_2 )
{
if ( V_2 -> V_34 . V_59 != V_44 )
return 0 ;
if ( V_2 -> V_34 . V_40 == V_41 ||
V_2 -> V_34 . V_40 == V_43 )
return 1 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
if ( V_2 -> V_34 . V_40 != V_44 )
return 0 ;
if ( V_2 -> V_34 . V_59 == V_41 ||
V_2 -> V_34 . V_59 == V_43 )
return 1 ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 )
{
const F_36 ( * V_60 ) [ 3 ] [ 4 ] = & V_61 ;
unsigned V_62 ;
T_2 V_63 = 1 ;
if ( F_32 ( V_2 ) ) {
if ( V_2 -> V_34 . V_59 == V_41 ) {
if ( V_2 -> V_34 . V_64 ==
V_65 )
V_60 = & V_66 ;
else
V_60 = & V_67 ;
} else if ( V_2 -> V_34 . V_40 == V_41 ) {
if ( V_2 -> V_34 . V_64 ==
V_65 )
V_60 = & V_68 ;
else
V_60 = & V_69 ;
V_63 = 0 ;
}
}
for ( V_62 = 0 ; V_62 < F_37 ( V_61 [ 0 ] ) ; V_62 ++ ) {
F_36 V_70 = ( * V_60 ) [ 0 ] [ V_62 ] ;
F_36 V_71 = ( * V_60 ) [ 1 ] [ V_62 ] ;
F_36 V_72 = ( * V_60 ) [ 2 ] [ V_62 ] ;
F_9 ( V_2 , V_70 & 0xff , V_73 + V_62 * 2 ) ;
F_9 ( V_2 , V_70 >> 8 , V_74 + V_62 * 2 ) ;
F_9 ( V_2 , V_71 & 0xff , V_75 + V_62 * 2 ) ;
F_9 ( V_2 , V_71 >> 8 , V_76 + V_62 * 2 ) ;
F_9 ( V_2 , V_72 & 0xff , V_77 + V_62 * 2 ) ;
F_9 ( V_2 , V_72 >> 8 , V_78 + V_62 * 2 ) ;
}
F_11 ( V_2 , V_63 , V_79 ,
V_80 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
int V_81 = 0 ;
int V_82 = V_83 ;
int V_84 = 0 ;
if ( F_34 ( V_2 ) )
V_82 = V_85 ;
else if ( F_33 ( V_2 ) )
V_84 = V_86 ;
if ( V_2 -> V_34 . V_42 == 8 )
V_81 = V_87 ;
else if ( V_2 -> V_34 . V_42 == 10 )
V_81 = V_88 ;
else if ( V_2 -> V_34 . V_42 == 12 )
V_81 = V_89 ;
else if ( V_2 -> V_34 . V_42 == 16 )
V_81 = V_90 ;
else
return;
F_9 ( V_2 , V_82 | V_84 , V_91 ) ;
F_11 ( V_2 , V_81 , V_92 ,
V_80 ) ;
F_35 ( V_2 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
unsigned int V_81 = 0 ;
unsigned int V_93 = V_94 ;
unsigned int V_95 = V_96 ;
struct V_97 * V_34 = & V_2 -> V_34 ;
T_1 V_3 , V_98 ;
if ( V_34 -> V_59 == V_41 ||
V_34 -> V_59 == V_43 ) {
if ( ! V_34 -> V_42 ) {
V_95 = V_99 ;
} else if ( V_34 -> V_42 == 8 ) {
V_81 = 4 ;
V_95 = V_99 ;
} else if ( V_34 -> V_42 == 10 ) {
V_81 = 5 ;
} else if ( V_34 -> V_42 == 12 ) {
V_81 = 6 ;
} else if ( V_34 -> V_42 == 16 ) {
V_81 = 7 ;
} else {
return;
}
} else if ( V_34 -> V_59 == V_44 ) {
if ( ! V_34 -> V_42 ||
V_34 -> V_42 == 8 )
V_93 = V_94 ;
else if ( V_34 -> V_42 == 10 )
V_93 = V_100 ;
else if ( V_34 -> V_42 == 12 )
V_93 = V_101 ;
else
return;
V_95 = V_102 ;
} else {
return;
}
V_3 = ( ( V_81 << V_103 ) &
V_104 ) |
( ( V_34 -> V_105 <<
V_106 ) &
V_107 ) ;
F_9 ( V_2 , V_3 , V_108 ) ;
F_11 ( V_2 , V_109 ,
V_110 , V_111 ) ;
if ( V_34 -> V_105 > 1 ) {
V_98 = V_112 |
V_113 ;
} else {
V_98 = V_114 |
V_115 ;
}
F_11 ( V_2 , V_98 ,
V_116 |
V_117 , V_118 ) ;
F_11 ( V_2 , 1 << V_119 ,
V_120 , V_111 ) ;
F_9 ( V_2 , V_93 , V_121 ) ;
if ( V_95 == V_96 ) {
V_98 = V_122 |
V_123 |
V_124 ;
} else if ( V_95 == V_102 ) {
V_98 = V_122 |
V_125 |
V_126 ;
} else if ( V_95 == V_99 ) {
V_98 = V_127 |
V_125 |
V_124 ;
} else {
return;
}
F_11 ( V_2 , V_98 ,
V_128 | V_129 |
V_130 , V_118 ) ;
F_11 ( V_2 , V_131 |
V_132 ,
V_133 |
V_134 , V_111 ) ;
F_11 ( V_2 , V_95 , V_135 ,
V_118 ) ;
}
static inline void F_40 ( struct V_1 * V_2 ,
unsigned char V_136 )
{
F_11 ( V_2 , V_136 << V_137 ,
V_138 , V_139 ) ;
}
static inline void F_41 ( struct V_1 * V_2 ,
unsigned char V_136 )
{
F_11 ( V_2 , V_136 << V_140 ,
V_141 , V_139 ) ;
}
static inline void F_42 ( struct V_1 * V_2 ,
unsigned char V_136 )
{
F_11 ( V_2 , V_136 << V_142 ,
V_143 , V_139 ) ;
}
static inline void F_43 ( struct V_1 * V_2 ,
unsigned char V_136 )
{
F_9 ( V_2 , V_136 , V_144 ) ;
}
static inline void F_44 ( struct V_1 * V_2 ,
unsigned char V_136 )
{
F_9 ( V_2 , V_136 , V_145 ) ;
}
static bool F_45 ( struct V_1 * V_2 , int V_146 )
{
T_2 V_3 ;
while ( ( V_3 = F_10 ( V_2 , V_147 ) & 0x3 ) == 0 ) {
if ( V_146 -- == 0 )
return false ;
F_46 ( 1000 ) ;
}
F_9 ( V_2 , V_3 , V_147 ) ;
return true ;
}
static void F_47 ( struct V_1 * V_2 , unsigned short V_8 ,
unsigned char V_148 )
{
F_9 ( V_2 , 0xFF , V_147 ) ;
F_9 ( V_2 , V_148 , V_149 ) ;
F_9 ( V_2 , ( unsigned char ) ( V_8 >> 8 ) ,
V_150 ) ;
F_9 ( V_2 , ( unsigned char ) ( V_8 >> 0 ) ,
V_151 ) ;
F_9 ( V_2 , V_152 ,
V_153 ) ;
F_45 ( V_2 , 1000 ) ;
}
static int F_48 ( struct V_1 * V_2 , unsigned short V_8 ,
unsigned char V_148 )
{
F_47 ( V_2 , V_8 , V_148 ) ;
return 0 ;
}
static void F_49 ( struct V_1 * V_2 , bool V_154 )
{
F_12 ( V_2 , ! V_154 , V_155 ,
V_156 ,
V_157 ) ;
}
static void F_50 ( struct V_1 * V_2 , T_1 V_154 )
{
F_12 ( V_2 , V_154 , V_155 ,
V_158 ,
V_159 ) ;
}
static void F_51 ( struct V_1 * V_2 , T_1 V_154 )
{
F_12 ( V_2 , V_154 , V_155 ,
V_160 ,
V_161 ) ;
}
static void F_52 ( struct V_1 * V_2 , T_1 V_154 )
{
F_12 ( V_2 , V_154 , V_155 ,
V_162 ,
V_163 ) ;
}
static void F_53 ( struct V_1 * V_2 , T_1 V_154 )
{
F_12 ( V_2 , V_154 , V_155 ,
V_164 ,
V_165 ) ;
}
static void F_54 ( struct V_1 * V_2 , T_1 V_154 )
{
F_12 ( V_2 , V_154 , V_155 ,
V_166 ,
V_167 ) ;
}
static void F_55 ( struct V_1 * V_2 , T_1 V_154 )
{
F_12 ( V_2 , V_154 , V_155 ,
V_168 ,
V_169 ) ;
}
static int F_56 ( struct V_1 * V_2 , unsigned char V_170 ,
unsigned char V_171 , int V_172 )
{
unsigned V_173 ;
T_1 V_3 , V_146 ;
const struct V_174 * V_175 = V_2 -> V_176 ;
const struct V_177 * V_178 = V_175 -> V_179 ;
const struct V_180 * V_181 = V_175 -> V_182 ;
const struct V_183 * V_184 = V_175 -> V_184 ;
if ( V_170 )
return - V_185 ;
switch ( V_171 ) {
case 0 :
case 8 :
V_173 = V_186 ;
break;
case 10 :
V_173 = V_187 ;
break;
case 12 :
V_173 = V_188 ;
break;
default:
return - V_185 ;
}
for (; V_178 -> V_36 != ~ 0UL ; V_178 ++ )
if ( V_2 -> V_34 . V_35 . V_36 <=
V_178 -> V_36 )
break;
for (; V_181 -> V_36 != ~ 0UL ; V_181 ++ )
if ( V_2 -> V_34 . V_35 . V_36 <=
V_181 -> V_36 )
break;
for (; V_184 -> V_36 != ~ 0UL ; V_184 ++ )
if ( V_2 -> V_34 . V_35 . V_36 <=
V_184 -> V_36 )
break;
if ( V_178 -> V_36 == ~ 0UL ||
V_181 -> V_36 == ~ 0UL ||
V_184 -> V_36 == ~ 0UL ) {
F_18 ( V_2 -> V_28 , L_4 ,
V_2 -> V_34 . V_35 . V_36 ) ;
return - V_185 ;
}
if ( V_172 )
V_3 = V_189 ;
else
V_3 = V_190 ;
F_9 ( V_2 , V_3 , V_191 ) ;
F_53 ( V_2 , 0 ) ;
F_52 ( V_2 , 1 ) ;
F_9 ( V_2 , V_192 , V_193 ) ;
F_9 ( V_2 , V_194 , V_193 ) ;
F_9 ( V_2 , V_195 , V_196 ) ;
F_40 ( V_2 , 1 ) ;
F_9 ( V_2 , V_197 ,
V_198 ) ;
F_40 ( V_2 , 0 ) ;
F_48 ( V_2 , V_178 -> V_171 [ V_173 ] . V_199 , 0x06 ) ;
F_48 ( V_2 , V_178 -> V_171 [ V_173 ] . V_200 , 0x15 ) ;
F_48 ( V_2 , V_181 -> V_201 [ V_173 ] , 0x10 ) ;
F_48 ( V_2 , 0x0000 , 0x13 ) ;
F_48 ( V_2 , 0x0006 , 0x17 ) ;
F_48 ( V_2 , V_184 -> V_202 , 0x19 ) ;
F_48 ( V_2 , V_184 -> V_203 , 0x09 ) ;
F_48 ( V_2 , V_184 -> V_204 , 0x0E ) ;
F_48 ( V_2 , 0x8000 , 0x05 ) ;
F_49 ( V_2 , false ) ;
F_50 ( V_2 , 0 ) ;
F_50 ( V_2 , 1 ) ;
F_53 ( V_2 , 1 ) ;
F_52 ( V_2 , 0 ) ;
if ( V_2 -> V_205 == V_206 )
F_51 ( V_2 , 1 ) ;
V_146 = 5 ;
do {
V_3 = F_10 ( V_2 , V_207 ) & V_208 ;
if ( ! V_3 )
break;
if ( V_146 == 0 ) {
F_18 ( V_2 -> V_28 , L_5 ) ;
return - V_209 ;
}
F_46 ( 1000 ) ;
V_146 -- ;
} while ( 1 );
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
int V_62 , V_210 ;
bool V_172 ;
V_172 = V_2 -> V_211 && F_32 ( V_2 ) ;
for ( V_62 = 0 ; V_62 < 2 ; V_62 ++ ) {
F_54 ( V_2 , 1 ) ;
F_55 ( V_2 , 0 ) ;
F_50 ( V_2 , 0 ) ;
F_49 ( V_2 , true ) ;
V_210 = F_56 ( V_2 , 0 , 8 , V_172 ) ;
if ( V_210 )
return V_210 ;
}
V_2 -> V_212 = true ;
return 0 ;
}
static void F_58 ( struct V_1 * V_2 )
{
T_1 V_213 ;
if ( V_2 -> V_34 . V_35 . V_214 )
V_213 = V_215 ;
else
V_213 = V_216 ;
F_11 ( V_2 , V_217 ,
V_218 , V_219 ) ;
F_11 ( V_2 , V_213 , V_220 , V_221 ) ;
F_11 ( V_2 , V_222 ,
V_223 , V_224 ) ;
}
static void F_59 ( struct V_1 * V_2 , struct V_225 * V_226 )
{
struct V_227 V_228 ;
T_1 V_3 ;
F_60 ( & V_228 , V_226 ) ;
if ( V_2 -> V_34 . V_59 == V_43 )
V_228 . V_229 = V_230 ;
else if ( V_2 -> V_34 . V_59 == V_44 )
V_228 . V_229 = V_231 ;
else
V_228 . V_229 = V_232 ;
if ( V_2 -> V_34 . V_59 == V_233 ) {
V_228 . V_64 = V_234 ;
if ( V_2 -> V_34 . V_64 == V_65 )
V_228 . V_235 =
V_236 ;
else
V_228 . V_235 =
V_237 ;
} else if ( V_2 -> V_34 . V_59 != V_41 ) {
V_228 . V_64 = V_2 -> V_34 . V_64 ;
V_228 . V_235 = V_236 ;
} else {
V_228 . V_64 = V_238 ;
V_228 . V_235 = V_236 ;
}
V_228 . V_239 = V_240 ;
V_3 = ( V_228 . V_229 & 3 ) << 4 | ( V_228 . V_239 & 0x3 ) ;
if ( V_228 . V_241 & 15 )
V_3 |= V_242 ;
if ( V_228 . V_243 || V_228 . V_244 )
V_3 |= V_245 ;
if ( V_228 . V_246 || V_228 . V_247 )
V_3 |= V_248 ;
F_9 ( V_2 , V_3 , V_249 ) ;
V_3 = ( ( V_228 . V_64 & 0x3 ) << 6 ) |
( ( V_228 . V_250 & 0x3 ) << 4 ) |
( V_228 . V_241 & 0xf ) ;
F_9 ( V_2 , V_3 , V_251 ) ;
V_3 = ( ( V_228 . V_235 & 0x7 ) << 4 ) |
( ( V_228 . V_252 & 0x3 ) << 2 ) |
( V_228 . V_253 & 0x3 ) ;
if ( V_228 . V_254 )
V_3 |= V_255 ;
F_9 ( V_2 , V_3 , V_256 ) ;
V_3 = V_228 . V_257 & 0x7f ;
F_9 ( V_2 , V_3 , V_258 ) ;
V_3 = ( ( ( V_2 -> V_34 . V_35 . V_259 + 1 ) <<
V_260 ) &
V_261 ) |
( ( V_2 -> V_34 . V_35 . V_262 <<
V_263 ) &
V_264 ) ;
F_9 ( V_2 , V_3 , V_265 ) ;
V_3 = ( ( V_228 . V_266 & 0x3 ) << 2 ) |
( V_228 . V_267 & 0x3 ) ;
F_9 ( V_2 , V_3 , V_268 ) ;
F_9 ( V_2 , V_228 . V_243 & 0xff , V_269 ) ;
F_9 ( V_2 , ( V_228 . V_243 >> 8 ) & 0xff , V_270 ) ;
F_9 ( V_2 , V_228 . V_244 & 0xff , V_271 ) ;
F_9 ( V_2 , ( V_228 . V_244 >> 8 ) & 0xff , V_272 ) ;
F_9 ( V_2 , V_228 . V_246 & 0xff , V_273 ) ;
F_9 ( V_2 , ( V_228 . V_246 >> 8 ) & 0xff , V_274 ) ;
F_9 ( V_2 , V_228 . V_247 & 0xff , V_275 ) ;
F_9 ( V_2 , ( V_228 . V_247 >> 8 ) & 0xff , V_276 ) ;
}
static void F_61 ( struct V_1 * V_2 ,
const struct V_225 * V_226 )
{
T_1 V_277 ;
struct V_278 * V_279 = & V_2 -> V_34 . V_35 ;
int V_280 , V_281 , V_282 , V_283 , V_284 , V_285 ;
V_279 -> V_36 = V_226 -> clock * 1000 ;
F_19 ( V_2 -> V_28 , L_6 , V_279 -> V_36 ) ;
V_277 = ( V_2 -> V_34 . V_286 ?
V_287 :
V_288 ) ;
V_277 |= V_226 -> V_38 & V_289 ?
V_290 :
V_291 ;
V_277 |= V_226 -> V_38 & V_292 ?
V_293 :
V_294 ;
V_277 |= ( V_279 -> V_214 ?
V_295 :
V_296 ) ;
if ( V_2 -> V_297 == 39 )
V_277 |= V_298 ;
else
V_277 |= V_226 -> V_38 & V_299 ?
V_298 :
V_300 ;
V_277 |= V_226 -> V_38 & V_299 ?
V_301 :
V_302 ;
V_277 |= V_2 -> V_211 ?
V_303 :
V_304 ;
F_9 ( V_2 , V_277 , V_305 ) ;
F_9 ( V_2 , V_226 -> V_306 >> 8 , V_307 ) ;
F_9 ( V_2 , V_226 -> V_306 , V_308 ) ;
F_9 ( V_2 , V_226 -> V_309 >> 8 , V_310 ) ;
F_9 ( V_2 , V_226 -> V_309 , V_311 ) ;
V_280 = V_226 -> V_312 - V_226 -> V_306 ;
F_9 ( V_2 , V_280 >> 8 , V_313 ) ;
F_9 ( V_2 , V_280 , V_314 ) ;
V_281 = V_226 -> V_315 - V_226 -> V_309 ;
F_9 ( V_2 , V_281 , V_316 ) ;
V_282 = V_226 -> V_317 - V_226 -> V_306 ;
F_9 ( V_2 , V_282 >> 8 , V_318 ) ;
F_9 ( V_2 , V_282 , V_319 ) ;
V_283 = V_226 -> V_320 - V_226 -> V_309 ;
F_9 ( V_2 , V_283 , V_321 ) ;
V_284 = V_226 -> V_322 - V_226 -> V_317 ;
F_9 ( V_2 , V_284 >> 8 , V_323 ) ;
F_9 ( V_2 , V_284 , V_324 ) ;
V_285 = V_226 -> V_325 - V_226 -> V_320 ;
F_9 ( V_2 , V_285 , V_326 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_212 )
return;
F_50 ( V_2 , 0 ) ;
F_49 ( V_2 , true ) ;
V_2 -> V_212 = false ;
}
static void F_63 ( struct V_1 * V_2 )
{
T_1 V_327 ;
F_9 ( V_2 , 12 , V_328 ) ;
F_9 ( V_2 , 32 , V_329 ) ;
F_9 ( V_2 , 1 , V_330 ) ;
F_9 ( V_2 , 0x0B , V_331 ) ;
F_9 ( V_2 , 0x16 , V_332 ) ;
F_9 ( V_2 , 0x21 , V_333 ) ;
V_327 = 0x7F ;
V_327 &= ~ V_334 ;
F_9 ( V_2 , V_327 , V_335 ) ;
V_327 &= ~ V_336 ;
F_9 ( V_2 , V_327 , V_335 ) ;
if ( F_32 ( V_2 ) ) {
V_327 &= ~ V_337 ;
F_9 ( V_2 , V_327 , V_335 ) ;
}
}
static void F_64 ( struct V_1 * V_2 )
{
F_11 ( V_2 , 0 , V_338 , V_335 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
int V_339 ;
T_1 V_3 ;
F_9 ( V_2 , ( T_1 ) ~ V_340 , V_341 ) ;
V_3 = F_10 ( V_2 , V_305 ) ;
if ( V_2 -> V_205 == V_342 ) {
F_9 ( V_2 , V_3 , V_305 ) ;
return;
}
for ( V_339 = 0 ; V_339 < 4 ; V_339 ++ )
F_9 ( V_2 , V_3 , V_305 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
F_9 ( V_2 , 0 , V_343 ) ;
F_9 ( V_2 , 0 , V_344 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_345 ,
V_344 ) ;
}
static int F_68 ( struct V_1 * V_2 , struct V_225 * V_226 )
{
int V_210 ;
F_67 ( V_2 ) ;
V_2 -> V_297 = F_69 ( V_226 ) ;
if ( ! V_2 -> V_297 ) {
F_19 ( V_2 -> V_28 , L_7 ) ;
} else {
F_19 ( V_2 -> V_28 , L_8 , V_2 -> V_297 ) ;
}
if ( ( V_2 -> V_297 == 6 ) || ( V_2 -> V_297 == 7 ) ||
( V_2 -> V_297 == 21 ) || ( V_2 -> V_297 == 22 ) ||
( V_2 -> V_297 == 2 ) || ( V_2 -> V_297 == 3 ) ||
( V_2 -> V_297 == 17 ) || ( V_2 -> V_297 == 18 ) )
V_2 -> V_34 . V_64 = V_65 ;
else
V_2 -> V_34 . V_64 = V_346 ;
V_2 -> V_34 . V_35 . V_262 = 0 ;
V_2 -> V_34 . V_35 . V_259 = 0 ;
V_2 -> V_34 . V_40 = V_41 ;
V_2 -> V_34 . V_59 = V_41 ;
V_2 -> V_34 . V_42 = 8 ;
V_2 -> V_34 . V_105 = 0 ;
V_2 -> V_34 . V_286 = 0 ;
V_2 -> V_34 . V_35 . V_214 = true ;
F_61 ( V_2 , V_226 ) ;
V_210 = F_57 ( V_2 ) ;
if ( V_210 )
return V_210 ;
F_63 ( V_2 ) ;
if ( V_2 -> V_347 ) {
F_19 ( V_2 -> V_28 , L_9 ) ;
F_25 ( V_2 ) ;
F_64 ( V_2 ) ;
}
if ( V_2 -> V_211 ) {
F_19 ( V_2 -> V_28 , L_10 , V_26 ) ;
F_59 ( V_2 , V_226 ) ;
} else {
F_19 ( V_2 -> V_28 , L_11 , V_26 ) ;
}
F_39 ( V_2 ) ;
F_38 ( V_2 ) ;
F_31 ( V_2 ) ;
F_58 ( V_2 ) ;
F_65 ( V_2 ) ;
if ( V_2 -> V_348 && V_2 -> V_211 )
F_66 ( V_2 ) ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_349 ,
V_350 ) ;
F_9 ( V_2 , V_351 |
V_352 ,
V_353 ) ;
F_9 ( V_2 , ( T_1 ) ~ V_354 , V_355 ) ;
F_9 ( V_2 , V_356 , V_357 ) ;
return 0 ;
}
static void F_71 ( struct V_1 * V_2 )
{
T_1 V_358 ;
V_358 = F_10 ( V_2 , V_359 ) |
V_360 |
V_361 ;
F_9 ( V_2 , V_358 , V_359 ) ;
F_9 ( V_2 , 0xff , V_362 ) ;
F_9 ( V_2 , 0xff , V_363 ) ;
F_9 ( V_2 , 0xff , V_364 ) ;
F_9 ( V_2 , 0xff , V_343 ) ;
F_9 ( V_2 , 0xff , V_355 ) ;
F_9 ( V_2 , 0xff , V_350 ) ;
F_9 ( V_2 , 0xff , V_353 ) ;
F_9 ( V_2 , 0xff , V_365 ) ;
F_9 ( V_2 , 0xff , V_366 ) ;
F_9 ( V_2 , 0xff , V_367 ) ;
F_9 ( V_2 , 0xff , V_368 ) ;
F_9 ( V_2 , 0xff , V_369 ) ;
F_9 ( V_2 , 0xff , V_370 ) ;
F_9 ( V_2 , 0xff , V_371 ) ;
F_9 ( V_2 , 0xff , V_372 ) ;
F_9 ( V_2 , 0xff , V_373 ) ;
F_9 ( V_2 , 0xff , V_374 ) ;
F_9 ( V_2 , 0xff , V_344 ) ;
F_9 ( V_2 , 0xff , V_375 ) ;
F_9 ( V_2 , 0xff , V_376 ) ;
F_9 ( V_2 , 0xff , V_377 ) ;
F_9 ( V_2 , 0xff , V_378 ) ;
F_9 ( V_2 , 0xff , V_379 ) ;
F_9 ( V_2 , 0xff , V_380 ) ;
F_9 ( V_2 , 0xff , V_381 ) ;
V_358 &= ~ ( V_360 |
V_361 ) ;
F_9 ( V_2 , V_358 , V_359 ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
F_68 ( V_2 , & V_2 -> V_382 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
F_62 ( V_2 ) ;
}
static void F_74 ( struct V_383 * V_384 ,
struct V_225 * V_385 ,
struct V_225 * V_226 )
{
struct V_1 * V_2 = V_384 -> V_386 ;
F_23 ( & V_2 -> V_387 ) ;
memcpy ( & V_2 -> V_382 , V_226 , sizeof( V_2 -> V_382 ) ) ;
F_24 ( & V_2 -> V_387 ) ;
}
static bool F_75 ( struct V_383 * V_384 ,
const struct V_225 * V_226 ,
struct V_225 * V_388 )
{
return true ;
}
static void F_76 ( struct V_383 * V_384 )
{
struct V_1 * V_2 = V_384 -> V_386 ;
F_23 ( & V_2 -> V_387 ) ;
V_2 -> V_389 = true ;
F_73 ( V_2 ) ;
F_24 ( & V_2 -> V_387 ) ;
}
static void F_77 ( struct V_383 * V_384 )
{
struct V_1 * V_2 = V_384 -> V_386 ;
F_23 ( & V_2 -> V_387 ) ;
F_72 ( V_2 ) ;
V_2 -> V_389 = false ;
F_24 ( & V_2 -> V_387 ) ;
}
static void F_78 ( struct V_383 * V_384 )
{
}
static enum V_390
F_79 ( struct V_391 * V_392 , bool V_393 )
{
struct V_1 * V_2 = F_80 ( V_392 , struct V_1 ,
V_392 ) ;
return F_10 ( V_2 , V_207 ) & V_354 ?
V_394 : V_395 ;
}
static int F_81 ( struct V_391 * V_392 )
{
struct V_1 * V_2 = F_80 ( V_392 , struct V_1 ,
V_392 ) ;
struct V_396 * V_396 ;
int V_210 = 0 ;
if ( ! V_2 -> V_397 )
return 0 ;
V_396 = F_82 ( V_392 , V_2 -> V_397 ) ;
if ( V_396 ) {
F_19 ( V_2 -> V_28 , L_12 ,
V_396 -> V_398 , V_396 -> V_399 ) ;
V_2 -> V_211 = F_83 ( V_396 ) ;
V_2 -> V_347 = F_84 ( V_396 ) ;
F_85 ( V_392 , V_396 ) ;
V_210 = F_86 ( V_392 , V_396 ) ;
F_87 ( V_396 ) ;
} else {
F_19 ( V_2 -> V_28 , L_13 ) ;
}
return V_210 ;
}
static enum V_400
F_88 ( struct V_391 * V_392 ,
struct V_225 * V_226 )
{
struct V_1 * V_2 = F_80 ( V_392 ,
struct V_1 , V_392 ) ;
enum V_400 V_401 = V_402 ;
if ( V_226 -> V_38 & V_403 )
return V_404 ;
if ( V_2 -> V_176 -> V_405 )
V_401 = V_2 -> V_176 -> V_405 ( V_392 , V_226 ) ;
return V_401 ;
}
static struct V_406 * F_89 ( struct V_391
* V_392 )
{
struct V_1 * V_2 = F_80 ( V_392 , struct V_1 ,
V_392 ) ;
return V_2 -> V_407 ;
}
static void F_90 ( struct V_391 * V_392 )
{
F_91 ( V_392 ) ;
F_92 ( V_392 ) ;
}
static T_3 F_93 ( int V_408 , void * V_409 )
{
struct V_1 * V_2 = V_409 ;
T_1 V_410 ;
V_410 = F_10 ( V_2 , V_357 ) ;
if ( V_410 )
F_9 ( V_2 , ~ 0 , V_376 ) ;
return V_410 ? V_411 : V_412 ;
}
static T_3 F_94 ( int V_408 , void * V_409 )
{
struct V_1 * V_2 = V_409 ;
T_1 V_410 ;
T_1 V_413 ;
V_410 = F_10 ( V_2 , V_357 ) ;
V_413 = F_10 ( V_2 , V_414 ) ;
if ( V_410 & V_356 ) {
F_11 ( V_2 , ~ V_413 , V_354 , V_414 ) ;
F_23 ( & V_2 -> V_387 ) ;
if ( V_413 & V_354 ) {
F_19 ( V_2 -> V_28 , L_14 ) ;
if ( ! V_2 -> V_389 )
F_72 ( V_2 ) ;
} else {
F_19 ( V_2 -> V_28 , L_15 ) ;
if ( ! V_2 -> V_389 )
F_73 ( V_2 ) ;
}
F_24 ( & V_2 -> V_387 ) ;
F_95 ( V_2 -> V_384 -> V_28 ) ;
}
F_9 ( V_2 , V_410 , V_357 ) ;
F_9 ( V_2 , ~ V_356 , V_376 ) ;
return V_415 ;
}
static int F_96 ( struct V_416 * V_417 , struct V_1 * V_2 )
{
struct V_406 * V_407 = V_2 -> V_407 ;
struct V_383 * V_384 ;
int V_210 ;
V_384 = F_97 ( V_417 -> V_28 , sizeof( * V_384 ) , V_418 ) ;
if ( ! V_384 ) {
F_98 ( L_16 ) ;
return - V_419 ;
}
V_2 -> V_384 = V_384 ;
V_384 -> V_386 = V_2 ;
V_384 -> V_420 = & V_421 ;
V_210 = F_99 ( V_417 , V_384 ) ;
if ( V_210 ) {
F_98 ( L_17 ) ;
return - V_185 ;
}
V_407 -> V_384 = V_384 ;
V_2 -> V_392 . V_422 = V_423 ;
F_100 ( & V_2 -> V_392 ,
& V_424 ) ;
F_101 ( V_417 , & V_2 -> V_392 , & V_425 ,
V_426 ) ;
V_2 -> V_392 . V_407 = V_407 ;
F_102 ( & V_2 -> V_392 , V_407 ) ;
return 0 ;
}
int F_103 ( struct V_427 * V_28 , struct V_427 * V_428 ,
void * V_8 , struct V_406 * V_407 ,
struct V_429 * V_430 , int V_408 ,
const struct V_174 * V_176 )
{
struct V_416 * V_417 = V_8 ;
struct V_431 * V_432 = V_28 -> V_433 ;
struct V_431 * V_434 ;
struct V_1 * V_2 ;
int V_210 ;
T_2 V_3 = 1 ;
V_2 = F_97 ( V_28 , sizeof( * V_2 ) , V_418 ) ;
if ( ! V_2 )
return - V_419 ;
V_2 -> V_176 = V_176 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_205 = V_176 -> V_205 ;
V_2 -> V_27 = 48000 ;
V_2 -> V_25 = 100 ;
V_2 -> V_407 = V_407 ;
V_2 -> V_389 = true ;
F_104 ( & V_2 -> V_387 ) ;
F_104 ( & V_2 -> V_33 ) ;
F_105 ( & V_2 -> V_29 ) ;
F_106 ( V_432 , L_18 , & V_3 ) ;
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
F_18 ( V_28 , L_19 ) ;
return - V_185 ;
}
V_434 = F_107 ( V_432 , L_20 , 0 ) ;
if ( V_434 ) {
V_2 -> V_397 = F_108 ( V_434 ) ;
F_109 ( V_434 ) ;
if ( ! V_2 -> V_397 ) {
F_19 ( V_2 -> V_28 , L_21 ) ;
return - V_435 ;
}
} else {
F_19 ( V_2 -> V_28 , L_22 ) ;
}
V_2 -> V_5 = F_110 ( V_28 , V_430 ) ;
if ( F_111 ( V_2 -> V_5 ) )
return F_112 ( V_2 -> V_5 ) ;
V_2 -> V_436 = F_113 ( V_2 -> V_28 , L_23 ) ;
if ( F_111 ( V_2 -> V_436 ) ) {
V_210 = F_112 ( V_2 -> V_436 ) ;
F_18 ( V_2 -> V_28 , L_24 , V_210 ) ;
return V_210 ;
}
V_210 = F_114 ( V_2 -> V_436 ) ;
if ( V_210 ) {
F_18 ( V_2 -> V_28 , L_25 , V_210 ) ;
return V_210 ;
}
V_2 -> V_437 = F_113 ( V_2 -> V_28 , L_26 ) ;
if ( F_111 ( V_2 -> V_437 ) ) {
V_210 = F_112 ( V_2 -> V_437 ) ;
F_18 ( V_2 -> V_28 , L_27 , V_210 ) ;
goto V_438;
}
V_210 = F_114 ( V_2 -> V_437 ) ;
if ( V_210 ) {
F_18 ( V_2 -> V_28 , L_28 , V_210 ) ;
goto V_438;
}
F_115 ( V_28 ,
L_29 ,
F_10 ( V_2 , V_439 ) ,
F_10 ( V_2 , V_440 ) ,
F_10 ( V_2 , V_441 ) ,
F_10 ( V_2 , V_442 ) ) ;
F_71 ( V_2 ) ;
V_210 = F_116 ( V_28 , V_408 , F_93 ,
F_94 , V_443 ,
F_117 ( V_28 ) , V_2 ) ;
if ( V_210 )
goto V_444;
F_22 ( V_2 ) ;
F_9 ( V_2 , V_354 , V_414 ) ;
F_9 ( V_2 , V_356 , V_357 ) ;
V_210 = F_70 ( V_2 ) ;
if ( V_210 )
goto V_444;
V_210 = F_96 ( V_417 , V_2 ) ;
if ( V_210 )
goto V_444;
F_9 ( V_2 , ~ V_356 , V_376 ) ;
F_118 ( V_28 , V_2 ) ;
return 0 ;
V_444:
F_119 ( V_2 -> V_437 ) ;
V_438:
F_119 ( V_2 -> V_436 ) ;
return V_210 ;
}
void F_120 ( struct V_427 * V_28 , struct V_427 * V_428 , void * V_8 )
{
struct V_1 * V_2 = F_121 ( V_28 ) ;
F_9 ( V_2 , ~ 0 , V_376 ) ;
V_2 -> V_392 . V_420 -> V_445 ( & V_2 -> V_392 ) ;
V_2 -> V_407 -> V_420 -> V_445 ( V_2 -> V_407 ) ;
F_119 ( V_2 -> V_437 ) ;
F_119 ( V_2 -> V_436 ) ;
F_122 ( V_2 -> V_397 ) ;
}
