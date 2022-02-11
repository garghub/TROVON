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
return V_81 ;
}
static int F_27 ( struct V_77 * V_85 ,
struct V_77 * V_86 )
{
struct V_62 * V_63 = F_24 ( V_85 -> V_80 ) ;
struct V_1 * V_2 = F_25 ( V_63 ) ;
if ( V_2 -> V_87 == V_88 )
return 1 ;
else
return 0 ;
}
static int F_28 ( struct V_77 * V_78 ,
struct V_54 * V_55 , int V_79 )
{
struct V_62 * V_63 = F_24 ( V_78 -> V_80 ) ;
struct V_1 * V_2 = F_25 ( V_63 ) ;
switch ( V_79 ) {
case V_89 :
if ( V_2 -> V_61 ) {
V_2 -> V_61 = 0 ;
F_16 ( V_2 -> V_3 ,
V_72 , F_17 ( V_72 ) ) ;
F_18 ( V_2 -> V_73 ) ;
F_19 ( V_2 -> V_73 ) ;
}
break;
default:
return 0 ;
}
return 0 ;
}
static int F_29 ( struct V_90 * V_91 ,
struct V_92 * V_93 , struct V_94 * V_95 )
{
struct V_62 * V_63 = V_95 -> V_63 ;
struct V_1 * V_2 = F_25 ( V_63 ) ;
int V_96 , V_97 , V_98 ;
unsigned int V_99 = 0 ;
V_2 -> V_100 = F_30 ( V_93 ) ;
V_96 = F_31 ( V_2 -> V_82 , V_2 -> V_100 ) ;
if ( V_96 < 0 ) {
F_14 ( V_63 -> V_5 , L_6 ) ;
return - V_76 ;
}
V_98 = F_32 ( V_93 ) ;
if ( V_98 < 0 ) {
F_14 ( V_63 -> V_5 , L_7 , V_98 ) ;
return - V_76 ;
}
V_97 = V_98 > 32 ;
V_2 -> V_101 = V_2 -> V_100 * ( 32 << V_97 ) ;
F_33 ( V_95 -> V_5 , L_8 ,
V_2 -> V_101 , V_2 -> V_100 ) ;
F_33 ( V_95 -> V_5 , L_9 ,
V_97 , V_96 , V_95 -> V_102 ) ;
switch ( F_34 ( V_93 ) ) {
case V_103 :
break;
case V_104 :
V_99 = V_105 ;
break;
case V_106 :
V_99 = V_107 ;
break;
case V_108 :
V_99 = V_109 ;
break;
default:
return - V_76 ;
}
F_26 ( V_2 -> V_73 , V_12 , V_110 ,
V_99 ) ;
F_26 ( V_2 -> V_73 , V_24 ,
V_111 | V_112 ,
V_96 << V_113 |
V_96 << V_114 ) ;
return 0 ;
}
static int F_35 ( struct V_94 * V_95 , unsigned int V_115 )
{
struct V_62 * V_63 = V_95 -> V_63 ;
struct V_1 * V_2 = F_25 ( V_63 ) ;
unsigned int V_116 = 0 ;
switch ( V_115 & V_117 ) {
case V_118 :
break;
case V_119 :
V_116 |= V_120 ;
break;
case V_121 :
V_116 |= V_122 ;
break;
case V_123 :
V_116 |= V_122 | V_120 ;
break;
default:
return - V_76 ;
}
switch ( V_115 & V_124 ) {
case V_125 :
break;
case V_126 :
V_116 |= V_127 ;
break;
case V_128 :
V_116 |= V_129 ;
break;
case V_130 :
V_116 |= V_131 ;
break;
default:
return - V_76 ;
}
F_26 ( V_2 -> V_73 , V_12 ,
V_132 | V_133 | V_134 ,
V_116 ) ;
return 0 ;
}
static int F_36 ( struct V_94 * V_95 ,
int V_135 , unsigned int V_136 , int V_137 )
{
struct V_62 * V_63 = V_95 -> V_63 ;
struct V_1 * V_2 = F_25 ( V_63 ) ;
unsigned int V_116 = 0 ;
if ( V_136 == V_2 -> V_82 && V_135 == V_2 -> V_87 )
return 0 ;
switch ( V_135 ) {
case V_138 :
V_116 |= V_139 ;
break;
case V_88 :
V_116 |= V_140 ;
break;
default:
F_14 ( V_63 -> V_5 , L_10 , V_135 ) ;
return - V_76 ;
}
F_26 ( V_2 -> V_73 , V_24 ,
V_141 , V_116 ) ;
V_2 -> V_82 = V_136 ;
V_2 -> V_87 = V_135 ;
F_33 ( V_95 -> V_5 , L_11 , V_136 , V_135 ) ;
return 0 ;
}
static int F_37 ( struct V_94 * V_95 , int V_142 , int V_85 ,
unsigned int V_143 , unsigned int V_144 )
{
struct V_62 * V_63 = V_95 -> V_63 ;
struct V_1 * V_2 = F_25 ( V_63 ) ;
struct V_145 V_146 ;
int V_147 ;
if ( ! V_143 || ! V_144 ) {
F_33 ( V_63 -> V_5 , L_12 ) ;
V_2 -> V_148 = 0 ;
V_2 -> V_149 = 0 ;
F_26 ( V_2 -> V_73 , V_24 ,
V_141 ,
V_139 ) ;
return 0 ;
}
if ( V_85 == V_2 -> V_150 && V_143 == V_2 -> V_148 &&
V_144 == V_2 -> V_149 )
return 0 ;
switch ( V_85 ) {
case V_151 :
F_26 ( V_2 -> V_73 , V_22 ,
V_152 , V_153 ) ;
break;
case V_154 :
F_26 ( V_2 -> V_73 , V_22 ,
V_152 , V_155 ) ;
break;
default:
F_14 ( V_63 -> V_5 , L_13 , V_85 ) ;
return - V_76 ;
}
V_147 = F_38 ( V_143 , V_144 , & V_146 ) ;
if ( V_147 < 0 ) {
F_14 ( V_63 -> V_5 , L_14 , V_143 ) ;
return V_147 ;
}
F_33 ( V_63 -> V_5 , L_15 ,
V_146 . V_156 , ( V_146 . V_156 ? 0 : V_146 . V_157 ) ,
V_146 . V_158 , V_146 . V_159 ) ;
F_2 ( V_2 -> V_73 , V_46 ,
V_146 . V_159 << V_160 |
V_146 . V_158 << V_161 |
( V_146 . V_156 ? 0 : V_146 . V_157 ) << V_162 ) ;
F_26 ( V_2 -> V_73 , V_47 ,
V_163 , V_146 . V_156 << V_164 ) ;
V_2 -> V_148 = V_143 ;
V_2 -> V_149 = V_144 ;
V_2 -> V_150 = V_85 ;
return 0 ;
}
static int F_39 ( struct V_94 * V_95 , unsigned int V_165 ,
unsigned int V_166 , int V_167 , int V_168 )
{
struct V_62 * V_63 = V_95 -> V_63 ;
struct V_1 * V_2 = F_25 ( V_63 ) ;
unsigned int V_169 = 0 ;
if ( V_166 || V_165 )
V_169 |= V_170 ;
if ( V_167 == 4 )
V_169 |= V_171 | V_172 ;
switch ( V_168 ) {
case 20 :
V_169 |= V_173 | V_174 ;
break;
case 24 :
V_169 |= V_175 | V_176 ;
break;
case 32 :
V_169 |= V_177 | V_178 ;
break;
case 16 :
default:
break;
}
F_26 ( V_2 -> V_73 , V_12 , V_170 |
V_179 | V_180 |
V_181 | V_182 , V_169 ) ;
return 0 ;
}
static int F_40 ( struct V_62 * V_63 ,
enum V_183 V_184 )
{
struct V_1 * V_2 = F_25 ( V_63 ) ;
int V_147 ;
switch ( V_184 ) {
case V_185 :
if ( F_41 ( V_2 -> V_186 ) )
break;
if ( F_10 ( V_63 ) == V_187 ) {
F_42 ( V_2 -> V_186 ) ;
} else {
V_147 = F_43 ( V_2 -> V_186 ) ;
if ( V_147 )
return V_147 ;
}
break;
default:
break;
}
return 0 ;
}
static int F_44 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = F_25 ( V_63 ) ;
V_2 -> V_186 = F_45 ( V_63 -> V_5 , L_16 ) ;
if ( F_46 ( V_2 -> V_186 ) == - V_188 )
return - V_188 ;
V_2 -> V_63 = V_63 ;
return 0 ;
}
static int F_47 ( void * V_189 , unsigned int V_6 , unsigned int * V_169 )
{
struct V_190 * V_191 = V_189 ;
struct V_1 * V_2 = F_48 ( V_191 ) ;
F_49 ( V_2 -> V_3 , V_6 | V_53 , V_169 ) ;
return 0 ;
}
static int F_50 ( void * V_189 , unsigned int V_6 , unsigned int V_169 )
{
struct V_190 * V_191 = V_189 ;
struct V_1 * V_2 = F_48 ( V_191 ) ;
F_2 ( V_2 -> V_3 , V_6 | V_53 , V_169 ) ;
return 0 ;
}
static int F_51 ( struct V_190 * V_192 ,
const struct V_193 * V_102 )
{
struct V_1 * V_2 ;
int V_147 ;
unsigned int V_169 ;
V_2 = F_52 ( & V_192 -> V_5 , sizeof( struct V_1 ) ,
V_194 ) ;
if ( V_2 == NULL )
return - V_195 ;
F_53 ( V_192 , V_2 ) ;
V_2 -> V_3 = F_54 ( V_192 , & V_196 ) ;
if ( F_41 ( V_2 -> V_3 ) ) {
V_147 = F_46 ( V_2 -> V_3 ) ;
F_14 ( & V_192 -> V_5 , L_17 ,
V_147 ) ;
return V_147 ;
}
V_2 -> V_73 = F_55 ( & V_192 -> V_5 , NULL , V_192 , & V_197 ) ;
if ( F_41 ( V_2 -> V_73 ) ) {
V_147 = F_46 ( V_2 -> V_73 ) ;
F_14 ( & V_192 -> V_5 , L_17 ,
V_147 ) ;
return V_147 ;
}
F_49 ( V_2 -> V_73 , V_8 , & V_169 ) ;
if ( V_169 != V_198 ) {
F_14 ( & V_192 -> V_5 ,
L_18 , V_169 ) ;
return - V_199 ;
}
V_147 = F_16 ( V_2 -> V_3 , V_72 ,
F_17 ( V_72 ) ) ;
if ( V_147 != 0 )
F_22 ( & V_192 -> V_5 , L_19 ,
V_147 ) ;
V_147 = F_56 ( V_2 -> V_73 , V_200 ,
F_17 ( V_200 ) ) ;
if ( V_147 != 0 )
F_22 ( & V_192 -> V_5 , L_20 , V_147 ) ;
return F_57 ( & V_192 -> V_5 , & V_201 ,
V_202 , F_17 ( V_202 ) ) ;
}
static int F_58 ( struct V_190 * V_192 )
{
F_59 ( & V_192 -> V_5 ) ;
return 0 ;
}
