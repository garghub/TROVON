static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) -> V_4 ;
}
static bool F_3 ( struct V_5 * V_6 , unsigned int V_7 )
{
switch ( V_7 ) {
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case F_4 ( 1 ) :
case F_5 ( 0 ) :
case F_5 ( 1 ) :
case V_16 :
case F_6 ( 0 ) :
case F_6 ( 1 ) :
case F_6 ( 2 ) :
case F_6 ( 3 ) :
case F_6 ( 4 ) :
case F_6 ( 5 ) :
case F_6 ( 6 ) :
case F_6 ( 7 ) :
case V_17 :
case V_18 :
case F_7 ( 0 ) :
case F_7 ( 1 ) :
case F_7 ( 2 ) :
case F_7 ( 3 ) :
case F_7 ( 4 ) :
case V_19 :
case F_8 ( 0 ) :
case F_8 ( 1 ) :
case V_20 :
case V_21 :
return true ;
}
return false ;
}
static void F_9 ( struct V_1 * V_1 , bool V_22 ,
const T_1 * V_23 ,
unsigned int V_24 )
{
unsigned int V_25 ;
F_10 ( V_1 -> V_26 , F_11 ( 1 ) ,
V_27 , V_27 ) ;
if ( V_22 ) {
for ( V_25 = 0 ; V_25 < 12 ; ++ V_25 ) {
F_10 ( V_1 -> V_26 ,
F_11 ( V_25 ) ,
0x1f , V_23 [ V_25 ] >> 8 ) ;
F_12 ( V_1 -> V_26 ,
F_13 ( V_25 ) ,
V_23 [ V_25 ] & 0xff ) ;
}
}
if ( V_22 )
F_10 ( V_1 -> V_26 , F_11 ( 0 ) ,
0xe0 , 0x80 | ( V_24 << 5 ) ) ;
else
F_10 ( V_1 -> V_26 , F_11 ( 0 ) ,
0x80 , 0x00 ) ;
F_10 ( V_1 -> V_26 , F_11 ( 1 ) ,
V_27 , 0 ) ;
}
static int F_14 ( struct V_1 * V_1 , unsigned int V_28 )
{
if ( V_28 & 0xff )
F_10 ( V_1 -> V_26 , V_29 ,
V_28 , 0xff ) ;
if ( V_28 & 0xff00 ) {
V_28 >>= 8 ;
F_10 ( V_1 -> V_26 , V_30 ,
V_28 , 0xff ) ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_1 , unsigned int V_28 )
{
if ( V_28 & 0xff )
F_10 ( V_1 -> V_26 , V_29 ,
V_28 , 0x00 ) ;
if ( V_28 & 0xff00 ) {
V_28 >>= 8 ;
F_10 ( V_1 -> V_26 , V_30 ,
V_28 , 0x00 ) ;
}
return 0 ;
}
static void F_16 ( struct V_1 * V_1 ,
struct V_31 * V_32 ,
bool V_33 )
{
struct V_34 V_35 ;
bool V_36 , V_37 ;
unsigned int V_38 ;
T_2 V_39 [ 17 ] ;
if ( V_1 -> V_40 )
V_35 . V_41 = F_17 ( V_1 -> V_40 ) ;
else
V_35 . V_41 = false ;
F_18 ( & V_35 . V_42 ) ;
V_35 . V_42 . V_43 = V_44 ;
if ( V_33 ) {
V_35 . V_45 = false ;
V_35 . V_42 . V_46 = V_47 ;
} else {
V_35 . V_48 = V_49 ;
V_35 . V_50 = V_51 ;
if ( ( V_32 -> V_52 . V_53 &
V_54 ) &&
V_35 . V_41 ) {
V_35 . V_45 = false ;
V_35 . V_42 . V_46 =
V_55 ;
} else {
V_35 . V_45 = true ;
V_35 . V_42 . V_46 = V_47 ;
}
}
if ( V_35 . V_41 ) {
V_38 = V_56 ;
switch ( V_35 . V_42 . V_46 ) {
case V_57 :
V_36 = false ;
V_37 = true ;
break;
case V_55 :
V_36 = true ;
V_37 = true ;
break;
default:
V_36 = false ;
V_37 = false ;
break;
}
} else {
V_38 = V_58 ;
V_36 = false ;
V_37 = false ;
}
F_15 ( V_1 , V_59 ) ;
F_9 ( V_1 , V_35 . V_45 ,
V_35 . V_50 ,
V_35 . V_48 ) ;
F_10 ( V_1 -> V_26 , V_60 , 0x81 ,
( V_36 << 7 ) | V_37 ) ;
F_10 ( V_1 -> V_26 , V_61 ,
V_62 , V_38 ) ;
F_19 ( & V_35 . V_42 , V_39 ,
sizeof( V_39 ) ) ;
F_20 ( V_1 -> V_26 , V_63 ,
V_39 + 1 , sizeof( V_39 ) - 1 ) ;
F_14 ( V_1 , V_59 ) ;
}
static void F_21 ( struct V_1 * V_1 ,
const struct V_64 * V_35 )
{
static const unsigned int V_65 [ 4 ] = { 0 , 2 , 1 , 3 } ;
unsigned int V_66 ;
unsigned int V_67 ;
unsigned int V_68 ;
V_66 = ( V_35 -> V_66 + 1200 ) / 400 ;
V_67 = V_35 -> V_69 == 8 ? 3
: ( V_35 -> V_69 == 10 ? 1 : 2 ) ;
if ( V_35 -> V_70 != V_55 )
V_68 = V_35 -> V_71 == V_72
? 5 : 0 ;
else if ( V_35 -> V_71 == V_72 )
V_68 = V_35 -> V_73 ? 8 : 7 ;
else if ( V_35 -> V_71 == V_74 )
V_68 = V_35 -> V_73 ? 4 : 3 ;
else
V_68 = V_35 -> V_73 ? 2 : 1 ;
F_10 ( V_1 -> V_26 , V_75 , 0xf ,
V_68 ) ;
F_10 ( V_1 -> V_26 , V_60 , 0x7e ,
( V_67 << 4 ) |
( V_65 [ V_35 -> V_76 ] << 2 ) ) ;
F_12 ( V_1 -> V_26 , V_77 ,
V_35 -> V_78 << 3 ) ;
F_12 ( V_1 -> V_26 , V_79 ,
V_35 -> V_80 << 2 ) ;
F_12 ( V_1 -> V_26 , 0xba , V_66 << 5 ) ;
V_1 -> V_73 = V_35 -> V_73 ;
V_1 -> V_81 = V_35 -> V_81 ;
V_1 -> V_82 = V_35 -> V_82 ;
V_1 -> V_33 = V_35 -> V_70 == V_47 ;
}
static void F_22 ( struct V_1 * V_1 )
{
V_1 -> V_83 = - 1 ;
F_12 ( V_1 -> V_26 , F_5 ( 0 ) ,
V_84 ) ;
F_12 ( V_1 -> V_26 , F_5 ( 1 ) ,
V_85 ) ;
F_10 ( V_1 -> V_26 , V_86 ,
V_87 , 0 ) ;
F_10 ( V_1 -> V_26 , V_88 ,
V_89 ,
V_90 ) ;
F_23 ( V_1 -> V_26 ) ;
V_1 -> V_91 = true ;
}
static void F_24 ( struct V_1 * V_1 )
{
F_10 ( V_1 -> V_26 , V_86 ,
V_87 ,
V_87 ) ;
F_25 ( V_1 -> V_26 ) ;
V_1 -> V_91 = false ;
}
static bool F_26 ( struct V_1 * V_1 )
{
unsigned int V_92 ;
int V_93 ;
V_93 = F_27 ( V_1 -> V_26 , F_5 ( 0 ) , & V_92 ) ;
if ( V_93 < 0 )
return false ;
if ( V_92 & V_94 ) {
F_12 ( V_1 -> V_26 , F_5 ( 0 ) ,
V_94 ) ;
return true ;
}
return false ;
}
static int F_28 ( struct V_1 * V_1 )
{
unsigned int V_92 , V_95 ;
int V_93 ;
V_93 = F_27 ( V_1 -> V_26 , F_5 ( 0 ) , & V_92 ) ;
if ( V_93 < 0 )
return V_93 ;
V_93 = F_27 ( V_1 -> V_26 , F_5 ( 1 ) , & V_95 ) ;
if ( V_93 < 0 )
return V_93 ;
F_12 ( V_1 -> V_26 , F_5 ( 0 ) , V_92 ) ;
F_12 ( V_1 -> V_26 , F_5 ( 1 ) , V_95 ) ;
if ( V_92 & V_94 )
F_29 ( V_1 -> V_3 -> V_6 ) ;
if ( V_92 & V_84 || V_95 & V_85 ) {
V_1 -> V_96 = true ;
if ( V_1 -> V_97 -> V_98 )
F_30 ( & V_1 -> V_99 ) ;
}
return 0 ;
}
static T_3 F_31 ( int V_98 , void * V_100 )
{
struct V_1 * V_1 = V_100 ;
int V_93 ;
V_93 = F_28 ( V_1 ) ;
return V_93 < 0 ? V_101 : V_102 ;
}
static int F_32 ( struct V_1 * V_1 , int V_103 )
{
int V_93 ;
if ( V_1 -> V_97 -> V_98 ) {
V_93 = F_33 ( V_1 -> V_99 ,
V_1 -> V_96 , F_34 ( V_103 ) ) ;
} else {
for (; V_103 > 0 ; V_103 -= 25 ) {
V_93 = F_28 ( V_1 ) ;
if ( V_93 < 0 )
break;
if ( V_1 -> V_96 )
break;
F_35 ( 25 ) ;
}
}
return V_1 -> V_96 ? 0 : - V_104 ;
}
static int F_36 ( void * V_105 , T_4 * V_106 , unsigned int V_107 ,
T_5 V_108 )
{
struct V_1 * V_1 = V_105 ;
struct V_109 V_110 [ 2 ] ;
T_2 V_111 ;
unsigned int V_25 ;
int V_93 ;
if ( V_108 > 128 )
return - V_112 ;
if ( V_1 -> V_83 != V_107 / 2 ) {
unsigned int V_113 ;
V_93 = F_27 ( V_1 -> V_26 , V_19 ,
& V_113 ) ;
if ( V_93 < 0 )
return V_93 ;
if ( V_113 != 2 ) {
V_1 -> V_96 = false ;
F_12 ( V_1 -> V_26 , V_114 ,
V_107 ) ;
V_93 = F_32 ( V_1 , 200 ) ;
if ( V_93 < 0 )
return V_93 ;
}
V_110 [ 0 ] . V_115 = V_1 -> V_116 -> V_115 ;
V_110 [ 0 ] . V_117 = 0 ;
V_110 [ 0 ] . V_108 = 1 ;
V_110 [ 0 ] . V_106 = & V_111 ;
V_110 [ 1 ] . V_115 = V_1 -> V_116 -> V_115 ;
V_110 [ 1 ] . V_117 = V_118 ;
V_110 [ 1 ] . V_108 = 64 ;
V_110 [ 1 ] . V_106 = V_1 -> V_119 ;
V_111 = 0 ;
for ( V_25 = 0 ; V_25 < 4 ; ++ V_25 ) {
V_93 = F_37 ( V_1 -> V_116 -> V_120 , V_110 ,
F_38 ( V_110 ) ) ;
if ( V_93 < 0 )
return V_93 ;
else if ( V_93 != 2 )
return - V_104 ;
V_110 [ 1 ] . V_106 += 64 ;
V_111 += 64 ;
}
V_1 -> V_83 = V_107 / 2 ;
}
if ( V_107 % 2 == 0 )
memcpy ( V_106 , V_1 -> V_119 , V_108 ) ;
else
memcpy ( V_106 , V_1 -> V_119 + 128 , V_108 ) ;
return 0 ;
}
static int F_39 ( struct V_2 * V_3 ,
struct V_31 * V_32 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_40 * V_40 ;
unsigned int V_121 ;
if ( ! V_1 -> V_91 ) {
F_12 ( V_1 -> V_26 , F_5 ( 0 ) ,
V_84 ) ;
F_12 ( V_1 -> V_26 , F_5 ( 1 ) ,
V_85 ) ;
F_10 ( V_1 -> V_26 , V_86 ,
V_87 , 0 ) ;
V_1 -> V_83 = - 1 ;
}
V_40 = F_40 ( V_32 , F_36 , V_1 ) ;
if ( ! V_1 -> V_91 )
F_10 ( V_1 -> V_26 , V_86 ,
V_87 ,
V_87 ) ;
F_41 ( V_1 -> V_40 ) ;
V_1 -> V_40 = V_40 ;
if ( ! V_40 )
return 0 ;
F_42 ( V_32 , V_40 ) ;
V_121 = F_43 ( V_32 , V_40 ) ;
F_16 ( V_1 , V_32 , V_1 -> V_33 ) ;
return V_121 ;
}
static void F_44 ( struct V_2 * V_3 , int V_38 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_38 == V_122 )
F_22 ( V_1 ) ;
else
F_24 ( V_1 ) ;
}
static enum V_123
F_45 ( struct V_2 * V_3 ,
struct V_31 * V_32 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_123 V_113 ;
unsigned int V_124 ;
bool V_125 ;
int V_93 ;
V_93 = F_27 ( V_1 -> V_26 , V_15 , & V_124 ) ;
if ( V_93 < 0 )
return V_126 ;
if ( V_124 & V_127 )
V_113 = V_128 ;
else
V_113 = V_126 ;
V_125 = F_26 ( V_1 ) ;
if ( V_113 == V_128 && V_125 && V_1 -> V_91 ) {
F_25 ( V_1 -> V_26 ) ;
F_22 ( V_1 ) ;
F_39 ( V_3 , V_32 ) ;
if ( V_1 -> V_113 == V_128 )
V_113 = V_126 ;
} else {
F_10 ( V_1 -> V_26 , V_88 ,
V_89 ,
V_129 ) ;
}
V_1 -> V_113 = V_113 ;
return V_113 ;
}
static int F_46 ( struct V_2 * V_3 ,
struct V_130 * V_38 )
{
if ( V_38 -> clock > 165000 )
return V_131 ;
return V_132 ;
}
static void F_47 ( struct V_2 * V_3 ,
struct V_130 * V_38 ,
struct V_130 * V_133 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned int V_134 ;
unsigned int V_81 = 0 ;
unsigned int V_82 = 0 ;
if ( V_1 -> V_73 ) {
unsigned int V_135 , V_136 ;
unsigned int V_137 , V_138 ;
V_135 = V_133 -> V_139 -
V_133 -> V_140 ;
V_137 = V_133 -> V_141 -
V_133 -> V_142 ;
V_136 = V_133 -> V_143 -
V_133 -> V_139 ;
V_138 = V_133 -> V_144 -
V_133 -> V_141 ;
V_137 += 1 ;
F_12 ( V_1 -> V_26 , V_145 ,
( ( V_135 >> 10 ) & 0x7 ) << 5 ) ;
F_12 ( V_1 -> V_26 , F_48 ( 0 ) ,
( V_135 >> 2 ) & 0xff ) ;
F_12 ( V_1 -> V_26 , F_48 ( 1 ) ,
( ( V_135 & 0x3 ) << 6 ) |
( ( V_136 >> 4 ) & 0x3f ) ) ;
F_12 ( V_1 -> V_26 , F_48 ( 2 ) ,
( ( V_136 & 0xf ) << 4 ) |
( ( V_137 >> 6 ) & 0xf ) ) ;
F_12 ( V_1 -> V_26 , F_48 ( 3 ) ,
( ( V_137 & 0x3f ) << 2 ) |
( ( V_138 >> 8 ) & 0x3 ) ) ;
F_12 ( V_1 -> V_26 , F_48 ( 4 ) ,
V_138 & 0xff ) ;
V_81 = ! ( V_133 -> V_117 & V_146 ) ;
V_82 = ! ( V_133 -> V_117 & V_147 ) ;
} else {
enum V_148 V_149 ;
enum V_148 V_150 ;
if ( V_133 -> V_117 & V_151 )
V_149 = V_152 ;
else
V_149 = V_153 ;
if ( V_133 -> V_117 & V_154 )
V_150 = V_152 ;
else
V_150 = V_153 ;
if ( V_1 -> V_81 != V_149 &&
V_1 -> V_81 !=
V_155 )
V_81 = 1 ;
if ( V_1 -> V_82 != V_150 &&
V_1 -> V_82 !=
V_155 )
V_82 = 1 ;
}
if ( V_38 -> V_156 <= 24000 )
V_134 = V_157 ;
else if ( V_38 -> V_156 <= 25000 )
V_134 = V_158 ;
else if ( V_38 -> V_156 <= 30000 )
V_134 = V_159 ;
else
V_134 = V_160 ;
F_10 ( V_1 -> V_26 , 0xfb ,
0x6 , V_134 << 1 ) ;
F_10 ( V_1 -> V_26 , 0x17 ,
0x60 , ( V_82 << 6 ) | ( V_81 << 5 ) ) ;
V_1 -> V_161 = V_38 -> clock ;
}
static int F_49 ( struct V_162 * V_163 ,
struct V_64 * V_35 )
{
const char * V_164 ;
int V_93 ;
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
F_50 ( V_163 , L_1 , & V_35 -> V_69 ) ;
if ( V_35 -> V_69 != 8 && V_35 -> V_69 != 10 &&
V_35 -> V_69 != 12 )
return - V_112 ;
V_93 = F_51 ( V_163 , L_2 , & V_164 ) ;
if ( V_93 < 0 )
return V_93 ;
if ( ! strcmp ( V_164 , L_3 ) )
V_35 -> V_70 = V_47 ;
else if ( ! strcmp ( V_164 , L_4 ) )
V_35 -> V_70 = V_55 ;
else if ( ! strcmp ( V_164 , L_5 ) )
V_35 -> V_70 = V_57 ;
else
return - V_112 ;
V_93 = F_51 ( V_163 , L_6 , & V_164 ) ;
if ( V_93 < 0 )
return V_93 ;
if ( ! strcmp ( V_164 , L_7 ) )
V_35 -> V_71 = V_165 ;
else if ( ! strcmp ( V_164 , L_8 ) )
V_35 -> V_71 = V_74 ;
else if ( ! strcmp ( V_164 , L_9 ) )
V_35 -> V_71 = V_72 ;
else
return - V_112 ;
if ( V_35 -> V_70 == V_55 ||
V_35 -> V_71 != V_165 ) {
V_93 = F_50 ( V_163 , L_10 ,
& V_35 -> V_76 ) ;
if ( V_93 )
return V_93 ;
if ( V_35 -> V_76 < 1 || V_35 -> V_76 > 3 )
return - V_112 ;
V_93 = F_51 ( V_163 , L_11 ,
& V_164 ) ;
if ( V_93 < 0 )
return V_93 ;
if ( ! strcmp ( V_164 , L_12 ) )
V_35 -> V_78 =
V_166 ;
else if ( ! strcmp ( V_164 , L_13 ) )
V_35 -> V_78 =
V_167 ;
else if ( ! strcmp ( V_164 , L_14 ) )
V_35 -> V_78 =
V_168 ;
else
return - V_112 ;
} else {
V_35 -> V_76 = 1 ;
V_35 -> V_78 = V_166 ;
}
F_50 ( V_163 , L_15 , & V_35 -> V_66 ) ;
if ( V_35 -> V_66 < - 1200 || V_35 -> V_66 > 1600 )
return - V_112 ;
V_35 -> V_73 = F_52 ( V_163 , L_16 ) ;
V_35 -> V_80 = V_169 ;
V_35 -> V_82 = V_155 ;
V_35 -> V_81 = V_155 ;
return 0 ;
}
static int F_53 ( struct V_170 * V_171 , const struct V_172 * V_173 )
{
struct V_64 V_174 ;
struct V_1 * V_1 ;
struct V_5 * V_6 = & V_171 -> V_6 ;
unsigned int V_124 ;
int V_93 ;
if ( ! V_6 -> V_175 )
return - V_112 ;
V_1 = F_54 ( V_6 , sizeof( * V_1 ) , V_176 ) ;
if ( ! V_1 )
return - V_177 ;
V_1 -> V_91 = false ;
V_1 -> V_113 = V_126 ;
V_93 = F_49 ( V_6 -> V_175 , & V_174 ) ;
if ( V_93 )
return V_93 ;
V_1 -> V_178 = F_55 ( V_6 , L_17 , V_179 ) ;
if ( F_56 ( V_1 -> V_178 ) )
return F_57 ( V_1 -> V_178 ) ;
if ( V_1 -> V_178 ) {
F_58 ( 5 ) ;
F_59 ( V_1 -> V_178 , 0 ) ;
}
V_1 -> V_26 = F_60 ( V_171 , & V_180 ) ;
if ( F_56 ( V_1 -> V_26 ) )
return F_57 ( V_1 -> V_26 ) ;
V_93 = F_27 ( V_1 -> V_26 , V_8 , & V_124 ) ;
if ( V_93 )
return V_93 ;
F_61 ( V_6 , L_18 , V_124 ) ;
V_93 = F_62 ( V_1 -> V_26 , V_181 ,
F_38 ( V_181 ) ) ;
if ( V_93 )
return V_93 ;
F_12 ( V_1 -> V_26 , V_182 , V_183 ) ;
F_12 ( V_1 -> V_26 , V_184 ,
V_185 ) ;
F_12 ( V_1 -> V_26 , V_186 , V_187 ) ;
F_15 ( V_1 , 0xffff ) ;
V_1 -> V_97 = V_171 ;
V_1 -> V_116 = F_63 ( V_171 -> V_120 , V_183 >> 1 ) ;
if ( ! V_1 -> V_116 )
return - V_177 ;
if ( V_171 -> V_98 ) {
F_64 ( & V_1 -> V_99 ) ;
V_93 = F_65 ( V_6 , V_171 -> V_98 , NULL ,
F_31 ,
V_188 , F_66 ( V_6 ) ,
V_1 ) ;
if ( V_93 )
goto V_189;
}
F_12 ( V_1 -> V_26 , V_190 ,
V_191 ) ;
F_24 ( V_1 ) ;
F_67 ( V_171 , V_1 ) ;
F_21 ( V_1 , & V_174 ) ;
return 0 ;
V_189:
F_68 ( V_1 -> V_116 ) ;
return V_93 ;
}
static int F_69 ( struct V_170 * V_171 )
{
struct V_1 * V_1 = F_70 ( V_171 ) ;
F_68 ( V_1 -> V_116 ) ;
F_41 ( V_1 -> V_40 ) ;
return 0 ;
}
static int F_71 ( struct V_170 * V_171 , struct V_192 * V_6 ,
struct V_193 * V_3 )
{
struct V_1 * V_1 = F_70 ( V_171 ) ;
V_3 -> V_4 = V_1 ;
V_3 -> V_194 = & V_195 ;
V_1 -> V_3 = & V_3 -> V_196 ;
return 0 ;
}
static int T_6 F_72 ( void )
{
return F_73 ( V_197 , & V_198 ) ;
}
static void T_7 F_74 ( void )
{
F_75 ( & V_198 ) ;
}
