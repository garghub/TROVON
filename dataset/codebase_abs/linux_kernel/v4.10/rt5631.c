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
struct V_1 * V_2 = F_13 ( V_65 -> V_67 ) ;
unsigned int V_3 ;
V_3 = F_4 ( V_2 , V_41 ) ;
return V_3 & V_68 ;
}
static int F_14 ( struct V_64 * V_65 ,
struct V_64 * V_66 )
{
struct V_1 * V_2 = F_13 ( V_65 -> V_67 ) ;
struct V_61 * V_62 = F_10 ( V_2 ) ;
return V_62 -> V_63 ;
}
static int F_15 ( struct V_64 * V_65 ,
struct V_64 * V_66 )
{
struct V_1 * V_2 = F_13 ( V_65 -> V_67 ) ;
unsigned int V_3 ;
V_3 = F_4 ( V_2 , V_23 ) ;
return ! ( V_3 & V_69 ) ;
}
static int F_16 ( struct V_64 * V_65 ,
struct V_64 * V_66 )
{
struct V_1 * V_2 = F_13 ( V_65 -> V_67 ) ;
unsigned int V_3 ;
V_3 = F_4 ( V_2 , V_24 ) ;
return ! ( V_3 & V_70 ) ;
}
static int F_17 ( struct V_64 * V_65 ,
struct V_64 * V_66 )
{
struct V_1 * V_2 = F_13 ( V_65 -> V_67 ) ;
unsigned int V_3 ;
V_3 = F_4 ( V_2 , V_30 ) ;
return ! ( V_3 & V_71 ) ;
}
static int F_18 ( struct V_64 * V_65 ,
struct V_64 * V_66 )
{
struct V_1 * V_2 = F_13 ( V_65 -> V_67 ) ;
unsigned int V_3 ;
V_3 = F_4 ( V_2 , V_30 ) ;
return ! ( V_3 & V_72 ) ;
}
static int F_19 ( struct V_64 * V_65 ,
struct V_64 * V_66 )
{
struct V_1 * V_2 = F_13 ( V_65 -> V_67 ) ;
unsigned int V_3 ;
V_3 = F_4 ( V_2 , V_20 ) ;
return ! ( V_3 & V_73 ) ;
}
static int F_20 ( struct V_64 * V_65 ,
struct V_64 * V_66 )
{
struct V_1 * V_2 = F_13 ( V_65 -> V_67 ) ;
unsigned int V_3 ;
V_3 = F_4 ( V_2 , V_20 ) ;
return ! ( V_3 & V_74 ) ;
}
static void F_21 ( struct V_1 * V_2 , int V_75 )
{
unsigned int V_76 , V_77 ;
F_22 ( V_2 , V_47 ,
V_78 , 0 ) ;
V_76 = F_4 ( V_2 , V_49 ) ;
F_2 ( V_2 , V_49 , 0 ) ;
V_77 = F_4 ( V_2 , V_10 ) ;
F_2 ( V_2 , V_10 , V_77 & 0xf7ff ) ;
if ( V_75 ) {
F_1 ( V_2 , V_79 , 0x84c0 ) ;
F_1 ( V_2 , V_80 , 0x309f ) ;
F_1 ( V_2 , V_81 , 0x6530 ) ;
F_2 ( V_2 , V_47 ,
V_82 ) ;
} else {
F_2 ( V_2 , V_47 , 0 ) ;
F_23 ( 100 ) ;
}
F_2 ( V_2 , V_49 , V_76 ) ;
F_2 ( V_2 , V_10 , V_77 ) ;
}
static void F_24 ( struct V_1 * V_2 , int V_75 )
{
unsigned int V_76 , V_77 ;
F_22 ( V_2 , V_47 ,
V_78 , 0 ) ;
V_76 = F_4 ( V_2 , V_49 ) ;
F_2 ( V_2 , V_49 , 0 ) ;
V_77 = F_4 ( V_2 , V_10 ) ;
F_2 ( V_2 , V_10 , V_77 & 0xf7ff ) ;
if ( V_75 ) {
F_25 ( F_26 ( 10 ) ) ;
F_1 ( V_2 , V_80 , 0x307f ) ;
F_22 ( V_2 , V_13 ,
V_83 | V_84 , 0 ) ;
F_23 ( 300 ) ;
} else {
F_22 ( V_2 , V_13 ,
V_83 | V_84 ,
V_83 | V_84 ) ;
F_23 ( 100 ) ;
}
F_2 ( V_2 , V_49 , V_76 ) ;
F_2 ( V_2 , V_10 , V_77 ) ;
}
static void F_27 ( struct V_1 * V_2 , int V_75 )
{
unsigned int V_76 , V_77 ;
F_22 ( V_2 , V_47 ,
V_78 , V_78 ) ;
V_76 = F_4 ( V_2 , V_49 ) ;
F_2 ( V_2 , V_49 , 0 ) ;
V_77 = F_4 ( V_2 , V_10 ) ;
F_2 ( V_2 , V_10 , V_77 & 0xf7ff ) ;
if ( V_75 ) {
F_1 ( V_2 , V_80 , 0x303e ) ;
F_22 ( V_2 , V_38 ,
V_85 | V_86 |
V_87 ,
V_85 | V_86 |
V_87 ) ;
F_2 ( V_2 , V_46 ,
V_88 | V_89 ) ;
F_23 ( 100 ) ;
F_22 ( V_2 , V_38 ,
V_90 , V_90 ) ;
} else {
F_1 ( V_2 , V_80 , 0x303F ) ;
F_2 ( V_2 , V_46 ,
V_88 | V_91 |
V_92 | V_93 ) ;
F_23 ( 75 ) ;
F_2 ( V_2 , V_46 ,
V_88 | V_92 |
V_93 ) ;
F_22 ( V_2 , V_38 ,
V_90 , 0 ) ;
F_2 ( V_2 , V_46 ,
V_88 | V_89 |
V_92 | V_93 ) ;
F_23 ( 80 ) ;
F_2 ( V_2 , V_46 ,
V_88 ) ;
F_22 ( V_2 , V_38 ,
V_85 | V_86 |
V_87 , 0 ) ;
}
F_2 ( V_2 , V_49 , V_76 ) ;
F_2 ( V_2 , V_10 , V_77 ) ;
}
static void F_28 ( struct V_1 * V_2 , int V_75 )
{
unsigned int V_76 , V_77 ;
F_22 ( V_2 , V_47 ,
V_78 , V_78 ) ;
V_76 = F_4 ( V_2 , V_49 ) ;
F_2 ( V_2 , V_49 , 0 ) ;
V_77 = F_4 ( V_2 , V_10 ) ;
F_2 ( V_2 , V_10 , V_77 & 0xf7ff ) ;
if ( V_75 ) {
F_25 ( F_26 ( 10 ) ) ;
F_1 ( V_2 , V_80 , 0x302f ) ;
F_2 ( V_2 , V_46 ,
V_88 | V_91 |
V_94 |
V_95 ) ;
F_22 ( V_2 , V_13 ,
V_83 | V_84 , 0 ) ;
F_23 ( 160 ) ;
} else {
F_1 ( V_2 , V_80 , 0x302f ) ;
F_2 ( V_2 , V_46 ,
V_88 | V_91 |
V_94 |
V_95 ) ;
F_22 ( V_2 , V_13 ,
V_83 | V_84 ,
V_83 | V_84 ) ;
F_23 ( 150 ) ;
}
F_2 ( V_2 , V_49 , V_76 ) ;
F_2 ( V_2 , V_10 , V_77 ) ;
}
static int F_29 ( struct V_64 * V_96 ,
struct V_57 * V_58 , int V_97 )
{
struct V_1 * V_2 = F_13 ( V_96 -> V_67 ) ;
struct V_61 * V_62 = F_10 ( V_2 ) ;
switch ( V_97 ) {
case V_98 :
if ( V_62 -> V_99 ) {
F_24 ( V_2 , 0 ) ;
F_21 ( V_2 , 0 ) ;
} else {
F_28 ( V_2 , 0 ) ;
F_27 ( V_2 , 0 ) ;
}
break;
case V_100 :
if ( V_62 -> V_99 ) {
F_21 ( V_2 , 1 ) ;
F_24 ( V_2 , 1 ) ;
} else {
F_27 ( V_2 , 1 ) ;
F_28 ( V_2 , 1 ) ;
}
break;
default:
break;
}
return 0 ;
}
static int F_30 ( struct V_64 * V_96 ,
struct V_57 * V_58 , int V_97 )
{
struct V_1 * V_2 = F_13 ( V_96 -> V_67 ) ;
struct V_61 * V_62 = F_10 ( V_2 ) ;
switch ( V_62 -> V_101 ) {
case 44100 :
case 48000 :
F_22 ( V_2 , V_28 ,
V_102 ,
V_103 ) ;
break;
case 32000 :
case 22050 :
F_22 ( V_2 , V_28 ,
V_102 ,
V_104 ) ;
break;
case 16000 :
case 11025 :
case 8000 :
F_22 ( V_2 , V_28 ,
V_102 ,
V_105 ) ;
break;
default:
return - V_106 ;
}
return 0 ;
}
static int F_31 ( int V_107 , int V_108 , int V_109 )
{
int V_110 ;
for ( V_110 = 0 ; V_110 < F_32 ( V_111 ) ; V_110 ++ ) {
if ( V_111 [ V_110 ] . V_107 == V_107 && V_111 [ V_110 ] . V_108 == V_108 &&
( V_111 [ V_110 ] . V_112 / V_111 [ V_110 ] . V_108 ) == V_109 )
return V_110 ;
}
return - V_106 ;
}
static int F_33 ( struct V_113 * V_114 ,
struct V_115 * V_116 , struct V_117 * V_118 )
{
struct V_1 * V_2 = V_118 -> V_2 ;
struct V_61 * V_62 = F_10 ( V_2 ) ;
int V_109 = 32 , V_119 ;
unsigned int V_120 = 0 ;
F_34 ( V_2 -> V_9 , L_1 , V_121 ) ;
V_62 -> V_122 = F_35 ( V_116 ) ;
if ( V_62 -> V_122 < 0 ) {
F_36 ( V_2 -> V_9 , L_2 ) ;
return V_62 -> V_122 ;
}
V_62 -> V_101 = F_37 ( V_116 ) ;
if ( V_62 -> V_123 )
V_119 = F_31 ( V_62 -> V_124 , V_62 -> V_101 ,
V_62 -> V_122 / V_62 -> V_101 ) ;
else
V_119 = F_31 ( V_62 -> V_124 , V_62 -> V_101 ,
V_109 ) ;
if ( V_119 < 0 ) {
F_36 ( V_2 -> V_9 , L_3 ) ;
return V_119 ;
}
switch ( F_38 ( V_116 ) ) {
case 16 :
break;
case 20 :
V_120 |= V_125 ;
break;
case 24 :
V_120 |= V_126 ;
break;
case 8 :
V_120 |= V_127 ;
break;
default:
return - V_106 ;
}
F_22 ( V_2 , V_33 ,
V_128 , V_120 ) ;
F_2 ( V_2 , V_35 ,
V_111 [ V_119 ] . V_129 ) ;
return 0 ;
}
static int F_39 ( struct V_117 * V_130 ,
unsigned int V_131 )
{
struct V_1 * V_2 = V_130 -> V_2 ;
struct V_61 * V_62 = F_10 ( V_2 ) ;
unsigned int V_120 = 0 ;
F_34 ( V_2 -> V_9 , L_1 , V_121 ) ;
switch ( V_131 & V_132 ) {
case V_133 :
V_62 -> V_123 = 1 ;
break;
case V_134 :
V_120 |= V_135 ;
V_62 -> V_123 = 0 ;
break;
default:
return - V_106 ;
}
switch ( V_131 & V_136 ) {
case V_137 :
break;
case V_138 :
V_120 |= V_139 ;
break;
case V_140 :
V_120 |= V_141 ;
break;
case V_142 :
V_120 |= V_143 ;
break;
default:
return - V_106 ;
}
switch ( V_131 & V_144 ) {
case V_145 :
break;
case V_146 :
V_120 |= V_147 ;
break;
default:
return - V_106 ;
}
F_2 ( V_2 , V_33 , V_120 ) ;
return 0 ;
}
static int F_40 ( struct V_117 * V_130 ,
int V_148 , unsigned int V_149 , int V_150 )
{
struct V_1 * V_2 = V_130 -> V_2 ;
struct V_61 * V_62 = F_10 ( V_2 ) ;
F_34 ( V_2 -> V_9 , L_4 , V_121 , V_149 ) ;
if ( ( V_149 >= ( 256 * 8000 ) ) && ( V_149 <= ( 512 * 96000 ) ) ) {
V_62 -> V_124 = V_149 ;
return 0 ;
}
return - V_106 ;
}
static int F_41 ( struct V_117 * V_130 , int V_151 ,
int V_65 , unsigned int V_152 , unsigned int V_153 )
{
struct V_1 * V_2 = V_130 -> V_2 ;
struct V_61 * V_62 = F_10 ( V_2 ) ;
int V_110 , V_154 = - V_106 ;
F_34 ( V_2 -> V_9 , L_1 , V_121 ) ;
if ( ! V_152 || ! V_153 ) {
F_34 ( V_2 -> V_9 , L_5 ) ;
F_22 ( V_2 , V_41 ,
V_155 ,
V_156 ) ;
return 0 ;
}
if ( V_62 -> V_123 ) {
for ( V_110 = 0 ; V_110 < F_32 ( V_157 ) ; V_110 ++ )
if ( V_152 == V_157 [ V_110 ] . V_158 &&
V_153 == V_157 [ V_110 ] . V_159 ) {
F_42 ( V_2 -> V_9 ,
L_6 ) ;
F_2 ( V_2 , V_42 ,
V_157 [ V_110 ] . V_129 ) ;
F_25 (
F_26 ( 20 ) ) ;
F_22 ( V_2 ,
V_41 ,
V_155 |
V_160 ,
V_68 |
V_161 ) ;
V_154 = 0 ;
break;
}
} else {
for ( V_110 = 0 ; V_110 < F_32 ( V_162 ) ; V_110 ++ )
if ( V_152 == V_162 [ V_110 ] . V_158 &&
V_153 == V_162 [ V_110 ] . V_159 ) {
F_42 ( V_2 -> V_9 ,
L_7 ) ;
F_2 ( V_2 , V_42 ,
V_162 [ V_110 ] . V_129 ) ;
F_25 (
F_26 ( 20 ) ) ;
F_22 ( V_2 ,
V_41 ,
V_155 |
V_160 ,
V_68 |
V_163 ) ;
V_154 = 0 ;
break;
}
}
return V_154 ;
}
static int F_43 ( struct V_1 * V_2 ,
enum V_164 V_165 )
{
struct V_61 * V_62 = F_10 ( V_2 ) ;
switch ( V_165 ) {
case V_166 :
case V_167 :
F_22 ( V_2 , V_37 ,
V_168 | V_169 ,
V_168 | V_169 ) ;
break;
case V_170 :
if ( F_44 ( V_2 ) == V_171 ) {
F_22 ( V_2 , V_38 ,
V_172 | V_173 ,
V_172 | V_173 ) ;
F_23 ( 80 ) ;
F_22 ( V_2 , V_38 ,
V_174 ,
V_174 ) ;
F_45 ( V_62 -> V_175 , false ) ;
F_46 ( V_62 -> V_175 ) ;
}
break;
case V_171 :
F_2 ( V_2 , V_36 , 0x0000 ) ;
F_2 ( V_2 , V_37 , 0x0000 ) ;
F_2 ( V_2 , V_38 , 0x0000 ) ;
F_2 ( V_2 , V_39 , 0x0000 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = F_10 ( V_2 ) ;
unsigned int V_176 ;
V_176 = F_3 ( V_2 , V_177 ) ;
if ( V_176 & 0x0002 )
V_62 -> V_99 = 1 ;
else
V_62 -> V_99 = 0 ;
F_5 ( V_2 ) ;
F_22 ( V_2 , V_38 ,
V_172 | V_173 ,
V_172 | V_173 ) ;
F_23 ( 80 ) ;
F_22 ( V_2 , V_38 ,
V_174 , V_174 ) ;
F_2 ( V_2 , V_10 , 0x0f18 ) ;
if ( V_62 -> V_99 )
F_22 ( V_2 , V_10 ,
0x2000 , 0x2000 ) ;
else
F_22 ( V_2 , V_10 ,
0x2000 , 0 ) ;
if ( V_62 -> V_63 ) {
F_22 ( V_2 , V_44 ,
V_178 |
V_179 ,
V_180 |
V_181 ) ;
F_22 ( V_2 , V_28 ,
V_182 |
V_183 ,
V_184 |
V_185 ) ;
}
F_48 ( V_2 , V_170 ) ;
return 0 ;
}
static int F_49 ( struct V_186 * V_187 ,
const struct V_188 * V_189 )
{
struct V_61 * V_62 ;
int V_154 ;
V_62 = F_50 ( & V_187 -> V_9 , sizeof( struct V_61 ) ,
V_190 ) ;
if ( NULL == V_62 )
return - V_191 ;
F_51 ( V_187 , V_62 ) ;
V_62 -> V_175 = F_52 ( V_187 , & V_192 ) ;
if ( F_53 ( V_62 -> V_175 ) )
return F_54 ( V_62 -> V_175 ) ;
V_154 = F_55 ( & V_187 -> V_9 , & V_193 ,
V_194 , F_32 ( V_194 ) ) ;
return V_154 ;
}
static int F_56 ( struct V_186 * V_195 )
{
F_57 ( & V_195 -> V_9 ) ;
return 0 ;
}
