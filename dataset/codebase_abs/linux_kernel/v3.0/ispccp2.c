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
static void F_23 ( struct V_1 * V_2 , T_1 V_34 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_35 * V_36 = F_24 ( & V_2 -> V_37 . V_38 ) ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_39 ; V_23 ++ )
F_25 ( V_4 , V_24 , F_26 ( V_23 ) ,
V_40 ,
V_34 ? V_40 : 0 ) ;
F_25 ( V_4 , V_24 , V_41 ,
V_42 | V_43 ,
V_34 ? ( V_42 | V_43 ) : 0 ) ;
if ( V_36 -> V_44 ) {
if ( V_34 )
F_17 ( V_4 , V_24 ,
V_45 ,
V_46 ) ;
else
F_27 ( V_4 , V_24 ,
V_45 ,
V_46 ) ;
}
}
static void F_28 ( struct V_1 * V_2 , T_1 V_34 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_34 )
F_23 ( V_2 , 0 ) ;
F_25 ( V_4 , V_24 , V_41 ,
V_42 , V_34 ? V_42 : 0 ) ;
F_25 ( V_4 , V_24 , V_47 ,
V_48 ,
V_34 ? V_48 : 0 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
const struct V_49 * V_50 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_51 ;
V_51 = F_18 ( V_4 , V_24 , V_41 ) |
V_52 | V_42 ;
F_30 ( V_51 , V_53 , V_54 ,
V_50 -> V_55 ) ;
F_30 ( V_51 , V_56 , V_57 ,
V_50 -> V_58 ) ;
F_22 ( V_4 , V_51 , V_24 , V_41 ) ;
V_51 = F_18 ( V_4 , V_24 , V_41 ) ;
if ( ! ( V_51 & V_42 ) ) {
if ( V_50 -> V_59 )
F_20 ( V_4 -> V_5 , L_4 ) ;
if ( V_50 -> V_55 == V_60 )
return - V_61 ;
}
return 0 ;
}
static void F_31 ( struct V_1 * V_2 ,
unsigned int V_62 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_51 ;
V_51 = F_18 ( V_4 , V_24 , V_41 ) ;
V_51 |= V_63 ;
if ( V_4 -> V_30 == V_31 ) {
V_62 = F_32 (unsigned int, vpclk_div, 1 , 65536 ) ;
V_62 = F_33 ( V_64 / V_62 , 65535U ) ;
F_30 ( V_51 , V_65 ,
V_66 , V_62 ) ;
} else {
V_62 = F_32 (unsigned int, vpclk_div, 1 , 4 ) ;
F_30 ( V_51 , V_67 ,
V_68 , V_62 - 1 ) ;
}
F_22 ( V_4 , V_51 , V_24 , V_41 ) ;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_69 * V_70 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_51 , V_71 ;
switch ( V_70 -> V_71 ) {
case V_72 :
V_71 = V_73 ;
break;
case V_74 :
default:
V_71 = V_75 ;
break;
}
V_51 = F_18 ( V_4 , V_24 , F_26 ( 0 ) )
| ( V_76 ) ;
if ( V_4 -> V_30 == V_31 ) {
F_30 ( V_51 , V_77 ,
V_78 ,
V_70 -> V_79 ) ;
F_30 ( V_51 , V_80 ,
V_81 , V_71 ) ;
} else {
F_30 ( V_51 , V_82 ,
V_78 ,
V_70 -> V_79 ) ;
F_30 ( V_51 , V_83 ,
V_84 , V_71 ) ;
}
F_22 ( V_4 , V_51 , V_24 , F_26 ( 0 ) ) ;
F_22 ( V_4 , V_70 -> V_85 << V_86 ,
V_24 , F_35 ( 0 ) ) ;
F_22 ( V_4 , V_70 -> V_87 << V_86 ,
V_24 , F_36 ( 0 ) ) ;
V_51 = V_88 |
V_89 |
V_90 |
V_91 |
V_46 |
V_92 |
V_93 ;
F_22 ( V_4 , V_51 , V_24 , V_94 ) ;
F_17 ( V_4 , V_24 , V_45 , V_51 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
const struct V_95 * V_50 ;
struct V_96 * V_71 ;
struct V_97 * V_98 ;
struct V_99 * V_100 ;
T_2 V_101 = 0 ;
int V_102 ;
F_21 ( V_2 ) ;
V_98 = F_38 ( & V_2 -> V_103 [ V_104 ] ) ;
V_100 = F_39 ( V_98 -> V_38 ) ;
V_50 = V_100 -> V_105 ;
V_102 = F_29 ( V_2 , & V_50 -> V_106 . V_2 ) ;
if ( V_102 < 0 )
return V_102 ;
F_31 ( V_2 , V_50 -> V_106 . V_2 . V_62 + 1 ) ;
F_40 ( V_100 , V_100 , V_107 , & V_101 ) ;
V_71 = & V_2 -> V_108 [ V_104 ] ;
V_2 -> V_109 . V_85 = V_101 ;
V_2 -> V_109 . V_79 = V_50 -> V_106 . V_2 . V_79 ;
V_2 -> V_109 . V_71 = V_71 -> V_110 ;
V_2 -> V_109 . V_87 = V_71 -> V_111 ;
F_34 ( V_2 , & V_2 -> V_109 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = F_24 ( & V_2 -> V_37 . V_38 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_96 * V_112 = & V_2 -> V_108 [ V_113 ] ;
unsigned long V_114 = V_36 -> V_114 ;
struct V_115 * V_116 ;
unsigned int V_62 = 2 ;
unsigned int V_117 ;
T_3 V_118 ;
T_3 V_119 ;
V_62 = F_42 (unsigned int, DIV_ROUND_UP(l3_ick, pipe->max_rate),
vpclk_div) ;
V_116 = & V_36 -> V_120 ;
if ( V_116 -> V_121 ) {
V_119 = V_112 -> V_122 * V_112 -> V_111 ;
V_118 = F_43 ( V_119 * V_116 -> V_123 ,
V_116 -> V_121 ) ;
V_117 = F_44 ( T_3 , V_118 , V_114 ) ;
V_62 = F_42 (unsigned int, l3_ick / value, vpclk_div) ;
}
F_3 ( V_4 -> V_5 , L_5 , V_124 ,
V_62 ) ;
return V_62 ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_125 * V_70 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_126 = V_2 -> V_108 [ V_104 ] . V_110 ;
T_2 V_127 = V_2 -> V_108 [ V_113 ] . V_110 ;
unsigned int V_128 = 0 ;
T_2 V_51 , V_129 ;
if ( V_126 != V_127 &&
V_126 == V_72 )
V_128 = 1 ;
F_21 ( V_2 ) ;
F_22 ( V_4 , V_130 |
( V_70 -> V_131 << V_132 ) ,
V_24 , V_133 ) ;
F_22 ( V_4 , V_70 -> V_134 << V_135 ,
V_24 , V_136 ) ;
if ( V_2 -> V_137 . V_138 == 0 )
V_70 -> V_139 = 0 ;
else
V_70 -> V_139 = V_2 -> V_137 . V_140 ;
F_22 ( V_4 , V_70 -> V_139 , V_24 ,
V_141 ) ;
V_51 = V_142 <<
V_143 ;
if ( V_128 ) {
V_51 |= V_144 <<
V_145 ;
V_51 |= V_146 ;
V_51 |= V_147 <<
V_148 ;
} else {
V_51 |= V_149 <<
V_145 ;
}
V_51 |= V_150 <<
V_151 ;
F_22 ( V_4 , V_51 , V_24 , V_47 ) ;
if ( V_128 )
V_129 = ( V_130 +
V_70 -> V_131 ) >> 3 ;
else
V_129 = ( V_130 +
V_70 -> V_131 ) >> 2 ;
F_22 ( V_4 , V_129 << V_152 ,
V_24 , V_153 ) ;
F_17 ( V_4 , V_24 , V_41 ,
V_52 | V_42 ) ;
F_31 ( V_2 , F_41 ( V_2 ) ) ;
F_22 ( V_4 , V_154 |
V_155 ,
V_24 , V_156 ) ;
F_17 ( V_4 , V_24 , V_157 ,
V_155 |
V_154 ) ;
}
static void F_46 ( struct V_1 * V_2 , T_2 V_158 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_22 ( V_4 , V_158 , V_24 , V_159 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = F_24 ( & V_2 -> V_37 . V_38 ) ;
struct V_160 * V_161 ;
V_161 = F_48 ( & V_2 -> V_137 , V_2 -> error ) ;
if ( V_161 != NULL )
F_46 ( V_2 , V_161 -> V_162 ) ;
V_36 -> V_163 |= V_164 ;
if ( V_2 -> V_163 == V_165 ) {
if ( F_49 ( V_36 ) )
F_50 ( V_36 ,
V_165 ) ;
}
V_2 -> error = 0 ;
}
int F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_102 = 0 ;
static const T_2 V_166 =
V_88 |
V_89 |
V_90 |
V_91 |
V_92 |
V_93 ;
T_2 V_167 , V_168 ;
V_167 = F_18 ( V_4 , V_24 ,
V_94 ) ;
F_22 ( V_4 , V_167 , V_24 ,
V_94 ) ;
V_168 = F_18 ( V_4 , V_24 ,
V_156 ) ;
F_22 ( V_4 , V_168 , V_24 ,
V_156 ) ;
if ( V_167 & V_166 ) {
V_2 -> error = 1 ;
F_3 ( V_4 -> V_5 , L_6 , V_167 ) ;
return - V_61 ;
}
if ( V_168 & V_154 ) {
V_2 -> error = 1 ;
F_3 ( V_4 -> V_5 , L_7 , V_168 ) ;
V_102 = - V_61 ;
}
if ( F_52 ( & V_2 -> V_169 , & V_2 -> V_170 ) )
return 0 ;
if ( V_167 & V_46 ) {
struct V_35 * V_36 =
F_24 ( & V_2 -> V_37 . V_38 ) ;
if ( V_36 -> V_44 )
F_53 ( & V_36 -> V_171 ) ;
}
if ( V_168 & V_155 )
F_47 ( V_2 ) ;
return V_102 ;
}
static struct V_96 *
F_54 ( struct V_1 * V_2 , struct V_172 * V_173 ,
unsigned int V_98 , enum V_174 V_175 )
{
if ( V_175 == V_176 )
return F_55 ( V_173 , V_98 ) ;
else
return & V_2 -> V_108 [ V_98 ] ;
}
static void F_56 ( struct V_1 * V_2 ,
struct V_172 * V_173 , unsigned int V_98 ,
struct V_96 * V_177 ,
enum V_174 V_175 )
{
struct V_96 * V_71 ;
switch ( V_98 ) {
case V_104 :
if ( V_177 -> V_110 != V_72 )
V_177 -> V_110 = V_74 ;
if ( V_2 -> V_178 == V_179 ) {
V_177 -> V_122 = F_32 ( T_2 , V_177 -> V_122 ,
V_180 ,
V_181 ) ;
V_177 -> V_111 = F_32 ( T_2 , V_177 -> V_111 ,
V_182 ,
V_183 ) ;
} else if ( V_2 -> V_178 == V_184 ) {
V_177 -> V_122 = F_32 ( T_2 , V_177 -> V_122 ,
V_185 ,
V_186 ) ;
V_177 -> V_111 = F_32 ( T_2 , V_177 -> V_111 ,
V_187 ,
V_188 ) ;
}
break;
case V_113 :
V_71 = F_54 ( V_2 , V_173 , V_104 , V_175 ) ;
memcpy ( V_177 , V_71 , sizeof( * V_177 ) ) ;
V_177 -> V_110 = V_74 ;
break;
}
V_177 -> V_189 = V_190 ;
V_177 -> V_191 = V_192 ;
}
static int F_57 ( struct V_99 * V_193 ,
struct V_172 * V_173 ,
struct V_194 * V_110 )
{
struct V_1 * V_2 = F_58 ( V_193 ) ;
struct V_96 * V_71 ;
if ( V_110 -> V_98 == V_104 ) {
if ( V_110 -> V_195 >= F_59 ( V_196 ) )
return - V_197 ;
V_110 -> V_110 = V_196 [ V_110 -> V_195 ] ;
} else {
if ( V_110 -> V_195 != 0 )
return - V_197 ;
V_71 = F_54 ( V_2 , V_173 , V_104 ,
V_176 ) ;
V_110 -> V_110 = V_71 -> V_110 ;
}
return 0 ;
}
static int F_60 ( struct V_99 * V_193 ,
struct V_172 * V_173 ,
struct V_198 * V_199 )
{
struct V_1 * V_2 = F_58 ( V_193 ) ;
struct V_96 V_71 ;
if ( V_199 -> V_195 != 0 )
return - V_197 ;
V_71 . V_110 = V_199 -> V_110 ;
V_71 . V_122 = 1 ;
V_71 . V_111 = 1 ;
F_56 ( V_2 , V_173 , V_199 -> V_98 , & V_71 , V_176 ) ;
V_199 -> V_200 = V_71 . V_122 ;
V_199 -> V_201 = V_71 . V_111 ;
if ( V_71 . V_110 != V_199 -> V_110 )
return - V_197 ;
V_71 . V_110 = V_199 -> V_110 ;
V_71 . V_122 = - 1 ;
V_71 . V_111 = - 1 ;
F_56 ( V_2 , V_173 , V_199 -> V_98 , & V_71 , V_176 ) ;
V_199 -> V_202 = V_71 . V_122 ;
V_199 -> V_203 = V_71 . V_111 ;
return 0 ;
}
static int F_61 ( struct V_99 * V_193 , struct V_172 * V_173 ,
struct V_204 * V_177 )
{
struct V_1 * V_2 = F_58 ( V_193 ) ;
struct V_96 * V_71 ;
V_71 = F_54 ( V_2 , V_173 , V_177 -> V_98 , V_177 -> V_175 ) ;
if ( V_71 == NULL )
return - V_197 ;
V_177 -> V_71 = * V_71 ;
return 0 ;
}
static int F_62 ( struct V_99 * V_193 , struct V_172 * V_173 ,
struct V_204 * V_177 )
{
struct V_1 * V_2 = F_58 ( V_193 ) ;
struct V_96 * V_71 ;
V_71 = F_54 ( V_2 , V_173 , V_177 -> V_98 , V_177 -> V_175 ) ;
if ( V_71 == NULL )
return - V_197 ;
F_56 ( V_2 , V_173 , V_177 -> V_98 , & V_177 -> V_71 , V_177 -> V_175 ) ;
* V_71 = V_177 -> V_71 ;
if ( V_177 -> V_98 == V_104 ) {
V_71 = F_54 ( V_2 , V_173 , V_113 ,
V_177 -> V_175 ) ;
* V_71 = V_177 -> V_71 ;
F_56 ( V_2 , V_173 , V_113 , V_71 , V_177 -> V_175 ) ;
}
return 0 ;
}
static int F_63 ( struct V_99 * V_193 , struct V_172 * V_173 )
{
struct V_204 V_71 ;
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
V_71 . V_98 = V_104 ;
V_71 . V_175 = V_173 ? V_176 : V_205 ;
V_71 . V_71 . V_110 = V_74 ;
V_71 . V_71 . V_122 = 4096 ;
V_71 . V_71 . V_111 = 4096 ;
F_62 ( V_193 , V_173 , & V_71 ) ;
return 0 ;
}
static int F_64 ( struct V_99 * V_193 , int V_34 )
{
struct V_1 * V_2 = F_58 ( V_193 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_206 * V_5 = F_65 ( V_2 ) ;
int V_102 ;
if ( V_2 -> V_163 == V_207 ) {
if ( V_34 == V_207 )
return 0 ;
F_66 ( & V_2 -> V_170 , 0 ) ;
V_2 -> error = 0 ;
}
switch ( V_34 ) {
case V_208 :
if ( V_2 -> V_209 ) {
V_102 = F_67 ( V_2 -> V_209 ) ;
if ( V_102 < 0 )
return V_102 ;
}
F_37 ( V_2 ) ;
F_1 ( V_2 ) ;
F_23 ( V_2 , 1 ) ;
break;
case V_165 :
if ( V_2 -> V_163 != V_165 ) {
struct V_96 * V_71 ;
V_71 = & V_2 -> V_108 [ V_104 ] ;
V_2 -> V_210 . V_131 = V_71 -> V_122 ;
V_2 -> V_210 . V_134 = V_71 -> V_111 ;
V_2 -> V_210 . V_139 = 0 ;
F_45 ( V_2 , & V_2 -> V_210 ) ;
F_68 ( V_4 , V_211 ) ;
F_1 ( V_2 ) ;
}
F_28 ( V_2 , 1 ) ;
break;
case V_207 :
if ( F_69 ( & V_193 -> V_38 , & V_2 -> V_169 ,
& V_2 -> V_170 ) )
F_3 ( V_5 , L_8 , V_193 -> V_212 ) ;
if ( V_2 -> V_178 == V_184 ) {
F_28 ( V_2 , 0 ) ;
F_70 ( V_4 , V_211 ) ;
} else if ( V_2 -> V_178 == V_179 ) {
F_23 ( V_2 , 0 ) ;
if ( V_2 -> V_209 )
F_71 ( V_2 -> V_209 ) ;
}
break;
}
V_2 -> V_163 = V_34 ;
return 0 ;
}
static int F_72 ( struct V_213 * V_214 , struct V_160 * V_161 )
{
struct V_1 * V_2 = & V_214 -> V_4 -> V_215 ;
F_46 ( V_2 , V_161 -> V_162 ) ;
return 0 ;
}
static int F_73 ( struct V_216 * V_38 ,
const struct V_97 * V_217 ,
const struct V_97 * V_218 , T_2 V_219 )
{
struct V_99 * V_193 = F_39 ( V_38 ) ;
struct V_1 * V_2 = F_58 ( V_193 ) ;
switch ( V_217 -> V_195 | F_74 ( V_218 -> V_38 ) ) {
case V_104 | V_220 :
if ( V_219 & V_221 ) {
if ( V_2 -> V_178 == V_179 )
return - V_222 ;
V_2 -> V_178 = V_184 ;
} else {
if ( V_2 -> V_178 == V_184 )
V_2 -> V_178 = V_223 ;
}
break;
case V_104 | V_224 :
if ( V_219 & V_221 ) {
if ( V_2 -> V_178 == V_184 )
return - V_222 ;
V_2 -> V_178 = V_179 ;
} else {
if ( V_2 -> V_178 == V_179 )
V_2 -> V_178 = V_223 ;
} break;
case V_113 | V_224 :
if ( V_219 & V_221 )
V_2 -> V_225 = V_226 ;
else
V_2 -> V_225 = V_227 ;
break;
default:
return - V_197 ;
}
return 0 ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_99 * V_193 = & V_2 -> V_37 ;
struct V_97 * V_103 = V_2 -> V_103 ;
struct V_216 * V_228 = & V_193 -> V_38 ;
int V_102 ;
V_2 -> V_178 = V_223 ;
V_2 -> V_225 = V_227 ;
F_76 ( V_193 , & V_229 ) ;
V_193 -> V_230 = & V_231 ;
F_77 ( V_193 -> V_212 , L_9 , sizeof( V_193 -> V_212 ) ) ;
V_193 -> V_232 = 1 << 16 ;
F_78 ( V_193 , V_2 ) ;
V_193 -> V_219 |= V_233 ;
V_103 [ V_104 ] . V_219 = V_234 ;
V_103 [ V_113 ] . V_219 = V_235 ;
V_228 -> V_236 = & V_237 ;
V_102 = F_79 ( V_228 , V_238 , V_103 , 0 ) ;
if ( V_102 < 0 )
return V_102 ;
F_63 ( V_193 , NULL ) ;
V_2 -> V_137 . type = V_239 ;
V_2 -> V_137 . V_240 = 32 ;
V_2 -> V_137 . V_241 = 0xffffffe0 ;
V_2 -> V_137 . V_4 = F_2 ( V_2 ) ;
V_2 -> V_137 . V_236 = & V_242 ;
V_2 -> V_137 . V_243 = F_80 ( 4096 * 4096 ) * 3 ;
V_102 = F_81 ( & V_2 -> V_137 , L_10 ) ;
if ( V_102 < 0 )
return V_102 ;
V_102 = F_82 ( & V_2 -> V_137 . V_214 . V_38 , 0 ,
& V_2 -> V_37 . V_38 , V_104 , 0 ) ;
if ( V_102 < 0 )
return V_102 ;
return 0 ;
}
void F_83 ( struct V_1 * V_2 )
{
F_84 ( & V_2 -> V_37 . V_38 ) ;
F_85 ( & V_2 -> V_37 ) ;
F_86 ( & V_2 -> V_137 ) ;
}
int F_87 ( struct V_1 * V_2 ,
struct V_244 * V_245 )
{
int V_102 ;
V_102 = F_88 ( V_245 , & V_2 -> V_37 ) ;
if ( V_102 < 0 )
goto error;
V_102 = F_89 ( & V_2 -> V_137 , V_245 ) ;
if ( V_102 < 0 )
goto error;
return 0 ;
error:
F_83 ( V_2 ) ;
return V_102 ;
}
void F_90 ( struct V_3 * V_4 )
{
}
int F_91 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_215 ;
int V_102 ;
F_92 ( & V_2 -> V_169 ) ;
if ( V_4 -> V_30 == V_31 )
V_2 -> V_209 = & V_4 -> V_246 ;
V_102 = F_75 ( V_2 ) ;
if ( V_102 < 0 )
goto V_247;
F_16 ( V_2 ) ;
V_247:
if ( V_102 )
F_90 ( V_4 ) ;
return V_102 ;
}
