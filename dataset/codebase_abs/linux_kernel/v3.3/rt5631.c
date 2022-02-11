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
static int F_6 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
switch ( V_3 ) {
case V_7 :
case V_8 :
case V_5 :
case V_6 :
case V_9 :
return 1 ;
default:
return 0 ;
}
}
static int F_7 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
switch ( V_3 ) {
case V_7 :
case V_10 :
case V_11 :
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
case V_8 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_5 :
case V_6 :
case V_9 :
case V_52 :
case V_53 :
case V_54 :
return 1 ;
default:
return 0 ;
}
}
static int F_8 ( struct V_55 * V_56 ,
struct V_57 * V_58 )
{
struct V_1 * V_2 = F_9 ( V_56 ) ;
struct V_59 * V_60 = F_10 ( V_2 ) ;
V_58 -> V_4 . integer . V_4 [ 0 ] = V_60 -> V_61 ;
return 0 ;
}
static int F_11 ( struct V_55 * V_56 ,
struct V_57 * V_58 )
{
struct V_1 * V_2 = F_9 ( V_56 ) ;
struct V_59 * V_60 = F_10 ( V_2 ) ;
V_60 -> V_61 = V_58 -> V_4 . integer . V_4 [ 0 ] ;
return 0 ;
}
static int F_12 ( struct V_62 * V_63 ,
struct V_62 * V_64 )
{
unsigned int V_3 ;
V_3 = F_4 ( V_63 -> V_2 , V_39 ) ;
return V_3 & V_65 ;
}
static int F_13 ( struct V_62 * V_63 ,
struct V_62 * V_64 )
{
struct V_59 * V_60 = F_10 ( V_63 -> V_2 ) ;
return V_60 -> V_61 ;
}
static int F_14 ( struct V_62 * V_63 ,
struct V_62 * V_64 )
{
unsigned int V_3 ;
V_3 = F_4 ( V_63 -> V_2 , V_21 ) ;
return ! ( V_3 & V_66 ) ;
}
static int F_15 ( struct V_62 * V_63 ,
struct V_62 * V_64 )
{
unsigned int V_3 ;
V_3 = F_4 ( V_63 -> V_2 , V_22 ) ;
return ! ( V_3 & V_67 ) ;
}
static int F_16 ( struct V_62 * V_63 ,
struct V_62 * V_64 )
{
unsigned int V_3 ;
V_3 = F_4 ( V_63 -> V_2 , V_28 ) ;
return ! ( V_3 & V_68 ) ;
}
static int F_17 ( struct V_62 * V_63 ,
struct V_62 * V_64 )
{
unsigned int V_3 ;
V_3 = F_4 ( V_63 -> V_2 , V_28 ) ;
return ! ( V_3 & V_69 ) ;
}
static int F_18 ( struct V_62 * V_63 ,
struct V_62 * V_64 )
{
unsigned int V_3 ;
V_3 = F_4 ( V_63 -> V_2 , V_18 ) ;
return ! ( V_3 & V_70 ) ;
}
static int F_19 ( struct V_62 * V_63 ,
struct V_62 * V_64 )
{
unsigned int V_3 ;
V_3 = F_4 ( V_63 -> V_2 , V_18 ) ;
return ! ( V_3 & V_71 ) ;
}
static void F_20 ( struct V_1 * V_2 , int V_72 )
{
unsigned int V_73 , V_74 ;
F_21 ( V_2 , V_45 ,
V_75 , 0 ) ;
V_73 = F_4 ( V_2 , V_47 ) ;
F_2 ( V_2 , V_47 , 0 ) ;
V_74 = F_4 ( V_2 , V_8 ) ;
F_2 ( V_2 , V_8 , V_74 & 0xf7ff ) ;
if ( V_72 ) {
F_1 ( V_2 , V_76 , 0x84c0 ) ;
F_1 ( V_2 , V_77 , 0x309f ) ;
F_1 ( V_2 , V_78 , 0x6530 ) ;
F_2 ( V_2 , V_45 ,
V_79 ) ;
} else {
F_2 ( V_2 , V_45 , 0 ) ;
F_22 ( 100 ) ;
}
F_2 ( V_2 , V_47 , V_73 ) ;
F_2 ( V_2 , V_8 , V_74 ) ;
}
static void F_23 ( struct V_1 * V_2 , int V_72 )
{
unsigned int V_73 , V_74 ;
F_21 ( V_2 , V_45 ,
V_75 , 0 ) ;
V_73 = F_4 ( V_2 , V_47 ) ;
F_2 ( V_2 , V_47 , 0 ) ;
V_74 = F_4 ( V_2 , V_8 ) ;
F_2 ( V_2 , V_8 , V_74 & 0xf7ff ) ;
if ( V_72 ) {
F_24 ( F_25 ( 10 ) ) ;
F_1 ( V_2 , V_77 , 0x307f ) ;
F_21 ( V_2 , V_11 ,
V_80 | V_81 , 0 ) ;
F_22 ( 300 ) ;
} else {
F_21 ( V_2 , V_11 ,
V_80 | V_81 ,
V_80 | V_81 ) ;
F_22 ( 100 ) ;
}
F_2 ( V_2 , V_47 , V_73 ) ;
F_2 ( V_2 , V_8 , V_74 ) ;
}
static void F_26 ( struct V_1 * V_2 , int V_72 )
{
unsigned int V_73 , V_74 ;
F_21 ( V_2 , V_45 ,
V_75 , V_75 ) ;
V_73 = F_4 ( V_2 , V_47 ) ;
F_2 ( V_2 , V_47 , 0 ) ;
V_74 = F_4 ( V_2 , V_8 ) ;
F_2 ( V_2 , V_8 , V_74 & 0xf7ff ) ;
if ( V_72 ) {
F_1 ( V_2 , V_77 , 0x303e ) ;
F_21 ( V_2 , V_36 ,
V_82 | V_83 |
V_84 ,
V_82 | V_83 |
V_84 ) ;
F_2 ( V_2 , V_44 ,
V_85 | V_86 ) ;
F_22 ( 100 ) ;
F_21 ( V_2 , V_36 ,
V_87 , V_87 ) ;
} else {
F_1 ( V_2 , V_77 , 0x303F ) ;
F_2 ( V_2 , V_44 ,
V_85 | V_88 |
V_89 | V_90 ) ;
F_22 ( 75 ) ;
F_2 ( V_2 , V_44 ,
V_85 | V_89 |
V_90 ) ;
F_21 ( V_2 , V_36 ,
V_87 , 0 ) ;
F_2 ( V_2 , V_44 ,
V_85 | V_86 |
V_89 | V_90 ) ;
F_22 ( 80 ) ;
F_2 ( V_2 , V_44 ,
V_85 ) ;
F_21 ( V_2 , V_36 ,
V_82 | V_83 |
V_84 , 0 ) ;
}
F_2 ( V_2 , V_47 , V_73 ) ;
F_2 ( V_2 , V_8 , V_74 ) ;
}
static void F_27 ( struct V_1 * V_2 , int V_72 )
{
unsigned int V_73 , V_74 ;
F_21 ( V_2 , V_45 ,
V_75 , V_75 ) ;
V_73 = F_4 ( V_2 , V_47 ) ;
F_2 ( V_2 , V_47 , 0 ) ;
V_74 = F_4 ( V_2 , V_8 ) ;
F_2 ( V_2 , V_8 , V_74 & 0xf7ff ) ;
if ( V_72 ) {
F_24 ( F_25 ( 10 ) ) ;
F_1 ( V_2 , V_77 , 0x302f ) ;
F_2 ( V_2 , V_44 ,
V_85 | V_88 |
V_91 |
V_92 ) ;
F_21 ( V_2 , V_11 ,
V_80 | V_81 , 0 ) ;
F_22 ( 160 ) ;
} else {
F_1 ( V_2 , V_77 , 0x302f ) ;
F_2 ( V_2 , V_44 ,
V_85 | V_88 |
V_91 |
V_92 ) ;
F_21 ( V_2 , V_11 ,
V_80 | V_81 ,
V_80 | V_81 ) ;
F_22 ( 150 ) ;
}
F_2 ( V_2 , V_47 , V_73 ) ;
F_2 ( V_2 , V_8 , V_74 ) ;
}
static int F_28 ( struct V_62 * V_93 ,
struct V_55 * V_56 , int V_94 )
{
struct V_1 * V_2 = V_93 -> V_2 ;
struct V_59 * V_60 = F_10 ( V_2 ) ;
switch ( V_94 ) {
case V_95 :
if ( V_60 -> V_96 ) {
F_23 ( V_2 , 0 ) ;
F_20 ( V_2 , 0 ) ;
} else {
F_27 ( V_2 , 0 ) ;
F_26 ( V_2 , 0 ) ;
}
break;
case V_97 :
if ( V_60 -> V_96 ) {
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
static int F_29 ( struct V_62 * V_93 ,
struct V_55 * V_56 , int V_94 )
{
struct V_1 * V_2 = V_93 -> V_2 ;
struct V_59 * V_60 = F_10 ( V_2 ) ;
switch ( V_60 -> V_98 ) {
case 44100 :
case 48000 :
F_21 ( V_2 , V_26 ,
V_99 ,
V_100 ) ;
break;
case 32000 :
case 22050 :
F_21 ( V_2 , V_26 ,
V_99 ,
V_101 ) ;
break;
case 16000 :
case 11025 :
case 8000 :
F_21 ( V_2 , V_26 ,
V_99 ,
V_102 ) ;
break;
default:
return - V_103 ;
}
return 0 ;
}
static int F_30 ( int V_104 , int V_105 , int V_106 )
{
int V_107 ;
for ( V_107 = 0 ; V_107 < F_31 ( V_108 ) ; V_107 ++ ) {
if ( V_108 [ V_107 ] . V_104 == V_104 && V_108 [ V_107 ] . V_105 == V_105 &&
( V_108 [ V_107 ] . V_109 / V_108 [ V_107 ] . V_105 ) == V_106 )
return V_107 ;
}
return - V_103 ;
}
static int F_32 ( struct V_110 * V_111 ,
struct V_112 * V_113 , struct V_114 * V_115 )
{
struct V_116 * V_117 = V_111 -> V_118 ;
struct V_1 * V_2 = V_117 -> V_2 ;
struct V_59 * V_60 = F_10 ( V_2 ) ;
int V_106 = 32 , V_119 ;
unsigned int V_120 = 0 ;
F_33 ( V_2 -> V_121 , L_1 , V_122 ) ;
V_60 -> V_123 = F_34 ( V_113 ) ;
if ( V_60 -> V_123 < 0 ) {
F_35 ( V_2 -> V_121 , L_2 ) ;
return V_60 -> V_123 ;
}
V_60 -> V_98 = F_36 ( V_113 ) ;
if ( V_60 -> V_124 )
V_119 = F_30 ( V_60 -> V_125 , V_60 -> V_98 ,
V_60 -> V_123 / V_60 -> V_98 ) ;
else
V_119 = F_30 ( V_60 -> V_125 , V_60 -> V_98 ,
V_106 ) ;
if ( V_119 < 0 ) {
F_35 ( V_2 -> V_121 , L_3 ) ;
return - V_103 ;
}
switch ( F_37 ( V_113 ) ) {
case V_126 :
break;
case V_127 :
V_120 |= V_128 ;
break;
case V_129 :
V_120 |= V_130 ;
break;
case V_131 :
V_120 |= V_132 ;
break;
default:
return - V_103 ;
}
F_21 ( V_2 , V_31 ,
V_133 , V_120 ) ;
F_2 ( V_2 , V_33 ,
V_108 [ V_119 ] . V_134 ) ;
return 0 ;
}
static int F_38 ( struct V_114 * V_135 ,
unsigned int V_136 )
{
struct V_1 * V_2 = V_135 -> V_2 ;
struct V_59 * V_60 = F_10 ( V_2 ) ;
unsigned int V_120 = 0 ;
F_33 ( V_2 -> V_121 , L_1 , V_122 ) ;
switch ( V_136 & V_137 ) {
case V_138 :
V_60 -> V_124 = 1 ;
break;
case V_139 :
V_120 |= V_140 ;
V_60 -> V_124 = 0 ;
break;
default:
return - V_103 ;
}
switch ( V_136 & V_141 ) {
case V_142 :
break;
case V_143 :
V_120 |= V_144 ;
break;
case V_145 :
V_120 |= V_146 ;
break;
case V_147 :
V_120 |= V_148 ;
break;
default:
return - V_103 ;
}
switch ( V_136 & V_149 ) {
case V_150 :
break;
case V_151 :
V_120 |= V_152 ;
break;
default:
return - V_103 ;
}
F_2 ( V_2 , V_31 , V_120 ) ;
return 0 ;
}
static int F_39 ( struct V_114 * V_135 ,
int V_153 , unsigned int V_154 , int V_155 )
{
struct V_1 * V_2 = V_135 -> V_2 ;
struct V_59 * V_60 = F_10 ( V_2 ) ;
F_33 ( V_2 -> V_121 , L_4 , V_122 , V_154 ) ;
if ( ( V_154 >= ( 256 * 8000 ) ) && ( V_154 <= ( 512 * 96000 ) ) ) {
V_60 -> V_125 = V_154 ;
return 0 ;
}
return - V_103 ;
}
static int F_40 ( struct V_114 * V_135 , int V_156 ,
int V_63 , unsigned int V_157 , unsigned int V_158 )
{
struct V_1 * V_2 = V_135 -> V_2 ;
struct V_59 * V_60 = F_10 ( V_2 ) ;
int V_107 , V_159 = - V_103 ;
F_33 ( V_2 -> V_121 , L_1 , V_122 ) ;
if ( ! V_157 || ! V_158 ) {
F_33 ( V_2 -> V_121 , L_5 ) ;
F_21 ( V_2 , V_39 ,
V_160 ,
V_161 ) ;
return 0 ;
}
if ( V_60 -> V_124 ) {
for ( V_107 = 0 ; V_107 < F_31 ( V_162 ) ; V_107 ++ )
if ( V_157 == V_162 [ V_107 ] . V_163 &&
V_158 == V_162 [ V_107 ] . V_164 ) {
F_41 ( V_2 -> V_121 ,
L_6 ) ;
F_2 ( V_2 , V_40 ,
V_162 [ V_107 ] . V_134 ) ;
F_24 (
F_25 ( 20 ) ) ;
F_21 ( V_2 ,
V_39 ,
V_160 |
V_165 ,
V_65 |
V_166 ) ;
V_159 = 0 ;
break;
}
} else {
for ( V_107 = 0 ; V_107 < F_31 ( V_167 ) ; V_107 ++ )
if ( V_157 == V_167 [ V_107 ] . V_163 &&
V_158 == V_167 [ V_107 ] . V_164 ) {
F_41 ( V_2 -> V_121 ,
L_7 ) ;
F_2 ( V_2 , V_40 ,
V_167 [ V_107 ] . V_134 ) ;
F_24 (
F_25 ( 20 ) ) ;
F_21 ( V_2 ,
V_39 ,
V_160 |
V_165 ,
V_65 |
V_168 ) ;
V_159 = 0 ;
break;
}
}
return V_159 ;
}
static int F_42 ( struct V_1 * V_2 ,
enum V_169 V_170 )
{
switch ( V_170 ) {
case V_171 :
case V_172 :
F_21 ( V_2 , V_35 ,
V_173 | V_174 ,
V_173 | V_174 ) ;
break;
case V_175 :
if ( V_2 -> V_176 . V_177 == V_178 ) {
F_21 ( V_2 , V_36 ,
V_179 | V_180 ,
V_179 | V_180 ) ;
F_22 ( 80 ) ;
F_21 ( V_2 , V_36 ,
V_181 ,
V_181 ) ;
V_2 -> V_182 = false ;
F_43 ( V_2 ) ;
}
break;
case V_178 :
F_2 ( V_2 , V_34 , 0x0000 ) ;
F_2 ( V_2 , V_35 , 0x0000 ) ;
F_2 ( V_2 , V_36 , 0x0000 ) ;
F_2 ( V_2 , V_37 , 0x0000 ) ;
break;
default:
break;
}
V_2 -> V_176 . V_177 = V_170 ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = F_10 ( V_2 ) ;
unsigned int V_183 ;
int V_159 ;
V_159 = F_45 ( V_2 , 8 , 16 , V_184 ) ;
if ( V_159 != 0 ) {
F_35 ( V_2 -> V_121 , L_8 , V_159 ) ;
return V_159 ;
}
V_183 = F_3 ( V_2 , V_185 ) ;
if ( V_183 & 0x0002 )
V_60 -> V_96 = 1 ;
else
V_60 -> V_96 = 0 ;
F_5 ( V_2 ) ;
F_21 ( V_2 , V_36 ,
V_179 | V_180 ,
V_179 | V_180 ) ;
F_22 ( 80 ) ;
F_21 ( V_2 , V_36 ,
V_181 , V_181 ) ;
F_2 ( V_2 , V_8 , 0x0f18 ) ;
if ( V_60 -> V_96 )
F_21 ( V_2 , V_8 ,
0x2000 , 0x2000 ) ;
else
F_21 ( V_2 , V_8 ,
0x2000 , 0 ) ;
if ( V_60 -> V_61 ) {
F_21 ( V_2 , V_42 ,
V_186 |
V_187 ,
V_188 |
V_189 ) ;
F_21 ( V_2 , V_26 ,
V_190 |
V_191 ,
V_192 |
V_193 ) ;
}
V_2 -> V_176 . V_177 = V_175 ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
F_42 ( V_2 , V_178 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
F_42 ( V_2 , V_178 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 )
{
F_42 ( V_2 , V_175 ) ;
return 0 ;
}
static int F_49 ( struct V_194 * V_195 ,
const struct V_196 * V_197 )
{
struct V_59 * V_60 ;
int V_159 ;
V_60 = F_50 ( & V_195 -> V_121 , sizeof( struct V_59 ) ,
V_198 ) ;
if ( NULL == V_60 )
return - V_199 ;
F_51 ( V_195 , V_60 ) ;
V_159 = F_52 ( & V_195 -> V_121 , & V_200 ,
V_201 , F_31 ( V_201 ) ) ;
return V_159 ;
}
static T_1 int F_53 ( struct V_194 * V_202 )
{
F_54 ( & V_202 -> V_121 ) ;
return 0 ;
}
static int T_2 F_55 ( void )
{
return F_56 ( & V_203 ) ;
}
static void T_3 F_57 ( void )
{
F_58 ( & V_203 ) ;
}
