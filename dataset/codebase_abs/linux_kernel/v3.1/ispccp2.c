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
if ( V_34 && V_2 -> V_39 )
F_25 ( V_2 -> V_39 ) ;
for ( V_23 = 0 ; V_23 < V_40 ; V_23 ++ )
F_26 ( V_4 , V_24 , F_27 ( V_23 ) ,
V_41 ,
V_34 ? V_41 : 0 ) ;
F_26 ( V_4 , V_24 , V_42 ,
V_43 | V_44 ,
V_34 ? ( V_43 | V_44 ) : 0 ) ;
if ( V_36 -> V_45 ) {
if ( V_34 )
F_17 ( V_4 , V_24 ,
V_46 ,
V_47 ) ;
else
F_28 ( V_4 , V_24 ,
V_46 ,
V_47 ) ;
}
if ( ! V_34 && V_2 -> V_39 )
F_29 ( V_2 -> V_39 ) ;
}
static void F_30 ( struct V_1 * V_2 , T_1 V_34 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_34 )
F_23 ( V_2 , 0 ) ;
F_26 ( V_4 , V_24 , V_42 ,
V_43 , V_34 ? V_43 : 0 ) ;
F_26 ( V_4 , V_24 , V_48 ,
V_49 ,
V_34 ? V_49 : 0 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
const struct V_50 * V_51 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_52 ;
V_52 = F_18 ( V_4 , V_24 , V_42 ) |
V_53 | V_43 ;
F_32 ( V_52 , V_54 , V_55 ,
V_51 -> V_56 ) ;
F_32 ( V_52 , V_57 , V_58 ,
V_51 -> V_59 ) ;
F_22 ( V_4 , V_52 , V_24 , V_42 ) ;
V_52 = F_18 ( V_4 , V_24 , V_42 ) ;
if ( ! ( V_52 & V_43 ) ) {
if ( V_51 -> V_60 )
F_20 ( V_4 -> V_5 , L_4 ) ;
if ( V_51 -> V_56 == V_61 )
return - V_62 ;
}
return 0 ;
}
static void F_33 ( struct V_1 * V_2 ,
unsigned int V_63 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_52 ;
V_52 = F_18 ( V_4 , V_24 , V_42 ) ;
V_52 |= V_64 ;
if ( V_4 -> V_30 == V_31 ) {
V_63 = F_34 (unsigned int, vpclk_div, 1 , 65536 ) ;
V_63 = F_35 ( V_65 / V_63 , 65535U ) ;
F_32 ( V_52 , V_66 ,
V_67 , V_63 ) ;
} else {
V_63 = F_34 (unsigned int, vpclk_div, 1 , 4 ) ;
F_32 ( V_52 , V_68 ,
V_69 , V_63 - 1 ) ;
}
F_22 ( V_4 , V_52 , V_24 , V_42 ) ;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_70 * V_71 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_52 , V_72 ;
switch ( V_71 -> V_72 ) {
case V_73 :
V_72 = V_74 ;
break;
case V_75 :
default:
V_72 = V_76 ;
break;
}
V_52 = F_18 ( V_4 , V_24 , F_27 ( 0 ) )
| ( V_77 ) ;
if ( V_4 -> V_30 == V_31 ) {
F_32 ( V_52 , V_78 ,
V_79 ,
V_71 -> V_80 ) ;
F_32 ( V_52 , V_81 ,
V_82 , V_72 ) ;
} else {
F_32 ( V_52 , V_83 ,
V_79 ,
V_71 -> V_80 ) ;
F_32 ( V_52 , V_84 ,
V_85 , V_72 ) ;
}
F_22 ( V_4 , V_52 , V_24 , F_27 ( 0 ) ) ;
F_22 ( V_4 , V_71 -> V_86 << V_87 ,
V_24 , F_37 ( 0 ) ) ;
F_22 ( V_4 , V_71 -> V_88 << V_87 ,
V_24 , F_38 ( 0 ) ) ;
V_52 = V_89 |
V_90 |
V_91 |
V_92 |
V_47 |
V_93 |
V_94 ;
F_22 ( V_4 , V_52 , V_24 , V_95 ) ;
F_17 ( V_4 , V_24 , V_46 , V_52 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
const struct V_96 * V_51 ;
struct V_97 * V_72 ;
struct V_98 * V_99 ;
struct V_100 * V_101 ;
T_2 V_102 = 0 ;
int V_103 ;
F_21 ( V_2 ) ;
V_99 = F_40 ( & V_2 -> V_104 [ V_105 ] ) ;
V_101 = F_41 ( V_99 -> V_38 ) ;
V_51 = V_101 -> V_106 ;
V_103 = F_31 ( V_2 , & V_51 -> V_107 . V_2 ) ;
if ( V_103 < 0 )
return V_103 ;
F_33 ( V_2 , V_51 -> V_107 . V_2 . V_63 + 1 ) ;
F_42 ( V_101 , V_101 , V_108 , & V_102 ) ;
V_72 = & V_2 -> V_109 [ V_105 ] ;
V_2 -> V_110 . V_86 = V_102 ;
V_2 -> V_110 . V_80 = V_51 -> V_107 . V_2 . V_80 ;
V_2 -> V_110 . V_72 = V_72 -> V_111 ;
V_2 -> V_110 . V_88 = V_72 -> V_112 ;
F_36 ( V_2 , & V_2 -> V_110 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = F_24 ( & V_2 -> V_37 . V_38 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_97 * V_113 = & V_2 -> V_109 [ V_114 ] ;
unsigned long V_115 = V_36 -> V_115 ;
struct V_116 * V_117 ;
unsigned int V_63 = 2 ;
unsigned int V_118 ;
T_3 V_119 ;
T_3 V_120 ;
V_63 = F_44 (unsigned int, DIV_ROUND_UP(l3_ick, pipe->max_rate),
vpclk_div) ;
V_117 = & V_36 -> V_121 ;
if ( V_117 -> V_122 ) {
V_120 = V_113 -> V_123 * V_113 -> V_112 ;
V_119 = F_45 ( V_120 * V_117 -> V_124 ,
V_117 -> V_122 ) ;
V_118 = F_46 ( T_3 , V_119 , V_115 ) ;
V_63 = F_44 (unsigned int, l3_ick / value, vpclk_div) ;
}
F_3 ( V_4 -> V_5 , L_5 , V_125 ,
V_63 ) ;
return V_63 ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_126 * V_71 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_127 = V_2 -> V_109 [ V_105 ] . V_111 ;
T_2 V_128 = V_2 -> V_109 [ V_114 ] . V_111 ;
unsigned int V_129 = 0 ;
T_2 V_52 , V_130 ;
if ( V_127 != V_128 &&
V_127 == V_73 )
V_129 = 1 ;
F_21 ( V_2 ) ;
F_22 ( V_4 , V_131 |
( V_71 -> V_132 << V_133 ) ,
V_24 , V_134 ) ;
F_22 ( V_4 , V_71 -> V_135 << V_136 ,
V_24 , V_137 ) ;
if ( V_2 -> V_138 . V_139 == 0 )
V_71 -> V_140 = 0 ;
else
V_71 -> V_140 = V_2 -> V_138 . V_141 ;
F_22 ( V_4 , V_71 -> V_140 , V_24 ,
V_142 ) ;
V_52 = V_143 <<
V_144 ;
if ( V_129 ) {
V_52 |= V_145 <<
V_146 ;
V_52 |= V_147 ;
V_52 |= V_148 <<
V_149 ;
} else {
V_52 |= V_150 <<
V_146 ;
}
V_52 |= V_151 <<
V_152 ;
F_22 ( V_4 , V_52 , V_24 , V_48 ) ;
if ( V_129 )
V_130 = ( V_131 +
V_71 -> V_132 ) >> 3 ;
else
V_130 = ( V_131 +
V_71 -> V_132 ) >> 2 ;
F_22 ( V_4 , V_130 << V_153 ,
V_24 , V_154 ) ;
F_17 ( V_4 , V_24 , V_42 ,
V_53 | V_43 ) ;
F_33 ( V_2 , F_43 ( V_2 ) ) ;
F_22 ( V_4 , V_155 |
V_156 ,
V_24 , V_157 ) ;
F_17 ( V_4 , V_24 , V_158 ,
V_156 |
V_155 ) ;
}
static void F_48 ( struct V_1 * V_2 , T_2 V_159 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_22 ( V_4 , V_159 , V_24 , V_160 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = F_24 ( & V_2 -> V_37 . V_38 ) ;
struct V_161 * V_162 ;
V_162 = F_50 ( & V_2 -> V_138 , V_2 -> error ) ;
if ( V_162 != NULL )
F_48 ( V_2 , V_162 -> V_163 ) ;
V_36 -> V_164 |= V_165 ;
if ( V_2 -> V_164 == V_166 ) {
if ( F_51 ( V_36 ) )
F_52 ( V_36 ,
V_166 ) ;
}
V_2 -> error = 0 ;
}
int F_53 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_103 = 0 ;
static const T_2 V_167 =
V_89 |
V_90 |
V_91 |
V_92 |
V_93 |
V_94 ;
T_2 V_168 , V_169 ;
V_168 = F_18 ( V_4 , V_24 ,
V_95 ) ;
F_22 ( V_4 , V_168 , V_24 ,
V_95 ) ;
V_169 = F_18 ( V_4 , V_24 ,
V_157 ) ;
F_22 ( V_4 , V_169 , V_24 ,
V_157 ) ;
if ( V_168 & V_167 ) {
V_2 -> error = 1 ;
F_3 ( V_4 -> V_5 , L_6 , V_168 ) ;
return - V_62 ;
}
if ( V_169 & V_155 ) {
V_2 -> error = 1 ;
F_3 ( V_4 -> V_5 , L_7 , V_169 ) ;
V_103 = - V_62 ;
}
if ( F_54 ( & V_2 -> V_170 , & V_2 -> V_171 ) )
return 0 ;
if ( V_168 & V_47 ) {
struct V_35 * V_36 =
F_24 ( & V_2 -> V_37 . V_38 ) ;
if ( V_36 -> V_45 )
F_55 ( & V_36 -> V_172 ) ;
}
if ( V_169 & V_156 )
F_49 ( V_2 ) ;
return V_103 ;
}
static struct V_97 *
F_56 ( struct V_1 * V_2 , struct V_173 * V_174 ,
unsigned int V_99 , enum V_175 V_176 )
{
if ( V_176 == V_177 )
return F_57 ( V_174 , V_99 ) ;
else
return & V_2 -> V_109 [ V_99 ] ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_173 * V_174 , unsigned int V_99 ,
struct V_97 * V_178 ,
enum V_175 V_176 )
{
struct V_97 * V_72 ;
switch ( V_99 ) {
case V_105 :
if ( V_178 -> V_111 != V_73 )
V_178 -> V_111 = V_75 ;
if ( V_2 -> V_179 == V_180 ) {
V_178 -> V_123 = F_34 ( T_2 , V_178 -> V_123 ,
V_181 ,
V_182 ) ;
V_178 -> V_112 = F_34 ( T_2 , V_178 -> V_112 ,
V_183 ,
V_184 ) ;
} else if ( V_2 -> V_179 == V_185 ) {
V_178 -> V_123 = F_34 ( T_2 , V_178 -> V_123 ,
V_186 ,
V_187 ) ;
V_178 -> V_112 = F_34 ( T_2 , V_178 -> V_112 ,
V_188 ,
V_189 ) ;
}
break;
case V_114 :
V_72 = F_56 ( V_2 , V_174 , V_105 , V_176 ) ;
memcpy ( V_178 , V_72 , sizeof( * V_178 ) ) ;
V_178 -> V_111 = V_75 ;
break;
}
V_178 -> V_190 = V_191 ;
V_178 -> V_192 = V_193 ;
}
static int F_59 ( struct V_100 * V_194 ,
struct V_173 * V_174 ,
struct V_195 * V_111 )
{
struct V_1 * V_2 = F_60 ( V_194 ) ;
struct V_97 * V_72 ;
if ( V_111 -> V_99 == V_105 ) {
if ( V_111 -> V_196 >= F_61 ( V_197 ) )
return - V_198 ;
V_111 -> V_111 = V_197 [ V_111 -> V_196 ] ;
} else {
if ( V_111 -> V_196 != 0 )
return - V_198 ;
V_72 = F_56 ( V_2 , V_174 , V_105 ,
V_177 ) ;
V_111 -> V_111 = V_72 -> V_111 ;
}
return 0 ;
}
static int F_62 ( struct V_100 * V_194 ,
struct V_173 * V_174 ,
struct V_199 * V_200 )
{
struct V_1 * V_2 = F_60 ( V_194 ) ;
struct V_97 V_72 ;
if ( V_200 -> V_196 != 0 )
return - V_198 ;
V_72 . V_111 = V_200 -> V_111 ;
V_72 . V_123 = 1 ;
V_72 . V_112 = 1 ;
F_58 ( V_2 , V_174 , V_200 -> V_99 , & V_72 , V_177 ) ;
V_200 -> V_201 = V_72 . V_123 ;
V_200 -> V_202 = V_72 . V_112 ;
if ( V_72 . V_111 != V_200 -> V_111 )
return - V_198 ;
V_72 . V_111 = V_200 -> V_111 ;
V_72 . V_123 = - 1 ;
V_72 . V_112 = - 1 ;
F_58 ( V_2 , V_174 , V_200 -> V_99 , & V_72 , V_177 ) ;
V_200 -> V_203 = V_72 . V_123 ;
V_200 -> V_204 = V_72 . V_112 ;
return 0 ;
}
static int F_63 ( struct V_100 * V_194 , struct V_173 * V_174 ,
struct V_205 * V_178 )
{
struct V_1 * V_2 = F_60 ( V_194 ) ;
struct V_97 * V_72 ;
V_72 = F_56 ( V_2 , V_174 , V_178 -> V_99 , V_178 -> V_176 ) ;
if ( V_72 == NULL )
return - V_198 ;
V_178 -> V_72 = * V_72 ;
return 0 ;
}
static int F_64 ( struct V_100 * V_194 , struct V_173 * V_174 ,
struct V_205 * V_178 )
{
struct V_1 * V_2 = F_60 ( V_194 ) ;
struct V_97 * V_72 ;
V_72 = F_56 ( V_2 , V_174 , V_178 -> V_99 , V_178 -> V_176 ) ;
if ( V_72 == NULL )
return - V_198 ;
F_58 ( V_2 , V_174 , V_178 -> V_99 , & V_178 -> V_72 , V_178 -> V_176 ) ;
* V_72 = V_178 -> V_72 ;
if ( V_178 -> V_99 == V_105 ) {
V_72 = F_56 ( V_2 , V_174 , V_114 ,
V_178 -> V_176 ) ;
* V_72 = V_178 -> V_72 ;
F_58 ( V_2 , V_174 , V_114 , V_72 , V_178 -> V_176 ) ;
}
return 0 ;
}
static int F_65 ( struct V_100 * V_194 , struct V_173 * V_174 )
{
struct V_205 V_72 ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . V_99 = V_105 ;
V_72 . V_176 = V_174 ? V_177 : V_206 ;
V_72 . V_72 . V_111 = V_75 ;
V_72 . V_72 . V_123 = 4096 ;
V_72 . V_72 . V_112 = 4096 ;
F_64 ( V_194 , V_174 , & V_72 ) ;
return 0 ;
}
static int F_66 ( struct V_100 * V_194 , int V_34 )
{
struct V_1 * V_2 = F_60 ( V_194 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_207 * V_5 = F_67 ( V_2 ) ;
int V_103 ;
if ( V_2 -> V_164 == V_208 ) {
if ( V_34 == V_208 )
return 0 ;
F_68 ( & V_2 -> V_171 , 0 ) ;
V_2 -> error = 0 ;
}
switch ( V_34 ) {
case V_209 :
if ( V_2 -> V_210 ) {
V_103 = F_69 ( V_2 -> V_210 ) ;
if ( V_103 < 0 )
return V_103 ;
}
F_39 ( V_2 ) ;
F_1 ( V_2 ) ;
F_23 ( V_2 , 1 ) ;
break;
case V_166 :
if ( V_2 -> V_164 != V_166 ) {
struct V_97 * V_72 ;
V_72 = & V_2 -> V_109 [ V_105 ] ;
V_2 -> V_211 . V_132 = V_72 -> V_123 ;
V_2 -> V_211 . V_135 = V_72 -> V_112 ;
V_2 -> V_211 . V_140 = 0 ;
F_47 ( V_2 , & V_2 -> V_211 ) ;
F_70 ( V_4 , V_212 ) ;
F_1 ( V_2 ) ;
}
F_30 ( V_2 , 1 ) ;
break;
case V_208 :
if ( F_71 ( & V_194 -> V_38 , & V_2 -> V_170 ,
& V_2 -> V_171 ) )
F_3 ( V_5 , L_8 , V_194 -> V_213 ) ;
if ( V_2 -> V_179 == V_185 ) {
F_30 ( V_2 , 0 ) ;
F_72 ( V_4 , V_212 ) ;
} else if ( V_2 -> V_179 == V_180 ) {
F_23 ( V_2 , 0 ) ;
if ( V_2 -> V_210 )
F_73 ( V_2 -> V_210 ) ;
}
break;
}
V_2 -> V_164 = V_34 ;
return 0 ;
}
static int F_74 ( struct V_214 * V_215 , struct V_161 * V_162 )
{
struct V_1 * V_2 = & V_215 -> V_4 -> V_216 ;
F_48 ( V_2 , V_162 -> V_163 ) ;
return 0 ;
}
static int F_75 ( struct V_217 * V_38 ,
const struct V_98 * V_218 ,
const struct V_98 * V_219 , T_2 V_220 )
{
struct V_100 * V_194 = F_41 ( V_38 ) ;
struct V_1 * V_2 = F_60 ( V_194 ) ;
switch ( V_218 -> V_196 | F_76 ( V_219 -> V_38 ) ) {
case V_105 | V_221 :
if ( V_220 & V_222 ) {
if ( V_2 -> V_179 == V_180 )
return - V_223 ;
V_2 -> V_179 = V_185 ;
} else {
if ( V_2 -> V_179 == V_185 )
V_2 -> V_179 = V_224 ;
}
break;
case V_105 | V_225 :
if ( V_220 & V_222 ) {
if ( V_2 -> V_179 == V_185 )
return - V_223 ;
V_2 -> V_179 = V_180 ;
} else {
if ( V_2 -> V_179 == V_180 )
V_2 -> V_179 = V_224 ;
} break;
case V_114 | V_225 :
if ( V_220 & V_222 )
V_2 -> V_226 = V_227 ;
else
V_2 -> V_226 = V_228 ;
break;
default:
return - V_198 ;
}
return 0 ;
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_100 * V_194 = & V_2 -> V_37 ;
struct V_98 * V_104 = V_2 -> V_104 ;
struct V_217 * V_229 = & V_194 -> V_38 ;
int V_103 ;
V_2 -> V_179 = V_224 ;
V_2 -> V_226 = V_228 ;
F_78 ( V_194 , & V_230 ) ;
V_194 -> V_231 = & V_232 ;
F_79 ( V_194 -> V_213 , L_9 , sizeof( V_194 -> V_213 ) ) ;
V_194 -> V_233 = 1 << 16 ;
F_80 ( V_194 , V_2 ) ;
V_194 -> V_220 |= V_234 ;
V_104 [ V_105 ] . V_220 = V_235 ;
V_104 [ V_114 ] . V_220 = V_236 ;
V_229 -> V_237 = & V_238 ;
V_103 = F_81 ( V_229 , V_239 , V_104 , 0 ) ;
if ( V_103 < 0 )
return V_103 ;
F_65 ( V_194 , NULL ) ;
V_2 -> V_138 . type = V_240 ;
V_2 -> V_138 . V_241 = 32 ;
V_2 -> V_138 . V_242 = 0xffffffe0 ;
V_2 -> V_138 . V_4 = F_2 ( V_2 ) ;
V_2 -> V_138 . V_237 = & V_243 ;
V_2 -> V_138 . V_244 = F_82 ( 4096 * 4096 ) * 3 ;
V_103 = F_83 ( & V_2 -> V_138 , L_10 ) ;
if ( V_103 < 0 )
return V_103 ;
V_103 = F_84 ( & V_2 -> V_138 . V_215 . V_38 , 0 ,
& V_2 -> V_37 . V_38 , V_105 , 0 ) ;
if ( V_103 < 0 )
return V_103 ;
return 0 ;
}
void F_85 ( struct V_1 * V_2 )
{
F_86 ( & V_2 -> V_37 . V_38 ) ;
F_87 ( & V_2 -> V_37 ) ;
F_88 ( & V_2 -> V_138 ) ;
}
int F_89 ( struct V_1 * V_2 ,
struct V_245 * V_246 )
{
int V_103 ;
V_103 = F_90 ( V_246 , & V_2 -> V_37 ) ;
if ( V_103 < 0 )
goto error;
V_103 = F_91 ( & V_2 -> V_138 , V_246 ) ;
if ( V_103 < 0 )
goto error;
return 0 ;
error:
F_85 ( V_2 ) ;
return V_103 ;
}
void F_92 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_216 ;
F_93 ( V_2 -> V_39 ) ;
}
int F_94 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_216 ;
int V_103 ;
F_95 ( & V_2 -> V_170 ) ;
if ( V_4 -> V_30 == V_247 ) {
V_2 -> V_39 = F_96 ( V_4 -> V_5 , L_11 ) ;
if ( F_97 ( V_2 -> V_39 ) ) {
F_3 ( V_4 -> V_5 ,
L_12 ) ;
V_2 -> V_39 = NULL ;
}
} else if ( V_4 -> V_30 == V_31 ) {
V_2 -> V_210 = & V_4 -> V_248 ;
}
V_103 = F_77 ( V_2 ) ;
if ( V_103 < 0 )
goto V_249;
F_16 ( V_2 ) ;
V_249:
if ( V_103 )
F_92 ( V_4 ) ;
return V_103 ;
}
