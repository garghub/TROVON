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
unsigned char V_136 )
{
int V_42 = - V_57 ;
struct V_8 * V_9 = V_39 -> V_51 ;
struct V_1 * V_2 = V_9 -> V_51 ;
T_1 V_137 = 0 ;
T_4 V_138 = 0 ;
for ( V_138 = 0 ; V_138 < V_139 ; V_138 ++ ) {
if ( V_55 == V_9 -> V_60 [ V_138 ] )
break;
}
F_16 ( & V_2 -> V_52 ) ;
F_21 ( V_74 , L_11 , V_63 , V_133 ) ;
if ( V_135 != NULL )
V_137 = * V_135 ;
switch ( V_133 ) {
case V_140 :
V_42 = F_37 ( V_2 ,
V_134 ,
V_137 ,
V_136 ,
V_141 ) ;
break;
case V_142 :
V_42 = F_37 ( V_2 ,
V_134 ,
0 ,
V_136 ,
V_143 ) ;
break;
case V_144 :
V_2 -> V_145 [ V_138 ] . V_146 = V_137 ;
F_38 ( V_55 , V_125 -> V_147 , V_134 ) ;
V_42 = 0 ;
break;
case V_148 :
case V_149 :
case V_150 :
V_42 = F_37 ( V_2 ,
V_134 ,
V_137 ,
V_136 ,
V_151 ) ;
if ( ! V_42 )
F_39 ( V_55 , V_125 -> V_147 , V_134 ) ;
break;
case V_152 :
V_42 = F_37 ( V_2 ,
V_134 ,
V_2 -> V_145 [ V_138 ]
. V_146 ,
V_136 ,
V_153 ) ;
break;
default:
F_21 ( V_62 , L_12 , V_63 ) ;
break;
}
F_17 ( & V_2 -> V_52 ) ;
return V_42 ;
}
static int F_40 ( struct V_38 * V_39 ,
T_2 V_154 )
{
struct V_8 * V_9 = V_39 -> V_51 ;
struct V_1 * V_2 = V_9 -> V_51 ;
F_16 ( & V_2 -> V_52 ) ;
V_2 -> V_155 = V_154 ;
F_17 ( & V_2 -> V_52 ) ;
return 0 ;
}
static int F_41 ( struct V_38 * V_39 ,
struct V_54 * V_55 ,
const struct V_156 * V_157 )
{
struct V_8 * V_9 = V_39 -> V_51 ;
struct V_1 * V_2 = V_9 -> V_51 ;
enum V_158 V_10 = V_39 -> V_66 . V_67 . V_68 -> V_10 ;
F_16 ( & V_2 -> V_52 ) ;
V_2 -> V_159 [ V_10 ] = 0 ;
if ( V_157 -> V_50 [ V_10 ] . V_160 == 0xfff ) {
V_2 -> V_159 [ V_10 ] =
( V_157 -> V_50 [ V_10 ] . V_161 [ 0 ] << 12 ) ;
} else {
V_2 -> V_159 [ V_10 ] =
V_157 -> V_50 [ V_10 ] . V_160 ;
}
F_17 ( & V_2 -> V_52 ) ;
return 0 ;
}
static void F_42 ( struct V_1 * V_2 ,
T_4 * V_81 ,
T_5 V_162 )
{
struct V_8 * V_9 = V_2 -> V_51 ;
T_5 V_163 = V_2 -> V_85 . V_86 ;
int V_164 = V_2 -> V_85 . V_87 ;
T_2 V_165 = V_2 -> V_85 . V_89 ;
enum V_166 V_167 ;
if ( V_162 < V_164 && ( V_163 == 0 || V_162 < ( V_163 - V_165 ) ) )
V_167 = V_168 ;
else if ( V_162 > V_164 &&
( V_163 == 0 || V_162 > ( V_163 + V_165 ) ) )
V_167 = V_169 ;
else
return;
V_2 -> V_85 . V_86 = V_162 ;
F_21 ( V_74 , L_13 , V_167 ) ;
F_43 ( V_9 -> V_60 [ 0 ] , V_167 , V_16 ) ;
return;
}
static void F_44 ( struct V_38 * V_39 ,
struct V_40 * V_41 ,
struct V_1 * V_2 ,
struct V_170 * V_171 )
{
struct V_71 * V_72 = & V_2 -> V_51 -> V_60 [ 0 ] -> V_73 ;
struct V_43 * V_44 = F_11 ( V_41 ) ;
struct V_172 * V_173 = (struct V_172 * ) V_44 -> V_45 ;
struct V_174 * V_175 ;
char V_162 = V_173 -> V_162 ;
T_4 V_176 = 0 ;
T_4 V_69 = V_173 -> V_69 ;
T_6 V_177 ;
V_175 = ( (struct V_174 * ) ( V_41 -> V_178 ) ) ;
V_176 = F_45 ( V_175 -> V_179 ) ;
memset ( V_44 , 0 , sizeof( struct V_43 ) ) ;
V_171 -> signal = - ( V_162 ) ;
V_171 -> V_10 = V_2 -> V_10 ;
V_177 = F_46 ( V_69 , V_171 -> V_10 ) ;
if ( V_177 )
V_171 -> V_177 = V_177 ;
if ( F_47 ( V_175 -> V_179 ) ) {
if ( F_1 ( V_2 ) ) {
memmove ( V_41 -> V_178 + 4 , V_41 -> V_178 , V_176 ) ;
F_48 ( V_41 , 4 ) ;
} else {
memmove ( V_41 -> V_178 + 8 , V_41 -> V_178 , V_176 ) ;
F_48 ( V_41 , 8 ) ;
V_171 -> V_180 |= V_181 ;
}
V_171 -> V_180 |= V_182 ;
V_171 -> V_180 |= V_183 ;
}
if ( V_72 -> V_76 && ! ( memcmp ( V_72 -> V_81 , V_175 -> V_184 , V_185 ) ) ) {
if ( F_49 ( V_175 -> V_179 ) )
F_42 ( V_2 , V_175 -> V_184 , V_171 -> signal ) ;
}
return;
}
void F_50 ( struct V_1 * V_2 ,
struct V_40 * V_41 )
{
struct V_8 * V_9 = V_2 -> V_51 ;
struct V_38 * V_39 = V_9 -> V_39 ;
struct V_170 * V_186 = F_51 ( V_41 ) ;
if ( ( V_2 -> V_53 ) || ( ! V_9 -> V_59 ) ) {
F_52 ( V_41 ) ;
return;
}
F_44 ( V_39 , V_41 , V_2 , V_186 ) ;
F_53 ( V_39 , V_41 ) ;
}
static void F_54 ( struct V_38 * V_39 ,
struct V_124 * V_125 ,
struct V_1 * V_2 )
{
T_4 V_10 = V_39 -> V_66 . V_67 . V_68 -> V_10 ;
T_4 V_138 ;
T_2 V_187 ;
bool V_188 = false ;
V_2 -> V_189 [ V_10 ] = V_125 -> V_190 [ V_10 ] ;
V_187 = ( V_2 -> V_159 [ V_10 ] & V_125 -> V_190 [ V_10 ] ) ;
if ( V_187 & 0xfff ) {
for ( V_138 = 0 ; V_138 < F_4 ( V_19 ) ; V_138 ++ ) {
if ( V_187 & F_55 ( V_138 ) ) {
V_2 -> V_191 = V_19 [ V_138 ] . V_70 ;
V_188 = true ;
break;
}
}
}
V_2 -> V_145 [ 0 ] . V_192 = V_125 -> V_23 . V_25 ;
if ( ( V_2 -> V_145 [ 0 ] . V_192 ) && ( V_187 >> 12 ) ) {
for ( V_138 = 0 ; V_138 < F_4 ( V_193 ) ; V_138 ++ ) {
if ( ( V_187 >> 12 ) & F_55 ( V_138 ) ) {
V_2 -> V_191 = V_193 [ V_138 ] ;
V_188 = true ;
break;
}
}
}
if ( ! V_188 )
V_2 -> V_191 = 0xffff ;
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
V_2 -> V_145 [ 0 ] . V_194 = true ;
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
V_2 -> V_189 [ V_14 ] = 0 ;
V_2 -> V_189 [ V_22 ] = 0 ;
V_2 -> V_191 = 0xffff ;
V_2 -> V_145 [ 0 ] . V_192 = false ;
V_2 -> V_145 [ 0 ] . V_194 = false ;
V_2 -> V_145 [ 0 ] . V_146 = 0 ;
V_2 -> V_3 . V_7 = 0 ;
V_2 -> V_3 . V_4 = 0 ;
F_17 ( & V_2 -> V_52 ) ;
return 0 ;
}
int F_59 ( struct V_1 * V_2 )
{
int V_42 = 0 ;
struct V_38 * V_39 = NULL ;
struct V_195 * V_195 = NULL ;
struct V_8 * V_9 = V_2 -> V_51 ;
T_4 V_196 [ V_185 ] = { 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x3 } ;
F_21 ( V_197 , L_14 , V_63 ) ;
V_39 = F_60 ( sizeof( struct V_8 ) , & V_198 ) ;
if ( ! V_39 ) {
F_21 ( V_62 , L_15 , V_63 ) ;
return - V_199 ;
}
V_195 = V_39 -> V_195 ;
F_61 ( V_39 , V_9 -> V_200 ) ;
V_39 -> V_51 = V_9 ;
V_9 -> V_39 = V_39 ;
V_39 -> V_47 = V_201 |
V_202 |
V_203 |
0 ;
V_39 -> V_204 = V_205 ;
V_39 -> V_206 = V_207 ;
V_39 -> V_208 = 1 ;
V_39 -> V_209 = V_210 ;
V_39 -> V_211 = 6 ;
F_2 ( V_9 , V_14 ) ;
F_2 ( V_9 , V_22 ) ;
V_39 -> V_212 = L_16 ;
F_62 ( V_39 , V_2 -> V_213 ) ;
F_63 ( V_39 -> V_195 -> V_196 , V_196 ) ;
V_195 -> V_214 = F_55 ( V_58 ) ;
V_195 -> V_215 = V_216 ;
V_195 -> V_217 = V_218 ;
V_195 -> V_219 = V_220 ;
V_195 -> V_221 = V_222 ;
V_195 -> V_155 = V_223 ;
V_195 -> V_47 = 0 ;
V_195 -> V_224 = 1 ;
V_195 -> V_225 = 1 ;
V_195 -> V_226 [ V_14 ] =
& V_9 -> V_12 [ V_14 ] ;
V_195 -> V_226 [ V_22 ] =
& V_9 -> V_12 [ V_22 ] ;
V_42 = F_64 ( V_39 ) ;
if ( V_42 )
return V_42 ;
return F_65 ( V_9 ) ;
}
