static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 = 0 ;
if ( V_3 ) {
V_6 = V_7 |
V_8 ;
if ( V_5 -> V_9 . V_10 & V_11 )
V_6 |= V_12 ;
}
F_3 ( V_13 |
V_14 |
V_15 |
V_16 | V_6 ,
V_5 -> V_17 + V_18 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = & V_2 -> V_20 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
const T_1 V_25 = V_26 |
V_27 ;
T_1 V_28 , V_29 ;
T_1 V_30 , V_31 ;
int V_32 ;
V_28 = F_5 ( V_5 -> V_17 + V_33 ) ;
if ( V_28 & V_34 )
V_24 = F_6 ( V_2 , & V_22 ) ;
else
V_24 = F_7 ( V_2 , (struct V_35 * * ) & V_22 ) ;
if ( ! V_24 ) {
V_20 -> V_36 ++ ;
return;
}
V_30 = ( V_28 >> V_37 ) &
V_38 ;
if ( V_28 & V_34 )
V_22 -> V_39 = F_8 ( V_30 ) ;
else
V_22 -> V_39 = F_9 ( V_30 ) ;
V_29 = F_5 ( V_5 -> V_17 + V_40 ) ;
V_31 = ( V_29 >> V_41 ) ;
if ( V_31 & V_42 ) {
V_31 &= V_43 ;
V_31 = ( V_31 >> V_44 ) |
( ( V_31 & V_45 ) <<
V_46 ) ;
V_31 |= V_47 ;
} else {
V_31 &= V_45 ;
}
V_22 -> V_48 = V_31 ;
if ( V_28 & V_49 ) {
V_22 -> V_50 |= V_51 ;
F_10 ( V_2 , L_1 ) ;
}
if ( ! ( V_28 & V_34 ) &&
( V_28 & V_52 ) ) {
V_22 -> V_48 |= V_53 ;
} else {
if ( V_28 & V_54 )
V_22 -> V_50 |= V_55 ;
for ( V_32 = 0 ; V_32 < V_22 -> V_39 ; V_32 += 4 ) {
* ( T_1 * ) ( V_22 -> V_56 + V_32 ) =
F_5 ( V_5 -> V_17 + V_57 + V_32 ) ;
}
}
F_3 ( V_58 , V_5 -> V_17 + V_59 ) ;
F_3 ( V_25 , V_5 -> V_17 + V_60 ) ;
V_20 -> V_61 ++ ;
V_20 -> V_62 += V_22 -> V_39 ;
F_11 ( V_24 ) ;
}
static int F_12 ( struct V_1 * V_2 , int V_63 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_64 = 0 ;
T_1 V_65 ;
V_65 = F_5 ( V_5 -> V_17 + V_59 ) ;
if ( V_65 & V_66 ) {
F_10 ( V_2 , L_2 ) ;
return 0 ;
}
for (; ; ) {
if ( V_65 & V_66 )
break;
if ( V_63 <= 0 )
break;
F_4 ( V_2 ) ;
V_63 -- ;
V_64 ++ ;
V_65 = F_5 ( V_5 -> V_17 + V_59 ) ;
}
if ( V_64 )
F_13 ( V_2 , V_67 ) ;
return V_64 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = & V_2 -> V_20 ;
struct V_23 * V_24 ;
struct V_35 * V_68 ;
F_15 ( V_2 , L_3 ) ;
V_20 -> V_69 ++ ;
V_20 -> V_70 ++ ;
V_24 = F_16 ( V_2 , & V_68 ) ;
if ( F_17 ( ! V_24 ) )
return 0 ;
V_68 -> V_48 |= V_71 ;
V_68 -> V_56 [ 1 ] = V_72 ;
F_11 ( V_24 ) ;
return 1 ;
}
static int F_18 ( struct V_1 * V_2 , const T_1 V_73 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_19 * V_20 = & V_2 -> V_20 ;
struct V_35 * V_22 ;
struct V_23 * V_24 ;
const T_1 V_74 = V_75 |
V_76 |
V_77 |
V_78 |
V_79 |
V_80 |
V_81 ;
if ( ! ( V_73 & V_74 ) )
return 0 ;
V_5 -> V_9 . V_82 . V_83 ++ ;
V_20 -> V_69 ++ ;
V_24 = F_16 ( V_2 , & V_22 ) ;
if ( F_17 ( ! V_24 ) )
return 0 ;
V_22 -> V_48 |= V_84 | V_85 ;
if ( V_73 & V_75 )
V_22 -> V_56 [ 2 ] |= V_86 ;
if ( V_73 & V_76 )
V_22 -> V_56 [ 3 ] = V_87 ;
if ( V_73 & V_77 )
V_22 -> V_56 [ 2 ] |= V_88 ;
if ( V_73 & V_78 )
V_22 -> V_56 [ 2 ] |= V_89 ;
if ( V_73 & V_79 )
V_22 -> V_56 [ 2 ] |= V_90 ;
if ( V_73 & V_80 )
V_22 -> V_56 [ 3 ] = V_91 ;
if ( V_73 & V_81 )
V_22 -> V_56 [ 2 ] |= V_92 ;
F_3 ( V_93 , V_5 -> V_17 + V_94 ) ;
F_3 ( V_12 ,
V_5 -> V_17 + V_60 ) ;
F_3 ( V_95 , V_5 -> V_17 + V_94 ) ;
V_20 -> V_61 ++ ;
V_20 -> V_62 += V_22 -> V_96 ;
F_11 ( V_24 ) ;
return 1 ;
}
static int F_19 ( const struct V_1 * V_2 ,
struct V_97 * V_98 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_99 ;
V_99 = F_5 ( V_5 -> V_17 + V_100 ) ;
V_98 -> V_101 = ( V_99 >> V_102 ) &
V_103 ;
V_98 -> V_104 = ( V_99 >> V_105 ) &
V_106 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
enum V_107 V_108 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_19 * V_20 = & V_2 -> V_20 ;
struct V_35 * V_22 ;
struct V_23 * V_24 ;
struct V_97 V_98 ;
switch ( V_108 ) {
case V_109 :
V_5 -> V_9 . V_82 . V_110 ++ ;
V_5 -> V_9 . V_111 = V_112 ;
break;
case V_113 :
V_5 -> V_9 . V_82 . V_114 ++ ;
V_5 -> V_9 . V_111 = V_113 ;
break;
case V_115 :
V_5 -> V_9 . V_111 = V_115 ;
F_1 ( V_2 , 0 ) ;
V_5 -> V_9 . V_82 . V_116 ++ ;
F_21 ( V_2 ) ;
break;
default:
break;
}
V_24 = F_16 ( V_2 , & V_22 ) ;
if ( F_17 ( ! V_24 ) )
return 0 ;
F_19 ( V_2 , & V_98 ) ;
switch ( V_108 ) {
case V_109 :
V_22 -> V_48 |= V_71 ;
V_22 -> V_56 [ 1 ] = ( V_98 . V_104 > V_98 . V_101 ) ?
V_117 :
V_118 ;
V_22 -> V_56 [ 6 ] = V_98 . V_104 ;
V_22 -> V_56 [ 7 ] = V_98 . V_101 ;
break;
case V_113 :
V_22 -> V_48 |= V_71 ;
V_22 -> V_56 [ 1 ] |= V_119 ;
if ( V_98 . V_104 > 127 )
V_22 -> V_56 [ 1 ] |= V_120 ;
V_22 -> V_56 [ 6 ] = V_98 . V_104 ;
V_22 -> V_56 [ 7 ] = V_98 . V_101 ;
break;
case V_115 :
V_22 -> V_48 |= V_121 ;
break;
default:
break;
}
V_20 -> V_61 ++ ;
V_20 -> V_62 += V_22 -> V_96 ;
F_11 ( V_24 ) ;
return 1 ;
}
static int F_22 ( struct V_1 * V_2 , T_1 V_122 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_123 = 0 ;
T_1 V_124 ;
V_124 = F_5 ( V_5 -> V_17 + V_60 ) ;
if ( ( V_124 & V_125 ) &&
( V_5 -> V_9 . V_111 != V_112 ) ) {
F_3 ( V_125 ,
V_5 -> V_17 + V_60 ) ;
F_10 ( V_2 , L_4 ) ;
V_123 += F_20 ( V_2 ,
V_112 ) ;
}
if ( ( V_122 & V_126 ) &&
( V_5 -> V_9 . V_111 != V_113 ) ) {
F_10 ( V_2 , L_5 ) ;
V_123 += F_20 ( V_2 ,
V_113 ) ;
}
if ( ( V_122 & V_127 ) &&
( V_5 -> V_9 . V_111 != V_115 ) ) {
F_10 ( V_2 , L_6 ) ;
V_123 += F_20 ( V_2 ,
V_115 ) ;
}
return V_123 ;
}
static int F_23 ( struct V_128 * V_129 , int V_63 )
{
struct V_1 * V_2 = V_129 -> V_130 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
const T_1 V_131 = V_126 |
V_127 ;
int V_123 = 0 ;
T_1 V_122 = F_5 ( V_5 -> V_17 + V_132 ) ;
T_1 V_133 = F_5 ( V_5 -> V_17 + V_59 ) ;
T_1 V_73 = F_5 ( V_5 -> V_17 + V_94 ) ;
if ( ( V_122 & V_131 ) ||
( ( V_122 & V_134 ) == 0 ) )
V_123 += F_22 ( V_2 , V_122 ) ;
if ( V_133 & V_135 )
V_123 += F_14 ( V_2 ) ;
if ( V_5 -> V_9 . V_10 & V_11 )
V_123 += F_18 ( V_2 , V_73 ) ;
if ( ! ( V_133 & V_66 ) )
V_123 += F_12 ( V_2 , V_63 - V_123 ) ;
if ( V_123 < V_63 ) {
F_24 ( V_129 , V_123 ) ;
F_1 ( V_2 , 1 ) ;
}
return V_123 ;
}
static T_2 F_25 ( int V_136 , void * V_137 )
{
struct V_1 * V_2 = (struct V_1 * ) V_137 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_19 * V_20 = & V_2 -> V_20 ;
const T_1 V_25 = V_26 |
V_27 |
V_125 |
V_12 ;
const T_1 V_138 = V_139 |
V_140 ;
const T_1 V_141 = ~ ( ( T_1 ) ( V_142 |
V_125 ) ) ;
T_1 V_124 ;
V_124 = F_5 ( V_5 -> V_17 + V_60 ) ;
if ( V_124 == 0 )
return V_143 ;
F_3 ( V_141 , V_5 -> V_17 + V_60 ) ;
if ( V_124 & V_25 ) {
F_1 ( V_2 , 0 ) ;
F_26 ( & V_5 -> V_129 ) ;
}
if ( V_124 & V_140 ) {
V_20 -> V_144 += F_27 ( V_2 , 0 ) ;
V_20 -> V_145 ++ ;
F_13 ( V_2 , V_146 ) ;
}
if ( V_124 & V_138 )
F_28 ( V_2 ) ;
return V_147 ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_148 * V_149 = & V_5 -> V_9 . V_150 ;
const struct V_148 * V_151 = & V_5 -> V_9 . V_152 ;
T_3 V_153 , V_154 , V_155 , V_156 , V_157 ;
V_153 = V_149 -> V_153 - 2 ;
V_154 = V_149 -> V_154 - 1 ;
V_155 = V_149 -> V_158 + V_149 -> V_159 - 1 ;
V_156 = V_149 -> V_160 - 2 ;
F_3 ( ( V_156 << V_161 ) |
( V_155 << V_162 ) |
( V_153 << V_163 ) |
( V_154 << V_164 ) ,
V_5 -> V_17 + V_165 ) ;
V_153 = V_151 -> V_153 - 2 ;
V_154 = V_151 -> V_154 - 1 ;
V_155 = V_151 -> V_158 + V_151 -> V_159 - 1 ;
V_156 = V_151 -> V_160 - 2 ;
F_3 ( ( V_156 << V_161 ) |
( V_155 << V_162 ) |
( V_153 << V_163 ) |
( V_154 << V_164 ) ,
V_5 -> V_17 + V_166 ) ;
V_157 = V_151 -> V_153 * ( V_151 -> V_158 + V_151 -> V_159 ) ;
V_157 &= V_167 ;
F_3 ( V_168 | V_157 , V_5 -> V_17 + V_169 ) ;
}
static void F_30 ( struct V_1 * V_2 , const T_1 V_31 ,
const T_1 V_170 , const T_1 V_171 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( V_170 , V_5 -> V_17 + F_31 ( V_31 ) ) ;
F_3 ( V_171 , V_5 -> V_17 + F_32 ( V_31 ) ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_30 ( V_2 , 0 ,
V_172 |
V_173 ,
V_174 ) ;
F_30 ( V_2 , 1 ,
V_172 |
V_173 ,
V_174 |
V_175 ) ;
F_30 ( V_2 , 2 ,
V_172 |
V_176 |
V_173 ,
V_174 |
V_177 |
V_175 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_122 ;
F_3 ( V_178 , V_5 -> V_17 + V_132 ) ;
F_3 ( V_179 ,
V_5 -> V_17 + V_132 ) ;
F_29 ( V_2 ) ;
F_33 ( V_2 ) ;
F_3 ( V_180 , V_5 -> V_17 + V_59 ) ;
F_3 ( 0 , V_5 -> V_17 + V_59 ) ;
F_3 ( V_181 , V_5 -> V_17 + V_182 ) ;
F_3 ( 0 , V_5 -> V_17 + V_182 ) ;
F_3 ( 0 , V_5 -> V_17 + V_183 ) ;
F_3 ( 0 , V_5 -> V_17 + V_184 ) ;
F_3 ( ( T_1 ) ( ~ V_142 ) ,
V_5 -> V_17 + V_60 ) ;
V_122 = V_185 | V_186 |
V_179 ;
if ( V_5 -> V_9 . V_10 & V_187 )
V_122 |= V_188 ;
if ( V_5 -> V_9 . V_10 & V_189 )
V_122 |= V_190 ;
if ( ( V_5 -> V_9 . V_10 & V_191 ) &&
! ( V_5 -> V_9 . V_10 & V_192 ) )
V_122 |= V_193 ;
if ( ! ( V_5 -> V_9 . V_10 & V_191 ) )
V_122 |= V_194 ;
V_5 -> V_9 . V_111 = V_109 ;
F_1 ( V_2 , 1 ) ;
F_3 ( V_195 ,
V_5 -> V_17 + V_94 ) ;
F_3 ( V_93 , V_5 -> V_17 + V_94 ) ;
F_3 ( V_95 , V_5 -> V_17 + V_94 ) ;
F_3 ( V_122 , V_5 -> V_17 + V_132 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( V_93 , V_5 -> V_17 + V_94 ) ;
F_3 ( 0 , V_5 -> V_17 + V_94 ) ;
F_3 ( V_178 , V_5 -> V_17 + V_132 ) ;
F_3 ( ~ 0 , V_5 -> V_17 + V_18 ) ;
F_3 ( ( T_1 ) ( ~ V_142 ) ,
V_5 -> V_17 + V_60 ) ;
V_5 -> V_9 . V_111 = V_196 ;
}
static int F_36 ( struct V_1 * V_2 , enum V_197 V_198 )
{
switch ( V_198 ) {
case V_199 :
F_34 ( V_2 ) ;
F_28 ( V_2 ) ;
break;
default:
return - V_200 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_201 ;
V_201 = F_38 ( V_2 ) ;
if ( V_201 ) {
F_15 ( V_2 , L_7 ) ;
return V_201 ;
}
V_201 = F_39 ( V_2 -> V_136 , F_25 , V_202 ,
V_2 -> V_203 , V_2 ) ;
if ( V_201 < 0 ) {
F_15 ( V_2 , L_8 ) ;
goto V_204;
}
F_34 ( V_2 ) ;
F_13 ( V_2 , V_205 ) ;
F_40 ( & V_5 -> V_129 ) ;
F_41 ( V_2 ) ;
return 0 ;
V_204:
F_42 ( V_2 ) ;
return V_201 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_44 ( V_2 ) ;
F_45 ( & V_5 -> V_129 ) ;
F_35 ( V_2 ) ;
F_46 ( V_2 -> V_136 , V_2 ) ;
F_42 ( V_2 ) ;
F_13 ( V_2 , V_206 ) ;
return 0 ;
}
static T_4 F_47 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_21 * V_22 = (struct V_21 * ) V_24 -> V_56 ;
T_1 V_207 , V_208 , V_209 ;
int V_32 ;
if ( F_48 ( V_2 , V_24 ) )
return V_210 ;
V_207 = F_5 ( V_5 -> V_17 + V_182 ) ;
if ( V_207 & V_211 ) {
F_44 ( V_2 ) ;
F_15 ( V_2 , L_9 ) ;
return V_212 ;
}
F_44 ( V_2 ) ;
if ( V_22 -> V_48 & V_47 ) {
V_208 = V_22 -> V_48 & V_213 ;
V_208 = ( V_208 >> V_214 ) |
( ( V_208 & V_215 ) <<
V_216 ) ;
V_208 |= V_217 ;
} else {
V_208 = V_22 -> V_48 & V_218 ;
}
V_209 = F_49 ( V_22 -> V_39 ) ;
if ( ( V_5 -> V_9 . V_10 & V_191 ) && F_50 ( V_24 ) ) {
V_209 |= V_219 ;
if ( V_22 -> V_50 & V_55 )
V_209 |= V_220 ;
}
if ( V_22 -> V_48 & V_53 )
V_209 |= V_221 ;
F_3 ( V_208 , V_5 -> V_17 + V_222 ) ;
F_3 ( V_209 , V_5 -> V_17 + V_223 ) ;
for ( V_32 = 0 ; V_32 < V_22 -> V_39 ; V_32 += 4 ) {
F_3 ( * ( T_1 * ) ( V_22 -> V_56 + V_32 ) ,
V_5 -> V_17 + V_224 + V_32 ) ;
}
F_3 ( 0 , V_5 -> V_17 + V_225 ) ;
F_3 ( 0 , V_5 -> V_17 + V_226 ) ;
F_51 ( V_24 , V_2 , 0 ) ;
F_3 ( V_227 , V_5 -> V_17 + V_182 ) ;
return V_210 ;
}
static int F_52 ( struct V_228 * V_229 )
{
struct V_230 * V_130 = & V_229 -> V_130 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_231 * V_232 ;
void T_5 * V_233 ;
int V_136 , V_201 ;
T_1 V_31 ;
V_232 = F_53 ( V_229 , V_234 , 0 ) ;
V_233 = F_54 ( V_130 , V_232 ) ;
V_136 = F_55 ( V_229 , 0 ) ;
if ( F_56 ( V_233 ) || V_136 < 0 )
return - V_235 ;
V_31 = F_5 ( V_233 + V_236 ) ;
if ( V_31 != V_237 ) {
F_57 ( V_130 , L_10 , V_31 ) ;
return - V_235 ;
}
V_2 = F_58 ( sizeof( * V_5 ) , 1 ) ;
if ( ! V_2 )
return - V_238 ;
V_2 -> V_136 = V_136 ;
V_2 -> V_50 |= V_239 ;
V_2 -> V_240 = & V_241 ;
V_5 = F_2 ( V_2 ) ;
V_5 -> V_2 = V_2 ;
V_5 -> V_17 = V_233 ;
F_59 ( V_2 , & V_5 -> V_129 , F_23 , 64 ) ;
V_5 -> V_9 . V_111 = V_196 ;
V_5 -> V_9 . clock . V_242 = F_5 ( V_233 + V_243 ) ;
V_5 -> V_9 . V_244 = & V_245 ;
V_5 -> V_9 . V_246 = & V_245 ;
V_5 -> V_9 . V_247 = F_36 ;
V_5 -> V_9 . V_248 = F_19 ;
V_5 -> V_9 . V_10 = V_191 ;
V_5 -> V_9 . V_249 = V_189 |
V_187 |
V_191 |
V_192 |
V_11 ;
F_60 ( V_229 , V_2 ) ;
F_61 ( V_2 , V_130 ) ;
V_201 = F_62 ( V_2 ) ;
if ( V_201 ) {
F_57 ( V_130 , L_11 , V_201 ) ;
goto V_250;
}
F_63 ( V_2 ) ;
F_64 ( V_130 , L_12 ,
V_5 -> V_17 , V_2 -> V_136 , V_5 -> V_9 . clock . V_242 ) ;
return 0 ;
V_250:
F_65 ( V_2 ) ;
return V_201 ;
}
static int F_66 ( struct V_228 * V_229 )
{
struct V_1 * V_2 = F_67 ( V_229 ) ;
F_68 ( V_2 ) ;
F_60 ( V_229 , NULL ) ;
F_65 ( V_2 ) ;
return 0 ;
}
