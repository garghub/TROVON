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
F_7 ( V_3 -> V_12 , L_1 , V_11 ) ;
return V_11 ;
}
F_8 ( V_3 -> V_12 , 2 , V_13 , L_2 , V_8 , V_11 ) ;
return V_11 ;
}
static int F_9 ( struct V_2 * V_3 , unsigned char V_8 ,
unsigned char V_14 )
{
struct V_9 * V_10 = F_5 ( V_3 ) ;
int V_11 ;
F_8 ( V_3 -> V_12 , 2 , V_13 , L_3 , V_8 , V_14 ) ;
V_11 = F_10 ( V_10 , V_8 , V_14 ) ;
if ( V_11 < 0 )
F_7 ( V_3 -> V_12 , L_1 , V_11 ) ;
return V_11 ;
}
static void F_11 ( struct V_2 * V_3 , char * V_15 , T_1 V_16 ,
const T_1 V_17 , int V_18 )
{
T_1 V_19 [ 16 ] ;
int V_20 = 0 , V_21 , V_22 ;
if ( V_18 > 16 ) {
F_12 ( V_3 -> V_12 , L_4 ) ;
return;
}
for ( V_20 = V_16 ; V_20 < V_17 ; V_20 += V_18 ) {
V_22 = ( V_17 - V_20 > V_18 ) ? V_18 : V_17 - V_20 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ )
V_19 [ V_21 ] = F_4 ( V_3 , V_20 + V_21 ) ;
F_12 ( V_3 -> V_12 , L_5 , V_15 , V_20 , V_22 , V_19 ) ;
}
}
static int F_13 ( struct V_2 * V_3 )
{
F_12 ( V_3 -> V_12 , L_6 ,
F_4 ( V_3 , V_23 ) ) ;
F_12 ( V_3 -> V_12 , L_7 ,
F_4 ( V_3 , V_24 ) ) ;
F_12 ( V_3 -> V_12 , L_8 ,
F_4 ( V_3 , V_25 ) ) ;
F_12 ( V_3 -> V_12 , L_9 ,
F_4 ( V_3 , V_26 ) ) ;
F_12 ( V_3 -> V_12 , L_10 ,
F_4 ( V_3 , V_27 ) ) ;
F_12 ( V_3 -> V_12 , L_11 ,
F_4 ( V_3 , V_28 ) ) ;
F_12 ( V_3 -> V_12 , L_12 ,
F_4 ( V_3 , V_29 ) ,
F_4 ( V_3 , V_30 ) ,
F_4 ( V_3 , V_31 ) ) ;
F_12 ( V_3 -> V_12 , L_13 ,
F_4 ( V_3 , V_32 ) ) ;
F_12 ( V_3 -> V_12 , L_14 ,
F_4 ( V_3 , V_33 ) ) ;
F_12 ( V_3 -> V_12 , L_15 ,
F_4 ( V_3 , V_34 ) ) ;
F_12 ( V_3 -> V_12 , L_16 ,
F_4 ( V_3 , V_35 ) ) ;
F_12 ( V_3 -> V_12 , L_17 ,
F_4 ( V_3 , V_36 ) ) ;
F_12 ( V_3 -> V_12 , L_18 ,
F_4 ( V_3 , V_37 ) ) ;
F_12 ( V_3 -> V_12 , L_19 ,
F_4 ( V_3 , V_38 ) ,
F_4 ( V_3 , V_39 ) ) ;
F_12 ( V_3 -> V_12 , L_20 ,
F_4 ( V_3 , V_40 ) ,
F_4 ( V_3 , V_41 ) ) ;
F_12 ( V_3 -> V_12 , L_21 ,
F_4 ( V_3 , V_42 ) ) ;
F_12 ( V_3 -> V_12 , L_22 ,
F_4 ( V_3 , V_43 ) ) ;
F_12 ( V_3 -> V_12 , L_23 ,
F_4 ( V_3 , V_44 ) ) ;
F_12 ( V_3 -> V_12 , L_24 ,
F_4 ( V_3 , V_45 ) ) ;
F_12 ( V_3 -> V_12 , L_25 ,
F_4 ( V_3 , V_46 ) ,
F_4 ( V_3 , V_47 ) ) ;
F_12 ( V_3 -> V_12 , L_26 ,
F_4 ( V_3 , V_48 ) ) ;
F_12 ( V_3 -> V_12 , L_27 ,
F_4 ( V_3 , V_49 ) ) ;
F_12 ( V_3 -> V_12 , L_28 ,
F_4 ( V_3 , V_50 ) ) ;
F_12 ( V_3 -> V_12 , L_29 ,
F_4 ( V_3 , V_51 ) ) ;
F_12 ( V_3 -> V_12 , L_30 ,
F_4 ( V_3 , V_52 ) ,
F_4 ( V_3 , V_53 ) ) ;
F_12 ( V_3 -> V_12 , L_31 ,
F_4 ( V_3 , V_54 ) ) ;
F_12 ( V_3 -> V_12 , L_32 ,
F_4 ( V_3 , V_55 ) ) ;
F_12 ( V_3 -> V_12 , L_33 ,
( F_4 ( V_3 , V_56 ) & 1 ) ? 3 : 4 ) ;
F_12 ( V_3 -> V_12 , L_34 ,
F_4 ( V_3 , V_57 ) ,
F_4 ( V_3 , V_58 ) ) ;
F_12 ( V_3 -> V_12 , L_35 ,
F_4 ( V_3 , V_59 ) ,
F_4 ( V_3 , V_60 ) ) ;
F_12 ( V_3 -> V_12 , L_36 ,
F_4 ( V_3 , V_61 ) ,
F_4 ( V_3 , V_62 ) ) ;
F_12 ( V_3 -> V_12 , L_37 ,
F_4 ( V_3 , V_63 ) ) ;
F_12 ( V_3 -> V_12 , L_38 ,
F_4 ( V_3 , V_64 ) ) ;
F_12 ( V_3 -> V_12 , L_39 ,
F_4 ( V_3 , V_65 ) ,
F_4 ( V_3 , V_66 ) ,
F_4 ( V_3 , V_67 ) ,
F_4 ( V_3 , V_68 ) ,
F_4 ( V_3 , V_69 ) ) ;
F_11 ( V_3 , L_40 , V_70 ,
V_71 , 8 ) ;
F_11 ( V_3 , L_41 , V_72 ,
V_73 , 8 ) ;
F_12 ( V_3 -> V_12 , L_42 ,
F_4 ( V_3 , V_74 ) ) ;
F_12 ( V_3 -> V_12 , L_43 ,
F_4 ( V_3 , V_75 ) ) ;
F_12 ( V_3 -> V_12 , L_44 ,
F_4 ( V_3 , V_76 ) ) ;
F_12 ( V_3 -> V_12 , L_45 ,
F_4 ( V_3 , V_77 ) ) ;
F_12 ( V_3 -> V_12 , L_46 ,
F_4 ( V_3 , V_78 ) ) ;
F_12 ( V_3 -> V_12 , L_47 ,
F_4 ( V_3 , V_79 ) ) ;
F_12 ( V_3 -> V_12 , L_48 ,
F_4 ( V_3 , V_80 ) ) ;
F_12 ( V_3 -> V_12 , L_49 ,
F_4 ( V_3 , V_81 ) ) ;
F_12 ( V_3 -> V_12 , L_50 ,
F_4 ( V_3 , V_82 ) ) ;
F_12 ( V_3 -> V_12 , L_51 ,
F_4 ( V_3 , V_83 ) ,
F_4 ( V_3 , V_84 ) ) ;
F_12 ( V_3 -> V_12 , L_52 ,
F_4 ( V_3 , V_85 ) ) ;
F_12 ( V_3 -> V_12 , L_53 ,
F_4 ( V_3 , V_86 ) ) ;
F_12 ( V_3 -> V_12 , L_54 ,
F_4 ( V_3 , V_87 ) ) ;
F_11 ( V_3 , L_55 , V_88 ,
V_89 , 8 ) ;
F_11 ( V_3 , L_56 , V_90 ,
V_91 , 8 ) ;
F_11 ( V_3 , L_57 , V_92 ,
V_93 , 8 ) ;
F_11 ( V_3 , L_58 , V_94 ,
V_95 , 10 ) ;
F_11 ( V_3 , L_59 , V_96 ,
V_97 , 8 ) ;
return 0 ;
}
static void F_14 ( struct V_2 * V_3 )
{
int V_98 = 0 ;
struct V_1 * V_99 = F_1 ( V_3 ) ;
int V_100 = 0 ;
int V_101 ;
if ( ( V_99 -> V_102 == 0x5150 && V_99 -> V_103 == 0x0400 ) ||
( V_99 -> V_102 == 0x5151 && V_99 -> V_103 == 0x0100 ) ) {
if ( ! V_99 -> V_104 )
V_100 = 8 ;
}
switch ( V_99 -> V_100 ) {
case V_105 :
V_100 |= 2 ;
case V_106 :
break;
case V_107 :
default:
V_100 |= 1 ;
break;
}
F_8 ( V_3 -> V_12 , 1 , V_13 , L_60 ,
V_99 -> V_100 , V_99 -> V_108 ,
V_100 , V_98 ) ;
F_9 ( V_3 , V_25 , V_98 ) ;
F_9 ( V_3 , V_23 , V_100 ) ;
V_101 = F_4 ( V_3 , V_26 ) ;
if ( V_101 < 0 ) {
F_7 ( V_3 -> V_12 , L_61 , V_109 , V_101 ) ;
return;
}
if ( V_99 -> V_100 == V_107 )
V_101 = ( V_101 & ~ V_110 ) | V_111 ;
else
V_101 = ( V_101 & ~ V_111 ) | V_110 ;
F_9 ( V_3 , V_26 , V_101 ) ;
}
static int F_15 ( struct V_2 * V_3 ,
const struct V_112 * V_113 )
{
while ( V_113 -> V_114 != 0xff ) {
F_9 ( V_3 , V_113 -> V_114 , V_113 -> V_14 ) ;
V_113 ++ ;
}
return 0 ;
}
static int F_16 ( struct V_2 * V_3 ,
const struct V_115 * V_113 )
{
unsigned int V_20 ;
F_9 ( V_3 , V_86 , 0 ) ;
for ( V_20 = V_96 ; V_20 <= V_97 ; V_20 ++ )
F_9 ( V_3 , V_20 , 0xff ) ;
while ( V_113 -> V_114 != ( V_116 ) - 1 ) {
F_9 ( V_3 , V_117 , V_113 -> V_114 >> 8 ) ;
F_9 ( V_3 , V_118 , V_113 -> V_114 ) ;
for ( V_20 = 0 ; V_20 < 16 ; V_20 ++ )
F_9 ( V_3 , V_119 , V_113 -> V_120 [ V_20 ] ) ;
V_113 ++ ;
}
return 0 ;
}
static int F_17 ( struct V_2 * V_3 ,
struct V_121 * V_122 )
{
const struct V_115 * V_113 = V_123 ;
int line ;
F_8 ( V_3 -> V_12 , 1 , V_13 , L_62 ) ;
memset ( V_122 , 0 , sizeof *V_122 ) ;
while ( V_113 -> V_114 != ( V_116 ) - 1 ) {
for ( line = V_113 -> type . V_124 ; line <= V_113 -> type . V_125 ; line ++ ) {
V_122 -> V_126 [ 0 ] [ line ] |= V_113 -> type . V_127 ;
}
V_122 -> V_128 |= V_113 -> type . V_127 ;
V_113 ++ ;
}
return 0 ;
}
static int F_18 ( struct V_2 * V_3 ,
const struct V_115 * V_113 ,
unsigned int type , T_1 V_129 , int line ,
const int V_130 )
{
struct V_1 * V_99 = F_1 ( V_3 ) ;
T_2 V_131 = V_99 -> V_132 ;
T_1 V_114 ;
int V_133 = 0 ;
if ( V_131 == V_134 ) {
F_7 ( V_3 -> V_12 , L_63 ) ;
return 0 ;
} else if ( V_131 & V_135 ) {
line += 3 ;
}
if ( line < 6 || line > 27 )
return 0 ;
while ( V_113 -> V_114 != ( V_116 ) - 1 ) {
if ( ( type & V_113 -> type . V_127 ) &&
( line >= V_113 -> type . V_124 ) &&
( line <= V_113 -> type . V_125 ) ) {
type = V_113 -> type . V_127 ;
break;
}
V_113 ++ ;
V_133 ++ ;
}
if ( V_113 -> V_114 == ( V_116 ) - 1 )
return 0 ;
type = V_133 | ( V_129 & 0xf0 ) ;
V_114 = ( ( line - 6 ) << 1 ) + V_96 ;
if ( V_130 & 1 ) {
F_9 ( V_3 , V_114 , type ) ;
}
if ( V_130 & 2 ) {
F_9 ( V_3 , V_114 + 1 , type ) ;
}
return type ;
}
static int F_19 ( struct V_2 * V_3 ,
const struct V_115 * V_113 , int line )
{
struct V_1 * V_99 = F_1 ( V_3 ) ;
T_2 V_131 = V_99 -> V_132 ;
T_1 V_114 ;
int V_133 , type = 0 ;
int V_20 , V_136 = 0 ;
if ( V_131 == V_134 ) {
F_7 ( V_3 -> V_12 , L_63 ) ;
return 0 ;
} else if ( V_131 & V_135 ) {
line += 3 ;
}
if ( line < 6 || line > 27 )
return 0 ;
V_114 = ( ( line - 6 ) << 1 ) + V_96 ;
for ( V_20 = 0 ; V_20 <= 1 ; V_20 ++ ) {
V_136 = F_4 ( V_3 , V_114 + V_20 ) ;
if ( V_136 < 0 ) {
F_7 ( V_3 -> V_12 , L_61 ,
V_109 , V_136 ) ;
return 0 ;
}
V_133 = V_136 & 0x0f ;
if ( V_133 < 0x0f )
type |= V_113 [ V_133 ] . type . V_127 ;
}
return type ;
}
static int F_20 ( struct V_2 * V_3 , T_2 V_131 )
{
struct V_1 * V_99 = F_1 ( V_3 ) ;
int V_137 = 0 ;
V_99 -> V_132 = V_131 ;
if ( V_131 == V_138 ) {
V_137 = V_139 ;
} else if ( V_131 == V_140 ) {
V_137 = V_141 ;
} else if ( V_131 == V_142 || V_131 == V_143 ) {
V_137 = V_144 ;
} else {
if ( V_131 & V_145 )
V_137 = V_146 ;
else if ( V_131 & V_147 )
V_137 = V_148 ;
else if ( V_131 & V_149 )
V_137 = V_150 ;
}
F_8 ( V_3 -> V_12 , 1 , V_13 , L_64 , V_137 ) ;
F_9 ( V_3 , V_51 , V_137 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 , T_2 V_131 )
{
struct V_1 * V_99 = F_1 ( V_3 ) ;
if ( V_99 -> V_132 == V_131 )
return 0 ;
if ( V_131 & V_151 )
V_99 -> V_152 . V_153 = V_154 ;
else
V_99 -> V_152 . V_153 = V_155 ;
return F_20 ( V_3 , V_131 ) ;
}
static int F_22 ( struct V_2 * V_3 , T_3 V_101 )
{
struct V_1 * V_99 = F_1 ( V_3 ) ;
F_15 ( V_3 , V_156 ) ;
F_16 ( V_3 , V_123 ) ;
F_14 ( V_3 ) ;
F_15 ( V_3 , V_157 ) ;
F_23 ( & V_99 -> V_7 ) ;
F_20 ( V_3 , V_99 -> V_132 ) ;
if ( V_99 -> V_158 == V_159 )
F_9 ( V_3 , V_36 , 0x40 ) ;
return 0 ;
}
static int F_24 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_99 = F_1 ( V_3 ) ;
switch ( V_5 -> V_160 ) {
case V_161 :
F_9 ( V_3 , V_32 , V_5 -> V_101 ) ;
return 0 ;
case V_162 :
F_9 ( V_3 , V_35 , V_5 -> V_101 ) ;
return 0 ;
case V_163 :
F_9 ( V_3 , V_33 , V_5 -> V_101 ) ;
return 0 ;
case V_164 :
F_9 ( V_3 , V_34 , V_5 -> V_101 ) ;
break;
case V_165 :
V_99 -> V_104 = V_5 -> V_101 ? false : true ;
F_14 ( V_3 ) ;
return 0 ;
}
return - V_166 ;
}
static T_2 F_25 ( struct V_2 * V_3 )
{
int V_101 = F_4 ( V_3 , V_69 ) ;
switch ( V_101 & 0x0F ) {
case 0x01 :
return V_145 ;
case 0x03 :
return V_147 ;
case 0x05 :
return V_140 ;
case 0x07 :
return V_142 | V_143 ;
case 0x09 :
return V_138 ;
case 0xb :
return V_149 ;
default:
return V_167 ;
}
}
static int F_26 ( struct V_2 * V_3 ,
struct V_168 * V_169 ,
struct V_170 * V_171 )
{
struct V_172 * V_173 ;
struct V_1 * V_99 = F_1 ( V_3 ) ;
if ( ! V_171 || V_171 -> V_174 )
return - V_166 ;
V_173 = & V_171 -> V_171 ;
V_173 -> V_175 = V_99 -> V_152 . V_175 ;
V_173 -> V_153 = V_99 -> V_152 . V_153 / 2 ;
V_173 -> V_176 = V_177 ;
V_173 -> V_178 = V_179 ;
V_173 -> V_180 = V_181 ;
F_8 ( V_3 -> V_12 , 1 , V_13 , L_65 , V_173 -> V_175 ,
V_173 -> V_153 ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 ,
struct V_168 * V_169 ,
struct V_182 * V_183 )
{
struct V_1 * V_99 = F_1 ( V_3 ) ;
struct V_184 V_152 = V_183 -> V_185 ;
T_2 V_131 ;
int V_186 ;
if ( V_183 -> V_187 != V_188 ||
V_183 -> V_189 != V_190 )
return - V_166 ;
F_8 ( V_3 -> V_12 , 1 , V_13 , L_66 ,
V_109 , V_152 . V_191 , V_152 . V_192 , V_152 . V_175 , V_152 . V_153 ) ;
V_152 . V_191 = F_28 ( V_152 . V_191 , 0 , V_193 ) ;
V_152 . V_175 = F_29 (unsigned int, rect.width,
TVP5150_H_MAX - TVP5150_MAX_CROP_LEFT - rect.left,
TVP5150_H_MAX - rect.left) ;
V_152 . V_192 = F_28 ( V_152 . V_192 , 0 , V_194 ) ;
if ( V_99 -> V_132 == V_134 )
V_131 = F_25 ( V_3 ) ;
else
V_131 = V_99 -> V_132 ;
if ( V_131 & V_151 )
V_186 = V_154 ;
else
V_186 = V_155 ;
V_152 . V_153 = F_29 (unsigned int, rect.height,
hmax - TVP5150_MAX_CROP_TOP - rect.top,
hmax - rect.top) ;
F_9 ( V_3 , V_44 , V_152 . V_192 ) ;
F_9 ( V_3 , V_45 ,
V_152 . V_192 + V_152 . V_153 - V_186 ) ;
F_9 ( V_3 , V_38 ,
V_152 . V_191 >> V_195 ) ;
F_9 ( V_3 , V_39 ,
V_152 . V_191 | ( 1 << V_195 ) ) ;
F_9 ( V_3 , V_40 ,
( V_152 . V_191 + V_152 . V_175 - V_193 ) >>
V_195 ) ;
F_9 ( V_3 , V_41 ,
V_152 . V_191 + V_152 . V_175 - V_193 ) ;
V_99 -> V_152 = V_152 ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 ,
struct V_168 * V_169 ,
struct V_182 * V_183 )
{
struct V_1 * V_99 = F_2 ( V_3 , struct V_1 , V_3 ) ;
T_2 V_131 ;
if ( V_183 -> V_187 != V_188 )
return - V_166 ;
switch ( V_183 -> V_189 ) {
case V_196 :
case V_197 :
V_183 -> V_185 . V_191 = 0 ;
V_183 -> V_185 . V_192 = 0 ;
V_183 -> V_185 . V_175 = V_198 ;
if ( V_99 -> V_132 == V_134 )
V_131 = F_25 ( V_3 ) ;
else
V_131 = V_99 -> V_132 ;
if ( V_131 & V_151 )
V_183 -> V_185 . V_153 = V_154 ;
else
V_183 -> V_185 . V_153 = V_155 ;
return 0 ;
case V_190 :
V_183 -> V_185 = V_99 -> V_152 ;
return 0 ;
default:
return - V_166 ;
}
}
static int F_31 ( struct V_2 * V_3 ,
struct V_199 * V_169 )
{
struct V_1 * V_99 = F_1 ( V_3 ) ;
V_169 -> type = V_99 -> V_158 ;
V_169 -> V_129 = V_200 | V_201
| V_202 | V_203 ;
return 0 ;
}
static int F_32 ( struct V_2 * V_3 ,
struct V_168 * V_169 ,
struct V_204 * V_176 )
{
if ( V_176 -> V_174 || V_176 -> V_205 )
return - V_166 ;
V_176 -> V_176 = V_177 ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 ,
struct V_168 * V_169 ,
struct V_206 * V_207 )
{
struct V_1 * V_99 = F_1 ( V_3 ) ;
if ( V_207 -> V_205 >= 8 || V_207 -> V_176 != V_177 )
return - V_166 ;
V_207 -> V_176 = V_177 ;
V_207 -> V_208 = V_99 -> V_152 . V_175 ;
V_207 -> V_209 = V_99 -> V_152 . V_175 ;
V_207 -> V_210 = V_99 -> V_152 . V_153 / 2 ;
V_207 -> V_211 = V_99 -> V_152 . V_153 / 2 ;
return 0 ;
}
static int F_34 ( struct V_212 * V_213 ,
const struct V_214 * V_215 ,
const struct V_214 * V_216 , T_3 V_129 )
{
struct V_2 * V_3 = F_35 ( V_213 ) ;
struct V_1 * V_99 = F_1 ( V_3 ) ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_217 ; V_20 ++ ) {
if ( V_216 -> V_213 == & V_99 -> V_218 [ V_20 ] )
break;
}
if ( V_20 == V_217 )
return 0 ;
V_99 -> V_100 = V_20 ;
F_14 ( V_3 ) ;
return 0 ;
}
static int F_36 ( struct V_2 * V_3 , int V_104 )
{
struct V_1 * V_99 = F_1 ( V_3 ) ;
int V_101 ;
V_101 = F_4 ( V_3 , V_26 ) ;
if ( V_101 < 0 )
return V_101 ;
V_101 &= ~ ( V_219 | V_220 |
V_221 ) ;
if ( V_104 ) {
V_101 |= V_219 | V_221 ;
if ( V_99 -> V_158 == V_159 )
V_101 |= V_220 ;
}
F_9 ( V_3 , V_26 , V_101 ) ;
return 0 ;
}
static int F_37 ( struct V_2 * V_3 ,
T_3 V_100 , T_3 V_108 , T_3 V_222 )
{
struct V_1 * V_99 = F_1 ( V_3 ) ;
V_99 -> V_100 = V_100 ;
V_99 -> V_108 = V_108 ;
if ( V_108 == V_223 )
V_99 -> V_104 = false ;
else
V_99 -> V_104 = true ;
F_14 ( V_3 ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_3 , struct V_224 * V_137 )
{
if ( V_137 -> V_225 == V_226 )
F_9 ( V_3 , V_29 , 0x70 ) ;
if ( V_137 -> V_227 [ 0 ] == 18 && V_137 -> V_227 [ 1 ] == 18 ) {
F_9 ( V_3 , V_44 , 0x00 ) ;
F_9 ( V_3 , V_45 , 0x01 ) ;
}
return 0 ;
}
static int F_39 ( struct V_2 * V_3 , struct V_228 * V_229 )
{
int V_20 ;
if ( V_229 -> V_128 != 0 ) {
for ( V_20 = 0 ; V_20 <= 23 ; V_20 ++ ) {
V_229 -> V_126 [ 1 ] [ V_20 ] = 0 ;
V_229 -> V_126 [ 0 ] [ V_20 ] =
F_18 ( V_3 , V_123 ,
V_229 -> V_126 [ 0 ] [ V_20 ] , 0xf0 , V_20 , 3 ) ;
}
F_9 ( V_3 , V_85 , 1 ) ;
} else {
F_9 ( V_3 , V_85 , 0 ) ;
F_9 ( V_3 , V_86 , 0 ) ;
for ( V_20 = V_96 ; V_20 <= V_97 ; V_20 ++ )
F_9 ( V_3 , V_20 , 0xff ) ;
}
return 0 ;
}
static int F_40 ( struct V_2 * V_3 , struct V_228 * V_229 )
{
int V_20 , V_230 = 0 ;
memset ( V_229 -> V_126 , 0 , sizeof( V_229 -> V_126 ) ) ;
for ( V_20 = 0 ; V_20 <= 23 ; V_20 ++ ) {
V_229 -> V_126 [ 0 ] [ V_20 ] =
F_19 ( V_3 , V_123 , V_20 ) ;
V_230 |= V_229 -> V_126 [ 0 ] [ V_20 ] ;
}
V_229 -> V_128 = V_230 ;
return 0 ;
}
static int F_41 ( struct V_2 * V_3 , struct V_231 * V_114 )
{
int V_232 ;
V_232 = F_4 ( V_3 , V_114 -> V_114 & 0xff ) ;
if ( V_232 < 0 ) {
F_7 ( V_3 -> V_12 , L_61 , V_109 , V_232 ) ;
return V_232 ;
}
V_114 -> V_101 = V_232 ;
V_114 -> V_233 = 1 ;
return 0 ;
}
static int F_42 ( struct V_2 * V_3 , const struct V_231 * V_114 )
{
return F_9 ( V_3 , V_114 -> V_114 & 0xff , V_114 -> V_101 & 0xff ) ;
}
static int F_43 ( struct V_2 * V_3 , struct V_234 * V_235 )
{
int V_236 = F_4 ( V_3 , 0x88 ) ;
V_235 -> signal = ( ( V_236 & 0x04 ) && ( V_236 & 0x02 ) ) ? 0xffff : 0x0 ;
return 0 ;
}
static int F_44 ( struct V_2 * V_3 )
{
#ifdef F_45
struct V_1 * V_99 = F_1 ( V_3 ) ;
int V_136 = 0 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_217 ; V_20 ++ ) {
struct V_212 * V_100 = & V_99 -> V_218 [ V_20 ] ;
struct V_214 * V_174 = & V_99 -> V_237 [ V_20 ] ;
if ( ! V_100 -> V_238 )
continue;
V_99 -> V_237 [ V_20 ] . V_129 = V_239 ;
V_136 = F_46 ( V_100 , 1 , V_174 ) ;
if ( V_136 < 0 )
return V_136 ;
V_136 = F_47 ( V_3 -> V_240 -> V_241 , V_100 ) ;
if ( V_136 < 0 )
return V_136 ;
V_136 = F_48 ( V_100 , 0 , & V_3 -> V_213 ,
V_242 , 0 ) ;
if ( V_136 < 0 ) {
F_49 ( V_100 ) ;
return V_136 ;
}
}
#endif
return 0 ;
}
static int F_50 ( struct V_1 * V_243 )
{
struct V_2 * V_3 = & V_243 -> V_3 ;
struct V_9 * V_10 = F_5 ( V_3 ) ;
unsigned int V_20 ;
T_1 V_113 [ 4 ] ;
int V_232 ;
for ( V_20 = 0 ; V_20 < 4 ; V_20 ++ ) {
V_232 = F_4 ( V_3 , V_57 + V_20 ) ;
if ( V_232 < 0 )
return V_232 ;
V_113 [ V_20 ] = V_232 ;
}
V_243 -> V_102 = ( V_113 [ 0 ] << 8 ) | V_113 [ 1 ] ;
V_243 -> V_103 = ( V_113 [ 2 ] << 8 ) | V_113 [ 3 ] ;
F_51 ( V_3 -> V_12 , L_67 ,
V_243 -> V_102 , V_113 [ 2 ] , V_113 [ 3 ] , V_10 -> V_8 << 1 ,
V_10 -> V_244 -> V_238 ) ;
if ( V_243 -> V_102 == 0x5150 && V_243 -> V_103 == 0x0321 ) {
F_51 ( V_3 -> V_12 , L_68 ) ;
} else if ( V_243 -> V_102 == 0x5150 && V_243 -> V_103 == 0x0400 ) {
F_51 ( V_3 -> V_12 , L_69 ) ;
F_9 ( V_3 , V_56 , 0 ) ;
} else if ( V_243 -> V_102 == 0x5151 && V_243 -> V_103 == 0x0100 ) {
F_51 ( V_3 -> V_12 , L_70 ) ;
} else {
F_51 ( V_3 -> V_12 , L_71 ,
V_243 -> V_102 ) ;
}
return 0 ;
}
static int F_52 ( struct V_9 * V_10 )
{
struct V_245 * V_246 ;
struct V_245 * V_247 ;
V_246 = F_53 ( & V_10 -> V_12 , L_72 , V_248 ) ;
if ( F_54 ( V_246 ) )
return F_55 ( V_246 ) ;
if ( V_246 ) {
F_56 ( V_246 , 0 ) ;
F_57 ( 20 ) ;
}
V_247 = F_53 ( & V_10 -> V_12 , L_73 , V_248 ) ;
if ( F_54 ( V_247 ) )
return F_55 ( V_247 ) ;
if ( V_247 ) {
F_58 ( 500 ) ;
F_56 ( V_247 , 0 ) ;
F_59 ( 200 , 250 ) ;
}
return 0 ;
}
static int F_60 ( struct V_1 * V_99 , struct V_249 * V_250 )
{
struct V_251 V_252 ;
struct V_249 * V_253 ;
#ifdef F_45
struct V_249 * V_254 , * V_255 ;
struct V_212 * V_100 ;
const char * V_238 ;
T_3 V_256 ;
#endif
unsigned int V_129 ;
int V_136 = 0 ;
V_253 = F_61 ( V_250 , NULL ) ;
if ( ! V_253 )
return - V_166 ;
V_136 = F_62 ( V_253 , & V_252 ) ;
if ( V_136 )
goto V_257;
V_129 = V_252 . V_258 . V_259 . V_129 ;
if ( V_252 . V_260 == V_159 &&
! ( V_129 & V_261 &&
V_129 & V_262 &&
V_129 & V_202 ) ) {
V_136 = - V_166 ;
goto V_257;
}
V_99 -> V_158 = V_252 . V_260 ;
#ifdef F_45
V_254 = F_63 ( V_250 , L_74 ) ;
if ( ! V_254 )
goto V_257;
F_64 (connectors, child) {
V_136 = F_65 ( V_255 , L_75 , & V_256 ) ;
if ( V_136 ) {
F_7 ( V_99 -> V_3 . V_12 ,
L_76 ,
V_255 -> V_238 ) ;
goto V_263;
}
if ( V_256 >= V_217 ) {
V_136 = - V_166 ;
goto V_263;
}
V_100 = & V_99 -> V_218 [ V_256 ] ;
if ( V_100 -> V_238 ) {
F_7 ( V_99 -> V_3 . V_12 ,
L_77 ,
V_100 -> V_238 ) ;
V_136 = - V_166 ;
goto V_263;
}
switch ( V_256 ) {
case V_106 :
case V_105 :
V_100 -> V_264 = V_265 ;
break;
case V_107 :
V_100 -> V_264 = V_266 ;
break;
}
V_100 -> V_129 = V_267 ;
V_136 = F_66 ( V_255 , L_78 , & V_238 ) ;
if ( V_136 < 0 ) {
F_7 ( V_99 -> V_3 . V_12 ,
L_79 ,
V_255 -> V_238 ) ;
goto V_263;
}
V_100 -> V_238 = V_238 ;
}
V_263:
F_67 ( V_254 ) ;
#endif
V_257:
F_67 ( V_253 ) ;
return V_136 ;
}
static int F_68 ( struct V_9 * V_10 ,
const struct V_268 * V_160 )
{
struct V_1 * V_243 ;
struct V_2 * V_3 ;
struct V_249 * V_250 = V_10 -> V_12 . V_269 ;
int V_232 ;
if ( ! F_69 ( V_10 -> V_244 ,
V_270 | V_271 ) )
return - V_272 ;
V_232 = F_52 ( V_10 ) ;
if ( V_232 )
return V_232 ;
V_243 = F_70 ( & V_10 -> V_12 , sizeof( * V_243 ) , V_273 ) ;
if ( ! V_243 )
return - V_274 ;
V_3 = & V_243 -> V_3 ;
if ( F_71 ( V_275 ) && V_250 ) {
V_232 = F_60 ( V_243 , V_250 ) ;
if ( V_232 ) {
F_7 ( V_3 -> V_12 , L_80 , V_232 ) ;
return V_232 ;
}
} else {
V_243 -> V_158 = V_276 ;
}
F_72 ( V_3 , V_10 , & V_277 ) ;
V_3 -> V_278 = & V_279 ;
V_3 -> V_129 |= V_280 ;
#if F_73 ( F_45 )
V_243 -> V_281 [ V_242 ] . V_129 = V_282 ;
V_243 -> V_281 [ V_283 ] . V_129 = V_239 ;
V_243 -> V_281 [ V_284 ] . V_129 = V_239 ;
V_3 -> V_213 . V_264 = V_285 ;
V_232 = F_46 ( & V_3 -> V_213 , V_286 , V_243 -> V_281 ) ;
if ( V_232 < 0 )
return V_232 ;
V_3 -> V_213 . V_287 = & V_288 ;
#endif
V_232 = F_50 ( V_243 ) ;
if ( V_232 < 0 )
return V_232 ;
V_243 -> V_132 = V_134 ;
V_243 -> V_100 = V_105 ;
V_243 -> V_104 = true ;
F_74 ( & V_243 -> V_7 , 5 ) ;
F_75 ( & V_243 -> V_7 , & V_289 ,
V_161 , 0 , 255 , 1 , 128 ) ;
F_75 ( & V_243 -> V_7 , & V_289 ,
V_162 , 0 , 255 , 1 , 128 ) ;
F_75 ( & V_243 -> V_7 , & V_289 ,
V_163 , 0 , 255 , 1 , 128 ) ;
F_75 ( & V_243 -> V_7 , & V_289 ,
V_164 , - 128 , 127 , 1 , 0 ) ;
F_75 ( & V_243 -> V_7 , & V_289 ,
V_290 , 27000000 ,
27000000 , 1 , 27000000 ) ;
F_76 ( & V_243 -> V_7 , & V_289 ,
V_165 ,
F_77 ( V_291 ) ,
0 , 0 , V_291 ) ;
V_3 -> V_292 = & V_243 -> V_7 ;
if ( V_243 -> V_7 . error ) {
V_232 = V_243 -> V_7 . error ;
goto V_257;
}
V_243 -> V_152 . V_192 = 0 ;
if ( F_25 ( V_3 ) & V_151 )
V_243 -> V_152 . V_153 = V_154 ;
else
V_243 -> V_152 . V_153 = V_155 ;
V_243 -> V_152 . V_191 = 0 ;
V_243 -> V_152 . V_175 = V_198 ;
F_22 ( V_3 , 0 ) ;
V_232 = F_78 ( V_3 ) ;
if ( V_232 < 0 )
goto V_257;
if ( V_13 > 1 )
F_13 ( V_3 ) ;
return 0 ;
V_257:
F_79 ( & V_243 -> V_7 ) ;
return V_232 ;
}
static int F_80 ( struct V_9 * V_10 )
{
struct V_2 * V_3 = F_81 ( V_10 ) ;
struct V_1 * V_99 = F_1 ( V_3 ) ;
F_8 ( V_3 -> V_12 , 1 , V_13 ,
L_81 ,
V_10 -> V_8 << 1 ) ;
F_82 ( V_3 ) ;
F_79 ( & V_99 -> V_7 ) ;
return 0 ;
}
