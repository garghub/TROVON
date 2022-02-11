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
int V_11 ;
V_11 = F_6 ( V_10 , V_8 ) ;
if ( V_11 < 0 ) {
F_7 ( V_3 , L_1 , V_11 ) ;
return V_11 ;
}
F_8 ( 2 , V_12 , V_3 , L_2 , V_8 , V_11 ) ;
return V_11 ;
}
static inline void F_9 ( struct V_2 * V_3 , unsigned char V_8 ,
unsigned char V_13 )
{
struct V_9 * V_10 = F_5 ( V_3 ) ;
int V_11 ;
F_8 ( 2 , V_12 , V_3 , L_3 , V_8 , V_13 ) ;
V_11 = F_10 ( V_10 , V_8 , V_13 ) ;
if ( V_11 < 0 )
F_8 ( 0 , V_12 , V_3 , L_1 , V_11 ) ;
}
static void F_11 ( struct V_2 * V_3 , char * V_14 , T_1 V_15 ,
const T_1 V_16 , int V_17 )
{
int V_18 = 0 ;
while ( V_15 != ( T_1 ) ( V_16 + 1 ) ) {
if ( ( V_18 % V_17 ) == 0 ) {
if ( V_18 > 0 )
F_12 ( L_4 ) ;
F_12 ( L_5 , V_14 , V_15 ) ;
}
F_12 ( L_6 , F_4 ( V_3 , V_15 ) ) ;
V_15 ++ ;
V_18 ++ ;
}
F_12 ( L_4 ) ;
}
static int F_13 ( struct V_2 * V_3 )
{
F_12 ( L_7 ,
F_4 ( V_3 , V_19 ) ) ;
F_12 ( L_8 ,
F_4 ( V_3 , V_20 ) ) ;
F_12 ( L_9 ,
F_4 ( V_3 , V_21 ) ) ;
F_12 ( L_10 ,
F_4 ( V_3 , V_22 ) ) ;
F_12 ( L_11 ,
F_4 ( V_3 , V_23 ) ) ;
F_12 ( L_12 ,
F_4 ( V_3 , V_24 ) ) ;
F_12 ( L_13 ,
F_4 ( V_3 , V_25 ) ,
F_4 ( V_3 , V_26 ) ,
F_4 ( V_3 , V_27 ) ) ;
F_12 ( L_14 ,
F_4 ( V_3 , V_28 ) ) ;
F_12 ( L_15 ,
F_4 ( V_3 , V_29 ) ) ;
F_12 ( L_16 ,
F_4 ( V_3 , V_30 ) ) ;
F_12 ( L_17 ,
F_4 ( V_3 , V_31 ) ) ;
F_12 ( L_18 ,
F_4 ( V_3 , V_32 ) ) ;
F_12 ( L_19 ,
F_4 ( V_3 , V_33 ) ) ;
F_12 ( L_20 ,
F_4 ( V_3 , V_34 ) ,
F_4 ( V_3 , V_35 ) ) ;
F_12 ( L_21 ,
F_4 ( V_3 , V_36 ) ,
F_4 ( V_3 , V_37 ) ) ;
F_12 ( L_22 ,
F_4 ( V_3 , V_38 ) ) ;
F_12 ( L_23 ,
F_4 ( V_3 , V_39 ) ) ;
F_12 ( L_24 ,
F_4 ( V_3 , V_40 ) ) ;
F_12 ( L_25 ,
F_4 ( V_3 , V_41 ) ) ;
F_12 ( L_26 ,
F_4 ( V_3 , V_42 ) ,
F_4 ( V_3 , V_43 ) ) ;
F_12 ( L_27 ,
F_4 ( V_3 , V_44 ) ) ;
F_12 ( L_28 ,
F_4 ( V_3 , V_45 ) ) ;
F_12 ( L_29 ,
F_4 ( V_3 , V_46 ) ) ;
F_12 ( L_30 ,
F_4 ( V_3 , V_47 ) ) ;
F_12 ( L_31 ,
F_4 ( V_3 , V_48 ) ,
F_4 ( V_3 , V_49 ) ) ;
F_12 ( L_32 ,
F_4 ( V_3 , V_50 ) ) ;
F_12 ( L_33 ,
F_4 ( V_3 , V_51 ) ) ;
F_12 ( L_34 ,
( F_4 ( V_3 , V_52 ) & 1 ) ? 3 : 4 ) ;
F_12 ( L_35 ,
F_4 ( V_3 , V_53 ) ,
F_4 ( V_3 , V_54 ) ) ;
F_12 ( L_36 ,
F_4 ( V_3 , V_55 ) ,
F_4 ( V_3 , V_56 ) ) ;
F_12 ( L_37 ,
F_4 ( V_3 , V_57 ) ,
F_4 ( V_3 , V_58 ) ) ;
F_12 ( L_38 ,
F_4 ( V_3 , V_59 ) ) ;
F_12 ( L_39 ,
F_4 ( V_3 , V_60 ) ) ;
F_12 ( L_40 ,
F_4 ( V_3 , V_61 ) ,
F_4 ( V_3 , V_62 ) ,
F_4 ( V_3 , V_63 ) ,
F_4 ( V_3 , V_64 ) ,
F_4 ( V_3 , V_65 ) ) ;
F_11 ( V_3 , L_41 , V_66 ,
V_67 , 8 ) ;
F_11 ( V_3 , L_42 , V_68 ,
V_69 , 8 ) ;
F_12 ( L_43 ,
F_4 ( V_3 , V_70 ) ) ;
F_12 ( L_44 ,
F_4 ( V_3 , V_71 ) ) ;
F_12 ( L_45 ,
F_4 ( V_3 , V_72 ) ) ;
F_12 ( L_46 ,
F_4 ( V_3 , V_73 ) ) ;
F_12 ( L_47 ,
F_4 ( V_3 , V_74 ) ) ;
F_12 ( L_48 ,
F_4 ( V_3 , V_75 ) ) ;
F_12 ( L_49 ,
F_4 ( V_3 , V_76 ) ) ;
F_12 ( L_50 ,
F_4 ( V_3 , V_77 ) ) ;
F_12 ( L_51 ,
F_4 ( V_3 , V_78 ) ) ;
F_12 ( L_52 ,
F_4 ( V_3 , V_79 ) ,
F_4 ( V_3 , V_80 ) ) ;
F_12 ( L_53 ,
F_4 ( V_3 , V_81 ) ) ;
F_12 ( L_54 ,
F_4 ( V_3 , V_82 ) ) ;
F_12 ( L_55 ,
F_4 ( V_3 , V_83 ) ) ;
F_11 ( V_3 , L_56 , V_84 ,
V_85 , 8 ) ;
F_11 ( V_3 , L_57 , V_86 ,
V_87 , 8 ) ;
F_11 ( V_3 , L_58 , V_88 ,
V_89 , 8 ) ;
F_11 ( V_3 , L_59 , V_90 ,
V_91 , 10 ) ;
F_11 ( V_3 , L_60 , V_92 ,
V_93 , 8 ) ;
return 0 ;
}
static inline void F_14 ( struct V_2 * V_3 )
{
int V_94 = 0 ;
struct V_1 * V_95 = F_1 ( V_3 ) ;
int V_96 = 0 ;
int V_97 ;
if ( ( V_95 -> V_98 & V_99 ) || ! V_95 -> V_100 )
V_96 = 8 ;
switch ( V_95 -> V_96 ) {
case V_101 :
V_96 |= 2 ;
case V_102 :
break;
case V_103 :
default:
V_96 |= 1 ;
break;
}
F_8 ( 1 , V_12 , V_3 , L_61
L_62 ,
V_95 -> V_96 , V_95 -> V_98 ,
V_96 , V_94 ) ;
F_9 ( V_3 , V_21 , V_94 ) ;
F_9 ( V_3 , V_19 , V_96 ) ;
V_97 = F_4 ( V_3 , V_22 ) ;
if ( V_97 < 0 ) {
F_7 ( V_3 , L_63 , V_104 , V_97 ) ;
return;
}
if ( V_95 -> V_96 == V_103 )
V_97 = ( V_97 & ~ 0x40 ) | 0x10 ;
else
V_97 = ( V_97 & ~ 0x10 ) | 0x40 ;
F_9 ( V_3 , V_22 , V_97 ) ;
}
static int F_15 ( struct V_2 * V_3 ,
const struct V_105 * V_106 )
{
while ( V_106 -> V_107 != 0xff ) {
F_9 ( V_3 , V_106 -> V_107 , V_106 -> V_13 ) ;
V_106 ++ ;
}
return 0 ;
}
static int F_16 ( struct V_2 * V_3 ,
const struct V_108 * V_106 )
{
unsigned int V_18 ;
F_9 ( V_3 , V_82 , 0 ) ;
for ( V_18 = V_92 ; V_18 <= V_93 ; V_18 ++ )
F_9 ( V_3 , V_18 , 0xff ) ;
while ( V_106 -> V_107 != ( V_109 ) - 1 ) {
F_9 ( V_3 , V_110 , V_106 -> V_107 >> 8 ) ;
F_9 ( V_3 , V_111 , V_106 -> V_107 ) ;
for ( V_18 = 0 ; V_18 < 16 ; V_18 ++ )
F_9 ( V_3 , V_112 , V_106 -> V_113 [ V_18 ] ) ;
V_106 ++ ;
}
return 0 ;
}
static int F_17 ( struct V_2 * V_3 ,
struct V_114 * V_115 )
{
const struct V_108 * V_106 = V_116 ;
int line ;
F_8 ( 1 , V_12 , V_3 , L_64 ) ;
memset ( V_115 , 0 , sizeof *V_115 ) ;
while ( V_106 -> V_107 != ( V_109 ) - 1 ) {
for ( line = V_106 -> type . V_117 ; line <= V_106 -> type . V_118 ; line ++ ) {
V_115 -> V_119 [ 0 ] [ line ] |= V_106 -> type . V_120 ;
}
V_115 -> V_121 |= V_106 -> type . V_120 ;
V_106 ++ ;
}
return 0 ;
}
static int F_18 ( struct V_2 * V_3 ,
const struct V_108 * V_106 ,
unsigned int type , T_1 V_122 , int line ,
const int V_123 )
{
struct V_1 * V_95 = F_1 ( V_3 ) ;
T_2 V_124 = V_95 -> V_125 ;
T_1 V_107 ;
int V_126 = 0 ;
if ( V_124 == V_127 ) {
F_7 ( V_3 , L_65 ) ;
return 0 ;
} else if ( V_124 & V_128 ) {
line += 3 ;
}
if ( line < 6 || line > 27 )
return 0 ;
while ( V_106 -> V_107 != ( V_109 ) - 1 ) {
if ( ( type & V_106 -> type . V_120 ) &&
( line >= V_106 -> type . V_117 ) &&
( line <= V_106 -> type . V_118 ) ) {
type = V_106 -> type . V_120 ;
break;
}
V_106 ++ ;
V_126 ++ ;
}
if ( V_106 -> V_107 == ( V_109 ) - 1 )
return 0 ;
type = V_126 | ( V_122 & 0xf0 ) ;
V_107 = ( ( line - 6 ) << 1 ) + V_92 ;
if ( V_123 & 1 ) {
F_9 ( V_3 , V_107 , type ) ;
}
if ( V_123 & 2 ) {
F_9 ( V_3 , V_107 + 1 , type ) ;
}
return type ;
}
static int F_19 ( struct V_2 * V_3 ,
const struct V_108 * V_106 , int line )
{
struct V_1 * V_95 = F_1 ( V_3 ) ;
T_2 V_124 = V_95 -> V_125 ;
T_1 V_107 ;
int V_126 , type = 0 ;
int V_18 , V_129 = 0 ;
if ( V_124 == V_127 ) {
F_7 ( V_3 , L_65 ) ;
return 0 ;
} else if ( V_124 & V_128 ) {
line += 3 ;
}
if ( line < 6 || line > 27 )
return 0 ;
V_107 = ( ( line - 6 ) << 1 ) + V_92 ;
for ( V_18 = 0 ; V_18 <= 1 ; V_18 ++ ) {
V_129 = F_4 ( V_3 , V_107 + V_18 ) ;
if ( V_129 < 0 ) {
F_7 ( V_3 , L_63 ,
V_104 , V_129 ) ;
return 0 ;
}
V_126 = V_129 & 0x0f ;
if ( V_126 < 0x0f )
type |= V_106 [ V_126 ] . type . V_120 ;
}
return type ;
}
static int F_20 ( struct V_2 * V_3 , T_2 V_124 )
{
struct V_1 * V_95 = F_1 ( V_3 ) ;
int V_130 = 0 ;
V_95 -> V_125 = V_124 ;
if ( V_124 == V_131 ) {
V_130 = V_132 ;
} else if ( V_124 == V_133 ) {
V_130 = V_134 ;
} else if ( V_124 == V_135 || V_124 == V_136 ) {
V_130 = V_137 ;
} else {
if ( V_124 & V_138 )
V_130 = V_139 ;
else if ( V_124 & V_140 )
V_130 = V_141 ;
else if ( V_124 & V_142 )
V_130 = V_143 ;
}
F_8 ( 1 , V_12 , V_3 , L_66 , V_130 ) ;
F_9 ( V_3 , V_47 , V_130 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 , T_2 V_124 )
{
struct V_1 * V_95 = F_1 ( V_3 ) ;
if ( V_95 -> V_125 == V_124 )
return 0 ;
if ( V_124 & V_144 )
V_95 -> V_145 . V_146 = V_147 ;
else
V_95 -> V_145 . V_146 = V_148 ;
return F_20 ( V_3 , V_124 ) ;
}
static int F_22 ( struct V_2 * V_3 , T_3 V_97 )
{
struct V_1 * V_95 = F_1 ( V_3 ) ;
F_15 ( V_3 , V_149 ) ;
F_16 ( V_3 , V_116 ) ;
F_14 ( V_3 ) ;
F_15 ( V_3 , V_150 ) ;
F_23 ( & V_95 -> V_7 ) ;
F_20 ( V_3 , V_95 -> V_125 ) ;
return 0 ;
}
static int F_24 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
switch ( V_5 -> V_151 ) {
case V_152 :
F_9 ( V_3 , V_28 , V_5 -> V_97 ) ;
return 0 ;
case V_153 :
F_9 ( V_3 , V_31 , V_5 -> V_97 ) ;
return 0 ;
case V_154 :
F_9 ( V_3 , V_29 , V_5 -> V_97 ) ;
return 0 ;
case V_155 :
F_9 ( V_3 , V_30 , V_5 -> V_97 ) ;
return 0 ;
}
return - V_156 ;
}
static T_2 F_25 ( struct V_2 * V_3 )
{
int V_97 = F_4 ( V_3 , V_65 ) ;
switch ( V_97 & 0x0F ) {
case 0x01 :
return V_138 ;
case 0x03 :
return V_140 ;
case 0x05 :
return V_133 ;
case 0x07 :
return V_135 | V_136 ;
case 0x09 :
return V_131 ;
case 0xb :
return V_142 ;
default:
return V_157 ;
}
}
static int F_26 ( struct V_2 * V_3 ,
struct V_158 * V_159 ,
struct V_160 * V_161 )
{
if ( V_161 -> V_162 || V_161 -> V_163 )
return - V_156 ;
V_161 -> V_161 = V_164 ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 ,
struct V_158 * V_159 ,
struct V_165 * V_166 )
{
struct V_167 * V_168 ;
struct V_1 * V_95 = F_1 ( V_3 ) ;
if ( ! V_166 || V_166 -> V_162 )
return - V_156 ;
V_168 = & V_166 -> V_166 ;
F_22 ( V_3 , 0 ) ;
V_168 -> V_169 = V_95 -> V_145 . V_169 ;
V_168 -> V_146 = V_95 -> V_145 . V_146 ;
V_168 -> V_161 = V_164 ;
V_168 -> V_170 = V_171 ;
V_168 -> V_172 = V_173 ;
F_8 ( 1 , V_12 , V_3 , L_67 , V_168 -> V_169 ,
V_168 -> V_146 ) ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 , const struct V_174 * V_175 )
{
struct V_176 V_145 = V_175 -> V_10 ;
struct V_1 * V_95 = F_1 ( V_3 ) ;
T_2 V_124 ;
unsigned int V_177 ;
F_8 ( 1 , V_12 , V_3 , L_68 ,
V_104 , V_145 . V_178 , V_145 . V_179 , V_145 . V_169 , V_145 . V_146 ) ;
if ( V_175 -> type != V_180 )
return - V_156 ;
V_145 . V_178 = F_29 ( V_145 . V_178 , 0 , V_181 ) ;
V_145 . V_169 = F_30 (unsigned int, rect.width,
TVP5150_H_MAX - TVP5150_MAX_CROP_LEFT - rect.left,
TVP5150_H_MAX - rect.left) ;
V_145 . V_179 = F_29 ( V_145 . V_179 , 0 , V_182 ) ;
if ( V_95 -> V_125 == V_127 )
V_124 = F_25 ( V_3 ) ;
else
V_124 = V_95 -> V_125 ;
if ( V_124 & V_144 )
V_177 = V_147 ;
else
V_177 = V_148 ;
V_145 . V_146 = F_30 (unsigned int, rect.height,
hmax - TVP5150_MAX_CROP_TOP - rect.top,
hmax - rect.top) ;
F_9 ( V_3 , V_40 , V_145 . V_179 ) ;
F_9 ( V_3 , V_41 ,
V_145 . V_179 + V_145 . V_146 - V_177 ) ;
F_9 ( V_3 , V_34 ,
V_145 . V_178 >> V_183 ) ;
F_9 ( V_3 , V_35 ,
V_145 . V_178 | ( 1 << V_183 ) ) ;
F_9 ( V_3 , V_36 ,
( V_145 . V_178 + V_145 . V_169 - V_181 ) >>
V_183 ) ;
F_9 ( V_3 , V_37 ,
V_145 . V_178 + V_145 . V_169 - V_181 ) ;
V_95 -> V_145 = V_145 ;
return 0 ;
}
static int F_31 ( struct V_2 * V_3 , struct V_174 * V_175 )
{
struct V_1 * V_95 = F_1 ( V_3 ) ;
V_175 -> V_10 = V_95 -> V_145 ;
V_175 -> type = V_180 ;
return 0 ;
}
static int F_32 ( struct V_2 * V_3 , struct V_184 * V_175 )
{
struct V_1 * V_95 = F_1 ( V_3 ) ;
T_2 V_124 ;
if ( V_175 -> type != V_180 )
return - V_156 ;
V_175 -> V_185 . V_178 = 0 ;
V_175 -> V_185 . V_179 = 0 ;
V_175 -> V_185 . V_169 = V_186 ;
if ( V_95 -> V_125 == V_127 )
V_124 = F_25 ( V_3 ) ;
else
V_124 = V_95 -> V_125 ;
if ( V_124 & V_144 )
V_175 -> V_185 . V_146 = V_147 ;
else
V_175 -> V_185 . V_146 = V_148 ;
V_175 -> V_187 = V_175 -> V_185 ;
V_175 -> V_188 . V_189 = 1 ;
V_175 -> V_188 . V_190 = 1 ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 ,
T_3 V_96 , T_3 V_98 , T_3 V_191 )
{
struct V_1 * V_95 = F_1 ( V_3 ) ;
V_95 -> V_96 = V_96 ;
V_95 -> V_98 = V_98 ;
F_14 ( V_3 ) ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 , struct V_192 * V_130 )
{
if ( V_130 -> V_193 == V_194 )
F_9 ( V_3 , V_25 , 0x70 ) ;
if ( V_130 -> V_195 [ 0 ] == 18 && V_130 -> V_195 [ 1 ] == 18 ) {
F_9 ( V_3 , V_40 , 0x00 ) ;
F_9 ( V_3 , V_41 , 0x01 ) ;
}
return 0 ;
}
static int F_35 ( struct V_2 * V_3 , struct V_196 * V_197 )
{
int V_18 ;
if ( V_197 -> V_121 != 0 ) {
for ( V_18 = 0 ; V_18 <= 23 ; V_18 ++ ) {
V_197 -> V_119 [ 1 ] [ V_18 ] = 0 ;
V_197 -> V_119 [ 0 ] [ V_18 ] =
F_18 ( V_3 , V_116 ,
V_197 -> V_119 [ 0 ] [ V_18 ] , 0xf0 , V_18 , 3 ) ;
}
F_9 ( V_3 , V_81 , 1 ) ;
} else {
F_9 ( V_3 , V_81 , 0 ) ;
F_9 ( V_3 , V_82 , 0 ) ;
for ( V_18 = V_92 ; V_18 <= V_93 ; V_18 ++ )
F_9 ( V_3 , V_18 , 0xff ) ;
}
return 0 ;
}
static int F_36 ( struct V_2 * V_3 , struct V_196 * V_197 )
{
int V_18 , V_198 = 0 ;
memset ( V_197 -> V_119 , 0 , sizeof( V_197 -> V_119 ) ) ;
for ( V_18 = 0 ; V_18 <= 23 ; V_18 ++ ) {
V_197 -> V_119 [ 0 ] [ V_18 ] =
F_19 ( V_3 , V_116 , V_18 ) ;
V_198 |= V_197 -> V_119 [ 0 ] [ V_18 ] ;
}
V_197 -> V_121 = V_198 ;
return 0 ;
}
static int F_37 ( struct V_2 * V_3 , struct V_199 * V_107 )
{
int V_200 ;
V_200 = F_4 ( V_3 , V_107 -> V_107 & 0xff ) ;
if ( V_200 < 0 ) {
F_7 ( V_3 , L_63 , V_104 , V_200 ) ;
return V_200 ;
}
V_107 -> V_97 = V_200 ;
V_107 -> V_201 = 1 ;
return 0 ;
}
static int F_38 ( struct V_2 * V_3 , const struct V_199 * V_107 )
{
F_9 ( V_3 , V_107 -> V_107 & 0xff , V_107 -> V_97 & 0xff ) ;
return 0 ;
}
static int F_39 ( struct V_2 * V_3 , struct V_202 * V_203 )
{
int V_204 = F_4 ( V_3 , 0x88 ) ;
V_203 -> signal = ( ( V_204 & 0x04 ) && ( V_204 & 0x02 ) ) ? 0xffff : 0x0 ;
return 0 ;
}
static int F_40 ( struct V_9 * V_10 ,
const struct V_205 * V_151 )
{
struct V_1 * V_206 ;
struct V_2 * V_3 ;
int V_207 [ 4 ] ;
int V_18 , V_200 ;
if ( ! F_41 ( V_10 -> V_208 ,
V_209 | V_210 ) )
return - V_211 ;
V_206 = F_42 ( & V_10 -> V_212 , sizeof( * V_206 ) , V_213 ) ;
if ( ! V_206 )
return - V_214 ;
V_3 = & V_206 -> V_3 ;
F_43 ( V_3 , V_10 , & V_215 ) ;
for ( V_18 = 0 ; V_18 < 4 ; V_18 ++ ) {
V_200 = F_4 ( V_3 , V_53 + V_18 ) ;
if ( V_200 < 0 )
return V_200 ;
V_207 [ V_18 ] = V_200 ;
}
F_44 ( V_10 , L_69 ,
V_10 -> V_8 << 1 , V_10 -> V_208 -> V_216 ) ;
if ( V_207 [ 2 ] == 4 && V_207 [ 3 ] == 0 ) {
F_45 ( V_3 , L_70 ,
V_207 [ 0 ] , V_207 [ 1 ] ) ;
F_9 ( V_3 , V_52 , 0 ) ;
} else {
if ( V_207 [ 2 ] == 3 || V_207 [ 3 ] == 0x21 ) {
F_45 ( V_3 , L_71 ,
V_207 [ 0 ] , V_207 [ 1 ] ) ;
} else {
F_45 ( V_3 , L_72 ,
V_207 [ 0 ] , V_207 [ 1 ] ) ;
F_45 ( V_3 , L_73 ,
V_207 [ 2 ] , V_207 [ 3 ] ) ;
}
}
V_206 -> V_125 = V_127 ;
V_206 -> V_96 = V_101 ;
V_206 -> V_100 = 1 ;
F_46 ( & V_206 -> V_7 , 4 ) ;
F_47 ( & V_206 -> V_7 , & V_217 ,
V_152 , 0 , 255 , 1 , 128 ) ;
F_47 ( & V_206 -> V_7 , & V_217 ,
V_153 , 0 , 255 , 1 , 128 ) ;
F_47 ( & V_206 -> V_7 , & V_217 ,
V_154 , 0 , 255 , 1 , 128 ) ;
F_47 ( & V_206 -> V_7 , & V_217 ,
V_155 , - 128 , 127 , 1 , 0 ) ;
V_3 -> V_218 = & V_206 -> V_7 ;
if ( V_206 -> V_7 . error ) {
V_200 = V_206 -> V_7 . error ;
goto V_219;
}
F_23 ( & V_206 -> V_7 ) ;
V_206 -> V_145 . V_179 = 0 ;
if ( F_25 ( V_3 ) & V_144 )
V_206 -> V_145 . V_146 = V_147 ;
else
V_206 -> V_145 . V_146 = V_148 ;
V_206 -> V_145 . V_178 = 0 ;
V_206 -> V_145 . V_169 = V_186 ;
V_200 = F_48 ( V_3 ) ;
if ( V_200 < 0 )
goto V_219;
if ( V_12 > 1 )
F_13 ( V_3 ) ;
return 0 ;
V_219:
F_49 ( & V_206 -> V_7 ) ;
return V_200 ;
}
static int F_50 ( struct V_9 * V_10 )
{
struct V_2 * V_3 = F_51 ( V_10 ) ;
struct V_1 * V_95 = F_1 ( V_3 ) ;
F_8 ( 1 , V_12 , V_3 ,
L_74 ,
V_10 -> V_8 << 1 ) ;
F_52 ( V_3 ) ;
F_49 ( & V_95 -> V_7 ) ;
return 0 ;
}
