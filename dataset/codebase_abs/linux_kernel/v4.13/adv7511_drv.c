static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case F_2 ( 1 ) :
case F_3 ( 0 ) :
case F_3 ( 1 ) :
case V_12 :
case F_4 ( 0 ) :
case F_4 ( 1 ) :
case F_4 ( 2 ) :
case F_4 ( 3 ) :
case F_4 ( 4 ) :
case F_4 ( 5 ) :
case F_4 ( 6 ) :
case F_4 ( 7 ) :
case V_13 :
case V_14 :
case F_5 ( 0 ) :
case F_5 ( 1 ) :
case F_5 ( 2 ) :
case F_5 ( 3 ) :
case F_5 ( 4 ) :
case V_15 :
case V_16 :
case F_6 ( 0 ) :
case F_6 ( 1 ) :
case V_17 :
case V_18 :
return true ;
}
return false ;
}
static void F_7 ( struct V_19 * V_19 , bool V_20 ,
const T_1 * V_21 ,
unsigned int V_22 )
{
unsigned int V_23 ;
F_8 ( V_19 -> V_24 , F_9 ( 1 ) ,
V_25 , V_25 ) ;
if ( V_20 ) {
for ( V_23 = 0 ; V_23 < 12 ; ++ V_23 ) {
F_8 ( V_19 -> V_24 ,
F_9 ( V_23 ) ,
0x1f , V_21 [ V_23 ] >> 8 ) ;
F_10 ( V_19 -> V_24 ,
F_11 ( V_23 ) ,
V_21 [ V_23 ] & 0xff ) ;
}
}
if ( V_20 )
F_8 ( V_19 -> V_24 , F_9 ( 0 ) ,
0xe0 , 0x80 | ( V_22 << 5 ) ) ;
else
F_8 ( V_19 -> V_24 , F_9 ( 0 ) ,
0x80 , 0x00 ) ;
F_8 ( V_19 -> V_24 , F_9 ( 1 ) ,
V_25 , 0 ) ;
}
static int F_12 ( struct V_19 * V_19 , unsigned int V_26 )
{
if ( V_26 & 0xff )
F_8 ( V_19 -> V_24 , V_27 ,
V_26 , 0xff ) ;
if ( V_26 & 0xff00 ) {
V_26 >>= 8 ;
F_8 ( V_19 -> V_24 , V_28 ,
V_26 , 0xff ) ;
}
return 0 ;
}
static int F_13 ( struct V_19 * V_19 , unsigned int V_26 )
{
if ( V_26 & 0xff )
F_8 ( V_19 -> V_24 , V_27 ,
V_26 , 0x00 ) ;
if ( V_26 & 0xff00 ) {
V_26 >>= 8 ;
F_8 ( V_19 -> V_24 , V_28 ,
V_26 , 0x00 ) ;
}
return 0 ;
}
static void F_14 ( struct V_19 * V_19 ,
struct V_29 * V_30 ,
bool V_31 )
{
struct V_32 V_33 ;
bool V_34 , V_35 ;
unsigned int V_36 ;
T_2 V_37 [ 17 ] ;
if ( V_19 -> V_38 )
V_33 . V_39 = F_15 ( V_19 -> V_38 ) ;
else
V_33 . V_39 = false ;
F_16 ( & V_33 . V_40 ) ;
V_33 . V_40 . V_41 = V_42 ;
if ( V_31 ) {
V_33 . V_43 = false ;
V_33 . V_40 . V_44 = V_45 ;
} else {
V_33 . V_46 = V_47 ;
V_33 . V_48 = V_49 ;
if ( ( V_30 -> V_50 . V_51 &
V_52 ) &&
V_33 . V_39 ) {
V_33 . V_43 = false ;
V_33 . V_40 . V_44 =
V_53 ;
} else {
V_33 . V_43 = true ;
V_33 . V_40 . V_44 = V_45 ;
}
}
if ( V_33 . V_39 ) {
V_36 = V_54 ;
switch ( V_33 . V_40 . V_44 ) {
case V_55 :
V_34 = false ;
V_35 = true ;
break;
case V_53 :
V_34 = true ;
V_35 = true ;
break;
default:
V_34 = false ;
V_35 = false ;
break;
}
} else {
V_36 = V_56 ;
V_34 = false ;
V_35 = false ;
}
F_13 ( V_19 , V_57 ) ;
F_7 ( V_19 , V_33 . V_43 ,
V_33 . V_48 ,
V_33 . V_46 ) ;
F_8 ( V_19 -> V_24 , V_58 , 0x81 ,
( V_34 << 7 ) | V_35 ) ;
F_8 ( V_19 -> V_24 , V_59 ,
V_60 , V_36 ) ;
F_17 ( & V_33 . V_40 , V_37 ,
sizeof( V_37 ) ) ;
F_18 ( V_19 -> V_24 , V_61 ,
V_37 + 1 , sizeof( V_37 ) - 1 ) ;
F_12 ( V_19 , V_57 ) ;
}
static void F_19 ( struct V_19 * V_19 ,
const struct V_62 * V_33 )
{
static const unsigned int V_63 [ 4 ] = { 0 , 2 , 1 , 3 } ;
unsigned int V_64 ;
unsigned int V_65 ;
unsigned int V_66 ;
V_64 = ( V_33 -> V_64 + 1200 ) / 400 ;
V_65 = V_33 -> V_67 == 8 ? 3
: ( V_33 -> V_67 == 10 ? 1 : 2 ) ;
if ( V_33 -> V_68 != V_53 )
V_66 = V_33 -> V_69 == V_70
? 5 : 0 ;
else if ( V_33 -> V_69 == V_70 )
V_66 = V_33 -> V_71 ? 8 : 7 ;
else if ( V_33 -> V_69 == V_72 )
V_66 = V_33 -> V_71 ? 4 : 3 ;
else
V_66 = V_33 -> V_71 ? 2 : 1 ;
F_8 ( V_19 -> V_24 , V_73 , 0xf ,
V_66 ) ;
F_8 ( V_19 -> V_24 , V_58 , 0x7e ,
( V_65 << 4 ) |
( V_63 [ V_33 -> V_74 ] << 2 ) ) ;
F_10 ( V_19 -> V_24 , V_75 ,
V_33 -> V_76 << 3 ) ;
F_10 ( V_19 -> V_24 , V_77 ,
V_33 -> V_78 << 2 ) ;
F_10 ( V_19 -> V_24 , 0xba , V_64 << 5 ) ;
V_19 -> V_71 = V_33 -> V_71 ;
V_19 -> V_79 = V_33 -> V_79 ;
V_19 -> V_80 = V_33 -> V_80 ;
V_19 -> V_31 = V_33 -> V_68 == V_45 ;
}
static void F_20 ( struct V_19 * V_19 )
{
V_19 -> V_81 = - 1 ;
F_8 ( V_19 -> V_24 , V_82 ,
V_83 , 0 ) ;
if ( V_19 -> V_84 -> V_85 ) {
F_10 ( V_19 -> V_24 , F_21 ( 0 ) ,
V_86 | V_87 ) ;
F_10 ( V_19 -> V_24 , F_21 ( 1 ) ,
V_88 ) ;
}
F_8 ( V_19 -> V_24 , V_89 ,
V_90 ,
V_91 ) ;
}
static void F_22 ( struct V_19 * V_19 )
{
F_20 ( V_19 ) ;
F_23 ( V_19 -> V_24 ) ;
if ( V_19 -> type == V_92 )
F_24 ( V_19 ) ;
V_19 -> V_93 = true ;
}
static void F_25 ( struct V_19 * V_19 )
{
F_8 ( V_19 -> V_24 , V_82 ,
V_83 ,
V_83 ) ;
F_26 ( V_19 -> V_24 ) ;
}
static void F_27 ( struct V_19 * V_19 )
{
F_25 ( V_19 ) ;
if ( V_19 -> type == V_92 )
F_28 ( V_19 ) ;
V_19 -> V_93 = false ;
}
static bool F_29 ( struct V_19 * V_19 )
{
unsigned int V_94 ;
int V_95 ;
V_95 = F_30 ( V_19 -> V_24 , F_3 ( 0 ) , & V_94 ) ;
if ( V_95 < 0 )
return false ;
if ( V_94 & V_87 ) {
F_10 ( V_19 -> V_24 , F_3 ( 0 ) ,
V_87 ) ;
return true ;
}
return false ;
}
static void F_31 ( struct V_96 * V_97 )
{
struct V_19 * V_19 = F_32 ( V_97 , struct V_19 , V_98 ) ;
enum V_99 V_100 ;
unsigned int V_101 ;
int V_95 ;
V_95 = F_30 ( V_19 -> V_24 , V_11 , & V_101 ) ;
if ( V_95 < 0 )
V_100 = V_102 ;
else if ( V_101 & V_103 )
V_100 = V_104 ;
else
V_100 = V_102 ;
if ( V_19 -> V_30 . V_100 != V_100 ) {
V_19 -> V_30 . V_100 = V_100 ;
F_33 ( V_19 -> V_30 . V_2 ) ;
}
}
static int F_34 ( struct V_19 * V_19 , bool V_105 )
{
unsigned int V_94 , V_106 ;
int V_95 ;
V_95 = F_30 ( V_19 -> V_24 , F_3 ( 0 ) , & V_94 ) ;
if ( V_95 < 0 )
return V_95 ;
V_95 = F_30 ( V_19 -> V_24 , F_3 ( 1 ) , & V_106 ) ;
if ( V_95 < 0 )
return V_95 ;
F_10 ( V_19 -> V_24 , F_3 ( 0 ) , V_94 ) ;
F_10 ( V_19 -> V_24 , F_3 ( 1 ) , V_106 ) ;
if ( V_105 && V_94 & V_87 && V_19 -> V_107 . V_108 )
F_35 ( & V_19 -> V_98 ) ;
if ( V_94 & V_86 || V_106 & V_88 ) {
V_19 -> V_109 = true ;
if ( V_19 -> V_84 -> V_85 )
F_36 ( & V_19 -> V_110 ) ;
}
return 0 ;
}
static T_3 F_37 ( int V_85 , void * V_111 )
{
struct V_19 * V_19 = V_111 ;
int V_95 ;
V_95 = F_34 ( V_19 , true ) ;
return V_95 < 0 ? V_112 : V_113 ;
}
static int F_38 ( struct V_19 * V_19 , int V_114 )
{
int V_95 ;
if ( V_19 -> V_84 -> V_85 ) {
V_95 = F_39 ( V_19 -> V_110 ,
V_19 -> V_109 , F_40 ( V_114 ) ) ;
} else {
for (; V_114 > 0 ; V_114 -= 25 ) {
V_95 = F_34 ( V_19 , false ) ;
if ( V_95 < 0 )
break;
if ( V_19 -> V_109 )
break;
F_41 ( 25 ) ;
}
}
return V_19 -> V_109 ? 0 : - V_115 ;
}
static int F_42 ( void * V_116 , T_4 * V_117 , unsigned int V_118 ,
T_5 V_119 )
{
struct V_19 * V_19 = V_116 ;
struct V_120 V_121 [ 2 ] ;
T_2 V_122 ;
unsigned int V_23 ;
int V_95 ;
if ( V_119 > 128 )
return - V_123 ;
if ( V_19 -> V_81 != V_118 / 2 ) {
unsigned int V_100 ;
V_95 = F_30 ( V_19 -> V_24 , V_15 ,
& V_100 ) ;
if ( V_95 < 0 )
return V_95 ;
if ( V_100 != 2 ) {
V_19 -> V_109 = false ;
F_10 ( V_19 -> V_24 , V_124 ,
V_118 ) ;
V_95 = F_38 ( V_19 , 200 ) ;
if ( V_95 < 0 )
return V_95 ;
}
V_121 [ 0 ] . V_125 = V_19 -> V_126 -> V_125 ;
V_121 [ 0 ] . V_127 = 0 ;
V_121 [ 0 ] . V_119 = 1 ;
V_121 [ 0 ] . V_117 = & V_122 ;
V_121 [ 1 ] . V_125 = V_19 -> V_126 -> V_125 ;
V_121 [ 1 ] . V_127 = V_128 ;
V_121 [ 1 ] . V_119 = 64 ;
V_121 [ 1 ] . V_117 = V_19 -> V_129 ;
V_122 = 0 ;
for ( V_23 = 0 ; V_23 < 4 ; ++ V_23 ) {
V_95 = F_43 ( V_19 -> V_126 -> V_130 , V_121 ,
F_44 ( V_121 ) ) ;
if ( V_95 < 0 )
return V_95 ;
else if ( V_95 != 2 )
return - V_115 ;
V_121 [ 1 ] . V_117 += 64 ;
V_122 += 64 ;
}
V_19 -> V_81 = V_118 / 2 ;
}
if ( V_118 % 2 == 0 )
memcpy ( V_117 , V_19 -> V_129 , V_119 ) ;
else
memcpy ( V_117 , V_19 -> V_129 + 128 , V_119 ) ;
return 0 ;
}
static int F_45 ( struct V_19 * V_19 ,
struct V_29 * V_30 )
{
struct V_38 * V_38 ;
unsigned int V_131 ;
if ( ! V_19 -> V_93 ) {
unsigned int V_132 =
( V_19 -> V_84 -> V_125 << 1 ) + 4 ;
F_20 ( V_19 ) ;
F_10 ( V_19 -> V_24 , V_133 ,
V_132 ) ;
}
V_38 = F_46 ( V_30 , F_42 , V_19 ) ;
if ( ! V_19 -> V_93 )
F_25 ( V_19 ) ;
F_47 ( V_19 -> V_38 ) ;
V_19 -> V_38 = V_38 ;
if ( ! V_38 )
return 0 ;
F_48 ( V_30 , V_38 ) ;
V_131 = F_49 ( V_30 , V_38 ) ;
F_14 ( V_19 , V_30 , V_19 -> V_31 ) ;
return V_131 ;
}
static enum V_99
F_50 ( struct V_19 * V_19 , struct V_29 * V_30 )
{
enum V_99 V_100 ;
unsigned int V_101 ;
bool V_134 ;
int V_95 ;
V_95 = F_30 ( V_19 -> V_24 , V_11 , & V_101 ) ;
if ( V_95 < 0 )
return V_102 ;
if ( V_101 & V_103 )
V_100 = V_104 ;
else
V_100 = V_102 ;
V_134 = F_29 ( V_19 ) ;
if ( V_100 == V_104 && V_134 && V_19 -> V_93 ) {
F_26 ( V_19 -> V_24 ) ;
F_22 ( V_19 ) ;
F_45 ( V_19 , V_30 ) ;
if ( V_19 -> V_100 == V_104 )
V_100 = V_102 ;
} else {
F_8 ( V_19 -> V_24 , V_89 ,
V_90 ,
V_135 ) ;
}
V_19 -> V_100 = V_100 ;
return V_100 ;
}
static int F_51 ( struct V_19 * V_19 ,
struct V_136 * V_36 )
{
if ( V_36 -> clock > 165000 )
return V_137 ;
return V_138 ;
}
static void F_52 ( struct V_19 * V_19 ,
struct V_136 * V_36 ,
struct V_136 * V_139 )
{
unsigned int V_140 ;
unsigned int V_79 = 0 ;
unsigned int V_80 = 0 ;
if ( V_19 -> V_71 ) {
unsigned int V_141 , V_142 ;
unsigned int V_143 , V_144 ;
V_141 = V_139 -> V_145 -
V_139 -> V_146 ;
V_143 = V_139 -> V_147 -
V_139 -> V_148 ;
V_142 = V_139 -> V_149 -
V_139 -> V_145 ;
V_144 = V_139 -> V_150 -
V_139 -> V_147 ;
V_143 += 1 ;
F_10 ( V_19 -> V_24 , V_151 ,
( ( V_141 >> 10 ) & 0x7 ) << 5 ) ;
F_10 ( V_19 -> V_24 , F_53 ( 0 ) ,
( V_141 >> 2 ) & 0xff ) ;
F_10 ( V_19 -> V_24 , F_53 ( 1 ) ,
( ( V_141 & 0x3 ) << 6 ) |
( ( V_142 >> 4 ) & 0x3f ) ) ;
F_10 ( V_19 -> V_24 , F_53 ( 2 ) ,
( ( V_142 & 0xf ) << 4 ) |
( ( V_143 >> 6 ) & 0xf ) ) ;
F_10 ( V_19 -> V_24 , F_53 ( 3 ) ,
( ( V_143 & 0x3f ) << 2 ) |
( ( V_144 >> 8 ) & 0x3 ) ) ;
F_10 ( V_19 -> V_24 , F_53 ( 4 ) ,
V_144 & 0xff ) ;
V_79 = ! ( V_139 -> V_127 & V_152 ) ;
V_80 = ! ( V_139 -> V_127 & V_153 ) ;
} else {
enum V_154 V_155 ;
enum V_154 V_156 ;
if ( V_139 -> V_127 & V_157 )
V_155 = V_158 ;
else
V_155 = V_159 ;
if ( V_139 -> V_127 & V_160 )
V_156 = V_158 ;
else
V_156 = V_159 ;
if ( V_19 -> V_79 != V_155 &&
V_19 -> V_79 !=
V_161 )
V_79 = 1 ;
if ( V_19 -> V_80 != V_156 &&
V_19 -> V_80 !=
V_161 )
V_80 = 1 ;
}
if ( V_36 -> V_162 <= 24000 )
V_140 = V_163 ;
else if ( V_36 -> V_162 <= 25000 )
V_140 = V_164 ;
else if ( V_36 -> V_162 <= 30000 )
V_140 = V_165 ;
else
V_140 = V_166 ;
F_8 ( V_19 -> V_24 , 0xfb ,
0x6 , V_140 << 1 ) ;
F_8 ( V_19 -> V_24 , 0x17 ,
0x60 , ( V_80 << 6 ) | ( V_79 << 5 ) ) ;
if ( V_19 -> type == V_92 )
F_54 ( V_19 , V_139 ) ;
F_55 ( & V_19 -> V_167 , V_139 ) ;
V_19 -> V_168 = V_36 -> clock ;
}
static struct V_19 * F_56 ( struct V_29 * V_30 )
{
return F_32 ( V_30 , struct V_19 , V_30 ) ;
}
static int F_57 ( struct V_29 * V_30 )
{
struct V_19 * V_169 = F_56 ( V_30 ) ;
return F_45 ( V_169 , V_30 ) ;
}
static enum V_170
F_58 ( struct V_29 * V_30 ,
struct V_136 * V_36 )
{
struct V_19 * V_169 = F_56 ( V_30 ) ;
return F_51 ( V_169 , V_36 ) ;
}
static enum V_99
F_59 ( struct V_29 * V_30 , bool V_171 )
{
struct V_19 * V_169 = F_56 ( V_30 ) ;
return F_50 ( V_169 , V_30 ) ;
}
static struct V_19 * F_60 ( struct V_172 * V_107 )
{
return F_32 ( V_107 , struct V_19 , V_107 ) ;
}
static void F_61 ( struct V_172 * V_107 )
{
struct V_19 * V_169 = F_60 ( V_107 ) ;
F_22 ( V_169 ) ;
}
static void F_62 ( struct V_172 * V_107 )
{
struct V_19 * V_169 = F_60 ( V_107 ) ;
F_27 ( V_169 ) ;
}
static void F_63 ( struct V_172 * V_107 ,
struct V_136 * V_36 ,
struct V_136 * V_139 )
{
struct V_19 * V_169 = F_60 ( V_107 ) ;
F_52 ( V_169 , V_36 , V_139 ) ;
}
static int F_64 ( struct V_172 * V_107 )
{
struct V_19 * V_169 = F_60 ( V_107 ) ;
int V_95 ;
if ( ! V_107 -> V_108 ) {
F_65 ( L_1 ) ;
return - V_173 ;
}
V_169 -> V_30 . V_174 = V_175 ;
V_95 = F_66 ( V_107 -> V_2 , & V_169 -> V_30 ,
& V_176 ,
V_177 ) ;
if ( V_95 ) {
F_65 ( L_2 ) ;
return V_95 ;
}
F_67 ( & V_169 -> V_30 ,
& V_178 ) ;
F_68 ( & V_169 -> V_30 , V_107 -> V_108 ) ;
if ( V_169 -> type == V_92 )
V_95 = F_69 ( V_169 ) ;
if ( V_169 -> V_84 -> V_85 )
F_10 ( V_169 -> V_24 , F_21 ( 0 ) ,
V_87 ) ;
return V_95 ;
}
static int F_70 ( struct V_19 * V_169 )
{
struct V_1 * V_2 = & V_169 -> V_84 -> V_2 ;
const char * const * V_179 ;
unsigned int V_23 ;
int V_95 ;
if ( V_169 -> type == V_180 ) {
V_179 = V_181 ;
V_169 -> V_182 = F_44 ( V_181 ) ;
} else {
V_179 = V_183 ;
V_169 -> V_182 = F_44 ( V_183 ) ;
}
V_169 -> V_184 = F_71 ( V_2 , V_169 -> V_182 ,
sizeof( * V_169 -> V_184 ) , V_185 ) ;
if ( ! V_169 -> V_184 )
return - V_186 ;
for ( V_23 = 0 ; V_23 < V_169 -> V_182 ; V_23 ++ )
V_169 -> V_184 [ V_23 ] . V_187 = V_179 [ V_23 ] ;
V_95 = F_72 ( V_2 , V_169 -> V_182 , V_169 -> V_184 ) ;
if ( V_95 )
return V_95 ;
return F_73 ( V_169 -> V_182 , V_169 -> V_184 ) ;
}
static void F_74 ( struct V_19 * V_169 )
{
F_75 ( V_169 -> V_182 , V_169 -> V_184 ) ;
}
static int F_76 ( struct V_188 * V_189 ,
struct V_62 * V_33 )
{
const char * V_190 ;
int V_95 ;
F_77 ( V_189 , L_3 , & V_33 -> V_67 ) ;
if ( V_33 -> V_67 != 8 && V_33 -> V_67 != 10 &&
V_33 -> V_67 != 12 )
return - V_123 ;
V_95 = F_78 ( V_189 , L_4 , & V_190 ) ;
if ( V_95 < 0 )
return V_95 ;
if ( ! strcmp ( V_190 , L_5 ) )
V_33 -> V_68 = V_45 ;
else if ( ! strcmp ( V_190 , L_6 ) )
V_33 -> V_68 = V_53 ;
else if ( ! strcmp ( V_190 , L_7 ) )
V_33 -> V_68 = V_55 ;
else
return - V_123 ;
V_95 = F_78 ( V_189 , L_8 , & V_190 ) ;
if ( V_95 < 0 )
return V_95 ;
if ( ! strcmp ( V_190 , L_9 ) )
V_33 -> V_69 = V_191 ;
else if ( ! strcmp ( V_190 , L_10 ) )
V_33 -> V_69 = V_72 ;
else if ( ! strcmp ( V_190 , L_11 ) )
V_33 -> V_69 = V_70 ;
else
return - V_123 ;
if ( V_33 -> V_68 == V_53 ||
V_33 -> V_69 != V_191 ) {
V_95 = F_77 ( V_189 , L_12 ,
& V_33 -> V_74 ) ;
if ( V_95 )
return V_95 ;
if ( V_33 -> V_74 < 1 || V_33 -> V_74 > 3 )
return - V_123 ;
V_95 = F_78 ( V_189 , L_13 ,
& V_190 ) ;
if ( V_95 < 0 )
return V_95 ;
if ( ! strcmp ( V_190 , L_14 ) )
V_33 -> V_76 =
V_192 ;
else if ( ! strcmp ( V_190 , L_15 ) )
V_33 -> V_76 =
V_193 ;
else if ( ! strcmp ( V_190 , L_16 ) )
V_33 -> V_76 =
V_194 ;
else
return - V_123 ;
} else {
V_33 -> V_74 = 1 ;
V_33 -> V_76 = V_192 ;
}
F_77 ( V_189 , L_17 , & V_33 -> V_64 ) ;
if ( V_33 -> V_64 < - 1200 || V_33 -> V_64 > 1600 )
return - V_123 ;
V_33 -> V_71 = F_79 ( V_189 , L_18 ) ;
V_33 -> V_78 = V_195 ;
V_33 -> V_80 = V_161 ;
V_33 -> V_79 = V_161 ;
return 0 ;
}
static int F_80 ( struct V_196 * V_197 , const struct V_198 * V_199 )
{
struct V_62 V_200 ;
struct V_19 * V_19 ;
struct V_1 * V_2 = & V_197 -> V_2 ;
unsigned int V_201 = V_197 -> V_125 << 1 ;
unsigned int V_132 = V_201 + 4 ;
unsigned int V_101 ;
int V_95 ;
if ( ! V_2 -> V_202 )
return - V_123 ;
V_19 = F_81 ( V_2 , sizeof( * V_19 ) , V_185 ) ;
if ( ! V_19 )
return - V_186 ;
V_19 -> V_84 = V_197 ;
V_19 -> V_93 = false ;
V_19 -> V_100 = V_102 ;
if ( V_2 -> V_202 )
V_19 -> type = (enum V_203 ) F_82 ( V_2 ) ;
else
V_19 -> type = V_199 -> V_204 ;
memset ( & V_200 , 0 , sizeof( V_200 ) ) ;
if ( V_19 -> type == V_180 )
V_95 = F_76 ( V_2 -> V_202 , & V_200 ) ;
else
V_95 = F_83 ( V_2 -> V_202 , V_19 ) ;
if ( V_95 )
return V_95 ;
V_95 = F_70 ( V_19 ) ;
if ( V_95 ) {
F_84 ( V_2 , L_19 ) ;
return V_95 ;
}
V_19 -> V_205 = F_85 ( V_2 , L_20 , V_206 ) ;
if ( F_86 ( V_19 -> V_205 ) ) {
V_95 = F_87 ( V_19 -> V_205 ) ;
goto V_207;
}
if ( V_19 -> V_205 ) {
F_88 ( 5 ) ;
F_89 ( V_19 -> V_205 , 0 ) ;
}
V_19 -> V_24 = F_90 ( V_197 , & V_208 ) ;
if ( F_86 ( V_19 -> V_24 ) ) {
V_95 = F_87 ( V_19 -> V_24 ) ;
goto V_207;
}
V_95 = F_30 ( V_19 -> V_24 , V_4 , & V_101 ) ;
if ( V_95 )
goto V_207;
F_91 ( V_2 , L_21 , V_101 ) ;
if ( V_19 -> type == V_180 )
V_95 = F_92 ( V_19 -> V_24 ,
V_209 ,
F_44 ( V_209 ) ) ;
else
V_95 = F_93 ( V_19 ) ;
if ( V_95 )
goto V_207;
F_10 ( V_19 -> V_24 , V_133 , V_132 ) ;
F_10 ( V_19 -> V_24 , V_210 ,
V_201 - 0xa ) ;
F_10 ( V_19 -> V_24 , V_211 ,
V_201 - 2 ) ;
F_13 ( V_19 , 0xffff ) ;
V_19 -> V_126 = F_94 ( V_197 -> V_130 , V_132 >> 1 ) ;
if ( ! V_19 -> V_126 ) {
V_95 = - V_186 ;
goto V_207;
}
if ( V_19 -> type == V_92 ) {
V_95 = F_95 ( V_19 ) ;
if ( V_95 )
goto V_212;
}
F_96 ( & V_19 -> V_98 , F_31 ) ;
if ( V_197 -> V_85 ) {
F_97 ( & V_19 -> V_110 ) ;
V_95 = F_98 ( V_2 , V_197 -> V_85 , NULL ,
F_37 ,
V_213 , F_99 ( V_2 ) ,
V_19 ) ;
if ( V_95 )
goto V_214;
}
F_10 ( V_19 -> V_24 , V_215 ,
V_216 ) ;
F_27 ( V_19 ) ;
F_100 ( V_197 , V_19 ) ;
if ( V_19 -> type == V_180 )
F_19 ( V_19 , & V_200 ) ;
V_19 -> V_107 . V_217 = & V_218 ;
V_19 -> V_107 . V_202 = V_2 -> V_202 ;
V_95 = F_101 ( & V_19 -> V_107 ) ;
if ( V_95 ) {
F_84 ( V_2 , L_22 ) ;
goto V_214;
}
F_102 ( V_2 , V_19 ) ;
return 0 ;
V_214:
F_103 ( V_19 ) ;
V_212:
F_104 ( V_19 -> V_126 ) ;
V_207:
F_74 ( V_19 ) ;
return V_95 ;
}
static int F_105 ( struct V_196 * V_197 )
{
struct V_19 * V_19 = F_106 ( V_197 ) ;
if ( V_19 -> type == V_92 ) {
F_107 ( V_19 ) ;
F_103 ( V_19 ) ;
}
F_74 ( V_19 ) ;
F_108 ( & V_19 -> V_107 ) ;
F_109 ( V_19 ) ;
F_104 ( V_19 -> V_126 ) ;
F_47 ( V_19 -> V_38 ) ;
return 0 ;
}
static int T_6 F_110 ( void )
{
if ( F_111 ( V_219 ) )
F_112 ( & V_220 ) ;
return F_113 ( & V_221 ) ;
}
static void T_7 F_114 ( void )
{
F_115 ( & V_221 ) ;
if ( F_111 ( V_219 ) )
F_116 ( & V_220 ) ;
}
