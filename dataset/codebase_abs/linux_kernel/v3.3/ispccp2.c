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
if ( V_51 -> V_60 == V_61 )
F_20 ( V_4 -> V_5 , L_4 ) ;
if ( V_51 -> V_56 == V_62 )
return - V_63 ;
}
return 0 ;
}
static void F_33 ( struct V_1 * V_2 ,
unsigned int V_64 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_52 ;
V_52 = F_18 ( V_4 , V_24 , V_42 ) ;
V_52 |= V_65 ;
if ( V_4 -> V_30 == V_31 ) {
V_64 = F_34 (unsigned int, vpclk_div, 1 , 65536 ) ;
V_64 = F_35 ( V_66 / V_64 , 65535U ) ;
F_32 ( V_52 , V_67 ,
V_68 , V_64 ) ;
} else {
V_64 = F_34 (unsigned int, vpclk_div, 1 , 4 ) ;
F_32 ( V_52 , V_69 ,
V_70 , V_64 - 1 ) ;
}
F_22 ( V_4 , V_52 , V_24 , V_42 ) ;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_71 * V_72 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_52 , V_73 ;
switch ( V_72 -> V_73 ) {
case V_74 :
V_73 = V_75 ;
break;
case V_76 :
default:
V_73 = V_77 ;
break;
}
V_52 = F_18 ( V_4 , V_24 , F_27 ( 0 ) )
| ( V_78 ) ;
if ( V_4 -> V_30 == V_31 ) {
F_32 ( V_52 , V_79 ,
V_80 ,
V_72 -> V_81 ) ;
F_32 ( V_52 , V_82 ,
V_83 , V_73 ) ;
} else {
F_32 ( V_52 , V_84 ,
V_80 ,
V_72 -> V_81 ) ;
F_32 ( V_52 , V_85 ,
V_86 , V_73 ) ;
}
F_22 ( V_4 , V_52 , V_24 , F_27 ( 0 ) ) ;
F_22 ( V_4 , V_72 -> V_87 << V_88 ,
V_24 , F_37 ( 0 ) ) ;
F_22 ( V_4 , V_72 -> V_89 << V_88 ,
V_24 , F_38 ( 0 ) ) ;
V_52 = V_90 |
V_91 |
V_92 |
V_93 |
V_47 |
V_94 |
V_95 ;
F_22 ( V_4 , V_52 , V_24 , V_96 ) ;
F_17 ( V_4 , V_24 , V_46 , V_52 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
const struct V_97 * V_51 ;
struct V_98 * V_73 ;
struct V_99 * V_100 ;
struct V_101 * V_102 ;
T_2 V_103 = 0 ;
int V_104 ;
F_21 ( V_2 ) ;
V_100 = F_40 ( & V_2 -> V_105 [ V_106 ] ) ;
V_102 = F_41 ( V_100 -> V_38 ) ;
V_51 = V_102 -> V_107 ;
V_104 = F_31 ( V_2 , & V_51 -> V_108 . V_2 ) ;
if ( V_104 < 0 )
return V_104 ;
F_33 ( V_2 , V_51 -> V_108 . V_2 . V_64 + 1 ) ;
F_42 ( V_102 , V_102 , V_109 , & V_103 ) ;
V_73 = & V_2 -> V_110 [ V_106 ] ;
V_2 -> V_111 . V_87 = V_103 ;
V_2 -> V_111 . V_81 = V_51 -> V_108 . V_2 . V_81 ;
V_2 -> V_111 . V_73 = V_73 -> V_112 ;
V_2 -> V_111 . V_89 = V_73 -> V_113 ;
F_36 ( V_2 , & V_2 -> V_111 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = F_24 ( & V_2 -> V_37 . V_38 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_98 * V_114 = & V_2 -> V_110 [ V_115 ] ;
unsigned long V_116 = V_36 -> V_116 ;
struct V_117 * V_118 ;
unsigned int V_64 = 2 ;
unsigned int V_119 ;
T_3 V_120 ;
T_3 V_121 ;
V_64 = F_44 (unsigned int, DIV_ROUND_UP(l3_ick, pipe->max_rate),
vpclk_div) ;
V_118 = & V_36 -> V_122 ;
if ( V_118 -> V_123 ) {
V_121 = V_114 -> V_124 * V_114 -> V_113 ;
V_120 = F_45 ( V_121 * V_118 -> V_125 ,
V_118 -> V_123 ) ;
V_119 = F_46 ( T_3 , V_120 , V_116 ) ;
V_64 = F_44 (unsigned int, l3_ick / value, vpclk_div) ;
}
F_3 ( V_4 -> V_5 , L_5 , V_126 ,
V_64 ) ;
return V_64 ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_127 * V_72 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_128 = V_2 -> V_110 [ V_106 ] . V_112 ;
T_2 V_129 = V_2 -> V_110 [ V_115 ] . V_112 ;
unsigned int V_130 = 0 ;
T_2 V_52 , V_131 ;
if ( V_128 != V_129 &&
V_128 == V_74 )
V_130 = 1 ;
F_21 ( V_2 ) ;
F_22 ( V_4 , V_132 |
( V_72 -> V_133 << V_134 ) ,
V_24 , V_135 ) ;
F_22 ( V_4 , V_72 -> V_136 << V_137 ,
V_24 , V_138 ) ;
if ( V_2 -> V_139 . V_140 == 0 )
V_72 -> V_141 = 0 ;
else
V_72 -> V_141 = V_2 -> V_139 . V_142 ;
F_22 ( V_4 , V_72 -> V_141 , V_24 ,
V_143 ) ;
V_52 = V_144 <<
V_145 ;
if ( V_130 ) {
V_52 |= V_146 <<
V_147 ;
V_52 |= V_148 ;
V_52 |= V_149 <<
V_150 ;
} else {
V_52 |= V_151 <<
V_147 ;
}
V_52 |= V_152 <<
V_153 ;
F_22 ( V_4 , V_52 , V_24 , V_48 ) ;
if ( V_130 )
V_131 = ( V_132 +
V_72 -> V_133 ) >> 3 ;
else
V_131 = ( V_132 +
V_72 -> V_133 ) >> 2 ;
F_22 ( V_4 , V_131 << V_154 ,
V_24 , V_155 ) ;
F_17 ( V_4 , V_24 , V_42 ,
V_53 | V_43 ) ;
F_33 ( V_2 , F_43 ( V_2 ) ) ;
F_22 ( V_4 , V_156 |
V_157 ,
V_24 , V_158 ) ;
F_17 ( V_4 , V_24 , V_159 ,
V_157 |
V_156 ) ;
}
static void F_48 ( struct V_1 * V_2 , T_2 V_160 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_22 ( V_4 , V_160 , V_24 , V_161 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = F_24 ( & V_2 -> V_37 . V_38 ) ;
struct V_162 * V_163 ;
V_163 = F_50 ( & V_2 -> V_139 ) ;
if ( V_163 != NULL )
F_48 ( V_2 , V_163 -> V_164 ) ;
V_36 -> V_165 |= V_166 ;
if ( V_2 -> V_165 == V_167 ) {
if ( F_51 ( V_36 ) )
F_52 ( V_36 ,
V_167 ) ;
}
}
void F_53 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = F_24 ( & V_2 -> V_37 . V_38 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
static const T_2 V_168 =
V_90 |
V_91 |
V_92 |
V_93 |
V_94 |
V_95 ;
T_2 V_169 , V_170 ;
V_169 = F_18 ( V_4 , V_24 ,
V_96 ) ;
F_22 ( V_4 , V_169 , V_24 ,
V_96 ) ;
V_170 = F_18 ( V_4 , V_24 ,
V_158 ) ;
F_22 ( V_4 , V_170 , V_24 ,
V_158 ) ;
if ( V_169 & V_168 ) {
V_36 -> error = true ;
F_3 ( V_4 -> V_5 , L_6 , V_169 ) ;
return;
}
if ( V_170 & V_156 ) {
V_36 -> error = true ;
F_3 ( V_4 -> V_5 , L_7 , V_170 ) ;
}
if ( F_54 ( & V_2 -> V_171 , & V_2 -> V_172 ) )
return;
if ( V_169 & V_47 ) {
struct V_35 * V_36 =
F_24 ( & V_2 -> V_37 . V_38 ) ;
if ( V_36 -> V_45 )
F_55 ( & V_36 -> V_173 ) ;
}
if ( V_170 & V_157 )
F_49 ( V_2 ) ;
}
static struct V_98 *
F_56 ( struct V_1 * V_2 , struct V_174 * V_175 ,
unsigned int V_100 , enum V_176 V_177 )
{
if ( V_177 == V_178 )
return F_57 ( V_175 , V_100 ) ;
else
return & V_2 -> V_110 [ V_100 ] ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_174 * V_175 , unsigned int V_100 ,
struct V_98 * V_179 ,
enum V_176 V_177 )
{
struct V_98 * V_73 ;
switch ( V_100 ) {
case V_106 :
if ( V_179 -> V_112 != V_74 )
V_179 -> V_112 = V_76 ;
if ( V_2 -> V_180 == V_181 ) {
V_179 -> V_124 = F_34 ( T_2 , V_179 -> V_124 ,
V_182 ,
V_183 ) ;
V_179 -> V_113 = F_34 ( T_2 , V_179 -> V_113 ,
V_184 ,
V_185 ) ;
} else if ( V_2 -> V_180 == V_186 ) {
V_179 -> V_124 = F_34 ( T_2 , V_179 -> V_124 ,
V_187 ,
V_188 ) ;
V_179 -> V_113 = F_34 ( T_2 , V_179 -> V_113 ,
V_189 ,
V_190 ) ;
}
break;
case V_115 :
V_73 = F_56 ( V_2 , V_175 , V_106 , V_177 ) ;
memcpy ( V_179 , V_73 , sizeof( * V_179 ) ) ;
V_179 -> V_112 = V_76 ;
break;
}
V_179 -> V_191 = V_192 ;
V_179 -> V_193 = V_194 ;
}
static int F_59 ( struct V_101 * V_195 ,
struct V_174 * V_175 ,
struct V_196 * V_112 )
{
struct V_1 * V_2 = F_60 ( V_195 ) ;
struct V_98 * V_73 ;
if ( V_112 -> V_100 == V_106 ) {
if ( V_112 -> V_197 >= F_61 ( V_198 ) )
return - V_199 ;
V_112 -> V_112 = V_198 [ V_112 -> V_197 ] ;
} else {
if ( V_112 -> V_197 != 0 )
return - V_199 ;
V_73 = F_56 ( V_2 , V_175 , V_106 ,
V_178 ) ;
V_112 -> V_112 = V_73 -> V_112 ;
}
return 0 ;
}
static int F_62 ( struct V_101 * V_195 ,
struct V_174 * V_175 ,
struct V_200 * V_201 )
{
struct V_1 * V_2 = F_60 ( V_195 ) ;
struct V_98 V_73 ;
if ( V_201 -> V_197 != 0 )
return - V_199 ;
V_73 . V_112 = V_201 -> V_112 ;
V_73 . V_124 = 1 ;
V_73 . V_113 = 1 ;
F_58 ( V_2 , V_175 , V_201 -> V_100 , & V_73 , V_178 ) ;
V_201 -> V_202 = V_73 . V_124 ;
V_201 -> V_203 = V_73 . V_113 ;
if ( V_73 . V_112 != V_201 -> V_112 )
return - V_199 ;
V_73 . V_112 = V_201 -> V_112 ;
V_73 . V_124 = - 1 ;
V_73 . V_113 = - 1 ;
F_58 ( V_2 , V_175 , V_201 -> V_100 , & V_73 , V_178 ) ;
V_201 -> V_204 = V_73 . V_124 ;
V_201 -> V_205 = V_73 . V_113 ;
return 0 ;
}
static int F_63 ( struct V_101 * V_195 , struct V_174 * V_175 ,
struct V_206 * V_179 )
{
struct V_1 * V_2 = F_60 ( V_195 ) ;
struct V_98 * V_73 ;
V_73 = F_56 ( V_2 , V_175 , V_179 -> V_100 , V_179 -> V_177 ) ;
if ( V_73 == NULL )
return - V_199 ;
V_179 -> V_73 = * V_73 ;
return 0 ;
}
static int F_64 ( struct V_101 * V_195 , struct V_174 * V_175 ,
struct V_206 * V_179 )
{
struct V_1 * V_2 = F_60 ( V_195 ) ;
struct V_98 * V_73 ;
V_73 = F_56 ( V_2 , V_175 , V_179 -> V_100 , V_179 -> V_177 ) ;
if ( V_73 == NULL )
return - V_199 ;
F_58 ( V_2 , V_175 , V_179 -> V_100 , & V_179 -> V_73 , V_179 -> V_177 ) ;
* V_73 = V_179 -> V_73 ;
if ( V_179 -> V_100 == V_106 ) {
V_73 = F_56 ( V_2 , V_175 , V_115 ,
V_179 -> V_177 ) ;
* V_73 = V_179 -> V_73 ;
F_58 ( V_2 , V_175 , V_115 , V_73 , V_179 -> V_177 ) ;
}
return 0 ;
}
static int F_65 ( struct V_101 * V_195 , struct V_174 * V_175 )
{
struct V_206 V_73 ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
V_73 . V_100 = V_106 ;
V_73 . V_177 = V_175 ? V_178 : V_207 ;
V_73 . V_73 . V_112 = V_76 ;
V_73 . V_73 . V_124 = 4096 ;
V_73 . V_73 . V_113 = 4096 ;
F_64 ( V_195 , V_175 , & V_73 ) ;
return 0 ;
}
static int F_66 ( struct V_101 * V_195 , int V_34 )
{
struct V_1 * V_2 = F_60 ( V_195 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_208 * V_5 = F_67 ( V_2 ) ;
int V_104 ;
if ( V_2 -> V_165 == V_209 ) {
if ( V_34 == V_209 )
return 0 ;
F_68 ( & V_2 -> V_172 , 0 ) ;
}
switch ( V_34 ) {
case V_210 :
if ( V_2 -> V_211 ) {
V_104 = F_69 ( V_2 -> V_211 ) ;
if ( V_104 < 0 )
return V_104 ;
}
F_39 ( V_2 ) ;
F_1 ( V_2 ) ;
F_23 ( V_2 , 1 ) ;
break;
case V_167 :
if ( V_2 -> V_165 != V_167 ) {
struct V_98 * V_73 ;
V_73 = & V_2 -> V_110 [ V_106 ] ;
V_2 -> V_212 . V_133 = V_73 -> V_124 ;
V_2 -> V_212 . V_136 = V_73 -> V_113 ;
V_2 -> V_212 . V_141 = 0 ;
F_47 ( V_2 , & V_2 -> V_212 ) ;
F_70 ( V_4 , V_213 ) ;
F_1 ( V_2 ) ;
}
F_30 ( V_2 , 1 ) ;
break;
case V_209 :
if ( F_71 ( & V_195 -> V_38 , & V_2 -> V_171 ,
& V_2 -> V_172 ) )
F_3 ( V_5 , L_8 , V_195 -> V_214 ) ;
if ( V_2 -> V_180 == V_186 ) {
F_30 ( V_2 , 0 ) ;
F_72 ( V_4 , V_213 ) ;
} else if ( V_2 -> V_180 == V_181 ) {
F_23 ( V_2 , 0 ) ;
if ( V_2 -> V_211 )
F_73 ( V_2 -> V_211 ) ;
}
break;
}
V_2 -> V_165 = V_34 ;
return 0 ;
}
static int F_74 ( struct V_215 * V_216 , struct V_162 * V_163 )
{
struct V_1 * V_2 = & V_216 -> V_4 -> V_217 ;
F_48 ( V_2 , V_163 -> V_164 ) ;
return 0 ;
}
static int F_75 ( struct V_218 * V_38 ,
const struct V_99 * V_219 ,
const struct V_99 * V_220 , T_2 V_221 )
{
struct V_101 * V_195 = F_41 ( V_38 ) ;
struct V_1 * V_2 = F_60 ( V_195 ) ;
switch ( V_219 -> V_197 | F_76 ( V_220 -> V_38 ) ) {
case V_106 | V_222 :
if ( V_221 & V_223 ) {
if ( V_2 -> V_180 == V_181 )
return - V_224 ;
V_2 -> V_180 = V_186 ;
} else {
if ( V_2 -> V_180 == V_186 )
V_2 -> V_180 = V_225 ;
}
break;
case V_106 | V_226 :
if ( V_221 & V_223 ) {
if ( V_2 -> V_180 == V_186 )
return - V_224 ;
V_2 -> V_180 = V_181 ;
} else {
if ( V_2 -> V_180 == V_181 )
V_2 -> V_180 = V_225 ;
} break;
case V_115 | V_226 :
if ( V_221 & V_223 )
V_2 -> V_227 = V_228 ;
else
V_2 -> V_227 = V_229 ;
break;
default:
return - V_199 ;
}
return 0 ;
}
void F_77 ( struct V_1 * V_2 )
{
F_78 ( & V_2 -> V_37 ) ;
F_79 ( & V_2 -> V_139 ) ;
}
int F_80 ( struct V_1 * V_2 ,
struct V_230 * V_231 )
{
int V_104 ;
V_104 = F_81 ( V_231 , & V_2 -> V_37 ) ;
if ( V_104 < 0 )
goto error;
V_104 = F_82 ( & V_2 -> V_139 , V_231 ) ;
if ( V_104 < 0 )
goto error;
return 0 ;
error:
F_77 ( V_2 ) ;
return V_104 ;
}
static int F_83 ( struct V_1 * V_2 )
{
struct V_101 * V_195 = & V_2 -> V_37 ;
struct V_99 * V_105 = V_2 -> V_105 ;
struct V_218 * V_232 = & V_195 -> V_38 ;
int V_104 ;
V_2 -> V_180 = V_225 ;
V_2 -> V_227 = V_229 ;
F_84 ( V_195 , & V_233 ) ;
V_195 -> V_234 = & V_235 ;
F_85 ( V_195 -> V_214 , L_9 , sizeof( V_195 -> V_214 ) ) ;
V_195 -> V_236 = 1 << 16 ;
F_86 ( V_195 , V_2 ) ;
V_195 -> V_221 |= V_237 ;
V_105 [ V_106 ] . V_221 = V_238 ;
V_105 [ V_115 ] . V_221 = V_239 ;
V_232 -> V_240 = & V_241 ;
V_104 = F_87 ( V_232 , V_242 , V_105 , 0 ) ;
if ( V_104 < 0 )
return V_104 ;
F_65 ( V_195 , NULL ) ;
V_2 -> V_139 . type = V_243 ;
V_2 -> V_139 . V_244 = 32 ;
V_2 -> V_139 . V_245 = 0xffffffe0 ;
V_2 -> V_139 . V_4 = F_2 ( V_2 ) ;
V_2 -> V_139 . V_240 = & V_246 ;
V_2 -> V_139 . V_247 = F_88 ( 4096 * 4096 ) * 3 ;
V_104 = F_89 ( & V_2 -> V_139 , L_10 ) ;
if ( V_104 < 0 )
goto V_248;
V_104 = F_90 ( & V_2 -> V_139 . V_216 . V_38 , 0 ,
& V_2 -> V_37 . V_38 , V_106 , 0 ) ;
if ( V_104 < 0 )
goto V_249;
return 0 ;
V_249:
F_91 ( & V_2 -> V_139 ) ;
V_248:
F_92 ( & V_2 -> V_37 . V_38 ) ;
return V_104 ;
}
int F_93 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_217 ;
int V_104 ;
F_94 ( & V_2 -> V_171 ) ;
if ( V_4 -> V_30 == V_250 ) {
V_2 -> V_39 = F_95 ( V_4 -> V_5 , L_11 ) ;
if ( F_96 ( V_2 -> V_39 ) ) {
F_3 ( V_4 -> V_5 ,
L_12 ) ;
V_2 -> V_39 = NULL ;
}
} else if ( V_4 -> V_30 == V_31 ) {
V_2 -> V_211 = & V_4 -> V_251 ;
}
V_104 = F_83 ( V_2 ) ;
if ( V_104 < 0 ) {
F_97 ( V_2 -> V_39 ) ;
return V_104 ;
}
F_16 ( V_2 ) ;
return 0 ;
}
void F_98 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_217 ;
F_91 ( & V_2 -> V_139 ) ;
F_92 ( & V_2 -> V_37 . V_38 ) ;
F_97 ( V_2 -> V_39 ) ;
}
