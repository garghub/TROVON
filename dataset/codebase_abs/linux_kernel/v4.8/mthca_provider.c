static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 1 ;
V_2 -> V_4 = V_5 ;
V_2 -> V_6 = 1 ;
V_2 -> V_7 = V_8 ;
}
static int F_2 ( struct V_9 * V_10 , struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_1 * V_15 = NULL ;
struct V_1 * V_16 = NULL ;
int V_17 = - V_18 ;
struct V_19 * V_20 = F_3 ( V_10 ) ;
if ( V_14 -> V_21 || V_14 -> V_22 )
return - V_23 ;
V_15 = F_4 ( sizeof *V_15 , V_24 ) ;
V_16 = F_5 ( sizeof *V_16 , V_24 ) ;
if ( ! V_15 || ! V_16 )
goto V_25;
memset ( V_12 , 0 , sizeof *V_12 ) ;
V_12 -> V_26 = V_20 -> V_26 ;
F_1 ( V_15 ) ;
V_15 -> V_27 = V_28 ;
V_17 = F_6 ( V_20 , 1 , 1 ,
1 , NULL , NULL , V_15 , V_16 ) ;
if ( V_17 )
goto V_25;
V_12 -> V_29 = V_20 -> V_29 ;
V_12 -> V_30 = F_7 ( ( V_31 * ) ( V_16 -> V_32 + 36 ) ) &
0xffffff ;
V_12 -> V_33 = F_8 ( ( V_34 * ) ( V_16 -> V_32 + 30 ) ) ;
V_12 -> V_35 = F_7 ( ( V_31 * ) ( V_16 -> V_32 + 32 ) ) ;
memcpy ( & V_12 -> V_36 , V_16 -> V_32 + 4 , 8 ) ;
V_12 -> V_37 = ~ 0ull ;
V_12 -> V_38 = V_20 -> V_39 . V_38 ;
V_12 -> V_40 = V_20 -> V_39 . V_41 - V_20 -> V_39 . V_42 ;
V_12 -> V_43 = V_20 -> V_39 . V_44 ;
V_12 -> V_45 = V_20 -> V_39 . V_46 ;
V_12 -> V_47 = V_12 -> V_45 ;
V_12 -> V_48 = V_20 -> V_39 . V_49 - V_20 -> V_39 . V_50 ;
V_12 -> V_51 = V_20 -> V_39 . V_52 ;
V_12 -> V_53 = V_20 -> V_39 . V_54 - V_20 -> V_39 . V_55 ;
V_12 -> V_56 = V_20 -> V_39 . V_57 - V_20 -> V_39 . V_58 ;
V_12 -> V_59 = 1 << V_20 -> V_60 . V_61 ;
V_12 -> V_62 = V_20 -> V_39 . V_63 ;
V_12 -> V_64 = V_12 -> V_59 * V_12 -> V_40 ;
V_12 -> V_65 = V_20 -> V_39 . V_66 - V_20 -> V_39 . V_67 ;
V_12 -> V_68 = V_20 -> V_39 . V_69 ;
V_12 -> V_70 = V_20 -> V_39 . V_70 ;
V_12 -> V_71 = V_20 -> V_39 . V_71 ;
V_12 -> V_72 = V_20 -> V_39 . V_73 & V_74 ?
V_75 : V_76 ;
V_12 -> V_77 = V_20 -> V_39 . V_78 ;
V_12 -> V_79 = V_20 -> V_39 . V_80 + V_20 -> V_39 . V_81 ;
V_12 -> V_82 = V_83 ;
V_12 -> V_84 = V_12 -> V_82 *
V_12 -> V_79 ;
if ( V_20 -> V_85 & V_86 )
V_12 -> V_87 = 255 ;
else
V_12 -> V_87 =
( 1 << ( 32 - F_9 ( V_20 -> V_39 . V_54 ) ) ) - 1 ;
V_17 = 0 ;
V_25:
F_10 ( V_15 ) ;
F_10 ( V_16 ) ;
return V_17 ;
}
static int F_11 ( struct V_9 * V_10 ,
T_1 V_88 , struct V_89 * V_12 )
{
struct V_1 * V_15 = NULL ;
struct V_1 * V_16 = NULL ;
int V_17 = - V_18 ;
V_15 = F_4 ( sizeof *V_15 , V_24 ) ;
V_16 = F_5 ( sizeof *V_16 , V_24 ) ;
if ( ! V_15 || ! V_16 )
goto V_25;
memset ( V_12 , 0 , sizeof *V_12 ) ;
F_1 ( V_15 ) ;
V_15 -> V_27 = V_90 ;
V_15 -> V_91 = F_12 ( V_88 ) ;
V_17 = F_6 ( F_3 ( V_10 ) , 1 , 1 ,
V_88 , NULL , NULL , V_15 , V_16 ) ;
if ( V_17 )
goto V_25;
V_12 -> V_92 = F_8 ( ( V_34 * ) ( V_16 -> V_32 + 16 ) ) ;
V_12 -> V_93 = V_16 -> V_32 [ 34 ] & 0x7 ;
V_12 -> V_94 = F_8 ( ( V_34 * ) ( V_16 -> V_32 + 18 ) ) ;
V_12 -> V_95 = V_16 -> V_32 [ 36 ] & 0xf ;
V_12 -> V_96 = V_16 -> V_32 [ 32 ] & 0xf ;
V_12 -> V_97 = V_16 -> V_32 [ 33 ] >> 4 ;
V_12 -> V_98 = F_7 ( ( V_31 * ) ( V_16 -> V_32 + 20 ) ) ;
V_12 -> V_99 = F_3 ( V_10 ) -> V_39 . V_100 ;
V_12 -> V_101 = 0x80000000 ;
V_12 -> V_102 = F_3 ( V_10 ) -> V_39 . V_78 ;
V_12 -> V_103 = F_8 ( ( V_34 * ) ( V_16 -> V_32 + 46 ) ) ;
V_12 -> V_104 = F_8 ( ( V_34 * ) ( V_16 -> V_32 + 48 ) ) ;
V_12 -> V_105 = V_16 -> V_32 [ 31 ] & 0xf ;
V_12 -> V_106 = V_16 -> V_32 [ 35 ] >> 4 ;
V_12 -> V_107 = V_16 -> V_32 [ 41 ] & 0xf ;
V_12 -> V_108 = V_16 -> V_32 [ 36 ] >> 4 ;
V_12 -> V_109 = V_16 -> V_32 [ 51 ] & 0x1f ;
V_12 -> V_110 = V_16 -> V_32 [ 37 ] >> 4 ;
V_12 -> V_111 = V_16 -> V_32 [ 41 ] >> 4 ;
V_25:
F_10 ( V_15 ) ;
F_10 ( V_16 ) ;
return V_17 ;
}
static int F_13 ( struct V_9 * V_10 ,
int V_112 ,
struct V_113 * V_12 )
{
if ( V_112 & ~ V_114 )
return - V_115 ;
if ( V_112 & V_114 ) {
if ( F_14 ( & F_3 ( V_10 ) -> V_116 ) )
return - V_117 ;
memcpy ( V_10 -> V_118 , V_12 -> V_118 , 64 ) ;
F_15 ( & F_3 ( V_10 ) -> V_116 ) ;
}
return 0 ;
}
static int F_16 ( struct V_9 * V_10 ,
T_1 V_88 , int V_119 ,
struct V_120 * V_12 )
{
struct V_121 V_122 ;
struct V_89 V_123 ;
int V_17 ;
if ( F_14 ( & F_3 ( V_10 ) -> V_116 ) )
return - V_117 ;
V_17 = F_11 ( V_10 , V_88 , & V_123 ) ;
if ( V_17 )
goto V_25;
V_122 . V_124 = 0 ;
V_122 . V_125 = ! ! ( V_119 & V_126 ) ;
V_122 . V_127 = ( V_123 . V_98 | V_12 -> V_128 ) &
~ V_12 -> V_129 ;
V_17 = F_17 ( F_3 ( V_10 ) , & V_122 , V_88 ) ;
if ( V_17 )
goto V_25;
V_25:
F_15 ( & F_3 ( V_10 ) -> V_116 ) ;
return V_17 ;
}
static int F_18 ( struct V_9 * V_10 ,
T_1 V_88 , T_2 V_130 , T_2 * V_131 )
{
struct V_1 * V_15 = NULL ;
struct V_1 * V_16 = NULL ;
int V_17 = - V_18 ;
V_15 = F_4 ( sizeof *V_15 , V_24 ) ;
V_16 = F_5 ( sizeof *V_16 , V_24 ) ;
if ( ! V_15 || ! V_16 )
goto V_25;
F_1 ( V_15 ) ;
V_15 -> V_27 = V_132 ;
V_15 -> V_91 = F_12 ( V_130 / 32 ) ;
V_17 = F_6 ( F_3 ( V_10 ) , 1 , 1 ,
V_88 , NULL , NULL , V_15 , V_16 ) ;
if ( V_17 )
goto V_25;
* V_131 = F_19 ( ( ( V_34 * ) V_16 -> V_32 ) [ V_130 % 32 ] ) ;
V_25:
F_10 ( V_15 ) ;
F_10 ( V_16 ) ;
return V_17 ;
}
static int F_20 ( struct V_9 * V_10 , T_1 V_88 ,
int V_130 , union V_133 * V_134 )
{
struct V_1 * V_15 = NULL ;
struct V_1 * V_16 = NULL ;
int V_17 = - V_18 ;
V_15 = F_4 ( sizeof *V_15 , V_24 ) ;
V_16 = F_5 ( sizeof *V_16 , V_24 ) ;
if ( ! V_15 || ! V_16 )
goto V_25;
F_1 ( V_15 ) ;
V_15 -> V_27 = V_90 ;
V_15 -> V_91 = F_12 ( V_88 ) ;
V_17 = F_6 ( F_3 ( V_10 ) , 1 , 1 ,
V_88 , NULL , NULL , V_15 , V_16 ) ;
if ( V_17 )
goto V_25;
memcpy ( V_134 -> V_135 , V_16 -> V_32 + 8 , 8 ) ;
F_1 ( V_15 ) ;
V_15 -> V_27 = V_136 ;
V_15 -> V_91 = F_12 ( V_130 / 8 ) ;
V_17 = F_6 ( F_3 ( V_10 ) , 1 , 1 ,
V_88 , NULL , NULL , V_15 , V_16 ) ;
if ( V_17 )
goto V_25;
memcpy ( V_134 -> V_135 + 8 , V_16 -> V_32 + ( V_130 % 8 ) * 8 , 8 ) ;
V_25:
F_10 ( V_15 ) ;
F_10 ( V_16 ) ;
return V_17 ;
}
static struct V_137 * F_21 ( struct V_9 * V_10 ,
struct V_13 * V_138 )
{
struct V_139 V_140 ;
struct V_141 * V_142 ;
int V_17 ;
if ( ! ( F_3 ( V_10 ) -> V_143 ) )
return F_22 ( - V_144 ) ;
memset ( & V_140 , 0 , sizeof V_140 ) ;
V_140 . V_145 = F_3 ( V_10 ) -> V_39 . V_41 ;
if ( F_23 ( F_3 ( V_10 ) ) )
V_140 . V_146 = F_3 ( V_10 ) -> V_147 . V_146 ;
else
V_140 . V_146 = 0 ;
V_142 = F_5 ( sizeof *V_142 , V_24 ) ;
if ( ! V_142 )
return F_22 ( - V_18 ) ;
V_17 = F_24 ( F_3 ( V_10 ) , & V_142 -> V_148 ) ;
if ( V_17 ) {
F_10 ( V_142 ) ;
return F_22 ( V_17 ) ;
}
V_142 -> V_149 = F_25 ( F_3 ( V_10 ) ) ;
if ( F_26 ( V_142 -> V_149 ) ) {
V_17 = F_27 ( V_142 -> V_149 ) ;
F_28 ( F_3 ( V_10 ) , & V_142 -> V_148 ) ;
F_10 ( V_142 ) ;
return F_22 ( V_17 ) ;
}
if ( F_29 ( V_138 , & V_140 , sizeof V_140 ) ) {
F_30 ( F_3 ( V_10 ) , & V_142 -> V_148 , V_142 -> V_149 ) ;
F_28 ( F_3 ( V_10 ) , & V_142 -> V_148 ) ;
F_10 ( V_142 ) ;
return F_22 ( - V_150 ) ;
}
V_142 -> V_151 = 0 ;
return & V_142 -> V_152 ;
}
static int F_31 ( struct V_137 * V_142 )
{
F_30 ( F_3 ( V_142 -> V_153 ) , & F_32 ( V_142 ) -> V_148 ,
F_32 ( V_142 ) -> V_149 ) ;
F_28 ( F_3 ( V_142 -> V_153 ) , & F_32 ( V_142 ) -> V_148 ) ;
F_10 ( F_32 ( V_142 ) ) ;
return 0 ;
}
static int F_33 ( struct V_137 * V_142 ,
struct V_154 * V_155 )
{
if ( V_155 -> V_156 - V_155 -> V_157 != V_158 )
return - V_23 ;
V_155 -> V_159 = F_34 ( V_155 -> V_159 ) ;
if ( F_35 ( V_155 , V_155 -> V_157 ,
F_32 ( V_142 ) -> V_148 . V_160 ,
V_158 , V_155 -> V_159 ) )
return - V_144 ;
return 0 ;
}
static struct V_161 * F_36 ( struct V_9 * V_10 ,
struct V_137 * V_142 ,
struct V_13 * V_138 )
{
struct V_162 * V_163 ;
int V_17 ;
V_163 = F_5 ( sizeof *V_163 , V_24 ) ;
if ( ! V_163 )
return F_22 ( - V_18 ) ;
V_17 = F_37 ( F_3 ( V_10 ) , ! V_142 , V_163 ) ;
if ( V_17 ) {
F_10 ( V_163 ) ;
return F_22 ( V_17 ) ;
}
if ( V_142 ) {
if ( F_29 ( V_138 , & V_163 -> V_164 , sizeof ( V_165 ) ) ) {
F_38 ( F_3 ( V_10 ) , V_163 ) ;
F_10 ( V_163 ) ;
return F_22 ( - V_150 ) ;
}
}
return & V_163 -> V_166 ;
}
static int F_39 ( struct V_161 * V_163 )
{
F_38 ( F_3 ( V_163 -> V_153 ) , F_40 ( V_163 ) ) ;
F_10 ( V_163 ) ;
return 0 ;
}
static struct V_167 * F_41 ( struct V_161 * V_163 ,
struct V_168 * V_169 )
{
int V_17 ;
struct V_170 * V_171 ;
V_171 = F_5 ( sizeof *V_171 , V_172 ) ;
if ( ! V_171 )
return F_22 ( - V_18 ) ;
V_17 = F_42 ( F_3 ( V_163 -> V_153 ) , F_40 ( V_163 ) , V_169 , V_171 ) ;
if ( V_17 ) {
F_10 ( V_171 ) ;
return F_22 ( V_17 ) ;
}
return & V_171 -> V_173 ;
}
static int F_43 ( struct V_167 * V_171 )
{
F_44 ( F_3 ( V_171 -> V_153 ) , F_45 ( V_171 ) ) ;
F_10 ( V_171 ) ;
return 0 ;
}
static struct V_174 * F_46 ( struct V_161 * V_163 ,
struct V_175 * V_176 ,
struct V_13 * V_138 )
{
struct F_46 V_177 ;
struct V_141 * V_142 = NULL ;
struct V_178 * V_179 ;
int V_17 ;
if ( V_176 -> V_180 != V_181 )
return F_22 ( - V_182 ) ;
V_179 = F_5 ( sizeof *V_179 , V_24 ) ;
if ( ! V_179 )
return F_22 ( - V_18 ) ;
if ( V_163 -> V_183 ) {
V_142 = F_32 ( V_163 -> V_183 -> V_142 ) ;
if ( F_47 ( & V_177 , V_138 , sizeof V_177 ) ) {
V_17 = - V_150 ;
goto V_184;
}
V_17 = F_48 ( F_3 ( V_163 -> V_153 ) , & V_142 -> V_148 ,
V_142 -> V_149 , V_177 . V_185 ,
V_177 . V_186 ) ;
if ( V_17 )
goto V_184;
V_179 -> V_187 . V_188 . V_189 = V_177 . V_189 ;
V_179 -> V_185 = V_177 . V_185 ;
}
V_17 = F_49 ( F_3 ( V_163 -> V_153 ) , F_40 ( V_163 ) ,
& V_176 -> V_123 , V_179 ) ;
if ( V_17 && V_163 -> V_183 )
F_50 ( F_3 ( V_163 -> V_153 ) , & V_142 -> V_148 ,
V_142 -> V_149 , V_177 . V_185 ) ;
if ( V_17 )
goto V_184;
if ( V_142 && F_29 ( V_138 , & V_179 -> V_190 , sizeof ( V_165 ) ) ) {
F_51 ( F_3 ( V_163 -> V_153 ) , V_179 ) ;
V_17 = - V_150 ;
goto V_184;
}
return & V_179 -> V_191 ;
V_184:
F_10 ( V_179 ) ;
return F_22 ( V_17 ) ;
}
static int F_52 ( struct V_174 * V_179 )
{
struct V_141 * V_142 ;
if ( V_179 -> V_183 ) {
V_142 = F_32 ( V_179 -> V_183 -> V_142 ) ;
F_50 ( F_3 ( V_179 -> V_153 ) , & V_142 -> V_148 ,
V_142 -> V_149 , F_53 ( V_179 ) -> V_185 ) ;
}
F_51 ( F_3 ( V_179 -> V_153 ) , F_53 ( V_179 ) ) ;
F_10 ( V_179 ) ;
return 0 ;
}
static struct V_192 * F_54 ( struct V_161 * V_163 ,
struct V_193 * V_176 ,
struct V_13 * V_138 )
{
struct F_54 V_177 ;
struct V_194 * V_195 ;
int V_17 ;
if ( V_176 -> V_196 )
return F_22 ( - V_23 ) ;
switch ( V_176 -> V_197 ) {
case V_198 :
case V_199 :
case V_200 :
{
struct V_141 * V_142 ;
V_195 = F_5 ( sizeof *V_195 , V_24 ) ;
if ( ! V_195 )
return F_22 ( - V_18 ) ;
if ( V_163 -> V_183 ) {
V_142 = F_32 ( V_163 -> V_183 -> V_142 ) ;
if ( F_47 ( & V_177 , V_138 , sizeof V_177 ) ) {
F_10 ( V_195 ) ;
return F_22 ( - V_150 ) ;
}
V_17 = F_48 ( F_3 ( V_163 -> V_153 ) , & V_142 -> V_148 ,
V_142 -> V_149 ,
V_177 . V_201 , V_177 . V_202 ) ;
if ( V_17 ) {
F_10 ( V_195 ) ;
return F_22 ( V_17 ) ;
}
V_17 = F_48 ( F_3 ( V_163 -> V_153 ) , & V_142 -> V_148 ,
V_142 -> V_149 ,
V_177 . V_203 , V_177 . V_204 ) ;
if ( V_17 ) {
F_50 ( F_3 ( V_163 -> V_153 ) ,
& V_142 -> V_148 ,
V_142 -> V_149 ,
V_177 . V_201 ) ;
F_10 ( V_195 ) ;
return F_22 ( V_17 ) ;
}
V_195 -> V_187 . V_188 . V_189 = V_177 . V_189 ;
V_195 -> V_205 . V_185 = V_177 . V_201 ;
V_195 -> V_206 . V_185 = V_177 . V_203 ;
}
V_17 = F_55 ( F_3 ( V_163 -> V_153 ) , F_40 ( V_163 ) ,
F_56 ( V_176 -> V_207 ) ,
F_56 ( V_176 -> V_208 ) ,
V_176 -> V_197 , V_176 -> V_209 ,
& V_176 -> V_210 , V_195 ) ;
if ( V_17 && V_163 -> V_183 ) {
V_142 = F_32 ( V_163 -> V_183 -> V_142 ) ;
F_50 ( F_3 ( V_163 -> V_153 ) ,
& V_142 -> V_148 ,
V_142 -> V_149 ,
V_177 . V_201 ) ;
F_50 ( F_3 ( V_163 -> V_153 ) ,
& V_142 -> V_148 ,
V_142 -> V_149 ,
V_177 . V_203 ) ;
}
V_195 -> V_211 . V_212 = V_195 -> V_213 ;
break;
}
case V_214 :
case V_215 :
{
if ( V_163 -> V_183 )
return F_22 ( - V_23 ) ;
V_195 = F_5 ( sizeof ( struct V_216 ) , V_24 ) ;
if ( ! V_195 )
return F_22 ( - V_18 ) ;
V_195 -> V_211 . V_212 = V_176 -> V_197 == V_214 ? 0 : 1 ;
V_17 = F_57 ( F_3 ( V_163 -> V_153 ) , F_40 ( V_163 ) ,
F_56 ( V_176 -> V_207 ) ,
F_56 ( V_176 -> V_208 ) ,
V_176 -> V_209 , & V_176 -> V_210 ,
V_195 -> V_211 . V_212 , V_176 -> V_217 ,
F_58 ( V_195 ) ) ;
break;
}
default:
return F_22 ( - V_182 ) ;
}
if ( V_17 ) {
F_10 ( V_195 ) ;
return F_22 ( V_17 ) ;
}
V_176 -> V_210 . V_218 = V_195 -> V_205 . V_219 ;
V_176 -> V_210 . V_220 = V_195 -> V_206 . V_219 ;
V_176 -> V_210 . V_221 = V_195 -> V_205 . V_222 ;
V_176 -> V_210 . V_223 = V_195 -> V_206 . V_222 ;
V_176 -> V_210 . V_224 = V_195 -> V_224 ;
return & V_195 -> V_211 ;
}
static int F_59 ( struct V_192 * V_195 )
{
if ( V_195 -> V_183 ) {
F_50 ( F_3 ( V_195 -> V_153 ) ,
& F_32 ( V_195 -> V_183 -> V_142 ) -> V_148 ,
F_32 ( V_195 -> V_183 -> V_142 ) -> V_149 ,
F_60 ( V_195 ) -> V_205 . V_185 ) ;
F_50 ( F_3 ( V_195 -> V_153 ) ,
& F_32 ( V_195 -> V_183 -> V_142 ) -> V_148 ,
F_32 ( V_195 -> V_183 -> V_142 ) -> V_149 ,
F_60 ( V_195 ) -> V_206 . V_185 ) ;
}
F_61 ( F_3 ( V_195 -> V_153 ) , F_60 ( V_195 ) ) ;
F_10 ( V_195 ) ;
return 0 ;
}
static struct V_225 * F_62 ( struct V_9 * V_10 ,
const struct V_226 * V_123 ,
struct V_137 * V_142 ,
struct V_13 * V_138 )
{
int V_227 = V_123 -> V_228 ;
struct F_62 V_177 ;
struct V_229 * V_230 ;
int V_231 ;
int V_17 ;
if ( V_123 -> V_73 )
return F_22 ( - V_23 ) ;
if ( V_227 < 1 || V_227 > F_3 ( V_10 ) -> V_39 . V_52 )
return F_22 ( - V_23 ) ;
if ( V_142 ) {
if ( F_47 ( & V_177 , V_138 , sizeof V_177 ) )
return F_22 ( - V_150 ) ;
V_17 = F_48 ( F_3 ( V_10 ) , & F_32 ( V_142 ) -> V_148 ,
F_32 ( V_142 ) -> V_149 ,
V_177 . V_232 , V_177 . V_233 ) ;
if ( V_17 )
return F_22 ( V_17 ) ;
V_17 = F_48 ( F_3 ( V_10 ) , & F_32 ( V_142 ) -> V_148 ,
F_32 ( V_142 ) -> V_149 ,
V_177 . V_234 , V_177 . V_235 ) ;
if ( V_17 )
goto V_236;
}
V_230 = F_5 ( sizeof *V_230 , V_24 ) ;
if ( ! V_230 ) {
V_17 = - V_18 ;
goto V_237;
}
if ( V_142 ) {
V_230 -> V_238 . V_187 . V_188 . V_189 = V_177 . V_189 ;
V_230 -> V_239 = V_177 . V_232 ;
V_230 -> V_234 = V_177 . V_234 ;
}
for ( V_231 = 1 ; V_231 <= V_227 ; V_231 <<= 1 )
;
V_17 = F_63 ( F_3 ( V_10 ) , V_231 ,
V_142 ? F_32 ( V_142 ) : NULL ,
V_142 ? V_177 . V_240 : F_3 ( V_10 ) -> V_241 . V_164 ,
V_230 ) ;
if ( V_17 )
goto V_184;
if ( V_142 && F_29 ( V_138 , & V_230 -> V_242 , sizeof ( V_165 ) ) ) {
F_64 ( F_3 ( V_10 ) , V_230 ) ;
V_17 = - V_150 ;
goto V_184;
}
V_230 -> V_243 = NULL ;
return & V_230 -> V_244 ;
V_184:
F_10 ( V_230 ) ;
V_237:
if ( V_142 )
F_50 ( F_3 ( V_10 ) , & F_32 ( V_142 ) -> V_148 ,
F_32 ( V_142 ) -> V_149 , V_177 . V_234 ) ;
V_236:
if ( V_142 )
F_50 ( F_3 ( V_10 ) , & F_32 ( V_142 ) -> V_148 ,
F_32 ( V_142 ) -> V_149 , V_177 . V_232 ) ;
return F_22 ( V_17 ) ;
}
static int F_65 ( struct V_19 * V_245 , struct V_229 * V_230 ,
int V_227 )
{
int V_246 ;
F_66 ( & V_230 -> V_247 ) ;
if ( V_230 -> V_243 ) {
V_246 = - V_248 ;
goto V_249;
}
V_230 -> V_243 = F_5 ( sizeof * V_230 -> V_243 , V_172 ) ;
if ( ! V_230 -> V_243 ) {
V_246 = - V_18 ;
goto V_249;
}
V_230 -> V_243 -> V_96 = V_250 ;
V_246 = 0 ;
V_249:
F_67 ( & V_230 -> V_247 ) ;
if ( V_246 )
return V_246 ;
V_246 = F_68 ( V_245 , & V_230 -> V_243 -> V_238 , V_227 ) ;
if ( V_246 ) {
F_66 ( & V_230 -> V_247 ) ;
F_10 ( V_230 -> V_243 ) ;
V_230 -> V_243 = NULL ;
F_67 ( & V_230 -> V_247 ) ;
return V_246 ;
}
V_230 -> V_243 -> V_228 = V_227 - 1 ;
F_66 ( & V_230 -> V_247 ) ;
V_230 -> V_243 -> V_96 = V_251 ;
F_67 ( & V_230 -> V_247 ) ;
return 0 ;
}
static int F_69 ( struct V_225 * V_244 , int V_227 , struct V_13 * V_138 )
{
struct V_19 * V_245 = F_3 ( V_244 -> V_153 ) ;
struct V_229 * V_230 = F_56 ( V_244 ) ;
struct F_69 V_177 ;
T_3 V_189 ;
int V_246 ;
if ( V_227 < 1 || V_227 > V_245 -> V_39 . V_52 )
return - V_23 ;
F_70 ( & V_230 -> V_252 ) ;
V_227 = F_71 ( V_227 + 1 ) ;
if ( V_227 == V_244 -> V_228 + 1 ) {
V_246 = 0 ;
goto V_25;
}
if ( V_230 -> V_253 ) {
V_246 = F_65 ( V_245 , V_230 , V_227 ) ;
if ( V_246 )
goto V_25;
V_189 = V_230 -> V_243 -> V_238 . V_187 . V_188 . V_189 ;
} else {
if ( F_47 ( & V_177 , V_138 , sizeof V_177 ) ) {
V_246 = - V_150 ;
goto V_25;
}
V_189 = V_177 . V_189 ;
}
V_246 = F_72 ( V_245 , V_230 -> V_242 , V_189 , F_9 ( V_227 ) ) ;
if ( V_246 ) {
if ( V_230 -> V_243 ) {
F_73 ( V_245 , & V_230 -> V_243 -> V_238 ,
V_230 -> V_243 -> V_228 ) ;
F_10 ( V_230 -> V_243 ) ;
F_66 ( & V_230 -> V_247 ) ;
V_230 -> V_243 = NULL ;
F_67 ( & V_230 -> V_247 ) ;
}
goto V_25;
}
if ( V_230 -> V_253 ) {
struct V_254 V_255 ;
int V_256 ;
F_66 ( & V_230 -> V_247 ) ;
if ( V_230 -> V_243 -> V_96 == V_251 ) {
F_74 ( V_230 ) ;
V_255 = V_230 -> V_238 ;
V_256 = V_230 -> V_244 . V_228 ;
V_230 -> V_238 = V_230 -> V_243 -> V_238 ;
V_230 -> V_244 . V_228 = V_230 -> V_243 -> V_228 ;
} else {
V_255 = V_230 -> V_243 -> V_238 ;
V_256 = V_230 -> V_243 -> V_228 ;
}
F_10 ( V_230 -> V_243 ) ;
V_230 -> V_243 = NULL ;
F_67 ( & V_230 -> V_247 ) ;
F_73 ( V_245 , & V_255 , V_256 ) ;
} else
V_244 -> V_228 = V_227 - 1 ;
V_25:
F_15 ( & V_230 -> V_252 ) ;
return V_246 ;
}
static int F_75 ( struct V_225 * V_230 )
{
if ( V_230 -> V_183 ) {
F_50 ( F_3 ( V_230 -> V_153 ) ,
& F_32 ( V_230 -> V_183 -> V_142 ) -> V_148 ,
F_32 ( V_230 -> V_183 -> V_142 ) -> V_149 ,
F_56 ( V_230 ) -> V_234 ) ;
F_50 ( F_3 ( V_230 -> V_153 ) ,
& F_32 ( V_230 -> V_183 -> V_142 ) -> V_148 ,
F_32 ( V_230 -> V_183 -> V_142 ) -> V_149 ,
F_56 ( V_230 ) -> V_239 ) ;
}
F_64 ( F_3 ( V_230 -> V_153 ) , F_56 ( V_230 ) ) ;
F_10 ( V_230 ) ;
return 0 ;
}
static inline T_3 F_76 ( int V_257 )
{
return ( V_257 & V_258 ? V_259 : 0 ) |
( V_257 & V_260 ? V_261 : 0 ) |
( V_257 & V_262 ? V_263 : 0 ) |
( V_257 & V_264 ? V_265 : 0 ) |
V_266 ;
}
static struct V_267 * F_77 ( struct V_161 * V_163 , int V_257 )
{
struct V_268 * V_187 ;
int V_17 ;
V_187 = F_5 ( sizeof *V_187 , V_24 ) ;
if ( ! V_187 )
return F_22 ( - V_18 ) ;
V_17 = F_78 ( F_3 ( V_163 -> V_153 ) ,
F_40 ( V_163 ) -> V_164 ,
F_76 ( V_257 ) , V_187 ) ;
if ( V_17 ) {
F_10 ( V_187 ) ;
return F_22 ( V_17 ) ;
}
V_187 -> V_269 = NULL ;
return & V_187 -> V_188 ;
}
static struct V_267 * F_79 ( struct V_161 * V_163 , T_4 V_270 , T_4 V_271 ,
T_4 V_272 , int V_257 , struct V_13 * V_138 )
{
struct V_19 * V_245 = F_3 ( V_163 -> V_153 ) ;
struct V_273 * V_274 ;
struct V_268 * V_187 ;
struct V_275 V_177 ;
T_4 * V_276 ;
int V_277 , V_278 , V_279 ;
int V_280 , V_281 , V_282 ;
int V_17 = 0 ;
int V_283 ;
if ( V_138 -> V_21 - sizeof ( struct V_284 ) < sizeof V_177 ) {
if ( ! F_32 ( V_163 -> V_183 -> V_142 ) -> V_151 ) {
F_80 ( V_245 , L_1 ,
V_285 -> V_286 ) ;
F_80 ( V_245 , L_2 ) ;
}
++ F_32 ( V_163 -> V_183 -> V_142 ) -> V_151 ;
V_177 . V_287 = 0 ;
} else if ( F_47 ( & V_177 , V_138 , sizeof V_177 ) )
return F_22 ( - V_150 ) ;
V_187 = F_5 ( sizeof *V_187 , V_24 ) ;
if ( ! V_187 )
return F_22 ( - V_18 ) ;
V_187 -> V_269 = F_81 ( V_163 -> V_183 -> V_142 , V_270 , V_271 , V_257 ,
V_177 . V_287 & V_288 ) ;
if ( F_26 ( V_187 -> V_269 ) ) {
V_17 = F_27 ( V_187 -> V_269 ) ;
goto V_17;
}
V_277 = F_82 ( V_187 -> V_269 -> V_289 ) - 1 ;
V_278 = V_187 -> V_269 -> V_290 ;
V_187 -> V_291 = F_83 ( V_245 , V_278 ) ;
if ( F_26 ( V_187 -> V_291 ) ) {
V_17 = F_27 ( V_187 -> V_291 ) ;
goto V_292;
}
V_276 = ( T_4 * ) F_84 ( V_24 ) ;
if ( ! V_276 ) {
V_17 = - V_18 ;
goto V_293;
}
V_280 = V_278 = 0 ;
V_283 = F_85 ( F_86 ( V_245 ) , ( int ) ( V_158 / sizeof *V_276 ) ) ;
F_87 (mr->umem->sg_head.sgl, sg, mr->umem->nmap, entry) {
V_279 = F_88 ( V_274 ) >> V_277 ;
for ( V_281 = 0 ; V_281 < V_279 ; ++ V_281 ) {
V_276 [ V_280 ++ ] = F_89 ( V_274 ) +
V_187 -> V_269 -> V_289 * V_281 ;
if ( V_280 == V_283 ) {
V_17 = F_90 ( V_245 , V_187 -> V_291 , V_278 , V_276 , V_280 ) ;
if ( V_17 )
goto V_294;
V_278 += V_280 ;
V_280 = 0 ;
}
}
}
if ( V_280 )
V_17 = F_90 ( V_245 , V_187 -> V_291 , V_278 , V_276 , V_280 ) ;
V_294:
F_91 ( ( unsigned long ) V_276 ) ;
if ( V_17 )
goto V_293;
V_17 = F_92 ( V_245 , F_40 ( V_163 ) -> V_164 , V_277 , V_272 , V_271 ,
F_76 ( V_257 ) , V_187 ) ;
if ( V_17 )
goto V_293;
return & V_187 -> V_188 ;
V_293:
F_93 ( V_245 , V_187 -> V_291 ) ;
V_292:
F_94 ( V_187 -> V_269 ) ;
V_17:
F_10 ( V_187 ) ;
return F_22 ( V_17 ) ;
}
static int F_95 ( struct V_267 * V_187 )
{
struct V_268 * V_295 = F_96 ( V_187 ) ;
F_97 ( F_3 ( V_187 -> V_153 ) , V_295 ) ;
if ( V_295 -> V_269 )
F_94 ( V_295 -> V_269 ) ;
F_10 ( V_295 ) ;
return 0 ;
}
static struct V_296 * F_98 ( struct V_161 * V_163 , int V_297 ,
struct V_298 * V_299 )
{
struct V_300 * V_301 ;
int V_17 ;
V_301 = F_5 ( sizeof *V_301 , V_24 ) ;
if ( ! V_301 )
return F_22 ( - V_18 ) ;
memcpy ( & V_301 -> V_123 , V_299 , sizeof *V_299 ) ;
V_17 = F_99 ( F_3 ( V_163 -> V_153 ) , F_40 ( V_163 ) -> V_164 ,
F_76 ( V_297 ) , V_301 ) ;
if ( V_17 ) {
F_10 ( V_301 ) ;
return F_22 ( V_17 ) ;
}
return & V_301 -> V_188 ;
}
static int F_100 ( struct V_296 * V_301 )
{
struct V_300 * V_302 = F_101 ( V_301 ) ;
int V_17 ;
V_17 = F_102 ( F_3 ( V_301 -> V_153 ) , V_302 ) ;
if ( V_17 )
return V_17 ;
F_10 ( V_302 ) ;
return 0 ;
}
static int F_103 ( struct V_303 * V_304 )
{
struct V_296 * V_301 ;
int V_17 ;
struct V_19 * V_20 = NULL ;
F_104 (fmr, fmr_list, list) {
if ( V_20 && F_3 ( V_301 -> V_153 ) != V_20 )
return - V_23 ;
V_20 = F_3 ( V_301 -> V_153 ) ;
}
if ( ! V_20 )
return 0 ;
if ( F_23 ( V_20 ) ) {
F_104 (fmr, fmr_list, list)
F_105 ( V_20 , F_101 ( V_301 ) ) ;
F_106 () ;
} else
F_104 (fmr, fmr_list, list)
F_107 ( V_20 , F_101 ( V_301 ) ) ;
V_17 = F_108 ( V_20 ) ;
return V_17 ;
}
static T_5 F_109 ( struct V_153 * V_153 , struct V_305 * V_123 ,
char * V_238 )
{
struct V_19 * V_245 =
F_110 ( V_153 , struct V_19 , V_306 . V_245 ) ;
return sprintf ( V_238 , L_3 , V_245 -> V_307 ) ;
}
static T_5 F_111 ( struct V_153 * V_153 , struct V_305 * V_123 ,
char * V_238 )
{
struct V_19 * V_245 =
F_110 ( V_153 , struct V_19 , V_306 . V_245 ) ;
switch ( V_245 -> V_308 -> V_153 ) {
case V_309 :
return sprintf ( V_238 , L_4 ) ;
case V_310 :
return sprintf ( V_238 , L_5 ) ;
case V_311 :
return sprintf ( V_238 , L_6 ) ;
case V_312 :
case V_313 :
return sprintf ( V_238 , L_7 ) ;
default:
return sprintf ( V_238 , L_8 ) ;
}
}
static T_5 F_112 ( struct V_153 * V_153 , struct V_305 * V_123 ,
char * V_238 )
{
struct V_19 * V_245 =
F_110 ( V_153 , struct V_19 , V_306 . V_245 ) ;
return sprintf ( V_238 , L_9 , V_314 , V_245 -> V_315 ) ;
}
static int F_113 ( struct V_19 * V_245 )
{
struct V_1 * V_15 = NULL ;
struct V_1 * V_16 = NULL ;
int V_17 = - V_18 ;
V_15 = F_4 ( sizeof *V_15 , V_24 ) ;
V_16 = F_5 ( sizeof *V_16 , V_24 ) ;
if ( ! V_15 || ! V_16 )
goto V_25;
F_1 ( V_15 ) ;
V_15 -> V_27 = V_316 ;
V_17 = F_6 ( V_245 , 1 , 1 ,
1 , NULL , NULL , V_15 , V_16 ) ;
if ( V_17 )
goto V_25;
memcpy ( V_245 -> V_306 . V_118 , V_16 -> V_32 , 64 ) ;
V_15 -> V_27 = V_28 ;
V_17 = F_6 ( V_245 , 1 , 1 ,
1 , NULL , NULL , V_15 , V_16 ) ;
if ( V_17 )
goto V_25;
if ( F_23 ( V_245 ) )
V_245 -> V_307 = F_7 ( ( V_31 * ) ( V_16 -> V_32 + 32 ) ) ;
memcpy ( & V_245 -> V_306 . V_317 , V_16 -> V_32 + 12 , 8 ) ;
V_25:
F_10 ( V_15 ) ;
F_10 ( V_16 ) ;
return V_17 ;
}
static int F_114 ( struct V_9 * V_10 , T_1 V_217 ,
struct V_318 * V_319 )
{
struct V_89 V_123 ;
int V_17 ;
V_17 = F_11 ( V_10 , V_217 , & V_123 ) ;
if ( V_17 )
return V_17 ;
V_319 -> V_102 = V_123 . V_102 ;
V_319 -> V_99 = V_123 . V_99 ;
V_319 -> V_320 = V_321 ;
V_319 -> V_322 = V_323 ;
return 0 ;
}
static void F_115 ( struct V_9 * V_153 , char * V_324 ,
T_6 V_325 )
{
struct V_19 * V_245 =
F_110 ( V_153 , struct V_19 , V_306 ) ;
snprintf ( V_324 , V_325 , L_10 ,
( int ) ( V_245 -> V_26 >> 32 ) ,
( int ) ( V_245 -> V_26 >> 16 ) & 0xffff ,
( int ) V_245 -> V_26 & 0xffff ) ;
}
int F_116 ( struct V_19 * V_245 )
{
int V_246 ;
int V_280 ;
V_246 = F_113 ( V_245 ) ;
if ( V_246 )
return V_246 ;
F_117 ( V_245 -> V_306 . V_326 , L_11 , V_327 ) ;
V_245 -> V_306 . V_328 = V_329 ;
V_245 -> V_306 . V_330 = V_331 ;
V_245 -> V_306 . V_332 =
( 1ull << V_333 ) |
( 1ull << V_334 ) |
( 1ull << V_335 ) |
( 1ull << V_336 ) |
( 1ull << V_337 ) |
( 1ull << V_338 ) |
( 1ull << V_339 ) |
( 1ull << V_340 ) |
( 1ull << V_341 ) |
( 1ull << V_342 ) |
( 1ull << V_343 ) |
( 1ull << V_344 ) |
( 1ull << V_345 ) |
( 1ull << V_346 ) |
( 1ull << V_347 ) |
( 1ull << V_348 ) |
( 1ull << V_349 ) ;
V_245 -> V_306 . V_350 = V_351 ;
V_245 -> V_306 . V_352 = V_245 -> V_39 . V_353 ;
V_245 -> V_306 . V_354 = 1 ;
V_245 -> V_306 . V_355 = & V_245 -> V_308 -> V_245 ;
V_245 -> V_306 . V_356 = F_2 ;
V_245 -> V_306 . V_357 = F_11 ;
V_245 -> V_306 . V_358 = F_13 ;
V_245 -> V_306 . V_359 = F_16 ;
V_245 -> V_306 . V_360 = F_18 ;
V_245 -> V_306 . V_361 = F_20 ;
V_245 -> V_306 . V_362 = F_21 ;
V_245 -> V_306 . V_363 = F_31 ;
V_245 -> V_306 . V_364 = F_33 ;
V_245 -> V_306 . V_365 = F_36 ;
V_245 -> V_306 . V_366 = F_39 ;
V_245 -> V_306 . V_367 = F_41 ;
V_245 -> V_306 . V_368 = V_369 ;
V_245 -> V_306 . V_370 = F_43 ;
if ( V_245 -> V_85 & V_371 ) {
V_245 -> V_306 . V_372 = F_46 ;
V_245 -> V_306 . V_373 = V_374 ;
V_245 -> V_306 . V_375 = V_376 ;
V_245 -> V_306 . V_377 = F_52 ;
V_245 -> V_306 . V_332 |=
( 1ull << V_378 ) |
( 1ull << V_379 ) |
( 1ull << V_380 ) |
( 1ull << V_381 ) ;
if ( F_23 ( V_245 ) )
V_245 -> V_306 . V_382 = V_383 ;
else
V_245 -> V_306 . V_382 = V_384 ;
}
V_245 -> V_306 . V_385 = F_54 ;
V_245 -> V_306 . V_386 = V_387 ;
V_245 -> V_306 . V_388 = V_389 ;
V_245 -> V_306 . V_390 = F_59 ;
V_245 -> V_306 . V_391 = F_62 ;
V_245 -> V_306 . V_392 = F_69 ;
V_245 -> V_306 . V_393 = F_75 ;
V_245 -> V_306 . V_394 = V_395 ;
V_245 -> V_306 . V_396 = F_77 ;
V_245 -> V_306 . V_397 = F_79 ;
V_245 -> V_306 . V_398 = F_95 ;
V_245 -> V_306 . V_399 = F_114 ;
V_245 -> V_306 . F_115 = F_115 ;
if ( V_245 -> V_85 & V_400 ) {
V_245 -> V_306 . V_401 = F_98 ;
V_245 -> V_306 . V_402 = F_103 ;
V_245 -> V_306 . V_403 = F_100 ;
if ( F_23 ( V_245 ) )
V_245 -> V_306 . V_404 = V_405 ;
else
V_245 -> V_306 . V_404 = V_406 ;
}
V_245 -> V_306 . V_407 = V_408 ;
V_245 -> V_306 . V_409 = V_410 ;
V_245 -> V_306 . V_411 = V_412 ;
if ( F_23 ( V_245 ) ) {
V_245 -> V_306 . V_413 = V_414 ;
V_245 -> V_306 . V_415 = V_416 ;
V_245 -> V_306 . V_417 = V_418 ;
} else {
V_245 -> V_306 . V_413 = V_419 ;
V_245 -> V_306 . V_415 = V_420 ;
V_245 -> V_306 . V_417 = V_421 ;
}
F_118 ( & V_245 -> V_116 ) ;
V_246 = F_119 ( & V_245 -> V_306 , NULL ) ;
if ( V_246 )
return V_246 ;
for ( V_280 = 0 ; V_280 < F_120 ( V_422 ) ; ++ V_280 ) {
V_246 = F_121 ( & V_245 -> V_306 . V_245 ,
V_422 [ V_280 ] ) ;
if ( V_246 ) {
F_122 ( & V_245 -> V_306 ) ;
return V_246 ;
}
}
F_123 ( V_245 ) ;
return 0 ;
}
void F_124 ( struct V_19 * V_245 )
{
F_125 ( V_245 ) ;
F_122 ( & V_245 -> V_306 ) ;
}
