static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 , L_1 ) ;
F_4 ( V_4 , V_6 ) ;
F_4 ( V_4 , V_7 ) ;
F_4 ( V_4 , V_8 ) ;
F_4 ( V_4 , V_9 ) ;
F_4 ( V_4 , V_10 ) ;
F_4 ( V_4 , V_11 ) ;
F_4 ( V_4 , V_12 ) ;
F_4 ( V_4 , V_13 ) ;
F_4 ( V_4 , V_14 ) ;
F_4 ( V_4 , F_5 ( 0 ) ) ;
F_4 ( V_4 , F_6 ( 0 ) ) ;
F_4 ( V_4 , F_7 ( 0 ) ) ;
F_4 ( V_4 , F_8 ( 0 ) ) ;
F_4 ( V_4 , F_9 ( 0 ) ) ;
F_4 ( V_4 , F_10 ( 0 ) ) ;
F_4 ( V_4 , F_11 ( 0 ) ) ;
F_4 ( V_4 , F_12 ( 0 ) ) ;
F_4 ( V_4 , F_13 ( 0 ) ) ;
F_4 ( V_4 , F_14 ( 0 ) ) ;
F_4 ( V_4 , F_15 ( 0 ) ) ;
F_4 ( V_4 , V_15 ) ;
F_4 ( V_4 , V_16 ) ;
F_4 ( V_4 , V_17 ) ;
F_4 ( V_4 , V_18 ) ;
F_4 ( V_4 , V_19 ) ;
F_4 ( V_4 , V_20 ) ;
F_4 ( V_4 , V_21 ) ;
F_4 ( V_4 , V_22 ) ;
F_3 ( V_4 -> V_5 , L_2 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_23 = 0 ;
F_17 ( V_4 , V_24 , V_25 ,
V_26 ) ;
while ( ! ( F_18 ( V_4 , V_24 , V_27 ) &
V_28 ) ) {
F_19 ( 10 ) ;
if ( V_23 ++ > 10 ) {
F_20 ( V_4 -> V_5 ,
L_3 ) ;
break;
}
}
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_22 ( V_4 , V_29 |
( ( V_4 -> V_30 == V_31 && V_4 -> V_32 ) ?
V_33 : 0 ) ,
V_24 , V_25 ) ;
}
static int F_23 ( struct V_1 * V_2 , T_1 V_34 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_35 ;
int V_23 ;
if ( V_34 && V_2 -> V_36 ) {
V_35 = F_24 ( V_2 -> V_36 ) ;
if ( V_35 < 0 )
return V_35 ;
}
for ( V_23 = 0 ; V_23 < V_37 ; V_23 ++ )
F_25 ( V_4 , V_24 , F_26 ( V_23 ) ,
V_38 ,
V_34 ? V_38 : 0 ) ;
F_25 ( V_4 , V_24 , V_39 ,
V_40 | V_41 ,
V_34 ? ( V_40 | V_41 ) : 0 ) ;
if ( ! V_34 && V_2 -> V_36 )
F_27 ( V_2 -> V_36 ) ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 , T_1 V_34 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_34 )
F_23 ( V_2 , 0 ) ;
F_25 ( V_4 , V_24 , V_39 ,
V_40 , V_34 ? V_40 : 0 ) ;
F_25 ( V_4 , V_24 , V_42 ,
V_43 ,
V_34 ? V_43 : 0 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
const struct V_44 * V_45 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_46 ;
V_46 = F_18 ( V_4 , V_24 , V_39 ) |
V_40 ;
F_30 ( V_46 , V_47 , V_48 ,
V_45 -> V_49 ) ;
F_30 ( V_46 , V_50 ,
V_51 , V_45 -> V_52 ) ;
F_30 ( V_46 , V_53 , V_54 ,
V_45 -> V_55 ) ;
F_30 ( V_46 , V_56 ,
V_57 , V_45 -> V_58 ) ;
F_22 ( V_4 , V_46 , V_24 , V_39 ) ;
V_46 = F_18 ( V_4 , V_24 , V_39 ) ;
if ( ! ( V_46 & V_40 ) ) {
if ( V_45 -> V_52 == V_59 )
F_20 ( V_4 -> V_5 , L_4 ) ;
if ( V_45 -> V_49 == V_60 )
return - V_61 ;
}
return 0 ;
}
static void F_31 ( struct V_1 * V_2 ,
unsigned int V_62 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_46 ;
V_46 = F_18 ( V_4 , V_24 , V_39 ) ;
V_46 |= V_63 ;
if ( V_4 -> V_30 == V_31 ) {
V_62 = F_32 (unsigned int, vpclk_div, 1 , 65536 ) ;
V_62 = F_33 ( V_64 / V_62 , 65535U ) ;
F_30 ( V_46 , V_65 ,
V_66 , V_62 ) ;
} else {
V_62 = F_32 (unsigned int, vpclk_div, 1 , 4 ) ;
F_30 ( V_46 , V_67 ,
V_68 , V_62 - 1 ) ;
}
F_22 ( V_4 , V_46 , V_24 , V_39 ) ;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_69 * V_70 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_46 , V_71 ;
switch ( V_70 -> V_71 ) {
case V_72 :
V_71 = V_73 ;
break;
case V_74 :
default:
V_71 = V_75 ;
break;
}
V_46 = F_18 ( V_4 , V_24 , F_26 ( 0 ) )
| ( V_76 ) ;
if ( V_4 -> V_30 == V_31 ) {
F_30 ( V_46 , V_77 ,
V_78 ,
V_70 -> V_79 ) ;
F_30 ( V_46 , V_80 ,
V_81 , V_71 ) ;
} else {
F_30 ( V_46 , V_82 ,
V_78 ,
V_70 -> V_79 ) ;
F_30 ( V_46 , V_83 ,
V_84 , V_71 ) ;
}
F_22 ( V_4 , V_46 , V_24 , F_26 ( 0 ) ) ;
F_22 ( V_4 , V_70 -> V_85 << V_86 ,
V_24 , F_35 ( 0 ) ) ;
F_22 ( V_4 , V_70 -> V_87 << V_86 ,
V_24 , F_36 ( 0 ) ) ;
V_46 = V_88 |
V_89 |
V_90 |
V_91 |
V_92 |
V_93 ;
F_22 ( V_4 , V_46 , V_24 , V_94 ) ;
F_17 ( V_4 , V_24 , V_95 , V_46 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_96 * V_97 = F_38 ( & V_2 -> V_98 . V_99 ) ;
const struct V_100 * V_45 ;
struct V_101 * V_71 ;
struct V_102 * V_103 ;
struct V_104 * V_105 ;
T_2 V_106 = 0 ;
int V_35 ;
F_21 ( V_2 ) ;
V_103 = F_39 ( & V_2 -> V_107 [ V_108 ] ) ;
V_105 = F_40 ( V_103 -> V_99 ) ;
V_45 = F_41 ( V_97 -> V_109 ) ;
V_35 = F_29 ( V_2 , & V_45 -> V_110 . V_2 ) ;
if ( V_35 < 0 )
return V_35 ;
F_31 ( V_2 , V_45 -> V_110 . V_2 . V_62 + 1 ) ;
F_42 ( V_105 , V_105 , V_111 , & V_106 ) ;
V_71 = & V_2 -> V_112 [ V_108 ] ;
V_2 -> V_113 . V_85 = V_106 ;
V_2 -> V_113 . V_79 = V_45 -> V_110 . V_2 . V_79 ;
V_2 -> V_113 . V_71 = V_71 -> V_114 ;
V_2 -> V_113 . V_87 = V_71 -> V_115 ;
F_34 ( V_2 , & V_2 -> V_113 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_96 * V_97 = F_38 ( & V_2 -> V_98 . V_99 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_101 * V_116 = & V_2 -> V_112 [ V_117 ] ;
unsigned long V_118 = V_97 -> V_118 ;
struct V_119 * V_120 ;
unsigned int V_62 = 2 ;
unsigned int V_121 ;
T_3 V_122 ;
T_3 V_123 ;
V_62 = F_44 (unsigned int, DIV_ROUND_UP(l3_ick, pipe->max_rate),
vpclk_div) ;
V_120 = & V_97 -> V_124 ;
if ( V_120 -> V_125 ) {
V_123 = V_116 -> V_126 * V_116 -> V_115 ;
V_122 = F_45 ( V_123 * V_120 -> V_127 ,
V_120 -> V_125 ) ;
V_121 = F_46 ( T_3 , V_122 , V_118 ) ;
V_62 = F_44 (unsigned int, l3_ick / value, vpclk_div) ;
}
F_3 ( V_4 -> V_5 , L_5 , V_128 ,
V_62 ) ;
return V_62 ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_129 * V_70 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_130 = V_2 -> V_112 [ V_108 ] . V_114 ;
T_2 V_131 = V_2 -> V_112 [ V_117 ] . V_114 ;
unsigned int V_132 = 0 ;
T_2 V_46 , V_133 ;
if ( V_130 != V_131 &&
V_130 == V_72 )
V_132 = 1 ;
F_21 ( V_2 ) ;
F_22 ( V_4 , V_134 |
( V_70 -> V_135 << V_136 ) ,
V_24 , V_137 ) ;
F_22 ( V_4 , V_70 -> V_138 << V_139 ,
V_24 , V_140 ) ;
if ( V_2 -> V_141 . V_142 == 0 )
V_70 -> V_143 = 0 ;
else
V_70 -> V_143 = V_2 -> V_141 . V_144 ;
F_22 ( V_4 , V_70 -> V_143 , V_24 ,
V_145 ) ;
V_46 = V_146 <<
V_147 ;
if ( V_132 ) {
V_46 |= V_148 <<
V_149 ;
V_46 |= V_150 ;
V_46 |= V_151 <<
V_152 ;
} else {
V_46 |= V_153 <<
V_149 ;
}
V_46 |= V_154 <<
V_155 ;
F_22 ( V_4 , V_46 , V_24 , V_42 ) ;
if ( V_132 )
V_133 = ( V_134 +
V_70 -> V_135 ) >> 3 ;
else
V_133 = ( V_134 +
V_70 -> V_135 ) >> 2 ;
F_22 ( V_4 , V_133 << V_156 ,
V_24 , V_157 ) ;
F_17 ( V_4 , V_24 , V_39 ,
V_158 | V_40 ) ;
F_31 ( V_2 , F_43 ( V_2 ) ) ;
F_22 ( V_4 , V_159 |
V_160 ,
V_24 , V_161 ) ;
F_17 ( V_4 , V_24 , V_162 ,
V_160 |
V_159 ) ;
}
static void F_48 ( struct V_1 * V_2 , T_2 V_163 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_22 ( V_4 , V_163 , V_24 , V_164 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_96 * V_97 = F_38 ( & V_2 -> V_98 . V_99 ) ;
struct V_165 * V_166 ;
V_166 = F_50 ( & V_2 -> V_141 ) ;
if ( V_166 != NULL )
F_48 ( V_2 , V_166 -> V_167 ) ;
V_97 -> V_168 |= V_169 ;
if ( V_2 -> V_168 == V_170 ) {
if ( F_51 ( V_97 ) )
F_52 ( V_97 ,
V_170 ) ;
}
}
void F_53 ( struct V_1 * V_2 )
{
struct V_96 * V_97 = F_38 ( & V_2 -> V_98 . V_99 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
static const T_2 V_171 =
V_88 |
V_89 |
V_90 |
V_91 |
V_92 |
V_93 ;
T_2 V_172 , V_173 ;
V_172 = F_18 ( V_4 , V_24 ,
V_94 ) ;
F_22 ( V_4 , V_172 , V_24 ,
V_94 ) ;
V_173 = F_18 ( V_4 , V_24 ,
V_161 ) ;
F_22 ( V_4 , V_173 , V_24 ,
V_161 ) ;
if ( V_172 & V_171 ) {
V_97 -> error = true ;
F_3 ( V_4 -> V_5 , L_6 , V_172 ) ;
return;
}
if ( V_173 & V_159 ) {
V_97 -> error = true ;
F_3 ( V_4 -> V_5 , L_7 , V_173 ) ;
}
if ( F_54 ( & V_2 -> V_174 , & V_2 -> V_175 ) )
return;
if ( V_173 & V_160 )
F_49 ( V_2 ) ;
}
static struct V_101 *
F_55 ( struct V_1 * V_2 , struct V_176 * V_177 ,
unsigned int V_103 , enum V_178 V_179 )
{
if ( V_179 == V_180 )
return F_56 ( & V_2 -> V_98 , V_177 , V_103 ) ;
else
return & V_2 -> V_112 [ V_103 ] ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_176 * V_177 , unsigned int V_103 ,
struct V_101 * V_181 ,
enum V_178 V_179 )
{
struct V_101 * V_71 ;
switch ( V_103 ) {
case V_108 :
if ( V_181 -> V_114 != V_72 )
V_181 -> V_114 = V_74 ;
if ( V_2 -> V_182 == V_183 ) {
V_181 -> V_126 = F_32 ( T_2 , V_181 -> V_126 ,
V_184 ,
V_185 ) ;
V_181 -> V_115 = F_32 ( T_2 , V_181 -> V_115 ,
V_186 ,
V_187 ) ;
} else if ( V_2 -> V_182 == V_188 ) {
V_181 -> V_126 = F_32 ( T_2 , V_181 -> V_126 ,
V_189 ,
V_190 ) ;
V_181 -> V_115 = F_32 ( T_2 , V_181 -> V_115 ,
V_191 ,
V_192 ) ;
}
break;
case V_117 :
V_71 = F_55 ( V_2 , V_177 , V_108 , V_179 ) ;
memcpy ( V_181 , V_71 , sizeof( * V_181 ) ) ;
V_181 -> V_114 = V_74 ;
break;
}
V_181 -> V_193 = V_194 ;
V_181 -> V_195 = V_196 ;
}
static int F_58 ( struct V_104 * V_197 ,
struct V_176 * V_177 ,
struct V_198 * V_114 )
{
struct V_1 * V_2 = F_59 ( V_197 ) ;
struct V_101 * V_71 ;
if ( V_114 -> V_103 == V_108 ) {
if ( V_114 -> V_199 >= F_60 ( V_200 ) )
return - V_201 ;
V_114 -> V_114 = V_200 [ V_114 -> V_199 ] ;
} else {
if ( V_114 -> V_199 != 0 )
return - V_201 ;
V_71 = F_55 ( V_2 , V_177 , V_108 ,
V_114 -> V_179 ) ;
V_114 -> V_114 = V_71 -> V_114 ;
}
return 0 ;
}
static int F_61 ( struct V_104 * V_197 ,
struct V_176 * V_177 ,
struct V_202 * V_203 )
{
struct V_1 * V_2 = F_59 ( V_197 ) ;
struct V_101 V_71 ;
if ( V_203 -> V_199 != 0 )
return - V_201 ;
V_71 . V_114 = V_203 -> V_114 ;
V_71 . V_126 = 1 ;
V_71 . V_115 = 1 ;
F_57 ( V_2 , V_177 , V_203 -> V_103 , & V_71 , V_203 -> V_179 ) ;
V_203 -> V_204 = V_71 . V_126 ;
V_203 -> V_205 = V_71 . V_115 ;
if ( V_71 . V_114 != V_203 -> V_114 )
return - V_201 ;
V_71 . V_114 = V_203 -> V_114 ;
V_71 . V_126 = - 1 ;
V_71 . V_115 = - 1 ;
F_57 ( V_2 , V_177 , V_203 -> V_103 , & V_71 , V_203 -> V_179 ) ;
V_203 -> V_206 = V_71 . V_126 ;
V_203 -> V_207 = V_71 . V_115 ;
return 0 ;
}
static int F_62 ( struct V_104 * V_197 , struct V_176 * V_177 ,
struct V_208 * V_181 )
{
struct V_1 * V_2 = F_59 ( V_197 ) ;
struct V_101 * V_71 ;
V_71 = F_55 ( V_2 , V_177 , V_181 -> V_103 , V_181 -> V_179 ) ;
if ( V_71 == NULL )
return - V_201 ;
V_181 -> V_71 = * V_71 ;
return 0 ;
}
static int F_63 ( struct V_104 * V_197 , struct V_176 * V_177 ,
struct V_208 * V_181 )
{
struct V_1 * V_2 = F_59 ( V_197 ) ;
struct V_101 * V_71 ;
V_71 = F_55 ( V_2 , V_177 , V_181 -> V_103 , V_181 -> V_179 ) ;
if ( V_71 == NULL )
return - V_201 ;
F_57 ( V_2 , V_177 , V_181 -> V_103 , & V_181 -> V_71 , V_181 -> V_179 ) ;
* V_71 = V_181 -> V_71 ;
if ( V_181 -> V_103 == V_108 ) {
V_71 = F_55 ( V_2 , V_177 , V_117 ,
V_181 -> V_179 ) ;
* V_71 = V_181 -> V_71 ;
F_57 ( V_2 , V_177 , V_117 , V_71 , V_181 -> V_179 ) ;
}
return 0 ;
}
static int F_64 ( struct V_104 * V_197 , struct V_209 * V_210 )
{
struct V_208 V_71 ;
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
V_71 . V_103 = V_108 ;
V_71 . V_179 = V_210 ? V_180 : V_211 ;
V_71 . V_71 . V_114 = V_74 ;
V_71 . V_71 . V_126 = 4096 ;
V_71 . V_71 . V_115 = 4096 ;
F_63 ( V_197 , V_210 ? V_210 -> V_103 : NULL , & V_71 ) ;
return 0 ;
}
static int F_65 ( struct V_104 * V_197 , int V_34 )
{
struct V_1 * V_2 = F_59 ( V_197 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_212 * V_5 = F_66 ( V_2 ) ;
int V_35 ;
if ( V_2 -> V_168 == V_213 ) {
if ( V_34 == V_213 )
return 0 ;
F_67 ( & V_2 -> V_175 , 0 ) ;
}
switch ( V_34 ) {
case V_214 :
if ( V_2 -> V_215 ) {
V_35 = F_68 ( V_2 -> V_215 , & V_197 -> V_99 ) ;
if ( V_35 < 0 )
return V_35 ;
}
F_37 ( V_2 ) ;
F_1 ( V_2 ) ;
V_35 = F_23 ( V_2 , 1 ) ;
if ( V_35 < 0 ) {
if ( V_2 -> V_215 )
F_69 ( V_2 -> V_215 ) ;
return V_35 ;
}
break;
case V_170 :
if ( V_2 -> V_168 != V_170 ) {
struct V_101 * V_71 ;
V_71 = & V_2 -> V_112 [ V_108 ] ;
V_2 -> V_216 . V_135 = V_71 -> V_126 ;
V_2 -> V_216 . V_138 = V_71 -> V_115 ;
V_2 -> V_216 . V_143 = 0 ;
F_47 ( V_2 , & V_2 -> V_216 ) ;
F_70 ( V_4 , V_217 ) ;
F_1 ( V_2 ) ;
}
F_28 ( V_2 , 1 ) ;
break;
case V_213 :
if ( F_71 ( & V_197 -> V_99 , & V_2 -> V_174 ,
& V_2 -> V_175 ) )
F_3 ( V_5 , L_8 , V_197 -> V_218 ) ;
if ( V_2 -> V_182 == V_188 ) {
F_28 ( V_2 , 0 ) ;
F_72 ( V_4 , V_217 ) ;
} else if ( V_2 -> V_182 == V_183 ) {
F_23 ( V_2 , 0 ) ;
if ( V_2 -> V_215 )
F_69 ( V_2 -> V_215 ) ;
}
break;
}
V_2 -> V_168 = V_34 ;
return 0 ;
}
static int F_73 ( struct V_219 * V_220 , struct V_165 * V_166 )
{
struct V_1 * V_2 = & V_220 -> V_4 -> V_221 ;
F_48 ( V_2 , V_166 -> V_167 ) ;
return 0 ;
}
static int F_74 ( struct V_222 * V_99 ,
const struct V_102 * V_223 ,
const struct V_102 * V_224 , T_2 V_225 )
{
struct V_104 * V_197 = F_40 ( V_99 ) ;
struct V_1 * V_2 = F_59 ( V_197 ) ;
unsigned int V_199 = V_223 -> V_199 ;
if ( F_75 ( V_224 -> V_99 ) )
V_199 |= 2 << 16 ;
switch ( V_199 ) {
case V_108 :
if ( V_225 & V_226 ) {
if ( V_2 -> V_182 == V_183 )
return - V_227 ;
V_2 -> V_182 = V_188 ;
} else {
if ( V_2 -> V_182 == V_188 )
V_2 -> V_182 = V_228 ;
}
break;
case V_108 | 2 << 16 :
if ( V_225 & V_226 ) {
if ( V_2 -> V_182 == V_188 )
return - V_227 ;
V_2 -> V_182 = V_183 ;
} else {
if ( V_2 -> V_182 == V_183 )
V_2 -> V_182 = V_228 ;
} break;
case V_117 | 2 << 16 :
if ( V_225 & V_226 )
V_2 -> V_229 = V_230 ;
else
V_2 -> V_229 = V_231 ;
break;
default:
return - V_201 ;
}
return 0 ;
}
void F_76 ( struct V_1 * V_2 )
{
F_77 ( & V_2 -> V_98 ) ;
F_78 ( & V_2 -> V_141 ) ;
}
int F_79 ( struct V_1 * V_2 ,
struct V_232 * V_233 )
{
int V_35 ;
V_35 = F_80 ( V_233 , & V_2 -> V_98 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_81 ( & V_2 -> V_141 , V_233 ) ;
if ( V_35 < 0 )
goto error;
return 0 ;
error:
F_76 ( V_2 ) ;
return V_35 ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_104 * V_197 = & V_2 -> V_98 ;
struct V_102 * V_107 = V_2 -> V_107 ;
struct V_222 * V_234 = & V_197 -> V_99 ;
int V_35 ;
V_2 -> V_182 = V_228 ;
V_2 -> V_229 = V_231 ;
F_83 ( V_197 , & V_235 ) ;
V_197 -> V_236 = & V_237 ;
F_84 ( V_197 -> V_218 , L_9 , sizeof( V_197 -> V_218 ) ) ;
V_197 -> V_238 = 1 << 16 ;
F_85 ( V_197 , V_2 ) ;
V_197 -> V_225 |= V_239 ;
V_107 [ V_108 ] . V_225 = V_240
| V_241 ;
V_107 [ V_117 ] . V_225 = V_242 ;
V_234 -> V_243 = & V_244 ;
V_35 = F_86 ( V_234 , V_245 , V_107 ) ;
if ( V_35 < 0 )
return V_35 ;
F_64 ( V_197 , NULL ) ;
V_2 -> V_141 . type = V_246 ;
V_2 -> V_141 . V_247 = 32 ;
V_2 -> V_141 . V_248 = 0xffffffe0 ;
V_2 -> V_141 . V_4 = F_2 ( V_2 ) ;
V_2 -> V_141 . V_243 = & V_249 ;
V_2 -> V_141 . V_250 = F_87 ( 4096 * 4096 ) * 3 ;
V_35 = F_88 ( & V_2 -> V_141 , L_10 ) ;
if ( V_35 < 0 )
goto error;
return 0 ;
error:
F_89 ( & V_2 -> V_98 . V_99 ) ;
return V_35 ;
}
int F_90 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_221 ;
int V_35 ;
F_91 ( & V_2 -> V_174 ) ;
if ( V_4 -> V_30 == V_251 ) {
V_2 -> V_36 = F_92 ( V_4 -> V_5 , L_11 ) ;
if ( F_93 ( V_2 -> V_36 ) ) {
if ( F_94 ( V_2 -> V_36 ) == - V_252 ) {
F_3 ( V_4 -> V_5 ,
L_12 ) ;
return - V_252 ;
}
F_3 ( V_4 -> V_5 ,
L_13 ) ;
V_2 -> V_36 = NULL ;
}
V_2 -> V_215 = & V_4 -> V_253 ;
} else if ( V_4 -> V_30 == V_31 ) {
V_2 -> V_215 = & V_4 -> V_254 ;
}
V_35 = F_82 ( V_2 ) ;
if ( V_35 < 0 )
return V_35 ;
F_16 ( V_2 ) ;
return 0 ;
}
void F_95 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_221 ;
F_96 ( & V_2 -> V_141 ) ;
F_89 ( & V_2 -> V_98 . V_99 ) ;
}
