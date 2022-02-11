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
return F_21 ( V_3 , V_124 ) ;
}
static int F_23 ( struct V_2 * V_3 , T_3 V_98 )
{
struct V_1 * V_96 = F_1 ( V_3 ) ;
F_15 ( V_3 , V_144 ) ;
F_16 ( V_3 , V_116 ) ;
F_14 ( V_3 ) ;
F_15 ( V_3 , V_145 ) ;
F_24 ( & V_96 -> V_7 ) ;
F_21 ( V_3 , V_96 -> V_125 ) ;
return 0 ;
}
static int F_25 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
switch ( V_5 -> V_146 ) {
case V_147 :
F_10 ( V_3 , V_29 , V_5 -> V_98 ) ;
return 0 ;
case V_148 :
F_10 ( V_3 , V_32 , V_5 -> V_98 ) ;
return 0 ;
case V_149 :
F_10 ( V_3 , V_30 , V_5 -> V_98 ) ;
return 0 ;
case V_150 :
F_10 ( V_3 , V_31 , V_5 -> V_98 ) ;
return 0 ;
}
return - V_151 ;
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
return V_152 ;
}
}
static int F_27 ( struct V_2 * V_3 , unsigned V_153 ,
enum V_154 * V_155 )
{
if ( V_153 )
return - V_151 ;
* V_155 = V_156 ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 ,
struct V_157 * V_158 )
{
struct V_1 * V_96 = F_1 ( V_3 ) ;
T_2 V_124 ;
if ( V_158 == NULL )
return - V_151 ;
F_23 ( V_3 , 0 ) ;
if ( V_96 -> V_125 == V_127 )
V_124 = F_26 ( V_3 ) ;
else
V_124 = V_96 -> V_125 ;
V_158 -> V_159 = 720 ;
if ( V_124 & V_160 )
V_158 -> V_161 = 480 ;
else
V_158 -> V_161 = 576 ;
V_158 -> V_155 = V_156 ;
V_158 -> V_162 = V_163 ;
V_158 -> V_164 = V_165 ;
F_7 ( 1 , V_13 , V_3 , L_67 , V_158 -> V_159 ,
V_158 -> V_161 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 ,
T_3 V_97 , T_3 V_99 , T_3 V_166 )
{
struct V_1 * V_96 = F_1 ( V_3 ) ;
V_96 -> V_97 = V_97 ;
V_96 -> V_99 = V_99 ;
F_14 ( V_3 ) ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 , struct V_167 * V_129 )
{
if ( V_129 -> V_168 == V_169 )
F_10 ( V_3 , V_26 , 0x70 ) ;
if ( V_129 -> V_170 [ 0 ] == 18 && V_129 -> V_170 [ 1 ] == 18 ) {
F_10 ( V_3 , V_41 , 0x00 ) ;
F_10 ( V_3 , V_42 , 0x01 ) ;
}
return 0 ;
}
static int F_31 ( struct V_2 * V_3 , struct V_171 * V_172 )
{
int V_19 ;
if ( V_172 -> V_121 != 0 ) {
for ( V_19 = 0 ; V_19 <= 23 ; V_19 ++ ) {
V_172 -> V_119 [ 1 ] [ V_19 ] = 0 ;
V_172 -> V_119 [ 0 ] [ V_19 ] =
F_18 ( V_3 , V_116 ,
V_172 -> V_119 [ 0 ] [ V_19 ] , 0xf0 , V_19 , 3 ) ;
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
static int F_32 ( struct V_2 * V_3 , struct V_171 * V_172 )
{
int V_19 , V_173 = 0 ;
memset ( V_172 , 0 , sizeof( * V_172 ) ) ;
for ( V_19 = 0 ; V_19 <= 23 ; V_19 ++ ) {
V_172 -> V_119 [ 0 ] [ V_19 ] =
F_20 ( V_3 , V_116 , V_19 ) ;
V_173 |= V_172 -> V_119 [ 0 ] [ V_19 ] ;
}
V_172 -> V_121 = V_173 ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 ,
struct V_174 * V_175 )
{
int V_176 ;
struct V_9 * V_177 = F_5 ( V_3 ) ;
V_176 = F_4 ( V_3 , V_56 ) << 8 |
F_4 ( V_3 , V_57 ) ;
return F_34 ( V_177 , V_175 , V_178 ,
V_176 ) ;
}
static int F_35 ( struct V_2 * V_3 , struct V_179 * V_107 )
{
struct V_9 * V_177 = F_5 ( V_3 ) ;
if ( ! F_36 ( V_177 , & V_107 -> V_180 ) )
return - V_151 ;
if ( ! F_37 ( V_181 ) )
return - V_182 ;
V_107 -> V_98 = F_4 ( V_3 , V_107 -> V_107 & 0xff ) ;
V_107 -> V_183 = 1 ;
return 0 ;
}
static int F_38 ( struct V_2 * V_3 , struct V_179 * V_107 )
{
struct V_9 * V_177 = F_5 ( V_3 ) ;
if ( ! F_36 ( V_177 , & V_107 -> V_180 ) )
return - V_151 ;
if ( ! F_37 ( V_181 ) )
return - V_182 ;
F_10 ( V_3 , V_107 -> V_107 & 0xff , V_107 -> V_98 & 0xff ) ;
return 0 ;
}
static int F_39 ( struct V_2 * V_3 , struct V_184 * V_185 )
{
int V_186 = F_4 ( V_3 , 0x88 ) ;
V_185 -> signal = ( ( V_186 & 0x04 ) && ( V_186 & 0x02 ) ) ? 0xffff : 0x0 ;
return 0 ;
}
static int F_40 ( struct V_9 * V_10 ,
const struct V_187 * V_146 )
{
struct V_1 * V_188 ;
struct V_2 * V_3 ;
T_1 V_189 , V_190 , V_191 , V_192 ;
if ( ! F_41 ( V_10 -> V_193 ,
V_194 | V_195 ) )
return - V_196 ;
V_188 = F_42 ( sizeof( struct V_1 ) , V_197 ) ;
if ( ! V_188 ) {
return - V_198 ;
}
V_3 = & V_188 -> V_3 ;
F_43 ( V_3 , V_10 , & V_199 ) ;
F_44 ( V_10 , L_68 ,
V_10 -> V_8 << 1 , V_10 -> V_193 -> V_200 ) ;
V_189 = F_4 ( V_3 , V_54 ) ;
V_190 = F_4 ( V_3 , V_55 ) ;
V_191 = F_4 ( V_3 , V_56 ) ;
V_192 = F_4 ( V_3 , V_57 ) ;
if ( V_191 == 4 && V_192 == 0 ) {
F_45 ( V_3 , L_69 , V_189 , V_190 ) ;
F_10 ( V_3 , V_53 , 0 ) ;
} else {
if ( V_191 == 3 || V_192 == 0x21 ) {
F_45 ( V_3 , L_70 , V_189 , V_190 ) ;
} else {
F_45 ( V_3 , L_71 ,
V_189 , V_190 ) ;
F_45 ( V_3 , L_72 , V_191 , V_192 ) ;
}
}
V_188 -> V_125 = V_127 ;
V_188 -> V_97 = V_102 ;
V_188 -> V_101 = 1 ;
F_46 ( & V_188 -> V_7 , 4 ) ;
F_47 ( & V_188 -> V_7 , & V_201 ,
V_147 , 0 , 255 , 1 , 128 ) ;
F_47 ( & V_188 -> V_7 , & V_201 ,
V_148 , 0 , 255 , 1 , 128 ) ;
F_47 ( & V_188 -> V_7 , & V_201 ,
V_149 , 0 , 255 , 1 , 128 ) ;
F_47 ( & V_188 -> V_7 , & V_201 ,
V_150 , - 128 , 127 , 1 , 0 ) ;
V_3 -> V_202 = & V_188 -> V_7 ;
if ( V_188 -> V_7 . error ) {
int V_203 = V_188 -> V_7 . error ;
F_48 ( & V_188 -> V_7 ) ;
F_49 ( V_188 ) ;
return V_203 ;
}
F_24 ( & V_188 -> V_7 ) ;
if ( V_13 > 1 )
F_13 ( V_3 ) ;
return 0 ;
}
static int F_50 ( struct V_9 * V_10 )
{
struct V_2 * V_3 = F_51 ( V_10 ) ;
struct V_1 * V_96 = F_1 ( V_3 ) ;
F_7 ( 1 , V_13 , V_3 ,
L_73 ,
V_10 -> V_8 << 1 ) ;
F_52 ( V_3 ) ;
F_48 ( & V_96 -> V_7 ) ;
F_49 ( F_1 ( V_3 ) ) ;
return 0 ;
}
static T_4 int F_53 ( void )
{
return F_54 ( & V_204 ) ;
}
static T_5 void F_55 ( void )
{
F_56 ( & V_204 ) ;
}
