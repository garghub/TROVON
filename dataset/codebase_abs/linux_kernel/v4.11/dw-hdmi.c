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
static void F_13 ( struct V_1 * V_2 )
{
F_9 ( V_2 , 0x00 , V_12 ) ;
F_9 ( V_2 , 0x00 , V_13 ) ;
F_9 ( V_2 , V_14 , V_15 ) ;
F_9 ( V_2 , V_16 | V_17 ,
V_18 ) ;
F_9 ( V_2 , V_19 | V_20 ,
V_21 ) ;
F_9 ( V_2 , V_19 | V_20 ,
V_22 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned char * V_23 , unsigned int V_24 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
int V_27 ;
if ( ! V_26 -> V_28 ) {
F_15 ( V_2 -> V_29 , L_1 ) ;
V_26 -> V_30 = 0x00 ;
V_26 -> V_28 = true ;
}
while ( V_24 -- ) {
F_16 ( & V_26 -> V_31 ) ;
F_9 ( V_2 , V_26 -> V_30 ++ , V_32 ) ;
F_9 ( V_2 , V_33 ,
V_34 ) ;
V_27 = F_17 ( & V_26 -> V_31 , V_35 / 10 ) ;
if ( ! V_27 )
return - V_36 ;
if ( V_26 -> V_27 & V_19 )
return - V_37 ;
* V_23 ++ = F_10 ( V_2 , V_38 ) ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned char * V_23 , unsigned int V_24 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
int V_27 ;
if ( ! V_26 -> V_28 ) {
V_26 -> V_30 = V_23 [ 0 ] ;
V_24 -- ;
V_23 ++ ;
V_26 -> V_28 = true ;
}
while ( V_24 -- ) {
F_16 ( & V_26 -> V_31 ) ;
F_9 ( V_2 , * V_23 ++ , V_39 ) ;
F_9 ( V_2 , V_26 -> V_30 ++ , V_32 ) ;
F_9 ( V_2 , V_40 ,
V_34 ) ;
V_27 = F_17 ( & V_26 -> V_31 , V_35 / 10 ) ;
if ( ! V_27 )
return - V_36 ;
if ( V_26 -> V_27 & V_19 )
return - V_37 ;
}
return 0 ;
}
static int F_19 ( struct V_41 * V_42 ,
struct V_43 * V_44 , int V_45 )
{
struct V_1 * V_2 = F_20 ( V_42 ) ;
struct V_25 * V_26 = V_2 -> V_26 ;
T_1 V_46 = V_44 [ 0 ] . V_46 ;
int V_47 , V_48 = 0 ;
F_15 ( V_2 -> V_29 , L_2 , V_45 , V_46 ) ;
for ( V_47 = 0 ; V_47 < V_45 ; V_47 ++ ) {
if ( V_44 [ V_47 ] . V_46 != V_46 ) {
F_21 ( V_2 -> V_29 ,
L_3 ) ;
return - V_49 ;
}
if ( V_44 [ V_47 ] . V_50 == 0 ) {
F_15 ( V_2 -> V_29 ,
L_4 ,
V_47 + 1 , V_45 ) ;
return - V_49 ;
}
}
F_22 ( & V_26 -> V_51 ) ;
F_9 ( V_2 , 0x00 , V_22 ) ;
F_9 ( V_2 , V_46 , V_52 ) ;
V_26 -> V_28 = false ;
for ( V_47 = 0 ; V_47 < V_45 ; V_47 ++ ) {
F_15 ( V_2 -> V_29 , L_5 ,
V_47 + 1 , V_45 , V_44 [ V_47 ] . V_50 , V_44 [ V_47 ] . V_53 ) ;
if ( V_44 [ V_47 ] . V_53 & V_54 )
V_48 = F_14 ( V_2 , V_44 [ V_47 ] . V_23 , V_44 [ V_47 ] . V_50 ) ;
else
V_48 = F_18 ( V_2 , V_44 [ V_47 ] . V_23 , V_44 [ V_47 ] . V_50 ) ;
if ( V_48 < 0 )
break;
}
if ( ! V_48 )
V_48 = V_45 ;
F_9 ( V_2 , V_19 | V_20 ,
V_22 ) ;
F_23 ( & V_26 -> V_51 ) ;
return V_48 ;
}
static T_2 F_24 ( struct V_41 * V_55 )
{
return V_56 | V_57 ;
}
static struct V_41 * F_25 ( struct V_1 * V_2 )
{
struct V_41 * V_42 ;
struct V_25 * V_26 ;
int V_48 ;
V_26 = F_26 ( V_2 -> V_29 , sizeof( * V_26 ) , V_58 ) ;
if ( ! V_26 )
return F_27 ( - V_59 ) ;
F_28 ( & V_26 -> V_51 ) ;
F_29 ( & V_26 -> V_31 ) ;
V_42 = & V_26 -> V_42 ;
V_42 -> V_60 = V_61 ;
V_42 -> V_62 = V_63 ;
V_42 -> V_29 . V_64 = V_2 -> V_29 ;
V_42 -> V_65 = & V_66 ;
F_30 ( V_42 -> V_67 , L_6 , sizeof( V_42 -> V_67 ) ) ;
F_31 ( V_42 , V_2 ) ;
V_48 = F_32 ( V_42 ) ;
if ( V_48 ) {
F_21 ( V_2 -> V_29 , L_7 , V_42 -> V_67 ) ;
F_33 ( V_2 -> V_29 , V_26 ) ;
return F_27 ( V_48 ) ;
}
V_2 -> V_26 = V_26 ;
F_34 ( V_2 -> V_29 , L_8 , V_42 -> V_67 ) ;
return V_42 ;
}
static void F_35 ( struct V_1 * V_2 , unsigned int V_68 ,
unsigned int V_69 )
{
F_11 ( V_2 , 0 , V_70 , V_71 ) ;
F_11 ( V_2 , 0 , V_72 , V_71 ) ;
F_9 ( V_2 , ( ( V_68 >> 16 ) & V_73 ) |
V_70 , V_71 ) ;
F_9 ( V_2 , ( V_68 >> 8 ) & 0xff , V_74 ) ;
F_9 ( V_2 , V_68 & 0xff , V_75 ) ;
F_9 ( V_2 , ( V_69 >> 16 ) & 0x0f , V_76 ) ;
F_9 ( V_2 , ( V_69 >> 8 ) & 0xff , V_77 ) ;
F_9 ( V_2 , V_69 & 0xff , V_78 ) ;
}
static unsigned int F_36 ( unsigned int V_79 , unsigned long V_80 )
{
unsigned int V_69 = ( 128 * V_79 ) / 1000 ;
unsigned int V_81 = 1 ;
while ( V_79 > 48000 ) {
V_81 *= 2 ;
V_79 /= 2 ;
}
switch ( V_79 ) {
case 32000 :
if ( V_80 == 25175000 )
V_69 = 4576 ;
else if ( V_80 == 27027000 )
V_69 = 4096 ;
else if ( V_80 == 74176000 || V_80 == 148352000 )
V_69 = 11648 ;
else
V_69 = 4096 ;
V_69 *= V_81 ;
break;
case 44100 :
if ( V_80 == 25175000 )
V_69 = 7007 ;
else if ( V_80 == 74176000 )
V_69 = 17836 ;
else if ( V_80 == 148352000 )
V_69 = 8918 ;
else
V_69 = 6272 ;
V_69 *= V_81 ;
break;
case 48000 :
if ( V_80 == 25175000 )
V_69 = 6864 ;
else if ( V_80 == 27027000 )
V_69 = 6144 ;
else if ( V_80 == 74176000 )
V_69 = 11648 ;
else if ( V_80 == 148352000 )
V_69 = 5824 ;
else
V_69 = 6144 ;
V_69 *= V_81 ;
break;
default:
break;
}
return V_69 ;
}
static void F_37 ( struct V_1 * V_2 ,
unsigned long V_80 , unsigned int V_82 )
{
unsigned long V_83 = V_80 ;
unsigned int V_69 , V_68 ;
T_3 V_84 ;
V_69 = F_36 ( V_82 , V_80 ) ;
V_84 = ( T_3 ) V_83 * V_69 ;
F_38 ( V_84 , 128 * V_82 ) ;
V_68 = V_84 ;
F_15 ( V_2 -> V_29 , L_9 ,
V_85 , V_82 , V_83 / 1000000 , ( V_83 / 1000 ) % 1000 ,
V_69 , V_68 ) ;
F_39 ( & V_2 -> V_86 ) ;
V_2 -> V_87 = V_69 ;
V_2 -> V_88 = V_68 ;
F_35 ( V_2 , V_68 , V_2 -> V_89 ? V_69 : 0 ) ;
F_40 ( & V_2 -> V_86 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
F_22 ( & V_2 -> V_90 ) ;
F_37 ( V_2 , 74250000 , V_2 -> V_82 ) ;
F_23 ( & V_2 -> V_90 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_22 ( & V_2 -> V_90 ) ;
F_37 ( V_2 , V_2 -> V_91 . V_92 . V_93 ,
V_2 -> V_82 ) ;
F_23 ( & V_2 -> V_90 ) ;
}
void F_43 ( struct V_1 * V_2 , unsigned int V_94 )
{
F_22 ( & V_2 -> V_90 ) ;
V_2 -> V_82 = V_94 ;
F_37 ( V_2 , V_2 -> V_91 . V_92 . V_93 ,
V_2 -> V_82 ) ;
F_23 ( & V_2 -> V_90 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
unsigned long V_53 ;
F_45 ( & V_2 -> V_86 , V_53 ) ;
V_2 -> V_89 = true ;
F_35 ( V_2 , V_2 -> V_88 , V_2 -> V_87 ) ;
F_46 ( & V_2 -> V_86 , V_53 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
unsigned long V_53 ;
F_45 ( & V_2 -> V_86 , V_53 ) ;
V_2 -> V_89 = false ;
F_35 ( V_2 , V_2 -> V_88 , 0 ) ;
F_46 ( & V_2 -> V_86 , V_53 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
int V_95 = 0 ;
T_1 V_3 ;
if ( V_2 -> V_91 . V_96 == V_97 ) {
if ( V_2 -> V_91 . V_98 == 8 )
V_95 = 0x01 ;
else if ( V_2 -> V_91 . V_98 == 10 )
V_95 = 0x03 ;
else if ( V_2 -> V_91 . V_98 == 12 )
V_95 = 0x05 ;
else if ( V_2 -> V_91 . V_98 == 16 )
V_95 = 0x07 ;
else
return;
} else if ( V_2 -> V_91 . V_96 == V_99 ) {
if ( V_2 -> V_91 . V_98 == 8 )
V_95 = 0x09 ;
else if ( V_2 -> V_91 . V_98 == 10 )
V_95 = 0x0B ;
else if ( V_2 -> V_91 . V_98 == 12 )
V_95 = 0x0D ;
else if ( V_2 -> V_91 . V_98 == 16 )
V_95 = 0x0F ;
else
return;
} else if ( V_2 -> V_91 . V_96 == V_100 ) {
if ( V_2 -> V_91 . V_98 == 8 )
V_95 = 0x16 ;
else if ( V_2 -> V_91 . V_98 == 10 )
V_95 = 0x14 ;
else if ( V_2 -> V_91 . V_98 == 12 )
V_95 = 0x12 ;
else
return;
}
V_3 = V_101 |
( ( V_95 << V_102 ) &
V_103 ) ;
F_9 ( V_2 , V_3 , V_104 ) ;
V_3 = V_105 |
V_106 |
V_107 ;
F_9 ( V_2 , V_3 , V_108 ) ;
F_9 ( V_2 , 0x0 , V_109 ) ;
F_9 ( V_2 , 0x0 , V_110 ) ;
F_9 ( V_2 , 0x0 , V_111 ) ;
F_9 ( V_2 , 0x0 , V_112 ) ;
F_9 ( V_2 , 0x0 , V_113 ) ;
F_9 ( V_2 , 0x0 , V_114 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
return V_2 -> V_91 . V_96 != V_2 -> V_91 . V_115 ;
}
static int F_50 ( struct V_1 * V_2 )
{
if ( V_2 -> V_91 . V_115 != V_100 )
return 0 ;
if ( V_2 -> V_91 . V_96 == V_97 ||
V_2 -> V_91 . V_96 == V_99 )
return 1 ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
if ( V_2 -> V_91 . V_96 != V_100 )
return 0 ;
if ( V_2 -> V_91 . V_115 == V_97 ||
V_2 -> V_91 . V_115 == V_99 )
return 1 ;
return 0 ;
}
static void F_52 ( struct V_1 * V_2 )
{
const F_53 ( * V_116 ) [ 3 ] [ 4 ] = & V_117 ;
unsigned V_47 ;
T_2 V_118 = 1 ;
if ( F_49 ( V_2 ) ) {
if ( V_2 -> V_91 . V_115 == V_97 ) {
if ( V_2 -> V_91 . V_119 ==
V_120 )
V_116 = & V_121 ;
else
V_116 = & V_122 ;
} else if ( V_2 -> V_91 . V_96 == V_97 ) {
if ( V_2 -> V_91 . V_119 ==
V_120 )
V_116 = & V_123 ;
else
V_116 = & V_124 ;
V_118 = 0 ;
}
}
for ( V_47 = 0 ; V_47 < F_54 ( V_117 [ 0 ] ) ; V_47 ++ ) {
F_53 V_125 = ( * V_116 ) [ 0 ] [ V_47 ] ;
F_53 V_126 = ( * V_116 ) [ 1 ] [ V_47 ] ;
F_53 V_127 = ( * V_116 ) [ 2 ] [ V_47 ] ;
F_9 ( V_2 , V_125 & 0xff , V_128 + V_47 * 2 ) ;
F_9 ( V_2 , V_125 >> 8 , V_129 + V_47 * 2 ) ;
F_9 ( V_2 , V_126 & 0xff , V_130 + V_47 * 2 ) ;
F_9 ( V_2 , V_126 >> 8 , V_131 + V_47 * 2 ) ;
F_9 ( V_2 , V_127 & 0xff , V_132 + V_47 * 2 ) ;
F_9 ( V_2 , V_127 >> 8 , V_133 + V_47 * 2 ) ;
}
F_11 ( V_2 , V_118 , V_134 ,
V_135 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
int V_136 = 0 ;
int V_137 = V_138 ;
int V_139 = 0 ;
if ( F_51 ( V_2 ) )
V_137 = V_140 ;
else if ( F_50 ( V_2 ) )
V_139 = V_141 ;
if ( V_2 -> V_91 . V_98 == 8 )
V_136 = V_142 ;
else if ( V_2 -> V_91 . V_98 == 10 )
V_136 = V_143 ;
else if ( V_2 -> V_91 . V_98 == 12 )
V_136 = V_144 ;
else if ( V_2 -> V_91 . V_98 == 16 )
V_136 = V_145 ;
else
return;
F_9 ( V_2 , V_137 | V_139 , V_146 ) ;
F_11 ( V_2 , V_136 , V_147 ,
V_135 ) ;
F_52 ( V_2 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
unsigned int V_136 = 0 ;
unsigned int V_148 = V_149 ;
unsigned int V_150 = V_151 ;
struct V_152 * V_91 = & V_2 -> V_91 ;
T_1 V_3 , V_153 ;
if ( V_91 -> V_115 == V_97 ||
V_91 -> V_115 == V_99 ) {
if ( ! V_91 -> V_98 ) {
V_150 = V_154 ;
} else if ( V_91 -> V_98 == 8 ) {
V_136 = 4 ;
V_150 = V_154 ;
} else if ( V_91 -> V_98 == 10 ) {
V_136 = 5 ;
} else if ( V_91 -> V_98 == 12 ) {
V_136 = 6 ;
} else if ( V_91 -> V_98 == 16 ) {
V_136 = 7 ;
} else {
return;
}
} else if ( V_91 -> V_115 == V_100 ) {
if ( ! V_91 -> V_98 ||
V_91 -> V_98 == 8 )
V_148 = V_149 ;
else if ( V_91 -> V_98 == 10 )
V_148 = V_155 ;
else if ( V_91 -> V_98 == 12 )
V_148 = V_156 ;
else
return;
V_150 = V_157 ;
} else {
return;
}
V_3 = ( ( V_136 << V_158 ) &
V_159 ) |
( ( V_91 -> V_160 <<
V_161 ) &
V_162 ) ;
F_9 ( V_2 , V_3 , V_163 ) ;
F_11 ( V_2 , V_164 ,
V_165 , V_166 ) ;
if ( V_91 -> V_160 > 1 ) {
V_153 = V_167 |
V_168 ;
} else {
V_153 = V_169 |
V_170 ;
}
F_11 ( V_2 , V_153 ,
V_171 |
V_172 , V_173 ) ;
F_11 ( V_2 , 1 << V_174 ,
V_175 , V_166 ) ;
F_9 ( V_2 , V_148 , V_176 ) ;
if ( V_150 == V_151 ) {
V_153 = V_177 |
V_178 |
V_179 ;
} else if ( V_150 == V_157 ) {
V_153 = V_177 |
V_180 |
V_181 ;
} else if ( V_150 == V_154 ) {
V_153 = V_182 |
V_180 |
V_179 ;
} else {
return;
}
F_11 ( V_2 , V_153 ,
V_183 | V_184 |
V_185 , V_173 ) ;
F_11 ( V_2 , V_186 |
V_187 ,
V_188 |
V_189 , V_166 ) ;
F_11 ( V_2 , V_150 , V_190 ,
V_173 ) ;
}
static inline void F_57 ( struct V_1 * V_2 ,
unsigned char V_191 )
{
F_11 ( V_2 , V_191 << V_192 ,
V_193 , V_194 ) ;
}
static inline void F_58 ( struct V_1 * V_2 ,
unsigned char V_191 )
{
F_11 ( V_2 , V_191 << V_195 ,
V_196 , V_194 ) ;
}
static inline void F_59 ( struct V_1 * V_2 ,
unsigned char V_191 )
{
F_11 ( V_2 , V_191 << V_197 ,
V_198 , V_194 ) ;
}
static inline void F_60 ( struct V_1 * V_2 ,
unsigned char V_191 )
{
F_9 ( V_2 , V_191 , V_199 ) ;
}
static inline void F_61 ( struct V_1 * V_2 ,
unsigned char V_191 )
{
F_9 ( V_2 , V_191 , V_200 ) ;
}
static bool F_62 ( struct V_1 * V_2 , int V_201 )
{
T_2 V_3 ;
while ( ( V_3 = F_10 ( V_2 , V_202 ) & 0x3 ) == 0 ) {
if ( V_201 -- == 0 )
return false ;
F_63 ( 1000 ) ;
}
F_9 ( V_2 , V_3 , V_202 ) ;
return true ;
}
static void F_64 ( struct V_1 * V_2 , unsigned short V_8 ,
unsigned char V_46 )
{
F_9 ( V_2 , 0xFF , V_202 ) ;
F_9 ( V_2 , V_46 , V_203 ) ;
F_9 ( V_2 , ( unsigned char ) ( V_8 >> 8 ) ,
V_204 ) ;
F_9 ( V_2 , ( unsigned char ) ( V_8 >> 0 ) ,
V_205 ) ;
F_9 ( V_2 , V_206 ,
V_207 ) ;
F_62 ( V_2 , 1000 ) ;
}
static void F_65 ( struct V_1 * V_2 , bool V_208 )
{
F_12 ( V_2 , ! V_208 , V_209 ,
V_210 ,
V_211 ) ;
}
static void F_66 ( struct V_1 * V_2 , T_1 V_208 )
{
F_12 ( V_2 , V_208 , V_209 ,
V_212 ,
V_213 ) ;
}
static void F_67 ( struct V_1 * V_2 , T_1 V_208 )
{
F_12 ( V_2 , V_208 , V_209 ,
V_214 ,
V_215 ) ;
}
static void F_68 ( struct V_1 * V_2 , T_1 V_208 )
{
F_12 ( V_2 , V_208 , V_209 ,
V_216 ,
V_217 ) ;
}
static void F_69 ( struct V_1 * V_2 , T_1 V_208 )
{
F_12 ( V_2 , V_208 , V_209 ,
V_218 ,
V_219 ) ;
}
static void F_70 ( struct V_1 * V_2 , T_1 V_208 )
{
F_12 ( V_2 , V_208 , V_209 ,
V_220 ,
V_221 ) ;
}
static void F_71 ( struct V_1 * V_2 , T_1 V_208 )
{
F_12 ( V_2 , V_208 , V_209 ,
V_222 ,
V_223 ) ;
}
static int F_72 ( struct V_1 * V_2 , int V_224 )
{
T_1 V_3 , V_201 ;
const struct V_225 * V_226 = V_2 -> V_227 ;
const struct V_228 * V_229 = V_226 -> V_230 ;
const struct V_231 * V_232 = V_226 -> V_233 ;
const struct V_234 * V_235 = V_226 -> V_235 ;
for (; V_229 -> V_93 != ~ 0UL ; V_229 ++ )
if ( V_2 -> V_91 . V_92 . V_93 <=
V_229 -> V_93 )
break;
for (; V_232 -> V_93 != ~ 0UL ; V_232 ++ )
if ( V_2 -> V_91 . V_92 . V_93 <=
V_232 -> V_93 )
break;
for (; V_235 -> V_93 != ~ 0UL ; V_235 ++ )
if ( V_2 -> V_91 . V_92 . V_93 <=
V_235 -> V_93 )
break;
if ( V_229 -> V_93 == ~ 0UL ||
V_232 -> V_93 == ~ 0UL ||
V_235 -> V_93 == ~ 0UL ) {
F_73 ( V_2 -> V_29 , L_10 ,
V_2 -> V_91 . V_92 . V_93 ) ;
return - V_236 ;
}
if ( V_224 )
V_3 = V_237 ;
else
V_3 = V_238 ;
F_9 ( V_2 , V_3 , V_239 ) ;
F_69 ( V_2 , 0 ) ;
F_68 ( V_2 , 1 ) ;
if ( V_2 -> V_240 -> V_241 )
F_67 ( V_2 , 1 ) ;
F_9 ( V_2 , V_242 , V_243 ) ;
F_9 ( V_2 , 0 , V_243 ) ;
F_9 ( V_2 , V_244 , V_245 ) ;
F_57 ( V_2 , 1 ) ;
F_9 ( V_2 , V_246 ,
V_247 ) ;
F_57 ( V_2 , 0 ) ;
F_64 ( V_2 , V_229 -> V_248 [ 0 ] . V_249 ,
V_250 ) ;
F_64 ( V_2 , V_229 -> V_248 [ 0 ] . V_251 ,
V_252 ) ;
F_64 ( V_2 , V_232 -> V_253 [ 0 ] ,
V_254 ) ;
F_64 ( V_2 , 0 , V_255 ) ;
F_64 ( V_2 , V_256 ,
V_257 ) ;
F_64 ( V_2 , V_235 -> V_258 , V_259 ) ;
F_64 ( V_2 , V_235 -> V_260 ,
V_261 ) ;
F_64 ( V_2 , V_235 -> V_262 ,
V_263 ) ;
F_64 ( V_2 , V_264 ,
V_265 ) ;
F_65 ( V_2 , false ) ;
F_66 ( V_2 , 0 ) ;
F_66 ( V_2 , 1 ) ;
F_69 ( V_2 , 1 ) ;
F_68 ( V_2 , 0 ) ;
V_201 = 5 ;
do {
V_3 = F_10 ( V_2 , V_266 ) & V_267 ;
if ( ! V_3 )
break;
if ( V_201 == 0 ) {
F_73 ( V_2 -> V_29 , L_11 ) ;
return - V_268 ;
}
F_63 ( 1000 ) ;
V_201 -- ;
} while ( 1 );
return 0 ;
}
static int F_74 ( struct V_1 * V_2 )
{
int V_47 , V_48 ;
bool V_224 ;
V_224 = V_2 -> V_269 && F_49 ( V_2 ) ;
for ( V_47 = 0 ; V_47 < 2 ; V_47 ++ ) {
F_70 ( V_2 , 1 ) ;
F_71 ( V_2 , 0 ) ;
F_66 ( V_2 , 0 ) ;
F_65 ( V_2 , true ) ;
V_48 = F_72 ( V_2 , V_224 ) ;
if ( V_48 )
return V_48 ;
}
V_2 -> V_270 = true ;
return 0 ;
}
static void F_75 ( struct V_1 * V_2 )
{
T_1 V_271 ;
if ( V_2 -> V_91 . V_92 . V_272 )
V_271 = V_273 ;
else
V_271 = V_274 ;
F_11 ( V_2 , V_275 ,
V_276 , V_277 ) ;
F_11 ( V_2 , V_271 , V_278 , V_279 ) ;
F_11 ( V_2 , V_280 ,
V_281 , V_282 ) ;
}
static void F_76 ( struct V_1 * V_2 , struct V_283 * V_284 )
{
struct V_285 V_286 ;
T_1 V_3 ;
F_77 ( & V_286 , V_284 ) ;
if ( V_2 -> V_91 . V_115 == V_99 )
V_286 . V_287 = V_288 ;
else if ( V_2 -> V_91 . V_115 == V_100 )
V_286 . V_287 = V_289 ;
else
V_286 . V_287 = V_290 ;
if ( V_2 -> V_91 . V_115 == V_291 ) {
V_286 . V_119 = V_292 ;
if ( V_2 -> V_91 . V_119 == V_120 )
V_286 . V_293 =
V_294 ;
else
V_286 . V_293 =
V_295 ;
} else if ( V_2 -> V_91 . V_115 != V_97 ) {
V_286 . V_119 = V_2 -> V_91 . V_119 ;
V_286 . V_293 = V_294 ;
} else {
V_286 . V_119 = V_296 ;
V_286 . V_293 = V_294 ;
}
V_286 . V_297 = V_298 ;
V_3 = ( V_286 . V_297 & 3 ) << 4 | ( V_286 . V_287 & 3 ) ;
if ( V_286 . V_299 & 15 )
V_3 |= V_300 ;
if ( V_286 . V_301 || V_286 . V_302 )
V_3 |= V_303 ;
if ( V_286 . V_304 || V_286 . V_305 )
V_3 |= V_306 ;
F_9 ( V_2 , V_3 , V_307 ) ;
V_3 = ( ( V_286 . V_119 & 0x3 ) << 6 ) |
( ( V_286 . V_308 & 0x3 ) << 4 ) |
( V_286 . V_299 & 0xf ) ;
F_9 ( V_2 , V_3 , V_309 ) ;
V_3 = ( ( V_286 . V_293 & 0x7 ) << 4 ) |
( ( V_286 . V_310 & 0x3 ) << 2 ) |
( V_286 . V_311 & 0x3 ) ;
if ( V_286 . V_312 )
V_3 |= V_313 ;
F_9 ( V_2 , V_3 , V_314 ) ;
V_3 = V_286 . V_315 & 0x7f ;
F_9 ( V_2 , V_3 , V_316 ) ;
V_3 = ( ( ( V_2 -> V_91 . V_92 . V_317 + 1 ) <<
V_318 ) &
V_319 ) |
( ( V_2 -> V_91 . V_92 . V_320 <<
V_321 ) &
V_322 ) ;
F_9 ( V_2 , V_3 , V_323 ) ;
V_3 = ( ( V_286 . V_324 & 0x3 ) << 2 ) |
( V_286 . V_325 & 0x3 ) ;
F_9 ( V_2 , V_3 , V_326 ) ;
F_9 ( V_2 , V_286 . V_301 & 0xff , V_327 ) ;
F_9 ( V_2 , ( V_286 . V_301 >> 8 ) & 0xff , V_328 ) ;
F_9 ( V_2 , V_286 . V_302 & 0xff , V_329 ) ;
F_9 ( V_2 , ( V_286 . V_302 >> 8 ) & 0xff , V_330 ) ;
F_9 ( V_2 , V_286 . V_304 & 0xff , V_331 ) ;
F_9 ( V_2 , ( V_286 . V_304 >> 8 ) & 0xff , V_332 ) ;
F_9 ( V_2 , V_286 . V_305 & 0xff , V_333 ) ;
F_9 ( V_2 , ( V_286 . V_305 >> 8 ) & 0xff , V_334 ) ;
}
static void F_78 ( struct V_1 * V_2 ,
const struct V_283 * V_284 )
{
T_1 V_335 ;
struct V_336 * V_337 = & V_2 -> V_91 . V_92 ;
int V_338 , V_339 , V_340 , V_341 , V_342 , V_343 ;
unsigned int V_344 ;
V_337 -> V_93 = V_284 -> clock * 1000 ;
F_15 ( V_2 -> V_29 , L_12 , V_337 -> V_93 ) ;
V_335 = ( V_2 -> V_91 . V_345 ?
V_346 :
V_347 ) ;
V_335 |= V_284 -> V_53 & V_348 ?
V_349 :
V_350 ;
V_335 |= V_284 -> V_53 & V_351 ?
V_352 :
V_353 ;
V_335 |= ( V_337 -> V_272 ?
V_354 :
V_355 ) ;
if ( V_2 -> V_356 == 39 )
V_335 |= V_357 ;
else
V_335 |= V_284 -> V_53 & V_358 ?
V_357 :
V_359 ;
V_335 |= V_284 -> V_53 & V_358 ?
V_360 :
V_361 ;
V_335 |= V_2 -> V_269 ?
V_362 :
V_363 ;
F_9 ( V_2 , V_335 , V_364 ) ;
V_344 = V_284 -> V_344 ;
V_339 = V_284 -> V_365 - V_284 -> V_344 ;
V_341 = V_284 -> V_366 - V_284 -> V_344 ;
V_343 = V_284 -> V_367 - V_284 -> V_366 ;
if ( V_284 -> V_53 & V_358 ) {
V_344 /= 2 ;
V_339 /= 2 ;
V_341 /= 2 ;
V_343 /= 2 ;
}
F_9 ( V_2 , V_284 -> V_368 >> 8 , V_369 ) ;
F_9 ( V_2 , V_284 -> V_368 , V_370 ) ;
F_9 ( V_2 , V_344 >> 8 , V_371 ) ;
F_9 ( V_2 , V_344 , V_372 ) ;
V_338 = V_284 -> V_373 - V_284 -> V_368 ;
F_9 ( V_2 , V_338 >> 8 , V_374 ) ;
F_9 ( V_2 , V_338 , V_375 ) ;
F_9 ( V_2 , V_339 , V_376 ) ;
V_340 = V_284 -> V_377 - V_284 -> V_368 ;
F_9 ( V_2 , V_340 >> 8 , V_378 ) ;
F_9 ( V_2 , V_340 , V_379 ) ;
F_9 ( V_2 , V_341 , V_380 ) ;
V_342 = V_284 -> V_381 - V_284 -> V_377 ;
F_9 ( V_2 , V_342 >> 8 , V_382 ) ;
F_9 ( V_2 , V_342 , V_383 ) ;
F_9 ( V_2 , V_343 , V_384 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_270 )
return;
F_66 ( V_2 , 0 ) ;
F_65 ( V_2 , true ) ;
V_2 -> V_270 = false ;
}
static void F_80 ( struct V_1 * V_2 )
{
T_1 V_385 ;
F_9 ( V_2 , 12 , V_386 ) ;
F_9 ( V_2 , 32 , V_387 ) ;
F_9 ( V_2 , 1 , V_388 ) ;
F_9 ( V_2 , 0x0B , V_389 ) ;
F_9 ( V_2 , 0x16 , V_390 ) ;
F_9 ( V_2 , 0x21 , V_391 ) ;
V_385 = 0x7F ;
V_385 &= ~ V_392 ;
F_9 ( V_2 , V_385 , V_393 ) ;
V_385 &= ~ V_394 ;
F_9 ( V_2 , V_385 , V_393 ) ;
if ( F_49 ( V_2 ) ) {
V_385 &= ~ V_395 ;
F_9 ( V_2 , V_385 , V_393 ) ;
}
}
static void F_81 ( struct V_1 * V_2 )
{
F_11 ( V_2 , 0 , V_396 , V_393 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
unsigned int V_397 ;
unsigned int V_47 ;
T_1 V_3 ;
switch ( V_2 -> V_398 ) {
case 0x130a :
V_397 = 4 ;
break;
case 0x131a :
V_397 = 1 ;
break;
default:
return;
}
F_9 ( V_2 , ( T_1 ) ~ V_399 , V_400 ) ;
V_3 = F_10 ( V_2 , V_364 ) ;
for ( V_47 = 0 ; V_47 < V_397 ; V_47 ++ )
F_9 ( V_2 , V_3 , V_364 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
F_9 ( V_2 , 0 , V_401 ) ;
F_9 ( V_2 , 0 , V_402 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_403 ,
V_402 ) ;
}
static int F_85 ( struct V_1 * V_2 , struct V_283 * V_284 )
{
int V_48 ;
F_84 ( V_2 ) ;
V_2 -> V_356 = F_86 ( V_284 ) ;
if ( ! V_2 -> V_356 ) {
F_15 ( V_2 -> V_29 , L_13 ) ;
} else {
F_15 ( V_2 -> V_29 , L_14 , V_2 -> V_356 ) ;
}
if ( ( V_2 -> V_356 == 6 ) || ( V_2 -> V_356 == 7 ) ||
( V_2 -> V_356 == 21 ) || ( V_2 -> V_356 == 22 ) ||
( V_2 -> V_356 == 2 ) || ( V_2 -> V_356 == 3 ) ||
( V_2 -> V_356 == 17 ) || ( V_2 -> V_356 == 18 ) )
V_2 -> V_91 . V_119 = V_120 ;
else
V_2 -> V_91 . V_119 = V_404 ;
V_2 -> V_91 . V_92 . V_320 = 0 ;
V_2 -> V_91 . V_92 . V_317 = 0 ;
V_2 -> V_91 . V_96 = V_97 ;
V_2 -> V_91 . V_115 = V_97 ;
V_2 -> V_91 . V_98 = 8 ;
V_2 -> V_91 . V_160 = 0 ;
V_2 -> V_91 . V_345 = 0 ;
V_2 -> V_91 . V_92 . V_272 = true ;
F_78 ( V_2 , V_284 ) ;
V_48 = F_74 ( V_2 ) ;
if ( V_48 )
return V_48 ;
F_80 ( V_2 ) ;
if ( V_2 -> V_405 ) {
F_15 ( V_2 -> V_29 , L_15 ) ;
F_42 ( V_2 ) ;
F_81 ( V_2 ) ;
}
if ( V_2 -> V_269 ) {
F_15 ( V_2 -> V_29 , L_16 , V_85 ) ;
F_76 ( V_2 , V_284 ) ;
} else {
F_15 ( V_2 -> V_29 , L_17 , V_85 ) ;
}
F_56 ( V_2 ) ;
F_55 ( V_2 ) ;
F_48 ( V_2 ) ;
F_75 ( V_2 ) ;
F_82 ( V_2 ) ;
if ( V_2 -> V_406 && V_2 -> V_269 )
F_83 ( V_2 ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_407 ,
V_408 ) ;
F_9 ( V_2 , V_409 |
V_410 ,
V_411 ) ;
F_9 ( V_2 , V_2 -> V_412 , V_413 ) ;
F_9 ( V_2 , V_414 | V_415 ,
V_416 ) ;
return 0 ;
}
static void F_88 ( struct V_1 * V_2 )
{
T_1 V_417 ;
V_417 = F_10 ( V_2 , V_418 ) |
V_419 |
V_420 ;
F_9 ( V_2 , V_417 , V_418 ) ;
F_9 ( V_2 , 0xff , V_421 ) ;
F_9 ( V_2 , 0xff , V_422 ) ;
F_9 ( V_2 , 0xff , V_423 ) ;
F_9 ( V_2 , 0xff , V_401 ) ;
F_9 ( V_2 , 0xff , V_413 ) ;
F_9 ( V_2 , 0xff , V_408 ) ;
F_9 ( V_2 , 0xff , V_411 ) ;
F_9 ( V_2 , 0xff , V_424 ) ;
F_9 ( V_2 , 0xff , V_425 ) ;
F_9 ( V_2 , 0xff , V_426 ) ;
F_9 ( V_2 , 0xff , V_427 ) ;
F_9 ( V_2 , 0xff , V_428 ) ;
F_9 ( V_2 , 0xff , V_429 ) ;
F_9 ( V_2 , 0xff , V_15 ) ;
F_9 ( V_2 , 0xff , V_18 ) ;
F_9 ( V_2 , 0xff , V_430 ) ;
F_9 ( V_2 , 0xff , V_431 ) ;
F_9 ( V_2 , 0xff , V_402 ) ;
F_9 ( V_2 , 0xff , V_432 ) ;
F_9 ( V_2 , 0xff , V_433 ) ;
F_9 ( V_2 , 0xff , V_22 ) ;
F_9 ( V_2 , 0xff , V_434 ) ;
F_9 ( V_2 , 0xff , V_435 ) ;
F_9 ( V_2 , 0xff , V_436 ) ;
F_9 ( V_2 , 0xff , V_437 ) ;
V_417 &= ~ ( V_419 |
V_420 ) ;
F_9 ( V_2 , V_417 , V_418 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
V_2 -> V_438 = true ;
F_85 ( V_2 , & V_2 -> V_439 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
F_79 ( V_2 ) ;
V_2 -> V_438 = false ;
}
static void F_91 ( struct V_1 * V_2 )
{
int V_440 = V_2 -> V_440 ;
if ( V_2 -> V_441 ) {
V_440 = V_442 ;
} else if ( V_440 == V_443 ) {
if ( V_2 -> V_444 )
V_440 = V_445 ;
else
V_440 = V_442 ;
}
if ( V_440 == V_442 ) {
if ( V_2 -> V_438 )
F_90 ( V_2 ) ;
} else {
if ( ! V_2 -> V_438 )
F_89 ( V_2 ) ;
}
}
static void F_92 ( struct V_1 * V_2 )
{
T_1 V_446 = V_2 -> V_412 ;
if ( V_2 -> V_440 || V_2 -> V_441 || ! V_2 -> V_444 )
V_2 -> V_412 |= V_447 ;
else
V_2 -> V_412 &= ~ V_447 ;
if ( V_446 != V_2 -> V_412 )
F_9 ( V_2 , V_2 -> V_412 , V_413 ) ;
}
static enum V_448
F_93 ( struct V_449 * V_450 , bool V_440 )
{
struct V_1 * V_2 = F_94 ( V_450 , struct V_1 ,
V_450 ) ;
F_22 ( & V_2 -> V_451 ) ;
V_2 -> V_440 = V_443 ;
F_91 ( V_2 ) ;
F_92 ( V_2 ) ;
F_23 ( & V_2 -> V_451 ) ;
return F_10 ( V_2 , V_266 ) & V_452 ?
V_453 : V_454 ;
}
static int F_95 ( struct V_449 * V_450 )
{
struct V_1 * V_2 = F_94 ( V_450 , struct V_1 ,
V_450 ) ;
struct V_455 * V_455 ;
int V_48 = 0 ;
if ( ! V_2 -> V_456 )
return 0 ;
V_455 = F_96 ( V_450 , V_2 -> V_456 ) ;
if ( V_455 ) {
F_15 ( V_2 -> V_29 , L_18 ,
V_455 -> V_457 , V_455 -> V_458 ) ;
V_2 -> V_269 = F_97 ( V_455 ) ;
V_2 -> V_405 = F_98 ( V_455 ) ;
F_99 ( V_450 , V_455 ) ;
V_48 = F_100 ( V_450 , V_455 ) ;
F_101 ( V_450 , V_455 ) ;
F_102 ( V_455 ) ;
} else {
F_15 ( V_2 -> V_29 , L_19 ) ;
}
return V_48 ;
}
static enum V_459
F_103 ( struct V_449 * V_450 ,
struct V_283 * V_284 )
{
struct V_1 * V_2 = F_94 ( V_450 ,
struct V_1 , V_450 ) ;
enum V_459 V_460 = V_461 ;
if ( V_284 -> V_53 & V_462 )
return V_463 ;
if ( V_2 -> V_227 -> V_464 )
V_460 = V_2 -> V_227 -> V_464 ( V_450 , V_284 ) ;
return V_460 ;
}
static void F_104 ( struct V_449 * V_450 )
{
struct V_1 * V_2 = F_94 ( V_450 , struct V_1 ,
V_450 ) ;
F_22 ( & V_2 -> V_451 ) ;
V_2 -> V_440 = V_450 -> V_440 ;
F_91 ( V_2 ) ;
F_92 ( V_2 ) ;
F_23 ( & V_2 -> V_451 ) ;
}
static int F_105 ( struct V_465 * V_466 )
{
struct V_1 * V_2 = V_466 -> V_467 ;
struct V_468 * V_469 = V_466 -> V_469 ;
struct V_449 * V_450 = & V_2 -> V_450 ;
V_450 -> V_470 = 1 ;
V_450 -> V_471 = V_472 ;
F_106 ( V_450 , & V_473 ) ;
F_107 ( V_466 -> V_29 , V_450 , & V_474 ,
V_475 ) ;
F_108 ( V_450 , V_469 ) ;
return 0 ;
}
static void F_109 ( struct V_465 * V_466 ,
struct V_283 * V_476 ,
struct V_283 * V_284 )
{
struct V_1 * V_2 = V_466 -> V_467 ;
F_22 ( & V_2 -> V_451 ) ;
memcpy ( & V_2 -> V_439 , V_284 , sizeof( V_2 -> V_439 ) ) ;
F_23 ( & V_2 -> V_451 ) ;
}
static void F_110 ( struct V_465 * V_466 )
{
struct V_1 * V_2 = V_466 -> V_467 ;
F_22 ( & V_2 -> V_451 ) ;
V_2 -> V_441 = true ;
F_91 ( V_2 ) ;
F_92 ( V_2 ) ;
F_23 ( & V_2 -> V_451 ) ;
}
static void F_111 ( struct V_465 * V_466 )
{
struct V_1 * V_2 = V_466 -> V_467 ;
F_22 ( & V_2 -> V_451 ) ;
V_2 -> V_441 = false ;
F_91 ( V_2 ) ;
F_92 ( V_2 ) ;
F_23 ( & V_2 -> V_451 ) ;
}
static T_4 F_112 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
unsigned int V_27 ;
V_27 = F_10 ( V_2 , V_21 ) ;
if ( ! V_27 )
return V_477 ;
F_9 ( V_2 , V_27 , V_21 ) ;
V_26 -> V_27 = V_27 ;
F_113 ( & V_26 -> V_31 ) ;
return V_478 ;
}
static T_4 F_114 ( int V_479 , void * V_480 )
{
struct V_1 * V_2 = V_480 ;
T_1 V_481 ;
T_4 V_48 = V_477 ;
if ( V_2 -> V_26 )
V_48 = F_112 ( V_2 ) ;
V_481 = F_10 ( V_2 , V_416 ) ;
if ( V_481 ) {
F_9 ( V_2 , ~ 0 , V_433 ) ;
return V_482 ;
}
return V_48 ;
}
static T_4 F_115 ( int V_479 , void * V_480 )
{
struct V_1 * V_2 = V_480 ;
T_1 V_481 , V_483 , V_484 , V_485 ;
V_481 = F_10 ( V_2 , V_416 ) ;
V_483 = F_10 ( V_2 , V_486 ) ;
V_485 = F_10 ( V_2 , V_266 ) ;
V_484 = 0 ;
if ( V_481 & V_414 )
V_484 |= V_452 ;
if ( V_481 & V_487 )
V_484 |= V_488 ;
if ( V_481 & V_489 )
V_484 |= V_490 ;
if ( V_481 & V_491 )
V_484 |= V_492 ;
if ( V_481 & V_493 )
V_484 |= V_494 ;
if ( V_484 )
F_11 ( V_2 , ~ V_483 , V_484 , V_486 ) ;
if ( V_481 &
( V_415 | V_414 ) ) {
F_22 ( & V_2 -> V_451 ) ;
if ( ! V_2 -> V_441 && ! V_2 -> V_440 ) {
if ( ! ( V_485 & V_447 ) )
V_2 -> V_444 = false ;
if ( V_485 & V_452 )
V_2 -> V_444 = true ;
F_91 ( V_2 ) ;
F_92 ( V_2 ) ;
}
F_23 ( & V_2 -> V_451 ) ;
}
if ( V_481 & V_414 ) {
F_15 ( V_2 -> V_29 , L_20 ,
V_483 & V_452 ? L_21 : L_22 ) ;
if ( V_2 -> V_466 . V_29 )
F_116 ( V_2 -> V_466 . V_29 ) ;
}
F_9 ( V_2 , V_481 , V_416 ) ;
F_9 ( V_2 , ~ ( V_414 | V_415 ) ,
V_433 ) ;
return V_478 ;
}
static int F_117 ( struct V_1 * V_2 )
{
unsigned int V_47 ;
T_1 V_495 ;
V_495 = F_10 ( V_2 , V_496 ) ;
for ( V_47 = 0 ; V_47 < F_54 ( V_497 ) ; ++ V_47 ) {
if ( V_497 [ V_47 ] . type == V_495 ) {
V_2 -> V_240 = & V_497 [ V_47 ] ;
return 0 ;
}
}
if ( V_495 == V_498 )
F_73 ( V_2 -> V_29 , L_23 ) ;
else
F_73 ( V_2 -> V_29 , L_24 ,
V_495 ) ;
return - V_499 ;
}
static struct V_1 *
F_118 ( struct V_500 * V_501 ,
const struct V_225 * V_227 )
{
struct V_502 * V_29 = & V_501 -> V_29 ;
struct V_503 * V_504 = V_29 -> V_505 ;
struct V_506 V_507 ;
struct V_503 * V_508 ;
struct V_1 * V_2 ;
struct V_509 * V_510 ;
int V_479 ;
int V_48 ;
T_2 V_3 = 1 ;
T_1 V_511 ;
T_1 V_512 ;
T_1 V_513 ;
T_1 V_514 ;
V_2 = F_26 ( V_29 , sizeof( * V_2 ) , V_58 ) ;
if ( ! V_2 )
return F_27 ( - V_59 ) ;
V_2 -> V_227 = V_227 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_515 = V_227 -> V_515 ;
V_2 -> V_82 = 48000 ;
V_2 -> V_441 = true ;
V_2 -> V_444 = true ;
V_2 -> V_412 = ( T_1 ) ~ ( V_452 | V_447 ) ;
F_28 ( & V_2 -> V_451 ) ;
F_28 ( & V_2 -> V_90 ) ;
F_119 ( & V_2 -> V_86 ) ;
F_120 ( V_504 , L_25 , & V_3 ) ;
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
F_73 ( V_29 , L_26 ) ;
return F_27 ( - V_236 ) ;
}
V_508 = F_121 ( V_504 , L_27 , 0 ) ;
if ( V_508 ) {
V_2 -> V_456 = F_122 ( V_508 ) ;
F_123 ( V_508 ) ;
if ( ! V_2 -> V_456 ) {
F_15 ( V_2 -> V_29 , L_28 ) ;
return F_27 ( - V_516 ) ;
}
} else {
F_15 ( V_2 -> V_29 , L_29 ) ;
}
V_510 = F_124 ( V_501 , V_517 , 0 ) ;
V_2 -> V_5 = F_125 ( V_29 , V_510 ) ;
if ( F_126 ( V_2 -> V_5 ) ) {
V_48 = F_127 ( V_2 -> V_5 ) ;
goto V_518;
}
V_2 -> V_519 = F_128 ( V_2 -> V_29 , L_30 ) ;
if ( F_126 ( V_2 -> V_519 ) ) {
V_48 = F_127 ( V_2 -> V_519 ) ;
F_73 ( V_2 -> V_29 , L_31 , V_48 ) ;
goto V_518;
}
V_48 = F_129 ( V_2 -> V_519 ) ;
if ( V_48 ) {
F_73 ( V_2 -> V_29 , L_32 , V_48 ) ;
goto V_518;
}
V_2 -> V_520 = F_128 ( V_2 -> V_29 , L_33 ) ;
if ( F_126 ( V_2 -> V_520 ) ) {
V_48 = F_127 ( V_2 -> V_520 ) ;
F_73 ( V_2 -> V_29 , L_34 , V_48 ) ;
goto V_521;
}
V_48 = F_129 ( V_2 -> V_520 ) ;
if ( V_48 ) {
F_73 ( V_2 -> V_29 , L_35 , V_48 ) ;
goto V_521;
}
V_2 -> V_398 = ( F_10 ( V_2 , V_522 ) << 8 )
| ( F_10 ( V_2 , V_523 ) << 0 ) ;
V_511 = F_10 ( V_2 , V_524 ) ;
V_512 = F_10 ( V_2 , V_525 ) ;
if ( V_511 != V_526 ||
( V_512 & ~ V_527 ) != V_528 ) {
F_73 ( V_29 , L_36 ,
V_2 -> V_398 , V_511 , V_512 ) ;
V_48 = - V_499 ;
goto V_529;
}
V_48 = F_117 ( V_2 ) ;
if ( V_48 < 0 )
goto V_529;
F_34 ( V_29 , L_37 ,
V_2 -> V_398 >> 12 , V_2 -> V_398 & 0xfff ,
V_512 & V_527 ? L_38 : L_39 ,
V_2 -> V_240 -> V_67 ) ;
F_88 ( V_2 ) ;
V_479 = F_130 ( V_501 , 0 ) ;
if ( V_479 < 0 ) {
V_48 = V_479 ;
goto V_529;
}
V_48 = F_131 ( V_29 , V_479 , F_114 ,
F_115 , V_530 ,
F_132 ( V_29 ) , V_2 ) ;
if ( V_48 )
goto V_529;
F_41 ( V_2 ) ;
if ( ! V_2 -> V_456 ) {
V_2 -> V_456 = F_25 ( V_2 ) ;
if ( F_126 ( V_2 -> V_456 ) )
V_2 -> V_456 = NULL ;
}
F_9 ( V_2 , V_452 | V_447 , V_486 ) ;
F_9 ( V_2 , V_414 | V_415 ,
V_416 ) ;
V_2 -> V_466 . V_467 = V_2 ;
V_2 -> V_466 . V_531 = & V_532 ;
#ifdef F_133
V_2 -> V_466 . V_505 = V_501 -> V_29 . V_505 ;
#endif
V_48 = F_87 ( V_2 ) ;
if ( V_48 )
goto V_529;
F_9 ( V_2 , ~ ( V_414 | V_415 ) ,
V_433 ) ;
memset ( & V_507 , 0 , sizeof( V_507 ) ) ;
V_507 . V_64 = V_29 ;
V_507 . V_533 = V_534 ;
V_513 = F_10 ( V_2 , V_535 ) ;
V_514 = F_10 ( V_2 , V_536 ) ;
if ( V_514 & V_537 ) {
struct V_538 V_539 ;
V_539 . V_540 = V_510 -> V_541 ;
V_539 . V_542 = V_2 -> V_5 ;
V_539 . V_479 = V_479 ;
V_539 . V_2 = V_2 ;
V_539 . V_543 = V_2 -> V_450 . V_543 ;
V_507 . V_67 = L_40 ;
V_507 . V_8 = & V_539 ;
V_507 . V_544 = sizeof( V_539 ) ;
V_507 . V_545 = F_134 ( 32 ) ;
V_2 -> V_539 = F_135 ( & V_507 ) ;
} else if ( V_513 & V_546 ) {
struct V_547 V_539 ;
V_539 . V_2 = V_2 ;
V_539 . V_6 = F_9 ;
V_539 . V_7 = F_10 ;
V_507 . V_67 = L_41 ;
V_507 . V_8 = & V_539 ;
V_507 . V_544 = sizeof( V_539 ) ;
V_507 . V_545 = F_134 ( 32 ) ;
V_2 -> V_539 = F_135 ( & V_507 ) ;
}
if ( V_2 -> V_26 )
F_13 ( V_2 ) ;
F_136 ( V_501 , V_2 ) ;
return V_2 ;
V_529:
if ( V_2 -> V_26 ) {
F_137 ( & V_2 -> V_26 -> V_42 ) ;
V_2 -> V_456 = NULL ;
}
F_138 ( V_2 -> V_520 ) ;
V_521:
F_138 ( V_2 -> V_519 ) ;
V_518:
F_139 ( V_2 -> V_456 ) ;
return F_27 ( V_48 ) ;
}
static void F_140 ( struct V_1 * V_2 )
{
if ( V_2 -> V_539 && ! F_126 ( V_2 -> V_539 ) )
F_141 ( V_2 -> V_539 ) ;
F_9 ( V_2 , ~ 0 , V_433 ) ;
F_138 ( V_2 -> V_520 ) ;
F_138 ( V_2 -> V_519 ) ;
if ( V_2 -> V_26 )
F_137 ( & V_2 -> V_26 -> V_42 ) ;
else
F_139 ( V_2 -> V_456 ) ;
}
int F_142 ( struct V_500 * V_501 ,
const struct V_225 * V_227 )
{
struct V_1 * V_2 ;
int V_48 ;
V_2 = F_118 ( V_501 , V_227 ) ;
if ( F_126 ( V_2 ) )
return F_127 ( V_2 ) ;
V_48 = F_143 ( & V_2 -> V_466 ) ;
if ( V_48 < 0 ) {
F_140 ( V_2 ) ;
return V_48 ;
}
return 0 ;
}
void F_144 ( struct V_500 * V_501 )
{
struct V_1 * V_2 = F_145 ( V_501 ) ;
F_146 ( & V_2 -> V_466 ) ;
F_140 ( V_2 ) ;
}
int F_147 ( struct V_500 * V_501 , struct V_468 * V_469 ,
const struct V_225 * V_227 )
{
struct V_1 * V_2 ;
int V_48 ;
V_2 = F_118 ( V_501 , V_227 ) ;
if ( F_126 ( V_2 ) )
return F_127 ( V_2 ) ;
V_48 = F_148 ( V_469 , & V_2 -> V_466 , NULL ) ;
if ( V_48 ) {
F_144 ( V_501 ) ;
F_149 ( L_42 ) ;
return V_48 ;
}
return 0 ;
}
void F_150 ( struct V_502 * V_29 )
{
struct V_1 * V_2 = F_151 ( V_29 ) ;
F_140 ( V_2 ) ;
}
