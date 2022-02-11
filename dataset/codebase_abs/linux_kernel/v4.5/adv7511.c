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
case V_20 :
case F_8 ( 0 ) :
case F_8 ( 1 ) :
case V_21 :
case V_22 :
return true ;
}
return false ;
}
static void F_9 ( struct V_1 * V_1 , bool V_23 ,
const T_1 * V_24 ,
unsigned int V_25 )
{
unsigned int V_26 ;
F_10 ( V_1 -> V_27 , F_11 ( 1 ) ,
V_28 , V_28 ) ;
if ( V_23 ) {
for ( V_26 = 0 ; V_26 < 12 ; ++ V_26 ) {
F_10 ( V_1 -> V_27 ,
F_11 ( V_26 ) ,
0x1f , V_24 [ V_26 ] >> 8 ) ;
F_12 ( V_1 -> V_27 ,
F_13 ( V_26 ) ,
V_24 [ V_26 ] & 0xff ) ;
}
}
if ( V_23 )
F_10 ( V_1 -> V_27 , F_11 ( 0 ) ,
0xe0 , 0x80 | ( V_25 << 5 ) ) ;
else
F_10 ( V_1 -> V_27 , F_11 ( 0 ) ,
0x80 , 0x00 ) ;
F_10 ( V_1 -> V_27 , F_11 ( 1 ) ,
V_28 , 0 ) ;
}
static int F_14 ( struct V_1 * V_1 , unsigned int V_29 )
{
if ( V_29 & 0xff )
F_10 ( V_1 -> V_27 , V_30 ,
V_29 , 0xff ) ;
if ( V_29 & 0xff00 ) {
V_29 >>= 8 ;
F_10 ( V_1 -> V_27 , V_31 ,
V_29 , 0xff ) ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_1 , unsigned int V_29 )
{
if ( V_29 & 0xff )
F_10 ( V_1 -> V_27 , V_30 ,
V_29 , 0x00 ) ;
if ( V_29 & 0xff00 ) {
V_29 >>= 8 ;
F_10 ( V_1 -> V_27 , V_31 ,
V_29 , 0x00 ) ;
}
return 0 ;
}
static void F_16 ( struct V_1 * V_1 ,
struct V_32 * V_33 ,
bool V_34 )
{
struct V_35 V_36 ;
bool V_37 , V_38 ;
unsigned int V_39 ;
T_2 V_40 [ 17 ] ;
if ( V_1 -> V_41 )
V_36 . V_42 = F_17 ( V_1 -> V_41 ) ;
else
V_36 . V_42 = false ;
F_18 ( & V_36 . V_43 ) ;
V_36 . V_43 . V_44 = V_45 ;
if ( V_34 ) {
V_36 . V_46 = false ;
V_36 . V_43 . V_47 = V_48 ;
} else {
V_36 . V_49 = V_50 ;
V_36 . V_51 = V_52 ;
if ( ( V_33 -> V_53 . V_54 &
V_55 ) &&
V_36 . V_42 ) {
V_36 . V_46 = false ;
V_36 . V_43 . V_47 =
V_56 ;
} else {
V_36 . V_46 = true ;
V_36 . V_43 . V_47 = V_48 ;
}
}
if ( V_36 . V_42 ) {
V_39 = V_57 ;
switch ( V_36 . V_43 . V_47 ) {
case V_58 :
V_37 = false ;
V_38 = true ;
break;
case V_56 :
V_37 = true ;
V_38 = true ;
break;
default:
V_37 = false ;
V_38 = false ;
break;
}
} else {
V_39 = V_59 ;
V_37 = false ;
V_38 = false ;
}
F_15 ( V_1 , V_60 ) ;
F_9 ( V_1 , V_36 . V_46 ,
V_36 . V_51 ,
V_36 . V_49 ) ;
F_10 ( V_1 -> V_27 , V_61 , 0x81 ,
( V_37 << 7 ) | V_38 ) ;
F_10 ( V_1 -> V_27 , V_62 ,
V_63 , V_39 ) ;
F_19 ( & V_36 . V_43 , V_40 ,
sizeof( V_40 ) ) ;
F_20 ( V_1 -> V_27 , V_64 ,
V_40 + 1 , sizeof( V_40 ) - 1 ) ;
F_14 ( V_1 , V_60 ) ;
}
static void F_21 ( struct V_1 * V_1 ,
const struct V_65 * V_36 )
{
static const unsigned int V_66 [ 4 ] = { 0 , 2 , 1 , 3 } ;
unsigned int V_67 ;
unsigned int V_68 ;
unsigned int V_69 ;
V_67 = ( V_36 -> V_67 + 1200 ) / 400 ;
V_68 = V_36 -> V_70 == 8 ? 3
: ( V_36 -> V_70 == 10 ? 1 : 2 ) ;
if ( V_36 -> V_71 != V_56 )
V_69 = V_36 -> V_72 == V_73
? 5 : 0 ;
else if ( V_36 -> V_72 == V_73 )
V_69 = V_36 -> V_74 ? 8 : 7 ;
else if ( V_36 -> V_72 == V_75 )
V_69 = V_36 -> V_74 ? 4 : 3 ;
else
V_69 = V_36 -> V_74 ? 2 : 1 ;
F_10 ( V_1 -> V_27 , V_76 , 0xf ,
V_69 ) ;
F_10 ( V_1 -> V_27 , V_61 , 0x7e ,
( V_68 << 4 ) |
( V_66 [ V_36 -> V_77 ] << 2 ) ) ;
F_12 ( V_1 -> V_27 , V_78 ,
V_36 -> V_79 << 3 ) ;
F_12 ( V_1 -> V_27 , V_80 ,
V_36 -> V_81 << 2 ) ;
F_12 ( V_1 -> V_27 , 0xba , V_67 << 5 ) ;
V_1 -> V_74 = V_36 -> V_74 ;
V_1 -> V_82 = V_36 -> V_82 ;
V_1 -> V_83 = V_36 -> V_83 ;
V_1 -> V_34 = V_36 -> V_71 == V_48 ;
}
static void F_22 ( struct V_1 * V_1 )
{
V_1 -> V_84 = - 1 ;
F_10 ( V_1 -> V_27 , V_85 ,
V_86 , 0 ) ;
if ( V_1 -> V_87 -> V_88 ) {
F_12 ( V_1 -> V_27 , F_23 ( 0 ) ,
V_89 ) ;
F_12 ( V_1 -> V_27 , F_23 ( 1 ) ,
V_90 ) ;
}
F_10 ( V_1 -> V_27 , V_91 ,
V_92 ,
V_93 ) ;
F_24 ( V_1 -> V_27 ) ;
V_1 -> V_94 = true ;
}
static void F_25 ( struct V_1 * V_1 )
{
F_10 ( V_1 -> V_27 , V_85 ,
V_86 ,
V_86 ) ;
F_26 ( V_1 -> V_27 ) ;
V_1 -> V_94 = false ;
}
static bool F_27 ( struct V_1 * V_1 )
{
unsigned int V_95 ;
int V_96 ;
V_96 = F_28 ( V_1 -> V_27 , F_5 ( 0 ) , & V_95 ) ;
if ( V_96 < 0 )
return false ;
if ( V_95 & V_97 ) {
F_12 ( V_1 -> V_27 , F_5 ( 0 ) ,
V_97 ) ;
return true ;
}
return false ;
}
static int F_29 ( struct V_1 * V_1 )
{
unsigned int V_95 , V_98 ;
int V_96 ;
V_96 = F_28 ( V_1 -> V_27 , F_5 ( 0 ) , & V_95 ) ;
if ( V_96 < 0 )
return V_96 ;
V_96 = F_28 ( V_1 -> V_27 , F_5 ( 1 ) , & V_98 ) ;
if ( V_96 < 0 )
return V_96 ;
F_12 ( V_1 -> V_27 , F_5 ( 0 ) , V_95 ) ;
F_12 ( V_1 -> V_27 , F_5 ( 1 ) , V_98 ) ;
if ( V_95 & V_97 && V_1 -> V_3 )
F_30 ( V_1 -> V_3 -> V_6 ) ;
if ( V_95 & V_89 || V_98 & V_90 ) {
V_1 -> V_99 = true ;
if ( V_1 -> V_87 -> V_88 )
F_31 ( & V_1 -> V_100 ) ;
}
return 0 ;
}
static T_3 F_32 ( int V_88 , void * V_101 )
{
struct V_1 * V_1 = V_101 ;
int V_96 ;
V_96 = F_29 ( V_1 ) ;
return V_96 < 0 ? V_102 : V_103 ;
}
static int F_33 ( struct V_1 * V_1 , int V_104 )
{
int V_96 ;
if ( V_1 -> V_87 -> V_88 ) {
V_96 = F_34 ( V_1 -> V_100 ,
V_1 -> V_99 , F_35 ( V_104 ) ) ;
} else {
for (; V_104 > 0 ; V_104 -= 25 ) {
V_96 = F_29 ( V_1 ) ;
if ( V_96 < 0 )
break;
if ( V_1 -> V_99 )
break;
F_36 ( 25 ) ;
}
}
return V_1 -> V_99 ? 0 : - V_105 ;
}
static int F_37 ( void * V_106 , T_4 * V_107 , unsigned int V_108 ,
T_5 V_109 )
{
struct V_1 * V_1 = V_106 ;
struct V_110 V_111 [ 2 ] ;
T_2 V_112 ;
unsigned int V_26 ;
int V_96 ;
if ( V_109 > 128 )
return - V_113 ;
if ( V_1 -> V_84 != V_108 / 2 ) {
unsigned int V_114 ;
V_96 = F_28 ( V_1 -> V_27 , V_19 ,
& V_114 ) ;
if ( V_96 < 0 )
return V_96 ;
if ( V_114 != 2 ) {
V_1 -> V_99 = false ;
F_12 ( V_1 -> V_27 , V_115 ,
V_108 ) ;
V_96 = F_33 ( V_1 , 200 ) ;
if ( V_96 < 0 )
return V_96 ;
}
V_111 [ 0 ] . V_116 = V_1 -> V_117 -> V_116 ;
V_111 [ 0 ] . V_118 = 0 ;
V_111 [ 0 ] . V_109 = 1 ;
V_111 [ 0 ] . V_107 = & V_112 ;
V_111 [ 1 ] . V_116 = V_1 -> V_117 -> V_116 ;
V_111 [ 1 ] . V_118 = V_119 ;
V_111 [ 1 ] . V_109 = 64 ;
V_111 [ 1 ] . V_107 = V_1 -> V_120 ;
V_112 = 0 ;
for ( V_26 = 0 ; V_26 < 4 ; ++ V_26 ) {
V_96 = F_38 ( V_1 -> V_117 -> V_121 , V_111 ,
F_39 ( V_111 ) ) ;
if ( V_96 < 0 )
return V_96 ;
else if ( V_96 != 2 )
return - V_105 ;
V_111 [ 1 ] . V_107 += 64 ;
V_112 += 64 ;
}
V_1 -> V_84 = V_108 / 2 ;
}
if ( V_108 % 2 == 0 )
memcpy ( V_107 , V_1 -> V_120 , V_109 ) ;
else
memcpy ( V_107 , V_1 -> V_120 + 128 , V_109 ) ;
return 0 ;
}
static int F_40 ( struct V_2 * V_3 ,
struct V_32 * V_33 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_41 * V_41 ;
unsigned int V_122 ;
if ( ! V_1 -> V_94 ) {
F_10 ( V_1 -> V_27 , V_85 ,
V_86 , 0 ) ;
if ( V_1 -> V_87 -> V_88 ) {
F_12 ( V_1 -> V_27 , F_23 ( 0 ) ,
V_89 ) ;
F_12 ( V_1 -> V_27 , F_23 ( 1 ) ,
V_90 ) ;
}
V_1 -> V_84 = - 1 ;
}
V_41 = F_41 ( V_33 , F_37 , V_1 ) ;
if ( ! V_1 -> V_94 )
F_10 ( V_1 -> V_27 , V_85 ,
V_86 ,
V_86 ) ;
F_42 ( V_1 -> V_41 ) ;
V_1 -> V_41 = V_41 ;
if ( ! V_41 )
return 0 ;
F_43 ( V_33 , V_41 ) ;
V_122 = F_44 ( V_33 , V_41 ) ;
F_16 ( V_1 , V_33 , V_1 -> V_34 ) ;
return V_122 ;
}
static void F_45 ( struct V_2 * V_3 , int V_39 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_39 == V_123 )
F_22 ( V_1 ) ;
else
F_25 ( V_1 ) ;
}
static enum V_124
F_46 ( struct V_2 * V_3 ,
struct V_32 * V_33 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_124 V_114 ;
unsigned int V_125 ;
bool V_126 ;
int V_96 ;
V_96 = F_28 ( V_1 -> V_27 , V_15 , & V_125 ) ;
if ( V_96 < 0 )
return V_127 ;
if ( V_125 & V_128 )
V_114 = V_129 ;
else
V_114 = V_127 ;
V_126 = F_27 ( V_1 ) ;
if ( V_114 == V_129 && V_126 && V_1 -> V_94 ) {
F_26 ( V_1 -> V_27 ) ;
F_22 ( V_1 ) ;
F_40 ( V_3 , V_33 ) ;
if ( V_1 -> V_114 == V_129 )
V_114 = V_127 ;
} else {
F_10 ( V_1 -> V_27 , V_91 ,
V_92 ,
V_130 ) ;
}
V_1 -> V_114 = V_114 ;
return V_114 ;
}
static int F_47 ( struct V_2 * V_3 ,
struct V_131 * V_39 )
{
if ( V_39 -> clock > 165000 )
return V_132 ;
return V_133 ;
}
static void F_48 ( struct V_2 * V_3 ,
struct V_131 * V_39 ,
struct V_131 * V_134 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned int V_135 ;
unsigned int V_82 = 0 ;
unsigned int V_83 = 0 ;
if ( V_1 -> V_74 ) {
unsigned int V_136 , V_137 ;
unsigned int V_138 , V_139 ;
V_136 = V_134 -> V_140 -
V_134 -> V_141 ;
V_138 = V_134 -> V_142 -
V_134 -> V_143 ;
V_137 = V_134 -> V_144 -
V_134 -> V_140 ;
V_139 = V_134 -> V_145 -
V_134 -> V_142 ;
V_138 += 1 ;
F_12 ( V_1 -> V_27 , V_146 ,
( ( V_136 >> 10 ) & 0x7 ) << 5 ) ;
F_12 ( V_1 -> V_27 , F_49 ( 0 ) ,
( V_136 >> 2 ) & 0xff ) ;
F_12 ( V_1 -> V_27 , F_49 ( 1 ) ,
( ( V_136 & 0x3 ) << 6 ) |
( ( V_137 >> 4 ) & 0x3f ) ) ;
F_12 ( V_1 -> V_27 , F_49 ( 2 ) ,
( ( V_137 & 0xf ) << 4 ) |
( ( V_138 >> 6 ) & 0xf ) ) ;
F_12 ( V_1 -> V_27 , F_49 ( 3 ) ,
( ( V_138 & 0x3f ) << 2 ) |
( ( V_139 >> 8 ) & 0x3 ) ) ;
F_12 ( V_1 -> V_27 , F_49 ( 4 ) ,
V_139 & 0xff ) ;
V_82 = ! ( V_134 -> V_118 & V_147 ) ;
V_83 = ! ( V_134 -> V_118 & V_148 ) ;
} else {
enum V_149 V_150 ;
enum V_149 V_151 ;
if ( V_134 -> V_118 & V_152 )
V_150 = V_153 ;
else
V_150 = V_154 ;
if ( V_134 -> V_118 & V_155 )
V_151 = V_153 ;
else
V_151 = V_154 ;
if ( V_1 -> V_82 != V_150 &&
V_1 -> V_82 !=
V_156 )
V_82 = 1 ;
if ( V_1 -> V_83 != V_151 &&
V_1 -> V_83 !=
V_156 )
V_83 = 1 ;
}
if ( V_39 -> V_157 <= 24000 )
V_135 = V_158 ;
else if ( V_39 -> V_157 <= 25000 )
V_135 = V_159 ;
else if ( V_39 -> V_157 <= 30000 )
V_135 = V_160 ;
else
V_135 = V_161 ;
F_10 ( V_1 -> V_27 , 0xfb ,
0x6 , V_135 << 1 ) ;
F_10 ( V_1 -> V_27 , 0x17 ,
0x60 , ( V_83 << 6 ) | ( V_82 << 5 ) ) ;
V_1 -> V_162 = V_39 -> clock ;
}
static int F_50 ( struct V_163 * V_164 ,
struct V_65 * V_36 )
{
const char * V_165 ;
int V_96 ;
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
F_51 ( V_164 , L_1 , & V_36 -> V_70 ) ;
if ( V_36 -> V_70 != 8 && V_36 -> V_70 != 10 &&
V_36 -> V_70 != 12 )
return - V_113 ;
V_96 = F_52 ( V_164 , L_2 , & V_165 ) ;
if ( V_96 < 0 )
return V_96 ;
if ( ! strcmp ( V_165 , L_3 ) )
V_36 -> V_71 = V_48 ;
else if ( ! strcmp ( V_165 , L_4 ) )
V_36 -> V_71 = V_56 ;
else if ( ! strcmp ( V_165 , L_5 ) )
V_36 -> V_71 = V_58 ;
else
return - V_113 ;
V_96 = F_52 ( V_164 , L_6 , & V_165 ) ;
if ( V_96 < 0 )
return V_96 ;
if ( ! strcmp ( V_165 , L_7 ) )
V_36 -> V_72 = V_166 ;
else if ( ! strcmp ( V_165 , L_8 ) )
V_36 -> V_72 = V_75 ;
else if ( ! strcmp ( V_165 , L_9 ) )
V_36 -> V_72 = V_73 ;
else
return - V_113 ;
if ( V_36 -> V_71 == V_56 ||
V_36 -> V_72 != V_166 ) {
V_96 = F_51 ( V_164 , L_10 ,
& V_36 -> V_77 ) ;
if ( V_96 )
return V_96 ;
if ( V_36 -> V_77 < 1 || V_36 -> V_77 > 3 )
return - V_113 ;
V_96 = F_52 ( V_164 , L_11 ,
& V_165 ) ;
if ( V_96 < 0 )
return V_96 ;
if ( ! strcmp ( V_165 , L_12 ) )
V_36 -> V_79 =
V_167 ;
else if ( ! strcmp ( V_165 , L_13 ) )
V_36 -> V_79 =
V_168 ;
else if ( ! strcmp ( V_165 , L_14 ) )
V_36 -> V_79 =
V_169 ;
else
return - V_113 ;
} else {
V_36 -> V_77 = 1 ;
V_36 -> V_79 = V_167 ;
}
F_51 ( V_164 , L_15 , & V_36 -> V_67 ) ;
if ( V_36 -> V_67 < - 1200 || V_36 -> V_67 > 1600 )
return - V_113 ;
V_36 -> V_74 = F_53 ( V_164 , L_16 ) ;
V_36 -> V_81 = V_170 ;
V_36 -> V_83 = V_156 ;
V_36 -> V_82 = V_156 ;
return 0 ;
}
static int F_54 ( struct V_171 * V_172 , const struct V_173 * V_174 )
{
struct V_65 V_175 ;
struct V_1 * V_1 ;
struct V_5 * V_6 = & V_172 -> V_6 ;
unsigned int V_125 ;
int V_96 ;
if ( ! V_6 -> V_176 )
return - V_113 ;
V_1 = F_55 ( V_6 , sizeof( * V_1 ) , V_177 ) ;
if ( ! V_1 )
return - V_178 ;
V_1 -> V_94 = false ;
V_1 -> V_114 = V_127 ;
V_96 = F_50 ( V_6 -> V_176 , & V_175 ) ;
if ( V_96 )
return V_96 ;
V_1 -> V_179 = F_56 ( V_6 , L_17 , V_180 ) ;
if ( F_57 ( V_1 -> V_179 ) )
return F_58 ( V_1 -> V_179 ) ;
if ( V_1 -> V_179 ) {
F_59 ( 5 ) ;
F_60 ( V_1 -> V_179 , 0 ) ;
}
V_1 -> V_27 = F_61 ( V_172 , & V_181 ) ;
if ( F_57 ( V_1 -> V_27 ) )
return F_58 ( V_1 -> V_27 ) ;
V_96 = F_28 ( V_1 -> V_27 , V_8 , & V_125 ) ;
if ( V_96 )
return V_96 ;
F_62 ( V_6 , L_18 , V_125 ) ;
V_96 = F_63 ( V_1 -> V_27 , V_182 ,
F_39 ( V_182 ) ) ;
if ( V_96 )
return V_96 ;
F_12 ( V_1 -> V_27 , V_183 , V_184 ) ;
F_12 ( V_1 -> V_27 , V_185 ,
V_186 ) ;
F_12 ( V_1 -> V_27 , V_187 , V_188 ) ;
F_15 ( V_1 , 0xffff ) ;
V_1 -> V_87 = V_172 ;
V_1 -> V_117 = F_64 ( V_172 -> V_121 , V_184 >> 1 ) ;
if ( ! V_1 -> V_117 )
return - V_178 ;
if ( V_172 -> V_88 ) {
F_65 ( & V_1 -> V_100 ) ;
V_96 = F_66 ( V_6 , V_172 -> V_88 , NULL ,
F_32 ,
V_189 , F_67 ( V_6 ) ,
V_1 ) ;
if ( V_96 )
goto V_190;
}
F_12 ( V_1 -> V_27 , V_191 ,
V_192 ) ;
F_25 ( V_1 ) ;
F_68 ( V_172 , V_1 ) ;
F_21 ( V_1 , & V_175 ) ;
return 0 ;
V_190:
F_69 ( V_1 -> V_117 ) ;
return V_96 ;
}
static int F_70 ( struct V_171 * V_172 )
{
struct V_1 * V_1 = F_71 ( V_172 ) ;
F_69 ( V_1 -> V_117 ) ;
F_42 ( V_1 -> V_41 ) ;
return 0 ;
}
static int F_72 ( struct V_171 * V_172 , struct V_193 * V_6 ,
struct V_194 * V_3 )
{
struct V_1 * V_1 = F_71 ( V_172 ) ;
V_3 -> V_4 = V_1 ;
V_3 -> V_195 = & V_196 ;
V_1 -> V_3 = & V_3 -> V_197 ;
return 0 ;
}
static int T_6 F_73 ( void )
{
return F_74 ( V_198 , & V_199 ) ;
}
static void T_7 F_75 ( void )
{
F_76 ( & V_199 ) ;
}
