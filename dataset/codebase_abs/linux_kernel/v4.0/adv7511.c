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
static bool F_22 ( struct V_1 * V_1 )
{
unsigned int V_83 ;
int V_84 ;
V_84 = F_23 ( V_1 -> V_26 , F_5 ( 0 ) , & V_83 ) ;
if ( V_84 < 0 )
return false ;
if ( V_83 & V_85 ) {
F_12 ( V_1 -> V_26 , F_5 ( 0 ) ,
V_85 ) ;
return true ;
}
return false ;
}
static T_3 F_24 ( int V_86 , void * V_87 )
{
struct V_1 * V_1 = V_87 ;
if ( F_22 ( V_1 ) )
F_25 ( V_1 -> V_3 -> V_6 ) ;
F_26 ( & V_1 -> V_88 ) ;
return V_89 ;
}
static unsigned int F_27 ( struct V_1 * V_1 ,
unsigned int V_86 )
{
unsigned int V_83 , V_90 ;
unsigned int V_91 ;
int V_84 ;
V_84 = F_23 ( V_1 -> V_26 , F_5 ( 0 ) , & V_83 ) ;
if ( V_84 < 0 )
return 0 ;
V_84 = F_23 ( V_1 -> V_26 , F_5 ( 1 ) , & V_90 ) ;
if ( V_84 < 0 )
return 0 ;
V_91 = ( V_90 << 8 ) | V_83 ;
return V_91 & V_86 ;
}
static int F_28 ( struct V_1 * V_1 , int V_86 ,
int V_92 )
{
unsigned int V_91 ;
int V_84 ;
if ( V_1 -> V_93 -> V_86 ) {
V_84 = F_29 ( V_1 -> V_88 ,
F_27 ( V_1 , V_86 ) ,
F_30 ( V_92 ) ) ;
if ( V_84 <= 0 )
return 0 ;
V_91 = F_27 ( V_1 , V_86 ) ;
} else {
if ( V_92 < 25 )
V_92 = 25 ;
do {
V_91 = F_27 ( V_1 , V_86 ) ;
if ( V_91 )
break;
F_31 ( 25 ) ;
V_92 -= 25 ;
} while ( V_92 >= 25 );
}
return V_91 ;
}
static int F_32 ( void * V_94 , T_4 * V_95 , unsigned int V_96 ,
T_5 V_97 )
{
struct V_1 * V_1 = V_94 ;
struct V_98 V_99 [ 2 ] ;
T_2 V_100 ;
unsigned int V_25 ;
int V_84 ;
if ( V_97 > 128 )
return - V_101 ;
if ( V_1 -> V_102 != V_96 / 2 ) {
unsigned int V_103 ;
V_84 = F_23 ( V_1 -> V_26 , V_19 ,
& V_103 ) ;
if ( V_84 < 0 )
return V_84 ;
if ( V_103 != 2 ) {
F_12 ( V_1 -> V_26 , V_104 ,
V_96 ) ;
V_84 = F_28 ( V_1 ,
V_105 |
V_106 , 200 ) ;
if ( ! ( V_84 & V_105 ) )
return - V_107 ;
}
F_12 ( V_1 -> V_26 , F_5 ( 0 ) ,
V_105 | V_106 ) ;
V_99 [ 0 ] . V_108 = V_1 -> V_109 -> V_108 ;
V_99 [ 0 ] . V_110 = 0 ;
V_99 [ 0 ] . V_97 = 1 ;
V_99 [ 0 ] . V_95 = & V_100 ;
V_99 [ 1 ] . V_108 = V_1 -> V_109 -> V_108 ;
V_99 [ 1 ] . V_110 = V_111 ;
V_99 [ 1 ] . V_97 = 64 ;
V_99 [ 1 ] . V_95 = V_1 -> V_112 ;
V_100 = 0 ;
for ( V_25 = 0 ; V_25 < 4 ; ++ V_25 ) {
V_84 = F_33 ( V_1 -> V_109 -> V_113 , V_99 ,
F_34 ( V_99 ) ) ;
if ( V_84 < 0 )
return V_84 ;
else if ( V_84 != 2 )
return - V_107 ;
V_99 [ 1 ] . V_95 += 64 ;
V_100 += 64 ;
}
V_1 -> V_102 = V_96 / 2 ;
}
if ( V_96 % 2 == 0 )
memcpy ( V_95 , V_1 -> V_112 , V_97 ) ;
else
memcpy ( V_95 , V_1 -> V_112 + 128 , V_97 ) ;
return 0 ;
}
static int F_35 ( struct V_2 * V_3 ,
struct V_31 * V_32 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_40 * V_40 ;
unsigned int V_114 ;
if ( V_1 -> V_115 != V_116 ) {
F_12 ( V_1 -> V_26 , F_5 ( 0 ) ,
V_105 | V_106 ) ;
F_10 ( V_1 -> V_26 , V_117 ,
V_118 , 0 ) ;
V_1 -> V_102 = - 1 ;
}
V_40 = F_36 ( V_32 , F_32 , V_1 ) ;
if ( V_1 -> V_115 != V_116 )
F_10 ( V_1 -> V_26 , V_117 ,
V_118 ,
V_118 ) ;
F_37 ( V_1 -> V_40 ) ;
V_1 -> V_40 = V_40 ;
if ( ! V_40 )
return 0 ;
F_38 ( V_32 , V_40 ) ;
V_114 = F_39 ( V_32 , V_40 ) ;
F_16 ( V_1 , V_32 , V_1 -> V_33 ) ;
return V_114 ;
}
static void F_40 ( struct V_2 * V_3 , int V_38 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
switch ( V_38 ) {
case V_116 :
V_1 -> V_102 = - 1 ;
F_12 ( V_1 -> V_26 , F_5 ( 0 ) ,
V_105 | V_106 ) ;
F_10 ( V_1 -> V_26 , V_117 ,
V_118 , 0 ) ;
F_10 ( V_1 -> V_26 , V_119 ,
V_120 ,
V_121 ) ;
F_41 ( V_1 -> V_26 ) ;
break;
default:
F_10 ( V_1 -> V_26 , V_117 ,
V_118 ,
V_118 ) ;
F_42 ( V_1 -> V_26 ) ;
break;
}
V_1 -> V_115 = V_38 ;
}
static enum V_122
F_43 ( struct V_2 * V_3 ,
struct V_31 * V_32 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_122 V_103 ;
unsigned int V_123 ;
bool V_124 ;
int V_84 ;
V_84 = F_23 ( V_1 -> V_26 , V_15 , & V_123 ) ;
if ( V_84 < 0 )
return V_125 ;
if ( V_123 & V_126 )
V_103 = V_127 ;
else
V_103 = V_125 ;
V_124 = F_22 ( V_1 ) ;
if ( V_103 == V_127 && V_124 &&
V_1 -> V_115 == V_116 ) {
F_42 ( V_1 -> V_26 ) ;
F_40 ( V_3 , V_1 -> V_115 ) ;
F_35 ( V_3 , V_32 ) ;
if ( V_1 -> V_103 == V_127 )
V_103 = V_125 ;
} else {
F_10 ( V_1 -> V_26 , V_119 ,
V_120 ,
V_128 ) ;
}
V_1 -> V_103 = V_103 ;
return V_103 ;
}
static int F_44 ( struct V_2 * V_3 ,
struct V_129 * V_38 )
{
if ( V_38 -> clock > 165000 )
return V_130 ;
return V_131 ;
}
static void F_45 ( struct V_2 * V_3 ,
struct V_129 * V_38 ,
struct V_129 * V_132 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned int V_133 ;
unsigned int V_81 = 0 ;
unsigned int V_82 = 0 ;
if ( V_1 -> V_73 ) {
unsigned int V_134 , V_135 ;
unsigned int V_136 , V_137 ;
V_134 = V_132 -> V_138 -
V_132 -> V_139 ;
V_136 = V_132 -> V_140 -
V_132 -> V_141 ;
V_135 = V_132 -> V_142 -
V_132 -> V_138 ;
V_137 = V_132 -> V_143 -
V_132 -> V_140 ;
V_136 += 1 ;
F_12 ( V_1 -> V_26 , V_144 ,
( ( V_134 >> 10 ) & 0x7 ) << 5 ) ;
F_12 ( V_1 -> V_26 , F_46 ( 0 ) ,
( V_134 >> 2 ) & 0xff ) ;
F_12 ( V_1 -> V_26 , F_46 ( 1 ) ,
( ( V_134 & 0x3 ) << 6 ) |
( ( V_135 >> 4 ) & 0x3f ) ) ;
F_12 ( V_1 -> V_26 , F_46 ( 2 ) ,
( ( V_135 & 0xf ) << 4 ) |
( ( V_136 >> 6 ) & 0xf ) ) ;
F_12 ( V_1 -> V_26 , F_46 ( 3 ) ,
( ( V_136 & 0x3f ) << 2 ) |
( ( V_137 >> 8 ) & 0x3 ) ) ;
F_12 ( V_1 -> V_26 , F_46 ( 4 ) ,
V_137 & 0xff ) ;
V_81 = ! ( V_132 -> V_110 & V_145 ) ;
V_82 = ! ( V_132 -> V_110 & V_146 ) ;
} else {
enum V_147 V_148 ;
enum V_147 V_149 ;
if ( V_132 -> V_110 & V_150 )
V_148 = V_151 ;
else
V_148 = V_152 ;
if ( V_132 -> V_110 & V_153 )
V_149 = V_151 ;
else
V_149 = V_152 ;
if ( V_1 -> V_81 != V_148 &&
V_1 -> V_81 !=
V_154 )
V_81 = 1 ;
if ( V_1 -> V_82 != V_149 &&
V_1 -> V_82 !=
V_154 )
V_82 = 1 ;
}
if ( V_38 -> V_155 <= 24000 )
V_133 = V_156 ;
else if ( V_38 -> V_155 <= 25000 )
V_133 = V_157 ;
else if ( V_38 -> V_155 <= 30000 )
V_133 = V_158 ;
else
V_133 = V_159 ;
F_10 ( V_1 -> V_26 , 0xfb ,
0x6 , V_133 << 1 ) ;
F_10 ( V_1 -> V_26 , 0x17 ,
0x60 , ( V_82 << 6 ) | ( V_81 << 5 ) ) ;
V_1 -> V_160 = V_38 -> clock ;
}
static int F_47 ( struct V_161 * V_162 ,
struct V_64 * V_35 )
{
const char * V_163 ;
int V_84 ;
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
F_48 ( V_162 , L_1 , & V_35 -> V_69 ) ;
if ( V_35 -> V_69 != 8 && V_35 -> V_69 != 10 &&
V_35 -> V_69 != 12 )
return - V_101 ;
V_84 = F_49 ( V_162 , L_2 , & V_163 ) ;
if ( V_84 < 0 )
return V_84 ;
if ( ! strcmp ( V_163 , L_3 ) )
V_35 -> V_70 = V_47 ;
else if ( ! strcmp ( V_163 , L_4 ) )
V_35 -> V_70 = V_55 ;
else if ( ! strcmp ( V_163 , L_5 ) )
V_35 -> V_70 = V_57 ;
else
return - V_101 ;
V_84 = F_49 ( V_162 , L_6 , & V_163 ) ;
if ( V_84 < 0 )
return V_84 ;
if ( ! strcmp ( V_163 , L_7 ) )
V_35 -> V_71 = V_164 ;
else if ( ! strcmp ( V_163 , L_8 ) )
V_35 -> V_71 = V_74 ;
else if ( ! strcmp ( V_163 , L_9 ) )
V_35 -> V_71 = V_72 ;
else
return - V_101 ;
if ( V_35 -> V_70 == V_55 ||
V_35 -> V_71 != V_164 ) {
V_84 = F_48 ( V_162 , L_10 ,
& V_35 -> V_76 ) ;
if ( V_84 )
return V_84 ;
if ( V_35 -> V_76 < 1 || V_35 -> V_76 > 3 )
return - V_101 ;
V_84 = F_49 ( V_162 , L_11 ,
& V_163 ) ;
if ( V_84 < 0 )
return V_84 ;
if ( ! strcmp ( V_163 , L_12 ) )
V_35 -> V_78 =
V_165 ;
else if ( ! strcmp ( V_163 , L_13 ) )
V_35 -> V_78 =
V_166 ;
else if ( ! strcmp ( V_163 , L_14 ) )
V_35 -> V_78 =
V_167 ;
else
return - V_101 ;
} else {
V_35 -> V_76 = 1 ;
V_35 -> V_78 = V_165 ;
}
F_48 ( V_162 , L_15 , & V_35 -> V_66 ) ;
if ( V_35 -> V_66 < - 1200 || V_35 -> V_66 > 1600 )
return - V_101 ;
V_35 -> V_73 = F_50 ( V_162 , L_16 ) ;
V_35 -> V_80 = V_168 ;
V_35 -> V_82 = V_154 ;
V_35 -> V_81 = V_154 ;
return 0 ;
}
static int F_51 ( struct V_169 * V_170 , const struct V_171 * V_172 )
{
struct V_64 V_173 ;
struct V_1 * V_1 ;
struct V_5 * V_6 = & V_170 -> V_6 ;
unsigned int V_123 ;
int V_84 ;
if ( ! V_6 -> V_174 )
return - V_101 ;
V_1 = F_52 ( V_6 , sizeof( * V_1 ) , V_175 ) ;
if ( ! V_1 )
return - V_176 ;
V_1 -> V_115 = V_177 ;
V_1 -> V_103 = V_125 ;
V_84 = F_47 ( V_6 -> V_174 , & V_173 ) ;
if ( V_84 )
return V_84 ;
V_1 -> V_178 = F_53 ( V_6 , L_17 , V_179 ) ;
if ( F_54 ( V_1 -> V_178 ) )
return F_55 ( V_1 -> V_178 ) ;
if ( V_1 -> V_178 ) {
F_56 ( 5 ) ;
F_57 ( V_1 -> V_178 , 0 ) ;
}
V_1 -> V_26 = F_58 ( V_170 , & V_180 ) ;
if ( F_54 ( V_1 -> V_26 ) )
return F_55 ( V_1 -> V_26 ) ;
V_84 = F_23 ( V_1 -> V_26 , V_8 , & V_123 ) ;
if ( V_84 )
return V_84 ;
F_59 ( V_6 , L_18 , V_123 ) ;
V_84 = F_60 ( V_1 -> V_26 , V_181 ,
F_34 ( V_181 ) ) ;
if ( V_84 )
return V_84 ;
F_12 ( V_1 -> V_26 , V_182 , V_183 ) ;
F_12 ( V_1 -> V_26 , V_184 ,
V_185 ) ;
F_12 ( V_1 -> V_26 , V_186 , V_187 ) ;
F_15 ( V_1 , 0xffff ) ;
V_1 -> V_93 = V_170 ;
V_1 -> V_109 = F_61 ( V_170 -> V_113 , V_183 >> 1 ) ;
if ( ! V_1 -> V_109 )
return - V_176 ;
if ( V_170 -> V_86 ) {
F_62 ( & V_1 -> V_88 ) ;
V_84 = F_63 ( V_6 , V_170 -> V_86 , NULL ,
F_24 ,
V_188 , F_64 ( V_6 ) ,
V_1 ) ;
if ( V_84 )
goto V_189;
}
F_12 ( V_1 -> V_26 , V_190 ,
V_191 ) ;
F_10 ( V_1 -> V_26 , V_117 ,
V_118 , V_118 ) ;
V_1 -> V_102 = - 1 ;
F_65 ( V_170 , V_1 ) ;
F_21 ( V_1 , & V_173 ) ;
return 0 ;
V_189:
F_66 ( V_1 -> V_109 ) ;
return V_84 ;
}
static int F_67 ( struct V_169 * V_170 )
{
struct V_1 * V_1 = F_68 ( V_170 ) ;
F_66 ( V_1 -> V_109 ) ;
F_37 ( V_1 -> V_40 ) ;
return 0 ;
}
static int F_69 ( struct V_169 * V_170 , struct V_192 * V_6 ,
struct V_193 * V_3 )
{
struct V_1 * V_1 = F_68 ( V_170 ) ;
V_3 -> V_4 = V_1 ;
V_3 -> V_194 = & V_195 ;
V_1 -> V_3 = & V_3 -> V_196 ;
return 0 ;
}
static int T_6 F_70 ( void )
{
return F_71 ( V_197 , & V_198 ) ;
}
static void T_7 F_72 ( void )
{
F_73 ( & V_198 ) ;
}
