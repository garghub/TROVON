static void F_1 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_2 -> V_3 ;
const unsigned long long V_4 = 266000000 ;
const unsigned V_5 = 4600 ;
const unsigned V_6 = 5400 ;
const unsigned V_7 = 600 ;
const unsigned V_8 = 1300 ;
const unsigned V_9 = 1000 ;
const unsigned V_10 = 10 ;
unsigned long long V_11 ;
unsigned V_12 ;
V_11 = V_4 / V_10 ;
V_11 /= 1000 ;
F_2 ( V_3 , V_13 , 0 , 0 , 0 ) ;
if ( F_3 ( V_3 , V_13 ,
0 , 0 , 1 ) != 1 )
F_4 ( L_1 ) ;
F_2 ( V_3 , V_14 , 0 , 3 , 3 ) ;
V_12 = F_5 ( V_5 * V_11 , 1000000 ) ;
F_2 ( V_3 , V_15 ,
( V_12 >> 8 ) & 0xff , 7 , 0 ) ;
F_2 ( V_3 , V_16 ,
V_12 & 0xff , 7 , 0 ) ;
V_12 = F_5 ( V_6 * V_11 , 1000000 ) ;
F_2 ( V_3 , V_17 ,
( V_12 >> 8 ) & 0xff , 7 , 0 ) ;
F_2 ( V_3 , V_18 ,
V_12 & 0xff , 7 , 0 ) ;
V_12 = F_5 ( V_7 * V_11 , 1000000 ) ;
F_2 ( V_3 , V_19 ,
( V_12 >> 8 ) & 0xff , 7 , 0 ) ;
F_2 ( V_3 , V_20 ,
V_12 & 0xff , 7 , 0 ) ;
V_12 = F_5 ( V_8 * V_11 , 1000000 ) ;
F_2 ( V_3 , V_21 ,
( V_12 >> 8 ) & 0xff , 7 , 0 ) ;
F_2 ( V_3 , V_22 ,
V_12 & 0xff , 7 , 0 ) ;
V_12 = F_5 ( V_9 * V_11 , 1000000 ) ;
F_2 ( V_3 , V_23 , V_12 & 0xff , 7 , 0 ) ;
F_2 ( V_3 , V_24 , 0x50 , 6 , 0 ) ;
F_2 ( V_3 , V_25 , 0x30 , 6 , 0 ) ;
F_2 ( V_3 , V_26 , 0x1 , 7 , 7 ) ;
F_2 ( V_3 , V_26 , 0x0 , 6 , 6 ) ;
F_2 ( V_3 , V_26 , 0x1 , 3 , 3 ) ;
F_2 ( V_3 , V_26 , 0x0 , 2 , 2 ) ;
F_2 ( V_3 , V_27 , 0x1 , 3 , 3 ) ;
F_2 ( V_3 , V_27 , 0x0 , 2 , 2 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_2 -> V_3 ;
F_2 ( V_3 , V_26 , 0x1 , 6 , 6 ) ;
F_2 ( V_3 , V_26 , 0x1 , 2 , 2 ) ;
F_2 ( V_3 , V_27 , 0x1 , 2 , 2 ) ;
}
static int F_7 ( struct V_1 * V_2 , T_2 * V_28 , T_2 V_29 )
{
void T_1 * V_3 = V_2 -> V_3 ;
T_2 V_30 ;
char V_31 = 0 ;
const int V_32 = 1000 ;
T_2 V_33 = V_29 / 2 ;
T_2 V_34 = ( ( V_29 % 2 ) * 0x80 ) ;
F_2 ( V_3 , V_35 , V_33 , 7 , 0 ) ;
for ( V_30 = 0 ; V_30 < 128 ; ++ V_30 ) {
int V_36 ;
F_2 ( V_3 , V_37 , 0x3 , 1 , 0 ) ;
F_2 ( V_3 , V_38 ,
V_34 + V_30 , 7 , 0 ) ;
if ( V_33 )
F_2 ( V_3 , V_39 , 1 , 1 , 1 ) ;
else
F_2 ( V_3 , V_39 , 1 , 0 , 0 ) ;
for ( V_36 = 0 ; V_36 < V_32 ; ++ V_36 ) {
T_3 V_40 ;
V_40 = F_8 ( V_3 , V_37 , 1 , 0 ) ;
if ( V_40 & 1 ) {
F_4 ( L_2 ) ;
return - V_41 ;
}
if ( V_40 & ( 1 << 1 ) )
break;
F_9 ( 250 , 1000 ) ;
}
if ( V_36 == V_32 ) {
F_4 ( L_3 ) ;
return - V_41 ;
}
V_28 [ V_30 ] = F_8 ( V_3 , V_42 , 7 , 0 ) ;
V_31 += V_28 [ V_30 ] ;
}
return 0 ;
}
int F_10 ( struct V_1 * V_2 , T_2 * V_43 , int V_44 )
{
int V_45 , V_46 , V_36 ;
int V_47 = ( V_44 / 128 ) - 1 ;
if ( V_44 < 128 )
return - V_48 ;
F_1 ( V_2 ) ;
V_45 = F_7 ( V_2 , V_43 , 0 ) ;
if ( V_45 )
goto V_49;
V_46 = V_43 [ 0x7e ] ;
if ( V_46 > V_47 )
V_46 = V_47 ;
for ( V_36 = 1 ; V_36 <= V_46 ; V_36 ++ ) {
V_45 = F_7 ( V_2 , V_43 + V_36 * V_50 , V_36 ) ;
if ( V_45 )
goto V_49;
}
V_49:
F_6 ( V_2 ) ;
return V_45 ? V_45 : V_44 ;
}
void F_11 ( struct V_1 * V_2 , struct V_51 * V_52 )
{
#define F_12 ( V_45 ) seq_printf(s, "%-35s %08x\n", #r,\
hdmi_read_reg(core->base, r))
F_12 ( V_53 ) ;
F_12 ( V_54 ) ;
F_12 ( V_55 ) ;
F_12 ( V_56 ) ;
F_12 ( V_57 ) ;
F_12 ( V_58 ) ;
F_12 ( V_59 ) ;
F_12 ( V_60 ) ;
F_12 ( V_61 ) ;
F_12 ( V_62 ) ;
F_12 ( V_63 ) ;
F_12 ( V_64 ) ;
F_12 ( V_65 ) ;
F_12 ( V_66 ) ;
F_12 ( V_67 ) ;
F_12 ( V_68 ) ;
F_12 ( V_69 ) ;
F_12 ( V_70 ) ;
F_12 ( V_71 ) ;
F_12 ( V_72 ) ;
F_12 ( V_73 ) ;
F_12 ( V_74 ) ;
F_12 ( V_75 ) ;
F_12 ( V_76 ) ;
F_12 ( V_77 ) ;
F_12 ( V_78 ) ;
F_12 ( V_79 ) ;
F_12 ( V_80 ) ;
F_12 ( V_81 ) ;
F_12 ( V_82 ) ;
F_12 ( V_24 ) ;
F_12 ( V_38 ) ;
F_12 ( V_83 ) ;
F_12 ( V_42 ) ;
F_12 ( V_39 ) ;
F_12 ( V_27 ) ;
F_12 ( V_26 ) ;
F_12 ( V_14 ) ;
F_12 ( V_25 ) ;
F_12 ( V_13 ) ;
F_12 ( V_35 ) ;
F_12 ( V_15 ) ;
F_12 ( V_16 ) ;
F_12 ( V_17 ) ;
F_12 ( V_18 ) ;
F_12 ( V_19 ) ;
F_12 ( V_20 ) ;
F_12 ( V_21 ) ;
F_12 ( V_22 ) ;
F_12 ( V_23 ) ;
}
static void F_13 ( struct V_84 * V_85 ,
struct V_86 * V_87 )
{
F_14 ( L_4 ) ;
V_85 -> V_88 . V_89 = V_87 -> V_89 ;
V_85 -> V_90 = 1 ;
V_85 -> V_91 = V_87 -> V_89 . V_92 +
V_87 -> V_89 . V_93 + V_87 -> V_89 . V_94 ;
V_85 -> V_95 = 0 ;
V_85 -> V_96 = V_87 -> V_89 . V_97 + V_87 -> V_89 . V_98 +
V_87 -> V_89 . V_99 ;
V_85 -> V_88 . V_100 = V_87 -> V_100 ;
if ( V_87 -> V_89 . V_101 & V_102 ) {
if ( V_85 -> V_96 % 2 != 0 )
V_85 -> V_95 = 1 ;
V_85 -> V_88 . V_89 . V_103 /= 2 ;
V_85 -> V_96 /= 2 ;
V_85 -> V_88 . V_89 . V_98 /= 2 ;
V_85 -> V_88 . V_89 . V_97 /= 2 ;
V_85 -> V_88 . V_89 . V_99 /= 2 ;
}
if ( V_87 -> V_89 . V_101 & V_104 ) {
V_85 -> V_88 . V_89 . V_105 *= 2 ;
V_85 -> V_91 *= 2 ;
V_85 -> V_88 . V_89 . V_92 *= 2 ;
V_85 -> V_88 . V_89 . V_94 *= 2 ;
V_85 -> V_88 . V_89 . V_93 *= 2 ;
}
}
static void F_15 ( struct V_1 * V_2 ,
struct V_84 * V_87 )
{
void T_1 * V_3 = V_2 -> V_3 ;
struct V_106 * V_89 = & V_87 -> V_88 . V_89 ;
unsigned char V_45 = 0 ;
bool V_107 , V_108 ;
V_107 = ! ! ( V_89 -> V_101 & V_109 ) ;
V_108 = ! ! ( V_89 -> V_101 & V_110 ) ;
V_45 = F_16 ( V_3 , V_53 ) ;
V_45 = F_17 ( V_45 , V_107 , 6 , 6 ) ;
V_45 = F_17 ( V_45 , V_108 , 5 , 5 ) ;
V_45 = F_17 ( V_45 , V_87 -> V_90 , 4 , 4 ) ;
V_45 = F_17 ( V_45 , V_87 -> V_95 , 1 , 1 ) ;
V_45 = F_17 ( V_45 , ! ! ( V_89 -> V_101 & V_102 ) , 0 , 0 ) ;
F_18 ( V_3 , V_53 , V_45 ) ;
F_2 ( V_3 , V_55 , V_89 -> V_105 >> 8 , 4 , 0 ) ;
F_2 ( V_3 , V_54 , V_89 -> V_105 & 0xFF , 7 , 0 ) ;
F_2 ( V_3 , V_59 , V_89 -> V_103 >> 8 , 4 , 0 ) ;
F_2 ( V_3 , V_58 , V_89 -> V_103 & 0xFF , 7 , 0 ) ;
F_2 ( V_3 , V_57 , V_87 -> V_91 >> 8 , 4 , 0 ) ;
F_2 ( V_3 , V_56 , V_87 -> V_91 & 0xFF , 7 , 0 ) ;
F_2 ( V_3 , V_60 , V_87 -> V_96 , 7 , 0 ) ;
F_2 ( V_3 , V_62 , V_89 -> V_92 >> 8 ,
4 , 0 ) ;
F_2 ( V_3 , V_61 , V_89 -> V_92 & 0xFF ,
7 , 0 ) ;
F_2 ( V_3 , V_65 , V_89 -> V_98 , 7 , 0 ) ;
F_2 ( V_3 , V_64 , ( V_89 -> V_94 >> 8 ) ,
1 , 0 ) ;
F_2 ( V_3 , V_63 , V_89 -> V_94 & 0xFF ,
7 , 0 ) ;
F_2 ( V_3 , V_66 , V_89 -> V_97 , 5 , 0 ) ;
F_2 ( V_3 , V_53 ,
V_87 -> V_88 . V_100 , 3 , 3 ) ;
if ( V_89 -> V_101 & V_104 )
F_2 ( V_3 , V_77 , 2 , 7 , 4 ) ;
else
F_2 ( V_3 , V_77 , 1 , 7 , 4 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_2 -> V_3 ;
int V_111 = 0 ;
F_2 ( V_3 , V_112 , V_111 , 7 , 4 ) ;
F_2 ( V_3 , V_113 , V_111 ? 0 : 1 , 6 , 6 ) ;
F_2 ( V_3 , V_113 , V_111 ? 1 : 0 , 5 , 5 ) ;
F_2 ( V_3 , V_113 , 0 , 3 , 3 ) ;
F_2 ( V_3 , V_114 , V_111 ? 1 : 0 , 1 , 1 ) ;
F_2 ( V_3 , V_114 , 1 , 2 , 2 ) ;
F_2 ( V_3 , V_113 , V_111 ? 0 : 2 , 1 , 0 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
int V_111 = 0 ;
F_2 ( V_2 -> V_3 , V_115 , V_111 , 7 , 4 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
int V_116 = 1 ;
F_2 ( V_2 -> V_3 , V_117 , V_116 , 4 , 0 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_118 * V_119 )
{
void T_1 * V_3 = V_2 -> V_3 ;
T_2 V_120 [ F_23 ( V_121 ) ] ;
T_2 * V_122 ;
unsigned V_123 , V_124 , V_125 , V_52 ;
unsigned V_126 , V_127 , V_45 ;
unsigned V_128 , V_129 , V_130 , V_131 ;
unsigned V_132 ;
unsigned V_133 , V_134 , V_135 ;
F_24 ( V_119 , V_120 , sizeof( V_120 ) ) ;
F_25 ( L_5 , V_136 , 16 , 1 , V_120 ,
F_23 ( V_121 ) , false ) ;
V_122 = V_120 + V_137 ;
V_123 = ( V_122 [ 0 ] >> 5 ) & 0x3 ;
V_124 = ( V_122 [ 0 ] >> 4 ) & 0x1 ;
V_125 = ( V_122 [ 0 ] >> 2 ) & 0x3 ;
V_52 = ( V_122 [ 0 ] >> 0 ) & 0x3 ;
V_126 = ( V_122 [ 1 ] >> 6 ) & 0x3 ;
V_127 = ( V_122 [ 1 ] >> 4 ) & 0x3 ;
V_45 = ( V_122 [ 1 ] >> 0 ) & 0xf ;
V_128 = ( V_122 [ 2 ] >> 7 ) & 0x1 ;
V_129 = ( V_122 [ 2 ] >> 4 ) & 0x7 ;
V_130 = ( V_122 [ 2 ] >> 2 ) & 0x3 ;
V_131 = ( V_122 [ 2 ] >> 0 ) & 0x3 ;
V_132 = V_122 [ 3 ] ;
V_133 = ( V_122 [ 4 ] >> 6 ) & 0x3 ;
V_134 = ( V_122 [ 4 ] >> 4 ) & 0x3 ;
V_135 = ( V_122 [ 4 ] >> 0 ) & 0xf ;
F_18 ( V_3 , V_73 ,
( V_124 << 6 ) | ( V_52 << 4 ) | ( V_125 << 2 ) | ( V_123 << 0 ) ) ;
F_18 ( V_3 , V_74 ,
( V_126 << 6 ) | ( V_127 << 4 ) | ( V_45 << 0 ) ) ;
F_18 ( V_3 , V_75 ,
( V_128 << 7 ) | ( V_129 << 4 ) | ( V_130 << 2 ) | ( V_131 << 0 ) ) ;
F_18 ( V_3 , V_76 , V_132 ) ;
F_18 ( V_3 , V_138 ,
( V_133 << 2 ) | ( V_134 << 0 ) ) ;
F_2 ( V_3 , V_77 , V_135 , 3 , 0 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_139 V_140 )
{
void T_1 * V_3 = V_2 -> V_3 ;
F_2 ( V_3 , V_141 , V_140 . V_142 >> 8 , 6 , 0 ) ;
F_2 ( V_3 , V_143 , V_140 . V_142 , 7 , 0 ) ;
F_2 ( V_3 , V_144 , V_140 . V_145 >> 8 , 6 , 0 ) ;
F_2 ( V_3 , V_146 , V_140 . V_145 , 7 , 0 ) ;
F_2 ( V_3 , V_147 , V_140 . V_148 >> 8 , 6 , 0 ) ;
F_2 ( V_3 , V_149 , V_140 . V_148 , 7 , 0 ) ;
F_2 ( V_3 , V_150 , V_140 . V_151 >> 8 , 6 , 0 ) ;
F_2 ( V_3 , V_152 , V_140 . V_151 , 7 , 0 ) ;
F_2 ( V_3 , V_153 , V_140 . V_154 >> 8 , 6 , 0 ) ;
F_2 ( V_3 , V_155 , V_140 . V_154 , 7 , 0 ) ;
F_2 ( V_3 , V_156 , V_140 . V_157 >> 8 , 6 , 0 ) ;
F_2 ( V_3 , V_158 , V_140 . V_157 , 7 , 0 ) ;
F_2 ( V_3 , V_159 , V_140 . V_160 >> 8 , 6 , 0 ) ;
F_2 ( V_3 , V_161 , V_140 . V_160 , 7 , 0 ) ;
F_2 ( V_3 , V_162 , V_140 . V_163 >> 8 , 6 , 0 ) ;
F_2 ( V_3 , V_164 , V_140 . V_163 , 7 , 0 ) ;
F_2 ( V_3 , V_165 , V_140 . V_166 >> 8 , 6 , 0 ) ;
F_2 ( V_3 , V_167 , V_140 . V_166 , 7 , 0 ) ;
F_2 ( V_3 , V_168 , V_140 . V_169 >> 8 , 6 , 0 ) ;
F_2 ( V_3 , V_170 , V_140 . V_169 , 7 , 0 ) ;
F_2 ( V_3 , V_171 , V_140 . V_172 >> 8 , 6 , 0 ) ;
F_2 ( V_3 , V_173 , V_140 . V_172 , 7 , 0 ) ;
F_2 ( V_3 , V_174 , V_140 . V_175 >> 8 , 6 , 0 ) ;
F_2 ( V_3 , V_176 , V_140 . V_175 , 7 , 0 ) ;
F_2 ( V_3 , V_80 , 0x1 , 0 , 0 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_139 V_140 = { 0 } ;
V_140 = V_177 [ 0 ] ;
F_26 ( V_2 , V_140 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_2 -> V_3 ;
F_14 ( L_6 ) ;
F_2 ( V_3 , V_67 , 0x0C , 7 , 0 ) ;
F_2 ( V_3 , V_68 , 0x20 , 7 , 0 ) ;
F_2 ( V_3 , V_69 , 0x01 , 7 , 0 ) ;
F_2 ( V_3 , V_70 , 0x0B , 7 , 0 ) ;
F_2 ( V_3 , V_71 , 0x16 , 5 , 0 ) ;
F_2 ( V_3 , V_72 , 0x21 , 5 , 0 ) ;
F_2 ( V_3 , V_78 , 0x00 , 0 , 0 ) ;
F_2 ( V_3 , V_78 , 0x00 , 1 , 1 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_2 -> V_3 ;
F_2 ( V_3 , V_178 , 0x3 , 1 , 0 ) ;
F_2 ( V_3 , V_179 , 0xff , 7 , 0 ) ;
F_2 ( V_3 , V_180 , 0xe7 , 7 , 0 ) ;
F_2 ( V_3 , V_181 , 0xfb , 7 , 0 ) ;
F_2 ( V_3 , V_182 , 0x3 , 1 , 0 ) ;
F_2 ( V_3 , V_183 , 0x3 , 3 , 2 ) ;
F_2 ( V_3 , V_184 , 0x3 , 1 , 0 ) ;
F_2 ( V_3 , V_185 , 0x7f , 6 , 0 ) ;
F_2 ( V_3 , V_26 , 0x1 , 6 , 6 ) ;
F_2 ( V_3 , V_26 , 0x1 , 2 , 2 ) ;
F_2 ( V_3 , V_27 , 0x1 , 2 , 2 ) ;
F_2 ( V_3 , V_186 , 0xf3 , 7 , 0 ) ;
F_2 ( V_3 , V_187 , 0xff , 7 , 0 ) ;
F_2 ( V_3 , V_188 , 0xff , 7 , 0 ) ;
F_2 ( V_3 , V_189 , 0xe7 , 7 , 0 ) ;
F_2 ( V_3 , V_190 , 0xfb , 7 , 0 ) ;
F_2 ( V_3 , V_191 , 0x3 , 1 , 0 ) ;
F_2 ( V_3 , V_192 , 0x7 , 2 , 0 ) ;
F_2 ( V_3 , V_193 , 0x7f , 6 , 0 ) ;
F_2 ( V_3 , V_37 , 0x3 , 1 , 0 ) ;
F_2 ( V_3 , V_187 , 0xff , 7 , 0 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_178 , 0x0 , 1 , 0 ) ;
}
int F_31 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_2 -> V_3 ;
F_2 ( V_3 , V_189 , 0xff , 7 , 0 ) ;
F_2 ( V_3 , V_190 , 0xff , 7 , 0 ) ;
F_2 ( V_3 , V_191 , 0xff , 7 , 0 ) ;
F_2 ( V_3 , V_192 , 0xff , 7 , 0 ) ;
F_2 ( V_3 , V_187 , 0xff , 7 , 0 ) ;
F_2 ( V_3 , V_37 , 0xff , 7 , 0 ) ;
F_2 ( V_3 , V_193 , 0xff , 7 , 0 ) ;
F_2 ( V_3 , V_188 , 0xff , 7 , 0 ) ;
F_2 ( V_3 , V_194 , 0xff , 7 , 0 ) ;
return 0 ;
}
void F_32 ( struct V_1 * V_2 , struct V_195 * V_196 ,
struct V_86 * V_87 )
{
struct V_106 V_89 ;
struct V_197 V_198 ;
struct V_84 V_199 ;
F_29 ( V_2 ) ;
F_13 ( & V_199 , V_87 ) ;
F_33 ( & V_198 , & V_89 , V_87 ) ;
F_34 ( V_196 , & V_89 ) ;
V_198 . V_200 = V_201 ;
F_35 ( V_196 , & V_198 ) ;
F_36 ( V_196 , & V_89 ) ;
F_27 ( V_2 ) ;
V_87 -> V_202 . V_203 = V_204 ;
V_199 . V_205 = V_206 ;
F_15 ( V_2 , & V_199 ) ;
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
if ( V_87 -> V_100 == V_207 )
F_22 ( V_2 , & V_87 -> V_202 ) ;
F_28 ( V_2 ) ;
F_30 ( V_2 ) ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_208 * V_87 )
{
void T_1 * V_3 = V_2 -> V_3 ;
T_2 V_209 ;
F_2 ( V_3 , V_210 , 0xf , 7 , 4 ) ;
F_2 ( V_3 , V_211 , V_87 -> V_46 , 7 , 0 ) ;
F_2 ( V_3 , V_212 , V_87 -> V_46 >> 8 , 7 , 0 ) ;
F_2 ( V_3 , V_213 , V_87 -> V_46 >> 16 , 3 , 0 ) ;
F_2 ( V_3 , V_214 , 1 , 4 , 4 ) ;
F_2 ( V_3 , V_215 , V_87 -> V_216 , 7 , 0 ) ;
F_2 ( V_3 , V_217 , V_87 -> V_216 >> 8 , 7 , 0 ) ;
F_2 ( V_3 , V_214 , V_87 -> V_216 >> 16 , 3 , 0 ) ;
if ( V_87 -> V_218 == V_219 )
F_2 ( V_3 , V_210 , 0 , 0 , 0 ) ;
else
F_2 ( V_3 , V_210 , 1 , 0 , 0 ) ;
F_2 ( V_3 , V_220 , 0 , 0 , 0 ) ;
F_2 ( V_3 , V_220 , 0 , 4 , 4 ) ;
if ( V_87 -> V_218 == V_219 )
V_209 = 1 ;
else
V_209 = 0 ;
F_2 ( V_3 , V_220 , V_209 , 1 , 1 ) ;
F_2 ( V_3 , V_220 , V_209 , 5 , 5 ) ;
F_2 ( V_3 , V_220 , V_209 , 2 , 2 ) ;
F_2 ( V_3 , V_220 , V_209 , 6 , 6 ) ;
if ( V_87 -> V_218 == V_221 )
V_209 = 1 ;
F_2 ( V_3 , V_220 , V_209 , 3 , 3 ) ;
F_2 ( V_3 , V_220 , V_209 , 7 , 7 ) ;
F_2 ( V_3 , V_222 , 0 , 7 , 0 ) ;
V_209 = V_87 -> V_223 -> V_224 [ 5 ] & V_225 ;
F_2 ( V_3 , F_38 ( 0 ) , V_209 , 5 , 4 ) ;
V_209 = ( V_87 -> V_223 -> V_224 [ 0 ] &
V_226 ) >> 2 ;
F_2 ( V_3 , F_38 ( 0 ) , V_209 , 0 , 0 ) ;
F_18 ( V_3 , F_38 ( 1 ) ,
V_87 -> V_223 -> V_224 [ 1 ] ) ;
V_209 = ( V_87 -> V_223 -> V_224 [ 0 ] & V_227 ) >> 6 ;
F_2 ( V_3 , F_38 ( 2 ) , V_209 , 6 , 4 ) ;
V_209 = V_87 -> V_223 -> V_224 [ 2 ] & V_228 ;
F_2 ( V_3 , F_38 ( 2 ) , V_209 , 3 , 0 ) ;
F_2 ( V_3 , F_38 ( 3 ) , 2 , 3 , 0 ) ;
F_2 ( V_3 , F_38 ( 3 ) , 4 , 7 , 4 ) ;
F_2 ( V_3 , F_38 ( 4 ) , 6 , 3 , 0 ) ;
F_2 ( V_3 , F_38 ( 4 ) , 8 , 7 , 4 ) ;
F_2 ( V_3 , F_38 ( 5 ) , 1 , 3 , 0 ) ;
F_2 ( V_3 , F_38 ( 5 ) , 3 , 7 , 4 ) ;
F_2 ( V_3 , F_38 ( 6 ) , 5 , 3 , 0 ) ;
F_2 ( V_3 , F_38 ( 6 ) , 7 , 7 , 4 ) ;
F_18 ( V_3 , F_38 ( 7 ) ,
V_87 -> V_223 -> V_224 [ 3 ] ) ;
F_18 ( V_3 , F_38 ( 8 ) ,
V_87 -> V_223 -> V_224 [ 4 ] ) ;
F_2 ( V_3 , V_183 , 3 , 3 , 2 ) ;
if ( V_87 -> V_218 == V_219 ) {
F_2 ( V_3 , V_229 , 0 , 5 , 5 ) ;
F_2 ( V_3 , V_230 , 3 , 7 , 0 ) ;
} else if ( V_87 -> V_218 == V_221 ) {
F_2 ( V_3 , V_229 , 0 , 5 , 5 ) ;
F_2 ( V_3 , V_230 , 0x3F , 7 , 0 ) ;
} else {
F_2 ( V_3 , V_229 , 0 , 5 , 5 ) ;
F_2 ( V_3 , V_230 , 0xFF , 7 , 0 ) ;
}
F_2 ( V_3 , V_231 , 0 , 0 , 0 ) ;
F_2 ( V_3 , V_231 , 1 , 1 , 1 ) ;
F_2 ( V_3 , V_184 , 3 , 1 , 0 ) ;
F_2 ( V_3 , V_232 , 1 , 0 , 0 ) ;
F_2 ( V_3 , V_210 , 0 , 7 , 4 ) ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_233 * V_234 )
{
void T_1 * V_3 = V_2 -> V_3 ;
F_18 ( V_3 , V_235 ,
( V_234 -> V_236 & V_237 ) << 4 |
( V_234 -> V_236 & V_238 ) >> 4 ) ;
F_18 ( V_3 , V_239 , V_234 -> V_240 ) ;
F_18 ( V_3 , V_241 , V_234 -> V_242 ) ;
F_18 ( V_3 , V_243 ,
( V_234 -> V_244 & V_245 ) >> 3 |
( V_234 -> V_244 & V_246 ) ) ;
}
int F_40 ( struct V_1 * V_2 , struct V_195 * V_196 ,
struct V_247 * V_248 , T_3 V_249 )
{
struct V_250 V_251 ;
struct V_252 V_253 ;
struct V_208 V_254 ;
int V_255 , V_46 , V_216 , V_256 ;
unsigned int V_257 ;
bool V_258 = false ;
if ( ! V_248 || ! V_248 -> V_259 || ! V_248 -> V_260 || ! V_2 )
return - V_48 ;
V_254 . V_223 = V_248 -> V_259 ;
if ( ! ( V_248 -> V_259 -> V_224 [ 4 ] & V_261 ) &&
( V_248 -> V_259 -> V_224 [ 4 ] & V_262 ) )
V_258 = true ;
if ( ! V_258 )
return - V_48 ;
switch ( V_248 -> V_259 -> V_224 [ 3 ] & V_263 ) {
case V_264 :
V_257 = 32000 ;
break;
case V_265 :
V_257 = 44100 ;
break;
case V_266 :
V_257 = 48000 ;
break;
case V_267 :
V_257 = 88200 ;
break;
case V_268 :
V_257 = 96000 ;
break;
case V_269 :
V_257 = 176400 ;
break;
case V_270 :
V_257 = 192000 ;
break;
default:
return - V_48 ;
}
V_255 = F_41 ( V_249 , V_257 , & V_46 , & V_216 ) ;
V_254 . V_46 = V_46 ;
V_254 . V_216 = V_216 ;
V_256 = ( V_248 -> V_260 -> V_236 & V_237 )
+ 1 ;
if ( V_256 == 2 )
V_254 . V_218 = V_219 ;
else if ( V_256 == 6 )
V_254 . V_218 = V_221 ;
else
V_254 . V_218 = V_271 ;
if ( V_258 )
V_253 . V_272 = 0x10 ;
else
V_253 . V_272 = 0x20 ;
V_253 . V_273 = 0xC0 ;
V_253 . V_274 = V_275 ;
V_253 . V_276 = 0x20 ;
V_251 . V_277 = V_278 ;
V_251 . V_279 = V_280 ;
V_251 . V_281 = V_282 ;
V_251 . V_283 = V_284 ;
V_251 . type = V_285 ;
V_251 . V_283 = V_284 ;
V_251 . V_286 = V_287 ;
F_42 ( V_196 , & V_253 ) ;
F_43 ( V_196 , & V_251 ) ;
F_37 ( V_2 , & V_254 ) ;
F_39 ( V_2 , V_248 -> V_260 ) ;
return 0 ;
}
int F_44 ( struct V_288 * V_289 , struct V_1 * V_2 )
{
struct V_290 * V_291 ;
V_291 = F_45 ( V_289 , V_292 , L_7 ) ;
if ( ! V_291 ) {
F_4 ( L_8 ) ;
return - V_48 ;
}
V_2 -> V_3 = F_46 ( & V_289 -> V_293 , V_291 ) ;
if ( F_47 ( V_2 -> V_3 ) ) {
F_4 ( L_9 ) ;
return F_48 ( V_2 -> V_3 ) ;
}
return 0 ;
}
