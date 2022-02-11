static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_2 * F_3 ( struct V_4 * V_5 )
{
return & F_2 ( V_5 -> V_6 , struct V_1 , V_7 ) -> V_3 ;
}
static int F_4 ( struct V_2 * V_3 , unsigned char V_8 )
{
struct V_9 * V_10 = F_5 ( V_3 ) ;
unsigned char V_11 [ 1 ] ;
int V_12 ;
struct V_13 V_14 [] = {
{ . V_8 = V_10 -> V_8 , . V_15 = 0 ,
. V_16 = & V_8 , . V_17 = 1 } ,
{ . V_8 = V_10 -> V_8 , . V_15 = V_18 ,
. V_16 = V_11 , . V_17 = 1 }
} ;
V_12 = F_6 ( V_10 -> V_19 , V_14 , 2 ) ;
if ( V_12 < 0 || V_12 != 2 ) {
F_7 ( V_3 , L_1 , V_12 ) ;
return V_12 < 0 ? V_12 : - V_20 ;
}
F_8 ( 2 , V_21 , V_3 , L_2 , V_8 , V_11 [ 0 ] ) ;
return ( V_11 [ 0 ] ) ;
}
static inline void F_9 ( struct V_2 * V_3 , unsigned char V_8 ,
unsigned char V_22 )
{
struct V_9 * V_10 = F_5 ( V_3 ) ;
unsigned char V_11 [ 2 ] ;
int V_12 ;
V_11 [ 0 ] = V_8 ;
V_11 [ 1 ] = V_22 ;
F_8 ( 2 , V_21 , V_3 , L_3 , V_11 [ 0 ] , V_11 [ 1 ] ) ;
if ( 2 != ( V_12 = F_10 ( V_10 , V_11 , 2 ) ) )
F_8 ( 0 , V_21 , V_3 , L_1 , V_12 ) ;
}
static void F_11 ( struct V_2 * V_3 , char * V_23 , T_1 V_24 ,
const T_1 V_25 , int V_26 )
{
int V_27 = 0 ;
while ( V_24 != ( T_1 ) ( V_25 + 1 ) ) {
if ( ( V_27 % V_26 ) == 0 ) {
if ( V_27 > 0 )
F_12 ( L_4 ) ;
F_12 ( L_5 , V_23 , V_24 ) ;
}
F_12 ( L_6 , F_4 ( V_3 , V_24 ) ) ;
V_24 ++ ;
V_27 ++ ;
}
F_12 ( L_4 ) ;
}
static int F_13 ( struct V_2 * V_3 )
{
F_12 ( L_7 ,
F_4 ( V_3 , V_28 ) ) ;
F_12 ( L_8 ,
F_4 ( V_3 , V_29 ) ) ;
F_12 ( L_9 ,
F_4 ( V_3 , V_30 ) ) ;
F_12 ( L_10 ,
F_4 ( V_3 , V_31 ) ) ;
F_12 ( L_11 ,
F_4 ( V_3 , V_32 ) ) ;
F_12 ( L_12 ,
F_4 ( V_3 , V_33 ) ) ;
F_12 ( L_13 ,
F_4 ( V_3 , V_34 ) ,
F_4 ( V_3 , V_35 ) ,
F_4 ( V_3 , V_36 ) ) ;
F_12 ( L_14 ,
F_4 ( V_3 , V_37 ) ) ;
F_12 ( L_15 ,
F_4 ( V_3 , V_38 ) ) ;
F_12 ( L_16 ,
F_4 ( V_3 , V_39 ) ) ;
F_12 ( L_17 ,
F_4 ( V_3 , V_40 ) ) ;
F_12 ( L_18 ,
F_4 ( V_3 , V_41 ) ) ;
F_12 ( L_19 ,
F_4 ( V_3 , V_42 ) ) ;
F_12 ( L_20 ,
F_4 ( V_3 , V_43 ) ,
F_4 ( V_3 , V_44 ) ) ;
F_12 ( L_21 ,
F_4 ( V_3 , V_45 ) ,
F_4 ( V_3 , V_46 ) ) ;
F_12 ( L_22 ,
F_4 ( V_3 , V_47 ) ) ;
F_12 ( L_23 ,
F_4 ( V_3 , V_48 ) ) ;
F_12 ( L_24 ,
F_4 ( V_3 , V_49 ) ) ;
F_12 ( L_25 ,
F_4 ( V_3 , V_50 ) ) ;
F_12 ( L_26 ,
F_4 ( V_3 , V_51 ) ,
F_4 ( V_3 , V_52 ) ) ;
F_12 ( L_27 ,
F_4 ( V_3 , V_53 ) ) ;
F_12 ( L_28 ,
F_4 ( V_3 , V_54 ) ) ;
F_12 ( L_29 ,
F_4 ( V_3 , V_55 ) ) ;
F_12 ( L_30 ,
F_4 ( V_3 , V_56 ) ) ;
F_12 ( L_31 ,
F_4 ( V_3 , V_57 ) ,
F_4 ( V_3 , V_58 ) ) ;
F_12 ( L_32 ,
F_4 ( V_3 , V_59 ) ) ;
F_12 ( L_33 ,
F_4 ( V_3 , V_60 ) ) ;
F_12 ( L_34 ,
( F_4 ( V_3 , V_61 ) & 1 ) ? 3 : 4 ) ;
F_12 ( L_35 ,
F_4 ( V_3 , V_62 ) ,
F_4 ( V_3 , V_63 ) ) ;
F_12 ( L_36 ,
F_4 ( V_3 , V_64 ) ,
F_4 ( V_3 , V_65 ) ) ;
F_12 ( L_37 ,
F_4 ( V_3 , V_66 ) ,
F_4 ( V_3 , V_67 ) ) ;
F_12 ( L_38 ,
F_4 ( V_3 , V_68 ) ) ;
F_12 ( L_39 ,
F_4 ( V_3 , V_69 ) ) ;
F_12 ( L_40 ,
F_4 ( V_3 , V_70 ) ,
F_4 ( V_3 , V_71 ) ,
F_4 ( V_3 , V_72 ) ,
F_4 ( V_3 , V_73 ) ,
F_4 ( V_3 , V_74 ) ) ;
F_11 ( V_3 , L_41 , V_75 ,
V_76 , 8 ) ;
F_11 ( V_3 , L_42 , V_77 ,
V_78 , 8 ) ;
F_12 ( L_43 ,
F_4 ( V_3 , V_79 ) ) ;
F_12 ( L_44 ,
F_4 ( V_3 , V_80 ) ) ;
F_12 ( L_45 ,
F_4 ( V_3 , V_81 ) ) ;
F_12 ( L_46 ,
F_4 ( V_3 , V_82 ) ) ;
F_12 ( L_47 ,
F_4 ( V_3 , V_83 ) ) ;
F_12 ( L_48 ,
F_4 ( V_3 , V_84 ) ) ;
F_12 ( L_49 ,
F_4 ( V_3 , V_85 ) ) ;
F_12 ( L_50 ,
F_4 ( V_3 , V_86 ) ) ;
F_12 ( L_51 ,
F_4 ( V_3 , V_87 ) ) ;
F_12 ( L_52 ,
F_4 ( V_3 , V_88 ) ,
F_4 ( V_3 , V_89 ) ) ;
F_12 ( L_53 ,
F_4 ( V_3 , V_90 ) ) ;
F_12 ( L_54 ,
F_4 ( V_3 , V_91 ) ) ;
F_12 ( L_55 ,
F_4 ( V_3 , V_92 ) ) ;
F_11 ( V_3 , L_56 , V_93 ,
V_94 , 8 ) ;
F_11 ( V_3 , L_57 , V_95 ,
V_96 , 8 ) ;
F_11 ( V_3 , L_58 , V_97 ,
V_98 , 8 ) ;
F_11 ( V_3 , L_59 , V_99 ,
V_100 , 10 ) ;
F_11 ( V_3 , L_60 , V_101 ,
V_102 , 8 ) ;
return 0 ;
}
static inline void F_14 ( struct V_2 * V_3 )
{
int V_103 = 0 ;
struct V_1 * V_104 = F_1 ( V_3 ) ;
int V_105 = 0 ;
int V_106 ;
if ( ( V_104 -> V_107 & V_108 ) || ! V_104 -> V_109 )
V_105 = 8 ;
switch ( V_104 -> V_105 ) {
case V_110 :
V_105 |= 2 ;
case V_111 :
break;
case V_112 :
default:
V_105 |= 1 ;
break;
}
F_8 ( 1 , V_21 , V_3 , L_61
L_62 ,
V_104 -> V_105 , V_104 -> V_107 ,
V_105 , V_103 ) ;
F_9 ( V_3 , V_30 , V_103 ) ;
F_9 ( V_3 , V_28 , V_105 ) ;
V_106 = F_4 ( V_3 , V_31 ) ;
if ( V_106 < 0 ) {
F_7 ( V_3 , L_63 , V_113 , V_106 ) ;
return;
}
if ( V_104 -> V_105 == V_112 )
V_106 = ( V_106 & ~ 0x40 ) | 0x10 ;
else
V_106 = ( V_106 & ~ 0x10 ) | 0x40 ;
F_9 ( V_3 , V_31 , V_106 ) ;
}
static int F_15 ( struct V_2 * V_3 ,
const struct V_114 * V_115 )
{
while ( V_115 -> V_116 != 0xff ) {
F_9 ( V_3 , V_115 -> V_116 , V_115 -> V_22 ) ;
V_115 ++ ;
}
return 0 ;
}
static int F_16 ( struct V_2 * V_3 ,
const struct V_117 * V_115 )
{
unsigned int V_27 ;
F_9 ( V_3 , V_91 , 0 ) ;
for ( V_27 = V_101 ; V_27 <= V_102 ; V_27 ++ )
F_9 ( V_3 , V_27 , 0xff ) ;
while ( V_115 -> V_116 != ( V_118 ) - 1 ) {
F_9 ( V_3 , V_119 , V_115 -> V_116 >> 8 ) ;
F_9 ( V_3 , V_120 , V_115 -> V_116 ) ;
for ( V_27 = 0 ; V_27 < 16 ; V_27 ++ )
F_9 ( V_3 , V_121 , V_115 -> V_122 [ V_27 ] ) ;
V_115 ++ ;
}
return 0 ;
}
static int F_17 ( struct V_2 * V_3 ,
struct V_123 * V_124 )
{
const struct V_117 * V_115 = V_125 ;
int line ;
F_8 ( 1 , V_21 , V_3 , L_64 ) ;
memset ( V_124 , 0 , sizeof *V_124 ) ;
while ( V_115 -> V_116 != ( V_118 ) - 1 ) {
for ( line = V_115 -> type . V_126 ; line <= V_115 -> type . V_127 ; line ++ ) {
V_124 -> V_128 [ 0 ] [ line ] |= V_115 -> type . V_129 ;
}
V_124 -> V_130 |= V_115 -> type . V_129 ;
V_115 ++ ;
}
return 0 ;
}
static int F_18 ( struct V_2 * V_3 ,
const struct V_117 * V_115 ,
unsigned int type , T_1 V_15 , int line ,
const int V_131 )
{
struct V_1 * V_104 = F_1 ( V_3 ) ;
T_2 V_132 = V_104 -> V_133 ;
T_1 V_116 ;
int V_134 = 0 ;
if ( V_132 == V_135 ) {
F_7 ( V_3 , L_65 ) ;
return 0 ;
} else if ( V_132 & V_136 ) {
line += 3 ;
}
if ( line < 6 || line > 27 )
return 0 ;
while ( V_115 -> V_116 != ( V_118 ) - 1 ) {
if ( ( type & V_115 -> type . V_129 ) &&
( line >= V_115 -> type . V_126 ) &&
( line <= V_115 -> type . V_127 ) ) {
type = V_115 -> type . V_129 ;
break;
}
V_115 ++ ;
V_134 ++ ;
}
if ( V_115 -> V_116 == ( V_118 ) - 1 )
return 0 ;
type = V_134 | ( V_15 & 0xf0 ) ;
V_116 = ( ( line - 6 ) << 1 ) + V_101 ;
if ( V_131 & 1 ) {
F_9 ( V_3 , V_116 , type ) ;
}
if ( V_131 & 2 ) {
F_9 ( V_3 , V_116 + 1 , type ) ;
}
return type ;
}
static int F_19 ( struct V_2 * V_3 ,
const struct V_117 * V_115 , int line )
{
struct V_1 * V_104 = F_1 ( V_3 ) ;
T_2 V_132 = V_104 -> V_133 ;
T_1 V_116 ;
int V_134 , type = 0 ;
int V_27 , V_137 = 0 ;
if ( V_132 == V_135 ) {
F_7 ( V_3 , L_65 ) ;
return 0 ;
} else if ( V_132 & V_136 ) {
line += 3 ;
}
if ( line < 6 || line > 27 )
return 0 ;
V_116 = ( ( line - 6 ) << 1 ) + V_101 ;
for ( V_27 = 0 ; V_27 <= 1 ; V_27 ++ ) {
V_137 = F_4 ( V_3 , V_116 + V_27 ) ;
if ( V_137 < 0 ) {
F_7 ( V_3 , L_63 ,
V_113 , V_137 ) ;
return 0 ;
}
V_134 = V_137 & 0x0f ;
if ( V_134 < 0x0f )
type |= V_115 [ V_134 ] . type . V_129 ;
}
return type ;
}
static int F_20 ( struct V_2 * V_3 , T_2 V_132 )
{
struct V_1 * V_104 = F_1 ( V_3 ) ;
int V_138 = 0 ;
V_104 -> V_133 = V_132 ;
if ( V_132 == V_139 ) {
V_138 = V_140 ;
} else if ( V_132 == V_141 ) {
V_138 = V_142 ;
} else if ( V_132 == V_143 || V_132 == V_144 ) {
V_138 = V_145 ;
} else {
if ( V_132 & V_146 )
V_138 = V_147 ;
else if ( V_132 & V_148 )
V_138 = V_149 ;
else if ( V_132 & V_150 )
V_138 = V_151 ;
}
F_8 ( 1 , V_21 , V_3 , L_66 , V_138 ) ;
F_9 ( V_3 , V_56 , V_138 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 , T_2 V_132 )
{
struct V_1 * V_104 = F_1 ( V_3 ) ;
if ( V_104 -> V_133 == V_132 )
return 0 ;
if ( V_132 & V_152 )
V_104 -> V_153 . V_154 = V_155 ;
else
V_104 -> V_153 . V_154 = V_156 ;
return F_20 ( V_3 , V_132 ) ;
}
static int F_22 ( struct V_2 * V_3 , T_3 V_106 )
{
struct V_1 * V_104 = F_1 ( V_3 ) ;
F_15 ( V_3 , V_157 ) ;
F_16 ( V_3 , V_125 ) ;
F_14 ( V_3 ) ;
F_15 ( V_3 , V_158 ) ;
F_23 ( & V_104 -> V_7 ) ;
F_20 ( V_3 , V_104 -> V_133 ) ;
return 0 ;
}
static int F_24 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
switch ( V_5 -> V_159 ) {
case V_160 :
F_9 ( V_3 , V_37 , V_5 -> V_106 ) ;
return 0 ;
case V_161 :
F_9 ( V_3 , V_40 , V_5 -> V_106 ) ;
return 0 ;
case V_162 :
F_9 ( V_3 , V_38 , V_5 -> V_106 ) ;
return 0 ;
case V_163 :
F_9 ( V_3 , V_39 , V_5 -> V_106 ) ;
return 0 ;
}
return - V_164 ;
}
static T_2 F_25 ( struct V_2 * V_3 )
{
int V_106 = F_4 ( V_3 , V_74 ) ;
switch ( V_106 & 0x0F ) {
case 0x01 :
return V_146 ;
case 0x03 :
return V_148 ;
case 0x05 :
return V_141 ;
case 0x07 :
return V_143 | V_144 ;
case 0x09 :
return V_139 ;
case 0xb :
return V_150 ;
default:
return V_165 ;
}
}
static int F_26 ( struct V_2 * V_3 , unsigned V_166 ,
enum V_167 * V_168 )
{
if ( V_166 )
return - V_164 ;
* V_168 = V_169 ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 ,
struct V_170 * V_171 )
{
struct V_1 * V_104 = F_1 ( V_3 ) ;
if ( V_171 == NULL )
return - V_164 ;
F_22 ( V_3 , 0 ) ;
V_171 -> V_172 = V_104 -> V_153 . V_172 ;
V_171 -> V_154 = V_104 -> V_153 . V_154 ;
V_171 -> V_168 = V_169 ;
V_171 -> V_173 = V_174 ;
V_171 -> V_175 = V_176 ;
F_8 ( 1 , V_21 , V_3 , L_67 , V_171 -> V_172 ,
V_171 -> V_154 ) ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 , const struct V_177 * V_178 )
{
struct V_179 V_153 = V_178 -> V_10 ;
struct V_1 * V_104 = F_1 ( V_3 ) ;
T_2 V_132 ;
unsigned int V_180 ;
F_8 ( 1 , V_21 , V_3 , L_68 ,
V_113 , V_153 . V_181 , V_153 . V_182 , V_153 . V_172 , V_153 . V_154 ) ;
if ( V_178 -> type != V_183 )
return - V_164 ;
V_153 . V_181 = F_29 ( V_153 . V_181 , 0 , V_184 ) ;
V_153 . V_172 = F_30 (unsigned int, rect.width,
TVP5150_H_MAX - TVP5150_MAX_CROP_LEFT - rect.left,
TVP5150_H_MAX - rect.left) ;
V_153 . V_182 = F_29 ( V_153 . V_182 , 0 , V_185 ) ;
if ( V_104 -> V_133 == V_135 )
V_132 = F_25 ( V_3 ) ;
else
V_132 = V_104 -> V_133 ;
if ( V_132 & V_152 )
V_180 = V_155 ;
else
V_180 = V_156 ;
V_153 . V_154 = F_30 (unsigned int, rect.height,
hmax - TVP5150_MAX_CROP_TOP - rect.top,
hmax - rect.top) ;
F_9 ( V_3 , V_49 , V_153 . V_182 ) ;
F_9 ( V_3 , V_50 ,
V_153 . V_182 + V_153 . V_154 - V_180 ) ;
F_9 ( V_3 , V_43 ,
V_153 . V_181 >> V_186 ) ;
F_9 ( V_3 , V_44 ,
V_153 . V_181 | ( 1 << V_186 ) ) ;
F_9 ( V_3 , V_45 ,
( V_153 . V_181 + V_153 . V_172 - V_184 ) >>
V_186 ) ;
F_9 ( V_3 , V_46 ,
V_153 . V_181 + V_153 . V_172 - V_184 ) ;
V_104 -> V_153 = V_153 ;
return 0 ;
}
static int F_31 ( struct V_2 * V_3 , struct V_177 * V_178 )
{
struct V_1 * V_104 = F_1 ( V_3 ) ;
V_178 -> V_10 = V_104 -> V_153 ;
V_178 -> type = V_183 ;
return 0 ;
}
static int F_32 ( struct V_2 * V_3 , struct V_187 * V_178 )
{
struct V_1 * V_104 = F_1 ( V_3 ) ;
T_2 V_132 ;
if ( V_178 -> type != V_183 )
return - V_164 ;
V_178 -> V_188 . V_181 = 0 ;
V_178 -> V_188 . V_182 = 0 ;
V_178 -> V_188 . V_172 = V_189 ;
if ( V_104 -> V_133 == V_135 )
V_132 = F_25 ( V_3 ) ;
else
V_132 = V_104 -> V_133 ;
if ( V_132 & V_152 )
V_178 -> V_188 . V_154 = V_155 ;
else
V_178 -> V_188 . V_154 = V_156 ;
V_178 -> V_190 = V_178 -> V_188 ;
V_178 -> V_191 . V_192 = 1 ;
V_178 -> V_191 . V_193 = 1 ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 ,
T_3 V_105 , T_3 V_107 , T_3 V_194 )
{
struct V_1 * V_104 = F_1 ( V_3 ) ;
V_104 -> V_105 = V_105 ;
V_104 -> V_107 = V_107 ;
F_14 ( V_3 ) ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 , struct V_195 * V_138 )
{
if ( V_138 -> V_196 == V_197 )
F_9 ( V_3 , V_34 , 0x70 ) ;
if ( V_138 -> V_198 [ 0 ] == 18 && V_138 -> V_198 [ 1 ] == 18 ) {
F_9 ( V_3 , V_49 , 0x00 ) ;
F_9 ( V_3 , V_50 , 0x01 ) ;
}
return 0 ;
}
static int F_35 ( struct V_2 * V_3 , struct V_199 * V_200 )
{
int V_27 ;
if ( V_200 -> V_130 != 0 ) {
for ( V_27 = 0 ; V_27 <= 23 ; V_27 ++ ) {
V_200 -> V_128 [ 1 ] [ V_27 ] = 0 ;
V_200 -> V_128 [ 0 ] [ V_27 ] =
F_18 ( V_3 , V_125 ,
V_200 -> V_128 [ 0 ] [ V_27 ] , 0xf0 , V_27 , 3 ) ;
}
F_9 ( V_3 , V_90 , 1 ) ;
} else {
F_9 ( V_3 , V_90 , 0 ) ;
F_9 ( V_3 , V_91 , 0 ) ;
for ( V_27 = V_101 ; V_27 <= V_102 ; V_27 ++ )
F_9 ( V_3 , V_27 , 0xff ) ;
}
return 0 ;
}
static int F_36 ( struct V_2 * V_3 , struct V_199 * V_200 )
{
int V_27 , V_201 = 0 ;
memset ( V_200 -> V_128 , 0 , sizeof( V_200 -> V_128 ) ) ;
for ( V_27 = 0 ; V_27 <= 23 ; V_27 ++ ) {
V_200 -> V_128 [ 0 ] [ V_27 ] =
F_19 ( V_3 , V_125 , V_27 ) ;
V_201 |= V_200 -> V_128 [ 0 ] [ V_27 ] ;
}
V_200 -> V_130 = V_201 ;
return 0 ;
}
static int F_37 ( struct V_2 * V_3 , struct V_202 * V_116 )
{
int V_203 ;
V_203 = F_4 ( V_3 , V_116 -> V_116 & 0xff ) ;
if ( V_203 < 0 ) {
F_7 ( V_3 , L_63 , V_113 , V_203 ) ;
return V_203 ;
}
V_116 -> V_106 = V_203 ;
V_116 -> V_204 = 1 ;
return 0 ;
}
static int F_38 ( struct V_2 * V_3 , const struct V_202 * V_116 )
{
F_9 ( V_3 , V_116 -> V_116 & 0xff , V_116 -> V_106 & 0xff ) ;
return 0 ;
}
static int F_39 ( struct V_2 * V_3 , struct V_205 * V_206 )
{
int V_207 = F_4 ( V_3 , 0x88 ) ;
V_206 -> signal = ( ( V_207 & 0x04 ) && ( V_207 & 0x02 ) ) ? 0xffff : 0x0 ;
return 0 ;
}
static int F_40 ( struct V_9 * V_10 ,
const struct V_208 * V_159 )
{
struct V_1 * V_209 ;
struct V_2 * V_3 ;
int V_210 [ 4 ] ;
int V_27 , V_203 ;
if ( ! F_41 ( V_10 -> V_19 ,
V_211 | V_212 ) )
return - V_20 ;
V_209 = F_42 ( & V_10 -> V_213 , sizeof( * V_209 ) , V_214 ) ;
if ( ! V_209 )
return - V_215 ;
V_3 = & V_209 -> V_3 ;
F_43 ( V_3 , V_10 , & V_216 ) ;
for ( V_27 = 0 ; V_27 < 4 ; V_27 ++ ) {
V_203 = F_4 ( V_3 , V_62 + V_27 ) ;
if ( V_203 < 0 )
return V_203 ;
V_210 [ V_27 ] = V_203 ;
}
F_44 ( V_10 , L_69 ,
V_10 -> V_8 << 1 , V_10 -> V_19 -> V_217 ) ;
if ( V_210 [ 2 ] == 4 && V_210 [ 3 ] == 0 ) {
F_45 ( V_3 , L_70 ,
V_210 [ 0 ] , V_210 [ 1 ] ) ;
F_9 ( V_3 , V_61 , 0 ) ;
} else {
if ( V_210 [ 2 ] == 3 || V_210 [ 3 ] == 0x21 ) {
F_45 ( V_3 , L_71 ,
V_210 [ 2 ] , V_210 [ 3 ] ) ;
} else {
F_45 ( V_3 , L_72 ,
V_210 [ 2 ] , V_210 [ 3 ] ) ;
F_45 ( V_3 , L_73 ,
V_210 [ 2 ] , V_210 [ 3 ] ) ;
}
}
V_209 -> V_133 = V_135 ;
V_209 -> V_105 = V_110 ;
V_209 -> V_109 = 1 ;
F_46 ( & V_209 -> V_7 , 4 ) ;
F_47 ( & V_209 -> V_7 , & V_218 ,
V_160 , 0 , 255 , 1 , 128 ) ;
F_47 ( & V_209 -> V_7 , & V_218 ,
V_161 , 0 , 255 , 1 , 128 ) ;
F_47 ( & V_209 -> V_7 , & V_218 ,
V_162 , 0 , 255 , 1 , 128 ) ;
F_47 ( & V_209 -> V_7 , & V_218 ,
V_163 , - 128 , 127 , 1 , 0 ) ;
V_3 -> V_219 = & V_209 -> V_7 ;
if ( V_209 -> V_7 . error ) {
V_203 = V_209 -> V_7 . error ;
F_48 ( & V_209 -> V_7 ) ;
return V_203 ;
}
F_23 ( & V_209 -> V_7 ) ;
V_209 -> V_153 . V_182 = 0 ;
if ( F_25 ( V_3 ) & V_152 )
V_209 -> V_153 . V_154 = V_155 ;
else
V_209 -> V_153 . V_154 = V_156 ;
V_209 -> V_153 . V_181 = 0 ;
V_209 -> V_153 . V_172 = V_189 ;
if ( V_21 > 1 )
F_13 ( V_3 ) ;
return 0 ;
}
static int F_49 ( struct V_9 * V_10 )
{
struct V_2 * V_3 = F_50 ( V_10 ) ;
struct V_1 * V_104 = F_1 ( V_3 ) ;
F_8 ( 1 , V_21 , V_3 ,
L_74 ,
V_10 -> V_8 << 1 ) ;
F_51 ( V_3 ) ;
F_48 ( & V_104 -> V_7 ) ;
return 0 ;
}
