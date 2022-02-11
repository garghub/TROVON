static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , 0x18002000 , 0x000010ec ) ;
F_2 ( V_2 -> V_3 , 0x18002200 , 0x00028604 ) ;
F_2 ( V_2 -> V_3 , 0xfafafafa , 0x00000001 ) ;
F_2 ( V_2 -> V_3 , 0x18002f00 , 0x0005514b ) ;
F_2 ( V_2 -> V_3 , 0x18002f00 , 0x00055149 ) ;
F_2 ( V_2 -> V_3 , 0xfafafafa , 0x00000000 ) ;
F_2 ( V_2 -> V_3 , 0x18002070 , 0x00000040 ) ;
F_2 ( V_2 -> V_3 , 0x18002240 , 0x0000000a ) ;
F_2 ( V_2 -> V_3 , 0x18002100 , 0x0000000b ) ;
F_2 ( V_2 -> V_3 , 0x18002004 , 0x00808b81 ) ;
F_2 ( V_2 -> V_3 , 0x18002f08 , 0x00000005 ) ;
F_2 ( V_2 -> V_3 , 0x18001114 , 0x00000001 ) ;
F_2 ( V_2 -> V_3 , 0x18001118 , 0x00000001 ) ;
}
static bool F_3 ( struct V_4 * V_5 , unsigned int V_6 )
{
switch ( V_6 ) {
case V_7 :
case V_8 :
return true ;
default:
return false ;
}
}
static bool F_4 ( struct V_4 * V_5 , unsigned int V_6 )
{
switch ( V_6 ) {
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_7 :
case V_8 :
return true ;
default:
return false ;
}
}
static bool F_5 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
switch ( V_6 ) {
case V_53 | V_9 :
case V_53 | V_10 :
case V_53 | V_11 :
case V_53 | V_12 :
case V_53 | V_13 :
case V_53 | V_14 :
case V_53 | V_15 :
case V_53 | V_16 :
case V_53 | V_17 :
case V_53 | V_18 :
case V_53 | V_19 :
case V_53 | V_20 :
case V_53 | V_21 :
case V_53 | V_22 :
case V_53 | V_23 :
case V_53 | V_24 :
case V_53 | V_25 :
case V_53 | V_26 :
case V_53 | V_27 :
case V_53 | V_28 :
case V_53 | V_29 :
case V_53 | V_30 :
case V_53 | V_31 :
case V_53 | V_32 :
case V_53 | V_33 :
case V_53 | V_34 :
case V_53 | V_35 :
case V_53 | V_36 :
case V_53 | V_37 :
case V_53 | V_38 :
case V_53 | V_39 :
case V_53 | V_40 :
case V_53 | V_41 :
case V_53 | V_42 :
case V_53 | V_43 :
case V_53 | V_44 :
case V_53 | V_45 :
case V_53 | V_46 :
case V_53 | V_47 :
case V_53 | V_48 :
case V_53 | V_49 :
case V_53 | V_50 :
case V_53 | V_51 :
case V_53 | V_52 :
case V_53 | V_7 :
case V_53 | V_8 :
return true ;
default:
return false ;
}
}
static int F_6 ( struct V_54 * V_55 ,
struct V_56 * V_57 )
{
struct V_58 * V_59 = F_7 ( V_55 ) ;
struct V_1 * V_2 = F_8 ( V_59 ) ;
V_57 -> V_60 . integer . V_60 [ 0 ] = V_2 -> V_61 ;
return 0 ;
}
static int F_9 ( struct V_54 * V_55 ,
struct V_56 * V_57 )
{
struct V_58 * V_59 = F_7 ( V_55 ) ;
struct V_1 * V_2 = F_8 ( V_59 ) ;
struct V_62 * V_63 = V_2 -> V_63 ;
const struct V_64 * V_65 = NULL ;
if ( V_57 -> V_60 . integer . V_60 [ 0 ] == V_2 -> V_61 )
return 0 ;
if ( F_10 ( V_63 ) == V_66 ) {
V_2 -> V_61 = V_57 -> V_60 . integer . V_60 [ 0 ] ;
if ( V_2 -> V_61 ) {
F_1 ( V_2 ) ;
F_11 ( & V_65 , V_67 , V_63 -> V_5 ) ;
if ( V_65 ) {
#if F_12 ( V_68 )
F_13 ( 0x4ff60000 , V_65 -> V_69 ,
( ( V_65 -> V_70 / 8 ) + 1 ) * 8 ) ;
#else
F_14 ( V_63 -> V_5 , L_1
L_2 ) ;
#endif
F_15 ( V_65 ) ;
V_65 = NULL ;
}
F_11 ( & V_65 , V_71 , V_63 -> V_5 ) ;
if ( V_65 ) {
#if F_12 ( V_68 )
F_13 ( 0x4ffc0000 , V_65 -> V_69 ,
( ( V_65 -> V_70 / 8 ) + 1 ) * 8 ) ;
#else
F_14 ( V_63 -> V_5 , L_1
L_2 ) ;
#endif
F_15 ( V_65 ) ;
V_65 = NULL ;
}
F_2 ( V_2 -> V_3 , 0x18002f00 ,
0x00055148 ) ;
} else {
F_16 ( V_2 -> V_3 ,
V_72 , F_17 ( V_72 ) ) ;
F_18 ( V_2 -> V_73 ) ;
F_19 ( V_2 -> V_73 ) ;
}
}
return 0 ;
}
static int F_20 ( struct V_62 * V_63 , int V_74 )
{
int div [] = { 2 , 3 , 4 , 8 , 12 , 16 , 24 , 32 } ;
int V_75 ;
if ( V_74 < 1000000 * div [ 0 ] ) {
F_21 ( L_3 , V_74 ) ;
return - V_76 ;
}
for ( V_75 = 0 ; V_75 < F_17 ( div ) ; V_75 ++ ) {
if ( 3072000 * div [ V_75 ] >= V_74 )
return V_75 ;
}
F_22 ( V_63 -> V_5 , L_4 , V_74 ) ;
return - V_76 ;
}
static int F_23 ( struct V_77 * V_78 ,
struct V_54 * V_55 , int V_79 )
{
struct V_62 * V_63 = F_24 ( V_78 -> V_80 ) ;
struct V_1 * V_2 = F_25 ( V_63 ) ;
int V_81 ;
V_81 = F_20 ( V_63 , V_2 -> V_82 ) ;
if ( V_81 < 0 )
F_14 ( V_63 -> V_5 , L_5 ) ;
else
F_26 ( V_2 -> V_73 , V_23 ,
V_83 ,
V_81 << V_84 ) ;
if ( V_2 -> V_85 . V_86 )
F_27 ( V_2 -> V_85 . V_86 ) ;
return V_81 ;
}
static int F_28 ( struct V_77 * V_87 ,
struct V_77 * V_88 )
{
struct V_62 * V_63 = F_24 ( V_87 -> V_80 ) ;
struct V_1 * V_2 = F_25 ( V_63 ) ;
if ( V_2 -> V_89 == V_90 )
return 1 ;
else
return 0 ;
}
static int F_29 ( struct V_77 * V_87 ,
struct V_77 * V_88 )
{
struct V_62 * V_63 = F_24 ( V_87 -> V_80 ) ;
struct V_1 * V_2 = F_25 ( V_63 ) ;
return ( V_2 -> V_82 > V_2 -> V_91 * 384 ) ;
}
static int F_30 ( struct V_92 * V_93 ,
struct V_94 * V_95 , struct V_96 * V_97 )
{
struct V_62 * V_63 = V_97 -> V_63 ;
struct V_1 * V_2 = F_25 ( V_63 ) ;
int V_98 , V_99 , V_100 ;
unsigned int V_101 = 0 ;
V_2 -> V_91 = F_31 ( V_95 ) ;
V_98 = F_32 ( V_2 -> V_82 , V_2 -> V_91 ) ;
if ( V_98 < 0 ) {
F_14 ( V_63 -> V_5 , L_6 ) ;
return - V_76 ;
}
V_100 = F_33 ( V_95 ) ;
if ( V_100 < 0 ) {
F_14 ( V_63 -> V_5 , L_7 , V_100 ) ;
return - V_76 ;
}
V_99 = V_100 > 32 ;
V_2 -> V_102 = V_2 -> V_91 * ( 32 << V_99 ) ;
F_34 ( V_97 -> V_5 , L_8 ,
V_2 -> V_102 , V_2 -> V_91 ) ;
F_34 ( V_97 -> V_5 , L_9 ,
V_99 , V_98 , V_97 -> V_103 ) ;
switch ( F_35 ( V_95 ) ) {
case V_104 :
break;
case V_105 :
V_101 = V_106 ;
break;
case V_107 :
V_101 = V_108 ;
break;
case V_109 :
V_101 = V_110 ;
break;
default:
return - V_76 ;
}
F_26 ( V_2 -> V_73 , V_12 , V_111 ,
V_101 ) ;
F_26 ( V_2 -> V_73 , V_23 ,
V_112 ,
( V_98 + 1 ) << V_113 ) ;
F_26 ( V_2 -> V_73 , V_24 ,
V_114 | V_115 ,
V_98 << V_116 |
V_98 << V_117 ) ;
return 0 ;
}
static int F_36 ( struct V_96 * V_97 , unsigned int V_118 )
{
struct V_62 * V_63 = V_97 -> V_63 ;
struct V_1 * V_2 = F_25 ( V_63 ) ;
unsigned int V_119 = 0 ;
switch ( V_118 & V_120 ) {
case V_121 :
break;
case V_122 :
V_119 |= V_123 ;
break;
case V_124 :
V_119 |= V_125 ;
break;
case V_126 :
V_119 |= V_125 | V_123 ;
break;
default:
return - V_76 ;
}
switch ( V_118 & V_127 ) {
case V_128 :
break;
case V_129 :
V_119 |= V_130 ;
break;
case V_131 :
V_119 |= V_132 ;
break;
case V_133 :
V_119 |= V_134 ;
break;
default:
return - V_76 ;
}
F_26 ( V_2 -> V_73 , V_12 ,
V_135 | V_136 | V_137 ,
V_119 ) ;
return 0 ;
}
static int F_37 ( struct V_96 * V_97 ,
int V_138 , unsigned int V_139 , int V_140 )
{
struct V_62 * V_63 = V_97 -> V_63 ;
struct V_1 * V_2 = F_25 ( V_63 ) ;
unsigned int V_119 = 0 ;
if ( V_139 == V_2 -> V_82 && V_138 == V_2 -> V_89 )
return 0 ;
switch ( V_138 ) {
case V_141 :
V_119 |= V_142 ;
break;
case V_90 :
V_119 |= V_143 ;
break;
default:
F_14 ( V_63 -> V_5 , L_10 , V_138 ) ;
return - V_76 ;
}
F_26 ( V_2 -> V_73 , V_24 ,
V_144 , V_119 ) ;
V_2 -> V_82 = V_139 ;
V_2 -> V_89 = V_138 ;
F_34 ( V_97 -> V_5 , L_11 , V_139 , V_138 ) ;
return 0 ;
}
static int F_38 ( struct V_96 * V_97 , int V_145 , int V_87 ,
unsigned int V_146 , unsigned int V_147 )
{
struct V_62 * V_63 = V_97 -> V_63 ;
struct V_1 * V_2 = F_25 ( V_63 ) ;
struct V_148 V_149 ;
int V_150 ;
if ( ! V_146 || ! V_147 ) {
F_34 ( V_63 -> V_5 , L_12 ) ;
V_2 -> V_151 = 0 ;
V_2 -> V_152 = 0 ;
F_26 ( V_2 -> V_73 , V_24 ,
V_144 ,
V_142 ) ;
return 0 ;
}
if ( V_87 == V_2 -> V_153 && V_146 == V_2 -> V_151 &&
V_147 == V_2 -> V_152 )
return 0 ;
switch ( V_87 ) {
case V_154 :
F_26 ( V_2 -> V_73 , V_22 ,
V_155 , V_156 ) ;
break;
case V_157 :
F_26 ( V_2 -> V_73 , V_22 ,
V_155 , V_158 ) ;
break;
default:
F_14 ( V_63 -> V_5 , L_13 , V_87 ) ;
return - V_76 ;
}
V_150 = F_39 ( V_146 , V_147 , & V_149 ) ;
if ( V_150 < 0 ) {
F_14 ( V_63 -> V_5 , L_14 , V_146 ) ;
return V_150 ;
}
F_34 ( V_63 -> V_5 , L_15 ,
V_149 . V_159 , ( V_149 . V_159 ? 0 : V_149 . V_160 ) ,
V_149 . V_161 , V_149 . V_162 ) ;
F_2 ( V_2 -> V_73 , V_46 ,
V_149 . V_162 << V_163 |
V_149 . V_161 << V_164 |
( V_149 . V_159 ? 0 : V_149 . V_160 ) << V_165 ) ;
F_26 ( V_2 -> V_73 , V_47 ,
V_166 , V_149 . V_159 << V_167 ) ;
V_2 -> V_151 = V_146 ;
V_2 -> V_152 = V_147 ;
V_2 -> V_153 = V_87 ;
return 0 ;
}
static int F_40 ( struct V_96 * V_97 , unsigned int V_168 ,
unsigned int V_169 , int V_170 , int V_171 )
{
struct V_62 * V_63 = V_97 -> V_63 ;
struct V_1 * V_2 = F_25 ( V_63 ) ;
unsigned int V_172 = 0 , V_173 = 0 ;
if ( V_169 || V_168 )
V_172 |= V_174 ;
switch ( V_168 ) {
case 0x3 :
V_173 |= V_175 | V_176 |
V_177 ;
break;
case 0x30 :
V_173 |= V_175 | V_176 |
V_178 ;
break;
case 0xf :
V_173 |= V_175 | V_179 |
V_177 ;
break;
case 0xf0 :
V_173 |= V_175 | V_179 |
V_178 ;
break;
default:
break;
}
switch ( V_170 ) {
case 4 :
V_172 |= V_180 | V_181 ;
break;
case 6 :
V_172 |= V_182 | V_183 ;
break;
case 8 :
V_172 |= V_184 | V_185 ;
break;
case 2 :
default:
break;
}
switch ( V_171 ) {
case 20 :
V_172 |= V_186 | V_187 ;
break;
case 24 :
V_172 |= V_188 | V_189 ;
break;
case 25 :
V_172 |= V_190 ;
break;
case 32 :
V_172 |= V_191 | V_192 ;
break;
case 16 :
default:
break;
}
F_26 ( V_2 -> V_73 , V_12 , V_174 |
V_193 | V_194 |
V_195 | V_196 |
V_190 , V_172 ) ;
F_26 ( V_2 -> V_73 , V_13 ,
V_175 | V_197 |
V_198 , V_173 ) ;
return 0 ;
}
static int F_41 ( struct V_62 * V_63 ,
enum V_199 V_200 )
{
struct V_1 * V_2 = F_25 ( V_63 ) ;
int V_150 ;
switch ( V_200 ) {
case V_201 :
if ( F_42 ( V_2 -> V_202 ) )
break;
if ( F_10 ( V_63 ) == V_203 ) {
F_43 ( V_2 -> V_202 ) ;
} else {
V_150 = F_44 ( V_2 -> V_202 ) ;
if ( V_150 )
return V_150 ;
}
break;
case V_204 :
if ( F_10 ( V_63 ) == V_66 ) {
if ( V_2 -> V_61 ) {
V_2 -> V_61 = 0 ;
F_16 ( V_2 -> V_3 ,
V_72 ,
F_17 ( V_72 ) ) ;
F_18 ( V_2 -> V_73 ) ;
F_19 ( V_2 -> V_73 ) ;
}
}
break;
default:
break;
}
return 0 ;
}
static int F_45 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = F_25 ( V_63 ) ;
V_2 -> V_202 = F_46 ( V_63 -> V_5 , L_16 ) ;
if ( F_47 ( V_2 -> V_202 ) == - V_205 )
return - V_205 ;
V_2 -> V_63 = V_63 ;
return 0 ;
}
static int F_48 ( void * V_206 , unsigned int V_6 , unsigned int * V_172 )
{
struct V_207 * V_208 = V_206 ;
struct V_1 * V_2 = F_49 ( V_208 ) ;
F_50 ( V_2 -> V_3 , V_6 | V_53 , V_172 ) ;
return 0 ;
}
static int F_51 ( void * V_206 , unsigned int V_6 , unsigned int V_172 )
{
struct V_207 * V_208 = V_206 ;
struct V_1 * V_2 = F_49 ( V_208 ) ;
F_2 ( V_2 -> V_3 , V_6 | V_53 , V_172 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
F_53 ( V_5 , L_17 ,
& V_2 -> V_85 . V_86 ) ;
return 0 ;
}
static T_1 int F_54 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_55 ( V_5 ) ;
unsigned int V_172 ;
F_50 ( V_2 -> V_73 , V_8 , & V_172 ) ;
return 0 ;
}
static int F_56 ( struct V_207 * V_209 ,
const struct V_210 * V_103 )
{
struct V_211 * V_85 = F_57 ( & V_209 -> V_5 ) ;
struct V_1 * V_2 ;
int V_150 ;
unsigned int V_172 = ~ 0 ;
V_2 = F_58 ( & V_209 -> V_5 , sizeof( struct V_1 ) ,
V_212 ) ;
if ( V_2 == NULL )
return - V_213 ;
F_59 ( V_209 , V_2 ) ;
if ( V_85 )
V_2 -> V_85 = * V_85 ;
else if ( V_209 -> V_5 . V_214 )
F_52 ( V_2 , & V_209 -> V_5 ) ;
V_2 -> V_3 = F_60 ( V_209 , & V_215 ) ;
if ( F_42 ( V_2 -> V_3 ) ) {
V_150 = F_47 ( V_2 -> V_3 ) ;
F_14 ( & V_209 -> V_5 , L_18 ,
V_150 ) ;
return V_150 ;
}
V_2 -> V_73 = F_61 ( & V_209 -> V_5 , NULL , V_209 , & V_216 ) ;
if ( F_42 ( V_2 -> V_73 ) ) {
V_150 = F_47 ( V_2 -> V_73 ) ;
F_14 ( & V_209 -> V_5 , L_18 ,
V_150 ) ;
return V_150 ;
}
V_150 = F_50 ( V_2 -> V_73 , V_8 , & V_172 ) ;
if ( V_150 || V_172 != V_217 )
V_150 = F_50 ( V_2 -> V_73 , V_8 , & V_172 ) ;
if ( V_150 || V_172 != V_217 ) {
F_14 ( & V_209 -> V_5 ,
L_19 , V_172 ) ;
return - V_218 ;
}
V_150 = F_16 ( V_2 -> V_3 , V_72 ,
F_17 ( V_72 ) ) ;
if ( V_150 != 0 )
F_22 ( & V_209 -> V_5 , L_20 ,
V_150 ) ;
V_150 = F_62 ( V_2 -> V_73 , V_219 ,
F_17 ( V_219 ) ) ;
if ( V_150 != 0 )
F_22 ( & V_209 -> V_5 , L_21 , V_150 ) ;
return F_63 ( & V_209 -> V_5 , & V_220 ,
V_221 , F_17 ( V_221 ) ) ;
}
static int F_64 ( struct V_207 * V_209 )
{
F_65 ( & V_209 -> V_5 ) ;
return 0 ;
}
