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
V_47 | V_40 ;
F_30 ( V_46 , V_48 , V_49 ,
V_45 -> V_50 ) ;
F_30 ( V_46 , V_51 , V_52 ,
V_45 -> V_53 ) ;
F_22 ( V_4 , V_46 , V_24 , V_39 ) ;
V_46 = F_18 ( V_4 , V_24 , V_39 ) ;
if ( ! ( V_46 & V_40 ) ) {
if ( V_45 -> V_54 == V_55 )
F_20 ( V_4 -> V_5 , L_4 ) ;
if ( V_45 -> V_50 == V_56 )
return - V_57 ;
}
return 0 ;
}
static void F_31 ( struct V_1 * V_2 ,
unsigned int V_58 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_46 ;
V_46 = F_18 ( V_4 , V_24 , V_39 ) ;
V_46 |= V_59 ;
if ( V_4 -> V_30 == V_31 ) {
V_58 = F_32 (unsigned int, vpclk_div, 1 , 65536 ) ;
V_58 = F_33 ( V_60 / V_58 , 65535U ) ;
F_30 ( V_46 , V_61 ,
V_62 , V_58 ) ;
} else {
V_58 = F_32 (unsigned int, vpclk_div, 1 , 4 ) ;
F_30 ( V_46 , V_63 ,
V_64 , V_58 - 1 ) ;
}
F_22 ( V_4 , V_46 , V_24 , V_39 ) ;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_65 * V_66 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_46 , V_67 ;
switch ( V_66 -> V_67 ) {
case V_68 :
V_67 = V_69 ;
break;
case V_70 :
default:
V_67 = V_71 ;
break;
}
V_46 = F_18 ( V_4 , V_24 , F_26 ( 0 ) )
| ( V_72 ) ;
if ( V_4 -> V_30 == V_31 ) {
F_30 ( V_46 , V_73 ,
V_74 ,
V_66 -> V_75 ) ;
F_30 ( V_46 , V_76 ,
V_77 , V_67 ) ;
} else {
F_30 ( V_46 , V_78 ,
V_74 ,
V_66 -> V_75 ) ;
F_30 ( V_46 , V_79 ,
V_80 , V_67 ) ;
}
F_22 ( V_4 , V_46 , V_24 , F_26 ( 0 ) ) ;
F_22 ( V_4 , V_66 -> V_81 << V_82 ,
V_24 , F_35 ( 0 ) ) ;
F_22 ( V_4 , V_66 -> V_83 << V_82 ,
V_24 , F_36 ( 0 ) ) ;
V_46 = V_84 |
V_85 |
V_86 |
V_87 |
V_88 |
V_89 ;
F_22 ( V_4 , V_46 , V_24 , V_90 ) ;
F_17 ( V_4 , V_24 , V_91 , V_46 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
const struct V_92 * V_45 ;
struct V_93 * V_67 ;
struct V_94 * V_95 ;
struct V_96 * V_97 ;
T_2 V_98 = 0 ;
int V_35 ;
F_21 ( V_2 ) ;
V_95 = F_38 ( & V_2 -> V_99 [ V_100 ] ) ;
V_97 = F_39 ( V_95 -> V_101 ) ;
V_45 = V_97 -> V_102 ;
V_35 = F_29 ( V_2 , & V_45 -> V_103 . V_2 ) ;
if ( V_35 < 0 )
return V_35 ;
F_31 ( V_2 , V_45 -> V_103 . V_2 . V_58 + 1 ) ;
F_40 ( V_97 , V_97 , V_104 , & V_98 ) ;
V_67 = & V_2 -> V_105 [ V_100 ] ;
V_2 -> V_106 . V_81 = V_98 ;
V_2 -> V_106 . V_75 = V_45 -> V_103 . V_2 . V_75 ;
V_2 -> V_106 . V_67 = V_67 -> V_107 ;
V_2 -> V_106 . V_83 = V_67 -> V_108 ;
F_34 ( V_2 , & V_2 -> V_106 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_109 * V_110 = F_42 ( & V_2 -> V_111 . V_101 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_93 * V_112 = & V_2 -> V_105 [ V_113 ] ;
unsigned long V_114 = V_110 -> V_114 ;
struct V_115 * V_116 ;
unsigned int V_58 = 2 ;
unsigned int V_117 ;
T_3 V_118 ;
T_3 V_119 ;
V_58 = F_43 (unsigned int, DIV_ROUND_UP(l3_ick, pipe->max_rate),
vpclk_div) ;
V_116 = & V_110 -> V_120 ;
if ( V_116 -> V_121 ) {
V_119 = V_112 -> V_122 * V_112 -> V_108 ;
V_118 = F_44 ( V_119 * V_116 -> V_123 ,
V_116 -> V_121 ) ;
V_117 = F_45 ( T_3 , V_118 , V_114 ) ;
V_58 = F_43 (unsigned int, l3_ick / value, vpclk_div) ;
}
F_3 ( V_4 -> V_5 , L_5 , V_124 ,
V_58 ) ;
return V_58 ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_125 * V_66 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_126 = V_2 -> V_105 [ V_100 ] . V_107 ;
T_2 V_127 = V_2 -> V_105 [ V_113 ] . V_107 ;
unsigned int V_128 = 0 ;
T_2 V_46 , V_129 ;
if ( V_126 != V_127 &&
V_126 == V_68 )
V_128 = 1 ;
F_21 ( V_2 ) ;
F_22 ( V_4 , V_130 |
( V_66 -> V_131 << V_132 ) ,
V_24 , V_133 ) ;
F_22 ( V_4 , V_66 -> V_134 << V_135 ,
V_24 , V_136 ) ;
if ( V_2 -> V_137 . V_138 == 0 )
V_66 -> V_139 = 0 ;
else
V_66 -> V_139 = V_2 -> V_137 . V_140 ;
F_22 ( V_4 , V_66 -> V_139 , V_24 ,
V_141 ) ;
V_46 = V_142 <<
V_143 ;
if ( V_128 ) {
V_46 |= V_144 <<
V_145 ;
V_46 |= V_146 ;
V_46 |= V_147 <<
V_148 ;
} else {
V_46 |= V_149 <<
V_145 ;
}
V_46 |= V_150 <<
V_151 ;
F_22 ( V_4 , V_46 , V_24 , V_42 ) ;
if ( V_128 )
V_129 = ( V_130 +
V_66 -> V_131 ) >> 3 ;
else
V_129 = ( V_130 +
V_66 -> V_131 ) >> 2 ;
F_22 ( V_4 , V_129 << V_152 ,
V_24 , V_153 ) ;
F_17 ( V_4 , V_24 , V_39 ,
V_47 | V_40 ) ;
F_31 ( V_2 , F_41 ( V_2 ) ) ;
F_22 ( V_4 , V_154 |
V_155 ,
V_24 , V_156 ) ;
F_17 ( V_4 , V_24 , V_157 ,
V_155 |
V_154 ) ;
}
static void F_47 ( struct V_1 * V_2 , T_2 V_158 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_22 ( V_4 , V_158 , V_24 , V_159 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_109 * V_110 = F_42 ( & V_2 -> V_111 . V_101 ) ;
struct V_160 * V_161 ;
V_161 = F_49 ( & V_2 -> V_137 ) ;
if ( V_161 != NULL )
F_47 ( V_2 , V_161 -> V_162 ) ;
V_110 -> V_163 |= V_164 ;
if ( V_2 -> V_163 == V_165 ) {
if ( F_50 ( V_110 ) )
F_51 ( V_110 ,
V_165 ) ;
}
}
void F_52 ( struct V_1 * V_2 )
{
struct V_109 * V_110 = F_42 ( & V_2 -> V_111 . V_101 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
static const T_2 V_166 =
V_84 |
V_85 |
V_86 |
V_87 |
V_88 |
V_89 ;
T_2 V_167 , V_168 ;
V_167 = F_18 ( V_4 , V_24 ,
V_90 ) ;
F_22 ( V_4 , V_167 , V_24 ,
V_90 ) ;
V_168 = F_18 ( V_4 , V_24 ,
V_156 ) ;
F_22 ( V_4 , V_168 , V_24 ,
V_156 ) ;
if ( V_167 & V_166 ) {
V_110 -> error = true ;
F_3 ( V_4 -> V_5 , L_6 , V_167 ) ;
return;
}
if ( V_168 & V_154 ) {
V_110 -> error = true ;
F_3 ( V_4 -> V_5 , L_7 , V_168 ) ;
}
if ( F_53 ( & V_2 -> V_169 , & V_2 -> V_170 ) )
return;
if ( V_168 & V_155 )
F_48 ( V_2 ) ;
}
static struct V_93 *
F_54 ( struct V_1 * V_2 , struct V_171 * V_172 ,
unsigned int V_95 , enum V_173 V_174 )
{
if ( V_174 == V_175 )
return F_55 ( & V_2 -> V_111 , V_172 , V_95 ) ;
else
return & V_2 -> V_105 [ V_95 ] ;
}
static void F_56 ( struct V_1 * V_2 ,
struct V_171 * V_172 , unsigned int V_95 ,
struct V_93 * V_176 ,
enum V_173 V_174 )
{
struct V_93 * V_67 ;
switch ( V_95 ) {
case V_100 :
if ( V_176 -> V_107 != V_68 )
V_176 -> V_107 = V_70 ;
if ( V_2 -> V_177 == V_178 ) {
V_176 -> V_122 = F_32 ( T_2 , V_176 -> V_122 ,
V_179 ,
V_180 ) ;
V_176 -> V_108 = F_32 ( T_2 , V_176 -> V_108 ,
V_181 ,
V_182 ) ;
} else if ( V_2 -> V_177 == V_183 ) {
V_176 -> V_122 = F_32 ( T_2 , V_176 -> V_122 ,
V_184 ,
V_185 ) ;
V_176 -> V_108 = F_32 ( T_2 , V_176 -> V_108 ,
V_186 ,
V_187 ) ;
}
break;
case V_113 :
V_67 = F_54 ( V_2 , V_172 , V_100 , V_174 ) ;
memcpy ( V_176 , V_67 , sizeof( * V_176 ) ) ;
V_176 -> V_107 = V_70 ;
break;
}
V_176 -> V_188 = V_189 ;
V_176 -> V_190 = V_191 ;
}
static int F_57 ( struct V_96 * V_192 ,
struct V_171 * V_172 ,
struct V_193 * V_107 )
{
struct V_1 * V_2 = F_58 ( V_192 ) ;
struct V_93 * V_67 ;
if ( V_107 -> V_95 == V_100 ) {
if ( V_107 -> V_194 >= F_59 ( V_195 ) )
return - V_196 ;
V_107 -> V_107 = V_195 [ V_107 -> V_194 ] ;
} else {
if ( V_107 -> V_194 != 0 )
return - V_196 ;
V_67 = F_54 ( V_2 , V_172 , V_100 ,
V_107 -> V_174 ) ;
V_107 -> V_107 = V_67 -> V_107 ;
}
return 0 ;
}
static int F_60 ( struct V_96 * V_192 ,
struct V_171 * V_172 ,
struct V_197 * V_198 )
{
struct V_1 * V_2 = F_58 ( V_192 ) ;
struct V_93 V_67 ;
if ( V_198 -> V_194 != 0 )
return - V_196 ;
V_67 . V_107 = V_198 -> V_107 ;
V_67 . V_122 = 1 ;
V_67 . V_108 = 1 ;
F_56 ( V_2 , V_172 , V_198 -> V_95 , & V_67 , V_198 -> V_174 ) ;
V_198 -> V_199 = V_67 . V_122 ;
V_198 -> V_200 = V_67 . V_108 ;
if ( V_67 . V_107 != V_198 -> V_107 )
return - V_196 ;
V_67 . V_107 = V_198 -> V_107 ;
V_67 . V_122 = - 1 ;
V_67 . V_108 = - 1 ;
F_56 ( V_2 , V_172 , V_198 -> V_95 , & V_67 , V_198 -> V_174 ) ;
V_198 -> V_201 = V_67 . V_122 ;
V_198 -> V_202 = V_67 . V_108 ;
return 0 ;
}
static int F_61 ( struct V_96 * V_192 , struct V_171 * V_172 ,
struct V_203 * V_176 )
{
struct V_1 * V_2 = F_58 ( V_192 ) ;
struct V_93 * V_67 ;
V_67 = F_54 ( V_2 , V_172 , V_176 -> V_95 , V_176 -> V_174 ) ;
if ( V_67 == NULL )
return - V_196 ;
V_176 -> V_67 = * V_67 ;
return 0 ;
}
static int F_62 ( struct V_96 * V_192 , struct V_171 * V_172 ,
struct V_203 * V_176 )
{
struct V_1 * V_2 = F_58 ( V_192 ) ;
struct V_93 * V_67 ;
V_67 = F_54 ( V_2 , V_172 , V_176 -> V_95 , V_176 -> V_174 ) ;
if ( V_67 == NULL )
return - V_196 ;
F_56 ( V_2 , V_172 , V_176 -> V_95 , & V_176 -> V_67 , V_176 -> V_174 ) ;
* V_67 = V_176 -> V_67 ;
if ( V_176 -> V_95 == V_100 ) {
V_67 = F_54 ( V_2 , V_172 , V_113 ,
V_176 -> V_174 ) ;
* V_67 = V_176 -> V_67 ;
F_56 ( V_2 , V_172 , V_113 , V_67 , V_176 -> V_174 ) ;
}
return 0 ;
}
static int F_63 ( struct V_96 * V_192 , struct V_204 * V_205 )
{
struct V_203 V_67 ;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
V_67 . V_95 = V_100 ;
V_67 . V_174 = V_205 ? V_175 : V_206 ;
V_67 . V_67 . V_107 = V_70 ;
V_67 . V_67 . V_122 = 4096 ;
V_67 . V_67 . V_108 = 4096 ;
F_62 ( V_192 , V_205 ? V_205 -> V_95 : NULL , & V_67 ) ;
return 0 ;
}
static int F_64 ( struct V_96 * V_192 , int V_34 )
{
struct V_1 * V_2 = F_58 ( V_192 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_207 * V_5 = F_65 ( V_2 ) ;
int V_35 ;
if ( V_2 -> V_163 == V_208 ) {
if ( V_34 == V_208 )
return 0 ;
F_66 ( & V_2 -> V_170 , 0 ) ;
}
switch ( V_34 ) {
case V_209 :
if ( V_2 -> V_210 ) {
V_35 = F_67 ( V_2 -> V_210 ) ;
if ( V_35 < 0 )
return V_35 ;
}
F_37 ( V_2 ) ;
F_1 ( V_2 ) ;
V_35 = F_23 ( V_2 , 1 ) ;
if ( V_35 < 0 ) {
if ( V_2 -> V_210 )
F_68 ( V_2 -> V_210 ) ;
return V_35 ;
}
break;
case V_165 :
if ( V_2 -> V_163 != V_165 ) {
struct V_93 * V_67 ;
V_67 = & V_2 -> V_105 [ V_100 ] ;
V_2 -> V_211 . V_131 = V_67 -> V_122 ;
V_2 -> V_211 . V_134 = V_67 -> V_108 ;
V_2 -> V_211 . V_139 = 0 ;
F_46 ( V_2 , & V_2 -> V_211 ) ;
F_69 ( V_4 , V_212 ) ;
F_1 ( V_2 ) ;
}
F_28 ( V_2 , 1 ) ;
break;
case V_208 :
if ( F_70 ( & V_192 -> V_101 , & V_2 -> V_169 ,
& V_2 -> V_170 ) )
F_3 ( V_5 , L_8 , V_192 -> V_213 ) ;
if ( V_2 -> V_177 == V_183 ) {
F_28 ( V_2 , 0 ) ;
F_71 ( V_4 , V_212 ) ;
} else if ( V_2 -> V_177 == V_178 ) {
F_23 ( V_2 , 0 ) ;
if ( V_2 -> V_210 )
F_68 ( V_2 -> V_210 ) ;
}
break;
}
V_2 -> V_163 = V_34 ;
return 0 ;
}
static int F_72 ( struct V_214 * V_215 , struct V_160 * V_161 )
{
struct V_1 * V_2 = & V_215 -> V_4 -> V_216 ;
F_47 ( V_2 , V_161 -> V_162 ) ;
return 0 ;
}
static int F_73 ( struct V_217 * V_101 ,
const struct V_94 * V_218 ,
const struct V_94 * V_219 , T_2 V_220 )
{
struct V_96 * V_192 = F_39 ( V_101 ) ;
struct V_1 * V_2 = F_58 ( V_192 ) ;
unsigned int V_194 = V_218 -> V_194 ;
if ( F_74 ( V_219 -> V_101 ) )
V_194 |= 2 << 16 ;
switch ( V_194 ) {
case V_100 :
if ( V_220 & V_221 ) {
if ( V_2 -> V_177 == V_178 )
return - V_222 ;
V_2 -> V_177 = V_183 ;
} else {
if ( V_2 -> V_177 == V_183 )
V_2 -> V_177 = V_223 ;
}
break;
case V_100 | 2 << 16 :
if ( V_220 & V_221 ) {
if ( V_2 -> V_177 == V_183 )
return - V_222 ;
V_2 -> V_177 = V_178 ;
} else {
if ( V_2 -> V_177 == V_178 )
V_2 -> V_177 = V_223 ;
} break;
case V_113 | 2 << 16 :
if ( V_220 & V_221 )
V_2 -> V_224 = V_225 ;
else
V_2 -> V_224 = V_226 ;
break;
default:
return - V_196 ;
}
return 0 ;
}
void F_75 ( struct V_1 * V_2 )
{
F_76 ( & V_2 -> V_111 ) ;
F_77 ( & V_2 -> V_137 ) ;
}
int F_78 ( struct V_1 * V_2 ,
struct V_227 * V_228 )
{
int V_35 ;
V_35 = F_79 ( V_228 , & V_2 -> V_111 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_80 ( & V_2 -> V_137 , V_228 ) ;
if ( V_35 < 0 )
goto error;
return 0 ;
error:
F_75 ( V_2 ) ;
return V_35 ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_96 * V_192 = & V_2 -> V_111 ;
struct V_94 * V_99 = V_2 -> V_99 ;
struct V_217 * V_229 = & V_192 -> V_101 ;
int V_35 ;
V_2 -> V_177 = V_223 ;
V_2 -> V_224 = V_226 ;
F_82 ( V_192 , & V_230 ) ;
V_192 -> V_231 = & V_232 ;
F_83 ( V_192 -> V_213 , L_9 , sizeof( V_192 -> V_213 ) ) ;
V_192 -> V_233 = 1 << 16 ;
F_84 ( V_192 , V_2 ) ;
V_192 -> V_220 |= V_234 ;
V_99 [ V_100 ] . V_220 = V_235
| V_236 ;
V_99 [ V_113 ] . V_220 = V_237 ;
V_229 -> V_238 = & V_239 ;
V_35 = F_85 ( V_229 , V_240 , V_99 ) ;
if ( V_35 < 0 )
return V_35 ;
F_63 ( V_192 , NULL ) ;
V_2 -> V_137 . type = V_241 ;
V_2 -> V_137 . V_242 = 32 ;
V_2 -> V_137 . V_243 = 0xffffffe0 ;
V_2 -> V_137 . V_4 = F_2 ( V_2 ) ;
V_2 -> V_137 . V_238 = & V_244 ;
V_2 -> V_137 . V_245 = F_86 ( 4096 * 4096 ) * 3 ;
V_35 = F_87 ( & V_2 -> V_137 , L_10 ) ;
if ( V_35 < 0 )
goto error;
return 0 ;
error:
F_88 ( & V_2 -> V_111 . V_101 ) ;
return V_35 ;
}
int F_89 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_216 ;
int V_35 ;
F_90 ( & V_2 -> V_169 ) ;
if ( V_4 -> V_30 == V_246 ) {
V_2 -> V_36 = F_91 ( V_4 -> V_5 , L_11 ) ;
if ( F_92 ( V_2 -> V_36 ) ) {
F_3 ( V_4 -> V_5 ,
L_12 ) ;
V_2 -> V_36 = NULL ;
}
} else if ( V_4 -> V_30 == V_31 ) {
V_2 -> V_210 = & V_4 -> V_247 ;
}
V_35 = F_81 ( V_2 ) ;
if ( V_35 < 0 )
return V_35 ;
F_16 ( V_2 ) ;
return 0 ;
}
void F_93 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_216 ;
F_94 ( & V_2 -> V_137 ) ;
F_88 ( & V_2 -> V_111 . V_101 ) ;
}
