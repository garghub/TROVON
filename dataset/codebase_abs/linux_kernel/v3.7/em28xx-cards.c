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
if ( V_7 -> V_13 . V_173 && ! V_174 )
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
F_44 ( & V_7 -> V_106 ) ;
F_45 ( V_7 -> V_175 ) ;
F_46 ( V_7 -> V_176 , & V_177 ) ;
}
static int F_47 ( struct V_6 * V_7 , struct V_178 * V_175 ,
struct V_179 * V_180 ,
int V_181 )
{
int V_182 ;
V_7 -> V_175 = V_175 ;
F_48 ( & V_7 -> V_183 ) ;
F_49 ( & V_7 -> V_184 ) ;
V_7 -> F_17 = F_17 ;
V_7 -> V_185 = V_185 ;
V_7 -> V_186 = V_186 ;
V_7 -> V_187 = V_187 ;
V_7 -> V_188 = V_188 ;
V_7 -> V_13 . V_47 = V_15 [ V_7 -> V_16 ] . V_47 ;
F_3 ( V_7 ) ;
V_7 -> V_189 = V_55 ;
V_7 -> V_190 = V_53 ;
V_7 -> V_191 = 5 ;
V_182 = V_185 ( V_7 , V_192 ) ;
if ( V_182 > 0 ) {
V_7 -> V_193 = V_182 ;
switch ( V_7 -> V_193 ) {
case V_194 :
F_25 ( L_53 ) ;
break;
case V_195 :
F_25 ( L_54 ) ;
break;
case V_196 :
F_25 ( L_55 ) ;
break;
case V_197 :
F_25 ( L_56 ) ;
break;
case V_198 :
F_25 ( L_57 ) ;
break;
case V_199 :
F_25 ( L_58 ) ;
break;
case V_200 :
F_25 ( L_59 ) ;
V_7 -> V_191 = 0 ;
break;
case V_201 :
F_25 ( L_60 ) ;
V_7 -> V_190 = V_202 ;
V_7 -> V_191 = 0 ;
break;
case V_203 :
F_25 ( L_61 ) ;
V_7 -> V_190 = V_202 ;
V_7 -> V_191 = 0 ;
break;
case V_204 :
F_25 ( L_62 ) ;
V_7 -> V_191 = 0 ;
break;
case V_205 :
F_25 ( L_63 ) ;
V_7 -> V_190 = V_202 ;
V_7 -> V_191 = 0 ;
break;
default:
F_25 ( L_64 , V_7 -> V_193 ) ;
}
}
if ( V_7 -> V_206 ) {
V_182 = F_50 ( V_7 ) ;
if ( V_182 )
return - V_207 ;
F_35 ( V_7 ) ;
return 0 ;
}
V_182 = V_185 ( V_7 , V_7 -> V_189 ) ;
if ( V_182 >= 0 )
V_7 -> V_208 = V_182 ;
F_12 ( V_7 ) ;
if ( ! V_7 -> V_13 . V_47 ) {
V_182 = F_14 ( V_7 , V_48 , V_7 -> V_13 . V_20 ) ;
if ( V_182 < 0 ) {
F_13 ( L_65
L_66 ,
V_209 , V_182 ) ;
return V_182 ;
}
}
V_182 = F_51 ( & V_180 -> V_7 , & V_7 -> V_106 ) ;
if ( V_182 < 0 ) {
F_13 ( L_67 ) ;
return V_182 ;
}
V_182 = F_52 ( V_7 ) ;
if ( V_182 < 0 ) {
F_13 ( L_68 ,
V_209 , V_182 ) ;
goto V_210;
}
V_7 -> V_39 = 0x10 ;
V_7 -> V_40 = V_211 |
V_212 ;
F_24 ( V_7 ) ;
V_182 = F_50 ( V_7 ) ;
if ( V_182 < 0 ) {
F_13 ( L_69 ,
V_209 , V_182 ) ;
goto V_213;
}
F_53 ( V_7 ) ;
F_54 ( & V_7 -> V_214 . V_215 ) ;
F_54 ( & V_7 -> V_216 . V_215 ) ;
if ( V_7 -> V_13 . V_138 ) {
V_182 = F_14 ( V_7 , V_53 , 0xf7 ) ;
if ( V_182 < 0 ) {
F_13 ( L_70
L_71 ,
V_209 , V_182 ) ;
goto V_213;
}
F_15 ( 3 ) ;
V_182 = F_14 ( V_7 , V_53 , 0xff ) ;
if ( V_182 < 0 ) {
F_13 ( L_70
L_72 ,
V_209 , V_182 ) ;
goto V_213;
}
F_15 ( 3 ) ;
}
V_182 = F_55 ( V_7 ) ;
if ( V_182 < 0 ) {
goto V_213;
}
F_21 ( & V_7 -> V_106 , 0 , V_217 , V_218 , 0 ) ;
return 0 ;
V_213:
F_43 ( V_7 ) ;
V_210:
F_44 ( & V_7 -> V_106 ) ;
return V_182 ;
}
static int F_56 ( struct V_179 * V_180 ,
const struct V_219 * V_220 )
{
struct V_178 * V_175 ;
struct V_6 * V_7 = NULL ;
int V_182 ;
bool V_221 = false , V_222 = false , V_172 = false ;
int V_23 , V_223 ;
const int V_224 = V_180 -> V_225 [ 0 ] . V_226 . V_227 ;
char * V_228 ;
V_175 = F_57 ( F_58 ( V_180 ) ) ;
do {
V_223 = F_59 ( & V_177 , V_229 ) ;
if ( V_223 >= V_229 ) {
F_11 ( V_230 L_73 ,
V_229 ) ;
V_182 = - V_231 ;
goto V_232;
}
} while ( F_60 ( V_223 , & V_177 ) );
if ( V_180 -> V_225 [ 0 ] . V_226 . V_233 == V_234 ) {
F_61 ( V_230 L_74
L_75 ,
F_62 ( V_175 -> V_235 . V_236 ) ,
F_62 ( V_175 -> V_235 . V_237 ) ,
V_224 ,
V_180 -> V_225 [ 0 ] . V_226 . V_233 ) ;
V_182 = - V_207 ;
goto V_238;
}
V_7 = F_63 ( sizeof( * V_7 ) , V_239 ) ;
if ( V_7 == NULL ) {
F_61 ( V_230 L_76 ) ;
V_182 = - V_231 ;
goto V_238;
}
V_7 -> V_240 = F_64 ( sizeof( V_7 -> V_240 [ 0 ] ) *
V_180 -> V_241 , V_239 ) ;
if ( V_7 -> V_240 == NULL ) {
F_13 ( L_77 ) ;
F_65 ( V_7 ) ;
V_182 = - V_231 ;
goto V_238;
}
for ( V_23 = 0 ; V_23 < V_180 -> V_241 ; V_23 ++ ) {
int V_242 ;
for ( V_242 = 0 ; V_242 < V_180 -> V_225 [ V_23 ] . V_226 . V_243 ; V_242 ++ ) {
const struct V_244 * V_245 ;
int V_246 , V_247 ;
V_245 = & V_180 -> V_225 [ V_23 ] . V_248 [ V_242 ] . V_226 ;
V_246 = F_62 ( V_245 -> V_249 ) ;
V_247 = V_246 & 0x7ff ;
if ( V_175 -> V_228 == V_250 )
V_247 = V_247 * F_66 ( V_246 ) ;
if ( F_67 ( V_245 ) &&
F_68 ( V_245 ) ) {
switch ( V_245 -> V_251 ) {
case V_252 :
V_221 = true ;
break;
case V_253 :
V_222 = true ;
V_7 -> V_240 [ V_23 ] = V_247 ;
break;
case V_254 :
V_172 = true ;
if ( V_247 > V_7 -> V_255 ) {
V_7 -> V_255 = V_247 ;
V_7 -> V_256 = V_23 ;
}
break;
}
}
}
}
if ( ! ( V_221 || V_222 || V_172 ) ) {
V_182 = - V_207 ;
goto V_257;
}
switch ( V_175 -> V_228 ) {
case V_258 :
V_228 = L_78 ;
break;
case V_259 :
case V_260 :
V_228 = L_79 ;
break;
case V_250 :
V_228 = L_80 ;
break;
default:
V_228 = L_81 ;
}
F_11 (KERN_INFO DRIVER_NAME
L_82
L_83 ,
udev->manufacturer ? udev->manufacturer : L_84 ,
udev->product ? udev->product : L_84 ,
speed,
le16_to_cpu(udev->descriptor.idVendor),
le16_to_cpu(udev->descriptor.idProduct),
ifnum,
interface->altsetting->desc.bInterfaceNumber) ;
if ( V_221 )
F_11 (KERN_INFO DRIVER_NAME
L_85 ,
ifnum) ;
if ( V_222 )
F_11 (KERN_INFO DRIVER_NAME
L_86 ,
ifnum) ;
if ( V_172 )
F_11 (KERN_INFO DRIVER_NAME
L_87 ,
ifnum) ;
if ( V_175 -> V_228 != V_250 && V_261 == 0 ) {
F_11 ( V_230 L_88 ) ;
F_11 ( V_230 L_89
L_90 ) ;
V_182 = - V_207 ;
goto V_257;
}
snprintf ( V_7 -> V_45 , sizeof( V_7 -> V_45 ) , L_91 , V_223 ) ;
V_7 -> V_176 = V_223 ;
V_7 -> V_16 = V_220 -> V_262 ;
V_7 -> V_263 = - 1 ;
V_7 -> V_206 = V_221 && ! ( V_222 || V_172 ) ;
V_7 -> V_171 = V_221 ;
V_7 -> V_264 = V_224 ;
for ( V_23 = 0 ; V_23 < V_175 -> V_265 -> V_226 . V_266 ; V_23 ++ ) {
struct V_179 * V_267 = V_175 -> V_265 -> V_180 [ V_23 ] ;
if ( V_267 -> V_225 [ 0 ] . V_226 . V_233 == V_234 ) {
V_7 -> V_170 = 1 ;
break;
}
}
V_7 -> V_268 = V_180 -> V_241 ;
if ( ( V_269 [ V_223 ] >= 0 ) && ( V_269 [ V_223 ] < V_125 ) )
V_7 -> V_16 = V_269 [ V_223 ] ;
F_69 ( V_180 , V_7 ) ;
F_48 ( & V_7 -> V_270 ) ;
F_70 ( & V_7 -> V_270 ) ;
V_182 = F_47 ( V_7 , V_175 , V_180 , V_223 ) ;
if ( V_182 ) {
goto V_271;
}
if ( V_172 ) {
V_182 = F_71 ( V_7 , V_272 ,
V_273 ,
V_274 ,
V_7 -> V_255 ) ;
if ( V_182 ) {
goto V_271;
}
}
F_36 ( V_7 ) ;
F_72 ( & V_7 -> V_270 ) ;
return 0 ;
V_271:
F_72 ( & V_7 -> V_270 ) ;
V_257:
F_65 ( V_7 -> V_240 ) ;
F_65 ( V_7 ) ;
V_238:
F_46 ( V_223 , & V_177 ) ;
V_232:
F_45 ( V_175 ) ;
return V_182 ;
}
static void F_73 ( struct V_179 * V_180 )
{
struct V_6 * V_7 ;
V_7 = F_74 ( V_180 ) ;
F_69 ( V_180 , NULL ) ;
if ( ! V_7 )
return;
if ( V_7 -> V_206 ) {
F_70 ( & V_7 -> V_270 ) ;
F_75 ( V_7 ) ;
F_72 ( & V_7 -> V_270 ) ;
return;
}
F_25 ( L_92 , V_7 -> V_275 -> V_45 ) ;
F_39 ( V_7 ) ;
F_70 ( & V_7 -> V_270 ) ;
F_76 ( & V_7 -> V_106 ) ;
if ( V_7 -> V_276 ) {
F_77
( L_93
L_94 ,
F_78 ( V_7 -> V_275 ) ) ;
V_7 -> V_277 |= V_278 ;
F_79 ( V_7 , V_7 -> V_279 ) ;
V_7 -> V_277 |= V_280 ;
} else {
V_7 -> V_277 |= V_280 ;
F_41 ( V_7 ) ;
}
F_79 ( V_7 , V_272 ) ;
F_72 ( & V_7 -> V_270 ) ;
F_75 ( V_7 ) ;
if ( ! V_7 -> V_276 ) {
F_65 ( V_7 -> V_240 ) ;
F_65 ( V_7 ) ;
}
}
