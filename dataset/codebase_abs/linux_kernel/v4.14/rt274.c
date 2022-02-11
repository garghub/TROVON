static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case 0 ... 0xff :
case F_2 ( V_4 , V_5 ) :
case V_6 :
case V_7 :
case V_8 :
case F_3 ( V_9 , V_10 , 0 ) :
case F_3 ( V_9 , V_11 , 0 ) :
case F_3 ( V_12 , V_13 , 0 ) :
case F_3 ( V_12 , V_14 , 0 ) :
case F_3 ( V_12 , V_15 , 0 ) :
case F_3 ( V_12 , V_16 , 0 ) :
case F_3 ( V_17 , V_13 , 0 ) :
case F_3 ( V_17 , V_14 , 0 ) :
case F_3 ( V_17 , V_15 , 0 ) :
case F_3 ( V_17 , V_16 , 0 ) :
case F_3 ( V_17 , V_18 , 0 ) :
case F_3 ( V_17 , V_19 , 0 ) :
case F_3 ( V_17 , V_10 , 0 ) :
case F_3 ( V_17 , V_20 , 0 ) :
case F_3 ( V_17 , V_21 , 0 ) :
case F_3 ( V_17 , V_11 , 0 ) :
case F_3 ( V_22 , V_11 , 0 ) :
case F_3 ( V_22 , V_23 , 0 ) :
case F_3 ( V_22 , V_24 , 0 ) :
case F_3 ( V_25 , V_18 , 0 ) :
case F_3 ( V_25 , V_19 , 0 ) :
case F_3 ( V_25 , V_10 , 0 ) :
case F_3 ( V_25 , V_20 , 0 ) :
case F_3 ( V_25 , V_21 , 0 ) :
case F_3 ( V_25 , V_11 , 0 ) :
case F_3 ( V_26 , V_11 , 0 ) :
case F_3 ( V_26 , V_10 , 0 ) :
case F_3 ( V_26 , V_27 , 0 ) :
return true ;
default:
return false ;
}
}
static bool F_4 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case 0 ... 0xff :
case F_2 ( V_4 , V_5 ) :
case V_6 :
case V_7 :
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
case V_54 :
case V_8 :
case V_55 :
case V_56 :
case F_5 ( V_13 ) :
case F_5 ( V_14 ) :
case F_5 ( V_15 ) :
case F_5 ( V_16 ) :
case F_5 ( V_19 ) :
case F_5 ( V_10 ) :
case F_3 ( V_9 , V_10 , 0 ) :
case F_3 ( V_9 , V_11 , 0 ) :
case F_3 ( V_12 , V_13 , 0 ) :
case F_3 ( V_12 , V_14 , 0 ) :
case F_3 ( V_12 , V_15 , 0 ) :
case F_3 ( V_12 , V_16 , 0 ) :
case F_3 ( V_17 , V_13 , 0 ) :
case F_3 ( V_17 , V_14 , 0 ) :
case F_3 ( V_17 , V_15 , 0 ) :
case F_3 ( V_17 , V_16 , 0 ) :
case F_3 ( V_17 , V_18 , 0 ) :
case F_3 ( V_17 , V_19 , 0 ) :
case F_3 ( V_17 , V_10 , 0 ) :
case F_3 ( V_17 , V_20 , 0 ) :
case F_3 ( V_17 , V_21 , 0 ) :
case F_3 ( V_17 , V_11 , 0 ) :
case F_3 ( V_22 , V_11 , 0 ) :
case F_3 ( V_22 , V_23 , 0 ) :
case F_3 ( V_22 , V_24 , 0 ) :
case F_3 ( V_25 , V_18 , 0 ) :
case F_3 ( V_25 , V_19 , 0 ) :
case F_3 ( V_25 , V_10 , 0 ) :
case F_3 ( V_25 , V_20 , 0 ) :
case F_3 ( V_25 , V_21 , 0 ) :
case F_3 ( V_25 , V_11 , 0 ) :
case F_3 ( V_26 , V_11 , 0 ) :
case F_3 ( V_26 , V_10 , 0 ) :
case F_3 ( V_26 , V_27 , 0 ) :
return true ;
default:
return false ;
}
}
static void F_6 ( struct V_57 * V_58 )
{
struct V_59 * V_60 = F_7 ( V_58 ) ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_62 ; V_61 ++ ) {
F_8 ( V_58 , V_60 -> V_63 [ V_61 ] . V_3 ,
V_60 -> V_63 [ V_61 ] . V_64 ) ;
}
}
static int F_9 ( struct V_59 * V_60 , bool * V_65 , bool * V_66 )
{
unsigned int V_67 ;
* V_65 = false ;
* V_66 = false ;
if ( ! V_60 -> V_58 )
return - V_68 ;
F_10 ( V_60 -> V_69 , V_6 , & V_67 ) ;
* V_65 = V_67 & 0x80000000 ;
F_10 ( V_60 -> V_69 , V_7 , & V_67 ) ;
* V_66 = V_67 & 0x80000000 ;
F_11 ( L_1 , * V_65 , * V_66 ) ;
return 0 ;
}
static void F_12 ( struct V_70 * V_71 )
{
struct V_59 * V_60 =
F_13 ( V_71 , struct V_59 , V_72 . V_71 ) ;
int V_73 = 0 ;
bool V_65 = false ;
bool V_66 = false ;
if ( F_9 ( V_60 , & V_65 , & V_66 ) < 0 )
return;
if ( V_65 == true )
V_73 |= V_74 ;
if ( V_66 == true )
V_73 |= V_75 ;
F_14 ( V_60 -> V_76 , V_73 ,
V_75 | V_74 ) ;
}
static int F_15 ( struct V_57 * V_58 ,
struct V_77 * V_76 , void * V_78 )
{
struct V_59 * V_60 = F_7 ( V_58 ) ;
if ( V_76 == NULL ) {
F_16 ( V_60 -> V_69 , V_79 ,
V_80 , V_81 ) ;
return 0 ;
}
V_60 -> V_76 = V_76 ;
F_16 ( V_60 -> V_69 , V_79 ,
V_80 , V_80 ) ;
F_17 ( 0 , V_60 ) ;
return 0 ;
}
static int F_18 ( struct V_82 * V_83 ,
struct V_84 * V_85 ,
struct V_86 * V_87 )
{
struct V_57 * V_58 = V_87 -> V_58 ;
struct V_59 * V_60 = F_7 ( V_58 ) ;
unsigned int V_88 = 0 ;
int V_89 = 0 , V_90 = 0 ;
switch ( F_19 ( V_85 ) ) {
case 44100 :
case 48000 :
break;
default:
F_20 ( V_58 -> V_2 , L_2 ,
F_19 ( V_85 ) ) ;
return - V_68 ;
}
switch ( V_60 -> V_91 ) {
case 12288000 :
case 24576000 :
if ( F_19 ( V_85 ) != 48000 ) {
F_20 ( V_58 -> V_2 , L_3 ,
F_19 ( V_85 ) , V_60 -> V_91 ) ;
return - V_68 ;
}
break;
case 11289600 :
case 22579200 :
if ( F_19 ( V_85 ) != 44100 ) {
F_20 ( V_58 -> V_2 , L_3 ,
F_19 ( V_85 ) , V_60 -> V_91 ) ;
return - V_68 ;
}
break;
}
if ( F_21 ( V_85 ) <= 16 ) {
V_88 |= ( F_21 ( V_85 ) - 1 ) ;
} else {
F_20 ( V_58 -> V_2 , L_4 ,
F_21 ( V_85 ) ) ;
return - V_68 ;
}
switch ( F_22 ( V_85 ) ) {
case 16 :
V_89 = 0 ;
V_90 = 0 ;
V_88 |= ( 0x1 << 4 ) ;
break;
case 32 :
V_89 = 2 ;
V_90 = 3 ;
V_88 |= ( 0x4 << 4 ) ;
break;
case 20 :
V_89 = 1 ;
V_90 = 1 ;
V_88 |= ( 0x2 << 4 ) ;
break;
case 24 :
V_89 = 2 ;
V_90 = 2 ;
V_88 |= ( 0x3 << 4 ) ;
break;
case 8 :
V_89 = 3 ;
V_90 = 0 ;
break;
default:
return - V_68 ;
}
if ( V_60 -> V_92 )
V_90 = 0x3 ;
F_23 ( V_58 ,
V_93 , 0xc018 , V_89 << 3 | V_90 << 14 ) ;
F_24 ( V_58 -> V_2 , L_5 , V_88 ) ;
F_23 ( V_58 , V_52 , 0x407f , V_88 ) ;
F_23 ( V_58 , V_53 , 0x407f , V_88 ) ;
return 0 ;
}
static int F_25 ( struct V_86 * V_87 , unsigned int V_94 )
{
struct V_57 * V_58 = V_87 -> V_58 ;
struct V_59 * V_60 = F_7 ( V_58 ) ;
switch ( V_94 & V_95 ) {
case V_96 :
F_23 ( V_58 ,
V_93 , V_97 , V_98 ) ;
V_60 -> V_92 = true ;
break;
case V_99 :
F_23 ( V_58 ,
V_93 , V_97 , V_100 ) ;
V_60 -> V_92 = false ;
break;
default:
return - V_68 ;
}
switch ( V_94 & V_101 ) {
case V_102 :
F_23 ( V_58 , V_93 ,
V_103 , V_104 ) ;
break;
case V_105 :
F_23 ( V_58 , V_93 ,
V_103 , V_106 ) ;
break;
case V_107 :
F_23 ( V_58 , V_93 ,
V_103 , V_108 ) ;
break;
case V_109 :
F_23 ( V_58 , V_93 ,
V_103 , V_110 ) ;
break;
default:
return - V_68 ;
}
F_23 ( V_58 , V_52 , 0x8000 , 0 ) ;
F_23 ( V_58 , V_53 , 0x8000 , 0 ) ;
return 0 ;
}
static int F_26 ( struct V_86 * V_87 , int V_111 , int V_112 ,
unsigned int V_113 , unsigned int V_114 )
{
struct V_57 * V_58 = V_87 -> V_58 ;
struct V_59 * V_60 = F_7 ( V_58 ) ;
switch ( V_112 ) {
case V_115 :
F_23 ( V_58 , V_116 ,
V_117 , V_118 ) ;
break;
default:
F_27 ( V_58 -> V_2 , L_6 ) ;
case V_119 :
F_23 ( V_58 , V_116 ,
V_117 , V_120 ) ;
break;
}
if ( V_112 == V_119 ) {
F_23 ( V_58 , V_121 ,
( 0x3 << 12 ) , ( 0x3 << 12 ) ) ;
switch ( V_60 -> V_122 ) {
case 50 :
F_8 ( V_58 , 0x7a , 0xaab6 ) ;
F_8 ( V_58 , 0x7b , 0x0301 ) ;
F_8 ( V_58 , 0x7c , 0x04fe ) ;
break;
case 64 :
F_8 ( V_58 , 0x7a , 0xaa96 ) ;
F_8 ( V_58 , 0x7b , 0x8003 ) ;
F_8 ( V_58 , 0x7c , 0x081e ) ;
break;
case 128 :
F_8 ( V_58 , 0x7a , 0xaa96 ) ;
F_8 ( V_58 , 0x7b , 0x8003 ) ;
F_8 ( V_58 , 0x7c , 0x080e ) ;
break;
default:
F_27 ( V_58 -> V_2 , L_7 ) ;
case 100 :
F_8 ( V_58 , 0x7a , 0xaab6 ) ;
F_8 ( V_58 , 0x7b , 0x0301 ) ;
F_8 ( V_58 , 0x7c , 0x047e ) ;
break;
}
}
return 0 ;
}
static int F_28 ( struct V_86 * V_87 ,
int V_123 , unsigned int V_124 , int V_125 )
{
struct V_57 * V_58 = V_87 -> V_58 ;
struct V_59 * V_60 = F_7 ( V_58 ) ;
unsigned int V_126 , V_127 ;
F_24 ( V_58 -> V_2 , L_8 , V_128 , V_124 ) ;
switch ( V_123 ) {
case V_129 :
V_127 = V_130 ;
V_126 = V_131 ;
break;
case V_132 :
V_127 = V_133 ;
V_126 = V_131 ;
break;
case V_134 :
V_127 = V_130 ;
V_126 = V_135 ;
break;
default:
V_127 = V_133 ;
V_126 = V_131 ;
F_27 ( V_58 -> V_2 , L_9 ) ;
break;
}
F_23 ( V_58 , V_121 ,
V_136 , V_127 ) ;
F_23 ( V_58 , V_137 ,
V_138 , V_126 ) ;
switch ( V_124 ) {
case 19200000 :
if ( V_123 == V_129 ) {
F_20 ( V_58 -> V_2 , L_10 ) ;
return - V_68 ;
}
F_23 ( V_58 ,
V_139 , 0x40 , 0x40 ) ;
break;
case 24000000 :
if ( V_123 == V_129 ) {
F_20 ( V_58 -> V_2 , L_10 ) ;
return - V_68 ;
}
F_23 ( V_58 ,
V_139 , 0x40 , 0x0 ) ;
break;
case 12288000 :
case 11289600 :
F_23 ( V_58 ,
V_121 , 0x1fcf , 0x0008 ) ;
break;
case 24576000 :
case 22579200 :
F_23 ( V_58 ,
V_121 , 0x1fcf , 0x1543 ) ;
break;
default:
F_20 ( V_58 -> V_2 , L_11 ) ;
return - V_68 ;
}
V_60 -> V_91 = V_124 ;
V_60 -> V_123 = V_123 ;
return 0 ;
}
static int F_29 ( struct V_86 * V_87 , unsigned int V_140 )
{
struct V_57 * V_58 = V_87 -> V_58 ;
struct V_59 * V_60 = F_7 ( V_58 ) ;
F_24 ( V_58 -> V_2 , L_12 , V_128 , V_140 ) ;
V_60 -> V_122 = V_140 ;
if ( ( V_140 / 50 ) == 0 )
F_23 ( V_58 ,
V_93 , 0x1000 , 0x1000 ) ;
else
F_23 ( V_58 ,
V_93 , 0x1000 , 0x0 ) ;
return 0 ;
}
static int F_30 ( struct V_86 * V_87 , unsigned int V_141 ,
unsigned int V_142 , int V_143 , int V_144 )
{
struct V_57 * V_58 = V_87 -> V_58 ;
if ( V_142 || V_141 ) {
F_23 ( V_58 ,
V_93 , V_145 , V_145 ) ;
} else {
F_23 ( V_58 ,
V_93 , V_145 , V_146 ) ;
return 0 ;
}
switch ( V_143 ) {
case 4 :
F_23 ( V_58 ,
V_93 , V_147 , V_148 ) ;
break;
case 2 :
F_23 ( V_58 ,
V_93 , V_147 , V_149 ) ;
break;
default:
F_20 ( V_58 -> V_2 ,
L_13 ) ;
return - V_68 ;
}
return 0 ;
}
static int F_31 ( struct V_57 * V_58 ,
enum V_150 V_151 )
{
switch ( V_151 ) {
case V_152 :
if ( V_153 ==
F_32 ( V_58 ) ) {
F_8 ( V_58 ,
V_28 , V_154 ) ;
}
break;
case V_153 :
F_8 ( V_58 ,
V_28 , V_155 ) ;
break;
default:
break;
}
return 0 ;
}
static T_1 F_17 ( int V_156 , void * V_78 )
{
struct V_59 * V_60 = V_78 ;
bool V_65 = false ;
bool V_66 = false ;
int V_157 , V_73 = 0 ;
F_16 ( V_60 -> V_69 , V_79 ,
V_158 , V_158 ) ;
V_157 = F_9 ( V_60 , & V_65 , & V_66 ) ;
if ( V_157 == 0 ) {
if ( V_65 == true )
V_73 |= V_74 ;
if ( V_66 == true )
V_73 |= V_75 ;
F_14 ( V_60 -> V_76 , V_73 ,
V_75 | V_74 ) ;
F_33 ( & V_60 -> V_159 -> V_2 , 300 ) ;
}
return V_160 ;
}
static int F_34 ( struct V_57 * V_58 )
{
struct V_59 * V_60 = F_7 ( V_58 ) ;
V_60 -> V_58 = V_58 ;
if ( V_60 -> V_159 -> V_156 ) {
F_35 ( & V_60 -> V_72 ,
F_12 ) ;
F_36 ( & V_60 -> V_72 ,
F_37 ( 1250 ) ) ;
}
return 0 ;
}
static int F_38 ( struct V_57 * V_58 )
{
struct V_59 * V_60 = F_7 ( V_58 ) ;
F_39 ( & V_60 -> V_72 ) ;
return 0 ;
}
static int F_40 ( struct V_57 * V_58 )
{
struct V_59 * V_60 = F_7 ( V_58 ) ;
F_41 ( V_60 -> V_69 , true ) ;
F_42 ( V_60 -> V_69 ) ;
return 0 ;
}
static int F_43 ( struct V_57 * V_58 )
{
struct V_59 * V_60 = F_7 ( V_58 ) ;
F_41 ( V_60 -> V_69 , false ) ;
F_6 ( V_58 ) ;
F_44 ( V_60 -> V_69 ) ;
return 0 ;
}
static int F_45 ( struct V_161 * V_159 ,
const struct V_162 * V_163 )
{
struct V_59 * V_60 ;
int V_157 ;
unsigned int V_88 ;
V_60 = F_46 ( & V_159 -> V_2 , sizeof( * V_60 ) ,
V_164 ) ;
if ( V_60 == NULL )
return - V_165 ;
V_60 -> V_69 = F_47 ( & V_159 -> V_2 , NULL , V_159 , & V_166 ) ;
if ( F_48 ( V_60 -> V_69 ) ) {
V_157 = F_49 ( V_60 -> V_69 ) ;
F_20 ( & V_159 -> V_2 , L_14 ,
V_157 ) ;
return V_157 ;
}
F_10 ( V_60 -> V_69 ,
F_2 ( V_4 , V_5 ) , & V_88 ) ;
if ( V_88 != V_167 ) {
F_20 ( & V_159 -> V_2 ,
L_15 , V_88 ) ;
return - V_168 ;
}
V_60 -> V_63 = F_50 ( & V_159 -> V_2 , V_169 ,
sizeof( V_169 ) , V_164 ) ;
if ( ! V_60 -> V_63 )
return - V_165 ;
V_60 -> V_170 = V_62 ;
V_60 -> V_159 = V_159 ;
F_51 ( V_159 , V_60 ) ;
F_52 ( V_60 -> V_69 , V_171 , 0 ) ;
F_16 ( V_60 -> V_69 , 0x1a , 0x4000 , 0x4000 ) ;
F_16 ( V_60 -> V_69 , V_172 , 0x3 , 0x0 ) ;
F_52 ( V_60 -> V_69 , V_173 , 0x01 ) ;
F_52 ( V_60 -> V_69 , V_174 , 0x8540 ) ;
F_16 ( V_60 -> V_69 , 0x6f , 0x0100 , 0x0100 ) ;
F_52 ( V_60 -> V_69 , 0x4a , 0x201b ) ;
F_16 ( V_60 -> V_69 , 0x6f , 0x3000 , 0x2000 ) ;
F_16 ( V_60 -> V_69 , 0x6f , 0xf , 0x0 ) ;
F_52 ( V_60 -> V_69 , V_175 , 0x00 ) ;
F_52 ( V_60 -> V_69 , V_176 , 0xb888 ) ;
F_53 ( 500 ) ;
F_16 ( V_60 -> V_69 , 0x6f , 0xf , 0xb ) ;
F_52 ( V_60 -> V_69 , V_175 , 0x00 ) ;
F_52 ( V_60 -> V_69 , V_176 , 0x3888 ) ;
F_52 ( V_60 -> V_69 , V_36 , 0x40 ) ;
F_52 ( V_60 -> V_69 , V_37 , 0x40 ) ;
F_52 ( V_60 -> V_69 , V_35 , 0x20 ) ;
F_52 ( V_60 -> V_69 , V_38 , 0x20 ) ;
F_16 ( V_60 -> V_69 , V_139 , 0xc004 , 0x4004 ) ;
F_16 ( V_60 -> V_69 , V_79 ,
V_177 , V_178 ) ;
F_52 ( V_60 -> V_69 , V_179 , 0x81 ) ;
F_52 ( V_60 -> V_69 , V_180 , 0x82 ) ;
if ( V_60 -> V_159 -> V_156 ) {
V_157 = F_54 ( V_60 -> V_159 -> V_156 , NULL , F_17 ,
V_181 | V_182 , L_16 , V_60 ) ;
if ( V_157 != 0 ) {
F_20 ( & V_159 -> V_2 ,
L_17 , V_157 ) ;
return V_157 ;
}
}
V_157 = F_55 ( & V_159 -> V_2 , & V_183 ,
V_184 , F_56 ( V_184 ) ) ;
return V_157 ;
}
static int F_57 ( struct V_161 * V_159 )
{
struct V_59 * V_60 = F_58 ( V_159 ) ;
if ( V_159 -> V_156 )
F_59 ( V_159 -> V_156 , V_60 ) ;
F_60 ( & V_159 -> V_2 ) ;
return 0 ;
}
