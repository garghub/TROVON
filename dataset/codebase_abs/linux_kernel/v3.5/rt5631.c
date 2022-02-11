static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
F_2 ( V_2 , V_5 , V_3 ) ;
F_2 ( V_2 , V_6 , V_4 ) ;
}
static unsigned int F_3 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned int V_4 ;
F_2 ( V_2 , V_5 , V_3 ) ;
V_4 = F_4 ( V_2 , V_6 ) ;
return V_4 ;
}
static int F_5 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_7 , 0 ) ;
}
static bool F_6 ( struct V_8 * V_9 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_7 :
case V_10 :
case V_5 :
case V_6 :
case V_11 :
return 1 ;
default:
return 0 ;
}
}
static bool F_7 ( struct V_8 * V_9 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_7 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_10 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_5 :
case V_6 :
case V_11 :
case V_54 :
case V_55 :
case V_56 :
return 1 ;
default:
return 0 ;
}
}
static int F_8 ( struct V_57 * V_58 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = F_9 ( V_58 ) ;
struct V_61 * V_62 = F_10 ( V_2 ) ;
V_60 -> V_4 . integer . V_4 [ 0 ] = V_62 -> V_63 ;
return 0 ;
}
static int F_11 ( struct V_57 * V_58 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = F_9 ( V_58 ) ;
struct V_61 * V_62 = F_10 ( V_2 ) ;
V_62 -> V_63 = V_60 -> V_4 . integer . V_4 [ 0 ] ;
return 0 ;
}
static int F_12 ( struct V_64 * V_65 ,
struct V_64 * V_66 )
{
unsigned int V_3 ;
V_3 = F_4 ( V_65 -> V_2 , V_41 ) ;
return V_3 & V_67 ;
}
static int F_13 ( struct V_64 * V_65 ,
struct V_64 * V_66 )
{
struct V_61 * V_62 = F_10 ( V_65 -> V_2 ) ;
return V_62 -> V_63 ;
}
static int F_14 ( struct V_64 * V_65 ,
struct V_64 * V_66 )
{
unsigned int V_3 ;
V_3 = F_4 ( V_65 -> V_2 , V_23 ) ;
return ! ( V_3 & V_68 ) ;
}
static int F_15 ( struct V_64 * V_65 ,
struct V_64 * V_66 )
{
unsigned int V_3 ;
V_3 = F_4 ( V_65 -> V_2 , V_24 ) ;
return ! ( V_3 & V_69 ) ;
}
static int F_16 ( struct V_64 * V_65 ,
struct V_64 * V_66 )
{
unsigned int V_3 ;
V_3 = F_4 ( V_65 -> V_2 , V_30 ) ;
return ! ( V_3 & V_70 ) ;
}
static int F_17 ( struct V_64 * V_65 ,
struct V_64 * V_66 )
{
unsigned int V_3 ;
V_3 = F_4 ( V_65 -> V_2 , V_30 ) ;
return ! ( V_3 & V_71 ) ;
}
static int F_18 ( struct V_64 * V_65 ,
struct V_64 * V_66 )
{
unsigned int V_3 ;
V_3 = F_4 ( V_65 -> V_2 , V_20 ) ;
return ! ( V_3 & V_72 ) ;
}
static int F_19 ( struct V_64 * V_65 ,
struct V_64 * V_66 )
{
unsigned int V_3 ;
V_3 = F_4 ( V_65 -> V_2 , V_20 ) ;
return ! ( V_3 & V_73 ) ;
}
static void F_20 ( struct V_1 * V_2 , int V_74 )
{
unsigned int V_75 , V_76 ;
F_21 ( V_2 , V_47 ,
V_77 , 0 ) ;
V_75 = F_4 ( V_2 , V_49 ) ;
F_2 ( V_2 , V_49 , 0 ) ;
V_76 = F_4 ( V_2 , V_10 ) ;
F_2 ( V_2 , V_10 , V_76 & 0xf7ff ) ;
if ( V_74 ) {
F_1 ( V_2 , V_78 , 0x84c0 ) ;
F_1 ( V_2 , V_79 , 0x309f ) ;
F_1 ( V_2 , V_80 , 0x6530 ) ;
F_2 ( V_2 , V_47 ,
V_81 ) ;
} else {
F_2 ( V_2 , V_47 , 0 ) ;
F_22 ( 100 ) ;
}
F_2 ( V_2 , V_49 , V_75 ) ;
F_2 ( V_2 , V_10 , V_76 ) ;
}
static void F_23 ( struct V_1 * V_2 , int V_74 )
{
unsigned int V_75 , V_76 ;
F_21 ( V_2 , V_47 ,
V_77 , 0 ) ;
V_75 = F_4 ( V_2 , V_49 ) ;
F_2 ( V_2 , V_49 , 0 ) ;
V_76 = F_4 ( V_2 , V_10 ) ;
F_2 ( V_2 , V_10 , V_76 & 0xf7ff ) ;
if ( V_74 ) {
F_24 ( F_25 ( 10 ) ) ;
F_1 ( V_2 , V_79 , 0x307f ) ;
F_21 ( V_2 , V_13 ,
V_82 | V_83 , 0 ) ;
F_22 ( 300 ) ;
} else {
F_21 ( V_2 , V_13 ,
V_82 | V_83 ,
V_82 | V_83 ) ;
F_22 ( 100 ) ;
}
F_2 ( V_2 , V_49 , V_75 ) ;
F_2 ( V_2 , V_10 , V_76 ) ;
}
static void F_26 ( struct V_1 * V_2 , int V_74 )
{
unsigned int V_75 , V_76 ;
F_21 ( V_2 , V_47 ,
V_77 , V_77 ) ;
V_75 = F_4 ( V_2 , V_49 ) ;
F_2 ( V_2 , V_49 , 0 ) ;
V_76 = F_4 ( V_2 , V_10 ) ;
F_2 ( V_2 , V_10 , V_76 & 0xf7ff ) ;
if ( V_74 ) {
F_1 ( V_2 , V_79 , 0x303e ) ;
F_21 ( V_2 , V_38 ,
V_84 | V_85 |
V_86 ,
V_84 | V_85 |
V_86 ) ;
F_2 ( V_2 , V_46 ,
V_87 | V_88 ) ;
F_22 ( 100 ) ;
F_21 ( V_2 , V_38 ,
V_89 , V_89 ) ;
} else {
F_1 ( V_2 , V_79 , 0x303F ) ;
F_2 ( V_2 , V_46 ,
V_87 | V_90 |
V_91 | V_92 ) ;
F_22 ( 75 ) ;
F_2 ( V_2 , V_46 ,
V_87 | V_91 |
V_92 ) ;
F_21 ( V_2 , V_38 ,
V_89 , 0 ) ;
F_2 ( V_2 , V_46 ,
V_87 | V_88 |
V_91 | V_92 ) ;
F_22 ( 80 ) ;
F_2 ( V_2 , V_46 ,
V_87 ) ;
F_21 ( V_2 , V_38 ,
V_84 | V_85 |
V_86 , 0 ) ;
}
F_2 ( V_2 , V_49 , V_75 ) ;
F_2 ( V_2 , V_10 , V_76 ) ;
}
static void F_27 ( struct V_1 * V_2 , int V_74 )
{
unsigned int V_75 , V_76 ;
F_21 ( V_2 , V_47 ,
V_77 , V_77 ) ;
V_75 = F_4 ( V_2 , V_49 ) ;
F_2 ( V_2 , V_49 , 0 ) ;
V_76 = F_4 ( V_2 , V_10 ) ;
F_2 ( V_2 , V_10 , V_76 & 0xf7ff ) ;
if ( V_74 ) {
F_24 ( F_25 ( 10 ) ) ;
F_1 ( V_2 , V_79 , 0x302f ) ;
F_2 ( V_2 , V_46 ,
V_87 | V_90 |
V_93 |
V_94 ) ;
F_21 ( V_2 , V_13 ,
V_82 | V_83 , 0 ) ;
F_22 ( 160 ) ;
} else {
F_1 ( V_2 , V_79 , 0x302f ) ;
F_2 ( V_2 , V_46 ,
V_87 | V_90 |
V_93 |
V_94 ) ;
F_21 ( V_2 , V_13 ,
V_82 | V_83 ,
V_82 | V_83 ) ;
F_22 ( 150 ) ;
}
F_2 ( V_2 , V_49 , V_75 ) ;
F_2 ( V_2 , V_10 , V_76 ) ;
}
static int F_28 ( struct V_64 * V_95 ,
struct V_57 * V_58 , int V_96 )
{
struct V_1 * V_2 = V_95 -> V_2 ;
struct V_61 * V_62 = F_10 ( V_2 ) ;
switch ( V_96 ) {
case V_97 :
if ( V_62 -> V_98 ) {
F_23 ( V_2 , 0 ) ;
F_20 ( V_2 , 0 ) ;
} else {
F_27 ( V_2 , 0 ) ;
F_26 ( V_2 , 0 ) ;
}
break;
case V_99 :
if ( V_62 -> V_98 ) {
F_20 ( V_2 , 1 ) ;
F_23 ( V_2 , 1 ) ;
} else {
F_26 ( V_2 , 1 ) ;
F_27 ( V_2 , 1 ) ;
}
break;
default:
break;
}
return 0 ;
}
static int F_29 ( struct V_64 * V_95 ,
struct V_57 * V_58 , int V_96 )
{
struct V_1 * V_2 = V_95 -> V_2 ;
struct V_61 * V_62 = F_10 ( V_2 ) ;
switch ( V_62 -> V_100 ) {
case 44100 :
case 48000 :
F_21 ( V_2 , V_28 ,
V_101 ,
V_102 ) ;
break;
case 32000 :
case 22050 :
F_21 ( V_2 , V_28 ,
V_101 ,
V_103 ) ;
break;
case 16000 :
case 11025 :
case 8000 :
F_21 ( V_2 , V_28 ,
V_101 ,
V_104 ) ;
break;
default:
return - V_105 ;
}
return 0 ;
}
static int F_30 ( int V_106 , int V_107 , int V_108 )
{
int V_109 ;
for ( V_109 = 0 ; V_109 < F_31 ( V_110 ) ; V_109 ++ ) {
if ( V_110 [ V_109 ] . V_106 == V_106 && V_110 [ V_109 ] . V_107 == V_107 &&
( V_110 [ V_109 ] . V_111 / V_110 [ V_109 ] . V_107 ) == V_108 )
return V_109 ;
}
return - V_105 ;
}
static int F_32 ( struct V_112 * V_113 ,
struct V_114 * V_115 , struct V_116 * V_117 )
{
struct V_1 * V_2 = V_117 -> V_2 ;
struct V_61 * V_62 = F_10 ( V_2 ) ;
int V_108 = 32 , V_118 ;
unsigned int V_119 = 0 ;
F_33 ( V_2 -> V_9 , L_1 , V_120 ) ;
V_62 -> V_121 = F_34 ( V_115 ) ;
if ( V_62 -> V_121 < 0 ) {
F_35 ( V_2 -> V_9 , L_2 ) ;
return V_62 -> V_121 ;
}
V_62 -> V_100 = F_36 ( V_115 ) ;
if ( V_62 -> V_122 )
V_118 = F_30 ( V_62 -> V_123 , V_62 -> V_100 ,
V_62 -> V_121 / V_62 -> V_100 ) ;
else
V_118 = F_30 ( V_62 -> V_123 , V_62 -> V_100 ,
V_108 ) ;
if ( V_118 < 0 ) {
F_35 ( V_2 -> V_9 , L_3 ) ;
return - V_105 ;
}
switch ( F_37 ( V_115 ) ) {
case V_124 :
break;
case V_125 :
V_119 |= V_126 ;
break;
case V_127 :
V_119 |= V_128 ;
break;
case V_129 :
V_119 |= V_130 ;
break;
default:
return - V_105 ;
}
F_21 ( V_2 , V_33 ,
V_131 , V_119 ) ;
F_2 ( V_2 , V_35 ,
V_110 [ V_118 ] . V_132 ) ;
return 0 ;
}
static int F_38 ( struct V_116 * V_133 ,
unsigned int V_134 )
{
struct V_1 * V_2 = V_133 -> V_2 ;
struct V_61 * V_62 = F_10 ( V_2 ) ;
unsigned int V_119 = 0 ;
F_33 ( V_2 -> V_9 , L_1 , V_120 ) ;
switch ( V_134 & V_135 ) {
case V_136 :
V_62 -> V_122 = 1 ;
break;
case V_137 :
V_119 |= V_138 ;
V_62 -> V_122 = 0 ;
break;
default:
return - V_105 ;
}
switch ( V_134 & V_139 ) {
case V_140 :
break;
case V_141 :
V_119 |= V_142 ;
break;
case V_143 :
V_119 |= V_144 ;
break;
case V_145 :
V_119 |= V_146 ;
break;
default:
return - V_105 ;
}
switch ( V_134 & V_147 ) {
case V_148 :
break;
case V_149 :
V_119 |= V_150 ;
break;
default:
return - V_105 ;
}
F_2 ( V_2 , V_33 , V_119 ) ;
return 0 ;
}
static int F_39 ( struct V_116 * V_133 ,
int V_151 , unsigned int V_152 , int V_153 )
{
struct V_1 * V_2 = V_133 -> V_2 ;
struct V_61 * V_62 = F_10 ( V_2 ) ;
F_33 ( V_2 -> V_9 , L_4 , V_120 , V_152 ) ;
if ( ( V_152 >= ( 256 * 8000 ) ) && ( V_152 <= ( 512 * 96000 ) ) ) {
V_62 -> V_123 = V_152 ;
return 0 ;
}
return - V_105 ;
}
static int F_40 ( struct V_116 * V_133 , int V_154 ,
int V_65 , unsigned int V_155 , unsigned int V_156 )
{
struct V_1 * V_2 = V_133 -> V_2 ;
struct V_61 * V_62 = F_10 ( V_2 ) ;
int V_109 , V_157 = - V_105 ;
F_33 ( V_2 -> V_9 , L_1 , V_120 ) ;
if ( ! V_155 || ! V_156 ) {
F_33 ( V_2 -> V_9 , L_5 ) ;
F_21 ( V_2 , V_41 ,
V_158 ,
V_159 ) ;
return 0 ;
}
if ( V_62 -> V_122 ) {
for ( V_109 = 0 ; V_109 < F_31 ( V_160 ) ; V_109 ++ )
if ( V_155 == V_160 [ V_109 ] . V_161 &&
V_156 == V_160 [ V_109 ] . V_162 ) {
F_41 ( V_2 -> V_9 ,
L_6 ) ;
F_2 ( V_2 , V_42 ,
V_160 [ V_109 ] . V_132 ) ;
F_24 (
F_25 ( 20 ) ) ;
F_21 ( V_2 ,
V_41 ,
V_158 |
V_163 ,
V_67 |
V_164 ) ;
V_157 = 0 ;
break;
}
} else {
for ( V_109 = 0 ; V_109 < F_31 ( V_165 ) ; V_109 ++ )
if ( V_155 == V_165 [ V_109 ] . V_161 &&
V_156 == V_165 [ V_109 ] . V_162 ) {
F_41 ( V_2 -> V_9 ,
L_7 ) ;
F_2 ( V_2 , V_42 ,
V_165 [ V_109 ] . V_132 ) ;
F_24 (
F_25 ( 20 ) ) ;
F_21 ( V_2 ,
V_41 ,
V_158 |
V_163 ,
V_67 |
V_166 ) ;
V_157 = 0 ;
break;
}
}
return V_157 ;
}
static int F_42 ( struct V_1 * V_2 ,
enum V_167 V_168 )
{
struct V_61 * V_62 = F_10 ( V_2 ) ;
switch ( V_168 ) {
case V_169 :
case V_170 :
F_21 ( V_2 , V_37 ,
V_171 | V_172 ,
V_171 | V_172 ) ;
break;
case V_173 :
if ( V_2 -> V_174 . V_175 == V_176 ) {
F_21 ( V_2 , V_38 ,
V_177 | V_178 ,
V_177 | V_178 ) ;
F_22 ( 80 ) ;
F_21 ( V_2 , V_38 ,
V_179 ,
V_179 ) ;
F_43 ( V_62 -> V_180 , false ) ;
F_44 ( V_62 -> V_180 ) ;
}
break;
case V_176 :
F_2 ( V_2 , V_36 , 0x0000 ) ;
F_2 ( V_2 , V_37 , 0x0000 ) ;
F_2 ( V_2 , V_38 , 0x0000 ) ;
F_2 ( V_2 , V_39 , 0x0000 ) ;
break;
default:
break;
}
V_2 -> V_174 . V_175 = V_168 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = F_10 ( V_2 ) ;
unsigned int V_181 ;
int V_157 ;
V_2 -> V_182 = V_62 -> V_180 ;
V_157 = F_46 ( V_2 , 8 , 16 , V_183 ) ;
if ( V_157 != 0 ) {
F_35 ( V_2 -> V_9 , L_8 , V_157 ) ;
return V_157 ;
}
V_181 = F_3 ( V_2 , V_184 ) ;
if ( V_181 & 0x0002 )
V_62 -> V_98 = 1 ;
else
V_62 -> V_98 = 0 ;
F_5 ( V_2 ) ;
F_21 ( V_2 , V_38 ,
V_177 | V_178 ,
V_177 | V_178 ) ;
F_22 ( 80 ) ;
F_21 ( V_2 , V_38 ,
V_179 , V_179 ) ;
F_2 ( V_2 , V_10 , 0x0f18 ) ;
if ( V_62 -> V_98 )
F_21 ( V_2 , V_10 ,
0x2000 , 0x2000 ) ;
else
F_21 ( V_2 , V_10 ,
0x2000 , 0 ) ;
if ( V_62 -> V_63 ) {
F_21 ( V_2 , V_44 ,
V_185 |
V_186 ,
V_187 |
V_188 ) ;
F_21 ( V_2 , V_28 ,
V_189 |
V_190 ,
V_191 |
V_192 ) ;
}
V_2 -> V_174 . V_175 = V_173 ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
F_42 ( V_2 , V_176 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 )
{
F_42 ( V_2 , V_176 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
F_42 ( V_2 , V_173 ) ;
return 0 ;
}
static int F_50 ( struct V_193 * V_194 ,
const struct V_195 * V_196 )
{
struct V_61 * V_62 ;
int V_157 ;
V_62 = F_51 ( & V_194 -> V_9 , sizeof( struct V_61 ) ,
V_197 ) ;
if ( NULL == V_62 )
return - V_198 ;
F_52 ( V_194 , V_62 ) ;
V_62 -> V_180 = F_53 ( V_194 , & V_199 ) ;
if ( F_54 ( V_62 -> V_180 ) )
return F_55 ( V_62 -> V_180 ) ;
V_157 = F_56 ( & V_194 -> V_9 , & V_200 ,
V_201 , F_31 ( V_201 ) ) ;
return V_157 ;
}
static T_1 int F_57 ( struct V_193 * V_202 )
{
F_58 ( & V_202 -> V_9 ) ;
return 0 ;
}
