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
V_11 [ 0 ] = V_8 ;
if ( 1 != ( V_12 = F_6 ( V_10 , V_11 , 1 ) ) )
F_7 ( 0 , V_13 , V_3 , L_1 , V_12 ) ;
F_8 ( 10 ) ;
if ( 1 != ( V_12 = F_9 ( V_10 , V_11 , 1 ) ) )
F_7 ( 0 , V_13 , V_3 , L_1 , V_12 ) ;
F_7 ( 2 , V_13 , V_3 , L_2 , V_8 , V_11 [ 0 ] ) ;
return ( V_11 [ 0 ] ) ;
}
static inline void F_10 ( struct V_2 * V_3 , unsigned char V_8 ,
unsigned char V_14 )
{
struct V_9 * V_10 = F_5 ( V_3 ) ;
unsigned char V_11 [ 2 ] ;
int V_12 ;
V_11 [ 0 ] = V_8 ;
V_11 [ 1 ] = V_14 ;
F_7 ( 2 , V_13 , V_3 , L_3 , V_11 [ 0 ] , V_11 [ 1 ] ) ;
if ( 2 != ( V_12 = F_6 ( V_10 , V_11 , 2 ) ) )
F_7 ( 0 , V_13 , V_3 , L_4 , V_12 ) ;
}
static void F_11 ( struct V_2 * V_3 , char * V_15 , T_1 V_16 ,
const T_1 V_17 , int V_18 )
{
int V_19 = 0 ;
while ( V_16 != ( T_1 ) ( V_17 + 1 ) ) {
if ( ( V_19 % V_18 ) == 0 ) {
if ( V_19 > 0 )
F_12 ( L_5 ) ;
F_12 ( L_6 , V_15 , V_16 ) ;
}
F_12 ( L_7 , F_4 ( V_3 , V_16 ) ) ;
V_16 ++ ;
V_19 ++ ;
}
F_12 ( L_5 ) ;
}
static int F_13 ( struct V_2 * V_3 )
{
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
F_4 ( V_3 , V_25 ) ) ;
F_12 ( L_14 ,
F_4 ( V_3 , V_26 ) ,
F_4 ( V_3 , V_27 ) ,
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
F_4 ( V_3 , V_34 ) ) ;
F_12 ( L_21 ,
F_4 ( V_3 , V_35 ) ,
F_4 ( V_3 , V_36 ) ) ;
F_12 ( L_22 ,
F_4 ( V_3 , V_37 ) ,
F_4 ( V_3 , V_38 ) ) ;
F_12 ( L_23 ,
F_4 ( V_3 , V_39 ) ) ;
F_12 ( L_24 ,
F_4 ( V_3 , V_40 ) ) ;
F_12 ( L_25 ,
F_4 ( V_3 , V_41 ) ) ;
F_12 ( L_26 ,
F_4 ( V_3 , V_42 ) ) ;
F_12 ( L_27 ,
F_4 ( V_3 , V_43 ) ,
F_4 ( V_3 , V_44 ) ) ;
F_12 ( L_28 ,
F_4 ( V_3 , V_45 ) ) ;
F_12 ( L_29 ,
F_4 ( V_3 , V_46 ) ) ;
F_12 ( L_30 ,
F_4 ( V_3 , V_47 ) ) ;
F_12 ( L_31 ,
F_4 ( V_3 , V_48 ) ) ;
F_12 ( L_32 ,
F_4 ( V_3 , V_49 ) ,
F_4 ( V_3 , V_50 ) ) ;
F_12 ( L_33 ,
F_4 ( V_3 , V_51 ) ) ;
F_12 ( L_34 ,
F_4 ( V_3 , V_52 ) ) ;
F_12 ( L_35 ,
( F_4 ( V_3 , V_53 ) & 1 ) ? 3 : 4 ) ;
F_12 ( L_36 ,
F_4 ( V_3 , V_54 ) ,
F_4 ( V_3 , V_55 ) ) ;
F_12 ( L_37 ,
F_4 ( V_3 , V_56 ) ,
F_4 ( V_3 , V_57 ) ) ;
F_12 ( L_38 ,
F_4 ( V_3 , V_58 ) ,
F_4 ( V_3 , V_59 ) ) ;
F_12 ( L_39 ,
F_4 ( V_3 , V_60 ) ) ;
F_12 ( L_40 ,
F_4 ( V_3 , V_61 ) ) ;
F_12 ( L_41 ,
F_4 ( V_3 , V_62 ) ,
F_4 ( V_3 , V_63 ) ,
F_4 ( V_3 , V_64 ) ,
F_4 ( V_3 , V_65 ) ,
F_4 ( V_3 , V_66 ) ) ;
F_11 ( V_3 , L_42 , V_67 ,
V_68 , 8 ) ;
F_11 ( V_3 , L_43 , V_69 ,
V_70 , 8 ) ;
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
F_4 ( V_3 , V_79 ) ) ;
F_12 ( L_53 ,
F_4 ( V_3 , V_80 ) ,
F_4 ( V_3 , V_81 ) ) ;
F_12 ( L_54 ,
F_4 ( V_3 , V_82 ) ) ;
F_12 ( L_55 ,
F_4 ( V_3 , V_83 ) ) ;
F_12 ( L_56 ,
F_4 ( V_3 , V_84 ) ) ;
F_11 ( V_3 , L_57 , V_85 ,
V_86 , 8 ) ;
F_11 ( V_3 , L_58 , V_87 ,
V_88 , 8 ) ;
F_11 ( V_3 , L_59 , V_89 ,
V_90 , 8 ) ;
F_11 ( V_3 , L_60 , V_91 ,
V_92 , 10 ) ;
F_11 ( V_3 , L_61 , V_93 ,
V_94 , 8 ) ;
return 0 ;
}
static inline void F_14 ( struct V_2 * V_3 )
{
int V_95 = 0 ;
struct V_1 * V_96 = F_1 ( V_3 ) ;
int V_97 = 0 ;
unsigned char V_98 ;
if ( ( V_96 -> V_99 & V_100 ) || ! V_96 -> V_101 )
V_97 = 8 ;
switch ( V_96 -> V_97 ) {
case V_102 :
V_97 |= 2 ;
case V_103 :
break;
case V_104 :
default:
V_97 |= 1 ;
break;
}
F_7 ( 1 , V_13 , V_3 , L_62
L_63 ,
V_96 -> V_97 , V_96 -> V_99 ,
V_97 , V_95 ) ;
F_10 ( V_3 , V_22 , V_95 ) ;
F_10 ( V_3 , V_20 , V_97 ) ;
V_98 = F_4 ( V_3 , V_23 ) ;
if ( V_96 -> V_97 == V_104 )
V_98 = ( V_98 & ~ 0x40 ) | 0x10 ;
else
V_98 = ( V_98 & ~ 0x10 ) | 0x40 ;
F_10 ( V_3 , V_23 , V_98 ) ;
}
static int F_15 ( struct V_2 * V_3 ,
const struct V_105 * V_106 )
{
while ( V_106 -> V_107 != 0xff ) {
F_10 ( V_3 , V_106 -> V_107 , V_106 -> V_14 ) ;
V_106 ++ ;
}
return 0 ;
}
static int F_16 ( struct V_2 * V_3 ,
const struct V_108 * V_106 )
{
unsigned int V_19 ;
F_10 ( V_3 , V_83 , 0 ) ;
for ( V_19 = V_93 ; V_19 <= V_94 ; V_19 ++ )
F_10 ( V_3 , V_19 , 0xff ) ;
while ( V_106 -> V_107 != ( V_109 ) - 1 ) {
F_10 ( V_3 , V_110 , V_106 -> V_107 >> 8 ) ;
F_10 ( V_3 , V_111 , V_106 -> V_107 ) ;
for ( V_19 = 0 ; V_19 < 16 ; V_19 ++ )
F_10 ( V_3 , V_112 , V_106 -> V_113 [ V_19 ] ) ;
V_106 ++ ;
}
return 0 ;
}
static int F_17 ( struct V_2 * V_3 ,
struct V_114 * V_115 )
{
const struct V_108 * V_106 = V_116 ;
int line ;
F_7 ( 1 , V_13 , V_3 , L_64 ) ;
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
struct V_1 * V_96 = F_1 ( V_3 ) ;
T_2 V_124 = V_96 -> V_125 ;
T_1 V_107 ;
int V_126 = 0 ;
if ( V_124 == V_127 ) {
F_19 ( V_3 , L_65 ) ;
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
V_107 = ( ( line - 6 ) << 1 ) + V_93 ;
if ( V_123 & 1 ) {
F_10 ( V_3 , V_107 , type ) ;
}
if ( V_123 & 2 ) {
F_10 ( V_3 , V_107 + 1 , type ) ;
}
return type ;
}
static int F_20 ( struct V_2 * V_3 ,
const struct V_108 * V_106 , int line )
{
struct V_1 * V_96 = F_1 ( V_3 ) ;
T_2 V_124 = V_96 -> V_125 ;
T_1 V_107 ;
int V_126 , type = 0 ;
if ( V_124 == V_127 ) {
F_19 ( V_3 , L_65 ) ;
return 0 ;
} else if ( V_124 & V_128 ) {
line += 3 ;
}
if ( line < 6 || line > 27 )
return 0 ;
V_107 = ( ( line - 6 ) << 1 ) + V_93 ;
V_126 = F_4 ( V_3 , V_107 ) & 0x0f ;
if ( V_126 < 0x0f )
type = V_106 [ V_126 ] . type . V_120 ;
V_126 = F_4 ( V_3 , V_107 + 1 ) & 0x0f ;
if ( V_126 < 0x0f )
type |= V_106 [ V_126 ] . type . V_120 ;
return type ;
}
static int F_21 ( struct V_2 * V_3 , T_2 V_124 )
{
struct V_1 * V_96 = F_1 ( V_3 ) ;
int V_129 = 0 ;
V_96 -> V_125 = V_124 ;
if ( V_124 == V_127 ) {
V_129 = V_130 ;
} else if ( V_124 & V_131 ) {
V_129 = V_132 ;
} else if ( V_124 & V_133 ) {
V_129 = V_134 ;
} else if ( V_124 & ( V_135 | V_136 ) ) {
V_129 = V_137 ;
} else {
if ( V_124 & V_138 )
V_129 = V_139 ;
else if ( V_124 & V_140 )
V_129 = V_141 ;
else if ( V_124 & V_142 )
V_129 = V_143 ;
}
F_7 ( 1 , V_13 , V_3 , L_66 , V_129 ) ;
F_10 ( V_3 , V_48 , V_129 ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 , T_2 V_124 )
{
struct V_1 * V_96 = F_1 ( V_3 ) ;
if ( V_96 -> V_125 == V_124 )
return 0 ;
if ( V_124 & V_144 )
V_96 -> V_145 . V_146 = V_147 ;
else
V_96 -> V_145 . V_146 = V_148 ;
return F_21 ( V_3 , V_124 ) ;
}
static int F_23 ( struct V_2 * V_3 , T_3 V_98 )
{
struct V_1 * V_96 = F_1 ( V_3 ) ;
F_15 ( V_3 , V_149 ) ;
F_16 ( V_3 , V_116 ) ;
F_14 ( V_3 ) ;
F_15 ( V_3 , V_150 ) ;
F_24 ( & V_96 -> V_7 ) ;
F_21 ( V_3 , V_96 -> V_125 ) ;
return 0 ;
}
static int F_25 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
switch ( V_5 -> V_151 ) {
case V_152 :
F_10 ( V_3 , V_29 , V_5 -> V_98 ) ;
return 0 ;
case V_153 :
F_10 ( V_3 , V_32 , V_5 -> V_98 ) ;
return 0 ;
case V_154 :
F_10 ( V_3 , V_30 , V_5 -> V_98 ) ;
return 0 ;
case V_155 :
F_10 ( V_3 , V_31 , V_5 -> V_98 ) ;
return 0 ;
}
return - V_156 ;
}
static T_2 F_26 ( struct V_2 * V_3 )
{
int V_98 = F_4 ( V_3 , V_66 ) ;
switch ( V_98 & 0x0F ) {
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
static int F_27 ( struct V_2 * V_3 , unsigned V_158 ,
enum V_159 * V_160 )
{
if ( V_158 )
return - V_156 ;
* V_160 = V_161 ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 ,
struct V_162 * V_163 )
{
struct V_1 * V_96 = F_1 ( V_3 ) ;
if ( V_163 == NULL )
return - V_156 ;
F_23 ( V_3 , 0 ) ;
V_163 -> V_164 = V_96 -> V_145 . V_164 ;
V_163 -> V_146 = V_96 -> V_145 . V_146 ;
V_163 -> V_160 = V_161 ;
V_163 -> V_165 = V_166 ;
V_163 -> V_167 = V_168 ;
F_7 ( 1 , V_13 , V_3 , L_67 , V_163 -> V_164 ,
V_163 -> V_146 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 , struct V_169 * V_170 )
{
struct V_171 V_145 = V_170 -> V_10 ;
struct V_1 * V_96 = F_1 ( V_3 ) ;
T_2 V_124 ;
int V_172 ;
F_7 ( 1 , V_13 , V_3 , L_68 ,
V_173 , V_145 . V_174 , V_145 . V_175 , V_145 . V_164 , V_145 . V_146 ) ;
if ( V_170 -> type != V_176 )
return - V_156 ;
V_145 . V_174 = F_30 ( V_145 . V_174 , 0 , V_177 ) ;
V_145 . V_164 = F_30 ( V_145 . V_164 ,
V_178 - V_177 - V_145 . V_174 ,
V_178 - V_145 . V_174 ) ;
V_145 . V_175 = F_30 ( V_145 . V_175 , 0 , V_179 ) ;
if ( V_96 -> V_125 == V_127 )
V_124 = F_26 ( V_3 ) ;
else
V_124 = V_96 -> V_125 ;
if ( V_124 & V_144 )
V_172 = V_147 ;
else
V_172 = V_148 ;
V_145 . V_146 = F_30 ( V_145 . V_146 ,
V_172 - V_179 - V_145 . V_175 ,
V_172 - V_145 . V_175 ) ;
F_10 ( V_3 , V_41 , V_145 . V_175 ) ;
F_10 ( V_3 , V_42 ,
V_145 . V_175 + V_145 . V_146 - V_172 ) ;
F_10 ( V_3 , V_35 ,
V_145 . V_174 >> V_180 ) ;
F_10 ( V_3 , V_36 ,
V_145 . V_174 | ( 1 << V_180 ) ) ;
F_10 ( V_3 , V_37 ,
( V_145 . V_174 + V_145 . V_164 - V_177 ) >>
V_180 ) ;
F_10 ( V_3 , V_38 ,
V_145 . V_174 + V_145 . V_164 - V_177 ) ;
V_96 -> V_145 = V_145 ;
return 0 ;
}
static int F_31 ( struct V_2 * V_3 , struct V_169 * V_170 )
{
struct V_1 * V_96 = F_2 ( V_3 , struct V_1 , V_3 ) ;
V_170 -> V_10 = V_96 -> V_145 ;
V_170 -> type = V_176 ;
return 0 ;
}
static int F_32 ( struct V_2 * V_3 , struct V_181 * V_170 )
{
struct V_1 * V_96 = F_2 ( V_3 , struct V_1 , V_3 ) ;
T_2 V_124 ;
if ( V_170 -> type != V_176 )
return - V_156 ;
V_170 -> V_182 . V_174 = 0 ;
V_170 -> V_182 . V_175 = 0 ;
V_170 -> V_182 . V_164 = V_178 ;
if ( V_96 -> V_125 == V_127 )
V_124 = F_26 ( V_3 ) ;
else
V_124 = V_96 -> V_125 ;
if ( V_124 & V_144 )
V_170 -> V_182 . V_146 = V_147 ;
else
V_170 -> V_182 . V_146 = V_148 ;
V_170 -> V_183 = V_170 -> V_182 ;
V_170 -> V_184 . V_185 = 1 ;
V_170 -> V_184 . V_186 = 1 ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 ,
T_3 V_97 , T_3 V_99 , T_3 V_187 )
{
struct V_1 * V_96 = F_1 ( V_3 ) ;
V_96 -> V_97 = V_97 ;
V_96 -> V_99 = V_99 ;
F_14 ( V_3 ) ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 , struct V_188 * V_129 )
{
if ( V_129 -> V_189 == V_190 )
F_10 ( V_3 , V_26 , 0x70 ) ;
if ( V_129 -> V_191 [ 0 ] == 18 && V_129 -> V_191 [ 1 ] == 18 ) {
F_10 ( V_3 , V_41 , 0x00 ) ;
F_10 ( V_3 , V_42 , 0x01 ) ;
}
return 0 ;
}
static int F_35 ( struct V_2 * V_3 , struct V_192 * V_193 )
{
int V_19 ;
if ( V_193 -> V_121 != 0 ) {
for ( V_19 = 0 ; V_19 <= 23 ; V_19 ++ ) {
V_193 -> V_119 [ 1 ] [ V_19 ] = 0 ;
V_193 -> V_119 [ 0 ] [ V_19 ] =
F_18 ( V_3 , V_116 ,
V_193 -> V_119 [ 0 ] [ V_19 ] , 0xf0 , V_19 , 3 ) ;
}
F_10 ( V_3 , V_82 , 1 ) ;
} else {
F_10 ( V_3 , V_82 , 0 ) ;
F_10 ( V_3 , V_83 , 0 ) ;
for ( V_19 = V_93 ; V_19 <= V_94 ; V_19 ++ )
F_10 ( V_3 , V_19 , 0xff ) ;
}
return 0 ;
}
static int F_36 ( struct V_2 * V_3 , struct V_192 * V_193 )
{
int V_19 , V_194 = 0 ;
memset ( V_193 , 0 , sizeof( * V_193 ) ) ;
for ( V_19 = 0 ; V_19 <= 23 ; V_19 ++ ) {
V_193 -> V_119 [ 0 ] [ V_19 ] =
F_20 ( V_3 , V_116 , V_19 ) ;
V_194 |= V_193 -> V_119 [ 0 ] [ V_19 ] ;
}
V_193 -> V_121 = V_194 ;
return 0 ;
}
static int F_37 ( struct V_2 * V_3 ,
struct V_195 * V_196 )
{
int V_197 ;
struct V_9 * V_198 = F_5 ( V_3 ) ;
V_197 = F_4 ( V_3 , V_56 ) << 8 |
F_4 ( V_3 , V_57 ) ;
return F_38 ( V_198 , V_196 , V_199 ,
V_197 ) ;
}
static int F_39 ( struct V_2 * V_3 , struct V_200 * V_107 )
{
struct V_9 * V_198 = F_5 ( V_3 ) ;
if ( ! F_40 ( V_198 , & V_107 -> V_201 ) )
return - V_156 ;
if ( ! F_41 ( V_202 ) )
return - V_203 ;
V_107 -> V_98 = F_4 ( V_3 , V_107 -> V_107 & 0xff ) ;
V_107 -> V_204 = 1 ;
return 0 ;
}
static int F_42 ( struct V_2 * V_3 , struct V_200 * V_107 )
{
struct V_9 * V_198 = F_5 ( V_3 ) ;
if ( ! F_40 ( V_198 , & V_107 -> V_201 ) )
return - V_156 ;
if ( ! F_41 ( V_202 ) )
return - V_203 ;
F_10 ( V_3 , V_107 -> V_107 & 0xff , V_107 -> V_98 & 0xff ) ;
return 0 ;
}
static int F_43 ( struct V_2 * V_3 , struct V_205 * V_206 )
{
int V_207 = F_4 ( V_3 , 0x88 ) ;
V_206 -> signal = ( ( V_207 & 0x04 ) && ( V_207 & 0x02 ) ) ? 0xffff : 0x0 ;
return 0 ;
}
static int F_44 ( struct V_9 * V_10 ,
const struct V_208 * V_151 )
{
struct V_1 * V_209 ;
struct V_2 * V_3 ;
T_1 V_210 , V_211 , V_212 , V_213 ;
if ( ! F_45 ( V_10 -> V_214 ,
V_215 | V_216 ) )
return - V_217 ;
V_209 = F_46 ( sizeof( struct V_1 ) , V_218 ) ;
if ( ! V_209 ) {
return - V_219 ;
}
V_3 = & V_209 -> V_3 ;
F_47 ( V_3 , V_10 , & V_220 ) ;
F_48 ( V_10 , L_69 ,
V_10 -> V_8 << 1 , V_10 -> V_214 -> V_221 ) ;
V_210 = F_4 ( V_3 , V_54 ) ;
V_211 = F_4 ( V_3 , V_55 ) ;
V_212 = F_4 ( V_3 , V_56 ) ;
V_213 = F_4 ( V_3 , V_57 ) ;
if ( V_212 == 4 && V_213 == 0 ) {
F_49 ( V_3 , L_70 , V_210 , V_211 ) ;
F_10 ( V_3 , V_53 , 0 ) ;
} else {
if ( V_212 == 3 || V_213 == 0x21 ) {
F_49 ( V_3 , L_71 , V_210 , V_211 ) ;
} else {
F_49 ( V_3 , L_72 ,
V_210 , V_211 ) ;
F_49 ( V_3 , L_73 , V_212 , V_213 ) ;
}
}
V_209 -> V_125 = V_127 ;
V_209 -> V_97 = V_102 ;
V_209 -> V_101 = 1 ;
F_50 ( & V_209 -> V_7 , 4 ) ;
F_51 ( & V_209 -> V_7 , & V_222 ,
V_152 , 0 , 255 , 1 , 128 ) ;
F_51 ( & V_209 -> V_7 , & V_222 ,
V_153 , 0 , 255 , 1 , 128 ) ;
F_51 ( & V_209 -> V_7 , & V_222 ,
V_154 , 0 , 255 , 1 , 128 ) ;
F_51 ( & V_209 -> V_7 , & V_222 ,
V_155 , - 128 , 127 , 1 , 0 ) ;
V_3 -> V_223 = & V_209 -> V_7 ;
if ( V_209 -> V_7 . error ) {
int V_224 = V_209 -> V_7 . error ;
F_52 ( & V_209 -> V_7 ) ;
F_53 ( V_209 ) ;
return V_224 ;
}
F_24 ( & V_209 -> V_7 ) ;
V_209 -> V_145 . V_175 = 0 ;
if ( F_26 ( V_3 ) & V_144 )
V_209 -> V_145 . V_146 = V_147 ;
else
V_209 -> V_145 . V_146 = V_148 ;
V_209 -> V_145 . V_174 = 0 ;
V_209 -> V_145 . V_164 = V_178 ;
if ( V_13 > 1 )
F_13 ( V_3 ) ;
return 0 ;
}
static int F_54 ( struct V_9 * V_10 )
{
struct V_2 * V_3 = F_55 ( V_10 ) ;
struct V_1 * V_96 = F_1 ( V_3 ) ;
F_7 ( 1 , V_13 , V_3 ,
L_74 ,
V_10 -> V_8 << 1 ) ;
F_56 ( V_3 ) ;
F_52 ( & V_96 -> V_7 ) ;
F_53 ( F_1 ( V_3 ) ) ;
return 0 ;
}
