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
static int F_23 ( struct V_38 * V_39 )
{
struct V_8 * V_9 = V_39 -> V_51 ;
struct V_1 * V_2 = V_9 -> V_51 ;
int V_42 = - V_57 ;
struct V_64 * V_65 = V_39 -> V_66 . V_67 . V_68 ;
T_1 V_69 = V_65 -> V_70 ;
struct V_71 * V_72 = & V_9 -> V_60 [ 0 ] -> V_73 ;
F_21 ( V_74 ,
L_2 ,
V_63 , V_65 -> V_75 ,
V_65 -> V_47 , V_69 ) ;
if ( V_72 -> V_76 ) {
if ( ! V_2 -> V_77 &&
( F_24 ( V_9 ) != V_69 ) ) {
F_21 ( V_74 , L_3 , V_69 ) ;
if ( ! F_25 ( V_2 , true ) )
V_2 -> V_77 = true ;
}
}
V_42 = F_26 ( V_2 ) ;
if ( ! V_42 )
V_42 = F_27 ( V_9 -> V_51 , V_69 ) ;
if ( V_72 -> V_76 ) {
if ( V_2 -> V_77 &&
( F_24 ( V_9 ) == V_69 ) ) {
F_21 ( V_74 , L_4 , V_69 ) ;
if ( ! F_25 ( V_2 , false ) )
V_2 -> V_77 = false ;
}
} else {
if ( V_2 -> V_77 ) {
F_21 ( V_74 , L_4 , V_69 ) ;
if ( ! F_25 ( V_2 , false ) )
V_2 -> V_77 = false ;
}
}
return V_42 ;
}
static int F_28 ( struct V_38 * V_39 ,
T_2 V_78 )
{
struct V_8 * V_9 = V_39 -> V_51 ;
struct V_1 * V_2 = V_9 -> V_51 ;
int V_42 = - V_57 ;
F_16 ( & V_2 -> V_52 ) ;
if ( V_78 & V_79 )
V_42 = F_23 ( V_39 ) ;
F_17 ( & V_2 -> V_52 ) ;
return V_42 ;
}
T_1 F_24 ( struct V_8 * V_9 )
{
struct V_54 * V_55 = V_9 -> V_60 [ 0 ] ;
if ( V_55 ) {
struct V_71 * V_72 = & V_55 -> V_73 ;
struct V_64 * V_69 = V_72 -> V_67 . V_68 ;
return V_69 -> V_70 ;
}
return 0 ;
}
static void F_29 ( struct V_38 * V_39 ,
struct V_54 * V_55 ,
struct V_71 * V_73 ,
T_2 V_78 )
{
struct V_8 * V_9 = V_39 -> V_51 ;
struct V_1 * V_2 = V_9 -> V_51 ;
F_16 ( & V_2 -> V_52 ) ;
if ( V_78 & V_80 ) {
F_21 ( V_74 , L_5 ,
V_63 , V_73 -> V_76 ) ;
F_30 ( V_2 ,
V_73 -> V_76 ,
V_73 -> V_81 ,
V_73 -> V_82 ,
V_73 -> V_83 ) ;
}
if ( V_78 & V_84 ) {
V_2 -> V_85 . V_86 = 0 ;
V_2 -> V_85 . V_87 = V_73 -> V_88 ;
V_2 -> V_85 . V_89 = V_73 -> V_90 ;
F_21 ( V_74 , L_6 ,
V_2 -> V_85 . V_87 ,
V_2 -> V_85 . V_89 ) ;
}
F_17 ( & V_2 -> V_52 ) ;
}
static void F_31 ( struct V_38 * V_39 ,
T_2 V_91 ,
T_2 * V_92 ,
T_3 V_93 )
{
* V_92 &= V_94 ;
}
static int F_32 ( struct V_38 * V_39 ,
struct V_54 * V_55 , T_1 V_95 ,
const struct V_96 * V_97 )
{
struct V_8 * V_9 = V_39 -> V_51 ;
struct V_1 * V_2 = V_9 -> V_51 ;
T_4 V_98 = 0 ;
if ( V_95 >= V_99 )
return 0 ;
F_21 ( V_74 ,
L_7 ,
V_63 , V_95 , V_97 -> V_100 ,
V_97 -> V_101 , V_97 -> V_102 , V_97 -> V_103 ) ;
F_16 ( & V_2 -> V_52 ) ;
switch ( V_95 ) {
case V_104 :
V_98 = V_105 ;
break;
case V_106 :
V_98 = V_107 ;
break;
case V_108 :
V_98 = V_109 ;
break;
case V_110 :
V_98 = V_111 ;
break;
default:
V_98 = V_109 ;
break;
}
memcpy ( & V_2 -> V_112 [ V_98 ] ,
V_97 ,
sizeof( struct V_96 ) ) ;
F_17 ( & V_2 -> V_52 ) ;
return 0 ;
}
static int F_33 ( struct V_38 * V_39 ,
struct V_54 * V_55 ,
struct V_113 * V_114 )
{
struct V_8 * V_9 = V_39 -> V_51 ;
int V_42 ;
T_4 V_115 ;
if ( V_114 -> V_47 & V_116 )
V_115 = V_117 ;
else
V_115 = V_118 ;
F_21 ( V_62 , L_8 ,
V_63 , V_114 -> V_119 , V_115 , V_114 -> V_120 ) ;
if ( ( V_114 -> V_119 == V_5 ) ||
( V_114 -> V_119 == V_6 ) ) {
V_42 = F_34 ( V_9 -> V_51 ,
V_114 -> V_114 ,
V_114 -> V_120 ,
V_117 ,
V_114 -> V_121 ,
V_114 -> V_119 ) ;
if ( V_42 )
return V_42 ;
}
return F_34 ( V_9 -> V_51 ,
V_114 -> V_114 ,
V_114 -> V_120 ,
V_115 ,
V_114 -> V_121 ,
V_114 -> V_119 ) ;
}
static int F_35 ( struct V_38 * V_39 ,
enum V_122 V_123 ,
struct V_54 * V_55 ,
struct V_124 * V_125 ,
struct V_113 * V_114 )
{
struct V_8 * V_9 = V_39 -> V_51 ;
struct V_1 * V_2 = V_9 -> V_51 ;
struct V_126 * V_3 = & V_2 -> V_3 ;
int V_42 ;
F_16 ( & V_2 -> V_52 ) ;
switch ( V_123 ) {
case V_127 :
V_3 -> V_128 = true ;
V_42 = F_33 ( V_39 , V_55 , V_114 ) ;
if ( V_42 ) {
F_17 ( & V_2 -> V_52 ) ;
return V_42 ;
}
if ( V_114 -> V_47 & V_116 )
V_3 -> V_7 = V_114 -> V_119 ;
else
V_3 -> V_4 = V_114 -> V_119 ;
V_114 -> V_129 = V_114 -> V_121 ;
V_114 -> V_47 |= V_130 ;
F_21 ( V_62 , L_9 , V_63 ) ;
break;
case V_131 :
V_3 -> V_128 = false ;
F_21 ( V_62 , L_10 , V_63 ) ;
memset ( V_114 , 0 , sizeof( struct V_113 ) ) ;
V_42 = F_33 ( V_39 , V_55 , V_114 ) ;
break;
default:
V_42 = - V_57 ;
break;
}
F_17 ( & V_2 -> V_52 ) ;
return V_42 ;
}
static int F_36 ( struct V_38 * V_39 ,
struct V_54 * V_55 ,
enum V_132 V_133 ,
struct V_124 * V_125 ,
unsigned short V_134 ,
unsigned short * V_135 ,
unsigned char V_136 ,
bool V_137 )
{
int V_42 = - V_57 ;
struct V_8 * V_9 = V_39 -> V_51 ;
struct V_1 * V_2 = V_9 -> V_51 ;
T_1 V_138 = 0 ;
T_4 V_139 = 0 ;
for ( V_139 = 0 ; V_139 < V_140 ; V_139 ++ ) {
if ( V_55 == V_9 -> V_60 [ V_139 ] )
break;
}
F_16 ( & V_2 -> V_52 ) ;
F_21 ( V_74 , L_11 , V_63 , V_133 ) ;
if ( V_135 != NULL )
V_138 = * V_135 ;
switch ( V_133 ) {
case V_141 :
V_42 = F_37 ( V_2 ,
V_134 ,
V_138 ,
V_136 ,
V_142 ) ;
break;
case V_143 :
V_42 = F_37 ( V_2 ,
V_134 ,
0 ,
V_136 ,
V_144 ) ;
break;
case V_145 :
V_2 -> V_146 [ V_139 ] . V_147 = V_138 ;
F_38 ( V_55 , V_125 -> V_148 , V_134 ) ;
V_42 = 0 ;
break;
case V_149 :
case V_150 :
case V_151 :
V_42 = F_37 ( V_2 ,
V_134 ,
V_138 ,
V_136 ,
V_152 ) ;
if ( ! V_42 )
F_39 ( V_55 , V_125 -> V_148 , V_134 ) ;
break;
case V_153 :
V_42 = F_37 ( V_2 ,
V_134 ,
V_2 -> V_146 [ V_139 ]
. V_147 ,
V_136 ,
V_154 ) ;
break;
default:
F_21 ( V_62 , L_12 , V_63 ) ;
break;
}
F_17 ( & V_2 -> V_52 ) ;
return V_42 ;
}
static int F_40 ( struct V_38 * V_39 ,
T_2 V_155 )
{
struct V_8 * V_9 = V_39 -> V_51 ;
struct V_1 * V_2 = V_9 -> V_51 ;
F_16 ( & V_2 -> V_52 ) ;
V_2 -> V_156 = V_155 ;
F_17 ( & V_2 -> V_52 ) ;
return 0 ;
}
static int F_41 ( struct V_38 * V_39 ,
struct V_54 * V_55 ,
const struct V_157 * V_158 )
{
struct V_8 * V_9 = V_39 -> V_51 ;
struct V_1 * V_2 = V_9 -> V_51 ;
enum V_159 V_10 = V_39 -> V_66 . V_67 . V_68 -> V_10 ;
F_16 ( & V_2 -> V_52 ) ;
V_2 -> V_160 [ V_10 ] = 0 ;
if ( V_158 -> V_50 [ V_10 ] . V_161 == 0xfff ) {
V_2 -> V_160 [ V_10 ] =
( V_158 -> V_50 [ V_10 ] . V_162 [ 0 ] << 12 ) ;
} else {
V_2 -> V_160 [ V_10 ] =
V_158 -> V_50 [ V_10 ] . V_161 ;
}
F_17 ( & V_2 -> V_52 ) ;
return 0 ;
}
static void F_42 ( struct V_1 * V_2 ,
T_4 * V_81 ,
T_5 V_163 )
{
struct V_8 * V_9 = V_2 -> V_51 ;
T_5 V_164 = V_2 -> V_85 . V_86 ;
int V_165 = V_2 -> V_85 . V_87 ;
T_2 V_166 = V_2 -> V_85 . V_89 ;
enum V_167 V_168 ;
if ( V_163 < V_165 && ( V_164 == 0 || V_163 < ( V_164 - V_166 ) ) )
V_168 = V_169 ;
else if ( V_163 > V_165 &&
( V_164 == 0 || V_163 > ( V_164 + V_166 ) ) )
V_168 = V_170 ;
else
return;
V_2 -> V_85 . V_86 = V_163 ;
F_21 ( V_74 , L_13 , V_168 ) ;
F_43 ( V_9 -> V_60 [ 0 ] , V_168 , V_16 ) ;
return;
}
static void F_44 ( struct V_38 * V_39 ,
struct V_40 * V_41 ,
struct V_1 * V_2 ,
struct V_171 * V_172 )
{
struct V_71 * V_72 = & V_2 -> V_51 -> V_60 [ 0 ] -> V_73 ;
struct V_43 * V_44 = F_11 ( V_41 ) ;
struct V_173 * V_174 = (struct V_173 * ) V_44 -> V_45 ;
struct V_175 * V_176 ;
char V_163 = V_174 -> V_163 ;
T_4 V_177 = 0 ;
T_4 V_69 = V_174 -> V_69 ;
T_6 V_178 ;
V_176 = ( (struct V_175 * ) ( V_41 -> V_179 ) ) ;
V_177 = F_45 ( V_176 -> V_180 ) ;
memset ( V_44 , 0 , sizeof( struct V_43 ) ) ;
V_172 -> signal = - ( V_163 ) ;
V_172 -> V_10 = V_2 -> V_10 ;
V_178 = F_46 ( V_69 , V_172 -> V_10 ) ;
if ( V_178 )
V_172 -> V_178 = V_178 ;
if ( F_47 ( V_176 -> V_180 ) ) {
if ( F_1 ( V_2 ) ) {
memmove ( V_41 -> V_179 + 4 , V_41 -> V_179 , V_177 ) ;
F_48 ( V_41 , 4 ) ;
} else {
memmove ( V_41 -> V_179 + 8 , V_41 -> V_179 , V_177 ) ;
F_48 ( V_41 , 8 ) ;
V_172 -> V_181 |= V_182 ;
}
V_172 -> V_181 |= V_183 ;
V_172 -> V_181 |= V_184 ;
}
if ( V_72 -> V_76 && ! ( memcmp ( V_72 -> V_81 , V_176 -> V_185 , V_186 ) ) ) {
if ( F_49 ( V_176 -> V_180 ) )
F_42 ( V_2 , V_176 -> V_185 , V_172 -> signal ) ;
}
return;
}
void F_50 ( struct V_1 * V_2 ,
struct V_40 * V_41 )
{
struct V_8 * V_9 = V_2 -> V_51 ;
struct V_38 * V_39 = V_9 -> V_39 ;
struct V_171 * V_187 = F_51 ( V_41 ) ;
if ( ( V_2 -> V_53 ) || ( ! V_9 -> V_59 ) ) {
F_52 ( V_41 ) ;
return;
}
F_44 ( V_39 , V_41 , V_2 , V_187 ) ;
F_53 ( V_39 , V_41 ) ;
}
static void F_54 ( struct V_38 * V_39 ,
struct V_124 * V_125 ,
struct V_1 * V_2 )
{
T_4 V_10 = V_39 -> V_66 . V_67 . V_68 -> V_10 ;
T_4 V_139 ;
T_2 V_188 ;
bool V_189 = false ;
V_2 -> V_190 [ V_10 ] = V_125 -> V_191 [ V_10 ] ;
V_188 = ( V_2 -> V_160 [ V_10 ] & V_125 -> V_191 [ V_10 ] ) ;
if ( V_188 & 0xfff ) {
for ( V_139 = 0 ; V_139 < F_4 ( V_19 ) ; V_139 ++ ) {
if ( V_188 & F_55 ( V_139 ) ) {
V_2 -> V_192 = V_19 [ V_139 ] . V_70 ;
V_189 = true ;
break;
}
}
}
V_2 -> V_146 [ 0 ] . V_193 = V_125 -> V_23 . V_25 ;
if ( ( V_2 -> V_146 [ 0 ] . V_193 ) && ( V_188 >> 12 ) ) {
for ( V_139 = 0 ; V_139 < F_4 ( V_194 ) ; V_139 ++ ) {
if ( ( V_188 >> 12 ) & F_55 ( V_139 ) ) {
V_2 -> V_192 = V_194 [ V_139 ] ;
V_189 = true ;
break;
}
}
}
if ( ! V_189 )
V_2 -> V_192 = 0xffff ;
}
static int F_56 ( struct V_38 * V_39 ,
struct V_54 * V_55 ,
struct V_124 * V_125 )
{
struct V_8 * V_9 = V_39 -> V_51 ;
struct V_1 * V_2 = V_9 -> V_51 ;
F_16 ( & V_2 -> V_52 ) ;
F_54 ( V_39 , V_125 , V_2 ) ;
if ( ( V_125 -> V_23 . V_26 & V_28 ) ||
( V_125 -> V_23 . V_26 & V_29 ) ) {
V_2 -> V_146 [ 0 ] . V_195 = true ;
}
if ( V_125 -> V_23 . V_25 )
F_57 ( V_125 , 0 , 0 ) ;
F_17 ( & V_2 -> V_52 ) ;
return 0 ;
}
static int F_58 ( struct V_38 * V_39 ,
struct V_54 * V_55 ,
struct V_124 * V_125 )
{
struct V_8 * V_9 = V_39 -> V_51 ;
struct V_1 * V_2 = V_9 -> V_51 ;
F_16 ( & V_2 -> V_52 ) ;
V_2 -> V_190 [ V_14 ] = 0 ;
V_2 -> V_190 [ V_22 ] = 0 ;
V_2 -> V_192 = 0xffff ;
V_2 -> V_146 [ 0 ] . V_193 = false ;
V_2 -> V_146 [ 0 ] . V_195 = false ;
V_2 -> V_146 [ 0 ] . V_147 = 0 ;
V_2 -> V_3 . V_7 = 0 ;
V_2 -> V_3 . V_4 = 0 ;
F_17 ( & V_2 -> V_52 ) ;
return 0 ;
}
int F_59 ( struct V_1 * V_2 )
{
int V_42 = 0 ;
struct V_38 * V_39 = NULL ;
struct V_196 * V_196 = NULL ;
struct V_8 * V_9 = V_2 -> V_51 ;
T_4 V_197 [ V_186 ] = { 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x3 } ;
F_21 ( V_198 , L_14 , V_63 ) ;
V_39 = F_60 ( sizeof( struct V_8 ) , & V_199 ) ;
if ( ! V_39 ) {
F_21 ( V_62 , L_15 , V_63 ) ;
return - V_200 ;
}
V_196 = V_39 -> V_196 ;
F_61 ( V_39 , V_9 -> V_201 ) ;
V_39 -> V_51 = V_9 ;
V_9 -> V_39 = V_39 ;
F_62 ( V_39 , V_202 ) ;
F_62 ( V_39 , V_203 ) ;
F_62 ( V_39 , V_204 ) ;
V_39 -> V_205 = V_206 ;
V_39 -> V_207 = V_208 ;
V_39 -> V_209 = 1 ;
V_39 -> V_210 = V_211 ;
V_39 -> V_212 = 6 ;
F_2 ( V_9 , V_14 ) ;
F_2 ( V_9 , V_22 ) ;
V_39 -> V_213 = L_16 ;
F_63 ( V_39 , V_2 -> V_214 ) ;
F_64 ( V_39 -> V_196 -> V_197 , V_197 ) ;
V_196 -> V_215 = F_55 ( V_58 ) ;
V_196 -> V_216 = V_217 ;
V_196 -> V_218 = V_219 ;
V_196 -> V_220 = V_221 ;
V_196 -> V_222 = V_223 ;
V_196 -> V_156 = V_224 ;
V_196 -> V_47 = 0 ;
V_196 -> V_225 = 1 ;
V_196 -> V_226 = 1 ;
V_196 -> V_227 [ V_14 ] =
& V_9 -> V_12 [ V_14 ] ;
V_196 -> V_227 [ V_22 ] =
& V_9 -> V_12 [ V_22 ] ;
V_42 = F_65 ( V_39 ) ;
if ( V_42 )
return V_42 ;
return F_66 ( V_9 ) ;
}
