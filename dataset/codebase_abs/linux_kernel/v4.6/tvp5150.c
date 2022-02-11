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
if ( ( V_95 -> V_98 == 0x5150 && V_95 -> V_99 == 0x0400 ) ||
( V_95 -> V_98 == 0x5151 && V_95 -> V_99 == 0x0100 ) ) {
if ( ! V_95 -> V_100 )
V_96 = 8 ;
}
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
V_95 -> V_96 , V_95 -> V_104 ,
V_96 , V_94 ) ;
F_9 ( V_3 , V_21 , V_94 ) ;
F_9 ( V_3 , V_19 , V_96 ) ;
V_97 = F_4 ( V_3 , V_22 ) ;
if ( V_97 < 0 ) {
F_7 ( V_3 , L_63 , V_105 , V_97 ) ;
return;
}
if ( V_95 -> V_96 == V_103 )
V_97 = ( V_97 & ~ 0x40 ) | 0x10 ;
else
V_97 = ( V_97 & ~ 0x10 ) | 0x40 ;
F_9 ( V_3 , V_22 , V_97 ) ;
}
static int F_15 ( struct V_2 * V_3 ,
const struct V_106 * V_107 )
{
while ( V_107 -> V_108 != 0xff ) {
F_9 ( V_3 , V_107 -> V_108 , V_107 -> V_13 ) ;
V_107 ++ ;
}
return 0 ;
}
static int F_16 ( struct V_2 * V_3 ,
const struct V_109 * V_107 )
{
unsigned int V_18 ;
F_9 ( V_3 , V_82 , 0 ) ;
for ( V_18 = V_92 ; V_18 <= V_93 ; V_18 ++ )
F_9 ( V_3 , V_18 , 0xff ) ;
while ( V_107 -> V_108 != ( V_110 ) - 1 ) {
F_9 ( V_3 , V_111 , V_107 -> V_108 >> 8 ) ;
F_9 ( V_3 , V_112 , V_107 -> V_108 ) ;
for ( V_18 = 0 ; V_18 < 16 ; V_18 ++ )
F_9 ( V_3 , V_113 , V_107 -> V_114 [ V_18 ] ) ;
V_107 ++ ;
}
return 0 ;
}
static int F_17 ( struct V_2 * V_3 ,
struct V_115 * V_116 )
{
const struct V_109 * V_107 = V_117 ;
int line ;
F_8 ( 1 , V_12 , V_3 , L_64 ) ;
memset ( V_116 , 0 , sizeof *V_116 ) ;
while ( V_107 -> V_108 != ( V_110 ) - 1 ) {
for ( line = V_107 -> type . V_118 ; line <= V_107 -> type . V_119 ; line ++ ) {
V_116 -> V_120 [ 0 ] [ line ] |= V_107 -> type . V_121 ;
}
V_116 -> V_122 |= V_107 -> type . V_121 ;
V_107 ++ ;
}
return 0 ;
}
static int F_18 ( struct V_2 * V_3 ,
const struct V_109 * V_107 ,
unsigned int type , T_1 V_123 , int line ,
const int V_124 )
{
struct V_1 * V_95 = F_1 ( V_3 ) ;
T_2 V_125 = V_95 -> V_126 ;
T_1 V_108 ;
int V_127 = 0 ;
if ( V_125 == V_128 ) {
F_7 ( V_3 , L_65 ) ;
return 0 ;
} else if ( V_125 & V_129 ) {
line += 3 ;
}
if ( line < 6 || line > 27 )
return 0 ;
while ( V_107 -> V_108 != ( V_110 ) - 1 ) {
if ( ( type & V_107 -> type . V_121 ) &&
( line >= V_107 -> type . V_118 ) &&
( line <= V_107 -> type . V_119 ) ) {
type = V_107 -> type . V_121 ;
break;
}
V_107 ++ ;
V_127 ++ ;
}
if ( V_107 -> V_108 == ( V_110 ) - 1 )
return 0 ;
type = V_127 | ( V_123 & 0xf0 ) ;
V_108 = ( ( line - 6 ) << 1 ) + V_92 ;
if ( V_124 & 1 ) {
F_9 ( V_3 , V_108 , type ) ;
}
if ( V_124 & 2 ) {
F_9 ( V_3 , V_108 + 1 , type ) ;
}
return type ;
}
static int F_19 ( struct V_2 * V_3 ,
const struct V_109 * V_107 , int line )
{
struct V_1 * V_95 = F_1 ( V_3 ) ;
T_2 V_125 = V_95 -> V_126 ;
T_1 V_108 ;
int V_127 , type = 0 ;
int V_18 , V_130 = 0 ;
if ( V_125 == V_128 ) {
F_7 ( V_3 , L_65 ) ;
return 0 ;
} else if ( V_125 & V_129 ) {
line += 3 ;
}
if ( line < 6 || line > 27 )
return 0 ;
V_108 = ( ( line - 6 ) << 1 ) + V_92 ;
for ( V_18 = 0 ; V_18 <= 1 ; V_18 ++ ) {
V_130 = F_4 ( V_3 , V_108 + V_18 ) ;
if ( V_130 < 0 ) {
F_7 ( V_3 , L_63 ,
V_105 , V_130 ) ;
return 0 ;
}
V_127 = V_130 & 0x0f ;
if ( V_127 < 0x0f )
type |= V_107 [ V_127 ] . type . V_121 ;
}
return type ;
}
static int F_20 ( struct V_2 * V_3 , T_2 V_125 )
{
struct V_1 * V_95 = F_1 ( V_3 ) ;
int V_131 = 0 ;
V_95 -> V_126 = V_125 ;
if ( V_125 == V_132 ) {
V_131 = V_133 ;
} else if ( V_125 == V_134 ) {
V_131 = V_135 ;
} else if ( V_125 == V_136 || V_125 == V_137 ) {
V_131 = V_138 ;
} else {
if ( V_125 & V_139 )
V_131 = V_140 ;
else if ( V_125 & V_141 )
V_131 = V_142 ;
else if ( V_125 & V_143 )
V_131 = V_144 ;
}
F_8 ( 1 , V_12 , V_3 , L_66 , V_131 ) ;
F_9 ( V_3 , V_47 , V_131 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 , T_2 V_125 )
{
struct V_1 * V_95 = F_1 ( V_3 ) ;
if ( V_95 -> V_126 == V_125 )
return 0 ;
if ( V_125 & V_145 )
V_95 -> V_146 . V_147 = V_148 ;
else
V_95 -> V_146 . V_147 = V_149 ;
return F_20 ( V_3 , V_125 ) ;
}
static int F_22 ( struct V_2 * V_3 , T_3 V_97 )
{
struct V_1 * V_95 = F_1 ( V_3 ) ;
F_15 ( V_3 , V_150 ) ;
F_16 ( V_3 , V_117 ) ;
F_14 ( V_3 ) ;
F_15 ( V_3 , V_151 ) ;
F_23 ( & V_95 -> V_7 ) ;
F_20 ( V_3 , V_95 -> V_126 ) ;
if ( V_95 -> V_152 == V_153 )
F_9 ( V_3 , V_32 , 0x40 ) ;
return 0 ;
}
static int F_24 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_95 = F_1 ( V_3 ) ;
switch ( V_5 -> V_154 ) {
case V_155 :
F_9 ( V_3 , V_28 , V_5 -> V_97 ) ;
return 0 ;
case V_156 :
F_9 ( V_3 , V_31 , V_5 -> V_97 ) ;
return 0 ;
case V_157 :
F_9 ( V_3 , V_29 , V_5 -> V_97 ) ;
return 0 ;
case V_158 :
F_9 ( V_3 , V_30 , V_5 -> V_97 ) ;
case V_159 :
V_95 -> V_100 = V_5 -> V_97 ? false : true ;
F_14 ( V_3 ) ;
return 0 ;
}
return - V_160 ;
}
static T_2 F_25 ( struct V_2 * V_3 )
{
int V_97 = F_4 ( V_3 , V_65 ) ;
switch ( V_97 & 0x0F ) {
case 0x01 :
return V_139 ;
case 0x03 :
return V_141 ;
case 0x05 :
return V_134 ;
case 0x07 :
return V_136 | V_137 ;
case 0x09 :
return V_132 ;
case 0xb :
return V_143 ;
default:
return V_161 ;
}
}
static int F_26 ( struct V_2 * V_3 ,
struct V_162 * V_163 ,
struct V_164 * V_165 )
{
struct V_166 * V_167 ;
struct V_1 * V_95 = F_1 ( V_3 ) ;
if ( ! V_165 || V_165 -> V_168 )
return - V_160 ;
V_167 = & V_165 -> V_165 ;
F_22 ( V_3 , 0 ) ;
V_167 -> V_169 = V_95 -> V_146 . V_169 ;
V_167 -> V_147 = V_95 -> V_146 . V_147 / 2 ;
V_167 -> V_170 = V_171 ;
V_167 -> V_172 = V_173 ;
V_167 -> V_174 = V_175 ;
F_8 ( 1 , V_12 , V_3 , L_67 , V_167 -> V_169 ,
V_167 -> V_147 ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 , const struct V_176 * V_177 )
{
struct V_178 V_146 = V_177 -> V_10 ;
struct V_1 * V_95 = F_1 ( V_3 ) ;
T_2 V_125 ;
unsigned int V_179 ;
F_8 ( 1 , V_12 , V_3 , L_68 ,
V_105 , V_146 . V_180 , V_146 . V_181 , V_146 . V_169 , V_146 . V_147 ) ;
if ( V_177 -> type != V_182 )
return - V_160 ;
V_146 . V_180 = F_28 ( V_146 . V_180 , 0 , V_183 ) ;
V_146 . V_169 = F_29 (unsigned int, rect.width,
TVP5150_H_MAX - TVP5150_MAX_CROP_LEFT - rect.left,
TVP5150_H_MAX - rect.left) ;
V_146 . V_181 = F_28 ( V_146 . V_181 , 0 , V_184 ) ;
if ( V_95 -> V_126 == V_128 )
V_125 = F_25 ( V_3 ) ;
else
V_125 = V_95 -> V_126 ;
if ( V_125 & V_145 )
V_179 = V_148 ;
else
V_179 = V_149 ;
V_146 . V_147 = F_29 (unsigned int, rect.height,
hmax - TVP5150_MAX_CROP_TOP - rect.top,
hmax - rect.top) ;
F_9 ( V_3 , V_40 , V_146 . V_181 ) ;
F_9 ( V_3 , V_41 ,
V_146 . V_181 + V_146 . V_147 - V_179 ) ;
F_9 ( V_3 , V_34 ,
V_146 . V_180 >> V_185 ) ;
F_9 ( V_3 , V_35 ,
V_146 . V_180 | ( 1 << V_185 ) ) ;
F_9 ( V_3 , V_36 ,
( V_146 . V_180 + V_146 . V_169 - V_183 ) >>
V_185 ) ;
F_9 ( V_3 , V_37 ,
V_146 . V_180 + V_146 . V_169 - V_183 ) ;
V_95 -> V_146 = V_146 ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 , struct V_176 * V_177 )
{
struct V_1 * V_95 = F_1 ( V_3 ) ;
V_177 -> V_10 = V_95 -> V_146 ;
V_177 -> type = V_182 ;
return 0 ;
}
static int F_31 ( struct V_2 * V_3 , struct V_186 * V_177 )
{
struct V_1 * V_95 = F_1 ( V_3 ) ;
T_2 V_125 ;
if ( V_177 -> type != V_182 )
return - V_160 ;
V_177 -> V_187 . V_180 = 0 ;
V_177 -> V_187 . V_181 = 0 ;
V_177 -> V_187 . V_169 = V_188 ;
if ( V_95 -> V_126 == V_128 )
V_125 = F_25 ( V_3 ) ;
else
V_125 = V_95 -> V_126 ;
if ( V_125 & V_145 )
V_177 -> V_187 . V_147 = V_148 ;
else
V_177 -> V_187 . V_147 = V_149 ;
V_177 -> V_189 = V_177 -> V_187 ;
V_177 -> V_190 . V_191 = 1 ;
V_177 -> V_190 . V_192 = 1 ;
return 0 ;
}
static int F_32 ( struct V_2 * V_3 ,
struct V_193 * V_163 )
{
struct V_1 * V_95 = F_1 ( V_3 ) ;
V_163 -> type = V_95 -> V_152 ;
V_163 -> V_123 = V_194 | V_195
| V_196 | V_197 ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 ,
struct V_162 * V_163 ,
struct V_198 * V_170 )
{
if ( V_170 -> V_168 || V_170 -> V_199 )
return - V_160 ;
V_170 -> V_170 = V_171 ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 ,
struct V_162 * V_163 ,
struct V_200 * V_201 )
{
struct V_1 * V_95 = F_1 ( V_3 ) ;
if ( V_201 -> V_199 >= 8 || V_201 -> V_170 != V_171 )
return - V_160 ;
V_201 -> V_170 = V_171 ;
V_201 -> V_202 = V_95 -> V_146 . V_169 ;
V_201 -> V_203 = V_95 -> V_146 . V_169 ;
V_201 -> V_204 = V_95 -> V_146 . V_147 / 2 ;
V_201 -> V_205 = V_95 -> V_146 . V_147 / 2 ;
return 0 ;
}
static int F_35 ( struct V_206 * V_207 ,
const struct V_208 * V_209 ,
const struct V_208 * V_210 , T_3 V_123 )
{
#ifdef F_36
struct V_2 * V_3 = F_37 ( V_207 ) ;
struct V_1 * V_95 = F_1 ( V_3 ) ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_211 ; V_18 ++ ) {
if ( V_210 -> V_207 == & V_95 -> V_212 [ V_18 ] )
break;
}
if ( V_18 == V_211 )
return 0 ;
V_95 -> V_96 = V_18 ;
F_14 ( V_3 ) ;
#endif
return 0 ;
}
static int F_38 ( struct V_2 * V_3 , int V_100 )
{
struct V_1 * V_95 = F_1 ( V_3 ) ;
int V_97 = 0x09 ;
if ( V_95 -> V_152 == V_153 )
V_97 = 0x0d ;
F_9 ( V_3 , V_33 , 0x00 ) ;
if ( V_100 )
F_9 ( V_3 , V_22 , V_97 ) ;
else
F_9 ( V_3 , V_22 , 0x00 ) ;
return 0 ;
}
static int F_39 ( struct V_2 * V_3 ,
T_3 V_96 , T_3 V_104 , T_3 V_213 )
{
struct V_1 * V_95 = F_1 ( V_3 ) ;
V_95 -> V_96 = V_96 ;
V_95 -> V_104 = V_104 ;
if ( V_104 == V_214 )
V_95 -> V_100 = false ;
else
V_95 -> V_100 = true ;
F_14 ( V_3 ) ;
return 0 ;
}
static int F_40 ( struct V_2 * V_3 , struct V_215 * V_131 )
{
if ( V_131 -> V_216 == V_217 )
F_9 ( V_3 , V_25 , 0x70 ) ;
if ( V_131 -> V_218 [ 0 ] == 18 && V_131 -> V_218 [ 1 ] == 18 ) {
F_9 ( V_3 , V_40 , 0x00 ) ;
F_9 ( V_3 , V_41 , 0x01 ) ;
}
return 0 ;
}
static int F_41 ( struct V_2 * V_3 , struct V_219 * V_220 )
{
int V_18 ;
if ( V_220 -> V_122 != 0 ) {
for ( V_18 = 0 ; V_18 <= 23 ; V_18 ++ ) {
V_220 -> V_120 [ 1 ] [ V_18 ] = 0 ;
V_220 -> V_120 [ 0 ] [ V_18 ] =
F_18 ( V_3 , V_117 ,
V_220 -> V_120 [ 0 ] [ V_18 ] , 0xf0 , V_18 , 3 ) ;
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
static int F_42 ( struct V_2 * V_3 , struct V_219 * V_220 )
{
int V_18 , V_221 = 0 ;
memset ( V_220 -> V_120 , 0 , sizeof( V_220 -> V_120 ) ) ;
for ( V_18 = 0 ; V_18 <= 23 ; V_18 ++ ) {
V_220 -> V_120 [ 0 ] [ V_18 ] =
F_19 ( V_3 , V_117 , V_18 ) ;
V_221 |= V_220 -> V_120 [ 0 ] [ V_18 ] ;
}
V_220 -> V_122 = V_221 ;
return 0 ;
}
static int F_43 ( struct V_2 * V_3 , struct V_222 * V_108 )
{
int V_223 ;
V_223 = F_4 ( V_3 , V_108 -> V_108 & 0xff ) ;
if ( V_223 < 0 ) {
F_7 ( V_3 , L_63 , V_105 , V_223 ) ;
return V_223 ;
}
V_108 -> V_97 = V_223 ;
V_108 -> V_224 = 1 ;
return 0 ;
}
static int F_44 ( struct V_2 * V_3 , const struct V_222 * V_108 )
{
F_9 ( V_3 , V_108 -> V_108 & 0xff , V_108 -> V_97 & 0xff ) ;
return 0 ;
}
static int F_45 ( struct V_2 * V_3 , struct V_225 * V_226 )
{
int V_227 = F_4 ( V_3 , 0x88 ) ;
V_226 -> signal = ( ( V_227 & 0x04 ) && ( V_227 & 0x02 ) ) ? 0xffff : 0x0 ;
return 0 ;
}
static int F_46 ( struct V_2 * V_3 )
{
#ifdef F_36
struct V_1 * V_95 = F_1 ( V_3 ) ;
int V_130 = 0 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_211 ; V_18 ++ ) {
struct V_206 * V_96 = & V_95 -> V_212 [ V_18 ] ;
struct V_208 * V_168 = & V_95 -> V_228 [ V_18 ] ;
if ( ! V_96 -> V_229 )
continue;
V_95 -> V_228 [ V_18 ] . V_123 = V_230 ;
V_130 = F_47 ( V_96 , 1 , V_168 ) ;
if ( V_130 < 0 )
return V_130 ;
V_130 = F_48 ( V_3 -> V_231 -> V_232 , V_96 ) ;
if ( V_130 < 0 )
return V_130 ;
V_130 = F_49 ( V_96 , 0 , & V_3 -> V_207 ,
V_233 , 0 ) ;
if ( V_130 < 0 ) {
F_50 ( V_96 ) ;
return V_130 ;
}
}
#endif
return 0 ;
}
static int F_51 ( struct V_1 * V_234 )
{
struct V_2 * V_3 = & V_234 -> V_3 ;
struct V_9 * V_10 = F_5 ( V_3 ) ;
unsigned int V_18 ;
T_1 V_107 [ 4 ] ;
int V_223 ;
for ( V_18 = 0 ; V_18 < 4 ; V_18 ++ ) {
V_223 = F_4 ( V_3 , V_53 + V_18 ) ;
if ( V_223 < 0 )
return V_223 ;
V_107 [ V_18 ] = V_223 ;
}
V_234 -> V_98 = ( V_107 [ 0 ] << 8 ) | V_107 [ 1 ] ;
V_234 -> V_99 = ( V_107 [ 2 ] << 8 ) | V_107 [ 3 ] ;
F_52 ( V_3 , L_69 ,
V_234 -> V_98 , V_107 [ 2 ] , V_107 [ 3 ] , V_10 -> V_8 << 1 ,
V_10 -> V_235 -> V_229 ) ;
if ( V_234 -> V_98 == 0x5150 && V_234 -> V_99 == 0x0321 ) {
F_52 ( V_3 , L_70 ) ;
} else if ( V_234 -> V_98 == 0x5150 && V_234 -> V_99 == 0x0400 ) {
F_52 ( V_3 , L_71 ) ;
F_9 ( V_3 , V_52 , 0 ) ;
} else if ( V_234 -> V_98 == 0x5151 && V_234 -> V_99 == 0x0100 ) {
F_52 ( V_3 , L_72 ) ;
} else {
F_52 ( V_3 , L_73 ,
V_234 -> V_98 ) ;
}
return 0 ;
}
static int F_53 ( struct V_9 * V_10 )
{
struct V_236 * V_237 ;
struct V_236 * V_238 ;
V_237 = F_54 ( & V_10 -> V_239 , L_74 , V_240 ) ;
if ( F_55 ( V_237 ) )
return F_56 ( V_237 ) ;
if ( V_237 ) {
F_57 ( V_237 , 0 ) ;
F_58 ( 20 ) ;
}
V_238 = F_54 ( & V_10 -> V_239 , L_75 , V_240 ) ;
if ( F_55 ( V_238 ) )
return F_56 ( V_238 ) ;
if ( V_238 ) {
F_59 ( 500 ) ;
F_57 ( V_238 , 0 ) ;
F_60 ( 200 , 250 ) ;
}
return 0 ;
}
static int F_61 ( struct V_1 * V_95 , struct V_241 * V_242 )
{
struct V_243 V_244 ;
struct V_241 * V_245 ;
#ifdef F_36
struct V_241 * V_246 , * V_247 ;
struct V_206 * V_96 ;
const char * V_229 ;
T_3 V_248 ;
#endif
unsigned int V_123 ;
int V_130 = 0 ;
V_245 = F_62 ( V_242 , NULL ) ;
if ( ! V_245 )
return - V_160 ;
V_130 = F_63 ( V_245 , & V_244 ) ;
if ( V_130 )
goto V_249;
V_123 = V_244 . V_250 . V_251 . V_123 ;
if ( V_244 . V_252 == V_153 &&
! ( V_123 & V_253 &&
V_123 & V_254 &&
V_123 & V_196 ) ) {
V_130 = - V_160 ;
goto V_249;
}
V_95 -> V_152 = V_244 . V_252 ;
#ifdef F_36
V_246 = F_64 ( V_242 , L_76 ) ;
if ( ! V_246 )
goto V_249;
F_65 (connectors, child) {
V_130 = F_66 ( V_247 , L_77 , & V_248 ) ;
if ( V_130 ) {
F_7 ( & V_95 -> V_3 ,
L_78 ,
V_247 -> V_229 ) ;
goto V_255;
}
if ( V_248 >= V_211 ) {
V_130 = - V_160 ;
goto V_255;
}
V_96 = & V_95 -> V_212 [ V_248 ] ;
if ( V_96 -> V_229 ) {
F_7 ( & V_95 -> V_3 ,
L_79 ,
V_96 -> V_229 ) ;
V_130 = - V_160 ;
goto V_255;
}
switch ( V_248 ) {
case V_102 :
case V_101 :
V_96 -> V_256 = V_257 ;
break;
case V_103 :
V_96 -> V_256 = V_258 ;
break;
}
V_96 -> V_123 = V_259 ;
V_130 = F_67 ( V_247 , L_80 , & V_229 ) ;
if ( V_130 < 0 ) {
F_7 ( & V_95 -> V_3 ,
L_81 ,
V_247 -> V_229 ) ;
goto V_255;
}
V_96 -> V_229 = V_229 ;
}
V_255:
F_68 ( V_246 ) ;
#endif
V_249:
F_68 ( V_245 ) ;
return V_130 ;
}
static int F_69 ( struct V_9 * V_10 ,
const struct V_260 * V_154 )
{
struct V_1 * V_234 ;
struct V_2 * V_3 ;
struct V_241 * V_242 = V_10 -> V_239 . V_261 ;
int V_223 ;
if ( ! F_70 ( V_10 -> V_235 ,
V_262 | V_263 ) )
return - V_264 ;
V_223 = F_53 ( V_10 ) ;
if ( V_223 )
return V_223 ;
V_234 = F_71 ( & V_10 -> V_239 , sizeof( * V_234 ) , V_265 ) ;
if ( ! V_234 )
return - V_266 ;
V_3 = & V_234 -> V_3 ;
if ( F_72 ( V_267 ) && V_242 ) {
V_223 = F_61 ( V_234 , V_242 ) ;
if ( V_223 ) {
F_7 ( V_3 , L_82 , V_223 ) ;
return V_223 ;
}
} else {
V_234 -> V_152 = V_268 ;
}
F_73 ( V_3 , V_10 , & V_269 ) ;
V_3 -> V_123 |= V_270 ;
#if F_74 ( F_36 )
V_234 -> V_271 [ V_233 ] . V_123 = V_272 ;
V_234 -> V_271 [ V_273 ] . V_123 = V_230 ;
V_234 -> V_271 [ V_274 ] . V_123 = V_230 ;
V_3 -> V_207 . V_256 = V_275 ;
V_223 = F_47 ( & V_3 -> V_207 , V_276 , V_234 -> V_271 ) ;
if ( V_223 < 0 )
return V_223 ;
V_3 -> V_207 . V_277 = & V_278 ;
#endif
V_223 = F_51 ( V_234 ) ;
if ( V_223 < 0 )
return V_223 ;
V_234 -> V_126 = V_128 ;
V_234 -> V_96 = V_101 ;
V_234 -> V_100 = true ;
F_75 ( & V_234 -> V_7 , 5 ) ;
F_76 ( & V_234 -> V_7 , & V_279 ,
V_155 , 0 , 255 , 1 , 128 ) ;
F_76 ( & V_234 -> V_7 , & V_279 ,
V_156 , 0 , 255 , 1 , 128 ) ;
F_76 ( & V_234 -> V_7 , & V_279 ,
V_157 , 0 , 255 , 1 , 128 ) ;
F_76 ( & V_234 -> V_7 , & V_279 ,
V_158 , - 128 , 127 , 1 , 0 ) ;
F_76 ( & V_234 -> V_7 , & V_279 ,
V_280 , 27000000 ,
27000000 , 1 , 27000000 ) ;
F_77 ( & V_234 -> V_7 , & V_279 ,
V_159 ,
F_78 ( V_281 ) ,
0 , 0 , V_281 ) ;
V_3 -> V_282 = & V_234 -> V_7 ;
if ( V_234 -> V_7 . error ) {
V_223 = V_234 -> V_7 . error ;
goto V_249;
}
F_23 ( & V_234 -> V_7 ) ;
V_234 -> V_146 . V_181 = 0 ;
if ( F_25 ( V_3 ) & V_145 )
V_234 -> V_146 . V_147 = V_148 ;
else
V_234 -> V_146 . V_147 = V_149 ;
V_234 -> V_146 . V_180 = 0 ;
V_234 -> V_146 . V_169 = V_188 ;
V_223 = F_79 ( V_3 ) ;
if ( V_223 < 0 )
goto V_249;
if ( V_12 > 1 )
F_13 ( V_3 ) ;
return 0 ;
V_249:
F_80 ( & V_234 -> V_7 ) ;
return V_223 ;
}
static int F_81 ( struct V_9 * V_10 )
{
struct V_2 * V_3 = F_82 ( V_10 ) ;
struct V_1 * V_95 = F_1 ( V_3 ) ;
F_8 ( 1 , V_12 , V_3 ,
L_83 ,
V_10 -> V_8 << 1 ) ;
F_83 ( V_3 ) ;
F_80 ( & V_95 -> V_7 ) ;
return 0 ;
}
