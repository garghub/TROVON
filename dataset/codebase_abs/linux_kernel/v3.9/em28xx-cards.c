int F_1 ( void * V_1 , int V_2 , int V_3 , int V_4 )
{
int V_5 = 0 ;
struct V_6 * V_7 = V_1 ;
if ( V_7 -> V_8 != V_9 && V_7 -> V_8 != V_10 )
return 0 ;
if ( V_3 != V_11 && V_3 != V_12 )
return 0 ;
V_5 = F_2 ( V_7 , V_7 -> V_13 . V_14 ) ;
return V_5 ;
}
static inline void F_3 ( struct V_6 * V_7 )
{
V_7 -> V_13 = V_15 [ V_7 -> V_16 ] ;
if ( ! V_7 -> V_13 . V_17 )
V_7 -> V_13 . V_17 = V_18 |
V_19 ;
if ( ! V_7 -> V_13 . V_20 )
V_7 -> V_13 . V_20 = V_21 |
V_22 ;
}
static int F_4 ( struct V_6 * V_7 )
{
int V_23 ;
unsigned char V_24 [] [ 3 ] = {
{ 0x0d , 0x00 , 0x01 , } ,
{ 0x0d , 0x00 , 0x00 , } ,
{ 0x0a , 0x00 , 0x21 , } ,
{ 0x21 , 0x04 , 0x00 , } ,
} ;
for ( V_23 = 0 ; V_23 < F_5 ( V_24 ) ; V_23 ++ )
F_6 ( & V_7 -> V_25 , & V_24 [ V_23 ] [ 0 ] , 3 ) ;
return 0 ;
}
static int F_7 ( struct V_6 * V_7 )
{
int V_23 ;
unsigned char V_24 [] [ 3 ] = {
{ 0x0d , 0x00 , 0x01 , } ,
{ 0x0d , 0x00 , 0x00 , } ,
{ 0x04 , 0x05 , 0x00 , } ,
{ 0x03 , 0x04 , 0x00 , } ,
{ 0x20 , 0x11 , 0x00 , } ,
{ 0x06 , 0x00 , 0x10 , } ,
{ 0x2b , 0x00 , 0x24 , } ,
{ 0x2e , 0x00 , 0x24 , } ,
{ 0x35 , 0x00 , 0x24 , } ,
{ 0x2d , 0x00 , 0x20 , } ,
{ 0x2c , 0x00 , 0x20 , } ,
{ 0x09 , 0x0a , 0xd4 , } ,
{ 0x35 , 0x00 , 0x57 , } ,
} ;
for ( V_23 = 0 ; V_23 < F_5 ( V_24 ) ; V_23 ++ )
F_6 ( & V_7 -> V_25 , & V_24 [ V_23 ] [ 0 ] , 3 ) ;
return 0 ;
}
static int F_8 ( struct V_6 * V_7 )
{
int V_5 ;
char * V_26 ;
unsigned char V_27 ;
T_1 V_28 ;
T_2 V_29 ;
V_7 -> V_25 . V_30 = 0xba >> 1 ;
V_27 = 0 ;
F_6 ( & V_7 -> V_25 , & V_27 , 1 ) ;
V_5 = F_9 ( & V_7 -> V_25 , ( char * ) & V_28 , 2 ) ;
if ( V_5 != 2 )
return - V_31 ;
V_29 = F_10 ( V_28 ) ;
switch ( V_29 ) {
case 0x8232 :
case 0x8243 :
V_7 -> V_16 = V_32 ;
F_3 ( V_7 ) ;
V_26 = L_1 ;
V_7 -> V_33 = V_34 ;
V_7 -> V_35 = 640 ;
V_7 -> V_36 = 480 ;
V_7 -> V_13 . V_17 = V_37 ;
V_7 -> V_38 = 4300000 ;
V_7 -> V_39 = 0x0d ;
V_7 -> V_40 = 0x00 ;
break;
case 0x143a :
V_7 -> V_16 = V_41 ;
F_3 ( V_7 ) ;
V_26 = L_2 ;
V_7 -> V_13 . V_17 = V_42 ;
V_7 -> V_33 = V_43 ;
F_4 ( V_7 ) ;
V_7 -> V_35 = 640 ;
V_7 -> V_36 = 512 ;
V_7 -> V_39 = 0x0a ;
V_7 -> V_40 = 0x00 ;
break;
case 0x8431 :
V_7 -> V_16 = V_41 ;
F_3 ( V_7 ) ;
V_26 = L_3 ;
V_7 -> V_33 = V_44 ;
F_7 ( V_7 ) ;
V_7 -> V_35 = 1280 ;
V_7 -> V_36 = 1024 ;
V_7 -> V_39 = 0x0c ;
V_7 -> V_40 = 0x00 ;
break;
default:
F_11 ( L_4 , V_29 ) ;
return - V_31 ;
}
F_12 ( V_7 ) ;
F_13 ( L_5 ,
V_26 , V_15 [ V_7 -> V_16 ] . V_45 ) ;
return 0 ;
}
static void F_12 ( struct V_6 * V_7 )
{
F_14 ( V_7 , V_46 , V_7 -> V_13 . V_17 & 0x7f ) ;
if ( ! V_7 -> V_13 . V_47 )
F_14 ( V_7 , V_48 , V_7 -> V_13 . V_20 ) ;
F_15 ( 50 ) ;
switch ( V_7 -> V_16 ) {
case V_49 :
V_7 -> V_50 = 2048000 ;
break;
case V_51 :
case V_52 :
F_14 ( V_7 , V_53 , 0x6d ) ;
F_15 ( 10 ) ;
F_14 ( V_7 , V_53 , 0x7d ) ;
F_15 ( 10 ) ;
break;
case V_54 :
F_14 ( V_7 , V_55 , 0x00 ) ;
F_15 ( 10 ) ;
F_14 ( V_7 , V_55 , 0x01 ) ;
F_15 ( 10 ) ;
F_14 ( V_7 , V_53 , 0xfd ) ;
F_16 ( 70 ) ;
F_14 ( V_7 , V_53 , 0xfc ) ;
F_16 ( 70 ) ;
F_14 ( V_7 , V_53 , 0xdc ) ;
F_16 ( 70 ) ;
F_14 ( V_7 , V_53 , 0xfc ) ;
F_16 ( 70 ) ;
break;
case V_56 :
F_14 ( V_7 , V_53 , 0xfe ) ;
F_16 ( 70 ) ;
F_14 ( V_7 , V_53 , 0xde ) ;
F_16 ( 70 ) ;
F_14 ( V_7 , V_53 , 0xfe ) ;
F_16 ( 70 ) ;
break;
case V_57 :
F_14 ( V_7 , V_53 , 0xfe ) ;
F_16 ( 70 ) ;
F_14 ( V_7 , V_53 , 0xde ) ;
F_16 ( 70 ) ;
F_14 ( V_7 , V_53 , 0xfe ) ;
F_16 ( 70 ) ;
break;
case V_58 :
case V_59 :
F_14 ( V_7 , V_53 , 0xfd ) ;
break;
case V_60 :
F_14 ( V_7 , V_53 , 0xff ) ;
F_15 ( 10 ) ;
F_14 ( V_7 , V_53 , 0xfe ) ;
F_15 ( 10 ) ;
F_14 ( V_7 , V_55 , 0x00 ) ;
F_15 ( 10 ) ;
F_14 ( V_7 , V_55 , 0x08 ) ;
F_15 ( 10 ) ;
break;
case V_61 :
F_17 ( V_7 , V_46 , L_6 , 1 ) ;
F_17 ( V_7 , V_48 , L_7 , 1 ) ;
F_17 ( V_7 , 0x0d , L_8 , 1 ) ;
F_17 ( V_7 , 0x08 , L_9 , 1 ) ;
F_15 ( 10 ) ;
F_17 ( V_7 , 0x08 , L_10 , 1 ) ;
F_15 ( 10 ) ;
F_17 ( V_7 , 0x08 , L_11 , 1 ) ;
F_15 ( 10 ) ;
F_17 ( V_7 , 0x08 , L_12 , 1 ) ;
break;
case V_62 :
F_17 ( V_7 , 0x08 , L_13 , 1 ) ;
break;
case V_63 :
F_14 ( V_7 , V_53 , 0xff ) ;
F_15 ( 70 ) ;
F_14 ( V_7 , V_53 , 0xf7 ) ;
F_15 ( 10 ) ;
F_14 ( V_7 , V_53 , 0xfe ) ;
F_15 ( 70 ) ;
F_14 ( V_7 , V_53 , 0xfd ) ;
F_15 ( 70 ) ;
break;
}
F_2 ( V_7 , V_7 -> V_13 . V_14 ) ;
F_18 ( V_7 , V_64 ) ;
F_18 ( V_7 , V_65 ) ;
}
static void F_19 ( struct V_6 * V_7 , struct V_66 * V_67 )
{
memset ( V_67 , 0 , sizeof( * V_67 ) ) ;
V_67 -> V_68 = V_69 ;
V_67 -> V_70 = 64 ;
V_67 -> V_71 = V_15 [ V_7 -> V_16 ] . V_72 ;
switch ( V_7 -> V_16 ) {
case V_73 :
case V_74 :
case V_75 :
V_67 -> V_76 = V_77 ;
break;
case V_78 :
case V_79 :
case V_80 :
V_67 -> V_76 = V_77 ;
break;
case V_81 :
case V_82 :
V_67 -> V_76 = V_83 ;
break;
case V_84 :
V_67 -> V_76 = V_83 ;
V_67 -> V_68 = V_85 ;
break;
case V_86 :
case V_87 :
case V_88 :
V_67 -> V_76 = V_83 ;
break;
case V_89 :
case V_90 :
case V_91 :
V_67 -> V_76 = V_92 ;
V_67 -> V_68 = V_69 ;
break;
case V_93 :
V_67 -> V_76 = V_92 ;
V_67 -> V_68 = V_85 ;
break;
default:
V_67 -> V_76 = V_94 ;
}
}
static void F_20 ( struct V_6 * V_7 )
{
struct V_95 V_96 ;
struct V_97 V_98 ;
if ( V_7 -> V_8 == V_99 )
return;
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
V_96 . V_100 = V_101 | V_102 ;
V_96 . V_103 = F_1 ;
if ( V_7 -> V_13 . V_104 . type ) {
V_96 . type = V_7 -> V_13 . V_104 . type ;
V_96 . V_30 = V_7 -> V_13 . V_105 ;
F_21 ( & V_7 -> V_106 , 0 , V_107 , V_108 , & V_96 ) ;
}
if ( ( V_7 -> V_8 != V_99 ) && ( V_7 -> V_8 ) ) {
V_96 . type = V_7 -> V_8 ;
V_96 . V_30 = V_7 -> V_109 ;
F_21 ( & V_7 -> V_106 , 0 , V_107 , V_108 , & V_96 ) ;
}
if ( V_7 -> V_110 ) {
struct V_111 V_112 ;
V_112 . V_107 = V_113 ;
V_112 . V_114 = & V_7 -> V_110 ;
F_21 ( & V_7 -> V_106 , 0 , V_107 , V_115 , & V_112 ) ;
}
if ( V_7 -> V_8 == V_9 ) {
struct V_111 V_116 ;
struct V_66 V_67 ;
memset ( & V_116 , 0 , sizeof( V_116 ) ) ;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
F_19 ( V_7 , & V_67 ) ;
V_116 . V_107 = V_9 ;
V_116 . V_114 = & V_67 ;
F_21 ( & V_7 -> V_106 , 0 , V_107 , V_115 , & V_116 ) ;
}
V_98 . V_107 = 0 ;
V_98 . type = V_117 ;
V_98 . V_118 = 9076 ;
V_7 -> V_119 = V_98 . V_118 ;
F_21 ( & V_7 -> V_106 , 0 , V_107 , V_120 , & V_98 ) ;
}
static int F_22 ( struct V_6 * V_7 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < F_5 ( V_121 ) ; V_23 ++ ) {
if ( V_7 -> V_122 == V_121 [ V_23 ] . V_122 ) {
V_7 -> V_16 = V_121 [ V_23 ] . V_16 ;
V_7 -> V_8 = V_121 [ V_23 ] . V_107 ;
F_13 ( L_14 ) ;
F_13 ( L_15
L_16 ) ;
F_13 ( L_17 ) ;
F_13 ( L_18
L_19 ) ;
F_13 ( L_20
L_21 ) ;
F_13 ( L_22 ,
V_15 [ V_7 -> V_16 ] . V_45 ) ;
return 0 ;
}
}
if ( ! V_7 -> V_123 )
F_23 ( V_7 ) ;
for ( V_23 = 0 ; V_23 < F_5 ( V_124 ) ; V_23 ++ ) {
if ( V_7 -> V_123 == V_124 [ V_23 ] . V_122 ) {
V_7 -> V_16 = V_124 [ V_23 ] . V_16 ;
V_7 -> V_8 = V_124 [ V_23 ] . V_107 ;
F_13 ( L_14 ) ;
F_13 ( L_15
L_23 ) ;
F_13 ( L_17 ) ;
F_13 ( L_18
L_19 ) ;
F_13 ( L_20
L_21 ) ;
F_13 ( L_22 ,
V_15 [ V_7 -> V_16 ] . V_45 ) ;
return 0 ;
}
}
F_13 ( L_24
L_25 ) ;
F_13 ( L_26
L_27 ) ;
F_13 ( L_28 ) ;
F_13 ( L_29 ) ;
F_13 ( L_30 , V_7 -> V_122 ) ;
F_13 ( L_31 , V_7 -> V_123 ) ;
F_13 ( L_32
L_33 ) ;
for ( V_23 = 0 ; V_23 < V_125 ; V_23 ++ ) {
F_13 ( L_34 ,
V_23 , V_15 [ V_23 ] . V_45 ) ;
}
return - 1 ;
}
static void F_24 ( struct V_6 * V_7 )
{
if ( V_7 -> V_13 . V_126 ) {
if ( F_8 ( V_7 ) < 0 )
V_7 -> V_13 . V_126 = 0 ;
else
V_7 -> V_127 = 1 ;
}
if ( ! V_7 -> V_13 . V_126 ) {
switch ( V_7 -> V_16 ) {
case V_128 :
case V_129 :
if ( F_22 ( V_7 ) < 0 )
F_13 ( L_35 ) ;
else {
F_3 ( V_7 ) ;
F_12 ( V_7 ) ;
}
break;
default:
F_3 ( V_7 ) ;
}
}
F_25 ( L_36 ,
V_7 -> V_13 . V_45 , V_7 -> V_16 ) ;
V_7 -> V_8 = V_15 [ V_7 -> V_16 ] . V_8 ;
if ( V_15 [ V_7 -> V_16 ] . V_109 )
V_7 -> V_109 = V_15 [ V_7 -> V_16 ] . V_109 ;
if ( V_15 [ V_7 -> V_16 ] . V_110 )
V_7 -> V_110 = V_15 [ V_7 -> V_16 ] . V_110 ;
switch ( V_7 -> V_16 ) {
case V_130 :
case V_74 :
case V_81 :
case V_86 :
case V_87 :
{
struct V_131 V_132 ;
#if F_26 ( V_133 ) && F_26 ( V_134 )
F_27 ( L_37 ) ;
#endif
V_7 -> V_25 . V_30 = 0xa0 >> 1 ;
F_28 ( & V_7 -> V_25 , & V_132 , V_7 -> V_135 ) ;
V_7 -> V_8 = V_132 . V_8 ;
if ( V_132 . V_136 == V_137 ) {
V_7 -> V_50 = 2048000 ;
V_7 -> V_13 . V_138 = 1 ;
}
break;
}
case V_60 :
F_14 ( V_7 , 0x0d , 0x42 ) ;
F_15 ( 10 ) ;
F_14 ( V_7 , V_53 , 0xfd ) ;
F_15 ( 10 ) ;
break;
case V_139 :
F_14 ( V_7 , V_53 , 0xf9 ) ;
break;
case V_128 :
case V_129 :
case V_140 :
if ( ! F_22 ( V_7 ) )
F_3 ( V_7 ) ;
F_2 ( V_7 , V_7 -> V_13 . V_14 ) ;
F_18 ( V_7 , V_64 ) ;
break;
case V_91 :
if ( ! F_22 ( V_7 ) )
F_3 ( V_7 ) ;
F_2 ( V_7 , V_7 -> V_13 . V_14 ) ;
F_18 ( V_7 , V_64 ) ;
break;
}
if ( V_7 -> V_13 . V_141 == V_142 ) {
F_13 ( L_38 ) ;
F_13 ( L_39
L_40 ) ;
F_13 ( L_41 ) ;
F_13 ( L_42
L_43 ) ;
}
if ( V_107 >= 0 )
V_7 -> V_8 = V_107 ;
if ( V_7 -> V_13 . V_138 )
F_29 ( & V_7 -> V_106 , & V_7 -> V_143 ,
L_44 , 0 , V_144 ) ;
if ( V_7 -> V_13 . V_145 == V_146 )
F_29 ( & V_7 -> V_106 , & V_7 -> V_143 ,
L_45 , 0 , V_147 ) ;
if ( V_7 -> V_13 . V_145 == V_148 )
F_29 ( & V_7 -> V_106 , & V_7 -> V_143 ,
L_46 , 0 , V_149 ) ;
if ( V_7 -> V_33 == V_34 ) {
struct V_150 V_151 ;
struct V_152 V_153 = {
. type = L_1 ,
. V_30 = 0xba >> 1 ,
. V_154 = & V_151 ,
} ;
V_151 . V_155 = V_7 -> V_38 ;
F_30 ( & V_7 -> V_106 , & V_7 -> V_143 ,
& V_153 , NULL ) ;
}
if ( V_7 -> V_13 . V_156 == V_157 )
F_29 ( & V_7 -> V_106 , & V_7 -> V_143 ,
L_47 , V_7 -> V_13 . V_158 , NULL ) ;
if ( V_7 -> V_13 . V_8 != V_99 ) {
int V_159 = ( V_7 -> V_110 & V_160 ) ;
if ( V_7 -> V_13 . V_104 . type )
F_29 ( & V_7 -> V_106 , & V_7 -> V_143 ,
L_48 , V_7 -> V_13 . V_105 , NULL ) ;
if ( V_159 )
F_29 ( & V_7 -> V_106 ,
& V_7 -> V_143 , L_48 ,
0 , F_31 ( V_161 ) ) ;
if ( V_7 -> V_109 == 0 ) {
enum V_162 type =
V_159 ? V_163 : V_164 ;
struct V_165 * V_166 ;
V_166 = F_29 ( & V_7 -> V_106 ,
& V_7 -> V_143 , L_48 ,
0 , F_31 ( type ) ) ;
if ( V_166 )
V_7 -> V_109 = F_32 ( V_166 ) ;
} else {
F_29 ( & V_7 -> V_106 , & V_7 -> V_143 ,
L_48 , V_7 -> V_109 , NULL ) ;
}
}
F_20 ( V_7 ) ;
}
static void F_33 ( struct V_167 * V_168 )
{
struct V_6 * V_7 = F_34 ( V_168 ,
struct V_6 , V_169 ) ;
F_35 ( V_7 ) ;
#if F_26 ( V_133 ) && F_26 ( V_134 )
if ( V_7 -> V_170 )
F_27 ( L_49 ) ;
else if ( V_7 -> V_171 )
F_27 ( L_50 ) ;
if ( V_7 -> V_13 . V_172 )
F_27 ( L_51 ) ;
if ( ( V_7 -> V_13 . V_173 || V_7 -> V_13 . V_174 ) && ! V_175 )
F_27 ( L_52 ) ;
#endif
}
static void F_36 ( struct V_6 * V_7 )
{
F_37 ( & V_7 -> V_169 , F_33 ) ;
F_38 ( & V_7 -> V_169 ) ;
}
static void F_39 ( struct V_6 * V_7 )
{
F_40 ( & V_7 -> V_169 ) ;
}
void F_41 ( struct V_6 * V_7 )
{
F_42 ( V_7 ) ;
F_43 ( V_7 ) ;
F_44 ( & V_7 -> V_176 ) ;
F_45 ( & V_7 -> V_106 ) ;
F_46 ( V_7 -> V_177 ) ;
F_47 ( V_7 -> V_178 , & V_179 ) ;
}
static int F_48 ( struct V_6 * V_7 , struct V_180 * V_177 ,
struct V_181 * V_182 ,
int V_183 )
{
struct V_184 * V_185 = & V_7 -> V_176 ;
int V_186 ;
static const char * V_187 = L_53 ;
const char * V_188 = V_187 ;
V_7 -> V_177 = V_177 ;
F_49 ( & V_7 -> V_189 ) ;
F_49 ( & V_7 -> V_190 ) ;
F_49 ( & V_7 -> V_191 ) ;
F_50 ( & V_7 -> V_192 ) ;
V_7 -> F_17 = F_17 ;
V_7 -> V_193 = V_193 ;
V_7 -> V_194 = V_194 ;
V_7 -> V_195 = V_195 ;
V_7 -> V_196 = V_196 ;
V_7 -> V_13 . V_47 = V_15 [ V_7 -> V_16 ] . V_47 ;
F_3 ( V_7 ) ;
V_7 -> V_197 = V_55 ;
V_7 -> V_198 = V_53 ;
V_7 -> V_199 = 5 ;
V_186 = V_193 ( V_7 , V_200 ) ;
if ( V_186 > 0 ) {
V_7 -> V_201 = V_186 ;
switch ( V_7 -> V_201 ) {
case V_202 :
V_188 = L_54 ;
break;
case V_203 :
V_188 = L_55 ;
break;
case V_204 :
V_188 = L_56 ;
break;
case V_205 :
V_188 = L_57 ;
break;
case V_206 :
V_188 = L_58 ;
break;
case V_207 :
V_188 = L_59 ;
break;
case V_208 :
V_188 = L_60 ;
V_7 -> V_199 = 0 ;
break;
case V_209 :
V_188 = L_61 ;
V_7 -> V_198 = V_210 ;
V_7 -> V_199 = 0 ;
break;
case V_211 :
V_188 = L_62 ;
V_7 -> V_198 = V_210 ;
V_7 -> V_199 = 0 ;
break;
case V_212 :
V_188 = L_63 ;
V_7 -> V_199 = 0 ;
break;
case V_213 :
V_188 = L_64 ;
V_7 -> V_198 = V_210 ;
V_7 -> V_199 = 0 ;
break;
default:
F_11 (KERN_INFO DRIVER_NAME
L_65 , dev->chip_id) ;
}
}
if ( V_188 != V_187 )
F_11 (KERN_INFO DRIVER_NAME
L_66 , chip_name) ;
snprintf ( V_7 -> V_45 , sizeof( V_7 -> V_45 ) , L_67 , V_188 , V_7 -> V_178 ) ;
if ( V_7 -> V_214 ) {
V_186 = F_51 ( V_7 ) ;
if ( V_186 )
return - V_215 ;
F_35 ( V_7 ) ;
return 0 ;
}
V_186 = V_193 ( V_7 , V_7 -> V_197 ) ;
if ( V_186 >= 0 )
V_7 -> V_216 = V_186 ;
F_12 ( V_7 ) ;
if ( V_7 -> V_201 == V_205 ) {
if ( V_7 -> V_13 . V_126 )
V_188 = L_55 ;
else
V_188 = L_68 ;
snprintf ( V_7 -> V_45 , sizeof( V_7 -> V_45 ) , L_67 , V_188 , V_7 -> V_178 ) ;
}
if ( ! V_7 -> V_13 . V_47 ) {
V_186 = F_14 ( V_7 , V_48 , V_7 -> V_13 . V_20 ) ;
if ( V_186 < 0 ) {
F_13 ( L_69
L_70 ,
V_217 , V_186 ) ;
return V_186 ;
}
}
V_186 = F_52 ( & V_182 -> V_7 , & V_7 -> V_106 ) ;
if ( V_186 < 0 ) {
F_13 ( L_71 ) ;
return V_186 ;
}
F_53 ( V_185 , 4 ) ;
V_7 -> V_106 . V_176 = V_185 ;
V_186 = F_54 ( V_7 ) ;
if ( V_186 < 0 ) {
F_13 ( L_72 ,
V_217 , V_186 ) ;
goto V_218;
}
V_7 -> V_39 = 0x10 ;
V_7 -> V_40 = V_219 |
V_220 ;
F_24 ( V_7 ) ;
V_186 = F_51 ( V_7 ) ;
if ( V_186 < 0 ) {
F_13 ( L_73 ,
V_217 , V_186 ) ;
goto V_221;
}
if ( V_7 -> V_222 . V_223 != V_224 ) {
F_55 ( V_185 , & V_225 ,
V_226 , 0 , 1 , 1 , 1 ) ;
F_55 ( V_185 , & V_225 ,
V_227 , 0 , 0x1f , 1 , 0x1f ) ;
} else {
F_56 ( F_57 ( V_185 , V_226 ) ,
V_228 , V_7 ) ;
F_56 ( F_57 ( V_185 , V_227 ) ,
V_228 , V_7 ) ;
}
F_58 ( V_7 ) ;
F_59 ( & V_7 -> V_229 . V_230 ) ;
F_59 ( & V_7 -> V_231 . V_230 ) ;
if ( V_7 -> V_13 . V_138 ) {
V_186 = F_14 ( V_7 , V_53 , 0xf7 ) ;
if ( V_186 < 0 ) {
F_13 ( L_74
L_75 ,
V_217 , V_186 ) ;
goto V_221;
}
F_15 ( 3 ) ;
V_186 = F_14 ( V_7 , V_53 , 0xff ) ;
if ( V_186 < 0 ) {
F_13 ( L_74
L_76 ,
V_217 , V_186 ) ;
goto V_221;
}
F_15 ( 3 ) ;
}
F_60 ( & V_7 -> V_176 ) ;
V_186 = V_7 -> V_176 . error ;
if ( V_186 )
goto V_221;
V_186 = F_61 ( V_7 ) ;
if ( V_186 < 0 ) {
goto V_221;
}
F_21 ( & V_7 -> V_106 , 0 , V_232 , V_233 , 0 ) ;
return 0 ;
V_221:
F_43 ( V_7 ) ;
F_44 ( & V_7 -> V_176 ) ;
V_218:
F_45 ( & V_7 -> V_106 ) ;
return V_186 ;
}
static int F_62 ( struct V_181 * V_182 ,
const struct V_234 * V_235 )
{
struct V_180 * V_177 ;
struct V_6 * V_7 = NULL ;
int V_186 ;
bool V_236 = false , V_237 = false , V_172 = false ;
int V_23 , V_238 , V_239 ;
const int V_240 = V_182 -> V_241 [ 0 ] . V_242 . V_243 ;
char * V_244 ;
V_177 = F_63 ( F_64 ( V_182 ) ) ;
do {
V_238 = F_65 ( & V_179 , V_245 ) ;
if ( V_238 >= V_245 ) {
F_11 ( V_246 L_77 ,
V_245 ) ;
V_186 = - V_247 ;
goto V_248;
}
} while ( F_66 ( V_238 , & V_179 ) );
if ( V_182 -> V_241 [ 0 ] . V_242 . V_249 == V_250 ) {
F_67 ( V_246 L_78
L_79 ,
F_68 ( V_177 -> V_251 . V_252 ) ,
F_68 ( V_177 -> V_251 . V_253 ) ,
V_240 ,
V_182 -> V_241 [ 0 ] . V_242 . V_249 ) ;
V_186 = - V_215 ;
goto V_254;
}
V_7 = F_69 ( sizeof( * V_7 ) , V_255 ) ;
if ( V_7 == NULL ) {
F_67 ( V_246 L_80 ) ;
V_186 = - V_247 ;
goto V_254;
}
V_7 -> V_256 =
F_70 ( sizeof( V_7 -> V_256 [ 0 ] ) *
V_182 -> V_257 , V_255 ) ;
if ( V_7 -> V_256 == NULL ) {
F_13 ( L_81 ) ;
F_71 ( V_7 ) ;
V_186 = - V_247 ;
goto V_254;
}
for ( V_23 = 0 ; V_23 < V_182 -> V_257 ; V_23 ++ ) {
int V_258 ;
for ( V_258 = 0 ; V_258 < V_182 -> V_241 [ V_23 ] . V_242 . V_259 ; V_258 ++ ) {
const struct V_260 * V_261 ;
int V_262 , V_263 ;
V_261 = & V_182 -> V_241 [ V_23 ] . V_264 [ V_258 ] . V_242 ;
V_262 = F_68 ( V_261 -> V_265 ) ;
V_263 = V_262 & 0x7ff ;
if ( V_177 -> V_244 == V_266 )
V_263 = V_263 * F_72 ( V_262 ) ;
if ( F_73 ( V_261 ) ) {
switch ( V_261 -> V_267 ) {
case 0x82 :
V_237 = true ;
if ( F_74 ( V_261 ) ) {
V_7 -> V_268 =
V_261 -> V_267 ;
V_7 -> V_256 [ V_23 ] = V_263 ;
} else if ( F_75 ( V_261 ) ) {
V_7 -> V_269 =
V_261 -> V_267 ;
}
break;
case 0x83 :
if ( F_74 ( V_261 ) ) {
V_236 = true ;
} else {
F_11 (KERN_INFO DRIVER_NAME
L_82 ) ;
}
break;
case 0x84 :
if ( V_237 &&
( F_75 ( V_261 ) ) ) {
V_7 -> V_269 =
V_261 -> V_267 ;
} else {
V_172 = true ;
if ( F_74 ( V_261 ) ) {
V_7 -> V_270 = V_261 -> V_267 ;
if ( V_263 > V_7 -> V_271 ) {
V_7 -> V_271 = V_263 ;
V_7 -> V_272 = V_23 ;
}
} else {
V_7 -> V_273 = V_261 -> V_267 ;
}
}
break;
}
}
}
}
if ( ! ( V_236 || V_237 || V_172 ) ) {
V_186 = - V_215 ;
goto V_274;
}
switch ( V_177 -> V_244 ) {
case V_275 :
V_244 = L_83 ;
break;
case V_276 :
case V_277 :
V_244 = L_84 ;
break;
case V_266 :
V_244 = L_85 ;
break;
default:
V_244 = L_86 ;
}
F_11 (KERN_INFO DRIVER_NAME
L_87
L_88 ,
udev->manufacturer ? udev->manufacturer : L_89 ,
udev->product ? udev->product : L_89 ,
speed,
le16_to_cpu(udev->descriptor.idVendor),
le16_to_cpu(udev->descriptor.idProduct),
ifnum,
interface->altsetting->desc.bInterfaceNumber) ;
if ( V_177 -> V_244 != V_266 && V_278 == 0 ) {
F_11 ( V_246 L_90 ) ;
F_11 ( V_246 L_91
L_92 ) ;
V_186 = - V_215 ;
goto V_274;
}
V_7 -> V_178 = V_238 ;
V_7 -> V_16 = V_235 -> V_279 ;
V_7 -> V_280 = - 1 ;
V_7 -> V_214 = V_236 && ! ( V_237 || V_172 ) ;
V_7 -> V_171 = V_236 ;
V_7 -> V_281 = V_240 ;
for ( V_23 = 0 ; V_23 < V_177 -> V_282 -> V_242 . V_283 ; V_23 ++ ) {
struct V_181 * V_284 = V_177 -> V_282 -> V_182 [ V_23 ] ;
if ( V_284 -> V_241 [ 0 ] . V_242 . V_249 == V_250 ) {
V_7 -> V_170 = 1 ;
break;
}
}
if ( V_236 )
F_11 (KERN_INFO DRIVER_NAME
L_93 ,
ifnum,
dev->has_audio_class ? L_94 : L_95 ) ;
if ( V_237 )
F_11 (KERN_INFO DRIVER_NAME
L_96 ,
ifnum,
dev->analog_ep_bulk ? L_97 : L_89 ,
dev->analog_ep_isoc ? L_98 : L_89 ) ;
if ( V_172 )
F_11 (KERN_INFO DRIVER_NAME
L_99 ,
ifnum,
dev->dvb_ep_bulk ? L_97 : L_89 ,
dev->dvb_ep_isoc ? L_98 : L_89 ) ;
V_7 -> V_285 = V_182 -> V_257 ;
if ( ( unsigned ) V_286 [ V_238 ] < V_125 )
V_7 -> V_16 = V_286 [ V_238 ] ;
F_76 ( V_182 , V_7 ) ;
F_77 ( V_7 ) ;
F_49 ( & V_7 -> V_287 ) ;
F_78 ( & V_7 -> V_287 ) ;
V_186 = F_48 ( V_7 , V_177 , V_182 , V_238 ) ;
if ( V_186 ) {
goto V_288;
}
if ( V_289 < 0 ) {
if ( V_7 -> V_13 . V_126 )
V_239 = 1 ;
else
V_239 = 0 ;
} else {
V_239 = V_289 > 0 ;
}
if ( V_237 ) {
if ( ! V_7 -> V_268 || ( V_239 && V_7 -> V_269 ) )
V_7 -> V_290 = 1 ;
F_25 ( L_100 ,
V_7 -> V_290 ? L_101 : L_102 ) ;
}
if ( V_172 ) {
if ( ! V_7 -> V_270 || ( V_239 && V_7 -> V_273 ) )
V_7 -> V_291 = 1 ;
F_25 ( L_103 ,
V_7 -> V_291 ? L_101 : L_102 ) ;
if ( V_7 -> V_291 ) {
V_186 = F_79 ( V_7 , V_292 ,
V_7 -> V_291 ,
V_293 ,
512 ,
V_294 ) ;
} else {
V_186 = F_79 ( V_7 , V_292 ,
V_7 -> V_291 ,
V_293 ,
V_7 -> V_271 ,
V_295 ) ;
}
if ( V_186 ) {
F_11 ( V_246
L_104 ) ;
goto V_288;
}
}
F_36 ( V_7 ) ;
F_80 ( & V_7 -> V_287 ) ;
return 0 ;
V_288:
F_80 ( & V_7 -> V_287 ) ;
V_274:
F_71 ( V_7 -> V_256 ) ;
F_71 ( V_7 ) ;
V_254:
F_47 ( V_238 , & V_179 ) ;
V_248:
F_46 ( V_177 ) ;
return V_186 ;
}
static void F_81 ( struct V_181 * V_182 )
{
struct V_6 * V_7 ;
V_7 = F_82 ( V_182 ) ;
F_76 ( V_182 , NULL ) ;
if ( ! V_7 )
return;
V_7 -> V_296 = 1 ;
if ( V_7 -> V_214 ) {
F_78 ( & V_7 -> V_287 ) ;
F_83 ( V_7 ) ;
F_80 ( & V_7 -> V_287 ) ;
return;
}
F_25 ( L_105 , V_7 -> V_297 -> V_45 ) ;
F_39 ( V_7 ) ;
F_78 ( & V_7 -> V_287 ) ;
F_84 ( & V_7 -> V_106 ) ;
if ( V_7 -> V_298 ) {
F_85 ( L_106 ,
F_86 ( V_7 -> V_297 ) ) ;
F_87 ( V_7 , V_64 ) ;
F_87 ( V_7 , V_292 ) ;
}
F_83 ( V_7 ) ;
if ( ! V_7 -> V_298 )
F_41 ( V_7 ) ;
F_80 ( & V_7 -> V_287 ) ;
if ( ! V_7 -> V_298 ) {
F_71 ( V_7 -> V_256 ) ;
F_71 ( V_7 ) ;
}
}
