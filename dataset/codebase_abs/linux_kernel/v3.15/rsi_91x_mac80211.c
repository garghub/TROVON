bool F_1 ( struct V_1 * V_2 )
{
if ( ( ( V_2 -> V_3 . V_4 == V_5 ) ||
( V_2 -> V_3 . V_4 == V_6 ) ) &&
( ! V_2 -> V_3 . V_7 ) )
return true ;
else
return false ;
}
static void F_2 ( struct V_8 * V_9 , int V_10 )
{
struct V_11 * V_12 = & V_9 -> V_12 [ V_10 ] ;
void * V_13 = NULL ;
if ( V_10 == V_14 ) {
V_13 = F_3 ( sizeof( V_15 ) , V_16 ) ;
memcpy ( V_13 ,
V_15 ,
sizeof( V_15 ) ) ;
V_12 -> V_10 = V_14 ;
V_12 -> V_17 = F_4 ( V_15 ) ;
V_12 -> V_18 = V_19 ;
V_12 -> V_20 = F_4 ( V_19 ) ;
} else {
V_13 = F_3 ( sizeof( V_21 ) , V_16 ) ;
memcpy ( V_13 ,
V_21 ,
sizeof( V_21 ) ) ;
V_12 -> V_10 = V_22 ;
V_12 -> V_17 = F_4 ( V_21 ) ;
V_12 -> V_18 = & V_19 [ 4 ] ;
V_12 -> V_20 = F_4 ( V_19 ) - 4 ;
}
V_12 -> V_13 = V_13 ;
memset ( & V_12 -> V_23 , 0 , sizeof( struct V_24 ) ) ;
V_12 -> V_23 . V_25 = true ;
V_12 -> V_23 . V_26 = ( V_27 |
V_28 |
V_29 ) ;
V_12 -> V_23 . V_30 = V_31 ;
V_12 -> V_23 . V_32 = V_33 ;
V_12 -> V_23 . V_34 . V_35 [ 0 ] = 0xff ;
V_12 -> V_23 . V_34 . V_36 = V_37 ;
}
void F_5 ( struct V_8 * V_9 )
{
struct V_38 * V_39 = V_9 -> V_39 ;
if ( V_39 ) {
F_6 ( V_39 ) ;
F_7 ( V_39 ) ;
F_8 ( V_39 ) ;
}
F_9 ( V_9 ) ;
}
void F_10 ( struct V_8 * V_9 ,
struct V_40 * V_41 ,
int V_42 )
{
struct V_43 * V_44 = F_11 ( V_41 ) ;
memset ( V_44 -> V_45 , 0 , V_46 ) ;
if ( ! V_42 )
V_44 -> V_47 |= V_48 ;
F_12 ( V_9 -> V_39 , V_41 ) ;
}
static void F_13 ( struct V_38 * V_39 ,
struct V_49 * V_50 ,
struct V_40 * V_41 )
{
struct V_8 * V_9 = V_39 -> V_51 ;
struct V_1 * V_2 = V_9 -> V_51 ;
F_14 ( V_2 , V_41 ) ;
}
static int F_15 ( struct V_38 * V_39 )
{
struct V_8 * V_9 = V_39 -> V_51 ;
struct V_1 * V_2 = V_9 -> V_51 ;
F_16 ( & V_2 -> V_52 ) ;
V_2 -> V_53 = false ;
F_17 ( & V_2 -> V_52 ) ;
return 0 ;
}
static void F_18 ( struct V_38 * V_39 )
{
struct V_8 * V_9 = V_39 -> V_51 ;
struct V_1 * V_2 = V_9 -> V_51 ;
F_16 ( & V_2 -> V_52 ) ;
V_2 -> V_53 = true ;
F_17 ( & V_2 -> V_52 ) ;
}
static int F_19 ( struct V_38 * V_39 ,
struct V_54 * V_55 )
{
struct V_8 * V_9 = V_39 -> V_51 ;
struct V_1 * V_2 = V_9 -> V_51 ;
int V_56 = - V_57 ;
F_16 ( & V_2 -> V_52 ) ;
switch ( V_55 -> type ) {
case V_58 :
if ( ! V_9 -> V_59 ) {
++ V_9 -> V_59 ;
V_9 -> V_60 [ 0 ] = V_55 ;
V_56 = F_20 ( V_2 , V_61 ) ;
}
break;
default:
F_21 ( V_62 ,
L_1 , V_63 ,
V_55 -> type ) ;
}
F_17 ( & V_2 -> V_52 ) ;
return V_56 ;
}
static void F_22 ( struct V_38 * V_39 ,
struct V_54 * V_55 )
{
struct V_8 * V_9 = V_39 -> V_51 ;
struct V_1 * V_2 = V_9 -> V_51 ;
F_16 ( & V_2 -> V_52 ) ;
if ( V_55 -> type == V_58 )
V_9 -> V_59 -- ;
if ( ! memcmp ( V_9 -> V_60 [ 0 ] , V_55 , sizeof( struct V_54 ) ) )
V_9 -> V_60 [ 0 ] = NULL ;
F_17 ( & V_2 -> V_52 ) ;
}
static int F_23 ( struct V_38 * V_39 ,
T_1 V_64 )
{
struct V_8 * V_9 = V_39 -> V_51 ;
struct V_1 * V_2 = V_9 -> V_51 ;
int V_42 = - V_57 ;
F_16 ( & V_2 -> V_52 ) ;
if ( V_64 & V_65 ) {
struct V_66 * V_67 = V_39 -> V_68 . V_69 . V_70 ;
T_2 V_71 = V_67 -> V_72 ;
F_21 ( V_73 ,
L_2 ,
V_63 , V_67 -> V_74 ,
V_67 -> V_47 , V_71 ) ;
V_2 -> V_10 = V_67 -> V_10 ;
V_42 = F_24 ( V_9 -> V_51 , V_71 ) ;
}
F_17 ( & V_2 -> V_52 ) ;
return V_42 ;
}
T_2 F_25 ( struct V_8 * V_9 )
{
struct V_54 * V_55 = V_9 -> V_60 [ 0 ] ;
if ( V_55 ) {
struct V_75 * V_76 = & V_55 -> V_77 ;
struct V_66 * V_71 = V_76 -> V_69 . V_70 ;
return V_71 -> V_72 ;
}
return 0 ;
}
static void F_26 ( struct V_38 * V_39 ,
struct V_54 * V_55 ,
struct V_75 * V_77 ,
T_1 V_64 )
{
struct V_8 * V_9 = V_39 -> V_51 ;
struct V_1 * V_2 = V_9 -> V_51 ;
F_16 ( & V_2 -> V_52 ) ;
if ( V_64 & V_78 ) {
F_21 ( V_73 , L_3 ,
V_63 , V_77 -> V_79 ) ;
F_27 ( V_2 ,
V_77 -> V_79 ,
V_77 -> V_80 ,
V_77 -> V_81 ,
V_77 -> V_82 ) ;
}
F_17 ( & V_2 -> V_52 ) ;
}
static void F_28 ( struct V_38 * V_39 ,
T_1 V_83 ,
T_1 * V_84 ,
T_3 V_85 )
{
* V_84 &= V_86 ;
}
static int F_29 ( struct V_38 * V_39 ,
struct V_54 * V_55 , T_2 V_87 ,
const struct V_88 * V_89 )
{
struct V_8 * V_9 = V_39 -> V_51 ;
struct V_1 * V_2 = V_9 -> V_51 ;
T_4 V_90 = 0 ;
if ( V_87 >= V_91 )
return 0 ;
F_21 ( V_73 ,
L_4 ,
V_63 , V_87 , V_89 -> V_92 ,
V_89 -> V_93 , V_89 -> V_94 , V_89 -> V_95 ) ;
F_16 ( & V_2 -> V_52 ) ;
switch ( V_87 ) {
case V_96 :
V_90 = V_97 ;
break;
case V_98 :
V_90 = V_99 ;
break;
case V_100 :
V_90 = V_101 ;
break;
case V_102 :
V_90 = V_103 ;
break;
default:
V_90 = V_101 ;
break;
}
memcpy ( & V_2 -> V_104 [ V_90 ] ,
V_89 ,
sizeof( struct V_88 ) ) ;
F_17 ( & V_2 -> V_52 ) ;
return 0 ;
}
static int F_30 ( struct V_38 * V_39 ,
struct V_54 * V_55 ,
struct V_105 * V_106 )
{
struct V_8 * V_9 = V_39 -> V_51 ;
int V_42 ;
T_4 V_107 ;
if ( V_106 -> V_47 & V_108 )
V_107 = V_109 ;
else
V_107 = V_110 ;
F_21 ( V_62 , L_5 ,
V_63 , V_106 -> V_111 , V_107 , V_106 -> V_112 ) ;
if ( ( V_106 -> V_111 == V_5 ) ||
( V_106 -> V_111 == V_6 ) ) {
V_42 = F_31 ( V_9 -> V_51 ,
V_106 -> V_106 ,
V_106 -> V_112 ,
V_109 ,
V_106 -> V_113 ,
V_106 -> V_111 ) ;
if ( V_42 )
return V_42 ;
}
return F_31 ( V_9 -> V_51 ,
V_106 -> V_106 ,
V_106 -> V_112 ,
V_107 ,
V_106 -> V_113 ,
V_106 -> V_111 ) ;
}
static int F_32 ( struct V_38 * V_39 ,
enum V_114 V_115 ,
struct V_54 * V_55 ,
struct V_116 * V_117 ,
struct V_105 * V_106 )
{
struct V_8 * V_9 = V_39 -> V_51 ;
struct V_1 * V_2 = V_9 -> V_51 ;
struct V_118 * V_3 = & V_2 -> V_3 ;
int V_42 ;
F_16 ( & V_2 -> V_52 ) ;
switch ( V_115 ) {
case V_119 :
V_3 -> V_120 = true ;
V_42 = F_30 ( V_39 , V_55 , V_106 ) ;
if ( V_42 ) {
F_17 ( & V_2 -> V_52 ) ;
return V_42 ;
}
if ( V_106 -> V_47 & V_108 )
V_3 -> V_7 = V_106 -> V_111 ;
else
V_3 -> V_4 = V_106 -> V_111 ;
V_106 -> V_121 = V_106 -> V_113 ;
V_106 -> V_47 |= V_122 ;
F_21 ( V_62 , L_6 , V_63 ) ;
break;
case V_123 :
V_3 -> V_120 = false ;
F_21 ( V_62 , L_7 , V_63 ) ;
memset ( V_106 , 0 , sizeof( struct V_105 ) ) ;
V_42 = F_30 ( V_39 , V_55 , V_106 ) ;
break;
default:
V_42 = - V_57 ;
break;
}
F_17 ( & V_2 -> V_52 ) ;
return V_42 ;
}
static int F_33 ( struct V_38 * V_39 ,
struct V_54 * V_55 ,
enum V_124 V_125 ,
struct V_116 * V_117 ,
unsigned short V_126 ,
unsigned short * V_127 ,
unsigned char V_128 )
{
int V_42 = - V_57 ;
struct V_8 * V_9 = V_39 -> V_51 ;
struct V_1 * V_2 = V_9 -> V_51 ;
T_2 V_129 = 0 ;
T_4 V_130 = 0 ;
for ( V_130 = 0 ; V_130 < V_131 ; V_130 ++ ) {
if ( V_55 == V_9 -> V_60 [ V_130 ] )
break;
}
F_16 ( & V_2 -> V_52 ) ;
F_21 ( V_73 , L_8 , V_63 , V_125 ) ;
if ( V_127 != NULL )
V_129 = * V_127 ;
switch ( V_125 ) {
case V_132 :
V_42 = F_34 ( V_2 ,
V_126 ,
V_129 ,
V_128 ,
V_133 ) ;
break;
case V_134 :
V_42 = F_34 ( V_2 ,
V_126 ,
0 ,
V_128 ,
V_135 ) ;
break;
case V_136 :
V_2 -> V_137 [ V_130 ] . V_138 = V_129 ;
F_35 ( V_55 , V_117 -> V_139 , V_126 ) ;
break;
case V_140 :
case V_141 :
case V_142 :
V_42 = F_34 ( V_2 ,
V_126 ,
V_129 ,
V_128 ,
V_143 ) ;
if ( ! V_42 )
F_36 ( V_55 , V_117 -> V_139 , V_126 ) ;
break;
case V_144 :
V_42 = F_34 ( V_2 ,
V_126 ,
V_2 -> V_137 [ V_130 ]
. V_138 ,
V_128 ,
V_145 ) ;
break;
default:
F_21 ( V_62 , L_9 , V_63 ) ;
break;
}
F_17 ( & V_2 -> V_52 ) ;
return V_42 ;
}
static int F_37 ( struct V_38 * V_39 ,
T_1 V_146 )
{
struct V_8 * V_9 = V_39 -> V_51 ;
struct V_1 * V_2 = V_9 -> V_51 ;
F_16 ( & V_2 -> V_52 ) ;
V_2 -> V_147 = V_146 ;
F_17 ( & V_2 -> V_52 ) ;
return 0 ;
}
static int F_38 ( struct V_38 * V_39 ,
struct V_54 * V_55 ,
const struct V_148 * V_149 )
{
struct V_8 * V_9 = V_39 -> V_51 ;
struct V_1 * V_2 = V_9 -> V_51 ;
F_16 ( & V_2 -> V_52 ) ;
V_2 -> V_150 [ V_14 ] = 0 ;
if ( V_149 -> V_50 [ V_14 ] . V_151 == 0xfff ) {
V_2 -> V_150 [ V_14 ] =
( V_149 -> V_50 [ V_14 ] . V_152 [ 0 ] << 12 ) ;
} else {
V_2 -> V_150 [ V_14 ] =
V_149 -> V_50 [ V_14 ] . V_151 ;
}
F_17 ( & V_2 -> V_52 ) ;
return 0 ;
}
static void F_39 ( struct V_38 * V_39 ,
struct V_40 * V_41 ,
struct V_1 * V_2 ,
struct V_153 * V_154 )
{
struct V_43 * V_44 = F_11 ( V_41 ) ;
struct V_155 * V_156 = (struct V_155 * ) V_44 -> V_45 ;
struct V_157 * V_158 ;
char V_159 = V_156 -> V_159 ;
T_4 V_160 = 0 ;
T_4 V_71 = V_156 -> V_71 ;
T_5 V_161 ;
V_158 = ( (struct V_157 * ) ( V_41 -> V_162 ) ) ;
V_160 = F_40 ( V_158 -> V_163 ) ;
memset ( V_44 , 0 , sizeof( struct V_43 ) ) ;
V_154 -> signal = - ( V_159 ) ;
if ( V_71 <= 14 )
V_154 -> V_10 = V_14 ;
else
V_154 -> V_10 = V_22 ;
V_161 = F_41 ( V_71 , V_154 -> V_10 ) ;
if ( V_161 )
V_154 -> V_161 = V_161 ;
if ( F_42 ( V_158 -> V_163 ) ) {
if ( F_1 ( V_2 ) ) {
memmove ( V_41 -> V_162 + 4 , V_41 -> V_162 , V_160 ) ;
F_43 ( V_41 , 4 ) ;
} else {
memmove ( V_41 -> V_162 + 8 , V_41 -> V_162 , V_160 ) ;
F_43 ( V_41 , 8 ) ;
V_154 -> V_164 |= V_165 ;
}
V_154 -> V_164 |= V_166 ;
V_154 -> V_164 |= V_167 ;
}
}
void F_44 ( struct V_1 * V_2 ,
struct V_40 * V_41 )
{
struct V_8 * V_9 = V_2 -> V_51 ;
struct V_38 * V_39 = V_9 -> V_39 ;
struct V_153 * V_168 = F_45 ( V_41 ) ;
if ( ( V_2 -> V_53 ) || ( ! V_9 -> V_59 ) ) {
F_46 ( V_41 ) ;
return;
}
F_39 ( V_39 , V_41 , V_2 , V_168 ) ;
F_47 ( V_39 , V_41 ) ;
}
static void F_48 ( struct V_38 * V_39 ,
struct V_116 * V_117 ,
struct V_1 * V_2 )
{
T_4 V_10 = V_39 -> V_68 . V_69 . V_70 -> V_10 ;
T_4 V_130 ;
T_1 V_169 ;
bool V_170 = false ;
V_2 -> V_171 [ V_10 ] = V_117 -> V_172 [ V_10 ] ;
V_169 = ( V_2 -> V_150 [ V_10 ] & V_117 -> V_172 [ V_10 ] ) ;
if ( V_169 & 0xfff ) {
for ( V_130 = 0 ; V_130 < F_4 ( V_19 ) ; V_130 ++ ) {
if ( V_169 & F_49 ( V_130 ) ) {
V_2 -> V_173 = V_19 [ V_130 ] . V_72 ;
V_170 = true ;
break;
}
}
}
V_2 -> V_137 [ 0 ] . V_174 = V_117 -> V_23 . V_25 ;
if ( ( V_2 -> V_137 [ 0 ] . V_174 ) && ( V_169 >> 12 ) ) {
for ( V_130 = 0 ; V_130 < F_4 ( V_175 ) ; V_130 ++ ) {
if ( ( V_169 >> 12 ) & F_49 ( V_130 ) ) {
V_2 -> V_173 = V_175 [ V_130 ] ;
V_170 = true ;
break;
}
}
}
if ( ! V_170 )
V_2 -> V_173 = 0xffff ;
}
static int F_50 ( struct V_38 * V_39 ,
struct V_54 * V_55 ,
struct V_116 * V_117 )
{
struct V_8 * V_9 = V_39 -> V_51 ;
struct V_1 * V_2 = V_9 -> V_51 ;
F_16 ( & V_2 -> V_52 ) ;
F_48 ( V_39 , V_117 , V_2 ) ;
if ( ( V_117 -> V_23 . V_26 & V_28 ) ||
( V_117 -> V_23 . V_26 & V_29 ) ) {
V_2 -> V_137 [ 0 ] . V_176 = true ;
}
if ( V_117 -> V_23 . V_25 )
F_51 ( V_117 , 0 , 0 ) ;
F_17 ( & V_2 -> V_52 ) ;
return 0 ;
}
static int F_52 ( struct V_38 * V_39 ,
struct V_54 * V_55 ,
struct V_116 * V_117 )
{
struct V_8 * V_9 = V_39 -> V_51 ;
struct V_1 * V_2 = V_9 -> V_51 ;
F_16 ( & V_2 -> V_52 ) ;
V_2 -> V_171 [ V_14 ] = 0 ;
V_2 -> V_171 [ V_22 ] = 0 ;
V_2 -> V_173 = 0xffff ;
V_2 -> V_137 [ 0 ] . V_174 = false ;
V_2 -> V_137 [ 0 ] . V_176 = false ;
V_2 -> V_137 [ 0 ] . V_138 = 0 ;
V_2 -> V_3 . V_7 = 0 ;
V_2 -> V_3 . V_4 = 0 ;
F_17 ( & V_2 -> V_52 ) ;
return 0 ;
}
int F_53 ( struct V_1 * V_2 )
{
int V_42 = 0 ;
struct V_38 * V_39 = NULL ;
struct V_177 * V_177 = NULL ;
struct V_8 * V_9 = V_2 -> V_51 ;
T_4 V_178 [ V_179 ] = { 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x3 } ;
F_21 ( V_180 , L_10 , V_63 ) ;
V_39 = F_54 ( sizeof( struct V_8 ) , & V_181 ) ;
if ( ! V_39 ) {
F_21 ( V_62 , L_11 , V_63 ) ;
return - V_182 ;
}
V_177 = V_39 -> V_177 ;
F_55 ( V_39 , V_9 -> V_183 ) ;
V_39 -> V_51 = V_9 ;
V_9 -> V_39 = V_39 ;
V_39 -> V_47 = V_184 |
V_185 |
V_186 |
0 ;
V_39 -> V_187 = V_188 ;
V_39 -> V_189 = V_190 ;
V_39 -> V_191 = 1 ;
V_39 -> V_192 = V_193 ;
V_39 -> V_194 = 6 ;
F_2 ( V_9 , V_14 ) ;
V_39 -> V_195 = L_12 ;
F_56 ( V_39 , V_2 -> V_196 ) ;
F_57 ( V_39 -> V_177 -> V_178 , V_178 ) ;
V_177 -> V_197 = F_49 ( V_58 ) ;
V_177 -> V_198 = V_199 ;
V_177 -> V_200 = V_201 ;
V_177 -> V_202 = V_203 ;
V_177 -> V_204 = V_205 ;
V_177 -> V_147 = V_206 ;
V_177 -> V_47 = 0 ;
V_177 -> V_207 = 1 ;
V_177 -> V_208 = 1 ;
V_177 -> V_209 [ V_14 ] =
& V_9 -> V_12 [ V_14 ] ;
V_42 = F_58 ( V_39 ) ;
if ( V_42 )
return V_42 ;
return F_59 ( V_9 ) ;
}
