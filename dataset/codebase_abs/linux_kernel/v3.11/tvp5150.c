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
V_12 = F_6 ( V_10 , V_11 , 1 ) ;
if ( V_12 < 0 ) {
F_7 ( V_3 , L_1 , V_12 ) ;
return V_12 ;
}
F_8 ( 10 ) ;
V_12 = F_9 ( V_10 , V_11 , 1 ) ;
if ( V_12 < 0 ) {
F_7 ( V_3 , L_1 , V_12 ) ;
return V_12 ;
}
F_10 ( 2 , V_13 , V_3 , L_2 , V_8 , V_11 [ 0 ] ) ;
return ( V_11 [ 0 ] ) ;
}
static inline void F_11 ( struct V_2 * V_3 , unsigned char V_8 ,
unsigned char V_14 )
{
struct V_9 * V_10 = F_5 ( V_3 ) ;
unsigned char V_11 [ 2 ] ;
int V_12 ;
V_11 [ 0 ] = V_8 ;
V_11 [ 1 ] = V_14 ;
F_10 ( 2 , V_13 , V_3 , L_3 , V_11 [ 0 ] , V_11 [ 1 ] ) ;
if ( 2 != ( V_12 = F_6 ( V_10 , V_11 , 2 ) ) )
F_10 ( 0 , V_13 , V_3 , L_4 , V_12 ) ;
}
static void F_12 ( struct V_2 * V_3 , char * V_15 , T_1 V_16 ,
const T_1 V_17 , int V_18 )
{
int V_19 = 0 ;
while ( V_16 != ( T_1 ) ( V_17 + 1 ) ) {
if ( ( V_19 % V_18 ) == 0 ) {
if ( V_19 > 0 )
F_13 ( L_5 ) ;
F_13 ( L_6 , V_15 , V_16 ) ;
}
F_13 ( L_7 , F_4 ( V_3 , V_16 ) ) ;
V_16 ++ ;
V_19 ++ ;
}
F_13 ( L_5 ) ;
}
static int F_14 ( struct V_2 * V_3 )
{
F_13 ( L_8 ,
F_4 ( V_3 , V_20 ) ) ;
F_13 ( L_9 ,
F_4 ( V_3 , V_21 ) ) ;
F_13 ( L_10 ,
F_4 ( V_3 , V_22 ) ) ;
F_13 ( L_11 ,
F_4 ( V_3 , V_23 ) ) ;
F_13 ( L_12 ,
F_4 ( V_3 , V_24 ) ) ;
F_13 ( L_13 ,
F_4 ( V_3 , V_25 ) ) ;
F_13 ( L_14 ,
F_4 ( V_3 , V_26 ) ,
F_4 ( V_3 , V_27 ) ,
F_4 ( V_3 , V_28 ) ) ;
F_13 ( L_15 ,
F_4 ( V_3 , V_29 ) ) ;
F_13 ( L_16 ,
F_4 ( V_3 , V_30 ) ) ;
F_13 ( L_17 ,
F_4 ( V_3 , V_31 ) ) ;
F_13 ( L_18 ,
F_4 ( V_3 , V_32 ) ) ;
F_13 ( L_19 ,
F_4 ( V_3 , V_33 ) ) ;
F_13 ( L_20 ,
F_4 ( V_3 , V_34 ) ) ;
F_13 ( L_21 ,
F_4 ( V_3 , V_35 ) ,
F_4 ( V_3 , V_36 ) ) ;
F_13 ( L_22 ,
F_4 ( V_3 , V_37 ) ,
F_4 ( V_3 , V_38 ) ) ;
F_13 ( L_23 ,
F_4 ( V_3 , V_39 ) ) ;
F_13 ( L_24 ,
F_4 ( V_3 , V_40 ) ) ;
F_13 ( L_25 ,
F_4 ( V_3 , V_41 ) ) ;
F_13 ( L_26 ,
F_4 ( V_3 , V_42 ) ) ;
F_13 ( L_27 ,
F_4 ( V_3 , V_43 ) ,
F_4 ( V_3 , V_44 ) ) ;
F_13 ( L_28 ,
F_4 ( V_3 , V_45 ) ) ;
F_13 ( L_29 ,
F_4 ( V_3 , V_46 ) ) ;
F_13 ( L_30 ,
F_4 ( V_3 , V_47 ) ) ;
F_13 ( L_31 ,
F_4 ( V_3 , V_48 ) ) ;
F_13 ( L_32 ,
F_4 ( V_3 , V_49 ) ,
F_4 ( V_3 , V_50 ) ) ;
F_13 ( L_33 ,
F_4 ( V_3 , V_51 ) ) ;
F_13 ( L_34 ,
F_4 ( V_3 , V_52 ) ) ;
F_13 ( L_35 ,
( F_4 ( V_3 , V_53 ) & 1 ) ? 3 : 4 ) ;
F_13 ( L_36 ,
F_4 ( V_3 , V_54 ) ,
F_4 ( V_3 , V_55 ) ) ;
F_13 ( L_37 ,
F_4 ( V_3 , V_56 ) ,
F_4 ( V_3 , V_57 ) ) ;
F_13 ( L_38 ,
F_4 ( V_3 , V_58 ) ,
F_4 ( V_3 , V_59 ) ) ;
F_13 ( L_39 ,
F_4 ( V_3 , V_60 ) ) ;
F_13 ( L_40 ,
F_4 ( V_3 , V_61 ) ) ;
F_13 ( L_41 ,
F_4 ( V_3 , V_62 ) ,
F_4 ( V_3 , V_63 ) ,
F_4 ( V_3 , V_64 ) ,
F_4 ( V_3 , V_65 ) ,
F_4 ( V_3 , V_66 ) ) ;
F_12 ( V_3 , L_42 , V_67 ,
V_68 , 8 ) ;
F_12 ( V_3 , L_43 , V_69 ,
V_70 , 8 ) ;
F_13 ( L_44 ,
F_4 ( V_3 , V_71 ) ) ;
F_13 ( L_45 ,
F_4 ( V_3 , V_72 ) ) ;
F_13 ( L_46 ,
F_4 ( V_3 , V_73 ) ) ;
F_13 ( L_47 ,
F_4 ( V_3 , V_74 ) ) ;
F_13 ( L_48 ,
F_4 ( V_3 , V_75 ) ) ;
F_13 ( L_49 ,
F_4 ( V_3 , V_76 ) ) ;
F_13 ( L_50 ,
F_4 ( V_3 , V_77 ) ) ;
F_13 ( L_51 ,
F_4 ( V_3 , V_78 ) ) ;
F_13 ( L_52 ,
F_4 ( V_3 , V_79 ) ) ;
F_13 ( L_53 ,
F_4 ( V_3 , V_80 ) ,
F_4 ( V_3 , V_81 ) ) ;
F_13 ( L_54 ,
F_4 ( V_3 , V_82 ) ) ;
F_13 ( L_55 ,
F_4 ( V_3 , V_83 ) ) ;
F_13 ( L_56 ,
F_4 ( V_3 , V_84 ) ) ;
F_12 ( V_3 , L_57 , V_85 ,
V_86 , 8 ) ;
F_12 ( V_3 , L_58 , V_87 ,
V_88 , 8 ) ;
F_12 ( V_3 , L_59 , V_89 ,
V_90 , 8 ) ;
F_12 ( V_3 , L_60 , V_91 ,
V_92 , 10 ) ;
F_12 ( V_3 , L_61 , V_93 ,
V_94 , 8 ) ;
return 0 ;
}
static inline void F_15 ( struct V_2 * V_3 )
{
int V_95 = 0 ;
struct V_1 * V_96 = F_1 ( V_3 ) ;
int V_97 = 0 ;
int V_98 ;
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
F_10 ( 1 , V_13 , V_3 , L_62
L_63 ,
V_96 -> V_97 , V_96 -> V_99 ,
V_97 , V_95 ) ;
F_11 ( V_3 , V_22 , V_95 ) ;
F_11 ( V_3 , V_20 , V_97 ) ;
V_98 = F_4 ( V_3 , V_23 ) ;
if ( V_98 < 0 ) {
F_7 ( V_3 , L_64 , V_105 , V_98 ) ;
return;
}
if ( V_96 -> V_97 == V_104 )
V_98 = ( V_98 & ~ 0x40 ) | 0x10 ;
else
V_98 = ( V_98 & ~ 0x10 ) | 0x40 ;
F_11 ( V_3 , V_23 , V_98 ) ;
}
static int F_16 ( struct V_2 * V_3 ,
const struct V_106 * V_107 )
{
while ( V_107 -> V_108 != 0xff ) {
F_11 ( V_3 , V_107 -> V_108 , V_107 -> V_14 ) ;
V_107 ++ ;
}
return 0 ;
}
static int F_17 ( struct V_2 * V_3 ,
const struct V_109 * V_107 )
{
unsigned int V_19 ;
F_11 ( V_3 , V_83 , 0 ) ;
for ( V_19 = V_93 ; V_19 <= V_94 ; V_19 ++ )
F_11 ( V_3 , V_19 , 0xff ) ;
while ( V_107 -> V_108 != ( V_110 ) - 1 ) {
F_11 ( V_3 , V_111 , V_107 -> V_108 >> 8 ) ;
F_11 ( V_3 , V_112 , V_107 -> V_108 ) ;
for ( V_19 = 0 ; V_19 < 16 ; V_19 ++ )
F_11 ( V_3 , V_113 , V_107 -> V_114 [ V_19 ] ) ;
V_107 ++ ;
}
return 0 ;
}
static int F_18 ( struct V_2 * V_3 ,
struct V_115 * V_116 )
{
const struct V_109 * V_107 = V_117 ;
int line ;
F_10 ( 1 , V_13 , V_3 , L_65 ) ;
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
static int F_19 ( struct V_2 * V_3 ,
const struct V_109 * V_107 ,
unsigned int type , T_1 V_123 , int line ,
const int V_124 )
{
struct V_1 * V_96 = F_1 ( V_3 ) ;
T_2 V_125 = V_96 -> V_126 ;
T_1 V_108 ;
int V_127 = 0 ;
if ( V_125 == V_128 ) {
F_7 ( V_3 , L_66 ) ;
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
V_108 = ( ( line - 6 ) << 1 ) + V_93 ;
if ( V_124 & 1 ) {
F_11 ( V_3 , V_108 , type ) ;
}
if ( V_124 & 2 ) {
F_11 ( V_3 , V_108 + 1 , type ) ;
}
return type ;
}
static int F_20 ( struct V_2 * V_3 ,
const struct V_109 * V_107 , int line )
{
struct V_1 * V_96 = F_1 ( V_3 ) ;
T_2 V_125 = V_96 -> V_126 ;
T_1 V_108 ;
int V_127 , type = 0 ;
int V_19 , V_130 = 0 ;
if ( V_125 == V_128 ) {
F_7 ( V_3 , L_66 ) ;
return 0 ;
} else if ( V_125 & V_129 ) {
line += 3 ;
}
if ( line < 6 || line > 27 )
return 0 ;
V_108 = ( ( line - 6 ) << 1 ) + V_93 ;
for ( V_19 = 0 ; V_19 <= 1 ; V_19 ++ ) {
V_130 = F_4 ( V_3 , V_108 + V_19 ) ;
if ( V_130 < 0 ) {
F_7 ( V_3 , L_64 ,
V_105 , V_130 ) ;
return 0 ;
}
V_127 = V_130 & 0x0f ;
if ( V_127 < 0x0f )
type |= V_107 [ V_127 ] . type . V_121 ;
}
return type ;
}
static int F_21 ( struct V_2 * V_3 , T_2 V_125 )
{
struct V_1 * V_96 = F_1 ( V_3 ) ;
int V_131 = 0 ;
V_96 -> V_126 = V_125 ;
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
F_10 ( 1 , V_13 , V_3 , L_67 , V_131 ) ;
F_11 ( V_3 , V_48 , V_131 ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 , T_2 V_125 )
{
struct V_1 * V_96 = F_1 ( V_3 ) ;
if ( V_96 -> V_126 == V_125 )
return 0 ;
if ( V_125 & V_145 )
V_96 -> V_146 . V_147 = V_148 ;
else
V_96 -> V_146 . V_147 = V_149 ;
return F_21 ( V_3 , V_125 ) ;
}
static int F_23 ( struct V_2 * V_3 , T_3 V_98 )
{
struct V_1 * V_96 = F_1 ( V_3 ) ;
F_16 ( V_3 , V_150 ) ;
F_17 ( V_3 , V_117 ) ;
F_15 ( V_3 ) ;
F_16 ( V_3 , V_151 ) ;
F_24 ( & V_96 -> V_7 ) ;
F_21 ( V_3 , V_96 -> V_126 ) ;
return 0 ;
}
static int F_25 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
switch ( V_5 -> V_152 ) {
case V_153 :
F_11 ( V_3 , V_29 , V_5 -> V_98 ) ;
return 0 ;
case V_154 :
F_11 ( V_3 , V_32 , V_5 -> V_98 ) ;
return 0 ;
case V_155 :
F_11 ( V_3 , V_30 , V_5 -> V_98 ) ;
return 0 ;
case V_156 :
F_11 ( V_3 , V_31 , V_5 -> V_98 ) ;
return 0 ;
}
return - V_157 ;
}
static T_2 F_26 ( struct V_2 * V_3 )
{
int V_98 = F_4 ( V_3 , V_66 ) ;
switch ( V_98 & 0x0F ) {
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
return V_158 ;
}
}
static int F_27 ( struct V_2 * V_3 , unsigned V_159 ,
enum V_160 * V_161 )
{
if ( V_159 )
return - V_157 ;
* V_161 = V_162 ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 ,
struct V_163 * V_164 )
{
struct V_1 * V_96 = F_1 ( V_3 ) ;
if ( V_164 == NULL )
return - V_157 ;
F_23 ( V_3 , 0 ) ;
V_164 -> V_165 = V_96 -> V_146 . V_165 ;
V_164 -> V_147 = V_96 -> V_146 . V_147 ;
V_164 -> V_161 = V_162 ;
V_164 -> V_166 = V_167 ;
V_164 -> V_168 = V_169 ;
F_10 ( 1 , V_13 , V_3 , L_68 , V_164 -> V_165 ,
V_164 -> V_147 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 , const struct V_170 * V_171 )
{
struct V_172 V_146 = V_171 -> V_10 ;
struct V_1 * V_96 = F_1 ( V_3 ) ;
T_2 V_125 ;
int V_173 ;
F_10 ( 1 , V_13 , V_3 , L_69 ,
V_105 , V_146 . V_174 , V_146 . V_175 , V_146 . V_165 , V_146 . V_147 ) ;
if ( V_171 -> type != V_176 )
return - V_157 ;
V_146 . V_174 = F_30 ( V_146 . V_174 , 0 , V_177 ) ;
V_146 . V_165 = F_30 ( V_146 . V_165 ,
V_178 - V_177 - V_146 . V_174 ,
V_178 - V_146 . V_174 ) ;
V_146 . V_175 = F_30 ( V_146 . V_175 , 0 , V_179 ) ;
if ( V_96 -> V_126 == V_128 )
V_125 = F_26 ( V_3 ) ;
else
V_125 = V_96 -> V_126 ;
if ( V_125 & V_145 )
V_173 = V_148 ;
else
V_173 = V_149 ;
V_146 . V_147 = F_30 ( V_146 . V_147 ,
V_173 - V_179 - V_146 . V_175 ,
V_173 - V_146 . V_175 ) ;
F_11 ( V_3 , V_41 , V_146 . V_175 ) ;
F_11 ( V_3 , V_42 ,
V_146 . V_175 + V_146 . V_147 - V_173 ) ;
F_11 ( V_3 , V_35 ,
V_146 . V_174 >> V_180 ) ;
F_11 ( V_3 , V_36 ,
V_146 . V_174 | ( 1 << V_180 ) ) ;
F_11 ( V_3 , V_37 ,
( V_146 . V_174 + V_146 . V_165 - V_177 ) >>
V_180 ) ;
F_11 ( V_3 , V_38 ,
V_146 . V_174 + V_146 . V_165 - V_177 ) ;
V_96 -> V_146 = V_146 ;
return 0 ;
}
static int F_31 ( struct V_2 * V_3 , struct V_170 * V_171 )
{
struct V_1 * V_96 = F_2 ( V_3 , struct V_1 , V_3 ) ;
V_171 -> V_10 = V_96 -> V_146 ;
V_171 -> type = V_176 ;
return 0 ;
}
static int F_32 ( struct V_2 * V_3 , struct V_181 * V_171 )
{
struct V_1 * V_96 = F_2 ( V_3 , struct V_1 , V_3 ) ;
T_2 V_125 ;
if ( V_171 -> type != V_176 )
return - V_157 ;
V_171 -> V_182 . V_174 = 0 ;
V_171 -> V_182 . V_175 = 0 ;
V_171 -> V_182 . V_165 = V_178 ;
if ( V_96 -> V_126 == V_128 )
V_125 = F_26 ( V_3 ) ;
else
V_125 = V_96 -> V_126 ;
if ( V_125 & V_145 )
V_171 -> V_182 . V_147 = V_148 ;
else
V_171 -> V_182 . V_147 = V_149 ;
V_171 -> V_183 = V_171 -> V_182 ;
V_171 -> V_184 . V_185 = 1 ;
V_171 -> V_184 . V_186 = 1 ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 ,
T_3 V_97 , T_3 V_99 , T_3 V_187 )
{
struct V_1 * V_96 = F_1 ( V_3 ) ;
V_96 -> V_97 = V_97 ;
V_96 -> V_99 = V_99 ;
F_15 ( V_3 ) ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 , struct V_188 * V_131 )
{
if ( V_131 -> V_189 == V_190 )
F_11 ( V_3 , V_26 , 0x70 ) ;
if ( V_131 -> V_191 [ 0 ] == 18 && V_131 -> V_191 [ 1 ] == 18 ) {
F_11 ( V_3 , V_41 , 0x00 ) ;
F_11 ( V_3 , V_42 , 0x01 ) ;
}
return 0 ;
}
static int F_35 ( struct V_2 * V_3 , struct V_192 * V_193 )
{
int V_19 ;
if ( V_193 -> V_122 != 0 ) {
for ( V_19 = 0 ; V_19 <= 23 ; V_19 ++ ) {
V_193 -> V_120 [ 1 ] [ V_19 ] = 0 ;
V_193 -> V_120 [ 0 ] [ V_19 ] =
F_19 ( V_3 , V_117 ,
V_193 -> V_120 [ 0 ] [ V_19 ] , 0xf0 , V_19 , 3 ) ;
}
F_11 ( V_3 , V_82 , 1 ) ;
} else {
F_11 ( V_3 , V_82 , 0 ) ;
F_11 ( V_3 , V_83 , 0 ) ;
for ( V_19 = V_93 ; V_19 <= V_94 ; V_19 ++ )
F_11 ( V_3 , V_19 , 0xff ) ;
}
return 0 ;
}
static int F_36 ( struct V_2 * V_3 , struct V_192 * V_193 )
{
int V_19 , V_194 = 0 ;
memset ( V_193 -> V_120 , 0 , sizeof( V_193 -> V_120 ) ) ;
for ( V_19 = 0 ; V_19 <= 23 ; V_19 ++ ) {
V_193 -> V_120 [ 0 ] [ V_19 ] =
F_20 ( V_3 , V_117 , V_19 ) ;
V_194 |= V_193 -> V_120 [ 0 ] [ V_19 ] ;
}
V_193 -> V_122 = V_194 ;
return 0 ;
}
static int F_37 ( struct V_2 * V_3 , struct V_195 * V_108 )
{
int V_196 ;
V_196 = F_4 ( V_3 , V_108 -> V_108 & 0xff ) ;
if ( V_196 < 0 ) {
F_7 ( V_3 , L_64 , V_105 , V_196 ) ;
return V_196 ;
}
V_108 -> V_98 = V_196 ;
V_108 -> V_197 = 1 ;
return 0 ;
}
static int F_38 ( struct V_2 * V_3 , const struct V_195 * V_108 )
{
F_11 ( V_3 , V_108 -> V_108 & 0xff , V_108 -> V_98 & 0xff ) ;
return 0 ;
}
static int F_39 ( struct V_2 * V_3 , struct V_198 * V_199 )
{
int V_200 = F_4 ( V_3 , 0x88 ) ;
V_199 -> signal = ( ( V_200 & 0x04 ) && ( V_200 & 0x02 ) ) ? 0xffff : 0x0 ;
return 0 ;
}
static int F_40 ( struct V_9 * V_10 ,
const struct V_201 * V_152 )
{
struct V_1 * V_202 ;
struct V_2 * V_3 ;
int V_203 [ 4 ] ;
int V_19 , V_196 ;
if ( ! F_41 ( V_10 -> V_204 ,
V_205 | V_206 ) )
return - V_207 ;
V_202 = F_42 ( & V_10 -> V_208 , sizeof( * V_202 ) , V_209 ) ;
if ( ! V_202 )
return - V_210 ;
V_3 = & V_202 -> V_3 ;
F_43 ( V_3 , V_10 , & V_211 ) ;
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
V_196 = F_4 ( V_3 , V_54 + V_19 ) ;
if ( V_196 < 0 )
return V_196 ;
V_203 [ V_19 ] = V_196 ;
}
F_44 ( V_10 , L_70 ,
V_10 -> V_8 << 1 , V_10 -> V_204 -> V_212 ) ;
if ( V_203 [ 2 ] == 4 && V_203 [ 3 ] == 0 ) {
F_45 ( V_3 , L_71 ,
V_203 [ 0 ] , V_203 [ 1 ] ) ;
F_11 ( V_3 , V_53 , 0 ) ;
} else {
if ( V_203 [ 2 ] == 3 || V_203 [ 3 ] == 0x21 ) {
F_45 ( V_3 , L_72 ,
V_203 [ 2 ] , V_203 [ 3 ] ) ;
} else {
F_45 ( V_3 , L_73 ,
V_203 [ 2 ] , V_203 [ 3 ] ) ;
F_45 ( V_3 , L_74 ,
V_203 [ 2 ] , V_203 [ 3 ] ) ;
}
}
V_202 -> V_126 = V_128 ;
V_202 -> V_97 = V_102 ;
V_202 -> V_101 = 1 ;
F_46 ( & V_202 -> V_7 , 4 ) ;
F_47 ( & V_202 -> V_7 , & V_213 ,
V_153 , 0 , 255 , 1 , 128 ) ;
F_47 ( & V_202 -> V_7 , & V_213 ,
V_154 , 0 , 255 , 1 , 128 ) ;
F_47 ( & V_202 -> V_7 , & V_213 ,
V_155 , 0 , 255 , 1 , 128 ) ;
F_47 ( & V_202 -> V_7 , & V_213 ,
V_156 , - 128 , 127 , 1 , 0 ) ;
V_3 -> V_214 = & V_202 -> V_7 ;
if ( V_202 -> V_7 . error ) {
V_196 = V_202 -> V_7 . error ;
F_48 ( & V_202 -> V_7 ) ;
return V_196 ;
}
F_24 ( & V_202 -> V_7 ) ;
V_202 -> V_146 . V_175 = 0 ;
if ( F_26 ( V_3 ) & V_145 )
V_202 -> V_146 . V_147 = V_148 ;
else
V_202 -> V_146 . V_147 = V_149 ;
V_202 -> V_146 . V_174 = 0 ;
V_202 -> V_146 . V_165 = V_178 ;
if ( V_13 > 1 )
F_14 ( V_3 ) ;
return 0 ;
}
static int F_49 ( struct V_9 * V_10 )
{
struct V_2 * V_3 = F_50 ( V_10 ) ;
struct V_1 * V_96 = F_1 ( V_3 ) ;
F_10 ( 1 , V_13 , V_3 ,
L_75 ,
V_10 -> V_8 << 1 ) ;
F_51 ( V_3 ) ;
F_48 ( & V_96 -> V_7 ) ;
return 0 ;
}
